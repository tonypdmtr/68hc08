;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08JM16_48, version 3.00.048 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08jm8.inc
;     Processor : MC9S08JM8CGT
;     FileFormat: V2.32
;     DataSheet : MC9S08JM16 Rev. 2 5/2008
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
;      - 8.11.2007, V3.00.0:
;              - Removed USB FIFO registers: FIFO0, F0BADDR, F0SIZE, F0CTL.
;              -   REASON: Changes in data sheet (from Ver 1.0 Draft D to Ver 1.0 Draft F).
;      - 10.04.2008, V3.00.1:
;              - Removed MCGT register.
;              -   REASON: For factory use only.
;      - 15.08.2008, V3.00.2:
;              - Removed bit SRS[ILAD].
;              -   REASON: Bug-fix(#6425 in Issue Manager).
;      - 6.11.2008, V3.00.3:
;              - Removed bits KBISC[3], KBIPE[3].
;              -   REASON: Changes in Data Sheet (from Rev 1.0, Draft F 9/2007 to Rev 2, 5/2008).
;
;     File-Format-Revisions:
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
ROM                 equ       $0000E000
ROM_END             equ       $0000FFAD
RAM                 equ       $000000B0
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $000004AF
RAM1                equ       $00001860
RAM1_END            equ       $0000195F
XROM                equ       $0000FFC0
XROM_END            equ       $0000FFC3
;
Vrtc                equ       $0000FFC4
Viic                equ       $0000FFC6
Vacmp               equ       $0000FFC8
Vadc                equ       $0000FFCA
Vkeyboard           equ       $0000FFCC
Vsci2tx             equ       $0000FFCE
Vsci2rx             equ       $0000FFD0
Vsci2err            equ       $0000FFD2
Vsci1tx             equ       $0000FFD4
Vsci1rx             equ       $0000FFD6
Vsci1err            equ       $0000FFD8
Vtpm2ovf            equ       $0000FFDA
Vtpm2ch1            equ       $0000FFDC
Vtpm2ch0            equ       $0000FFDE
Vtpm1ovf            equ       $0000FFE0
VReserved14         equ       $0000FFE2
VReserved13         equ       $0000FFE4
Vtpm1ch3            equ       $0000FFE6
Vtpm1ch2            equ       $0000FFE8
Vtpm1ch1            equ       $0000FFEA
Vtpm1ch0            equ       $0000FFEC
VReserved8          equ       $0000FFEE
Vusb                equ       $0000FFF0
Vspi2               equ       $0000FFF2
Vspi1               equ       $0000FFF4
Vlol                equ       $0000FFF6
Vlvd                equ       $0000FFF8
Virq                equ       $0000FFFA
Vswi                equ       $0000FFFC
Vreset              equ       $0000FFFE
;


;*** PTAD - Port A Data Register
PTAD                equ       $00000000           ;*** PTAD - Port A Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAD_PTAD0          equ       0                   ; Port A Data Register Bit 0
PTAD_PTAD5          equ       5                   ; Port A Data Register Bit 5
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD5         equ       %00100000


;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000001           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; Data Direction for Port A Bit 0
PTADD_PTADD5        equ       5                   ; Data Direction for Port A Bit 5
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD5       equ       %00100000


;*** PTBD - Port B Data Register
PTBD                equ       $00000002           ;*** PTBD - Port B Data Register
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


;*** PTBDD - Port B Data Direction Register
PTBDD               equ       $00000003           ;*** PTBDD - Port B Data Direction Register
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
PTCD                equ       $00000004           ;*** PTCD - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0          equ       0                   ; Port C Data Register Bit 0
PTCD_PTCD1          equ       1                   ; Port C Data Register Bit 1
PTCD_PTCD2          equ       2                   ; Port C Data Register Bit 2
PTCD_PTCD3          equ       3                   ; Port C Data Register Bit 3
PTCD_PTCD4          equ       4                   ; Port C Data Register Bit 4
PTCD_PTCD5          equ       5                   ; Port C Data Register Bit 5
; bit position masks
mPTCD_PTCD0         equ       %00000001
mPTCD_PTCD1         equ       %00000010
mPTCD_PTCD2         equ       %00000100
mPTCD_PTCD3         equ       %00001000
mPTCD_PTCD4         equ       %00010000
mPTCD_PTCD5         equ       %00100000


;*** PTCDD - Port C Data Direction Register
PTCDD               equ       $00000005           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; Data Direction for Port C Bit 0
PTCDD_PTCDD1        equ       1                   ; Data Direction for Port C Bit 1
PTCDD_PTCDD2        equ       2                   ; Data Direction for Port C Bit 2
PTCDD_PTCDD3        equ       3                   ; Data Direction for Port C Bit 3
PTCDD_PTCDD4        equ       4                   ; Data Direction for Port C Bit 4
PTCDD_PTCDD5        equ       5                   ; Data Direction for Port C Bit 5
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000
mPTCDD_PTCDD4       equ       %00010000
mPTCDD_PTCDD5       equ       %00100000


;*** PTDD - Port D Data Register
PTDD                equ       $00000006           ;*** PTDD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0          equ       0                   ; Port D Data Register Bit 0
PTDD_PTDD1          equ       1                   ; Port D Data Register Bit 1
PTDD_PTDD2          equ       2                   ; Port D Data Register Bit 2
PTDD_PTDD7          equ       7                   ; Port D Data Register Bit 7
; bit position masks
mPTDD_PTDD0         equ       %00000001
mPTDD_PTDD1         equ       %00000010
mPTDD_PTDD2         equ       %00000100
mPTDD_PTDD7         equ       %10000000


;*** PTDDD - Port D Data Direction Register
PTDDD               equ       $00000007           ;*** PTDDD - Port D Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0        equ       0                   ; Data Direction for Port D Bit 0
PTDDD_PTDDD1        equ       1                   ; Data Direction for Port D Bit 1
PTDDD_PTDDD2        equ       2                   ; Data Direction for Port D Bit 2
PTDDD_PTDDD7        equ       7                   ; Data Direction for Port D Bit 7
; bit position masks
mPTDDD_PTDDD0       equ       %00000001
mPTDDD_PTDDD1       equ       %00000010
mPTDDD_PTDDD2       equ       %00000100
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
PTEDD               equ       $00000009           ;*** PTEDD - Port E Data Direction Register
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


;*** PTFD - Port F Data Register
PTFD                equ       $0000000A           ;*** PTFD - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFD_PTFD0          equ       0                   ; Port F Data Register Bit 0
PTFD_PTFD1          equ       1                   ; Port F Data Register Bit 1
PTFD_PTFD4          equ       4                   ; Port F Data Register Bit 4
PTFD_PTFD5          equ       5                   ; Port F Data Register Bit 5
PTFD_PTFD6          equ       6                   ; Port F Data Register Bit 6
; bit position masks
mPTFD_PTFD0         equ       %00000001
mPTFD_PTFD1         equ       %00000010
mPTFD_PTFD4         equ       %00010000
mPTFD_PTFD5         equ       %00100000
mPTFD_PTFD6         equ       %01000000


;*** PTFDD - Port F Data Direction Register
PTFDD               equ       $0000000B           ;*** PTFDD - Port F Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDD_PTFDD0        equ       0                   ; Data Direction for Port F Bit 0
PTFDD_PTFDD1        equ       1                   ; Data Direction for Port F Bit 1
PTFDD_PTFDD4        equ       4                   ; Data Direction for Port F Bit 4
PTFDD_PTFDD5        equ       5                   ; Data Direction for Port F Bit 5
PTFDD_PTFDD6        equ       6                   ; Data Direction for Port F Bit 6
; bit position masks
mPTFDD_PTFDD0       equ       %00000001
mPTFDD_PTFDD1       equ       %00000010
mPTFDD_PTFDD4       equ       %00010000
mPTFDD_PTFDD5       equ       %00100000
mPTFDD_PTFDD6       equ       %01000000


;*** PTGD - Port G Data Register
PTGD                equ       $0000000C           ;*** PTGD - Port G Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGD_PTGD0          equ       0                   ; Port G Data Register Bit 0
PTGD_PTGD1          equ       1                   ; Port G Data Register Bit 1
PTGD_PTGD2          equ       2                   ; Port G Data Register Bit 2
PTGD_PTGD3          equ       3                   ; Port G Data Register Bit 3
PTGD_PTGD4          equ       4                   ; Port G Data Register Bit 4
PTGD_PTGD5          equ       5                   ; Port G Data Register Bit 5
; bit position masks
mPTGD_PTGD0         equ       %00000001
mPTGD_PTGD1         equ       %00000010
mPTGD_PTGD2         equ       %00000100
mPTGD_PTGD3         equ       %00001000
mPTGD_PTGD4         equ       %00010000
mPTGD_PTGD5         equ       %00100000


;*** PTGDD - Port G Data Direction Register
PTGDD               equ       $0000000D           ;*** PTGDD - Port G Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDD_PTGDD0        equ       0                   ; Data Direction for Port G Bit 0
PTGDD_PTGDD1        equ       1                   ; Data Direction for Port G Bit 1
PTGDD_PTGDD2        equ       2                   ; Data Direction for Port G Bit 2
PTGDD_PTGDD3        equ       3                   ; Data Direction for Port G Bit 3
PTGDD_PTGDD4        equ       4                   ; Data Direction for Port G Bit 4
PTGDD_PTGDD5        equ       5                   ; Data Direction for Port G Bit 5
; bit position masks
mPTGDD_PTGDD0       equ       %00000001
mPTGDD_PTGDD1       equ       %00000010
mPTGDD_PTGDD2       equ       %00000100
mPTGDD_PTGDD3       equ       %00001000
mPTGDD_PTGDD4       equ       %00010000
mPTGDD_PTGDD5       equ       %00100000


;*** ACMPSC - ACMP Status and Control Register
ACMPSC              equ       $0000000E           ;*** ACMPSC - ACMP Status and Control Register
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
; bit position masks
mAPCTL1_ADPC0       equ       %00000001
mAPCTL1_ADPC1       equ       %00000010
mAPCTL1_ADPC2       equ       %00000100
mAPCTL1_ADPC3       equ       %00001000
mAPCTL1_ADPC4       equ       %00010000
mAPCTL1_ADPC5       equ       %00100000


;*** APCTL2 - Pin Control 2 Register
APCTL2              equ       $00000018           ;*** APCTL2 - Pin Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL2_ADPC8        equ       0                   ; ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8
APCTL2_ADPC9        equ       1                   ; ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9
; bit position masks
mAPCTL2_ADPC8       equ       %00000001
mAPCTL2_ADPC9       equ       %00000010


;*** IRQSC - Interrupt request status and control register
IRQSC               equ       $0000001B           ;*** IRQSC - Interrupt request status and control register
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


;*** KBISC - KBI Status and Control Register
KBISC               equ       $0000001C           ;*** KBISC - KBI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBISC_KBMOD         equ       0                   ; Keyboard Detection Mode
KBISC_KBIE          equ       1                   ; Keyboard Interrupt Enable
KBISC_KBACK         equ       2                   ; Keyboard Interrupt Acknowledge
KBISC_KBF           equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBISC_KBMOD        equ       %00000001
mKBISC_KBIE         equ       %00000010
mKBISC_KBACK        equ       %00000100
mKBISC_KBF          equ       %00001000


;*** KBIPE - KBI Pin Enable Register
KBIPE               equ       $0000001D           ;*** KBIPE - KBI Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPE_KBIPE0        equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBIPE_KBIPE1        equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBIPE_KBIPE2        equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBIPE_KBIPE4        equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBIPE_KBIPE5        equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBIPE_KBIPE6        equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBIPE_KBIPE7        equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBIPE_KBIPE0       equ       %00000001
mKBIPE_KBIPE1       equ       %00000010
mKBIPE_KBIPE2       equ       %00000100
mKBIPE_KBIPE4       equ       %00010000
mKBIPE_KBIPE5       equ       %00100000
mKBIPE_KBIPE6       equ       %01000000
mKBIPE_KBIPE7       equ       %10000000


;*** KBIES - KBI Edge Select Register
KBIES               equ       $0000001E           ;*** KBIES - KBI Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIES_KBEDG0        equ       0                   ; Keyboard Edge Select Bit 0
KBIES_KBEDG1        equ       1                   ; Keyboard Edge Select Bit 1
KBIES_KBEDG2        equ       2                   ; Keyboard Edge Select Bit 2
KBIES_KBEDG4        equ       4                   ; Keyboard Edge Select Bit 4
KBIES_KBEDG5        equ       5                   ; Keyboard Edge Select Bit 5
KBIES_KBEDG6        equ       6                   ; Keyboard Edge Select Bit 6
KBIES_KBEDG7        equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBIES_KBEDG0       equ       %00000001
mKBIES_KBEDG1       equ       %00000010
mKBIES_KBEDG2       equ       %00000100
mKBIES_KBEDG4       equ       %00010000
mKBIES_KBEDG5       equ       %00100000
mKBIES_KBEDG6       equ       %01000000
mKBIES_KBEDG7       equ       %10000000


;*** TPM1SC - TPM1 Status and Control Register
TPM1SC              equ       $00000020           ;*** TPM1SC - TPM1 Status and Control Register
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
TPM1CNT             equ       $00000021           ;*** TPM1CNT - TPM1 Timer Counter Register


;*** TPM1CNTH - TPM1 Timer Counter Register High
TPM1CNTH            equ       $00000021           ;*** TPM1CNTH - TPM1 Timer Counter Register High


;*** TPM1CNTL - TPM1 Timer Counter Register Low
TPM1CNTL            equ       $00000022           ;*** TPM1CNTL - TPM1 Timer Counter Register Low


;*** TPM1MOD - TPM1 Timer Counter Modulo Register
TPM1MOD             equ       $00000023           ;*** TPM1MOD - TPM1 Timer Counter Modulo Register


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High
TPM1MODH            equ       $00000023           ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low
TPM1MODL            equ       $00000024           ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $00000025           ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
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
TPM1C0V             equ       $00000026           ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $00000026           ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $00000027           ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $00000028           ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
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
TPM1C1V             equ       $00000029           ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $00000029           ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $0000002A           ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low


;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register
TPM1C2SC            equ       $0000002B           ;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C2SC_ELS2A      equ       2                   ; Edge/Level Select Bit A
TPM1C2SC_ELS2B      equ       3                   ; Edge/Level Select Bit B
TPM1C2SC_MS2A       equ       4                   ; Mode Select A for TPM Channel 2
TPM1C2SC_MS2B       equ       5                   ; Mode Select B for TPM Channel 2
TPM1C2SC_CH2IE      equ       6                   ; Channel 2 Interrupt Enable
TPM1C2SC_CH2F       equ       7                   ; Channel 2 Flag
; bit position masks
mTPM1C2SC_ELS2A     equ       %00000100
mTPM1C2SC_ELS2B     equ       %00001000
mTPM1C2SC_MS2A      equ       %00010000
mTPM1C2SC_MS2B      equ       %00100000
mTPM1C2SC_CH2IE     equ       %01000000
mTPM1C2SC_CH2F      equ       %10000000


;*** TPM1C2V - TPM1 Timer Channel 2 Value Register
TPM1C2V             equ       $0000002C           ;*** TPM1C2V - TPM1 Timer Channel 2 Value Register


;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High
TPM1C2VH            equ       $0000002C           ;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High


;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low
TPM1C2VL            equ       $0000002D           ;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low


;*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register
TPM1C3SC            equ       $0000002E           ;*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C3SC_ELS3A      equ       2                   ; Edge/Level Select Bit A
TPM1C3SC_ELS3B      equ       3                   ; Edge/Level Select Bit B
TPM1C3SC_MS3A       equ       4                   ; Mode Select A for TPM Channel 3
TPM1C3SC_MS3B       equ       5                   ; Mode Select B for TPM Channel 3
TPM1C3SC_CH3IE      equ       6                   ; Channel 3 Interrupt Enable
TPM1C3SC_CH3F       equ       7                   ; Channel 3 Flag
; bit position masks
mTPM1C3SC_ELS3A     equ       %00000100
mTPM1C3SC_ELS3B     equ       %00001000
mTPM1C3SC_MS3A      equ       %00010000
mTPM1C3SC_MS3B      equ       %00100000
mTPM1C3SC_CH3IE     equ       %01000000
mTPM1C3SC_CH3F      equ       %10000000


;*** TPM1C3V - TPM1 Timer Channel 3 Value Register
TPM1C3V             equ       $0000002F           ;*** TPM1C3V - TPM1 Timer Channel 3 Value Register


;*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High
TPM1C3VH            equ       $0000002F           ;*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High


;*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low
TPM1C3VL            equ       $00000030           ;*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low


;*** SCI1BD - SCI1 Baud Rate Register
SCI1BD              equ       $00000038           ;*** SCI1BD - SCI1 Baud Rate Register


;*** SCI1BDH - SCI1 Baud Rate Register High
SCI1BDH             equ       $00000038           ;*** SCI1BDH - SCI1 Baud Rate Register High
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
SCI1BDL             equ       $00000039           ;*** SCI1BDL - SCI1 Baud Rate Register Low
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
SCI1C1              equ       $0000003A           ;*** SCI1C1 - SCI1 Control Register 1
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
SCI1C2              equ       $0000003B           ;*** SCI1C2 - SCI1 Control Register 2
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
SCI1S1              equ       $0000003C           ;*** SCI1S1 - SCI1 Status Register 1
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
SCI1S2              equ       $0000003D           ;*** SCI1S2 - SCI1 Status Register 2
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
SCI1C3              equ       $0000003E           ;*** SCI1C3 - SCI1 Control Register 3
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
SCI1D               equ       $0000003F           ;*** SCI1D - SCI1 Data Register
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
SCI2BD              equ       $00000040           ;*** SCI2BD - SCI2 Baud Rate Register


;*** SCI2BDH - SCI2 Baud Rate Register High
SCI2BDH             equ       $00000040           ;*** SCI2BDH - SCI2 Baud Rate Register High
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
SCI2BDL             equ       $00000041           ;*** SCI2BDL - SCI2 Baud Rate Register Low
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
SCI2C1              equ       $00000042           ;*** SCI2C1 - SCI2 Control Register 1
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
SCI2C2              equ       $00000043           ;*** SCI2C2 - SCI2 Control Register 2
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
SCI2S1              equ       $00000044           ;*** SCI2S1 - SCI2 Status Register 1
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
SCI2S2              equ       $00000045           ;*** SCI2S2 - SCI2 Status Register 2
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
SCI2C3              equ       $00000046           ;*** SCI2C3 - SCI2 Control Register 3
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
SCI2D               equ       $00000047           ;*** SCI2D - SCI2 Data Register
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


;*** MCGC1 - MCG Control Register 1
MCGC1               equ       $00000048           ;*** MCGC1 - MCG Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC1_IREFSTEN      equ       0                   ; Internal Reference Stop Enable
MCGC1_IRCLKEN       equ       1                   ; Internal Reference Clock Enable
MCGC1_IREFS         equ       2                   ; Internal Reference Select
MCGC1_RDIV0         equ       3                   ; Reference Divider, bit 0
MCGC1_RDIV1         equ       4                   ; Reference Divider, bit 1
MCGC1_RDIV2         equ       5                   ; Reference Divider, bit 2
MCGC1_CLKS0         equ       6                   ; Clock Source Select, bit 0
MCGC1_CLKS1         equ       7                   ; Clock Source Select, bit 1
; bit position masks
mMCGC1_IREFSTEN     equ       %00000001
mMCGC1_IRCLKEN      equ       %00000010
mMCGC1_IREFS        equ       %00000100
mMCGC1_RDIV0        equ       %00001000
mMCGC1_RDIV1        equ       %00010000
mMCGC1_RDIV2        equ       %00100000
mMCGC1_CLKS0        equ       %01000000
mMCGC1_CLKS1        equ       %10000000


;*** MCGC2 - MCG Control Register 2
MCGC2               equ       $00000049           ;*** MCGC2 - MCG Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC2_EREFSTEN      equ       0                   ; External Reference Stop Enable
MCGC2_ERCLKEN       equ       1                   ; External Reference Enable
MCGC2_EREFS         equ       2                   ; External Reference Select
MCGC2_LP            equ       3                   ; Low Power Select
MCGC2_HGO           equ       4                   ; High Gain Oscillator Select
MCGC2_RANGE         equ       5                   ; Frequency Range Select
MCGC2_BDIV0         equ       6                   ; Bus Frequency Divider, bit 0
MCGC2_BDIV1         equ       7                   ; Bus Frequency Divider, bit 1
; bit position masks
mMCGC2_EREFSTEN     equ       %00000001
mMCGC2_ERCLKEN      equ       %00000010
mMCGC2_EREFS        equ       %00000100
mMCGC2_LP           equ       %00001000
mMCGC2_HGO          equ       %00010000
mMCGC2_RANGE        equ       %00100000
mMCGC2_BDIV0        equ       %01000000
mMCGC2_BDIV1        equ       %10000000


;*** MCGTRM - MCG Trim Register
MCGTRM              equ       $0000004A           ;*** MCGTRM - MCG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGTRM_TRIM0        equ       0                   ; MCG Trim Setting, bit 0
MCGTRM_TRIM1        equ       1                   ; MCG Trim Setting, bit 1
MCGTRM_TRIM2        equ       2                   ; MCG Trim Setting, bit 2
MCGTRM_TRIM3        equ       3                   ; MCG Trim Setting, bit 3
MCGTRM_TRIM4        equ       4                   ; MCG Trim Setting, bit 4
MCGTRM_TRIM5        equ       5                   ; MCG Trim Setting, bit 5
MCGTRM_TRIM6        equ       6                   ; MCG Trim Setting, bit 6
MCGTRM_TRIM7        equ       7                   ; MCG Trim Setting, bit 7
; bit position masks
mMCGTRM_TRIM0       equ       %00000001
mMCGTRM_TRIM1       equ       %00000010
mMCGTRM_TRIM2       equ       %00000100
mMCGTRM_TRIM3       equ       %00001000
mMCGTRM_TRIM4       equ       %00010000
mMCGTRM_TRIM5       equ       %00100000
mMCGTRM_TRIM6       equ       %01000000
mMCGTRM_TRIM7       equ       %10000000


;*** MCGSC - MCG Status and Control Register
MCGSC               equ       $0000004B           ;*** MCGSC - MCG Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGSC_FTRIM         equ       0                   ; MCG Fine Trim
MCGSC_OSCINIT       equ       1                   ; OSC Initialization
MCGSC_CLKST0        equ       2                   ; Clock Mode Status, bit 0
MCGSC_CLKST1        equ       3                   ; Clock Mode Status, bit 1
MCGSC_IREFST        equ       4                   ; Internal Reference Status
MCGSC_PLLST         equ       5                   ; PLL Select Status
MCGSC_LOCK          equ       6                   ; Lock Status
MCGSC_LOLS          equ       7                   ; Loss of Lock Status
; bit position masks
mMCGSC_FTRIM        equ       %00000001
mMCGSC_OSCINIT      equ       %00000010
mMCGSC_CLKST0       equ       %00000100
mMCGSC_CLKST1       equ       %00001000
mMCGSC_IREFST       equ       %00010000
mMCGSC_PLLST        equ       %00100000
mMCGSC_LOCK         equ       %01000000
mMCGSC_LOLS         equ       %10000000


;*** MCGC3 - MCG Control Register 3
MCGC3               equ       $0000004C           ;*** MCGC3 - MCG Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC3_VDIV0         equ       0                   ; VCO Divider, bit 0
MCGC3_VDIV1         equ       1                   ; VCO Divider, bit 1
MCGC3_VDIV2         equ       2                   ; VCO Divider, bit 2
MCGC3_VDIV3         equ       3                   ; VCO Divider, bit 3
MCGC3_CME           equ       5                   ; Clock Monitor Enable
MCGC3_PLLS          equ       6                   ; PLL Select
MCGC3_LOLIE         equ       7                   ; Loss of Lock Interrupt Enable
; bit position masks
mMCGC3_VDIV0        equ       %00000001
mMCGC3_VDIV1        equ       %00000010
mMCGC3_VDIV2        equ       %00000100
mMCGC3_VDIV3        equ       %00001000
mMCGC3_CME          equ       %00100000
mMCGC3_PLLS         equ       %01000000
mMCGC3_LOLIE        equ       %10000000


;*** SPI1C1 - SPI1 Control Register 1
SPI1C1              equ       $00000050           ;*** SPI1C1 - SPI1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C1_LSBFE        equ       0                   ; LSB First (Shifter Direction)
SPI1C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI1C1_CPHA         equ       2                   ; Clock Phase
SPI1C1_CPOL         equ       3                   ; Clock Polarity
SPI1C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI1C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI1C1_SPE          equ       6                   ; SPI System Enable
SPI1C1_SPIE         equ       7                   ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI1C1_LSBFE       equ       %00000001
mSPI1C1_SSOE        equ       %00000010
mSPI1C1_CPHA        equ       %00000100
mSPI1C1_CPOL        equ       %00001000
mSPI1C1_MSTR        equ       %00010000
mSPI1C1_SPTIE       equ       %00100000
mSPI1C1_SPE         equ       %01000000
mSPI1C1_SPIE        equ       %10000000


;*** SPI1C2 - SPI1 Control Register 2
SPI1C2              equ       $00000051           ;*** SPI1C2 - SPI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI1C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI1C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI1C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
SPI1C2_SPIMODE      equ       6                   ; SPI 8- or 16-bit Mode Select
SPI1C2_SPMIE        equ       7                   ; SPI Match Interrupt Enable
; bit position masks
mSPI1C2_SPC0        equ       %00000001
mSPI1C2_SPISWAI     equ       %00000010
mSPI1C2_BIDIROE     equ       %00001000
mSPI1C2_MODFEN      equ       %00010000
mSPI1C2_SPIMODE     equ       %01000000
mSPI1C2_SPMIE       equ       %10000000


;*** SPI1BR - SPI1 Baud Rate Register
SPI1BR              equ       $00000052           ;*** SPI1BR - SPI1 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI1BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI1BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI1BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2        equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0        equ       %00000001
mSPI1BR_SPR1        equ       %00000010
mSPI1BR_SPR2        equ       %00000100
mSPI1BR_SPPR0       equ       %00010000
mSPI1BR_SPPR1       equ       %00100000
mSPI1BR_SPPR2       equ       %01000000


;*** SPI1S - SPI1 Status Register
SPI1S               equ       $00000053           ;*** SPI1S - SPI1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF          equ       4                   ; Master Mode Fault Flag
SPI1S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI1S_SPMF          equ       6                   ; SPI Match Flag
SPI1S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_MODF         equ       %00010000
mSPI1S_SPTEF        equ       %00100000
mSPI1S_SPMF         equ       %01000000
mSPI1S_SPRF         equ       %10000000


;*** SPI1D16 - SPI1 Data Register
SPI1D16             equ       $00000054           ;*** SPI1D16 - SPI1 Data Register


;*** SPI1DH - SPI1 Data Register High
SPI1DH              equ       $00000054           ;*** SPI1DH - SPI1 Data Register High


;*** SPI1DL - SPI1 Data Register Low
SPI1DL              equ       $00000055           ;*** SPI1DL - SPI1 Data Register Low


;*** SPI1D - SPI1 Data Register Low
SPI1D               equ       $00000055           ;*** SPI1D - SPI1 Data Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1D_Bit0          equ       0                   ; SPI Data Bit 0
SPI1D_Bit1          equ       1                   ; SPI Data Bit 1
SPI1D_Bit2          equ       2                   ; SPI Data Bit 2
SPI1D_Bit3          equ       3                   ; SPI Data Bit 3
SPI1D_Bit4          equ       4                   ; SPI Data Bit 4
SPI1D_Bit5          equ       5                   ; SPI Data Bit 5
SPI1D_Bit6          equ       6                   ; SPI Data Bit 6
SPI1D_Bit7          equ       7                   ; SPI Data Bit 7
; bit position masks
mSPI1D_Bit0         equ       %00000001
mSPI1D_Bit1         equ       %00000010
mSPI1D_Bit2         equ       %00000100
mSPI1D_Bit3         equ       %00001000
mSPI1D_Bit4         equ       %00010000
mSPI1D_Bit5         equ       %00100000
mSPI1D_Bit6         equ       %01000000
mSPI1D_Bit7         equ       %10000000


;*** SPI1M - SPI1 Match Register
SPI1M               equ       $00000056           ;*** SPI1M - SPI1 Match Register


;*** SPI1MH - SPI1 Match Register High
SPI1MH              equ       $00000056           ;*** SPI1MH - SPI1 Match Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1MH_Bit8         equ       0                   ; SPI Match Value Bit 8
SPI1MH_Bit9         equ       1                   ; SPI Match Value Bit 9
SPI1MH_Bit10        equ       2                   ; SPI Match Value Bit 10
SPI1MH_Bit11        equ       3                   ; SPI Match Value Bit 11
SPI1MH_Bit12        equ       4                   ; SPI Match Value Bit 12
SPI1MH_Bit13        equ       5                   ; SPI Match Value Bit 13
SPI1MH_Bit14        equ       6                   ; SPI Match Value Bit 14
SPI1MH_Bit15        equ       7                   ; SPI Match Value Bit 15
; bit position masks
mSPI1MH_Bit8        equ       %00000001
mSPI1MH_Bit9        equ       %00000010
mSPI1MH_Bit10       equ       %00000100
mSPI1MH_Bit11       equ       %00001000
mSPI1MH_Bit12       equ       %00010000
mSPI1MH_Bit13       equ       %00100000
mSPI1MH_Bit14       equ       %01000000
mSPI1MH_Bit15       equ       %10000000


;*** SPI1ML - SPI1 Match Register Low
SPI1ML              equ       $00000057           ;*** SPI1ML - SPI1 Match Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1ML_Bit0         equ       0                   ; SPI Match Value Bit 0
SPI1ML_Bit1         equ       1                   ; SPI Match Value Bit 1
SPI1ML_Bit2         equ       2                   ; SPI Match Value Bit 2
SPI1ML_Bit3         equ       3                   ; SPI Match Value Bit 3
SPI1ML_Bit4         equ       4                   ; SPI Match Value Bit 4
SPI1ML_Bit5         equ       5                   ; SPI Match Value Bit 5
SPI1ML_Bit6         equ       6                   ; SPI Match Value Bit 6
SPI1ML_Bit7         equ       7                   ; SPI Match Value Bit 7
; bit position masks
mSPI1ML_Bit0        equ       %00000001
mSPI1ML_Bit1        equ       %00000010
mSPI1ML_Bit2        equ       %00000100
mSPI1ML_Bit3        equ       %00001000
mSPI1ML_Bit4        equ       %00010000
mSPI1ML_Bit5        equ       %00100000
mSPI1ML_Bit6        equ       %01000000
mSPI1ML_Bit7        equ       %10000000


;*** IICA - IIC Address Register
IICA                equ       $00000058           ;*** IICA - IIC Address Register
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
IICF                equ       $00000059           ;*** IICF - IIC Frequency Divider Register
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
IICC1               equ       $0000005A           ;*** IICC1 - IIC Control Register 1
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
IICC                equ       $0000005A           ;*** IICC - IIC Control Register
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
IICS                equ       $0000005B           ;*** IICS - IIC Status Register
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
IICD                equ       $0000005C           ;*** IICD - IIC Data I/O Register
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
IICC2               equ       $0000005D           ;*** IICC2 - IIC Control Register 2
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


;*** TPM2SC - TPM2 Status and Control Register
TPM2SC              equ       $00000060           ;*** TPM2SC - TPM2 Status and Control Register
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
TPM2CNT             equ       $00000061           ;*** TPM2CNT - TPM2 Timer Counter Register


;*** TPM2CNTH - TPM2 Timer Counter Register High
TPM2CNTH            equ       $00000061           ;*** TPM2CNTH - TPM2 Timer Counter Register High


;*** TPM2CNTL - TPM2 Timer Counter Register Low
TPM2CNTL            equ       $00000062           ;*** TPM2CNTL - TPM2 Timer Counter Register Low


;*** TPM2MOD - TPM2 Timer Counter Modulo Register
TPM2MOD             equ       $00000063           ;*** TPM2MOD - TPM2 Timer Counter Modulo Register


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High
TPM2MODH            equ       $00000063           ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low
TPM2MODL            equ       $00000064           ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $00000065           ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
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
TPM2C0V             equ       $00000066           ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $00000066           ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $00000067           ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
TPM2C1SC            equ       $00000068           ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
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
TPM2C1V             equ       $00000069           ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High
TPM2C1VH            equ       $00000069           ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low
TPM2C1VL            equ       $0000006A           ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low


;*** RTCSC - RTC Status and Control Register
RTCSC               equ       $0000006C           ;*** RTCSC - RTC Status and Control Register
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
RTCCNT              equ       $0000006D           ;*** RTCCNT - RTC Counter Register


;*** RTCMOD - RTC Modulo Register
RTCMOD              equ       $0000006E           ;*** RTCMOD - RTC Modulo Register


;*** SPI2C1 - SPI2 Control Register 1
SPI2C1              equ       $00000070           ;*** SPI2C1 - SPI2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C1_LSBFE        equ       0                   ; LSB First (Shifter Direction)
SPI2C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI2C1_CPHA         equ       2                   ; Clock Phase
SPI2C1_CPOL         equ       3                   ; Clock Polarity
SPI2C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI2C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI2C1_SPE          equ       6                   ; SPI System Enable
SPI2C1_SPIE         equ       7                   ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI2C1_LSBFE       equ       %00000001
mSPI2C1_SSOE        equ       %00000010
mSPI2C1_CPHA        equ       %00000100
mSPI2C1_CPOL        equ       %00001000
mSPI2C1_MSTR        equ       %00010000
mSPI2C1_SPTIE       equ       %00100000
mSPI2C1_SPE         equ       %01000000
mSPI2C1_SPIE        equ       %10000000


;*** SPI2C2 - SPI2 Control Register 2
SPI2C2              equ       $00000071           ;*** SPI2C2 - SPI2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI2C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI2C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI2C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
SPI2C2_SPIMODE      equ       6                   ; SPI 8- or 16-bit Mode Select
SPI2C2_SPMIE        equ       7                   ; SPI Match Interrupt Enable
; bit position masks
mSPI2C2_SPC0        equ       %00000001
mSPI2C2_SPISWAI     equ       %00000010
mSPI2C2_BIDIROE     equ       %00001000
mSPI2C2_MODFEN      equ       %00010000
mSPI2C2_SPIMODE     equ       %01000000
mSPI2C2_SPMIE       equ       %10000000


;*** SPI2BR - SPI2 Baud Rate Register
SPI2BR              equ       $00000072           ;*** SPI2BR - SPI2 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI2BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI2BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI2BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI2BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI2BR_SPPR2        equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI2BR_SPR0        equ       %00000001
mSPI2BR_SPR1        equ       %00000010
mSPI2BR_SPR2        equ       %00000100
mSPI2BR_SPPR0       equ       %00010000
mSPI2BR_SPPR1       equ       %00100000
mSPI2BR_SPPR2       equ       %01000000


;*** SPI2S - SPI2 Status Register
SPI2S               equ       $00000073           ;*** SPI2S - SPI2 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_MODF          equ       4                   ; Master Mode Fault Flag
SPI2S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI2S_SPMF          equ       6                   ; SPI Match Flag
SPI2S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI2S_MODF         equ       %00010000
mSPI2S_SPTEF        equ       %00100000
mSPI2S_SPMF         equ       %01000000
mSPI2S_SPRF         equ       %10000000


;*** SPI2D16 - SPI2 Data Register
SPI2D16             equ       $00000074           ;*** SPI2D16 - SPI2 Data Register


;*** SPI2DH - SPI2 Data Register High
SPI2DH              equ       $00000074           ;*** SPI2DH - SPI2 Data Register High


;*** SPI2DL - SPI2 Data Register Low
SPI2DL              equ       $00000075           ;*** SPI2DL - SPI2 Data Register Low


;*** SPI2D - SPI2 Data Register Low
SPI2D               equ       $00000075           ;*** SPI2D - SPI2 Data Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2D_Bit0          equ       0                   ; SPI Data Bit 0
SPI2D_Bit1          equ       1                   ; SPI Data Bit 1
SPI2D_Bit2          equ       2                   ; SPI Data Bit 2
SPI2D_Bit3          equ       3                   ; SPI Data Bit 3
SPI2D_Bit4          equ       4                   ; SPI Data Bit 4
SPI2D_Bit5          equ       5                   ; SPI Data Bit 5
SPI2D_Bit6          equ       6                   ; SPI Data Bit 6
SPI2D_Bit7          equ       7                   ; SPI Data Bit 7
; bit position masks
mSPI2D_Bit0         equ       %00000001
mSPI2D_Bit1         equ       %00000010
mSPI2D_Bit2         equ       %00000100
mSPI2D_Bit3         equ       %00001000
mSPI2D_Bit4         equ       %00010000
mSPI2D_Bit5         equ       %00100000
mSPI2D_Bit6         equ       %01000000
mSPI2D_Bit7         equ       %10000000


;*** SPI2M - SPI2 Match Register
SPI2M               equ       $00000076           ;*** SPI2M - SPI2 Match Register


;*** SPI2MH - SPI2 Match Register High
SPI2MH              equ       $00000076           ;*** SPI2MH - SPI2 Match Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2MH_Bit8         equ       0                   ; SPI Match Value Bit 8
SPI2MH_Bit9         equ       1                   ; SPI Match Value Bit 9
SPI2MH_Bit10        equ       2                   ; SPI Match Value Bit 10
SPI2MH_Bit11        equ       3                   ; SPI Match Value Bit 11
SPI2MH_Bit12        equ       4                   ; SPI Match Value Bit 12
SPI2MH_Bit13        equ       5                   ; SPI Match Value Bit 13
SPI2MH_Bit14        equ       6                   ; SPI Match Value Bit 14
SPI2MH_Bit15        equ       7                   ; SPI Match Value Bit 15
; bit position masks
mSPI2MH_Bit8        equ       %00000001
mSPI2MH_Bit9        equ       %00000010
mSPI2MH_Bit10       equ       %00000100
mSPI2MH_Bit11       equ       %00001000
mSPI2MH_Bit12       equ       %00010000
mSPI2MH_Bit13       equ       %00100000
mSPI2MH_Bit14       equ       %01000000
mSPI2MH_Bit15       equ       %10000000


;*** SPI2ML - SPI2 Match Register Low
SPI2ML              equ       $00000077           ;*** SPI2ML - SPI2 Match Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2ML_Bit0         equ       0                   ; SPI Match Value Bit 0
SPI2ML_Bit1         equ       1                   ; SPI Match Value Bit 1
SPI2ML_Bit2         equ       2                   ; SPI Match Value Bit 2
SPI2ML_Bit3         equ       3                   ; SPI Match Value Bit 3
SPI2ML_Bit4         equ       4                   ; SPI Match Value Bit 4
SPI2ML_Bit5         equ       5                   ; SPI Match Value Bit 5
SPI2ML_Bit6         equ       6                   ; SPI Match Value Bit 6
SPI2ML_Bit7         equ       7                   ; SPI Match Value Bit 7
; bit position masks
mSPI2ML_Bit0        equ       %00000001
mSPI2ML_Bit1        equ       %00000010
mSPI2ML_Bit2        equ       %00000100
mSPI2ML_Bit3        equ       %00001000
mSPI2ML_Bit4        equ       %00010000
mSPI2ML_Bit5        equ       %00100000
mSPI2ML_Bit6        equ       %01000000
mSPI2ML_Bit7        equ       %10000000


;*** USBCTL0 - USB Control Register 0
USBCTL0             equ       $00000080           ;*** USBCTL0 - USB Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
USBCTL0_USBPHYEN    equ       0                   ; USB PHY Tranceiver Enable
USBCTL0_USBVREN     equ       2                   ; USB Voltage Regulator Enable
USBCTL0_LPRESF      equ       4                   ; Low-Power Resume Flag
USBCTL0_USBRESMEN   equ       5                   ; USB Low-Power Resume Event Enable
USBCTL0_USBPU       equ       6                   ; Pull Up Source
USBCTL0_USBRESET    equ       7                   ; USB Reset
; bit position masks
mUSBCTL0_USBPHYEN   equ       %00000001
mUSBCTL0_USBVREN    equ       %00000100
mUSBCTL0_LPRESF     equ       %00010000
mUSBCTL0_USBRESMEN  equ       %00100000
mUSBCTL0_USBPU      equ       %01000000
mUSBCTL0_USBRESET   equ       %10000000


;*** PERID - Peripheral ID Register
PERID               equ       $00000088           ;*** PERID - Peripheral ID Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PERID_ID0           equ       0                   ; Peripheral Configuration Number Bit 0
PERID_ID1           equ       1                   ; Peripheral Configuration Number Bit 1
PERID_ID2           equ       2                   ; Peripheral Configuration Number Bit 2
PERID_ID3           equ       3                   ; Peripheral Configuration Number Bit 3
PERID_ID4           equ       4                   ; Peripheral Configuration Number Bit 4
PERID_ID5           equ       5                   ; Peripheral Configuration Number Bit 5
; bit position masks
mPERID_ID0          equ       %00000001
mPERID_ID1          equ       %00000010
mPERID_ID2          equ       %00000100
mPERID_ID3          equ       %00001000
mPERID_ID4          equ       %00010000
mPERID_ID5          equ       %00100000


;*** IDCOMP - Peripheral ID Complement Register
IDCOMP              equ       $00000089           ;*** IDCOMP - Peripheral ID Complement Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IDCOMP_NID0         equ       0                   ; Complement ID Number Bit 0
IDCOMP_NID1         equ       1                   ; Complement ID Number Bit 1
IDCOMP_NID2         equ       2                   ; Complement ID Number Bit 2
IDCOMP_NID3         equ       3                   ; Complement ID Number Bit 3
IDCOMP_NID4         equ       4                   ; Complement ID Number Bit 4
IDCOMP_NID5         equ       5                   ; Complement ID Number Bit 5
; bit position masks
mIDCOMP_NID0        equ       %00000001
mIDCOMP_NID1        equ       %00000010
mIDCOMP_NID2        equ       %00000100
mIDCOMP_NID3        equ       %00001000
mIDCOMP_NID4        equ       %00010000
mIDCOMP_NID5        equ       %00100000


;*** REV - Peripheral Revision Register
REV                 equ       $0000008A           ;*** REV - Peripheral Revision Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
REV_REV0            equ       0                   ; Revision Bit 0
REV_REV1            equ       1                   ; Revision Bit 1
REV_REV2            equ       2                   ; Revision Bit 2
REV_REV3            equ       3                   ; Revision Bit 3
REV_REV4            equ       4                   ; Revision Bit 4
REV_REV5            equ       5                   ; Revision Bit 5
REV_REV6            equ       6                   ; Revision Bit 6
REV_REV7            equ       7                   ; Revision Bit 7
; bit position masks
mREV_REV0           equ       %00000001
mREV_REV1           equ       %00000010
mREV_REV2           equ       %00000100
mREV_REV3           equ       %00001000
mREV_REV4           equ       %00010000
mREV_REV5           equ       %00100000
mREV_REV6           equ       %01000000
mREV_REV7           equ       %10000000


;*** INTSTAT - Interrupt Status Register
INTSTAT             equ       $00000090           ;*** INTSTAT - Interrupt Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSTAT_USBRSTF     equ       0                   ; USB Reset Flag
INTSTAT_ERRORF      equ       1                   ; Error Flag
INTSTAT_SOFTOKF     equ       2                   ; SOF Token Flag
INTSTAT_TOKDNEF     equ       3                   ; Token Complete Flag
INTSTAT_SLEEPF      equ       4                   ; Sleep Flag
INTSTAT_RESUMEF     equ       5                   ; Resume Flag
INTSTAT_STALLF      equ       7                   ; Stall Flag
; bit position masks
mINTSTAT_USBRSTF    equ       %00000001
mINTSTAT_ERRORF     equ       %00000010
mINTSTAT_SOFTOKF    equ       %00000100
mINTSTAT_TOKDNEF    equ       %00001000
mINTSTAT_SLEEPF     equ       %00010000
mINTSTAT_RESUMEF    equ       %00100000
mINTSTAT_STALLF     equ       %10000000


;*** INTENB - Interrupt Enable Register
INTENB              equ       $00000091           ;*** INTENB - Interrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTENB_USBRST       equ       0                   ; USBRST Interrupt Enable
INTENB_ERROR        equ       1                   ; ERROR Interrupt Enable
INTENB_SOFTOK       equ       2                   ; SOFTOK Interrupt Enable
INTENB_TOKDNE       equ       3                   ; TOKDNE Interrupt Enable
INTENB_SLEEP        equ       4                   ; SLEEP Interrupt Enable
INTENB_RESUME       equ       5                   ; RESUME Interrupt Enable
INTENB_STALL        equ       7                   ; STALL Interrupt Enable
; bit position masks
mINTENB_USBRST      equ       %00000001
mINTENB_ERROR       equ       %00000010
mINTENB_SOFTOK      equ       %00000100
mINTENB_TOKDNE      equ       %00001000
mINTENB_SLEEP       equ       %00010000
mINTENB_RESUME      equ       %00100000
mINTENB_STALL       equ       %10000000


;*** ERRSTAT - Error Interrupt Status Register
ERRSTAT             equ       $00000092           ;*** ERRSTAT - Error Interrupt Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ERRSTAT_PIDERRF     equ       0                   ; PID Error Flag
ERRSTAT_CRC5F       equ       1                   ; CRC5 Error Flag
ERRSTAT_CRC16F      equ       2                   ; CRC16 Error Flag
ERRSTAT_DFN8F       equ       3                   ; Data Field Error Flag
ERRSTAT_BTOERRF     equ       4                   ; Bus Turnaround Error Timeout Flag
ERRSTAT_BUFERRF     equ       5                   ; Buffer Error Flag
ERRSTAT_BTSERRF     equ       7                   ; Bit Stuff Error Flag
; bit position masks
mERRSTAT_PIDERRF    equ       %00000001
mERRSTAT_CRC5F      equ       %00000010
mERRSTAT_CRC16F     equ       %00000100
mERRSTAT_DFN8F      equ       %00001000
mERRSTAT_BTOERRF    equ       %00010000
mERRSTAT_BUFERRF    equ       %00100000
mERRSTAT_BTSERRF    equ       %10000000


;*** ERRENB - Error Interrupt Enable Register
ERRENB              equ       $00000093           ;*** ERRENB - Error Interrupt Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ERRENB_PIDERR       equ       0                   ; PIDERR Interrupt Enable
ERRENB_CRC5         equ       1                   ; CRC5 Interrupt Enable
ERRENB_CRC16        equ       2                   ; CRC16 Interrupt Enable
ERRENB_DFN8         equ       3                   ; DFN8 Interrupt Enable
ERRENB_BTOERR       equ       4                   ; BTOERR Interrupt Enable
ERRENB_BUFERR       equ       5                   ; BUFERR Interrupt Enable
ERRENB_BTSERR       equ       7                   ; BTSERR Interrupt Enable
; bit position masks
mERRENB_PIDERR      equ       %00000001
mERRENB_CRC5        equ       %00000010
mERRENB_CRC16       equ       %00000100
mERRENB_DFN8        equ       %00001000
mERRENB_BTOERR      equ       %00010000
mERRENB_BUFERR      equ       %00100000
mERRENB_BTSERR      equ       %10000000


;*** STAT - Status Register
STAT                equ       $00000094           ;*** STAT - Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
STAT_ODD            equ       2                   ; Odd/Even Transaction
STAT_IN             equ       3                   ; In/Out Transaction
STAT_ENDP0          equ       4                   ; Endpoint Number Bit 0
STAT_ENDP1          equ       5                   ; Endpoint Number Bit 1
STAT_ENDP2          equ       6                   ; Endpoint Number Bit 2
STAT_ENDP3          equ       7                   ; Endpoint Number Bit 3
; bit position masks
mSTAT_ODD           equ       %00000100
mSTAT_IN            equ       %00001000
mSTAT_ENDP0         equ       %00010000
mSTAT_ENDP1         equ       %00100000
mSTAT_ENDP2         equ       %01000000
mSTAT_ENDP3         equ       %10000000


;*** CTL - Control Register
CTL                 equ       $00000095           ;*** CTL - Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CTL_USBEN           equ       0                   ; USB Enable
CTL_ODDRST          equ       1                   ; Odd Reset
CTL_CRESUME         equ       2                   ; Resume Signaling
CTL_TSUSPEND        equ       5                   ; Transaction Suspend
; bit position masks
mCTL_USBEN          equ       %00000001
mCTL_ODDRST         equ       %00000010
mCTL_CRESUME        equ       %00000100
mCTL_TSUSPEND       equ       %00100000


;*** ADDR - Address Register
ADDR                equ       $00000096           ;*** ADDR - Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADDR_ADDR0          equ       0                   ; USB Address Bit 0
ADDR_ADDR1          equ       1                   ; USB Address Bit 1
ADDR_ADDR2          equ       2                   ; USB Address Bit 2
ADDR_ADDR3          equ       3                   ; USB Address Bit 3
ADDR_ADDR4          equ       4                   ; USB Address Bit 4
ADDR_ADDR5          equ       5                   ; USB Address Bit 5
ADDR_ADDR6          equ       6                   ; USB Address Bit 6
; bit position masks
mADDR_ADDR0         equ       %00000001
mADDR_ADDR1         equ       %00000010
mADDR_ADDR2         equ       %00000100
mADDR_ADDR3         equ       %00001000
mADDR_ADDR4         equ       %00010000
mADDR_ADDR5         equ       %00100000
mADDR_ADDR6         equ       %01000000


;*** FRMNUML - Frame Number Register Low
FRMNUML             equ       $00000097           ;*** FRMNUML - Frame Number Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRMNUML_FRM0        equ       0                   ; Frame Number Bit 0
FRMNUML_FRM1        equ       1                   ; Frame Number Bit 1
FRMNUML_FRM2        equ       2                   ; Frame Number Bit 2
FRMNUML_FRM3        equ       3                   ; Frame Number Bit 3
FRMNUML_FRM4        equ       4                   ; Frame Number Bit 4
FRMNUML_FRM5        equ       5                   ; Frame Number Bit 5
FRMNUML_FRM6        equ       6                   ; Frame Number Bit 6
FRMNUML_FRM7        equ       7                   ; Frame Number Bit 7
; bit position masks
mFRMNUML_FRM0       equ       %00000001
mFRMNUML_FRM1       equ       %00000010
mFRMNUML_FRM2       equ       %00000100
mFRMNUML_FRM3       equ       %00001000
mFRMNUML_FRM4       equ       %00010000
mFRMNUML_FRM5       equ       %00100000
mFRMNUML_FRM6       equ       %01000000
mFRMNUML_FRM7       equ       %10000000


;*** FRMNUMH - Frame Number Register High
FRMNUMH             equ       $00000098           ;*** FRMNUMH - Frame Number Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRMNUMH_FRM8        equ       0                   ; Frame Number Bit 8
FRMNUMH_FRM9        equ       1                   ; Frame Number Bit 9
FRMNUMH_FRM10       equ       2                   ; Frame Number Bit 10
; bit position masks
mFRMNUMH_FRM8       equ       %00000001
mFRMNUMH_FRM9       equ       %00000010
mFRMNUMH_FRM10      equ       %00000100


;*** EPCTL0 - Endpoint Control Register 0
EPCTL0              equ       $0000009D           ;*** EPCTL0 - Endpoint Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL0_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL0_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL0_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL0_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL0_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL0_EPHSHK      equ       %00000001
mEPCTL0_EPSTALL     equ       %00000010
mEPCTL0_EPTXEN      equ       %00000100
mEPCTL0_EPRXEN      equ       %00001000
mEPCTL0_EPCTLDIS    equ       %00010000


;*** EPCTL1 - Endpoint Control Register 1
EPCTL1              equ       $0000009E           ;*** EPCTL1 - Endpoint Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL1_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL1_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL1_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL1_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL1_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL1_EPHSHK      equ       %00000001
mEPCTL1_EPSTALL     equ       %00000010
mEPCTL1_EPTXEN      equ       %00000100
mEPCTL1_EPRXEN      equ       %00001000
mEPCTL1_EPCTLDIS    equ       %00010000


;*** EPCTL2 - Endpoint Control Register 2
EPCTL2              equ       $0000009F           ;*** EPCTL2 - Endpoint Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL2_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL2_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL2_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL2_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL2_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL2_EPHSHK      equ       %00000001
mEPCTL2_EPSTALL     equ       %00000010
mEPCTL2_EPTXEN      equ       %00000100
mEPCTL2_EPRXEN      equ       %00001000
mEPCTL2_EPCTLDIS    equ       %00010000


;*** EPCTL3 - Endpoint Control Register 3
EPCTL3              equ       $000000A0           ;*** EPCTL3 - Endpoint Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL3_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL3_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL3_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL3_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL3_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL3_EPHSHK      equ       %00000001
mEPCTL3_EPSTALL     equ       %00000010
mEPCTL3_EPTXEN      equ       %00000100
mEPCTL3_EPRXEN      equ       %00001000
mEPCTL3_EPCTLDIS    equ       %00010000


;*** EPCTL4 - Endpoint Control Register 4
EPCTL4              equ       $000000A1           ;*** EPCTL4 - Endpoint Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL4_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL4_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL4_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL4_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL4_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL4_EPHSHK      equ       %00000001
mEPCTL4_EPSTALL     equ       %00000010
mEPCTL4_EPTXEN      equ       %00000100
mEPCTL4_EPRXEN      equ       %00001000
mEPCTL4_EPCTLDIS    equ       %00010000


;*** EPCTL5 - Endpoint Control Register 5
EPCTL5              equ       $000000A2           ;*** EPCTL5 - Endpoint Control Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL5_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL5_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL5_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL5_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL5_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL5_EPHSHK      equ       %00000001
mEPCTL5_EPSTALL     equ       %00000010
mEPCTL5_EPTXEN      equ       %00000100
mEPCTL5_EPRXEN      equ       %00001000
mEPCTL5_EPCTLDIS    equ       %00010000


;*** EPCTL6 - Endpoint Control Register 6
EPCTL6              equ       $000000A3           ;*** EPCTL6 - Endpoint Control Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPCTL6_EPHSHK       equ       0                   ; Endpoint Handshake
EPCTL6_EPSTALL      equ       1                   ; Endpoint Stall
EPCTL6_EPTXEN       equ       2                   ; Endpoint Tx Enable
EPCTL6_EPRXEN       equ       3                   ; Endpoint Rx Enable
EPCTL6_EPCTLDIS     equ       4                   ; Endpoint Control
; bit position masks
mEPCTL6_EPHSHK      equ       %00000001
mEPCTL6_EPSTALL     equ       %00000010
mEPCTL6_EPTXEN      equ       %00000100
mEPCTL6_EPRXEN      equ       %00001000
mEPCTL6_EPCTLDIS    equ       %00010000


;*** SRS - System Reset Status Register
SRS                 equ       $00001800           ;*** SRS - System Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD             equ       1                   ; Low Voltage Detect
SRS_LOC             equ       2                   ; Loss-of-Clock Reset
SRS_ILOP            equ       4                   ; Illegal Opcode
SRS_COP             equ       5                   ; Computer Operating Properly (COP) Watchdog
SRS_PIN             equ       6                   ; External Reset Pin
SRS_POR             equ       7                   ; Power-On Reset
; bit position masks
mSRS_LVD            equ       %00000010
mSRS_LOC            equ       %00000100
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
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT0         equ       6                   ; COP Watchdog Timeout, bit 0
SOPT1_COPT1         equ       7                   ; COP Watchdog Timeout, bit 1
; bit position masks
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT0        equ       %01000000
mSOPT1_COPT1        equ       %10000000


;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_ACIC          equ       0                   ; Analog Comparator to Input Capture Enable
SOPT2_SPI2FE        equ       1                   ; SPI2 Ports Input Filter Enable
SOPT2_SPI1FE        equ       2                   ; SPI1 Ports Input Filter Enable
SOPT2_COPW          equ       6                   ; COP Window
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_ACIC         equ       %00000001
mSOPT2_SPI2FE       equ       %00000010
mSOPT2_SPI1FE       equ       %00000100
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


;*** DBGF - Debug FIFO Register
DBGF                equ       $00001814           ;*** DBGF - Debug FIFO Register


;*** DBGFH - Debug FIFO High Register
DBGFH               equ       $00001814           ;*** DBGFH - Debug FIFO High Register
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
DBGFL               equ       $00001815           ;*** DBGFL - Debug FIFO Low Register
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
PTAPE_PTAPE5        equ       5                   ; Internal Pull Enable for Port A Bit 5
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE5       equ       %00100000


;*** PTASE - Port A Slew Rate Enable Register
PTASE               equ       $00001841           ;*** PTASE - Port A Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE5        equ       5                   ; Output Slew Rate Enable for Port A Bit 5
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE5       equ       %00100000


;*** PTADS - Port A Drive Strength Selection Register
PTADS               equ       $00001842           ;*** PTADS - Port A Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0        equ       0                   ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS5        equ       5                   ; Output Drive Strength Selection for Port A Bit 5
; bit position masks
mPTADS_PTADS0       equ       %00000001
mPTADS_PTADS5       equ       %00100000


;*** PTBPE - Port B Pull Enable Register
PTBPE               equ       $00001844           ;*** PTBPE - Port B Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Internal Pull Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Internal Pull Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Internal Pull Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Internal Pull Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Internal Pull Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Internal Pull Enable for Port B Bit 5
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000


;*** PTBSE - Port B Slew Rate Enable Register
PTBSE               equ       $00001845           ;*** PTBSE - Port B Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0        equ       0                   ; Output Slew Rate Enable for Port B Bit 0
PTBSE_PTBSE1        equ       1                   ; Output Slew Rate Enable for Port B Bit 1
PTBSE_PTBSE2        equ       2                   ; Output Slew Rate Enable for Port B Bit 2
PTBSE_PTBSE3        equ       3                   ; Output Slew Rate Enable for Port B Bit 3
PTBSE_PTBSE4        equ       4                   ; Output Slew Rate Enable for Port B Bit 4
PTBSE_PTBSE5        equ       5                   ; Output Slew Rate Enable for Port B Bit 5
; bit position masks
mPTBSE_PTBSE0       equ       %00000001
mPTBSE_PTBSE1       equ       %00000010
mPTBSE_PTBSE2       equ       %00000100
mPTBSE_PTBSE3       equ       %00001000
mPTBSE_PTBSE4       equ       %00010000
mPTBSE_PTBSE5       equ       %00100000


;*** PTBDS - Port B Drive Strength Selection Register
PTBDS               equ       $00001846           ;*** PTBDS - Port B Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS0        equ       0                   ; Output Drive Strength Selection for Port B Bit 0
PTBDS_PTBDS1        equ       1                   ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2        equ       2                   ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3        equ       3                   ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4        equ       4                   ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5        equ       5                   ; Output Drive Strength Selection for Port B Bit 5
; bit position masks
mPTBDS_PTBDS0       equ       %00000001
mPTBDS_PTBDS1       equ       %00000010
mPTBDS_PTBDS2       equ       %00000100
mPTBDS_PTBDS3       equ       %00001000
mPTBDS_PTBDS4       equ       %00010000
mPTBDS_PTBDS5       equ       %00100000


;*** PTCPE - Port C Pull Enable Register
PTCPE               equ       $00001848           ;*** PTCPE - Port C Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Internal Pull Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Internal Pull Enable for Port C Bit 1
PTCPE_PTCPE2        equ       2                   ; Internal Pull Enable for Port C Bit 2
PTCPE_PTCPE3        equ       3                   ; Internal Pull Enable for Port C Bit 3
PTCPE_PTCPE4        equ       4                   ; Internal Pull Enable for Port C Bit 4
PTCPE_PTCPE5        equ       5                   ; Internal Pull Enable for Port C Bit 5
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000


;*** PTCSE - Port C Slew Rate Enable Register
PTCSE               equ       $00001849           ;*** PTCSE - Port C Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0        equ       0                   ; Output Slew Rate Enable for Port C Bit 0
PTCSE_PTCSE1        equ       1                   ; Output Slew Rate Enable for Port C Bit 1
PTCSE_PTCSE2        equ       2                   ; Output Slew Rate Enable for Port C Bit 2
PTCSE_PTCSE3        equ       3                   ; Output Slew Rate Enable for Port C Bit 3
PTCSE_PTCSE4        equ       4                   ; Output Slew Rate Enable for Port C Bit 4
PTCSE_PTCSE5        equ       5                   ; Output Slew Rate Enable for Port C Bit 5
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010
mPTCSE_PTCSE2       equ       %00000100
mPTCSE_PTCSE3       equ       %00001000
mPTCSE_PTCSE4       equ       %00010000
mPTCSE_PTCSE5       equ       %00100000


;*** PTCDS - Port C Drive Strength Selection Register
PTCDS               equ       $0000184A           ;*** PTCDS - Port C Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0        equ       0                   ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1        equ       1                   ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2        equ       2                   ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3        equ       3                   ; Output Drive Strength Selection for Port C Bit 3
PTCDS_PTCDS4        equ       4                   ; Output Drive Strength Selection for Port C Bit 4
PTCDS_PTCDS5        equ       5                   ; Output Drive Strength Selection for Port C Bit 5
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010
mPTCDS_PTCDS2       equ       %00000100
mPTCDS_PTCDS3       equ       %00001000
mPTCDS_PTCDS4       equ       %00010000
mPTCDS_PTCDS5       equ       %00100000


;*** PTDPE - Port D Pull Enable Register
PTDPE               equ       $0000184C           ;*** PTDPE - Port D Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0        equ       0                   ; Internal Pull Enable for Port D Bit 0
PTDPE_PTDPE1        equ       1                   ; Internal Pull Enable for Port D Bit 1
PTDPE_PTDPE2        equ       2                   ; Internal Pull Enable for Port D Bit 2
PTDPE_PTDPE7        equ       7                   ; Internal Pull Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0       equ       %00000001
mPTDPE_PTDPE1       equ       %00000010
mPTDPE_PTDPE2       equ       %00000100
mPTDPE_PTDPE7       equ       %10000000


;*** PTDSE - Port D Slew Rate Enable Register
PTDSE               equ       $0000184D           ;*** PTDSE - Port D Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0        equ       0                   ; Output Slew Rate Enable for Port D Bit 0
PTDSE_PTDSE1        equ       1                   ; Output Slew Rate Enable for Port D Bit 1
PTDSE_PTDSE2        equ       2                   ; Output Slew Rate Enable for Port D Bit 2
PTDSE_PTDSE7        equ       7                   ; Output Slew Rate Enable for Port D Bit 7
; bit position masks
mPTDSE_PTDSE0       equ       %00000001
mPTDSE_PTDSE1       equ       %00000010
mPTDSE_PTDSE2       equ       %00000100
mPTDSE_PTDSE7       equ       %10000000


;*** PTDDS - Port D Drive Strength Selection Register
PTDDS               equ       $0000184E           ;*** PTDDS - Port D Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDS_PTDDS0        equ       0                   ; Output Drive Strength Selection for Port D Bit 0
PTDDS_PTDDS1        equ       1                   ; Output Drive Strength Selection for Port D Bit 1
PTDDS_PTDDS2        equ       2                   ; Output Drive Strength Selection for Port D Bit 2
PTDDS_PTDDS7        equ       7                   ; Output Drive Strength Selection for Port D Bit 7
; bit position masks
mPTDDS_PTDDS0       equ       %00000001
mPTDDS_PTDDS1       equ       %00000010
mPTDDS_PTDDS2       equ       %00000100
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
PTFPE_PTFPE4        equ       4                   ; Internal Pull Enable for Port F Bit 4
PTFPE_PTFPE5        equ       5                   ; Internal Pull Enable for Port F Bit 5
PTFPE_PTFPE6        equ       6                   ; Internal Pull Enable for Port F Bit 6
; bit position masks
mPTFPE_PTFPE0       equ       %00000001
mPTFPE_PTFPE1       equ       %00000010
mPTFPE_PTFPE4       equ       %00010000
mPTFPE_PTFPE5       equ       %00100000
mPTFPE_PTFPE6       equ       %01000000


;*** PTFSE - Port F Slew Rate Enable Register
PTFSE               equ       $00001855           ;*** PTFSE - Port F Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0        equ       0                   ; Output Slew Rate Enable for Port F Bit 0
PTFSE_PTFSE1        equ       1                   ; Output Slew Rate Enable for Port F Bit 1
PTFSE_PTFSE4        equ       4                   ; Output Slew Rate Enable for Port F Bit 4
PTFSE_PTFSE5        equ       5                   ; Output Slew Rate Enable for Port F Bit 5
PTFSE_PTFSE6        equ       6                   ; Output Slew Rate Enable for Port F Bit 6
; bit position masks
mPTFSE_PTFSE0       equ       %00000001
mPTFSE_PTFSE1       equ       %00000010
mPTFSE_PTFSE4       equ       %00010000
mPTFSE_PTFSE5       equ       %00100000
mPTFSE_PTFSE6       equ       %01000000


;*** PTFDS - Port F Drive Strength Selection Register
PTFDS               equ       $00001856           ;*** PTFDS - Port F Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDS_PTFDS0        equ       0                   ; Output Drive Strength Selection for Port F Bit 0
PTFDS_PTFDS1        equ       1                   ; Output Drive Strength Selection for Port F Bit 1
PTFDS_PTFDS4        equ       4                   ; Output Drive Strength Selection for Port F Bit 4
PTFDS_PTFDS5        equ       5                   ; Output Drive Strength Selection for Port F Bit 5
PTFDS_PTFDS6        equ       6                   ; Output Drive Strength Selection for Port F Bit 6
; bit position masks
mPTFDS_PTFDS0       equ       %00000001
mPTFDS_PTFDS1       equ       %00000010
mPTFDS_PTFDS4       equ       %00010000
mPTFDS_PTFDS5       equ       %00100000
mPTFDS_PTFDS6       equ       %01000000


;*** PTGPE - Port G Pull Enable Register
PTGPE               equ       $00001858           ;*** PTGPE - Port G Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0        equ       0                   ; Internal Pull Enable for Port G Bit 0
PTGPE_PTGPE1        equ       1                   ; Internal Pull Enable for Port G Bit 1
PTGPE_PTGPE2        equ       2                   ; Internal Pull Enable for Port G Bit 2
PTGPE_PTGPE3        equ       3                   ; Internal Pull Enable for Port G Bit 3
PTGPE_PTGPE4        equ       4                   ; Internal Pull Enable for Port G Bit 4
PTGPE_PTGPE5        equ       5                   ; Internal Pull Enable for Port G Bit 5
; bit position masks
mPTGPE_PTGPE0       equ       %00000001
mPTGPE_PTGPE1       equ       %00000010
mPTGPE_PTGPE2       equ       %00000100
mPTGPE_PTGPE3       equ       %00001000
mPTGPE_PTGPE4       equ       %00010000
mPTGPE_PTGPE5       equ       %00100000


;*** PTGSE - Port G Slew Rate Enable Register
PTGSE               equ       $00001859           ;*** PTGSE - Port G Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0        equ       0                   ; Output Slew Rate Enable for Port G Bit 0
PTGSE_PTGSE1        equ       1                   ; Output Slew Rate Enable for Port G Bit 1
PTGSE_PTGSE2        equ       2                   ; Output Slew Rate Enable for Port G Bit 2
PTGSE_PTGSE3        equ       3                   ; Output Slew Rate Enable for Port G Bit 3
PTGSE_PTGSE4        equ       4                   ; Output Slew Rate Enable for Port G Bit 4
PTGSE_PTGSE5        equ       5                   ; Output Slew Rate Enable for Port G Bit 5
; bit position masks
mPTGSE_PTGSE0       equ       %00000001
mPTGSE_PTGSE1       equ       %00000010
mPTGSE_PTGSE2       equ       %00000100
mPTGSE_PTGSE3       equ       %00001000
mPTGSE_PTGSE4       equ       %00010000
mPTGSE_PTGSE5       equ       %00100000


;*** PTGDS - Port G Drive Strength Selection Register
PTGDS               equ       $0000185A           ;*** PTGDS - Port G Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDS_PTGDS0        equ       0                   ; Output Drive Strength Selection for Port G Bit 0
PTGDS_PTGDS1        equ       1                   ; Output Drive Strength Selection for Port G Bit 1
PTGDS_PTGDS2        equ       2                   ; Output Drive Strength Selection for Port G Bit 2
PTGDS_PTGDS3        equ       3                   ; Output Drive Strength Selection for Port G Bit 3
PTGDS_PTGDS4        equ       4                   ; Output Drive Strength Selection for Port G Bit 4
PTGDS_PTGDS5        equ       5                   ; Output Drive Strength Selection for Port G Bit 5
; bit position masks
mPTGDS_PTGDS0       equ       %00000001
mPTGDS_PTGDS1       equ       %00000010
mPTGDS_PTGDS2       equ       %00000100
mPTGDS_PTGDS3       equ       %00001000
mPTGDS_PTGDS4       equ       %00010000
mPTGDS_PTGDS5       equ       %00100000


;*** NVFTRIM - Non-volatile MCG Fine Trim
NVFTRIM             equ       $0000FFAE           ;*** NVFTRIM - Non-volatile MCG Fine Trim
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFTRIM_FTRIM       equ       0                   ; MCG Fine Trim
; bit position masks
mNVFTRIM_FTRIM      equ       %00000001


;*** NVMCGTRM - Non-volatile MCG Trim Register
NVMCGTRM            equ       $0000FFAF           ;*** NVMCGTRM - Non-volatile MCG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVMCGTRM_TRIM0      equ       0                   ; MCG Trim Setting, bit 0
NVMCGTRM_TRIM1      equ       1                   ; MCG Trim Setting, bit 1
NVMCGTRM_TRIM2      equ       2                   ; MCG Trim Setting, bit 2
NVMCGTRM_TRIM3      equ       3                   ; MCG Trim Setting, bit 3
NVMCGTRM_TRIM4      equ       4                   ; MCG Trim Setting, bit 4
NVMCGTRM_TRIM5      equ       5                   ; MCG Trim Setting, bit 5
NVMCGTRM_TRIM6      equ       6                   ; MCG Trim Setting, bit 6
NVMCGTRM_TRIM7      equ       7                   ; MCG Trim Setting, bit 7
; bit position masks
mNVMCGTRM_TRIM0     equ       %00000001
mNVMCGTRM_TRIM1     equ       %00000010
mNVMCGTRM_TRIM2     equ       %00000100
mNVMCGTRM_TRIM3     equ       %00001000
mNVMCGTRM_TRIM4     equ       %00010000
mNVMCGTRM_TRIM5     equ       %00100000
mNVMCGTRM_TRIM6     equ       %01000000
mNVMCGTRM_TRIM7     equ       %10000000


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



; **** 13.11.2007

       #ifndef __GENERATE_APPLICATION__
        ;*** FIFO0 - FIFO 0 Data Register
FIFO0               equ       $00000081           ;*** FIFO0 - FIFO 0 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FIFO0_FDATA0        equ       0                   ; 8-bit data read/write port for the FIFO Bit 0
FIFO0_FDATA1        equ       1                   ; 8-bit data read/write port for the FIFO Bit 1
FIFO0_FDATA2        equ       2                   ; 8-bit data read/write port for the FIFO Bit 2
FIFO0_FDATA3        equ       3                   ; 8-bit data read/write port for the FIFO Bit 3
FIFO0_FDATA4        equ       4                   ; 8-bit data read/write port for the FIFO Bit 4
FIFO0_FDATA5        equ       5                   ; 8-bit data read/write port for the FIFO Bit 5
FIFO0_FDATA6        equ       6                   ; 8-bit data read/write port for the FIFO Bit 6
FIFO0_FDATA7        equ       7                   ; 8-bit data read/write port for the FIFO Bit 7
; bit position masks
mFIFO0_FDATA0       equ       %00000001
mFIFO0_FDATA1       equ       %00000010
mFIFO0_FDATA2       equ       %00000100
mFIFO0_FDATA3       equ       %00001000
mFIFO0_FDATA4       equ       %00010000
mFIFO0_FDATA5       equ       %00100000
mFIFO0_FDATA6       equ       %01000000
mFIFO0_FDATA7       equ       %10000000


;*** F0BADDR - FIFO 0 Base Address
F0BADDR             equ       $00000082           ;*** F0BADDR - FIFO 0 Base Address
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F0BADDR_REWIND      equ       0                   ; Rewind
F0BADDR_FBASE4      equ       2                   ; FIFO Base Address Bit 4
F0BADDR_FBASE5      equ       3                   ; FIFO Base Address Bit 5
F0BADDR_FBASE6      equ       4                   ; FIFO Base Address Bit 6
F0BADDR_FBASE7      equ       5                   ; FIFO Base Address Bit 7
F0BADDR_FBASE8      equ       6                   ; FIFO Base Address Bit 8
F0BADDR_FBASE9      equ       7                   ; FIFO Base Address Bit 9
; bit position masks
mF0BADDR_REWIND     equ       %00000001
mF0BADDR_FBASE4     equ       %00000100
mF0BADDR_FBASE5     equ       %00001000
mF0BADDR_FBASE6     equ       %00010000
mF0BADDR_FBASE7     equ       %00100000
mF0BADDR_FBASE8     equ       %01000000
mF0BADDR_FBASE9     equ       %10000000


;*** F0SIZE - FIFO 0 Size
F0SIZE              equ       $00000083           ;*** F0SIZE - FIFO 0 Size
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F0SIZE_FSIZE0       equ       5                   ; FIFO Buffer Size Bit 0
F0SIZE_FSIZE1       equ       6                   ; FIFO Buffer Size Bit 1
; bit position masks
mF0SIZE_FSIZE0      equ       %00100000
mF0SIZE_FSIZE1      equ       %01000000


;*** F0CTL - FIFO 0 Control
F0CTL               equ       $00000085           ;*** F0CTL - FIFO 0 Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
F0CTL_FIFOEN        equ       0                   ; FIFO Enable
F0CTL_FIFODIR       equ       7                   ; FIFO Direction
; bit position masks
mF0CTL_FIFOEN       equ       %00000001
mF0CTL_FIFODIR      equ       %10000000

       #endif

; **** 9.4.2008 16:05:56

       #ifndef __GENERATE_APPLICATION__
       #endif



; **** 15.8.2008 8:08:15

       #ifndef __GENERATE_APPLICATION__
       #endif


; **** 6.11.2008 15:30:05

       #ifndef __GENERATE_APPLICATION__
       #endif

; EOF
