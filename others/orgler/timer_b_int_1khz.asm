****************************************
** Register **
$include        'mr_regs.inc'

        ORG     $F000
START   RSP
        MOV     #$01,CONFIG
        MOV     #$30,TBSC       ; stop Timer to make changes
        MOV     #$54,TBSC0      ; compare with toggle + interrupt
        MOV     #$00,TBSC       ; start Timer
        CLI                     ; enable interrupt

LOOP        bra     LOOP

****************************************
INT_TB_CH0
        bclr    7,TBSC0
        lda     TBCH0L
        add     #$CC            ; add 1228 decimal
        sta     TBCH0L          ; hex 04 CC
        lda     TBCH0H
        adc     #$04
        sta     TBCH0H

        lda     TBCH0L          ; write again to low byte
        sta     TBCH0L

        RTI

********* Reset vector *********************

        ORG     $FFE2
        dw      INT_TB_CH0

        ORG     $FFFE
        dw      START

***  on PTE1 output compare with toggle 1 KHz  ***
