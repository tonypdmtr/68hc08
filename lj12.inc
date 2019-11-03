;*******************************************************************************
;*          MC68HC908LJ12 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER            *
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  ***********************
                    #Message  * Target: 68HC908LJ12 *
                    #Message  ***********************

                    #HcsOff                       ;Normal HC08
                    #NoMMU                        ;MMU not available

_LJ_                def       12
_LJ12_              def       *                   ;Tells us this INCLUDE has been used
MHZ                 def       32                  ;32 MHz external oscillator/8 MHz bus
MAX_OS_CALLS        def       64                  ;default room for OS calls

                    * MEMORY *

FLASH_PAGE_SIZE     def       128                 ;minimum that must be erased at once
TRUE_ROM            def       $C000

FLASH_DATA_SIZE     def       0
FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE

EEPROM              def       TRUE_ROM
EEPROM_END          def       EEPROM+FLASH_DATA_SIZE

FLBPR_MASK          def       EEPROM_END>7<1&$FF  ;mask to use for FLBPR

RAM                 def       $0060               ;Start of on-chip RAM
RAM_END             def       $00FF               ;End of zero-page RAM

XRAM                equ       $0100
XRAM_END            def       $025F               ;End of on-chip RAM

ROM                 def       EEPROM+FLASH_DATA_SIZE ;Start of ROM after data area
ROM_END             def       $EFFF               ;End of ROM

VECTORS             def       $FFDA               ;Start of Vectors

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

                    #XRAM
                    org       XRAM

                    #ROM
                    org       ROM

                  * REGISTER BLOCK ABSOLUTES *

PORTA               def       $00,1               ;Port A Data
PORTB               def       $01,1               ;Port B Data
PORTC               def       $02,1               ;Port C Data
PORTD               def       $03,1               ;Port D Data
DDRA                def       $04,1               ;Data Direction Register A
DDRB                def       $05,1               ;Data Direction Register B
DDRC                def       $06,1               ;Data Direction Register C
DDRD                def       $07,1               ;Data Direction Register D
LEDB                def       $0C,1               ;Port B LED control
SPCR                def       $10,1               ;SPI Control Register
SPSCR               def       $11,1               ;SPI Status and Control Register
SPDR                def       $12,1               ;SPI Data Register
SCC1                def       $13,1               ;SCI Control Register 1
SCC2                def       $14,1               ;SCI Control Register 2
SCC3                def       $15,1               ;SCI Control Register 3
SCS1                def       $16,1               ;SCI Status Register 1
SCS2                def       $17,1               ;SCI Status Register 2
SCDR                def       $18,1               ;SCI Data Register
SCBR                def       $19,1               ;SCI Baud Rate Register
SCIRCR              def       $1A,1               ;SCI Infrared Control Register
KBSCR               def       $1B,1               ;Keyboard Status and Control Register
KBIER               def       $1C,1               ;Keyboard Interrupt Enable Register
CONFIG2             def       $1D,1               ;Configuration Register 2
INTSCR              def       $1E,1               ;IRQ Status and Control Register
CONFIG1             def       $1F,1               ;Configuration Register 1
T1SC                def       $20,1               ;TIM1 Status and Control Register
T1CNT               def       $21,2               ;TIM1 Counter Register
T1CNTH              def       $21,1               ;TIM1 Counter Register High
T1CNTL              def       $22,1               ;TIM1 Counter Register Low
T1MOD               def       $23,2               ;TIM1 Counter Module Register
T1MODH              def       $23,1               ;TIM1 Counter Module Register High
T1MODL              def       $24,1               ;TIM1 Counter Module Register Low
T1SC0               def       $25,1               ;TIM1 Channel 0 Status and Control Register
T1CH0               def       $26,2               ;TIM1 Channel 0 Register
T1CH0H              def       $26,1               ;TIM1 Channel 0 Register High
T1CH0L              def       $27,1               ;TIM1 Channel 0 Register Low
T1SC1               def       $28,1               ;TIM1 Channel 1 Status and Control Register
T1CH1               def       $29,2               ;TIM1 Channel 1 Register
T1CH1H              def       $29,1               ;TIM1 Channel 1 Register High
T1CH1L              def       $2A,1               ;TIM1 Channel 1 Register Low
TSC                 def       T1SC,1              ;ALIAS: TIM1 Status and Control Register
TCNT                def       T1CNTH,2            ;ALIAS: TIM1 Counter Register
TCNTH               def       T1CNTH,1            ;ALIAS: TIM1 Counter Register High
TCNTL               def       T1CNTL,1            ;ALIAS: TIM1 Counter Register Low
TMOD                def       T1MODH,2            ;ALIAS: TIM1 Counter Module Register
TMODH               def       T1MODH,1            ;ALIAS: TIM1 Counter Module Register High
TMODL               def       T1MODL,1            ;ALIAS: TIM1 Counter Module Register Low
TSC0                def       T1SC0,1             ;ALIAS: TIM1 Channel 0 Status and Control Register
TCH0                def       T1CH0H,2            ;ALIAS: TIM1 Channel 0 Register
TCH0H               def       T1CH0H,1            ;ALIAS: TIM1 Channel 0 Register High
TCH0L               def       T1CH0L,1            ;ALIAS: TIM1 Channel 0 Register Low
TSC1                def       T1SC1,1             ;ALIAS: TIM1 Channel 1 Status and Control Register
TCH1                def       T1CH1H,2            ;ALIAS: TIM1 Channel 1 Register
TCH1H               def       T1CH1H,1            ;ALIAS: TIM1 Channel 1 Register High
TCH1L               def       T1CH1L,1            ;ALIAS: TIM1 Channel 1 Register Low
T2SC                def       $2B,1               ;TIM2 Status and Control Register
T2CNT               def       $2C,2               ;TIM2 Counter Register
T2CNTH              def       $2C,1               ;TIM2 Counter Register High
T2CNTL              def       $2D,1               ;TIM2 Counter Register Low
T2MOD               def       $2E,2               ;TIM2 Counter Module Register
T2MODH              def       $2E,1               ;TIM2 Counter Module Register High
T2MODL              def       $2F,1               ;TIM2 Counter Module Register Low
T2SC0               def       $30,1               ;TIM2 Channel 0 Status and Control Register
T2CH0               def       $31,2               ;TIM2 Channel 0 Register
T2CH0H              def       $31,1               ;TIM2 Channel 0 Register High
T2CH0L              def       $32,1               ;TIM2 Channel 0 Register Low
T2SC1               def       $33,1               ;TIM2 Channel 1 Status and Control Register
T2CH1               def       $34,2               ;TIM2 Channel 1 Register
T2CH1H              def       $34,1               ;TIM2 Channel 1 Register High
T2CH1L              def       $35,1               ;TIM2 Channel 1 Register Low
PTCL                def       $36,1               ;PLL Control Register
PBWC                def       $37,1               ;PLL Bandwidth Control Register
PMS                 def       $38,2               ;PLL Multiplier Select Register
PMSH                def       $38,1               ;PLL Multiplier Select Register High
PMSL                def       $39,1               ;PLL Multiplier Select Register Low
PMRS                def       $3A,1               ;PLL VCO Range Select Register
PMDS                def       $3B,1               ;PLL Reference Divider Select Register
ADSCR               def       $3C,1               ;ADC Status and Control Register
ADR                 def       $3D,2               ;ADC Data Register
ADRH                def       $3D,1               ;ADC Data Register High
ADRL                def       $3E,1               ;ADC Data Register Low
ADICLK              def       $3F,1               ;ADC Input Clock Register
ADCLK               def       ADICLK,1            ;ALIAS: ADC Input Clock Register
RTCCR1              def       $42,1               ;RTC Control Register 1
RTCCR2              def       $43,1               ;RTC Control Register 2
RTCSR               def       $44,1               ;RTC Status Register
ALMR                def       $45,1               ;Alarm Minute Register
ALHR                def       $46,1               ;Alarm Hour Register
SECR                def       $47,1               ;Second Register
MINR                def       $48,1               ;Minute Register
HRR                 def       $49,1               ;Hour Register
DAYR                def       $4A,1               ;Day Register
MTHR                def       $4B,1               ;Month Register
YRR                 def       $4C,1               ;Year Register
DOWR                def       $4D,1               ;Day-of-Week Register
CHRR                def       $4E,1               ;Chronograph Data Register
LCDCLK              def       $4F,1               ;LCD Clock Register
LCDCR               def       $51,1               ;LCD Control Register
LDAT1               def       $52,1               ;LCD Data Register 1
LDAT2               def       $53,1               ;LCD Data Register 2
LDAT3               def       $54,1               ;LCD Data Register 3
LDAT4               def       $55,1               ;LCD Data Register 4
LDAT5               def       $56,1               ;LCD Data Register 5
LDAT6               def       $57,1               ;LCD Data Register 6
LDAT7               def       $58,1               ;LCD Data Register 7
LDAT8               def       $59,1               ;LCD Data Register 8
LDAT9               def       $5A,1               ;LCD Data Register 9
LDAT10              def       $5B,1               ;LCD Data Register 10
LDAT11              def       $5C,1               ;LCD Data Register 11
LDAT12              def       $5D,1               ;LCD Data Register 12
LDAT13              def       $5E,1               ;LCD Data Register 13
LDAT14              def       $5F,1               ;LCD Data Register 14

BSR                 def       $FE00,1             ;Break Status Register
RSR                 def       $FE01,1             ;Reset Status Register
BFCR                def       $FE03,1             ;Break Flag Control Register
INT1                def       $FE04,1             ;Interrupt Status Register 1
INT2                def       $FE05,1             ;Interrupt Status Register 2
INT3                def       $FE06,1             ;Interrupt Status Register 3
FLCR                def       $FE08,1             ;FLASH Control Register
FLBPR               def       $FE09,1             ;FLASH Block Protect Register
BRK                 def       $FE0C,2             ;Break Address Register
BRKH                def       $FE0C,1             ;Break Address High Register
BRKL                def       $FE0D,1             ;Break Address Low Register
BRKSCR              def       $FE0E,1             ;Break Status and Control Register
LVISR               def       $FE0F,1             ;LVI Status Register
COPCTL              def       $FFFF,1             ;COP Control Register (low byte of reset)

                    #Uses     common.inc

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

; CONFIG register(s)

                    @bitnum   COPRS,7
                    @bitnum   LVID,4
                    @bitnum   SSREC,2
                    @bitnum   STOP,1
                    @bitnum   COPD,0

; BREAK register(s)

                    @bitnum   BRKE,7
                    @bitnum   BRKA,6

                    #MEMORY   CONFIG1 CONFIG2

                    #ROM

;-------------------------------------------------------------------------------
;                BUILT-IN ROM FLASH PROGRAMMING ROUTINES
; Parameters for the following routines are passed in a block pointed to by
; HX containing the following (given with offset addresses):
; Offset  Size      Contents
; ------- --------- ------------------------------------------------------------
; 0       1         Bus Speed (BUS_SPD)
; 1       1         Data Size (DATASIZE)
; 2       2         Start Address (High/Low)
; 4       DATASIZE  Actual Data

EE_WRITE            def       $FC00               ;ROM routine to emulate EEPROM write
EE_READ             def       $FC03               ;ROM routine to emulate EEPROM read
PRGRNGE             def       $FC06               ;ROM routine to program a range
ERARNGE             def       $FCBE               ;ROM routine to erase a 128-byte page or all (if $FFFF)
MON_PRGRNGE         def       $FC28               ;ROM routine to program a range in monitor mode
MON_LDRNGE          def       $FF24               ;ROM routine to load data from a range in monitor mode
MON_ERARNGE         def       $FF2C               ;ROM routine to erase a 128-byte page or all (if $FFFF) in monitor mode
LDRNGE              def       $FF30               ;ROM routine to load data from a range

Vswi                def       $FFFC,2             ;SWI vector
Vreset              def       $FFFE,2             ;Reset vector
