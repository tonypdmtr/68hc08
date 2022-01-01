;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9RS08KB12_20, version 3.00.009 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9rs08kb4.inc
;     Processor : MC9RS08KB4CWJ
;     FileFormat: V2.32
;     DataSheet : MC9RS08KB12RM Rev. 2 8/2009
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 14:53
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
;               - Changes have not affected this file (because they are related to another family)
;      - 18.05.2010, V2.32 :
;               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map
;******************************************
RESERVED_XRAM       equ       $00000000
RESERVED_XRAM_END   equ       $00000004
TINY_XRAM           equ       $00000005
TINY_XRAM_END       equ       $0000000D
INT_XRAM            equ       $00000050
INT_XRAM_END        equ       $00000054
XRAM                equ       $00000055
XRAM_END            equ       $000000BF
ROM                 equ       $00003000
ROM_END             equ       $00003FF6
;
;

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
; bit position masks
mADCRH_ADR8         equ       %00000001
mADCRH_ADR9         equ       %00000010

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
; bit position masks
mADCCVH_ADCV8       equ       %00000001
mADCCVH_ADCV9       equ       %00000010

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
; bit position masks
mAPCTL2_ADPC8       equ       %00000001
mAPCTL2_ADPC9       equ       %00000010
mAPCTL2_ADPC10      equ       %00000100
mAPCTL2_ADPC11      equ       %00001000

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

;*** SIP1 - System Interrupt Pending Register
SIP1                equ       $0000001C           ;*** SIP1 - System Interrupt Pending Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIP1_RTI            equ       0                   ; Real-TimeInterruptPending
SIP1_MTIM1          equ       1                   ; Modulo Timer 1 Interrupt Pending
SIP1_MTIM2          equ       2                   ; Modulo Timer 2 Interrupt Pending
SIP1_IIC            equ       3                   ; IIC Interrupt Pending
SIP1_ADC            equ       4                   ; ADC Interrupt Pending
SIP1_ACMP           equ       5                   ; Analog Comparator Interrupt Pending
SIP1_KBI            equ       6                   ; Keyboard Interrupt Pending
SIP1_LVD            equ       7                   ; Low-VoltageDetectInterruptPending
; bit position masks
mSIP1_RTI           equ       %00000001
mSIP1_MTIM1         equ       %00000010
mSIP1_MTIM2         equ       %00000100
mSIP1_IIC           equ       %00001000
mSIP1_ADC           equ       %00010000
mSIP1_ACMP          equ       %00100000
mSIP1_KBI           equ       %01000000
mSIP1_LVD           equ       %10000000

;*** SIP2 - System Interrupt Pending Register 2
SIP2                equ       $0000001D           ;*** SIP2 - System Interrupt Pending Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIP2_SCIT           equ       0                   ; SCI Transmitter Interrupt Pending
SIP2_SCIR           equ       1                   ; SCI Receiver Interrupt Pending
SIP2_SCIE           equ       2                   ; SCI Error Interrupt Pending
SIP2_TPMOV          equ       4                   ; TPM Overflow Interrupt Pending
SIP2_TPMCH1         equ       5                   ; TPM Channel 1 Interrupt Pending
SIP2_TPMCH0         equ       6                   ; TPM Channel 0 Interrupt Pending
SIP2_IMASK          equ       7                   ; Interrupt Mask
; bit position masks
mSIP2_SCIT          equ       %00000001
mSIP2_SCIR          equ       %00000010
mSIP2_SCIE          equ       %00000100
mSIP2_TPMOV         equ       %00010000
mSIP2_TPMCH1        equ       %00100000
mSIP2_TPMCH0        equ       %01000000
mSIP2_IMASK         equ       %10000000

;*** PAGESEL - Page Select Register
PAGESEL             equ       $0000001F           ;*** PAGESEL - Page Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PAGESEL_AD6         equ       0                   ; Page Selector Bit 6
PAGESEL_AD7         equ       1                   ; Page Selector Bit 7
PAGESEL_AD8         equ       2                   ; Page Selector Bit 8
PAGESEL_AD9         equ       3                   ; Page Selector Bit 9
PAGESEL_AD10        equ       4                   ; Page Selector Bit 10
PAGESEL_AD11        equ       5                   ; Page Selector Bit 11
PAGESEL_AD12        equ       6                   ; Page Selector Bit 12
PAGESEL_AD13        equ       7                   ; Page Selector Bit 13
; bit position masks
mPAGESEL_AD6        equ       %00000001
mPAGESEL_AD7        equ       %00000010
mPAGESEL_AD8        equ       %00000100
mPAGESEL_AD9        equ       %00001000
mPAGESEL_AD10       equ       %00010000
mPAGESEL_AD11       equ       %00100000
mPAGESEL_AD12       equ       %01000000
mPAGESEL_AD13       equ       %10000000

;*** PTAD - Port A Data Register
PTAD                equ       $00000020           ;*** PTAD - Port A Data Register
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
PTADD               equ       $00000021           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; PTADD
PTADD_PTADD1        equ       1                   ; PTADD
PTADD_PTADD2        equ       2                   ; PTADD
PTADD_PTADD3        equ       3                   ; PTADD
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000

;*** PTBD - Port B Data Register
PTBD                equ       $00000022           ;*** PTBD - Port B Data Register
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
PTBDD               equ       $00000023           ;*** PTBDD - Port B Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0        equ       0                   ; PTBDD
PTBDD_PTBDD1        equ       1                   ; PTBDD
PTBDD_PTBDD2        equ       2                   ; PTBDD
PTBDD_PTBDD3        equ       3                   ; PTBDD
PTBDD_PTBDD4        equ       4                   ; PTBDD
PTBDD_PTBDD5        equ       5                   ; PTBDD
PTBDD_PTBDD6        equ       6                   ; PTBDD
PTBDD_PTBDD7        equ       7                   ; PTBDD
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
PTCD                equ       $00000024           ;*** PTCD - Port C Data Register
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
PTCDD               equ       $00000025           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; PTCDD
PTCDD_PTCDD1        equ       1                   ; PTCDD
PTCDD_PTCDD2        equ       2                   ; PTCDD
PTCDD_PTCDD3        equ       3                   ; PTCDD
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000

;*** MTIM1SC - MTIM Clock Configuration Register
MTIM1SC             equ       $00000028           ;*** MTIM1SC - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM1SC_TSTP        equ       4                   ; MTIM Counter Stop
MTIM1SC_TRST        equ       5                   ; MTIM Counter Reset
MTIM1SC_TOIE        equ       6                   ; MTIM Overflow Interrupt Enable
MTIM1SC_TOF         equ       7                   ; MTIM Overflow Flag
; bit position masks
mMTIM1SC_TSTP       equ       %00010000
mMTIM1SC_TRST       equ       %00100000
mMTIM1SC_TOIE       equ       %01000000
mMTIM1SC_TOF        equ       %10000000

;*** MTIM1CLK - MTIM Clock Configuration Register
MTIM1CLK            equ       $00000029           ;*** MTIM1CLK - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM1CLK_PS0        equ       0                   ; Clock source Prescaler Bit 0
MTIM1CLK_PS1        equ       1                   ; Clock source Prescaler Bit 1
MTIM1CLK_PS2        equ       2                   ; Clock source Prescaler Bit 2
MTIM1CLK_PS3        equ       3                   ; Clock source Prescaler Bit 3
MTIM1CLK_CLKS0      equ       4                   ; Clock source Select Bit 0
MTIM1CLK_CLKS1      equ       5                   ; Clock source Select Bit 1
; bit position masks
mMTIM1CLK_PS0       equ       %00000001
mMTIM1CLK_PS1       equ       %00000010
mMTIM1CLK_PS2       equ       %00000100
mMTIM1CLK_PS3       equ       %00001000
mMTIM1CLK_CLKS0     equ       %00010000
mMTIM1CLK_CLKS1     equ       %00100000

;*** MTIM1CNT - MTIM Counter Register
MTIM1CNT            equ       $0000002A           ;*** MTIM1CNT - MTIM Counter Register

;*** MTIM1MOD - MTIM Modulo Register
MTIM1MOD            equ       $0000002B           ;*** MTIM1MOD - MTIM Modulo Register

;*** MTIM2SC - MTIM Clock Configuration Register
MTIM2SC             equ       $0000002C           ;*** MTIM2SC - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM2SC_TSTP        equ       4                   ; MTIM Counter Stop
MTIM2SC_TRST        equ       5                   ; MTIM Counter Reset
MTIM2SC_TOIE        equ       6                   ; MTIM Overflow Interrupt Enable
MTIM2SC_TOF         equ       7                   ; MTIM Overflow Flag
; bit position masks
mMTIM2SC_TSTP       equ       %00010000
mMTIM2SC_TRST       equ       %00100000
mMTIM2SC_TOIE       equ       %01000000
mMTIM2SC_TOF        equ       %10000000

;*** MTIM2CLK - MTIM Clock Configuration Register
MTIM2CLK            equ       $0000002D           ;*** MTIM2CLK - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM2CLK_PS0        equ       0                   ; Clock source Prescaler Bit 0
MTIM2CLK_PS1        equ       1                   ; Clock source Prescaler Bit 1
MTIM2CLK_PS2        equ       2                   ; Clock source Prescaler Bit 2
MTIM2CLK_PS3        equ       3                   ; Clock source Prescaler Bit 3
MTIM2CLK_CLKS0      equ       4                   ; Clock source Select Bit 0
MTIM2CLK_CLKS1      equ       5                   ; Clock source Select Bit 1
; bit position masks
mMTIM2CLK_PS0       equ       %00000001
mMTIM2CLK_PS1       equ       %00000010
mMTIM2CLK_PS2       equ       %00000100
mMTIM2CLK_PS3       equ       %00001000
mMTIM2CLK_CLKS0     equ       %00010000
mMTIM2CLK_CLKS1     equ       %00100000

;*** MTIM2CNT - MTIM Counter Register
MTIM2CNT            equ       $0000002E           ;*** MTIM2CNT - MTIM Counter Register

;*** MTIM2MOD - MTIM Modulo Register
MTIM2MOD            equ       $0000002F           ;*** MTIM2MOD - MTIM Modulo Register

;*** SCIBD - SCI Baud Rate Register
SCIBD               equ       $00000030           ;*** SCIBD - SCI Baud Rate Register

;*** SCIBDH - SCI Baud Rate Register High
SCIBDH              equ       $00000030           ;*** SCIBDH - SCI Baud Rate Register High
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
SCIBDL              equ       $00000031           ;*** SCIBDL - SCI Baud Rate Register Low
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
SCIC1               equ       $00000032           ;*** SCIC1 - SCI Control Register 1
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
SCIC2               equ       $00000033           ;*** SCIC2 - SCI Control Register 2
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
SCIS1               equ       $00000034           ;*** SCIS1 - SCI Status Register 1
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
SCIS2               equ       $00000035           ;*** SCIS2 - SCI Status Register 2
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
SCIC3               equ       $00000036           ;*** SCIC3 - SCI Control Register 3
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
SCID                equ       $00000037           ;*** SCID - SCI Data Register
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

;*** IICA - IIC Address Register
IICA                equ       $00000038           ;*** IICA - IIC Address Register
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
IICF                equ       $00000039           ;*** IICF - IIC Frequency Divider Register
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
IICC1               equ       $0000003A           ;*** IICC1 - IIC Control Register 1
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
IICC                equ       $0000003A           ;*** IICC - IIC Control Register
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
IICS                equ       $0000003B           ;*** IICS - IIC Status Register
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
IICD                equ       $0000003C           ;*** IICD - IIC Data I/O Register
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
IICC2               equ       $0000003D           ;*** IICC2 - IIC Control Register 2
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

;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register
TPMC1SC             equ       $00000048           ;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register
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

;*** TPMC1V - TPM Timer Channel 1 Value Register
TPMC1V              equ       $00000049           ;*** TPMC1V - TPM Timer Channel 1 Value Register

;*** TPMC1VH - TPM Timer Channel 1 Value Register High
TPMC1VH             equ       $00000049           ;*** TPMC1VH - TPM Timer Channel 1 Value Register High

;*** TPMC1VL - TPM Timer Channel 1 Value Register Low
TPMC1VL             equ       $0000004A           ;*** TPMC1VL - TPM Timer Channel 1 Value Register Low

;*** KBISC - KBI Status and Control Register
KBISC               equ       $0000004C           ;*** KBISC - KBI Status and Control Register
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
KBIPE               equ       $0000004D           ;*** KBIPE - KBI Pin Enable Register
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
KBIES               equ       $0000004E           ;*** KBIES - KBI Edge Select Register
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

;*** IEA - Interrupt Exit Address Register
IEA                 equ       $00000200           ;*** IEA - Interrupt Exit Address Register

;*** IRA - Interrupt Return Address Register
IRA                 equ       $00000201           ;*** IRA - Interrupt Return Address Register

;*** IRAH - Interrupt Return Address Register High
IRAH                equ       $00000201           ;*** IRAH - Interrupt Return Address Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRAH_A8             equ       0                   ; Return address, bit 8
IRAH_A9             equ       1                   ; Return address, bit 9
IRAH_A10            equ       2                   ; Return address, bit 10
IRAH_A11            equ       3                   ; Return address, bit 11
IRAH_A12            equ       4                   ; Return address, bit 12
IRAH_A13            equ       5                   ; Return address, bit 13
IRAH_CF             equ       6                   ; Contains the CCR C flag value saved before servicing an interrupt
IRAH_ZF             equ       7                   ; Contains the CCR Z flag value saved before servicing an interrupt
; bit position masks
mIRAH_A8            equ       %00000001
mIRAH_A9            equ       %00000010
mIRAH_A10           equ       %00000100
mIRAH_A11           equ       %00001000
mIRAH_A12           equ       %00010000
mIRAH_A13           equ       %00100000
mIRAH_CF            equ       %01000000
mIRAH_ZF            equ       %10000000

;*** IRAL - Interrupt Return Address Register Low
IRAL                equ       $00000202           ;*** IRAL - Interrupt Return Address Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRAL_A0             equ       0                   ; Return address, bit 0
IRAL_A1             equ       1                   ; Return address, bit 1
IRAL_A2             equ       2                   ; Return address, bit 2
IRAL_A3             equ       3                   ; Return address, bit 3
IRAL_A4             equ       4                   ; Return address, bit 4
IRAL_A5             equ       5                   ; Return address, bit 5
IRAL_A6             equ       6                   ; Return address, bit 6
IRAL_A7             equ       7                   ; Return address, bit 7
; bit position masks
mIRAL_A0            equ       %00000001
mIRAL_A1            equ       %00000010
mIRAL_A2            equ       %00000100
mIRAL_A3            equ       %00001000
mIRAL_A4            equ       %00010000
mIRAL_A5            equ       %00100000
mIRAL_A6            equ       %01000000
mIRAL_A7            equ       %10000000

;*** FOPT - Flash Options Register
FOPT                equ       $00000208           ;*** FOPT - Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SECD           equ       0                   ; Security State Code
; bit position masks
mFOPT_SECD          equ       %00000001

;*** FLCR - Flash Control Register
FLCR                equ       $00000209           ;*** FLCR - Flash Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_MASS           equ       2                   ; Mass Erase Control Bit
FLCR_HVEN           equ       3                   ; High Voltage Enable
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_MASS          equ       %00000100
mFLCR_HVEN          equ       %00001000

;*** SRS - System Reset Status Register
SRS                 equ       $00000210           ;*** SRS - System Reset Status Register
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

;*** SOPT1 - System Options Register 1
SOPT1               equ       $00000211           ;*** SOPT1 - System Options Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_RSTPE         equ       0                   ; RESET Pin Enable
SOPT1_BKGDPE        equ       1                   ; Background Debug Mode Pin Enable
SOPT1_SCIS          equ       2                   ; SCI Pin Select
SOPT1_IICPS         equ       3                   ; IIC Pin Select
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT          equ       6                   ; COP Watchdog Timeout
SOPT1_COPE          equ       7                   ; COP Watchdog Enable
; bit position masks
mSOPT1_RSTPE        equ       %00000001
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_SCIS         equ       %00000100
mSOPT1_IICPS        equ       %00001000
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT         equ       %01000000
mSOPT1_COPE         equ       %10000000

;*** SOPT2 - System Options Register 2
SOPT2               equ       $00000212           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_TPMCH0PS      equ       0                   ; TPMCH0 Pin Select
SOPT2_TPMCH1PS      equ       1                   ; TPMCH1 Pin Select
SOPT2_ADCHTS        equ       2                   ; ADC Hardware Trigger Select
SOPT2_MTIM1EC       equ       3                   ; MTIM1 External Clock Source Select
; bit position masks
mSOPT2_TPMCH0PS     equ       %00000001
mSOPT2_TPMCH1PS     equ       %00000010
mSOPT2_ADCHTS       equ       %00000100
mSOPT2_MTIM1EC      equ       %00001000

;*** SDID - System Device Identification Register
SDID                equ       $00000216           ;*** SDID - System Device Identification Register

;*** SDIDH - System Device Identification Register High
SDIDH               equ       $00000216           ;*** SDIDH - System Device Identification Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8           equ       0                   ; Part Identification Number, bit 8
SDIDH_ID9           equ       1                   ; Part Identification Number, bit 9
SDIDH_ID10          equ       2                   ; Part Identification Number, bit 10
SDIDH_ID11          equ       3                   ; Part Identification Number, bit 11
SDIDH_REV0          equ       4                   ; The revision number that is hard coded into these bits reflects the current silicon revision level
SDIDH_REV1          equ       5                   ; The revision number that is hard coded into these bits reflects the current silicon revision level
SDIDH_REV2          equ       6                   ; The revision number that is hard coded into these bits reflects the current silicon revision level
SDIDH_REV3          equ       7                   ; The revision number that is hard coded into these bits reflects the current silicon revision level
; bit position masks
mSDIDH_ID8          equ       %00000001
mSDIDH_ID9          equ       %00000010
mSDIDH_ID10         equ       %00000100
mSDIDH_ID11         equ       %00001000
mSDIDH_REV0         equ       %00010000
mSDIDH_REV1         equ       %00100000
mSDIDH_REV2         equ       %01000000
mSDIDH_REV3         equ       %10000000

;*** SDIDL - System Device Identification Register Low
SDIDL               equ       $00000217           ;*** SDIDL - System Device Identification Register Low
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

;*** SRTISC - System Real-Time Interrupt Status and Control Register
SRTISC              equ       $00000218           ;*** SRTISC - System Real-Time Interrupt Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRTISC_RTIS0        equ       0                   ; Real-Time Interrupt Delay Selects, bit 0
SRTISC_RTIS1        equ       1                   ; Real-Time Interrupt Delay Selects, bit 1
SRTISC_RTIS2        equ       2                   ; Real-Time Interrupt Delay Selects, bit 2
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
SPMSC1              equ       $00000219           ;*** SPMSC1 - System Power Management Status and Control 1 Register
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

;*** PTAPE - Port A Internal Pulling Device Enable Register
PTAPE               equ       $00000220           ;*** PTAPE - Port A Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pulling Device Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pulling Device Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pulling Device Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pulling Device Enable for Port A Bit 3
PTAPE_PTAPE5        equ       5                   ; Internal Pulling Device Enable for Port A Bit 5
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE5       equ       %00100000

;*** PTAPUD - Port A Pullup/Pulldown Control Register
PTAPUD              equ       $00000221           ;*** PTAPUD - Port A Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUD_PTAPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port A Bit 0
; bit position masks
mPTAPUD_PTAPUD0     equ       %00000001
mPTAPUD_PTAPUD1     equ       %00000010
mPTAPUD_PTAPUD2     equ       %00000100
mPTAPUD_PTAPUD3     equ       %00001000
mPTAPUD_PTAPUD5     equ       %00100000

;*** PTASE - Port A Output Slew Rate Control Enable Register
PTASE               equ       $00000222           ;*** PTASE - Port A Output Slew Rate Control Enable Register
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
PTADS               equ       $00000223           ;*** PTADS - Port A Drive Strength Selection Register
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

;*** PTBPE - Port B Internal Pulling Device Enable Register
PTBPE               equ       $00000224           ;*** PTBPE - Port B Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Internal Pulling Device Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Internal Pulling Device Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Internal Pulling Device Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Internal Pulling Device Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Internal Pulling Device Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Internal Pulling Device Enable for Port B Bit 5
PTBPE_PTBPE6        equ       6                   ; Internal Pulling Device Enable for Port B Bit 6
PTBPE_PTBPE7        equ       7                   ; Internal Pulling Device Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000
mPTBPE_PTBPE6       equ       %01000000
mPTBPE_PTBPE7       equ       %10000000

;*** PTBPUD - Port B Pullup/Pulldown Control Register
PTBPUD              equ       $00000225           ;*** PTBPUD - Port B Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPUD_PTBPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD6      equ       6                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD7      equ       7                   ; Pullup/Pulldown Device Control for Port B Bit 0
; bit position masks
mPTBPUD_PTBPUD0     equ       %00000001
mPTBPUD_PTBPUD1     equ       %00000010
mPTBPUD_PTBPUD2     equ       %00000100
mPTBPUD_PTBPUD3     equ       %00001000
mPTBPUD_PTBPUD4     equ       %00010000
mPTBPUD_PTBPUD5     equ       %00100000
mPTBPUD_PTBPUD6     equ       %01000000
mPTBPUD_PTBPUD7     equ       %10000000

;*** PTBSE - Port B Output Slew Rate Control Enable Register
PTBSE               equ       $00000226           ;*** PTBSE - Port B Output Slew Rate Control Enable Register
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
PTBDS               equ       $00000227           ;*** PTBDS - Port B Drive Strength Selection Register
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

;*** PTCPE - Port C Internal Pulling Device Enable Register
PTCPE               equ       $00000228           ;*** PTCPE - Port C Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Internal Pulling Device Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Internal Pulling Device Enable for Port C Bit 1
PTCPE_PTCPE2        equ       2                   ; Internal Pulling Device Enable for Port C Bit 2
PTCPE_PTCPE3        equ       3                   ; Internal Pulling Device Enable for Port C Bit 3
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000

;*** PTCPUD - Port C Pullup/Pulldown Control Register
PTCPUD              equ       $00000229           ;*** PTCPUD - Port C Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPUD_PTCPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port C Bit 0
; bit position masks
mPTCPUD_PTCPUD0     equ       %00000001
mPTCPUD_PTCPUD1     equ       %00000010
mPTCPUD_PTCPUD2     equ       %00000100
mPTCPUD_PTCPUD3     equ       %00001000

;*** PTCSE - Port C Output Slew Rate Control Enable Register
PTCSE               equ       $0000022A           ;*** PTCSE - Port C Output Slew Rate Control Enable Register
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
PTCDS               equ       $0000022B           ;*** PTCDS - Port C Drive Strength Selection Register
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

;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $00000238           ;*** ICSC1 - ICS Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN      equ       0                   ; Internal Reference Stop Enable
ICSC1_IRCLKEN       equ       1                   ; Internal Reference Clock Enable
ICSC1_IREFS         equ       2                   ; Internal Reference Select
ICSC1_RDIV          equ       3                   ; Reference Divider
ICSC1_CLKS          equ       6                   ; Clock Source Select
; bit position masks
mICSC1_IREFSTEN     equ       %00000001
mICSC1_IRCLKEN      equ       %00000010
mICSC1_IREFS        equ       %00000100
mICSC1_RDIV         equ       %00111000
mICSC1_CLKS         equ       %11000000

;*** ICSC2 - ICS Control Register 2
ICSC2               equ       $00000239           ;*** ICSC2 - ICS Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_EREFSTEN      equ       0                   ; External Reference Stop Enable
ICSC2_ERCLKEN       equ       1                   ; External Reference Enable
ICSC2_EREFS         equ       2                   ; External Reference Select
ICSC2_LP            equ       3                   ; Low Power Select
ICSC2_HGO           equ       4                   ; High Gain Oscillator Select
ICSC2_RANGE         equ       5                   ; Frequency Range Select
ICSC2_BDIV          equ       6                   ; Bus Frequency Divider
; bit position masks
mICSC2_EREFSTEN     equ       %00000001
mICSC2_ERCLKEN      equ       %00000010
mICSC2_EREFS        equ       %00000100
mICSC2_LP           equ       %00001000
mICSC2_HGO          equ       %00010000
mICSC2_RANGE        equ       %00100000
mICSC2_BDIV         equ       %11000000

;*** ICSTRM - ICS Trim Register
ICSTRM              equ       $0000023A           ;*** ICSTRM - ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM         equ       0                   ; ICS Trim Setting
; bit position masks
mICSTRM_TRIM        equ       %11111111

;*** ICSSC - ICS Status and Control Register
ICSSC               equ       $0000023B           ;*** ICSSC - ICS Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM         equ       0                   ; ICS Fine Trim
ICSSC_OSCINIT       equ       1                   ; OSC Initialization
ICSSC_CLKST         equ       2                   ; Clock Mode Status
; bit position masks
mICSSC_FTRIM        equ       %00000001
mICSSC_OSCINIT      equ       %00000010
mICSSC_CLKST        equ       %00001100

;*** NVICSTRM - Non-volatile ICS Trim Register
NVICSTRM            equ       $00003FFA           ;*** NVICSTRM - Non-volatile ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVICSTRM_TRIM       equ       0                   ; ICS Trim Setting
; bit position masks
mNVICSTRM_TRIM      equ       %11111111

;*** NVFTRIM - Non-volatile ICS Fine Trim
NVFTRIM             equ       $00003FFB           ;*** NVFTRIM - Non-volatile ICS Fine Trim
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFTRIM_FTRIM       equ       0                   ; ICS Fine Trim
; bit position masks
mNVFTRIM_FTRIM      equ       %00000001

;*** NVOPT - Non-volatile Flash Options Register
NVOPT               equ       $00003FFC           ;*** NVOPT - Non-volatile Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SECD          equ       0                   ; Security State Code
; bit position masks
mNVOPT_SECD         equ       %00000001

;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
       #ifndef  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
       #endif

; EOF
