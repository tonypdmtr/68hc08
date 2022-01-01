;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908LD64, version 2.87.145 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908ld64.inc
;     Processor : MC68HC908LD64IFU
;     FileFormat: V2.28
;     DataSheet : MC68HC908LD64 Rev. 3.0 07/2004
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
ROM                 equ       $00000C00
ROM_END             equ       $0000F9FF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000047F
RAM1                equ       $00000800
RAM1_END            equ       $00000BFF
;
INT_CGMPLL          equ       $0000FFE0
INT_KBI             equ       $0000FFE2
INT_ADC             equ       $0000FFE4
INT_OSD             equ       $0000FFE6
INT_MMIIC           equ       $0000FFE8
INT_Sync            equ       $0000FFEA
INT_TIMOvr          equ       $0000FFEC
INT_TIMCH1          equ       $0000FFEE
INT_TIMCH0          equ       $0000FFF0
INT_DDC12AB         equ       $0000FFF2
INT_USB_Device      equ       $0000FFF4
INT_USB_HUB_EP0     equ       $0000FFF6
INT_USB_HUB_Timing  equ       $0000FFF8
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
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000
mDDRC_DDRC4         equ       %00010000
mDDRC_DDRC5         equ       %00100000
mDDRC_DDRC6         equ       %01000000

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

;*** TSC - Timer Status & Control
TSC                 equ       $0000000A           ;*** TSC - Timer Status & Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC_PS0             equ       0                   ; Prescaler Select Bit
TSC_PS1             equ       1                   ; Prescaler Select Bit
TSC_PS2             equ       2                   ; Prescaler Select Bit
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
TCNT                equ       $0000000C           ;*** TCNT - TIM Counter Register

;*** TCNTH - TIM Counter Register
TCNTH               equ       $0000000C           ;*** TCNTH - TIM Counter Register

;*** TCNTL - TIM Counter Register
TCNTL               equ       $0000000D           ;*** TCNTL - TIM Counter Register

;*** TMOD - TIM Counter Modulo Register
TMOD                equ       $0000000E           ;*** TMOD - TIM Counter Modulo Register

;*** TMODH - TIM Counter Modulo Register
TMODH               equ       $0000000E           ;*** TMODH - TIM Counter Modulo Register

;*** TMODL - TIM Counter Modulo Register
TMODL               equ       $0000000F           ;*** TMODL - TIM Counter Modulo Register

;*** TSC0 - TIM Channel Status and Control Register 0
TSC0                equ       $00000010           ;*** TSC0 - TIM Channel Status and Control Register 0
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

;*** TCH0 - TIM channel 0 register
TCH0                equ       $00000011           ;*** TCH0 - TIM channel 0 register

;*** TCH0H - TIM channel 0 register High
TCH0H               equ       $00000011           ;*** TCH0H - TIM channel 0 register High

;*** TCH0L - TIM channel 0 register Low
TCH0L               equ       $00000012           ;*** TCH0L - TIM channel 0 register Low

;*** TSC1 - TIM Channel Status and Control Register 1
TSC1                equ       $00000013           ;*** TSC1 - TIM Channel Status and Control Register 1
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

;*** TCH1 - TIM channel 1 register
TCH1                equ       $00000014           ;*** TCH1 - TIM channel 1 register

;*** TCH1H - TIM channel 1 register High
TCH1H               equ       $00000014           ;*** TCH1H - TIM channel 1 register High

;*** TCH1L - TIM channel 1 register Low
TCH1L               equ       $00000015           ;*** TCH1L - TIM channel 1 register Low

;*** DDCMCR - DDC Master Control Register
DDCMCR              equ       $00000016           ;*** DDCMCR - DDC Master Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDCMCR_BR0          equ       0                   ; Baud Rate Select Bit 0
DDCMCR_BR1          equ       1                   ; Baud Rate Select Bit 1
DDCMCR_BR2          equ       2                   ; Baud Rate Select Bit 2
DDCMCR_MRW          equ       3                   ; Master Read/Write
DDCMCR_MAST         equ       4                   ; Master Control Bit
DDCMCR_BB           equ       5                   ; Bus Busy Flag
DDCMCR_NAKIF        equ       6                   ; No Acknowledge Interrupt Flag
DDCMCR_ALIF         equ       7                   ; DDC Arbitration Lost Interrupt Flag
; bit position masks
mDDCMCR_BR0         equ       %00000001
mDDCMCR_BR1         equ       %00000010
mDDCMCR_BR2         equ       %00000100
mDDCMCR_MRW         equ       %00001000
mDDCMCR_MAST        equ       %00010000
mDDCMCR_BB          equ       %00100000
mDDCMCR_NAKIF       equ       %01000000
mDDCMCR_ALIF        equ       %10000000

;*** DDCADR - DDC Address Register
DDCADR              equ       $00000017           ;*** DDCADR - DDC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDCADR_EXTAD        equ       0                   ; DDC Expand Address
DDCADR_DAD1         equ       1                   ; DDC Address Bit 1
DDCADR_DAD2         equ       2                   ; DDC Address Bit 2
DDCADR_DAD3         equ       3                   ; DDC Address Bit 3
DDCADR_DAD4         equ       4                   ; DDC Address Bit 4
DDCADR_DAD5         equ       5                   ; DDC Address Bit 5
DDCADR_DAD6         equ       6                   ; DDC Address Bit 6
DDCADR_DAD7         equ       7                   ; DDC Address Bit 7
; bit position masks
mDDCADR_EXTAD       equ       %00000001
mDDCADR_DAD1        equ       %00000010
mDDCADR_DAD2        equ       %00000100
mDDCADR_DAD3        equ       %00001000
mDDCADR_DAD4        equ       %00010000
mDDCADR_DAD5        equ       %00100000
mDDCADR_DAD6        equ       %01000000
mDDCADR_DAD7        equ       %10000000

;*** DDCCR - DDC Control Register
DDCCR               equ       $00000018           ;*** DDCCR - DDC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDCCR_DDC1EN        equ       1                   ; DDC1 Protocol Enable
DDCCR_SCLIEN        equ       2                   ; SCL Interrupt Enable
DDCCR_TXAK          equ       3                   ; Transmit Acknowledge Enable
DDCCR_DIEN          equ       6                   ; DDC Interrupt Enable
DDCCR_DEN           equ       7                   ; DDC Enable
; bit position masks
mDDCCR_DDC1EN       equ       %00000010
mDDCCR_SCLIEN       equ       %00000100
mDDCCR_TXAK         equ       %00001000
mDDCCR_DIEN         equ       %01000000
mDDCCR_DEN          equ       %10000000

;*** DDCSR - DDC Status Register
DDCSR               equ       $00000019           ;*** DDCSR - DDC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDCSR_RXBF          equ       0                   ; DDC Receive Buffer Full
DDCSR_TXBE          equ       1                   ; DDC Transmit Buffer Empty
DDCSR_SCLIF         equ       2                   ; SCL Interrupt Flag
DDCSR_RXAK          equ       3                   ; DDC Receive Acknowledge
DDCSR_SRW           equ       4                   ; DDC Slave Read/Write
DDCSR_MATCH         equ       5                   ; DDC Address Match
DDCSR_TXIF          equ       6                   ; DDC Transmit Interrupt Flag
DDCSR_RXIF          equ       7                   ; DDC Receive Interrupt Flag
; bit position masks
mDDCSR_RXBF         equ       %00000001
mDDCSR_TXBE         equ       %00000010
mDDCSR_SCLIF        equ       %00000100
mDDCSR_RXAK         equ       %00001000
mDDCSR_SRW          equ       %00010000
mDDCSR_MATCH        equ       %00100000
mDDCSR_TXIF         equ       %01000000
mDDCSR_RXIF         equ       %10000000

;*** DDCDTR - DDC Data Transmit Register
DDCDTR              equ       $0000001A           ;*** DDCDTR - DDC Data Transmit Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDCDTR_DTD0         equ       0                   ; DDC Data Transmit Bit 0
DDCDTR_DTD1         equ       1                   ; DDC Data Transmit Bit 1
DDCDTR_DTD2         equ       2                   ; DDC Data Transmit Bit 2
DDCDTR_DTD3         equ       3                   ; DDC Data Transmit Bit 3
DDCDTR_DTD4         equ       4                   ; DDC Data Transmit Bit 4
DDCDTR_DTD5         equ       5                   ; DDC Data Transmit Bit 5
DDCDTR_DTD6         equ       6                   ; DDC Data Transmit Bit 6
DDCDTR_DTD7         equ       7                   ; DDC Data Transmit Bit 7
; bit position masks
mDDCDTR_DTD0        equ       %00000001
mDDCDTR_DTD1        equ       %00000010
mDDCDTR_DTD2        equ       %00000100
mDDCDTR_DTD3        equ       %00001000
mDDCDTR_DTD4        equ       %00010000
mDDCDTR_DTD5        equ       %00100000
mDDCDTR_DTD6        equ       %01000000
mDDCDTR_DTD7        equ       %10000000

;*** DDCDRR - DDC Data Receive Register
DDCDRR              equ       $0000001B           ;*** DDCDRR - DDC Data Receive Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDCDRR_DRD0         equ       0                   ; DDC Data Receive Bit 0
DDCDRR_DRD1         equ       1                   ; DDC Data Receive Bit 1
DDCDRR_DRD2         equ       2                   ; DDC Data Receive Bit 2
DDCDRR_DRD3         equ       3                   ; DDC Data Receive Bit 3
DDCDRR_DRD4         equ       4                   ; DDC Data Receive Bit 4
DDCDRR_DRD5         equ       5                   ; DDC Data Receive Bit 5
DDCDRR_DRD6         equ       6                   ; DDC Data Receive Bit 6
DDCDRR_DRD7         equ       7                   ; DDC Data Receive Bit 7
; bit position masks
mDDCDRR_DRD0        equ       %00000001
mDDCDRR_DRD1        equ       %00000010
mDDCDRR_DRD2        equ       %00000100
mDDCDRR_DRD3        equ       %00001000
mDDCDRR_DRD4        equ       %00010000
mDDCDRR_DRD5        equ       %00100000
mDDCDRR_DRD6        equ       %01000000
mDDCDRR_DRD7        equ       %10000000

;*** DDC2ADR - DDC2 Address Register
DDC2ADR             equ       $0000001C           ;*** DDC2ADR - DDC2 Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDC2ADR_D2AD1       equ       1                   ; DDC2 Address Bit 1
DDC2ADR_D2AD2       equ       2                   ; DDC2 Address Bit 2
DDC2ADR_D2AD3       equ       3                   ; DDC2 Address Bit 3
DDC2ADR_D2AD4       equ       4                   ; DDC2 Address Bit 4
DDC2ADR_D2AD5       equ       5                   ; DDC2 Address Bit 5
DDC2ADR_D2AD6       equ       6                   ; DDC2 Address Bit 6
DDC2ADR_D2AD7       equ       7                   ; DDC2 Address Bit 7
; bit position masks
mDDC2ADR_D2AD1      equ       %00000010
mDDC2ADR_D2AD2      equ       %00000100
mDDC2ADR_D2AD3      equ       %00001000
mDDC2ADR_D2AD4      equ       %00010000
mDDC2ADR_D2AD5      equ       %00100000
mDDC2ADR_D2AD6      equ       %01000000
mDDC2ADR_D2AD7      equ       %10000000

;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001E           ;*** INTSCR - IRQ Status and Control Register
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

;*** CONFIG - Configuration Register
CONFIG              equ       $0000001F           ;*** CONFIG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG_COPD         equ       0                   ; COP Disable Bit
CONFIG_STOP         equ       1                   ; STOP Instruction Enable Bit
CONFIG_COPRS        equ       2                   ; COP Rate Select Bit
CONFIG_SSREC        equ       3                   ; Short Stop Recovery Bit
; bit position masks
mCONFIG_COPD        equ       %00000001
mCONFIG_STOP        equ       %00000010
mCONFIG_COPRS       equ       %00000100
mCONFIG_SSREC       equ       %00001000

;*** DE0D0 - USB Embedded Device Endpoint 0 Data Register 0
DE0D0               equ       $00000020           ;*** DE0D0 - USB Embedded Device Endpoint 0 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D0_DE0R00_DE0T00 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R01_DE0T01 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R02_DE0T02 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R03_DE0T03 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R04_DE0T04 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R05_DE0T05 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R06_DE0T06 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D0_DE0R07_DE0T07 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 0 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D0_DE0R00_DE0T00 equ       %00000001
mDE0D0_DE0R01_DE0T01 equ       %00000010
mDE0D0_DE0R02_DE0T02 equ       %00000100
mDE0D0_DE0R03_DE0T03 equ       %00001000
mDE0D0_DE0R04_DE0T04 equ       %00010000
mDE0D0_DE0R05_DE0T05 equ       %00100000
mDE0D0_DE0R06_DE0T06 equ       %01000000
mDE0D0_DE0R07_DE0T07 equ       %10000000

;*** DE0D1 - USB Embedded Device Endpoint 0 Data Register 1
DE0D1               equ       $00000021           ;*** DE0D1 - USB Embedded Device Endpoint 0 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D1_DE0R10_DE0T10 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R11_DE0T11 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R12_DE0T12 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R13_DE0T13 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R14_DE0T14 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R15_DE0T15 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R16_DE0T16 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D1_DE0R17_DE0T17 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 1 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D1_DE0R10_DE0T10 equ       %00000001
mDE0D1_DE0R11_DE0T11 equ       %00000010
mDE0D1_DE0R12_DE0T12 equ       %00000100
mDE0D1_DE0R13_DE0T13 equ       %00001000
mDE0D1_DE0R14_DE0T14 equ       %00010000
mDE0D1_DE0R15_DE0T15 equ       %00100000
mDE0D1_DE0R16_DE0T16 equ       %01000000
mDE0D1_DE0R17_DE0T17 equ       %10000000

;*** DE0D2 - USB Embedded Device Endpoint 0 Data Register 2
DE0D2               equ       $00000022           ;*** DE0D2 - USB Embedded Device Endpoint 0 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D2_DE0R20_DE0T20 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R21_DE0T21 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R22_DE0T22 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R23_DE0T23 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R24_DE0T24 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R25_DE0T25 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R26_DE0T26 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D2_DE0R27_DE0T27 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 2 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D2_DE0R20_DE0T20 equ       %00000001
mDE0D2_DE0R21_DE0T21 equ       %00000010
mDE0D2_DE0R22_DE0T22 equ       %00000100
mDE0D2_DE0R23_DE0T23 equ       %00001000
mDE0D2_DE0R24_DE0T24 equ       %00010000
mDE0D2_DE0R25_DE0T25 equ       %00100000
mDE0D2_DE0R26_DE0T26 equ       %01000000
mDE0D2_DE0R27_DE0T27 equ       %10000000

;*** DE0D3 - USB Embedded Device Endpoint 0 Data Register 3
DE0D3               equ       $00000023           ;*** DE0D3 - USB Embedded Device Endpoint 0 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D3_DE0R30_DE0T30 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R31_DE0T31 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R32_DE0T32 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R33_DE0T33 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R34_DE0T34 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R35_DE0T35 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R36_DE0T36 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D3_DE0R37_DE0T37 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 3 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D3_DE0R30_DE0T30 equ       %00000001
mDE0D3_DE0R31_DE0T31 equ       %00000010
mDE0D3_DE0R32_DE0T32 equ       %00000100
mDE0D3_DE0R33_DE0T33 equ       %00001000
mDE0D3_DE0R34_DE0T34 equ       %00010000
mDE0D3_DE0R35_DE0T35 equ       %00100000
mDE0D3_DE0R36_DE0T36 equ       %01000000
mDE0D3_DE0R37_DE0T37 equ       %10000000

;*** DE0D4 - USB Embedded Device Endpoint 0 Data Register 4
DE0D4               equ       $00000024           ;*** DE0D4 - USB Embedded Device Endpoint 0 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D4_DE0R40_DE0T40 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R41_DE0T41 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R42_DE0T42 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R43_DE0T43 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R44_DE0T44 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R45_DE0T45 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R46_DE0T46 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D4_DE0R47_DE0T47 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 4 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D4_DE0R40_DE0T40 equ       %00000001
mDE0D4_DE0R41_DE0T41 equ       %00000010
mDE0D4_DE0R42_DE0T42 equ       %00000100
mDE0D4_DE0R43_DE0T43 equ       %00001000
mDE0D4_DE0R44_DE0T44 equ       %00010000
mDE0D4_DE0R45_DE0T45 equ       %00100000
mDE0D4_DE0R46_DE0T46 equ       %01000000
mDE0D4_DE0R47_DE0T47 equ       %10000000

;*** DE0D5 - USB Embedded Device Endpoint 0 Data Register 5
DE0D5               equ       $00000025           ;*** DE0D5 - USB Embedded Device Endpoint 0 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D5_DE0R50_DE0T50 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R51_DE0T51 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R52_DE0T52 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R53_DE0T53 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R54_DE0T54 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R55_DE0T55 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R56_DE0T56 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D5_DE0R57_DE0T57 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 5 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D5_DE0R50_DE0T50 equ       %00000001
mDE0D5_DE0R51_DE0T51 equ       %00000010
mDE0D5_DE0R52_DE0T52 equ       %00000100
mDE0D5_DE0R53_DE0T53 equ       %00001000
mDE0D5_DE0R54_DE0T54 equ       %00010000
mDE0D5_DE0R55_DE0T55 equ       %00100000
mDE0D5_DE0R56_DE0T56 equ       %01000000
mDE0D5_DE0R57_DE0T57 equ       %10000000

;*** DE0D6 - USB Embedded Device Endpoint 0 Data Register 6
DE0D6               equ       $00000026           ;*** DE0D6 - USB Embedded Device Endpoint 0 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D6_DE0R60_DE0T60 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R61_DE0T61 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R62_DE0T62 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R63_DE0T63 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R64_DE0T64 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R65_DE0T65 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R66_DE0T66 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D6_DE0R67_DE0T67 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 6 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D6_DE0R60_DE0T60 equ       %00000001
mDE0D6_DE0R61_DE0T61 equ       %00000010
mDE0D6_DE0R62_DE0T62 equ       %00000100
mDE0D6_DE0R63_DE0T63 equ       %00001000
mDE0D6_DE0R64_DE0T64 equ       %00010000
mDE0D6_DE0R65_DE0T65 equ       %00100000
mDE0D6_DE0R66_DE0T66 equ       %01000000
mDE0D6_DE0R67_DE0T67 equ       %10000000

;*** DE0D7 - USB Embedded Device Endpoint 0 Data Register 7
DE0D7               equ       $00000027           ;*** DE0D7 - USB Embedded Device Endpoint 0 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE0D7_DE0R70_DE0T70 equ       0                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 0, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R71_DE0T71 equ       1                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 1, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R72_DE0T72 equ       2                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 2, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R73_DE0T73 equ       3                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 3, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R74_DE0T74 equ       4                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 4, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R75_DE0T75 equ       5                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 5, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R76_DE0T76 equ       6                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 6, Embedded Device Endpoint 0 Transmit Data
DE0D7_DE0R77_DE0T77 equ       7                   ; Embedded Device Endpoint 0 Receive Data Buffer 7 Bit 7, Embedded Device Endpoint 0 Transmit Data
; bit position masks
mDE0D7_DE0R70_DE0T70 equ       %00000001
mDE0D7_DE0R71_DE0T71 equ       %00000010
mDE0D7_DE0R72_DE0T72 equ       %00000100
mDE0D7_DE0R73_DE0T73 equ       %00001000
mDE0D7_DE0R74_DE0T74 equ       %00010000
mDE0D7_DE0R75_DE0T75 equ       %00100000
mDE0D7_DE0R76_DE0T76 equ       %01000000
mDE0D7_DE0R77_DE0T77 equ       %10000000

;*** DE1D0 - USB Embedded Device Endpoint 1/2 Data Register 0
DE1D0               equ       $00000028           ;*** DE1D0 - USB Embedded Device Endpoint 1/2 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D0_DE1T00        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 0
DE1D0_DE1T01        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 1
DE1D0_DE1T02        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 2
DE1D0_DE1T03        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 3
DE1D0_DE1T04        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 4
DE1D0_DE1T05        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 5
DE1D0_DE1T06        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 6
DE1D0_DE1T07        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 0 Bit 7
; bit position masks
mDE1D0_DE1T00       equ       %00000001
mDE1D0_DE1T01       equ       %00000010
mDE1D0_DE1T02       equ       %00000100
mDE1D0_DE1T03       equ       %00001000
mDE1D0_DE1T04       equ       %00010000
mDE1D0_DE1T05       equ       %00100000
mDE1D0_DE1T06       equ       %01000000
mDE1D0_DE1T07       equ       %10000000

;*** DE1D1 - USB Embedded Device Endpoint 1/2 Data Register 1
DE1D1               equ       $00000029           ;*** DE1D1 - USB Embedded Device Endpoint 1/2 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D1_DE1T10        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 0
DE1D1_DE1T11        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 1
DE1D1_DE1T12        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 2
DE1D1_DE1T13        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 3
DE1D1_DE1T14        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 4
DE1D1_DE1T15        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 5
DE1D1_DE1T16        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 6
DE1D1_DE1T17        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 1 Bit 7
; bit position masks
mDE1D1_DE1T10       equ       %00000001
mDE1D1_DE1T11       equ       %00000010
mDE1D1_DE1T12       equ       %00000100
mDE1D1_DE1T13       equ       %00001000
mDE1D1_DE1T14       equ       %00010000
mDE1D1_DE1T15       equ       %00100000
mDE1D1_DE1T16       equ       %01000000
mDE1D1_DE1T17       equ       %10000000

;*** DE1D2 - USB Embedded Device Endpoint 1/2 Data Register 2
DE1D2               equ       $0000002A           ;*** DE1D2 - USB Embedded Device Endpoint 1/2 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D2_DE1T20        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 0
DE1D2_DE1T21        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 1
DE1D2_DE1T22        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 2
DE1D2_DE1T23        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 3
DE1D2_DE1T24        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 4
DE1D2_DE1T25        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 5
DE1D2_DE1T26        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 6
DE1D2_DE1T27        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 2 Bit 7
; bit position masks
mDE1D2_DE1T20       equ       %00000001
mDE1D2_DE1T21       equ       %00000010
mDE1D2_DE1T22       equ       %00000100
mDE1D2_DE1T23       equ       %00001000
mDE1D2_DE1T24       equ       %00010000
mDE1D2_DE1T25       equ       %00100000
mDE1D2_DE1T26       equ       %01000000
mDE1D2_DE1T27       equ       %10000000

;*** DE1D3 - USB Embedded Device Endpoint 1/2 Data Register 3
DE1D3               equ       $0000002B           ;*** DE1D3 - USB Embedded Device Endpoint 1/2 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D3_DE1T30        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 0
DE1D3_DE1T31        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 1
DE1D3_DE1T32        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 2
DE1D3_DE1T33        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 3
DE1D3_DE1T34        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 4
DE1D3_DE1T35        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 5
DE1D3_DE1T36        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 6
DE1D3_DE1T37        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 3 Bit 7
; bit position masks
mDE1D3_DE1T30       equ       %00000001
mDE1D3_DE1T31       equ       %00000010
mDE1D3_DE1T32       equ       %00000100
mDE1D3_DE1T33       equ       %00001000
mDE1D3_DE1T34       equ       %00010000
mDE1D3_DE1T35       equ       %00100000
mDE1D3_DE1T36       equ       %01000000
mDE1D3_DE1T37       equ       %10000000

;*** DE1D4 - USB Embedded Device Endpoint 1/2 Data Register 4
DE1D4               equ       $0000002C           ;*** DE1D4 - USB Embedded Device Endpoint 1/2 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D4_DE1T40        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 0
DE1D4_DE1T41        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 1
DE1D4_DE1T42        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 2
DE1D4_DE1T43        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 3
DE1D4_DE1T44        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 4
DE1D4_DE1T45        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 5
DE1D4_DE1T46        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 6
DE1D4_DE1T47        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 4 Bit 7
; bit position masks
mDE1D4_DE1T40       equ       %00000001
mDE1D4_DE1T41       equ       %00000010
mDE1D4_DE1T42       equ       %00000100
mDE1D4_DE1T43       equ       %00001000
mDE1D4_DE1T44       equ       %00010000
mDE1D4_DE1T45       equ       %00100000
mDE1D4_DE1T46       equ       %01000000
mDE1D4_DE1T47       equ       %10000000

;*** DE1D5 - USB Embedded Device Endpoint 1/2 Data Register 5
DE1D5               equ       $0000002D           ;*** DE1D5 - USB Embedded Device Endpoint 1/2 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D5_DE1T50        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 0
DE1D5_DE1T51        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 1
DE1D5_DE1T52        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 2
DE1D5_DE1T53        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 3
DE1D5_DE1T54        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 4
DE1D5_DE1T55        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 5
DE1D5_DE1T56        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 6
DE1D5_DE1T57        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 5 Bit 7
; bit position masks
mDE1D5_DE1T50       equ       %00000001
mDE1D5_DE1T51       equ       %00000010
mDE1D5_DE1T52       equ       %00000100
mDE1D5_DE1T53       equ       %00001000
mDE1D5_DE1T54       equ       %00010000
mDE1D5_DE1T55       equ       %00100000
mDE1D5_DE1T56       equ       %01000000
mDE1D5_DE1T57       equ       %10000000

;*** DE1D6 - USB Embedded Device Endpoint 1/2 Data Register 6
DE1D6               equ       $0000002E           ;*** DE1D6 - USB Embedded Device Endpoint 1/2 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D6_DE1T60        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 0
DE1D6_DE1T61        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 1
DE1D6_DE1T62        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 2
DE1D6_DE1T63        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 3
DE1D6_DE1T64        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 4
DE1D6_DE1T65        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 5
DE1D6_DE1T66        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 6
DE1D6_DE1T67        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 6 Bit 7
; bit position masks
mDE1D6_DE1T60       equ       %00000001
mDE1D6_DE1T61       equ       %00000010
mDE1D6_DE1T62       equ       %00000100
mDE1D6_DE1T63       equ       %00001000
mDE1D6_DE1T64       equ       %00010000
mDE1D6_DE1T65       equ       %00100000
mDE1D6_DE1T66       equ       %01000000
mDE1D6_DE1T67       equ       %10000000

;*** DE1D7 - USB Embedded Device Endpoint 1/2 Data Register 7
DE1D7               equ       $0000002F           ;*** DE1D7 - USB Embedded Device Endpoint 1/2 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DE1D7_DE1T70        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 0
DE1D7_DE1T71        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 1
DE1D7_DE1T72        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 2
DE1D7_DE1T73        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 3
DE1D7_DE1T74        equ       4                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 4
DE1D7_DE1T75        equ       5                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 5
DE1D7_DE1T76        equ       6                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 6
DE1D7_DE1T77        equ       7                   ; Embedded Device Endpoint 1/2 Transmit Data Buffer 7 Bit 7
; bit position masks
mDE1D7_DE1T70       equ       %00000001
mDE1D7_DE1T71       equ       %00000010
mDE1D7_DE1T72       equ       %00000100
mDE1D7_DE1T73       equ       %00001000
mDE1D7_DE1T74       equ       %00010000
mDE1D7_DE1T75       equ       %00100000
mDE1D7_DE1T76       equ       %01000000
mDE1D7_DE1T77       equ       %10000000

;*** HE0D0 - USB HUB Endpoint 0 Data Register 0
HE0D0               equ       $00000030           ;*** HE0D0 - USB HUB Endpoint 0 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D0_HE0R00_HE0T00 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 0, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R01_HE0T01 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 1, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R02_HE0T02 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 2, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R03_HE0T03 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 3, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R04_HE0T04 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 4, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R05_HE0T05 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 5, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R06_HE0T06 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 6, HUB Endpoint 0 Transmit Data Buffer 0
HE0D0_HE0R07_HE0T07 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 0 Bit 7, HUB Endpoint 0 Transmit Data Buffer 0
; bit position masks
mHE0D0_HE0R00_HE0T00 equ       %00000001
mHE0D0_HE0R01_HE0T01 equ       %00000010
mHE0D0_HE0R02_HE0T02 equ       %00000100
mHE0D0_HE0R03_HE0T03 equ       %00001000
mHE0D0_HE0R04_HE0T04 equ       %00010000
mHE0D0_HE0R05_HE0T05 equ       %00100000
mHE0D0_HE0R06_HE0T06 equ       %01000000
mHE0D0_HE0R07_HE0T07 equ       %10000000

;*** HE0D1 - USB HUB Endpoint 0 Data Register 1
HE0D1               equ       $00000031           ;*** HE0D1 - USB HUB Endpoint 0 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D1_HE0R10_HE0T10 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 0, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R11_HE0T11 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 1, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R12_HE0T12 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 2, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R13_HE0T13 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 3, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R14_HE0T14 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 4, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R15_HE0T15 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 5, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R16_HE0T16 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 6, HUB Endpoint 0 Transmit Data Buffer 1
HE0D1_HE0R17_HE0T17 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 1 Bit 7, HUB Endpoint 0 Transmit Data Buffer 1
; bit position masks
mHE0D1_HE0R10_HE0T10 equ       %00000001
mHE0D1_HE0R11_HE0T11 equ       %00000010
mHE0D1_HE0R12_HE0T12 equ       %00000100
mHE0D1_HE0R13_HE0T13 equ       %00001000
mHE0D1_HE0R14_HE0T14 equ       %00010000
mHE0D1_HE0R15_HE0T15 equ       %00100000
mHE0D1_HE0R16_HE0T16 equ       %01000000
mHE0D1_HE0R17_HE0T17 equ       %10000000

;*** HE0D2 - USB HUB Endpoint 0 Data Register 2
HE0D2               equ       $00000032           ;*** HE0D2 - USB HUB Endpoint 0 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D2_HE0R20_HE0T20 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 0, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R21_HE0T21 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 1, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R22_HE0T22 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 2, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R23_HE0T23 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 3, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R24_HE0T24 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 4, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R25_HE0T25 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 5, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R26_HE0T26 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 6, HUB Endpoint 0 Transmit Data Buffer 2
HE0D2_HE0R27_HE0T27 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 2 Bit 7, HUB Endpoint 0 Transmit Data Buffer 2
; bit position masks
mHE0D2_HE0R20_HE0T20 equ       %00000001
mHE0D2_HE0R21_HE0T21 equ       %00000010
mHE0D2_HE0R22_HE0T22 equ       %00000100
mHE0D2_HE0R23_HE0T23 equ       %00001000
mHE0D2_HE0R24_HE0T24 equ       %00010000
mHE0D2_HE0R25_HE0T25 equ       %00100000
mHE0D2_HE0R26_HE0T26 equ       %01000000
mHE0D2_HE0R27_HE0T27 equ       %10000000

;*** HE0D3 - USB HUB Endpoint 0 Data Register 3
HE0D3               equ       $00000033           ;*** HE0D3 - USB HUB Endpoint 0 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D3_HE0R30_HE0T30 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 0, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R31_HE0T31 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 1, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R32_HE0T32 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 2, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R33_HE0T33 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 3, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R34_HE0T34 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 4, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R35_HE0T35 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 5, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R36_HE0T36 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 6, HUB Endpoint 0 Transmit Data Buffer 3
HE0D3_HE0R37_HE0T37 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 3 Bit 7, HUB Endpoint 0 Transmit Data Buffer 3
; bit position masks
mHE0D3_HE0R30_HE0T30 equ       %00000001
mHE0D3_HE0R31_HE0T31 equ       %00000010
mHE0D3_HE0R32_HE0T32 equ       %00000100
mHE0D3_HE0R33_HE0T33 equ       %00001000
mHE0D3_HE0R34_HE0T34 equ       %00010000
mHE0D3_HE0R35_HE0T35 equ       %00100000
mHE0D3_HE0R36_HE0T36 equ       %01000000
mHE0D3_HE0R37_HE0T37 equ       %10000000

;*** HE0D4 - USB HUB Endpoint 0 Data Register 4
HE0D4               equ       $00000034           ;*** HE0D4 - USB HUB Endpoint 0 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D4_HE0R40_HE0T40 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 0, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R41_HE0T41 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 1, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R42_HE0T42 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 2, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R43_HE0T43 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 3, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R44_HE0T44 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 4, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R45_HE0T45 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 5, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R46_HE0T46 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 6, HUB Endpoint 0 Transmit Data Buffer 4
HE0D4_HE0R47_HE0T47 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 4 Bit 7, HUB Endpoint 0 Transmit Data Buffer 4
; bit position masks
mHE0D4_HE0R40_HE0T40 equ       %00000001
mHE0D4_HE0R41_HE0T41 equ       %00000010
mHE0D4_HE0R42_HE0T42 equ       %00000100
mHE0D4_HE0R43_HE0T43 equ       %00001000
mHE0D4_HE0R44_HE0T44 equ       %00010000
mHE0D4_HE0R45_HE0T45 equ       %00100000
mHE0D4_HE0R46_HE0T46 equ       %01000000
mHE0D4_HE0R47_HE0T47 equ       %10000000

;*** HE0D5 - USB HUB Endpoint 0 Data Register 5
HE0D5               equ       $00000035           ;*** HE0D5 - USB HUB Endpoint 0 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D5_HE0R50_HE0T50 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 0, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R51_HE0T51 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 1, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R52_HE0T52 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 2, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R53_HE0T53 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 3, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R54_HE0T54 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 4, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R55_HE0T55 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 5, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R56_HE0T56 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 6, HUB Endpoint 0 Transmit Data Buffer 5
HE0D5_HE0R57_HE0T57 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 5 Bit 7, HUB Endpoint 0 Transmit Data Buffer 5
; bit position masks
mHE0D5_HE0R50_HE0T50 equ       %00000001
mHE0D5_HE0R51_HE0T51 equ       %00000010
mHE0D5_HE0R52_HE0T52 equ       %00000100
mHE0D5_HE0R53_HE0T53 equ       %00001000
mHE0D5_HE0R54_HE0T54 equ       %00010000
mHE0D5_HE0R55_HE0T55 equ       %00100000
mHE0D5_HE0R56_HE0T56 equ       %01000000
mHE0D5_HE0R57_HE0T57 equ       %10000000

;*** HE0D6 - USB HUB Endpoint 0 Data Register 6
HE0D6               equ       $00000036           ;*** HE0D6 - USB HUB Endpoint 0 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D6_HE0R60_HE0T60 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 0, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R61_HE0T61 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 1, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R62_HE0T62 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 2, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R63_HE0T63 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 3, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R64_HE0T64 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 4, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R65_HE0T65 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 5, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R66_HE0T66 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 6, HUB Endpoint 0 Transmit Data Buffer 6
HE0D6_HE0R67_HE0T67 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 6 Bit 7, HUB Endpoint 0 Transmit Data Buffer 6
; bit position masks
mHE0D6_HE0R60_HE0T60 equ       %00000001
mHE0D6_HE0R61_HE0T61 equ       %00000010
mHE0D6_HE0R62_HE0T62 equ       %00000100
mHE0D6_HE0R63_HE0T63 equ       %00001000
mHE0D6_HE0R64_HE0T64 equ       %00010000
mHE0D6_HE0R65_HE0T65 equ       %00100000
mHE0D6_HE0R66_HE0T66 equ       %01000000
mHE0D6_HE0R67_HE0T67 equ       %10000000

;*** HE0D7 - USB HUB Endpoint 0 Data Register 7
HE0D7               equ       $00000037           ;*** HE0D7 - USB HUB Endpoint 0 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HE0D7_HE0R70_HE0T70 equ       0                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 0, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R71_HE0T71 equ       1                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 1, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R72_HE0T72 equ       2                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 2, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R73_HE0T73 equ       3                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 3, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R74_HE0T74 equ       4                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 4, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R75_HE0T75 equ       5                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 5, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R76_HE0T76 equ       6                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 6, HUB Endpoint 0 Transmit Data Buffer 7
HE0D7_HE0R77_HE0T77 equ       7                   ; HUB Endpoint 0 Receive Data Buffer 7 Bit 7, HUB Endpoint 0 Transmit Data Buffer 7
; bit position masks
mHE0D7_HE0R70_HE0T70 equ       %00000001
mHE0D7_HE0R71_HE0T71 equ       %00000010
mHE0D7_HE0R72_HE0T72 equ       %00000100
mHE0D7_HE0R73_HE0T73 equ       %00001000
mHE0D7_HE0R74_HE0T74 equ       %00010000
mHE0D7_HE0R75_HE0T75 equ       %00100000
mHE0D7_HE0R76_HE0T76 equ       %01000000
mHE0D7_HE0R77_HE0T77 equ       %10000000

;*** PCTL - PLL Control Register
PCTL                equ       $00000038           ;*** PCTL - PLL Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL_BCS            equ       4                   ; Base Clock Select Bit
PCTL_PLLON          equ       5                   ; PLL On Bit
PCTL_PLLF           equ       6                   ; PLL Flag Bit
PCTL_PLLIE          equ       7                   ; PLL Interrupt Enable Bit
; bit position masks
mPCTL_BCS           equ       %00010000
mPCTL_PLLON         equ       %00100000
mPCTL_PLLF          equ       %01000000
mPCTL_PLLIE         equ       %10000000

;*** PBWC - PLL Bandwidth Control Register
PBWC                equ       $00000039           ;*** PBWC - PLL Bandwidth Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PBWC_XLD            equ       4                   ; Crystal Loss Detect Bit
PBWC_ACQ            equ       5                   ; Acquisition Mode Bit
PBWC_LOCK           equ       6                   ; Lock Indicator Bit
PBWC_AUTO           equ       7                   ; Automatic Bandwidth Control Bit
; bit position masks
mPBWC_XLD           equ       %00010000
mPBWC_ACQ           equ       %00100000
mPBWC_LOCK          equ       %01000000
mPBWC_AUTO          equ       %10000000

;*** PPG - PLL Programming Register
PPG                 equ       $0000003A           ;*** PPG - PLL Programming Register
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

;*** ADSCR - ADC Status and Control Register
ADSCR               equ       $0000003B           ;*** ADSCR - ADC Status and Control Register
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
ADR                 equ       $0000003C           ;*** ADR - ADC Data Register
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

;*** ADICLK - ADC Input Clock Register
ADICLK              equ       $0000003D           ;*** ADICLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADICLK_ADIV0        equ       5                   ; ADC Clock Prescaler Bit 0
ADICLK_ADIV1        equ       6                   ; ADC Clock Prescaler Bit 1
ADICLK_ADIV2        equ       7                   ; ADC Clock Prescaler Bit 2
; bit position masks
mADICLK_ADIV0       equ       %00100000
mADICLK_ADIV1       equ       %01000000
mADICLK_ADIV2       equ       %10000000

;*** HVOCR - H & V Sync Output Control Register
HVOCR               equ       $0000003F           ;*** HVOCR - H & V Sync Output Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HVOCR_HVOCR0        equ       0                   ; Free Running Video Mode Select Bit 0
HVOCR_HVOCR1        equ       1                   ; Free Running Video Mode Select Bit 1
HVOCR_DCLKPH0       equ       3                   ; DCLK Output Phase Adjustment Bit 0
HVOCR_DCLKPH1       equ       4                   ; DCLK Output Phase Adjustment Bit 1
; bit position masks
mHVOCR_HVOCR0       equ       %00000001
mHVOCR_HVOCR1       equ       %00000010
mHVOCR_DCLKPH0      equ       %00001000
mHVOCR_DCLKPH1      equ       %00010000

;*** SPCSR - Sync Processor Control and Status Register
SPCSR               equ       $00000040           ;*** SPCSR - Sync Processor Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPCSR_HPOL          equ       0                   ; Hsync Input Polarity
SPCSR_VPOL          equ       1                   ; Vsync Input Polarity
SPCSR_HINVO         equ       2                   ; HOUT Signal Polarity
SPCSR_VINVO         equ       3                   ; VOUT Signal Polarity
SPCSR_COMP          equ       4                   ; Composite Sync Input Enable
SPCSR_VSIF          equ       5                   ; VSync Interrupt Flag
SPCSR_VEDGE         equ       6                   ; VSync Interrupt Edge Select
SPCSR_VSIE          equ       7                   ; VSync Interrupt Enable
; bit position masks
mSPCSR_HPOL         equ       %00000001
mSPCSR_VPOL         equ       %00000010
mSPCSR_HINVO        equ       %00000100
mSPCSR_VINVO        equ       %00001000
mSPCSR_COMP         equ       %00010000
mSPCSR_VSIF         equ       %00100000
mSPCSR_VEDGE        equ       %01000000
mSPCSR_VSIE         equ       %10000000

;*** VFHR - Vertical Frequency Register High
VFHR                equ       $00000041           ;*** VFHR - Vertical Frequency Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VFHR_VF8            equ       0                   ; Vertical Frame Frequency Bit 8
VFHR_VF9            equ       1                   ; Vertical Frame Frequency Bit 9
VFHR_VF10           equ       2                   ; Vertical Frame Frequency Bit 10
VFHR_VF11           equ       3                   ; Vertical Frame Frequency Bit 11
VFHR_VF12           equ       4                   ; Vertical Frame Frequency Bit 12
VFHR_CPW0           equ       5                   ; Clamp Pulse Width Bit 0
VFHR_CPW1           equ       6                   ; Clamp Pulse Width Bit 1
VFHR_VOF            equ       7                   ; Vertical Frequency Counter Overflow
; bit position masks
mVFHR_VF8           equ       %00000001
mVFHR_VF9           equ       %00000010
mVFHR_VF10          equ       %00000100
mVFHR_VF11          equ       %00001000
mVFHR_VF12          equ       %00010000
mVFHR_CPW0          equ       %00100000
mVFHR_CPW1          equ       %01000000
mVFHR_VOF           equ       %10000000

;*** VFLR - Vertical Frequency Register Low
VFLR                equ       $00000042           ;*** VFLR - Vertical Frequency Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VFLR_VF0            equ       0                   ; Vertical Frame Frequency Bit 0
VFLR_VF1            equ       1                   ; Vertical Frame Frequency Bit 1
VFLR_VF2            equ       2                   ; Vertical Frame Frequency Bit 2
VFLR_VF3            equ       3                   ; Vertical Frame Frequency Bit 3
VFLR_VF4            equ       4                   ; Vertical Frame Frequency Bit 4
VFLR_VF5            equ       5                   ; Vertical Frame Frequency Bit 5
VFLR_VF6            equ       6                   ; Vertical Frame Frequency Bit 6
VFLR_VF7            equ       7                   ; Vertical Frame Frequency Bit 7
; bit position masks
mVFLR_VF0           equ       %00000001
mVFLR_VF1           equ       %00000010
mVFLR_VF2           equ       %00000100
mVFLR_VF3           equ       %00001000
mVFLR_VF4           equ       %00010000
mVFLR_VF5           equ       %00100000
mVFLR_VF6           equ       %01000000
mVFLR_VF7           equ       %10000000

;*** HFHR - Hsync Frequency Register High
HFHR                equ       $00000043           ;*** HFHR - Hsync Frequency Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HFHR_HFH0           equ       0                   ; Horizontal Line Frequency Bit 0
HFHR_HFH1           equ       1                   ; Horizontal Line Frequency Bit 1
HFHR_HFH2           equ       2                   ; Horizontal Line Frequency Bit 2
HFHR_HFH3           equ       3                   ; Horizontal Line Frequency Bit 3
HFHR_HFH4           equ       4                   ; Horizontal Line Frequency Bit 4
HFHR_HFH5           equ       5                   ; Horizontal Line Frequency Bit 5
HFHR_HFH6           equ       6                   ; Horizontal Line Frequency Bit 6
HFHR_HFH7           equ       7                   ; Horizontal Line Frequency Bit 7
; bit position masks
mHFHR_HFH0          equ       %00000001
mHFHR_HFH1          equ       %00000010
mHFHR_HFH2          equ       %00000100
mHFHR_HFH3          equ       %00001000
mHFHR_HFH4          equ       %00010000
mHFHR_HFH5          equ       %00100000
mHFHR_HFH6          equ       %01000000
mHFHR_HFH7          equ       %10000000

;*** HFLR - Hsync Frequency Register Low
HFLR                equ       $00000044           ;*** HFLR - Hsync Frequency Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HFLR_HFL0           equ       0                   ; Horizontal Line Frequency Bit 0
HFLR_HFL1           equ       1                   ; Horizontal Line Frequency Bit 1
HFLR_HFL2           equ       2                   ; Horizontal Line Frequency Bit 2
HFLR_HFL3           equ       3                   ; Horizontal Line Frequency Bit 3
HFLR_HFL4           equ       4                   ; Horizontal Line Frequency Bit 4
HFLR_HOVER          equ       7                   ; Hsync Frequency Counter Overflow
; bit position masks
mHFLR_HFL0          equ       %00000001
mHFLR_HFL1          equ       %00000010
mHFLR_HFL2          equ       %00000100
mHFLR_HFL3          equ       %00001000
mHFLR_HFL4          equ       %00010000
mHFLR_HOVER         equ       %10000000

;*** SPIOCR - Sync Processor Input/Output Control Register
SPIOCR              equ       $00000045           ;*** SPIOCR - Sync Processor Input/Output Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIOCR_SOUT         equ       0                   ; Sync Output Enable
SPIOCR_BPOR         equ       1                   ; Back Porch
SPIOCR_COINV        equ       5                   ; Clamp Output Invert
SPIOCR_HSYNCS       equ       6                   ; HSYNC Input State
SPIOCR_VSYNCS       equ       7                   ; VSYNC Input State
; bit position masks
mSPIOCR_SOUT        equ       %00000001
mSPIOCR_BPOR        equ       %00000010
mSPIOCR_COINV       equ       %00100000
mSPIOCR_HSYNCS      equ       %01000000
mSPIOCR_VSYNCS      equ       %10000000

;*** SPCR1 - Sync Processor Control Register 1
SPCR1               equ       $00000046           ;*** SPCR1 - Sync Processor Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPCR1_FSHF          equ       0                   ; Fast Horizontal Frequency Count
SPCR1_ATPOL         equ       1                   ; Auto Polarity
SPCR1_HPS0          equ       4                   ; HSYNC Input Detection Pulse Width Bit 0
SPCR1_HPS1          equ       5                   ; HSYNC Input Detection Pulse Width Bit 1
SPCR1_LVSIF         equ       6                   ; Low VSync Interrupt Flag
SPCR1_LVSIE         equ       7                   ; Low VSync Interrupt Enable
; bit position masks
mSPCR1_FSHF         equ       %00000001
mSPCR1_ATPOL        equ       %00000010
mSPCR1_HPS0         equ       %00010000
mSPCR1_HPS1         equ       %00100000
mSPCR1_LVSIF        equ       %01000000
mSPCR1_LVSIE        equ       %10000000

;*** DCR2 - USB Embedded Device Control Register 2
DCR2                equ       $00000047           ;*** DCR2 - USB Embedded Device Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DCR2_DSTALL1        equ       0                   ; Embedded Device Endpoint 1 Force Stall Bit
DCR2_DSTALL2        equ       1                   ; Embedded Device Endpoint 2 Force Stall Bit
DCR2_ENABLE1        equ       2                   ; Embedded Device Endpoint 1 Enable
DCR2_ENABLE2        equ       3                   ; Embedded Device Endpoint 2 Enable
; bit position masks
mDCR2_DSTALL1       equ       %00000001
mDCR2_DSTALL2       equ       %00000010
mDCR2_ENABLE1       equ       %00000100
mDCR2_ENABLE2       equ       %00001000

;*** DADDR - USB Embedded Device Address Register
DADDR               equ       $00000048           ;*** DADDR - USB Embedded Device Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DADDR_DADD0         equ       0                   ; USB Embedded Device Function Address Bit 0
DADDR_DADD1         equ       1                   ; USB Embedded Device Function Address Bit 1
DADDR_DADD2         equ       2                   ; USB Embedded Device Function Address Bit 2
DADDR_DADD3         equ       3                   ; USB Embedded Device Function Address Bit 3
DADDR_DADD4         equ       4                   ; USB Embedded Device Function Address Bit 4
DADDR_DADD5         equ       5                   ; USB Embedded Device Function Address Bit 5
DADDR_DADD6         equ       6                   ; USB Embedded Device Function Address Bit 6
DADDR_DEVEN         equ       7                   ; Enable USB Embedded Device
; bit position masks
mDADDR_DADD0        equ       %00000001
mDADDR_DADD1        equ       %00000010
mDADDR_DADD2        equ       %00000100
mDADDR_DADD3        equ       %00001000
mDADDR_DADD4        equ       %00010000
mDADDR_DADD5        equ       %00100000
mDADDR_DADD6        equ       %01000000
mDADDR_DEVEN        equ       %10000000

;*** DIR0 - USB Embedded Device Interrupt Register 0
DIR0                equ       $00000049           ;*** DIR0 - USB Embedded Device Interrupt Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DIR0_RXD0FR         equ       0                   ; Embedded Device Endpoint 0 Receive Flag Reset
DIR0_TXD0FR         equ       1                   ; Embedded Device Endpoint 0 Transmit Flag Reset
DIR0_RXD0IE         equ       2                   ; Embedded Device Endpoint Endpoint 0 Receive Interrupt Enable
DIR0_TXD0IE         equ       3                   ; Embedded Device Endpoint Endpoint 0 Transmit Interrupt Enable
DIR0_RXD0F          equ       6                   ; Embedded Device Endpoint 0 Data Receive Flag
DIR0_TXD0F          equ       7                   ; Embedded Device Endpoint 0 Data Transmit Flag
; bit position masks
mDIR0_RXD0FR        equ       %00000001
mDIR0_TXD0FR        equ       %00000010
mDIR0_RXD0IE        equ       %00000100
mDIR0_TXD0IE        equ       %00001000
mDIR0_RXD0F         equ       %01000000
mDIR0_TXD0F         equ       %10000000

;*** DIR1 - USB Embedded Device Interrupt Register 1
DIR1                equ       $0000004A           ;*** DIR1 - USB Embedded Device Interrupt Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DIR1_TXD1FR         equ       1                   ; Embedded Device Endpoint 1/2 Transmit Flag Reset
DIR1_TXD1IE         equ       3                   ; Embedded Device Endpoint 1/2 Transmit Interrupt Enable
DIR1_TXD1F          equ       7                   ; Embedded Device Endpoint 1/2 Data Transmit Flag
; bit position masks
mDIR1_TXD1FR        equ       %00000010
mDIR1_TXD1IE        equ       %00001000
mDIR1_TXD1F         equ       %10000000

;*** DCR0 - USB Embedded Device Control Register 0
DCR0                equ       $0000004B           ;*** DCR0 - USB Embedded Device Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DCR0_TP0SIZ0        equ       0                   ; Embedded Device Endpoint 0 Transmit Data Packet Size Bit 0
DCR0_TP0SIZ1        equ       1                   ; Embedded Device Endpoint 0 Transmit Data Packet Size Bit 1
DCR0_TP0SIZ2        equ       2                   ; Embedded Device Endpoint 0 Transmit Data Packet Size Bit 2
DCR0_TP0SIZ3        equ       3                   ; Embedded Device Endpoint 0 Transmit Data Packet Size Bit 3
DCR0_RX0E           equ       4                   ; Embedded Device Endpoint 0 Receive Enable
DCR0_TX0E           equ       5                   ; Embedded Device Endpoint 0 Transmit Enable
DCR0_DSTALL0        equ       6                   ; Embedded Device Endpoint 0 Force Stall Bit
DCR0_T0SEQ          equ       7                   ; Embedded Device Endpoint 0 Transmit Sequence Bit
; bit position masks
mDCR0_TP0SIZ0       equ       %00000001
mDCR0_TP0SIZ1       equ       %00000010
mDCR0_TP0SIZ2       equ       %00000100
mDCR0_TP0SIZ3       equ       %00001000
mDCR0_RX0E          equ       %00010000
mDCR0_TX0E          equ       %00100000
mDCR0_DSTALL0       equ       %01000000
mDCR0_T0SEQ         equ       %10000000

;*** DCR1 - USB Embedded Device Control Register 1
DCR1                equ       $0000004C           ;*** DCR1 - USB Embedded Device Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DCR1_TP1SIZ0        equ       0                   ; Embedded Device Endpoint 1/2 Transmit Data Packet Size Bit 0
DCR1_TP1SIZ1        equ       1                   ; Embedded Device Endpoint 1/2 Transmit Data Packet Size Bit 1
DCR1_TP1SIZ2        equ       2                   ; Embedded Device Endpoint 1/2 Transmit Data Packet Size Bit 2
DCR1_TP1SIZ3        equ       3                   ; Embedded Device Endpoint 1/2 Transmit Data Packet Size Bit 3
DCR1_TX1E           equ       5                   ; Embedded Device Endpoint 1/2 Transmit Enable
DCR1_ENDADD         equ       6                   ; Endpoint Address Select
DCR1_T1SEQ          equ       7                   ; Embedded Device Endpoint 1/2 Transmit Sequence Bit
; bit position masks
mDCR1_TP1SIZ0       equ       %00000001
mDCR1_TP1SIZ1       equ       %00000010
mDCR1_TP1SIZ2       equ       %00000100
mDCR1_TP1SIZ3       equ       %00001000
mDCR1_TX1E          equ       %00100000
mDCR1_ENDADD        equ       %01000000
mDCR1_T1SEQ         equ       %10000000

;*** DSR - USB Embedded Device Statsu Register
DSR                 equ       $0000004D           ;*** DSR - USB Embedded Device Statsu Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR_RP0SIZ0         equ       0                   ; Embedded Device Endpoint 0 Receive Data Packet Size Bit 0
DSR_RP0SIZ1         equ       1                   ; Embedded Device Endpoint 0 Receive Data Packet Size Bit 1
DSR_RP0SIZ2         equ       2                   ; Embedded Device Endpoint 0 Receive Data Packet Size Bit 2
DSR_RP0SIZ3         equ       3                   ; Embedded Device Endpoint 0 Receive Data Packet Size Bit 3
DSR_DTX1STR         equ       4                   ; Clear Transmit First Flag
DSR_DTX1ST          equ       5                   ; Embedded Device Transmit First Flag
DSR_DSETUP          equ       6                   ; Embedded Device SETUP Token Detect Bit
DSR_DRSEQ           equ       7                   ; Embedded Device Endpoint 0 Receive Sequence Bit
; bit position masks
mDSR_RP0SIZ0        equ       %00000001
mDSR_RP0SIZ1        equ       %00000010
mDSR_RP0SIZ2        equ       %00000100
mDSR_RP0SIZ3        equ       %00001000
mDSR_DTX1STR        equ       %00010000
mDSR_DTX1ST         equ       %00100000
mDSR_DSETUP         equ       %01000000
mDSR_DRSEQ          equ       %10000000

;*** KBSCR - Keyboard Status and Control Register
KBSCR               equ       $0000004E           ;*** KBSCR - Keyboard Status and Control Register
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
KBIER               equ       $0000004F           ;*** KBIER - Keyboard Interrupt Enable Register
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

;*** HDP1CR - USB HUB Downstream Port 1 Control Register
HDP1CR              equ       $00000051           ;*** HDP1CR - USB HUB Downstream Port 1 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HDP1CR_D1MINUS      equ       0                   ; Downstream Port Differential Data MINUS
HDP1CR_D1PLUS       equ       1                   ; Downstream Port Differential Data PLUS
HDP1CR_SUSP1        equ       3                   ; Downstream Port Selective Suspend Bit
HDP1CR_RESUM1       equ       4                   ; Force Resume to the Downstream Port
HDP1CR_RST1         equ       5                   ; Force Reset to the Downstream Port
HDP1CR_LOWSP1       equ       6                   ; Full-Speed / Low-Speed Port Control Bit
HDP1CR_PEN1         equ       7                   ; Downstream Port Enable Control Bit
; bit position masks
mHDP1CR_D1MINUS     equ       %00000001
mHDP1CR_D1PLUS      equ       %00000010
mHDP1CR_SUSP1       equ       %00001000
mHDP1CR_RESUM1      equ       %00010000
mHDP1CR_RST1        equ       %00100000
mHDP1CR_LOWSP1      equ       %01000000
mHDP1CR_PEN1        equ       %10000000

;*** HDP2CR - USB HUB Downstream Port 2 Control Register
HDP2CR              equ       $00000052           ;*** HDP2CR - USB HUB Downstream Port 2 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HDP2CR_D2MINUS      equ       0                   ; Downstream Port Differential Data MINUS
HDP2CR_D2PLUS       equ       1                   ; Downstream Port Differential Data PLUS
HDP2CR_SUSP2        equ       3                   ; Downstream Port Selective Suspend Bit
HDP2CR_RESUM2       equ       4                   ; Force Resume to the Downstream Port
HDP2CR_RST2         equ       5                   ; Force Reset to the Downstream Port
HDP2CR_LOWSP2       equ       6                   ; Full-Speed / Low-Speed Port Control Bit
HDP2CR_PEN2         equ       7                   ; Downstream Port Enable Control Bit
; bit position masks
mHDP2CR_D2MINUS     equ       %00000001
mHDP2CR_D2PLUS      equ       %00000010
mHDP2CR_SUSP2       equ       %00001000
mHDP2CR_RESUM2      equ       %00010000
mHDP2CR_RST2        equ       %00100000
mHDP2CR_LOWSP2      equ       %01000000
mHDP2CR_PEN2        equ       %10000000

;*** HDP3CR - USB HUB Downstream Port 3 Control Register
HDP3CR              equ       $00000053           ;*** HDP3CR - USB HUB Downstream Port 3 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HDP3CR_D3MINUS      equ       0                   ; Downstream Port Differential Data MINUS
HDP3CR_D3PLUS       equ       1                   ; Downstream Port Differential Data PLUS
HDP3CR_SUSP3        equ       3                   ; Downstream Port Selective Suspend Bit
HDP3CR_RESUM3       equ       4                   ; Force Resume to the Downstream Port
HDP3CR_RST3         equ       5                   ; Force Reset to the Downstream Port
HDP3CR_LOWSP3       equ       6                   ; Full-Speed / Low-Speed Port Control Bit
HDP3CR_PEN3         equ       7                   ; Downstream Port Enable Control Bit
; bit position masks
mHDP3CR_D3MINUS     equ       %00000001
mHDP3CR_D3PLUS      equ       %00000010
mHDP3CR_SUSP3       equ       %00001000
mHDP3CR_RESUM3      equ       %00010000
mHDP3CR_RST3        equ       %00100000
mHDP3CR_LOWSP3      equ       %01000000
mHDP3CR_PEN3        equ       %10000000

;*** HDP4CR - USB HUB Downstream Port 4 Control Register
HDP4CR              equ       $00000054           ;*** HDP4CR - USB HUB Downstream Port 4 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HDP4CR_D4MINUS      equ       0                   ; Downstream Port Differential Data MINUS
HDP4CR_D4PLUS       equ       1                   ; Downstream Port Differential Data PLUS
HDP4CR_SUSP4        equ       3                   ; Downstream Port Selective Suspend Bit
HDP4CR_RESUM4       equ       4                   ; Force Resume to the Downstream Port
HDP4CR_RST4         equ       5                   ; Force Reset to the Downstream Port
HDP4CR_LOWSP4       equ       6                   ; Full-Speed / Low-Speed Port Control Bit
HDP4CR_PEN4         equ       7                   ; Downstream Port Enable Control Bit
; bit position masks
mHDP4CR_D4MINUS     equ       %00000001
mHDP4CR_D4PLUS      equ       %00000010
mHDP4CR_SUSP4       equ       %00001000
mHDP4CR_RESUM4      equ       %00010000
mHDP4CR_RST4        equ       %00100000
mHDP4CR_LOWSP4      equ       %01000000
mHDP4CR_PEN4        equ       %10000000

;*** SIETIR - USB SIE Timing Interrupt Register
SIETIR              equ       $00000056           ;*** SIETIR - USB SIE Timing Interrupt Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIETIR_TRANIE       equ       0                   ; Bus Signal Transition Detect Interrupt Enable
SIETIR_EOPIE        equ       1                   ; End of Packet Detect Interrupt Enable
SIETIR_OEF2IE       equ       2                   ; The Second End Of Frame Point Interrupt Enable
SIETIR_SOFIE        equ       3                   ; Start Of Frame Interrupt Enable
SIETIR_TRANF        equ       4                   ; Bus Signal Transition Detect Flag
SIETIR_EOPF         equ       5                   ; End of Packet Detect Flag
SIETIR_EOF2F        equ       6                   ; Second End Of Frame Point Flag
SIETIR_SOFF         equ       7                   ; Start Of Frame Detect Flag
; bit position masks
mSIETIR_TRANIE      equ       %00000001
mSIETIR_EOPIE       equ       %00000010
mSIETIR_OEF2IE      equ       %00000100
mSIETIR_SOFIE       equ       %00001000
mSIETIR_TRANF       equ       %00010000
mSIETIR_EOPF        equ       %00100000
mSIETIR_EOF2F       equ       %01000000
mSIETIR_SOFF        equ       %10000000

;*** SIETSR - USB SIE Timing Status Register
SIETSR              equ       $00000057           ;*** SIETSR - USB SIE Timing Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIETSR_TRANFR       equ       0                   ; Bus Signal Transition Flag Reset
SIETSR_EOPFR        equ       1                   ; End of Packet Flag Reset
SIETSR_EOF2FR       equ       2                   ; The second End of Frame Point Flag Reset
SIETSR_LOCKFR       equ       3                   ; Clear Frame Timer Locked Flag
SIETSR_SOFFR        equ       4                   ; Start Of Frame Flag Reset
SIETSR_LOCKF        equ       5                   ; USB Frame Timer Locked
SIETSR_RSTFR        equ       6                   ; Clear Reset Flag Bit
SIETSR_RSTF         equ       7                   ; USB Reset Flag
; bit position masks
mSIETSR_TRANFR      equ       %00000001
mSIETSR_EOPFR       equ       %00000010
mSIETSR_EOF2FR      equ       %00000100
mSIETSR_LOCKFR      equ       %00001000
mSIETSR_SOFFR       equ       %00010000
mSIETSR_LOCKF       equ       %00100000
mSIETSR_RSTFR       equ       %01000000
mSIETSR_RSTF        equ       %10000000

;*** HADDR - USB HUB Address Register
HADDR               equ       $00000058           ;*** HADDR - USB HUB Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HADDR_ADD0          equ       0                   ; USB HUB Function Address Bit 0
HADDR_ADD1          equ       1                   ; USB HUB Function Address Bit 1
HADDR_ADD2          equ       2                   ; USB HUB Function Address Bit 2
HADDR_ADD3          equ       3                   ; USB HUB Function Address Bit 3
HADDR_ADD4          equ       4                   ; USB HUB Function Address Bit 4
HADDR_ADD5          equ       5                   ; USB HUB Function Address Bit 5
HADDR_ADD6          equ       6                   ; USB HUB Function Address Bit 6
HADDR_USBEN         equ       7                   ; USB Module Enable
; bit position masks
mHADDR_ADD0         equ       %00000001
mHADDR_ADD1         equ       %00000010
mHADDR_ADD2         equ       %00000100
mHADDR_ADD3         equ       %00001000
mHADDR_ADD4         equ       %00010000
mHADDR_ADD5         equ       %00100000
mHADDR_ADD6         equ       %01000000
mHADDR_USBEN        equ       %10000000

;*** HIR0 - USB HUB Interrupt Register 0
HIR0                equ       $00000059           ;*** HIR0 - USB HUB Interrupt Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HIR0_RXDFR          equ       0                   ; Hub Endpoint 0 Receive Flag Reset
HIR0_TXDFR          equ       1                   ; Hub Endpoint 0 Transmit Flag Reset
HIR0_RXDIE          equ       2                   ; Hub Endpoint 0 Receive Interrupt Enable
HIR0_TXDIE          equ       3                   ; Hub Endpoint 0 Transmit Interrupt Enable
HIR0_RXDF           equ       6                   ; Hub Endpoint 0 Data Receive Flag
HIR0_TXDF           equ       7                   ; Hub Endpoint 0 Data Transmit Flag
; bit position masks
mHIR0_RXDFR         equ       %00000001
mHIR0_TXDFR         equ       %00000010
mHIR0_RXDIE         equ       %00000100
mHIR0_TXDIE         equ       %00001000
mHIR0_RXDF          equ       %01000000
mHIR0_TXDF          equ       %10000000

;*** HCR0 - USB Hub Control Register 0
HCR0                equ       $0000005B           ;*** HCR0 - USB Hub Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HCR0_TPSIZ0         equ       0                   ; Hub Endpoint 0 Transmit Data Packet Size Bit 0
HCR0_TPSIZ1         equ       1                   ; Hub Endpoint 0 Transmit Data Packet Size Bit 1
HCR0_TPSIZ2         equ       2                   ; Hub Endpoint 0 Transmit Data Packet Size Bit 2
HCR0_TPSIZ3         equ       3                   ; Hub Endpoint 0 Transmit Data Packet Size Bit 3
HCR0_RXE            equ       4                   ; Hub Endpoint 0 Receive Enable
HCR0_TXE            equ       5                   ; Hub Endpoint 0 Transmit Enable
HCR0_STALL0         equ       6                   ; Hub Endpoint 0 Force Stall Bit
HCR0_TSEQ           equ       7                   ; Hub Endpoint 0 Transmit Sequence Bit
; bit position masks
mHCR0_TPSIZ0        equ       %00000001
mHCR0_TPSIZ1        equ       %00000010
mHCR0_TPSIZ2        equ       %00000100
mHCR0_TPSIZ3        equ       %00001000
mHCR0_RXE           equ       %00010000
mHCR0_TXE           equ       %00100000
mHCR0_STALL0        equ       %01000000
mHCR0_TSEQ          equ       %10000000

;*** HCDR - USB Hub Endpoint 1 Control and Data Register
HCDR                equ       $0000005C           ;*** HCDR - USB Hub Endpoint 1 Control and Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HCDR_PCHG0          equ       0                   ; Hub and Port Status Change Bitmap Bit 0
HCDR_PCHG1          equ       1                   ; Hub and Port Status Change Bitmap Bit 1
HCDR_PCHG2          equ       2                   ; Hub and Port Status Change Bitmap Bit 2
HCDR_PCHG3          equ       3                   ; Hub and Port Status Change Bitmap Bit 3
HCDR_PCHG4          equ       4                   ; Hub and Port Status Change Bitmap Bit 4
HCDR_PCHG5          equ       5                   ; Hub and Port Status Change Bitmap Bit 5
HCDR_PNEW           equ       6                   ; Port New Status Change
HCDR_STALL1         equ       7                   ; Hub Endpoint 1 Force Stall Bit
; bit position masks
mHCDR_PCHG0         equ       %00000001
mHCDR_PCHG1         equ       %00000010
mHCDR_PCHG2         equ       %00000100
mHCDR_PCHG3         equ       %00001000
mHCDR_PCHG4         equ       %00010000
mHCDR_PCHG5         equ       %00100000
mHCDR_PNEW          equ       %01000000
mHCDR_STALL1        equ       %10000000

;*** HSR - USB Hub Status Register
HSR                 equ       $0000005D           ;*** HSR - USB Hub Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSR_PRSIZ0          equ       0                   ; Hub Endpoint 0 Receive Data Packet Size Bit 0
HSR_PRSIZ1          equ       1                   ; Hub Endpoint 0 Receive Data Packet Size Bit 1
HSR_PRSIZ2          equ       2                   ; Hub Endpoint 0 Receive Data Packet Size Bit 2
HSR_PRSIZ3          equ       3                   ; Hub Endpoint 0 Receive Data Packet Size Bit 3
HSR_TX1STR          equ       4                   ; Clear Hub Transmit First Flag
HSR_TX1ST           equ       5                   ; Hub Transmit First Flag
HSR_SETUP           equ       6                   ; Hub SETUP Token Detect Bit
HSR_RSEQ            equ       7                   ; Hub Endpoint 0 Receive Sequence Bit
; bit position masks
mHSR_PRSIZ0         equ       %00000001
mHSR_PRSIZ1         equ       %00000010
mHSR_PRSIZ2         equ       %00000100
mHSR_PRSIZ3         equ       %00001000
mHSR_TX1STR         equ       %00010000
mHSR_TX1ST          equ       %00100000
mHSR_SETUP          equ       %01000000
mHSR_RSEQ           equ       %10000000

;*** HRPCR - USB Hub Root Port Control Register
HRPCR               equ       $0000005E           ;*** HRPCR - USB Hub Root Port Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPCR_D0MINUS       equ       0                   ; Root Port Differential Data MINUS
HRPCR_D0PLUS        equ       1                   ; Root Port Differential Data PLUS
HRPCR_SUSPND        equ       3                   ; USB Suspend Control Bit
HRPCR_RESUM0        equ       4                   ; Force Resume to the Root Port
; bit position masks
mHRPCR_D0MINUS      equ       %00000001
mHRPCR_D0PLUS       equ       %00000010
mHRPCR_SUSPND       equ       %00001000
mHRPCR_RESUM0       equ       %00010000

;*** OSDCR - OSD Control Register
OSDCR               equ       $00000060           ;*** OSDCR - OSD Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDCR_OSDIEN        equ       0                   ; OSD Interrupt Enable
OSDCR_HALFCLK       equ       1                   ; Half Frequency of Pixel Clock
OSDCR_CLKPH0        equ       2                   ; Pixel Clock Phase Adjustment Bit 0
OSDCR_CLKPH1        equ       3                   ; Pixel Clock Phase Adjustment Bit 1
OSDCR_CLKINV        equ       4                   ; Pixel Clock Inversion
OSDCR_OSDRST        equ       5                   ; OSD Module Reset
OSDCR_OSDMEN        equ       7                   ; OSD Memory Enable
; bit position masks
mOSDCR_OSDIEN       equ       %00000001
mOSDCR_HALFCLK      equ       %00000010
mOSDCR_CLKPH0       equ       %00000100
mOSDCR_CLKPH1       equ       %00001000
mOSDCR_CLKINV       equ       %00010000
mOSDCR_OSDRST       equ       %00100000
mOSDCR_OSDMEN       equ       %10000000

;*** OSDSR - OSD Status Register
OSDSR               equ       $00000061           ;*** OSDSR - OSD Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDSR_#endif        equ       0                   ; OSD Display Interrupt End
OSDSR_WRDY          equ       7                   ; OSD Buffer Write Ready
; bit position masks
mOSDSR_#endif       equ       %00000001
mOSDSR_WRDY         equ       %10000000

;*** OSDDR - OSD Data Register
OSDDR               equ       $00000062           ;*** OSDDR - OSD Data Register

;*** OSDDRL - OSD Data Register Low
OSDDRL              equ       $00000062           ;*** OSDDRL - OSD Data Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDDRL_OSDD0        equ       0                   ; OSD Data Bit 0
OSDDRL_OSDD1        equ       1                   ; OSD Data Bit 1
OSDDRL_OSDD2        equ       2                   ; OSD Data Bit 2
OSDDRL_OSDD3        equ       3                   ; OSD Data Bit 3
OSDDRL_OSDD4        equ       4                   ; OSD Data Bit 4
OSDDRL_OSDD5        equ       5                   ; OSD Data Bit 5
OSDDRL_OSDD6        equ       6                   ; OSD Data Bit 6
OSDDRL_OSDD7        equ       7                   ; OSD Data Bit 7
; bit position masks
mOSDDRL_OSDD0       equ       %00000001
mOSDDRL_OSDD1       equ       %00000010
mOSDDRL_OSDD2       equ       %00000100
mOSDDRL_OSDD3       equ       %00001000
mOSDDRL_OSDD4       equ       %00010000
mOSDDRL_OSDD5       equ       %00100000
mOSDDRL_OSDD6       equ       %01000000
mOSDDRL_OSDD7       equ       %10000000

;*** OSDDRH - OSD Data Register High
OSDDRH              equ       $00000063           ;*** OSDDRH - OSD Data Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDDRH_OSDD8        equ       0                   ; OSD Data Bit 8
OSDDRH_OSDD9        equ       1                   ; OSD Data Bit 9
OSDDRH_OSDD10       equ       2                   ; OSD Data Bit 10
OSDDRH_OSDD11       equ       3                   ; OSD Data Bit 11
OSDDRH_OSDD12       equ       4                   ; OSD Data Bit 12
OSDDRH_OSDD13       equ       5                   ; OSD Data Bit 13
OSDDRH_OSDD14       equ       6                   ; OSD Data Bit 14
OSDDRH_OSDD15       equ       7                   ; OSD Data Bit 15
; bit position masks
mOSDDRH_OSDD8       equ       %00000001
mOSDDRH_OSDD9       equ       %00000010
mOSDDRH_OSDD10      equ       %00000100
mOSDDRH_OSDD11      equ       %00001000
mOSDDRH_OSDD12      equ       %00010000
mOSDDRH_OSDD13      equ       %00100000
mOSDDRH_OSDD14      equ       %01000000
mOSDDRH_OSDD15      equ       %10000000

;*** OSDRAR - OSD Row Address Register
OSDRAR              equ       $00000064           ;*** OSDRAR - OSD Row Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDRAR_ROWA0        equ       0                   ; OSD Row Address Bit 0
OSDRAR_ROWA1        equ       1                   ; OSD Row Address Bit 1
OSDRAR_ROWA2        equ       2                   ; OSD Row Address Bit 2
OSDRAR_ROWA3        equ       3                   ; OSD Row Address Bit 3
; bit position masks
mOSDRAR_ROWA0       equ       %00000001
mOSDRAR_ROWA1       equ       %00000010
mOSDRAR_ROWA2       equ       %00000100
mOSDRAR_ROWA3       equ       %00001000

;*** OSDCAR - OSD Column Address Register
OSDCAR              equ       $00000065           ;*** OSDCAR - OSD Column Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDCAR_COLA0        equ       0                   ; OSD RAM Column Address Bit 0
OSDCAR_COLA1        equ       1                   ; OSD RAM Column Address Bit 1
OSDCAR_COLA2        equ       2                   ; OSD RAM Column Address Bit 2
OSDCAR_COLA3        equ       3                   ; OSD RAM Column Address Bit 3
OSDCAR_COLA4        equ       4                   ; OSD RAM Column Address Bit 4
; bit position masks
mOSDCAR_COLA0       equ       %00000001
mOSDCAR_COLA1       equ       %00000010
mOSDCAR_COLA2       equ       %00000100
mOSDCAR_COLA3       equ       %00001000
mOSDCAR_COLA4       equ       %00010000

;*** OSDEHBUF - OSD FLASH Even High Byte Write Buffer
OSDEHBUF            equ       $00000066           ;*** OSDEHBUF - OSD FLASH Even High Byte Write Buffer
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSDEHBUF_DOT8       equ       0                   ; OSD FLASH Even High Byte Buffer Bit 8
OSDEHBUF_DOT9       equ       1                   ; OSD FLASH Even High Byte Buffer Bit 9
OSDEHBUF_DOT10      equ       2                   ; OSD FLASH Even High Byte Buffer Bit 10
OSDEHBUF_DOT11      equ       3                   ; OSD FLASH Even High Byte Buffer Bit 11
OSDEHBUF_DOT12      equ       4                   ; OSD FLASH Even High Byte Buffer Bit 12
OSDEHBUF_DOT13      equ       5                   ; OSD FLASH Even High Byte Buffer Bit 13
OSDEHBUF_DOT14      equ       6                   ; OSD FLASH Even High Byte Buffer Bit 14
OSDEHBUF_DOT15      equ       7                   ; OSD FLASH Even High Byte Buffer Bit 15
; bit position masks
mOSDEHBUF_DOT8      equ       %00000001
mOSDEHBUF_DOT9      equ       %00000010
mOSDEHBUF_DOT10     equ       %00000100
mOSDEHBUF_DOT11     equ       %00001000
mOSDEHBUF_DOT12     equ       %00010000
mOSDEHBUF_DOT13     equ       %00100000
mOSDEHBUF_DOT14     equ       %01000000
mOSDEHBUF_DOT15     equ       %10000000

;*** PECR - Port E Control Register
PECR                equ       $00000068           ;*** PECR - Port E Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PECR_USBDS1E        equ       0                   ; USB HUB Data Pin 1 Enable
PECR_USBDS2E        equ       1                   ; USB HUB Data Pin 2 Enable
PECR_USBDS3E        equ       2                   ; USB HUB Data Pin 3 Enable
PECR_USBDS4E        equ       3                   ; USB HUB Data Pin 4 Enable
; bit position masks
mPECR_USBDS1E       equ       %00000001
mPECR_USBDS2E       equ       %00000010
mPECR_USBDS3E       equ       %00000100
mPECR_USBDS4E       equ       %00001000

;*** PDCR - Port D Configuration Register
PDCR                equ       $00000069           ;*** PDCR - Port D Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDCR_DCLKE          equ       0                   ; DCLK Pin Enable
PDCR_DEE            equ       1                   ; DE Pin Enable
PDCR_VOUTE          equ       2                   ; VOUT Pin Enable
PDCR_HOUTE          equ       3                   ; HOUT Pin Enable
PDCR_DDCSCLE        equ       4                   ; DDC Clock Pin Enable
PDCR_DDCDATE        equ       5                   ; DDC Data Pin Enable
PDCR_IICSCLE        equ       6                   ; MMIIC Clock Pin Enable
PDCR_IICDATE        equ       7                   ; MMIIC Data Pin Enable
; bit position masks
mPDCR_DCLKE         equ       %00000001
mPDCR_DEE           equ       %00000010
mPDCR_VOUTE         equ       %00000100
mPDCR_HOUTE         equ       %00001000
mPDCR_DDCSCLE       equ       %00010000
mPDCR_DDCDATE       equ       %00100000
mPDCR_IICSCLE       equ       %01000000
mPDCR_IICDATE       equ       %10000000

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
MMCR_MMTXAK         equ       3                   ; Transmit Acknowledge Enable
MMCR_MMIEN          equ       6                   ; Multi-Master IIC Interrupt Enable
MMCR_MMEN           equ       7                   ; Multi-Master IIC Enable
; bit position masks
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
MMDTR_MMTD0         equ       0                   ; Multi-Master IIC Transmit Data Bit 0
MMDTR_MMTD1         equ       1                   ; Multi-Master IIC Transmit Data Bit 1
MMDTR_MMTD2         equ       2                   ; Multi-Master IIC Transmit Data Bit 2
MMDTR_MMTD3         equ       3                   ; Multi-Master IIC Transmit Data Bit 3
MMDTR_MMTD4         equ       4                   ; Multi-Master IIC Transmit Data Bit 4
MMDTR_MMTD5         equ       5                   ; Multi-Master IIC Transmit Data Bit 5
MMDTR_MMTD6         equ       6                   ; Multi-Master IIC Transmit Data Bit 6
MMDTR_MMTD7         equ       7                   ; Multi-Master IIC Transmit Data Bit 7
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
MMDRR_MMRD0         equ       0                   ; Multi-Master IIC Receive Data Bit 0
MMDRR_MMRD1         equ       1                   ; Multi-Master IIC Receive Data Bit 1
MMDRR_MMRD2         equ       2                   ; Multi-Master IIC Receive Data Bit 2
MMDRR_MMRD3         equ       3                   ; Multi-Master IIC Receive Data Bit 3
MMDRR_MMRD4         equ       4                   ; Multi-Master IIC Receive Data Bit 4
MMDRR_MMRD5         equ       5                   ; Multi-Master IIC Receive Data Bit 5
MMDRR_MMRD6         equ       6                   ; Multi-Master IIC Receive Data Bit 6
MMDRR_MMRD7         equ       7                   ; Multi-Master IIC Receive Data Bit 7
; bit position masks
mMMDRR_MMRD0        equ       %00000001
mMMDRR_MMRD1        equ       %00000010
mMMDRR_MMRD2        equ       %00000100
mMMDRR_MMRD3        equ       %00001000
mMMDRR_MMRD4        equ       %00010000
mMMDRR_MMRD5        equ       %00100000
mMMDRR_MMRD6        equ       %01000000
mMMDRR_MMRD7        equ       %10000000

;*** PWM0 - PWM Data Register 0
PWM0                equ       $00000070           ;*** PWM0 - PWM Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM0_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM0_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM0_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM0_PWM_0          equ       3                   ; PWM Bit 0
PWM0_PWM_1          equ       4                   ; PWM Bit 1
PWM0_PWM_2          equ       5                   ; PWM Bit 2
PWM0_PWM_3          equ       6                   ; PWM Bit 3
PWM0_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM0_BRM0          equ       %00000001
mPWM0_BRM1          equ       %00000010
mPWM0_BRM2          equ       %00000100
mPWM0_PWM_0         equ       %00001000
mPWM0_PWM_1         equ       %00010000
mPWM0_PWM_2         equ       %00100000
mPWM0_PWM_3         equ       %01000000
mPWM0_PWM_4         equ       %10000000

;*** PWM1 - PWM Data Register 1
PWM1                equ       $00000071           ;*** PWM1 - PWM Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM1_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM1_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM1_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM1_PWM_0          equ       3                   ; PWM Bit 0
PWM1_PWM_1          equ       4                   ; PWM Bit 1
PWM1_PWM_2          equ       5                   ; PWM Bit 2
PWM1_PWM_3          equ       6                   ; PWM Bit 3
PWM1_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM1_BRM0          equ       %00000001
mPWM1_BRM1          equ       %00000010
mPWM1_BRM2          equ       %00000100
mPWM1_PWM_0         equ       %00001000
mPWM1_PWM_1         equ       %00010000
mPWM1_PWM_2         equ       %00100000
mPWM1_PWM_3         equ       %01000000
mPWM1_PWM_4         equ       %10000000

;*** PWM2 - PWM Data Register 2
PWM2                equ       $00000072           ;*** PWM2 - PWM Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM2_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM2_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM2_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM2_PWM_0          equ       3                   ; PWM Bit 0
PWM2_PWM_1          equ       4                   ; PWM Bit 1
PWM2_PWM_2          equ       5                   ; PWM Bit 2
PWM2_PWM_3          equ       6                   ; PWM Bit 3
PWM2_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM2_BRM0          equ       %00000001
mPWM2_BRM1          equ       %00000010
mPWM2_BRM2          equ       %00000100
mPWM2_PWM_0         equ       %00001000
mPWM2_PWM_1         equ       %00010000
mPWM2_PWM_2         equ       %00100000
mPWM2_PWM_3         equ       %01000000
mPWM2_PWM_4         equ       %10000000

;*** PWM3 - PWM Data Register 3
PWM3                equ       $00000073           ;*** PWM3 - PWM Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM3_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM3_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM3_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM3_PWM_0          equ       3                   ; PWM Bit 0
PWM3_PWM_1          equ       4                   ; PWM Bit 1
PWM3_PWM_2          equ       5                   ; PWM Bit 2
PWM3_PWM_3          equ       6                   ; PWM Bit 3
PWM3_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM3_BRM0          equ       %00000001
mPWM3_BRM1          equ       %00000010
mPWM3_BRM2          equ       %00000100
mPWM3_PWM_0         equ       %00001000
mPWM3_PWM_1         equ       %00010000
mPWM3_PWM_2         equ       %00100000
mPWM3_PWM_3         equ       %01000000
mPWM3_PWM_4         equ       %10000000

;*** PWM4 - PWM Data Register 4
PWM4                equ       $00000074           ;*** PWM4 - PWM Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM4_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM4_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM4_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM4_PWM_0          equ       3                   ; PWM Bit 0
PWM4_PWM_1          equ       4                   ; PWM Bit 1
PWM4_PWM_2          equ       5                   ; PWM Bit 2
PWM4_PWM_3          equ       6                   ; PWM Bit 3
PWM4_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM4_BRM0          equ       %00000001
mPWM4_BRM1          equ       %00000010
mPWM4_BRM2          equ       %00000100
mPWM4_PWM_0         equ       %00001000
mPWM4_PWM_1         equ       %00010000
mPWM4_PWM_2         equ       %00100000
mPWM4_PWM_3         equ       %01000000
mPWM4_PWM_4         equ       %10000000

;*** PWM5 - PWM Data Register 5
PWM5                equ       $00000075           ;*** PWM5 - PWM Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM5_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM5_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM5_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM5_PWM_0          equ       3                   ; PWM Bit 0
PWM5_PWM_1          equ       4                   ; PWM Bit 1
PWM5_PWM_2          equ       5                   ; PWM Bit 2
PWM5_PWM_3          equ       6                   ; PWM Bit 3
PWM5_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM5_BRM0          equ       %00000001
mPWM5_BRM1          equ       %00000010
mPWM5_BRM2          equ       %00000100
mPWM5_PWM_0         equ       %00001000
mPWM5_PWM_1         equ       %00010000
mPWM5_PWM_2         equ       %00100000
mPWM5_PWM_3         equ       %01000000
mPWM5_PWM_4         equ       %10000000

;*** PWM6 - PWM Data Register 6
PWM6                equ       $00000076           ;*** PWM6 - PWM Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM6_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM6_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM6_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM6_PWM_0          equ       3                   ; PWM Bit 0
PWM6_PWM_1          equ       4                   ; PWM Bit 1
PWM6_PWM_2          equ       5                   ; PWM Bit 2
PWM6_PWM_3          equ       6                   ; PWM Bit 3
PWM6_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM6_BRM0          equ       %00000001
mPWM6_BRM1          equ       %00000010
mPWM6_BRM2          equ       %00000100
mPWM6_PWM_0         equ       %00001000
mPWM6_PWM_1         equ       %00010000
mPWM6_PWM_2         equ       %00100000
mPWM6_PWM_3         equ       %01000000
mPWM6_PWM_4         equ       %10000000

;*** PWM7 - PWM Data Register 7
PWM7                equ       $00000077           ;*** PWM7 - PWM Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM7_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM7_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM7_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM7_PWM_0          equ       3                   ; PWM Bit 0
PWM7_PWM_1          equ       4                   ; PWM Bit 1
PWM7_PWM_2          equ       5                   ; PWM Bit 2
PWM7_PWM_3          equ       6                   ; PWM Bit 3
PWM7_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM7_BRM0          equ       %00000001
mPWM7_BRM1          equ       %00000010
mPWM7_BRM2          equ       %00000100
mPWM7_PWM_0         equ       %00001000
mPWM7_PWM_1         equ       %00010000
mPWM7_PWM_2         equ       %00100000
mPWM7_PWM_3         equ       %01000000
mPWM7_PWM_4         equ       %10000000

;*** PWMCR - PWM Control Register
PWMCR               equ       $00000078           ;*** PWMCR - PWM Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCR_PWM0E         equ       0                   ; PWM 0 Output Enable
PWMCR_PWM1E         equ       1                   ; PWM 1 Output Enable
PWMCR_PWM2E         equ       2                   ; PWM 2 Output Enable
PWMCR_PWM3E         equ       3                   ; PWM 3 Output Enable
PWMCR_PWM4E         equ       4                   ; PWM 4 Output Enable
PWMCR_PWM5E         equ       5                   ; PWM 5 Output Enable
PWMCR_PWM6E         equ       6                   ; PWM 6 Output Enable
PWMCR_PWM7E         equ       7                   ; PWM 7 Output Enable
; bit position masks
mPWMCR_PWM0E        equ       %00000001
mPWMCR_PWM1E        equ       %00000010
mPWMCR_PWM2E        equ       %00000100
mPWMCR_PWM3E        equ       %00001000
mPWMCR_PWM4E        equ       %00010000
mPWMCR_PWM5E        equ       %00100000
mPWMCR_PWM6E        equ       %01000000
mPWMCR_PWM7E        equ       %10000000

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

;*** FLCR - 47,616 Bytes FLASH Control Register
FLCR                equ       $0000FE07           ;*** FLCR - 47,616 Bytes FLASH Control Register
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
FLBPR               equ       $0000FE08           ;*** FLBPR - FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR1          equ       1                   ; Flash Block Protect Bit 1
FLBPR_BPR2          equ       2                   ; Flash Block Protect Bit 2
FLBPR_BPR3          equ       3                   ; Flash Block Protect Bit 3
FLBPR_BPR4          equ       4                   ; Flash Block Protect Bit 4
FLBPR_BPR5          equ       5                   ; Flash Block Protect Bit 5
FLBPR_BPR6          equ       6                   ; Flash Block Protect Bit 6
FLBPR_BPR7          equ       7                   ; Flash Block Protect Bit 7
; bit position masks
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000
mFLBPR_BPR4         equ       %00010000
mFLBPR_BPR5         equ       %00100000
mFLBPR_BPR6         equ       %01000000
mFLBPR_BPR7         equ       %10000000

;*** FLCR1 - 13k-Bytes FLASH Control Register
FLCR1               equ       $0000FE0A           ;*** FLCR1 - 13k-Bytes FLASH Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR1_PGM1          equ       0                   ; Program Control Bit
FLCR1_ERASE1        equ       1                   ; Erase Control Bit
FLCR1_MASS1         equ       2                   ; Mass Erase Control Bit
FLCR1_HVEN1         equ       3                   ; High-Voltage Enable Bit
; bit position masks
mFLCR1_PGM1         equ       %00000001
mFLCR1_ERASE1       equ       %00000010
mFLCR1_MASS1        equ       %00000100
mFLCR1_HVEN1        equ       %00001000

;*** FLBPR1 - 13k-Bytes FLASH Block Protect Register
FLBPR1              equ       $0000FE0B           ;*** FLBPR1 - 13k-Bytes FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR1_BPR11        equ       1                   ; Block Protect Register Bit 11
FLBPR1_BPR12        equ       2                   ; Block Protect Register Bit 12
FLBPR1_BPR13        equ       3                   ; Block Protect Register Bit 13
FLBPR1_BPR14        equ       4                   ; Block Protect Register Bit 14
FLBPR1_BPR15        equ       5                   ; Block Protect Register Bit 15
FLBPR1_BPR16        equ       6                   ; Block Protect Register Bit 16
FLBPR1_BPR17        equ       7                   ; Block Protect Register Bit 17
; bit position masks
mFLBPR1_BPR11       equ       %00000010
mFLBPR1_BPR12       equ       %00000100
mFLBPR1_BPR13       equ       %00001000
mFLBPR1_BPR14       equ       %00010000
mFLBPR1_BPR15       equ       %00100000
mFLBPR1_BPR16       equ       %01000000
mFLBPR1_BPR17       equ       %10000000

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
