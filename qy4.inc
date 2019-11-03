;*******************************************************************************
;*           MC68HC908QY4 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER            *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: 68HC908QY4 *
                    #Message  **********************

                    #HcsOff                       ;Normal HC08
                    #NoMMU                        ;MMU not available

_QY4_               def       *                   ;Tells us this INCLUDE has been used
_QY_                def       4                   ;Tells us a QY type device is used

                    * MEMORY *

TRUE_ROM            def       $EE00
MAX_OS_CALLS        def       64                  ;default room for OS calls

FLASH_PAGE_SIZE     def       64                  ;minimum that must be erased at once
EEPROM              def       TRUE_ROM

FLASH_DATA_SIZE     def       0
FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE
EEPROM_END          def       EEPROM+FLASH_DATA_SIZE-1

FLBPR_MASK          def       EEPROM+FLASH_DATA_SIZE>6&$FF ;mask to use for FLBPR

RAM                 def       $0080               ;Start of on-chip RAM
RAM_END             def       $00FF               ;End of on-chip RAM
ROM                 def       EEPROM_END+1        ;Start of ROM after data area
ROM_END             def       $FDFF               ;End of ROM
VECTORS             def       $FFDE               ;Start of Vectors

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
PORTB               def       $01,1               ;Port B Data
DDRA                def       $04,1               ;Data Direction Register A
DDRB                def       $05,1               ;Data Direction Register B
PTAPUE              def       $0B,1               ;Port A Pullup Enable Register
PTBPUE              def       $0C,1               ;Port B Pullup Enable Register
KBSCR               def       $1A,1               ;Keyboard Status and Control Register
KBIER               def       $1B,1               ;Keyboard Interrupt Enable Register
INTSCR              def       $1D,1               ;IRQ Status and Control Register
CONFIG2             def       $1E,1               ;Configuration Register 2
CONFIG1             def       $1F,1               ;Configuration Register 1
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
TCH1                def       $29,2               ;TIM Channel 1 Register
TCH1H               def       $29,1               ;TIM Channel 1 Register High
TCH1L               def       $2A,1               ;TIM Channel 1 Register Low
OSCSTAT             def       $36,1               ;Oscillator Status Register
OSCTRIM             def       $38,1               ;Oscillator Trim Register
ADSCR               def       $3C,1               ;ADC Status and Control Register
ADR                 def       $3E,1               ;ADC Data Register
ADRL                equ       $3E,1               ;ADC Data Register Low
ADCLK               def       $3F,1               ;ADC Input Clock Register

BSR                 def       $FE00,1             ;Break Status Register
RSR                 def       $FE01,1             ;Reset Status Register
BRKAR               def       $FE02,1             ;Break auxilliary register
BFCR                def       $FE03,1             ;Break Flag Control Register
INT1                def       $FE04,1             ;Interrupt Status Register 1
INT2                def       $FE05,1             ;Interrupt Status Register 2
INT3                def       $FE06,1             ;Interrupt Status Register 3
FLCR                def       $FE08,1             ;FLASH Control Register
BRK                 def       $FE09,2             ;Break Address Register
BRKH                def       $FE09,1             ;Break Address High Register
BRKL                def       $FE0A,1             ;Break Address Low Register
BRKSCR              def       $FE0B,1             ;Break Status and Control Register
LVISR               def       $FE0C,1             ;LVI Status Register
FLBPR               def       $FFBE,1             ;FLASH Block Protect Register
OSCTRIMVALUE        def       $FFC0,1             ;Internal OSC trim value - optional
COPCTL              def       $FFFF,1             ;COP Control Register (low byte of reset)
COP                 def       COPCTL,1            ;for "STA COP"

                    #MEMORY   CONFIG1 CONFIG2

                    #SEG1

          ; THIS MUST BE PROGRAMMED WHEN BURNING THE DEVICE

                    #MEMORY   FLBPR

                    org       FLBPR
                    fcb       FLBPR_MASK          ;QT needs this as flash programmed

                    #ROM

          ; BUILT-IN ROM FLASH PROGRAMMING ROUTINES

GETBYTE             def       $2800               ;ROM routine to read a byte from PB0
RDVRRNG             def       $2803               ;ROM routine to read/verify a range
ERARNGE             def       $2806               ;ROM routine to erase a range
PRGRNGE             def       $2809               ;ROM routine to program a range
DELNUS              def       $280C               ;ROM routine to delay a number of micro-seconds
ICGTRIM             def       $280F               ;ROM routine to the ICG
ICGTEST             def       $2812               ;ROM routine to test the ICG

          ; BUILT-IN ROM routines' RAM variable allocation

;CTRLBYT            def       RAM+$08             ;Mass erase flag is 6
;CPUSPD             def       RAM+$09             ;CPU bus speed X 4 (e.g. 32 for 8MHz)
;LADDR              def       RAM+$0A             ;Last address for read or program range
;DATA               def       RAM+$0C             ;Variable number of data bytes

Vadc                def       $FFDE               ;ADC
Vkeyboard           def       $FFE0               ;Keyboard
Vtimovf             def       $FFF2               ;TIM Overflow
Vtimch1             def       $FFF4               ;TIM Ch1
Vtimch0             def       $FFF6               ;TIM Ch0
Virq                def       $FFFA               ;/IRQ vector
Vswi                def       $FFFC               ;SWI vector
Vreset              def       $FFFE               ;/RESET

#ifndef MHZ
          #ifndef HZ
KHZ                 def       12800               ;12.8 MHz internal oscillator
          #endif
#endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

; TIM - Time Interface Module

                    @bitnum   TOF,7
                    @bitnum   TOIE,6
                    @bitnum   TSTOP,5
                    @bitnum   TRST,4
                    @bitnum   PS2,2
                    @bitnum   PS1,1
                    @bitnum   PS0,0

                    @bitnum   CHxF,7
                    @bitnum   CHxIE,6
                    @bitnum   MS0B,5
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
