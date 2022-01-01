;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908EY16A, version 2.89.115 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908ey16a.inc
;     Processor : MC68HC908EY16AKFAE
;     FileFormat: V2.28
;     DataSheet : MC68HC908EY16A Rev. 0 04/2006
;     Compiler  : CodeWarrior compiler
;     Date/Time : 27.5.2009, 9:59
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;      - 14.11.2005, V2.00 :
;               - Deprecated symbols added for backward compatibility (section at the end of this file)
;      - 15.11.2005, V2.01 :
;               - Changes have not affected this file (because they are related to another family)
;      - 17.12.2005, V2.02 :
;               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
;      - 16.01.2006, V2.03 :
;               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
;               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
;      - 08.03.2006, V2.04 :
;               - Support for bit(s) names duplicated with any register name in .h header files
;      - 24.03.2006, V2.05 :
;               - Changes have not affected this file (because they are related to another family)
;      - 26.04.2006, V2.06 :
;               - Absolute assembly supported (depreciated symbols are not defined)
;      - 27.04.2006, V2.07 :
;               - Fixed macro __RESET_WATCHDOG for HCS12, HCS12X ,HCS08 DZ and HCS08 EN derivatives (write 0x55,0xAA).
;      - 07.06.2006, V2.08 :
;               - For .inc files added constants "RAMStart" and "RAMEnd" even there is only Z_RAM.
;      - 03.07.2006, V2.09 :
;               - Flash commands constants supported
;      - 27.10.2006, V2.10 :
;               - __RESET_WATCHDOG improved formating and re-definition
;      - 23.11.2006, V2.11 :
;               - Changes have not affected this file (because they are related to another family)
;      - 22.01.2007, V2.12 :
;               - Changes have not affected this file (because they are related to another family)
;      - 01.03.2007, V2.13 :
;               - Flash commands constants values converted to HEX format
;      - 02.03.2007, V2.14 :
;               - Interrupt vector numbers added into .H, see VectorNumber_*
;      - 26.03.2007, V2.15 :
;               - Changes have not affected this file (because they are related to another family)
;      - 10.05.2007, V2.16 :
;               - Fixed flash commands definition for ColdFireV1 assembler (equ -> .equ)
;      - 05.06.2007, V2.17 :
;               - Changes have not affected this file (because they are related to another family)
;      - 19.07.2007, V2.18 :
;               - Improved number of blanked lines inside register structures
;      - 06.08.2007, V2.19 :
;               - CPUDB revisions generated ahead of the file-format revisions.
;      - 11.09.2007, V2.20 :
;               - Added comment about initialization of unbonded pins.
;      - 02.01.2008, V2.21 :
;               - Changes have not affected this file (because they are related to another family)
;      - 13.02.2008, V2.22 :
;               - Changes have not affected this file (because they are related to another family)
;      - 20.02.2008, V2.23 :
;               - Changes have not affected this file (because they are related to another family)
;      - 03.07.2008, V2.24 :
;               - Added support for bits with name starting with number (like "1HZ")
;      - 28.11.2008, V2.25 :
;               - StandBy RAM array declaration for ANSI-C added
;      - 1.12.2008, V2.26 :
;               - Duplication of bit (or bit-group) name with register name is not marked as a problem, is register is internal only and it is not displayed in I/O map.
;      - 17.3.2009, V2.27 :
;               - Merged bit-group is not generated, if the name matchs with anouther bit name in the register
;      - 6.4.2009, V2.28 :
;               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000C000
ROM_END             equ       $0000FDFF
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000023F
;
INT_TBM             equ       $0000FFDC
INT_SPITransmit     equ       $0000FFDE
INT_SPIReceive      equ       $0000FFE0
INT_ADC             equ       $0000FFE2
INT_KBI             equ       $0000FFE4
INT_SCITransmit     equ       $0000FFE6
INT_SCIReceive      equ       $0000FFE8
INT_SCIError        equ       $0000FFEA
INT_TIMBOvr         equ       $0000FFEC
INT_TIMBCH1         equ       $0000FFEE
INT_TIMBCH0         equ       $0000FFF0
INT_TIMAOvr         equ       $0000FFF2
INT_TIMACH1         equ       $0000FFF4
INT_TIMACH0         equ       $0000FFF6
INT_ICG             equ       $0000FFF8
INT_IRQ1            equ       $0000FFFA
INT_SWI             equ       $0000FFFC
INT_RESET           equ       $0000FFFE
;

;*** PTA - Port A Data Register
PTA                 equ       $00000000           ;*** PTA - Port A Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTA_PTA0            equ       0                   ; Port A Data Bit 0
PTA_PTA1            equ       1                   ; Port A Data Bit 1
PTA_PTA2            equ       2                   ; Port A Data Bit 2
PTA_PTA3            equ       3                   ; Port A Data Bit 3
PTA_PTA4            equ       4                   ; Port A Data Bit 4
PTA_PTA5            equ       5                   ; Port A Data Bit 5
PTA_PTA6            equ       6                   ; Port A Data Bit 6
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000
mPTA_PTA5           equ       %00100000
mPTA_PTA6           equ       %01000000

;*** PTB - Port B Data Register
PTB                 equ       $00000001           ;*** PTB - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTB_PTB0            equ       0                   ; Port B Data Bit 0
PTB_PTB1            equ       1                   ; Port B Data Bit 1
PTB_PTB2            equ       2                   ; Port B Data Bit 2
PTB_PTB3            equ       3                   ; Port B Data Bit 3
PTB_PTB4            equ       4                   ; Port B Data Bit 4
PTB_PTB5            equ       5                   ; Port B Data Bit 5
PTB_PTB6            equ       6                   ; Port B Data Bit 6
PTB_PTB7            equ       7                   ; Port B Data Bit 7
; bit position masks
mPTB_PTB0           equ       %00000001
mPTB_PTB1           equ       %00000010
mPTB_PTB2           equ       %00000100
mPTB_PTB3           equ       %00001000
mPTB_PTB4           equ       %00010000
mPTB_PTB5           equ       %00100000
mPTB_PTB6           equ       %01000000
mPTB_PTB7           equ       %10000000

;*** PTC - Port C Data Register
PTC                 equ       $00000002           ;*** PTC - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTC_PTC0            equ       0                   ; Port C Data Bit 0
PTC_PTC1            equ       1                   ; Port C Data Bit 1
PTC_PTC2            equ       2                   ; Port C Data Bit 2
PTC_PTC3            equ       3                   ; Port C Data Bit 3
PTC_PTC4            equ       4                   ; Port C Data Bit 4
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010
mPTC_PTC2           equ       %00000100
mPTC_PTC3           equ       %00001000
mPTC_PTC4           equ       %00010000

;*** PTD - Port D Data Register
PTD                 equ       $00000003           ;*** PTD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTD_PTD0            equ       0                   ; Port D Data Bit 0
PTD_PTD1            equ       1                   ; Port D Data Bit 1
; bit position masks
mPTD_PTD0           equ       %00000001
mPTD_PTD1           equ       %00000010

;*** DDRA - Data Direction Register A
DDRA                equ       $00000004           ;*** DDRA - Data Direction Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRA_DDRA0          equ       0                   ; Data Direction Register A Bit 0
DDRA_DDRA1          equ       1                   ; Data Direction Register A Bit 1
DDRA_DDRA2          equ       2                   ; Data Direction Register A Bit 2
DDRA_DDRA3          equ       3                   ; Data Direction Register A Bit 3
DDRA_DDRA4          equ       4                   ; Data Direction Register A Bit 4
DDRA_DDRA5          equ       5                   ; Data Direction Register A Bit 5
DDRA_DDRA6          equ       6                   ; Data Direction Register A Bit 6
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA2         equ       %00000100
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000
mDDRA_DDRA5         equ       %00100000
mDDRA_DDRA6         equ       %01000000

;*** DDRB - Data Direction Register B
DDRB                equ       $00000005           ;*** DDRB - Data Direction Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRB_DDRB0          equ       0                   ; Data Direction Register B Bit 0
DDRB_DDRB1          equ       1                   ; Data Direction Register B Bit 1
DDRB_DDRB2          equ       2                   ; Data Direction Register B Bit 2
DDRB_DDRB3          equ       3                   ; Data Direction Register B Bit 3
DDRB_DDRB4          equ       4                   ; Data Direction Register B Bit 4
DDRB_DDRB5          equ       5                   ; Data Direction Register B Bit 5
DDRB_DDRB6          equ       6                   ; Data Direction Register B Bit 6
DDRB_DDRB7          equ       7                   ; Data Direction Register B Bit 7
; bit position masks
mDDRB_DDRB0         equ       %00000001
mDDRB_DDRB1         equ       %00000010
mDDRB_DDRB2         equ       %00000100
mDDRB_DDRB3         equ       %00001000
mDDRB_DDRB4         equ       %00010000
mDDRB_DDRB5         equ       %00100000
mDDRB_DDRB6         equ       %01000000
mDDRB_DDRB7         equ       %10000000

;*** DDRC - Data Direction Register C
DDRC                equ       $00000006           ;*** DDRC - Data Direction Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRC_DDRC0          equ       0                   ; Data Direction Register C Bit 0
DDRC_DDRC1          equ       1                   ; Data Direction Register C Bit 1
DDRC_DDRC2          equ       2                   ; Data Direction Register C Bit 2
DDRC_DDRC3          equ       3                   ; Data Direction Register C Bit 3
DDRC_DDRC4          equ       4                   ; Data Direction Register C Bit 4
DDRC_MCLKEN         equ       7                   ; MCLK Enable Bit
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000
mDDRC_DDRC4         equ       %00010000
mDDRC_MCLKEN        equ       %10000000

;*** DDRD - Data Direction Register D
DDRD                equ       $00000007           ;*** DDRD - Data Direction Register D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRD_DDRD0          equ       0                   ; Data Direction Register D Bit 0
DDRD_DDRD1          equ       1                   ; Data Direction Register D Bit 1
; bit position masks
mDDRD_DDRD0         equ       %00000001
mDDRD_DDRD1         equ       %00000010

;*** PTE - Port E Data Register
PTE                 equ       $00000008           ;*** PTE - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTE_PTE0            equ       0                   ; Port E Data Bit 0
PTE_PTE1            equ       1                   ; Port E Data Bit 1
; bit position masks
mPTE_PTE0           equ       %00000001
mPTE_PTE1           equ       %00000010

;*** CONFIG3 - Configuration Register 3
CONFIG3             equ       $00000009           ;*** CONFIG3 - Configuration Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG3_SPISEL      equ       0                   ; SPI Pin Selection Bit
CONFIG3_ESCISEL     equ       1                   ; ESCI Pin Selection Bit
CONFIG3_PORTSRE     equ       2                   ; Slew Rate Enable for Ports
CONFIG3_MCLKSRE     equ       3                   ; Slew Rate Enable for MCLK
CONFIG3_SPISRE      equ       4                   ; Slew Rate Enable for SPI
CONFIG3_ESCISRE     equ       5                   ; Slew Rate Enable for ESCI
CONFIG3_RNGSEL      equ       6                   ; External Oscillator Frequency Range Select
; bit position masks
mCONFIG3_SPISEL     equ       %00000001
mCONFIG3_ESCISEL    equ       %00000010
mCONFIG3_PORTSRE    equ       %00000100
mCONFIG3_MCLKSRE    equ       %00001000
mCONFIG3_SPISRE     equ       %00010000
mCONFIG3_ESCISRE    equ       %00100000
mCONFIG3_RNGSEL     equ       %01000000

;*** DDRE - Data Direction Register E
DDRE                equ       $0000000A           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0          equ       0                   ; Data Direction Register E Bit 0
DDRE_DDRE1          equ       1                   ; Data Direction Register E Bit 1
; bit position masks
mDDRE_DDRE0         equ       %00000001
mDDRE_DDRE1         equ       %00000010

;*** BEMF - BEMF Register
BEMF                equ       $0000000B           ;*** BEMF - BEMF Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BEMF_BEMF0          equ       0                   ; BEMF Counter Bit 0
BEMF_BEMF1          equ       1                   ; BEMF Counter Bit 1
BEMF_BEMF2          equ       2                   ; BEMF Counter Bit 2
BEMF_BEMF3          equ       3                   ; BEMF Counter Bit 3
BEMF_BEMF4          equ       4                   ; BEMF Counter Bit 4
BEMF_BEMF5          equ       5                   ; BEMF Counter Bit 5
BEMF_BEMF6          equ       6                   ; BEMF Counter Bit 6
BEMF_BEMF7          equ       7                   ; BEMF Counter Bit 7
; bit position masks
mBEMF_BEMF0         equ       %00000001
mBEMF_BEMF1         equ       %00000010
mBEMF_BEMF2         equ       %00000100
mBEMF_BEMF3         equ       %00001000
mBEMF_BEMF4         equ       %00010000
mBEMF_BEMF5         equ       %00100000
mBEMF_BEMF6         equ       %01000000
mBEMF_BEMF7         equ       %10000000

;*** KBIPR - Keyboard Interrupt Polarity Register
KBIPR               equ       $0000000C           ;*** KBIPR - Keyboard Interrupt Polarity Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPR_KBIP0         equ       0                   ; Keyboard Interrupt Polarity Bit 0
KBIPR_KBIP1         equ       1                   ; Keyboard Interrupt Polarity Bit 1
KBIPR_KBIP2         equ       2                   ; Keyboard Interrupt Polarity Bit 2
KBIPR_KBIP3         equ       3                   ; Keyboard Interrupt Polarity Bit 3
KBIPR_KBIP4         equ       4                   ; Keyboard Interrupt Polarity Bit 4
; bit position masks
mKBIPR_KBIP0        equ       %00000001
mKBIPR_KBIP1        equ       %00000010
mKBIPR_KBIP2        equ       %00000100
mKBIPR_KBIP3        equ       %00001000
mKBIPR_KBIP4        equ       %00010000

;*** SPCR - SPI Control Register
SPCR                equ       $0000000D           ;*** SPCR - SPI Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPCR_SPTIE          equ       0                   ; SPI Transmit Interrupt Enable Bit
SPCR_SPE            equ       1                   ; SPI Enable Bit
SPCR_SPWOM          equ       2                   ; SPI Wired-OR Mode Bit
SPCR_CPHA           equ       3                   ; Clock Phase Bit
SPCR_CPOL           equ       4                   ; Clock Polarity Bit
SPCR_SPMSTR         equ       5                   ; SPI Master Bit
SPCR_SPRIE          equ       7                   ; SPI Receiver Interrupt Enable Bit
; bit position masks
mSPCR_SPTIE         equ       %00000001
mSPCR_SPE           equ       %00000010
mSPCR_SPWOM         equ       %00000100
mSPCR_CPHA          equ       %00001000
mSPCR_CPOL          equ       %00010000
mSPCR_SPMSTR        equ       %00100000
mSPCR_SPRIE         equ       %10000000

;*** SPSCR - SPI Status and Control Register
SPSCR               equ       $0000000E           ;*** SPSCR - SPI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPSCR_SPR0          equ       0                   ; SPI Baud Rate Select Bit 0
SPSCR_SPR1          equ       1                   ; SPI Baud Rate Select Bit 1
SPSCR_MODFEN        equ       2                   ; Mode Fault Enable Bit
SPSCR_SPTE          equ       3                   ; SPI Transmitter Empty Bit
SPSCR_MODF          equ       4                   ; Mode Fault Bit
SPSCR_OVRF          equ       5                   ; Overflow Bit
SPSCR_ERRIE         equ       6                   ; Error Interrupt Enable Bit
SPSCR_SPRF          equ       7                   ; SPI Receiver Full Bit
; bit position masks
mSPSCR_SPR0         equ       %00000001
mSPSCR_SPR1         equ       %00000010
mSPSCR_MODFEN       equ       %00000100
mSPSCR_SPTE         equ       %00001000
mSPSCR_MODF         equ       %00010000
mSPSCR_OVRF         equ       %00100000
mSPSCR_ERRIE        equ       %01000000
mSPSCR_SPRF         equ       %10000000

;*** SPDR - SPI Data Register
SPDR                equ       $0000000F           ;*** SPDR - SPI Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPDR_R0_T0          equ       0                   ; Receive/Transmit Data Bit 0
SPDR_R1_T1          equ       1                   ; Receive/Transmit Data Bit 1
SPDR_R2_T2          equ       2                   ; Receive/Transmit Data Bit 2
SPDR_R3_T3          equ       3                   ; Receive/Transmit Data Bit 3
SPDR_R4_T4          equ       4                   ; Receive/Transmit Data Bit 4
SPDR_R5_T5          equ       5                   ; Receive/Transmit Data Bit 5
SPDR_R6_T6          equ       6                   ; Receive/Transmit Data Bit 6
SPDR_R7_T7          equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSPDR_R0_T0         equ       %00000001
mSPDR_R1_T1         equ       %00000010
mSPDR_R2_T2         equ       %00000100
mSPDR_R3_T3         equ       %00001000
mSPDR_R4_T4         equ       %00010000
mSPDR_R5_T5         equ       %00100000
mSPDR_R6_T6         equ       %01000000
mSPDR_R7_T7         equ       %10000000

;*** SCC1 - ESCI Control Register 1
SCC1                equ       $00000010           ;*** SCC1 - ESCI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC1_PTY            equ       0                   ; Parity Bit
SCC1_PEN            equ       1                   ; Parity Enable Bit
SCC1_ILTY           equ       2                   ; Idle Line Type Bit
SCC1_WAKE           equ       3                   ; Wakeup Condition Bit
SCC1_M              equ       4                   ; Mode (Character Length) Bit
SCC1_TXINV          equ       5                   ; Transmit Inversion Bit
SCC1_ENSCI          equ       6                   ; Enable SCI Bit
SCC1_LOOPS          equ       7                   ; Loop Mode Select Bit
; bit position masks
mSCC1_PTY           equ       %00000001
mSCC1_PEN           equ       %00000010
mSCC1_ILTY          equ       %00000100
mSCC1_WAKE          equ       %00001000
mSCC1_M             equ       %00010000
mSCC1_TXINV         equ       %00100000
mSCC1_ENSCI         equ       %01000000
mSCC1_LOOPS         equ       %10000000

;*** SCC2 - ESCI Control Register 2
SCC2                equ       $00000011           ;*** SCC2 - ESCI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC2_SBK            equ       0                   ; Send Break Bit
SCC2_RWU            equ       1                   ; Receiver Wakeup Bit
SCC2_RE             equ       2                   ; Receiver Enable Bit
SCC2_TE             equ       3                   ; Transmitter Enable Bit
SCC2_ILIE           equ       4                   ; Idle Line Interrupt Enable Bit
SCC2_SCRIE          equ       5                   ; ESCI Receive Interrupt Enable Bit
SCC2_TCIE           equ       6                   ; Transmission Complete Interrupt Enable Bit
SCC2_SCTIE          equ       7                   ; ESCI Transmit Interrupt Enable Bit
; bit position masks
mSCC2_SBK           equ       %00000001
mSCC2_RWU           equ       %00000010
mSCC2_RE            equ       %00000100
mSCC2_TE            equ       %00001000
mSCC2_ILIE          equ       %00010000
mSCC2_SCRIE         equ       %00100000
mSCC2_TCIE          equ       %01000000
mSCC2_SCTIE         equ       %10000000

;*** SCC3 - ESCI Control Register 3
SCC3                equ       $00000012           ;*** SCC3 - ESCI Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC3_PEIE           equ       0                   ; Receiver Parity Error Interrupt Enable Bit
SCC3_FEIE           equ       1                   ; Receiver Framing Error Interrupt Enable Bit
SCC3_NEIE           equ       2                   ; Receiver Noise Error Interrupt Enable Bit
SCC3_ORIE           equ       3                   ; Receiver Overrun Interrupt Enable Bit
SCC3_T8             equ       6                   ; Transmitted Bit 8
SCC3_R8             equ       7                   ; Received Bit 8
; bit position masks
mSCC3_PEIE          equ       %00000001
mSCC3_FEIE          equ       %00000010
mSCC3_NEIE          equ       %00000100
mSCC3_ORIE          equ       %00001000
mSCC3_T8            equ       %01000000
mSCC3_R8            equ       %10000000

;*** SCS1 - SCI Status Register 1
SCS1                equ       $00000013           ;*** SCS1 - SCI Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS1_PE             equ       0                   ; Receiver Parity Error Bit
SCS1_FE             equ       1                   ; Receiver Framing Error Bit
SCS1_NF             equ       2                   ; Receiver Noise Flag Bit
SCS1_OR             equ       3                   ; Receiver Overrun Bit
SCS1_IDLE           equ       4                   ; Receiver Idle Bit
SCS1_SCRF           equ       5                   ; ESCI Receiver Full Bit
SCS1_TC             equ       6                   ; Transmission Complete Bit
SCS1_SCTE           equ       7                   ; ESCI Transmitter Empty Bit
; bit position masks
mSCS1_PE            equ       %00000001
mSCS1_FE            equ       %00000010
mSCS1_NF            equ       %00000100
mSCS1_OR            equ       %00001000
mSCS1_IDLE          equ       %00010000
mSCS1_SCRF          equ       %00100000
mSCS1_TC            equ       %01000000
mSCS1_SCTE          equ       %10000000

;*** SCS2 - SCI Status Register 2
SCS2                equ       $00000014           ;*** SCS2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS2_RPF            equ       0                   ; Reception in Progress Flag Bit
SCS2_BKF            equ       1                   ; Break Flag Bit
; bit position masks
mSCS2_RPF           equ       %00000001
mSCS2_BKF           equ       %00000010

;*** SCDR - SCI Data Register
SCDR                equ       $00000015           ;*** SCDR - SCI Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCDR_R0_T0          equ       0                   ; Receive/Transmit Data Bit 0
SCDR_R1_T1          equ       1                   ; Receive/Transmit Data Bit 1
SCDR_R2_T2          equ       2                   ; Receive/Transmit Data Bit 2
SCDR_R3_T3          equ       3                   ; Receive/Transmit Data Bit 3
SCDR_R4_T4          equ       4                   ; Receive/Transmit Data Bit 4
SCDR_R5_T5          equ       5                   ; Receive/Transmit Data Bit 5
SCDR_R6_T6          equ       6                   ; Receive/Transmit Data Bit 6
SCDR_R7_T7          equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCDR_R0_T0         equ       %00000001
mSCDR_R1_T1         equ       %00000010
mSCDR_R2_T2         equ       %00000100
mSCDR_R3_T3         equ       %00001000
mSCDR_R4_T4         equ       %00010000
mSCDR_R5_T5         equ       %00100000
mSCDR_R6_T6         equ       %01000000
mSCDR_R7_T7         equ       %10000000

;*** SCBR - SCI Baud Rate Register
SCBR                equ       $00000016           ;*** SCBR - SCI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCBR_SCR0           equ       0                   ; ESCI Baud Rate Select Bit 0
SCBR_SCR1           equ       1                   ; ESCI Baud Rate Select Bit 1
SCBR_SCR2           equ       2                   ; ESCI Baud Rate Select Bit 2
SCBR_SCP0           equ       4                   ; ESCI Baud Rate Prescaler Bit 0
SCBR_SCP1           equ       5                   ; ESCI Baud Rate Prescaler Bit 1
SCBR_LINR           equ       6                   ; LIN Receiver Bit
SCBR_LINT           equ       7                   ; LIN Break Symbol Transmit Enable
; bit position masks
mSCBR_SCR0          equ       %00000001
mSCBR_SCR1          equ       %00000010
mSCBR_SCR2          equ       %00000100
mSCBR_SCP0          equ       %00010000
mSCBR_SCP1          equ       %00100000
mSCBR_LINR          equ       %01000000
mSCBR_LINT          equ       %10000000

;*** SCPSC - ESCI Prescale Register
SCPSC               equ       $00000017           ;*** SCPSC - ESCI Prescale Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCPSC_PSSB0         equ       0                   ; Clock Insertion Select Bit 0
SCPSC_PSSB1         equ       1                   ; Clock Insertion Select Bit 1
SCPSC_PSSB2         equ       2                   ; Clock Insertion Select Bit 2
SCPSC_PSSB3         equ       3                   ; Clock Insertion Select Bit 3
SCPSC_PSSB4         equ       4                   ; Clock Insertion Select Bit 4
SCPSC_PDS0          equ       5                   ; Prescaler Divisor Select Bit 0
SCPSC_PDS1          equ       6                   ; Prescaler Divisor Select Bit 1
SCPSC_PDS2          equ       7                   ; Prescaler Divisor Select Bit 2
; bit position masks
mSCPSC_PSSB0        equ       %00000001
mSCPSC_PSSB1        equ       %00000010
mSCPSC_PSSB2        equ       %00000100
mSCPSC_PSSB3        equ       %00001000
mSCPSC_PSSB4        equ       %00010000
mSCPSC_PDS0         equ       %00100000
mSCPSC_PDS1         equ       %01000000
mSCPSC_PDS2         equ       %10000000

;*** SCIACTL - ESCI Arbiter Control Register
SCIACTL             equ       $00000018           ;*** SCIACTL - ESCI Arbiter Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIACTL_ARD8        equ       0                   ; Arbiter Counter MSB
SCIACTL_AROVFL      equ       1                   ; Arbiter Counter Overflow Bit
SCIACTL_ARUN        equ       2                   ; Arbiter Counter Running Flag
SCIACTL_AFIN        equ       3                   ; Arbiter Bit Time Measurement Finish Flag
SCIACTL_ACLK        equ       4                   ; Arbiter Counter Clock Select Bit
SCIACTL_AM0         equ       5                   ; Arbiter Mode Select Bit 0
SCIACTL_ALOST       equ       6                   ; Arbitration Lost Flag
SCIACTL_AM1         equ       7                   ; Arbiter Mode Select Bit 1
; bit position masks
mSCIACTL_ARD8       equ       %00000001
mSCIACTL_AROVFL     equ       %00000010
mSCIACTL_ARUN       equ       %00000100
mSCIACTL_AFIN       equ       %00001000
mSCIACTL_ACLK       equ       %00010000
mSCIACTL_AM0        equ       %00100000
mSCIACTL_ALOST      equ       %01000000
mSCIACTL_AM1        equ       %10000000

;*** SCIADAT - ESCI Arbiter Data Register
SCIADAT             equ       $00000019           ;*** SCIADAT - ESCI Arbiter Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIADAT_ARD0        equ       0                   ; Arbiter Least Significant Counter Bit 0
SCIADAT_ARD1        equ       1                   ; Arbiter Least Significant Counter Bit 1
SCIADAT_ARD2        equ       2                   ; Arbiter Least Significant Counter Bit 2
SCIADAT_ARD3        equ       3                   ; Arbiter Least Significant Counter Bit 3
SCIADAT_ARD4        equ       4                   ; Arbiter Least Significant Counter Bit 4
SCIADAT_ARD5        equ       5                   ; Arbiter Least Significant Counter Bit 5
SCIADAT_ARD6        equ       6                   ; Arbiter Least Significant Counter Bit 6
SCIADAT_ARD7        equ       7                   ; Arbiter Least Significant Counter Bit 7
; bit position masks
mSCIADAT_ARD0       equ       %00000001
mSCIADAT_ARD1       equ       %00000010
mSCIADAT_ARD2       equ       %00000100
mSCIADAT_ARD3       equ       %00001000
mSCIADAT_ARD4       equ       %00010000
mSCIADAT_ARD5       equ       %00100000
mSCIADAT_ARD6       equ       %01000000
mSCIADAT_ARD7       equ       %10000000

;*** KBSCR - Keyboard Status and Control Register
KBSCR               equ       $0000001A           ;*** KBSCR - Keyboard Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBSCR_MODEK         equ       0                   ; Keyboard Triggering Sensitivity Bit
KBSCR_IMASKK        equ       1                   ; Keyboard Interrupt Mask Bit
KBSCR_ACKK          equ       2                   ; Keyboard Acknowledge Bit
KBSCR_KEYF          equ       3                   ; Keyboard Flag Bit
; bit position masks
mKBSCR_MODEK        equ       %00000001
mKBSCR_IMASKK       equ       %00000010
mKBSCR_ACKK         equ       %00000100
mKBSCR_KEYF         equ       %00001000

;*** KBIER - Keyboard Interrupt Enable Register
KBIER               equ       $0000001B           ;*** KBIER - Keyboard Interrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIER_KBIE0         equ       0                   ; Keyboard Interrupt Enable Bit 0
KBIER_KBIE1         equ       1                   ; Keyboard Interrupt Enable Bit 1
KBIER_KBIE2         equ       2                   ; Keyboard Interrupt Enable Bit 2
KBIER_KBIE3         equ       3                   ; Keyboard Interrupt Enable Bit 3
KBIER_KBIE4         equ       4                   ; Keyboard Interrupt Enable Bit 4
; bit position masks
mKBIER_KBIE0        equ       %00000001
mKBIER_KBIE1        equ       %00000010
mKBIER_KBIE2        equ       %00000100
mKBIER_KBIE3        equ       %00001000
mKBIER_KBIE4        equ       %00010000

;*** TBCR - Timebase Control Register
TBCR                equ       $0000001C           ;*** TBCR - Timebase Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBCR_TBON           equ       1                   ; Timebase Enabled Bit
TBCR_TBIE           equ       2                   ; Timebase Interrupt Enabled Bit
TBCR_TACK           equ       3                   ; Timebase ACKnowledge Bit
TBCR_TBR0           equ       4                   ; Timebase Divider Selection Bit 0
TBCR_TBR1           equ       5                   ; Timebase Divider Selection Bit 1
TBCR_TBR2           equ       6                   ; Timebase Divider Selection Bit 2
TBCR_TBIF           equ       7                   ; Timebase Interrupt Flag
; bit position masks
mTBCR_TBON          equ       %00000010
mTBCR_TBIE          equ       %00000100
mTBCR_TACK          equ       %00001000
mTBCR_TBR0          equ       %00010000
mTBCR_TBR1          equ       %00100000
mTBCR_TBR2          equ       %01000000
mTBCR_TBIF          equ       %10000000

;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001D           ;*** INTSCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSCR_MODE         equ       0                   ; IRQ Edge/Level Select Bit
INTSCR_IMASK        equ       1                   ; IRQ Interrupt Mask Bit
INTSCR_ACK          equ       2                   ; IRQ Interrupt Request Acknowledge Bit
INTSCR_IRQF         equ       3                   ; IRQ Flag Bit
; bit position masks
mINTSCR_MODE        equ       %00000001
mINTSCR_IMASK       equ       %00000010
mINTSCR_ACK         equ       %00000100
mINTSCR_IRQF        equ       %00001000

;*** CONFIG2 - Configuration Register
CONFIG2             equ       $0000001E           ;*** CONFIG2 - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_SSBPUENB    equ       0                   ; SSB Pull-up Enable Bit
CONFIG2_OSCENINSTOP equ       1                   ; Oscillator Enable In Stop Mode Bit
CONFIG2_TMBCLKSEL   equ       2                   ; Timebase Clock Select Bit
CONFIG2_EXTCLKEN    equ       3                   ; External Clock Enable Bit
CONFIG2_EXTSLOW     equ       4                   ; Slow External Crystal Enable Bit
CONFIG2_EXTXTALEN   equ       5                   ; External Crystal Enable Bit
CONFIG2_ESCIBDSRC   equ       6                   ; ESCI Baud Rate Clock Source Bit
; bit position masks
mCONFIG2_SSBPUENB   equ       %00000001
mCONFIG2_OSCENINSTOP equ       %00000010
mCONFIG2_TMBCLKSEL  equ       %00000100
mCONFIG2_EXTCLKEN   equ       %00001000
mCONFIG2_EXTSLOW    equ       %00010000
mCONFIG2_EXTXTALEN  equ       %00100000
mCONFIG2_ESCIBDSRC  equ       %01000000

;*** CONFIG1 - Configuration Register
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVI5OR3     equ       3                   ; LVI 5-V or 3-V Operating Mode Bit
CONFIG1_LVIPWRD     equ       4                   ; LVI Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; LVI Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP Rate Select Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVI5OR3    equ       %00001000
mCONFIG1_LVIPWRD    equ       %00010000
mCONFIG1_LVIRSTD    equ       %00100000
mCONFIG1_LVISTOP    equ       %01000000
mCONFIG1_COPRS      equ       %10000000

;*** TASC - TIMA Status/Control Register
TASC                equ       $00000020           ;*** TASC - TIMA Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC_PS0            equ       0                   ; Prescaler Select Bit 0
TASC_PS1            equ       1                   ; Prescaler Select Bit 1
TASC_PS2            equ       2                   ; Prescaler Select Bit 2
TASC_TRST           equ       4                   ; TIMA Reset Bit
TASC_TSTOP          equ       5                   ; TIMA Stop Bit
TASC_TOIE           equ       6                   ; TIMA Overflow Interrupt Enable Bit
TASC_TOF            equ       7                   ; TIMA Overflow Flag Bit
; bit position masks
mTASC_PS0           equ       %00000001
mTASC_PS1           equ       %00000010
mTASC_PS2           equ       %00000100
mTASC_TRST          equ       %00010000
mTASC_TSTOP         equ       %00100000
mTASC_TOIE          equ       %01000000
mTASC_TOF           equ       %10000000

;*** TACNT - TIMA Counter Register
TACNT               equ       $00000021           ;*** TACNT - TIMA Counter Register

;*** TACNTH - TIMA Counter Register High
TACNTH              equ       $00000021           ;*** TACNTH - TIMA Counter Register High

;*** TACNTL - TIMA Counter Register Low
TACNTL              equ       $00000022           ;*** TACNTL - TIMA Counter Register Low

;*** TAMOD - TIMA Counter Modulo Register
TAMOD               equ       $00000023           ;*** TAMOD - TIMA Counter Modulo Register

;*** TAMODH - TIMA Counter Modulo Register
TAMODH              equ       $00000023           ;*** TAMODH - TIMA Counter Modulo Register

;*** TAMODL - TIMA Counter Modulo Register
TAMODL              equ       $00000024           ;*** TAMODL - TIMA Counter Modulo Register

;*** TASC0 - TIMA Channel 0 Status/Control Register
TASC0               equ       $00000025           ;*** TASC0 - TIMA Channel 0 Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
TASC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
TASC0_ELS0A         equ       2                   ; Edge/Level Select Bit A
TASC0_ELS0B         equ       3                   ; Edge/Level Select Bit B
TASC0_MS0A          equ       4                   ; Mode Select Bit A
TASC0_MS0B          equ       5                   ; Mode Select Bit B
TASC0_CH0IE         equ       6                   ; Channel 0 Interrupt Enable Bit
TASC0_CH0F          equ       7                   ; Channel 0 Flag Bit
; bit position masks
mTASC0_CH0MAX       equ       %00000001
mTASC0_TOV0         equ       %00000010
mTASC0_ELS0A        equ       %00000100
mTASC0_ELS0B        equ       %00001000
mTASC0_MS0A         equ       %00010000
mTASC0_MS0B         equ       %00100000
mTASC0_CH0IE        equ       %01000000
mTASC0_CH0F         equ       %10000000

;*** TACH0 - TIMA Channel 0 Register
TACH0               equ       $00000026           ;*** TACH0 - TIMA Channel 0 Register

;*** TACH0H - TIMA Channel 0 Register High
TACH0H              equ       $00000026           ;*** TACH0H - TIMA Channel 0 Register High

;*** TACH0L - TIMA Channel 0 Register Low
TACH0L              equ       $00000027           ;*** TACH0L - TIMA Channel 0 Register Low

;*** TASC1 - TIMA Channel 1 Status/Control Register
TASC1               equ       $00000028           ;*** TASC1 - TIMA Channel 1 Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
TASC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
TASC1_ELS1A         equ       2                   ; Edge/Level Select Bit A
TASC1_ELS1B         equ       3                   ; Edge/Level Select Bit B
TASC1_MS1A          equ       4                   ; Mode Select Bit A
TASC1_CH1IE         equ       6                   ; Channel 1 Interrupt Enable Bit
TASC1_CH1F          equ       7                   ; Channel 1 Flag Bit
; bit position masks
mTASC1_CH1MAX       equ       %00000001
mTASC1_TOV1         equ       %00000010
mTASC1_ELS1A        equ       %00000100
mTASC1_ELS1B        equ       %00001000
mTASC1_MS1A         equ       %00010000
mTASC1_CH1IE        equ       %01000000
mTASC1_CH1F         equ       %10000000

;*** TACH1 - TIMA Channel 1 Register
TACH1               equ       $00000029           ;*** TACH1 - TIMA Channel 1 Register

;*** TACH1H - TIMA Channel 1 Register High
TACH1H              equ       $00000029           ;*** TACH1H - TIMA Channel 1 Register High

;*** TACH1L - TIMA Channel 1 Register Low
TACH1L              equ       $0000002A           ;*** TACH1L - TIMA Channel 1 Register Low

;*** TBSC - TIMB Status/Control Register
TBSC                equ       $0000002B           ;*** TBSC - TIMB Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBSC_PS0            equ       0                   ; Prescaler Select Bit 0
TBSC_PS1            equ       1                   ; Prescaler Select Bit 1
TBSC_PS2            equ       2                   ; Prescaler Select Bit 2
TBSC_TRST           equ       4                   ; TIMB Reset Bit
TBSC_TSTOP          equ       5                   ; TIMB Stop Bit
TBSC_TOIE           equ       6                   ; TIMB Overflow Interrupt Enable Bit
TBSC_TOF            equ       7                   ; TIMB Overflow Flag Bit
; bit position masks
mTBSC_PS0           equ       %00000001
mTBSC_PS1           equ       %00000010
mTBSC_PS2           equ       %00000100
mTBSC_TRST          equ       %00010000
mTBSC_TSTOP         equ       %00100000
mTBSC_TOIE          equ       %01000000
mTBSC_TOF           equ       %10000000

;*** TBCNT - TIMB Counter Register
TBCNT               equ       $0000002C           ;*** TBCNT - TIMB Counter Register

;*** TBCNTH - TIMB Counter Register High
TBCNTH              equ       $0000002C           ;*** TBCNTH - TIMB Counter Register High

;*** TBCNTL - TIMB Counter Register Low
TBCNTL              equ       $0000002D           ;*** TBCNTL - TIMB Counter Register Low

;*** TBMOD - TIMB Counter Modulo Register
TBMOD               equ       $0000002E           ;*** TBMOD - TIMB Counter Modulo Register

;*** TBMODH - TIMB Counter Modulo Register High
TBMODH              equ       $0000002E           ;*** TBMODH - TIMB Counter Modulo Register High

;*** TBMODL - TIMB Counter Modulo Register
TBMODL              equ       $0000002F           ;*** TBMODL - TIMB Counter Modulo Register

;*** TBSC0 - TIMB Channel 0 Status/Control Register
TBSC0               equ       $00000030           ;*** TBSC0 - TIMB Channel 0 Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBSC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
TBSC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
TBSC0_ELS0A         equ       2                   ; Edge/Level Select Bit A
TBSC0_ELS0B         equ       3                   ; Edge/Level Select Bit B
TBSC0_MS0A          equ       4                   ; Mode Select Bit A
TBSC0_MS0B          equ       5                   ; Mode Select Bit B
TBSC0_CH0IE         equ       6                   ; Channel 0 Interrupt Enable Bit
TBSC0_CH0F          equ       7                   ; Channel 0 Flag Bit
; bit position masks
mTBSC0_CH0MAX       equ       %00000001
mTBSC0_TOV0         equ       %00000010
mTBSC0_ELS0A        equ       %00000100
mTBSC0_ELS0B        equ       %00001000
mTBSC0_MS0A         equ       %00010000
mTBSC0_MS0B         equ       %00100000
mTBSC0_CH0IE        equ       %01000000
mTBSC0_CH0F         equ       %10000000

;*** TBCH0 - TIMB Channel 0 Register
TBCH0               equ       $00000031           ;*** TBCH0 - TIMB Channel 0 Register

;*** TBCH0H - TIMB Channel 0 Register High
TBCH0H              equ       $00000031           ;*** TBCH0H - TIMB Channel 0 Register High

;*** TBCH0L - TIMB Channel 0 Register Low
TBCH0L              equ       $00000032           ;*** TBCH0L - TIMB Channel 0 Register Low

;*** TBSC1 - IMB Channel Status and Control Register
TBSC1               equ       $00000033           ;*** TBSC1 - IMB Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBSC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
TBSC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
TBSC1_ELS1A         equ       2                   ; Edge/Level Select Bit A
TBSC1_ELS1B         equ       3                   ; Edge/Level Select Bit B
TBSC1_MS1A          equ       4                   ; Mode Select Bit A
TBSC1_CH1IE         equ       6                   ; Channel 1 Interrupt Enable Bit
TBSC1_CH1F          equ       7                   ; Channel 1 Flag Bit
; bit position masks
mTBSC1_CH1MAX       equ       %00000001
mTBSC1_TOV1         equ       %00000010
mTBSC1_ELS1A        equ       %00000100
mTBSC1_ELS1B        equ       %00001000
mTBSC1_MS1A         equ       %00010000
mTBSC1_CH1IE        equ       %01000000
mTBSC1_CH1F         equ       %10000000

;*** TBCH1 - TIMB Channel 1 Register
TBCH1               equ       $00000034           ;*** TBCH1 - TIMB Channel 1 Register

;*** TBCH1H - TIMB Channel 1 Register High
TBCH1H              equ       $00000034           ;*** TBCH1H - TIMB Channel 1 Register High

;*** TBCH1L - TIMB Channel 1 Register Low
TBCH1L              equ       $00000035           ;*** TBCH1L - TIMB Channel 1 Register Low

;*** ICGCR - ICG Control Register
ICGCR               equ       $00000036           ;*** ICGCR - ICG Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGCR_ECGS          equ       0                   ; External Clock Generator Stable Bit
ICGCR_ECGON         equ       1                   ; External Clock Generator On Bit
ICGCR_ICGS          equ       2                   ; Internal Clock Generator Stable Bit
ICGCR_ICGON         equ       3                   ; Internal Clock Generator On Bit
ICGCR_CS            equ       4                   ; Clock Select Bit
ICGCR_CMON          equ       5                   ; Clock Monitor On Bit
ICGCR_CMF           equ       6                   ; Clock Monitor Interrupt Flag
ICGCR_CMIE          equ       7                   ; Clock Monitor Interrupt Enable Bit
; bit position masks
mICGCR_ECGS         equ       %00000001
mICGCR_ECGON        equ       %00000010
mICGCR_ICGS         equ       %00000100
mICGCR_ICGON        equ       %00001000
mICGCR_CS           equ       %00010000
mICGCR_CMON         equ       %00100000
mICGCR_CMF          equ       %01000000
mICGCR_CMIE         equ       %10000000

;*** ICGMR - ICG Multiplier Register
ICGMR               equ       $00000037           ;*** ICGMR - ICG Multiplier Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGMR_N0            equ       0                   ; ICG Multiplier Factor Bit 0
ICGMR_N1            equ       1                   ; ICG Multiplier Factor Bit 1
ICGMR_N2            equ       2                   ; ICG Multiplier Factor Bit 2
ICGMR_N3            equ       3                   ; ICG Multiplier Factor Bit 3
ICGMR_N4            equ       4                   ; ICG Multiplier Factor Bit 4
ICGMR_N5            equ       5                   ; ICG Multiplier Factor Bit 5
ICGMR_N6            equ       6                   ; ICG Multiplier Factor Bit 6
; bit position masks
mICGMR_N0           equ       %00000001
mICGMR_N1           equ       %00000010
mICGMR_N2           equ       %00000100
mICGMR_N3           equ       %00001000
mICGMR_N4           equ       %00010000
mICGMR_N5           equ       %00100000
mICGMR_N6           equ       %01000000

;*** ICGTR - ICG Trim Register
ICGTR               equ       $00000038           ;*** ICGTR - ICG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGTR_TRIM0         equ       0                   ; ICG Trim Factor Bit 0
ICGTR_TRIM1         equ       1                   ; ICG Trim Factor Bit 1
ICGTR_TRIM2         equ       2                   ; ICG Trim Factor Bit 2
ICGTR_TRIM3         equ       3                   ; ICG Trim Factor Bit 3
ICGTR_TRIM4         equ       4                   ; ICG Trim Factor Bit 4
ICGTR_TRIM5         equ       5                   ; ICG Trim Factor Bit 5
ICGTR_TRIM6         equ       6                   ; ICG Trim Factor Bit 6
ICGTR_TRIM7         equ       7                   ; ICG Trim Factor Bit 7
; bit position masks
mICGTR_TRIM0        equ       %00000001
mICGTR_TRIM1        equ       %00000010
mICGTR_TRIM2        equ       %00000100
mICGTR_TRIM3        equ       %00001000
mICGTR_TRIM4        equ       %00010000
mICGTR_TRIM5        equ       %00100000
mICGTR_TRIM6        equ       %01000000
mICGTR_TRIM7        equ       %10000000

;*** ICGDVR - ICG Divider Control Register
ICGDVR              equ       $00000039           ;*** ICGDVR - ICG Divider Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGDVR_DDIV0        equ       0                   ; ICG DCO Divider Control Bit 0
ICGDVR_DDIV1        equ       1                   ; ICG DCO Divider Control Bit 1
ICGDVR_DDIV2        equ       2                   ; ICG DCO Divider Control Bit 2
ICGDVR_DDIV3        equ       3                   ; ICG DCO Divider Control Bit 3
; bit position masks
mICGDVR_DDIV0       equ       %00000001
mICGDVR_DDIV1       equ       %00000010
mICGDVR_DDIV2       equ       %00000100
mICGDVR_DDIV3       equ       %00001000

;*** ICGDSR - ICG DCO State Control Register
ICGDSR              equ       $0000003A           ;*** ICGDSR - ICG DCO State Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGDSR_DSTG0        equ       0                   ; ICG DCO Stage Control Bit 0
ICGDSR_DSTG1        equ       1                   ; ICG DCO Stage Control Bit 1
ICGDSR_DSTG2        equ       2                   ; ICG DCO Stage Control Bit 2
ICGDSR_DSTG3        equ       3                   ; ICG DCO Stage Control Bit 3
ICGDSR_DSTG4        equ       4                   ; ICG DCO Stage Control Bit 4
ICGDSR_DSTG5        equ       5                   ; ICG DCO Stage Control Bit 5
ICGDSR_DSTG6        equ       6                   ; ICG DCO Stage Control Bit 6
ICGDSR_DSTG7        equ       7                   ; ICG DCO Stage Control Bit 7
; bit position masks
mICGDSR_DSTG0       equ       %00000001
mICGDSR_DSTG1       equ       %00000010
mICGDSR_DSTG2       equ       %00000100
mICGDSR_DSTG3       equ       %00001000
mICGDSR_DSTG4       equ       %00010000
mICGDSR_DSTG5       equ       %00100000
mICGDSR_DSTG6       equ       %01000000
mICGDSR_DSTG7       equ       %10000000

;*** ADSCR - ADC10 Status and Control Register
ADSCR               equ       $0000003C           ;*** ADSCR - ADC10 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSCR_ADCH0         equ       0                   ; ADC10 Channel Select Bit 0
ADSCR_ADCH1         equ       1                   ; ADC10 Channel Select Bit 1
ADSCR_ADCH2         equ       2                   ; ADC10 Channel Select Bit 2
ADSCR_ADCH3         equ       3                   ; ADC10 Channel Select Bit 3
ADSCR_ADCH4         equ       4                   ; ADC10 Channel Select Bit 4
ADSCR_ADCO          equ       5                   ; ADC10 Continuous Conversion Bit
ADSCR_AIEN          equ       6                   ; ADC10 Interrupt Enable Bit
ADSCR_COCO          equ       7                   ; Conversions Complete Bit
; bit position masks
mADSCR_ADCH0        equ       %00000001
mADSCR_ADCH1        equ       %00000010
mADSCR_ADCH2        equ       %00000100
mADSCR_ADCH3        equ       %00001000
mADSCR_ADCH4        equ       %00010000
mADSCR_ADCO         equ       %00100000
mADSCR_AIEN         equ       %01000000
mADSCR_COCO         equ       %10000000

;*** ADR - ADC10 Data Register Right Justified
ADR                 equ       $0000003D           ;*** ADR - ADC10 Data Register Right Justified

;*** ADRH - ADC10 Data Register High ~ Right Justified Mode
ADRH                equ       $0000003D           ;*** ADRH - ADC10 Data Register High ~ Right Justified Mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_AD8            equ       0                   ; ADC10 Data Bit 8
ADRH_AD9            equ       1                   ; ADC10 Data Bit 9
; bit position masks
mADRH_AD8           equ       %00000001
mADRH_AD9           equ       %00000010

;*** ADRL - ADC10 Data Register Low ~ Right Justified Mode
ADRL                equ       $0000003E           ;*** ADRL - ADC10 Data Register Low ~ Right Justified Mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRL_AD0            equ       0                   ; ADC10 Data Bit 0
ADRL_AD1            equ       1                   ; ADC10 Data Bit 1
ADRL_AD2            equ       2                   ; ADC10 Data Bit 2
ADRL_AD3            equ       3                   ; ADC10 Data Bit 3
ADRL_AD4            equ       4                   ; ADC10 Data Bit 4
ADRL_AD5            equ       5                   ; ADC10 Data Bit 5
ADRL_AD6            equ       6                   ; ADC10 Data Bit 6
ADRL_AD7            equ       7                   ; ADC10 Data Bit 7
; bit position masks
mADRL_AD0           equ       %00000001
mADRL_AD1           equ       %00000010
mADRL_AD2           equ       %00000100
mADRL_AD3           equ       %00001000
mADRL_AD4           equ       %00010000
mADRL_AD5           equ       %00100000
mADRL_AD6           equ       %01000000
mADRL_AD7           equ       %10000000

;*** ADCLK - ADC10 Clock Register
ADCLK               equ       $0000003F           ;*** ADCLK - ADC10 Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_ACLKEN        equ       0                   ; Asynchronous Clock Source Enable
ADCLK_ADLSMP        equ       1                   ; Long Sample Time Configuration
ADCLK_MODE0         equ       2                   ; Mode of Result Justification Bit 0
ADCLK_MODE1         equ       3                   ; Mode of Result Justification Bit 1
ADCLK_ADICLK        equ       4                   ; ADC10 Input Clock Select Bit
ADCLK_ADIV0         equ       5                   ; ADC10 Clock Prescaler Bit 0
ADCLK_ADIV1         equ       6                   ; ADC10 Clock Prescaler Bit 1
ADCLK_ADLPC         equ       7                   ; ADC10 Low-Power Configuration Bit
; bit position masks
mADCLK_ACLKEN       equ       %00000001
mADCLK_ADLSMP       equ       %00000010
mADCLK_MODE0        equ       %00000100
mADCLK_MODE1        equ       %00001000
mADCLK_ADICLK       equ       %00010000
mADCLK_ADIV0        equ       %00100000
mADCLK_ADIV1        equ       %01000000
mADCLK_ADLPC        equ       %10000000

;*** SBSR - SIM Break Status Register
SBSR                equ       $0000FE00           ;*** SBSR - SIM Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBSR_SBSW           equ       1                   ; SIM Break STOP/WAIT
; bit position masks
mSBSR_SBSW          equ       %00000010

;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset bit
SRSR_MENRST         equ       2                   ; Forced Monitor Mode Entry Reset Bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
mSRSR_MENRST        equ       %00000100
mSRSR_ILAD          equ       %00001000
mSRSR_ILOP          equ       %00010000
mSRSR_COP           equ       %00100000
mSRSR_PIN           equ       %01000000
mSRSR_POR           equ       %10000000

;*** SBFCR - SIM Break Flag Control Register
SBFCR               equ       $0000FE03           ;*** SBFCR - SIM Break Flag Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBFCR_BCFE          equ       7                   ; Break Clear Flag Enable Bit
; bit position masks
mSBFCR_BCFE         equ       %10000000

;*** INT1 - Interrupt Status Register 1
INT1                equ       $0000FE04           ;*** INT1 - Interrupt Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT1_IF1            equ       2                   ; Interrupt Flag 1
INT1_IF2            equ       3                   ; Interrupt Flag 2
INT1_IF3            equ       4                   ; Interrupt Flag 3
INT1_IF4            equ       5                   ; Interrupt Flag 4
INT1_IF5            equ       6                   ; Interrupt Flag 5
INT1_IF6            equ       7                   ; Interrupt Flag 6
; bit position masks
mINT1_IF1           equ       %00000100
mINT1_IF2           equ       %00001000
mINT1_IF3           equ       %00010000
mINT1_IF4           equ       %00100000
mINT1_IF5           equ       %01000000
mINT1_IF6           equ       %10000000

;*** INT2 - Interrupt Status Register 2
INT2                equ       $0000FE05           ;*** INT2 - Interrupt Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT2_IF7            equ       0                   ; Interrupt Flag 7
INT2_IF8            equ       1                   ; Interrupt Flag 8
INT2_IF9            equ       2                   ; Interrupt Flag 9
INT2_IF10           equ       3                   ; Interrupt Flag 10
INT2_IF11           equ       4                   ; Interrupt Flag 11
INT2_IF12           equ       5                   ; Interrupt Flag 12
INT2_IF13           equ       6                   ; Interrupt Flag 13
INT2_IF14           equ       7                   ; Interrupt Flag 14
; bit position masks
mINT2_IF7           equ       %00000001
mINT2_IF8           equ       %00000010
mINT2_IF9           equ       %00000100
mINT2_IF10          equ       %00001000
mINT2_IF11          equ       %00010000
mINT2_IF12          equ       %00100000
mINT2_IF13          equ       %01000000
mINT2_IF14          equ       %10000000

;*** INT3 - Interrupt Status Register 3
INT3                equ       $0000FE06           ;*** INT3 - Interrupt Status Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT3_IF15           equ       0                   ; Interrupt Flag 15
INT3_IF16           equ       1                   ; Interrupt Flag 16
; bit position masks
mINT3_IF15          equ       %00000001
mINT3_IF16          equ       %00000010

;*** FLCR - FLASH Control Register
FLCR                equ       $0000FE08           ;*** FLCR - FLASH Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_ERASE          equ       1                   ; Erase Control Bit
FLCR_MASS           equ       2                   ; Mass Erase Control Bit
FLCR_HVEN           equ       3                   ; High-Voltage Enable Bit
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_ERASE         equ       %00000010
mFLCR_MASS          equ       %00000100
mFLCR_HVEN          equ       %00001000

;*** BRK - Break Address Register
BRK                 equ       $0000FE09           ;*** BRK - Break Address Register

;*** BRKH - Break Address Register High
BRKH                equ       $0000FE09           ;*** BRKH - Break Address Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKH_BIT8           equ       0                   ; Break Address Bit 8
BRKH_BIT9           equ       1                   ; Break Address Bit 9
BRKH_BIT10          equ       2                   ; Break Address Bit 10
BRKH_BIT11          equ       3                   ; Break Address Bit 11
BRKH_BIT12          equ       4                   ; Break Address Bit 12
BRKH_BIT13          equ       5                   ; Break Address Bit 13
BRKH_BIT14          equ       6                   ; Break Address Bit 14
BRKH_BIT15          equ       7                   ; Break Address Bit 15
; bit position masks
mBRKH_BIT8          equ       %00000001
mBRKH_BIT9          equ       %00000010
mBRKH_BIT10         equ       %00000100
mBRKH_BIT11         equ       %00001000
mBRKH_BIT12         equ       %00010000
mBRKH_BIT13         equ       %00100000
mBRKH_BIT14         equ       %01000000
mBRKH_BIT15         equ       %10000000

;*** BRKL - Break Address Register
BRKL                equ       $0000FE0A           ;*** BRKL - Break Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKL_BIT0           equ       0                   ; Break Address Bit 0
BRKL_BIT1           equ       1                   ; Break Address Bit 1
BRKL_BIT2           equ       2                   ; Break Address Bit 2
BRKL_BIT3           equ       3                   ; Break Address Bit 3
BRKL_BIT4           equ       4                   ; Break Address Bit 4
BRKL_BIT5           equ       5                   ; Break Address Bit 5
BRKL_BIT6           equ       6                   ; Break Address Bit 6
BRKL_BIT7           equ       7                   ; Break Address Bit 7
; bit position masks
mBRKL_BIT0          equ       %00000001
mBRKL_BIT1          equ       %00000010
mBRKL_BIT2          equ       %00000100
mBRKL_BIT3          equ       %00001000
mBRKL_BIT4          equ       %00010000
mBRKL_BIT5          equ       %00100000
mBRKL_BIT6          equ       %01000000
mBRKL_BIT7          equ       %10000000

;*** BSCR - Break Status and Control Register
BSCR                equ       $0000FE0B           ;*** BSCR - Break Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BSCR_BRKA           equ       6                   ; Break Active Bit
BSCR_BRKE           equ       7                   ; Break Enable Bit
; bit position masks
mBSCR_BRKA          equ       %01000000
mBSCR_BRKE          equ       %10000000

;*** LVISR - LVI Status and Control Register
LVISR               equ       $0000FE0C           ;*** LVISR - LVI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LVIOUT       equ       %10000000

;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FF7E           ;*** FLBPR - FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR0          equ       0                   ; Flash Block Protect Bit 0
FLBPR_BPR1          equ       1                   ; Flash Block Protect Bit 1
FLBPR_BPR2          equ       2                   ; Flash Block Protect Bit 2
FLBPR_BPR3          equ       3                   ; Flash Block Protect Bit 3
FLBPR_BPR4          equ       4                   ; Flash Block Protect Bit 4
FLBPR_BPR5          equ       5                   ; Flash Block Protect Bit 5
FLBPR_BPR6          equ       6                   ; Flash Block Protect Bit 6
FLBPR_BPR7          equ       7                   ; Flash Block Protect Bit 7
; bit position masks
mFLBPR_BPR0         equ       %00000001
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000
mFLBPR_BPR4         equ       %00010000
mFLBPR_BPR5         equ       %00100000
mFLBPR_BPR6         equ       %01000000
mFLBPR_BPR7         equ       %10000000

;*** ICGT5V - 5V Internal Oscillator Trim Value
ICGT5V              equ       $0000FF80           ;*** ICGT5V - 5V Internal Oscillator Trim Value
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGT5V_BIT0         equ       0                   ; 5V Internal Oscillator Trim Value Bit 0
ICGT5V_BIT1         equ       1                   ; 5V Internal Oscillator Trim Value Bit 1
ICGT5V_BIT2         equ       2                   ; 5V Internal Oscillator Trim Value Bit 2
ICGT5V_BIT3         equ       3                   ; 5V Internal Oscillator Trim Value Bit 3
ICGT5V_BIT4         equ       4                   ; 5V Internal Oscillator Trim Value Bit 4
ICGT5V_BIT5         equ       5                   ; 5V Internal Oscillator Trim Value Bit 5
ICGT5V_BIT6         equ       6                   ; 5V Internal Oscillator Trim Value Bit 6
ICGT5V_BIT7         equ       7                   ; 5V Internal Oscillator Trim Value Bit 7
; bit position masks
mICGT5V_BIT0        equ       %00000001
mICGT5V_BIT1        equ       %00000010
mICGT5V_BIT2        equ       %00000100
mICGT5V_BIT3        equ       %00001000
mICGT5V_BIT4        equ       %00010000
mICGT5V_BIT5        equ       %00100000
mICGT5V_BIT6        equ       %01000000
mICGT5V_BIT7        equ       %10000000

;*** ICGT3V - 3V Internal Oscillator Trim Value
ICGT3V              equ       $0000FF81           ;*** ICGT3V - 3V Internal Oscillator Trim Value
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGT3V_BIT0         equ       0                   ; 3V Internal Oscillator Trim Value Bit 0
ICGT3V_BIT1         equ       1                   ; 3V Internal Oscillator Trim Value Bit 1
ICGT3V_BIT2         equ       2                   ; 3V Internal Oscillator Trim Value Bit 2
ICGT3V_BIT3         equ       3                   ; 3V Internal Oscillator Trim Value Bit 3
ICGT3V_BIT4         equ       4                   ; 3V Internal Oscillator Trim Value Bit 4
ICGT3V_BIT5         equ       5                   ; 3V Internal Oscillator Trim Value Bit 5
ICGT3V_BIT6         equ       6                   ; 3V Internal Oscillator Trim Value Bit 6
ICGT3V_BIT7         equ       7                   ; 3V Internal Oscillator Trim Value Bit 7
; bit position masks
mICGT3V_BIT0        equ       %00000001
mICGT3V_BIT1        equ       %00000010
mICGT3V_BIT2        equ       %00000100
mICGT3V_BIT3        equ       %00001000
mICGT3V_BIT4        equ       %00010000
mICGT3V_BIT5        equ       %00100000
mICGT3V_BIT6        equ       %01000000
mICGT3V_BIT7        equ       %10000000

;*** COPCTL - COP Control Register
COPCTL              equ       $0000FFFF           ;*** COPCTL - COP Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
COPCTL_BIT0         equ       0                   ; Bit 0
COPCTL_BIT1         equ       1                   ; Bit 1
COPCTL_BIT2         equ       2                   ; Bit 2
COPCTL_BIT3         equ       3                   ; Bit 3
COPCTL_BIT4         equ       4                   ; Bit 4
COPCTL_BIT5         equ       5                   ; Bit 5
COPCTL_BIT6         equ       6                   ; Bit 6
COPCTL_BIT7         equ       7                   ; Bit 7
; bit position masks
mCOPCTL_BIT0        equ       %00000001
mCOPCTL_BIT1        equ       %00000010
mCOPCTL_BIT2        equ       %00000100
mCOPCTL_BIT3        equ       %00001000
mCOPCTL_BIT4        equ       %00010000
mCOPCTL_BIT5        equ       %00100000
mCOPCTL_BIT6        equ       %01000000
mCOPCTL_BIT7        equ       %10000000

;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
       #ifndef  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
       #endif
; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------

; EOF
