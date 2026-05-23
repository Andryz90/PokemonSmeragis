from __future__ import annotations

import argparse
import re
import unicodedata
from datetime import datetime
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
MAX_ARTIFACT_SKEW_SECONDS = 600


DEFINE_RE = re.compile(r"^#define\s+([A-Z0-9_]+)\s+(.+?)\s*$")
MOVE_NAME_RE = re.compile(r'\[(MOVE_[A-Z0-9_]+)\]\s*=\s*_\("([^"]*)"\)')
MOVE_INFO_NAME_RE = re.compile(r'\.name\s*=\s*(?:COMPOUND_STRING|_)\("([^"]*)"\)')
SPECIES_NAME_RE = re.compile(r'\.speciesName\s*=\s*_\("([^"]*)"\)')
GROWTH_RE = re.compile(r'\.growthRate\s*=\s*(GROWTH_[A-Z0-9_]+)')
ABILITIES_RE = re.compile(
    r'\.abilities\s*=\s*\{\s*(ABILITY_[A-Z0-9_]+)\s*,\s*(ABILITY_[A-Z0-9_]+)\s*,\s*(ABILITY_[A-Z0-9_]+)\s*\}',
    re.S,
)
SPECIES_JS_NAME_RE = re.compile(r'"name"\s*:\s*"([^"]+)"')
FORME_ORDER_RE = re.compile(r'"formeOrder"\s*:\s*\[(.*?)\]', re.S)
QUOTED_STRING_RE = re.compile(r'"([^"]+)"')
MACRO_DEFINE_RE = re.compile(r"^\s*#define\s+([A-Z0-9_]+)(?:\([^)]*\))?\s*(.*)$")
MACRO_CALL_RE = re.compile(r"\b([A-Z][A-Z0-9_]+)\s*\(")


def normalize_ascii(text: str) -> str:
    replacements = {
        "♀": "-F",
        "♂": "-M",
        "’": "'",
        "‘": "'",
        "“": '"',
        "”": '"',
        "–": "-",
        "—": "-",
        "…": "...",
        "Pokémon": "Pokemon",
        "Poké": "Poke",
    }
    for old, new in replacements.items():
        text = text.replace(old, new)
    text = unicodedata.normalize("NFKD", text).encode("ascii", "ignore").decode("ascii")
    return text


def load_text(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="replace")


def format_mtime(path: Path) -> str:
    return datetime.fromtimestamp(path.stat().st_mtime).strftime("%Y-%m-%d %H:%M:%S")


def ensure_fresh_build_artifacts(rom_path: Path, map_path: Path, elf_path: Path) -> None:
    missing = [path for path in (rom_path, map_path, elf_path) if not path.exists()]
    if missing:
        raise FileNotFoundError(
            "Missing build artifact(s): "
            + ", ".join(str(path) for path in missing)
        )

    rom_mtime = rom_path.stat().st_mtime
    stale = []
    for artifact in (map_path, elf_path):
        skew_seconds = rom_mtime - artifact.stat().st_mtime
        if skew_seconds > MAX_ARTIFACT_SKEW_SECONDS:
            stale.append((artifact, int(skew_seconds)))

    if stale:
        details = "\n".join(
            f"  - {artifact.name}: {format_mtime(artifact)} ({skew_seconds}s older than {rom_path.name})"
            for artifact, skew_seconds in stale
        )
        raise ValueError(
            "The symbol files are older than the ROM currently being used.\n"
            f"  - {rom_path.name}: {format_mtime(rom_path)}\n"
            f"{details}\n"
            "Rebuild pokeemerald.elf and pokeemerald.map for this ROM, then regenerate Smeragis.lua."
        )


def normalize_lookup_key(text: str) -> str:
    return re.sub(r"[^a-z0-9]+", "", normalize_ascii(text).lower())


def parse_defines(path: Path) -> dict[str, int]:
    lines = load_text(path).splitlines()
    raw_defs: list[tuple[str, str]] = []
    for line in lines:
        line = line.split("//", 1)[0].strip()
        if not line:
            continue
        match = DEFINE_RE.match(line)
        if not match:
            continue
        name, expr = match.groups()
        if "(" in name:
            continue
        raw_defs.append((name, expr.strip()))

    known: dict[str, int] = {}
    pending = raw_defs[:]
    made_progress = True
    while pending and made_progress:
        made_progress = False
        next_pending: list[tuple[str, str]] = []
        for name, expr in pending:
            try:
                value = eval(expr, {"__builtins__": {}}, known)  # noqa: S307 - trusted local source
            except Exception:
                next_pending.append((name, expr))
                continue
            if isinstance(value, int):
                known[name] = value
                made_progress = True
            else:
                next_pending.append((name, expr))
        pending = next_pending
    return known


def find_matching_brace(text: str, start_index: int) -> int:
    depth = 0
    i = start_index
    in_string = False
    string_char = ""
    while i < len(text):
        ch = text[i]
        nxt = text[i + 1] if i + 1 < len(text) else ""
        if in_string:
            if ch == "\\":
                i += 2
                continue
            if ch == string_char:
                in_string = False
            i += 1
            continue
        if ch in ('"', "'"):
            in_string = True
            string_char = ch
            i += 1
            continue
        if ch == "/" and nxt == "/":
            newline = text.find("\n", i)
            if newline == -1:
                return len(text)
            i = newline + 1
            continue
        if ch == "/" and nxt == "*":
            end = text.find("*/", i + 2)
            if end == -1:
                raise ValueError("Unterminated block comment while parsing braces")
            i = end + 2
            continue
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    raise ValueError("No matching brace found")


def extract_indexed_entries(text: str, prefix: str) -> dict[str, str]:
    start_re = re.compile(rf"^\s*\[({prefix}[A-Z0-9_]+)\]\s*=\s*$", re.M)
    entries: dict[str, str] = {}
    for match in start_re.finditer(text):
        name = match.group(1)
        brace_index = text.find("{", match.end())
        if brace_index == -1:
            continue
        end_index = find_matching_brace(text, brace_index)
        entries[name] = text[brace_index + 1:end_index]
    return entries


def extract_species_assignments(text: str) -> dict[str, str]:
    assignment_re = re.compile(r"^\s*\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*(.*)$", re.M)
    entries: dict[str, str] = {}
    for match in assignment_re.finditer(text):
        species_macro = match.group(1)
        remainder = match.group(2).strip()
        if not remainder:
            brace_index = text.find("{", match.end())
            if brace_index == -1:
                continue
            if text[match.end():brace_index].strip():
                continue
            end_index = find_matching_brace(text, brace_index)
            entries[species_macro] = text[brace_index + 1:end_index]
            continue
        if remainder.startswith("{"):
            brace_offset = match.group(2).find("{")
            brace_index = match.start(2) + brace_offset
            end_index = find_matching_brace(text, brace_index)
            entries[species_macro] = text[brace_index + 1:end_index]
            continue
        entries[species_macro] = remainder.rstrip(",").strip()
    return entries


def parse_macro_definitions(text: str) -> dict[str, str]:
    lines = text.splitlines()
    definitions: dict[str, str] = {}
    i = 0
    while i < len(lines):
        match = MACRO_DEFINE_RE.match(lines[i])
        if not match:
            i += 1
            continue
        name, first_body = match.groups()
        body_lines = [first_body]
        while lines[i].rstrip().endswith("\\"):
            i += 1
            if i >= len(lines):
                break
            body_lines.append(lines[i])
        cleaned = [line.rstrip().removesuffix("\\").rstrip() for line in body_lines]
        definitions[name] = "\n".join(line for line in cleaned if line.strip())
        i += 1
    return definitions


def expand_macro_references(text: str, macro_definitions: dict[str, str]) -> str:
    expanded_parts = [text]
    pending = [text]
    seen: set[str] = set()
    while pending:
        current = pending.pop()
        for macro_name in MACRO_CALL_RE.findall(current):
            if macro_name in seen or macro_name not in macro_definitions:
                continue
            seen.add(macro_name)
            body = macro_definitions[macro_name]
            expanded_parts.append(body)
            pending.append(body)
    return "\n".join(expanded_parts)


def parse_porydex_species_names() -> dict[str, str]:
    path = ROOT / "docs" / "Documentation_Sites" / "porydex" / "site" / "data" / "species.js"
    text = load_text(path)
    mapping: dict[str, str] = {}
    for name in SPECIES_JS_NAME_RE.findall(text):
        ascii_name = normalize_ascii(name)
        mapping[normalize_lookup_key(ascii_name)] = ascii_name
    for block in FORME_ORDER_RE.findall(text):
        for name in QUOTED_STRING_RE.findall(block):
            ascii_name = normalize_ascii(name)
            mapping[normalize_lookup_key(ascii_name)] = ascii_name
    return mapping


def humanize_species_macro(macro: str) -> str:
    tokens = macro.removeprefix("SPECIES_").split("_")
    token_aliases = {
        "ALOLAN": "Alola",
        "GALARIAN": "Galar",
        "HISUIAN": "Hisui",
        "PALDEAN": "Paldea",
        "FEMALE": "F",
        "MALE": "M",
        "JR": "Jr",
        "MR": "Mr",
        "OF": "of",
    }
    words: list[str] = []
    for token in tokens:
        if token in token_aliases:
            words.append(token_aliases[token])
        elif len(token) == 1 or token.isdigit():
            words.append(token)
        else:
            words.append(token.capitalize())
    return " ".join(words)


def resolve_species_display_name(species_macro: str, raw_species_name: str, porydex_names: dict[str, str]) -> str:
    candidates = [
        humanize_species_macro(species_macro),
        humanize_species_macro(species_macro).replace(" ", "-"),
        raw_species_name,
        raw_species_name.replace(" ", "-"),
    ]
    for candidate in candidates:
        lookup = normalize_lookup_key(candidate)
        if lookup in porydex_names:
            return porydex_names[lookup]
    return normalize_ascii(candidates[0])


def parse_species_entries() -> dict[str, dict[str, object]]:
    species_dir = ROOT / "src" / "data" / "pokemon" / "species_info"
    porydex_names = parse_porydex_species_names()
    parsed: dict[str, dict[str, object]] = {}
    for path in sorted(species_dir.glob("gen_*_families.h")):
        text = load_text(path)
        entries = extract_species_assignments(text)
        macro_definitions = parse_macro_definitions(text)
        for species_macro, body in entries.items():
            expanded_body = expand_macro_references(body, macro_definitions)
            name_match = SPECIES_NAME_RE.search(expanded_body)
            growth_match = GROWTH_RE.search(expanded_body)
            abilities_match = ABILITIES_RE.search(expanded_body)
            if not name_match or not growth_match or not abilities_match:
                continue
            display_name = resolve_species_display_name(species_macro, name_match.group(1), porydex_names)
            parsed[species_macro] = {
                "name": display_name,
                "growth": growth_match.group(1),
                "abilities": list(abilities_match.groups()),
            }
    return parsed


def parse_move_names() -> dict[str, str]:
    mapping: dict[str, str] = {}
    legacy_path = ROOT / "src" / "data" / "text" / "move_names.h"
    if legacy_path.exists():
        for macro, name in MOVE_NAME_RE.findall(load_text(legacy_path)):
            normalized = normalize_ascii(name)
            mapping[macro] = "" if macro == "MOVE_NONE" else normalized.title()

    moves_info_path = ROOT / "src" / "data" / "moves_info.h"
    if moves_info_path.exists():
        entries = extract_indexed_entries(load_text(moves_info_path), "MOVE_")
        for macro, body in entries.items():
            match = MOVE_INFO_NAME_RE.search(body)
            if not match:
                continue
            mapping[macro] = normalize_ascii(match.group(1))
    mapping["MOVE_NONE"] = ""
    return mapping


def parse_name_entries(path: Path, prefix: str, override_none: str | None = None) -> dict[str, str]:
    text = load_text(path)
    entries = extract_indexed_entries(text, prefix)
    mapping: dict[str, str] = {}
    for macro, body in entries.items():
        match = re.search(r'\.name\s*=\s*_\("([^"]*)"\)', body)
        if not match:
            continue
        name = normalize_ascii(match.group(1))
        if macro.endswith("_NONE") and override_none is not None:
            name = override_none
        mapping[macro] = name
    return mapping


def parse_map_symbols(path: Path, symbols: list[str]) -> dict[str, int]:
    found: dict[str, int] = {}
    symbol_set = set(symbols)
    line_re = re.compile(r"0x([0-9A-Fa-f]+)\s+([A-Za-z0-9_]+)$")
    for line in load_text(path).splitlines():
        match = line_re.search(line.rstrip())
        if not match:
            continue
        address = int(match.group(1), 16)
        symbol = match.group(2)
        if symbol in symbol_set:
            found[symbol] = address
    missing = [symbol for symbol in symbols if symbol not in found]
    if missing:
        raise ValueError(f"Missing symbols in map file: {', '.join(missing)}")
    return found


def build_numeric_table(
    ids: dict[str, int],
    names: dict[str, str],
    minimum_id: int,
    maximum_id: int,
    default: str,
) -> list[str]:
    values = [default for _ in range(maximum_id - minimum_id + 1)]
    for macro, value in ids.items():
        if minimum_id <= value <= maximum_id and macro in names:
            values[value - minimum_id] = names[macro]
    return values


def escape_lua_string(value: str) -> str:
    return value.replace("\\", "\\\\").replace('"', '\\"')


def format_lua_string_array(name: str, values: list[str]) -> str:
    lines = [f'{name} = {{']
    lines.extend(f'"{escape_lua_string(value)}",' for value in values[:-1])
    if values:
        lines.append(f'"{escape_lua_string(values[-1])}"')
    lines.append("}")
    return "\n".join(lines)


def format_lua_number_array(name: str, values: list[int]) -> str:
    lines = [f"{name}={{"]
    chunk_size = 32
    for i in range(0, len(values), chunk_size):
        chunk = ",".join(str(value) for value in values[i:i + chunk_size])
        if i + chunk_size < len(values):
            lines.append(chunk + ",")
        else:
            lines.append(chunk)
    lines.append("}")
    return "\n".join(lines)


def replace_section(text: str, start_marker: str, end_marker: str, replacement: str) -> str:
    start_index = text.index(start_marker)
    end_index = text.index(end_marker, start_index)
    return text[:start_index] + replacement + text[end_index:]


def replace_regex(text: str, pattern: str, replacement: str) -> str:
    new_text, count = re.subn(pattern, lambda _match: replacement, text, flags=re.S | re.M)
    if count != 1:
        raise ValueError(f"Expected exactly one match for pattern: {pattern}")
    return new_text


def replace_regex_if_missing(text: str, pattern: str, replacement: str, marker: str) -> str:
    if marker in text:
        return text
    return replace_regex(text, pattern, replacement)


READ_BOX_MON_REPLACEMENT = """function readBoxMon(address)
\tlocal mon = {}
\tmon.personality = emu:read32(address + 0)
\tmon.otId = emu:read32(address + 4)
\tmon.nickname = toString(emu:readRange(address + 8, monNameLength))

\tlocal natureLang = emu:read8(address + 18)
\tmon.language = natureLang & 0x7
\tmon.hiddenNatureModifier = (natureLang >> 3) & 0x1F

\tlocal flags = emu:read8(address + 19)
\tmon.isBadEgg = flags & 1
\tmon.hasSpecies = (flags >> 1) & 1
\tmon.isEgg = (flags >> 2) & 1
\tmon.daysSinceFormChange = (flags >> 4) & 0x7
\tmon.locationDefined = (flags >> 7) & 1
\tmon.otName = toString(emu:readRange(address + 20, playerNameLength))

\tlocal markings = emu:read8(address + 27)
\tmon.markings = markings & 0xF
\tmon.compressedStatus = (markings >> 4) & 0xF

\tlocal key = mon.otId ~ mon.personality
\tlocal substructSelector = {
\t\t[ 0] = {0, 1, 2, 3},
\t\t[ 1] = {0, 1, 3, 2},
\t\t[ 2] = {0, 2, 1, 3},
\t\t[ 3] = {0, 3, 1, 2},
\t\t[ 4] = {0, 2, 3, 1},
\t\t[ 5] = {0, 3, 2, 1},
\t\t[ 6] = {1, 0, 2, 3},
\t\t[ 7] = {1, 0, 3, 2},
\t\t[ 8] = {2, 0, 1, 3},
\t\t[ 9] = {3, 0, 1, 2},
\t\t[10] = {2, 0, 3, 1},
\t\t[11] = {3, 0, 2, 1},
\t\t[12] = {1, 2, 0, 3},
\t\t[13] = {1, 3, 0, 2},
\t\t[14] = {2, 1, 0, 3},
\t\t[15] = {3, 1, 0, 2},
\t\t[16] = {2, 3, 0, 1},
\t\t[17] = {3, 2, 0, 1},
\t\t[18] = {1, 2, 3, 0},
\t\t[19] = {1, 3, 2, 0},
\t\t[20] = {2, 1, 3, 0},
\t\t[21] = {3, 1, 2, 0},
\t\t[22] = {2, 3, 1, 0},
\t\t[23] = {3, 2, 1, 0},
\t}

\tlocal pSel = substructSelector[mon.personality % 24]
\tlocal ss0 = {}
\tlocal ss1 = {}
\tlocal ss2 = {}
\tlocal ss3 = {}

\tfor i = 0, 2 do
\t\tss0[i] = emu:read32(address + 32 + pSel[1] * 12 + i * 4) ~ key
\t\tss1[i] = emu:read32(address + 32 + pSel[2] * 12 + i * 4) ~ key
\t\tss2[i] = emu:read32(address + 32 + pSel[3] * 12 + i * 4) ~ key
\t\tss3[i] = emu:read32(address + 32 + pSel[4] * 12 + i * 4) ~ key
\tend

\tlocal nature = mon.personality % 25
\tmon.hiddenNature = nature ~ mon.hiddenNatureModifier

\tmon.species = ss0[0] & 0x7FF
\tmon.teraType = (ss0[0] >> 11) & 0x1F
\tmon.heldItem = (ss0[0] >> 16) & 0x3FF
\tmon.experience = ss0[1] & 0x1FFFFF
\tmon.ppBonuses = ss0[2] & 0xFF
\tmon.friendship = (ss0[2] >> 8) & 0xFF
\tmon.pokeball = (ss0[2] >> 16) & 0x3F

\tmon.moves = {
\t\tss1[0] & 0x7FF,
\t\t(ss1[0] >> 16) & 0x7FF,
\t\tss1[1] & 0x7FF,
\t\t(ss1[1] >> 16) & 0x7FF
\t}
\tmon.hyperTrainedHP = (ss1[1] >> 30) & 0x1
\tmon.hyperTrainedAttack = (ss1[1] >> 31) & 0x1
\tmon.pp = {
\t\tss1[2] & 0x7F,
\t\t(ss1[2] >> 8) & 0x7F,
\t\t(ss1[2] >> 16) & 0x7F,
\t\t(ss1[2] >> 24) & 0x7F
\t}
\tmon.hyperTrainedDefense = (ss1[2] >> 7) & 0x1
\tmon.hyperTrainedSpeed = (ss1[2] >> 15) & 0x1
\tmon.hyperTrainedSpAttack = (ss1[2] >> 23) & 0x1
\tmon.hyperTrainedSpDefense = (ss1[2] >> 31) & 0x1

\tmon.hpEV = ss2[0] & 0xFF
\tmon.attackEV = (ss2[0] >> 8) & 0xFF
\tmon.defenseEV = (ss2[0] >> 16) & 0xFF
\tmon.speedEV = ss2[0] >> 24
\tmon.spAttackEV = ss2[1] & 0xFF
\tmon.spDefenseEV = (ss2[1] >> 8) & 0xFF
\tmon.cool = (ss2[1] >> 16) & 0xFF
\tmon.beauty = ss2[1] >> 24
\tmon.cute = ss2[2] & 0xFF
\tmon.smart = (ss2[2] >> 8) & 0xFF
\tmon.tough = (ss2[2] >> 16) & 0xFF
\tmon.sheen = ss2[2] >> 24

\tmon.pokerus = ss3[0] & 0xFF
\tmon.metLocation = (ss3[0] >> 8) & 0xFF
\tmon.metLevel = (ss3[0] >> 16) & 0x7F
\tmon.metGame = (ss3[0] >> 23) & 0xF
\tmon.dynamaxLevel = (ss3[0] >> 27) & 0xF
\tmon.otGender = (ss3[0] >> 31) & 0x1

\tmon.hpIV = ss3[1] & 0x1F
\tmon.attackIV = (ss3[1] >> 5) & 0x1F
\tmon.defenseIV = (ss3[1] >> 10) & 0x1F
\tmon.speedIV = (ss3[1] >> 15) & 0x1F
\tmon.spAttackIV = (ss3[1] >> 20) & 0x1F
\tmon.spDefenseIV = (ss3[1] >> 25) & 0x1F
\tmon.gigantamaxFactor = (ss3[1] >> 31) & 0x1

\tflags = ss3[2]
\tmon.coolRibbon = flags & 7
\tmon.beautyRibbon = (flags >> 3) & 7
\tmon.cuteRibbon = (flags >> 6) & 7
\tmon.smartRibbon = (flags >> 9) & 7
\tmon.toughRibbon = (flags >> 12) & 7
\tmon.championRibbon = (flags >> 15) & 1
\tmon.winningRibbon = (flags >> 16) & 1
\tmon.victoryRibbon = (flags >> 17) & 1
\tmon.artistRibbon = (flags >> 18) & 1
\tmon.effortRibbon = (flags >> 19) & 1
\tmon.marineRibbon = (flags >> 20) & 1
\tmon.landRibbon = (flags >> 21) & 1
\tmon.skyRibbon = (flags >> 22) & 1
\tmon.countryRibbon = (flags >> 23) & 1
\tmon.nationalRibbon = (flags >> 24) & 1
\tmon.earthRibbon = (flags >> 25) & 1
\tmon.worldRibbon = (flags >> 26) & 1
\tmon.isShadow = (flags >> 27) & 1
\tmon.altAbility = (flags >> 29) & 3
\tmon.modernFatefulEncounter = (flags >> 31) & 1
\treturn mon
end

function readPartyMon(address)"""


TO_STRING_REPLACEMENT = """function toString(rawstring)
\tlocal string = ""
\tfor _, char in ipairs({rawstring:byte(1, #rawstring)}) do
\t\tif char == terminator then
\t\t\tbreak
\t\tend
\t\tstring = string .. (charmap[char] or "?")
\tend
\treturn string
end

function _read16BE(emu, address)"""


NATURE_REPLACEMENT = """function getSpeciesName(species)
\tlocal name = mons[species]
\tif name == nil or name == "" then
\t\treturn string.format("Unknown Species %d", species)
\tend
\treturn name
end

function isValidSpeciesId(species)
\treturn type(species) == "number" and species > 0 and species <= #mons
end

function requireValidSpecies(species, context)
\tif isValidSpeciesId(species) then
\t\treturn
\tend
\tlocal where = context or "Pokemon data"
\terror(string.format("%s looks invalid (species=%s). Rebuild pokeemerald.elf and pokeemerald.map for the ROM currently loaded in mGBA, then regenerate Smeragis.lua.", where, tostring(species)))
end

function validatePartyData(party)
\tif party == nil or #party == 0 then
\t\treturn false, "party count is zero or unreadable"
\tend
\tfor _, mon in ipairs(party) do
\t\tif mon.species ~= 0 then
\t\t\tif not isValidSpeciesId(mon.species) then
\t\t\t\treturn false, string.format("species=%s", tostring(mon.species))
\t\t\tend
\t\t\tif mon.level == nil or mon.level < 1 or mon.level > 100 then
\t\t\t\treturn false, string.format("species=%s level=%s", tostring(mon.species), tostring(mon.level))
\t\t\tend
\t\tend
\tend
\treturn true
end

function requireValidParty(party)
\tlocal ok, reason = validatePartyData(party)
\tif not ok then
\t\terror("Party RAM looks invalid (" .. reason .. "). Rebuild pokeemerald.elf and pokeemerald.map for the ROM currently loaded in mGBA, then regenerate Smeragis.lua.")
\tend
\treturn party
end

function getAbility(mon)
\tlocal abilityIndex = (mon.species * 3) + 1 + mon.altAbility
\tlocal current = ability[abilityIndex]
\tif current == nil or current == "None" or current == "" then
\t\tcurrent = ability[(mon.species * 3) + 1]
\tend
\tif current == nil or current == "" then
\t\treturn "None"
\tend
\treturn current
end

function getNature(mon)
\treturn nature[mon.hiddenNature + 1] or "Hardy"
end

function getEffectiveIV(rawIv, isHyperTrained)
\tif isHyperTrained == 1 then
\t\treturn 31
\tend
\treturn rawIv
end

function getPartyEVTotal(mon)
\treturn mon.hpEV + mon.attackEV + mon.defenseEV + mon.spAttackEV + mon.spDefenseEV + mon.speedEV
end

function getPartyPrint(mon)"""


PARTY_PRINT_REPLACEMENT = """function getPartyPrint(mon)
\tlocal str = ""
\trequireValidSpecies(mon.species, "Party export")
\tlocal hpIV = getEffectiveIV(mon.hpIV, mon.hyperTrainedHP)
\tlocal atkIV = getEffectiveIV(mon.attackIV, mon.hyperTrainedAttack)
\tlocal defIV = getEffectiveIV(mon.defenseIV, mon.hyperTrainedDefense)
\tlocal spaIV = getEffectiveIV(mon.spAttackIV, mon.hyperTrainedSpAttack)
\tlocal spdIV = getEffectiveIV(mon.spDefenseIV, mon.hyperTrainedSpDefense)
\tlocal speIV = getEffectiveIV(mon.speedIV, mon.hyperTrainedSpeed)
\tstr = str .. getSpeciesName(mon.species)
\tif item[mon.heldItem] then
\t\tstr = str .. string.format(" @ %s", item[mon.heldItem])
\tend
\tstr = str .. string.format("\\n")
\tstr = str .. "Ability: " .. string.format("%s", getAbility(mon)) .. string.format("\\n")
\tstr = str .. string.format("Level: %d\\n", mon.level)
\tstr = str .. string.format("%s", getNature(mon)) .. " Nature" .. string.format("\\n")
\tstr = str .. string.format("IVs: %d HP / %d Atk / %d Def / %d SpA / %d SpD / %d Spe", hpIV, atkIV, defIV, spaIV, spdIV, speIV) .. string.format("\\n")
\tif getPartyEVTotal(mon) > 0 then
\t\tstr = str .. string.format("EVs: %d HP / %d Atk / %d Def / %d SpA / %d SpD / %d Spe", mon.hpEV, mon.attackEV, mon.defenseEV, mon.spAttackEV, mon.spDefenseEV, mon.speedEV) .. string.format("\\n")
\tend
\tfor i=1,4 do
\t\tlocal moveId = mon.moves[i]
\t\tlocal mv = move[moveId + 1] or ""
\t\tif moveId ~= 0 and (mv == nil or mv == "" or mv == "-") then
\t\t\tmv = string.format("Unknown Move %d", moveId)
\t\tend
\t\tif mv:lower() == "hidden power" then
\t\t\tstr = str .. string.format("- Hidden Power %s\\n", getHP(mon))
\t\telseif mv ~= "" then
\t\t\tstr = str .. string.format("- %s\\n", mv)
\t\tend
\tend
\tstr = str .. string.format("\\n")
\treturn str
end

function getPCPrint(mon)"""


PC_PRINT_REPLACEMENT = """function getPCPrint(mon)
\tlocal str = ""
\trequireValidSpecies(mon.species, "PC export")
\tlocal hpIV = getEffectiveIV(mon.hpIV, mon.hyperTrainedHP)
\tlocal atkIV = getEffectiveIV(mon.attackIV, mon.hyperTrainedAttack)
\tlocal defIV = getEffectiveIV(mon.defenseIV, mon.hyperTrainedDefense)
\tlocal spaIV = getEffectiveIV(mon.spAttackIV, mon.hyperTrainedSpAttack)
\tlocal spdIV = getEffectiveIV(mon.spDefenseIV, mon.hyperTrainedSpDefense)
\tlocal speIV = getEffectiveIV(mon.speedIV, mon.hyperTrainedSpeed)
\tstr = str .. getSpeciesName(mon.species)
\tif item[mon.heldItem] then
\t\tstr = str .. string.format(" @ %s", item[mon.heldItem])
\tend
\tstr = str .. string.format("\\n")
\tstr = str .. "Ability: " .. string.format("%s", getAbility(mon)) .. string.format("\\n")
\tstr = str .. string.format("Level: %d\\n", calcLevel(mon.experience, mon.species))
\tstr = str .. string.format("%s", getNature(mon)) .. " Nature" .. string.format("\\n")
\tstr = str .. string.format("IVs: %d HP / %d Atk / %d Def / %d SpA / %d SpD / %d Spe", hpIV, atkIV, defIV, spaIV, spdIV, speIV) .. string.format("\\n")
\tif getPartyEVTotal(mon) > 0 then
\t\tstr = str .. string.format("EVs: %d HP / %d Atk / %d Def / %d SpA / %d SpD / %d Spe", mon.hpEV, mon.attackEV, mon.defenseEV, mon.spAttackEV, mon.spDefenseEV, mon.speedEV) .. string.format("\\n")
\tend
\tfor i=1,4 do
\t\tlocal moveId = mon.moves[i]
\t\tlocal mv = move[moveId + 1] or ""
\t\tif moveId ~= 0 and (mv == nil or mv == "" or mv == "-") then
\t\t\tmv = string.format("Unknown Move %d", moveId)
\t\tend
\t\tif mv:lower() == "hidden power" then
\t\t\tstr = str .. string.format("- Hidden Power %s\\n", getHP(mon))
\t\telseif mv ~= "" then
\t\t\tstr = str .. string.format("- %s\\n", mv)
\t\tend
\tend
\tstr = str .. string.format("\\n")
\treturn str
end

function printPartyStatus(buffer)"""


PARTY_STATUS_REPLACEMENT = """function printPartyStatus(buffer)
\tlocal party = requireValidParty(getParty())
\tbuffer:clear()
\tfor _, mon in ipairs(party) do
\t\tif (mon.species ~= 0) then
\t\t\tbuffer:print(getPartyPrint(mon))
\t\tend
\tend
end

function printStorageStatus(buffer)
\tlocal storageLoc = getStorageLoc()
\tlocal address = storageLoc + 4
\tlocal i = 0
\tbuffer:clear()
\twhile i<storageSlotCount do
\t\tlocal boxMon = readBoxMon(address)
\t\tif boxMon.hasSpecies == 1 and isValidSpeciesId(boxMon.species) then
\t\t\tbuffer:print(getPCPrint(boxMon))
\t\tend
\t\ti = i+1
\t\taddress = address + 80
\tend
end

function getHP(mon)"""


HIDDENS_REPLACEMENT = """function getHiddens(buffer)
\tbuffer:clear()
\tlocal party = requireValidParty(getParty())
\tfor _, mon in ipairs(party) do
\t\tif (mon.species ~= 0) then
\t\t\tbuffer:print(string.format("%s - %s\\n", getSpeciesName(mon.species), getHP(mon)))
\t\tend
\tend
end

function hiddens()"""


START_AND_EXPORT_REPLACEMENT = """function startScript()
\tconsole:log('Type "export()" to refresh the Showdown Export buffer.')
\tif not partyBuffer then
\t\tpartyBuffer = console:createBuffer("Showdown Export")
\t\tpartyBuffer:setSize(400,1200)
\tend
\tif not storageBuffer then
\t\tstorageBuffer = console:createBuffer("Stored Pokemon")
\t\tstorageBuffer:setSize(400,1200)
\tend
\tif not hiddenBuffer then
\t\thiddenBuffer = console:createBuffer("Hidden Power Types")
\t\thiddenBuffer:setSize(260,200)
\tend
\texport()
end

function export()
\tif not partyBuffer then
\t\tpartyBuffer = console:createBuffer("Showdown Export")
\t\tpartyBuffer:setSize(400,1200)
\tend
\tif not storageBuffer then
\t\tstorageBuffer = console:createBuffer("Stored Pokemon")
\t\tstorageBuffer:setSize(400,1200)
\tend
\tif not hiddenBuffer then
\t\thiddenBuffer = console:createBuffer("Hidden Power Types")
\t\thiddenBuffer:setSize(260,200)
\tend
\tlocal ok, err = pcall(function()
\t\tprintPartyStatus(partyBuffer)
\t\tprintStorageStatus(storageBuffer)
\t\thiddens()
\tend)
\tif not ok then
\t\tconsole:log("[ERROR] " .. tostring(err))
\tend
end

callbacks:add("start", startScript)
if emu then
\tstartScript()
end"""


def build_output(template_path: Path, rom_path: Path, map_path: Path, elf_path: Path) -> str:
    constants_species = parse_defines(ROOT / "include" / "constants" / "species.h")
    constants_items = parse_defines(ROOT / "include" / "constants" / "items.h")
    constants_abilities = parse_defines(ROOT / "include" / "constants" / "abilities.h")
    constants_moves = parse_defines(ROOT / "include" / "constants" / "moves.h")
    constants_growth = parse_defines(ROOT / "include" / "constants" / "pokemon.h")
    storage_constants = parse_defines(ROOT / "include" / "pokemon_storage_system.h")

    species_info = parse_species_entries()
    item_names = parse_name_entries(ROOT / "src" / "data" / "items.h", "ITEM_")
    ability_names = parse_name_entries(ROOT / "src" / "data" / "abilities.h", "ABILITY_", override_none="None")
    move_names = parse_move_names()

    max_species_id = constants_species["SPECIES_EGG"]
    max_item_id = max(value for name, value in constants_items.items() if name.startswith("ITEM_"))
    max_move_id = max(value for name, value in constants_moves.items() if name.startswith("MOVE_"))
    total_boxes = storage_constants["TOTAL_BOXES_COUNT"]
    in_box_count = storage_constants["IN_BOX_COUNT"]
    storage_slot_count = total_boxes * in_box_count

    mons = ["" for _ in range(max_species_id)]
    curves = [0 for _ in range(max_species_id)]
    abilities = ["None" for _ in range(max_species_id * 3 + 3)]

    growth_lookup = {
        "GROWTH_MEDIUM_FAST": constants_growth["GROWTH_MEDIUM_FAST"],
        "GROWTH_ERRATIC": constants_growth["GROWTH_ERRATIC"],
        "GROWTH_FLUCTUATING": constants_growth["GROWTH_FLUCTUATING"],
        "GROWTH_MEDIUM_SLOW": constants_growth["GROWTH_MEDIUM_SLOW"],
        "GROWTH_FAST": constants_growth["GROWTH_FAST"],
        "GROWTH_SLOW": constants_growth["GROWTH_SLOW"],
    }

    for species_macro, info in species_info.items():
        species_id = constants_species.get(species_macro)
        if species_id is None or species_id == 0 or species_id > max_species_id:
            continue
        mons[species_id - 1] = info["name"]  # type: ignore[index]
        curves[species_id - 1] = growth_lookup[info["growth"]]  # type: ignore[index]
        ability_macros = info["abilities"]  # type: ignore[assignment]
        for offset, ability_macro in enumerate(ability_macros):
            ability_name = ability_names.get(ability_macro, "None")
            abilities[species_id * 3 + offset] = ability_name

    preferred_species_macros: dict[int, str] = {}
    for species_macro, species_id in constants_species.items():
        if not species_macro.startswith("SPECIES_") or species_id <= 0 or species_id > max_species_id:
            continue
        current = preferred_species_macros.get(species_id)
        if current is None or len(species_macro.removeprefix("SPECIES_").split("_")) > len(current.removeprefix("SPECIES_").split("_")):
            preferred_species_macros[species_id] = species_macro
    porydex_names = parse_porydex_species_names()
    for species_id, species_macro in preferred_species_macros.items():
        if mons[species_id - 1]:
            continue
        fallback_name = resolve_species_display_name(species_macro, humanize_species_macro(species_macro), porydex_names)
        mons[species_id - 1] = fallback_name

    items = ["" for _ in range(max_item_id)]
    for item_macro, item_id in constants_items.items():
        if not item_macro.startswith("ITEM_") or item_id <= 0 or item_id > max_item_id:
            continue
        if item_macro in item_names:
            items[item_id - 1] = item_names[item_macro]

    moves = ["" for _ in range(max_move_id + 1)]
    for move_macro, move_id in constants_moves.items():
        if not move_macro.startswith("MOVE_") or move_id < 0 or move_id > max_move_id:
            continue
        if move_macro in move_names:
            moves[move_id] = move_names[move_macro]

    ensure_fresh_build_artifacts(rom_path, map_path, elf_path)

    symbols = parse_map_symbols(
        map_path,
        ["gPlayerParty", "gPlayerPartyCount", "gPokemonStorage", "gPokemonStoragePtr"],
    )

    template = load_text(template_path)
    template = replace_section(template, "move = {", "\n\nmons = {", format_lua_string_array("move", moves) + "\n\n")
    template = replace_section(template, "mons = {", "\n\nitem = {", format_lua_string_array("mons", mons) + "\n\n")
    template = replace_section(template, "item = {", "\n\nability = {", format_lua_string_array("item", items) + "\n\n")
    template = replace_section(template, "ability = {", "\n\ncurve=", format_lua_string_array("ability", abilities) + "\n\n")
    template = replace_section(template, "curve={", "\n\nnature = {", format_lua_number_array("curve", curves) + "\n\n")

    template = replace_regex(
        template,
        r"local playerNameLength=\d+",
        "local playerNameLength=7",
    )
    offset_block = (
        f"local partyloc=0x{symbols['gPlayerParty']:08x} -- gPlayerParty\n"
        f"local partyCount=0x{symbols['gPlayerPartyCount']:08x} -- gPlayerPartyCount\n"
        f"local storageBaseLoc=0x{symbols['gPokemonStorage']:08x} -- gPokemonStorage (ASLR wrapper)\n"
        f"local storagePtrLoc=0x{symbols['gPokemonStoragePtr']:08x} -- gPokemonStoragePtr\n\n"
        f"local storageSlotCount={storage_slot_count} -- TOTAL_BOXES_COUNT * IN_BOX_COUNT\n\n"
    )
    if "local speciesNameTable=" in template:
        template = replace_regex(
            template,
            r"local partyloc=.*?local speciesNameTable=.*?\n\n",
            offset_block,
        )
    else:
        template = replace_regex(
            template,
            r"local partyloc=.*?local storagePtrLoc=.*?\n\n",
            offset_block,
        )
    template = replace_regex_if_missing(
        template,
        r"function getParty\(\)",
        "function getStorageLoc()\n\tlocal ptr = emu:read32(storagePtrLoc)\n\tif ptr == 0 then\n\t\treturn storageBaseLoc\n\tend\n\treturn ptr\nend\n\nfunction getParty()",
        "function getStorageLoc()",
    )
    template = replace_regex(
        template,
        r"function toString\(rawstring\).*?function _read16BE\(emu, address\)",
        TO_STRING_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"function readBoxMon\(address\).*?function readPartyMon\(address\)",
        READ_BOX_MON_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"(?:function getSpeciesName\(species\).*?end\s*)?function getAbility\(mon\).*?function getPartyPrint\(mon\)",
        NATURE_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"function getPartyPrint\(mon\).*?function getPCPrint\(mon\)",
        PARTY_PRINT_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"function getPCPrint\(mon\).*?function printPartyStatus\(buffer\)",
        PC_PRINT_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"function printPartyStatus\(buffer\).*?function getHP\(mon\)",
        PARTY_STATUS_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"function getHiddens\(buffer\).*?function hiddens\(\)",
        HIDDENS_REPLACEMENT,
    )
    template = replace_regex(
        template,
        r"function startScript\(\).*?if emu then\s*startScript\(\)\s*end",
        START_AND_EXPORT_REPLACEMENT,
    )
    template = replace_regex_if_missing(
        template,
        r"mon\.mail = emu:read32\(address \+ 85\)",
        "mon.mail = emu:read8(address + 85)",
        "mon.mail = emu:read8(address + 85)",
    )
    return template


def main() -> None:
    parser = argparse.ArgumentParser(description="Rigenera il Lua mGBA per Pokemon Smeragis dai dati correnti della hack.")
    parser.add_argument("--template", required=True, help="Path al template Lua di partenza.")
    parser.add_argument("--output", required=True, help="Path del file Lua da generare.")
    parser.add_argument("--rom", default=str(ROOT / "pokeemerald.gba"), help="Path della ROM caricata in mGBA.")
    parser.add_argument("--map", dest="map_path", default=str(ROOT / "pokeemerald.map"), help="Path del file .map con i simboli.")
    parser.add_argument("--elf", default=str(ROOT / "pokeemerald.elf"), help="Path del file .elf usato per generare i simboli.")
    args = parser.parse_args()

    template_path = Path(args.template)
    output_path = Path(args.output)
    rom_path = Path(args.rom)
    map_path = Path(args.map_path)
    elf_path = Path(args.elf)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output = build_output(template_path, rom_path, map_path, elf_path)
    output_path.write_text(output, encoding="utf-8", newline="\n")


if __name__ == "__main__":
    main()
