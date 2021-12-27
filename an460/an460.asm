;*******************************************************************************
; HC05E0 RDS Decoder.
; P. Topping 29th February '92
;*******************************************************************************

PORTA               equ       $00                 ;PORT A ADDRESS
PORTB               equ       $01                 ;" B "
PORTC               equ       $02                 ;" C "
PORTD               equ       $03                 ;" D "
PORTE               equ       $04                 ;" E "
PORTAD              equ       $05                 ;PORT A DATA DIRECTION REG.
PORTBD              equ       $06                 ;" B " " "
PORTCD              equ       $07                 ;" C " " "
PORTDD              equ       $08                 ;" D " " "
PORTED              equ       $09                 ;" E " " "
TAP                 equ       $0A                 ;TIMER A PRE-SCALLER
TBS                 equ       $0B                 ;TIMER B SCALLER
TCR                 equ       $0C                 ;TIMER CONTROL REGISTER
ICR                 equ       $0E                 ;INTERRUPT CONTROL REGISTER
PORTDSF             equ       $12                 ;PORTD SPECIAL FUNCTIONS
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
IO_LINE             pin       PORTD,5             ;I/O line
DATA_PIN            pin       PORTB,1
DATA_CLK            pin       PORTB,0
ALARM_SLEEP         pin       PORTE,0

;*******************************************************************************
                    #RAM      $0030
;*******************************************************************************

Q                   rmb       9                   ;BCD WORKING NUMBERS
TMQ                 rmb       9                   ;SCRATCH
P                   rmb       9                   ;WORKING NUMBER 2
TMP                 rmb       9                   ;MULT. OVER. OR DIV. REMAINDER
R                   rmb       9                   ;WORKING NUMBER 3
MJD                 rmb       9                   ;MODIFIED JULIAN DAY NUMBER
YR                  rmb       9                   ;YEAR
MNTH                rmb       2                   ;MONTH
DOM                 rmb       2                   ;DATE
DOW                 rmb       1                   ;DAY OF WEEK
BMJD                rmb       3                   ;BINARY MJD
DIST                rmb       1                   ;DISPLAY TRANSIENT TIMEOUT COUNTER
SLEPT               rmb       1                   ;SLEEP TIMER MINUTES COUNTER
RDSTO               rmb       1                   ;RDS TIMEOUT COUNTER
DAT                 rmb       4                   ;SERIAL DATA BUFFER
TMPGRP              rmb       8                   ;TEMPORARY GROUP DATA
GROUP               rmb       8                   ;COMPLETE GROUP DATA
PTY                 rmb       1                   ;PROGRAM-TYPE CODE (CURRENT)
PI                  rmb       2                   ;PROGRAM IDENTIFICATION CODE
PIN                 rmb       2                   ;PROGRAM ITEM NUMBER
LEV                 rmb       1                   ;VALID BLOCK LEVEL
BIT                 rmb       1                   ;BIT LEVEL
ITMP1               rmb       1                   ;TEMP BYTE FOR USE IN IRQ
SYN                 rmb       2                   ;SYNDROME
CONF                rmb       1                   ;SYNDROME CONFIDENCE
TH8                 rmb       1                   ;TICS (EIGHTHS OF SECONDS)
SEC                 rmb       1                   ;SECONDS
MIN                 rmb       1                   ;MINUTES
OUR                 rmb       1                   ;HOURS
AMIN                rmb       1                   ;ALARM MINUTES
AOUR                rmb       1                   ;ALARM HOURS
DISP1               rmb       1                   ;RT DISPLAY POINTER #1
DISP2               rmb       1                   ;RT DISPLAY POINTER #2
W1                  rmb       1                   ;W
W2                  rmb       1                   ;O
W3                  rmb       1                   ;R
W4                  rmb       1                   ;K
W5                  rmb       1                   ;I
W6                  rmb       1                   ;N
W7                  rmb       1                   ;G
W8                  rmb       1
KEY                 rmb       1                   ;CODE OF PRESSED KEY
KOUNT               rmb       1                   ;KEYBOARD COUNTER
CARRY               rmb       1                   ;BCD CARRY
COUNT               rmb       1                   ;LOOP COUNTER
NUM1                rmb       1                   ;1ST No. POINTER (ADD & SUBTRACT)
NUM2                rmb       1                   ;2ND No. POINTER (ADD & SUBTRACT)
RTDIS               rmb       1                   ;RDS DISPLAY TYPE
DI                  rmb       1                   ;DECODER IDENTIFICATION
DISP                rmb       16                  ;LCD MODULE BUFFER
PSN                 rmb       8                   ;PS NAME
STAT2               rmb       1                   ;0: VALID SYNDROME
                                                  ;1: VALID GROUP
                                                  ;2: RT DISPLAY
                                                  ;3: UPDATE DISPLAY
                                                  ;4: CLEAR DISPLAY
                                                  ;5: SPACE FLAG
STAT3               rmb       1                   ;0: M/S, 0: M, 1: S
                                                  ;1: TEXTA/TEXTB BIT (RT)
                                                  ;2: TA FLAG
                                                  ;3: TP FLAG
                                                  ;4: KEY REPEATING
                                                  ;5: KEY FUNCTION PERFORMED
                                                  ;6: UPDATE DATE
STAT4               rmb       1                   ;0: DISPLAY TRANSIENT
                                                  ;1: SLEEP TIMER RUNNING
                                                  ;2: SLEEP DISPLAY
                                                  ;3: ALARM DISPLAY
                                                  ;4: ALARM ARMED
                                                  ;5: ALARM SET-UP
                                                  ;6: ALARM HOURS (SET-UP)
                                                  ;7: RDS DISPLAYS
                    rmb       33                  ;not used
STACK               rmb       18                  ;19 BYTES USED (1 INTERRUPT
                    rmb       1                   ;AND 7 NESTED SUBROUTINES)

;*******************************************************************************
                    #XRAM     $0100
;*******************************************************************************

RT                  rmb       69                  ;RADIOTEXT
EON                 rmb       176                 ;EON DATA (MAX: 11 NETWORKS)

;*******************************************************************************
                    #ROM      $E000
;*******************************************************************************

;STRST              jmp       Start               ;RESET VECTOR ($0400 DURING DEBUG)
;IRQ                jmp       SDATA               ;IRQ ($0403 DURING DEBUG)
;TIMERA             jmp       Start               ;TIMER A INTERRUPT (NOT USED, $0406 DURING DEBUG)
;TIMERB             jmp       TINTB               ;TIMER B INTERRUPT ($0409 DURING DEBUG)
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
                    lda       #$FF                ;E0BUG DISPLAY/KEYBOARD I/O
                    sta       PORTAD              ;NOT USED IN RDS APPLICATION
                    clr       PORTB               ;0, 1: SERIAL CLOCK AND DATA
                    lda       #$CB                ;2: RDS DATA IN, 3: VFD SELECT
                    sta       PORTBD              ;4, 5: KEYBOARD IN, 6, 7: KEYBOARD OUT
                    clr       PORTC
                    lda       #$FF                ;ALL OUT, LCD DATA BUS
                    sta       PORTCD
                    lda       #$3C                ;BITS 2, 3 & 4 OUT, LCD
                    clr       PORTD               ;2: RS, 3: R/W, 4: CLOCK, 5: LED (TA=TP=1)
                    sta       PORTDD              ;0, 1, 6 & 7 USED DURING DEBUG
                    lda       #$0C                ;BIT0: INPUT, ENABLE SLEEP TIMER AT ALARM TIME
                    sta       PORTE               ;BIT1: INPUT, ENABLE ALARM OUTPUT
;                   lda       #$0C                ;BIT2: ALARM OUTPUT (ACTIVE LOW)
                    sta       PORTED              ;BIT3: RADIO ON OUTPUT (ACTIVE HIGH)
          ;-------------------------------------- ;Initialise LCD
                    lda       #$30
                    jsr       CLOCK               ;INITIALISE LCD
                    jsr       CLREON              ;CLEAR EON DATA
                    jsr       CLREON
                    jsr       CLREON              ;4 TIMES TO PROVIDE A 5mS DELAY
                    jsr       CLREON              ;FOR LCD MODULE INITIALISATION
                    lda       #$30
                    jsr       CLOCK               ;INITIALISE LCD
                    ldx       #Q                  ;INITIALISE RAM
Loop@@              clr       ,x
                    incx                          ;PROVIDES A 1mS DELAY FOR LCD
                    cpx       #STACK
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
                    brclr     0,STAT4,_1@@        ;DISPLAY TRANSIENT ?
                    lda       DIST
                    bne       _1@@                ;YES, TIMED OUT ?
                    jsr       CLTR                ;YES, CLEAR TRANSIENT DISPLAYS
_1@@                brclr     3,STAT2,Scan@@      ;DISPLAY UPDATE REQUIRED ?
                    jsr       MOD                 ;YES, DO IT
                    bclr      3,STAT2             ;AND CLEAR FLAG
Scan@@              brclr     4,STAT4,_3@@        ;ALARM ARMED ?
                    lda       AOUR                ;YES, COMPARE ALARM HOURS
                    cmpa      OUR                 ;WITH TIME
                    bne       _3@@                ;SAME ?
                    lda       AMIN                ;YES, COMPARE ALARM MINUTES
                    cmpa      MIN                 ;WITH TIME
                    bne       _3@@                ;SAME ?
                    lda       SEC                 ;ONLY ALLOW WAKE-UP IN FIRST SECOND
                    bne       _3@@                ;TO PREVENT SWITCH-OFF LOCKOUT
                    bset      SWITCH              ;YES, SWITCH ON
                    brset     ALARM_SWITCH,_2@@   ;ALARM ENABLED (SWITCH) ?
                    bclr      ALARM_BUZZER        ;YES, SOUND ALARM
_2@@                brset     ALARM_SLEEP,_3@@    ;SLEEP TIMER AT ALARM TIME ?
                    jsr       INSLP               ;YES, START SLEEP TIMER
_3@@                brclr     1,STAT4,_4@@        ;SLEEP TIMER RUNNING ?
                    lda       SLEPT               ;YES
                    bne       _4@@                ;TIME TO FINISH ?
                    bclr      1,STAT4             ;YES, CLEAR FLAG
                    bclr      SWITCH              ;AND SWITCH OFF
_4@@                bsr       KBD                 ;READ KEYBOARD
                    jsr       KEYP                ;EXECUTE KEY
                    lda       STAT3
                    and       #$0C
                    cbeqa     #$0C,_5@@           ;TA AND TP BOTH HIGH ?
                    brset     IO_LINE,_6@@        ;NO, I/O LINE ALREADY HIGH ?
                    bset      IO_LINE             ;NO, MAKE IT HIGH
                    bra       _6@@

_5@@                brclr     IO_LINE,_6@@        ;TA=TP=1, I/O LINE ALREADY LOW ?
                    bclr      IO_LINE             ;NO, MAKE IT LOW
_6@@                brclr     6,STAT3,Cont@@      ;UPDATE DATE ?
                    bsr       MJDAT               ;YES, CONVERT FROM MJD
Cont@@              bra       Idle@@

;*******************************************************************************
; Extract MJD and convert to decimal.
;*******************************************************************************

MJDAT               proc
                    lda       BMJD+2
                    sta       YR+2
                    lda       BMJD+1
                    sta       YR+1
                    lda       BMJD
                    sta       YR
                    ldx       #R                  ;CLEAR
                    stx       NUM1
                    jsr       CLRAS               ;R
                    inc       R+ND-1              ;R <- 1
                    ldx       #MJD
                    jsr       CLRAS               ;CLEAR MJD
                    lda       #17                 ;17 BITS TO CONVERT
                    sta       W6
LooP@@              lsr       YR                  ;MOVE OUT
                    ror       YR+1
                    ror       YR+2                ;FIRST (LS) BIT
                    bcc       Cont@@              ;ZERO ?
                    ldx       #MJD                ;ONE, ADD
                    stx       NUM2                ;CURRENT VALUE
                    jsr       ADD                 ;OF R
Cont@@              ldx       #R                  ;ADD R
                    stx       NUM2                ;TO
                    jsr       ADD                 ;ITSELF
                    dbnz      W6,LooP@@           ;ALL DONE ?
                    bclr      6,STAT3             ;MJD UPDATED
                    jmp       MJDC                ;CONVERT MJD TO DAY, DATE, MONTH & YEAR

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
                    decx                          ;NO, TRY NEXT COLUMN
                    bne       _1@@                ;LAST COLUMN ?
                    clr       KEY                 ;YES, NO KEY PRESSED
                    bra       Exit@@

_2@@                lda       PORTB               ;READ KEYBOARD
                    and       #$F0
                    cbeq      KEY,Exit@@          ;SAME AS LAST TIME ?
                    sta       KEY                 ;NO, SAVE THIS KEY
                    clr       KOUNT
Exit@@              inc       KOUNT               ;YES, THE SAME
                    lda       KOUNT
                    brclr     4,STAT3,Normal@@    ;REPEATING ?
                    cmpa      #10                 ;YES, REPEAT AT 6 Hz
                    bra       _3@@

Normal@@            cmpa      #3                  ;NO, 3 THE SAME ?
                    blo       Done@@              ;IF NOT DO NOTHING
                    beq       _6@@                ;IF 3 THEN PERFORM KEY FUNCTION
                    cmpa      #48                 ;MORE THAN 3, MORE THAN 48 (750mS) ?
_3@@                bhi       _4@@                ;TIME TO DO SOMETHING ?
                    lda       KEY                 ;NO
                    beq       _7@@                ;KEY PRESSED ?
                    clc
                    rts                           ;YES BUT DO NOTHING

_4@@                lda       KEY
                    cbeqa     #$50,_5@@           ;SLEEP (DEC.)
                    cmpa      #$90                ;RDS (INC.)
                    bne       _8@@                ;IF NOT A REPEAT KEY, DO NOTHING
_5@@                brclr     5,STAT4,_8@@        ;REPEAT KEY, BUT IS MODE ALARM SET-UP ?
                    bset      4,STAT3             ;YES, SET REPEAT FLAG
                    clr       KOUNT
_6@@                lda       KEY
                    beq       _7@@                ;SOMETHING TO DO ?
                    sec                           ;YES, SET C
                    rts

_7@@                bclr      5,STAT3             ;NO, CLEAR DONE FLAG
_8@@                bclr      4,STAT3             ;CLEAR REPEAT FLAG
                    clr       KOUNT               ;CLEAR COUNTER
Done@@              clc
                    rts

;*******************************************************************************
; Execute key function.
;*******************************************************************************

KEYP                proc
                    bcc       Done@@              ;ANYTHING TO DO ?
                    lda       KEY                 ;YES, GET KEY
                    cbeqa     #$50,_@@            ;SLEEP (DEC.)
                    cbeqa     #$90,_@@            ;RDS (INC.)
                    brset     5,STAT3,Done@@      ;NOT A REPEAT KEY, DONE FLAG SET ?
_@@                 clrx
Loop@@              lda       CTAB,x              ;FETCH KEYCODE
                    cbeq      KEY,_1@@            ;THIS ONE ? YES
                    cmpa      LAST
                    beq       Done@@              ;NO, LAST CHANCE ? YES, ABORT
                    incx:4                        ;NO, TRY THE NEXT KEY
                    bra       Loop@@

_1@@                bset      5,STAT3             ;KEY FUNCTION DONE
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
                    brclr     3,STAT4,On@@        ;NO, ALARM DISPLAY ON ?
                    brclr     4,STAT4,Off@@       ;YES, ALARM ON ?
                    bclr      4,STAT4             ;YES, SWITCH OFF
                    bra       UdCnt@@

Off@@               bset      4,STAT4             ;NO, SWITCH ON
                    bra       UdCnt@@

On@@                jsr       CLTR
                    bset      3,STAT4             ;ALARM DISPLAY FLAG
UdCnt@@             bclr      5,STAT4             ;CANCEL SET-UP
                    lda       #25                 ;3 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ;SET DISPLAY TRANSIENT FLAG
                    rts

;*******************************************************************************
; On/off key (alarm set-up).
;*******************************************************************************

ONOFF               proc
                    brclr     ALARM_BUZZER,CancelAlarm ;ALARM RINGING ?
                    brclr     3,STAT4,NOTALR      ;NO, ALARM DISPLAY ?
                    brclr     4,STAT4,NOTALR      ;YES, ALARM ARMED ?
                    brset     5,STAT4,InSetup@@   ;YES, ALREADY SET-UP MODE ?
                    bset      5,STAT4             ;NO, ENTER SET-UP MODE
                    bset      6,STAT4             ;WITH HOURS
Loop@@              lda       #80
                    sta       DIST
                    bset      0,STAT4             ;SET DISPLAY TRANSIENT FLAG
                    rts

InSetup@@           brset     6,STAT4,Mins@@      ;SET-UP HOURS ?
                    bclr      5,STAT4             ;NO, CANCELL SET-UP
                    bra       Loop@@

Mins@@              bclr      6,STAT4             ;YES, MAKE IT MINUTES
                    bra       Loop@@

;*******************************************************************************
; On/off key (normal function).
;*******************************************************************************

NOTALR              proc
                    jsr       CLTR                ;CLEAR DISPLAY TRANSIENTS
                    bclr      1,STAT4             ;CANCEL SLEEP TIMER
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
                    brclr     5,STAT4,_1@@        ;NO, ALARM SET-UP ?
                    bra       PDEC                ;YES

_1@@                brset     2,STAT4,DECS        ;NO, ALREADY SLEEP DISPLAY ?
                    brset     1,STAT4,STR2        ;NO, SLEEP TIMER ALREADY RUNNING ?
;                   bra       INSLP

;*******************************************************************************

INSLP               proc
                    lda       #60                 ;NO, INITIALISE SLEEP TIMER
                    sta       SLEPT
                    bset      1,STAT4             ;START SLEEP TIMER
STR2                jsr       CLTR                ;YES, CLEAR DISPLAY TRANSIENTS
                    bset      2,STAT4             ;SLEEP DISPLAY
                    bra       SLPTOK              ;NO DECREMENT IF FIRST TIME

DECS                lda       SLEPT               ;DECREMENT SLEEP TIMER
                    sub       #5
                    sta       SLEPT
                    bmi       INSLP               ;IF UNDERFLOW WRAP ROUND TO 60
SLPTOK              lda       #25
                    sta       DIST
                    bset      0,STAT4             ;START DISPLAY TRANSIENT
                    bra       SODM

;*******************************************************************************
; RDS display key
;*******************************************************************************

RDS                 proc
                    brclr     ALARM_BUZZER,CancelAlarm ;ALARM RINGING ?
                    brset     5,STAT4,PINC        ;NO, ALARM SET-UP ?
                    brclr     SWITCH,_2@@         ;NO, STANDBY ?
                    brset     7,STAT4,_1@@        ;ALREADY RDS ?
                    brclr     2,STAT2,_3@@        ;ALREADY RT DISPLAY ?
_1@@                bset      7,STAT4             ;SET RDS DISPLAY FLAG
                    lda       RTDIS               ;MOVE ON
                    inca
                    cbeqa     #19,_3@@
                    sta       RTDIS
                    lda       #100                ;12 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ;RE-START TRANSIENT TIMEOUT
_2@@                rts

_3@@                jsr       CLTR                ;CLEAR DISPLAY TRANSIENTS
                    bset      2,STAT2             ;SET RT DISPLAY FLAG
                    lda       #9
                    sta       DISP1
                    lda       #1
                    sta       DISP2
                    rts

;*******************************************************************************
; Increment alarm time.
;*******************************************************************************

PINC                proc
                    brset     6,STAT4,_2@@        ;SET-UP HOURS ?
                    lda       AMIN                ;NO, MINUTES
                    cmpa      #59
                    bhs       _1@@
                    inc       AMIN
                    bra       _3@@

_1@@                clr       AMIN
                    bra       _3@@

_2@@                lda       AOUR
                    cmpa      #23
                    bhs       _4@@
                    inc       AOUR
_3@@                lda       #80                 ;10 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ;SET DISPLAY TRANSIENT FLAG
                    rts

_4@@                clr       AOUR
                    bra       _3@@

;*******************************************************************************
; Decrement alarm time.
;*******************************************************************************

PDEC                proc
                    brset     6,STAT4,_2@@        ;SET-UP HOURS ?
                    tst       AMIN                ;NO, MINUTES
                    beq       _1@@
                    dec       AMIN
                    bra       _3@@

_1@@                lda       #59
                    sta       AMIN
                    bra       _3@@

_2@@                tst       AOUR
                    beq       _4@@
                    dec       AOUR
_3@@                lda       #80                 ;10 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ;SET DISPLAY TRANSIENT FLAG
                    rts

_4@@                lda       #23
                    sta       AOUR
                    bra       _3@@

;*******************************************************************************
; Timer interrupt routine
;*******************************************************************************

TINTB               proc
                    inc       DISP1               ;DISP1 DISP2 DISPLAY
                    lda       DISP1               ;0 -8 0 PTY
                    cmpa      #8                  ;9 -78 1 - 70 MOVING RT
                    bls       _1@@                ;78 -88 70 END OF RT
                    cmpa      #78
                    bhi       _1@@                ;END OF RADIOTEXT ?
                    inc       DISP2               ;NO, MOVE RADIOTEXT ONE CHARACTER
_1@@                cmpa      #88                 ;2 SECONDS AT END OF RADIOTEXT
                    blo       _2@@
                    bclr      2,STAT2             ;RETURN TO NORMAL DISPLAY
_2@@                bclr      5,ICR               ;CLEAR TIMER B INTERRUPT FLAG
                    bset      3,STAT2             ;UPDATE DISPLAY
                    inc       TH8                 ;UPDATE EIGHTHS OF SECONDS
                    dec       DIST                ;DECREMENT TRANSIENT DISPLAY TIMER
                    inc       RDSTO
                    lda       RDSTO
                    cmpa      #80                 ;10S WITHOUT A GROUP 0 OR 15 ?
                    blo       RdsOk@@
                    bclr      2,STAT3             ;YES, CLEAR TA FLAG
                    clr       PTY                 ;PROGRAM TYPE
                    clr       PI                  ;AND
                    clr       PI+1                ;PI CODE
                    clr       PIN                 ;AND
                    clr       PIN+1               ;PIN
                    clr       DI                  ;AND DI
                    bclr      0,STAT3             ;AND M/S
RdsOk@@             lda       TH8                 ;EIGHTHS OF SECONDS
                    cmpa      #8
                    bne       Done@@              ;PAST 7 ?
                    clr       TH8                 ;YES, CLEAR
                    inc       SEC                 ;UPDATE SECONDS
                    lda       SEC
                    cmpa      #56
                    bne       _3@@
                    dec       SLEPT               ;DECREMENT SLEEP TIMER MINUTES
_3@@                cmpa      #60
                    bne       Done@@              ;PAST 59 ?
                    clr       SEC                 ;YES, CLEAR
                    inc       MIN                 ;UPDATE MINUTES
                    lda       MIN
                    cmpa      #60
                    bne       Done@@              ;PAST 59 ?
                    clr       MIN                 ;YES, CLEAR
                    inc       OUR                 ;UPDATE HOURS
                    lda       OUR
                    cmpa      #24
                    bne       Done@@              ;PAST 23 ?
                    clr       OUR                 ;YES CLEAR
                    inc       BMJD+2              ;AND ADD A DAY
                    bne       _4@@
                    inc       BMJD+1
                    bne       _4@@                ;INC BMJD only ever executes once, at midnight
                    inc       BMJD                ;on the night of Thu/Fri 22/23 April 2038.
_4@@                bset      6,STAT3             ;UPDATE DATE
Done@@              rti

;*******************************************************************************
; RDS clock interrupt (IRQ)
; Get a bit and calculate syndrome
;*******************************************************************************

SDATA               proc
                    brset     2,PORTB,*+3
                    rol       DAT+3
                    rol       DAT+2
                    rol       DAT+1
                    rol       DAT
                    brclr     0,STAT2,_2@@        ;BIT BY BIT CHECK ?
                    dec       BIT                 ;NO, WAIT FOR BIT 26
                    beq       _1@@                ;THIS TIME ?
                    bclr      3,ICR               ;CLEAR IRQ INTERRUPT FLAG
                    rti
          ;--------------------------------------
_1@@                lda       #26
                    sta       BIT
_2@@                lda       DAT                 ;MSB (2 BITS)
                    and       #3
                    tax
                    lda       DAT+1
                    sta       SYN+1               ;LSB
                    brclr     0,DAT+3,_3@@
                    lda       SYN+1
                    eor       #$1B
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_3@@                brclr     1,DAT+3,_4@@
                    lda       SYN+1
                    eor       #$8F
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_4@@                brclr     2,DAT+3,_5@@
                    lda       SYN+1
                    eor       #$A7
                    sta       SYN+1
                    txa
                    eor       #$02
                    tax
          ;--------------------------------------
_5@@                brclr     4,DAT+3,_6@@
                    lda       SYN+1
                    eor       #$EE
                    sta       SYN+1
                    txa
                    eor       #$01
                    tax
          ;--------------------------------------
_6@@                brclr     5,DAT+3,_7@@
                    lda       SYN+1
                    eor       #$DC
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_7@@                brclr     6,DAT+3,_8@@
                    lda       SYN+1
                    eor       #$01
                    sta       SYN+1
                    txa
                    eor       #$02
                    tax
          ;--------------------------------------
_8@@                brclr     7,DAT+3,_9@@
                    lda       SYN+1
                    eor       #$BB
                    sta       SYN+1
                    txa
                    eor       #$01
                    tax
          ;--------------------------------------
_9@@                brclr     0,DAT+2,_10@@
                    lda       SYN+1
                    eor       #$76
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_10@@               brclr     1,DAT+2,_11@@
                    lda       SYN+1
                    eor       #$55
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_11@@               brclr     2,DAT+2,_12@@
                    lda       SYN+1
                    eor       #$13
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_12@@               brclr     3,DAT+2,_13@@
                    lda       SYN+1
                    eor       #$9F
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
          ;--------------------------------------
_13@@               brclr     4,DAT+2,_14@@
                    lda       SYN+1
                    eor       #$87
                    sta       SYN+1
                    txa
                    eor       #$02
                    tax
          ;--------------------------------------
_14@@               brclr     6,DAT+2,_15@@
                    lda       SYN+1
                    eor       #$6E
                    sta       SYN+1
                    txa
                    eor       #$01
                    tax
          ;--------------------------------------
_15@@               brclr     7,DAT+2,_16@@
                    lda       SYN+1
                    eor       #$DC
                    sta       SYN+1
                    txa
                    eor       #$02
_16@@               sta       SYN
                    lda       SYN+1
                    brclr     3,DAT+3,_17@@
                    eor       #$F7
_17@@               brclr     5,DAT+2,_18@@
                    eor       #$B7
_18@@               sta       SYN+1
          ;-------------------------------------- ;Check for syndromes A, B, C & C'
                    bclr      3,ICR               ;CLEAR IRQ INTERRUPT FLAG
                    lda       LEV
                    cbeqa     #3,TRYD
                    cbeqa     #2,TryC@@
                    cbeqa     #1,TryB@@
                    clr       LEV
          ;-------------------------------------- ;TRYA
                    lda       SYN+1               ;BLOCK 1
                    cmpa      #$D8
                    bne       NotValid@@
                    lda       SYN
                    cmpa      #$03
                    bne       NotValid@@
                    bra       VALID
          ;--------------------------------------
TryB@@              lda       SYN+1               ;BLOCK 2
                    cmpa      #$D4
                    bne       NotValid@@
                    lda       SYN
                    cmpa      #$03
                    bne       NotValid@@
                    bra       VALID
          ;--------------------------------------
TryC@@              brset     3,TMPGRP+2,TryD@@   ;BLOCK 3 TYPE A
                    lda       SYN+1
                    cmpa      #$5C
                    bne       NotValid@@
                    lda       SYN
                    cmpa      #$02
                    bra       Valid@@
          ;--------------------------------------
TryD@@              lda       SYN+1               ;BLOCK 3 TYPE B
                    cmpa      #$CC
                    bne       NotValid@@
                    lda       SYN
                    cmpa      #$03
Valid@@             beq       VALID
          ;--------------------------------------
          ; Invalid syndrome handling, check for
          ; block 4 and save group data if valid.
          ;--------------------------------------
NotValid@@          clr       LEV                 ;RESTART AT BLOCK 1
                    lda       CONF
                    cmpa      #41                 ;CONFIDENCE 41 OR GREATER ?
                    bhs       DECC
                    bclr      0,STAT2             ;BIT BY BIT SYNDROME CHECK
                    cmpa      #10
                    bls       SKPDC               ;CONFIDENCE 10 OR LESS ?
                    dbnz      BIT,NNOW            ;USE BIT COUNTER TO SLOW CONFIDENCE
                    lda       #26                 ;DROP DURING BIT BY BIT ATTEMPT TO
                    sta       BIT                 ;RE-SYNCRONISE
DECC                dec       CONF
NNOW                rti

SKPDC               bset      4,STAT2             ;10 OR LESS, INITIALISE DISPLAY
NOT4                rti

TRYD                lda       SYN+1
                    cmpa      #$58
                    bne       NotValid@@
                    lda       SYN
                    cmpa      #$02
                    bne       NotValid@@
                    bset      1,STAT2             ;GROUP COMPLETE
VALID               brset     0,STAT2,VLD         ;VALID SYNDROME FLAG ALREADY SET ?
                    lda       #38                 ;NO,
                    sta       CONF                ;INITIALISE CONFIDENCE (38+4=42)
                    bset      0,STAT2             ;AND SET FLAG
VLD                 lda       CONF
                    cmpa      #56
                    bhi       NMR
                    add       #4
                    sta       CONF
NMR                 ldx       LEV
                    rolx
                    inc       LEV
                    lda       #26
                    sta       BIT
                    ror       DAT
                    ror       DAT+1
                    ror       DAT+2
                    ror       DAT
                    ror       DAT+1
                    ror       DAT+2
                    lda       DAT+2
                    sta       TMPGRP+1,x
                    lda       DAT+1
                    sta       TMPGRP,x
                    brclr     1,STAT2,NOT4        ;GROUP COMPLETE ?
XFER                ldx       #8
TXLP                lda       TMPGRP-1,x
                    sta       GROUP-1,x
                    dbnzx     TXLP
          ;--------------------------------------
          ; Update PI code, initialise if changed.
          ; All block 1s used, block 3s not used.
          ;--------------------------------------
PROC                lda       GROUP               ;COMPARE PI WITH PREVIOUS
                    cmpa      PI
                    bne       DNDX
                    lda       GROUP+1
                    cmpa      PI+1
                    beq       PTYL
DNDX                lda       GROUP               ;DIFFERENT, SAVE NEW PI
                    sta       PI
                    lda       GROUP+1
                    sta       PI+1
                    jsr       CLREON              ;CLEAR EON,
                    jsr       CLTR                ;TRANSIENTS
                    bset      4,STAT2             ;AND INITIALISE DISPLAY DATA
          ;--------------------------------------
          ; Update PTY and TP.
          ; All block 2s used, not block 4 (grp 15B).
          ;--------------------------------------
PTYL                lda       GROUP+2
                    sta       ITMP1
                    brclr     2,ITMP1,TPL1        ;TP HIGH ?
                    bset      3,STAT3             ;YES, FLAG HIGH
                    bra       TPL

TPL1                bclr      3,STAT3             ;NO, FLAG LOW
TPL                 lda       GROUP+3
                    ror       ITMP1
                    rora
                    lsra:4
                    sta       PTY
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
                    lda       GROUP+2
                    and       #$F8
                    beq       GRP0                ;GROUP 0A
                    cmpa      #$08                ;GROUP 0B
                    beq       GRP0
TGRP15              cmpa      #$F8                ;GROUP 15B
                    beq       TACK
                    bra       PROC1

GRP0                lda       GROUP+3             ;GROUP 0 -PS & TA
                    and       #$03
                    lsla
                    tax
                    lda       GROUP+6
                    sta       PSN,x
                    lda       GROUP+7
                    sta       PSN+1,x
TACK                clr       RDSTO               ;RDS OK, RESET TIME-OUT
                    brset     4,GROUP+3,TAH       ;TA HIGH ?
                    bclr      2,STAT3             ;NO, TA FLAG LOW
                    bra       NTD

TAH                 bset      2,STAT3             ;YES, TA FLAG HIGH
          ;-------------------------------------- ;Process group 0 & 15B (DI & M/S).
NTD                 lda       GROUP+3             ;DI
                    and       #3
                    tax
                    lda       GROUP+3
                    and       #$40
                    tstx
                    bne       NOT0
                    bclr      0,DI
                    tsta
                    beq       NOT0
                    bset      0,DI
NOT0                cpx       #1
                    bne       NOT1
                    bclr      1,DI
                    tsta
                    beq       NOT1
                    bset      1,DI
NOT1                cpx       #2
                    bne       NOT2
                    bclr      2,DI
                    tsta
                    beq       NOT2
                    bset      2,DI
NOT2                cpx       #3
                    bne       NOT3
                    bclr      3,DI
                    tsta
                    beq       NOT3
                    bset      3,DI
NOT3                bclr      0,STAT3             ;M/S
                    brclr     3,GROUP+3,MSZ
                    bset      0,STAT3
MSZ                 jmp       OUT1

;*******************************************************************************
; Process group 1 (PIN).
;*******************************************************************************

PROC1               proc
                    cmpa      #$10                ;GROUP 1A
                    beq       _@@
                    cmpa      #$18                ;GROUP 1B
                    bne       PROC2
_@@                 lda       GROUP+6
                    sta       PIN
                    lda       GROUP+7
                    sta       PIN+1
                    jmp       OUT1

;*******************************************************************************
; Process group 2A (RT).
; Group 2B not handled.
;*******************************************************************************

PROC2               proc
                    cmpa      #$20                ;GROUP 2A
                    bne       PROC4
                    brset     4,GROUP+3,_1@@
                    brset     1,STAT3,_3@@
                    bset      1,STAT3
                    bra       _2@@

_1@@                brclr     1,STAT3,_3@@
                    bclr      1,STAT3
_2@@                jsr       INITD
_3@@                lda       GROUP+3             ;GROUP 2A -RT
                    and       #$0F
                    lsla:2
                    tax
                    lda       GROUP+4
                    sta       RT+5,x
                    lda       GROUP+5
                    sta       RT+6,x
                    lda       GROUP+6
                    sta       RT+7,x
                    lda       GROUP+7
                    sta       RT+8,x
                    jmp       OUT1

;*******************************************************************************
; Process group 4A (CT)
;*******************************************************************************

PROC4               proc
                    cmpa      #$40                ;GROUP 4A -CT
                    jne       PROC14

                    lda       GROUP+3
                    rora
                    and       #$01
                    sta       BMJD                ;MJD MS BIT
                    lda       GROUP+4
                    rora
                    sta       BMJD+1              ;MJD MSD
                    lda       GROUP+6             ;GROUP 4
                    ror       GROUP+5             ;3210xxxx 4
                    rora                          ;43210xxx x
                    lsra:3                        ;-43210xx x
                                                  ;--43210x x
                                                  ;---43210 x
                    sta       OUR
                    lda       GROUP+5
                    sta       BMJD+2              ;MJD LSD
                    lda       GROUP+6             ;xxxx5432 x
                    lsl       GROUP+7             ;xxxx5432 1
                    rola                          ;xxx54321 x
                    lsl       GROUP+7             ;xxx54321 0
                    rola                          ;xx543210 x
                    and       #$3F                ;--543210 x
                    sta       MIN
                    clr       SEC
                    clr       TH8
                    bset      6,STAT3             ;UPDATE MJD
          ;-------------------------------------- ;Local time difference adjustment.
LOCAL               lda       GROUP+7
                    lsla
                    beq       OUT1                ;ADJUSTMENT ?
                    bcc       POS                 ;YES, POSITIVE ?
NEG                 lsra:4                        ;NO, NEGATIVE
                    tax                           ;HOURS IN X
                    bcc       NOTHN               ;1/2 HOUR ?
                    lda       MIN                 ;YES
                    sub       #30                 ;SUBTRACT 30 MINUTES
                    bpl       LT60                ;UNDERFLOW ?
                    add       #60                 ;YES, ADD 60 MINUTES
                    dec       OUR                 ;AND SUBTRACT 1 HOUR
LT60                sta       MIN
NOTHN               txa                           ;NEGATIVE HOUR OFFSET
                    sub       OUR                 ;MINUS UTC HOURS
                    coma                          ;WRONG WAY ROUND SO COMPLEMENT
                    inca                          ;AND INCREMENT
                    bpl       ZOM                 ;UNDERFLOW ?
                    add       #24                 ;YES, ADD 24 HOURS
                    sta       OUR
                    tst       BMJD+2              ;AND SUBTRACT A DAY
                    bne       TT2                 ;LSB WILL UNDERFLOW ?
                    tst       BMJD+1              ;YES
                    bne       TT1                 ;MSB WILL UNDERFLOW ?
                    dec       BMJD                ;YES DECREMENT MS BIT
TT1                 dec       BMJD+1              ;DECREMENT MSB
TT2                 dec       BMJD+2              ;DECREMENT LSB
                    bra       OUT1

ZOM                 sta       OUR
                    bra       OUT1

POS                 lsra:4                        ;POSITIVE ADJUSTMENT
                    tax                           ;HOURS IN X
                    bcc       NOTHP               ;HALF HOUR ?
                    lda       #30                 ;YES, ADD 30 MINUTES
                    add       MIN
                    cmpa      #59
                    bls       HDON                ;OVERFLOW ?
                    sub       #60                 ;YES, SUBTRACT 60 MINUTES
                    inc       OUR                 ;AND ADD AN HOUR
HDON                sta       MIN
NOTHP               txa                           ;HOUR OFFSET
                    add       OUR                 ;ADD UTC HOURS
                    cmpa      #23
                    bls       ADDON               ;OVERFLOW ?
                    sub       #24                 ;YES, SUBTRACT 24 HOURS
                    inc       BMJD+2              ;AND ADD A DAY
                    bne       ADDON
                    inc       BMJD+1
                    bne       ADDON
                    inc       BMJD
ADDON               sta       OUR
OUT1                bclr      1,STAT2             ;GROUP HANDLED, CLEAR FLAG
                    rti

;*******************************************************************************
; Process group 14 (EON)
;*******************************************************************************

PROC14              proc
                    cmpa      #$E0
                    beq       GRP14A
                    jmp       OUT2

GRP14A              clr       ITMP1               ;LOOK FOR PI CODE IN TABLE
LPIL                ldx       ITMP1
                    lda       EON,x
                    cmpa      GROUP+6
                    bne       NOTH
                    lda       EON+1,x
                    cmpa      GROUP+7
                    bne       NOTH
;                   lda       GROUP+3             ;TP (ON), NOT USED
;                   and       #$10
;                   ldx       ITMP1
;                   sta       EON+11,x
                    lda       GROUP+3             ;PI CODE FOUND
                    and       #$0F
                    cmpa      #4                  ;PS ?
                    bhs       NPS
                    lsla                          ;YES
                    add       ITMP1
                    tax
                    lda       GROUP+4
                    sta       EON+2,x             ;SAVE 2 PS-NAME CHARACTERS
                    lda       GROUP+5
                    sta       EON+3,x
                    bra       OUT1

NPS                 cmpa      #4                  ;AF ?
                    bne       TRYPIN
                    lda       GROUP+4             ;YES, METHOD A
                    cmpa      #250
                    bne       NMLW                ;MEDIUM OR LONG WAVE ?
                    lda       EON+12,x            ;YES
                    cmpa      #$FF                ;FIRST 2 BYTES ALREADY IN ?
                    beq       OUT2                ;IF NOT, DO NOTHING
                    lda       EON+14,x            ;YES
                    cmpa      #$FF                ;M/L FREQUENCY ALREADY IN ?
                    bne       OUT2                ;IF SO, DO NOTHING
                    lda       #250                ;NO, STORE FIRST FREQUENCY AFTER
                    sta       EON+14,x            ;ARRIVAL OF INITIAL BYTES
                    lda       GROUP+5
                    sta       EON+15,x
                    bra       OUT2

NMLW                cmpa      #224                ;FM
                    blo       TOOLS               ;LEGAL ? (No. OF FREQUENCIES)
                    cmpa      #249
                    bhi       TOOLS
                    ldx       ITMP1
                    sta       EON+12,x            ;YES, SAVE No. OF FREQUENCIES
                    lda       GROUP+5
                    sta       EON+13,x            ;AND FIRST FREQUENCY
TOOLS               bra       OUT2

;TRYPTY             cmpa      #$0D
;                   bne       TRYPIN
;                   lda       GROUP+4             ;PTY (EON), NOT USED
;                   lsra:3
;                   ldx       ITMP1
;                   sta       EON+10,x
;                   bra       OUT2
TRYPIN              cmpa      #$0E
                    bne       OUT2
                    ldx       ITMP1               ;PIN
                    lda       GROUP+4
                    sta       EON+10,x
                    lda       GROUP+5
                    sta       EON+11,x
                    bra       OUT2

NOTH                cmpa      #$FF                ;END OF PI LIST ?
                    bne       NOTH1
                    lda       GROUP+6             ;YES, ADD THIS PI CODE
                    sta       EON,x
                    lda       GROUP+7             ;TO EON TABLE
                    sta       EON+1,x
                    bra       OUT2

NOTH1               lda       ITMP1               ;NOT END, TRY NEXT ENTRY
                    add       #16
                    sta       ITMP1
                    cmpa      #$B0                ;END OF TABLE (11 ENTRIES) ?
                    beq       OUT2
                    jmp       LPIL

OUT2                bclr      1,STAT2             ;GROUP HANDLED, CLEAR FLAG
                    rti

;*******************************************************************************
; Display type selection
;*******************************************************************************

MOD                 proc
                    brclr     4,STAT2,_1@@        ;SHOULD DISPALY BE INITIALISED ?
                    jsr       INITD               ;YES, DO IT
                    bclr      4,STAT2             ;AND CLEAR FLAG
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
                    brset     2,STAT4,_11@@       ;YES, SLEEP DISPLAY ?
                    brset     3,STAT4,_13@@       ;NO, ALARM DISPLAY ?
                    jsr       STBYD               ;NO, NORMAL STANDBY DISPLAY
                    bra       _14@@
          ;--------------------------------------
_2@@                brclr     7,STAT4,_10@@       ;RDS DISPLAYS ?
                    lda       RTDIS
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
                    jsr       DMJD                ;MJD
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
_10@@               brclr     2,STAT2,_11@@       ;RT DISPLAY ?
                    jsr       RTDS
                    bra       _14@@
          ;--------------------------------------
_11@@               brclr     2,STAT4,_12@@       ;SLEEP TIMER DISPLAY ?
                    jsr       SLEEPD
                    bra       _14@@
          ;--------------------------------------
_12@@               brset     3,STAT4,_13@@       ;ALARM DISPLAY ?
                    jsr       NORMD
                    bra       _14@@
          ;--------------------------------------
_13@@               jsr       ALRMD
_14@@               clrx
Loop@@              jsr       WAIT
                    bset      LCD_DATA            ;WRITE DATA
                    lda       DISP,x              ;GET A BYTE
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
                    lda       DISP+8,x            ;GET A BYTE
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
                    bclr      DATA_PIN            ;DATA LOW ?
                    bset      DATA_CLK            ;CLOCK HIGH ?
                    bclr      3,PORTB             ;ENABLE LOW
                    clrx                          ;SEND VFD SET-UP BYTES
_1@@                lda       InitF@@,x
                    stx       W7                  ;SAVE INDEX
                    bsr       VFDL
                    cpx       #7
                    bne       _1@@                ;LAST BYTE ?
                    clrx                          ;SEND 16 CHARACTER BYTES
_2@@                stx       W7                  ;SAVE INDEX
                    lda       DISP,x              ;ASCII
                    cmpa      #$FF
                    bne       _3@@
                    lda       #$2D                ;REPLACE $FF WITH "-"
_3@@                and       #$7F                ;IGNORE BIT 7
                    tax
                    lda       VTAB,x              ;CONVERT TO VFD CHARACTER SET
                    bsr       VFDL
                    cpx       #16
                    bne       _2@@                ;LAST BYTE ?
                    bset      3,PORTB             ;ENABLE HIGH
                    bclr      DATA_CLK            ;CLOCK LOW ?
                    rts

InitF@@             fcb       $A0,$0F,$B0,$00,$80,$00,$90

;*******************************************************************************

VFDL                proc
                    ldx       #8
Loop@@              lsra                          ;GET A BIT
                    bcc       _1@@
                    bset      DATA_PIN            ;DATA HIGH
_1@@                bclr      DATA_CLK            ;CLOCK
                    bset      DATA_CLK            ;IT
                    bclr      DATA_PIN            ;CLEAR DATA
                    dbnzx     Loop@@              ;COMPLETE ? NO
                    ldx       #64
Delay@@             dbnzx     Delay@@             ;WAIT 200uS
                    ldx       W7                  ;RESTORE INDEX
                    incx
                    rts

;*******************************************************************************
; Normal display (PS and time).
;*******************************************************************************

NORMD               proc
                    lda       #' '
                    sta       DISP
                    sta       DISP+9
                    sta       DISP+15
                    lda       #$2E                ;.
                    brclr     1,STAT4,_1@@        ;DP TO INDICATE SLEEP TIMER RUNNING
                    brclr     2,TH8,_1@@          ;FLASH IT
                    sta       DISP+15
_1@@                clrx
_2@@                lda       PSN,x               ;GET PS NAME
                    sta       DISP+1,x
                    incx
                    cpx       #7
                    bls       _2@@
                    lda       OUR                 ;GET TIME
                    jsr       CBCD
                    cpx       #'0'                ;LEADING ZERO ?
                    bne       _3@@
                    ldx       #$20                ;YES, MAKE IT A SPACE
_3@@                stx       DISP+10
                    sta       DISP+11
                    lda       MIN
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
                    lda       #' '
                    brclr     2,TH8,_4@@
                    lda       #':'                ;0.5 Hz FLASHING COLON
_4@@                sta       DISP+12
                    rts

;*******************************************************************************
; Clear display transient flags.
;*******************************************************************************

CLTR                bclr      0,STAT4             ;CLEAR DISPLAY TRANSIENT FLAG
                    bclr      2,STAT2             ;NOT RT DISPLAY
                    clr       RTDIS               ;CLEAR RDS DISPLAY INDEX
                    bclr      3,STAT4             ;NOT ALARM DISPLAY
                    bclr      5,STAT4             ;NOT ALARM SET-UP
                    bclr      7,STAT4             ;NOT RDS DISPLAYS
                    bclr      2,STAT4             ;NOT SLEEP TIMER DISPLAY
                    rts

;*******************************************************************************
; PTY display.
;*******************************************************************************

PTYD                proc
                    ldx       PTY
                    cpx       #16
                    blo       _1@@
                    clrx
_1@@                lda       #::PTYT             ;size of table entry (WAS: #16)
                    mul
                    sta       W8
                    clr       W7
Loop@@              ldx       W8
                    lda       PTYT,x
                    ldx       W7
                    sta       DISP,x              ;WAS MOD2
                    inc       W8
                    inc       W7
                    lda       W7
                    cmpa      #16
                    blo       Loop@@
                    rts

;*******************************************************************************
; RDS display
;*******************************************************************************

NXTC                proc
                    ldx       DISP2
                    lda       RT-1,x              ;RT
                    cmpa      #$20
                    bne       NOTSP               ;SPACE ?
                    brclr     5,STAT2,FSP         ;YES, FIRST ONE ?
                    inc       DISP1               ;NO, SKIP THIS ONE
                    inc       DISP2
;                   bra       RTDS

;*******************************************************************************

RTDS                proc
                    lda       DISP2
                    cmpa      #69
                    bhi       Done@@              ;END OF RT BUFFER
                    bra       NXTC                ;NO, GET NEXT CHARACTER

FSP                 bset      5,STAT2             ;FIRST SPACE, SET FLAG
                    bra       Cont@@

NOTSP               bclr      5,STAT2             ;NOT A SPACE, CLEAR FLAG
Cont@@              sta       W8                  ;SAVE NEW CHARACTER
                    clrx
Loop@@              lda       DISP+1,x            ;MOVE
                    sta       DISP,x              ;REST
                    incx                          ;LEFT
                    cpx       #15                 ;ONE
                    bne       Loop@@              ;PLACE
                    lda       W8
                    sta       DISP+15             ;ADD NEW CHAR. (WAS MOD2)
Done@@              rts

;*******************************************************************************
; Standby display
;*******************************************************************************

STBYD               proc
                    brset     4,STAT4,ALRMA       ;ALARM ARMED ?
                    lda       DOW                 ;NO, GET DAY OF WEEK
                    lsla
                    add       DOW
                    tax
                    lda       DNAME,x
                    sta       DISP
                    lda       DNAME+1,x
                    sta       DISP+1
                    lda       DNAME+2,x
                    sta       DISP+2
                    lda       #$20
                    sta       DISP+3
                    sta       DISP+6
                    sta       DISP+10
                    lda       DOM+1               ;DATE
                    add       #$30
                    sta       DISP+5
                    lda       DOM
                    beq       _1@@                ;IF ZERO USE A SPACE
                    add       #$10                ;IF NOT MAKE ASCII
_1@@                add       #$20
                    sta       DISP+4
                    ldx       MNTH+1              ;MONTH, LSD
                    lda       MNTH                ;MONTH, MSD
                    beq       _2@@
                    txa
                    add       #10
                    tax
_2@@                stx       W8
                    txa
                    lsla
                    add       W8
                    tax
                    lda       MNAME-3,x
                    sta       DISP+7
                    lda       MNAME-2,x
                    sta       DISP+8
                    lda       MNAME-1,x
                    sta       DISP+9
                    bra       STIME

;*******************************************************************************
; Standby (alarm armed) display
;*******************************************************************************

ALRMA               proc
                    lda       AOUR                ;GET ALARM HOURS
                    jsr       CBCD
                    stx       DISP
                    sta       DISP+1
                    lda       AMIN
                    jsr       CBCD
                    stx       DISP+2
                    sta       DISP+3
                    clrx
_1@@                lda       ALARMS+1,x
                    sta       DISP+4,x
                    incx
                    cpx       #6
                    bls       _1@@
STIME               lda       OUR                 ;GET TIME
                    jsr       CBCD
                    cpx       #$30                ;LEADING ZERO ?
                    bne       _2@@
                    ldx       #$20                ;YES, MAKE IT A SPACE
_2@@                stx       DISP+11
                    sta       DISP+12
                    lda       MIN
                    jsr       CBCD
                    stx       DISP+14
                    sta       DISP+15
                    lda       #$20
                    brclr     2,TH8,_3@@          ;FLASH ?
                    lda       #$3A                ;0.5 Hz FLASHING COLON
_3@@                sta       DISP+13
                    rts

;*******************************************************************************
; PI display
;*******************************************************************************

DIPI                proc
                    clrx
Loop@@              lda       PIST,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       PI
                    beq       Done@@
                    jsr       SPLIT
                    stx       DISP+11
                    sta       DISP+12
                    lda       PI+1
                    jsr       SPLIT
                    stx       DISP+13
                    sta       DISP+14
Done@@              rts

;*******************************************************************************
; Alarm display
;*******************************************************************************

ALRMD               proc
                    clrx                          ;YES
_1@@                lda       ALARMS,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       _1@@
                    brclr     4,STAT4,Done@@      ;ALARM ARMED ?
                    lda       #$3A                ;YES
                    sta       DISP+12
                    lda       AOUR                ;GET ALARM HOURS
                    jsr       CBCD
                    cpx       #$30                ;LEADING ZERO ?
                    bne       _2@@
                    ldx       #$20                ;YES, MAKE IT A SPACE
_2@@                stx       DISP+10
                    sta       DISP+11
                    lda       AMIN
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
                    brclr     5,STAT4,Done@@      ;SET-UP ?
                    brclr     2,TH8,Done@@
                    lda       #$20
                    brset     6,STAT4,_3@@        ;HOURS ?
                    sta       DISP+13             ;NO, FLASH MINUTES
                    sta       DISP+14
                    bra       Done@@

_3@@                sta       DISP+10             ;YES, FLASH HOURS
                    sta       DISP+11
Done@@              rts

;*******************************************************************************
; TA & TP flags display
;*******************************************************************************

DITAP               proc
                    clrx
Loop@@              lda       TAPST,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       #$31
                    brclr     3,STAT3,_1@@        ;TP FLAG HIGH ?
                    sta       DISP+6              ;YES, DISPLAY A 1
_1@@                brclr     2,STAT3,Done@@      ;TA FLAG HIGH ?
                    sta       DISP+14             ;YES, DISPLAY A 1
Done@@              rts

;*******************************************************************************
; PIN displays
;*******************************************************************************

DPIN1               proc
                    clrx
Loop@@              lda       PINST1,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       PIN
                    beq       Done@@
                    jsr       SPLIT
                    stx       DISP+11
                    sta       DISP+12
                    lda       PIN+1
                    jsr       SPLIT
                    stx       DISP+13
                    sta       DISP+14
Done@@              rts

;*******************************************************************************

DPIN2               proc
                    clrx
_1@@                lda       PINST2,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       _1@@
                    lda       PIN                 ;DATE
                    beq       Done@@
                    lsra:3
                    jsr       CBCD
                    cpx       #$30
                    bne       _2@@
                    ldx       #$20
_2@@                stx       DISP+2
                    sta       DISP+3
                    cpx       #$31
                    beq       _5@@
                    cmpa      #$31
                    bne       _3@@
                    lda       #'s'
                    sta       DISP+4
                    lda       #'t'
                    sta       DISP+5
_3@@                cmpa      #$32
                    bne       _4@@
                    lda       #'n'
                    sta       DISP+4
                    lda       #'d'
                    sta       DISP+5
_4@@                cmpa      #$33
                    bne       _5@@
                    lda       #'r'
                    sta       DISP+4
                    lda       #'d'
                    sta       DISP+5
_5@@                lda       PIN                 ;HOURS
                    and       #7
                    ldx       PIN+1
                    aslx
                    rola
                    aslx
                    rola
                    jsr       CBCD
                    stx       DISP+10
                    sta       DISP+11
                    lda       PIN+1               ;MINUTES
                    and       #$3F
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
Done@@              rts

;*******************************************************************************
; MJD display
;*******************************************************************************

DMJD                proc
                    bsr       SMJD
                    lda       MJD
                    beq       Done@@
                    add       #$30
                    sta       DISP+10
                    lda       MJD+1
                    add       #$30
                    sta       DISP+11
                    lda       MJD+2
                    add       #$30
                    sta       DISP+12
                    lda       MJD+3
                    add       #$30
                    sta       DISP+13
                    lda       MJD+4
                    add       #$30
                    sta       DISP+14
Done@@              rts

;*******************************************************************************

SMJD                proc
                    clrx
Loop@@              lda       MJDST,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    rts

;*******************************************************************************
; EON display
;*******************************************************************************

DEON                proc
                    bsr       SMJD                ;CLEAR FREQUENCY CHARACTERS
                    lda       RTDIS
                    sub       #8
                    ldx       #16
                    mul
                    tax
                    lda       #$20
                    sta       DISP+8
                    sta       DISP+9
                    lda       EON+2,x             ;DISPLAY PS (EON)
                    sta       DISP
                    lda       EON+3,x
                    sta       DISP+1
                    lda       EON+4,x
                    sta       DISP+2
                    lda       EON+5,x
                    sta       DISP+3
                    lda       EON+6,x
                    sta       DISP+4
                    lda       EON+7,x
                    sta       DISP+5
                    lda       EON+8,x
                    sta       DISP+6
                    lda       EON+9,x
                    sta       DISP+7
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
                    sta       W1
                    txa
                    adc       #$22
                    sta       W2
                    jsr       DCON2               ;CONVERT TO DECIMAL
                    lda       Q+4                 ;DISPLAY VHF EON FREQUENCY
                    bne       _2@@
                    lda       #$F0
_2@@                add       #$30
                    sta       DISP+10
                    tax
                    lda       Q+5
                    bne       _3@@
                    cpx       #$20
                    bne       _3@@
                    lda       #$F0
_3@@                add       #$30
                    sta       DISP+11
                    lda       Q+6
                    add       #$30
                    sta       DISP+12
                    lda       #$2E
                    sta       DISP+13
                    lda       Q+7
                    add       #$30
                    sta       DISP+14
                    lda       Q+8
                    add       #$30
                    sta       DISP+15
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
                    stx       W2
                    sta       W1
                    bsr       DCON2               ;CONVERT TO BCD IN Q
                    lda       Q+5
                    bne       _2@@                ;IF THOUSANDS OF kHz A ZERO
                    lda       #$F0                ;DISPLAY AS A SPACE
_2@@                add       #'0'
                    sta       DISP+9
                    lda       Q+6
                    add       #'0'
                    sta       DISP+10
                    lda       Q+7
                    add       #'0'
                    sta       DISP+11
                    lda       Q+8
                    add       #'0'
                    sta       DISP+12
                    lda       #'k'
                    sta       DISP+13
                    lda       #'H'
                    sta       DISP+14
                    lda       #'z'
                    sta       DISP+15
                    rts

;*******************************************************************************
; Sleep display.
;*******************************************************************************

SLEEPD              proc
                    clrx
Loop@@              lda       SLPST,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    lda       SLEPT
                    jsr       CBCD
                    stx       DISP+8
                    sta       DISP+9
                    rts

;*******************************************************************************
; M/S & DI display.
;*******************************************************************************

DMSD                proc
                    clrx
Loop@@              lda       MSDST,x
                    sta       DISP,x
                    incx
                    cpx       #15
                    bls       Loop@@
                    brclr     0,STAT3,Cont@@      ;M/S FLAG SET
                    lda       #'M'                ;YES, MUSIC
                    sta       DISP+6
Cont@@              lda       DI
                    bsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
                    rts

;*******************************************************************************
; Convert binary to unpacked BCD in Q.
;*******************************************************************************

DCON2               proc
                    ldx       #R                  ;CLEAR
                    stx       NUM1
                    jsr       CLRAS               ;RR
                    inc       R+8                 ;R <- 1
                    jsr       CLQ                 ;CLEAR RQ
                    lda       #14                 ;14 BITS TO CONVERT
                    sta       W6
Loop@@              lsr       W2                  ;MOVE OUT
                    ror       W1                  ;FIRST (LS) BIT
                    bcc       Cont@@              ;ZERO
                    ldx       #Q                  ;ONE, ADD
                    stx       NUM2                ;CURRENT VALUE
                    jsr       ADD                 ;OF R
Cont@@              ldx       #R                  ;ADD R
                    stx       NUM2                ;TO
                    jsr       ADD                 ;ITSELF
                    dbnz      W6,Loop@@           ;ALL DONE ?
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
                    clr       PORTCD              ;INPUT ON PORTC
Loop@@              bset      LCD_CLK             ;CLOCK HIGH
                    lda       PORTC               ;READ MODULE
                    bclr      LCD_CLK             ;CLOCK LOW
                    sta       W7
                    brset     7,W7,Loop@@         ;BUSY ?
                    com       PORTCD              ;OUTPUT ON PORTC
                    bclr      LCD_BUSY
                    rts

;*******************************************************************************
; Hex->BCD conversion (& decimal adjust).
;*******************************************************************************

CBCD                proc
                    bsr       UPX
                    bsr       ADJI                ;DECIMAL ADJUST
BCD                 sta       W7                  ;SAVE
                    add       #$16                ;ADD $16 (BCD 10)
                    bsr       ADJU                ;ADJUST
                    decx
                    bpl       BCD                 ;TOO FAR ?
                    lda       W7                  ;YES, RESTORE A
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
                    clr       DISP1               ;INITIALISE SCROLLING POINTERS
                    clr       DISP2
                    clr       PTY                 ;CLEAR PTY
                    clr       PIN                 ;AND
                    clr       PIN+1               ;PIN
                    clr       DI                  ;AND DI
                    bclr      0,STAT3             ;AND M/S
                    bclr      3,STAT3             ;CLEAR TP FLAG
                    bclr      2,STAT2             ;CANCEL RT DISPLAY
                    clrx
                    lda       #$2D
PLOP3               sta       PSN,x               ;CLEAR PS NAME
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
; MJD day and month strings.
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
; MJD -> day, date, month and year
;
; P. Topping 5th December '91
;
; Transfer of BCD numbers.
; (X) <- (NUM1), X preserved
;*******************************************************************************

TRA                 stx       NUM2                ;CLEAR DESTINATION
                    jsr       CLRAS               ;AND ADD IT TO No. AT NUM1

;*******************************************************************************
; Addition of BCD numbers.
;
; (X) <- (NUM1) + (NUM2), X preserved
;*******************************************************************************

ADD                 proc
                    clr       CARRY
                    stx       W7
AD                  stx       W5                  ;ANSWER POINTER
                    lda       #ND
                    sta       COUNT
                    ldx       NUM1                ;1st No. POINTER
                    stx       W3
                    ldx       NUM2                ;2nd No. POINTER
                    stx       W4
Loop@@              ldx       W3
                    lda       ND-1,x
                    dec       W3
                    ldx       W4
                    add       ND-1,x              ;ADD
                    dec       W4
                    add       CARRY               ;SET ON ADDITION OVERFLOW
                    clr       CARRY               ;OR POS. RESULT SUBTRACTION
                    bsr       ADJ                 ;DECIMAL ADJUST
                    ldx       W5
                    sta       ND-1,x              ;SAVE ANSWER
                    dec       W5
                    dbnz      COUNT,Loop@@        ;DONE ?
                    ldx       W7
                    rts

;*******************************************************************************

Loop@@              proc
                    sub       #10                 ;YES, SUTRACT 10
                    inc       CARRY               ;AND RECORD CARRY
ADJ                 cmpa      #10
                    bhs       Loop@@              ;10 OR MORE ?
                    rts                           ;NO

;*******************************************************************************
; Subtraction, complementing and incre-
; menting (X=REG-ND) of BCD numbers.
;
; (X) <- (NUM1) - (NUM2), X preserved.
; (X and NUM2 should not be equal)
;*******************************************************************************

SUB                 proc
                    stx       W6                  ;ANSWER POINTER
                    bsr       COM2                ;9S COMP. SECOND NUMBER
                    clr       CARRY               ;SET CARRY TO ONE
                    inc       CARRY               ;BEFORE ADDING
                    bsr       AD                  ;ADD FIRST NUMBER
;                   bra       COM2

;*******************************************************************************

COM2                proc
                    ldx       NUM2                ;9S COMPLEMENT
                    bsr       COMP                ;SECOND NUMBER
                    ldx       W6                  ;RESTORE ANSWER POINTER
                    rts

;*******************************************************************************

COMP                proc
                    lda       #ND                 ;9S COMPLEMENT
                    sta       COUNT
Loop@@              lda       #9
                    sub       ND-1,x
                    sta       ND-1,x
                    decx
                    dbnz      COUNT,Loop@@
                    rts

;*******************************************************************************
; Dead code - COM10 is never called

COM10               bsr       COMP                ;NINES COMPLEMENT THEN
;                   bra       ADD1

;*******************************************************************************

ADD1                proc
                    lda       #ND                 ;ADD 1 FOR TENS COMPLEMENT
                    sta       COUNT               ;ENTER WITH X = REG-ND
Loop@@              inc       2*ND-1,x
                    lda       2*ND-1,x
                    cmpa      #$0A
                    blo       Done@@
                    sub       #10
                    sta       2*ND-1,x
                    decx
                    dbnz      COUNT,Loop@@
Done@@              rts

;*******************************************************************************
; Mult., R <- P x Q, over. in TMP, X = #R.
;*******************************************************************************

MULT                proc
                    ldx       #R
                    jsr       CLRAS
                    ldx       #TMP
                    jsr       CLRAS               ;CLEAR RESULT
                    ldx       #2*ND
                    stx       W6                  ;INIT. R POINTER
                    ldx       #ND
Loop@@              lda       P-1,x
                    stx       W1                  ;SAVE P POINTER
                    sta       CARRY               ;SAVE P
                    ldx       #ND                 ;INIT. Q POINTER
Xit@@               lda       Q-1,x
                    sta       W4                  ;SAVE Q
                    beq       ToZero@@            ;IF ZERO GOTO NEXT Q
                    lda       CARRY               ;RECALL P
                    sta       W3                  ;SAVE P
                    clra
Ply@@               lsr       CARRY               ;RIGHT SHIFT INTO C
                    bcc       Shf@@               ;C = ZERO ?
                    add       W4                  ;NO, A=A+Q
Shf@@               tst       CARRY               ;ZERO ?
                    beq       C4@@                ;YES, FINISHED WITH THIS Q
                    asl       W4                  ;NO, LEFT SHIFT Q
                    bra       Ply@@

C4@@                decx                          ;Q = Q + 1
                    stx       W2                  ;SAVE Q POINTER
                    ldx       W6                  ;R POINTER
                    add       R-ND-1,x            ;ADD R TO A
                    bsr       ADJ                 ;ADJUST
                    sta       R-ND-1,x            ;R = R + A
                    lda       CARRY
                    add       R-ND-2,x            ;ADD R-(ND+2) TO CARRY
                    sta       R-ND-2,x            ;R-(ND+2) = R-(ND+2) + CARRY
                    lda       W3                  ;RECALL P
                    sta       CARRY               ;SAVE IN CARRY
                    decx
                    stx       W6                  ;SAVE R POINTER
                    ldx       W2                  ;Q POINTER
                    bra       C3@@

ToZero@@            dec       W6                  ;DEC. R POINTER
                    decx                          ;DEC. Q POINTER
C3@@                bne       Xit@@
                    lda       W6                  ;R POINTER
                    add       #ND-1
                    sta       W6                  ;R = R + ND-1
                    ldx       W1
                    decx                          ;P = P + 1
                    bne       Loop@@              ;IF NOT ZERO GOTO NEXT P
                    ldx       #R
                    rts

;*******************************************************************************
; Division of BCD numbers.
;
; R <- P / Q, remainder in TMP.
; on exit X = #R, TMQ used.
;*******************************************************************************

DIV                 proc
                    ldx       #R                  ;CLEAR
                    bsr       CLRAS               ;RESULT
                    ldx       #P                  ;TRANSFER
                    stx       NUM1                ;P TO
                    ldx       #TMP                ;WORKING
                    jsr       TRA                 ;P (TMP)
                    ldx       #Q                  ;TRANSFER
                    stx       NUM1                ;Q TO
                    ldx       #TMQ                ;WORKING
                    jsr       TRA                 ;Q (TMQ)
                    lda       #ND                 ;NUMBER
                    sta       COUNT               ;DIGITS
Loop@@              ldx       #TMQ                ;FIND LEAST SIGNIFICANT
                    lda       ,x                  ;NON-ZERO DIGIT
                    bne       Nosh@@              ;ZERO ?
                    bsr       SHIFT               ;YES, SHIFT Q
                    bne       Loop@@              ;UP ONE PLACE
                    bra       Done@@              ;Q WAS ZERO

Nosh@@              lda       COUNT               ;SAVE
                    sta       W1                  ;No. DIDITS - No. SHIFTS
SubQ@@              ldx       #TMP                ;SUBTRACT Q
                    stx       NUM1                ;FROM
                    jsr       SUB                 ;P
                    lda       CARRY               ;TOO FAR ?
                    beq       NextD@@             ;IF YES, GO TO NEXT DIGIT
                    ldx       W1                  ;INCREMENT RELEVANT
                    inc       R-1,x               ;DIGIT IN RESULT
                    bra       SubQ@@              ;ONCE AGAIN

NextD@@             ldx       #TMP                ;TOO FAR, ADD
                    jsr       ADD                 ;Q BACK ON
                    ldx       #TMQ                ;SET UP TO
                    lda       #ND-1               ;SHIFT BACK
                    sta       COUNT               ;WORKING Q
_@@                 lda       ND-2,x              ;MOVE ALL
                    sta       ND-1,x              ;DIGITS
                    decx                          ;DOWN
                    dec       COUNT               ;ONE PLACE
                    bne       _@@                 ;DONE ?
                    clr       ND-1,x              ;CLEAR MS DIGIT
                    inc       W1                  ;INCREMENT POINTER
                    lda       W1
                    cmpa      #ND+1               ;FINISHED ?
                    bne       SubQ@@              ;NO, NEXT DIGIT
Done@@              ldx       #R
                    rts

;*******************************************************************************

SHIFT               proc
                    sta       W3
                    bsr       DR1                 ;W1: MSD, W2: LSD
                    ldx       W1
Loop@@              lda       1,x                 ;MOVE ALL DIGITS
                    sta       ,x                  ;UP ONE PLACE
                    incx
                    cpx       W2
                    bne       Loop@@              ;DONE ?
                    lda       W3                  ;YES, RECOVER NEW DIGIT
                    sta       ,x                  ;AND PUT IT IN LSD
                    dec       COUNT
                    rts

;*******************************************************************************

DR1                 proc
                    stx       W1                  ;STORE POINTERS
                    lda       #ND-1               ;(USED IN DIGIT AND DQ)
Loop@@              incx
                    deca
                    bne       Loop@@
                    stx       W2
                    rts

;*******************************************************************************
; Clear.
;*******************************************************************************

CLQ                 proc
                    ldx       #Q                  ;CLEAR Q
;                   bra       CLRAS

;*******************************************************************************

CLRAS               proc
                    stx       W5
                    lda       #ND                 ;CLEAR No. DIGITS
                    sta       COUNT               ;STARTING AT X
Loop@@              clr       ,x
                    incx
                    dec       COUNT
                    bne       Loop@@              ;DONE ?
                    ldx       W5
                    rts

;*******************************************************************************
; MJD - day of week and year.
;
; DOW = (MJD+2)MOD7 (= WD-1) (DOW)
; Y' = INT((MJD-15078.2)/3652500) (YR)
;*******************************************************************************

MJDC                proc
                    ldx       #MJD
                    stx       NUM1
                    ldx       #P
                    jsr       TRA                 ;P <- MTD
                    ldx       #MJD
                    jsr       T10K                ;MJD <- MJD TIMES 10,000
                    ldx       #P-ND
                    jsr       ADD1                ;P <- MJD + 1
                    ldx       #P-ND
                    jsr       ADD1                ;P <- MJD + 2
                    ldx       #Q
                    bsr       CLRAS
                    lda       #7
                    sta       Q+ND-1              ;Q <- 7
                    jsr       DIV                 ;R <- (MJD+2)/7
                    lda       TMP+ND-1            ;REMAINDER (WD-1) IN TMP
                    sta       DOW
          ;-------------------------------------- ;YEAR
                    ldx       #MJD
                    stx       NUM1
                    ldx       #Q
                    stx       NUM2
                    jsr       TRCY                ;Q <- CY (150782000)
                    ldx       #P
                    jsr       SUB                 ;P <- 10K(MJD-15078.2)
                    jsr       TRDY                ;Q <- 3652500
                    jsr       DIV                 ;R <- Y' ((MJD-15078.2)/365.25)
                    stx       NUM1
                    ldx       #YR
                    jsr       TRA                 ;YR <- Y'

;*******************************************************************************
; MJD - month and day.
;
; M'= INT((MJD-14956.1-INT(Y'*365.25))/306001) (P)
; D = MJD-14956-INT(Y'*365.25)-INT(M'*30.6001) (Q(x10K))
;*******************************************************************************

MONTH               proc
                    jsr       INT                 ;R <- 10K(INT(Y'*365.25))
                    ldx       #MJD
                    stx       NUM1
                    ldx       #P
                    stx       NUM2
                    jsr       TRDO1               ;P <- 149561000
                    ldx       #Q
                    jsr       SUB                 ;Q <- 10K(MJD-14956.1)
                    stx       NUM1
                    ldx       #R
                    stx       NUM2
                    ldx       #P
                    jsr       SUB                 ;P <- 10K(MJD-14956.1-INT(Y'*365.25))
                    jsr       TRDM                ;Q <- 306001
                    jsr       DIV                 ;R <- M' ( MJD-14956.1-INT(Y'*365.25) )
                    stx       NUM1                ;INT ( --------------------------)
                    ldx       #P                  ;( 306001 )
                    jsr       TRA                 ;P <- M'
                    lda       P+ND-2              ;SAVE M'
                    sta       MNTH
                    lda       P+ND-1
                    sta       MNTH+1
DAY                 jsr       TRDM                ;Q <- 306001
                    bsr       MULTI               ;R <- 10K(INT(M'*30.6001))
                    stx       NUM1
                    ldx       #TMQ
                    jsr       TRA                 ;TMQ <- 10K(INT(M'*30.6001))
                    bsr       INT                 ;R <- 10K(INT(Y'*365.25))
                    stx       NUM2
                    ldx       #TMQ
                    stx       NUM1
                    jsr       ADD                 ;TMQ <- 10K(INT(Y'*365.25)+INT(M'*30.6001))
                    stx       NUM1
                    ldx       #P
                    stx       NUM2
                    jsr       TRDO1               ;P <- 149561000
                    clr       P+ND-4              ;P <- 149560000
                    ldx       #R
                    jsr       ADD                 ;R <- 10K(14956+INT(Y'*365.25)+INT(M'*30.6001))
                    stx       NUM2
                    ldx       #MJD
                    stx       NUM1
                    ldx       #Q
                    jsr       SUB                 ;Q <- MJD-R (10K*DOM)
                    lda       ND-5,x
                    sta       DOM+1               ;MJD-14956-INT(Y'*365.25)-INT(M'*30.6001)
                    lda       ND-6,x
                    sta       DOM

;*******************************************************************************
; MJD - final correction of year & month and subs.
;
; If M' = 14 or 15, then K = 1, else K = 0
; Y = Y' + K
; M = M' - 1 - K*12
;*******************************************************************************

ADJU2               proc
                    lda       MNTH                ;MONTH, MSD
                    beq       _2@@                ;0 ?
                    lda       MNTH+1              ;NO, M'= 10 THRU 15
                    beq       _1@@                ;0 ?
                    cmpa      #4                  ;NO, M'= 11 THRU 15
                    blo       _2@@                ;LESS THAN 14
                    ldx       #YR-ND              ;NO, M'= 14 OR 15, K=1
                    jsr       ADD1                ;Y <- Y'+1
                    clr       MNTH                ;MONTH, MSD (-10)
                    dec       MNTH+1              ;DEC. MONTH
                    dec       MNTH+1              ;AND AGAIN (-2)
                    bra       _2@@                ;-12

_1@@                lda       #10                 ;M'= 10
                    sta       MNTH+1              ;PUT 10 IN LSD
                    clr       MNTH                ;CLEAR MSD
_2@@                dec       MNTH+1              ;9<-10, 1,2<-14,15, 3-8<-4-9, 10-12<-11-13
                    rts

;*******************************************************************************

INT                 proc
                    ldx       #YR
                    stx       NUM1
                    ldx       #P
                    jsr       TRA                 ;P <- Y'
                    bsr       TRDY                ;Q <- 10K*365.25
;                   bra       MULTI

;*******************************************************************************

MULTI               proc
                    jsr       MULT                ;R <- 10K*Y'*365.25
                    clr       R+ND-4
                    clr       R+ND-3
                    clr       R+ND-2
                    clr       R+ND-1              ;R <- 10K(INT(Y'*365.25))
                    rts

;*******************************************************************************

T10K                proc
                    txa                           ;TIMES 10,000
                    add       #ND-4
                    sta       W1
Loop@@              lda       4,x
                    sta       ,x
                    incx
                    cpx       W1
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
                    sta       Q-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

TRDY                proc
                    ldx       #ND
Loop@@              lda       DY-1,x
                    sta       Q-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

TRDM                proc
                    ldx       #ND
Loop@@              lda       DM-1,x
                    sta       Q-1,x
                    dbnzx     Loop@@
                    rts

;*******************************************************************************

TRDO1               proc
                    ldx       #ND
Loop@@              lda       DO1-1,x
                    sta       P-1,x
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
                    fdb       TINTB               ;TIMER B
                    fdb       Start               ;TIMER A
                    fdb       SDATA               ;EXTERNAL INTERRUPT & RTI
                    fdb       Start               ;SWI
                    fdb       Start               ;RESET

                    end
