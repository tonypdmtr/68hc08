$Include 'mr_regs.inc'

                org $60
ADC_WERT        DS      1
LCDBUF1         DS      1
LCDBUF2         DS      1
LCDBUF3         DS      1

                 org    $8000

START           mov    #$91,CONFIG     ; EDGE=1, INDEP=1, COPD=1 (cop disabled)
                rsp                    ; reset stack pointer
                mov    #0,PORTB
                mov    #$3F,DDRB

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

                lda    #$80            ; Set cursor to HOME
                bsr     LcdInstr2
                lda     #'L'
                bsr     WriteLcdData
                lda     #'C'
                bsr     WriteLcdData
                lda     #'D'
                bsr     WriteLcdData

                mov     #$70,ADCLK   ; 8 Bit conversion

LOOP            lda     #7
                sta     ADSCR
                bsr     Delay
                ldhx    ADRH
                stx     ADC_WERT
                bsr     BINASCII
                bsr     LCDOUT

                bra     LOOP

BINASCII        mov     #$30,LCDBUF1
                mov     #$30,LCDBUF2
                mov     #$30,LCDBUF3
                lda     ADC_WERT
CHECK_100       cmp     #100
                blo     CHECK_10
                sub     #100
                inc     LCDBUF1
                bra     CHECK_100
CHECK_10        cmp     #10
                blo     CHECK_1
                sub     #10
                inc     LCDBUF2
                bra     CHECK_10
CHECK_1         add     LCDBUF3
                sta     LCDBUF3
                rts

LCDOUT          lda     #$85      ; set cursor first line position 5
                bsr     LcdInstr2
                lda     LCDBUF1
                bsr     WriteLcdData
                lda     LCDBUF2
                bsr     WriteLcdData
                lda     LCDBUF3
                bsr     WriteLcdData
                rts

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
WriteLcdData    psha            ; save A -> stack
                lsra
                lsra
                lsra
                lsra
                sta     PORTB
                bset    5,PORTB
                bset    4,PORTB
                bclr    4,PORTB
                pula            ; load A from stack
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
