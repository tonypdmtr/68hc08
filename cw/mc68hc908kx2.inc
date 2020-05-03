;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908KX2, version 2.89.059 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908kx2.inc
;     Processor : MC68HC908KX2CP
;     FileFormat: V2.28
;     DataSheet : MC68HC908KX8 Rev. 2.1 07/2005
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
ROM                 equ       $0000F600
ROM_END             equ       $0000FDFF
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       RAM
XRAM_END            equ       RAM_END
;
INT_TBM             equ       $0000FFDC
INT_ADC             equ       $0000FFDE
INT_KBI             equ       $0000FFE0
INT_SCITransmit     equ       $0000FFE2
INT_SCIReceive      equ       $0000FFE4
INT_SCIError        equ       $0000FFE6
Int7                equ       $0000FFE8
Int8                equ       $0000FFEA
Int9                equ       $0000FFEC
Int10               equ       $0000FFEE
Int11               equ       $0000FFF0
INT_TIMOvr          equ       $0000FFF2
INT_TIMCH1          equ       $0000FFF4
INT_TIMCH0          equ       $0000FFF6
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
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000


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
DDRA_DDRA2          equ       2                   ; Data Direction Register A Bit 2
DDRA_DDRA3          equ       3                   ; Data Direction Register A Bit 3
DDRA_DDRA4          equ       4                   ; Data Direction Register A Bit 4
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA2         equ       %00000100
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000


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
PTAPUE              equ       $0000000D           ;*** PTAPUE - Input Pull-Up Enable Register PTAPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUE_PTAPUE0      equ       0                   ; Pull-Up Enable bit 0, Port A
PTAPUE_PTAPUE1      equ       1                   ; Pull-Up Enable bit 1, Port A
PTAPUE_PTAPUE2      equ       2                   ; Pull-Up Enable bit 2, Port A
PTAPUE_PTAPUE3      equ       3                   ; Pull-Up Enable bit 3, Port A
PTAPUE_PTAPUE4      equ       4                   ; Pull-Up Enable bit 4, Port A
; bit position masks
mPTAPUE_PTAPUE0     equ       %00000001
mPTAPUE_PTAPUE1     equ       %00000010
mPTAPUE_PTAPUE2     equ       %00000100
mPTAPUE_PTAPUE3     equ       %00001000
mPTAPUE_PTAPUE4     equ       %00010000


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


;*** KBIER - Keyboard Interrrupt Enable Register KBIER
KBIER               equ       $0000001B           ;*** KBIER - Keyboard Interrrupt Enable Register KBIER
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
TBCR_TBIE           equ       2                   ; Timebase Interrupt Enable Bit
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


;*** ISCR - IRQ Status and Control Register
ISCR                equ       $0000001D           ;*** ISCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ISCR_MODE1          equ       0                   ; IRQ Edge/Level Select Bit
ISCR_IMASK1         equ       1                   ; IRQ1 Interrupt Mask Bit
ISCR_ACK1           equ       2                   ; IRQ1 Interrupt Request Acknowledge Bit
ISCR_IRQF1          equ       3                   ; IRQ1 Flag Bit
; bit position masks
mISCR_MODE1         equ       %00000001
mISCR_IMASK1        equ       %00000010
mISCR_ACK1          equ       %00000100
mISCR_IRQF1         equ       %00001000


;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001E           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_SCIBDSRC    equ       0                   ; SCI Baud Rate Clock Source Bit
CONFIG2_OSCENINSTOP equ       1                   ; Oscilator Enable In Stop Mode Bit
CONFIG2_EXTCLKEN    equ       3                   ; External Clock Enable Bit
CONFIG2_EXTSLOW     equ       4                   ; Slow External Crystal Enable Bit
CONFIG2_EXTXTALEN   equ       5                   ; External Crystal Enable Bit
; bit position masks
mCONFIG2_SCIBDSRC   equ       %00000001
mCONFIG2_OSCENINSTOP equ       %00000010
mCONFIG2_EXTCLKEN   equ       %00001000
mCONFIG2_EXTSLOW    equ       %00010000
mCONFIG2_EXTXTALEN  equ       %00100000


;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVI5OR3     equ       3                   ; LVI 5-V or 3-V Operating Mode Bit
CONFIG1_LVIPWRD     equ       4                   ; Low Voltage Inhibit Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; Low Voltage Inhibit Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP Reset Period Selection Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVI5OR3    equ       %00001000
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


;*** ICGCR - ICG Control Register
ICGCR               equ       $00000036           ;*** ICGCR - ICG Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGCR_ECGS          equ       0                   ; Extrernal Clock Generator Stable Bit
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


;*** ADSCR - ADC Status and Control Register
ADSCR               equ       $0000003C           ;*** ADSCR - ADC Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSCR_ADCH0         equ       0                   ; ADC Channel Select Bit 0
ADSCR_ADCH1         equ       1                   ; ADC Channel Select Bit 1
ADSCR_ADCH2         equ       2                   ; ADC Channel Select Bit 2
ADSCR_ADCH3         equ       3                   ; ADC Channel Select Bit 3
ADSCR_ADCH4         equ       4                   ; ADC Channel Select Bit 4
ADSCR_ADCO          equ       5                   ; ADC Continuous Conversion Bit
ADSCR_AIEN          equ       6                   ; ADC Interrupt Enable Bit
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


;*** ADR - ADC Data Register
ADR                 equ       $0000003D           ;*** ADR - ADC Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADR_AD0             equ       0                   ; ADC Data Bit 0
ADR_AD1             equ       1                   ; ADC Data Bit 1
ADR_AD2             equ       2                   ; ADC Data Bit 2
ADR_AD3             equ       3                   ; ADC Data Bit 3
ADR_AD4             equ       4                   ; ADC Data Bit 4
ADR_AD5             equ       5                   ; ADC Data Bit 5
ADR_AD6             equ       6                   ; ADC Data Bit 6
ADR_AD7             equ       7                   ; ADC Data Bit 7
; bit position masks
mADR_AD0            equ       %00000001
mADR_AD1            equ       %00000010
mADR_AD2            equ       %00000100
mADR_AD3            equ       %00001000
mADR_AD4            equ       %00010000
mADR_AD5            equ       %00100000
mADR_AD6            equ       %01000000
mADR_AD7            equ       %10000000


;*** ADCLK - ADC Input Clock Register
ADCLK               equ       $0000003E           ;*** ADCLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_ADICLK        equ       4                   ; ADC Input Clock Select Bit
ADCLK_ADIV0         equ       5                   ; ADC Clock Prescaler Bit 0
ADCLK_ADIV1         equ       6                   ; ADC Clock Prescaler Bit 1
ADCLK_ADIV2         equ       7                   ; ADC Clock Prescaler Bit 2
; bit position masks
mADCLK_ADICLK       equ       %00010000
mADCLK_ADIV0        equ       %00100000
mADCLK_ADIV1        equ       %01000000
mADCLK_ADIV2        equ       %10000000


;*** SBSR - SIM Break Status Register
SBSR                equ       $0000FE00           ;*** SBSR - SIM Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBSR_BW             equ       1                   ; Break Wait Bit
; bit position masks
mSBSR_BW            equ       %00000010


;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset Bit
SRSR_MENRST         equ       2                   ; Forced Monitor Mode Entry Reset Bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
mSRSR_MENRST        equ       %00000100
mSRSR_ILAD          equ       %00001000
mSRSR_ILOP          equ       %00010000
mSRSR_COP           equ       %00100000
mSRSR_POR           equ       %10000000


;*** BRKAR - Break Auxiliary Register
BRKAR               equ       $0000FE02           ;*** BRKAR - Break Auxiliary Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKAR_BDCOP         equ       0                   ; Break Disable COP Bit
; bit position masks
mBRKAR_BDCOP        equ       %00000001


;*** SBFCR - SIM Break Flag Control Register
SBFCR               equ       $0000FE03           ;*** SBFCR - SIM Break Flag Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBFCR_BCFE          equ       7                   ; Break Clear Flag Enable Bit
; bit position masks
mSBFCR_BCFE         equ       %10000000


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
FLBPR               equ       $0000FF7E           ;*** FLBPR - FLASH Block Protect Register
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
