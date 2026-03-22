from __future__ import annotations

import json
import re
from collections import defaultdict
from pathlib import Path


LABEL_RE = re.compile(r"^\s*[A-Za-z0-9_]+::?\s*$")
SETVAR_RE = re.compile(r"^\s*setvar\s+(VAR_[A-Z0-9x_]+)\s*,\s*([A-Z0-9_()]+)\b", re.IGNORECASE)
COPYVAR_RE = re.compile(r"^\s*copyvar\s+(VAR_[A-Z0-9x_]+)\s*,\s*(VAR_[A-Z0-9x_]+)\b", re.IGNORECASE)
RANDOMELEMENT_RE = re.compile(r"^\s*randomelement\s+(.+)$", re.IGNORECASE)
SETWILDBATTLE_RE = re.compile(r"^\s*setwildbattle\s+((?:SPECIES|VAR)_[A-Z0-9_]+)\s*,\s*([^,\s]+)", re.IGNORECASE)
SETEVENTMON_RE = re.compile(r"^\s*seteventmon\s+((?:SPECIES|VAR)_[A-Z0-9_]+)\s*,\s*([^,\s]+)", re.IGNORECASE)
GIVEMON_RE = re.compile(r"^\s*givemon\s+((?:SPECIES|VAR)_[A-Z0-9_]+)\s*,\s*([^,\s]+)", re.IGNORECASE)
GIVEEGG_RE = re.compile(r"^\s*giveegg\s+((?:SPECIES|VAR)_[A-Z0-9_]+)\b", re.IGNORECASE)
SPECIAL_GIVEMON_RE = re.compile(r"^\s*special\s+Script_GiveMonSpecial\b", re.IGNORECASE)
SPECIAL_CHOOSE_STARTER_RE = re.compile(r"^\s*special\s+ChooseStarter\b", re.IGNORECASE)
OBJ_EVENT_SPECIES_RE = re.compile(r"OBJ_EVENT_GFX_SPECIES\(([A-Z0-9_]+)\)")
STARTER_ARRAY_RE = re.compile(r"static const u16 sStarterMon\[STARTER_MON_COUNT\]\s*=\s*\{(.*?)\};", re.DOTALL)


def _repo_root() -> Path:
    return Path(__file__).resolve().parents[3]


def _strip_comment(line: str) -> str:
    return line.split("@", 1)[0].rstrip()


def _prettify_label(raw: str) -> str:
    raw = (raw or "").strip()
    if not raw:
        return ""
    raw = raw.replace("_", " ")
    raw = re.sub(r"([a-z0-9])([A-Z])", r"\1 \2", raw)
    raw = re.sub(r"([A-Za-z])(\d)", r"\1 \2", raw)
    raw = re.sub(r"(\d)([A-Za-z])", r"\1 \2", raw)
    raw = re.sub(r"\s+", " ", raw).strip()
    return " ".join(word.capitalize() if word.isupper() else word for word in raw.split())


def _load_section_names(root: Path) -> dict[str, str]:
    out: dict[str, str] = {}
    src = root / "src" / "data" / "region_map" / "region_map_sections.json"
    if not src.exists():
        return out
    data = json.loads(src.read_text(encoding="utf-8"))
    for sec in data.get("map_sections", []):
        sid = sec.get("id")
        name = sec.get("name")
        if sid and name:
            out[sid] = _prettify_label(name)
    return out


def _load_map_locations(root: Path, section_names: dict[str, str]) -> dict[str, str]:
    out: dict[str, str] = {}
    maps_dir = root / "data" / "maps"
    if not maps_dir.exists():
        return out

    for map_json in maps_dir.glob("*/map.json"):
        try:
            data = json.loads(map_json.read_text(encoding="utf-8"))
        except Exception:
            continue
        folder = map_json.parent.name
        map_section = data.get("region_map_section", "")
        out[folder] = section_names.get(map_section, _prettify_label(folder))
    return out


def _load_species_keys(root: Path) -> set[str]:
    species_js = root / "docs" / "Documentation_Sites" / "porydex" / "site" / "data" / "species.js"
    if not species_js.exists():
        return set()
    text = species_js.read_text(encoding="utf-8", errors="replace")
    return set(re.findall(r'^\s{4}"([a-z0-9]+)":\s*\{', text, flags=re.MULTILINE))


def _token_to_species_id(token: str, valid_species: set[str]) -> str:
    token = token.upper().strip().removeprefix("SPECIES_")
    candidates = [token]
    for old, new in (
        ("_ALOLAN", "_ALOLA"),
        ("_GALARIAN", "_GALAR"),
        ("_HISUIAN", "_HISUI"),
        ("_PALDEAN", "_PALDEA"),
    ):
        if token.endswith(old):
            candidates.append(token[: -len(old)] + new)
    if token.endswith("_NORMAL"):
        candidates.append(token[:-7])
    if token.endswith("_BASE"):
        candidates.append(token[:-5])

    for candidate in candidates:
        species_id = candidate.lower().replace("_", "")
        if species_id in valid_species:
            return species_id

    return token.lower().replace("_", "")


def _parse_int_token(value: object) -> int | None:
    text = str(value or "").strip()
    if not text:
        return None
    if re.fullmatch(r"\d+", text):
        return int(text, 10)
    if re.fullmatch(r"0x[0-9a-fA-F]+", text):
        return int(text, 16)
    return None


def _parse_bool_token(value: object) -> bool | None:
    text = str(value or "").strip().upper()
    if text == "TRUE":
        return True
    if text == "FALSE":
        return False
    return None


def _load_hoenn_starters(root: Path, valid_species: set[str]) -> list[str]:
    starter_file = root / "src" / "starter_choose.c"
    if not starter_file.exists():
        return []
    text = starter_file.read_text(encoding="utf-8", errors="replace")
    match = STARTER_ARRAY_RE.search(text)
    if not match:
        return []
    starters: list[str] = []
    for species_token in re.findall(r"\bSPECIES_[A-Z0-9_]+\b", match.group(1)):
        species_id = _token_to_species_id(species_token, valid_species)
        if species_id not in starters:
            starters.append(species_id)
    return starters


def _resolve_location_label(token: object, section_names: dict[str, str], fallback: str) -> str:
    text = str(token or "").strip()
    if not text:
        return fallback
    if text in section_names:
        return section_names[text]
    if text.startswith("MAPSEC_"):
        return section_names.get(text, _prettify_label(text[len("MAPSEC_") :]))
    if text.startswith("METLOC_"):
        return _prettify_label(text[len("METLOC_") :])
    return fallback


def _species_ids_from_value(value: object, valid_species: set[str]) -> list[str]:
    if value is None:
        return []
    values = value if isinstance(value, list) else [value]
    out: list[str] = []
    for raw in values:
        text = str(raw or "").strip()
        if not text.upper().startswith("SPECIES_"):
            continue
        species_id = _token_to_species_id(text, valid_species)
        if species_id and species_id not in out:
            out.append(species_id)
    return out


def _add_encounter(
    by_species: dict[str, list[dict]],
    dedupe: set[tuple[str, str, int, str]],
    species_id: str,
    location: str,
    level: int | None,
    kind: str,
    zoneid: str,
) -> None:
    if not species_id or not location:
        return
    level_value = int(level or 0)
    label = f"{location} ({kind})"
    key = (species_id, label, level_value, kind)
    if key in dedupe:
        return
    dedupe.add(key)
    by_species[species_id].append(
        {
            "name": label,
            "level": level_value,
            "rate": kind,
            "mode": "static",
            "zoneid": zoneid,
        }
    )


def _parse_script_file(
    path: Path,
    default_location: str,
    zone_prefix: str,
    section_names: dict[str, str],
    hoenn_starters: list[str],
    valid_species: set[str],
    by_species: dict[str, list[dict]],
    dedupe: set[tuple[str, str, int, str]],
    *,
    prefer_default_location: bool,
) -> None:
    try:
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    except Exception:
        return

    vars_state: dict[str, object] = {}

    for line_no, line in enumerate(lines, start=1):
        stripped = _strip_comment(line).strip()
        if not stripped:
            continue

        if LABEL_RE.match(stripped):
            vars_state = {}
            continue

        match = RANDOMELEMENT_RE.match(stripped)
        if match:
            tokens = [token.strip() for token in match.group(1).split(",") if token.strip()]
            vars_state["VAR_RESULT"] = tokens
            continue

        match = SETVAR_RE.match(stripped)
        if match:
            vars_state[match.group(1)] = match.group(2)
            continue

        match = COPYVAR_RE.match(stripped)
        if match:
            dest, source = match.groups()
            if source in vars_state:
                vars_state[dest] = vars_state[source]
            else:
                vars_state.pop(dest, None)
            continue

        match = SETWILDBATTLE_RE.match(stripped)
        if match:
            species_values = _species_ids_from_value(match.group(1), valid_species)
            level = _parse_int_token(match.group(2))
            for species_id in species_values:
                _add_encounter(
                    by_species,
                    dedupe,
                    species_id,
                    default_location,
                    level,
                    "Static",
                    f"{zone_prefix}-static-{line_no}",
                )
            continue

        match = SETEVENTMON_RE.match(stripped)
        if match:
            species_values = _species_ids_from_value(match.group(1), valid_species)
            level = _parse_int_token(match.group(2))
            for species_id in species_values:
                _add_encounter(
                    by_species,
                    dedupe,
                    species_id,
                    default_location,
                    level,
                    "Event",
                    f"{zone_prefix}-event-{line_no}",
                )
            continue

        match = GIVEMON_RE.match(stripped)
        if match:
            species_values = _species_ids_from_value(match.group(1), valid_species)
            level = _parse_int_token(match.group(2))
            for species_id in species_values:
                _add_encounter(
                    by_species,
                    dedupe,
                    species_id,
                    default_location,
                    level,
                    "Gift",
                    f"{zone_prefix}-gift-{line_no}",
                )
            continue

        match = GIVEEGG_RE.match(stripped)
        if match:
            species_values = _species_ids_from_value(match.group(1), valid_species)
            for species_id in species_values:
                _add_encounter(
                    by_species,
                    dedupe,
                    species_id,
                    default_location,
                    5,
                    "Egg",
                    f"{zone_prefix}-egg-{line_no}",
                )
            continue

        if SPECIAL_GIVEMON_RE.match(stripped):
            species_values = _species_ids_from_value(vars_state.get("VAR_RESULT"), valid_species)
            if not species_values:
                continue
            level = _parse_int_token(vars_state.get("VAR_0x8000"))
            is_egg = _parse_bool_token(vars_state.get("VAR_0x8003"))
            location = default_location
            if not prefer_default_location:
                location = _resolve_location_label(vars_state.get("VAR_0x8004"), section_names, default_location)
            kind = "Egg" if is_egg else "Gift"
            for species_id in species_values:
                _add_encounter(
                    by_species,
                    dedupe,
                    species_id,
                    location,
                    level if level is not None else (5 if is_egg else 0),
                    kind,
                    f"{zone_prefix}-{kind.lower()}-{line_no}",
                )
            continue

        if SPECIAL_CHOOSE_STARTER_RE.match(stripped):
            for species_id in hoenn_starters:
                _add_encounter(
                    by_species,
                    dedupe,
                    species_id,
                    default_location,
                    5,
                    "Starter",
                    f"{zone_prefix}-starter-{line_no}",
                )


def _parse_overworld_maps(
    root: Path,
    map_locations: dict[str, str],
    valid_species: set[str],
    by_species: dict[str, list[dict]],
    dedupe: set[tuple[str, str, int, str]],
) -> None:
    for map_json in (root / "data" / "maps").glob("*/map.json"):
        try:
            data = json.loads(map_json.read_text(encoding="utf-8"))
        except Exception:
            continue

        folder = map_json.parent.name
        location = map_locations.get(folder, _prettify_label(folder))
        object_events = data.get("object_events") or []
        for index, obj in enumerate(object_events):
            if obj.get("script") != "Common_EventScript_WildOWMon":
                continue
            graphics_id = str(obj.get("graphics_id") or "")
            species_match = OBJ_EVENT_SPECIES_RE.search(graphics_id)
            if not species_match:
                continue

            species_id = _token_to_species_id(species_match.group(1), valid_species)
            level = _parse_int_token(obj.get("trainer_sight_or_berry_tree_id"))
            if not level:
                level = 20
            _add_encounter(
                by_species,
                dedupe,
                species_id,
                location,
                level,
                "Overworld",
                f"{folder.lower()}-overworld-{index}",
            )


def build_static_encounters() -> dict[str, list[dict]]:
    root = _repo_root()
    section_names = _load_section_names(root)
    map_locations = _load_map_locations(root, section_names)
    valid_species = _load_species_keys(root)
    hoenn_starters = _load_hoenn_starters(root, valid_species)

    by_species: dict[str, list[dict]] = defaultdict(list)
    dedupe: set[tuple[str, str, int, str]] = set()

    for scripts in (root / "data" / "maps").glob("*/scripts.inc"):
        folder = scripts.parent.name
        location = map_locations.get(folder, _prettify_label(folder))
        _parse_script_file(
            scripts,
            location,
            folder.lower(),
            section_names,
            hoenn_starters,
            valid_species,
            by_species,
            dedupe,
            prefer_default_location=True,
        )

    for scripts in (root / "data" / "scripts").glob("*.inc"):
        if scripts.name.lower() == "debug.inc":
            continue
        fallback_location = _prettify_label(scripts.stem)
        _parse_script_file(
            scripts,
            fallback_location,
            scripts.stem.lower(),
            section_names,
            hoenn_starters,
            valid_species,
            by_species,
            dedupe,
            prefer_default_location=False,
        )

    _parse_overworld_maps(root, map_locations, valid_species, by_species, dedupe)

    out: dict[str, list[dict]] = {}
    for species_id in sorted(by_species):
        out[species_id] = sorted(
            by_species[species_id],
            key=lambda entry: (entry["name"], entry["level"], entry["zoneid"]),
        )
    return out


def write_output(encounters: dict[str, list[dict]]) -> Path:
    root = _repo_root()
    out_file = root / "docs" / "Documentation_Sites" / "porydex" / "site" / "js" / "static-encounters.js"
    out_file.parent.mkdir(parents=True, exist_ok=True)
    with out_file.open("w", encoding="utf-8", newline="\n") as handle:
        handle.write("window.BattleStaticEncounters = window.BattleStaticEncounters || {};\n")
        handle.write("Object.assign(window.BattleStaticEncounters, ")
        json.dump(encounters, handle, ensure_ascii=False, indent=4)
        handle.write(");\n")
    return out_file


if __name__ == "__main__":
    data = build_static_encounters()
    out = write_output(data)
    print(f"Wrote {len(data)} species with static/event/gift/overworld encounters -> {out}")
