;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08LC60_80, version 2.87.237 (RegistersPrg V2.18)

; ###################################################################
;     Filename  : mc9s08lc20.inc
;     Processor : MC9S08LC20PU
;     FileFormat: V2.18
;     DataSheet : MC9S08LC60 Rev. 1 Draft B 8/2006
;     Compiler  : CodeWarrior compiler
;     Date/Time : 25.7.2007, 8:44
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
;      - 02.03.2007, V2.14 :
;               - Interrupt vector numbers added into .H, see VectorNumber_*
;      - 26.03.2007, V2.15 :
;               - Revision is not related to this file (CPU family)
;      - 10.05.2007, V2.16 :
;               - Fixed flash commands definition for ColdFireV1 assembler (equ -> .equ)
;      - 05.06.2007, V2.17 :
;               - Revision is not related to this file (CPU family)
;      - 19.07.2007, V2.18 :
;               - Improved number of blanked lines inside register structures
;
;     CPU Registers Revisions:
;      - 23.02.2006, V2.87.178:
;              - Renamed bits IICA_ADDR0..6 ==> IICA_ADDR1..7 REASON: Bug-fix (#3047 from UNIS issue manager)
;      - 12.05.2006, V2.87.186:
;              - Added bit LCDSUPPLY_HDRVBUF, Added bit LCDCR0_LPWAVE
;              - REASON: Changes in data sheet (from rev 0.08 to rev 0.09)
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000C000
ROM_END             equ       $0000FFAF
RAM                 equ       $00000060
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000085F
XROM                equ       $00001870
XROM_END            equ       $0000286F
ROM2Start           equ       $0000FFC0
ROM2End             equ       $0000FFD1
;
Vlcd                equ       $0000FFD2
Vrti                equ       $0000FFD4
Viic                equ       $0000FFD6
Vacmp               equ       $0000FFD8
Vadc                equ       $0000FFDA
Vkeyboard2          equ       $0000FFDC
Vkeyboard1          equ       $0000FFDE
Vscitx              equ       $0000FFE0
Vscirx              equ       $0000FFE2
Vscierr             equ       $0000FFE4
Vspi2               equ       $0000FFE6
Vspi1               equ       $0000FFE8
Vtpm2ovf            equ       $0000FFEA
Vtpm2ch1            equ       $0000FFEC
Vtpm2ch0            equ       $0000FFEE
Vtpm1ovf            equ       $0000FFF0
Vtpm1ch1            equ       $0000FFF2
Vtpm1ch0            equ       $0000FFF4
Vicg                equ       $0000FFF6
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

;*** PTADD - Data Direction Register A
PTADD               equ       $00000001           ;*** PTADD - Data Direction Register A
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

;*** PTBDD - Data Direction Register B
PTBDD               equ       $00000003           ;*** PTBDD - Data Direction Register B
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

;*** PTCDD - Data Direction Register C
PTCDD               equ       $00000005           ;*** PTCDD - Data Direction Register C
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

;*** IRQSC - Interrupt Request Status and Control Register
IRQSC               equ       $00000006           ;*** IRQSC - Interrupt Request Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD        equ       0                   ; IRQ Detection Mode
IRQSC_IRQIE         equ       1                   ; IRQ Interrupt Enable
IRQSC_IRQACK        equ       2                   ; IRQ Acknowledge
IRQSC_IRQF          equ       3                   ; IRQ Flag
IRQSC_IRQPE         equ       4                   ; IRQ Pin Enable
IRQSC_IRQEDG        equ       5                   ; Interrupt Request (IRQ) Edge Select
IRQSC_IRQPDD        equ       6                   ; Interrupt Request (IRQ) Pull Device Disable
; bit position masks
mIRQSC_IRQMOD       equ       %00000001
mIRQSC_IRQIE        equ       %00000010
mIRQSC_IRQACK       equ       %00000100
mIRQSC_IRQF         equ       %00001000
mIRQSC_IRQPE        equ       %00010000
mIRQSC_IRQEDG       equ       %00100000
mIRQSC_IRQPDD       equ       %01000000

;*** KBI1SC - KBI1 Status and Control
KBI1SC              equ       $00000008           ;*** KBI1SC - KBI1 Status and Control
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
KBI1PE              equ       $00000009           ;*** KBI1PE - KBI1 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for Port A Bit 0
KBI1PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for Port A Bit 1
KBI1PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for Port A Bit 2
KBI1PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for Port A Bit 3
KBI1PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for Port A Bit 4
KBI1PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for Port A Bit 5
KBI1PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for Port A Bit 6
KBI1PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for Port A Bit 7
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
KBI1ES              equ       $0000000A           ;*** KBI1ES - KBI1 Edge Select Register
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

;*** KBI2SC - KBI2 Status and Control
KBI2SC              equ       $0000000C           ;*** KBI2SC - KBI2 Status and Control
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
KBI2PE              equ       $0000000D           ;*** KBI2PE - KBI2 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for Port A Bit 0
KBI2PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for Port A Bit 1
KBI2PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for Port A Bit 2
KBI2PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for Port A Bit 3
KBI2PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for Port A Bit 4
KBI2PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for Port A Bit 5
KBI2PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for Port A Bit 6
KBI2PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for Port A Bit 7
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
KBI2ES              equ       $0000000E           ;*** KBI2ES - KBI2 Edge Select Register
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

;*** ACMPSC - Analog Comparator Status and Control Register
ACMPSC              equ       $0000000F           ;*** ACMPSC - Analog Comparator Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ACMPSC_ACMOD0       equ       0                   ; Analog Comparator Mode Bit 0
ACMPSC_ACMOD1       equ       1                   ; Analog Comparator Mode Bit 1
ACMPSC_ACO          equ       3                   ; Analog Comparator Output
ACMPSC_ACIE         equ       4                   ; Analog Comparator Interrupt Enable
ACMPSC_ACF          equ       5                   ; Analog Comparator Flag
ACMPSC_ACBGS        equ       6                   ; Analog Comparator Bandgap Select
ACMPSC_ACME         equ       7                   ; Analog Comparator Module Enable
; bit position masks
mACMPSC_ACMOD0      equ       %00000001
mACMPSC_ACMOD1      equ       %00000010
mACMPSC_ACO         equ       %00001000
mACMPSC_ACIE        equ       %00010000
mACMPSC_ACF         equ       %00100000
mACMPSC_ACBGS       equ       %01000000
mACMPSC_ACME        equ       %10000000

;*** ADCSC1 - Status and Control Register
ADCSC1              equ       $00000010           ;*** ADCSC1 - Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1_ADCH0        equ       0                   ; Input Channel Select Bit 0
ADCSC1_ADCH1        equ       1                   ; Input Channel Select Bit 1
ADCSC1_ADCH2        equ       2                   ; Input Channel Select Bit 2
ADCSC1_ADCH3        equ       3                   ; Input Channel Select Bit 3
ADCSC1_ADCH4        equ       4                   ; Input Channel Select Bit 4
ADCSC1_ADCO         equ       5                   ; Continuous Conversion Enable
ADCSC1_AIEN         equ       6                   ; Interrupt Enable
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
ADCSC2_ACFE         equ       5                   ; Compare Function Enable
ADCSC2_ADTRG        equ       6                   ; Conversion Trigger Select
ADCSC2_ADACT        equ       7                   ; Conversion Active
; bit position masks
mADCSC2_ACFGT       equ       %00010000
mADCSC2_ACFE        equ       %00100000
mADCSC2_ADTRG       equ       %01000000
mADCSC2_ADACT       equ       %10000000

;*** ADCR - ADC Result Data Right Justified
ADCR                equ       $00000012           ;*** ADCR - ADC Result Data Right Justified

;*** ADCRH - ADC Result Data Right Justified High
ADCRH               equ       $00000012           ;*** ADCRH - ADC Result Data Right Justified High
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

;*** ADCRL - ADC Result Data Right Justified Low
ADCRL               equ       $00000013           ;*** ADCRL - ADC Result Data Right Justified Low
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

;*** ADCCVH - Compare Value Register High
ADCCVH              equ       $00000014           ;*** ADCCVH - Compare Value Register High
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

;*** ADCCVL - Compare Value Register Low
ADCCVL              equ       $00000015           ;*** ADCCVL - Compare Value Register Low
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

;*** APCTL1 - ADC Pin Control 1 Register
APCTL1              equ       $00000017           ;*** APCTL1 - ADC Pin Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0        equ       0                   ; ADC Pin Control 0
APCTL1_ADPC1        equ       1                   ; ADC Pin Control 1
APCTL1_ADPC2        equ       2                   ; ADC Pin Control 2
APCTL1_ADPC3        equ       3                   ; ADC Pin Control 3
APCTL1_ADPC4        equ       4                   ; ADC Pin Control 4
APCTL1_ADPC5        equ       5                   ; ADC Pin Control 5
APCTL1_ADPC6        equ       6                   ; ADC Pin Control 6
APCTL1_ADPC7        equ       7                   ; ADC Pin Control 7
; bit position masks
mAPCTL1_ADPC0       equ       %00000001
mAPCTL1_ADPC1       equ       %00000010
mAPCTL1_ADPC2       equ       %00000100
mAPCTL1_ADPC3       equ       %00001000
mAPCTL1_ADPC4       equ       %00010000
mAPCTL1_ADPC5       equ       %00100000
mAPCTL1_ADPC6       equ       %01000000
mAPCTL1_ADPC7       equ       %10000000

;*** IICA - IIC Address Register
IICA                equ       $00000018           ;*** IICA - IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA_ADDR1          equ       1                   ; IIC Address Bit 1
IICA_ADDR2          equ       2                   ; IIC Address Bit 2
IICA_ADDR3          equ       3                   ; IIC Address Bit 3
IICA_ADDR4          equ       4                   ; IIC Address Bit 4
IICA_ADDR5          equ       5                   ; IIC Address Bit 5
IICA_ADDR6          equ       6                   ; IIC Address Bit 6
IICA_ADDR7          equ       7                   ; IIC Address Bit 7
; bit position masks
mIICA_ADDR1         equ       %00000010
mIICA_ADDR2         equ       %00000100
mIICA_ADDR3         equ       %00001000
mIICA_ADDR4         equ       %00010000
mIICA_ADDR5         equ       %00100000
mIICA_ADDR6         equ       %01000000
mIICA_ADDR7         equ       %10000000

;*** IICF - IIC Frequency Divider Register
IICF                equ       $00000019           ;*** IICF - IIC Frequency Divider Register
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

;*** IICC - IIC Control Register
IICC                equ       $0000001A           ;*** IICC - IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC_RSTA           equ       2                   ; Repeat START Bit
IICC_TXAK           equ       3                   ; Transmit Acknowledge Enable Bit
IICC_TX             equ       4                   ; Transmit Mode Select Bit
IICC_MST            equ       5                   ; Master Mode Select Bit
IICC_IICIE          equ       6                   ; IIC Interrupt Enable Bit
IICC_IICEN          equ       7                   ; IIC Enable Bit
; bit position masks
mIICC_RSTA          equ       %00000100
mIICC_TXAK          equ       %00001000
mIICC_TX            equ       %00010000
mIICC_MST           equ       %00100000
mIICC_IICIE         equ       %01000000
mIICC_IICEN         equ       %10000000

;*** IICS - IIC Status Register
IICS                equ       $0000001B           ;*** IICS - IIC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICS_RXAK           equ       0                   ; Receive Acknowledge
IICS_IICIF          equ       1                   ; IIC Interrupt Flag
IICS_SRW            equ       2                   ; Slave Read/Write
IICS_ARBL           equ       4                   ; Arbitration Lost
IICS_BUSY           equ       5                   ; Bus Busy bit
IICS_IAAS           equ       6                   ; Addressed as a Slave Bit
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
IICD                equ       $0000001C           ;*** IICD - IIC Data I/O Register
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
; bit position masks
mSCIBDH_SBR8        equ       %00000001
mSCIBDH_SBR9        equ       %00000010
mSCIBDH_SBR10       equ       %00000100
mSCIBDH_SBR11       equ       %00001000
mSCIBDH_SBR12       equ       %00010000

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
SCIS2_BRK13         equ       2                   ; Break Character Length
; bit position masks
mSCIS2_RAF          equ       %00000001
mSCIS2_BRK13        equ       %00000100

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

;*** SPI1C1 - SPI1 Control Register 1
SPI1C1              equ       $00000028           ;*** SPI1C1 - SPI1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C1_LSBFE        equ       0                   ; LSB First (shifter direction)
SPI1C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI1C1_CPHA         equ       2                   ; Clock Phase
SPI1C1_CPOL         equ       3                   ; Clock Polarity
SPI1C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI1C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI1C1_SPE          equ       6                   ; SPI System Enable
SPI1C1_SPIE         equ       7                   ; SPI Interrupt Enable
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
SPI1C2              equ       $00000029           ;*** SPI1C2 - SPI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI1C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI1C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI1C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPI1C2_SPC0        equ       %00000001
mSPI1C2_SPISWAI     equ       %00000010
mSPI1C2_BIDIROE     equ       %00001000
mSPI1C2_MODFEN      equ       %00010000

;*** SPI1BR - SPI1 Baud Rate Register
SPI1BR              equ       $0000002A           ;*** SPI1BR - SPI1 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI1BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI1BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI1BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2        equ       6                   ; SP1 Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0        equ       %00000001
mSPI1BR_SPR1        equ       %00000010
mSPI1BR_SPR2        equ       %00000100
mSPI1BR_SPPR0       equ       %00010000
mSPI1BR_SPPR1       equ       %00100000
mSPI1BR_SPPR2       equ       %01000000

;*** SPI1S - SPI1 Status Register
SPI1S               equ       $0000002B           ;*** SPI1S - SPI1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF          equ       4                   ; Master Mode Fault Flag
SPI1S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI1S_SPRF          equ       7                   ; SP1 Read Buffer Full Flag
; bit position masks
mSPI1S_MODF         equ       %00010000
mSPI1S_SPTEF        equ       %00100000
mSPI1S_SPRF         equ       %10000000

;*** SPI1D - SPI1 Data Register
SPI1D               equ       $0000002D           ;*** SPI1D - SPI1 Data Register

;*** SPI2C1 - SPI2 Control Register 1
SPI2C1              equ       $00000030           ;*** SPI2C1 - SPI2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C1_LSBFE        equ       0                   ; LSB First (shifter direction)
SPI2C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI2C1_CPHA         equ       2                   ; Clock Phase
SPI2C1_CPOL         equ       3                   ; Clock Polarity
SPI2C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI2C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI2C1_SPE          equ       6                   ; SPI System Enable
SPI2C1_SPIE         equ       7                   ; SPI Interrupt Enable
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
SPI2C2              equ       $00000031           ;*** SPI2C2 - SPI2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI2C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI2C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI2C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPI2C2_SPC0        equ       %00000001
mSPI2C2_SPISWAI     equ       %00000010
mSPI2C2_BIDIROE     equ       %00001000
mSPI2C2_MODFEN      equ       %00010000

;*** SPI2BR - SPI2 Baud Rate Register
SPI2BR              equ       $00000032           ;*** SPI2BR - SPI2 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI2BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI2BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI2BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI2BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI2BR_SPPR2        equ       6                   ; SP1 Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI2BR_SPR0        equ       %00000001
mSPI2BR_SPR1        equ       %00000010
mSPI2BR_SPR2        equ       %00000100
mSPI2BR_SPPR0       equ       %00010000
mSPI2BR_SPPR1       equ       %00100000
mSPI2BR_SPPR2       equ       %01000000

;*** SPI2S - SPI2 Status Register
SPI2S               equ       $00000033           ;*** SPI2S - SPI2 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_MODF          equ       4                   ; Master Mode Fault Flag
SPI2S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI2S_SPRF          equ       7                   ; SP1 Read Buffer Full Flag
; bit position masks
mSPI2S_MODF         equ       %00010000
mSPI2S_SPTEF        equ       %00100000
mSPI2S_SPRF         equ       %10000000

;*** SPI2D - SPI2 Data Register
SPI2D               equ       $00000035           ;*** SPI2D - SPI2 Data Register

;*** ICGC1 - ICG Control Register 1
ICGC1               equ       $00000038           ;*** ICGC1 - ICG Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGC1_LOCD          equ       1                   ; Loss of Clock Disable
ICGC1_OSCSTEN       equ       2                   ; Enable Oscillator in Off Mode
ICGC1_CLKS0         equ       3                   ; Clock Mode Select Bit 0
ICGC1_CLKS1         equ       4                   ; Clock Mode Select Bit 1
ICGC1_REFS          equ       5                   ; External Reference Select
ICGC1_RANGE         equ       6                   ; Frequency Range Select
ICGC1_HGO           equ       7                   ; High Gain Oscillator Select
; bit position masks
mICGC1_LOCD         equ       %00000010
mICGC1_OSCSTEN      equ       %00000100
mICGC1_CLKS0        equ       %00001000
mICGC1_CLKS1        equ       %00010000
mICGC1_REFS         equ       %00100000
mICGC1_RANGE        equ       %01000000
mICGC1_HGO          equ       %10000000

;*** ICGC2 - ICG Control Register 2
ICGC2               equ       $00000039           ;*** ICGC2 - ICG Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGC2_RFD0          equ       0                   ; Reduced Frequency Divider Bit 0
ICGC2_RFD1          equ       1                   ; Reduced Frequency Divider Bit 1
ICGC2_RFD2          equ       2                   ; Reduced Frequency Divider Bit 2
ICGC2_LOCRE         equ       3                   ; Loss of Clock Reset Enable
ICGC2_MFD0          equ       4                   ; Multiplication Factor Bit 0
ICGC2_MFD1          equ       5                   ; Multiplication Factor Bit 1
ICGC2_MFD2          equ       6                   ; Multiplication Factor Bit 2
ICGC2_LOLRE         equ       7                   ; Loss of Lock Reset Enable
; bit position masks
mICGC2_RFD0         equ       %00000001
mICGC2_RFD1         equ       %00000010
mICGC2_RFD2         equ       %00000100
mICGC2_LOCRE        equ       %00001000
mICGC2_MFD0         equ       %00010000
mICGC2_MFD1         equ       %00100000
mICGC2_MFD2         equ       %01000000
mICGC2_LOLRE        equ       %10000000

;*** ICGS1 - ICG Status Register 1
ICGS1               equ       $0000003A           ;*** ICGS1 - ICG Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGS1_ICGIF         equ       0                   ; ICG Interrupt Flag
ICGS1_ERCS          equ       1                   ; External Reference Clock Status
ICGS1_LOCS          equ       2                   ; Loss Of Clock Status
ICGS1_LOCK          equ       3                   ; FLL Lock Status
ICGS1_LOLS          equ       4                   ; FLL Loss of Lock Status
ICGS1_REFST         equ       5                   ; Reference Clock Status
ICGS1_CLKST0        equ       6                   ; Clock Mode Status Bit 0
ICGS1_CLKST1        equ       7                   ; Clock Mode Status Bit 1
; bit position masks
mICGS1_ICGIF        equ       %00000001
mICGS1_ERCS         equ       %00000010
mICGS1_LOCS         equ       %00000100
mICGS1_LOCK         equ       %00001000
mICGS1_LOLS         equ       %00010000
mICGS1_REFST        equ       %00100000
mICGS1_CLKST0       equ       %01000000
mICGS1_CLKST1       equ       %10000000

;*** ICGS2 - ICG Status Register 2
ICGS2               equ       $0000003B           ;*** ICGS2 - ICG Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGS2_DCOS          equ       0                   ; DCO Clock Stable
; bit position masks
mICGS2_DCOS         equ       %00000001

;*** ICGFLT - ICG Upper Filter
ICGFLT              equ       $0000003C           ;*** ICGFLT - ICG Upper Filter

;*** ICGFLTU - ICG Upper Filter Register
ICGFLTU             equ       $0000003C           ;*** ICGFLTU - ICG Upper Filter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGFLTU_FILT8       equ       0                   ; ICG Filter Bit 8
ICGFLTU_FILT9       equ       1                   ; ICG Filter Bit 9
ICGFLTU_FILT10      equ       2                   ; ICG Filter Bit 10
ICGFLTU_FILT11      equ       3                   ; ICG Filter Bit 11
; bit position masks
mICGFLTU_FILT8      equ       %00000001
mICGFLTU_FILT9      equ       %00000010
mICGFLTU_FILT10     equ       %00000100
mICGFLTU_FILT11     equ       %00001000

;*** ICGFLTL - ICG Lower Filter Register
ICGFLTL             equ       $0000003D           ;*** ICGFLTL - ICG Lower Filter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGFLTL_FILT0       equ       0                   ; ICG Filter Bit 0
ICGFLTL_FILT1       equ       1                   ; ICG Filter Bit 1
ICGFLTL_FILT2       equ       2                   ; ICG Filter Bit 2
ICGFLTL_FILT3       equ       3                   ; ICG Filter Bit 3
ICGFLTL_FILT4       equ       4                   ; ICG Filter Bit 4
ICGFLTL_FILT5       equ       5                   ; ICG Filter Bit 5
ICGFLTL_FILT6       equ       6                   ; ICG Filter Bit 6
ICGFLTL_FILT7       equ       7                   ; ICG Filter Bit 7
; bit position masks
mICGFLTL_FILT0      equ       %00000001
mICGFLTL_FILT1      equ       %00000010
mICGFLTL_FILT2      equ       %00000100
mICGFLTL_FILT3      equ       %00001000
mICGFLTL_FILT4      equ       %00010000
mICGFLTL_FILT5      equ       %00100000
mICGFLTL_FILT6      equ       %01000000
mICGFLTL_FILT7      equ       %10000000

;*** ICGTRM - ICG Trim Register
ICGTRM              equ       $0000003E           ;*** ICGTRM - ICG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGTRM_TRIM0        equ       0                   ; ICG Trim Bit 0
ICGTRM_TRIM1        equ       1                   ; ICG Trim Bit 1
ICGTRM_TRIM2        equ       2                   ; ICG Trim Bit 2
ICGTRM_TRIM3        equ       3                   ; ICG Trim Bit 3
ICGTRM_TRIM4        equ       4                   ; ICG Trim Bit 4
ICGTRM_TRIM5        equ       5                   ; ICG Trim Bit 5
ICGTRM_TRIM6        equ       6                   ; ICG Trim Bit 6
ICGTRM_TRIM7        equ       7                   ; ICG Trim Bit 7
; bit position masks
mICGTRM_TRIM0       equ       %00000001
mICGTRM_TRIM1       equ       %00000010
mICGTRM_TRIM2       equ       %00000100
mICGTRM_TRIM3       equ       %00001000
mICGTRM_TRIM4       equ       %00010000
mICGTRM_TRIM5       equ       %00100000
mICGTRM_TRIM6       equ       %01000000
mICGTRM_TRIM7       equ       %10000000

;*** TPM1SC - TPM 1 Status and Control Register
TPM1SC              equ       $00000040           ;*** TPM1SC - TPM 1 Status and Control Register
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

;*** TPM1CNT - TPM 1 Counter Register
TPM1CNT             equ       $00000041           ;*** TPM1CNT - TPM 1 Counter Register

;*** TPM1CNTH - TPM 1 Counter Register High
TPM1CNTH            equ       $00000041           ;*** TPM1CNTH - TPM 1 Counter Register High

;*** TPM1CNTL - TPM 1 Counter Register Low
TPM1CNTL            equ       $00000042           ;*** TPM1CNTL - TPM 1 Counter Register Low

;*** TPM1MOD - TPM 1 Timer Counter Modulo Register
TPM1MOD             equ       $00000043           ;*** TPM1MOD - TPM 1 Timer Counter Modulo Register

;*** TPM1MODH - TPM 1 Timer Counter Modulo Register High
TPM1MODH            equ       $00000043           ;*** TPM1MODH - TPM 1 Timer Counter Modulo Register High

;*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low
TPM1MODL            equ       $00000044           ;*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low

;*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $00000045           ;*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register
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

;*** TPM1C0V - TPM 1 Timer Channel 0 Value Register
TPM1C0V             equ       $00000046           ;*** TPM1C0V - TPM 1 Timer Channel 0 Value Register

;*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $00000046           ;*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High

;*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $00000047           ;*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low

;*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $00000048           ;*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register
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

;*** TPM1C1V - TPM 1 Timer Channel 1 Value Register
TPM1C1V             equ       $00000049           ;*** TPM1C1V - TPM 1 Timer Channel 1 Value Register

;*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $00000049           ;*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High

;*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $0000004A           ;*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low

;*** TPM2SC - TPM 2 Status and Control Register
TPM2SC              equ       $00000050           ;*** TPM2SC - TPM 2 Status and Control Register
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

;*** TPM2CNT - TPM 2 Counter Register
TPM2CNT             equ       $00000051           ;*** TPM2CNT - TPM 2 Counter Register

;*** TPM2CNTH - TPM 2 Counter Register High
TPM2CNTH            equ       $00000051           ;*** TPM2CNTH - TPM 2 Counter Register High

;*** TPM2CNTL - TPM 2 Counter Register Low
TPM2CNTL            equ       $00000052           ;*** TPM2CNTL - TPM 2 Counter Register Low

;*** TPM2MOD - TPM 2 Timer Counter Modulo Register
TPM2MOD             equ       $00000053           ;*** TPM2MOD - TPM 2 Timer Counter Modulo Register

;*** TPM2MODH - TPM 2 Timer Counter Modulo Register High
TPM2MODH            equ       $00000053           ;*** TPM2MODH - TPM 2 Timer Counter Modulo Register High

;*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low
TPM2MODL            equ       $00000054           ;*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low

;*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $00000055           ;*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register
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

;*** TPM2C0V - TPM 2 Timer Channel 0 Value Register
TPM2C0V             equ       $00000056           ;*** TPM2C0V - TPM 2 Timer Channel 0 Value Register

;*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $00000056           ;*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High

;*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $00000057           ;*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low

;*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register
TPM2C1SC            equ       $00000058           ;*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register
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

;*** TPM2C1V - TPM 2 Timer Channel 1 Value Register
TPM2C1V             equ       $00000059           ;*** TPM2C1V - TPM 2 Timer Channel 1 Value Register

;*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High
TPM2C1VH            equ       $00000059           ;*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High

;*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low
TPM2C1VL            equ       $0000005A           ;*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low

;*** SRS - System Reset Status
SRS                 equ       $00001800           ;*** SRS - System Reset Status
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD             equ       1                   ; Low Voltage Detect
SRS_ICG             equ       2                   ; Internal Clock Generation Module Reset
SRS_ILOP            equ       4                   ; Illegal Opcode
SRS_COP             equ       5                   ; Computer Operating Properly (COP) Watchdog
SRS_PIN             equ       6                   ; External Reset Pin
SRS_POR             equ       7                   ; Power-On Reset
; bit position masks
mSRS_LVD            equ       %00000010
mSRS_ICG            equ       %00000100
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
SOPT1_RSTPE         equ       0                   ; Reset Pin Enable
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
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_ACIC         equ       %00000001
mSOPT2_COPCLKS      equ       %10000000

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
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowledge
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

;*** PTAPE - Pullup Enable for Port A
PTAPE               equ       $00001830           ;*** PTAPE - Pullup Enable for Port A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Pullup Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Pullup Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Pullup Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Pullup Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Pullup Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Pullup Enable for Port A Bit 5
PTAPE_PTAPE6        equ       6                   ; Pullup Enable for Port A Bit 6
PTAPE_PTAPE7        equ       7                   ; Pullup Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000
mPTAPE_PTAPE6       equ       %01000000
mPTAPE_PTAPE7       equ       %10000000

;*** PTASE - Slew Rate Control Enable for Port A
PTASE               equ       $00001831           ;*** PTASE - Slew Rate Control Enable for Port A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Slew Rate Control Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Slew Rate Control Enable for Port A Bit 1
PTASE_PTASE2        equ       2                   ; Slew Rate Control Enable for Port A Bit 2
PTASE_PTASE3        equ       3                   ; Slew Rate Control Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Slew Rate Control Enable for Port A Bit 4
PTASE_PTASE5        equ       5                   ; Slew Rate Control Enable for Port A Bit 5
PTASE_PTASE6        equ       6                   ; Slew Rate Control Enable for Port A Bit 6
PTASE_PTASE7        equ       7                   ; Slew Rate Control Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE2       equ       %00000100
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000
mPTASE_PTASE5       equ       %00100000
mPTASE_PTASE6       equ       %01000000
mPTASE_PTASE7       equ       %10000000

;*** PTADS - Output Drive Strength Selection for Port A
PTADS               equ       $00001832           ;*** PTADS - Output Drive Strength Selection for Port A
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

;*** PTBPE - Pullup Enable for Port B
PTBPE               equ       $00001834           ;*** PTBPE - Pullup Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Pullup Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Pullup Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Pullup Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Pullup Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Pullup Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Pullup Enable for Port B Bit 5
PTBPE_PTBPE6        equ       6                   ; Pullup Enable for Port B Bit 6
PTBPE_PTBPE7        equ       7                   ; Pullup Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000
mPTBPE_PTBPE6       equ       %01000000
mPTBPE_PTBPE7       equ       %10000000

;*** PTBSE - Slew Rate Control Enable for Port B
PTBSE               equ       $00001835           ;*** PTBSE - Slew Rate Control Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0        equ       0                   ; Slew Rate Control Enable for Port B Bit 0
PTBSE_PTBSE1        equ       1                   ; Slew Rate Control Enable for Port B Bit 1
PTBSE_PTBSE2        equ       2                   ; Slew Rate Control Enable for Port B Bit 2
PTBSE_PTBSE3        equ       3                   ; Slew Rate Control Enable for Port B Bit 3
PTBSE_PTBSE4        equ       4                   ; Slew Rate Control Enable for Port B Bit 4
PTBSE_PTBSE5        equ       5                   ; Slew Rate Control Enable for Port B Bit 5
PTBSE_PTBSE6        equ       6                   ; Slew Rate Control Enable for Port B Bit 6
PTBSE_PTBSE7        equ       7                   ; Slew Rate Control Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE0       equ       %00000001
mPTBSE_PTBSE1       equ       %00000010
mPTBSE_PTBSE2       equ       %00000100
mPTBSE_PTBSE3       equ       %00001000
mPTBSE_PTBSE4       equ       %00010000
mPTBSE_PTBSE5       equ       %00100000
mPTBSE_PTBSE6       equ       %01000000
mPTBSE_PTBSE7       equ       %10000000

;*** PTBDS - Output Drive Strength Selection for Port B
PTBDS               equ       $00001836           ;*** PTBDS - Output Drive Strength Selection for Port B
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

;*** PTCPE - Pullup Enable for Port B
PTCPE               equ       $00001838           ;*** PTCPE - Pullup Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Pullup Enable for Port B Bit 0
PTCPE_PTCPE1        equ       1                   ; Pullup Enable for Port B Bit 1
PTCPE_PTCPE2        equ       2                   ; Pullup Enable for Port B Bit 2
PTCPE_PTCPE3        equ       3                   ; Pullup Enable for Port B Bit 3
PTCPE_PTCPE4        equ       4                   ; Pullup Enable for Port B Bit 4
PTCPE_PTCPE5        equ       5                   ; Pullup Enable for Port B Bit 5
PTCPE_PTCPE6        equ       6                   ; Pullup Enable for Port B Bit 6
PTCPE_PTCPE7        equ       7                   ; Pullup Enable for Port B Bit 7
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000
mPTCPE_PTCPE6       equ       %01000000
mPTCPE_PTCPE7       equ       %10000000

;*** PTCSE - Slew Rate Control Enable for Port B
PTCSE               equ       $00001839           ;*** PTCSE - Slew Rate Control Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0        equ       0                   ; Slew Rate Control Enable for Port B Bit 0
PTCSE_PTCSE1        equ       1                   ; Slew Rate Control Enable for Port B Bit 1
PTCSE_PTCSE2        equ       2                   ; Slew Rate Control Enable for Port B Bit 2
PTCSE_PTCSE3        equ       3                   ; Slew Rate Control Enable for Port B Bit 3
PTCSE_PTCSE4        equ       4                   ; Slew Rate Control Enable for Port B Bit 4
PTCSE_PTCSE5        equ       5                   ; Slew Rate Control Enable for Port B Bit 5
PTCSE_PTCSE6        equ       6                   ; Slew Rate Control Enable for Port B Bit 6
PTCSE_PTCSE7        equ       7                   ; Slew Rate Control Enable for Port B Bit 7
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010
mPTCSE_PTCSE2       equ       %00000100
mPTCSE_PTCSE3       equ       %00001000
mPTCSE_PTCSE4       equ       %00010000
mPTCSE_PTCSE5       equ       %00100000
mPTCSE_PTCSE6       equ       %01000000
mPTCSE_PTCSE7       equ       %10000000

;*** PTCDS - Output Drive Strength Selection for Port B
PTCDS               equ       $0000183A           ;*** PTCDS - Output Drive Strength Selection for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0        equ       0                   ; Output Drive Strength Selection for Port B Bit 0
PTCDS_PTCDS1        equ       1                   ; Output Drive Strength Selection for Port B Bit 1
PTCDS_PTCDS2        equ       2                   ; Output Drive Strength Selection for Port B Bit 2
PTCDS_PTCDS3        equ       3                   ; Output Drive Strength Selection for Port B Bit 3
PTCDS_PTCDS4        equ       4                   ; Output Drive Strength Selection for Port B Bit 4
PTCDS_PTCDS5        equ       5                   ; Output Drive Strength Selection for Port B Bit 5
PTCDS_PTCDS6        equ       6                   ; Output Drive Strength Selection for Port B Bit 6
PTCDS_PTCDS7        equ       7                   ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010
mPTCDS_PTCDS2       equ       %00000100
mPTCDS_PTCDS3       equ       %00001000
mPTCDS_PTCDS4       equ       %00010000
mPTCDS_PTCDS5       equ       %00100000
mPTCDS_PTCDS6       equ       %01000000
mPTCDS_PTCDS7       equ       %10000000

;*** LCDCR0 - LCD Control Register 0
LCDCR0              equ       $00001840           ;*** LCDCR0 - LCD Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDCR0_DUTY0        equ       0                   ; LCD Duty Select Bit 0
LCDCR0_DUTY1        equ       1                   ; LCD Duty Select Bit 1
LCDCR0_LCLK0        equ       3                   ; LCD Clock Prescaler Bit 0
LCDCR0_LCLK1        equ       4                   ; LCD Clock Prescaler Bit 1
LCDCR0_LCLK2        equ       5                   ; LCD Clock Prescaler Bit 2
LCDCR0_LPWAVE       equ       6                   ; LCD Waveform
LCDCR0_LCDEN        equ       7                   ; LCD Driver Enable
; bit position masks
mLCDCR0_DUTY0       equ       %00000001
mLCDCR0_DUTY1       equ       %00000010
mLCDCR0_LCLK0       equ       %00001000
mLCDCR0_LCLK1       equ       %00010000
mLCDCR0_LCLK2       equ       %00100000
mLCDCR0_LPWAVE      equ       %01000000
mLCDCR0_LCDEN       equ       %10000000

;*** LCDCR1 - LCD Control Register 1
LCDCR1              equ       $00001841           ;*** LCDCR1 - LCD Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDCR1_LCDSTP3      equ       0                   ; LCD Module Driver and Charge Pump Stop While in Stop3 Mode
LCDCR1_LCDWAI       equ       1                   ; LCD Module Driver and Charge Pump Stop While in Wait Mode
LCDCR1_LCDIEN       equ       7                   ; LCD Module Frame Frequency Interrupt Enable
; bit position masks
mLCDCR1_LCDSTP3     equ       %00000001
mLCDCR1_LCDWAI      equ       %00000010
mLCDCR1_LCDIEN      equ       %10000000

;*** FPENR0 - LCD Frontplane Enable Registers 0
FPENR0              equ       $00001842           ;*** FPENR0 - LCD Frontplane Enable Registers 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPENR0_FP0EN        equ       0                   ; Frontplane Output Enable Bit 0
FPENR0_FP1EN        equ       1                   ; Frontplane Output Enable Bit 1
FPENR0_FP2EN        equ       2                   ; Frontplane Output Enable Bit 2
FPENR0_FP3EN        equ       3                   ; Frontplane Output Enable Bit 3
FPENR0_FP4EN        equ       4                   ; Frontplane Output Enable Bit 4
FPENR0_FP5EN        equ       5                   ; Frontplane Output Enable Bit 5
FPENR0_FP6EN        equ       6                   ; Frontplane Output Enable Bit 6
FPENR0_FP7EN        equ       7                   ; Frontplane Output Enable Bit 7
; bit position masks
mFPENR0_FP0EN       equ       %00000001
mFPENR0_FP1EN       equ       %00000010
mFPENR0_FP2EN       equ       %00000100
mFPENR0_FP3EN       equ       %00001000
mFPENR0_FP4EN       equ       %00010000
mFPENR0_FP5EN       equ       %00100000
mFPENR0_FP6EN       equ       %01000000
mFPENR0_FP7EN       equ       %10000000

;*** FPENR1 - LCD Frontplane Enable Registers 1
FPENR1              equ       $00001843           ;*** FPENR1 - LCD Frontplane Enable Registers 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPENR1_FP8EN        equ       0                   ; Frontplane Output Enable Bit 8
FPENR1_FP9EN        equ       1                   ; Frontplane Output Enable Bit 9
FPENR1_FP10EN       equ       2                   ; Frontplane Output Enable Bit 10
FPENR1_FP11EN       equ       3                   ; Frontplane Output Enable Bit 11
FPENR1_FP12EN       equ       4                   ; Frontplane Output Enable Bit 12
FPENR1_FP13EN       equ       5                   ; Frontplane Output Enable Bit 13
FPENR1_FP14EN       equ       6                   ; Frontplane Output Enable Bit 14
FPENR1_FP15EN       equ       7                   ; Frontplane Output Enable Bit 15
; bit position masks
mFPENR1_FP8EN       equ       %00000001
mFPENR1_FP9EN       equ       %00000010
mFPENR1_FP10EN      equ       %00000100
mFPENR1_FP11EN      equ       %00001000
mFPENR1_FP12EN      equ       %00010000
mFPENR1_FP13EN      equ       %00100000
mFPENR1_FP14EN      equ       %01000000
mFPENR1_FP15EN      equ       %10000000

;*** FPENR2 - LCD Frontplane Enable Registers 2
FPENR2              equ       $00001844           ;*** FPENR2 - LCD Frontplane Enable Registers 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPENR2_FP16EN       equ       0                   ; Frontplane Output Enable Bit 16
FPENR2_FP17EN       equ       1                   ; Frontplane Output Enable Bit 17
FPENR2_FP18EN       equ       2                   ; Frontplane Output Enable Bit 18
FPENR2_FP19EN       equ       3                   ; Frontplane Output Enable Bit 19
FPENR2_FP20EN       equ       4                   ; Frontplane Output Enable Bit 20
FPENR2_FP21EN       equ       5                   ; Frontplane Output Enable Bit 21
FPENR2_FP22EN       equ       6                   ; Frontplane Output Enable Bit 22
FPENR2_FP23EN       equ       7                   ; Frontplane Output Enable Bit 23
; bit position masks
mFPENR2_FP16EN      equ       %00000001
mFPENR2_FP17EN      equ       %00000010
mFPENR2_FP18EN      equ       %00000100
mFPENR2_FP19EN      equ       %00001000
mFPENR2_FP20EN      equ       %00010000
mFPENR2_FP21EN      equ       %00100000
mFPENR2_FP22EN      equ       %01000000
mFPENR2_FP23EN      equ       %10000000

;*** FPENR3 - LCD Frontplane Enable Registers 3
FPENR3              equ       $00001845           ;*** FPENR3 - LCD Frontplane Enable Registers 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPENR3_FP24EN       equ       0                   ; Frontplane Output Enable Bit 24
FPENR3_FP25EN       equ       1                   ; Frontplane Output Enable Bit 25
FPENR3_FP26EN       equ       2                   ; Frontplane Output Enable Bit 26
FPENR3_FP27EN       equ       3                   ; Frontplane Output Enable Bit 27
FPENR3_FP28EN       equ       4                   ; Frontplane Output Enable Bit 28
FPENR3_FP29EN       equ       5                   ; Frontplane Output Enable Bit 29
FPENR3_FP30EN       equ       6                   ; Frontplane Output Enable Bit 30
FPENR3_FP31EN       equ       7                   ; Frontplane Output Enable Bit 31
; bit position masks
mFPENR3_FP24EN      equ       %00000001
mFPENR3_FP25EN      equ       %00000010
mFPENR3_FP26EN      equ       %00000100
mFPENR3_FP27EN      equ       %00001000
mFPENR3_FP28EN      equ       %00010000
mFPENR3_FP29EN      equ       %00100000
mFPENR3_FP30EN      equ       %01000000
mFPENR3_FP31EN      equ       %10000000

;*** FPENR4 - LCD Frontplane Enable Registers 4
FPENR4              equ       $00001846           ;*** FPENR4 - LCD Frontplane Enable Registers 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPENR4_FP32EN       equ       0                   ; Frontplane Output Enable Bit 32
FPENR4_FP33EN       equ       1                   ; Frontplane Output Enable Bit 33
FPENR4_FP34EN       equ       2                   ; Frontplane Output Enable Bit 34
FPENR4_FP35EN       equ       3                   ; Frontplane Output Enable Bit 35
FPENR4_FP36EN       equ       4                   ; Frontplane Output Enable Bit 36
FPENR4_FP37EN       equ       5                   ; Frontplane Output Enable Bit 37
FPENR4_FP38EN       equ       6                   ; Frontplane Output Enable Bit 38
FPENR4_FP39EN       equ       7                   ; Frontplane Output Enable Bit 39
; bit position masks
mFPENR4_FP32EN      equ       %00000001
mFPENR4_FP33EN      equ       %00000010
mFPENR4_FP34EN      equ       %00000100
mFPENR4_FP35EN      equ       %00001000
mFPENR4_FP36EN      equ       %00010000
mFPENR4_FP37EN      equ       %00100000
mFPENR4_FP38EN      equ       %01000000
mFPENR4_FP39EN      equ       %10000000

;*** FPENR5 - LCD Frontplane Enable Registers 5
FPENR5              equ       $00001847           ;*** FPENR5 - LCD Frontplane Enable Registers 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPENR5_FP40EN       equ       0                   ; Frontplane Output Enable Bit 40
; bit position masks
mFPENR5_FP40EN      equ       %00000001

;*** LCDRAM0 - LCDRAM Register 0
LCDRAM0             equ       $00001848           ;*** LCDRAM0 - LCDRAM Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM0_FP0BP0      equ       0                   ; LCD Segment 0 Data Bit 0
LCDRAM0_FP0BP1      equ       1                   ; LCD Segment 0 Data Bit 1
LCDRAM0_FP0BP2      equ       2                   ; LCD Segment 0 Data Bit 2
LCDRAM0_FP0BP3      equ       3                   ; LCD Segment 0 Data Bit 3
LCDRAM0_FP1BP0      equ       4                   ; LCD Segment 1 Data Bit 0
LCDRAM0_FP1BP1      equ       5                   ; LCD Segment 1 Data Bit 1
LCDRAM0_FP1BP2      equ       6                   ; LCD Segment 1 Data Bit 2
LCDRAM0_FP1BP3      equ       7                   ; LCD Segment 1 Data Bit 3
; bit position masks
mLCDRAM0_FP0BP0     equ       %00000001
mLCDRAM0_FP0BP1     equ       %00000010
mLCDRAM0_FP0BP2     equ       %00000100
mLCDRAM0_FP0BP3     equ       %00001000
mLCDRAM0_FP1BP0     equ       %00010000
mLCDRAM0_FP1BP1     equ       %00100000
mLCDRAM0_FP1BP2     equ       %01000000
mLCDRAM0_FP1BP3     equ       %10000000

;*** LCDRAM1 - LCDRAM Register 1
LCDRAM1             equ       $00001849           ;*** LCDRAM1 - LCDRAM Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM1_FP2BP0      equ       0                   ; LCD Segment 2 Data Bit 0
LCDRAM1_FP2BP1      equ       1                   ; LCD Segment 2 Data Bit 1
LCDRAM1_FP2BP2      equ       2                   ; LCD Segment 2 Data Bit 2
LCDRAM1_FP2BP3      equ       3                   ; LCD Segment 2 Data Bit 3
LCDRAM1_FP3BP0      equ       4                   ; LCD Segment 3 Data Bit 0
LCDRAM1_FP3BP1      equ       5                   ; LCD Segment 3 Data Bit 1
LCDRAM1_FP3BP2      equ       6                   ; LCD Segment 3 Data Bit 2
LCDRAM1_FP3BP3      equ       7                   ; LCD Segment 3 Data Bit 3
; bit position masks
mLCDRAM1_FP2BP0     equ       %00000001
mLCDRAM1_FP2BP1     equ       %00000010
mLCDRAM1_FP2BP2     equ       %00000100
mLCDRAM1_FP2BP3     equ       %00001000
mLCDRAM1_FP3BP0     equ       %00010000
mLCDRAM1_FP3BP1     equ       %00100000
mLCDRAM1_FP3BP2     equ       %01000000
mLCDRAM1_FP3BP3     equ       %10000000

;*** LCDRAM2 - LCDRAM Register 2
LCDRAM2             equ       $0000184A           ;*** LCDRAM2 - LCDRAM Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM2_FP4BP0      equ       0                   ; LCD Segment 4 Data Bit 0
LCDRAM2_FP4BP1      equ       1                   ; LCD Segment 4 Data Bit 1
LCDRAM2_FP4BP2      equ       2                   ; LCD Segment 4 Data Bit 2
LCDRAM2_FP4BP3      equ       3                   ; LCD Segment 4 Data Bit 3
LCDRAM2_FP5BP0      equ       4                   ; LCD Segment 5 Data Bit 0
LCDRAM2_FP5BP1      equ       5                   ; LCD Segment 5 Data Bit 1
LCDRAM2_FP5BP2      equ       6                   ; LCD Segment 5 Data Bit 2
LCDRAM2_FP5BP3      equ       7                   ; LCD Segment 5 Data Bit 3
; bit position masks
mLCDRAM2_FP4BP0     equ       %00000001
mLCDRAM2_FP4BP1     equ       %00000010
mLCDRAM2_FP4BP2     equ       %00000100
mLCDRAM2_FP4BP3     equ       %00001000
mLCDRAM2_FP5BP0     equ       %00010000
mLCDRAM2_FP5BP1     equ       %00100000
mLCDRAM2_FP5BP2     equ       %01000000
mLCDRAM2_FP5BP3     equ       %10000000

;*** LCDRAM3 - LCDRAM Register 3
LCDRAM3             equ       $0000184B           ;*** LCDRAM3 - LCDRAM Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM3_FP6BP0      equ       0                   ; LCD Segment 6 Data Bit 0
LCDRAM3_FP6BP1      equ       1                   ; LCD Segment 6 Data Bit 1
LCDRAM3_FP6BP2      equ       2                   ; LCD Segment 6 Data Bit 2
LCDRAM3_FP6BP3      equ       3                   ; LCD Segment 6 Data Bit 3
LCDRAM3_FP7BP0      equ       4                   ; LCD Segment 7 Data Bit 0
LCDRAM3_FP7BP1      equ       5                   ; LCD Segment 7 Data Bit 1
LCDRAM3_FP7BP2      equ       6                   ; LCD Segment 7 Data Bit 2
LCDRAM3_FP7BP3      equ       7                   ; LCD Segment 7 Data Bit 3
; bit position masks
mLCDRAM3_FP6BP0     equ       %00000001
mLCDRAM3_FP6BP1     equ       %00000010
mLCDRAM3_FP6BP2     equ       %00000100
mLCDRAM3_FP6BP3     equ       %00001000
mLCDRAM3_FP7BP0     equ       %00010000
mLCDRAM3_FP7BP1     equ       %00100000
mLCDRAM3_FP7BP2     equ       %01000000
mLCDRAM3_FP7BP3     equ       %10000000

;*** LCDRAM4 - LCDRAM Register 4
LCDRAM4             equ       $0000184C           ;*** LCDRAM4 - LCDRAM Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM4_FP8BP0      equ       0                   ; LCD Segment 8 Data Bit 0
LCDRAM4_FP8BP1      equ       1                   ; LCD Segment 8 Data Bit 1
LCDRAM4_FP8BP2      equ       2                   ; LCD Segment 8 Data Bit 2
LCDRAM4_FP8BP3      equ       3                   ; LCD Segment 8 Data Bit 3
LCDRAM4_FP9BP0      equ       4                   ; LCD Segment 9 Data Bit 0
LCDRAM4_FP9BP1      equ       5                   ; LCD Segment 9 Data Bit 1
LCDRAM4_FP9BP2      equ       6                   ; LCD Segment 9 Data Bit 2
LCDRAM4_FP9BP3      equ       7                   ; LCD Segment 9 Data Bit 3
; bit position masks
mLCDRAM4_FP8BP0     equ       %00000001
mLCDRAM4_FP8BP1     equ       %00000010
mLCDRAM4_FP8BP2     equ       %00000100
mLCDRAM4_FP8BP3     equ       %00001000
mLCDRAM4_FP9BP0     equ       %00010000
mLCDRAM4_FP9BP1     equ       %00100000
mLCDRAM4_FP9BP2     equ       %01000000
mLCDRAM4_FP9BP3     equ       %10000000

;*** LCDRAM5 - LCDRAM Register 5
LCDRAM5             equ       $0000184D           ;*** LCDRAM5 - LCDRAM Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM5_FP10BP0     equ       0                   ; LCD Segment 10 Data Bit 0
LCDRAM5_FP10BP1     equ       1                   ; LCD Segment 10 Data Bit 1
LCDRAM5_FP10BP2     equ       2                   ; LCD Segment 10 Data Bit 2
LCDRAM5_FP10BP3     equ       3                   ; LCD Segment 10 Data Bit 3
LCDRAM5_FP11BP0     equ       4                   ; LCD Segment 11 Data Bit 0
LCDRAM5_FP11BP1     equ       5                   ; LCD Segment 11 Data Bit 1
LCDRAM5_FP11BP2     equ       6                   ; LCD Segment 11 Data Bit 2
LCDRAM5_FP11BP3     equ       7                   ; LCD Segment 11 Data Bit 3
; bit position masks
mLCDRAM5_FP10BP0    equ       %00000001
mLCDRAM5_FP10BP1    equ       %00000010
mLCDRAM5_FP10BP2    equ       %00000100
mLCDRAM5_FP10BP3    equ       %00001000
mLCDRAM5_FP11BP0    equ       %00010000
mLCDRAM5_FP11BP1    equ       %00100000
mLCDRAM5_FP11BP2    equ       %01000000
mLCDRAM5_FP11BP3    equ       %10000000

;*** LCDRAM6 - LCDRAM Register 6
LCDRAM6             equ       $0000184E           ;*** LCDRAM6 - LCDRAM Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM6_FP12BP0     equ       0                   ; LCD Segment 12 Data Bit 0
LCDRAM6_FP12BP1     equ       1                   ; LCD Segment 12 Data Bit 1
LCDRAM6_FP12BP2     equ       2                   ; LCD Segment 12 Data Bit 2
LCDRAM6_FP12BP3     equ       3                   ; LCD Segment 12 Data Bit 3
LCDRAM6_FP13BP0     equ       4                   ; LCD Segment 13 Data Bit 0
LCDRAM6_FP13BP1     equ       5                   ; LCD Segment 13 Data Bit 1
LCDRAM6_FP13BP2     equ       6                   ; LCD Segment 13 Data Bit 2
LCDRAM6_FP13BP3     equ       7                   ; LCD Segment 13 Data Bit 3
; bit position masks
mLCDRAM6_FP12BP0    equ       %00000001
mLCDRAM6_FP12BP1    equ       %00000010
mLCDRAM6_FP12BP2    equ       %00000100
mLCDRAM6_FP12BP3    equ       %00001000
mLCDRAM6_FP13BP0    equ       %00010000
mLCDRAM6_FP13BP1    equ       %00100000
mLCDRAM6_FP13BP2    equ       %01000000
mLCDRAM6_FP13BP3    equ       %10000000

;*** LCDRAM7 - LCDRAM Register 7
LCDRAM7             equ       $0000184F           ;*** LCDRAM7 - LCDRAM Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM7_FP14BP0     equ       0                   ; LCD Segment 14 Data Bit 0
LCDRAM7_FP14BP1     equ       1                   ; LCD Segment 14 Data Bit 1
LCDRAM7_FP14BP2     equ       2                   ; LCD Segment 14 Data Bit 2
LCDRAM7_FP14BP3     equ       3                   ; LCD Segment 14 Data Bit 3
LCDRAM7_FP15BP0     equ       4                   ; LCD Segment 15 Data Bit 0
LCDRAM7_FP15BP1     equ       5                   ; LCD Segment 15 Data Bit 1
LCDRAM7_FP15BP2     equ       6                   ; LCD Segment 15 Data Bit 2
LCDRAM7_FP15BP3     equ       7                   ; LCD Segment 15 Data Bit 3
; bit position masks
mLCDRAM7_FP14BP0    equ       %00000001
mLCDRAM7_FP14BP1    equ       %00000010
mLCDRAM7_FP14BP2    equ       %00000100
mLCDRAM7_FP14BP3    equ       %00001000
mLCDRAM7_FP15BP0    equ       %00010000
mLCDRAM7_FP15BP1    equ       %00100000
mLCDRAM7_FP15BP2    equ       %01000000
mLCDRAM7_FP15BP3    equ       %10000000

;*** LCDRAM8 - LCDRAM Register 8
LCDRAM8             equ       $00001850           ;*** LCDRAM8 - LCDRAM Register 8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM8_FP16BP0     equ       0                   ; LCD Segment 16 Data Bit 0
LCDRAM8_FP16BP1     equ       1                   ; LCD Segment 16 Data Bit 1
LCDRAM8_FP16BP2     equ       2                   ; LCD Segment 16 Data Bit 2
LCDRAM8_FP16BP3     equ       3                   ; LCD Segment 16 Data Bit 3
LCDRAM8_FP17BP0     equ       4                   ; LCD Segment 17 Data Bit 0
LCDRAM8_FP17BP1     equ       5                   ; LCD Segment 17 Data Bit 1
LCDRAM8_FP17BP2     equ       6                   ; LCD Segment 17 Data Bit 2
LCDRAM8_FP17BP3     equ       7                   ; LCD Segment 17 Data Bit 3
; bit position masks
mLCDRAM8_FP16BP0    equ       %00000001
mLCDRAM8_FP16BP1    equ       %00000010
mLCDRAM8_FP16BP2    equ       %00000100
mLCDRAM8_FP16BP3    equ       %00001000
mLCDRAM8_FP17BP0    equ       %00010000
mLCDRAM8_FP17BP1    equ       %00100000
mLCDRAM8_FP17BP2    equ       %01000000
mLCDRAM8_FP17BP3    equ       %10000000

;*** LCDRAM9 - LCDRAM Register 9
LCDRAM9             equ       $00001851           ;*** LCDRAM9 - LCDRAM Register 9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM9_FP18BP0     equ       0                   ; LCD Segment 18 Data Bit 0
LCDRAM9_FP18BP1     equ       1                   ; LCD Segment 18 Data Bit 1
LCDRAM9_FP18BP2     equ       2                   ; LCD Segment 18 Data Bit 2
LCDRAM9_FP18BP3     equ       3                   ; LCD Segment 18 Data Bit 3
LCDRAM9_FP19BP0     equ       4                   ; LCD Segment 19 Data Bit 0
LCDRAM9_FP19BP1     equ       5                   ; LCD Segment 19 Data Bit 1
LCDRAM9_FP19BP2     equ       6                   ; LCD Segment 19 Data Bit 2
LCDRAM9_FP19BP3     equ       7                   ; LCD Segment 19 Data Bit 3
; bit position masks
mLCDRAM9_FP18BP0    equ       %00000001
mLCDRAM9_FP18BP1    equ       %00000010
mLCDRAM9_FP18BP2    equ       %00000100
mLCDRAM9_FP18BP3    equ       %00001000
mLCDRAM9_FP19BP0    equ       %00010000
mLCDRAM9_FP19BP1    equ       %00100000
mLCDRAM9_FP19BP2    equ       %01000000
mLCDRAM9_FP19BP3    equ       %10000000

;*** LCDRAM10 - LCDRAM Register 10
LCDRAM10            equ       $00001852           ;*** LCDRAM10 - LCDRAM Register 10
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM10_FP20BP0    equ       0                   ; LCD Segment 20 Data Bit 0
LCDRAM10_FP20BP1    equ       1                   ; LCD Segment 20 Data Bit 1
LCDRAM10_FP20BP2    equ       2                   ; LCD Segment 20 Data Bit 2
LCDRAM10_FP20BP3    equ       3                   ; LCD Segment 20 Data Bit 3
LCDRAM10_FP21BP0    equ       4                   ; LCD Segment 21 Data Bit 0
LCDRAM10_FP21BP1    equ       5                   ; LCD Segment 21 Data Bit 1
LCDRAM10_FP21BP2    equ       6                   ; LCD Segment 21 Data Bit 2
LCDRAM10_FP21BP3    equ       7                   ; LCD Segment 21 Data Bit 3
; bit position masks
mLCDRAM10_FP20BP0   equ       %00000001
mLCDRAM10_FP20BP1   equ       %00000010
mLCDRAM10_FP20BP2   equ       %00000100
mLCDRAM10_FP20BP3   equ       %00001000
mLCDRAM10_FP21BP0   equ       %00010000
mLCDRAM10_FP21BP1   equ       %00100000
mLCDRAM10_FP21BP2   equ       %01000000
mLCDRAM10_FP21BP3   equ       %10000000

;*** LCDRAM11 - LCDRAM Register 11
LCDRAM11            equ       $00001853           ;*** LCDRAM11 - LCDRAM Register 11
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM11_FP22BP0    equ       0                   ; LCD Segment 22 Data Bit 0
LCDRAM11_FP22BP1    equ       1                   ; LCD Segment 22 Data Bit 1
LCDRAM11_FP22BP2    equ       2                   ; LCD Segment 22 Data Bit 2
LCDRAM11_FP22BP3    equ       3                   ; LCD Segment 22 Data Bit 3
LCDRAM11_FP23BP0    equ       4                   ; LCD Segment 23 Data Bit 0
LCDRAM11_FP23BP1    equ       5                   ; LCD Segment 23 Data Bit 1
LCDRAM11_FP23BP2    equ       6                   ; LCD Segment 23 Data Bit 2
LCDRAM11_FP23BP3    equ       7                   ; LCD Segment 23 Data Bit 3
; bit position masks
mLCDRAM11_FP22BP0   equ       %00000001
mLCDRAM11_FP22BP1   equ       %00000010
mLCDRAM11_FP22BP2   equ       %00000100
mLCDRAM11_FP22BP3   equ       %00001000
mLCDRAM11_FP23BP0   equ       %00010000
mLCDRAM11_FP23BP1   equ       %00100000
mLCDRAM11_FP23BP2   equ       %01000000
mLCDRAM11_FP23BP3   equ       %10000000

;*** LCDRAM12 - LCDRAM Register 12
LCDRAM12            equ       $00001854           ;*** LCDRAM12 - LCDRAM Register 12
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM12_FP24BP0    equ       0                   ; LCD Segment 24 Data Bit 0
LCDRAM12_FP24BP1    equ       1                   ; LCD Segment 24 Data Bit 1
LCDRAM12_FP24BP2    equ       2                   ; LCD Segment 24 Data Bit 2
LCDRAM12_FP24BP3    equ       3                   ; LCD Segment 24 Data Bit 3
LCDRAM12_FP25BP0    equ       4                   ; LCD Segment 25 Data Bit 0
LCDRAM12_FP25BP1    equ       5                   ; LCD Segment 25 Data Bit 1
LCDRAM12_FP25BP2    equ       6                   ; LCD Segment 25 Data Bit 2
LCDRAM12_FP25BP3    equ       7                   ; LCD Segment 25 Data Bit 3
; bit position masks
mLCDRAM12_FP24BP0   equ       %00000001
mLCDRAM12_FP24BP1   equ       %00000010
mLCDRAM12_FP24BP2   equ       %00000100
mLCDRAM12_FP24BP3   equ       %00001000
mLCDRAM12_FP25BP0   equ       %00010000
mLCDRAM12_FP25BP1   equ       %00100000
mLCDRAM12_FP25BP2   equ       %01000000
mLCDRAM12_FP25BP3   equ       %10000000

;*** LCDRAM13 - LCDRAM Register 13
LCDRAM13            equ       $00001855           ;*** LCDRAM13 - LCDRAM Register 13
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM13_FP26BP0    equ       0                   ; LCD Segment 26 Data Bit 0
LCDRAM13_FP26BP1    equ       1                   ; LCD Segment 26 Data Bit 1
LCDRAM13_FP26BP2    equ       2                   ; LCD Segment 26 Data Bit 2
LCDRAM13_FP26BP3    equ       3                   ; LCD Segment 26 Data Bit 3
LCDRAM13_FP27BP0    equ       4                   ; LCD Segment 27 Data Bit 0
LCDRAM13_FP27BP1    equ       5                   ; LCD Segment 27 Data Bit 1
LCDRAM13_FP27BP2    equ       6                   ; LCD Segment 27 Data Bit 2
LCDRAM13_FP27BP3    equ       7                   ; LCD Segment 27 Data Bit 3
; bit position masks
mLCDRAM13_FP26BP0   equ       %00000001
mLCDRAM13_FP26BP1   equ       %00000010
mLCDRAM13_FP26BP2   equ       %00000100
mLCDRAM13_FP26BP3   equ       %00001000
mLCDRAM13_FP27BP0   equ       %00010000
mLCDRAM13_FP27BP1   equ       %00100000
mLCDRAM13_FP27BP2   equ       %01000000
mLCDRAM13_FP27BP3   equ       %10000000

;*** LCDRAM14 - LCDRAM Register 14
LCDRAM14            equ       $00001856           ;*** LCDRAM14 - LCDRAM Register 14
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM14_FP28BP0    equ       0                   ; LCD Segment 28 Data Bit 0
LCDRAM14_FP28BP1    equ       1                   ; LCD Segment 28 Data Bit 1
LCDRAM14_FP28BP2    equ       2                   ; LCD Segment 28 Data Bit 2
LCDRAM14_FP28BP3    equ       3                   ; LCD Segment 28 Data Bit 3
LCDRAM14_FP29BP0    equ       4                   ; LCD Segment 29 Data Bit 0
LCDRAM14_FP29BP1    equ       5                   ; LCD Segment 29 Data Bit 1
LCDRAM14_FP29BP2    equ       6                   ; LCD Segment 29 Data Bit 2
LCDRAM14_FP29BP3    equ       7                   ; LCD Segment 29 Data Bit 3
; bit position masks
mLCDRAM14_FP28BP0   equ       %00000001
mLCDRAM14_FP28BP1   equ       %00000010
mLCDRAM14_FP28BP2   equ       %00000100
mLCDRAM14_FP28BP3   equ       %00001000
mLCDRAM14_FP29BP0   equ       %00010000
mLCDRAM14_FP29BP1   equ       %00100000
mLCDRAM14_FP29BP2   equ       %01000000
mLCDRAM14_FP29BP3   equ       %10000000

;*** LCDRAM15 - LCDRAM Register 15
LCDRAM15            equ       $00001857           ;*** LCDRAM15 - LCDRAM Register 15
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM15_FP30BP0    equ       0                   ; LCD Segment 30 Data Bit 0
LCDRAM15_FP30BP1    equ       1                   ; LCD Segment 30 Data Bit 1
LCDRAM15_FP30BP2    equ       2                   ; LCD Segment 30 Data Bit 2
LCDRAM15_FP30BP3    equ       3                   ; LCD Segment 30 Data Bit 3
LCDRAM15_FP31BP0    equ       4                   ; LCD Segment 31 Data Bit 0
LCDRAM15_FP31BP1    equ       5                   ; LCD Segment 31 Data Bit 1
LCDRAM15_FP31BP2    equ       6                   ; LCD Segment 31 Data Bit 2
LCDRAM15_FP31BP3    equ       7                   ; LCD Segment 31 Data Bit 3
; bit position masks
mLCDRAM15_FP30BP0   equ       %00000001
mLCDRAM15_FP30BP1   equ       %00000010
mLCDRAM15_FP30BP2   equ       %00000100
mLCDRAM15_FP30BP3   equ       %00001000
mLCDRAM15_FP31BP0   equ       %00010000
mLCDRAM15_FP31BP1   equ       %00100000
mLCDRAM15_FP31BP2   equ       %01000000
mLCDRAM15_FP31BP3   equ       %10000000

;*** LCDRAM16 - LCDRAM Register 16
LCDRAM16            equ       $00001858           ;*** LCDRAM16 - LCDRAM Register 16
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM16_FP32BP0    equ       0                   ; LCD Segment 32 Data Bit 0
LCDRAM16_FP32BP1    equ       1                   ; LCD Segment 32 Data Bit 1
LCDRAM16_FP32BP2    equ       2                   ; LCD Segment 32 Data Bit 2
LCDRAM16_FP32BP3    equ       3                   ; LCD Segment 32 Data Bit 3
LCDRAM16_FP33BP0    equ       4                   ; LCD Segment 33 Data Bit 0
LCDRAM16_FP33BP1    equ       5                   ; LCD Segment 33 Data Bit 1
LCDRAM16_FP33BP2    equ       6                   ; LCD Segment 33 Data Bit 2
LCDRAM16_FP33BP3    equ       7                   ; LCD Segment 33 Data Bit 3
; bit position masks
mLCDRAM16_FP32BP0   equ       %00000001
mLCDRAM16_FP32BP1   equ       %00000010
mLCDRAM16_FP32BP2   equ       %00000100
mLCDRAM16_FP32BP3   equ       %00001000
mLCDRAM16_FP33BP0   equ       %00010000
mLCDRAM16_FP33BP1   equ       %00100000
mLCDRAM16_FP33BP2   equ       %01000000
mLCDRAM16_FP33BP3   equ       %10000000

;*** LCDRAM17 - LCDRAM Register 17
LCDRAM17            equ       $00001859           ;*** LCDRAM17 - LCDRAM Register 17
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM17_FP34BP0    equ       0                   ; LCD Segment 34 Data Bit 0
LCDRAM17_FP34BP1    equ       1                   ; LCD Segment 34 Data Bit 1
LCDRAM17_FP34BP2    equ       2                   ; LCD Segment 34 Data Bit 2
LCDRAM17_FP34BP3    equ       3                   ; LCD Segment 34 Data Bit 3
LCDRAM17_FP35BP0    equ       4                   ; LCD Segment 35 Data Bit 0
LCDRAM17_FP35BP1    equ       5                   ; LCD Segment 35 Data Bit 1
LCDRAM17_FP35BP2    equ       6                   ; LCD Segment 35 Data Bit 2
LCDRAM17_FP35BP3    equ       7                   ; LCD Segment 35 Data Bit 3
; bit position masks
mLCDRAM17_FP34BP0   equ       %00000001
mLCDRAM17_FP34BP1   equ       %00000010
mLCDRAM17_FP34BP2   equ       %00000100
mLCDRAM17_FP34BP3   equ       %00001000
mLCDRAM17_FP35BP0   equ       %00010000
mLCDRAM17_FP35BP1   equ       %00100000
mLCDRAM17_FP35BP2   equ       %01000000
mLCDRAM17_FP35BP3   equ       %10000000

;*** LCDRAM18 - LCDRAM Register 18
LCDRAM18            equ       $0000185A           ;*** LCDRAM18 - LCDRAM Register 18
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM18_FP36BP0    equ       0                   ; LCD Segment 36 Data Bit 0
LCDRAM18_FP36BP1    equ       1                   ; LCD Segment 36 Data Bit 1
LCDRAM18_FP36BP2    equ       2                   ; LCD Segment 36 Data Bit 2
LCDRAM18_FP36BP3    equ       3                   ; LCD Segment 36 Data Bit 3
LCDRAM18_FP37BP0    equ       4                   ; LCD Segment 37 Data Bit 0
LCDRAM18_FP37BP1    equ       5                   ; LCD Segment 37 Data Bit 1
LCDRAM18_FP37BP2    equ       6                   ; LCD Segment 37 Data Bit 2
LCDRAM18_FP37BP3    equ       7                   ; LCD Segment 37 Data Bit 3
; bit position masks
mLCDRAM18_FP36BP0   equ       %00000001
mLCDRAM18_FP36BP1   equ       %00000010
mLCDRAM18_FP36BP2   equ       %00000100
mLCDRAM18_FP36BP3   equ       %00001000
mLCDRAM18_FP37BP0   equ       %00010000
mLCDRAM18_FP37BP1   equ       %00100000
mLCDRAM18_FP37BP2   equ       %01000000
mLCDRAM18_FP37BP3   equ       %10000000

;*** LCDRAM19 - LCDRAM Register 19
LCDRAM19            equ       $0000185B           ;*** LCDRAM19 - LCDRAM Register 19
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM19_FP38BP0    equ       0                   ; LCD Segment 38 Data Bit 0
LCDRAM19_FP38BP1    equ       1                   ; LCD Segment 38 Data Bit 1
LCDRAM19_FP38BP2    equ       2                   ; LCD Segment 38 Data Bit 2
LCDRAM19_FP38BP3    equ       3                   ; LCD Segment 38 Data Bit 3
LCDRAM19_FP39BP0    equ       4                   ; LCD Segment 39 Data Bit 0
LCDRAM19_FP39BP1    equ       5                   ; LCD Segment 39 Data Bit 1
LCDRAM19_FP39BP2    equ       6                   ; LCD Segment 39 Data Bit 2
LCDRAM19_FP39BP3    equ       7                   ; LCD Segment 39 Data Bit 3
; bit position masks
mLCDRAM19_FP38BP0   equ       %00000001
mLCDRAM19_FP38BP1   equ       %00000010
mLCDRAM19_FP38BP2   equ       %00000100
mLCDRAM19_FP38BP3   equ       %00001000
mLCDRAM19_FP39BP0   equ       %00010000
mLCDRAM19_FP39BP1   equ       %00100000
mLCDRAM19_FP39BP2   equ       %01000000
mLCDRAM19_FP39BP3   equ       %10000000

;*** LCDRAM20 - LCDRAM Register 20
LCDRAM20            equ       $0000185C           ;*** LCDRAM20 - LCDRAM Register 20
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRAM20_FP40BP0    equ       0                   ; LCD Segment 40 Data Bit 0
LCDRAM20_FP40BP1    equ       1                   ; LCD Segment 40 Data Bit 1
LCDRAM20_FP40BP2    equ       2                   ; LCD Segment 40 Data Bit 2
LCDRAM20_FP40BP3    equ       3                   ; LCD Segment 40 Data Bit 3
; bit position masks
mLCDRAM20_FP40BP0   equ       %00000001
mLCDRAM20_FP40BP1   equ       %00000010
mLCDRAM20_FP40BP2   equ       %00000100
mLCDRAM20_FP40BP3   equ       %00001000

;*** LCDCLKS - LCD Clock Source Register
LCDCLKS             equ       $00001862           ;*** LCDCLKS - LCD Clock Source Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDCLKS_CLKADJ0     equ       0                   ; LCD Clock Source Divider Bit 0
LCDCLKS_CLKADJ1     equ       1                   ; LCD Clock Source Divider Bit 1
LCDCLKS_CLKADJ2     equ       2                   ; LCD Clock Source Divider Bit 2
LCDCLKS_CLKADJ3     equ       3                   ; LCD Clock Source Divider Bit 3
LCDCLKS_CLKADJ4     equ       4                   ; LCD Clock Source Divider Bit 4
LCDCLKS_CLKADJ5     equ       5                   ; LCD Clock Source Divider Bit 5
LCDCLKS_DIV16       equ       6                   ; LCD Clock Prescaler Enable
LCDCLKS_SOURCE      equ       7                   ; LCD Clock Source Select
; bit position masks
mLCDCLKS_CLKADJ0    equ       %00000001
mLCDCLKS_CLKADJ1    equ       %00000010
mLCDCLKS_CLKADJ2    equ       %00000100
mLCDCLKS_CLKADJ3    equ       %00001000
mLCDCLKS_CLKADJ4    equ       %00010000
mLCDCLKS_CLKADJ5    equ       %00100000
mLCDCLKS_DIV16      equ       %01000000
mLCDCLKS_SOURCE     equ       %10000000

;*** LCDSUPPLY - LCD Voltage Supply Register
LCDSUPPLY           equ       $00001863           ;*** LCDSUPPLY - LCD Voltage Supply Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDSUPPLY_VSUPPLY0  equ       0                   ; Blink Rate Configuration Bit 0
LCDSUPPLY_VSUPPLY1  equ       1                   ; Blink Rate Configuration Bit 1
LCDSUPPLY_BBYPASS   equ       2                   ; Op Amp Control
LCDSUPPLY_HDRVBUF   equ       3                   ; High Drive Buffer Mode Select
LCDSUPPLY_CPCADJ0   equ       4                   ; LCD Module Charge Pump Clock Adjust Bit 0
LCDSUPPLY_CPCADJ1   equ       5                   ; LCD Module Charge Pump Clock Adjust Bit 1
LCDSUPPLY_LCDCPMS   equ       6                   ; LCD Module Charge Pump Mode Select
LCDSUPPLY_LCDCPEN   equ       7                   ; LCD Module Charge Pump Enable
; bit position masks
mLCDSUPPLY_VSUPPLY0 equ       %00000001
mLCDSUPPLY_VSUPPLY1 equ       %00000010
mLCDSUPPLY_BBYPASS  equ       %00000100
mLCDSUPPLY_HDRVBUF  equ       %00001000
mLCDSUPPLY_CPCADJ0  equ       %00010000
mLCDSUPPLY_CPCADJ1  equ       %00100000
mLCDSUPPLY_LCDCPMS  equ       %01000000
mLCDSUPPLY_LCDCPEN  equ       %10000000

;*** LCDBCTL - LCD Blink Control Register
LCDBCTL             equ       $00001864           ;*** LCDBCTL - LCD Blink Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBCTL_BRATE0      equ       0                   ; Blink Rate Configuration Bit 0
LCDBCTL_BRATE1      equ       1                   ; Blink Rate Configuration Bit 1
LCDBCTL_BRATE2      equ       2                   ; Blink Rate Configuration Bit 2
LCDBCTL_BLKMODE     equ       3                   ; Blink Mode Select
LCDBCTL_BLINK       equ       7                   ; Blink Command
; bit position masks
mLCDBCTL_BRATE0     equ       %00000001
mLCDBCTL_BRATE1     equ       %00000010
mLCDBCTL_BRATE2     equ       %00000100
mLCDBCTL_BLKMODE    equ       %00001000
mLCDBCTL_BLINK      equ       %10000000

;*** LCDCMD - LCD Command and Status Register
LCDCMD              equ       $00001865           ;*** LCDCMD - LCD Command and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDCMD_BLANK        equ       0                   ; LCD Display Blank Command
LCDCMD_LCDCLR       equ       1                   ; LCD Data Register Clear Command
LCDCMD_LCDDRMS      equ       3                   ; LCD Module Data Register Mode Select
LCDCMD_LCDIF        equ       7                   ; LCD Interrupt Flag
; bit position masks
mLCDCMD_BLANK       equ       %00000001
mLCDCMD_LCDCLR      equ       %00000010
mLCDCMD_LCDDRMS     equ       %00001000
mLCDCMD_LCDIF       equ       %10000000

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

;*** NVICGTRM - ICG Trim Register
NVICGTRM            equ       $0000FFBE           ;*** NVICGTRM - ICG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVICGTRM_NVTRIM0    equ       0                   ; ICG Trim Bit 0
NVICGTRM_NVTRIM1    equ       1                   ; ICG Trim Bit 1
NVICGTRM_NVTRIM2    equ       2                   ; ICG Trim Bit 2
NVICGTRM_NVTRIM3    equ       3                   ; ICG Trim Bit 3
NVICGTRM_NVTRIM4    equ       4                   ; ICG Trim Bit 4
NVICGTRM_NVTRIM5    equ       5                   ; ICG Trim Bit 5
NVICGTRM_NVTRIM6    equ       6                   ; ICG Trim Bit 6
NVICGTRM_NVTRIM7    equ       7                   ; ICG Trim Bit 7
; bit position masks
mNVICGTRM_NVTRIM0   equ       %00000001
mNVICGTRM_NVTRIM1   equ       %00000010
mNVICGTRM_NVTRIM2   equ       %00000100
mNVICGTRM_NVTRIM3   equ       %00001000
mNVICGTRM_NVTRIM4   equ       %00010000
mNVICGTRM_NVTRIM5   equ       %00100000
mNVICGTRM_NVTRIM6   equ       %01000000
mNVICGTRM_NVTRIM7   equ       %10000000

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
