;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908LT8_52, version 2.89.068 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908lt8.inc
;     Processor : MC68HC908LT8CPB
;     FileFormat: V2.28
;     DataSheet : MC68HC(9)08LT4/LT8 Rev. 0.8
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
ROM                 equ       $0000DE00
ROM_END             equ       $0000FDFF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       RAM
XRAM_END            equ       RAM_END
;
INT_KBD             equ       $0000FFDC
Reserved2           equ       $0000FFDE
Reserved3           equ       $0000FFE0
Reserved4           equ       $0000FFE2
Reserved5           equ       $0000FFE4
Reserved6           equ       $0000FFE6
Reserved7           equ       $0000FFE8
INT_TIM2Ovr         equ       $0000FFEA
INT_TIM2CH1         equ       $0000FFEC
INT_TIM2CH0         equ       $0000FFEE
INT_TIM1Ovr         equ       $0000FFF0
INT_TIM1CH1         equ       $0000FFF2
INT_TIM1CH0         equ       $0000FFF4
Reserved14          equ       $0000FFF6
INT_LVI             equ       $0000FFF8
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
PTB_PTB6            equ       6                   ; Port B Data Bit 6
PTB_PTB7            equ       7                   ; Port B Data Bit 7
; bit position masks
mPTB_PTB0           equ       %00000001
mPTB_PTB1           equ       %00000010
mPTB_PTB2           equ       %00000100
mPTB_PTB3           equ       %00001000
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
PTC_PTC5            equ       5                   ; Port C Data Bit 5
PTC_PTC6            equ       6                   ; Port C Data Bit 6
PTC_PTC7            equ       7                   ; Port C Data Bit 7
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010
mPTC_PTC2           equ       %00000100
mPTC_PTC3           equ       %00001000
mPTC_PTC4           equ       %00010000
mPTC_PTC5           equ       %00100000
mPTC_PTC6           equ       %01000000
mPTC_PTC7           equ       %10000000

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
DDRB_DDRB6          equ       6                   ; Data Direction Register B Bit 6
DDRB_DDRB7          equ       7                   ; Data Direction Register B Bit 7
; bit position masks
mDDRB_DDRB0         equ       %00000001
mDDRB_DDRB1         equ       %00000010
mDDRB_DDRB2         equ       %00000100
mDDRB_DDRB3         equ       %00001000
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
DDRC_DDRC5          equ       5                   ; Data Direction Register C Bit 5
DDRC_DDRC6          equ       6                   ; Data Direction Register C Bit 6
DDRC_DDRC7          equ       7                   ; Data Direction Register C Bit 7
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000
mDDRC_DDRC4         equ       %00010000
mDDRC_DDRC5         equ       %00100000
mDDRC_DDRC6         equ       %01000000
mDDRC_DDRC7         equ       %10000000

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

;*** DDRE - Data Direction Register E
DDRE                equ       $00000008           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0          equ       0                   ; Data Direction Register E Bit 0
DDRE_DDRE1          equ       1                   ; Data Direction Register E Bit 1
DDRE_DDRE2          equ       2                   ; Data Direction Register E Bit 2
DDRE_DDRE3          equ       3                   ; Data Direction Register E Bit 3
DDRE_DDRE4          equ       4                   ; Data Direction Register E Bit 4
DDRE_DDRE5          equ       5                   ; Data Direction Register E Bit 5
DDRE_DDRE6          equ       6                   ; Data Direction Register E Bit 6
DDRE_DDRE7          equ       7                   ; Data Direction Register E Bit 7
; bit position masks
mDDRE_DDRE0         equ       %00000001
mDDRE_DDRE1         equ       %00000010
mDDRE_DDRE2         equ       %00000100
mDDRE_DDRE3         equ       %00001000
mDDRE_DDRE4         equ       %00010000
mDDRE_DDRE5         equ       %00100000
mDDRE_DDRE6         equ       %01000000
mDDRE_DDRE7         equ       %10000000

;*** PTE - Port E Data Register
PTE                 equ       $00000009           ;*** PTE - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTE_PTE0            equ       0                   ; Port E Data Bit 0
PTE_PTE1            equ       1                   ; Port E Data Bit 1
PTE_PTE2            equ       2                   ; Port E Data Bit 2
PTE_PTE3            equ       3                   ; Port E Data Bit 3
PTE_PTE4            equ       4                   ; Port E Data Bit 4
PTE_PTE5            equ       5                   ; Port E Data Bit 5
PTE_PTE6            equ       6                   ; Port E Data Bit 6
PTE_PTE7            equ       7                   ; Port E Data Bit 7
; bit position masks
mPTE_PTE0           equ       %00000001
mPTE_PTE1           equ       %00000010
mPTE_PTE2           equ       %00000100
mPTE_PTE3           equ       %00001000
mPTE_PTE4           equ       %00010000
mPTE_PTE5           equ       %00100000
mPTE_PTE6           equ       %01000000
mPTE_PTE7           equ       %10000000

;*** HDB - Port B High Current Drive Control Register
HDB                 equ       $0000000C           ;*** HDB - Port B High Current Drive Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HDB_HDB2            equ       2                   ; Port B LED Drive Enable Bit 2
HDB_HDB3            equ       3                   ; Port B LED Drive Enable Bit 3
; bit position masks
mHDB_HDB2           equ       %00000100
mHDB_HDB3           equ       %00001000

;*** KBSCR - Keyboard Status and Control Register
KBSCR               equ       $0000001B           ;*** KBSCR - Keyboard Status and Control Register
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

;*** KBIER - Keyobard Interrupt Enable Register
KBIER               equ       $0000001C           ;*** KBIER - Keyobard Interrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIER_KBIE0         equ       0                   ; Keyboard Interrut Enable Bit
KBIER_KBIE1         equ       1                   ; Keyboard Interrut Enable Bit
KBIER_KBIE2         equ       2                   ; Keyboard Interrut Enable Bit
KBIER_KBIE3         equ       3                   ; Keyboard Interrut Enable Bit
; bit position masks
mKBIER_KBIE0        equ       %00000001
mKBIER_KBIE1        equ       %00000010
mKBIER_KBIE2        equ       %00000100
mKBIER_KBIE3        equ       %00001000

;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001D           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_LVISEL0     equ       0                   ; LVI Operating Mode Selection 0
CONFIG2_LVISEL1     equ       1                   ; LVI Operating Mode Selection 1
CONFIG2_PCEL        equ       2                   ; Port C Enable Low Nibble
CONFIG2_PCEH        equ       3                   ; Port C Enable High Nibble
CONFIG2_PDE         equ       4                   ; Port D Enable
CONFIG2_PEE         equ       5                   ; Port E Enable
CONFIG2_STOP_XTALEN equ       6                   ; Crystal Oscillator Stop Mode Enable
CONFIG2_STOP_XCLKEN equ       7                   ; Crystal Oscillator Stop Mode Enable
; bit position masks
mCONFIG2_LVISEL0    equ       %00000001
mCONFIG2_LVISEL1    equ       %00000010
mCONFIG2_PCEL       equ       %00000100
mCONFIG2_PCEH       equ       %00001000
mCONFIG2_PDE        equ       %00010000
mCONFIG2_PEE        equ       %00100000
mCONFIG2_STOP_XTALEN equ       %01000000
mCONFIG2_STOP_XCLKEN equ       %10000000

;*** INTSCR1 - IRQ Status and Control Register
INTSCR1             equ       $0000001E           ;*** INTSCR1 - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSCR1_MODE        equ       0                   ; IRQ Edge/Level Select Bit
INTSCR1_IMASK       equ       1                   ; IRQ Interrupt Mask Bit
INTSCR1_ACK         equ       2                   ; IRQ Interrupt Request Acknowledge Bit
INTSCR1_IRQF        equ       3                   ; IRQ Flag Bit
; bit position masks
mINTSCR1_MODE       equ       %00000001
mINTSCR1_IMASK      equ       %00000010
mINTSCR1_ACK        equ       %00000100
mINTSCR1_IRQF       equ       %00001000

;*** CONFIG1 - Configuration Register 2
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 2
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

;*** T1SC - TIM1 Status and Control Register
T1SC                equ       $00000020           ;*** T1SC - TIM1 Status and Control Register
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

;*** T1CNTH - TIM1 Counter Register
T1CNTH              equ       $00000021           ;*** T1CNTH - TIM1 Counter Register

;*** T1CNTL - TIM1 Counter Register
T1CNTL              equ       $00000022           ;*** T1CNTL - TIM1 Counter Register

;*** T1MOD - TIM1 Counter Modulo Register
T1MOD               equ       $00000023           ;*** T1MOD - TIM1 Counter Modulo Register

;*** T1MODH - TIM1 Counter Modulo Register
T1MODH              equ       $00000023           ;*** T1MODH - TIM1 Counter Modulo Register

;*** T1MODL - TIM1 Counter Modulo Register
T1MODL              equ       $00000024           ;*** T1MODL - TIM1 Counter Modulo Register

;*** T1SC0 - TIM1 Channel Status and Control Register
T1SC0               equ       $00000025           ;*** T1SC0 - TIM1 Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T1SC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
T1SC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
T1SC0_ELS0A         equ       2                   ; Edge/Level Select Bit
T1SC0_ELS0B         equ       3                   ; Edge/Level Select Bit
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

;*** T1CH0 - TIM1 Channel Register
T1CH0               equ       $00000026           ;*** T1CH0 - TIM1 Channel Register

;*** T1CH0H - TIM1 Channel Register
T1CH0H              equ       $00000026           ;*** T1CH0H - TIM1 Channel Register

;*** T1CH0L - TIM1 Channel Register
T1CH0L              equ       $00000027           ;*** T1CH0L - TIM1 Channel Register

;*** T1SC1 - TIM1 Channel Status and Control Register
T1SC1               equ       $00000028           ;*** T1SC1 - TIM1 Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T1SC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
T1SC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
T1SC1_ELS1A         equ       2                   ; Edge/Level Select Bit
T1SC1_ELS1B         equ       3                   ; Edge/Level Select Bit
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

;*** T1CH1 - TIM1 Channel Register
T1CH1               equ       $00000029           ;*** T1CH1 - TIM1 Channel Register

;*** T1CH1H - TIM1 Channel Register
T1CH1H              equ       $00000029           ;*** T1CH1H - TIM1 Channel Register

;*** T1CH1L - TIM1 Channel Register
T1CH1L              equ       $0000002A           ;*** T1CH1L - TIM1 Channel Register

;*** T2SC - TIM2 Status and Control Register
T2SC                equ       $0000002B           ;*** T2SC - TIM2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC_PS0            equ       0                   ; Prescaler Select Bit
T2SC_PS1            equ       1                   ; Prescaler Select Bit
T2SC_PS2            equ       2                   ; Prescaler Select Bit
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
T2CNT               equ       $0000002C           ;*** T2CNT - TIM2 Counter Register

;*** T2CNTH - TIM2 Counter Register
T2CNTH              equ       $0000002C           ;*** T2CNTH - TIM2 Counter Register

;*** T2CNTL - TIM2 Counter Register
T2CNTL              equ       $0000002D           ;*** T2CNTL - TIM2 Counter Register

;*** T2MOD - TIM2 Counter Modulo Register
T2MOD               equ       $0000002E           ;*** T2MOD - TIM2 Counter Modulo Register

;*** T2MODH - TIM2 Counter Modulo Register
T2MODH              equ       $0000002E           ;*** T2MODH - TIM2 Counter Modulo Register

;*** T2MODL - TIM2 Counter Modulo Register
T2MODL              equ       $0000002F           ;*** T2MODL - TIM2 Counter Modulo Register

;*** T2SC0 - TIM2 Channel Status and Control Register
T2SC0               equ       $00000030           ;*** T2SC0 - TIM2 Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
T2SC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
T2SC0_ELS0A         equ       2                   ; Edge/Level Select Bit
T2SC0_ELS0B         equ       3                   ; Edge/Level Select Bit
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

;*** T2CH0 - TIM2 Channel Register
T2CH0               equ       $00000031           ;*** T2CH0 - TIM2 Channel Register

;*** T2CH0H - TIM2 Channel Register
T2CH0H              equ       $00000031           ;*** T2CH0H - TIM2 Channel Register

;*** T2CH0L - TIM2 Channel Register
T2CH0L              equ       $00000032           ;*** T2CH0L - TIM2 Channel Register

;*** T2SC1 - TIM2 Channel Status and Control Register
T2SC1               equ       $00000033           ;*** T2SC1 - TIM2 Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
T2SC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
T2SC1_ELS1A         equ       2                   ; Edge/Level Select Bit
T2SC1_ELS1B         equ       3                   ; Edge/Level Select Bit
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

;*** T2CH1 - TIM2 Channel Register
T2CH1               equ       $00000034           ;*** T2CH1 - TIM2 Channel Register

;*** T2CH1H - TIM2 Channel Register
T2CH1H              equ       $00000034           ;*** T2CH1H - TIM2 Channel Register

;*** T2CH1L - TIM2 Channel Register
T2CH1L              equ       $00000035           ;*** T2CH1L - TIM2 Channel Register

;*** LCDCLK - LCD Clock Register
LCDCLK              equ       $0000004F           ;*** LCDCLK - LCD Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDCLK_LCLK0        equ       0                   ; LCD Waweform Base Clock Select 0
LCDCLK_LCLK1        equ       1                   ; LCD Waweform Base Clock Select 1
LCDCLK_LCLK2        equ       2                   ; LCD Waweform Base Clock Select 2
LCDCLK_DUTY0        equ       3                   ; Duty Cycle Select Bit 0
LCDCLK_DUTY1        equ       4                   ; Duty Cycle Select Bit 1
LCDCLK_FCCLT0       equ       5                   ; Fast Charde Duty Cycle Select Bit 0
LCDCLK_FCCLT1       equ       6                   ; Fast Charde Duty Cycle Select Bit 1
; bit position masks
mLCDCLK_LCLK0       equ       %00000001
mLCDCLK_LCLK1       equ       %00000010
mLCDCLK_LCLK2       equ       %00000100
mLCDCLK_DUTY0       equ       %00001000
mLCDCLK_DUTY1       equ       %00010000
mLCDCLK_FCCLT0      equ       %00100000
mLCDCLK_FCCLT1      equ       %01000000

;*** LCDCR - LCD Control Register
LCDCR               equ       $00000051           ;*** LCDCR - LCD Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDCR_LCCON0        equ       0                   ; LCD Contrast Control Bit 0
LCDCR_LCCON1        equ       1                   ; LCD Contrast Control Bit 1
LCDCR_LCCON2        equ       2                   ; LCD Contrast Control Bit 2
LCDCR_LCCON3        equ       3                   ; LCD Contrast Control Bit 3
LCDCR_LC            equ       4                   ; Low Current
LCDCR_FC            equ       5                   ; Fast Charge
LCDCR_LCDE          equ       7                   ; LCD Enable
; bit position masks
mLCDCR_LCCON0       equ       %00000001
mLCDCR_LCCON1       equ       %00000010
mLCDCR_LCCON2       equ       %00000100
mLCDCR_LCCON3       equ       %00001000
mLCDCR_LC           equ       %00010000
mLCDCR_FC           equ       %00100000
mLCDCR_LCDE         equ       %10000000

;*** LDAT1 - LCD Data Register
LDAT1               equ       $00000052           ;*** LDAT1 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT1_F0B0          equ       0                   ; LCD Segment 0 Data Bit 0
LDAT1_F0B1          equ       1                   ; LCD Segment 0 Data Bit 1
LDAT1_F0B2          equ       2                   ; LCD Segment 0 Data Bit 2
LDAT1_F0B3          equ       3                   ; LCD Segment 0 Data Bit 3
LDAT1_F1B0          equ       4                   ; LCD Segment 1 Data Bit 0
LDAT1_F1B1          equ       5                   ; LCD Segment 1 Data Bit 1
LDAT1_F1B2          equ       6                   ; LCD Segment 1 Data Bit 2
LDAT1_F1B3          equ       7                   ; LCD Segment 1 Data Bit 3
; bit position masks
mLDAT1_F0B0         equ       %00000001
mLDAT1_F0B1         equ       %00000010
mLDAT1_F0B2         equ       %00000100
mLDAT1_F0B3         equ       %00001000
mLDAT1_F1B0         equ       %00010000
mLDAT1_F1B1         equ       %00100000
mLDAT1_F1B2         equ       %01000000
mLDAT1_F1B3         equ       %10000000

;*** LDAT2 - LCD Data Register
LDAT2               equ       $00000053           ;*** LDAT2 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT2_F2B0          equ       0                   ; LCD Segment 2 Data Bit 0
LDAT2_F2B1          equ       1                   ; LCD Segment 2 Data Bit 1
LDAT2_F2B2          equ       2                   ; LCD Segment 2 Data Bit 2
LDAT2_F2B3          equ       3                   ; LCD Segment 2 Data Bit 3
LDAT2_F3B0          equ       4                   ; LCD Segment 3 Data Bit 0
LDAT2_F3B1          equ       5                   ; LCD Segment 3 Data Bit 1
LDAT2_F3B2          equ       6                   ; LCD Segment 3 Data Bit 2
LDAT2_F3B3          equ       7                   ; LCD Segment 3 Data Bit 3
; bit position masks
mLDAT2_F2B0         equ       %00000001
mLDAT2_F2B1         equ       %00000010
mLDAT2_F2B2         equ       %00000100
mLDAT2_F2B3         equ       %00001000
mLDAT2_F3B0         equ       %00010000
mLDAT2_F3B1         equ       %00100000
mLDAT2_F3B2         equ       %01000000
mLDAT2_F3B3         equ       %10000000

;*** LDAT3 - LCD Data Register
LDAT3               equ       $00000054           ;*** LDAT3 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT3_F4B0          equ       0                   ; LCD Segment 4 Data Bit 0
LDAT3_F4B1          equ       1                   ; LCD Segment 4 Data Bit 1
LDAT3_F4B2          equ       2                   ; LCD Segment 4 Data Bit 2
LDAT3_F4B3          equ       3                   ; LCD Segment 4 Data Bit 3
LDAT3_F5B0          equ       4                   ; LCD Segment 5 Data Bit 0
LDAT3_F5B1          equ       5                   ; LCD Segment 5 Data Bit 1
LDAT3_F5B2          equ       6                   ; LCD Segment 5 Data Bit 2
LDAT3_F5B3          equ       7                   ; LCD Segment 5 Data Bit 3
; bit position masks
mLDAT3_F4B0         equ       %00000001
mLDAT3_F4B1         equ       %00000010
mLDAT3_F4B2         equ       %00000100
mLDAT3_F4B3         equ       %00001000
mLDAT3_F5B0         equ       %00010000
mLDAT3_F5B1         equ       %00100000
mLDAT3_F5B2         equ       %01000000
mLDAT3_F5B3         equ       %10000000

;*** LDAT4 - LCD Data Register
LDAT4               equ       $00000055           ;*** LDAT4 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT4_F6B0          equ       0                   ; LCD Segment 6 Data Bit 0
LDAT4_F6B1          equ       1                   ; LCD Segment 6 Data Bit 1
LDAT4_F6B2          equ       2                   ; LCD Segment 6 Data Bit 2
LDAT4_F6B3          equ       3                   ; LCD Segment 6 Data Bit 3
LDAT4_F7B0          equ       4                   ; LCD Segment 7 Data Bit 0
LDAT4_F7B1          equ       5                   ; LCD Segment 7 Data Bit 1
LDAT4_F7B2          equ       6                   ; LCD Segment 7 Data Bit 2
LDAT4_F7B3          equ       7                   ; LCD Segment 7 Data Bit 3
; bit position masks
mLDAT4_F6B0         equ       %00000001
mLDAT4_F6B1         equ       %00000010
mLDAT4_F6B2         equ       %00000100
mLDAT4_F6B3         equ       %00001000
mLDAT4_F7B0         equ       %00010000
mLDAT4_F7B1         equ       %00100000
mLDAT4_F7B2         equ       %01000000
mLDAT4_F7B3         equ       %10000000

;*** LDAT5 - LCD Data Register
LDAT5               equ       $00000056           ;*** LDAT5 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT5_F8B0          equ       0                   ; LCD Segment 8 Data Bit 0
LDAT5_F8B1          equ       1                   ; LCD Segment 8 Data Bit 1
LDAT5_F8B2          equ       2                   ; LCD Segment 8 Data Bit 2
LDAT5_F8B3          equ       3                   ; LCD Segment 8 Data Bit 3
LDAT5_F9B0          equ       4                   ; LCD Segment 9 Data Bit 0
LDAT5_F9B1          equ       5                   ; LCD Segment 9 Data Bit 1
LDAT5_F9B2          equ       6                   ; LCD Segment 9 Data Bit 2
LDAT5_F9B3          equ       7                   ; LCD Segment 9 Data Bit 3
; bit position masks
mLDAT5_F8B0         equ       %00000001
mLDAT5_F8B1         equ       %00000010
mLDAT5_F8B2         equ       %00000100
mLDAT5_F8B3         equ       %00001000
mLDAT5_F9B0         equ       %00010000
mLDAT5_F9B1         equ       %00100000
mLDAT5_F9B2         equ       %01000000
mLDAT5_F9B3         equ       %10000000

;*** LDAT6 - LCD Data Register
LDAT6               equ       $00000057           ;*** LDAT6 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT6_F10B0         equ       0                   ; LCD Segment 10 Data Bit 0
LDAT6_F10B1         equ       1                   ; LCD Segment 10 Data Bit 1
LDAT6_F10B2         equ       2                   ; LCD Segment 10 Data Bit 2
LDAT6_F10B3         equ       3                   ; LCD Segment 10 Data Bit 3
LDAT6_F11B0         equ       4                   ; LCD Segment 11 Data Bit 0
LDAT6_F11B1         equ       5                   ; LCD Segment 11 Data Bit 1
LDAT6_F11B2         equ       6                   ; LCD Segment 11 Data Bit 2
LDAT6_F11B3         equ       7                   ; LCD Segment 11 Data Bit 3
; bit position masks
mLDAT6_F10B0        equ       %00000001
mLDAT6_F10B1        equ       %00000010
mLDAT6_F10B2        equ       %00000100
mLDAT6_F10B3        equ       %00001000
mLDAT6_F11B0        equ       %00010000
mLDAT6_F11B1        equ       %00100000
mLDAT6_F11B2        equ       %01000000
mLDAT6_F11B3        equ       %10000000

;*** LDAT7 - LCD Data Register
LDAT7               equ       $00000058           ;*** LDAT7 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT7_F12B0         equ       0                   ; LCD Segment 12 Data Bit 0
LDAT7_F12B1         equ       1                   ; LCD Segment 12 Data Bit 1
LDAT7_F12B2         equ       2                   ; LCD Segment 12 Data Bit 2
LDAT7_F12B3         equ       3                   ; LCD Segment 12 Data Bit 3
LDAT7_F13B0         equ       4                   ; LCD Segment 13 Data Bit 0
LDAT7_F13B1         equ       5                   ; LCD Segment 13 Data Bit 1
LDAT7_F13B2         equ       6                   ; LCD Segment 13 Data Bit 2
LDAT7_F13B3         equ       7                   ; LCD Segment 13 Data Bit 3
; bit position masks
mLDAT7_F12B0        equ       %00000001
mLDAT7_F12B1        equ       %00000010
mLDAT7_F12B2        equ       %00000100
mLDAT7_F12B3        equ       %00001000
mLDAT7_F13B0        equ       %00010000
mLDAT7_F13B1        equ       %00100000
mLDAT7_F13B2        equ       %01000000
mLDAT7_F13B3        equ       %10000000

;*** LDAT8 - LCD Data Register
LDAT8               equ       $00000059           ;*** LDAT8 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT8_F14B0         equ       0                   ; LCD Segment 14 Data Bit 0
LDAT8_F14B1         equ       1                   ; LCD Segment 14 Data Bit 1
LDAT8_F14B2         equ       2                   ; LCD Segment 14 Data Bit 2
LDAT8_F14B3         equ       3                   ; LCD Segment 14 Data Bit 3
LDAT8_F15B0         equ       4                   ; LCD Segment 15 Data Bit 0
LDAT8_F15B1         equ       5                   ; LCD Segment 15 Data Bit 1
LDAT8_F15B2         equ       6                   ; LCD Segment 15 Data Bit 2
LDAT8_F15B3         equ       7                   ; LCD Segment 15 Data Bit 3
; bit position masks
mLDAT8_F14B0        equ       %00000001
mLDAT8_F14B1        equ       %00000010
mLDAT8_F14B2        equ       %00000100
mLDAT8_F14B3        equ       %00001000
mLDAT8_F15B0        equ       %00010000
mLDAT8_F15B1        equ       %00100000
mLDAT8_F15B2        equ       %01000000
mLDAT8_F15B3        equ       %10000000

;*** LDAT9 - LCD Data Register
LDAT9               equ       $0000005A           ;*** LDAT9 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT9_F16B0         equ       0                   ; LCD Segment 16 Data Bit 0
LDAT9_F16B1         equ       1                   ; LCD Segment 16 Data Bit 1
LDAT9_F16B2         equ       2                   ; LCD Segment 16 Data Bit 2
LDAT9_F16B3         equ       3                   ; LCD Segment 16 Data Bit 3
LDAT9_F17B0         equ       4                   ; LCD Segment 17 Data Bit 0
LDAT9_F17B1         equ       5                   ; LCD Segment 17 Data Bit 1
LDAT9_F17B2         equ       6                   ; LCD Segment 17 Data Bit 2
LDAT9_F17B3         equ       7                   ; LCD Segment 17 Data Bit 3
; bit position masks
mLDAT9_F16B0        equ       %00000001
mLDAT9_F16B1        equ       %00000010
mLDAT9_F16B2        equ       %00000100
mLDAT9_F16B3        equ       %00001000
mLDAT9_F17B0        equ       %00010000
mLDAT9_F17B1        equ       %00100000
mLDAT9_F17B2        equ       %01000000
mLDAT9_F17B3        equ       %10000000

;*** LDAT10 - LCD Data Register
LDAT10              equ       $0000005B           ;*** LDAT10 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT10_F18B0        equ       0                   ; LCD Segment 18 Data Bit 0
LDAT10_F18B1        equ       1                   ; LCD Segment 18 Data Bit 1
LDAT10_F18B2        equ       2                   ; LCD Segment 18 Data Bit 2
LDAT10_F18B3        equ       3                   ; LCD Segment 18 Data Bit 3
LDAT10_F19B0        equ       4                   ; LCD Segment 19 Data Bit 0
LDAT10_F19B1        equ       5                   ; LCD Segment 19 Data Bit 1
LDAT10_F19B2        equ       6                   ; LCD Segment 19 Data Bit 2
LDAT10_F19B3        equ       7                   ; LCD Segment 19 Data Bit 3
; bit position masks
mLDAT10_F18B0       equ       %00000001
mLDAT10_F18B1       equ       %00000010
mLDAT10_F18B2       equ       %00000100
mLDAT10_F18B3       equ       %00001000
mLDAT10_F19B0       equ       %00010000
mLDAT10_F19B1       equ       %00100000
mLDAT10_F19B2       equ       %01000000
mLDAT10_F19B3       equ       %10000000

;*** LDAT11 - LCD Data Register
LDAT11              equ       $0000005C           ;*** LDAT11 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT11_F20B0        equ       0                   ; LCD Segment 20 Data Bit 0
LDAT11_F20B1        equ       1                   ; LCD Segment 20 Data Bit 1
LDAT11_F20B2        equ       2                   ; LCD Segment 20 Data Bit 2
LDAT11_F20B3        equ       3                   ; LCD Segment 20 Data Bit 3
LDAT11_F21B0        equ       4                   ; LCD Segment 21 Data Bit 0
LDAT11_F21B1        equ       5                   ; LCD Segment 21 Data Bit 1
LDAT11_F21B2        equ       6                   ; LCD Segment 21 Data Bit 2
LDAT11_F21B3        equ       7                   ; LCD Segment 21 Data Bit 3
; bit position masks
mLDAT11_F20B0       equ       %00000001
mLDAT11_F20B1       equ       %00000010
mLDAT11_F20B2       equ       %00000100
mLDAT11_F20B3       equ       %00001000
mLDAT11_F21B0       equ       %00010000
mLDAT11_F21B1       equ       %00100000
mLDAT11_F21B2       equ       %01000000
mLDAT11_F21B3       equ       %10000000

;*** LDAT12 - LCD Data Register
LDAT12              equ       $0000005D           ;*** LDAT12 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT12_F22B0        equ       0                   ; LCD Segment 22 Data Bit 0
LDAT12_F22B1        equ       1                   ; LCD Segment 22 Data Bit 1
LDAT12_F22B2        equ       2                   ; LCD Segment 22 Data Bit 2
LDAT12_F22B3        equ       3                   ; LCD Segment 22 Data Bit 3
LDAT12_F23B0        equ       4                   ; LCD Segment 23 Data Bit 0
LDAT12_F23B1        equ       5                   ; LCD Segment 23 Data Bit 1
LDAT12_F23B2        equ       6                   ; LCD Segment 23 Data Bit 2
LDAT12_F23B3        equ       7                   ; LCD Segment 23 Data Bit 3
; bit position masks
mLDAT12_F22B0       equ       %00000001
mLDAT12_F22B1       equ       %00000010
mLDAT12_F22B2       equ       %00000100
mLDAT12_F22B3       equ       %00001000
mLDAT12_F23B0       equ       %00010000
mLDAT12_F23B1       equ       %00100000
mLDAT12_F23B2       equ       %01000000
mLDAT12_F23B3       equ       %10000000

;*** LDAT13 - LCD Data Register
LDAT13              equ       $0000005E           ;*** LDAT13 - LCD Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT13_F24B0        equ       0                   ; LCD Segment 24 Data Bit 0
LDAT13_F24B1        equ       1                   ; LCD Segment 24 Data Bit 1
LDAT13_F24B2        equ       2                   ; LCD Segment 24 Data Bit 2
LDAT13_F24B3        equ       3                   ; LCD Segment 24 Data Bit 3
; bit position masks
mLDAT13_F24B0       equ       %00000001
mLDAT13_F24B1       equ       %00000010
mLDAT13_F24B2       equ       %00000100
mLDAT13_F24B3       equ       %00001000

;*** SBSR - SIM Break Status Register
SBSR                equ       $0000FE00           ;*** SBSR - SIM Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBSR_SBSW           equ       1                   ; SIM Break Stop/Wait
; bit position masks
mSBSR_SBSW          equ       %00000010

;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset Bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
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
; bit position masks
mINT2_IF7           equ       %00000001
mINT2_IF8           equ       %00000010
mINT2_IF9           equ       %00000100
mINT2_IF10          equ       %00001000

;*** INT3 - Interrupt Status Register 3
INT3                equ       $0000FE06           ;*** INT3 - Interrupt Status Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT3_IF16           equ       1                   ; Interrupt Flag 16
; bit position masks
mINT3_IF16          equ       %00000010

;*** FLTCR - Test Flash Test Registers and Programming Sequence
FLTCR               equ       $0000FE07           ;*** FLTCR - Test Flash Test Registers and Programming Sequence
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLTCR_TMSE          equ       0                   ; Test Mode serial shift Enable
FLTCR_TMR           equ       1                   ; Test Mode Shift Register Reset
FLTCR_TMSO_TMSI     equ       2                   ; Test Mode Serial Data Out, Test Mode Serial Data In
FLTCR_REVTUN        equ       6                   ; Reverse Tunneling Bit
; bit position masks
mFLTCR_TMSE         equ       %00000001
mFLTCR_TMR          equ       %00000010
mFLTCR_TMSO_TMSI    equ       %00000100
mFLTCR_REVTUN       equ       %01000000

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

;*** BRKH - Break Address Register
BRKH                equ       $0000FE0C           ;*** BRKH - Break Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKH_BIT8           equ       0                   ; Break Address Register Bit
BRKH_BIT9           equ       1                   ; Break Address Register Bit
BRKH_BIT10          equ       2                   ; Break Address Register Bit
BRKH_BIT11          equ       3                   ; Break Address Register Bit
BRKH_BIT12          equ       4                   ; Break Address Register Bit
BRKH_BIT13          equ       5                   ; Break Address Register Bit
BRKH_BIT14          equ       6                   ; Break Address Register Bit
BRKH_BIT15          equ       7                   ; Break Address Register Bit
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
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKL_BIT0           equ       0                   ; Break Address Register Bit
BRKL_BIT1           equ       1                   ; Break Address Register Bit
BRKL_BIT2           equ       2                   ; Break Address Register Bit
BRKL_BIT3           equ       3                   ; Break Address Register Bit
BRKL_BIT4           equ       4                   ; Break Address Register Bit
BRKL_BIT5           equ       5                   ; Break Address Register Bit
BRKL_BIT6           equ       6                   ; Break Address Register Bit
BRKL_BIT7           equ       7                   ; Break Address Register Bit
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

;*** LVISR - LVI Status Register
LVISR               equ       $0000FE0F           ;*** LVISR - LVI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISR_LVIIAK        equ       4                   ; LVI Interrupt Acknowledge
LVISR_LVIIF         equ       5                   ; LVI Interrupt Flag
LVISR_LVIIE         equ       6                   ; LVI Interrupt Enable Bit
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LVIIAK       equ       %00010000
mLVISR_LVIIF        equ       %00100000
mLVISR_LVIIE        equ       %01000000
mLVISR_LVIOUT       equ       %10000000

;*** FLBPR - FLASH1 Block Protect Register
FLBPR               equ       $0000FF7E           ;*** FLBPR - FLASH1 Block Protect Register
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
;
; Follows changes from the database 2.89.053 version
 #ifndef __GENERATE_APPLICATION__
 #endif

; EOF
