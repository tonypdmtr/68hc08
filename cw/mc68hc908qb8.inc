;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908QB8_P_DW, version 2.87.100 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908qb8.inc
;     Processor : MC68HC908QB8CP
;     FileFormat: V2.28
;     DataSheet : MC68HC908QB8 Rev. 2 04/2007
;     Compiler  : CodeWarrior compiler
;     Date/Time : 27.5.2009, 10:00
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;      - 22.02.2006, V2.87.079:
;              - Added bit FLBPR_BPR0. REASON: Bug-fix (#3040 in Issue Manager)
;      - 06.12.2007, V2.87.095:
;              - Added bis TSC2_MS2B, INT2_IF8, INT3_IF16..22. REASON: Bug-fix (#4090 in the Issue Manager).
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
ROM                 equ       $0000DE00
ROM_END             equ       $0000FDFF
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000013F
XROM                equ       $0000FFB0
XROM_END            equ       $0000FFBD
ROM2Start           equ       $0000FFC2
ROM2End             equ       $0000FFCF
;
INT_ADC             equ       $0000FFDE
INT_KBI             equ       $0000FFE0
INT_SPITransmit     equ       $0000FFE2
INT_SPIReceive      equ       $0000FFE4
INT_SCITransmit     equ       $0000FFE6
INT_SCIReceive      equ       $0000FFE8
INT_SCIError        equ       $0000FFEA
Reserved7           equ       $0000FFEC
INT_TIMCH3          equ       $0000FFEE
INT_TIMCH2          equ       $0000FFF0
INT_TIMOvr          equ       $0000FFF2
INT_TIMCH1          equ       $0000FFF4
INT_TIMCH0          equ       $0000FFF6
Reserved13          equ       $0000FFF8
INT_IRQ             equ       $0000FFFA
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
PTA_AWUL            equ       6                   ; Auto Wake-up Latch Data Bit
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000
mPTA_PTA5           equ       %00100000
mPTA_AWUL           equ       %01000000


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


;*** DDRA - Data Direction Register A
DDRA                equ       $00000004           ;*** DDRA - Data Direction Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRA_DDRA0          equ       0                   ; Data Direction Register A Bit 0
DDRA_DDRA1          equ       1                   ; Data Direction Register A Bit 1
DDRA_DDRA3          equ       3                   ; Data Direction Register A Bit 3
DDRA_DDRA4          equ       4                   ; Data Direction Register A Bit 4
DDRA_DDRA5          equ       5                   ; Data Direction Register A Bit 5
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000
mDDRA_DDRA5         equ       %00100000


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


;*** PTAPUE - Input Pull-Up Enable Register PTAPUE
PTAPUE              equ       $0000000B           ;*** PTAPUE - Input Pull-Up Enable Register PTAPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUE_PTAPUE0      equ       0                   ; Pull-Up Enable bit 0, Port A
PTAPUE_PTAPUE1      equ       1                   ; Pull-Up Enable bit 1, Port A
PTAPUE_PTAPUE2      equ       2                   ; Pull-Up Enable bit 2, Port A
PTAPUE_PTAPUE3      equ       3                   ; Pull-Up Enable bit 3, Port A
PTAPUE_PTAPUE4      equ       4                   ; Pull-Up Enable bit 4, Port A
PTAPUE_PTAPUE5      equ       5                   ; Pull-Up Enable bit 5, Port A
PTAPUE_OSC2EN       equ       7                   ; Enable PTA4 on OSC2 Pin
; bit position masks
mPTAPUE_PTAPUE0     equ       %00000001
mPTAPUE_PTAPUE1     equ       %00000010
mPTAPUE_PTAPUE2     equ       %00000100
mPTAPUE_PTAPUE3     equ       %00001000
mPTAPUE_PTAPUE4     equ       %00010000
mPTAPUE_PTAPUE5     equ       %00100000
mPTAPUE_OSC2EN      equ       %10000000


;*** PTBPUE - Input Pull-Up Enable Register PTBPUE
PTBPUE              equ       $0000000C           ;*** PTBPUE - Input Pull-Up Enable Register PTBPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPUE_PTBPUE0      equ       0                   ; Pull-Up Enable bit 0, Port B
PTBPUE_PTBPUE1      equ       1                   ; Pull-Up Enable bit 1, Port B
PTBPUE_PTBPUE2      equ       2                   ; Pull-Up Enable bit 2, Port B
PTBPUE_PTBPUE3      equ       3                   ; Pull-Up Enable bit 3, Port B
PTBPUE_PTBPUE4      equ       4                   ; Pull-Up Enable bit 4, Port B
PTBPUE_PTBPUE5      equ       5                   ; Pull-Up Enable bit 5, Port B
PTBPUE_PTBPUE6      equ       6                   ; Pull-Up Enable bit 6, Port B
PTBPUE_PTBPUE7      equ       7                   ; Pull-Up Enable bit 7, Port B
; bit position masks
mPTBPUE_PTBPUE0     equ       %00000001
mPTBPUE_PTBPUE1     equ       %00000010
mPTBPUE_PTBPUE2     equ       %00000100
mPTBPUE_PTBPUE3     equ       %00001000
mPTBPUE_PTBPUE4     equ       %00010000
mPTBPUE_PTBPUE5     equ       %00100000
mPTBPUE_PTBPUE6     equ       %01000000
mPTBPUE_PTBPUE7     equ       %10000000


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
SCC1_ENSCI          equ       6                   ; Enable ESCI Bit
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


;*** SCS1 - ESCI Status Register 1
SCS1                equ       $00000013           ;*** SCS1 - ESCI Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS1_PE             equ       0                   ; Receiver Parity Error Bit
SCS1_FE             equ       1                   ; Receiver Framing Error Bit
SCS1_NF             equ       2                   ; Receiver Noise Flag Bit
SCS1_OR             equ       3                   ; Receiver Overrun Bit
SCS1_IDLE           equ       4                   ; Receiver Idle Bit
SCS1_SCRF           equ       5                   ; SCI Receiver Full Bit
SCS1_TC             equ       6                   ; Transmission Complete Bit
SCS1_SCTE           equ       7                   ; SCI Transmitter Empty Bit
; bit position masks
mSCS1_PE            equ       %00000001
mSCS1_FE            equ       %00000010
mSCS1_NF            equ       %00000100
mSCS1_OR            equ       %00001000
mSCS1_IDLE          equ       %00010000
mSCS1_SCRF          equ       %00100000
mSCS1_TC            equ       %01000000
mSCS1_SCTE          equ       %10000000


;*** SCS2 - ESCI Status Register 2
SCS2                equ       $00000014           ;*** SCS2 - ESCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS2_RPF            equ       0                   ; Reception in Progress Flag Bit
SCS2_BKF            equ       1                   ; Break Flag Bit
; bit position masks
mSCS2_RPF           equ       %00000001
mSCS2_BKF           equ       %00000010


;*** SCDR - ESCI Data Register
SCDR                equ       $00000015           ;*** SCDR - ESCI Data Register
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


;*** SCBR - ESCI Baud Rate Register
SCBR                equ       $00000016           ;*** SCBR - ESCI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCBR_SCR0           equ       0                   ; ESCI Baud Rate Select Bit 0
SCBR_SCR1           equ       1                   ; ESCI Baud Rate Select Bit 1
SCBR_SCR2           equ       2                   ; ESCI Baud Rate Select Bit 2
SCBR_SCP0           equ       4                   ; ESCI Baud Rate Prescaler Bit 0
SCBR_SCP1           equ       5                   ; ESCI Baud Rate Prescaler Bit 1
SCBR_LINR           equ       6                   ; LIN Break Symbol Receiver Bit
SCBR_LINT           equ       7                   ; LIN Breal Symbol Transmit Enable
; bit position masks
mSCBR_SCR0          equ       %00000001
mSCBR_SCR1          equ       %00000010
mSCBR_SCR2          equ       %00000100
mSCBR_SCP0          equ       %00010000
mSCBR_SCP1          equ       %00100000
mSCBR_LINR          equ       %01000000
mSCBR_LINT          equ       %10000000


;*** SCPSC - ESCI Prescaler Register
SCPSC               equ       $00000017           ;*** SCPSC - ESCI Prescaler Register
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


;*** KBIER - Keyboard Interrrupt Enable Register KBIER
KBIER               equ       $0000001B           ;*** KBIER - Keyboard Interrrupt Enable Register KBIER
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIER_KBIE0         equ       0                   ; Keyboard Interrupt Enable Bit 0
KBIER_KBIE1         equ       1                   ; Keyboard Interrupt Enable Bit 1
KBIER_KBIE2         equ       2                   ; Keyboard Interrupt Enable Bit 2
KBIER_KBIE3         equ       3                   ; Keyboard Interrupt Enable Bit 3
KBIER_KBIE4         equ       4                   ; Keyboard Interrupt Enable Bit 4
KBIER_KBIE5         equ       5                   ; Keyboard Interrupt Enable Bit 5
KBIER_AWUIE         equ       6                   ; Auto Wake-up Interrupt Enable Bit
; bit position masks
mKBIER_KBIE0        equ       %00000001
mKBIER_KBIE1        equ       %00000010
mKBIER_KBIE2        equ       %00000100
mKBIER_KBIE3        equ       %00001000
mKBIER_KBIE4        equ       %00010000
mKBIER_KBIE5        equ       %00100000
mKBIER_AWUIE        equ       %01000000


;*** KBIPR - Keyboard Interrupt Polarity Register
KBIPR               equ       $0000001C           ;*** KBIPR - Keyboard Interrupt Polarity Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPR_KBIP0         equ       0                   ; Keyboard Interrupt Polarity Bit 0
KBIPR_KBIP1         equ       1                   ; Keyboard Interrupt Polarity Bit 1
KBIPR_KBIP2         equ       2                   ; Keyboard Interrupt Polarity Bit 2
KBIPR_KBIP3         equ       3                   ; Keyboard Interrupt Polarity Bit 3
KBIPR_KBIP4         equ       4                   ; Keyboard Interrupt Polarity Bit 4
KBIPR_KBIP5         equ       5                   ; Keyboard Interrupt Polarity Bit 5
; bit position masks
mKBIPR_KBIP0        equ       %00000001
mKBIPR_KBIP1        equ       %00000010
mKBIPR_KBIP2        equ       %00000100
mKBIPR_KBIP3        equ       %00001000
mKBIPR_KBIP4        equ       %00010000
mKBIPR_KBIP5        equ       %00100000


;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001D           ;*** INTSCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSCR_MODE         equ       0                   ; IRQ Edge/Level Select Bit
INTSCR_IMASK        equ       1                   ; IRQ1 Interrupt Mask Bit
INTSCR_ACK          equ       2                   ; IRQ1 Interrupt Request Acknowledge Bit
INTSCR_IRQF         equ       3                   ; IRQ1 Flag Bit
; bit position masks
mINTSCR_MODE        equ       %00000001
mINTSCR_IMASK       equ       %00000010
mINTSCR_ACK         equ       %00000100
mINTSCR_IRQF        equ       %00001000


;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001E           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_RSTEN       equ       0                   ; RST Pin Function Selection
CONFIG2_OSCENINSTOP equ       1                   ; Oscillator Enable in Stop Mode Bit
CONFIG2_ESCIBDSRC   equ       2                   ; ESCI Baud Rate Clock Source Bit
CONFIG2_IRQEN       equ       6                   ; IRQ Pin Function Selection Bit
CONFIG2_IRQPUD      equ       7                   ; IRQ Pin Pullup Control Bit
; bit position masks
mCONFIG2_RSTEN      equ       %00000001
mCONFIG2_OSCENINSTOP equ       %00000010
mCONFIG2_ESCIBDSRC  equ       %00000100
mCONFIG2_IRQEN      equ       %01000000
mCONFIG2_IRQPUD     equ       %10000000


;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVITRIP     equ       3                   ; LVI Trip Point Selection Bit
CONFIG1_LVIPWRD     equ       4                   ; Low Voltage Inhibit Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; Low Voltage Inhibit Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP Reset Period Selection Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVITRIP    equ       %00001000
mCONFIG1_LVIPWRD    equ       %00010000
mCONFIG1_LVIRSTD    equ       %00100000
mCONFIG1_LVISTOP    equ       %01000000
mCONFIG1_COPRS      equ       %10000000


;*** TSC - TIM Status and Control Register TSC
TSC                 equ       $00000020           ;*** TSC - TIM Status and Control Register TSC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC_PS0             equ       0                   ; Prescaler Select Bit 0
TSC_PS1             equ       1                   ; Prescaler Select Bit 1
TSC_PS2             equ       2                   ; Prescaler Select Bit 2
TSC_TRST            equ       4                   ; TIM Reset Bit
TSC_TSTOP           equ       5                   ; TIM Stop Bit
TSC_TOIE            equ       6                   ; TIM Overflow Interrupt Enable Bit
TSC_TOF             equ       7                   ; TIM Overflow Flag Bit
; bit position masks
mTSC_PS0            equ       %00000001
mTSC_PS1            equ       %00000010
mTSC_PS2            equ       %00000100
mTSC_TRST           equ       %00010000
mTSC_TSTOP          equ       %00100000
mTSC_TOIE           equ       %01000000
mTSC_TOF            equ       %10000000


;*** TCNT - TIM Counter Register
TCNT                equ       $00000021           ;*** TCNT - TIM Counter Register


;*** TCNTH - TIM Counter Register High
TCNTH               equ       $00000021           ;*** TCNTH - TIM Counter Register High


;*** TCNTL - TIM Counter Register Low
TCNTL               equ       $00000022           ;*** TCNTL - TIM Counter Register Low


;*** TMOD - TIM Counter Modulo Register
TMOD                equ       $00000023           ;*** TMOD - TIM Counter Modulo Register


;*** TMODH - TIM Counter Modulo Register High
TMODH               equ       $00000023           ;*** TMODH - TIM Counter Modulo Register High


;*** TMODL - TIM Counter Modulo Register Low
TMODL               equ       $00000024           ;*** TMODL - TIM Counter Modulo Register Low


;*** TSC0 - TIM Channel 0 Status and Control Register
TSC0                equ       $00000025           ;*** TSC0 - TIM Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC0_CH0MAX         equ       0                   ; Channel 0 Maximum Duty Cycle Bit
TSC0_TOV0           equ       1                   ; Toggle-On-Overflow Bit
TSC0_ELS0A          equ       2                   ; Edge/Level Select Bit A
TSC0_ELS0B          equ       3                   ; Edge/Level Select Bit B
TSC0_MS0A           equ       4                   ; Mode Select Bit A
TSC0_MS0B           equ       5                   ; Mode Select Bit B
TSC0_CH0IE          equ       6                   ; Channel 0 Interrupt Enable Bit
TSC0_CH0F           equ       7                   ; Channel 0 Flag Bit
; bit position masks
mTSC0_CH0MAX        equ       %00000001
mTSC0_TOV0          equ       %00000010
mTSC0_ELS0A         equ       %00000100
mTSC0_ELS0B         equ       %00001000
mTSC0_MS0A          equ       %00010000
mTSC0_MS0B          equ       %00100000
mTSC0_CH0IE         equ       %01000000
mTSC0_CH0F          equ       %10000000


;*** TCH0 - TIM Channel 0 Register
TCH0                equ       $00000026           ;*** TCH0 - TIM Channel 0 Register


;*** TCH0H - TIM Channel 0 Register High
TCH0H               equ       $00000026           ;*** TCH0H - TIM Channel 0 Register High


;*** TCH0L - TIM Channel 0 Register Low
TCH0L               equ       $00000027           ;*** TCH0L - TIM Channel 0 Register Low


;*** TSC1 - TIM Channel 1 Status and Control Register
TSC1                equ       $00000028           ;*** TSC1 - TIM Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC1_CH1MAX         equ       0                   ; Channel 1 Maximum Duty Cycle Bit
TSC1_TOV1           equ       1                   ; Toggle-On-Overflow Bit
TSC1_ELS1A          equ       2                   ; Edge/Level Select Bit A
TSC1_ELS1B          equ       3                   ; Edge/Level Select Bit B
TSC1_MS1A           equ       4                   ; Mode Select Bit A
TSC1_CH1IE          equ       6                   ; Channel 1 Interrupt Enable Bit
TSC1_CH1F           equ       7                   ; Channel 1 Flag Bit
; bit position masks
mTSC1_CH1MAX        equ       %00000001
mTSC1_TOV1          equ       %00000010
mTSC1_ELS1A         equ       %00000100
mTSC1_ELS1B         equ       %00001000
mTSC1_MS1A          equ       %00010000
mTSC1_CH1IE         equ       %01000000
mTSC1_CH1F          equ       %10000000


;*** TCH1 - TIM Channel 1 Register
TCH1                equ       $00000029           ;*** TCH1 - TIM Channel 1 Register


;*** TCH1H - TIM Channel 1 Register High
TCH1H               equ       $00000029           ;*** TCH1H - TIM Channel 1 Register High


;*** TCH1L - TIM Channel 1 Register Low
TCH1L               equ       $0000002A           ;*** TCH1L - TIM Channel 1 Register Low


;*** TSC2 - TIM Channel 2 Status and Control Register
TSC2                equ       $00000030           ;*** TSC2 - TIM Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC2_CH2MAX         equ       0                   ; Channel 2 Maximum Duty Cycle Bit
TSC2_TOV2           equ       1                   ; Toggle-On-Overflow Bit
TSC2_ELS2A          equ       2                   ; Edge/Level Select Bit A
TSC2_ELS2B          equ       3                   ; Edge/Level Select Bit B
TSC2_MS2A           equ       4                   ; Mode Select Bit A
TSC2_MS2B           equ       5                   ; Mode Select Bit B
TSC2_CH2IE          equ       6                   ; Channel 2 Interrupt Enable Bit
TSC2_CH2F           equ       7                   ; Channel 2 Flag Bit
; bit position masks
mTSC2_CH2MAX        equ       %00000001
mTSC2_TOV2          equ       %00000010
mTSC2_ELS2A         equ       %00000100
mTSC2_ELS2B         equ       %00001000
mTSC2_MS2A          equ       %00010000
mTSC2_MS2B          equ       %00100000
mTSC2_CH2IE         equ       %01000000
mTSC2_CH2F          equ       %10000000


;*** TCH2 - TIM Channel 2 Register
TCH2                equ       $00000031           ;*** TCH2 - TIM Channel 2 Register


;*** TCH2H - TIM Channel 2 Register High
TCH2H               equ       $00000031           ;*** TCH2H - TIM Channel 2 Register High


;*** TCH2L - TIM Channel 2 Register Low
TCH2L               equ       $00000032           ;*** TCH2L - TIM Channel 2 Register Low


;*** TSC3 - TIM Channel 3 Status and Control Register
TSC3                equ       $00000033           ;*** TSC3 - TIM Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC3_CH3MAX         equ       0                   ; Channel 3 Maximum Duty Cycle Bit
TSC3_TOV3           equ       1                   ; Toggle-On-Overflow Bit
TSC3_ELS3A          equ       2                   ; Edge/Level Select Bit A
TSC3_ELS3B          equ       3                   ; Edge/Level Select Bit B
TSC3_MS3A           equ       4                   ; Mode Select Bit A
TSC3_CH3IE          equ       6                   ; Channel 3 Interrupt Enable Bit
TSC3_CH3F           equ       7                   ; Channel 3 Flag Bit
; bit position masks
mTSC3_CH3MAX        equ       %00000001
mTSC3_TOV3          equ       %00000010
mTSC3_ELS3A         equ       %00000100
mTSC3_ELS3B         equ       %00001000
mTSC3_MS3A          equ       %00010000
mTSC3_CH3IE         equ       %01000000
mTSC3_CH3F          equ       %10000000


;*** TCH3 - TIM Channel 3 Register
TCH3                equ       $00000034           ;*** TCH3 - TIM Channel 3 Register


;*** TCH3H - TIM Channel 3 Register High
TCH3H               equ       $00000034           ;*** TCH3H - TIM Channel 3 Register High


;*** TCH3L - TIM Channel 3 Register Low
TCH3L               equ       $00000035           ;*** TCH3L - TIM Channel 3 Register Low


;*** OSCSC - Oscillator Status and Control Register
OSCSC               equ       $00000036           ;*** OSCSC - Oscillator Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSCSC_ECGST         equ       0                   ; External Clock Status Bit
OSCSC_ECGON         equ       1                   ; External Clock Generator On Bit
OSCSC_ECFS0         equ       2                   ; External Clock Frequency Select Bit 0
OSCSC_ECFS1         equ       3                   ; External Clock Frequency Select Bit 1
OSCSC_ICFS0         equ       4                   ; Internal Clock Frequency Select Bit 0
OSCSC_ICFS1         equ       5                   ; Internal Clock Frequency Select Bit 1
OSCSC_OSCOPT0       equ       6                   ; OSC Option Bit 0
OSCSC_OSCOPT1       equ       7                   ; OSC Option Bit 1
; bit position masks
mOSCSC_ECGST        equ       %00000001
mOSCSC_ECGON        equ       %00000010
mOSCSC_ECFS0        equ       %00000100
mOSCSC_ECFS1        equ       %00001000
mOSCSC_ICFS0        equ       %00010000
mOSCSC_ICFS1        equ       %00100000
mOSCSC_OSCOPT0      equ       %01000000
mOSCSC_OSCOPT1      equ       %10000000


;*** OSCTRIM - Oscillator Trim Register
OSCTRIM             equ       $00000038           ;*** OSCTRIM - Oscillator Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSCTRIM_BIT0        equ       0                   ; ICG Trim Factor Bit 0
OSCTRIM_BIT1        equ       1                   ; ICG Trim Factor Bit 1
OSCTRIM_BIT2        equ       2                   ; ICG Trim Factor Bit 2
OSCTRIM_BIT3        equ       3                   ; ICG Trim Factor Bit 3
OSCTRIM_BIT4        equ       4                   ; ICG Trim Factor Bit 4
OSCTRIM_BIT5        equ       5                   ; ICG Trim Factor Bit 5
OSCTRIM_BIT6        equ       6                   ; ICG Trim Factor Bit 6
OSCTRIM_BIT7        equ       7                   ; ICG Trim Factor Bit 7
; bit position masks
mOSCTRIM_BIT0       equ       %00000001
mOSCTRIM_BIT1       equ       %00000010
mOSCTRIM_BIT2       equ       %00000100
mOSCTRIM_BIT3       equ       %00001000
mOSCTRIM_BIT4       equ       %00010000
mOSCTRIM_BIT5       equ       %00100000
mOSCTRIM_BIT6       equ       %01000000
mOSCTRIM_BIT7       equ       %10000000


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


;*** ADR - ADC10 Data Register - Right-justified
ADR                 equ       $0000003D           ;*** ADR - ADC10 Data Register - Right-justified


;*** ADRH - ADC10 Data Register High - Right-justified mode
ADRH                equ       $0000003D           ;*** ADRH - ADC10 Data Register High - Right-justified mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_AD8            equ       0                   ; ADC10 Data Bit 8
ADRH_AD9            equ       1                   ; ADC10 Data Bit 9
; bit position masks
mADRH_AD8           equ       %00000001
mADRH_AD9           equ       %00000010


;*** ADRL - ADC10 Data Register Low - Right-justified mode
ADRL                equ       $0000003E           ;*** ADRL - ADC10 Data Register Low - Right-justified mode
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


;*** ADCLK - ADC Input Clock Register
ADCLK               equ       $0000003F           ;*** ADCLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_ACLKEN        equ       0                   ; Asynchronous Clock Source Enable
ADCLK_ADLSMP        equ       1                   ; Long Sample Time Configuration
ADCLK_MODE0         equ       2                   ; 10- or 8-Bit or External-Triggered Mode Selection Bit 0
ADCLK_MODE1         equ       3                   ; 10- or 8-Bit or External-Triggered Mode Selection Bit 1
ADCLK_ADICLK        equ       4                   ; Input Clock Select Bit
ADCLK_ADIV0         equ       5                   ; ADC10 Clock Divider Bit 0
ADCLK_ADIV1         equ       6                   ; ADC10 Clock Divider Bit 1
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


;*** BSR - Break Status Register
BSR                 equ       $0000FE00           ;*** BSR - Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BSR_SBSW            equ       1                   ; SIM Break Stop/Wait
; bit position masks
mBSR_SBSW           equ       %00000010


;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset Bit
SRSR_MODRST         equ       2                   ; Monitor Mode Entry Module Reset bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit (opcode fetches only)
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
mSRSR_MODRST        equ       %00000100
mSRSR_ILAD          equ       %00001000
mSRSR_ILOP          equ       %00010000
mSRSR_COP           equ       %00100000
mSRSR_PIN           equ       %01000000
mSRSR_POR           equ       %10000000


;*** BRKAR - Break Auxiliary Register
BRKAR               equ       $0000FE02           ;*** BRKAR - Break Auxiliary Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKAR_BDCOP         equ       0                   ; Break Disable COP Bit
; bit position masks
mBRKAR_BDCOP        equ       %00000001


;*** BFCR - SIM Break Flag Control Register
BFCR                equ       $0000FE03           ;*** BFCR - SIM Break Flag Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BFCR_BCFE           equ       7                   ; Break Clear Flag Enable Bit
; bit position masks
mBFCR_BCFE          equ       %10000000


;*** INT1 - Interrupt Status Register 1
INT1                equ       $0000FE04           ;*** INT1 - Interrupt Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT1_IF1            equ       2                   ; Interrupt Flag 1
INT1_IF3            equ       4                   ; Interrupt Flag 3
INT1_IF4            equ       5                   ; Interrupt Flag 4
INT1_IF5            equ       6                   ; Interrupt Flag 5
INT1_IF6            equ       7                   ; Interrupt Flag 6
; bit position masks
mINT1_IF1           equ       %00000100
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
INT3_IF17           equ       2                   ; Interrupt Flag 17
INT3_IF18           equ       3                   ; Interrupt Flag 18
INT3_IF19           equ       4                   ; Interrupt Flag 19
INT3_IF20           equ       5                   ; Interrupt Flag 20
INT3_IF21           equ       6                   ; Interrupt Flag 21
INT3_IF22           equ       7                   ; Interrupt Flag 22
; bit position masks
mINT3_IF15          equ       %00000001
mINT3_IF16          equ       %00000010
mINT3_IF17          equ       %00000100
mINT3_IF18          equ       %00001000
mINT3_IF19          equ       %00010000
mINT3_IF20          equ       %00100000
mINT3_IF21          equ       %01000000
mINT3_IF22          equ       %10000000


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
BRKH_BIT8           equ       0                   ; Break Address Register Bit 8
BRKH_BIT9           equ       1                   ; Break Address Register Bit 9
BRKH_BIT10          equ       2                   ; Break Address Register Bit 10
BRKH_BIT11          equ       3                   ; Break Address Register Bit 11
BRKH_BIT12          equ       4                   ; Break Address Register Bit 12
BRKH_BIT13          equ       5                   ; Break Address Register Bit 13
BRKH_BIT14          equ       6                   ; Break Address Register Bit 14
BRKH_BIT15          equ       7                   ; Break Address Register Bit 15
; bit position masks
mBRKH_BIT8          equ       %00000001
mBRKH_BIT9          equ       %00000010
mBRKH_BIT10         equ       %00000100
mBRKH_BIT11         equ       %00001000
mBRKH_BIT12         equ       %00010000
mBRKH_BIT13         equ       %00100000
mBRKH_BIT14         equ       %01000000
mBRKH_BIT15         equ       %10000000


;*** BRKL - Break Address Register Low
BRKL                equ       $0000FE0A           ;*** BRKL - Break Address Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKL_BIT0           equ       0                   ; Break Address Register Bit 0
BRKL_BIT1           equ       1                   ; Break Address Register Bit 1
BRKL_BIT2           equ       2                   ; Break Address Register Bit 2
BRKL_BIT3           equ       3                   ; Break Address Register Bit 3
BRKL_BIT4           equ       4                   ; Break Address Register Bit 4
BRKL_BIT5           equ       5                   ; Break Address Register Bit 5
BRKL_BIT6           equ       6                   ; Break Address Register Bit 6
BRKL_BIT7           equ       7                   ; Break Address Register Bit 7
; bit position masks
mBRKL_BIT0          equ       %00000001
mBRKL_BIT1          equ       %00000010
mBRKL_BIT2          equ       %00000100
mBRKL_BIT3          equ       %00001000
mBRKL_BIT4          equ       %00010000
mBRKL_BIT5          equ       %00100000
mBRKL_BIT6          equ       %01000000
mBRKL_BIT7          equ       %10000000


;*** BRKSCR - Break Status and Control Register
BRKSCR              equ       $0000FE0B           ;*** BRKSCR - Break Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKSCR_BRKA         equ       6                   ; Break Active Bit
BRKSCR_BRKE         equ       7                   ; Break Enable Bit
; bit position masks
mBRKSCR_BRKA        equ       %01000000
mBRKSCR_BRKE        equ       %10000000


;*** LVISR - LVI Status Register
LVISR               equ       $0000FE0C           ;*** LVISR - LVI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LVIOUT       equ       %10000000


;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FFBE           ;*** FLBPR - FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR0          equ       0                   ; Block Protect Register Bit 0
FLBPR_BPR1          equ       1                   ; Block Protect Register Bit 1
FLBPR_BPR2          equ       2                   ; Block Protect Register Bit 2
FLBPR_BPR3          equ       3                   ; Block Protect Register Bit 3
FLBPR_BPR4          equ       4                   ; Block Protect Register Bit 4
FLBPR_BPR5          equ       5                   ; Block Protect Register Bit 5
FLBPR_BPR6          equ       6                   ; Block Protect Register Bit 6
FLBPR_BPR7          equ       7                   ; Block Protect Register Bit 7
; bit position masks
mFLBPR_BPR0         equ       %00000001
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000
mFLBPR_BPR4         equ       %00010000
mFLBPR_BPR5         equ       %00100000
mFLBPR_BPR6         equ       %01000000
mFLBPR_BPR7         equ       %10000000


;*** Optional - Internal Oscillator Trim
Optional            equ       $0000FFC0           ;*** Optional - Internal Oscillator Trim
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
Optional_TRIM0      equ       0                   ; ICG Trim Factor Bit 0
Optional_TRIM1      equ       1                   ; ICG Trim Factor Bit 1
Optional_TRIM2      equ       2                   ; ICG Trim Factor Bit 2
Optional_TRIM3      equ       3                   ; ICG Trim Factor Bit 3
Optional_TRIM4      equ       4                   ; ICG Trim Factor Bit 4
Optional_TRIM5      equ       5                   ; ICG Trim Factor Bit 5
Optional_TRIM6      equ       6                   ; ICG Trim Factor Bit 6
Optional_TRIM7      equ       7                   ; ICG Trim Factor Bit 7
; bit position masks
mOptional_TRIM0     equ       %00000001
mOptional_TRIM1     equ       %00000010
mOptional_TRIM2     equ       %00000100
mOptional_TRIM3     equ       %00001000
mOptional_TRIM4     equ       %00010000
mOptional_TRIM5     equ       %00100000
mOptional_TRIM6     equ       %01000000
mOptional_TRIM7     equ       %10000000


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
