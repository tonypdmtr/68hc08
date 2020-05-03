;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08QL8_20, version 3.00.001 (RegistersPrg V2.33)

; ###################################################################
;     Filename  : mc9s08ql4.inc
;     Processor : MC9S08QL4CTG
;     FileFormat: V2.33
;     DataSheet : MC9S08QL8RM Rev. 0 6/2018
;     Compiler  : CodeWarrior compiler
;     Date/Time : 20-Jun-18, 6:07 PM
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2014 Freescale Semiconductor, Inc.
;     All Rights Reserved.
;
;     Redistribution and use in source and binary forms, with or without modification,
;     are permitted provided that the following conditions are met:
;
;     o Redistributions of source code must retain the above copyright notice, this list
;       of conditions and the following disclaimer.
;
;     o Redistributions in binary form must reproduce the above copyright notice, this
;       list of conditions and the following disclaimer in the documentation and/or
;       other materials provided with the distribution.
;
;     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
;       contributors may be used to endorse or promote products derived from this
;       software without specific prior written permission.
;
;     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
;     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
;     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
;     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
;     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
;     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
;     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;     http: www.freescale.com
;     mail: support@freescale.com
;
;     CPU Registers Revisions:
;      - 06.20.2018, V0.10:
;              - Updated changes according to manual revision Rev. 0 6/2018.
;
;     File-Format-Revisions:
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
;      - 15.09.2010, V2.33 :
;               - Empty union is not generated for data overlapping registers, cause there is no bit access
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000F000
ROM_END             equ       $0000FFAD
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000015F
XROM                equ       $0000FFC0
XROM_END            equ       $0000FFCD
;
Vrtc                equ       $0000FFCE
VReserved23         equ       $0000FFD0
VReserved22         equ       $0000FFD2
VReserved21         equ       $0000FFD4
Vacmp               equ       $0000FFD6
Vadc                equ       $0000FFD8
Vkeyboard           equ       $0000FFDA
VReserved17         equ       $0000FFDC
Vscitx              equ       $0000FFDE
Vscirx              equ       $0000FFE0
Vscierr             equ       $0000FFE2
VReserved13         equ       $0000FFE4
Vmtim               equ       $0000FFE6
VReserved11         equ       $0000FFE8
VReserved10         equ       $0000FFEA
VReserved9          equ       $0000FFEC
VReserved8          equ       $0000FFEE
Vtpmovf             equ       $0000FFF0
VReserved6          equ       $0000FFF2
VReserved5          equ       $0000FFF4
Vtpmch0             equ       $0000FFF6
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
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD1         equ       %00000010
mPTAD_PTAD2         equ       %00000100
mPTAD_PTAD3         equ       %00001000
mPTAD_PTAD4         equ       %00010000
mPTAD_PTAD5         equ       %00100000


;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000001           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; Data Direction for Port A Bit 0
PTADD_PTADD1        equ       1                   ; Data Direction for Port A Bit 1
PTADD_PTADD2        equ       2                   ; Data Direction for Port A Bit 2
PTADD_PTADD3        equ       3                   ; Data Direction for Port A Bit 3
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000


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
; bit position masks
mPTCD_PTCD0         equ       %00000001
mPTCD_PTCD1         equ       %00000010
mPTCD_PTCD2         equ       %00000100
mPTCD_PTCD3         equ       %00001000


;*** PTCDD - Port C Data Direction Register
PTCDD               equ       $00000005           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; Data Direction for Port C Bit 0
PTCDD_PTCDD1        equ       1                   ; Data Direction for Port C Bit 1
PTCDD_PTCDD2        equ       2                   ; Data Direction for Port C Bit 2
PTCDD_PTCDD3        equ       3                   ; Data Direction for Port C Bit 3
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000


;*** KBISC - KBI Status and Control Register
KBISC               equ       $0000000C           ;*** KBISC - KBI Status and Control Register
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
KBIPE               equ       $0000000D           ;*** KBIPE - KBI Pin Enable Register
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
KBIES               equ       $0000000E           ;*** KBIES - KBI Edge Select Register
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


;*** IRQSC - Interrupt request status and control register
IRQSC               equ       $0000000F           ;*** IRQSC - Interrupt request status and control register
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


;*** ADCSC1 - Status and Control Register 1
ADCSC1              equ       $00000010           ;*** ADCSC1 - Status and Control Register 1
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
ADCSC2              equ       $00000011           ;*** ADCSC2 - Status and Control Register 2
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
ADCR                equ       $00000012           ;*** ADCR - Data Result Register


;*** ADCRH - Data Result High Register
ADCRH               equ       $00000012           ;*** ADCRH - Data Result High Register
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
ADCRL               equ       $00000013           ;*** ADCRL - Data Result Low Register
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
ADCCV               equ       $00000014           ;*** ADCCV - Compare Value Register


;*** ADCCVH - Compare Value High Register
ADCCVH              equ       $00000014           ;*** ADCCVH - Compare Value High Register
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
ADCCVL              equ       $00000015           ;*** ADCCVL - Compare Value Low Register
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
ADCCFG              equ       $00000016           ;*** ADCCFG - Configuration Register
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
APCTL1              equ       $00000017           ;*** APCTL1 - Pin Control 1 Register
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


;*** ACMPSC - ACMP Status and Control Register
ACMPSC              equ       $0000001A           ;*** ACMPSC - ACMP Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ACMPSC_ACMOD0       equ       0                   ; Analog Comparator Mode Bit 0
ACMPSC_ACMOD1       equ       1                   ; Analog Comparator Mode Bit 1
ACMPSC_ACOPE        equ       2                   ; Analog Comparator Output Pin Enable
ACMPSC_ACO          equ       3                   ; Analog Comparator Output
ACMPSC_ACIE         equ       4                   ; Analog Comparator Interrupt Enable
ACMPSC_ACF          equ       5                   ; Analog Comparator Flag
ACMPSC_ACBGS        equ       6                   ; Analog Comparator Bandgap Select
ACMPSC_ACME         equ       7                   ; Analog Comparator Module Enable
; bit position masks
mACMPSC_ACMOD0      equ       %00000001
mACMPSC_ACMOD1      equ       %00000010
mACMPSC_ACOPE       equ       %00000100
mACMPSC_ACO         equ       %00001000
mACMPSC_ACIE        equ       %00010000
mACMPSC_ACF         equ       %00100000
mACMPSC_ACBGS       equ       %01000000
mACMPSC_ACME        equ       %10000000


;*** SCIBD - SCI Baud Rate Register
SCIBD               equ       $00000020           ;*** SCIBD - SCI Baud Rate Register


;*** SCIBDH - SCI Baud Rate Register High
SCIBDH              equ       $00000020           ;*** SCIBDH - SCI Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIBDH_SBR8         equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCIBDH_SBR9         equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCIBDH_SBR10        equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCIBDH_SBR11        equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCIBDH_SBR12        equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCIBDH_RXEDGIE      equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCIBDH_LBKDIE       equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCIBDH_SBR8        equ       %00000001
mSCIBDH_SBR9        equ       %00000010
mSCIBDH_SBR10       equ       %00000100
mSCIBDH_SBR11       equ       %00001000
mSCIBDH_SBR12       equ       %00010000
mSCIBDH_RXEDGIE     equ       %01000000
mSCIBDH_LBKDIE      equ       %10000000


;*** SCIBDL - SCI Baud Rate Register Low
SCIBDL              equ       $00000021           ;*** SCIBDL - SCI Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIBDL_SBR0         equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCIBDL_SBR1         equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCIBDL_SBR2         equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCIBDL_SBR3         equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCIBDL_SBR4         equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCIBDL_SBR5         equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCIBDL_SBR6         equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCIBDL_SBR7         equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCIBDL_SBR0        equ       %00000001
mSCIBDL_SBR1        equ       %00000010
mSCIBDL_SBR2        equ       %00000100
mSCIBDL_SBR3        equ       %00001000
mSCIBDL_SBR4        equ       %00010000
mSCIBDL_SBR5        equ       %00100000
mSCIBDL_SBR6        equ       %01000000
mSCIBDL_SBR7        equ       %10000000


;*** SCIC1 - SCI Control Register 1
SCIC1               equ       $00000022           ;*** SCIC1 - SCI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIC1_PT            equ       0                   ; Parity Type
SCIC1_PE            equ       1                   ; Parity Enable
SCIC1_ILT           equ       2                   ; Idle Line Type Select
SCIC1_WAKE          equ       3                   ; Receiver Wakeup Method Select
SCIC1_M             equ       4                   ; 9-Bit or 8-Bit Mode Select
SCIC1_RSRC          equ       5                   ; Receiver Source Select
SCIC1_SCISWAI       equ       6                   ; SCI Stops in Wait Mode
SCIC1_LOOPS         equ       7                   ; Loop Mode Select
; bit position masks
mSCIC1_PT           equ       %00000001
mSCIC1_PE           equ       %00000010
mSCIC1_ILT          equ       %00000100
mSCIC1_WAKE         equ       %00001000
mSCIC1_M            equ       %00010000
mSCIC1_RSRC         equ       %00100000
mSCIC1_SCISWAI      equ       %01000000
mSCIC1_LOOPS        equ       %10000000


;*** SCIC2 - SCI Control Register 2
SCIC2               equ       $00000023           ;*** SCIC2 - SCI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIC2_SBK           equ       0                   ; Send Break
SCIC2_RWU           equ       1                   ; Receiver Wakeup Control
SCIC2_RE            equ       2                   ; Receiver Enable
SCIC2_TE            equ       3                   ; Transmitter Enable
SCIC2_ILIE          equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCIC2_RIE           equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCIC2_TCIE          equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCIC2_TIE           equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCIC2_SBK          equ       %00000001
mSCIC2_RWU          equ       %00000010
mSCIC2_RE           equ       %00000100
mSCIC2_TE           equ       %00001000
mSCIC2_ILIE         equ       %00010000
mSCIC2_RIE          equ       %00100000
mSCIC2_TCIE         equ       %01000000
mSCIC2_TIE          equ       %10000000


;*** SCIS1 - SCI Status Register 1
SCIS1               equ       $00000024           ;*** SCIS1 - SCI Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIS1_PF            equ       0                   ; Parity Error Flag
SCIS1_FE            equ       1                   ; Framing Error Flag
SCIS1_NF            equ       2                   ; Noise Flag
SCIS1_OR            equ       3                   ; Receiver Overrun Flag
SCIS1_IDLE          equ       4                   ; Idle Line Flag
SCIS1_RDRF          equ       5                   ; Receive Data Register Full Flag
SCIS1_TC            equ       6                   ; Transmission Complete Flag
SCIS1_TDRE          equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCIS1_PF           equ       %00000001
mSCIS1_FE           equ       %00000010
mSCIS1_NF           equ       %00000100
mSCIS1_OR           equ       %00001000
mSCIS1_IDLE         equ       %00010000
mSCIS1_RDRF         equ       %00100000
mSCIS1_TC           equ       %01000000
mSCIS1_TDRE         equ       %10000000


;*** SCIS2 - SCI Status Register 2
SCIS2               equ       $00000025           ;*** SCIS2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIS2_RAF           equ       0                   ; Receiver Active Flag
SCIS2_LBKDE         equ       1                   ; LIN Break Detection Enable
SCIS2_BRK13         equ       2                   ; Break Character Generation Length
SCIS2_RWUID         equ       3                   ; Receive Wake Up Idle Detect
SCIS2_RXINV         equ       4                   ; Receive Data Inversion
SCIS2_RXEDGIF       equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCIS2_LBKDIF        equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCIS2_RAF          equ       %00000001
mSCIS2_LBKDE        equ       %00000010
mSCIS2_BRK13        equ       %00000100
mSCIS2_RWUID        equ       %00001000
mSCIS2_RXINV        equ       %00010000
mSCIS2_RXEDGIF      equ       %01000000
mSCIS2_LBKDIF       equ       %10000000


;*** SCIC3 - SCI Control Register 3
SCIC3               equ       $00000026           ;*** SCIC3 - SCI Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCIC3_PEIE          equ       0                   ; Parity Error Interrupt Enable
SCIC3_FEIE          equ       1                   ; Framing Error Interrupt Enable
SCIC3_NEIE          equ       2                   ; Noise Error Interrupt Enable
SCIC3_ORIE          equ       3                   ; Overrun Interrupt Enable
SCIC3_TXINV         equ       4                   ; Transmit Data Inversion
SCIC3_TXDIR         equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCIC3_T8            equ       6                   ; Ninth Data Bit for Transmitter
SCIC3_R8            equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCIC3_PEIE         equ       %00000001
mSCIC3_FEIE         equ       %00000010
mSCIC3_NEIE         equ       %00000100
mSCIC3_ORIE         equ       %00001000
mSCIC3_TXINV        equ       %00010000
mSCIC3_TXDIR        equ       %00100000
mSCIC3_T8           equ       %01000000
mSCIC3_R8           equ       %10000000


;*** SCID - SCI Data Register
SCID                equ       $00000027           ;*** SCID - SCI Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCID_R0_T0          equ       0                   ; Receive/Transmit Data Bit 0
SCID_R1_T1          equ       1                   ; Receive/Transmit Data Bit 1
SCID_R2_T2          equ       2                   ; Receive/Transmit Data Bit 2
SCID_R3_T3          equ       3                   ; Receive/Transmit Data Bit 3
SCID_R4_T4          equ       4                   ; Receive/Transmit Data Bit 4
SCID_R5_T5          equ       5                   ; Receive/Transmit Data Bit 5
SCID_R6_T6          equ       6                   ; Receive/Transmit Data Bit 6
SCID_R7_T7          equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCID_R0_T0         equ       %00000001
mSCID_R1_T1         equ       %00000010
mSCID_R2_T2         equ       %00000100
mSCID_R3_T3         equ       %00001000
mSCID_R4_T4         equ       %00010000
mSCID_R5_T5         equ       %00100000
mSCID_R6_T6         equ       %01000000
mSCID_R7_T7         equ       %10000000


;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $00000038           ;*** ICSC1 - ICS Control Register 1
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
ICSC2               equ       $00000039           ;*** ICSC2 - ICS Control Register 2
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
ICSTRM              equ       $0000003A           ;*** ICSTRM - ICS Trim Register
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
ICSSC               equ       $0000003B           ;*** ICSSC - ICS Status and Control Register
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


;*** MTIMSC - MTIM Clock Configuration Register
MTIMSC              equ       $0000003C           ;*** MTIMSC - MTIM Clock Configuration Register
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
MTIMCLK             equ       $0000003D           ;*** MTIMCLK - MTIM Clock Configuration Register
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
MTIMCNT             equ       $0000003E           ;*** MTIMCNT - MTIM Counter Register


;*** MTIMMOD - MTIM Modulo Register
MTIMMOD             equ       $0000003F           ;*** MTIMMOD - MTIM Modulo Register


;*** TPMSC - TPM Status and Control Register
TPMSC               equ       $00000040           ;*** TPMSC - TPM Status and Control Register
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


;*** TPMCNT - TPM Timer Counter Register
TPMCNT              equ       $00000041           ;*** TPMCNT - TPM Timer Counter Register


;*** TPMCNTH - TPM Timer Counter Register High
TPMCNTH             equ       $00000041           ;*** TPMCNTH - TPM Timer Counter Register High


;*** TPMCNTL - TPM Timer Counter Register Low
TPMCNTL             equ       $00000042           ;*** TPMCNTL - TPM Timer Counter Register Low


;*** TPMMOD - TPM Timer Counter Modulo Register
TPMMOD              equ       $00000043           ;*** TPMMOD - TPM Timer Counter Modulo Register


;*** TPMMODH - TPM Timer Counter Modulo Register High
TPMMODH             equ       $00000043           ;*** TPMMODH - TPM Timer Counter Modulo Register High


;*** TPMMODL - TPM Timer Counter Modulo Register Low
TPMMODL             equ       $00000044           ;*** TPMMODL - TPM Timer Counter Modulo Register Low


;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register
TPMC0SC             equ       $00000045           ;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register
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


;*** TPMC0V - TPM Timer Channel 0 Value Register
TPMC0V              equ       $00000046           ;*** TPMC0V - TPM Timer Channel 0 Value Register


;*** TPMC0VH - TPM Timer Channel 0 Value Register High
TPMC0VH             equ       $00000046           ;*** TPMC0VH - TPM Timer Channel 0 Value Register High


;*** TPMC0VL - TPM Timer Channel 0 Value Register Low
TPMC0VL             equ       $00000047           ;*** TPMC0VL - TPM Timer Channel 0 Value Register Low


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
SOPT2_ACIC          equ       0                   ; Analog Comparator to Input Capture Enable
SOPT2_TPMCH0PS      equ       4                   ; TPMCH0 Pin Select
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_ACIC         equ       %00000001
mSOPT2_TPMCH0PS     equ       %00010000
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
SPMSC1              equ       $00001808           ;*** SPMSC1 - System Power Management Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE         equ       0                   ; Bandgap Buffer Enable
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE        equ       5                   ; Low-Voltage Detect Interrupt Enable
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
SPMSC2              equ       $00001809           ;*** SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC         equ       0                   ; Partial Power Down Control
SPMSC2_PPDE         equ       1                   ; Partial Power-Down Enable
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowledge
SPMSC2_PPDF         equ       3                   ; Partial Power Down Flag
SPMSC2_LPWUI        equ       5                   ; Low Power Wake Up on Interrupt
SPMSC2_LPRS         equ       6                   ; Low Power Regulator Status
SPMSC2_LPR          equ       7                   ; Low Power Regulator Control
; bit position masks
mSPMSC2_PPDC        equ       %00000001
mSPMSC2_PPDE        equ       %00000010
mSPMSC2_PPDACK      equ       %00000100
mSPMSC2_PPDF        equ       %00001000
mSPMSC2_LPWUI       equ       %00100000
mSPMSC2_LPRS        equ       %01000000
mSPMSC2_LPR         equ       %10000000


;*** SPMSC3 - System Power Management Status and Control 3 Register
SPMSC3              equ       $0000180B           ;*** SPMSC3 - System Power Management Status and Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC3_LVWIE        equ       3                   ; Low-Voltage Warning Interrupt Enable
SPMSC3_LVWACK       equ       6                   ; Low-Voltage Warning Acknowledge
SPMSC3_LVWF         equ       7                   ; Low-Voltage Warning Flag
; bit position masks
mSPMSC3_LVWIE       equ       %00001000
mSPMSC3_LVWACK      equ       %01000000
mSPMSC3_LVWF        equ       %10000000


;*** SCGC1 - System Clock Gating Control 1 Register
SCGC1               equ       $0000180E           ;*** SCGC1 - System Clock Gating Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI           equ       0                   ; SCI Clock Gate Control
SCGC1_ADC           equ       4                   ; ADC Clock Gate Control
SCGC1_TPM           equ       5                   ; TPM Clock Gate Control
SCGC1_MTIM          equ       7                   ; MTIM Clock Gate Control
; bit position masks
mSCGC1_SCI          equ       %00000001
mSCGC1_ADC          equ       %00010000
mSCGC1_TPM          equ       %00100000
mSCGC1_MTIM         equ       %10000000


;*** SCGC2 - System Clock Gating Control 2 Register
SCGC2               equ       $0000180F           ;*** SCGC2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_RTC           equ       2                   ; RTC Clock Gate Control
SCGC2_ACMP          equ       3                   ; ACMP Clock Gate Control
SCGC2_KBI           equ       4                   ; KBI Clock Gate Control
SCGC2_IRQ           equ       5                   ; IRQ Clock Gate Control
SCGC2_FLS           equ       6                   ; FLASH Register Clock Gate Control
; bit position masks
mSCGC2_RTC          equ       %00000100
mSCGC2_ACMP         equ       %00001000
mSCGC2_KBI          equ       %00010000
mSCGC2_IRQ          equ       %00100000
mSCGC2_FLS          equ       %01000000


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


;*** RTCSC - RTC Status and Control Register
RTCSC               equ       $00001830           ;*** RTCSC - RTC Status and Control Register
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
RTCCNT              equ       $00001831           ;*** RTCCNT - RTC Counter Register


;*** RTCMOD - RTC Modulo Register
RTCMOD              equ       $00001832           ;*** RTCMOD - RTC Modulo Register


;*** PTAPE - Port A Pull Enable Register
PTAPE               equ       $00001840           ;*** PTAPE - Port A Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pull Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pull Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pull Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pull Enable for Port A Bit 3
PTAPE_PTAPE5        equ       5                   ; Internal Pull Enable for Port A Bit 5
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE5       equ       %00100000


;*** PTASE - Port A Slew Rate Enable Register
PTASE               equ       $00001841           ;*** PTASE - Port A Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2        equ       2                   ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3        equ       3                   ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Output Slew Rate Enable for Port A Bit 4
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE2       equ       %00000100
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000


;*** PTADS - Port A Drive Strength Selection Register
PTADS               equ       $00001842           ;*** PTADS - Port A Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0        equ       0                   ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1        equ       1                   ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2        equ       2                   ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3        equ       3                   ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4        equ       4                   ; Output Drive Strength Selection for Port A Bit 4
; bit position masks
mPTADS_PTADS0       equ       %00000001
mPTADS_PTADS1       equ       %00000010
mPTADS_PTADS2       equ       %00000100
mPTADS_PTADS3       equ       %00001000
mPTADS_PTADS4       equ       %00010000


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
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000


;*** PTCSE - Port C Slew Rate Enable Register
PTCSE               equ       $00001849           ;*** PTCSE - Port C Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0        equ       0                   ; Output Slew Rate Enable for Port C Bit 0
PTCSE_PTCSE1        equ       1                   ; Output Slew Rate Enable for Port C Bit 1
PTCSE_PTCSE2        equ       2                   ; Output Slew Rate Enable for Port C Bit 2
PTCSE_PTCSE3        equ       3                   ; Output Slew Rate Enable for Port C Bit 3
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010
mPTCSE_PTCSE2       equ       %00000100
mPTCSE_PTCSE3       equ       %00001000


;*** PTCDS - Port C Drive Strength Selection Register
PTCDS               equ       $0000184A           ;*** PTCDS - Port C Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0        equ       0                   ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1        equ       1                   ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2        equ       2                   ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3        equ       3                   ; Output Drive Strength Selection for Port C Bit 3
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010
mPTCDS_PTCDS2       equ       %00000100
mPTCDS_PTCDS3       equ       %00001000


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

; EOF
