                    #Uses     mr_regs.inc

SIG_A               pin       PORTB,4
SIG_B               pin

;*******************************************************************************
                    #RAM      $60
;*******************************************************************************

adc_val             rmb       1
lcdbuf              rmb       3

;*******************************************************************************
                    #ROM      $8000
;*******************************************************************************

Start               proc
                    mov       #$91,CONFIG         ;EDGE=1, INDEP=1, COPD=1 (cop disabled)
                    clr       PORTB
                    mov       #$3F,DDRB

                    lda       #$03
                    bsr       LcdInstr1

                    lda       #$03
                    bsr       LcdInstr1

                    lda       #$03
                    bsr       LcdInstr1
                                                  ;                 x  x  x DL N  F  x  x
                    lda       #%00101000          ;28 Function Set: 0  0  1  0 1  0  0  0
                    bsr       LcdInstr2           ;DL: 0=4-Bit-Interface 1=8-Bit-Interface

                    lda       #%00001100          ;0C
                    bsr       LcdInstr2
                                                  ;               x  x  x  x  x  x  ID S
                    lda       #%00000110          ;06 Entry Mode: 0  0  0  0  0  1  1  0
                    bsr       LcdInstr2           ;ID : 0=Adress decrement 1=Adress Increment

                    lda       #$80                ;Set cursor to HOME
                    bsr       LcdInstr2

                    lda       #'L'
                    bsr       WriteLcdData

                    lda       #'C'
                    bsr       WriteLcdData

                    lda       #'D'
                    bsr       WriteLcdData

                    mov       #$70,ADCLK          ;8-bit conversion

Loop@@              mov       #7,ADSCR
                    bsr       Delay
                    ldhx      ADRH
                    stx       adc_val
                    bsr       BINASCII
                    bsr       LCDOUT
                    bra       Loop@@

;*******************************************************************************

BINASCII            proc
                    mov       #'0',lcdbuf
                    mov       #'0',lcdbuf+1
                    mov       #'0',lcdbuf+2
          ;--------------------------------------
                    lda       adc_val
_100@@              cmpa      #100
                    blo       _10@@
                    sub       #100
                    inc       lcdbuf
                    bra       _100@@
          ;--------------------------------------
_10@@               cmpa      #10
                    blo       _1@@
                    sub       #10
                    inc       lcdbuf+1
                    bra       _10@@
          ;--------------------------------------
_1@@                add       lcdbuf+2
                    sta       lcdbuf+2
                    rts

;*******************************************************************************

LCDOUT              proc
                    lda       #$85                ;set cursor first line position 5
                    bsr       LcdInstr2

                    lda       lcdbuf
                    bsr       WriteLcdData

                    lda       lcdbuf+1
                    bsr       WriteLcdData

                    lda       lcdbuf+2
                    bra       WriteLcdData

;*******************************************************************************
; LCD UTIL

LcdInstr2           proc
                    psha
                    nsa
                    bsr       ?Write
                    pula
;                   bra       LcdInstr1

;*******************************************************************************

LcdInstr1           proc
                    bsr       ?Write
                    bra       Delay

;*******************************************************************************

?Write              proc
                    and       #$0F
                    sta       PORTB
                    bclr      SIG_B
                    bset      SIG_A
                    bclr      SIG_A
                    rts

;*******************************************************************************

WriteLcdData        proc
                    psha
                    nsa
                    and       #$0F
                    sta       PORTB
                    pula

                    bset      SIG_B
                    bset      SIG_A
                    bclr      SIG_A

                    and       #$0F
                    sta       PORTB
                    bset      SIG_B
                    bset      SIG_A
                    bclr      SIG_A
;                   bra       Delay

;*******************************************************************************

Delay               proc
                    pshhx
                    ldhx      #8192
Loop@@              aix       #-1
                    cphx      #0
                    bne       Loop@@
                    pulhx
                    rts

;*******************************************************************************
                    #VECTORS
;*******************************************************************************
                    org       $FFFE
                    dw        Start
