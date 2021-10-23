;*******************************************************************************
; The following math package is from the HITACHI handbook
; (slightly modified for the 68HC08)
; and adapted to ASM8 by <tonyp@acm.org>
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
binary              @var      2,6
bin2                @var      2
bin3                @var      2
digits              @var      6
digptr              equ       digits+5
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; ADD --- ADDING 16-BIT BINARY DATA
;         ENTRY : ADED
;                 ADER
;       RETURNS : ADED (SUM)
;                 CARRY (C=0:TRUE
;                        C=1:OVER FLOW)

ADD                 proc
aded@@              equ       binary
ader@@              equ       bin2

                    lda       aded@@+1
                    add       ader@@+1
                    sta       aded@@+1

                    lda       aded@@
                    adc       ader@@
                    sta       aded@@
                    rts

;*******************************************************************************
; SUB --- SUBTRACTING 16-BIT BINARY DATA
;         ENTRY : SBED (MINUEND)
;                 SBER (SUBTRAHEND)
;       RETURNS : SBED (RESIDUAL)
;                 CARRY (C=0:TRUE
;                        C=1:BORROW)

SUB                 proc
sbed@@              equ       binary
sber@@              equ       bin2

                    lda       sbed@@+1
                    sub       sber@@+1
                    sta       sbed@@+1

                    lda       sbed@@
                    sbc       sber@@
                    sta       sbed@@
                    rts

;*******************************************************************************
; MUL --- 16-BIT MULTIPLATION
;         ENTRY : MACAND (MULTIPLAND)
;                 MER (MULTIPLIER)
;       RETURNS : PRDCT (UPPER PRODUCT)
;                 MER (LOWER PRODUCT)

MUL                 proc
mcand@@             equ       binary
mer@@               equ       bin2
prdct@@             equ       bin3

                    clr       prdct@@             ; clear product area
                    clr       prdct@@+1

                    ldx       #16                 ; set bit counter
Loop@@              brclr     mer@@+1,Rotate@@    ; branch if MER(0)=0

                    lda       mcand@@+1           ; mcand + prdct -> prdct
                    add       prdct@@+1
                    sta       prdct@@+1

                    lda       mcand@@
                    adc       prdct@@
                    sta       prdct@@

Rotate@@            ror       prdct@@             ; rotate product area
                    ror       prdct@@+1
                    ror       mer@@               ; rotate multiplier area and
                    ror       mer@@+1             ; ..set LSB of MER to carry
                    dbnzx     Loop@@              ; decrement bit counter until = 0
                    rts

;*******************************************************************************
; DIV --- DIVING 16-BIT BINARY DATA
;         ENTRY : DVD (DIVIDEND)
;                 DVS (DIVISOR)
;       RETURNS : DVD (QUOTIENT)
;                 RSD (RESIDUAL)

DIV                 proc
dvd@@               equ       binary
dvs@@               equ       bin2
rsd@@               equ       bin3

                    ldx       #16                 ; set shift counter
                    clr       rsd@@               ; clear work
                    clr       rsd@@+1

Loop@@              sec                           ; set LSB of residual to one

                    rol       dvd@@+1             ; shift dividend and set MSB
                    rol       dvd@@               ; of dividend to LSB of work
                    rol       rsd@@+1
                    rol       rsd@@

                    lda       rsd@@+1             ; work - divisor -> work
                    sub       dvs@@+1
                    sta       rsd@@+1

                    lda       rsd@@
                    sbc       dvs@@
                    sta       rsd@@
                    bcc       Cont@@              ; branch if work > divisor

                    lda       dvs@@+1             ; work + divisor -> work
                    add       rsd@@+1
                    sta       rsd@@+1

                    lda       dvs@@
                    adc       rsd@@
                    sta       rsd@@

                    dec       dvd@@+1             ; clear LCB of residual area
Cont@@              dbnzx     Loop@@              ; decrement shift counter until = 0
                    rts

;*******************************************************************************
; CMD --- COMPARING 16-BIT BINARY DATA
;         ENTRY : CMD (COMPARAND)
;                 CMT (COMPARATIVE NUMBER)
;       RETURNS : CARRY & BIT 2 (COMPARISON RESULT)

CMP                 proc
cmd@@               equ       binary
cmt@@               equ       bin2

                    lda       cmd@@               ; compare with upper byte
                    cmpa      cmt@@
                    bne       Done@@
                    lda       cmd@@+1
                    cmpa      cmt@@+1
Done@@              rts

;*******************************************************************************
; SHR --- SHIFTING RIGHT 16-BIT DATA
;         ENTRY : SFT (16-BIT BINARY DATA)
;                 IX  (SHIFT COUNTER)
;       RETURNS : SFT (16-BIT BINARY DATA)
;
; Used for fast divide by powers of 2.
;
; Enter with number of times to shift in X.

SHR                 proc
n@@                 equ       binary
Loop@@              lsr       n@@                 ; shift upper byte to right
                    ror       n@@+1               ; rotate lower byte to right
                    dbnzx     Loop@@              ; decrement shift counter until = 0
                    rts

;*******************************************************************************
; CONVERT 16-BIT BINARY TO BCD
; Enter with number to be converted in BINARY
; Output goes into DIGITS array

CONVERT             proc
number@@            equ       bin2
index@@             equ       digptr

                    ldhx      #::digits           ; clear digits array and digptr
Init@@              clr       digits-1,x
                    dbnzx     Init@@

MainLoop@@          lda       Table@@,x
                    sta       number@@
                    lda       Table@@+1,x
                    sta       number@@+1
Loop@@              bsr       SUB
                    bcs       Borrow@@            ; borrow?
                    txa                           ; increment digit
                    ldx       index@@
                    inc       digits,x
                    tax
                    bra       Loop@@

Borrow@@            jsr       ADD                 ; restore it
                    inc       index@@
                    incx:2
                    cmpx      #10                 ; finished
                    bne       MainLoop@@
                    rts

;-------------------------------------------------------------------------------
; TABLE OF POWERS OF TEN
;-------------------------------------------------------------------------------

Table@@             fdb       10000
                    fdb       1000
                    fdb       100
                    fdb       10
                    fdb       1
