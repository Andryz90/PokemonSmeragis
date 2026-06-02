	.include "MPlayDef.s"

	.equ	mus_areazero_battle_grp, voicegroup203
	.equ	mus_areazero_battle_pri, 2
	.equ	mus_areazero_battle_rev, 0
	.equ	mus_areazero_battle_mvl, 80
	.equ	mus_areazero_battle_key, 0
	.equ	mus_areazero_battle_tbs, 1
	.equ	mus_areazero_battle_exg, 1
	.equ	mus_areazero_battle_cmp, 1

	.section .rodata
	.global	mus_areazero_battle
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_areazero_battle_1:
	.byte		VOL   , 127*mus_areazero_battle_mvl/mxv
	.byte	KEYSH , mus_areazero_battle_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte	TEMPO , 146*mus_areazero_battle_tbs/2
	.byte		VOICE , 81
	.byte		N03   , Fs2 , v104
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		N02   , As2 
	.byte	W54
mus_areazero_battle_1_B1:
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
mus_areazero_battle_1_005:
	.byte		N24   , Fs2 , v104
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		N72   , Fn3 
	.byte	W48
	.byte	PEND
@ 006   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N72   , Fn3 
	.byte	W48
@ 007   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N96   , Fn3 
	.byte	W48
@ 008   ----------------------------------------
	.byte	W48
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 009   ----------------------------------------
	.byte		        Gs2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		TIE   , As2 
	.byte	W48
@ 010   ----------------------------------------
	.byte	W72
	.byte		EOT   
	.byte		N24   , Gs2 
	.byte	W24
@ 011   ----------------------------------------
	.byte		        As2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N96   , As2 
	.byte	W48
@ 012   ----------------------------------------
	.byte	W48
	.byte		N24   , Gs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
@ 013   ----------------------------------------
mus_areazero_battle_1_013:
	.byte		N24   , Fs2 , v104
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		N48   , Fn2 
	.byte	W48
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_1_005
@ 015   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs3 , v104
	.byte	W24
	.byte		TIE   , Fn3 
	.byte	W48
@ 016   ----------------------------------------
	.byte	W72
	.byte		EOT   
	.byte		N24   , Fs3 
	.byte	W24
@ 017   ----------------------------------------
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		TIE   , As3 
	.byte	W48
@ 018   ----------------------------------------
	.byte	W72
	.byte		EOT   
	.byte		N24   , Fs3 
	.byte	W24
@ 019   ----------------------------------------
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N96   , As3 
	.byte	W48
@ 020   ----------------------------------------
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 021   ----------------------------------------
	.byte		        Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W72
@ 022   ----------------------------------------
	.byte		N20   , Ds2 
	.byte		N20   , Fs2 
	.byte	W24
	.byte		        Fn2 
	.byte		N20   , Gs2 
	.byte	W24
	.byte		N72   , Fn3 
	.byte	W48
@ 023   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N48   , Fn3 
	.byte	W48
@ 024   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N84   , Fn3 
	.byte	W36
@ 025   ----------------------------------------
	.byte	W48
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W24
@ 026   ----------------------------------------
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N06   , As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		N96   , As2 
	.byte	W24
@ 027   ----------------------------------------
	.byte	W72
	.byte		N24   , Gs2 
	.byte	W24
@ 028   ----------------------------------------
	.byte		        As2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N06   , As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		N96   , As2 
	.byte	W24
@ 029   ----------------------------------------
	.byte	W72
	.byte		N24   , Gs2 
	.byte	W24
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_1_013
@ 031   ----------------------------------------
	.byte	W12
	.byte		N12   , Fs3 , v104
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N60   , Fn4 
	.byte	W48
@ 032   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N72   , Fn4 
	.byte	W24
@ 033   ----------------------------------------
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		        Fs4 
	.byte	W24
@ 034   ----------------------------------------
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N96   , As4 
	.byte	W24
@ 035   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs4 
	.byte	W24
@ 036   ----------------------------------------
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N90   , As4 
	.byte	W48
@ 037   ----------------------------------------
	.byte	W48
	.byte		N20   , Gs4 
	.byte	W24
	.byte		        As4 
	.byte	W24
@ 038   ----------------------------------------
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Fn3 
	.byte	W48
@ 039   ----------------------------------------
	.byte	W48
	.byte		N20   
	.byte	W48
@ 040   ----------------------------------------
	.byte	W48
	.byte		N17   , Gs3 
	.byte	W18
	.byte		N11   , As3 
	.byte	W30
@ 041   ----------------------------------------
	.byte		N17   , Ds3 
	.byte	W18
	.byte		N11   , Fn3 
	.byte	W30
	.byte		N17   , As2 
	.byte	W18
	.byte		N05   , Cs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 042   ----------------------------------------
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N05   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N32   , As3 
	.byte		N32   , Ds4 
	.byte	W24
@ 043   ----------------------------------------
	.byte	W12
	.byte		N07   , Gs3 
	.byte		N07   , Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte		N07   , Gs3 
	.byte	W12
	.byte		N07   
	.byte		N07   , As3 
	.byte	W12
	.byte		N11   , Ds3 
	.byte		N11   , As3 
	.byte	W18
	.byte		N05   , Fn3 
	.byte		N05   , As3 
	.byte	W06
	.byte		N05   
	.byte		N05   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N05   , Cs4 
	.byte	W06
	.byte		        Fn3 
	.byte		N05   , As3 
	.byte	W06
	.byte		        Ds3 
	.byte		N05   , Gs3 
	.byte	W06
@ 044   ----------------------------------------
	.byte		        Fs3 
	.byte		N05   , As3 
	.byte	W06
	.byte		        Ds3 
	.byte		N05   , Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N20   , An3 
	.byte	W30
	.byte		N05   , Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
@ 045   ----------------------------------------
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N11   , As3 
	.byte	W12
	.byte		N05   , Gs3 
	.byte	W06
	.byte		N11   , As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N05   , Ds4 
	.byte	W06
@ 046   ----------------------------------------
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N48   , Fs3 
	.byte		N48   , Gs3 
	.byte		N48   , As3 
	.byte		N48   , Cs4 
	.byte	W48
@ 047   ----------------------------------------
	.byte		N02   
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W90
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W72
	.byte		N11   , Fn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 060   ----------------------------------------
	.byte		N17   , Ds3 
	.byte	W24
	.byte		N44   , Fn3 
	.byte	W48
	.byte		N11   , Fn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 061   ----------------------------------------
	.byte		N17   , Fn3 
	.byte	W18
	.byte		        Fs3 
	.byte	W18
	.byte		N54   , As3 
	.byte	W60
@ 062   ----------------------------------------
	.byte		N20   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W72
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	mus_areazero_battle_1_B1
mus_areazero_battle_1_B2:
@ 071   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_areazero_battle_2:
	.byte		VOL   , 127*mus_areazero_battle_mvl/mxv
	.byte	KEYSH , mus_areazero_battle_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte		VOICE , 36
	.byte	W60
	.byte		N11   , Ds1 , v100
	.byte	W24
	.byte		N11   
	.byte	W12
mus_areazero_battle_2_B1:
@ 002   ----------------------------------------
mus_areazero_battle_2_002:
	.byte	W12
	.byte		N11   , Ds1 , v100
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	W12
	.byte		        Cs1 
	.byte	W24
	.byte		        An0 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_2_002
@ 005   ----------------------------------------
mus_areazero_battle_2_005:
	.byte	W12
	.byte		N11   , Ds1 , v100
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_2_005
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_2_005
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_2_005
@ 009   ----------------------------------------
	.byte	W12
	.byte		N11   , Ds1 , v100
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		N20   , Cs1 
	.byte	W36
	.byte		N11   , Bn0 
	.byte	W12
@ 010   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
@ 011   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 012   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 014   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte		N11   , Fs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
@ 015   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		        Cs1 
	.byte		N11   , Ds1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
@ 016   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		N20   , Ds1 
	.byte	W24
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 017   ----------------------------------------
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 018   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Bn0 
	.byte		N11   , Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 019   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		        Bn0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 020   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
@ 021   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N05   , Fs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W18
	.byte		N11   , Ds1 
	.byte	W12
	.byte		N05   , Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
@ 022   ----------------------------------------
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N20   , Gs0 
	.byte	W24
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
@ 023   ----------------------------------------
	.byte		N05   , Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N11   , Gs0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N05   , Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N17   , Gs0 
	.byte	W18
	.byte		        Ds1 
	.byte	W18
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
@ 025   ----------------------------------------
	.byte		N11   , Ds0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N20   , Ds0 
	.byte	W24
	.byte		N05   , Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
@ 026   ----------------------------------------
	.byte		        Fs0 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		N11   , Gs1 
	.byte	W12
	.byte		N05   , Gs0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , Ds1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
@ 028   ----------------------------------------
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N11   , Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 029   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 030   ----------------------------------------
	.byte		N05   , Cs2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N20   
	.byte	W24
	.byte		N05   , Ds1 
	.byte	W06
	.byte		N11   , Fn1 
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N11   , Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 032   ----------------------------------------
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 033   ----------------------------------------
	.byte		        As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N05   , Ds1 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , Fs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
@ 034   ----------------------------------------
	.byte		        Fn0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N05   , Fs0 
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , Bn0 
	.byte	W06
	.byte		N11   , As0 
	.byte	W12
	.byte		N32   , Bn0 
	.byte	W12
@ 035   ----------------------------------------
	.byte	W24
	.byte		N05   , As0 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N11   , Fs0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , Bn0 
	.byte	W06
	.byte		N11   , As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
@ 036   ----------------------------------------
	.byte		N05   , Fs0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , As0 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N11   , Fs0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		N05   , Fs0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , Bn0 
	.byte	W12
@ 037   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		N20   
	.byte	W24
	.byte		N11   
	.byte	W12
@ 038   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N05   , Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N11   , Bn0 
	.byte	W12
	.byte		N66   , Ds1 
	.byte	W48
@ 039   ----------------------------------------
	.byte	W24
	.byte		N11   , Fs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N20   , Ds1 
	.byte	W24
	.byte		N05   , Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 040   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		N05   , Fs1 
	.byte	W06
	.byte		N17   , Gs1 
	.byte	W30
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
@ 041   ----------------------------------------
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N11   , Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 042   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W24
	.byte		N05   , Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 043   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
@ 044   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte		N11   , As0 
	.byte	W12
	.byte		N05   , Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Ds0 
	.byte		N11   , As0 
	.byte	W06
	.byte		N05   , Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 045   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 046   ----------------------------------------
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N11   , Cs1 
	.byte	W12
	.byte		N03   , Ds0 
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N03   
	.byte	W04
	.byte		N11   , As0 
	.byte	W12
	.byte		N42   , Ds1 
	.byte	W48
@ 047   ----------------------------------------
	.byte		N20   , Ds0 
	.byte	W24
	.byte		N17   , En1 
	.byte	W18
	.byte		N05   
	.byte	W06
	.byte		N36   , Ds0 , v100, gtp2
	.byte	W42
	.byte		N05   
	.byte	W06
@ 048   ----------------------------------------
	.byte		N32   , As0 
	.byte	W36
	.byte		N11   
	.byte	W12
	.byte		N20   , Ds0 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
@ 049   ----------------------------------------
	.byte		        Cs1 
	.byte	W24
	.byte		        As0 
	.byte	W24
	.byte		        An0 
	.byte	W24
	.byte		        Gs0 
	.byte	W24
@ 050   ----------------------------------------
	.byte		        Fs0 
	.byte	W24
	.byte		        Ds0 
	.byte	W24
	.byte		N42   
	.byte	W48
@ 051   ----------------------------------------
	.byte		        Fs1 
	.byte	W48
	.byte		N11   , Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N05   , Cs1 
	.byte	W06
	.byte		N17   , Ds1 
	.byte	W18
@ 052   ----------------------------------------
	.byte		N11   , Gs0 
	.byte	W18
	.byte		N05   , As0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
@ 053   ----------------------------------------
	.byte		N05   , Gs0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
@ 054   ----------------------------------------
	.byte		        Fs0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 055   ----------------------------------------
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , Dn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 056   ----------------------------------------
	.byte		        Fs0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , Gs0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N17   , Ds1 
	.byte	W18
	.byte		N11   , Ds0 
	.byte	W12
@ 057   ----------------------------------------
	.byte		N05   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N11   , Ds0 
	.byte	W12
@ 058   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N11   , Bn0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		        As0 
	.byte	W06
@ 059   ----------------------------------------
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 060   ----------------------------------------
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Fn0 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		        As0 
	.byte	W18
	.byte		N11   , Ds0 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
@ 061   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N05   , Gs0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		        Fn0 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 062   ----------------------------------------
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		        Ds1 
	.byte	W54
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W48
	.byte		N11   
	.byte	W12
	.byte		N05   , Fs0 
	.byte	W06
	.byte		N11   , Gs0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N11   , As0 
	.byte	W12
@ 067   ----------------------------------------
	.byte		        Gs0 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N11   , As0 
	.byte	W12
	.byte		N05   , Ds0 
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N05   , Bn0 
	.byte	W06
	.byte		        As0 
	.byte	W06
@ 068   ----------------------------------------
	.byte		N11   , An0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		N05   , Ds0 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N05   , Bn0 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N17   , Cs1 
	.byte	W18
	.byte		N11   , As0 
	.byte	W06
@ 069   ----------------------------------------
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N05   , An0 
	.byte	W06
	.byte		N11   , Gs0 
	.byte	W12
	.byte		N42   , Fn1 
	.byte	W48
@ 070   ----------------------------------------
	.byte		N20   , Ds1 
	.byte	W24
	.byte		        Bn0 
	.byte	W36
	.byte		N11   , Ds1 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	GOTO
	 .word	mus_areazero_battle_2_B1
mus_areazero_battle_2_B2:
@ 071   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_areazero_battle_3:
	.byte		VOL   , 127*mus_areazero_battle_mvl/mxv
	.byte	KEYSH , mus_areazero_battle_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte		VOICE , 48
	.byte	W60
	.byte		N11   , Fn3 , v096
	.byte	W24
	.byte		N11   
	.byte	W12
mus_areazero_battle_3_B1:
@ 002   ----------------------------------------
mus_areazero_battle_3_002:
	.byte	W12
	.byte		N11   , Fn3 , v096
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_002
@ 005   ----------------------------------------
mus_areazero_battle_3_005:
	.byte	W12
	.byte		N11   , Fn3 , v096
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_002
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_005
@ 009   ----------------------------------------
	.byte	W12
	.byte		N11   , Ds3 , v096
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N11   
	.byte	W12
@ 010   ----------------------------------------
mus_areazero_battle_3_010:
	.byte	W12
	.byte		N11   , As2 , v096
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_010
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_010
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_005
@ 014   ----------------------------------------
	.byte	W12
	.byte		N11   , Fn3 , v096
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte		N11   , Fn4 
	.byte	W12
	.byte		        Fs3 
	.byte		N11   , Fs4 
	.byte	W12
	.byte		        Cs3 
	.byte		N11   , Cs4 
	.byte	W12
	.byte		        Ds3 
	.byte		N11   , Ds4 
	.byte	W12
@ 015   ----------------------------------------
	.byte		        As2 
	.byte		N11   , As3 
	.byte	W12
	.byte		        Cs3 
	.byte		N11   , Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte		N11   , Fs4 
	.byte	W12
	.byte		        Gs3 
	.byte		N11   , Gs4 
	.byte	W12
	.byte		        Fn3 
	.byte		N11   , Fn4 
	.byte	W12
	.byte		        Fs3 
	.byte		N11   , Fs4 
	.byte	W36
@ 016   ----------------------------------------
mus_areazero_battle_3_016:
	.byte	W48
	.byte		N11   , Fn3 , v096
	.byte		N11   , Fn4 
	.byte	W12
	.byte		        Fs3 
	.byte		N11   , Fs4 
	.byte	W12
	.byte		        Cs3 
	.byte		N11   , Cs4 
	.byte	W12
	.byte		        Ds3 
	.byte		N11   , Ds4 
	.byte	W12
	.byte	PEND
@ 017   ----------------------------------------
mus_areazero_battle_3_017:
	.byte		N11   , As2 , v096
	.byte		N11   , As3 
	.byte	W12
	.byte		        Cs3 
	.byte		N11   , Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte		N11   , Fs4 
	.byte	W12
	.byte		        Gs3 
	.byte		N11   , Gs4 
	.byte	W60
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_016
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_017
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_016
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_017
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_016
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_3_017
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W60
	.byte		N11   , Fn3 , v096
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte	GOTO
	 .word	mus_areazero_battle_3_B1
mus_areazero_battle_3_B2:
@ 071   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_areazero_battle_4:
	.byte		VOL   , 127*mus_areazero_battle_mvl/mxv
	.byte	KEYSH , mus_areazero_battle_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte		VOICE , 13
	.byte	W48
	.byte		N11   , As3 , v100
	.byte	W12
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W18
mus_areazero_battle_4_B1:
@ 002   ----------------------------------------
mus_areazero_battle_4_002:
	.byte		N11   , As3 , v100
	.byte	W12
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W18
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 012   ----------------------------------------
	.byte		N11   , As3 , v100
	.byte	W12
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W36
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 021   ----------------------------------------
mus_areazero_battle_4_021:
	.byte		N11   , As3 , v100
	.byte	W12
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W66
	.byte	PEND
@ 022   ----------------------------------------
mus_areazero_battle_4_022:
	.byte	W48
	.byte		N11   , As3 , v100
	.byte	W12
	.byte		N11   
	.byte	W18
	.byte		N11   
	.byte	W18
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_021
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_022
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_4_002
	.byte	GOTO
	 .word	mus_areazero_battle_4_B1
mus_areazero_battle_4_B2:
@ 071   ----------------------------------------
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_areazero_battle_5:
	.byte		VOL   , 127*mus_areazero_battle_mvl/mxv
	.byte	KEYSH , mus_areazero_battle_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte		VOICE , 80
	.byte	W96
mus_areazero_battle_5_B1:
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte		N24   , Fs3 , v100
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N72   , Fn4 
	.byte	W48
@ 006   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N72   , Fn4 
	.byte	W48
@ 007   ----------------------------------------
	.byte	W24
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N96   , Fn4 
	.byte	W48
@ 008   ----------------------------------------
	.byte	W48
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
@ 009   ----------------------------------------
	.byte		        Gs3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		TIE   , As3 
	.byte	W48
@ 010   ----------------------------------------
	.byte	W72
	.byte		EOT   
	.byte		N24   , Gs3 
	.byte	W24
@ 011   ----------------------------------------
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N96   , As3 
	.byte	W48
@ 012   ----------------------------------------
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 013   ----------------------------------------
	.byte		        Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N48   , Fn3 
	.byte	W48
@ 014   ----------------------------------------
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N72   
	.byte		N72   , Fn4 
	.byte	W48
@ 015   ----------------------------------------
	.byte	W24
	.byte		N24   , As3 
	.byte		N24   , Fs4 
	.byte	W24
	.byte		TIE   , Gs3 
	.byte		TIE   , Fn4 
	.byte	W48
@ 016   ----------------------------------------
	.byte	W72
	.byte		EOT   , Gs3 
	.byte		        Fn4 
	.byte		N24   , As3 
	.byte		N24   , Fs4 
	.byte	W24
@ 017   ----------------------------------------
	.byte		        Fn4 
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Ds4 
	.byte		N24   , Bn4 
	.byte	W24
	.byte		TIE   , Cs4 
	.byte		TIE   , As4 
	.byte	W48
@ 018   ----------------------------------------
	.byte	W72
	.byte		EOT   , Cs4 
	.byte		        As4 
	.byte		N24   , As3 
	.byte		N24   , Fs4 
	.byte	W24
@ 019   ----------------------------------------
	.byte		        Fn4 
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Ds4 
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N96   , Cs4 
	.byte		N96   , As4 
	.byte	W48
@ 020   ----------------------------------------
	.byte	W48
	.byte		N24   , Bn3 
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Cs4 
	.byte		N24   , As4 
	.byte	W24
@ 021   ----------------------------------------
	.byte		        As3 
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Bn3 
	.byte		N24   , Gs4 
	.byte	W72
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W48
	.byte		N20   , Ds1 
	.byte	W24
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 047   ----------------------------------------
mus_areazero_battle_5_047:
	.byte		N17   , Cs2 , v100
	.byte	W18
	.byte		        Ds2 
	.byte	W54
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 048   ----------------------------------------
mus_areazero_battle_5_048:
	.byte		N17   , Ds2 , v100
	.byte	W18
	.byte		N48   , Fn2 , v100, gtp2
	.byte	W54
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 049   ----------------------------------------
mus_areazero_battle_5_049:
	.byte		N17   , Fn2 , v100
	.byte	W18
	.byte		        Fs2 
	.byte	W18
	.byte		N54   , Fn2 
	.byte	W60
	.byte	PEND
@ 050   ----------------------------------------
mus_areazero_battle_5_050:
	.byte		N20   , Ds2 , v100
	.byte	W24
	.byte		        Bn1 
	.byte	W48
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 051   ----------------------------------------
mus_areazero_battle_5_051:
	.byte		N17   , Cs2 , v100
	.byte	W18
	.byte		N11   , Ds2 
	.byte	W54
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 052   ----------------------------------------
mus_areazero_battle_5_052:
	.byte		N17   , Ds2 , v100
	.byte	W24
	.byte		N44   , Fn2 
	.byte	W48
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 053   ----------------------------------------
mus_areazero_battle_5_053:
	.byte		N17   , Fn2 , v100
	.byte	W18
	.byte		        Fs2 
	.byte	W18
	.byte		N54   , As2 
	.byte	W60
	.byte	PEND
@ 054   ----------------------------------------
	.byte		N20   , Gs2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		N11   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_047
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_048
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_049
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_050
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_051
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_052
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_5_053
@ 062   ----------------------------------------
	.byte		N20   , Gs2 , v100
	.byte	W24
	.byte		        Fs2 
	.byte	W72
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	mus_areazero_battle_5_B1
mus_areazero_battle_5_B2:
@ 071   ----------------------------------------
	.byte	FINE

@**************** Track 6 (Midi-Chn.10) ****************@

mus_areazero_battle_6:
	.byte		VOL   , 127*mus_areazero_battle_mvl/mxv
	.byte	KEYSH , mus_areazero_battle_key+0
@ 000   ----------------------------------------
@ 001   ----------------------------------------
	.byte		VOICE , 0
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn2 , v100
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N05   , Ds1 , v100
	.byte	W06
	.byte		N05   
	.byte	W18
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
mus_areazero_battle_6_B1:
@ 002   ----------------------------------------
mus_areazero_battle_6_002:
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 005   ----------------------------------------
mus_areazero_battle_6_005:
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N05   , Bn1 , v100
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 021   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , As1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N05   , Ds1 , v100
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
@ 022   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N05   , Dn2 , v100
	.byte	W06
	.byte		N17   
	.byte	W18
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 043   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 046   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N20   , Fs1 , v100
	.byte		N20   , Bn1 
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte		N05   , Fs1 , v100
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 047   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte	W24
	.byte		N12   
	.byte		N20   , Fs1 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte		N20   , Bn1 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Ds1 , v100
	.byte	W12
@ 048   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W18
	.byte		N05   , Ds1 
	.byte	W06
	.byte		N12   , Cn1 , v092
	.byte		N11   , Ds1 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte		N20   , Fs1 , v100
	.byte		N20   , Bn1 
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
@ 049   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte		N05   , Fs1 , v100
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N12   , Cn1 , v092
	.byte		N20   , Bn1 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte	W18
	.byte		N05   , Bn1 , v100
	.byte	W06
@ 050   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W12
	.byte		N05   , Fs1 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N12   , Cn1 , v092
	.byte		N11   , Fs1 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte		N05   , Fs1 , v100
	.byte		N20   , Bn1 
	.byte	W06
	.byte		N05   , Fs1 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N12   , Cn1 , v092
	.byte		N05   , Fs1 , v100
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 051   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N05   , Fs1 , v100
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   , As1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
@ 052   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , As1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
@ 053   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Fs1 , v100
	.byte	W24
	.byte		N12   , Cn1 , v092
	.byte	W06
	.byte		N05   , Fs1 , v100
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W06
	.byte		N11   , Fs1 , v100
	.byte	W18
@ 054   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N05   , Fs1 , v100
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N12   , Cn1 , v092
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
@ 055   ----------------------------------------
mus_areazero_battle_6_055:
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N05   , Fs1 , v100
	.byte		N05   , Bn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte	PEND
@ 056   ----------------------------------------
mus_areazero_battle_6_056:
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte	PEND
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_055
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_056
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_055
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_056
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_055
@ 062   ----------------------------------------
	.byte		N12   , Cn1 , v092
	.byte		N11   , Dn2 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		N11   , Fs1 , v100
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte		N11   , Bn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_005
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_areazero_battle_6_002
	.byte	GOTO
	 .word	mus_areazero_battle_6_B1
mus_areazero_battle_6_B2:
@ 071   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

mus_areazero_battle:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_areazero_battle_pri	@ Priority
	.byte	mus_areazero_battle_rev	@ Reverb.

	.word	mus_areazero_battle_grp

	.word	mus_areazero_battle_1
	.word	mus_areazero_battle_2
	.word	mus_areazero_battle_3
	.word	mus_areazero_battle_4
	.word	mus_areazero_battle_5
	.word	mus_areazero_battle_6

	.end
