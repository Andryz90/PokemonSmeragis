	.include "MPlayDef.s"

	.equ	se_shiny_crystal_grp, voicegroup202
	.equ	se_shiny_crystal_pri, 5
	.equ	se_shiny_crystal_rev, reverb_set+0
	.equ	se_shiny_crystal_mvl, 95
	.equ	se_shiny_crystal_key, 0
	.equ	se_shiny_crystal_tbs, 1
	.equ	se_shiny_crystal_exg, 1
	.equ	se_shiny_crystal_cmp, 1

	.section .rodata
	.global	se_shiny_crystal
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_shiny_crystal_1:
	.byte	KEYSH , se_shiny_crystal_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 198*se_shiny_crystal_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 110*se_shiny_crystal_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn4 , v104
	.byte	W01
	.byte		N01   , Fn4 , v104
	.byte	W01
	.byte		N01   , Cn5 , v104
	.byte	W01
	.byte		N01   , Cn6 , v104
	.byte	W01
	@.byte		N06   , Cn7 , v112
	@.byte	W05
	@.byte		N06   , Cn7 , v112
	@.byte	W05
@ 008   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

se_shiny_crystal:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_shiny_crystal_pri	@ Priority
	.byte	se_shiny_crystal_rev	@ Reverb.

	.word	se_shiny_crystal_grp

	.word	se_shiny_crystal_1

	.end
