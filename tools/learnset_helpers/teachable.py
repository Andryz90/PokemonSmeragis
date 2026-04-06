import glob
import json
import os
import re


PORYMOVES_DIR = "./tools/learnset_helpers/porymoves_files"
TEACHABLE_HEADER = "./src/data/pokemon/teachable_learnsets.h"
LEVELUP_HEADER = "./src/data/pokemon/level_up_learnsets/gen_9.h"
CUSTOM_TEACHABLE_JSON = os.path.join(PORYMOVES_DIR, "custom.json")
CURRENT_GENERATION = 9

MOVESET_KEYS = ("LevelMoves", "PreEvoMoves", "TMMoves", "EggMoves", "TutorMoves")
NON_LEVEL_KEYS = ("PreEvoMoves", "TMMoves", "EggMoves", "TutorMoves")
TEACHABLE_KEYS = ("TMMoves", "TutorMoves")
HEADER_WARNING = "// DO NOT MODIFY THIS FILE! "

GEN_FILE_PRIORITY = {
    1: ["rgb.json", "xd.json"],
    2: ["c.json", "gs.json"],
    3: ["frlg.json", "rse.json"],
    4: ["hgss.json", "pt.json", "dp.json"],
    5: ["b2w2.json", "bw.json"],
    6: ["oras.json", "xy.json", "y.json"],
    7: ["usum.json", "sm.json", "lgpe.json"],
    8: ["swsh.json", "bdsp.json", "la.json"],
    9: ["sv.json"],
}

ACTIVE_FALLBACK_FILES = {
    9: ["sv.json"],
    8: ["swsh.json"],
    7: ["usum.json"],
}


def parse_mon_name(name):
    return re.sub(r"(?!^)([A-Z]+)", r"_\1", name).upper()


def empty_entry():
    return {key: [] for key in MOVESET_KEYS}


def load_json(path):
    with open(path, "r") as file:
        return json.load(file)


def dump_json(path, payload):
    with open(path, "w") as file:
        json.dump(payload, file, indent=2)


def generation_sort_key(gen, path):
    basename = os.path.basename(path)
    priority = GEN_FILE_PRIORITY.get(gen, [])
    try:
        index = priority.index(basename)
    except ValueError:
        index = len(priority)
    return (index, basename)


def get_generation_paths(gen):
    pattern = os.path.join(PORYMOVES_DIR, f"Gen{gen}", "*.json")
    return sorted(
        [
            path
            for path in glob.glob(pattern)
            if os.path.basename(path).lower() != "zcustom.json"
        ],
        key=lambda path: generation_sort_key(gen, path),
    )


def get_active_generation_paths(gen):
    active_files = ACTIVE_FALLBACK_FILES.get(gen)
    if active_files is None:
        return get_generation_paths(gen)

    paths = []
    for filename in active_files:
        path = os.path.join(PORYMOVES_DIR, f"Gen{gen}", filename)
        if os.path.exists(path):
            paths.append(path)
    return paths


def build_source_catalog():
    catalog = []
    for gen in range(CURRENT_GENERATION, 0, -1):
        for path in get_active_generation_paths(gen):
            catalog.append((path, load_json(path)))
    return catalog


def list_header_mons(path, pattern):
    with open(path, "r") as file:
        raw = file.read()
    return re.findall(pattern, raw), raw


def append_unique_move(container, move):
    if move not in container:
        container.append(move)


def collect_teachable_moves(entry):
    moves = []
    for key in TEACHABLE_KEYS:
        for move in entry.get(key, []):
            if move == "MOVE_TERA_BLAST":
                continue
            append_unique_move(moves, move)
    return moves


def collect_level_moves(entry):
    moves = []
    seen_moves = set()
    for move in entry.get("LevelMoves", []):
        move_name = move["Move"]
        if move_name in seen_moves:
            continue
        seen_moves.add(move_name)
        moves.append({"Move": move_name, "Level": int(move["Level"])})
    return moves


def has_non_level_data(entry):
    return any(entry.get(key) for key in NON_LEVEL_KEYS)


def next_levelup_fallback(entries):
    for _, entry in entries:
        if entry.get("LevelMoves"):
            return entry
    return None


def should_skip_level_source(entry, fallback_entries):
    level_moves = entry.get("LevelMoves", [])
    if not level_moves:
        return True

    if has_non_level_data(entry):
        return False

    fallback_entry = next_levelup_fallback(fallback_entries)
    if fallback_entry is None:
        return False

    if has_non_level_data(fallback_entry):
        return True

    return len(fallback_entry.get("LevelMoves", [])) > len(level_moves)


def resolve_mon_entries(mon_name, source_catalog):
    entries = []
    for path, data in source_catalog:
        entry = data.get(mon_name)
        if entry is not None:
            entries.append((path, entry))
    return entries


def resolve_teachable_moves(mon_name, source_catalog):
    entries = resolve_mon_entries(mon_name, source_catalog)
    if not entries:
        return None

    for _, entry in entries:
        moves = collect_teachable_moves(entry)
        if moves:
            return moves

    return []


def resolve_level_moves(mon_name, source_catalog):
    entries = resolve_mon_entries(mon_name, source_catalog)
    if not entries:
        return None

    for index, (_, entry) in enumerate(entries):
        if should_skip_level_source(entry, entries[index + 1:]):
            continue
        return collect_level_moves(entry)

    return []


def preserve_custom_teachable_moves(compatibility_dict, raw_header):
    if HEADER_WARNING in raw_header:
        return compatibility_dict

    custom_teachables = {}
    for entry in re.findall(r"static const u16 s(.*)TeachableLearnset\[\] = {\n((.|\n)*?)\n};", raw_header):
        mon_name = parse_mon_name(entry[0])
        if mon_name == "NONE":
            continue

        custom_teachables.setdefault(mon_name, [])
        for move in entry[1].split("\n"):
            move = move.replace(",", "").strip()
            if move == "" or move == "MOVE_UNAVAILABLE":
                continue
            if mon_name not in compatibility_dict or move not in compatibility_dict[mon_name]:
                append_unique_move(custom_teachables[mon_name], move)

    custom_payload = load_json(CUSTOM_TEACHABLE_JSON) if os.path.exists(CUSTOM_TEACHABLE_JSON) else {}
    wrote_custom_payload = False
    for mon_name, moves in custom_teachables.items():
        if not moves:
            continue

        custom_payload.setdefault(mon_name, empty_entry())
        compatibility_dict.setdefault(mon_name, [])
        for move in moves:
            append_unique_move(custom_payload[mon_name]["TutorMoves"], move)
            append_unique_move(compatibility_dict[mon_name], move)
        wrote_custom_payload = True

    if wrote_custom_payload:
        dump_json(CUSTOM_TEACHABLE_JSON, custom_payload)
        print("FIRST RUN: Updated custom.json with teachable_learnsets.h's data")

    return compatibility_dict


def preserve_custom_level_moves(compatibility_dict, level_for_moves, raw_header):
    custom_found = False
    for entry in re.findall(r"static const struct LevelUpMove s(.*)LevelUpLearnset\[\] = {\n((.|\n)*?)\n};", raw_header):
        mon_name = parse_mon_name(entry[0])
        if mon_name == "NONE":
            continue

        compatibility_dict.setdefault(mon_name, [])
        level_for_moves.setdefault(mon_name, [])

        for move in entry[1].split("\n"):
            move = move.strip()
            if move == "" or move == "LEVEL_UP_END":
                continue

            level = int(move[move.index("(") + 1:move.index(",")].strip())
            move_name = move[move.index(",") + 2:move.index(")")].strip()
            if move_name == "" or move_name == "MOVE_UNAVAILABLE":
                continue
            if move_name in compatibility_dict[mon_name]:
                continue

            compatibility_dict[mon_name].append(move_name)
            level_for_moves[mon_name].append(level)
            custom_found = True

    if custom_found:
        print("FIRST RUN: Preserved level-up data from gen_9.h")

    return compatibility_dict, level_for_moves


# before all else, abort if the config is off
with open("./include/config/pokemon.h", "r") as file:
    learnset_config = re.findall(r"#define P_LEARNSET_HELPER_TEACHABLE *([^ ]*)", file.read())
    if len(learnset_config) != 1:
        quit()
    if learnset_config[0] != "TRUE":
        quit()


tm_moves = []
tutor_moves = []
level_for_moves = {}
trace_mons = set(
    x.strip().upper()
    for x in re.split(r"[,\s]+", os.environ.get("LEARNSET_TRACE_MON", ""))
    if x.strip()
)


def is_traced_mon(mon_name, mon_parsed):
    return mon_name.upper() in trace_mons or mon_parsed in trace_mons


# scan incs
incs_to_check = glob.glob("./data/scripts/*.inc")
incs_to_check += glob.glob("./data/maps/*/scripts.inc")

if len(incs_to_check) == 0:
    quit()

for file in incs_to_check:
    with open(file, "r", encoding="utf8") as f2:
        raw = f2.read()
    if "special ChooseMonForMoveTutor" in raw:
        for move in re.findall(r"setvar VAR_0x8005, (MOVE_.*)", raw):
            append_unique_move(tutor_moves, move)


# scan TMs and HMs
with open("./include/constants/tms_hms.h", "r") as file:
    for move in re.findall(r"F\((.*)\)", file.read()):
        append_unique_move(tm_moves, "MOVE_" + move)


# look up universal moves to exclude them
universal_moves = []
with open("./src/pokemon.c", "r") as file:
    match = re.search(r"static const u16 sUniversalMoves\[\]\s*=\s*{((.|\n)*?)};", file.read())
    if match:
        for move in match.group(1).replace("\n", "").split(","):
            move = move.strip()
            if move == "":
                continue
            append_unique_move(universal_moves, move)


source_catalog = build_source_catalog()


def construct_compatibility_dict(force_custom_check):
    dict_out = {}
    list_of_mons, raw = list_header_mons(TEACHABLE_HEADER, r"static const u16 s(.*)TeachableLearnset")

    for mon in list_of_mons:
        mon_parsed = parse_mon_name(mon)
        if mon_parsed in ("NONE", "MEW"):
            continue

        teachable_moves = resolve_teachable_moves(mon_parsed, source_catalog)
        if teachable_moves is not None:
            dict_out[mon_parsed] = teachable_moves

    if force_custom_check:
        dict_out = preserve_custom_teachable_moves(dict_out, raw)

    return dict_out


compatibility_dict = construct_compatibility_dict(True)


# actually prepare the file
with open(TEACHABLE_HEADER, "r") as file:
    out = file.read()
    list_of_mons = re.findall(r"static const u16 s(.*)TeachableLearnset", out)

for mon in list_of_mons:
    mon_parsed = parse_mon_name(mon)
    tm_learnset = []
    tutor_learnset = []
    if mon_parsed == "NONE" or mon_parsed == "MEW":
        continue
    if mon_parsed not in compatibility_dict:
        print("Unable to find %s in json" % mon)
        if is_traced_mon(mon, mon_parsed):
            print("[TRACE] %s: missing from teachable compatibility dict" % mon)
        continue

    for move in compatibility_dict[mon_parsed]:
        if move in tutor_moves:
            continue
        if move in tm_learnset:
            continue
        if move in universal_moves:
            continue
        tm_learnset.append(move)

    for move in tutor_moves:
        if move in universal_moves:
            continue
        if move in tutor_learnset:
            continue
        if move in compatibility_dict[mon_parsed]:
            tutor_learnset.append(move)
            continue

    tm_learnset.sort()
    tutor_learnset.sort()
    tm_learnset += tutor_learnset
    repl = "static const u16 s%sTeachableLearnset[] = {\n    " % mon
    if len(tm_learnset) > 0:
        repl += ",\n    ".join(tm_learnset) + ",\n    "
    repl += "MOVE_UNAVAILABLE,\n};"
    newout = re.sub(
        r"static const u16 s%sTeachableLearnset\[\] = {[\s\S]*?};" % re.escape(mon),
        repl,
        out,
    )
    if newout != out:
        out = newout
        print("Updated %s" % mon)
    elif is_traced_mon(mon, mon_parsed):
        print("[TRACE] %s: no teachable changes" % mon)


# add/update header
header = "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from tools/learnset_helpers/teachable.py\n//\n\n"
longest_move_name = 0
for move in tm_moves + tutor_moves:
    if len(move) > longest_move_name:
        longest_move_name = len(move)
longest_move_name += 2

universal_title = "Near-universal moves found in sUniversalMoves:"
tmhm_title = "TM/HM moves found in \"include/constants/tms_hms.h\":"
tutor_title = "Tutor moves found in map scripts:"

if longest_move_name < len(universal_title):
    longest_move_name = len(universal_title)
if longest_move_name < len(tmhm_title):
    longest_move_name = len(tmhm_title)
if longest_move_name < len(tutor_title):
    longest_move_name = len(tutor_title)


def header_print(string):
    global header
    header += "// " + string + " " * (longest_move_name - len(string)) + " //\n"


header += "// " + longest_move_name * "*" + " //\n"
header_print(tmhm_title)
for move in tm_moves:
    header_print("- " + move)
header += "// " + longest_move_name * "*" + " //\n"
header_print(tutor_title)
tutor_moves.sort()
for move in tutor_moves:
    header_print("- " + move)
header += "// " + longest_move_name * "*" + " //\n"
header_print(universal_title)
universal_moves.sort()
for move in universal_moves:
    header_print("- " + move)
header += "// " + longest_move_name * "*" + " //\n\n"

if HEADER_WARNING not in out:
    out = header + out
else:
    out = re.sub(r"\/\/\n\/\/ DO NOT MODIFY THIS FILE!(.|\n)*\* \/\/\n\n", header, out)

with open(TEACHABLE_HEADER, "w") as file:
    file.write(out)


def construct_compatibility_levelset(force_custom_check):
    dict_out = {}
    list_of_mons, raw = list_header_mons(
        LEVELUP_HEADER,
        r"static const struct LevelUpMove s(.*)LevelUpLearnset",
    )

    for mon in list_of_mons:
        mon_parsed = parse_mon_name(mon)
        if mon_parsed == "NONE":
            continue

        level_moves = resolve_level_moves(mon_parsed, source_catalog)
        if level_moves is None:
            continue

        dict_out[mon_parsed] = []
        level_for_moves[mon_parsed] = []
        for move in level_moves:
            dict_out[mon_parsed].append(move["Move"])
            level_for_moves[mon_parsed].append(move["Level"])

    if force_custom_check:
        dict_out, _ = preserve_custom_level_moves(dict_out, level_for_moves, raw)

    return dict_out


compatibility_dict = construct_compatibility_levelset(True)


# actually prepare the file
with open(LEVELUP_HEADER, "r") as file:
    out = file.read()
    list_of_mons = re.findall(r"static const struct LevelUpMove s(.*)LevelUpLearnset", out)

for mon in list_of_mons:
    mon_parsed = parse_mon_name(mon)
    levelup_moves = []
    levels = []
    index = 0
    if mon_parsed == "NONE":
        continue
    if mon_parsed not in compatibility_dict:
        print("Unable to find %s in json" % mon)
        if is_traced_mon(mon, mon_parsed):
            print("[TRACE] %s: missing from level-up compatibility dict" % mon)
        continue

    for move in compatibility_dict[mon_parsed]:
        levelup_moves.append(move)
        levels.append(level_for_moves[mon_parsed][index])
        index += 1

    repl = "static const struct LevelUpMove s%sLevelUpLearnset[] = {\n    " % mon
    index = 0
    while index < len(levelup_moves):
        if len(levelup_moves) > 0:
            repl += "    LEVEL_UP_MOVE(" + str(levels[index]) + ", " + levelup_moves[index] + "),\n    "
        index += 1
    repl += "    LEVEL_UP_END\n};"
    newout = re.sub(
        r"static const struct LevelUpMove s%sLevelUpLearnset\[\] = {[\s\S]*?};" % re.escape(mon),
        repl,
        out,
    )
    if newout != out:
        out = newout
        print("Updated %s" % mon)
    elif is_traced_mon(mon, mon_parsed):
        print("[TRACE] %s: no level-up changes" % mon)


# add/update header
header = "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from tools/learnset_helpers/teachable.py\n//\n\n"
if HEADER_WARNING not in out:
    out = header + out
else:
    out = re.sub(r"\/\/\n\/\/ DO NOT MODIFY THIS FILE!(.|\n)*\* \/\/\n\n", header, out)

with open(LEVELUP_HEADER, "w") as file:
    file.write(out)
