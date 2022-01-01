;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908BD48_44, version 2.87.126 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908bd48.inc
;     Processor : MC68HC908BD48IFB
;     FileFormat: V2.28
;     DataSheet : MC68HC908BD48/D Rev. 2.1 August 1, 2005
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
ROM                 equ       $00004000
ROM_END             equ       $0000FBFF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000047F
;
INT_ADC             equ       $0000FFE8
INT_MMIIC           equ       $0000FFEA
INT_Sync            equ       $0000FFEC
INT_TIMOvr          equ       $0000FFEE
INT_TIMCH1          equ       $0000FFF0
INT_TIMCH0          equ       $0000FFF2
Int7                equ       $0000FFF4
INT_DDC12AB         equ       $0000FFF6
INT_USB             equ       $0000FFF8
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
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010
mPTC_PTC2           equ       %00000100
mPTC_PTC3           equ       %00001000
mPTC_PTC4           equ       %00010000
mPTC_PTC5           equ       %00100000

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
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000
mDDRC_DDRC4         equ       %00010000
mDDRC_DDRC5         equ       %00100000

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
; bit position masks
mDDRD_DDRD0         equ       %00000001
mDDRD_DDRD1         equ       %00000010
mDDRD_DDRD2         equ       %00000100
mDDRD_DDRD3         equ       %00001000
mDDRD_DDRD4         equ       %00010000
mDDRD_DDRD5         equ       %00100000
mDDRD_DDRD6         equ       %01000000

;*** PTE - Port E Data Register
PTE                 equ       $00000008           ;*** PTE - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTE_PTE0            equ       0                   ; Port E Data Bit 0
PTE_PTE1            equ       1                   ; Port E Data Bit 1
PTE_PTE2            equ       2                   ; Port E Data Bit 2
; bit position masks
mPTE_PTE0           equ       %00000001
mPTE_PTE1           equ       %00000010
mPTE_PTE2           equ       %00000100

;*** DDRE - Data Direction Register E
DDRE                equ       $00000009           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0          equ       0                   ; Data Direction Register E Bit 0
DDRE_DDRE1          equ       1                   ; Data Direction Register E Bit 1
DDRE_DDRE2          equ       2                   ; Data Direction Register E Bit 2
; bit position masks
mDDRE_DDRE0         equ       %00000001
mDDRE_DDRE1         equ       %00000010
mDDRE_DDRE2         equ       %00000100

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

;*** TCNTH - TIM Counter Register High
TCNTH               equ       $0000000C           ;*** TCNTH - TIM Counter Register High

;*** TCNTL - TIM Counter Register
TCNTL               equ       $0000000D           ;*** TCNTL - TIM Counter Register

;*** TMOD - TIM Counter Modulo Register
TMOD                equ       $0000000E           ;*** TMOD - TIM Counter Modulo Register

;*** TMODH - TIM Counter Modulo Register
TMODH               equ       $0000000E           ;*** TMODH - TIM Counter Modulo Register

;*** TMODL - TIM Counter Modulo Register
TMODL               equ       $0000000F           ;*** TMODL - TIM Counter Modulo Register

;*** TSC0 - TIM Channel 0 Status and Control Register
TSC0                equ       $00000010           ;*** TSC0 - TIM Channel 0 Status and Control Register
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
TCH0                equ       $00000011           ;*** TCH0 - TIM Channel 0 Register

;*** TCH0H - TIM Channel 0 Register High
TCH0H               equ       $00000011           ;*** TCH0H - TIM Channel 0 Register High

;*** TCH0L - TIM Channel 0 Register Low
TCH0L               equ       $00000012           ;*** TCH0L - TIM Channel 0 Register Low

;*** TSC1 - TIM Channel 1 Status and Control Register
TSC1                equ       $00000013           ;*** TSC1 - TIM Channel 1 Status and Control Register
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
TCH1                equ       $00000014           ;*** TCH1 - TIM Channel 1 Register

;*** TCH1H - TIM Channel 1 Register High
TCH1H               equ       $00000014           ;*** TCH1H - TIM Channel 1 Register High

;*** TCH1L - TIM Channel 1 Register Low
TCH1L               equ       $00000015           ;*** TCH1L - TIM Channel 1 Register Low

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
DADR_EXTAD          equ       0                   ; DDC Expanded Address
DADR_DDAD1          equ       1                   ; DDC Address Bit 1
DADR_DDAD2          equ       2                   ; DDC Address Bit 2
DADR_DDAD3          equ       3                   ; DDC Address Bit 3
DADR_DDAD4          equ       4                   ; DDC Address Bit 4
DADR_DDAD5          equ       5                   ; DDC Address Bit 5
DADR_DDAD6          equ       6                   ; DDC Address Bit 6
DADR_DDAD7          equ       7                   ; DDC Address Bit 7
; bit position masks
mDADR_EXTAD         equ       %00000001
mDADR_DDAD1         equ       %00000010
mDADR_DDAD2         equ       %00000100
mDADR_DDAD3         equ       %00001000
mDADR_DDAD4         equ       %00010000
mDADR_DDAD5         equ       %00100000
mDADR_DDAD6         equ       %01000000
mDADR_DDAD7         equ       %10000000

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

;*** DSR - DDC Status Register
DSR                 equ       $00000019           ;*** DSR - DDC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR_RXBF            equ       0                   ; DDC Receive Buffer Full
DSR_TXBE            equ       1                   ; DDC Transmit Buffer Empty
DSR_SCLIF           equ       2                   ; SCL Interrupt Flag
DSR_RXAK            equ       3                   ; DDC Receive Acknowledge
DSR_SRW             equ       4                   ; DDC Slave Read/Write
DSR_MATCH           equ       5                   ; DDC Address Match
DSR_TXIF            equ       6                   ; DDC Transmit Interrupt Flag
DSR_RXIF            equ       7                   ; DDC Receive Interrupt Flag
; bit position masks
mDSR_RXBF           equ       %00000001
mDSR_TXBE           equ       %00000010
mDSR_SCLIF          equ       %00000100
mDSR_RXAK           equ       %00001000
mDSR_SRW            equ       %00010000
mDSR_MATCH          equ       %00100000
mDSR_TXIF           equ       %01000000
mDSR_RXIF           equ       %10000000

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

;*** CONFIG0 - Configuration Register 0
CONFIG0             equ       $0000001D           ;*** CONFIG0 - Configuration Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG0_SOGE        equ       5                   ; SOG Enable
CONFIG0_VSYNCOE     equ       6                   ; VSYNCO Enable
CONFIG0_HSYNCOE     equ       7                   ; HSYNCO Enable
; bit position masks
mCONFIG0_SOGE       equ       %00100000
mCONFIG0_VSYNCOE    equ       %01000000
mCONFIG0_HSYNCOE    equ       %10000000

;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001E           ;*** INTSCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSCR_MODE         equ       0                   ; IRQ Edge/Level Select Bit
INTSCR_IMASK        equ       1                   ; IRQ Interrupt Mask Bit
INTSCR_ACK          equ       2                   ; IRQ Interrupt Request Acknowledge Bit
INTSCR_IRQF         equ       3                   ; IRQ Flag Bit
; bit position masks
mINTSCR_MODE        equ       %00000001
mINTSCR_IMASK       equ       %00000010
mINTSCR_ACK         equ       %00000100
mINTSCR_IRQF        equ       %00001000

;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; Stop Instruction Enable Bit
CONFIG1_COPRS       equ       2                   ; COP Rate Select Bit
CONFIG1_SSREC       equ       3                   ; Short Stop Recovery Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_COPRS      equ       %00000100
mCONFIG1_SSREC      equ       %00001000

;*** PWM0 - PWM0 Data Register
PWM0                equ       $00000020           ;*** PWM0 - PWM0 Data Register
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

;*** PWM1 - PWM1 Data Register
PWM1                equ       $00000021           ;*** PWM1 - PWM1 Data Register
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

;*** PWM2 - PWM2 Data Register
PWM2                equ       $00000022           ;*** PWM2 - PWM2 Data Register
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

;*** PWM3 - PWM3 Data Register
PWM3                equ       $00000023           ;*** PWM3 - PWM3 Data Register
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

;*** PWM4 - PWM4 Data Register
PWM4                equ       $00000024           ;*** PWM4 - PWM4 Data Register
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

;*** PWM5 - PWM5 Data Register
PWM5                equ       $00000025           ;*** PWM5 - PWM5 Data Register
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

;*** PWM6 - PWM6 Data Register
PWM6                equ       $00000026           ;*** PWM6 - PWM6 Data Register
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

;*** PWM7 - PWM7 Data Register
PWM7                equ       $00000027           ;*** PWM7 - PWM7 Data Register
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

;*** PWMCR1 - PWM Control Register 1
PWMCR1              equ       $00000028           ;*** PWMCR1 - PWM Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCR1_PWM0E        equ       0                   ; PWM Output 0 Enable
PWMCR1_PWM1E        equ       1                   ; PWM Output 1 Enable
PWMCR1_PWM2E        equ       2                   ; PWM Output 2 Enable
PWMCR1_PWM3E        equ       3                   ; PWM Output 3 Enable
PWMCR1_PWM4E        equ       4                   ; PWM Output 4 Enable
PWMCR1_PWM5E        equ       5                   ; PWM Output 5 Enable
PWMCR1_PWM6E        equ       6                   ; PWM Output 6 Enable
PWMCR1_PWM7E        equ       7                   ; PWM Output 7 Enable
; bit position masks
mPWMCR1_PWM0E       equ       %00000001
mPWMCR1_PWM1E       equ       %00000010
mPWMCR1_PWM2E       equ       %00000100
mPWMCR1_PWM3E       equ       %00001000
mPWMCR1_PWM4E       equ       %00010000
mPWMCR1_PWM5E       equ       %00100000
mPWMCR1_PWM6E       equ       %01000000
mPWMCR1_PWM7E       equ       %10000000

;*** UADR - USB Address Register
UADR                equ       $00000029           ;*** UADR - USB Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UADR_UADD0          equ       0                   ; USB Address Bit 0
UADR_UADD1          equ       1                   ; USB Address Bit 1
UADR_UADD2          equ       2                   ; USB Address Bit 2
UADR_UADD3          equ       3                   ; USB Address Bit 3
UADR_UADD4          equ       4                   ; USB Address Bit 4
UADR_UADD5          equ       5                   ; USB Address Bit 5
UADR_UADD6          equ       6                   ; USB Address Bit 6
UADR_USBEN          equ       7                   ; USB Enable
; bit position masks
mUADR_UADD0         equ       %00000001
mUADR_UADD1         equ       %00000010
mUADR_UADD2         equ       %00000100
mUADR_UADD3         equ       %00001000
mUADR_UADD4         equ       %00010000
mUADR_UADD5         equ       %00100000
mUADR_UADD6         equ       %01000000
mUADR_USBEN         equ       %10000000

;*** UINTR - USB Interrupt Register
UINTR               equ       $0000002A           ;*** UINTR - USB Interrupt Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UINTR_RSTIE         equ       0                   ; Reset Interrupt Enable
UINTR_EOPIE         equ       1                   ; End Of Packet Interrupt Enable
UINTR_RBIE          equ       2                   ; Receive Buffer Interrupt Enable
UINTR_TBIE          equ       3                   ; Transmit Buffer Interrupt Enable
UINTR_RSTIF         equ       4                   ; Reset Interrupt Flag
UINTR_EOPIF         equ       5                   ; End Of Packet Interrupt Flag
UINTR_RBIFF         equ       6                   ; Receive Buffer Full Flag
UINTR_TBEF          equ       7                   ; Transmit Buffer Empty Flag
; bit position masks
mUINTR_RSTIE        equ       %00000001
mUINTR_EOPIE        equ       %00000010
mUINTR_RBIE         equ       %00000100
mUINTR_TBIE         equ       %00001000
mUINTR_RSTIF        equ       %00010000
mUINTR_EOPIF        equ       %00100000
mUINTR_RBIFF        equ       %01000000
mUINTR_TBEF         equ       %10000000

;*** UCR0 - USB Control Register 0
UCR0                equ       $0000002B           ;*** UCR0 - USB Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR0_TP0SIZ0        equ       0                   ; Endpoint 0 Transmit Data Size Bit 0
UCR0_TP0SIZ1        equ       1                   ; Endpoint 0 Transmit Data Size Bit 1
UCR0_TP0SIZ2        equ       2                   ; Endpoint 0 Transmit Data Size Bit 2
UCR0_TP0SIZ3        equ       3                   ; Endpoint 0 Transmit Data Size Bit 3
UCR0_RX0E           equ       4                   ; Endpoint 0 Receive Enable
UCR0_TX0E           equ       5                   ; Endpoint 0 Transmit Enable
UCR0_STALL0         equ       6                   ; Endpoint 0 STALL Handshake
UCR0_T0SEQ          equ       7                   ; Endpoint 0 Data Packet PID Select
; bit position masks
mUCR0_TP0SIZ0       equ       %00000001
mUCR0_TP0SIZ1       equ       %00000010
mUCR0_TP0SIZ2       equ       %00000100
mUCR0_TP0SIZ3       equ       %00001000
mUCR0_RX0E          equ       %00010000
mUCR0_TX0E          equ       %00100000
mUCR0_STALL0        equ       %01000000
mUCR0_T0SEQ         equ       %10000000

;*** USR - USB Status Register
USR                 equ       $0000002C           ;*** USR - USB Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USR_RPSIZ0          equ       0                   ; Received Data Size Bit 0
USR_RPSIZ1          equ       1                   ; Received Data Size Bit 1
USR_RPSIZ2          equ       2                   ; Received Data Size Bit 2
USR_RPSIZ3          equ       3                   ; Received Data Size Bit 3
USR_TX1ST           equ       5                   ; Transmit First Flag
USR_SETUP           equ       6                   ; SETUP Token
USR_RSEQ            equ       7                   ; Received Data Sequence
; bit position masks
mUSR_RPSIZ0         equ       %00000001
mUSR_RPSIZ1         equ       %00000010
mUSR_RPSIZ2         equ       %00000100
mUSR_RPSIZ3         equ       %00001000
mUSR_TX1ST          equ       %00100000
mUSR_SETUP          equ       %01000000
mUSR_RSEQ           equ       %10000000

;*** UCR2 - USB Control Register 2
UCR2                equ       $0000002D           ;*** UCR2 - USB Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR2_STALL1         equ       0                   ; Endpoint 1 STALL Handshake
UCR2_STALL2         equ       1                   ; Endpoint 2 STALL Handshake
UCR2_ENABLE1        equ       2                   ; Endpoint 1 Enable
UCR2_ENABLE2        equ       3                   ; Endpoint 2 Enable
UCR2_SUSPND         equ       4                   ; USB Suspend
UCR2_PULLEN         equ       5                   ; Pullup Enable on D-
UCR2_TX1STR         equ       6                   ; TX1ST Clear
UCR2_RSTIFR         equ       7                   ; Reset Interrupt Flag Clear
; bit position masks
mUCR2_STALL1        equ       %00000001
mUCR2_STALL2        equ       %00000010
mUCR2_ENABLE1       equ       %00000100
mUCR2_ENABLE2       equ       %00001000
mUCR2_SUSPND        equ       %00010000
mUCR2_PULLEN        equ       %00100000
mUCR2_TX1STR        equ       %01000000
mUCR2_RSTIFR        equ       %10000000

;*** UIR1 - USB Interrupt Register 1
UIR1                equ       $0000002E           ;*** UIR1 - USB Interrupt Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UIR1_EOPFR          equ       0                   ; End Of Packet Interrupt Flag Clear
UIR1_TXD1FR         equ       1                   ; Endpoint 1 and 2 Data Buffer Transmit Flag Clear
UIR1_RBFFR          equ       2                   ; Receive Buffer Full Flag Clear
UIR1_TBEFR          equ       3                   ; Transmit Buffer Empty Flag Clear
UIR1_RESUMFR        equ       4                   ; Resume Flag Clear
UIR1_RESUMF         equ       5                   ; Resume Flag
UIR1_TXD1IE         equ       6                   ; Transmit Buffer Interrupt Enable
UIR1_TXD1F          equ       7                   ; Endpoint 1/2 Data Buffer Transmit Flag
; bit position masks
mUIR1_EOPFR         equ       %00000001
mUIR1_TXD1FR        equ       %00000010
mUIR1_RBFFR         equ       %00000100
mUIR1_TBEFR         equ       %00001000
mUIR1_RESUMFR       equ       %00010000
mUIR1_RESUMF        equ       %00100000
mUIR1_TXD1IE        equ       %01000000
mUIR1_TXD1F         equ       %10000000

;*** UCR1 - USB Control Register 1
UCR1                equ       $0000002F           ;*** UCR1 - USB Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UCR1_TP1SIZ0        equ       0                   ; Endpoint 1/2 Transmit Data Size Bit 0
UCR1_TP1SIZ1        equ       1                   ; Endpoint 1/2 Transmit Data Size Bit 1
UCR1_TP1SIZ2        equ       2                   ; Endpoint 1/2 Transmit Data Size Bit 2
UCR1_TP1SIZ3        equ       3                   ; Endpoint 1/2 Transmit Data Size Bit 3
UCR1_FRESUM         equ       4                   ; Force Resume
UCR1_TX1E           equ       5                   ; Endpoint 1/2 Transmit Enable
UCR1_ENDADD         equ       6                   ; Endpoint Address Select
UCR1_T1SEQ          equ       7                   ; Endpoint 1/2 Data Packet PID Select
; bit position masks
mUCR1_TP1SIZ0       equ       %00000001
mUCR1_TP1SIZ1       equ       %00000010
mUCR1_TP1SIZ2       equ       %00000100
mUCR1_TP1SIZ3       equ       %00001000
mUCR1_FRESUM        equ       %00010000
mUCR1_TX1E          equ       %00100000
mUCR1_ENDADD        equ       %01000000
mUCR1_T1SEQ         equ       %10000000

;*** UD0R0 - USB Endpoint 0 Data Register 0
UD0R0               equ       $00000030           ;*** UD0R0 - USB Endpoint 0 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R0_UE0RD00_UE0TD00 equ       0                   ; Endpoint 0 Receive Data Buffer 0 Bit 0, Endpoint 0 Transmit Data Buffer 0 Bit 0
UD0R0_UE0RD01_UE0TD01 equ       1                   ; Endpoint 0 Receive Data Buffer 0 Bit 1, Endpoint 0 Transmit Data Buffer 0 Bit 1
UD0R0_UE0RD02_UE0TD02 equ       2                   ; Endpoint 0 Receive Data Buffer 0 Bit 2, Endpoint 0 Transmit Data Buffer 0 Bit 2
UD0R0_UE0RD03_UE0TD03 equ       3                   ; Endpoint 0 Receive Data Buffer 0 Bit 3, Endpoint 0 Transmit Data Buffer 0 Bit 3
UD0R0_UE0RD04_UE0TD04 equ       4                   ; Endpoint 0 Receive Data Buffer 0 Bit 4, Endpoint 0 Transmit Data Buffer 0 Bit 4
UD0R0_UE0RD05_UE0TD05 equ       5                   ; Endpoint 0 Receive Data Buffer 0 Bit 5, Endpoint 0 Transmit Data Buffer 0 Bit 5
UD0R0_UE0RD06_UE0TD06 equ       6                   ; Endpoint 0 Receive Data Buffer 0 Bit 6, Endpoint 0 Transmit Data Buffer 0 Bit 6
UD0R0_UE0RD07_UE0TD07 equ       7                   ; Endpoint 0 Receive Data Buffer 0 Bit 7, Endpoint 0 Transmit Data Buffer 0 Bit 7
; bit position masks
mUD0R0_UE0RD00_UE0TD00 equ       %00000001
mUD0R0_UE0RD01_UE0TD01 equ       %00000010
mUD0R0_UE0RD02_UE0TD02 equ       %00000100
mUD0R0_UE0RD03_UE0TD03 equ       %00001000
mUD0R0_UE0RD04_UE0TD04 equ       %00010000
mUD0R0_UE0RD05_UE0TD05 equ       %00100000
mUD0R0_UE0RD06_UE0TD06 equ       %01000000
mUD0R0_UE0RD07_UE0TD07 equ       %10000000

;*** UD0R1 - USB Endpoint 0 Data Register 1
UD0R1               equ       $00000031           ;*** UD0R1 - USB Endpoint 0 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R1_UE0RD10_UE0TD10 equ       0                   ; Endpoint 0 Receive Data Buffer 1 Bit 0, Endpoint 0 Transmit Data Buffer 1 Bit 0
UD0R1_UE0RD11_UE0TD11 equ       1                   ; Endpoint 0 Receive Data Buffer 1 Bit 1, Endpoint 0 Transmit Data Buffer 1 Bit 1
UD0R1_UE0RD12_UE0TD12 equ       2                   ; Endpoint 0 Receive Data Buffer 1 Bit 2, Endpoint 0 Transmit Data Buffer 1 Bit 2
UD0R1_UE0RD13_UE0TD13 equ       3                   ; Endpoint 0 Receive Data Buffer 1 Bit 3, Endpoint 0 Transmit Data Buffer 1 Bit 3
UD0R1_UE0RD14_UE0TD14 equ       4                   ; Endpoint 0 Receive Data Buffer 1 Bit 4, Endpoint 0 Transmit Data Buffer 1 Bit 4
UD0R1_UE0RD15_UE0TD15 equ       5                   ; Endpoint 0 Receive Data Buffer 1 Bit 5, Endpoint 0 Transmit Data Buffer 1 Bit 5
UD0R1_UE0RD16_UE0TD16 equ       6                   ; Endpoint 0 Receive Data Buffer 1 Bit 6, Endpoint 0 Transmit Data Buffer 1 Bit 6
UD0R1_UE0RD17_UE0TD17 equ       7                   ; Endpoint 0 Receive Data Buffer 1 Bit 7, Endpoint 0 Transmit Data Buffer 1 Bit 7
; bit position masks
mUD0R1_UE0RD10_UE0TD10 equ       %00000001
mUD0R1_UE0RD11_UE0TD11 equ       %00000010
mUD0R1_UE0RD12_UE0TD12 equ       %00000100
mUD0R1_UE0RD13_UE0TD13 equ       %00001000
mUD0R1_UE0RD14_UE0TD14 equ       %00010000
mUD0R1_UE0RD15_UE0TD15 equ       %00100000
mUD0R1_UE0RD16_UE0TD16 equ       %01000000
mUD0R1_UE0RD17_UE0TD17 equ       %10000000

;*** UD0R2 - USB Endpoint 0 Data Register 2
UD0R2               equ       $00000032           ;*** UD0R2 - USB Endpoint 0 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R2_UE0RD20_UE0TD20 equ       0                   ; Endpoint 0 Receive Data Buffer 2 Bit 0, Endpoint 0 Transmit Data Buffer 2 Bit 0
UD0R2_UE0RD21_UE0TD21 equ       1                   ; Endpoint 0 Receive Data Buffer 2 Bit 1, Endpoint 0 Transmit Data Buffer 2 Bit 1
UD0R2_UE0RD22_UE0TD22 equ       2                   ; Endpoint 0 Receive Data Buffer 2 Bit 2, Endpoint 0 Transmit Data Buffer 2 Bit 2
UD0R2_UE0RD23_UE0TD23 equ       3                   ; Endpoint 0 Receive Data Buffer 2 Bit 3, Endpoint 0 Transmit Data Buffer 2 Bit 3
UD0R2_UE0RD24_UE0TD24 equ       4                   ; Endpoint 0 Receive Data Buffer 2 Bit 4, Endpoint 0 Transmit Data Buffer 2 Bit 4
UD0R2_UE0RD25_UE0TD25 equ       5                   ; Endpoint 0 Receive Data Buffer 2 Bit 5, Endpoint 0 Transmit Data Buffer 2 Bit 5
UD0R2_UE0RD26_UE0TD26 equ       6                   ; Endpoint 0 Receive Data Buffer 2 Bit 6, Endpoint 0 Transmit Data Buffer 2 Bit 6
UD0R2_UE0RD27_UE0TD27 equ       7                   ; Endpoint 0 Receive Data Buffer 2 Bit 7, Endpoint 0 Transmit Data Buffer 2 Bit 7
; bit position masks
mUD0R2_UE0RD20_UE0TD20 equ       %00000001
mUD0R2_UE0RD21_UE0TD21 equ       %00000010
mUD0R2_UE0RD22_UE0TD22 equ       %00000100
mUD0R2_UE0RD23_UE0TD23 equ       %00001000
mUD0R2_UE0RD24_UE0TD24 equ       %00010000
mUD0R2_UE0RD25_UE0TD25 equ       %00100000
mUD0R2_UE0RD26_UE0TD26 equ       %01000000
mUD0R2_UE0RD27_UE0TD27 equ       %10000000

;*** UD0R3 - USB Endpoint 0 Data Register 3
UD0R3               equ       $00000033           ;*** UD0R3 - USB Endpoint 0 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R3_UE0RD30_UE0TD30 equ       0                   ; Endpoint 0 Receive Data Buffer 3 Bit 0, Endpoint 0 Transmit Data Buffer 3 Bit 0
UD0R3_UE0RD31_UE0TD31 equ       1                   ; Endpoint 0 Receive Data Buffer 3 Bit 1, Endpoint 0 Transmit Data Buffer 3 Bit 1
UD0R3_UE0RD32_UE0TD32 equ       2                   ; Endpoint 0 Receive Data Buffer 3 Bit 2, Endpoint 0 Transmit Data Buffer 3 Bit 2
UD0R3_UE0RD33_UE0TD33 equ       3                   ; Endpoint 0 Receive Data Buffer 3 Bit 3, Endpoint 0 Transmit Data Buffer 3 Bit 3
UD0R3_UE0RD34_UE0TD34 equ       4                   ; Endpoint 0 Receive Data Buffer 3 Bit 4, Endpoint 0 Transmit Data Buffer 3 Bit 4
UD0R3_UE0RD35_UE0TD35 equ       5                   ; Endpoint 0 Receive Data Buffer 3 Bit 5, Endpoint 0 Transmit Data Buffer 3 Bit 5
UD0R3_UE0RD36_UE0TD36 equ       6                   ; Endpoint 0 Receive Data Buffer 3 Bit 6, Endpoint 0 Transmit Data Buffer 3 Bit 6
UD0R3_UE0RD37_UE0TD37 equ       7                   ; Endpoint 0 Receive Data Buffer 3 Bit 7, Endpoint 0 Transmit Data Buffer 3 Bit 7
; bit position masks
mUD0R3_UE0RD30_UE0TD30 equ       %00000001
mUD0R3_UE0RD31_UE0TD31 equ       %00000010
mUD0R3_UE0RD32_UE0TD32 equ       %00000100
mUD0R3_UE0RD33_UE0TD33 equ       %00001000
mUD0R3_UE0RD34_UE0TD34 equ       %00010000
mUD0R3_UE0RD35_UE0TD35 equ       %00100000
mUD0R3_UE0RD36_UE0TD36 equ       %01000000
mUD0R3_UE0RD37_UE0TD37 equ       %10000000

;*** UD0R4 - USB Endpoint 0 Data Register 4
UD0R4               equ       $00000034           ;*** UD0R4 - USB Endpoint 0 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R4_UE0RD40_UE0TD40 equ       0                   ; Endpoint 0 Receive Data Buffer 4 Bit 0, Endpoint 0 Transmit Data Buffer 4 Bit 0
UD0R4_UE0RD41_UE0TD41 equ       1                   ; Endpoint 0 Receive Data Buffer 4 Bit 1, Endpoint 0 Transmit Data Buffer 4 Bit 1
UD0R4_UE0RD42_UE0TD42 equ       2                   ; Endpoint 0 Receive Data Buffer 4 Bit 2, Endpoint 0 Transmit Data Buffer 4 Bit 2
UD0R4_UE0RD43_UE0TD43 equ       3                   ; Endpoint 0 Receive Data Buffer 4 Bit 3, Endpoint 0 Transmit Data Buffer 4 Bit 3
UD0R4_UE0RD44_UE0TD44 equ       4                   ; Endpoint 0 Receive Data Buffer 4 Bit 4, Endpoint 0 Transmit Data Buffer 4 Bit 4
UD0R4_UE0RD45_UE0TD45 equ       5                   ; Endpoint 0 Receive Data Buffer 4 Bit 5, Endpoint 0 Transmit Data Buffer 4 Bit 5
UD0R4_UE0RD46_UE0TD46 equ       6                   ; Endpoint 0 Receive Data Buffer 4 Bit 6, Endpoint 0 Transmit Data Buffer 4 Bit 6
UD0R4_UE0RD47_UE0TD47 equ       7                   ; Endpoint 0 Receive Data Buffer 4 Bit 7, Endpoint 0 Transmit Data Buffer 4 Bit 7
; bit position masks
mUD0R4_UE0RD40_UE0TD40 equ       %00000001
mUD0R4_UE0RD41_UE0TD41 equ       %00000010
mUD0R4_UE0RD42_UE0TD42 equ       %00000100
mUD0R4_UE0RD43_UE0TD43 equ       %00001000
mUD0R4_UE0RD44_UE0TD44 equ       %00010000
mUD0R4_UE0RD45_UE0TD45 equ       %00100000
mUD0R4_UE0RD46_UE0TD46 equ       %01000000
mUD0R4_UE0RD47_UE0TD47 equ       %10000000

;*** UD0R5 - USB Endpoint 0 Data Register 5
UD0R5               equ       $00000035           ;*** UD0R5 - USB Endpoint 0 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R5_UE0RD50_UE0TD50 equ       0                   ; Endpoint 0 Receive Data Buffer 5 Bit 0, Endpoint 0 Transmit Data Buffer 5 Bit 0
UD0R5_UE0RD51_UE0TD51 equ       1                   ; Endpoint 0 Receive Data Buffer 5 Bit 1, Endpoint 0 Transmit Data Buffer 5 Bit 1
UD0R5_UE0RD52_UE0TD52 equ       2                   ; Endpoint 0 Receive Data Buffer 5 Bit 2, Endpoint 0 Transmit Data Buffer 5 Bit 2
UD0R5_UE0RD53_UE0TD53 equ       3                   ; Endpoint 0 Receive Data Buffer 5 Bit 3, Endpoint 0 Transmit Data Buffer 5 Bit 3
UD0R5_UE0RD54_UE0TD54 equ       4                   ; Endpoint 0 Receive Data Buffer 5 Bit 4, Endpoint 0 Transmit Data Buffer 5 Bit 4
UD0R5_UE0RD55_UE0TD55 equ       5                   ; Endpoint 0 Receive Data Buffer 5 Bit 5, Endpoint 0 Transmit Data Buffer 5 Bit 5
UD0R5_UE0RD56_UE0TD56 equ       6                   ; Endpoint 0 Receive Data Buffer 5 Bit 6, Endpoint 0 Transmit Data Buffer 5 Bit 6
UD0R5_UE0RD57_UE0TD57 equ       7                   ; Endpoint 0 Receive Data Buffer 5 Bit 7, Endpoint 0 Transmit Data Buffer 5 Bit 7
; bit position masks
mUD0R5_UE0RD50_UE0TD50 equ       %00000001
mUD0R5_UE0RD51_UE0TD51 equ       %00000010
mUD0R5_UE0RD52_UE0TD52 equ       %00000100
mUD0R5_UE0RD53_UE0TD53 equ       %00001000
mUD0R5_UE0RD54_UE0TD54 equ       %00010000
mUD0R5_UE0RD55_UE0TD55 equ       %00100000
mUD0R5_UE0RD56_UE0TD56 equ       %01000000
mUD0R5_UE0RD57_UE0TD57 equ       %10000000

;*** UD0R6 - USB Endpoint 0 Data Register 6
UD0R6               equ       $00000036           ;*** UD0R6 - USB Endpoint 0 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R6_UE0RD60_UE0TD60 equ       0                   ; Endpoint 0 Receive Data Buffer 6 Bit 0, Endpoint 0 Transmit Data Buffer 6 Bit 0
UD0R6_UE0RD61_UE0TD61 equ       1                   ; Endpoint 0 Receive Data Buffer 6 Bit 1, Endpoint 0 Transmit Data Buffer 6 Bit 1
UD0R6_UE0RD62_UE0TD62 equ       2                   ; Endpoint 0 Receive Data Buffer 6 Bit 2, Endpoint 0 Transmit Data Buffer 6 Bit 2
UD0R6_UE0RD63_UE0TD63 equ       3                   ; Endpoint 0 Receive Data Buffer 6 Bit 3, Endpoint 0 Transmit Data Buffer 6 Bit 3
UD0R6_UE0RD64_UE0TD64 equ       4                   ; Endpoint 0 Receive Data Buffer 6 Bit 4, Endpoint 0 Transmit Data Buffer 6 Bit 4
UD0R6_UE0RD65_UE0TD65 equ       5                   ; Endpoint 0 Receive Data Buffer 6 Bit 5, Endpoint 0 Transmit Data Buffer 6 Bit 5
UD0R6_UE0RD66_UE0TD66 equ       6                   ; Endpoint 0 Receive Data Buffer 6 Bit 6, Endpoint 0 Transmit Data Buffer 6 Bit 6
UD0R6_UE0RD67_UE0TD67 equ       7                   ; Endpoint 0 Receive Data Buffer 6 Bit 7, Endpoint 0 Transmit Data Buffer 6 Bit 7
; bit position masks
mUD0R6_UE0RD60_UE0TD60 equ       %00000001
mUD0R6_UE0RD61_UE0TD61 equ       %00000010
mUD0R6_UE0RD62_UE0TD62 equ       %00000100
mUD0R6_UE0RD63_UE0TD63 equ       %00001000
mUD0R6_UE0RD64_UE0TD64 equ       %00010000
mUD0R6_UE0RD65_UE0TD65 equ       %00100000
mUD0R6_UE0RD66_UE0TD66 equ       %01000000
mUD0R6_UE0RD67_UE0TD67 equ       %10000000

;*** UD0R7 - USB Endpoint 0 Data Register 7
UD0R7               equ       $00000037           ;*** UD0R7 - USB Endpoint 0 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD0R7_UE0RD70_UE0TD70 equ       0                   ; Endpoint 0 Receive Data Buffer 7 Bit 0, Endpoint 0 Transmit Data Buffer 7 Bit 0
UD0R7_UE0RD71_UE0TD71 equ       1                   ; Endpoint 0 Receive Data Buffer 7 Bit 1, Endpoint 0 Transmit Data Buffer 7 Bit 1
UD0R7_UE0RD72_UE0TD72 equ       2                   ; Endpoint 0 Receive Data Buffer 7 Bit 2, Endpoint 0 Transmit Data Buffer 7 Bit 2
UD0R7_UE0RD73_UE0TD73 equ       3                   ; Endpoint 0 Receive Data Buffer 7 Bit 3, Endpoint 0 Transmit Data Buffer 7 Bit 3
UD0R7_UE0RD74_UE0TD74 equ       4                   ; Endpoint 0 Receive Data Buffer 7 Bit 4, Endpoint 0 Transmit Data Buffer 7 Bit 4
UD0R7_UE0RD75_UE0TD75 equ       5                   ; Endpoint 0 Receive Data Buffer 7 Bit 5, Endpoint 0 Transmit Data Buffer 7 Bit 5
UD0R7_UE0RD76_UE0TD76 equ       6                   ; Endpoint 0 Receive Data Buffer 7 Bit 6, Endpoint 0 Transmit Data Buffer 7 Bit 6
UD0R7_UE0RD77_UE0TD77 equ       7                   ; Endpoint 0 Receive Data Buffer 7 Bit 7, Endpoint 0 Transmit Data Buffer 7 Bit 7
; bit position masks
mUD0R7_UE0RD70_UE0TD70 equ       %00000001
mUD0R7_UE0RD71_UE0TD71 equ       %00000010
mUD0R7_UE0RD72_UE0TD72 equ       %00000100
mUD0R7_UE0RD73_UE0TD73 equ       %00001000
mUD0R7_UE0RD74_UE0TD74 equ       %00010000
mUD0R7_UE0RD75_UE0TD75 equ       %00100000
mUD0R7_UE0RD76_UE0TD76 equ       %01000000
mUD0R7_UE0RD77_UE0TD77 equ       %10000000

;*** UD1R0 - USB Endpoint 1/2 Data Register 0
UD1R0               equ       $00000038           ;*** UD1R0 - USB Endpoint 1/2 Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R0_UE1TD00       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 0
UD1R0_UE1TD01       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 1
UD1R0_UE1TD02       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 2
UD1R0_UE1TD03       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 3
UD1R0_UE1TD04       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 4
UD1R0_UE1TD05       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 5
UD1R0_UE1TD06       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 6
UD1R0_UE1TD07       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 0 Bit 7
; bit position masks
mUD1R0_UE1TD00      equ       %00000001
mUD1R0_UE1TD01      equ       %00000010
mUD1R0_UE1TD02      equ       %00000100
mUD1R0_UE1TD03      equ       %00001000
mUD1R0_UE1TD04      equ       %00010000
mUD1R0_UE1TD05      equ       %00100000
mUD1R0_UE1TD06      equ       %01000000
mUD1R0_UE1TD07      equ       %10000000

;*** UD1R1 - USB Endpoint 1/2 Data Register 1
UD1R1               equ       $00000039           ;*** UD1R1 - USB Endpoint 1/2 Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R1_UE1TD10       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 0
UD1R1_UE1TD11       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 1
UD1R1_UE1TD12       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 2
UD1R1_UE1TD13       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 3
UD1R1_UE1TD14       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 4
UD1R1_UE1TD15       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 5
UD1R1_UE1TD16       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 6
UD1R1_UE1TD17       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 1 Bit 7
; bit position masks
mUD1R1_UE1TD10      equ       %00000001
mUD1R1_UE1TD11      equ       %00000010
mUD1R1_UE1TD12      equ       %00000100
mUD1R1_UE1TD13      equ       %00001000
mUD1R1_UE1TD14      equ       %00010000
mUD1R1_UE1TD15      equ       %00100000
mUD1R1_UE1TD16      equ       %01000000
mUD1R1_UE1TD17      equ       %10000000

;*** UD1R2 - USB Endpoint 1/2 Data Register 2
UD1R2               equ       $0000003A           ;*** UD1R2 - USB Endpoint 1/2 Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R2_UE1TD20       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 0
UD1R2_UE1TD21       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 1
UD1R2_UE1TD22       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 2
UD1R2_UE1TD23       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 3
UD1R2_UE1TD24       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 4
UD1R2_UE1TD25       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 5
UD1R2_UE1TD26       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 6
UD1R2_UE1TD27       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 2 Bit 7
; bit position masks
mUD1R2_UE1TD20      equ       %00000001
mUD1R2_UE1TD21      equ       %00000010
mUD1R2_UE1TD22      equ       %00000100
mUD1R2_UE1TD23      equ       %00001000
mUD1R2_UE1TD24      equ       %00010000
mUD1R2_UE1TD25      equ       %00100000
mUD1R2_UE1TD26      equ       %01000000
mUD1R2_UE1TD27      equ       %10000000

;*** UD1R3 - USB Endpoint 1/2 Data Register 3
UD1R3               equ       $0000003B           ;*** UD1R3 - USB Endpoint 1/2 Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R3_UE1TD30       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 0
UD1R3_UE1TD31       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 1
UD1R3_UE1TD32       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 2
UD1R3_UE1TD33       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 3
UD1R3_UE1TD34       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 4
UD1R3_UE1TD35       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 5
UD1R3_UE1TD36       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 6
UD1R3_UE1TD37       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 3 Bit 7
; bit position masks
mUD1R3_UE1TD30      equ       %00000001
mUD1R3_UE1TD31      equ       %00000010
mUD1R3_UE1TD32      equ       %00000100
mUD1R3_UE1TD33      equ       %00001000
mUD1R3_UE1TD34      equ       %00010000
mUD1R3_UE1TD35      equ       %00100000
mUD1R3_UE1TD36      equ       %01000000
mUD1R3_UE1TD37      equ       %10000000

;*** UD1R4 - USB Endpoint 1/2 Data Register 4
UD1R4               equ       $0000003C           ;*** UD1R4 - USB Endpoint 1/2 Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R4_UE1TD40       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 0
UD1R4_UE1TD41       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 1
UD1R4_UE1TD42       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 2
UD1R4_UE1TD43       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 3
UD1R4_UE1TD44       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 4
UD1R4_UE1TD45       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 5
UD1R4_UE1TD46       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 6
UD1R4_UE1TD47       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 4 Bit 7
; bit position masks
mUD1R4_UE1TD40      equ       %00000001
mUD1R4_UE1TD41      equ       %00000010
mUD1R4_UE1TD42      equ       %00000100
mUD1R4_UE1TD43      equ       %00001000
mUD1R4_UE1TD44      equ       %00010000
mUD1R4_UE1TD45      equ       %00100000
mUD1R4_UE1TD46      equ       %01000000
mUD1R4_UE1TD47      equ       %10000000

;*** UD1R5 - USB Endpoint 1/2 Data Register 5
UD1R5               equ       $0000003D           ;*** UD1R5 - USB Endpoint 1/2 Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R5_UE1TD50       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 0
UD1R5_UE1TD51       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 1
UD1R5_UE1TD52       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 2
UD1R5_UE1TD53       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 3
UD1R5_UE1TD54       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 4
UD1R5_UE1TD55       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 5
UD1R5_UE1TD56       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 6
UD1R5_UE1TD57       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 5 Bit 7
; bit position masks
mUD1R5_UE1TD50      equ       %00000001
mUD1R5_UE1TD51      equ       %00000010
mUD1R5_UE1TD52      equ       %00000100
mUD1R5_UE1TD53      equ       %00001000
mUD1R5_UE1TD54      equ       %00010000
mUD1R5_UE1TD55      equ       %00100000
mUD1R5_UE1TD56      equ       %01000000
mUD1R5_UE1TD57      equ       %10000000

;*** UD1R6 - USB Endpoint 1/2 Data Register 6
UD1R6               equ       $0000003E           ;*** UD1R6 - USB Endpoint 1/2 Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R6_UE1TD60       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 0
UD1R6_UE1TD61       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 1
UD1R6_UE1TD62       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 2
UD1R6_UE1TD63       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 3
UD1R6_UE1TD64       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 4
UD1R6_UE1TD65       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 5
UD1R6_UE1TD66       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 6
UD1R6_UE1TD67       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 6 Bit 7
; bit position masks
mUD1R6_UE1TD60      equ       %00000001
mUD1R6_UE1TD61      equ       %00000010
mUD1R6_UE1TD62      equ       %00000100
mUD1R6_UE1TD63      equ       %00001000
mUD1R6_UE1TD64      equ       %00010000
mUD1R6_UE1TD65      equ       %00100000
mUD1R6_UE1TD66      equ       %01000000
mUD1R6_UE1TD67      equ       %10000000

;*** UD1R7 - USB Endpoint 1/2 Data Register 7
UD1R7               equ       $0000003F           ;*** UD1R7 - USB Endpoint 1/2 Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
UD1R7_UE1TD70       equ       0                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 0
UD1R7_UE1TD71       equ       1                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 1
UD1R7_UE1TD72       equ       2                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 2
UD1R7_UE1TD73       equ       3                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 3
UD1R7_UE1TD74       equ       4                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 4
UD1R7_UE1TD75       equ       5                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 5
UD1R7_UE1TD76       equ       6                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 6
UD1R7_UE1TD77       equ       7                   ; Endpoint 1/2 Transmit Data Buffer 7 Bit 7
; bit position masks
mUD1R7_UE1TD70      equ       %00000001
mUD1R7_UE1TD71      equ       %00000010
mUD1R7_UE1TD72      equ       %00000100
mUD1R7_UE1TD73      equ       %00001000
mUD1R7_UE1TD74      equ       %00010000
mUD1R7_UE1TD75      equ       %00100000
mUD1R7_UE1TD76      equ       %01000000
mUD1R7_UE1TD77      equ       %10000000

;*** SPCSR - Sync Processor Control and Status Register
SPCSR               equ       $00000040           ;*** SPCSR - Sync Processor Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPCSR_HPOL          equ       0                   ; HSync Input Polarity
SPCSR_VPOL          equ       1                   ; VSync Input Polarity
SPCSR_HINVO         equ       2                   ; HSYNCO Signal Polarity
SPCSR_VINVO         equ       3                   ; VSYNCO Signal Polarity
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

;*** VFHR - Vertical Frequency High Register
VFHR                equ       $00000041           ;*** VFHR - Vertical Frequency High Register
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

;*** VFLR - Vertical Frequency Low Register
VFLR                equ       $00000042           ;*** VFLR - Vertical Frequency Low Register
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

;*** HFHR - Hsync Frequency High Register
HFHR                equ       $00000043           ;*** HFHR - Hsync Frequency High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HFHR_HFH0           equ       0                   ; Horizontal Line Frequency Bit 5
HFHR_HFH1           equ       1                   ; Horizontal Line Frequency Bit 6
HFHR_HFH2           equ       2                   ; Horizontal Line Frequency Bit 7
HFHR_HFH3           equ       3                   ; Horizontal Line Frequency Bit 8
HFHR_HFH4           equ       4                   ; Horizontal Line Frequency Bit 9
HFHR_HFH5           equ       5                   ; Horizontal Line Frequency Bit 10
HFHR_HFH6           equ       6                   ; Horizontal Line Frequency Bit 11
HFHR_HFH7           equ       7                   ; Horizontal Line Frequency Bit 12
; bit position masks
mHFHR_HFH0          equ       %00000001
mHFHR_HFH1          equ       %00000010
mHFHR_HFH2          equ       %00000100
mHFHR_HFH3          equ       %00001000
mHFHR_HFH4          equ       %00010000
mHFHR_HFH5          equ       %00100000
mHFHR_HFH6          equ       %01000000
mHFHR_HFH7          equ       %10000000

;*** HFLR - Hsync Frequency Low Register
HFLR                equ       $00000044           ;*** HFLR - Hsync Frequency Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HFLR_HFL0           equ       0                   ; Horizontal Line Frequency Bit 0
HFLR_HFL1           equ       1                   ; Horizontal Line Frequency Bit 1
HFLR_HFL2           equ       2                   ; Horizontal Line Frequency Bit 2
HFLR_HFL3           equ       3                   ; Horizontal Line Frequency Bit 3
HFLR_HFL4           equ       4                   ; Horizontal Line Frequency Bit 4
HFLR_HOVER          equ       7                   ; HSync Frequency Counter Overflow
; bit position masks
mHFLR_HFL0          equ       %00000001
mHFLR_HFL1          equ       %00000010
mHFLR_HFL2          equ       %00000100
mHFLR_HFL3          equ       %00001000
mHFLR_HFL4          equ       %00010000
mHFLR_HOVER         equ       %10000000

;*** SPIOCR - Sync Processor I/O Control Register
SPIOCR              equ       $00000045           ;*** SPIOCR - Sync Processor I/O Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIOCR_SOUT         equ       0                   ; Sync Output Enable
SPIOCR_BPOR         equ       1                   ; Back Porch
SPIOCR_CLAMPOE      equ       2                   ; Clamp Output Enable
SPIOCR_SOGSEL       equ       3                   ; SOG Select
SPIOCR_COINV        equ       5                   ; Clamp Output Invert
SPIOCR_HSYNCS       equ       6                   ; HSYNC Input State
SPIOCR_VSYNCS       equ       7                   ; VSYNC Input State
; bit position masks
mSPIOCR_SOUT        equ       %00000001
mSPIOCR_BPOR        equ       %00000010
mSPIOCR_CLAMPOE     equ       %00000100
mSPIOCR_SOGSEL      equ       %00001000
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

;*** HVOCR - H&V Sync Output Control Register
HVOCR               equ       $00000047           ;*** HVOCR - H&V Sync Output Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HVOCR_HVOCR0        equ       0                   ; H&V Output Select Bit 0
HVOCR_HVOCR1        equ       1                   ; H&V Output Select Bit 1
HVOCR_HVOCR2        equ       2                   ; H&V Output Select Bit 2
; bit position masks
mHVOCR_HVOCR0       equ       %00000001
mHVOCR_HVOCR1       equ       %00000010
mHVOCR_HVOCR2       equ       %00000100

;*** PDCR - Port D Configuration Register
PDCR                equ       $00000049           ;*** PDCR - Port D Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDCR_USBDPLUSE      equ       0                   ; USB D+ Pin Enable
PDCR_USBDMINUSE     equ       1                   ; USB D- Pin Enable
PDCR_DDCDATE        equ       2                   ; DDC Data Pin Enable
PDCR_DDCSCLE        equ       3                   ; DDC Clock Pin Enable
PDCR_CLAMPE         equ       4                   ; CLAMP Pin Enable
PDCR_IICSCLE        equ       5                   ; MMIIC Clock Pin Enable
PDCR_IICDATE        equ       6                   ; MMIIC Data Pin Enable
; bit position masks
mPDCR_USBDPLUSE     equ       %00000001
mPDCR_USBDMINUSE    equ       %00000010
mPDCR_DDCDATE       equ       %00000100
mPDCR_DDCSCLE       equ       %00001000
mPDCR_CLAMPE        equ       %00010000
mPDCR_IICSCLE       equ       %00100000
mPDCR_IICDATE       equ       %01000000

;*** MIMCR - Multi-Master IIC Master Control Register
MIMCR               equ       $0000004A           ;*** MIMCR - Multi-Master IIC Master Control Register
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
MMADR               equ       $0000004B           ;*** MMADR - Multi-Master IIC Address Register
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
MMCR                equ       $0000004C           ;*** MMCR - Multi-Master IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MMCR_MMTXAK         equ       3                   ; Transmit Acknowledge Enable
MMCR_MMIEN          equ       6                   ; Multi-Master IIC Interrupt Enable
MMCR_MMEN           equ       7                   ; Multi-Master IIC Enable
; bit position masks
mMMCR_MMTXAK        equ       %00001000
mMMCR_MMIEN         equ       %01000000
mMMCR_MMEN          equ       %10000000

;*** MMSR - Multi-Master IIC Status Register
MMSR                equ       $0000004D           ;*** MMSR - Multi-Master IIC Status Register
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
MMDTR               equ       $0000004E           ;*** MMDTR - Multi-Master IIC Data Transmit Register
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
MMDRR               equ       $0000004F           ;*** MMDRR - Multi-Master IIC Data Receive Register
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

;*** PWM8 - PWM8 Data Register
PWM8                equ       $00000051           ;*** PWM8 - PWM8 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM8_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM8_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM8_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM8_PWM_0          equ       3                   ; PWM Bit 0
PWM8_PWM_1          equ       4                   ; PWM Bit 1
PWM8_PWM_2          equ       5                   ; PWM Bit 2
PWM8_PWM_3          equ       6                   ; PWM Bit 3
PWM8_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM8_BRM0          equ       %00000001
mPWM8_BRM1          equ       %00000010
mPWM8_BRM2          equ       %00000100
mPWM8_PWM_0         equ       %00001000
mPWM8_PWM_1         equ       %00010000
mPWM8_PWM_2         equ       %00100000
mPWM8_PWM_3         equ       %01000000
mPWM8_PWM_4         equ       %10000000

;*** PWM9 - PWM9 Data Register
PWM9                equ       $00000052           ;*** PWM9 - PWM9 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM9_BRM0           equ       0                   ; Binary Rate Multiplier Bit 0
PWM9_BRM1           equ       1                   ; Binary Rate Multiplier Bit 1
PWM9_BRM2           equ       2                   ; Binary Rate Multiplier Bit 2
PWM9_PWM_0          equ       3                   ; PWM Bit 0
PWM9_PWM_1          equ       4                   ; PWM Bit 1
PWM9_PWM_2          equ       5                   ; PWM Bit 2
PWM9_PWM_3          equ       6                   ; PWM Bit 3
PWM9_PWM_4          equ       7                   ; PWM Bit 4
; bit position masks
mPWM9_BRM0          equ       %00000001
mPWM9_BRM1          equ       %00000010
mPWM9_BRM2          equ       %00000100
mPWM9_PWM_0         equ       %00001000
mPWM9_PWM_1         equ       %00010000
mPWM9_PWM_2         equ       %00100000
mPWM9_PWM_3         equ       %01000000
mPWM9_PWM_4         equ       %10000000

;*** PWM10 - PWM10 Data Register
PWM10               equ       $00000053           ;*** PWM10 - PWM10 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM10_BRM0          equ       0                   ; Binary Rate Multiplier Bit 0
PWM10_BRM1          equ       1                   ; Binary Rate Multiplier Bit 1
PWM10_BRM2          equ       2                   ; Binary Rate Multiplier Bit 2
PWM10_PWM_0         equ       3                   ; PWM Bit 0
PWM10_PWM_1         equ       4                   ; PWM Bit 1
PWM10_PWM_2         equ       5                   ; PWM Bit 2
PWM10_PWM_3         equ       6                   ; PWM Bit 3
PWM10_PWM_4         equ       7                   ; PWM Bit 4
; bit position masks
mPWM10_BRM0         equ       %00000001
mPWM10_BRM1         equ       %00000010
mPWM10_BRM2         equ       %00000100
mPWM10_PWM_0        equ       %00001000
mPWM10_PWM_1        equ       %00010000
mPWM10_PWM_2        equ       %00100000
mPWM10_PWM_3        equ       %01000000
mPWM10_PWM_4        equ       %10000000

;*** PWM11 - PWM11 Data Register
PWM11               equ       $00000054           ;*** PWM11 - PWM11 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM11_BRM0          equ       0                   ; Binary Rate Multiplier Bit 0
PWM11_BRM1          equ       1                   ; Binary Rate Multiplier Bit 1
PWM11_BRM2          equ       2                   ; Binary Rate Multiplier Bit 2
PWM11_PWM_0         equ       3                   ; PWM Bit 0
PWM11_PWM_1         equ       4                   ; PWM Bit 1
PWM11_PWM_2         equ       5                   ; PWM Bit 2
PWM11_PWM_3         equ       6                   ; PWM Bit 3
PWM11_PWM_4         equ       7                   ; PWM Bit 4
; bit position masks
mPWM11_BRM0         equ       %00000001
mPWM11_BRM1         equ       %00000010
mPWM11_BRM2         equ       %00000100
mPWM11_PWM_0        equ       %00001000
mPWM11_PWM_1        equ       %00010000
mPWM11_PWM_2        equ       %00100000
mPWM11_PWM_3        equ       %01000000
mPWM11_PWM_4        equ       %10000000

;*** PWM12 - PWM12 Data Register
PWM12               equ       $00000055           ;*** PWM12 - PWM12 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM12_BRM0          equ       0                   ; Binary Rate Multiplier Bit 0
PWM12_BRM1          equ       1                   ; Binary Rate Multiplier Bit 1
PWM12_BRM2          equ       2                   ; Binary Rate Multiplier Bit 2
PWM12_PWM_0         equ       3                   ; PWM Bit 0
PWM12_PWM_1         equ       4                   ; PWM Bit 1
PWM12_PWM_2         equ       5                   ; PWM Bit 2
PWM12_PWM_3         equ       6                   ; PWM Bit 3
PWM12_PWM_4         equ       7                   ; PWM Bit 4
; bit position masks
mPWM12_BRM0         equ       %00000001
mPWM12_BRM1         equ       %00000010
mPWM12_BRM2         equ       %00000100
mPWM12_PWM_0        equ       %00001000
mPWM12_PWM_1        equ       %00010000
mPWM12_PWM_2        equ       %00100000
mPWM12_PWM_3        equ       %01000000
mPWM12_PWM_4        equ       %10000000

;*** PWM13 - PWM13 Data Register
PWM13               equ       $00000056           ;*** PWM13 - PWM13 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM13_BRM0          equ       0                   ; Binary Rate Multiplier Bit 0
PWM13_BRM1          equ       1                   ; Binary Rate Multiplier Bit 1
PWM13_BRM2          equ       2                   ; Binary Rate Multiplier Bit 2
PWM13_PWM_0         equ       3                   ; PWM Bit 0
PWM13_PWM_1         equ       4                   ; PWM Bit 1
PWM13_PWM_2         equ       5                   ; PWM Bit 2
PWM13_PWM_3         equ       6                   ; PWM Bit 3
PWM13_PWM_4         equ       7                   ; PWM Bit 4
; bit position masks
mPWM13_BRM0         equ       %00000001
mPWM13_BRM1         equ       %00000010
mPWM13_BRM2         equ       %00000100
mPWM13_PWM_0        equ       %00001000
mPWM13_PWM_1        equ       %00010000
mPWM13_PWM_2        equ       %00100000
mPWM13_PWM_3        equ       %01000000
mPWM13_PWM_4        equ       %10000000

;*** PWM14 - PWM14 Data Register
PWM14               equ       $00000057           ;*** PWM14 - PWM14 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM14_BRM0          equ       0                   ; Binary Rate Multiplier Bit 0
PWM14_BRM1          equ       1                   ; Binary Rate Multiplier Bit 1
PWM14_BRM2          equ       2                   ; Binary Rate Multiplier Bit 2
PWM14_PWM_0         equ       3                   ; PWM Bit 0
PWM14_PWM_1         equ       4                   ; PWM Bit 1
PWM14_PWM_2         equ       5                   ; PWM Bit 2
PWM14_PWM_3         equ       6                   ; PWM Bit 3
PWM14_PWM_4         equ       7                   ; PWM Bit 4
; bit position masks
mPWM14_BRM0         equ       %00000001
mPWM14_BRM1         equ       %00000010
mPWM14_BRM2         equ       %00000100
mPWM14_PWM_0        equ       %00001000
mPWM14_PWM_1        equ       %00010000
mPWM14_PWM_2        equ       %00100000
mPWM14_PWM_3        equ       %01000000
mPWM14_PWM_4        equ       %10000000

;*** PWM15 - PWM15 Data Register
PWM15               equ       $00000058           ;*** PWM15 - PWM15 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM15_BRM0          equ       0                   ; Binary Rate Multiplier Bit 0
PWM15_BRM1          equ       1                   ; Binary Rate Multiplier Bit 1
PWM15_BRM2          equ       2                   ; Binary Rate Multiplier Bit 2
PWM15_PWM_0         equ       3                   ; PWM Bit 0
PWM15_PWM_1         equ       4                   ; PWM Bit 1
PWM15_PWM_2         equ       5                   ; PWM Bit 2
PWM15_PWM_3         equ       6                   ; PWM Bit 3
PWM15_PWM_4         equ       7                   ; PWM Bit 4
; bit position masks
mPWM15_BRM0         equ       %00000001
mPWM15_BRM1         equ       %00000010
mPWM15_BRM2         equ       %00000100
mPWM15_PWM_0        equ       %00001000
mPWM15_PWM_1        equ       %00010000
mPWM15_PWM_2        equ       %00100000
mPWM15_PWM_3        equ       %01000000
mPWM15_PWM_4        equ       %10000000

;*** PWMCR2 - PWM Control Register 2
PWMCR2              equ       $00000059           ;*** PWMCR2 - PWM Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWMCR2_PWM8E        equ       0                   ; PWM Output 8 Enable
PWMCR2_PWM9E        equ       1                   ; PWM Output 9 Enable
PWMCR2_PWM10E       equ       2                   ; PWM Output 10 Enable
PWMCR2_PWM11E       equ       3                   ; PWM Output 11 Enable
PWMCR2_PWM12E       equ       4                   ; PWM Output 12 Enable
PWMCR2_PWM13E       equ       5                   ; PWM Output 13 Enable
PWMCR2_PWM14E       equ       6                   ; PWM Output 14 Enable
PWMCR2_PWM15E       equ       7                   ; PWM Output 15 Enable
; bit position masks
mPWMCR2_PWM8E       equ       %00000001
mPWMCR2_PWM9E       equ       %00000010
mPWMCR2_PWM10E      equ       %00000100
mPWMCR2_PWM11E      equ       %00001000
mPWMCR2_PWM12E      equ       %00010000
mPWMCR2_PWM13E      equ       %00100000
mPWMCR2_PWM14E      equ       %01000000
mPWMCR2_PWM15E      equ       %10000000

;*** ADSCR - ADC Status and Control Register
ADSCR               equ       $0000005D           ;*** ADSCR - ADC Status and Control Register
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
ADR                 equ       $0000005E           ;*** ADR - ADC Data Register
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
ADICLK              equ       $0000005F           ;*** ADICLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADICLK_ADIV0        equ       5                   ; ADC Clock Prescaler Bit 0
ADICLK_ADIV1        equ       6                   ; ADC Clock Prescaler Bit 1
ADICLK_ADIV2        equ       7                   ; ADC Clock Prescaler Bit 2
; bit position masks
mADICLK_ADIV0       equ       %00100000
mADICLK_ADIV1       equ       %01000000
mADICLK_ADIV2       equ       %10000000

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
; bit position masks
mINT2_IF7           equ       %00000001
mINT2_IF8           equ       %00000010
mINT2_IF9           equ       %00000100
mINT2_IF10          equ       %00001000

;*** FLCR - FLASH Control Register
FLCR                equ       $0000FE07           ;*** FLCR - FLASH Control Register
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

;*** BRKL - Break Address Register
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Register
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
