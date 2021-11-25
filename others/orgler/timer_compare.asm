****************************************
** Register **
$include        'mr_regs.inc'

        ORG     $F000
START   RSP
        MOV     #$01,CONFIG
        MOV     #$FF,DDRB
        MOV     #$AA,PORTB
        MOV     #$30,TBSC       ; stop Timer to make changes
        MOV     #$10,TBSC0      ; only compare
        MOV     #$00,TBSC       ; start Timer

LOOP    lda     TBSC0
        bpl     LOOP		; wait until BIT7 is set
        bclr    7,TBSC0
        lda     PORTB           ; on PORTB 18.76 Hz
        eor     #$FF
        sta     PORTB

        bra     LOOP

********* Reset vector *********************
        ORG     $FFFE
        dw      START
