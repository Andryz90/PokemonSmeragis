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
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 120
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 2,
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
#line 127
                MOVE_MOONBLAST,
                MOVE_HYPER_VOICE,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 132
            .species = SPECIES_MIMIKYU,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 132
            .heldItem = ITEM_LIFE_ORB,
#line 136
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 133
            .ability = ABILITY_DISGUISE,
#line 134
            .lvl = 60,
#line 135
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 136
                MOVE_SWORDS_DANCE,
                MOVE_PLAY_ROUGH,
                MOVE_SHADOW_CLAW,
                MOVE_SHADOW_SNEAK,
            },
            },
        },
    },
#line 142
    [DIFFICULTY_NORMAL][PARTNER_SPLITFACE] =
    {
#line 143
        .trainerName = _("SPLITFACE"),
#line 144
        .trainerClass = TRAINER_CLASS_DEVELOPER,
#line 145
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 147
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 2,
        .party = (const struct TrainerMon[])
        {
            {
#line 149
            .species = SPECIES_ABOMASNOW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 153
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 150
            .ability = ABILITY_SNOW_WARNING,
#line 151
            .lvl = 60,
#line 152
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 153
                MOVE_BLIZZARD,
                MOVE_GIGA_DRAIN,
                MOVE_ICE_SHARD,
                MOVE_PROTECT,
            },
            },
            {
#line 158
            .species = SPECIES_GLALIE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 158
            .heldItem = ITEM_LEFTOVERS,
#line 162
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 159
            .ability = ABILITY_ICE_BODY,
#line 160
            .lvl = 60,
#line 161
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 162
                MOVE_BLIZZARD,
                MOVE_PROTECT,
                MOVE_TOXIC,
                MOVE_SUBSTITUTE,
            },
            },
        },
    },
#line 168
    [DIFFICULTY_NORMAL][PARTNER_WALLY_AREA_ZERO] =
    {
#line 169
        .trainerName = _("WALLY"),
#line 170
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 171
        .trainerPic = TRAINER_BACK_PIC_WALLY,
        .encounterMusic_gender =
#line 173
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 175
            .species = SPECIES_TINKATON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 175
            .heldItem = ITEM_AIR_BALLOON,
#line 176
            .ability = ABILITY_MOLD_BREAKER,
#line 177
            .lvl = 65,
#line 178
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 179
                MOVE_FAKE_OUT,
                MOVE_PROTECT,
                MOVE_PLAY_ROUGH,
                MOVE_GIGATON_HAMMER,
            },
            },
            {
#line 184
            .species = SPECIES_GALLADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 184
            .heldItem = ITEM_EXPERT_BELT,
#line 185
            .ability = ABILITY_SHARPNESS,
#line 186
            .lvl = 65,
#line 187
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 188
                MOVE_PSYCHO_CUT,
                MOVE_LEAF_BLADE,
                MOVE_SACRED_SWORD,
                MOVE_SWORDS_DANCE,
            },
            },
            {
#line 193
            .species = SPECIES_GARDEVOIR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 193
            .heldItem = ITEM_GARDEVOIRITE,
#line 194
            .ability = ABILITY_TRACE,
#line 195
            .lvl = 65,
#line 196
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 197
                MOVE_HYPER_VOICE,
                MOVE_PROTECT,
                MOVE_PSYSHOCK,
                MOVE_THUNDERBOLT,
            },
            },
        },
    },
#line 203
    [DIFFICULTY_NORMAL][PARTNER_MAY_AREA_ZERO_TREECKO] =
    {
#line 204
        .trainerName = _("MAY"),
#line 205
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 206
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 207
F_TRAINER_FEMALE |
#line 208
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 210
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 210
            .heldItem = ITEM_LEEK,
#line 211
            .ability = ABILITY_SCRAPPY,
#line 212
            .lvl = 65,
#line 213
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 214
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 219
            .species = SPECIES_RAPIDASH_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 219
            .heldItem = ITEM_EXPERT_BELT,
#line 220
            .ability = ABILITY_ADAPTABILITY,
#line 221
            .lvl = 65,
#line 222
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 223
                MOVE_PSYCHIC,
                MOVE_MOONBLAST,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 228
            .species = SPECIES_BLAZIKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 228
            .heldItem = ITEM_BLAZIKENITE,
#line 229
            .ability = ABILITY_SPEED_BOOST,
#line 230
            .lvl = 65,
#line 231
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 232
                MOVE_SWORDS_DANCE,
                MOVE_PROTECT,
                MOVE_FLARE_BLITZ,
                MOVE_HIGH_JUMP_KICK,
            },
            },
        },
    },
#line 238
    [DIFFICULTY_NORMAL][PARTNER_MAY_AREA_ZERO_TORCHIC] =
    {
#line 239
        .trainerName = _("MAY"),
#line 240
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 241
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 242
F_TRAINER_FEMALE |
#line 243
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 245
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 245
            .heldItem = ITEM_LEEK,
#line 246
            .ability = ABILITY_SCRAPPY,
#line 247
            .lvl = 65,
#line 248
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 249
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 254
            .species = SPECIES_RAPIDASH_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 254
            .heldItem = ITEM_EXPERT_BELT,
#line 255
            .ability = ABILITY_ADAPTABILITY,
#line 256
            .lvl = 65,
#line 257
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 258
                MOVE_PSYCHIC,
                MOVE_MOONBLAST,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 263
            .species = SPECIES_SWAMPERT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 263
            .heldItem = ITEM_SWAMPERTITE,
#line 264
            .ability = ABILITY_DAMP,
#line 265
            .lvl = 65,
#line 266
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 267
                MOVE_WATERFALL,
                MOVE_HIGH_HORSEPOWER,
                MOVE_ICE_PUNCH,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 273
    [DIFFICULTY_NORMAL][PARTNER_MAY_AREA_ZERO_MUDKIP] =
    {
#line 274
        .trainerName = _("MAY"),
#line 275
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 276
        .trainerPic = TRAINER_BACK_PIC_MAY,
        .encounterMusic_gender =
#line 277
F_TRAINER_FEMALE |
#line 278
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 280
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 280
            .heldItem = ITEM_LEEK,
#line 281
            .ability = ABILITY_SCRAPPY,
#line 282
            .lvl = 65,
#line 283
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 284
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 289
            .species = SPECIES_RAPIDASH_GALAR,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 289
            .heldItem = ITEM_EXPERT_BELT,
#line 290
            .ability = ABILITY_ADAPTABILITY,
#line 291
            .lvl = 65,
#line 292
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 293
                MOVE_PSYCHIC,
                MOVE_MOONBLAST,
                MOVE_MYSTICAL_FIRE,
                MOVE_PROTECT,
            },
            },
            {
#line 298
            .species = SPECIES_SCEPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 298
            .heldItem = ITEM_SCEPTILITE,
#line 299
            .ability = ABILITY_OVERGROW,
#line 300
            .lvl = 65,
#line 301
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 302
                MOVE_LEAF_STORM,
                MOVE_DRAGON_PULSE,
                MOVE_FOCUS_BLAST,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 308
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_AREA_ZERO_TREECKO] =
    {
#line 309
        .trainerName = _("BRENDAN"),
#line 310
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 311
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 313
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 315
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 315
            .heldItem = ITEM_LEEK,
#line 316
            .ability = ABILITY_SCRAPPY,
#line 317
            .lvl = 65,
#line 318
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 319
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 324
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 324
            .heldItem = ITEM_EXPERT_BELT,
#line 325
            .ability = ABILITY_STRONG_JAW,
#line 326
            .lvl = 65,
#line 327
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 328
                MOVE_THUNDER_FANG,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_FANG,
                MOVE_PIXIE_FANGS,
            },
            },
            {
#line 333
            .species = SPECIES_BLAZIKEN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 333
            .heldItem = ITEM_BLAZIKENITE,
#line 334
            .ability = ABILITY_SPEED_BOOST,
#line 335
            .lvl = 65,
#line 336
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 337
                MOVE_SWORDS_DANCE,
                MOVE_PROTECT,
                MOVE_FLARE_BLITZ,
                MOVE_HIGH_JUMP_KICK,
            },
            },
        },
    },
#line 343
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_AREA_ZERO_TORCHIC] =
    {
#line 344
        .trainerName = _("BRENDAN"),
#line 345
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 346
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 348
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 350
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 350
            .heldItem = ITEM_LEEK,
#line 351
            .ability = ABILITY_SCRAPPY,
#line 352
            .lvl = 65,
#line 353
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 354
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 359
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 359
            .heldItem = ITEM_EXPERT_BELT,
#line 360
            .ability = ABILITY_STRONG_JAW,
#line 361
            .lvl = 65,
#line 362
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 363
                MOVE_THUNDER_FANG,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_FANG,
                MOVE_PIXIE_FANGS,
            },
            },
            {
#line 368
            .species = SPECIES_SWAMPERT,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 368
            .heldItem = ITEM_SWAMPERTITE,
#line 369
            .ability = ABILITY_DAMP,
#line 370
            .lvl = 65,
#line 371
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 372
                MOVE_WATERFALL,
                MOVE_HIGH_HORSEPOWER,
                MOVE_ICE_PUNCH,
                MOVE_PROTECT,
            },
            },
        },
    },
#line 378
    [DIFFICULTY_NORMAL][PARTNER_BRENDAN_AREA_ZERO_MUDKIP] =
    {
#line 379
        .trainerName = _("BRENDAN"),
#line 380
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 381
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 383
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 385
            .species = SPECIES_SIRFETCHD,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 385
            .heldItem = ITEM_LEEK,
#line 386
            .ability = ABILITY_SCRAPPY,
#line 387
            .lvl = 65,
#line 388
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 389
                MOVE_METEOR_ASSAULT,
                MOVE_ROYAL_GUARD,
                MOVE_FIRST_IMPRESSION,
                MOVE_SOLAR_BLADE,
            },
            },
            {
#line 394
            .species = SPECIES_GRANBULL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 394
            .heldItem = ITEM_EXPERT_BELT,
#line 395
            .ability = ABILITY_STRONG_JAW,
#line 396
            .lvl = 65,
#line 397
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 398
                MOVE_THUNDER_FANG,
                MOVE_DRAIN_PUNCH,
                MOVE_ICE_FANG,
                MOVE_PIXIE_FANGS,
            },
            },
            {
#line 403
            .species = SPECIES_SCEPTILE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 403
            .heldItem = ITEM_SCEPTILITE,
#line 404
            .ability = ABILITY_OVERGROW,
#line 405
            .lvl = 65,
#line 406
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 407
                MOVE_LEAF_STORM,
                MOVE_DRAGON_PULSE,
                MOVE_FOCUS_BLAST,
                MOVE_PROTECT,
            },
            },
        },
    },
