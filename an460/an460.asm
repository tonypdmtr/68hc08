;*******************************************************************************
; HC05E0 RDS Decoder.
; P. Topping 29th February '92
;*******************************************************************************

PORTA               equ       $00                 ; PORT A ADDRESS
PORTB               equ       $01                 ; " B "
PORTC               equ       $02                 ; " C "
PORTD               equ       $03                 ; " D "
PORTE               equ       $04                 ; " E "
PORTAD              equ       $05                 ; PORT A DATA DIRECTION REG.
PORTBD              equ       $06                 ; " B " " "
PORTCD              equ       $07                 ; " C " " "
PORTDD              equ       $08                 ; " D " " "
PORTED              equ       $09                 ; " E " " "
TAP                 equ       $0A                 ; TIMER A PRE-SCALLER
TBS                 equ       $0B                 ; TIMER B SCALLER
TCR                 equ       $0C                 ; TIMER CONTROL REGISTER
ICR                 equ       $0E                 ; INTERRUPT CONTROL REGISTER
PORTDSF             equ       $12                 ; PORTD SPECIAL FUNCTIONS
ND                  equ       9                   ; No. BCD DIGITS

;*******************************************************************************
                    #RAM      $0030
;*******************************************************************************

Q                   rmb       9                   ; BCD WORKING NUMBERS
TMQ                 rmb       9                   ; SCRATCH
P                   rmb       9                   ; WORKING NUMBER 2
TMP                 rmb       9                   ; MULT. OVER. OR DIV. REMAINDER
R                   rmb       9                   ; WORKING NUMBER 3
MJD                 rmb       9                   ; MODIFIED JULIAN DAY NUMBER
YR                  rmb       9                   ; YEAR
MNTH                rmb       2                   ; MONTH
DOM                 rmb       2                   ; DATE
DOW                 rmb       1                   ; DAY OF WEEK
BMJD                rmb       3                   ; BINARY MJD
DIST                rmb       1                   ; DISPLAY TRANSIENT TIMEOUT COUNTER
SLEPT               rmb       1                   ; SLEEP TIMER MINUTES COUNTER
RDSTO               rmb       1                   ; RDS TIMEOUT COUNTER
DAT                 rmb       4                   ; SERIAL DATA BUFFER
TMPGRP              rmb       8                   ; TEMPORARY GROUP DATA
GROUP               rmb       8                   ; COMPLETE GROUP DATA
PTY                 rmb       1                   ; PROGRAM-TYPE CODE (CURRENT)
PI                  rmb       2                   ; PROGRAM IDENTIFICATION CODE
PIN                 rmb       2                   ; PROGRAM ITEM NUMBER
LEV                 rmb       1                   ; VALID BLOCK LEVEL
BIT                 rmb       1                   ; BIT LEVEL
ITMP1               rmb       1                   ; TEMP BYTE FOR USE IN IRQ
SYN                 rmb       2                   ; SYNDROME
CONF                rmb       1                   ; SYNDROME CONFIDENCE
TH8                 rmb       1                   ; TICS (EIGHTHS OF SECONDS)
SEC                 rmb       1                   ; SECONDS
MIN                 rmb       1                   ; MINUTES
OUR                 rmb       1                   ; HOURS
AMIN                rmb       1                   ; ALARM MINUTES
AOUR                rmb       1                   ; ALARM HOURS
DISP1               rmb       1                   ; RT DISPLAY POINTER #1
DISP2               rmb       1                   ; RT DISPLAY POINTER #2
W1                  rmb       1                   ; W
W2                  rmb       1                   ; O
W3                  rmb       1                   ; R
W4                  rmb       1                   ; K
W5                  rmb       1                   ; I
W6                  rmb       1                   ; N
W7                  rmb       1                   ; G
W8                  rmb       1
KEY                 rmb       1                   ; CODE OF PRESSED KEY
KOUNT               rmb       1                   ; KEYBOARD COUNTER
CARRY               rmb       1                   ; BCD CARRY
COUNT               rmb       1                   ; LOOP COUNTER
NUM1                rmb       1                   ; 1ST No. POINTER (ADD & SUBTRACT)
NUM2                rmb       1                   ; 2ND No. POINTER (ADD & SUBTRACT)
RTDIS               rmb       1                   ; RDS DISPLAY TYPE
DI                  rmb       1                   ; DECODER IDENTIFICATION
DISP                rmb       16                  ; LCD MODULE BUFFER
PSN                 rmb       8                   ; PS NAME
STAT2               rmb       1                   ; 0: VALID SYNDROME
                                                  ; 1: VALID GROUP
                                                  ; 2: RT DISPLAY
                                                  ; 3: UPDATE DISPLAY
                                                  ; 4: CLEAR DISPLAY
                                                  ; 5: SPACE FLAG
STAT3               rmb       1                   ; 0: M/S, 0: M, 1: S
                                                  ; 1: TEXTA/TEXTB BIT (RT)
                                                  ; 2: TA FLAG
                                                  ; 3: TP FLAG
                                                  ; 4: KEY REPEATING
                                                  ; 5: KEY FUNCTION PERFORMED
                                                  ; 6: UPDATE DATE
STAT4               rmb       1                   ; 0: DISPLAY TRANSIENT
                                                  ; 1: SLEEP TIMER RUNNING
                                                  ; 2: SLEEP DISPLAY
                                                  ; 3: ALARM DISPLAY
                                                  ; 4: ALARM ARMED
                                                  ; 5: ALARM SET-UP
                                                  ; 6: ALARM HOURS (SET-UP)
                                                  ; 7: RDS DISPLAYS
                    rmb       33                  ; not used
STACK               rmb       18                  ; 19 BYTES USED (1 INTERRUPT
                    rmb       1                   ; AND 7 NESTED SUBROUTINES)

;*******************************************************************************
                    #XRAM     $0100
;*******************************************************************************

RT                  rmb       69                  ; RADIOTEXT
EON                 rmb       176                 ; EON DATA (MAX: 11 NETWORKS)

;*******************************************************************************
                    #ROM      $E000
;*******************************************************************************

;STRST              jmp       START               ; RESET VECTOR ($0400 DURING DE-BUG)
;IRQ                jmp       SDATA               ; IRQ ($0403 DURING DE-BUG)
;TIMERA             jmp       START               ; TIMER A INTERRUPT (NOT USED, $0406 DURING DE-BUG)
;TIMERB             jmp       TINTB               ; TIMER B INTERRUPT ($0409 DURING DE-BUG)
;SERINT             jmp       START               ; SERIAL INTERRUPT (NOT USED, $040C DURING DE-BUG)

;*******************************************************************************
; Reset routine - setup ports.
;*******************************************************************************

START               lda       #$C3                ; ENABLE PORTD SPECIAL FUNCTIONS
                    sta       PORTDSF             ; P02, R/W, A14 & A15 (0,1,6,7)
                    lda       #$45                ; ENABLE POSITIVE EDGE/LEVEL
                    sta       ICR                 ; INTERRUPTS
                    lda       #1                  ; TIMER B SCALER: /2
                    sta       TBS                 ; 125 mS INTERRUPTS (4.194 MHz XTAL)
                    lda       #63                 ; TIMER A PRE-SCALER: /64
                    sta       TAP                 ; 64Hz IDLE LOOP
                    clr       PORTA
                    lda       #$FF                ; E0BUG DISPLAY/KEYBOARD I/O
                    sta       PORTAD              ; NOT USED IN RDS APPLICATION
                    clr       PORTB               ; 0, 1: SERIAL CLOCK AND DATA
                    lda       #$CB                ; 2: RDS DATA IN, 3: VFD SELECT
                    sta       PORTBD              ; 4, 5: KEYBOARD IN, 6, 7: KEYBOARD OUT
                    clr       PORTC
                    lda       #$FF                ; ALL OUT, LCD DATA BUS
                    sta       PORTCD
                    lda       #$3C                ; BITS 2, 3 & 4 OUT, LCD
                    clr       PORTD               ; 2: RS, 3: R/W, 4: CLOCK, 5: LED (TA=TP=1)
                    sta       PORTDD              ; 0, 1, 6 & 7 USED DURING DE-BUG
                    lda       #$0C                ; BIT0: INPUT, ENABLE SLEEP TIMER AT ALARM TIME
                    sta       PORTE               ; BIT1: INPUT, ENABLE ALARM OUTPUT
;                   lda       #$0C                ; BIT2: ALARM OUTPUT (ACTIVE LOW)
                    sta       PORTED              ; BIT3: RADIO ON OUTPUT (ACTIVE HIGH)

;*******************************************************************************
; Initialise LCD.
;*******************************************************************************

                    lda       #$30
                    jsr       CLOCK               ; INITIALISE LCD
                    jsr       CLREON              ; CLEAR EON DATA
                    jsr       CLREON
                    jsr       CLREON              ; 4 TIMES TO PROVIDE A 5mS DELAY
                    jsr       CLREON              ; FOR LCD MODULE INITIALISATION
                    lda       #$30
                    jsr       CLOCK               ; INITIALISE LCD
                    ldx       #Q                  ; INITIALISE RAM
CLOOP               clr       0,X
                    incx                          ; PROVIDES A 1mS DELAY FOR LCD
                    cpx       #STACK
                    bne       CLOOP
                    lda       #$30
                    jsr       CLOCK               ; INITIALISE LCD
                    jsr       WAIT
                    lda       #$30                ; 1-LINE DISPLAY
                    jsr       CLOCK               ; LATCH IT
                    jsr       WAIT
                    lda       #$08                ; SWITCH DISPLAY OFF
                    jsr       CLOCK               ; LATCH IT
                    jsr       WAIT
                    lda       #$01                ; CLEAR DISPLAY
                    jsr       CLOCK               ; LATCH IT
                    jsr       INITD

;*******************************************************************************
; Vectors for de-bug using E0BUG monitor.
;*******************************************************************************

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

;*******************************************************************************
; Enable interrupts.
;*******************************************************************************

                    lda       #$0B                ; EDGE SENSITIVE IRQ, TIMERS A & B ENABLED
                    sta       TCR                 ; SUB-SYS CLK = 262144 Hz (4.194 MHz XTAL)
                                                  ; DISABLE EXTERNAL RAM WRITE
                    cli

;*******************************************************************************
; Idle loop.
;*******************************************************************************

IDLE                brclr     4,ICR,*             ; 64 Hz
                    bclr      4,ICR
NO2D                brclr     0,STAT4,NOPS        ; DISPLAY TRANSIENT ?
                    lda       DIST
                    bne       NOPS                ; YES, TIMED OUT ?
                    jsr       CLTR                ; YES, CLEAR TRANSIENT DISPLAYS
NOPS                brclr     3,STAT2,SCAN        ; DISPLAY UPDATE REQUIRED ?
                    jsr       MOD                 ; YES, DO IT
                    bclr      3,STAT2             ; AND CLEAR FLAG
SCAN                brclr     4,STAT4,CHSLP       ; ALARM ARMED ?
                    lda       AOUR                ; YES, COMPARE ALARM HOURS
                    cmp       OUR                 ; WITH TIME
                    bne       CHSLP               ; SAME ?
                    lda       AMIN                ; YES, COMPARE ALARM MINUTES
                    cmp       MIN                 ; WITH TIME
                    bne       CHSLP               ; SAME ?
                    lda       SEC                 ; ONLY ALLOW WAKE-UP IN FIRST SECOND
                    bne       CHSLP               ; TO PREVENT SWITCH-OFF LOCKOUT
                    bset      3,PORTE             ; YES, SWITCH ON
                    brset     1,PORTE,FULON2      ; ALARM ENABLED (SWITCH) ?
                    bclr      2,PORTE             ; YES, SOUND ALARM
FULON2              brset     0,PORTE,CHSLP       ; SLEEP TIMER AT ALARM TIME ?
                    jsr       INSLP               ; YES, START SLEEP TIMER
CHSLP               brclr     1,STAT4,FLN         ; SLEEP TIMER RUNNING ?
                    lda       SLEPT               ; YES
                    bne       FLN                 ; TIME TO FINISH ?
                    bclr      1,STAT4             ; YES, CLEAR FLAG
                    bclr      3,PORTE             ; AND SWITCH OFF
FLN                 jsr       KBD                 ; READ KEYBOARD
                    jsr       KEYP                ; EXECUTE KEY
                    lda       STAT3
                    and       #$0C
                    cmp       #$0C                ; TA AND TP BOTH HIGH ?
                    beq       TATP
                    brset     5,PORTD,IOOK        ; NO, I/O LINE ALREADY HIGH ?
                    bset      5,PORTD             ; NO, MAKE IT HIGH
                    bra       IOOK

TATP                brclr     5,PORTD,IOOK        ; TA=TP=1, I/O LINE ALREADY LOW ?
                    bclr      5,PORTD             ; NO, MAKE IT LOW
IOOK                brclr     6,STAT3,IDLEJ       ; UPDATE DATE ?
                    bsr       MJDAT               ; YES, CONVERT FROM MJD
IDLEJ               bra       IDLE

;*******************************************************************************
; Extract MJD and convert to decimal.
;*******************************************************************************

MJDAT               lda       BMJD+2
                    sta       YR+2
                    lda       BMJD+1
                    sta       YR+1
                    lda       BMJD
                    sta       YR
                    ldx       #R                  ; CLEAR
                    stx       NUM1
                    jsr       CLRAS               ; R
                    inc       R+ND-1              ; R <- 1
                    ldx       #MJD
                    jsr       CLRAS               ; CLEAR MJD
                    lda       #17                 ; 17 BITS TO CONVERT
                    sta       W6
LOOPJ               lsr       YR                  ; MOVE OUT
                    ror       YR+1
                    ror       YR+2                ; FIRST (LS) BIT
                    bcc       NXTJ                ; ZERO ?
                    ldx       #MJD                ; ONE, ADD
                    stx       NUM2                ; CURRENT VALUE
                    jsr       ADD                 ; OF R
NXTJ                ldx       #R                  ; ADD R
                    stx       NUM2                ; TO
                    jsr       ADD                 ; ITSELF
                    dec       W6                  ; ALL
                    bne       LOOPJ               ; DONE ?
                    bclr      6,STAT3             ; MJD UPDATED
                    jmp       MJDC                ; CONVERT MJD TO DAY, DATE, MONTH & YEAR

;*******************************************************************************
; Keyboard routine.
;*******************************************************************************

KBD                 lda       #$20
                    ldx       #2
KEY1                lsla                          ; SELECT ROW
                    and       #$C0                ; BITS 6 & 7 ONLY
                    ora       #$08                ; VFD ENABLE HIGH
                    sta       PORTB
ROW                 lda       PORTB               ; READ KEYBOARD
                    bit       #$30                ; ANY INPUT LINE HIGH ?
                    bne       L1
                    decx                          ; NO, TRY NEXT COLUMN
                    bne       KEY1                ; LAST COLUMN ?
                    clr       KEY                 ; YES, NO KEY PRESSED
                    bra       EXIT

L1                  lda       PORTB               ; READ KEYBOARD
                    and       #$F0
                    cmp       KEY                 ; SAME AS LAST TIME ?
                    beq       EXIT
                    sta       KEY                 ; NO, SAVE THIS KEY
                    clr       KOUNT
EXIT                inc       KOUNT               ; YES, THE SAME
                    lda       KOUNT
                    brclr     4,STAT3,NRML        ; REPEATING ?
                    cmp       #10                 ; YES, REPEAT AT 6 Hz
                    bra       GON2

NRML                cmp       #3                  ; NO, 3 THE SAME ?
                    blo       KCLC                ; IF NOT DO NOTHING
                    beq       GOON                ; IF 3 THEN PERFORM KEY FUNCTION
                    cmp       #48                 ; MORE THAN 3, MORE THAN 48 (750mS) ?
GON2                bhi       GOON2               ; TIME TO DO SOMETHING ?
                    lda       KEY                 ; NO
                    beq       RKEY                ; KEY PRESSED ?
                    clc
                    rts                           ; YES BUT DO NOTHING

GOON2               lda       KEY
                    cmp       #$50                ; SLEEP (DEC.)
                    beq       GOON3
                    cmp       #$90                ; RDS (INC.)
                    bne       DNT2                ; IF NOT A REPEAT KEY, DO NOTHING
GOON3               brclr     5,STAT4,DNT2        ; REPEAT KEY, BUT IS MODE ALARM SET-UP ?
                    bset      4,STAT3             ; YES, SET REPEAT FLAG
                    clr       KOUNT
GOON                lda       KEY
                    beq       RKEY                ; SOMETHING TO DO ?
                    sec                           ; YES, SET C
                    rts

RKEY                bclr      5,STAT3             ; NO, CLEAR DONE FLAG
DNT2                bclr      4,STAT3             ; CLEAR REPEAT FLAG
                    clr       KOUNT               ; CLEAR COUNTER
KCLC                clc
                    rts

;*******************************************************************************
; Execute key function.
;*******************************************************************************

KEYP                bcc       DNT                 ; ANYTHING TO DO ?
KEYP2               lda       KEY                 ; YES, GET KEY
                    cmp       #$50                ; SLEEP (DEC.)
                    beq       RPT
                    cmp       #$90                ; RDS (INC.)
                    beq       RPT
                    brset     5,STAT3,DNT         ; NOT A REPEAT KEY, DONE FLAG SET ?
RPT                 clrx
RJ                  lda       CTAB,X              ; FETCH KEYCODE
                    cmp       KEY                 ; THIS ONE ?
                    beq       PJ                  ; YES
                    cmp       LAST                ; NO, LAST CHANCE ?
                    beq       DNT                 ; YES, ABORT
                    incx                          ; NO
                    incx                          ; TRY
                    incx                          ; THE
                    incx                          ; NEXT
                    bra       RJ                  ; KEY

PJ                  bset      5,STAT3             ; KEY FUNCTION DONE
                    incx
                    jsr       CTAB,X
DNT                 rts

;*******************************************************************************
; Keyboard jump table.
;*******************************************************************************

CTAB                fcb       $60                 ; ALARM
                    jmp       ALARM

                    fcb       $A0                 ; ON/OFF
                    jmp       ONOFF

                    fcb       $50                 ; SLEEP TIMER START
                    jmp       SLEEP

LAST                fcb       $90                 ; RDS DISPLAYS
                    jmp       RDS

;*******************************************************************************
; Alarm key.
;*******************************************************************************

ALARM               brclr     2,PORTE,ALRG        ; ALARM RINGING ?
                    brclr     3,STAT4,ADON        ; NO, ALARM DISPLAY ON ?
                    brclr     4,STAT4,ALOF        ; YES, ALARM ON ?
                    bclr      4,STAT4             ; YES, SWITCH OFF
                    bra       UDCNT

ALOF                bset      4,STAT4             ; NO, SWITCH ON
                    bra       UDCNT

ADON                jsr       CLTR
                    bset      3,STAT4             ; ALARM DISPLAY FLAG
UDCNT               bclr      5,STAT4             ; CANCEL SET-UP
                    lda       #25                 ; 3 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ; SET DISPLAY TRANSIENT FLAG
ABOA                rts

;*******************************************************************************
; On/off key (alarm set-up).
;*******************************************************************************

ONOFF               brclr     2,PORTE,ALRG        ; ALARM RINGING ?
                    brclr     3,STAT4,NOTALR      ; NO, ALARM DISPLAY ?
                    brclr     4,STAT4,NOTALR      ; YES, ALARM ARMED ?
                    brset     5,STAT4,AISM        ; YES, ALREADY SET-UP MODE ?
                    bset      5,STAT4             ; NO, ENTER SET-UP MODE
                    bset      6,STAT4             ; WITH HOURS
A5SD                lda       #80
                    sta       DIST
                    bset      0,STAT4             ; SET DISPLAY TRANSIENT FLAG
NTB2                rts

AISM                brset     6,STAT4,MSM         ; SET-UP HOURS ?
                    bclr      5,STAT4             ; NO, CANCELL SET-UP
                    bra       A5SD

MSM                 bclr      6,STAT4             ; YES, MAKE IT MINUTES
                    bra       A5SD

;*******************************************************************************
; On/off key (normal function).
;*******************************************************************************

NOTALR              jsr       CLTR                ; CLEAR DISPLAY TRANSIENTS
                    bclr      1,STAT4             ; CANCEL SLEEP TIMER
                    brset     3,PORTE,ALRON       ; ON ?
SODM                bset      3,PORTE             ; NO, SWITCH ON
                    rts

ALRON               bclr      3,PORTE             ; YES, SWITCH OFF
                    rts

ALRG                bset      2,PORTE             ; CANCEL ALARM
                    rts

;*******************************************************************************
; Sleep key.
;*******************************************************************************

SLEEP               brclr     2,PORTE,ALRG        ; ALARM RINGING ?
                    brclr     5,STAT4,NOTAL       ; NO, ALARM SET-UP ?
                    jmp       PDEC                ; YES

NOTAL               brset     2,STAT4,DECS        ; NO, ALREADY SLEEP DISPLAY ?
                    brset     1,STAT4,STR2        ; NO, SLEEP TIMER ALREADY RUNNING ?
INSLP               lda       #60                 ; NO, INITIALISE SLEEP TIMER
                    sta       SLEPT
                    bset      1,STAT4             ; START SLEEP TIMER
STR2                jsr       CLTR                ; YES, CLEAR DISPLAY TRANSIENTS
                    bset      2,STAT4             ; SLEEP DISPLAY
                    bra       SLPTOK              ; NO DECREMENT IF FIRST TIME

DECS                lda       SLEPT               ; DECREMENT SLEEP TIMER
                    sub       #5
                    sta       SLEPT
                    bmi       INSLP               ; IF UNDERFLOW WRAP ROUND TO 60
SLPTOK              lda       #25
                    sta       DIST
                    bset      0,STAT4             ; START DISPLAY TRANSIENT
                    bra       SODM

;*******************************************************************************
; RDS display key.
;*******************************************************************************

RDS                 brclr     2,PORTE,ALRG        ; ALARM RINGING ?
                    brset     5,STAT4,PINC        ; NO, ALARM SET-UP ?
                    brclr     3,PORTE,SRT3        ; NO, STANDBY ?
                    brset     7,STAT4,NOTRT       ; ALREADY RDS ?
                    brclr     2,STAT2,NORT        ; ALREADY RT DISPLAY ?
NOTRT               bset      7,STAT4             ; SET RDS DISPLAY FLAG
                    lda       RTDIS               ; MOVE ON
                    inca
                    cmp       #19
                    beq       NORT
                    sta       RTDIS
                    lda       #100                ; 12 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ; RE-START TRANSIENT TIMEOUT
SRT3                rts

NORT                jsr       CLTR                ; CLEAR DISPLAY TRANSIENTS
                    bset      2,STAT2             ; SET RT DISPLAY FLAG
                    lda       #9
                    sta       DISP1
                    lda       #1
                    sta       DISP2
                    rts

;*******************************************************************************
; Increment alarm time.
;*******************************************************************************

PINC                brset     6,STAT4,IHR         ; SET-UP HOURS ?
                    lda       AMIN                ; NO, MINUTES
                    cmp       #59
                    bhs       TOOH
                    inc       AMIN
                    bra       T5S

TOOH                clr       AMIN
                    bra       T5S

IHR                 lda       AOUR
                    cmp       #23
                    bhs       HTOH
                    inc       AOUR
T5S                 lda       #80                 ; 10 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ; SET DISPLAY TRANSIENT FLAG
                    rts

HTOH                clr       AOUR
                    bra       T5S

;*******************************************************************************
; Decrement alarm time.
;*******************************************************************************

PDEC                brset     6,STAT4,IHRD        ; SET-UP HOURS ?
                    tst       AMIN                ; NO, MINUTES
                    beq       MZ
                    dec       AMIN
                    bra       T5SD

MZ                  lda       #59
                    sta       AMIN
                    bra       T5SD

IHRD                tst       AOUR
                    beq       HZ
                    dec       AOUR
T5SD                lda       #80                 ; 10 SECOND TIMEOUT
                    sta       DIST
                    bset      0,STAT4             ; SET DISPLAY TRANSIENT FLAG
                    rts

HZ                  lda       #23
                    sta       AOUR
                    bra       T5SD

;*******************************************************************************
; Timer interrupt routine.
;*******************************************************************************

TINTB               inc       DISP1               ; DISP1 DISP2 DISPLAY
                    lda       DISP1               ; 0 -8 0 PTY
                    cmp       #8                  ; 9 -78 1 - 70 MOVING RT
                    bls       NWR                 ; 78 -88 70 END OF RT
                    cmp       #78
                    bhi       NWR                 ; END OF RADIOTEXT ?
                    inc       DISP2               ; NO, MOVE RADIOTEXT ONE CHARACTER
NWR                 cmp       #88                 ; 2 SECONDS AT END OF RADIOTEXT
                    blo       NWR2
                    bclr      2,STAT2             ; RETURN TO NORMAL DISPLAY
NWR2                bclr      5,ICR               ; CLEAR TIMER B INTERRUPT FLAG
                    bset      3,STAT2             ; UPDATE DISPLAY
CLCK                inc       TH8                 ; UPDATE EIGHTHS OF SECONDS
                    dec       DIST                ; DECREMENT TRANSIENT DISPLAY TIMER
                    inc       RDSTO
                    lda       RDSTO
                    cmp       #80                 ; 10S WITHOUT A GROUP 0 OR 15 ?
                    blo       RDSOK
                    bclr      2,STAT3             ; YES, CLEAR TA FLAG
N14B                clr       PTY                 ; PROGRAM TYPE
                    clr       PI                  ; AND
                    clr       PI+1                ; PI CODE
                    clr       PIN                 ; AND
                    clr       PIN+1               ; PIN
                    clr       DI                  ; AND DI
                    bclr      0,STAT3             ; AND M/S
RDSOK               lda       TH8                 ; EIGHTHS OF SECONDS
                    cmp       #8
                    bne       NOTC                ; PAST 7 ?
                    clr       TH8                 ; YES, CLEAR
                    inc       SEC                 ; UPDATE SECONDS
                    lda       SEC
                    cmp       #56
                    bne       NOT5
                    dec       SLEPT               ; DECREMENT SLEEP TIMER MINUTES
NOT5                cmp       #60
                    bne       NOTC                ; PAST 59 ?
                    clr       SEC                 ; YES, CLEAR
                    inc       MIN                 ; UPDATE MINUTES
                    lda       MIN
                    cmp       #60
                    bne       NOTC                ; PAST 59 ?
                    clr       MIN                 ; YES, CLEAR
                    inc       OUR                 ; UPDATE HOURS
                    lda       OUR
                    cmp       #24
                    bne       NOTC                ; PAST 23 ?
                    clr       OUR                 ; YES CLEAR
                    inc       BMJD+2              ; AND ADD A DAY
                    bne       NOTD
                    inc       BMJD+1
                    bne       NOTD                ; INC BMJD only ever executes once, at midnight
                    inc       BMJD                ; on the night of Thu/Fri 22/23 April 2038.
NOTD                bset      6,STAT3             ; UPDATE DATE
NOTC                rti

;*******************************************************************************
; RDS clock interrupt (IRQ).
; Get a bit and calculate syndrome.
;*******************************************************************************

SDATA               brset     2,PORTB,*+3
                    rol       DAT+3
                    rol       DAT+2
                    rol       DAT+1
                    rol       DAT
                    brclr     0,STAT2,TRY2        ; BIT BY BIT CHECK ?
                    dec       BIT                 ; NO, WAIT FOR BIT 26
                    beq       TRY1                ; THIS TIME ?
                    bclr      3,ICR               ; CLEAR IRQ INTERRUPT FLAG
                    rti

TRY1                lda       #26
                    sta       BIT
TRY2                lda       DAT                 ; MSB (2 BITS)
                    and       #3
                    tax
                    lda       DAT+1
                    sta       SYN+1               ; LSB
                    brclr     0,DAT+3,S13
                    lda       SYN+1
                    eor       #$1B
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S13                 brclr     1,DAT+3,S23
                    lda       SYN+1
                    eor       #$8F
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S23                 brclr     2,DAT+3,S43
                    lda       SYN+1
                    eor       #$A7
                    sta       SYN+1
                    txa
                    eor       #$02
                    tax
S43                 brclr     4,DAT+3,S53
                    lda       SYN+1
                    eor       #$EE
                    sta       SYN+1
                    txa
                    eor       #$01
                    tax
S53                 brclr     5,DAT+3,S63
                    lda       SYN+1
                    eor       #$DC
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S63                 brclr     6,DAT+3,S73
                    lda       SYN+1
                    eor       #$01
                    sta       SYN+1
                    txa
                    eor       #$02
                    tax
S73                 brclr     7,DAT+3,S02
                    lda       SYN+1
                    eor       #$BB
                    sta       SYN+1
                    txa
                    eor       #$01
                    tax
S02                 brclr     0,DAT+2,S12
                    lda       SYN+1
                    eor       #$76
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S12                 brclr     1,DAT+2,S22
                    lda       SYN+1
                    eor       #$55
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S22                 brclr     2,DAT+2,S32
                    lda       SYN+1
                    eor       #$13
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S32                 brclr     3,DAT+2,S42
                    lda       SYN+1
                    eor       #$9F
                    sta       SYN+1
                    txa
                    eor       #$03
                    tax
S42                 brclr     4,DAT+2,S62
                    lda       SYN+1
                    eor       #$87
                    sta       SYN+1
                    txa
                    eor       #$02
                    tax
S62                 brclr     6,DAT+2,S72
                    lda       SYN+1
                    eor       #$6E
                    sta       SYN+1
                    txa
                    eor       #$01
                    tax
S72                 brclr     7,DAT+2,S33
                    lda       SYN+1
                    eor       #$DC
                    sta       SYN+1
                    txa
                    eor       #$02
S33                 sta       SYN
                    lda       SYN+1
                    brclr     3,DAT+3,S52
                    eor       #$F7
S52                 brclr     5,DAT+2,FIN
                    eor       #$B7
FIN                 sta       SYN+1

;*******************************************************************************
; Check for syndromes A, B, C & C'.
;*******************************************************************************

                    bclr      3,ICR               ; CLEAR IRQ INTERRUPT FLAG
                    lda       LEV
                    cmp       #3
                    beq       TRYD
                    cmp       #2
                    beq       TRYC
                    cmp       #1
                    beq       TRYB
                    clr       LEV
TRYA                lda       SYN+1               ; BLOCK 1
                    cmp       #$D8
                    bne       NOTV
                    lda       SYN
                    cmp       #$03
                    bne       NOTV
                    bra       VALID

TRYB                lda       SYN+1               ; BLOCK 2
                    cmp       #$D4
                    bne       NOTV
                    lda       SYN
                    cmp       #$03
                    bne       NOTV
                    bra       VALID

TRYC                brset     3,TMPGRP+2,TRYCD    ; BLOCK 3 TYPE A
                    lda       SYN+1
                    cmp       #$5C
                    bne       NOTV
                    lda       SYN
                    cmp       #$02
                    bra       VC

TRYCD               lda       SYN+1               ; BLOCK 3 TYPE B
                    cmp       #$CC
                    bne       NOTV
                    lda       SYN
                    cmp       #$03
VC                  beq       VALID

;*******************************************************************************
; Invalid syndrome handling, check for
; block 4 and save group data if valid.
;*******************************************************************************

NOTV                clr       LEV                 ; RESTART AT BLOCK 1
                    lda       CONF
                    cmp       #41                 ; CONFIDENCE 41 OR GREATER ?
                    bhs       DECC
                    bclr      0,STAT2             ; BIT BY BIT SYNDROME CHECK
                    cmp       #10
                    bls       SKPDC               ; CONFIDENCE 10 OR LESS ?
                    dec       BIT
                    bne       NNOW                ; USE BIT COUNTER TO SLOW CONFIDENCE
                    lda       #26                 ; DROP DURING BIT BY BIT ATTEMPT TO
                    sta       BIT                 ; RE-SYNCRONISE
DECC                dec       CONF
NNOW                rti

SKPDC               bset      4,STAT2             ; 10 OR LESS, INITIALISE DISPLAY
NOT4                rti

TRYD                lda       SYN+1
                    cmp       #$58
                    bne       NOTV
                    lda       SYN
                    cmp       #$02
                    bne       NOTV
                    bset      1,STAT2             ; GROUP COMPLETE
VALID               brset     0,STAT2,VLD         ; VALID SYNDROME FLAG ALREADY SET ?
                    lda       #38                 ; NO,
                    sta       CONF                ; INITIALISE CONFIDENCE (38+4=42)
                    bset      0,STAT2             ; AND SET FLAG
VLD                 lda       CONF
                    cmp       #56
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
                    sta       TMPGRP+1,X
                    lda       DAT+1
                    sta       TMPGRP,X
                    brclr     1,STAT2,NOT4        ; GROUP COMPLETE ?
XFER                ldx       #8
TXLP                lda       TMPGRP-1,X
                    sta       GROUP-1,X
                    decx
                    bne       TXLP

;*******************************************************************************
; Update PI code, initialise if changed.
; All block 1s used, block 3s not used.
;*******************************************************************************

PROC                lda       GROUP               ; COMPARE PI WITH PREVIOUS
                    cmp       PI
                    bne       DNDX
                    lda       GROUP+1
                    cmp       PI+1
                    beq       PTYL
DNDX                lda       GROUP               ; DIFFERENT, SAVE NEW PI
                    sta       PI
                    lda       GROUP+1
                    sta       PI+1
                    jsr       CLREON              ; CLEAR EON,
                    jsr       CLTR                ; TRANSIENTS
                    bset      4,STAT2             ; AND INITIALISE DISPLAY DATA

;*******************************************************************************
; Update PTY and TP.
; All block 2s used, not block 4 (grp 15B).
;*******************************************************************************

PTYL                lda       GROUP+2
                    sta       ITMP1
                    brclr     2,ITMP1,TPL1        ; TP HIGH ?
                    bset      3,STAT3             ; YES, FLAG HIGH
                    bra       TPL

TPL1                bclr      3,STAT3             ; NO, FLAG LOW
TPL                 lda       GROUP+3
                    ror       ITMP1
                    rora
                    lsra
                    lsra
                    lsra
                    lsra
                    sta       PTY

;*******************************************************************************
; Groups handled.
;
; All PI, PTY & TP
; 0 A & B TA, PS, DI & M/S
; 1 A & B PIN
; 2 A RT
; 4 A CT
; 14 A EON
; 15 B TA, DI & M/S
;*******************************************************************************

;*******************************************************************************
; Process groups 0 & 15B (PS & TA).
;*******************************************************************************

                    lda       GROUP+2
                    and       #$F8
                    beq       GRP0                ; GROUP 0A
                    cmp       #$08                ; GROUP 0B
                    beq       GRP0
TGRP15              cmp       #$F8                ; GROUP 15B
                    beq       TACK
                    bra       PROC1

GRP0                lda       GROUP+3             ; GROUP 0 -PS & TA
                    and       #$03
                    lsla
                    tax
                    lda       GROUP+6
                    sta       PSN,X
                    lda       GROUP+7
                    sta       PSN+1,X
TACK                clr       RDSTO               ; RDS OK, RESET TIME-OUT
                    brset     4,GROUP+3,TAH       ; TA HIGH ?
                    bclr      2,STAT3             ; NO, TA FLAG LOW
                    bra       NTD

TAH                 bset      2,STAT3             ; YES, TA FLAG HIGH

;*******************************************************************************
; Process group 0 & 15B (DI & M/S).
;*******************************************************************************

NTD                 lda       GROUP+3             ; DI
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
NOT3                bclr      0,STAT3             ; M/S
                    brclr     3,GROUP+3,MSZ
                    bset      0,STAT3
MSZ                 jmp       OUT1

;*******************************************************************************
; Process group 1 (PIN).
;*******************************************************************************

PROC1               cmp       #$10                ; GROUP 1A
                    beq       GRP1
                    cmp       #$18                ; GROUP 1B
                    bne       PROC2
GRP1                lda       GROUP+6
                    sta       PIN
                    lda       GROUP+7
                    sta       PIN+1
                    jmp       OUT1

;*******************************************************************************
; Process group 2A (RT).
; Group 2B not handled.
;*******************************************************************************

PROC2               cmp       #$20                ; GROUP 2A
                    bne       PROC4
GRP2                brset     4,GROUP+3,TEXTB
TEXTA               brset     1,STAT3,NCH
                    bset      1,STAT3
                    bra       LCDINI

TEXTB               brclr     1,STAT3,NCH
                    bclr      1,STAT3
LCDINI              jsr       INITD
NCH                 lda       GROUP+3             ; GROUP 2A -RT
                    and       #$0F
                    lsla
                    lsla
                    tax
                    lda       GROUP+4
                    sta       RT+5,X
                    lda       GROUP+5
                    sta       RT+6,X
                    lda       GROUP+6
                    sta       RT+7,X
                    lda       GROUP+7
                    sta       RT+8,X
                    jmp       OUT1

;*******************************************************************************
; Process group 4A (CT).
;*******************************************************************************

PROC4               cmp       #$40                ; GROUP 4A -CT
                    beq       GRP4
                    jmp       PROC14

GRP4                lda       GROUP+3
                    rora
                    and       #$01
                    sta       BMJD                ; MJD MS BIT
                    lda       GROUP+4
                    rora
                    sta       BMJD+1              ; MJD MSD
                    lda       GROUP+6             ; GROUP 4
                    ror       GROUP+5             ; 3210xxxx 4
                    rora                          ; 43210xxx x
                    lsra                          ; -43210xx x
                    lsra                          ; --43210x x
                    lsra                          ; ---43210 x
                    sta       OUR
                    lda       GROUP+5
                    sta       BMJD+2              ; MJD LSD
                    lda       GROUP+6             ; xxxx5432 x
                    lsl       GROUP+7             ; xxxx5432 1
                    rola                          ; xxx54321 x
                    lsl       GROUP+7             ; xxx54321 0
                    rola                          ; xx543210 x
                    and       #$3F                ; --543210 x
                    sta       MIN
                    clr       SEC
                    clr       TH8
                    bset      6,STAT3             ; UPDATE MJD

;*******************************************************************************
; Local time difference adjustment.
;*******************************************************************************

LOCAL               lda       GROUP+7
                    lsla
                    beq       OUT1                ; ADJUSTMENT ?
                    bcc       POS                 ; YES, POSITIVE ?
NEG                 lsra                          ; NO, NEGATIVE
                    lsra
                    lsra
                    lsra
                    tax                           ; HOURS IN X
                    bcc       NOTHN               ; 1/2 HOUR ?
                    lda       MIN                 ; YES
                    sub       #30                 ; SUBTRACT 30 MINUTES
                    bpl       LT60                ; UNDERFLOW ?
                    add       #60                 ; YES, ADD 60 MINUTES
                    dec       OUR                 ; AND SUBTRACT 1 HOUR
LT60                sta       MIN
NOTHN               txa                           ; NEGATIVE HOUR OFFSET
                    sub       OUR                 ; MINUS UTC HOURS
                    coma                          ; WRONG WAY ROUND SO COMPLEMENT
                    inca                          ; AND INCREMENT
                    bpl       ZOM                 ; UNDERFLOW ?
                    add       #24                 ; YES, ADD 24 HOURS
                    sta       OUR
                    tst       BMJD+2              ; AND SUBTRACT A DAY
                    bne       TT2                 ; LSB WILL UNDERFLOW ?
                    tst       BMJD+1              ; YES
                    bne       TT1                 ; MSB WILL UNDERFLOW ?
                    dec       BMJD                ; YES DECREMENT MS BIT
TT1                 dec       BMJD+1              ; DECREMENT MSB
TT2                 dec       BMJD+2              ; DECREMENT LSB
                    bra       OUT1

ZOM                 sta       OUR
                    bra       OUT1

POS                 lsra                          ; POSITIVE ADJUSTMENT
                    lsra
                    lsra
                    lsra
                    tax                           ; HOURS IN X
                    bcc       NOTHP               ; HALF HOUR ?
                    lda       #30                 ; YES, ADD 30 MINUTES
                    add       MIN
                    cmp       #59
                    bls       HDON                ; OVERFLOW ?
                    sub       #60                 ; YES, SUBTRACT 60 MINUTES
                    inc       OUR                 ; AND ADD AN HOUR
HDON                sta       MIN
NOTHP               txa                           ; HOUR OFFSET
                    add       OUR                 ; ADD UTC HOURS
                    cmp       #23
                    bls       ADDON               ; OVERFLOW ?
                    sub       #24                 ; YES, SUBTRACT 24 HOURS
                    inc       BMJD+2              ; AND ADD A DAY
                    bne       ADDON
                    inc       BMJD+1
                    bne       ADDON
                    inc       BMJD
ADDON               sta       OUR
OUT1                bclr      1,STAT2             ; GROUP HANDLED, CLEAR FLAG
                    rti

;*******************************************************************************
; Process group 14 (EON).
;*******************************************************************************

PROC14              cmp       #$E0
                    beq       GRP14A
                    jmp       OUT2

GRP14A              clr       ITMP1               ; LOOK FOR PI CODE IN TABLE
LPIL                ldx       ITMP1
                    lda       EON,X
                    cmp       GROUP+6
                    bne       NOTH
                    lda       EON+1,X
                    cmp       GROUP+7
                    bne       NOTH
;                   lda       GROUP+3             ; TP (ON), NOT USED
;                   and       #$10
;                   ldx       ITMP1
;                   sta       EON+11,X
                    lda       GROUP+3             ; PI CODE FOUND
                    and       #$0F
                    cmp       #4                  ; PS ?
                    bhs       NPS
                    lsla                          ; YES
                    add       ITMP1
                    tax
                    lda       GROUP+4
                    sta       EON+2,X             ; SAVE 2 PS-NAME CHARACTERS
                    lda       GROUP+5
                    sta       EON+3,X
                    bra       OUT1

NPS                 cmp       #4                  ; AF ?
                    bne       TRYPIN
                    lda       GROUP+4             ; YES, METHOD A
                    cmp       #250
                    bne       NMLW                ; MEDIUM OR LONG WAVE ?
                    lda       EON+12,X            ; YES
                    cmp       #$FF                ; FIRST 2 BYTES ALREADY IN ?
                    beq       OUT2                ; IF NOT, DO NOTHING
                    lda       EON+14,X            ; YES
                    cmp       #$FF                ; M/L FREQUENCY ALREADY IN ?
                    bne       OUT2                ; IF SO, DO NOTHING
                    lda       #250                ; NO, STORE FIRST FREQUENCY AFTER
                    sta       EON+14,X            ; ARRIVAL OF INITIAL BYTES
                    lda       GROUP+5
                    sta       EON+15,X
                    bra       OUT2

NMLW                cmp       #224                ; FM
                    blo       TOOLS               ; LEGAL ? (No. OF FREQUENCIES)
                    cmp       #249
                    bhi       TOOLS
                    ldx       ITMP1
                    sta       EON+12,X            ; YES, SAVE No. OF FREQUENCIES
                    lda       GROUP+5
                    sta       EON+13,X            ; AND FIRST FREQUENCY
TOOLS               bra       OUT2

;TRYPTY             cmp       #$0D
;                   bne       TRYPIN
;                   lda       GROUP+4             ; PTY (EON), NOT USED
;                   lsra
;                   lsra
;                   lsra
;                   ldx       ITMP1
;                   sta       EON+10,X
;                   bra       OUT2
TRYPIN              cmp       #$0E
                    bne       OUT2
                    ldx       ITMP1               ; PIN
                    lda       GROUP+4
                    sta       EON+10,X
                    lda       GROUP+5
                    sta       EON+11,X
                    bra       OUT2

NOTH                cmp       #$FF                ; END OF PI LIST ?
                    bne       NOTH1
                    lda       GROUP+6             ; YES, ADD THIS PI CODE
                    sta       EON,X
                    lda       GROUP+7             ; TO EON TABLE
                    sta       EON+1,X
                    bra       OUT2

NOTH1               lda       ITMP1               ; NOT END, TRY NEXT ENTRY
                    add       #16
                    sta       ITMP1
                    cmp       #$B0                ; END OF TABLE (11 ENTRIES) ?
                    beq       OUT2
                    jmp       LPIL

OUT2                bclr      1,STAT2             ; GROUP HANDLED, CLEAR FLAG
                    rti

;*******************************************************************************
; Display type selection.
;*******************************************************************************

MOD                 brclr     4,STAT2,NOCL        ; SHOULD DISPALY BE INITIALISED ?
                    jsr       INITD               ; YES, DO IT
                    bclr      4,STAT2             ; AND CLEAR FLAG
NOCL                jsr       WAIT
                    lda       #$0C                ; SWITCH DISPLAY ON
                    jsr       CLOCK               ; LATCH IT
                    jsr       WAIT
;                   lda       #$38                ; /16 DISPLAY
                    lda       #$30                ; /8 DISPLAY
                    jsr       CLOCK               ; LATCH IT
                    jsr       WAIT
                    lda       #$80                ; ADDRESS DISPLAY RAM
                    jsr       CLOCK               ; LATCH IT
                    brset     3,PORTE,TRYRT       ; STANDBY ?
                    brset     2,STAT4,SLPD        ; YES, SLEEP DISPLAY ?
                    brset     3,STAT4,ALRMJ       ; NO, ALARM DISPLAY ?
                    jsr       STBYD               ; NO, NORMAL STANDBY DISPLAY
                    bra       ROW1

TRYRT               brclr     7,STAT4,RTITS       ; RDS DISPLAYS ?
                    lda       RTDIS
                    cmp       #1
                    bne       NPTY
                    jsr       PTYD                ; PTY
                    bra       ROW1

NPTY                cmp       #2
                    bne       NPI
                    jsr       DIPI                ; PI
                    bra       ROW1

NPI                 cmp       #3
                    bne       NTAP
                    jsr       DITAP               ; TA & TP
                    bra       ROW1

NTAP                cmp       #4
                    bne       NPIN1
                    jsr       DPIN1               ; PIN - HEX
                    bra       ROW1

NPIN1               cmp       #5
                    bne       NPIN2
                    jsr       DPIN2               ; PIN - DAY AND TIME
                    bra       ROW1

NPIN2               cmp       #6
                    bne       NMJD
                    jsr       DMJD                ; MJD
                    bra       ROW1

NMJD                cmp       #7
                    bne       NMSD
                    jsr       DMSD                ; M/S & DI
                    bra       ROW1

NMSD                jsr       DEON
                    bra       ROW1

RTITS               brclr     2,STAT2,SLPD        ; RT DISPLAY ?
                    jsr       RTDS
                    bra       ROW1

SLPD                brclr     2,STAT4,NRMD        ; SLEEP TIMER DISPLAY ?
                    jsr       SLEEPD
                    bra       ROW1

NRMD                brset     3,STAT4,ALRMJ       ; ALARM DISPLAY ?
                    jsr       NORMD
                    bra       ROW1

ALRMJ               jsr       ALRMD
ROW1                clrx
LCD                 jsr       WAIT
                    bset      2,PORTD             ; WRITE DATA
                    lda       DISP,X              ; GET A BYTE
                    cmp       #$FF
                    bne       COK
                    lda       #$2D
COK                 jsr       CLOCK               ; SEND IT TO MODULE
                    incx
                    cpx       #16                 ; DONE ?
                    bne       LCD
                    bra       VFD                 ; REMOVE FOR /16 LCDs

;*******************************************************************************
; Additional bits for /16 LCD modules.
;*******************************************************************************

LCD401              jsr       WAIT
                    lda       #$A8                ; TO 40
                    jsr       CLOCK               ; SEND IT TO MODULE
                    clrx
LCD41               jsr       WAIT
                    bset      2,PORTD             ; WRITE DATA
                    lda       DISP+8,X            ; GET A BYTE
                    cmp       #$FF
                    bne       COK2
                    lda       #$2D
COK2                jsr       CLOCK               ; SEND IT TO MODULE
                    incx
                    cpx       #8                  ; DONE ?
                    bne       LCD41

;*******************************************************************************
; VFD.
;*******************************************************************************

VFD                 bclr      1,PORTB             ; DATA LOW ?
                    bset      0,PORTB             ; CLOCK HIGH ?
                    bclr      3,PORTB             ; ENABLE LOW
                    clrx                          ; SEND VFD SET-UP BYTES
DIS5                lda       INITF,X
                    stx       W7                  ; SAVE INDEX
                    bsr       VFDL
                    cpx       #7
                    bne       DIS5                ; LAST BYTE ?
                    clrx                          ; SEND 16 CHARACTER BYTES
VFD3                stx       W7                  ; SAVE INDEX
                    lda       DISP,X              ; ASCII
                    cmp       #$FF
                    bne       NOTFF
                    lda       #$2D                ; REPLACE $FF WITH "-"
NOTFF               and       #$7F                ; IGNORE BIT 7
                    tax
                    lda       VTAB,X              ; CONVERT TO VFD CHARACTER SET
                    bsr       VFDL
                    cpx       #16
                    bne       VFD3                ; LAST BYTE ?
                    bset      3,PORTB             ; ENABLE HIGH
                    bclr      0,PORTB             ; CLOCK LOW ?
                    rts

VFDL                ldx       #8
DIS3                lsra                          ; GET A BIT
                    bcc       DIS4
                    bset      1,PORTB             ; DATA HIGH
DIS4                bclr      0,PORTB             ; CLOCK
                    bset      0,PORTB             ; IT
                    bclr      1,PORTB             ; CLEAR DATA
                    decx                          ; COMPLETE ?
                    bne       DIS3                ; NO
                    ldx       #64
DEL                 decx                          ; WAIT 200uS
                    bne       DEL
                    ldx       W7                  ; RESTORE INDEX
                    incx
                    rts

INITF               fcb       $A0,$0F,$B0,$00,$80,$00,$90

;*******************************************************************************
; Normal display (PS and time).
;*******************************************************************************

NORMD               lda       #$20
                    sta       DISP
                    sta       DISP+9
                    sta       DISP+15
                    lda       #$2E                ; .
                    brclr     1,STAT4,TYP1        ; DP TO INDICATE SLEEP TIMER RUNNING
                    brclr     2,TH8,TYP1          ; FLASH IT
                    sta       DISP+15
TYP1                clrx
MPS                 lda       PSN,X               ; GET PS NAME
                    sta       DISP+1,X
SCNG                incx
                    cpx       #7
                    bls       MPS
                    lda       OUR                 ; GET TIME
                    jsr       CBCD
                    cpx       #$30                ; LEADING ZERO ?
                    bne       TNZ
                    ldx       #$20                ; YES, MAKE IT A SPACE
TNZ                 stx       DISP+10
                    sta       DISP+11
CMIN                lda       MIN
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
CSEC                lda       #$20
                    brclr     2,TH8,DDC
                    lda       #$3A                ; 0.5 Hz FLASHING COLON
DDC                 sta       DISP+12
                    rts

;*******************************************************************************
; Clear display transient flags.
;*******************************************************************************

CLTR                bclr      0,STAT4             ; CLEAR DISPLAY TRANSIENT FLAG
                    bclr      2,STAT2             ; NOT RT DISPLAY
                    clr       RTDIS               ; CLEAR RDS DISPLAY INDEX
                    bclr      3,STAT4             ; NOT ALARM DISPLAY
                    bclr      5,STAT4             ; NOT ALARM SET-UP
                    bclr      7,STAT4             ; NOT RDS DISPLAYS
                    bclr      2,STAT4             ; NOT SLEEP TIMER DISPLAY
                    rts

;*******************************************************************************
; PTY display.
;*******************************************************************************

PTYD                ldx       PTY                 ; PTY
                    cpx       #16
                    blo       XOK2
                    clrx
XOK2                lda       #16
                    mul
                    sta       W8
                    clr       W7
LCD3                ldx       W8
                    lda       PTYT,X
                    ldx       W7
                    sta       DISP,X              ; WAS MOD2
                    inc       W8
                    inc       W7
                    lda       W7
                    cmp       #16
                    blo       LCD3
                    rts

;*******************************************************************************
; RDS display.
;*******************************************************************************

NXTC                ldx       DISP2
                    lda       RT-1,X              ; RT
                    cmp       #$20
                    bne       NOTSP               ; SPACE ?
                    brclr     5,STAT2,FSP         ; YES, FIRST ONE ?
                    inc       DISP1               ; NO, SKIP THIS ONE
                    inc       DISP2
RTDS                lda       DISP2
SKP1                cmp       #69
                    bhi       LCD4                ; END OF RT BUFFER
                    bra       NXTC                ; NO, GET NEXT CHARACTER

FSP                 bset      5,STAT2             ; FIRST SPACE, SET FLAG
                    bra       CONT

NOTSP               bclr      5,STAT2             ; NOT A SPACE, CLEAR FLAG
CONT                sta       W8                  ; SAVE NEW CHARACTER
                    clrx
ILP1                lda       DISP+1,X            ; MOVE
                    sta       DISP,X              ; REST
                    incx                          ; LEFT
                    cpx       #15                 ; ONE
                    bne       ILP1                ; PLACE
                    lda       W8
                    sta       DISP+15             ; ADD NEW CHAR. (WAS MOD2)
LCD4                rts

;*******************************************************************************
; Standby display.
;*******************************************************************************

STBYD               brset     4,STAT4,ALRMA       ; ALARM ARMED ?
                    lda       DOW                 ; NO, GET DAY OF WEEK
                    lsla
                    add       DOW
                    tax
                    lda       DNAME,X
                    sta       DISP
                    lda       DNAME+1,X
                    sta       DISP+1
                    lda       DNAME+2,X
                    sta       DISP+2
                    lda       #$20
                    sta       DISP+3
                    sta       DISP+6
                    sta       DISP+10
                    lda       DOM+1               ; DATE
                    add       #$30
                    sta       DISP+5
                    lda       DOM
                    beq       ADD20               ; IF ZERO USE A SPACE
                    add       #$10                ; IF NOT MAKE ASCII
ADD20               add       #$20
                    sta       DISP+4
                    ldx       MNTH+1              ; MONTH, LSD
                    lda       MNTH                ; MONTH, MSD
                    beq       MTHZ
                    txa
                    add       #10
                    tax
MTHZ                stx       W8
                    txa
                    lsla
                    add       W8
                    tax
                    lda       MNAME-3,X
                    sta       DISP+7
                    lda       MNAME-2,X
                    sta       DISP+8
                    lda       MNAME-1,X
                    sta       DISP+9
                    bra       STIME

;*******************************************************************************
; Standby (alarm armed) display.
;*******************************************************************************

ALRMA               lda       AOUR                ; GET ALARM HOURS
                    jsr       CBCD
                    stx       DISP
                    sta       DISP+1
                    lda       AMIN
                    jsr       CBCD
                    stx       DISP+2
                    sta       DISP+3
                    clrx
ALOP2               lda       ALARMS+1,X
                    sta       DISP+4,X
                    incx
                    cpx       #6
                    bls       ALOP2
STIME               lda       OUR                 ; GET TIME
                    jsr       CBCD
                    cpx       #$30                ; LEADING ZERO ?
                    bne       TMZ
                    ldx       #$20                ; YES, MAKE IT A SPACE
TMZ                 stx       DISP+11
                    sta       DISP+12
                    lda       MIN
                    jsr       CBCD
                    stx       DISP+14
                    sta       DISP+15
                    lda       #$20
                    brclr     2,TH8,DTF           ; FLASH ?
                    lda       #$3A                ; 0.5 Hz FLASHING COLON
DTF                 sta       DISP+13
                    rts

;*******************************************************************************
; PI display.
;*******************************************************************************

DIPI                clrx
DLOP                lda       PIST,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       DLOP
                    lda       PI
                    beq       PINV
                    jsr       SPLIT
                    stx       DISP+11
                    sta       DISP+12
                    lda       PI+1
                    jsr       SPLIT
                    stx       DISP+13
                    sta       DISP+14
PINV                rts

;*******************************************************************************
; Alarm display.
;*******************************************************************************

ALRMD               clrx                          ; YES
ALOP                lda       ALARMS,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       ALOP
                    brclr     4,STAT4,ALOF2       ; ALARM ARMED ?
                    lda       #$3A                ; YES
                    sta       DISP+12
                    lda       AOUR                ; GET ALARM HOURS
                    jsr       CBCD
                    cpx       #$30                ; LEADING ZERO ?
                    bne       TN3
                    ldx       #$20                ; YES, MAKE IT A SPACE
TN3                 stx       DISP+10
                    sta       DISP+11
                    lda       AMIN
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
                    brclr     5,STAT4,ALOF2       ; SET-UP ?
                    brclr     2,TH8,ALOF2
                    lda       #$20
                    brset     6,STAT4,FH          ; HOURS ?
                    sta       DISP+13             ; NO, FLASH MINUTES
                    sta       DISP+14
                    bra       ALOF2

FH                  sta       DISP+10             ; YES, FLASH HOURS
                    sta       DISP+11
ALOF2               rts

;*******************************************************************************
; TA & TP flags display.
;*******************************************************************************

DITAP               clrx
BLOP                lda       TAPST,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       BLOP
                    lda       #$31
                    brclr     3,STAT3,TPLOW       ; TP FLAG HIGH ?
                    sta       DISP+6              ; YES, DISPLAY A 1
TPLOW               brclr     2,STAT3,TALOW       ; TA FLAG HIGH ?
                    sta       DISP+14             ; YES, DISPLAY A 1
TALOW               rts

;*******************************************************************************
; PIN displays.
;*******************************************************************************

DPIN1               clrx
PLOP                lda       PINST1,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       PLOP
                    lda       PIN
                    beq       PINNV
                    jsr       SPLIT
                    stx       DISP+11
                    sta       DISP+12
                    lda       PIN+1
                    jsr       SPLIT
                    stx       DISP+13
                    sta       DISP+14
PINNV               rts

DPIN2               clrx
PLOP2               lda       PINST2,X
                    sta       DISP,X
INCX
                    cpx       #15
                    bls       PLOP2
                    lda       PIN                 ; DATE
                    beq       PINNV
                    lsra
                    lsra
                    lsra
                    jsr       CBCD
                    cpx       #$30
                    bne       DTN0
                    ldx       #$20
DTN0                stx       DISP+2
                    sta       DISP+3
                    cpx       #$31
                    beq       NOTRD
                    cmp       #$31
                    bne       NOTST
                    lda       #'s'
                    sta       DISP+4
                    lda       #'t'
                    sta       DISP+5
NOTST               cmp       #$32
                    bne       NOTND
                    lda       #'n'
                    sta       DISP+4
                    lda       #'d'
                    sta       DISP+5
NOTND               cmp       #$33
                    bne       NOTRD
                    lda       #'r'
                    sta       DISP+4
                    lda       #'d'
                    sta       DISP+5
NOTRD               lda       PIN                 ; HOURS
                    and       #7
                    ldx       PIN+1
                    aslx
                    rola
                    aslx
                    rola
                    jsr       CBCD
                    stx       DISP+10
                    sta       DISP+11
                    lda       PIN+1               ; MINUTES
                    and       #$3F
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
                    rts

;*******************************************************************************
; MJD display.
;*******************************************************************************

DMJD                bsr       SMJD
                    lda       MJD
                    beq       MJDNV
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
MJDNV               rts

SMJD                clrx
MLOP                lda       MJDST,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       MLOP
                    rts

;*******************************************************************************
; EON display.
;*******************************************************************************

DEON                jsr       SMJD                ; CLEAR FREQUENCY CHARACTERS
                    lda       RTDIS
                    sub       #8
                    ldx       #16
                    mul
                    tax
                    lda       #$20
                    sta       DISP+8
                    sta       DISP+9
                    lda       EON+2,X             ; DISPLAY PS (EON)
                    sta       DISP
                    lda       EON+3,X
                    sta       DISP+1
                    lda       EON+4,X
                    sta       DISP+2
                    lda       EON+5,X
                    sta       DISP+3
                    lda       EON+6,X
                    sta       DISP+4
                    lda       EON+7,X
                    sta       DISP+5
                    lda       EON+8,X
                    sta       DISP+6
                    lda       EON+9,X
                    sta       DISP+7
                    lda       EON+13,X
                    cmp       #205                ; FILLER ?
                    bne       NFIL
                    incx
                    lda       EON+13,X            ; YES, TRY AGAIN
NFIL                cmp       #250                ; MEDIUM/LONG ?
                    beq       MLWF
                    cmp       #204                ; NO, FREQUENCY OK ?
                    bhi       FNOK2
FOK2                ldx       #10                 ; VHF
                    mul
                    add       #$2E                ; CALCULATE FREQUENCY (BINARY)
                    sta       W1
                    txa
                    adc       #$22
                    sta       W2
                    jsr       DCON2               ; CONVERT TO DECIMAL
TYPE3               lda       Q+4                 ; DISPLAY VHF EON FREQUENCY
                    bne       NZ1
                    lda       #$F0
NZ1                 add       #$30
                    sta       DISP+10
                    tax
                    lda       Q+5
                    bne       NZ2
                    cpx       #$20
                    bne       NZ2
                    lda       #$F0
NZ2                 add       #$30
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
FNOK2               rts

MLWF                incx                          ; DISPLAY M/L EON FREQUENCY
                    lda       EON+13,X
                    cmp       #15
                    bls       LONG
                    add       #27                 ; MW OFFSET
LONG                add       #16                 ; M/L OFFSET
                    ldx       #9
                    mul
                    stx       W2
                    sta       W1
                    bsr       DCON2               ; CONVERT TO BCD IN Q
                    lda       Q+5
                    bne       NZ3                 ; IF THOUSANDS OF kHz A ZERO
                    lda       #$F0                ; DISPLAY AS A SPACE
NZ3                 add       #$30
                    sta       DISP+9
                    lda       Q+6
                    add       #$30
                    sta       DISP+10
                    lda       Q+7
                    add       #$30
                    sta       DISP+11
                    lda       Q+8
                    add       #$30
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

SLEEPD              clrx
SLOP                lda       SLPST,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       SLOP
                    lda       SLEPT
                    jsr       CBCD
                    stx       DISP+8
                    sta       DISP+9
                    rts

;*******************************************************************************
; M/S & DI display.
;*******************************************************************************

DMSD                clrx
ILOP                lda       MSDST,X
                    sta       DISP,X
                    incx
                    cpx       #15
                    bls       ILOP
                    brclr     0,STAT3,MSM2        ; M/S FLAG SET
                    lda       #'M'                ; YES, MUSIC
                    sta       DISP+6
MSM2                lda       DI
                    jsr       CBCD
                    stx       DISP+13
                    sta       DISP+14
                    rts

;*******************************************************************************
; Convert binary to unpacked BCD in Q.
;*******************************************************************************

DCON2               ldx       #R                  ; CLEAR
                    stx       NUM1
                    jsr       CLRAS               ; RR
                    inc       R+8                 ; R <- 1
                    jsr       CLQ                 ; CLEAR RQ
                    lda       #14                 ; 14 BITS TO CONVERT
                    sta       W6
LOOP2               lsr       W2                  ; MOVE OUT
                    ror       W1                  ; FIRST (LS) BIT
                    bcc       NXT                 ; ZERO
                    ldx       #Q                  ; ONE, ADD
                    stx       NUM2                ; CURRENT VALUE
                    jsr       ADD                 ; OF R
NXT                 ldx       #R                  ; ADD R
                    stx       NUM2                ; TO
                    jsr       ADD                 ; ITSELF
                    dec       W6                  ; ALL
                    bne       LOOP2               ; DONE ?
                    rts

;*******************************************************************************
; Split A nibbles into A (LS) and X (MS)
; and convert to ASCII.
;*******************************************************************************

SPLIT               tax                           ; MSD INTO X, LSD INTO A
                    sec
                    rorx
                    sec
                    rorx
                    lsrx
                    lsrx
                    cpx       #$39                ; $30-$39 <- 0-9
                    bls       XOK
                    incx
                    incx
                    incx
                    incx
                    incx
                    incx
                    incx
XOK                 and       #$0F                ; $41-$46 <- A-F
                    add       #$30
                    cmp       #$39
                    bls       AOK
                    add       #7
AOK                 rts

;*******************************************************************************
; Send and clock data to LCD module.
; Check to see if LCD module is busy.
;*******************************************************************************

CLOCK               sta       PORTC
                    bset      4,PORTD
                    bclr      4,PORTD             ; CLOCK IT
                    rts

WAIT                bclr      2,PORTD
                    bset      3,PORTD             ; READ LCD MODULE BUSY FLAG
                    bclr      4,PORTD
                    clr       PORTCD              ; INPUT ON PORTC
WLOOP               bset      4,PORTD             ; CLOCK HIGH
                    lda       PORTC               ; READ MODULE
                    bclr      4,PORTD             ; CLOCK LOW
                    sta       W7
                    brset     7,W7,WLOOP          ; BUSY ?
                    com       PORTCD              ; OUTPUT ON PORTC
                    bclr      3,PORTD
                    rts

;*******************************************************************************
; Hex->BCD conversion (& decimal adjust).
;*******************************************************************************

CBCD                bsr       UPX
                    bsr       ADJI                ; DECIMAL ADJUST
BCD                 sta       W7                  ; SAVE
                    add       #$16                ; ADD $16 (BCD 10)
                    bsr       ADJU                ; ADJUST
                    decx
                    bpl       BCD                 ; TOO FAR ?
                    lda       W7                  ; YES, RESTORE A
                    jmp       SPLIT

ADJU                bhcc      ADJI                ; OVERFLOW ?
                    add       #6                  ; YES
                    rts

ADJI                add       #6                  ; NO, BUT IS LS DIGIT
                    bhcs      ARTS                ; BIGGER THAN 9 ?
                    sub       #6                  ; NO, RESTORE
ARTS                rts

UPX                 tax
                    lsrx
                    lsrx
                    lsrx
                    lsrx      MSB                 ; IN X
                    and       #$0F                ; LSB IN A
                    rts

;*******************************************************************************
; LCD initialisation.
;*******************************************************************************

INITD               lda       #$A0
                    sta       RT                  ; SPACES BETWEEN PTY & RT
                    sta       RT+1
                    sta       RT+3
                    sta       RT+4
                    lda       #$2D
                    sta       RT+2                ; DASH BETWEEN EXISTING DISPLAY & RT
                    lda       #$20                ; INITIALISE RADIOTEXT TO SPACES
                    ldx       #5                  ; AFTER CONF LOSS OR TEXT A/B CHANGE
CLOP                sta       RT,X
                    incx
                    cpx       #69
                    bne       CLOP
                    clr       DISP1               ; INITIALISE SCROLLING POINTERS
                    clr       DISP2
                    clr       PTY                 ; CLEAR PTY
                    clr       PIN                 ; AND
                    clr       PIN+1               ; PIN
                    clr       DI                  ; AND DI
                    bclr      0,STAT3             ; AND M/S
                    bclr      3,STAT3             ; CLEAR TP FLAG
                    bclr      2,STAT2             ; CANCEL RT DISPLAY
                    clrx
                    lda       #$2D
PLOP3               sta       PSN,X               ; CLEAR PS NAME
                    incx
                    cpx       #8
                    bne       PLOP3
                    rts

CLREON              clrx
                    lda       #$FF
ELOP                sta       EON,X               ; EON RAM CLEAR
                    incx
                    cpx       #176
                    bne       ELOP
                    rts

;*******************************************************************************
; Display strings.
;*******************************************************************************

ALARMS              fcc       ' Alarm -OFF '
PIST                fcc       ' PI code -'
TAPST               fcc       ' TP - 0 TA - 0 '
PINST1              fcc       ' PIN no. -'
PINST2              fcc       ' th at --.-- '
MJDST               fcc       ' MJ day -'
SLPST               fcc       ' Sleep 0 min. '
MSDST               fcc       ' M/S S DI 0 '

;*******************************************************************************
; MJD day and month strings.
;*******************************************************************************

DNAME               fcc       'MonTueWedThuFriSatSun'
                    fcc       'inv'
MNAME               fcc       'JanFebMarAprMayJunJulAugSepOctNovDec'

;*******************************************************************************
; Programme Type (PTY) Codes.
;*******************************************************************************

PTYT                fcc       'no program type '  ; 0
                    fcc       ' News '            ; 1
                    fcc       'Current affairs '  ; 2
                    fcc       ' Information '     ; 3
                    fcc       ' Sport '           ; 4
                    fcc       ' Education '       ; 5
                    fcc       ' Drama '           ; 6
                    fcc       ' Culture '         ; 7
                    fcc       ' Science '         ; 8
                    fcc       ' Varied '          ; 9
                    fcc       ' Pop music '       ; 10
                    fcc       ' Rock music '      ; 11
                    fcc       ' Easy listening '  ; 12
                    fcc       ' Light classics '  ; 13
                    fcc       'Serious classics'  ; 14
                    fcc       ' Other music '     ; 15

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

VTAB                fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7E,$7E,$7E     ; all
                    fcb       $7E,$7B,$7A,$7E     ; ! " # #
                    fcb       $7E,$7E,$7E,$7A     ; $ % & ' $%&
                    fcb       $7E,$7E,$7E,$7E     ; ( ) * + all
                    fcb       $3F,$7D,$3E,$7D     ; , - . /
                    fcb       $00,$01,$02,$03     ; 0 1 2 3
                    fcb       $04,$05,$06,$07     ; 4 5 6 7
                    fcb       $08,$09,$7D,$7E     ; 8 9 : ; ;
                    fcb       $7E,$7E,$7E,$7C     ; < = > ? <=>
                    fcb       $7E,$0A,$0B,$0C     ; @ A B C @
                    fcb       $0D,$0E,$0F,$10     ; D E F G
                    fcb       $11,$12,$13,$14     ; H I J K
                    fcb       $15,$16,$17,$18     ; L M N O
                    fcb       $19,$1A,$1B,$1C     ; P Q R S
                    fcb       $1D,$1E,$1F,$20     ; T U V W
                    fcb       $21,$22,$23,$7E     ; X Y Z [ [
                    fcb       $7E,$7E,$7E,$7D     ; \ ] ^ -\]^
                    fcb       $7A,$24,$25,$26     ; ' a b c
                    fcb       $27,$28,$29,$2A     ; d e f g
                    fcb       $2B,$2C,$2D,$2E     ; h i j k
                    fcb       $2F,$30,$31,$32     ; l m n o
                    fcb       $33,$34,$35,$36     ; p q r s
                    fcb       $37,$38,$39,$3A     ; t u v w
                    fcb       $3B,$3C,$3D,$7E     ; x y z { {
                    fcb       $7E,$7E,$7E,$7E     ; | } ~ all

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

TRA                 stx       NUM2                ; CLEAR DESTINATION
                    jsr       CLRAS               ; AND ADD IT TO No. AT NUM1

;*******************************************************************************
; Addition of BCD numbers.
;
; (X) <- (NUM1) + (NUM2), X preserved
;*******************************************************************************

ADD                 clr       CARRY
                    stx       W7
AD                  stx       W5                  ; ANSWER POINTER
                    lda       #ND
                    sta       COUNT
                    ldx       NUM1                ; 1st No. POINTER
                    stx       W3
                    ldx       NUM2                ; 2nd No. POINTER
                    stx       W4
LOOP                ldx       W3
                    lda       ND-1,X
                    dec       W3
                    ldx       W4
                    add       ND-1,X              ; ADD
                    dec       W4
                    add       CARRY               ; SET ON ADDITION OVERFLOW
                    clr       CARRY               ; OR POS. RESULT SUBTRACTION
                    bsr       ADJ                 ; DECIMAL ADJUST
                    ldx       W5
                    sta       ND-1,X              ; SAVE ANSWER
                    dec       W5
                    dec       COUNT
                    bne       LOOP                ; DONE ?
                    ldx       W7
                    rts

AJ                  sub       #10                 ; YES, SUTRACT 10
                    inc       CARRY               ; AND RECORD CARRY
ADJ                 cmp       #10
                    bhs       AJ                  ; 10 OR MORE ?
                    rts                           ; NO

;*******************************************************************************
; Subtraction, complementing and incre-
; menting (X=REG-ND) of BCD numbers.
;
; (X) <- (NUM1) - (NUM2), X preserved.
; (X and NUM2 should not be equal)
;*******************************************************************************

SUB                 stx       W6                  ; ANSWER POINTER
                    bsr       COM2                ; 9S COMP. SECOND NUMBER
                    clr       CARRY               ; SET CARRY TO ONE
                    inc       CARRY               ; BEFORE ADDING
                    bsr       AD                  ; ADD FIRST NUMBER
COM2                ldx       NUM2                ; 9S COMPLIMENT
                    bsr       COMP                ; SECOND NUMBER
                    ldx       W6                  ; RESTORE ANSWER POINTER
                    rts

COMP                lda       #ND                 ; 9S COMPLIMENT
                    sta       COUNT
LOOP3               lda       #$09
                    sub       ND-1,X
                    sta       ND-1,X
                    decx
                    dec       COUNT
                    bne       LOOP3
                    rts

COM10               bsr       COMP                ; NINES COMPLIMENT THEN
ADD1                lda       #ND                 ; ADD 1 FOR TENS COMPLIMENT
                    sta       COUNT               ; ENTER WITH X = REG-ND
ADD2                inc       2*ND-1,X
                    lda       2*ND-1,X
                    cmp       #$0A
                    blo       RETURN
                    sub       #10
                    sta       2*ND-1,X
                    decx
                    dec       COUNT
                    bne       ADD2
RETURN              rts

;*******************************************************************************
; Mult., R <- P x Q, over. in TMP, X = #R.
;*******************************************************************************

MULT                ldx       #R
                    jsr       CLRAS
                    ldx       #TMP
                    jsr       CLRAS               ; CLEAR RESULT
                    ldx       #2*ND
                    stx       W6                  ; INIT. R POINTER
                    ldx       #ND
STR                 lda       P-1,X
                    stx       W1                  ; SAVE P POINTER
                    sta       CARRY               ; SAVE P
                    ldx       #ND                 ; INIT. Q POINTER
XTT                 lda       Q-1,X
                    sta       W4                  ; SAVE Q
                    beq       TZ0                 ; IF ZERO GOTO NEXT Q
                    lda       CARRY               ; RECALL P
                    sta       W3                  ; SAVE P
                    clra
PLY                 lsr       CARRY               ; RIGHT SHIFT INTO C
                    bcc       SHF                 ; C = ZERO ?
                    add       W4                  ; NO, A=A+Q
SHF                 tst       CARRY               ; ZERO ?
                    beq       C4                  ; YES, FINISHED WITH THIS Q
                    asl       W4                  ; NO, LEFT SHIFT Q
                    bra       PLY

C4                  decx                          ; Q = Q + 1
                    stx       W2                  ; SAVE Q POINTER
                    ldx       W6                  ; R POINTER
                    add       R-ND-1,X            ; ADD R TO A
                    jsr       ADJ                 ; ADJUST
                    sta       R-ND-1,X            ; R = R + A
                    lda       CARRY
                    add       R-ND-2,X            ; ADD R-(ND+2) TO CARRY
                    sta       R-ND-2,X            ; R-(ND+2) = R-(ND+2) + CARRY
                    lda       W3                  ; RECALL P
                    sta       CARRY               ; SAVE IN CARRY
                    decx
                    stx       W6                  ; SAVE R POINTER
                    ldx       W2                  ; Q POINTER
                    bra       C3

TZ0                 dec       W6                  ; DEC. R POINTER
                    decx                          ; DEC. Q POINTER
C3                  bne       XTT
                    lda       W6                  ; R POINTER
                    add       #ND-1
                    sta       W6                  ; R = R + ND-1
                    ldx       W1
                    decx                          ; P = P + 1
                    bne       STR                 ; IF NOT ZERO GOTO NEXT P
                    ldx       #R
                    rts

;*******************************************************************************
; Division of BCD numbers.
;
; R <- P / Q, remainder in TMP.
; on exit X = #R, TMQ used.
;*******************************************************************************

DIV                 ldx       #R                  ; CLEAR
                    jsr       CLRAS               ; RESULT
                    ldx       #P                  ; TRANSFER
                    stx       NUM1                ; P TO
                    ldx       #TMP                ; WORKING
                    jsr       TRA                 ; P (TMP)
                    ldx       #Q                  ; TRANSFER
                    stx       NUM1                ; Q TO
                    ldx       #TMQ                ; WORKING
                    jsr       TRA                 ; Q (TMQ)
POSS                lda       #ND                 ; NUMBER
                    sta       COUNT               ; DIGITS
LOOP6               ldx       #TMQ                ; FIND LEAST SIGNIFICANT
                    lda       0,X                 ; NON-ZERO DIGIT
                    bne       NOSH                ; ZERO ?
                    jsr       SHIFT               ; YES, SHIFT Q
                    bne       LOOP6               ; UP ONE PLACE
ZQ                  bra       RTRN                ; Q WAS ZERO

NOSH                lda       COUNT               ; SAVE
                    sta       W1                  ; No. DIDITS - No. SHIFTS
SUBB                ldx       #TMP                ; SUBTRACT Q
                    stx       NUM1                ; FROM
                    jsr       SUB                 ; P
                    lda       CARRY               ; TOO FAR ?
                    beq       NEXTD               ; IF YES, GO TO NEXT DIGIT
                    ldx       W1                  ; INCREMENT RELEVANT
                    inc       R-1,X               ; DIGIT IN RESULT
                    bra       SUBB                ; ONCE AGAIN

NEXTD               ldx       #TMP                ; TOO FAR, ADD
                    jsr       ADD                 ; Q BACK ON
ROR                 ldx       #TMQ                ; SET UP TO
                    lda       #ND-1               ; SHIFT BACK
                    sta       COUNT               ; WORKING Q
RRR                 lda       ND-2,X              ; MOVE ALL
                    sta       ND-1,X              ; DIGITS
                    decx                          ; DOWN
                    dec       COUNT               ; ONE PLACE
                    bne       RRR                 ; DONE ?
                    clr       ND-1,X              ; CLEAR MS DIGIT
                    inc       W1                  ; INCREMENT POINTER
                    lda       W1
                    cmp       #ND+1               ; FINISHED ?
                    bne       SUBB                ; NO, NEXT DIGIT
RTRN                ldx       #R
                    rts

;*******************************************************************************

SHIFT               sta       W3
                    jsr       DR1                 ; W1: MSD, W2: LSD
                    ldx       W1
AGS                 lda       1,X                 ; MOVE ALL DIGITS
                    sta       0,X                 ; UP ONE PLACE
                    incx
                    cpx       W2
                    bne       AGS                 ; DONE ?
                    lda       W3                  ; YES, RECOVER NEW DIGIT
                    sta       0,X                 ; AND PUT IT IN LSD
                    dec       COUNT
                    rts

DR1                 stx       W1                  ; STORE POINTERS
                    lda       #ND-1               ; (USED IN DIGIT AND DQ)
AXL                 incx
                    deca
                    bne       AXL
                    stx       W2
                    rts

;*******************************************************************************
; Clear.
;*******************************************************************************

CLQ                 ldx       #Q                  ; CLEAR Q
CLRAS               stx       W5
                    lda       #ND                 ; CLEAR No. DIGITS
                    sta       COUNT               ; STARTING AT X
CR                  clr       0,X
                    incx
                    dec       COUNT
                    bne       CR                  ; DONE ?
                    ldx       W5
                    rts

;*******************************************************************************
; MJD - day of week and year.
;
; DOW = (MJD+2)MOD7 (= WD-1) (DOW)
; Y' = INT((MJD-15078.2)/3652500) (YR)
;*******************************************************************************

MJDC                ldx       #MJD
                    stx       NUM1
                    ldx       #P
                    jsr       TRA                 ; P <- MTD
                    ldx       #MJD
                    jsr       T10K                ; MJD <- MJD TIMES 10,000
DOFFW               ldx       #P-ND
                    jsr       ADD1                ; P <- MJD + 1
                    ldx       #P-ND
                    jsr       ADD1                ; P <- MJD + 2
                    ldx       #Q
                    jsr       CLRAS
                    lda       #7
                    sta       Q+ND-1              ; Q <- 7
                    jsr       DIV                 ; R <- (MJD+2)/7
                    lda       TMP+ND-1            ; REMAINDER (WD-1) IN TMP
                    sta       DOW
YEAR                ldx       #MJD
                    stx       NUM1
                    ldx       #Q
                    stx       NUM2
                    jsr       TRCY                ; Q <- CY (150782000)
                    ldx       #P
                    jsr       SUB                 ; P <- 10K(MJD-15078.2)
                    jsr       TRDY                ; Q <- 3652500
                    jsr       DIV                 ; R <- Y' ((MJD-15078.2)/365.25)
                    stx       NUM1
                    ldx       #YR
                    jsr       TRA                 ; YR <- Y'

;*******************************************************************************
; MJD - month and day.
;
; M'= INT((MJD-14956.1-INT(Y'*365.25))/306001) (P)
; D = MJD-14956-INT(Y'*365.25)-INT(M'*30.6001) (Q(x10K))
;*******************************************************************************

MONTH               jsr       INT                 ; R <- 10K(INT(Y'*365.25))
                    ldx       #MJD
                    stx       NUM1
                    ldx       #P
                    stx       NUM2
                    jsr       TRDO1               ; P <- 149561000
                    ldx       #Q
                    jsr       SUB                 ; Q <- 10K(MJD-14956.1)
                    stx       NUM1
                    ldx       #R
                    stx       NUM2
                    ldx       #P
                    jsr       SUB                 ; P <- 10K(MJD-14956.1-INT(Y'*365.25))
                    jsr       TRDM                ; Q <- 306001
                    jsr       DIV                 ; R <- M' ( MJD-14956.1-INT(Y'*365.25) )
                    stx       NUM1                ; INT ( --------------------------)
                    ldx       #P                  ; ( 306001 )
                    jsr       TRA                 ; P <- M'
                    lda       P+ND-2              ; SAVE M'
                    sta       MNTH
                    lda       P+ND-1
                    sta       MNTH+1
DAY                 jsr       TRDM                ; Q <- 306001
                    jsr       MULTI               ; R <- 10K(INT(M'*30.6001))
                    stx       NUM1
                    ldx       #TMQ
                    jsr       TRA                 ; TMQ <- 10K(INT(M'*30.6001))
                    jsr       INT                 ; R <- 10K(INT(Y'*365.25))
                    stx       NUM2
                    ldx       #TMQ
                    stx       NUM1
                    jsr       ADD                 ; TMQ <- 10K(INT(Y'*365.25)+INT(M'*30.6001))
                    stx       NUM1
                    ldx       #P
                    stx       NUM2
                    jsr       TRDO1               ; P <- 149561000
                    clr       P+ND-4              ; P <- 149560000
                    ldx       #R
                    jsr       ADD                 ; R <- 10K(14956+INT(Y'*365.25)+INT(M'*30.6001))
                    stx       NUM2
                    ldx       #MJD
                    stx       NUM1
                    ldx       #Q
                    jsr       SUB                 ; Q <- MJD-R (10K*DOM)
                    lda       ND-5,X
                    sta       DOM+1               ; MJD-14956-INT(Y'*365.25)-INT(M'*30.6001)
                    lda       ND-6,X
                    sta       DOM

;*******************************************************************************
; MJD - final correction of year & month and subs.
;
; If M' = 14 or 15, then K = 1, else K = 0
; Y = Y' + K
; M = M' - 1 - K*12
;*******************************************************************************

ADJU2               lda       MNTH                ; MONTH, MSD
                    beq       KE02                ; 0 ?
                    lda       MNTH+1              ; NO, M'= 10 THRU 15
                    beq       KE01                ; 0 ?
                    cmp       #4                  ; NO, M'= 11 THRU 15
                    blo       KE02                ; LESS THAN 14
KE1                 ldx       #YR-ND              ; NO, M'= 14 OR 15, K=1
                    jsr       ADD1                ; Y <- Y'+1
                    clr       MNTH                ; MONTH, MSD (-10)
                    dec       MNTH+1              ; DEC. MONTH
                    dec       MNTH+1              ; AND AGAIN (-2)
                    bra       KE02                ; -12

KE01                lda       #10                 ; M'= 10
                    sta       MNTH+1              ; PUT 10 IN LSD
                    clr       MNTH                ; CLEAR MSD
KE02                dec       MNTH+1              ; 9<-10, 1,2<-14,15, 3-8<-4-9, 10-12<-11-13
                    rts

INT                 ldx       #YR
                    stx       NUM1
                    ldx       #P
                    jsr       TRA                 ; P <- Y'
                    jsr       TRDY                ; Q <- 10K*365.25
MULTI               jsr       MULT                ; R <- 10K*Y'*365.25
                    clr       R+ND-4
                    clr       R+ND-3
                    clr       R+ND-2
                    clr       R+ND-1              ; R <- 10K(INT(Y'*365.25))
                    rts

T10K                txa                           ; TIMES 10,000
                    add       #ND-4
                    sta       W1
SLP                 lda       4,X
                    sta       0,X
                    incx
                    cpx       W1
                    bne       SLP
                    clr       0,X
                    clr       1,X
                    clr       2,X
                    clr       3,X
                    rts

;*******************************************************************************
; MJD constants.
;*******************************************************************************

TRCY                ldx       #ND
CYL                 lda       CY-1,X
                    sta       Q-1,X
                    decx
                    bne       CYL
                    rts

TRDY                ldx       #ND
DYL                 lda       DY-1,X
                    sta       Q-1,X
                    decx
                    bne       DYL
                    rts

TRDM                ldx       #ND
DML                 lda       DM-1,X
                    sta       Q-1,X
                    decx
                    bne       DML
                    rts

TRDO1               ldx       #ND
DO1L                lda       DO1-1,X
                    sta       P-1,X
                    decx
                    bne       DO1L
                    rts

CY                  fcb       1,5,0,7,8,2,0,0,0
DY                  fcb       0,0,3,6,5,2,5,0,0
DO1                 fcb       1,4,9,5,6,1,0,0,0
DM                  fcb       0,0,0,3,0,6,0,0,1

;*******************************************************************************
                    #VECTORS  $FFF4
;*******************************************************************************

                    fdb       START               ; SERIAL
                    fdb       TINTB               ; TIMER B
                    fdb       START               ; TIMER A
                    fdb       SDATA               ; EXTERNAL INTERRUPT & RTI
                    fdb       START               ; SWI
                    fdb       START               ; RESET

                    end
