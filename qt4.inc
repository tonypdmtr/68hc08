;*******************************************************************************
;*           MC68HC908QT4 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER            *
;*******************************************************************************
; Property of ASPiSYS Ltd. and Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: 68HC908QT4 *
                    #Message  **********************

                    #HCSOff                       ;Normal HC08
                    #NoMMU                        ;MMU not available

_QT4_               def       *                   ;Tells us this INCLUDE has been used
_QT_                def       4                   ;Tells us a QT type device is used

          ; MEMORY

TRUE_ROM            equ       $EE00
MAX_OS_CALLS        def       64                  ;default room for OS calls

FLASH_PAGE_SIZE     equ       64                  ;minimum that must be erased at once
FLASH_DATA_SIZE     def       0
FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE

EEPROM              equ       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

RAM                 equ       $80                 ;Start of on-chip RAM
RAM_END             equ       $FF                 ;End of on-chip RAM
ROM                 equ       EEPROM_END+1        ;Start of ROM after data area
ROM_END             equ       $FDFF               ;End of ROM
VECTORS             equ       $FFDE               ;Start of Vectors

FLBPR_MASK          equ       ROM>6&$FF           ;mask to use for FLBPR

          #if FLASH_DATA_SIZE > ROM_END-EEPROM
                    #Error    FLASH_DATA_SIZE is larger than available Flash
          #endif
                    #MEMORY   EEPROM    ROM_END
                    #MEMORY   VECTORS   VECTORS|$FF

                    #EEPROM   EEPROM
                    #VECTORS  VECTORS
                    #RAM      RAM
                    #ROM      ROM

          ; REGISTER BLOCK ABSOLUTES

PORTA               equ       $00,1               ;Port A Data
PORTB               equ       $01,1               ;Port B Data
DDRA                equ       $04,1               ;Data Direction Register A
DDRB                equ       $05,1               ;Data Direction Register B
PTAPUE              equ       $0B,1               ;Port A Pullup Enable Register
PTBPUE              equ       $0C,1               ;Port B Pullup Enable Register
KBSCR               equ       $1A,1               ;Keyboard Status and Control Register
KBIER               equ       $1B,1               ;Keyboard Interrupt Enable Register
INTSCR              equ       $1D,1               ;IRQ Status and Control Register
CONFIG2             equ       $1E,1               ;Configuration Register 2
CONFIG1             equ       $1F,1               ;Configuration Register 1
TSC                 equ       $20,1               ;TIM Status and Control Register
TCNT                equ       $21,2               ;TIM Counter Register
TCNTH               equ       $21,1               ;TIM Counter Register High
TCNTL               equ       $22,1               ;TIM Counter Register Low
TMOD                equ       $23,2               ;TIM Counter Module Register
TMODH               equ       $23,1               ;TIM Counter Module Register High
TMODL               equ       $24,1               ;TIM Counter Module Register Low
TSC0                equ       $25,1               ;TIM Channel 0 Status and Control Register
TCH0                equ       $26,2               ;TIM Channel 0 Register
TCH0H               equ       $26,1               ;TIM Channel 0 Register High
TCH0L               equ       $27,1               ;TIM Channel 0 Register Low
TSC1                equ       $28,1               ;TIM Channel 1 Status and Control Register
TCH1                equ       $29,2               ;TIM Channel 1 Register
TCH1H               equ       $29,1               ;TIM Channel 1 Register High
TCH1L               equ       $2A,1               ;TIM Channel 1 Register Low
OSCSTAT             equ       $36,1               ;Oscillator Status Register
OSCTRIM             equ       $38,1               ;Oscillator Trim Register
ADSCR               equ       $3C,1               ;ADC Status and Control Register
ADR                 equ       $3E,1               ;ADC Data Register
ADRL                equ       $3E,1               ;ADC Data Register Low
ADCLK               equ       $3F,1               ;ADC Input Clock Register

BSR                 equ       $FE00,1             ;Break Status Register
RSR                 equ       $FE01,1             ;Reset Status Register
BRKAR               equ       $FE02,1             ;Break auxilliary register
BFCR                equ       $FE03,1             ;Break Flag Control Register
INT1                equ       $FE04,1             ;Interrupt Status Register 1
INT2                equ       $FE05,1             ;Interrupt Status Register 2
INT3                equ       $FE06,1             ;Interrupt Status Register 3
FLCR                equ       $FE08,1             ;FLASH Control Register
BRK                 equ       $FE09,2             ;Break Address Register
BRKH                equ       $FE09,1             ;Break Address High Register
BRKL                equ       $FE0A,1             ;Break Address Low Register
BRKSCR              equ       $FE0B,1             ;Break Status and Control Register
LVISR               equ       $FE0C,1             ;LVI Status Register
FLBPR               equ       $FFBE,1             ;FLASH Block Protect Register
OSCTRIMVALUE        equ       $FFC0,1             ;Internal OSC trim value - optional
COPCTL              equ       $FFFF,1             ;COP Control Register (low byte of reset)
COP                 equ       COPCTL,1            ;for "STA COP"

                    #MEMORY   CONFIG1 CONFIG2
          #ifndef NO_CODE                         ;THIS MUST BE PROGRAMMED WHEN BURNING THE DEVICE
                    #MEMORY   FLBPR
                    #SEG1     FLBPR
                    fcb       FLBPR_MASK          ;QT needs this as flash programmed
          #endif
                    #ROM

          ; BUILT-IN ROM FLASH PROGRAMMING ROUTINES

GETBYTE             equ       $2800               ;ROM routine to read a byte from PB0
RDVRRNG             equ       $2803               ;ROM routine to read/verify a range
ERARNGE             equ       $2806               ;ROM routine to erase a range
PRGRNGE             equ       $2809               ;ROM routine to program a range
DELNUS              equ       $280C               ;ROM routine to delay a number of micro-seconds
ICGTRIM             equ       $280F               ;ROM routine to the ICG
ICGTEST             equ       $2812               ;ROM routine to test the ICG

          ; BUILT-IN ROM routines' RAM variable allocation

;CTRLBYT            equ       RAM+$08             ;Mass erase flag is Bit6.
;CPUSPD             equ       RAM+$09             ;CPU bus speed X 4 (e.g. 32 for 8MHz)
;LADDR              equ       RAM+$0A             ;Last address for read or program range
;DATA               equ       RAM+$0C             ;Variable number of data bytes

Vadc                equ       $FFDE               ;ADC
Vkeyboard           equ       $FFE0               ;Keyboard
Vtimovf             equ       $FFF2               ;TIM Overflow
Vtimch1             equ       $FFF4               ;TIM Ch1
Vtimch0             equ       $FFF6               ;TIM Ch0
Virq                equ       $FFFA               ;/IRQ vector
Vswi                equ       $FFFC               ;SWI vector
Vreset              equ       $FFFE               ;/RESET

#ifndef MHZ¦HZ
KHZ                 def       12800               ;12.8 MHz internal oscillator
#endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

          ; TIM - Time Interface Module

                    @bitnum   TOF,7
                    @bitnum   TOIE,6
                    @bitnum   TSTOP,5
                    @bitnum   TRST,4
                    @bits     PS,0,2

                    @bitnum   CHxF,7
                    @bitnum   CHxIE,6
                    @bitnum   MSxB,5
                    @bitnum   MSxA,4
                    @bitnum   ELSxB,3
                    @bitnum   ELSxA,2
                    @bitnum   TOVx,1
                    @bitnum   CHxMAX,0

          ; A/D - Analog-to-Digital definitions

                    @bitnum   COCO,7              ;Conversion Complete Flag
                    @bitnum   AIEN,6              ;A/D Interrupts Enable
                    @bitnum   ADCO,5              ;A/D Continuous Conversion

          ; RSR register

                    @bitnum   POR,7               ;Power-On reset
                    @bitnum   PIN,6               ;External pin reset
                    @bitnum   COP,5               ;COP reset
                    @bitnum   ILOP,4              ;Illegal Opcode reset
                    @bitnum   ILAD,3              ;Illegal Address reset
                    @bitnum   MODRST,2            ;Monitor Mode Entry reset
                    @bitnum   LVI,1               ;Low-voltage reset

          ; CONFIG2 register

                    @bitnum   IRQPUD,7
                    @bitnum   IRQEN,6
                    @bitnum   RSTEN,0

          ; CONFIG1 register

                    @bitnum   COPRS,7
                    @bitnum   LVISTOP,6
                    @bitnum   LVIRSTD,5
                    @bitnum   LVIPWRD,4
                    @bitnum   SSREC,2
                    @bitnum   STOP,1
                    @bitnum   COPD,0

          ; BREAK register(s)

                    @bitnum   BRKE,7
                    @bitnum   BRKA,6
