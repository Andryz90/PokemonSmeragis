AreaZero_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AreaZero_Outside_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AreaZero_Outside_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AreaZero_Outside_OnFrame
	.byte 0

AreaZero_Outside_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_AREAZERO_STATE, 0xFF, AreaZero_Outside_OnTransition_RestoreWildMons
	call_if_ne VAR_AREAZERO_STATE, 0xFF, AreaZero_Outside_OnTransition_HideWildMons
	call_if_ge VAR_AREAZERO_STATE, 5, AreaZero_Outside_OnTransition_SetPostCaveObjectPositions
	end

AreaZero_Outside_OnTransition_RestoreWildMons:
	setobjectxyperm AREAZERO_WILD_OW_MON_1, 18, 37
	setobjectxyperm AREAZERO_WILD_OW_MON_2, 30, 35
	setobjectxyperm AREAZERO_WILD_OW_MON_3, 23, 30
	setobjectxyperm AREAZERO_WILD_OW_MON_4, 26, 23
	return

AreaZero_Outside_OnTransition_HideWildMons:
	setobjectxyperm AREAZERO_WILD_OW_MON_1, 0, 0
	setobjectxyperm AREAZERO_WILD_OW_MON_2, 0, 0
	setobjectxyperm AREAZERO_WILD_OW_MON_3, 0, 0
	setobjectxyperm AREAZERO_WILD_OW_MON_4, 0, 0
	return

AreaZero_Outside_OnTransition_SetPostCaveObjectPositions:
	clearflag FLAG_AREA_ZERO_LATIS
	setobjectxyperm AREA_ZERO_LATIOS, 21, 14
	setobjectxyperm AREA_ZERO_LATIAS, 24, 14
	setobjectmovementtype AREA_ZERO_LATIOS, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype AREA_ZERO_LATIAS, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm AREAZERO_STEVEN, 0, 0
	setobjectxyperm AREAZERO_ANDRY, 0, 0
	setobjectxyperm AREAZERO_EDO, 0, 0
	setobjectxyperm AREAZERO_WALLY, 0, 0
	setobjectxyperm AREAZERO_RIVAL, 0, 0
	setobjectmovementtype AREAZERO_STEVEN, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_ANDRY, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_EDO, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_WALLY, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_RIVAL, MOVEMENT_TYPE_NONE
	return

AreaZero_Outside_OnWarp:
	map_script_2 VAR_AREAZERO_STATE, 1, AreaZero_Outside_EventScript_PlayerFaceUp
	.2byte 0

AreaZero_Outside_EventScript_PlayerFaceUp::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

AreaZero_Outside_OnFrame:
	map_script_2 VAR_AREAZERO_STATE, 1, AreaZero_Outside_Intro
	.2byte 0

AreaZero_Outside_EventScript_Steven::
	lock
	faceplayer
	msgbox AreaZero_Outside_Text_StevenAnalyzingCrystals, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside_EventScript_Andry::
	lock
	faceplayer
	compare VAR_AREAZERO_STATE, 4
	goto_if_ge AreaZero_Outside_EventScript_AndryAfterTrigger
	msgbox AreaZero_Outside_Text_AndryStevenCanStudyCrystals, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_AREAZERO_STATE, 3
	release
	end

AreaZero_Outside_EventScript_AndryAfterTrigger:
	msgbox AreaZero_Outside_Text_AndryLatiWarningBreakCrystal, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside_EventScript_Wally::
	lock
	faceplayer
	msgbox AreaZero_Outside_Text_WallyLikesThisPlace, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside_EventScript_Rival::
	lock
	faceplayer
	msgbox AreaZero_Outside_Text_RivalSeesMoreCrystals, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside_EventScript_Splitface::
	lock
	faceplayer
	msgbox AreaZero_Outside_Text_SplitfaceCrystalsComment, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside_Intro::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	msgbox AreaZero_Outside_Text_StevenThisMustBeThePlace, MSGBOX_DEFAULT
	closemessage
	applymovement AREAZERO_STEVEN, AreaZero_Outside_Steven_ReachWally
	applymovement LOCALID_PLAYER, AreaZero_Outside_Player_ReachWally
	waitmovement 0
	applymovement AREAZERO_WALLY, Common_Movement_FaceRight
	applymovement AREAZERO_STEVEN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox AreaZero_Outside_Text_WallyYouMadeIt, MSGBOX_AUTOCLOSE
	applymovement AREAZERO_STEVEN, AreaZero_Outside_Steven_Player_ReachRival
	applymovement LOCALID_PLAYER, AreaZero_Outside_Steven_Player_ReachRival
	waitmovement 0
	applymovement AREAZERO_RIVAL, Common_Movement_FaceLeft
	applymovement AREAZERO_STEVEN, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox AreaZero_Outside_Text_RivalIncredibleIsland, MSGBOX_AUTOCLOSE
	applymovement AREAZERO_STEVEN, AreaZero_Outside_Steven_Player_ReachAndry
	applymovement LOCALID_PLAYER, AreaZero_Outside_Steven_Player_ReachAndry
	waitmovement 0
	msgbox AreaZero_Outside_Text_AndryEtherealPlace, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry

	@Latis Movement

	applymovement AREA_ZERO_LATIAS, Common_Movement_WalkUp4
	applymovement AREA_ZERO_LATIAS, Common_Movement_WalkUp4
	waitmovement 0
	removeobject AREA_ZERO_LATIAS
	removeobject AREA_ZERO_LATIOS

	setobjectxyperm AREA_ZERO_LATIOS, 30, 50
	addobject AREA_ZERO_LATIOS
	turnobject AREA_ZERO_LATIOS, DIR_WEST

	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	applymovement AREA_ZERO_LATIOS, AreaZero_Outside_LatiosFlyby
	waitmovement 0
	removeobject AREA_ZERO_LATIOS
	setobjectxyperm AREA_ZERO_LATIOS, 21, 14
	setobjectxyperm AREA_ZERO_LATIAS, 24, 14
	addobject AREA_ZERO_LATIAS
	addobject AREA_ZERO_LATIOS
	setobjectmovementtype AREA_ZERO_LATIOS, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_AREA_ZERO_LATIS

	@ End Latis positioning

	applymovement AREAZERO_STEVEN, Common_Movement_WalkUp4
	applymovement AREAZERO_ANDRY, Common_Movement_WalkUp4
	waitmovement 0
	applymovement AREAZERO_STEVEN, Common_Movement_WalkUp4
	applymovement AREAZERO_ANDRY, Common_Movement_WalkUp4
	waitmovement 0

	@ Rivals Movement
	applymovement AREAZERO_WALLY, AreaZero_Outside_Wally_ReachPlayer
	applymovement AREAZERO_RIVAL, AreaZero_Outside_Rival_FollowWally
	waitmovement 0
	applymovement AREAZERO_WALLY, Common_Movement_FaceLeft
	applymovement AREAZERO_RIVAL, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox AreaZero_Outside_Text_WallyLetsGoPlayer, MSGBOX_AUTOCLOSE
	applymovement AREAZERO_WALLY, AreaZero_Outside_Wally_Rival_LeaveScene
	applymovement AREAZERO_RIVAL, AreaZero_Outside_Wally_Rival_LeaveScene
	waitmovement 0

	@Distribuite people on map
	removeobject AREAZERO_STEVEN
	removeobject AREAZERO_ANDRY
	removeobject AREAZERO_WALLY
	removeobject AREAZERO_RIVAL

	setobjectxyperm AREAZERO_STEVEN, 21, 20
	setobjectxyperm AREAZERO_ANDRY, 25, 20
	setobjectxyperm AREAZERO_WALLY, 14, 29
	setobjectxyperm AREAZERO_RIVAL, 30, 34

	addobject AREAZERO_STEVEN
	addobject AREAZERO_ANDRY
	addobject AREAZERO_WALLY
	addobject AREAZERO_RIVAL

	clearflag FLAG_AREA_ZERO_OBJ @ Safety
	setobjectmovementtype AREAZERO_STEVEN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO_ANDRY,  MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype AREAZERO_WALLY,  MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype AREAZERO_RIVAL,  MOVEMENT_TYPE_FACE_RIGHT

	setvar VAR_AREAZERO_STATE, 2
	releaseall
	end

AreaZero_Outside_EventTrigger::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 24
	goto_if_eq AreaZero_Outside_EventTrigger_Right
	compare VAR_TEMP_0, 23
	goto_if_eq AreaZero_Outside_EventTrigger_Middle
	goto AreaZero_Outside_EventTrigger_Left

AreaZero_Outside_EventTrigger_Left:
	applymovement AREAZERO_STEVEN, AreaZero_Outside_Steven_ApproachTriggerLeft
	waitmovement 0
	goto AreaZero_Outside_EventTrigger_PositionAndry

AreaZero_Outside_EventTrigger_Middle:
	applymovement AREAZERO_STEVEN, AreaZero_Outside_Steven_ApproachTriggerMiddle
	waitmovement 0
	goto AreaZero_Outside_EventTrigger_PositionAndry

AreaZero_Outside_EventTrigger_Right:
	applymovement AREAZERO_STEVEN, AreaZero_Outside_Steven_ApproachTriggerRight
	waitmovement 0
	goto AreaZero_Outside_EventTrigger_PositionAndry

AreaZero_Outside_EventTrigger_PositionAndry:
	compare VAR_TEMP_0, 24
	goto_if_eq AreaZero_Outside_EventTrigger_AndryLeftOfSteven
	compare VAR_TEMP_0, 23
	goto_if_eq AreaZero_Outside_EventTrigger_AndryRightOfStevenMiddle
	goto AreaZero_Outside_EventTrigger_AndryRightOfStevenLeft

AreaZero_Outside_EventTrigger_AndryRightOfStevenLeft:
	applymovement AREAZERO_ANDRY, AreaZero_Outside_Andry_ApproachTriggerLeft
	waitmovement 0
	goto AreaZero_Outside_EventTrigger_StevenSpeaks

AreaZero_Outside_EventTrigger_AndryRightOfStevenMiddle:
	applymovement AREAZERO_ANDRY, AreaZero_Outside_Andry_ApproachTriggerMiddle
	waitmovement 0
	goto AreaZero_Outside_EventTrigger_StevenSpeaks

AreaZero_Outside_EventTrigger_AndryLeftOfSteven:
	applymovement AREAZERO_ANDRY, AreaZero_Outside_Andry_ApproachTriggerRight
	waitmovement 0
	goto AreaZero_Outside_EventTrigger_StevenSpeaks

AreaZero_Outside_EventTrigger_StevenSpeaks:
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox AreaZero_Outside_Text_StevenFirstCrystalAnalysis, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside_EventTrigger_AndrySpeaks

AreaZero_Outside_EventTrigger_AndrySpeaks:
	msgbox AreaZero_Outside_Text_AndryLatiWarningBreakCrystal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_AREAZERO_STATE, 4
	releaseall
	end

AreaZero_Outside_EventTrigger_BreakCrystalReminder::
	lockall
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, AreaZero_Outside_EventTrigger_BreakCrystalReminder_Block
	releaseall
	end

AreaZero_Outside_EventTrigger_BreakCrystalReminder_Block:
	msgbox AreaZero_Outside_Text_BreakCrystalBeforeLeaving, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

AreaZero_Crystal_BlockingSign::
	msgbox AreaZero_Outside_Text_SmallCrystalBrightLight, MSGBOX_SIGN
	end

AreaZero_Outside_EventScript_SmallCrystal::
	compare VAR_AREAZERO_STATE, 4
	goto_if_ge AreaZero_Outside_EventScript_RockSmashCrystal
	lockall
	msgbox AreaZero_Outside_Text_SmallCrystalBrightLight, MSGBOX_DEFAULT
	releaseall
	end

AreaZero_Outside_EventScript_UseRockSmashCrystal::
	lockall
	goto AreaZero_Outside_EventScript_SmashCrystalCommon

AreaZero_Outside_EventScript_RockSmashCrystal:
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage

AreaZero_Outside_EventScript_SmashCrystalCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	compare VAR_AREAZERO_STATE, 4
	goto_if_eq AreaZero_Outside_EventScript_CheckOutsideStoryCrystal
	compare VAR_AREAZERO_STATE, 6
	goto_if_eq AreaZero_Outside_EventScript_CheckInsideStoryCrystal
	goto AreaZero_Outside_EventScript_RemoveSmashedCrystal

AreaZero_Outside_EventScript_CheckOutsideStoryCrystal:
	compare VAR_LAST_TALKED, AREA_ZERO_CRYSTAL_CAVERN_ENTRANCE
	goto_if_eq AreaZero_Outside_EventScript_AfterBreakingStoryCrystal
	goto AreaZero_Outside_EventScript_RemoveSmashedCrystal

AreaZero_Outside_EventScript_CheckInsideStoryCrystal:
	compare VAR_LAST_TALKED, AREA_ZERO_INSIDE_CRYSTAL_EXIT
	goto_if_eq AreaZero_Inside_EventScript_AfterBreakingStoryCrystal

AreaZero_Outside_EventScript_RemoveSmashedCrystal:
	removeobject VAR_LAST_TALKED
	releaseall
	end

AreaZero_Outside_EventScript_AfterBreakingStoryCrystal:
	setflag FLAG_AREA_ZERO_CRYSTAL
	removeobject AREA_ZERO_CRYSTAL_CAVERN_ENTRANCE
	playmoncry SPECIES_GREAT_TUSK, CRY_MODE_NORMAL
	waitmoncry
	applymovement AREAZERO_STEVEN, Common_Movement_ExclamationMark
	applymovement AREAZERO_ANDRY, Common_Movement_ExclamationMark
	waitmovement 0
	goto AreaZero_Outside_EventScript_AfterBreakingCrystal

AreaZero_Outside_EventScript_AfterBreakingCrystal:
	setvar VAR_AREAZERO_STATE, 5
	removeobject AREAZERO_EDO
	removeobject AREAZERO_WALLY
	removeobject AREAZERO_RIVAL
	setobjectxyperm AREAZERO_WALLY, 23, 24
	setobjectxyperm AREAZERO_RIVAL, 23, 25
	clearflag FLAG_AREA_ZERO_OBJ
	addobject AREAZERO_EDO
	setobjectmovementtype AREAZERO_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO_RIVAL, MOVEMENT_TYPE_FACE_UP
	compare VAR_TEMP_0, 22
	goto_if_eq AreaZero_Outside_EventScript_SplitfaceApproachFreeRight
	goto AreaZero_Outside_EventScript_SplitfaceApproachFreeLeft

AreaZero_Outside_EventScript_SplitfaceApproachFreeRight:
	applymovement AREAZERO_EDO, AreaZero_Outside_Splitface_ApproachFreeRight
	waitmovement 0
	goto AreaZero_Outside_EventScript_SplitfaceCryComment

AreaZero_Outside_EventScript_SplitfaceApproachFreeLeft:
	applymovement AREAZERO_EDO, AreaZero_Outside_Splitface_ApproachFreeLeft
	waitmovement 0
	goto AreaZero_Outside_EventScript_SplitfaceCryComment

AreaZero_Outside_EventScript_SplitfaceCryComment:
	msgbox AreaZero_Outside_Text_SplitfaceCrystalBroke, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside_Text_StevenWasItDonphan, MSGBOX_DEFAULT
	closemessage
	addobject AREAZERO_WALLY
	addobject AREAZERO_RIVAL
	applymovement AREAZERO_WALLY, AreaZero_Outside_Group_ApproachCaveWR
	applymovement AREAZERO_RIVAL, AreaZero_Outside_Group_ApproachCaveWR
	waitmovement 0
	msgbox AreaZero_Outside_Wally_Cavern_Text, MSGBOX_DEFAULT
	msgbox AreaZero_Outside_Text_Rival, MSGBOX_DEFAULT
	playmoncry SPECIES_IRON_BUNDLE, CRY_MODE_NORMAL
	waitmoncry
	applymovement AREAZERO_STEVEN, Common_Movement_QuestionMark
	applymovement AREAZERO_ANDRY, Common_Movement_QuestionMark
	applymovement AREAZERO_WALLY, Common_Movement_QuestionMark
	applymovement AREAZERO_RIVAL, Common_Movement_QuestionMark
	applymovement AREAZERO_EDO, Common_Movement_QuestionMark
	waitmovement 0
	msgbox AreaZero_Outside_Text_SplitfaceWasItDelibird, MSGBOX_DEFAULT
	msgbox AreaZero_Outside_Text_AndryCav, MSGBOX_DEFAULT
	setwarp MAP_AREA_ZERO_INSIDE, 10, 15
	special DoContestHallWarp
	waitstate 
	end

AreaZero_Outside_Steven_ReachWally::
	face_player
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

AreaZero_Outside_Player_ReachWally::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end
AreaZero_Outside_Steven_Player_ReachRival::
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	step_end
AreaZero_Outside_Steven_Player_ReachAndry::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AreaZero_Outside_LatiosFlyby::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Outside_Wally_ReachPlayer::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AreaZero_Outside_Rival_FollowWally::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

AreaZero_Outside_Wally_Rival_LeaveScene::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AreaZero_Outside_Steven_ApproachTriggerLeft::
	walk_right
	walk_up
	face_up
	step_end

AreaZero_Outside_Steven_ApproachTriggerMiddle::
	walk_right
	walk_right
	walk_up
	face_up
	step_end

AreaZero_Outside_Steven_ApproachTriggerRight::
	walk_right
	walk_right
	walk_right
	walk_up
	face_up
	step_end

AreaZero_Outside_Andry_ApproachTriggerLeft::
	walk_left
	walk_left
	walk_up
	face_up
	step_end

AreaZero_Outside_Andry_ApproachTriggerMiddle::
	walk_left
	walk_up
	face_up
	step_end

AreaZero_Outside_Andry_ApproachTriggerRight::
	walk_left
	walk_left
	walk_up
	face_up
	step_end

AreaZero_Outside_Splitface_ApproachFreeRight::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_up
	step_end

AreaZero_Outside_Splitface_ApproachFreeLeft::
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_up
	step_end

AreaZero_Outside_Group_ApproachCaveWR::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AreaZero_Outside_Player_EnterCave::
	walk_up
	walk_up
	step_end

AreaZero_Outside_Text_StevenThisMustBeThePlace:
	.string "STEVEN: This appears to be\n"
	.string "the place.\p"
	.string "Let's catch up with the others.\n"
	.string "They went on ahead to explore. $"

AreaZero_Outside_Text_WallyYouMadeIt:
	.string "WALLY: {PLAYER}, you made it!\p"
	.string "Feel that wind?\n"
	.string "The air is so fresh here.\p"
	.string "It feels amazing just to\n"
	.string "breathe it in! $"

AreaZero_Outside_Text_RivalIncredibleIsland:
	.string "{RIVAL}: I can't believe a\n"
	.string "place like this exists.\p"
	.string "I never saw an island like this\n"
	.string "mentioned anywhere in my dad's\l"
	.string "field journals. $"

AreaZero_Outside_Text_AndryEtherealPlace:
	.string "ANDRY: STEVEN, do you know\n"
	.string "what this place is?\p"
	.string "It feels almost ethereal...\p"
	.string "SPLITFACE ran ahead after\n"
	.string "spotting the same crystals we\l"
	.string "saw earlier.\p"
	.string "Let's catch up to him.\n"
	.string "LATIAS looks worried. $"

AreaZero_Outside_Text_WallyLetsGoPlayer:
	.string "WALLY: Let's go, {PLAYER}! $"

AreaZero_Outside_Text_CrystalBlockingPassage:
	.string "A crystal is blocking\n"
	.string "the passage. $"

AreaZero_Outside_Text_SmallCrystalBrightLight:
	.string "A small crystal is glowing\n"
	.string "with a bright light. $"

AreaZero_Outside_Text_SplitfaceCrystalBroke:
	.string "SPLITFACE: Whoa, it broke!\n"
	.string "What was that cry? A POKéMON? $"

AreaZero_Outside_Text_StevenWasItDonphan:
	.string "STEVEN: Was that...\n"
	.string "a DONPHAN? $"

AreaZero_Outside_Wally_Cavern_Text::
	.string "WALLY: I didn't know that there are\nPOKéMON here.\p"
	.string "We should check it out\nthe cave then. $"

AreaZero_Outside_Text_Rival:
	.string "{RIVAL}: We shall go inside then. $"

AreaZero_Outside_Text_SplitfaceWasItDelibird:
	.string "SPLITFACE: Was that...\n"
	.string "a DELIBIRD? $"

AreaZero_Outside_Text_AndryCav:
	.string "ANDRY: Lets move on. $"

AreaZero_Outside_Text_StevenFirstCrystalAnalysis:
	.string "STEVEN: I've finished my\n"
	.string "preliminary analysis.\p"
	.string "These crystals appear to act\n"
	.string "as vessels for energy.\p"
	.string "A great abundance of that\n"
	.string "power must have gathered here,\l"
	.string "crystallizing into this form.\p"
	.string "Judging by their distribution,\n"
	.string "the source seems to be coming\l"
	.string "from the cave.\p"
	.string "We should investigate.\p"
	.string "The smaller crystals seem more\n"
	.string "fragile, though.\p"
	.string "They may be breakable with\n"
	.string "ROCK SMASH. $"

AreaZero_Outside_Text_AndryLatiWarningBreakCrystal:
	.string "ANDRY: LATIOS and LATIAS\n"
	.string "probably sensed this power as\l"
	.string "a threat.\p"
	.string "Maybe they came here to warn\n"
	.string "us.\p"
	.string "{PLAYER}, break the crystal\n"
	.string "so we can move on. $"

AreaZero_Outside_Text_BreakCrystalBeforeLeaving:
	.string "{PLAYER}, destroy the crystal\n"
	.string "so we can check the cave. $"

AreaZero_Outside_Text_StevenAnalyzingCrystals:
	.string "STEVEN: I've never seen\n"
	.string "anything like this.\p"
	.string "I'm analyzing these crystals\n"
	.string "now, trying to trace the\l"
	.string "source of their power. $"

AreaZero_Outside_Text_AndryStevenCanStudyCrystals:
	.string "ANDRY: Edoardo...\p"
	.string "As overexcited as he is\n"
	.string "about the crystals, he has a\l"
	.string "point.\p"
	.string "We don't know what they are\n"
	.string "or where they came from.\p"
	.string "All we know is that they emit\n"
	.string "a strong light that seems to\l"
	.string "create a strange power.\p"
	.string "STEVEN is analyzing them to\n"
	.string "see if he can learn anything.\p"
	.string "After all, he's the best person\n"
	.string "we could possibly ask. $"

AreaZero_Outside_Text_WallyLikesThisPlace:
	.string "WALLY: I really like this place.\p"
	.string "The air reminds me of home.\p"
	.string "I don't know what those crystals\n"
	.string "are, but I can feel a strange\l"
	.string "power coming from them. $"

AreaZero_Outside_Text_RivalSeesMoreCrystals:
	.string "{RIVAL}: From here, I can see\n"
	.string "more crystals scattered across\l"
	.string "this whole part of the island. \p"
	.string "They seem to glow some kind of\nenergy. $"

AreaZero_Outside_Text_SplitfaceCrystalsEverywhere:
	.string "SPLITFACE: Look at all these\n"
	.string "crystals!\p"
	.string "They're everywhere!\n"
	.string "They're super sparkly!\p"
	.string "I have no clue what they are,\n"
	.string "though. $"

AreaZero_Outside_Text_SplitfaceCrystalsComment:
	.string "SPLITFACE: Cazzo fratello,\nsassi che luccicano!\p"
	.string "Crystals, crystals, crystals...\n"
	.string "They're everywhere!\p"
	.string "They're super sparkly!\l"
	.string "I have no clue what they are,\n"
	.string "though. $"
