.set LOCALID_STEVEN, 19

Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_ROUTE118_STATE, 0, Route118_EventScript_HideAreaZeroActors
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
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

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
