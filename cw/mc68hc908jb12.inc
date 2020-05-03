;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908JB12_28, version 2.87.142 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908jb12.inc
;     Processor : MC68HC908JB12DW
;     FileFormat: V2.28
;     DataSheet : MC68HC908JB16/D Rev. 1.1, August 1, 2005, HC908JB16AD/D Rev. 1, 8/2002
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
ROM                 equ       $0000CA00
ROM_END             equ       $0000F9FF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $000001FF
;
INT_KBI             equ       $0000FFE0
INT_SCITransmit     equ       $0000FFE2
INT_SCIReceive      equ       $0000FFE4
INT_SCIError        equ       $0000FFE6
INT_TIM2Ovr         equ       $0000FFE8
INT_TIM2CH01        equ       $0000FFEA
INT_TIM2CH1         equ       $0000FFEC
INT_TIM2CH0         equ       $0000FFEE
INT_TIM1Ovr         equ       $0000FFF0
INT_TIM1CH01        equ       $0000FFF2
INT_TIM1CH1         equ       $0000FFF4
INT_TIM1CH0         equ       $0000FFF6
INT_IRQ             equ       $0000FFF8
INT_USB             equ       $0000FFFA
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


;*** PTC - Port C Data Register
PTC                 equ       $00000002           ;*** PTC - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTC_PTC0            equ       0                   ; Port C Data Bit 0
PTC_PTC1            equ       1                   ; Port C Data Bit 1
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010


;*** PTD - Port D Data Register
PTD                 equ       $00000003           ;*** PTD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTD_PTD0            equ       0                   ; Port D Data Bit 0
PTD_PTD1            equ       1                   ; Port D Data Bit 1
PTD_PTD2            equ       2                   ; Port D Data Bit 2
PTD_PTD3            equ       3                   ; Port D Data Bit 3
PTD_PTD4            equ       4                   ; Port D Data Bit 4
PTD_PTD5            equ       5                   ; Port D Data Bit 5
; bit position masks
mPTD_PTD0           equ       %00000001
mPTD_PTD1           equ       %00000010
mPTD_PTD2           equ       %00000100
mPTD_PTD3           equ       %00001000
mPTD_PTD4           equ       %00010000
mPTD_PTD5           equ       %00100000


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


;*** DDRC - Data Direction Register C
DDRC                equ       $00000006           ;*** DDRC - Data Direction Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRC_DDRC0          equ       0                   ; Data Direction Register C Bit 0
DDRC_DDRC1          equ       1                   ; Data Direction Register C Bit 1
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010


;*** DDRD - Data Direction Register D
DDRD                equ       $00000007           ;*** DDRD - Data Direction Register D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRD_DDRD0          equ       0                   ; Data Direction Register D Bit 0
DDRD_DDRD1          equ       1                   ; Data Direction Register D Bit 1
DDRD_DDRD2          equ       2                   ; Data Direction Register D Bit 2
DDRD_DDRD3          equ       3                   ; Data Direction Register D Bit 3
DDRD_DDRD4          equ       4                   ; Data Direction Register D Bit 4
DDRD_DDRD5          equ       5                   ; Data Direction Register D Bit 5
; bit position masks
mDDRD_DDRD0         equ       %00000001
mDDRD_DDRD1         equ       %00000010
mDDRD_DDRD2         equ       %00000100
mDDRD_DDRD3         equ       %00001000
mDDRD_DDRD4         equ       %00010000
mDDRD_DDRD5         equ       %00100000


;*** PTE - Port E Data Register
PTE                 equ       $00000008           ;*** PTE - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTE_PTE0            equ       0                   ; Port E Data Bit 0
PTE_PTE1            equ       1                   ; Port E Data Bit 1
PTE_PTE2            equ       2                   ; Port E Data Bit 2
PTE_PTE3            equ       3                   ; Port E Data Bit 3
PTE_PTE4            equ       4                   ; Port E Data Bit 4
; bit position masks
mPTE_PTE0           equ       %00000001
mPTE_PTE1           equ       %00000010
mPTE_PTE2           equ       %00000100
mPTE_PTE3           equ       %00001000
mPTE_PTE4           equ       %00010000


;*** DDRE - Data Direction Register E
DDRE                equ       $00000009           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0          equ       0                   ; Data Direction Register E Bit 0
DDRE_DDRE1          equ       1                   ; Data Direction Register E Bit 1
DDRE_DDRE2          equ       2                   ; Data Direction Register E Bit 2
DDRE_DDRE3          equ       3                   ; Data Direction Register E Bit 3
DDRE_DDRE4          equ       4                   ; Data Direction Register E Bit 4
; bit position masks
mDDRE_DDRE0         equ       %00000001
mDDRE_DDRE1         equ       %00000010
mDDRE_DDRE2         equ       %00000100
mDDRE_DDRE3         equ       %00001000
mDDRE_DDRE4         equ       %00010000


;*** T1SC - TIM Status and Control Register TSC
T1SC                equ       $0000000A           ;*** T1SC - TIM Status and Control Register TSC
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


;*** T1CNT - TIM Counter Register
T1CNT               equ       $0000000C           ;*** T1CNT - TIM Counter Register


;*** T1CNTH - TIM Counter Register High
T1CNTH              equ       $0000000C           ;*** T1CNTH - TIM Counter Register High


;*** T1CNTL - TIM Counter Register Low
T1CNTL              equ       $0000000D           ;*** T1CNTL - TIM Counter Register Low


;*** T1MOD - TIM Counter Modulo Register
T1MOD               equ       $0000000E           ;*** T1MOD - TIM Counter Modulo Register


;*** T1MODH - TIM Counter Modulo Register High
T1MODH              equ       $0000000E           ;*** T1MODH - TIM Counter Modulo Register High


;*** T1MODL - TIM Counter Modulo Register Low
T1MODL              equ       $0000000F           ;*** T1MODL - TIM Counter Modulo Register Low


;*** T1SC0 - TIM Channel 0 Status and Control Register
T1SC0               equ       $00000010           ;*** T1SC0 - TIM Channel 0 Status and Control Register
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


;*** T1CH0 - TIM Channel 0 Register
T1CH0               equ       $00000011           ;*** T1CH0 - TIM Channel 0 Register


;*** T1CH0H - TIM Channel 0 Register High
T1CH0H              equ       $00000011           ;*** T1CH0H - TIM Channel 0 Register High


;*** T1CH0L - TIM Channel 0 Register Low
T1CH0L              equ       $00000012           ;*** T1CH0L - TIM Channel 0 Register Low


;*** T1SC1 - TIM Channel 1 Status and Control Register
T1SC1               equ       $00000013           ;*** T1SC1 - TIM Channel 1 Status and Control Register
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


;*** T1CH1 - TIM Channel 1 Register
T1CH1               equ       $00000014           ;*** T1CH1 - TIM Channel 1 Register


;*** T1CH1H - TIM Channel 1 Register High
T1CH1H              equ       $00000014           ;*** T1CH1H - TIM Channel 1 Register High


;*** T1CH1L - TIM Channel 1 Register Low
T1CH1L              equ       $00000015           ;*** T1CH1L - TIM Channel 1 Register Low


;*** KBSCR - Keyboard Status and Control Register
KBSCR               equ       $00000016           ;*** KBSCR - Keyboard Status and Control Register
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
KBIER               equ       $00000017           ;*** KBIER - Keyboard Interrrupt Enable Register KBIER
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


;*** UIR2 - USB Interrupt Register 2
UIR2                equ       $00000018           ;*** UIR2 - USB Interrupt Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UIR2_RXD0FR         equ       0                   ; Endpoint 0 Receive Flag Reset
UIR2_TXD0FR         equ       1                   ; Endpoint 0 Transmit Flag Reset
UIR2_RESUMFR        equ       2                   ; Resume Flag Reset
UIR2_TXD1FR         equ       3                   ; Endpoint 1 Transmit Flag Reset
UIR2_RXD2FR         equ       4                   ; Endpoint 2 Receive Flag Reset
UIR2_TXD2FR         equ       5                   ; Endpoint 2 Transmit Flag Reset
UIR2_RSTFR          equ       6                   ; Clear Reset Indicator Bit
UIR2_EOPFR          equ       7                   ; End-of-Packet Flag Reset
; bit position masks
mUIR2_RXD0FR        equ       %00000001
mUIR2_TXD0FR        equ       %00000010
mUIR2_RESUMFR       equ       %00000100
mUIR2_TXD1FR        equ       %00001000
mUIR2_RXD2FR        equ       %00010000
mUIR2_TXD2FR        equ       %00100000
mUIR2_RSTFR         equ       %01000000
mUIR2_EOPFR         equ       %10000000


;*** UCR2 - USB Control Register 2
UCR2                equ       $00000019           ;*** UCR2 - USB Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR2_TP2SIZ0        equ       0                   ; Endpoint 2 Transmit Data Packet Size Bit 0
UCR2_TP2SIZ1        equ       1                   ; Endpoint 2 Transmit Data Packet Size Bit 1
UCR2_TP2SIZ2        equ       2                   ; Endpoint 2 Transmit Data Packet Size Bit 2
UCR2_TP2SIZ3        equ       3                   ; Endpoint 2 Transmit Data Packet Size Bit 3
UCR2_RX2E           equ       4                   ; Endpoint 2 Receive Enable
UCR2_TX2E           equ       5                   ; Endpoint 2 Transmit Enable
UCR2_STALL2         equ       6                   ; Endpoint 2 Force Stall Bit
UCR2_T2SEQ          equ       7                   ; Endpoint 2 Transmit Sequence Bit
; bit position masks
mUCR2_TP2SIZ0       equ       %00000001
mUCR2_TP2SIZ1       equ       %00000010
mUCR2_TP2SIZ2       equ       %00000100
mUCR2_TP2SIZ3       equ       %00001000
mUCR2_RX2E          equ       %00010000
mUCR2_TX2E          equ       %00100000
mUCR2_STALL2        equ       %01000000
mUCR2_T2SEQ         equ       %10000000


;*** UCR3 - USB Control Register 3
UCR3                equ       $0000001A           ;*** UCR3 - USB Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR3_ENABLE1        equ       0                   ; Endpoint 1 Enable
UCR3_ENABLE2        equ       1                   ; Endpoint 2 Enable
UCR3_PULLEN         equ       2                   ; Pull-up Enable
UCR3_ISTALL0        equ       4                   ; Endpoint 0 Force STALL Bit for IN token
UCR3_OSTALL0        equ       5                   ; Endpoint 0 Force STALL Bit for OUT token
UCR3_TX1STR         equ       6                   ; Clear Endpoint 0 Transmit First Flag
UCR3_TX1ST          equ       7                   ; Endpoint 0 Transmit First Flag
; bit position masks
mUCR3_ENABLE1       equ       %00000001
mUCR3_ENABLE2       equ       %00000010
mUCR3_PULLEN        equ       %00000100
mUCR3_ISTALL0       equ       %00010000
mUCR3_OSTALL0       equ       %00100000
mUCR3_TX1STR        equ       %01000000
mUCR3_TX1ST         equ       %10000000


;*** UCR4 - USB Control Register 4
UCR4                equ       $0000001B           ;*** UCR4 - USB Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR4_FDM            equ       0                   ; Force D-
UCR4_FDP            equ       1                   ; Force D+
UCR4_FUSBO          equ       2                   ; Force USB Output
; bit position masks
mUCR4_FDM           equ       %00000001
mUCR4_FDP           equ       %00000010
mUCR4_FUSBO         equ       %00000100


;*** IOCR - IRQ Option Register
IOCR                equ       $0000001C           ;*** IOCR - IRQ Option Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IOCR_IRQPD          equ       0                   ; IRQ Pullup Disable
IOCR_PTE4IE         equ       1                   ; PTE4 Interrupt Enable
IOCR_PTE4IF         equ       2                   ; PTE4 Interrupt Flag
; bit position masks
mIOCR_IRQPD         equ       %00000001
mIOCR_PTE4IE        equ       %00000010
mIOCR_PTE4IF        equ       %00000100


;*** POCR - Port Option Control Register
POCR                equ       $0000001D           ;*** POCR - Port Option Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
POCR_PAP            equ       0                   ; Port A Pullup Enable
POCR_PCP            equ       2                   ; Port C Pullup Enable
POCR_PTE3P          equ       3                   ; Pin PTE3 Pullup Enable
POCR_PTE4P          equ       4                   ; Pin PTE4 Pullup Enable
POCR_PTDILDD        equ       5                   ; Infrared LED Drive Control
POCR_PTDLDD         equ       6                   ; LED Direct Drive Control
POCR_PTE20P         equ       7                   ; Pins PTE[2:0] Pullup Enable
; bit position masks
mPOCR_PAP           equ       %00000001
mPOCR_PCP           equ       %00000100
mPOCR_PTE3P         equ       %00001000
mPOCR_PTE4P         equ       %00010000
mPOCR_PTDILDD       equ       %00100000
mPOCR_PTDLDD        equ       %01000000
mPOCR_PTE20P        equ       %10000000


;*** ISCR - IRQ Status and Control Register
ISCR                equ       $0000001E           ;*** ISCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ISCR_MODE           equ       0                   ; IRQ Edge/Level Select Bit
ISCR_IMASK          equ       1                   ; IRQ Interrupt Mask Bit
ISCR_ACK            equ       2                   ; IRQ Interrupt Request Acknowledge Bit
ISCR_IRQF           equ       3                   ; IRQ Flag Bit
; bit position masks
mISCR_MODE          equ       %00000001
mISCR_IMASK         equ       %00000010
mISCR_ACK           equ       %00000100
mISCR_IRQF          equ       %00001000


;*** CONFIG - Configuration Register
CONFIG              equ       $0000001F           ;*** CONFIG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG_COPD         equ       0                   ; COP Disable Bit
CONFIG_STOP         equ       1                   ; STOP Instruction Enable Bit
CONFIG_COPRS        equ       2                   ; COP Reset Period Selection Bit
CONFIG_SSREC        equ       3                   ; Short Stop Recovery Bit
CONFIG_LVID         equ       4                   ; Low Voltage Inhibit Disable Bit
CONFIG_URSTD        equ       5                   ; USB Reset Disable Bit
CONFIG_LVI5OR3      equ       6                   ; LVI Trip Point Voltage Select Bit for Vdd
CONFIG_LVIDR        equ       7                   ; LVI Disable Bit for Vreg
; bit position masks
mCONFIG_COPD        equ       %00000001
mCONFIG_STOP        equ       %00000010
mCONFIG_COPRS       equ       %00000100
mCONFIG_SSREC       equ       %00001000
mCONFIG_LVID        equ       %00010000
mCONFIG_URSTD       equ       %00100000
mCONFIG_LVI5OR3     equ       %01000000
mCONFIG_LVIDR       equ       %10000000


;*** UE0D0 - USB Endpoint 0 Data Register 0
UE0D0               equ       $00000020           ;*** UE0D0 - USB Endpoint 0 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D0_UE0R00_UE0T00 equ       0                   ; Endpoint 0 Receive Data Buffer 0 Bit 0, Endpoint 0 Transmit Data Buffer 0 Bit 0
UE0D0_UE0R01_UE0T01 equ       1                   ; Endpoint 0 Receive Data Buffer 0 Bit 1, Endpoint 0 Transmit Data Buffer 0 Bit 1
UE0D0_UE0R02_UE0T02 equ       2                   ; Endpoint 0 Receive Data Buffer 0 Bit 2, Endpoint 0 Transmit Data Buffer 0 Bit 2
UE0D0_UE0R03_UE0T03 equ       3                   ; Endpoint 0 Receive Data Buffer 0 Bit 3, Endpoint 0 Transmit Data Buffer 0 Bit 3
UE0D0_UE0R04_UE0T04 equ       4                   ; Endpoint 0 Receive Data Buffer 0 Bit 4, Endpoint 0 Transmit Data Buffer 0 Bit 4
UE0D0_UE0R05_UE0T05 equ       5                   ; Endpoint 0 Receive Data Buffer 0 Bit 5, Endpoint 0 Transmit Data Buffer 0 Bit 5
UE0D0_UE0R06_UE0T06 equ       6                   ; Endpoint 0 Receive Data Buffer 0 Bit 6, Endpoint 0 Transmit Data Buffer 0 Bit 6
UE0D0_UE0R07_UE0T07 equ       7                   ; Endpoint 0 Receive Data Buffer 0 Bit 7, Endpoint 0 Transmit Data Buffer 0 Bit 7
; bit position masks
mUE0D0_UE0R00_UE0T00 equ       %00000001
mUE0D0_UE0R01_UE0T01 equ       %00000010
mUE0D0_UE0R02_UE0T02 equ       %00000100
mUE0D0_UE0R03_UE0T03 equ       %00001000
mUE0D0_UE0R04_UE0T04 equ       %00010000
mUE0D0_UE0R05_UE0T05 equ       %00100000
mUE0D0_UE0R06_UE0T06 equ       %01000000
mUE0D0_UE0R07_UE0T07 equ       %10000000


;*** UE0D1 - USB Endpoint 0 Data Register 1
UE0D1               equ       $00000021           ;*** UE0D1 - USB Endpoint 0 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D1_UE0R10_UE0T10 equ       0                   ; Endpoint 0 Receive Data Buffer 1 Bit 0, Endpoint 0 Transmit Data Buffer 1 Bit 0
UE0D1_UE0R11_UE0T11 equ       1                   ; Endpoint 0 Receive Data Buffer 1 Bit 1, Endpoint 0 Transmit Data Buffer 1 Bit 1
UE0D1_UE0R12_UE0T12 equ       2                   ; Endpoint 0 Receive Data Buffer 1 Bit 2, Endpoint 0 Transmit Data Buffer 1 Bit 2
UE0D1_UE0R13_UE0T13 equ       3                   ; Endpoint 0 Receive Data Buffer 1 Bit 3, Endpoint 0 Transmit Data Buffer 1 Bit 3
UE0D1_UE0R14_UE0T14 equ       4                   ; Endpoint 0 Receive Data Buffer 1 Bit 4, Endpoint 0 Transmit Data Buffer 1 Bit 4
UE0D1_UE0R15_UE0T15 equ       5                   ; Endpoint 0 Receive Data Buffer 1 Bit 5, Endpoint 0 Transmit Data Buffer 1 Bit 5
UE0D1_UE0R16_UE0T16 equ       6                   ; Endpoint 0 Receive Data Buffer 1 Bit 6, Endpoint 0 Transmit Data Buffer 1 Bit 6
UE0D1_UE0R17_UE0T17 equ       7                   ; Endpoint 0 Receive Data Buffer 1 Bit 7, Endpoint 0 Transmit Data Buffer 1 Bit 7
; bit position masks
mUE0D1_UE0R10_UE0T10 equ       %00000001
mUE0D1_UE0R11_UE0T11 equ       %00000010
mUE0D1_UE0R12_UE0T12 equ       %00000100
mUE0D1_UE0R13_UE0T13 equ       %00001000
mUE0D1_UE0R14_UE0T14 equ       %00010000
mUE0D1_UE0R15_UE0T15 equ       %00100000
mUE0D1_UE0R16_UE0T16 equ       %01000000
mUE0D1_UE0R17_UE0T17 equ       %10000000


;*** UE0D2 - USB Endpoint 0 Data Register 2
UE0D2               equ       $00000022           ;*** UE0D2 - USB Endpoint 0 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D2_UE0R20_UE0T20 equ       0                   ; Endpoint 0 Receive Data Buffer 2 Bit 0, Endpoint 0 Transmit Data Buffer 2 Bit 0
UE0D2_UE0R21_UE0T21 equ       1                   ; Endpoint 0 Receive Data Buffer 2 Bit 1, Endpoint 0 Transmit Data Buffer 2 Bit 1
UE0D2_UE0R22_UE0T22 equ       2                   ; Endpoint 0 Receive Data Buffer 2 Bit 2, Endpoint 0 Transmit Data Buffer 2 Bit 2
UE0D2_UE0R23_UE0T23 equ       3                   ; Endpoint 0 Receive Data Buffer 2 Bit 3, Endpoint 0 Transmit Data Buffer 2 Bit 3
UE0D2_UE0R24_UE0T24 equ       4                   ; Endpoint 0 Receive Data Buffer 2 Bit 4, Endpoint 0 Transmit Data Buffer 2 Bit 4
UE0D2_UE0R25_UE0T25 equ       5                   ; Endpoint 0 Receive Data Buffer 2 Bit 5, Endpoint 0 Transmit Data Buffer 2 Bit 5
UE0D2_UE0R26_UE0T26 equ       6                   ; Endpoint 0 Receive Data Buffer 2 Bit 6, Endpoint 0 Transmit Data Buffer 2 Bit 6
UE0D2_UE0R27_UE0T27 equ       7                   ; Endpoint 0 Receive Data Buffer 2 Bit 7, Endpoint 0 Transmit Data Buffer 2 Bit 7
; bit position masks
mUE0D2_UE0R20_UE0T20 equ       %00000001
mUE0D2_UE0R21_UE0T21 equ       %00000010
mUE0D2_UE0R22_UE0T22 equ       %00000100
mUE0D2_UE0R23_UE0T23 equ       %00001000
mUE0D2_UE0R24_UE0T24 equ       %00010000
mUE0D2_UE0R25_UE0T25 equ       %00100000
mUE0D2_UE0R26_UE0T26 equ       %01000000
mUE0D2_UE0R27_UE0T27 equ       %10000000


;*** UE0D3 - USB Endpoint 0 Data Register 3
UE0D3               equ       $00000023           ;*** UE0D3 - USB Endpoint 0 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D3_UE0R30_UE0T30 equ       0                   ; Endpoint 0 Receive Data Buffer 3 Bit 0, Endpoint 0 Transmit Data Buffer 3 Bit 0
UE0D3_UE0R31_UE0T31 equ       1                   ; Endpoint 0 Receive Data Buffer 3 Bit 1, Endpoint 0 Transmit Data Buffer 3 Bit 1
UE0D3_UE0R32_UE0T32 equ       2                   ; Endpoint 0 Receive Data Buffer 3 Bit 2, Endpoint 0 Transmit Data Buffer 3 Bit 2
UE0D3_UE0R33_UE0T33 equ       3                   ; Endpoint 0 Receive Data Buffer 3 Bit 3, Endpoint 0 Transmit Data Buffer 3 Bit 3
UE0D3_UE0R34_UE0T34 equ       4                   ; Endpoint 0 Receive Data Buffer 3 Bit 4, Endpoint 0 Transmit Data Buffer 3 Bit 4
UE0D3_UE0R35_UE0T35 equ       5                   ; Endpoint 0 Receive Data Buffer 3 Bit 5, Endpoint 0 Transmit Data Buffer 3 Bit 5
UE0D3_UE0R36_UE0T36 equ       6                   ; Endpoint 0 Receive Data Buffer 3 Bit 6, Endpoint 0 Transmit Data Buffer 3 Bit 6
UE0D3_UE0R37_UE0T37 equ       7                   ; Endpoint 0 Receive Data Buffer 3 Bit 7, Endpoint 0 Transmit Data Buffer 3 Bit 7
; bit position masks
mUE0D3_UE0R30_UE0T30 equ       %00000001
mUE0D3_UE0R31_UE0T31 equ       %00000010
mUE0D3_UE0R32_UE0T32 equ       %00000100
mUE0D3_UE0R33_UE0T33 equ       %00001000
mUE0D3_UE0R34_UE0T34 equ       %00010000
mUE0D3_UE0R35_UE0T35 equ       %00100000
mUE0D3_UE0R36_UE0T36 equ       %01000000
mUE0D3_UE0R37_UE0T37 equ       %10000000


;*** UE0D4 - USB Endpoint 0 Data Register 4
UE0D4               equ       $00000024           ;*** UE0D4 - USB Endpoint 0 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D4_UE0R40_UE0T40 equ       0                   ; Endpoint 0 Receive Data Buffer 4 Bit 0, Endpoint 0 Transmit Data Buffer 4 Bit 0
UE0D4_UE0R41_UE0T41 equ       1                   ; Endpoint 0 Receive Data Buffer 4 Bit 1, Endpoint 0 Transmit Data Buffer 4 Bit 1
UE0D4_UE0R42_UE0T42 equ       2                   ; Endpoint 0 Receive Data Buffer 4 Bit 2, Endpoint 0 Transmit Data Buffer 4 Bit 2
UE0D4_UE0R43_UE0T43 equ       3                   ; Endpoint 0 Receive Data Buffer 4 Bit 3, Endpoint 0 Transmit Data Buffer 4 Bit 3
UE0D4_UE0R44_UE0T44 equ       4                   ; Endpoint 0 Receive Data Buffer 4 Bit 4, Endpoint 0 Transmit Data Buffer 4 Bit 4
UE0D4_UE0R45_UE0T45 equ       5                   ; Endpoint 0 Receive Data Buffer 4 Bit 5, Endpoint 0 Transmit Data Buffer 4 Bit 5
UE0D4_UE0R46_UE0T46 equ       6                   ; Endpoint 0 Receive Data Buffer 4 Bit 6, Endpoint 0 Transmit Data Buffer 4 Bit 6
UE0D4_UE0R47_UE0T47 equ       7                   ; Endpoint 0 Receive Data Buffer 4 Bit 7, Endpoint 0 Transmit Data Buffer 4 Bit 7
; bit position masks
mUE0D4_UE0R40_UE0T40 equ       %00000001
mUE0D4_UE0R41_UE0T41 equ       %00000010
mUE0D4_UE0R42_UE0T42 equ       %00000100
mUE0D4_UE0R43_UE0T43 equ       %00001000
mUE0D4_UE0R44_UE0T44 equ       %00010000
mUE0D4_UE0R45_UE0T45 equ       %00100000
mUE0D4_UE0R46_UE0T46 equ       %01000000
mUE0D4_UE0R47_UE0T47 equ       %10000000


;*** UE0D5 - USB Endpoint 0 Data Register 5
UE0D5               equ       $00000025           ;*** UE0D5 - USB Endpoint 0 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D5_UE0R50_UE0T50 equ       0                   ; Endpoint 0 Receive Data Buffer 5 Bit 0, Endpoint 0 Transmit Data Buffer 5 Bit 0
UE0D5_UE0R51_UE0T51 equ       1                   ; Endpoint 0 Receive Data Buffer 5 Bit 1, Endpoint 0 Transmit Data Buffer 5 Bit 1
UE0D5_UE0R52_UE0T52 equ       2                   ; Endpoint 0 Receive Data Buffer 5 Bit 2, Endpoint 0 Transmit Data Buffer 5 Bit 2
UE0D5_UE0R53_UE0T53 equ       3                   ; Endpoint 0 Receive Data Buffer 5 Bit 3, Endpoint 0 Transmit Data Buffer 5 Bit 3
UE0D5_UE0R54_UE0T54 equ       4                   ; Endpoint 0 Receive Data Buffer 5 Bit 4, Endpoint 0 Transmit Data Buffer 5 Bit 4
UE0D5_UE0R55_UE0T55 equ       5                   ; Endpoint 0 Receive Data Buffer 5 Bit 5, Endpoint 0 Transmit Data Buffer 5 Bit 5
UE0D5_UE0R56_UE0T56 equ       6                   ; Endpoint 0 Receive Data Buffer 5 Bit 6, Endpoint 0 Transmit Data Buffer 5 Bit 6
UE0D5_UE0R57_UE0T57 equ       7                   ; Endpoint 0 Receive Data Buffer 5 Bit 7, Endpoint 0 Transmit Data Buffer 5 Bit 7
; bit position masks
mUE0D5_UE0R50_UE0T50 equ       %00000001
mUE0D5_UE0R51_UE0T51 equ       %00000010
mUE0D5_UE0R52_UE0T52 equ       %00000100
mUE0D5_UE0R53_UE0T53 equ       %00001000
mUE0D5_UE0R54_UE0T54 equ       %00010000
mUE0D5_UE0R55_UE0T55 equ       %00100000
mUE0D5_UE0R56_UE0T56 equ       %01000000
mUE0D5_UE0R57_UE0T57 equ       %10000000


;*** UE0D6 - USB Endpoint 0 Data Register 6
UE0D6               equ       $00000026           ;*** UE0D6 - USB Endpoint 0 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D6_UE0R60_UE0T60 equ       0                   ; Endpoint 0 Receive Data Buffer 6 Bit 0, Endpoint 0 Transmit Data Buffer 6 Bit 0
UE0D6_UE0R61_UE0T61 equ       1                   ; Endpoint 0 Receive Data Buffer 6 Bit 1, Endpoint 0 Transmit Data Buffer 6 Bit 1
UE0D6_UE0R62_UE0T62 equ       2                   ; Endpoint 0 Receive Data Buffer 6 Bit 2, Endpoint 0 Transmit Data Buffer 6 Bit 2
UE0D6_UE0R63_UE0T63 equ       3                   ; Endpoint 0 Receive Data Buffer 6 Bit 3, Endpoint 0 Transmit Data Buffer 6 Bit 3
UE0D6_UE0R64_UE0T64 equ       4                   ; Endpoint 0 Receive Data Buffer 6 Bit 4, Endpoint 0 Transmit Data Buffer 6 Bit 4
UE0D6_UE0R65_UE0T65 equ       5                   ; Endpoint 0 Receive Data Buffer 6 Bit 5, Endpoint 0 Transmit Data Buffer 6 Bit 5
UE0D6_UE0R66_UE0T66 equ       6                   ; Endpoint 0 Receive Data Buffer 6 Bit 6, Endpoint 0 Transmit Data Buffer 6 Bit 6
UE0D6_UE0R67_UE0T67 equ       7                   ; Endpoint 0 Receive Data Buffer 6 Bit 7, Endpoint 0 Transmit Data Buffer 6 Bit 7
; bit position masks
mUE0D6_UE0R60_UE0T60 equ       %00000001
mUE0D6_UE0R61_UE0T61 equ       %00000010
mUE0D6_UE0R62_UE0T62 equ       %00000100
mUE0D6_UE0R63_UE0T63 equ       %00001000
mUE0D6_UE0R64_UE0T64 equ       %00010000
mUE0D6_UE0R65_UE0T65 equ       %00100000
mUE0D6_UE0R66_UE0T66 equ       %01000000
mUE0D6_UE0R67_UE0T67 equ       %10000000


;*** UE0D7 - USB Endpoint 0 Data Register 7
UE0D7               equ       $00000027           ;*** UE0D7 - USB Endpoint 0 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE0D7_UE0R70_UE0T70 equ       0                   ; Endpoint 0 Receive Data Buffer 7 Bit 0, Endpoint 0 Transmit Data Buffer 7 Bit 0
UE0D7_UE0R71_UE0T71 equ       1                   ; Endpoint 0 Receive Data Buffer 7 Bit 1, Endpoint 0 Transmit Data Buffer 7 Bit 1
UE0D7_UE0R72_UE0T72 equ       2                   ; Endpoint 0 Receive Data Buffer 7 Bit 2, Endpoint 0 Transmit Data Buffer 7 Bit 2
UE0D7_UE0R73_UE0T73 equ       3                   ; Endpoint 0 Receive Data Buffer 7 Bit 3, Endpoint 0 Transmit Data Buffer 7 Bit 3
UE0D7_UE0R74_UE0T74 equ       4                   ; Endpoint 0 Receive Data Buffer 7 Bit 4, Endpoint 0 Transmit Data Buffer 7 Bit 4
UE0D7_UE0R75_UE0T75 equ       5                   ; Endpoint 0 Receive Data Buffer 7 Bit 5, Endpoint 0 Transmit Data Buffer 7 Bit 5
UE0D7_UE0R76_UE0T76 equ       6                   ; Endpoint 0 Receive Data Buffer 7 Bit 6, Endpoint 0 Transmit Data Buffer 7 Bit 6
UE0D7_UE0R77_UE0T77 equ       7                   ; Endpoint 0 Receive Data Buffer 7 Bit 7, Endpoint 0 Transmit Data Buffer 7 Bit 7
; bit position masks
mUE0D7_UE0R70_UE0T70 equ       %00000001
mUE0D7_UE0R71_UE0T71 equ       %00000010
mUE0D7_UE0R72_UE0T72 equ       %00000100
mUE0D7_UE0R73_UE0T73 equ       %00001000
mUE0D7_UE0R74_UE0T74 equ       %00010000
mUE0D7_UE0R75_UE0T75 equ       %00100000
mUE0D7_UE0R76_UE0T76 equ       %01000000
mUE0D7_UE0R77_UE0T77 equ       %10000000


;*** UE1D0 - USB Endpoint 1 Data Register 0
UE1D0               equ       $00000028           ;*** UE1D0 - USB Endpoint 1 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D0_UE1T00        equ       0                   ; Endpoint 1 Transmit Data Buffer 0 Bit 0
UE1D0_UE1T01        equ       1                   ; Endpoint 1 Transmit Data Buffer 0 Bit 1
UE1D0_UE1T02        equ       2                   ; Endpoint 1 Transmit Data Buffer 0 Bit 2
UE1D0_UE1T03        equ       3                   ; Endpoint 1 Transmit Data Buffer 0 Bit 3
UE1D0_UE1T04        equ       4                   ; Endpoint 1 Transmit Data Buffer 0 Bit 4
UE1D0_UE1T05        equ       5                   ; Endpoint 1 Transmit Data Buffer 0 Bit 5
UE1D0_UE1T06        equ       6                   ; Endpoint 1 Transmit Data Buffer 0 Bit 6
UE1D0_UE1T07        equ       7                   ; Endpoint 1 Transmit Data Buffer 0 Bit 7
; bit position masks
mUE1D0_UE1T00       equ       %00000001
mUE1D0_UE1T01       equ       %00000010
mUE1D0_UE1T02       equ       %00000100
mUE1D0_UE1T03       equ       %00001000
mUE1D0_UE1T04       equ       %00010000
mUE1D0_UE1T05       equ       %00100000
mUE1D0_UE1T06       equ       %01000000
mUE1D0_UE1T07       equ       %10000000


;*** UE1D1 - USB Endpoint 1 Data Register 1
UE1D1               equ       $00000029           ;*** UE1D1 - USB Endpoint 1 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D1_UE1T10        equ       0                   ; Endpoint 1 Transmit Data Buffer 1 Bit 0
UE1D1_UE1T11        equ       1                   ; Endpoint 1 Transmit Data Buffer 1 Bit 1
UE1D1_UE1T12        equ       2                   ; Endpoint 1 Transmit Data Buffer 1 Bit 2
UE1D1_UE1T13        equ       3                   ; Endpoint 1 Transmit Data Buffer 1 Bit 3
UE1D1_UE1T14        equ       4                   ; Endpoint 1 Transmit Data Buffer 1 Bit 4
UE1D1_UE1T15        equ       5                   ; Endpoint 1 Transmit Data Buffer 1 Bit 5
UE1D1_UE1T16        equ       6                   ; Endpoint 1 Transmit Data Buffer 1 Bit 6
UE1D1_UE1T17        equ       7                   ; Endpoint 1 Transmit Data Buffer 1 Bit 7
; bit position masks
mUE1D1_UE1T10       equ       %00000001
mUE1D1_UE1T11       equ       %00000010
mUE1D1_UE1T12       equ       %00000100
mUE1D1_UE1T13       equ       %00001000
mUE1D1_UE1T14       equ       %00010000
mUE1D1_UE1T15       equ       %00100000
mUE1D1_UE1T16       equ       %01000000
mUE1D1_UE1T17       equ       %10000000


;*** UE1D2 - USB Endpoint 1 Data Register 2
UE1D2               equ       $0000002A           ;*** UE1D2 - USB Endpoint 1 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D2_UE1T20        equ       0                   ; Endpoint 1 Transmit Data Buffer 2 Bit 0
UE1D2_UE1T21        equ       1                   ; Endpoint 1 Transmit Data Buffer 2 Bit 1
UE1D2_UE1T22        equ       2                   ; Endpoint 1 Transmit Data Buffer 2 Bit 2
UE1D2_UE1T23        equ       3                   ; Endpoint 1 Transmit Data Buffer 2 Bit 3
UE1D2_UE1T24        equ       4                   ; Endpoint 1 Transmit Data Buffer 2 Bit 4
UE1D2_UE1T25        equ       5                   ; Endpoint 1 Transmit Data Buffer 2 Bit 5
UE1D2_UE1T26        equ       6                   ; Endpoint 1 Transmit Data Buffer 2 Bit 6
UE1D2_UE1T27        equ       7                   ; Endpoint 1 Transmit Data Buffer 2 Bit 7
; bit position masks
mUE1D2_UE1T20       equ       %00000001
mUE1D2_UE1T21       equ       %00000010
mUE1D2_UE1T22       equ       %00000100
mUE1D2_UE1T23       equ       %00001000
mUE1D2_UE1T24       equ       %00010000
mUE1D2_UE1T25       equ       %00100000
mUE1D2_UE1T26       equ       %01000000
mUE1D2_UE1T27       equ       %10000000


;*** UE1D3 - USB Endpoint 1 Data Register 3
UE1D3               equ       $0000002B           ;*** UE1D3 - USB Endpoint 1 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D3_UE1T30        equ       0                   ; Endpoint 1 Transmit Data Buffer 3 Bit 0
UE1D3_UE1T31        equ       1                   ; Endpoint 1 Transmit Data Buffer 3 Bit 1
UE1D3_UE1T32        equ       2                   ; Endpoint 1 Transmit Data Buffer 3 Bit 2
UE1D3_UE1T33        equ       3                   ; Endpoint 1 Transmit Data Buffer 3 Bit 3
UE1D3_UE1T34        equ       4                   ; Endpoint 1 Transmit Data Buffer 3 Bit 4
UE1D3_UE1T35        equ       5                   ; Endpoint 1 Transmit Data Buffer 3 Bit 5
UE1D3_UE1T36        equ       6                   ; Endpoint 1 Transmit Data Buffer 3 Bit 6
UE1D3_UE1T37        equ       7                   ; Endpoint 1 Transmit Data Buffer 3 Bit 7
; bit position masks
mUE1D3_UE1T30       equ       %00000001
mUE1D3_UE1T31       equ       %00000010
mUE1D3_UE1T32       equ       %00000100
mUE1D3_UE1T33       equ       %00001000
mUE1D3_UE1T34       equ       %00010000
mUE1D3_UE1T35       equ       %00100000
mUE1D3_UE1T36       equ       %01000000
mUE1D3_UE1T37       equ       %10000000


;*** UE1D4 - USB Endpoint 1 Data Register 4
UE1D4               equ       $0000002C           ;*** UE1D4 - USB Endpoint 1 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D4_UE1T40        equ       0                   ; Endpoint 1 Transmit Data Buffer 4 Bit 0
UE1D4_UE1T41        equ       1                   ; Endpoint 1 Transmit Data Buffer 4 Bit 1
UE1D4_UE1T42        equ       2                   ; Endpoint 1 Transmit Data Buffer 4 Bit 2
UE1D4_UE1T43        equ       3                   ; Endpoint 1 Transmit Data Buffer 4 Bit 3
UE1D4_UE1T44        equ       4                   ; Endpoint 1 Transmit Data Buffer 4 Bit 4
UE1D4_UE1T45        equ       5                   ; Endpoint 1 Transmit Data Buffer 4 Bit 5
UE1D4_UE1T46        equ       6                   ; Endpoint 1 Transmit Data Buffer 4 Bit 6
UE1D4_UE1T47        equ       7                   ; Endpoint 1 Transmit Data Buffer 4 Bit 7
; bit position masks
mUE1D4_UE1T40       equ       %00000001
mUE1D4_UE1T41       equ       %00000010
mUE1D4_UE1T42       equ       %00000100
mUE1D4_UE1T43       equ       %00001000
mUE1D4_UE1T44       equ       %00010000
mUE1D4_UE1T45       equ       %00100000
mUE1D4_UE1T46       equ       %01000000
mUE1D4_UE1T47       equ       %10000000


;*** UE1D5 - USB Endpoint 1 Data Register 5
UE1D5               equ       $0000002D           ;*** UE1D5 - USB Endpoint 1 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D5_UE1T50        equ       0                   ; Endpoint 1 Transmit Data Buffer 5 Bit 0
UE1D5_UE1T51        equ       1                   ; Endpoint 1 Transmit Data Buffer 5 Bit 1
UE1D5_UE1T52        equ       2                   ; Endpoint 1 Transmit Data Buffer 5 Bit 2
UE1D5_UE1T53        equ       3                   ; Endpoint 1 Transmit Data Buffer 5 Bit 3
UE1D5_UE1T54        equ       4                   ; Endpoint 1 Transmit Data Buffer 5 Bit 4
UE1D5_UE1T55        equ       5                   ; Endpoint 1 Transmit Data Buffer 5 Bit 5
UE1D5_UE1T56        equ       6                   ; Endpoint 1 Transmit Data Buffer 5 Bit 6
UE1D5_UE1T57        equ       7                   ; Endpoint 1 Transmit Data Buffer 5 Bit 7
; bit position masks
mUE1D5_UE1T50       equ       %00000001
mUE1D5_UE1T51       equ       %00000010
mUE1D5_UE1T52       equ       %00000100
mUE1D5_UE1T53       equ       %00001000
mUE1D5_UE1T54       equ       %00010000
mUE1D5_UE1T55       equ       %00100000
mUE1D5_UE1T56       equ       %01000000
mUE1D5_UE1T57       equ       %10000000


;*** UE1D6 - USB Endpoint 1 Data Register 6
UE1D6               equ       $0000002E           ;*** UE1D6 - USB Endpoint 1 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D6_UE1T60        equ       0                   ; Endpoint 1 Transmit Data Buffer 6 Bit 0
UE1D6_UE1T61        equ       1                   ; Endpoint 1 Transmit Data Buffer 6 Bit 1
UE1D6_UE1T62        equ       2                   ; Endpoint 1 Transmit Data Buffer 6 Bit 2
UE1D6_UE1T63        equ       3                   ; Endpoint 1 Transmit Data Buffer 6 Bit 3
UE1D6_UE1T64        equ       4                   ; Endpoint 1 Transmit Data Buffer 6 Bit 4
UE1D6_UE1T65        equ       5                   ; Endpoint 1 Transmit Data Buffer 6 Bit 5
UE1D6_UE1T66        equ       6                   ; Endpoint 1 Transmit Data Buffer 6 Bit 6
UE1D6_UE1T67        equ       7                   ; Endpoint 1 Transmit Data Buffer 6 Bit 7
; bit position masks
mUE1D6_UE1T60       equ       %00000001
mUE1D6_UE1T61       equ       %00000010
mUE1D6_UE1T62       equ       %00000100
mUE1D6_UE1T63       equ       %00001000
mUE1D6_UE1T64       equ       %00010000
mUE1D6_UE1T65       equ       %00100000
mUE1D6_UE1T66       equ       %01000000
mUE1D6_UE1T67       equ       %10000000


;*** UE1D7 - USB Endpoint 1 Data Register 7
UE1D7               equ       $0000002F           ;*** UE1D7 - USB Endpoint 1 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE1D7_UE1T70        equ       0                   ; Endpoint 1 Transmit Data Buffer 7 Bit 0
UE1D7_UE1T71        equ       1                   ; Endpoint 1 Transmit Data Buffer 7 Bit 1
UE1D7_UE1T72        equ       2                   ; Endpoint 1 Transmit Data Buffer 7 Bit 2
UE1D7_UE1T73        equ       3                   ; Endpoint 1 Transmit Data Buffer 7 Bit 3
UE1D7_UE1T74        equ       4                   ; Endpoint 1 Transmit Data Buffer 7 Bit 4
UE1D7_UE1T75        equ       5                   ; Endpoint 1 Transmit Data Buffer 7 Bit 5
UE1D7_UE1T76        equ       6                   ; Endpoint 1 Transmit Data Buffer 7 Bit 6
UE1D7_UE1T77        equ       7                   ; Endpoint 1 Transmit Data Buffer 7 Bit 7
; bit position masks
mUE1D7_UE1T70       equ       %00000001
mUE1D7_UE1T71       equ       %00000010
mUE1D7_UE1T72       equ       %00000100
mUE1D7_UE1T73       equ       %00001000
mUE1D7_UE1T74       equ       %00010000
mUE1D7_UE1T75       equ       %00100000
mUE1D7_UE1T76       equ       %01000000
mUE1D7_UE1T77       equ       %10000000


;*** UE2D0 - USB Endpoint 2 Data Register 0
UE2D0               equ       $00000030           ;*** UE2D0 - USB Endpoint 2 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D0_UE2R00_UE2T00 equ       0                   ; Endpoint 2 Receive Data Buffer 0 Bit 0, Endpoint 2 Transmit Data Buffer 0 Bit 0
UE2D0_UE2R01_UE2T01 equ       1                   ; Endpoint 2 Receive Data Buffer 0 Bit 1, Endpoint 2 Transmit Data Buffer 0 Bit 1
UE2D0_UE2R02_UE2T02 equ       2                   ; Endpoint 2 Receive Data Buffer 0 Bit 2, Endpoint 2 Transmit Data Buffer 0 Bit 2
UE2D0_UE2R03_UE2T03 equ       3                   ; Endpoint 2 Receive Data Buffer 0 Bit 3, Endpoint 2 Transmit Data Buffer 0 Bit 3
UE2D0_UE2R04_UE2T04 equ       4                   ; Endpoint 2 Receive Data Buffer 0 Bit 4, Endpoint 2 Transmit Data Buffer 0 Bit 4
UE2D0_UE2R05_UE2T05 equ       5                   ; Endpoint 2 Receive Data Buffer 0 Bit 5, Endpoint 2 Transmit Data Buffer 0 Bit 5
UE2D0_UE2R06_UE2T06 equ       6                   ; Endpoint 2 Receive Data Buffer 0 Bit 6, Endpoint 2 Transmit Data Buffer 0 Bit 6
UE2D0_UE2R07_UE2T07 equ       7                   ; Endpoint 2 Receive Data Buffer 0 Bit 7, Endpoint 2 Transmit Data Buffer 0 Bit 7
; bit position masks
mUE2D0_UE2R00_UE2T00 equ       %00000001
mUE2D0_UE2R01_UE2T01 equ       %00000010
mUE2D0_UE2R02_UE2T02 equ       %00000100
mUE2D0_UE2R03_UE2T03 equ       %00001000
mUE2D0_UE2R04_UE2T04 equ       %00010000
mUE2D0_UE2R05_UE2T05 equ       %00100000
mUE2D0_UE2R06_UE2T06 equ       %01000000
mUE2D0_UE2R07_UE2T07 equ       %10000000


;*** UE2D1 - USB Endpoint 2 Data Register 1
UE2D1               equ       $00000031           ;*** UE2D1 - USB Endpoint 2 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D1_UE2R10_UE2T10 equ       0                   ; Endpoint 2 Receive Data Buffer 1 Bit 0, Endpoint 2 Transmit Data Buffer 1 Bit 0
UE2D1_UE2R11_UE2T11 equ       1                   ; Endpoint 2 Receive Data Buffer 1 Bit 1, Endpoint 2 Transmit Data Buffer 1 Bit 1
UE2D1_UE2R12_UE2T12 equ       2                   ; Endpoint 2 Receive Data Buffer 1 Bit 2, Endpoint 2 Transmit Data Buffer 1 Bit 2
UE2D1_UE2R13_UE2T13 equ       3                   ; Endpoint 2 Receive Data Buffer 1 Bit 3, Endpoint 2 Transmit Data Buffer 1 Bit 3
UE2D1_UE2R14_UE2T14 equ       4                   ; Endpoint 2 Receive Data Buffer 1 Bit 4, Endpoint 2 Transmit Data Buffer 1 Bit 4
UE2D1_UE2R15_UE2T15 equ       5                   ; Endpoint 2 Receive Data Buffer 1 Bit 5, Endpoint 2 Transmit Data Buffer 1 Bit 5
UE2D1_UE2R16_UE2T16 equ       6                   ; Endpoint 2 Receive Data Buffer 1 Bit 6, Endpoint 2 Transmit Data Buffer 1 Bit 6
UE2D1_UE2R17_UE2T17 equ       7                   ; Endpoint 2 Receive Data Buffer 1 Bit 7, Endpoint 2 Transmit Data Buffer 1 Bit 7
; bit position masks
mUE2D1_UE2R10_UE2T10 equ       %00000001
mUE2D1_UE2R11_UE2T11 equ       %00000010
mUE2D1_UE2R12_UE2T12 equ       %00000100
mUE2D1_UE2R13_UE2T13 equ       %00001000
mUE2D1_UE2R14_UE2T14 equ       %00010000
mUE2D1_UE2R15_UE2T15 equ       %00100000
mUE2D1_UE2R16_UE2T16 equ       %01000000
mUE2D1_UE2R17_UE2T17 equ       %10000000


;*** UE2D2 - USB Endpoint 2 Data Register 2
UE2D2               equ       $00000032           ;*** UE2D2 - USB Endpoint 2 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D2_UE2R20_UE2T20 equ       0                   ; Endpoint 2 Receive Data Buffer 2 Bit 0, Endpoint 2 Transmit Data Buffer 2 Bit 0
UE2D2_UE2R21_UE2T21 equ       1                   ; Endpoint 2 Receive Data Buffer 2 Bit 1, Endpoint 2 Transmit Data Buffer 2 Bit 1
UE2D2_UE2R22_UE2T22 equ       2                   ; Endpoint 2 Receive Data Buffer 2 Bit 2, Endpoint 2 Transmit Data Buffer 2 Bit 2
UE2D2_UE2R23_UE2T23 equ       3                   ; Endpoint 2 Receive Data Buffer 2 Bit 3, Endpoint 2 Transmit Data Buffer 2 Bit 3
UE2D2_UE2R24_UE2T24 equ       4                   ; Endpoint 2 Receive Data Buffer 2 Bit 4, Endpoint 2 Transmit Data Buffer 2 Bit 4
UE2D2_UE2R25_UE2T25 equ       5                   ; Endpoint 2 Receive Data Buffer 2 Bit 5, Endpoint 2 Transmit Data Buffer 2 Bit 5
UE2D2_UE2R26_UE2T26 equ       6                   ; Endpoint 2 Receive Data Buffer 2 Bit 6, Endpoint 2 Transmit Data Buffer 2 Bit 6
UE2D2_UE2R27_UE2T27 equ       7                   ; Endpoint 2 Receive Data Buffer 2 Bit 7, Endpoint 2 Transmit Data Buffer 2 Bit 7
; bit position masks
mUE2D2_UE2R20_UE2T20 equ       %00000001
mUE2D2_UE2R21_UE2T21 equ       %00000010
mUE2D2_UE2R22_UE2T22 equ       %00000100
mUE2D2_UE2R23_UE2T23 equ       %00001000
mUE2D2_UE2R24_UE2T24 equ       %00010000
mUE2D2_UE2R25_UE2T25 equ       %00100000
mUE2D2_UE2R26_UE2T26 equ       %01000000
mUE2D2_UE2R27_UE2T27 equ       %10000000


;*** UE2D3 - USB Endpoint 2 Data Register 3
UE2D3               equ       $00000033           ;*** UE2D3 - USB Endpoint 2 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D3_UE2R30_UE2T30 equ       0                   ; Endpoint 2 Receive Data Buffer 3 Bit 0, Endpoint 2 Transmit Data Buffer 3 Bit 0
UE2D3_UE2R31_UE2T31 equ       1                   ; Endpoint 2 Receive Data Buffer 3 Bit 1, Endpoint 2 Transmit Data Buffer 3 Bit 1
UE2D3_UE2R32_UE2T32 equ       2                   ; Endpoint 2 Receive Data Buffer 3 Bit 2, Endpoint 2 Transmit Data Buffer 3 Bit 2
UE2D3_UE2R33_UE2T33 equ       3                   ; Endpoint 2 Receive Data Buffer 3 Bit 3, Endpoint 2 Transmit Data Buffer 3 Bit 3
UE2D3_UE2R34_UE2T34 equ       4                   ; Endpoint 2 Receive Data Buffer 3 Bit 4, Endpoint 2 Transmit Data Buffer 3 Bit 4
UE2D3_UE2R35_UE2T35 equ       5                   ; Endpoint 2 Receive Data Buffer 3 Bit 5, Endpoint 2 Transmit Data Buffer 3 Bit 5
UE2D3_UE2R36_UE2T36 equ       6                   ; Endpoint 2 Receive Data Buffer 3 Bit 6, Endpoint 2 Transmit Data Buffer 3 Bit 6
UE2D3_UE2R37_UE2T37 equ       7                   ; Endpoint 2 Receive Data Buffer 3 Bit 7, Endpoint 2 Transmit Data Buffer 3 Bit 7
; bit position masks
mUE2D3_UE2R30_UE2T30 equ       %00000001
mUE2D3_UE2R31_UE2T31 equ       %00000010
mUE2D3_UE2R32_UE2T32 equ       %00000100
mUE2D3_UE2R33_UE2T33 equ       %00001000
mUE2D3_UE2R34_UE2T34 equ       %00010000
mUE2D3_UE2R35_UE2T35 equ       %00100000
mUE2D3_UE2R36_UE2T36 equ       %01000000
mUE2D3_UE2R37_UE2T37 equ       %10000000


;*** UE2D4 - USB Endpoint 2 Data Register 4
UE2D4               equ       $00000034           ;*** UE2D4 - USB Endpoint 2 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D4_UE2R40_UE2T40 equ       0                   ; Endpoint 2 Receive Data Buffer 4 Bit 0, Endpoint 2 Transmit Data Buffer 4 Bit 0
UE2D4_UE2R41_UE2T41 equ       1                   ; Endpoint 2 Receive Data Buffer 4 Bit 1, Endpoint 2 Transmit Data Buffer 4 Bit 1
UE2D4_UE2R42_UE2T42 equ       2                   ; Endpoint 2 Receive Data Buffer 4 Bit 2, Endpoint 2 Transmit Data Buffer 4 Bit 2
UE2D4_UE2R43_UE2T43 equ       3                   ; Endpoint 2 Receive Data Buffer 4 Bit 3, Endpoint 2 Transmit Data Buffer 4 Bit 3
UE2D4_UE2R44_UE2T44 equ       4                   ; Endpoint 2 Receive Data Buffer 4 Bit 4, Endpoint 2 Transmit Data Buffer 4 Bit 4
UE2D4_UE2R45_UE2T45 equ       5                   ; Endpoint 2 Receive Data Buffer 4 Bit 5, Endpoint 2 Transmit Data Buffer 4 Bit 5
UE2D4_UE2R46_UE2T46 equ       6                   ; Endpoint 2 Receive Data Buffer 4 Bit 6, Endpoint 2 Transmit Data Buffer 4 Bit 6
UE2D4_UE2R47_UE2T47 equ       7                   ; Endpoint 2 Receive Data Buffer 4 Bit 7, Endpoint 2 Transmit Data Buffer 4 Bit 7
; bit position masks
mUE2D4_UE2R40_UE2T40 equ       %00000001
mUE2D4_UE2R41_UE2T41 equ       %00000010
mUE2D4_UE2R42_UE2T42 equ       %00000100
mUE2D4_UE2R43_UE2T43 equ       %00001000
mUE2D4_UE2R44_UE2T44 equ       %00010000
mUE2D4_UE2R45_UE2T45 equ       %00100000
mUE2D4_UE2R46_UE2T46 equ       %01000000
mUE2D4_UE2R47_UE2T47 equ       %10000000


;*** UE2D5 - USB Endpoint 2 Data Register 5
UE2D5               equ       $00000035           ;*** UE2D5 - USB Endpoint 2 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D5_UE2R50_UE2T50 equ       0                   ; Endpoint 2 Receive Data Buffer 5 Bit 0, Endpoint 2 Transmit Data Buffer 5 Bit 0
UE2D5_UE2R51_UE2T51 equ       1                   ; Endpoint 2 Receive Data Buffer 5 Bit 1, Endpoint 2 Transmit Data Buffer 5 Bit 1
UE2D5_UE2R52_UE2T52 equ       2                   ; Endpoint 2 Receive Data Buffer 5 Bit 2, Endpoint 2 Transmit Data Buffer 5 Bit 2
UE2D5_UE2R53_UE2T53 equ       3                   ; Endpoint 2 Receive Data Buffer 5 Bit 3, Endpoint 2 Transmit Data Buffer 5 Bit 3
UE2D5_UE2R54_UE2T54 equ       4                   ; Endpoint 2 Receive Data Buffer 5 Bit 4, Endpoint 2 Transmit Data Buffer 5 Bit 4
UE2D5_UE2R55_UE2T55 equ       5                   ; Endpoint 2 Receive Data Buffer 5 Bit 5, Endpoint 2 Transmit Data Buffer 5 Bit 5
UE2D5_UE2R56_UE2T56 equ       6                   ; Endpoint 2 Receive Data Buffer 5 Bit 6, Endpoint 2 Transmit Data Buffer 5 Bit 6
UE2D5_UE2R57_UE2T57 equ       7                   ; Endpoint 2 Receive Data Buffer 5 Bit 7, Endpoint 2 Transmit Data Buffer 5 Bit 7
; bit position masks
mUE2D5_UE2R50_UE2T50 equ       %00000001
mUE2D5_UE2R51_UE2T51 equ       %00000010
mUE2D5_UE2R52_UE2T52 equ       %00000100
mUE2D5_UE2R53_UE2T53 equ       %00001000
mUE2D5_UE2R54_UE2T54 equ       %00010000
mUE2D5_UE2R55_UE2T55 equ       %00100000
mUE2D5_UE2R56_UE2T56 equ       %01000000
mUE2D5_UE2R57_UE2T57 equ       %10000000


;*** UE2D6 - USB Endpoint 2 Data Register 6
UE2D6               equ       $00000036           ;*** UE2D6 - USB Endpoint 2 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D6_UE2R60_UE2T60 equ       0                   ; Endpoint 2 Receive Data Buffer 5 Bit 0, Endpoint 2 Transmit Data Buffer 6 Bit 0
UE2D6_UE2R61_UE2T61 equ       1                   ; Endpoint 2 Receive Data Buffer 5 Bit 1, Endpoint 2 Transmit Data Buffer 6 Bit 1
UE2D6_UE2R62_UE2T62 equ       2                   ; Endpoint 2 Receive Data Buffer 5 Bit 2, Endpoint 2 Transmit Data Buffer 6 Bit 2
UE2D6_UE2R63_UE2T63 equ       3                   ; Endpoint 2 Receive Data Buffer 5 Bit 3, Endpoint 2 Transmit Data Buffer 6 Bit 3
UE2D6_UE2R64_UE2T64 equ       4                   ; Endpoint 2 Receive Data Buffer 5 Bit 4, Endpoint 2 Transmit Data Buffer 6 Bit 4
UE2D6_UE2R65_UE2T65 equ       5                   ; Endpoint 2 Receive Data Buffer 5 Bit 5, Endpoint 2 Transmit Data Buffer 6 Bit 5
UE2D6_UE2R66_UE2T66 equ       6                   ; Endpoint 2 Receive Data Buffer 5 Bit 6, Endpoint 2 Transmit Data Buffer 6 Bit 6
UE2D6_UE2R67_UE2T67 equ       7                   ; Endpoint 2 Receive Data Buffer 5 Bit 7, Endpoint 2 Transmit Data Buffer 6 Bit 7
; bit position masks
mUE2D6_UE2R60_UE2T60 equ       %00000001
mUE2D6_UE2R61_UE2T61 equ       %00000010
mUE2D6_UE2R62_UE2T62 equ       %00000100
mUE2D6_UE2R63_UE2T63 equ       %00001000
mUE2D6_UE2R64_UE2T64 equ       %00010000
mUE2D6_UE2R65_UE2T65 equ       %00100000
mUE2D6_UE2R66_UE2T66 equ       %01000000
mUE2D6_UE2R67_UE2T67 equ       %10000000


;*** UE2D7 - USB Endpoint 2 Data Register 7
UE2D7               equ       $00000037           ;*** UE2D7 - USB Endpoint 2 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UE2D7_UE2R70_UE2T70 equ       0                   ; Endpoint 2 Receive Data Buffer 7 Bit 0, Endpoint 2 Transmit Data Buffer 7 Bit 0
UE2D7_UE2R71_UE2T71 equ       1                   ; Endpoint 2 Receive Data Buffer 7 Bit 1, Endpoint 2 Transmit Data Buffer 7 Bit 1
UE2D7_UE2R72_UE2T72 equ       2                   ; Endpoint 2 Receive Data Buffer 7 Bit 2, Endpoint 2 Transmit Data Buffer 7 Bit 2
UE2D7_UE2R73_UE2T73 equ       3                   ; Endpoint 2 Receive Data Buffer 7 Bit 3, Endpoint 2 Transmit Data Buffer 7 Bit 3
UE2D7_UE2R74_UE2T74 equ       4                   ; Endpoint 2 Receive Data Buffer 7 Bit 4, Endpoint 2 Transmit Data Buffer 7 Bit 4
UE2D7_UE2R75_UE2T75 equ       5                   ; Endpoint 2 Receive Data Buffer 7 Bit 5, Endpoint 2 Transmit Data Buffer 7 Bit 5
UE2D7_UE2R76_UE2T76 equ       6                   ; Endpoint 2 Receive Data Buffer 7 Bit 6, Endpoint 2 Transmit Data Buffer 7 Bit 6
UE2D7_UE2R77_UE2T77 equ       7                   ; Endpoint 2 Receive Data Buffer 7 Bit 7, Endpoint 2 Transmit Data Buffer 7 Bit 7
; bit position masks
mUE2D7_UE2R70_UE2T70 equ       %00000001
mUE2D7_UE2R71_UE2T71 equ       %00000010
mUE2D7_UE2R72_UE2T72 equ       %00000100
mUE2D7_UE2R73_UE2T73 equ       %00001000
mUE2D7_UE2R74_UE2T74 equ       %00010000
mUE2D7_UE2R75_UE2T75 equ       %00100000
mUE2D7_UE2R76_UE2T76 equ       %01000000
mUE2D7_UE2R77_UE2T77 equ       %10000000


;*** UADDR - USB Address Register
UADDR               equ       $00000038           ;*** UADDR - USB Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UADDR_UADD0         equ       0                   ; USB Function Address Bit 0
UADDR_UADD1         equ       1                   ; USB Function Address Bit 1
UADDR_UADD2         equ       2                   ; USB Function Address Bit 2
UADDR_UADD3         equ       3                   ; USB Function Address Bit 3
UADDR_UADD4         equ       4                   ; USB Function Address Bit 4
UADDR_UADD5         equ       5                   ; USB Function Address Bit 5
UADDR_UADD6         equ       6                   ; USB Function Address Bit 6
UADDR_USBEN         equ       7                   ; USB Module Enable
; bit position masks
mUADDR_UADD0        equ       %00000001
mUADDR_UADD1        equ       %00000010
mUADDR_UADD2        equ       %00000100
mUADDR_UADD3        equ       %00001000
mUADDR_UADD4        equ       %00010000
mUADDR_UADD5        equ       %00100000
mUADDR_UADD6        equ       %01000000
mUADDR_USBEN        equ       %10000000


;*** UIR0 - USB Interrupt Register 0
UIR0                equ       $00000039           ;*** UIR0 - USB Interrupt Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UIR0_RXD0IE         equ       0                   ; Endpoint 0 Receive Interrupt Enable
UIR0_TXD0IE         equ       1                   ; Endpoint 0 Transmit Interrupt Enable
UIR0_TXD1IE         equ       3                   ; Endpoint 1 Transmit Interrupt Enable
UIR0_RXD2IE         equ       4                   ; Endpoint 2 Receive Interrupt Enable
UIR0_TXD2IE         equ       5                   ; Endpoint 2 Transmit Interrupt Enable
UIR0_SUSPND         equ       6                   ; USB Suspend Bit
UIR0_EOPIE          equ       7                   ; End-of-Packet Detect Interrupt Enable
; bit position masks
mUIR0_RXD0IE        equ       %00000001
mUIR0_TXD0IE        equ       %00000010
mUIR0_TXD1IE        equ       %00001000
mUIR0_RXD2IE        equ       %00010000
mUIR0_TXD2IE        equ       %00100000
mUIR0_SUSPND        equ       %01000000
mUIR0_EOPIE         equ       %10000000


;*** UIR1 - USB Interrupt Register 1
UIR1                equ       $0000003A           ;*** UIR1 - USB Interrupt Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UIR1_RXD0F          equ       0                   ; Endpoint 0 Data Receive Flag
UIR1_TXD0F          equ       1                   ; Endpoint 0 Data Transmit Flag
UIR1_RESUMF         equ       2                   ; Resume Flag
UIR1_TXD1F          equ       3                   ; Endpoint 1 Data Transmit Flag
UIR1_RXD2F          equ       4                   ; Endpoint 2 Data Receive Flag
UIR1_TXD2F          equ       5                   ; Endpoint 2 Data Transmit Flag
UIR1_RSTF           equ       6                   ; USB Reset Flag
UIR1_EOPF           equ       7                   ; End-of-Packet Detect Flag
; bit position masks
mUIR1_RXD0F         equ       %00000001
mUIR1_TXD0F         equ       %00000010
mUIR1_RESUMF        equ       %00000100
mUIR1_TXD1F         equ       %00001000
mUIR1_RXD2F         equ       %00010000
mUIR1_TXD2F         equ       %00100000
mUIR1_RSTF          equ       %01000000
mUIR1_EOPF          equ       %10000000


;*** UCR0 - USB Control Register 0
UCR0                equ       $0000003B           ;*** UCR0 - USB Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR0_TP0SIZ0        equ       0                   ; Endpoint 0 Transmit Data Packet Size Bit 0
UCR0_TP0SIZ1        equ       1                   ; Endpoint 0 Transmit Data Packet Size Bit 1
UCR0_TP0SIZ2        equ       2                   ; Endpoint 0 Transmit Data Packet Size Bit 2
UCR0_TP0SIZ3        equ       3                   ; Endpoint 0 Transmit Data Packet Size Bit 3
UCR0_RX0E           equ       4                   ; Endpoint 0 Receive Enable
UCR0_TX0E           equ       5                   ; Endpoint 0 Transmit Enable
UCR0_T0SEQ          equ       7                   ; Endpoint 0 Transmit Sequence Bit
; bit position masks
mUCR0_TP0SIZ0       equ       %00000001
mUCR0_TP0SIZ1       equ       %00000010
mUCR0_TP0SIZ2       equ       %00000100
mUCR0_TP0SIZ3       equ       %00001000
mUCR0_RX0E          equ       %00010000
mUCR0_TX0E          equ       %00100000
mUCR0_T0SEQ         equ       %10000000


;*** UCR1 - USB Control Register 1
UCR1                equ       $0000003C           ;*** UCR1 - USB Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR1_TP1SIZ0        equ       0                   ; Endpoint 1 Transmit Data Packet Size Bit 0
UCR1_TP1SIZ1        equ       1                   ; Endpoint 1 Transmit Data Packet Size Bit 1
UCR1_TP1SIZ2        equ       2                   ; Endpoint 1 Transmit Data Packet Size Bit 2
UCR1_TP1SIZ3        equ       3                   ; Endpoint 1 Transmit Data Packet Size Bit 3
UCR1_FRESUM         equ       4                   ; Force Resume
UCR1_TX1E           equ       5                   ; Endpoint 1 Transmit Enable
UCR1_STALL1         equ       6                   ; Endpoint 1 Force Stall Bit
UCR1_T1SEQ          equ       7                   ; Endpoint 1 Transmit Sequence Bit
; bit position masks
mUCR1_TP1SIZ0       equ       %00000001
mUCR1_TP1SIZ1       equ       %00000010
mUCR1_TP1SIZ2       equ       %00000100
mUCR1_TP1SIZ3       equ       %00001000
mUCR1_FRESUM        equ       %00010000
mUCR1_TX1E          equ       %00100000
mUCR1_STALL1        equ       %01000000
mUCR1_T1SEQ         equ       %10000000


;*** USR0 - USB Status Register 0
USR0                equ       $0000003D           ;*** USR0 - USB Status Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USR0_RP0SIZ0        equ       0                   ; Endpoint 0 Receive Data Packet Size Bit 0
USR0_RP0SIZ1        equ       1                   ; Endpoint 0 Receive Data Packet Size Bit 1
USR0_RP0SIZ2        equ       2                   ; Endpoint 0 Receive Data Packet Size Bit 2
USR0_RP0SIZ3        equ       3                   ; Endpoint 0 Receive Data Packet Size Bit 3
USR0_SETUP          equ       6                   ; SETUP Token Detect Bit
USR0_R0SEQ          equ       7                   ; Endpoint 0 Receive Sequence Bit
; bit position masks
mUSR0_RP0SIZ0       equ       %00000001
mUSR0_RP0SIZ1       equ       %00000010
mUSR0_RP0SIZ2       equ       %00000100
mUSR0_RP0SIZ3       equ       %00001000
mUSR0_SETUP         equ       %01000000
mUSR0_R0SEQ         equ       %10000000


;*** USR1 - USB Status Register 1
USR1                equ       $0000003E           ;*** USR1 - USB Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USR1_RP2SIZ0        equ       0                   ; Endpoint 2 Receive Data Packet Size Bit 0
USR1_RP2SIZ1        equ       1                   ; Endpoint 2 Receive Data Packet Size Bit 1
USR1_RP2SIZ2        equ       2                   ; Endpoint 2 Receive Data Packet Size Bit 2
USR1_RP2SIZ3        equ       3                   ; Endpoint 2 Receive Data Packet Size Bit 3
USR1_TXSTL          equ       4                   ; STALL Token Transmit Bit
USR1_TXNAK          equ       5                   ; NAK Token Transmit Bit
USR1_TXACK          equ       6                   ; ACK Token Transmit Bit
USR1_R2SEQ          equ       7                   ; Endpoint 2 Receive Sequence Bit
; bit position masks
mUSR1_RP2SIZ0       equ       %00000001
mUSR1_RP2SIZ1       equ       %00000010
mUSR1_RP2SIZ2       equ       %00000100
mUSR1_RP2SIZ3       equ       %00001000
mUSR1_TXSTL         equ       %00010000
mUSR1_TXNAK         equ       %00100000
mUSR1_TXACK         equ       %01000000
mUSR1_R2SEQ         equ       %10000000


;*** T2SC - TIM2 Status and Control Register TSC
T2SC                equ       $00000040           ;*** T2SC - TIM2 Status and Control Register TSC
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
T2CNT               equ       $00000042           ;*** T2CNT - TIM2 Counter Register


;*** T2CNTH - TIM2 Counter Register High
T2CNTH              equ       $00000042           ;*** T2CNTH - TIM2 Counter Register High


;*** T2CNTL - TIM2 Counter Register Low
T2CNTL              equ       $00000043           ;*** T2CNTL - TIM2 Counter Register Low


;*** T2MOD - TIM2 Counter Modulo Register
T2MOD               equ       $00000044           ;*** T2MOD - TIM2 Counter Modulo Register


;*** T2MODH - TIM2 Counter Modulo Register High
T2MODH              equ       $00000044           ;*** T2MODH - TIM2 Counter Modulo Register High


;*** T2MODL - TIM2 Counter Modulo Register Low
T2MODL              equ       $00000045           ;*** T2MODL - TIM2 Counter Modulo Register Low


;*** T2SC0 - TIM2 Channel 0 Status and Control Register
T2SC0               equ       $00000046           ;*** T2SC0 - TIM2 Channel 0 Status and Control Register
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
T2CH0               equ       $00000047           ;*** T2CH0 - TIM2 Channel 0 Register


;*** T2CH0H - TIM2 Channel 0 Register High
T2CH0H              equ       $00000047           ;*** T2CH0H - TIM2 Channel 0 Register High


;*** T2CH0L - TIM2 Channel 0 Register Low
T2CH0L              equ       $00000048           ;*** T2CH0L - TIM2 Channel 0 Register Low


;*** T2SC1 - TIM2 Channel 1 Status and Control Register
T2SC1               equ       $00000049           ;*** T2SC1 - TIM2 Channel 1 Status and Control Register
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
T2CH1               equ       $0000004A           ;*** T2CH1 - TIM2 Channel 1 Register


;*** T2CH1H - TIM2 Channel 1 Register High
T2CH1H              equ       $0000004A           ;*** T2CH1H - TIM2 Channel 1 Register High


;*** T2CH1L - TIM2 Channel 1 Register Low
T2CH1L              equ       $0000004B           ;*** T2CH1L - TIM2 Channel 1 Register Low


;*** SCC1 - SCI Control Register 1
SCC1                equ       $0000005A           ;*** SCC1 - SCI Control Register 1
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
SCC2                equ       $0000005B           ;*** SCC2 - SCI Control Register 2
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
SCC3                equ       $0000005C           ;*** SCC3 - SCI Control Register 3
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
SCS1                equ       $0000005D           ;*** SCS1 - SCI Status Register 1
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
SCS2                equ       $0000005E           ;*** SCS2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS2_RPF            equ       0                   ; Reception in Progress Flag Bit
SCS2_BKF            equ       1                   ; Break Flag Bit
; bit position masks
mSCS2_RPF           equ       %00000001
mSCS2_BKF           equ       %00000010


;*** SCDR - SCI Data Register
SCDR                equ       $0000005F           ;*** SCDR - SCI Data Register
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
SCBR                equ       $00000060           ;*** SCBR - SCI Baud Rate Register
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


;*** BSR - Break Status Register
BSR                 equ       $0000FE00           ;*** BSR - Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BSR_SBSW            equ       1                   ; SIM Break Stop/Wait Bit
; bit position masks
mBSR_SBSW           equ       %00000010


;*** RSR - Reset Status Register
RSR                 equ       $0000FE01           ;*** RSR - Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RSR_LVI             equ       1                   ; Low-Voltage Inhibit Reset Bit
RSR_USB             equ       2                   ; Universal Serial Bus Reset Bit
RSR_ILAD            equ       3                   ; Illegal Address Reset Bit
RSR_ILOP            equ       4                   ; Illegal Opcode Reset Bit
RSR_COP             equ       5                   ; Computer Operating Properly Reset Bit
RSR_PIN             equ       6                   ; External Reset Bit
RSR_POR             equ       7                   ; Power-On Reset Bit
; bit position masks
mRSR_LVI            equ       %00000010
mRSR_USB            equ       %00000100
mRSR_ILAD           equ       %00001000
mRSR_ILOP           equ       %00010000
mRSR_COP            equ       %00100000
mRSR_PIN            equ       %01000000
mRSR_POR            equ       %10000000


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
INT1_IF2            equ       3                   ; Interrrupt Flag 2
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


;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FE09           ;*** FLBPR - FLASH Block Protect Register
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
