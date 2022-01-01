;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908GZ32_64, version 2.87.094 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908gz32.inc
;     Processor : MC68HC908GZ32CFU
;     FileFormat: V2.28
;     DataSheet : MC68HC908GZ60 Rev. 6.0 04/2007
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
;      - 07.12.2005, V2.87.067:
;              - Renamed bits SCPSC_PSx ==> SCPSC_PDSx. REASON: Changes in data sheet (from Rev. 0 6/2003 to Rev. 2.0 06/2005)
;      - 24.03.2006, V2.87.074:
;              - Renamed register SBSR ==> BSR. REASON: Bug-fix (#3149 in Issue Manager)
;      - 18.12.2007, V2.87.092:
;              - Added bit INT1_IF6. REASON: Bug-fix (#4090 in Issue Manager).
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
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000043F
RAM1                equ       $00000580
RAM1_END            equ       $0000077F
;
INT_TIM2CH5         equ       $0000FFCC
INT_TIM2CH4         equ       $0000FFCE
INT_TIM2CH3         equ       $0000FFD0
INT_TIM2CH2         equ       $0000FFD2
INT_MSCANTransmit   equ       $0000FFD4
INT_MSCANReceive    equ       $0000FFD6
INT_MSCANError      equ       $0000FFD8
INT_MSCANWakeup     equ       $0000FFDA
INT_TBM             equ       $0000FFDC
INT_ADC             equ       $0000FFDE
INT_KBD             equ       $0000FFE0
INT_SCITransmit     equ       $0000FFE2
INT_SCIReceive      equ       $0000FFE4
INT_SCIError        equ       $0000FFE6
INT_SPITransmit     equ       $0000FFE8
INT_SPIReceive      equ       $0000FFEA
INT_TIM2Ovr         equ       $0000FFEC
INT_TIM2CH1         equ       $0000FFEE
INT_TIM2CH0         equ       $0000FFF0
INT_TIM1Ovr         equ       $0000FFF2
INT_TIM1CH1         equ       $0000FFF4
INT_TIM1CH0         equ       $0000FFF6
INT_PLL             equ       $0000FFF8
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
; bit position masks
mPTE_PTE0           equ       %00000001
mPTE_PTE1           equ       %00000010
mPTE_PTE2           equ       %00000100
mPTE_PTE3           equ       %00001000
mPTE_PTE4           equ       %00010000
mPTE_PTE5           equ       %00100000

;*** SCPSC - ESCI Prescaler Register
SCPSC               equ       $00000009           ;*** SCPSC - ESCI Prescaler Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCPSC_PSSB0         equ       0                   ; Clock Insertion Select Bit 0
SCPSC_PSSB1         equ       1                   ; Clock Insertion Select Bit 1
SCPSC_PSSB2         equ       2                   ; Clock Insertion Select Bit 2
SCPSC_PSSB3         equ       3                   ; Clock Insertion Select Bit 3
SCPSC_PSSB4         equ       4                   ; Clock Insertion Select Bit 4
SCPSC_PDS0          equ       5                   ; Prescaler Divisor Select Bit 0
SCPSC_PDS1          equ       6                   ; Prescaler Divisor Select Bit 1
SCPSC_PDS2          equ       7                   ; Prescaler Divisor Select Bit 2
; bit position masks
mSCPSC_PSSB0        equ       %00000001
mSCPSC_PSSB1        equ       %00000010
mSCPSC_PSSB2        equ       %00000100
mSCPSC_PSSB3        equ       %00001000
mSCPSC_PSSB4        equ       %00010000
mSCPSC_PDS0         equ       %00100000
mSCPSC_PDS1         equ       %01000000
mSCPSC_PDS2         equ       %10000000

;*** SCIACTL - ESCI Arbiter Control Register
SCIACTL             equ       $0000000A           ;*** SCIACTL - ESCI Arbiter Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIACTL_ARD8        equ       0                   ; Arbiter Counter MSB
SCIACTL_AOVFL       equ       1                   ; Arbiter Counter Overflow Bit
SCIACTL_ARUN        equ       2                   ; Arbiter Counter Running Flag
SCIACTL_AFIN        equ       3                   ; Arbiter Bit Time Measurement Finish Flag
SCIACTL_ACLK        equ       4                   ; Arbiter Counter Clock Select Bit
SCIACTL_AM0         equ       5                   ; Arbiter Mode Select Bit 0
SCIACTL_ALOST       equ       6                   ; Arbitration Lost Flag
SCIACTL_AM1         equ       7                   ; Arbiter Mode Select Bit 1
; bit position masks
mSCIACTL_ARD8       equ       %00000001
mSCIACTL_AOVFL      equ       %00000010
mSCIACTL_ARUN       equ       %00000100
mSCIACTL_AFIN       equ       %00001000
mSCIACTL_ACLK       equ       %00010000
mSCIACTL_AM0        equ       %00100000
mSCIACTL_ALOST      equ       %01000000
mSCIACTL_AM1        equ       %10000000

;*** SCIADAT - ESCI Arbiter Data Register
SCIADAT             equ       $0000000B           ;*** SCIADAT - ESCI Arbiter Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIADAT_ARD0        equ       0                   ; Arbiter Least Significant Counter Bit 0
SCIADAT_ARD1        equ       1                   ; Arbiter Least Significant Counter Bit 1
SCIADAT_ARD2        equ       2                   ; Arbiter Least Significant Counter Bit 2
SCIADAT_ARD3        equ       3                   ; Arbiter Least Significant Counter Bit 3
SCIADAT_ARD4        equ       4                   ; Arbiter Least Significant Counter Bit 4
SCIADAT_ARD5        equ       5                   ; Arbiter Least Significant Counter Bit 5
SCIADAT_ARD6        equ       6                   ; Arbiter Least Significant Counter Bit 6
SCIADAT_ARD7        equ       7                   ; Arbiter Least Significant Counter Bit 7
; bit position masks
mSCIADAT_ARD0       equ       %00000001
mSCIADAT_ARD1       equ       %00000010
mSCIADAT_ARD2       equ       %00000100
mSCIADAT_ARD3       equ       %00001000
mSCIADAT_ARD4       equ       %00010000
mSCIADAT_ARD5       equ       %00100000
mSCIADAT_ARD6       equ       %01000000
mSCIADAT_ARD7       equ       %10000000

;*** DDRE - Data Direction Register E
DDRE                equ       $0000000C           ;*** DDRE - Data Direction Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRE_DDRE0          equ       0                   ; Data Direction Register E Bit 0
DDRE_DDRE1          equ       1                   ; Data Direction Register E Bit 1
DDRE_DDRE2          equ       2                   ; Data Direction Register E Bit 2
DDRE_DDRE3          equ       3                   ; Data Direction Register E Bit 3
DDRE_DDRE4          equ       4                   ; Data Direction Register E Bit 4
DDRE_DDRE5          equ       5                   ; Data Direction Register E Bit 5
; bit position masks
mDDRE_DDRE0         equ       %00000001
mDDRE_DDRE1         equ       %00000010
mDDRE_DDRE2         equ       %00000100
mDDRE_DDRE3         equ       %00001000
mDDRE_DDRE4         equ       %00010000
mDDRE_DDRE5         equ       %00100000

;*** PTAPUE - Port A Input Pullup Enable Register
PTAPUE              equ       $0000000D           ;*** PTAPUE - Port A Input Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUE_PTAPUE0      equ       0                   ; Port A Input Pullup Enable Bit 0
PTAPUE_PTAPUE1      equ       1                   ; Port A Input Pullup Enable Bit 1
PTAPUE_PTAPUE2      equ       2                   ; Port A Input Pullup Enable Bit 2
PTAPUE_PTAPUE3      equ       3                   ; Port A Input Pullup Enable Bit 3
PTAPUE_PTAPUE4      equ       4                   ; Port A Input Pullup Enable Bit 4
PTAPUE_PTAPUE5      equ       5                   ; Port A Input Pullup Enable Bit 5
PTAPUE_PTAPUE6      equ       6                   ; Port A Input Pullup Enable Bit 6
PTAPUE_PTAPUE7      equ       7                   ; Port A Input Pullup Enable Bit 7
; bit position masks
mPTAPUE_PTAPUE0     equ       %00000001
mPTAPUE_PTAPUE1     equ       %00000010
mPTAPUE_PTAPUE2     equ       %00000100
mPTAPUE_PTAPUE3     equ       %00001000
mPTAPUE_PTAPUE4     equ       %00010000
mPTAPUE_PTAPUE5     equ       %00100000
mPTAPUE_PTAPUE6     equ       %01000000
mPTAPUE_PTAPUE7     equ       %10000000

;*** PTCPUE - Port C Input Pullup Enable Register
PTCPUE              equ       $0000000E           ;*** PTCPUE - Port C Input Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPUE_PTCPUE0      equ       0                   ; Port C Input Pullup Enable Bit 0
PTCPUE_PTCPUE1      equ       1                   ; Port C Input Pullup Enable Bit 1
PTCPUE_PTCPUE2      equ       2                   ; Port C Input Pullup Enable Bit 2
PTCPUE_PTCPUE3      equ       3                   ; Port C Input Pullup Enable Bit 3
PTCPUE_PTCPUE4      equ       4                   ; Port C Input Pullup Enable Bit 4
PTCPUE_PTCPUE5      equ       5                   ; Port C Input Pullup Enable Bit 5
PTCPUE_PTCPUE6      equ       6                   ; Port C Input Pullup Enable Bit 6
; bit position masks
mPTCPUE_PTCPUE0     equ       %00000001
mPTCPUE_PTCPUE1     equ       %00000010
mPTCPUE_PTCPUE2     equ       %00000100
mPTCPUE_PTCPUE3     equ       %00001000
mPTCPUE_PTCPUE4     equ       %00010000
mPTCPUE_PTCPUE5     equ       %00100000
mPTCPUE_PTCPUE6     equ       %01000000

;*** PTDPUE - Port D Input Pullup Enable Register
PTDPUE              equ       $0000000F           ;*** PTDPUE - Port D Input Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPUE_PTDPUE0      equ       0                   ; Port D Input Pullup Enable Bit 0
PTDPUE_PTDPUE1      equ       1                   ; Port D Input Pullup Enable Bit 1
PTDPUE_PTDPUE2      equ       2                   ; Port D Input Pullup Enable Bit 2
PTDPUE_PTDPUE3      equ       3                   ; Port D Input Pullup Enable Bit 3
PTDPUE_PTDPUE4      equ       4                   ; Port D Input Pullup Enable Bit 4
PTDPUE_PTDPUE5      equ       5                   ; Port D Input Pullup Enable Bit 5
PTDPUE_PTDPUE6      equ       6                   ; Port D Input Pullup Enable Bit 6
PTDPUE_PTDPUE7      equ       7                   ; Port D Input Pullup Enable Bit 7
; bit position masks
mPTDPUE_PTDPUE0     equ       %00000001
mPTDPUE_PTDPUE1     equ       %00000010
mPTDPUE_PTDPUE2     equ       %00000100
mPTDPUE_PTDPUE3     equ       %00001000
mPTDPUE_PTDPUE4     equ       %00010000
mPTDPUE_PTDPUE5     equ       %00100000
mPTDPUE_PTDPUE6     equ       %01000000
mPTDPUE_PTDPUE7     equ       %10000000

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

;*** SCC1 - ESCI Control Register 1
SCC1                equ       $00000013           ;*** SCC1 - ESCI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC1_PTY            equ       0                   ; Parity Bit
SCC1_PEN            equ       1                   ; Parity Enable Bit
SCC1_ILTY           equ       2                   ; Idle Line Type Bit
SCC1_WAKE           equ       3                   ; Wakeup Condition Bit
SCC1_M              equ       4                   ; Mode (Character Length) Bit
SCC1_TXINV          equ       5                   ; Transmit Inversion Bit
SCC1_ENSCI          equ       6                   ; Enable ESCI Bit
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

;*** SCC2 - ESCI Control Register 2
SCC2                equ       $00000014           ;*** SCC2 - ESCI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCC2_SBK            equ       0                   ; Send Break Bit
SCC2_RWU            equ       1                   ; Receiver Wakeup Bit
SCC2_RE             equ       2                   ; Receiver Enable Bit
SCC2_TE             equ       3                   ; Transmitter Enable Bit
SCC2_ILIE           equ       4                   ; Idle Line Interrupt Enable Bit
SCC2_SCRIE          equ       5                   ; ESCI Receive Interrupt Enable Bit
SCC2_TCIE           equ       6                   ; Transmission Complete Interrupt Enable Bit
SCC2_SCTIE          equ       7                   ; ESCI Transmit Interrupt Enable Bit
; bit position masks
mSCC2_SBK           equ       %00000001
mSCC2_RWU           equ       %00000010
mSCC2_RE            equ       %00000100
mSCC2_TE            equ       %00001000
mSCC2_ILIE          equ       %00010000
mSCC2_SCRIE         equ       %00100000
mSCC2_TCIE          equ       %01000000
mSCC2_SCTIE         equ       %10000000

;*** SCC3 - ESCI Control Register 3
SCC3                equ       $00000015           ;*** SCC3 - ESCI Control Register 3
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

;*** SCS1 - ESCI Status Register 1
SCS1                equ       $00000016           ;*** SCS1 - ESCI Status Register 1
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

;*** SCS2 - ESCI Status Register 2
SCS2                equ       $00000017           ;*** SCS2 - ESCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCS2_RPF            equ       0                   ; Reception in Progress Flag Bit
SCS2_BKF            equ       1                   ; Break Flag Bit
; bit position masks
mSCS2_RPF           equ       %00000001
mSCS2_BKF           equ       %00000010

;*** SCDR - ESCI Data Register
SCDR                equ       $00000018           ;*** SCDR - ESCI Data Register
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

;*** SCBR - ESCI Baud Rate Register
SCBR                equ       $00000019           ;*** SCBR - ESCI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCBR_SCR0           equ       0                   ; ESCI Baud Rate Select Bit 0
SCBR_SCR1           equ       1                   ; ESCI Baud Rate Select Bit 1
SCBR_SCR2           equ       2                   ; ESCI Baud Rate Select Bit 2
SCBR_SCP0           equ       4                   ; ESCI Baud Rate Prescaler Bit 0
SCBR_SCP1           equ       5                   ; ESCI Baud Rate Prescaler Bit 1
SCBR_LINR           equ       6                   ; LIN Break Symbol Receiver Bit
SCBR_LINT           equ       7                   ; LIN Breal Symbol Transmit Enable
; bit position masks
mSCBR_SCR0          equ       %00000001
mSCBR_SCR1          equ       %00000010
mSCBR_SCR2          equ       %00000100
mSCBR_SCP0          equ       %00010000
mSCBR_SCP1          equ       %00100000
mSCBR_LINR          equ       %01000000
mSCBR_LINT          equ       %10000000

;*** INTKBSCR - Keyboard Status and Control Register
INTKBSCR            equ       $0000001A           ;*** INTKBSCR - Keyboard Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBSCR_MODEK      equ       0                   ; Keyboard Triggering Sensitivity Bit
INTKBSCR_IMASKK     equ       1                   ; Keyboard Interrupt Mask Bit
INTKBSCR_ACKK       equ       2                   ; Keyboard Acknowledge Bit
INTKBSCR_KEYF       equ       3                   ; Keyboard Flag Bit
; bit position masks
mINTKBSCR_MODEK     equ       %00000001
mINTKBSCR_IMASKK    equ       %00000010
mINTKBSCR_ACKK      equ       %00000100
mINTKBSCR_KEYF      equ       %00001000

;*** INTKBIER - Keyboard Interrupt Enable Register
INTKBIER            equ       $0000001B           ;*** INTKBIER - Keyboard Interrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBIER_KBIE0      equ       0                   ; Keyboard Interrupt Enable Bit 0
INTKBIER_KBIE1      equ       1                   ; Keyboard Interrupt Enable Bit 1
INTKBIER_KBIE2      equ       2                   ; Keyboard Interrupt Enable Bit 2
INTKBIER_KBIE3      equ       3                   ; Keyboard Interrupt Enable Bit 3
INTKBIER_KBIE4      equ       4                   ; Keyboard Interrupt Enable Bit 4
INTKBIER_KBIE5      equ       5                   ; Keyboard Interrupt Enable Bit 5
INTKBIER_KBIE6      equ       6                   ; Keyboard Interrupt Enable Bit 6
INTKBIER_KBIE7      equ       7                   ; Keyboard Interrupt Enable Bit 7
; bit position masks
mINTKBIER_KBIE0     equ       %00000001
mINTKBIER_KBIE1     equ       %00000010
mINTKBIER_KBIE2     equ       %00000100
mINTKBIER_KBIE3     equ       %00001000
mINTKBIER_KBIE4     equ       %00010000
mINTKBIER_KBIE5     equ       %00100000
mINTKBIER_KBIE6     equ       %01000000
mINTKBIER_KBIE7     equ       %10000000

;*** TBCR - Timebase Control Register
TBCR                equ       $0000001C           ;*** TBCR - Timebase Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TBCR_TBON           equ       1                   ; Timebase Enabled
TBCR_TBIE           equ       2                   ; Timebase Interrupt Enable
TBCR_TACK           equ       3                   ; Timebase ACKnowledge
TBCR_TBR0           equ       4                   ; Timebase Rate Selection Bit 0
TBCR_TBR1           equ       5                   ; Timebase Rate Selection Bit 1
TBCR_TBR2           equ       6                   ; Timebase Rate Selection Bit2
TBCR_TBIF           equ       7                   ; Timebase Interrupt Flag
; bit position masks
mTBCR_TBON          equ       %00000010
mTBCR_TBIE          equ       %00000100
mTBCR_TACK          equ       %00001000
mTBCR_TBR0          equ       %00010000
mTBCR_TBR1          equ       %00100000
mTBCR_TBR2          equ       %01000000
mTBCR_TBIF          equ       %10000000

;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001D           ;*** INTSCR - IRQ Status and Control Register
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

;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001E           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_SCIBDSRC    equ       0                   ; ESCI Baud Rate Clock Source Bit
CONFIG2_OSCENINSTOP equ       1                   ; Oscillator Enable In Stop Mode Bit
CONFIG2_TMBCLKSEL   equ       2                   ; Timebase Clock Select Bit
CONFIG2_MSCANEN     equ       3                   ; MSCAN Enable Bit
CONFIG2_MCLK0       equ       4                   ; MCLK Output Select Bit 0
CONFIG2_MCLK1       equ       5                   ; MCLK Output Select Bit 1
CONFIG2_MCLKSEL     equ       6                   ; MCLK Source Select Bit
; bit position masks
mCONFIG2_SCIBDSRC   equ       %00000001
mCONFIG2_OSCENINSTOP equ       %00000010
mCONFIG2_TMBCLKSEL  equ       %00000100
mCONFIG2_MSCANEN    equ       %00001000
mCONFIG2_MCLK0      equ       %00010000
mCONFIG2_MCLK1      equ       %00100000
mCONFIG2_MCLKSEL    equ       %01000000

;*** CONFIG1 - Configuration Register
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVI5OR3     equ       3                   ; LVI 5-V or 3-V Operating Mode Bit
CONFIG1_LVIPWRD     equ       4                   ; LVI Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; LVI Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP Rate Select Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVI5OR3    equ       %00001000
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

;*** T1CNTH - TIM1 Counter Register High
T1CNTH              equ       $00000021           ;*** T1CNTH - TIM1 Counter Register High

;*** T1CNTL - TIM1 Counter Register Low
T1CNTL              equ       $00000022           ;*** T1CNTL - TIM1 Counter Register Low

;*** T1MOD - TIM1 Counter Modulo Register
T1MOD               equ       $00000023           ;*** T1MOD - TIM1 Counter Modulo Register

;*** T1MODH - TIM1 Counter Modulo Register High
T1MODH              equ       $00000023           ;*** T1MODH - TIM1 Counter Modulo Register High

;*** T1MODL - TIM1 Counter Modulo Register Low
T1MODL              equ       $00000024           ;*** T1MODL - TIM1 Counter Modulo Register Low

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

;*** T2CNTH - TIM2 Counter Register High
T2CNTH              equ       $0000002C           ;*** T2CNTH - TIM2 Counter Register High

;*** T2CNTL - TIM2 Counter Register Low
T2CNTL              equ       $0000002D           ;*** T2CNTL - TIM2 Counter Register Low

;*** T2MOD - TIM2 Counter Modulo Register
T2MOD               equ       $0000002E           ;*** T2MOD - TIM2 Counter Modulo Register

;*** T2MODH - TIM2 Counter Modulo Register High
T2MODH              equ       $0000002E           ;*** T2MODH - TIM2 Counter Modulo Register High

;*** T2MODL - TIM2 Counter Modulo Register Low
T2MODL              equ       $0000002F           ;*** T2MODL - TIM2 Counter Modulo Register Low

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
PCTL_BCS            equ       4                   ; Base Clock Select Bit
PCTL_PLLON          equ       5                   ; PLL On Bit
PCTL_PLLF           equ       6                   ; PLL Flag Bit
PCTL_PLLIE          equ       7                   ; PLL Interrupt Enable Bit
; bit position masks
mPCTL_VPR0          equ       %00000001
mPCTL_VPR1          equ       %00000010
mPCTL_BCS           equ       %00010000
mPCTL_PLLON         equ       %00100000
mPCTL_PLLF          equ       %01000000
mPCTL_PLLIE         equ       %10000000

;*** PBWC - PLL Bandwidth Control Register
PBWC                equ       $00000037           ;*** PBWC - PLL Bandwidth Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PBWC_ACQ            equ       5                   ; Acquisition Mode Bit
PBWC_LOCK           equ       6                   ; Lock Indicator Bit
PBWC_AUTO           equ       7                   ; Automatic Bandwidth Control Bit
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

;*** PMRS - PLL VCO Range Select Register
PMRS                equ       $0000003A           ;*** PMRS - PLL VCO Range Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMRS_VRS0           equ       0                   ; PLL VCO Range Select Bit 0
PMRS_VRS1           equ       1                   ; PLL VCO Range Select Bit 1
PMRS_VRS2           equ       2                   ; PLL VCO Range Select Bit 2
PMRS_VRS3           equ       3                   ; PLL VCO Range Select Bit 3
PMRS_VRS4           equ       4                   ; PLL VCO Range Select Bit 4
PMRS_VRS5           equ       5                   ; PLL VCO Range Select Bit 5
PMRS_VRS6           equ       6                   ; PLL VCO Range Select Bit 6
PMRS_VRS7           equ       7                   ; PLL VCO Range Select Bit 7
; bit position masks
mPMRS_VRS0          equ       %00000001
mPMRS_VRS1          equ       %00000010
mPMRS_VRS2          equ       %00000100
mPMRS_VRS3          equ       %00001000
mPMRS_VRS4          equ       %00010000
mPMRS_VRS5          equ       %00100000
mPMRS_VRS6          equ       %01000000
mPMRS_VRS7          equ       %10000000

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

;*** ADRH - ADC Data Register High
ADRH                equ       $0000003D           ;*** ADRH - ADC Data Register High
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
ADRL                equ       $0000003E           ;*** ADRL - ADC Data Register Low
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

;*** PTF - Port F Data Register
PTF                 equ       $00000440           ;*** PTF - Port F Data Register
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

;*** PTG - Port G Data Register
PTG                 equ       $00000441           ;*** PTG - Port G Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTG_PTG0            equ       0                   ; Port G Data Bit 0
PTG_PTG1            equ       1                   ; Port G Data Bit 1
PTG_PTG2            equ       2                   ; Port G Data Bit 2
PTG_PTG3            equ       3                   ; Port G Data Bit 3
PTG_PTG4            equ       4                   ; Port G Data Bit 4
PTG_PTG5            equ       5                   ; Port G Data Bit 5
PTG_PTG6            equ       6                   ; Port G Data Bit 6
PTG_PTG7            equ       7                   ; Port G Data Bit 7
; bit position masks
mPTG_PTG0           equ       %00000001
mPTG_PTG1           equ       %00000010
mPTG_PTG2           equ       %00000100
mPTG_PTG3           equ       %00001000
mPTG_PTG4           equ       %00010000
mPTG_PTG5           equ       %00100000
mPTG_PTG6           equ       %01000000
mPTG_PTG7           equ       %10000000

;*** DDRF - Data Direction Register F
DDRF                equ       $00000444           ;*** DDRF - Data Direction Register F
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

;*** DDRG - Data Direction Register G
DDRG                equ       $00000445           ;*** DDRG - Data Direction Register G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRG_DDRG0          equ       0                   ; Data Direction Register G Bit 0
DDRG_DDRG1          equ       1                   ; Data Direction Register G Bit 1
DDRG_DDRG2          equ       2                   ; Data Direction Register G Bit 2
DDRG_DDRG3          equ       3                   ; Data Direction Register G Bit 3
DDRG_DDRG4          equ       4                   ; Data Direction Register G Bit 4
DDRG_DDRG5          equ       5                   ; Data Direction Register G Bit 5
DDRG_DDRG6          equ       6                   ; Data Direction Register G Bit 6
DDRG_DDRG7          equ       7                   ; Data Direction Register G Bit 7
; bit position masks
mDDRG_DDRG0         equ       %00000001
mDDRG_DDRG1         equ       %00000010
mDDRG_DDRG2         equ       %00000100
mDDRG_DDRG3         equ       %00001000
mDDRG_DDRG4         equ       %00010000
mDDRG_DDRG5         equ       %00100000
mDDRG_DDRG6         equ       %01000000
mDDRG_DDRG7         equ       %10000000

;*** INTKBIPR - Keyboard Interrupt Polarity Register
INTKBIPR            equ       $00000448           ;*** INTKBIPR - Keyboard Interrupt Polarity Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBIPR_KBIP0      equ       0                   ; Keyboard Interrupt Polarity Bit 0
INTKBIPR_KBIP1      equ       1                   ; Keyboard Interrupt Polarity Bit 1
INTKBIPR_KBIP2      equ       2                   ; Keyboard Interrupt Polarity Bit 2
INTKBIPR_KBIP3      equ       3                   ; Keyboard Interrupt Polarity Bit 3
INTKBIPR_KBIP4      equ       4                   ; Keyboard Interrupt Polarity Bit 4
INTKBIPR_KBIP5      equ       5                   ; Keyboard Interrupt Polarity Bit 5
INTKBIPR_KBIP6      equ       6                   ; Keyboard Interrupt Polarity Bit 6
INTKBIPR_KBIP7      equ       7                   ; Keyboard Interrupt Polarity Bit 7
; bit position masks
mINTKBIPR_KBIP0     equ       %00000001
mINTKBIPR_KBIP1     equ       %00000010
mINTKBIPR_KBIP2     equ       %00000100
mINTKBIPR_KBIP3     equ       %00001000
mINTKBIPR_KBIP4     equ       %00010000
mINTKBIPR_KBIP5     equ       %00100000
mINTKBIPR_KBIP6     equ       %01000000
mINTKBIPR_KBIP7     equ       %10000000

;*** T2SC2 - TIM2 Channel 2 Status and Control Register
T2SC2               equ       $00000456           ;*** T2SC2 - TIM2 Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC2_CH2MAX        equ       0                   ; Channel 2 Maximum Duty Cycle Bit
T2SC2_TOV2          equ       1                   ; Toggle-On-Overflow Bit
T2SC2_ELS2A         equ       2                   ; Edge/Level Select Bit A
T2SC2_ELS2B         equ       3                   ; Edge/Level Select Bit B
T2SC2_MS2A          equ       4                   ; Mode Select Bit A
T2SC2_CH2IE         equ       6                   ; Channel 2 Interrupt Enable Bit
T2SC2_CH2F          equ       7                   ; Channel 2 Flag Bit
; bit position masks
mT2SC2_CH2MAX       equ       %00000001
mT2SC2_TOV2         equ       %00000010
mT2SC2_ELS2A        equ       %00000100
mT2SC2_ELS2B        equ       %00001000
mT2SC2_MS2A         equ       %00010000
mT2SC2_CH2IE        equ       %01000000
mT2SC2_CH2F         equ       %10000000

;*** T2CH2 - TIM2 Channel 2 Register
T2CH2               equ       $00000457           ;*** T2CH2 - TIM2 Channel 2 Register

;*** T2CH2H - TIM2 Channel 2 Register High
T2CH2H              equ       $00000457           ;*** T2CH2H - TIM2 Channel 2 Register High

;*** T2CH2L - TIM2 Channel 2 Register Low
T2CH2L              equ       $00000458           ;*** T2CH2L - TIM2 Channel 2 Register Low

;*** T2SC3 - TIM2 Channel 3 Status and Control Register
T2SC3               equ       $00000459           ;*** T2SC3 - TIM2 Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC3_CH3MAX        equ       0                   ; Channel 3 Maximum Duty Cycle Bit
T2SC3_TOV3          equ       1                   ; Toggle-On-Overflow Bit
T2SC3_ELS3A         equ       2                   ; Edge/Level Select Bit A
T2SC3_ELS3B         equ       3                   ; Edge/Level Select Bit B
T2SC3_MS3A          equ       4                   ; Mode Select Bit A
T2SC3_CH3IE         equ       6                   ; Channel 3 Interrupt Enable Bit
T2SC3_CH3F          equ       7                   ; Channel 3 Flag Bit
; bit position masks
mT2SC3_CH3MAX       equ       %00000001
mT2SC3_TOV3         equ       %00000010
mT2SC3_ELS3A        equ       %00000100
mT2SC3_ELS3B        equ       %00001000
mT2SC3_MS3A         equ       %00010000
mT2SC3_CH3IE        equ       %01000000
mT2SC3_CH3F         equ       %10000000

;*** T2CH3 - TIM2 Channel 3 Register
T2CH3               equ       $0000045A           ;*** T2CH3 - TIM2 Channel 3 Register

;*** T2CH3H - TIM2 Channel 3 Register High
T2CH3H              equ       $0000045A           ;*** T2CH3H - TIM2 Channel 3 Register High

;*** T2CH3L - TIM2 Channel 3 Register Low
T2CH3L              equ       $0000045B           ;*** T2CH3L - TIM2 Channel 3 Register Low

;*** T2SC4 - TIM2 Channel 4 Status and Control Register
T2SC4               equ       $0000045C           ;*** T2SC4 - TIM2 Channel 4 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC4_CH4MAX        equ       0                   ; Channel 4 Maximum Duty Cycle Bit
T2SC4_TOV4          equ       1                   ; Toggle-On-Overflow Bit
T2SC4_ELS4A         equ       2                   ; Edge/Level Select Bit A
T2SC4_ELS4B         equ       3                   ; Edge/Level Select Bit B
T2SC4_MS4A          equ       4                   ; Mode Select Bit A
T2SC4_CH4IE         equ       6                   ; Channel 4 Interrupt Enable Bit
T2SC4_CH4F          equ       7                   ; Channel 4 Flag Bit
; bit position masks
mT2SC4_CH4MAX       equ       %00000001
mT2SC4_TOV4         equ       %00000010
mT2SC4_ELS4A        equ       %00000100
mT2SC4_ELS4B        equ       %00001000
mT2SC4_MS4A         equ       %00010000
mT2SC4_CH4IE        equ       %01000000
mT2SC4_CH4F         equ       %10000000

;*** T2CH4 - TIM2 Channel 4 Register
T2CH4               equ       $0000045D           ;*** T2CH4 - TIM2 Channel 4 Register

;*** T2CH4H - TIM2 Channel 4 Register High
T2CH4H              equ       $0000045D           ;*** T2CH4H - TIM2 Channel 4 Register High

;*** T2CH4L - TIM2 Channel 4 Register Low
T2CH4L              equ       $0000045E           ;*** T2CH4L - TIM2 Channel 4 Register Low

;*** T2SC5 - TIM2 Channel 5 Status and Control Register
T2SC5               equ       $0000045F           ;*** T2SC5 - TIM2 Channel 5 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC5_CH5MAX        equ       0                   ; Channel 5 Maximum Duty Cycle Bit
T2SC5_TOV5          equ       1                   ; Toggle-On-Overflow Bit
T2SC5_ELS5A         equ       2                   ; Edge/Level Select Bit A
T2SC5_ELS5B         equ       3                   ; Edge/Level Select Bit B
T2SC5_MS5A          equ       4                   ; Mode Select Bit A
T2SC5_CH5IE         equ       6                   ; Channel 5 Interrupt Enable Bit
T2SC5_CH5F          equ       7                   ; Channel 5 Flag Bit
; bit position masks
mT2SC5_CH5MAX       equ       %00000001
mT2SC5_TOV5         equ       %00000010
mT2SC5_ELS5A        equ       %00000100
mT2SC5_ELS5B        equ       %00001000
mT2SC5_MS5A         equ       %00010000
mT2SC5_CH5IE        equ       %01000000
mT2SC5_CH5F         equ       %10000000

;*** T2CH5 - TIM2 Channel 5 Register
T2CH5               equ       $00000460           ;*** T2CH5 - TIM2 Channel 5 Register

;*** T2CH5H - TIM2 Channel 5 Register High
T2CH5H              equ       $00000460           ;*** T2CH5H - TIM2 Channel 5 Register High

;*** T2CH5L - TIM2 Channel 5 Register Low
T2CH5L              equ       $00000461           ;*** T2CH5L - TIM2 Channel 5 Register Low

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
CIDAC_IDHIT2        equ       2                   ; Identifier Acceptance Hit Indicator 2
CIDAC_IDAM0         equ       4                   ; Identifier Acceptance Mode 0
CIDAC_IDAM1         equ       5                   ; Identifier Acceptance Mode 1
CIDAC_IDAM2         equ       6                   ; Identifier Acceptance Hit Indicator 2
; bit position masks
mCIDAC_IDHIT0       equ       %00000001
mCIDAC_IDHIT1       equ       %00000010
mCIDAC_IDHIT2       equ       %00000100
mCIDAC_IDAM0        equ       %00010000
mCIDAC_IDAM1        equ       %00100000
mCIDAC_IDAM2        equ       %01000000

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

;*** BSR - Break Status Register
BSR                 equ       $0000FE00           ;*** BSR - Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BSR_SBSW            equ       1                   ; SIM Break Stop/Wait
; bit position masks
mBSR_SBSW           equ       %00000010

;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset Bit
SRSR_MODRST         equ       2                   ; Monitor Mode Entry Module Reset Bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
mSRSR_MODRST        equ       %00000100
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
INT1_IF1            equ       2                   ; Interrupt Status Bit 1
INT1_IF2            equ       3                   ; Interrupt Status Bit 2
INT1_IF3            equ       4                   ; Interrupt Status Bit 3
INT1_IF4            equ       5                   ; Interrupt Status Bit 4
INT1_IF5            equ       6                   ; Interrupt Status Bit 5
INT1_IF6            equ       7                   ; Interrupt Status Bit 6
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
INT2_IF7            equ       0                   ; Interrupt Status Bit 7
INT2_IF8            equ       1                   ; Interrupt Status Bit 8
INT2_IF9            equ       2                   ; Interrupt Status Bit 9
INT2_IF10           equ       3                   ; Interrupt Status Bit 10
INT2_IF11           equ       4                   ; Interrupt Status Bit 11
INT2_IF12           equ       5                   ; Interrupt Status Bit 12
INT2_IF13           equ       6                   ; Interrupt Status Bit 13
INT2_IF14           equ       7                   ; Interrupt Status Bit 14
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
INT3_IF15           equ       0                   ; Interrupt Status Bit 15
INT3_IF16           equ       1                   ; Interrupt Status Bit 16
INT3_IF17           equ       2                   ; Interrupt Status Bit 17
INT3_IF18           equ       3                   ; Interrupt Status Bit 18
INT3_IF19           equ       4                   ; Interrupt Status Bit 19
INT3_IF20           equ       5                   ; Interrupt Status Bit 20
INT3_IF21           equ       6                   ; Interrupt Status Bit 21
INT3_IF22           equ       7                   ; Interrupt Status Bit 22
; bit position masks
mINT3_IF15          equ       %00000001
mINT3_IF16          equ       %00000010
mINT3_IF17          equ       %00000100
mINT3_IF18          equ       %00001000
mINT3_IF19          equ       %00010000
mINT3_IF20          equ       %00100000
mINT3_IF21          equ       %01000000
mINT3_IF22          equ       %10000000

;*** INT4 - Interrupt Status Register 4
INT4                equ       $0000FE07           ;*** INT4 - Interrupt Status Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT4_IF23           equ       0                   ; Interrupt Status Bit 23
INT4_IF24           equ       1                   ; Interrupt Status Bit 24
; bit position masks
mINT4_IF23          equ       %00000001
mINT4_IF24          equ       %00000010

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

;*** FL1BPR - FLASH 1 Block Protect Register
FL1BPR              equ       $0000FF80           ;*** FL1BPR - FLASH 1 Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FL1BPR_BPR0         equ       0                   ; Block Protect Bit 0
FL1BPR_BPR1         equ       1                   ; Block Protect Bit 1
FL1BPR_BPR2         equ       2                   ; Block Protect Bit 2
FL1BPR_BPR3         equ       3                   ; Block Protect Bit 3
FL1BPR_BPR4         equ       4                   ; Block Protect Bit 4
FL1BPR_BPR5         equ       5                   ; Block Protect Bit 5
FL1BPR_BPR6         equ       6                   ; Block Protect Bit 6
FL1BPR_BPR7         equ       7                   ; Block Protect Bit 7
; bit position masks
mFL1BPR_BPR0        equ       %00000001
mFL1BPR_BPR1        equ       %00000010
mFL1BPR_BPR2        equ       %00000100
mFL1BPR_BPR3        equ       %00001000
mFL1BPR_BPR4        equ       %00010000
mFL1BPR_BPR5        equ       %00100000
mFL1BPR_BPR6        equ       %01000000
mFL1BPR_BPR7        equ       %10000000

;*** FL1CR - FLASH 1 Control Register
FL1CR               equ       $0000FF88           ;*** FL1CR - FLASH 1 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FL1CR_PGM           equ       0                   ; Program Control Bit
FL1CR_ERASE         equ       1                   ; Erase Control Bit
FL1CR_MASS          equ       2                   ; Mass Erase Control Bit
FL1CR_HVEN          equ       3                   ; High-Voltage Enable Bit
; bit position masks
mFL1CR_PGM          equ       %00000001
mFL1CR_ERASE        equ       %00000010
mFL1CR_MASS         equ       %00000100
mFL1CR_HVEN         equ       %00001000

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
; Follows changes from the database 2.87.065 version
mSCPSC_PS0          equ       mSCPSC_PDS0
SCPSC_PS0           equ       SCPSC_PDS0
mSCPSC_PS1          equ       mSCPSC_PDS1
SCPSC_PS1           equ       SCPSC_PDS1
mSCPSC_PS2          equ       mSCPSC_PDS2
SCPSC_PS2           equ       SCPSC_PDS2
;
; Follows changes from the database 2.87.072 version
SBSR                equ       BSR
mSBSR_SBSW          equ       mBSR_SBSW
SBSR_SBSW           equ       BSR_SBSW

; EOF
