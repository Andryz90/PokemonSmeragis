.set LOCALID_STEVEN, 19
.set ROUTE118_AREA_ZERO_FINAL_SCENE_VALUE, 2
.set ROUTE118_AREA_ZERO_EVENT_COMPLETE_VALUE, 3

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_ROUTE118_STATE, 0, Route118_EventScript_HideAreaZeroActors
	call_if_eq VAR_ROUTE118_STATE, ROUTE118_AREA_ZERO_FINAL_SCENE_VALUE, Route118_EventScript_SetupAreaZeroFinalScene
	call GabbyAndTy_EventScript_UpdateLocation
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
	end

Route118_EventScript_HideAreaZeroActors:
	hideobjectat LOCALID_ROUTE118_LATIAS, MAP_ROUTE118
	hideobjectat LOCALID_ROUTE118_LATIOS, MAP_ROUTE118
	hideobjectat LOCALID_ROUTE118_WALLY, MAP_ROUTE118
	hideobjectat LOCALID_ROUTE118_RIVAL, MAP_ROUTE118
	return

Route118_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame:
	map_script_2 VAR_ROUTE118_STATE, ROUTE118_AREA_ZERO_FINAL_SCENE_VALUE, Route118_EventScript_AreaZeroFinalScene
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_EventScript_SetupAreaZeroFinalScene:
	removeobject ROUTE118_CRYSTAL_LOCALID
	setobjectxyperm LOCALID_STEVEN, 41, 14
	setobjectmovementtype LOCALID_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_ANDRY_118, 42, 13
	setobjectmovementtype LOCALID_ANDRY_118, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_SPLITFACE_118, 43, 13
	setobjectmovementtype LOCALID_SPLITFACE_118, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_ROUTE118_WALLY, 42, 15
	setobjectmovementtype LOCALID_ROUTE118_WALLY, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_ROUTE118_RIVAL, 43, 15
	setobjectmovementtype LOCALID_ROUTE118_RIVAL, MOVEMENT_TYPE_FACE_LEFT
	return

Route118_EventScript_AreaZeroFinalScene::
	lockall
	turnobject LOCALID_PLAYER, DIR_WEST
	msgbox Route118_Text_StevenFinalThanks, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_STEVEN, DIR_EAST
	playse SE_M_FLY
	applymovement LOCALID_STEVEN, Route118_Movement_StevenFlyAway
	waitmovement 0
	removeobject LOCALID_STEVEN
	applymovement LOCALID_ROUTE118_WALLY, Common_Movement_FaceUp
	applymovement LOCALID_ROUTE118_RIVAL, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceDown
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceDown
	waitmovement 0
	msgbox Route118_Text_WallyFortreeMeeting, MSGBOX_DEFAULT
	applymovement LOCALID_ROUTE118_WALLY, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE118_RIVAL, Common_Movement_ExclamationMark
	msgbox Route118_Text_WallyTeamAquaQuestion, MSGBOX_DEFAULT
	msgbox Route118_Text_PlayerToldTeamAquaStory, MSGBOX_DEFAULT
	msgbox Route118_Text_RivalUnknownCave, MSGBOX_DEFAULT
	msgbox Route118_Text_AndryIslandCave, MSGBOX_DEFAULT
	msgbox Route118_Text_RivalAbandonedShip, MSGBOX_DEFAULT
	msgbox Route118_Text_WallyRivalLeaveForFortree, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyLeaveForFortree
	applymovement LOCALID_ROUTE118_RIVAL, Route118_Movement_RivalLeaveForFortree
	waitmovement 0
	removeobject LOCALID_ROUTE118_WALLY
	removeobject LOCALID_ROUTE118_RIVAL

	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Route118_Text_AndryFarewell, MSGBOX_DEFAULT
	closemessage
	msgbox Route118_Text_SplitfaceTired, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SPLITFACE_118, Route118_Movement_SplitfaceLeaveFinal
	applymovement LOCALID_ANDRY_118, Route118_Movement_AndryLeaveFinal
	waitmovement 0
	removeobject LOCALID_ANDRY_118
	removeobject LOCALID_SPLITFACE_118
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	setvar VAR_ROUTE118_STATE, ROUTE118_AREA_ZERO_EVENT_COMPLETE_VALUE
	releaseall
	end

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerApproachCrystal0
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerApproachCrystal1
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerApproachCrystal2
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger::
	call Route118_EventScript_BufferBadgeCount
	delay 20
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route118_Text_SplitfaceSessosoCrystal, MSGBOX_DEFAULT
	msgbox Route118_Text_AndryPiantala, MSGBOX_DEFAULT
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceDown
	msgbox Route118_Text_CrystalAnalysis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_FaceLeft
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceLeft
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Route118_Text_StevenGreeting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_QuestionMark
	waitmovement 0
	msgbox Route118_Text_StevenPokeNavMalfunction, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_REGISTER_MATCH_CALL
	message Route118_Text_PokeNavFlyRestored
	waitfanfare
	setflag FLAG_NAV_POKERIDER
	msgbox Route118_Text_StevenPokeNavMalfunction, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_STEVEN, Common_Movement_FaceDown
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceDown
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceDown
	waitmovement 0
	showobjectat LOCALID_ROUTE118_LATIAS, MAP_ROUTE118
	showobjectat LOCALID_ROUTE118_LATIOS, MAP_ROUTE118
	applymovement LOCALID_ROUTE118_LATIAS, Route118_Movement_LatisArrive
	applymovement LOCALID_ROUTE118_LATIOS, Route118_Movement_LatisArrive
	waitmovement 0
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ROUTE118_LATIAS, Common_Movement_ExclamationMark
	applymovement LOCALID_ROUTE118_LATIOS, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route118_Text_AndryLatiasLatiosWarning, MSGBOX_DEFAULT
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	waitmoncry
	msgbox Route118_Text_StevenLatiasLatiosWarning, MSGBOX_DEFAULT
	removeobject LOCALID_ROUTE118_WALLY
	removeobject LOCALID_ROUTE118_RIVAL
	setobjectxyperm LOCALID_ROUTE118_WALLY, 44, 9
	setobjectxyperm LOCALID_ROUTE118_RIVAL, 43, 9
	addobject LOCALID_ROUTE118_WALLY
	addobject LOCALID_ROUTE118_RIVAL
	showobjectat LOCALID_ROUTE118_WALLY, MAP_ROUTE118
	showobjectat LOCALID_ROUTE118_RIVAL, MAP_ROUTE118
	delay 2
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyRivalArrive
	applymovement LOCALID_ROUTE118_RIVAL, Route118_Movement_WallyRivalArrive
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_STEVEN, Common_Movement_FaceUp
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceUp
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceUp
	waitmovement 0
	msgbox Route118_Text_WallyRivalArrive, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE118_RIVAL, Route118_Movement_RivalApproachingLatis
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_STEVEN, Common_Movement_FaceLeft
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceLeft
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Route118_Text_RivalAnalyzing, MSGBOX_DEFAULT
	msgbox Route118_Text_WallyGoingOn, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_STEVEN, Common_Movement_FaceUp
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceUp
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceUp
	waitmovement 0
	msgbox Route118_Text_StevenExplainsAlarm, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_STEVEN, Common_Movement_FaceDown
	applymovement LOCALID_SPLITFACE_118, Common_Movement_FaceDown
	applymovement LOCALID_ANDRY_118, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_ROUTE118_LATIAS, Route118_Movement_LatiasLatiosLead
	playmoncry SPECIES_LATIOS, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ROUTE118_LATIOS, Route118_Movement_LatiasLatiosLead
	waitmovement 0
	msgbox Route118_Text_FollowLatiasLatios, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE118_STATE, 1
	setvar VAR_AREAZERO_STATE, 1
	clearflag FLAG_AREA_ZERO_OBJ
	clearflag FLAG_AREA_ZERO_LATIS
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	warp MAP_AREA_ZERO_OUTSIDE, 1
	waitstate
	end

Route118_EventScript_BufferBadgeCount::
	setvar VAR_0x8004, 0
	call_if_set FLAG_BADGE01_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE02_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE03_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE04_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE05_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE06_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE07_GET, Route118_EventScript_CountBadge
	call_if_set FLAG_BADGE08_GET, Route118_EventScript_CountBadge
	buffernumberstring STR_VAR_1, VAR_0x8004
	return

Route118_EventScript_CountBadge::
	addvar VAR_0x8004, 1
	return

Route118_Movement_PlayerApproachCrystal0:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	face_right
	step_end

Route118_Movement_PlayerApproachCrystal1:
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
	step_end

Route118_Movement_PlayerApproachCrystal2:
	walk_right
	walk_right
	walk_right
	face_right
	step_end

Route118_Movement_LatisArrive:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_up
	step_end

Route118_Movement_WallyRivalArrive:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
Route118_Movement_RivalApproachingLatis:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

Route118_Movement_LatiasLatiosLead:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route118_Movement_StevenApproachPlayerFinal:
	walk_left
	walk_left
	face_left
	step_end

Route118_Movement_AndryApproachPlayerFinal:
	walk_left
	walk_left
	face_left
	step_end

Route118_Movement_StevenFlyAway:
	fly_up
	step_end

Route118_Movement_WallyLeaveForFortree:
	walk_fast_right
	walk_fast_right
	.rept 8
	walk_fast_up
	.endr
	.rept 5
	walk_fast_right
	.endr
	step_end

Route118_Movement_RivalLeaveForFortree:
	walk_fast_right
	.rept 8
	walk_fast_up
	.endr
	.rept 5
	walk_fast_right
	.endr
	step_end

Route118_Movement_AndryLeaveFinal:
	walk_right
	walk_right
	.rept 4
	walk_up
	.endr
	.rept 4
	walk_right
	.endr
	step_end

Route118_Movement_SplitfaceLeaveFinal:
	walk_right
	.rept 4
	walk_up
	.endr
	.rept 4
	walk_right
	.endr
	step_end

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end

Route118_EventScript_RematchRose::
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_RematchDalton::
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end


Route118_Text_SplitfaceSessosoCrystal:
	.string "SPLITFACE: Cristallo sessoso. $"
Route118_Text_AndryPiantala:
	.string "ANDRY: Piantala. $"
Route118_Text_CrystalAnalysis:
	.string "STEVEN: This crystal is remarkable.\p"
	.string "A white matrix, yet these colored\n"
	.string "fragments are suspended within it.\p"
	.string "They are not inclusions from any\n"
	.string "mineral I know in HOENN.\p"
	.string "ANDRY: The shards are separate colors,\n"
	.string "but the light bends through them as\l"
	.string "if they were one substance.\p"
	.string "I have never seen anything like\n"
	.string "this. $"

Route118_Text_StevenGreeting:
	.string "STEVEN: Ah, {PLAYER}{KUN}.\n"
	.string "It is good to see you again.\p"
	.string "How many GYM BADGES have you\n"
	.string "earned so far?\p"
	.string "{STR_VAR_1}? I see.\n"
	.string "Your progress is plain to see.\p"
	.string "Your POKéMON seem steadier, too.\n"
	.string "You have grown together. $"

Route118_Text_StevenPokeNavMalfunction:
	.string "STEVEN: Hmm? Your POKéNAV's\n"
	.string "FLY function is malfunctioning.\p"
	.string "It appears the problem is with\n"
	.string "the navigation module. $"

Route118_Text_PokeNavFlyRestored:
	.string "The POKéNAV's FLY function\n"
	.string "has been restored! $"

Route118_Text_StevenPokeNavFixed:
	.string "STEVEN: Here we go, fixed. $"

Route118_Text_AndryLatiasLatiosWarning:
	.string "ANDRY: LATIAS, LATIOS?\n"
	.string "Why are you here?$"
Route118_Text_StevenLatiasLatiosWarning:
	.string "STEVEN: They are trying to tell us\n"
	.string "something.\p"
	.string "It seems that they want\nus to follow. $"

Route118_Text_WallyRivalArrive:
	.string "WALLY: {PLAYER}! There you are!\p"
	.string "We came down when we spotted you.\p"
	.string "{RIVAL}: Are those...\n"
	.string "LATIOS and LATIAS?!$"
Route118_Text_RivalAnalyzing:
	.string "Me and my father are studing\n"
	.string "them! Their strong bond and\l"
	.string "psychic powers makes them friendly\l"
	.string "and emphatic towards humans.\p"
	.string "They're roaming around all HOENN.$"

Route118_Text_WallyGoingOn:
	.string "WALLY: {PLAYER}, what's going on? $"

Route118_Text_StevenExplainsAlarm:
	.string "STEVEN: We don't have time now\n"
	.string "to explain. We'll discuss while going.\p"
	.string "You too, come with us. $"

Route118_Text_FollowLatiasLatios:
	.string "ANDRY: SPLITFACE, you're coming too.\p"
	.string "SPLITFACE: Huh?! $"

Route118_Text_StevenFinalThanks:
	.string "STEVEN: I will continue studying\n"
	.string "what we found in AREA ZERO.\p"
	.string "I'll let you know as soon as I\n"
	.string "discover anything.\p"
	.string "Thank you all for your help. $"

Route118_Text_WallyFortreeMeeting:
	.string "WALLY: Like we said on ROUTE 110,\n"
	.string "we're going to FORTREE CITY.\p"
	.string "We'll meet the others there\n"
	.string "to stop TEAM MAGMA. $"

Route118_Text_WallyTeamAquaQuestion:
	.string "{RIVAL}: {PLAYER}, did you also see\n"
	.string "TEAM AQUA acting suspiciously? $"

Route118_Text_PlayerToldTeamAquaStory:
	.string "{PLAYER} told them about TEAM AQUA\n"
	.string "leaving a cave and raiding the\l"
	.string "ABANDONED SHIP's crew. $"

Route118_Text_RivalUnknownCave:
	.string "{RIVAL}: A cave? Do you know\n"
	.string "which one it was? $"

Route118_Text_AndryIslandCave:
	.string "ANDRY: The ISLAND CAVE.\p"
	.string "It's REGICE's resting place. $"

Route118_Text_RivalAbandonedShip:
	.string "{RIVAL}: They stole sea charts and\n"
	.string "a navigation device from the crew.\p"
	.string "TEAM AQUA must be planning\n"
	.string "something at sea. $"

Route118_Text_WallyRivalLeaveForFortree:
	.string "WALLY: There's no time to lose.\p"
	.string "We'll go ahead to FORTREE CITY\n"
	.string "and wait for you there. $"

Route118_Text_AndryFarewell:
	.string "ANDRY: We should get moving too.\p"
	.string "See you soon, {PLAYER}. $"

Route118_Text_SplitfaceTired:
	.string "SPLITFACE: Sono stanco- $"

Route118_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree? $"

Route118_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD! $"

Route118_Text_TryYourLuckFishing:
	.string "Wherever there's water, try your luck\n"
	.string "at fishing. $"

Route118_Text_DontYouLikeToFish:
	.string "Don't you like to fish? $"

Route118_Text_TryCatchingMonWithGoodRod:
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD. $"

Route118_Text_CanCrossRiversWithSurf:
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much! $"

Route118_Text_RouteSignMauville:
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MAUVILLE CITY $"

Route118_Text_RouteSign119:
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119 $"
