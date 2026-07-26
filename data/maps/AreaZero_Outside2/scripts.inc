.set AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, 16
.set AREA_ZERO_OUTSIDE2_FORMATION_VALUE, 17
.set AREA_ZERO_OUTSIDE2_INTRO_DONE_VALUE, 18

AreaZero_Outside2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AreaZero_Outside2_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AreaZero_Outside2_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AreaZero_Outside2_OnFrame
	.byte 0

AreaZero_Outside2_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	call_if_eq VAR_AREAZERO_STATE, 0xFF, AreaZero_Outside2_OnTransition_RestoreWildMons
	call_if_ne VAR_AREAZERO_STATE, 0xFF, AreaZero_Outside2_OnTransition_HideWildMons
	call_if_eq VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, AreaZero_Outside2_OnTransition_SetArrivalState
	call_if_ge VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_FORMATION_VALUE, AreaZero_Outside2_OnTransition_SetPostIntroState
	end

AreaZero_Outside2_OnTransition_RestoreWildMons:
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	clearflag FLAG_TEMP_6
	clearflag FLAG_TEMP_7
	clearflag FLAG_TEMP_8
	setobjectxyperm AREAZERO2_WILD_OW_MON_1, 11, 32
	setobjectxyperm AREAZERO2_WILD_OW_MON_2, 32, 28
	setobjectxyperm AREAZERO2_WILD_OW_MON_3, 32, 19
	setobjectxyperm AREAZERO2_WILD_OW_MON_4, 1, 32
	setobjectxyperm AREAZERO2_WILD_OW_MON_5, 3, 19
	setobjectxyperm AREAZERO2_WILD_OW_MON_6, 19, 14
	setobjectxyperm AREAZERO2_WILD_OW_MON_7, 30, 8
	setobjectxyperm AREAZERO2_WILD_OW_MON_8, 2, 8
	return

AreaZero_Outside2_OnTransition_HideWildMons:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	setobjectxyperm AREAZERO2_WILD_OW_MON_1, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_2, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_3, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_4, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_5, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_6, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_7, 0, 0
	setobjectxyperm AREAZERO2_WILD_OW_MON_8, 0, 0
	return

AreaZero_Outside2_OnTransition_SetArrivalState:
	setobjectmovementtype AREAZERO2_STEVEN, MOVEMENT_TYPE_FACE_DOWN
	removeobject AREAZERO2_EDO
	removeobject AREAZERO2_RIVAL
	removeobject AREAZERO2_WALLY
	removeobject AREAZERO2_ANDRY
	setobjectxyperm AREAZERO2_EDO, 0, 0
	setobjectxyperm AREAZERO2_RIVAL, 0, 0
	setobjectxyperm AREAZERO2_WALLY, 0, 0
	setobjectxyperm AREAZERO2_ANDRY, 0, 0
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_NONE
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_NONE
	return

AreaZero_Outside2_OnTransition_SetPostIntroState:
	clearflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	setobjectxyperm AREAZERO2_STEVEN, 18, 16
	setobjectxyperm AREAZERO2_ANDRY, 15, 16
	setobjectxyperm AREAZERO2_EDO, 16, 16
	setobjectxyperm AREAZERO2_WALLY, 15, 17
	setobjectxyperm AREAZERO2_RIVAL, 16, 17
	setobjectmovementtype AREAZERO2_STEVEN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

AreaZero_Outside2_OnWarp:
	map_script_2 VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, AreaZero_Outside2_EventScript_PlayerFaceUp
	.2byte 0

AreaZero_Outside2_EventScript_PlayerFaceUp::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

AreaZero_Outside2_OnFrame:
	map_script_2 VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, AreaZero_Outside2_EventScript_Intro
	.2byte 0

AreaZero_Outside2_EventScript_Steven::
	lock
	faceplayer
	msgbox AreaZero_Outside2_Text_StevenTalk, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside2_EventScript_Andry::
	lock
	faceplayer
	msgbox AreaZero_Outside2_Text_AndryTalk, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside2_EventScript_Splitface::
	lock
	faceplayer
	msgbox AreaZero_Outside2_Text_SplitfaceTalk, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside2_EventScript_Wally::
	lock
	faceplayer
	msgbox AreaZero_Outside2_Text_WallyTalk, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside2_EventScript_Rival::
	lock
	faceplayer
	msgbox AreaZero_Outside2_Text_RivalTalk, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

AreaZero_Outside2_EventScript_Intro::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenGladYouMadeIt, MSGBOX_DEFAULT
	closemessage
	applymovement AREAZERO2_STEVEN, AreaZero_Outside2_Movement_StevenLeadForward
	delay 16
	applymovement LOCALID_PLAYER, AreaZero_Outside2_Movement_PlayerFollowSteven
	waitmovement 0
	applymovement AREAZERO2_STEVEN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenWaitOthers, MSGBOX_DEFAULT
	applymovement AREAZERO2_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenPastOrFuture, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 8, MULTI_AREAZERO_PAST_FUTURE, TRUE
	compare VAR_RESULT, 0
	goto_if_eq AreaZero_Outside2_EventScript_ChoicePast
	goto AreaZero_Outside2_EventScript_ChoiceFuture

AreaZero_Outside2_EventScript_ChoicePast:
	setvar VAR_TEMP_0, 0
	msgbox AreaZero_Outside2_Text_PlayerChoosesPast, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_StevenRepliesPast, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_GroupReunion

AreaZero_Outside2_EventScript_ChoiceFuture:
	setvar VAR_TEMP_0, 1
	msgbox AreaZero_Outside2_Text_PlayerChoosesFuture, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_StevenRepliesFuture, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_GroupReunion

AreaZero_Outside2_EventScript_GroupReunion:
	msgbox AreaZero_Outside2_Text_StevenThanks, MSGBOX_DEFAULT
	@ SPLITFACE bursts out of the cave first, peeling off to the left
	setobjectxyperm AREAZERO2_EDO, 16, 39
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_FACE_UP
	addobject AREAZERO2_EDO
	applymovement AREAZERO2_EDO, AreaZero_Outside2_Movement_SplitfaceApproach
	waitmovement 0
	applymovement AREAZERO2_STEVEN, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox AreaZero_Outside2_Text_SplitfaceMadeIt, MSGBOX_DEFAULT
	closemessage

	@ RIVAL next, peeling off to the right
	setobjectxyperm AREAZERO2_RIVAL, 16, 39
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_FACE_UP
	addobject AREAZERO2_RIVAL
	applymovement AREAZERO2_RIVAL, AreaZero_Outside2_Movement_RivalApproach
	waitmovement 0
	applymovement AREAZERO2_EDO, Common_Movement_FaceRight
	applymovement AREAZERO2_STEVEN, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox AreaZero_Outside2_Text_RivalMadeIt, MSGBOX_DEFAULT
	closemessage

	@ WALLY next, stays back closer to the cave mouth
	setobjectxyperm AREAZERO2_WALLY, 16, 39
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	addobject AREAZERO2_WALLY
	applymovement AREAZERO2_WALLY, AreaZero_Outside2_Movement_WallyApproach
	waitmovement 0
	applymovement AREAZERO2_EDO, Common_Movement_FaceLeft
	msgbox AreaZero_Outside2_Text_WallyMadeIt, MSGBOX_DEFAULT
	closemessage

	@ ANDRY last, walks straight up to STEVEN
	setobjectxyperm AREAZERO2_ANDRY, 16, 39
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_FACE_UP
	addobject AREAZERO2_ANDRY
	applymovement AREAZERO2_ANDRY, AreaZero_Outside2_Movement_AndryApproachSteven
	waitmovement 0
	applymovement AREAZERO2_EDO, Common_Movement_FaceRight
	applymovement AREAZERO2_STEVEN, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement AREAZERO2_WALLY, Common_Movement_FaceRight
	applymovement AREAZERO2_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	msgbox AreaZero_Outside2_Text_AndryMadeIt, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_AndrySensesSomething, MSGBOX_DEFAULT
	closemessage

	@ MIRAIDON and KORAIDON cry out at once, the ground trembles
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 6
	special ShakeCamera
	playmoncry SPECIES_KORAIDON, CRY_MODE_NORMAL
	playmoncry SPECIES_MIRAIDON, CRY_MODE_NORMAL
	waitmoncry
	applymovement AREAZERO2_EDO, Common_Movement_ExclamationMark
	applymovement AREAZERO2_STEVEN, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement AREAZERO2_WALLY, Common_Movement_ExclamationMark
	applymovement AREAZERO2_RIVAL, Common_Movement_ExclamationMark
	applymovement AREAZERO2_ANDRY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement AREAZERO2_EDO, Common_Movement_FaceUp
	applymovement AREAZERO2_STEVEN, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement AREAZERO2_WALLY, Common_Movement_FaceUp
	applymovement AREAZERO2_RIVAL, Common_Movement_FaceUp
	applymovement AREAZERO2_ANDRY, Common_Movement_FaceUp
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenSomethingIsThere, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_AndryGoCheckFast, MSGBOX_DEFAULT
	closemessage

	@ SPLITFACE, RIVAL, WALLY and ANDRY all rush off ahead, spreading out to avoid each other and the player/STEVEN
	applymovement AREAZERO2_WALLY, AreaZero_Outside2_Movement_WallyRushOff
	applymovement AREAZERO2_EDO, AreaZero_Outside2_Movement_SplitfaceRushOff
	applymovement AREAZERO2_RIVAL, AreaZero_Outside2_Movement_RivalRushOff
	applymovement AREAZERO2_ANDRY, AreaZero_Outside2_Movement_AndryRushOff
	waitmovement 0
	removeobject AREAZERO2_EDO
	removeobject AREAZERO2_ANDRY
	removeobject AREAZERO2_WALLY
	removeobject AREAZERO2_RIVAL

	@ They regroup ahead in a square: ANDRY and SPLITFACE up front, WALLY and RIVAL behind them
	setobjectxyperm AREAZERO2_ANDRY, 15, 16
	setobjectxyperm AREAZERO2_EDO, 16, 16
	setobjectxyperm AREAZERO2_WALLY, 15, 17
	setobjectxyperm AREAZERO2_RIVAL, 16, 17
	addobject AREAZERO2_ANDRY
	addobject AREAZERO2_EDO
	addobject AREAZERO2_WALLY
	addobject AREAZERO2_RIVAL
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_FACE_UP

	@ STEVEN turns to the player, then rushes ahead alone - no more escorting from here
	applymovement AREAZERO2_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenGoAheadFast, MSGBOX_DEFAULT
	closemessage
	applymovement AREAZERO2_STEVEN, AreaZero_Outside2_Movement_StevenRushOff
	waitmovement 0
	removeobject AREAZERO2_STEVEN
	setobjectxyperm AREAZERO2_STEVEN, 18, 16
	addobject AREAZERO2_STEVEN
	setobjectmovementtype AREAZERO2_STEVEN, MOVEMENT_TYPE_FACE_UP

	@ The scene changes: every paradox mon ahead is now visible
	clearflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	addobject AREAZERO2_FLUTTER_MANE
	addobject AREAZERO2_GREAT_TUSK
	addobject AREAZERO2_SLITHER_WING
	addobject AREAZERO2_BRUTE_BONNET
	delay 4
	addobject AREAZERO2_ROARING_MOON
	addobject AREAZERO2_SCREAM_TAIL
	addobject AREAZERO2_IRON_JUGULIS
	addobject AREAZERO2_IRON_BUNDLE
	delay 4
	addobject AREAZERO2_IRON_VALIANT
	addobject AREAZERO2_IRON_HANDS
	addobject AREAZERO2_IRON_MOTH
	addobject AREAZERO2_IRON_THORNS
	delay 4
	addobject AREAZERO2_KORAIDON
	addobject AREAZERO2_MIRAIDON

	@ The player gets control back here and walks up on their own - no more forced movement
	setvar VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_FORMATION_VALUE
	releaseall
	end

@ Fires from a coord_event once the player walks into the gap between ANDRY and STEVEN
AreaZero_Outside2_EventScript_LegendaryApproach::
	lockall
	turnobject LOCALID_PLAYER, DIR_NORTH
	compare VAR_TEMP_0, 0
	goto_if_eq AreaZero_Outside2_EventScript_PastLegendaryApproach
	goto AreaZero_Outside2_EventScript_FutureLegendaryApproach

AreaZero_Outside2_EventScript_PastLegendaryApproach:
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonApproachPlayer
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonApproachSteven
	waitmovement 0
	goto AreaZero_Outside2_EventScript_GroupReunionEnd

AreaZero_Outside2_EventScript_FutureLegendaryApproach:
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonApproachPlayer
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonApproachSteven
	waitmovement 0
	goto AreaZero_Outside2_EventScript_GroupReunionEnd

AreaZero_Outside2_EventScript_GroupReunionEnd:
	setvar VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_INTRO_DONE_VALUE
	releaseall
	end

AreaZero_Outside2_Movement_StevenLeadForward::
	walk_up
	walk_up
	face_down
	step_end

AreaZero_Outside2_Movement_PlayerFollowSteven::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	face_right
	step_end

AreaZero_Outside2_Movement_SplitfaceApproach::
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

AreaZero_Outside2_Movement_RivalApproach::
	walk_up
	walk_up
	walk_up
	step_end

AreaZero_Outside2_Movement_WallyApproach::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

AreaZero_Outside2_Movement_AndryApproachSteven::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_left
	step_end

AreaZero_Outside2_Movement_WallyRushOff::
	walk_left
	walk_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Outside2_Movement_SplitfaceRushOff::
	walk_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Outside2_Movement_RivalRushOff::
	walk_right
	walk_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Outside2_Movement_AndryRushOff::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Outside2_Movement_StevenRushOff::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AreaZero_Outside2_Movement_KoraidonApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

AreaZero_Outside2_Movement_KoraidonApproachSteven::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	face_down
	step_end

AreaZero_Outside2_Movement_MiraidonApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_down
	step_end

AreaZero_Outside2_Movement_MiraidonApproachSteven::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end

AreaZero_Outside2_Text_StevenGladYouMadeIt:
	.string "STEVEN: Here we are.\p"
	.string "Let's put some distance\n"
	.string "between us and the cave first. $"

AreaZero_Outside2_Text_StevenWaitOthers:
	.string "STEVEN: Let's wait for the others here... $"

AreaZero_Outside2_Text_StevenPastOrFuture:
	.string "STEVEN: Oh, almost forgot... \p"
	.string "Since this place feels tied to time \n"
	.string "itself... it made me reflect, \l"
	.string "and wanted to ask you: \p"
	.string "Would you rather face the PAST, \n"
	.string "or prepare yourself to face the FUTURE? $"

AreaZero_Outside2_Text_PlayerChoosesPast:
	.string "{PLAYER} decides to face\n"
	.string "what the past has left behind. $"

AreaZero_Outside2_Text_StevenRepliesPast:
	.string "STEVEN: I see...\p"
	.string "Perhaps you have something \n"
	.string "left unresolved. $"

AreaZero_Outside2_Text_StevenThanks:
	.string "{PLAYER}, thanks for your answer. $"

AreaZero_Outside2_Text_PlayerChoosesFuture:
	.string "{PLAYER} decides to prepare\n"
	.string "for whatever the future holds. $"

AreaZero_Outside2_Text_StevenRepliesFuture:
	.string "STEVEN: The future...\p"
	.string "It is wise to prepare yourself\nfor what lies ahead. $"

AreaZero_Outside2_Text_SplitfaceMadeIt:
	.string "SPLITFACE: Finally, we're out...\p"
	.string "Voglio andare a casa, sigh. $"

AreaZero_Outside2_Text_RivalMadeIt:
	.string "{RIVAL}: We made it out.\p"
	.string "I won't lie, that place\n"
	.string "tested us more than I expected. $"

AreaZero_Outside2_Text_WallyMadeIt:
	.string "WALLY: Phew... I'm just glad\n"
	.string "we're all still standing.\p"
	.string "That was a close call back\n"
	.string "there. $"

AreaZero_Outside2_Text_AndryMadeIt:
	.string "ANDRY: STEVEN, {PLAYER}...\p"
	.string "We're all here. $"

AreaZero_Outside2_Text_AndrySensesSomething:
	.string "ANDRY: STEVEN, what did you find- $"

AreaZero_Outside2_Text_StevenSomethingIsThere:
	.string "STEVEN: That cry...!\p"
	.string "Something is out there. $"

AreaZero_Outside2_Text_AndryGoCheckFast:
	.string "ANDRY: We need to go check, now! $"

AreaZero_Outside2_Text_StevenGoAheadFast:
	.string "STEVEN: {PLAYER}, we need to\n"
	.string "catch up to them, fast.\p"
	.string "I'll go on ahead! $"

AreaZero_Outside2_Text_StevenTalk:
	.string "STEVEN: Stay sharp.\p"
	.string "Whatever's out there, we're\n"
	.string "not facing it alone. $"

AreaZero_Outside2_Text_AndryTalk:
	.string "ANDRY: I can still feel it...\p"
	.string "Whatever it is, it's close. $"

AreaZero_Outside2_Text_SplitfaceTalk:
	.string "SPLITFACE: My legs still\n"
	.string "hurt from all that running.\p"
	.string "Worth it, though! $"

AreaZero_Outside2_Text_WallyTalk:
	.string "WALLY: The air out here is\n"
	.string "so much better than in\l"
	.string "that cave. $"

AreaZero_Outside2_Text_RivalTalk:
	.string "{RIVAL}: Let's stay focused.\n"
	.string "We're close to something\l"
	.string "big. $"
