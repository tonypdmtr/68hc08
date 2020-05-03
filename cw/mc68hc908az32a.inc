;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908AZ32A, version 2.89.031 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908az32a.inc
;     Processor : MC68HC908AZ32ACFU
;     FileFormat: V2.28
;     DataSheet : MC68HC908AZ32A/D Rev. 0.0, 5/2002
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
;      - 13.04.2006, V2.89.016:
;              - Added symbols for compatibility with ROM version of the AZ32A
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
RAM                 equ       $00000050
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000044F
EEPROM              equ       $00000800
EEPROM_END          equ       $000009FF
;
INT_TIMACH5         equ       $0000FFCC
INT_TIMACH4         equ       $0000FFCE
INT_ADC             equ       $0000FFD0
INT_KBD             equ       $0000FFD2
INT_SCITransmit     equ       $0000FFD4
INT_SCIReceive      equ       $0000FFD6
INT_SCIError        equ       $0000FFD8
INT_CANTransmit     equ       $0000FFDA
INT_CANReceive      equ       $0000FFDC
INT_CANError        equ       $0000FFDE
INT_CANWakeup       equ       $0000FFE0
INT_SPITransmit     equ       $0000FFE2
INT_SPIReceive      equ       $0000FFE4
INT_TIMBOvr         equ       $0000FFE6
INT_TIMBCH1         equ       $0000FFE8
INT_TIMBCH0         equ       $0000FFEA
INT_TIMAOvr         equ       $0000FFEC
INT_TIMACH3         equ       $0000FFEE
INT_TIMACH2         equ       $0000FFF0
INT_TIMACH1         equ       $0000FFF2
INT_TIMACH0         equ       $0000FFF4
INT_PIT             equ       $0000FFF6
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
DDRC_MCLKEN         equ       7                   ; MCLK Enable Bit
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100
mDDRC_DDRC3         equ       %00001000
mDDRC_DDRC4         equ       %00010000
mDDRC_DDRC5         equ       %00100000
mDDRC_MCLKEN        equ       %10000000


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


;*** PTF - Port F Data Register
PTF                 equ       $00000009           ;*** PTF - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTF_PTF0            equ       0                   ; Port F Data Bit 0
PTF_PTF1            equ       1                   ; Port F Data Bit 1
PTF_PTF2            equ       2                   ; Port F Data Bit 2
PTF_PTF3            equ       3                   ; Port F Data Bit 3
PTF_PTF4            equ       4                   ; Port F Data Bit 4
PTF_PTF5            equ       5                   ; Port F Data Bit 5
PTF_PTF6            equ       6                   ; Port F Data Bit 6
; bit position masks
mPTF_PTF0           equ       %00000001
mPTF_PTF1           equ       %00000010
mPTF_PTF2           equ       %00000100
mPTF_PTF3           equ       %00001000
mPTF_PTF4           equ       %00010000
mPTF_PTF5           equ       %00100000
mPTF_PTF6           equ       %01000000


;*** PTG - Port G Data Register
PTG                 equ       $0000000A           ;*** PTG - Port G Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTG_PTG0            equ       0                   ; Port G Data Bit 0
PTG_PTG1            equ       1                   ; Port G Data Bit 1
PTG_PTG2            equ       2                   ; Port G Data Bit 2
; bit position masks
mPTG_PTG0           equ       %00000001
mPTG_PTG1           equ       %00000010
mPTG_PTG2           equ       %00000100


;*** PTH - Port H Data Register
PTH                 equ       $0000000B           ;*** PTH - Port H Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTH_PTH0            equ       0                   ; Port H Data Bit 0
PTH_PTH1            equ       1                   ; Port H Data Bit 1
; bit position masks
mPTH_PTH0           equ       %00000001
mPTH_PTH1           equ       %00000010


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
DDRF_DDRF6          equ       6                   ; Data Direction Register F Bit 6
; bit position masks
mDDRF_DDRF0         equ       %00000001
mDDRF_DDRF1         equ       %00000010
mDDRF_DDRF2         equ       %00000100
mDDRF_DDRF3         equ       %00001000
mDDRF_DDRF4         equ       %00010000
mDDRF_DDRF5         equ       %00100000
mDDRF_DDRF6         equ       %01000000


;*** DDRG - Data Direction Register G
DDRG                equ       $0000000E           ;*** DDRG - Data Direction Register G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRG_DDRG0          equ       0                   ; Data Direction Register G Bit 0
DDRG_DDRG1          equ       1                   ; Data Direction Register G Bit 1
DDRG_DDRG2          equ       2                   ; Data Direction Register G Bit 2
; bit position masks
mDDRG_DDRG0         equ       %00000001
mDDRG_DDRG1         equ       %00000010
mDDRG_DDRG2         equ       %00000100


;*** DDRH - Data Direction Register H
DDRH                equ       $0000000F           ;*** DDRH - Data Direction Register H
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRH_DDRH0          equ       0                   ; Data Direction Register H Bit 0
DDRH_DDRH1          equ       1                   ; Data Direction Register H Bit 1
; bit position masks
mDDRH_DDRH0         equ       %00000001
mDDRH_DDRH1         equ       %00000010


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


;*** ISCR - IRQ Status and Control Register
ISCR                equ       $0000001A           ;*** ISCR - IRQ Status and Control Register
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


;*** PCTL - PLL Control Register
PCTL                equ       $0000001C           ;*** PCTL - PLL Control Register
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
PBWC                equ       $0000001D           ;*** PBWC - PLL Bandwidth Control Register
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
PPG                 equ       $0000001E           ;*** PPG - PLL Programming Register
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


;*** CONFIG1 - Configuration Register
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_COPRS       equ       2                   ; COP Rate Select Bit
CONFIG1_SSREC       equ       3                   ; Short Stop Recovery Bit
CONFIG1_LVIPWR      equ       4                   ; LVI Power Enable Bit
CONFIG1_LVIRST      equ       5                   ; LVI Reset Enable Bit
CONFIG1_LVISTOP     equ       7                   ; LVI Stop Mode Enable Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_COPRS      equ       %00000100
mCONFIG1_SSREC      equ       %00001000
mCONFIG1_LVIPWR     equ       %00010000
mCONFIG1_LVIRST     equ       %00100000
mCONFIG1_LVISTOP    equ       %10000000


;*** TASC - TIMA Status and Control Register
TASC                equ       $00000020           ;*** TASC - TIMA Status and Control Register
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


;*** KBIER - Keyboard Interrupt Enable Register
KBIER               equ       $00000021           ;*** KBIER - Keyboard Interrupt Enable Register
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


;*** TACNT - TIMA Counter Register
TACNT               equ       $00000022           ;*** TACNT - TIMA Counter Register


;*** TACNTH - TIMA Counter Register
TACNTH              equ       $00000022           ;*** TACNTH - TIMA Counter Register


;*** TACNTL - TIMA Counter Register
TACNTL              equ       $00000023           ;*** TACNTL - TIMA Counter Register


;*** TAMOD - TIMA Counter Modulo Register
TAMOD               equ       $00000024           ;*** TAMOD - TIMA Counter Modulo Register


;*** TAMODH - TIMA Counter Modulo Register
TAMODH              equ       $00000024           ;*** TAMODH - TIMA Counter Modulo Register


;*** TAMODL - TIMA Counter Modulo Register
TAMODL              equ       $00000025           ;*** TAMODL - TIMA Counter Modulo Register


;*** TASC0 - TIMA Channel Status and Control Register
TASC0               equ       $00000026           ;*** TASC0 - TIMA Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
TASC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
TASC0_ELS0A         equ       2                   ; Edge/Level Select Bit
TASC0_ELS0B         equ       3                   ; Edge/Level Select Bit
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


;*** TACH0 - TIMA Channel Register
TACH0               equ       $00000027           ;*** TACH0 - TIMA Channel Register


;*** TACH0H - TIMA Channel Register
TACH0H              equ       $00000027           ;*** TACH0H - TIMA Channel Register


;*** TACH0L - TIMA Channel Register
TACH0L              equ       $00000028           ;*** TACH0L - TIMA Channel Register


;*** TASC1 - TIMA Channel Status and Control Register
TASC1               equ       $00000029           ;*** TASC1 - TIMA Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
TASC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
TASC1_ELS1A         equ       2                   ; Edge/Level Select Bit
TASC1_ELS1B         equ       3                   ; Edge/Level Select Bit
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


;*** TACH1 - TIMA Channel Register
TACH1               equ       $0000002A           ;*** TACH1 - TIMA Channel Register


;*** TACH1H - TIMA Channel Register
TACH1H              equ       $0000002A           ;*** TACH1H - TIMA Channel Register


;*** TACH1L - TIMA Channel Register
TACH1L              equ       $0000002B           ;*** TACH1L - TIMA Channel Register


;*** TASC2 - TIMA Channel Status and Control Register
TASC2               equ       $0000002C           ;*** TASC2 - TIMA Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC2_CH2MAX        equ       0                   ; Channel 2 Maximum Duty Cycle Bit
TASC2_TOV2          equ       1                   ; Toggle-On-Overflow Bit
TASC2_ELS2A         equ       2                   ; Edge_Level Select Bits
TASC2_ELS2B         equ       3                   ; Edge_Level Select Bits
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


;*** TACH2 - TIMA Channel Register
TACH2               equ       $0000002D           ;*** TACH2 - TIMA Channel Register


;*** TACH2H - TIMA Channel Register
TACH2H              equ       $0000002D           ;*** TACH2H - TIMA Channel Register


;*** TACH2L - TIMA Channel Register
TACH2L              equ       $0000002E           ;*** TACH2L - TIMA Channel Register


;*** TASC3 - TIMA Channel Status and Control Register
TASC3               equ       $0000002F           ;*** TASC3 - TIMA Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC3_CH3MAX        equ       0                   ; Channel 3 Maximum Duty Cycle Bit
TASC3_TOV3          equ       1                   ; Toggle-On-Overflow Bit
TASC3_ELS3A         equ       2                   ; Edge_Level Select Bits
TASC3_ELS3B         equ       3                   ; Edge_Level Select Bits
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


;*** TACH3 - TIMA Channel Register
TACH3               equ       $00000030           ;*** TACH3 - TIMA Channel Register


;*** TACH3H - TIMA Channel Register
TACH3H              equ       $00000030           ;*** TACH3H - TIMA Channel Register


;*** TACH3L - TIMA Channel Register
TACH3L              equ       $00000031           ;*** TACH3L - TIMA Channel Register


;*** TASC4 - TIMA Channel Status and Control Register
TASC4               equ       $00000032           ;*** TASC4 - TIMA Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC4_CH4MAX        equ       0                   ; Channel 4 Maximum Duty Cycle Bit
TASC4_TOV4          equ       1                   ; Toggle-On-Overflow Bit
TASC4_ELS4A         equ       2                   ; Edge_Level Select Bits
TASC4_ELS4B         equ       3                   ; Edge_Level Select Bits
TASC4_MS4A          equ       4                   ; Mode Select Bit A
TASC4_MS4B          equ       5                   ; Mode Select Bit B
TASC4_CH4IE         equ       6                   ; Channel 4 Interrupt Enable Bit
TASC4_CH4F          equ       7                   ; Channel 4 Flag Bit
; bit position masks
mTASC4_CH4MAX       equ       %00000001
mTASC4_TOV4         equ       %00000010
mTASC4_ELS4A        equ       %00000100
mTASC4_ELS4B        equ       %00001000
mTASC4_MS4A         equ       %00010000
mTASC4_MS4B         equ       %00100000
mTASC4_CH4IE        equ       %01000000
mTASC4_CH4F         equ       %10000000


;*** TACH4 - TIMA Channel Register
TACH4               equ       $00000033           ;*** TACH4 - TIMA Channel Register


;*** TACH4H - TIMA Channel Register
TACH4H              equ       $00000033           ;*** TACH4H - TIMA Channel Register


;*** TACH4L - TIMA Channel Register
TACH4L              equ       $00000034           ;*** TACH4L - TIMA Channel Register


;*** TASC5 - TIMA Channel Status and Control Register
TASC5               equ       $00000035           ;*** TASC5 - TIMA Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TASC5_CH5MAX        equ       0                   ; Channel 5 Maximum Duty Cycle Bit
TASC5_TOV5          equ       1                   ; Toggle-On-Overflow Bit
TASC5_ELS5A         equ       2                   ; Edge_Level Select Bits
TASC5_ELS5B         equ       3                   ; Edge_Level Select Bits
TASC5_MS5A          equ       4                   ; Mode Select Bit A
TASC5_CH5IE         equ       6                   ; Channel 5 Interrupt Enable Bit
TASC5_CH5F          equ       7                   ; Channel 5 Flag Bit
; bit position masks
mTASC5_CH5MAX       equ       %00000001
mTASC5_TOV5         equ       %00000010
mTASC5_ELS5A        equ       %00000100
mTASC5_ELS5B        equ       %00001000
mTASC5_MS5A         equ       %00010000
mTASC5_CH5IE        equ       %01000000
mTASC5_CH5F         equ       %10000000


;*** TACH5 - TIMA Channel Register
TACH5               equ       $00000036           ;*** TACH5 - TIMA Channel Register


;*** TACH5H - TIMA Channel Register
TACH5H              equ       $00000036           ;*** TACH5H - TIMA Channel Register


;*** TACH5L - TIMA Channel Register
TACH5L              equ       $00000037           ;*** TACH5L - TIMA Channel Register


;*** ADSCR - ADC Status and Control Register
ADSCR               equ       $00000038           ;*** ADSCR - ADC Status and Control Register
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
ADR                 equ       $00000039           ;*** ADR - ADC Data Register
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
ADICLK              equ       $0000003A           ;*** ADICLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADICLK_ADICLK_BIT   equ       4                   ; ADC Input Clock Register Bit
ADICLK_ADIV0        equ       5                   ; ADC Clock Prescaler Bit 0
ADICLK_ADIV1        equ       6                   ; ADC Clock Prescaler Bit 1
ADICLK_ADIV2        equ       7                   ; ADC Clock Prescaler Bit 2
; bit position masks
mADICLK_ADICLK_BIT  equ       %00010000
mADICLK_ADIV0       equ       %00100000
mADICLK_ADIV1       equ       %01000000
mADICLK_ADIV2       equ       %10000000


;*** TBSCR - TIMB Status and Control Register
TBSCR               equ       $00000040           ;*** TBSCR - TIMB Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBSCR_PS0           equ       0                   ; Prescaler Select Bit
TBSCR_PS1           equ       1                   ; Prescaler Select Bit
TBSCR_PS2           equ       2                   ; Prescaler Select Bit
TBSCR_TRST          equ       4                   ; TIMB Reset Bit
TBSCR_TSTOP         equ       5                   ; TIMB Stop Bit
TBSCR_TOIE          equ       6                   ; TIMB Overflow Interrupt Enable Bit
TBSCR_TOF           equ       7                   ; TIMB Overflow Flag Bit
; bit position masks
mTBSCR_PS0          equ       %00000001
mTBSCR_PS1          equ       %00000010
mTBSCR_PS2          equ       %00000100
mTBSCR_TRST         equ       %00010000
mTBSCR_TSTOP        equ       %00100000
mTBSCR_TOIE         equ       %01000000
mTBSCR_TOF          equ       %10000000


;*** TBCNT - TIMB Counter Register
TBCNT               equ       $00000041           ;*** TBCNT - TIMB Counter Register


;*** TBCNTH - TIMB Counter Register
TBCNTH              equ       $00000041           ;*** TBCNTH - TIMB Counter Register


;*** TBCNTL - TIMB Counter Register
TBCNTL              equ       $00000042           ;*** TBCNTL - TIMB Counter Register


;*** TBMOD - TIMB Counter Modulo Register
TBMOD               equ       $00000043           ;*** TBMOD - TIMB Counter Modulo Register


;*** TBMODH - TIMB Counter Modulo Register
TBMODH              equ       $00000043           ;*** TBMODH - TIMB Counter Modulo Register


;*** TBMODL - TIMB Counter Modulo Register
TBMODL              equ       $00000044           ;*** TBMODL - TIMB Counter Modulo Register


;*** TBSC0 - TIMB Channel Status and Control Register
TBSC0               equ       $00000045           ;*** TBSC0 - TIMB Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBSC0_CH0MAX        equ       0                   ; Channel 0 Maximum Duty Cycle Bit
TBSC0_TOV0          equ       1                   ; Toggle-On-Overflow Bit
TBSC0_ELS0A         equ       2                   ; Edge/Level Select Bit
TBSC0_ELS0B         equ       3                   ; Edge/Level Select Bit
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


;*** TBCH0 - TIMB Channel Register
TBCH0               equ       $00000046           ;*** TBCH0 - TIMB Channel Register


;*** TBCH0H - TIMB Channel Register
TBCH0H              equ       $00000046           ;*** TBCH0H - TIMB Channel Register


;*** TBCH0L - TIMB Channel Register
TBCH0L              equ       $00000047           ;*** TBCH0L - TIMB Channel Register


;*** TBSC1 - IMB Channel Status and Control Register
TBSC1               equ       $00000048           ;*** TBSC1 - IMB Channel Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBSC1_CH1MAX        equ       0                   ; Channel 1 Maximum Duty Cycle Bit
TBSC1_TOV1          equ       1                   ; Toggle-On-Overflow Bit
TBSC1_ELS1A         equ       2                   ; Edge/Level Select Bit
TBSC1_ELS1B         equ       3                   ; Edge/Level Select Bit
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


;*** TBCH1 - TIMB Channel Register
TBCH1               equ       $00000049           ;*** TBCH1 - TIMB Channel Register


;*** TBCH1H - TIMB Channel Register
TBCH1H              equ       $00000049           ;*** TBCH1H - TIMB Channel Register


;*** TBCH1L - TIMB Channel Register
TBCH1L              equ       $0000004A           ;*** TBCH1L - TIMB Channel Register


;*** PSC - Timer Status & Control
PSC                 equ       $0000004B           ;*** PSC - Timer Status & Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PSC_PPS0            equ       0                   ; Prescaler Select Bit
PSC_PPS1            equ       1                   ; Prescaler Select Bit
PSC_PPS2            equ       2                   ; Prescaler Select Bit
PSC_PRST            equ       4                   ; PIT Reset Bit
PSC_PSTOP           equ       5                   ; PIT Stop Bit
PSC_POIE            equ       6                   ; PIT Overflow Interrupt Enable Bit
PSC_POF             equ       7                   ; PIT Overflow Flag Bit
; bit position masks
mPSC_PPS0           equ       %00000001
mPSC_PPS1           equ       %00000010
mPSC_PPS2           equ       %00000100
mPSC_PRST           equ       %00010000
mPSC_PSTOP          equ       %00100000
mPSC_POIE           equ       %01000000
mPSC_POF            equ       %10000000


;*** PCNT - PIT Counter Register
PCNT                equ       $0000004C           ;*** PCNT - PIT Counter Register


;*** PCNTH - PIT Counter Register
PCNTH               equ       $0000004C           ;*** PCNTH - PIT Counter Register


;*** PCNTL - PIT Counter Register
PCNTL               equ       $0000004D           ;*** PCNTL - PIT Counter Register


;*** PMOD - PIT Counter Modulo Register
PMOD                equ       $0000004E           ;*** PMOD - PIT Counter Modulo Register


;*** PMODH - PIT Counter Modulo Register
PMODH               equ       $0000004E           ;*** PMODH - PIT Counter Modulo Register


;*** PMODL - PIT Counter Modulo Register
PMODL               equ       $0000004F           ;*** PMODL - PIT Counter Modulo Register


;*** CMCR0 - Module Control Register 0
CMCR0               equ       $00000500           ;*** CMCR0 - Module Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMCR0_SFTRES        equ       0                   ; Soft Reset
CMCR0_SLPRQ         equ       1                   ; Sleep Request, Go to Internal Sleep Mode
CMCR0_SLPAK         equ       2                   ; Sleep Mode Acknowledge
CMCR0_TLNKEN        equ       3                   ; Timer Enable
CMCR0_SYNCH         equ       4                   ; Synchronized Status
; bit position masks
mCMCR0_SFTRES       equ       %00000001
mCMCR0_SLPRQ        equ       %00000010
mCMCR0_SLPAK        equ       %00000100
mCMCR0_TLNKEN       equ       %00001000
mCMCR0_SYNCH        equ       %00010000


;*** CMCR1 - Module Control Register 1
CMCR1               equ       $00000501           ;*** CMCR1 - Module Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMCR1_CLKSRC        equ       0                   ; Clock Source
CMCR1_WUPM          equ       1                   ; Wakeup Mode
CMCR1_LOOPB         equ       2                   ; Loop Back Self-Test Mode
; bit position masks
mCMCR1_CLKSRC       equ       %00000001
mCMCR1_WUPM         equ       %00000010
mCMCR1_LOOPB        equ       %00000100


;*** CBTR0 - Bus Timing Register 0
CBTR0               equ       $00000502           ;*** CBTR0 - Bus Timing Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CBTR0_BRP0          equ       0                   ; Baud Rate Prescaler 0
CBTR0_BRP1          equ       1                   ; Baud Rate Prescaler 1
CBTR0_BRP2          equ       2                   ; Baud Rate Prescaler 2
CBTR0_BRP3          equ       3                   ; Baud Rate Prescaler 3
CBTR0_BRP4          equ       4                   ; Baud Rate Prescaler 4
CBTR0_BRP5          equ       5                   ; Baud Rate Prescaler 5
CBTR0_SJW0          equ       6                   ; Synchronization Jump Width 0
CBTR0_SJW1          equ       7                   ; Synchronization Jump Width 1
; bit position masks
mCBTR0_BRP0         equ       %00000001
mCBTR0_BRP1         equ       %00000010
mCBTR0_BRP2         equ       %00000100
mCBTR0_BRP3         equ       %00001000
mCBTR0_BRP4         equ       %00010000
mCBTR0_BRP5         equ       %00100000
mCBTR0_SJW0         equ       %01000000
mCBTR0_SJW1         equ       %10000000


;*** CBTR1 - Bus Timing Register 1
CBTR1               equ       $00000503           ;*** CBTR1 - Bus Timing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CBTR1_TSEG10        equ       0                   ; Time Segment 10
CBTR1_TSEG11        equ       1                   ; Time Segment 11
CBTR1_TSEG12        equ       2                   ; Time Segment 12
CBTR1_TSEG13        equ       3                   ; Time Segment 13
CBTR1_TSEG20        equ       4                   ; Time Segment 20
CBTR1_TSEG21        equ       5                   ; Time Segment 21
CBTR1_TSEG22        equ       6                   ; Time Segment 22
CBTR1_SAMP          equ       7                   ; Sampling
; bit position masks
mCBTR1_TSEG10       equ       %00000001
mCBTR1_TSEG11       equ       %00000010
mCBTR1_TSEG12       equ       %00000100
mCBTR1_TSEG13       equ       %00001000
mCBTR1_TSEG20       equ       %00010000
mCBTR1_TSEG21       equ       %00100000
mCBTR1_TSEG22       equ       %01000000
mCBTR1_SAMP         equ       %10000000


;*** CRFLG - Receiver Flag Register
CRFLG               equ       $00000504           ;*** CRFLG - Receiver Flag Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRFLG_RXF           equ       0                   ; Receive Buffer Full
CRFLG_OVRIF         equ       1                   ; Overrun Interrupt Flag
CRFLG_BOFFIF        equ       2                   ; Bus-Off Interrupt Flag
CRFLG_TERRIF        equ       3                   ; Transmitter Error Passive Interrupt Flag
CRFLG_RERRIF        equ       4                   ; Receiver Error Passive Interrupt Flag
CRFLG_TWRNIF        equ       5                   ; Transmitter Warning Interrupt Flag
CRFLG_RWRNIF        equ       6                   ; Receiver Warning Interrupt Flag
CRFLG_WUPIF         equ       7                   ; Wakeup Interrupt Flag
; bit position masks
mCRFLG_RXF          equ       %00000001
mCRFLG_OVRIF        equ       %00000010
mCRFLG_BOFFIF       equ       %00000100
mCRFLG_TERRIF       equ       %00001000
mCRFLG_RERRIF       equ       %00010000
mCRFLG_TWRNIF       equ       %00100000
mCRFLG_RWRNIF       equ       %01000000
mCRFLG_WUPIF        equ       %10000000


;*** CRIER - Receiver Interrupt Enable Register
CRIER               equ       $00000505           ;*** CRIER - Receiver Interrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRIER_RXFIE         equ       0                   ; Receiver Full Interrupt Enable
CRIER_OVRIE         equ       1                   ; Overrun Interrupt Enable
CRIER_BOFFIE        equ       2                   ; Bus-Off Interrupt Enable
CRIER_TERRIE        equ       3                   ; Transmitter Error Passive Interrupt Enable
CRIER_RERRIE        equ       4                   ; Receiver Error Passive Interrupt Enable
CRIER_TWRNIE        equ       5                   ; Transmitter Warning Interrupt Enable
CRIER_RWRNIE        equ       6                   ; Receiver Warning Interrupt Enable
CRIER_WUPIE         equ       7                   ; Wakeup Interrupt Enable
; bit position masks
mCRIER_RXFIE        equ       %00000001
mCRIER_OVRIE        equ       %00000010
mCRIER_BOFFIE       equ       %00000100
mCRIER_TERRIE       equ       %00001000
mCRIER_RERRIE       equ       %00010000
mCRIER_TWRNIE       equ       %00100000
mCRIER_RWRNIE       equ       %01000000
mCRIER_WUPIE        equ       %10000000


;*** CTFLG - Transmitter Flag Register
CTFLG               equ       $00000506           ;*** CTFLG - Transmitter Flag Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CTFLG_TXE0          equ       0                   ; Transmitter Empty 0
CTFLG_TXE1          equ       1                   ; Transmitter Empty 1
CTFLG_TXE2          equ       2                   ; Transmitter Empty 2
CTFLG_ABTAK0        equ       4                   ; Abort Acknowledge 0
CTFLG_ABTAK1        equ       5                   ; Abort Acknowledge 1
CTFLG_ABTAK2        equ       6                   ; Abort Acknowledge 2
; bit position masks
mCTFLG_TXE0         equ       %00000001
mCTFLG_TXE1         equ       %00000010
mCTFLG_TXE2         equ       %00000100
mCTFLG_ABTAK0       equ       %00010000
mCTFLG_ABTAK1       equ       %00100000
mCTFLG_ABTAK2       equ       %01000000


;*** CTCR - Transmitter Control Register
CTCR                equ       $00000507           ;*** CTCR - Transmitter Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CTCR_TXEIE0         equ       0                   ; Transmitter Empty Interrupt Enable 0
CTCR_TXEIE1         equ       1                   ; Transmitter Empty Interrupt Enable 1
CTCR_TXEIE2         equ       2                   ; Transmitter Empty Interrupt Enable 2
CTCR_ABTRQ0         equ       4                   ; Abort Request 0
CTCR_ABTRQ1         equ       5                   ; Abort Request 1
CTCR_ABTRQ2         equ       6                   ; Abort Request 2
; bit position masks
mCTCR_TXEIE0        equ       %00000001
mCTCR_TXEIE1        equ       %00000010
mCTCR_TXEIE2        equ       %00000100
mCTCR_ABTRQ0        equ       %00010000
mCTCR_ABTRQ1        equ       %00100000
mCTCR_ABTRQ2        equ       %01000000


;*** CIDAC - Identifier Acceptance Control Register
CIDAC               equ       $00000508           ;*** CIDAC - Identifier Acceptance Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDAC_IDHIT0        equ       0                   ; Identifier Acceptance Hit Indicator 0
CIDAC_IDHIT1        equ       1                   ; Identifier Acceptance Hit Indicator 1
CIDAC_IDAM0         equ       4                   ; Identifier Acceptance Mode 0
CIDAC_IDAM1         equ       5                   ; Identifier Acceptance Mode 1
; bit position masks
mCIDAC_IDHIT0       equ       %00000001
mCIDAC_IDHIT1       equ       %00000010
mCIDAC_IDAM0        equ       %00010000
mCIDAC_IDAM1        equ       %00100000


;*** CRXERR - Receiver Error Counter Register
CRXERR              equ       $0000050E           ;*** CRXERR - Receiver Error Counter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRXERR_RXERR0       equ       0                   ; Receiver Error Counter Register Bit 0
CRXERR_RXERR1       equ       1                   ; Receiver Error Counter Register Bit 1
CRXERR_RXERR2       equ       2                   ; Receiver Error Counter Register Bit 2
CRXERR_RXERR3       equ       3                   ; Receiver Error Counter Register Bit 3
CRXERR_RXERR4       equ       4                   ; Receiver Error Counter Register Bit 4
CRXERR_RXERR5       equ       5                   ; Receiver Error Counter Register Bit 5
CRXERR_RXERR6       equ       6                   ; Receiver Error Counter Register Bit 6
CRXERR_RXERR7       equ       7                   ; Receiver Error Counter Register Bit 7
; bit position masks
mCRXERR_RXERR0      equ       %00000001
mCRXERR_RXERR1      equ       %00000010
mCRXERR_RXERR2      equ       %00000100
mCRXERR_RXERR3      equ       %00001000
mCRXERR_RXERR4      equ       %00010000
mCRXERR_RXERR5      equ       %00100000
mCRXERR_RXERR6      equ       %01000000
mCRXERR_RXERR7      equ       %10000000


;*** CTXERR - Transmit Error Counter Register
CTXERR              equ       $0000050F           ;*** CTXERR - Transmit Error Counter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CTXERR_TXERR0       equ       0                   ; Transmit Error Counter Register Bit 0
CTXERR_TXERR1       equ       1                   ; Transmit Error Counter Register Bit 1
CTXERR_TXERR2       equ       2                   ; Transmit Error Counter Register Bit 2
CTXERR_TXERR3       equ       3                   ; Transmit Error Counter Register Bit 3
CTXERR_TXERR4       equ       4                   ; Transmit Error Counter Register Bit 4
CTXERR_TXERR5       equ       5                   ; Transmit Error Counter Register Bit 5
CTXERR_TXERR6       equ       6                   ; Transmit Error Counter Register Bit 6
CTXERR_TXERR7       equ       7                   ; Transmit Error Counter Register Bit 7
; bit position masks
mCTXERR_TXERR0      equ       %00000001
mCTXERR_TXERR1      equ       %00000010
mCTXERR_TXERR2      equ       %00000100
mCTXERR_TXERR3      equ       %00001000
mCTXERR_TXERR4      equ       %00010000
mCTXERR_TXERR5      equ       %00100000
mCTXERR_TXERR6      equ       %01000000
mCTXERR_TXERR7      equ       %10000000


;*** CIDAR - Identifier Acceptance Register
CIDAR               equ       $00000510           ;*** CIDAR - Identifier Acceptance Register


;*** CIDAR0 - Identifier Acceptance Register 0
CIDAR0              equ       $00000510           ;*** CIDAR0 - Identifier Acceptance Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDAR0_AC0          equ       0                   ; Acceptance Code Bit 0
CIDAR0_AC1          equ       1                   ; Acceptance Code Bit 1
CIDAR0_AC2          equ       2                   ; Acceptance Code Bit 2
CIDAR0_AC3          equ       3                   ; Acceptance Code Bit 3
CIDAR0_AC4          equ       4                   ; Acceptance Code Bit 4
CIDAR0_AC5          equ       5                   ; Acceptance Code Bit 5
CIDAR0_AC6          equ       6                   ; Acceptance Code Bit 6
CIDAR0_AC7          equ       7                   ; Acceptance Code Bit 7
; bit position masks
mCIDAR0_AC0         equ       %00000001
mCIDAR0_AC1         equ       %00000010
mCIDAR0_AC2         equ       %00000100
mCIDAR0_AC3         equ       %00001000
mCIDAR0_AC4         equ       %00010000
mCIDAR0_AC5         equ       %00100000
mCIDAR0_AC6         equ       %01000000
mCIDAR0_AC7         equ       %10000000


;*** CIDAR1 - Identifier Acceptance Register 1
CIDAR1              equ       $00000511           ;*** CIDAR1 - Identifier Acceptance Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDAR1_AC0          equ       0                   ; Acceptance Code Bit 0
CIDAR1_AC1          equ       1                   ; Acceptance Code Bit 1
CIDAR1_AC2          equ       2                   ; Acceptance Code Bit 2
CIDAR1_AC3          equ       3                   ; Acceptance Code Bit 3
CIDAR1_AC4          equ       4                   ; Acceptance Code Bit 4
CIDAR1_AC5          equ       5                   ; Acceptance Code Bit 5
CIDAR1_AC6          equ       6                   ; Acceptance Code Bit 6
CIDAR1_AC7          equ       7                   ; Acceptance Code Bit 7
; bit position masks
mCIDAR1_AC0         equ       %00000001
mCIDAR1_AC1         equ       %00000010
mCIDAR1_AC2         equ       %00000100
mCIDAR1_AC3         equ       %00001000
mCIDAR1_AC4         equ       %00010000
mCIDAR1_AC5         equ       %00100000
mCIDAR1_AC6         equ       %01000000
mCIDAR1_AC7         equ       %10000000


;*** CIDAR2 - Identifier Acceptance Register 2
CIDAR2              equ       $00000512           ;*** CIDAR2 - Identifier Acceptance Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDAR2_AC0          equ       0                   ; Acceptance Code Bit 0
CIDAR2_AC1          equ       1                   ; Acceptance Code Bit 1
CIDAR2_AC2          equ       2                   ; Acceptance Code Bit 2
CIDAR2_AC3          equ       3                   ; Acceptance Code Bit 3
CIDAR2_AC4          equ       4                   ; Acceptance Code Bit 4
CIDAR2_AC5          equ       5                   ; Acceptance Code Bit 5
CIDAR2_AC6          equ       6                   ; Acceptance Code Bit 6
CIDAR2_AC7          equ       7                   ; Acceptance Code Bit 7
; bit position masks
mCIDAR2_AC0         equ       %00000001
mCIDAR2_AC1         equ       %00000010
mCIDAR2_AC2         equ       %00000100
mCIDAR2_AC3         equ       %00001000
mCIDAR2_AC4         equ       %00010000
mCIDAR2_AC5         equ       %00100000
mCIDAR2_AC6         equ       %01000000
mCIDAR2_AC7         equ       %10000000


;*** CIDAR3 - Identifier Acceptance Register 3
CIDAR3              equ       $00000513           ;*** CIDAR3 - Identifier Acceptance Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDAR3_AC0          equ       0                   ; Acceptance Code Bit 0
CIDAR3_AC1          equ       1                   ; Acceptance Code Bit 1
CIDAR3_AC2          equ       2                   ; Acceptance Code Bit 2
CIDAR3_AC3          equ       3                   ; Acceptance Code Bit 3
CIDAR3_AC4          equ       4                   ; Acceptance Code Bit 4
CIDAR3_AC5          equ       5                   ; Acceptance Code Bit 5
CIDAR3_AC6          equ       6                   ; Acceptance Code Bit 6
CIDAR3_AC7          equ       7                   ; Acceptance Code Bit 7
; bit position masks
mCIDAR3_AC0         equ       %00000001
mCIDAR3_AC1         equ       %00000010
mCIDAR3_AC2         equ       %00000100
mCIDAR3_AC3         equ       %00001000
mCIDAR3_AC4         equ       %00010000
mCIDAR3_AC5         equ       %00100000
mCIDAR3_AC6         equ       %01000000
mCIDAR3_AC7         equ       %10000000


;*** CIDMR - Identifier Mask Register
CIDMR               equ       $00000514           ;*** CIDMR - Identifier Mask Register


;*** CIDMR0 - Identifier Mask Register 0
CIDMR0              equ       $00000514           ;*** CIDMR0 - Identifier Mask Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDMR0_AM0          equ       0                   ; Acceptance Mask Bit 0
CIDMR0_AM1          equ       1                   ; Acceptance Mask Bit 1
CIDMR0_AM2          equ       2                   ; Acceptance Mask Bit 2
CIDMR0_AM3          equ       3                   ; Acceptance Mask Bit 3
CIDMR0_AM4          equ       4                   ; Acceptance Mask Bit 4
CIDMR0_AM5          equ       5                   ; Acceptance Mask Bit 5
CIDMR0_AM6          equ       6                   ; Acceptance Mask Bit 6
CIDMR0_AM7          equ       7                   ; Acceptance Mask Bit 7
; bit position masks
mCIDMR0_AM0         equ       %00000001
mCIDMR0_AM1         equ       %00000010
mCIDMR0_AM2         equ       %00000100
mCIDMR0_AM3         equ       %00001000
mCIDMR0_AM4         equ       %00010000
mCIDMR0_AM5         equ       %00100000
mCIDMR0_AM6         equ       %01000000
mCIDMR0_AM7         equ       %10000000


;*** CIDMR1 - Identifier Mask Register 1
CIDMR1              equ       $00000515           ;*** CIDMR1 - Identifier Mask Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDMR1_AM0          equ       0                   ; Acceptance Mask Bit 0
CIDMR1_AM1          equ       1                   ; Acceptance Mask Bit 1
CIDMR1_AM2          equ       2                   ; Acceptance Mask Bit 2
CIDMR1_AM3          equ       3                   ; Acceptance Mask Bit 3
CIDMR1_AM4          equ       4                   ; Acceptance Mask Bit 4
CIDMR1_AM5          equ       5                   ; Acceptance Mask Bit 5
CIDMR1_AM6          equ       6                   ; Acceptance Mask Bit 6
CIDMR1_AM7          equ       7                   ; Acceptance Mask Bit 7
; bit position masks
mCIDMR1_AM0         equ       %00000001
mCIDMR1_AM1         equ       %00000010
mCIDMR1_AM2         equ       %00000100
mCIDMR1_AM3         equ       %00001000
mCIDMR1_AM4         equ       %00010000
mCIDMR1_AM5         equ       %00100000
mCIDMR1_AM6         equ       %01000000
mCIDMR1_AM7         equ       %10000000


;*** CIDMR2 - Identifier Mask Register 2
CIDMR2              equ       $00000516           ;*** CIDMR2 - Identifier Mask Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDMR2_AM0          equ       0                   ; Acceptance Mask Bit 0
CIDMR2_AM1          equ       1                   ; Acceptance Mask Bit 1
CIDMR2_AM2          equ       2                   ; Acceptance Mask Bit 2
CIDMR2_AM3          equ       3                   ; Acceptance Mask Bit 3
CIDMR2_AM4          equ       4                   ; Acceptance Mask Bit 4
CIDMR2_AM5          equ       5                   ; Acceptance Mask Bit 5
CIDMR2_AM6          equ       6                   ; Acceptance Mask Bit 6
CIDMR2_AM7          equ       7                   ; Acceptance Mask Bit 7
; bit position masks
mCIDMR2_AM0         equ       %00000001
mCIDMR2_AM1         equ       %00000010
mCIDMR2_AM2         equ       %00000100
mCIDMR2_AM3         equ       %00001000
mCIDMR2_AM4         equ       %00010000
mCIDMR2_AM5         equ       %00100000
mCIDMR2_AM6         equ       %01000000
mCIDMR2_AM7         equ       %10000000


;*** CIDMR3 - Identifier Mask Register 3
CIDMR3              equ       $00000517           ;*** CIDMR3 - Identifier Mask Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CIDMR3_AM0          equ       0                   ; Acceptance Mask Bit 0
CIDMR3_AM1          equ       1                   ; Acceptance Mask Bit 1
CIDMR3_AM2          equ       2                   ; Acceptance Mask Bit 2
CIDMR3_AM3          equ       3                   ; Acceptance Mask Bit 3
CIDMR3_AM4          equ       4                   ; Acceptance Mask Bit 4
CIDMR3_AM5          equ       5                   ; Acceptance Mask Bit 5
CIDMR3_AM6          equ       6                   ; Acceptance Mask Bit 6
CIDMR3_AM7          equ       7                   ; Acceptance Mask Bit 7
; bit position masks
mCIDMR3_AM0         equ       %00000001
mCIDMR3_AM1         equ       %00000010
mCIDMR3_AM2         equ       %00000100
mCIDMR3_AM3         equ       %00001000
mCIDMR3_AM4         equ       %00010000
mCIDMR3_AM5         equ       %00100000
mCIDMR3_AM6         equ       %01000000
mCIDMR3_AM7         equ       %10000000


;*** REC_IDR - Receive Buffer Identifier Register
REC_IDR             equ       $00000540           ;*** REC_IDR - Receive Buffer Identifier Register


;*** REC_IDR0 - Receive Buffer Identifier Register 0
REC_IDR0            equ       $00000540           ;*** REC_IDR0 - Receive Buffer Identifier Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_IDR0_ID21       equ       0                   ; Identifier Register Bit
REC_IDR0_ID22       equ       1                   ; Identifier Register Bit
REC_IDR0_ID23       equ       2                   ; Identifier Register Bit
REC_IDR0_ID24       equ       3                   ; Identifier Register Bit
REC_IDR0_ID25       equ       4                   ; Identifier Register Bit
REC_IDR0_ID26       equ       5                   ; Identifier Register Bit
REC_IDR0_ID27       equ       6                   ; Identifier Register Bit
REC_IDR0_ID28       equ       7                   ; Identifier Register Bit
; bit position masks
mREC_IDR0_ID21      equ       %00000001
mREC_IDR0_ID22      equ       %00000010
mREC_IDR0_ID23      equ       %00000100
mREC_IDR0_ID24      equ       %00001000
mREC_IDR0_ID25      equ       %00010000
mREC_IDR0_ID26      equ       %00100000
mREC_IDR0_ID27      equ       %01000000
mREC_IDR0_ID28      equ       %10000000


;*** REC_IDR1 - Receive Buffer Identifier Register 1
REC_IDR1            equ       $00000541           ;*** REC_IDR1 - Receive Buffer Identifier Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_IDR1_ID15       equ       0                   ; Identifier Register Bit
REC_IDR1_ID16       equ       1                   ; Identifier Register Bit
REC_IDR1_ID17       equ       2                   ; Identifier Register Bit
REC_IDR1_IDE        equ       3                   ; ID Extended
REC_IDR1_SRR        equ       4                   ; Substitute Remote Request
REC_IDR1_ID18       equ       5                   ; Identifier Register Bit
REC_IDR1_ID19       equ       6                   ; Identifier Register Bit
REC_IDR1_ID20       equ       7                   ; Identifier Register Bit
; bit position masks
mREC_IDR1_ID15      equ       %00000001
mREC_IDR1_ID16      equ       %00000010
mREC_IDR1_ID17      equ       %00000100
mREC_IDR1_IDE       equ       %00001000
mREC_IDR1_SRR       equ       %00010000
mREC_IDR1_ID18      equ       %00100000
mREC_IDR1_ID19      equ       %01000000
mREC_IDR1_ID20      equ       %10000000


;*** REC_IDR2 - Receive Buffer Identifier Register 2
REC_IDR2            equ       $00000542           ;*** REC_IDR2 - Receive Buffer Identifier Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_IDR2_ID7        equ       0                   ; Identifier Register Bit
REC_IDR2_ID8        equ       1                   ; Identifier Register Bit
REC_IDR2_ID9        equ       2                   ; Identifier Register Bit
REC_IDR2_ID10       equ       3                   ; Identifier Register Bit
REC_IDR2_ID11       equ       4                   ; Identifier Register Bit
REC_IDR2_ID12       equ       5                   ; Identifier Register Bit
REC_IDR2_ID13       equ       6                   ; Identifier Register Bit
REC_IDR2_ID14       equ       7                   ; Identifier Register Bit
; bit position masks
mREC_IDR2_ID7       equ       %00000001
mREC_IDR2_ID8       equ       %00000010
mREC_IDR2_ID9       equ       %00000100
mREC_IDR2_ID10      equ       %00001000
mREC_IDR2_ID11      equ       %00010000
mREC_IDR2_ID12      equ       %00100000
mREC_IDR2_ID13      equ       %01000000
mREC_IDR2_ID14      equ       %10000000


;*** REC_IDR3 - Receive Buffer Identifier Register 3
REC_IDR3            equ       $00000543           ;*** REC_IDR3 - Receive Buffer Identifier Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_IDR3_RTR        equ       0                   ; Remote Transmission Request
REC_IDR3_ID0        equ       1                   ; Identifier Register Bit
REC_IDR3_ID1        equ       2                   ; Identifier Register Bit
REC_IDR3_ID2        equ       3                   ; Identifier Register Bit
REC_IDR3_ID3        equ       4                   ; Identifier Register Bit
REC_IDR3_ID4        equ       5                   ; Identifier Register Bit
REC_IDR3_ID5        equ       6                   ; Identifier Register Bit
REC_IDR3_ID6        equ       7                   ; Identifier Register Bit
; bit position masks
mREC_IDR3_RTR       equ       %00000001
mREC_IDR3_ID0       equ       %00000010
mREC_IDR3_ID1       equ       %00000100
mREC_IDR3_ID2       equ       %00001000
mREC_IDR3_ID3       equ       %00010000
mREC_IDR3_ID4       equ       %00100000
mREC_IDR3_ID5       equ       %01000000
mREC_IDR3_ID6       equ       %10000000



;*** REC_DSR0 - Receive Buffer Data Segment Register 0
REC_DSR0            equ       $00000544           ;*** REC_DSR0 - Receive Buffer Data Segment Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR0_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR0_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR0_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR0_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR0_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR0_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR0_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR0_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR0_DB0       equ       %00000001
mREC_DSR0_DB1       equ       %00000010
mREC_DSR0_DB2       equ       %00000100
mREC_DSR0_DB3       equ       %00001000
mREC_DSR0_DB4       equ       %00010000
mREC_DSR0_DB5       equ       %00100000
mREC_DSR0_DB6       equ       %01000000
mREC_DSR0_DB7       equ       %10000000


;*** REC_DSR1 - Receive Buffer Data Segment Register 1
REC_DSR1            equ       $00000545           ;*** REC_DSR1 - Receive Buffer Data Segment Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR1_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR1_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR1_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR1_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR1_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR1_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR1_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR1_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR1_DB0       equ       %00000001
mREC_DSR1_DB1       equ       %00000010
mREC_DSR1_DB2       equ       %00000100
mREC_DSR1_DB3       equ       %00001000
mREC_DSR1_DB4       equ       %00010000
mREC_DSR1_DB5       equ       %00100000
mREC_DSR1_DB6       equ       %01000000
mREC_DSR1_DB7       equ       %10000000


;*** REC_DSR2 - Receive Buffer Data Segment Register 2
REC_DSR2            equ       $00000546           ;*** REC_DSR2 - Receive Buffer Data Segment Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR2_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR2_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR2_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR2_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR2_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR2_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR2_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR2_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR2_DB0       equ       %00000001
mREC_DSR2_DB1       equ       %00000010
mREC_DSR2_DB2       equ       %00000100
mREC_DSR2_DB3       equ       %00001000
mREC_DSR2_DB4       equ       %00010000
mREC_DSR2_DB5       equ       %00100000
mREC_DSR2_DB6       equ       %01000000
mREC_DSR2_DB7       equ       %10000000


;*** REC_DSR3 - Receive Buffer Data Segment Register 3
REC_DSR3            equ       $00000547           ;*** REC_DSR3 - Receive Buffer Data Segment Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR3_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR3_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR3_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR3_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR3_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR3_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR3_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR3_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR3_DB0       equ       %00000001
mREC_DSR3_DB1       equ       %00000010
mREC_DSR3_DB2       equ       %00000100
mREC_DSR3_DB3       equ       %00001000
mREC_DSR3_DB4       equ       %00010000
mREC_DSR3_DB5       equ       %00100000
mREC_DSR3_DB6       equ       %01000000
mREC_DSR3_DB7       equ       %10000000


;*** REC_DSR4 - Receive Buffer Data Segment Register 4
REC_DSR4            equ       $00000548           ;*** REC_DSR4 - Receive Buffer Data Segment Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR4_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR4_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR4_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR4_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR4_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR4_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR4_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR4_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR4_DB0       equ       %00000001
mREC_DSR4_DB1       equ       %00000010
mREC_DSR4_DB2       equ       %00000100
mREC_DSR4_DB3       equ       %00001000
mREC_DSR4_DB4       equ       %00010000
mREC_DSR4_DB5       equ       %00100000
mREC_DSR4_DB6       equ       %01000000
mREC_DSR4_DB7       equ       %10000000


;*** REC_DSR5 - Receive Buffer Data Segment Register 5
REC_DSR5            equ       $00000549           ;*** REC_DSR5 - Receive Buffer Data Segment Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR5_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR5_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR5_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR5_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR5_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR5_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR5_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR5_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR5_DB0       equ       %00000001
mREC_DSR5_DB1       equ       %00000010
mREC_DSR5_DB2       equ       %00000100
mREC_DSR5_DB3       equ       %00001000
mREC_DSR5_DB4       equ       %00010000
mREC_DSR5_DB5       equ       %00100000
mREC_DSR5_DB6       equ       %01000000
mREC_DSR5_DB7       equ       %10000000


;*** REC_DSR6 - Receive Buffer Data Segment Register 6
REC_DSR6            equ       $0000054A           ;*** REC_DSR6 - Receive Buffer Data Segment Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR6_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR6_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR6_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR6_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR6_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR6_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR6_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR6_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR6_DB0       equ       %00000001
mREC_DSR6_DB1       equ       %00000010
mREC_DSR6_DB2       equ       %00000100
mREC_DSR6_DB3       equ       %00001000
mREC_DSR6_DB4       equ       %00010000
mREC_DSR6_DB5       equ       %00100000
mREC_DSR6_DB6       equ       %01000000
mREC_DSR6_DB7       equ       %10000000


;*** REC_DSR7 - Receive Buffer Data Segment Register 7
REC_DSR7            equ       $0000054B           ;*** REC_DSR7 - Receive Buffer Data Segment Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DSR7_DB0        equ       0                   ; Data Segment Register Bit
REC_DSR7_DB1        equ       1                   ; Data Segment Register Bit
REC_DSR7_DB2        equ       2                   ; Data Segment Register Bit
REC_DSR7_DB3        equ       3                   ; Data Segment Register Bit
REC_DSR7_DB4        equ       4                   ; Data Segment Register Bit
REC_DSR7_DB5        equ       5                   ; Data Segment Register Bit
REC_DSR7_DB6        equ       6                   ; Data Segment Register Bit
REC_DSR7_DB7        equ       7                   ; Data Segment Register Bit
; bit position masks
mREC_DSR7_DB0       equ       %00000001
mREC_DSR7_DB1       equ       %00000010
mREC_DSR7_DB2       equ       %00000100
mREC_DSR7_DB3       equ       %00001000
mREC_DSR7_DB4       equ       %00010000
mREC_DSR7_DB5       equ       %00100000
mREC_DSR7_DB6       equ       %01000000
mREC_DSR7_DB7       equ       %10000000


;*** REC_DLR - Receive Buffer Data Length Register
REC_DLR             equ       $0000054C           ;*** REC_DLR - Receive Buffer Data Length Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REC_DLR_DLC0        equ       0                   ; Data Length Code Bit
REC_DLR_DLC1        equ       1                   ; Data Length Code Bit
REC_DLR_DLC2        equ       2                   ; Data Length Code Bit
REC_DLR_DLC3        equ       3                   ; Data Length Code Bit
; bit position masks
mREC_DLR_DLC0       equ       %00000001
mREC_DLR_DLC1       equ       %00000010
mREC_DLR_DLC2       equ       %00000100
mREC_DLR_DLC3       equ       %00001000


;*** IDR0 - Transmit Buffer 0 Identifier Register
IDR0                equ       $00000550           ;*** IDR0 - Transmit Buffer 0 Identifier Register


;*** IDR00 - Transmit Buffer 0 Identifier Register 0
IDR00               equ       $00000550           ;*** IDR00 - Transmit Buffer 0 Identifier Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR00_ID21          equ       0                   ; Identifier Register Bit
IDR00_ID22          equ       1                   ; Identifier Register Bit
IDR00_ID23          equ       2                   ; Identifier Register Bit
IDR00_ID24          equ       3                   ; Identifier Register Bit
IDR00_ID25          equ       4                   ; Identifier Register Bit
IDR00_ID26          equ       5                   ; Identifier Register Bit
IDR00_ID27          equ       6                   ; Identifier Register Bit
IDR00_ID28          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR00_ID21         equ       %00000001
mIDR00_ID22         equ       %00000010
mIDR00_ID23         equ       %00000100
mIDR00_ID24         equ       %00001000
mIDR00_ID25         equ       %00010000
mIDR00_ID26         equ       %00100000
mIDR00_ID27         equ       %01000000
mIDR00_ID28         equ       %10000000


;*** IDR10 - Transmit Buffer 0 Identifier Register 1
IDR10               equ       $00000551           ;*** IDR10 - Transmit Buffer 0 Identifier Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR10_ID15          equ       0                   ; Identifier Register Bit
IDR10_ID16          equ       1                   ; Identifier Register Bit
IDR10_ID17          equ       2                   ; Identifier Register Bit
IDR10_IDE           equ       3                   ; ID Extended
IDR10_SRR           equ       4                   ; Substitute Remote Request
IDR10_ID18          equ       5                   ; Identifier Register Bit
IDR10_ID19          equ       6                   ; Identifier Register Bit
IDR10_ID20          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR10_ID15         equ       %00000001
mIDR10_ID16         equ       %00000010
mIDR10_ID17         equ       %00000100
mIDR10_IDE          equ       %00001000
mIDR10_SRR          equ       %00010000
mIDR10_ID18         equ       %00100000
mIDR10_ID19         equ       %01000000
mIDR10_ID20         equ       %10000000


;*** IDR20 - Transmit Buffer 0 Identifier Register 2
IDR20               equ       $00000552           ;*** IDR20 - Transmit Buffer 0 Identifier Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR20_ID7           equ       0                   ; Identifier Register Bit
IDR20_ID8           equ       1                   ; Identifier Register Bit
IDR20_ID9           equ       2                   ; Identifier Register Bit
IDR20_ID10          equ       3                   ; Identifier Register Bit
IDR20_ID11          equ       4                   ; Identifier Register Bit
IDR20_ID12          equ       5                   ; Identifier Register Bit
IDR20_ID13          equ       6                   ; Identifier Register Bit
IDR20_ID14          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR20_ID7          equ       %00000001
mIDR20_ID8          equ       %00000010
mIDR20_ID9          equ       %00000100
mIDR20_ID10         equ       %00001000
mIDR20_ID11         equ       %00010000
mIDR20_ID12         equ       %00100000
mIDR20_ID13         equ       %01000000
mIDR20_ID14         equ       %10000000


;*** IDR30 - Transmit Buffer 0 Identifier Register 3
IDR30               equ       $00000553           ;*** IDR30 - Transmit Buffer 0 Identifier Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR30_RTR           equ       0                   ; Remote Transmission Request
IDR30_ID0           equ       1                   ; Identifier Register Bit
IDR30_ID1           equ       2                   ; Identifier Register Bit
IDR30_ID2           equ       3                   ; Identifier Register Bit
IDR30_ID3           equ       4                   ; Identifier Register Bit
IDR30_ID4           equ       5                   ; Identifier Register Bit
IDR30_ID5           equ       6                   ; Identifier Register Bit
IDR30_ID6           equ       7                   ; Identifier Register Bit
; bit position masks
mIDR30_RTR          equ       %00000001
mIDR30_ID0          equ       %00000010
mIDR30_ID1          equ       %00000100
mIDR30_ID2          equ       %00001000
mIDR30_ID3          equ       %00010000
mIDR30_ID4          equ       %00100000
mIDR30_ID5          equ       %01000000
mIDR30_ID6          equ       %10000000


;*** DSR00 - Transmit Buffer 0 Data Segment Register 0
DSR00               equ       $00000554           ;*** DSR00 - Transmit Buffer 0 Data Segment Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR00_DB0           equ       0                   ; Data Segment Register Bit
DSR00_DB1           equ       1                   ; Data Segment Register Bit
DSR00_DB2           equ       2                   ; Data Segment Register Bit
DSR00_DB3           equ       3                   ; Data Segment Register Bit
DSR00_DB4           equ       4                   ; Data Segment Register Bit
DSR00_DB5           equ       5                   ; Data Segment Register Bit
DSR00_DB6           equ       6                   ; Data Segment Register Bit
DSR00_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR00_DB0          equ       %00000001
mDSR00_DB1          equ       %00000010
mDSR00_DB2          equ       %00000100
mDSR00_DB3          equ       %00001000
mDSR00_DB4          equ       %00010000
mDSR00_DB5          equ       %00100000
mDSR00_DB6          equ       %01000000
mDSR00_DB7          equ       %10000000


;*** DSR10 - Transmit Buffer 0 Data Segment Register 1
DSR10               equ       $00000555           ;*** DSR10 - Transmit Buffer 0 Data Segment Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR10_DB0           equ       0                   ; Data Segment Register Bit
DSR10_DB1           equ       1                   ; Data Segment Register Bit
DSR10_DB2           equ       2                   ; Data Segment Register Bit
DSR10_DB3           equ       3                   ; Data Segment Register Bit
DSR10_DB4           equ       4                   ; Data Segment Register Bit
DSR10_DB5           equ       5                   ; Data Segment Register Bit
DSR10_DB6           equ       6                   ; Data Segment Register Bit
DSR10_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR10_DB0          equ       %00000001
mDSR10_DB1          equ       %00000010
mDSR10_DB2          equ       %00000100
mDSR10_DB3          equ       %00001000
mDSR10_DB4          equ       %00010000
mDSR10_DB5          equ       %00100000
mDSR10_DB6          equ       %01000000
mDSR10_DB7          equ       %10000000


;*** DSR20 - Transmit Buffer 0 Data Segment Register 2
DSR20               equ       $00000556           ;*** DSR20 - Transmit Buffer 0 Data Segment Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR20_DB0           equ       0                   ; Data Segment Register Bit
DSR20_DB1           equ       1                   ; Data Segment Register Bit
DSR20_DB2           equ       2                   ; Data Segment Register Bit
DSR20_DB3           equ       3                   ; Data Segment Register Bit
DSR20_DB4           equ       4                   ; Data Segment Register Bit
DSR20_DB5           equ       5                   ; Data Segment Register Bit
DSR20_DB6           equ       6                   ; Data Segment Register Bit
DSR20_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR20_DB0          equ       %00000001
mDSR20_DB1          equ       %00000010
mDSR20_DB2          equ       %00000100
mDSR20_DB3          equ       %00001000
mDSR20_DB4          equ       %00010000
mDSR20_DB5          equ       %00100000
mDSR20_DB6          equ       %01000000
mDSR20_DB7          equ       %10000000


;*** DSR30 - Transmit Buffer 0 Data Segment Register 3
DSR30               equ       $00000557           ;*** DSR30 - Transmit Buffer 0 Data Segment Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR30_DB0           equ       0                   ; Data Segment Register Bit
DSR30_DB1           equ       1                   ; Data Segment Register Bit
DSR30_DB2           equ       2                   ; Data Segment Register Bit
DSR30_DB3           equ       3                   ; Data Segment Register Bit
DSR30_DB4           equ       4                   ; Data Segment Register Bit
DSR30_DB5           equ       5                   ; Data Segment Register Bit
DSR30_DB6           equ       6                   ; Data Segment Register Bit
DSR30_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR30_DB0          equ       %00000001
mDSR30_DB1          equ       %00000010
mDSR30_DB2          equ       %00000100
mDSR30_DB3          equ       %00001000
mDSR30_DB4          equ       %00010000
mDSR30_DB5          equ       %00100000
mDSR30_DB6          equ       %01000000
mDSR30_DB7          equ       %10000000


;*** DSR40 - Transmit Buffer 0 Data Segment Register 4
DSR40               equ       $00000558           ;*** DSR40 - Transmit Buffer 0 Data Segment Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR40_DB0           equ       0                   ; Data Segment Register Bit
DSR40_DB1           equ       1                   ; Data Segment Register Bit
DSR40_DB2           equ       2                   ; Data Segment Register Bit
DSR40_DB3           equ       3                   ; Data Segment Register Bit
DSR40_DB4           equ       4                   ; Data Segment Register Bit
DSR40_DB5           equ       5                   ; Data Segment Register Bit
DSR40_DB6           equ       6                   ; Data Segment Register Bit
DSR40_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR40_DB0          equ       %00000001
mDSR40_DB1          equ       %00000010
mDSR40_DB2          equ       %00000100
mDSR40_DB3          equ       %00001000
mDSR40_DB4          equ       %00010000
mDSR40_DB5          equ       %00100000
mDSR40_DB6          equ       %01000000
mDSR40_DB7          equ       %10000000


;*** DSR50 - Transmit Buffer 0 Data Segment Register 5
DSR50               equ       $00000559           ;*** DSR50 - Transmit Buffer 0 Data Segment Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR50_DB0           equ       0                   ; Data Segment Register Bit
DSR50_DB1           equ       1                   ; Data Segment Register Bit
DSR50_DB2           equ       2                   ; Data Segment Register Bit
DSR50_DB3           equ       3                   ; Data Segment Register Bit
DSR50_DB4           equ       4                   ; Data Segment Register Bit
DSR50_DB5           equ       5                   ; Data Segment Register Bit
DSR50_DB6           equ       6                   ; Data Segment Register Bit
DSR50_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR50_DB0          equ       %00000001
mDSR50_DB1          equ       %00000010
mDSR50_DB2          equ       %00000100
mDSR50_DB3          equ       %00001000
mDSR50_DB4          equ       %00010000
mDSR50_DB5          equ       %00100000
mDSR50_DB6          equ       %01000000
mDSR50_DB7          equ       %10000000


;*** DSR60 - Transmit Buffer 0 Data Segment Register 6
DSR60               equ       $0000055A           ;*** DSR60 - Transmit Buffer 0 Data Segment Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR60_DB0           equ       0                   ; Data Segment Register Bit
DSR60_DB1           equ       1                   ; Data Segment Register Bit
DSR60_DB2           equ       2                   ; Data Segment Register Bit
DSR60_DB3           equ       3                   ; Data Segment Register Bit
DSR60_DB4           equ       4                   ; Data Segment Register Bit
DSR60_DB5           equ       5                   ; Data Segment Register Bit
DSR60_DB6           equ       6                   ; Data Segment Register Bit
DSR60_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR60_DB0          equ       %00000001
mDSR60_DB1          equ       %00000010
mDSR60_DB2          equ       %00000100
mDSR60_DB3          equ       %00001000
mDSR60_DB4          equ       %00010000
mDSR60_DB5          equ       %00100000
mDSR60_DB6          equ       %01000000
mDSR60_DB7          equ       %10000000


;*** DSR70 - Transmit Buffer 0 Data Segment Register 7
DSR70               equ       $0000055B           ;*** DSR70 - Transmit Buffer 0 Data Segment Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR70_DB0           equ       0                   ; Data Segment Register Bit
DSR70_DB1           equ       1                   ; Data Segment Register Bit
DSR70_DB2           equ       2                   ; Data Segment Register Bit
DSR70_DB3           equ       3                   ; Data Segment Register Bit
DSR70_DB4           equ       4                   ; Data Segment Register Bit
DSR70_DB5           equ       5                   ; Data Segment Register Bit
DSR70_DB6           equ       6                   ; Data Segment Register Bit
DSR70_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR70_DB0          equ       %00000001
mDSR70_DB1          equ       %00000010
mDSR70_DB2          equ       %00000100
mDSR70_DB3          equ       %00001000
mDSR70_DB4          equ       %00010000
mDSR70_DB5          equ       %00100000
mDSR70_DB6          equ       %01000000
mDSR70_DB7          equ       %10000000


;*** DLR0 - Transmit Buffer 0 Data Length Register
DLR0                equ       $0000055C           ;*** DLR0 - Transmit Buffer 0 Data Length Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DLR0_DLC0           equ       0                   ; Data Length Code Bit
DLR0_DLC1           equ       1                   ; Data Length Code Bit
DLR0_DLC2           equ       2                   ; Data Length Code Bit
DLR0_DLC3           equ       3                   ; Data Length Code Bit
; bit position masks
mDLR0_DLC0          equ       %00000001
mDLR0_DLC1          equ       %00000010
mDLR0_DLC2          equ       %00000100
mDLR0_DLC3          equ       %00001000


;*** TBPR0 - Transmit Buffer 0 Priority Register
TBPR0               equ       $0000055D           ;*** TBPR0 - Transmit Buffer 0 Priority Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBPR0_PRIO0         equ       0                   ; Local Priority
TBPR0_PRIO1         equ       1                   ; Local Priority
TBPR0_PRIO2         equ       2                   ; Local Priority
TBPR0_PRIO3         equ       3                   ; Local Priority
TBPR0_PRIO4         equ       4                   ; Local Priority
TBPR0_PRIO5         equ       5                   ; Local Priority
TBPR0_PRIO6         equ       6                   ; Local Priority
TBPR0_PRIO7         equ       7                   ; Local Priority
; bit position masks
mTBPR0_PRIO0        equ       %00000001
mTBPR0_PRIO1        equ       %00000010
mTBPR0_PRIO2        equ       %00000100
mTBPR0_PRIO3        equ       %00001000
mTBPR0_PRIO4        equ       %00010000
mTBPR0_PRIO5        equ       %00100000
mTBPR0_PRIO6        equ       %01000000
mTBPR0_PRIO7        equ       %10000000


;*** IDR1 - Transmit Buffer 1 Identifier Register
IDR1                equ       $00000560           ;*** IDR1 - Transmit Buffer 1 Identifier Register


;*** IDR01 - Transmit Buffer 1 Identifier Register 0
IDR01               equ       $00000560           ;*** IDR01 - Transmit Buffer 1 Identifier Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR01_ID21          equ       0                   ; Identifier Register Bit
IDR01_ID22          equ       1                   ; Identifier Register Bit
IDR01_ID23          equ       2                   ; Identifier Register Bit
IDR01_ID24          equ       3                   ; Identifier Register Bit
IDR01_ID25          equ       4                   ; Identifier Register Bit
IDR01_ID26          equ       5                   ; Identifier Register Bit
IDR01_ID27          equ       6                   ; Identifier Register Bit
IDR01_ID28          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR01_ID21         equ       %00000001
mIDR01_ID22         equ       %00000010
mIDR01_ID23         equ       %00000100
mIDR01_ID24         equ       %00001000
mIDR01_ID25         equ       %00010000
mIDR01_ID26         equ       %00100000
mIDR01_ID27         equ       %01000000
mIDR01_ID28         equ       %10000000


;*** IDR11 - Transmit Buffer 1 Identifier Register 1
IDR11               equ       $00000561           ;*** IDR11 - Transmit Buffer 1 Identifier Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR11_ID15          equ       0                   ; Identifier Register Bit
IDR11_ID16          equ       1                   ; Identifier Register Bit
IDR11_ID17          equ       2                   ; Identifier Register Bit
IDR11_IDE           equ       3                   ; ID Extended
IDR11_SRR           equ       4                   ; Substitute Remote Request
IDR11_ID18          equ       5                   ; Identifier Register Bit
IDR11_ID19          equ       6                   ; Identifier Register Bit
IDR11_ID20          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR11_ID15         equ       %00000001
mIDR11_ID16         equ       %00000010
mIDR11_ID17         equ       %00000100
mIDR11_IDE          equ       %00001000
mIDR11_SRR          equ       %00010000
mIDR11_ID18         equ       %00100000
mIDR11_ID19         equ       %01000000
mIDR11_ID20         equ       %10000000


;*** IDR21 - Transmit Buffer 1 Identifier Register 2
IDR21               equ       $00000562           ;*** IDR21 - Transmit Buffer 1 Identifier Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR21_ID7           equ       0                   ; Identifier Register Bit
IDR21_ID8           equ       1                   ; Identifier Register Bit
IDR21_ID9           equ       2                   ; Identifier Register Bit
IDR21_ID10          equ       3                   ; Identifier Register Bit
IDR21_ID11          equ       4                   ; Identifier Register Bit
IDR21_ID12          equ       5                   ; Identifier Register Bit
IDR21_ID13          equ       6                   ; Identifier Register Bit
IDR21_ID14          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR21_ID7          equ       %00000001
mIDR21_ID8          equ       %00000010
mIDR21_ID9          equ       %00000100
mIDR21_ID10         equ       %00001000
mIDR21_ID11         equ       %00010000
mIDR21_ID12         equ       %00100000
mIDR21_ID13         equ       %01000000
mIDR21_ID14         equ       %10000000


;*** IDR31 - Transmit Buffer 1 Identifier Register 3
IDR31               equ       $00000563           ;*** IDR31 - Transmit Buffer 1 Identifier Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR31_RTR           equ       0                   ; Remote Transmission Request
IDR31_ID0           equ       1                   ; Identifier Register Bit
IDR31_ID1           equ       2                   ; Identifier Register Bit
IDR31_ID2           equ       3                   ; Identifier Register Bit
IDR31_ID3           equ       4                   ; Identifier Register Bit
IDR31_ID4           equ       5                   ; Identifier Register Bit
IDR31_ID5           equ       6                   ; Identifier Register Bit
IDR31_ID6           equ       7                   ; Identifier Register Bit
; bit position masks
mIDR31_RTR          equ       %00000001
mIDR31_ID0          equ       %00000010
mIDR31_ID1          equ       %00000100
mIDR31_ID2          equ       %00001000
mIDR31_ID3          equ       %00010000
mIDR31_ID4          equ       %00100000
mIDR31_ID5          equ       %01000000
mIDR31_ID6          equ       %10000000


;*** DSR01 - Transmit Buffer 1 Data Segment Register 0
DSR01               equ       $00000564           ;*** DSR01 - Transmit Buffer 1 Data Segment Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR01_DB0           equ       0                   ; Data Segment Register Bit
DSR01_DB1           equ       1                   ; Data Segment Register Bit
DSR01_DB2           equ       2                   ; Data Segment Register Bit
DSR01_DB3           equ       3                   ; Data Segment Register Bit
DSR01_DB4           equ       4                   ; Data Segment Register Bit
DSR01_DB5           equ       5                   ; Data Segment Register Bit
DSR01_DB6           equ       6                   ; Data Segment Register Bit
DSR01_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR01_DB0          equ       %00000001
mDSR01_DB1          equ       %00000010
mDSR01_DB2          equ       %00000100
mDSR01_DB3          equ       %00001000
mDSR01_DB4          equ       %00010000
mDSR01_DB5          equ       %00100000
mDSR01_DB6          equ       %01000000
mDSR01_DB7          equ       %10000000


;*** DSR11 - Transmit Buffer 1 Data Segment Register 1
DSR11               equ       $00000565           ;*** DSR11 - Transmit Buffer 1 Data Segment Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR11_DB0           equ       0                   ; Data Segment Register Bit
DSR11_DB1           equ       1                   ; Data Segment Register Bit
DSR11_DB2           equ       2                   ; Data Segment Register Bit
DSR11_DB3           equ       3                   ; Data Segment Register Bit
DSR11_DB4           equ       4                   ; Data Segment Register Bit
DSR11_DB5           equ       5                   ; Data Segment Register Bit
DSR11_DB6           equ       6                   ; Data Segment Register Bit
DSR11_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR11_DB0          equ       %00000001
mDSR11_DB1          equ       %00000010
mDSR11_DB2          equ       %00000100
mDSR11_DB3          equ       %00001000
mDSR11_DB4          equ       %00010000
mDSR11_DB5          equ       %00100000
mDSR11_DB6          equ       %01000000
mDSR11_DB7          equ       %10000000


;*** DSR21 - Transmit Buffer 1 Data Segment Register 2
DSR21               equ       $00000566           ;*** DSR21 - Transmit Buffer 1 Data Segment Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR21_DB0           equ       0                   ; Data Segment Register Bit
DSR21_DB1           equ       1                   ; Data Segment Register Bit
DSR21_DB2           equ       2                   ; Data Segment Register Bit
DSR21_DB3           equ       3                   ; Data Segment Register Bit
DSR21_DB4           equ       4                   ; Data Segment Register Bit
DSR21_DB5           equ       5                   ; Data Segment Register Bit
DSR21_DB6           equ       6                   ; Data Segment Register Bit
DSR21_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR21_DB0          equ       %00000001
mDSR21_DB1          equ       %00000010
mDSR21_DB2          equ       %00000100
mDSR21_DB3          equ       %00001000
mDSR21_DB4          equ       %00010000
mDSR21_DB5          equ       %00100000
mDSR21_DB6          equ       %01000000
mDSR21_DB7          equ       %10000000


;*** DSR31 - Transmit Buffer 1 Data Segment Register 3
DSR31               equ       $00000567           ;*** DSR31 - Transmit Buffer 1 Data Segment Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR31_DB0           equ       0                   ; Data Segment Register Bit
DSR31_DB1           equ       1                   ; Data Segment Register Bit
DSR31_DB2           equ       2                   ; Data Segment Register Bit
DSR31_DB3           equ       3                   ; Data Segment Register Bit
DSR31_DB4           equ       4                   ; Data Segment Register Bit
DSR31_DB5           equ       5                   ; Data Segment Register Bit
DSR31_DB6           equ       6                   ; Data Segment Register Bit
DSR31_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR31_DB0          equ       %00000001
mDSR31_DB1          equ       %00000010
mDSR31_DB2          equ       %00000100
mDSR31_DB3          equ       %00001000
mDSR31_DB4          equ       %00010000
mDSR31_DB5          equ       %00100000
mDSR31_DB6          equ       %01000000
mDSR31_DB7          equ       %10000000


;*** DSR41 - Transmit Buffer 1 Data Segment Register 4
DSR41               equ       $00000568           ;*** DSR41 - Transmit Buffer 1 Data Segment Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR41_DB0           equ       0                   ; Data Segment Register Bit
DSR41_DB1           equ       1                   ; Data Segment Register Bit
DSR41_DB2           equ       2                   ; Data Segment Register Bit
DSR41_DB3           equ       3                   ; Data Segment Register Bit
DSR41_DB4           equ       4                   ; Data Segment Register Bit
DSR41_DB5           equ       5                   ; Data Segment Register Bit
DSR41_DB6           equ       6                   ; Data Segment Register Bit
DSR41_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR41_DB0          equ       %00000001
mDSR41_DB1          equ       %00000010
mDSR41_DB2          equ       %00000100
mDSR41_DB3          equ       %00001000
mDSR41_DB4          equ       %00010000
mDSR41_DB5          equ       %00100000
mDSR41_DB6          equ       %01000000
mDSR41_DB7          equ       %10000000


;*** DSR51 - Transmit Buffer 1 Data Segment Register 5
DSR51               equ       $00000569           ;*** DSR51 - Transmit Buffer 1 Data Segment Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR51_DB0           equ       0                   ; Data Segment Register Bit
DSR51_DB1           equ       1                   ; Data Segment Register Bit
DSR51_DB2           equ       2                   ; Data Segment Register Bit
DSR51_DB3           equ       3                   ; Data Segment Register Bit
DSR51_DB4           equ       4                   ; Data Segment Register Bit
DSR51_DB5           equ       5                   ; Data Segment Register Bit
DSR51_DB6           equ       6                   ; Data Segment Register Bit
DSR51_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR51_DB0          equ       %00000001
mDSR51_DB1          equ       %00000010
mDSR51_DB2          equ       %00000100
mDSR51_DB3          equ       %00001000
mDSR51_DB4          equ       %00010000
mDSR51_DB5          equ       %00100000
mDSR51_DB6          equ       %01000000
mDSR51_DB7          equ       %10000000


;*** DSR61 - Transmit Buffer 1 Data Segment Register 6
DSR61               equ       $0000056A           ;*** DSR61 - Transmit Buffer 1 Data Segment Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR61_DB0           equ       0                   ; Data Segment Register Bit
DSR61_DB1           equ       1                   ; Data Segment Register Bit
DSR61_DB2           equ       2                   ; Data Segment Register Bit
DSR61_DB3           equ       3                   ; Data Segment Register Bit
DSR61_DB4           equ       4                   ; Data Segment Register Bit
DSR61_DB5           equ       5                   ; Data Segment Register Bit
DSR61_DB6           equ       6                   ; Data Segment Register Bit
DSR61_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR61_DB0          equ       %00000001
mDSR61_DB1          equ       %00000010
mDSR61_DB2          equ       %00000100
mDSR61_DB3          equ       %00001000
mDSR61_DB4          equ       %00010000
mDSR61_DB5          equ       %00100000
mDSR61_DB6          equ       %01000000
mDSR61_DB7          equ       %10000000


;*** DSR71 - Transmit Buffer 1 Data Segment Register 7
DSR71               equ       $0000056B           ;*** DSR71 - Transmit Buffer 1 Data Segment Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR71_DB0           equ       0                   ; Data Segment Register Bit
DSR71_DB1           equ       1                   ; Data Segment Register Bit
DSR71_DB2           equ       2                   ; Data Segment Register Bit
DSR71_DB3           equ       3                   ; Data Segment Register Bit
DSR71_DB4           equ       4                   ; Data Segment Register Bit
DSR71_DB5           equ       5                   ; Data Segment Register Bit
DSR71_DB6           equ       6                   ; Data Segment Register Bit
DSR71_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR71_DB0          equ       %00000001
mDSR71_DB1          equ       %00000010
mDSR71_DB2          equ       %00000100
mDSR71_DB3          equ       %00001000
mDSR71_DB4          equ       %00010000
mDSR71_DB5          equ       %00100000
mDSR71_DB6          equ       %01000000
mDSR71_DB7          equ       %10000000


;*** DLR1 - Transmit Buffer 1 Data Length Register
DLR1                equ       $0000056C           ;*** DLR1 - Transmit Buffer 1 Data Length Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DLR1_DLC0           equ       0                   ; Data Length Code Bit
DLR1_DLC1           equ       1                   ; Data Length Code Bit
DLR1_DLC2           equ       2                   ; Data Length Code Bit
DLR1_DLC3           equ       3                   ; Data Length Code Bit
; bit position masks
mDLR1_DLC0          equ       %00000001
mDLR1_DLC1          equ       %00000010
mDLR1_DLC2          equ       %00000100
mDLR1_DLC3          equ       %00001000


;*** TBPR1 - Transmit Buffer 1 Priority Register
TBPR1               equ       $0000056D           ;*** TBPR1 - Transmit Buffer 1 Priority Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBPR1_PRIO0         equ       0                   ; Local Priority
TBPR1_PRIO1         equ       1                   ; Local Priority
TBPR1_PRIO2         equ       2                   ; Local Priority
TBPR1_PRIO3         equ       3                   ; Local Priority
TBPR1_PRIO4         equ       4                   ; Local Priority
TBPR1_PRIO5         equ       5                   ; Local Priority
TBPR1_PRIO6         equ       6                   ; Local Priority
TBPR1_PRIO7         equ       7                   ; Local Priority
; bit position masks
mTBPR1_PRIO0        equ       %00000001
mTBPR1_PRIO1        equ       %00000010
mTBPR1_PRIO2        equ       %00000100
mTBPR1_PRIO3        equ       %00001000
mTBPR1_PRIO4        equ       %00010000
mTBPR1_PRIO5        equ       %00100000
mTBPR1_PRIO6        equ       %01000000
mTBPR1_PRIO7        equ       %10000000


;*** IDR2 - Transmit Buffer 2 Identifier Register
IDR2                equ       $00000570           ;*** IDR2 - Transmit Buffer 2 Identifier Register


;*** IDR02 - Transmit Buffer 2 Identifier Register 0
IDR02               equ       $00000570           ;*** IDR02 - Transmit Buffer 2 Identifier Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR02_ID21          equ       0                   ; Identifier Register Bit
IDR02_ID22          equ       1                   ; Identifier Register Bit
IDR02_ID23          equ       2                   ; Identifier Register Bit
IDR02_ID24          equ       3                   ; Identifier Register Bit
IDR02_ID25          equ       4                   ; Identifier Register Bit
IDR02_ID26          equ       5                   ; Identifier Register Bit
IDR02_ID27          equ       6                   ; Identifier Register Bit
IDR02_ID28          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR02_ID21         equ       %00000001
mIDR02_ID22         equ       %00000010
mIDR02_ID23         equ       %00000100
mIDR02_ID24         equ       %00001000
mIDR02_ID25         equ       %00010000
mIDR02_ID26         equ       %00100000
mIDR02_ID27         equ       %01000000
mIDR02_ID28         equ       %10000000


;*** IDR12 - Transmit Buffer 2 Identifier Register 1
IDR12               equ       $00000571           ;*** IDR12 - Transmit Buffer 2 Identifier Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR12_ID15          equ       0                   ; Identifier Register Bit
IDR12_ID16          equ       1                   ; Identifier Register Bit
IDR12_ID17          equ       2                   ; Identifier Register Bit
IDR12_IDE           equ       3                   ; ID Extended
IDR12_SRR           equ       4                   ; Substitute Remote Request
IDR12_ID18          equ       5                   ; Identifier Register Bit
IDR12_ID19          equ       6                   ; Identifier Register Bit
IDR12_ID20          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR12_ID15         equ       %00000001
mIDR12_ID16         equ       %00000010
mIDR12_ID17         equ       %00000100
mIDR12_IDE          equ       %00001000
mIDR12_SRR          equ       %00010000
mIDR12_ID18         equ       %00100000
mIDR12_ID19         equ       %01000000
mIDR12_ID20         equ       %10000000


;*** IDR22 - Transmit Buffer 2 Identifier Register 2
IDR22               equ       $00000572           ;*** IDR22 - Transmit Buffer 2 Identifier Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR22_ID7           equ       0                   ; Identifier Register Bit
IDR22_ID8           equ       1                   ; Identifier Register Bit
IDR22_ID9           equ       2                   ; Identifier Register Bit
IDR22_ID10          equ       3                   ; Identifier Register Bit
IDR22_ID11          equ       4                   ; Identifier Register Bit
IDR22_ID12          equ       5                   ; Identifier Register Bit
IDR22_ID13          equ       6                   ; Identifier Register Bit
IDR22_ID14          equ       7                   ; Identifier Register Bit
; bit position masks
mIDR22_ID7          equ       %00000001
mIDR22_ID8          equ       %00000010
mIDR22_ID9          equ       %00000100
mIDR22_ID10         equ       %00001000
mIDR22_ID11         equ       %00010000
mIDR22_ID12         equ       %00100000
mIDR22_ID13         equ       %01000000
mIDR22_ID14         equ       %10000000


;*** IDR32 - Transmit Buffer 2 Identifier Register 3
IDR32               equ       $00000573           ;*** IDR32 - Transmit Buffer 2 Identifier Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDR32_RTR           equ       0                   ; Remote Transmission Request
IDR32_ID0           equ       1                   ; Identifier Register Bit
IDR32_ID1           equ       2                   ; Identifier Register Bit
IDR32_ID2           equ       3                   ; Identifier Register Bit
IDR32_ID3           equ       4                   ; Identifier Register Bit
IDR32_ID4           equ       5                   ; Identifier Register Bit
IDR32_ID5           equ       6                   ; Identifier Register Bit
IDR32_ID6           equ       7                   ; Identifier Register Bit
; bit position masks
mIDR32_RTR          equ       %00000001
mIDR32_ID0          equ       %00000010
mIDR32_ID1          equ       %00000100
mIDR32_ID2          equ       %00001000
mIDR32_ID3          equ       %00010000
mIDR32_ID4          equ       %00100000
mIDR32_ID5          equ       %01000000
mIDR32_ID6          equ       %10000000


;*** DSR02 - Transmit Buffer 2 Data Segment Register 0
DSR02               equ       $00000574           ;*** DSR02 - Transmit Buffer 2 Data Segment Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR02_DB0           equ       0                   ; Data Segment Register Bit
DSR02_DB1           equ       1                   ; Data Segment Register Bit
DSR02_DB2           equ       2                   ; Data Segment Register Bit
DSR02_DB3           equ       3                   ; Data Segment Register Bit
DSR02_DB4           equ       4                   ; Data Segment Register Bit
DSR02_DB5           equ       5                   ; Data Segment Register Bit
DSR02_DB6           equ       6                   ; Data Segment Register Bit
DSR02_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR02_DB0          equ       %00000001
mDSR02_DB1          equ       %00000010
mDSR02_DB2          equ       %00000100
mDSR02_DB3          equ       %00001000
mDSR02_DB4          equ       %00010000
mDSR02_DB5          equ       %00100000
mDSR02_DB6          equ       %01000000
mDSR02_DB7          equ       %10000000


;*** DSR12 - Transmit Buffer 2 Data Segment Register 1
DSR12               equ       $00000575           ;*** DSR12 - Transmit Buffer 2 Data Segment Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR12_DB0           equ       0                   ; Data Segment Register Bit
DSR12_DB1           equ       1                   ; Data Segment Register Bit
DSR12_DB2           equ       2                   ; Data Segment Register Bit
DSR12_DB3           equ       3                   ; Data Segment Register Bit
DSR12_DB4           equ       4                   ; Data Segment Register Bit
DSR12_DB5           equ       5                   ; Data Segment Register Bit
DSR12_DB6           equ       6                   ; Data Segment Register Bit
DSR12_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR12_DB0          equ       %00000001
mDSR12_DB1          equ       %00000010
mDSR12_DB2          equ       %00000100
mDSR12_DB3          equ       %00001000
mDSR12_DB4          equ       %00010000
mDSR12_DB5          equ       %00100000
mDSR12_DB6          equ       %01000000
mDSR12_DB7          equ       %10000000


;*** DSR22 - Transmit Buffer 2 Data Segment Register 2
DSR22               equ       $00000576           ;*** DSR22 - Transmit Buffer 2 Data Segment Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR22_DB0           equ       0                   ; Data Segment Register Bit
DSR22_DB1           equ       1                   ; Data Segment Register Bit
DSR22_DB2           equ       2                   ; Data Segment Register Bit
DSR22_DB3           equ       3                   ; Data Segment Register Bit
DSR22_DB4           equ       4                   ; Data Segment Register Bit
DSR22_DB5           equ       5                   ; Data Segment Register Bit
DSR22_DB6           equ       6                   ; Data Segment Register Bit
DSR22_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR22_DB0          equ       %00000001
mDSR22_DB1          equ       %00000010
mDSR22_DB2          equ       %00000100
mDSR22_DB3          equ       %00001000
mDSR22_DB4          equ       %00010000
mDSR22_DB5          equ       %00100000
mDSR22_DB6          equ       %01000000
mDSR22_DB7          equ       %10000000


;*** DSR32 - Transmit Buffer 2 Data Segment Register 3
DSR32               equ       $00000577           ;*** DSR32 - Transmit Buffer 2 Data Segment Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR32_DB0           equ       0                   ; Data Segment Register Bit
DSR32_DB1           equ       1                   ; Data Segment Register Bit
DSR32_DB2           equ       2                   ; Data Segment Register Bit
DSR32_DB3           equ       3                   ; Data Segment Register Bit
DSR32_DB4           equ       4                   ; Data Segment Register Bit
DSR32_DB5           equ       5                   ; Data Segment Register Bit
DSR32_DB6           equ       6                   ; Data Segment Register Bit
DSR32_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR32_DB0          equ       %00000001
mDSR32_DB1          equ       %00000010
mDSR32_DB2          equ       %00000100
mDSR32_DB3          equ       %00001000
mDSR32_DB4          equ       %00010000
mDSR32_DB5          equ       %00100000
mDSR32_DB6          equ       %01000000
mDSR32_DB7          equ       %10000000


;*** DSR42 - Transmit Buffer 2 Data Segment Register 4
DSR42               equ       $00000578           ;*** DSR42 - Transmit Buffer 2 Data Segment Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR42_DB0           equ       0                   ; Data Segment Register Bit
DSR42_DB1           equ       1                   ; Data Segment Register Bit
DSR42_DB2           equ       2                   ; Data Segment Register Bit
DSR42_DB3           equ       3                   ; Data Segment Register Bit
DSR42_DB4           equ       4                   ; Data Segment Register Bit
DSR42_DB5           equ       5                   ; Data Segment Register Bit
DSR42_DB6           equ       6                   ; Data Segment Register Bit
DSR42_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR42_DB0          equ       %00000001
mDSR42_DB1          equ       %00000010
mDSR42_DB2          equ       %00000100
mDSR42_DB3          equ       %00001000
mDSR42_DB4          equ       %00010000
mDSR42_DB5          equ       %00100000
mDSR42_DB6          equ       %01000000
mDSR42_DB7          equ       %10000000


;*** DSR52 - Transmit Buffer 2 Data Segment Register 5
DSR52               equ       $00000579           ;*** DSR52 - Transmit Buffer 2 Data Segment Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR52_DB0           equ       0                   ; Data Segment Register Bit
DSR52_DB1           equ       1                   ; Data Segment Register Bit
DSR52_DB2           equ       2                   ; Data Segment Register Bit
DSR52_DB3           equ       3                   ; Data Segment Register Bit
DSR52_DB4           equ       4                   ; Data Segment Register Bit
DSR52_DB5           equ       5                   ; Data Segment Register Bit
DSR52_DB6           equ       6                   ; Data Segment Register Bit
DSR52_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR52_DB0          equ       %00000001
mDSR52_DB1          equ       %00000010
mDSR52_DB2          equ       %00000100
mDSR52_DB3          equ       %00001000
mDSR52_DB4          equ       %00010000
mDSR52_DB5          equ       %00100000
mDSR52_DB6          equ       %01000000
mDSR52_DB7          equ       %10000000


;*** DSR62 - Transmit Buffer 2 Data Segment Register 6
DSR62               equ       $0000057A           ;*** DSR62 - Transmit Buffer 2 Data Segment Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR62_DB0           equ       0                   ; Data Segment Register Bit
DSR62_DB1           equ       1                   ; Data Segment Register Bit
DSR62_DB2           equ       2                   ; Data Segment Register Bit
DSR62_DB3           equ       3                   ; Data Segment Register Bit
DSR62_DB4           equ       4                   ; Data Segment Register Bit
DSR62_DB5           equ       5                   ; Data Segment Register Bit
DSR62_DB6           equ       6                   ; Data Segment Register Bit
DSR62_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR62_DB0          equ       %00000001
mDSR62_DB1          equ       %00000010
mDSR62_DB2          equ       %00000100
mDSR62_DB3          equ       %00001000
mDSR62_DB4          equ       %00010000
mDSR62_DB5          equ       %00100000
mDSR62_DB6          equ       %01000000
mDSR62_DB7          equ       %10000000


;*** DSR72 - Transmit Buffer 2 Data Segment Register 7
DSR72               equ       $0000057B           ;*** DSR72 - Transmit Buffer 2 Data Segment Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DSR72_DB0           equ       0                   ; Data Segment Register Bit
DSR72_DB1           equ       1                   ; Data Segment Register Bit
DSR72_DB2           equ       2                   ; Data Segment Register Bit
DSR72_DB3           equ       3                   ; Data Segment Register Bit
DSR72_DB4           equ       4                   ; Data Segment Register Bit
DSR72_DB5           equ       5                   ; Data Segment Register Bit
DSR72_DB6           equ       6                   ; Data Segment Register Bit
DSR72_DB7           equ       7                   ; Data Segment Register Bit
; bit position masks
mDSR72_DB0          equ       %00000001
mDSR72_DB1          equ       %00000010
mDSR72_DB2          equ       %00000100
mDSR72_DB3          equ       %00001000
mDSR72_DB4          equ       %00010000
mDSR72_DB5          equ       %00100000
mDSR72_DB6          equ       %01000000
mDSR72_DB7          equ       %10000000


;*** DLR2 - Transmit Buffer 2 Data Length Register
DLR2                equ       $0000057C           ;*** DLR2 - Transmit Buffer 2 Data Length Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DLR2_DLC0           equ       0                   ; Data Length Code Bit
DLR2_DLC1           equ       1                   ; Data Length Code Bit
DLR2_DLC2           equ       2                   ; Data Length Code Bit
DLR2_DLC3           equ       3                   ; Data Length Code Bit
; bit position masks
mDLR2_DLC0          equ       %00000001
mDLR2_DLC1          equ       %00000010
mDLR2_DLC2          equ       %00000100
mDLR2_DLC3          equ       %00001000


;*** TBPR2 - Transmit Buffer 2 Priority Register
TBPR2               equ       $0000057D           ;*** TBPR2 - Transmit Buffer 2 Priority Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBPR2_PRIO0         equ       0                   ; Local Priority
TBPR2_PRIO1         equ       1                   ; Local Priority
TBPR2_PRIO2         equ       2                   ; Local Priority
TBPR2_PRIO3         equ       3                   ; Local Priority
TBPR2_PRIO4         equ       4                   ; Local Priority
TBPR2_PRIO5         equ       5                   ; Local Priority
TBPR2_PRIO6         equ       6                   ; Local Priority
TBPR2_PRIO7         equ       7                   ; Local Priority
; bit position masks
mTBPR2_PRIO0        equ       %00000001
mTBPR2_PRIO1        equ       %00000010
mTBPR2_PRIO2        equ       %00000100
mTBPR2_PRIO3        equ       %00001000
mTBPR2_PRIO4        equ       %00010000
mTBPR2_PRIO5        equ       %00100000
mTBPR2_PRIO6        equ       %01000000
mTBPR2_PRIO7        equ       %10000000


;*** SBSR - SIM Break Status Register
SBSR                equ       $0000FE00           ;*** SBSR - SIM Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBSR_BW             equ       1                   ; SIM Break Stop/Wait
; bit position masks
mSBSR_BW            equ       %00000010


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


;*** CONFIG2 - Configuration Register
CONFIG2             equ       $0000FE09           ;*** CONFIG2 - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_AZ32A       equ       3                   ; Device indicator
CONFIG2_EEMONSEC    equ       4                   ; EEPROM Read Protection in Monitor Mode Bit
CONFIG2_EEDIVCLK    equ       7                   ; EEPROM Timebase Divider Clock select bit
; bit position masks
mCONFIG2_AZ32A      equ       %00001000
mCONFIG2_EEMONSEC   equ       %00010000
mCONFIG2_EEDIVCLK   equ       %10000000


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
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LVIOUT       equ       %10000000


;*** EEDIVHNVR - EEDIV Hi Non-volatile Register
EEDIVHNVR           equ       $0000FE10           ;*** EEDIVHNVR - EEDIV Hi Non-volatile Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EEDIVHNVR_EEDIV8    equ       0                   ; EEPROM timebase prescaler
EEDIVHNVR_EEDIV9    equ       1                   ; EEPROM timebase prescaler
EEDIVHNVR_EEDIV10   equ       2                   ; EEPROM timebase prescaler
EEDIVHNVR_EEDIVSECD equ       7                   ; EEPROM Divider Security Disable
; bit position masks
mEEDIVHNVR_EEDIV8   equ       %00000001
mEEDIVHNVR_EEDIV9   equ       %00000010
mEEDIVHNVR_EEDIV10  equ       %00000100
mEEDIVHNVR_EEDIVSECD equ       %10000000


;*** EEDIVLNVR - EEDIV Lo Non-volatile Register
EEDIVLNVR           equ       $0000FE11           ;*** EEDIVLNVR - EEDIV Lo Non-volatile Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EEDIVLNVR_EEDIV0    equ       0                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV1    equ       1                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV2    equ       2                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV3    equ       3                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV4    equ       4                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV5    equ       5                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV6    equ       6                   ; EEPROM timebase prescaler
EEDIVLNVR_EEDIV7    equ       7                   ; EEPROM timebase prescaler
; bit position masks
mEEDIVLNVR_EEDIV0   equ       %00000001
mEEDIVLNVR_EEDIV1   equ       %00000010
mEEDIVLNVR_EEDIV2   equ       %00000100
mEEDIVLNVR_EEDIV3   equ       %00001000
mEEDIVLNVR_EEDIV4   equ       %00010000
mEEDIVLNVR_EEDIV5   equ       %00100000
mEEDIVLNVR_EEDIV6   equ       %01000000
mEEDIVLNVR_EEDIV7   equ       %10000000


;*** EEDIVH - EEDIV Divider High Register
EEDIVH              equ       $0000FE1A           ;*** EEDIVH - EEDIV Divider High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EEDIVH_EEDIV8       equ       0                   ; EEPROM timebase prescaler
EEDIVH_EEDIV9       equ       1                   ; EEPROM timebase prescaler
EEDIVH_EEDIV10      equ       2                   ; EEPROM timebase prescaler
EEDIVH_EEDIVSECD    equ       7                   ; EEPROM Divider Security Disable
; bit position masks
mEEDIVH_EEDIV8      equ       %00000001
mEEDIVH_EEDIV9      equ       %00000010
mEEDIVH_EEDIV10     equ       %00000100
mEEDIVH_EEDIVSECD   equ       %10000000


;*** EEDIVL - EEDIV Divider Low Register
EEDIVL              equ       $0000FE1B           ;*** EEDIVL - EEDIV Divider Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EEDIVL_EEDIV0       equ       0                   ; EEPROM timebase prescaler
EEDIVL_EEDIV1       equ       1                   ; EEPROM timebase prescaler
EEDIVL_EEDIV2       equ       2                   ; EEPROM timebase prescaler
EEDIVL_EEDIV3       equ       3                   ; EEPROM timebase prescaler
EEDIVL_EEDIV4       equ       4                   ; EEPROM timebase prescaler
EEDIVL_EEDIV5       equ       5                   ; EEPROM timebase prescaler
EEDIVL_EEDIV6       equ       6                   ; EEPROM timebase prescaler
EEDIVL_EEDIV7       equ       7                   ; EEPROM timebase prescaler
; bit position masks
mEEDIVL_EEDIV0      equ       %00000001
mEEDIVL_EEDIV1      equ       %00000010
mEEDIVL_EEDIV2      equ       %00000100
mEEDIVL_EEDIV3      equ       %00001000
mEEDIVL_EEDIV4      equ       %00010000
mEEDIVL_EEDIV5      equ       %00100000
mEEDIVL_EEDIV6      equ       %01000000
mEEDIVL_EEDIV7      equ       %10000000


;*** EENVR - EEPROM1 Non-volatile Register
EENVR               equ       $0000FE1C           ;*** EENVR - EEPROM1 Non-volatile Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EENVR_EEBP0         equ       0                   ; EEPROM Block Protection Bit
EENVR_EEBP1         equ       1                   ; EEPROM Block Protection Bit
EENVR_EEBP2         equ       2                   ; EEPROM Block Protection Bit
EENVR_EEBP3         equ       3                   ; EEPROM Block Protection Bit
EENVR_EEPRTCT       equ       4                   ; EEPROM Protection
; bit position masks
mEENVR_EEBP0        equ       %00000001
mEENVR_EEBP1        equ       %00000010
mEENVR_EEBP2        equ       %00000100
mEENVR_EEBP3        equ       %00001000
mEENVR_EEPRTCT      equ       %00010000


;*** EECR - EEPROM1 Control Register
EECR                equ       $0000FE1D           ;*** EECR - EEPROM1 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EECR_EEPGM          equ       0                   ; EEPROM Program/Erase Enable
EECR_AUTO           equ       1                   ; Automatic termination of program/erase cycle
EECR_EELAT          equ       2                   ; EEPROM Latch Control
EECR_EERAS0         equ       3                   ; Erase Bit
EECR_EERAS1         equ       4                   ; Erase Bit
EECR_EEOFF          equ       5                   ; EEPROM Power Down
; bit position masks
mEECR_EEPGM         equ       %00000001
mEECR_AUTO          equ       %00000010
mEECR_EELAT         equ       %00000100
mEECR_EERAS0        equ       %00001000
mEECR_EERAS1        equ       %00010000
mEECR_EEOFF         equ       %00100000


;*** EEACR - EEPROM1 Array Control Register
EEACR               equ       $0000FE1F           ;*** EEACR - EEPROM1 Array Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EEACR_EEBP0         equ       0                   ; EEPROM Block Protection Bit
EEACR_EEBP1         equ       1                   ; EEPROM Block Protection Bit
EEACR_EEBP2         equ       2                   ; EEPROM Block Protection Bit
EEACR_EEBP3         equ       3                   ; EEPROM Block Protection Bit
EEACR_EEPRTCT       equ       4                   ; EEPROM Protection
; bit position masks
mEEACR_EEBP0        equ       %00000001
mEEACR_EEBP1        equ       %00000010
mEEACR_EEBP2        equ       %00000100
mEEACR_EEBP3        equ       %00001000
mEEACR_EEPRTCT      equ       %00010000


;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FF80           ;*** FLBPR - FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR0          equ       0                   ; Block Protect Bit 0
FLBPR_BPR1          equ       1                   ; Block Protect Bit 1
FLBPR_BPR2          equ       2                   ; Block Protect Bit 2
FLBPR_BPR3          equ       3                   ; Block Protect Bit 3
FLBPR_BPR4          equ       4                   ; Block Protect Bit 4
FLBPR_BPR5          equ       5                   ; Block Protect Bit 5
FLBPR_BPR6          equ       6                   ; Block Protect Bit 6
FLBPR_BPR7          equ       7                   ; Block Protect Bit 7
; bit position masks
mFLBPR_BPR0         equ       %00000001
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000
mFLBPR_BPR4         equ       %00010000
mFLBPR_BPR5         equ       %00100000
mFLBPR_BPR6         equ       %01000000
mFLBPR_BPR7         equ       %10000000


;*** FLCR - FLASH Control Register
FLCR                equ       $0000FF88           ;*** FLCR - FLASH Control Register
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
; symbols for compatibility with ROM version of the AZ32A
 #ifndef __GENERATE_APPLICATION__
 #endif
MORA                equ       CONFIG1
MORA_COPD           equ       CONFIG1_COPD
MORA_COPRS          equ       CONFIG1_COPRS
MORA_LVIPWR         equ       CONFIG1_LVIPWR
MORA_LVIRST         equ       CONFIG1_LVIRST
MORA_LVISTOP        equ       CONFIG1_LVISTOP
MORA_SSREC          equ       CONFIG1_SSREC
MORA_STOP           equ       CONFIG1_STOP
MORB                equ       CONFIG2
MORB_AZ32A          equ       CONFIG2_AZ32A
MORB_EEDIVCLK       equ       CONFIG2_EEDIVCLK
MORB_EEMONSEC       equ       CONFIG2_EEMONSEC
PSC_PIE             equ       PSC_POIE
mMORA_COPD          equ       mCONFIG1_COPD
mMORA_COPRS         equ       mCONFIG1_COPRS
mMORA_LVIPWR        equ       mCONFIG1_LVIPWR
mMORA_LVIRST        equ       mCONFIG1_LVIRST
mMORA_LVISTOP       equ       mCONFIG1_LVISTOP
 #ifndef __GENERATE_APPLICATION__
 #endif
mMORA_SSREC         equ       mCONFIG1_SSREC
mMORA_STOP          equ       mCONFIG1_STOP
mMORB_AZ32A         equ       mCONFIG2_AZ32A
mMORB_EEDIVCLK      equ       mCONFIG2_EEDIVCLK
mMORB_EEMONSEC      equ       mCONFIG2_EEMONSEC
mPSC_PIE            equ       mPSC_POIE
INT_IRQ             equ       INT_IRQ1

; EOF
