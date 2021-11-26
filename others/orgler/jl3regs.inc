; 68HC908JL3, 68HC908JK3, 68HC908JK1 Equates

PTA                 equ       $0000               ; Ports and data direction
PORTA               equ       $0000
PTB                 equ       $0001
PORTB               equ       $0001
PTD                 equ       $0003
PORTD               equ       $0003

DDR                 equ       4                   ; offset to respective DDR register

DDRA                equ       PORTA+DDR
DDRB                equ       PORTB+DDR
DDRD                equ       PORTD+DDR

PDCR                equ       $000A
PTAUE               equ       $000D

INTKBSR             equ       $001A               ; IRQ & Keyboard
KBSCR               equ       $001A
INTKBIER            equ       $001B
KBIER               equ       $001B

INTSCR              equ       $001D

CONFIG1             equ       $001F               ; System configuration register
CONFIG2             equ       $001E               ; System configuration register

TSC                 equ       $0020               ; Timer
TCNTH               equ       $0021
TCNTL               equ       $0022
TMODH               equ       $0023
TMODL               equ       $0024
TSC0                equ       $0025
TCH0H               equ       $0026
TCH0L               equ       $0027
TSC1                equ       $0028
TCH1H               equ       $0029
TCH1L               equ       $002A

ADSCR               equ       $003C               ; ADC Converter
ADR                 equ       $003D
ADCLK               equ       $003E

BSR                 equ       $FE00               ; SIM Module
RSR                 equ       $FE01
BFCR                equ       $FE03

FLCR                equ       $FE08               ; Flash control
FLSPR               equ       $FE09
FLTCR               equ       $FE0A

BRKH                equ       $FE0C               ; Break control
BRKL                equ       $FE0D
BSCR                equ       $FE0E

INT1                equ       $FE04               ; Interrupt Status
INT2                equ       $FE05
INT3                equ       $FE06

COPCTL              equ       $FFFF               ; COP control register

BIT0                equ       $01
BIT1                equ       $02
BIT2                equ       $04
BIT3                equ       $08
BIT4                equ       $10
BIT5                equ       $20
BIT6                equ       $40
BIT7                equ       $80

BIT0_INVERS         equ       $FE
BIT1_INVERS         equ       $FD
BIT2_INVERS         equ       $FB
BIT3_INVERS         equ       $F7
BIT4_INVERS         equ       $EF
BIT5_INVERS         equ       $DF
BIT6_INVERS         equ       $BF
BIT7_INVERS         equ       $7F
