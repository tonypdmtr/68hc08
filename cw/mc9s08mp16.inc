;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08MP16_48, version 3.00.021 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08mp16.inc
;     Processor : MC9S08MP16VLF
;     FileFormat: V2.32
;     DataSheet : MC9S08MP16 Rev. 1 09/2009
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 13:42
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
ROM                 equ       $0000C000
ROM_END             equ       $0000FFAD
RAM                 equ       $00000090
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000048F
;
VReserved31         equ       $0000FFC0
Vkeyboard3          equ       $0000FFC2
Vkeyboard2          equ       $0000FFC4
Vkeyboard1          equ       $0000FFC6
Vhscmp3             equ       $0000FFC8
Vhscmp2             equ       $0000FFCA
Vhscmp1             equ       $0000FFCC
Vrtc                equ       $0000FFCE
Viic                equ       $0000FFD0
Vscitx              equ       $0000FFD2
Vscirx              equ       $0000FFD4
Vscierr             equ       $0000FFD6
Vspi                equ       $0000FFD8
Vadc                equ       $0000FFDA
Vpdb2               equ       $0000FFDC
Vpdb1               equ       $0000FFDE
Vmtim               equ       $0000FFE0
Vftm2ovf            equ       $0000FFE2
Vftm2ch5            equ       $0000FFE4
Vftm2ch4            equ       $0000FFE6
Vftm2ch3            equ       $0000FFE8
Vftm2ch2            equ       $0000FFEA
Vftm2ch1            equ       $0000FFEC
Vftm2ch0            equ       $0000FFEE
Vftm1ovf            equ       $0000FFF0
Vftm1ch1            equ       $0000FFF2
Vftm1ch0            equ       $0000FFF4
Vftm2fault          equ       $0000FFF6
Vftm1fault          equ       $0000FFF8
Vlvw                equ       $0000FFFA
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
PTCD_PTCD7          equ       7                   ; Port C Data Register Bit 7
; bit position masks
mPTCD_PTCD0         equ       %00000001
mPTCD_PTCD1         equ       %00000010
mPTCD_PTCD2         equ       %00000100
mPTCD_PTCD3         equ       %00001000
mPTCD_PTCD4         equ       %00010000
mPTCD_PTCD5         equ       %00100000
mPTCD_PTCD6         equ       %01000000
mPTCD_PTCD7         equ       %10000000


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
PTCDD_PTCDD7        equ       7                   ; Data Direction for Port C Bit 7
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000
mPTCDD_PTCDD4       equ       %00010000
mPTCDD_PTCDD5       equ       %00100000
mPTCDD_PTCDD6       equ       %01000000
mPTCDD_PTCDD7       equ       %10000000


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


;*** PTED - Port E Data Register
PTED                equ       $00000008           ;*** PTED - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTED_PTED0          equ       0                   ; Port E Data Register Bit 0
PTED_PTED1          equ       1                   ; Port E Data Register Bit 1
PTED_PTED2          equ       2                   ; Port E Data Register Bit 2
PTED_PTED3          equ       3                   ; Port E Data Register Bit 3
PTED_PTED4          equ       4                   ; Port E Data Register Bit 4
PTED_PTED5          equ       5                   ; Port E Data Register Bit 5
PTED_PTED6          equ       6                   ; Port E Data Register Bit 6
; bit position masks
mPTED_PTED0         equ       %00000001
mPTED_PTED1         equ       %00000010
mPTED_PTED2         equ       %00000100
mPTED_PTED3         equ       %00001000
mPTED_PTED4         equ       %00010000
mPTED_PTED5         equ       %00100000
mPTED_PTED6         equ       %01000000


;*** PTEDD - Port E Data Direction Register
PTEDD               equ       $00000009           ;*** PTEDD - Port E Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0        equ       0                   ; Data Direction for Port E Bit 0
PTEDD_PTEDD1        equ       1                   ; Data Direction for Port E Bit 1
PTEDD_PTEDD2        equ       2                   ; Data Direction for Port E Bit 2
PTEDD_PTEDD3        equ       3                   ; Data Direction for Port E Bit 3
PTEDD_PTEDD4        equ       4                   ; Data Direction for Port E Bit 4
PTEDD_PTEDD5        equ       5                   ; Data Direction for Port E Bit 5
PTEDD_PTEDD6        equ       6                   ; Data Direction for Port E Bit 6
; bit position masks
mPTEDD_PTEDD0       equ       %00000001
mPTEDD_PTEDD1       equ       %00000010
mPTEDD_PTEDD2       equ       %00000100
mPTEDD_PTEDD3       equ       %00001000
mPTEDD_PTEDD4       equ       %00010000
mPTEDD_PTEDD5       equ       %00100000
mPTEDD_PTEDD6       equ       %01000000


;*** PTFD - Port F Data Register
PTFD                equ       $0000000A           ;*** PTFD - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFD_PTFD0          equ       0                   ; Port F Data Register Bit 0
PTFD_PTFD1          equ       1                   ; Port F Data Register Bit 1
PTFD_PTFD2          equ       2                   ; Port F Data Register Bit 2
; bit position masks
mPTFD_PTFD0         equ       %00000001
mPTFD_PTFD1         equ       %00000010
mPTFD_PTFD2         equ       %00000100


;*** PTFDD - Port F Data Direction Register
PTFDD               equ       $0000000B           ;*** PTFDD - Port F Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDD_PTFDD0        equ       0                   ; Data Direction for Port F Bit 0
PTFDD_PTFDD1        equ       1                   ; Data Direction for Port F Bit 1
PTFDD_PTFDD2        equ       2                   ; Data Direction for Port F Bit 2
; bit position masks
mPTFDD_PTFDD0       equ       %00000001
mPTFDD_PTFDD1       equ       %00000010
mPTFDD_PTFDD2       equ       %00000100


;*** KBI1SC - KBI1 Status and Control Register
KBI1SC              equ       $0000000C           ;*** KBI1SC - KBI1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1SC_KBIMOD       equ       0                   ; Keyboard Detection Mode
KBI1SC_KBIE         equ       1                   ; Keyboard Interrupt Enable
KBI1SC_KBACK        equ       2                   ; Keyboard Interrupt Acknowledge
KBI1SC_KBF          equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI1SC_KBIMOD      equ       %00000001
mKBI1SC_KBIE        equ       %00000010
mKBI1SC_KBACK       equ       %00000100
mKBI1SC_KBF         equ       %00001000


;*** KBI1PE - KBI1 Pin Enable Register
KBI1PE              equ       $0000000D           ;*** KBI1PE - KBI1 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI1PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI1PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI1PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBI1PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBI1PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBI1PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBI1PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI1PE_KBIPE0      equ       %00000001
mKBI1PE_KBIPE1      equ       %00000010
mKBI1PE_KBIPE2      equ       %00000100
mKBI1PE_KBIPE3      equ       %00001000
mKBI1PE_KBIPE4      equ       %00010000
mKBI1PE_KBIPE5      equ       %00100000
mKBI1PE_KBIPE6      equ       %01000000
mKBI1PE_KBIPE7      equ       %10000000


;*** KBI1ES - KBI1 Edge Select Register
KBI1ES              equ       $0000000E           ;*** KBI1ES - KBI1 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1ES_KBEDG0       equ       0                   ; Keyboard Edge Select Bit 0
KBI1ES_KBEDG1       equ       1                   ; Keyboard Edge Select Bit 1
KBI1ES_KBEDG2       equ       2                   ; Keyboard Edge Select Bit 2
KBI1ES_KBEDG3       equ       3                   ; Keyboard Edge Select Bit 3
KBI1ES_KBEDG4       equ       4                   ; Keyboard Edge Select Bit 4
KBI1ES_KBEDG5       equ       5                   ; Keyboard Edge Select Bit 5
KBI1ES_KBEDG6       equ       6                   ; Keyboard Edge Select Bit 6
KBI1ES_KBEDG7       equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBI1ES_KBEDG0      equ       %00000001
mKBI1ES_KBEDG1      equ       %00000010
mKBI1ES_KBEDG2      equ       %00000100
mKBI1ES_KBEDG3      equ       %00001000
mKBI1ES_KBEDG4      equ       %00010000
mKBI1ES_KBEDG5      equ       %00100000
mKBI1ES_KBEDG6      equ       %01000000
mKBI1ES_KBEDG7      equ       %10000000


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


;*** APCTL2 - Pin Control 2 Register
APCTL2              equ       $00000018           ;*** APCTL2 - Pin Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL2_ADPC8        equ       0                   ; ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8
APCTL2_ADPC9        equ       1                   ; ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9
APCTL2_ADPC10       equ       2                   ; ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10
APCTL2_ADPC11       equ       3                   ; ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11
APCTL2_ADPC12       equ       4                   ; ADC Pin Control 12 - ADPC12 is used to control the pin associated with channel AD12
; bit position masks
mAPCTL2_ADPC8       equ       %00000001
mAPCTL2_ADPC9       equ       %00000010
mAPCTL2_ADPC10      equ       %00000100
mAPCTL2_ADPC11      equ       %00001000
mAPCTL2_ADPC12      equ       %00010000


;*** DAC1CTRL - DAC Control Register
DAC1CTRL            equ       $00000019           ;*** DAC1CTRL - DAC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DAC1CTRL_VOSEL0     equ       0                   ; DAC output voltage select, bit 0
DAC1CTRL_VOSEL1     equ       1                   ; DAC output voltage select, bit 1
DAC1CTRL_VOSEL2     equ       2                   ; DAC output voltage select, bit 2
DAC1CTRL_VOSEL3     equ       3                   ; DAC output voltage select, bit 3
DAC1CTRL_VOSEL4     equ       4                   ; DAC output voltage select, bit 4
DAC1CTRL_DACEN      equ       7                   ; DAC enable. When the module is disabled, the DAC is powered down to conserve power
; bit position masks
mDAC1CTRL_VOSEL0    equ       %00000001
mDAC1CTRL_VOSEL1    equ       %00000010
mDAC1CTRL_VOSEL2    equ       %00000100
mDAC1CTRL_VOSEL3    equ       %00001000
mDAC1CTRL_VOSEL4    equ       %00010000
mDAC1CTRL_DACEN     equ       %10000000


;*** DAC2CTRL - DAC Control Register
DAC2CTRL            equ       $0000001A           ;*** DAC2CTRL - DAC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DAC2CTRL_VOSEL0     equ       0                   ; DAC output voltage select, bit 0
DAC2CTRL_VOSEL1     equ       1                   ; DAC output voltage select, bit 1
DAC2CTRL_VOSEL2     equ       2                   ; DAC output voltage select, bit 2
DAC2CTRL_VOSEL3     equ       3                   ; DAC output voltage select, bit 3
DAC2CTRL_VOSEL4     equ       4                   ; DAC output voltage select, bit 4
DAC2CTRL_DACEN      equ       7                   ; DAC enable. When the module is disabled, the DAC is powered down to conserve power
; bit position masks
mDAC2CTRL_VOSEL0    equ       %00000001
mDAC2CTRL_VOSEL1    equ       %00000010
mDAC2CTRL_VOSEL2    equ       %00000100
mDAC2CTRL_VOSEL3    equ       %00001000
mDAC2CTRL_VOSEL4    equ       %00010000
mDAC2CTRL_DACEN     equ       %10000000


;*** DAC3CTRL - DAC Control Register
DAC3CTRL            equ       $0000001B           ;*** DAC3CTRL - DAC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DAC3CTRL_VOSEL0     equ       0                   ; DAC output voltage select, bit 0
DAC3CTRL_VOSEL1     equ       1                   ; DAC output voltage select, bit 1
DAC3CTRL_VOSEL2     equ       2                   ; DAC output voltage select, bit 2
DAC3CTRL_VOSEL3     equ       3                   ; DAC output voltage select, bit 3
DAC3CTRL_VOSEL4     equ       4                   ; DAC output voltage select, bit 4
DAC3CTRL_DACEN      equ       7                   ; DAC enable. When the module is disabled, the DAC is powered down to conserve power
; bit position masks
mDAC3CTRL_VOSEL0    equ       %00000001
mDAC3CTRL_VOSEL1    equ       %00000010
mDAC3CTRL_VOSEL2    equ       %00000100
mDAC3CTRL_VOSEL3    equ       %00001000
mDAC3CTRL_VOSEL4    equ       %00010000
mDAC3CTRL_DACEN     equ       %10000000


;*** KBI2SC - KBI2 Status and Control Register
KBI2SC              equ       $0000001C           ;*** KBI2SC - KBI2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2SC_KBIMOD       equ       0                   ; Keyboard Detection Mode
KBI2SC_KBIE         equ       1                   ; Keyboard Interrupt Enable
KBI2SC_KBACK        equ       2                   ; Keyboard Interrupt Acknowledge
KBI2SC_KBF          equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI2SC_KBIMOD      equ       %00000001
mKBI2SC_KBIE        equ       %00000010
mKBI2SC_KBACK       equ       %00000100
mKBI2SC_KBF         equ       %00001000


;*** KBI2PE - KBI2 Pin Enable Register
KBI2PE              equ       $0000001D           ;*** KBI2PE - KBI2 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI2PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI2PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI2PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBI2PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBI2PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBI2PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBI2PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI2PE_KBIPE0      equ       %00000001
mKBI2PE_KBIPE1      equ       %00000010
mKBI2PE_KBIPE2      equ       %00000100
mKBI2PE_KBIPE3      equ       %00001000
mKBI2PE_KBIPE4      equ       %00010000
mKBI2PE_KBIPE5      equ       %00100000
mKBI2PE_KBIPE6      equ       %01000000
mKBI2PE_KBIPE7      equ       %10000000


;*** KBI2ES - KBI2 Edge Select Register
KBI2ES              equ       $0000001E           ;*** KBI2ES - KBI2 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2ES_KBEDG0       equ       0                   ; Keyboard Edge Select Bit 0
KBI2ES_KBEDG1       equ       1                   ; Keyboard Edge Select Bit 1
KBI2ES_KBEDG2       equ       2                   ; Keyboard Edge Select Bit 2
KBI2ES_KBEDG3       equ       3                   ; Keyboard Edge Select Bit 3
KBI2ES_KBEDG4       equ       4                   ; Keyboard Edge Select Bit 4
KBI2ES_KBEDG5       equ       5                   ; Keyboard Edge Select Bit 5
KBI2ES_KBEDG6       equ       6                   ; Keyboard Edge Select Bit 6
KBI2ES_KBEDG7       equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBI2ES_KBEDG0      equ       %00000001
mKBI2ES_KBEDG1      equ       %00000010
mKBI2ES_KBEDG2      equ       %00000100
mKBI2ES_KBEDG3      equ       %00001000
mKBI2ES_KBEDG4      equ       %00010000
mKBI2ES_KBEDG5      equ       %00100000
mKBI2ES_KBEDG6      equ       %01000000
mKBI2ES_KBEDG7      equ       %10000000


;*** IICA1 - IIC Address Register
IICA1               equ       $00000020           ;*** IICA1 - IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA1_AD1           equ       1                   ; Slave Address Bit 1
IICA1_AD2           equ       2                   ; Slave Address Bit 2
IICA1_AD3           equ       3                   ; Slave Address Bit 3
IICA1_AD4           equ       4                   ; Slave Address Bit 4
IICA1_AD5           equ       5                   ; Slave Address Bit 5
IICA1_AD6           equ       6                   ; Slave Address Bit 6
IICA1_AD7           equ       7                   ; Slave Address Bit 7
; bit position masks
mIICA1_AD1          equ       %00000010
mIICA1_AD2          equ       %00000100
mIICA1_AD3          equ       %00001000
mIICA1_AD4          equ       %00010000
mIICA1_AD5          equ       %00100000
mIICA1_AD6          equ       %01000000
mIICA1_AD7          equ       %10000000


;*** IICA - IIC Address Register
IICA                equ       $00000020           ;*** IICA - IIC Address Register
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
IICF                equ       $00000021           ;*** IICF - IIC Frequency Divider Register
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
IICC1               equ       $00000022           ;*** IICC1 - IIC Control Register 1
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
IICC                equ       $00000022           ;*** IICC - IIC Control Register
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
IICS                equ       $00000023           ;*** IICS - IIC Status Register
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
IICD                equ       $00000024           ;*** IICD - IIC Data I/O Register
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
IICC2               equ       $00000025           ;*** IICC2 - IIC Control Register 2
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


;*** IICSMB - SMBus Control and Status Register
IICSMB              equ       $00000026           ;*** IICSMB - SMBus Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSMB_SHTF         equ       2                   ; SCL High Timeout Flag
IICSMB_SLTF         equ       3                   ; SCL Low Timeout Flag
IICSMB_TCKSEL       equ       4                   ; Time Out Counter Clock Select
IICSMB_SIICAEN      equ       5                   ; Second IIC Address Enable
IICSMB_ALERTEN      equ       6                   ; SMBus Alert Response Address Enable
IICSMB_FACK         equ       7                   ; Fast NACK/ACK enable
; bit position masks
mIICSMB_SHTF        equ       %00000100
mIICSMB_SLTF        equ       %00001000
mIICSMB_TCKSEL      equ       %00010000
mIICSMB_SIICAEN     equ       %00100000
mIICSMB_ALERTEN     equ       %01000000
mIICSMB_FACK        equ       %10000000


;*** IICA2 - IIC Address Register 2
IICA2               equ       $00000027           ;*** IICA2 - IIC Address Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA2_SAD1          equ       1                   ; SMBus Address Bit 1
IICA2_SAD2          equ       2                   ; SMBus Address Bit 2
IICA2_SAD3          equ       3                   ; SMBus Address Bit 3
IICA2_SAD4          equ       4                   ; SMBus Address Bit 4
IICA2_SAD5          equ       5                   ; SMBus Address Bit 5
IICA2_SAD6          equ       6                   ; SMBus Address Bit 6
IICA2_SAD7          equ       7                   ; SMBus Address Bit 7
; bit position masks
mIICA2_SAD1         equ       %00000010
mIICA2_SAD2         equ       %00000100
mIICA2_SAD3         equ       %00001000
mIICA2_SAD4         equ       %00010000
mIICA2_SAD5         equ       %00100000
mIICA2_SAD6         equ       %01000000
mIICA2_SAD7         equ       %10000000


;*** IICSLT - IIC SCL Low Time Out register
IICSLT              equ       $00000028           ;*** IICSLT - IIC SCL Low Time Out register


;*** IICSLTH - IIC SCL Low Time Out register - High byte
IICSLTH             equ       $00000028           ;*** IICSLTH - IIC SCL Low Time Out register - High byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLTH_SSLT8       equ       0                   ; SCL Low Time Out Bit 8
IICSLTH_SSLT9       equ       1                   ; SCL Low Time Out Bit 9
IICSLTH_SSLT10      equ       2                   ; SCL Low Time Out Bit 10
IICSLTH_SSLT11      equ       3                   ; SCL Low Time Out Bit 11
IICSLTH_SSLT12      equ       4                   ; SCL Low Time Out Bit 12
IICSLTH_SSLT13      equ       5                   ; SCL Low Time Out Bit 13
IICSLTH_SSLT14      equ       6                   ; SCL Low Time Out Bit 14
IICSLTH_SSLT15      equ       7                   ; SCL Low Time Out Bit 15
; bit position masks
mIICSLTH_SSLT8      equ       %00000001
mIICSLTH_SSLT9      equ       %00000010
mIICSLTH_SSLT10     equ       %00000100
mIICSLTH_SSLT11     equ       %00001000
mIICSLTH_SSLT12     equ       %00010000
mIICSLTH_SSLT13     equ       %00100000
mIICSLTH_SSLT14     equ       %01000000
mIICSLTH_SSLT15     equ       %10000000


;*** IICSLTL - IIC SCL Low Time Out register - Low byte
IICSLTL             equ       $00000029           ;*** IICSLTL - IIC SCL Low Time Out register - Low byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLTL_SSLT0       equ       0                   ; SCL Low Time Out Bits, bit 0
IICSLTL_SSLT1       equ       1                   ; SCL Low Time Out Bits, bit 1
IICSLTL_SSLT2       equ       2                   ; SCL Low Time Out Bits, bit 2
IICSLTL_SSLT3       equ       3                   ; SCL Low Time Out Bits, bit 3
IICSLTL_SSLT4       equ       4                   ; SCL Low Time Out Bits, bit 4
IICSLTL_SSLT5       equ       5                   ; SCL Low Time Out Bits, bit 5
IICSLTL_SSLT6       equ       6                   ; SCL Low Time Out Bits, bit 6
IICSLTL_SSLT7       equ       7                   ; SCL Low Time Out Bits, bit 7
; bit position masks
mIICSLTL_SSLT0      equ       %00000001
mIICSLTL_SSLT1      equ       %00000010
mIICSLTL_SSLT2      equ       %00000100
mIICSLTL_SSLT3      equ       %00001000
mIICSLTL_SSLT4      equ       %00010000
mIICSLTL_SSLT5      equ       %00100000
mIICSLTL_SSLT6      equ       %01000000
mIICSLTL_SSLT7      equ       %10000000


;*** IICFLT - IIC Filter register
IICFLT              equ       $0000002A           ;*** IICFLT - IIC Filter register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICFLT_FLT0         equ       0                   ; Filter value bit 0
IICFLT_FLT1         equ       1                   ; Filter value bit 1
IICFLT_FLT2         equ       2                   ; Filter value bit 2
; bit position masks
mIICFLT_FLT0        equ       %00000001
mIICFLT_FLT1        equ       %00000010
mIICFLT_FLT2        equ       %00000100


;*** KBI3SC - KBI3 Status and Control Register
KBI3SC              equ       $0000002C           ;*** KBI3SC - KBI3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI3SC_KBIMOD       equ       0                   ; Keyboard Detection Mode
KBI3SC_KBIE         equ       1                   ; Keyboard Interrupt Enable
KBI3SC_KBACK        equ       2                   ; Keyboard Interrupt Acknowledge
KBI3SC_KBF          equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI3SC_KBIMOD      equ       %00000001
mKBI3SC_KBIE        equ       %00000010
mKBI3SC_KBACK       equ       %00000100
mKBI3SC_KBF         equ       %00001000


;*** KBI3PE - KBI3 Pin Enable Register
KBI3PE              equ       $0000002D           ;*** KBI3PE - KBI3 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI3PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI3PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI3PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI3PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBI3PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBI3PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBI3PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBI3PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI3PE_KBIPE0      equ       %00000001
mKBI3PE_KBIPE1      equ       %00000010
mKBI3PE_KBIPE2      equ       %00000100
mKBI3PE_KBIPE3      equ       %00001000
mKBI3PE_KBIPE4      equ       %00010000
mKBI3PE_KBIPE5      equ       %00100000
mKBI3PE_KBIPE6      equ       %01000000
mKBI3PE_KBIPE7      equ       %10000000


;*** KBI3ES - KBI3 Edge Select Register
KBI3ES              equ       $0000002E           ;*** KBI3ES - KBI3 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI3ES_KBEDG0       equ       0                   ; Keyboard Edge Select Bit 0
KBI3ES_KBEDG1       equ       1                   ; Keyboard Edge Select Bit 1
KBI3ES_KBEDG2       equ       2                   ; Keyboard Edge Select Bit 2
KBI3ES_KBEDG3       equ       3                   ; Keyboard Edge Select Bit 3
KBI3ES_KBEDG4       equ       4                   ; Keyboard Edge Select Bit 4
KBI3ES_KBEDG5       equ       5                   ; Keyboard Edge Select Bit 5
KBI3ES_KBEDG6       equ       6                   ; Keyboard Edge Select Bit 6
KBI3ES_KBEDG7       equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBI3ES_KBEDG0      equ       %00000001
mKBI3ES_KBEDG1      equ       %00000010
mKBI3ES_KBEDG2      equ       %00000100
mKBI3ES_KBEDG3      equ       %00001000
mKBI3ES_KBEDG4      equ       %00010000
mKBI3ES_KBEDG5      equ       %00100000
mKBI3ES_KBEDG6      equ       %01000000
mKBI3ES_KBEDG7      equ       %10000000


;*** FTM1SC - FTM1 Status and Control Register
FTM1SC              equ       $00000030           ;*** FTM1SC - FTM1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1SC_PS0          equ       0                   ; Prescale Divisor Select Bit 0
FTM1SC_PS1          equ       1                   ; Prescale Divisor Select Bit 1
FTM1SC_PS2          equ       2                   ; Prescale Divisor Select Bit 2
FTM1SC_CLKSA        equ       3                   ; Clock Source Select A
FTM1SC_CLKSB        equ       4                   ; Clock Source Select B
FTM1SC_CPWMS        equ       5                   ; Center-Aligned PWM Select
FTM1SC_TOIE         equ       6                   ; Timer Overflow Interrupt Enable
FTM1SC_TOF          equ       7                   ; Timer Overflow Flag
; bit position masks
mFTM1SC_PS0         equ       %00000001
mFTM1SC_PS1         equ       %00000010
mFTM1SC_PS2         equ       %00000100
mFTM1SC_CLKSA       equ       %00001000
mFTM1SC_CLKSB       equ       %00010000
mFTM1SC_CPWMS       equ       %00100000
mFTM1SC_TOIE        equ       %01000000
mFTM1SC_TOF         equ       %10000000


;*** FTM1CNT - FTM1 Timer Counter Register
FTM1CNT             equ       $00000031           ;*** FTM1CNT - FTM1 Timer Counter Register


;*** FTM1CNTH - FTM1 Timer Counter Register High
FTM1CNTH            equ       $00000031           ;*** FTM1CNTH - FTM1 Timer Counter Register High


;*** FTM1CNTL - FTM1 Timer Counter Register Low
FTM1CNTL            equ       $00000032           ;*** FTM1CNTL - FTM1 Timer Counter Register Low


;*** FTM1MOD - FTM1 Timer Counter Modulo Register
FTM1MOD             equ       $00000033           ;*** FTM1MOD - FTM1 Timer Counter Modulo Register


;*** FTM1MODH - FTM1 Timer Counter Modulo Register High
FTM1MODH            equ       $00000033           ;*** FTM1MODH - FTM1 Timer Counter Modulo Register High


;*** FTM1MODL - FTM1 Timer Counter Modulo Register Low
FTM1MODL            equ       $00000034           ;*** FTM1MODL - FTM1 Timer Counter Modulo Register Low


;*** FTM1C0SC - FTM1 Timer Channel 0 Status and Control Register
FTM1C0SC            equ       $00000035           ;*** FTM1C0SC - FTM1 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1C0SC_ELS0A      equ       2                   ; Edge/Level Select Bit A
FTM1C0SC_ELS0B      equ       3                   ; Edge/Level Select Bit B
FTM1C0SC_MS0A       equ       4                   ; Mode Select A for FTM1 Channel 0
FTM1C0SC_MS0B       equ       5                   ; Mode Select B for FTM1 Channel 0
FTM1C0SC_CH0IE      equ       6                   ; Channel 0 Interrupt Enable
FTM1C0SC_CH0F       equ       7                   ; Channel 0 Flag
; bit position masks
mFTM1C0SC_ELS0A     equ       %00000100
mFTM1C0SC_ELS0B     equ       %00001000
mFTM1C0SC_MS0A      equ       %00010000
mFTM1C0SC_MS0B      equ       %00100000
mFTM1C0SC_CH0IE     equ       %01000000
mFTM1C0SC_CH0F      equ       %10000000


;*** FTM1C0V - FTM1 Timer Channel 0 Value Register
FTM1C0V             equ       $00000036           ;*** FTM1C0V - FTM1 Timer Channel 0 Value Register


;*** FTM1C0VH - FTM1 Timer Channel 0 Value Register High
FTM1C0VH            equ       $00000036           ;*** FTM1C0VH - FTM1 Timer Channel 0 Value Register High


;*** FTM1C0VL - FTM1 Timer Channel 0 Value Register Low
FTM1C0VL            equ       $00000037           ;*** FTM1C0VL - FTM1 Timer Channel 0 Value Register Low


;*** FTM1C1SC - FTM1 Timer Channel 1 Status and Control Register
FTM1C1SC            equ       $00000038           ;*** FTM1C1SC - FTM1 Timer Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1C1SC_ELS1A      equ       2                   ; Edge/Level Select Bit A
FTM1C1SC_ELS1B      equ       3                   ; Edge/Level Select Bit B
FTM1C1SC_MS1A       equ       4                   ; Mode Select A for FTM1 Channel 1
FTM1C1SC_MS1B       equ       5                   ; Mode Select B for FTM1 Channel 1
FTM1C1SC_CH1IE      equ       6                   ; Channel 1 Interrupt Enable
FTM1C1SC_CH1F       equ       7                   ; Channel 1 Flag
; bit position masks
mFTM1C1SC_ELS1A     equ       %00000100
mFTM1C1SC_ELS1B     equ       %00001000
mFTM1C1SC_MS1A      equ       %00010000
mFTM1C1SC_MS1B      equ       %00100000
mFTM1C1SC_CH1IE     equ       %01000000
mFTM1C1SC_CH1F      equ       %10000000


;*** FTM1C1V - FTM1 Timer Channel 1 Value Register
FTM1C1V             equ       $00000039           ;*** FTM1C1V - FTM1 Timer Channel 1 Value Register


;*** FTM1C1VH - FTM1 Timer Channel 1 Value Register High
FTM1C1VH            equ       $00000039           ;*** FTM1C1VH - FTM1 Timer Channel 1 Value Register High


;*** FTM1C1VL - FTM1 Timer Channel 1 Value Register Low
FTM1C1VL            equ       $0000003A           ;*** FTM1C1VL - FTM1 Timer Channel 1 Value Register Low


;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $0000003C           ;*** ICSC1 - ICS Control Register 1
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
ICSC2               equ       $0000003D           ;*** ICSC2 - ICS Control Register 2
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
ICSTRM              equ       $0000003E           ;*** ICSTRM - ICS Trim Register
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
ICSSC               equ       $0000003F           ;*** ICSSC - ICS Status and Control Register
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


;*** FTM1CNTIN - FTM1 Counter Initial Value Registers
FTM1CNTIN           equ       $00000040           ;*** FTM1CNTIN - FTM1 Counter Initial Value Registers


;*** FTM1CNTINH - FTM1 Counter Initial Value Registers High
FTM1CNTINH          equ       $00000040           ;*** FTM1CNTINH - FTM1 Counter Initial Value Registers High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1CNTINH_BIT8     equ       0                   ; FTM1 Counter Initial Value Bit 8
FTM1CNTINH_BIT9     equ       1                   ; FTM1 Counter Initial Value Bit 9
FTM1CNTINH_BIT10    equ       2                   ; FTM1 Counter Initial Value Bit 10
FTM1CNTINH_BIT11    equ       3                   ; FTM1 Counter Initial Value Bit 11
FTM1CNTINH_BIT12    equ       4                   ; FTM1 Counter Initial Value Bit 12
FTM1CNTINH_BIT13    equ       5                   ; FTM1 Counter Initial Value Bit 13
FTM1CNTINH_BIT14    equ       6                   ; FTM1 Counter Initial Value Bit 14
FTM1CNTINH_BIT15    equ       7                   ; FTM1 Counter Initial Value Bit 15
; bit position masks
mFTM1CNTINH_BIT8    equ       %00000001
mFTM1CNTINH_BIT9    equ       %00000010
mFTM1CNTINH_BIT10   equ       %00000100
mFTM1CNTINH_BIT11   equ       %00001000
mFTM1CNTINH_BIT12   equ       %00010000
mFTM1CNTINH_BIT13   equ       %00100000
mFTM1CNTINH_BIT14   equ       %01000000
mFTM1CNTINH_BIT15   equ       %10000000


;*** FTM1CNTINL - FTM1 Counter Initial Value Registers Low
FTM1CNTINL          equ       $00000041           ;*** FTM1CNTINL - FTM1 Counter Initial Value Registers Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1CNTINL_BIT0     equ       0                   ; FTM1 Counter Initial Value Bit 0
FTM1CNTINL_BIT1     equ       1                   ; FTM1 Counter Initial Value Bit 1
FTM1CNTINL_BIT2     equ       2                   ; FTM1 Counter Initial Value Bit 2
FTM1CNTINL_BIT3     equ       3                   ; FTM1 Counter Initial Value Bit 3
FTM1CNTINL_BIT4     equ       4                   ; FTM1 Counter Initial Value Bit 4
FTM1CNTINL_BIT5     equ       5                   ; FTM1 Counter Initial Value Bit 5
FTM1CNTINL_BIT6     equ       6                   ; FTM1 Counter Initial Value Bit 6
FTM1CNTINL_BIT7     equ       7                   ; FTM1 Counter Initial Value Bit 7
; bit position masks
mFTM1CNTINL_BIT0    equ       %00000001
mFTM1CNTINL_BIT1    equ       %00000010
mFTM1CNTINL_BIT2    equ       %00000100
mFTM1CNTINL_BIT3    equ       %00001000
mFTM1CNTINL_BIT4    equ       %00010000
mFTM1CNTINL_BIT5    equ       %00100000
mFTM1CNTINL_BIT6    equ       %01000000
mFTM1CNTINL_BIT7    equ       %10000000


;*** FTM1STATUS - FTM1 Capture and Compare Status Register
FTM1STATUS          equ       $00000042           ;*** FTM1STATUS - FTM1 Capture and Compare Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1STATUS_CH0F     equ       0                   ; Channel 0 Flag
FTM1STATUS_CH1F     equ       1                   ; Channel 1 Flag
; bit position masks
mFTM1STATUS_CH0F    equ       %00000001
mFTM1STATUS_CH1F    equ       %00000010


;*** FTM1MODE - FTM1 Features Mode Selection Register
FTM1MODE            equ       $00000043           ;*** FTM1MODE - FTM1 Features Mode Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1MODE_FTMEN      equ       0                   ; FTM1 Enable
FTM1MODE_INIT       equ       1                   ; Initialize the Channels Output
FTM1MODE_WPDIS      equ       2                   ; Write Protected Disable
FTM1MODE_PWMSYNC    equ       3                   ; PWM synchronization mode
FTM1MODE_CAPTTEST   equ       4                   ; Capture test mode enable
FTM1MODE_FAULTM0    equ       5                   ; Fault Control Mode Bits, bit 0
FTM1MODE_FAULTM1    equ       6                   ; Fault Control Mode Bits, bit 1
FTM1MODE_FAULTIE    equ       7                   ; Fault Interrupt Enable
; bit position masks
mFTM1MODE_FTMEN     equ       %00000001
mFTM1MODE_INIT      equ       %00000010
mFTM1MODE_WPDIS     equ       %00000100
mFTM1MODE_PWMSYNC   equ       %00001000
mFTM1MODE_CAPTTEST  equ       %00010000
mFTM1MODE_FAULTM0   equ       %00100000
mFTM1MODE_FAULTM1   equ       %01000000
mFTM1MODE_FAULTIE   equ       %10000000


;*** FTM1SYNC - FTM1 Synchronization Register
FTM1SYNC            equ       $00000044           ;*** FTM1SYNC - FTM1 Synchronization Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1SYNC_CNTMIN     equ       0                   ; FTM1 Counter is Minimum
FTM1SYNC_CNTMAX     equ       1                   ; FTM1 Counter is Maximum
FTM1SYNC_REINIT     equ       2                   ; Reinitialization of FTM1 Counter by Synchronization
FTM1SYNC_SYNCHOM    equ       3                   ; Output Mask by Synchronization
FTM1SYNC_TRIG0      equ       4                   ; External Trigger Bit 0 for Synchronization
FTM1SYNC_TRIG1      equ       5                   ; External Trigger Bit 1 for Synchronization
FTM1SYNC_TRIG2      equ       6                   ; External Trigger Bit 2 for Synchronization
FTM1SYNC_SWSYNC     equ       7                   ; Software Trigger for Synchronization
; bit position masks
mFTM1SYNC_CNTMIN    equ       %00000001
mFTM1SYNC_CNTMAX    equ       %00000010
mFTM1SYNC_REINIT    equ       %00000100
mFTM1SYNC_SYNCHOM   equ       %00001000
mFTM1SYNC_TRIG0     equ       %00010000
mFTM1SYNC_TRIG1     equ       %00100000
mFTM1SYNC_TRIG2     equ       %01000000
mFTM1SYNC_SWSYNC    equ       %10000000


;*** FTM1OUTINIT - FTM1 Initial State for Channels Output Register
FTM1OUTINIT         equ       $00000045           ;*** FTM1OUTINIT - FTM1 Initial State for Channels Output Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1OUTINIT_CH0OI   equ       0                   ; Initial State for Channel 0 Output
FTM1OUTINIT_CH1OI   equ       1                   ; Initial State for Channel 1 Output
; bit position masks
mFTM1OUTINIT_CH0OI  equ       %00000001
mFTM1OUTINIT_CH1OI  equ       %00000010


;*** FTM1OUTMASK - FTM1 Output Mask Register
FTM1OUTMASK         equ       $00000046           ;*** FTM1OUTMASK - FTM1 Output Mask Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1OUTMASK_CH0OM   equ       0                   ; Channel 0 Output Mask
FTM1OUTMASK_CH1OM   equ       1                   ; Channel 1 Output Mask
; bit position masks
mFTM1OUTMASK_CH0OM  equ       %00000001
mFTM1OUTMASK_CH1OM  equ       %00000010


;*** FTM1COMBINE0 - FTM1 Function For Linked Channel 0 Register
FTM1COMBINE0        equ       $00000047           ;*** FTM1COMBINE0 - FTM1 Function For Linked Channel 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1COMBINE0_COMBINE equ       0                   ; Enables the Combine of the Channels 0 and 1
FTM1COMBINE0_COMP   equ       1                   ; Complementary of Channel 0
FTM1COMBINE0_DTEN   equ       4                   ; Deadtime Enable
FTM1COMBINE0_SYNCEN equ       5                   ; Synchronization Enable
FTM1COMBINE0_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM1COMBINE0_COMBINE equ       %00000001
mFTM1COMBINE0_COMP  equ       %00000010
mFTM1COMBINE0_DTEN  equ       %00010000
mFTM1COMBINE0_SYNCEN equ       %00100000
mFTM1COMBINE0_FAULTEN equ       %01000000


;*** FTM1DEADTIME - FTM1 Deadtime Insertion Control Register
FTM1DEADTIME        equ       $0000004B           ;*** FTM1DEADTIME - FTM1 Deadtime Insertion Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1DEADTIME_DTVAL0 equ       0                   ; Deadtime Value Bits, bit 0
FTM1DEADTIME_DTVAL1 equ       1                   ; Deadtime Value Bits, bit 1
FTM1DEADTIME_DTVAL2 equ       2                   ; Deadtime Value Bits, bit 2
FTM1DEADTIME_DTVAL3 equ       3                   ; Deadtime Value Bits, bit 3
FTM1DEADTIME_DTVAL4 equ       4                   ; Deadtime Value Bits, bit 4
FTM1DEADTIME_DTVAL5 equ       5                   ; Deadtime Value Bits, bit 5
FTM1DEADTIME_DTPS0  equ       6                   ; Deadtime Prescaler Value Bits, bit 0
FTM1DEADTIME_DTPS1  equ       7                   ; Deadtime Prescaler Value Bits, bit 1
; bit position masks
mFTM1DEADTIME_DTVAL0 equ       %00000001
mFTM1DEADTIME_DTVAL1 equ       %00000010
mFTM1DEADTIME_DTVAL2 equ       %00000100
mFTM1DEADTIME_DTVAL3 equ       %00001000
mFTM1DEADTIME_DTVAL4 equ       %00010000
mFTM1DEADTIME_DTVAL5 equ       %00100000
mFTM1DEADTIME_DTPS0 equ       %01000000
mFTM1DEADTIME_DTPS1 equ       %10000000


;*** FTM1EXTTRIG - FTM1 ExternalTrigger Register
FTM1EXTTRIG         equ       $0000004C           ;*** FTM1EXTTRIG - FTM1 ExternalTrigger Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1EXTTRIG_INITTRIGEN equ       6                   ; Enables the Generation of a Trigger Signal
; bit position masks
mFTM1EXTTRIG_INITTRIGEN equ       %01000000


;*** FTM1POL - FTM1 Channels Polarity Register
FTM1POL             equ       $0000004D           ;*** FTM1POL - FTM1 Channels Polarity Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1POL_POL0        equ       0                   ; Channel 0 Polarity
FTM1POL_POL1        equ       1                   ; Channel 1 Polarity
; bit position masks
mFTM1POL_POL0       equ       %00000001
mFTM1POL_POL1       equ       %00000010


;*** FTM1FMS - FTM1 Fault Mode Status Register
FTM1FMS             equ       $0000004E           ;*** FTM1FMS - FTM1 Fault Mode Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1FMS_FAULTF0     equ       0                   ; Fault detection flag 0
FTM1FMS_FAULTF1     equ       1                   ; Fault detection flag 1
FTM1FMS_FAULTF2     equ       2                   ; Fault detection flag 2
FTM1FMS_FAULTF3     equ       3                   ; Fault detection flag 3
FTM1FMS_FAULTIN     equ       5                   ; Fault Input
FTM1FMS_WPEN        equ       6                   ; Write Protected Enable
FTM1FMS_FAULTF      equ       7                   ; Fault Detection Flag
; bit position masks
mFTM1FMS_FAULTF0    equ       %00000001
mFTM1FMS_FAULTF1    equ       %00000010
mFTM1FMS_FAULTF2    equ       %00000100
mFTM1FMS_FAULTF3    equ       %00001000
mFTM1FMS_FAULTIN    equ       %00100000
mFTM1FMS_WPEN       equ       %01000000
mFTM1FMS_FAULTF     equ       %10000000


;*** FTM1FILTER0 - FTM1 Input Capture Filter Control Register 0
FTM1FILTER0         equ       $0000004F           ;*** FTM1FILTER0 - FTM1 Input Capture Filter Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1FILTER0_CH0FVAL0 equ       0                   ; Channel 0 Input Filter Bits, bit 0
FTM1FILTER0_CH0FVAL1 equ       1                   ; Channel 0 Input Filter Bits, bit 1
FTM1FILTER0_CH0FVAL2 equ       2                   ; Channel 0 Input Filter Bits, bit 2
FTM1FILTER0_CH0FVAL3 equ       3                   ; Channel 0 Input Filter Bits, bit 3
FTM1FILTER0_CH1FVAL0 equ       4                   ; Channel 1 Input Filter Bits, bit 0
FTM1FILTER0_CH1FVAL1 equ       5                   ; Channel 1 Input Filter Bits, bit 1
FTM1FILTER0_CH1FVAL2 equ       6                   ; Channel 1 Input Filter Bits, bit 2
FTM1FILTER0_CH1FVAL3 equ       7                   ; Channel 1 Input Filter Bits, bit 3
; bit position masks
mFTM1FILTER0_CH0FVAL0 equ       %00000001
mFTM1FILTER0_CH0FVAL1 equ       %00000010
mFTM1FILTER0_CH0FVAL2 equ       %00000100
mFTM1FILTER0_CH0FVAL3 equ       %00001000
mFTM1FILTER0_CH1FVAL0 equ       %00010000
mFTM1FILTER0_CH1FVAL1 equ       %00100000
mFTM1FILTER0_CH1FVAL2 equ       %01000000
mFTM1FILTER0_CH1FVAL3 equ       %10000000


;*** FTM1FLTFILTER - FTM1 Fault Input Filter Control Register
FTM1FLTFILTER       equ       $00000051           ;*** FTM1FLTFILTER - FTM1 Fault Input Filter Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1FLTFILTER_FFVAL0 equ       0                   ; Fault Input Filter Bits, bit 0
FTM1FLTFILTER_FFVAL1 equ       1                   ; Fault Input Filter Bits, bit 1
FTM1FLTFILTER_FFVAL2 equ       2                   ; Fault Input Filter Bits, bit 2
FTM1FLTFILTER_FFVAL3 equ       3                   ; Fault Input Filter Bits, bit 3
; bit position masks
mFTM1FLTFILTER_FFVAL0 equ       %00000001
mFTM1FLTFILTER_FFVAL1 equ       %00000010
mFTM1FLTFILTER_FFVAL2 equ       %00000100
mFTM1FLTFILTER_FFVAL3 equ       %00001000


;*** FTM1FLTCTRL - FTM1 Fault Control Register
FTM1FLTCTRL         equ       $00000052           ;*** FTM1FLTCTRL - FTM1 Fault Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM1FLTCTRL_FAULT0EN equ       0                   ; Fault input 0 enable
FTM1FLTCTRL_FAULT1EN equ       1                   ; Fault input 1 enable
FTM1FLTCTRL_FAULT2EN equ       2                   ; Fault input 2 enable
FTM1FLTCTRL_FAULT3EN equ       3                   ; Fault input 3 enable
FTM1FLTCTRL_FFLTR0EN equ       4                   ; Fault input 0 filter enable
; bit position masks
mFTM1FLTCTRL_FAULT0EN equ       %00000001
mFTM1FLTCTRL_FAULT1EN equ       %00000010
mFTM1FLTCTRL_FAULT2EN equ       %00000100
mFTM1FLTCTRL_FAULT3EN equ       %00001000
mFTM1FLTCTRL_FFLTR0EN equ       %00010000


;*** MTIMSC - MTIM Clock Configuration Register
MTIMSC              equ       $00000054           ;*** MTIMSC - MTIM Clock Configuration Register
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
MTIMCLK             equ       $00000055           ;*** MTIMCLK - MTIM Clock Configuration Register
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
MTIMCNT             equ       $00000056           ;*** MTIMCNT - MTIM Counter Register


;*** MTIMMOD - MTIM Modulo Register
MTIMMOD             equ       $00000057           ;*** MTIMMOD - MTIM Modulo Register


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


;*** IPCSC - IPC Status and Control Register
IPCSC               equ       $0000005E           ;*** IPCSC - IPC Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPCSC_IPM0          equ       0                   ; Interrupt Priority Mask, bit 0
IPCSC_IPM1          equ       1                   ; Interrupt Priority Mask, bit 1
IPCSC_PULIPM        equ       3                   ; Pull IPM from IPMPS
IPCSC_PSF           equ       4                   ; Pseudo Stack Full
IPCSC_PSE           equ       5                   ; Pseudo Stack Empty
IPCSC_IPCE          equ       7                   ; Interrupt Priority Controller Enable
; bit position masks
mIPCSC_IPM0         equ       %00000001
mIPCSC_IPM1         equ       %00000010
mIPCSC_PULIPM       equ       %00001000
mIPCSC_PSF          equ       %00010000
mIPCSC_PSE          equ       %00100000
mIPCSC_IPCE         equ       %10000000


;*** IPMPS - Interrupt Priority Mask Pseudo Stack Register
IPMPS               equ       $0000005F           ;*** IPMPS - Interrupt Priority Mask Pseudo Stack Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPMPS_IPM00         equ       0                   ; Interrupt Priority Mask pseudo stack position 0, bit 0
IPMPS_IPM01         equ       1                   ; Interrupt Priority Mask pseudo stack position 0, bit 1
IPMPS_IPM10         equ       2                   ; Interrupt Priority Mask pseudo stack position 1, bit 0
IPMPS_IPM11         equ       3                   ; Interrupt Priority Mask pseudo stack position 1, bit 1
IPMPS_IPM20         equ       4                   ; Interrupt Priority Mask pseudo stack position 2, bit 0
IPMPS_IPM21         equ       5                   ; Interrupt Priority Mask pseudo stack position 2, bit 1
IPMPS_IPM30         equ       6                   ; Interrupt Priority Mask pseudo stack position 3, bit 0
IPMPS_IPM31         equ       7                   ; Interrupt Priority Mask pseudo stack position 3, bit 1
; bit position masks
mIPMPS_IPM00        equ       %00000001
mIPMPS_IPM01        equ       %00000010
mIPMPS_IPM10        equ       %00000100
mIPMPS_IPM11        equ       %00001000
mIPMPS_IPM20        equ       %00010000
mIPMPS_IPM21        equ       %00100000
mIPMPS_IPM30        equ       %01000000
mIPMPS_IPM31        equ       %10000000


;*** ILRS0 - Interrupt Level Setting Register
ILRS0               equ       $00000060           ;*** ILRS0 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS0_ILR00         equ       0                   ; Interrupt Level Register for Source 0, bit 0
ILRS0_ILR01         equ       1                   ; Interrupt Level Register for Source 0, bit 1
ILRS0_ILR10         equ       2                   ; Interrupt Level Register for Source 1, bit 0
ILRS0_ILR11         equ       3                   ; Interrupt Level Register for Source 1, bit 1
ILRS0_ILR20         equ       4                   ; Interrupt Level Register for Source 2, bit 0
ILRS0_ILR21         equ       5                   ; Interrupt Level Register for Source 2, bit 1
ILRS0_ILR30         equ       6                   ; Interrupt Level Register for Source 3, bit 0
ILRS0_ILR31         equ       7                   ; Interrupt Level Register for Source 3, bit 1
; bit position masks
mILRS0_ILR00        equ       %00000001
mILRS0_ILR01        equ       %00000010
mILRS0_ILR10        equ       %00000100
mILRS0_ILR11        equ       %00001000
mILRS0_ILR20        equ       %00010000
mILRS0_ILR21        equ       %00100000
mILRS0_ILR30        equ       %01000000
mILRS0_ILR31        equ       %10000000


;*** ILRS1 - Interrupt Level Setting Register
ILRS1               equ       $00000061           ;*** ILRS1 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS1_ILR40         equ       0                   ; Interrupt Level Register for Source 4, bit 0
ILRS1_ILR41         equ       1                   ; Interrupt Level Register for Source 4, bit 1
ILRS1_ILR50         equ       2                   ; Interrupt Level Register for Source 5, bit 0
ILRS1_ILR51         equ       3                   ; Interrupt Level Register for Source 5, bit 1
ILRS1_ILR60         equ       4                   ; Interrupt Level Register for Source 6, bit 0
ILRS1_ILR61         equ       5                   ; Interrupt Level Register for Source 6, bit 1
ILRS1_ILR70         equ       6                   ; Interrupt Level Register for Source 7, bit 0
ILRS1_ILR71         equ       7                   ; Interrupt Level Register for Source 7, bit 1
; bit position masks
mILRS1_ILR40        equ       %00000001
mILRS1_ILR41        equ       %00000010
mILRS1_ILR50        equ       %00000100
mILRS1_ILR51        equ       %00001000
mILRS1_ILR60        equ       %00010000
mILRS1_ILR61        equ       %00100000
mILRS1_ILR70        equ       %01000000
mILRS1_ILR71        equ       %10000000


;*** ILRS2 - Interrupt Level Setting Register
ILRS2               equ       $00000062           ;*** ILRS2 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS2_ILR80         equ       0                   ; Interrupt Level Register for Source 8, bit 0
ILRS2_ILR81         equ       1                   ; Interrupt Level Register for Source 8, bit 1
ILRS2_ILR90         equ       2                   ; Interrupt Level Register for Source 9, bit 0
ILRS2_ILR91         equ       3                   ; Interrupt Level Register for Source 9, bit 1
ILRS2_ILR100        equ       4                   ; Interrupt Level Register for Source 10, bit 0
ILRS2_ILR101        equ       5                   ; Interrupt Level Register for Source 10, bit 1
ILRS2_ILR110        equ       6                   ; Interrupt Level Register for Source 11, bit 0
ILRS2_ILR111        equ       7                   ; Interrupt Level Register for Source 11, bit 1
; bit position masks
mILRS2_ILR80        equ       %00000001
mILRS2_ILR81        equ       %00000010
mILRS2_ILR90        equ       %00000100
mILRS2_ILR91        equ       %00001000
mILRS2_ILR100       equ       %00010000
mILRS2_ILR101       equ       %00100000
mILRS2_ILR110       equ       %01000000
mILRS2_ILR111       equ       %10000000


;*** ILRS3 - Interrupt Level Setting Register
ILRS3               equ       $00000063           ;*** ILRS3 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS3_ILR120        equ       0                   ; Interrupt Level Register for Source 12, bit 0
ILRS3_ILR121        equ       1                   ; Interrupt Level Register for Source 12, bit 1
ILRS3_ILR130        equ       2                   ; Interrupt Level Register for Source 13, bit 0
ILRS3_ILR131        equ       3                   ; Interrupt Level Register for Source 13, bit 1
ILRS3_ILR140        equ       4                   ; Interrupt Level Register for Source 14, bit 0
ILRS3_ILR141        equ       5                   ; Interrupt Level Register for Source 14, bit 1
ILRS3_ILR150        equ       6                   ; Interrupt Level Register for Source 15, bit 0
ILRS3_ILR151        equ       7                   ; Interrupt Level Register for Source 15, bit 1
; bit position masks
mILRS3_ILR120       equ       %00000001
mILRS3_ILR121       equ       %00000010
mILRS3_ILR130       equ       %00000100
mILRS3_ILR131       equ       %00001000
mILRS3_ILR140       equ       %00010000
mILRS3_ILR141       equ       %00100000
mILRS3_ILR150       equ       %01000000
mILRS3_ILR151       equ       %10000000


;*** ILRS4 - Interrupt Level Setting Register
ILRS4               equ       $00000064           ;*** ILRS4 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS4_ILR160        equ       0                   ; Interrupt Level Register for Source 16, bit 0
ILRS4_ILR161        equ       1                   ; Interrupt Level Register for Source 16, bit 1
ILRS4_ILR170        equ       2                   ; Interrupt Level Register for Source 17, bit 0
ILRS4_ILR171        equ       3                   ; Interrupt Level Register for Source 17, bit 1
ILRS4_ILR180        equ       4                   ; Interrupt Level Register for Source 18, bit 0
ILRS4_ILR181        equ       5                   ; Interrupt Level Register for Source 18, bit 1
ILRS4_ILR190        equ       6                   ; Interrupt Level Register for Source 19, bit 0
ILRS4_ILR191        equ       7                   ; Interrupt Level Register for Source 19, bit 1
; bit position masks
mILRS4_ILR160       equ       %00000001
mILRS4_ILR161       equ       %00000010
mILRS4_ILR170       equ       %00000100
mILRS4_ILR171       equ       %00001000
mILRS4_ILR180       equ       %00010000
mILRS4_ILR181       equ       %00100000
mILRS4_ILR190       equ       %01000000
mILRS4_ILR191       equ       %10000000


;*** ILRS5 - Interrupt Level Setting Register
ILRS5               equ       $00000065           ;*** ILRS5 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS5_ILR200        equ       0                   ; Interrupt Level Register for Source 20, bit 0
ILRS5_ILR201        equ       1                   ; Interrupt Level Register for Source 20, bit 1
ILRS5_ILR210        equ       2                   ; Interrupt Level Register for Source 21, bit 0
ILRS5_ILR211        equ       3                   ; Interrupt Level Register for Source 21, bit 1
ILRS5_ILR220        equ       4                   ; Interrupt Level Register for Source 22, bit 0
ILRS5_ILR221        equ       5                   ; Interrupt Level Register for Source 22, bit 1
ILRS5_ILR230        equ       6                   ; Interrupt Level Register for Source 23, bit 0
ILRS5_ILR231        equ       7                   ; Interrupt Level Register for Source 23, bit 1
; bit position masks
mILRS5_ILR200       equ       %00000001
mILRS5_ILR201       equ       %00000010
mILRS5_ILR210       equ       %00000100
mILRS5_ILR211       equ       %00001000
mILRS5_ILR220       equ       %00010000
mILRS5_ILR221       equ       %00100000
mILRS5_ILR230       equ       %01000000
mILRS5_ILR231       equ       %10000000


;*** ILRS6 - Interrupt Level Setting Register
ILRS6               equ       $00000066           ;*** ILRS6 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS6_ILR240        equ       0                   ; Interrupt Level Register for Source 24, bit 0
ILRS6_ILR241        equ       1                   ; Interrupt Level Register for Source 24, bit 1
ILRS6_ILR250        equ       2                   ; Interrupt Level Register for Source 25, bit 0
ILRS6_ILR251        equ       3                   ; Interrupt Level Register for Source 25, bit 1
ILRS6_ILR260        equ       4                   ; Interrupt Level Register for Source 26, bit 0
ILRS6_ILR261        equ       5                   ; Interrupt Level Register for Source 26, bit 1
ILRS6_ILR270        equ       6                   ; Interrupt Level Register for Source 27, bit 0
ILRS6_ILR271        equ       7                   ; Interrupt Level Register for Source 27, bit 1
; bit position masks
mILRS6_ILR240       equ       %00000001
mILRS6_ILR241       equ       %00000010
mILRS6_ILR250       equ       %00000100
mILRS6_ILR251       equ       %00001000
mILRS6_ILR260       equ       %00010000
mILRS6_ILR261       equ       %00100000
mILRS6_ILR270       equ       %01000000
mILRS6_ILR271       equ       %10000000


;*** ILRS7 - Interrupt Level Setting Register
ILRS7               equ       $00000067           ;*** ILRS7 - Interrupt Level Setting Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ILRS7_ILR280        equ       0                   ; Interrupt Level Register for Source 28, bit 0
ILRS7_ILR281        equ       1                   ; Interrupt Level Register for Source 28, bit 1
ILRS7_ILR290        equ       2                   ; Interrupt Level Register for Source 29, bit 0
ILRS7_ILR291        equ       3                   ; Interrupt Level Register for Source 29, bit 1
ILRS7_ILR300        equ       4                   ; Interrupt Level Register for Source 30, bit 0
ILRS7_ILR301        equ       5                   ; Interrupt Level Register for Source 30, bit 1
ILRS7_ILR310        equ       6                   ; Interrupt Level Register for Source 31, bit 0
ILRS7_ILR311        equ       7                   ; Interrupt Level Register for Source 31, bit 1
; bit position masks
mILRS7_ILR280       equ       %00000001
mILRS7_ILR281       equ       %00000010
mILRS7_ILR290       equ       %00000100
mILRS7_ILR291       equ       %00001000
mILRS7_ILR300       equ       %00010000
mILRS7_ILR301       equ       %00100000
mILRS7_ILR310       equ       %01000000
mILRS7_ILR311       equ       %10000000


;*** SCIBD - SCI Baud Rate Register
SCIBD               equ       $00000068           ;*** SCIBD - SCI Baud Rate Register


;*** SCIBDH - SCI Baud Rate Register High
SCIBDH              equ       $00000068           ;*** SCIBDH - SCI Baud Rate Register High
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
SCIBDL              equ       $00000069           ;*** SCIBDL - SCI Baud Rate Register Low
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
SCIC1               equ       $0000006A           ;*** SCIC1 - SCI Control Register 1
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
SCIC2               equ       $0000006B           ;*** SCIC2 - SCI Control Register 2
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
SCIS1               equ       $0000006C           ;*** SCIS1 - SCI Status Register 1
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
SCIS2               equ       $0000006D           ;*** SCIS2 - SCI Status Register 2
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
SCIC3               equ       $0000006E           ;*** SCIC3 - SCI Control Register 3
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
SCID                equ       $0000006F           ;*** SCID - SCI Data Register
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


;*** PDB1CTRL1 - PDB1 Control 1 Register
PDB1CTRL1           equ       $00000070           ;*** PDB1CTRL1 - PDB1 Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1CTRL1_LDOK      equ       0                   ; Load OK
PDB1CTRL1_ENA       equ       1                   ; Trigger A Enable
PDB1CTRL1_AOS0      equ       2                   ; Trigger A Output Select, bit 0
PDB1CTRL1_AOS1      equ       3                   ; Trigger A Output Select, bit 1
PDB1CTRL1_ENB       equ       4                   ; Trigger B Enable
PDB1CTRL1_BOS0      equ       5                   ; Trigger B Output Select, bit 0
PDB1CTRL1_BOS1      equ       6                   ; Trigger B Output Select, bit 1
PDB1CTRL1_LDMOD     equ       7                   ; Load mode select
; bit position masks
mPDB1CTRL1_LDOK     equ       %00000001
mPDB1CTRL1_ENA      equ       %00000010
mPDB1CTRL1_AOS0     equ       %00000100
mPDB1CTRL1_AOS1     equ       %00001000
mPDB1CTRL1_ENB      equ       %00010000
mPDB1CTRL1_BOS0     equ       %00100000
mPDB1CTRL1_BOS1     equ       %01000000
mPDB1CTRL1_LDMOD    equ       %10000000


;*** PDB1CTRL2 - PDB1 Control 2 Register
PDB1CTRL2           equ       $00000071           ;*** PDB1CTRL2 - PDB1 Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1CTRL2_SWTRIG    equ       0                   ; Software Trigger
PDB1CTRL2_CONT      equ       1                   ; Continuous Mode Enable
PDB1CTRL2_TRIGSEL0  equ       2                   ; Input Trigger, bit 0
PDB1CTRL2_TRIGSEL1  equ       3                   ; Input Trigger, bit 1
PDB1CTRL2_TRIGSEL2  equ       4                   ; Input Trigger, bit 2
PDB1CTRL2_PRESCALER0 equ       5                   ; Clock Prescaler, bit 0
PDB1CTRL2_PRESCALER1 equ       6                   ; Clock Prescaler, bit 1
PDB1CTRL2_PRESCALER2 equ       7                   ; Clock Prescaler, bit 2
; bit position masks
mPDB1CTRL2_SWTRIG   equ       %00000001
mPDB1CTRL2_CONT     equ       %00000010
mPDB1CTRL2_TRIGSEL0 equ       %00000100
mPDB1CTRL2_TRIGSEL1 equ       %00001000
mPDB1CTRL2_TRIGSEL2 equ       %00010000
mPDB1CTRL2_PRESCALER0 equ       %00100000
mPDB1CTRL2_PRESCALER1 equ       %01000000
mPDB1CTRL2_PRESCALER2 equ       %10000000


;*** PDB1DLYA - PDB1 Delay A Register
PDB1DLYA            equ       $00000072           ;*** PDB1DLYA - PDB1 Delay A Register


;*** PDB1DLYAH - PDB1 Delay A High Register
PDB1DLYAH           equ       $00000072           ;*** PDB1DLYAH - PDB1 Delay A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1DLYAH_DELAYA8   equ       0                   ; Delay A, bit 8
PDB1DLYAH_DELAYA9   equ       1                   ; Delay A, bit 9
PDB1DLYAH_DELAYA10  equ       2                   ; Delay A, bit 10
PDB1DLYAH_DELAYA11  equ       3                   ; Delay A, bit 11
PDB1DLYAH_DELAYA12  equ       4                   ; Delay A, bit 12
PDB1DLYAH_DELAYA13  equ       5                   ; Delay A, bit 13
PDB1DLYAH_DELAYA14  equ       6                   ; Delay A, bit 14
PDB1DLYAH_DELAYA15  equ       7                   ; Delay A, bit 15
; bit position masks
mPDB1DLYAH_DELAYA8  equ       %00000001
mPDB1DLYAH_DELAYA9  equ       %00000010
mPDB1DLYAH_DELAYA10 equ       %00000100
mPDB1DLYAH_DELAYA11 equ       %00001000
mPDB1DLYAH_DELAYA12 equ       %00010000
mPDB1DLYAH_DELAYA13 equ       %00100000
mPDB1DLYAH_DELAYA14 equ       %01000000
mPDB1DLYAH_DELAYA15 equ       %10000000


;*** PDB1DLYAL - PDB1 Delay A Low Register
PDB1DLYAL           equ       $00000073           ;*** PDB1DLYAL - PDB1 Delay A Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1DLYAL_DELAYA0   equ       0                   ; Delay A, bit 0
PDB1DLYAL_DELAYA1   equ       1                   ; Delay A, bit 1
PDB1DLYAL_DELAYA2   equ       2                   ; Delay A, bit 2
PDB1DLYAL_DELAYA3   equ       3                   ; Delay A, bit 3
PDB1DLYAL_DELAYA4   equ       4                   ; Delay A, bit 4
PDB1DLYAL_DELAYA5   equ       5                   ; Delay A, bit 5
PDB1DLYAL_DELAYA6   equ       6                   ; Delay A, bit 6
PDB1DLYAL_DELAYA7   equ       7                   ; Delay A, bit 7
; bit position masks
mPDB1DLYAL_DELAYA0  equ       %00000001
mPDB1DLYAL_DELAYA1  equ       %00000010
mPDB1DLYAL_DELAYA2  equ       %00000100
mPDB1DLYAL_DELAYA3  equ       %00001000
mPDB1DLYAL_DELAYA4  equ       %00010000
mPDB1DLYAL_DELAYA5  equ       %00100000
mPDB1DLYAL_DELAYA6  equ       %01000000
mPDB1DLYAL_DELAYA7  equ       %10000000


;*** PDB1DLYB - PDB1 Delay B Register
PDB1DLYB            equ       $00000074           ;*** PDB1DLYB - PDB1 Delay B Register


;*** PDB1DLYBH - PDB1 Delay B High Register
PDB1DLYBH           equ       $00000074           ;*** PDB1DLYBH - PDB1 Delay B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1DLYBH_DELAYB8   equ       0                   ; Delay B, bit 8
PDB1DLYBH_DELAYB9   equ       1                   ; Delay B, bit 9
PDB1DLYBH_DELAYB10  equ       2                   ; Delay B, bit 10
PDB1DLYBH_DELAYB11  equ       3                   ; Delay B, bit 11
PDB1DLYBH_DELAYB12  equ       4                   ; Delay B, bit 12
PDB1DLYBH_DELAYB13  equ       5                   ; Delay B, bit 13
PDB1DLYBH_DELAYB14  equ       6                   ; Delay B, bit 14
PDB1DLYBH_DELAYB15  equ       7                   ; Delay B, bit 15
; bit position masks
mPDB1DLYBH_DELAYB8  equ       %00000001
mPDB1DLYBH_DELAYB9  equ       %00000010
mPDB1DLYBH_DELAYB10 equ       %00000100
mPDB1DLYBH_DELAYB11 equ       %00001000
mPDB1DLYBH_DELAYB12 equ       %00010000
mPDB1DLYBH_DELAYB13 equ       %00100000
mPDB1DLYBH_DELAYB14 equ       %01000000
mPDB1DLYBH_DELAYB15 equ       %10000000


;*** PDB1DLYBL - PDB1 Delay B Low Register
PDB1DLYBL           equ       $00000075           ;*** PDB1DLYBL - PDB1 Delay B Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1DLYBL_DELAYB0   equ       0                   ; Delay B, bit 0
PDB1DLYBL_DELAYB1   equ       1                   ; Delay B, bit 1
PDB1DLYBL_DELAYB2   equ       2                   ; Delay B, bit 2
PDB1DLYBL_DELAYB3   equ       3                   ; Delay B, bit 3
PDB1DLYBL_DELAYB4   equ       4                   ; Delay B, bit 4
PDB1DLYBL_DELAYB5   equ       5                   ; Delay B, bit 5
PDB1DLYBL_DELAYB6   equ       6                   ; Delay B, bit 6
PDB1DLYBL_DELAYB7   equ       7                   ; Delay B, bit 7
; bit position masks
mPDB1DLYBL_DELAYB0  equ       %00000001
mPDB1DLYBL_DELAYB1  equ       %00000010
mPDB1DLYBL_DELAYB2  equ       %00000100
mPDB1DLYBL_DELAYB3  equ       %00001000
mPDB1DLYBL_DELAYB4  equ       %00010000
mPDB1DLYBL_DELAYB5  equ       %00100000
mPDB1DLYBL_DELAYB6  equ       %01000000
mPDB1DLYBL_DELAYB7  equ       %10000000


;*** PDB1MOD - PDB1 Counter Modulus Register
PDB1MOD             equ       $00000076           ;*** PDB1MOD - PDB1 Counter Modulus Register


;*** PDB1MODH - PDB1 Counter Modulus High Register
PDB1MODH            equ       $00000076           ;*** PDB1MODH - PDB1 Counter Modulus High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1MODH_MOD8       equ       0                   ; Counter Modulus, bit 8
PDB1MODH_MOD9       equ       1                   ; Counter Modulus, bit 9
PDB1MODH_MOD10      equ       2                   ; Counter Modulus, bit 10
PDB1MODH_MOD11      equ       3                   ; Counter Modulus, bit 11
PDB1MODH_MOD12      equ       4                   ; Counter Modulus, bit 12
PDB1MODH_MOD13      equ       5                   ; Counter Modulus, bit 13
PDB1MODH_MOD14      equ       6                   ; Counter Modulus, bit 14
PDB1MODH_MOD15      equ       7                   ; Counter Modulus, bit 15
; bit position masks
mPDB1MODH_MOD8      equ       %00000001
mPDB1MODH_MOD9      equ       %00000010
mPDB1MODH_MOD10     equ       %00000100
mPDB1MODH_MOD11     equ       %00001000
mPDB1MODH_MOD12     equ       %00010000
mPDB1MODH_MOD13     equ       %00100000
mPDB1MODH_MOD14     equ       %01000000
mPDB1MODH_MOD15     equ       %10000000


;*** PDB1MODL - PDB1 Counter Modulus Low Register
PDB1MODL            equ       $00000077           ;*** PDB1MODL - PDB1 Counter Modulus Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1MODL_MOD0       equ       0                   ; Counter Modulus, bit 0
PDB1MODL_MOD1       equ       1                   ; Counter Modulus, bit 1
PDB1MODL_MOD2       equ       2                   ; Counter Modulus, bit 2
PDB1MODL_MOD3       equ       3                   ; Counter Modulus, bit 3
PDB1MODL_MOD4       equ       4                   ; Counter Modulus, bit 4
PDB1MODL_MOD5       equ       5                   ; Counter Modulus, bit 5
PDB1MODL_MOD6       equ       6                   ; Counter Modulus, bit 6
PDB1MODL_MOD7       equ       7                   ; Counter Modulus, bit 7
; bit position masks
mPDB1MODL_MOD0      equ       %00000001
mPDB1MODL_MOD1      equ       %00000010
mPDB1MODL_MOD2      equ       %00000100
mPDB1MODL_MOD3      equ       %00001000
mPDB1MODL_MOD4      equ       %00010000
mPDB1MODL_MOD5      equ       %00100000
mPDB1MODL_MOD6      equ       %01000000
mPDB1MODL_MOD7      equ       %10000000


;*** PDB1CNT - PDB1 Counter Value Register
PDB1CNT             equ       $00000078           ;*** PDB1CNT - PDB1 Counter Value Register


;*** PDB1CNTH - PDB1 Counter Value High Register
PDB1CNTH            equ       $00000078           ;*** PDB1CNTH - PDB1 Counter Value High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1CNTH_COUNT8     equ       0                   ; Counter Value, bit 8
PDB1CNTH_COUNT9     equ       1                   ; Counter Value, bit 9
PDB1CNTH_COUNT10    equ       2                   ; Counter Value, bit 10
PDB1CNTH_COUNT11    equ       3                   ; Counter Value, bit 11
PDB1CNTH_COUNT12    equ       4                   ; Counter Value, bit 12
PDB1CNTH_COUNT13    equ       5                   ; Counter Value, bit 13
PDB1CNTH_COUNT14    equ       6                   ; Counter Value, bit 14
PDB1CNTH_COUNT15    equ       7                   ; Counter Value, bit 15
; bit position masks
mPDB1CNTH_COUNT8    equ       %00000001
mPDB1CNTH_COUNT9    equ       %00000010
mPDB1CNTH_COUNT10   equ       %00000100
mPDB1CNTH_COUNT11   equ       %00001000
mPDB1CNTH_COUNT12   equ       %00010000
mPDB1CNTH_COUNT13   equ       %00100000
mPDB1CNTH_COUNT14   equ       %01000000
mPDB1CNTH_COUNT15   equ       %10000000


;*** PDB1CNTL - PDB1 Counter Value Low Register
PDB1CNTL            equ       $00000079           ;*** PDB1CNTL - PDB1 Counter Value Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1CNTL_COUNT0     equ       0                   ; Counter Value, bit 0
PDB1CNTL_COUNT1     equ       1                   ; Counter Value, bit 1
PDB1CNTL_COUNT2     equ       2                   ; Counter Value, bit 2
PDB1CNTL_COUNT3     equ       3                   ; Counter Value, bit 3
PDB1CNTL_COUNT4     equ       4                   ; Counter Value, bit 4
PDB1CNTL_COUNT5     equ       5                   ; Counter Value, bit 5
PDB1CNTL_COUNT6     equ       6                   ; Counter Value, bit 6
PDB1CNTL_COUNT7     equ       7                   ; Counter Value, bit 7
; bit position masks
mPDB1CNTL_COUNT0    equ       %00000001
mPDB1CNTL_COUNT1    equ       %00000010
mPDB1CNTL_COUNT2    equ       %00000100
mPDB1CNTL_COUNT3    equ       %00001000
mPDB1CNTL_COUNT4    equ       %00010000
mPDB1CNTL_COUNT5    equ       %00100000
mPDB1CNTL_COUNT6    equ       %01000000
mPDB1CNTL_COUNT7    equ       %10000000


;*** PDB1SCR - PDB1 Status Register
PDB1SCR             equ       $0000007A           ;*** PDB1SCR - PDB1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB1SCR_DAIE        equ       0                   ; Delay A successful compare interrupt request enable
PDB1SCR_DAF         equ       1                   ; Delay A flag
PDB1SCR_DBIE        equ       2                   ; Delay B successful compare interrupt request enable
PDB1SCR_DBF         equ       3                   ; Delay B flag
PDB1SCR_COIE        equ       4                   ; Counter overflow interrupt request enable
PDB1SCR_COF         equ       5                   ; Counter overflow flag
PDB1SCR_PDBEN       equ       6                   ; PDB module enable
PDB1SCR_PADEN       equ       7                   ; Pulse output PAD enable
; bit position masks
mPDB1SCR_DAIE       equ       %00000001
mPDB1SCR_DAF        equ       %00000010
mPDB1SCR_DBIE       equ       %00000100
mPDB1SCR_DBF        equ       %00001000
mPDB1SCR_COIE       equ       %00010000
mPDB1SCR_COF        equ       %00100000
mPDB1SCR_PDBEN      equ       %01000000
mPDB1SCR_PADEN      equ       %10000000


;*** CRCH - CRC High Register
CRCH                equ       $0000007C           ;*** CRCH - CRC High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRCH_BIT8           equ       0                   ; High byte of CRC register ,bit 8
CRCH_BIT9           equ       1                   ; High byte of CRC register ,bit 9
CRCH_BIT10          equ       2                   ; High byte of CRC register ,bit 10
CRCH_BIT11          equ       3                   ; High byte of CRC register ,bit 11
CRCH_BIT12          equ       4                   ; High byte of CRC register ,bit 12
CRCH_BIT13          equ       5                   ; High byte of CRC register ,bit 13
CRCH_BIT14          equ       6                   ; High byte of CRC register ,bit 14
CRCH_BIT15          equ       7                   ; High byte of CRC register ,bit 15
; bit position masks
mCRCH_BIT8          equ       %00000001
mCRCH_BIT9          equ       %00000010
mCRCH_BIT10         equ       %00000100
mCRCH_BIT11         equ       %00001000
mCRCH_BIT12         equ       %00010000
mCRCH_BIT13         equ       %00100000
mCRCH_BIT14         equ       %01000000
mCRCH_BIT15         equ       %10000000


;*** CRCL - CRC Low Register
CRCL                equ       $0000007D           ;*** CRCL - CRC Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRCL_BIT0           equ       0                   ; Low byte of CRC register, bit 0
CRCL_BIT1           equ       1                   ; Low byte of CRC register, bit 1
CRCL_BIT2           equ       2                   ; Low byte of CRC register, bit 2
CRCL_BIT3           equ       3                   ; Low byte of CRC register, bit 3
CRCL_BIT4           equ       4                   ; Low byte of CRC register, bit 4
CRCL_BIT5           equ       5                   ; Low byte of CRC register, bit 5
CRCL_BIT6           equ       6                   ; Low byte of CRC register, bit 6
CRCL_BIT7           equ       7                   ; Low byte of CRC register, bit 7
; bit position masks
mCRCL_BIT0          equ       %00000001
mCRCL_BIT1          equ       %00000010
mCRCL_BIT2          equ       %00000100
mCRCL_BIT3          equ       %00001000
mCRCL_BIT4          equ       %00010000
mCRCL_BIT5          equ       %00100000
mCRCL_BIT6          equ       %01000000
mCRCL_BIT7          equ       %10000000


;*** TRANSPOSE - CRC Transpose Register
TRANSPOSE           equ       $0000007E           ;*** TRANSPOSE - CRC Transpose Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TRANSPOSE_BIT0      equ       0                   ; CRC transpose register, bit 0
TRANSPOSE_BIT1      equ       1                   ; CRC transpose register, bit 1
TRANSPOSE_BIT2      equ       2                   ; CRC transpose register, bit 2
TRANSPOSE_BIT3      equ       3                   ; CRC transpose register, bit 3
TRANSPOSE_BIT4      equ       4                   ; CRC transpose register, bit 4
TRANSPOSE_BIT5      equ       5                   ; CRC transpose register, bit 5
TRANSPOSE_BIT6      equ       6                   ; CRC transpose register, bit 6
TRANSPOSE_BIT7      equ       7                   ; CRC transpose register, bit 7
; bit position masks
mTRANSPOSE_BIT0     equ       %00000001
mTRANSPOSE_BIT1     equ       %00000010
mTRANSPOSE_BIT2     equ       %00000100
mTRANSPOSE_BIT3     equ       %00001000
mTRANSPOSE_BIT4     equ       %00010000
mTRANSPOSE_BIT5     equ       %00100000
mTRANSPOSE_BIT6     equ       %01000000
mTRANSPOSE_BIT7     equ       %10000000


;*** PDB2CTRL1 - PDB2 Control 1 Register
PDB2CTRL1           equ       $00000080           ;*** PDB2CTRL1 - PDB2 Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2CTRL1_LDOK      equ       0                   ; Load OK
PDB2CTRL1_LDMOD     equ       7                   ; Load mode select
; bit position masks
mPDB2CTRL1_LDOK     equ       %00000001
mPDB2CTRL1_LDMOD    equ       %10000000


;*** PDB2CTRL2 - PDB2 Control 2 Register
PDB2CTRL2           equ       $00000081           ;*** PDB2CTRL2 - PDB2 Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2CTRL2_SWTRIG    equ       0                   ; Software Trigger
PDB2CTRL2_CONT      equ       1                   ; Continuous Mode Enable
PDB2CTRL2_TRIGSEL0  equ       2                   ; Input Trigger, bit 0
PDB2CTRL2_TRIGSEL1  equ       3                   ; Input Trigger, bit 1
PDB2CTRL2_TRIGSEL2  equ       4                   ; Input Trigger, bit 2
PDB2CTRL2_PRESCALER0 equ       5                   ; Clock Prescaler, bit 0
PDB2CTRL2_PRESCALER1 equ       6                   ; Clock Prescaler, bit 1
PDB2CTRL2_PRESCALER2 equ       7                   ; Clock Prescaler, bit 2
; bit position masks
mPDB2CTRL2_SWTRIG   equ       %00000001
mPDB2CTRL2_CONT     equ       %00000010
mPDB2CTRL2_TRIGSEL0 equ       %00000100
mPDB2CTRL2_TRIGSEL1 equ       %00001000
mPDB2CTRL2_TRIGSEL2 equ       %00010000
mPDB2CTRL2_PRESCALER0 equ       %00100000
mPDB2CTRL2_PRESCALER1 equ       %01000000
mPDB2CTRL2_PRESCALER2 equ       %10000000


;*** PDB2DLYA - PDB2 Delay A Register
PDB2DLYA            equ       $00000082           ;*** PDB2DLYA - PDB2 Delay A Register


;*** PDB2DLYAH - PDB2 Delay A High Register
PDB2DLYAH           equ       $00000082           ;*** PDB2DLYAH - PDB2 Delay A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2DLYAH_DELAYA8   equ       0                   ; Delay A, bit 8
PDB2DLYAH_DELAYA9   equ       1                   ; Delay A, bit 9
PDB2DLYAH_DELAYA10  equ       2                   ; Delay A, bit 10
PDB2DLYAH_DELAYA11  equ       3                   ; Delay A, bit 11
PDB2DLYAH_DELAYA12  equ       4                   ; Delay A, bit 12
PDB2DLYAH_DELAYA13  equ       5                   ; Delay A, bit 13
PDB2DLYAH_DELAYA14  equ       6                   ; Delay A, bit 14
PDB2DLYAH_DELAYA15  equ       7                   ; Delay A, bit 15
; bit position masks
mPDB2DLYAH_DELAYA8  equ       %00000001
mPDB2DLYAH_DELAYA9  equ       %00000010
mPDB2DLYAH_DELAYA10 equ       %00000100
mPDB2DLYAH_DELAYA11 equ       %00001000
mPDB2DLYAH_DELAYA12 equ       %00010000
mPDB2DLYAH_DELAYA13 equ       %00100000
mPDB2DLYAH_DELAYA14 equ       %01000000
mPDB2DLYAH_DELAYA15 equ       %10000000


;*** PDB2DLYAL - PDB2 Delay A Low Register
PDB2DLYAL           equ       $00000083           ;*** PDB2DLYAL - PDB2 Delay A Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2DLYAL_DELAYA0   equ       0                   ; Delay A, bit 0
PDB2DLYAL_DELAYA1   equ       1                   ; Delay A, bit 1
PDB2DLYAL_DELAYA2   equ       2                   ; Delay A, bit 2
PDB2DLYAL_DELAYA3   equ       3                   ; Delay A, bit 3
PDB2DLYAL_DELAYA4   equ       4                   ; Delay A, bit 4
PDB2DLYAL_DELAYA5   equ       5                   ; Delay A, bit 5
PDB2DLYAL_DELAYA6   equ       6                   ; Delay A, bit 6
PDB2DLYAL_DELAYA7   equ       7                   ; Delay A, bit 7
; bit position masks
mPDB2DLYAL_DELAYA0  equ       %00000001
mPDB2DLYAL_DELAYA1  equ       %00000010
mPDB2DLYAL_DELAYA2  equ       %00000100
mPDB2DLYAL_DELAYA3  equ       %00001000
mPDB2DLYAL_DELAYA4  equ       %00010000
mPDB2DLYAL_DELAYA5  equ       %00100000
mPDB2DLYAL_DELAYA6  equ       %01000000
mPDB2DLYAL_DELAYA7  equ       %10000000


;*** PDB2DLYB - PDB2 Delay B Register
PDB2DLYB            equ       $00000084           ;*** PDB2DLYB - PDB2 Delay B Register


;*** PDB2DLYBH - PDB2 Delay B High Register
PDB2DLYBH           equ       $00000084           ;*** PDB2DLYBH - PDB2 Delay B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2DLYBH_DELAYB8   equ       0                   ; Delay B, bit 8
PDB2DLYBH_DELAYB9   equ       1                   ; Delay B, bit 9
PDB2DLYBH_DELAYB10  equ       2                   ; Delay B, bit 10
PDB2DLYBH_DELAYB11  equ       3                   ; Delay B, bit 11
PDB2DLYBH_DELAYB12  equ       4                   ; Delay B, bit 12
PDB2DLYBH_DELAYB13  equ       5                   ; Delay B, bit 13
PDB2DLYBH_DELAYB14  equ       6                   ; Delay B, bit 14
PDB2DLYBH_DELAYB15  equ       7                   ; Delay B, bit 15
; bit position masks
mPDB2DLYBH_DELAYB8  equ       %00000001
mPDB2DLYBH_DELAYB9  equ       %00000010
mPDB2DLYBH_DELAYB10 equ       %00000100
mPDB2DLYBH_DELAYB11 equ       %00001000
mPDB2DLYBH_DELAYB12 equ       %00010000
mPDB2DLYBH_DELAYB13 equ       %00100000
mPDB2DLYBH_DELAYB14 equ       %01000000
mPDB2DLYBH_DELAYB15 equ       %10000000


;*** PDB2DLYBL - PDB2 Delay B Low Register
PDB2DLYBL           equ       $00000085           ;*** PDB2DLYBL - PDB2 Delay B Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2DLYBL_DELAYB0   equ       0                   ; Delay B, bit 0
PDB2DLYBL_DELAYB1   equ       1                   ; Delay B, bit 1
PDB2DLYBL_DELAYB2   equ       2                   ; Delay B, bit 2
PDB2DLYBL_DELAYB3   equ       3                   ; Delay B, bit 3
PDB2DLYBL_DELAYB4   equ       4                   ; Delay B, bit 4
PDB2DLYBL_DELAYB5   equ       5                   ; Delay B, bit 5
PDB2DLYBL_DELAYB6   equ       6                   ; Delay B, bit 6
PDB2DLYBL_DELAYB7   equ       7                   ; Delay B, bit 7
; bit position masks
mPDB2DLYBL_DELAYB0  equ       %00000001
mPDB2DLYBL_DELAYB1  equ       %00000010
mPDB2DLYBL_DELAYB2  equ       %00000100
mPDB2DLYBL_DELAYB3  equ       %00001000
mPDB2DLYBL_DELAYB4  equ       %00010000
mPDB2DLYBL_DELAYB5  equ       %00100000
mPDB2DLYBL_DELAYB6  equ       %01000000
mPDB2DLYBL_DELAYB7  equ       %10000000


;*** PDB2MOD - PDB2 Counter Modulus Register
PDB2MOD             equ       $00000086           ;*** PDB2MOD - PDB2 Counter Modulus Register


;*** PDB2MODH - PDB2 Counter Modulus High Register
PDB2MODH            equ       $00000086           ;*** PDB2MODH - PDB2 Counter Modulus High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2MODH_MOD8       equ       0                   ; Counter Modulus, bit 8
PDB2MODH_MOD9       equ       1                   ; Counter Modulus, bit 9
PDB2MODH_MOD10      equ       2                   ; Counter Modulus, bit 10
PDB2MODH_MOD11      equ       3                   ; Counter Modulus, bit 11
PDB2MODH_MOD12      equ       4                   ; Counter Modulus, bit 12
PDB2MODH_MOD13      equ       5                   ; Counter Modulus, bit 13
PDB2MODH_MOD14      equ       6                   ; Counter Modulus, bit 14
PDB2MODH_MOD15      equ       7                   ; Counter Modulus, bit 15
; bit position masks
mPDB2MODH_MOD8      equ       %00000001
mPDB2MODH_MOD9      equ       %00000010
mPDB2MODH_MOD10     equ       %00000100
mPDB2MODH_MOD11     equ       %00001000
mPDB2MODH_MOD12     equ       %00010000
mPDB2MODH_MOD13     equ       %00100000
mPDB2MODH_MOD14     equ       %01000000
mPDB2MODH_MOD15     equ       %10000000


;*** PDB2MODL - PDB2 Counter Modulus Low Register
PDB2MODL            equ       $00000087           ;*** PDB2MODL - PDB2 Counter Modulus Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2MODL_MOD0       equ       0                   ; Counter Modulus, bit 0
PDB2MODL_MOD1       equ       1                   ; Counter Modulus, bit 1
PDB2MODL_MOD2       equ       2                   ; Counter Modulus, bit 2
PDB2MODL_MOD3       equ       3                   ; Counter Modulus, bit 3
PDB2MODL_MOD4       equ       4                   ; Counter Modulus, bit 4
PDB2MODL_MOD5       equ       5                   ; Counter Modulus, bit 5
PDB2MODL_MOD6       equ       6                   ; Counter Modulus, bit 6
PDB2MODL_MOD7       equ       7                   ; Counter Modulus, bit 7
; bit position masks
mPDB2MODL_MOD0      equ       %00000001
mPDB2MODL_MOD1      equ       %00000010
mPDB2MODL_MOD2      equ       %00000100
mPDB2MODL_MOD3      equ       %00001000
mPDB2MODL_MOD4      equ       %00010000
mPDB2MODL_MOD5      equ       %00100000
mPDB2MODL_MOD6      equ       %01000000
mPDB2MODL_MOD7      equ       %10000000


;*** PDB2CNT - PDB2 Counter Value Register
PDB2CNT             equ       $00000088           ;*** PDB2CNT - PDB2 Counter Value Register


;*** PDB2CNTH - PDB2 Counter Value High Register
PDB2CNTH            equ       $00000088           ;*** PDB2CNTH - PDB2 Counter Value High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2CNTH_COUNT8     equ       0                   ; Counter Value, bit 8
PDB2CNTH_COUNT9     equ       1                   ; Counter Value, bit 9
PDB2CNTH_COUNT10    equ       2                   ; Counter Value, bit 10
PDB2CNTH_COUNT11    equ       3                   ; Counter Value, bit 11
PDB2CNTH_COUNT12    equ       4                   ; Counter Value, bit 12
PDB2CNTH_COUNT13    equ       5                   ; Counter Value, bit 13
PDB2CNTH_COUNT14    equ       6                   ; Counter Value, bit 14
PDB2CNTH_COUNT15    equ       7                   ; Counter Value, bit 15
; bit position masks
mPDB2CNTH_COUNT8    equ       %00000001
mPDB2CNTH_COUNT9    equ       %00000010
mPDB2CNTH_COUNT10   equ       %00000100
mPDB2CNTH_COUNT11   equ       %00001000
mPDB2CNTH_COUNT12   equ       %00010000
mPDB2CNTH_COUNT13   equ       %00100000
mPDB2CNTH_COUNT14   equ       %01000000
mPDB2CNTH_COUNT15   equ       %10000000


;*** PDB2CNTL - PDB2 Counter Value Low Register
PDB2CNTL            equ       $00000089           ;*** PDB2CNTL - PDB2 Counter Value Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2CNTL_COUNT0     equ       0                   ; Counter Value, bit 0
PDB2CNTL_COUNT1     equ       1                   ; Counter Value, bit 1
PDB2CNTL_COUNT2     equ       2                   ; Counter Value, bit 2
PDB2CNTL_COUNT3     equ       3                   ; Counter Value, bit 3
PDB2CNTL_COUNT4     equ       4                   ; Counter Value, bit 4
PDB2CNTL_COUNT5     equ       5                   ; Counter Value, bit 5
PDB2CNTL_COUNT6     equ       6                   ; Counter Value, bit 6
PDB2CNTL_COUNT7     equ       7                   ; Counter Value, bit 7
; bit position masks
mPDB2CNTL_COUNT0    equ       %00000001
mPDB2CNTL_COUNT1    equ       %00000010
mPDB2CNTL_COUNT2    equ       %00000100
mPDB2CNTL_COUNT3    equ       %00001000
mPDB2CNTL_COUNT4    equ       %00010000
mPDB2CNTL_COUNT5    equ       %00100000
mPDB2CNTL_COUNT6    equ       %01000000
mPDB2CNTL_COUNT7    equ       %10000000


;*** PDB2SCR - PDB2 Status Register
PDB2SCR             equ       $0000008A           ;*** PDB2SCR - PDB2 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB2SCR_DAIE        equ       0                   ; Delay A successful compare interrupt request enable
PDB2SCR_DAF         equ       1                   ; Delay A flag
PDB2SCR_DBIE        equ       2                   ; Delay B successful compare interrupt request enable
PDB2SCR_DBF         equ       3                   ; Delay B flag
PDB2SCR_COIE        equ       4                   ; Counter overflow interrupt request enable
PDB2SCR_COF         equ       5                   ; Counter overflow flag
PDB2SCR_PDBEN       equ       6                   ; PDB module enable
PDB2SCR_PADEN       equ       7                   ; Pulse output PAD enable
; bit position masks
mPDB2SCR_DAIE       equ       %00000001
mPDB2SCR_DAF        equ       %00000010
mPDB2SCR_DBIE       equ       %00000100
mPDB2SCR_DBF        equ       %00001000
mPDB2SCR_COIE       equ       %00010000
mPDB2SCR_COF        equ       %00100000
mPDB2SCR_PDBEN      equ       %01000000
mPDB2SCR_PADEN      equ       %10000000


;*** RTCSC - RTC Status and Control Register
RTCSC               equ       $0000008C           ;*** RTCSC - RTC Status and Control Register
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
RTCCNT              equ       $0000008D           ;*** RTCCNT - RTC Counter Register


;*** RTCMOD - RTC Modulo Register
RTCMOD              equ       $0000008E           ;*** RTCMOD - RTC Modulo Register


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
SOPT1_ACIC1         equ       2                   ; Analog Comparator to Input Capture Enable
SOPT1_ACIC2         equ       3                   ; Analog Comparator to Input Capture Enable
SOPT1_SPIFE         equ       4                   ; SPI Ports Filter Enable
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT0         equ       6                   ; COP Watchdog Timeout, bit 0
SOPT1_COPT1         equ       7                   ; COP Watchdog Timeout, bit 1
; bit position masks
mSOPT1_RSTPE        equ       %00000001
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_ACIC1        equ       %00000100
mSOPT1_ACIC2        equ       %00001000
mSOPT1_SPIFE        equ       %00010000
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT0        equ       %01000000
mSOPT1_COPT1        equ       %10000000


;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_CMP2OPS       equ       0                   ; CMP2OUT Pin Select
SOPT2_CMP3OPS       equ       1                   ; CMP3OUT Pin Select
SOPT2_TCLKPS        equ       2                   ; TCLK Pin Select
SOPT2_IICPS0        equ       3                   ; IIC Pin Select, bit 0
SOPT2_IICPS1        equ       4                   ; IIC Pin Select, bit 1
SOPT2_FTM2T2S       equ       5                   ; Flextimer 2 Trigger 2 Input Select
SOPT2_COPW          equ       6                   ; COP Window
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_CMP2OPS      equ       %00000001
mSOPT2_CMP3OPS      equ       %00000010
mSOPT2_TCLKPS       equ       %00000100
mSOPT2_IICPS0       equ       %00001000
mSOPT2_IICPS1       equ       %00010000
mSOPT2_FTM2T2S      equ       %00100000
mSOPT2_COPW         equ       %01000000
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


;*** SOPT3 - System Options Register 3
SOPT3               equ       $0000180B           ;*** SOPT3 - System Options Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT3_SYNCFTM       equ       0                   ; Synchronize FTM
; bit position masks
mSOPT3_SYNCFTM      equ       %00000001


;*** SCGC1 - System Clock Gating Control 1 Register
SCGC1               equ       $0000180E           ;*** SCGC1 - System Clock Gating Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_CMPDAC1       equ       0                   ; HSCMP1 and DAC1 Clock Gate Control
SCGC1_CMPDAC2       equ       1                   ; HSCMP2 and DAC2 Clock Gate Control
SCGC1_CMPDAC3       equ       2                   ; HSCMP3 and DAC3 Clock Gate Control
SCGC1_PDB           equ       3                   ; PDB1 and PDB2 Clock Gate Control
SCGC1_RTC           equ       4                   ; RTC Clock Gate Control
SCGC1_MTIM          equ       5                   ; MTIM Clock Gate Control
SCGC1_FTM1          equ       6                   ; FTM1 Clock Gate Control
SCGC1_FTM2          equ       7                   ; FTM2 Clock Gate Control
; bit position masks
mSCGC1_CMPDAC1      equ       %00000001
mSCGC1_CMPDAC2      equ       %00000010
mSCGC1_CMPDAC3      equ       %00000100
mSCGC1_PDB          equ       %00001000
mSCGC1_RTC          equ       %00010000
mSCGC1_MTIM         equ       %00100000
mSCGC1_FTM1         equ       %01000000
mSCGC1_FTM2         equ       %10000000


;*** SCGC2 - System Clock Gating Control 2 Register
SCGC2               equ       $0000180F           ;*** SCGC2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_PGA           equ       0                   ; PGA Clock Gate Control
SCGC2_IIC           equ       1                   ; IIC Clock Gate Control
SCGC2_SPI           equ       2                   ; SPI Clock Gate Control
SCGC2_SCI           equ       3                   ; SCI Clock Gate Control
SCGC2_ADC           equ       4                   ; ADC Clock Gate Control
SCGC2_KBI           equ       5                   ; KBI1, KBI2, and KBI3 Clock Gate Control
SCGC2_FLS           equ       6                   ; Flash Clock Gate Control
SCGC2_DBG           equ       7                   ; DBG Clock Gate Control
; bit position masks
mSCGC2_PGA          equ       %00000001
mSCGC2_IIC          equ       %00000010
mSCGC2_SPI          equ       %00000100
mSCGC2_SCI          equ       %00001000
mSCGC2_ADC          equ       %00010000
mSCGC2_KBI          equ       %00100000
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
PTCPE_PTCPE7        equ       7                   ; Internal Pull Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000
mPTCPE_PTCPE6       equ       %01000000
mPTCPE_PTCPE7       equ       %10000000


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
PTCSE_PTCSE7        equ       7                   ; Output Slew Rate Enable for Port C Bit 7
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010
mPTCSE_PTCSE2       equ       %00000100
mPTCSE_PTCSE3       equ       %00001000
mPTCSE_PTCSE4       equ       %00010000
mPTCSE_PTCSE5       equ       %00100000
mPTCSE_PTCSE6       equ       %01000000
mPTCSE_PTCSE7       equ       %10000000


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
PTCDS_PTCDS7        equ       7                   ; Output Drive Strength Selection for Port C Bit 7
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010
mPTCDS_PTCDS2       equ       %00000100
mPTCDS_PTCDS3       equ       %00001000
mPTCDS_PTCDS4       equ       %00010000
mPTCDS_PTCDS5       equ       %00100000
mPTCDS_PTCDS6       equ       %01000000
mPTCDS_PTCDS7       equ       %10000000


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
; bit position masks
mPTEPE_PTEPE0       equ       %00000001
mPTEPE_PTEPE1       equ       %00000010
mPTEPE_PTEPE2       equ       %00000100
mPTEPE_PTEPE3       equ       %00001000
mPTEPE_PTEPE4       equ       %00010000
mPTEPE_PTEPE5       equ       %00100000
mPTEPE_PTEPE6       equ       %01000000


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
; bit position masks
mPTESE_PTESE0       equ       %00000001
mPTESE_PTESE1       equ       %00000010
mPTESE_PTESE2       equ       %00000100
mPTESE_PTESE3       equ       %00001000
mPTESE_PTESE4       equ       %00010000
mPTESE_PTESE5       equ       %00100000
mPTESE_PTESE6       equ       %01000000


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
; bit position masks
mPTEDS_PTEDS0       equ       %00000001
mPTEDS_PTEDS1       equ       %00000010
mPTEDS_PTEDS2       equ       %00000100
mPTEDS_PTEDS3       equ       %00001000
mPTEDS_PTEDS4       equ       %00010000
mPTEDS_PTEDS5       equ       %00100000
mPTEDS_PTEDS6       equ       %01000000


;*** PTFPE - Port F Pull Enable Register
PTFPE               equ       $00001854           ;*** PTFPE - Port F Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPE_PTFPE0        equ       0                   ; Internal Pull Enable for Port F Bit 0
PTFPE_PTFPE1        equ       1                   ; Internal Pull Enable for Port F Bit 1
PTFPE_PTFPE2        equ       2                   ; Internal Pull Enable for Port F Bit 2
; bit position masks
mPTFPE_PTFPE0       equ       %00000001
mPTFPE_PTFPE1       equ       %00000010
mPTFPE_PTFPE2       equ       %00000100


;*** PTFSE - Port F Slew Rate Enable Register
PTFSE               equ       $00001855           ;*** PTFSE - Port F Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0        equ       0                   ; Output Slew Rate Enable for Port F Bit 0
PTFSE_PTFSE1        equ       1                   ; Output Slew Rate Enable for Port F Bit 1
PTFSE_PTFSE2        equ       2                   ; Output Slew Rate Enable for Port F Bit 2
; bit position masks
mPTFSE_PTFSE0       equ       %00000001
mPTFSE_PTFSE1       equ       %00000010
mPTFSE_PTFSE2       equ       %00000100


;*** PTFDS - Port F Drive Strength Selection Register
PTFDS               equ       $00001856           ;*** PTFDS - Port F Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDS_PTFDS0        equ       0                   ; Output Drive Strength Selection for Port F Bit 0
PTFDS_PTFDS1        equ       1                   ; Output Drive Strength Selection for Port F Bit 1
PTFDS_PTFDS2        equ       2                   ; Output Drive Strength Selection for Port F Bit 2
; bit position masks
mPTFDS_PTFDS0       equ       %00000001
mPTFDS_PTFDS1       equ       %00000010
mPTFDS_PTFDS2       equ       %00000100


;*** HSCMP1CR0 - HSCMP1 Control Register 0
HSCMP1CR0           equ       $00001860           ;*** HSCMP1CR0 - HSCMP1 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP1CR0_MMC0      equ       0                   ; Minus Input Mux Control, bit 0
HSCMP1CR0_MMC1      equ       1                   ; Minus Input Mux Control, bit 1
HSCMP1CR0_PMC0      equ       2                   ; Positive Input Mux Control, bit 0
HSCMP1CR0_PMC1      equ       3                   ; Positive Input Mux Control, bit 1
HSCMP1CR0_FILTER_CNT0 equ       4                   ; Filter Sample Count, bit 0
HSCMP1CR0_FILTER_CNT1 equ       5                   ; Filter Sample Count, bit 1
HSCMP1CR0_FILTER_CNT2 equ       6                   ; Filter Sample Count, bit 2
; bit position masks
mHSCMP1CR0_MMC0     equ       %00000001
mHSCMP1CR0_MMC1     equ       %00000010
mHSCMP1CR0_PMC0     equ       %00000100
mHSCMP1CR0_PMC1     equ       %00001000
mHSCMP1CR0_FILTER_CNT0 equ       %00010000
mHSCMP1CR0_FILTER_CNT1 equ       %00100000
mHSCMP1CR0_FILTER_CNT2 equ       %01000000


;*** HSCMP1CR1 - HSCMP1 Control Register 1
HSCMP1CR1           equ       $00001861           ;*** HSCMP1CR1 - HSCMP1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP1CR1_EN        equ       0                   ; Comparator Module Enable
HSCMP1CR1_OPE       equ       1                   ; Comparator Output Pin Enable
HSCMP1CR1_COS       equ       2                   ; Comparator Output Select
HSCMP1CR1_INV       equ       3                   ; Comparator INVERT
HSCMP1CR1_PMODE     equ       4                   ; Power Mode Select
HSCMP1CR1_WE        equ       6                   ; Windowing Enable
HSCMP1CR1_SE        equ       7                   ; Sample Enable
; bit position masks
mHSCMP1CR1_EN       equ       %00000001
mHSCMP1CR1_OPE      equ       %00000010
mHSCMP1CR1_COS      equ       %00000100
mHSCMP1CR1_INV      equ       %00001000
mHSCMP1CR1_PMODE    equ       %00010000
mHSCMP1CR1_WE       equ       %01000000
mHSCMP1CR1_SE       equ       %10000000


;*** HSCMP1FPR - HSCMP1 Filter Period Register
HSCMP1FPR           equ       $00001862           ;*** HSCMP1FPR - HSCMP1 Filter Period Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP1FPR_FILT_PER0 equ       0                   ; Filter Period, bit 0
HSCMP1FPR_FILT_PER1 equ       1                   ; Filter Period, bit 1
HSCMP1FPR_FILT_PER2 equ       2                   ; Filter Period, bit 2
HSCMP1FPR_FILT_PER3 equ       3                   ; Filter Period, bit 3
HSCMP1FPR_FILT_PER4 equ       4                   ; Filter Period, bit 4
HSCMP1FPR_FILT_PER5 equ       5                   ; Filter Period, bit 5
HSCMP1FPR_FILT_PER6 equ       6                   ; Filter Period, bit 6
HSCMP1FPR_FILT_PER7 equ       7                   ; Filter Period, bit 7
; bit position masks
mHSCMP1FPR_FILT_PER0 equ       %00000001
mHSCMP1FPR_FILT_PER1 equ       %00000010
mHSCMP1FPR_FILT_PER2 equ       %00000100
mHSCMP1FPR_FILT_PER3 equ       %00001000
mHSCMP1FPR_FILT_PER4 equ       %00010000
mHSCMP1FPR_FILT_PER5 equ       %00100000
mHSCMP1FPR_FILT_PER6 equ       %01000000
mHSCMP1FPR_FILT_PER7 equ       %10000000


;*** HSCMP1SCR - HSCMP1 Status & Control Register
HSCMP1SCR           equ       $00001863           ;*** HSCMP1SCR - HSCMP1 Status & Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP1SCR_COUT      equ       0                   ; Analog Comparator Output
HSCMP1SCR_CFF       equ       1                   ; Analog Comparator Flag Falling
HSCMP1SCR_CFR       equ       2                   ; Analog Comparator Flag Rising
HSCMP1SCR_IEF       equ       3                   ; Comparator Interrupt Enable Falling
HSCMP1SCR_IER       equ       4                   ; Comparator Interrupt Enable Rising
HSCMP1SCR_SMLEB     equ       5                   ; Stop Mode Edge / Level Interrupt Control
; bit position masks
mHSCMP1SCR_COUT     equ       %00000001
mHSCMP1SCR_CFF      equ       %00000010
mHSCMP1SCR_CFR      equ       %00000100
mHSCMP1SCR_IEF      equ       %00001000
mHSCMP1SCR_IER      equ       %00010000
mHSCMP1SCR_SMLEB    equ       %00100000


;*** HSCMP1PCR - Pin Control Register
HSCMP1PCR           equ       $00001864           ;*** HSCMP1PCR - Pin Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP1PCR_INMPE1    equ       0                   ; Minus Input Pin 1 Enable
HSCMP1PCR_INMPE2    equ       1                   ; Minus Input Pin 2 Enable
HSCMP1PCR_INMPE3    equ       2                   ; Minus Input Pin 3 Enable
HSCMP1PCR_INMPE4    equ       3                   ; Minus Input Pin 4 Enable
HSCMP1PCR_INPPE1    equ       4                   ; Positive Input Pin 1 Enable
HSCMP1PCR_INPPE2    equ       5                   ; Positive Input Pin 2 Enable
HSCMP1PCR_INPPE3    equ       6                   ; Positive Input Pin 3 Enable
HSCMP1PCR_INPPE4    equ       7                   ; Positive Input Pin 4 Enable
; bit position masks
mHSCMP1PCR_INMPE1   equ       %00000001
mHSCMP1PCR_INMPE2   equ       %00000010
mHSCMP1PCR_INMPE3   equ       %00000100
mHSCMP1PCR_INMPE4   equ       %00001000
mHSCMP1PCR_INPPE1   equ       %00010000
mHSCMP1PCR_INPPE2   equ       %00100000
mHSCMP1PCR_INPPE3   equ       %01000000
mHSCMP1PCR_INPPE4   equ       %10000000


;*** HSCMP2CR0 - HSCMP2 Control Register 0
HSCMP2CR0           equ       $00001868           ;*** HSCMP2CR0 - HSCMP2 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP2CR0_MMC0      equ       0                   ; Minus Input Mux Control, bit 0
HSCMP2CR0_MMC1      equ       1                   ; Minus Input Mux Control, bit 1
HSCMP2CR0_PMC0      equ       2                   ; Positive Input Mux Control, bit 0
HSCMP2CR0_PMC1      equ       3                   ; Positive Input Mux Control, bit 1
HSCMP2CR0_FILTER_CNT0 equ       4                   ; Filter Sample Count, bit 0
HSCMP2CR0_FILTER_CNT1 equ       5                   ; Filter Sample Count, bit 1
HSCMP2CR0_FILTER_CNT2 equ       6                   ; Filter Sample Count, bit 2
; bit position masks
mHSCMP2CR0_MMC0     equ       %00000001
mHSCMP2CR0_MMC1     equ       %00000010
mHSCMP2CR0_PMC0     equ       %00000100
mHSCMP2CR0_PMC1     equ       %00001000
mHSCMP2CR0_FILTER_CNT0 equ       %00010000
mHSCMP2CR0_FILTER_CNT1 equ       %00100000
mHSCMP2CR0_FILTER_CNT2 equ       %01000000


;*** HSCMP2CR1 - HSCMP2 Control Register 1
HSCMP2CR1           equ       $00001869           ;*** HSCMP2CR1 - HSCMP2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP2CR1_EN        equ       0                   ; Comparator Module Enable
HSCMP2CR1_OPE       equ       1                   ; Comparator Output Pin Enable
HSCMP2CR1_COS       equ       2                   ; Comparator Output Select
HSCMP2CR1_INV       equ       3                   ; Comparator INVERT
HSCMP2CR1_PMODE     equ       4                   ; Power Mode Select
HSCMP2CR1_WE        equ       6                   ; Windowing Enable
HSCMP2CR1_SE        equ       7                   ; Sample Enable
; bit position masks
mHSCMP2CR1_EN       equ       %00000001
mHSCMP2CR1_OPE      equ       %00000010
mHSCMP2CR1_COS      equ       %00000100
mHSCMP2CR1_INV      equ       %00001000
mHSCMP2CR1_PMODE    equ       %00010000
mHSCMP2CR1_WE       equ       %01000000
mHSCMP2CR1_SE       equ       %10000000


;*** HSCMP2FPR - HSCMP2 Filter Period Register
HSCMP2FPR           equ       $0000186A           ;*** HSCMP2FPR - HSCMP2 Filter Period Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP2FPR_FILT_PER0 equ       0                   ; Filter Period, bit 0
HSCMP2FPR_FILT_PER1 equ       1                   ; Filter Period, bit 1
HSCMP2FPR_FILT_PER2 equ       2                   ; Filter Period, bit 2
HSCMP2FPR_FILT_PER3 equ       3                   ; Filter Period, bit 3
HSCMP2FPR_FILT_PER4 equ       4                   ; Filter Period, bit 4
HSCMP2FPR_FILT_PER5 equ       5                   ; Filter Period, bit 5
HSCMP2FPR_FILT_PER6 equ       6                   ; Filter Period, bit 6
HSCMP2FPR_FILT_PER7 equ       7                   ; Filter Period, bit 7
; bit position masks
mHSCMP2FPR_FILT_PER0 equ       %00000001
mHSCMP2FPR_FILT_PER1 equ       %00000010
mHSCMP2FPR_FILT_PER2 equ       %00000100
mHSCMP2FPR_FILT_PER3 equ       %00001000
mHSCMP2FPR_FILT_PER4 equ       %00010000
mHSCMP2FPR_FILT_PER5 equ       %00100000
mHSCMP2FPR_FILT_PER6 equ       %01000000
mHSCMP2FPR_FILT_PER7 equ       %10000000


;*** HSCMP2SCR - HSCMP2 Status & Control Register
HSCMP2SCR           equ       $0000186B           ;*** HSCMP2SCR - HSCMP2 Status & Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP2SCR_COUT      equ       0                   ; Analog Comparator Output
HSCMP2SCR_CFF       equ       1                   ; Analog Comparator Flag Falling
HSCMP2SCR_CFR       equ       2                   ; Analog Comparator Flag Rising
HSCMP2SCR_IEF       equ       3                   ; Comparator Interrupt Enable Falling
HSCMP2SCR_IER       equ       4                   ; Comparator Interrupt Enable Rising
HSCMP2SCR_SMLEB     equ       5                   ; Stop Mode Edge / Level Interrupt Control
; bit position masks
mHSCMP2SCR_COUT     equ       %00000001
mHSCMP2SCR_CFF      equ       %00000010
mHSCMP2SCR_CFR      equ       %00000100
mHSCMP2SCR_IEF      equ       %00001000
mHSCMP2SCR_IER      equ       %00010000
mHSCMP2SCR_SMLEB    equ       %00100000


;*** HSCMP2PCR - Pin Control Register
HSCMP2PCR           equ       $0000186C           ;*** HSCMP2PCR - Pin Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP2PCR_INMPE1    equ       0                   ; Minus Input Pin 1 Enable
HSCMP2PCR_INMPE2    equ       1                   ; Minus Input Pin 2 Enable
HSCMP2PCR_INMPE3    equ       2                   ; Minus Input Pin 3 Enable
HSCMP2PCR_INMPE4    equ       3                   ; Minus Input Pin 4 Enable
HSCMP2PCR_INPPE1    equ       4                   ; Positive Input Pin 1 Enable
HSCMP2PCR_INPPE2    equ       5                   ; Positive Input Pin 2 Enable
HSCMP2PCR_INPPE3    equ       6                   ; Positive Input Pin 3 Enable
HSCMP2PCR_INPPE4    equ       7                   ; Positive Input Pin 4 Enable
; bit position masks
mHSCMP2PCR_INMPE1   equ       %00000001
mHSCMP2PCR_INMPE2   equ       %00000010
mHSCMP2PCR_INMPE3   equ       %00000100
mHSCMP2PCR_INMPE4   equ       %00001000
mHSCMP2PCR_INPPE1   equ       %00010000
mHSCMP2PCR_INPPE2   equ       %00100000
mHSCMP2PCR_INPPE3   equ       %01000000
mHSCMP2PCR_INPPE4   equ       %10000000


;*** HSCMP3CR0 - HSCMP3 Control Register 0
HSCMP3CR0           equ       $00001870           ;*** HSCMP3CR0 - HSCMP3 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP3CR0_MMC0      equ       0                   ; Minus Input Mux Control, bit 0
HSCMP3CR0_MMC1      equ       1                   ; Minus Input Mux Control, bit 1
HSCMP3CR0_PMC0      equ       2                   ; Positive Input Mux Control, bit 0
HSCMP3CR0_PMC1      equ       3                   ; Positive Input Mux Control, bit 1
HSCMP3CR0_FILTER_CNT0 equ       4                   ; Filter Sample Count, bit 0
HSCMP3CR0_FILTER_CNT1 equ       5                   ; Filter Sample Count, bit 1
HSCMP3CR0_FILTER_CNT2 equ       6                   ; Filter Sample Count, bit 2
; bit position masks
mHSCMP3CR0_MMC0     equ       %00000001
mHSCMP3CR0_MMC1     equ       %00000010
mHSCMP3CR0_PMC0     equ       %00000100
mHSCMP3CR0_PMC1     equ       %00001000
mHSCMP3CR0_FILTER_CNT0 equ       %00010000
mHSCMP3CR0_FILTER_CNT1 equ       %00100000
mHSCMP3CR0_FILTER_CNT2 equ       %01000000


;*** HSCMP3CR1 - HSCMP3 Control Register 1
HSCMP3CR1           equ       $00001871           ;*** HSCMP3CR1 - HSCMP3 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP3CR1_EN        equ       0                   ; Comparator Module Enable
HSCMP3CR1_OPE       equ       1                   ; Comparator Output Pin Enable
HSCMP3CR1_COS       equ       2                   ; Comparator Output Select
HSCMP3CR1_INV       equ       3                   ; Comparator INVERT
HSCMP3CR1_PMODE     equ       4                   ; Power Mode Select
HSCMP3CR1_WE        equ       6                   ; Windowing Enable
HSCMP3CR1_SE        equ       7                   ; Sample Enable
; bit position masks
mHSCMP3CR1_EN       equ       %00000001
mHSCMP3CR1_OPE      equ       %00000010
mHSCMP3CR1_COS      equ       %00000100
mHSCMP3CR1_INV      equ       %00001000
mHSCMP3CR1_PMODE    equ       %00010000
mHSCMP3CR1_WE       equ       %01000000
mHSCMP3CR1_SE       equ       %10000000


;*** HSCMP3FPR - HSCMP3 Filter Period Register
HSCMP3FPR           equ       $00001872           ;*** HSCMP3FPR - HSCMP3 Filter Period Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP3FPR_FILT_PER0 equ       0                   ; Filter Period, bit 0
HSCMP3FPR_FILT_PER1 equ       1                   ; Filter Period, bit 1
HSCMP3FPR_FILT_PER2 equ       2                   ; Filter Period, bit 2
HSCMP3FPR_FILT_PER3 equ       3                   ; Filter Period, bit 3
HSCMP3FPR_FILT_PER4 equ       4                   ; Filter Period, bit 4
HSCMP3FPR_FILT_PER5 equ       5                   ; Filter Period, bit 5
HSCMP3FPR_FILT_PER6 equ       6                   ; Filter Period, bit 6
HSCMP3FPR_FILT_PER7 equ       7                   ; Filter Period, bit 7
; bit position masks
mHSCMP3FPR_FILT_PER0 equ       %00000001
mHSCMP3FPR_FILT_PER1 equ       %00000010
mHSCMP3FPR_FILT_PER2 equ       %00000100
mHSCMP3FPR_FILT_PER3 equ       %00001000
mHSCMP3FPR_FILT_PER4 equ       %00010000
mHSCMP3FPR_FILT_PER5 equ       %00100000
mHSCMP3FPR_FILT_PER6 equ       %01000000
mHSCMP3FPR_FILT_PER7 equ       %10000000


;*** HSCMP3SCR - HSCMP3 Status & Control Register
HSCMP3SCR           equ       $00001873           ;*** HSCMP3SCR - HSCMP3 Status & Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP3SCR_COUT      equ       0                   ; Analog Comparator Output
HSCMP3SCR_CFF       equ       1                   ; Analog Comparator Flag Falling
HSCMP3SCR_CFR       equ       2                   ; Analog Comparator Flag Rising
HSCMP3SCR_IEF       equ       3                   ; Comparator Interrupt Enable Falling
HSCMP3SCR_IER       equ       4                   ; Comparator Interrupt Enable Rising
HSCMP3SCR_SMLEB     equ       5                   ; Stop Mode Edge / Level Interrupt Control
; bit position masks
mHSCMP3SCR_COUT     equ       %00000001
mHSCMP3SCR_CFF      equ       %00000010
mHSCMP3SCR_CFR      equ       %00000100
mHSCMP3SCR_IEF      equ       %00001000
mHSCMP3SCR_IER      equ       %00010000
mHSCMP3SCR_SMLEB    equ       %00100000


;*** HSCMP3PCR - Pin Control Register
HSCMP3PCR           equ       $00001874           ;*** HSCMP3PCR - Pin Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HSCMP3PCR_INMPE1    equ       0                   ; Minus Input Pin 1 Enable
HSCMP3PCR_INMPE2    equ       1                   ; Minus Input Pin 2 Enable
HSCMP3PCR_INMPE3    equ       2                   ; Minus Input Pin 3 Enable
HSCMP3PCR_INMPE4    equ       3                   ; Minus Input Pin 4 Enable
HSCMP3PCR_INPPE1    equ       4                   ; Positive Input Pin 1 Enable
HSCMP3PCR_INPPE2    equ       5                   ; Positive Input Pin 2 Enable
HSCMP3PCR_INPPE3    equ       6                   ; Positive Input Pin 3 Enable
HSCMP3PCR_INPPE4    equ       7                   ; Positive Input Pin 4 Enable
; bit position masks
mHSCMP3PCR_INMPE1   equ       %00000001
mHSCMP3PCR_INMPE2   equ       %00000010
mHSCMP3PCR_INMPE3   equ       %00000100
mHSCMP3PCR_INMPE4   equ       %00001000
mHSCMP3PCR_INPPE1   equ       %00010000
mHSCMP3PCR_INPPE2   equ       %00100000
mHSCMP3PCR_INPPE3   equ       %01000000
mHSCMP3PCR_INPPE4   equ       %10000000


;*** PGACNTL0 - PGA Control Register 0
PGACNTL0            equ       $00001878           ;*** PGACNTL0 - PGA Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PGACNTL0_EN         equ       0                   ; Module Enable
PGACNTL0_LP         equ       1                   ; Power Mode
PGACNTL0_GAINSEL0   equ       2                   ; Gain Select, bit 0
PGACNTL0_GAINSEL1   equ       3                   ; Gain Select, bit 1
PGACNTL0_GAINSEL2   equ       4                   ; Gain Select, bit 2
PGACNTL0_GAINSEL3   equ       5                   ; Gain Select, bit 3
PGACNTL0_GAINSEL4   equ       6                   ; Gain Select, bit 4
PGACNTL0_TM         equ       7                   ; Trigger Mode
; bit position masks
mPGACNTL0_EN        equ       %00000001
mPGACNTL0_LP        equ       %00000010
mPGACNTL0_GAINSEL0  equ       %00000100
mPGACNTL0_GAINSEL1  equ       %00001000
mPGACNTL0_GAINSEL2  equ       %00010000
mPGACNTL0_GAINSEL3  equ       %00100000
mPGACNTL0_GAINSEL4  equ       %01000000
mPGACNTL0_TM        equ       %10000000


;*** PGACNTL1 - PGA Control Register 1
PGACNTL1            equ       $00001879           ;*** PGACNTL1 - PGA Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PGACNTL1_CPD0       equ       0                   ; Charge Pump Divisor, bit 0
PGACNTL1_CPD1       equ       1                   ; Charge Pump Divisor, bit 1
PGACNTL1_CPD2       equ       2                   ; Charge Pump Divisor, bit 2
PGACNTL1_CALMODE0   equ       3                   ; Calibration Mode, bit 0
PGACNTL1_CALMODE1   equ       4                   ; Calibration Mode, bit 1
; bit position masks
mPGACNTL1_CPD0      equ       %00000001
mPGACNTL1_CPD1      equ       %00000010
mPGACNTL1_CPD2      equ       %00000100
mPGACNTL1_CALMODE0  equ       %00001000
mPGACNTL1_CALMODE1  equ       %00010000


;*** PGACNTL2 - PGA Control Register 2
PGACNTL2            equ       $0000187A           ;*** PGACNTL2 - PGA Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PGACNTL2_ADIV0      equ       0                   ; Clock Divide Select, bit 0
PGACNTL2_ADIV1      equ       1                   ; Clock Divide Select, bit 1
PGACNTL2_NUM_CLK_GS0 equ       2                   ; Number of clk_gs pulses per conversion, bit 0
PGACNTL2_NUM_CLK_GS1 equ       3                   ; Number of clk_gs pulses per conversion, bit 1
PGACNTL2_NUM_CLK_GS2 equ       4                   ; Number of clk_gs pulses per conversion, bit 2
PGACNTL2_SWTRIG     equ       5                   ; Software Trigger
; bit position masks
mPGACNTL2_ADIV0     equ       %00000001
mPGACNTL2_ADIV1     equ       %00000010
mPGACNTL2_NUM_CLK_GS0 equ       %00000100
mPGACNTL2_NUM_CLK_GS1 equ       %00001000
mPGACNTL2_NUM_CLK_GS2 equ       %00010000
mPGACNTL2_SWTRIG    equ       %00100000


;*** PGASTS - PGA Status Register
PGASTS              equ       $0000187B           ;*** PGASTS - PGA Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PGASTS_STCOMP       equ       0                   ; Startup Complete
PGASTS_RUNNING      equ       1                   ; PGA RUN Sequence Underway
; bit position masks
mPGASTS_STCOMP      equ       %00000001
mPGASTS_RUNNING     equ       %00000010


;*** FTM2SC - FTM2 Status and Control Register
FTM2SC              equ       $00001880           ;*** FTM2SC - FTM2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2SC_PS0          equ       0                   ; Prescale Divisor Select Bit 0
FTM2SC_PS1          equ       1                   ; Prescale Divisor Select Bit 1
FTM2SC_PS2          equ       2                   ; Prescale Divisor Select Bit 2
FTM2SC_CLKSA        equ       3                   ; Clock Source Select A
FTM2SC_CLKSB        equ       4                   ; Clock Source Select B
FTM2SC_CPWMS        equ       5                   ; Center-Aligned PWM Select
FTM2SC_TOIE         equ       6                   ; Timer Overflow Interrupt Enable
FTM2SC_TOF          equ       7                   ; Timer Overflow Flag
; bit position masks
mFTM2SC_PS0         equ       %00000001
mFTM2SC_PS1         equ       %00000010
mFTM2SC_PS2         equ       %00000100
mFTM2SC_CLKSA       equ       %00001000
mFTM2SC_CLKSB       equ       %00010000
mFTM2SC_CPWMS       equ       %00100000
mFTM2SC_TOIE        equ       %01000000
mFTM2SC_TOF         equ       %10000000


;*** FTM2CNT - FTM2 Timer Counter Register
FTM2CNT             equ       $00001881           ;*** FTM2CNT - FTM2 Timer Counter Register


;*** FTM2CNTH - FTM2 Timer Counter Register High
FTM2CNTH            equ       $00001881           ;*** FTM2CNTH - FTM2 Timer Counter Register High


;*** FTM2CNTL - FTM2 Timer Counter Register Low
FTM2CNTL            equ       $00001882           ;*** FTM2CNTL - FTM2 Timer Counter Register Low


;*** FTM2MOD - FTM2 Timer Counter Modulo Register
FTM2MOD             equ       $00001883           ;*** FTM2MOD - FTM2 Timer Counter Modulo Register


;*** FTM2MODH - FTM2 Timer Counter Modulo Register High
FTM2MODH            equ       $00001883           ;*** FTM2MODH - FTM2 Timer Counter Modulo Register High


;*** FTM2MODL - FTM2 Timer Counter Modulo Register Low
FTM2MODL            equ       $00001884           ;*** FTM2MODL - FTM2 Timer Counter Modulo Register Low


;*** FTM2C0SC - FTM2 Timer Channel 0 Status and Control Register
FTM2C0SC            equ       $00001885           ;*** FTM2C0SC - FTM2 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2C0SC_ELS0A      equ       2                   ; Edge/Level Select Bit A
FTM2C0SC_ELS0B      equ       3                   ; Edge/Level Select Bit B
FTM2C0SC_MS0A       equ       4                   ; Mode Select A for FTM2 Channel 0
FTM2C0SC_MS0B       equ       5                   ; Mode Select B for FTM2 Channel 0
FTM2C0SC_CH0IE      equ       6                   ; Channel 0 Interrupt Enable
FTM2C0SC_CH0F       equ       7                   ; Channel 0 Flag
; bit position masks
mFTM2C0SC_ELS0A     equ       %00000100
mFTM2C0SC_ELS0B     equ       %00001000
mFTM2C0SC_MS0A      equ       %00010000
mFTM2C0SC_MS0B      equ       %00100000
mFTM2C0SC_CH0IE     equ       %01000000
mFTM2C0SC_CH0F      equ       %10000000


;*** FTM2C0V - FTM2 Timer Channel 0 Value Register
FTM2C0V             equ       $00001886           ;*** FTM2C0V - FTM2 Timer Channel 0 Value Register


;*** FTM2C0VH - FTM2 Timer Channel 0 Value Register High
FTM2C0VH            equ       $00001886           ;*** FTM2C0VH - FTM2 Timer Channel 0 Value Register High


;*** FTM2C0VL - FTM2 Timer Channel 0 Value Register Low
FTM2C0VL            equ       $00001887           ;*** FTM2C0VL - FTM2 Timer Channel 0 Value Register Low


;*** FTM2C1SC - FTM2 Timer Channel 1 Status and Control Register
FTM2C1SC            equ       $00001888           ;*** FTM2C1SC - FTM2 Timer Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2C1SC_ELS1A      equ       2                   ; Edge/Level Select Bit A
FTM2C1SC_ELS1B      equ       3                   ; Edge/Level Select Bit B
FTM2C1SC_MS1A       equ       4                   ; Mode Select A for FTM2 Channel 1
FTM2C1SC_MS1B       equ       5                   ; Mode Select B for FTM2 Channel 1
FTM2C1SC_CH1IE      equ       6                   ; Channel 1 Interrupt Enable
FTM2C1SC_CH1F       equ       7                   ; Channel 1 Flag
; bit position masks
mFTM2C1SC_ELS1A     equ       %00000100
mFTM2C1SC_ELS1B     equ       %00001000
mFTM2C1SC_MS1A      equ       %00010000
mFTM2C1SC_MS1B      equ       %00100000
mFTM2C1SC_CH1IE     equ       %01000000
mFTM2C1SC_CH1F      equ       %10000000


;*** FTM2C1V - FTM2 Timer Channel 1 Value Register
FTM2C1V             equ       $00001889           ;*** FTM2C1V - FTM2 Timer Channel 1 Value Register


;*** FTM2C1VH - FTM2 Timer Channel 1 Value Register High
FTM2C1VH            equ       $00001889           ;*** FTM2C1VH - FTM2 Timer Channel 1 Value Register High


;*** FTM2C1VL - FTM2 Timer Channel 1 Value Register Low
FTM2C1VL            equ       $0000188A           ;*** FTM2C1VL - FTM2 Timer Channel 1 Value Register Low


;*** FTM2C2SC - FTM2 Timer Channel 2 Status and Control Register
FTM2C2SC            equ       $0000188B           ;*** FTM2C2SC - FTM2 Timer Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2C2SC_ELS2A      equ       2                   ; Edge/Level Select Bit A
FTM2C2SC_ELS2B      equ       3                   ; Edge/Level Select Bit B
FTM2C2SC_MS2A       equ       4                   ; Mode Select A for FTM2 Channel 2
FTM2C2SC_MS2B       equ       5                   ; Mode Select B for FTM2 Channel 2
FTM2C2SC_CH2IE      equ       6                   ; Channel 2 Interrupt Enable
FTM2C2SC_CH2F       equ       7                   ; Channel 2 Flag
; bit position masks
mFTM2C2SC_ELS2A     equ       %00000100
mFTM2C2SC_ELS2B     equ       %00001000
mFTM2C2SC_MS2A      equ       %00010000
mFTM2C2SC_MS2B      equ       %00100000
mFTM2C2SC_CH2IE     equ       %01000000
mFTM2C2SC_CH2F      equ       %10000000


;*** FTM2C2V - FTM2 Timer Channel 2 Value Register
FTM2C2V             equ       $0000188C           ;*** FTM2C2V - FTM2 Timer Channel 2 Value Register


;*** FTM2C2VH - FTM2 Timer Channel 2 Value Register High
FTM2C2VH            equ       $0000188C           ;*** FTM2C2VH - FTM2 Timer Channel 2 Value Register High


;*** FTM2C2VL - FTM2 Timer Channel 2 Value Register Low
FTM2C2VL            equ       $0000188D           ;*** FTM2C2VL - FTM2 Timer Channel 2 Value Register Low


;*** FTM2C3SC - FTM2 Timer Channel 3 Status and Control Register
FTM2C3SC            equ       $0000188E           ;*** FTM2C3SC - FTM2 Timer Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2C3SC_ELS3A      equ       2                   ; Edge/Level Select Bit A
FTM2C3SC_ELS3B      equ       3                   ; Edge/Level Select Bit B
FTM2C3SC_MS3A       equ       4                   ; Mode Select A for FTM2 Channel 3
FTM2C3SC_MS3B       equ       5                   ; Mode Select B for FTM2 Channel 3
FTM2C3SC_CH3IE      equ       6                   ; Channel 3 Interrupt Enable
FTM2C3SC_CH3F       equ       7                   ; Channel 3 Flag
; bit position masks
mFTM2C3SC_ELS3A     equ       %00000100
mFTM2C3SC_ELS3B     equ       %00001000
mFTM2C3SC_MS3A      equ       %00010000
mFTM2C3SC_MS3B      equ       %00100000
mFTM2C3SC_CH3IE     equ       %01000000
mFTM2C3SC_CH3F      equ       %10000000


;*** FTM2C3V - FTM2 Timer Channel 3 Value Register
FTM2C3V             equ       $0000188F           ;*** FTM2C3V - FTM2 Timer Channel 3 Value Register


;*** FTM2C3VH - FTM2 Timer Channel 3 Value Register High
FTM2C3VH            equ       $0000188F           ;*** FTM2C3VH - FTM2 Timer Channel 3 Value Register High


;*** FTM2C3VL - FTM2 Timer Channel 3 Value Register Low
FTM2C3VL            equ       $00001890           ;*** FTM2C3VL - FTM2 Timer Channel 3 Value Register Low


;*** FTM2C4SC - FTM2 Timer Channel 4 Status and Control Register
FTM2C4SC            equ       $00001891           ;*** FTM2C4SC - FTM2 Timer Channel 4 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2C4SC_ELS4A      equ       2                   ; Edge/Level Select Bit A
FTM2C4SC_ELS4B      equ       3                   ; Edge/Level Select Bit B
FTM2C4SC_MS4A       equ       4                   ; Mode Select A for FTM2 Channel 4
FTM2C4SC_MS4B       equ       5                   ; Mode Select B for FTM2 Channel 4
FTM2C4SC_CH4IE      equ       6                   ; Channel 4 Interrupt Enable
FTM2C4SC_CH4F       equ       7                   ; Channel 4 Flag
; bit position masks
mFTM2C4SC_ELS4A     equ       %00000100
mFTM2C4SC_ELS4B     equ       %00001000
mFTM2C4SC_MS4A      equ       %00010000
mFTM2C4SC_MS4B      equ       %00100000
mFTM2C4SC_CH4IE     equ       %01000000
mFTM2C4SC_CH4F      equ       %10000000


;*** FTM2C4V - FTM2 Timer Channel 4 Value Register
FTM2C4V             equ       $00001892           ;*** FTM2C4V - FTM2 Timer Channel 4 Value Register


;*** FTM2C4VH - FTM2 Timer Channel 4 Value Register High
FTM2C4VH            equ       $00001892           ;*** FTM2C4VH - FTM2 Timer Channel 4 Value Register High


;*** FTM2C4VL - FTM2 Timer Channel 4 Value Register Low
FTM2C4VL            equ       $00001893           ;*** FTM2C4VL - FTM2 Timer Channel 4 Value Register Low


;*** FTM2C5SC - FTM2 Timer Channel 5 Status and Control Register
FTM2C5SC            equ       $00001894           ;*** FTM2C5SC - FTM2 Timer Channel 5 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2C5SC_ELS5A      equ       2                   ; Edge/Level Select Bit A
FTM2C5SC_ELS5B      equ       3                   ; Edge/Level Select Bit B
FTM2C5SC_MS5A       equ       4                   ; Mode Select A for FTM2 Channel 5
FTM2C5SC_MS5B       equ       5                   ; Mode Select B for FTM2 Channel 5
FTM2C5SC_CH5IE      equ       6                   ; Channel 5 Interrupt Enable
FTM2C5SC_CH5F       equ       7                   ; Channel 5 Flag
; bit position masks
mFTM2C5SC_ELS5A     equ       %00000100
mFTM2C5SC_ELS5B     equ       %00001000
mFTM2C5SC_MS5A      equ       %00010000
mFTM2C5SC_MS5B      equ       %00100000
mFTM2C5SC_CH5IE     equ       %01000000
mFTM2C5SC_CH5F      equ       %10000000


;*** FTM2C5V - FTM2 Timer Channel 5 Value Register
FTM2C5V             equ       $00001895           ;*** FTM2C5V - FTM2 Timer Channel 5 Value Register


;*** FTM2C5VH - FTM2 Timer Channel 5 Value Register High
FTM2C5VH            equ       $00001895           ;*** FTM2C5VH - FTM2 Timer Channel 5 Value Register High


;*** FTM2C5VL - FTM2 Timer Channel 5 Value Register Low
FTM2C5VL            equ       $00001896           ;*** FTM2C5VL - FTM2 Timer Channel 5 Value Register Low


;*** FTM2CNTIN - FTM2 Counter Initial Value Registers
FTM2CNTIN           equ       $000018A0           ;*** FTM2CNTIN - FTM2 Counter Initial Value Registers


;*** FTM2CNTINH - FTM2 Counter Initial Value Registers High
FTM2CNTINH          equ       $000018A0           ;*** FTM2CNTINH - FTM2 Counter Initial Value Registers High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2CNTINH_BIT8     equ       0                   ; FTM2 Counter Initial Value Bit 8
FTM2CNTINH_BIT9     equ       1                   ; FTM2 Counter Initial Value Bit 9
FTM2CNTINH_BIT10    equ       2                   ; FTM2 Counter Initial Value Bit 10
FTM2CNTINH_BIT11    equ       3                   ; FTM2 Counter Initial Value Bit 11
FTM2CNTINH_BIT12    equ       4                   ; FTM2 Counter Initial Value Bit 12
FTM2CNTINH_BIT13    equ       5                   ; FTM2 Counter Initial Value Bit 13
FTM2CNTINH_BIT14    equ       6                   ; FTM2 Counter Initial Value Bit 14
FTM2CNTINH_BIT15    equ       7                   ; FTM2 Counter Initial Value Bit 15
; bit position masks
mFTM2CNTINH_BIT8    equ       %00000001
mFTM2CNTINH_BIT9    equ       %00000010
mFTM2CNTINH_BIT10   equ       %00000100
mFTM2CNTINH_BIT11   equ       %00001000
mFTM2CNTINH_BIT12   equ       %00010000
mFTM2CNTINH_BIT13   equ       %00100000
mFTM2CNTINH_BIT14   equ       %01000000
mFTM2CNTINH_BIT15   equ       %10000000


;*** FTM2CNTINL - FTM2 Counter Initial Value Registers Low
FTM2CNTINL          equ       $000018A1           ;*** FTM2CNTINL - FTM2 Counter Initial Value Registers Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2CNTINL_BIT0     equ       0                   ; FTM2 Counter Initial Value Bit 0
FTM2CNTINL_BIT1     equ       1                   ; FTM2 Counter Initial Value Bit 1
FTM2CNTINL_BIT2     equ       2                   ; FTM2 Counter Initial Value Bit 2
FTM2CNTINL_BIT3     equ       3                   ; FTM2 Counter Initial Value Bit 3
FTM2CNTINL_BIT4     equ       4                   ; FTM2 Counter Initial Value Bit 4
FTM2CNTINL_BIT5     equ       5                   ; FTM2 Counter Initial Value Bit 5
FTM2CNTINL_BIT6     equ       6                   ; FTM2 Counter Initial Value Bit 6
FTM2CNTINL_BIT7     equ       7                   ; FTM2 Counter Initial Value Bit 7
; bit position masks
mFTM2CNTINL_BIT0    equ       %00000001
mFTM2CNTINL_BIT1    equ       %00000010
mFTM2CNTINL_BIT2    equ       %00000100
mFTM2CNTINL_BIT3    equ       %00001000
mFTM2CNTINL_BIT4    equ       %00010000
mFTM2CNTINL_BIT5    equ       %00100000
mFTM2CNTINL_BIT6    equ       %01000000
mFTM2CNTINL_BIT7    equ       %10000000


;*** FTM2STATUS - FTM2 Capture and Compare Status Register
FTM2STATUS          equ       $000018A2           ;*** FTM2STATUS - FTM2 Capture and Compare Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2STATUS_CH0F     equ       0                   ; Channel 0 Flag
FTM2STATUS_CH1F     equ       1                   ; Channel 1 Flag
FTM2STATUS_CH2F     equ       2                   ; Channel 2 Flag
FTM2STATUS_CH3F     equ       3                   ; Channel 3 Flag
FTM2STATUS_CH4F     equ       4                   ; Channel 4 Flag
FTM2STATUS_CH5F     equ       5                   ; Channel 5 Flag
; bit position masks
mFTM2STATUS_CH0F    equ       %00000001
mFTM2STATUS_CH1F    equ       %00000010
mFTM2STATUS_CH2F    equ       %00000100
mFTM2STATUS_CH3F    equ       %00001000
mFTM2STATUS_CH4F    equ       %00010000
mFTM2STATUS_CH5F    equ       %00100000


;*** FTM2MODE - FTM2 Features Mode Selection Register
FTM2MODE            equ       $000018A3           ;*** FTM2MODE - FTM2 Features Mode Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2MODE_FTMEN      equ       0                   ; FTM2 Enable
FTM2MODE_INIT       equ       1                   ; Initialize the Channels Output
FTM2MODE_WPDIS      equ       2                   ; Write Protected Disable
FTM2MODE_PWMSYNC    equ       3                   ; PWM synchronization mode
FTM2MODE_CAPTTEST   equ       4                   ; Capture test mode enable
FTM2MODE_FAULTM0    equ       5                   ; Fault Control Mode Bits, bit 0
FTM2MODE_FAULTM1    equ       6                   ; Fault Control Mode Bits, bit 1
FTM2MODE_FAULTIE    equ       7                   ; Fault Interrupt Enable
; bit position masks
mFTM2MODE_FTMEN     equ       %00000001
mFTM2MODE_INIT      equ       %00000010
mFTM2MODE_WPDIS     equ       %00000100
mFTM2MODE_PWMSYNC   equ       %00001000
mFTM2MODE_CAPTTEST  equ       %00010000
mFTM2MODE_FAULTM0   equ       %00100000
mFTM2MODE_FAULTM1   equ       %01000000
mFTM2MODE_FAULTIE   equ       %10000000


;*** FTM2SYNC - FTM2 Synchronization Register
FTM2SYNC            equ       $000018A4           ;*** FTM2SYNC - FTM2 Synchronization Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2SYNC_CNTMIN     equ       0                   ; FTM2 Counter is Minimum
FTM2SYNC_CNTMAX     equ       1                   ; FTM2 Counter is Maximum
FTM2SYNC_REINIT     equ       2                   ; Reinitialization of FTM2 Counter by Synchronization
FTM2SYNC_SYNCHOM    equ       3                   ; Output Mask by Synchronization
FTM2SYNC_TRIG0      equ       4                   ; External Trigger Bit 0 for Synchronization
FTM2SYNC_TRIG1      equ       5                   ; External Trigger Bit 1 for Synchronization
FTM2SYNC_TRIG2      equ       6                   ; External Trigger Bit 2 for Synchronization
FTM2SYNC_SWSYNC     equ       7                   ; Software Trigger for Synchronization
; bit position masks
mFTM2SYNC_CNTMIN    equ       %00000001
mFTM2SYNC_CNTMAX    equ       %00000010
mFTM2SYNC_REINIT    equ       %00000100
mFTM2SYNC_SYNCHOM   equ       %00001000
mFTM2SYNC_TRIG0     equ       %00010000
mFTM2SYNC_TRIG1     equ       %00100000
mFTM2SYNC_TRIG2     equ       %01000000
mFTM2SYNC_SWSYNC    equ       %10000000


;*** FTM2OUTINIT - FTM2 Initial State for Channels Output Register
FTM2OUTINIT         equ       $000018A5           ;*** FTM2OUTINIT - FTM2 Initial State for Channels Output Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2OUTINIT_CH0OI   equ       0                   ; Initial State for Channel 0 Output
FTM2OUTINIT_CH1OI   equ       1                   ; Initial State for Channel 1 Output
FTM2OUTINIT_CH2OI   equ       2                   ; Initial State for Channel 2 Output
FTM2OUTINIT_CH3OI   equ       3                   ; Initial State for Channel 3 Output
FTM2OUTINIT_CH4OI   equ       4                   ; Initial State for Channel 4 Output
FTM2OUTINIT_CH5OI   equ       5                   ; Initial State for Channel 5 Output
; bit position masks
mFTM2OUTINIT_CH0OI  equ       %00000001
mFTM2OUTINIT_CH1OI  equ       %00000010
mFTM2OUTINIT_CH2OI  equ       %00000100
mFTM2OUTINIT_CH3OI  equ       %00001000
mFTM2OUTINIT_CH4OI  equ       %00010000
mFTM2OUTINIT_CH5OI  equ       %00100000


;*** FTM2OUTMASK - FTM2 Output Mask Register
FTM2OUTMASK         equ       $000018A6           ;*** FTM2OUTMASK - FTM2 Output Mask Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2OUTMASK_CH0OM   equ       0                   ; Channel 0 Output Mask
FTM2OUTMASK_CH1OM   equ       1                   ; Channel 1 Output Mask
FTM2OUTMASK_CH2OM   equ       2                   ; Channel 2 Output Mask
FTM2OUTMASK_CH3OM   equ       3                   ; Channel 3 Output Mask
FTM2OUTMASK_CH4OM   equ       4                   ; Channel 4 Output Mask
FTM2OUTMASK_CH5OM   equ       5                   ; Channel 5 Output Mask
; bit position masks
mFTM2OUTMASK_CH0OM  equ       %00000001
mFTM2OUTMASK_CH1OM  equ       %00000010
mFTM2OUTMASK_CH2OM  equ       %00000100
mFTM2OUTMASK_CH3OM  equ       %00001000
mFTM2OUTMASK_CH4OM  equ       %00010000
mFTM2OUTMASK_CH5OM  equ       %00100000


;*** FTM2COMBINE0 - FTM2 Function For Linked Channel 0 Register
FTM2COMBINE0        equ       $000018A7           ;*** FTM2COMBINE0 - FTM2 Function For Linked Channel 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2COMBINE0_COMBINE equ       0                   ; Enables the Combine of the Channels 0 and 1
FTM2COMBINE0_COMP   equ       1                   ; Complementary of Channel 0
FTM2COMBINE0_DTEN   equ       4                   ; Deadtime Enable
FTM2COMBINE0_SYNCEN equ       5                   ; Synchronization Enable
FTM2COMBINE0_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM2COMBINE0_COMBINE equ       %00000001
mFTM2COMBINE0_COMP  equ       %00000010
mFTM2COMBINE0_DTEN  equ       %00010000
mFTM2COMBINE0_SYNCEN equ       %00100000
mFTM2COMBINE0_FAULTEN equ       %01000000


;*** FTM2COMBINE1 - FTM2 Function For Linked Channel 1 Register
FTM2COMBINE1        equ       $000018A8           ;*** FTM2COMBINE1 - FTM2 Function For Linked Channel 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2COMBINE1_COMBINE equ       0                   ; Enables the Combine of the Channels 2 and 3
FTM2COMBINE1_COMP   equ       1                   ; Complementary of Channel 2
FTM2COMBINE1_DTEN   equ       4                   ; Deadtime Enable
FTM2COMBINE1_SYNCEN equ       5                   ; Synchronization Enable
FTM2COMBINE1_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM2COMBINE1_COMBINE equ       %00000001
mFTM2COMBINE1_COMP  equ       %00000010
mFTM2COMBINE1_DTEN  equ       %00010000
mFTM2COMBINE1_SYNCEN equ       %00100000
mFTM2COMBINE1_FAULTEN equ       %01000000


;*** FTM2COMBINE2 - FTM2 Function For Linked Channel 2 Register
FTM2COMBINE2        equ       $000018A9           ;*** FTM2COMBINE2 - FTM2 Function For Linked Channel 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2COMBINE2_COMBINE equ       0                   ; Enables the Combine of the Channels 4 and 5
FTM2COMBINE2_COMP   equ       1                   ; Complementary of Channel 4
FTM2COMBINE2_DTEN   equ       4                   ; Deadtime Enable
FTM2COMBINE2_SYNCEN equ       5                   ; Synchronization Enable
FTM2COMBINE2_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM2COMBINE2_COMBINE equ       %00000001
mFTM2COMBINE2_COMP  equ       %00000010
mFTM2COMBINE2_DTEN  equ       %00010000
mFTM2COMBINE2_SYNCEN equ       %00100000
mFTM2COMBINE2_FAULTEN equ       %01000000


;*** FTM2DEADTIME - FTM2 Deadtime Insertion Control Register
FTM2DEADTIME        equ       $000018AB           ;*** FTM2DEADTIME - FTM2 Deadtime Insertion Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2DEADTIME_DTVAL0 equ       0                   ; Deadtime Value Bits, bit 0
FTM2DEADTIME_DTVAL1 equ       1                   ; Deadtime Value Bits, bit 1
FTM2DEADTIME_DTVAL2 equ       2                   ; Deadtime Value Bits, bit 2
FTM2DEADTIME_DTVAL3 equ       3                   ; Deadtime Value Bits, bit 3
FTM2DEADTIME_DTVAL4 equ       4                   ; Deadtime Value Bits, bit 4
FTM2DEADTIME_DTVAL5 equ       5                   ; Deadtime Value Bits, bit 5
FTM2DEADTIME_DTPS0  equ       6                   ; Deadtime Prescaler Value Bits, bit 0
FTM2DEADTIME_DTPS1  equ       7                   ; Deadtime Prescaler Value Bits, bit 1
; bit position masks
mFTM2DEADTIME_DTVAL0 equ       %00000001
mFTM2DEADTIME_DTVAL1 equ       %00000010
mFTM2DEADTIME_DTVAL2 equ       %00000100
mFTM2DEADTIME_DTVAL3 equ       %00001000
mFTM2DEADTIME_DTVAL4 equ       %00010000
mFTM2DEADTIME_DTVAL5 equ       %00100000
mFTM2DEADTIME_DTPS0 equ       %01000000
mFTM2DEADTIME_DTPS1 equ       %10000000


;*** FTM2EXTTRIG - FTM2 ExternalTrigger Register
FTM2EXTTRIG         equ       $000018AC           ;*** FTM2EXTTRIG - FTM2 ExternalTrigger Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2EXTTRIG_INITTRIGEN equ       6                   ; Enables the Generation of a Trigger Signal
; bit position masks
mFTM2EXTTRIG_INITTRIGEN equ       %01000000


;*** FTM2POL - FTM2 Channels Polarity Register
FTM2POL             equ       $000018AD           ;*** FTM2POL - FTM2 Channels Polarity Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2POL_POL0        equ       0                   ; Channel 0 Polarity
FTM2POL_POL1        equ       1                   ; Channel 1 Polarity
FTM2POL_POL2        equ       2                   ; Channel 2 Polarity
FTM2POL_POL3        equ       3                   ; Channel 3 Polarity
FTM2POL_POL4        equ       4                   ; Channel 4 Polarity
FTM2POL_POL5        equ       5                   ; Channel 5 Polarity
; bit position masks
mFTM2POL_POL0       equ       %00000001
mFTM2POL_POL1       equ       %00000010
mFTM2POL_POL2       equ       %00000100
mFTM2POL_POL3       equ       %00001000
mFTM2POL_POL4       equ       %00010000
mFTM2POL_POL5       equ       %00100000


;*** FTM2FMS - FTM2 Fault Mode Status Register
FTM2FMS             equ       $000018AE           ;*** FTM2FMS - FTM2 Fault Mode Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2FMS_FAULTF0     equ       0                   ; Fault detection flag 0
FTM2FMS_FAULTF1     equ       1                   ; Fault detection flag 1
FTM2FMS_FAULTF2     equ       2                   ; Fault detection flag 2
FTM2FMS_FAULTF3     equ       3                   ; Fault detection flag 3
FTM2FMS_FAULTIN     equ       5                   ; Fault Input
FTM2FMS_WPEN        equ       6                   ; Write Protected Enable
FTM2FMS_FAULTF      equ       7                   ; Fault Detection Flag
; bit position masks
mFTM2FMS_FAULTF0    equ       %00000001
mFTM2FMS_FAULTF1    equ       %00000010
mFTM2FMS_FAULTF2    equ       %00000100
mFTM2FMS_FAULTF3    equ       %00001000
mFTM2FMS_FAULTIN    equ       %00100000
mFTM2FMS_WPEN       equ       %01000000
mFTM2FMS_FAULTF     equ       %10000000


;*** FTM2FILTER0 - FTM2 Input Capture Filter Control Register 0
FTM2FILTER0         equ       $000018AF           ;*** FTM2FILTER0 - FTM2 Input Capture Filter Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2FILTER0_CH0FVAL0 equ       0                   ; Channel 0 Input Filter Bits, bit 0
FTM2FILTER0_CH0FVAL1 equ       1                   ; Channel 0 Input Filter Bits, bit 1
FTM2FILTER0_CH0FVAL2 equ       2                   ; Channel 0 Input Filter Bits, bit 2
FTM2FILTER0_CH0FVAL3 equ       3                   ; Channel 0 Input Filter Bits, bit 3
FTM2FILTER0_CH1FVAL0 equ       4                   ; Channel 1 Input Filter Bits, bit 0
FTM2FILTER0_CH1FVAL1 equ       5                   ; Channel 1 Input Filter Bits, bit 1
FTM2FILTER0_CH1FVAL2 equ       6                   ; Channel 1 Input Filter Bits, bit 2
FTM2FILTER0_CH1FVAL3 equ       7                   ; Channel 1 Input Filter Bits, bit 3
; bit position masks
mFTM2FILTER0_CH0FVAL0 equ       %00000001
mFTM2FILTER0_CH0FVAL1 equ       %00000010
mFTM2FILTER0_CH0FVAL2 equ       %00000100
mFTM2FILTER0_CH0FVAL3 equ       %00001000
mFTM2FILTER0_CH1FVAL0 equ       %00010000
mFTM2FILTER0_CH1FVAL1 equ       %00100000
mFTM2FILTER0_CH1FVAL2 equ       %01000000
mFTM2FILTER0_CH1FVAL3 equ       %10000000


;*** FTM2FILTER1 - FTM2 Input Capture Filter Control Register 1
FTM2FILTER1         equ       $000018B0           ;*** FTM2FILTER1 - FTM2 Input Capture Filter Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2FILTER1_CH2FVAL0 equ       0                   ; Channel 2 Input Filter Bits, bit 0
FTM2FILTER1_CH2FVAL1 equ       1                   ; Channel 2 Input Filter Bits, bit 1
FTM2FILTER1_CH2FVAL2 equ       2                   ; Channel 2 Input Filter Bits, bit 2
FTM2FILTER1_CH2FVAL3 equ       3                   ; Channel 2 Input Filter Bits, bit 3
FTM2FILTER1_CH3FVAL0 equ       4                   ; Channel 3 Input Filter Bits, bit 0
FTM2FILTER1_CH3FVAL1 equ       5                   ; Channel 3 Input Filter Bits, bit 1
FTM2FILTER1_CH3FVAL2 equ       6                   ; Channel 3 Input Filter Bits, bit 2
FTM2FILTER1_CH3FVAL3 equ       7                   ; Channel 3 Input Filter Bits, bit 3
; bit position masks
mFTM2FILTER1_CH2FVAL0 equ       %00000001
mFTM2FILTER1_CH2FVAL1 equ       %00000010
mFTM2FILTER1_CH2FVAL2 equ       %00000100
mFTM2FILTER1_CH2FVAL3 equ       %00001000
mFTM2FILTER1_CH3FVAL0 equ       %00010000
mFTM2FILTER1_CH3FVAL1 equ       %00100000
mFTM2FILTER1_CH3FVAL2 equ       %01000000
mFTM2FILTER1_CH3FVAL3 equ       %10000000


;*** FTM2FLTFILTER - FTM2 Fault Input Filter Control Register
FTM2FLTFILTER       equ       $000018B1           ;*** FTM2FLTFILTER - FTM2 Fault Input Filter Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2FLTFILTER_FFVAL0 equ       0                   ; Fault Input Filter Bits, bit 0
FTM2FLTFILTER_FFVAL1 equ       1                   ; Fault Input Filter Bits, bit 1
FTM2FLTFILTER_FFVAL2 equ       2                   ; Fault Input Filter Bits, bit 2
FTM2FLTFILTER_FFVAL3 equ       3                   ; Fault Input Filter Bits, bit 3
; bit position masks
mFTM2FLTFILTER_FFVAL0 equ       %00000001
mFTM2FLTFILTER_FFVAL1 equ       %00000010
mFTM2FLTFILTER_FFVAL2 equ       %00000100
mFTM2FLTFILTER_FFVAL3 equ       %00001000


;*** FTM2FLTCTRL - FTM2 Fault Control Register
FTM2FLTCTRL         equ       $000018B2           ;*** FTM2FLTCTRL - FTM2 Fault Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2FLTCTRL_FAULT0EN equ       0                   ; Fault input 0 enable
FTM2FLTCTRL_FAULT1EN equ       1                   ; Fault input 1 enable
FTM2FLTCTRL_FAULT2EN equ       2                   ; Fault input 2 enable
FTM2FLTCTRL_FAULT3EN equ       3                   ; Fault input 3 enable
FTM2FLTCTRL_FFLTR0EN equ       4                   ; Fault input 0 filter enable
; bit position masks
mFTM2FLTCTRL_FAULT0EN equ       %00000001
mFTM2FLTCTRL_FAULT1EN equ       %00000010
mFTM2FLTCTRL_FAULT2EN equ       %00000100
mFTM2FLTCTRL_FAULT3EN equ       %00001000
mFTM2FLTCTRL_FFLTR0EN equ       %00010000


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
