	.include "MPlayDef.s"

	.equ	se_shiny_grp, voicegroup127
	.equ	se_shiny_pri, 6
	.equ	se_shiny_rev, reverb_set+0
	.equ	se_shiny_mvl, 118
	.equ	se_shiny_key, 0
	.equ	se_shiny_tbs, 1
	.equ	se_shiny_exg, 1
	.equ	se_shiny_cmp, 1

	.section .rodata
	.global	se_shiny
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_shiny_1:
	.byte	KEYSH , se_shiny_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 210*se_shiny_tbs/2
	.byte		VOICE , 87
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 127*se_shiny_mvl/mxv
	.byte		BENDR , 1
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Cn5 , v120
	.byte	W02
	.byte		        Fn5 , v120
	.byte	W02
	.byte		        Cn6 , v120
	.byte	W02
	.byte		        Cn7 , v120
	.byte	W02
	.byte		VOICE , 88
	.byte		N24   , Cn8 , v127
	.byte	W24
@ 001   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

se_shiny:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_shiny_pri	@ Priority
	.byte	se_shiny_rev	@ Reverb.

	.word	se_shiny_grp

	.word	se_shiny_1

	.end
