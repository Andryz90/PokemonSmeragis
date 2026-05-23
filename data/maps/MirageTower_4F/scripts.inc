MirageTower_4F_MapScripts::
	.byte 0

MirageTower_4F_EventScript_TowerChest::
	finditem ITEM_GIMMIGHOUL_COIN, 100
	goto_if_ne VAR_RESULT, TRUE, MirageTower_4F_EventScript_TowerChestEnd
	lockall
	goto MirageTower_4F_EventScript_CollapseMirageTower

MirageTower_4F_EventScript_TowerChestEnd::
	end

MirageTower_4F_EventScript_CollapseMirageTower::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	warp MAP_ROUTE111, 19, 59
	waitstate
	releaseall
	end
