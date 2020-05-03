;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908QL16_28, version 2.87.030 (RegistersPrg V2.13)

; ###################################################################
;     Filename  : mc68hc908ql8.inc
;     Processor : MC68HC908QL8CDRE
;     FileFormat: V2.13
;     DataSheet : MC68HC908QL16 Rev. 0 11/2005
;     Compiler  : CodeWarrior compiler
;     Date/Time : 08.03.2007, 16:01
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     (c) Copyright UNIS, spol. s r.o. 1997-2006
;     UNIS, spol. s r.o.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
;
;     File-Format-Revisions:
;      - 14.11.2005, V2.00 :
;               - Deprecated symbols added for backward compatibility (section at the end of this file)
;      - 15.11.2005, V2.01 :
;               - Revision is not related to this file (CPU family)
;      - 17.12.2005, V2.02 :
;               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
;      - 16.01.2006, V2.03 :
;               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
;               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
;      - 08.03.2006, V2.04 :
;               - Support for bit(s) names duplicated with any register name in .h header files
;      - 24.03.2006, V2.05 :
;               - Revision is not related to this file (CPU family)
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
;               - Revision is not related to this file (CPU family)
;      - 22.01.2007, V2.12 :
;               - Revision is not related to this file (CPU family)
;      - 01.03.2007, V2.13 :
;               - Flash commands constants values converted to HEX format
;
;     CPU Registers Revisions:
;               - none
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000DE00
ROM_END             equ       $0000FDFF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $000001FF
;
INT_ADC             equ       $0000FFDE
INT_KBI             equ       $0000FFE0
Reserved2           equ       $0000FFE2
Reserved3           equ       $0000FFE4
INT_SPITransmit     equ       $0000FFE6
INT_SPIReceive      equ       $0000FFE8
INT_SLIC            equ       $0000FFEA
INT_TIM2Ovr         equ       $0000FFEC
INT_TIM2CH1         equ       $0000FFEE
INT_TIM2CH0         equ       $0000FFF0
INT_TIM1Ovr         equ       $0000FFF2
INT_TIM1CH1         equ       $0000FFF4
INT_TIM1CH0         equ       $0000FFF6
Reserved13          equ       $0000FFF8
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
PTA_AWUL            equ       6                   ; Auto Wake-up Latch Data Bit
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000
mPTA_PTA5           equ       %00100000
mPTA_AWUL           equ       %01000000


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
DDRA_DDRA3          equ       3                   ; Data Direction Register A Bit 3
DDRA_DDRA4          equ       4                   ; Data Direction Register A Bit 4
DDRA_DDRA5          equ       5                   ; Data Direction Register A Bit 5
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000
mDDRA_DDRA5         equ       %00100000


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
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010
mDDRC_DDRC2         equ       %00000100


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


;*** PTAPUE - Input Pull-Up Enable Register PTAPUE
PTAPUE              equ       $0000000B           ;*** PTAPUE - Input Pull-Up Enable Register PTAPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUE_PTAPUE0      equ       0                   ; Pull-Up Enable bit 0, Port A
PTAPUE_PTAPUE1      equ       1                   ; Pull-Up Enable bit 1, Port A
PTAPUE_PTAPUE2      equ       2                   ; Pull-Up Enable bit 2, Port A
PTAPUE_PTAPUE3      equ       3                   ; Pull-Up Enable bit 3, Port A
PTAPUE_PTAPUE4      equ       4                   ; Pull-Up Enable bit 4, Port A
PTAPUE_PTAPUE5      equ       5                   ; Pull-Up Enable bit 5, Port A
PTAPUE_OSC2EN       equ       7                   ; Enable PTA4 on OSC2 Pin
; bit position masks
mPTAPUE_PTAPUE0     equ       %00000001
mPTAPUE_PTAPUE1     equ       %00000010
mPTAPUE_PTAPUE2     equ       %00000100
mPTAPUE_PTAPUE3     equ       %00001000
mPTAPUE_PTAPUE4     equ       %00010000
mPTAPUE_PTAPUE5     equ       %00100000
mPTAPUE_OSC2EN      equ       %10000000


;*** PTBPUE - Input Pull-Up Enable Register PTBPUE
PTBPUE              equ       $0000000C           ;*** PTBPUE - Input Pull-Up Enable Register PTBPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPUE_PTBPUE0      equ       0                   ; Pull-Up Enable bit 0, Port B
PTBPUE_PTBPUE1      equ       1                   ; Pull-Up Enable bit 1, Port B
PTBPUE_PTBPUE2      equ       2                   ; Pull-Up Enable bit 2, Port B
PTBPUE_PTBPUE3      equ       3                   ; Pull-Up Enable bit 3, Port B
PTBPUE_PTBPUE4      equ       4                   ; Pull-Up Enable bit 4, Port B
PTBPUE_PTBPUE5      equ       5                   ; Pull-Up Enable bit 5, Port B
PTBPUE_PTBPUE6      equ       6                   ; Pull-Up Enable bit 6, Port B
PTBPUE_PTBPUE7      equ       7                   ; Pull-Up Enable bit 7, Port B
; bit position masks
mPTBPUE_PTBPUE0     equ       %00000001
mPTBPUE_PTBPUE1     equ       %00000010
mPTBPUE_PTBPUE2     equ       %00000100
mPTBPUE_PTBPUE3     equ       %00001000
mPTBPUE_PTBPUE4     equ       %00010000
mPTBPUE_PTBPUE5     equ       %00100000
mPTBPUE_PTBPUE6     equ       %01000000
mPTBPUE_PTBPUE7     equ       %10000000


;*** PTCPUE - Input Pull-Up Enable Register PTCPUE
PTCPUE              equ       $0000000D           ;*** PTCPUE - Input Pull-Up Enable Register PTCPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPUE_PTCPUE0      equ       0                   ; Pull-Up Enable bit 0, Port C
PTCPUE_PTCPUE1      equ       1                   ; Pull-Up Enable bit 1, Port C
PTCPUE_PTCPUE2      equ       2                   ; Pull-Up Enable bit 2, Port C
PTCPUE_PTCPUE3      equ       3                   ; Pull-Up Enable bit 3, Port C
; bit position masks
mPTCPUE_PTCPUE0     equ       %00000001
mPTCPUE_PTCPUE1     equ       %00000010
mPTCPUE_PTCPUE2     equ       %00000100
mPTCPUE_PTCPUE3     equ       %00001000


;*** PTDPUE - Input Pull-Up Enable Register PTDPUE
PTDPUE              equ       $0000000E           ;*** PTDPUE - Input Pull-Up Enable Register PTDPUE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPUE_PTDPUE0      equ       0                   ; Pull-Up Enable bit 0, Port D
PTDPUE_PTDPUE1      equ       1                   ; Pull-Up Enable bit 1, Port D
PTDPUE_PTDPUE2      equ       2                   ; Pull-Up Enable bit 2, Port D
PTDPUE_PTDPUE3      equ       3                   ; Pull-Up Enable bit 3, Port D
PTDPUE_PTDPUE4      equ       4                   ; Pull-Up Enable bit 4, Port D
PTDPUE_PTDPUE5      equ       5                   ; Pull-Up Enable bit 5, Port D
PTDPUE_PTDPUE6      equ       6                   ; Pull-Up Enable bit 6, Port D
PTDPUE_PTDPUE7      equ       7                   ; Pull-Up Enable bit 7, Port D
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


;*** KBSCR - Keyboard Status and Control Register
KBSCR               equ       $0000001A           ;*** KBSCR - Keyboard Status and Control Register
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
KBIER               equ       $0000001B           ;*** KBIER - Keyboard Interrrupt Enable Register KBIER
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIER_KBIE0         equ       0                   ; Keyboard Interrupt Enable Bit 0
KBIER_KBIE1         equ       1                   ; Keyboard Interrupt Enable Bit 1
KBIER_KBIE2         equ       2                   ; Keyboard Interrupt Enable Bit 2
KBIER_KBIE3         equ       3                   ; Keyboard Interrupt Enable Bit 3
KBIER_KBIE4         equ       4                   ; Keyboard Interrupt Enable Bit 4
KBIER_KBIE5         equ       5                   ; Keyboard Interrupt Enable Bit 5
KBIER_AWUIE         equ       6                   ; Auto Wake-up Interrupt Enable Bit
; bit position masks
mKBIER_KBIE0        equ       %00000001
mKBIER_KBIE1        equ       %00000010
mKBIER_KBIE2        equ       %00000100
mKBIER_KBIE3        equ       %00001000
mKBIER_KBIE4        equ       %00010000
mKBIER_KBIE5        equ       %00100000
mKBIER_AWUIE        equ       %01000000


;*** KBIPR - Keyboard Interrupt Polarity Register
KBIPR               equ       $0000001C           ;*** KBIPR - Keyboard Interrupt Polarity Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPR_KBIP0         equ       0                   ; Keyboard Interrupt Polarity Bit 0
KBIPR_KBIP1         equ       1                   ; Keyboard Interrupt Polarity Bit 1
KBIPR_KBIP2         equ       2                   ; Keyboard Interrupt Polarity Bit 2
KBIPR_KBIP3         equ       3                   ; Keyboard Interrupt Polarity Bit 3
KBIPR_KBIP4         equ       4                   ; Keyboard Interrupt Polarity Bit 4
KBIPR_KBIP5         equ       5                   ; Keyboard Interrupt Polarity Bit 5
; bit position masks
mKBIPR_KBIP0        equ       %00000001
mKBIPR_KBIP1        equ       %00000010
mKBIPR_KBIP2        equ       %00000100
mKBIPR_KBIP3        equ       %00001000
mKBIPR_KBIP4        equ       %00010000
mKBIPR_KBIP5        equ       %00100000


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
CONFIG2_RSTEN       equ       0                   ; RST Pin Function Selection
CONFIG2_OSCENINSTOP equ       1                   ; Oscillator Enable in Stop Mode Bit
CONFIG2_IRQEN       equ       6                   ; IRQ Pin Function Selection Bit
CONFIG2_IRQPUD      equ       7                   ; IRQ Pin Pullup Control Bit
; bit position masks
mCONFIG2_RSTEN      equ       %00000001
mCONFIG2_OSCENINSTOP equ       %00000010
mCONFIG2_IRQEN      equ       %01000000
mCONFIG2_IRQPUD     equ       %10000000


;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVITRIP     equ       3                   ; LVI Trip Point Selection Bit
CONFIG1_LVIPWRD     equ       4                   ; Low Voltage Inhibit Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; Low Voltage Inhibit Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP Reset Period Selection Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVITRIP    equ       %00001000
mCONFIG1_LVIPWRD    equ       %00010000
mCONFIG1_LVIRSTD    equ       %00100000
mCONFIG1_LVISTOP    equ       %01000000
mCONFIG1_COPRS      equ       %10000000


;*** T1SC - TIM1 Status and Control Register TSC
T1SC                equ       $00000020           ;*** T1SC - TIM1 Status and Control Register TSC
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


;*** OSCSC - Oscillator Status and Control Register
OSCSC               equ       $00000036           ;*** OSCSC - Oscillator Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSCSC_ECGST         equ       0                   ; External Clock Status Bit
OSCSC_ECGON         equ       1                   ; External Clock Generator On Bit
OSCSC_ECFS0         equ       2                   ; External Clock Frequency Select Bit 0
OSCSC_ECFS1         equ       3                   ; External Clock Frequency Select Bit 1
OSCSC_ICFS0         equ       4                   ; Internal Clock Frequency Select Bit 0
OSCSC_ICFS1         equ       5                   ; Internal Clock Frequency Select Bit 1
OSCSC_OSCOPT0       equ       6                   ; OSC Option Bit 0
OSCSC_OSCOPT1       equ       7                   ; OSC Option Bit 1
; bit position masks
mOSCSC_ECGST        equ       %00000001
mOSCSC_ECGON        equ       %00000010
mOSCSC_ECFS0        equ       %00000100
mOSCSC_ECFS1        equ       %00001000
mOSCSC_ICFS0        equ       %00010000
mOSCSC_ICFS1        equ       %00100000
mOSCSC_OSCOPT0      equ       %01000000
mOSCSC_OSCOPT1      equ       %10000000


;*** OSCTRIM - Oscillator Trim Register
OSCTRIM             equ       $00000038           ;*** OSCTRIM - Oscillator Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSCTRIM_TRIM0       equ       0                   ; Oscillator Trim Bit 0
OSCTRIM_TRIM1       equ       1                   ; Oscillator Trim Bit 1
OSCTRIM_TRIM2       equ       2                   ; Oscillator Trim Bit 2
OSCTRIM_TRIM3       equ       3                   ; Oscillator Trim Bit 3
OSCTRIM_TRIM4       equ       4                   ; Oscillator Trim Bit 4
OSCTRIM_TRIM5       equ       5                   ; Oscillator Trim Bit 5
OSCTRIM_TRIM6       equ       6                   ; Oscillator Trim Bit 6
OSCTRIM_TRIM7       equ       7                   ; Oscillator Trim Bit 7
; bit position masks
mOSCTRIM_TRIM0      equ       %00000001
mOSCTRIM_TRIM1      equ       %00000010
mOSCTRIM_TRIM2      equ       %00000100
mOSCTRIM_TRIM3      equ       %00001000
mOSCTRIM_TRIM4      equ       %00010000
mOSCTRIM_TRIM5      equ       %00100000
mOSCTRIM_TRIM6      equ       %01000000
mOSCTRIM_TRIM7      equ       %10000000


;*** ADSCR - ADC10 Status and Control Register
ADSCR               equ       $0000003C           ;*** ADSCR - ADC10 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSCR_ADCH0         equ       0                   ; ADC10 Channel Select Bit 0
ADSCR_ADCH1         equ       1                   ; ADC10 Channel Select Bit 1
ADSCR_ADCH2         equ       2                   ; ADC10 Channel Select Bit 2
ADSCR_ADCH3         equ       3                   ; ADC10 Channel Select Bit 3
ADSCR_ADCH4         equ       4                   ; ADC10 Channel Select Bit 4
ADSCR_ADCO          equ       5                   ; ADC10 Continuous Conversion Bit
ADSCR_AIEN          equ       6                   ; ADC10 Interrupt Enable Bit
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


;*** ADR - ADC10 Data Register - Right-justified
ADR                 equ       $0000003D           ;*** ADR - ADC10 Data Register - Right-justified


;*** ADRH - ADC10 Data Register High - Right-justified mode
ADRH                equ       $0000003D           ;*** ADRH - ADC10 Data Register High - Right-justified mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_AD8            equ       0                   ; ADC10 Data Bit 8
ADRH_AD9            equ       1                   ; ADC10 Data Bit 9
; bit position masks
mADRH_AD8           equ       %00000001
mADRH_AD9           equ       %00000010


;*** ADRL - ADC10 Data Register Low - Right-justified mode
ADRL                equ       $0000003E           ;*** ADRL - ADC10 Data Register Low - Right-justified mode
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRL_AD0            equ       0                   ; ADC10 Data Bit 0
ADRL_AD1            equ       1                   ; ADC10 Data Bit 1
ADRL_AD2            equ       2                   ; ADC10 Data Bit 2
ADRL_AD3            equ       3                   ; ADC10 Data Bit 3
ADRL_AD4            equ       4                   ; ADC10 Data Bit 4
ADRL_AD5            equ       5                   ; ADC10 Data Bit 5
ADRL_AD6            equ       6                   ; ADC10 Data Bit 6
ADRL_AD7            equ       7                   ; ADC10 Data Bit 7
; bit position masks
mADRL_AD0           equ       %00000001
mADRL_AD1           equ       %00000010
mADRL_AD2           equ       %00000100
mADRL_AD3           equ       %00001000
mADRL_AD4           equ       %00010000
mADRL_AD5           equ       %00100000
mADRL_AD6           equ       %01000000
mADRL_AD7           equ       %10000000


;*** ADCLK - ADC Input Clock Register
ADCLK               equ       $0000003F           ;*** ADCLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_ACLKEN        equ       0                   ; Asynchronous Clock Source Enable
ADCLK_ADLSMP        equ       1                   ; Long Sample Time Configuration
ADCLK_MODE0         equ       2                   ; 10- or 8-Bit or External-Triggered Mode Selection Bit 0
ADCLK_MODE1         equ       3                   ; 10- or 8-Bit or External-Triggered Mode Selection Bit 1
ADCLK_ADICLK        equ       4                   ; Input Clock Select Bit
ADCLK_ADIV0         equ       5                   ; ADC10 Clock Divider Bit 0
ADCLK_ADIV1         equ       6                   ; ADC10 Clock Divider Bit 1
ADCLK_ADLPC         equ       7                   ; ADC10 Low-Power Configuration Bit
; bit position masks
mADCLK_ACLKEN       equ       %00000001
mADCLK_ADLSMP       equ       %00000010
mADCLK_MODE0        equ       %00000100
mADCLK_MODE1        equ       %00001000
mADCLK_ADICLK       equ       %00010000
mADCLK_ADIV0        equ       %00100000
mADCLK_ADIV1        equ       %01000000
mADCLK_ADLPC        equ       %10000000


;*** SLCC1 - SLIC Control Register 1
SLCC1               equ       $00000040           ;*** SLCC1 - SLIC Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCC1_SLCIE         equ       0                   ; SLIC Interrupt Enable
SLCC1_IMSG          equ       1                   ; SLIC Ignore Message Bit
SLCC1_TXABRT        equ       2                   ; Transmit Abort Message
SLCC1_WAKETX        equ       3                   ; Transmit Wakeup Symbol
SLCC1_BEDD          equ       4                   ; Bit Error Detection Disable
SLCC1_INITREQ       equ       5                   ; Initialization Request
; bit position masks
mSLCC1_SLCIE        equ       %00000001
mSLCC1_IMSG         equ       %00000010
mSLCC1_TXABRT       equ       %00000100
mSLCC1_WAKETX       equ       %00001000
mSLCC1_BEDD         equ       %00010000
mSLCC1_INITREQ      equ       %00100000


;*** SLCC2 - SLIC Control Register 2
SLCC2               equ       $00000041           ;*** SLCC2 - SLIC Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCC2_SLCE          equ       0                   ; SLIC Module Enable
SLCC2_BTM           equ       2                   ; UART Byte Transfer Mode
SLCC2_SLCWCM        equ       3                   ; SLIC Wait Clock Mode
; bit position masks
mSLCC2_SLCE         equ       %00000001
mSLCC2_BTM          equ       %00000100
mSLCC2_SLCWCM       equ       %00001000


;*** SLCS - SLIC Status Register
SLCS                equ       $00000042           ;*** SLCS - SLIC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCS_SLCF           equ       0                   ; SLIC Interrupt Flag
SLCS_INITACK        equ       5                   ; Initialization Mode Acknowledge
SLCS_SLCACT         equ       7                   ; SLIC Active (Oscillator Trim Blocking Semaphore)
; bit position masks
mSLCS_SLCF          equ       %00000001
mSLCS_INITACK       equ       %00100000
mSLCS_SLCACT        equ       %10000000


;*** SLCP - SLIC Prescale Register
SLCP                equ       $00000043           ;*** SLCP - SLIC Prescale Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCP_RXFP0          equ       6                   ; Digital Receive Filter Clock Prescaler Bit 0
SLCP_RXFP1          equ       7                   ; Digital Receive Filter Clock Prescaler Bit 1
; bit position masks
mSLCP_RXFP0         equ       %01000000
mSLCP_RXFP1         equ       %10000000


;*** SLCBT - SLIC Bit Time Register
SLCBT               equ       $00000044           ;*** SLCBT - SLIC Bit Time Register


;*** SLCBTH - SLIC Bit Time Register High
SLCBTH              equ       $00000044           ;*** SLCBTH - SLIC Bit Time Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCBTH_BT8          equ       0                   ; SLIC Bit Time Register Bit 8
SLCBTH_BT9          equ       1                   ; SLIC Bit Time Register Bit 9
SLCBTH_BT10         equ       2                   ; SLIC Bit Time Register Bit 10
SLCBTH_BT11         equ       3                   ; SLIC Bit Time Register Bit 11
SLCBTH_BT12         equ       4                   ; SLIC Bit Time Register Bit 12
; bit position masks
mSLCBTH_BT8         equ       %00000001
mSLCBTH_BT9         equ       %00000010
mSLCBTH_BT10        equ       %00000100
mSLCBTH_BT11        equ       %00001000
mSLCBTH_BT12        equ       %00010000


;*** SLCBTL - SLIC Bit Time Register Low
SLCBTL              equ       $00000045           ;*** SLCBTL - SLIC Bit Time Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCBTL_BT1          equ       1                   ; SLIC Bit Time Register Bit 1
SLCBTL_BT2          equ       2                   ; SLIC Bit Time Register Bit 2
SLCBTL_BT3          equ       3                   ; SLIC Bit Time Register Bit 3
SLCBTL_BT4          equ       4                   ; SLIC Bit Time Register Bit 4
SLCBTL_BT5          equ       5                   ; SLIC Bit Time Register Bit 5
SLCBTL_BT6          equ       6                   ; SLIC Bit Time Register Bit 6
SLCBTL_BT7          equ       7                   ; SLIC Bit Time Register Bit 7
; bit position masks
mSLCBTL_BT1         equ       %00000010
mSLCBTL_BT2         equ       %00000100
mSLCBTL_BT3         equ       %00001000
mSLCBTL_BT4         equ       %00010000
mSLCBTL_BT5         equ       %00100000
mSLCBTL_BT6         equ       %01000000
mSLCBTL_BT7         equ       %10000000


;*** SLCSV - SLIC State Vector Register
SLCSV               equ       $00000046           ;*** SLCSV - SLIC State Vector Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCSV_I0            equ       2                   ; Interrupt State Vector Bit 0
SLCSV_I1            equ       3                   ; Interrupt State Vector Bit 1
SLCSV_I2            equ       4                   ; Interrupt State Vector Bit 2
SLCSV_I3            equ       5                   ; Interrupt State Vector Bit 3
; bit position masks
mSLCSV_I0           equ       %00000100
mSLCSV_I1           equ       %00001000
mSLCSV_I2           equ       %00010000
mSLCSV_I3           equ       %00100000


;*** SLCDLC - SLIC Data Length Code Register
SLCDLC              equ       $00000047           ;*** SLCDLC - SLIC Data Length Code Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCDLC_DLC0         equ       0                   ; Data Length Control Bit 0
SLCDLC_DLC1         equ       1                   ; Data Length Control Bit 1
SLCDLC_DLC2         equ       2                   ; Data Length Control Bit 2
SLCDLC_DLC3         equ       3                   ; Data Length Control Bit 3
SLCDLC_DLC4         equ       4                   ; Data Length Control Bit 4
SLCDLC_DLC5         equ       5                   ; Data Length Control Bit 5
SLCDLC_CHKMOD       equ       6                   ; LIN Checksum Mode
SLCDLC_TXGO         equ       7                   ; SLIC Transmit Go
; bit position masks
mSLCDLC_DLC0        equ       %00000001
mSLCDLC_DLC1        equ       %00000010
mSLCDLC_DLC2        equ       %00000100
mSLCDLC_DLC3        equ       %00001000
mSLCDLC_DLC4        equ       %00010000
mSLCDLC_DLC5        equ       %00100000
mSLCDLC_CHKMOD      equ       %01000000
mSLCDLC_TXGO        equ       %10000000


;*** SLCID - SLIC Identifier Register
SLCID               equ       $00000048           ;*** SLCID - SLIC Identifier Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCID_R0_T0         equ       0                   ; SLIC Identifier Bit 0
SLCID_R1_T1         equ       1                   ; SLIC Identifier Bit 1
SLCID_R2_T2         equ       2                   ; SLIC Identifier Bit 2
SLCID_R3_T3         equ       3                   ; SLIC Identifier Bit 3
SLCID_R4_T4         equ       4                   ; SLIC Identifier Bit 4
SLCID_R5_T5         equ       5                   ; SLIC Identifier Bit 5
SLCID_R6_T6         equ       6                   ; SLIC Identifier Bit 6
SLCID_R7_T7         equ       7                   ; SLIC Identifier Bit 7
; bit position masks
mSLCID_R0_T0        equ       %00000001
mSLCID_R1_T1        equ       %00000010
mSLCID_R2_T2        equ       %00000100
mSLCID_R3_T3        equ       %00001000
mSLCID_R4_T4        equ       %00010000
mSLCID_R5_T5        equ       %00100000
mSLCID_R6_T6        equ       %01000000
mSLCID_R7_T7        equ       %10000000


;*** SLCD7 - SLIC Data Register 7
SLCD7               equ       $00000049           ;*** SLCD7 - SLIC Data Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD7_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD7_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD7_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD7_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD7_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD7_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD7_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD7_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD7_R0_T0        equ       %00000001
mSLCD7_R1_T1        equ       %00000010
mSLCD7_R2_T2        equ       %00000100
mSLCD7_R3_T3        equ       %00001000
mSLCD7_R4_T4        equ       %00010000
mSLCD7_R5_T5        equ       %00100000
mSLCD7_R6_T6        equ       %01000000
mSLCD7_R7_T7        equ       %10000000


;*** SLCD6 - SLIC Data Register 6
SLCD6               equ       $0000004A           ;*** SLCD6 - SLIC Data Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD6_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD6_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD6_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD6_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD6_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD6_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD6_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD6_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD6_R0_T0        equ       %00000001
mSLCD6_R1_T1        equ       %00000010
mSLCD6_R2_T2        equ       %00000100
mSLCD6_R3_T3        equ       %00001000
mSLCD6_R4_T4        equ       %00010000
mSLCD6_R5_T5        equ       %00100000
mSLCD6_R6_T6        equ       %01000000
mSLCD6_R7_T7        equ       %10000000


;*** SLCD5 - SLIC Data Register 5
SLCD5               equ       $0000004B           ;*** SLCD5 - SLIC Data Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD5_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD5_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD5_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD5_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD5_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD5_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD5_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD5_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD5_R0_T0        equ       %00000001
mSLCD5_R1_T1        equ       %00000010
mSLCD5_R2_T2        equ       %00000100
mSLCD5_R3_T3        equ       %00001000
mSLCD5_R4_T4        equ       %00010000
mSLCD5_R5_T5        equ       %00100000
mSLCD5_R6_T6        equ       %01000000
mSLCD5_R7_T7        equ       %10000000


;*** SLCD4 - SLIC Data Register 4
SLCD4               equ       $0000004C           ;*** SLCD4 - SLIC Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD4_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD4_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD4_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD4_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD4_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD4_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD4_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD4_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD4_R0_T0        equ       %00000001
mSLCD4_R1_T1        equ       %00000010
mSLCD4_R2_T2        equ       %00000100
mSLCD4_R3_T3        equ       %00001000
mSLCD4_R4_T4        equ       %00010000
mSLCD4_R5_T5        equ       %00100000
mSLCD4_R6_T6        equ       %01000000
mSLCD4_R7_T7        equ       %10000000


;*** SLCD3 - SLIC Data Register 3
SLCD3               equ       $0000004D           ;*** SLCD3 - SLIC Data Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD3_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD3_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD3_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD3_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD3_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD3_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD3_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD3_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD3_R0_T0        equ       %00000001
mSLCD3_R1_T1        equ       %00000010
mSLCD3_R2_T2        equ       %00000100
mSLCD3_R3_T3        equ       %00001000
mSLCD3_R4_T4        equ       %00010000
mSLCD3_R5_T5        equ       %00100000
mSLCD3_R6_T6        equ       %01000000
mSLCD3_R7_T7        equ       %10000000


;*** SLCD2 - SLIC Data Register 2
SLCD2               equ       $0000004E           ;*** SLCD2 - SLIC Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD2_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD2_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD2_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD2_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD2_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD2_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD2_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD2_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD2_R0_T0        equ       %00000001
mSLCD2_R1_T1        equ       %00000010
mSLCD2_R2_T2        equ       %00000100
mSLCD2_R3_T3        equ       %00001000
mSLCD2_R4_T4        equ       %00010000
mSLCD2_R5_T5        equ       %00100000
mSLCD2_R6_T6        equ       %01000000
mSLCD2_R7_T7        equ       %10000000


;*** SLCD1 - SLIC Data Register 1
SLCD1               equ       $0000004F           ;*** SLCD1 - SLIC Data Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD1_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD1_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD1_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD1_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD1_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD1_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD1_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD1_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD1_R0_T0        equ       %00000001
mSLCD1_R1_T1        equ       %00000010
mSLCD1_R2_T2        equ       %00000100
mSLCD1_R3_T3        equ       %00001000
mSLCD1_R4_T4        equ       %00010000
mSLCD1_R5_T5        equ       %00100000
mSLCD1_R6_T6        equ       %01000000
mSLCD1_R7_T7        equ       %10000000


;*** SLCD0 - SLIC Data Register 0
SLCD0               equ       $00000050           ;*** SLCD0 - SLIC Data Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SLCD0_R0_T0         equ       0                   ; SLIC Data Bit 0
SLCD0_R1_T1         equ       1                   ; SLIC Data Bit 1
SLCD0_R2_T2         equ       2                   ; SLIC Data Bit 2
SLCD0_R3_T3         equ       3                   ; SLIC Data Bit 3
SLCD0_R4_T4         equ       4                   ; SLIC Data Bit 4
SLCD0_R5_T5         equ       5                   ; SLIC Data Bit 5
SLCD0_R6_T6         equ       6                   ; SLIC Data Bit 6
SLCD0_R7_T7         equ       7                   ; SLIC Data Bit 7
; bit position masks
mSLCD0_R0_T0        equ       %00000001
mSLCD0_R1_T1        equ       %00000010
mSLCD0_R2_T2        equ       %00000100
mSLCD0_R3_T3        equ       %00001000
mSLCD0_R4_T4        equ       %00010000
mSLCD0_R5_T5        equ       %00100000
mSLCD0_R6_T6        equ       %01000000
mSLCD0_R7_T7        equ       %10000000


;*** T2SC - TIM1 Status and Control Register TSC
T2SC                equ       $00000060           ;*** T2SC - TIM1 Status and Control Register TSC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
T2SC_PS0            equ       0                   ; Prescaler Select Bit 0
T2SC_PS1            equ       1                   ; Prescaler Select Bit 1
T2SC_PS2            equ       2                   ; Prescaler Select Bit 2
T2SC_TRST           equ       4                   ; TIM1 Reset Bit
T2SC_TSTOP          equ       5                   ; TIM1 Stop Bit
T2SC_TOIE           equ       6                   ; TIM1 Overflow Interrupt Enable Bit
T2SC_TOF            equ       7                   ; TIM1 Overflow Flag Bit
; bit position masks
mT2SC_PS0           equ       %00000001
mT2SC_PS1           equ       %00000010
mT2SC_PS2           equ       %00000100
mT2SC_TRST          equ       %00010000
mT2SC_TSTOP         equ       %00100000
mT2SC_TOIE          equ       %01000000
mT2SC_TOF           equ       %10000000


;*** T2CNT - TIM1 Counter Register
T2CNT               equ       $00000061           ;*** T2CNT - TIM1 Counter Register


;*** T2CNTH - TIM1 Counter Register High
T2CNTH              equ       $00000061           ;*** T2CNTH - TIM1 Counter Register High


;*** T2CNTL - TIM1 Counter Register Low
T2CNTL              equ       $00000062           ;*** T2CNTL - TIM1 Counter Register Low


;*** T2MOD - TIM1 Counter Modulo Register
T2MOD               equ       $00000063           ;*** T2MOD - TIM1 Counter Modulo Register


;*** T2MODH - TIM1 Counter Modulo Register High
T2MODH              equ       $00000063           ;*** T2MODH - TIM1 Counter Modulo Register High


;*** T2MODL - TIM1 Counter Modulo Register Low
T2MODL              equ       $00000064           ;*** T2MODL - TIM1 Counter Modulo Register Low


;*** T2SC0 - TIM1 Channel 0 Status and Control Register
T2SC0               equ       $00000065           ;*** T2SC0 - TIM1 Channel 0 Status and Control Register
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


;*** T2CH0 - TIM1 Channel 0 Register
T2CH0               equ       $00000066           ;*** T2CH0 - TIM1 Channel 0 Register


;*** T2CH0H - TIM1 Channel 0 Register High
T2CH0H              equ       $00000066           ;*** T2CH0H - TIM1 Channel 0 Register High


;*** T2CH0L - TIM1 Channel 0 Register Low
T2CH0L              equ       $00000067           ;*** T2CH0L - TIM1 Channel 0 Register Low


;*** T2SC1 - TIM1 Channel 1 Status and Control Register
T2SC1               equ       $00000068           ;*** T2SC1 - TIM1 Channel 1 Status and Control Register
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


;*** T2CH1 - TIM1 Channel 1 Register
T2CH1               equ       $00000069           ;*** T2CH1 - TIM1 Channel 1 Register


;*** T2CH1H - TIM1 Channel 1 Register High
T2CH1H              equ       $00000069           ;*** T2CH1H - TIM1 Channel 1 Register High


;*** T2CH1L - TIM1 Channel 1 Register Low
T2CH1L              equ       $0000006A           ;*** T2CH1L - TIM1 Channel 1 Register Low


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
SRSR_MODRST         equ       2                   ; Monitor Mode Entry Module Reset bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit (opcode fetches only)
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


;*** BRKAR - Break Auxiliary Register
BRKAR               equ       $0000FE02           ;*** BRKAR - Break Auxiliary Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKAR_BDCOP         equ       0                   ; Break Disable COP Bit
; bit position masks
mBRKAR_BDCOP        equ       %00000001


;*** BFCR - SIM Break Flag Control Register
BFCR                equ       $0000FE03           ;*** BFCR - SIM Break Flag Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BFCR_BCFE           equ       7                   ; Break Clear Flag Enable Bit
; bit position masks
mBFCR_BCFE          equ       %10000000


;*** INT1 - Interrupt Status Register 1
INT1                equ       $0000FE04           ;*** INT1 - Interrupt Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INT1_IF1            equ       2                   ; Interrupt Flag 1
INT1_IF3            equ       4                   ; Interrupt Flag 3
INT1_IF4            equ       5                   ; Interrupt Flag 4
INT1_IF5            equ       6                   ; Interrupt Flag 5
INT1_IF6            equ       7                   ; Interrupt Flag 6
; bit position masks
mINT1_IF1           equ       %00000100
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
INT3_IF19           equ       4                   ; Interrupt Flag 19
INT3_IF20           equ       5                   ; Interrupt Flag 20
INT3_IF21           equ       6                   ; Interrupt Flag 21
INT3_IF22           equ       7                   ; Interrupt Flag 22
; bit position masks
mINT3_IF15          equ       %00000001
mINT3_IF16          equ       %00000010
mINT3_IF17          equ       %00000100
mINT3_IF18          equ       %00001000
mINT3_IF19          equ       %00010000
mINT3_IF20          equ       %00100000
mINT3_IF21          equ       %01000000
mINT3_IF22          equ       %10000000


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
FLBPR               equ       $0000FFBE           ;*** FLBPR - FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR1          equ       1                   ; Block Protect Register Bit 1
FLBPR_BPR2          equ       2                   ; Block Protect Register Bit 2
FLBPR_BPR3          equ       3                   ; Block Protect Register Bit 3
FLBPR_BPR4          equ       4                   ; Block Protect Register Bit 4
FLBPR_BPR5          equ       5                   ; Block Protect Register Bit 5
FLBPR_BPR6          equ       6                   ; Block Protect Register Bit 6
FLBPR_BPR7          equ       7                   ; Block Protect Register Bit 7
; bit position masks
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000
mFLBPR_BPR4         equ       %00010000
mFLBPR_BPR5         equ       %00100000
mFLBPR_BPR6         equ       %01000000
mFLBPR_BPR7         equ       %10000000


;*** Optional - Internal Oscillator Trim
Optional            equ       $0000FFC0           ;*** Optional - Internal Oscillator Trim
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
Optional_TRIM0      equ       0                   ; ICG Trim Factor Bit 0
Optional_TRIM1      equ       1                   ; ICG Trim Factor Bit 1
Optional_TRIM2      equ       2                   ; ICG Trim Factor Bit 2
Optional_TRIM3      equ       3                   ; ICG Trim Factor Bit 3
Optional_TRIM4      equ       4                   ; ICG Trim Factor Bit 4
Optional_TRIM5      equ       5                   ; ICG Trim Factor Bit 5
Optional_TRIM6      equ       6                   ; ICG Trim Factor Bit 6
Optional_TRIM7      equ       7                   ; ICG Trim Factor Bit 7
; bit position masks
mOptional_TRIM0     equ       %00000001
mOptional_TRIM1     equ       %00000010
mOptional_TRIM2     equ       %00000100
mOptional_TRIM3     equ       %00001000
mOptional_TRIM4     equ       %00010000
mOptional_TRIM5     equ       %00100000
mOptional_TRIM6     equ       %01000000
mOptional_TRIM7     equ       %10000000


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
