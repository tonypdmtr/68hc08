;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908LD60, version 2.87.134 (RegistersPrg V2.23)

; ###################################################################
;     Filename  : mc68hc908ld60.inc
;     Processor : MC68HC908LD60IFU
;     FileFormat: V2.23
;     DataSheet : MC68HC908LD60/D REV 1
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
ROM                 equ       $00000C00
ROM_END             equ       $0000F9FF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000047F
;
INT_CGMPLL          equ       $0000FFE0
INT_KBI             equ       $0000FFE2
INT_ADC             equ       $0000FFE4
Reserved3           equ       $0000FFE6
INT_MMIIC           equ       $0000FFE8
INT_Sync            equ       $0000FFEA
INT_TIMOvr          equ       $0000FFEC
INT_TIMCH1          equ       $0000FFEE
INT_TIMCH0          equ       $0000FFF0
INT_DDC12AB         equ       $0000FFF2
Reserved10          equ       $0000FFF4
Reserved11          equ       $0000FFF6
Reserved12          equ       $0000FFF8
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

;*** DMCR - DDC Master Control Register
DMCR                equ       $00000016           ;*** DMCR - DDC Master Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DMCR_BR0            equ       0                   ; Baud Rate Select Bit 0
DMCR_BR1            equ       1                   ; Baud Rate Select Bit 1
DMCR_BR2            equ       2                   ; Baud Rate Select Bit 2
DMCR_MRW            equ       3                   ; Master Read/Write
DMCR_MAST           equ       4                   ; Master Control Bit
DMCR_BB             equ       5                   ; Bus Busy Flag
DMCR_NAKIF          equ       6                   ; No Acknowledge Interrupt Flag
DMCR_ALIF           equ       7                   ; DDC Arbitration Lost Interrupt Flag
; bit position masks
mDMCR_BR0           equ       %00000001
mDMCR_BR1           equ       %00000010
mDMCR_BR2           equ       %00000100
mDMCR_MRW           equ       %00001000
mDMCR_MAST          equ       %00010000
mDMCR_BB            equ       %00100000
mDMCR_NAKIF         equ       %01000000
mDMCR_ALIF          equ       %10000000

;*** DADR - DDC Address Register
DADR                equ       $00000017           ;*** DADR - DDC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DADR_EXTAD          equ       0                   ; DDC Expand Address
DADR_DAD1           equ       1                   ; DDC Address Bit 1
DADR_DAD2           equ       2                   ; DDC Address Bit 2
DADR_DAD3           equ       3                   ; DDC Address Bit 3
DADR_DAD4           equ       4                   ; DDC Address Bit 4
DADR_DAD5           equ       5                   ; DDC Address Bit 5
DADR_DAD6           equ       6                   ; DDC Address Bit 6
DADR_DAD7           equ       7                   ; DDC Address Bit 7
; bit position masks
mDADR_EXTAD         equ       %00000001
mDADR_DAD1          equ       %00000010
mDADR_DAD2          equ       %00000100
mDADR_DAD3          equ       %00001000
mDADR_DAD4          equ       %00010000
mDADR_DAD5          equ       %00100000
mDADR_DAD6          equ       %01000000
mDADR_DAD7          equ       %10000000

;*** DCR - DDC Control Register
DCR                 equ       $00000018           ;*** DCR - DDC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DCR_DDC1EN          equ       1                   ; DDC1 Protocol Enable
DCR_SCLIEN          equ       2                   ; SCL Interrupt Enable
DCR_TXAK            equ       3                   ; Transmit Acknowledge Enable
DCR_DIEN            equ       6                   ; DDC Interrupt Enable
DCR_DEN             equ       7                   ; DDC Enable
; bit position masks
mDCR_DDC1EN         equ       %00000010
mDCR_SCLIEN         equ       %00000100
mDCR_TXAK           equ       %00001000
mDCR_DIEN           equ       %01000000
mDCR_DEN            equ       %10000000

;*** DSR_DDC - DDC Status Register
DSR_DDC             equ       $00000019           ;*** DSR_DDC - DDC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR_DDC_RXBF        equ       0                   ; DDC Receive Buffer Full
DSR_DDC_TXBE        equ       1                   ; DDC Transmit Buffer Empty
DSR_DDC_SCLIF       equ       2                   ; SCL Interrupt Flag
DSR_DDC_RXAK        equ       3                   ; DDC Receive Acknowledge
DSR_DDC_SRW         equ       4                   ; DDC Slave Read/Write
DSR_DDC_MATCH       equ       5                   ; DDC Address Match
DSR_DDC_TXIF        equ       6                   ; DDC Transmit Interrupt Flag
DSR_DDC_RXIF        equ       7                   ; DDC Receive Interrupt Flag
; bit position masks
mDSR_DDC_RXBF       equ       %00000001
mDSR_DDC_TXBE       equ       %00000010
mDSR_DDC_SCLIF      equ       %00000100
mDSR_DDC_RXAK       equ       %00001000
mDSR_DDC_SRW        equ       %00010000
mDSR_DDC_MATCH      equ       %00100000
mDSR_DDC_TXIF       equ       %01000000
mDSR_DDC_RXIF       equ       %10000000

;*** DDTR - DDC Data Transmit Register
DDTR                equ       $0000001A           ;*** DDTR - DDC Data Transmit Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDTR_DTD0           equ       0                   ; DDC Data Transmit Bit 0
DDTR_DTD1           equ       1                   ; DDC Data Transmit Bit 1
DDTR_DTD2           equ       2                   ; DDC Data Transmit Bit 2
DDTR_DTD3           equ       3                   ; DDC Data Transmit Bit 3
DDTR_DTD4           equ       4                   ; DDC Data Transmit Bit 4
DDTR_DTD5           equ       5                   ; DDC Data Transmit Bit 5
DDTR_DTD6           equ       6                   ; DDC Data Transmit Bit 6
DDTR_DTD7           equ       7                   ; DDC Data Transmit Bit 7
; bit position masks
mDDTR_DTD0          equ       %00000001
mDDTR_DTD1          equ       %00000010
mDDTR_DTD2          equ       %00000100
mDDTR_DTD3          equ       %00001000
mDDTR_DTD4          equ       %00010000
mDDTR_DTD5          equ       %00100000
mDDTR_DTD6          equ       %01000000
mDDTR_DTD7          equ       %10000000

;*** DDRR - DDC Data Receive Register
DDRR                equ       $0000001B           ;*** DDRR - DDC Data Receive Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRR_DRD0           equ       0                   ; DDC Data Receive Bit 0
DDRR_DRD1           equ       1                   ; DDC Data Receive Bit 1
DDRR_DRD2           equ       2                   ; DDC Data Receive Bit 2
DDRR_DRD3           equ       3                   ; DDC Data Receive Bit 3
DDRR_DRD4           equ       4                   ; DDC Data Receive Bit 4
DDRR_DRD5           equ       5                   ; DDC Data Receive Bit 5
DDRR_DRD6           equ       6                   ; DDC Data Receive Bit 6
DDRR_DRD7           equ       7                   ; DDC Data Receive Bit 7
; bit position masks
mDDRR_DRD0          equ       %00000001
mDDRR_DRD1          equ       %00000010
mDDRR_DRD2          equ       %00000100
mDDRR_DRD3          equ       %00001000
mDDRR_DRD4          equ       %00010000
mDDRR_DRD5          equ       %00100000
mDDRR_DRD6          equ       %01000000
mDDRR_DRD7          equ       %10000000

;*** D2ADR - DDC2 Address Register
D2ADR               equ       $0000001C           ;*** D2ADR - DDC2 Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
D2ADR_D2AD1         equ       1                   ; DDC2 Address Bit 1
D2ADR_D2AD2         equ       2                   ; DDC2 Address Bit 2
D2ADR_D2AD3         equ       3                   ; DDC2 Address Bit 3
D2ADR_D2AD4         equ       4                   ; DDC2 Address Bit 4
D2ADR_D2AD5         equ       5                   ; DDC2 Address Bit 5
D2ADR_D2AD6         equ       6                   ; DDC2 Address Bit 6
D2ADR_D2AD7         equ       7                   ; DDC2 Address Bit 7
; bit position masks
mD2ADR_D2AD1        equ       %00000010
mD2ADR_D2AD2        equ       %00000100
mD2ADR_D2AD3        equ       %00001000
mD2ADR_D2AD4        equ       %00010000
mD2ADR_D2AD5        equ       %00100000
mD2ADR_D2AD6        equ       %01000000
mD2ADR_D2AD7        equ       %10000000

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

;*** KEBUF_13 - 13k-Byte FLASH Even Byte Write Buffer
KEBUF_13            equ       $00000066           ;*** KEBUF_13 - 13k-Byte FLASH Even Byte Write Buffer
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KEBUF_13_BIT0       equ       0                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 0
KEBUF_13_BIT1       equ       1                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 1
KEBUF_13_BIT2       equ       2                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 2
KEBUF_13_BIT3       equ       3                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 3
KEBUF_13_BIT4       equ       4                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 4
KEBUF_13_BIT5       equ       5                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 5
KEBUF_13_BIT6       equ       6                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 6
KEBUF_13_BIT7       equ       7                   ; 13k-Byte FLASH Even Byte Write Buffer Bit 7
; bit position masks
mKEBUF_13_BIT0      equ       %00000001
mKEBUF_13_BIT1      equ       %00000010
mKEBUF_13_BIT2      equ       %00000100
mKEBUF_13_BIT3      equ       %00001000
mKEBUF_13_BIT4      equ       %00010000
mKEBUF_13_BIT5      equ       %00100000
mKEBUF_13_BIT6      equ       %01000000
mKEBUF_13_BIT7      equ       %10000000

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
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
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

;*** BRKL - Break Address Register
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Register
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
