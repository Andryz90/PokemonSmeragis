#ifndef GUARD_CONSTANTS_BATTLE_AI_CONSTANTS_INC
#define GUARD_CONSTANTS_BATTLE_AI_CONSTANTS_INC

	.set AI_FLAG_CHECK_BAD_MOVE,             1 << 0
	.set AI_FLAG_TRY_TO_FAINT,               1 << 1
	.set AI_FLAG_CHECK_VIABILITY,            1 << 2
	.set AI_FLAG_FORCE_SETUP_FIRST_TURN,     1 << 3
	.set AI_FLAG_RISKY,                      1 << 4
	.set AI_FLAG_TRY_TO_2HKO,                1 << 5
	.set AI_FLAG_PREFER_BATON_PASS,          1 << 6
	.set AI_FLAG_DOUBLE_BATTLE,              1 << 7
	.set AI_FLAG_HP_AWARE,                   1 << 8
	.set AI_FLAG_POWERFUL_STATUS,            1 << 9
	.set AI_FLAG_NEGATE_UNAWARE,             1 << 10
	.set AI_FLAG_WILL_SUICIDE,               1 << 11
	.set AI_FLAG_PREFER_STATUS_MOVES,        1 << 12
	.set AI_FLAG_STALL,                      1 << 13
	.set AI_FLAG_SMART_SWITCHING,            1 << 14
	.set AI_FLAG_ACE_POKEMON,                1 << 15
	.set AI_FLAG_OMNISCIENT,                 1 << 16
	.set AI_FLAG_SMART_MON_CHOICES,          1 << 17
	.set AI_FLAG_CONSERVATIVE,               1 << 18
	.set AI_FLAG_SEQUENCE_SWITCHING,         1 << 19
	.set AI_FLAG_DOUBLE_ACE_POKEMON,         1 << 20
	.set AI_FLAG_WEIGH_ABILITY_PREDICTION,   1 << 21
	.set AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE, 1 << 22
	.set AI_FLAG_PREDICT_SWITCH,             1 << 23
	.set AI_FLAG_PREDICT_INCOMING_MON,       1 << 24
	.set AI_FLAG_PP_STALL_PREVENTION,        1 << 25
	.set AI_FLAG_PREDICT_MOVE,               1 << 26

	.set AI_FLAG_BASIC_TRAINER, AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY
	.set AI_FLAG_SMART_TRAINER, AI_FLAG_BASIC_TRAINER | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_WEIGH_ABILITY_PREDICTION
	.set AI_FLAG_PREDICTION, AI_FLAG_PREDICT_SWITCH | AI_FLAG_PREDICT_INCOMING_MON | AI_FLAG_PREDICT_MOVE

@ High u64-only flags are intentionally omitted here while setwildbattleaiflags
@ writes a single word.

#endif @ GUARD_CONSTANTS_BATTLE_AI_CONSTANTS_INC
