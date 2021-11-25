PTA                 equ       $0000               ;Ports and data direction
PORTA               equ       $0000
PTB                 equ       $0001
PORTB               equ       $0001
PTC                 equ       $0002
PORTC               equ       $0002
PTD                 equ       $0003
PORTD               equ       $0003
DDRA                equ       $0004
DDRB                equ       $0005
DDRC                equ       $0006
DDRD                equ       $0007
PTE                 equ       $0008
PORTE               equ       $0008
PTF                 equ       $0009
PORTF               equ       $0009
DDRE                equ       $000C
DDRF                equ       $000D

TASC                equ       $000E               ;Timer A
TACNTH              equ       $000F
TACNTL              equ       $0010
TAMODH              equ       $0011
TAMODL              equ       $0012
TASC0               equ       $0013
TACH0H              equ       $0014
TACH0L              equ       $0015
TASC1               equ       $0016
TACH1H              equ       $0017
TACH1L              equ       $0018
TASC2               equ       $0019
TACH2H              equ       $001A
TACH2L              equ       $001B
TASC3               equ       $001C
TACH3H              equ       $001D
TACH3L              equ       $001E

CONFIG              equ       $001F               ;System configuration

PCTL1               equ       $0020               ;Pulse width modulator
PCTL2               equ       $0021
FCR                 equ       $0022
FSR                 equ       $0023
FTACK               equ       $0024
PWMOUT              equ       $0025
PCNTH               equ       $0026
PCNTL               equ       $0027
PMODH               equ       $0028
PMODL               equ       $0029
PVAL1H              equ       $002A
PVAL1L              equ       $002B
PVAL2H              equ       $002C
PVAL2L              equ       $002D
PVAL3H              equ       $002E
PVAL3L              equ       $002F
PVAL4H              equ       $0030
PVAL4L              equ       $0031
PVAL5H              equ       $0032
PVAL5L              equ       $0033
PVAL6H              equ       $0034
PVAL6L              equ       $0035
DEADTM              equ       $0036
DISMAP              equ       $0037

SCC1                equ       $0038               ;SCI (Asyncronous communications)
SCC2                equ       $0039
SCC3                equ       $003A
SCS1                equ       $003B
SCS2                equ       $003C
SCDR                equ       $003D
SCBR                equ       $003E

INTSCR              equ       $003F               ;IRQ status/control
ISCR                equ       $003F

ADSCR               equ       $0040               ;A/D converter
ADRH                equ       $0041
ADRL                equ       $0042
ADCLK               equ       $0043

SPCR                equ       $0044               ;SPI (Syncronous communications)
SPSCR               equ       $0045
SPDR                equ       $0046

TBSC                equ       $0051               ;Timer B
TBCNTH              equ       $0052
TBCNTL              equ       $0053
TBMODH              equ       $0054
TBMODL              equ       $0055
TBSC0               equ       $0056
TBCH0H              equ       $0057
TBCH0L              equ       $0058
TBSC1               equ       $0059
TBCH1H              equ       $005A
TBCH1L              equ       $005B

PCTL                equ       $005C               ;Clock Generator Module
PBWC                equ       $005D
PPG                 equ       $005E

SBSR                equ       $FE00               ;System integration
SRSR                equ       $FE01
SBFCR               equ       $FE03

FLCR                equ       $FE08

BRKH                equ       $FE0C               ;Hardware breakpoint
BRKL                equ       $FE0D
BRKSCR              equ       $FE0E

LVISR               equ       $FE0C               ;Low voltage detect
FLBPR               equ       $FF7E               ;Flash boot protect

COPCTL              equ       $FFFF               ;COP (Computer operating properly) control
