AreaZero_Inside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AreaZero_Inside_OnTransition
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AreaZero_Inside_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AreaZero_Inside_OnFrame
	.byte 0

AreaZero_Inside_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_AREA_ZERO_GREAT_TUSK
	end

AreaZero_Inside_OnFrame:
	map_script_2 VAR_AREAZERO_STATE, 5, AreaZero_Inside_StartScript
	.2byte 0

AreaZero_Inside_StartScript::
	lockall
	setvar VAR_AREAZERO_STATE, 6
	releaseall
	end

AreaZero_Inside_EventScript_Steven::
	lock
	faceplayer
	msgbox AreaZero_Inside_Text_StevenCrystalsRooted, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_Andry::
	lock
	faceplayer
	msgbox AreaZero_Inside_Text_AndryCaveFeelsAlive, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_Wally::
	lock
	faceplayer
	msgbox AreaZero_Inside_Text_WallyCrystalPulse, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_Rival::
	lock
	faceplayer
	msgbox AreaZero_Inside_Text_RivalDadNotebook, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_Splitface::
	lock
	faceplayer
	msgbox AreaZero_Inside_Text_SplitfaceGlowRocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_GreatTusk::
	lock
	faceplayer
	playmoncry SPECIES_GREAT_TUSK, CRY_MODE_NORMAL
	waitmoncry
	release
	end

AreaZero_Inside_EventScript_SmallCrystal::
	compare VAR_AREAZERO_STATE, 4
	goto_if_ge AreaZero_Outside_EventScript_RockSmashCrystal
	lockall
	msgbox AreaZero_Inside_Text_SmallCrystalPulse, MSGBOX_DEFAULT
	releaseall
	end

AreaZero_Inside_EventScript_AfterBreakingStoryCrystal::
	setflag FLAG_AREA_ZERO_CRYSTAL2
	removeobject AREA_ZERO_INSIDE_CRYSTAL_EXIT
	delay 24
	playmoncry SPECIES_GREAT_TUSK, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	applymovement AREAZERO_STEVEN_INSIDE, Common_Movement_QuestionMark
	applymovement AREAZERO_ANDRY_INSIDE, Common_Movement_QuestionMark
	applymovement AREAZERO_WALLY_INSIDE, Common_Movement_QuestionMark
	applymovement AREAZERO_RIVAL_INSIDE, Common_Movement_QuestionMark
	applymovement AREAZERO_EDO_INSIDE, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement AREAZERO_STEVEN_INSIDE, Common_Movement_FaceUp
	applymovement AREAZERO_ANDRY_INSIDE, Common_Movement_FaceUp
	applymovement AREAZERO_WALLY_INSIDE, Common_Movement_FaceUp
	applymovement AREAZERO_RIVAL_INSIDE, Common_Movement_FaceUp
	applymovement AREAZERO_EDO_INSIDE, Common_Movement_FaceUp
	waitmovement 0
	delay 8
	setobjectxyperm AREAZERO_GREAT_TUSK_INSIDE, 11, 3
	setobjectmovementtype AREAZERO_GREAT_TUSK_INSIDE, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_AREA_ZERO_GREAT_TUSK
	addobject AREAZERO_GREAT_TUSK_INSIDE
	delay 16
	delay 16
	applymovement AREAZERO_GREAT_TUSK_INSIDE, Common_Movement_FacePlayer
	waitmovement 0
	delay 16
	msgbox AreaZero_Inside_Text_WallyPlayer, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, AREAZERO_GREAT_TUSK_INSIDE
	setwildbattle SPECIES_GREAT_TUSK, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AreaZero_Inside_EventScript_GreatTuskGone
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AreaZero_Inside_EventScript_GreatTuskGone
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, AreaZero_Inside_EventScript_GreatTuskGone
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AreaZero_Inside_EventScript_GreatTuskGone
	goto AreaZero_Inside_EventScript_GreatTuskGone

AreaZero_Inside_EventScript_GreatTuskGone:
	setflag FLAG_AREA_ZERO_GREAT_TUSK
	removeobject AREAZERO_GREAT_TUSK_INSIDE
	setvar VAR_AREAZERO_STATE, 7
	releaseall
	end

AreaZero_Inside_Text_StevenCrystalsRooted:
	.string "STEVEN: The energy is much\n"
	.string "denser inside the cave.\p"
	.string "These crystals are not simply\n"
	.string "sitting here.\p"
	.string "They seem rooted into the stone,\n"
	.string "drawing power from the walls. $"

AreaZero_Inside_Text_AndryCaveFeelsAlive:
	.string "ANDRY: Listen closely...\p"
	.string "The whole cave is vibrating.\p"
	.string "If those cries belong to\n"
	.string "POKéMON, something may be\l"
	.string "pulling them toward this place. $"

AreaZero_Inside_Text_WallyCrystalPulse:
	.string "WALLY: The air is fresh here,\n"
	.string "too, but it feels heavier.\p"
	.string "Every crystal gives off a little\n"
	.string "pulse.\p"
	.string "It's almost like the cave is\n"
	.string "breathing with them. $"

AreaZero_Inside_Text_RivalDadNotebook:
	.string "{RIVAL}: These formations aren't\n"
	.string "random.\p"
	.string "The smaller crystals almost look\n"
	.string "like they point toward the\l"
	.string "passage ahead.\p"
	.string "My dad would lose his mind\n"
	.string "over this place. $"

AreaZero_Inside_Text_SplitfaceGlowRocks:
	.string "SPLITFACE: Okay, hold up.\p"
	.string "The island was sparkly, sure,\n"
	.string "but this is deluxe sparkly.\p"
	.string "These little glow rocks are\n"
	.string "humming.\p"
	.string "Can rocks hum?\n"
	.string "They absolutely should not hum. $"

AreaZero_Inside_Text_SmallCrystalPulse:
	.string "A small crystal pulses with\n"
	.string "a sharp, bright light. $"

AreaZero_Inside_Text_WallyPlayer:
	.string "WALLY: {PLAYER}! $"
