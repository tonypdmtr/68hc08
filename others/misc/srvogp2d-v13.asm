;*******************************************************************************
; srvogp2d-v13.asm
;
; 2011-12-29 - v1.0 Created
; 2012-01-06 - v1.2 get/send, servo, GP2D and main loop
; 2012-01-27 - v1.3 Separated GP2D byte read from trigger
; 2021-11-25 -      Adapted to ASM8 by Tony Papadimitriou <tonyp@acm.org>
;
; Code to support servo motor PWM and GP2D distance sensor.
; Micro will link through simple serial connection to V25 board for
; command/data and to servo + GP2D sensor.
;
; Application's controller pin functionality:
;  PA0 [DO] - PWM servo control (TCH0)
;  PA1 [AI] - battery level (AD1) [acting as ext. trigger for timing GP2D]
;  PA2 [DI] - from GP2D Vout
;  PA3 [DO] - to GP2D Vin
;  PA4 [DO] - Data out (in) to (from) V25
;  PA5 [DI] - Clock in from V25
;
; Legend: A=Analog, D=Digital, I=Input, O=Output
;
; Communication protocol:
;  Always initiated by V25
;  Data sent or received in 8 bit length
;  4 bit command format (b0 through b3):
;    0     - no command / invalid command / error
;    1     - get revision (two 8-bit values will follow to V25:
;            revision code out to V25 and last reset status/reason)
;    2     - servo position (8-bit servo position will follow from V25)
;    3     - trigger GP2D (8-bit true(-1)/false(0) to V25 will follow)
;    4     - read GP2D (8-bit GP2D distance data out to V25 will follow)
;    5     - read battary (8-bit battary voltage out to V25 will follow)
;    6..15 - not used
;    $aa   - echo $aa byte (echo comm test)
;
;*******************************************************************************

;*******************************************************************************
                    #Uses     qt4.inc             ;derivative-specific definitions
;*******************************************************************************

Del_2mSec           macro
                    pshxa
                    lda       #105
                    ldx       #20
                    jsr       ROM_DELAY
                    pulxa
                    endm
;-------------------------------------------------------------------------------
Del_100uSec         macro
                    pshxa
                    lda       #105
                    ldx       #1
                    jsr       ROM_DELAY
                    pulxa
                    endm
;-------------------------------------------------------------------------------
CODEREV             equ       $13                 ;revision '1.3'

CMD_GETREV          equ       1                   ;V25/HC08 command set
CMD_SRVPOS          equ       2
CMD_GP2DTRG         equ       3
CMD_GP2DRD          equ       4
CMD_GETVOLT         equ       5
ECHO                equ       $aa                 ;special echo command
          ;-------------------------------------- ;bit/pin definitions
COCO                pin       ADSCR,COCO.         ;High when conversion completes
START_TIM           pin       TSC,5               ;Low starts timer

GP2D_DATA           pin       PORTA,2
GP2D_CLK            pin       PORTA,3
COMM_DATA           pin       PORTA,4
COMM_CLK            pin       PORTA,5
          ;-------------------------------------- ;CONFIG reg.
CONFIG1_INIT        equ       %00111001           ;default initialization
                              ;||||||||           ;CONFIG1 is a write-once register
                              ;|||||||+-----------;COPD    - 1 disable COP watchdog
                              ;||||||+------------;STOP    - 0 disable STOP instruction
                              ;|||||+-------------;SSREC   - 0 4096 cycle STOP recovery
                              ;||||+--------------;LVI5OR3 - 1 set LVI for 5v system
                              ;|||+---------------;LVIPWRD - 1 disable power to LVI system
                              ;||+----------------;LVIRSTD - 1 disable reset on LVI trip
                              ;|+-----------------;LVISTOP - 0 enable LVI in STOP mode
                              ;+------------------;COPRS   - 0 long COP timeout
          ;-------------------------------------- ;Port A reg.
PORTA_DEF           equ       %00011000           ;PORTA(x) default output pin levels
PORTA_DDR           equ       %00011010
                              ;||||||||           ;PORTA DDR
                              ;|||||||+-----------;PA0 - 0 (PWM clock channel)
                              ;||||||+------------;PA1 - 1 output, *** ext. timing trigger
                              ;|||||+-------------;PA2 - 0 input , GP2D Vo
                              ;||||+--------------;PA3 - 1 output, GP2D Vi
                              ;|||+---------------;PA4 - 1 output, V25 data
                              ;||+----------------;PA5 - 0 input , V25 clock
                              ;|+-----------------;n/a - 0
                              ;+------------------;n/a - 0
PORTA_PUP           equ       %00100000
                              ;||||||||           ;PORTA Pull-up config
                              ;|||||||+-----------;PA0 - 0 disable, (clock channel)
                              ;||||||+------------;PA1 - 0 disable, output, ext. timing trigger
                              ;|||||+-------------;PA2 - 0 disable, input , GP2D Vo
                              ;||||+--------------;PA3 - 0 disable, output, GP2D Vi
                              ;|||+---------------;PA4 - 1 enable,  output/input, V25/HC08 data
                              ;||+----------------;PA5 - 1 enable,  input,  V25 clock
                              ;|+-----------------;n/a - 0
                              ;+------------------;n/a - 0
          ;-------------------------------------- ;Timer channel 0
TIM_INIT            equ       %00110110           ;timer control/mode
                              ;||||||||           ;TIM initialization
                              ;|||||||+-----------;PS0   - 0 |
                              ;||||||+------------;PS1   - 1 +- div. by 64 pre-scaler
                              ;|||||+-------------;PS2   - 1 |
                              ;||||+--------------;n/a   - 0
                              ;|||+---------------;TRST  - 1 Prescaler and TIM counter cleared
                              ;||+----------------;TSTOP - 1 TIM counter stopped
                              ;|+-----------------;TOIE  - 0 TIM overflow interrupts disabled
                              ;+------------------;TOF   - 0 overflow flag
TSC0_INIT           equ       %00011010
                              ;||||||||           ;TIM Channel 0 PWM initialization
                              ;|||||||+-----------;CH0MAX - 0 not max. on TOV
                              ;||||||+------------;TOV0   - 1 channel 0 pin toggles on TIM counter overflow
                              ;|||||+-------------;ELS0A  - 0 | Clear output on compare
                              ;||||+--------------;ELS0B  - 1 |
                              ;|||+---------------;MS0A   - 1 Unbuffered output compare/PWM operation
                              ;||+----------------;MS0B   - 0 Buffered output compare/PWM operation disabled
                              ;|+-----------------;CH0IE  - 0 Channel 0 interrupt requests disabled
                              ;+------------------;CH0F   - 0 n/a

TIM_MOD             equ       1000                ;modulo counter values for 20mSec PWM cycle time
TIM_CHAN            equ       80                  ;default compare value for PWM period for mid servo position of 1.5mSec
MIN_PWM             equ       35                  ;min. PWM value in TCH0L for 0.5mSec
MAX_PWM             equ       125                 ;max. PWM value in TCH0L for 2.5mSec
          ;-------------------------------------- ;ADC
ADSCR_INIT          equ       %00100001
                              ;||||||||       ADC channel 1 initialization
                              ;|||||||+-CH      - 1 |
                              ;||||||+--CH      - 0 |
                              ;|||||+---CH      - 0 +- Channle select 1
                              ;||||+----CH      - 0 |
                              ;|||+-----CH      - 0 |
                              ;||+------ADCO    - 1 Continuous ADC conversion
                              ;|+-------AIEN    - 0 ADC interrupt disabled
                              ;+--------COCO 0 n/a
ADC_OFF             equ       $1f                 ;ADC off
ADC_DUMMY           equ       $aa                 ;dummy return value for ADC
ADICLK_INIT         equ       $00                 ;conversion clock = bus speed

;FLBPR              equ       $FFBE               ;flash block protect reg (flash)
;                   org       FLBPR               ;flash block protect location
;                   fcb       $FE                 ;protect this code, FLBPR,& vectors

;*******************************************************************************
                    #RAM
;*******************************************************************************

rst_status          rmb       1                   ;last system reset status (copy of SRSR reg.)

;*******************************************************************************
                    #ROM
;*******************************************************************************

;*******************************************************************************
; HC908 MCU initialization

Start               proc
                    lda       RSR
                    sta       rst_status          ;save last reset status
                    mov       #CONFIG1_INIT,CONFIG1 ;initialize CONFIG1 reg.
                    lda       OSCTRIMVALUE
                    sta       OSCTRIM             ;set working trim value in ICG
                    @rsp                          ;initialize the stack pointer
          ;--------------------------------------
          ; Configure PORTA(x) port pins
          ; PA0 [DO] - PWM servo control (TCH0)
          ; PA1 [AI] - battery level (AD1)
          ; PA2 [DI] - from GP2D Vo
          ; PA3 [DO] - to GP2D Vi
          ; PA4 [DO] - Data out (in) to (from) V25
          ; PA5 [DI] - Clock in from V25
          ;--------------------------------------
                    mov       #PORTA_DEF,PORTA    ;setup init output levels before direction
                    mov       #PORTA_PUP,PTAPUE
                    mov       #PORTA_DDR,DDRA
          ;--------------------------------------
          ; Timer channel 0 setup for PWM
          ;--------------------------------------
                    mov       #TIM_INIT,TSC       ;initialize timer and set pre-scaler
                    mov       #]TIM_MOD,TMODH
                    mov       #[TIM_MOD,TMODL     ;setup modulo counter to 20mSec PWM cycle time
                    mov       #]TIM_CHAN,TCH0H
                    mov       #[TIM_CHAN,TCH0L    ;setup channel 0 compare value for PWM period
                    mov       #TSC0_INIT,TSC0     ;setup channel 0 for PWM
                    bclr      START_TIM           ;start the timer (PWM)
          ;--------------------------------------
          ; ADC channel 1 setup
          ;--------------------------------------
                    mov       #ADSCR_INIT,ADSCR   ;use ADSCR_INIT if ADC1 is implemented
                    mov       #ADICLK_INIT,ADCLK  ;conversion clock = bus clock
;                   bra       MainLoop

;*******************************************************************************

MainLoop            proc
                    bsr       GetByte             ;get command
                    cmpa      #CMD_GETREV
                    bne       _1@@
                    jsr       SendRev             ;revision read handler
                    bra       MainLoop
          ;--------------------------------------
_1@@                cmpa      #CMD_SRVPOS
                    bne       _2@@
                    bsr       GetByte             ;servo PWM handler
                    jsr       SetServoPos         ;send position to servo
                    bra       MainLoop
          ;--------------------------------------
_2@@                cmpa      #CMD_GP2DTRG
                    bne       _3@@
                    jsr       TrigGP2D            ;GP2D trigger handler
                    bra       Cont@@              ;return trigger status
          ;--------------------------------------
_3@@                cmpa      #CMD_GP2DRD
                    bne       _4@@
                    jsr       ReadGP2D            ;GP2D handler
                    bra       Cont@@              ;send GP2D readout
          ;--------------------------------------
_4@@                cmpa      #CMD_GETVOLT
                    bne       _5@@
                    jsr       ReadBattVolt        ;battery voltage read handler
                    bra       Cont@@              ;send ADC readout
          ;--------------------------------------
_5@@                cmpa      #ECHO
                    bne       MainLoop
          ;--------------------------------------
Cont@@              bsr       SendByte            ;echo received byte
                    bra       MainLoop

;*******************************************************************************
; Get byte from serial connection from V25
; Byte returned in Accumulator (A)
; All affected registers are preserved
; This is a blocking function and will return only after
; 8 bit data is received from V25 LSB first
; Serial comm PA4 data direction is entered as 'out',
; changed to 'in' for the duraiton of the transmission,
; and reverted back to 'out'.
; IO pins:
; PA4 [DO] - Data out (in) to (from) V25
; PA5 [DI] - Clock in from V25

GetByte             proc
                    pshx                          ;save registers
                    clra
                    brset     COMM_CLK,*          ;wait for V25 to lower CLK line
                    @Del_100usec                  ;wait another 100uSec and check again...
                    brset     COMM_CLK,Done@@     ;exit if V25 did not hold CLK at LO
                    bclr      COMM_DATA           ;signal ready by lowering DATA line
                    brclr     COMM_CLK,*          ;wait for clock HI before swapping data pin direction
                    bclr      COMM_DATA+DDR       ;set DATA to input
                    ldx       #4                  ;load counter for 8-bit size (4 pairs)
Loop@@              brset     COMM_CLK,*          ;wait for CLK to go LO
                    bsr       ?GetBit
                    brclr     COMM_CLK,*          ;wait for CLK to go HI
                    bsr       ?GetBit
                    dbnzx     Loop@@              ;cycle through next bits
                    bset      COMM_DATA           ;set DATA line to HI when done
                    bset      COMM_DATA+DDR       ;set DATA back to output
                    @Del_100usec
Done@@              pulx                          ;restore registers
                    rts

;*******************************************************************************

?GetBit             proc
                    @ReadPin  COMM_DATA
                    rora
                    rts

;*******************************************************************************
; Send data from Accumulator (A) through serial to V25
; Accumulator and all registers are preserved
; This function returnes after sending 8 bits LSB first
; IO pins:
; PA4 [DO] - Data out (in) to (from) V25
; PA5 [DI] - Clock in from V25

SendByte            proc
                    pshxa                         ;save registers
                    brset     COMM_CLK,*          ;wait for V25 to lower CLK line
                    @Del_100usec                  ;wait another 100uSec and check again...
                    brset     COMM_CLK,Done@@     ;exit if V25 did not hold CLK at LO
                    bclr      COMM_DATA           ;signal ready by lowering DATA line
                    ldx       #4                  ;load counter for 8-bit size (4 pairs)
Loop@@              brclr     COMM_CLK,*          ;wait for CLK to go HI
                    bsr       ?SendBit
                    brset     COMM_CLK,*          ;wait for CLK to go LO
                    bsr       ?SendBit
                    dbnzx     Loop@@              ;cycle through next bits
                    brclr     COMM_CLK,*          ;wait for CLK to go HI
                    bset      COMM_DATA           ;set DATA line to HI when done
                    @Del_100usec
Done@@              pulxa                         ;restore registers
                    rts

;*******************************************************************************

?SendBit            proc
                    rora
                    @CopyPin  ,COMM_DATA          ;set bit HI
                    rts

;*******************************************************************************
; Send code revision and reset status to V25
; All registers are preserved

SendRev             proc
                    psha
                    lda       #CODEREV
                    bsr       SendByte            ;load and send code rev to V25
                    lda       rst_status
                    bsr       SendByte            ;load and send last Reser status/reason to V25
                    pula
                    rts

;*******************************************************************************
; Set servo PWM from count passed in Accumulator (A)
; All registeres are preserved

SetServoPos         proc
                    psha
                    cmpa      #MIN_PWM
                    blo       Low@@
                    cmpa      #MAX_PWM            ;range-check value is <=max. AND >=min.
                    bls       Done@@              ;treat as unsigned value when comparing
          ;-------------------------------------- ;too high
                    lda       #MAX_PWM
                    bra       Done@@
          ;-------------------------------------- ;too low
Low@@               lda       #MIN_PWM
          ;--------------------------------------
Done@@              sta       TCH0L               ;store new PWM into counter
                    pula
                    rts

;*******************************************************************************
; Trigger GP2D sensor and return with true/false in Accumulator (A)
; True(-1) trigger ok, false(0) did not trigger
; All other registers are preserved.
; IO pins:
; PA2 [DI] GP2D_DATA - from GP2D Vout
; PA3 [DO] GP2D_CLK  - to GP2D Vin

TrigGP2D            proc
                    clra
                    brclr     GP2D_DATA,Done@@    ;exit if GP2D Vo is LO, can't trigger
                    bclr      GP2D_CLK            ;pull GP2D Vin LO to signal start of measurment
                    @Del_100usec                  ;delay 100uSec to give sensor time to power on
                    brset     GP2D_DATA,NoTrig@@  ;exit if GP2D Vo is HI, didn't trigger
                    lda       #-1                 ;exit with 'true' if GP2D did trigger
                    rts

NoTrig@@            bset      GP2D_CLK            ;exit with clock HI
Done@@              rts

;*******************************************************************************
; Read GP2D sensor and return distance data byte in Accumulator (A)
; All other registers are preserved.
; IO pins:
; PA2 [DI] GP2D_DATA - from GP2D Vout
; PA3 [DO] GP2D_CLK  - to GP2D Vin

ReadGP2D            proc
                    pshx                          ;save registers
                    clra
                    brclr     GP2D_DATA,*         ;wait for measurement to complete (total ~45mSec)
                    ldx       #8                  ;load bit counter
                    bset      GP2D_CLK            ;raise clock in prepapration for reading
                    @Del_100usec                  ;delay 100uSec
Loop@@              bclr      GP2D_CLK            ;clock a bit
                    @Del_100usec                  ;delay 100uSec
                    @ReadPin  GP2D_DATA
                    rola                          ;rotate left, MSB in first
                    bset      GP2D_CLK            ;raise clock
                    @Del_100usec                  ;delay 100uSec
                    dbnzx     Loop@@              ;get next bit from GP2D
                    bset      GP2D_CLK            ;exit with clock HI
                    @Del_2msec                    ;delay 2mSec before next conversion can start
                    pulx                          ;restore registers
                    rts

;*******************************************************************************
; ReadBattVolt
;
; read AD1 voltage and return value in Accumulator

ReadBattVolt        proc
                    brclr     COCO,*              ;is convertion complete?
                    lda       ADR                 ;yes, return ADC reading
                    rts

;*******************************************************************************
; ROM routine
;-------------------------------------------------------------------------------
; DELNUS renamed to ROM_DELAY [p.14 sec 3.6 and 9.6 AN1831]
; Uses two parameters in Accumulator (A) and X register (X)
; Delay (cycles) resulting from this routine is:
; 3 (A value) (X value) + 8 cycles (where a value of A>=4, X>=1)

          #ifdef DELNUS
ROM_DELAY           equ       DELNUS              ;DELNUS delay routine in QT4 ROM
          #else
ROM_DELAY           proc
                    deca
Loop@@              psha
                    deca:2
                    dbnza     *
                    pula
                    dbnzx     Loop@@
                    rts
          #endif
;*******************************************************************************
                    #VECTORS  Vreset
;*******************************************************************************
                    dw        Start
