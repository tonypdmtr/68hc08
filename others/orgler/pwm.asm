*** Orgler electronic  PWM generation*****
RAMStart       EQU  $0080

PORTD   EQU $0003
DDRD    EQU $0007
CONFIG1 EQU $001F    ; System configuration register
TSC     EQU $0020      ; Timer
TCNTH   EQU $0021
TCNTL   EQU $0022
TMODH   EQU $0023
TMODL   EQU $0024
TSC0    EQU $0025
TCH0H   EQU $0026
TCH0L   EQU $0027
TSC1    EQU $0028
TCH1H   EQU $0029
TCH1L   EQU $002A

               org RAMStart
LedCounter      ds  2

                 org $F000
*********************************************************************
START             rsp
                  mov     #$01,CONFIG1
*----------------------------------------------------------------
                  mov    #%10000000,PORTD
                  lda    #%11000000
                  sta    DDRD
*--------------------------------------------

                  mov    #$32,TSC      ; Timer A - Cleared + Stopped.
                  ldhx   #$0100
                  sthx   TMODH

                  ldhx  #$0040        ;duty cycle of 25%
                  sthx   TCH0H

                  mov   #$1A,TSC0
;  CH0F CH0IE MS0B MS0A ELS0B ELS0A TOV0 CH0MAX
;   0     0    1     1    0     1     0     0   $34 toggle
;   0     0    0     1    1     0     1     0   $1A clear
;   0     0    0     1    1     1     1     0   $1E set
; if TOV==1 toggle on Timer Overflow TOV

                  mov   #$02,TSC   ; Start the timer -> prescaler 4
**********************************************************************
**********************************************************************
LOOP
*               ---------- blink led PTD6(PIN10)  and PTD7 (PIN 9) ----
                 ldhx   LedCounter
                 aix    #-1
                 cphx   #0
                 bne    SaveLedCounter
                 lda    PORTD
                 eor    #%11000000
                 sta    PORTD
*                ---
                 ldhx   #$4000
SaveLedCounter   sthx   LedCounter
*               ----------------------
                 bra     LOOP
**************************************************************

                org $FFFE
        dw  START        ; Reset Vector
