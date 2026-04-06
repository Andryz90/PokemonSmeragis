import os
import json
import re
import html
import unicodedata
from typing import List, Optional

# =============================
# Data models
# =============================
class Pokemon:
    def __init__(self):
        self.nickname: Optional[str] = None
        self.species: Optional[str] = None
        self.level: Optional[str] = None
        self.ability: Optional[str] = None
        self.gender: Optional[str] = None
        self.item: Optional[str] = None
        self.nature: Optional[str] = None
        self.ivs: Optional[dict] = None
        self.ivs_specified: bool = False
        self.teraType: Optional[str] = None
        self.status: Optional[str] = None
        self.index: Optional[int] = None
        self.moves: List[str] = []

class Trainer:
    def __init__(self):
        self.name: str = ""
        self.trainer_id: Optional[str] = None
        self.double_battle: str = "No"
        self.trainer_class: Optional[str] = None
        self.trainer_pic: Optional[str] = None
        self.party: List[Pokemon] = []

# =============================
# File utilities
# =============================
def delete_file(path: str):
    try:
        os.remove(path)
    except FileNotFoundError:
        pass

def ensure_dir_for(path: str):
    d = os.path.dirname(path)
    if d and not os.path.exists(d):
        os.makedirs(d, exist_ok=True)

def write_file(s: str, path: str, encoding="utf-8"):
    ensure_dir_for(path)
    with open(path, "w", encoding=encoding) as f:
        f.write(s)

# =============================
# Comment remover
# =============================
_COMMENT_RE = re.compile(
    r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
    re.DOTALL | re.MULTILINE
)

def _comment_replacer(match):
    s = match.group(0)
    return " " if s.startswith('/') else s

def strip_c_style_comments(text: str) -> str:
    return re.sub(_COMMENT_RE, _comment_replacer, text)

# =============================
# Input
# =============================
def get_party_contents(path: str) -> List[str]:
    with open(path, "r", encoding="utf-8") as f:
        raw = f.read()
    cleaned = strip_c_style_comments(raw)
    return cleaned.splitlines(keepends=True)

# =============================
# Parser (come il tuo)
# =============================
IGNORED_PREFIXES = (
    "Pic:", "Gender:", "Music:", "AI Flags:", "Battle Type:", "Text:",
    "Items:", "Win Text:", "Lose Text:", "Intro Text:", "Encounter Music:",
)

def ensure_default_ivs(mon: Pokemon):
    if mon.ivs is None:
        mon.ivs = {"hp": 31, "at": 31, "df": 31, "sa": 31, "sd": 31, "sp": 31}

def build_display_name(trainer_class: Optional[str], trainer_name: Optional[str], trainer_pic: Optional[str]) -> str:
    left = (trainer_class or "").strip()
    right = (trainer_name or "").strip()
    pic = (trainer_pic or "").strip()

    if pic in {
        "Swimmer M", "Swimmer F", "Cooltrainer M", "Cooltrainer F",
        "School Kid M", "School Kid F", "Pokefan M", "Pokefan F",
        "Expert M", "Expert F", "Psychic M", "Psychic F",
    }:
        left = pic
    elif pic.startswith("Pokemon Breeder"):
        left = pic
    else:
        triathlete_match = re.match(r"^(?:[A-Za-z]+\s+)?Triathlete\s+([MF])$", pic)
        if triathlete_match:
            left = f"Triathlete {triathlete_match.group(1)}"

    return (left + " " + right).strip() or right or "Unknown"

def parse_parties(lines: List[str]) -> List[Trainer]:
    trainer_parties: List[Trainer] = []
    trainer: Optional[Trainer] = None
    pokemon: Optional[Pokemon] = None
    prev_line: Optional[str] = None
    parsing_mon = False
    mon_index = 0
    trainer_name = None
    trainer_class = None
    trainer_pic = None
    trainer_id = None

    def close_mon():
        nonlocal parsing_mon, pokemon, mon_index, trainer
        if parsing_mon and pokemon:
            ensure_default_ivs(pokemon)
            pokemon.index = mon_index
            mon_index += 1
            if trainer:
                trainer.party.append(pokemon)
        parsing_mon = False

    def close_trainer():
        nonlocal trainer
        if trainer:
            trainer_parties.append(trainer)

    for line in lines:
        # ignora blocchi marcatori tipo "=== PARTNER_WALLY_DESERT ==="
        if line.strip().startswith("===") and "TRAINER_" not in line:
            prev_line = line
            continue
        
        if "REGULAR TRAINERS END" in line:
            break

        if line.startswith("Name:"):
            trainer_name = line.split(":", 1)[1].strip()
        elif line.startswith("Class:"):
            trainer_class = line.split(":", 1)[1].strip()
            close_mon()
            close_trainer()
            trainer = Trainer()
            trainer.name = build_display_name(trainer_class, trainer_name, trainer_pic)
            trainer.trainer_id = trainer_id
            trainer.trainer_class = trainer_class
            mon_index = 0
        elif line.startswith("Pic:"):
            trainer_pic = line.split(":", 1)[1].strip()
            if trainer:
                trainer.trainer_pic = trainer_pic
                trainer.name = build_display_name(trainer_class, trainer_name, trainer_pic)
        elif line.startswith("Double Battle:"):
            if trainer:
                trainer.double_battle = line.split(":", 1)[1].strip()

        elif line.startswith("=== TRAINER_"):
            m = re.match(r"===\s*(TRAINER_[A-Z0-9_]+)\s*===", line.strip())
            trainer_id = m.group(1) if m else None
            if (prev_line == "\n" or prev_line is None):
                close_mon()
                close_trainer()
                trainer = None
                trainer_name = None
                trainer_class = None
                trainer_pic = None

        elif (prev_line == "\n") and not any(line.startswith(p) for p in ("Name:", "Class:", "Double Battle:") + IGNORED_PREFIXES) and line.strip():
            parsing_mon = True
            pokemon = Pokemon()
            parts = line.split("@", 1)
            pokemon.species = parts[0].strip()
            pokemon.item = parts[1].strip() if len(parts) > 1 and parts[1].strip() else None

        elif parsing_mon:
            if line == "\n":
                close_mon()
            elif line.startswith("Ability:"):
                pokemon.ability = line.split(":", 1)[1].strip()
            elif line.startswith("Level:"):
                pokemon.level = line.split(":", 1)[1].strip()
            elif line.startswith("Tera Type:"):
                pokemon.teraType = line.split(":", 1)[1].strip()
            elif line.startswith("Status:"):
                pokemon.status = line.split(":", 1)[1].strip()
            elif line.startswith("Nature:"):
                pokemon.nature = line.split(":", 1)[1].strip()
            elif line.strip().endswith("Nature"):
                m = re.match(r"^\s*([A-Za-z]+)\s+Nature\s*$", line.strip())
                if m:
                    pokemon.nature = m.group(1).strip()
            elif line.startswith("IVs:"):
                _STAT_NAME_MAP = {"hp": "hp", "atk": "at", "def": "df", "spa": "sa", "spd": "sd", "spe": "sp"}
                ival = line.split(":", 1)[1].strip()
                ivs = {"hp": 31, "at": 31, "df": 31, "sa": 31, "sd": 31, "sp": 31}
                for seg in ival.split("/"):
                    seg = seg.strip()
                    parts = seg.split()
                    if len(parts) == 2:
                        val_str, stat_name = parts
                        key = _STAT_NAME_MAP.get(stat_name.lower())
                        if key:
                            ivs[key] = int(val_str)
                    elif len(parts) == 1 and parts[0].isdigit():
                        # positional fallback (shouldn't happen in Showdown format)
                        pass
                pokemon.ivs = ivs
                pokemon.ivs_specified = True
            elif line.startswith("- "):
                pokemon.moves.append(line[2:].strip())
            else:
                pass

        prev_line = line

    if parsing_mon and pokemon:
        ensure_default_ivs(pokemon)
        pokemon.index = mon_index
        if trainer:
            trainer.party.append(pokemon)
    if trainer:
        trainer_parties.append(trainer)

    return trainer_parties

# =============================
# Helpers: when to show IVs
# =============================
def needs_ivs_row(mon: Pokemon) -> bool:
    if not mon.moves:
        return False
    return any(m.lower().startswith("hidden power") for m in mon.moves)

# =============================
# Output: Mastersheet (Markdown)
# =============================
def get_mon_suffix(mon: Pokemon) -> str:
    bits = []
    if mon.level:   bits.append(f"Lv.{mon.level}")
    if mon.ability: bits.append(mon.ability)
    if mon.nature:  bits.append(f"{mon.nature} Nature")
    if mon.teraType:bits.append(f"Tera: {mon.teraType}")
    if mon.status:  bits.append(f"Status: {mon.status}")
    if needs_ivs_row(mon) and mon.ivs:
        ivs = mon.ivs
        bits.append("IVs " + "/".join(str(ivs[k]) for k in ("hp","at","df","sa","sd","sp")))
    return " | ".join(bits)

def generate_mastersheet(trainers: List[Trainer]) -> str:
    out = []
    for tr in trainers:
        title = f"## {tr.name} {'[Double Battle]' if tr.double_battle.lower() == 'yes' else ''}".strip()
        out.append(title)
        for mon in tr.party:
            item = f" @{mon.item}" if mon.item else ""
            suffix = get_mon_suffix(mon)
            if suffix:
                out.append(f"{mon.species}{item}: {', '.join(mon.moves) if mon.moves else ''} [{suffix}]  ")
            else:
                out.append(f"{mon.species}{item}: {', '.join(mon.moves) if mon.moves else ''}  ")
        out.append("")
    return "\n".join(out).rstrip() + "\n"

# =============================
# Output: JS (per calculator)
# =============================
def _is_relevant_trainer(trainer: Trainer) -> bool:
    """A trainer is relevant if at least one Pokemon has at least one move."""
    return any(bool(mon.moves) for mon in trainer.party)

def _location_suffix(trainer_id: Optional[str], trainer_name: str) -> Optional[str]:
    """Extract a human-readable location/version suffix from the trainer_id.

    Examples:
      TRAINER_GRUNT_RUSTURF_TUNNEL       + "Team Aqua GRUNT"   -> "Rusturf Tunnel"
      TRAINER_MAGMA_GRUNT_ROUTE114       + "Team Magma GRUNT"  -> "Route114"
      TRAINER_WINONA_3                   + "Leader WINONA"     -> "3"
      TRAINER_DECLAN                     + "Swimmer M DECLAN"  -> None (exact match)
    """
    if not trainer_id:
        return None
    tid = trainer_id.upper()
    for prefix in ("TRAINER_", "PARTNER_"):
        if tid.startswith(prefix):
            tid = tid[len(prefix):]
            break

    # Try progressively more words from the right side of the name as the key.
    # e.g. "Team Magma GRUNT" -> try "GRUNT", then "MAGMA_GRUNT", then "TEAM_MAGMA_GRUNT"
    name_words = re.sub(r"[^A-Z0-9 ]", "", trainer_name.upper()).split()
    if not name_words:
        return None

    for n in range(1, len(name_words) + 1):
        name_key = "_".join(name_words[-n:])
        if tid == name_key:
            return None  # exact match, no suffix
        if tid.startswith(name_key + "_"):
            suffix = tid[len(name_key) + 1:]
            return suffix.replace("_", " ").title()
    return None

def generate_cals_sets(trainers: List[Trainer]) -> str:
    # Numeric-versioned trainers (e.g., WINONA_1..5): keep only the lowest version,
    # displayed without the number. Location-based variants keep individual entries.
    best_numeric: dict[str, tuple[int, Trainer]] = {}
    for tr in trainers:
        if not _is_relevant_trainer(tr):
            continue
        base = (tr.name or "Unknown").strip() or "Unknown"
        suffix = _location_suffix(tr.trainer_id, base)
        if suffix is not None and suffix.isdigit():
            num = int(suffix)
            if base not in best_numeric or num < best_numeric[base][0]:
                best_numeric[base] = (num, tr)

    data: dict = {}
    used_labels: dict[str, int] = {}
    trainer_index = 0
    seen_numeric: set[str] = set()
    for tr in trainers:
        if not _is_relevant_trainer(tr):
            continue
        base = (tr.name or "Unknown").strip() or "Unknown"
        suffix = _location_suffix(tr.trainer_id, base)
        if suffix is not None and suffix.isdigit():
            if best_numeric.get(base, (None, None))[1] is not tr or base in seen_numeric:
                continue
            seen_numeric.add(base)
            tr_label = base
        else:
            tr_label = f"{base} ({suffix})" if suffix else base

        trainer_index += 1
        if tr_label in used_labels:
            used_labels[tr_label] += 1
            tr_label = f"{tr_label} [{used_labels[tr_label]}]"
        else:
            used_labels[tr_label] = 1

        fallback_level = next((m.level for m in tr.party if m.level), "1")
        for slot_fallback, mon in enumerate(tr.party):
            species = re.sub(r"\s*\((?:M|F)\)\s*$", "", (mon.species or "").strip())
            if not species:
                continue
            slot_index = mon.index if mon.index is not None else slot_fallback
            data.setdefault(species, {})[tr_label] = {
                "index": trainer_index,
                "slot": slot_index,
                "level": mon.level if mon.level else fallback_level,
                "ivs": mon.ivs if mon.ivs else {"hp":31,"at":31,"df":31,"sa":31,"sd":31,"sp":31},
                "ivsSpecified": mon.ivs_specified,
                "item": mon.item,
                "ability": mon.ability,
                "nature": mon.nature,
                "moves": mon.moves,
            }
    return "window.TRAINER_SETS = " + json.dumps(data, ensure_ascii=False, indent=2) + ";\n"

# =============================
# HTML helpers
# =============================
def get_html_header() -> List[str]:
    header_path = "./header.html"
    if os.path.exists(header_path):
        with open(header_path, "r", encoding="utf-8") as f:
            return f.read().splitlines(keepends=True)
    return [
        "<!DOCTYPE html>\n",
        "<html lang=\"en\">\n",
        "<head>\n",
        "  <meta charset=\"UTF-8\">\n",
        "  <title>Styled Table Example</title>\n",
        "  <link rel=\"stylesheet\" href=\"sheet_style.css\">\n",
        "</head>\n",
        "<body>\n",
    ]

def sprite_url(species: str) -> str:
    if not species:
        return "https://play.pokemonshowdown.com/sprites/gen5/.png"
    s = re.sub(r"\s*\((?:M|F|Male|Female)\)\s*$", "", species, flags=re.I)
    s = unicodedata.normalize("NFKD", s).encode("ascii", "ignore").decode("ascii")
    s = s.lower().strip()
    s = re.sub(r"[.\'’_:]", "", s)
    s = s.replace(" ", "")
    aliases = {
        "porygon-z": "porygonz",
        "mr-mime": "mrmime",
        "mime-jr": "mimejr",
        "jangmo-o": "jangmoo",
        "hakamo-o": "hakamoo",
        "kommo-o": "kommoo",
        "nidoran-f": "nidoranf",
        "nidoran-m": "nidoranm",
    }
    s = aliases.get(s, s)
    return f"https://play.pokemonshowdown.com/sprites/gen5/{s}.png"

# =============================
# Output: Webpage with tables
# =============================
def generate_webpage(trainers: List[Trainer]) -> str:
    html_parts: List[str] = ["".join(get_html_header()) + "\n"]

    for tr in trainers:
        real_party = [m for m in tr.party if m and (m.species or "").strip()]
        if not real_party:
            continue

        trainer_id_attr = html.escape((tr.trainer_id or "").strip(), quote=True)
        trainer_name_attr = html.escape((tr.name or "").strip(), quote=True)
        html_parts.append(
            f'<table class="content-table" data-trainer-id="{trainer_id_attr}" '
            f'data-trainer-name="{trainer_name_attr}">'
        )
        caption = tr.name + (" [Double Battle]" if tr.double_battle and tr.double_battle.strip().lower() == "yes" else "")
        html_parts.append(f'<caption class="caption-content">{caption}</caption>')
        html_parts.append("<tbody>")

        mons = real_party[:6] + [Pokemon() for _ in range(max(0, 6 - len(real_party[:6])))]

        html_parts.append('<tr> <!-- Images -->')
        for m in mons:
            html_parts.append(f"<td><img src=\"{sprite_url(m.species)}\" alt=\"\"></img></td>")
        html_parts.append("</tr>")

        html_parts.append('<tr> <!-- Species -->')
        for m in mons:
            html_parts.append(f"<th>{m.species or ''}</th>")
        html_parts.append("</tr>")

        html_parts.append("<tr>")
        for m in mons:
            html_parts.append(f"<td>{m.level or ''}</td>")
        html_parts.append("</tr>")

        if any((m.item or "").strip() for m in mons):
            html_parts.append("<tr>")
            for m in mons:
                html_parts.append(f"<td>{m.item or ''}</td>")
            html_parts.append("</tr>")

        html_parts.append("<tr>")
        for m in mons:
            html_parts.append(f"<td>{m.ability or ''}</td>")
        html_parts.append("</tr>")

        if any(any(move.lower().startswith("hidden power") for move in m.moves) for m in mons):
            html_parts.append("<tr>")
            for m in mons:
                if any(move.lower().startswith("hidden power") for move in m.moves) and m.ivs:
                    ivs = m.ivs
                    iv_txt = "/".join(str(ivs[k]) for k in ("hp","at","df","sa","sd","sp"))
                    html_parts.append(f"<td>{iv_txt}</td>")
                else:
                    html_parts.append("<td></td>")
            html_parts.append("</tr>")

        if any((m.nature or "").strip() for m in mons):
            html_parts.append("<tr>")
            for m in mons:
                html_parts.append(f"<td>{m.nature or ''}</td>")
            html_parts.append("</tr>")

        max_moves = min(max((len(m.moves) for m in mons), default=0), 4)
        for r in range(max_moves):
            if not any(len(m.moves) > r for m in mons):
                continue
            html_parts.append("<tr>")
            for m in mons:
                move = m.moves[r] if len(m.moves) > r else ""
                html_parts.append(f"<td>{move}</td>")
            html_parts.append("</tr>")

        html_parts.append("</tbody>")
        html_parts.append("</table>\n")

    html_final = "\n".join(html_parts)
    if "</body>" not in html_final.lower():
        html_final += "\n</body>\n</html>\n"
    return html_final

# =============================
# main
# =============================
if __name__ == "__main__":
    source = "./trainers.party"
    partners = "./battle_partners.party"  # [NEW]
    mastersheet = "./mastersheet.md"
    calc_sets = "./gen9.js"
    webpage = "./site/index.html"

    parsed_trainers = parse_parties(get_party_contents(source))
    print("Num of trainers:", len(parsed_trainers))

    # [NEW] Partner: se esiste, parse e prefissa "Partner " al nome (per caption/tokens)
    if os.path.exists(partners):
        partner_trainers = parse_parties(get_party_contents(partners))
        for tr in partner_trainers:
            tr.name = ("Partner " + tr.name).strip()
        print("Num of partners:", len(partner_trainers))
        parsed_trainers.extend(partner_trainers)

    delete_file(mastersheet)
    write_file(generate_mastersheet(parsed_trainers), mastersheet)

    delete_file(calc_sets)
    write_file(generate_cals_sets(parsed_trainers), calc_sets)

    delete_file(webpage)
    write_file(generate_webpage(parsed_trainers), webpage)

    print("OK: generated mastersheet.md, gen9.js, site/index.html")
