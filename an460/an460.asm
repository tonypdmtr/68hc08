;*******************************************************************************
; HC05E0 RDS Decoder.
; P. Topping 29th February '92
; Ported to FL16 by Tony Papadimitriou starting on 2021-12-27
;*******************************************************************************

RAM                 def       $0030
XRAM                def       $0100
ROM                 def       $E000
          ;-------------------------------------- ;Port Registers
PORTA               equ       $00
PORTB               equ       $01
PORTC               equ       $02
PORTD               equ       $03
PORTE               equ       $04
          ;-------------------------------------- ;Data Direction Registers
DDRA                equ       $05
DDRB                equ       $06
DDRC                equ       $07
DDRD                equ       $08
DDRE                equ       $09
          ;-------------------------------------- ;Other Registers
TAP                 equ       $0A                 ;TIMER A PRESCALER
TBS                 equ       $0B                 ;TIMER B PRESCALER
TCR                 equ       $0C                 ;TIMER CONTROL REGISTER
ICR                 equ       $0E                 ;INTERRUPT CONTROL REGISTER
PORTDSF             equ       $12                 ;PORTD SPECIAL FUNCTIONS
          ;--------------------------------------
ND                  equ       9                   ;No. BCD DIGITS

;*******************************************************************************
; PIN definitions
;*******************************************************************************

LCD_BUSY            pin       PORTD,3             ;LCD MODULE BUSY FLAG
LCD_CLK             pin       PORTD,4             ;LCD CLOCK
LCD_DATA            pin       PORTD,2             ;LCD DATA
SWITCH              pin       PORTE,3             ;Switch output
ALARM_SWITCH        pin       PORTE,1             ;Alarm switch input
ALARM_BUZZER        pin       PORTE,2             ;Alarm sound (buzzer?)
ALARM_SLEEP         pin       PORTE,0
IO_LINE             pin       PORTD,5             ;I/O line

SPI_MOSI            pin       PORTB,1
SPI_MISO            pin       PORTB,2
SPI_CLK             pin       PORTB,0
SPI_SS              pin       PORTB,3

;*******************************************************************************
                    #RAM      RAM
;*******************************************************************************

q                   rmb       9                   ;BCD WORKING NUMBERS
tmq                 rmb       9                   ;SCRATCH
p                   rmb       9                   ;WORKING NUMBER 2
tmp                 rmb       9                   ;MULT. OVER. OR DIV. REMAINDER
r                   rmb       9                   ;WORKING NUMBER 3
mjd                 rmb       9                   ;MODIFIED JULIAN DAY NUMBER
year                rmb       9
month               rmb       2
dom                 rmb       2                   ;day of month
dow                 rmb       1                   ;day of week
bmjd                rmb       3                   ;BINARY mjd
dist                rmb       1                   ;DISPLAY TRANSIENT TIMEOUT COUNTER
slept               rmb       1                   ;SLEEP TIMER MINUTES COUNTER
rdsto               rmb       1                   ;RDS TIMEOUT COUNTER
dat                 rmb       4                   ;SERIAL DATA BUFFER
tmpgrp              rmb       8                   ;TEMPORARY GROUP DATA
group               rmb       8                   ;COMPLETE GROUP DATA
pty                 rmb       1                   ;PROGRAM-TYPE CODE (CURRENT)
pi                  rmb       2                   ;PROGRAM IDENTIFICATION CODE
pin                 rmb       2                   ;PROGRAM ITEM NUMBER
lev                 rmb       1                   ;VALID BLOCK LEVEL
bit                 rmb       1                   ;BIT LEVEL
irq_tmp             rmb       1                   ;TEMP BYTE FOR USE IN IRQ
syn                 rmb       2                   ;SYNDROME
conf                rmb       1                   ;SYNDROME CONFIDENCE
th8                 rmb       1                   ;TICS (EIGHTHS OF SECONDS)
sec                 rmb       1                   ;SECONDS
min                 rmb       1                   ;MINUTES
our                 rmb       1                   ;HOURS
alarm_mins          rmb       1                   ;ALARM MINUTES
alarm_hours         rmb       1                   ;ALARM HOURS
disp1               rmb       1                   ;RT DISPLAY POINTER #1
disp2               rmb       1                   ;RT DISPLAY POINTER #2
w1                  rmb       1                   ;W
w2                  rmb       1                   ;O
w3                  rmb       1                   ;R
w4                  rmb       1                   ;K
w5                  rmb       1                   ;I
w6                  rmb       1                   ;N
w7                  rmb       1                   ;G
w8                  rmb       1
key                 rmb       1                   ;CODE OF PRESSED KEY
kount               rmb       1                   ;KEYBOARD COUNTER
carry               rmb       1                   ;BCD CARRY
count               rmb       1                   ;LOOP COUNTER
num1                rmb       1                   ;1ST No. POINTER (ADD & SUBTRACT)
num2                rmb       1                   ;2ND No. POINTER (ADD & SUBTRACT)
rtdis               rmb       1                   ;RDS DISPLAY TYPE
di                  rmb       1                   ;DECODER IDENTIFICATION
disp                rmb       16                  ;LCD MODULE BUFFER
ps_name             rmb       8                   ;PS NAME
          ;--------------------------------------
stat2               rmb       1
VALID_SYNDROME      pin       stat2               ;0: VALID SYNDROME
VALID_GROUP         pin                           ;1: VALID GROUP
RT_DISPLAY          pin                           ;2: RT DISPLAY
UPDATE_DISPLAY      pin                           ;3: UPDATE DISPLAY
CLEAR_DISPLAY       pin                           ;4: CLEAR DISPLAY
SPACE_FLAG          pin                           ;5: SPACE FLAG
          ;--------------------------------------
stat3               rmb       1
MODE_SELECT         pin       stat3               ;0: M/S, 0: M, 1: S
TEXT_RT             pin                           ;1: TEXTA/TEXTB BIT (RT)
TA_FLAG             pin                           ;2: TA FLAG
TP_FLAG             pin                           ;3: TP FLAG
KEY_REPEAT          pin                           ;4: KEY REPEATING
KEY_FUNCTION_PERF   pin                           ;5: KEY FUNCTION PERFORMED
UPDATE_DATE         pin                           ;6: UPDATE DATE
          ;--------------------------------------
stat4               rmb       1
DISPLAY_TRANSIENT   pin       stat4               ;0: DISPLAY TRANSIENT
SLEEP_TIMER_RUNNING pin                           ;1: SLEEP TIMER RUNNING
SLEEP_DISPLAY       pin                           ;2: SLEEP DISPLAY
ALARM_DISPLAY       pin                           ;3: ALARM DISPLAY
ALARM_ARMED         pin                           ;4: ALARM ARMED
ALARM_SETUP         pin                           ;5: ALARM SET-UP
ALARM_HOURS_SETUP   pin                           ;6: ALARM HOURS (SET-UP)
RDS_DISPLAYS        pin                           ;7: RDS DISPLAYS
          ;--------------------------------------
                    rmb       33                  ;not used
stack               rmb       18                  ;19 BYTES USED (1 INTERRUPT
                    rmb       1                   ;AND 7 NESTED SUBROUTINES)

;*******************************************************************************
                    #XRAM     XRAM
;*******************************************************************************

RT                  rmb       69                  ;RADIOTEXT
EON                 rmb       176                 ;EON DATA (MAX: 11 NETWORKS)

;*******************************************************************************
                    #ROM      ROM
;*******************************************************************************

;STRST              jmp       Start               ;RESET VECTOR ($0400 DURING DEBUG)
;IRQ                jmp       IRQ_Handler         ;IRQ ($0403 DURING DEBUG)
;TIMERA             jmp       Start               ;TIMER A INTERRUPT (NOT USED, $0406 DURING DEBUG)
;TIMERB             jmp       TIM_Handler         ;TIMER B INTERRUPT ($0409 DURING DEBUG)
;SERINT             jmp       Start               ;SERIAL INTERRUPT (NOT USED, $040C DURING DEBUG)

;*******************************************************************************
; Reset routine - setup ports
;*******************************************************************************

Start               proc
                    lda       #$C3                ;ENABLE PORTD SPECIAL FUNCTIONS
                    sta       PORTDSF             ;P02, R/W, A14 & A15 (0,1,6,7)
                    lda       #$45                ;ENABLE POSITIVE EDGE/LEVEL
                    sta       ICR                 ;INTERRUPTS
                    lda       #1                  ;TIMER B SCALER: /2
                    sta       TBS                 ;125 mS INTERRUPTS (4.194 MHz XTAL)
                    lda       #63                 ;TIMER A PRE-SCALER: /64
                    sta       TAP                 ;64Hz IDLE LOOP
                    clr       PORTA
                    mov       #$FF,DDRA           ;E0BUG DISPLAY/KEYBOARD I/O (NOT USED IN RDS APPLICATION)
                    clr       PORTB               ;0, 1: SERIAL CLOCK AND DATA
                    mov       #$CB,DDRB           ;2: RDS DATA IN, 3: VFD SELECT
                                                  ;4, 5: KEYBOARD IN, 6, 7: KEYBOARD OUT
                    clr       PORTC
                    mov       #$FF,DDRC           ;ALL OUT, LCD DATA BUS
                    lda       #$3C                ;BITS 2, 3 & 4 OUT, LCD
                    clr       PORTD               ;2: RS, 3: R/W, 4: CLOCK, 5: LED (TA=TP=1)
                    sta       DDRD                ;0, 1, 6 & 7 USED DURING DEBUG
                    mov       #$0C,PORTE          ;BIT0: INPUT, ENABLE SLEEP TIMER AT ALARM TIME
                                                  ;BIT1: INPUT, ENABLE ALARM OUTPUT
                    mov       #$0C,DDRE           ;BIT2: ALARM OUTPUT (ACTIVE LOW)
                                                  ;BIT3: RADIO ON OUTPUT (ACTIVE HIGH)
          ;-------------------------------------- ;Initialise LCD
                    lda       #$30
                    jsr       CLOCK               ;INITIALISE LCD
                    jsr:4     CLREON              ;CLEAR EON DATA 4 TIMES TO PROVIDE A 5mS DELAY
                                                  ;FOR LCD MODULE INITIALISATION
                    lda       #$30
                    jsr       CLOCK               ;INITIALISE LCD
                    ldx       #q                  ;INITIALISE RAM
Loop@@              clr       ,x
                    incx                          ;PROVIDES A 1mS DELAY FOR LCD
                    cpx       #stack
                    bne       Loop@@
                    lda       #$30
                    jsr       CLOCK               ;INITIALISE LCD
                    jsr       WAIT
                    lda       #$30                ;1-LINE DISPLAY
                    jsr       CLOCK               ;LATCH IT
                    jsr       WAIT
                    lda       #$08                ;SWITCH DISPLAY OFF
                    jsr       CLOCK               ;LATCH IT
                    jsr       WAIT
                    lda       #$01                ;CLEAR DISPLAY
                    jsr       CLOCK               ;LATCH IT
                    jsr       INITD
          ;-------------------------------------- ;Vectors for debug using E0BUG monitor.
;                   lda       #$0C                ;ENABLE EXTERNAL RAM WRITE
;                   sta       TCR
;                   lda       #$04                ;VECTORS FOR E0 MONITOR
;                   sta       $0201
;                   sta       $0204               ;USING JUMP TABLE AT $0400
;                   sta       $0207
;                   sta       $020A               ;(LINES 126-130)
;                   lda       #$03
;                   sta       $0202               ;IRQ ($0403)
;                   lda       #$06
;                   sta       $0205               ;TIMER A ($0406)
;                   lda       #$09
;                   sta       $0208               ;TIMER B ($0409)
;                   lda       #$0C
;                   sta       $020B               ;SERIAL ($040C)
          ;-------------------------------------- ;Enable interrupts.
                    lda       #$0B                ;EDGE SENSITIVE IRQ, TIMERS A & B ENABLED
                    sta       TCR                 ;SUB-SYS CLK = 262144 Hz (4.194 MHz XTAL)
                                                  ;DISABLE EXTERNAL RAM WRITE
                    cli
          ;-------------------------------------- ;Idle loop
Idle@@              brclr     4,ICR,*             ;64 Hz
                    bclr      4,ICR
                    brclr     DISPLAY_TRANSIENT,_1@@ ;DISPLAY TRANSIENT ?
                    lda       dist
                    bne       _1@@                ;YES, TIMED OUT ?
                    jsr       CLTR                ;YES, CLEAR TRANSIENT DISPLAYS
_1@@                brclr     UPDATE_DISPLAY,Scan@@ ;DISPLAY UPDATE REQUIRED ?
                    jsr       MOD                 ;YES, DO IT
                    bclr      UPDATE_DISPLAY      ;AND CLEAR FLAG
Scan@@              brclr     ALARM_ARMED,_3@@    ;ALARM ARMED ?
                    lda       alarm_hours         ;YES, COMPARE ALARM HOURS
                    cmpa      our                 ;WITH TIME
                    bne       _3@@                ;SAME ?
                    lda       alarm_mins          ;YES, COMPARE ALARM MINUTES
                    cmpa      min                 ;WITH TIME
                    bne       _3@@                ;SAME ?
                    lda       sec                 ;ONLY ALLOW WAKE-UP IN FIRST SECOND
                    bne       _3@@                ;TO PREVENT SWITCH-OFF LOCKOUT
                    bset      SWITCH              ;YES, SWITCH ON
                    brset     ALARM_SWITCH,_2@@   ;ALARM ENABLED (SWITCH) ?
                    bclr      ALARM_BUZZER        ;YES, SOUND ALARM
_2@@                brset     ALARM_SLEEP,_3@@    ;SLEEP TIMER AT ALARM TIME ?
                    jsr       INSLP               ;YES, START SLEEP TIMER
_3@@                brclr     SLEEP_TIMER_RUNNING,_4@@ ;SLEEP TIMER RUNNING ?
                    lda       slept               ;YES
                    bne       _4@@                ;TIME TO FINISH ?
                    bclr      SLEEP_TIMER_RUNNING ;YES, CLEAR FLAG
                    bclr      SWITCH              ;AND SWITCH OFF
_4@@                bsr       KBD                 ;READ KEYBOARD
                    jsr       KEYP                ;EXECUTE KEY
                    lda       stat3
                    and       #@TA_FLAG|@TP_FLAG  ;TA AND TP BOTH HIGH ?
                    cbeqa     #@TA_FLAG|@TP_FLAG,_5@@
                    brset     IO_LINE,_6@@        ;NO, I/O LINE ALREADY HIGH ?
                    bset      IO_LINE             ;NO, MAKE IT HIGH
                    bra       _6@@

_5@@                brclr     IO_LINE,_6@@        ;TA=TP=1, I/O LINE ALREADY LOW ?
                    bclr      IO_LINE             ;NO, MAKE IT LOW
_6@@                brclr     UPDATE_DATE,Cont@@  ;UPDATE DATE ?
                    bsr       MJDAT               ;YES, CONVERT FROM mjd
Cont@@              bra       Idle@@

;*******************************************************************************
; Extract mjd and convert to decimal.
;*******************************************************************************

MJDAT               proc
                    mov       bmjd+2,year+2
                    mov       bmjd+1,year+1
                    mov       bmjd,year
                    mov       #r,num1             ;CLEAR
                    jsr       CLRAS               ;R
                    inc       r+ND-1              ;R <- 1
                    ldx       #mjd
                    jsr       CLRAS               ;CLEAR mjd
                    mov       #17,w6              ;17 BITS TO CONVERT
LooP@@              lsr       year                ;MOVE OUT
                    ror       year+1
                    ror       year+2              ;FIRST (LS) BIT
                    bcc       Cont@@              ;ZERO ?
                    ldx       #mjd                ;ONE, ADD
                    stx       num2                ;CURRENT VALUE
                    jsr       ADD                 ;OF R
Cont@@              mov       #r,num2             ;ADD R TO
                    jsr       ADD                 ;ITSELF
                    dbnz      w6,LooP@@           ;ALL DONE ?
                    bclr      UPDATE_DATE         ;MJD UPDATED
                    jmp       MJDC                ;CONVERT mjd TO DAY, DATE, MONTH & YEAR

;*******************************************************************************
; Keyboard routine.
;*******************************************************************************

KBD                 proc
                    lda       #$20
                    ldx       #2
_1@@                lsla                          ;SELECT ROW
                    and       #$C0                ;BITS 6 & 7 ONLY
                    ora       #$08                ;VFD ENABLE HIGH
                    sta       PORTB
                    lda       PORTB               ;READ KEYBOARD
                    bit       #$30                ;ANY INPUT LINE HIGH ?
                    bne       _2@@
                    dbnzx     _1@@                ;NO, TRY NEXT COLUMN. LAST COLUMN ?
                    clr       key                 ;YES, NO KEY PRESSED
                    bra       Exit@@

_2@@                lda       PORTB               ;READ KEYBOARD
                    and       #$F0
                    cbeq      key,Exit@@          ;SAME AS LAST TIME ?
                    sta       key                 ;NO, SAVE THIS KEY
                    clr       kount
Exit@@              inc       kount               ;YES, THE SAME
                    lda       kount
                    brclr     KEY_REPEAT,Normal@@ ;REPEATING ?
                    cmpa      #10                 ;YES, REPEAT AT 6 Hz
                    bra       _3@@

Normal@@            cmpa      #3                  ;NO, 3 THE SAME ?
                    blo       Done@@              ;IF NOT DO NOTHING
                    beq       _6@@                ;IF 3 THEN PERFORM KEY FUNCTION
                    cmpa      #48                 ;MORE THAN 3, MORE THAN 48 (750mS) ?
_3@@                bhi       _4@@                ;TIME TO DO SOMETHING ?
                    lda       key                 ;NO
                    beq       _7@@                ;KEY PRESSED ?
                    clc
                    rts                           ;YES BUT DO NOTHING

_4@@                lda       key
                    cbeqa     #$50,_5@@           ;SLEEP (DEC.)
                    cmpa      #$90                ;RDS (INC.)
                    bne       _8@@                ;IF NOT A REPEAT KEY, DO NOTHING
_5@@                brclr     ALARM_SETUP,_8@@    ;REPEAT KEY, BUT IS MODE ALARM SET-UP ?
                    bset      KEY_REPEAT          ;YES, SET REPEAT FLAG
                    clr       kount
_6@@                lda       key
                    beq       _7@@                ;SOMETHING TO DO ?
                    sec                           ;YES, SET C
                    rts

_7@@                bclr      KEY_FUNCTION_PERF   ;NO, CLEAR DONE FLAG
_8@@                bclr      KEY_REPEAT          ;CLEAR REPEAT FLAG
                    clr       kount               ;CLEAR COUNTER
Done@@              clc
                    rts

;*******************************************************************************
; Execute key function.
;*******************************************************************************

KEYP                proc
                    bcc       Done@@              ;ANYTHING TO DO ?
                    lda       key                 ;YES, GET KEY
                    cbeqa     #$50,_@@            ;SLEEP (DEC.)
                    cbeqa     #$90,_@@            ;RDS (INC.)
                    brset     KEY_FUNCTION_PERF,Done@@ ;NOT A REPEAT KEY, DONE FLAG SET ?
_@@                 clrx
Loop@@              lda       CTAB,x              ;FETCH KEYCODE
                    cbeq      key,_1@@            ;THIS ONE ? YES
                    cmpa      LAST
                    beq       Done@@              ;NO, LAST CHANCE ? YES, ABORT
                    incx:4                        ;NO, TRY THE NEXT KEY
                    bra       Loop@@

_1@@                bset      KEY_FUNCTION_PERF   ;KEY FUNCTION DONE
                    incx
                    jsr       CTAB,x
Done@@              rts

;*******************************************************************************
; Keyboard jump table
;*******************************************************************************

?                   macro
                    fcb       ~1~
                    !jmp      ~2~
                    endm

CTAB                @?        $60,ALARM           ;ALARM
                    @?        $A0,ONOFF           ;ON/OFF
                    @?        $50,SLEEP           ;SLEEP TIMER START
LAST                @?        $90,RDS             ;RDS DISPLAYS

;*******************************************************************************
; Alarm key
;*******************************************************************************

ALARM               proc
                    brclr     ALARM_BUZZER,CancelAlarm ;ALARM RINGING ?
                    brclr     ALARM_DISPLAY,On@@  ;NO, ALARM DISPLAY ON ?
                    brclr     ALARM_ARMED,Off@@   ;YES, ALARM ON ?
                    bclr      ALARM_ARMED         ;YES, SWITCH OFF
                    bra       UdCnt@@

Off@@               bset      ALARM_ARMED         ;NO, SWITCH ON
                    bra       UdCnt@@

On@@                jsr       CLTR
                    bset      ALARM_DISPLAY       ;ALARM DISPLAY FLAG
UdCnt@@             bclr      ALARM_SETUP         ;CANCEL SET-UP
                    lda       #25                 ;3 SECOND TIMEOUT
                    sta       dist
                    bset      DISPLAY_TRANSIENT   ;SET DISPLAY TRANSIENT FLAG
                    rts

;*******************************************************************************
; On/off key (alarm set-up).
;*******************************************************************************

ONOFF               proc
                    brclr     ALARM_BUZZER,CancelAlarm      ;ALARM RINGING ?
                    brclr     ALARM_DISPLAY,NOTALR          ;NO, ALARM DISPLAY ?
                    brclr     ALARM_ARMED,NOTALR            ;YES, ALARM ARMED ?
                    brset     ALARM_SETUP,InSetup@@         ;YES, ALREADY SET-UP MODE ?
                    bset      ALARM_SETUP                   ;NO, ENTER SET-UP MODE
                    bset      ALARM_HOURS_SETUP             ;WITH HOURS
Loop@@              mov       #80,dist
                    bset      DISPLAY_TRANSIENT             ;SET DISPLAY TRANSIENT FLAG
                    rts

InSetup@@           brset     ALARM_HOURS_SETUP,Mins@@      ;SET-UP HOURS ?
                    bclr      ALARM_SETUP                   ;NO, CANCEL SET-UP
                    bra       Loop@@

Mins@@              bclr      ALARM_HOURS_SETUP             ;YES, MAKE IT MINUTES
                    bra       Loop@@

;*******************************************************************************
; On/off key (normal function).
;*******************************************************************************

NOTALR              proc
                    jsr       CLTR                ;CLEAR DISPLAY TRANSIENTS
                    bclr      SLEEP_TIMER_RUNNING ;CANCEL SLEEP TIMER
                    brset     SWITCH,On@@         ;ON ?
SODM                bset      SWITCH              ;NO, SWITCH ON
                    rts

On@@                bclr      SWITCH              ;YES, SWITCH OFF
                    rts

;*******************************************************************************

CancelAlarm         proc
                    bset      ALARM_BUZZER        ;CANCEL ALARM
                    rts

;*******************************************************************************
; Sleep key
;*******************************************************************************

SLEEP               proc
                    brclr     ALARM_BUZZER,CancelAlarm ;ALARM RINGING ?
                    brclr     ALARM_SETUP,_1@@    ;NO, ALARM SET-UP ?
                    bra       PDEC                ;YES

_1@@                brset     SLEEP_DISPLAY,DECS  ;NO, ALREADY SLEEP DISPLAY ?
                    brset     SLEEP_TIMER_RUNNING,STR2 ;NO, SLEEP TIMER ALREADY RUNNING ?
;                   bra       INSLP

;*******************************************************************************

INSLP               proc
                    lda       #60                 ;NO, INITIALISE SLEEP TIMER
                    sta       slept
                    bset      SLEEP_TIMER_RUNNING ;START SLEEP TIMER
STR2                jsr       CLTR                ;YES, CLEAR DISPLAY TRANSIENTS
                    bset      SLEEP_DISPLAY       ;SLEEP DISPLAY
                    bra       SLPTOK              ;NO DECREMENT IF FIRST TIME

DECS                lda       slept               ;DECREMENT SLEEP TIMER
                    sub       #5
                    sta       slept
                    bmi       INSLP               ;IF UNDERFLOW WRAP ROUND TO 60
SLPTOK              lda       #25
                    sta       dist
                    bset      DISPLAY_TRANSIENT   ;START DISPLAY TRANSIENT
                    bra       SODM

;*******************************************************************************
; RDS display key
;*******************************************************************************

RDS                 proc
                    brclr     ALARM_BUZZER,CancelAlarm ;ALARM RINGING ?
                    brset     ALARM_SETUP,PINC    ;NO, ALARM SET-UP ?
                    brclr     SWITCH,_2@@         ;NO, STANDBY ?
                    brset     RDS_DISPLAYS,_1@@   ;ALREADY RDS ?
                    brclr     RT_DISPLAY,_3@@     ;ALREADY RT DISPLAY ?
_1@@                bset      RDS_DISPLAYS        ;SET RDS DISPLAY FLAG
                    lda       rtdis               ;MOVE ON
                    inca
                    cbeqa     #19,_3@@
                    sta       rtdis
                    lda       #100                ;12 SECOND TIMEOUT
                    sta       dist
                    bset      DISPLAY_TRANSIENT   ;RE-START TRANSIENT TIMEOUT
_2@@                rts

_3@@                jsr       CLTR                ;CLEAR DISPLAY TRANSIENTS
                    bset      RT_DISPLAY          ;SET RT DISPLAY FLAG
                    mov       #9,disp1
                    mov       #1,disp2
                    rts

;*******************************************************************************
; Increment alarm time.
;*******************************************************************************

PINC                proc
                    brset     ALARM_HOURS_SETUP,_2@@        ;SET-UP HOURS ?
                    lda       alarm_mins                    ;NO, MINUTES
                    cmpa      #59
                    bhs       _1@@
                    inc       alarm_mins
                    bra       _3@@

_1@@                clr       alarm_mins
                    bra       _3@@

_2@@                lda       alarm_hours
                    cmpa      #23
                    bhs       _4@@
                    inc       alarm_hours
_3@@                lda       #80                 ;10 SECOND TIMEOUT
                    sta       dist
                    bset      DISPLAY_TRANSIENT   ;SET DISPLAY TRANSIENT FLAG
                    rts

_4@@                clr       alarm_hours
                    bra       _3@@

;*******************************************************************************
; Decrement alarm time.
;*******************************************************************************

PDEC                proc
                    brset     ALARM_HOURS_SETUP,_2@@        ;SET-UP HOURS ?
                    tst       alarm_mins                    ;NO, MINUTES
                    beq       _1@@
                    dec       alarm_mins
                    bra       _3@@

_1@@                mov       #59,alarm_mins
                    bra       _3@@

_2@@                tst       alarm_hours
                    beq       _4@@
                    dec       alarm_hours
_3@@                lda       #80                 ;10 SECOND TIMEOUT
                    sta       dist
                    bset      DISPLAY_TRANSIENT   ;SET DISPLAY TRANSIENT FLAG
                    rts

_4@@                mov       #23,alarm_hours
                    bra       _3@@

;*******************************************************************************
; Timer interrupt routine
;*******************************************************************************

TIM_Handler         proc
                    inc       disp1               ;disp1 disp2 DISPLAY
                    lda       disp1               ;0 -8 0 PTY
                    cmpa      #8                  ;9 -78 1 - 70 MOVING RT
                    bls       _1@@                ;78 -88 70 END OF RT
                    cmpa      #78
                    bhi       _1@@                ;END OF RADIOTEXT ?
                    inc       disp2               ;NO, MOVE RADIOTEXT ONE CHARACTER
_1@@                cmpa      #88                 ;2 SECONDS AT END OF RADIOTEXT
                    blo       _2@@
                    bclr      RT_DISPLAY          ;RETURN TO NORMAL DISPLAY
_2@@                bclr      5,ICR               ;CLEAR TIMER B INTERRUPT FLAG
                    bset      UPDATE_DISPLAY      ;UPDATE DISPLAY
                    inc       th8                 ;UPDATE EIGHTHS OF SECONDS
                    dec       dist                ;DECREMENT TRANSIENT DISPLAY TIMER
                    inc       rdsto
                    lda       rdsto
                    cmpa      #80                 ;10S WITHOUT A GROUP 0 OR 15 ?
                    blo       RdsOk@@
                    bclr      TA_FLAG             ;YES, CLEAR TA FLAG
                    clr       pty                 ;PROGRAM TYPE
                    clr       pi                  ;AND
                    clr       pi+1                ;PI CODE
                    clr       pin                 ;AND
                    clr       pin+1               ;PIN
                    clr       di                  ;AND DI
                    bclr      MODE_SELECT         ;AND M/S
RdsOk@@             lda       th8                 ;EIGHTHS OF SECONDS
                    cmpa      #8
                    bne       Done@@              ;PAST 7 ?
                    clr       th8                 ;YES, CLEAR
                    inc       sec                 ;UPDATE SECONDS
                    lda       sec
                    cmpa      #56
                    bne       _3@@
                    dec       slept               ;DECREMENT SLEEP TIMER MINUTES
_3@@                cmpa      #60
                    bne       Done@@              ;PAST 59 ?
                    clr       sec                 ;YES, CLEAR
                    inc       min                 ;UPDATE MINUTES
                    lda       min
                    cmpa      #60
                    bne       Done@@              ;PAST 59 ?
                    clr       min                 ;YES, CLEAR
                    inc       our                 ;UPDATE HOURS
                    lda       our
                    cmpa      #24
                    bne       Done@@              ;PAST 23 ?
                    clr       our                 ;YES CLEAR
                    inc       bmjd+2              ;AND ADD A DAY
                    bne       _4@@
                    inc       bmjd+1
                    bne       _4@@                ;INC bmjd only ever executes once, at midnight
                    inc       bmjd                ;on the night of Thu/Fri 22/23 April 2038.
_4@@                bset      UPDATE_DATE         ;UPDATE DATE
Done@@              rti

;*******************************************************************************
; RDS clock interrupt (IRQ)
; Get a bit and calculate syndrome
;*******************************************************************************

IRQ_Handler         proc
                    brset     SPI_MISO,_@@
_@@                 rol       dat+3
                    rol       dat+2
                    rol       dat+1
                    rol       dat
                    brclr     VALID_SYNDROME,_2@@ ;BIT BY BIT CHECK ?
                    dec       bit                 ;NO, WAIT FOR BIT 26
                    beq       _1@@                ;THIS TIME ?
                    bclr      3,ICR               ;CLEAR IRQ INTERRUPT FLAG
                    rti
          ;--------------------------------------
_1@@                lda       #26
                    sta       bit
_2@@                lda       dat                 ;MSB (2 BITS)
                    and       #3
                    tax
                    lda       dat+1
                    sta       syn+1               ;LSB
                    brclr     0,dat+3,_3@@
                    lda       syn+1
                    eor       #$1B
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_3@@                brclr     1,dat+3,_4@@
                    lda       syn+1
                    eor       #$8F
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_4@@                brclr     2,dat+3,_5@@
                    lda       syn+1
                    eor       #$A7
                    sta       syn+1
                    txa
                    eor       #$02
                    tax
          ;--------------------------------------
_5@@                brclr     4,dat+3,_6@@
                    lda       syn+1
                    eor       #$EE
                    sta       syn+1
                    txa
                    eor       #$01
                    tax
          ;--------------------------------------
_6@@                brclr     5,dat+3,_7@@
                    lda       syn+1
                    eor       #$DC
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_7@@                brclr     6,dat+3,_8@@
                    lda       syn+1
                    eor       #$01
                    sta       syn+1
                    txa
                    eor       #$02
                    tax
          ;--------------------------------------
_8@@                brclr     7,dat+3,_9@@
                    lda       syn+1
                    eor       #$BB
                    sta       syn+1
                    txa
                    eor       #$01
                    tax
          ;--------------------------------------
_9@@                brclr     0,dat+2,_10@@
                    lda       syn+1
                    eor       #$76
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_10@@               brclr     1,dat+2,_11@@
                    lda       syn+1
                    eor       #$55
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_11@@               brclr     2,dat+2,_12@@
                    lda       syn+1
                    eor       #$13
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_12@@               brclr     3,dat+2,_13@@
                    lda       syn+1
                    eor       #$9F
                    sta       syn+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_13@@               brclr     4,dat+2,_14@@
                    lda       syn+1
                    eor       #$87
                    sta       syn+1
                    txa
                    eor       #$02
                    tax
          ;--------------------------------------
_14@@               brclr     6,dat+2,_15@@
                    lda       syn+1
                    eor       #$6E
                    sta       syn+1
                    txa
                    eor       #$01
                    tax
          ;--------------------------------------
_15@@               brclr     7,dat+2,_16@@
                    lda       syn+1
                    eor       #$DC
                    sta       syn+1
                    txa
                    eor       #$02
_16@@               sta       syn
                    lda       syn+1
                    brclr     3,dat+3,_17@@
                    eor       #$F7
_17@@               brclr     5,dat+2,_18@@
                    eor       #$B7
_18@@               sta       syn+1
          ;-------------------------------------- ;Check for syndromes A, B, C & C'
                    bclr      3,ICR               ;Clear IRQ interrupt flag
                    lda       lev
                    cbeqa     #3,TRYD
                    cbeqa     #2,TryC@@
                    cbeqa     #1,TryB@@
                    clr       lev
          ;-------------------------------------- ;TRYA
                    lda       syn+1               ;BLOCK 1
                    cmpa      #$D8
                    bne       NotValid@@
                    lda       syn
                    cmpa      #$03
                    bne       NotValid@@
                    bra       VALID
          ;--------------------------------------
TryB@@              lda       syn+1               ;BLOCK 2
                    cmpa      #$D4
                    bne       NotValid@@
                    lda       syn
                    cmpa      #$03
                    bne       NotValid@@
                    bra       VALID
          ;--------------------------------------
TryC@@              brset     3,tmpgrp+2,TryD@@   ;BLOCK 3 TYPE A
                    lda       syn+1
                    cmpa      #$5C
                    bne       NotValid@@
                    lda       syn
                    cmpa      #$02
                    bra       Valid@@
          ;--------------------------------------
TryD@@              lda       syn+1               ;BLOCK 3 TYPE B
                    cmpa      #$CC
                    bne       NotValid@@
                    lda       syn
                    cmpa      #$03
Valid@@             beq       VALID
          ;--------------------------------------
          ; Invalid syndrome handling, check for
          ; block 4 and save group data if valid.
          ;--------------------------------------
NotValid@@          clr       lev                 ;RESTART AT BLOCK 1
                    lda       conf
                    cmpa      #41                 ;CONFIDENCE 41 OR GREATER ?
                    bhs       DECC
                    bclr      VALID_SYNDROME      ;BIT BY BIT SYNDROME CHECK
                    cmpa      #10
                    bls       SKPDC               ;CONFIDENCE 10 OR LESS ?
                    dbnz      bit,NNOW            ;USE BIT COUNTER TO SLOW CONFIDENCE
                    lda       #26                 ;DROP DURING BIT BY BIT ATTEMPT TO
                    sta       bit                 ;RE-SYNCRONISE
DECC                dec       conf
NNOW                rti

SKPDC               bset      CLEAR_DISPLAY       ;10 OR LESS, INITIALISE DISPLAY
NOT4                rti

TRYD                lda       syn+1
                    cmpa      #$58
                    bne       NotValid@@
                    lda       syn
                    cmpa      #$02
                    bne       NotValid@@
                    bset      VALID_GROUP         ;GROUP COMPLETE
VALID               brset     VALID_SYNDROME,VLD  ;VALID SYNDROME FLAG ALREADY SET ?
                    lda       #38                 ;NO,
                    sta       conf                ;INITIALISE CONFIDENCE (38+4=42)
                    bset      VALID_SYNDROME      ;AND SET FLAG
VLD                 lda       conf
                    cmpa      #56
                    bhi       NMR
                    add       #4
                    sta       conf
NMR                 ldx       lev
                    rolx
                    inc       lev
                    lda       #26
                    sta       bit
                    ror       dat
                    ror       dat+1
                    ror       dat+2
                    ror       dat
                    ror       dat+1
                    ror       dat+2
                    lda       dat+2
                    sta       tmpgrp+1,x
                    lda       dat+1
                    sta       tmpgrp,x
                    brclr     VALID_GROUP,NOT4    ;GROUP COMPLETE ?
XFER                ldx       #8
TXLP                lda       tmpgrp-1,x
                    sta       group-1,x
                    dbnzx     TXLP
          ;--------------------------------------
          ; Update PI code, initialise if changed.
          ; All block 1s used, block 3s not used.
          ;--------------------------------------
PROC                lda       group               ;COMPARE PI WITH PREVIOUS
                    cmpa      pi
                    bne       DNDX
                    lda       group+1
                    cmpa      pi+1
                    beq       PTYL
DNDX                lda       group               ;DIFFERENT, SAVE NEW PI
                    sta       pi
                    lda       group+1
                    sta       pi+1
                    jsr       CLREON              ;CLEAR EON,
                    jsr       CLTR                ;TRANSIENTS
                    bset      CLEAR_DISPLAY       ;AND INITIALISE DISPLAY DATA
          ;--------------------------------------
          ; Update PTY and TP.
          ; All block 2s used, not block 4 (grp 15B).
          ;--------------------------------------
PTYL                lda       group+2
                    sta       irq_tmp
                    brclr     2,irq_tmp,TPL1      ;TP HIGH ?
                    bset      TP_FLAG             ;YES, FLAG HIGH
                    bra       TPL

TPL1                bclr      TP_FLAG             ;NO, FLAG LOW
TPL                 lda       group+3
                    ror       irq_tmp
                    rora
                    lsra:4
                    sta       pty
          ;--------------------------------------
          ; Groups handled.
          ;
          ; All PI, PTY & TP
          ; 0 A & B TA, PS, DI & M/S
          ; 1 A & B PIN
          ; 2 A RT
          ; 4 A CT
          ; 14 A EON
          ; 15 B TA, DI & M/S
          ;-------------------------------------- ;Process groups 0 & 15B (PS & TA).
                    lda       group+2
                    and       #$F8
                    beq       GRP0                ;GROUP 0A
                    cmpa      #$08                ;GROUP 0B
                    beq       GRP0
TGRP15              cmpa      #$F8                ;GROUP 15B
                    beq       TACK
                    bra       PROC1

GRP0                lda       group+3             ;GROUP 0 -PS & TA
                    and       #$03
                    lsla
                    tax
                    lda       group+6
                    sta       ps_name,x
                    lda       group+7
                    sta       ps_name+1,x
TACK                clr       rdsto               ;RDS OK, RESET TIME-OUT
                    brset     4,group+3,TAH       ;TA HIGH ?
                    bclr      TA_FLAG             ;NO, TA FLAG LOW
                    bra       NTD

TAH                 bset      TA_FLAG             ;YES, TA FLAG HIGH
          ;-------------------------------------- ;Process group 0 & 15B (DI & M/S).
NTD                 lda       group+3             ;DI
                    and       #3
                    tax
                    lda       group+3
                    and       #$40
                    tstx
                    bne       NOT0
                    bclr      0,di
                    tsta
                    beq       NOT0
                    bset      0,di
NOT0                cpx       #1
                    bne       NOT1
                    bclr      1,di
                    tsta
                    beq       NOT1
                    bset      1,di
NOT1                cpx       #2
                    bne       NOT2
                    bclr      2,di
                    tsta
                    beq       NOT2
                    bset      2,di
NOT2                cpx       #3
                    bne       NOT3
                    bclr      3,di
                    tsta
                    beq       NOT3
                    bset      3,di
NOT3                bclr      MODE_SELECT         ;M/S
                    brclr     3,group+3,MSZ
                    bset      MODE_SELECT
MSZ                 jmp       OUT1

;*******************************************************************************
; Process group 1 (PIN).
;*******************************************************************************

PROC1               proc
                    cmpa      #$10                ;GROUP 1A
                    beq       _@@
                    cmpa      #$18                ;GROUP 1B
                    bne       PROC2
_@@                 lda       group+6
                    sta       pin
                    lda       group+7
                    sta       pin+1
                    jmp       OUT1

;*******************************************************************************
; Process group 2A (RT).
; Group 2B not handled.
;*******************************************************************************

PROC2               proc
                    cmpa      #$20                ;GROUP 2A
                    bne       PROC4
                    brset     4,group+3,_1@@
                    brset     TEXT_RT,_3@@
                    bset      TEXT_RT
                    bra       _2@@

_1@@                brclr     TEXT_RT,_3@@
                    bclr      TEXT_RT
_2@@                jsr       INITD
_3@@                lda       group+3             ;GROUP 2A -RT
                    and       #$0F
                    lsla:2
                    tax
                    lda       group+4
                    sta       RT+5,x
                    lda       group+5
                    sta       RT+6,x
                    lda       group+6
                    sta       RT+7,x
                    lda       group+7
                    sta       RT+8,x
                    jmp       OUT1

;*******************************************************************************
; Process group 4A (CT)
;*******************************************************************************

PROC4               proc
                    cmpa      #$40                ;GROUP 4A -CT
                    jne       PROC14

                    lda       group+3
                    rora
                    and       #$01
                    sta       bmjd                ;mjd MS BIT
                    lda       group+4
                    rora
                    sta       bmjd+1              ;mjd MSD
                    lda       group+6             ;GROUP 4
                    ror       group+5             ;3210xxxx 4
                    rora                          ;43210xxx x
                    lsra:3                        ;-43210xx x
                                                  ;--43210x x
                                                  ;---43210 x
                    sta       our
                    lda       group+5
                    sta       bmjd+2              ;mjd LSD
                    lda       group+6             ;xxxx5432 x
                    lsl       group+7             ;xxxx5432 1
                    rola                          ;xxx54321 x
                    lsl       group+7             ;xxx54321 0
                    rola                          ;xx543210 x
                    and       #$3F                ;--543210 x
                    sta       min
                    clr       sec
                    clr       th8
                    bset      UPDATE_DATE         ;UPDATE MJD
          ;-------------------------------------- ;Local time difference adjustment.
LOCAL               lda       group+7
                    lsla
                    beq       OUT1                ;ADJUSTMENT ?
                    bcc       POS                 ;YES, POSITIVE ?
NEG                 lsra:4                        ;NO, NEGATIVE
                    tax                           ;HOURS IN X
                    bcc       NOTHN               ;1/2 HOUR ?
                    lda       min                 ;YES
                    sub       #30                 ;SUBTRACT 30 MINUTES
                    bpl       LT60                ;UNDERFLOW ?
                    add       #60                 ;YES, ADD 60 MINUTES
                    dec       our                 ;AND SUBTRACT 1 HOUR
LT60                sta       min
NOTHN               txa                           ;NEGATIVE HOUR OFFSET
                    sub       our                 ;MINUS UTC HOURS
                    coma                          ;WRONG WAY ROUND SO COMPLEMENT
                    inca                          ;AND INCREMENT
                    bpl       ZOM                 ;UNDERFLOW ?
                    add       #24                 ;YES, ADD 24 HOURS
                    sta       our
                    tst       bmjd+2              ;AND SUBTRACT A DAY
                    bne       TT2                 ;LSB WILL UNDERFLOW ?
                    tst       bmjd+1              ;YES
                    bne       TT1                 ;MSB WILL UNDERFLOW ?
                    dec       bmjd                ;YES DECREMENT MS BIT
TT1                 dec       bmjd+1              ;DECREMENT MSB
TT2                 dec       bmjd+2              ;DECREMENT LSB
                    bra       OUT1

ZOM                 sta       our
                    bra       OUT1

POS                 lsra:4                        ;POSITIVE ADJUSTMENT
                    tax                           ;HOURS IN X
                    bcc       NOTHP               ;HALF HOUR ?
                    lda       #30                 ;YES, ADD 30 MINUTES
                    add       min
                    cmpa      #59
                    bls       HDON                ;OVERFLOW ?
                    sub       #60                 ;YES, SUBTRACT 60 MINUTES
                    inc       our                 ;AND ADD AN HOUR
HDON                sta       min
NOTHP               txa                           ;HOUR OFFSET
                    add       our                 ;ADD UTC HOURS
                    cmpa      #23
                    bls       ADDON               ;OVERFLOW ?
                    sub       #24                 ;YES, SUBTRACT 24 HOURS
                    inc       bmjd+2              ;AND ADD A DAY
                    bne       ADDON
                    inc       bmjd+1
                    bne       ADDON
                    inc       bmjd
ADDON               sta       our
OUT1                bclr      VALID_GROUP         ;GROUP HANDLED, CLEAR FLAG
                    rti

;*******************************************************************************
; Process group 14 (EON)
;*******************************************************************************

PROC14              proc
                    cmpa      #$E0
                    jne       _7@@

                    clr       irq_tmp             ;LOOK FOR PI CODE IN TABLE
Loop@@              ldx       irq_tmp
                    lda       EON,x
                    cmpa      group+6
                    bne       _5@@
                    lda       EON+1,x
                    cmpa      group+7
                    bne       _5@@
;                   lda       group+3             ;TP (ON), NOT USED
;                   and       #$10
;                   ldx       irq_tmp
;                   sta       EON+11,x
                    lda       group+3             ;PI CODE FOUND
                    and       #$0F
                    cmpa      #4                  ;PS ?
                    bhs       _1@@
                    lsla                          ;YES
                    add       irq_tmp
                    tax
                    lda       group+4
                    sta       EON+2,x             ;SAVE 2 PS-NAME CHARACTERS
                    lda       group+5
                    sta       EON+3,x
                    bra       OUT1

_1@@                cmpa      #4                  ;AF ?
                    bne       _4@@
                    lda       group+4             ;YES, METHOD A
                    cmpa      #250
                    bne       _2@@                ;MEDIUM OR LONG WAVE ?
                    lda       EON+12,x            ;YES
                    cmpa      #$FF                ;FIRST 2 BYTES ALREADY IN ?
                    beq       _7@@                ;IF NOT, DO NOTHING
                    lda       EON+14,x            ;YES
                    cmpa      #$FF                ;M/L FREQUENCY ALREADY IN ?
                    bne       _7@@                ;IF SO, DO NOTHING
                    lda       #250                ;NO, STORE FIRST FREQUENCY AFTER
                    sta       EON+14,x            ;ARRIVAL OF INITIAL BYTES
                    lda       group+5
                    sta       EON+15,x
                    bra       _7@@

_2@@                cmpa      #224                ;FM
                    blo       _3@@                ;LEGAL ? (No. OF FREQUENCIES)
                    cmpa      #249
                    bhi       _3@@
                    ldx       irq_tmp
                    sta       EON+12,x            ;YES, SAVE No. OF FREQUENCIES
                    lda       group+5
                    sta       EON+13,x            ;AND FIRST FREQUENCY
_3@@                bra       _7@@

;                   cmpa      #$0D
;                   bne       _4@@
;                   lda       group+4             ;PTY (EON), NOT USED
;                   lsra:3
;                   ldx       irq_tmp
;                   sta       EON+10,x
;                   bra       _7@@
_4@@                cmpa      #$0E
                    bne       _7@@
                    ldx       irq_tmp             ;PIN
                    lda       group+4
                    sta       EON+10,x
                    lda       group+5
                    sta       EON+11,x
                    bra       _7@@

_5@@                cmpa      #$FF                ;END OF PI LIST ?
                    bne       _6@@
                    lda       group+6             ;YES, ADD THIS PI CODE
                    sta       EON,x
                    lda       group+7             ;TO EON TABLE
                    sta       EON+1,x
                    bra       _7@@

_6@@                lda       irq_tmp             ;NOT END, TRY NEXT ENTRY
                    add       #16
                    sta       irq_tmp
                    cmpa      #$B0                ;END OF TABLE (11 ENTRIES) ?
                    beq       _7@@
                    jmp       Loop@@

_7@@                bclr      VALID_GROUP         ;GROUP HANDLED, CLEAR FLAG
                    rti

;*******************************************************************************
; Display type selection
;*******************************************************************************

MOD                 proc
                    brclr     CLEAR_DISPLAY,_1@@  ;SHOULD DISPALY BE INITIALISED ?
                    jsr       INITD               ;YES, DO IT
                    bclr      CLEAR_DISPLAY       ;AND CLEAR FLAG
_1@@                jsr       WAIT
                    lda       #$0C                ;SWITCH DISPLAY ON
                    jsr       CLOCK               ;LATCH IT
                    jsr       WAIT
;                   lda       #$38                ;/16 DISPLAY
                    lda       #$30                ;/8 DISPLAY
                    jsr       CLOCK               ;LATCH IT
                    jsr       WAIT
                    lda       #$80                ;ADDRESS DISPLAY RAM
                    jsr       CLOCK               ;LATCH IT
                    brset     SWITCH,_2@@         ;STANDBY ?
                    brset     SLEEP_DISPLAY,_11@@ ;YES, SLEEP DISPLAY ?
                    brset     ALARM_DISPLAY,_13@@ ;NO, ALARM DISPLAY ?
                    jsr       STBYD               ;NO, NORMAL STANDBY DISPLAY
                    bra       _14@@
          ;--------------------------------------
_2@@                brclr     RDS_DISPLAYS,_10@@  ;RDS DISPLAYS ?
                    lda       rtdis
                    cmpa      #1
                    bne       _3@@
                    jsr       PTYD                ;PTY
                    bra       _14@@
          ;--------------------------------------
_3@@                cmpa      #2
                    bne       _4@@
                    jsr       DIPI                ;PI
                    bra       _14@@
          ;--------------------------------------
_4@@                cmpa      #3
                    bne       _5@@
                    jsr       DITAP               ;TA & TP
                    bra       _14@@
          ;--------------------------------------
_5@@                cmpa      #4
                    bne       _6@@
                    jsr       DPIN1               ;PIN - HEX
                    bra       _14@@
          ;--------------------------------------
_6@@                cmpa      #5
                    bne       _7@@
                    jsr       DPIN2               ;PIN - DAY AND TIME
                    bra       _14@@
          ;--------------------------------------
_7@@                cmpa      #6
                    bne       _8@@
                    jsr       DMJD                ;mjd
                    bra       _14@@
          ;--------------------------------------
_8@@                cmpa      #7
                    bne       _9@@
                    jsr       DMSD                ;M/S & DI
                    bra       _14@@
          ;--------------------------------------
_9@@                jsr       DEON
                    bra       _14@@
          ;--------------------------------------
_10@@               brclr     RT_DISPLAY,_11@@    ;RT DISPLAY ?
                    jsr       RTDS
                    bra       _14@@
          ;--------------------------------------
_11@@               brclr     SLEEP_DISPLAY,_12@@ ;SLEEP TIMER DISPLAY ?
                    jsr       SLEEPD
                    bra       _14@@
          ;--------------------------------------
_12@@               brset     ALARM_DISPLAY,_13@@ ;ALARM DISPLAY ?
                    jsr       NORMD
                    bra       _14@@
          ;--------------------------------------
_13@@               jsr       ALRMD
_14@@               clrx
Loop@@              jsr       WAIT
                    bset      LCD_DATA            ;WRITE DATA
                    lda       disp,x              ;GET A BYTE
                    cmpa      #$FF
                    bne       _15@@
                    lda       #$2D
_15@@               jsr       CLOCK               ;SEND IT TO MODULE
                    incx
                    cpx       #16                 ;DONE ?
                    bne       Loop@@
                    bra       VFD                 ;REMOVE FOR /16 LCDs

;*******************************************************************************
; Additional bits for /16 LCD modules -- LCD401 is dead code
;*******************************************************************************

LCD401              proc
                    jsr       WAIT
                    lda       #$A8                ;TO 40
                    jsr       CLOCK               ;SEND IT TO MODULE
                    clrx
Loop@@              jsr       WAIT
                    bset      LCD_DATA            ;WRITE DATA
                    lda       disp+8,x            ;GET A BYTE
                    cmpa      #$FF
                    bne       Cont@@
                    lda       #$2D
Cont@@              jsr       CLOCK               ;SEND IT TO MODULE
                    incx
                    cpx       #8                  ;DONE ?
                    bne       Loop@@
;                   bra       VFD

;*******************************************************************************
; VFD
;*******************************************************************************

VFD                 proc
                    bclr      SPI_MOSI            ;DATA LOW ?
                    bset      SPI_CLK             ;CLOCK HIGH ?
                    bclr      SPI_SS              ;ENABLE LOW
                    clrx                          ;SEND VFD SET-UP BYTES
_1@@                lda       InitF@@,x
                    stx       w7                  ;SAVE INDEX
                    bsr       VFDL
                    cpx       #7
                    bne       _1@@                ;LAST BYTE ?
                    clrx                          ;SEND 16 CHARACTER BYTES
_2@@                stx       w7                  ;SAVE INDEX
                    lda       disp,x              ;ASCII
                    cmpa      #$FF
                    bne       _3@@
                    lda       #$2D                ;REPLACE $FF WITH "-"
_3@@                and       #$7F                ;IGNORE BIT 7
                    tax
                    lda       VTAB,x              ;CONVERT TO VFD CHARACTER SET
                    bsr       VFDL
                    cpx       #16
                    bne       _2@@                ;LAST BYTE ?
                    bset      SPI_SS              ;ENABLE HIGH
                    bclr      SPI_CLK             ;CLOCK LOW ?
                    rts

InitF@@             fcb       $A0,$0F,$B0,$00,$80,$00,$90

;*******************************************************************************

VFDL                proc
                    ldx       #8
Loop@@              lsra                          ;GET A BIT
                    bcc       _1@@
                    bset      SPI_MOSI            ;DATA HIGH
_1@@                bclr      SPI_CLK             ;CLOCK
                    bset      SPI_CLK             ;IT
                    bclr      SPI_MOSI            ;CLEAR DATA
                    dbnzx     Loop@@              ;COMPLETE ? NO
                    ldx       #64
Delay@@             dbnzx     Delay@@             ;WAIT 200uS
                    ldx       w7                  ;RESTORE INDEX
                    incx
                    rts

;*******************************************************************************
; Normal display (PS and time).
;*******************************************************************************

NORMD               proc
                    lda       #' '
                    sta       disp
                    sta       disp+9
                    sta       disp+15
                    lda       #'.'
                    brclr     SLEEP_TIMER_RUNNING,_1@@ ;DP TO INDICATE SLEEP TIMER RUNNING
                    brclr     2,th8,_1@@          ;FLASH IT
                    sta       disp+15
_1@@                clrx
_2@@                lda       ps_name,x           ;GET PS NAME
                    sta       disp+1,x
                    incx
                    cpx       #7
                    bls       _2@@
                    lda       our                 ;GET TIME
                    jsr       CBCD
                    cpx       #'0'                ;LEADING ZERO ?
                    bne       _3@@
                    ldx       #$20                ;YES, MAKE IT A SPACE
_3@@                stx       disp+10
                    sta       disp+11
                    lda       min
                    jsr       CBCD
                    stx       disp+13
                    sta       disp+14
                    lda       #' '
                    brclr     2,th8,_4@@
                    lda       #':'                ;0.5 Hz FLASHING COLON
_4@@                sta       disp+12
                    rts

;*******************************************************************************
; Clear display transient flags.
;*******************************************************************************

CLTR                bclr      DISPLAY_TRANSIENT   ;CLEAR DISPLAY TRANSIENT FLAG
                    bclr      RT_DISPLAY          ;NOT RT DISPLAY
                    clr       rtdis               ;CLEAR RDS DISPLAY INDEX
                    bclr      ALARM_DISPLAY       ;NOT ALARM DISPLAY
                    bclr      ALARM_SETUP         ;NOT ALARM SET-UP
                    bclr      RDS_DISPLAYS        ;NOT RDS DISPLAYS
                    bclr      SLEEP_DISPLAY       ;NOT SLEEP TIMER DISPLAY
                    rts

;*******************************************************************************
; PTY display.
;*******************************************************************************

PTYD                proc
                    ldx       pty
                    cpx       #16
                    blo       _1@@
                    clrx
_1@@                lda       #::PTYT             ;size of table entry (WAS: #16)
                    mul
                    sta       w8
                    clr       w7
Loop@@              ldx       w8
                    lda       PTYT,x
                    ldx       w7
                    sta       disp,x              ;WAS MOD2
                    inc       w8
                    inc       w7
                    lda       w7
                    cmpa      #16
                    blo       Loop@@
                    rts

;*******************************************************************************
; RDS display
;*******************************************************************************

NXTC                proc
                    ldx       disp2
                    lda       RT-1,x              ;RT
                    cmpa      #$20
                    bne       NOTSP               ;SPACE ?
                    brclr     SPACE_FLAG,FSP      ;YES, FIRST ONE ?
                    inc       disp1               ;NO, SKIP THIS ONE
                    inc       disp2
;                   bra       RTDS

;*******************************************************************************

RTDS                proc
                    lda       disp2
                    cmpa      #69
                    bhi       Done@@              ;END OF RT BUFFER
                    bra       NXTC                ;NO, GET NEXT CHARACTER

FSP                 bset      SPACE_FLAG          ;FIRST SPACE, SET FLAG
                    bra       Cont@@

NOTSP               bclr      SPACE_FLAG          ;NOT A SPACE, CLEAR FLAG
Cont@@              sta       w8                  ;SAVE NEW CHARACTER
                    clrx
Loop@@              lda       disp+1,x            ;MOVE
                    sta       disp,x              ;REST
                    incx                          ;LEFT
                    cpx       #15                 ;ONE
                    bne       Loop@@              ;PLACE
                    lda       w8
                    sta       disp+15             ;ADD NEW CHAR. (WAS MOD2)
Done@@              rts

;*******************************************************************************
; Standby display
;*******************************************************************************

STBYD               proc
                    brset     ALARM_ARMED,ALRMA   ;ALARM ARMED ?
                    lda       dow                 ;NO, GET DAY OF WEEK
                    lsla
                    add       dow
                    tax
                    lda       DNAME,x
                    sta       disp
                    lda       DNAME+1,x
                    sta       disp+1
                    lda       DNAME+2,x
                    sta       disp+2
                    lda       #$20
                    sta       disp+3
                    sta       disp+6
                    sta       disp+10
                    lda       dom+1               ;DATE
                    add       #$30
                    sta       disp+5
                    lda       dom
                    beq       _1@@                ;IF ZERO USE A SPACE
                    add       #$10                ;IF NOT MAKE ASCII
_1@@                add       #$20
                    sta       disp+4
                    ldx       month+1             ;MONTH, LSD
                    lda       month               ;MONTH, MSD
                    beq       _2@@
                    txa
                    add       #10
                    tax
_2@@                stx       w8
                    txa
                    lsla
                    add       w8
                    tax
                    lda       MNAME-3,x
                    sta       disp+7
                    lda       MNAME-2,x
                    sta       disp+8
                    lda       MNAME-1,x
                    sta       disp+9
                    bra       STIME

;*******************************************************************************
; Standby (alarm armed) display
;*******************************************************************************

ALRMA               proc
                    lda       alarm_hours         ;GET ALARM HOURS
                    jsr       CBCD
                    stx       disp
                    sta       disp+1
                    lda       alarm_mins
                    jsr       CBCD
                    stx       disp+2
                    sta       disp+3
                    clrx
_1@@                lda       ALARMS+1,x
                    sta       disp+4,x
                    incx
                    cpx       #6
                    bls       _1@@
STIME               lda       our                 ;GET TIME
                    jsr       CBCD
                    cpx       #$30                ;LEADING ZERO ?
                    bne       _2@@
                    ldx       #$20                ;YES, MAKE IT A SPACE
_2@@                stx       disp+11
                    sta       disp+12
                    lda       min
                    jsr       CBCD
                    stx       disp+14
                    sta       disp+15
                    lda       #$20
                    brclr     2,th8,_3@@          ;FLASH ?
                    lda       #$3A                ;0.5 Hz FLASHING COLON
_3@@                sta       disp+13
                    rts

;*******************************************************************************
; PI display
;*******************************************************************************

DIPI                proc
                    clrx
Loop@@              lda       PIST,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       pi
                    beq       Done@@
                    jsr       SPLIT
                    stx       disp+11
                    sta       disp+12
                    lda       pi+1
                    jsr       SPLIT
                    stx       disp+13
                    sta       disp+14
Done@@              rts

;*******************************************************************************
; Alarm display
;*******************************************************************************

ALRMD               proc
                    clrx                          ;YES
_1@@                lda       ALARMS,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       _1@@
                    brclr     ALARM_ARMED,Done@@  ;ALARM ARMED ?
                    lda       #$3A                ;YES
                    sta       disp+12
                    lda       alarm_hours         ;GET ALARM HOURS
                    jsr       CBCD
                    cpx       #$30                ;LEADING ZERO ?
                    bne       _2@@
                    ldx       #$20                ;YES, MAKE IT A SPACE
_2@@                stx       disp+10
                    sta       disp+11
                    lda       alarm_mins
                    jsr       CBCD
                    stx       disp+13
                    sta       disp+14
                    brclr     ALARM_SETUP,Done@@  ;SET-UP ?
                    brclr     2,th8,Done@@
                    lda       #$20
                    brset     ALARM_HOURS_SETUP,_3@@        ;HOURS ?
                    sta       disp+13                       ;NO, FLASH MINUTES
                    sta       disp+14
                    bra       Done@@

_3@@                sta       disp+10             ;YES, FLASH HOURS
                    sta       disp+11
Done@@              rts

;*******************************************************************************
; TA & TP flags display
;*******************************************************************************

DITAP               proc
                    clrx
Loop@@              lda       TAPST,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       #$31
                    brclr     TP_FLAG,_1@@        ;TP FLAG HIGH ?
                    sta       disp+6              ;YES, DISPLAY A 1
_1@@                brclr     TA_FLAG,Done@@      ;TA FLAG HIGH ?
                    sta       disp+14             ;YES, DISPLAY A 1
Done@@              rts

;*******************************************************************************
; PIN displays
;*******************************************************************************

DPIN1               proc
                    clrx
Loop@@              lda       PINST1,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       pin
                    beq       Done@@
                    jsr       SPLIT
                    stx       disp+11
                    sta       disp+12
                    lda       pin+1
                    jsr       SPLIT
                    stx       disp+13
                    sta       disp+14
Done@@              rts

;*******************************************************************************

DPIN2               proc
                    clrx
_1@@                lda       PINST2,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       _1@@
                    lda       pin                 ;DATE
                    beq       Done@@
                    lsra:3
                    jsr       CBCD
                    cpx       #$30
                    bne       _2@@
                    ldx       #$20
_2@@                stx       disp+2
                    sta       disp+3
                    cpx       #$31
                    beq       _5@@
                    cmpa      #$31
                    bne       _3@@
                    lda       #'s'
                    sta       disp+4
                    lda       #'t'
                    sta       disp+5
_3@@                cmpa      #$32
                    bne       _4@@
                    lda       #'n'
                    sta       disp+4
                    lda       #'d'
                    sta       disp+5
_4@@                cmpa      #$33
                    bne       _5@@
                    lda       #'r'
                    sta       disp+4
                    lda       #'d'
                    sta       disp+5
_5@@                lda       pin                 ;HOURS
                    and       #7
                    ldx       pin+1
                    aslx
                    rola
                    aslx
                    rola
                    jsr       CBCD
                    stx       disp+10
                    sta       disp+11
                    lda       pin+1               ;MINUTES
                    and       #$3F
                    jsr       CBCD
                    stx       disp+13
                    sta       disp+14
Done@@              rts

;*******************************************************************************
; mjd display
;*******************************************************************************

DMJD                proc
                    bsr       SMJD
                    lda       mjd
                    beq       Done@@
                    add       #$30
                    sta       disp+10
                    lda       mjd+1
                    add       #$30
                    sta       disp+11
                    lda       mjd+2
                    add       #$30
                    sta       disp+12
                    lda       mjd+3
                    add       #$30
                    sta       disp+13
                    lda       mjd+4
                    add       #$30
                    sta       disp+14
Done@@              rts

;*******************************************************************************

SMJD                proc
                    clrx
Loop@@              lda       MJDST,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    rts

;*******************************************************************************
; EON display
;*******************************************************************************

DEON                proc
                    bsr       SMJD                ;CLEAR FREQUENCY CHARACTERS
                    lda       rtdis
                    sub       #8
                    ldx       #16
                    mul
                    tax
                    lda       #$20
                    sta       disp+8
                    sta       disp+9
                    lda       EON+2,x             ;DISPLAY PS (EON)
                    sta       disp
                    lda       EON+3,x
                    sta       disp+1
                    lda       EON+4,x
                    sta       disp+2
                    lda       EON+5,x
                    sta       disp+3
                    lda       EON+6,x
                    sta       disp+4
                    lda       EON+7,x
                    sta       disp+5
                    lda       EON+8,x
                    sta       disp+6
                    lda       EON+9,x
                    sta       disp+7
                    lda       EON+13,x
                    cmpa      #205                ;FILLER ?
                    bne       _1@@
                    incx
                    lda       EON+13,x            ;YES, TRY AGAIN
_1@@                cmpa      #250                ;MEDIUM/LONG ?
                    beq       MLWF
                    cmpa      #204                ;NO, FREQUENCY OK ?
                    bhi       Done@@
                    ldx       #10                 ;VHF
                    mul
                    add       #$2E                ;CALCULATE FREQUENCY (BINARY)
                    sta       w1
                    txa
                    adc       #$22
                    sta       w2
                    jsr       DCON2               ;CONVERT TO DECIMAL
                    lda       q+4                 ;DISPLAY VHF EON FREQUENCY
                    bne       _2@@
                    lda       #$F0
_2@@                add       #$30
                    sta       disp+10
                    tax
                    lda       q+5
                    bne       _3@@
                    cpx       #$20
                    bne       _3@@
                    lda       #$F0
_3@@                add       #$30
                    sta       disp+11
                    lda       q+6
                    add       #$30
                    sta       disp+12
                    lda       #$2E
                    sta       disp+13
                    lda       q+7
                    add       #$30
                    sta       disp+14
                    lda       q+8
                    add       #$30
                    sta       disp+15
Done@@              rts

;*******************************************************************************

MLWF                proc
                    incx                          ;DISPLAY M/L EON FREQUENCY
                    lda       EON+13,x
                    cmpa      #15
                    bls       _1@@
                    add       #27                 ;MW OFFSET
_1@@                add       #16                 ;M/L OFFSET
                    ldx       #9
                    mul
                    stx       w2
                    sta       w1
                    bsr       DCON2               ;CONVERT TO BCD IN Q
                    lda       q+5
                    bne       _2@@                ;IF THOUSANDS OF kHz A ZERO
                    lda       #$F0                ;DISPLAY AS A SPACE
_2@@                add       #'0'
                    sta       disp+9
                    lda       q+6
                    add       #'0'
                    sta       disp+10
                    lda       q+7
                    add       #'0'
                    sta       disp+11
                    lda       q+8
                    add       #'0'
                    sta       disp+12
                    lda       #'k'
                    sta       disp+13
                    lda       #'H'
                    sta       disp+14
                    lda       #'z'
                    sta       disp+15
                    rts

;*******************************************************************************
; Sleep display.
;*******************************************************************************

SLEEPD              proc
                    clrx
Loop@@              lda       SLPST,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       slept
                    jsr       CBCD
                    stx       disp+8
                    sta       disp+9
                    rts

;*******************************************************************************
; M/S & DI display.
;*******************************************************************************

DMSD                proc
                    clrx
Loop@@              lda       MSDST,x
                    sta       disp,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    brclr     MODE_SELECT,Cont@@  ;M/S FLAG SET
                    lda       #'M'                ;YES, MUSIC
                    sta       disp+6
Cont@@              lda       di
                    bsr       CBCD
                    stx       disp+13
                    sta       disp+14
                    rts

;*******************************************************************************
; Convert binary to unpacked BCD in Q.
;*******************************************************************************

DCON2               proc
                    ldx       #r                  ;CLEAR
                    stx       num1
                    jsr       CLRAS               ;RR
                    inc       r+8                 ;R <- 1
                    jsr       CLQ                 ;CLEAR RQ
                    lda       #14                 ;14 BITS TO CONVERT
                    sta       w6
Loop@@              lsr       w2                  ;MOVE OUT
                    ror       w1                  ;FIRST (LS) BIT
                    bcc       Cont@@              ;ZERO
                    ldx       #q                  ;ONE, ADD
                    stx       num2                ;CURRENT VALUE
                    jsr       ADD                 ;OF R
Cont@@              ldx       #r                  ;ADD R
                    stx       num2                ;TO
                    jsr       ADD                 ;ITSELF
                    dbnz      w6,Loop@@           ;ALL DONE ?
                    rts

;*******************************************************************************
; Split A nibbles into A (LS) and X (MS)
; and convert to ASCII.
;*******************************************************************************

SPLIT               proc
                    tax                           ;MSD INTO X, LSD INTO A
                    sec
                    rorx
                    sec
                    rorx
                    lsrx:2
                    cpx       #'9'                ;$30-$39 <- 0-9
                    bls       _@@
                    incx:7
_@@                 and       #$0F                ;$41-$46 <- A-F
                    add       #'0'
                    cmpa      #'9'
                    bls       Done@@
                    add       #7
Done@@              rts

;*******************************************************************************
; Send and clock data to LCD module.
; Check to see if LCD module is busy.
;*******************************************************************************

CLOCK               proc
                    sta       PORTC
                    bset      LCD_CLK
                    bclr      LCD_CLK             ;CLOCK IT
                    rts

;*******************************************************************************

WAIT                proc
                    bclr      LCD_DATA
                    bset      LCD_BUSY            ;READ LCD MODULE BUSY FLAG
                    bclr      LCD_CLK
                    clr       DDRC                ;INPUT ON PORTC
Loop@@              bset      LCD_CLK             ;CLOCK HIGH
                    lda       PORTC               ;READ MODULE
                    bclr      LCD_CLK             ;CLOCK LOW
                    sta       w7
                    brset     7,w7,Loop@@         ;BUSY ?
                    com       DDRC                ;OUTPUT ON PORTC
                    bclr      LCD_BUSY
                    rts

;*******************************************************************************
; Hex->BCD conversion (& decimal adjust).
;*******************************************************************************

CBCD                proc
                    bsr       UPX
                    bsr       ADJI                ;DECIMAL ADJUST
BCD                 sta       w7                  ;SAVE
                    add       #$16                ;ADD $16 (BCD 10)
                    bsr       ADJU                ;ADJUST
                    decx
                    bpl       BCD                 ;TOO FAR ?
                    lda       w7                  ;YES, RESTORE A
                    bra       SPLIT

;*******************************************************************************

ADJU                proc
                    bhcc      ADJI                ;OVERFLOW ?
                    add       #6                  ;YES
                    rts

;*******************************************************************************

ADJI                proc
                    add       #6                  ;NO, BUT IS LS DIGIT
                    bhcs      ARTS                ;BIGGER THAN 9 ?
                    sub       #6                  ;NO, RESTORE
ARTS                rts

;*******************************************************************************

UPX                 proc
                    tax
                    lsrx:4                        ;MSB IN X
                    and       #$0F                ;LSB IN A
                    rts

;*******************************************************************************
; LCD initialisation.
;*******************************************************************************

INITD               lda       #$A0
                    sta       RT                  ;SPACES BETWEEN PTY & RT
                    sta       RT+1
                    sta       RT+3
                    sta       RT+4
                    lda       #$2D
                    sta       RT+2                ;DASH BETWEEN EXISTING DISPLAY & RT
                    lda       #$20                ;INITIALISE RADIOTEXT TO SPACES
                    ldx       #5                  ;AFTER CONF LOSS OR TEXT A/B CHANGE
CLOP                sta       RT,x
                    incx
                    cpx       #69
                    bne       CLOP
                    clr       disp1               ;INITIALISE SCROLLING POINTERS
                    clr       disp2
                    clr       pty                 ;CLEAR PTY
                    clr       pin                 ;AND
                    clr       pin+1               ;PIN
                    clr       di                  ;AND DI
                    bclr      MODE_SELECT         ;AND M/S
                    bclr      TP_FLAG             ;CLEAR TP FLAG
                    bclr      RT_DISPLAY          ;CANCEL RT DISPLAY
                    clrx
                    lda       #$2D
PLOP3               sta       ps_name,x           ;CLEAR PS NAME
                    incx
                    cpx       #8
                    bne       PLOP3
                    rts

CLREON              clrx
                    lda       #$FF
ELOP                sta       EON,x               ;EON RAM CLEAR
                    incx
                    cpx       #176
                    bne       ELOP
                    rts

;*******************************************************************************
; Display strings.
;*******************************************************************************

ALARMS              fcc       '  Alarm - OFF   '
PIST                fcc       ' PI code -      '
TAPST               fcc       ' TP - 0 TA - 0  '
PINST1              fcc       ' PIN no. -      '
PINST2              fcc       '   th at --.--  '
MJDST               fcc       ' MJ day -       '
SLPST               fcc       ' Sleep   0 min. '
MSDST               fcc       ' M/S S     DI 0 '

;*******************************************************************************
; mjd day and month strings.
;*******************************************************************************

DNAME               fcc       'MonTueWedThuFriSatSun'
                    fcc       'inv'
MNAME               fcc       'JanFebMarAprMayJunJulAugSepOctNovDec'

;*******************************************************************************
; Programme Type (PTY) Codes.
;*******************************************************************************

PTYT                fcc       'No program type '  ;0
                    fcc       '      News      '  ;1
                    fcc       'Current affairs '  ;2
                    fcc       '  Information   '  ;3
                    fcc       '     Sport      '  ;4
                    fcc       '   Education    '  ;5
                    fcc       '     Drama      '  ;6
                    fcc       '    Culture     '  ;7
                    fcc       '    Science     '  ;8
                    fcc       '    Varied      '  ;9
                    fcc       '   Pop music    '  ;10
                    fcc       '   Rock music   '  ;11
                    fcc       ' Easy listening '  ;12
                    fcc       ' Light classics '  ;13
                    fcc       'Serious classics'  ;14
                    fcc       '   Other music  '  ;15

;*******************************************************************************
; VFD character set.
;
; Position in table is ASCII value.
; Entry is the VFD character used.
; Last column shows characters replaced
; by spaces. $00 to $1F are ASCII control
; characters and shouldn't occur.
; : has been entered as -
; / has been entered as -
; " has been entered as '
;*******************************************************************************

VTAB                fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7E,$7E,$7E     ;                   all
                    fcb       $7E,$7B,$7A,$7E     ;! " #              #
                    fcb       $7E,$7E,$7E,$7A     ;$ % & '            $%&
                    fcb       $7E,$7E,$7E,$7E     ;( ) * +            all
                    fcb       $3F,$7D,$3E,$7D     ;, - . /
                    fcb       $00,$01,$02,$03     ;0 1 2 3
                    fcb       $04,$05,$06,$07     ;4 5 6 7
                    fcb       $08,$09,$7D,$7E     ;8 9 : ;            ;
                    fcb       $7E,$7E,$7E,$7C     ;< = > ?            <=>
                    fcb       $7E,$0A,$0B,$0C     ;@ A B C            @
                    fcb       $0D,$0E,$0F,$10     ;D E F G
                    fcb       $11,$12,$13,$14     ;H I J K
                    fcb       $15,$16,$17,$18     ;L M N O
                    fcb       $19,$1A,$1B,$1C     ;P Q R S
                    fcb       $1D,$1E,$1F,$20     ;T U V W
                    fcb       $21,$22,$23,$7E     ;X Y Z [             [
                    fcb       $7E,$7E,$7E,$7D     ;\ ] ^ -            \]^
                    fcb       $7A,$24,$25,$26     ;' a b c
                    fcb       $27,$28,$29,$2A     ;d e f g
                    fcb       $2B,$2C,$2D,$2E     ;h i j k
                    fcb       $2F,$30,$31,$32     ;l m n o
                    fcb       $33,$34,$35,$36     ;p q r s
                    fcb       $37,$38,$39,$3A     ;t u v w
                    fcb       $3B,$3C,$3D,$7E     ;x y z {            {
                    fcb       $7E,$7E,$7E,$7E     ;| } ~              all

;*******************************************************************************
; MC68HC05E0 functions.
;
; Add, Subtract, Multiply, Divide,
; mjd -> day, date, month and year
;
; P. Topping 5th December '91
;
; Transfer of BCD numbers.
; (X) <- (num1), X preserved
;*******************************************************************************

TRA                 stx       num2                ;CLEAR DESTINATION
                    jsr       CLRAS               ;AND ADD IT TO No. AT num1

;*******************************************************************************
; Addition of BCD numbers.
;
; (X) <- (num1) + (num2), X preserved
;*******************************************************************************

ADD                 proc
                    clr       carry
                    stx       w7
AD                  stx       w5                  ;ANSWER POINTER
                    lda       #ND
                    sta       count
                    ldx       num1                ;1st No. POINTER
                    stx       w3
                    ldx       num2                ;2nd No. POINTER
                    stx       w4
Loop@@              ldx       w3
                    lda       ND-1,x
                    dec       w3
                    ldx       w4
                    add       ND-1,x              ;ADD
                    dec       w4
                    add       carry               ;SET ON ADDITION OVERFLOW
                    clr       carry               ;OR POS. RESULT SUBTRACTION
                    bsr       ADJ                 ;DECIMAL ADJUST
                    ldx       w5
                    sta       ND-1,x              ;SAVE ANSWER
                    dec       w5
                    dbnz      count,Loop@@        ;DONE ?
                    ldx       w7
                    rts

;*******************************************************************************

Loop@@              proc
                    sub       #10                 ;YES, SUTRACT 10
                    inc       carry               ;AND RECORD CARRY
ADJ                 cmpa      #10
                    bhs       Loop@@              ;10 OR MORE ?
                    rts                           ;NO

;*******************************************************************************
; Subtraction, complementing and incre-
; menting (X=REG-ND) of BCD numbers.
;
; (X) <- (num1) - (num2), X preserved.
; (X and num2 should not be equal)
;*******************************************************************************

SUB                 proc
                    stx       w6                  ;ANSWER POINTER
                    bsr       COM2                ;9S COMP. SECOND NUMBER
                    clr       carry               ;SET CARRY TO ONE
                    inc       carry               ;BEFORE ADDING
                    bsr       AD                  ;ADD FIRST NUMBER
;                   bra       COM2

;*******************************************************************************

COM2                proc
                    ldx       num2                ;9S COMPLEMENT
                    bsr       COMP                ;SECOND NUMBER
                    ldx       w6                  ;RESTORE ANSWER POINTER
                    rts

;*******************************************************************************

COMP                proc
                    lda       #ND                 ;9S COMPLEMENT
                    sta       count
Loop@@              lda       #9
                    sub       ND-1,x
                    sta       ND-1,x
                    decx
                    dbnz      count,Loop@@
                    rts

;*******************************************************************************
; Dead code - COM10 is never called

COM10               bsr       COMP                ;NINES COMPLEMENT THEN
;                   bra       ADD1

;*******************************************************************************

ADD1                proc
                    lda       #ND                 ;ADD 1 FOR TENS COMPLEMENT
                    sta       count               ;ENTER WITH X = REG-ND
Loop@@              inc       2*ND-1,x
                    lda       2*ND-1,x
                    cmpa      #$0A
                    blo       Done@@
                    sub       #10
                    sta       2*ND-1,x
                    decx
                    dbnz      count,Loop@@
Done@@              rts

;*******************************************************************************
; Mult., R <- P x Q, over. in tmp, X = #R.
;*******************************************************************************

MULT                proc
                    ldx       #r
                    jsr       CLRAS
                    ldx       #tmp
                    jsr       CLRAS               ;CLEAR RESULT
                    ldx       #2*ND
                    stx       w6                  ;INIT. R POINTER
                    ldx       #ND
Loop@@              lda       p-1,x
                    stx       w1                  ;SAVE P POINTER
                    sta       carry               ;SAVE P
                    ldx       #ND                 ;INIT. Q POINTER
Xit@@               lda       q-1,x
                    sta       w4                  ;SAVE Q
                    beq       ToZero@@            ;IF ZERO GOTO NEXT Q
                    lda       carry               ;RECALL P
                    sta       w3                  ;SAVE P
                    clra
Ply@@               lsr       carry               ;RIGHT SHIFT INTO C
                    bcc       Shf@@               ;C = ZERO ?
                    add       w4                  ;NO, A=A+Q
Shf@@               tst       carry               ;ZERO ?
                    beq       C4@@                ;YES, FINISHED WITH THIS Q
                    asl       w4                  ;NO, LEFT SHIFT Q
                    bra       Ply@@

C4@@                decx                          ;Q = Q + 1
                    stx       w2                  ;SAVE Q POINTER
                    ldx       w6                  ;R POINTER
                    add       r-ND-1,x            ;ADD R TO A
                    bsr       ADJ                 ;ADJUST
                    sta       r-ND-1,x            ;R = R + A
                    lda       carry
                    add       r-ND-2,x            ;ADD R-(ND+2) TO CARRY
                    sta       r-ND-2,x            ;R-(ND+2) = R-(ND+2) + CARRY
                    lda       w3                  ;RECALL P
                    sta       carry               ;SAVE IN CARRY
                    decx
                    stx       w6                  ;SAVE R POINTER
                    ldx       w2                  ;Q POINTER
                    bra       C3@@

ToZero@@            dec       w6                  ;DEC. R POINTER
                    decx                          ;DEC. Q POINTER
C3@@                bne       Xit@@
                    lda       w6                  ;R POINTER
                    add       #ND-1
                    sta       w6                  ;R = R + ND-1
                    ldx       w1
                    decx                          ;P = P + 1
                    bne       Loop@@              ;IF NOT ZERO GOTO NEXT P
                    ldx       #r
                    rts

;*******************************************************************************
; Division of BCD numbers.
;
; R <- P / Q, remainder in tmp.
; on exit X = #R, tmq used.
;*******************************************************************************

DIV                 proc
                    ldx       #r                  ;CLEAR
                    bsr       CLRAS               ;RESULT
                    ldx       #p                  ;TRANSFER
                    stx       num1                ;P TO
                    ldx       #tmp                ;WORKING
                    jsr       TRA                 ;P (tmp)
                    ldx       #q                  ;TRANSFER
                    stx       num1                ;Q TO
                    ldx       #tmq                ;WORKING
                    jsr       TRA                 ;Q (tmq)
                    lda       #ND                 ;NUMBER
                    sta       count               ;DIGITS
Loop@@              ldx       #tmq                ;FIND LEAST SIGNIFICANT
                    lda       ,x                  ;NON-ZERO DIGIT
                    bne       Nosh@@              ;ZERO ?
                    bsr       SHIFT               ;YES, SHIFT Q
                    bne       Loop@@              ;UP ONE PLACE
                    bra       Done@@              ;Q WAS ZERO

Nosh@@              lda       count               ;SAVE
                    sta       w1                  ;No. DIDITS - No. SHIFTS
SubQ@@              ldx       #tmp                ;SUBTRACT Q
                    stx       num1                ;FROM
                    jsr       SUB                 ;P
                    lda       carry               ;TOO FAR ?
                    beq       NextD@@             ;IF YES, GO TO NEXT DIGIT
                    ldx       w1                  ;INCREMENT RELEVANT
                    inc       r-1,x               ;DIGIT IN RESULT
                    bra       SubQ@@              ;ONCE AGAIN

NextD@@             ldx       #tmp                ;TOO FAR, ADD
                    jsr       ADD                 ;Q BACK ON
                    ldx       #tmq                ;SET UP TO
                    lda       #ND-1               ;SHIFT BACK
                    sta       count               ;WORKING Q
_@@                 lda       ND-2,x              ;MOVE ALL
                    sta       ND-1,x              ;DIGITS
                    decx                          ;DOWN
                    dec       count               ;ONE PLACE
                    bne       _@@                 ;DONE ?
                    clr       ND-1,x              ;CLEAR MS DIGIT
                    inc       w1                  ;INCREMENT POINTER
                    lda       w1
                    cmpa      #ND+1               ;FINISHED ?
                    bne       SubQ@@              ;NO, NEXT DIGIT
Done@@              ldx       #r
                    rts

;*******************************************************************************

SHIFT               proc
                    sta       w3
                    bsr       DR1                 ;w1: MSD, w2: LSD
                    ldx       w1
Loop@@              lda       1,x                 ;MOVE ALL DIGITS
                    sta       ,x                  ;UP ONE PLACE
                    incx
                    cpx       w2
                    bne       Loop@@              ;DONE ?
                    lda       w3                  ;YES, RECOVER NEW DIGIT
                    sta       ,x                  ;AND PUT IT IN LSD
                    dec       count
                    rts

;*******************************************************************************

DR1                 proc
                    stx       w1                  ;STORE POINTERS
                    lda       #ND-1               ;(USED IN DIGIT AND DQ)
Loop@@              incx
                    deca
                    bne       Loop@@
                    stx       w2
                    rts

;*******************************************************************************
; Clear.
;*******************************************************************************

CLQ                 proc
                    ldx       #q                  ;CLEAR Q
;                   bra       CLRAS

;*******************************************************************************

CLRAS               proc
                    stx       w5
                    lda       #ND                 ;CLEAR No. DIGITS
                    sta       count               ;STARTING AT X
Loop@@              clr       ,x
                    incx
                    dec       count
                    bne       Loop@@              ;DONE ?
                    ldx       w5
                    rts

;*******************************************************************************
; mjd - day of week and year.
;
; dow = (mjd+2)MOD7 (= WD-1) (dow)
; Y' = INT((mjd-15078.2)/3652500) (year)
;*******************************************************************************

MJDC                proc
                    ldx       #mjd
                    stx       num1
                    ldx       #p
                    jsr       TRA                 ;P <- MTD
                    ldx       #mjd
                    jsr       T10K                ;mjd <- mjd TIMES 10,000
                    ldx       #p-ND
                    jsr       ADD1                ;P <- mjd + 1
                    ldx       #p-ND
                    jsr       ADD1                ;P <- mjd + 2
                    ldx       #q
                    bsr       CLRAS
                    lda       #7
                    sta       q+ND-1              ;Q <- 7
                    jsr       DIV                 ;R <- (mjd+2)/7
                    lda       tmp+ND-1            ;REMAINDER (WD-1) IN tmp
                    sta       dow
          ;-------------------------------------- ;YEAR
                    ldx       #mjd
                    stx       num1
                    ldx       #q
                    stx       num2
                    jsr       TRCY                ;Q <- CY (150782000)
                    ldx       #p
                    jsr       SUB                 ;P <- 10K(mjd-15078.2)
                    jsr       TRDY                ;Q <- 3652500
                    jsr       DIV                 ;R <- Y' ((mjd-15078.2)/365.25)
                    stx       num1
                    ldx       #year
                    jsr       TRA                 ;year <- Y'

;*******************************************************************************
; mjd - month and day.
;
; M'= INT((mjd-14956.1-INT(Y'*365.25))/306001) (P)
; D = mjd-14956-INT(Y'*365.25)-INT(M'*30.6001) (Q(x10K))
;*******************************************************************************

MONTH               proc
                    jsr       INT                 ;R <- 10K(INT(Y'*365.25))
                    ldx       #mjd
                    stx       num1
                    ldx       #p
                    stx       num2
                    jsr       TRDO1               ;P <- 149561000
                    ldx       #q
                    jsr       SUB                 ;Q <- 10K(mjd-14956.1)
                    stx       num1
                    ldx       #r
                    stx       num2
                    ldx       #p
                    jsr       SUB                 ;P <- 10K(mjd-14956.1-INT(Y'*365.25))
                    jsr       TRDM                ;Q <- 306001
                    jsr       DIV                 ;R <- M' ( mjd-14956.1-INT(Y'*365.25) )
                    stx       num1                ;INT ( --------------------------)
                    ldx       #p                  ;( 306001 )
                    jsr       TRA                 ;P <- M'
                    lda       p+ND-2              ;SAVE M'
                    sta       month
                    lda       p+ND-1
                    sta       month+1
DAY                 jsr       TRDM                ;Q <- 306001
                    bsr       MULTI               ;R <- 10K(INT(M'*30.6001))
                    stx       num1
                    ldx       #tmq
                    jsr       TRA                 ;tmq <- 10K(INT(M'*30.6001))
                    bsr       INT                 ;R <- 10K(INT(Y'*365.25))
                    stx       num2
                    ldx       #tmq
                    stx       num1
                    jsr       ADD                 ;tmq <- 10K(INT(Y'*365.25)+INT(M'*30.6001))
                    stx       num1
                    ldx       #p
                    stx       num2
                    jsr       TRDO1               ;P <- 149561000
                    clr       p+ND-4              ;P <- 149560000
                    ldx       #r
                    jsr       ADD                 ;R <- 10K(14956+INT(Y'*365.25)+INT(M'*30.6001))
                    stx       num2
                    ldx       #mjd
                    stx       num1
                    ldx       #q
                    jsr       SUB                 ;Q <- mjd-R (10K*dom)
                    lda       ND-5,x
                    sta       dom+1               ;mjd-14956-INT(Y'*365.25)-INT(M'*30.6001)
                    lda       ND-6,x
                    sta       dom

;*******************************************************************************
; mjd - final correction of year & month and subs.
;
; If M' = 14 or 15, then K = 1, else K = 0
; Y = Y' + K
; M = M' - 1 - K*12
;*******************************************************************************

ADJU2               proc
                    lda       month               ;MONTH, MSD
                    beq       _2@@                ;0 ?
                    lda       month+1             ;NO, M'= 10 THRU 15
                    beq       _1@@                ;0 ?
                    cmpa      #4                  ;NO, M'= 11 THRU 15
                    blo       _2@@                ;LESS THAN 14
                    ldx       #year-ND            ;NO, M'= 14 OR 15, K=1
                    jsr       ADD1                ;Y <- Y'+1
                    clr       month               ;MONTH, MSD (-10)
                    dec       month+1             ;DEC. MONTH
                    dec       month+1             ;AND AGAIN (-2)
                    bra       _2@@                ;-12

_1@@                lda       #10                 ;M'= 10
                    sta       month+1             ;PUT 10 IN LSD
                    clr       month               ;CLEAR MSD
_2@@                dec       month+1             ;9<-10, 1,2<-14,15, 3-8<-4-9, 10-12<-11-13
                    rts

;*******************************************************************************

INT                 proc
                    ldx       #year
                    stx       num1
                    ldx       #p
                    jsr       TRA                 ;P <- Y'
                    bsr       TRDY                ;Q <- 10K*365.25
;                   bra       MULTI

;*******************************************************************************

MULTI               proc
                    jsr       MULT                ;R <- 10K*Y'*365.25
                    clr       r+ND-4
                    clr       r+ND-3
                    clr       r+ND-2
                    clr       r+ND-1              ;R <- 10K(INT(Y'*365.25))
                    rts

;*******************************************************************************

T10K                proc
                    txa                           ;TIMES 10,000
                    add       #ND-4
                    sta       w1
Loop@@              lda       4,x
                    sta       ,x
                    incx
                    cpx       w1
                    bne       Loop@@
                    clr       ,x
                    clr       1,x
                    clr       2,x
                    clr       3,x
                    rts

;*******************************************************************************
; MJD constants.
;*******************************************************************************

TRCY                proc
                    ldx       #ND
Loop@@              lda       CY-1,x
                    sta       q-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

TRDY                proc
                    ldx       #ND
Loop@@              lda       DY-1,x
                    sta       q-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

TRDM                proc
                    ldx       #ND
Loop@@              lda       DM-1,x
                    sta       q-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

TRDO1               proc
                    ldx       #ND
Loop@@              lda       DO1-1,x
                    sta       p-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

CY                  fcb       1,5,0,7,8,2,0,0,0
DY                  fcb       0,0,3,6,5,2,5,0,0
DO1                 fcb       1,4,9,5,6,1,0,0,0
DM                  fcb       0,0,0,3,0,6,0,0,1

;*******************************************************************************
                    #VECTORS  $FFF4
;*******************************************************************************

                    fdb       Start               ;SERIAL
                    fdb       TIM_Handler         ;TIMER B
                    fdb       Start               ;TIMER A
                    fdb       IRQ_Handler         ;EXTERNAL INTERRUPT & RTI
                    fdb       Start               ;SWI
                    fdb       Start               ;RESET

                    end
