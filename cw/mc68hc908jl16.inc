;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908JL16_32SP, version 2.87.086 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908jl16.inc
;     Processor : MC68HC908JL16CSPE
;     FileFormat: V2.28
;     DataSheet : MC68HC908JL16 Rev. 1.1 11/2005
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
ROM                 equ       $0000BC00
ROM_END             equ       $0000FBFF
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000025F
;
INT_ADC             equ       $0000FFDE
INT_KBI             equ       $0000FFE0
INT_SCITransmit     equ       $0000FFE2
INT_SCIReceive      equ       $0000FFE4
INT_SCIError        equ       $0000FFE6
INT_MMIIC           equ       $0000FFE8
Reserved6           equ       $0000FFEA
INT_TIM2Ovr         equ       $0000FFEC
INT_TIM2CH1         equ       $0000FFEE
INT_TIM2CH0         equ       $0000FFF0
INT_TIM1Ovr         equ       $0000FFF2
INT_TIM1CH1         equ       $0000FFF4
INT_TIM1CH0         equ       $0000FFF6
Reserved13          equ       $0000FFF8
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
PTA_PTA7            equ       7                   ; Port A Data Bit 7
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000
mPTA_PTA5           equ       %00100000
mPTA_PTA6           equ       %01000000
mPTA_PTA7           equ       %10000000


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


;*** PTD - Port D Data Register
PTD                 equ       $00000003           ;*** PTD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTD_PTD0            equ       0                   ; Port D Data Bit 0
PTD_PTD1            equ       1                   ; Port D Data Bit 1
PTD_PTD2            equ       2                   ; Port D Data Bit 2
PTD_PTD3            equ       3                   ; Port D Data Bit 3
PTD_PTD4            equ       4                   ; Port D Data Bit 4
PTD_PTD5            equ       5                   ; Port D Data Bit 5
PTD_PTD6            equ       6                   ; Port D Data Bit 6
PTD_PTD7            equ       7                   ; Port D Data Bit 7
; bit position masks
mPTD_PTD0           equ       %00000001
mPTD_PTD1           equ       %00000010
mPTD_PTD2           equ       %00000100
mPTD_PTD3           equ       %00001000
mPTD_PTD4           equ       %00010000
mPTD_PTD5           equ       %00100000
mPTD_PTD6           equ       %01000000
mPTD_PTD7           equ       %10000000


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
DDRA_DDRA7          equ       7                   ; Data Direction Register A Bit 7
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA2         equ       %00000100
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000
mDDRA_DDRA5         equ       %00100000
mDDRA_DDRA6         equ       %01000000
mDDRA_DDRA7         equ       %10000000


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


;*** DDRD - Data Direction Register D
DDRD                equ       $00000007           ;*** DDRD - Data Direction Register D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRD_DDRD0          equ       0                   ; Data Direction Register D Bit 0
DDRD_DDRD1          equ       1                   ; Data Direction Register D Bit 1
DDRD_DDRD2          equ       2                   ; Data Direction Register D Bit 2
DDRD_DDRD3          equ       3                   ; Data Direction Register D Bit 3
DDRD_DDRD4          equ       4                   ; Data Direction Register D Bit 4
DDRD_DDRD5          equ       5                   ; Data Direction Register D Bit 5
DDRD_DDRD6          equ       6                   ; Data Direction Register D Bit 6
DDRD_DDRD7          equ       7                   ; Data Direction Register D Bit 7
; bit position masks
mDDRD_DDRD0         equ       %00000001
mDDRD_DDRD1         equ       %00000010
mDDRD_DDRD2         equ       %00000100
mDDRD_DDRD3         equ       %00001000
mDDRD_DDRD4         equ       %00010000
mDDRD_DDRD5         equ       %00100000
mDDRD_DDRD6         equ       %01000000
mDDRD_DDRD7         equ       %10000000


;*** PTE - Port E Data Register
PTE                 equ       $00000008           ;*** PTE - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTE_PTE0            equ       0                   ; Port E Data Bit 0
PTE_PTE1            equ       1                   ; Port E Data Bit 1
; bit position masks
mPTE_PTE0           equ       %00000001
mPTE_PTE1           equ       %00000010


;*** PDCR - Port D Control Register
PDCR                equ       $0000000A           ;*** PDCR - Port D Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDCR_PTDPU6         equ       0                   ; Pull-Up Enable bit 6, port D
PDCR_PTDPU7         equ       1                   ; Pull-Up Enable bit 7, port D
PDCR_SLOWD6         equ       2                   ; Slow Edge Enable bit 6, port D
PDCR_SLOWD7         equ       3                   ; Slow Edge Enable bit 7, port D
; bit position masks
mPDCR_PTDPU6        equ       %00000001
mPDCR_PTDPU7        equ       %00000010
mPDCR_SLOWD6        equ       %00000100
mPDCR_SLOWD7        equ       %00001000


;*** DDRE - Data Direction Register E
DDRE                equ       $0000000C           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0          equ       0                   ; Data Direction Register E Bit 0
DDRE_DDRE1          equ       1                   ; Data Direction Register E Bit 1
; bit position masks
mDDRE_DDRE0         equ       %00000001
mDDRE_DDRE1         equ       %00000010


;*** PTAPUE - Input Pull-Up Enable Register
PTAPUE              equ       $0000000D           ;*** PTAPUE - Input Pull-Up Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUE_PTAPUE0      equ       0                   ; Pull-Up Enable bit 0, Port A
PTAPUE_PTAPUE1      equ       1                   ; Pull-Up Enable bit 1, Port A
PTAPUE_PTAPUE2      equ       2                   ; Pull-Up Enable bit 2, Port A
PTAPUE_PTAPUE3      equ       3                   ; Pull-Up Enable bit 3, Port A
PTAPUE_PTAPUE4      equ       4                   ; Pull-Up Enable bit 4, Port A
PTAPUE_PTAPUE5      equ       5                   ; Pull-Up Enable bit 5, Port A
PTAPUE_PTAPUE6      equ       6                   ; Pull-Up Enable bit 6, Port A
PTAPUE_PTA6EN       equ       7                   ; Enable PTA6 on OSC2, Port A
; bit position masks
mPTAPUE_PTAPUE0     equ       %00000001
mPTAPUE_PTAPUE1     equ       %00000010
mPTAPUE_PTAPUE2     equ       %00000100
mPTAPUE_PTAPUE3     equ       %00001000
mPTAPUE_PTAPUE4     equ       %00010000
mPTAPUE_PTAPUE5     equ       %00100000
mPTAPUE_PTAPUE6     equ       %01000000
mPTAPUE_PTA6EN      equ       %10000000


;*** PTA7PUE - Input Pull-Up Enable Register
PTA7PUE             equ       $0000000E           ;*** PTA7PUE - Input Pull-Up Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTA7PUE_PTAPUE7     equ       7                   ; Pull-Up Enable bit 7, Port A
; bit position masks
mPTA7PUE_PTAPUE7    equ       %10000000


;*** SCC1 - SCI Control Register 1
SCC1                equ       $00000013           ;*** SCC1 - SCI Control Register 1
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


;*** SCC2 - SCI Control Register 2
SCC2                equ       $00000014           ;*** SCC2 - SCI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC2_SBK            equ       0                   ; Send Break Bit
SCC2_RWU            equ       1                   ; Receiver Wakeup Bit
SCC2_RE             equ       2                   ; Receiver Enable Bit
SCC2_TE             equ       3                   ; Transmitter Enable Bit
SCC2_ILIE           equ       4                   ; Idle Line Interrupt Enable Bit
SCC2_SCRIE          equ       5                   ; SCI Receive Interrupt Enable Bit
SCC2_TCIE           equ       6                   ; Transmission Complete Interrupt Enable Bit
SCC2_SCTIE          equ       7                   ; SCI Transmit Interrupt Enable Bit
; bit position masks
mSCC2_SBK           equ       %00000001
mSCC2_RWU           equ       %00000010
mSCC2_RE            equ       %00000100
mSCC2_TE            equ       %00001000
mSCC2_ILIE          equ       %00010000
mSCC2_SCRIE         equ       %00100000
mSCC2_TCIE          equ       %01000000
mSCC2_SCTIE         equ       %10000000


;*** SCC3 - SCI Control Register 3
SCC3                equ       $00000015           ;*** SCC3 - SCI Control Register 3
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
SCS1                equ       $00000016           ;*** SCS1 - SCI Status Register 1
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


;*** SCS2 - SCI Status Register 2
SCS2                equ       $00000017           ;*** SCS2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS2_RPF            equ       0                   ; Reception in Progress Flag Bit
SCS2_BKF            equ       1                   ; Break Flag Bit
; bit position masks
mSCS2_RPF           equ       %00000001
mSCS2_BKF           equ       %00000010


;*** SCDR - SCI Data Register
SCDR                equ       $00000018           ;*** SCDR - SCI Data Register
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
SCBR                equ       $00000019           ;*** SCBR - SCI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCBR_SCR0           equ       0                   ; SCI Baud Rate Select Bit 0
SCBR_SCR1           equ       1                   ; SCI Baud Rate Select Bit 1
SCBR_SCR2           equ       2                   ; SCI Baud Rate Select Bit 2
SCBR_SCP0           equ       4                   ; SCI Baud Rate Prescaler Bit 0
SCBR_SCP1           equ       5                   ; SCI Baud Rate Prescaler Bit 1
; bit position masks
mSCBR_SCR0          equ       %00000001
mSCBR_SCR1          equ       %00000010
mSCBR_SCR2          equ       %00000100
mSCBR_SCP0          equ       %00010000
mSCBR_SCP1          equ       %00100000


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


;*** KBIER - Keyboard Interrrupt Enable Register
KBIER               equ       $0000001B           ;*** KBIER - Keyboard Interrrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIER_KBIE0         equ       0                   ; Keyboard Interrupt Enable Bit 0
KBIER_KBIE1         equ       1                   ; Keyboard Interrupt Enable Bit 1
KBIER_KBIE2         equ       2                   ; Keyboard Interrupt Enable Bit 2
KBIER_KBIE3         equ       3                   ; Keyboard Interrupt Enable Bit 3
KBIER_KBIE4         equ       4                   ; Keyboard Interrupt Enable Bit 4
KBIER_KBIE5         equ       5                   ; Keyboard Interrupt Enable Bit 5
KBIER_KBIE6         equ       6                   ; Keyboard Interrupt Enable Bit 6
KBIER_KBIE7         equ       7                   ; Keyboard Interrupt Enable Bit 7
; bit position masks
mKBIER_KBIE0        equ       %00000001
mKBIER_KBIE1        equ       %00000010
mKBIER_KBIE2        equ       %00000100
mKBIER_KBIE3        equ       %00001000
mKBIER_KBIE4        equ       %00010000
mKBIER_KBIE5        equ       %00100000
mKBIER_KBIE6        equ       %01000000
mKBIER_KBIE7        equ       %10000000


;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001D           ;*** INTSCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSCR_MODE         equ       0                   ; IRQ Edge/Level Select Bit
INTSCR_IMASK        equ       1                   ; IRQ Interrupt Mask Bit
INTSCR_ACK          equ       2                   ; IRQ Interrupt Request Acknowledge Bit
INTSCR_IRQF         equ       3                   ; IRQ Flag
; bit position masks
mINTSCR_MODE        equ       %00000001
mINTSCR_IMASK       equ       %00000010
mINTSCR_ACK         equ       %00000100
mINTSCR_IRQF        equ       %00001000


;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001E           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_STOP_ICLKDIS equ       0                   ; Internal oscillator STOP mode disable bit
CONFIG2_IICSEL      equ       1                   ; MMIIC Pin Selection Bit
CONFIG2_LVIT0       equ       3                   ; Low Voltage Inhibit Trip Voltage Selection Bit 0
CONFIG2_LVIT1       equ       4                   ; Low Voltage Inhibit Trip Voltage Selection Bit 1
CONFIG2_IRQPUD      equ       7                   ; IRQ1 Pin Pull-Up Control Bit
; bit position masks
mCONFIG2_STOP_ICLKDIS equ       %00000001
mCONFIG2_IICSEL     equ       %00000010
mCONFIG2_LVIT0      equ       %00001000
mCONFIG2_LVIT1      equ       %00010000
mCONFIG2_IRQPUD     equ       %10000000


;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVID        equ       4                   ; Low Voltage Inhibit Disable Bit
CONFIG1_COPRS       equ       7                   ; COP Reset Period Selection Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVID       equ       %00010000
mCONFIG1_COPRS      equ       %10000000


;*** T1SC - TIM1 Status and Control Register TSC
T1SC                equ       $00000020           ;*** T1SC - TIM1 Status and Control Register TSC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T1SC_PS0            equ       0                   ; Prescaler Select Bit 0
T1SC_PS1            equ       1                   ; Prescaler Select Bit 1
T1SC_PS2            equ       2                   ; Prescaler Select Bit 2
T1SC_TRST           equ       4                   ; TIM1 Reset Bit
T1SC_TSTOP          equ       5                   ; TIM1 Stop Bit
T1SC_TOIE           equ       6                   ; TIM1 Overflow Interrupt Enable Bit
T1SC_TOF            equ       7                   ; TIM1 Overflow Flag Bit
; bit position masks
mT1SC_PS0           equ       %00000001
mT1SC_PS1           equ       %00000010
mT1SC_PS2           equ       %00000100
mT1SC_TRST          equ       %00010000
mT1SC_TSTOP         equ       %00100000
mT1SC_TOIE          equ       %01000000
mT1SC_TOF           equ       %10000000


;*** T1CNT - TIM1 Counter Register
T1CNT               equ       $00000021           ;*** T1CNT - TIM1 Counter Register


;*** T1CNTH - TIM1 Counter Register High
T1CNTH              equ       $00000021           ;*** T1CNTH - TIM1 Counter Register High


;*** T1CNTL - TIM1 Counter Register Low
T1CNTL              equ       $00000022           ;*** T1CNTL - TIM1 Counter Register Low


;*** T1MOD - TIM1 Counter Modulo Register
T1MOD               equ       $00000023           ;*** T1MOD - TIM1 Counter Modulo Register


;*** T1MODH - TIM1 Counter Modulo Register High
T1MODH              equ       $00000023           ;*** T1MODH - TIM1 Counter Modulo Register High


;*** T1MODL - TIM1 Counter Modulo Register Low
T1MODL              equ       $00000024           ;*** T1MODL - TIM1 Counter Modulo Register Low


;*** T1SC0 - TIM1 Channel 0 Status and Control Register
T1SC0               equ       $00000025           ;*** T1SC0 - TIM1 Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T1SC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
T1SC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
T1SC0_ELS0A         equ       2                   ; Edge/Level Select Bit A
T1SC0_ELS0B         equ       3                   ; Edge/Level Select Bit B
T1SC0_MS0A          equ       4                   ; Mode Select Bit A
T1SC0_MS0B          equ       5                   ; Mode Select Bit B
T1SC0_CH0IE         equ       6                   ; Channel 0 Interrupt Enable Bit
T1SC0_CH0F          equ       7                   ; Channel 0 Flag Bit
; bit position masks
mT1SC0_CH0MAX       equ       %00000001
mT1SC0_TOV0         equ       %00000010
mT1SC0_ELS0A        equ       %00000100
mT1SC0_ELS0B        equ       %00001000
mT1SC0_MS0A         equ       %00010000
mT1SC0_MS0B         equ       %00100000
mT1SC0_CH0IE        equ       %01000000
mT1SC0_CH0F         equ       %10000000


;*** T1CH0 - TIM1 Channel 0 Register
T1CH0               equ       $00000026           ;*** T1CH0 - TIM1 Channel 0 Register


;*** T1CH0H - TIM1 Channel 0 Register High
T1CH0H              equ       $00000026           ;*** T1CH0H - TIM1 Channel 0 Register High


;*** T1CH0L - TIM1 Channel 0 Register Low
T1CH0L              equ       $00000027           ;*** T1CH0L - TIM1 Channel 0 Register Low


;*** T1SC1 - TIM1 Channel 1 Status and Control Register
T1SC1               equ       $00000028           ;*** T1SC1 - TIM1 Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T1SC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
T1SC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
T1SC1_ELS1A         equ       2                   ; Edge/Level Select Bit A
T1SC1_ELS1B         equ       3                   ; Edge/Level Select Bit B
T1SC1_MS1A          equ       4                   ; Mode Select Bit A
T1SC1_CH1IE         equ       6                   ; Channel 1 Interrupt Enable Bit
T1SC1_CH1F          equ       7                   ; Channel 1 Flag Bit
; bit position masks
mT1SC1_CH1MAX       equ       %00000001
mT1SC1_TOV1         equ       %00000010
mT1SC1_ELS1A        equ       %00000100
mT1SC1_ELS1B        equ       %00001000
mT1SC1_MS1A         equ       %00010000
mT1SC1_CH1IE        equ       %01000000
mT1SC1_CH1F         equ       %10000000


;*** T1CH1 - TIM1 Channel 1 Register
T1CH1               equ       $00000029           ;*** T1CH1 - TIM1 Channel 1 Register


;*** T1CH1H - TIM1 Channel 1 Register High
T1CH1H              equ       $00000029           ;*** T1CH1H - TIM1 Channel 1 Register High


;*** T1CH1L - TIM1 Channel 1 Register Low
T1CH1L              equ       $0000002A           ;*** T1CH1L - TIM1 Channel 1 Register Low


;*** T2SC - TIM2 Status and Control Register
T2SC                equ       $00000030           ;*** T2SC - TIM2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC_PS0            equ       0                   ; Prescaler Select Bit 0
T2SC_PS1            equ       1                   ; Prescaler Select Bit 1
T2SC_PS2            equ       2                   ; Prescaler Select Bit 2
T2SC_TRST           equ       4                   ; TIM2 Reset Bit
T2SC_TSTOP          equ       5                   ; TIM2 Stop Bit
T2SC_TOIE           equ       6                   ; TIM2 Overflow Interrupt Enable Bit
T2SC_TOF            equ       7                   ; TIM2 Overflow Flag Bit
; bit position masks
mT2SC_PS0           equ       %00000001
mT2SC_PS1           equ       %00000010
mT2SC_PS2           equ       %00000100
mT2SC_TRST          equ       %00010000
mT2SC_TSTOP         equ       %00100000
mT2SC_TOIE          equ       %01000000
mT2SC_TOF           equ       %10000000


;*** T2CNT - TIM2 Counter Register
T2CNT               equ       $00000031           ;*** T2CNT - TIM2 Counter Register


;*** T2CNTH - TIM2 Counter Register High
T2CNTH              equ       $00000031           ;*** T2CNTH - TIM2 Counter Register High


;*** T2CNTL - TIM2 Counter Register Low
T2CNTL              equ       $00000032           ;*** T2CNTL - TIM2 Counter Register Low


;*** T2MOD - TIM2 Counter Modulo Register
T2MOD               equ       $00000033           ;*** T2MOD - TIM2 Counter Modulo Register


;*** T2MODH - TIM2 Counter Modulo Register High
T2MODH              equ       $00000033           ;*** T2MODH - TIM2 Counter Modulo Register High


;*** T2MODL - TIM2 Counter Modulo Register Low
T2MODL              equ       $00000034           ;*** T2MODL - TIM2 Counter Modulo Register Low


;*** T2SC0 - TIM2 Channel 0 Status and Control Register
T2SC0               equ       $00000035           ;*** T2SC0 - TIM2 Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
T2SC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
T2SC0_ELS0A         equ       2                   ; Edge/Level Select Bit A
T2SC0_ELS0B         equ       3                   ; Edge/Level Select Bit B
T2SC0_MS0A          equ       4                   ; Mode Select Bit A
T2SC0_MS0B          equ       5                   ; Mode Select Bit B
T2SC0_CH0IE         equ       6                   ; Channel 0 Interrupt Enable Bit
T2SC0_CH0F          equ       7                   ; Channel 0 Flag Bit
; bit position masks
mT2SC0_CH0MAX       equ       %00000001
mT2SC0_TOV0         equ       %00000010
mT2SC0_ELS0A        equ       %00000100
mT2SC0_ELS0B        equ       %00001000
mT2SC0_MS0A         equ       %00010000
mT2SC0_MS0B         equ       %00100000
mT2SC0_CH0IE        equ       %01000000
mT2SC0_CH0F         equ       %10000000


;*** T2CH0 - TIM2 Channel 0 Register
T2CH0               equ       $00000036           ;*** T2CH0 - TIM2 Channel 0 Register


;*** T2CH0H - TIM2 Channel 0 Register High
T2CH0H              equ       $00000036           ;*** T2CH0H - TIM2 Channel 0 Register High


;*** T2CH0L - TIM2 Channel 0 Register Low
T2CH0L              equ       $00000037           ;*** T2CH0L - TIM2 Channel 0 Register Low


;*** T2SC1 - TIM2 Channel 1 Status and Control Register
T2SC1               equ       $00000038           ;*** T2SC1 - TIM2 Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
T2SC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
T2SC1_ELS1A         equ       2                   ; Edge/Level Select Bit A
T2SC1_ELS1B         equ       3                   ; Edge/Level Select Bit B
T2SC1_MS1A          equ       4                   ; Mode Select Bit A
T2SC1_CH1IE         equ       6                   ; Channel 1 Interrupt Enable Bit
T2SC1_CH1F          equ       7                   ; Channel 1 Flag Bit
; bit position masks
mT2SC1_CH1MAX       equ       %00000001
mT2SC1_TOV1         equ       %00000010
mT2SC1_ELS1A        equ       %00000100
mT2SC1_ELS1B        equ       %00001000
mT2SC1_MS1A         equ       %00010000
mT2SC1_CH1IE        equ       %01000000
mT2SC1_CH1F         equ       %10000000


;*** T2CH1 - TIM2 Channel 1 Register
T2CH1               equ       $00000039           ;*** T2CH1 - TIM2 Channel 1 Register


;*** T2CH1H - TIM2 Channel 1 Register High
T2CH1H              equ       $00000039           ;*** T2CH1H - TIM2 Channel 1 Register High


;*** T2CH1L - TIM2 Channel 1 Register Low
T2CH1L              equ       $0000003A           ;*** T2CH1L - TIM2 Channel 1 Register Low


;*** ADCSC - ADC10 Status and Control Register
ADCSC               equ       $0000003C           ;*** ADCSC - ADC10 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC_ADCH0         equ       0                   ; ADC10 Channel Select Bit 0
ADCSC_ADCH1         equ       1                   ; ADC10 Channel Select Bit 1
ADCSC_ADCH2         equ       2                   ; ADC10 Channel Select Bit 2
ADCSC_ADCH3         equ       3                   ; ADC10 Channel Select Bit 3
ADCSC_ADCH4         equ       4                   ; ADC10 Channel Select Bit 4
ADCSC_ADCO          equ       5                   ; ADC10 Continuous Conversion Bit
ADCSC_AIEN          equ       6                   ; ADC10 Interrupt Enable Bit
ADCSC_COCO          equ       7                   ; Conversions Complete Bit
; bit position masks
mADCSC_ADCH0        equ       %00000001
mADCSC_ADCH1        equ       %00000010
mADCSC_ADCH2        equ       %00000100
mADCSC_ADCH3        equ       %00001000
mADCSC_ADCH4        equ       %00010000
mADCSC_ADCO         equ       %00100000
mADCSC_AIEN         equ       %01000000
mADCSC_COCO         equ       %10000000


;*** ADR - ADC10 Data Register
ADR                 equ       $0000003D           ;*** ADR - ADC10 Data Register


;*** ADRH - ADC10 Data Register High
ADRH                equ       $0000003D           ;*** ADRH - ADC10 Data Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_AD8            equ       0                   ; ADC10 Data Bit 8
ADRH_AD9            equ       1                   ; ADC10 Data Bit 9
; bit position masks
mADRH_AD8           equ       %00000001
mADRH_AD9           equ       %00000010


;*** ADRL - ADC10 Data Register Low
ADRL                equ       $0000003E           ;*** ADRL - ADC10 Data Register Low
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


;*** ADCLK - ADC10 Input Clock Register
ADCLK               equ       $0000003F           ;*** ADCLK - ADC10 Input Clock Register
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


;*** MIMCR - Multi-Master IIC Master Control Register
MIMCR               equ       $00000040           ;*** MIMCR - Multi-Master IIC Master Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MIMCR_MMBR0         equ       0                   ; Baud Rate Select Bit 0
MIMCR_MMBR1         equ       1                   ; Baud Rate Select Bit 1
MIMCR_MMBR2         equ       2                   ; Baud Rate Select Bit 2
MIMCR_MMRW          equ       3                   ; Master Read/Write
MIMCR_MMAST         equ       4                   ; Master Control Bit
MIMCR_MMBB          equ       5                   ; Bus Busy Flag
MIMCR_MMNAKIF       equ       6                   ; No Acknowledge Interrupt Flag
MIMCR_MMALIF        equ       7                   ; Multi-Master Arbitration Lost Interrupt Flag
; bit position masks
mMIMCR_MMBR0        equ       %00000001
mMIMCR_MMBR1        equ       %00000010
mMIMCR_MMBR2        equ       %00000100
mMIMCR_MMRW         equ       %00001000
mMIMCR_MMAST        equ       %00010000
mMIMCR_MMBB         equ       %00100000
mMIMCR_MMNAKIF      equ       %01000000
mMIMCR_MMALIF       equ       %10000000


;*** MMADR - Multi-Master IIC Address Register
MMADR               equ       $00000041           ;*** MMADR - Multi-Master IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMADR_MMEXTAD       equ       0                   ; Multi-Master Expanded Address
MMADR_MMAD1         equ       1                   ; Multi-Master Address Bit 1
MMADR_MMAD2         equ       2                   ; Multi-Master Address Bit 2
MMADR_MMAD3         equ       3                   ; Multi-Master Address Bit 3
MMADR_MMAD4         equ       4                   ; Multi-Master Address Bit 4
MMADR_MMAD5         equ       5                   ; Multi-Master Address Bit 5
MMADR_MMAD6         equ       6                   ; Multi-Master Address Bit 6
MMADR_MMAD7         equ       7                   ; Multi-Master Address Bit 7
; bit position masks
mMMADR_MMEXTAD      equ       %00000001
mMMADR_MMAD1        equ       %00000010
mMMADR_MMAD2        equ       %00000100
mMMADR_MMAD3        equ       %00001000
mMMADR_MMAD4        equ       %00010000
mMMADR_MMAD5        equ       %00100000
mMMADR_MMAD6        equ       %01000000
mMMADR_MMAD7        equ       %10000000


;*** MMCR - Multi-Master IIC Control Register
MMCR                equ       $00000042           ;*** MMCR - Multi-Master IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMCR_REPSEN         equ       2                   ; Repeated Start Enable
MMCR_MMTXAK         equ       3                   ; Transmit Acknowledge Enable
MMCR_MMIEN          equ       6                   ; Multi-Master IIC Interrupt Enable
MMCR_MMEN           equ       7                   ; Multi-Master IIC Enable
; bit position masks
mMMCR_REPSEN        equ       %00000100
mMMCR_MMTXAK        equ       %00001000
mMMCR_MMIEN         equ       %01000000
mMMCR_MMEN          equ       %10000000


;*** MMSR - Multi-Master IIC Status Register
MMSR                equ       $00000043           ;*** MMSR - Multi-Master IIC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMSR_MMRXBF         equ       0                   ; Multi-Master Receive Buffer Full
MMSR_MMTXBE         equ       1                   ; Multi-Master Transmit Buffer Empty
MMSR_MMRXAK         equ       3                   ; Multi-Master Receive Acknowledge
MMSR_MMSRW          equ       4                   ; Multi-Master Slave Read/Write
MMSR_MMATCH         equ       5                   ; Multi-Master Address Match
MMSR_MMTXIF         equ       6                   ; Multi-Master Transmit Interrupt Flag
MMSR_MMRXIF         equ       7                   ; Multi-Master IIC Receive Interrupt Flag
; bit position masks
mMMSR_MMRXBF        equ       %00000001
mMMSR_MMTXBE        equ       %00000010
mMMSR_MMRXAK        equ       %00001000
mMMSR_MMSRW         equ       %00010000
mMMSR_MMATCH        equ       %00100000
mMMSR_MMTXIF        equ       %01000000
mMMSR_MMRXIF        equ       %10000000


;*** MMDTR - Multi-Master IIC Data Transmit Register
MMDTR               equ       $00000044           ;*** MMDTR - Multi-Master IIC Data Transmit Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMDTR_MMTD0         equ       0                   ; Data Bit 0
MMDTR_MMTD1         equ       1                   ; Data Bit 1
MMDTR_MMTD2         equ       2                   ; Data Bit 2
MMDTR_MMTD3         equ       3                   ; Data Bit 3
MMDTR_MMTD4         equ       4                   ; Data Bit 4
MMDTR_MMTD5         equ       5                   ; Data Bit 5
MMDTR_MMTD6         equ       6                   ; Data Bit 6
MMDTR_MMTD7         equ       7                   ; Data Bit 7
; bit position masks
mMMDTR_MMTD0        equ       %00000001
mMMDTR_MMTD1        equ       %00000010
mMMDTR_MMTD2        equ       %00000100
mMMDTR_MMTD3        equ       %00001000
mMMDTR_MMTD4        equ       %00010000
mMMDTR_MMTD5        equ       %00100000
mMMDTR_MMTD6        equ       %01000000
mMMDTR_MMTD7        equ       %10000000


;*** MMDRR - Multi-Master IIC Data Receive Register
MMDRR               equ       $00000045           ;*** MMDRR - Multi-Master IIC Data Receive Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMDRR_MMRD0         equ       0                   ; Data Bit 0
MMDRR_MMRD1         equ       1                   ; Data Bit 1
MMDRR_MMRD2         equ       2                   ; Data Bit 2
MMDRR_MMRD3         equ       3                   ; Data Bit 3
MMDRR_MMRD4         equ       4                   ; Data Bit 4
MMDRR_MMRD5         equ       5                   ; Data Bit 5
MMDRR_MMRD6         equ       6                   ; Data Bit 6
MMDRR_MMRD7         equ       7                   ; Data Bit 7
; bit position masks
mMMDRR_MMRD0        equ       %00000001
mMMDRR_MMRD1        equ       %00000010
mMMDRR_MMRD2        equ       %00000100
mMMDRR_MMRD3        equ       %00001000
mMMDRR_MMRD4        equ       %00010000
mMMDRR_MMRD5        equ       %00100000
mMMDRR_MMRD6        equ       %01000000
mMMDRR_MMRD7        equ       %10000000


;*** BSR - Break Status Register
BSR                 equ       $0000FE00           ;*** BSR - Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BSR_SBSW            equ       1                   ; SIM Break Stop/Wait
; bit position masks
mBSR_SBSW           equ       %00000010


;*** RSR - Reset Status Register
RSR                 equ       $0000FE01           ;*** RSR - Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RSR_LVI             equ       1                   ; Low-Voltage Inhibit Reset Bit
RSR_MODRST          equ       2                   ; Monitor Mode Entry Module Reset Bit
RSR_ILAD            equ       3                   ; Illegal Address Reset Bit
RSR_ILOP            equ       4                   ; Illegal Opcode Reset Bit
RSR_COP             equ       5                   ; Computer Operating Properly Reset Bit
RSR_PIN             equ       6                   ; External Reset Bit
RSR_POR             equ       7                   ; Power-On Reset Bit
; bit position masks
mRSR_LVI            equ       %00000010
mRSR_MODRST         equ       %00000100
mRSR_ILAD           equ       %00001000
mRSR_ILOP           equ       %00010000
mRSR_COP            equ       %00100000
mRSR_PIN            equ       %01000000
mRSR_POR            equ       %10000000


;*** BFCR - Break Flag Control Register
BFCR                equ       $0000FE03           ;*** BFCR - Break Flag Control Register
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
INT2_IF10           equ       3                   ; Interrupt Flag 10
INT2_IF11           equ       4                   ; Interrupt Flag 11
INT2_IF12           equ       5                   ; Interrupt Flag 12
INT2_IF13           equ       6                   ; Interrupt Flag 13
INT2_IF14           equ       7                   ; Interrupt Flag 14
; bit position masks
mINT2_IF7           equ       %00000001
mINT2_IF8           equ       %00000010
mINT2_IF10          equ       %00001000
mINT2_IF11          equ       %00010000
mINT2_IF12          equ       %00100000
mINT2_IF13          equ       %01000000
mINT2_IF14          equ       %10000000


;*** INT3 - Interrupt Status Register 3
INT3                equ       $0000FE06           ;*** INT3 - Interrupt Status Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT3_IF15           equ       0                   ; Interrupt Flag 15
; bit position masks
mINT3_IF15          equ       %00000001


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
BRK                 equ       $0000FE0C           ;*** BRK - Break Address Register


;*** BRKH - Break Address Register High
BRKH                equ       $0000FE0C           ;*** BRKH - Break Address Register High
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
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Register Low
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
BRKSCR              equ       $0000FE0E           ;*** BRKSCR - Break Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKSCR_BRKA         equ       6                   ; Break Active Bit
BRKSCR_BRKE         equ       7                   ; Break Enable Bit
; bit position masks
mBRKSCR_BRKA        equ       %01000000
mBRKSCR_BRKE        equ       %10000000


;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FFCF           ;*** FLBPR - FLASH Block Protect Register
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


;*** MOR - Mask Option Register
MOR                 equ       $0000FFD0           ;*** MOR - Mask Option Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MOR_OSCSEL          equ       7                   ; Oscillator Select Bit
; bit position masks
mMOR_OSCSEL         equ       %10000000


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
