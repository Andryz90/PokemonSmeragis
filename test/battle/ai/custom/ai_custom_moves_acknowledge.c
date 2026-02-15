#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

#define AI_FLAGS_TRAINER_PROFILE (AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES)

AI_SINGLE_BATTLE_TEST("AI custom move acknowledge: damaging custom moves are preferred over do-nothing options")
{
    u16 customMove = MOVE_NONE;
    PARAMETRIZE { customMove = MOVE_COMBO_PUNCH; }
    PARAMETRIZE { customMove = MOVE_POISON_DRAIN; }
    PARAMETRIZE { customMove = MOVE_DETERIO; }
    PARAMETRIZE { customMove = MOVE_SNOW_SLIDE; }
    PARAMETRIZE { customMove = MOVE_POISON_DRILL; }
    PARAMETRIZE { customMove = MOVE_TECTONIC_POWER; }
    PARAMETRIZE { customMove = MOVE_PIXIE_DRAIN; }
    PARAMETRIZE { customMove = MOVE_WATER_FANGS; }
    PARAMETRIZE { customMove = MOVE_SISMA; }
    PARAMETRIZE { customMove = MOVE_PURIFYING_WATER; }
    PARAMETRIZE { customMove = MOVE_WINDSOM_OF_CHANGE; }
    PARAMETRIZE { customMove = MOVE_SEASON_POWER; }
    PARAMETRIZE { customMove = MOVE_PIXIE_FANGS; }
    PARAMETRIZE { customMove = MOVE_IRON_GRIP; }

    GIVEN {
        ASSUME(GetMovePower(customMove) > 0);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(customMove, MOVE_CELEBRATE, MOVE_SPLASH, MOVE_GROWL); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, customMove, MOVE_CELEBRATE);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, customMove);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move acknowledge: Royal Guard is treated like Protect for setup turns")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(GetMoveEffect(MOVE_ROYAL_GUARD) == EFFECT_PROTECT);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_ELECTRODE) { Speed(200); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_SWELLOW) { Ability(ABILITY_GUTS); Item(ITEM_FLAME_ORB); Speed(100); HP(80); MaxHP(160); Moves(MOVE_ROYAL_GUARD, MOVE_FACADE); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); EXPECT_MOVE(opponent, MOVE_ROYAL_GUARD); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move acknowledge: Hoarfrost is preferred over Celebrate on a healthy target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HOARFROST) == EFFECT_HOARFROST);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_EEVEE) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLALIE) { Moves(MOVE_HOARFROST, MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_HOARFROST, MOVE_CELEBRATE);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, MOVE_HOARFROST);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move acknowledge: Deterio is preferred against Steel targets")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DETERIO) == EFFECT_SUPER_EFFECTIVE_ON_ARG);
        ASSUME(GetMoveArgType(MOVE_DETERIO) == TYPE_STEEL);
        ASSUME(gSpeciesInfo[SPECIES_AGGRON].types[0] == TYPE_STEEL || gSpeciesInfo[SPECIES_AGGRON].types[1] == TYPE_STEEL);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_AGGRON) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_DETERIO, MOVE_POISON_DRAIN, MOVE_CELEBRATE, MOVE_GROWL); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_DETERIO, MOVE_POISON_DRAIN);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, MOVE_DETERIO);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move acknowledge: Season Power scoring uses dynamic type logic")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SEASON_POWER) == EFFECT_CHANGE_TYPE);
        ASSUME(gSpeciesInfo[SPECIES_VAPOREON].types[0] == TYPE_WATER);
        ASSUME(gSpeciesInfo[SPECIES_GENGAR].types[0] == TYPE_GHOST || gSpeciesInfo[SPECIES_GENGAR].types[1] == TYPE_GHOST);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_GENGAR) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_VAPOREON) { Moves(MOVE_SEASON_POWER, MOVE_TACKLE, MOVE_CELEBRATE, MOVE_GROWL); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_SEASON_POWER, MOVE_TACKLE);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, MOVE_SEASON_POWER);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move acknowledge: AI avoids hazard setup if opponent can remove hazards with Windsom of Change")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
        ASSUME(GetMoveEffect(MOVE_WINDSOM_OF_CHANGE) == EFFECT_WINDSOM_OF_CHANGE);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_BLASTOISE) { Moves(MOVE_WINDSOM_OF_CHANGE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_FERROTHORN) { Moves(MOVE_SPIKES, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move bug check: Hoarfrost should be avoided if target already has a major status")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HOARFROST) == EFFECT_HOARFROST);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_EEVEE) { Status1(STATUS1_BURN); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLALIE) { Moves(MOVE_HOARFROST, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_CELEBRATE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom move bug check: Purifying Water should be avoided into Water targets")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PURIFYING_WATER) == EFFECT_PURIFYING_WATER);
        ASSUME(gSpeciesInfo[SPECIES_VAPOREON].types[0] == TYPE_WATER || gSpeciesInfo[SPECIES_VAPOREON].types[1] == TYPE_WATER);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_VAPOREON) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BLASTOISE) { Moves(MOVE_PURIFYING_WATER, MOVE_WATER_GUN, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_WATER_GUN); }
    }
}
