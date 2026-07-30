.set AREA_ZERO_INSIDE_2_POST_SCENE_VALUE, 15

AreaZero_Inside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AreaZero_Inside_OnTransition
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AreaZero_Inside_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AreaZero_Inside_OnFrame
	.byte 0

AreaZero_Inside_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_AREA_ZERO_GREAT_TUSK
	setflag FLAG_AREA_ZERO_IRON_JUGULIS
	setflag FLAG_AREA_ZERO_FLUTTER_MANE
	call_if_ge VAR_AREAZERO_STATE, 8, AreaZero_Inside_OnTransition_SetPostParadoxObjectPositions
	call_if_ge VAR_AREAZERO_STATE, AREA_ZERO_INSIDE_2_POST_SCENE_VALUE, AreaZero_Inside_OnTransition_RemoveAllAreaZeroInsideNpcs
	end

AreaZero_Inside_OnTransition_SetPostParadoxObjectPositions:
	clearflag FLAG_AREA_ZERO_OBJ
	clearflag FLAG_AREA_ZERO_IRON_JUGULIS
	clearflag FLAG_AREA_ZERO_FLUTTER_MANE
	setobjectxyperm AREAZERO_STEVEN_INSIDE, 0, 0
	setobjectxyperm AREAZERO_ANDRY_INSIDE, 0, 0
	setobjectxyperm AREAZERO_EDO_INSIDE, 0, 0
	setobjectxyperm AREAZERO_WALLY_INSIDE, 10, 7
	setobjectxyperm AREAZERO_RIVAL_INSIDE, 12, 7
	setobjectxyperm AREAZERO_IRON_JUGULIS_INSIDE, 10, 8
	setobjectxyperm AREAZERO_FLUTTER_MANE_INSIDE, 12, 8
	setobjectmovementtype AREAZERO_STEVEN_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_ANDRY_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_EDO_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_WALLY_INSIDE, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype AREAZERO_RIVAL_INSIDE, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype AREAZERO_IRON_JUGULIS_INSIDE, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO_FLUTTER_MANE_INSIDE, MOVEMENT_TYPE_FACE_UP
	return

AreaZero_Inside_OnTransition_RemoveAllAreaZeroInsideNpcs:
	setflag FLAG_AREA_ZERO_OBJ
	setflag FLAG_AREA_ZERO_GREAT_TUSK
	setflag FLAG_AREA_ZERO_IRON_JUGULIS
	setflag FLAG_AREA_ZERO_FLUTTER_MANE
	removeobject AREAZERO_EDO_INSIDE
	removeobject AREAZERO_ANDRY_INSIDE
	removeobject AREAZERO_WALLY_INSIDE
	removeobject AREAZERO_STEVEN_INSIDE
	removeobject AREAZERO_RIVAL_INSIDE
	removeobject AREAZERO_GREAT_TUSK_INSIDE
	removeobject AREAZERO_IRON_JUGULIS_INSIDE
	removeobject AREAZERO_FLUTTER_MANE_INSIDE
	setobjectxyperm AREAZERO_EDO_INSIDE, 0, 0
	setobjectxyperm AREAZERO_ANDRY_INSIDE, 0, 0
	setobjectxyperm AREAZERO_WALLY_INSIDE, 0, 0
	setobjectxyperm AREAZERO_STEVEN_INSIDE, 0, 0
	setobjectxyperm AREAZERO_RIVAL_INSIDE, 0, 0
	setobjectxyperm AREAZERO_GREAT_TUSK_INSIDE, 0, 0
	setobjectxyperm AREAZERO_IRON_JUGULIS_INSIDE, 0, 0
	setobjectxyperm AREAZERO_FLUTTER_MANE_INSIDE, 0, 0
	setobjectmovementtype AREAZERO_EDO_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_ANDRY_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_WALLY_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_STEVEN_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_RIVAL_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_GREAT_TUSK_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_IRON_JUGULIS_INSIDE, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO_FLUTTER_MANE_INSIDE, MOVEMENT_TYPE_NONE
	return

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
	compare VAR_AREAZERO_STATE, 8
	goto_if_ge AreaZero_Inside_EventScript_WallyRivalHoldThemOff
	faceplayer
	msgbox AreaZero_Inside_Text_WallyCrystalPulse, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_Rival::
	lock
	compare VAR_AREAZERO_STATE, 8
	goto_if_ge AreaZero_Inside_EventScript_WallyRivalHoldThemOff
	faceplayer
	msgbox AreaZero_Inside_Text_RivalDadNotebook, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Inside_EventScript_WallyRivalHoldThemOff:
	msgbox AreaZero_Inside_Text_WallyRivalHoldThemOff, MSGBOX_DEFAULT
	closemessage
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

AreaZero_Inside_EventScript_IronJugulis::
	lock
	faceplayer
	playmoncry SPECIES_IRON_JUGULIS, CRY_MODE_NORMAL
	waitmoncry
	release
	end

AreaZero_Inside_EventScript_FlutterMane::
	lock
	faceplayer
	playmoncry SPECIES_FLUTTER_MANE, CRY_MODE_NORMAL
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
	call AreaZero_Inside_EventScript_PlayerFaceGreatTusk
	delay 16
	delay 16
	applymovement AREAZERO_GREAT_TUSK_INSIDE, Common_Movement_FacePlayer
	waitmovement 0
	delay 16
	msgbox AreaZero_Inside_Text_WallyPlayer, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, AREAZERO_GREAT_TUSK_INSIDE
	setcustomwildbattle  	SPECIES_GREAT_TUSK, 70, ITEM_BOOSTER_ENERGY, MOVE_CLOSE_COMBAT, MOVE_HEADLONG_RUSH, MOVE_ICE_SPINNER, MOVE_BODY_PRESS
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setwildbattleaiflags AI_FLAG_SMART_TRAINER
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AreaZero_Inside_EventScript_GreatTuskGone
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AreaZero_Inside_EventScript_GreatTuskGone
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, AreaZero_Inside_EventScript_GreatTuskGone
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AreaZero_Inside_EventScript_GreatTuskGone
	goto AreaZero_Inside_EventScript_GreatTuskGone

AreaZero_Inside_EventScript_PlayerFaceGreatTusk:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 10
	goto_if_eq AreaZero_Inside_EventScript_PlayerFaceGreatTuskRight
	compare VAR_TEMP_0, 12
	goto_if_eq AreaZero_Inside_EventScript_PlayerFaceGreatTuskLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

AreaZero_Inside_EventScript_PlayerFaceGreatTuskRight:
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

AreaZero_Inside_EventScript_PlayerFaceGreatTuskLeft:
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

AreaZero_Inside_EventScript_GreatTuskGone:
	setflag FLAG_AREA_ZERO_GREAT_TUSK
	removeobject AREAZERO_GREAT_TUSK_INSIDE
	hidefollower
	delay 16
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	call AreaZero_Inside_EventScript_GroupApproachAfterTusk
	waitmovement AREAZERO_STEVEN_INSIDE
	waitmovement AREAZERO_ANDRY_INSIDE
	waitmovement AREAZERO_WALLY_INSIDE
	waitmovement AREAZERO_RIVAL_INSIDE
	waitmovement AREAZERO_EDO_INSIDE
	applymovement AREAZERO_STEVEN_INSIDE, Common_Movement_FacePlayer
	applymovement AREAZERO_ANDRY_INSIDE, Common_Movement_FacePlayer
	applymovement AREAZERO_WALLY_INSIDE, Common_Movement_FaceUp
	applymovement AREAZERO_RIVAL_INSIDE, Common_Movement_FaceUp
	applymovement AREAZERO_EDO_INSIDE, Common_Movement_FaceUp
	waitmovement 0
	msgbox AreaZero_Inside_Text_WhatWasGreatTusk, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Inside_Text_StevenGreatTuskDonphan, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Inside_Text_AndryGreatTuskPrimitive, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Inside_Text_ProceedDeeper, MSGBOX_DEFAULT
	closemessage
	call AreaZero_Inside_EventScript_GroupEnterInside2
	delay 16
	waitse
	playmoncry SPECIES_IRON_JUGULIS, CRY_MODE_NORMAL
	playmoncry SPECIES_FLUTTER_MANE, CRY_MODE_NORMAL
	applymovement AREAZERO_WALLY_INSIDE, Common_Movement_QuestionMark
	applymovement AREAZERO_RIVAL_INSIDE, Common_Movement_QuestionMark
	waitmovement 0
	waitmoncry
	applymovement AREAZERO_WALLY_INSIDE, Common_Movement_FaceDown
	applymovement AREAZERO_RIVAL_INSIDE, Common_Movement_FaceDown
	waitmovement 0
	clearflag FLAG_AREA_ZERO_IRON_JUGULIS
	clearflag FLAG_AREA_ZERO_FLUTTER_MANE
	removeobject AREAZERO_IRON_JUGULIS_INSIDE
	removeobject AREAZERO_FLUTTER_MANE_INSIDE
	setobjectxyperm AREAZERO_FLUTTER_MANE_INSIDE, 10, 17
	setobjectxyperm AREAZERO_IRON_JUGULIS_INSIDE, 10, 17
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, AreaZero_Inside_Movement_CameraPanToEntrance
	waitmovement 0
	addobject AREAZERO_FLUTTER_MANE_INSIDE
	applymovement AREAZERO_FLUTTER_MANE_INSIDE, Common_Movement_WalkUpFast
	waitmovement 0
	applymovement AREAZERO_FLUTTER_MANE_INSIDE, Common_Movement_WalkRightFast
	waitmovement 0
	addobject     AREAZERO_IRON_JUGULIS_INSIDE
	applymovement AREAZERO_IRON_JUGULIS_INSIDE, Common_Movement_WalkUpFast
	waitmovement 0
	applymovement AREAZERO_FLUTTER_MANE_INSIDE, Common_Movement_FaceUp
	waitmovement 0
	msgbox AreaZero_Inside_Text_WallyRivalParadox, MSGBOX_DEFAULT
	applymovement AREAZERO_IRON_JUGULIS_INSIDE, AreaZero_Inside_Movement_IronJugulisRushToWally
	applymovement AREAZERO_FLUTTER_MANE_INSIDE, AreaZero_Inside_Movement_FlutterManeRushToRival
	applymovement LOCALID_CAMERA, AreaZero_Inside_Movement_CameraPanBackToPlayer
	waitmovement 0
	msgbox AreaZero_Inside_Text_WallyRivalHoldThemOff, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_IRON_JUGULIS, CRY_MODE_NORMAL
	playmoncry SPECIES_FLUTTER_MANE, CRY_MODE_NORMAL
	waitmoncry
	special RemoveCameraObject
	setvar VAR_AREAZERO_STATE, 8
	setwarp MAP_AREA_ZERO_INSIDE_2, 7, 47
	special DoContestHallWarp
	waitstate
	end

AreaZero_Inside_EventScript_GroupApproachAfterTusk:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 10
	goto_if_eq AreaZero_Inside_EventScript_GroupApproachAfterTusk_CheckPlayerLeft
	compare VAR_TEMP_0, 12
	goto_if_eq AreaZero_Inside_EventScript_GroupApproachAfterTusk_CheckPlayerRight
	goto AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerBelow

AreaZero_Inside_EventScript_GroupApproachAfterTusk_CheckPlayerLeft:
	compare VAR_TEMP_1, 4
	goto_if_eq AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerLeftFollower
	goto AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerLeft

AreaZero_Inside_EventScript_GroupApproachAfterTusk_CheckPlayerRight:
	compare VAR_TEMP_1, 4
	goto_if_eq AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerRightFollower
	goto AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerRight

AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerLeft:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerLeft
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerLeft
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerLeft
	applymovement AREAZERO_WALLY_INSIDE, AreaZero_Inside_Movement_WallyApproachAfterTusk
	applymovement AREAZERO_RIVAL_INSIDE, AreaZero_Inside_Movement_RivalApproachAfterTusk
	waitmovement 0
	return

AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerLeftFollower:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerLeftFollower
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerLeftFollower
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerLeftFollower
	applymovement AREAZERO_WALLY_INSIDE, AreaZero_Inside_Movement_WallyApproachAfterTusk
	applymovement AREAZERO_RIVAL_INSIDE, AreaZero_Inside_Movement_RivalApproachAfterTusk
	waitmovement 0
	return

AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerRight:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerRight
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerRight
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerRight
	applymovement AREAZERO_WALLY_INSIDE, AreaZero_Inside_Movement_WallyApproachAfterTusk
	applymovement AREAZERO_RIVAL_INSIDE, AreaZero_Inside_Movement_RivalApproachAfterTusk
	waitmovement 0
	return

AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerRightFollower:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerRightFollower
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerRightFollower
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerRightFollower
	applymovement AREAZERO_WALLY_INSIDE, AreaZero_Inside_Movement_WallyApproachAfterTusk
	applymovement AREAZERO_RIVAL_INSIDE, AreaZero_Inside_Movement_RivalApproachAfterTusk
	waitmovement 0
	return

AreaZero_Inside_EventScript_GroupApproachAfterTusk_PlayerBelow:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerBelow
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerBelow
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerBelow
	applymovement AREAZERO_WALLY_INSIDE, AreaZero_Inside_Movement_WallyApproachAfterTusk
	applymovement AREAZERO_RIVAL_INSIDE, AreaZero_Inside_Movement_RivalApproachAfterTusk
	waitmovement 0
	return

AreaZero_Inside_EventScript_GroupEnterInside2:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 10
	goto_if_eq AreaZero_Inside_EventScript_GroupEnterInside2_CheckRightRoute
	compare VAR_TEMP_0, 12
	goto_if_eq AreaZero_Inside_EventScript_GroupEnterInside2_CheckLeftRoute
	goto AreaZero_Inside_EventScript_GroupEnterInside2_SideRoutes

AreaZero_Inside_EventScript_GroupEnterInside2_CheckRightRoute:
	compare VAR_TEMP_1, 4
	goto_if_eq AreaZero_Inside_EventScript_GroupEnterInside2_RightRouteFollower
	goto AreaZero_Inside_EventScript_GroupEnterInside2_RightRoute

AreaZero_Inside_EventScript_GroupEnterInside2_CheckLeftRoute:
	compare VAR_TEMP_1, 4
	goto_if_eq AreaZero_Inside_EventScript_GroupEnterInside2_LeftRouteFollower
	goto AreaZero_Inside_EventScript_GroupEnterInside2_LeftRoute

AreaZero_Inside_EventScript_GroupEnterInside2_LeftRoute:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenEnterInside2Left
	waitmovement AREAZERO_STEVEN_INSIDE
	removeobject AREAZERO_STEVEN_INSIDE
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceEnterInside2Left
	waitmovement AREAZERO_EDO_INSIDE
	removeobject AREAZERO_EDO_INSIDE
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryEnterInside2Left
	waitmovement AREAZERO_ANDRY_INSIDE
	removeobject AREAZERO_ANDRY_INSIDE
	return

AreaZero_Inside_EventScript_GroupEnterInside2_LeftRouteFollower:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenEnterInside2LeftFollower
	waitmovement AREAZERO_STEVEN_INSIDE
	removeobject AREAZERO_STEVEN_INSIDE
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceEnterInside2LeftFollower
	waitmovement AREAZERO_EDO_INSIDE
	removeobject AREAZERO_EDO_INSIDE
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryEnterInside2LeftFollower
	waitmovement AREAZERO_ANDRY_INSIDE
	removeobject AREAZERO_ANDRY_INSIDE
	return

AreaZero_Inside_EventScript_GroupEnterInside2_RightRoute:
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryEnterInside2Right
	waitmovement AREAZERO_ANDRY_INSIDE
	removeobject AREAZERO_ANDRY_INSIDE
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceEnterInside2Right
	waitmovement AREAZERO_EDO_INSIDE
	removeobject AREAZERO_EDO_INSIDE
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenEnterInside2Right
	waitmovement AREAZERO_STEVEN_INSIDE
	removeobject AREAZERO_STEVEN_INSIDE
	return

AreaZero_Inside_EventScript_GroupEnterInside2_RightRouteFollower:
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryEnterInside2RightFollower
	waitmovement AREAZERO_ANDRY_INSIDE
	removeobject AREAZERO_ANDRY_INSIDE
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceEnterInside2RightFollower
	waitmovement AREAZERO_EDO_INSIDE
	removeobject AREAZERO_EDO_INSIDE
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenEnterInside2RightFollower
	waitmovement AREAZERO_STEVEN_INSIDE
	removeobject AREAZERO_STEVEN_INSIDE
	return

AreaZero_Inside_EventScript_GroupEnterInside2_SideRoutes:
	applymovement AREAZERO_STEVEN_INSIDE, AreaZero_Inside_Movement_StevenEnterInside2Below
	waitmovement AREAZERO_STEVEN_INSIDE
	removeobject AREAZERO_STEVEN_INSIDE
	applymovement AREAZERO_ANDRY_INSIDE, AreaZero_Inside_Movement_AndryEnterInside2Below
	waitmovement AREAZERO_ANDRY_INSIDE
	removeobject AREAZERO_ANDRY_INSIDE
	applymovement AREAZERO_EDO_INSIDE, AreaZero_Inside_Movement_SplitfaceEnterInside2Below
	waitmovement AREAZERO_EDO_INSIDE
	removeobject AREAZERO_EDO_INSIDE
	return

AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerLeft:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerLeftFollower:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerRightFollower:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_StevenApproachAfterTusk_PlayerBelow:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerLeft:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerLeftFollower:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerRightFollower:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_AndryApproachAfterTusk_PlayerBelow:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	face_player
	step_end

AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerLeftFollower:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerRight:
	delay_16
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerRightFollower:
	delay_16
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceApproachAfterTusk_PlayerBelow:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_WallyApproachAfterTusk:
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_RivalApproachAfterTusk:
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_StevenEnterInside2Left:
	walk_fast_up
	step_end

AreaZero_Inside_Movement_StevenEnterInside2LeftFollower:
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_StevenEnterInside2Right:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_StevenEnterInside2RightFollower:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_AndryEnterInside2Left:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_AndryEnterInside2LeftFollower:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_AndryEnterInside2Right:
	walk_fast_up
	step_end

AreaZero_Inside_Movement_AndryEnterInside2RightFollower:
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceEnterInside2Left:
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceEnterInside2LeftFollower:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceEnterInside2Right:
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_SplitfaceEnterInside2RightFollower:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_StevenEnterInside2Below:
	walk_fast_up
	walk_fast_right
	walk_fast_up
	step_end

AreaZero_Inside_Movement_AndryEnterInside2Below:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

AreaZero_Inside_Movement_SplitfaceEnterInside2Below:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	step_end

AreaZero_Inside_Movement_CameraPanToEntrance:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AreaZero_Inside_Movement_CameraPanBackToPlayer:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_ParadoxApproach:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_IronJugulisRushToWally:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Movement_FlutterManeRushToRival:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Inside_Text_StevenCrystalsRooted:
	.string "STEVEN: This may be the\n"
	.string "strongest power source\l"
	.string "HOENN has ever seen. $"

AreaZero_Inside_Text_AndryCaveFeelsAlive:
	.string "ANDRY: The cave is vibrating.\p"
	.string "If those cries belong to POKéMON,\n"
	.string "something is drawing them here. $"

AreaZero_Inside_Text_WallyCrystalPulse:
	.string "WALLY: Each crystal pulses\n"
	.string "differently.\p"
	.string "It's like each one holds\n"
	.string "a different color inside. $"

AreaZero_Inside_Text_RivalDadNotebook:
	.string "{RIVAL}: My dad would lose\n"
	.string "his mind over this place. $"

AreaZero_Inside_Text_SplitfaceGlowRocks:
	.string "SPLITFACE: There are bigger\n"
	.string "crystals here.\p"
	.string "The deeper we go, the more\n"
	.string "concentrated they become.\p"
	.string "Something big has to be\n"
	.string "waiting ahead. $"

AreaZero_Inside_Text_SmallCrystalPulse:
	.string "A small crystal pulses with\n"
	.string "a sharp, bright light. $"

AreaZero_Inside_Text_WallyPlayer:
	.string "WALLY: {PLAYER}! $"

AreaZero_Inside_Text_WhatWasGreatTusk:
	.string "SPLITFACE: That wasn't\n"
	.string "a DONPHAN, was it?! $"

AreaZero_Inside_Text_StevenGreatTuskDonphan:
	.string "STEVEN: Its cry and shape\n"
	.string "resembled DONPHAN's.\p"
	.string "But it was far more primitive. $"

AreaZero_Inside_Text_AndryGreatTuskPrimitive:
	.string "ANDRY: Like a DONPHAN\n"
	.string "from another age.\p"
	.string "This energy may be connected\n"
	.string "to what it has become. $"

AreaZero_Inside_Text_ProceedDeeper:
	.string "STEVEN: The source has to be\n"
	.string "deeper inside. Let's move. $"

AreaZero_Inside_Text_WallyRivalParadox:
	.string "WALLY: Wait!\n"
	.string "Something's behind us!\p"
	.string "{RIVAL}: What are those\n"
	.string "POKéMON? $"

AreaZero_Inside_Text_WallyRivalHoldThemOff:
	.string "WALLY: {PLAYER}, go on!\n"
	.string "We'll handle them!\p"
	.string "{RIVAL}: Keep moving!\n"
	.string "We'll catch up! $"
