$Include 'mr_regs.inc'

       org $8000

START  mov   #$91,CONFIG    ; EDGE=1, INDEP=1, COPD=1 (cop disabled)
       ldhx  #$100          ; Load Counter Modulo Register with 256
       sthx  PMODH

       ldhx  #$20           ; PWM 25%
       sthx  PVAL1H

       mov   #0,PCTL2       ; Reload every PWM cycle, fastest PWM frequency
       mov   #3,PCTL1       ; no interrupt, load parameters, PWM on
       bset  1,PCTL1        ; force reload on PWM parameters
       mov   #$3F,PWMOUT

LOOP

       bra LOOP

       ORG $FFFE
       dw   START             ; Reset Vector
