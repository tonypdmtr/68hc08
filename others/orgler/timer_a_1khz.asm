****************************************
** Register **
$include        'mr_regs.inc'

        ORG     $F000
START   RSP
        MOV     #$01,CONFIG
        MOV     #$FF,DDRB
        MOV     #$AA,PORTB
        MOV     #$30,TASC       ; stop Timer to make changes
        MOV     #$14,TASC0      ; compare with toggle
        MOV     #$00,TASC       ; start Timer

LOOP    lda     TASC0
        bpl     LOOP
        bclr    7,TASC0
        lda     PORTB           ; on PORTA 1 Khz
        eor     #$FF
        sta     PORTB
*       ---------------
        lda     TACH0L
        add     #$CC            ; add 1228 decimal
        sta     TACH0L          ; hex 04 CC
        lda     TACH0H
        adc     #$04
        sta     TACH0H

        lda     TACH0L          ; write again to low byte
        sta     TACH0L
*       ----------------

        bra     LOOP

********* Reset vector *********************
        ORG     $FFFE
        dw      START

***  on PTE4 output compare with toggle 1 KHz  ***
