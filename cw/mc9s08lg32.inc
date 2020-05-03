;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08LG32_80, version 3.00.006 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08lg32.inc
;     Processor : MC9S08LG32CLK
;     FileFormat: V2.32
;     DataSheet : MC9S08LG32RM Rev. 4 2/2009
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 13:41
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;      - 20.1.2009, V3.00.0:
;              - Updated definition of the PINPS1 register: PINPS1[KBI1:8] -> PINPS1[KBI0:7].
;              -   REASON: Changes in the RM(from Rev. 0 Draft B to Rev.3 11/2008).
;      - 12.3.2009, V3.00.1:
;              - Removed register LCDRVC. Removed bits LCDSUPPLY[BBYPASS,HREFSEL].
;              - Added registers NVFTRIM(0xFFAE), NVICSTRM(0xFFAF).
;              -   REASON: Changes in the RM(from Rev.3 11/2008 to Rev. 4 2/2009).
;
;     File-Format-Revisions:
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
ROM                 equ       $00008000
ROM_END             equ       $0000FFAD
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000081F
XROM                equ       $0000FFC0
XROM_END            equ       $0000FFC9
;
Vrtc                equ       $0000FFCA
Vmtim               equ       $0000FFCC
Vtpm2ovf            equ       $0000FFCE
Vtpm2ch5            equ       $0000FFD0
Vtpm2ch4            equ       $0000FFD2
Vtpm2ch3            equ       $0000FFD4
Vtpm2ch2            equ       $0000FFD6
Vtpm2ch1            equ       $0000FFD8
Vtpm2ch0            equ       $0000FFDA
Vadc                equ       $0000FFDC
Vkeyboard           equ       $0000FFDE
Viic                equ       $0000FFE0
Vsci2tx             equ       $0000FFE2
Vsci2rx             equ       $0000FFE4
Vsci2err            equ       $0000FFE6
Vspi                equ       $0000FFE8
Vlcd                equ       $0000FFEA
Vsci1tx             equ       $0000FFEC
Vsci1rx             equ       $0000FFEE
Vsci1err            equ       $0000FFF0
Vtpm1ovf            equ       $0000FFF2
Vtpm1ch1            equ       $0000FFF4
Vtpm1ch0            equ       $0000FFF6
Vlvw                equ       $0000FFF8
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
PTAD_PTAD7          equ       7                   ; Port A Data Register Bit 7
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD1         equ       %00000010
mPTAD_PTAD2         equ       %00000100
mPTAD_PTAD3         equ       %00001000
mPTAD_PTAD4         equ       %00010000
mPTAD_PTAD5         equ       %00100000
mPTAD_PTAD6         equ       %01000000
mPTAD_PTAD7         equ       %10000000


;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000001           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; Data Direction for Port A Bit 0
PTADD_PTADD1        equ       1                   ; Data Direction for Port A Bit 1
PTADD_PTADD2        equ       2                   ; Data Direction for Port A Bit 2
PTADD_PTADD3        equ       3                   ; Data Direction for Port A Bit 3
PTADD_PTADD4        equ       4                   ; Data Direction for Port A Bit 4
PTADD_PTADD5        equ       5                   ; Data Direction for Port A Bit 5
PTADD_PTADD6        equ       6                   ; Data Direction for Port A Bit 6
PTADD_PTADD7        equ       7                   ; Data Direction for Port A Bit 7
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000
mPTADD_PTADD4       equ       %00010000
mPTADD_PTADD5       equ       %00100000
mPTADD_PTADD6       equ       %01000000
mPTADD_PTADD7       equ       %10000000


;*** PTBD - Port B Data Register
PTBD                equ       $00000002           ;*** PTBD - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBD_PTBD0          equ       0                   ; Port B Data Register Bit 0
PTBD_PTBD1          equ       1                   ; Port B Data Register Bit 1
PTBD_PTBD2          equ       2                   ; Port B Data Register Bit 2
PTBD_PTBD3          equ       3                   ; Port B Data Register Bit 3
PTBD_PTBD4          equ       4                   ; Port B Data Register Bit 4
PTBD_PTBD5          equ       5                   ; Port B Data Register Bit 5
PTBD_PTBD6          equ       6                   ; Port B Data Register Bit 6
PTBD_PTBD7          equ       7                   ; Port B Data Register Bit 7
; bit position masks
mPTBD_PTBD0         equ       %00000001
mPTBD_PTBD1         equ       %00000010
mPTBD_PTBD2         equ       %00000100
mPTBD_PTBD3         equ       %00001000
mPTBD_PTBD4         equ       %00010000
mPTBD_PTBD5         equ       %00100000
mPTBD_PTBD6         equ       %01000000
mPTBD_PTBD7         equ       %10000000


;*** PTBDD - Port B Data Direction Register
PTBDD               equ       $00000003           ;*** PTBDD - Port B Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0        equ       0                   ; Data Direction for Port B Bit 0
PTBDD_PTBDD1        equ       1                   ; Data Direction for Port B Bit 1
PTBDD_PTBDD2        equ       2                   ; Data Direction for Port B Bit 2
PTBDD_PTBDD3        equ       3                   ; Data Direction for Port B Bit 3
PTBDD_PTBDD4        equ       4                   ; Data Direction for Port B Bit 4
PTBDD_PTBDD5        equ       5                   ; Data Direction for Port B Bit 5
PTBDD_PTBDD6        equ       6                   ; Data Direction for Port B Bit 6
PTBDD_PTBDD7        equ       7                   ; Data Direction for Port B Bit 7
; bit position masks
mPTBDD_PTBDD0       equ       %00000001
mPTBDD_PTBDD1       equ       %00000010
mPTBDD_PTBDD2       equ       %00000100
mPTBDD_PTBDD3       equ       %00001000
mPTBDD_PTBDD4       equ       %00010000
mPTBDD_PTBDD5       equ       %00100000
mPTBDD_PTBDD6       equ       %01000000
mPTBDD_PTBDD7       equ       %10000000


;*** PTCD - Port C Data Register
PTCD                equ       $00000004           ;*** PTCD - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0          equ       0                   ; Port C Data Register Bit 0
PTCD_PTCD1          equ       1                   ; Port C Data Register Bit 1
PTCD_PTCD2          equ       2                   ; Port C Data Register Bit 2
PTCD_PTCD3          equ       3                   ; Port C Data Register Bit 3
PTCD_PTCD4          equ       4                   ; Port C Data Register Bit 4
PTCD_PTCD5          equ       5                   ; Port C Data Register Bit 5
PTCD_PTCD6          equ       6                   ; Port C Data Register Bit 6
; bit position masks
mPTCD_PTCD0         equ       %00000001
mPTCD_PTCD1         equ       %00000010
mPTCD_PTCD2         equ       %00000100
mPTCD_PTCD3         equ       %00001000
mPTCD_PTCD4         equ       %00010000
mPTCD_PTCD5         equ       %00100000
mPTCD_PTCD6         equ       %01000000


;*** PTCDD - Port C Data Direction Register
PTCDD               equ       $00000005           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; Data Direction for Port C Bit 0
PTCDD_PTCDD1        equ       1                   ; Data Direction for Port C Bit 1
PTCDD_PTCDD2        equ       2                   ; Data Direction for Port C Bit 2
PTCDD_PTCDD3        equ       3                   ; Data Direction for Port C Bit 3
PTCDD_PTCDD4        equ       4                   ; Data Direction for Port C Bit 4
PTCDD_PTCDD5        equ       5                   ; Data Direction for Port C Bit 5
PTCDD_PTCDD6        equ       6                   ; Data Direction for Port C Bit 6
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000
mPTCDD_PTCDD4       equ       %00010000
mPTCDD_PTCDD5       equ       %00100000
mPTCDD_PTCDD6       equ       %01000000


;*** PTDD - Port D Data Register
PTDD                equ       $00000006           ;*** PTDD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0          equ       0                   ; Port D Data Register Bit 0
PTDD_PTDD1          equ       1                   ; Port D Data Register Bit 1
PTDD_PTDD2          equ       2                   ; Port D Data Register Bit 2
PTDD_PTDD3          equ       3                   ; Port D Data Register Bit 3
PTDD_PTDD4          equ       4                   ; Port D Data Register Bit 4
PTDD_PTDD5          equ       5                   ; Port D Data Register Bit 5
PTDD_PTDD6          equ       6                   ; Port D Data Register Bit 6
PTDD_PTDD7          equ       7                   ; Port D Data Register Bit 7
; bit position masks
mPTDD_PTDD0         equ       %00000001
mPTDD_PTDD1         equ       %00000010
mPTDD_PTDD2         equ       %00000100
mPTDD_PTDD3         equ       %00001000
mPTDD_PTDD4         equ       %00010000
mPTDD_PTDD5         equ       %00100000
mPTDD_PTDD6         equ       %01000000
mPTDD_PTDD7         equ       %10000000


;*** PTDDD - Port D Data Direction Register
PTDDD               equ       $00000007           ;*** PTDDD - Port D Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0        equ       0                   ; Data Direction for Port D Bit 0
PTDDD_PTDDD1        equ       1                   ; Data Direction for Port D Bit 1
PTDDD_PTDDD2        equ       2                   ; Data Direction for Port D Bit 2
PTDDD_PTDDD3        equ       3                   ; Data Direction for Port D Bit 3
PTDDD_PTDDD4        equ       4                   ; Data Direction for Port D Bit 4
PTDDD_PTDDD5        equ       5                   ; Data Direction for Port D Bit 5
PTDDD_PTDDD6        equ       6                   ; Data Direction for Port D Bit 6
PTDDD_PTDDD7        equ       7                   ; Data Direction for Port D Bit 7
; bit position masks
mPTDDD_PTDDD0       equ       %00000001
mPTDDD_PTDDD1       equ       %00000010
mPTDDD_PTDDD2       equ       %00000100
mPTDDD_PTDDD3       equ       %00001000
mPTDDD_PTDDD4       equ       %00010000
mPTDDD_PTDDD5       equ       %00100000
mPTDDD_PTDDD6       equ       %01000000
mPTDDD_PTDDD7       equ       %10000000


;*** IICA - IIC Address Register
IICA                equ       $00000008           ;*** IICA - IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA_AD1            equ       1                   ; Slave Address Bit 1
IICA_AD2            equ       2                   ; Slave Address Bit 2
IICA_AD3            equ       3                   ; Slave Address Bit 3
IICA_AD4            equ       4                   ; Slave Address Bit 4
IICA_AD5            equ       5                   ; Slave Address Bit 5
IICA_AD6            equ       6                   ; Slave Address Bit 6
IICA_AD7            equ       7                   ; Slave Address Bit 7
; bit position masks
mIICA_AD1           equ       %00000010
mIICA_AD2           equ       %00000100
mIICA_AD3           equ       %00001000
mIICA_AD4           equ       %00010000
mIICA_AD5           equ       %00100000
mIICA_AD6           equ       %01000000
mIICA_AD7           equ       %10000000


;*** IICF - IIC Frequency Divider Register
IICF                equ       $00000009           ;*** IICF - IIC Frequency Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICF_ICR0           equ       0                   ; IIC Clock Rate Bit 0
IICF_ICR1           equ       1                   ; IIC Clock Rate Bit 1
IICF_ICR2           equ       2                   ; IIC Clock Rate Bit 2
IICF_ICR3           equ       3                   ; IIC Clock Rate Bit 3
IICF_ICR4           equ       4                   ; IIC Clock Rate Bit 4
IICF_ICR5           equ       5                   ; IIC Clock Rate Bit 5
IICF_MULT0          equ       6                   ; Multiplier Factor Bit 0
IICF_MULT1          equ       7                   ; Multiplier Factor Bit 1
; bit position masks
mIICF_ICR0          equ       %00000001
mIICF_ICR1          equ       %00000010
mIICF_ICR2          equ       %00000100
mIICF_ICR3          equ       %00001000
mIICF_ICR4          equ       %00010000
mIICF_ICR5          equ       %00100000
mIICF_MULT0         equ       %01000000
mIICF_MULT1         equ       %10000000


;*** IICC1 - IIC Control Register 1
IICC1               equ       $0000000A           ;*** IICC1 - IIC Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC1_RSTA          equ       2                   ; Repeat START
IICC1_TXAK          equ       3                   ; Transmit Acknowledge Enable
IICC1_TX            equ       4                   ; Transmit Mode Select
IICC1_MST           equ       5                   ; Master Mode Select
IICC1_IICIE         equ       6                   ; IIC Interrupt Enable
IICC1_IICEN         equ       7                   ; IIC Enable
; bit position masks
mIICC1_RSTA         equ       %00000100
mIICC1_TXAK         equ       %00001000
mIICC1_TX           equ       %00010000
mIICC1_MST          equ       %00100000
mIICC1_IICIE        equ       %01000000
mIICC1_IICEN        equ       %10000000


;*** IICC - IIC Control Register
IICC                equ       $0000000A           ;*** IICC - IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC_RSTA           equ       2                   ; Repeat START
IICC_TXAK           equ       3                   ; Transmit Acknowledge Enable
IICC_TX             equ       4                   ; Transmit Mode Select
IICC_MST            equ       5                   ; Master Mode Select
IICC_IICIE          equ       6                   ; IIC Interrupt Enable
IICC_IICEN          equ       7                   ; IIC Enable
; bit position masks
mIICC_RSTA          equ       %00000100
mIICC_TXAK          equ       %00001000
mIICC_TX            equ       %00010000
mIICC_MST           equ       %00100000
mIICC_IICIE         equ       %01000000
mIICC_IICEN         equ       %10000000


;*** IICS - IIC Status Register
IICS                equ       $0000000B           ;*** IICS - IIC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICS_RXAK           equ       0                   ; Receive Acknowledge
IICS_IICIF          equ       1                   ; IIC Interrupt Flag
IICS_SRW            equ       2                   ; Slave Read/Write
IICS_ARBL           equ       4                   ; Arbitration Lost
IICS_BUSY           equ       5                   ; Bus Busy
IICS_IAAS           equ       6                   ; Addressed as a Slave
IICS_TCF            equ       7                   ; Transfer Complete Flag
; bit position masks
mIICS_RXAK          equ       %00000001
mIICS_IICIF         equ       %00000010
mIICS_SRW           equ       %00000100
mIICS_ARBL          equ       %00010000
mIICS_BUSY          equ       %00100000
mIICS_IAAS          equ       %01000000
mIICS_TCF           equ       %10000000


;*** IICD - IIC Data I/O Register
IICD                equ       $0000000C           ;*** IICD - IIC Data I/O Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICD_DATA0          equ       0                   ; IIC Data Bit 0
IICD_DATA1          equ       1                   ; IIC Data Bit 1
IICD_DATA2          equ       2                   ; IIC Data Bit 2
IICD_DATA3          equ       3                   ; IIC Data Bit 3
IICD_DATA4          equ       4                   ; IIC Data Bit 4
IICD_DATA5          equ       5                   ; IIC Data Bit 5
IICD_DATA6          equ       6                   ; IIC Data Bit 6
IICD_DATA7          equ       7                   ; IIC Data Bit 7
; bit position masks
mIICD_DATA0         equ       %00000001
mIICD_DATA1         equ       %00000010
mIICD_DATA2         equ       %00000100
mIICD_DATA3         equ       %00001000
mIICD_DATA4         equ       %00010000
mIICD_DATA5         equ       %00100000
mIICD_DATA6         equ       %01000000
mIICD_DATA7         equ       %10000000


;*** IICC2 - IIC Control Register 2
IICC2               equ       $0000000D           ;*** IICC2 - IIC Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC2_AD8           equ       0                   ; Slave Address Bit 8
IICC2_AD9           equ       1                   ; Slave Address Bit 9
IICC2_AD10          equ       2                   ; Slave Address Bit 10
IICC2_ADEXT         equ       6                   ; Address Extension
IICC2_GCAEN         equ       7                   ; General Call Address Enable
; bit position masks
mIICC2_AD8          equ       %00000001
mIICC2_AD9          equ       %00000010
mIICC2_AD10         equ       %00000100
mIICC2_ADEXT        equ       %01000000
mIICC2_GCAEN        equ       %10000000


;*** PTED - Port E Data Register
PTED                equ       $0000000E           ;*** PTED - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTED_PTED0          equ       0                   ; Port E Data Register Bit 0
PTED_PTED1          equ       1                   ; Port E Data Register Bit 1
PTED_PTED2          equ       2                   ; Port E Data Register Bit 2
PTED_PTED3          equ       3                   ; Port E Data Register Bit 3
PTED_PTED4          equ       4                   ; Port E Data Register Bit 4
PTED_PTED5          equ       5                   ; Port E Data Register Bit 5
PTED_PTED6          equ       6                   ; Port E Data Register Bit 6
PTED_PTED7          equ       7                   ; Port E Data Register Bit 7
; bit position masks
mPTED_PTED0         equ       %00000001
mPTED_PTED1         equ       %00000010
mPTED_PTED2         equ       %00000100
mPTED_PTED3         equ       %00001000
mPTED_PTED4         equ       %00010000
mPTED_PTED5         equ       %00100000
mPTED_PTED6         equ       %01000000
mPTED_PTED7         equ       %10000000


;*** PTEDD - Port E Data Direction Register
PTEDD               equ       $0000000F           ;*** PTEDD - Port E Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0        equ       0                   ; Data Direction for Port E Bit 0
PTEDD_PTEDD1        equ       1                   ; Data Direction for Port E Bit 1
PTEDD_PTEDD2        equ       2                   ; Data Direction for Port E Bit 2
PTEDD_PTEDD3        equ       3                   ; Data Direction for Port E Bit 3
PTEDD_PTEDD4        equ       4                   ; Data Direction for Port E Bit 4
PTEDD_PTEDD5        equ       5                   ; Data Direction for Port E Bit 5
PTEDD_PTEDD6        equ       6                   ; Data Direction for Port E Bit 6
PTEDD_PTEDD7        equ       7                   ; Data Direction for Port E Bit 7
; bit position masks
mPTEDD_PTEDD0       equ       %00000001
mPTEDD_PTEDD1       equ       %00000010
mPTEDD_PTEDD2       equ       %00000100
mPTEDD_PTEDD3       equ       %00001000
mPTEDD_PTEDD4       equ       %00010000
mPTEDD_PTEDD5       equ       %00100000
mPTEDD_PTEDD6       equ       %01000000
mPTEDD_PTEDD7       equ       %10000000


;*** SCI1BD - SCI1 Baud Rate Register
SCI1BD              equ       $00000010           ;*** SCI1BD - SCI1 Baud Rate Register


;*** SCI1BDH - SCI1 Baud Rate Register High
SCI1BDH             equ       $00000010           ;*** SCI1BDH - SCI1 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCI1BDH_RXEDGIE     equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1BDH_LBKDIE      equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1BDH_SBR8       equ       %00000001
mSCI1BDH_SBR9       equ       %00000010
mSCI1BDH_SBR10      equ       %00000100
mSCI1BDH_SBR11      equ       %00001000
mSCI1BDH_SBR12      equ       %00010000
mSCI1BDH_RXEDGIE    equ       %01000000
mSCI1BDH_LBKDIE     equ       %10000000


;*** SCI1BDL - SCI1 Baud Rate Register Low
SCI1BDL             equ       $00000011           ;*** SCI1BDL - SCI1 Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDL_SBR0        equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCI1BDL_SBR1        equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCI1BDL_SBR2        equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCI1BDL_SBR3        equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCI1BDL_SBR4        equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCI1BDL_SBR5        equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCI1BDL_SBR6        equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCI1BDL_SBR7        equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI1BDL_SBR0       equ       %00000001
mSCI1BDL_SBR1       equ       %00000010
mSCI1BDL_SBR2       equ       %00000100
mSCI1BDL_SBR3       equ       %00001000
mSCI1BDL_SBR4       equ       %00010000
mSCI1BDL_SBR5       equ       %00100000
mSCI1BDL_SBR6       equ       %01000000
mSCI1BDL_SBR7       equ       %10000000


;*** SCI1C1 - SCI1 Control Register 1
SCI1C1              equ       $00000012           ;*** SCI1C1 - SCI1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C1_PT           equ       0                   ; Parity Type
SCI1C1_PE           equ       1                   ; Parity Enable
SCI1C1_ILT          equ       2                   ; Idle Line Type Select
SCI1C1_WAKE         equ       3                   ; Receiver Wakeup Method Select
SCI1C1_M            equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI1C1_RSRC         equ       5                   ; Receiver Source Select
SCI1C1_SCISWAI      equ       6                   ; SCI Stops in Wait Mode
SCI1C1_LOOPS        equ       7                   ; Loop Mode Select
; bit position masks
mSCI1C1_PT          equ       %00000001
mSCI1C1_PE          equ       %00000010
mSCI1C1_ILT         equ       %00000100
mSCI1C1_WAKE        equ       %00001000
mSCI1C1_M           equ       %00010000
mSCI1C1_RSRC        equ       %00100000
mSCI1C1_SCISWAI     equ       %01000000
mSCI1C1_LOOPS       equ       %10000000


;*** SCI1C2 - SCI1 Control Register 2
SCI1C2              equ       $00000013           ;*** SCI1C2 - SCI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C2_SBK          equ       0                   ; Send Break
SCI1C2_RWU          equ       1                   ; Receiver Wakeup Control
SCI1C2_RE           equ       2                   ; Receiver Enable
SCI1C2_TE           equ       3                   ; Transmitter Enable
SCI1C2_ILIE         equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCI1C2_RIE          equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCI1C2_TCIE         equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCI1C2_TIE          equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI1C2_SBK         equ       %00000001
mSCI1C2_RWU         equ       %00000010
mSCI1C2_RE          equ       %00000100
mSCI1C2_TE          equ       %00001000
mSCI1C2_ILIE        equ       %00010000
mSCI1C2_RIE         equ       %00100000
mSCI1C2_TCIE        equ       %01000000
mSCI1C2_TIE         equ       %10000000


;*** SCI1S1 - SCI1 Status Register 1
SCI1S1              equ       $00000014           ;*** SCI1S1 - SCI1 Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S1_PF           equ       0                   ; Parity Error Flag
SCI1S1_FE           equ       1                   ; Framing Error Flag
SCI1S1_NF           equ       2                   ; Noise Flag
SCI1S1_OR           equ       3                   ; Receiver Overrun Flag
SCI1S1_IDLE         equ       4                   ; Idle Line Flag
SCI1S1_RDRF         equ       5                   ; Receive Data Register Full Flag
SCI1S1_TC           equ       6                   ; Transmission Complete Flag
SCI1S1_TDRE         equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI1S1_PF          equ       %00000001
mSCI1S1_FE          equ       %00000010
mSCI1S1_NF          equ       %00000100
mSCI1S1_OR          equ       %00001000
mSCI1S1_IDLE        equ       %00010000
mSCI1S1_RDRF        equ       %00100000
mSCI1S1_TC          equ       %01000000
mSCI1S1_TDRE        equ       %10000000


;*** SCI1S2 - SCI1 Status Register 2
SCI1S2              equ       $00000015           ;*** SCI1S2 - SCI1 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF          equ       0                   ; Receiver Active Flag
SCI1S2_LBKDE        equ       1                   ; LIN Break Detection Enable
SCI1S2_BRK13        equ       2                   ; Break Character Generation Length
SCI1S2_RWUID        equ       3                   ; Receive Wake Up Idle Detect
SCI1S2_RXINV        equ       4                   ; Receive Data Inversion
SCI1S2_RXEDGIF      equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI1S2_LBKDIF       equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI1S2_RAF         equ       %00000001
mSCI1S2_LBKDE       equ       %00000010
mSCI1S2_BRK13       equ       %00000100
mSCI1S2_RWUID       equ       %00001000
mSCI1S2_RXINV       equ       %00010000
mSCI1S2_RXEDGIF     equ       %01000000
mSCI1S2_LBKDIF      equ       %10000000


;*** SCI1C3 - SCI1 Control Register 3
SCI1C3              equ       $00000016           ;*** SCI1C3 - SCI1 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI1C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI1C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI1C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI1C3_TXINV        equ       4                   ; Transmit Data Inversion
SCI1C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI1C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE        equ       %00000001
mSCI1C3_FEIE        equ       %00000010
mSCI1C3_NEIE        equ       %00000100
mSCI1C3_ORIE        equ       %00001000
mSCI1C3_TXINV       equ       %00010000
mSCI1C3_TXDIR       equ       %00100000
mSCI1C3_T8          equ       %01000000
mSCI1C3_R8          equ       %10000000


;*** SCI1D - SCI1 Data Register
SCI1D               equ       $00000017           ;*** SCI1D - SCI1 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1D_R0_T0         equ       0                   ; Receive/Transmit Data Bit 0
SCI1D_R1_T1         equ       1                   ; Receive/Transmit Data Bit 1
SCI1D_R2_T2         equ       2                   ; Receive/Transmit Data Bit 2
SCI1D_R3_T3         equ       3                   ; Receive/Transmit Data Bit 3
SCI1D_R4_T4         equ       4                   ; Receive/Transmit Data Bit 4
SCI1D_R5_T5         equ       5                   ; Receive/Transmit Data Bit 5
SCI1D_R6_T6         equ       6                   ; Receive/Transmit Data Bit 6
SCI1D_R7_T7         equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCI1D_R0_T0        equ       %00000001
mSCI1D_R1_T1        equ       %00000010
mSCI1D_R2_T2        equ       %00000100
mSCI1D_R3_T3        equ       %00001000
mSCI1D_R4_T4        equ       %00010000
mSCI1D_R5_T5        equ       %00100000
mSCI1D_R6_T6        equ       %01000000
mSCI1D_R7_T7        equ       %10000000


;*** SCI2BD - SCI2 Baud Rate Register
SCI2BD              equ       $00000018           ;*** SCI2BD - SCI2 Baud Rate Register


;*** SCI2BDH - SCI2 Baud Rate Register High
SCI2BDH             equ       $00000018           ;*** SCI2BDH - SCI2 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI2BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI2BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI2BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI2BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCI2BDH_RXEDGIE     equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI2BDH_LBKDIE      equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI2BDH_SBR8       equ       %00000001
mSCI2BDH_SBR9       equ       %00000010
mSCI2BDH_SBR10      equ       %00000100
mSCI2BDH_SBR11      equ       %00001000
mSCI2BDH_SBR12      equ       %00010000
mSCI2BDH_RXEDGIE    equ       %01000000
mSCI2BDH_LBKDIE     equ       %10000000


;*** SCI2BDL - SCI2 Baud Rate Register Low
SCI2BDL             equ       $00000019           ;*** SCI2BDL - SCI2 Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDL_SBR0        equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCI2BDL_SBR1        equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCI2BDL_SBR2        equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCI2BDL_SBR3        equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCI2BDL_SBR4        equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCI2BDL_SBR5        equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCI2BDL_SBR6        equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCI2BDL_SBR7        equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI2BDL_SBR0       equ       %00000001
mSCI2BDL_SBR1       equ       %00000010
mSCI2BDL_SBR2       equ       %00000100
mSCI2BDL_SBR3       equ       %00001000
mSCI2BDL_SBR4       equ       %00010000
mSCI2BDL_SBR5       equ       %00100000
mSCI2BDL_SBR6       equ       %01000000
mSCI2BDL_SBR7       equ       %10000000


;*** SCI2C1 - SCI2 Control Register 1
SCI2C1              equ       $0000001A           ;*** SCI2C1 - SCI2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C1_PT           equ       0                   ; Parity Type
SCI2C1_PE           equ       1                   ; Parity Enable
SCI2C1_ILT          equ       2                   ; Idle Line Type Select
SCI2C1_WAKE         equ       3                   ; Receiver Wakeup Method Select
SCI2C1_M            equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI2C1_RSRC         equ       5                   ; Receiver Source Select
SCI2C1_SCISWAI      equ       6                   ; SCI Stops in Wait Mode
SCI2C1_LOOPS        equ       7                   ; Loop Mode Select
; bit position masks
mSCI2C1_PT          equ       %00000001
mSCI2C1_PE          equ       %00000010
mSCI2C1_ILT         equ       %00000100
mSCI2C1_WAKE        equ       %00001000
mSCI2C1_M           equ       %00010000
mSCI2C1_RSRC        equ       %00100000
mSCI2C1_SCISWAI     equ       %01000000
mSCI2C1_LOOPS       equ       %10000000


;*** SCI2C2 - SCI2 Control Register 2
SCI2C2              equ       $0000001B           ;*** SCI2C2 - SCI2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C2_SBK          equ       0                   ; Send Break
SCI2C2_RWU          equ       1                   ; Receiver Wakeup Control
SCI2C2_RE           equ       2                   ; Receiver Enable
SCI2C2_TE           equ       3                   ; Transmitter Enable
SCI2C2_ILIE         equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCI2C2_RIE          equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCI2C2_TCIE         equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCI2C2_TIE          equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI2C2_SBK         equ       %00000001
mSCI2C2_RWU         equ       %00000010
mSCI2C2_RE          equ       %00000100
mSCI2C2_TE          equ       %00001000
mSCI2C2_ILIE        equ       %00010000
mSCI2C2_RIE         equ       %00100000
mSCI2C2_TCIE        equ       %01000000
mSCI2C2_TIE         equ       %10000000


;*** SCI2S1 - SCI2 Status Register 1
SCI2S1              equ       $0000001C           ;*** SCI2S1 - SCI2 Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S1_PF           equ       0                   ; Parity Error Flag
SCI2S1_FE           equ       1                   ; Framing Error Flag
SCI2S1_NF           equ       2                   ; Noise Flag
SCI2S1_OR           equ       3                   ; Receiver Overrun Flag
SCI2S1_IDLE         equ       4                   ; Idle Line Flag
SCI2S1_RDRF         equ       5                   ; Receive Data Register Full Flag
SCI2S1_TC           equ       6                   ; Transmission Complete Flag
SCI2S1_TDRE         equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI2S1_PF          equ       %00000001
mSCI2S1_FE          equ       %00000010
mSCI2S1_NF          equ       %00000100
mSCI2S1_OR          equ       %00001000
mSCI2S1_IDLE        equ       %00010000
mSCI2S1_RDRF        equ       %00100000
mSCI2S1_TC          equ       %01000000
mSCI2S1_TDRE        equ       %10000000


;*** SCI2S2 - SCI2 Status Register 2
SCI2S2              equ       $0000001D           ;*** SCI2S2 - SCI2 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S2_RAF          equ       0                   ; Receiver Active Flag
SCI2S2_LBKDE        equ       1                   ; LIN Break Detection Enable
SCI2S2_BRK13        equ       2                   ; Break Character Generation Length
SCI2S2_RWUID        equ       3                   ; Receive Wake Up Idle Detect
SCI2S2_RXINV        equ       4                   ; Receive Data Inversion
SCI2S2_RXEDGIF      equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI2S2_LBKDIF       equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI2S2_RAF         equ       %00000001
mSCI2S2_LBKDE       equ       %00000010
mSCI2S2_BRK13       equ       %00000100
mSCI2S2_RWUID       equ       %00001000
mSCI2S2_RXINV       equ       %00010000
mSCI2S2_RXEDGIF     equ       %01000000
mSCI2S2_LBKDIF      equ       %10000000


;*** SCI2C3 - SCI2 Control Register 3
SCI2C3              equ       $0000001E           ;*** SCI2C3 - SCI2 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI2C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI2C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI2C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI2C3_TXINV        equ       4                   ; Transmit Data Inversion
SCI2C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI2C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI2C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI2C3_PEIE        equ       %00000001
mSCI2C3_FEIE        equ       %00000010
mSCI2C3_NEIE        equ       %00000100
mSCI2C3_ORIE        equ       %00001000
mSCI2C3_TXINV       equ       %00010000
mSCI2C3_TXDIR       equ       %00100000
mSCI2C3_T8          equ       %01000000
mSCI2C3_R8          equ       %10000000


;*** SCI2D - SCI2 Data Register
SCI2D               equ       $0000001F           ;*** SCI2D - SCI2 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2D_R0_T0         equ       0                   ; Receive/Transmit Data Bit 0
SCI2D_R1_T1         equ       1                   ; Receive/Transmit Data Bit 1
SCI2D_R2_T2         equ       2                   ; Receive/Transmit Data Bit 2
SCI2D_R3_T3         equ       3                   ; Receive/Transmit Data Bit 3
SCI2D_R4_T4         equ       4                   ; Receive/Transmit Data Bit 4
SCI2D_R5_T5         equ       5                   ; Receive/Transmit Data Bit 5
SCI2D_R6_T6         equ       6                   ; Receive/Transmit Data Bit 6
SCI2D_R7_T7         equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCI2D_R0_T0        equ       %00000001
mSCI2D_R1_T1        equ       %00000010
mSCI2D_R2_T2        equ       %00000100
mSCI2D_R3_T3        equ       %00001000
mSCI2D_R4_T4        equ       %00010000
mSCI2D_R5_T5        equ       %00100000
mSCI2D_R6_T6        equ       %01000000
mSCI2D_R7_T7        equ       %10000000


;*** TPM2SC - TPM2 Status and Control Register
TPM2SC              equ       $00000020           ;*** TPM2SC - TPM2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2SC_PS0          equ       0                   ; Prescale Divisor Select Bit 0
TPM2SC_PS1          equ       1                   ; Prescale Divisor Select Bit 1
TPM2SC_PS2          equ       2                   ; Prescale Divisor Select Bit 2
TPM2SC_CLKSA        equ       3                   ; Clock Source Select A
TPM2SC_CLKSB        equ       4                   ; Clock Source Select B
TPM2SC_CPWMS        equ       5                   ; Center-Aligned PWM Select
TPM2SC_TOIE         equ       6                   ; Timer Overflow Interrupt Enable
TPM2SC_TOF          equ       7                   ; Timer Overflow Flag
; bit position masks
mTPM2SC_PS0         equ       %00000001
mTPM2SC_PS1         equ       %00000010
mTPM2SC_PS2         equ       %00000100
mTPM2SC_CLKSA       equ       %00001000
mTPM2SC_CLKSB       equ       %00010000
mTPM2SC_CPWMS       equ       %00100000
mTPM2SC_TOIE        equ       %01000000
mTPM2SC_TOF         equ       %10000000


;*** TPM2CNT - TPM2 Timer Counter Register
TPM2CNT             equ       $00000021           ;*** TPM2CNT - TPM2 Timer Counter Register


;*** TPM2CNTH - TPM2 Timer Counter Register High
TPM2CNTH            equ       $00000021           ;*** TPM2CNTH - TPM2 Timer Counter Register High


;*** TPM2CNTL - TPM2 Timer Counter Register Low
TPM2CNTL            equ       $00000022           ;*** TPM2CNTL - TPM2 Timer Counter Register Low


;*** TPM2MOD - TPM2 Timer Counter Modulo Register
TPM2MOD             equ       $00000023           ;*** TPM2MOD - TPM2 Timer Counter Modulo Register


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High
TPM2MODH            equ       $00000023           ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low
TPM2MODL            equ       $00000024           ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $00000025           ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C0SC_ELS0A      equ       2                   ; Edge/Level Select Bit A
TPM2C0SC_ELS0B      equ       3                   ; Edge/Level Select Bit B
TPM2C0SC_MS0A       equ       4                   ; Mode Select A for TPM Channel 0
TPM2C0SC_MS0B       equ       5                   ; Mode Select B for TPM Channel 0
TPM2C0SC_CH0IE      equ       6                   ; Channel 0 Interrupt Enable
TPM2C0SC_CH0F       equ       7                   ; Channel 0 Flag
; bit position masks
mTPM2C0SC_ELS0A     equ       %00000100
mTPM2C0SC_ELS0B     equ       %00001000
mTPM2C0SC_MS0A      equ       %00010000
mTPM2C0SC_MS0B      equ       %00100000
mTPM2C0SC_CH0IE     equ       %01000000
mTPM2C0SC_CH0F      equ       %10000000


;*** TPM2C0V - TPM2 Timer Channel 0 Value Register
TPM2C0V             equ       $00000026           ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $00000026           ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $00000027           ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
TPM2C1SC            equ       $00000028           ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C1SC_ELS1A      equ       2                   ; Edge/Level Select Bit A
TPM2C1SC_ELS1B      equ       3                   ; Edge/Level Select Bit B
TPM2C1SC_MS1A       equ       4                   ; Mode Select A for TPM Channel 1
TPM2C1SC_MS1B       equ       5                   ; Mode Select B for TPM Channel 1
TPM2C1SC_CH1IE      equ       6                   ; Channel 1 Interrupt Enable
TPM2C1SC_CH1F       equ       7                   ; Channel 1 Flag
; bit position masks
mTPM2C1SC_ELS1A     equ       %00000100
mTPM2C1SC_ELS1B     equ       %00001000
mTPM2C1SC_MS1A      equ       %00010000
mTPM2C1SC_MS1B      equ       %00100000
mTPM2C1SC_CH1IE     equ       %01000000
mTPM2C1SC_CH1F      equ       %10000000


;*** TPM2C1V - TPM2 Timer Channel 1 Value Register
TPM2C1V             equ       $00000029           ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High
TPM2C1VH            equ       $00000029           ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low
TPM2C1VL            equ       $0000002A           ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low


;*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register
TPM2C2SC            equ       $0000002B           ;*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C2SC_ELS2A      equ       2                   ; Edge/Level Select Bit A
TPM2C2SC_ELS2B      equ       3                   ; Edge/Level Select Bit B
TPM2C2SC_MS2A       equ       4                   ; Mode Select A for TPM Channel 2
TPM2C2SC_MS2B       equ       5                   ; Mode Select B for TPM Channel 2
TPM2C2SC_CH2IE      equ       6                   ; Channel 2 Interrupt Enable
TPM2C2SC_CH2F       equ       7                   ; Channel 2 Flag
; bit position masks
mTPM2C2SC_ELS2A     equ       %00000100
mTPM2C2SC_ELS2B     equ       %00001000
mTPM2C2SC_MS2A      equ       %00010000
mTPM2C2SC_MS2B      equ       %00100000
mTPM2C2SC_CH2IE     equ       %01000000
mTPM2C2SC_CH2F      equ       %10000000


;*** TPM2C2V - TPM2 Timer Channel 2 Value Register
TPM2C2V             equ       $0000002C           ;*** TPM2C2V - TPM2 Timer Channel 2 Value Register


;*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High
TPM2C2VH            equ       $0000002C           ;*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High


;*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low
TPM2C2VL            equ       $0000002D           ;*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low


;*** TPM2C3SC - TPM2 Timer Channel 3 Status and Control Register
TPM2C3SC            equ       $0000002E           ;*** TPM2C3SC - TPM2 Timer Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C3SC_ELS3A      equ       2                   ; Edge/Level Select Bit A
TPM2C3SC_ELS3B      equ       3                   ; Edge/Level Select Bit B
TPM2C3SC_MS3A       equ       4                   ; Mode Select A for TPM Channel 3
TPM2C3SC_MS3B       equ       5                   ; Mode Select B for TPM Channel 3
TPM2C3SC_CH3IE      equ       6                   ; Channel 3 Interrupt Enable
TPM2C3SC_CH3F       equ       7                   ; Channel 3 Flag
; bit position masks
mTPM2C3SC_ELS3A     equ       %00000100
mTPM2C3SC_ELS3B     equ       %00001000
mTPM2C3SC_MS3A      equ       %00010000
mTPM2C3SC_MS3B      equ       %00100000
mTPM2C3SC_CH3IE     equ       %01000000
mTPM2C3SC_CH3F      equ       %10000000


;*** TPM2C3V - TPM2 Timer Channel 3 Value Register
TPM2C3V             equ       $0000002F           ;*** TPM2C3V - TPM2 Timer Channel 3 Value Register


;*** TPM2C3VH - TPM2 Timer Channel 3 Value Register High
TPM2C3VH            equ       $0000002F           ;*** TPM2C3VH - TPM2 Timer Channel 3 Value Register High


;*** TPM2C3VL - TPM2 Timer Channel 3 Value Register Low
TPM2C3VL            equ       $00000030           ;*** TPM2C3VL - TPM2 Timer Channel 3 Value Register Low


;*** TPM2C4SC - TPM2 Timer Channel 4 Status and Control Register
TPM2C4SC            equ       $00000031           ;*** TPM2C4SC - TPM2 Timer Channel 4 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C4SC_ELS4A      equ       2                   ; Edge/Level Select Bit A
TPM2C4SC_ELS4B      equ       3                   ; Edge/Level Select Bit B
TPM2C4SC_MS4A       equ       4                   ; Mode Select A for TPM Channel 4
TPM2C4SC_MS4B       equ       5                   ; Mode Select B for TPM Channel 4
TPM2C4SC_CH4IE      equ       6                   ; Channel 4 Interrupt Enable
TPM2C4SC_CH4F       equ       7                   ; Channel 4 Flag
; bit position masks
mTPM2C4SC_ELS4A     equ       %00000100
mTPM2C4SC_ELS4B     equ       %00001000
mTPM2C4SC_MS4A      equ       %00010000
mTPM2C4SC_MS4B      equ       %00100000
mTPM2C4SC_CH4IE     equ       %01000000
mTPM2C4SC_CH4F      equ       %10000000


;*** TPM2C4V - TPM2 Timer Channel 4 Value Register
TPM2C4V             equ       $00000032           ;*** TPM2C4V - TPM2 Timer Channel 4 Value Register


;*** TPM2C4VH - TPM2 Timer Channel 4 Value Register High
TPM2C4VH            equ       $00000032           ;*** TPM2C4VH - TPM2 Timer Channel 4 Value Register High


;*** TPM2C4VL - TPM2 Timer Channel 4 Value Register Low
TPM2C4VL            equ       $00000033           ;*** TPM2C4VL - TPM2 Timer Channel 4 Value Register Low


;*** TPM2C5SC - TPM2 Timer Channel 5 Status and Control Register
TPM2C5SC            equ       $00000034           ;*** TPM2C5SC - TPM2 Timer Channel 5 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C5SC_ELS5A      equ       2                   ; Edge/Level Select Bit A
TPM2C5SC_ELS5B      equ       3                   ; Edge/Level Select Bit B
TPM2C5SC_MS5A       equ       4                   ; Mode Select A for TPM Channel 5
TPM2C5SC_MS5B       equ       5                   ; Mode Select B for TPM Channel 5
TPM2C5SC_CH5IE      equ       6                   ; Channel 5 Interrupt Enable
TPM2C5SC_CH5F       equ       7                   ; Channel 5 Flag
; bit position masks
mTPM2C5SC_ELS5A     equ       %00000100
mTPM2C5SC_ELS5B     equ       %00001000
mTPM2C5SC_MS5A      equ       %00010000
mTPM2C5SC_MS5B      equ       %00100000
mTPM2C5SC_CH5IE     equ       %01000000
mTPM2C5SC_CH5F      equ       %10000000


;*** TPM2C5V - TPM2 Timer Channel 5 Value Register
TPM2C5V             equ       $00000035           ;*** TPM2C5V - TPM2 Timer Channel 5 Value Register


;*** TPM2C5VH - TPM2 Timer Channel 5 Value Register High
TPM2C5VH            equ       $00000035           ;*** TPM2C5VH - TPM2 Timer Channel 5 Value Register High


;*** TPM2C5VL - TPM2 Timer Channel 5 Value Register Low
TPM2C5VL            equ       $00000036           ;*** TPM2C5VL - TPM2 Timer Channel 5 Value Register Low


;*** IRQSC - Interrupt request status and control register
IRQSC               equ       $00000037           ;*** IRQSC - Interrupt request status and control register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD        equ       0                   ; IRQ Detection Mode
IRQSC_IRQIE         equ       1                   ; IRQ Interrupt Enable
IRQSC_IRQACK        equ       2                   ; IRQ Acknowledge
IRQSC_IRQF          equ       3                   ; IRQ Flag
IRQSC_IRQPE         equ       4                   ; IRQ Pin Enable
IRQSC_IRQEDG        equ       5                   ; IRQ Edge Select
IRQSC_IRQPDD        equ       6                   ; IRQ Pull Device Disable
; bit position masks
mIRQSC_IRQMOD       equ       %00000001
mIRQSC_IRQIE        equ       %00000010
mIRQSC_IRQACK       equ       %00000100
mIRQSC_IRQF         equ       %00001000
mIRQSC_IRQPE        equ       %00010000
mIRQSC_IRQEDG       equ       %00100000
mIRQSC_IRQPDD       equ       %01000000


;*** LCDC0 - LCD Control Register 0
LCDC0               equ       $00000038           ;*** LCDC0 - LCD Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDC0_DUTY0         equ       0                   ; LCD Duty Select Bit 0
LCDC0_DUTY1         equ       1                   ; LCD Duty Select Bit 1
LCDC0_DUTY2         equ       2                   ; LCD Duty Select Bit 2
LCDC0_LCLK0         equ       3                   ; LCD Clock Prescaler Bit 0
LCDC0_LCLK1         equ       4                   ; LCD Clock Prescaler Bit 1
LCDC0_LCLK2         equ       5                   ; LCD Clock Prescaler Bit 2
LCDC0_SOURCE        equ       6                   ; LCD Clock Source Select
LCDC0_LCDEN         equ       7                   ; LCD Driver Enable
; bit position masks
mLCDC0_DUTY0        equ       %00000001
mLCDC0_DUTY1        equ       %00000010
mLCDC0_DUTY2        equ       %00000100
mLCDC0_LCLK0        equ       %00001000
mLCDC0_LCLK1        equ       %00010000
mLCDC0_LCLK2        equ       %00100000
mLCDC0_SOURCE       equ       %01000000
mLCDC0_LCDEN        equ       %10000000


;*** LCDC1 - LCD Control Register 1
LCDC1               equ       $00000039           ;*** LCDC1 - LCD Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDC1_LCDSTP        equ       0                   ; LCD Module Driver and Charge Pump Stop While in Stop2 or Stop3 Mode
LCDC1_LCDWAI        equ       1                   ; LCD Module Driver and Charge Pump Stop While in Wait Mode
LCDC1_FCDEN         equ       2                   ; Full Complementary Drive Enable
LCDC1_LCDIEN        equ       7                   ; LCD Module Frame Frequency Interrupt Enable
; bit position masks
mLCDC1_LCDSTP       equ       %00000001
mLCDC1_LCDWAI       equ       %00000010
mLCDC1_FCDEN        equ       %00000100
mLCDC1_LCDIEN       equ       %10000000


;*** LCDSUPPLY - LCD Voltage Supply Register
LCDSUPPLY           equ       $0000003A           ;*** LCDSUPPLY - LCD Voltage Supply Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDSUPPLY_VSUPPLY0  equ       0                   ; Voltage Supply Control Bit 0
LCDSUPPLY_VSUPPLY1  equ       1                   ; Voltage Supply Control Bit 1
LCDSUPPLY_LADJ0     equ       4                   ; LCD Module Load Adjust Bit 0
LCDSUPPLY_LADJ1     equ       5                   ; LCD Module Load Adjust Bit 1
LCDSUPPLY_CPSEL     equ       7                   ; Charge Pump or Resistor Bias Select
; bit position masks
mLCDSUPPLY_VSUPPLY0 equ       %00000001
mLCDSUPPLY_VSUPPLY1 equ       %00000010
mLCDSUPPLY_LADJ0    equ       %00010000
mLCDSUPPLY_LADJ1    equ       %00100000
mLCDSUPPLY_CPSEL    equ       %10000000


;*** LCDBCTL - LCD Blink Control Register
LCDBCTL             equ       $0000003C           ;*** LCDBCTL - LCD Blink Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBCTL_BRATE0      equ       0                   ; Blink-Rate Configuration Bit 0
LCDBCTL_BRATE1      equ       1                   ; Blink-Rate Configuration Bit 1
LCDBCTL_BRATE2      equ       2                   ; Blink-Rate Configuration Bit 2
LCDBCTL_BMODE       equ       3                   ; Blink Mode
LCDBCTL_BLANK       equ       5                   ; Blank Display Mode
LCDBCTL_ALT         equ       6                   ; Alternate Display Mode
LCDBCTL_BLINK       equ       7                   ; Blink Command
; bit position masks
mLCDBCTL_BRATE0     equ       %00000001
mLCDBCTL_BRATE1     equ       %00000010
mLCDBCTL_BRATE2     equ       %00000100
mLCDBCTL_BMODE      equ       %00001000
mLCDBCTL_BLANK      equ       %00100000
mLCDBCTL_ALT        equ       %01000000
mLCDBCTL_BLINK      equ       %10000000


;*** LCDS - LCD Status Register
LCDS                equ       $0000003D           ;*** LCDS - LCD Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDS_LCDIF          equ       7                   ; LCD Interrupt Flag
; bit position masks
mLCDS_LCDIF         equ       %10000000


;*** PTFD - Port F Data Register
PTFD                equ       $0000003E           ;*** PTFD - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFD_PTFD0          equ       0                   ; Port F Data Register Bit 0
PTFD_PTFD1          equ       1                   ; Port F Data Register Bit 1
PTFD_PTFD2          equ       2                   ; Port F Data Register Bit 2
PTFD_PTFD3          equ       3                   ; Port F Data Register Bit 3
PTFD_PTFD4          equ       4                   ; Port F Data Register Bit 4
PTFD_PTFD5          equ       5                   ; Port F Data Register Bit 5
PTFD_PTFD6          equ       6                   ; Port F Data Register Bit 6
PTFD_PTFD7          equ       7                   ; Port F Data Register Bit 7
; bit position masks
mPTFD_PTFD0         equ       %00000001
mPTFD_PTFD1         equ       %00000010
mPTFD_PTFD2         equ       %00000100
mPTFD_PTFD3         equ       %00001000
mPTFD_PTFD4         equ       %00010000
mPTFD_PTFD5         equ       %00100000
mPTFD_PTFD6         equ       %01000000
mPTFD_PTFD7         equ       %10000000


;*** PTFDD - Port F Data Direction Register
PTFDD               equ       $0000003F           ;*** PTFDD - Port F Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDD_PTFDD0        equ       0                   ; Data Direction for Port F Bit 0
PTFDD_PTFDD1        equ       1                   ; Data Direction for Port F Bit 1
PTFDD_PTFDD2        equ       2                   ; Data Direction for Port F Bit 2
PTFDD_PTFDD3        equ       3                   ; Data Direction for Port F Bit 3
PTFDD_PTFDD4        equ       4                   ; Data Direction for Port F Bit 4
PTFDD_PTFDD5        equ       5                   ; Data Direction for Port F Bit 5
PTFDD_PTFDD6        equ       6                   ; Data Direction for Port F Bit 6
PTFDD_PTFDD7        equ       7                   ; Data Direction for Port F Bit 7
; bit position masks
mPTFDD_PTFDD0       equ       %00000001
mPTFDD_PTFDD1       equ       %00000010
mPTFDD_PTFDD2       equ       %00000100
mPTFDD_PTFDD3       equ       %00001000
mPTFDD_PTFDD4       equ       %00010000
mPTFDD_PTFDD5       equ       %00100000
mPTFDD_PTFDD6       equ       %01000000
mPTFDD_PTFDD7       equ       %10000000


;*** TPM1SC - TPM1 Status and Control Register
TPM1SC              equ       $00000040           ;*** TPM1SC - TPM1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1SC_PS0          equ       0                   ; Prescale Divisor Select Bit 0
TPM1SC_PS1          equ       1                   ; Prescale Divisor Select Bit 1
TPM1SC_PS2          equ       2                   ; Prescale Divisor Select Bit 2
TPM1SC_CLKSA        equ       3                   ; Clock Source Select A
TPM1SC_CLKSB        equ       4                   ; Clock Source Select B
TPM1SC_CPWMS        equ       5                   ; Center-Aligned PWM Select
TPM1SC_TOIE         equ       6                   ; Timer Overflow Interrupt Enable
TPM1SC_TOF          equ       7                   ; Timer Overflow Flag
; bit position masks
mTPM1SC_PS0         equ       %00000001
mTPM1SC_PS1         equ       %00000010
mTPM1SC_PS2         equ       %00000100
mTPM1SC_CLKSA       equ       %00001000
mTPM1SC_CLKSB       equ       %00010000
mTPM1SC_CPWMS       equ       %00100000
mTPM1SC_TOIE        equ       %01000000
mTPM1SC_TOF         equ       %10000000


;*** TPM1CNT - TPM1 Timer Counter Register
TPM1CNT             equ       $00000041           ;*** TPM1CNT - TPM1 Timer Counter Register


;*** TPM1CNTH - TPM1 Timer Counter Register High
TPM1CNTH            equ       $00000041           ;*** TPM1CNTH - TPM1 Timer Counter Register High


;*** TPM1CNTL - TPM1 Timer Counter Register Low
TPM1CNTL            equ       $00000042           ;*** TPM1CNTL - TPM1 Timer Counter Register Low


;*** TPM1MOD - TPM1 Timer Counter Modulo Register
TPM1MOD             equ       $00000043           ;*** TPM1MOD - TPM1 Timer Counter Modulo Register


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High
TPM1MODH            equ       $00000043           ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low
TPM1MODL            equ       $00000044           ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $00000045           ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C0SC_ELS0A      equ       2                   ; Edge/Level Select Bit A
TPM1C0SC_ELS0B      equ       3                   ; Edge/Level Select Bit B
TPM1C0SC_MS0A       equ       4                   ; Mode Select A for TPM Channel 0
TPM1C0SC_MS0B       equ       5                   ; Mode Select B for TPM Channel 0
TPM1C0SC_CH0IE      equ       6                   ; Channel 0 Interrupt Enable
TPM1C0SC_CH0F       equ       7                   ; Channel 0 Flag
; bit position masks
mTPM1C0SC_ELS0A     equ       %00000100
mTPM1C0SC_ELS0B     equ       %00001000
mTPM1C0SC_MS0A      equ       %00010000
mTPM1C0SC_MS0B      equ       %00100000
mTPM1C0SC_CH0IE     equ       %01000000
mTPM1C0SC_CH0F      equ       %10000000


;*** TPM1C0V - TPM1 Timer Channel 0 Value Register
TPM1C0V             equ       $00000046           ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $00000046           ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $00000047           ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $00000048           ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C1SC_ELS1A      equ       2                   ; Edge/Level Select Bit A
TPM1C1SC_ELS1B      equ       3                   ; Edge/Level Select Bit B
TPM1C1SC_MS1A       equ       4                   ; Mode Select A for TPM Channel 1
TPM1C1SC_MS1B       equ       5                   ; Mode Select B for TPM Channel 1
TPM1C1SC_CH1IE      equ       6                   ; Channel 1 Interrupt Enable
TPM1C1SC_CH1F       equ       7                   ; Channel 1 Flag
; bit position masks
mTPM1C1SC_ELS1A     equ       %00000100
mTPM1C1SC_ELS1B     equ       %00001000
mTPM1C1SC_MS1A      equ       %00010000
mTPM1C1SC_MS1B      equ       %00100000
mTPM1C1SC_CH1IE     equ       %01000000
mTPM1C1SC_CH1F      equ       %10000000


;*** TPM1C1V - TPM1 Timer Channel 1 Value Register
TPM1C1V             equ       $00000049           ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $00000049           ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $0000004A           ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low


;*** ADCSC1 - Status and Control Register 1
ADCSC1              equ       $0000004B           ;*** ADCSC1 - Status and Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1_ADCH0        equ       0                   ; Input Channel Select Bit 0
ADCSC1_ADCH1        equ       1                   ; Input Channel Select Bit 1
ADCSC1_ADCH2        equ       2                   ; Input Channel Select Bit 2
ADCSC1_ADCH3        equ       3                   ; Input Channel Select Bit 3
ADCSC1_ADCH4        equ       4                   ; Input Channel Select Bit 4
ADCSC1_ADCO         equ       5                   ; Continuous Conversion Enable - ADCO is used to enable continuous conversions
ADCSC1_AIEN         equ       6                   ; Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while
ADCSC1_COCO         equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1_ADCH0       equ       %00000001
mADCSC1_ADCH1       equ       %00000010
mADCSC1_ADCH2       equ       %00000100
mADCSC1_ADCH3       equ       %00001000
mADCSC1_ADCH4       equ       %00010000
mADCSC1_ADCO        equ       %00100000
mADCSC1_AIEN        equ       %01000000
mADCSC1_COCO        equ       %10000000


;*** ADCSC2 - Status and Control Register 2
ADCSC2              equ       $0000004C           ;*** ADCSC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC2_ACFGT        equ       4                   ; Compare Function Greater Than Enable
ADCSC2_ACFE         equ       5                   ; Compare Function Enable - ACFE is used to enable the compare function
ADCSC2_ADTRG        equ       6                   ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADCSC2_ADACT        equ       7                   ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a
; bit position masks
mADCSC2_ACFGT       equ       %00010000
mADCSC2_ACFE        equ       %00100000
mADCSC2_ADTRG       equ       %01000000
mADCSC2_ADACT       equ       %10000000


;*** ADCR - Data Result Register
ADCR                equ       $0000004D           ;*** ADCR - Data Result Register


;*** ADCRH - Data Result High Register
ADCRH               equ       $0000004D           ;*** ADCRH - Data Result High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRH_ADR8          equ       0                   ; ADC Result Data Bit 8
ADCRH_ADR9          equ       1                   ; ADC Result Data Bit 9
ADCRH_ADR10         equ       2                   ; ADC Result Data Bit 10
ADCRH_ADR11         equ       3                   ; ADC Result Data Bit 11
; bit position masks
mADCRH_ADR8         equ       %00000001
mADCRH_ADR9         equ       %00000010
mADCRH_ADR10        equ       %00000100
mADCRH_ADR11        equ       %00001000


;*** ADCRL - Data Result Low Register
ADCRL               equ       $0000004E           ;*** ADCRL - Data Result Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRL_ADR0          equ       0                   ; ADC Result Data Bit 0
ADCRL_ADR1          equ       1                   ; ADC Result Data Bit 1
ADCRL_ADR2          equ       2                   ; ADC Result Data Bit 2
ADCRL_ADR3          equ       3                   ; ADC Result Data Bit 3
ADCRL_ADR4          equ       4                   ; ADC Result Data Bit 4
ADCRL_ADR5          equ       5                   ; ADC Result Data Bit 5
ADCRL_ADR6          equ       6                   ; ADC Result Data Bit 6
ADCRL_ADR7          equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRL_ADR0         equ       %00000001
mADCRL_ADR1         equ       %00000010
mADCRL_ADR2         equ       %00000100
mADCRL_ADR3         equ       %00001000
mADCRL_ADR4         equ       %00010000
mADCRL_ADR5         equ       %00100000
mADCRL_ADR6         equ       %01000000
mADCRL_ADR7         equ       %10000000


;*** ADCCV - Compare Value Register
ADCCV               equ       $0000004F           ;*** ADCCV - Compare Value Register


;*** ADCCVH - Compare Value High Register
ADCCVH              equ       $0000004F           ;*** ADCCVH - Compare Value High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCVH_ADCV8        equ       0                   ; Compare Function Value 8
ADCCVH_ADCV9        equ       1                   ; Compare Function Value 9
ADCCVH_ADCV10       equ       2                   ; Compare Function Value 10
ADCCVH_ADCV11       equ       3                   ; Compare Function Value 11
; bit position masks
mADCCVH_ADCV8       equ       %00000001
mADCCVH_ADCV9       equ       %00000010
mADCCVH_ADCV10      equ       %00000100
mADCCVH_ADCV11      equ       %00001000


;*** ADCCVL - Compare Value Low Register
ADCCVL              equ       $00000050           ;*** ADCCVL - Compare Value Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCVL_ADCV0        equ       0                   ; Compare Function Value 0
ADCCVL_ADCV1        equ       1                   ; Compare Function Value 1
ADCCVL_ADCV2        equ       2                   ; Compare Function Value 2
ADCCVL_ADCV3        equ       3                   ; Compare Function Value 3
ADCCVL_ADCV4        equ       4                   ; Compare Function Value 4
ADCCVL_ADCV5        equ       5                   ; Compare Function Value 5
ADCCVL_ADCV6        equ       6                   ; Compare Function Value 6
ADCCVL_ADCV7        equ       7                   ; Compare Function Value 7
; bit position masks
mADCCVL_ADCV0       equ       %00000001
mADCCVL_ADCV1       equ       %00000010
mADCCVL_ADCV2       equ       %00000100
mADCCVL_ADCV3       equ       %00001000
mADCCVL_ADCV4       equ       %00010000
mADCCVL_ADCV5       equ       %00100000
mADCCVL_ADCV6       equ       %01000000
mADCCVL_ADCV7       equ       %10000000


;*** ADCCFG - Configuration Register
ADCCFG              equ       $00000051           ;*** ADCCFG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG_ADICLK0      equ       0                   ; Input Clock Select Bit 0
ADCCFG_ADICLK1      equ       1                   ; Input Clock Select Bit 1
ADCCFG_MODE0        equ       2                   ; Conversion Mode Selection Bit 0
ADCCFG_MODE1        equ       3                   ; Conversion Mode Selection Bit 1
ADCCFG_ADLSMP       equ       4                   ; Long Sample Time Configuration
ADCCFG_ADIV0        equ       5                   ; Clock Divide Select Bit 0
ADCCFG_ADIV1        equ       6                   ; Clock Divide Select Bit 1
ADCCFG_ADLPC        equ       7                   ; Low Power Configuration
; bit position masks
mADCCFG_ADICLK0     equ       %00000001
mADCCFG_ADICLK1     equ       %00000010
mADCCFG_MODE0       equ       %00000100
mADCCFG_MODE1       equ       %00001000
mADCCFG_ADLSMP      equ       %00010000
mADCCFG_ADIV0       equ       %00100000
mADCCFG_ADIV1       equ       %01000000
mADCCFG_ADLPC       equ       %10000000


;*** APCTL1 - Pin Control 1 Register
APCTL1              equ       $00000052           ;*** APCTL1 - Pin Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0        equ       0                   ; ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0
APCTL1_ADPC1        equ       1                   ; ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1
APCTL1_ADPC2        equ       2                   ; ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2
APCTL1_ADPC3        equ       3                   ; ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3
APCTL1_ADPC4        equ       4                   ; ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4
APCTL1_ADPC5        equ       5                   ; ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5
APCTL1_ADPC6        equ       6                   ; ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6
APCTL1_ADPC7        equ       7                   ; ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7
; bit position masks
mAPCTL1_ADPC0       equ       %00000001
mAPCTL1_ADPC1       equ       %00000010
mAPCTL1_ADPC2       equ       %00000100
mAPCTL1_ADPC3       equ       %00001000
mAPCTL1_ADPC4       equ       %00010000
mAPCTL1_ADPC5       equ       %00100000
mAPCTL1_ADPC6       equ       %01000000
mAPCTL1_ADPC7       equ       %10000000


;*** APCTL2 - Pin Control 2 Register
APCTL2              equ       $00000053           ;*** APCTL2 - Pin Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL2_ADPC8        equ       0                   ; ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8
APCTL2_ADPC9        equ       1                   ; ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9
APCTL2_ADPC10       equ       2                   ; ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10
APCTL2_ADPC11       equ       3                   ; ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11
APCTL2_ADPC12       equ       4                   ; ADC Pin Control 12 - ADPC12 is used to control the pin associated with channel AD12
APCTL2_ADPC13       equ       5                   ; ADC Pin Control 13 - ADPC13 is used to control the pin associated with channel AD13
APCTL2_ADPC14       equ       6                   ; ADC Pin Control 14 - ADPC14 is used to control the pin associated with channel AD14
APCTL2_ADPC15       equ       7                   ; ADC Pin Control 15 - ADPC15 is used to control the pin associated with channel AD15
; bit position masks
mAPCTL2_ADPC8       equ       %00000001
mAPCTL2_ADPC9       equ       %00000010
mAPCTL2_ADPC10      equ       %00000100
mAPCTL2_ADPC11      equ       %00001000
mAPCTL2_ADPC12      equ       %00010000
mAPCTL2_ADPC13      equ       %00100000
mAPCTL2_ADPC14      equ       %01000000
mAPCTL2_ADPC15      equ       %10000000


;*** PTGD - Port G Data Register
PTGD                equ       $00000054           ;*** PTGD - Port G Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGD_PTGD0          equ       0                   ; Port G Data Register Bit 0
PTGD_PTGD1          equ       1                   ; Port G Data Register Bit 1
PTGD_PTGD2          equ       2                   ; Port G Data Register Bit 2
PTGD_PTGD3          equ       3                   ; Port G Data Register Bit 3
PTGD_PTGD4          equ       4                   ; Port G Data Register Bit 4
PTGD_PTGD5          equ       5                   ; Port G Data Register Bit 5
PTGD_PTGD6          equ       6                   ; Port G Data Register Bit 6
PTGD_PTGD7          equ       7                   ; Port G Data Register Bit 7
; bit position masks
mPTGD_PTGD0         equ       %00000001
mPTGD_PTGD1         equ       %00000010
mPTGD_PTGD2         equ       %00000100
mPTGD_PTGD3         equ       %00001000
mPTGD_PTGD4         equ       %00010000
mPTGD_PTGD5         equ       %00100000
mPTGD_PTGD6         equ       %01000000
mPTGD_PTGD7         equ       %10000000


;*** PTGDD - Port G Data Direction Register
PTGDD               equ       $00000055           ;*** PTGDD - Port G Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDD_PTGDD0        equ       0                   ; Data Direction for Port G Bit 0
PTGDD_PTGDD1        equ       1                   ; Data Direction for Port G Bit 1
PTGDD_PTGDD2        equ       2                   ; Data Direction for Port G Bit 2
PTGDD_PTGDD3        equ       3                   ; Data Direction for Port G Bit 3
PTGDD_PTGDD4        equ       4                   ; Data Direction for Port G Bit 4
PTGDD_PTGDD5        equ       5                   ; Data Direction for Port G Bit 5
PTGDD_PTGDD6        equ       6                   ; Data Direction for Port G Bit 6
PTGDD_PTGDD7        equ       7                   ; Data Direction for Port G Bit 7
; bit position masks
mPTGDD_PTGDD0       equ       %00000001
mPTGDD_PTGDD1       equ       %00000010
mPTGDD_PTGDD2       equ       %00000100
mPTGDD_PTGDD3       equ       %00001000
mPTGDD_PTGDD4       equ       %00010000
mPTGDD_PTGDD5       equ       %00100000
mPTGDD_PTGDD6       equ       %01000000
mPTGDD_PTGDD7       equ       %10000000


;*** PTHD - Port H Data Register
PTHD                equ       $00000056           ;*** PTHD - Port H Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHD_PTHD0          equ       0                   ; Port H Data Register Bit 0
PTHD_PTHD1          equ       1                   ; Port H Data Register Bit 1
PTHD_PTHD2          equ       2                   ; Port H Data Register Bit 2
PTHD_PTHD3          equ       3                   ; Port H Data Register Bit 3
PTHD_PTHD4          equ       4                   ; Port H Data Register Bit 4
PTHD_PTHD5          equ       5                   ; Port H Data Register Bit 5
PTHD_PTHD6          equ       6                   ; Port H Data Register Bit 6
PTHD_PTHD7          equ       7                   ; Port H Data Register Bit 7
; bit position masks
mPTHD_PTHD0         equ       %00000001
mPTHD_PTHD1         equ       %00000010
mPTHD_PTHD2         equ       %00000100
mPTHD_PTHD3         equ       %00001000
mPTHD_PTHD4         equ       %00010000
mPTHD_PTHD5         equ       %00100000
mPTHD_PTHD6         equ       %01000000
mPTHD_PTHD7         equ       %10000000


;*** PTHDD - Port H Data Direction Register
PTHDD               equ       $00000057           ;*** PTHDD - Port H Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDD_PTHDD0        equ       0                   ; Data Direction for Port H Bit 0
PTHDD_PTHDD1        equ       1                   ; Data Direction for Port H Bit 1
PTHDD_PTHDD2        equ       2                   ; Data Direction for Port H Bit 2
PTHDD_PTHDD3        equ       3                   ; Data Direction for Port H Bit 3
PTHDD_PTHDD4        equ       4                   ; Data Direction for Port H Bit 4
PTHDD_PTHDD5        equ       5                   ; Data Direction for Port H Bit 5
PTHDD_PTHDD6        equ       6                   ; Data Direction for Port H Bit 6
PTHDD_PTHDD7        equ       7                   ; Data Direction for Port H Bit 7
; bit position masks
mPTHDD_PTHDD0       equ       %00000001
mPTHDD_PTHDD1       equ       %00000010
mPTHDD_PTHDD2       equ       %00000100
mPTHDD_PTHDD3       equ       %00001000
mPTHDD_PTHDD4       equ       %00010000
mPTHDD_PTHDD5       equ       %00100000
mPTHDD_PTHDD6       equ       %01000000
mPTHDD_PTHDD7       equ       %10000000


;*** SPIC1 - SPI Control Register 1
SPIC1               equ       $00000058           ;*** SPIC1 - SPI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC1_LSBFE         equ       0                   ; LSB First (Shifter Direction)
SPIC1_SSOE          equ       1                   ; Slave Select Output Enable
SPIC1_CPHA          equ       2                   ; Clock Phase
SPIC1_CPOL          equ       3                   ; Clock Polarity
SPIC1_MSTR          equ       4                   ; Master/Slave Mode Select
SPIC1_SPTIE         equ       5                   ; SPI Transmit Interrupt Enable
SPIC1_SPE           equ       6                   ; SPI System Enable
SPIC1_SPIE          equ       7                   ; SPI Interrupt Enable (for SPRF and MODF)
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
SPIC2               equ       $00000059           ;*** SPIC2 - SPI Control Register 2
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
SPIBR               equ       $0000005A           ;*** SPIBR - SPI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIBR_SPR0          equ       0                   ; SPI Baud Rate Divisor Bit 0
SPIBR_SPR1          equ       1                   ; SPI Baud Rate Divisor Bit 1
SPIBR_SPR2          equ       2                   ; SPI Baud Rate Divisor Bit 2
SPIBR_SPR3          equ       3                   ; SPI Baud Rate Divisor Bit 3
SPIBR_SPPR0         equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPIBR_SPPR1         equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPIBR_SPPR2         equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPIBR_SPR0         equ       %00000001
mSPIBR_SPR1         equ       %00000010
mSPIBR_SPR2         equ       %00000100
mSPIBR_SPR3         equ       %00001000
mSPIBR_SPPR0        equ       %00010000
mSPIBR_SPPR1        equ       %00100000
mSPIBR_SPPR2        equ       %01000000


;*** SPIS - SPI Status Register
SPIS                equ       $0000005B           ;*** SPIS - SPI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIS_MODF           equ       4                   ; Master Mode Fault Flag
SPIS_SPTEF          equ       5                   ; SPI Transmit Buffer Empty Flag
SPIS_SPRF           equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPIS_MODF          equ       %00010000
mSPIS_SPTEF         equ       %00100000
mSPIS_SPRF          equ       %10000000


;*** SPID - SPI Data Register
SPID                equ       $0000005D           ;*** SPID - SPI Data Register


;*** PTID - Port I Data Register
PTID                equ       $0000005E           ;*** PTID - Port I Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTID_PTID0          equ       0                   ; Port I Data Register Bit 0
PTID_PTID1          equ       1                   ; Port I Data Register Bit 1
PTID_PTID2          equ       2                   ; Port I Data Register Bit 2
PTID_PTID3          equ       3                   ; Port I Data Register Bit 3
PTID_PTID4          equ       4                   ; Port I Data Register Bit 4
PTID_PTID5          equ       5                   ; Port I Data Register Bit 5
; bit position masks
mPTID_PTID0         equ       %00000001
mPTID_PTID1         equ       %00000010
mPTID_PTID2         equ       %00000100
mPTID_PTID3         equ       %00001000
mPTID_PTID4         equ       %00010000
mPTID_PTID5         equ       %00100000


;*** PTIDD - Port I Data Direction Register
PTIDD               equ       $0000005F           ;*** PTIDD - Port I Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIDD_PTIDD0        equ       0                   ; Data Direction for Port I Bit 0
PTIDD_PTIDD1        equ       1                   ; Data Direction for Port I Bit 1
PTIDD_PTIDD2        equ       2                   ; Data Direction for Port I Bit 2
PTIDD_PTIDD3        equ       3                   ; Data Direction for Port I Bit 3
PTIDD_PTIDD4        equ       4                   ; Data Direction for Port I Bit 4
PTIDD_PTIDD5        equ       5                   ; Data Direction for Port I Bit 5
; bit position masks
mPTIDD_PTIDD0       equ       %00000001
mPTIDD_PTIDD1       equ       %00000010
mPTIDD_PTIDD2       equ       %00000100
mPTIDD_PTIDD3       equ       %00001000
mPTIDD_PTIDD4       equ       %00010000
mPTIDD_PTIDD5       equ       %00100000


;*** LCDPEN0 - LCD Pin Enable Register 0
LCDPEN0             equ       $00000820           ;*** LCDPEN0 - LCD Pin Enable Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN0_PEN0        equ       0                   ; Enable LCD pin 0 for LCD operation
LCDPEN0_PEN1        equ       1                   ; Enable LCD pin 1 for LCD operation
LCDPEN0_PEN2        equ       2                   ; Enable LCD pin 2 for LCD operation
LCDPEN0_PEN3        equ       3                   ; Enable LCD pin 3 for LCD operation
LCDPEN0_PEN4        equ       4                   ; Enable LCD pin 4 for LCD operation
LCDPEN0_PEN5        equ       5                   ; Enable LCD pin 5 for LCD operation
LCDPEN0_PEN6        equ       6                   ; Enable LCD pin 6 for LCD operation
LCDPEN0_PEN7        equ       7                   ; Enable LCD pin 7 for LCD operation
; bit position masks
mLCDPEN0_PEN0       equ       %00000001
mLCDPEN0_PEN1       equ       %00000010
mLCDPEN0_PEN2       equ       %00000100
mLCDPEN0_PEN3       equ       %00001000
mLCDPEN0_PEN4       equ       %00010000
mLCDPEN0_PEN5       equ       %00100000
mLCDPEN0_PEN6       equ       %01000000
mLCDPEN0_PEN7       equ       %10000000


;*** LCDPEN1 - LCD Pin Enable Register 1
LCDPEN1             equ       $00000821           ;*** LCDPEN1 - LCD Pin Enable Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN1_PEN8        equ       0                   ; Enable LCD pin 8 for LCD operation
LCDPEN1_PEN9        equ       1                   ; Enable LCD pin 9 for LCD operation
LCDPEN1_PEN10       equ       2                   ; Enable LCD pin 10 for LCD operation
LCDPEN1_PEN11       equ       3                   ; Enable LCD pin 11 for LCD operation
LCDPEN1_PEN12       equ       4                   ; Enable LCD pin 12 for LCD operation
LCDPEN1_PEN13       equ       5                   ; Enable LCD pin 13 for LCD operation
LCDPEN1_PEN14       equ       6                   ; Enable LCD pin 14 for LCD operation
LCDPEN1_PEN15       equ       7                   ; Enable LCD pin 15 for LCD operation
; bit position masks
mLCDPEN1_PEN8       equ       %00000001
mLCDPEN1_PEN9       equ       %00000010
mLCDPEN1_PEN10      equ       %00000100
mLCDPEN1_PEN11      equ       %00001000
mLCDPEN1_PEN12      equ       %00010000
mLCDPEN1_PEN13      equ       %00100000
mLCDPEN1_PEN14      equ       %01000000
mLCDPEN1_PEN15      equ       %10000000


;*** LCDPEN2 - LCD Pin Enable Register 2
LCDPEN2             equ       $00000822           ;*** LCDPEN2 - LCD Pin Enable Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN2_PEN16       equ       0                   ; Enable LCD pin 16 for LCD operation
LCDPEN2_PEN17       equ       1                   ; Enable LCD pin 17 for LCD operation
LCDPEN2_PEN18       equ       2                   ; Enable LCD pin 18 for LCD operation
LCDPEN2_PEN19       equ       3                   ; Enable LCD pin 19 for LCD operation
LCDPEN2_PEN20       equ       4                   ; Enable LCD pin 20 for LCD operation
LCDPEN2_PEN21       equ       5                   ; Enable LCD pin 21 for LCD operation
LCDPEN2_PEN22       equ       6                   ; Enable LCD pin 22 for LCD operation
LCDPEN2_PEN23       equ       7                   ; Enable LCD pin 23 for LCD operation
; bit position masks
mLCDPEN2_PEN16      equ       %00000001
mLCDPEN2_PEN17      equ       %00000010
mLCDPEN2_PEN18      equ       %00000100
mLCDPEN2_PEN19      equ       %00001000
mLCDPEN2_PEN20      equ       %00010000
mLCDPEN2_PEN21      equ       %00100000
mLCDPEN2_PEN22      equ       %01000000
mLCDPEN2_PEN23      equ       %10000000


;*** LCDPEN3 - LCD Pin Enable Register 3
LCDPEN3             equ       $00000823           ;*** LCDPEN3 - LCD Pin Enable Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN3_PEN24       equ       0                   ; Enable LCD pin 24 for LCD operation
LCDPEN3_PEN25       equ       1                   ; Enable LCD pin 25 for LCD operation
LCDPEN3_PEN26       equ       2                   ; Enable LCD pin 26 for LCD operation
LCDPEN3_PEN27       equ       3                   ; Enable LCD pin 27 for LCD operation
LCDPEN3_PEN28       equ       4                   ; Enable LCD pin 28 for LCD operation
LCDPEN3_PEN29       equ       5                   ; Enable LCD pin 29 for LCD operation
LCDPEN3_PEN30       equ       6                   ; Enable LCD pin 30 for LCD operation
LCDPEN3_PEN31       equ       7                   ; Enable LCD pin 31 for LCD operation
; bit position masks
mLCDPEN3_PEN24      equ       %00000001
mLCDPEN3_PEN25      equ       %00000010
mLCDPEN3_PEN26      equ       %00000100
mLCDPEN3_PEN27      equ       %00001000
mLCDPEN3_PEN28      equ       %00010000
mLCDPEN3_PEN29      equ       %00100000
mLCDPEN3_PEN30      equ       %01000000
mLCDPEN3_PEN31      equ       %10000000


;*** LCDPEN4 - LCD Pin Enable Register 4
LCDPEN4             equ       $00000824           ;*** LCDPEN4 - LCD Pin Enable Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN4_PEN32       equ       0                   ; Enable LCD pin 32 for LCD operation
LCDPEN4_PEN33       equ       1                   ; Enable LCD pin 33 for LCD operation
LCDPEN4_PEN34       equ       2                   ; Enable LCD pin 34 for LCD operation
LCDPEN4_PEN35       equ       3                   ; Enable LCD pin 35 for LCD operation
LCDPEN4_PEN36       equ       4                   ; Enable LCD pin 36 for LCD operation
LCDPEN4_PEN37       equ       5                   ; Enable LCD pin 37 for LCD operation
LCDPEN4_PEN38       equ       6                   ; Enable LCD pin 38 for LCD operation
LCDPEN4_PEN39       equ       7                   ; Enable LCD pin 39 for LCD operation
; bit position masks
mLCDPEN4_PEN32      equ       %00000001
mLCDPEN4_PEN33      equ       %00000010
mLCDPEN4_PEN34      equ       %00000100
mLCDPEN4_PEN35      equ       %00001000
mLCDPEN4_PEN36      equ       %00010000
mLCDPEN4_PEN37      equ       %00100000
mLCDPEN4_PEN38      equ       %01000000
mLCDPEN4_PEN39      equ       %10000000


;*** LCDPEN5 - LCD Pin Enable Register 5
LCDPEN5             equ       $00000825           ;*** LCDPEN5 - LCD Pin Enable Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN5_PEN40       equ       0                   ; Enable LCD pin 40 for LCD operation
LCDPEN5_PEN41       equ       1                   ; Enable LCD pin 41 for LCD operation
LCDPEN5_PEN42       equ       2                   ; Enable LCD pin 42 for LCD operation
LCDPEN5_PEN43       equ       3                   ; Enable LCD pin 43 for LCD operation
LCDPEN5_PEN44       equ       4                   ; Enable LCD pin 44 for LCD operation
; bit position masks
mLCDPEN5_PEN40      equ       %00000001
mLCDPEN5_PEN41      equ       %00000010
mLCDPEN5_PEN42      equ       %00000100
mLCDPEN5_PEN43      equ       %00001000
mLCDPEN5_PEN44      equ       %00010000


;*** LCDBPEN0 - LCD Backplane Enable Register 0
LCDBPEN0            equ       $00000828           ;*** LCDBPEN0 - LCD Backplane Enable Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN0_BPEN0      equ       0                   ; Enable LCD pin 0 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN1      equ       1                   ; Enable LCD pin 1 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN2      equ       2                   ; Enable LCD pin 2 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN3      equ       3                   ; Enable LCD pin 3 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN4      equ       4                   ; Enable LCD pin 4 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN5      equ       5                   ; Enable LCD pin 5 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN6      equ       6                   ; Enable LCD pin 6 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN7      equ       7                   ; Enable LCD pin 7 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN0_BPEN0     equ       %00000001
mLCDBPEN0_BPEN1     equ       %00000010
mLCDBPEN0_BPEN2     equ       %00000100
mLCDBPEN0_BPEN3     equ       %00001000
mLCDBPEN0_BPEN4     equ       %00010000
mLCDBPEN0_BPEN5     equ       %00100000
mLCDBPEN0_BPEN6     equ       %01000000
mLCDBPEN0_BPEN7     equ       %10000000


;*** LCDBPEN1 - LCD Backplane Enable Register 1
LCDBPEN1            equ       $00000829           ;*** LCDBPEN1 - LCD Backplane Enable Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN1_BPEN8      equ       0                   ; Enable LCD pin 8 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN9      equ       1                   ; Enable LCD pin 9 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN10     equ       2                   ; Enable LCD pin 10 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN11     equ       3                   ; Enable LCD pin 11 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN12     equ       4                   ; Enable LCD pin 12 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN13     equ       5                   ; Enable LCD pin 13 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN14     equ       6                   ; Enable LCD pin 14 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN15     equ       7                   ; Enable LCD pin 15 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN1_BPEN8     equ       %00000001
mLCDBPEN1_BPEN9     equ       %00000010
mLCDBPEN1_BPEN10    equ       %00000100
mLCDBPEN1_BPEN11    equ       %00001000
mLCDBPEN1_BPEN12    equ       %00010000
mLCDBPEN1_BPEN13    equ       %00100000
mLCDBPEN1_BPEN14    equ       %01000000
mLCDBPEN1_BPEN15    equ       %10000000


;*** LCDBPEN2 - LCD Backplane Enable Register 2
LCDBPEN2            equ       $0000082A           ;*** LCDBPEN2 - LCD Backplane Enable Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN2_BPEN16     equ       0                   ; Enable LCD pin 16 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN17     equ       1                   ; Enable LCD pin 17 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN18     equ       2                   ; Enable LCD pin 18 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN19     equ       3                   ; Enable LCD pin 19 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN20     equ       4                   ; Enable LCD pin 20 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN21     equ       5                   ; Enable LCD pin 21 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN22     equ       6                   ; Enable LCD pin 22 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN23     equ       7                   ; Enable LCD pin 23 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN2_BPEN16    equ       %00000001
mLCDBPEN2_BPEN17    equ       %00000010
mLCDBPEN2_BPEN18    equ       %00000100
mLCDBPEN2_BPEN19    equ       %00001000
mLCDBPEN2_BPEN20    equ       %00010000
mLCDBPEN2_BPEN21    equ       %00100000
mLCDBPEN2_BPEN22    equ       %01000000
mLCDBPEN2_BPEN23    equ       %10000000


;*** LCDBPEN3 - LCD Backplane Enable Register 3
LCDBPEN3            equ       $0000082B           ;*** LCDBPEN3 - LCD Backplane Enable Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN3_BPEN24     equ       0                   ; Enable LCD pin 24 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN25     equ       1                   ; Enable LCD pin 25 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN26     equ       2                   ; Enable LCD pin 26 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN27     equ       3                   ; Enable LCD pin 27 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN28     equ       4                   ; Enable LCD pin 28 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN29     equ       5                   ; Enable LCD pin 29 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN30     equ       6                   ; Enable LCD pin 30 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN31     equ       7                   ; Enable LCD pin 31 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN3_BPEN24    equ       %00000001
mLCDBPEN3_BPEN25    equ       %00000010
mLCDBPEN3_BPEN26    equ       %00000100
mLCDBPEN3_BPEN27    equ       %00001000
mLCDBPEN3_BPEN28    equ       %00010000
mLCDBPEN3_BPEN29    equ       %00100000
mLCDBPEN3_BPEN30    equ       %01000000
mLCDBPEN3_BPEN31    equ       %10000000


;*** LCDBPEN4 - LCD Backplane Enable Register 4
LCDBPEN4            equ       $0000082C           ;*** LCDBPEN4 - LCD Backplane Enable Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN4_BPEN32     equ       0                   ; Enable LCD pin 32 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN33     equ       1                   ; Enable LCD pin 33 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN34     equ       2                   ; Enable LCD pin 34 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN35     equ       3                   ; Enable LCD pin 35 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN36     equ       4                   ; Enable LCD pin 36 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN37     equ       5                   ; Enable LCD pin 37 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN38     equ       6                   ; Enable LCD pin 38 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN39     equ       7                   ; Enable LCD pin 39 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN4_BPEN32    equ       %00000001
mLCDBPEN4_BPEN33    equ       %00000010
mLCDBPEN4_BPEN34    equ       %00000100
mLCDBPEN4_BPEN35    equ       %00001000
mLCDBPEN4_BPEN36    equ       %00010000
mLCDBPEN4_BPEN37    equ       %00100000
mLCDBPEN4_BPEN38    equ       %01000000
mLCDBPEN4_BPEN39    equ       %10000000


;*** LCDBPEN5 - LCD Backplane Enable Register 5
LCDBPEN5            equ       $0000082D           ;*** LCDBPEN5 - LCD Backplane Enable Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN5_BPEN40     equ       0                   ; Enable LCD pin 40 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN41     equ       1                   ; Enable LCD pin 41 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN42     equ       2                   ; Enable LCD pin 42 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN43     equ       3                   ; Enable LCD pin 43 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN44     equ       4                   ; Enable LCD pin 44 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN5_BPEN40    equ       %00000001
mLCDBPEN5_BPEN41    equ       %00000010
mLCDBPEN5_BPEN42    equ       %00000100
mLCDBPEN5_BPEN43    equ       %00001000
mLCDBPEN5_BPEN44    equ       %00010000


;*** LCDWF0 - LCD Waveform Register 0
LCDWF0              equ       $00000830           ;*** LCDWF0 - LCD Waveform Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF0_BPALCD0      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPBLCD0      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPCLCD0      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPDLCD0      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPELCD0      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPFLCD0      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPGLCD0      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPHLCD0      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF0_BPALCD0     equ       %00000001
mLCDWF0_BPBLCD0     equ       %00000010
mLCDWF0_BPCLCD0     equ       %00000100
mLCDWF0_BPDLCD0     equ       %00001000
mLCDWF0_BPELCD0     equ       %00010000
mLCDWF0_BPFLCD0     equ       %00100000
mLCDWF0_BPGLCD0     equ       %01000000
mLCDWF0_BPHLCD0     equ       %10000000


;*** LCDWF1 - LCD Waveform Register 1
LCDWF1              equ       $00000831           ;*** LCDWF1 - LCD Waveform Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF1_BPALCD1      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPBLCD1      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPCLCD1      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPDLCD1      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPELCD1      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPFLCD1      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPGLCD1      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPHLCD1      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF1_BPALCD1     equ       %00000001
mLCDWF1_BPBLCD1     equ       %00000010
mLCDWF1_BPCLCD1     equ       %00000100
mLCDWF1_BPDLCD1     equ       %00001000
mLCDWF1_BPELCD1     equ       %00010000
mLCDWF1_BPFLCD1     equ       %00100000
mLCDWF1_BPGLCD1     equ       %01000000
mLCDWF1_BPHLCD1     equ       %10000000


;*** LCDWF2 - LCD Waveform Register 2
LCDWF2              equ       $00000832           ;*** LCDWF2 - LCD Waveform Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF2_BPALCD2      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPBLCD2      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPCLCD2      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPDLCD2      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPELCD2      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPFLCD2      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPGLCD2      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPHLCD2      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF2_BPALCD2     equ       %00000001
mLCDWF2_BPBLCD2     equ       %00000010
mLCDWF2_BPCLCD2     equ       %00000100
mLCDWF2_BPDLCD2     equ       %00001000
mLCDWF2_BPELCD2     equ       %00010000
mLCDWF2_BPFLCD2     equ       %00100000
mLCDWF2_BPGLCD2     equ       %01000000
mLCDWF2_BPHLCD2     equ       %10000000


;*** LCDWF3 - LCD Waveform Register 3
LCDWF3              equ       $00000833           ;*** LCDWF3 - LCD Waveform Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF3_BPALCD3      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPBLCD3      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPCLCD3      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPDLCD3      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPELCD3      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPFLCD3      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPGLCD3      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPHLCD3      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF3_BPALCD3     equ       %00000001
mLCDWF3_BPBLCD3     equ       %00000010
mLCDWF3_BPCLCD3     equ       %00000100
mLCDWF3_BPDLCD3     equ       %00001000
mLCDWF3_BPELCD3     equ       %00010000
mLCDWF3_BPFLCD3     equ       %00100000
mLCDWF3_BPGLCD3     equ       %01000000
mLCDWF3_BPHLCD3     equ       %10000000


;*** LCDWF4 - LCD Waveform Register 4
LCDWF4              equ       $00000834           ;*** LCDWF4 - LCD Waveform Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF4_BPALCD4      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPBLCD4      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPCLCD4      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPDLCD4      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPELCD4      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPFLCD4      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPGLCD4      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPHLCD4      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF4_BPALCD4     equ       %00000001
mLCDWF4_BPBLCD4     equ       %00000010
mLCDWF4_BPCLCD4     equ       %00000100
mLCDWF4_BPDLCD4     equ       %00001000
mLCDWF4_BPELCD4     equ       %00010000
mLCDWF4_BPFLCD4     equ       %00100000
mLCDWF4_BPGLCD4     equ       %01000000
mLCDWF4_BPHLCD4     equ       %10000000


;*** LCDWF5 - LCD Waveform Register 5
LCDWF5              equ       $00000835           ;*** LCDWF5 - LCD Waveform Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF5_BPALCD5      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPBLCD5      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPCLCD5      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPDLCD5      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPELCD5      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPFLCD5      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPGLCD5      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPHLCD5      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF5_BPALCD5     equ       %00000001
mLCDWF5_BPBLCD5     equ       %00000010
mLCDWF5_BPCLCD5     equ       %00000100
mLCDWF5_BPDLCD5     equ       %00001000
mLCDWF5_BPELCD5     equ       %00010000
mLCDWF5_BPFLCD5     equ       %00100000
mLCDWF5_BPGLCD5     equ       %01000000
mLCDWF5_BPHLCD5     equ       %10000000


;*** LCDWF6 - LCD Waveform Register 6
LCDWF6              equ       $00000836           ;*** LCDWF6 - LCD Waveform Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF6_BPALCD6      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPBLCD6      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPCLCD6      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPDLCD6      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPELCD6      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPFLCD6      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPGLCD6      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPHLCD6      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF6_BPALCD6     equ       %00000001
mLCDWF6_BPBLCD6     equ       %00000010
mLCDWF6_BPCLCD6     equ       %00000100
mLCDWF6_BPDLCD6     equ       %00001000
mLCDWF6_BPELCD6     equ       %00010000
mLCDWF6_BPFLCD6     equ       %00100000
mLCDWF6_BPGLCD6     equ       %01000000
mLCDWF6_BPHLCD6     equ       %10000000


;*** LCDWF7 - LCD Waveform Register 7
LCDWF7              equ       $00000837           ;*** LCDWF7 - LCD Waveform Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF7_BPALCD7      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPBLCD7      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPCLCD7      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPDLCD7      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPELCD7      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPFLCD7      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPGLCD7      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPHLCD7      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF7_BPALCD7     equ       %00000001
mLCDWF7_BPBLCD7     equ       %00000010
mLCDWF7_BPCLCD7     equ       %00000100
mLCDWF7_BPDLCD7     equ       %00001000
mLCDWF7_BPELCD7     equ       %00010000
mLCDWF7_BPFLCD7     equ       %00100000
mLCDWF7_BPGLCD7     equ       %01000000
mLCDWF7_BPHLCD7     equ       %10000000


;*** LCDWF8 - LCD Waveform Register 8
LCDWF8              equ       $00000838           ;*** LCDWF8 - LCD Waveform Register 8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF8_BPALCD8      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPBLCD8      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPCLCD8      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPDLCD8      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPELCD8      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPFLCD8      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPGLCD8      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPHLCD8      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF8_BPALCD8     equ       %00000001
mLCDWF8_BPBLCD8     equ       %00000010
mLCDWF8_BPCLCD8     equ       %00000100
mLCDWF8_BPDLCD8     equ       %00001000
mLCDWF8_BPELCD8     equ       %00010000
mLCDWF8_BPFLCD8     equ       %00100000
mLCDWF8_BPGLCD8     equ       %01000000
mLCDWF8_BPHLCD8     equ       %10000000


;*** LCDWF9 - LCD Waveform Register 9
LCDWF9              equ       $00000839           ;*** LCDWF9 - LCD Waveform Register 9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF9_BPALCD9      equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPBLCD9      equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPCLCD9      equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPDLCD9      equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPELCD9      equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPFLCD9      equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPGLCD9      equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPHLCD9      equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF9_BPALCD9     equ       %00000001
mLCDWF9_BPBLCD9     equ       %00000010
mLCDWF9_BPCLCD9     equ       %00000100
mLCDWF9_BPDLCD9     equ       %00001000
mLCDWF9_BPELCD9     equ       %00010000
mLCDWF9_BPFLCD9     equ       %00100000
mLCDWF9_BPGLCD9     equ       %01000000
mLCDWF9_BPHLCD9     equ       %10000000


;*** LCDWF10 - LCD Waveform Register 10
LCDWF10             equ       $0000083A           ;*** LCDWF10 - LCD Waveform Register 10
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF10_BPALCD10    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPBLCD10    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPCLCD10    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPDLCD10    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPELCD10    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPFLCD10    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPGLCD10    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPHLCD10    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF10_BPALCD10   equ       %00000001
mLCDWF10_BPBLCD10   equ       %00000010
mLCDWF10_BPCLCD10   equ       %00000100
mLCDWF10_BPDLCD10   equ       %00001000
mLCDWF10_BPELCD10   equ       %00010000
mLCDWF10_BPFLCD10   equ       %00100000
mLCDWF10_BPGLCD10   equ       %01000000
mLCDWF10_BPHLCD10   equ       %10000000


;*** LCDWF11 - LCD Waveform Register 11
LCDWF11             equ       $0000083B           ;*** LCDWF11 - LCD Waveform Register 11
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF11_BPALCD11    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPBLCD11    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPCLCD11    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPDLCD11    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPELCD11    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPFLCD11    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPGLCD11    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPHLCD11    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF11_BPALCD11   equ       %00000001
mLCDWF11_BPBLCD11   equ       %00000010
mLCDWF11_BPCLCD11   equ       %00000100
mLCDWF11_BPDLCD11   equ       %00001000
mLCDWF11_BPELCD11   equ       %00010000
mLCDWF11_BPFLCD11   equ       %00100000
mLCDWF11_BPGLCD11   equ       %01000000
mLCDWF11_BPHLCD11   equ       %10000000


;*** LCDWF12 - LCD Waveform Register 12
LCDWF12             equ       $0000083C           ;*** LCDWF12 - LCD Waveform Register 12
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF12_BPALCD12    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPBLCD12    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPCLCD12    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPDLCD12    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPELCD12    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPFLCD12    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPGLCD12    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPHLCD12    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF12_BPALCD12   equ       %00000001
mLCDWF12_BPBLCD12   equ       %00000010
mLCDWF12_BPCLCD12   equ       %00000100
mLCDWF12_BPDLCD12   equ       %00001000
mLCDWF12_BPELCD12   equ       %00010000
mLCDWF12_BPFLCD12   equ       %00100000
mLCDWF12_BPGLCD12   equ       %01000000
mLCDWF12_BPHLCD12   equ       %10000000


;*** LCDWF13 - LCD Waveform Register 13
LCDWF13             equ       $0000083D           ;*** LCDWF13 - LCD Waveform Register 13
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF13_BPALCD13    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPBLCD13    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPCLCD13    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPDLCD13    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPELCD13    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPFLCD13    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPGLCD13    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPHLCD13    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF13_BPALCD13   equ       %00000001
mLCDWF13_BPBLCD13   equ       %00000010
mLCDWF13_BPCLCD13   equ       %00000100
mLCDWF13_BPDLCD13   equ       %00001000
mLCDWF13_BPELCD13   equ       %00010000
mLCDWF13_BPFLCD13   equ       %00100000
mLCDWF13_BPGLCD13   equ       %01000000
mLCDWF13_BPHLCD13   equ       %10000000


;*** LCDWF14 - LCD Waveform Register 14
LCDWF14             equ       $0000083E           ;*** LCDWF14 - LCD Waveform Register 14
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF14_BPALCD14    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPBLCD14    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPCLCD14    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPDLCD14    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPELCD14    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPFLCD14    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPGLCD14    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPHLCD14    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF14_BPALCD14   equ       %00000001
mLCDWF14_BPBLCD14   equ       %00000010
mLCDWF14_BPCLCD14   equ       %00000100
mLCDWF14_BPDLCD14   equ       %00001000
mLCDWF14_BPELCD14   equ       %00010000
mLCDWF14_BPFLCD14   equ       %00100000
mLCDWF14_BPGLCD14   equ       %01000000
mLCDWF14_BPHLCD14   equ       %10000000


;*** LCDWF15 - LCD Waveform Register 15
LCDWF15             equ       $0000083F           ;*** LCDWF15 - LCD Waveform Register 15
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF15_BPALCD15    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPBLCD15    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPCLCD15    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPDLCD15    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPELCD15    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPFLCD15    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPGLCD15    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPHLCD15    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF15_BPALCD15   equ       %00000001
mLCDWF15_BPBLCD15   equ       %00000010
mLCDWF15_BPCLCD15   equ       %00000100
mLCDWF15_BPDLCD15   equ       %00001000
mLCDWF15_BPELCD15   equ       %00010000
mLCDWF15_BPFLCD15   equ       %00100000
mLCDWF15_BPGLCD15   equ       %01000000
mLCDWF15_BPHLCD15   equ       %10000000


;*** LCDWF16 - LCD Waveform Register 16
LCDWF16             equ       $00000840           ;*** LCDWF16 - LCD Waveform Register 16
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF16_BPALCD16    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPBLCD16    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPCLCD16    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPDLCD16    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPELCD16    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPFLCD16    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPGLCD16    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPHLCD16    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF16_BPALCD16   equ       %00000001
mLCDWF16_BPBLCD16   equ       %00000010
mLCDWF16_BPCLCD16   equ       %00000100
mLCDWF16_BPDLCD16   equ       %00001000
mLCDWF16_BPELCD16   equ       %00010000
mLCDWF16_BPFLCD16   equ       %00100000
mLCDWF16_BPGLCD16   equ       %01000000
mLCDWF16_BPHLCD16   equ       %10000000


;*** LCDWF17 - LCD Waveform Register 17
LCDWF17             equ       $00000841           ;*** LCDWF17 - LCD Waveform Register 17
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF17_BPALCD17    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPBLCD17    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPCLCD17    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPDLCD17    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPELCD17    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPFLCD17    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPGLCD17    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPHLCD17    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF17_BPALCD17   equ       %00000001
mLCDWF17_BPBLCD17   equ       %00000010
mLCDWF17_BPCLCD17   equ       %00000100
mLCDWF17_BPDLCD17   equ       %00001000
mLCDWF17_BPELCD17   equ       %00010000
mLCDWF17_BPFLCD17   equ       %00100000
mLCDWF17_BPGLCD17   equ       %01000000
mLCDWF17_BPHLCD17   equ       %10000000


;*** LCDWF18 - LCD Waveform Register 18
LCDWF18             equ       $00000842           ;*** LCDWF18 - LCD Waveform Register 18
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF18_BPALCD18    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPBLCD18    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPCLCD18    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPDLCD18    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPELCD18    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPFLCD18    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPGLCD18    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPHLCD18    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF18_BPALCD18   equ       %00000001
mLCDWF18_BPBLCD18   equ       %00000010
mLCDWF18_BPCLCD18   equ       %00000100
mLCDWF18_BPDLCD18   equ       %00001000
mLCDWF18_BPELCD18   equ       %00010000
mLCDWF18_BPFLCD18   equ       %00100000
mLCDWF18_BPGLCD18   equ       %01000000
mLCDWF18_BPHLCD18   equ       %10000000


;*** LCDWF19 - LCD Waveform Register 19
LCDWF19             equ       $00000843           ;*** LCDWF19 - LCD Waveform Register 19
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF19_BPALCD19    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPBLCD19    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPCLCD19    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPDLCD19    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPELCD19    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPFLCD19    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPGLCD19    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPHLCD19    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF19_BPALCD19   equ       %00000001
mLCDWF19_BPBLCD19   equ       %00000010
mLCDWF19_BPCLCD19   equ       %00000100
mLCDWF19_BPDLCD19   equ       %00001000
mLCDWF19_BPELCD19   equ       %00010000
mLCDWF19_BPFLCD19   equ       %00100000
mLCDWF19_BPGLCD19   equ       %01000000
mLCDWF19_BPHLCD19   equ       %10000000


;*** LCDWF20 - LCD Waveform Register 20
LCDWF20             equ       $00000844           ;*** LCDWF20 - LCD Waveform Register 20
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF20_BPALCD20    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPBLCD20    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPCLCD20    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPDLCD20    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPELCD20    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPFLCD20    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPGLCD20    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPHLCD20    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF20_BPALCD20   equ       %00000001
mLCDWF20_BPBLCD20   equ       %00000010
mLCDWF20_BPCLCD20   equ       %00000100
mLCDWF20_BPDLCD20   equ       %00001000
mLCDWF20_BPELCD20   equ       %00010000
mLCDWF20_BPFLCD20   equ       %00100000
mLCDWF20_BPGLCD20   equ       %01000000
mLCDWF20_BPHLCD20   equ       %10000000


;*** LCDWF21 - LCD Waveform Register 21
LCDWF21             equ       $00000845           ;*** LCDWF21 - LCD Waveform Register 21
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF21_BPALCD21    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPBLCD21    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPCLCD21    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPDLCD21    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPELCD21    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPFLCD21    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPGLCD21    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPHLCD21    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF21_BPALCD21   equ       %00000001
mLCDWF21_BPBLCD21   equ       %00000010
mLCDWF21_BPCLCD21   equ       %00000100
mLCDWF21_BPDLCD21   equ       %00001000
mLCDWF21_BPELCD21   equ       %00010000
mLCDWF21_BPFLCD21   equ       %00100000
mLCDWF21_BPGLCD21   equ       %01000000
mLCDWF21_BPHLCD21   equ       %10000000


;*** LCDWF22 - LCD Waveform Register 22
LCDWF22             equ       $00000846           ;*** LCDWF22 - LCD Waveform Register 22
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF22_BPALCD22    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPBLCD22    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPCLCD22    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPDLCD22    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPELCD22    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPFLCD22    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPGLCD22    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPHLCD22    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF22_BPALCD22   equ       %00000001
mLCDWF22_BPBLCD22   equ       %00000010
mLCDWF22_BPCLCD22   equ       %00000100
mLCDWF22_BPDLCD22   equ       %00001000
mLCDWF22_BPELCD22   equ       %00010000
mLCDWF22_BPFLCD22   equ       %00100000
mLCDWF22_BPGLCD22   equ       %01000000
mLCDWF22_BPHLCD22   equ       %10000000


;*** LCDWF23 - LCD Waveform Register 23
LCDWF23             equ       $00000847           ;*** LCDWF23 - LCD Waveform Register 23
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF23_BPALCD23    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPBLCD23    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPCLCD23    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPDLCD23    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPELCD23    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPFLCD23    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPGLCD23    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPHLCD23    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF23_BPALCD23   equ       %00000001
mLCDWF23_BPBLCD23   equ       %00000010
mLCDWF23_BPCLCD23   equ       %00000100
mLCDWF23_BPDLCD23   equ       %00001000
mLCDWF23_BPELCD23   equ       %00010000
mLCDWF23_BPFLCD23   equ       %00100000
mLCDWF23_BPGLCD23   equ       %01000000
mLCDWF23_BPHLCD23   equ       %10000000


;*** LCDWF24 - LCD Waveform Register 24
LCDWF24             equ       $00000848           ;*** LCDWF24 - LCD Waveform Register 24
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF24_BPALCD24    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPBLCD24    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPCLCD24    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPDLCD24    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPELCD24    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPFLCD24    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPGLCD24    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPHLCD24    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF24_BPALCD24   equ       %00000001
mLCDWF24_BPBLCD24   equ       %00000010
mLCDWF24_BPCLCD24   equ       %00000100
mLCDWF24_BPDLCD24   equ       %00001000
mLCDWF24_BPELCD24   equ       %00010000
mLCDWF24_BPFLCD24   equ       %00100000
mLCDWF24_BPGLCD24   equ       %01000000
mLCDWF24_BPHLCD24   equ       %10000000


;*** LCDWF25 - LCD Waveform Register 25
LCDWF25             equ       $00000849           ;*** LCDWF25 - LCD Waveform Register 25
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF25_BPALCD25    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPBLCD25    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPCLCD25    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPDLCD25    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPELCD25    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPFLCD25    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPGLCD25    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPHLCD25    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF25_BPALCD25   equ       %00000001
mLCDWF25_BPBLCD25   equ       %00000010
mLCDWF25_BPCLCD25   equ       %00000100
mLCDWF25_BPDLCD25   equ       %00001000
mLCDWF25_BPELCD25   equ       %00010000
mLCDWF25_BPFLCD25   equ       %00100000
mLCDWF25_BPGLCD25   equ       %01000000
mLCDWF25_BPHLCD25   equ       %10000000


;*** LCDWF26 - LCD Waveform Register 26
LCDWF26             equ       $0000084A           ;*** LCDWF26 - LCD Waveform Register 26
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF26_BPALCD26    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPBLCD26    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPCLCD26    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPDLCD26    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPELCD26    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPFLCD26    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPGLCD26    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPHLCD26    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF26_BPALCD26   equ       %00000001
mLCDWF26_BPBLCD26   equ       %00000010
mLCDWF26_BPCLCD26   equ       %00000100
mLCDWF26_BPDLCD26   equ       %00001000
mLCDWF26_BPELCD26   equ       %00010000
mLCDWF26_BPFLCD26   equ       %00100000
mLCDWF26_BPGLCD26   equ       %01000000
mLCDWF26_BPHLCD26   equ       %10000000


;*** LCDWF27 - LCD Waveform Register 27
LCDWF27             equ       $0000084B           ;*** LCDWF27 - LCD Waveform Register 27
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF27_BPALCD27    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPBLCD27    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPCLCD27    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPDLCD27    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPELCD27    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPFLCD27    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPGLCD27    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPHLCD27    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF27_BPALCD27   equ       %00000001
mLCDWF27_BPBLCD27   equ       %00000010
mLCDWF27_BPCLCD27   equ       %00000100
mLCDWF27_BPDLCD27   equ       %00001000
mLCDWF27_BPELCD27   equ       %00010000
mLCDWF27_BPFLCD27   equ       %00100000
mLCDWF27_BPGLCD27   equ       %01000000
mLCDWF27_BPHLCD27   equ       %10000000


;*** LCDWF28 - LCD Waveform Register 28
LCDWF28             equ       $0000084C           ;*** LCDWF28 - LCD Waveform Register 28
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF28_BPALCD28    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPBLCD28    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPCLCD28    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPDLCD28    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPELCD28    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPFLCD28    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPGLCD28    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPHLCD28    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF28_BPALCD28   equ       %00000001
mLCDWF28_BPBLCD28   equ       %00000010
mLCDWF28_BPCLCD28   equ       %00000100
mLCDWF28_BPDLCD28   equ       %00001000
mLCDWF28_BPELCD28   equ       %00010000
mLCDWF28_BPFLCD28   equ       %00100000
mLCDWF28_BPGLCD28   equ       %01000000
mLCDWF28_BPHLCD28   equ       %10000000


;*** LCDWF29 - LCD Waveform Register 29
LCDWF29             equ       $0000084D           ;*** LCDWF29 - LCD Waveform Register 29
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF29_BPALCD29    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPBLCD29    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPCLCD29    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPDLCD29    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPELCD29    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPFLCD29    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPGLCD29    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPHLCD29    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF29_BPALCD29   equ       %00000001
mLCDWF29_BPBLCD29   equ       %00000010
mLCDWF29_BPCLCD29   equ       %00000100
mLCDWF29_BPDLCD29   equ       %00001000
mLCDWF29_BPELCD29   equ       %00010000
mLCDWF29_BPFLCD29   equ       %00100000
mLCDWF29_BPGLCD29   equ       %01000000
mLCDWF29_BPHLCD29   equ       %10000000


;*** LCDWF30 - LCD Waveform Register 30
LCDWF30             equ       $0000084E           ;*** LCDWF30 - LCD Waveform Register 30
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF30_BPALCD30    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPBLCD30    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPCLCD30    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPDLCD30    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPELCD30    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPFLCD30    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPGLCD30    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPHLCD30    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF30_BPALCD30   equ       %00000001
mLCDWF30_BPBLCD30   equ       %00000010
mLCDWF30_BPCLCD30   equ       %00000100
mLCDWF30_BPDLCD30   equ       %00001000
mLCDWF30_BPELCD30   equ       %00010000
mLCDWF30_BPFLCD30   equ       %00100000
mLCDWF30_BPGLCD30   equ       %01000000
mLCDWF30_BPHLCD30   equ       %10000000


;*** LCDWF31 - LCD Waveform Register 31
LCDWF31             equ       $0000084F           ;*** LCDWF31 - LCD Waveform Register 31
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF31_BPALCD31    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPBLCD31    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPCLCD31    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPDLCD31    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPELCD31    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPFLCD31    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPGLCD31    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPHLCD31    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF31_BPALCD31   equ       %00000001
mLCDWF31_BPBLCD31   equ       %00000010
mLCDWF31_BPCLCD31   equ       %00000100
mLCDWF31_BPDLCD31   equ       %00001000
mLCDWF31_BPELCD31   equ       %00010000
mLCDWF31_BPFLCD31   equ       %00100000
mLCDWF31_BPGLCD31   equ       %01000000
mLCDWF31_BPHLCD31   equ       %10000000


;*** LCDWF32 - LCD Waveform Register 32
LCDWF32             equ       $00000850           ;*** LCDWF32 - LCD Waveform Register 32
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF32_BPALCD32    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPBLCD32    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPCLCD32    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPDLCD32    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPELCD32    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPFLCD32    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPGLCD32    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPHLCD32    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF32_BPALCD32   equ       %00000001
mLCDWF32_BPBLCD32   equ       %00000010
mLCDWF32_BPCLCD32   equ       %00000100
mLCDWF32_BPDLCD32   equ       %00001000
mLCDWF32_BPELCD32   equ       %00010000
mLCDWF32_BPFLCD32   equ       %00100000
mLCDWF32_BPGLCD32   equ       %01000000
mLCDWF32_BPHLCD32   equ       %10000000


;*** LCDWF33 - LCD Waveform Register 33
LCDWF33             equ       $00000851           ;*** LCDWF33 - LCD Waveform Register 33
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF33_BPALCD33    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPBLCD33    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPCLCD33    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPDLCD33    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPELCD33    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPFLCD33    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPGLCD33    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPHLCD33    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF33_BPALCD33   equ       %00000001
mLCDWF33_BPBLCD33   equ       %00000010
mLCDWF33_BPCLCD33   equ       %00000100
mLCDWF33_BPDLCD33   equ       %00001000
mLCDWF33_BPELCD33   equ       %00010000
mLCDWF33_BPFLCD33   equ       %00100000
mLCDWF33_BPGLCD33   equ       %01000000
mLCDWF33_BPHLCD33   equ       %10000000


;*** LCDWF34 - LCD Waveform Register 34
LCDWF34             equ       $00000852           ;*** LCDWF34 - LCD Waveform Register 34
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF34_BPALCD34    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPBLCD34    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPCLCD34    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPDLCD34    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPELCD34    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPFLCD34    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPGLCD34    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPHLCD34    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF34_BPALCD34   equ       %00000001
mLCDWF34_BPBLCD34   equ       %00000010
mLCDWF34_BPCLCD34   equ       %00000100
mLCDWF34_BPDLCD34   equ       %00001000
mLCDWF34_BPELCD34   equ       %00010000
mLCDWF34_BPFLCD34   equ       %00100000
mLCDWF34_BPGLCD34   equ       %01000000
mLCDWF34_BPHLCD34   equ       %10000000


;*** LCDWF35 - LCD Waveform Register 35
LCDWF35             equ       $00000853           ;*** LCDWF35 - LCD Waveform Register 35
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF35_BPALCD35    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPBLCD35    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPCLCD35    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPDLCD35    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPELCD35    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPFLCD35    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPGLCD35    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPHLCD35    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF35_BPALCD35   equ       %00000001
mLCDWF35_BPBLCD35   equ       %00000010
mLCDWF35_BPCLCD35   equ       %00000100
mLCDWF35_BPDLCD35   equ       %00001000
mLCDWF35_BPELCD35   equ       %00010000
mLCDWF35_BPFLCD35   equ       %00100000
mLCDWF35_BPGLCD35   equ       %01000000
mLCDWF35_BPHLCD35   equ       %10000000


;*** LCDWF36 - LCD Waveform Register 36
LCDWF36             equ       $00000854           ;*** LCDWF36 - LCD Waveform Register 36
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF36_BPALCD36    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPBLCD36    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPCLCD36    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPDLCD36    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPELCD36    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPFLCD36    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPGLCD36    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPHLCD36    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF36_BPALCD36   equ       %00000001
mLCDWF36_BPBLCD36   equ       %00000010
mLCDWF36_BPCLCD36   equ       %00000100
mLCDWF36_BPDLCD36   equ       %00001000
mLCDWF36_BPELCD36   equ       %00010000
mLCDWF36_BPFLCD36   equ       %00100000
mLCDWF36_BPGLCD36   equ       %01000000
mLCDWF36_BPHLCD36   equ       %10000000


;*** LCDWF37 - LCD Waveform Register 37
LCDWF37             equ       $00000855           ;*** LCDWF37 - LCD Waveform Register 37
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF37_BPALCD37    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPBLCD37    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPCLCD37    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPDLCD37    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPELCD37    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPFLCD37    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPGLCD37    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPHLCD37    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF37_BPALCD37   equ       %00000001
mLCDWF37_BPBLCD37   equ       %00000010
mLCDWF37_BPCLCD37   equ       %00000100
mLCDWF37_BPDLCD37   equ       %00001000
mLCDWF37_BPELCD37   equ       %00010000
mLCDWF37_BPFLCD37   equ       %00100000
mLCDWF37_BPGLCD37   equ       %01000000
mLCDWF37_BPHLCD37   equ       %10000000


;*** LCDWF38 - LCD Waveform Register 38
LCDWF38             equ       $00000856           ;*** LCDWF38 - LCD Waveform Register 38
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF38_BPALCD38    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPBLCD38    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPCLCD38    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPDLCD38    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPELCD38    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPFLCD38    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPGLCD38    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPHLCD38    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF38_BPALCD38   equ       %00000001
mLCDWF38_BPBLCD38   equ       %00000010
mLCDWF38_BPCLCD38   equ       %00000100
mLCDWF38_BPDLCD38   equ       %00001000
mLCDWF38_BPELCD38   equ       %00010000
mLCDWF38_BPFLCD38   equ       %00100000
mLCDWF38_BPGLCD38   equ       %01000000
mLCDWF38_BPHLCD38   equ       %10000000


;*** LCDWF39 - LCD Waveform Register 39
LCDWF39             equ       $00000857           ;*** LCDWF39 - LCD Waveform Register 39
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF39_BPALCD39    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPBLCD39    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPCLCD39    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPDLCD39    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPELCD39    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPFLCD39    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPGLCD39    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPHLCD39    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF39_BPALCD39   equ       %00000001
mLCDWF39_BPBLCD39   equ       %00000010
mLCDWF39_BPCLCD39   equ       %00000100
mLCDWF39_BPDLCD39   equ       %00001000
mLCDWF39_BPELCD39   equ       %00010000
mLCDWF39_BPFLCD39   equ       %00100000
mLCDWF39_BPGLCD39   equ       %01000000
mLCDWF39_BPHLCD39   equ       %10000000


;*** LCDWF40 - LCD Waveform Register 40
LCDWF40             equ       $00000858           ;*** LCDWF40 - LCD Waveform Register 40
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF40_BPALCD40    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPBLCD40    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPCLCD40    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPDLCD40    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPELCD40    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPFLCD40    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPGLCD40    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPHLCD40    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF40_BPALCD40   equ       %00000001
mLCDWF40_BPBLCD40   equ       %00000010
mLCDWF40_BPCLCD40   equ       %00000100
mLCDWF40_BPDLCD40   equ       %00001000
mLCDWF40_BPELCD40   equ       %00010000
mLCDWF40_BPFLCD40   equ       %00100000
mLCDWF40_BPGLCD40   equ       %01000000
mLCDWF40_BPHLCD40   equ       %10000000


;*** LCDWF41 - LCD Waveform Register 41
LCDWF41             equ       $00000859           ;*** LCDWF41 - LCD Waveform Register 41
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF41_BPALCD41    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPBLCD41    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPCLCD41    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPDLCD41    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPELCD41    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPFLCD41    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPGLCD41    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPHLCD41    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF41_BPALCD41   equ       %00000001
mLCDWF41_BPBLCD41   equ       %00000010
mLCDWF41_BPCLCD41   equ       %00000100
mLCDWF41_BPDLCD41   equ       %00001000
mLCDWF41_BPELCD41   equ       %00010000
mLCDWF41_BPFLCD41   equ       %00100000
mLCDWF41_BPGLCD41   equ       %01000000
mLCDWF41_BPHLCD41   equ       %10000000


;*** LCDWF42 - LCD Waveform Register 42
LCDWF42             equ       $0000085A           ;*** LCDWF42 - LCD Waveform Register 42
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF42_BPALCD42    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPBLCD42    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPCLCD42    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPDLCD42    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPELCD42    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPFLCD42    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPGLCD42    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPHLCD42    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF42_BPALCD42   equ       %00000001
mLCDWF42_BPBLCD42   equ       %00000010
mLCDWF42_BPCLCD42   equ       %00000100
mLCDWF42_BPDLCD42   equ       %00001000
mLCDWF42_BPELCD42   equ       %00010000
mLCDWF42_BPFLCD42   equ       %00100000
mLCDWF42_BPGLCD42   equ       %01000000
mLCDWF42_BPHLCD42   equ       %10000000


;*** LCDWF43 - LCD Waveform Register 43
LCDWF43             equ       $0000085B           ;*** LCDWF43 - LCD Waveform Register 43
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF43_BPALCD43    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPBLCD43    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPCLCD43    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPDLCD43    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPELCD43    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPFLCD43    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPGLCD43    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPHLCD43    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF43_BPALCD43   equ       %00000001
mLCDWF43_BPBLCD43   equ       %00000010
mLCDWF43_BPCLCD43   equ       %00000100
mLCDWF43_BPDLCD43   equ       %00001000
mLCDWF43_BPELCD43   equ       %00010000
mLCDWF43_BPFLCD43   equ       %00100000
mLCDWF43_BPGLCD43   equ       %01000000
mLCDWF43_BPHLCD43   equ       %10000000


;*** LCDWF44 - LCD Waveform Register 44
LCDWF44             equ       $0000085C           ;*** LCDWF44 - LCD Waveform Register 44
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF44_BPALCD44    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPBLCD44    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPCLCD44    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPDLCD44    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPELCD44    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPFLCD44    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPGLCD44    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF44_BPHLCD44    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF44_BPALCD44   equ       %00000001
mLCDWF44_BPBLCD44   equ       %00000010
mLCDWF44_BPCLCD44   equ       %00000100
mLCDWF44_BPDLCD44   equ       %00001000
mLCDWF44_BPELCD44   equ       %00010000
mLCDWF44_BPFLCD44   equ       %00100000
mLCDWF44_BPGLCD44   equ       %01000000
mLCDWF44_BPHLCD44   equ       %10000000


;*** SRS - System Reset Status Register
SRS                 equ       $00001800           ;*** SRS - System Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD             equ       1                   ; Low Voltage Detect
SRS_ILAD            equ       3                   ; Illegal Address
SRS_ILOP            equ       4                   ; Illegal Opcode
SRS_COP             equ       5                   ; Computer Operating Properly (COP) Watchdog
SRS_PIN             equ       6                   ; External Reset Pin
SRS_POR             equ       7                   ; Power-On Reset
; bit position masks
mSRS_LVD            equ       %00000010
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
SOPT1_RSTPE         equ       0                   ; RESET Pin Enable
SOPT1_BKGDPE        equ       1                   ; Background Debug Mode Pin Enable
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT          equ       6                   ; COP Watchdog Timeout
SOPT1_COPE          equ       7                   ; COP Watchdog Enable
; bit position masks
mSOPT1_RSTPE        equ       %00000001
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT         equ       %01000000
mSOPT1_COPE         equ       %10000000


;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_SPIFE         equ       0                   ; SPI Filter Enable
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_SPIFE        equ       %00000001
mSOPT2_COPCLKS      equ       %10000000


;*** SDID - System Device Identification Register
SDID                equ       $00001806           ;*** SDID - System Device Identification Register


;*** SDIDH - System Device Identification Register High
SDIDH               equ       $00001806           ;*** SDIDH - System Device Identification Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8           equ       0                   ; Part Identification Number, bit 8
SDIDH_ID9           equ       1                   ; Part Identification Number, bit 9
SDIDH_ID10          equ       2                   ; Part Identification Number, bit 10
SDIDH_ID11          equ       3                   ; Part Identification Number, bit 11
; bit position masks
mSDIDH_ID8          equ       %00000001
mSDIDH_ID9          equ       %00000010
mSDIDH_ID10         equ       %00000100
mSDIDH_ID11         equ       %00001000


;*** SDIDL - System Device Identification Register Low
SDIDL               equ       $00001807           ;*** SDIDL - System Device Identification Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDL_ID0           equ       0                   ; Part Identification Number, bit 0
SDIDL_ID1           equ       1                   ; Part Identification Number, bit 1
SDIDL_ID2           equ       2                   ; Part Identification Number, bit 2
SDIDL_ID3           equ       3                   ; Part Identification Number, bit 3
SDIDL_ID4           equ       4                   ; Part Identification Number, bit 4
SDIDL_ID5           equ       5                   ; Part Identification Number, bit 5
SDIDL_ID6           equ       6                   ; Part Identification Number, bit 6
SDIDL_ID7           equ       7                   ; Part Identification Number, bit 7
; bit position masks
mSDIDL_ID0          equ       %00000001
mSDIDL_ID1          equ       %00000010
mSDIDL_ID2          equ       %00000100
mSDIDL_ID3          equ       %00001000
mSDIDL_ID4          equ       %00010000
mSDIDL_ID5          equ       %00100000
mSDIDL_ID6          equ       %01000000
mSDIDL_ID7          equ       %10000000


;*** SPMSC1 - System Power Management Status and Control 1 Register
SPMSC1              equ       $00001809           ;*** SPMSC1 - System Power Management Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE         equ       0                   ; Bandgap Buffer Enable
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVWIE        equ       5                   ; Low-Voltage Warning Interrupt Enable
SPMSC1_LVWACK       equ       6                   ; Low-Voltage Warning Acknowledge
SPMSC1_LVWF         equ       7                   ; Low-Voltage Warning status
; bit position masks
mSPMSC1_BGBE        equ       %00000001
mSPMSC1_LVDE        equ       %00000100
mSPMSC1_LVDSE       equ       %00001000
mSPMSC1_LVDRE       equ       %00010000
mSPMSC1_LVWIE       equ       %00100000
mSPMSC1_LVWACK      equ       %01000000
mSPMSC1_LVWF        equ       %10000000


;*** SPMSC2 - System Power Management Status and Control 2 Register
SPMSC2              equ       $0000180A           ;*** SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC         equ       0                   ; Partial Power Down Control
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowledge
SPMSC2_PPDF         equ       3                   ; Partial Power Down Flag
SPMSC2_LVWV         equ       4                   ; Low-Voltage Warning Voltage Select
SPMSC2_LVDV         equ       5                   ; Low-Voltage Detect Voltage Select
; bit position masks
mSPMSC2_PPDC        equ       %00000001
mSPMSC2_PPDACK      equ       %00000100
mSPMSC2_PPDF        equ       %00001000
mSPMSC2_LVWV        equ       %00010000
mSPMSC2_LVDV        equ       %00100000


;*** SCGC1 - System Clock Gating Control 1 Register
SCGC1               equ       $0000180E           ;*** SCGC1 - System Clock Gating Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI1          equ       0                   ; SCI1 Clock Gate Control
SCGC1_SCI2          equ       1                   ; SCI2 Clock Gate Control
SCGC1_IIC           equ       2                   ; IIC Clock Gate Control
SCGC1_MTIM          equ       3                   ; MTIM Clock Gate Control
SCGC1_ADC           equ       4                   ; ADC Clock Gate Control
SCGC1_TPM1          equ       5                   ; TPM1 Clock Gate Control
SCGC1_TPM2          equ       6                   ; TPM2 Clock Gate Control
SCGC1_RTC           equ       7                   ; RTC Clock Gate Control
; bit position masks
mSCGC1_SCI1         equ       %00000001
mSCGC1_SCI2         equ       %00000010
mSCGC1_IIC          equ       %00000100
mSCGC1_MTIM         equ       %00001000
mSCGC1_ADC          equ       %00010000
mSCGC1_TPM1         equ       %00100000
mSCGC1_TPM2         equ       %01000000
mSCGC1_RTC          equ       %10000000


;*** SCGC2 - System Clock Gating Control 2 Register
SCGC2               equ       $0000180F           ;*** SCGC2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI           equ       0                   ; SPI Clock Gate Control
SCGC2_LCD           equ       1                   ; LCDClockGateControl
SCGC2_KBI           equ       4                   ; KBI Clock Gate Control
SCGC2_IRQ           equ       5                   ; IRQ Clock Gate Control
SCGC2_FLS           equ       6                   ; FLASH Register Clock Gate Control
SCGC2_DBG           equ       7                   ; DBG Clock Gate Control
; bit position masks
mSCGC2_SPI          equ       %00000001
mSCGC2_LCD          equ       %00000010
mSCGC2_KBI          equ       %00010000
mSCGC2_IRQ          equ       %00100000
mSCGC2_FLS          equ       %01000000
mSCGC2_DBG          equ       %10000000


;*** DBGCA - Debug Comparator A Register
DBGCA               equ       $00001810           ;*** DBGCA - Debug Comparator A Register


;*** DBGCAH - Debug Comparator A High Register
DBGCAH              equ       $00001810           ;*** DBGCAH - Debug Comparator A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAH_Bit8         equ       0                   ; Comparator A High Compare Bit 8
DBGCAH_Bit9         equ       1                   ; Comparator A High Compare Bit 9
DBGCAH_Bit10        equ       2                   ; Comparator A High Compare Bit 10
DBGCAH_Bit11        equ       3                   ; Comparator A High Compare Bit 11
DBGCAH_Bit12        equ       4                   ; Comparator A High Compare Bit 12
DBGCAH_Bit13        equ       5                   ; Comparator A High Compare Bit 13
DBGCAH_Bit14        equ       6                   ; Comparator A High Compare Bit 14
DBGCAH_Bit15        equ       7                   ; Comparator A High Compare Bit 15
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
DBGCAL_Bit0         equ       0                   ; Comparator A Low Compare Bit 0
DBGCAL_Bit1         equ       1                   ; Comparator A Low Compare Bit 1
DBGCAL_Bit2         equ       2                   ; Comparator A Low Compare Bit 2
DBGCAL_Bit3         equ       3                   ; Comparator A Low Compare Bit 3
DBGCAL_Bit4         equ       4                   ; Comparator A Low Compare Bit 4
DBGCAL_Bit5         equ       5                   ; Comparator A Low Compare Bit 5
DBGCAL_Bit6         equ       6                   ; Comparator A Low Compare Bit 6
DBGCAL_Bit7         equ       7                   ; Comparator A Low Compare Bit 7
; bit position masks
mDBGCAL_Bit0        equ       %00000001
mDBGCAL_Bit1        equ       %00000010
mDBGCAL_Bit2        equ       %00000100
mDBGCAL_Bit3        equ       %00001000
mDBGCAL_Bit4        equ       %00010000
mDBGCAL_Bit5        equ       %00100000
mDBGCAL_Bit6        equ       %01000000
mDBGCAL_Bit7        equ       %10000000


;*** DBGCB - Debug Comparator B Register
DBGCB               equ       $00001812           ;*** DBGCB - Debug Comparator B Register


;*** DBGCBH - Debug Comparator B High Register
DBGCBH              equ       $00001812           ;*** DBGCBH - Debug Comparator B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBH_Bit8         equ       0                   ; Comparator B High Compare Bit 8
DBGCBH_Bit9         equ       1                   ; Comparator B High Compare Bit 9
DBGCBH_Bit10        equ       2                   ; Comparator B High Compare Bit 10
DBGCBH_Bit11        equ       3                   ; Comparator B High Compare Bit 11
DBGCBH_Bit12        equ       4                   ; Comparator B High Compare Bit 12
DBGCBH_Bit13        equ       5                   ; Comparator B High Compare Bit 13
DBGCBH_Bit14        equ       6                   ; Comparator B High Compare Bit 14
DBGCBH_Bit15        equ       7                   ; Comparator B High Compare Bit 15
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
DBGCBL_Bit0         equ       0                   ; Comparator B Low Compare Bit 0
DBGCBL_Bit1         equ       1                   ; Comparator B Low Compare Bit 1
DBGCBL_Bit2         equ       2                   ; Comparator B Low Compare Bit 2
DBGCBL_Bit3         equ       3                   ; Comparator B Low Compare Bit 3
DBGCBL_Bit4         equ       4                   ; Comparator B Low Compare Bit 4
DBGCBL_Bit5         equ       5                   ; Comparator B Low Compare Bit 5
DBGCBL_Bit6         equ       6                   ; Comparator B Low Compare Bit 6
DBGCBL_Bit7         equ       7                   ; Comparator B Low Compare Bit 7
; bit position masks
mDBGCBL_Bit0        equ       %00000001
mDBGCBL_Bit1        equ       %00000010
mDBGCBL_Bit2        equ       %00000100
mDBGCBL_Bit3        equ       %00001000
mDBGCBL_Bit4        equ       %00010000
mDBGCBL_Bit5        equ       %00100000
mDBGCBL_Bit6        equ       %01000000
mDBGCBL_Bit7        equ       %10000000


;*** DBGCC - Debug Comparator C Register
DBGCC               equ       $00001814           ;*** DBGCC - Debug Comparator C Register


;*** DBGCCH - Debug Comparator C High Register
DBGCCH              equ       $00001814           ;*** DBGCCH - Debug Comparator C High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCH_Bit8         equ       0                   ; Comparator C High Compare Bit 8
DBGCCH_Bit9         equ       1                   ; Comparator C High Compare Bit 9
DBGCCH_Bit10        equ       2                   ; Comparator C High Compare Bit 10
DBGCCH_Bit11        equ       3                   ; Comparator C High Compare Bit 11
DBGCCH_Bit12        equ       4                   ; Comparator C High Compare Bit 12
DBGCCH_Bit13        equ       5                   ; Comparator C High Compare Bit 13
DBGCCH_Bit14        equ       6                   ; Comparator C High Compare Bit 14
DBGCCH_Bit15        equ       7                   ; Comparator C High Compare Bit 15
; bit position masks
mDBGCCH_Bit8        equ       %00000001
mDBGCCH_Bit9        equ       %00000010
mDBGCCH_Bit10       equ       %00000100
mDBGCCH_Bit11       equ       %00001000
mDBGCCH_Bit12       equ       %00010000
mDBGCCH_Bit13       equ       %00100000
mDBGCCH_Bit14       equ       %01000000
mDBGCCH_Bit15       equ       %10000000


;*** DBGCCL - Debug Comparator C Low Register
DBGCCL              equ       $00001815           ;*** DBGCCL - Debug Comparator C Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCL_Bit0         equ       0                   ; Comparator C Low Compare Bit 0
DBGCCL_Bit1         equ       1                   ; Comparator C Low Compare Bit 1
DBGCCL_Bit2         equ       2                   ; Comparator C Low Compare Bit 2
DBGCCL_Bit3         equ       3                   ; Comparator C Low Compare Bit 3
DBGCCL_Bit4         equ       4                   ; Comparator C Low Compare Bit 4
DBGCCL_Bit5         equ       5                   ; Comparator C Low Compare Bit 5
DBGCCL_Bit6         equ       6                   ; Comparator C Low Compare Bit 6
DBGCCL_Bit7         equ       7                   ; Comparator C Low Compare Bit 7
; bit position masks
mDBGCCL_Bit0        equ       %00000001
mDBGCCL_Bit1        equ       %00000010
mDBGCCL_Bit2        equ       %00000100
mDBGCCL_Bit3        equ       %00001000
mDBGCCL_Bit4        equ       %00010000
mDBGCCL_Bit5        equ       %00100000
mDBGCCL_Bit6        equ       %01000000
mDBGCCL_Bit7        equ       %10000000


;*** DBGF - Debug FIFO Register
DBGF                equ       $00001816           ;*** DBGF - Debug FIFO Register


;*** DBGFH - Debug FIFO High Register
DBGFH               equ       $00001816           ;*** DBGFH - Debug FIFO High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFH_Bit8          equ       0                   ; FIFO High Data Bit 8
DBGFH_Bit9          equ       1                   ; FIFO High Data Bit 9
DBGFH_Bit10         equ       2                   ; FIFO High Data Bit 10
DBGFH_Bit11         equ       3                   ; FIFO High Data Bit 11
DBGFH_Bit12         equ       4                   ; FIFO High Data Bit 12
DBGFH_Bit13         equ       5                   ; FIFO High Data Bit 13
DBGFH_Bit14         equ       6                   ; FIFO High Data Bit 14
DBGFH_Bit15         equ       7                   ; FIFO High Data Bit 15
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
DBGFL               equ       $00001817           ;*** DBGFL - Debug FIFO Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFL_Bit0          equ       0                   ; FIFO Low Data Bit 0
DBGFL_Bit1          equ       1                   ; FIFO Low Data Bit 1
DBGFL_Bit2          equ       2                   ; FIFO Low Data Bit 2
DBGFL_Bit3          equ       3                   ; FIFO Low Data Bit 3
DBGFL_Bit4          equ       4                   ; FIFO Low Data Bit 4
DBGFL_Bit5          equ       5                   ; FIFO Low Data Bit 5
DBGFL_Bit6          equ       6                   ; FIFO Low Data Bit 6
DBGFL_Bit7          equ       7                   ; FIFO Low Data Bit 7
; bit position masks
mDBGFL_Bit0         equ       %00000001
mDBGFL_Bit1         equ       %00000010
mDBGFL_Bit2         equ       %00000100
mDBGFL_Bit3         equ       %00001000
mDBGFL_Bit4         equ       %00010000
mDBGFL_Bit5         equ       %00100000
mDBGFL_Bit6         equ       %01000000
mDBGFL_Bit7         equ       %10000000


;*** DBGCAX - Debug Comparator A Extension Register
DBGCAX              equ       $00001818           ;*** DBGCAX - Debug Comparator A Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAX_RWA          equ       6                   ; Read/Write Comparator A Value Bit
DBGCAX_RWAEN        equ       7                   ; Read/Write Comparator A Enable Bit
; bit position masks
mDBGCAX_RWA         equ       %01000000
mDBGCAX_RWAEN       equ       %10000000


;*** DBGCBX - Debug Comparator B Extension Register
DBGCBX              equ       $00001819           ;*** DBGCBX - Debug Comparator B Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBX_RWB          equ       6                   ; Read/Write Comparator B Value Bit
DBGCBX_RWBEN        equ       7                   ; Read/Write Comparator B Enable Bit
; bit position masks
mDBGCBX_RWB         equ       %01000000
mDBGCBX_RWBEN       equ       %10000000


;*** DBGCCX - Debug Comparator C Extension Register
DBGCCX              equ       $0000181A           ;*** DBGCCX - Debug Comparator C Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCX_RWC          equ       6                   ; Read/Write Comparator C Value Bit
DBGCCX_RWCEN        equ       7                   ; Read/Write Comparator C Enable Bit
; bit position masks
mDBGCCX_RWC         equ       %01000000
mDBGCCX_RWCEN       equ       %10000000


;*** DBGC - Debug Control Register
DBGC                equ       $0000181C           ;*** DBGC - Debug Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC_LOOP1          equ       0                   ; Select LOOP1 Capture Mode
DBGC_BRKEN          equ       4                   ; Break Enable Bit
DBGC_TAG            equ       5                   ; Tag or Force Bit
DBGC_ARM            equ       6                   ; Arm Bit
DBGC_DBGEN          equ       7                   ; DBG Module Enable Bit
; bit position masks
mDBGC_LOOP1         equ       %00000001
mDBGC_BRKEN         equ       %00010000
mDBGC_TAG           equ       %00100000
mDBGC_ARM           equ       %01000000
mDBGC_DBGEN         equ       %10000000


;*** DBGT - Debug Trigger Register
DBGT                equ       $0000181D           ;*** DBGT - Debug Trigger Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGT_TRG0           equ       0                   ; Trigger Mode Bit 0
DBGT_TRG1           equ       1                   ; Trigger Mode Bit 1
DBGT_TRG2           equ       2                   ; Trigger Mode Bit 2
DBGT_TRG3           equ       3                   ; Trigger Mode Bit 3
DBGT_BEGIN          equ       6                   ; Begin/End Trigger Bit
DBGT_TRGSEL         equ       7                   ; Trigger Selection Bit
; bit position masks
mDBGT_TRG0          equ       %00000001
mDBGT_TRG1          equ       %00000010
mDBGT_TRG2          equ       %00000100
mDBGT_TRG3          equ       %00001000
mDBGT_BEGIN         equ       %01000000
mDBGT_TRGSEL        equ       %10000000


;*** DBGS - Debug Status Register
DBGS                equ       $0000181E           ;*** DBGS - Debug Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGS_ARMF           equ       0                   ; Arm Flag Bit
DBGS_CF             equ       5                   ; Trigger C Match Bit
DBGS_BF             equ       6                   ; Trigger B Match Bit
DBGS_AF             equ       7                   ; Trigger A Match Bit
; bit position masks
mDBGS_ARMF          equ       %00000001
mDBGS_CF            equ       %00100000
mDBGS_BF            equ       %01000000
mDBGS_AF            equ       %10000000


;*** DBGCNT - Debug Count Status Register
DBGCNT              equ       $0000181F           ;*** DBGCNT - Debug Count Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCNT_CNT0         equ       0                   ; FIFO Valid Count Bits, bit 0
DBGCNT_CNT1         equ       1                   ; FIFO Valid Count Bits, bit 1
DBGCNT_CNT2         equ       2                   ; FIFO Valid Count Bits, bit 2
DBGCNT_CNT3         equ       3                   ; FIFO Valid Count Bits, bit 3
; bit position masks
mDBGCNT_CNT0        equ       %00000001
mDBGCNT_CNT1        equ       %00000010
mDBGCNT_CNT2        equ       %00000100
mDBGCNT_CNT3        equ       %00001000


;*** FCDIV - FLASH Clock Divider Register
FCDIV               equ       $00001820           ;*** FCDIV - FLASH Clock Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCDIV_DIV0          equ       0                   ; Divisor for FLASH Clock Divider, bit 0
FCDIV_DIV1          equ       1                   ; Divisor for FLASH Clock Divider, bit 1
FCDIV_DIV2          equ       2                   ; Divisor for FLASH Clock Divider, bit 2
FCDIV_DIV3          equ       3                   ; Divisor for FLASH Clock Divider, bit 3
FCDIV_DIV4          equ       4                   ; Divisor for FLASH Clock Divider, bit 4
FCDIV_DIV5          equ       5                   ; Divisor for FLASH Clock Divider, bit 5
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
FOPT_SEC00          equ       0                   ; Security State Code, bit 0
FOPT_SEC01          equ       1                   ; Security State Code, bit 1
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


;*** FSTAT - Flash Status Register
FSTAT               equ       $00001825           ;*** FSTAT - Flash Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_FBLANK        equ       2                   ; FLASH Flag Indicating the Erase Verify Operation Status
FSTAT_FACCERR       equ       4                   ; FLASH Access Error Flag
FSTAT_FPVIOL        equ       5                   ; FLASH Protection Violation Flag
FSTAT_FCCF          equ       6                   ; FLASH Command Complete Interrupt Flag
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
FCMD_FCMD0          equ       0                   ; FLASH Command Bit 0
FCMD_FCMD1          equ       1                   ; FLASH Command Bit 1
FCMD_FCMD2          equ       2                   ; FLASH Command Bit 2
FCMD_FCMD3          equ       3                   ; FLASH Command Bit 3
FCMD_FCMD4          equ       4                   ; FLASH Command Bit 4
FCMD_FCMD5          equ       5                   ; FLASH Command Bit 5
FCMD_FCMD6          equ       6                   ; FLASH Command Bit 6
FCMD_FCMD7          equ       7                   ; FLASH Command Bit 7
; bit position masks
mFCMD_FCMD0         equ       %00000001
mFCMD_FCMD1         equ       %00000010
mFCMD_FCMD2         equ       %00000100
mFCMD_FCMD3         equ       %00001000
mFCMD_FCMD4         equ       %00010000
mFCMD_FCMD5         equ       %00100000
mFCMD_FCMD6         equ       %01000000
mFCMD_FCMD7         equ       %10000000


;*** PINPS1 - Pin Position Control Register 1
PINPS1              equ       $00001830           ;*** PINPS1 - Pin Position Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PINPS1_KBI0         equ       0                   ; KBI0 Pin Position
PINPS1_KBI1         equ       1                   ; KBI1 Pin Position
PINPS1_KBI2         equ       2                   ; KBI2 Pin Position
PINPS1_KBI3         equ       3                   ; KBI3 Pin Position
PINPS1_KBI4         equ       4                   ; KBI4 Pin Position
PINPS1_KBI5         equ       5                   ; KBI5 Pin Position
PINPS1_KBI6         equ       6                   ; KBI6 Pin Position
PINPS1_KBI7         equ       7                   ; KBI7 Pin Position
; bit position masks
mPINPS1_KBI0        equ       %00000001
mPINPS1_KBI1        equ       %00000010
mPINPS1_KBI2        equ       %00000100
mPINPS1_KBI3        equ       %00001000
mPINPS1_KBI4        equ       %00010000
mPINPS1_KBI5        equ       %00100000
mPINPS1_KBI6        equ       %01000000
mPINPS1_KBI7        equ       %10000000


;*** PINPS2 - Pin Position Control Register 2
PINPS2              equ       $00001831           ;*** PINPS2 - Pin Position Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PINPS2_TPM10        equ       0                   ; TPM1[0] Pin Position
PINPS2_TPM11        equ       1                   ; TPM1[1] Pin Position
PINPS2_TPM20        equ       2                   ; TPM2[0] Pin Position
PINPS2_TPM21        equ       3                   ; TPM2[1] Pin Position
PINPS2_TPM22        equ       4                   ; TPM2[2] Pin Position
PINPS2_TPM23        equ       5                   ; TPM2[3] Pin Position
PINPS2_TPM24        equ       6                   ; TPM2[4] Pin Position
PINPS2_TPM25        equ       7                   ; TPM2[5] Pin Position
; bit position masks
mPINPS2_TPM10       equ       %00000001
mPINPS2_TPM11       equ       %00000010
mPINPS2_TPM20       equ       %00000100
mPINPS2_TPM21       equ       %00001000
mPINPS2_TPM22       equ       %00010000
mPINPS2_TPM23       equ       %00100000
mPINPS2_TPM24       equ       %01000000
mPINPS2_TPM25       equ       %10000000


;*** PINPS3 - Pin Position Control Register 3
PINPS3              equ       $00001832           ;*** PINPS3 - Pin Position Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PINPS3_SS           equ       0                   ; SS Pin Position
PINPS3_SCK          equ       1                   ; SCK Pin Position
PINPS3_MOSI         equ       2                   ; MOSI Pin Position
PINPS3_MISO         equ       3                   ; MISO Pin Position
PINPS3_SDA          equ       4                   ; SDA Pin Position
PINPS3_SCL          equ       5                   ; SCL Pin Position
PINPS3_RX2          equ       6                   ; RX2 Pin Position
PINPS3_TX2          equ       7                   ; TX2 Pin Position
; bit position masks
mPINPS3_SS          equ       %00000001
mPINPS3_SCK         equ       %00000010
mPINPS3_MOSI        equ       %00000100
mPINPS3_MISO        equ       %00001000
mPINPS3_SDA         equ       %00010000
mPINPS3_SCL         equ       %00100000
mPINPS3_RX2         equ       %01000000
mPINPS3_TX2         equ       %10000000


;*** PINPS4 - Pin Position Control Register 4
PINPS4              equ       $00001833           ;*** PINPS4 - Pin Position Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PINPS4_RX1          equ       0                   ; RX1 Pin Position
PINPS4_TX1          equ       1                   ; TX1 Pin Position
; bit position masks
mPINPS4_RX1         equ       %00000001
mPINPS4_TX1         equ       %00000010


;*** RTCSC - RTC Status and Control Register
RTCSC               equ       $0000183C           ;*** RTCSC - RTC Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTCSC_RTCPS0        equ       0                   ; Real-Time Clock Prescaler Select, bit 0
RTCSC_RTCPS1        equ       1                   ; Real-Time Clock Prescaler Select, bit 1
RTCSC_RTCPS2        equ       2                   ; Real-Time Clock Prescaler Select, bit 2
RTCSC_RTCPS3        equ       3                   ; Real-Time Clock Prescaler Select, bit 3
RTCSC_RTIE          equ       4                   ; Real-Time Interrupt Enable
RTCSC_RTCLKS0       equ       5                   ; Real-Time Clock Source Select, bit 0
RTCSC_RTCLKS1       equ       6                   ; Real-Time Clock Source Select, bit 1
RTCSC_RTIF          equ       7                   ; Real-Time Interrupt Flag
; bit position masks
mRTCSC_RTCPS0       equ       %00000001
mRTCSC_RTCPS1       equ       %00000010
mRTCSC_RTCPS2       equ       %00000100
mRTCSC_RTCPS3       equ       %00001000
mRTCSC_RTIE         equ       %00010000
mRTCSC_RTCLKS0      equ       %00100000
mRTCSC_RTCLKS1      equ       %01000000
mRTCSC_RTIF         equ       %10000000


;*** RTCCNT - RTC Counter Register
RTCCNT              equ       $0000183D           ;*** RTCCNT - RTC Counter Register


;*** RTCMOD - RTC Modulo Register
RTCMOD              equ       $0000183E           ;*** RTCMOD - RTC Modulo Register


;*** PTAPE - Port A Pull Enable Register
PTAPE               equ       $00001840           ;*** PTAPE - Port A Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pull Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pull Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pull Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pull Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Internal Pull Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Internal Pull Enable for Port A Bit 5
PTAPE_PTAPE6        equ       6                   ; Internal Pull Enable for Port A Bit 6
PTAPE_PTAPE7        equ       7                   ; Internal Pull Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000
mPTAPE_PTAPE6       equ       %01000000
mPTAPE_PTAPE7       equ       %10000000


;*** PTASE - Port A Slew Rate Enable Register
PTASE               equ       $00001841           ;*** PTASE - Port A Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2        equ       2                   ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3        equ       3                   ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE5        equ       5                   ; Output Slew Rate Enable for Port A Bit 5
PTASE_PTASE6        equ       6                   ; Output Slew Rate Enable for Port A Bit 6
PTASE_PTASE7        equ       7                   ; Output Slew Rate Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE2       equ       %00000100
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000
mPTASE_PTASE5       equ       %00100000
mPTASE_PTASE6       equ       %01000000
mPTASE_PTASE7       equ       %10000000


;*** PTADS - Port A Drive Strength Selection Register
PTADS               equ       $00001842           ;*** PTADS - Port A Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0        equ       0                   ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1        equ       1                   ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2        equ       2                   ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3        equ       3                   ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4        equ       4                   ; Output Drive Strength Selection for Port A Bit 4
PTADS_PTADS5        equ       5                   ; Output Drive Strength Selection for Port A Bit 5
PTADS_PTADS6        equ       6                   ; Output Drive Strength Selection for Port A Bit 6
PTADS_PTADS7        equ       7                   ; Output Drive Strength Selection for Port A Bit 7
; bit position masks
mPTADS_PTADS0       equ       %00000001
mPTADS_PTADS1       equ       %00000010
mPTADS_PTADS2       equ       %00000100
mPTADS_PTADS3       equ       %00001000
mPTADS_PTADS4       equ       %00010000
mPTADS_PTADS5       equ       %00100000
mPTADS_PTADS6       equ       %01000000
mPTADS_PTADS7       equ       %10000000


;*** PTBPE - Port B Pull Enable Register
PTBPE               equ       $00001844           ;*** PTBPE - Port B Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Internal Pull Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Internal Pull Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Internal Pull Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Internal Pull Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Internal Pull Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Internal Pull Enable for Port B Bit 5
PTBPE_PTBPE6        equ       6                   ; Internal Pull Enable for Port B Bit 6
PTBPE_PTBPE7        equ       7                   ; Internal Pull Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000
mPTBPE_PTBPE6       equ       %01000000
mPTBPE_PTBPE7       equ       %10000000


;*** PTBSE - Port B Slew Rate Enable Register
PTBSE               equ       $00001845           ;*** PTBSE - Port B Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0        equ       0                   ; Output Slew Rate Enable for Port B Bit 0
PTBSE_PTBSE1        equ       1                   ; Output Slew Rate Enable for Port B Bit 1
PTBSE_PTBSE2        equ       2                   ; Output Slew Rate Enable for Port B Bit 2
PTBSE_PTBSE3        equ       3                   ; Output Slew Rate Enable for Port B Bit 3
PTBSE_PTBSE4        equ       4                   ; Output Slew Rate Enable for Port B Bit 4
PTBSE_PTBSE5        equ       5                   ; Output Slew Rate Enable for Port B Bit 5
PTBSE_PTBSE6        equ       6                   ; Output Slew Rate Enable for Port B Bit 6
PTBSE_PTBSE7        equ       7                   ; Output Slew Rate Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE0       equ       %00000001
mPTBSE_PTBSE1       equ       %00000010
mPTBSE_PTBSE2       equ       %00000100
mPTBSE_PTBSE3       equ       %00001000
mPTBSE_PTBSE4       equ       %00010000
mPTBSE_PTBSE5       equ       %00100000
mPTBSE_PTBSE6       equ       %01000000
mPTBSE_PTBSE7       equ       %10000000


;*** PTBDS - Port B Drive Strength Selection Register
PTBDS               equ       $00001846           ;*** PTBDS - Port B Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS0        equ       0                   ; Output Drive Strength Selection for Port B Bit 0
PTBDS_PTBDS1        equ       1                   ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2        equ       2                   ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3        equ       3                   ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4        equ       4                   ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5        equ       5                   ; Output Drive Strength Selection for Port B Bit 5
PTBDS_PTBDS6        equ       6                   ; Output Drive Strength Selection for Port B Bit 6
PTBDS_PTBDS7        equ       7                   ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTBDS_PTBDS0       equ       %00000001
mPTBDS_PTBDS1       equ       %00000010
mPTBDS_PTBDS2       equ       %00000100
mPTBDS_PTBDS3       equ       %00001000
mPTBDS_PTBDS4       equ       %00010000
mPTBDS_PTBDS5       equ       %00100000
mPTBDS_PTBDS6       equ       %01000000
mPTBDS_PTBDS7       equ       %10000000


;*** PTCPE - Port C Pull Enable Register
PTCPE               equ       $00001848           ;*** PTCPE - Port C Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Internal Pull Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Internal Pull Enable for Port C Bit 1
PTCPE_PTCPE2        equ       2                   ; Internal Pull Enable for Port C Bit 2
PTCPE_PTCPE3        equ       3                   ; Internal Pull Enable for Port C Bit 3
PTCPE_PTCPE4        equ       4                   ; Internal Pull Enable for Port C Bit 4
PTCPE_PTCPE5        equ       5                   ; Internal Pull Enable for Port C Bit 5
PTCPE_PTCPE6        equ       6                   ; Internal Pull Enable for Port C Bit 6
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000
mPTCPE_PTCPE6       equ       %01000000


;*** PTCSE - Port C Slew Rate Enable Register
PTCSE               equ       $00001849           ;*** PTCSE - Port C Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0        equ       0                   ; Output Slew Rate Enable for Port C Bit 0
PTCSE_PTCSE1        equ       1                   ; Output Slew Rate Enable for Port C Bit 1
PTCSE_PTCSE2        equ       2                   ; Output Slew Rate Enable for Port C Bit 2
PTCSE_PTCSE3        equ       3                   ; Output Slew Rate Enable for Port C Bit 3
PTCSE_PTCSE4        equ       4                   ; Output Slew Rate Enable for Port C Bit 4
PTCSE_PTCSE5        equ       5                   ; Output Slew Rate Enable for Port C Bit 5
PTCSE_PTCSE6        equ       6                   ; Output Slew Rate Enable for Port C Bit 6
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010
mPTCSE_PTCSE2       equ       %00000100
mPTCSE_PTCSE3       equ       %00001000
mPTCSE_PTCSE4       equ       %00010000
mPTCSE_PTCSE5       equ       %00100000
mPTCSE_PTCSE6       equ       %01000000


;*** PTCDS - Port C Drive Strength Selection Register
PTCDS               equ       $0000184A           ;*** PTCDS - Port C Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0        equ       0                   ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1        equ       1                   ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2        equ       2                   ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3        equ       3                   ; Output Drive Strength Selection for Port C Bit 3
PTCDS_PTCDS4        equ       4                   ; Output Drive Strength Selection for Port C Bit 4
PTCDS_PTCDS5        equ       5                   ; Output Drive Strength Selection for Port C Bit 5
PTCDS_PTCDS6        equ       6                   ; Output Drive Strength Selection for Port C Bit 6
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010
mPTCDS_PTCDS2       equ       %00000100
mPTCDS_PTCDS3       equ       %00001000
mPTCDS_PTCDS4       equ       %00010000
mPTCDS_PTCDS5       equ       %00100000
mPTCDS_PTCDS6       equ       %01000000


;*** PTDPE - Port D Pull Enable Register
PTDPE               equ       $0000184C           ;*** PTDPE - Port D Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0        equ       0                   ; Internal Pull Enable for Port D Bit 0
PTDPE_PTDPE1        equ       1                   ; Internal Pull Enable for Port D Bit 1
PTDPE_PTDPE2        equ       2                   ; Internal Pull Enable for Port D Bit 2
PTDPE_PTDPE3        equ       3                   ; Internal Pull Enable for Port D Bit 3
PTDPE_PTDPE4        equ       4                   ; Internal Pull Enable for Port D Bit 4
PTDPE_PTDPE5        equ       5                   ; Internal Pull Enable for Port D Bit 5
PTDPE_PTDPE6        equ       6                   ; Internal Pull Enable for Port D Bit 6
PTDPE_PTDPE7        equ       7                   ; Internal Pull Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0       equ       %00000001
mPTDPE_PTDPE1       equ       %00000010
mPTDPE_PTDPE2       equ       %00000100
mPTDPE_PTDPE3       equ       %00001000
mPTDPE_PTDPE4       equ       %00010000
mPTDPE_PTDPE5       equ       %00100000
mPTDPE_PTDPE6       equ       %01000000
mPTDPE_PTDPE7       equ       %10000000


;*** PTDSE - Port D Slew Rate Enable Register
PTDSE               equ       $0000184D           ;*** PTDSE - Port D Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0        equ       0                   ; Output Slew Rate Enable for Port D Bit 0
PTDSE_PTDSE1        equ       1                   ; Output Slew Rate Enable for Port D Bit 1
PTDSE_PTDSE2        equ       2                   ; Output Slew Rate Enable for Port D Bit 2
PTDSE_PTDSE3        equ       3                   ; Output Slew Rate Enable for Port D Bit 3
PTDSE_PTDSE4        equ       4                   ; Output Slew Rate Enable for Port D Bit 4
PTDSE_PTDSE5        equ       5                   ; Output Slew Rate Enable for Port D Bit 5
PTDSE_PTDSE6        equ       6                   ; Output Slew Rate Enable for Port D Bit 6
PTDSE_PTDSE7        equ       7                   ; Output Slew Rate Enable for Port D Bit 7
; bit position masks
mPTDSE_PTDSE0       equ       %00000001
mPTDSE_PTDSE1       equ       %00000010
mPTDSE_PTDSE2       equ       %00000100
mPTDSE_PTDSE3       equ       %00001000
mPTDSE_PTDSE4       equ       %00010000
mPTDSE_PTDSE5       equ       %00100000
mPTDSE_PTDSE6       equ       %01000000
mPTDSE_PTDSE7       equ       %10000000


;*** PTDDS - Port D Drive Strength Selection Register
PTDDS               equ       $0000184E           ;*** PTDDS - Port D Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDS_PTDDS0        equ       0                   ; Output Drive Strength Selection for Port D Bit 0
PTDDS_PTDDS1        equ       1                   ; Output Drive Strength Selection for Port D Bit 1
PTDDS_PTDDS2        equ       2                   ; Output Drive Strength Selection for Port D Bit 2
PTDDS_PTDDS3        equ       3                   ; Output Drive Strength Selection for Port D Bit 3
PTDDS_PTDDS4        equ       4                   ; Output Drive Strength Selection for Port D Bit 4
PTDDS_PTDDS5        equ       5                   ; Output Drive Strength Selection for Port D Bit 5
PTDDS_PTDDS6        equ       6                   ; Output Drive Strength Selection for Port D Bit 6
PTDDS_PTDDS7        equ       7                   ; Output Drive Strength Selection for Port D Bit 7
; bit position masks
mPTDDS_PTDDS0       equ       %00000001
mPTDDS_PTDDS1       equ       %00000010
mPTDDS_PTDDS2       equ       %00000100
mPTDDS_PTDDS3       equ       %00001000
mPTDDS_PTDDS4       equ       %00010000
mPTDDS_PTDDS5       equ       %00100000
mPTDDS_PTDDS6       equ       %01000000
mPTDDS_PTDDS7       equ       %10000000


;*** PTEPE - Port E Pull Enable Register
PTEPE               equ       $00001850           ;*** PTEPE - Port E Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPE_PTEPE0        equ       0                   ; Internal Pull Enable for Port E Bit 0
PTEPE_PTEPE1        equ       1                   ; Internal Pull Enable for Port E Bit 1
PTEPE_PTEPE2        equ       2                   ; Internal Pull Enable for Port E Bit 2
PTEPE_PTEPE3        equ       3                   ; Internal Pull Enable for Port E Bit 3
PTEPE_PTEPE4        equ       4                   ; Internal Pull Enable for Port E Bit 4
PTEPE_PTEPE5        equ       5                   ; Internal Pull Enable for Port E Bit 5
PTEPE_PTEPE6        equ       6                   ; Internal Pull Enable for Port E Bit 6
PTEPE_PTEPE7        equ       7                   ; Internal Pull Enable for Port E Bit 7
; bit position masks
mPTEPE_PTEPE0       equ       %00000001
mPTEPE_PTEPE1       equ       %00000010
mPTEPE_PTEPE2       equ       %00000100
mPTEPE_PTEPE3       equ       %00001000
mPTEPE_PTEPE4       equ       %00010000
mPTEPE_PTEPE5       equ       %00100000
mPTEPE_PTEPE6       equ       %01000000
mPTEPE_PTEPE7       equ       %10000000


;*** PTESE - Port E Slew Rate Enable Register
PTESE               equ       $00001851           ;*** PTESE - Port E Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESE_PTESE0        equ       0                   ; Output Slew Rate Enable for Port E Bit 0
PTESE_PTESE1        equ       1                   ; Output Slew Rate Enable for Port E Bit 1
PTESE_PTESE2        equ       2                   ; Output Slew Rate Enable for Port E Bit 2
PTESE_PTESE3        equ       3                   ; Output Slew Rate Enable for Port E Bit 3
PTESE_PTESE4        equ       4                   ; Output Slew Rate Enable for Port E Bit 4
PTESE_PTESE5        equ       5                   ; Output Slew Rate Enable for Port E Bit 5
PTESE_PTESE6        equ       6                   ; Output Slew Rate Enable for Port E Bit 6
PTESE_PTESE7        equ       7                   ; Output Slew Rate Enable for Port E Bit 7
; bit position masks
mPTESE_PTESE0       equ       %00000001
mPTESE_PTESE1       equ       %00000010
mPTESE_PTESE2       equ       %00000100
mPTESE_PTESE3       equ       %00001000
mPTESE_PTESE4       equ       %00010000
mPTESE_PTESE5       equ       %00100000
mPTESE_PTESE6       equ       %01000000
mPTESE_PTESE7       equ       %10000000


;*** PTEDS - Port E Drive Strength Selection Register
PTEDS               equ       $00001852           ;*** PTEDS - Port E Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDS_PTEDS0        equ       0                   ; Output Drive Strength Selection for Port E Bit 0
PTEDS_PTEDS1        equ       1                   ; Output Drive Strength Selection for Port E Bit 1
PTEDS_PTEDS2        equ       2                   ; Output Drive Strength Selection for Port E Bit 2
PTEDS_PTEDS3        equ       3                   ; Output Drive Strength Selection for Port E Bit 3
PTEDS_PTEDS4        equ       4                   ; Output Drive Strength Selection for Port E Bit 4
PTEDS_PTEDS5        equ       5                   ; Output Drive Strength Selection for Port E Bit 5
PTEDS_PTEDS6        equ       6                   ; Output Drive Strength Selection for Port E Bit 6
PTEDS_PTEDS7        equ       7                   ; Output Drive Strength Selection for Port E Bit 7
; bit position masks
mPTEDS_PTEDS0       equ       %00000001
mPTEDS_PTEDS1       equ       %00000010
mPTEDS_PTEDS2       equ       %00000100
mPTEDS_PTEDS3       equ       %00001000
mPTEDS_PTEDS4       equ       %00010000
mPTEDS_PTEDS5       equ       %00100000
mPTEDS_PTEDS6       equ       %01000000
mPTEDS_PTEDS7       equ       %10000000


;*** PTFPE - Port F Pull Enable Register
PTFPE               equ       $00001854           ;*** PTFPE - Port F Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPE_PTFPE0        equ       0                   ; Internal Pull Enable for Port F Bit 0
PTFPE_PTFPE1        equ       1                   ; Internal Pull Enable for Port F Bit 1
PTFPE_PTFPE2        equ       2                   ; Internal Pull Enable for Port F Bit 2
PTFPE_PTFPE3        equ       3                   ; Internal Pull Enable for Port F Bit 3
PTFPE_PTFPE4        equ       4                   ; Internal Pull Enable for Port F Bit 4
PTFPE_PTFPE5        equ       5                   ; Internal Pull Enable for Port F Bit 5
PTFPE_PTFPE6        equ       6                   ; Internal Pull Enable for Port F Bit 6
PTFPE_PTFPE7        equ       7                   ; Internal Pull Enable for Port F Bit 7
; bit position masks
mPTFPE_PTFPE0       equ       %00000001
mPTFPE_PTFPE1       equ       %00000010
mPTFPE_PTFPE2       equ       %00000100
mPTFPE_PTFPE3       equ       %00001000
mPTFPE_PTFPE4       equ       %00010000
mPTFPE_PTFPE5       equ       %00100000
mPTFPE_PTFPE6       equ       %01000000
mPTFPE_PTFPE7       equ       %10000000


;*** PTFSE - Port F Slew Rate Enable Register
PTFSE               equ       $00001855           ;*** PTFSE - Port F Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0        equ       0                   ; Output Slew Rate Enable for Port F Bit 0
PTFSE_PTFSE1        equ       1                   ; Output Slew Rate Enable for Port F Bit 1
PTFSE_PTFSE2        equ       2                   ; Output Slew Rate Enable for Port F Bit 2
PTFSE_PTFSE3        equ       3                   ; Output Slew Rate Enable for Port F Bit 3
PTFSE_PTFSE4        equ       4                   ; Output Slew Rate Enable for Port F Bit 4
PTFSE_PTFSE5        equ       5                   ; Output Slew Rate Enable for Port F Bit 5
PTFSE_PTFSE6        equ       6                   ; Output Slew Rate Enable for Port F Bit 6
PTFSE_PTFSE7        equ       7                   ; Output Slew Rate Enable for Port F Bit 7
; bit position masks
mPTFSE_PTFSE0       equ       %00000001
mPTFSE_PTFSE1       equ       %00000010
mPTFSE_PTFSE2       equ       %00000100
mPTFSE_PTFSE3       equ       %00001000
mPTFSE_PTFSE4       equ       %00010000
mPTFSE_PTFSE5       equ       %00100000
mPTFSE_PTFSE6       equ       %01000000
mPTFSE_PTFSE7       equ       %10000000


;*** PTFDS - Port F Drive Strength Selection Register
PTFDS               equ       $00001856           ;*** PTFDS - Port F Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDS_PTFDS0        equ       0                   ; Output Drive Strength Selection for Port F Bit 0
PTFDS_PTFDS1        equ       1                   ; Output Drive Strength Selection for Port F Bit 1
PTFDS_PTFDS2        equ       2                   ; Output Drive Strength Selection for Port F Bit 2
PTFDS_PTFDS3        equ       3                   ; Output Drive Strength Selection for Port F Bit 3
PTFDS_PTFDS4        equ       4                   ; Output Drive Strength Selection for Port F Bit 4
PTFDS_PTFDS5        equ       5                   ; Output Drive Strength Selection for Port F Bit 5
PTFDS_PTFDS6        equ       6                   ; Output Drive Strength Selection for Port F Bit 6
PTFDS_PTFDS7        equ       7                   ; Output Drive Strength Selection for Port F Bit 7
; bit position masks
mPTFDS_PTFDS0       equ       %00000001
mPTFDS_PTFDS1       equ       %00000010
mPTFDS_PTFDS2       equ       %00000100
mPTFDS_PTFDS3       equ       %00001000
mPTFDS_PTFDS4       equ       %00010000
mPTFDS_PTFDS5       equ       %00100000
mPTFDS_PTFDS6       equ       %01000000
mPTFDS_PTFDS7       equ       %10000000


;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $00001860           ;*** ICSC1 - ICS Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN      equ       0                   ; Internal Reference Stop Enable
ICSC1_IRCLKEN       equ       1                   ; Internal Reference Clock Enable
ICSC1_IREFS         equ       2                   ; Internal Reference Select
ICSC1_RDIV0         equ       3                   ; Reference Divider, bit 0
ICSC1_RDIV1         equ       4                   ; Reference Divider, bit 1
ICSC1_RDIV2         equ       5                   ; Reference Divider, bit 2
ICSC1_CLKS0         equ       6                   ; Clock Source Select, bit 0
ICSC1_CLKS1         equ       7                   ; Clock Source Select, bit 1
; bit position masks
mICSC1_IREFSTEN     equ       %00000001
mICSC1_IRCLKEN      equ       %00000010
mICSC1_IREFS        equ       %00000100
mICSC1_RDIV0        equ       %00001000
mICSC1_RDIV1        equ       %00010000
mICSC1_RDIV2        equ       %00100000
mICSC1_CLKS0        equ       %01000000
mICSC1_CLKS1        equ       %10000000


;*** ICSC2 - ICS Control Register 2
ICSC2               equ       $00001861           ;*** ICSC2 - ICS Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_EREFSTEN      equ       0                   ; External Reference Stop Enable
ICSC2_ERCLKEN       equ       1                   ; External Reference Enable
ICSC2_EREFS         equ       2                   ; External Reference Select
ICSC2_LP            equ       3                   ; Low Power Select
ICSC2_HGO           equ       4                   ; High Gain Oscillator Select
ICSC2_RANGE         equ       5                   ; Frequency Range Select
ICSC2_BDIV0         equ       6                   ; Bus Frequency Divider, bit 0
ICSC2_BDIV1         equ       7                   ; Bus Frequency Divider, bit 1
; bit position masks
mICSC2_EREFSTEN     equ       %00000001
mICSC2_ERCLKEN      equ       %00000010
mICSC2_EREFS        equ       %00000100
mICSC2_LP           equ       %00001000
mICSC2_HGO          equ       %00010000
mICSC2_RANGE        equ       %00100000
mICSC2_BDIV0        equ       %01000000
mICSC2_BDIV1        equ       %10000000


;*** ICSTRM - ICS Trim Register
ICSTRM              equ       $00001862           ;*** ICSTRM - ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM0        equ       0                   ; ICS Trim Setting, bit 0
ICSTRM_TRIM1        equ       1                   ; ICS Trim Setting, bit 1
ICSTRM_TRIM2        equ       2                   ; ICS Trim Setting, bit 2
ICSTRM_TRIM3        equ       3                   ; ICS Trim Setting, bit 3
ICSTRM_TRIM4        equ       4                   ; ICS Trim Setting, bit 4
ICSTRM_TRIM5        equ       5                   ; ICS Trim Setting, bit 5
ICSTRM_TRIM6        equ       6                   ; ICS Trim Setting, bit 6
ICSTRM_TRIM7        equ       7                   ; ICS Trim Setting, bit 7
; bit position masks
mICSTRM_TRIM0       equ       %00000001
mICSTRM_TRIM1       equ       %00000010
mICSTRM_TRIM2       equ       %00000100
mICSTRM_TRIM3       equ       %00001000
mICSTRM_TRIM4       equ       %00010000
mICSTRM_TRIM5       equ       %00100000
mICSTRM_TRIM6       equ       %01000000
mICSTRM_TRIM7       equ       %10000000


;*** ICSSC - ICS Status and Control Register
ICSSC               equ       $00001863           ;*** ICSSC - ICS Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM         equ       0                   ; ICS Fine Trim
ICSSC_OSCINIT       equ       1                   ; OSC Initialization
ICSSC_CLKST0        equ       2                   ; Clock Mode Status, bit 0
ICSSC_CLKST1        equ       3                   ; Clock Mode Status, bit 1
ICSSC_IREFST        equ       4                   ; Internal Reference Status
ICSSC_DMX32         equ       5                   ; DCO Maximum frequency with 32.768 kHz reference
ICSSC_DRST_DRS0     equ       6                   ; DCO Range Status/Range Select, bit 0
ICSSC_DRST_DRS1     equ       7                   ; DCO Range Status/Range Select, bit 1
; bit position masks
mICSSC_FTRIM        equ       %00000001
mICSSC_OSCINIT      equ       %00000010
mICSSC_CLKST0       equ       %00000100
mICSSC_CLKST1       equ       %00001000
mICSSC_IREFST       equ       %00010000
mICSSC_DMX32        equ       %00100000
mICSSC_DRST_DRS0    equ       %01000000
mICSSC_DRST_DRS1    equ       %10000000


;*** PTGPE - Port G Pull Enable Register
PTGPE               equ       $00001868           ;*** PTGPE - Port G Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0        equ       0                   ; Internal Pull Enable for Port G Bit 0
PTGPE_PTGPE1        equ       1                   ; Internal Pull Enable for Port G Bit 1
PTGPE_PTGPE2        equ       2                   ; Internal Pull Enable for Port G Bit 2
PTGPE_PTGPE3        equ       3                   ; Internal Pull Enable for Port G Bit 3
PTGPE_PTGPE4        equ       4                   ; Internal Pull Enable for Port G Bit 4
PTGPE_PTGPE5        equ       5                   ; Internal Pull Enable for Port G Bit 5
PTGPE_PTGPE6        equ       6                   ; Internal Pull Enable for Port G Bit 6
PTGPE_PTGPE7        equ       7                   ; Internal Pull Enable for Port G Bit 7
; bit position masks
mPTGPE_PTGPE0       equ       %00000001
mPTGPE_PTGPE1       equ       %00000010
mPTGPE_PTGPE2       equ       %00000100
mPTGPE_PTGPE3       equ       %00001000
mPTGPE_PTGPE4       equ       %00010000
mPTGPE_PTGPE5       equ       %00100000
mPTGPE_PTGPE6       equ       %01000000
mPTGPE_PTGPE7       equ       %10000000


;*** PTGSE - Port G Slew Rate Enable Register
PTGSE               equ       $00001869           ;*** PTGSE - Port G Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0        equ       0                   ; Output Slew Rate Enable for Port G Bit 0
PTGSE_PTGSE1        equ       1                   ; Output Slew Rate Enable for Port G Bit 1
PTGSE_PTGSE2        equ       2                   ; Output Slew Rate Enable for Port G Bit 2
PTGSE_PTGSE3        equ       3                   ; Output Slew Rate Enable for Port G Bit 3
PTGSE_PTGSE4        equ       4                   ; Output Slew Rate Enable for Port G Bit 4
PTGSE_PTGSE5        equ       5                   ; Output Slew Rate Enable for Port G Bit 5
PTGSE_PTGSE6        equ       6                   ; Output Slew Rate Enable for Port G Bit 6
PTGSE_PTGSE7        equ       7                   ; Output Slew Rate Enable for Port G Bit 7
; bit position masks
mPTGSE_PTGSE0       equ       %00000001
mPTGSE_PTGSE1       equ       %00000010
mPTGSE_PTGSE2       equ       %00000100
mPTGSE_PTGSE3       equ       %00001000
mPTGSE_PTGSE4       equ       %00010000
mPTGSE_PTGSE5       equ       %00100000
mPTGSE_PTGSE6       equ       %01000000
mPTGSE_PTGSE7       equ       %10000000


;*** PTGDS - Port G Drive Strength Selection Register
PTGDS               equ       $0000186A           ;*** PTGDS - Port G Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDS_PTGDS0        equ       0                   ; Output Drive Strength Selection for Port G Bit 0
PTGDS_PTGDS1        equ       1                   ; Output Drive Strength Selection for Port G Bit 1
PTGDS_PTGDS2        equ       2                   ; Output Drive Strength Selection for Port G Bit 2
PTGDS_PTGDS3        equ       3                   ; Output Drive Strength Selection for Port G Bit 3
PTGDS_PTGDS4        equ       4                   ; Output Drive Strength Selection for Port G Bit 4
PTGDS_PTGDS5        equ       5                   ; Output Drive Strength Selection for Port G Bit 5
PTGDS_PTGDS6        equ       6                   ; Output Drive Strength Selection for Port G Bit 6
PTGDS_PTGDS7        equ       7                   ; Output Drive Strength Selection for Port G Bit 7
; bit position masks
mPTGDS_PTGDS0       equ       %00000001
mPTGDS_PTGDS1       equ       %00000010
mPTGDS_PTGDS2       equ       %00000100
mPTGDS_PTGDS3       equ       %00001000
mPTGDS_PTGDS4       equ       %00010000
mPTGDS_PTGDS5       equ       %00100000
mPTGDS_PTGDS6       equ       %01000000
mPTGDS_PTGDS7       equ       %10000000


;*** PTHPE - Port H Pull Enable Register
PTHPE               equ       $0000186C           ;*** PTHPE - Port H Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPE_PTHPE0        equ       0                   ; Internal Pull Enable for Port H Bit 0
PTHPE_PTHPE1        equ       1                   ; Internal Pull Enable for Port H Bit 1
PTHPE_PTHPE2        equ       2                   ; Internal Pull Enable for Port H Bit 2
PTHPE_PTHPE3        equ       3                   ; Internal Pull Enable for Port H Bit 3
PTHPE_PTHPE4        equ       4                   ; Internal Pull Enable for Port H Bit 4
PTHPE_PTHPE5        equ       5                   ; Internal Pull Enable for Port H Bit 5
PTHPE_PTHPE6        equ       6                   ; Internal Pull Enable for Port H Bit 6
PTHPE_PTHPE7        equ       7                   ; Internal Pull Enable for Port H Bit 7
; bit position masks
mPTHPE_PTHPE0       equ       %00000001
mPTHPE_PTHPE1       equ       %00000010
mPTHPE_PTHPE2       equ       %00000100
mPTHPE_PTHPE3       equ       %00001000
mPTHPE_PTHPE4       equ       %00010000
mPTHPE_PTHPE5       equ       %00100000
mPTHPE_PTHPE6       equ       %01000000
mPTHPE_PTHPE7       equ       %10000000


;*** PTHSE - Port H Slew Rate Enable Register
PTHSE               equ       $0000186D           ;*** PTHSE - Port H Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHSE_PTHSE0        equ       0                   ; Output Slew Rate Enable for Port H Bit 0
PTHSE_PTHSE1        equ       1                   ; Output Slew Rate Enable for Port H Bit 1
PTHSE_PTHSE2        equ       2                   ; Output Slew Rate Enable for Port H Bit 2
PTHSE_PTHSE3        equ       3                   ; Output Slew Rate Enable for Port H Bit 3
PTHSE_PTHSE4        equ       4                   ; Output Slew Rate Enable for Port H Bit 4
PTHSE_PTHSE5        equ       5                   ; Output Slew Rate Enable for Port H Bit 5
PTHSE_PTHSE6        equ       6                   ; Output Slew Rate Enable for Port H Bit 6
PTHSE_PTHSE7        equ       7                   ; Output Slew Rate Enable for Port H Bit 7
; bit position masks
mPTHSE_PTHSE0       equ       %00000001
mPTHSE_PTHSE1       equ       %00000010
mPTHSE_PTHSE2       equ       %00000100
mPTHSE_PTHSE3       equ       %00001000
mPTHSE_PTHSE4       equ       %00010000
mPTHSE_PTHSE5       equ       %00100000
mPTHSE_PTHSE6       equ       %01000000
mPTHSE_PTHSE7       equ       %10000000


;*** PTHDS - Port H Drive Strength Selection Register
PTHDS               equ       $0000186E           ;*** PTHDS - Port H Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDS_PTHDS0        equ       0                   ; Output Drive Strength Selection for Port H Bit 0
PTHDS_PTHDS1        equ       1                   ; Output Drive Strength Selection for Port H Bit 1
PTHDS_PTHDS2        equ       2                   ; Output Drive Strength Selection for Port H Bit 2
PTHDS_PTHDS3        equ       3                   ; Output Drive Strength Selection for Port H Bit 3
PTHDS_PTHDS4        equ       4                   ; Output Drive Strength Selection for Port H Bit 4
PTHDS_PTHDS5        equ       5                   ; Output Drive Strength Selection for Port H Bit 5
PTHDS_PTHDS6        equ       6                   ; Output Drive Strength Selection for Port H Bit 6
PTHDS_PTHDS7        equ       7                   ; Output Drive Strength Selection for Port H Bit 7
; bit position masks
mPTHDS_PTHDS0       equ       %00000001
mPTHDS_PTHDS1       equ       %00000010
mPTHDS_PTHDS2       equ       %00000100
mPTHDS_PTHDS3       equ       %00001000
mPTHDS_PTHDS4       equ       %00010000
mPTHDS_PTHDS5       equ       %00100000
mPTHDS_PTHDS6       equ       %01000000
mPTHDS_PTHDS7       equ       %10000000


;*** MTIMSC - MTIM Clock Configuration Register
MTIMSC              equ       $00001870           ;*** MTIMSC - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIMSC_TSTP         equ       4                   ; MTIM Counter Stop
MTIMSC_TRST         equ       5                   ; MTIM Counter Reset
MTIMSC_TOIE         equ       6                   ; MTIM Overflow Interrupt Enable
MTIMSC_TOF          equ       7                   ; MTIM Overflow Flag
; bit position masks
mMTIMSC_TSTP        equ       %00010000
mMTIMSC_TRST        equ       %00100000
mMTIMSC_TOIE        equ       %01000000
mMTIMSC_TOF         equ       %10000000


;*** MTIMCLK - MTIM Clock Configuration Register
MTIMCLK             equ       $00001871           ;*** MTIMCLK - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIMCLK_PS0         equ       0                   ; Clock source Prescaler Bit 0
MTIMCLK_PS1         equ       1                   ; Clock source Prescaler Bit 1
MTIMCLK_PS2         equ       2                   ; Clock source Prescaler Bit 2
MTIMCLK_PS3         equ       3                   ; Clock source Prescaler Bit 3
MTIMCLK_CLKS0       equ       4                   ; Clock source Select Bit 0
MTIMCLK_CLKS1       equ       5                   ; Clock source Select Bit 1
; bit position masks
mMTIMCLK_PS0        equ       %00000001
mMTIMCLK_PS1        equ       %00000010
mMTIMCLK_PS2        equ       %00000100
mMTIMCLK_PS3        equ       %00001000
mMTIMCLK_CLKS0      equ       %00010000
mMTIMCLK_CLKS1      equ       %00100000


;*** MTIMCNT - MTIM Counter Register
MTIMCNT             equ       $00001872           ;*** MTIMCNT - MTIM Counter Register


;*** MTIMMOD - MTIM Modulo Register
MTIMMOD             equ       $00001873           ;*** MTIMMOD - MTIM Modulo Register


;*** PTIPE - Port I Pull Enable Register
PTIPE               equ       $00001874           ;*** PTIPE - Port I Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIPE_PTIPE0        equ       0                   ; Internal Pull Enable for Port I Bit 0
PTIPE_PTIPE1        equ       1                   ; Internal Pull Enable for Port I Bit 1
PTIPE_PTIPE2        equ       2                   ; Internal Pull Enable for Port I Bit 2
PTIPE_PTIPE3        equ       3                   ; Internal Pull Enable for Port I Bit 3
PTIPE_PTIPE4        equ       4                   ; Internal Pull Enable for Port I Bit 4
PTIPE_PTIPE5        equ       5                   ; Internal Pull Enable for Port I Bit 5
; bit position masks
mPTIPE_PTIPE0       equ       %00000001
mPTIPE_PTIPE1       equ       %00000010
mPTIPE_PTIPE2       equ       %00000100
mPTIPE_PTIPE3       equ       %00001000
mPTIPE_PTIPE4       equ       %00010000
mPTIPE_PTIPE5       equ       %00100000


;*** PTISE - Port I Slew Rate Enable Register
PTISE               equ       $00001875           ;*** PTISE - Port I Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTISE_PTISE0        equ       0                   ; Output Slew Rate Enable for Port I Bit 0
PTISE_PTISE1        equ       1                   ; Output Slew Rate Enable for Port I Bit 1
PTISE_PTISE2        equ       2                   ; Output Slew Rate Enable for Port I Bit 2
PTISE_PTISE3        equ       3                   ; Output Slew Rate Enable for Port I Bit 3
PTISE_PTISE4        equ       4                   ; Output Slew Rate Enable for Port I Bit 4
PTISE_PTISE5        equ       5                   ; Output Slew Rate Enable for Port I Bit 5
; bit position masks
mPTISE_PTISE0       equ       %00000001
mPTISE_PTISE1       equ       %00000010
mPTISE_PTISE2       equ       %00000100
mPTISE_PTISE3       equ       %00001000
mPTISE_PTISE4       equ       %00010000
mPTISE_PTISE5       equ       %00100000


;*** PTIDS - Port I Drive Strength Selection Register
PTIDS               equ       $00001876           ;*** PTIDS - Port I Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTIDS_PTIDS0        equ       0                   ; Output Drive Strength Selection for Port I Bit 0
PTIDS_PTIDS1        equ       1                   ; Output Drive Strength Selection for Port I Bit 1
PTIDS_PTIDS2        equ       2                   ; Output Drive Strength Selection for Port I Bit 2
PTIDS_PTIDS3        equ       3                   ; Output Drive Strength Selection for Port I Bit 3
PTIDS_PTIDS4        equ       4                   ; Output Drive Strength Selection for Port I Bit 4
PTIDS_PTIDS5        equ       5                   ; Output Drive Strength Selection for Port I Bit 5
; bit position masks
mPTIDS_PTIDS0       equ       %00000001
mPTIDS_PTIDS1       equ       %00000010
mPTIDS_PTIDS2       equ       %00000100
mPTIDS_PTIDS3       equ       %00001000
mPTIDS_PTIDS4       equ       %00010000
mPTIDS_PTIDS5       equ       %00100000


;*** KBISC - KBI Status and Control Register
KBISC               equ       $00001878           ;*** KBISC - KBI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBISC_KBIMOD        equ       0                   ; Keyboard Detection Mode
KBISC_KBIE          equ       1                   ; Keyboard Interrupt Enable
KBISC_KBACK         equ       2                   ; Keyboard Interrupt Acknowledge
KBISC_KBF           equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBISC_KBIMOD       equ       %00000001
mKBISC_KBIE         equ       %00000010
mKBISC_KBACK        equ       %00000100
mKBISC_KBF          equ       %00001000


;*** KBIPE - KBI Pin Enable Register
KBIPE               equ       $00001879           ;*** KBIPE - KBI Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPE_KBIPE0        equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBIPE_KBIPE1        equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBIPE_KBIPE2        equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBIPE_KBIPE3        equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBIPE_KBIPE4        equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBIPE_KBIPE5        equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBIPE_KBIPE6        equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBIPE_KBIPE7        equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBIPE_KBIPE0       equ       %00000001
mKBIPE_KBIPE1       equ       %00000010
mKBIPE_KBIPE2       equ       %00000100
mKBIPE_KBIPE3       equ       %00001000
mKBIPE_KBIPE4       equ       %00010000
mKBIPE_KBIPE5       equ       %00100000
mKBIPE_KBIPE6       equ       %01000000
mKBIPE_KBIPE7       equ       %10000000


;*** KBIES - KBI Edge Select Register
KBIES               equ       $0000187A           ;*** KBIES - KBI Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIES_KBEDG0        equ       0                   ; Keyboard Edge Select Bit 0
KBIES_KBEDG1        equ       1                   ; Keyboard Edge Select Bit 1
KBIES_KBEDG2        equ       2                   ; Keyboard Edge Select Bit 2
KBIES_KBEDG3        equ       3                   ; Keyboard Edge Select Bit 3
KBIES_KBEDG4        equ       4                   ; Keyboard Edge Select Bit 4
KBIES_KBEDG5        equ       5                   ; Keyboard Edge Select Bit 5
KBIES_KBEDG6        equ       6                   ; Keyboard Edge Select Bit 6
KBIES_KBEDG7        equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBIES_KBEDG0       equ       %00000001
mKBIES_KBEDG1       equ       %00000010
mKBIES_KBEDG2       equ       %00000100
mKBIES_KBEDG3       equ       %00001000
mKBIES_KBEDG4       equ       %00010000
mKBIES_KBEDG5       equ       %00100000
mKBIES_KBEDG6       equ       %01000000
mKBIES_KBEDG7       equ       %10000000


;*** NVFTRIM - Non-volatile ICS Fine Trim
NVFTRIM             equ       $0000FFAE           ;*** NVFTRIM - Non-volatile ICS Fine Trim
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFTRIM_FTRIM       equ       0                   ; ICS Fine Trim
; bit position masks
mNVFTRIM_FTRIM      equ       %00000001


;*** NVICSTRM - Non-volatile ICS Trim Register
NVICSTRM            equ       $0000FFAF           ;*** NVICSTRM - Non-volatile ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVICSTRM_TRIM0      equ       0                   ; ICS Trim Setting, bit 0
NVICSTRM_TRIM1      equ       1                   ; ICS Trim Setting, bit 1
NVICSTRM_TRIM2      equ       2                   ; ICS Trim Setting, bit 2
NVICSTRM_TRIM3      equ       3                   ; ICS Trim Setting, bit 3
NVICSTRM_TRIM4      equ       4                   ; ICS Trim Setting, bit 4
NVICSTRM_TRIM5      equ       5                   ; ICS Trim Setting, bit 5
NVICSTRM_TRIM6      equ       6                   ; ICS Trim Setting, bit 6
NVICSTRM_TRIM7      equ       7                   ; ICS Trim Setting, bit 7
; bit position masks
mNVICSTRM_TRIM0     equ       %00000001
mNVICSTRM_TRIM1     equ       %00000010
mNVICSTRM_TRIM2     equ       %00000100
mNVICSTRM_TRIM3     equ       %00001000
mNVICSTRM_TRIM4     equ       %00010000
mNVICSTRM_TRIM5     equ       %00100000
mNVICSTRM_TRIM6     equ       %01000000
mNVICSTRM_TRIM7     equ       %10000000


;*** NVBACKKEY0 - Backdoor Comparison Key 0
NVBACKKEY0          equ       $0000FFB0           ;*** NVBACKKEY0 - Backdoor Comparison Key 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY0_KEY0     equ       0                   ; Backdoor Comparison Key 0 Bits, bit 0
NVBACKKEY0_KEY1     equ       1                   ; Backdoor Comparison Key 0 Bits, bit 1
NVBACKKEY0_KEY2     equ       2                   ; Backdoor Comparison Key 0 Bits, bit 2
NVBACKKEY0_KEY3     equ       3                   ; Backdoor Comparison Key 0 Bits, bit 3
NVBACKKEY0_KEY4     equ       4                   ; Backdoor Comparison Key 0 Bits, bit 4
NVBACKKEY0_KEY5     equ       5                   ; Backdoor Comparison Key 0 Bits, bit 5
NVBACKKEY0_KEY6     equ       6                   ; Backdoor Comparison Key 0 Bits, bit 6
NVBACKKEY0_KEY7     equ       7                   ; Backdoor Comparison Key 0 Bits, bit 7
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
NVBACKKEY1_KEY0     equ       0                   ; Backdoor Comparison Key 1 Bits, bit 0
NVBACKKEY1_KEY1     equ       1                   ; Backdoor Comparison Key 1 Bits, bit 1
NVBACKKEY1_KEY2     equ       2                   ; Backdoor Comparison Key 1 Bits, bit 2
NVBACKKEY1_KEY3     equ       3                   ; Backdoor Comparison Key 1 Bits, bit 3
NVBACKKEY1_KEY4     equ       4                   ; Backdoor Comparison Key 1 Bits, bit 4
NVBACKKEY1_KEY5     equ       5                   ; Backdoor Comparison Key 1 Bits, bit 5
NVBACKKEY1_KEY6     equ       6                   ; Backdoor Comparison Key 1 Bits, bit 6
NVBACKKEY1_KEY7     equ       7                   ; Backdoor Comparison Key 1 Bits, bit 7
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
NVBACKKEY2_KEY0     equ       0                   ; Backdoor Comparison Key 2 Bits, bit 0
NVBACKKEY2_KEY1     equ       1                   ; Backdoor Comparison Key 2 Bits, bit 1
NVBACKKEY2_KEY2     equ       2                   ; Backdoor Comparison Key 2 Bits, bit 2
NVBACKKEY2_KEY3     equ       3                   ; Backdoor Comparison Key 2 Bits, bit 3
NVBACKKEY2_KEY4     equ       4                   ; Backdoor Comparison Key 2 Bits, bit 4
NVBACKKEY2_KEY5     equ       5                   ; Backdoor Comparison Key 2 Bits, bit 5
NVBACKKEY2_KEY6     equ       6                   ; Backdoor Comparison Key 2 Bits, bit 6
NVBACKKEY2_KEY7     equ       7                   ; Backdoor Comparison Key 2 Bits, bit 7
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
NVBACKKEY3_KEY0     equ       0                   ; Backdoor Comparison Key 3 Bits, bit 0
NVBACKKEY3_KEY1     equ       1                   ; Backdoor Comparison Key 3 Bits, bit 1
NVBACKKEY3_KEY2     equ       2                   ; Backdoor Comparison Key 3 Bits, bit 2
NVBACKKEY3_KEY3     equ       3                   ; Backdoor Comparison Key 3 Bits, bit 3
NVBACKKEY3_KEY4     equ       4                   ; Backdoor Comparison Key 3 Bits, bit 4
NVBACKKEY3_KEY5     equ       5                   ; Backdoor Comparison Key 3 Bits, bit 5
NVBACKKEY3_KEY6     equ       6                   ; Backdoor Comparison Key 3 Bits, bit 6
NVBACKKEY3_KEY7     equ       7                   ; Backdoor Comparison Key 3 Bits, bit 7
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
NVBACKKEY4_KEY0     equ       0                   ; Backdoor Comparison Key 4 Bits, bit 0
NVBACKKEY4_KEY1     equ       1                   ; Backdoor Comparison Key 4 Bits, bit 1
NVBACKKEY4_KEY2     equ       2                   ; Backdoor Comparison Key 4 Bits, bit 2
NVBACKKEY4_KEY3     equ       3                   ; Backdoor Comparison Key 4 Bits, bit 3
NVBACKKEY4_KEY4     equ       4                   ; Backdoor Comparison Key 4 Bits, bit 4
NVBACKKEY4_KEY5     equ       5                   ; Backdoor Comparison Key 4 Bits, bit 5
NVBACKKEY4_KEY6     equ       6                   ; Backdoor Comparison Key 4 Bits, bit 6
NVBACKKEY4_KEY7     equ       7                   ; Backdoor Comparison Key 4 Bits, bit 7
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
NVBACKKEY5_KEY0     equ       0                   ; Backdoor Comparison Key 5 Bits, bit 0
NVBACKKEY5_KEY1     equ       1                   ; Backdoor Comparison Key 5 Bits, bit 1
NVBACKKEY5_KEY2     equ       2                   ; Backdoor Comparison Key 5 Bits, bit 2
NVBACKKEY5_KEY3     equ       3                   ; Backdoor Comparison Key 5 Bits, bit 3
NVBACKKEY5_KEY4     equ       4                   ; Backdoor Comparison Key 5 Bits, bit 4
NVBACKKEY5_KEY5     equ       5                   ; Backdoor Comparison Key 5 Bits, bit 5
NVBACKKEY5_KEY6     equ       6                   ; Backdoor Comparison Key 5 Bits, bit 6
NVBACKKEY5_KEY7     equ       7                   ; Backdoor Comparison Key 5 Bits, bit 7
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
NVBACKKEY6_KEY0     equ       0                   ; Backdoor Comparison Key 6 Bits, bit 0
NVBACKKEY6_KEY1     equ       1                   ; Backdoor Comparison Key 6 Bits, bit 1
NVBACKKEY6_KEY2     equ       2                   ; Backdoor Comparison Key 6 Bits, bit 2
NVBACKKEY6_KEY3     equ       3                   ; Backdoor Comparison Key 6 Bits, bit 3
NVBACKKEY6_KEY4     equ       4                   ; Backdoor Comparison Key 6 Bits, bit 4
NVBACKKEY6_KEY5     equ       5                   ; Backdoor Comparison Key 6 Bits, bit 5
NVBACKKEY6_KEY6     equ       6                   ; Backdoor Comparison Key 6 Bits, bit 6
NVBACKKEY6_KEY7     equ       7                   ; Backdoor Comparison Key 6 Bits, bit 7
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
NVBACKKEY7_KEY0     equ       0                   ; Backdoor Comparison Key 7 Bits, bit 0
NVBACKKEY7_KEY1     equ       1                   ; Backdoor Comparison Key 7 Bits, bit 1
NVBACKKEY7_KEY2     equ       2                   ; Backdoor Comparison Key 7 Bits, bit 2
NVBACKKEY7_KEY3     equ       3                   ; Backdoor Comparison Key 7 Bits, bit 3
NVBACKKEY7_KEY4     equ       4                   ; Backdoor Comparison Key 7 Bits, bit 4
NVBACKKEY7_KEY5     equ       5                   ; Backdoor Comparison Key 7 Bits, bit 5
NVBACKKEY7_KEY6     equ       6                   ; Backdoor Comparison Key 7 Bits, bit 6
NVBACKKEY7_KEY7     equ       7                   ; Backdoor Comparison Key 7 Bits, bit 7
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
NVPROT_FPS1         equ       1                   ; FLASH Protect Select Bit 1
NVPROT_FPS2         equ       2                   ; FLASH Protect Select Bit 2
NVPROT_FPS3         equ       3                   ; FLASH Protect Select Bit 3
NVPROT_FPS4         equ       4                   ; FLASH Protect Select Bit 4
NVPROT_FPS5         equ       5                   ; FLASH Protect Select Bit 5
NVPROT_FPS6         equ       6                   ; FLASH Protect Select Bit 6
NVPROT_FPS7         equ       7                   ; FLASH Protect Select Bit 7
; bit position masks
mNVPROT_FPDIS       equ       %00000001
mNVPROT_FPS1        equ       %00000010
mNVPROT_FPS2        equ       %00000100
mNVPROT_FPS3        equ       %00001000
mNVPROT_FPS4        equ       %00010000
mNVPROT_FPS5        equ       %00100000
mNVPROT_FPS6        equ       %01000000
mNVPROT_FPS7        equ       %10000000


;*** NVOPT - Non-volatile Flash Options Register
NVOPT               equ       $0000FFBF           ;*** NVOPT - Non-volatile Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC00         equ       0                   ; Security State Code, bit 0
NVOPT_SEC01         equ       1                   ; Security State Code, bit 1
NVOPT_FNORED        equ       6                   ; Vector Redirection Disable
NVOPT_KEYEN         equ       7                   ; Backdoor Key Mechanism Enable
; bit position masks
mNVOPT_SEC00        equ       %00000001
mNVOPT_SEC01        equ       %00000010
mNVOPT_FNORED       equ       %01000000
mNVOPT_KEYEN        equ       %10000000



; Flash commands
mBlank              equ       $05
mBurstProg          equ       $25
mByteProg           equ       $20
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



; **** 12.3.2009 8:37:33

       #ifndef __GENERATE_APPLICATION__
       #endif

; EOF
