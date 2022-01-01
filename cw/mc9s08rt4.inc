;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08RT16_24, version 2.87.213 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08rt4.inc
;     Processor : MC9S08RT4
;     FileFormat: V2.32
;     DataSheet : MC9S08RT16 Rev. 0.07 7/2005
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 13:44
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
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
;               - Duplication of bit (or bit-group) name with register name is not marked as a problem, if register is internal only and it is not displayed in I/O map.
;      - 17.3.2009, V2.27 :
;               - Merged bit-group is not generated, if the name matches with another bit name in the register
;      - 6.4.2009, V2.28 :
;               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
;      - 3.8.2009, V2.29 :
;               - If there is just one bits group matching register name, single bits are not generated
;      - 10.9.2009, V2.30 :
;               - Fixed generation of registers arrays.
;      - 15.10.2009, V2.31 :
;               - HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
;      - 18.05.2010, V2.32 :
;               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000F000
ROM_END             equ       $0000FFAF
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000015F
XROM                equ       $0000FFC0
XROM_END            equ       $0000FFE1
;
Vpci                equ       $0000FFE2
Vmdr                equ       $0000FFE4
Vrti                equ       $0000FFE6
Vlfrcvr             equ       $0000FFE8
Vadc                equ       $0000FFEA
Reserved5           equ       $0000FFEC
Vspi                equ       $0000FFEE
Vtpmovf             equ       $0000FFF0
Vtpmch1             equ       $0000FFF2
Vtpmch0             equ       $0000FFF4
Vwuktmr             equ       $0000FFF6
Vlvd                equ       $0000FFF8
Virq                equ       $0000FFFA
Vswi                equ       $0000FFFC
Vreset              equ       $0000FFFE
;

;*** PTAD - Port A Data Register
PTAD                equ       $00000000           ;*** PTAD - Port A Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAD_PTAD0          equ       0                   ; Port A Data Register Bit 0
PTAD_PTAD1          equ       1                   ; Port A Data Register Bit 1
PTAD_PTAD2          equ       2                   ; Port A Data Register Bit 2
PTAD_PTAD3          equ       3                   ; Port A Data Register Bit 3
PTAD_PTAD4          equ       4                   ; Port A Data Register Bit 4
PTAD_PTAD5          equ       5                   ; Port A Data Register Bit 5
PTAD_PTAD6          equ       6                   ; Port A Data Register Bit 6
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD1         equ       %00000010
mPTAD_PTAD2         equ       %00000100
mPTAD_PTAD3         equ       %00001000
mPTAD_PTAD4         equ       %00010000
mPTAD_PTAD5         equ       %00100000
mPTAD_PTAD6         equ       %01000000

;*** PTAPE - Pullup Enable for Port A
PTAPE               equ       $00000001           ;*** PTAPE - Pullup Enable for Port A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Pullup Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Pullup Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Pullup Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Pullup Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Pullup Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Pullup Enable for Port A Bit 5
PTAPE_PTAPE6        equ       6                   ; Pullup Enable for Port A Bit 6
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000
mPTAPE_PTAPE6       equ       %01000000

;*** PTADD - Data Direction Register A
PTADD               equ       $00000003           ;*** PTADD - Data Direction Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; Data Direction for Port A Bit 0
PTADD_PTADD1        equ       1                   ; Data Direction for Port A Bit 1
PTADD_PTADD2        equ       2                   ; Data Direction for Port A Bit 2
PTADD_PTADD3        equ       3                   ; Data Direction for Port A Bit 3
PTADD_PTADD4        equ       4                   ; Data Direction for Port A Bit 4
PTADD_PTADD5        equ       5                   ; Data Direction for Port A Bit 5
PTADD_PTADD6        equ       6                   ; Data Direction for Port A Bit 6
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000
mPTADD_PTADD4       equ       %00010000
mPTADD_PTADD5       equ       %00100000
mPTADD_PTADD6       equ       %01000000

;*** PTBD - Port B Data Register
PTBD                equ       $00000004           ;*** PTBD - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBD_PTBD0          equ       0                   ; Port B Data Register Bit 0
PTBD_PTBD1          equ       1                   ; Port B Data Register Bit 1
PTBD_PTBD2          equ       2                   ; Port B Data Register Bit 2
PTBD_PTBD3          equ       3                   ; Port B Data Register Bit 3
PTBD_PTBD4          equ       4                   ; Port B Data Register Bit 4
PTBD_PTBD5          equ       5                   ; Port B Data Register Bit 5
; bit position masks
mPTBD_PTBD0         equ       %00000001
mPTBD_PTBD1         equ       %00000010
mPTBD_PTBD2         equ       %00000100
mPTBD_PTBD3         equ       %00001000
mPTBD_PTBD4         equ       %00010000
mPTBD_PTBD5         equ       %00100000

;*** PTBPE - Pullup Enable for Port B
PTBPE               equ       $00000005           ;*** PTBPE - Pullup Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Pullup Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Pullup Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Pullup Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Pullup Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Pullup Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Pullup Enable for Port B Bit 5
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000

;*** PTBDD - Data Direction Register B
PTBDD               equ       $00000007           ;*** PTBDD - Data Direction Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0        equ       0                   ; Data Direction for Port B Bit 0
PTBDD_PTBDD1        equ       1                   ; Data Direction for Port B Bit 1
PTBDD_PTBDD2        equ       2                   ; Data Direction for Port B Bit 2
PTBDD_PTBDD3        equ       3                   ; Data Direction for Port B Bit 3
PTBDD_PTBDD4        equ       4                   ; Data Direction for Port B Bit 4
PTBDD_PTBDD5        equ       5                   ; Data Direction for Port B Bit 5
; bit position masks
mPTBDD_PTBDD0       equ       %00000001
mPTBDD_PTBDD1       equ       %00000010
mPTBDD_PTBDD2       equ       %00000100
mPTBDD_PTBDD3       equ       %00001000
mPTBDD_PTBDD4       equ       %00010000
mPTBDD_PTBDD5       equ       %00100000

;*** PTCD - Port C Data Register
PTCD                equ       $00000008           ;*** PTCD - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0          equ       0                   ; Port C Data Register Bit 0
PTCD_PTCD1          equ       1                   ; Port C Data Register Bit 1
; bit position masks
mPTCD_PTCD0         equ       %00000001
mPTCD_PTCD1         equ       %00000010

;*** PTCPE - Pullup Enable for Port C
PTCPE               equ       $00000009           ;*** PTCPE - Pullup Enable for Port C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Pullup Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Pullup Enable for Port C Bit 1
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010

;*** PTCDD - Data Direction Register C
PTCDD               equ       $0000000B           ;*** PTCDD - Data Direction Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; Data Direction for Port C Bit 0
PTCDD_PTCDD1        equ       1                   ; Data Direction for Port C Bit 1
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010

;*** IRQSC - Interrupt Request Status and Control Register
IRQSC               equ       $0000000C           ;*** IRQSC - Interrupt Request Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD        equ       0                   ; IRQ Detection Mode
IRQSC_IRQIE         equ       1                   ; IRQ Interrupt Enable
IRQSC_IRQACK        equ       2                   ; IRQ Acknowledge
IRQSC_IRQF          equ       3                   ; IRQ Flag
IRQSC_IRQPE         equ       4                   ; IRQ Pin Enable
IRQSC_IRQEDG        equ       5                   ; Interrupt Request (IRQ) Edge Select
; bit position masks
mIRQSC_IRQMOD       equ       %00000001
mIRQSC_IRQIE        equ       %00000010
mIRQSC_IRQACK       equ       %00000100
mIRQSC_IRQF         equ       %00001000
mIRQSC_IRQPE        equ       %00010000
mIRQSC_IRQEDG       equ       %00100000

;*** TPMSC - TPM 1 Status and Control Register
TPMSC               equ       $00000010           ;*** TPMSC - TPM 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMSC_PS0           equ       0                   ; Prescale Divisor Select Bit 0
TPMSC_PS1           equ       1                   ; Prescale Divisor Select Bit 1
TPMSC_PS2           equ       2                   ; Prescale Divisor Select Bit 2
TPMSC_CLKSA         equ       3                   ; Clock Source Select A
TPMSC_CLKSB         equ       4                   ; Clock Source Select B
TPMSC_CPWMS         equ       5                   ; Center-Aligned PWM Select
TPMSC_TOIE          equ       6                   ; Timer Overflow Interrupt Enable
TPMSC_TOF           equ       7                   ; Timer Overflow Flag
; bit position masks
mTPMSC_PS0          equ       %00000001
mTPMSC_PS1          equ       %00000010
mTPMSC_PS2          equ       %00000100
mTPMSC_CLKSA        equ       %00001000
mTPMSC_CLKSB        equ       %00010000
mTPMSC_CPWMS        equ       %00100000
mTPMSC_TOIE         equ       %01000000
mTPMSC_TOF          equ       %10000000

;*** TPMCNT - TPM 1 Counter Register
TPMCNT              equ       $00000011           ;*** TPMCNT - TPM 1 Counter Register

;*** TPMCNTH - TPM 1 Counter Register High
TPMCNTH             equ       $00000011           ;*** TPMCNTH - TPM 1 Counter Register High

;*** TPMCNTL - TPM 1 Counter Register Low
TPMCNTL             equ       $00000012           ;*** TPMCNTL - TPM 1 Counter Register Low

;*** TPMMOD - TPM 1 Timer Counter Modulo Register
TPMMOD              equ       $00000013           ;*** TPMMOD - TPM 1 Timer Counter Modulo Register

;*** TPMMODH - TPM 1 Timer Counter Modulo Register High
TPMMODH             equ       $00000013           ;*** TPMMODH - TPM 1 Timer Counter Modulo Register High

;*** TPMMODL - TPM 1 Timer Counter Modulo Register Low
TPMMODL             equ       $00000014           ;*** TPMMODL - TPM 1 Timer Counter Modulo Register Low

;*** TPMC0SC - TPM 1 Timer Channel 0 Status and Control Register
TPMC0SC             equ       $00000015           ;*** TPMC0SC - TPM 1 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMC0SC_ELS0A       equ       2                   ; Edge/Level Select Bit A
TPMC0SC_ELS0B       equ       3                   ; Edge/Level Select Bit B
TPMC0SC_MS0A        equ       4                   ; Mode Select A for TPM Channel 0
TPMC0SC_MS0B        equ       5                   ; Mode Select B for TPM Channel 0
TPMC0SC_CH0IE       equ       6                   ; Channel 0 Interrupt Enable
TPMC0SC_CH0F        equ       7                   ; Channel 0 Flag
; bit position masks
mTPMC0SC_ELS0A      equ       %00000100
mTPMC0SC_ELS0B      equ       %00001000
mTPMC0SC_MS0A       equ       %00010000
mTPMC0SC_MS0B       equ       %00100000
mTPMC0SC_CH0IE      equ       %01000000
mTPMC0SC_CH0F       equ       %10000000

;*** TPMC0V - TPM 1 Timer Channel 0 Value Register
TPMC0V              equ       $00000016           ;*** TPMC0V - TPM 1 Timer Channel 0 Value Register

;*** TPMC0VH - TPM 1 Timer Channel 0 Value Register High
TPMC0VH             equ       $00000016           ;*** TPMC0VH - TPM 1 Timer Channel 0 Value Register High

;*** TPMC0VL - TPM 1 Timer Channel 0 Value Register Low
TPMC0VL             equ       $00000017           ;*** TPMC0VL - TPM 1 Timer Channel 0 Value Register Low

;*** TPMC1SC - TPM 1 Timer Channel 1 Status and Control Register
TPMC1SC             equ       $00000018           ;*** TPMC1SC - TPM 1 Timer Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPMC1SC_ELS1A       equ       2                   ; Edge/Level Select Bit A
TPMC1SC_ELS1B       equ       3                   ; Edge/Level Select Bit B
TPMC1SC_MS1A        equ       4                   ; Mode Select A for TPM Channel 1
TPMC1SC_MS1B        equ       5                   ; Mode Select B for TPM Channel 1
TPMC1SC_CH1IE       equ       6                   ; Channel 1 Interrupt Enable
TPMC1SC_CH1F        equ       7                   ; Channel 1 Flag
; bit position masks
mTPMC1SC_ELS1A      equ       %00000100
mTPMC1SC_ELS1B      equ       %00001000
mTPMC1SC_MS1A       equ       %00010000
mTPMC1SC_MS1B       equ       %00100000
mTPMC1SC_CH1IE      equ       %01000000
mTPMC1SC_CH1F       equ       %10000000

;*** TPMC1V - TPM 1 Timer Channel 1 Value Register
TPMC1V              equ       $00000019           ;*** TPMC1V - TPM 1 Timer Channel 1 Value Register

;*** TPMC1VH - TPM 1 Timer Channel 1 Value Register High
TPMC1VH             equ       $00000019           ;*** TPMC1VH - TPM 1 Timer Channel 1 Value Register High

;*** TPMC1VL - TPM 1 Timer Channel 1 Value Register Low
TPMC1VL             equ       $0000001A           ;*** TPMC1VL - TPM 1 Timer Channel 1 Value Register Low

;*** PCICS - PCI Control/Status Register
PCICS               equ       $0000001C           ;*** PCICS - PCI Control/Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCICS_PCD0          equ       0                   ; Power Up Delay Bit 0
PCICS_PCD1          equ       1                   ; Power Up Delay Bit 1
PCICS_PCIPEN        equ       3                   ; The PCIPEN bit enables the PCI to control the pin functions going to the P-Chip
PCICS_PEN           equ       4                   ; Pressure Measurement Enable
PCICS_PCIIE         equ       5                   ; PCI Interrupt Enable.
PCICS_PCIFAK        equ       6                   ; Acknowledge PCIF Interrupt Flag
PCICS_PCIF          equ       7                   ; PCI Interrupt Flag
; bit position masks
mPCICS_PCD0         equ       %00000001
mPCICS_PCD1         equ       %00000010
mPCICS_PCIPEN       equ       %00001000
mPCICS_PEN          equ       %00010000
mPCICS_PCIIE        equ       %00100000
mPCICS_PCIFAK       equ       %01000000
mPCICS_PCIF         equ       %10000000

;*** PCIC - P-Chip Interface Control Register
PCIC                equ       $0000001D           ;*** PCIC - P-Chip Interface Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCIC_PRST           equ       2                   ; PCI Reset
PCIC_PTRIM          equ       5                   ; P-Chip Trim Update
PCIC_PCAP           equ       6                   ; Pressure Capture
PCIC_PCIEN          equ       7                   ; PCI Enable
; bit position masks
mPCIC_PRST          equ       %00000100
mPCIC_PTRIM         equ       %00100000
mPCIC_PCAP          equ       %01000000
mPCIC_PCIEN         equ       %10000000

;*** SPIC1 - SPI Control Register 1
SPIC1               equ       $00000020           ;*** SPIC1 - SPI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC1_LSBFE         equ       0                   ; LSB First (shifter direction)
SPIC1_SSOE          equ       1                   ; Slave Select Output Enable
SPIC1_CPHA          equ       2                   ; Clock Phase
SPIC1_CPOL          equ       3                   ; Clock Polarity
SPIC1_MSTR          equ       4                   ; Master/Slave Mode Select
SPIC1_SPTIE         equ       5                   ; SPI Transmit Interrupt Enable
SPIC1_SPE           equ       6                   ; SPI System Enable
SPIC1_SPIE          equ       7                   ; SPI Interrupt Enable
; bit position masks
mSPIC1_LSBFE        equ       %00000001
mSPIC1_SSOE         equ       %00000010
mSPIC1_CPHA         equ       %00000100
mSPIC1_CPOL         equ       %00001000
mSPIC1_MSTR         equ       %00010000
mSPIC1_SPTIE        equ       %00100000
mSPIC1_SPE          equ       %01000000
mSPIC1_SPIE         equ       %10000000

;*** SPIC2 - SPI Control Register 2
SPIC2               equ       $00000021           ;*** SPIC2 - SPI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC2_SPC0          equ       0                   ; SPI Pin Control 0
SPIC2_SPISWAI       equ       1                   ; SPI Stop in Wait Mode
SPIC2_BIDIROE       equ       3                   ; Bidirectional Mode Output Enable
SPIC2_MODFEN        equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPIC2_SPC0         equ       %00000001
mSPIC2_SPISWAI      equ       %00000010
mSPIC2_BIDIROE      equ       %00001000
mSPIC2_MODFEN       equ       %00010000

;*** SPIBR - SPI Baud Rate Register
SPIBR               equ       $00000022           ;*** SPIBR - SPI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIBR_SPR0          equ       0                   ; SPI Baud Rate Divisor Bit 0
SPIBR_SPR1          equ       1                   ; SPI Baud Rate Divisor Bit 1
SPIBR_SPR2          equ       2                   ; SPI Baud Rate Divisor Bit 2
SPIBR_SPPR0         equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPIBR_SPPR1         equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPIBR_SPPR2         equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPIBR_SPR0         equ       %00000001
mSPIBR_SPR1         equ       %00000010
mSPIBR_SPR2         equ       %00000100
mSPIBR_SPPR0        equ       %00010000
mSPIBR_SPPR1        equ       %00100000
mSPIBR_SPPR2        equ       %01000000

;*** SPISR - SPI Status Register
SPISR               equ       $00000023           ;*** SPISR - SPI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPISR_MODF          equ       4                   ; Master Mode Fault Flag
SPISR_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPISR_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPISR_MODF         equ       %00010000
mSPISR_SPTEF        equ       %00100000
mSPISR_SPRF         equ       %10000000

;*** SPIDR - SPI Data Register
SPIDR               equ       $00000025           ;*** SPIDR - SPI Data Register

;*** LFCA0 - LF Wake Up Code A - byte 0 Register
LFCA0               equ       $00000028           ;*** LFCA0 - LF Wake Up Code A - byte 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCA0_LFA0          equ       0                   ; Wake Up Code A Bit 0
LFCA0_LFA1          equ       1                   ; Wake Up Code A Bit 1
LFCA0_LFA2          equ       2                   ; Wake Up Code A Bit 2
LFCA0_LFA3          equ       3                   ; Wake Up Code A Bit 3
LFCA0_LFA4          equ       4                   ; Wake Up Code A Bit 4
LFCA0_LFA5          equ       5                   ; Wake Up Code A Bit 5
LFCA0_LFA6          equ       6                   ; Wake Up Code A Bit 6
LFCA0_LFA7          equ       7                   ; Wake Up Code A Bit 7
; bit position masks
mLFCA0_LFA0         equ       %00000001
mLFCA0_LFA1         equ       %00000010
mLFCA0_LFA2         equ       %00000100
mLFCA0_LFA3         equ       %00001000
mLFCA0_LFA4         equ       %00010000
mLFCA0_LFA5         equ       %00100000
mLFCA0_LFA6         equ       %01000000
mLFCA0_LFA7         equ       %10000000

;*** LFCA1 - LF Wake Up Code A - byte 1 Register
LFCA1               equ       $00000029           ;*** LFCA1 - LF Wake Up Code A - byte 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCA1_LFA8          equ       0                   ; Wake Up Code A Bit 8
LFCA1_LFA9          equ       1                   ; Wake Up Code A Bit 9
LFCA1_LFA10         equ       2                   ; Wake Up Code A Bit 10
LFCA1_LFA11         equ       3                   ; Wake Up Code A Bit 11
LFCA1_LFA12         equ       4                   ; Wake Up Code A Bit 12
LFCA1_LFA13         equ       5                   ; Wake Up Code A Bit 13
LFCA1_LFA14         equ       6                   ; Wake Up Code A Bit 14
LFCA1_LFA15         equ       7                   ; Wake Up Code A Bit 15
; bit position masks
mLFCA1_LFA8         equ       %00000001
mLFCA1_LFA9         equ       %00000010
mLFCA1_LFA10        equ       %00000100
mLFCA1_LFA11        equ       %00001000
mLFCA1_LFA12        equ       %00010000
mLFCA1_LFA13        equ       %00100000
mLFCA1_LFA14        equ       %01000000
mLFCA1_LFA15        equ       %10000000

;*** LFCB0 - LF Wake Up Code B - byte 0 Register
LFCB0               equ       $0000002A           ;*** LFCB0 - LF Wake Up Code B - byte 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCB0_LFB0          equ       0                   ; Wake Up Code B Bit 0
LFCB0_LFB1          equ       1                   ; Wake Up Code B Bit 1
LFCB0_LFB2          equ       2                   ; Wake Up Code B Bit 2
LFCB0_LFB3          equ       3                   ; Wake Up Code B Bit 3
LFCB0_LFB4          equ       4                   ; Wake Up Code B Bit 4
LFCB0_LFB5          equ       5                   ; Wake Up Code B Bit 5
LFCB0_LFB6          equ       6                   ; Wake Up Code B Bit 6
LFCB0_LFB7          equ       7                   ; Wake Up Code B Bit 7
; bit position masks
mLFCB0_LFB0         equ       %00000001
mLFCB0_LFB1         equ       %00000010
mLFCB0_LFB2         equ       %00000100
mLFCB0_LFB3         equ       %00001000
mLFCB0_LFB4         equ       %00010000
mLFCB0_LFB5         equ       %00100000
mLFCB0_LFB6         equ       %01000000
mLFCB0_LFB7         equ       %10000000

;*** LFCB1 - LF Wake Up Code B - byte 1 Register
LFCB1               equ       $0000002B           ;*** LFCB1 - LF Wake Up Code B - byte 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCB1_LFB8          equ       0                   ; Wake Up Code B Bit 8
LFCB1_LFB9          equ       1                   ; Wake Up Code B Bit 9
LFCB1_LFB10         equ       2                   ; Wake Up Code B Bit 10
LFCB1_LFB11         equ       3                   ; Wake Up Code B Bit 11
LFCB1_LFB12         equ       4                   ; Wake Up Code B Bit 12
LFCB1_LFB13         equ       5                   ; Wake Up Code B Bit 13
LFCB1_LFB14         equ       6                   ; Wake Up Code B Bit 14
LFCB1_LFB15         equ       7                   ; Wake Up Code B Bit 15
; bit position masks
mLFCB1_LFB8         equ       %00000001
mLFCB1_LFB9         equ       %00000010
mLFCB1_LFB10        equ       %00000100
mLFCB1_LFB11        equ       %00001000
mLFCB1_LFB12        equ       %00010000
mLFCB1_LFB13        equ       %00100000
mLFCB1_LFB14        equ       %01000000
mLFCB1_LFB15        equ       %10000000

;*** LFDATA - LF Decoder Data Register
LFDATA              equ       $0000002C           ;*** LFDATA - LF Decoder Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFDATA_LFD0         equ       0                   ; LF Data Bit 0
LFDATA_LFD1         equ       1                   ; LF Data Bit 1
LFDATA_LFD2         equ       2                   ; LF Data Bit 2
LFDATA_LFD3         equ       3                   ; LF Data Bit 3
LFDATA_LFD4         equ       4                   ; LF Data Bit 4
LFDATA_LFD5         equ       5                   ; LF Data Bit 5
LFDATA_LFD6         equ       6                   ; LF Data Bit 6
LFDATA_LFD7         equ       7                   ; LF Data Bit 7
; bit position masks
mLFDATA_LFD0        equ       %00000001
mLFDATA_LFD1        equ       %00000010
mLFDATA_LFD2        equ       %00000100
mLFDATA_LFD3        equ       %00001000
mLFDATA_LFD4        equ       %00010000
mLFDATA_LFD5        equ       %00100000
mLFDATA_LFD6        equ       %01000000
mLFDATA_LFD7        equ       %10000000

;*** LFCR - LF Control Register
LFCR                equ       $0000002D           ;*** LFCR - LF Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCR_LFS0           equ       0                   ; LF Sample Time Bit 0
LFCR_LFS1           equ       1                   ; LF Sample Time Bit 1
LFCR_LFS2           equ       2                   ; LF Sample Time Bit 2
LFCR_LFS3           equ       3                   ; LF Sample Time Bit 3
LFCR_LFC0           equ       4                   ; LF Carrier Detection Time Bit 0
LFCR_LFC1           equ       5                   ; LF Carrier Detection Time Bit 1
LFCR_LFM0           equ       6                   ; LF Decoding Mode Bit 0
LFCR_LFM1           equ       7                   ; LF Decoding Mode Bit 1
; bit position masks
mLFCR_LFS0          equ       %00000001
mLFCR_LFS1          equ       %00000010
mLFCR_LFS2          equ       %00000100
mLFCR_LFS3          equ       %00001000
mLFCR_LFC0          equ       %00010000
mLFCR_LFC1          equ       %00100000
mLFCR_LFM0          equ       %01000000
mLFCR_LFM1          equ       %10000000

;*** LFCS0 - LF Control/Status Register 0
LFCS0               equ       $0000002E           ;*** LFCS0 - LF Control/Status Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCS0_LFLVL         equ       1                   ; LF Detector Level
LFCS0_LFE0          equ       2                   ; LF Detector 0 Enable
LFCS0_LFE1          equ       3                   ; LF Detector 1 Enable
LFCS0_LFRST         equ       4                   ; LF Reset Time
LFCS0_LFOFF         equ       5                   ; LF Lockout
LFCS0_LFIE          equ       6                   ; LF Interrupt Enable
LFCS0_LFDO          equ       7                   ; LF Detector Output
; bit position masks
mLFCS0_LFLVL        equ       %00000010
mLFCS0_LFE0         equ       %00000100
mLFCS0_LFE1         equ       %00001000
mLFCS0_LFRST        equ       %00010000
mLFCS0_LFOFF        equ       %00100000
mLFCS0_LFIE         equ       %01000000
mLFCS0_LFDO         equ       %10000000

;*** LFCS1 - LF Control/Status Register 1
LFCS1               equ       $0000002F           ;*** LFCS1 - LF Control/Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCS1_LFIG          equ       0                   ; Ignore LFR Detector Output
LFCS1_LFAF          equ       2                   ; Wake Up Code Flag A
LFCS1_LFBF          equ       3                   ; Wake Up Code Flag B
LFCS1_LFCFAK        equ       4                   ; LF Carrier Flag Acknowledge
LFCS1_LFCF          equ       5                   ; LF Carrier Flag.
LFCS1_LFDFAK        equ       6                   ; LF Data Flag Acknowledge
LFCS1_LFDF          equ       7                   ; LF Data Flag
; bit position masks
mLFCS1_LFIG         equ       %00000001
mLFCS1_LFAF         equ       %00000100
mLFCS1_LFBF         equ       %00001000
mLFCS1_LFCFAK       equ       %00010000
mLFCS1_LFCF         equ       %00100000
mLFCS1_LFDFAK       equ       %01000000
mLFCS1_LFDF         equ       %10000000

;*** ADSC1 - Status and Control Register
ADSC1               equ       $00000030           ;*** ADSC1 - Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSC1_ADCH0         equ       0                   ; Input Channel Select Bit 0
ADSC1_ADCH1         equ       1                   ; Input Channel Select Bit 1
ADSC1_ADCH2         equ       2                   ; Input Channel Select Bit 2
ADSC1_ADCH3         equ       3                   ; Input Channel Select Bit 3
ADSC1_ADCH4         equ       4                   ; Input Channel Select Bit 4
ADSC1_ADCO          equ       5                   ; Continuous Conversion Enable
ADSC1_AIEN          equ       6                   ; Interrupt Enable
ADSC1_COCO          equ       7                   ; Conversion Complete Flag
; bit position masks
mADSC1_ADCH0        equ       %00000001
mADSC1_ADCH1        equ       %00000010
mADSC1_ADCH2        equ       %00000100
mADSC1_ADCH3        equ       %00001000
mADSC1_ADCH4        equ       %00010000
mADSC1_ADCO         equ       %00100000
mADSC1_AIEN         equ       %01000000
mADSC1_COCO         equ       %10000000

;*** ADSC2 - Status and Control Register 2
ADSC2               equ       $00000031           ;*** ADSC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSC2_ACFGT         equ       4                   ; Compare Function Greater Than Enable
ADSC2_ACFE          equ       5                   ; Compare Function Enable
ADSC2_ADTRG         equ       6                   ; Conversion Trigger Select
ADSC2_ADACT         equ       7                   ; Conversion Active
; bit position masks
mADSC2_ACFGT        equ       %00010000
mADSC2_ACFE         equ       %00100000
mADSC2_ADTRG        equ       %01000000
mADSC2_ADACT        equ       %10000000

;*** ADR - ADC10 Result Data Right Justified
ADR                 equ       $00000032           ;*** ADR - ADC10 Result Data Right Justified

;*** ADRH - ADC10 Result Data Right Justified High
ADRH                equ       $00000032           ;*** ADRH - ADC10 Result Data Right Justified High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRH_ADR8           equ       0                   ; ADC10 Result Data Bit 8
ADRH_ADR9           equ       1                   ; ADC10 Result Data Bit 9
ADRH_ADR10          equ       2                   ; ADC10 Result Data Bit 10
ADRH_ADR11          equ       3                   ; ADC10 Result Data Bit 11
; bit position masks
mADRH_ADR8          equ       %00000001
mADRH_ADR9          equ       %00000010
mADRH_ADR10         equ       %00000100
mADRH_ADR11         equ       %00001000

;*** ADRL - ADC10 Result Data Right Justified Low
ADRL                equ       $00000033           ;*** ADRL - ADC10 Result Data Right Justified Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADRL_ADR0           equ       0                   ; ADC10 Result Data Bit 0
ADRL_ADR1           equ       1                   ; ADC10 Result Data Bit 1
ADRL_ADR2           equ       2                   ; ADC10 Result Data Bit 2
ADRL_ADR3           equ       3                   ; ADC10 Result Data Bit 3
ADRL_ADR4           equ       4                   ; ADC10 Result Data Bit 4
ADRL_ADR5           equ       5                   ; ADC10 Result Data Bit 5
ADRL_ADR6           equ       6                   ; ADC10 Result Data Bit 6
ADRL_ADR7           equ       7                   ; ADC10 Result Data Bit 7
; bit position masks
mADRL_ADR0          equ       %00000001
mADRL_ADR1          equ       %00000010
mADRL_ADR2          equ       %00000100
mADRL_ADR3          equ       %00001000
mADRL_ADR4          equ       %00010000
mADRL_ADR5          equ       %00100000
mADRL_ADR6          equ       %01000000
mADRL_ADR7          equ       %10000000

;*** ADCV - Compare Value Register
ADCV                equ       $00000034           ;*** ADCV - Compare Value Register

;*** ADCVH - Compare Value Register High
ADCVH               equ       $00000034           ;*** ADCVH - Compare Value Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCVH_ADCV8         equ       0                   ; Compare Function Value 8
ADCVH_ADCV9         equ       1                   ; Compare Function Value 9
ADCVH_ADCV10        equ       2                   ; Compare Function Value 10
ADCVH_ADCV11        equ       3                   ; Compare Function Value 11
; bit position masks
mADCVH_ADCV8        equ       %00000001
mADCVH_ADCV9        equ       %00000010
mADCVH_ADCV10       equ       %00000100
mADCVH_ADCV11       equ       %00001000

;*** ADCVL - Compare Value Register Low
ADCVL               equ       $00000035           ;*** ADCVL - Compare Value Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCVL_ADCV0         equ       0                   ; Compare Function Value 0
ADCVL_ADCV1         equ       1                   ; Compare Function Value 1
ADCVL_ADCV2         equ       2                   ; Compare Function Value 2
ADCVL_ADCV3         equ       3                   ; Compare Function Value 3
ADCVL_ADCV4         equ       4                   ; Compare Function Value 4
ADCVL_ADCV5         equ       5                   ; Compare Function Value 5
ADCVL_ADCV6         equ       6                   ; Compare Function Value 6
ADCVL_ADCV7         equ       7                   ; Compare Function Value 7
; bit position masks
mADCVL_ADCV0        equ       %00000001
mADCVL_ADCV1        equ       %00000010
mADCVL_ADCV2        equ       %00000100
mADCVL_ADCV3        equ       %00001000
mADCVL_ADCV4        equ       %00010000
mADCVL_ADCV5        equ       %00100000
mADCVL_ADCV6        equ       %01000000
mADCVL_ADCV7        equ       %10000000

;*** ADCFG - Configuration Register
ADCFG               equ       $00000036           ;*** ADCFG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCFG_ADICLK0       equ       0                   ; Input Clock Select Bit 0
ADCFG_ADICLK1       equ       1                   ; Input Clock Select Bit 1
ADCFG_MODE0         equ       2                   ; Conversion Mode Selection Bit 0
ADCFG_MODE1         equ       3                   ; Conversion Mode Selection Bit 1
ADCFG_ADLSMP        equ       4                   ; Long Sample Time Configuration
ADCFG_ADIV0         equ       5                   ; Clock Divide Select Bit 0
ADCFG_ADIV1         equ       6                   ; Clock Divide Select Bit 1
ADCFG_ADLPC         equ       7                   ; Low Power Configuration
; bit position masks
mADCFG_ADICLK0      equ       %00000001
mADCFG_ADICLK1      equ       %00000010
mADCFG_MODE0        equ       %00000100
mADCFG_MODE1        equ       %00001000
mADCFG_ADLSMP       equ       %00010000
mADCFG_ADIV0        equ       %00100000
mADCFG_ADIV1        equ       %01000000
mADCFG_ADLPC        equ       %10000000

;*** APCTL1 - ADC10 Pin Control 1 Register
APCTL1              equ       $00000037           ;*** APCTL1 - ADC10 Pin Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0        equ       0                   ; ADC10 Pin Control 0
APCTL1_ADPC1        equ       1                   ; ADC10 Pin Control 1
APCTL1_ADPC2        equ       2                   ; ADC10 Pin Control 2
APCTL1_ADPC3        equ       3                   ; ADC10 Pin Control 3
APCTL1_ADPC4        equ       4                   ; ADC10 Pin Control 4
APCTL1_ADPC5        equ       5                   ; ADC10 Pin Control 5
APCTL1_ADPC6        equ       6                   ; ADC10 Pin Control 6
APCTL1_ADPC7        equ       7                   ; ADC10 Pin Control 7
; bit position masks
mAPCTL1_ADPC0       equ       %00000001
mAPCTL1_ADPC1       equ       %00000010
mAPCTL1_ADPC2       equ       %00000100
mAPCTL1_ADPC3       equ       %00001000
mAPCTL1_ADPC4       equ       %00010000
mAPCTL1_ADPC5       equ       %00100000
mAPCTL1_ADPC6       equ       %01000000
mAPCTL1_ADPC7       equ       %10000000

;*** PWUDIV - Periodic Wakeup Divider Register
PWUDIV              equ       $00000038           ;*** PWUDIV - Periodic Wakeup Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUDIV_WDIV0        equ       0                   ; Wake up divider Bit 0
PWUDIV_WDIV1        equ       1                   ; Wake up divider Bit 1
PWUDIV_WDIV2        equ       2                   ; Wake up divider Bit 2
PWUDIV_WDIV3        equ       3                   ; Wake up divider Bit 3
PWUDIV_WDIV4        equ       4                   ; Wake up divider Bit 4
PWUDIV_WDIV5        equ       5                   ; Wake up divider Bit 5
; bit position masks
mPWUDIV_WDIV0       equ       %00000001
mPWUDIV_WDIV1       equ       %00000010
mPWUDIV_WDIV2       equ       %00000100
mPWUDIV_WDIV3       equ       %00001000
mPWUDIV_WDIV4       equ       %00010000
mPWUDIV_WDIV5       equ       %00100000

;*** PWUSC0 - Periodic Wakeup Status & Control Register 0
PWUSC0              equ       $00000039           ;*** PWUSC0 - Periodic Wakeup Status & Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUSC0_WUT0         equ       0                   ; Wake Up Time Bit 0
PWUSC0_WUT1         equ       1                   ; Wake Up Time Bit 1
PWUSC0_WUT2         equ       2                   ; Wake Up Time Bit 2
PWUSC0_WUT3         equ       3                   ; Wake Up Time Bit 3
PWUSC0_WUT4         equ       4                   ; Wake Up Time Bit 4
PWUSC0_WUT5         equ       5                   ; Wake Up Time Bit 5
PWUSC0_WUFACK       equ       6                   ; Wake Up Interrupt Acknowledge
PWUSC0_WUF          equ       7                   ; Wake Up Interrupt Flag
; bit position masks
mPWUSC0_WUT0        equ       %00000001
mPWUSC0_WUT1        equ       %00000010
mPWUSC0_WUT2        equ       %00000100
mPWUSC0_WUT3        equ       %00001000
mPWUSC0_WUT4        equ       %00010000
mPWUSC0_WUT5        equ       %00100000
mPWUSC0_WUFACK      equ       %01000000
mPWUSC0_WUF         equ       %10000000

;*** PWUSC1 - Periodic Wakeup Status & Control Register 1
PWUSC1              equ       $0000003A           ;*** PWUSC1 - Periodic Wakeup Status & Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUSC1_PRST0        equ       0                   ; Periodic Reset Time Bit 0
PWUSC1_PRST1        equ       1                   ; Periodic Reset Time Bit 1
PWUSC1_PRST2        equ       2                   ; Periodic Reset Time Bit 2
PWUSC1_PRST3        equ       3                   ; Periodic Reset Time Bit 3
PWUSC1_PRST4        equ       4                   ; Periodic Reset Time Bit 4
PWUSC1_PRST5        equ       5                   ; Periodic Reset Time Bit 5
PWUSC1_PRFACK       equ       6                   ; Periodic Reset Acknowledge
PWUSC1_PRF          equ       7                   ; Periodic Reset Flag
; bit position masks
mPWUSC1_PRST0       equ       %00000001
mPWUSC1_PRST1       equ       %00000010
mPWUSC1_PRST2       equ       %00000100
mPWUSC1_PRST3       equ       %00001000
mPWUSC1_PRST4       equ       %00010000
mPWUSC1_PRST5       equ       %00100000
mPWUSC1_PRFACK      equ       %01000000
mPWUSC1_PRF         equ       %10000000

;*** MDRC - Motion Detection Receiver Control Register
MDRC                equ       $0000003C           ;*** MDRC - Motion Detection Receiver Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MDRC_MVH0           equ       0                   ; MOV Decoder Hold Count Bit 0
MDRC_MVH1           equ       1                   ; MOV Decoder Hold Count Bit 1
MDRC_MVH2           equ       2                   ; MOV Decoder Hold Count Bit 2
MDRC_MVH3           equ       3                   ; MOV Decoder Hold Count Bit 3
MDRC_MVH4           equ       4                   ; MOV Decoder Hold Count Bit 4
MDRC_MVF0           equ       5                   ; MOV Decoder Filter Count Bit 0
MDRC_MVF1           equ       6                   ; MOV Decoder Filter Count Bit 1
MDRC_MVF2           equ       7                   ; MOV Decoder Filter Count Bit 2
; bit position masks
mMDRC_MVH0          equ       %00000001
mMDRC_MVH1          equ       %00000010
mMDRC_MVH2          equ       %00000100
mMDRC_MVH3          equ       %00001000
mMDRC_MVH4          equ       %00010000
mMDRC_MVF0          equ       %00100000
mMDRC_MVF1          equ       %01000000
mMDRC_MVF2          equ       %10000000

;*** MDRCS0 - Motion Detection Receiver Control/Status Register 0
MDRCS0              equ       $0000003D           ;*** MDRCS0 - Motion Detection Receiver Control/Status Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MDRCS0_MVS0         equ       0                   ; Sample Time Bit 0
MDRCS0_MVS1         equ       1                   ; Sample Time Bit 1
MDRCS0_MVS2         equ       2                   ; Sample Time Bit 2
MDRCS0_MVS3         equ       3                   ; Sample Time Bit 3
MDRCS0_MVS4         equ       4                   ; Sample Time Bit 4
MDRCS0_MDRPEN       equ       5                   ; MDR Pin Enable
MDRCS0_MOV          equ       6                   ; Motion Detection
MDRCS0_MVDO         equ       7                   ; MOV Detector Output
; bit position masks
mMDRCS0_MVS0        equ       %00000001
mMDRCS0_MVS1        equ       %00000010
mMDRCS0_MVS2        equ       %00000100
mMDRCS0_MVS3        equ       %00001000
mMDRCS0_MVS4        equ       %00010000
mMDRCS0_MDRPEN      equ       %00100000
mMDRCS0_MOV         equ       %01000000
mMDRCS0_MVDO        equ       %10000000

;*** MDRCS1 - Motion Detection Receiver Control/Status Register 1
MDRCS1              equ       $0000003E           ;*** MDRCS1 - Motion Detection Receiver Control/Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MDRCS1_MVT0         equ       2                   ; MOV Detector Threshold Bit 0
MDRCS1_MVT1         equ       3                   ; MOV Detector Threshold Bit 1
MDRCS1_MVIG         equ       4                   ; Ignore MDR Detector Output.
MDRCS1_MVIE         equ       5                   ; MDR Interrupt Enable
MDRCS1_MVIFAK       equ       6                   ; MDR Interrupt Flag Acknowledge
MDRCS1_MVIF         equ       7                   ; MDR Interrupt Flag
; bit position masks
mMDRCS1_MVT0        equ       %00000100
mMDRCS1_MVT1        equ       %00001000
mMDRCS1_MVIG        equ       %00010000
mMDRCS1_MVIE        equ       %00100000
mMDRCS1_MVIFAK      equ       %01000000
mMDRCS1_MVIF        equ       %10000000

;*** PARAM0 - Parameter Register 0
PARAM0              equ       $00000040           ;*** PARAM0 - Parameter Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM0_BIT0         equ       0                   ; Bit 0
PARAM0_BIT1         equ       1                   ; Bit 1
PARAM0_BIT2         equ       2                   ; Bit 2
PARAM0_BIT3         equ       3                   ; Bit 3
PARAM0_BIT4         equ       4                   ; Bit 4
PARAM0_BIT5         equ       5                   ; Bit 5
PARAM0_BIT6         equ       6                   ; Bit 6
PARAM0_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM0_BIT0        equ       %00000001
mPARAM0_BIT1        equ       %00000010
mPARAM0_BIT2        equ       %00000100
mPARAM0_BIT3        equ       %00001000
mPARAM0_BIT4        equ       %00010000
mPARAM0_BIT5        equ       %00100000
mPARAM0_BIT6        equ       %01000000
mPARAM0_BIT7        equ       %10000000

;*** PARAM1 - Parameter Register 1
PARAM1              equ       $00000041           ;*** PARAM1 - Parameter Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM1_BIT0         equ       0                   ; Bit 0
PARAM1_BIT1         equ       1                   ; Bit 1
PARAM1_BIT2         equ       2                   ; Bit 2
PARAM1_BIT3         equ       3                   ; Bit 3
PARAM1_BIT4         equ       4                   ; Bit 4
PARAM1_BIT5         equ       5                   ; Bit 5
PARAM1_BIT6         equ       6                   ; Bit 6
PARAM1_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM1_BIT0        equ       %00000001
mPARAM1_BIT1        equ       %00000010
mPARAM1_BIT2        equ       %00000100
mPARAM1_BIT3        equ       %00001000
mPARAM1_BIT4        equ       %00010000
mPARAM1_BIT5        equ       %00100000
mPARAM1_BIT6        equ       %01000000
mPARAM1_BIT7        equ       %10000000

;*** PARAM2 - Parameter Register 2
PARAM2              equ       $00000042           ;*** PARAM2 - Parameter Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM2_BIT0         equ       0                   ; Bit 0
PARAM2_BIT1         equ       1                   ; Bit 1
PARAM2_BIT2         equ       2                   ; Bit 2
PARAM2_BIT3         equ       3                   ; Bit 3
PARAM2_BIT4         equ       4                   ; Bit 4
PARAM2_BIT5         equ       5                   ; Bit 5
PARAM2_BIT6         equ       6                   ; Bit 6
PARAM2_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM2_BIT0        equ       %00000001
mPARAM2_BIT1        equ       %00000010
mPARAM2_BIT2        equ       %00000100
mPARAM2_BIT3        equ       %00001000
mPARAM2_BIT4        equ       %00010000
mPARAM2_BIT5        equ       %00100000
mPARAM2_BIT6        equ       %01000000
mPARAM2_BIT7        equ       %10000000

;*** PARAM3 - Parameter Register 3
PARAM3              equ       $00000043           ;*** PARAM3 - Parameter Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM3_BIT0         equ       0                   ; Bit 0
PARAM3_BIT1         equ       1                   ; Bit 1
PARAM3_BIT2         equ       2                   ; Bit 2
PARAM3_BIT3         equ       3                   ; Bit 3
PARAM3_BIT4         equ       4                   ; Bit 4
PARAM3_BIT5         equ       5                   ; Bit 5
PARAM3_BIT6         equ       6                   ; Bit 6
PARAM3_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM3_BIT0        equ       %00000001
mPARAM3_BIT1        equ       %00000010
mPARAM3_BIT2        equ       %00000100
mPARAM3_BIT3        equ       %00001000
mPARAM3_BIT4        equ       %00010000
mPARAM3_BIT5        equ       %00100000
mPARAM3_BIT6        equ       %01000000
mPARAM3_BIT7        equ       %10000000

;*** PARAM4 - Parameter Register 4
PARAM4              equ       $00000044           ;*** PARAM4 - Parameter Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM4_BIT0         equ       0                   ; Bit 0
PARAM4_BIT1         equ       1                   ; Bit 1
PARAM4_BIT2         equ       2                   ; Bit 2
PARAM4_BIT3         equ       3                   ; Bit 3
PARAM4_BIT4         equ       4                   ; Bit 4
PARAM4_BIT5         equ       5                   ; Bit 5
PARAM4_BIT6         equ       6                   ; Bit 6
PARAM4_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM4_BIT0        equ       %00000001
mPARAM4_BIT1        equ       %00000010
mPARAM4_BIT2        equ       %00000100
mPARAM4_BIT3        equ       %00001000
mPARAM4_BIT4        equ       %00010000
mPARAM4_BIT5        equ       %00100000
mPARAM4_BIT6        equ       %01000000
mPARAM4_BIT7        equ       %10000000

;*** PARAM5 - Parameter Register 5
PARAM5              equ       $00000045           ;*** PARAM5 - Parameter Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM5_BIT0         equ       0                   ; Bit 0
PARAM5_BIT1         equ       1                   ; Bit 1
PARAM5_BIT2         equ       2                   ; Bit 2
PARAM5_BIT3         equ       3                   ; Bit 3
PARAM5_BIT4         equ       4                   ; Bit 4
PARAM5_BIT5         equ       5                   ; Bit 5
PARAM5_BIT6         equ       6                   ; Bit 6
PARAM5_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM5_BIT0        equ       %00000001
mPARAM5_BIT1        equ       %00000010
mPARAM5_BIT2        equ       %00000100
mPARAM5_BIT3        equ       %00001000
mPARAM5_BIT4        equ       %00010000
mPARAM5_BIT5        equ       %00100000
mPARAM5_BIT6        equ       %01000000
mPARAM5_BIT7        equ       %10000000

;*** PARAM6 - Parameter Register 6
PARAM6              equ       $00000046           ;*** PARAM6 - Parameter Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM6_BIT0         equ       0                   ; Bit 0
PARAM6_BIT1         equ       1                   ; Bit 1
PARAM6_BIT2         equ       2                   ; Bit 2
PARAM6_BIT3         equ       3                   ; Bit 3
PARAM6_BIT4         equ       4                   ; Bit 4
PARAM6_BIT5         equ       5                   ; Bit 5
PARAM6_BIT6         equ       6                   ; Bit 6
PARAM6_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM6_BIT0        equ       %00000001
mPARAM6_BIT1        equ       %00000010
mPARAM6_BIT2        equ       %00000100
mPARAM6_BIT3        equ       %00001000
mPARAM6_BIT4        equ       %00010000
mPARAM6_BIT5        equ       %00100000
mPARAM6_BIT6        equ       %01000000
mPARAM6_BIT7        equ       %10000000

;*** PARAM7 - Parameter Register 7
PARAM7              equ       $00000047           ;*** PARAM7 - Parameter Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM7_BIT0         equ       0                   ; Bit 0
PARAM7_BIT1         equ       1                   ; Bit 1
PARAM7_BIT2         equ       2                   ; Bit 2
PARAM7_BIT3         equ       3                   ; Bit 3
PARAM7_BIT4         equ       4                   ; Bit 4
PARAM7_BIT5         equ       5                   ; Bit 5
PARAM7_BIT6         equ       6                   ; Bit 6
PARAM7_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM7_BIT0        equ       %00000001
mPARAM7_BIT1        equ       %00000010
mPARAM7_BIT2        equ       %00000100
mPARAM7_BIT3        equ       %00001000
mPARAM7_BIT4        equ       %00010000
mPARAM7_BIT5        equ       %00100000
mPARAM7_BIT6        equ       %01000000
mPARAM7_BIT7        equ       %10000000

;*** PARAM8 - Parameter Register 8
PARAM8              equ       $00000048           ;*** PARAM8 - Parameter Register 8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM8_BIT0         equ       0                   ; Bit 0
PARAM8_BIT1         equ       1                   ; Bit 1
PARAM8_BIT2         equ       2                   ; Bit 2
PARAM8_BIT3         equ       3                   ; Bit 3
PARAM8_BIT4         equ       4                   ; Bit 4
PARAM8_BIT5         equ       5                   ; Bit 5
PARAM8_BIT6         equ       6                   ; Bit 6
PARAM8_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM8_BIT0        equ       %00000001
mPARAM8_BIT1        equ       %00000010
mPARAM8_BIT2        equ       %00000100
mPARAM8_BIT3        equ       %00001000
mPARAM8_BIT4        equ       %00010000
mPARAM8_BIT5        equ       %00100000
mPARAM8_BIT6        equ       %01000000
mPARAM8_BIT7        equ       %10000000

;*** PARAM9 - Parameter Register 9
PARAM9              equ       $00000049           ;*** PARAM9 - Parameter Register 9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM9_BIT0         equ       0                   ; Bit 0
PARAM9_BIT1         equ       1                   ; Bit 1
PARAM9_BIT2         equ       2                   ; Bit 2
PARAM9_BIT3         equ       3                   ; Bit 3
PARAM9_BIT4         equ       4                   ; Bit 4
PARAM9_BIT5         equ       5                   ; Bit 5
PARAM9_BIT6         equ       6                   ; Bit 6
PARAM9_BIT7         equ       7                   ; Bit 7
; bit position masks
mPARAM9_BIT0        equ       %00000001
mPARAM9_BIT1        equ       %00000010
mPARAM9_BIT2        equ       %00000100
mPARAM9_BIT3        equ       %00001000
mPARAM9_BIT4        equ       %00010000
mPARAM9_BIT5        equ       %00100000
mPARAM9_BIT6        equ       %01000000
mPARAM9_BIT7        equ       %10000000

;*** PARAM10 - Parameter Register 10
PARAM10             equ       $0000004A           ;*** PARAM10 - Parameter Register 10
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM10_BIT0        equ       0                   ; Bit 0
PARAM10_BIT1        equ       1                   ; Bit 1
PARAM10_BIT2        equ       2                   ; Bit 2
PARAM10_BIT3        equ       3                   ; Bit 3
PARAM10_BIT4        equ       4                   ; Bit 4
PARAM10_BIT5        equ       5                   ; Bit 5
PARAM10_BIT6        equ       6                   ; Bit 6
PARAM10_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM10_BIT0       equ       %00000001
mPARAM10_BIT1       equ       %00000010
mPARAM10_BIT2       equ       %00000100
mPARAM10_BIT3       equ       %00001000
mPARAM10_BIT4       equ       %00010000
mPARAM10_BIT5       equ       %00100000
mPARAM10_BIT6       equ       %01000000
mPARAM10_BIT7       equ       %10000000

;*** PARAM11 - Parameter Register 11
PARAM11             equ       $0000004B           ;*** PARAM11 - Parameter Register 11
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM11_BIT0        equ       0                   ; Bit 0
PARAM11_BIT1        equ       1                   ; Bit 1
PARAM11_BIT2        equ       2                   ; Bit 2
PARAM11_BIT3        equ       3                   ; Bit 3
PARAM11_BIT4        equ       4                   ; Bit 4
PARAM11_BIT5        equ       5                   ; Bit 5
PARAM11_BIT6        equ       6                   ; Bit 6
PARAM11_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM11_BIT0       equ       %00000001
mPARAM11_BIT1       equ       %00000010
mPARAM11_BIT2       equ       %00000100
mPARAM11_BIT3       equ       %00001000
mPARAM11_BIT4       equ       %00010000
mPARAM11_BIT5       equ       %00100000
mPARAM11_BIT6       equ       %01000000
mPARAM11_BIT7       equ       %10000000

;*** PARAM12 - Parameter Register 12
PARAM12             equ       $0000004C           ;*** PARAM12 - Parameter Register 12
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM12_BIT0        equ       0                   ; Bit 0
PARAM12_BIT1        equ       1                   ; Bit 1
PARAM12_BIT2        equ       2                   ; Bit 2
PARAM12_BIT3        equ       3                   ; Bit 3
PARAM12_BIT4        equ       4                   ; Bit 4
PARAM12_BIT5        equ       5                   ; Bit 5
PARAM12_BIT6        equ       6                   ; Bit 6
PARAM12_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM12_BIT0       equ       %00000001
mPARAM12_BIT1       equ       %00000010
mPARAM12_BIT2       equ       %00000100
mPARAM12_BIT3       equ       %00001000
mPARAM12_BIT4       equ       %00010000
mPARAM12_BIT5       equ       %00100000
mPARAM12_BIT6       equ       %01000000
mPARAM12_BIT7       equ       %10000000

;*** PARAM13 - Parameter Register 13
PARAM13             equ       $0000004D           ;*** PARAM13 - Parameter Register 13
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM13_BIT0        equ       0                   ; Bit 0
PARAM13_BIT1        equ       1                   ; Bit 1
PARAM13_BIT2        equ       2                   ; Bit 2
PARAM13_BIT3        equ       3                   ; Bit 3
PARAM13_BIT4        equ       4                   ; Bit 4
PARAM13_BIT5        equ       5                   ; Bit 5
PARAM13_BIT6        equ       6                   ; Bit 6
PARAM13_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM13_BIT0       equ       %00000001
mPARAM13_BIT1       equ       %00000010
mPARAM13_BIT2       equ       %00000100
mPARAM13_BIT3       equ       %00001000
mPARAM13_BIT4       equ       %00010000
mPARAM13_BIT5       equ       %00100000
mPARAM13_BIT6       equ       %01000000
mPARAM13_BIT7       equ       %10000000

;*** PARAM14 - Parameter Register 14
PARAM14             equ       $0000004E           ;*** PARAM14 - Parameter Register 14
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM14_BIT0        equ       0                   ; Bit 0
PARAM14_BIT1        equ       1                   ; Bit 1
PARAM14_BIT2        equ       2                   ; Bit 2
PARAM14_BIT3        equ       3                   ; Bit 3
PARAM14_BIT4        equ       4                   ; Bit 4
PARAM14_BIT5        equ       5                   ; Bit 5
PARAM14_BIT6        equ       6                   ; Bit 6
PARAM14_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM14_BIT0       equ       %00000001
mPARAM14_BIT1       equ       %00000010
mPARAM14_BIT2       equ       %00000100
mPARAM14_BIT3       equ       %00001000
mPARAM14_BIT4       equ       %00010000
mPARAM14_BIT5       equ       %00100000
mPARAM14_BIT6       equ       %01000000
mPARAM14_BIT7       equ       %10000000

;*** PARAM15 - Parameter Register 15
PARAM15             equ       $0000004F           ;*** PARAM15 - Parameter Register 15
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM15_BIT0        equ       0                   ; Bit 0
PARAM15_BIT1        equ       1                   ; Bit 1
PARAM15_BIT2        equ       2                   ; Bit 2
PARAM15_BIT3        equ       3                   ; Bit 3
PARAM15_BIT4        equ       4                   ; Bit 4
PARAM15_BIT5        equ       5                   ; Bit 5
PARAM15_BIT6        equ       6                   ; Bit 6
PARAM15_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM15_BIT0       equ       %00000001
mPARAM15_BIT1       equ       %00000010
mPARAM15_BIT2       equ       %00000100
mPARAM15_BIT3       equ       %00001000
mPARAM15_BIT4       equ       %00010000
mPARAM15_BIT5       equ       %00100000
mPARAM15_BIT6       equ       %01000000
mPARAM15_BIT7       equ       %10000000

;*** PARAM16 - Parameter Register 16
PARAM16             equ       $00000050           ;*** PARAM16 - Parameter Register 16
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM16_BIT0        equ       0                   ; Bit 0
PARAM16_BIT1        equ       1                   ; Bit 1
PARAM16_BIT2        equ       2                   ; Bit 2
PARAM16_BIT3        equ       3                   ; Bit 3
PARAM16_BIT4        equ       4                   ; Bit 4
PARAM16_BIT5        equ       5                   ; Bit 5
PARAM16_BIT6        equ       6                   ; Bit 6
PARAM16_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM16_BIT0       equ       %00000001
mPARAM16_BIT1       equ       %00000010
mPARAM16_BIT2       equ       %00000100
mPARAM16_BIT3       equ       %00001000
mPARAM16_BIT4       equ       %00010000
mPARAM16_BIT5       equ       %00100000
mPARAM16_BIT6       equ       %01000000
mPARAM16_BIT7       equ       %10000000

;*** PARAM17 - Parameter Register 17
PARAM17             equ       $00000051           ;*** PARAM17 - Parameter Register 17
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM17_BIT0        equ       0                   ; Bit 0
PARAM17_BIT1        equ       1                   ; Bit 1
PARAM17_BIT2        equ       2                   ; Bit 2
PARAM17_BIT3        equ       3                   ; Bit 3
PARAM17_BIT4        equ       4                   ; Bit 4
PARAM17_BIT5        equ       5                   ; Bit 5
PARAM17_BIT6        equ       6                   ; Bit 6
PARAM17_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM17_BIT0       equ       %00000001
mPARAM17_BIT1       equ       %00000010
mPARAM17_BIT2       equ       %00000100
mPARAM17_BIT3       equ       %00001000
mPARAM17_BIT4       equ       %00010000
mPARAM17_BIT5       equ       %00100000
mPARAM17_BIT6       equ       %01000000
mPARAM17_BIT7       equ       %10000000

;*** PARAM18 - Parameter Register 18
PARAM18             equ       $00000052           ;*** PARAM18 - Parameter Register 18
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM18_BIT0        equ       0                   ; Bit 0
PARAM18_BIT1        equ       1                   ; Bit 1
PARAM18_BIT2        equ       2                   ; Bit 2
PARAM18_BIT3        equ       3                   ; Bit 3
PARAM18_BIT4        equ       4                   ; Bit 4
PARAM18_BIT5        equ       5                   ; Bit 5
PARAM18_BIT6        equ       6                   ; Bit 6
PARAM18_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM18_BIT0       equ       %00000001
mPARAM18_BIT1       equ       %00000010
mPARAM18_BIT2       equ       %00000100
mPARAM18_BIT3       equ       %00001000
mPARAM18_BIT4       equ       %00010000
mPARAM18_BIT5       equ       %00100000
mPARAM18_BIT6       equ       %01000000
mPARAM18_BIT7       equ       %10000000

;*** PARAM19 - Parameter Register 19
PARAM19             equ       $00000053           ;*** PARAM19 - Parameter Register 19
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM19_BIT0        equ       0                   ; Bit 0
PARAM19_BIT1        equ       1                   ; Bit 1
PARAM19_BIT2        equ       2                   ; Bit 2
PARAM19_BIT3        equ       3                   ; Bit 3
PARAM19_BIT4        equ       4                   ; Bit 4
PARAM19_BIT5        equ       5                   ; Bit 5
PARAM19_BIT6        equ       6                   ; Bit 6
PARAM19_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM19_BIT0       equ       %00000001
mPARAM19_BIT1       equ       %00000010
mPARAM19_BIT2       equ       %00000100
mPARAM19_BIT3       equ       %00001000
mPARAM19_BIT4       equ       %00010000
mPARAM19_BIT5       equ       %00100000
mPARAM19_BIT6       equ       %01000000
mPARAM19_BIT7       equ       %10000000

;*** PARAM20 - Parameter Register 20
PARAM20             equ       $00000054           ;*** PARAM20 - Parameter Register 20
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM20_BIT0        equ       0                   ; Bit 0
PARAM20_BIT1        equ       1                   ; Bit 1
PARAM20_BIT2        equ       2                   ; Bit 2
PARAM20_BIT3        equ       3                   ; Bit 3
PARAM20_BIT4        equ       4                   ; Bit 4
PARAM20_BIT5        equ       5                   ; Bit 5
PARAM20_BIT6        equ       6                   ; Bit 6
PARAM20_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM20_BIT0       equ       %00000001
mPARAM20_BIT1       equ       %00000010
mPARAM20_BIT2       equ       %00000100
mPARAM20_BIT3       equ       %00001000
mPARAM20_BIT4       equ       %00010000
mPARAM20_BIT5       equ       %00100000
mPARAM20_BIT6       equ       %01000000
mPARAM20_BIT7       equ       %10000000

;*** PARAM21 - Parameter Register 21
PARAM21             equ       $00000055           ;*** PARAM21 - Parameter Register 21
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM21_BIT0        equ       0                   ; Bit 0
PARAM21_BIT1        equ       1                   ; Bit 1
PARAM21_BIT2        equ       2                   ; Bit 2
PARAM21_BIT3        equ       3                   ; Bit 3
PARAM21_BIT4        equ       4                   ; Bit 4
PARAM21_BIT5        equ       5                   ; Bit 5
PARAM21_BIT6        equ       6                   ; Bit 6
PARAM21_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM21_BIT0       equ       %00000001
mPARAM21_BIT1       equ       %00000010
mPARAM21_BIT2       equ       %00000100
mPARAM21_BIT3       equ       %00001000
mPARAM21_BIT4       equ       %00010000
mPARAM21_BIT5       equ       %00100000
mPARAM21_BIT6       equ       %01000000
mPARAM21_BIT7       equ       %10000000

;*** PARAM22 - Parameter Register 22
PARAM22             equ       $00000056           ;*** PARAM22 - Parameter Register 22
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM22_BIT0        equ       0                   ; Bit 0
PARAM22_BIT1        equ       1                   ; Bit 1
PARAM22_BIT2        equ       2                   ; Bit 2
PARAM22_BIT3        equ       3                   ; Bit 3
PARAM22_BIT4        equ       4                   ; Bit 4
PARAM22_BIT5        equ       5                   ; Bit 5
PARAM22_BIT6        equ       6                   ; Bit 6
PARAM22_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM22_BIT0       equ       %00000001
mPARAM22_BIT1       equ       %00000010
mPARAM22_BIT2       equ       %00000100
mPARAM22_BIT3       equ       %00001000
mPARAM22_BIT4       equ       %00010000
mPARAM22_BIT5       equ       %00100000
mPARAM22_BIT6       equ       %01000000
mPARAM22_BIT7       equ       %10000000

;*** PARAM23 - Parameter Register 23
PARAM23             equ       $00000057           ;*** PARAM23 - Parameter Register 23
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM23_BIT0        equ       0                   ; Bit 0
PARAM23_BIT1        equ       1                   ; Bit 1
PARAM23_BIT2        equ       2                   ; Bit 2
PARAM23_BIT3        equ       3                   ; Bit 3
PARAM23_BIT4        equ       4                   ; Bit 4
PARAM23_BIT5        equ       5                   ; Bit 5
PARAM23_BIT6        equ       6                   ; Bit 6
PARAM23_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM23_BIT0       equ       %00000001
mPARAM23_BIT1       equ       %00000010
mPARAM23_BIT2       equ       %00000100
mPARAM23_BIT3       equ       %00001000
mPARAM23_BIT4       equ       %00010000
mPARAM23_BIT5       equ       %00100000
mPARAM23_BIT6       equ       %01000000
mPARAM23_BIT7       equ       %10000000

;*** PARAM24 - Parameter Register 24
PARAM24             equ       $00000058           ;*** PARAM24 - Parameter Register 24
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM24_BIT0        equ       0                   ; Bit 0
PARAM24_BIT1        equ       1                   ; Bit 1
PARAM24_BIT2        equ       2                   ; Bit 2
PARAM24_BIT3        equ       3                   ; Bit 3
PARAM24_BIT4        equ       4                   ; Bit 4
PARAM24_BIT5        equ       5                   ; Bit 5
PARAM24_BIT6        equ       6                   ; Bit 6
PARAM24_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM24_BIT0       equ       %00000001
mPARAM24_BIT1       equ       %00000010
mPARAM24_BIT2       equ       %00000100
mPARAM24_BIT3       equ       %00001000
mPARAM24_BIT4       equ       %00010000
mPARAM24_BIT5       equ       %00100000
mPARAM24_BIT6       equ       %01000000
mPARAM24_BIT7       equ       %10000000

;*** PARAM25 - Parameter Register 25
PARAM25             equ       $00000059           ;*** PARAM25 - Parameter Register 25
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM25_BIT0        equ       0                   ; Bit 0
PARAM25_BIT1        equ       1                   ; Bit 1
PARAM25_BIT2        equ       2                   ; Bit 2
PARAM25_BIT3        equ       3                   ; Bit 3
PARAM25_BIT4        equ       4                   ; Bit 4
PARAM25_BIT5        equ       5                   ; Bit 5
PARAM25_BIT6        equ       6                   ; Bit 6
PARAM25_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM25_BIT0       equ       %00000001
mPARAM25_BIT1       equ       %00000010
mPARAM25_BIT2       equ       %00000100
mPARAM25_BIT3       equ       %00001000
mPARAM25_BIT4       equ       %00010000
mPARAM25_BIT5       equ       %00100000
mPARAM25_BIT6       equ       %01000000
mPARAM25_BIT7       equ       %10000000

;*** PARAM26 - Parameter Register 26
PARAM26             equ       $0000005A           ;*** PARAM26 - Parameter Register 26
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM26_BIT0        equ       0                   ; Bit 0
PARAM26_BIT1        equ       1                   ; Bit 1
PARAM26_BIT2        equ       2                   ; Bit 2
PARAM26_BIT3        equ       3                   ; Bit 3
PARAM26_BIT4        equ       4                   ; Bit 4
PARAM26_BIT5        equ       5                   ; Bit 5
PARAM26_BIT6        equ       6                   ; Bit 6
PARAM26_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM26_BIT0       equ       %00000001
mPARAM26_BIT1       equ       %00000010
mPARAM26_BIT2       equ       %00000100
mPARAM26_BIT3       equ       %00001000
mPARAM26_BIT4       equ       %00010000
mPARAM26_BIT5       equ       %00100000
mPARAM26_BIT6       equ       %01000000
mPARAM26_BIT7       equ       %10000000

;*** PARAM27 - Parameter Register 27
PARAM27             equ       $0000005B           ;*** PARAM27 - Parameter Register 27
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM27_BIT0        equ       0                   ; Bit 0
PARAM27_BIT1        equ       1                   ; Bit 1
PARAM27_BIT2        equ       2                   ; Bit 2
PARAM27_BIT3        equ       3                   ; Bit 3
PARAM27_BIT4        equ       4                   ; Bit 4
PARAM27_BIT5        equ       5                   ; Bit 5
PARAM27_BIT6        equ       6                   ; Bit 6
PARAM27_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM27_BIT0       equ       %00000001
mPARAM27_BIT1       equ       %00000010
mPARAM27_BIT2       equ       %00000100
mPARAM27_BIT3       equ       %00001000
mPARAM27_BIT4       equ       %00010000
mPARAM27_BIT5       equ       %00100000
mPARAM27_BIT6       equ       %01000000
mPARAM27_BIT7       equ       %10000000

;*** PARAM28 - Parameter Register 28
PARAM28             equ       $0000005C           ;*** PARAM28 - Parameter Register 28
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM28_BIT0        equ       0                   ; Bit 0
PARAM28_BIT1        equ       1                   ; Bit 1
PARAM28_BIT2        equ       2                   ; Bit 2
PARAM28_BIT3        equ       3                   ; Bit 3
PARAM28_BIT4        equ       4                   ; Bit 4
PARAM28_BIT5        equ       5                   ; Bit 5
PARAM28_BIT6        equ       6                   ; Bit 6
PARAM28_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM28_BIT0       equ       %00000001
mPARAM28_BIT1       equ       %00000010
mPARAM28_BIT2       equ       %00000100
mPARAM28_BIT3       equ       %00001000
mPARAM28_BIT4       equ       %00010000
mPARAM28_BIT5       equ       %00100000
mPARAM28_BIT6       equ       %01000000
mPARAM28_BIT7       equ       %10000000

;*** PARAM29 - Parameter Register 29
PARAM29             equ       $0000005D           ;*** PARAM29 - Parameter Register 29
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM29_BIT0        equ       0                   ; Bit 0
PARAM29_BIT1        equ       1                   ; Bit 1
PARAM29_BIT2        equ       2                   ; Bit 2
PARAM29_BIT3        equ       3                   ; Bit 3
PARAM29_BIT4        equ       4                   ; Bit 4
PARAM29_BIT5        equ       5                   ; Bit 5
PARAM29_BIT6        equ       6                   ; Bit 6
PARAM29_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM29_BIT0       equ       %00000001
mPARAM29_BIT1       equ       %00000010
mPARAM29_BIT2       equ       %00000100
mPARAM29_BIT3       equ       %00001000
mPARAM29_BIT4       equ       %00010000
mPARAM29_BIT5       equ       %00100000
mPARAM29_BIT6       equ       %01000000
mPARAM29_BIT7       equ       %10000000

;*** PARAM30 - Parameter Register 30
PARAM30             equ       $0000005E           ;*** PARAM30 - Parameter Register 30
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM30_BIT0        equ       0                   ; Bit 0
PARAM30_BIT1        equ       1                   ; Bit 1
PARAM30_BIT2        equ       2                   ; Bit 2
PARAM30_BIT3        equ       3                   ; Bit 3
PARAM30_BIT4        equ       4                   ; Bit 4
PARAM30_BIT5        equ       5                   ; Bit 5
PARAM30_BIT6        equ       6                   ; Bit 6
PARAM30_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM30_BIT0       equ       %00000001
mPARAM30_BIT1       equ       %00000010
mPARAM30_BIT2       equ       %00000100
mPARAM30_BIT3       equ       %00001000
mPARAM30_BIT4       equ       %00010000
mPARAM30_BIT5       equ       %00100000
mPARAM30_BIT6       equ       %01000000
mPARAM30_BIT7       equ       %10000000

;*** PARAM31 - Parameter Register 31
PARAM31             equ       $0000005F           ;*** PARAM31 - Parameter Register 31
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM31_BIT0        equ       0                   ; Bit 0
PARAM31_BIT1        equ       1                   ; Bit 1
PARAM31_BIT2        equ       2                   ; Bit 2
PARAM31_BIT3        equ       3                   ; Bit 3
PARAM31_BIT4        equ       4                   ; Bit 4
PARAM31_BIT5        equ       5                   ; Bit 5
PARAM31_BIT6        equ       6                   ; Bit 6
PARAM31_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM31_BIT0       equ       %00000001
mPARAM31_BIT1       equ       %00000010
mPARAM31_BIT2       equ       %00000100
mPARAM31_BIT3       equ       %00001000
mPARAM31_BIT4       equ       %00010000
mPARAM31_BIT5       equ       %00100000
mPARAM31_BIT6       equ       %01000000
mPARAM31_BIT7       equ       %10000000

;*** SRS - System Reset Status
SRS                 equ       $00001800           ;*** SRS - System Reset Status
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD             equ       1                   ; Low Voltage Detect
SRS_PWU             equ       2                   ; PWU
SRS_ILAD            equ       3                   ; Illegal Address
SRS_ILOP            equ       4                   ; Illegal Opcode
SRS_COP             equ       5                   ; Computer Operating Properly (COP) Watchdog
SRS_PIN             equ       6                   ; External Reset Pin
SRS_POR             equ       7                   ; Power-On Reset
; bit position masks
mSRS_LVD            equ       %00000010
mSRS_PWU            equ       %00000100
mSRS_ILAD           equ       %00001000
mSRS_ILOP           equ       %00010000
mSRS_COP            equ       %00100000
mSRS_PIN            equ       %01000000
mSRS_POR            equ       %10000000

;*** SBDFR - System Background Debug Force Reset Register
SBDFR               equ       $00001801           ;*** SBDFR - System Background Debug Force Reset Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBDFR_BDFR          equ       0                   ; Background Debug Force Reset
; bit position masks
mSBDFR_BDFR         equ       %00000001

;*** SOPT1 - System Options Register 1
SOPT1               equ       $00001802           ;*** SOPT1 - System Options Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_BKGDPE        equ       1                   ; Background Debug Mode Pin Enable
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT          equ       6                   ; COP Watchdog Timeout
SOPT1_COPE          equ       7                   ; COP Watchdog Enable
; bit position masks
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT         equ       %01000000
mSOPT1_COPE         equ       %10000000

;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_LFOSEL        equ       3                   ; LFO Selected
SOPT2_TRE           equ       7                   ; Temperature Restart Wakeup Enable
; bit position masks
mSOPT2_LFOSEL       equ       %00001000
mSOPT2_TRE          equ       %10000000

;*** SOTRM - System Oscillator Trim Register
SOTRM               equ       $00001804           ;*** SOTRM - System Oscillator Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOTRM_SOTRM0        equ       0                   ; MFO Trim Value Bit 0
SOTRM_SOTRM1        equ       1                   ; MFO Trim Value Bit 1
SOTRM_SOTRM2        equ       2                   ; MFO Trim Value Bit 2
SOTRM_SOTRM3        equ       3                   ; MFO Trim Value Bit 3
SOTRM_SOTRM4        equ       4                   ; MFO Trim Value Bit 4
SOTRM_SOTRM5        equ       5                   ; MFO Trim Value Bit 5
SOTRM_SOTRM6        equ       6                   ; MFO Trim Value Bit 6
SOTRM_SOTRM7        equ       7                   ; MFO Trim Value Bit 7
; bit position masks
mSOTRM_SOTRM0       equ       %00000001
mSOTRM_SOTRM1       equ       %00000010
mSOTRM_SOTRM2       equ       %00000100
mSOTRM_SOTRM3       equ       %00001000
mSOTRM_SOTRM4       equ       %00010000
mSOTRM_SOTRM5       equ       %00100000
mSOTRM_SOTRM6       equ       %01000000
mSOTRM_SOTRM7       equ       %10000000

;*** SDID - System Integration Module Part ID Register
SDID                equ       $00001806           ;*** SDID - System Integration Module Part ID Register

;*** SDIDH - System Integration Module Part ID Register High
SDIDH               equ       $00001806           ;*** SDIDH - System Integration Module Part ID Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8           equ       0                   ; Part Identification Number 8
SDIDH_ID9           equ       1                   ; Part Identification Number 9
SDIDH_ID10          equ       2                   ; Part Identification Number 10
SDIDH_ID11          equ       3                   ; Part Identification Number 11
SDIDH_REV0          equ       4                   ; Revision Number 0
SDIDH_REV1          equ       5                   ; Revision Number 1
SDIDH_REV2          equ       6                   ; Revision Number 2
SDIDH_REV3          equ       7                   ; Revision Number 3
; bit position masks
mSDIDH_ID8          equ       %00000001
mSDIDH_ID9          equ       %00000010
mSDIDH_ID10         equ       %00000100
mSDIDH_ID11         equ       %00001000
mSDIDH_REV0         equ       %00010000
mSDIDH_REV1         equ       %00100000
mSDIDH_REV2         equ       %01000000
mSDIDH_REV3         equ       %10000000

;*** SDIDL - System Integration Module Part ID Register Low
SDIDL               equ       $00001807           ;*** SDIDL - System Integration Module Part ID Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDL_ID0           equ       0                   ; Part Identification Number 0
SDIDL_ID1           equ       1                   ; Part Identification Number 1
SDIDL_ID2           equ       2                   ; Part Identification Number 2
SDIDL_ID3           equ       3                   ; Part Identification Number 3
SDIDL_ID4           equ       4                   ; Part Identification Number 4
SDIDL_ID5           equ       5                   ; Part Identification Number 5
SDIDL_ID6           equ       6                   ; Part Identification Number 6
SDIDL_ID7           equ       7                   ; Part Identification Number 7
; bit position masks
mSDIDL_ID0          equ       %00000001
mSDIDL_ID1          equ       %00000010
mSDIDL_ID2          equ       %00000100
mSDIDL_ID3          equ       %00001000
mSDIDL_ID4          equ       %00010000
mSDIDL_ID5          equ       %00100000
mSDIDL_ID6          equ       %01000000
mSDIDL_ID7          equ       %10000000

;*** SRTISC - System RTI Status and Control Register
SRTISC              equ       $00001808           ;*** SRTISC - System RTI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRTISC_RTIS0        equ       0                   ; Real-Time Interrupt Delay Select Bit 0
SRTISC_RTIS1        equ       1                   ; Real-Time Interrupt Delay Select Bit 1
SRTISC_RTIS2        equ       2                   ; Real-Time Interrupt Delay Select Bit 2
SRTISC_RTIE         equ       4                   ; Real-Time Interrupt Enable
SRTISC_RTICLKS      equ       5                   ; Real-Time Interrupt Clock Select
SRTISC_RTIACK       equ       6                   ; Real-Time Interrupt Acknowledge
SRTISC_RTIF         equ       7                   ; Real-Time Interrupt Flag
; bit position masks
mSRTISC_RTIS0       equ       %00000001
mSRTISC_RTIS1       equ       %00000010
mSRTISC_RTIS2       equ       %00000100
mSRTISC_RTIE        equ       %00010000
mSRTISC_RTICLKS     equ       %00100000
mSRTISC_RTIACK      equ       %01000000
mSRTISC_RTIF        equ       %10000000

;*** SPMSC1 - System Power Management Status and Control 1 Register
SPMSC1              equ       $00001809           ;*** SPMSC1 - System Power Management Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE         equ       0                   ; Bandgap Buffer Enable
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE        equ       5                   ; Low-Voltage Detect Interrrupt Enable
SPMSC1_LVDACK       equ       6                   ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF         equ       7                   ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_BGBE        equ       %00000001
mSPMSC1_LVDE        equ       %00000100
mSPMSC1_LVDSE       equ       %00001000
mSPMSC1_LVDRE       equ       %00010000
mSPMSC1_LVDIE       equ       %00100000
mSPMSC1_LVDACK      equ       %01000000
mSPMSC1_LVDF        equ       %10000000

;*** SPMSC2 - System Power Management Status and Control 2 Register
SPMSC2              equ       $0000180A           ;*** SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC         equ       0                   ; Partial Power Down Control
SPMSC2_PDC          equ       1                   ; Power Down Control
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowlege
SPMSC2_PPDF         equ       3                   ; Partial Power Down Flag
SPMSC2_PDF          equ       4                   ; Power Down Flag
; bit position masks
mSPMSC2_PPDC        equ       %00000001
mSPMSC2_PDC         equ       %00000010
mSPMSC2_PPDACK      equ       %00000100
mSPMSC2_PPDF        equ       %00001000
mSPMSC2_PDF         equ       %00010000

;*** SPMSC3 - System Power Management Status and Control 3 Register
SPMSC3              equ       $0000180C           ;*** SPMSC3 - System Power Management Status and Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC3_LVWV         equ       4                   ; Low-Voltage Warning Voltage Select
SPMSC3_LVDV         equ       5                   ; Low-Voltage Detect Voltage Select
SPMSC3_LVWACK       equ       6                   ; Low-Voltage Warning Acknowledge
SPMSC3_LVWF         equ       7                   ; Low-Voltage Warning Flag
; bit position masks
mSPMSC3_LVWV        equ       %00010000
mSPMSC3_LVDV        equ       %00100000
mSPMSC3_LVWACK      equ       %01000000
mSPMSC3_LVWF        equ       %10000000

;*** DBGCAH - Debug Comparator A High Register
DBGCAH              equ       $00001810           ;*** DBGCAH - Debug Comparator A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAH_Bit8         equ       0                   ; Debug Comparator A Bit 8
DBGCAH_Bit9         equ       1                   ; Debug Comparator A Bit 9
DBGCAH_Bit10        equ       2                   ; Debug Comparator A Bit 10
DBGCAH_Bit11        equ       3                   ; Debug Comparator A Bit 11
DBGCAH_Bit12        equ       4                   ; Debug Comparator A Bit 12
DBGCAH_Bit13        equ       5                   ; Debug Comparator A Bit 13
DBGCAH_Bit14        equ       6                   ; Debug Comparator A Bit 14
DBGCAH_Bit15        equ       7                   ; Debug Comparator A Bit 15
; bit position masks
mDBGCAH_Bit8        equ       %00000001
mDBGCAH_Bit9        equ       %00000010
mDBGCAH_Bit10       equ       %00000100
mDBGCAH_Bit11       equ       %00001000
mDBGCAH_Bit12       equ       %00010000
mDBGCAH_Bit13       equ       %00100000
mDBGCAH_Bit14       equ       %01000000
mDBGCAH_Bit15       equ       %10000000

;*** DBGCAL - Debug Comparator A Low Register
DBGCAL              equ       $00001811           ;*** DBGCAL - Debug Comparator A Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAL_Bit0         equ       0                   ; Debug Comparator A Bit 0
DBGCAL_Bit1         equ       1                   ; Debug Comparator A Bit 1
DBGCAL_Bit2         equ       2                   ; Debug Comparator A Bit 2
DBGCAL_Bit3         equ       3                   ; Debug Comparator A Bit 3
DBGCAL_Bit4         equ       4                   ; Debug Comparator A Bit 4
DBGCAL_Bit5         equ       5                   ; Debug Comparator A Bit 5
DBGCAL_Bit6         equ       6                   ; Debug Comparator A Bit 6
DBGCAL_Bit7         equ       7                   ; Debug Comparator A Bit 7
; bit position masks
mDBGCAL_Bit0        equ       %00000001
mDBGCAL_Bit1        equ       %00000010
mDBGCAL_Bit2        equ       %00000100
mDBGCAL_Bit3        equ       %00001000
mDBGCAL_Bit4        equ       %00010000
mDBGCAL_Bit5        equ       %00100000
mDBGCAL_Bit6        equ       %01000000
mDBGCAL_Bit7        equ       %10000000

;*** DBGCBH - Debug Comparator B High Register
DBGCBH              equ       $00001812           ;*** DBGCBH - Debug Comparator B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBH_Bit8         equ       0                   ; Debug Comparator B Bit 8
DBGCBH_Bit9         equ       1                   ; Debug Comparator B Bit 9
DBGCBH_Bit10        equ       2                   ; Debug Comparator B Bit 10
DBGCBH_Bit11        equ       3                   ; Debug Comparator B Bit 11
DBGCBH_Bit12        equ       4                   ; Debug Comparator B Bit 12
DBGCBH_Bit13        equ       5                   ; Debug Comparator B Bit 13
DBGCBH_Bit14        equ       6                   ; Debug Comparator B Bit 14
DBGCBH_Bit15        equ       7                   ; Debug Comparator B Bit 15
; bit position masks
mDBGCBH_Bit8        equ       %00000001
mDBGCBH_Bit9        equ       %00000010
mDBGCBH_Bit10       equ       %00000100
mDBGCBH_Bit11       equ       %00001000
mDBGCBH_Bit12       equ       %00010000
mDBGCBH_Bit13       equ       %00100000
mDBGCBH_Bit14       equ       %01000000
mDBGCBH_Bit15       equ       %10000000

;*** DBGCBL - Debug Comparator B Low Register
DBGCBL              equ       $00001813           ;*** DBGCBL - Debug Comparator B Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBL_Bit0         equ       0                   ; Debug Comparator B Bit 0
DBGCBL_Bit1         equ       1                   ; Debug Comparator B Bit 1
DBGCBL_Bit2         equ       2                   ; Debug Comparator B Bit 2
DBGCBL_Bit3         equ       3                   ; Debug Comparator B Bit 3
DBGCBL_Bit4         equ       4                   ; Debug Comparator B Bit 4
DBGCBL_Bit5         equ       5                   ; Debug Comparator B Bit 5
DBGCBL_Bit6         equ       6                   ; Debug Comparator B Bit 6
DBGCBL_Bit7         equ       7                   ; Debug Comparator B Bit 7
; bit position masks
mDBGCBL_Bit0        equ       %00000001
mDBGCBL_Bit1        equ       %00000010
mDBGCBL_Bit2        equ       %00000100
mDBGCBL_Bit3        equ       %00001000
mDBGCBL_Bit4        equ       %00010000
mDBGCBL_Bit5        equ       %00100000
mDBGCBL_Bit6        equ       %01000000
mDBGCBL_Bit7        equ       %10000000

;*** DBGF - Debug FIFO Register
DBGF                equ       $00001814           ;*** DBGF - Debug FIFO Register

;*** DBGFH - Debug FIFO High Register
DBGFH               equ       $00001814           ;*** DBGFH - Debug FIFO High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFH_Bit8          equ       0                   ; Debug FIFO Bit 8
DBGFH_Bit9          equ       1                   ; Debug FIFO Bit 9
DBGFH_Bit10         equ       2                   ; Debug FIFO Bit 10
DBGFH_Bit11         equ       3                   ; Debug FIFO Bit 11
DBGFH_Bit12         equ       4                   ; Debug FIFO Bit 12
DBGFH_Bit13         equ       5                   ; Debug FIFO Bit 13
DBGFH_Bit14         equ       6                   ; Debug FIFO Bit 14
DBGFH_Bit15         equ       7                   ; Debug FIFO Bit 15
; bit position masks
mDBGFH_Bit8         equ       %00000001
mDBGFH_Bit9         equ       %00000010
mDBGFH_Bit10        equ       %00000100
mDBGFH_Bit11        equ       %00001000
mDBGFH_Bit12        equ       %00010000
mDBGFH_Bit13        equ       %00100000
mDBGFH_Bit14        equ       %01000000
mDBGFH_Bit15        equ       %10000000

;*** DBGFL - Debug FIFO Low Register
DBGFL               equ       $00001815           ;*** DBGFL - Debug FIFO Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFL_Bit0          equ       0                   ; Debug FIFO Bit 0
DBGFL_Bit1          equ       1                   ; Debug FIFO Bit 1
DBGFL_Bit2          equ       2                   ; Debug FIFO Bit 2
DBGFL_Bit3          equ       3                   ; Debug FIFO Bit 3
DBGFL_Bit4          equ       4                   ; Debug FIFO Bit 4
DBGFL_Bit5          equ       5                   ; Debug FIFO Bit 5
DBGFL_Bit6          equ       6                   ; Debug FIFO Bit 6
DBGFL_Bit7          equ       7                   ; Debug FIFO Bit 7
; bit position masks
mDBGFL_Bit0         equ       %00000001
mDBGFL_Bit1         equ       %00000010
mDBGFL_Bit2         equ       %00000100
mDBGFL_Bit3         equ       %00001000
mDBGFL_Bit4         equ       %00010000
mDBGFL_Bit5         equ       %00100000
mDBGFL_Bit6         equ       %01000000
mDBGFL_Bit7         equ       %10000000

;*** DBGC - Debug Control Register
DBGC                equ       $00001816           ;*** DBGC - Debug Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC_RWBEN          equ       0                   ; Enable R/W for Comparator B
DBGC_RWB            equ       1                   ; R/W Comparison Value for Comparator B
DBGC_RWAEN          equ       2                   ; Enable R/W for Comparator A
DBGC_RWA            equ       3                   ; R/W Comparison Value for Comparator A
DBGC_BRKEN          equ       4                   ; Break Enable
DBGC_TAG            equ       5                   ; Tag/Force Select
DBGC_ARM            equ       6                   ; Arm Control
DBGC_DBGEN          equ       7                   ; Debug Module Enable
; bit position masks
mDBGC_RWBEN         equ       %00000001
mDBGC_RWB           equ       %00000010
mDBGC_RWAEN         equ       %00000100
mDBGC_RWA           equ       %00001000
mDBGC_BRKEN         equ       %00010000
mDBGC_TAG           equ       %00100000
mDBGC_ARM           equ       %01000000
mDBGC_DBGEN         equ       %10000000

;*** DBGT - Debug Trigger Register
DBGT                equ       $00001817           ;*** DBGT - Debug Trigger Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGT_TRG0           equ       0                   ; Select Trigger Mode Bit 0
DBGT_TRG1           equ       1                   ; Select Trigger Mode Bit 1
DBGT_TRG2           equ       2                   ; Select Trigger Mode Bit 2
DBGT_TRG3           equ       3                   ; Select Trigger Mode Bit 3
DBGT_BEGIN          equ       6                   ; Begin/End Trigger Select
DBGT_TRGSEL         equ       7                   ; Trigger Type
; bit position masks
mDBGT_TRG0          equ       %00000001
mDBGT_TRG1          equ       %00000010
mDBGT_TRG2          equ       %00000100
mDBGT_TRG3          equ       %00001000
mDBGT_BEGIN         equ       %01000000
mDBGT_TRGSEL        equ       %10000000

;*** DBGS - Debug Status Register
DBGS                equ       $00001818           ;*** DBGS - Debug Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGS_CNT0           equ       0                   ; FIFO Valid Count Bit 0
DBGS_CNT1           equ       1                   ; FIFO Valid Count Bit 1
DBGS_CNT2           equ       2                   ; FIFO Valid Count Bit 2
DBGS_CNT3           equ       3                   ; FIFO Valid Count Bit 3
DBGS_ARMF           equ       5                   ; Arm Flag
DBGS_BF             equ       6                   ; Trigger Match B Flag
DBGS_AF             equ       7                   ; Trigger Match A Flag
; bit position masks
mDBGS_CNT0          equ       %00000001
mDBGS_CNT1          equ       %00000010
mDBGS_CNT2          equ       %00000100
mDBGS_CNT3          equ       %00001000
mDBGS_ARMF          equ       %00100000
mDBGS_BF            equ       %01000000
mDBGS_AF            equ       %10000000

;*** FCDIV - FLASH Clock Divider Register
FCDIV               equ       $00001820           ;*** FCDIV - FLASH Clock Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCDIV_DIV0          equ       0                   ; Divisor for FLASH Clock Divider Bit 0
FCDIV_DIV1          equ       1                   ; Divisor for FLASH Clock Divider Bit 1
FCDIV_DIV2          equ       2                   ; Divisor for FLASH Clock Divider Bit 2
FCDIV_DIV3          equ       3                   ; Divisor for FLASH Clock Divider Bit 3
FCDIV_DIV4          equ       4                   ; Divisor for FLASH Clock Divider Bit 4
FCDIV_DIV5          equ       5                   ; Divisor for FLASH Clock Divider Bit 5
FCDIV_PRDIV8        equ       6                   ; Prescale (Divide) FLASH Clock by 8
FCDIV_DIVLD         equ       7                   ; Divisor Loaded Status Flag
; bit position masks
mFCDIV_DIV0         equ       %00000001
mFCDIV_DIV1         equ       %00000010
mFCDIV_DIV2         equ       %00000100
mFCDIV_DIV3         equ       %00001000
mFCDIV_DIV4         equ       %00010000
mFCDIV_DIV5         equ       %00100000
mFCDIV_PRDIV8       equ       %01000000
mFCDIV_DIVLD        equ       %10000000

;*** FOPT - FLASH Options Register
FOPT                equ       $00001821           ;*** FOPT - FLASH Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SEC00          equ       0                   ; Security State Code Bit 0
FOPT_SEC01          equ       1                   ; Security State Code Bit 1
FOPT_FNORED         equ       6                   ; Vector Redirection Disable
FOPT_KEYEN          equ       7                   ; Backdoor Key Mechanism Enable
; bit position masks
mFOPT_SEC00         equ       %00000001
mFOPT_SEC01         equ       %00000010
mFOPT_FNORED        equ       %01000000
mFOPT_KEYEN         equ       %10000000

;*** FCNFG - FLASH Configuration Register
FCNFG               equ       $00001823           ;*** FCNFG - FLASH Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC        equ       5                   ; Enable Writing of Access Key
; bit position masks
mFCNFG_KEYACC       equ       %00100000

;*** FPROT - FLASH Protection Register
FPROT               equ       $00001824           ;*** FPROT - FLASH Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPDIS         equ       0                   ; FLASH Protection Disable
FPROT_FPS1          equ       1                   ; FLASH Protect Select Bit 1
FPROT_FPS2          equ       2                   ; FLASH Protect Select Bit 2
FPROT_FPS3          equ       3                   ; FLASH Protect Select Bit 3
FPROT_FPS4          equ       4                   ; FLASH Protect Select Bit 4
FPROT_FPS5          equ       5                   ; FLASH Protect Select Bit 5
FPROT_FPS6          equ       6                   ; FLASH Protect Select Bit 6
FPROT_FPS7          equ       7                   ; FLASH Protect Select Bit 7
; bit position masks
mFPROT_FPDIS        equ       %00000001
mFPROT_FPS1         equ       %00000010
mFPROT_FPS2         equ       %00000100
mFPROT_FPS3         equ       %00001000
mFPROT_FPS4         equ       %00010000
mFPROT_FPS5         equ       %00100000
mFPROT_FPS6         equ       %01000000
mFPROT_FPS7         equ       %10000000

;*** FSTAT - FLASH Status Register
FSTAT               equ       $00001825           ;*** FSTAT - FLASH Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_FBLANK        equ       2                   ; FLASH Verified as All Blank (erased) Flag
FSTAT_FACCERR       equ       4                   ; Access Error Flag
FSTAT_FPVIOL        equ       5                   ; Protection Violation Flag
FSTAT_FCCF          equ       6                   ; FLASH Command Complete Flag
FSTAT_FCBEF         equ       7                   ; FLASH Command Buffer Empty Flag
; bit position masks
mFSTAT_FBLANK       equ       %00000100
mFSTAT_FACCERR      equ       %00010000
mFSTAT_FPVIOL       equ       %00100000
mFSTAT_FCCF         equ       %01000000
mFSTAT_FCBEF        equ       %10000000

;*** FCMD - FLASH Command Register
FCMD                equ       $00001826           ;*** FCMD - FLASH Command Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCMD_FCMDB0         equ       0                   ; FLASH Command Bit 0
FCMD_FCMDB1         equ       1                   ; FLASH Command Bit 1
FCMD_FCMDB2         equ       2                   ; FLASH Command Bit 2
FCMD_FCMDB3         equ       3                   ; FLASH Command Bit 3
FCMD_FCMDB4         equ       4                   ; FLASH Command Bit 4
FCMD_FCMDB5         equ       5                   ; FLASH Command Bit 5
FCMD_FCMDB6         equ       6                   ; FLASH Command Bit 6
FCMD_FCMDB7         equ       7                   ; FLASH Command Bit 7
; bit position masks
mFCMD_FCMDB0        equ       %00000001
mFCMD_FCMDB1        equ       %00000010
mFCMD_FCMDB2        equ       %00000100
mFCMD_FCMDB3        equ       %00001000
mFCMD_FCMDB4        equ       %00010000
mFCMD_FCMDB5        equ       %00100000
mFCMD_FCMDB6        equ       %01000000
mFCMD_FCMDB7        equ       %10000000

;*** NVBACKKEY0 - Backdoor Comparison Key 0
NVBACKKEY0          equ       $0000FFB0           ;*** NVBACKKEY0 - Backdoor Comparison Key 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY0_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY0_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY0_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY0_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY0_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY0_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY0_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY0_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY0_KEY0    equ       %00000001
mNVBACKKEY0_KEY1    equ       %00000010
mNVBACKKEY0_KEY2    equ       %00000100
mNVBACKKEY0_KEY3    equ       %00001000
mNVBACKKEY0_KEY4    equ       %00010000
mNVBACKKEY0_KEY5    equ       %00100000
mNVBACKKEY0_KEY6    equ       %01000000
mNVBACKKEY0_KEY7    equ       %10000000

;*** NVBACKKEY1 - Backdoor Comparison Key 1
NVBACKKEY1          equ       $0000FFB1           ;*** NVBACKKEY1 - Backdoor Comparison Key 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY1_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY1_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY1_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY1_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY1_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY1_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY1_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY1_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY1_KEY0    equ       %00000001
mNVBACKKEY1_KEY1    equ       %00000010
mNVBACKKEY1_KEY2    equ       %00000100
mNVBACKKEY1_KEY3    equ       %00001000
mNVBACKKEY1_KEY4    equ       %00010000
mNVBACKKEY1_KEY5    equ       %00100000
mNVBACKKEY1_KEY6    equ       %01000000
mNVBACKKEY1_KEY7    equ       %10000000

;*** NVBACKKEY2 - Backdoor Comparison Key 2
NVBACKKEY2          equ       $0000FFB2           ;*** NVBACKKEY2 - Backdoor Comparison Key 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY2_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY2_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY2_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY2_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY2_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY2_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY2_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY2_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY2_KEY0    equ       %00000001
mNVBACKKEY2_KEY1    equ       %00000010
mNVBACKKEY2_KEY2    equ       %00000100
mNVBACKKEY2_KEY3    equ       %00001000
mNVBACKKEY2_KEY4    equ       %00010000
mNVBACKKEY2_KEY5    equ       %00100000
mNVBACKKEY2_KEY6    equ       %01000000
mNVBACKKEY2_KEY7    equ       %10000000

;*** NVBACKKEY3 - Backdoor Comparison Key 3
NVBACKKEY3          equ       $0000FFB3           ;*** NVBACKKEY3 - Backdoor Comparison Key 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY3_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY3_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY3_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY3_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY3_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY3_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY3_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY3_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY3_KEY0    equ       %00000001
mNVBACKKEY3_KEY1    equ       %00000010
mNVBACKKEY3_KEY2    equ       %00000100
mNVBACKKEY3_KEY3    equ       %00001000
mNVBACKKEY3_KEY4    equ       %00010000
mNVBACKKEY3_KEY5    equ       %00100000
mNVBACKKEY3_KEY6    equ       %01000000
mNVBACKKEY3_KEY7    equ       %10000000

;*** NVBACKKEY4 - Backdoor Comparison Key 4
NVBACKKEY4          equ       $0000FFB4           ;*** NVBACKKEY4 - Backdoor Comparison Key 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY4_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY4_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY4_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY4_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY4_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY4_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY4_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY4_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY4_KEY0    equ       %00000001
mNVBACKKEY4_KEY1    equ       %00000010
mNVBACKKEY4_KEY2    equ       %00000100
mNVBACKKEY4_KEY3    equ       %00001000
mNVBACKKEY4_KEY4    equ       %00010000
mNVBACKKEY4_KEY5    equ       %00100000
mNVBACKKEY4_KEY6    equ       %01000000
mNVBACKKEY4_KEY7    equ       %10000000

;*** NVBACKKEY5 - Backdoor Comparison Key 5
NVBACKKEY5          equ       $0000FFB5           ;*** NVBACKKEY5 - Backdoor Comparison Key 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY5_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY5_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY5_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY5_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY5_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY5_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY5_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY5_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY5_KEY0    equ       %00000001
mNVBACKKEY5_KEY1    equ       %00000010
mNVBACKKEY5_KEY2    equ       %00000100
mNVBACKKEY5_KEY3    equ       %00001000
mNVBACKKEY5_KEY4    equ       %00010000
mNVBACKKEY5_KEY5    equ       %00100000
mNVBACKKEY5_KEY6    equ       %01000000
mNVBACKKEY5_KEY7    equ       %10000000

;*** NVBACKKEY6 - Backdoor Comparison Key 6
NVBACKKEY6          equ       $0000FFB6           ;*** NVBACKKEY6 - Backdoor Comparison Key 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY6_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY6_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY6_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY6_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY6_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY6_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY6_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY6_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY6_KEY0    equ       %00000001
mNVBACKKEY6_KEY1    equ       %00000010
mNVBACKKEY6_KEY2    equ       %00000100
mNVBACKKEY6_KEY3    equ       %00001000
mNVBACKKEY6_KEY4    equ       %00010000
mNVBACKKEY6_KEY5    equ       %00100000
mNVBACKKEY6_KEY6    equ       %01000000
mNVBACKKEY6_KEY7    equ       %10000000

;*** NVBACKKEY7 - Backdoor Comparison Key 7
NVBACKKEY7          equ       $0000FFB7           ;*** NVBACKKEY7 - Backdoor Comparison Key 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY7_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY7_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY7_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY7_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY7_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY7_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY7_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY7_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
; bit position masks
mNVBACKKEY7_KEY0    equ       %00000001
mNVBACKKEY7_KEY1    equ       %00000010
mNVBACKKEY7_KEY2    equ       %00000100
mNVBACKKEY7_KEY3    equ       %00001000
mNVBACKKEY7_KEY4    equ       %00010000
mNVBACKKEY7_KEY5    equ       %00100000
mNVBACKKEY7_KEY6    equ       %01000000
mNVBACKKEY7_KEY7    equ       %10000000

;*** NVPROT - Non-volatile FLASH Protection Register
NVPROT              equ       $0000FFBD           ;*** NVPROT - Non-volatile FLASH Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPDIS        equ       0                   ; FLASH Protection Disable
NVPROT_FPS0         equ       1                   ; FLASH Protect Select Bits, bit 0
NVPROT_FPS1         equ       2                   ; FLASH Protect Select Bits, bit 1
NVPROT_FPS2         equ       3                   ; FLASH Protect Select Bits, bit 2
NVPROT_FPS3         equ       4                   ; FLASH Protect Select Bits, bit 3
NVPROT_FPS4         equ       5                   ; FLASH Protect Select Bits, bit 4
NVPROT_FPS5         equ       6                   ; FLASH Protect Select Bits, bit 5
NVPROT_FPS6         equ       7                   ; FLASH Protect Select Bits, bit 6
; bit position masks
mNVPROT_FPDIS       equ       %00000001
mNVPROT_FPS0        equ       %00000010
mNVPROT_FPS1        equ       %00000100
mNVPROT_FPS2        equ       %00001000
mNVPROT_FPS3        equ       %00010000
mNVPROT_FPS4        equ       %00100000
mNVPROT_FPS5        equ       %01000000
mNVPROT_FPS6        equ       %10000000

;*** NVOPT - Non-volatile FLASH Options Register
NVOPT               equ       $0000FFBF           ;*** NVOPT - Non-volatile FLASH Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC00         equ       0                   ; Security State Code Bit 0
NVOPT_SEC01         equ       1                   ; Security State Code Bit 1
NVOPT_FNORED        equ       6                   ; Vector Redirection Disable
NVOPT_KEYEN         equ       7                   ; Backdoor Key Mechanism Enable
; bit position masks
mNVOPT_SEC00        equ       %00000001
mNVOPT_SEC01        equ       %00000010
mNVOPT_FNORED       equ       %01000000
mNVOPT_KEYEN        equ       %10000000

; Flash commands
mBlank              equ       $05
mByteProg           equ       $20
mBurstProg          equ       $25
mMassErase          equ       $41
mPageErase          equ       $40

;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
       #ifndef  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
       #endif
; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------

; EOF
