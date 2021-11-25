PORTD   EQU $0003
DDRD    EQU $0007
CONFIG1 EQU $001F
TSC     EQU $0020
TSC0    EQU $0025

          org    $F000
START     mov   #$01,CONFIG1    ; disable COP
          mov   #$FF,DDRD       ; Set all outputs
          mov   #$30,TSC        ; Timer STOP and RESET
          mov   #$14,TSC0       ; set TIMER action
          mov   #0,TSC          ; start the TIMER

LOOP      lda   PORTD
          eor   #$FF
          sta   PORTD
          bra   LOOP

          org $FFFE
          dw  START                   ; Reset Vector

;PORTD BIT [PIN 19] output frequency 18,8 Hz
;PORTD BIT [PIN ] output frequency 112 KHz
