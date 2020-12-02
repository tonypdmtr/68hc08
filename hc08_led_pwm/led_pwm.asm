;*******************************************************************************
; Two dimming LED driver
;*******************************************************************************
; Internal fOsc=12.8MHz,
; TIMER time T(decimal)=50*T(ms)
; Pulse Width increment/decrement=6,i.e 6/50=0.12ms
; $include 'Fr908qt2.asm' ;frame file for 908QT2
;
; Modified by xiaolaba, fit for QT2 / QT4
; 2012-06-29
;*******************************************************************************

RAM                 equ       $80
ROM                 equ       $EE00
prtA                equ       0
pA0.                equ       1
pA1.                equ       2
TOF                 equ       7

CONFIG1             equ       $001F

DDRA                equ       $0004

TSC                 equ       $0020
TMODH               equ       $0023
TSC0                equ       $0025
TCH0H               equ       $0026
TCH0L               equ       $0027
TSC1                equ       $0028
TCH1H               equ       $0029
TCH1L               equ       $002A

; I/O

; pA0 output PWM to LED1
; pA1 output PWM to LED2
; pA2 input ON/OFF Control: ON(1),OFF(0)

; CONSTANTS
PERIOD_PWM          equ       $320                ; period PWM=16ms (16*50=800=$320)

;*******************************************************************************
                    #RAM                          ; VARIABLES
;*******************************************************************************
                    org       RAM

ramp_counter        rmb       1                   ; Ramp time counter
delay_counter       rmb       1                   ; delay counter

;*******************************************************************************
                    #ROM                          ; INITIALIZATION
;*******************************************************************************
                    org       ROM

Start               proc
                    rsp                           ; reset Stack Pointer = $FF
                    mov       #$01,CONFIG1        ; COP disabled
                    clrh                          ; clear H:X
                    clrx
                    clra
                    clr       ramp_counter

                    mov       #$03,Tch1H          ; set Initial pwLED2=6x128=800=$0300
                    clr       Tch1L

                    clr       Tch0H               ; set Initial pwLED1=0
                    clr       Tch0L

                    clr       delay_counter

                    mov       #255,ramp_counter   ; set Initial ramp_counter (to be 0 after INC)
                    clr       prtA
                    mov       #pA0.+pA1.,DDRA     ; set I/O prtA

                    ldhx      #PERIOD_PWM         ; PWM PERIOD save to TmodH
                    sthx      TmodH

                    mov       #%00010110,TSC      ; clear and start TIMER,prescaler:64
;                   bra       MainLoop

;*******************************************************************************

MainLoop            proc
;                   brset     2,prtA,_1@@         ; start working only when pA2=1
;                   clr       TSC0
;                   clr       TSC1
;                   bra       MainLoop

_1@@                brclr     TOF,TSC,*           ; wait for the end of PERIOD_PWM, loop here
                    bclr      TOF,TSC             ; TOF reset
                    inc       ramp_counter        ; set the next time step
                    lda       ramp_counter        ; is the time overpassed the ramp 1

                    cmp       #128                ; duration?
                    bhs       _3@@

                    tst       ramp_counter        ; ramp_counter=0?
                    bne       _2@@                ; If not, go to _2@@
                    bsr       Delay               ; If yes, go to delay

_2@@                ldhx      Tch0H               ; increment pwLED1
                    aix       #6
                    sthx      Tch0H
                    ldhx      Tch1H               ; decrement pwLED2
                    aix       #-6
                    sthx      Tch1H
                    bra       _5@@

_3@@                bne       _4@@                ; ramp_counter=128? If not,go to _4@@
                    bsr       Delay               ; If yes,go to delay

_4@@                ldhx      Tch1H               ; increment pwLED2
                    aix       #6
                    sthx      Tch1H
                    ldhx      Tch0H               ; decrement pwLED1
                    aix       #-6
                    sthx      Tch0H

_5@@                mov       #%00011010,TSC0     ; start Tch0H on pA0
                    mov       #%00011010,TSC1     ; start Tch1H on pA1
                    bra       MainLoop

;*******************************************************************************

Delay               proc
                    lda       #30                 ; delay 3sec
Loop@@              bsr       Delay100ms
                    dbnza     Loop@@
                    rts

;*******************************************************************************

Delay100ms          proc
                    ldx       #250                ; delay 100 msec
Loop@@              dbnz      delay_counter,*
                    dbnzx     Loop@@
                    rts

;*******************************************************************************
                    #VECTORS
;*******************************************************************************
                    org       $FFFE               ; Vector reset
                    fdb       Start               ; Set start address
