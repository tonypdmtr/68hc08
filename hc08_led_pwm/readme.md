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
****************************************************************
*     Two dimming LEDs driver                        *
******************************************************
* Internal fosc=12.8MHz,
* TIMER time T(decimal)=50*T(ms)
* Pulse Width increment/decrement=6,i.e 6/50=0.12ms

$nolist
;$include 'Fr908qt2.asm' ;frame file for 908QT2

; modified by xiaolaba, fit for QT2 / QT4
; 2012-06-29
; -------------------
RAM     equ     $80
ROM     equ     $EE00
prtA    equ     $0
pA0.    equ     $1
pA1.    equ     $2
TOF     equ     7

CONFIG2 EQU $001E
CONFIG1 EQU $001F

PORTA   EQU $0000
PORTB   EQU $0001
DDRA    EQU $0004
DDRB    EQU $0005
PTAPUE  EQU $000B
PTBPUE  EQU $000C

TSC     EQU $0020
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

OSCSTAT EQU $0036
OSCTRIM EQU $0038
; -------------------

$list
*I/O

*pA0 output PWM to LED1
*pA1 output PWM to LED2
*pA2 input ON/OFF Control: ON(1),OFF(0)

* CONSTANTS
PERIOD_PWM  EQU $320 ;period PWM=16ms (16*50=800=$320)

*VARIABLES
  ORG RAM
Tcnt        RMB 1    ;Ramp time counter
cnt01s      RMB 1    ;delay counter

*INITIALIZATION
  ORG ROM
init:
  RSP                ;reset Stack Pointer = $FF
  MOV   #$01,CONFIG1 ;COP disabled
  CLRH               ;clear H:X
  CLRX
  CLRA
  clr   Tcnt        ;

  MOV   #$03,Tch1H      ;set Initial pwLED2=6x128=800=$0300
  clr   Tch1L

  clr   Tch0H           ;set Initial pwLED1=0
  clr   Tch0L

  clr   cnt01s

  MOV   #255T,Tcnt      ;set Initial Tcnt (to be 0 after INC)
  CLR   prtA            ;
  MOV   #pA0.+pA1.,DDRA ;set I/O prtA

  LDHX  #PERIOD_PWM     ;PWM PERIOD save to TmodH
  STHX  TmodH

  MOV   #%00010110,TSC  ;clear and start TIMER,prescaler:64

.page
MAIN:
;  brset 2,prtA,m4    ;start working only when pA2=1
;  CLR   TSC0
;  CLR   TSC1
;  BRA   MAIN
m4:
  BRCLR TOF,TSC,*    ;wait for the end of PERIOD_PWM, loop here
  BCLR  TOF,TSC      ;TOF reset
  INC   Tcnt         ;set the next time step
  LDA   Tcnt         ;is the time overpassed the ramp 1
m1:
  CMP   #128T        ;duration?
  BHS   m3
***************************************
  tst   Tcnt         ;Tcnt=0?
  bne   ramp1        ;If not, go to ramp1
  jsr   dly          ;If yes, go to delay
ramp1:
  LDHX  Tch0H        ;increment pwLED1
  AIX   #6T
  STHX  Tch0H
  LDHX  Tch1H        ;decrement pwLED2
  AIX   #-6T
  STHX  Tch1H
  BRA   m2
****************************************
m3:
  bne   ramp2        ;Tcnt=128? If not,go to ramp2
  jsr   dly          ;          If yes,go to delay
ramp2:
  LDHX  Tch1H        ;increment pwLED2
  AIX   #6T
  STHX  Tch1H
  LDHX  Tch0H        ;decrement pwLED1
  AIX   #-6T
  STHX  Tch0H
****************************************
m2:
  MOV   #%00011010,TSC0 ;start Tch0H on pA0
  MOV   #%00011010,TSC1 ;start Tch1H on pA1
  JMP   MAIN
**************************************************************
dly:
  LDA   #30T          ;delay 3sec
lp0:
  JSR   dly01s
  DBNZA lp0
  rts
**************************************************************
dly01s:
  LDX   #250T         ;delay0.1sec
loop:
  DBNZ  cnt01s,loop
  DBNZX loop
  rts
**************************************************************
  ORG $FFFE  ; Vector reset
  FDB init   ; Set start address

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
