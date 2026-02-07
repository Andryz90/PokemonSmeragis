DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	special RegisterTalkedFossil
	msgbox DesertUnderpass_Text_FossilRegistered, MSGBOX_YESNO	
	switch VAR_RESULT
	case YES, DesertUnderpass_EventScript_GiveFossilRegistered
	case NO, DesertUnderpass_EventScript_Fossil_Exit
	case MULTI_B_PRESSED, DesertUnderpass_EventScript_Fossil_Exit
	release
	end

DesertUnderpass_EventScript_GiveFossilRegistered::
	giveitem VAR_UNUSED_0x8014
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 12 @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	refreshobjectsinmap 
	fadescreen FADE_FROM_BLACK
	release
	end

DesertUnderpass_EventScript_Fossil_Exit::
	release 
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil::
	.string "{PLAYER} found the ROOT FOSSIL. $"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER} found the CLAW FOSSIL. $"

DesertUnderpass_Text_FossilRegistered::
	.string "Inside there is {STR_VAR_1}\n"
	.string "Woud you like to take it? $"