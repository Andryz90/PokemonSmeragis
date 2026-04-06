	.arch armv4t
	.fpu softvfp
	.file	"<stdin>"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 1 "<stdin>"
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	WriteCommand, %function
WriteCommand:
.LVL0:
.LFB11:
	.file 2 "src/siirtc.c"
	.loc 2 387 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 387 1 is_stmt 0 view .LVU1
	push	{r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 2 388 5 is_stmt 1 view .LVU2
	.loc 2 389 5 view .LVU3
	.loc 2 391 5 view .LVU4
.LVL1:
	.loc 2 391 12 is_stmt 0 view .LVU5
	movs	r1, #0
	.loc 2 391 5 view .LVU6
	b	.L2
.LVL2:
.L3:
	.loc 2 393 9 is_stmt 1 discriminator 3 view .LVU7
	.loc 2 393 30 is_stmt 0 discriminator 3 view .LVU8
	movs	r3, #7
	subs	r3, r3, r1
	.loc 2 393 24 discriminator 3 view .LVU9
	movs	r2, r0
	asrs	r2, r2, r3
	.loc 2 393 36 discriminator 3 view .LVU10
	lsls	r2, r2, #24
	lsrs	r2, r2, #24
	.loc 2 393 14 discriminator 3 view .LVU11
	movs	r3, #1
	ands	r3, r2
.LVL3:
	.loc 2 394 9 is_stmt 1 discriminator 3 view .LVU12
	.loc 2 394 44 is_stmt 0 discriminator 3 view .LVU13
	lsls	r3, r3, #1
.LVL4:
	.loc 2 394 44 discriminator 3 view .LVU14
	movs	r2, #4
.LVL5:
	.loc 2 394 44 discriminator 3 view .LVU15
	orrs	r2, r3
	lsls	r2, r2, #16
	lsrs	r2, r2, #16
	.loc 2 394 30 discriminator 3 view .LVU16
	ldr	r4, .L4
	strh	r2, [r4]
	.loc 2 395 9 is_stmt 1 discriminator 3 view .LVU17
	.loc 2 395 30 is_stmt 0 discriminator 3 view .LVU18
	strh	r2, [r4]
	.loc 2 396 9 is_stmt 1 discriminator 3 view .LVU19
	.loc 2 396 30 is_stmt 0 discriminator 3 view .LVU20
	strh	r2, [r4]
	.loc 2 397 9 is_stmt 1 discriminator 3 view .LVU21
	.loc 2 397 48 is_stmt 0 discriminator 3 view .LVU22
	movs	r2, #5
	orrs	r3, r2
	lsls	r3, r3, #16
	lsrs	r3, r3, #16
	.loc 2 397 30 discriminator 3 view .LVU23
	strh	r3, [r4]
	.loc 2 391 25 is_stmt 1 discriminator 3 view .LVU24
	adds	r1, r1, #1
.LVL6:
	.loc 2 391 25 is_stmt 0 discriminator 3 view .LVU25
	lsls	r1, r1, #24
.LVL7:
	.loc 2 391 25 discriminator 3 view .LVU26
	lsrs	r1, r1, #24
.LVL8:
.L2:
	.loc 2 391 19 is_stmt 1 discriminator 1 view .LVU27
	cmp	r1, #7
	bls	.L3
	.loc 2 403 5 view .LVU28
	.loc 2 405 1 is_stmt 0 view .LVU29
	movs	r0, #0
.LVL9:
	.loc 2 405 1 view .LVU30
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
.L5:
	.align	2
.L4:
	.word	134217924
	.cfi_endproc
.LFE11:
	.size	WriteCommand, .-WriteCommand
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	WriteData, %function
WriteData:
.LVL10:
.LFB12:
	.loc 2 408 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 408 1 is_stmt 0 view .LVU32
	push	{r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	.loc 2 409 5 is_stmt 1 view .LVU33
	.loc 2 410 5 view .LVU34
	.loc 2 412 5 view .LVU35
.LVL11:
	.loc 2 412 12 is_stmt 0 view .LVU36
	movs	r1, #0
	.loc 2 412 5 view .LVU37
	b	.L7
.LVL12:
.L8:
	.loc 2 414 9 is_stmt 1 discriminator 3 view .LVU38
	.loc 2 414 24 is_stmt 0 discriminator 3 view .LVU39
	movs	r2, r0
	asrs	r2, r2, r1
	.loc 2 414 30 discriminator 3 view .LVU40
	lsls	r2, r2, #24
	lsrs	r2, r2, #24
	.loc 2 414 14 discriminator 3 view .LVU41
	movs	r3, #1
	ands	r3, r2
.LVL13:
	.loc 2 415 9 is_stmt 1 discriminator 3 view .LVU42
	.loc 2 415 44 is_stmt 0 discriminator 3 view .LVU43
	lsls	r3, r3, #1
.LVL14:
	.loc 2 415 44 discriminator 3 view .LVU44
	movs	r2, #4
.LVL15:
	.loc 2 415 44 discriminator 3 view .LVU45
	orrs	r2, r3
	lsls	r2, r2, #16
	lsrs	r2, r2, #16
	.loc 2 415 30 discriminator 3 view .LVU46
	ldr	r4, .L9
	strh	r2, [r4]
	.loc 2 416 9 is_stmt 1 discriminator 3 view .LVU47
	.loc 2 416 30 is_stmt 0 discriminator 3 view .LVU48
	strh	r2, [r4]
	.loc 2 417 9 is_stmt 1 discriminator 3 view .LVU49
	.loc 2 417 30 is_stmt 0 discriminator 3 view .LVU50
	strh	r2, [r4]
	.loc 2 418 9 is_stmt 1 discriminator 3 view .LVU51
	.loc 2 418 48 is_stmt 0 discriminator 3 view .LVU52
	movs	r2, #5
	orrs	r3, r2
	lsls	r3, r3, #16
	lsrs	r3, r3, #16
	.loc 2 418 30 discriminator 3 view .LVU53
	strh	r3, [r4]
	.loc 2 412 25 is_stmt 1 discriminator 3 view .LVU54
	adds	r1, r1, #1
.LVL16:
	.loc 2 412 25 is_stmt 0 discriminator 3 view .LVU55
	lsls	r1, r1, #24
.LVL17:
	.loc 2 412 25 discriminator 3 view .LVU56
	lsrs	r1, r1, #24
.LVL18:
.L7:
	.loc 2 412 19 is_stmt 1 discriminator 1 view .LVU57
	cmp	r1, #7
	bls	.L8
	.loc 2 424 5 view .LVU58
	.loc 2 426 1 is_stmt 0 view .LVU59
	movs	r0, #0
.LVL19:
	.loc 2 426 1 view .LVU60
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
.L10:
	.align	2
.L9:
	.word	134217924
	.cfi_endproc
.LFE12:
	.size	WriteData, .-WriteData
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	ReadData, %function
ReadData:
.LFB13:
	.loc 2 429 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 2 430 5 view .LVU62
	.loc 2 431 5 view .LVU63
	.loc 2 432 5 view .LVU64
	.loc 2 435 5 view .LVU65
.LVL20:
	.loc 2 438 5 view .LVU66
	.loc 2 435 11 is_stmt 0 view .LVU67
	movs	r0, #0
	.loc 2 438 12 view .LVU68
	movs	r2, #0
	.loc 2 438 5 view .LVU69
	b	.L12
.LVL21:
.L13:
	.loc 2 440 9 is_stmt 1 discriminator 3 view .LVU70
	.loc 2 440 30 is_stmt 0 discriminator 3 view .LVU71
	ldr	r3, .L14
	movs	r1, #4
	strh	r1, [r3]
	.loc 2 441 9 is_stmt 1 discriminator 3 view .LVU72
	.loc 2 441 30 is_stmt 0 discriminator 3 view .LVU73
	strh	r1, [r3]
	.loc 2 442 9 is_stmt 1 discriminator 3 view .LVU74
	.loc 2 442 30 is_stmt 0 discriminator 3 view .LVU75
	strh	r1, [r3]
	.loc 2 443 9 is_stmt 1 discriminator 3 view .LVU76
	.loc 2 443 30 is_stmt 0 discriminator 3 view .LVU77
	strh	r1, [r3]
	.loc 2 444 9 is_stmt 1 discriminator 3 view .LVU78
	.loc 2 444 30 is_stmt 0 discriminator 3 view .LVU79
	strh	r1, [r3]
	.loc 2 445 9 is_stmt 1 discriminator 3 view .LVU80
	.loc 2 445 30 is_stmt 0 discriminator 3 view .LVU81
	adds	r1, r1, #1
	strh	r1, [r3]
	.loc 2 447 9 is_stmt 1 discriminator 3 view .LVU82
	.loc 2 447 19 is_stmt 0 discriminator 3 view .LVU83
	ldrh	r3, [r3]
	.loc 2 447 44 discriminator 3 view .LVU84
	lsrs	r3, r3, #1
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	.loc 2 447 14 discriminator 3 view .LVU85
	subs	r1, r1, #4
	ands	r3, r1
.LVL22:
	.loc 2 448 9 is_stmt 1 discriminator 3 view .LVU86
	.loc 2 448 30 is_stmt 0 discriminator 3 view .LVU87
	lsrs	r0, r0, #1
.LVL23:
	.loc 2 448 38 discriminator 3 view .LVU88
	lsls	r3, r3, #7
.LVL24:
	.loc 2 448 15 discriminator 3 view .LVU89
	orrs	r0, r3
.LVL25:
	.loc 2 438 25 is_stmt 1 discriminator 3 view .LVU90
	adds	r2, r2, #1
.LVL26:
	.loc 2 438 25 is_stmt 0 discriminator 3 view .LVU91
	lsls	r2, r2, #24
	lsrs	r2, r2, #24
.LVL27:
.L12:
	.loc 2 438 19 is_stmt 1 discriminator 1 view .LVU92
	cmp	r2, #7
	bls	.L13
	.loc 2 451 5 view .LVU93
	.loc 2 452 1 is_stmt 0 view .LVU94
	@ sp needed
	bx	lr
.L15:
	.align	2
.L14:
	.word	134217924
	.cfi_endproc
.LFE13:
	.size	ReadData, .-ReadData
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	EnableGpioPortRead, %function
EnableGpioPortRead:
.LFB14:
	.loc 2 455 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 2 456 5 view .LVU96
	.loc 2 456 26 is_stmt 0 view .LVU97
	ldr	r3, .L17
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 457 1 view .LVU98
	@ sp needed
	bx	lr
.L18:
	.align	2
.L17:
	.word	134217928
	.cfi_endproc
.LFE14:
	.size	EnableGpioPortRead, .-EnableGpioPortRead
	.align	1
	.syntax unified
	.code	16
	.thumb_func
	.type	DisableGpioPortRead, %function
DisableGpioPortRead:
.LFB15:
	.loc 2 460 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	.loc 2 461 5 view .LVU100
	.loc 2 461 26 is_stmt 0 view .LVU101
	ldr	r3, .L20
	movs	r2, #0
	strh	r2, [r3]
	.loc 2 462 1 view .LVU102
	@ sp needed
	bx	lr
.L21:
	.align	2
.L20:
	.word	134217928
	.cfi_endproc
.LFE15:
	.size	DisableGpioPortRead, .-DisableGpioPortRead
	.align	1
	.global	SiiRtcUnprotect
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcUnprotect, %function
SiiRtcUnprotect:
.LFB0:
	.loc 2 81 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	.loc 2 82 5 view .LVU104
	bl	EnableGpioPortRead
.LVL28:
	.loc 2 83 5 view .LVU105
	.loc 2 83 13 is_stmt 0 view .LVU106
	ldr	r3, .L23
	movs	r2, #0
	strb	r2, [r3]
	.loc 2 84 1 view .LVU107
	@ sp needed
	pop	{r0}
	bx	r0
.L24:
	.align	2
.L23:
	.word	.LANCHOR0
	.cfi_endproc
.LFE0:
	.size	SiiRtcUnprotect, .-SiiRtcUnprotect
	.align	1
	.global	SiiRtcProtect
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcProtect, %function
SiiRtcProtect:
.LFB1:
	.loc 2 87 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{lr}
	.cfi_def_cfa_offset 4
	.cfi_offset 14, -4
	.loc 2 88 5 view .LVU109
	bl	DisableGpioPortRead
.LVL29:
	.loc 2 89 5 view .LVU110
	.loc 2 89 13 is_stmt 0 view .LVU111
	ldr	r3, .L26
	movs	r2, #1
	strb	r2, [r3]
	.loc 2 90 1 view .LVU112
	@ sp needed
	pop	{r0}
	bx	r0
.L27:
	.align	2
.L26:
	.word	.LANCHOR0
	.cfi_endproc
.LFE1:
	.size	SiiRtcProtect, .-SiiRtcProtect
	.align	1
	.global	SiiRtcGetStatus
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcGetStatus, %function
SiiRtcGetStatus:
.LVL30:
.LFB4:
	.loc 2 167 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 4
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 167 1 is_stmt 0 view .LVU114
	push	{r4, r5, r6, r7, lr}
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	mov	lr, r9
	push	{lr}
	.cfi_def_cfa_offset 24
	.cfi_offset 9, -24
	sub	sp, sp, #4
	.cfi_def_cfa_offset 28
	str	r0, [sp]
	.loc 2 168 5 is_stmt 1 view .LVU115
	.loc 2 170 5 view .LVU116
	.loc 2 170 17 is_stmt 0 view .LVU117
	ldr	r3, .L31
	ldrb	r3, [r3]
	.loc 2 170 8 view .LVU118
	cmp	r3, #1
	beq	.L30
	.loc 2 173 5 is_stmt 1 view .LVU119
	.loc 2 173 13 is_stmt 0 view .LVU120
	ldr	r5, .L31
	movs	r7, #1
	strb	r7, [r5]
	.loc 2 175 5 is_stmt 1 view .LVU121
	.loc 2 175 26 is_stmt 0 view .LVU122
	ldr	r6, .L31+4
	strh	r7, [r6]
	.loc 2 176 5 is_stmt 1 view .LVU123
	.loc 2 176 26 is_stmt 0 view .LVU124
	movs	r3, #5
	mov	r9, r3
	strh	r3, [r6]
	.loc 2 178 5 is_stmt 1 view .LVU125
	.loc 2 178 26 is_stmt 0 view .LVU126
	ldr	r4, .L31+8
	adds	r3, r3, #2
	strh	r3, [r4]
	.loc 2 180 5 is_stmt 1 view .LVU127
	movs	r0, #99
.LVL31:
	.loc 2 180 5 is_stmt 0 view .LVU128
	bl	WriteCommand
.LVL32:
	.loc 2 182 5 is_stmt 1 view .LVU129
	.loc 2 182 26 is_stmt 0 view .LVU130
	mov	r3, r9
	strh	r3, [r4]
	.loc 2 184 5 is_stmt 1 view .LVU131
	.loc 2 184 18 is_stmt 0 view .LVU132
	bl	ReadData
.LVL33:
	.loc 2 186 5 is_stmt 1 view .LVU133
	.loc 2 186 31 is_stmt 0 view .LVU134
	movs	r3, #63
	movs	r2, r0
	bics	r2, r3
	lsls	r3, r2, #24
	asrs	r3, r3, #24
	.loc 2 187 40 view .LVU135
	asrs	r1, r0, #3
	movs	r2, #4
	ands	r2, r1
	.loc 2 187 17 view .LVU136
	orrs	r3, r2
	lsls	r3, r3, #24
	asrs	r3, r3, #24
	.loc 2 188 40 view .LVU137
	asrs	r1, r0, #2
	movs	r2, #2
	ands	r2, r1
	.loc 2 188 17 view .LVU138
	orrs	r3, r2
	lsls	r3, r3, #24
	asrs	r3, r3, #24
	.loc 2 189 40 view .LVU139
	asrs	r0, r0, #1
.LVL34:
	.loc 2 189 40 view .LVU140
	movs	r2, #1
	ands	r2, r0
	.loc 2 189 17 view .LVU141
	orrs	r3, r2
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	.loc 2 186 17 view .LVU142
	ldr	r2, [sp]
	strb	r3, [r2, #7]
	.loc 2 191 5 is_stmt 1 view .LVU143
	.loc 2 191 26 is_stmt 0 view .LVU144
	strh	r7, [r6]
	.loc 2 192 5 is_stmt 1 view .LVU145
	.loc 2 192 26 is_stmt 0 view .LVU146
	strh	r7, [r6]
	.loc 2 194 5 is_stmt 1 view .LVU147
	.loc 2 194 13 is_stmt 0 view .LVU148
	movs	r3, #0
	strb	r3, [r5]
	.loc 2 196 5 is_stmt 1 view .LVU149
	.loc 2 196 12 is_stmt 0 view .LVU150
	movs	r0, #1
.LVL35:
.L29:
	.loc 2 197 1 view .LVU151
	add	sp, sp, #4
	@ sp needed
	pop	{r7}
	mov	r9, r7
	pop	{r4, r5, r6, r7}
	pop	{r1}
	bx	r1
.LVL36:
.L30:
	.loc 2 171 16 view .LVU152
	movs	r0, #0
.LVL37:
	.loc 2 171 16 view .LVU153
	b	.L29
.L32:
	.align	2
.L31:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE4:
	.size	SiiRtcGetStatus, .-SiiRtcGetStatus
	.align	1
	.global	SiiRtcSetStatus
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcSetStatus, %function
SiiRtcSetStatus:
.LVL38:
.LFB5:
	.loc 2 200 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 200 1 is_stmt 0 view .LVU155
	push	{r4, r5, r6, r7, lr}
	.cfi_def_cfa_offset 20
	.cfi_offset 4, -20
	.cfi_offset 5, -16
	.cfi_offset 6, -12
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	.loc 2 201 5 is_stmt 1 view .LVU156
	.loc 2 203 5 view .LVU157
	.loc 2 203 17 is_stmt 0 view .LVU158
	ldr	r3, .L36
	ldrb	r3, [r3]
	.loc 2 203 8 view .LVU159
	cmp	r3, #1
	beq	.L35
	.loc 2 206 5 is_stmt 1 view .LVU160
	.loc 2 206 13 is_stmt 0 view .LVU161
	ldr	r5, .L36
	movs	r7, #1
	strb	r7, [r5]
	.loc 2 208 5 is_stmt 1 view .LVU162
	.loc 2 208 26 is_stmt 0 view .LVU163
	ldr	r6, .L36+4
	strh	r7, [r6]
	.loc 2 209 5 is_stmt 1 view .LVU164
	.loc 2 209 26 is_stmt 0 view .LVU165
	movs	r3, #5
	strh	r3, [r6]
	.loc 2 211 5 is_stmt 1 view .LVU166
	.loc 2 212 23 is_stmt 0 view .LVU167
	ldrb	r3, [r0, #7]
	.loc 2 212 40 view .LVU168
	lsls	r2, r3, #3
	movs	r4, #32
	ands	r4, r2
	.loc 2 212 16 view .LVU169
	movs	r2, #64
	orrs	r4, r2
	lsls	r4, r4, #24
	asrs	r4, r4, #24
	.loc 2 213 40 view .LVU170
	lsls	r1, r3, #2
	movs	r2, #8
	ands	r2, r1
	.loc 2 213 16 view .LVU171
	orrs	r4, r2
	.loc 2 214 40 view .LVU172
	lsls	r3, r3, #1
	movs	r2, #2
	ands	r3, r2
	.loc 2 211 16 view .LVU173
	orrs	r4, r3
.LVL39:
	.loc 2 216 5 is_stmt 1 view .LVU174
	.loc 2 216 26 is_stmt 0 view .LVU175
	ldr	r3, .L36+8
	adds	r2, r2, #5
	strh	r2, [r3]
	.loc 2 218 5 is_stmt 1 view .LVU176
	movs	r0, #98
.LVL40:
	.loc 2 218 5 is_stmt 0 view .LVU177
	bl	WriteCommand
.LVL41:
	.loc 2 220 5 is_stmt 1 view .LVU178
	movs	r0, r4
	bl	WriteData
.LVL42:
	.loc 2 222 5 view .LVU179
	.loc 2 222 26 is_stmt 0 view .LVU180
	strh	r7, [r6]
	.loc 2 223 5 is_stmt 1 view .LVU181
	.loc 2 223 26 is_stmt 0 view .LVU182
	strh	r7, [r6]
	.loc 2 225 5 is_stmt 1 view .LVU183
	.loc 2 225 13 is_stmt 0 view .LVU184
	movs	r3, #0
	strb	r3, [r5]
	.loc 2 227 5 is_stmt 1 view .LVU185
	.loc 2 227 12 is_stmt 0 view .LVU186
	movs	r0, #1
.LVL43:
.L34:
	.loc 2 228 1 view .LVU187
	@ sp needed
	pop	{r4, r5, r6, r7}
	pop	{r1}
	bx	r1
.LVL44:
.L35:
	.loc 2 204 16 view .LVU188
	movs	r0, #0
.LVL45:
	.loc 2 204 16 view .LVU189
	b	.L34
.L37:
	.align	2
.L36:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE5:
	.size	SiiRtcSetStatus, .-SiiRtcSetStatus
	.align	1
	.global	SiiRtcReset
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcReset, %function
SiiRtcReset:
.LFB3:
	.loc 2 138 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 12
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, lr}
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 28
	.loc 2 139 5 view .LVU191
	.loc 2 140 5 view .LVU192
	.loc 2 142 5 view .LVU193
	.loc 2 142 17 is_stmt 0 view .LVU194
	ldr	r3, .L41
	ldrb	r3, [r3]
	.loc 2 142 8 view .LVU195
	cmp	r3, #1
	beq	.L40
	.loc 2 145 5 is_stmt 1 view .LVU196
	.loc 2 145 13 is_stmt 0 view .LVU197
	ldr	r4, .L41
	movs	r6, #1
	strb	r6, [r4]
	.loc 2 147 5 is_stmt 1 view .LVU198
	.loc 2 147 26 is_stmt 0 view .LVU199
	ldr	r5, .L41+4
	strh	r6, [r5]
	.loc 2 148 5 is_stmt 1 view .LVU200
	.loc 2 148 26 is_stmt 0 view .LVU201
	movs	r3, #5
	strh	r3, [r5]
	.loc 2 150 5 is_stmt 1 view .LVU202
	.loc 2 150 26 is_stmt 0 view .LVU203
	ldr	r3, .L41+8
	movs	r2, #7
	strh	r2, [r3]
	.loc 2 152 5 is_stmt 1 view .LVU204
	movs	r0, #96
	bl	WriteCommand
.LVL46:
	.loc 2 154 5 view .LVU205
	.loc 2 154 26 is_stmt 0 view .LVU206
	strh	r6, [r5]
	.loc 2 155 5 is_stmt 1 view .LVU207
	.loc 2 155 26 is_stmt 0 view .LVU208
	strh	r6, [r5]
	.loc 2 157 5 is_stmt 1 view .LVU209
	.loc 2 157 13 is_stmt 0 view .LVU210
	movs	r3, #0
	strb	r3, [r4]
	.loc 2 159 5 is_stmt 1 view .LVU211
	.loc 2 159 16 is_stmt 0 view .LVU212
	adds	r3, r3, #64
	mov	r2, sp
	strb	r3, [r2, #7]
	.loc 2 161 5 is_stmt 1 view .LVU213
	.loc 2 161 14 is_stmt 0 view .LVU214
	mov	r0, sp
	bl	SiiRtcSetStatus
.LVL47:
	.loc 2 163 5 is_stmt 1 view .LVU215
.L39:
	.loc 2 164 1 is_stmt 0 view .LVU216
	add	sp, sp, #12
	@ sp needed
	pop	{r4, r5, r6}
	pop	{r1}
	bx	r1
.L40:
	.loc 2 143 16 view .LVU217
	movs	r0, #0
	b	.L39
.L42:
	.align	2
.L41:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE3:
	.size	SiiRtcReset, .-SiiRtcReset
	.align	1
	.global	SiiRtcGetDateTime
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcGetDateTime, %function
SiiRtcGetDateTime:
.LVL48:
.LFB6:
	.loc 2 231 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 231 1 is_stmt 0 view .LVU219
	push	{r4, r5, r6, lr}
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
	movs	r6, r0
	.loc 2 232 5 is_stmt 1 view .LVU220
	.loc 2 234 5 view .LVU221
	.loc 2 234 17 is_stmt 0 view .LVU222
	ldr	r3, .L48
	ldrb	r3, [r3]
	.loc 2 234 8 view .LVU223
	cmp	r3, #1
	beq	.L47
	.loc 2 237 5 is_stmt 1 view .LVU224
	.loc 2 237 13 is_stmt 0 view .LVU225
	ldr	r3, .L48
	movs	r2, #1
	strb	r2, [r3]
	.loc 2 239 5 is_stmt 1 view .LVU226
	.loc 2 239 26 is_stmt 0 view .LVU227
	ldr	r3, .L48+4
	strh	r2, [r3]
	.loc 2 240 5 is_stmt 1 view .LVU228
	.loc 2 240 26 is_stmt 0 view .LVU229
	movs	r5, #5
	strh	r5, [r3]
	.loc 2 242 5 is_stmt 1 view .LVU230
	.loc 2 242 26 is_stmt 0 view .LVU231
	ldr	r4, .L48+8
	movs	r3, #7
	strh	r3, [r4]
	.loc 2 244 5 is_stmt 1 view .LVU232
	movs	r0, #101
.LVL49:
	.loc 2 244 5 is_stmt 0 view .LVU233
	bl	WriteCommand
.LVL50:
	.loc 2 246 5 is_stmt 1 view .LVU234
	.loc 2 246 26 is_stmt 0 view .LVU235
	strh	r5, [r4]
	.loc 2 248 5 is_stmt 1 view .LVU236
.LVL51:
	.loc 2 248 12 is_stmt 0 view .LVU237
	movs	r4, #0
	.loc 2 248 5 view .LVU238
	b	.L45
.LVL52:
.L46:
	.loc 2 249 9 is_stmt 1 discriminator 3 view .LVU239
	.loc 2 249 24 is_stmt 0 discriminator 3 view .LVU240
	adds	r5, r6, r4
	.loc 2 249 17 discriminator 3 view .LVU241
	bl	ReadData
.LVL53:
	.loc 2 249 15 discriminator 3 view .LVU242
	strb	r0, [r5]
	.loc 2 248 27 is_stmt 1 discriminator 3 view .LVU243
	adds	r4, r4, #1
.LVL54:
	.loc 2 248 27 is_stmt 0 discriminator 3 view .LVU244
	lsls	r4, r4, #24
	lsrs	r4, r4, #24
.LVL55:
.L45:
	.loc 2 248 19 is_stmt 1 discriminator 1 view .LVU245
	cmp	r4, #6
	bls	.L46
	.loc 2 251 5 view .LVU246
	.loc 2 251 6 is_stmt 0 view .LVU247
	ldrb	r2, [r6, #4]
	.loc 2 251 8 view .LVU248
	movs	r3, #127
	ands	r3, r2
	strb	r3, [r6, #4]
	.loc 2 253 5 is_stmt 1 view .LVU249
	.loc 2 253 26 is_stmt 0 view .LVU250
	ldr	r3, .L48+4
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 254 5 is_stmt 1 view .LVU251
	.loc 2 254 26 is_stmt 0 view .LVU252
	strh	r2, [r3]
	.loc 2 256 5 is_stmt 1 view .LVU253
	.loc 2 256 13 is_stmt 0 view .LVU254
	ldr	r3, .L48
	movs	r2, #0
	strb	r2, [r3]
	.loc 2 258 5 is_stmt 1 view .LVU255
	.loc 2 258 12 is_stmt 0 view .LVU256
	movs	r0, #1
.LVL56:
.L44:
	.loc 2 259 1 view .LVU257
	@ sp needed
.LVL57:
	.loc 2 259 1 view .LVU258
	pop	{r4, r5, r6}
	pop	{r1}
	bx	r1
.LVL58:
.L47:
	.loc 2 235 16 view .LVU259
	movs	r0, #0
.LVL59:
	.loc 2 235 16 view .LVU260
	b	.L44
.L49:
	.align	2
.L48:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE6:
	.size	SiiRtcGetDateTime, .-SiiRtcGetDateTime
	.align	1
	.global	SiiRtcSetDateTime
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcSetDateTime, %function
SiiRtcSetDateTime:
.LVL60:
.LFB7:
	.loc 2 262 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 262 1 is_stmt 0 view .LVU262
	push	{r4, r5, lr}
	.cfi_def_cfa_offset 12
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
	movs	r5, r0
	.loc 2 263 5 is_stmt 1 view .LVU263
	.loc 2 265 5 view .LVU264
	.loc 2 265 17 is_stmt 0 view .LVU265
	ldr	r3, .L55
	ldrb	r3, [r3]
	.loc 2 265 8 view .LVU266
	cmp	r3, #1
	beq	.L54
	.loc 2 268 5 is_stmt 1 view .LVU267
	.loc 2 268 13 is_stmt 0 view .LVU268
	ldr	r3, .L55
	movs	r2, #1
	strb	r2, [r3]
	.loc 2 270 5 is_stmt 1 view .LVU269
	.loc 2 270 26 is_stmt 0 view .LVU270
	ldr	r3, .L55+4
	strh	r2, [r3]
	.loc 2 271 5 is_stmt 1 view .LVU271
	.loc 2 271 26 is_stmt 0 view .LVU272
	adds	r2, r2, #4
	strh	r2, [r3]
	.loc 2 273 5 is_stmt 1 view .LVU273
	.loc 2 273 26 is_stmt 0 view .LVU274
	ldr	r3, .L55+8
	adds	r2, r2, #2
	strh	r2, [r3]
	.loc 2 275 5 is_stmt 1 view .LVU275
	movs	r0, #100
.LVL61:
	.loc 2 275 5 is_stmt 0 view .LVU276
	bl	WriteCommand
.LVL62:
	.loc 2 277 5 is_stmt 1 view .LVU277
	.loc 2 277 12 is_stmt 0 view .LVU278
	movs	r4, #0
	.loc 2 277 5 view .LVU279
	b	.L52
.LVL63:
.L53:
	.loc 2 278 9 is_stmt 1 discriminator 3 view .LVU280
	.loc 2 278 20 is_stmt 0 discriminator 3 view .LVU281
	ldrb	r0, [r5, r4]
	.loc 2 278 9 discriminator 3 view .LVU282
	bl	WriteData
.LVL64:
	.loc 2 277 27 is_stmt 1 discriminator 3 view .LVU283
	adds	r4, r4, #1
.LVL65:
	.loc 2 277 27 is_stmt 0 discriminator 3 view .LVU284
	lsls	r4, r4, #24
	lsrs	r4, r4, #24
.LVL66:
.L52:
	.loc 2 277 19 is_stmt 1 discriminator 1 view .LVU285
	cmp	r4, #6
	bls	.L53
	.loc 2 280 5 view .LVU286
	.loc 2 280 26 is_stmt 0 view .LVU287
	ldr	r3, .L55+4
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 281 5 is_stmt 1 view .LVU288
	.loc 2 281 26 is_stmt 0 view .LVU289
	strh	r2, [r3]
	.loc 2 283 5 is_stmt 1 view .LVU290
	.loc 2 283 13 is_stmt 0 view .LVU291
	ldr	r3, .L55
	movs	r2, #0
	strb	r2, [r3]
	.loc 2 285 5 is_stmt 1 view .LVU292
	.loc 2 285 12 is_stmt 0 view .LVU293
	movs	r0, #1
.LVL67:
.L51:
	.loc 2 286 1 view .LVU294
	@ sp needed
.LVL68:
	.loc 2 286 1 view .LVU295
	pop	{r4, r5}
	pop	{r1}
	bx	r1
.LVL69:
.L54:
	.loc 2 266 16 view .LVU296
	movs	r0, #0
.LVL70:
	.loc 2 266 16 view .LVU297
	b	.L51
.L56:
	.align	2
.L55:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE7:
	.size	SiiRtcSetDateTime, .-SiiRtcSetDateTime
	.align	1
	.global	SiiRtcGetTime
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcGetTime, %function
SiiRtcGetTime:
.LVL71:
.LFB8:
	.loc 2 289 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 289 1 is_stmt 0 view .LVU299
	push	{r4, r5, r6, lr}
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	.cfi_offset 5, -12
	.cfi_offset 6, -8
	.cfi_offset 14, -4
	movs	r6, r0
	.loc 2 290 5 is_stmt 1 view .LVU300
	.loc 2 292 5 view .LVU301
	.loc 2 292 17 is_stmt 0 view .LVU302
	ldr	r3, .L62
	ldrb	r3, [r3]
	.loc 2 292 8 view .LVU303
	cmp	r3, #1
	beq	.L61
	.loc 2 295 5 is_stmt 1 view .LVU304
	.loc 2 295 13 is_stmt 0 view .LVU305
	ldr	r3, .L62
	movs	r2, #1
	strb	r2, [r3]
	.loc 2 297 5 is_stmt 1 view .LVU306
	.loc 2 297 26 is_stmt 0 view .LVU307
	ldr	r3, .L62+4
	strh	r2, [r3]
	.loc 2 298 5 is_stmt 1 view .LVU308
	.loc 2 298 26 is_stmt 0 view .LVU309
	movs	r5, #5
	strh	r5, [r3]
	.loc 2 300 5 is_stmt 1 view .LVU310
	.loc 2 300 26 is_stmt 0 view .LVU311
	ldr	r4, .L62+8
	movs	r3, #7
	strh	r3, [r4]
	.loc 2 302 5 is_stmt 1 view .LVU312
	movs	r0, #103
.LVL72:
	.loc 2 302 5 is_stmt 0 view .LVU313
	bl	WriteCommand
.LVL73:
	.loc 2 304 5 is_stmt 1 view .LVU314
	.loc 2 304 26 is_stmt 0 view .LVU315
	strh	r5, [r4]
	.loc 2 306 5 is_stmt 1 view .LVU316
.LVL74:
	.loc 2 306 12 is_stmt 0 view .LVU317
	movs	r4, #0
	.loc 2 306 5 view .LVU318
	b	.L59
.LVL75:
.L60:
	.loc 2 307 9 is_stmt 1 discriminator 3 view .LVU319
	.loc 2 307 8 is_stmt 0 discriminator 3 view .LVU320
	adds	r5, r4, #4
	.loc 2 307 24 discriminator 3 view .LVU321
	adds	r5, r6, r5
	.loc 2 307 17 discriminator 3 view .LVU322
	bl	ReadData
.LVL76:
	.loc 2 307 15 discriminator 3 view .LVU323
	strb	r0, [r5]
	.loc 2 306 27 is_stmt 1 discriminator 3 view .LVU324
	adds	r4, r4, #1
.LVL77:
	.loc 2 306 27 is_stmt 0 discriminator 3 view .LVU325
	lsls	r4, r4, #24
	lsrs	r4, r4, #24
.LVL78:
.L59:
	.loc 2 306 19 is_stmt 1 discriminator 1 view .LVU326
	cmp	r4, #2
	bls	.L60
	.loc 2 309 5 view .LVU327
	.loc 2 309 6 is_stmt 0 view .LVU328
	ldrb	r2, [r6, #4]
	.loc 2 309 8 view .LVU329
	movs	r3, #127
	ands	r3, r2
	strb	r3, [r6, #4]
	.loc 2 311 5 is_stmt 1 view .LVU330
	.loc 2 311 26 is_stmt 0 view .LVU331
	ldr	r3, .L62+4
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 312 5 is_stmt 1 view .LVU332
	.loc 2 312 26 is_stmt 0 view .LVU333
	strh	r2, [r3]
	.loc 2 314 5 is_stmt 1 view .LVU334
	.loc 2 314 13 is_stmt 0 view .LVU335
	ldr	r3, .L62
	movs	r2, #0
	strb	r2, [r3]
	.loc 2 316 5 is_stmt 1 view .LVU336
	.loc 2 316 12 is_stmt 0 view .LVU337
	movs	r0, #1
.LVL79:
.L58:
	.loc 2 317 1 view .LVU338
	@ sp needed
.LVL80:
	.loc 2 317 1 view .LVU339
	pop	{r4, r5, r6}
	pop	{r1}
	bx	r1
.LVL81:
.L61:
	.loc 2 293 16 view .LVU340
	movs	r0, #0
.LVL82:
	.loc 2 293 16 view .LVU341
	b	.L58
.L63:
	.align	2
.L62:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE8:
	.size	SiiRtcGetTime, .-SiiRtcGetTime
	.align	1
	.global	SiiRtcProbe
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcProbe, %function
SiiRtcProbe:
.LFB2:
	.loc 2 93 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 12
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	sub	sp, sp, #12
	.cfi_def_cfa_offset 20
	.loc 2 94 5 view .LVU343
	.loc 2 95 5 view .LVU344
	.loc 2 97 5 view .LVU345
	.loc 2 97 10 is_stmt 0 view .LVU346
	mov	r0, sp
	bl	SiiRtcGetStatus
.LVL83:
	.loc 2 97 8 view .LVU347
	cmp	r0, #0
	beq	.L65
	.loc 2 100 5 is_stmt 1 view .LVU348
.LVL84:
	.loc 2 103 5 view .LVU349
	.loc 2 103 14 is_stmt 0 view .LVU350
	mov	r3, sp
	ldrb	r3, [r3, #7]
	.loc 2 103 8 view .LVU351
	lsls	r2, r3, #25
	bpl	.L66
	.loc 2 103 30 discriminator 1 view .LVU352
	lsls	r3, r3, #24
	bmi	.L66
	.loc 2 100 15 view .LVU353
	movs	r4, #0
	b	.L67
.L66:
	.loc 2 116 9 is_stmt 1 view .LVU354
	.loc 2 116 14 is_stmt 0 view .LVU355
	bl	SiiRtcReset
.LVL85:
	.loc 2 116 12 view .LVU356
	cmp	r0, #0
	beq	.L65
	.loc 2 119 18 view .LVU357
	movs	r4, #1
.L67:
.LVL86:
	.loc 2 122 5 is_stmt 1 view .LVU358
	mov	r0, sp
	bl	SiiRtcGetTime
.LVL87:
	.loc 2 124 5 view .LVU359
	.loc 2 124 12 is_stmt 0 view .LVU360
	mov	r3, sp
	ldrb	r3, [r3, #6]
	.loc 2 124 9 view .LVU361
	lsls	r3, r3, #24
	.loc 2 124 8 view .LVU362
	bmi	.L72
.L68:
	.loc 2 134 5 is_stmt 1 view .LVU363
	.loc 2 134 23 is_stmt 0 view .LVU364
	lsls	r0, r4, #4
	.loc 2 134 29 view .LVU365
	movs	r3, #1
	orrs	r0, r3
	lsls	r0, r0, #24
	lsrs	r0, r0, #24
.LVL88:
.L65:
	.loc 2 135 1 view .LVU366
	add	sp, sp, #12
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
.LVL89:
.L72:
	.loc 2 128 9 is_stmt 1 view .LVU367
	.loc 2 128 14 is_stmt 0 view .LVU368
	bl	SiiRtcReset
.LVL90:
	.loc 2 128 12 view .LVU369
	cmp	r0, #0
	beq	.L73
	.loc 2 131 9 is_stmt 1 view .LVU370
	.loc 2 131 18 is_stmt 0 view .LVU371
	adds	r4, r4, #1
.LVL91:
	.loc 2 131 18 view .LVU372
	lsls	r4, r4, #24
	lsrs	r4, r4, #24
.LVL92:
	.loc 2 131 18 view .LVU373
	b	.L68
.L73:
	.loc 2 129 13 is_stmt 1 view .LVU374
	.loc 2 129 37 is_stmt 0 view .LVU375
	lsls	r0, r4, #28
	lsrs	r0, r0, #24
	b	.L65
	.cfi_endproc
.LFE2:
	.size	SiiRtcProbe, .-SiiRtcProbe
	.align	1
	.global	SiiRtcSetTime
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcSetTime, %function
SiiRtcSetTime:
.LVL93:
.LFB9:
	.loc 2 320 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 320 1 is_stmt 0 view .LVU377
	push	{r4, r5, lr}
	.cfi_def_cfa_offset 12
	.cfi_offset 4, -12
	.cfi_offset 5, -8
	.cfi_offset 14, -4
	movs	r5, r0
	.loc 2 321 5 is_stmt 1 view .LVU378
	.loc 2 323 5 view .LVU379
	.loc 2 323 17 is_stmt 0 view .LVU380
	ldr	r3, .L79
	ldrb	r3, [r3]
	.loc 2 323 8 view .LVU381
	cmp	r3, #1
	beq	.L78
	.loc 2 326 5 is_stmt 1 view .LVU382
	.loc 2 326 13 is_stmt 0 view .LVU383
	ldr	r3, .L79
	movs	r2, #1
	strb	r2, [r3]
	.loc 2 328 5 is_stmt 1 view .LVU384
	.loc 2 328 26 is_stmt 0 view .LVU385
	ldr	r3, .L79+4
	strh	r2, [r3]
	.loc 2 329 5 is_stmt 1 view .LVU386
	.loc 2 329 26 is_stmt 0 view .LVU387
	adds	r2, r2, #4
	strh	r2, [r3]
	.loc 2 331 5 is_stmt 1 view .LVU388
	.loc 2 331 26 is_stmt 0 view .LVU389
	ldr	r3, .L79+8
	adds	r2, r2, #2
	strh	r2, [r3]
	.loc 2 333 5 is_stmt 1 view .LVU390
	movs	r0, #102
.LVL94:
	.loc 2 333 5 is_stmt 0 view .LVU391
	bl	WriteCommand
.LVL95:
	.loc 2 335 5 is_stmt 1 view .LVU392
	.loc 2 335 12 is_stmt 0 view .LVU393
	movs	r4, #0
	.loc 2 335 5 view .LVU394
	b	.L76
.LVL96:
.L77:
	.loc 2 336 9 is_stmt 1 discriminator 3 view .LVU395
	.loc 2 336 18 is_stmt 0 discriminator 3 view .LVU396
	adds	r3, r4, #4
	.loc 2 336 20 discriminator 3 view .LVU397
	ldrb	r0, [r5, r3]
	.loc 2 336 9 discriminator 3 view .LVU398
	bl	WriteData
.LVL97:
	.loc 2 335 27 is_stmt 1 discriminator 3 view .LVU399
	adds	r4, r4, #1
.LVL98:
	.loc 2 335 27 is_stmt 0 discriminator 3 view .LVU400
	lsls	r4, r4, #24
	lsrs	r4, r4, #24
.LVL99:
.L76:
	.loc 2 335 19 is_stmt 1 discriminator 1 view .LVU401
	cmp	r4, #2
	bls	.L77
	.loc 2 338 5 view .LVU402
	.loc 2 338 26 is_stmt 0 view .LVU403
	ldr	r3, .L79+4
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 339 5 is_stmt 1 view .LVU404
	.loc 2 339 26 is_stmt 0 view .LVU405
	strh	r2, [r3]
	.loc 2 341 5 is_stmt 1 view .LVU406
	.loc 2 341 13 is_stmt 0 view .LVU407
	ldr	r3, .L79
	movs	r2, #0
	strb	r2, [r3]
	.loc 2 343 5 is_stmt 1 view .LVU408
	.loc 2 343 12 is_stmt 0 view .LVU409
	movs	r0, #1
.LVL100:
.L75:
	.loc 2 344 1 view .LVU410
	@ sp needed
.LVL101:
	.loc 2 344 1 view .LVU411
	pop	{r4, r5}
	pop	{r1}
	bx	r1
.LVL102:
.L78:
	.loc 2 324 16 view .LVU412
	movs	r0, #0
.LVL103:
	.loc 2 324 16 view .LVU413
	b	.L75
.L80:
	.align	2
.L79:
	.word	.LANCHOR0
	.word	134217924
	.word	134217926
	.cfi_endproc
.LFE9:
	.size	SiiRtcSetTime, .-SiiRtcSetTime
	.align	1
	.global	SiiRtcSetAlarm
	.syntax unified
	.code	16
	.thumb_func
	.type	SiiRtcSetAlarm, %function
SiiRtcSetAlarm:
.LVL104:
.LFB10:
	.loc 2 347 1 is_stmt 1 view -0
	.cfi_startproc
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 4
	@ frame_needed = 0, uses_anonymous_args = 0
	.loc 2 347 1 is_stmt 0 view .LVU415
	push	{r4, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 4, -8
	.cfi_offset 14, -4
	sub	sp, sp, #4
	.cfi_def_cfa_offset 12
	.loc 2 348 5 is_stmt 1 view .LVU416
	.loc 2 349 5 view .LVU417
	.loc 2 351 5 view .LVU418
	.loc 2 351 17 is_stmt 0 view .LVU419
	ldr	r3, .L88
	ldrb	r3, [r3]
	.loc 2 351 8 view .LVU420
	cmp	r3, #1
	beq	.L87
	.loc 2 354 5 is_stmt 1 view .LVU421
	.loc 2 354 13 is_stmt 0 view .LVU422
	ldr	r3, .L88
	movs	r2, #1
	strb	r2, [r3]
	.loc 2 357 5 is_stmt 1 view .LVU423
	.loc 2 357 24 is_stmt 0 view .LVU424
	ldrb	r1, [r0, #8]
	.loc 2 357 36 view .LVU425
	movs	r3, #15
	ands	r3, r1
	.loc 2 357 43 view .LVU426
	lsrs	r2, r1, #4
	lsls	r4, r2, #2
	adds	r2, r2, r4
	lsls	r2, r2, #1
	adds	r3, r3, r2
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	.loc 2 357 18 view .LVU427
	mov	r2, sp
	strb	r3, [r2]
	.loc 2 361 5 is_stmt 1 view .LVU428
	.loc 2 361 8 is_stmt 0 view .LVU429
	cmp	r3, #11
	bhi	.L83
	.loc 2 362 9 is_stmt 1 view .LVU430
	.loc 2 362 22 is_stmt 0 view .LVU431
	strb	r1, [r2]
.L84:
	.loc 2 366 5 is_stmt 1 view .LVU432
	.loc 2 366 23 is_stmt 0 view .LVU433
	ldrb	r3, [r0, #9]
	.loc 2 366 18 view .LVU434
	mov	r2, sp
	strb	r3, [r2, #1]
	.loc 2 368 5 is_stmt 1 view .LVU435
	.loc 2 368 26 is_stmt 0 view .LVU436
	ldr	r3, .L88+4
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 369 5 is_stmt 1 view .LVU437
	.loc 2 369 26 is_stmt 0 view .LVU438
	adds	r2, r2, #4
	strh	r2, [r3]
	.loc 2 371 5 is_stmt 1 view .LVU439
	.loc 2 371 23 is_stmt 0 view .LVU440
	ldr	r3, .L88+8
	adds	r2, r2, #2
	strh	r2, [r3]
	.loc 2 373 5 is_stmt 1 view .LVU441
	movs	r0, #104
.LVL105:
	.loc 2 373 5 is_stmt 0 view .LVU442
	bl	WriteCommand
.LVL106:
	.loc 2 375 5 is_stmt 1 view .LVU443
	.loc 2 375 12 is_stmt 0 view .LVU444
	movs	r4, #0
	.loc 2 375 5 view .LVU445
	b	.L85
.LVL107:
.L83:
	.loc 2 364 9 is_stmt 1 view .LVU446
	.loc 2 364 22 is_stmt 0 view .LVU447
	movs	r3, #128
	rsbs	r3, r3, #0
	orrs	r3, r1
	mov	r2, sp
	strb	r3, [r2]
	b	.L84
.LVL108:
.L86:
	.loc 2 376 9 is_stmt 1 discriminator 3 view .LVU448
	.loc 2 376 28 is_stmt 0 discriminator 3 view .LVU449
	mov	r3, sp
	ldrb	r0, [r3, r4]
	.loc 2 376 9 discriminator 3 view .LVU450
	bl	WriteData
.LVL109:
	.loc 2 375 25 is_stmt 1 discriminator 3 view .LVU451
	adds	r4, r4, #1
.LVL110:
	.loc 2 375 25 is_stmt 0 discriminator 3 view .LVU452
	lsls	r4, r4, #24
	lsrs	r4, r4, #24
.LVL111:
.L85:
	.loc 2 375 19 is_stmt 1 discriminator 1 view .LVU453
	cmp	r4, #1
	bls	.L86
	.loc 2 378 5 view .LVU454
	.loc 2 378 26 is_stmt 0 view .LVU455
	ldr	r3, .L88+4
	movs	r2, #1
	strh	r2, [r3]
	.loc 2 379 5 is_stmt 1 view .LVU456
	.loc 2 379 26 is_stmt 0 view .LVU457
	strh	r2, [r3]
	.loc 2 381 5 is_stmt 1 view .LVU458
	.loc 2 381 13 is_stmt 0 view .LVU459
	ldr	r3, .L88
	movs	r2, #0
	strb	r2, [r3]
	.loc 2 383 5 is_stmt 1 view .LVU460
	.loc 2 383 12 is_stmt 0 view .LVU461
	movs	r0, #1
.LVL112:
.L82:
	.loc 2 384 1 view .LVU462
	add	sp, sp, #4
	@ sp needed
	pop	{r4}
	pop	{r1}
	bx	r1
.LVL113:
.L87:
	.loc 2 352 16 view .LVU463
	movs	r0, #0
.LVL114:
	.loc 2 352 16 view .LVU464
	b	.L82
.L89:
	.align	2
.L88:
	.word	.LANCHOR0
	.word	134217924
	.word	GPIOPortDirection
	.cfi_endproc
.LFE10:
	.size	SiiRtcSetAlarm, .-SiiRtcSetAlarm
	.section	.rodata
	.align	2
	.type	AgbLibRtcVersion, %object
	.size	AgbLibRtcVersion, 12
AgbLibRtcVersion:
	.ascii	"SIIRTC_V001\000"
	.bss
	.set	.LANCHOR0,. + 0
	.type	sLocked, %object
	.size	sLocked, 1
sLocked:
	.space	1
	.text
.Letext0:
	.file 3 "/usr/lib/gcc/arm-none-eabi/12.2.1/include/stdint.h"
	.file 4 "include/gba/types.h"
	.file 5 "include/siirtc.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x6cf
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF48
	.byte	0xc
	.4byte	.LASF49
	.4byte	.LASF50
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF0
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.4byte	.LASF1
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.4byte	.LASF2
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.4byte	.LASF3
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x4
	.4byte	.LASF7
	.byte	0x3
	.byte	0x2e
	.byte	0x17
	.4byte	0x62
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.4byte	.LASF6
	.uleb128 0x4
	.4byte	.LASF8
	.byte	0x3
	.byte	0x31
	.byte	0x1c
	.4byte	0x75
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.4byte	.LASF10
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.4byte	.LASF11
	.uleb128 0x5
	.ascii	"u8\000"
	.byte	0x4
	.byte	0x7
	.byte	0x11
	.4byte	0x56
	.uleb128 0x5
	.ascii	"u16\000"
	.byte	0x4
	.byte	0x8
	.byte	0x12
	.4byte	0x69
	.uleb128 0x6
	.4byte	0x95
	.uleb128 0x4
	.4byte	.LASF12
	.byte	0x4
	.byte	0x11
	.byte	0x16
	.4byte	0xa1
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.4byte	.LASF13
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.4byte	.LASF14
	.uleb128 0x4
	.4byte	.LASF15
	.byte	0x4
	.byte	0x1c
	.byte	0xc
	.4byte	0x8a
	.uleb128 0x7
	.4byte	.LASF51
	.byte	0xc
	.byte	0x5
	.byte	0x7
	.byte	0x8
	.4byte	0x15c
	.uleb128 0x8
	.4byte	.LASF16
	.byte	0x5
	.byte	0x9
	.byte	0x8
	.4byte	0x8a
	.byte	0
	.uleb128 0x8
	.4byte	.LASF17
	.byte	0x5
	.byte	0xa
	.byte	0x8
	.4byte	0x8a
	.byte	0x1
	.uleb128 0x9
	.ascii	"day\000"
	.byte	0x5
	.byte	0xb
	.byte	0x8
	.4byte	0x8a
	.byte	0x2
	.uleb128 0x8
	.4byte	.LASF18
	.byte	0x5
	.byte	0xc
	.byte	0x8
	.4byte	0x8a
	.byte	0x3
	.uleb128 0x8
	.4byte	.LASF19
	.byte	0x5
	.byte	0xd
	.byte	0x8
	.4byte	0x8a
	.byte	0x4
	.uleb128 0x8
	.4byte	.LASF20
	.byte	0x5
	.byte	0xe
	.byte	0x8
	.4byte	0x8a
	.byte	0x5
	.uleb128 0x8
	.4byte	.LASF21
	.byte	0x5
	.byte	0xf
	.byte	0x8
	.4byte	0x8a
	.byte	0x6
	.uleb128 0x8
	.4byte	.LASF22
	.byte	0x5
	.byte	0x10
	.byte	0x8
	.4byte	0x8a
	.byte	0x7
	.uleb128 0x8
	.4byte	.LASF23
	.byte	0x5
	.byte	0x11
	.byte	0x8
	.4byte	0x8a
	.byte	0x8
	.uleb128 0x8
	.4byte	.LASF24
	.byte	0x5
	.byte	0x12
	.byte	0x8
	.4byte	0x8a
	.byte	0x9
	.byte	0
	.uleb128 0xa
	.4byte	.LASF30
	.byte	0x2
	.byte	0x43
	.byte	0xd
	.4byte	0xa6
	.uleb128 0xb
	.4byte	.LASF26
	.byte	0x2
	.byte	0x45
	.byte	0xe
	.4byte	0xc0
	.uleb128 0x5
	.byte	0x3
	.4byte	sLocked
	.uleb128 0xc
	.4byte	0x196
	.4byte	0x18a
	.uleb128 0xd
	.4byte	0x7c
	.byte	0xb
	.byte	0
	.uleb128 0xe
	.4byte	0x17a
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.4byte	.LASF25
	.uleb128 0xe
	.4byte	0x18f
	.uleb128 0xb
	.4byte	.LASF27
	.byte	0x2
	.byte	0x4e
	.byte	0x29
	.4byte	0x18a
	.uleb128 0x5
	.byte	0x3
	.4byte	AgbLibRtcVersion
	.uleb128 0xf
	.4byte	.LASF28
	.byte	0x2
	.2byte	0x1cb
	.byte	0xd
	.4byte	.LFB15
	.4byte	.LFE15-.LFB15
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xf
	.4byte	.LASF29
	.byte	0x2
	.2byte	0x1c6
	.byte	0xd
	.4byte	.LFB14
	.4byte	.LFE14-.LFB14
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x10
	.4byte	.LASF52
	.byte	0x2
	.2byte	0x1ac
	.byte	0xb
	.4byte	0x8a
	.4byte	.LFB13
	.4byte	.LFE13-.LFB13
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x22c
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x1ae
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST6
	.4byte	.LVUS6
	.uleb128 0x12
	.4byte	.LASF31
	.byte	0x2
	.2byte	0x1af
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST7
	.4byte	.LVUS7
	.uleb128 0x12
	.4byte	.LASF32
	.byte	0x2
	.2byte	0x1b0
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST8
	.4byte	.LVUS8
	.byte	0
	.uleb128 0x13
	.4byte	.LASF33
	.byte	0x2
	.2byte	0x197
	.byte	0xc
	.4byte	0x25
	.4byte	.LFB12
	.4byte	.LFE12-.LFB12
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x285
	.uleb128 0x14
	.4byte	.LASF32
	.byte	0x2
	.2byte	0x197
	.byte	0x19
	.4byte	0x8a
	.4byte	.LLST3
	.4byte	.LVUS3
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x199
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST4
	.4byte	.LVUS4
	.uleb128 0x12
	.4byte	.LASF31
	.byte	0x2
	.2byte	0x19a
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST5
	.4byte	.LVUS5
	.byte	0
	.uleb128 0x13
	.4byte	.LASF34
	.byte	0x2
	.2byte	0x182
	.byte	0xc
	.4byte	0x25
	.4byte	.LFB11
	.4byte	.LFE11-.LFB11
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x2de
	.uleb128 0x14
	.4byte	.LASF32
	.byte	0x2
	.2byte	0x182
	.byte	0x1c
	.4byte	0x8a
	.4byte	.LLST0
	.4byte	.LVUS0
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x184
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST1
	.4byte	.LVUS1
	.uleb128 0x12
	.4byte	.LASF31
	.byte	0x2
	.2byte	0x185
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST2
	.4byte	.LVUS2
	.byte	0
	.uleb128 0x15
	.4byte	.LASF36
	.byte	0x2
	.2byte	0x15a
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB10
	.4byte	.LFE10-.LFB10
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x35e
	.uleb128 0x16
	.ascii	"rtc\000"
	.byte	0x2
	.2byte	0x15a
	.byte	0x29
	.4byte	0x35e
	.4byte	.LLST23
	.4byte	.LVUS23
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x15c
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST24
	.4byte	.LVUS24
	.uleb128 0x17
	.4byte	.LASF35
	.byte	0x2
	.2byte	0x15d
	.byte	0x8
	.4byte	0x364
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x18
	.4byte	.LVL106
	.4byte	0x285
	.4byte	0x345
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x68
	.byte	0
	.uleb128 0x1a
	.4byte	.LVL109
	.4byte	0x22c
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0xa
	.byte	0x7d
	.sleb128 0
	.byte	0x74
	.sleb128 0
	.byte	0x22
	.byte	0x94
	.byte	0x1
	.byte	0x8
	.byte	0xff
	.byte	0x1a
	.byte	0
	.byte	0
	.uleb128 0x1b
	.byte	0x4
	.4byte	0xcc
	.uleb128 0xc
	.4byte	0x8a
	.4byte	0x374
	.uleb128 0xd
	.4byte	0x7c
	.byte	0x1
	.byte	0
	.uleb128 0x15
	.4byte	.LASF37
	.byte	0x2
	.2byte	0x13f
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB9
	.4byte	.LFE9-.LFB9
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x3d5
	.uleb128 0x16
	.ascii	"rtc\000"
	.byte	0x2
	.2byte	0x13f
	.byte	0x28
	.4byte	0x35e
	.4byte	.LLST21
	.4byte	.LVUS21
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x141
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST22
	.4byte	.LVUS22
	.uleb128 0x18
	.4byte	.LVL95
	.4byte	0x285
	.4byte	0x3cb
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x66
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL97
	.4byte	0x22c
	.byte	0
	.uleb128 0x15
	.4byte	.LASF38
	.byte	0x2
	.2byte	0x120
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB8
	.4byte	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x436
	.uleb128 0x16
	.ascii	"rtc\000"
	.byte	0x2
	.2byte	0x120
	.byte	0x28
	.4byte	0x35e
	.4byte	.LLST18
	.4byte	.LVUS18
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x122
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST19
	.4byte	.LVUS19
	.uleb128 0x18
	.4byte	.LVL73
	.4byte	0x285
	.4byte	0x42c
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x67
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL76
	.4byte	0x1d3
	.byte	0
	.uleb128 0x15
	.4byte	.LASF39
	.byte	0x2
	.2byte	0x105
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB7
	.4byte	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x497
	.uleb128 0x16
	.ascii	"rtc\000"
	.byte	0x2
	.2byte	0x105
	.byte	0x2c
	.4byte	0x35e
	.4byte	.LLST16
	.4byte	.LVUS16
	.uleb128 0x11
	.ascii	"i\000"
	.byte	0x2
	.2byte	0x107
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST17
	.4byte	.LVUS17
	.uleb128 0x18
	.4byte	.LVL62
	.4byte	0x285
	.4byte	0x48d
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x64
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL64
	.4byte	0x22c
	.byte	0
	.uleb128 0x1d
	.4byte	.LASF40
	.byte	0x2
	.byte	0xe6
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB6
	.4byte	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x4f5
	.uleb128 0x1e
	.ascii	"rtc\000"
	.byte	0x2
	.byte	0xe6
	.byte	0x2c
	.4byte	0x35e
	.4byte	.LLST14
	.4byte	.LVUS14
	.uleb128 0x1f
	.ascii	"i\000"
	.byte	0x2
	.byte	0xe8
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST15
	.4byte	.LVUS15
	.uleb128 0x18
	.4byte	.LVL50
	.4byte	0x285
	.4byte	0x4eb
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x65
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL53
	.4byte	0x1d3
	.byte	0
	.uleb128 0x1d
	.4byte	.LASF41
	.byte	0x2
	.byte	0xc7
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB5
	.4byte	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x55c
	.uleb128 0x1e
	.ascii	"rtc\000"
	.byte	0x2
	.byte	0xc7
	.byte	0x2a
	.4byte	0x35e
	.4byte	.LLST11
	.4byte	.LVUS11
	.uleb128 0x20
	.4byte	.LASF42
	.byte	0x2
	.byte	0xc9
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST12
	.4byte	.LVUS12
	.uleb128 0x18
	.4byte	.LVL41
	.4byte	0x285
	.4byte	0x54b
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x62
	.byte	0
	.uleb128 0x1a
	.4byte	.LVL42
	.4byte	0x22c
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x1d
	.4byte	.LASF43
	.byte	0x2
	.byte	0xa6
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB4
	.4byte	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x5bc
	.uleb128 0x1e
	.ascii	"rtc\000"
	.byte	0x2
	.byte	0xa6
	.byte	0x2a
	.4byte	0x35e
	.4byte	.LLST9
	.4byte	.LVUS9
	.uleb128 0x20
	.4byte	.LASF42
	.byte	0x2
	.byte	0xa8
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST10
	.4byte	.LVUS10
	.uleb128 0x18
	.4byte	.LVL32
	.4byte	0x285
	.4byte	0x5b2
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x63
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL33
	.4byte	0x1d3
	.byte	0
	.uleb128 0x1d
	.4byte	.LASF44
	.byte	0x2
	.byte	0x89
	.byte	0x7
	.4byte	0xc0
	.4byte	.LFB3
	.4byte	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x61e
	.uleb128 0x20
	.4byte	.LASF45
	.byte	0x2
	.byte	0x8b
	.byte	0xb
	.4byte	0xc0
	.4byte	.LLST13
	.4byte	.LVUS13
	.uleb128 0x21
	.ascii	"rtc\000"
	.byte	0x2
	.byte	0x8c
	.byte	0x17
	.4byte	0xcc
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x18
	.4byte	.LVL46
	.4byte	0x285
	.4byte	0x60d
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x8
	.byte	0x60
	.byte	0
	.uleb128 0x1a
	.4byte	.LVL47
	.4byte	0x4f5
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x1d
	.4byte	.LASF46
	.byte	0x2
	.byte	0x5c
	.byte	0x4
	.4byte	0x8a
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x696
	.uleb128 0x20
	.4byte	.LASF47
	.byte	0x2
	.byte	0x5e
	.byte	0x8
	.4byte	0x8a
	.4byte	.LLST20
	.4byte	.LVUS20
	.uleb128 0x21
	.ascii	"rtc\000"
	.byte	0x2
	.byte	0x5f
	.byte	0x17
	.4byte	0xcc
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x18
	.4byte	.LVL83
	.4byte	0x55c
	.4byte	0x66f
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL85
	.4byte	0x5bc
	.uleb128 0x18
	.4byte	.LVL87
	.4byte	0x3d5
	.4byte	0x68c
	.uleb128 0x19
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.uleb128 0x1c
	.4byte	.LVL90
	.4byte	0x5bc
	.byte	0
	.uleb128 0x22
	.4byte	.LASF53
	.byte	0x2
	.byte	0x56
	.byte	0x6
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x6b6
	.uleb128 0x1c
	.4byte	.LVL29
	.4byte	0x1ad
	.byte	0
	.uleb128 0x23
	.4byte	.LASF54
	.byte	0x2
	.byte	0x50
	.byte	0x6
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1c
	.4byte	.LVL28
	.4byte	0x1c0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LVUS6:
	.uleb128 .LVU67
	.uleb128 .LVU70
	.uleb128 .LVU70
	.uleb128 .LVU91
	.uleb128 .LVU92
	.uleb128 0
.LLST6:
	.4byte	.LVL20-.Ltext0
	.4byte	.LVL21-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL21-.Ltext0
	.4byte	.LVL26-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	.LVL27-.Ltext0
	.4byte	.LFE13-.Ltext0
	.2byte	0x1
	.byte	0x52
	.4byte	0
	.4byte	0
.LVUS7:
	.uleb128 .LVU86
	.uleb128 .LVU89
.LLST7:
	.4byte	.LVL22-.Ltext0
	.4byte	.LVL24-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	0
	.4byte	0
.LVUS8:
	.uleb128 .LVU66
	.uleb128 .LVU70
	.uleb128 .LVU70
	.uleb128 .LVU88
	.uleb128 .LVU90
	.uleb128 0
.LLST8:
	.4byte	.LVL20-.Ltext0
	.4byte	.LVL21-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL21-.Ltext0
	.4byte	.LVL23-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL25-.Ltext0
	.4byte	.LFE13-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	0
	.4byte	0
.LVUS3:
	.uleb128 0
	.uleb128 .LVU60
	.uleb128 .LVU60
	.uleb128 0
.LLST3:
	.4byte	.LVL10-.Ltext0
	.4byte	.LVL19-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL19-.Ltext0
	.4byte	.LFE12-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LVUS4:
	.uleb128 .LVU36
	.uleb128 .LVU38
	.uleb128 .LVU38
	.uleb128 .LVU55
	.uleb128 .LVU57
	.uleb128 0
.LLST4:
	.4byte	.LVL11-.Ltext0
	.4byte	.LVL12-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL12-.Ltext0
	.4byte	.LVL16-.Ltext0
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL18-.Ltext0
	.4byte	.LFE12-.Ltext0
	.2byte	0x1
	.byte	0x51
	.4byte	0
	.4byte	0
.LVUS5:
	.uleb128 .LVU42
	.uleb128 .LVU44
	.uleb128 .LVU44
	.uleb128 .LVU45
	.uleb128 .LVU45
	.uleb128 .LVU55
	.uleb128 .LVU55
	.uleb128 .LVU56
.LLST5:
	.4byte	.LVL13-.Ltext0
	.4byte	.LVL14-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL14-.Ltext0
	.4byte	.LVL15-.Ltext0
	.2byte	0x5
	.byte	0x72
	.sleb128 0
	.byte	0x31
	.byte	0x1a
	.byte	0x9f
	.4byte	.LVL15-.Ltext0
	.4byte	.LVL16-.Ltext0
	.2byte	0xc
	.byte	0x70
	.sleb128 0
	.byte	0x71
	.sleb128 0
	.byte	0x26
	.byte	0x48
	.byte	0x24
	.byte	0x48
	.byte	0x25
	.byte	0x31
	.byte	0x1a
	.byte	0x9f
	.4byte	.LVL16-.Ltext0
	.4byte	.LVL17-.Ltext0
	.2byte	0xc
	.byte	0x70
	.sleb128 0
	.byte	0x71
	.sleb128 -1
	.byte	0x26
	.byte	0x48
	.byte	0x24
	.byte	0x48
	.byte	0x25
	.byte	0x31
	.byte	0x1a
	.byte	0x9f
	.4byte	0
	.4byte	0
.LVUS0:
	.uleb128 0
	.uleb128 .LVU30
	.uleb128 .LVU30
	.uleb128 0
.LLST0:
	.4byte	.LVL0-.Ltext0
	.4byte	.LVL9-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL9-.Ltext0
	.4byte	.LFE11-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LVUS1:
	.uleb128 .LVU5
	.uleb128 .LVU7
	.uleb128 .LVU7
	.uleb128 .LVU25
	.uleb128 .LVU27
	.uleb128 0
.LLST1:
	.4byte	.LVL1-.Ltext0
	.4byte	.LVL2-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL2-.Ltext0
	.4byte	.LVL6-.Ltext0
	.2byte	0x1
	.byte	0x51
	.4byte	.LVL8-.Ltext0
	.4byte	.LFE11-.Ltext0
	.2byte	0x1
	.byte	0x51
	.4byte	0
	.4byte	0
.LVUS2:
	.uleb128 .LVU12
	.uleb128 .LVU14
	.uleb128 .LVU14
	.uleb128 .LVU15
	.uleb128 .LVU15
	.uleb128 .LVU25
	.uleb128 .LVU25
	.uleb128 .LVU26
.LLST2:
	.4byte	.LVL3-.Ltext0
	.4byte	.LVL4-.Ltext0
	.2byte	0x1
	.byte	0x53
	.4byte	.LVL4-.Ltext0
	.4byte	.LVL5-.Ltext0
	.2byte	0x5
	.byte	0x72
	.sleb128 0
	.byte	0x31
	.byte	0x1a
	.byte	0x9f
	.4byte	.LVL5-.Ltext0
	.4byte	.LVL6-.Ltext0
	.2byte	0xe
	.byte	0x70
	.sleb128 0
	.byte	0x37
	.byte	0x71
	.sleb128 0
	.byte	0x1c
	.byte	0x26
	.byte	0x48
	.byte	0x24
	.byte	0x48
	.byte	0x25
	.byte	0x31
	.byte	0x1a
	.byte	0x9f
	.4byte	.LVL6-.Ltext0
	.4byte	.LVL7-.Ltext0
	.2byte	0xe
	.byte	0x70
	.sleb128 0
	.byte	0x38
	.byte	0x71
	.sleb128 0
	.byte	0x1c
	.byte	0x26
	.byte	0x48
	.byte	0x24
	.byte	0x48
	.byte	0x25
	.byte	0x31
	.byte	0x1a
	.byte	0x9f
	.4byte	0
	.4byte	0
.LVUS23:
	.uleb128 0
	.uleb128 .LVU442
	.uleb128 .LVU442
	.uleb128 .LVU446
	.uleb128 .LVU446
	.uleb128 .LVU448
	.uleb128 .LVU448
	.uleb128 .LVU463
	.uleb128 .LVU463
	.uleb128 .LVU464
	.uleb128 .LVU464
	.uleb128 0
.LLST23:
	.4byte	.LVL104-.Ltext0
	.4byte	.LVL105-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL105-.Ltext0
	.4byte	.LVL107-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL107-.Ltext0
	.4byte	.LVL108-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL108-.Ltext0
	.4byte	.LVL113-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL113-.Ltext0
	.4byte	.LVL114-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL114-.Ltext0
	.4byte	.LFE10-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LVUS24:
	.uleb128 .LVU444
	.uleb128 .LVU446
	.uleb128 .LVU448
	.uleb128 .LVU452
	.uleb128 .LVU453
	.uleb128 .LVU462
.LLST24:
	.4byte	.LVL106-.Ltext0
	.4byte	.LVL107-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL108-.Ltext0
	.4byte	.LVL110-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL111-.Ltext0
	.4byte	.LVL112-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
.LVUS21:
	.uleb128 0
	.uleb128 .LVU391
	.uleb128 .LVU391
	.uleb128 .LVU411
	.uleb128 .LVU411
	.uleb128 .LVU412
	.uleb128 .LVU412
	.uleb128 .LVU413
	.uleb128 .LVU413
	.uleb128 0
.LLST21:
	.4byte	.LVL93-.Ltext0
	.4byte	.LVL94-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL94-.Ltext0
	.4byte	.LVL101-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL101-.Ltext0
	.4byte	.LVL102-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL102-.Ltext0
	.4byte	.LVL103-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL103-.Ltext0
	.4byte	.LFE9-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0
	.4byte	0
.LVUS22:
	.uleb128 .LVU393
	.uleb128 .LVU395
	.uleb128 .LVU395
	.uleb128 .LVU400
	.uleb128 .LVU401
	.uleb128 .LVU410
.LLST22:
	.4byte	.LVL95-.Ltext0
	.4byte	.LVL96-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL96-.Ltext0
	.4byte	.LVL98-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL99-.Ltext0
	.4byte	.LVL100-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
.LVUS18:
	.uleb128 0
	.uleb128 .LVU313
	.uleb128 .LVU313
	.uleb128 .LVU339
	.uleb128 .LVU339
	.uleb128 .LVU340
	.uleb128 .LVU340
	.uleb128 .LVU341
	.uleb128 .LVU341
	.uleb128 0
.LLST18:
	.4byte	.LVL71-.Ltext0
	.4byte	.LVL72-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL72-.Ltext0
	.4byte	.LVL80-.Ltext0
	.2byte	0x1
	.byte	0x56
	.4byte	.LVL80-.Ltext0
	.4byte	.LVL81-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL81-.Ltext0
	.4byte	.LVL82-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL82-.Ltext0
	.4byte	.LFE8-.Ltext0
	.2byte	0x1
	.byte	0x56
	.4byte	0
	.4byte	0
.LVUS19:
	.uleb128 .LVU317
	.uleb128 .LVU319
	.uleb128 .LVU319
	.uleb128 .LVU325
	.uleb128 .LVU326
	.uleb128 .LVU338
.LLST19:
	.4byte	.LVL74-.Ltext0
	.4byte	.LVL75-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL75-.Ltext0
	.4byte	.LVL77-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL78-.Ltext0
	.4byte	.LVL79-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
.LVUS16:
	.uleb128 0
	.uleb128 .LVU276
	.uleb128 .LVU276
	.uleb128 .LVU295
	.uleb128 .LVU295
	.uleb128 .LVU296
	.uleb128 .LVU296
	.uleb128 .LVU297
	.uleb128 .LVU297
	.uleb128 0
.LLST16:
	.4byte	.LVL60-.Ltext0
	.4byte	.LVL61-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL61-.Ltext0
	.4byte	.LVL68-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	.LVL68-.Ltext0
	.4byte	.LVL69-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL69-.Ltext0
	.4byte	.LVL70-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL70-.Ltext0
	.4byte	.LFE7-.Ltext0
	.2byte	0x1
	.byte	0x55
	.4byte	0
	.4byte	0
.LVUS17:
	.uleb128 .LVU278
	.uleb128 .LVU280
	.uleb128 .LVU280
	.uleb128 .LVU284
	.uleb128 .LVU285
	.uleb128 .LVU294
.LLST17:
	.4byte	.LVL62-.Ltext0
	.4byte	.LVL63-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL63-.Ltext0
	.4byte	.LVL65-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL66-.Ltext0
	.4byte	.LVL67-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
.LVUS14:
	.uleb128 0
	.uleb128 .LVU233
	.uleb128 .LVU233
	.uleb128 .LVU258
	.uleb128 .LVU258
	.uleb128 .LVU259
	.uleb128 .LVU259
	.uleb128 .LVU260
	.uleb128 .LVU260
	.uleb128 0
.LLST14:
	.4byte	.LVL48-.Ltext0
	.4byte	.LVL49-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL49-.Ltext0
	.4byte	.LVL57-.Ltext0
	.2byte	0x1
	.byte	0x56
	.4byte	.LVL57-.Ltext0
	.4byte	.LVL58-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL58-.Ltext0
	.4byte	.LVL59-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL59-.Ltext0
	.4byte	.LFE6-.Ltext0
	.2byte	0x1
	.byte	0x56
	.4byte	0
	.4byte	0
.LVUS15:
	.uleb128 .LVU237
	.uleb128 .LVU239
	.uleb128 .LVU239
	.uleb128 .LVU244
	.uleb128 .LVU245
	.uleb128 .LVU257
.LLST15:
	.4byte	.LVL51-.Ltext0
	.4byte	.LVL52-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL52-.Ltext0
	.4byte	.LVL54-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL55-.Ltext0
	.4byte	.LVL56-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
.LVUS11:
	.uleb128 0
	.uleb128 .LVU177
	.uleb128 .LVU177
	.uleb128 .LVU188
	.uleb128 .LVU188
	.uleb128 .LVU189
	.uleb128 .LVU189
	.uleb128 0
.LLST11:
	.4byte	.LVL38-.Ltext0
	.4byte	.LVL40-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL40-.Ltext0
	.4byte	.LVL44-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL44-.Ltext0
	.4byte	.LVL45-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL45-.Ltext0
	.4byte	.LFE5-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	0
	.4byte	0
.LVUS12:
	.uleb128 .LVU174
	.uleb128 .LVU187
.LLST12:
	.4byte	.LVL39-.Ltext0
	.4byte	.LVL43-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
.LVUS9:
	.uleb128 0
	.uleb128 .LVU128
	.uleb128 .LVU128
	.uleb128 .LVU152
	.uleb128 .LVU152
	.uleb128 .LVU153
	.uleb128 .LVU153
	.uleb128 0
.LLST9:
	.4byte	.LVL30-.Ltext0
	.4byte	.LVL31-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL31-.Ltext0
	.4byte	.LVL36-.Ltext0
	.2byte	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x50
	.byte	0x9f
	.4byte	.LVL36-.Ltext0
	.4byte	.LVL37-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	.LVL37-.Ltext0
	.4byte	.LFE4-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 0
	.4byte	0
	.4byte	0
.LVUS10:
	.uleb128 .LVU133
	.uleb128 .LVU140
.LLST10:
	.4byte	.LVL33-.Ltext0
	.4byte	.LVL34-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	0
	.4byte	0
.LVUS13:
	.uleb128 .LVU215
	.uleb128 .LVU216
.LLST13:
	.4byte	.LVL47-.Ltext0
	.4byte	.LVL47-.Ltext0
	.2byte	0x1
	.byte	0x50
	.4byte	0
	.4byte	0
.LVUS20:
	.uleb128 .LVU349
	.uleb128 .LVU358
	.uleb128 .LVU358
	.uleb128 .LVU366
	.uleb128 .LVU367
	.uleb128 .LVU372
	.uleb128 .LVU373
	.uleb128 0
.LLST20:
	.4byte	.LVL84-.Ltext0
	.4byte	.LVL86-.Ltext0
	.2byte	0x2
	.byte	0x30
	.byte	0x9f
	.4byte	.LVL86-.Ltext0
	.4byte	.LVL88-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL89-.Ltext0
	.4byte	.LVL91-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	.LVL92-.Ltext0
	.4byte	.LFE2-.Ltext0
	.2byte	0x1
	.byte	0x54
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF52:
	.ascii	"ReadData\000"
.LASF34:
	.ascii	"WriteCommand\000"
.LASF32:
	.ascii	"value\000"
.LASF16:
	.ascii	"year\000"
.LASF40:
	.ascii	"SiiRtcGetDateTime\000"
.LASF30:
	.ascii	"GPIOPortDirection\000"
.LASF51:
	.ascii	"SiiRtcInfo\000"
.LASF35:
	.ascii	"alarmData\000"
.LASF53:
	.ascii	"SiiRtcProtect\000"
.LASF54:
	.ascii	"SiiRtcUnprotect\000"
.LASF17:
	.ascii	"month\000"
.LASF22:
	.ascii	"status\000"
.LASF12:
	.ascii	"vu16\000"
.LASF50:
	.ascii	"/home/grieco/HackRomProject\000"
.LASF44:
	.ascii	"SiiRtcReset\000"
.LASF33:
	.ascii	"WriteData\000"
.LASF15:
	.ascii	"bool8\000"
.LASF13:
	.ascii	"float\000"
.LASF49:
	.ascii	"<stdin>\000"
.LASF6:
	.ascii	"unsigned char\000"
.LASF10:
	.ascii	"long unsigned int\000"
.LASF31:
	.ascii	"temp\000"
.LASF9:
	.ascii	"short unsigned int\000"
.LASF36:
	.ascii	"SiiRtcSetAlarm\000"
.LASF39:
	.ascii	"SiiRtcSetDateTime\000"
.LASF21:
	.ascii	"second\000"
.LASF46:
	.ascii	"SiiRtcProbe\000"
.LASF27:
	.ascii	"AgbLibRtcVersion\000"
.LASF14:
	.ascii	"double\000"
.LASF48:
	.ascii	"GNU C17 12.2.1 20221205 -gdwarf-4 -mthumb -mthumb-i"
	.ascii	"nterwork -Og -mabi=apcs-gnu -mtune=arm7tdmi -march="
	.ascii	"armv4t -std=gnu17 -g -gdwarf-4\000"
.LASF41:
	.ascii	"SiiRtcSetStatus\000"
.LASF4:
	.ascii	"short int\000"
.LASF18:
	.ascii	"dayOfWeek\000"
.LASF23:
	.ascii	"alarmHour\000"
.LASF47:
	.ascii	"errorCode\000"
.LASF20:
	.ascii	"minute\000"
.LASF42:
	.ascii	"statusData\000"
.LASF0:
	.ascii	"unsigned int\000"
.LASF11:
	.ascii	"long long unsigned int\000"
.LASF7:
	.ascii	"uint8_t\000"
.LASF26:
	.ascii	"sLocked\000"
.LASF45:
	.ascii	"result\000"
.LASF19:
	.ascii	"hour\000"
.LASF1:
	.ascii	"long long int\000"
.LASF25:
	.ascii	"char\000"
.LASF28:
	.ascii	"DisableGpioPortRead\000"
.LASF38:
	.ascii	"SiiRtcGetTime\000"
.LASF8:
	.ascii	"uint16_t\000"
.LASF29:
	.ascii	"EnableGpioPortRead\000"
.LASF43:
	.ascii	"SiiRtcGetStatus\000"
.LASF5:
	.ascii	"long int\000"
.LASF2:
	.ascii	"long double\000"
.LASF3:
	.ascii	"signed char\000"
.LASF37:
	.ascii	"SiiRtcSetTime\000"
.LASF24:
	.ascii	"alarmMinute\000"
	.ident	"GCC: (15:12.2.rel1-1) 12.2.1 20221205"
.text
	.align	2, 0

