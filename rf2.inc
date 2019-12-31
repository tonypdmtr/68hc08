;*******************************************************************************
;*           MC68HC908RF2 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER            *
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: 68HC908RF2 *
                    #Message  **********************

                    #HcsOff                       ;Normal HC08
                    #NoMMU                        ;MMU not available

_RF2_               def       *                   ;Tells us this INCLUDE has been used
_RF_                def       2                   ;Tells us a RF type device is used

; CONSTANTS

COP                 def       $FFFF,1

#ifndef KHZ
  #ifndef MHZ
HZ                  def       9830400             ;9.8304 MHz internal oscillator
  #endif
#endif

; MEMORY

TRUE_ROM            def       $7800
MAX_OS_CALLS        def       64                  ;default room for OS calls

FLASH_PAGE_SIZE     def       64                  ;minimum that must be erased at once
FLASH_DATA_SIZE     def       0
FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE

EEPROM              def       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

#if FLASH_DATA_SIZE > 512
                    #Message  All Flash is unprotected
FLBPR_MASK          def       %00000000           ;all Flash is unprotected
#else if FLASH_DATA_SIZE > 256
FLBPR_MASK          def       %00001000           ;256-512 bytes of Flash
#else if FLASH_DATA_SIZE > 128
FLBPR_MASK          def       %00000100           ;128-256 bytes of Flash
#else ifnz FLASH_DATA_SIZE
FLBPR_MASK          def       %00000010           ;0-128 bytes of Flash
#endif
FLBPR_MASK          def       %00000001           ;all Flash is protected

RAM                 def       $0080               ;Start of on-chip RAM
RAM_END             def       $00FF               ;End of on-chip RAM
ROM                 def       EEPROM+FLASH_DATA_SIZE ;Start of ROM after data area
ROM_END             def       $7FEE               ;End of ROM
VECTORS             def       $FFF2               ;Start of Vectors

          #if FLASH_DATA_SIZE > ROM_END-EEPROM
                    #Error    FLASH_DATA_SIZE is larger than available Flash
          #endif
                    #MEMORY   EEPROM    ROM_END
                    #MEMORY   VECTORS   VECTORS|$00FF

                    #EEPROM
                    org       EEPROM

                    #VECTORS
                    org       VECTORS

                    #RAM
                    org       RAM

                    #ROM
                    org       ROM

; REGISTER BLOCK ABSOLUTES

PORTA               def       $00,1               ;Port A Data
PRTA                def       PORTA,1
PORTB               def       $01,1               ;Port B Data
PRTB                def       PORTB,1
DDRA                def       $04,1               ;Data Direction Register A
DDRB                def       $05,1               ;Data Direction Register B
INTKBSCR            def       $1A,1               ;IRQ and Keyboard Status and Control Register
KBIER               def       $1B,1               ;Keyboard Interrupt Enable Register
CONFIG              def       $1F,1               ;Configuration Register
TSC                 def       $20,1               ;TIM Status and Control Register
TCNT                def       $21,2               ;TIM Counter Register
TCNTH               def       $21,1               ;TIM Counter Register High
TCNTL               def       $22,1               ;TIM Counter Register Low
TMOD                def       $23,2               ;TIM Counter Module Register
TMODH               def       $23,1               ;TIM Counter Module Register High
TMODL               def       $24,1               ;TIM Counter Module Register Low
TSC0                def       $25,1               ;TIM Channel 0 Status and Control Register
TCH0                def       $26,2               ;TIM Channel 0 Register
TCH0H               def       $26,1               ;TIM Channel 0 Register High
TCH0L               def       $27,1               ;TIM Channel 0 Register Low
TSC1                def       $28,1               ;TIM Channel 1 Status and Control Register
TCH1                def       $29,2               ;TIM Channel 1 Register High
TCH1H               def       $29,1               ;TIM Channel 1 Register High
TCH1L               def       $2A,1               ;TIM Channel 1 Register Low

ICGMR               def       $37,1               ;ICG Multiplier Register
ICGTR               def       $38,1               ;ICG Trim Register
ICGDVR              def       $39,1               ;ICG DCO Divider Register
ICGDSR              def       $3A,1               ;ICG DCO Stage Control Bits

SBSR                def       $FE00,1             ;Break Status Register
SRSR                def       $FE01,1             ;Reset Status Register
SBFCR               def       $FE02,1             ;Break Flag Control Register
BSR                 def       SBSR,1              ;|
RSR                 def       SRSR,1              ; > aliases
BFCR                def       SBFCR,1             ;|
FLCR                def       $FE08,1             ;FLASH Control Register
BRK                 def       $FE0C,2             ;Break Address Register
BRKH                def       $FE0C,1             ;Break Address High Register
BRKL                def       $FE0D,1             ;Break Address Low Register
BRKSCR              def       $FE0E,1             ;Break Status and Control Register
LVISR               def       $FE0F,1             ;LVI Status Register
FLBPR               def       $FFF0,1             ;FLASH Block Protect Register
ICGTRIMVALUE        def       $7FEF,1             ;ICG Trim Register value - optional
COPCTL              def       $FFFF,1             ;COP Control Register (low byte of reset)

ERASED_STATE        def       0                   ;FLASH 2TS has zeros erased state, not ones
                    #Uses     common.inc

ICGMRVALUE          def       HZ/307200

          #if ICGMRVALUE > 127
                    #Warning  ICGMRVALUE [{ICGMRVALUE}] is out-of-range
          #endif

          ; TIM - Time Interface Module

                    @port     PS0,PS1,PS2,,TRST,TSTOP,TOIE,TOF
                    @port     CHxMAX,TOVx,ELSxA,ELSxB,MSxA,MS0B,CHxIE,CHxF

          ; A/D - Analog-to-Digital definitions

                    @port     ,,,,,ADCO,AIEN,COCO

          ; RSR register

                    @port     ,LVI,MODRST,ILAD,ILOP,COP,PIN,POR

          ; CONFIG register(s)

                    @port     COPD,STOP,SSREC,,LVID,,,COPRS

          ; BREAK register(s)

                    @port     ,,,,,,BRKA,BRKE

          ; THIS MUST BE PROGRAMMED WHEN BURNING THE DEVICE

                    #MEMORY   FLBPR

                    #ppc
                    org       FLBPR
                    fcb       FLBPR_MASK          ;RF needs this as flash programmed
                    org       :ppc

                    #ROM

; BUILT-IN ROM FLASH PROGRAMMING ROUTINES

RDVRRNG             def       $F000               ;ROM routine to read/verify a range
PRGRNGE             def       $F003               ;ROM routine to program a range
ERARNGE             def       $F006               ;ROM routine to erase a range
REDPROG             def       $F009               ;ROM routine to range emulate a row write/erase

; BUILT-IN ROM routines' RAM variable allocation
;
;                   #RAM
;                   #ppc
;                   org       RAM+8
;CTRLBYT            rmb       1                   ;Bit6 & Bit5 hold the block size to erase
;CPUSPD             rmb       1                   ;CPU bus speed X 4 (e.g. 32 for 8MHz)
;LADDR              rmb       2                   ;Last address for read or program range
;BUMPS              rmb       1                   ;Maximum number of programming bumps to use
;DERASE             rmb       2                   ;Erase delay time in uS/24
;DATA               equ       *                   ;Variable number of data bytes (define in your program)
;                   org       :ppc

; CONSTANTS

; CTRLBYT values

.FULL_ARRAY_ERASE_  def       0
.HALF_ARRAY_ERASE_  def       Bit5_
.EIGHT_ROWS_ERASE_  def       Bit6_
.ONE_ROW_ERASE_     def       .EIGHT_ROWS_ERASE_|.HALF_ARRAY_ERASE_

                    #ROM

Vicg                def       $FFF2
Vtimovf             def       $FFF4
Vtimch1             def       $FFF6
Vtimch0             def       $FFF8
Virq                def       $FFFA
Vswi                def       $FFFC
Vreset              def       $FFFE
