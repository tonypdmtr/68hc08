# HC08_LED_PWM
HC08, QT2 or QT4, PWM to drive LED, code in asm, copy from the web.  slightly modified for demo purpose.

### modification
disabled the user control, no need for any user input, once power up, PA0 and PA1 will dim/lite LED constantly.
```
;  brset 2,prtA,m4    ;start working only when pA2=1
;  CLR   TSC0
;  CLR   TSC1
;  BRA   MAIN
```

### circuit diagram
see this [HC08-led-brightness-control-pwm-method/](https://xiaolaba.wordpress.com/2012/06/29/mc68hc908qt2-microcontroller-handles-led-brightness-control-pwm-method/)


### source code in asm

```
;*******************************************************************************
; Two dimming LEDs driver
;*******************************************************************************
; Internal fosc=12.8MHz,
; TIMER time T(decimal)=50*T(ms)
; Pulse Width increment/decrement=6,i.e 6/50=0.12ms
                    #NoList
;                   #Include  Fr908qt2.asm        ;frame file for 908QT2
;
; Modified by xiaolaba, fit for QT2 / QT4
; 2012-06-29
;*******************************************************************************

RAM                 equ       $80
ROM                 equ       $EE00

PORTA               equ       $0000
DDRA                equ       $0004

pA0.                equ       1
pA1.                equ       2
TOF.                equ       7

CONFIG1             equ       $001F
TSC                 equ       $0020
TMODH               equ       $0023
TSC0                equ       $0025
TCH0H               equ       $0026
TCH0L               equ       $0027
TSC1                equ       $0028
TCH1H               equ       $0029
TCH1L               equ       $002A

;-------------------------------------------------------------------------------
; I/O
;-------------------------------------------------------------------------------
; pA0 output PWM to LED1
; pA1 output PWM to LED2
; pA2 input ON/OFF Control: ON(1),OFF(0)

;-------------------------------------------------------------------------------
; CONSTANTS
;-------------------------------------------------------------------------------

PERIOD_PWM          equ       $320                ; period PWM=16ms (16*50=800=$320)

;*******************************************************************************
                    #RAM
;*******************************************************************************
                    org       RAM

tcnt                rmb       1                   ; Ramp time counter
cnt01s              rmb       1                   ; delay counter

;*******************************************************************************
                    #ROM
;*******************************************************************************
                    org       ROM

Start               proc
                    rsp                           ; reset Stack Pointer = $FF
                    mov       #$01,CONFIG1        ; COP disabled
                    clrhx                         ; clear HX
                    clra
                    clr       tcnt

                    mov       #$03,TCH1H          ; set Initial pwLED2=6x128=800=$0300
                    clr       TCH1L

                    clr       TCH0H               ; set Initial pwLED1=0
                    clr       TCH0L

                    clr       cnt01s

                    mov       #255,tcnt           ; set Initial tcnt (to be 0 after INC)
                    clr       PORTA
                    mov       #pA0.+pA1.,DDRA     ; set I/O PORTA

                    ldhx      #PERIOD_PWM         ; PWM PERIOD save to TMODH
                    sthx      TMODH

                    mov       #%00010110,TSC      ; clear and start TIMER,prescaler:64
;                   bra       MainLoop

;*******************************************************************************

MainLoop            proc
;                   brset     2,PORTA,_1@@        ; start working only when pA2=1
;                   clr       TSC0
;                   clr       TSC1
;                   bra       MainLoop

_1@@                brclr     TOF.,TSC,*          ; wait for the end of PERIOD_PWM, loop here
                    bclr      TOF.,TSC            ; TOF reset
                    inc       tcnt                ; set the next time step
                    lda       tcnt                ; is the time overpassed the ramp 1
                    cmpa      #128                ; duration?
                    bhs       _3@@
          ;--------------------------------------
                    tst       tcnt                ; tcnt=0?
                    bne       _4@@                ; If not, go to _4@@
                    bsr       dly                 ; If yes, go to delay

_4@@                ldhx      TCH0H               ; increment pwLED1
                    aix       #6
                    sthx      TCH0H
                    ldhx      TCH1H               ; decrement pwLED2
                    aix       #-6
                    sthx      TCH1H
                    bra       _2@@
          ;--------------------------------------
_3@@                bne       ramp2               ; tcnt=128? If not,go to ramp2
                    bsr       dly                 ; If yes,go to delay
ramp2
                    ldhx      TCH1H               ; increment pwLED2
                    aix       #6
                    sthx      TCH1H
                    ldhx      TCH0H               ; decrement pwLED1
                    aix       #-6
                    sthx      TCH0H
          ;--------------------------------------
_2@@                mov       #%00011010,TSC0     ; start TCH0H on pA0
                    mov       #%00011010,TSC1     ; start TCH1H on pA1
                    bra       MainLoop

;*******************************************************************************

dly                 proc
                    lda       #30                 ; delay 3sec
Loop@@              bsr       dly01s
                    dbnza     Loop@@
                    rts

;*******************************************************************************

dly01s              proc
                    ldx       #250                ; delay0.1sec
Loop@@              dbnz      cnt01s,*
                    dbnzx     Loop@@
                    rts

;*******************************************************************************
                    #VECTORS
;*******************************************************************************
                    org       $FFFE               ; Vector reset
                    fdb       Start               ; Set start address
```


### Firmware image
```
S113EE009C6E011F8C5F4F3F806E03293F2A3F2673
S113EE103F273F816EFF803F006E0304450320358A
S113EE20236E16200F20FD1F203C80B680A1802475
S113EE30153D802603CDEE605526AF0635265529AF
S113EE40AFFA352920112603CDEE605529AF0635DA
S113EE50295526AFFA35266E1A256E1A28CCEE24CB
S113EE60A61ECDEE684BFB81AEFA3B81FD5BFB81B8
S105FFFEEE000F
S9030000FC

```
