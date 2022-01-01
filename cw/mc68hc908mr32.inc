;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908MR32_64, version 2.89.077 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908mr32.inc
;     Processor : MC68HC908MR32CFU
;     FileFormat: V2.28
;     DataSheet : MC68HC908MR32 Rev. 6.1 07/2005
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
ROM                 equ       $00008000
ROM_END             equ       $0000FDFF
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000035F
;
INT_SCITransmit     equ       $0000FFD2
INT_SCIReceive      equ       $0000FFD4
INT_SCIError        equ       $0000FFD6
INT_SPITransmit     equ       $0000FFD8
INT_SPIReceive      equ       $0000FFDA
INT_ADC             equ       $0000FFDC
INT_TIMBOvr         equ       $0000FFDE
INT_TIMBCH1         equ       $0000FFE0
INT_TIMBCH0         equ       $0000FFE2
INT_TIMAOvr         equ       $0000FFE4
INT_TIMACH3         equ       $0000FFE6
INT_TIMACH2         equ       $0000FFE8
INT_TIMACH1         equ       $0000FFEA
INT_TIMACH0         equ       $0000FFEC
INT_PWMMC           equ       $0000FFEE
INT_FAULT4          equ       $0000FFF0
INT_FAULT3          equ       $0000FFF2
INT_FAULT2          equ       $0000FFF4
INT_FAULT1          equ       $0000FFF6
INT_PLL             equ       $0000FFF8
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
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010
mPTC_PTC2           equ       %00000100
mPTC_PTC3           equ       %00001000
mPTC_PTC4           equ       %00010000
mPTC_PTC5           equ       %00100000
mPTC_PTC6           equ       %01000000

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
; bit position masks
mPTD_PTD0           equ       %00000001
mPTD_PTD1           equ       %00000010
mPTD_PTD2           equ       %00000100
mPTD_PTD3           equ       %00001000
mPTD_PTD4           equ       %00010000
mPTD_PTD5           equ       %00100000
mPTD_PTD6           equ       %01000000

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
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000
mDDRC_DDRC4         equ       %00010000
mDDRC_DDRC5         equ       %00100000
mDDRC_DDRC6         equ       %01000000

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

;*** PTF - Port F Data Register
PTF                 equ       $00000009           ;*** PTF - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTF_PTF0            equ       0                   ; Port F Data Bit 0
PTF_PTF1            equ       1                   ; Port F Data Bit 1
PTF_PTF2            equ       2                   ; Port F Data Bit 2
PTF_PTF3            equ       3                   ; Port F Data Bit 3
PTF_PTF4            equ       4                   ; Port F Data Bit 4
PTF_PTF5            equ       5                   ; Port F Data Bit 5
; bit position masks
mPTF_PTF0           equ       %00000001
mPTF_PTF1           equ       %00000010
mPTF_PTF2           equ       %00000100
mPTF_PTF3           equ       %00001000
mPTF_PTF4           equ       %00010000
mPTF_PTF5           equ       %00100000

;*** DDRE - Data Direction Register E
DDRE                equ       $0000000C           ;*** DDRE - Data Direction Register E
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

;*** DDRF - Data Direction Register F
DDRF                equ       $0000000D           ;*** DDRF - Data Direction Register F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRF_DDRF0          equ       0                   ; Data Direction Register F Bit 0
DDRF_DDRF1          equ       1                   ; Data Direction Register F Bit 1
DDRF_DDRF2          equ       2                   ; Data Direction Register F Bit 2
DDRF_DDRF3          equ       3                   ; Data Direction Register F Bit 3
DDRF_DDRF4          equ       4                   ; Data Direction Register F Bit 4
DDRF_DDRF5          equ       5                   ; Data Direction Register F Bit 5
; bit position masks
mDDRF_DDRF0         equ       %00000001
mDDRF_DDRF1         equ       %00000010
mDDRF_DDRF2         equ       %00000100
mDDRF_DDRF3         equ       %00001000
mDDRF_DDRF4         equ       %00010000
mDDRF_DDRF5         equ       %00100000

;*** TASC - TIMA Status/Control Register
TASC                equ       $0000000E           ;*** TASC - TIMA Status/Control Register
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
TACNT               equ       $0000000F           ;*** TACNT - TIMA Counter Register

;*** TACNTH - TIMA Counter Register High
TACNTH              equ       $0000000F           ;*** TACNTH - TIMA Counter Register High

;*** TACNTL - TIMA Counter Register Low
TACNTL              equ       $00000010           ;*** TACNTL - TIMA Counter Register Low

;*** TAMOD - TIMA Counter Modulo Register
TAMOD               equ       $00000011           ;*** TAMOD - TIMA Counter Modulo Register

;*** TAMODH - TIMA Counter Modulo Register High
TAMODH              equ       $00000011           ;*** TAMODH - TIMA Counter Modulo Register High

;*** TAMODL - TIMA Counter Modulo Register Low
TAMODL              equ       $00000012           ;*** TAMODL - TIMA Counter Modulo Register Low

;*** TASC0 - TIMA Channel 0 Status/Control Register
TASC0               equ       $00000013           ;*** TASC0 - TIMA Channel 0 Status/Control Register
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
TACH0               equ       $00000014           ;*** TACH0 - TIMA Channel 0 Register

;*** TACH0H - TIMA Channel 0 Register High
TACH0H              equ       $00000014           ;*** TACH0H - TIMA Channel 0 Register High

;*** TACH0L - TIMA Channel 0 Register Low
TACH0L              equ       $00000015           ;*** TACH0L - TIMA Channel 0 Register Low

;*** TASC1 - TIMA Channel 1 Status/Control Register
TASC1               equ       $00000016           ;*** TASC1 - TIMA Channel 1 Status/Control Register
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
TACH1               equ       $00000017           ;*** TACH1 - TIMA Channel 1 Register

;*** TACH1H - TIMA Channel 1 Register High
TACH1H              equ       $00000017           ;*** TACH1H - TIMA Channel 1 Register High

;*** TACH1L - TIMA Channel 1 Register Low
TACH1L              equ       $00000018           ;*** TACH1L - TIMA Channel 1 Register Low

;*** TASC2 - TIMA Channel 2 Status/Control Register
TASC2               equ       $00000019           ;*** TASC2 - TIMA Channel 2 Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC2_CH2MAX        equ       0                   ; Channel 2 Maximum Duty Cycle Bit
TASC2_TOV2          equ       1                   ; Toggle-On-Overflow Bit
TASC2_ELS2A         equ       2                   ; Edge/Level Select Bit A
TASC2_ELS2B         equ       3                   ; Edge/Level Select Bit B
TASC2_MS2A          equ       4                   ; Mode Select Bit A
TASC2_MS2B          equ       5                   ; Mode Select Bit B
TASC2_CH2IE         equ       6                   ; Channel 2 Interrupt Enable Bit
TASC2_CH2F          equ       7                   ; Channel 2 Flag Bit
; bit position masks
mTASC2_CH2MAX       equ       %00000001
mTASC2_TOV2         equ       %00000010
mTASC2_ELS2A        equ       %00000100
mTASC2_ELS2B        equ       %00001000
mTASC2_MS2A         equ       %00010000
mTASC2_MS2B         equ       %00100000
mTASC2_CH2IE        equ       %01000000
mTASC2_CH2F         equ       %10000000

;*** TACH2 - TIMA Channel 2 Register
TACH2               equ       $0000001A           ;*** TACH2 - TIMA Channel 2 Register

;*** TACH2H - TIMA Channel 2 Register High
TACH2H              equ       $0000001A           ;*** TACH2H - TIMA Channel 2 Register High

;*** TACH2L - TIMA Channel 2 Register Low
TACH2L              equ       $0000001B           ;*** TACH2L - TIMA Channel 2 Register Low

;*** TASC3 - TIMA Channel 3 Status/Control Register
TASC3               equ       $0000001C           ;*** TASC3 - TIMA Channel 3 Status/Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC3_CH3MAX        equ       0                   ; Channel 3 Maximum Duty Cycle Bit
TASC3_TOV3          equ       1                   ; Toggle-On-Overflow Bit
TASC3_ELS3A         equ       2                   ; Edge/Level Select Bit A
TASC3_ELS3B         equ       3                   ; Edge/Level Select Bit B
TASC3_MS3A          equ       4                   ; Mode Select Bit A
TASC3_CH3IE         equ       6                   ; Channel 3 Interrupt Enable Bit
TASC3_CH3F          equ       7                   ; Channel 3 Flag Bit
; bit position masks
mTASC3_CH3MAX       equ       %00000001
mTASC3_TOV3         equ       %00000010
mTASC3_ELS3A        equ       %00000100
mTASC3_ELS3B        equ       %00001000
mTASC3_MS3A         equ       %00010000
mTASC3_CH3IE        equ       %01000000
mTASC3_CH3F         equ       %10000000

;*** TACH3 - TIMA Channel 3 Register
TACH3               equ       $0000001D           ;*** TACH3 - TIMA Channel 3 Register

;*** TACH3H - TIMA Channel 3 Register High
TACH3H              equ       $0000001D           ;*** TACH3H - TIMA Channel 3 Register High

;*** TACH3L - TIMA Channel 3 Register Low
TACH3L              equ       $0000001E           ;*** TACH3L - TIMA Channel 3 Register Low

;*** CONFIG - Configuration Register
CONFIG              equ       $0000001F           ;*** CONFIG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG_COPD         equ       0                   ; COP Disable Bit
CONFIG_STOPE        equ       1                   ; Stop Enable Bit
CONFIG_LVIPWR       equ       2                   ; LVI Power Enable Bit
CONFIG_LVIRST       equ       3                   ; LVI Reset Enable Bit
CONFIG_INDEP        equ       4                   ; Independent Mode Enable Bit
CONFIG_TOPNEG       equ       5                   ; Top-Side PWM Polarity Bit
CONFIG_BOTNEG       equ       6                   ; Bottom-Side PWM Polarity Bit
CONFIG_EDGE         equ       7                   ; Edge-Align Enable Bit
; bit position masks
mCONFIG_COPD        equ       %00000001
mCONFIG_STOPE       equ       %00000010
mCONFIG_LVIPWR      equ       %00000100
mCONFIG_LVIRST      equ       %00001000
mCONFIG_INDEP       equ       %00010000
mCONFIG_TOPNEG      equ       %00100000
mCONFIG_BOTNEG      equ       %01000000
mCONFIG_EDGE        equ       %10000000

;*** PCTL1 - PWM Control Register 1
PCTL1               equ       $00000020           ;*** PCTL1 - PWM Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL1_PWMEN         equ       0                   ; PWM Module Enable Bit
PCTL1_LDOK          equ       1                   ; Load OK Bit
PCTL1_ISENS0        equ       2                   ; Current Sense Correction Bit 0
PCTL1_ISENS1        equ       3                   ; Current Sense Correction Bit 1
PCTL1_PWMF          equ       4                   ; PWM Reload Flag
PCTL1_PWMINT        equ       5                   ; PWM Interrupt Enable Bit
PCTL1_DISY          equ       6                   ; Software Disable Bit for Bank Y Bit
PCTL1_DISX          equ       7                   ; Software Disable Bit for Bank X Bit
; bit position masks
mPCTL1_PWMEN        equ       %00000001
mPCTL1_LDOK         equ       %00000010
mPCTL1_ISENS0       equ       %00000100
mPCTL1_ISENS1       equ       %00001000
mPCTL1_PWMF         equ       %00010000
mPCTL1_PWMINT       equ       %00100000
mPCTL1_DISY         equ       %01000000
mPCTL1_DISX         equ       %10000000

;*** PCTL2 - PWM Control Register 2
PCTL2               equ       $00000021           ;*** PCTL2 - PWM Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL2_PRSC0         equ       0                   ; PWM Prescaler Bit 0
PCTL2_PRSC1         equ       1                   ; PWM Prescaler Bit 1
PCTL2_IPOL3         equ       2                   ; Top/Bottom Correction Bit for PWM Pair 3 (PWMs 5 & 6)
PCTL2_IPOL2         equ       3                   ; Top/Bottom Correction Bit for PWM Pair 2 (PWMs 3 & 4)
PCTL2_IPOL1         equ       4                   ; Top/Bottom Correction Bit for PWM Pair 1 (PWMs 1 & 2)
PCTL2_LDFQ0         equ       6                   ; PWM Load Frequency Bit 0
PCTL2_LDFQ1         equ       7                   ; PWM Load Frequency Bit 1
; bit position masks
mPCTL2_PRSC0        equ       %00000001
mPCTL2_PRSC1        equ       %00000010
mPCTL2_IPOL3        equ       %00000100
mPCTL2_IPOL2        equ       %00001000
mPCTL2_IPOL1        equ       %00010000
mPCTL2_LDFQ0        equ       %01000000
mPCTL2_LDFQ1        equ       %10000000

;*** FCR - Fault Control Register
FCR                 equ       $00000022           ;*** FCR - Fault Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCR_FMODE1          equ       0                   ; Fault Mode Selection for Fault Pin 1 Bit
FCR_FINT1           equ       1                   ; Fault 1 Interrupt Enable Bit
FCR_FMODE2          equ       2                   ; Fault Mode Selection for Fault Pin 2 Bit
FCR_FINT2           equ       3                   ; Fault 2 Interrupt Enable Bit
FCR_FMODE3          equ       4                   ; Fault Mode Selection for Fault Pin 3 Bit
FCR_FINT3           equ       5                   ; Fault 3 Interrupt Enable Bit
FCR_FMODE4          equ       6                   ; Fault Mode Selection for Fault Pin 4 Bit
FCR_FINT4           equ       7                   ; Fault 4 Interrupt Enable Bit
; bit position masks
mFCR_FMODE1         equ       %00000001
mFCR_FINT1          equ       %00000010
mFCR_FMODE2         equ       %00000100
mFCR_FINT2          equ       %00001000
mFCR_FMODE3         equ       %00010000
mFCR_FINT3          equ       %00100000
mFCR_FMODE4         equ       %01000000
mFCR_FINT4          equ       %10000000

;*** FSR - Fault Status Register
FSR                 equ       $00000023           ;*** FSR - Fault Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSR_FFLAG1          equ       0                   ; Fault Event Flag 1
FSR_FPIN1           equ       1                   ; State of Fault Pin 1 Bit
FSR_FFLAG2          equ       2                   ; Fault Event Flag 2
FSR_FPIN2           equ       3                   ; State of Fault Pin 2 Bit
FSR_FFLAG3          equ       4                   ; Fault Event Flag 3
FSR_FPIN3           equ       5                   ; State of Fault Pin 3 Bit
FSR_FFLAG4          equ       6                   ; Fault Event Flag 4
FSR_FPIN4           equ       7                   ; State of Fault Pin 4 Bit
; bit position masks
mFSR_FFLAG1         equ       %00000001
mFSR_FPIN1          equ       %00000010
mFSR_FFLAG2         equ       %00000100
mFSR_FPIN2          equ       %00001000
mFSR_FFLAG3         equ       %00010000
mFSR_FPIN3          equ       %00100000
mFSR_FFLAG4         equ       %01000000
mFSR_FPIN4          equ       %10000000

;*** FTACK - Fault Acknowledge Register
FTACK               equ       $00000024           ;*** FTACK - Fault Acknowledge Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTACK_DT1_FTACK1    equ       0                   ; Dead-Time 1 Bit, Fault Acknowledge 1 Bit
FTACK_DT2           equ       1                   ; Dead-Time 2 Bit
FTACK_DT3_FTACK2    equ       2                   ; Dead-Time 3 Bit, Fault Acknowledge 2 Bit
FTACK_DT4           equ       3                   ; Dead-Time 4 Bit
FTACK_DT5_FTACK3    equ       4                   ; Dead-Time 5 Bit, Fault Acknowledge 3 Bit
FTACK_DT6           equ       5                   ; Dead-Time 6 Bit
FTACK_FTACK4        equ       6                   ; Fault Acknowledge 4 Bit
; bit position masks
mFTACK_DT1_FTACK1   equ       %00000001
mFTACK_DT2          equ       %00000010
mFTACK_DT3_FTACK2   equ       %00000100
mFTACK_DT4          equ       %00001000
mFTACK_DT5_FTACK3   equ       %00010000
mFTACK_DT6          equ       %00100000
mFTACK_FTACK4       equ       %01000000

;*** PWMOUT - PWM Output Control Register
PWMOUT              equ       $00000025           ;*** PWMOUT - PWM Output Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMOUT_OUT1         equ       0                   ; PWM Pin Output Control Bit 1
PWMOUT_OUT2         equ       1                   ; PWM Pin Output Control Bit 2
PWMOUT_OUT3         equ       2                   ; PWM Pin Output Control Bit 3
PWMOUT_OUT4         equ       3                   ; PWM Pin Output Control Bit 4
PWMOUT_OUT5         equ       4                   ; PWM Pin Output Control Bit 5
PWMOUT_OUT6         equ       5                   ; PWM Pin Output Control Bit 6
PWMOUT_OUTCTL       equ       6                   ; Output Control Enable Bit
; bit position masks
mPWMOUT_OUT1        equ       %00000001
mPWMOUT_OUT2        equ       %00000010
mPWMOUT_OUT3        equ       %00000100
mPWMOUT_OUT4        equ       %00001000
mPWMOUT_OUT5        equ       %00010000
mPWMOUT_OUT6        equ       %00100000
mPWMOUT_OUTCTL      equ       %01000000

;*** PCNT - PWM Counter Register
PCNT                equ       $00000026           ;*** PCNT - PWM Counter Register

;*** PCNTH - PWM Counter Register High
PCNTH               equ       $00000026           ;*** PCNTH - PWM Counter Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNTH_BIT8          equ       0                   ; PWM Counter Bit 8
PCNTH_BIT9          equ       1                   ; PWM Counter Bit 9
PCNTH_BIT10         equ       2                   ; PWM Counter Bit 10
PCNTH_BIT11         equ       3                   ; PWM Counter Bit 11
; bit position masks
mPCNTH_BIT8         equ       %00000001
mPCNTH_BIT9         equ       %00000010
mPCNTH_BIT10        equ       %00000100
mPCNTH_BIT11        equ       %00001000

;*** PCNTL - PWM Counter Register Low
PCNTL               equ       $00000027           ;*** PCNTL - PWM Counter Register Low

;*** PMOD - PWM Counter Modulo Register
PMOD                equ       $00000028           ;*** PMOD - PWM Counter Modulo Register

;*** PMODH - PWM Counter Modulo Register High
PMODH               equ       $00000028           ;*** PMODH - PWM Counter Modulo Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMODH_BIT8          equ       0                   ; PWM Counter Modulo Bit 8
PMODH_BIT9          equ       1                   ; PWM Counter Modulo Bit 9
PMODH_BIT10         equ       2                   ; PWM Counter Modulo Bit 10
PMODH_BIT11         equ       3                   ; PWM Counter Modulo Bit 11
; bit position masks
mPMODH_BIT8         equ       %00000001
mPMODH_BIT9         equ       %00000010
mPMODH_BIT10        equ       %00000100
mPMODH_BIT11        equ       %00001000

;*** PMODL - PWM Counter Modulo Register Low
PMODL               equ       $00000029           ;*** PMODL - PWM Counter Modulo Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMODL_BIT0          equ       0                   ; PWM Counter Modulo Bit 0
PMODL_BIT1          equ       1                   ; PWM Counter Modulo Bit 1
PMODL_BIT2          equ       2                   ; PWM Counter Modulo Bit 2
PMODL_BIT3          equ       3                   ; PWM Counter Modulo Bit 3
PMODL_BIT4          equ       4                   ; PWM Counter Modulo Bit 4
PMODL_BIT5          equ       5                   ; PWM Counter Modulo Bit 5
PMODL_BIT6          equ       6                   ; PWM Counter Modulo Bit 6
PMODL_BIT7          equ       7                   ; PWM Counter Modulo Bit 7
; bit position masks
mPMODL_BIT0         equ       %00000001
mPMODL_BIT1         equ       %00000010
mPMODL_BIT2         equ       %00000100
mPMODL_BIT3         equ       %00001000
mPMODL_BIT4         equ       %00010000
mPMODL_BIT5         equ       %00100000
mPMODL_BIT6         equ       %01000000
mPMODL_BIT7         equ       %10000000

;*** PVAL1 - PWM1 Value Register
PVAL1               equ       $0000002A           ;*** PVAL1 - PWM1 Value Register

;*** PVAL1H - PWM1 Value Register High
PVAL1H              equ       $0000002A           ;*** PVAL1H - PWM1 Value Register High

;*** PVAL1L - PWM1 Value Register Low
PVAL1L              equ       $0000002B           ;*** PVAL1L - PWM1 Value Register Low

;*** PVAL2 - PWM2 Value Register
PVAL2               equ       $0000002C           ;*** PVAL2 - PWM2 Value Register

;*** PVAL2H - PWM2 Value Register High
PVAL2H              equ       $0000002C           ;*** PVAL2H - PWM2 Value Register High

;*** PVAL2L - PWM2 Value Register Low
PVAL2L              equ       $0000002D           ;*** PVAL2L - PWM2 Value Register Low

;*** PVAL3 - PWM3 Value Register
PVAL3               equ       $0000002E           ;*** PVAL3 - PWM3 Value Register

;*** PVAL3H - PWM3 Value Register High
PVAL3H              equ       $0000002E           ;*** PVAL3H - PWM3 Value Register High

;*** PVAL3L - PWM3 Value Register Low
PVAL3L              equ       $0000002F           ;*** PVAL3L - PWM3 Value Register Low

;*** PVAL4 - PWM4 Value Register
PVAL4               equ       $00000030           ;*** PVAL4 - PWM4 Value Register

;*** PVAL4H - PWM4 Value Register High
PVAL4H              equ       $00000030           ;*** PVAL4H - PWM4 Value Register High

;*** PVAL4L - PWM4 Value Register Low
PVAL4L              equ       $00000031           ;*** PVAL4L - PWM4 Value Register Low

;*** PVAL5 - PWM5 Value Register
PVAL5               equ       $00000032           ;*** PVAL5 - PWM5 Value Register

;*** PVAL5H - PWM5 Value Register High
PVAL5H              equ       $00000032           ;*** PVAL5H - PWM5 Value Register High

;*** PVAL5L - PWM5 Value Register Low
PVAL5L              equ       $00000033           ;*** PVAL5L - PWM5 Value Register Low

;*** PVAL6 - PWM6 Value Register
PVAL6               equ       $00000034           ;*** PVAL6 - PWM6 Value Register

;*** PVAL6H - PWM6 Value Register High
PVAL6H              equ       $00000034           ;*** PVAL6H - PWM6 Value Register High

;*** PVAL6L - PWM6 Value Register Low
PVAL6L              equ       $00000035           ;*** PVAL6L - PWM6 Value Register Low

;*** DEADTM - Dead-Time Write-Once Register
DEADTM              equ       $00000036           ;*** DEADTM - Dead-Time Write-Once Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DEADTM_BIT0         equ       0                   ; Dead-Time Value Bit 0
DEADTM_BIT1         equ       1                   ; Dead-Time Value Bit 1
DEADTM_BIT2         equ       2                   ; Dead-Time Value Bit 2
DEADTM_BIT3         equ       3                   ; Dead-Time Value Bit 3
DEADTM_BIT4         equ       4                   ; Dead-Time Value Bit 4
DEADTM_BIT5         equ       5                   ; Dead-Time Value Bit 5
DEADTM_BIT6         equ       6                   ; Dead-Time Value Bit 6
DEADTM_BIT7         equ       7                   ; Dead-Time Value Bit 7
; bit position masks
mDEADTM_BIT0        equ       %00000001
mDEADTM_BIT1        equ       %00000010
mDEADTM_BIT2        equ       %00000100
mDEADTM_BIT3        equ       %00001000
mDEADTM_BIT4        equ       %00010000
mDEADTM_BIT5        equ       %00100000
mDEADTM_BIT6        equ       %01000000
mDEADTM_BIT7        equ       %10000000

;*** DISMAP - PWM Disable Mapping Write-Once Register
DISMAP              equ       $00000037           ;*** DISMAP - PWM Disable Mapping Write-Once Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DISMAP_BIT0         equ       0                   ; PWM Disable Mapping Bit 0
DISMAP_BIT1         equ       1                   ; PWM Disable Mapping Bit 1
DISMAP_BIT2         equ       2                   ; PWM Disable Mapping Bit 2
DISMAP_BIT3         equ       3                   ; PWM Disable Mapping Bit 3
DISMAP_BIT4         equ       4                   ; PWM Disable Mapping Bit 4
DISMAP_BIT5         equ       5                   ; PWM Disable Mapping Bit 5
DISMAP_BIT6         equ       6                   ; PWM Disable Mapping Bit 6
DISMAP_BIT7         equ       7                   ; PWM Disable Mapping Bit 7
; bit position masks
mDISMAP_BIT0        equ       %00000001
mDISMAP_BIT1        equ       %00000010
mDISMAP_BIT2        equ       %00000100
mDISMAP_BIT3        equ       %00001000
mDISMAP_BIT4        equ       %00010000
mDISMAP_BIT5        equ       %00100000
mDISMAP_BIT6        equ       %01000000
mDISMAP_BIT7        equ       %10000000

;*** SCC1 - SCI Control Register 1
SCC1                equ       $00000038           ;*** SCC1 - SCI Control Register 1
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
SCC2                equ       $00000039           ;*** SCC2 - SCI Control Register 2
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
SCC3                equ       $0000003A           ;*** SCC3 - SCI Control Register 3
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
SCS1                equ       $0000003B           ;*** SCS1 - SCI Status Register 1
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
SCS2                equ       $0000003C           ;*** SCS2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS2_RPF            equ       0                   ; Reception in Progress Flag Bit
SCS2_BKF            equ       1                   ; Break Flag Bit
; bit position masks
mSCS2_RPF           equ       %00000001
mSCS2_BKF           equ       %00000010

;*** SCDR - SCI Data Register
SCDR                equ       $0000003D           ;*** SCDR - SCI Data Register
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
SCBR                equ       $0000003E           ;*** SCBR - SCI Baud Rate Register
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

;*** ISCR - IRQ Status and Control Register
ISCR                equ       $0000003F           ;*** ISCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ISCR_MODE1          equ       0                   ; IRQ Edge/Level Select Bit
ISCR_IMASK1         equ       1                   ; IRQ Interrupt Mask Bit
ISCR_ACK1           equ       2                   ; IRQ Interrupt Request Acknowledge Bit
ISCR_IRQF           equ       3                   ; IRQ Flag Bit
; bit position masks
mISCR_MODE1         equ       %00000001
mISCR_IMASK1        equ       %00000010
mISCR_ACK1          equ       %00000100
mISCR_IRQF          equ       %00001000

;*** ADSCR - ADC Status and Control Register
ADSCR               equ       $00000040           ;*** ADSCR - ADC Status and Control Register
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
ADR                 equ       $00000041           ;*** ADR - ADC Data Register

;*** ADRH - ADC Data Register High
ADRH                equ       $00000041           ;*** ADRH - ADC Data Register High
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

;*** ADRL - ADC Data Register Low
ADRL                equ       $00000042           ;*** ADRL - ADC Data Register Low
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

;*** ADCLK - ADC Clock Register
ADCLK               equ       $00000043           ;*** ADCLK - ADC Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_MODE0         equ       2                   ; Mode of Result Justification Bit 0
ADCLK_MODE1         equ       3                   ; Mode of Result Justification Bit 1
ADCLK_ADICLK        equ       4                   ; ADC Input Clock Select Bit
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

;*** SPCR - SPI Control Register
SPCR                equ       $00000044           ;*** SPCR - SPI Control Register
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
SPSCR               equ       $00000045           ;*** SPSCR - SPI Status and Control Register
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
SPDR                equ       $00000046           ;*** SPDR - SPI Data Register
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

;*** TBSC - TIMB Status/Control Register
TBSC                equ       $00000051           ;*** TBSC - TIMB Status/Control Register
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
TBCNT               equ       $00000052           ;*** TBCNT - TIMB Counter Register

;*** TBCNTH - TIMB Counter Register High
TBCNTH              equ       $00000052           ;*** TBCNTH - TIMB Counter Register High

;*** TBCNTL - TIMB Counter Register Low
TBCNTL              equ       $00000053           ;*** TBCNTL - TIMB Counter Register Low

;*** TBMOD - TIMB Counter Modulo Register
TBMOD               equ       $00000054           ;*** TBMOD - TIMB Counter Modulo Register

;*** TBMODH - TIMB Counter Modulo Register High
TBMODH              equ       $00000054           ;*** TBMODH - TIMB Counter Modulo Register High

;*** TBMODL - TIMB Counter Modulo Register Low
TBMODL              equ       $00000055           ;*** TBMODL - TIMB Counter Modulo Register Low

;*** TBSC0 - TIMB Channel 0 Status/Control Register
TBSC0               equ       $00000056           ;*** TBSC0 - TIMB Channel 0 Status/Control Register
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
TBCH0               equ       $00000057           ;*** TBCH0 - TIMB Channel 0 Register

;*** TBCH0H - TIMB Channel 0 Register High
TBCH0H              equ       $00000057           ;*** TBCH0H - TIMB Channel 0 Register High

;*** TBCH0L - TIMB Channel 0 Register Low
TBCH0L              equ       $00000058           ;*** TBCH0L - TIMB Channel 0 Register Low

;*** TBSC1 - IMB Channel Status and Control Register
TBSC1               equ       $00000059           ;*** TBSC1 - IMB Channel Status and Control Register
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
TBCH1               equ       $0000005A           ;*** TBCH1 - TIMB Channel 1 Register

;*** TBCH1H - TIMB Channel 1 Register High
TBCH1H              equ       $0000005A           ;*** TBCH1H - TIMB Channel 1 Register High

;*** TBCH1L - TIMB Channel 1 Register Low
TBCH1L              equ       $0000005B           ;*** TBCH1L - TIMB Channel 1 Register Low

;*** PCTL - PLL Control Register
PCTL                equ       $0000005C           ;*** PCTL - PLL Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL_BCS            equ       4                   ; Base Clock Select Bit
PCTL_PLLON          equ       5                   ; PLL On Bit
PCTL_PLLF           equ       6                   ; PLL Interrupt Flag
PCTL_PLLIE          equ       7                   ; PLL Interrupt Enable Bit
; bit position masks
mPCTL_BCS           equ       %00010000
mPCTL_PLLON         equ       %00100000
mPCTL_PLLF          equ       %01000000
mPCTL_PLLIE         equ       %10000000

;*** PBWC - PLL Bandwith Control Register
PBWC                equ       $0000005D           ;*** PBWC - PLL Bandwith Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PBWC_XLD            equ       4                   ; Crystal Loss Detect Bit
PBWC_ACQ            equ       5                   ; Acquisition Mode Bit
PBWC_LOCK           equ       6                   ; Lock Indicator Bit
PBWC_AUTO           equ       7                   ; Automatic Bandwith Control Bit
; bit position masks
mPBWC_XLD           equ       %00010000
mPBWC_ACQ           equ       %00100000
mPBWC_LOCK          equ       %01000000
mPBWC_AUTO          equ       %10000000

;*** PPG - PLL Programming Register
PPG                 equ       $0000005E           ;*** PPG - PLL Programming Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPG_VRS4            equ       0                   ; VCO Range Select Bit 4
PPG_VRS5            equ       1                   ; VCO Range Select Bit 5
PPG_VRS6            equ       2                   ; VCO Range Select Bit 6
PPG_VRS7            equ       3                   ; VCO Range Select Bit 7
PPG_MUL4            equ       4                   ; Multiplier Select Bit 4
PPG_MUL5            equ       5                   ; Multiplier Select Bit 5
PPG_MUL6            equ       6                   ; Multiplier Select Bit 6
PPG_MUL7            equ       7                   ; Multiplier Select Bit 7
; bit position masks
mPPG_VRS4           equ       %00000001
mPPG_VRS5           equ       %00000010
mPPG_VRS6           equ       %00000100
mPPG_VRS7           equ       %00001000
mPPG_MUL4           equ       %00010000
mPPG_MUL5           equ       %00100000
mPPG_MUL6           equ       %01000000
mPPG_MUL7           equ       %10000000

;*** SBSR - SIM Break Status Register
SBSR                equ       $0000FE00           ;*** SBSR - SIM Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBSR_BW             equ       1                   ; Break Wait Bit
; bit position masks
mSBSR_BW            equ       %00000010

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

;*** BRKL - Break Address Register Low
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Register Low
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

;*** BRKSCR - Break Status and Control Register
BRKSCR              equ       $0000FE0E           ;*** BRKSCR - Break Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKSCR_BRKA         equ       6                   ; Break Active Bit
BRKSCR_BRKE         equ       7                   ; Break Enable Bit
; bit position masks
mBRKSCR_BRKA        equ       %01000000
mBRKSCR_BRKE        equ       %10000000

;*** LVISCR - LVI Status and Control Register
LVISCR              equ       $0000FE0F           ;*** LVISCR - LVI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISCR_TRPSEL       equ       5                   ; LVI Trip Select Bit
LVISCR_LVIOUT       equ       7                   ; LVI Output Bit
; bit position masks
mLVISCR_TRPSEL      equ       %00100000
mLVISCR_LVIOUT      equ       %10000000

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
