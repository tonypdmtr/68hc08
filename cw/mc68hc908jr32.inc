;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908JR32, version 2.87.091 (RegistersPrg V2.23)

; ###################################################################
;     Filename  : mc68hc908jr32.inc
;     Processor : MC68HC908JR32FB
;     FileFormat: V2.23
;     DataSheet : PC68HC908JF32 — Rev. 1.2 review May 17, 2004 5:02 am
;     Compiler  : CodeWarrior compiler
;     Date/Time : 26.2.2008, 11:37
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     (c) Copyright UNIS, spol. s r.o. 1997-2008
;     UNIS, spol. s r.o.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;      - 14.11.2005, V2.00 :
;               - Deprecated symbols added for backward compatibility (section at the end of this file)
;      - 15.11.2005, V2.01 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 17.12.2005, V2.02 :
;               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
;      - 16.01.2006, V2.03 :
;               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
;               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
;      - 08.03.2006, V2.04 :
;               - Support for bit(s) names duplicated with any register name in .h header files
;      - 24.03.2006, V2.05 :
;               -  Changes have not affected this file (because they are related to another family)
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
;               -  Changes have not affected this file (because they are related to another family)
;      - 22.01.2007, V2.12 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 01.03.2007, V2.13 :
;               - Flash commands constants values converted to HEX format
;      - 02.03.2007, V2.14 :
;               - Interrupt vector numbers added into .H, see VectorNumber_*
;      - 26.03.2007, V2.15 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 10.05.2007, V2.16 :
;               - Fixed flash commands definition for ColdFireV1 assembler (equ -> .equ)
;      - 05.06.2007, V2.17 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 19.07.2007, V2.18 :
;               - Improved number of blanked lines inside register structures
;      - 06.08.2007, V2.19 :
;               - CPUDB revisions generated ahead of the file-format revisions.
;      - 11.09.2007, V2.20 :
;               - Added comment about initialization of unbonded pins.
;      - 02.01.2008, V2.21 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 13.02.2008, V2.22 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 20.02.2008, V2.23 :
;               -  Changes have not affected this file (because they are related to another family)
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $00007000
ROM_END             equ       $0000EFFF
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000045F
;
INT_TBM             equ       $0000FFDE
INT_KBI             equ       $0000FFE0
INT_SPITransmit     equ       $0000FFE2
INT_SPIReceive      equ       $0000FFE4
INT_DCM2Receive     equ       $0000FFE6
INT_DCM1Transmit    equ       $0000FFE8
INT_DCM1Receive     equ       $0000FFEA
INT_PS2             equ       $0000FFEC
INT_TIM1Ovr         equ       $0000FFEE
INT_TIM1CH1         equ       $0000FFF0
INT_TIM1CH0         equ       $0000FFF2
INT_PLL             equ       $0000FFF4
INT_IRQ             equ       $0000FFF6
INT_USBEndpoint     equ       $0000FFF8
INT_USBSystem       equ       $0000FFFA
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

;*** PTC - Port C Data Register
PTC                 equ       $00000002           ;*** PTC - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTC_PTC0            equ       0                   ; Port C Data Bit 0
PTC_PTC1            equ       1                   ; Port C Data Bit 1
PTC_PTC2            equ       2                   ; Port C Data Bit 2
PTC_PTC3            equ       3                   ; Port C Data Bit 3
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010
mPTC_PTC2           equ       %00000100
mPTC_PTC3           equ       %00001000

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

;*** DDRC - Data Direction Register C
DDRC                equ       $00000006           ;*** DDRC - Data Direction Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRC_DDRC0          equ       0                   ; Data Direction Register C Bit 0
DDRC_DDRC1          equ       1                   ; Data Direction Register C Bit 1
DDRC_DDRC2          equ       2                   ; Data Direction Register C Bit 2
DDRC_DDRC3          equ       3                   ; Data Direction Register C Bit 3
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000

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
PTE_PTE2            equ       2                   ; Port E Data Bit 2
PTE_PTE3            equ       3                   ; Port E Data Bit 3
PTE_PTE4            equ       4                   ; Port E Data Bit 4
PTE_PTE5            equ       5                   ; Port E Data Bit 5
PTE_PTE6            equ       6                   ; Port E Data Bit 6
PTE_PTE7            equ       7                   ; Port E Data Bit 7
; bit position masks
mPTE_PTE2           equ       %00000100
mPTE_PTE3           equ       %00001000
mPTE_PTE4           equ       %00010000
mPTE_PTE5           equ       %00100000
mPTE_PTE6           equ       %01000000
mPTE_PTE7           equ       %10000000

;*** DDRE - Data Direction Register E
DDRE                equ       $00000009           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE2          equ       2                   ; Data Direction Register E Bit 2
DDRE_DDRE3          equ       3                   ; Data Direction Register E Bit 3
DDRE_DDRE4          equ       4                   ; Data Direction Register E Bit 4
DDRE_DDRE5          equ       5                   ; Data Direction Register E Bit 5
DDRE_DDRE6          equ       6                   ; Data Direction Register E Bit 6
DDRE_DDRE7          equ       7                   ; Data Direction Register E Bit 7
; bit position masks
mDDRE_DDRE2         equ       %00000100
mDDRE_DDRE3         equ       %00001000
mDDRE_DDRE4         equ       %00010000
mDDRE_DDRE5         equ       %00100000
mDDRE_DDRE6         equ       %01000000
mDDRE_DDRE7         equ       %10000000

;*** T1SC - TIM1 Status and Control Register TSC
T1SC                equ       $0000000A           ;*** T1SC - TIM1 Status and Control Register TSC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T1SC_PS0            equ       0                   ; Prescaler Select Bit
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
T1CNT               equ       $0000000C           ;*** T1CNT - TIM1 Counter Register

;*** T1CNTH - TIM1 Counter Register High
T1CNTH              equ       $0000000C           ;*** T1CNTH - TIM1 Counter Register High

;*** T1CNTL - TIM1 Counter Register Low
T1CNTL              equ       $0000000D           ;*** T1CNTL - TIM1 Counter Register Low

;*** T1MOD - TIM1 Counter Modulo Register
T1MOD               equ       $0000000E           ;*** T1MOD - TIM1 Counter Modulo Register

;*** T1MODH - TIM1 Counter Modulo Register High
T1MODH              equ       $0000000E           ;*** T1MODH - TIM1 Counter Modulo Register High

;*** T1MODL - TIM1 Counter Modulo Register Low
T1MODL              equ       $0000000F           ;*** T1MODL - TIM1 Counter Modulo Register Low

;*** T1SC0 - TIM1 Channel 0 Status and Control Register
T1SC0               equ       $00000010           ;*** T1SC0 - TIM1 Channel 0 Status and Control Register
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
T1CH0               equ       $00000011           ;*** T1CH0 - TIM1 Channel 0 Register

;*** T1CH0H - TIM1 Channel 0 Register High
T1CH0H              equ       $00000011           ;*** T1CH0H - TIM1 Channel 0 Register High

;*** T1CH0L - TIM1 Channel 0 Register Low
T1CH0L              equ       $00000012           ;*** T1CH0L - TIM1 Channel 0 Register Low

;*** T1SC1 - TIM1 Channel 1 Status and Control Register
T1SC1               equ       $00000013           ;*** T1SC1 - TIM1 Channel 1 Status and Control Register
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
T1CH1               equ       $00000014           ;*** T1CH1 - TIM1 Channel 1 Register

;*** T1CH1H - TIM1 Channel 1 Register High
T1CH1H              equ       $00000014           ;*** T1CH1H - TIM1 Channel 1 Register High

;*** T1CH1L - TIM1 Channel 1 Register Low
T1CH1L              equ       $00000015           ;*** T1CH1L - TIM1 Channel 1 Register Low

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

;*** TBCR - Timebase Control Register
TBCR                equ       $00000018           ;*** TBCR - Timebase Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBCR_TBON           equ       1                   ; Timebase Enabled
TBCR_TBIE           equ       2                   ; Timebase Interrupt Enable
TBCR_TACK           equ       3                   ; Timebase ACKnowledge
TBCR_TBR0           equ       4                   ; Timebase Rate Selection Bit 0
TBCR_TBR1           equ       5                   ; Timebase Rate Selection Bit 1
TBCR_TBR2           equ       6                   ; Timebase Rate Selection Bit 2
TBCR_TBIF           equ       7                   ; Timebase Interrupt Flag
; bit position masks
mTBCR_TBON          equ       %00000010
mTBCR_TBIE          equ       %00000100
mTBCR_TACK          equ       %00001000
mTBCR_TBR0          equ       %00010000
mTBCR_TBR1          equ       %00100000
mTBCR_TBR2          equ       %01000000
mTBCR_TBIF          equ       %10000000

;*** PS2CSR - I/O Control Register
PS2CSR              equ       $00000019           ;*** PS2CSR - I/O Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PS2CSR_PS2EN        equ       0                   ; PS2 Clock Generator Module Enable
PS2CSR_CLKEN        equ       1                   ; Clock Output Enable bit
PS2CSR_PS2IEN       equ       2                   ; PS2 Interrupt Mask
PS2CSR_CSEL0        equ       3                   ; Clock Frequency Selection bit 0
PS2CSR_CSEL1        equ       4                   ; Clock Frequency Selection bit 1
PS2CSR_PRE          equ       5                   ; Prescalar Selection
PS2CSR_PS2IF        equ       6                   ; PS2 Interrupt Flag
PS2CSR_PSTATUS      equ       7                   ; Port Status Flag
; bit position masks
mPS2CSR_PS2EN       equ       %00000001
mPS2CSR_CLKEN       equ       %00000010
mPS2CSR_PS2IEN      equ       %00000100
mPS2CSR_CSEL0       equ       %00001000
mPS2CSR_CSEL1       equ       %00010000
mPS2CSR_PRE         equ       %00100000
mPS2CSR_PS2IF       equ       %01000000
mPS2CSR_PSTATUS     equ       %10000000

;*** POCR1 - Port Option Control Register 1
POCR1               equ       $0000001A           ;*** POCR1 - Port Option Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
POCR1_LEDB0         equ       0                   ; Port B LED Drive Enable Bit 0
POCR1_LEDB1         equ       1                   ; Port B LED Drive Enable Bit 1
POCR1_LEDB2         equ       2                   ; Port B LED Drive Enable Bit 2
POCR1_LEDB3         equ       3                   ; Port B LED Drive Enable Bit 3
POCR1_LEDB4         equ       4                   ; Port B LED Drive Enable Bit 4
POCR1_LEDB5         equ       5                   ; Port B LED Drive Enable Bit 5
POCR1_LEDB6         equ       6                   ; Port B LED Drive Enable Bit 6
POCR1_LEDB7         equ       7                   ; Port B LED Drive Enable Bit 7
; bit position masks
mPOCR1_LEDB0        equ       %00000001
mPOCR1_LEDB1        equ       %00000010
mPOCR1_LEDB2        equ       %00000100
mPOCR1_LEDB3        equ       %00001000
mPOCR1_LEDB4        equ       %00010000
mPOCR1_LEDB5        equ       %00100000
mPOCR1_LEDB6        equ       %01000000
mPOCR1_LEDB7        equ       %10000000

;*** POCR2 - Port Option Control Register 2
POCR2               equ       $0000001B           ;*** POCR2 - Port Option Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
POCR2_PTE2P         equ       0                   ; Pin PTE2 Pullup Enable
POCR2_PTE3P         equ       1                   ; Pin PTE3 Pullup Enable
POCR2_DPPULLEN      equ       2                   ; D+ Pullup Enable
POCR2_PTD2PD        equ       3                   ; Pin PTD2 Pullup Disable
POCR2_PTD3PD        equ       4                   ; Pin PTD3 Pullup Disable
POCR2_PTD7PD        equ       5                   ; Pin PTD7 Pullup Disable
; bit position masks
mPOCR2_PTE2P        equ       %00000001
mPOCR2_PTE3P        equ       %00000010
mPOCR2_DPPULLEN     equ       %00000100
mPOCR2_PTD2PD       equ       %00001000
mPOCR2_PTD3PD       equ       %00010000
mPOCR2_PTD7PD       equ       %00100000

;*** IOCR - IRQ Option Register
IOCR                equ       $0000001C           ;*** IOCR - IRQ Option Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IOCR_IRQPD          equ       0                   ; IRQ Pullup Disable
IOCR_PTE3IE         equ       1                   ; PTE3 Interrupt Enable
IOCR_PTE3IF         equ       2                   ; PTE3 Interrupt Flag
; bit position masks
mIOCR_IRQPD         equ       %00000001
mIOCR_PTE3IE        equ       %00000010
mIOCR_PTE3IF        equ       %00000100

;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001D           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_URSTD       equ       0                   ; USB Reset Disable Bit
CONFIG2_VREG33D     equ       1                   ; 3.3V USB Regulator Disable Bit
CONFIG2_CLKS        equ       2                   ; Clock source selection Bit
CONFIG2_STOP_RCCLKEN equ       4                   ; RC clock Stop Mode Enable
CONFIG2_STOP_XCLKEN equ       5                   ; Crystal Oscillator Stop Mode Enable
CONFIG2_STOPEN      equ       6                   ; STOP pin output enable
; bit position masks
mCONFIG2_URSTD      equ       %00000001
mCONFIG2_VREG33D    equ       %00000010
mCONFIG2_CLKS       equ       %00000100
mCONFIG2_STOP_RCCLKEN equ       %00010000
mCONFIG2_STOP_XCLKEN equ       %00100000
mCONFIG2_STOPEN     equ       %01000000

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

;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVIPWRD     equ       4                   ; LVI Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; LVI Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP rate Select Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVIPWRD    equ       %00010000
mCONFIG1_LVIRSTD    equ       %00100000
mCONFIG1_LVISTOP    equ       %01000000
mCONFIG1_COPRS      equ       %10000000

;*** DC1CR - Data Codec 1 Control Register
DC1CR               equ       $00000020           ;*** DC1CR - Data Codec 1 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1CR_RSTTRG0       equ       0                   ; Reset trigger Selection Bit 0
DC1CR_RSTTRG1       equ       1                   ; Reset trigger Selection Bit 1
DC1CR_MODE          equ       2                   ; Mode selection bit
DC1CR_INITLOG       equ       3                   ; Initial Logic Definition bit
DC1CR_PSTART        equ       4                   ; Pulse Generation Enable bit
DC1CR_FLUSH         equ       5                   ; Data Flush bit
DC1CR_MILLEREN      equ       6                   ; Miller Encoder/Decoder Enable bit
DC1CR_DCMEN         equ       7                   ; Data Codec Enable bit
; bit position masks
mDC1CR_RSTTRG0      equ       %00000001
mDC1CR_RSTTRG1      equ       %00000010
mDC1CR_MODE         equ       %00000100
mDC1CR_INITLOG      equ       %00001000
mDC1CR_PSTART       equ       %00010000
mDC1CR_FLUSH        equ       %00100000
mDC1CR_MILLEREN     equ       %01000000
mDC1CR_DCMEN        equ       %10000000

;*** DC1SCR1 - Data Codec 1 Status & Control Register 1
DC1SCR1             equ       $00000021           ;*** DC1SCR1 - Data Codec 1 Status & Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1SCR1_DWNLD       equ       0                   ; 64 bit data buffer download enable
DC1SCR1_RISEFALL    equ       1                   ; RISE/FALL Selection bit
DC1SCR1_CONT        equ       2                   ; Continuous Decoding Enable bit
DC1SCR1_ERRIEN      equ       3                   ; Error interrupt enable bit
DC1SCR1__8OVF       equ       4                   ; 8 Bit Free running counter overflow flag
DC1SCR1_RBF         equ       5                   ; Receive buffer full flag
DC1SCR1_CARRIER     equ       6                   ; Carrier flag
DC1SCR1_VIOLATE     equ       7                   ; Miller format violation flag
; bit position masks
mDC1SCR1_DWNLD      equ       %00000001
mDC1SCR1_RISEFALL   equ       %00000010
mDC1SCR1_CONT       equ       %00000100
mDC1SCR1_ERRIEN     equ       %00001000
mDC1SCR1__8OVF      equ       %00010000
mDC1SCR1_RBF        equ       %00100000
mDC1SCR1_CARRIER    equ       %01000000
mDC1SCR1_VIOLATE    equ       %10000000

;*** DC1SR2 - Data Codec 1 StatusRegister 2
DC1SR2              equ       $00000022           ;*** DC1SR2 - Data Codec 1 StatusRegister 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1SR2_CNT1DT       equ       0                   ; Comparator 1 match flag
DC1SR2_CNT2DT       equ       1                   ; Comparator 2 match flag
DC1SR2_CNT3DT       equ       2                   ; Comparator 3 match flag
DC1SR2_CNT4DT       equ       3                   ; Comparator 4 match flag
DC1SR2_RSTDT        equ       4                   ; 8 bit Free running counter Reset flag
DC1SR2_LAST         equ       5                   ; LAST bit indicator Flag
DC1SR2_EDGE         equ       6                   ; Edge detection Flag
DC1SR2_RISE         equ       7                   ; Rising Edge detection Flag
; bit position masks
mDC1SR2_CNT1DT      equ       %00000001
mDC1SR2_CNT2DT      equ       %00000010
mDC1SR2_CNT3DT      equ       %00000100
mDC1SR2_CNT4DT      equ       %00001000
mDC1SR2_RSTDT       equ       %00010000
mDC1SR2_LAST        equ       %00100000
mDC1SR2_EDGE        equ       %01000000
mDC1SR2_RISE        equ       %10000000

;*** DC1ICR - Data Codec 1 Interrupt Control Register
DC1ICR              equ       $00000023           ;*** DC1ICR - Data Codec 1 Interrupt Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1ICR_CNT1IEN      equ       0                   ; CNT1DT Interrupt Enable bit
DC1ICR_CNT2IEN      equ       1                   ; CNT2DT Interrupt Enable bit
DC1ICR_CNT3IEN      equ       2                   ; CNT3DT Interrupt Enable bit
DC1ICR_CNT4IEN      equ       3                   ; CNT4DT Interrupt Enable bit
DC1ICR_RSTIEN       equ       4                   ; RSTDT Interrupt Enable bit
DC1ICR_LASTIEN      equ       5                   ; LAST Interrupt Enable bit
DC1ICR_EDGEIEN      equ       6                   ; EDGE Interrupt Enable bit
DC1ICR_OVF_SEL      equ       7                   ; Counter overflow selection bit
; bit position masks
mDC1ICR_CNT1IEN     equ       %00000001
mDC1ICR_CNT2IEN     equ       %00000010
mDC1ICR_CNT3IEN     equ       %00000100
mDC1ICR_CNT4IEN     equ       %00001000
mDC1ICR_RSTIEN      equ       %00010000
mDC1ICR_LASTIEN     equ       %00100000
mDC1ICR_EDGEIEN     equ       %01000000
mDC1ICR_OVF_SEL     equ       %10000000

;*** DC1CNT - Data Codec 1 Counter Register
DC1CNT              equ       $00000024           ;*** DC1CNT - Data Codec 1 Counter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1CNT_CNT0         equ       0                   ; Data Codec 1 Counter Bit 0
DC1CNT_CNT1         equ       1                   ; Data Codec 1 Counter Bit 1
DC1CNT_CNT2         equ       2                   ; Data Codec 1 Counter Bit 2
DC1CNT_CNT3         equ       3                   ; Data Codec 1 Counter Bit 3
DC1CNT_CNT4         equ       4                   ; Data Codec 1 Counter Bit 4
DC1CNT_CNT5         equ       5                   ; Data Codec 1 Counter Bit 5
DC1CNT_CNT6         equ       6                   ; Data Codec 1 Counter Bit 6
DC1CNT_CNT7         equ       7                   ; Data Codec 1 Counter Bit 7
; bit position masks
mDC1CNT_CNT0        equ       %00000001
mDC1CNT_CNT1        equ       %00000010
mDC1CNT_CNT2        equ       %00000100
mDC1CNT_CNT3        equ       %00001000
mDC1CNT_CNT4        equ       %00010000
mDC1CNT_CNT5        equ       %00100000
mDC1CNT_CNT6        equ       %01000000
mDC1CNT_CNT7        equ       %10000000

;*** DC1CCNT - Data Codec 1 Compensated Counter Register
DC1CCNT             equ       $00000025           ;*** DC1CCNT - Data Codec 1 Compensated Counter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1CCNT_CCNT0       equ       0                   ; Compensated Captured Counter Value Bit 0
DC1CCNT_CCNT1       equ       1                   ; Compensated Captured Counter Value Bit 1
DC1CCNT_CCNT2       equ       2                   ; Compensated Captured Counter Value Bit 2
DC1CCNT_CCNT3       equ       3                   ; Compensated Captured Counter Value Bit 3
DC1CCNT_CCNT4       equ       4                   ; Compensated Captured Counter Value Bit 4
DC1CCNT_CCNT5       equ       5                   ; Compensated Captured Counter Value Bit 5
DC1CCNT_CCNT6       equ       6                   ; Compensated Captured Counter Value Bit 6
DC1CCNT_CCNT7       equ       7                   ; Compensated Captured Counter Value Bit 7
; bit position masks
mDC1CCNT_CCNT0      equ       %00000001
mDC1CCNT_CCNT1      equ       %00000010
mDC1CCNT_CCNT2      equ       %00000100
mDC1CCNT_CCNT3      equ       %00001000
mDC1CCNT_CCNT4      equ       %00010000
mDC1CCNT_CCNT5      equ       %00100000
mDC1CCNT_CCNT6      equ       %01000000
mDC1CCNT_CCNT7      equ       %10000000

;*** DC1VAL1 - Data Codec 1 Comparator 1 Register
DC1VAL1             equ       $00000026           ;*** DC1VAL1 - Data Codec 1 Comparator 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1VAL1_CVALUE10    equ       0                   ; Data Codec 1 Comparator 1 Bit 0
DC1VAL1_CVALUE11    equ       1                   ; Data Codec 1 Comparator 1 Bit 1
DC1VAL1_CVALUE12    equ       2                   ; Data Codec 1 Comparator 1 Bit 2
DC1VAL1_CVALUE13    equ       3                   ; Data Codec 1 Comparator 1 Bit 3
DC1VAL1_CVALUE14    equ       4                   ; Data Codec 1 Comparator 1 Bit 4
DC1VAL1_CVALUE15    equ       5                   ; Data Codec 1 Comparator 1 Bit 5
DC1VAL1_CVALUE16    equ       6                   ; Data Codec 1 Comparator 1 Bit 6
DC1VAL1_CVALUE17    equ       7                   ; Data Codec 1 Comparator 1 Bit 7
; bit position masks
mDC1VAL1_CVALUE10   equ       %00000001
mDC1VAL1_CVALUE11   equ       %00000010
mDC1VAL1_CVALUE12   equ       %00000100
mDC1VAL1_CVALUE13   equ       %00001000
mDC1VAL1_CVALUE14   equ       %00010000
mDC1VAL1_CVALUE15   equ       %00100000
mDC1VAL1_CVALUE16   equ       %01000000
mDC1VAL1_CVALUE17   equ       %10000000

;*** DC1VAL2 - Data Codec 1 Comparator 2 Register
DC1VAL2             equ       $00000027           ;*** DC1VAL2 - Data Codec 1 Comparator 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1VAL2_CVALUE20    equ       0                   ; Data Codec 1 Comparator 2 Bit 0
DC1VAL2_CVALUE21    equ       1                   ; Data Codec 1 Comparator 2 Bit 1
DC1VAL2_CVALUE22    equ       2                   ; Data Codec 1 Comparator 2 Bit 2
DC1VAL2_CVALUE23    equ       3                   ; Data Codec 1 Comparator 2 Bit 3
DC1VAL2_CVALUE24    equ       4                   ; Data Codec 1 Comparator 2 Bit 4
DC1VAL2_CVALUE25    equ       5                   ; Data Codec 1 Comparator 2 Bit 5
DC1VAL2_CVALUE26    equ       6                   ; Data Codec 1 Comparator 2 Bit 6
DC1VAL2_CVALUE27    equ       7                   ; Data Codec 1 Comparator 2 Bit 7
; bit position masks
mDC1VAL2_CVALUE20   equ       %00000001
mDC1VAL2_CVALUE21   equ       %00000010
mDC1VAL2_CVALUE22   equ       %00000100
mDC1VAL2_CVALUE23   equ       %00001000
mDC1VAL2_CVALUE24   equ       %00010000
mDC1VAL2_CVALUE25   equ       %00100000
mDC1VAL2_CVALUE26   equ       %01000000
mDC1VAL2_CVALUE27   equ       %10000000

;*** DC1VAL3 - Data Codec 1 Comparator 3 Register
DC1VAL3             equ       $00000028           ;*** DC1VAL3 - Data Codec 1 Comparator 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1VAL3_CVALUE30    equ       0                   ; Data Codec 1 Comparator 3 Bit 0
DC1VAL3_CVALUE31    equ       1                   ; Data Codec 1 Comparator 3 Bit 1
DC1VAL3_CVALUE32    equ       2                   ; Data Codec 1 Comparator 3 Bit 2
DC1VAL3_CVALUE33    equ       3                   ; Data Codec 1 Comparator 3 Bit 3
DC1VAL3_CVALUE34    equ       4                   ; Data Codec 1 Comparator 3 Bit 4
DC1VAL3_CVALUE35    equ       5                   ; Data Codec 1 Comparator 3 Bit 5
DC1VAL3_CVALUE36    equ       6                   ; Data Codec 1 Comparator 3 Bit 6
DC1VAL3_CVALUE37    equ       7                   ; Data Codec 1 Comparator 3 Bit 7
; bit position masks
mDC1VAL3_CVALUE30   equ       %00000001
mDC1VAL3_CVALUE31   equ       %00000010
mDC1VAL3_CVALUE32   equ       %00000100
mDC1VAL3_CVALUE33   equ       %00001000
mDC1VAL3_CVALUE34   equ       %00010000
mDC1VAL3_CVALUE35   equ       %00100000
mDC1VAL3_CVALUE36   equ       %01000000
mDC1VAL3_CVALUE37   equ       %10000000

;*** DC1VAL4 - Data Codec 1 Comparator 4 Register
DC1VAL4             equ       $00000029           ;*** DC1VAL4 - Data Codec 1 Comparator 4 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1VAL4_CVALUE40    equ       0                   ; Data Codec 1 Comparator 4 Bit 0
DC1VAL4_CVALUE41    equ       1                   ; Data Codec 1 Comparator 4 Bit 1
DC1VAL4_CVALUE42    equ       2                   ; Data Codec 1 Comparator 4 Bit 2
DC1VAL4_CVALUE43    equ       3                   ; Data Codec 1 Comparator 4 Bit 3
DC1VAL4_CVALUE44    equ       4                   ; Data Codec 1 Comparator 4 Bit 4
DC1VAL4_CVALUE45    equ       5                   ; Data Codec 1 Comparator 4 Bit 5
DC1VAL4_CVALUE46    equ       6                   ; Data Codec 1 Comparator 4 Bit 6
DC1VAL4_CVALUE47    equ       7                   ; Data Codec 1 Comparator 4 Bit 7
; bit position masks
mDC1VAL4_CVALUE40   equ       %00000001
mDC1VAL4_CVALUE41   equ       %00000010
mDC1VAL4_CVALUE42   equ       %00000100
mDC1VAL4_CVALUE43   equ       %00001000
mDC1VAL4_CVALUE44   equ       %00010000
mDC1VAL4_CVALUE45   equ       %00100000
mDC1VAL4_CVALUE46   equ       %01000000
mDC1VAL4_CVALUE47   equ       %10000000

;*** DC1TOL - Data Codec 1 Tolerance Register
DC1TOL              equ       $0000002A           ;*** DC1TOL - Data Codec 1 Tolerance Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1TOL_TOL0         equ       0                   ; Tolerance value Bit 0
DC1TOL_TOL1         equ       1                   ; Tolerance value Bit 1
DC1TOL_TOL2         equ       2                   ; Tolerance value Bit 2
DC1TOL_TOL3         equ       3                   ; Tolerance value Bit 3
DC1TOL_TOL4         equ       4                   ; Tolerance value Bit 4
DC1TOL_ADD          equ       7                   ; Add operation Selection bit
; bit position masks
mDC1TOL_TOL0        equ       %00000001
mDC1TOL_TOL1        equ       %00000010
mDC1TOL_TOL2        equ       %00000100
mDC1TOL_TOL3        equ       %00001000
mDC1TOL_TOL4        equ       %00010000
mDC1TOL_ADD         equ       %10000000

;*** DC1BAUD - Data Codec 1 Baud Selection Register
DC1BAUD             equ       $0000002B           ;*** DC1BAUD - Data Codec 1 Baud Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1BAUD_DCMR0       equ       0                   ; Second Divider Selection Bit 0
DC1BAUD_DCMR1       equ       1                   ; Second Divider Selection Bit 1
DC1BAUD_DCMR2       equ       2                   ; Second Divider Selection Bit 2
DC1BAUD_DCMP0       equ       4                   ; First Divider Selection bit
DC1BAUD_DCMC        equ       6                   ; Divider clock option Selection bit
; bit position masks
mDC1BAUD_DCMR0      equ       %00000001
mDC1BAUD_DCMR1      equ       %00000010
mDC1BAUD_DCMR2      equ       %00000100
mDC1BAUD_DCMP0      equ       %00010000
mDC1BAUD_DCMC       equ       %01000000

;*** DC1DCNT - Data Codec 1 Data Count Register
DC1DCNT             equ       $0000002C           ;*** DC1DCNT - Data Codec 1 Data Count Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1DCNT_DATCNT0     equ       0                   ; Data Counter Bit 0
DC1DCNT_DATCNT1     equ       1                   ; Data Counter Bit 1
DC1DCNT_DATCNT2     equ       2                   ; Data Counter Bit 2
DC1DCNT_DATCNT3     equ       3                   ; Data Counter Bit 3
DC1DCNT_DATCNT4     equ       4                   ; Data Counter Bit 4
DC1DCNT_DATCNT5     equ       5                   ; Data Counter Bit 5
DC1DCNT_DATCNT6     equ       6                   ; Data Counter Bit 6
; bit position masks
mDC1DCNT_DATCNT0    equ       %00000001
mDC1DCNT_DATCNT1    equ       %00000010
mDC1DCNT_DATCNT2    equ       %00000100
mDC1DCNT_DATCNT3    equ       %00001000
mDC1DCNT_DATCNT4    equ       %00010000
mDC1DCNT_DATCNT5    equ       %00100000
mDC1DCNT_DATCNT6    equ       %01000000

;*** DC1PAGE - Data Codec 1 Page Register
DC1PAGE             equ       $0000002D           ;*** DC1PAGE - Data Codec 1 Page Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1PAGE_PAGE0       equ       0                   ; Page Selection Bit 0
DC1PAGE_PAGE1       equ       1                   ; Page Selection Bit 1
DC1PAGE_PAGE2       equ       2                   ; Page Selection Bit 2
; bit position masks
mDC1PAGE_PAGE0      equ       %00000001
mDC1PAGE_PAGE1      equ       %00000010
mDC1PAGE_PAGE2      equ       %00000100

;*** DC1DAT - Data Codec 1 Data Register
DC1DAT              equ       $0000002E           ;*** DC1DAT - Data Codec 1 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC1DAT_DAT0         equ       0                   ; 8 bit Data Window Bit 0
DC1DAT_DAT1         equ       1                   ; 8 bit Data Window Bit 1
DC1DAT_DAT2         equ       2                   ; 8 bit Data Window Bit 2
DC1DAT_DAT3         equ       3                   ; 8 bit Data Window Bit 3
DC1DAT_DAT4         equ       4                   ; 8 bit Data Window Bit 4
DC1DAT_DAT5         equ       5                   ; 8 bit Data Window Bit 5
DC1DAT_DAT6         equ       6                   ; 8 bit Data Window Bit 6
DC1DAT_DAT7         equ       7                   ; 8 bit Data Window Bit 7
; bit position masks
mDC1DAT_DAT0        equ       %00000001
mDC1DAT_DAT1        equ       %00000010
mDC1DAT_DAT2        equ       %00000100
mDC1DAT_DAT3        equ       %00001000
mDC1DAT_DAT4        equ       %00010000
mDC1DAT_DAT5        equ       %00100000
mDC1DAT_DAT6        equ       %01000000
mDC1DAT_DAT7        equ       %10000000

;*** DC2CR - Data Codec 2 Control Register
DC2CR               equ       $0000002F           ;*** DC2CR - Data Codec 2 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2CR_RSTTRG0       equ       0                   ; Reset trigger Selection Bit 0
DC2CR_RSTTRG1       equ       1                   ; Reset trigger Selection Bit 1
DC2CR_MODE          equ       2                   ; Mode selection bit
DC2CR_INITLOG       equ       3                   ; Initial Logic Definition bit
DC2CR_PSTART        equ       4                   ; Pulse Generation Enable bit
DC2CR_FLUSH         equ       5                   ; Data Flush bit
DC2CR_MILLEREN      equ       6                   ; Miller Encoder/Decoder Enable bit
DC2CR_DCMEN         equ       7                   ; Data Codec Enable bit
; bit position masks
mDC2CR_RSTTRG0      equ       %00000001
mDC2CR_RSTTRG1      equ       %00000010
mDC2CR_MODE         equ       %00000100
mDC2CR_INITLOG      equ       %00001000
mDC2CR_PSTART       equ       %00010000
mDC2CR_FLUSH        equ       %00100000
mDC2CR_MILLEREN     equ       %01000000
mDC2CR_DCMEN        equ       %10000000

;*** DC2SCR1 - Data Codec 2 Status & Control Register 1
DC2SCR1             equ       $00000030           ;*** DC2SCR1 - Data Codec 2 Status & Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2SCR1_DWNLD       equ       0                   ; 64 bit data buffer download enable
DC2SCR1_RISEFALL    equ       1                   ; RISE/FALL Selection bit
DC2SCR1_CONT        equ       2                   ; Continuous Decoding Enable bit
DC2SCR1_ERRIEN      equ       3                   ; Error interrupt enable bit
DC2SCR1__8OVF       equ       4                   ; 8 Bit Free running counter overflow flag
DC2SCR1_RBF         equ       5                   ; Receive buffer full flag
DC2SCR1_CARRIER     equ       6                   ; Carrier flag
DC2SCR1_VIOLATE     equ       7                   ; Miller format violation flag
; bit position masks
mDC2SCR1_DWNLD      equ       %00000001
mDC2SCR1_RISEFALL   equ       %00000010
mDC2SCR1_CONT       equ       %00000100
mDC2SCR1_ERRIEN     equ       %00001000
mDC2SCR1__8OVF      equ       %00010000
mDC2SCR1_RBF        equ       %00100000
mDC2SCR1_CARRIER    equ       %01000000
mDC2SCR1_VIOLATE    equ       %10000000

;*** DC2SR2 - Data Codec 2 StatusRegister 2
DC2SR2              equ       $00000031           ;*** DC2SR2 - Data Codec 2 StatusRegister 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2SR2_CNT1DT       equ       0                   ; Comparator 1 match flag
DC2SR2_CNT2DT       equ       1                   ; Comparator 2 match flag
DC2SR2_CNT3DT       equ       2                   ; Comparator 3 match flag
DC2SR2_CNT4DT       equ       3                   ; Comparator 4 match flag
DC2SR2_RSTDT        equ       4                   ; 8 bit Free running counter Reset flag
DC2SR2_LAST         equ       5                   ; LAST bit indicator Flag
DC2SR2_EDGE         equ       6                   ; Edge detection Flag
DC2SR2_RISE         equ       7                   ; Rising Edge detection Flag
; bit position masks
mDC2SR2_CNT1DT      equ       %00000001
mDC2SR2_CNT2DT      equ       %00000010
mDC2SR2_CNT3DT      equ       %00000100
mDC2SR2_CNT4DT      equ       %00001000
mDC2SR2_RSTDT       equ       %00010000
mDC2SR2_LAST        equ       %00100000
mDC2SR2_EDGE        equ       %01000000
mDC2SR2_RISE        equ       %10000000

;*** DC2ICR - Data Codec 2 Interrupt Control Register
DC2ICR              equ       $00000032           ;*** DC2ICR - Data Codec 2 Interrupt Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2ICR_CNT1IEN      equ       0                   ; CNT1DT Interrupt Enable bit
DC2ICR_CNT2IEN      equ       1                   ; CNT2DT Interrupt Enable bit
DC2ICR_CNT3IEN      equ       2                   ; CNT3DT Interrupt Enable bit
DC2ICR_CNT4IEN      equ       3                   ; CNT4DT Interrupt Enable bit
DC2ICR_RSTIEN       equ       4                   ; RSTDT Interrupt Enable bit
DC2ICR_LASTIEN      equ       5                   ; LAST Interrupt Enable bit
DC2ICR_EDGEIEN      equ       6                   ; EDGE Interrupt Enable bit
DC2ICR_OVF_SEL      equ       7                   ; Counter overflow selection bit
; bit position masks
mDC2ICR_CNT1IEN     equ       %00000001
mDC2ICR_CNT2IEN     equ       %00000010
mDC2ICR_CNT3IEN     equ       %00000100
mDC2ICR_CNT4IEN     equ       %00001000
mDC2ICR_RSTIEN      equ       %00010000
mDC2ICR_LASTIEN     equ       %00100000
mDC2ICR_EDGEIEN     equ       %01000000
mDC2ICR_OVF_SEL     equ       %10000000

;*** DC2CNT - Data Codec 2 Counter Register
DC2CNT              equ       $00000033           ;*** DC2CNT - Data Codec 2 Counter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2CNT_CNT0         equ       0                   ; Data Codec 2 Counter Bit 0
DC2CNT_CNT1         equ       1                   ; Data Codec 2 Counter Bit 1
DC2CNT_CNT2         equ       2                   ; Data Codec 2 Counter Bit 2
DC2CNT_CNT3         equ       3                   ; Data Codec 2 Counter Bit 3
DC2CNT_CNT4         equ       4                   ; Data Codec 2 Counter Bit 4
DC2CNT_CNT5         equ       5                   ; Data Codec 2 Counter Bit 5
DC2CNT_CNT6         equ       6                   ; Data Codec 2 Counter Bit 6
DC2CNT_CNT7         equ       7                   ; Data Codec 2 Counter Bit 7
; bit position masks
mDC2CNT_CNT0        equ       %00000001
mDC2CNT_CNT1        equ       %00000010
mDC2CNT_CNT2        equ       %00000100
mDC2CNT_CNT3        equ       %00001000
mDC2CNT_CNT4        equ       %00010000
mDC2CNT_CNT5        equ       %00100000
mDC2CNT_CNT6        equ       %01000000
mDC2CNT_CNT7        equ       %10000000

;*** DC2CCNT - Data Codec 2 Compensated Counter Register
DC2CCNT             equ       $00000034           ;*** DC2CCNT - Data Codec 2 Compensated Counter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2CCNT_CCNT0       equ       0                   ; Compensated Captured Counter Value Bit 0
DC2CCNT_CCNT1       equ       1                   ; Compensated Captured Counter Value Bit 1
DC2CCNT_CCNT2       equ       2                   ; Compensated Captured Counter Value Bit 2
DC2CCNT_CCNT3       equ       3                   ; Compensated Captured Counter Value Bit 3
DC2CCNT_CCNT4       equ       4                   ; Compensated Captured Counter Value Bit 4
DC2CCNT_CCNT5       equ       5                   ; Compensated Captured Counter Value Bit 5
DC2CCNT_CCNT6       equ       6                   ; Compensated Captured Counter Value Bit 6
DC2CCNT_CCNT7       equ       7                   ; Compensated Captured Counter Value Bit 7
; bit position masks
mDC2CCNT_CCNT0      equ       %00000001
mDC2CCNT_CCNT1      equ       %00000010
mDC2CCNT_CCNT2      equ       %00000100
mDC2CCNT_CCNT3      equ       %00001000
mDC2CCNT_CCNT4      equ       %00010000
mDC2CCNT_CCNT5      equ       %00100000
mDC2CCNT_CCNT6      equ       %01000000
mDC2CCNT_CCNT7      equ       %10000000

;*** DC2VAL1 - Data Codec 2 Comparator 1 Register
DC2VAL1             equ       $00000035           ;*** DC2VAL1 - Data Codec 2 Comparator 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2VAL1_CVALUE10    equ       0                   ; Data Codec 2 Comparator 1 Bit 0
DC2VAL1_CVALUE11    equ       1                   ; Data Codec 2 Comparator 1 Bit 1
DC2VAL1_CVALUE12    equ       2                   ; Data Codec 2 Comparator 1 Bit 2
DC2VAL1_CVALUE13    equ       3                   ; Data Codec 2 Comparator 1 Bit 3
DC2VAL1_CVALUE14    equ       4                   ; Data Codec 2 Comparator 1 Bit 4
DC2VAL1_CVALUE15    equ       5                   ; Data Codec 2 Comparator 1 Bit 5
DC2VAL1_CVALUE16    equ       6                   ; Data Codec 2 Comparator 1 Bit 6
DC2VAL1_CVALUE17    equ       7                   ; Data Codec 2 Comparator 1 Bit 7
; bit position masks
mDC2VAL1_CVALUE10   equ       %00000001
mDC2VAL1_CVALUE11   equ       %00000010
mDC2VAL1_CVALUE12   equ       %00000100
mDC2VAL1_CVALUE13   equ       %00001000
mDC2VAL1_CVALUE14   equ       %00010000
mDC2VAL1_CVALUE15   equ       %00100000
mDC2VAL1_CVALUE16   equ       %01000000
mDC2VAL1_CVALUE17   equ       %10000000

;*** DC2VAL2 - Data Codec 2 Comparator 2 Register
DC2VAL2             equ       $00000036           ;*** DC2VAL2 - Data Codec 2 Comparator 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2VAL2_CVALUE20    equ       0                   ; Data Codec 2 Comparator 2 Bit 0
DC2VAL2_CVALUE21    equ       1                   ; Data Codec 2 Comparator 2 Bit 1
DC2VAL2_CVALUE22    equ       2                   ; Data Codec 2 Comparator 2 Bit 2
DC2VAL2_CVALUE23    equ       3                   ; Data Codec 2 Comparator 2 Bit 3
DC2VAL2_CVALUE24    equ       4                   ; Data Codec 2 Comparator 2 Bit 4
DC2VAL2_CVALUE25    equ       5                   ; Data Codec 2 Comparator 2 Bit 5
DC2VAL2_CVALUE26    equ       6                   ; Data Codec 2 Comparator 2 Bit 6
DC2VAL2_CVALUE27    equ       7                   ; Data Codec 2 Comparator 2 Bit 7
; bit position masks
mDC2VAL2_CVALUE20   equ       %00000001
mDC2VAL2_CVALUE21   equ       %00000010
mDC2VAL2_CVALUE22   equ       %00000100
mDC2VAL2_CVALUE23   equ       %00001000
mDC2VAL2_CVALUE24   equ       %00010000
mDC2VAL2_CVALUE25   equ       %00100000
mDC2VAL2_CVALUE26   equ       %01000000
mDC2VAL2_CVALUE27   equ       %10000000

;*** DC2VAL3 - Data Codec 2 Comparator 3 Register
DC2VAL3             equ       $00000037           ;*** DC2VAL3 - Data Codec 2 Comparator 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2VAL3_CVALUE30    equ       0                   ; Data Codec 2 Comparator 3 Bit 0
DC2VAL3_CVALUE31    equ       1                   ; Data Codec 2 Comparator 3 Bit 1
DC2VAL3_CVALUE32    equ       2                   ; Data Codec 2 Comparator 3 Bit 2
DC2VAL3_CVALUE33    equ       3                   ; Data Codec 2 Comparator 3 Bit 3
DC2VAL3_CVALUE34    equ       4                   ; Data Codec 2 Comparator 3 Bit 4
DC2VAL3_CVALUE35    equ       5                   ; Data Codec 2 Comparator 3 Bit 5
DC2VAL3_CVALUE36    equ       6                   ; Data Codec 2 Comparator 3 Bit 6
DC2VAL3_CVALUE37    equ       7                   ; Data Codec 2 Comparator 3 Bit 7
; bit position masks
mDC2VAL3_CVALUE30   equ       %00000001
mDC2VAL3_CVALUE31   equ       %00000010
mDC2VAL3_CVALUE32   equ       %00000100
mDC2VAL3_CVALUE33   equ       %00001000
mDC2VAL3_CVALUE34   equ       %00010000
mDC2VAL3_CVALUE35   equ       %00100000
mDC2VAL3_CVALUE36   equ       %01000000
mDC2VAL3_CVALUE37   equ       %10000000

;*** DC2VAL4 - Data Codec 2 Comparator 4 Register
DC2VAL4             equ       $00000038           ;*** DC2VAL4 - Data Codec 2 Comparator 4 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2VAL4_CVALUE40    equ       0                   ; Data Codec 2 Comparator 4 Bit 0
DC2VAL4_CVALUE41    equ       1                   ; Data Codec 2 Comparator 4 Bit 1
DC2VAL4_CVALUE42    equ       2                   ; Data Codec 2 Comparator 4 Bit 2
DC2VAL4_CVALUE43    equ       3                   ; Data Codec 2 Comparator 4 Bit 3
DC2VAL4_CVALUE44    equ       4                   ; Data Codec 2 Comparator 4 Bit 4
DC2VAL4_CVALUE45    equ       5                   ; Data Codec 2 Comparator 4 Bit 5
DC2VAL4_CVALUE46    equ       6                   ; Data Codec 2 Comparator 4 Bit 6
DC2VAL4_CVALUE47    equ       7                   ; Data Codec 2 Comparator 4 Bit 7
; bit position masks
mDC2VAL4_CVALUE40   equ       %00000001
mDC2VAL4_CVALUE41   equ       %00000010
mDC2VAL4_CVALUE42   equ       %00000100
mDC2VAL4_CVALUE43   equ       %00001000
mDC2VAL4_CVALUE44   equ       %00010000
mDC2VAL4_CVALUE45   equ       %00100000
mDC2VAL4_CVALUE46   equ       %01000000
mDC2VAL4_CVALUE47   equ       %10000000

;*** DC2TOL - Data Codec 2 Tolerance Register
DC2TOL              equ       $00000039           ;*** DC2TOL - Data Codec 2 Tolerance Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2TOL_TOL0         equ       0                   ; Tolerance value Bit 0
DC2TOL_TOL1         equ       1                   ; Tolerance value Bit 1
DC2TOL_TOL2         equ       2                   ; Tolerance value Bit 2
DC2TOL_TOL3         equ       3                   ; Tolerance value Bit 3
DC2TOL_TOL4         equ       4                   ; Tolerance value Bit 4
DC2TOL_ADD          equ       7                   ; Add operation Selection bit
; bit position masks
mDC2TOL_TOL0        equ       %00000001
mDC2TOL_TOL1        equ       %00000010
mDC2TOL_TOL2        equ       %00000100
mDC2TOL_TOL3        equ       %00001000
mDC2TOL_TOL4        equ       %00010000
mDC2TOL_ADD         equ       %10000000

;*** DC2BAUD - Data Codec 2 Baud Selection Register
DC2BAUD             equ       $0000003A           ;*** DC2BAUD - Data Codec 2 Baud Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2BAUD_DCMR0       equ       0                   ; Second Divider Selection Bit 0
DC2BAUD_DCMR1       equ       1                   ; Second Divider Selection Bit 1
DC2BAUD_DCMR2       equ       2                   ; Second Divider Selection Bit 2
DC2BAUD_DCMP0       equ       4                   ; First Divider Selection bit
DC2BAUD_DCMC        equ       6                   ; Divider clock option Selection bit
; bit position masks
mDC2BAUD_DCMR0      equ       %00000001
mDC2BAUD_DCMR1      equ       %00000010
mDC2BAUD_DCMR2      equ       %00000100
mDC2BAUD_DCMP0      equ       %00010000
mDC2BAUD_DCMC       equ       %01000000

;*** DC2DCNT - Data Codec 2 Data Count Register
DC2DCNT             equ       $0000003B           ;*** DC2DCNT - Data Codec 2 Data Count Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2DCNT_DATCNT0     equ       0                   ; Data Counter Bit 0
DC2DCNT_DATCNT1     equ       1                   ; Data Counter Bit 1
DC2DCNT_DATCNT2     equ       2                   ; Data Counter Bit 2
DC2DCNT_DATCNT3     equ       3                   ; Data Counter Bit 3
DC2DCNT_DATCNT4     equ       4                   ; Data Counter Bit 4
DC2DCNT_DATCNT5     equ       5                   ; Data Counter Bit 5
DC2DCNT_DATCNT6     equ       6                   ; Data Counter Bit 6
; bit position masks
mDC2DCNT_DATCNT0    equ       %00000001
mDC2DCNT_DATCNT1    equ       %00000010
mDC2DCNT_DATCNT2    equ       %00000100
mDC2DCNT_DATCNT3    equ       %00001000
mDC2DCNT_DATCNT4    equ       %00010000
mDC2DCNT_DATCNT5    equ       %00100000
mDC2DCNT_DATCNT6    equ       %01000000

;*** DC2PAGE - Data Codec 2 Page Register
DC2PAGE             equ       $0000003C           ;*** DC2PAGE - Data Codec 2 Page Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2PAGE_PAGE0       equ       0                   ; Page Selection Bit 0
DC2PAGE_PAGE1       equ       1                   ; Page Selection Bit 1
DC2PAGE_PAGE2       equ       2                   ; Page Selection Bit 2
; bit position masks
mDC2PAGE_PAGE0      equ       %00000001
mDC2PAGE_PAGE1      equ       %00000010
mDC2PAGE_PAGE2      equ       %00000100

;*** DC2DAT - Data Codec 2 Data Register
DC2DAT              equ       $0000003D           ;*** DC2DAT - Data Codec 2 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DC2DAT_DAT0         equ       0                   ; 8 bit Data Window Bit 0
DC2DAT_DAT1         equ       1                   ; 8 bit Data Window Bit 1
DC2DAT_DAT2         equ       2                   ; 8 bit Data Window Bit 2
DC2DAT_DAT3         equ       3                   ; 8 bit Data Window Bit 3
DC2DAT_DAT4         equ       4                   ; 8 bit Data Window Bit 4
DC2DAT_DAT5         equ       5                   ; 8 bit Data Window Bit 5
DC2DAT_DAT6         equ       6                   ; 8 bit Data Window Bit 6
DC2DAT_DAT7         equ       7                   ; 8 bit Data Window Bit 7
; bit position masks
mDC2DAT_DAT0        equ       %00000001
mDC2DAT_DAT1        equ       %00000010
mDC2DAT_DAT2        equ       %00000100
mDC2DAT_DAT3        equ       %00001000
mDC2DAT_DAT4        equ       %00010000
mDC2DAT_DAT5        equ       %00100000
mDC2DAT_DAT6        equ       %01000000
mDC2DAT_DAT7        equ       %10000000

;*** PULLCR - Pullup Control Register
PULLCR              equ       $0000003E           ;*** PULLCR - Pullup Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PULLCR_PULL0EN      equ       0                   ; Pullup enable bit 0
PULLCR_PULL1EN      equ       1                   ; Pullup enable bit 1
PULLCR_PULL2EN      equ       2                   ; Pullup enable bit 2
PULLCR_PULL3EN      equ       3                   ; Pullup enable bit 3
PULLCR_PULL4EN      equ       4                   ; Pullup enable bit 4
PULLCR_PULL5EN      equ       5                   ; Pullup enable bit 5
PULLCR_PULL6EN      equ       6                   ; Pullup enable bit 6
PULLCR_PULL7EN      equ       7                   ; Pullup enable bit 7
; bit position masks
mPULLCR_PULL0EN     equ       %00000001
mPULLCR_PULL1EN     equ       %00000010
mPULLCR_PULL2EN     equ       %00000100
mPULLCR_PULL3EN     equ       %00001000
mPULLCR_PULL4EN     equ       %00010000
mPULLCR_PULL5EN     equ       %00100000
mPULLCR_PULL6EN     equ       %01000000
mPULLCR_PULL7EN     equ       %10000000

;*** ADATCR - Alternate Data Control Register
ADATCR              equ       $0000003F           ;*** ADATCR - Alternate Data Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADATCR_ADATA10      equ       0                   ; Alternate Data1 and DIR Mux control bit 0
ADATCR_ADATA11      equ       1                   ; Alternate Data1 and DIR Mux control bit 1
ADATCR_ADATA20      equ       4                   ; Alternate Data2 and DIR Mux control bit 0
ADATCR_ADATA21      equ       5                   ; Alternate Data2 and DIR Mux control bit 1
; bit position masks
mADATCR_ADATA10     equ       %00000001
mADATCR_ADATA11     equ       %00000010
mADATCR_ADATA20     equ       %00010000
mADATCR_ADATA21     equ       %00100000

;*** UE0D0 - USB Endpoint 0 Data Register 0
UE0D0               equ       $00000040           ;*** UE0D0 - USB Endpoint 0 Data Register 0
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
UE0D1               equ       $00000041           ;*** UE0D1 - USB Endpoint 0 Data Register 1
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
UE0D2               equ       $00000042           ;*** UE0D2 - USB Endpoint 0 Data Register 2
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
UE0D3               equ       $00000043           ;*** UE0D3 - USB Endpoint 0 Data Register 3
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
UE0D4               equ       $00000044           ;*** UE0D4 - USB Endpoint 0 Data Register 4
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
UE0D5               equ       $00000045           ;*** UE0D5 - USB Endpoint 0 Data Register 5
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
UE0D6               equ       $00000046           ;*** UE0D6 - USB Endpoint 0 Data Register 6
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
UE0D7               equ       $00000047           ;*** UE0D7 - USB Endpoint 0 Data Register 7
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

;*** SPCR - SPI Control Register
SPCR                equ       $0000004C           ;*** SPCR - SPI Control Register
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
SPSCR               equ       $0000004D           ;*** SPSCR - SPI Status and Control Register
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
SPDR                equ       $0000004E           ;*** SPDR - SPI Data Register
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

;*** USBCR - USB Control Register
USBCR               equ       $00000051           ;*** USBCR - USB Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USBCR_RESUME        equ       0                   ; Force RESUME condition
USBCR_TFC0IE        equ       1                   ; Transfer complete interrupt enable for endpoint 0
USBCR_TFC1IE        equ       2                   ; Transfer complete interrupt enable for endpoint 1
USBCR_TFC2IE        equ       3                   ; Transfer complete interrupt enable for endpoint 2
USBCR_TFC3IE        equ       4                   ; Transfer complete interrupt enable for endpoint 3
USBCR_TFC4IE        equ       5                   ; Transfer complete interrupt enable for endpoint 4
USBCR_USBCLKEN      equ       6                   ; USB Clock Enable
USBCR_USBEN         equ       7                   ; USB Module Enable
; bit position masks
mUSBCR_RESUME       equ       %00000001
mUSBCR_TFC0IE       equ       %00000010
mUSBCR_TFC1IE       equ       %00000100
mUSBCR_TFC2IE       equ       %00001000
mUSBCR_TFC3IE       equ       %00010000
mUSBCR_TFC4IE       equ       %00100000
mUSBCR_USBCLKEN     equ       %01000000
mUSBCR_USBEN        equ       %10000000

;*** USBSR - USB Status Register
USBSR               equ       $00000052           ;*** USBSR - USB Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USBSR_SUSPND        equ       0                   ; SUSPEND Detection Flag
USBSR_RESUMEF       equ       1                   ; RESUME Detection Flag
USBSR_USBRST        equ       2                   ; USB Reset Detection Flag
USBSR_CONFIG_CHG    equ       3                   ; Change of Configuration Detection Flag
USBSR_SOF           equ       4                   ; Start of Frame Detection Flag
USBSR_SETUP         equ       5                   ; SETUP Request Received
USBSR_CONFIG        equ       7                   ; Configuration Number
; bit position masks
mUSBSR_SUSPND       equ       %00000001
mUSBSR_RESUMEF      equ       %00000010
mUSBSR_USBRST       equ       %00000100
mUSBSR_CONFIG_CHG   equ       %00001000
mUSBSR_SOF          equ       %00010000
mUSBSR_SETUP        equ       %00100000
mUSBSR_CONFIG       equ       %10000000

;*** USIMR - USB Status Interrupt Mask Register
USIMR               equ       $00000053           ;*** USIMR - USB Status Interrupt Mask Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USIMR_SUSPNDIE      equ       0                   ; Suspend Mode Interrupt Mask
USIMR_RESUMEFIE     equ       1                   ; Resume Interrupt Mask
USIMR_USBRSTIE      equ       2                   ; USB RESET Interrupt Mask
USIMR_CONFIG_CHGIE  equ       3                   ; Configuration Change Interrupt Mask
USIMR_SOFIE         equ       4                   ; Start-of-frame Interrupt Mask
USIMR_SETUPIE       equ       5                   ; SETUP Request Interrupt Mask
USIMR_EP0_STALL     equ       6                   ; Forced EP0 STALL Handshake Enable
; bit position masks
mUSIMR_SUSPNDIE     equ       %00000001
mUSIMR_RESUMEFIE    equ       %00000010
mUSIMR_USBRSTIE     equ       %00000100
mUSIMR_CONFIG_CHGIE equ       %00001000
mUSIMR_SOFIE        equ       %00010000
mUSIMR_SETUPIE      equ       %00100000
mUSIMR_EP0_STALL    equ       %01000000

;*** UEP0CSR - USB Endpoint 0 Control/Status Register
UEP0CSR             equ       $00000054           ;*** UEP0CSR - USB Endpoint 0 Control/Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP0CSR_TFRC_OUT    equ       0                   ; Transfer Complete Flag for OUT packet
UEP0CSR_DVALID_OUT  equ       1                   ; Data valid enable bit for OUT packet
UEP0CSR_TFRC_IN     equ       2                   ; Transfer Complete Flag for IN packet
UEP0CSR_DVALID_IN   equ       3                   ; Data valid enable bit for IN packet
UEP0CSR_DSIZE0_OUT_DSIZE0_IN equ       4                   ; Endpoint 0 Data Size for OUT packet, Endpoint 0 Data Size for IN packet, Bit 0
UEP0CSR_DSIZE1_OUT_DSIZE1_IN equ       5                   ; Endpoint 0 Data Size for OUT packet, Endpoint 0 Data Size for IN packet, Bit 1
UEP0CSR_DSIZE2_OUT_DSIZE2_IN equ       6                   ; Endpoint 0 Data Size for OUT packet, Endpoint 0 Data Size for IN packet, Bit 2
UEP0CSR_DSIZE3_OUT_DSIZE3_IN equ       7                   ; Endpoint 0 Data Size for OUT packet, Endpoint 0 Data Size for IN packet, Bit 3
; bit position masks
mUEP0CSR_TFRC_OUT   equ       %00000001
mUEP0CSR_DVALID_OUT equ       %00000010
mUEP0CSR_TFRC_IN    equ       %00000100
mUEP0CSR_DVALID_IN  equ       %00001000
mUEP0CSR_DSIZE0_OUT_DSIZE0_IN equ       %00010000
mUEP0CSR_DSIZE1_OUT_DSIZE1_IN equ       %00100000
mUEP0CSR_DSIZE2_OUT_DSIZE2_IN equ       %01000000
mUEP0CSR_DSIZE3_OUT_DSIZE3_IN equ       %10000000

;*** UEP1CSR - USB Endpoint 1 Control/Status Register
UEP1CSR             equ       $00000055           ;*** UEP1CSR - USB Endpoint 1 Control/Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP1CSR_TFRC        equ       0                   ; Transfer Complete Flag
UEP1CSR_DVALID      equ       1                   ; Data valid bit
UEP1CSR_SIZE0       equ       2                   ; Buffer size Selection bit 0
UEP1CSR_SIZE1       equ       3                   ; Buffer size Selection bit 1
UEP1CSR_DIR         equ       4                   ; Endpoint Direction Bit
UEP1CSR_STALL       equ       5                   ; Forced STALL Handshake Enable
UEP1CSR_MODE0       equ       6                   ; Endpoint Type selection bit 0
UEP1CSR_MODE1       equ       7                   ; Endpoint Type selection bit 1
; bit position masks
mUEP1CSR_TFRC       equ       %00000001
mUEP1CSR_DVALID     equ       %00000010
mUEP1CSR_SIZE0      equ       %00000100
mUEP1CSR_SIZE1      equ       %00001000
mUEP1CSR_DIR        equ       %00010000
mUEP1CSR_STALL      equ       %00100000
mUEP1CSR_MODE0      equ       %01000000
mUEP1CSR_MODE1      equ       %10000000

;*** UEP2CSR - USB Endpoint 2 Control/Status Register
UEP2CSR             equ       $00000056           ;*** UEP2CSR - USB Endpoint 2 Control/Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP2CSR_TFRC        equ       0                   ; Transfer Complete Flag
UEP2CSR_DVALID      equ       1                   ; Data valid bit
UEP2CSR_SIZE0       equ       2                   ; Buffer size Selection bit 0
UEP2CSR_SIZE1       equ       3                   ; Buffer size Selection bit 1
UEP2CSR_DIR         equ       4                   ; Endpoint Direction Bit
UEP2CSR_STALL       equ       5                   ; Forced STALL Handshake Enable
UEP2CSR_MODE0       equ       6                   ; Endpoint Type selection bit 0
UEP2CSR_MODE1       equ       7                   ; Endpoint Type selection bit 1
; bit position masks
mUEP2CSR_TFRC       equ       %00000001
mUEP2CSR_DVALID     equ       %00000010
mUEP2CSR_SIZE0      equ       %00000100
mUEP2CSR_SIZE1      equ       %00001000
mUEP2CSR_DIR        equ       %00010000
mUEP2CSR_STALL      equ       %00100000
mUEP2CSR_MODE0      equ       %01000000
mUEP2CSR_MODE1      equ       %10000000

;*** UEP3CSR - USB Endpoint 3 Control/Status Register
UEP3CSR             equ       $00000057           ;*** UEP3CSR - USB Endpoint 3 Control/Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP3CSR_TFRC        equ       0                   ; Transfer Complete Flag
UEP3CSR_DVALID      equ       1                   ; Data valid bit
UEP3CSR_SIZE0       equ       2                   ; Buffer size Selection bit 0
UEP3CSR_SIZE1       equ       3                   ; Buffer size Selection bit 1
UEP3CSR_DIR         equ       4                   ; Endpoint Direction Bit
UEP3CSR_STALL       equ       5                   ; Forced STALL Handshake Enable
UEP3CSR_MODE0       equ       6                   ; Endpoint Type selection bit 0
UEP3CSR_MODE1       equ       7                   ; Endpoint Type selection bit 1
; bit position masks
mUEP3CSR_TFRC       equ       %00000001
mUEP3CSR_DVALID     equ       %00000010
mUEP3CSR_SIZE0      equ       %00000100
mUEP3CSR_SIZE1      equ       %00001000
mUEP3CSR_DIR        equ       %00010000
mUEP3CSR_STALL      equ       %00100000
mUEP3CSR_MODE0      equ       %01000000
mUEP3CSR_MODE1      equ       %10000000

;*** UEP4CSR - USB Endpoint 4 Control/Status Register
UEP4CSR             equ       $00000058           ;*** UEP4CSR - USB Endpoint 4 Control/Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP4CSR_TFRC        equ       0                   ; Transfer Complete Flag
UEP4CSR_DVALID      equ       1                   ; Data valid bit
UEP4CSR_SIZE0       equ       2                   ; Buffer size Selection bit 0
UEP4CSR_SIZE1       equ       3                   ; Buffer size Selection bit 1
UEP4CSR_DIR         equ       4                   ; Endpoint Direction Bit
UEP4CSR_STALL       equ       5                   ; Forced STALL Handshake Enable
UEP4CSR_MODE0       equ       6                   ; Endpoint Type selection bit 0
UEP4CSR_MODE1       equ       7                   ; Endpoint Type selection bit 1
; bit position masks
mUEP4CSR_TFRC       equ       %00000001
mUEP4CSR_DVALID     equ       %00000010
mUEP4CSR_SIZE0      equ       %00000100
mUEP4CSR_SIZE1      equ       %00001000
mUEP4CSR_DIR        equ       %00010000
mUEP4CSR_STALL      equ       %00100000
mUEP4CSR_MODE0      equ       %01000000
mUEP4CSR_MODE1      equ       %10000000

;*** UEP1DSR - USB Endpoint 1 Data Size Register
UEP1DSR             equ       $00000059           ;*** UEP1DSR - USB Endpoint 1 Data Size Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP1DSR_DSIZE0      equ       0                   ; Packet Data Size Bit 0
UEP1DSR_DSIZE1      equ       1                   ; Packet Data Size Bit 1
UEP1DSR_DSIZE2      equ       2                   ; Packet Data Size Bit 2
UEP1DSR_DSIZE3      equ       3                   ; Packet Data Size Bit 3
UEP1DSR_DSIZE4      equ       4                   ; Packet Data Size Bit 4
UEP1DSR_DSIZE5      equ       5                   ; Packet Data Size Bit 5
UEP1DSR_DSIZE6      equ       6                   ; Packet Data Size Bit 6
; bit position masks
mUEP1DSR_DSIZE0     equ       %00000001
mUEP1DSR_DSIZE1     equ       %00000010
mUEP1DSR_DSIZE2     equ       %00000100
mUEP1DSR_DSIZE3     equ       %00001000
mUEP1DSR_DSIZE4     equ       %00010000
mUEP1DSR_DSIZE5     equ       %00100000
mUEP1DSR_DSIZE6     equ       %01000000

;*** UEP2DSR - USB Endpoint 2 Data Size Register
UEP2DSR             equ       $0000005A           ;*** UEP2DSR - USB Endpoint 2 Data Size Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP2DSR_DSIZE0      equ       0                   ; Packet Data Size Bit 0
UEP2DSR_DSIZE1      equ       1                   ; Packet Data Size Bit 1
UEP2DSR_DSIZE2      equ       2                   ; Packet Data Size Bit 2
UEP2DSR_DSIZE3      equ       3                   ; Packet Data Size Bit 3
UEP2DSR_DSIZE4      equ       4                   ; Packet Data Size Bit 4
UEP2DSR_DSIZE5      equ       5                   ; Packet Data Size Bit 5
UEP2DSR_DSIZE6      equ       6                   ; Packet Data Size Bit 6
; bit position masks
mUEP2DSR_DSIZE0     equ       %00000001
mUEP2DSR_DSIZE1     equ       %00000010
mUEP2DSR_DSIZE2     equ       %00000100
mUEP2DSR_DSIZE3     equ       %00001000
mUEP2DSR_DSIZE4     equ       %00010000
mUEP2DSR_DSIZE5     equ       %00100000
mUEP2DSR_DSIZE6     equ       %01000000

;*** UEP3DSR - USB Endpoint 3 Data Size Register
UEP3DSR             equ       $0000005B           ;*** UEP3DSR - USB Endpoint 3 Data Size Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP3DSR_DSIZE0      equ       0                   ; Packet Data Size Bit 0
UEP3DSR_DSIZE1      equ       1                   ; Packet Data Size Bit 1
UEP3DSR_DSIZE2      equ       2                   ; Packet Data Size Bit 2
UEP3DSR_DSIZE3      equ       3                   ; Packet Data Size Bit 3
UEP3DSR_DSIZE4      equ       4                   ; Packet Data Size Bit 4
UEP3DSR_DSIZE5      equ       5                   ; Packet Data Size Bit 5
UEP3DSR_DSIZE6      equ       6                   ; Packet Data Size Bit 6
; bit position masks
mUEP3DSR_DSIZE0     equ       %00000001
mUEP3DSR_DSIZE1     equ       %00000010
mUEP3DSR_DSIZE2     equ       %00000100
mUEP3DSR_DSIZE3     equ       %00001000
mUEP3DSR_DSIZE4     equ       %00010000
mUEP3DSR_DSIZE5     equ       %00100000
mUEP3DSR_DSIZE6     equ       %01000000

;*** UEP4DSR - USB Endpoint 4 Data Size Register
UEP4DSR             equ       $0000005C           ;*** UEP4DSR - USB Endpoint 4 Data Size Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP4DSR_DSIZE0      equ       0                   ; Packet Data Size Bit 0
UEP4DSR_DSIZE1      equ       1                   ; Packet Data Size Bit 1
UEP4DSR_DSIZE2      equ       2                   ; Packet Data Size Bit 2
UEP4DSR_DSIZE3      equ       3                   ; Packet Data Size Bit 3
UEP4DSR_DSIZE4      equ       4                   ; Packet Data Size Bit 4
UEP4DSR_DSIZE5      equ       5                   ; Packet Data Size Bit 5
UEP4DSR_DSIZE6      equ       6                   ; Packet Data Size Bit 6
; bit position masks
mUEP4DSR_DSIZE0     equ       %00000001
mUEP4DSR_DSIZE1     equ       %00000010
mUEP4DSR_DSIZE2     equ       %00000100
mUEP4DSR_DSIZE3     equ       %00001000
mUEP4DSR_DSIZE4     equ       %00010000
mUEP4DSR_DSIZE5     equ       %00100000
mUEP4DSR_DSIZE6     equ       %01000000

;*** UEP12BPR - USB Endpoint 1/2 Base Pointer Register
UEP12BPR            equ       $0000005D           ;*** UEP12BPR - USB Endpoint 1/2 Base Pointer Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP12BPR_BASE10     equ       0                   ; Base Location Pointer 1 Bit 0
UEP12BPR_BASE11     equ       1                   ; Base Location Pointer 1 Bit 1
UEP12BPR_BASE12     equ       2                   ; Base Location Pointer 1 Bit 2
UEP12BPR_BASE20     equ       4                   ; Base Location Pointer 2 Bit 0
UEP12BPR_BASE21     equ       5                   ; Base Location Pointer 2 Bit 1
UEP12BPR_BASE22     equ       6                   ; Base Location Pointer 2 Bit 2
; bit position masks
mUEP12BPR_BASE10    equ       %00000001
mUEP12BPR_BASE11    equ       %00000010
mUEP12BPR_BASE12    equ       %00000100
mUEP12BPR_BASE20    equ       %00010000
mUEP12BPR_BASE21    equ       %00100000
mUEP12BPR_BASE22    equ       %01000000

;*** UEP34BPR - USB Endpoint 3/4 Base Pointer Register
UEP34BPR            equ       $0000005E           ;*** UEP34BPR - USB Endpoint 3/4 Base Pointer Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UEP34BPR_BASE30     equ       0                   ; Base Location Pointer 3 Bit 0
UEP34BPR_BASE31     equ       1                   ; Base Location Pointer 3 Bit 1
UEP34BPR_BASE32     equ       2                   ; Base Location Pointer 3 Bit 2
UEP34BPR_BASE40     equ       4                   ; Base Location Pointer 4 Bit 0
UEP34BPR_BASE41     equ       5                   ; Base Location Pointer 4 Bit 1
UEP34BPR_BASE42     equ       6                   ; Base Location Pointer 4 Bit 2
; bit position masks
mUEP34BPR_BASE30    equ       %00000001
mUEP34BPR_BASE31    equ       %00000010
mUEP34BPR_BASE32    equ       %00000100
mUEP34BPR_BASE40    equ       %00010000
mUEP34BPR_BASE41    equ       %00100000
mUEP34BPR_BASE42    equ       %01000000

;*** UINTFCR - USB Interface Control Register
UINTFCR             equ       $0000005F           ;*** UINTFCR - USB Interface Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UINTFCR_EP1INT      equ       0                   ; Endpoint 1 Interface number
UINTFCR_EP2INT      equ       2                   ; Endpoint 2 Interface number
UINTFCR_EP3INT      equ       4                   ; Endpoint 3 Interface number
UINTFCR_EP4INT      equ       6                   ; Endpoint 4 Interface number
; bit position masks
mUINTFCR_EP1INT     equ       %00000001
mUINTFCR_EP2INT     equ       %00000100
mUINTFCR_EP3INT     equ       %00010000
mUINTFCR_EP4INT     equ       %01000000

;*** PCTL - PLL Control Register
PCTL                equ       $00001090           ;*** PCTL - PLL Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL_VPR0           equ       0                   ; VCO Power-of-Two Range Select Bit 0
PCTL_VPR1           equ       1                   ; VCO Power-of-Two Range Select Bit 1
PCTL_PRE0           equ       2                   ; Prescaler Program Bit 0
PCTL_PRE1           equ       3                   ; Prescaler Program Bit 1
PCTL_BCS            equ       4                   ; Base Clock Select Bit
PCTL_PLLON          equ       5                   ; PLL On Bit
PCTL_PLLF           equ       6                   ; PLL Flag Bit
PCTL_PLLIE          equ       7                   ; PLL Interrupt Enable Bit
; bit position masks
mPCTL_VPR0          equ       %00000001
mPCTL_VPR1          equ       %00000010
mPCTL_PRE0          equ       %00000100
mPCTL_PRE1          equ       %00001000
mPCTL_BCS           equ       %00010000
mPCTL_PLLON         equ       %00100000
mPCTL_PLLF          equ       %01000000
mPCTL_PLLIE         equ       %10000000

;*** PBWC - PLL Bandwidth Control Register
PBWC                equ       $00001091           ;*** PBWC - PLL Bandwidth Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PBWC_ACQ            equ       5                   ; Automatic Bandwidth Control Bit
PBWC_LOCK           equ       6                   ; Lock Indicator Bit
PBWC_AUTO           equ       7                   ; Acquisiton Mode Bit
; bit position masks
mPBWC_ACQ           equ       %00100000
mPBWC_LOCK          equ       %01000000
mPBWC_AUTO          equ       %10000000

;*** PMS - PLL Multiplier Select Register
PMS                 equ       $00001092           ;*** PMS - PLL Multiplier Select Register

;*** PMSH - PLL Multiplier Select Register High
PMSH                equ       $00001092           ;*** PMSH - PLL Multiplier Select Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMSH_MUL8           equ       0                   ; PLL Multiplier Select Bit 8
PMSH_MUL9           equ       1                   ; PLL Multiplier Select Bit 9
PMSH_MUL10          equ       2                   ; PLL Multiplier Select Bit 10
PMSH_MUL11          equ       3                   ; PLL Multiplier Select Bit 11
; bit position masks
mPMSH_MUL8          equ       %00000001
mPMSH_MUL9          equ       %00000010
mPMSH_MUL10         equ       %00000100
mPMSH_MUL11         equ       %00001000

;*** PMSL - PLL Multiplier Select Register Low
PMSL                equ       $00001093           ;*** PMSL - PLL Multiplier Select Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMSL_MUL0           equ       0                   ; PLL Multiplier Select Bit 0
PMSL_MUL1           equ       1                   ; PLL Multiplier Select Bit 1
PMSL_MUL2           equ       2                   ; PLL Multiplier Select Bit 2
PMSL_MUL3           equ       3                   ; PLL Multiplier Select Bit 3
PMSL_MUL4           equ       4                   ; PLL Multiplier Select Bit 4
PMSL_MUL5           equ       5                   ; PLL Multiplier Select Bit 5
PMSL_MUL6           equ       6                   ; PLL Multiplier Select Bit 6
PMSL_MUL7           equ       7                   ; PLL Multiplier Select Bit 7
; bit position masks
mPMSL_MUL0          equ       %00000001
mPMSL_MUL1          equ       %00000010
mPMSL_MUL2          equ       %00000100
mPMSL_MUL3          equ       %00001000
mPMSL_MUL4          equ       %00010000
mPMSL_MUL5          equ       %00100000
mPMSL_MUL6          equ       %01000000
mPMSL_MUL7          equ       %10000000

;*** PMRS - PLL VCO Range Select
PMRS                equ       $00001094           ;*** PMRS - PLL VCO Range Select
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMRS_VRS0           equ       0                   ; VCO Range Select Bit 0
PMRS_VRS1           equ       1                   ; VCO Range Select Bit 1
PMRS_VRS2           equ       2                   ; VCO Range Select Bit 2
PMRS_VRS3           equ       3                   ; VCO Range Select Bit 3
PMRS_VRS4           equ       4                   ; VCO Range Select Bit 4
PMRS_VRS5           equ       5                   ; VCO Range Select Bit 5
PMRS_VRS6           equ       6                   ; VCO Range Select Bit 6
PMRS_VRS7           equ       7                   ; VCO Range Select Bit 7
; bit position masks
mPMRS_VRS0          equ       %00000001
mPMRS_VRS1          equ       %00000010
mPMRS_VRS2          equ       %00000100
mPMRS_VRS3          equ       %00001000
mPMRS_VRS4          equ       %00010000
mPMRS_VRS5          equ       %00100000
mPMRS_VRS6          equ       %01000000
mPMRS_VRS7          equ       %10000000

;*** PMDS - PLL Reference Divider Select Register
PMDS                equ       $00001095           ;*** PMDS - PLL Reference Divider Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMDS_RDS0           equ       0                   ; Reference Divider Select Bit 0
PMDS_RDS1           equ       1                   ; Reference Divider Select Bit 1
PMDS_RDS2           equ       2                   ; Reference Divider Select Bit 2
PMDS_RDS3           equ       3                   ; Reference Divider Select Bit 3
; bit position masks
mPMDS_RDS0          equ       %00000001
mPMDS_RDS1          equ       %00000010
mPMDS_RDS2          equ       %00000100
mPMDS_RDS3          equ       %00001000

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
INT2_IF7            equ       0                   ; Interrupt Flag Bit 7
INT2_IF8            equ       1                   ; Interrupt Flag Bit 8
INT2_IF9            equ       2                   ; Interrupt Flag Bit 9
INT2_IF10           equ       3                   ; Interrupt Flag Bit 10
INT2_IF11           equ       4                   ; Interrupt Flag Bit 11
INT2_IF12           equ       5                   ; Interrupt Flag Bit 12
INT2_IF13           equ       6                   ; Interrupt Flag Bit 13
INT2_IF14           equ       7                   ; Interrupt Flag Bit 14
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
INT3_IF15           equ       0                   ; Interrupt Flag Bit 15
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

;*** LVISR - LVI I/O Register
LVISR               equ       $0000FE0F           ;*** LVISR - LVI I/O Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LVIOUT       equ       %10000000

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
