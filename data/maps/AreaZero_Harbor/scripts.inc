AreaZero_Harbor_MapScripts::
	.byte 0

AreaZero_Harbor_EventScript_Sailor::
	lock
	faceplayer
	msgbox AreaZero_Harbor_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AreaZero_Harbor_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_AREA_ZERO_HARBOR_SAILOR, MAP_AREA_ZERO_HARBOR
	setvar VAR_0x8004, LOCALID_AREA_ZERO_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

AreaZero_Harbor_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

AreaZero_Harbor_Text_SailorReturn:
	.string "This place gives me the creeps...\p"
	.string "Do you want to return to\n"
	.string "LILYCOVE? $"
