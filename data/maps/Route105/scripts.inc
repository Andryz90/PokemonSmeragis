Route105_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
	.byte 0

Route105_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute105North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute105South
	end

Route105_CloseRegiEntrance::
	setmetatile 9, 19, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 9, 20, METATILE_General_RockWall_SandBase, TRUE
	return

Route105_OnTransition:
	setflag FLAG_REGI_DOORS_OPENED
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_StartKyogreWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_StartKyogreWeather
	end

Route105_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route105_EventScript_Foster::
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Luis::
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Dominik::
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Imani::
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Josue::
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Andres::
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route105_EventScript_AndresRematch
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_EventScript_AndresRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDRES_1
	release
	end

Route105_EventScript_AndresRematch::
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_TeamAquaRegice::
	lockall
	setvar VAR_ROUTE105_AQUA_EVENT_STATE, 1
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route105_Movement_CameraPanAwayFromPlayer
	waitmovement LOCALID_CAMERA
	applymovement LOCALID_CAMERA, Route105_Movement_CameraPanToTeamAqua
	waitmovement 0
	special HidePlayerForCutscene
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	waitmovement 0
	msgbox Route105_Text_ArchieClaimedRegicePower, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R105_ARCHIE, Common_Movement_FaceDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_R105_ARCHIE
	waitse
	applymovement LOCALID_R105_AQUA_GRUNT_F, Route105_Movement_AquaGruntFBoardBoat
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_R105_AQUA_GRUNT_F
	waitse
	applymovement LOCALID_R105_AQUA_GRUNT_M, Route105_Movement_AquaGruntMBoardBoat
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_R105_AQUA_GRUNT_M
	waitse
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 5, Route105_EventScript_CenterCameraOnBoatFromX5
	goto_if_eq VAR_0x8004, 6, Route105_EventScript_CenterCameraOnBoatFromX6
	goto_if_eq VAR_0x8004, 7, Route105_EventScript_CenterCameraOnBoatFromX7
	goto_if_eq VAR_0x8004, 8, Route105_EventScript_BoatDeparture
	goto Route105_EventScript_CenterCameraOnBoatFromX9

Route105_EventScript_CenterCameraOnBoatFromX5::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraCenterBoatFromX5
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatDeparture

Route105_EventScript_CenterCameraOnBoatFromX6::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraCenterBoatFromX6
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatDeparture

Route105_EventScript_CenterCameraOnBoatFromX7::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraCenterBoatFromX7
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatDeparture

Route105_EventScript_CenterCameraOnBoatFromX9::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraCenterBoatFromX9
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatDeparture

Route105_EventScript_BoatDeparture::
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatAndCameraLeaveScene
	applymovement LOCALID_CAMERA, Route105_Movement_AquaBoatAndCameraLeaveScene
	waitmovement LOCALID_CAMERA
	special ShowPlayerAfterCutscene
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatAndCameraApproachPlayer
	applymovement LOCALID_CAMERA, Route105_Movement_AquaBoatAndCameraApproachPlayer
	waitmovement LOCALID_CAMERA
	goto_if_eq VAR_0x8004, 5, Route105_EventScript_AlignBoatToPlayerX5
	goto_if_eq VAR_0x8004, 6, Route105_EventScript_AlignBoatToPlayerX6
	goto_if_eq VAR_0x8004, 7, Route105_EventScript_AlignBoatToPlayerX7
	goto_if_eq VAR_0x8004, 8, Route105_EventScript_BoatSailPastPlayer
	goto Route105_EventScript_AlignBoatToPlayerX9

Route105_EventScript_AlignBoatToPlayerX5::
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatAndCameraShiftLeft3
	applymovement LOCALID_CAMERA, Route105_Movement_AquaBoatAndCameraShiftLeft3
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatSailPastPlayer

Route105_EventScript_AlignBoatToPlayerX6::
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatAndCameraShiftLeft2
	applymovement LOCALID_CAMERA, Route105_Movement_AquaBoatAndCameraShiftLeft2
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatSailPastPlayer

Route105_EventScript_AlignBoatToPlayerX7::
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatAndCameraShiftLeft1
	applymovement LOCALID_CAMERA, Route105_Movement_AquaBoatAndCameraShiftLeft1
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatSailPastPlayer

Route105_EventScript_AlignBoatToPlayerX9::
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatAndCameraShiftLeft1
	applymovement LOCALID_CAMERA, Route105_Movement_AquaBoatAndCameraShiftLeft1
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_BoatSailPastPlayer

Route105_EventScript_BoatSailPastPlayer::
	applymovement LOCALID_R105_AQUA_SCENE_BOAT, Route105_Movement_AquaBoatSailPastPlayer
	waitmovement LOCALID_R105_AQUA_SCENE_BOAT
	goto_if_eq VAR_0x8004, 8, Route105_EventScript_ReturnCameraFromPlayerX
	goto_if_eq VAR_0x8004, 9, Route105_EventScript_ReturnCameraFromPlayerLeft
	goto Route105_EventScript_ReturnCameraFromPlayerRight

Route105_EventScript_ReturnCameraFromPlayerRight::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraReturnToPlayer
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_FinishTeamAquaRegice

Route105_EventScript_ReturnCameraFromPlayerX::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraReturnToPlayerX
	waitmovement LOCALID_CAMERA
	goto Route105_EventScript_FinishTeamAquaRegice

Route105_EventScript_ReturnCameraFromPlayerLeft::
	applymovement LOCALID_CAMERA, Route105_Movement_CameraReturnToPlayerLeft
	waitmovement LOCALID_CAMERA

Route105_EventScript_FinishTeamAquaRegice::
	special RemoveCameraObject
	removeobject LOCALID_R105_AQUA_SCENE_BOAT
	removeobject LOCALID_R105_AQUA_BOAT_1
	removeobject LOCALID_R105_AQUA_BOAT_2
	removeobject LOCALID_R105_AQUA_BOAT_4
	removeobject LOCALID_R105_AQUA_BOAT_5
	removeobject LOCALID_R105_AQUA_BOAT_6
	removeobject LOCALID_R105_AQUA_WITNESS_F1
	removeobject LOCALID_R105_AQUA_WITNESS_F2
	removeobject LOCALID_R105_AQUA_WITNESS_M1
	removeobject LOCALID_R105_AQUA_WITNESS_M2
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
	setflag FLAG_DEFEATED_REGICE
	setflag FLAG_HIDE_REGICE
	setflag FLAG_AQUA_R105_EVENT
	releaseall
	end

Route105_EventScript_AquaBoatWitnessF::
	faceplayer
	msgbox Route105_Text_AquaBoatWitnessF, MSGBOX_DEFAULT
	release
	end

Route105_EventScript_AquaBoatWitnessM::
	faceplayer
	msgbox Route105_Text_AquaBoatWitnessM, MSGBOX_DEFAULT
	release
	end

Route105_Movement_CameraPanAwayFromPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route105_Movement_CameraPanToTeamAqua:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route105_Movement_AquaGruntFBoardBoat:
	walk_right
	walk_down
	step_end

Route105_Movement_AquaGruntMBoardBoat:
	walk_left
	walk_down
	step_end

Route105_Movement_CameraCenterBoatFromX5:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route105_Movement_CameraCenterBoatFromX6:
	walk_right
	walk_right
	walk_right
	step_end

Route105_Movement_CameraCenterBoatFromX7:
	walk_right
	walk_right
	step_end

Route105_Movement_CameraCenterBoatFromX9:
	walk_left
	step_end

Route105_Movement_AquaBoatAndCameraLeaveScene:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route105_Movement_AquaBoatAndCameraApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route105_Movement_AquaBoatAndCameraShiftLeft3:
	walk_left
	walk_left
	walk_left
	step_end

Route105_Movement_AquaBoatAndCameraShiftLeft2:
	walk_left
	walk_left
	step_end

Route105_Movement_AquaBoatAndCameraShiftLeft1:
	walk_left
	step_end

Route105_Movement_AquaBoatAndCameraShiftRight1:
	walk_right
	step_end

Route105_Movement_AquaBoatSailPastPlayer:
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
	walk_down
	walk_down
	step_end

Route105_Movement_CameraReturnToPlayer:
	walk_left
	walk_down
	walk_down
	step_end

Route105_Movement_CameraReturnToPlayerX:
	walk_down
	walk_down
	step_end

Route105_Movement_CameraReturnToPlayerLeft:
	walk_right
	walk_down
	walk_down
	step_end

Route104_Text_DadPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "DAD: Oh, {PLAYER}?\p"
	.string "… … … … … …\n"
	.string "Where are you now?\l"
	.string "It sounds windy wherever you are.\p"
	.string "I just heard from DEVON's MR. STONE\n"
	.string "about your POKéNAV, so I decided\l"
	.string "to give you a call.\p"
	.string "It sounds like you're doing fine,\n"
	.string "so that's fine with me.\p"
	.string "You take care now.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click! $"

Route104_Text_RegisteredDadInPokenav:
	.string "Registered DAD NORMAN\n"
	.string "in the POKéNAV. $"

Route105_Text_ArchieClaimedRegicePower:
	.string "ARCHIE: We did it. At last, REGICE's\n"
	.string "power is in our hands.\p"
	.string "TEAM MAGMA won't defeat us\n"
	.string "so easily. $"

Route105_Text_AquaBoatWitnessF:
	.string "Those boats appeared out of nowhere!\n"
	.string "They're blocking the route.\p"
	.string "They look like pirates, but no one\n"
	.string "aboard will tell us what's going on. $"

Route105_Text_AquaBoatWitnessM:
	.string "I tried asking what was happening,\n"
	.string "but nobody on those boats answered.\p"
	.string "They look like a group of pirates.\n"
	.string "Best to stay out of their way. $"
