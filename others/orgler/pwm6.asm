RomStart     EQU  $8000         ; Valid Rom for MR32

$Include 'mr_regs.inc'

        org RomStart

START   rsp
        mov #$91,CONFIG     ; EDGE=1, INDEP=1, COPD=1 (cop disabled)
        ldhx  #256        ; Load Counter Modulo Register with 256
        sthx  PMODH

        ldhx  #0           ; PWM 0/6
        sthx  PVAL1H

        ldhx  #43          ; PWM 1/6
        sthx  PVAL2H

        ldhx  #85          ; PWM 2/6
        sthx  PVAL3H

        ldhx  #128         ; PWM 3/6
        sthx  PVAL4H

        ldhx  #171         ; PWM 4/6
        sthx  PVAL5H

        ldhx  #213         ; PWM 5/6
        sthx  PVAL6H

        mov   #00,PCTL2     ; Reload every PWM cycle, fastest PWM frequency
        mov   #03,PCTL1     ; no interrupt, load parameters, PWM on
        bset  1,PCTL1       ; force reload on PWM parameters
        mov   #$3F,PWMOUT

LOOP    inc   PVAL1L
        inc   PVAL2L
        inc   PVAL3L
        inc   PVAL4L
        inc   PVAL5L
        inc   PVAL6L

        bset  1,PCTL1        ; force reload on PWM parameters

        ldhx  #0
next_x  aix   #1
        cphx  #$800
        blo   next_x

        bra   LOOP

        ORG  $FFFE
        dw   START    ; Reset Vector
