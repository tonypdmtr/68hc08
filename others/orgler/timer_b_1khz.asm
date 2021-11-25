****************************************
** Register **
$include        'mr_regs.inc'

        ORG     $F000
START   RSP
        MOV     #$01,CONFIG
        MOV     #$FF,DDRB
        MOV     #$AA,PORTB
        MOV     #$30,TBSC       ; stop Timer to make changes
        MOV     #$14,TBSC0      ; compare with toggle
        MOV     #$00,TBSC       ; start Timer

LOOP    lda     TBSC0
        bpl     LOOP
        bclr    7,TBSC0
        lda     PORTB           ; on PORTB 1 Khz
        eor     #$FF
        sta     PORTB
*       ---------------
        lda     TBCH0L
        add     #$CC            ; add 1228 decimal
        sta     TBCH0L          ; hex 04 CC
        lda     TBCH0H
        adc     #$04
        sta     TBCH0H

        lda     TBCH0L          ; write again to low byte
        sta     TBCH0L
*       ----------------

        bra     LOOP

********* Reset vector *********************
        ORG     $FFFE
        dw      START

***  on PTE1 output compare with toggle 1 KHz  ***
