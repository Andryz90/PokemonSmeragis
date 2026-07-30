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
	setflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
	setflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	call_if_eq VAR_AREAZERO_STATE, 0xFF, AreaZero_Outside2_OnTransition_RestoreWildMons
	call_if_ne VAR_AREAZERO_STATE, 0xFF, AreaZero_Outside2_OnTransition_HideWildMons
	call_if_eq VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, AreaZero_Outside2_OnTransition_SetArrivalState
	compare VAR_AREAZERO_WHITEOUT_RESCUE, AREA_ZERO_WHITEOUT_RESCUE_OUTSIDE2
	goto_if_eq AreaZero_Outside2_OnTransition_BeginWhiteoutRecovery
	compare VAR_AREAZERO_WHITEOUT_RESCUE, AREA_ZERO_WHITEOUT_RESCUE_OUTSIDE2_PREP
	goto_if_eq AreaZero_Outside2_OnTransition_ResumeWhiteoutRecovery
	compare VAR_AREAZERO_STATE, 0xFF
	goto_if_eq AreaZero_Outside2_OnTransition_SetEventCompleteState
	call_if_ge VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_FORMATION_VALUE, AreaZero_Outside2_OnTransition_SetPostIntroState
	end


@ This runs before InitObjectEventsLocal.  Configure every template here so the
@ Latis are part of the initial map load instead of being created after the player.
AreaZero_Outside2_OnTransition_BeginWhiteoutRecovery:
	call AreaZero_Outside2_EventScript_SetupBattlefieldAfterWhiteOut
	clearflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
	setobjectxyperm AREAZERO2_LATIOS, 22, 40
	setobjectxyperm AREAZERO2_LATIAS, 24, 38
	setobjectmovementtype AREAZERO2_LATIOS, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_LATIAS, MOVEMENT_TYPE_FACE_UP
	end

@ If the map is reloaded after the healing, keep the prepared battle scene and
@ do not replay the rescue or recreate any object on screen.
AreaZero_Outside2_OnTransition_ResumeWhiteoutRecovery:
	call AreaZero_Outside2_EventScript_SetupBattlefieldAfterWhiteOut
	setflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
	end

AreaZero_Outside2_OnTransition_SetEventCompleteState:
	setflag FLAG_AREA_ZERO_OUTSIDE2_OBJ
	setflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	setflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
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
	removeobject AREAZERO2_WILD_OW_MON_1
	removeobject AREAZERO2_WILD_OW_MON_2
	removeobject AREAZERO2_WILD_OW_MON_3
	removeobject AREAZERO2_WILD_OW_MON_4
	removeobject AREAZERO2_WILD_OW_MON_5
	removeobject AREAZERO2_WILD_OW_MON_6
	removeobject AREAZERO2_WILD_OW_MON_7
	removeobject AREAZERO2_WILD_OW_MON_8
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
	clearflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
	setobjectxyperm AREAZERO2_LATIOS, 22, 40
	setobjectxyperm AREAZERO2_LATIAS, 24, 40
	setobjectmovementtype AREAZERO2_LATIOS, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype AREAZERO2_LATIAS, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm AREAZERO2_STEVEN, 22, 13
	setobjectxyperm AREAZERO2_ANDRY, 26, 13
	setobjectxyperm AREAZERO2_EDO, 28, 13
	setobjectxyperm AREAZERO2_WALLY, 22, 15
	setobjectxyperm AREAZERO2_RIVAL, 26, 15
	setobjectmovementtype AREAZERO2_STEVEN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

AreaZero_Outside2_EventScript_SpawnLatisAtCaveEntrance:
	clearflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
	setobjectxyperm AREAZERO2_LATIOS, 22, 40
	setobjectxyperm AREAZERO2_LATIAS, 24, 40
	setobjectmovementtype AREAZERO2_LATIOS, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_LATIAS, MOVEMENT_TYPE_FACE_UP
	addobject AREAZERO2_LATIOS
	addobject AREAZERO2_LATIAS
	return

AreaZero_Outside2_OnWarp:
	map_script_2 VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, AreaZero_Outside2_EventScript_PlayerFaceUp
	.2byte 0

AreaZero_Outside2_EventScript_PlayerFaceUp::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

AreaZero_Outside2_OnFrame:
	map_script_2 VAR_AREAZERO_WHITEOUT_RESCUE, AREA_ZERO_WHITEOUT_RESCUE_OUTSIDE2, AreaZero_Outside2_EventScript_LatiasWhiteOutRescue
	map_script_2 VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_ARRIVAL_VALUE, AreaZero_Outside2_EventScript_Intro
	.2byte 0

AreaZero_Outside2_EventScript_LatiasWhiteOutRescue::
	lockall
	@ LATIAS was loaded beside the player with the map. Heal, then return her to
	@ the entrance without any late object creation or palette mismatch.
	turnobject AREAZERO2_LATIAS, DIR_WEST
	turnobject LOCALID_PLAYER, DIR_EAST
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	call AreaZero_Outside2_EventScript_HealPartyWithoutPaletteOverwrite
	applymovement AREAZERO2_LATIAS, Common_Movement_WalkDown2
	waitmovement 0
	turnobject AREAZERO2_LATIAS, DIR_NORTH
	applymovement LOCALID_PLAYER, AreaZero_Outside2_PlayerComeBackFromHealing
	waitmovement 0
	setvar VAR_AREAZERO_WHITEOUT_RESCUE, AREA_ZERO_WHITEOUT_RESCUE_OUTSIDE2_PREP
	releaseall
	end

@ Do not use Common_EventScript_OutOfCenterPartyHeal here. Its normal fade-out
@ copies the already light-blended palette into the source buffer; the fade-in
@ then blends it a second time. Route 111 fixes that same issue with the
@ hardware/swap-buffer fade, which keeps both palette buffers intact.
AreaZero_Outside2_EventScript_HealPartyWithoutPaletteOverwrite:
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreenswapbuffers FADE_FROM_BLACK
	return

@ The tile north of the preparation spot starts a fresh attempt with the current party.
AreaZero_Outside2_EventScript_ResumeBattleAfterWhiteOut::
	lockall
	setvar VAR_AREAZERO_WHITEOUT_RESCUE, AREA_ZERO_WHITEOUT_RESCUE_NONE
	setflag FLAG_AREA_ZERO_OUTSIDE2_LATIS
	removeobject AREAZERO2_LATIAS
	removeobject AREAZERO2_LATIOS
	@ The formation was prepared during the rescue and has already entered view.
	applymovement LOCALID_PLAYER, AreaZero_Outside2_Movement_PlayerReturnToBattlePosition
	waitmovement 0
	compare VAR_TEMP_0, 0
	goto_if_eq AreaZero_Outside2_EventScript_PastLegendaryApproach
	goto AreaZero_Outside2_EventScript_FutureLegendaryApproach

AreaZero_Outside2_EventScript_SetupBattlefieldAfterWhiteOut:
	@ Restore the exact battle formation only when the player chooses to try again.
	clearflag FLAG_AREA_ZERO_OUTSIDE2_OBJ
	clearflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	setobjectxyperm AREAZERO2_STEVEN, 22, 13
	setobjectxyperm AREAZERO2_ANDRY, 26, 13
	setobjectxyperm AREAZERO2_EDO, 28, 13
	setobjectxyperm AREAZERO2_WALLY, 22, 15
	setobjectxyperm AREAZERO2_RIVAL, 26, 15
	setobjectmovementtype AREAZERO2_STEVEN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm AREAZERO2_KORAIDON, 25, 10
	setobjectxyperm AREAZERO2_MIRAIDON, 22, 10
	setobjectxyperm AREAZERO2_FLUTTER_MANE, 28, 9
	setobjectxyperm AREAZERO2_GREAT_TUSK, 27, 10
	setobjectxyperm AREAZERO2_SLITHER_WING, 28, 11
	setobjectxyperm AREAZERO2_IRON_TREADS, 20, 10
	setobjectxyperm AREAZERO2_IRON_BUNDLE, 19, 9
	setobjectxyperm AREAZERO2_IRON_MOTH, 19, 11
	setobjectmovementtype AREAZERO2_KORAIDON, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype AREAZERO2_MIRAIDON, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype AREAZERO2_FLUTTER_MANE, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype AREAZERO2_GREAT_TUSK, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype AREAZERO2_SLITHER_WING, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype AREAZERO2_IRON_TREADS, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype AREAZERO2_IRON_BUNDLE, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype AREAZERO2_IRON_MOTH, MOVEMENT_TYPE_FACE_RIGHT
	return

AreaZero_Outside2_EventScript_SpawnBattlefieldAfterWhiteOut:
	addobject AREAZERO2_STEVEN
	addobject AREAZERO2_ANDRY
	addobject AREAZERO2_EDO
	addobject AREAZERO2_WALLY
	addobject AREAZERO2_RIVAL
	addobject AREAZERO2_KORAIDON
	addobject AREAZERO2_MIRAIDON
	addobject AREAZERO2_FLUTTER_MANE
	addobject AREAZERO2_GREAT_TUSK
	addobject AREAZERO2_SLITHER_WING
	addobject AREAZERO2_IRON_TREADS
	addobject AREAZERO2_IRON_BUNDLE
	addobject AREAZERO2_IRON_MOTH
	return

AreaZero_Outside2_EventScript_WhiteoutBoundaryDown::
	lockall
	@ Let the player enter the preparation spot from the cave, but not leave it again.
	goto_if_eq VAR_FACING, DIR_NORTH, AreaZero_Outside2_EventScript_WhiteoutBoundaryEnd
	msgbox AreaZero_Outside2_Text_MustContinueBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
AreaZero_Outside2_EventScript_WhiteoutBoundaryEnd:
	releaseall
	end

AreaZero_Outside2_EventScript_WhiteoutBoundaryLeft::
	lockall
	msgbox AreaZero_Outside2_Text_MustContinueBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	releaseall
	end

AreaZero_Outside2_EventScript_WhiteoutBoundaryRight::
	lockall
	msgbox AreaZero_Outside2_Text_MustContinueBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

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
	msgbox AreaZero_Outside2_Text_StevenThanks, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_GroupReunion

AreaZero_Outside2_EventScript_ChoiceFuture:
	setvar VAR_TEMP_0, 1
	msgbox AreaZero_Outside2_Text_PlayerChoosesFuture, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_StevenRepliesFuture, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_StevenThanks, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_GroupReunion

AreaZero_Outside2_EventScript_GroupReunion:
	@ The arrival state removed these NPCs. They share this visibility flag, so it
	@ must be cleared before adding any of them back to the field.
	clearflag FLAG_AREA_ZERO_OUTSIDE2_OBJ
	@ SPLITFACE bursts out of the cave first, peeling off to the left
	setobjectxyperm AREAZERO2_EDO, 23, 39
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
	setobjectxyperm AREAZERO2_RIVAL, 23, 39
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
	setobjectxyperm AREAZERO2_WALLY, 23, 39
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	addobject AREAZERO2_WALLY
	applymovement AREAZERO2_WALLY, AreaZero_Outside2_Movement_WallyApproach
	waitmovement 0
	applymovement AREAZERO2_EDO, Common_Movement_FaceLeft
	msgbox AreaZero_Outside2_Text_WallyMadeIt, MSGBOX_DEFAULT
	closemessage

	@ ANDRY last, walks straight up to STEVEN
	setobjectxyperm AREAZERO2_ANDRY, 23, 39
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

	@ Formation facing north, centered on the player's space at (24, 13).
	@ Row 13: STEVEN, player space, ANDRY, SPLITFACE. Row 15: WALLY behind STEVEN, RIVAL behind ANDRY.
	setobjectxyperm AREAZERO2_ANDRY, 26, 13
	setobjectxyperm AREAZERO2_EDO, 28, 13
	setobjectxyperm AREAZERO2_WALLY, 22, 15
	setobjectxyperm AREAZERO2_RIVAL, 26, 15
	clearflag FLAG_AREA_ZERO_OUTSIDE2_OBJ
	addobject AREAZERO2_ANDRY
	addobject AREAZERO2_EDO
	addobject AREAZERO2_WALLY
	addobject AREAZERO2_RIVAL
	setobjectmovementtype AREAZERO2_ANDRY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_EDO, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype AREAZERO2_RIVAL, MOVEMENT_TYPE_FACE_UP

	@ Spawn the Paradox Pokémon before the escort, so they are already present when
	@ the camera reaches the clearing instead of popping in at the trigger.
	clearflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	addobject AREAZERO2_KORAIDON
	addobject AREAZERO2_MIRAIDON
	addobject AREAZERO2_FLUTTER_MANE
	addobject AREAZERO2_GREAT_TUSK
	addobject AREAZERO2_SLITHER_WING
	addobject AREAZERO2_IRON_TREADS
	addobject AREAZERO2_IRON_BUNDLE
	addobject AREAZERO2_IRON_MOTH
	delay 30

	@ STEVEN tells the player to move, making sure they are facing one another first.
	applymovement AREAZERO2_STEVEN, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenGoAheadFast, MSGBOX_DEFAULT
	closemessage

	@ The player follows directly behind STEVEN, then turns into the trigger tile.
	@ The three calls use brief instant field messages and require no player input.
	applymovement AREAZERO2_STEVEN, AreaZero_Outside2_Movement_StevenEscortToFormation
	applymovement LOCALID_PLAYER, AreaZero_Outside2_Movement_PlayerRunWithSteven
	messageinstant AreaZero_Outside2_Text_WallyRunWithSteven
	delay 50
	messageinstant AreaZero_Outside2_Text_SplitfaceRunWithSteven
	delay 50
	closemessage
	waitmovement 0

	@ The player is now standing on the coord-event tile. Run that same scene directly;
	@ its ending advances the state to 18, disabling this one-shot trigger.
	call AreaZero_Outside2_EventScript_SpawnLatisAtCaveEntrance
	setvar VAR_AREAZERO_STATE, AREA_ZERO_OUTSIDE2_FORMATION_VALUE
	goto AreaZero_Outside2_EventScript_LegendaryApproach

@ Fires from a coord_event once the player walks into the gap between ANDRY and STEVEN
AreaZero_Outside2_EventScript_LegendaryApproach::
	lockall
	turnobject LOCALID_PLAYER, DIR_NORTH
	msgbox AreaZero_Outside2_Text_AndryUnderstandsTheTurmoil, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_AndryParadoxEnergy, MSGBOX_DEFAULT
	closemessage
	@ The two unknown Pokémon lunge at each other, making the ground shake.
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonClashMiraidon
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonClashKoraidon
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 6
	special ShakeCamera
	playmoncry SPECIES_KORAIDON, CRY_MODE_NORMAL
	playmoncry SPECIES_MIRAIDON, CRY_MODE_NORMAL
	waitmoncry
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonRecoilFromClash
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonRecoilFromClash
	waitmovement 0
	msgbox AreaZero_Outside2_Text_AndryStopTheParadoxMons, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_0, 0
	goto_if_eq AreaZero_Outside2_EventScript_PastLegendaryApproach
	goto AreaZero_Outside2_EventScript_FutureLegendaryApproach

AreaZero_Outside2_EventScript_PastLegendaryApproach:
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonApproachPlayer
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonApproachSteven
	call AreaZero_Outside2_EventScript_FaceParadoxMonsDown
	waitmovement 0
	goto AreaZero_Outside2_EventScript_PastBattleLeadIn

AreaZero_Outside2_EventScript_FutureLegendaryApproach:
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonApproachPlayer
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonApproachAndrySplitface
	call AreaZero_Outside2_EventScript_FaceParadoxMonsDown
	waitmovement 0
	goto AreaZero_Outside2_EventScript_FutureBattleLeadIn

AreaZero_Outside2_EventScript_FaceParadoxMonsDown:
	applymovement AREAZERO2_FLUTTER_MANE, Common_Movement_FaceDown
	applymovement AREAZERO2_GREAT_TUSK, Common_Movement_FaceDown
	applymovement AREAZERO2_SLITHER_WING, Common_Movement_FaceDown
	applymovement AREAZERO2_IRON_TREADS, Common_Movement_FaceDown
	applymovement AREAZERO2_IRON_BUNDLE, Common_Movement_FaceDown
	applymovement AREAZERO2_IRON_MOTH, Common_Movement_FaceDown
	return

AreaZero_Outside2_EventScript_PastBattleLeadIn:
	@ Explicitly set both leads to face their opponents after they finish moving.
	applymovement AREAZERO2_KORAIDON, Common_Movement_FaceDown
	applymovement AREAZERO2_MIRAIDON, Common_Movement_FaceDown
	waitmovement 0
	msgbox AreaZero_Outside2_Text_StevenParadoxBattleLeadIn, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_RivalParadoxBattleLeadIn, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_ParadoxBattleLeadIn_Common

AreaZero_Outside2_EventScript_FutureBattleLeadIn:
	@ Explicitly set both leads to face their opponents after they finish moving.
	applymovement AREAZERO2_KORAIDON, Common_Movement_FaceDown
	applymovement AREAZERO2_MIRAIDON, Common_Movement_FaceDown
	waitmovement 0
	msgbox AreaZero_Outside2_Text_AndryParadoxBattleLeadIn, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_SplitfaceParadoxBattleLeadIn, MSGBOX_DEFAULT
	closemessage
	msgbox AreaZero_Outside2_Text_WallyParadoxBattleLeadIn, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_ParadoxBattleLeadIn_Common

AreaZero_Outside2_EventScript_ParadoxBattleLeadIn_Common:
	call AreaZero_Outside2_EventScript_ChooseParadoxBossParty
	compare VAR_TEMP_0, 0
	goto_if_eq AreaZero_Outside2_EventScript_StartPastParadoxBossBattle
	goto AreaZero_Outside2_EventScript_StartFutureParadoxBossBattle

AreaZero_Outside2_EventScript_ChooseParadoxBossParty:
	msgbox AreaZero_Outside2_Text_SelectParadoxBossParty, MSGBOX_DEFAULT
	choose_mons
	goto_if_eq VAR_RESULT, FALSE, AreaZero_Outside2_EventScript_ChooseParadoxBossParty
	callnative BattleSetup_UseSelectedPartyForNextScriptedWildPartnerBattle
	return

AreaZero_Outside2_EventScript_StartPastParadoxBossBattle:
	setcustomwildbattleparty 6, SPECIES_GREAT_TUSK, 70, ITEM_BOOSTER_ENERGY, MOVE_HEADLONG_RUSH, MOVE_CLOSE_COMBAT, MOVE_ICE_SPINNER, MOVE_BODY_PRESS, SPECIES_KORAIDON, 70, ITEM_BOOSTER_ENERGY, MOVE_COLLISION_COURSE, MOVE_FLARE_BLITZ, MOVE_DRAGON_CLAW, MOVE_CRUNCH, SPECIES_FLUTTER_MANE, 70, ITEM_BOOSTER_ENERGY, MOVE_MOONBLAST, MOVE_SHADOW_BALL, MOVE_PSYSHOCK, MOVE_MYSTICAL_FIRE, SPECIES_ROARING_MOON, 70, ITEM_BOOSTER_ENERGY, MOVE_DRAGON_DANCE, MOVE_CRUNCH, MOVE_ACROBATICS, MOVE_EARTHQUAKE, SPECIES_SLITHER_WING, 70, ITEM_BOOSTER_ENERGY, MOVE_FIRST_IMPRESSION, MOVE_CLOSE_COMBAT, MOVE_LEECH_LIFE, MOVE_WILD_CHARGE, SPECIES_BRUTE_BONNET, 70, ITEM_BOOSTER_ENERGY, MOVE_SPORE, MOVE_SUCKER_PUNCH, MOVE_SEED_BOMB, MOVE_CLOSE_COMBAT
	call AreaZero_Outside2_EventScript_SetPastRivalPartner
	goto AreaZero_Outside2_EventScript_BeginParadoxBossBattle

AreaZero_Outside2_EventScript_StartFutureParadoxBossBattle:
	setcustomwildbattleparty 6, SPECIES_IRON_TREADS, 70, ITEM_BOOSTER_ENERGY, MOVE_HIGH_HORSEPOWER, MOVE_IRON_HEAD, MOVE_BODY_PRESS, MOVE_KNOCK_OFF, SPECIES_MIRAIDON, 70, ITEM_BOOSTER_ENERGY, MOVE_ELECTRO_DRIFT, MOVE_DRACO_METEOR, MOVE_VOLT_SWITCH, MOVE_DAZZLING_GLEAM, SPECIES_IRON_VALIANT, 70, ITEM_BOOSTER_ENERGY, MOVE_SPIRIT_BREAK, MOVE_DRAIN_PUNCH, MOVE_PROTECT, MOVE_KNOCK_OFF, SPECIES_IRON_BUNDLE, 70, ITEM_BOOSTER_ENERGY, MOVE_FREEZE_DRY, MOVE_HYDRO_PUMP, MOVE_SHEER_COLD, MOVE_SUBSTITUTE, SPECIES_IRON_JUGULIS, 70, ITEM_BOOSTER_ENERGY, MOVE_DARK_PULSE, MOVE_AIR_SLASH, MOVE_FLAMETHROWER, MOVE_EARTH_POWER, SPECIES_IRON_THORNS, 70, ITEM_BOOSTER_ENERGY, MOVE_WILD_CHARGE, MOVE_STONE_EDGE, MOVE_EARTHQUAKE, MOVE_IRON_HEAD
	setcustomwildbattlepartner PARTNER_WALLY_AREA_ZERO

AreaZero_Outside2_EventScript_BeginParadoxBossBattle:
	setwildbattleaiflags AI_FLAG_SMART_TRAINER
	@ The background Paradox Pokémon have already withdrawn when the battle ends.
	@ Remove their field objects before entering battle so they cannot flash back
	@ into view during the return-to-field reconstruction.
	removeobject AREAZERO2_FLUTTER_MANE
	removeobject AREAZERO2_GREAT_TUSK
	removeobject AREAZERO2_SLITHER_WING
	removeobject AREAZERO2_IRON_TREADS
	removeobject AREAZERO2_IRON_BUNDLE
	removeobject AREAZERO2_IRON_MOTH
	dowildbattle

	@ dowildbattle resumes here once the custom wild battle ends.
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AreaZero_Outside2_EventScript_GroupReunionEnd
	releaseall
	end

AreaZero_Outside2_EventScript_SetPastRivalPartner:
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, AreaZero_Outside2_EventScript_SetMayPartner
	goto AreaZero_Outside2_EventScript_SetBrendanPartner

AreaZero_Outside2_EventScript_SetMayPartner:
	compare VAR_STARTER_MON, 0
	goto_if_eq AreaZero_Outside2_EventScript_SetMayTreeckoPartner
	compare VAR_STARTER_MON, 1
	goto_if_eq AreaZero_Outside2_EventScript_SetMayTorchicPartner
	goto AreaZero_Outside2_EventScript_SetMayMudkipPartner

AreaZero_Outside2_EventScript_SetMayTreeckoPartner:
	setcustomwildbattlepartner PARTNER_MAY_AREA_ZERO_TREECKO
	return

AreaZero_Outside2_EventScript_SetMayTorchicPartner:
	setcustomwildbattlepartner PARTNER_MAY_AREA_ZERO_TORCHIC
	return

AreaZero_Outside2_EventScript_SetMayMudkipPartner:
	setcustomwildbattlepartner PARTNER_MAY_AREA_ZERO_MUDKIP
	return

AreaZero_Outside2_EventScript_SetBrendanPartner:
	compare VAR_STARTER_MON, 0
	goto_if_eq AreaZero_Outside2_EventScript_SetBrendanTreeckoPartner
	compare VAR_STARTER_MON, 1
	goto_if_eq AreaZero_Outside2_EventScript_SetBrendanTorchicPartner
	goto AreaZero_Outside2_EventScript_SetBrendanMudkipPartner

AreaZero_Outside2_EventScript_SetBrendanTreeckoPartner:
	setcustomwildbattlepartner PARTNER_BRENDAN_AREA_ZERO_TREECKO
	return

AreaZero_Outside2_EventScript_SetBrendanTorchicPartner:
	setcustomwildbattlepartner PARTNER_BRENDAN_AREA_ZERO_TORCHIC
	return

AreaZero_Outside2_EventScript_SetBrendanMudkipPartner:
	setcustomwildbattlepartner PARTNER_BRENDAN_AREA_ZERO_MUDKIP
	return

AreaZero_Outside2_EventScript_GroupReunionEnd:
	goto AreaZero_Outside2_EventScript_PostBattle

AreaZero_Outside2_EventScript_PostBattle:
	@ The two leaders retreat without breaking eye contact with the group.
	applymovement AREAZERO2_KORAIDON, AreaZero_Outside2_Movement_KoraidonStepBack
	applymovement AREAZERO2_MIRAIDON, AreaZero_Outside2_Movement_MiraidonStepBack
	waitmovement 0
	compare VAR_TEMP_0, 0
	goto_if_eq AreaZero_Outside2_EventScript_PostBattlePastLatisArrive
	goto AreaZero_Outside2_EventScript_PostBattleFutureLatisArrive

AreaZero_Outside2_EventScript_PostBattlePastLatisArrive:
	removeobject AREAZERO2_LATIAS
	removeobject AREAZERO2_LATIOS
	removeobject AREAZERO2_FLUTTER_MANE
	removeobject AREAZERO2_GREAT_TUSK
	removeobject AREAZERO2_SLITHER_WING
	removeobject AREAZERO2_IRON_TREADS
	removeobject AREAZERO2_IRON_BUNDLE
	removeobject AREAZERO2_IRON_MOTH
	setobjectxyperm AREAZERO2_LATIAS, 33, 12
	setobjectxyperm AREAZERO2_LATIOS, 18, 12
	addobject AREAZERO2_LATIAS
	applymovement AREAZERO2_LATIAS, AreaZero_Outside2_Movement_LatiasArrivePast
	waitmovement 0
	turnobject AREAZERO2_KORAIDON, DIR_EAST
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	addobject AREAZERO2_LATIOS
	applymovement AREAZERO2_LATIOS, AreaZero_Outside2_Movement_LatiosArrivePast
	waitmovement 0
	turnobject AREAZERO2_MIRAIDON, DIR_WEST
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_KORAIDON, CRY_MODE_NORMAL
	playmoncry SPECIES_MIRAIDON, CRY_MODE_NORMAL
	waitmoncry
	goto AreaZero_Outside2_EventScript_PostBattleParadoxDepart

AreaZero_Outside2_EventScript_PostBattleFutureLatisArrive:
	removeobject AREAZERO2_LATIAS
	removeobject AREAZERO2_LATIOS
	removeobject AREAZERO2_FLUTTER_MANE
	removeobject AREAZERO2_GREAT_TUSK
	removeobject AREAZERO2_SLITHER_WING
	removeobject AREAZERO2_IRON_TREADS
	removeobject AREAZERO2_IRON_BUNDLE
	removeobject AREAZERO2_IRON_MOTH
	setobjectxyperm AREAZERO2_LATIAS, 35, 12
	setobjectxyperm AREAZERO2_LATIOS, 18, 12
	addobject AREAZERO2_LATIAS
	applymovement AREAZERO2_LATIAS, AreaZero_Outside2_Movement_LatiasArriveFuture
	waitmovement 0
	turnobject AREAZERO2_KORAIDON, DIR_EAST
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	addobject AREAZERO2_LATIOS
	applymovement AREAZERO2_LATIOS, AreaZero_Outside2_Movement_LatiosArriveFuture
	waitmovement 0
	turnobject AREAZERO2_MIRAIDON, DIR_WEST
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_KORAIDON, CRY_MODE_NORMAL
	playmoncry SPECIES_MIRAIDON, CRY_MODE_NORMAL
	waitmoncry
	goto AreaZero_Outside2_EventScript_PostBattleParadoxDepart

AreaZero_Outside2_EventScript_PostBattleParadoxDepart:
	@ Their conflict is over: the Paradox Pokémon vanish for good.
	@ This is an in-map update: use the hardware fade, as in Route 111, so the
	@ fade-out cannot overwrite the normal palette buffer with a blackened copy.
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_AREA_ZERO_OUTSIDE2_PARADOX_VISION
	removeobject AREAZERO2_KORAIDON
	removeobject AREAZERO2_MIRAIDON
	setvar VAR_AREAZERO_STATE, 0xFF
	special DrawWholeMapView
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox AreaZero_Outside2_Text_AndryParadoxMonsAreGone, MSGBOX_DEFAULT
	closemessage
	goto AreaZero_Outside2_EventScript_PostBattleLatisReassureGroup

AreaZero_Outside2_EventScript_PostBattleLatisReassureGroup:
	turnobject AREAZERO2_LATIAS, DIR_SOUTH
	turnobject AREAZERO2_LATIOS, DIR_SOUTH
	msgbox AreaZero_Outside2_Text_StevenLatisAreCalmer, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	waitmoncry
	applymovement AREAZERO2_LATIAS, AreaZero_Outside2_Movement_LatisLeaveScene
	applymovement AREAZERO2_LATIOS, AreaZero_Outside2_Movement_LatisLeaveScene
	waitmovement 0
	removeobject AREAZERO2_LATIAS
	removeobject AREAZERO2_LATIOS
	setflag FLAG_AREA_ZERO_OUTSIDE2_LATIS

	@ The team gathers around STEVEN for his final briefing.
	turnobject AREAZERO2_STEVEN, DIR_EAST
	applymovement LOCALID_PLAYER, AreaZero_Outside2_Movement_PlayerApproachStevenAfterBattle
	applymovement AREAZERO2_ANDRY, AreaZero_Outside2_Movement_AndryApproachStevenAfterBattle
	applymovement AREAZERO2_EDO, AreaZero_Outside2_Movement_SplitfaceApproachStevenAfterBattle
	applymovement AREAZERO2_WALLY, AreaZero_Outside2_Movement_WallyApproachStevenAfterBattle
	applymovement AREAZERO2_RIVAL, AreaZero_Outside2_Movement_RivalApproachStevenAfterBattle
	waitmovement 0
	turnobject AREAZERO2_STEVEN, DIR_EAST
	msgbox AreaZero_Outside2_Text_StevenThanksForEverything, MSGBOX_DEFAULT
	msgbox AreaZero_Outside2_Text_StevenResearchPlan, MSGBOX_DEFAULT
	msgbox AreaZero_Outside2_Text_GroupAgrees, MSGBOX_DEFAULT
	turnobject AREAZERO2_ANDRY, DIR_WEST
	msgbox AreaZero_Outside2_Text_AndryLetsGo, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	setflag FLAG_AREA_ZERO_OUTSIDE2_OBJ
	clearflag FLAG_HIDE_ROUTE_118_STEVEN
	setvar VAR_ROUTE118_STATE, 2
	warp MAP_ROUTE118, 42, 14
	waitstate
	fadescreen FADE_FROM_BLACK
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
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ From (23, 35) to STEVEN's slot at (22, 13).
AreaZero_Outside2_Movement_StevenEscortToFormation::
	.rept 22
	walk_fast_up
	.endr
	walk_fast_left
	face_up
	step_end

@ Follow STEVEN one tile behind, then step right into the coord-event tile at (24, 13).
AreaZero_Outside2_Movement_PlayerRunWithSteven::
	delay_8
	walk_fast_right
	.rept 22
	walk_fast_up
	.endr
	walk_fast_right
	face_up
	step_end

@ Starts at the recovery trigger on (24, 17) and returns to the battle slot.
AreaZero_Outside2_Movement_PlayerReturnToBattlePosition::
	.rept 4
	walk_fast_up
	.endr
	face_up
	step_end

AreaZero_Outside2_Movement_KoraidonApproachPlayer::
	walk_down
	walk_down
	walk_left
	walk_down
	step_end

@ In the Future branch, KORAIDON confronts ANDRY and SPLITFACE at (27, 12).
AreaZero_Outside2_Movement_KoraidonApproachAndrySplitface::
	walk_down
	walk_down
	.rept 2
	walk_right
	.endr
	walk_down
	step_end

AreaZero_Outside2_Movement_MiraidonApproachPlayer::
	walk_down
	walk_right
	walk_down
	walk_right
	walk_down
	step_end

AreaZero_Outside2_Movement_MiraidonApproachSteven::
	walk_down
	walk_down
	walk_down
	step_end

AreaZero_Outside2_Movement_KoraidonClashMiraidon::
	walk_fast_left
	face_left
	step_end

AreaZero_Outside2_Movement_MiraidonClashKoraidon::
	walk_fast_right
	face_right
	step_end

AreaZero_Outside2_Movement_KoraidonRecoilFromClash::
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

AreaZero_Outside2_Movement_MiraidonRecoilFromClash::
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

AreaZero_Outside2_Movement_KoraidonStepBack::
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

AreaZero_Outside2_Movement_MiraidonStepBack::
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

@ In the Past route, KORAIDON is at (24, 12) and MIRAIDON at (22, 12).
AreaZero_Outside2_Movement_LatiasArrivePast::
	.rept 8
	walk_fast_left
	.endr
	face_left
	step_end

AreaZero_Outside2_Movement_LatiosArrivePast::
	.rept 3
	walk_fast_right
	.endr
	face_right
	step_end

@ In the Future route, KORAIDON is at (27, 12) and MIRAIDON at (24, 12).
AreaZero_Outside2_Movement_LatiasArriveFuture::
	.rept 7
	walk_fast_left
	.endr
	face_left
	step_end

AreaZero_Outside2_Movement_LatiosArriveFuture::
	.rept 5
	walk_fast_right
	.endr
	face_right
	step_end

AreaZero_Outside2_Movement_LatiasJoinGroupPast::
	walk_down
	face_down
	step_end

AreaZero_Outside2_Movement_LatiosJoinGroupPast::
	walk_down
	face_down
	step_end

AreaZero_Outside2_Movement_LatiasJoinGroupFuture::
	walk_left
	walk_down
	face_down
	step_end

AreaZero_Outside2_Movement_LatiosJoinGroupFuture::
	walk_down
	face_down
	step_end

AreaZero_Outside2_Movement_LatisLeaveScene::
	.rept 5
	walk_fast_up
	.endr
	step_end

AreaZero_Outside2_Movement_PlayerApproachStevenAfterBattle::
	walk_left
	face_left
	step_end

AreaZero_Outside2_Movement_AndryApproachStevenAfterBattle::
	walk_left
	face_left
	step_end

AreaZero_Outside2_Movement_SplitfaceApproachStevenAfterBattle::
	walk_left
	face_left
	step_end

AreaZero_Outside2_Movement_WallyApproachStevenAfterBattle::
	walk_up
	face_up
	step_end

AreaZero_Outside2_Movement_RivalApproachStevenAfterBattle::
	walk_up
	face_left
	step_end

AreaZero_Outside2_PlayerComeBackFromHealing::
	@ Stop one tile south of the coord event. Coord events are only checked after
	@ stepping onto their tile, not when a variable changes beneath the player.
	.rept 17
	walk_fast_up
	.endr
	walk_fast_right
	.rept 3
	walk_fast_up
	.endr
	step_end

AreaZero_Outside2_Text_StevenGladYouMadeIt:
	.string "STEVEN: Here we are.\p"
	.string "Let's get some distance from\n"
	.string "the cave before the others arrive. $"

AreaZero_Outside2_Text_StevenWaitOthers:
	.string "STEVEN: Let's wait for the others here. $"

AreaZero_Outside2_Text_StevenPastOrFuture:
	.string "STEVEN: This place has made me\n"
	.string "think about the paths ahead.\p"
	.string "When you look forward, are you\n"
	.string "drawn to the PAST or FUTURE? $"

AreaZero_Outside2_Text_PlayerChoosesPast:
	.string "{PLAYER} chooses to face\n"
	.string "what the past left behind. $"

AreaZero_Outside2_Text_StevenRepliesPast:
	.string "STEVEN: Then perhaps the past\n"
	.string "still has something to teach you. $"

AreaZero_Outside2_Text_PlayerChoosesFuture:
	.string "{PLAYER} chooses to prepare\n"
	.string "for whatever the future holds. $"

AreaZero_Outside2_Text_StevenRepliesFuture:
	.string "STEVEN: The future...\p"
	.string "It is wise to prepare yourself\n"
	.string "for what lies ahead. $"

AreaZero_Outside2_Text_StevenThanks:
	.string "{PLAYER}, thanks for your answer. $"

AreaZero_Outside2_Text_SplitfaceMadeIt:
	.string "SPLITFACE: Finally, we're out...\p"
	.string "Voglio andare a casa, sigh. $"

AreaZero_Outside2_Text_RivalMadeIt:
	.string "{RIVAL}: We made it out.\p"
	.string "I've never seen anything like\n"
	.string "those POKéMON in my father's\l"
	.string "research before. $"

AreaZero_Outside2_Text_WallyMadeIt:
	.string "WALLY: Phew... I'm glad we're\n"
	.string "all still standing.\p"
	.string "That was far too close. $"

AreaZero_Outside2_Text_AndryMadeIt:
	.string "ANDRY: STEVEN, {PLAYER}...\p"
	.string "We're all here. $"

AreaZero_Outside2_Text_AndrySensesSomething:
	.string "ANDRY: STEVEN, what did you find- $"

AreaZero_Outside2_Text_StevenSomethingIsThere:
	.string "STEVEN: That sound...!\p"
	.string "What was that? $"

AreaZero_Outside2_Text_AndryGoCheckFast:
	.string "ANDRY: We need to see what it is. Now! $"

AreaZero_Outside2_Text_StevenGoAheadFast:
	.string "STEVEN: {PLAYER}, stay close.\p"
	.string "We need to catch up to them. $"

AreaZero_Outside2_Text_WallyRunWithSteven:
	.string "WALLY: W-what are those? $"

AreaZero_Outside2_Text_SplitfaceRunWithSteven:
	.string "SPLITFACE: They're enormous. $"

AreaZero_Outside2_Text_AndryUnderstandsTheTurmoil:
	.string "ANDRY: I see it now...\p"
	.string "Those two POKéMON are fighting\n"
	.string "over this territory. $"

AreaZero_Outside2_Text_AndryParadoxEnergy:
	.string "ANDRY: Their energy has thrown\n"
	.string "every other POKéMON into turmoil.\p"
	.string "I don't even know what they are... $"

AreaZero_Outside2_Text_AndryStopTheParadoxMons:
	.string "ANDRY: Then we stop them before\n"
	.string "their fight spreads any further. $"

AreaZero_Outside2_Text_StevenParadoxBattleLeadIn:
	.string "STEVEN: Stay focused, {PLAYER}.\p"
	.string "I'll stand against the future. $"

AreaZero_Outside2_Text_AndryParadoxBattleLeadIn:
	.string "ANDRY: We'll handle the other one. $"

AreaZero_Outside2_Text_SplitfaceParadoxBattleLeadIn:
	.string "SPLITFACE: I'll have that delibird thingy. $"

AreaZero_Outside2_Text_WallyParadoxBattleLeadIn:
	.string "WALLY: Then I'm with you, {PLAYER}! $"

AreaZero_Outside2_Text_RivalParadoxBattleLeadIn:
	.string "{RIVAL}: {PLAYER}, we'll take\n"
	.string "that one together! $"

AreaZero_Outside2_Text_SelectParadoxBossParty:
	.string "Choose three POKéMON to fight\n"
	.string "alongside your ally. $"

AreaZero_Outside2_Text_AndryParadoxMonsAreGone:
	.string "ANDRY: They've backed down.\p"
	.string "I think the danger has passed. $"

AreaZero_Outside2_Text_StevenLatisAreCalmer:
	.string "STEVEN: LATIOS and LATIAS have\n"
	.string "calmed down as well.\p"
	.string "The fighting must have upset them. $"

AreaZero_Outside2_Text_StevenThanksForEverything:
	.string "STEVEN: Thank you, everyone.\p"
	.string "The situation is stable at last. $"

AreaZero_Outside2_Text_StevenResearchPlan:
	.string "STEVEN: I'll return home to\n"
	.string "examine the samples.\p"
	.string "We'll keep surveying this place,\n"
	.string "learn where those POKéMON came\l"
	.string "from, and protect it. $"

AreaZero_Outside2_Text_GroupAgrees:
	.string "The others nod in agreement. $"

AreaZero_Outside2_Text_AndryLetsGo:
	.string "ANDRY: Okay, let's go back. $"

AreaZero_Outside2_Text_MustContinueBattle:
	.string "You need to continue the battle.\n"
	.string "Prepare your team, then head north. $"

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
