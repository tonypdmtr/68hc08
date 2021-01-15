;*******************************************************************************
; MC68HC908GP32 Definitions                          Copyright (c) Motorola 2000
;*******************************************************************************
;
; File name:          gp32.inc                    Current Release Level:     1.0
; Last Edit Date:     22-Feb-00                   Classification:             ES
;
; Include Files:      none
;
; Assembler:          ASM8
;
; Target Device:      MC68HC908GP32
;
; Documentation:      MC68HC908GP32/H  Rev 3   Microcontroller Technical Data
;
;*******************************************************************************
;
;      Author:             DHJ Klotz                   Location:   TOR
;      First Release:      22-Feb-00
;
;      Update History:
;
;      Rev     Date        Author  Description of Change
;      ------  ---------   ------  --------------------------------------------
;      ES 1.0  22-Feb-00   DHJK    Initial release.
;
;      ES 2.0  25-Apr-01   BAB     Fixed errors, and added new definitions
;
;*******************************************************************************
;
; Motorola reserves the right to make changes without further notice to any
; product herein to improve reliability, function, or design.  Motorola does not
; assume any liability arising out of the application or use of any product,
; circuit, or software described herein; neither does it convey any license
; under its patent rights nor the rights of others.  Motorola products are not
; designed, intended, or authorized for use as components in systems intended
; for surgical implant into the body, or other applications intended to support
; life, or for any other application in which the failure of the Motorola
; product could create a situation where personal injury or death may occur.
; Should Buyer purchase or use Motorola products for any such intended or
; unauthorized application, Buyer shall indemnify and hold Motorola and its
; officers, employees, subsidiaries, affiliates, and distributors harmless
; against all claims, costs, damages, and expenses, and reasonable attorney
; fees arising out of, directly or indirectly, any claim of personal injury or
; death associated with such unintended or unauthorized use, even if such claim
; alleges that Motorola was negligent regarding the design or manufacture of the
; part.
;
; Motorola and the Motorola logo are registered trademarks of Motorola Ltd.
;
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  ************************
                    #Message  * Target: MC68HC08GP32 *
                    #Message  ************************

                    #HcsOff
                    #NoMMU                        ;MMU not available

_GP_                def       32
_GP32_              def       *

MAX_OS_CALLS        def       64                  ;default room for OS calls

;*******************************************************************************
; Memory Map and Interrupt Vectors
;*******************************************************************************

RAM                 def       $40                 ;start of RAM
RAM_END             def       $FF

XRAM                def       $0100
XRAM_END            def       $023F               ;last RAM location

ROM                 def       $8000               ;start of ROM
ROM_END             def       $FDFF               ;last ROM location

VECTORS             def       $FFDC

Vtimebase           def       $FFDC,2             ;Timebase vector
Vadc                def       $FFDE,2             ;ADC vector
Vkbd                def       $FFE0,2             ;Keyboard vector
Vscitx              def       $FFE2,2             ;SCI transmit vector
Vscirx              def       $FFE4,2             ;SCI receive vector
Vscierr             def       $FFE6,2             ;SCI error vector
Vspitx              def       $FFE8,2             ;SPI transmit vector
Vspirx              def       $FFEA,2             ;SPI receive vector
Vtim2ov             def       $FFEC,2             ;Timer 2 overflow vector
Vtim2ch1            def       $FFEE,2             ;Timer 2 channel 1 vector
Vtim2ch0            def       $FFF0,2             ;Timer 2 channel 0 vector
Vtim1ov             def       $FFF2,2             ;Timer 1 oveflow vector
Vtim1ch1            def       $FFF4,2             ;Timer 1 channel 1 vector
Vtim1ch0            def       $FFF6,2             ;Timer 1 channel 0 vector
Vpll                def       $FFF8,2             ;PLL vector
Virq                def       $FFFA,2             ;IRQ vector
Vswi                def       $FFFC,2             ;SWI vector
Vreset              def       $FFFE,2             ;Reset vector

;*******************************************************************************
; Input/Output (I/O) Ports
;*******************************************************************************

PORTA               def       $00,1               ;Port A Data Register
PORTB               def       $01,1               ;Port B Data Register
PORTC               def       $02,1               ;Port C Data Register
PORTD               def       $03,1               ;Port D Data Register
PORTE               def       $08,1               ;Port E Data Register

DDRA                def       $04,1               ;Port A Data Direction Register
DDRB                def       $05,1               ;Port B Data Direction Register
DDRC                def       $06,1               ;Port C Data Direction Register
DDRD                def       $07,1               ;Port D Data Direction Register
DDRE                def       $0C,1               ;Port E Data Direction Register

PTAPUE              def       $0D,1               ;Port A Input Pullup Enable Register
PTCPUE              def       $0E,1               ;Port C Input Pullup Enable Register
PTDPUE              def       $0F,1               ;Port D Input Pullup Enable Register

;*******************************************************************************
; Serial Peripheral Interface Module (SPI)
;*******************************************************************************

SPCR                def       $10,1               ;SPI Control Register
SPRIE.              def       7                   ;SPI receiver interrupt enable bit
SPMSTR.             def       5                   ;SPI master bit
CPOL.               def       4                   ;clock polarity bit
CPHA.               def       3                   ;clock phase bit
SPWOM.              def       2                   ;SPI wired-or mode bit
SPE.                def       1                   ;SPI enable
SPTIE.              def       0                   ;SPI transmit interrupt enable

SPSCR               def       $11,1               ;SPI Status and Control Register
SPRF.               def       7                   ;SPI receiver full bit
ERRIE.              def       6                   ;error interrupt enable bit
OVRF.               def       5                   ;overflow bit
MODF.               def       4                   ;mode fault bit
SPTE.               def       3                   ;SPI transmitter empty bit
MODFEN.             def       2                   ;mode fault enable bit
SPR1.               def       1                   ;SPI baud rate
SPR0.               def       0                   ;select bits

SPDR                def       $12,1               ;SPI Data Register

;*******************************************************************************
; Serial Communications Interface (SCI)
;*******************************************************************************

                                                  ;SCI Control Register 1
SCC1                @port     $13,PTY,PEN,ILTY,WAKE,M,TXINV,ENSCI,LOOPS
                                                  ;SCI Control Register 2
SCC2                @port     $14,SBK,RWU,RE,TE,ILIE,SCRIE,TCIE,SCTIE
                                                  ;SCI Control Register 3
SCC3                @port     $15,PEIE,FEIE,NEIE,ORIE,DMATE,DMARE,T8,R8
                                                  ;SCI Status Register 1
SCS1                @port     $16,PE,FE,NF,OR,IDLE,SCRF,TC,SCTE
                                                  ;SCI Status Register 2
SCS2                @port     $17,RPF,BKF
SCDR                @port     $18                 ;SCI Data Register
SCBR                @port     $19                 ;SCI Baud Rate Register

;*******************************************************************************
; Keyboard Interrupt Module (KBI)
;*******************************************************************************

                                                  ;Keyboard Status and Control Register
INTKBSCR            @port     $1A,MODEK,IMASKK,ACKK,KEYF
                                                  ;Keyboard Interrupt Enable Register
INTKBIER            @port     $1B,KBIE0,KBIE1,KBIE2,KBIE3,KBIE4,KBIE5,KBIE6,KBIE7

;*******************************************************************************
; Timebase Module (TBM)
;*******************************************************************************

                                                  ;Timebase Control Register
TBCR                @port     $1C,,TBON,TBIE,TACK,TBR0,TBR1,TBR2,TBIF

;*******************************************************************************
; External Interrupt (IRQ)
;*******************************************************************************

                                                  ;IRQ Status and Control Register
INTSCR              @port     $1D,MODE,IMASK,ACK,IRQF

;*******************************************************************************
; Configuration Registers (CONFIG)
;*******************************************************************************

CONFIG2             @port     $1E                 ;Configuration Register 2
CONFIG1             @port     $1F                 ;Configuration Register 1

;*******************************************************************************
; Timer Interface module (TIM)
;*******************************************************************************

T1SC                @port     $20                 ;Timer 1 Status and Control Register
                                                  ;Timer 2 Status and Control Register
T2SC                @port     $2B,PS0,PS1,PS2,TRST,TSTOP,TOIE,TOF

T1SC0               @port     $25                 ;Timer 1 Channel 0 Status and Control Register
T1SC1               @port     $28                 ;Timer 1 Channel 1 Status and Control Register
T2SC0               @port     $30                 ;Timer 2 Channel 0 Status and Control Register
                                                  ;Timer 2 Channel 1 Status and Control Register
T2SC1               @port     $33,CHXMAX,TOVX,ELSxA,ELSxB,MSxA,MSxB,CHxIE,CHxF

T1CNT               @port     $21 2               ;Timer 1 Counter Register
T1CNTH              @port     $21                 ;Timer 1 Counter Register high
T1CNTL              @port     $22                 ;Timer 1 Counter Register low
T1MOD               @port     $23 2               ;Timer 1 Counter Modulo Register
T1MODH              @port     $23                 ;Timer 1 Counter Modulo Register high
T1MODL              @port     $24                 ;Timer 1 Counter Modulo Register low
T1CH0               @port     $26 2               ;Timer 1 Channel 0 Register
T1CH0H              @port     $26                 ;Timer 1 Channel 0 Register high
T1CH0L              @port     $27                 ;Timer 1 Channel 0 Register low
T1CH1               @port     $29 2               ;Timer 1 Channel 1 Register
T1CH1H              @port     $29                 ;Timer 1 Channel 1 Register high
T1CH1L              @port     $2A                 ;Timer 1 Channel 1 Register low

T2CNT               @port     $2C 2               ;Timer 2 Counter Register
T2CNTH              @port     $2C                 ;Timer 2 Counter Register high
T2CNTL              @port     $2D                 ;Timer 2 Counter Register low
T2MOD               @port     $2E                 ;Timer 2 Counter Module Register
T2MODH              @port     $2E                 ;Timer 2 Counter Module Register High
T2MODL              @port     $2F                 ;Timer 2 Counter Module Register Low
T2CH0               @port     $31 2               ;Timer 2 Channel 0 Register
T2CH0H              @port     $31                 ;Timer 2 Channel 0 Register High
T2CH0L              @port     $32                 ;Timer 2 Channel 0 Register low
;T2CH0L             @port     $33                 ;Timer 2 Channel 0 Register low
T2CH1               @port     $34 2               ;Timer 2 Channel 1 Register
T2CH1H              @port     $34                 ;Timer 2 Channel 1 Register High
T2CH1L              @port     $35                 ;Timer 2 Channel 1 Register low

;*******************************************************************************
; Clock Generator Module (CGMC)
;*******************************************************************************

                                                  ;PLL Control Register
PCTL                @port     $36,VPR0,VPR1,PRE0,PRE1,BCS,PLLON,PLLF,PLLIE

                                                  ;PLL Bandwidth Control Register
PBWC                @port     $37,,,,,,ACQ,LOCK,AUTO

PMS                 @port     $38 2               ;PLL Multiplier Select Register
PMSH                @port     $38                 ;PLL Multiplier Select High Register
PMSL                @port     $39                 ;PLL Multiplier Select Low Register
PMRS                @port     $3A                 ;PLL VCO Select Range Register
PMDS                @port     $3B                 ;PLL Reference Divider Select Register

;*******************************************************************************
; Analog-to-Digital Converter (ADC)
;*******************************************************************************

                                                  ;ADC Status and Control Register
ADSCR               @port     $3C,ADCH0,ADCH1,ADCH2,ADCH3,ADCH4,ADCO,AIEN,COCO
ADR                 @port     $3D                 ;ADC Data Register
                                                  ;ADC Clock Register
ADCLK               @port     $3E,,,,,ADICLK,ADIV0,ADIV1,ADIV2

;*******************************************************************************
; System Integration Module (SIM)
;*******************************************************************************

SBSR                @port     $FE00,,SBSW         ;SIM Break Status Register
                                                  ;SIM Reset Status Register
SRSR                @port     $FE01,,LVI,MODRST,ILAD,ILOP,COP,PIN,POR

SUBAR               @port     $FE02               ;SIM Upper Byte Address Register
SBFCR               @port     $FE03,,,,,,,,BCFE   ;SIM Break Flag Control Register
INT1                @port     $FE04               ;Interrupt Status Register 1
INT2                @port     $FE05               ;Interrupt Status Register 2
INT3                @port     $FE06               ;Interrupt Status Register 3

;*******************************************************************************
; Flash Memory
;*******************************************************************************

                                                  ;Flash Control Register
FLCR                @port     $FE08,PGM,ERASE,MASS,HVEN
FLBPR               @port     $FF7E               ;Flash Block Protect Register

;*******************************************************************************
; Breakpoint Module (BRK)
;*******************************************************************************

BRK                 @port     $FE09 2             ;Break Address Register
BRKH                @port     $FE09               ;Break Address Register High
BRKL                @port     $FE0A               ;Break Address Register Low
                                                  ;Break Status and Control Register
BRKSCR              @port     $FE0B,,,,,,,BRKA,BRKE

;*******************************************************************************
; Low-Voltage Inhibit (LVI)
;*******************************************************************************

LVISR               @port     $FE0C,,,,,,,,LVIOUT ;LVI Status Register

;*******************************************************************************
; Computer Operating Properly (COP)
;*******************************************************************************

COPCTL              @port     $FFFF               ;COP Control Register
COP                 @port     COPCTL

;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

                    #VECTORS
                    org       VECTORS

                    #RAM
                    org       RAM

                    #XRAM
                    org       XRAM

                    #ROM
                    org       ROM
