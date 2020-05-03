;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908GR16A_48, version 2.89.060 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908gr16a.inc
;     Processor : MC68HC908GR16ACFA
;     FileFormat: V2.28
;     DataSheet : MC68HC908GR16A Rev. 1.0 03/2006
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
ROM                 equ       $0000C000
ROM_END             equ       $0000FDFF
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000043F
;
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
TBCR_TBR0           equ       4                   ; Timebase Rate Selection
TBCR_TBR1           equ       5                   ; Timebase Rate Selection
TBCR_TBR2           equ       6                   ; Timebase Rate Selection
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
CONFIG2_ESCIBDSRC   equ       0                   ; ESCI Baud Rate Clock Source Bit
CONFIG2_OSCENINSTOP equ       1                   ; Oscillator Enable In Stop Mode Bit
CONFIG2_TMBCLKSEL   equ       2                   ; Timebase Clock Select Bit
; bit position masks
mCONFIG2_ESCIBDSRC  equ       %00000001
mCONFIG2_OSCENINSTOP equ       %00000010
mCONFIG2_TMBCLKSEL  equ       %00000100


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
; bit position masks
mINT3_IF15          equ       %00000001
mINT3_IF16          equ       %00000010
mINT3_IF17          equ       %00000100
mINT3_IF18          equ       %00001000
mINT3_IF19          equ       %00010000
mINT3_IF20          equ       %00100000


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


;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FF7E           ;*** FLBPR - FLASH Block Protect Register
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
