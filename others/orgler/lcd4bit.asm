$Include 'mr_regs.inc'

                org  $8000

START           mov     #$91,CONFIG     ; EDGE=1, INDEP=1, COPD=1 (cop disabled)
                rsp
                mov     #$00,PORTB
                mov     #$3F,DDRB

                lda     #$03
                bsr     LcdInstr1
                lda     #$03
                bsr     LcdInstr1
                lda     #$03
                bsr     LcdInstr1
                                     ;                  x  x  x  DL N  F  x  x
                lda     #%00101000   ; 28 Function Set: 0  0  1  0  1  0  0  0
                bsr     LcdInstr2    ; DL: 0=4-Bit-Interface  1=8-Bit-Interface

                lda     #%00001100   ;0C
                bsr     LcdInstr2
                                       ;               x  x  x  x  x  x  ID S
                lda     #%00000110     ;06 Entry Mode: 0  0  0  0  0  1  1  0
                bsr     LcdInstr2      ; ID : 0=Adress decrement 1=Adress Increment

                lda    #$80            ; set cursor to home position
                bsr     LcdInstr2

                lda     #'O'           ; write OKAY to LCD
                bsr     WriteLcdData
                lda     #'K'
                bsr     WriteLcdData
                lda     #'A'
                bsr     WriteLcdData
                lda     #'Y'
                bsr     WriteLcdData

LOOP            bra     LOOP

******************** LCD UTIL ***************************
LcdInstr2       psha
                lsra
                lsra
                lsra
                lsra
                sta     PORTB
                bclr    5,PORTB
                bset    4,PORTB
                bclr    4,PORTB
                pula
LcdInstr1       and     #$0F
                sta     PORTB
                bclr    5,PORTB
                bset    4,PORTB
                bclr    4,PORTB
                bsr     Delay
                rts
;               ----
WriteLcdData    psha
                lsra
                lsra
                lsra
                lsra
                sta     PORTB
                bset    5,PORTB
                bset    4,PORTB
                bclr    4,PORTB
                pula
                and     #$0F
                sta     PORTB
                bset    5,PORTB
                bset    4,PORTB
                bclr    4,PORTB
                bsr     Delay
                rts

Delay           ldhx    #$2000
next_x          aix     #-1
                cphx    #0
                bne     next_x
                rts

                ORG    $FFFE
                dw     START
