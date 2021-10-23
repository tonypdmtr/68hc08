# HC08_LED_PWM
HC08, QT2 or QT4, PWM to drive LED, code in asm, copy from the web.  slightly modified for demo purpose.

### modification
disabled the user control, no need for any user input, once power up, PA0 and PA1 will dim/lite LED constantly.
```
;                   brset     SWITCH,_1@@         ; start working only when pA2=1
;                   clr       TSC0
;                   clr       TSC1
;                   bra       MainLoop
```

### circuit diagram
see this [HC08-led-brightness-control-pwm-method/](https://xiaolaba.wordpress.com/2012/06/29/mc68hc908qt2-microcontroller-handles-led-brightness-control-pwm-method/)


### source code in asm

```
;*******************************************************************************
; Two dimming LED driver
;*******************************************************************************
; 9S08QT2 with internal fOsc=12.8MHz,
; TIMER time T(decimal)=50*T(ms)
; Modified by xiaolaba, fit for QT2 / QT4 2012-06-29
;*******************************************************************************

KHZ                 equ       12800               ;fOsc=12.8MHz
BUS_KHZ             equ       KHZ/4               ;BUS = 1/4 fOsc

RAM                 equ       $80                 ;beginning of RAM
ROM                 equ       $EE00               ;beginning of ROM

PWM_STEP            equ       6                   ;PWM inc/decrement, 6/50=0.12ms
PWM_PERIOD          equ       16*50               ;16ms (16*50=800)

PORTA               equ       $00
DDR                 equ       4                   ;offset for DDR register

CONFIG1             equ       $1F

TSC                 equ       $20
TMODH               equ       $23

TSC0                equ       $25
TCH0H               equ       $26
TCH0L               equ       $27

TSC1                equ       $28
TCH1H               equ       $29
TCH1L               equ       $2A

TSC_TOF             pin       TSC,7
;-------------------------------------------------------------------------------
; I/O
; pA0 output PWM to LED1
; pA1 output PWM to LED2
; pA2 input ON/OFF Control: ON(1),OFF(0)
;-------------------------------------------------------------------------------
LED1                pin       PORTA,1
LED2                pin       PORTA,2
SWITCH              pin       PORTA,2

;*******************************************************************************
                    #RAM      RAM                 ; VARIABLES
;*******************************************************************************

ramp_counter        rmb       1                   ; Ramp time counter

;*******************************************************************************
                    #ROM      ROM                 ; INITIALIZATION
;*******************************************************************************

Start               proc
                    rsp                           ; reset Stack Pointer = $FF
                    mov       #$01,CONFIG1        ; COP disabled
                    clrhx                         ; clear HX
                    clra
                    clr       ramp_counter

                    mov       #$03,TCH1H          ; set Initial pwLED2=6x128=800=$0300
                    clr       TCH1L

                    clr       TCH0H               ; set Initial pwLED1=0
                    clr       TCH0L

                    mov       #255,ramp_counter   ; set Initial ramp_counter (to be 0 after INC)

                    clr       PORTA

                    bset      LED1+DDR            ; make LED pins outputs
                    bset      LED2+DDR

                    ldhx      #PWM_PERIOD         ; PWM PERIOD save to TMODH
                    sthx      TMODH

                    mov       #%00010110,TSC      ; clear and start TIMER,prescaler:64
;                   bra       MainLoop

;*******************************************************************************

MainLoop            proc
;                   brset     SWITCH,_1@@         ; start working only when pA2=1
;                   clr       TSC0
;                   clr       TSC1
;                   bra       MainLoop

_1@@                brclr     TSC_TOF,*           ; wait for the end of PWM_PERIOD, loop here
                    bclr      TSC_TOF             ; TOF reset
                    inc       ramp_counter        ; set the next time step
                    lda       ramp_counter        ; is the time overpassed the ramp 1

                    cmpa      #128                ; duration?
                    bhs       _3@@

                    tst       ramp_counter        ; ramp_counter=0?
                    bne       _2@@                ; If not, go to _2@@
                    bsr       Delay               ; If yes, go to delay

_2@@                ldhx      TCH0H               ; increment pwLED1
                    aix       #PWM_STEP
                    sthx      TCH0H

                    ldhx      TCH1H               ; decrement pwLED2
                    aix       #-PWM_STEP
                    sthx      TCH1H
                    bra       _5@@

_3@@                bne       _4@@                ; ramp_counter=128? If not,go to _4@@
                    bsr       Delay               ; If yes,go to delay

_4@@                ldhx      TCH1H               ; increment pwLED2
                    aix       #PWM_STEP
                    sthx      TCH1H

                    ldhx      TCH0H               ; decrement pwLED1
                    aix       #-PWM_STEP
                    sthx      TCH0H

_5@@                mov       #%00011010,TSC0     ; start TCH0H on LED1
                    mov       #%00011010,TSC1     ; start TCH1H on LED2
                    bra       MainLoop

;*******************************************************************************

Delay               proc
                    lda       #30                 ; delay 3sec (30*100 msec)
Loop@@              bsr       Delay100ms
                    dbnza     Loop@@
                    rts

;*******************************************************************************
                              #Cycles
Delay100ms          proc
                    pshhx
                    ldhx      #DELAY@@
                              #Cycles
Loop@@              aix       #-1
                    cphx      #0
                    bne       Loop@@
                              #temp :cycles
                    pulhx
                    rts

DELAY@@             equ       100*BUS_KHZ-:cycles-:ocycles/:temp

;*******************************************************************************
                    #VECTORS
;*******************************************************************************
                    org       $FFFE               ; Vector reset
                    fdb       Start               ; Set start address
```


### Firmware image
```
S123EE009C6E011F8C5F4F3F806E03293F2A3F263F276EFF803F00120414044503203523E3
S123EE206E16200F20FD1F203C80B680A18024143D802602AD265526AF0635265529AFFA0A
S123EE40352920102602AD145529AF0635295526AFFA35266E1A256E1A2820C7A61EAD036F
S115EE604BFC81898B459C3DAFFF65000026F98A8881DD
S105FFFEEE000F
S9030000FC
```
