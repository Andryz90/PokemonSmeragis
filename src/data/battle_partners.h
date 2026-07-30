//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [DIFFICULTY_NORMAL][PARTNER_WALLY] =
    {
#line 9
        .trainerName = _("WALLY"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_WALLY,
        .encounterMusic_gender =
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_KIRLIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 15
            .heldItem = ITEM_SITRUS_BERRY,
#line 19
            .iv = TRAINER_PARTY_IVS(31, 0, 31, 31, 31, 31),
#line 16
            .ability = ABILITY_TRACE,
#line 17
            .lvl = 22,
#line 18
            .nature = NATURE_BOLD,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_PSYBEAM,
                MOVE_LIFE_DEW,
                MOVE_DRAINING_KISS,
            },
            },
            {
#line 24
            .species = SPECIES_AZUMARILL,
#line 24
            .gender = TRAINER_MON_MALE,
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 25
            .ability = ABILITY_HUGE_POWER,
#line 26
            .lvl = 21,
#line 27
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 28
                MOVE_HELPING_HAND,
                MOVE_AQUA_TAIL,
                MOVE_BOUNCE,
                MOVE_CHARM,
            },
            },
            {
#line 33
            .species = SPECIES_DEDENNE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 33
            .heldItem = ITEM_ORAN_BERRY,
#line 36
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 34
            .ability = ABILITY_CHEEK_POUCH,
#line 35
            .lvl = 21,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 36
                MOVE_NUZZLE,
                MOVE_DRAINING_KISS,
                MOVE_THUNDER_SHOCK,
            },
            },
        },
    },
#line 41
    [DIFFICULTY_NORMAL][PARTNER_WALLY_DESERT] =
    {
#line 42
        .trainerName = _("WALLY"),
#line 43
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 44
        .trainerPic = TRAINER_BACK_PIC_WALLY,
        .encounterMusic_gender =
#line 46
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 48
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 48
            .heldItem = ITEM_LIFE_ORB,
#line 52
            .iv = TRAINER_PARTY_IVS(31, 0, 31, 31, 31, 31),
#line 49
            .ability = ABILITY_TRACE,
#line 50
            .lvl = 45,
#line 51
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 53
                MOVE_MOONBLAST,
                MOVE_PSYCHIC_NOISE,
                MOVE_ENERGY_BALL,
                MOVE_CALM_MIND,
            },
            },
            {
#line 58
            .species = SPECIES_GALLADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 58
            .heldItem = ITEM_EXPERT_BELT,
#line 62
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 59
            .ability = ABILITY_SHARPNESS,
#line 60
            .lvl = 45,
#line 61
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 62
                MOVE_PSYCHO_CUT,
                MOVE_NIGHT_SLASH,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_PUNCH,
            },
            },
            {
#line 67
            .species = SPECIES_TINKATON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 67
            .heldItem = ITEM_AIR_BALLOON,
#line 71
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 68
            .ability = ABILITY_MOLD_BREAKER,
#line 69
            .lvl = 45,
#line 70
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 71
                MOVE_PROTECT,
                MOVE_FAKE_OUT,
                MOVE_GIGATON_HAMMER,
                MOVE_PLAY_ROUGH,
            },
            },
        },
    },
#line 77
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 78
        .trainerName = _("STEVEN"),
#line 79
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 80
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 82
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 84
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 88
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 87
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 86
            .lvl = 42,
#line 85
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 89
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 94
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 98
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 97
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 96
            .lvl = 43,
#line 95
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 99
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 104
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 108
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 107
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 106
            .lvl = 44,
#line 105
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 109
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 115
    [DIFFICULTY_NORMAL][PARTNER_ANDRY] =
    {
#line 116
        .trainerName = _("ANDRY"),
#line 117
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 118
        .trainerPic = TRAINER_BACK_PIC_ANDRY,
        .encounterMusic_gender =
#line 120
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 122
            .species = SPECIES_SYLVEON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 122
            .heldItem = ITEM_THROAT_SPRAY,
#line 126
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 123
            .ability = ABILITY_PIXILATE,
#line 124
            .lvl = 60,
#line 125
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 126
                MOVE_MOONBLAST,
                MOVE_HYPER_VOICE,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 131
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 131
            .heldItem = ITEM_LIFE_ORB,
#line 135
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 132
            .ability = ABILITY_DISGUISE,
#line 133
            .lvl = 60,
#line 134
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 135
                MOVE_SWORDS_DANCE,
                MOVE_PLAY_ROUGH,
                MOVE_SHADOW_CLAW,
                MOVE_SHADOW_SNEAK,
            },
            },
            {
#line 140
            .species = SPECIES_TOGEKISS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 140
            .heldItem = ITEM_LEFTOVERS,
#line 144
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 141
            .ability = ABILITY_DISGUISE,
#line 142
            .lvl = 60,
#line 143
            .nature = NATURE_BOLD,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 144
                MOVE_AIR_SLASH,
                MOVE_ROOST,
                MOVE_DAZZLING_GLEAM,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 149
    [DIFFICULTY_NORMAL][PARTNER_SPLITFACE] =
    {
#line 150
        .trainerName = _("SPLITFACE"),
#line 151
        .trainerClass = TRAINER_CLASS_DEVELOPER,
#line 152
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 154
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 156
            .species = SPECIES_ABOMASNOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 160
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 157
            .ability = ABILITY_SNOW_WARNING,
#line 158
            .lvl = 60,
#line 159
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 160
                MOVE_BLIZZARD,
                MOVE_GIGA_DRAIN,
                MOVE_ICE_SHARD,
                MOVE_PROTECT,
            },
            },
            {
#line 165
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 165
            .heldItem = ITEM_LEFTOVERS,
#line 169
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 166
            .ability = ABILITY_ICE_BODY,
#line 167
            .lvl = 60,
#line 168
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 169
                MOVE_BLIZZARD,
                MOVE_PROTECT,
                MOVE_TOXIC,
                MOVE_SUBSTITUTE,
            },
            },
            {
#line 174
            .species = SPECIES_DELIBIRD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 174
            .heldItem = ITEM_LIFE_ORB,
#line 178
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 175
            .ability = ABILITY_HUSTLE,
#line 176
            .lvl = 60,
#line 177
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 178
                MOVE_AERIAL_ACE,
                MOVE_ICE_SPINNER,
                MOVE_PROTECT,
                MOVE_PRESENT,
            },
            },
        },
    },
#line 184
    [DIFFICULTY_NORMAL][PARTNER_WALLY_AREA_ZERO] =
    {
#line 185
        .trainerName = _("WALLY"),
#line 186
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 187
        .trainerPic = TRAINER_BACK_PIC_WALLY,
        .encounterMusic_gender =
#line 189
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 191
            .species = SPECIES_TINKATON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 191
            .heldItem = ITEM_AIR_BALLOON,
#line 195
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 192
            .ability = ABILITY_MOLD_BREAKER,
#line 193
            .lvl = 65,
#line 194
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 195
                MOVE_FAKE_OUT,
                MOVE_PROTECT,
                MOVE_PLAY_ROUGH,
                MOVE_GIGATON_HAMMER,
            },
            },
            {
#line 200
            .species = SPECIES_GALLADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 200
            .heldItem = ITEM_EXPERT_BELT,
#line 204
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 201
            .ability = ABILITY_SHARPNESS,
#line 202
            .lvl = 65,
#line 203
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 204
                MOVE_PSYCHO_CUT,
                MOVE_LEAF_BLADE,
                MOVE_SACRED_SWORD,
                MOVE_SWORDS_DANCE,
            },
            },
            {
#line 209
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 209
            .heldItem = ITEM_GARDEVOIRITE,
#line 213
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 210
            .ability = ABILITY_TRACE,
#line 211
            .lvl = 65,
#line 212
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 213
                MOVE_HYPER_VOICE,
                MOVE_PROTECT,
                MOVE_PSYSHOCK,
                MOVE_THUNDERBOLT,
            },
            },
        },
    },
#line 219
    [DIFFICULTY_NORMAL][PARTNER_MAY_AREA_ZERO_TREECKO] =
    {
#line 220
        .trainerName = _("MAY"),
#line 221
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 222
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 223
F_TRAINER_FEMALE | 
#line 224
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 227
            .species = SPECIES_RAPIDASH_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 227
            .heldItem = ITEM_FOCUS_SASH,
#line 231
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 228
            .ability = ABILITY_ADAPTABILITY,
#line 229
            .lvl = 65,
#line 230
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 231
                MOVE_PSYCHIC,
                MOVE_MOONBLAST,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 236
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 236
            .heldItem = ITEM_LEEK,
#line 240
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 237
            .ability = ABILITY_SCRAPPY,
#line 238
            .lvl = 65,
#line 239
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 240
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 245
            .species = SPECIES_BLAZIKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 245
            .heldItem = ITEM_BLAZIKENITE,
#line 249
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 246
            .ability = ABILITY_SPEED_BOOST,
#line 247
            .lvl = 65,
#line 248
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 249
                MOVE_SWORDS_DANCE,
                MOVE_PROTECT,
                MOVE_FLARE_BLITZ,
                MOVE_HIGH_JUMP_KICK,
            },
            },
        },
    },
#line 255
    [DIFFICULTY_NORMAL][PARTNER_MAY_AREA_ZERO_TORCHIC] =
    {
#line 256
        .trainerName = _("MAY"),
#line 257
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 258
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 259
F_TRAINER_FEMALE | 
#line 260
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 262
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 262
            .heldItem = ITEM_LEEK,
#line 266
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 263
            .ability = ABILITY_SCRAPPY,
#line 264
            .lvl = 65,
#line 265
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 266
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 271
            .species = SPECIES_RAPIDASH_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 271
            .heldItem = ITEM_FOCUS_SASH,
#line 275
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 272
            .ability = ABILITY_ADAPTABILITY,
#line 273
            .lvl = 65,
#line 274
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 275
                MOVE_PSYCHIC,
                MOVE_MOONBLAST,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 280
            .species = SPECIES_SWAMPERT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 280
            .heldItem = ITEM_SWAMPERTITE,
#line 284
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 281
            .ability = ABILITY_DAMP,
#line 282
            .lvl = 65,
#line 283
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 284
                MOVE_WATERFALL,
                MOVE_HIGH_HORSEPOWER,
                MOVE_ICE_PUNCH,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 290
    [DIFFICULTY_NORMAL][PARTNER_MAY_AREA_ZERO_MUDKIP] =
    {
#line 291
        .trainerName = _("MAY"),
#line 292
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 293
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 294
F_TRAINER_FEMALE | 
#line 295
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 297
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 297
            .heldItem = ITEM_LEEK,
#line 301
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 298
            .ability = ABILITY_SCRAPPY,
#line 299
            .lvl = 65,
#line 300
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 301
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 306
            .species = SPECIES_RAPIDASH_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 306
            .heldItem = ITEM_FOCUS_SASH,
#line 310
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 307
            .ability = ABILITY_ADAPTABILITY,
#line 308
            .lvl = 65,
#line 309
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 310
                MOVE_PSYCHIC,
                MOVE_MOONBLAST,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 315
            .species = SPECIES_SCEPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 315
            .heldItem = ITEM_SCEPTILITE,
#line 319
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 316
            .ability = ABILITY_OVERGROW,
#line 317
            .lvl = 65,
#line 318
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 319
                MOVE_BULLET_SEED,
                MOVE_DUAL_CHOP,
                MOVE_ROCK_TOMB,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 325
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_AREA_ZERO_TREECKO] =
    {
#line 326
        .trainerName = _("BRENDAN"),
#line 327
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 328
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 330
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 332
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 332
            .heldItem = ITEM_LEEK,
#line 336
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 333
            .ability = ABILITY_SCRAPPY,
#line 334
            .lvl = 65,
#line 335
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 336
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 341
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 341
            .heldItem = ITEM_EXPERT_BELT,
#line 345
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 342
            .ability = ABILITY_STRONG_JAW,
#line 343
            .lvl = 65,
#line 344
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 345
                MOVE_THUNDER_FANG,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_FANG,
                MOVE_PIXIE_FANGS,
            },
            },
            {
#line 350
            .species = SPECIES_BLAZIKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 350
            .heldItem = ITEM_BLAZIKENITE,
#line 354
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 351
            .ability = ABILITY_SPEED_BOOST,
#line 352
            .lvl = 65,
#line 353
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 354
                MOVE_SWORDS_DANCE,
                MOVE_PROTECT,
                MOVE_FLARE_BLITZ,
                MOVE_HIGH_JUMP_KICK,
            },
            },
        },
    },
#line 360
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_AREA_ZERO_TORCHIC] =
    {
#line 361
        .trainerName = _("BRENDAN"),
#line 362
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 363
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 365
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 367
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 367
            .heldItem = ITEM_LEEK,
#line 371
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 368
            .ability = ABILITY_SCRAPPY,
#line 369
            .lvl = 65,
#line 370
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 371
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 376
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 376
            .heldItem = ITEM_EXPERT_BELT,
#line 380
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 377
            .ability = ABILITY_STRONG_JAW,
#line 378
            .lvl = 65,
#line 379
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 380
                MOVE_THUNDER_FANG,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_FANG,
                MOVE_PIXIE_FANGS,
            },
            },
            {
#line 385
            .species = SPECIES_SWAMPERT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 385
            .heldItem = ITEM_SWAMPERTITE,
#line 389
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 386
            .ability = ABILITY_DAMP,
#line 387
            .lvl = 65,
#line 388
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 389
                MOVE_WATERFALL,
                MOVE_HIGH_HORSEPOWER,
                MOVE_ICE_PUNCH,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 395
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_AREA_ZERO_MUDKIP] =
    {
#line 396
        .trainerName = _("BRENDAN"),
#line 397
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 398
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 400
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 402
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 402
            .heldItem = ITEM_LEEK,
#line 406
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 403
            .ability = ABILITY_SCRAPPY,
#line 404
            .lvl = 65,
#line 405
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 406
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_DUAL_WINGBEAT,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 411
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 411
            .heldItem = ITEM_EXPERT_BELT,
#line 415
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 412
            .ability = ABILITY_STRONG_JAW,
#line 413
            .lvl = 65,
#line 414
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 415
                MOVE_THUNDER_FANG,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_FANG,
                MOVE_PIXIE_FANGS,
            },
            },
            {
#line 420
            .species = SPECIES_SCEPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 420
            .heldItem = ITEM_SCEPTILITE,
#line 424
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 421
            .ability = ABILITY_OVERGROW,
#line 422
            .lvl = 65,
#line 423
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 424
                MOVE_BULLET_SEED,
                MOVE_DUAL_CHOP,
                MOVE_ROCK_TOMB,
                MOVE_PROTECT,
            },
            },
        },
    },
