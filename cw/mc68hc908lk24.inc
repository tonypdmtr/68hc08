;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908LK24_80, version 2.87.089 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908lk24.inc
;     Processor : MC68HC908LK24CPK
;     FileFormat: V2.28
;     DataSheet : MC68HC908LJ24/D Rev. 2.1 August 16, 2005
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
;      - 23.03.2006, V2.87.067:
;              - Renamed bits ADSCR_CHx ==> ADSCR_ADCHx. REASON: Bug-fix (#3140 in Issue Manager)
;      - 17.07.2007, V2.87.086:
;              - Corrected register FLBPR address (FECF ==>FFCF). REASON: Bug-fix (#4902 in Issue Manager)
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
ROM                 equ       $00009000
ROM_END             equ       $0000EFFF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000037F
;
INT_RTC             equ       $0000FFD8
INT_ADC             equ       $0000FFDA
INT_KBD             equ       $0000FFDC
INT_MMIIC           equ       $0000FFDE
INT_SCITransmit     equ       $0000FFE0
INT_SCIReceive      equ       $0000FFE2
INT_SCIError        equ       $0000FFE4
INT_SPIReceive      equ       $0000FFE6
INT_SPITransmit     equ       $0000FFE8
INT_TIM2Ovr         equ       $0000FFEA
INT_TIM2CH1         equ       $0000FFEC
INT_TIM2CH0         equ       $0000FFEE
INT_TIM1Ovr         equ       $0000FFF0
INT_TIM1CH1         equ       $0000FFF2
INT_TIM1CH0         equ       $0000FFF4
INT_PLL             equ       $0000FFF6
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


;*** PTE - Port E Data Register
PTE                 equ       $00000008           ;*** PTE - Port E Data Register
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


;*** DDRE - Data Direction Register E
DDRE                equ       $00000009           ;*** DDRE - Data Direction Register E
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


;*** PTF - Port F Data Register
PTF                 equ       $0000000A           ;*** PTF - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTF_PTF0            equ       0                   ; Port F Data Bit 0
PTF_PTF1            equ       1                   ; Port F Data Bit 1
PTF_PTF2            equ       2                   ; Port F Data Bit 2
PTF_PTF3            equ       3                   ; Port F Data Bit 3
PTF_PTF4            equ       4                   ; Port F Data Bit 4
PTF_PTF5            equ       5                   ; Port F Data Bit 5
PTF_PTF6            equ       6                   ; Port F Data Bit 6
PTF_PTF7            equ       7                   ; Port F Data Bit 7
; bit position masks
mPTF_PTF0           equ       %00000001
mPTF_PTF1           equ       %00000010
mPTF_PTF2           equ       %00000100
mPTF_PTF3           equ       %00001000
mPTF_PTF4           equ       %00010000
mPTF_PTF5           equ       %00100000
mPTF_PTF6           equ       %01000000
mPTF_PTF7           equ       %10000000


;*** DDRF - Data Direction Register F
DDRF                equ       $0000000B           ;*** DDRF - Data Direction Register F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRF_DDRF0          equ       0                   ; Data Direction Register F Bit 0
DDRF_DDRF1          equ       1                   ; Data Direction Register F Bit 1
DDRF_DDRF2          equ       2                   ; Data Direction Register F Bit 2
DDRF_DDRF3          equ       3                   ; Data Direction Register F Bit 3
DDRF_DDRF4          equ       4                   ; Data Direction Register F Bit 4
DDRF_DDRF5          equ       5                   ; Data Direction Register F Bit 5
DDRF_DDRF6          equ       6                   ; Data Direction Register F Bit 6
DDRF_DDRF7          equ       7                   ; Data Direction Register F Bit 7
; bit position masks
mDDRF_DDRF0         equ       %00000001
mDDRF_DDRF1         equ       %00000010
mDDRF_DDRF2         equ       %00000100
mDDRF_DDRF3         equ       %00001000
mDDRF_DDRF4         equ       %00010000
mDDRF_DDRF5         equ       %00100000
mDDRF_DDRF6         equ       %01000000
mDDRF_DDRF7         equ       %10000000


;*** LEDB - Port B LED Control Register
LEDB                equ       $0000000C           ;*** LEDB - Port B LED Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LEDB_LEDB0          equ       0                   ; Port B LED Drive Enable Bit 0
LEDB_LEDB1          equ       1                   ; Port B LED Drive Enable Bit 1
LEDB_LEDB2          equ       2                   ; Port B LED Drive Enable Bit 2
LEDB_LEDB3          equ       3                   ; Port B LED Drive Enable Bit 3
LEDB_LEDB4          equ       4                   ; Port B LED Drive Enable Bit 4
LEDB_LEDB5          equ       5                   ; Port B LED Drive Enable Bit 5
; bit position masks
mLEDB_LEDB0         equ       %00000001
mLEDB_LEDB1         equ       %00000010
mLEDB_LEDB2         equ       %00000100
mLEDB_LEDB3         equ       %00001000
mLEDB_LEDB4         equ       %00010000
mLEDB_LEDB5         equ       %00100000


;*** LEDC - Port C LED Control Register
LEDC                equ       $0000000D           ;*** LEDC - Port C LED Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LEDC_LEDC0          equ       0                   ; Port C LED Drive Enable Bit 0
LEDC_LEDC1          equ       1                   ; Port C LED Drive Enable Bit 1
LEDC_LEDC2          equ       2                   ; Port C LED Drive Enable Bit 2
LEDC_LEDC3          equ       3                   ; Port C LED Drive Enable Bit 3
LEDC_LEDC4          equ       4                   ; Port C LED Drive Enable Bit 4
LEDC_LEDC5          equ       5                   ; Port C LED Drive Enable Bit 5
LEDC_LEDC6          equ       6                   ; Port C LED Drive Enable Bit 6
LEDC_LEDC7          equ       7                   ; Port C LED Drive Enable Bit 7
; bit position masks
mLEDC_LEDC0         equ       %00000001
mLEDC_LEDC1         equ       %00000010
mLEDC_LEDC2         equ       %00000100
mLEDC_LEDC3         equ       %00001000
mLEDC_LEDC4         equ       %00010000
mLEDC_LEDC5         equ       %00100000
mLEDC_LEDC6         equ       %01000000
mLEDC_LEDC7         equ       %10000000


;*** LEDE - Port E LED Control Register
LEDE                equ       $0000000E           ;*** LEDE - Port E LED Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LEDE_LEDE0          equ       0                   ; Port E LED Drive Enable Bit 0
LEDE_LEDE1          equ       1                   ; Port E LED Drive Enable Bit 1
LEDE_LEDE2          equ       2                   ; Port E LED Drive Enable Bit 2
LEDE_LEDE3          equ       3                   ; Port E LED Drive Enable Bit 3
LEDE_LEDE4          equ       4                   ; Port E LED Drive Enable Bit 4
LEDE_LEDE5          equ       5                   ; Port E LED Drive Enable Bit 5
LEDE_LEDE6          equ       6                   ; Port E LED Drive Enable Bit 6
LEDE_LEDE7          equ       7                   ; Port E LED Drive Enable Bit 7
; bit position masks
mLEDE_LEDE0         equ       %00000001
mLEDE_LEDE1         equ       %00000010
mLEDE_LEDE2         equ       %00000100
mLEDE_LEDE3         equ       %00001000
mLEDE_LEDE4         equ       %00010000
mLEDE_LEDE5         equ       %00100000
mLEDE_LEDE6         equ       %01000000
mLEDE_LEDE7         equ       %10000000


;*** LEDF - Port F LED Control Register
LEDF                equ       $0000000F           ;*** LEDF - Port F LED Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LEDF_LEDF0          equ       0                   ; Port F LED Drive Enable Bit 0
LEDF_LEDF1          equ       1                   ; Port F LED Drive Enable Bit 1
LEDF_LEDF2          equ       2                   ; Port F LED Drive Enable Bit 2
LEDF_LEDF3          equ       3                   ; Port F LED Drive Enable Bit 3
LEDF_LEDF4          equ       4                   ; Port F LED Drive Enable Bit 4
LEDF_LEDF5          equ       5                   ; Port F LED Drive Enable Bit 5
LEDF_LEDF6          equ       6                   ; Port F LED Drive Enable Bit 6
LEDF_LEDF7          equ       7                   ; Port F LED Drive Enable Bit 7
; bit position masks
mLEDF_LEDF0         equ       %00000001
mLEDF_LEDF1         equ       %00000010
mLEDF_LEDF2         equ       %00000100
mLEDF_LEDF3         equ       %00001000
mLEDF_LEDF4         equ       %00010000
mLEDF_LEDF5         equ       %00100000
mLEDF_LEDF6         equ       %01000000
mLEDF_LEDF7         equ       %10000000


;*** SPCR - SPI Control Register
SPCR                equ       $00000010           ;*** SPCR - SPI Control Register
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
SPSCR               equ       $00000011           ;*** SPSCR - SPI Status and Control Register
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
SPDR                equ       $00000012           ;*** SPDR - SPI Data Register
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


;*** SCC1 - SCI Control Register 1
SCC1                equ       $00000013           ;*** SCC1 - SCI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC1_PTY            equ       0                   ; Parity Bit
SCC1_PEN            equ       1                   ; Parity Enable Bit
SCC1_ILTY           equ       2                   ; Idle Line Type Bit
SCC1_WAKE           equ       3                   ; Wakeup Condition Bit
SCC1_M              equ       4                   ; Mode (Character Length) Bit
SCC1_ENSCI          equ       6                   ; Enable SCI Bit
SCC1_LOOPS          equ       7                   ; Loop Mode Select Bit
; bit position masks
mSCC1_PTY           equ       %00000001
mSCC1_PEN           equ       %00000010
mSCC1_ILTY          equ       %00000100
mSCC1_WAKE          equ       %00001000
mSCC1_M             equ       %00010000
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
SCBR_CKS            equ       7                   ; Baud Clock Input Select
; bit position masks
mSCBR_SCR0          equ       %00000001
mSCBR_SCR1          equ       %00000010
mSCBR_SCR2          equ       %00000100
mSCBR_SCP0          equ       %00010000
mSCBR_SCP1          equ       %00100000
mSCBR_CKS           equ       %10000000


;*** SCIRCR - SCI Infrared Control Register
SCIRCR              equ       $0000001A           ;*** SCIRCR - SCI Infrared Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIRCR_IREN         equ       0                   ; Infrared Enable Bit
SCIRCR_TNP0         equ       1                   ; Transmitter Narrow Pulse Bit 0
SCIRCR_TNP1         equ       2                   ; Transmitter Narrow Pulse Bit 1
; bit position masks
mSCIRCR_IREN        equ       %00000001
mSCIRCR_TNP0        equ       %00000010
mSCIRCR_TNP1        equ       %00000100


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
KBIER_KBIE0         equ       0                   ; Keyboard Interrut Enable Bit 0
KBIER_KBIE1         equ       1                   ; Keyboard Interrut Enable Bit 1
KBIER_KBIE2         equ       2                   ; Keyboard Interrut Enable Bit 2
KBIER_KBIE3         equ       3                   ; Keyboard Interrut Enable Bit 3
KBIER_KBIE4         equ       4                   ; Keyboard Interrut Enable Bit 4
KBIER_KBIE5         equ       5                   ; Keyboard Interrut Enable Bit 5
KBIER_KBIE6         equ       6                   ; Keyboard Interrut Enable Bit 6
KBIER_KBIE7         equ       7                   ; Keyboard Interrut Enable Bit 7
; bit position masks
mKBIER_KBIE0        equ       %00000001
mKBIER_KBIE1        equ       %00000010
mKBIER_KBIE2        equ       %00000100
mKBIER_KBIE3        equ       %00001000
mKBIER_KBIE4        equ       %00010000
mKBIER_KBIE5        equ       %00100000
mKBIER_KBIE6        equ       %01000000
mKBIER_KBIE7        equ       %10000000


;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001D           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_LVISEL0     equ       0                   ; LVI Operating Mode Selection 0
CONFIG2_LVISEL1     equ       1                   ; LVI Operating Mode Selection 1
CONFIG2_PCEL        equ       2                   ; Port C Enable Low Nibble
CONFIG2_PCEH        equ       3                   ; Port C Enable High Nibble
CONFIG2_DIV2CLK     equ       4                   ; Divide-by-2 Clock Bypass
CONFIG2_STOP_XCLKEN equ       5                   ; Crystal Oscillator Stop Mode Enable
CONFIG2_STOP_IRCDIS equ       6                   ; Internal RC Oscillator Stop Mode Disable
CONFIG2_PEE         equ       7                   ; Port E Enable
; bit position masks
mCONFIG2_LVISEL0    equ       %00000001
mCONFIG2_LVISEL1    equ       %00000010
mCONFIG2_PCEL       equ       %00000100
mCONFIG2_PCEH       equ       %00001000
mCONFIG2_DIV2CLK    equ       %00010000
mCONFIG2_STOP_XCLKEN equ       %00100000
mCONFIG2_STOP_IRCDIS equ       %01000000
mCONFIG2_PEE        equ       %10000000


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


;*** T1CNTH - TIM1 Counter High Register
T1CNTH              equ       $00000021           ;*** T1CNTH - TIM1 Counter High Register


;*** T1CNTL - TIM1 Counter Low Register
T1CNTL              equ       $00000022           ;*** T1CNTL - TIM1 Counter Low Register


;*** T1MOD - TIM1 Counter Modulo Register
T1MOD               equ       $00000023           ;*** T1MOD - TIM1 Counter Modulo Register


;*** T1MODH - TIM1 Counter Modulo High Register
T1MODH              equ       $00000023           ;*** T1MODH - TIM1 Counter Modulo High Register


;*** T1MODL - TIM1 Counter Modulo Low Register
T1MODL              equ       $00000024           ;*** T1MODL - TIM1 Counter Modulo Low Register


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
T2SC                equ       $0000002B           ;*** T2SC - TIM2 Status and Control Register
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
T2CNT               equ       $0000002C           ;*** T2CNT - TIM2 Counter Register


;*** T2CNTH - TIM2 Counter High Register
T2CNTH              equ       $0000002C           ;*** T2CNTH - TIM2 Counter High Register


;*** T2CNTL - TIM2 Counter Low Register
T2CNTL              equ       $0000002D           ;*** T2CNTL - TIM2 Counter Low Register


;*** T2MOD - TIM2 Counter Modulo Register
T2MOD               equ       $0000002E           ;*** T2MOD - TIM2 Counter Modulo Register


;*** T2MODH - TIM2 Counter Modulo High Register
T2MODH              equ       $0000002E           ;*** T2MODH - TIM2 Counter Modulo High Register


;*** T2MODL - TIM2 Counter Modulo Low Register
T2MODL              equ       $0000002F           ;*** T2MODL - TIM2 Counter Modulo Low Register


;*** T2SC0 - TIM2 Channel 0 Status and Control Register
T2SC0               equ       $00000030           ;*** T2SC0 - TIM2 Channel 0 Status and Control Register
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
T2CH0               equ       $00000031           ;*** T2CH0 - TIM2 Channel 0 Register


;*** T2CH0H - TIM2 Channel 0 Register High
T2CH0H              equ       $00000031           ;*** T2CH0H - TIM2 Channel 0 Register High


;*** T2CH0L - TIM2 Channel 0 Register Low
T2CH0L              equ       $00000032           ;*** T2CH0L - TIM2 Channel 0 Register Low


;*** T2SC1 - TIM2 Channel 1 Status and Control Register
T2SC1               equ       $00000033           ;*** T2SC1 - TIM2 Channel 1 Status and Control Register
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
T2CH1               equ       $00000034           ;*** T2CH1 - TIM2 Channel 1 Register


;*** T2CH1H - TIM2 Channel 1 Register High
T2CH1H              equ       $00000034           ;*** T2CH1H - TIM2 Channel 1 Register High


;*** T2CH1L - TIM2 Channel 1 Register Low
T2CH1L              equ       $00000035           ;*** T2CH1L - TIM2 Channel 1 Register Low


;*** PCTL - PLL Control Register
PCTL                equ       $00000036           ;*** PCTL - PLL Control Register
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
PBWC                equ       $00000037           ;*** PBWC - PLL Bandwidth Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PBWC_ACQ            equ       5                   ; Automatic Bandwidth Control Bit
PBWC_LOCK           equ       6                   ; Lock Indicator Bit
PBWC_AUTO           equ       7                   ; Acquisiton Mode Bit
; bit position masks
mPBWC_ACQ           equ       %00100000
mPBWC_LOCK          equ       %01000000
mPBWC_AUTO          equ       %10000000


;*** PMS - PLL Multiplier Select Register
PMS                 equ       $00000038           ;*** PMS - PLL Multiplier Select Register


;*** PMSH - PLL Multiplier Select Register High
PMSH                equ       $00000038           ;*** PMSH - PLL Multiplier Select Register High
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
PMSL                equ       $00000039           ;*** PMSL - PLL Multiplier Select Register Low
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
PMRS                equ       $0000003A           ;*** PMRS - PLL VCO Range Select
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
PMDS                equ       $0000003B           ;*** PMDS - PLL Reference Divider Select Register
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


;*** ADR - ADC Data Register - Right-justified
ADR                 equ       $0000003D           ;*** ADR - ADC Data Register - Right-justified


;*** ADRH - ADC Data Register High - Right-justified mode
ADRH                equ       $0000003D           ;*** ADRH - ADC Data Register High - Right-justified mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_BIT8           equ       0                   ; ADC Data Bit 8
ADRH_BIT9           equ       1                   ; ADC Data Bit 9
ADRH_BIT10          equ       2                   ; ADC Data Bit 10
ADRH_BIT11          equ       3                   ; ADC Data Bit 11
ADRH_BIT12          equ       4                   ; ADC Data Bit 12
ADRH_BIT13          equ       5                   ; ADC Data Bit 13
ADRH_BIT14          equ       6                   ; ADC Data Bit 14
ADRH_BIT15          equ       7                   ; ADC Data Bit 15
; bit position masks
mADRH_BIT8          equ       %00000001
mADRH_BIT9          equ       %00000010
mADRH_BIT10         equ       %00000100
mADRH_BIT11         equ       %00001000
mADRH_BIT12         equ       %00010000
mADRH_BIT13         equ       %00100000
mADRH_BIT14         equ       %01000000
mADRH_BIT15         equ       %10000000


;*** ADRL - ADC Data Register Low - Right-justified mode
ADRL                equ       $0000003E           ;*** ADRL - ADC Data Register Low - Right-justified mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRL_BIT0           equ       0                   ; ADC Data Bit 0
ADRL_BIT1           equ       1                   ; ADC Data Bit 1
ADRL_BIT2           equ       2                   ; ADC Data Bit 2
ADRL_BIT3           equ       3                   ; ADC Data Bit 3
ADRL_BIT4           equ       4                   ; ADC Data Bit 4
ADRL_BIT5           equ       5                   ; ADC Data Bit 5
ADRL_BIT6           equ       6                   ; ADC Data Bit 6
ADRL_BIT7           equ       7                   ; ADC Data Bit 7
; bit position masks
mADRL_BIT0          equ       %00000001
mADRL_BIT1          equ       %00000010
mADRL_BIT2          equ       %00000100
mADRL_BIT3          equ       %00001000
mADRL_BIT4          equ       %00010000
mADRL_BIT5          equ       %00100000
mADRL_BIT6          equ       %01000000
mADRL_BIT7          equ       %10000000


;*** ADCLK - ADC Input Clock Register
ADCLK               equ       $0000003F           ;*** ADCLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_MODE0         equ       2                   ; Modes of Result Justification Bit 0
ADCLK_MODE1         equ       3                   ; Modes of Result Justification Bit 1
ADCLK_ADICLK        equ       4                   ; ADC Input Clock Register Bit
ADCLK_ADIV0         equ       5                   ; ADC Clock Prescaler Bit 0
ADCLK_ADIV1         equ       6                   ; ADC Clock Prescaler Bit 1
ADCLK_ADIV2         equ       7                   ; ADC Clock Prescaler Bit 2
; bit position masks
mADCLK_MODE0        equ       %00000100
mADCLK_MODE1        equ       %00001000
mADCLK_ADICLK       equ       %00010000
mADCLK_ADIV0        equ       %00100000
mADCLK_ADIV1        equ       %01000000
mADCLK_ADIV2        equ       %10000000


;*** RTCCOMR - RTC Calibration Control Register
RTCCOMR             equ       $00000040           ;*** RTCCOMR - RTC Calibration Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCCOMR_RTCWE0      equ       0                   ; RTC module write enable status Bit 0
RTCCOMR_RTCWE1      equ       1                   ; RTC module write enable status Bit 1
RTCCOMR_OUTF0       equ       2                   ; Calibration mode clock output selection Bit 0
RTCCOMR_OUTF1       equ       3                   ; Calibration mode clock output selection Bit 1
RTCCOMR_AUTOCAL     equ       4                   ; RTC Automatic Calibration Enable
RTCCOMR_CAL         equ       5                   ; RTC Calibration Mode
; bit position masks
mRTCCOMR_RTCWE0     equ       %00000001
mRTCCOMR_RTCWE1     equ       %00000010
mRTCCOMR_OUTF0      equ       %00000100
mRTCCOMR_OUTF1      equ       %00001000
mRTCCOMR_AUTOCAL    equ       %00010000
mRTCCOMR_CAL        equ       %00100000


;*** RTCCDAT - RTC Calibration Data Register
RTCCDAT             equ       $00000041           ;*** RTCCDAT - RTC Calibration Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCCDAT_E0          equ       0                   ; RTC compensation value Bit 0
RTCCDAT_E1          equ       1                   ; RTC compensation value Bit 1
RTCCDAT_E2          equ       2                   ; RTC compensation value Bit 2
RTCCDAT_E3          equ       3                   ; RTC compensation value Bit 3
RTCCDAT_E4          equ       4                   ; RTC compensation value Bit 4
RTCCDAT_E5          equ       5                   ; RTC compensation value Bit 5
RTCCDAT_EOVL        equ       7                   ; E register overflow
; bit position masks
mRTCCDAT_E0         equ       %00000001
mRTCCDAT_E1         equ       %00000010
mRTCCDAT_E2         equ       %00000100
mRTCCDAT_E3         equ       %00001000
mRTCCDAT_E4         equ       %00010000
mRTCCDAT_E5         equ       %00100000
mRTCCDAT_EOVL       equ       %10000000


;*** RTCCR1 - RTC Control Register 1
RTCCR1              equ       $00000042           ;*** RTCCR1 - RTC Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCCR1_TB2IE        equ       0                   ; Timebase 2 Interrupt Enable
RTCCR1_TB1IE        equ       1                   ; Timebase 1 Interrupt Enable
RTCCR1_SECIE        equ       2                   ; Second Interrupt Enable
RTCCR1_MINIE        equ       3                   ; Minute Interrupt Enable
RTCCR1_HRIE         equ       4                   ; Hour Interrupt Enable
RTCCR1_DAYIE        equ       5                   ; Day Interrupt Enable
RTCCR1_CHRIE        equ       6                   ; Chronograph Interrupt Enable
RTCCR1_ALMIE        equ       7                   ; Alarm Interrupt Enable
; bit position masks
mRTCCR1_TB2IE       equ       %00000001
mRTCCR1_TB1IE       equ       %00000010
mRTCCR1_SECIE       equ       %00000100
mRTCCR1_MINIE       equ       %00001000
mRTCCR1_HRIE        equ       %00010000
mRTCCR1_DAYIE       equ       %00100000
mRTCCR1_CHRIE       equ       %01000000
mRTCCR1_ALMIE       equ       %10000000


;*** RTCCR2 - RTC Control Register 2
RTCCR2              equ       $00000043           ;*** RTCCR2 - RTC Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCCR2_TBH          equ       3                   ; Timebase High Frequency Set Select
RTCCR2_RTCE         equ       4                   ; Real Time Clock Enable
RTCCR2_CHRE         equ       5                   ; Chronograph Enable
RTCCR2_CHRCLR       equ       6                   ; Chronograph Counter Clear
RTCCR2_COMEN        equ       7                   ; Crystal Frequency Select Bit 0
; bit position masks
mRTCCR2_TBH         equ       %00001000
mRTCCR2_RTCE        equ       %00010000
mRTCCR2_CHRE        equ       %00100000
mRTCCR2_CHRCLR      equ       %01000000
mRTCCR2_COMEN       equ       %10000000


;*** RTCSR - RTC Status Register
RTCSR               equ       $00000044           ;*** RTCSR - RTC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCSR_TB2F          equ       0                   ; Timebase 2 Flag
RTCSR_TB1F          equ       1                   ; Timebase 1 Flag
RTCSR_SECF          equ       2                   ; Second Flag
RTCSR_MINF          equ       3                   ; Minute Flag
RTCSR_HRF           equ       4                   ; Hour Flag
RTCSR_DAYF          equ       5                   ; Day Flag
RTCSR_CHRF          equ       6                   ; Chronograph Flag
RTCSR_ALMF          equ       7                   ; Alarm Flag
; bit position masks
mRTCSR_TB2F         equ       %00000001
mRTCSR_TB1F         equ       %00000010
mRTCSR_SECF         equ       %00000100
mRTCSR_MINF         equ       %00001000
mRTCSR_HRF          equ       %00010000
mRTCSR_DAYF         equ       %00100000
mRTCSR_CHRF         equ       %01000000
mRTCSR_ALMF         equ       %10000000


;*** ALMR - Alarm Minute Register
ALMR                equ       $00000045           ;*** ALMR - Alarm Minute Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ALMR_AM0            equ       0                   ; Alarm Minute Bit 0
ALMR_AM1            equ       1                   ; Alarm Minute Bit 1
ALMR_AM2            equ       2                   ; Alarm Minute Bit 2
ALMR_AM3            equ       3                   ; Alarm Minute Bit 3
ALMR_AM4            equ       4                   ; Alarm Minute Bit 4
ALMR_AM5            equ       5                   ; Alarm Minute Bit 5
; bit position masks
mALMR_AM0           equ       %00000001
mALMR_AM1           equ       %00000010
mALMR_AM2           equ       %00000100
mALMR_AM3           equ       %00001000
mALMR_AM4           equ       %00010000
mALMR_AM5           equ       %00100000


;*** ALHR - Alarm Hour Register
ALHR                equ       $00000046           ;*** ALHR - Alarm Hour Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ALHR_AH0            equ       0                   ; Alarm Hour Bit 0
ALHR_AH1            equ       1                   ; Alarm Hour Bit 1
ALHR_AH2            equ       2                   ; Alarm Hour Bit 2
ALHR_AH3            equ       3                   ; Alarm Hour Bit 3
ALHR_AH4            equ       4                   ; Alarm Hour Bit 4
; bit position masks
mALHR_AH0           equ       %00000001
mALHR_AH1           equ       %00000010
mALHR_AH2           equ       %00000100
mALHR_AH3           equ       %00001000
mALHR_AH4           equ       %00010000


;*** SECR - Second Register
SECR                equ       $00000047           ;*** SECR - Second Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SECR_SEC0           equ       0                   ; Second Bit 0
SECR_SEC1           equ       1                   ; Second Bit 1
SECR_SEC2           equ       2                   ; Second Bit 2
SECR_SEC3           equ       3                   ; Second Bit 3
SECR_SEC4           equ       4                   ; Second Bit 4
SECR_SEC5           equ       5                   ; Second Bit 5
; bit position masks
mSECR_SEC0          equ       %00000001
mSECR_SEC1          equ       %00000010
mSECR_SEC2          equ       %00000100
mSECR_SEC3          equ       %00001000
mSECR_SEC4          equ       %00010000
mSECR_SEC5          equ       %00100000


;*** MINR - Minute Register
MINR                equ       $00000048           ;*** MINR - Minute Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MINR_MIN0           equ       0                   ; Minute Bit 0
MINR_MIN1           equ       1                   ; Minute Bit 1
MINR_MIN2           equ       2                   ; Minute Bit 2
MINR_MIN3           equ       3                   ; Minute Bit 3
MINR_MIN4           equ       4                   ; Minute Bit 4
MINR_MIN5           equ       5                   ; Minute Bit 5
; bit position masks
mMINR_MIN0          equ       %00000001
mMINR_MIN1          equ       %00000010
mMINR_MIN2          equ       %00000100
mMINR_MIN3          equ       %00001000
mMINR_MIN4          equ       %00010000
mMINR_MIN5          equ       %00100000


;*** HRR - Hour Register
HRR                 equ       $00000049           ;*** HRR - Hour Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRR_HR0             equ       0                   ; Hour Bit 0
HRR_HR1             equ       1                   ; Hour Bit 1
HRR_HR2             equ       2                   ; Hour Bit 2
HRR_HR3             equ       3                   ; Hour Bit 3
HRR_HR4             equ       4                   ; Hour Bit 4
; bit position masks
mHRR_HR0            equ       %00000001
mHRR_HR1            equ       %00000010
mHRR_HR2            equ       %00000100
mHRR_HR3            equ       %00001000
mHRR_HR4            equ       %00010000


;*** DAYR - Day Register
DAYR                equ       $0000004A           ;*** DAYR - Day Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DAYR_DAY0           equ       0                   ; Day Bit 0
DAYR_DAY1           equ       1                   ; Day Bit 1
DAYR_DAY2           equ       2                   ; Day Bit 2
DAYR_DAY3           equ       3                   ; Day Bit 3
DAYR_DAY4           equ       4                   ; Day Bit 4
; bit position masks
mDAYR_DAY0          equ       %00000001
mDAYR_DAY1          equ       %00000010
mDAYR_DAY2          equ       %00000100
mDAYR_DAY3          equ       %00001000
mDAYR_DAY4          equ       %00010000


;*** MTHR - Monh Register
MTHR                equ       $0000004B           ;*** MTHR - Monh Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTHR_MTH0           equ       0                   ; Month Bit 0
MTHR_MTH1           equ       1                   ; Month Bit 1
MTHR_MTH2           equ       2                   ; Month Bit 2
MTHR_MTH3           equ       3                   ; Month Bit 3
; bit position masks
mMTHR_MTH0          equ       %00000001
mMTHR_MTH1          equ       %00000010
mMTHR_MTH2          equ       %00000100
mMTHR_MTH3          equ       %00001000


;*** YRR - Year Register
YRR                 equ       $0000004C           ;*** YRR - Year Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
YRR_YR0             equ       0                   ; Year Bit 0
YRR_YR1             equ       1                   ; Year Bit 1
YRR_YR2             equ       2                   ; Year Bit 2
YRR_YR3             equ       3                   ; Year Bit 3
YRR_YR4             equ       4                   ; Year Bit 4
YRR_YR5             equ       5                   ; Year Bit 5
YRR_YR6             equ       6                   ; Year Bit 6
YRR_YR7             equ       7                   ; Year Bit 7
; bit position masks
mYRR_YR0            equ       %00000001
mYRR_YR1            equ       %00000010
mYRR_YR2            equ       %00000100
mYRR_YR3            equ       %00001000
mYRR_YR4            equ       %00010000
mYRR_YR5            equ       %00100000
mYRR_YR6            equ       %01000000
mYRR_YR7            equ       %10000000


;*** DOWR - Day-Of-Week Register
DOWR                equ       $0000004D           ;*** DOWR - Day-Of-Week Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DOWR_DOW0           equ       0                   ; Day-Of-Week Bit 0
DOWR_DOW1           equ       1                   ; Day-Of-Week Bit 1
DOWR_DOW2           equ       2                   ; Day-Of-Week Bit 2
; bit position masks
mDOWR_DOW0          equ       %00000001
mDOWR_DOW1          equ       %00000010
mDOWR_DOW2          equ       %00000100


;*** CHRR - Chronograph Data Register
CHRR                equ       $0000004E           ;*** CHRR - Chronograph Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CHRR_CHR0           equ       0                   ; Chronograph Bit 0
CHRR_CHR1           equ       1                   ; Chronograph Bit 1
CHRR_CHR2           equ       2                   ; Chronograph Bit 2
CHRR_CHR3           equ       3                   ; Chronograph Bit 3
CHRR_CHR4           equ       4                   ; Chronograph Bit 4
CHRR_CHR5           equ       5                   ; Chronograph Bit 5
CHRR_CHR6           equ       6                   ; Chronograph Bit 6
; bit position masks
mCHRR_CHR0          equ       %00000001
mCHRR_CHR1          equ       %00000010
mCHRR_CHR2          equ       %00000100
mCHRR_CHR3          equ       %00001000
mCHRR_CHR4          equ       %00010000
mCHRR_CHR5          equ       %00100000
mCHRR_CHR6          equ       %01000000


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


;*** LDAT1 - LCD Data Register 1
LDAT1               equ       $00000052           ;*** LDAT1 - LCD Data Register 1
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


;*** LDAT2 - LCD Data Register 2
LDAT2               equ       $00000053           ;*** LDAT2 - LCD Data Register 2
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


;*** LDAT3 - LCD Data Register 3
LDAT3               equ       $00000054           ;*** LDAT3 - LCD Data Register 3
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


;*** LDAT4 - LCD Data Register 4
LDAT4               equ       $00000055           ;*** LDAT4 - LCD Data Register 4
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


;*** LDAT5 - LCD Data Register 5
LDAT5               equ       $00000056           ;*** LDAT5 - LCD Data Register 5
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


;*** LDAT6 - LCD Data Register 6
LDAT6               equ       $00000057           ;*** LDAT6 - LCD Data Register 6
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


;*** LDAT7 - LCD Data Register 7
LDAT7               equ       $00000058           ;*** LDAT7 - LCD Data Register 7
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


;*** LDAT8 - LCD Data Register 8
LDAT8               equ       $00000059           ;*** LDAT8 - LCD Data Register 8
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


;*** LDAT9 - LCD Data Register 9
LDAT9               equ       $0000005A           ;*** LDAT9 - LCD Data Register 9
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


;*** LDAT10 - LCD Data Register 10
LDAT10              equ       $0000005B           ;*** LDAT10 - LCD Data Register 10
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


;*** LDAT11 - LCD Data Register 11
LDAT11              equ       $0000005C           ;*** LDAT11 - LCD Data Register 11
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


;*** LDAT12 - LCD Data Register 12
LDAT12              equ       $0000005D           ;*** LDAT12 - LCD Data Register 12
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


;*** LDAT13 - LCD Data Register 13
LDAT13              equ       $0000005E           ;*** LDAT13 - LCD Data Register 13
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT13_F24B0        equ       0                   ; LCD Segment 24 Data Bit 0
LDAT13_F24B1        equ       1                   ; LCD Segment 24 Data Bit 1
LDAT13_F24B2        equ       2                   ; LCD Segment 24 Data Bit 2
LDAT13_F24B3        equ       3                   ; LCD Segment 24 Data Bit 3
LDAT13_F25B0        equ       4                   ; LCD Segment 25 Data Bit 0
LDAT13_F25B1        equ       5                   ; LCD Segment 25 Data Bit 1
LDAT13_F25B2        equ       6                   ; LCD Segment 25 Data Bit 2
LDAT13_F25B3        equ       7                   ; LCD Segment 25 Data Bit 3
; bit position masks
mLDAT13_F24B0       equ       %00000001
mLDAT13_F24B1       equ       %00000010
mLDAT13_F24B2       equ       %00000100
mLDAT13_F24B3       equ       %00001000
mLDAT13_F25B0       equ       %00010000
mLDAT13_F25B1       equ       %00100000
mLDAT13_F25B2       equ       %01000000
mLDAT13_F25B3       equ       %10000000


;*** LDAT14 - LCD Data Register 14
LDAT14              equ       $0000005F           ;*** LDAT14 - LCD Data Register 14
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT14_F26B0        equ       0                   ; LCD Segment 26 Data Bit 0
LDAT14_F26B1        equ       1                   ; LCD Segment 26 Data Bit 1
LDAT14_F26B2        equ       2                   ; LCD Segment 26 Data Bit 2
LDAT14_F26B3        equ       3                   ; LCD Segment 26 Data Bit 3
LDAT14_F27B0        equ       4                   ; LCD Segment 27 Data Bit 0
LDAT14_F27B1        equ       5                   ; LCD Segment 27 Data Bit 1
LDAT14_F27B2        equ       6                   ; LCD Segment 27 Data Bit 2
LDAT14_F27B3        equ       7                   ; LCD Segment 27 Data Bit 3
; bit position masks
mLDAT14_F26B0       equ       %00000001
mLDAT14_F26B1       equ       %00000010
mLDAT14_F26B2       equ       %00000100
mLDAT14_F26B3       equ       %00001000
mLDAT14_F27B0       equ       %00010000
mLDAT14_F27B1       equ       %00100000
mLDAT14_F27B2       equ       %01000000
mLDAT14_F27B3       equ       %10000000


;*** LDAT15 - LCD Data Register 15
LDAT15              equ       $00000060           ;*** LDAT15 - LCD Data Register 15
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT15_F28B0        equ       0                   ; LCD Segment 28 Data Bit 0
LDAT15_F28B1        equ       1                   ; LCD Segment 28 Data Bit 1
LDAT15_F28B2        equ       2                   ; LCD Segment 28 Data Bit 2
LDAT15_F28B3        equ       3                   ; LCD Segment 28 Data Bit 3
LDAT15_F29B0        equ       4                   ; LCD Segment 29 Data Bit 0
LDAT15_F29B1        equ       5                   ; LCD Segment 29 Data Bit 1
LDAT15_F29B2        equ       6                   ; LCD Segment 29 Data Bit 2
LDAT15_F29B3        equ       7                   ; LCD Segment 29 Data Bit 3
; bit position masks
mLDAT15_F28B0       equ       %00000001
mLDAT15_F28B1       equ       %00000010
mLDAT15_F28B2       equ       %00000100
mLDAT15_F28B3       equ       %00001000
mLDAT15_F29B0       equ       %00010000
mLDAT15_F29B1       equ       %00100000
mLDAT15_F29B2       equ       %01000000
mLDAT15_F29B3       equ       %10000000


;*** LDAT16 - LCD Data Register 16
LDAT16              equ       $00000061           ;*** LDAT16 - LCD Data Register 16
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT16_F30B0        equ       0                   ; LCD Segment 30 Data Bit 0
LDAT16_F30B1        equ       1                   ; LCD Segment 30 Data Bit 1
LDAT16_F30B2        equ       2                   ; LCD Segment 30 Data Bit 2
LDAT16_F30B3        equ       3                   ; LCD Segment 30 Data Bit 3
LDAT16_F31B0        equ       4                   ; LCD Segment 31 Data Bit 0
LDAT16_F31B1        equ       5                   ; LCD Segment 31 Data Bit 1
LDAT16_F31B2        equ       6                   ; LCD Segment 31 Data Bit 2
LDAT16_F31B3        equ       7                   ; LCD Segment 31 Data Bit 3
; bit position masks
mLDAT16_F30B0       equ       %00000001
mLDAT16_F30B1       equ       %00000010
mLDAT16_F30B2       equ       %00000100
mLDAT16_F30B3       equ       %00001000
mLDAT16_F31B0       equ       %00010000
mLDAT16_F31B1       equ       %00100000
mLDAT16_F31B2       equ       %01000000
mLDAT16_F31B3       equ       %10000000


;*** LDAT17 - LCD Data Register 17
LDAT17              equ       $00000062           ;*** LDAT17 - LCD Data Register 17
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LDAT17_F32B0        equ       0                   ; LCD Segment 32 Data Bit 0
LDAT17_F32B1        equ       1                   ; LCD Segment 32 Data Bit 1
LDAT17_F32B2        equ       2                   ; LCD Segment 32 Data Bit 2
LDAT17_F32B3        equ       3                   ; LCD Segment 32 Data Bit 3
; bit position masks
mLDAT17_F32B0       equ       %00000001
mLDAT17_F32B1       equ       %00000010
mLDAT17_F32B2       equ       %00000100
mLDAT17_F32B3       equ       %00001000


;*** MIMCR - Multi-Master IIC Master Control Register
MIMCR               equ       $0000006A           ;*** MIMCR - Multi-Master IIC Master Control Register
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
MMADR               equ       $0000006B           ;*** MMADR - Multi-Master IIC Address Register
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
MMCR                equ       $0000006C           ;*** MMCR - Multi-Master IIC Control Register
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
MMSR                equ       $0000006D           ;*** MMSR - Multi-Master IIC Status Register
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
MMDTR               equ       $0000006E           ;*** MMDTR - Multi-Master IIC Data Transmit Register
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
MMDRR               equ       $0000006F           ;*** MMDRR - Multi-Master IIC Data Receive Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMDRR_MMTD0         equ       0                   ; Data Bit 0
MMDRR_MMTD1         equ       1                   ; Data Bit 1
MMDRR_MMTD2         equ       2                   ; Data Bit 2
MMDRR_MMTD3         equ       3                   ; Data Bit 3
MMDRR_MMTD4         equ       4                   ; Data Bit 4
MMDRR_MMTD5         equ       5                   ; Data Bit 5
MMDRR_MMTD6         equ       6                   ; Data Bit 6
MMDRR_MMTD7         equ       7                   ; Data Bit 7
; bit position masks
mMMDRR_MMTD0        equ       %00000001
mMMDRR_MMTD1        equ       %00000010
mMMDRR_MMTD2        equ       %00000100
mMMDRR_MMTD3        equ       %00001000
mMMDRR_MMTD4        equ       %00010000
mMMDRR_MMTD5        equ       %00100000
mMMDRR_MMTD6        equ       %01000000
mMMDRR_MMTD7        equ       %10000000


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
; bit position masks
mINT3_IF15          equ       %00000001
mINT3_IF16          equ       %00000010
mINT3_IF17          equ       %00000100
mINT3_IF18          equ       %00001000


;*** FLCR - FLASH Control Register
FLCR                equ       $0000FE08           ;*** FLCR - FLASH Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_ERASE          equ       1                   ; Erase Control Bit
FLCR_MARGIN         equ       2                   ; Margin Read Control Bit
FLCR_HVEN           equ       3                   ; High-Voltage Enable Bit
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_ERASE         equ       %00000010
mFLCR_MARGIN        equ       %00000100
mFLCR_HVEN          equ       %00001000


;*** BRK - Break Address Register
BRK                 equ       $0000FE0C           ;*** BRK - Break Address Register


;*** BRKH - Break Address High Register
BRKH                equ       $0000FE0C           ;*** BRKH - Break Address High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKH_MUL8           equ       0                   ; Break Address Register Bit 8
BRKH_MUL9           equ       1                   ; Break Address Register Bit 9
BRKH_MUL10          equ       2                   ; Break Address Register Bit 10
BRKH_MUL11          equ       3                   ; Break Address Register Bit 11
BRKH_MUL12          equ       4                   ; Break Address Register Bit 12
BRKH_MUL13          equ       5                   ; Break Address Register Bit 13
BRKH_MUL14          equ       6                   ; Break Address Register Bit 14
BRKH_MUL15          equ       7                   ; Break Address Register Bit 15
; bit position masks
mBRKH_MUL8          equ       %00000001
mBRKH_MUL9          equ       %00000010
mBRKH_MUL10         equ       %00000100
mBRKH_MUL11         equ       %00001000
mBRKH_MUL12         equ       %00010000
mBRKH_MUL13         equ       %00100000
mBRKH_MUL14         equ       %01000000
mBRKH_MUL15         equ       %10000000


;*** BRKL - Break Address Low Register
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKL_MUL0           equ       0                   ; Break Address Register Bit 0
BRKL_MUL1           equ       1                   ; Break Address Register Bit 1
BRKL_MUL2           equ       2                   ; Break Address Register Bit 2
BRKL_MUL3           equ       3                   ; Break Address Register Bit 3
BRKL_MUL4           equ       4                   ; Break Address Register Bit 4
BRKL_MUL5           equ       5                   ; Break Address Register Bit 5
BRKL_MUL6           equ       6                   ; Break Address Register Bit 6
BRKL_MUL7           equ       7                   ; Break Address Register Bit 7
; bit position masks
mBRKL_MUL0          equ       %00000001
mBRKL_MUL1          equ       %00000010
mBRKL_MUL2          equ       %00000100
mBRKL_MUL3          equ       %00001000
mBRKL_MUL4          equ       %00010000
mBRKL_MUL5          equ       %00100000
mBRKL_MUL6          equ       %01000000
mBRKL_MUL7          equ       %10000000


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
; Follows changes from the database 2.87.066 version
mADSCR_CH0          equ       mADSCR_ADCH0
mADSCR_CH1          equ       mADSCR_ADCH1
mADSCR_CH2          equ       mADSCR_ADCH2
mADSCR_CH3          equ       mADSCR_ADCH3
mADSCR_CH4          equ       mADSCR_ADCH4
ADSCR_CH0           equ       ADSCR_ADCH0
ADSCR_CH1           equ       ADSCR_ADCH1
ADSCR_CH2           equ       ADSCR_ADCH2
ADSCR_CH3           equ       ADSCR_ADCH3
ADSCR_CH4           equ       ADSCR_ADCH4

; EOF
