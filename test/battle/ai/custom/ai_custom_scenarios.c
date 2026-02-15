#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

#define AI_FLAGS_TRAINER_PROFILE (AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES)
#define AI_FLAGS_BOSS_PROFILE (AI_FLAGS_TRAINER_PROFILE | AI_FLAG_OMNISCIENT)

AI_SINGLE_BATTLE_TEST("AI custom scenarios: chooses priority KO over non-priority KO when slower")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(200); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: can choose either KO move when it is already faster")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(200); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVES(opponent, MOVE_QUICK_ATTACK, MOVE_STRENGTH); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: switches to an immunity when facing a lethal move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_GARCHOMP) { Speed(200); Moves(MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_MANECTRIC) { Speed(100); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_BRONZONG) { Speed(50); Ability(ABILITY_LEVITATE); Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); EXPECT_SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); EXPECT_MOVE(opponent, MOVE_PSYCHIC); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: with no better switch, it still prefers the kill move even if it gets outsped")
{
    GIVEN {
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(200); Moves(MOVE_STRENGTH); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(1); Moves(MOVE_STRENGTH, MOVE_GROWL); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_STRENGTH, MOVE_GROWL);
            MOVE(player, MOVE_STRENGTH);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: with a faster revenge option in party, it switches out of a lethal ground move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_GARCHOMP) { HP(1); Speed(200); Moves(MOVE_EARTHQUAKE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(200); }
        OPPONENT(SPECIES_MANECTRIC) { Speed(100); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_BRONZONG) { Speed(300); Ability(ABILITY_LEVITATE); Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); EXPECT_SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); EXPECT_MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Garchomp fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Maxie-like Hippowdon lead does not auto-switch immediately into Water Fangs")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_FANGS) == TYPE_WATER);
        AI_FLAGS(AI_FLAGS_BOSS_PROFILE);
        PLAYER(SPECIES_FERALIGATR) { Level(50); Speed(120); Moves(MOVE_WATER_FANGS); }
        OPPONENT(SPECIES_HIPPOWDON) { Level(48); Ability(ABILITY_SAND_STREAM); Speed(60); Moves(MOVE_STEALTH_ROCK, MOVE_ROAR, MOVE_STONE_EDGE, MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_MARACTUS) { Level(48); Ability(ABILITY_SAND_FORCE); Speed(70); Moves(MOVE_SHORE_UP, MOVE_EARTH_POWER, MOVE_GIGA_DRAIN, MOVE_WEATHER_BALL); }
        OPPONENT(SPECIES_CAMERUPT) { Level(49); Ability(ABILITY_MAGMA_ARMOR); Speed(40); Moves(MOVE_EARTH_POWER, MOVE_HEAT_WAVE, MOVE_ERUPTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_FANGS); EXPECT_MOVES(opponent, MOVE_STEALTH_ROCK, MOVE_ROAR, MOVE_STONE_EDGE, MOVE_EARTHQUAKE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Maxie-like Maractus answer does not hard-switch immediately into Water Fangs")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_FANGS) == TYPE_WATER);
        AI_FLAGS(AI_FLAGS_BOSS_PROFILE);
        PLAYER(SPECIES_FERALIGATR) { Level(50); Speed(120); Moves(MOVE_WATER_FANGS); }
        OPPONENT(SPECIES_MARACTUS) { Level(48); Ability(ABILITY_SAND_FORCE); Speed(70); Moves(MOVE_SHORE_UP, MOVE_EARTH_POWER, MOVE_GIGA_DRAIN, MOVE_WEATHER_BALL); }
        OPPONENT(SPECIES_HIPPOWDON) { Level(48); Ability(ABILITY_SAND_STREAM); Speed(60); Moves(MOVE_STEALTH_ROCK, MOVE_ROAR, MOVE_STONE_EDGE, MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_CAMERUPT) { Level(49); Ability(ABILITY_MAGMA_ARMOR); Speed(40); Moves(MOVE_EARTH_POWER, MOVE_HEAT_WAVE, MOVE_ERUPTION); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_FANGS); EXPECT_MOVES(opponent, MOVE_SHORE_UP, MOVE_EARTH_POWER, MOVE_GIGA_DRAIN, MOVE_WEATHER_BALL); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Taunt is preferred when the target is status-oriented")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(120); Moves(MOVE_CELEBRATE, MOVE_GROWL, MOVE_PROTECT, MOVE_TAIL_WHIP); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_TAUNT, MOVE_CELEBRATE, MOVE_SPLASH, MOVE_GROWL); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_TAUNT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Taunt is ignored if AI can take an immediate KO")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(50); Moves(MOVE_CELEBRATE, MOVE_GROWL, MOVE_PROTECT, MOVE_TAIL_WHIP); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_TAUNT, MOVE_STRENGTH, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_STRENGTH); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Taunt is deprioritized when the target is fully offensive")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_STRENGTH, MOVE_QUICK_ATTACK, MOVE_POUND, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_TAUNT, MOVE_STRENGTH, MOVE_SPLASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH); EXPECT_MOVE(opponent, MOVE_STRENGTH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: in speed ties, AI evaluates priority as if it were faster")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_QUICK_ATTACK, MOVE_STRENGTH); }
    } WHEN {
        TURN { EXPECT_MOVES(opponent, MOVE_QUICK_ATTACK, MOVE_STRENGTH); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Shed Tail is preferred in a safe pivot situation")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SHED_TAIL) == EFFECT_SHED_TAIL);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SHED_TAIL, MOVE_STRENGTH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_STRENGTH); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SHED_TAIL); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Shed Tail is avoided at or below 50 percent HP")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SHED_TAIL) == EFFECT_SHED_TAIL);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(200); Moves(MOVE_SHED_TAIL, MOVE_STRENGTH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_STRENGTH); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_STRENGTH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Shed Tail is avoided if there is no usable switch target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SHED_TAIL) == EFFECT_SHED_TAIL);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SHED_TAIL, MOVE_STRENGTH); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_STRENGTH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: against unknown Lanturn abilities, AI is not fully cautious and may pick electric first")
{
    PASSES_RANDOMLY(2, 3, RNG_AI_ABILITY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_LANTURN) { Moves(MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_SURF); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); }
        TURN { EXPECT_MOVE(opponent, MOVE_SURF); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: once Volt Absorb is revealed, AI remembers it even after switch out and back in")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); Speed(80); MaxHP(500); HP(500); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_SWAMPERT) { Speed(200); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PORYGON2) { Speed(120); Ability(ABILITY_TRACE); Moves(MOVE_THUNDERBOLT, MOVE_SURF); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SURF); }
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_SURF); }
        TURN { SWITCH(player, 0); EXPECT_MOVE(opponent, MOVE_SURF); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SURF); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: without Omniscient, AI can be baited by opponent Illusion typing")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); Speed(200); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GARCHOMP) { Speed(50); }
        OPPONENT(SPECIES_PORYGON2) { Speed(100); Moves(MOVE_THUNDERBOLT, MOVE_GROWL); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_GROWL); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: even with Omniscient, AI still falls for opponent Illusion at first")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); Speed(200); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GARCHOMP) { Speed(50); }
        OPPONENT(SPECIES_PORYGON2) { Speed(100); Moves(MOVE_THUNDERBOLT, MOVE_GROWL); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_GROWL); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: after seeing an impossible move, AI stops falling for Illusion")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); Speed(200); Moves(MOVE_NIGHT_DAZE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_GARCHOMP) { Speed(50); }
        OPPONENT(SPECIES_PORYGON2) { Speed(100); HP(400); MaxHP(400); Moves(MOVE_THUNDERBOLT, MOVE_GROWL); }
    } WHEN {
        TURN { MOVE(player, MOVE_NIGHT_DAZE); EXPECT_MOVE(opponent, MOVE_GROWL); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: AI with Illusion still chooses moves using its true typing")
{
    GIVEN {
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_EEVEE) { Speed(100); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZOROARK) { Ability(ABILITY_ILLUSION); Speed(200); Moves(MOVE_NIGHT_DAZE, MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_GARCHOMP) { Speed(50); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_NIGHT_DAZE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Guts user with Flame Orb can choose Protect to activate status before attacking")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_ELECTRODE) { Speed(200); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_SWELLOW) { Ability(ABILITY_GUTS); Item(ITEM_FLAME_ORB); Speed(100); HP(80); MaxHP(160); Moves(MOVE_PROTECT, MOVE_FACADE); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); EXPECT_MOVE(opponent, MOVE_PROTECT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Toxic Boost user with Toxic Orb can choose Protect to activate status before attacking")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_ELECTRODE) { Speed(200); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_ZANGOOSE) { Ability(ABILITY_TOXIC_BOOST); Item(ITEM_TOXIC_ORB); Speed(100); HP(80); MaxHP(160); Moves(MOVE_PROTECT, MOVE_FACADE); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); EXPECT_MOVE(opponent, MOVE_PROTECT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: with Mega available, move scoring is still based on base-form profile")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BODY_SLAM) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        ASSUME(gSpeciesInfo[SPECIES_ALTARIA_MEGA].abilities[0] == ABILITY_PIXILATE
            || gSpeciesInfo[SPECIES_ALTARIA_MEGA].abilities[1] == ABILITY_PIXILATE
            || gSpeciesInfo[SPECIES_ALTARIA_MEGA].abilities[2] == ABILITY_PIXILATE);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_GARCHOMP) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ALTARIA) { Item(ITEM_ALTARIANITE); Moves(MOVE_BODY_SLAM, MOVE_DRAGON_CLAW, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_DRAGON_CLAW, MOVE_BODY_SLAM);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, MOVE_DRAGON_CLAW);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: when pivoting is mandatory (Zero to Hero), AI uses hit-escape moves (U-turn, Volt Switch, Flip Turn)")
{
    u16 pivotMove = MOVE_NONE;
    PARAMETRIZE { pivotMove = MOVE_U_TURN; }
    PARAMETRIZE { pivotMove = MOVE_VOLT_SWITCH; }
    PARAMETRIZE { pivotMove = MOVE_FLIP_TURN; }

    GIVEN {
        ASSUME(GetMoveEffect(pivotMove) == EFFECT_HIT_ESCAPE);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Moves(pivotMove, MOVE_TACKLE, MOVE_GROWL, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, pivotMove); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: Knock Off is preferred over Crunch when the target still has a removable item")
{
    GIVEN {
        ASSUME(B_KNOCK_OFF_DMG >= GEN_6);
        ASSUME(B_TRAINERS_KNOCK_OFF_ITEMS == TRUE);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Item(ITEM_LEFTOVERS); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_UMBREON) { Moves(MOVE_KNOCK_OFF, MOVE_CRUNCH, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_KNOCK_OFF, MOVE_CRUNCH);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, MOVE_KNOCK_OFF);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI custom scenarios: after item pressure is gone, AI prefers stronger Dark damage over Knock Off")
{
    GIVEN {
        ASSUME(B_KNOCK_OFF_DMG >= GEN_6);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); Item(ITEM_NONE); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_UMBREON) { Moves(MOVE_KNOCK_OFF, MOVE_CRUNCH, MOVE_GROWL, MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            SCORE_GT(opponent, MOVE_CRUNCH, MOVE_KNOCK_OFF);
            MOVE(player, MOVE_CELEBRATE);
            EXPECT_MOVE(opponent, MOVE_CRUNCH);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI custom scenarios: Helping Hand can turn partner damage from non-KO into KO", s16 damage)
{
    s16 hpThreshold;
    bool32 helperUsesHelpingHand;
    hpThreshold = 30;
    PARAMETRIZE { helperUsesHelpingHand = FALSE; }
    PARAMETRIZE { helperUsesHelpingHand = TRUE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HELPING_HAND) == EFFECT_HELPING_HAND);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAGS_TRAINER_PROFILE);
        PLAYER(SPECIES_WOBBUFFET) { HP(hpThreshold); MaxHP(hpThreshold); Speed(200); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(200); Moves(MOVE_CELEBRATE); }
        if (helperUsesHelpingHand)
            OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_HELPING_HAND, MOVE_CELEBRATE); }
        else
            OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PIKACHU) { Level(50); Speed(90); Moves(MOVE_THUNDERBOLT, MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            if (helperUsesHelpingHand)
                EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND);
            else
                EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentRight, MOVE_THUNDERBOLT, target: playerLeft);
        }
    } SCENE {
        HP_BAR(playerLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT(results[0].damage < hpThreshold);
        EXPECT(results[1].damage >= hpThreshold);
    }
}
