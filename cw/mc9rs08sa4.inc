;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9RS08SA12_32_SDIP, version 3.00.016 (RegistersPrg V2.23)

; ###################################################################
;     Filename  : mc9rs08sa4.inc
;     Processor : MC9RS08SA4C_32
;     FileFormat: V2.23
;     DataSheet : MC9RS08SA12 Rev. 1, Draft G 6/2007
;     Compiler  : CodeWarrior compiler
;     Date/Time : 26.2.2008, 11:38
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     (c) Copyright UNIS, spol. s r.o. 1997-2008
;     UNIS, spol. s r.o.
;     Jundrovska 33
;     624 00 Brno
;     Czech Republic
;     http      : www.processorexpert.com
;     mail      : info@processorexpert.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;      - 19.07.2007, V2.18 :
;               - Improved number of blanked lines inside register structures
;      - 06.08.2007, V2.19 :
;               - CPUDB revisions generated ahead of the file-format revisions.
;      - 11.09.2007, V2.20 :
;               - Added comment about initialization of unbonded pins.
;      - 02.01.2008, V2.21 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 13.02.2008, V2.22 :
;               -  Changes have not affected this file (because they are related to another family)
;      - 20.02.2008, V2.23 :
;               -  Changes have not affected this file (because they are related to another family)
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
XRAM                equ       $00000030
XRAM_END            equ       $000000BF
ROM                 equ       $00003000
ROM_END             equ       $00003FF9
;
;

;*** PTAD - Port A Data Register
PTAD                equ       $00000010           ;*** PTAD - Port A Data Register
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

;*** PTBD - Port B Data Register
PTBD                equ       $00000011           ;*** PTBD - Port B Data Register
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

;*** PTCD - Port C Data Register
PTCD                equ       $00000012           ;*** PTCD - Port C Data Register
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

;*** PTDD - Port D Data Register
PTDD                equ       $00000013           ;*** PTDD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0          equ       0                   ; Port D Data Register Bit 0
PTDD_PTDD1          equ       1                   ; Port D Data Register Bit 1
PTDD_PTDD2          equ       2                   ; Port D Data Register Bit 2
PTDD_PTDD3          equ       3                   ; Port D Data Register Bit 3
PTDD_PTDD4          equ       4                   ; Port D Data Register Bit 4
PTDD_PTDD5          equ       5                   ; Port D Data Register Bit 5
; bit position masks
mPTDD_PTDD0         equ       %00000001
mPTDD_PTDD1         equ       %00000010
mPTDD_PTDD2         equ       %00000100
mPTDD_PTDD3         equ       %00001000
mPTDD_PTDD4         equ       %00010000
mPTDD_PTDD5         equ       %00100000

;*** KBISC - KBI Status and Control Register
KBISC               equ       $00000014           ;*** KBISC - KBI Status and Control Register
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

;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register
TPMC0SC             equ       $00000015           ;*** TPMC0SC - TPM Timer Channel 0 Status and Control Register
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
TPMC0V              equ       $00000016           ;*** TPMC0V - TPM Timer Channel 0 Value Register

;*** TPMC0VH - TPM Timer Channel 0 Value Register High
TPMC0VH             equ       $00000016           ;*** TPMC0VH - TPM Timer Channel 0 Value Register High

;*** TPMC0VL - TPM Timer Channel 0 Value Register Low
TPMC0VL             equ       $00000017           ;*** TPMC0VL - TPM Timer Channel 0 Value Register Low

;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register
TPMC1SC             equ       $00000018           ;*** TPMC1SC - TPM Timer Channel 1 Status and Control Register
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
TPMC1V              equ       $00000019           ;*** TPMC1V - TPM Timer Channel 1 Value Register

;*** TPMC1VH - TPM Timer Channel 1 Value Register High
TPMC1VH             equ       $00000019           ;*** TPMC1VH - TPM Timer Channel 1 Value Register High

;*** TPMC1VL - TPM Timer Channel 1 Value Register Low
TPMC1VL             equ       $0000001A           ;*** TPMC1VL - TPM Timer Channel 1 Value Register Low

;*** ACMPSC - ACMP Status and Control Register
ACMPSC              equ       $0000001B           ;*** ACMPSC - ACMP Status and Control Register
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
ADCSC1              equ       $0000001C           ;*** ADCSC1 - Status and Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1_ADCH0        equ       0                   ; Input Channel Select Bit 0
ADCSC1_ADCH1        equ       1                   ; Input Channel Select Bit 1
ADCSC1_ADCH2        equ       2                   ; Input Channel Select Bit 2
ADCSC1_ADCH3        equ       3                   ; Input Channel Select Bit 3
ADCSC1_ADCO         equ       5                   ; Continuous Conversion Enable - ADCO is used to enable continuous conversions
ADCSC1_AIEN         equ       6                   ; Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while
ADCSC1_COCO         equ       7                   ; Conversion Complete Flag - The COCO flag is a read-only bit which is set each time
; bit position masks
mADCSC1_ADCH0       equ       %00000001
mADCSC1_ADCH1       equ       %00000010
mADCSC1_ADCH2       equ       %00000100
mADCSC1_ADCH3       equ       %00001000
mADCSC1_ADCO        equ       %00100000
mADCSC1_AIEN        equ       %01000000
mADCSC1_COCO        equ       %10000000

;*** ADCSC2 - Status and Control Register 2
ADCSC2              equ       $0000001D           ;*** ADCSC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC2_ACFGT        equ       4                   ; Compare Function Greater Than Enable-ACFGT is used to configure the compare function to trigger when the
ADCSC2_ACFE         equ       5                   ; Compare Function Enable - ACFE is used to enable the compare function
ADCSC2_ADTRG        equ       6                   ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADCSC2_ADACT        equ       7                   ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a
; bit position masks
mADCSC2_ACFGT       equ       %00010000
mADCSC2_ACFE        equ       %00100000
mADCSC2_ADTRG       equ       %01000000
mADCSC2_ADACT       equ       %10000000

;*** ADCR - Data Result Low Register
ADCR                equ       $0000001E           ;*** ADCR - Data Result Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCR_ADR0           equ       0                   ; ADC Result Data Bit 0
ADCR_ADR1           equ       1                   ; ADC Result Data Bit 1
ADCR_ADR2           equ       2                   ; ADC Result Data Bit 2
ADCR_ADR3           equ       3                   ; ADC Result Data Bit 3
ADCR_ADR4           equ       4                   ; ADC Result Data Bit 4
ADCR_ADR5           equ       5                   ; ADC Result Data Bit 5
ADCR_ADR6           equ       6                   ; ADC Result Data Bit 6
ADCR_ADR7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCR_ADR0          equ       %00000001
mADCR_ADR1          equ       %00000010
mADCR_ADR2          equ       %00000100
mADCR_ADR3          equ       %00001000
mADCR_ADR4          equ       %00010000
mADCR_ADR5          equ       %00100000
mADCR_ADR6          equ       %01000000
mADCR_ADR7          equ       %10000000

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

;*** MTIM1SC - MTIM Clock Configuration Register
MTIM1SC             equ       $00000020           ;*** MTIM1SC - MTIM Clock Configuration Register
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
MTIM1CLK            equ       $00000021           ;*** MTIM1CLK - MTIM Clock Configuration Register
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
MTIM1CNT            equ       $00000022           ;*** MTIM1CNT - MTIM Counter Register

;*** MTIM1MOD - MTIM Modulo Register
MTIM1MOD            equ       $00000023           ;*** MTIM1MOD - MTIM Modulo Register

;*** MTIM2SC - MTIM Clock Configuration Register
MTIM2SC             equ       $00000024           ;*** MTIM2SC - MTIM Clock Configuration Register
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
MTIM2CLK            equ       $00000025           ;*** MTIM2CLK - MTIM Clock Configuration Register
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
MTIM2CNT            equ       $00000026           ;*** MTIM2CNT - MTIM Counter Register

;*** MTIM2MOD - MTIM Modulo Register
MTIM2MOD            equ       $00000027           ;*** MTIM2MOD - MTIM Modulo Register

;*** SCIBD - SCI Baud Rate Register
SCIBD               equ       $00000028           ;*** SCIBD - SCI Baud Rate Register

;*** SCIBDH - SCI Baud Rate Register High
SCIBDH              equ       $00000028           ;*** SCIBDH - SCI Baud Rate Register High
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
SCIBDL              equ       $00000029           ;*** SCIBDL - SCI Baud Rate Register Low
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
SCIC1               equ       $0000002A           ;*** SCIC1 - SCI Control Register 1
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
SCIC2               equ       $0000002B           ;*** SCIC2 - SCI Control Register 2
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
SCIS1               equ       $0000002C           ;*** SCIS1 - SCI Status Register 1
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
SCIS2               equ       $0000002D           ;*** SCIS2 - SCI Status Register 2
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
SCIC3               equ       $0000002E           ;*** SCIC3 - SCI Control Register 3
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
SCID                equ       $0000002F           ;*** SCID - SCI Data Register
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

;*** SRS - System Reset Status Register
SRS                 equ       $00000200           ;*** SRS - System Reset Status Register
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

;*** SOPT - System Options Register
SOPT                equ       $00000201           ;*** SOPT - System Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT_RSTPE          equ       0                   ; RESET Pin Enable
SOPT_BKGDPE         equ       1                   ; Background Debug Mode Pin Enable
SOPT_STOPE          equ       5                   ; Stop Mode Enable
SOPT_COPT           equ       6                   ; COP Watchdog Timeout
SOPT_COPE           equ       7                   ; COP Watchdog Enable
; bit position masks
mSOPT_RSTPE         equ       %00000001
mSOPT_BKGDPE        equ       %00000010
mSOPT_STOPE         equ       %00100000
mSOPT_COPT          equ       %01000000
mSOPT_COPE          equ       %10000000

;*** SIP1 - System Interrupt Pending Register
SIP1                equ       $00000202           ;*** SIP1 - System Interrupt Pending Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIP1_RTI            equ       0                   ; Real-Time Interrupt Pending
SIP1_MTIM1          equ       1                   ; Modulo Timer 1 Interrupt Pending
SIP1_MTIM2          equ       2                   ; Modulo Timer 2 Interrupt Pending
SIP1_TPM            equ       3                   ; Timer/PWM Interrupt Pending
SIP1_ADC            equ       4                   ; ADC Interrupt Pending
SIP1_ACMP           equ       5                   ; Analog Comparator Interrupt Pending
SIP1_KBI            equ       6                   ; Keyboard Interrupt Pending
SIP1_SCI            equ       7                   ; SCI Interrupt Pending
; bit position masks
mSIP1_RTI           equ       %00000001
mSIP1_MTIM1         equ       %00000010
mSIP1_MTIM2         equ       %00000100
mSIP1_TPM           equ       %00001000
mSIP1_ADC           equ       %00010000
mSIP1_ACMP          equ       %00100000
mSIP1_KBI           equ       %01000000
mSIP1_SCI           equ       %10000000

;*** SDID - System Device Identification Register
SDID                equ       $00000206           ;*** SDID - System Device Identification Register

;*** SDIDH - System Device Identification Register High
SDIDH               equ       $00000206           ;*** SDIDH - System Device Identification Register High
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
SDIDL               equ       $00000207           ;*** SDIDL - System Device Identification Register Low
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
SRTISC              equ       $00000208           ;*** SRTISC - System Real-Time Interrupt Status and Control Register
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
SPMSC1              equ       $00000209           ;*** SPMSC1 - System Power Management Status and Control 1 Register
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

;*** FOPT - Flash Options Register
FOPT                equ       $00000210           ;*** FOPT - Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SECD           equ       0                   ; Security State Code
; bit position masks
mFOPT_SECD          equ       %00000001

;*** FLCR - Flash Control Register
FLCR                equ       $00000211           ;*** FLCR - Flash Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_MASS           equ       2                   ; Mass Erase Control Bit
FLCR_HVEN           equ       3                   ; High Voltage Enable
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_MASS          equ       %00000100
mFLCR_HVEN          equ       %00001000

;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000220           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; PTADD
PTADD_PTADD1        equ       1                   ; PTADD
PTADD_PTADD2        equ       2                   ; PTADD
PTADD_PTADD3        equ       3                   ; PTADD
PTADD_PTADD6        equ       6                   ; PTADD
PTADD_PTADD7        equ       7                   ; PTADD
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000
mPTADD_PTADD6       equ       %01000000
mPTADD_PTADD7       equ       %10000000

;*** PTAPE - Port A Internal Pulling Device Enable Register
PTAPE               equ       $00000221           ;*** PTAPE - Port A Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pulling Device Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pulling Device Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pulling Device Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pulling Device Enable for Port A Bit 3
PTAPE_PTAPE5        equ       5                   ; Internal Pulling Device Enable for Port A Bit 5
PTAPE_PTAPE6        equ       6                   ; Internal Pulling Device Enable for Port A Bit 6
PTAPE_PTAPE7        equ       7                   ; Internal Pulling Device Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE5       equ       %00100000
mPTAPE_PTAPE6       equ       %01000000
mPTAPE_PTAPE7       equ       %10000000

;*** PTAPUD - Port A Pullup/Pulldown Control Register
PTAPUD              equ       $00000222           ;*** PTAPUD - Port A Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUD_PTAPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD6      equ       6                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD7      equ       7                   ; Pullup/Pulldown Device Control for Port A Bit 0
; bit position masks
mPTAPUD_PTAPUD0     equ       %00000001
mPTAPUD_PTAPUD1     equ       %00000010
mPTAPUD_PTAPUD2     equ       %00000100
mPTAPUD_PTAPUD3     equ       %00001000
mPTAPUD_PTAPUD5     equ       %00100000
mPTAPUD_PTAPUD6     equ       %01000000
mPTAPUD_PTAPUD7     equ       %10000000

;*** PTASE - Port A Output Slew Rate Control Enable Register
PTASE               equ       $00000223           ;*** PTASE - Port A Output Slew Rate Control Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2        equ       2                   ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3        equ       3                   ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE6        equ       6                   ; Output Slew Rate Enable for Port A Bit 6
PTASE_PTASE7        equ       7                   ; Output Slew Rate Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE2       equ       %00000100
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000
mPTASE_PTASE6       equ       %01000000
mPTASE_PTASE7       equ       %10000000

;*** PTBDD - Port B Data Direction Register
PTBDD               equ       $00000224           ;*** PTBDD - Port B Data Direction Register
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

;*** PTBPE - Port B Internal Pulling Device Enable Register
PTBPE               equ       $00000225           ;*** PTBPE - Port B Internal Pulling Device Enable Register
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
PTBPUD              equ       $00000226           ;*** PTBPUD - Port B Pullup/Pulldown Control Register
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
PTBSE               equ       $00000227           ;*** PTBSE - Port B Output Slew Rate Control Enable Register
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

;*** PTCDD - Port C Data Direction Register
PTCDD               equ       $00000228           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; PTCDD
PTCDD_PTCDD1        equ       1                   ; PTCDD
PTCDD_PTCDD2        equ       2                   ; PTCDD
PTCDD_PTCDD3        equ       3                   ; PTCDD
PTCDD_PTCDD4        equ       4                   ; PTCDD
PTCDD_PTCDD5        equ       5                   ; PTCDD
PTCDD_PTCDD6        equ       6                   ; PTCDD
PTCDD_PTCDD7        equ       7                   ; PTCDD
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000
mPTCDD_PTCDD4       equ       %00010000
mPTCDD_PTCDD5       equ       %00100000
mPTCDD_PTCDD6       equ       %01000000
mPTCDD_PTCDD7       equ       %10000000

;*** PTCPE - Port C Internal Pulling Device Enable Register
PTCPE               equ       $00000229           ;*** PTCPE - Port C Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Internal Pulling Device Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Internal Pulling Device Enable for Port C Bit 1
PTCPE_PTCPE2        equ       2                   ; Internal Pulling Device Enable for Port C Bit 2
PTCPE_PTCPE3        equ       3                   ; Internal Pulling Device Enable for Port C Bit 3
PTCPE_PTCPE4        equ       4                   ; Internal Pulling Device Enable for Port C Bit 4
PTCPE_PTCPE5        equ       5                   ; Internal Pulling Device Enable for Port C Bit 5
PTCPE_PTCPE6        equ       6                   ; Internal Pulling Device Enable for Port C Bit 6
PTCPE_PTCPE7        equ       7                   ; Internal Pulling Device Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000
mPTCPE_PTCPE6       equ       %01000000
mPTCPE_PTCPE7       equ       %10000000

;*** PTCPUD - Port C Pullup/Pulldown Control Register
PTCPUD              equ       $0000022A           ;*** PTCPUD - Port C Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPUD_PTCPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD6      equ       6                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD7      equ       7                   ; Pullup/Pulldown Device Control for Port C Bit 0
; bit position masks
mPTCPUD_PTCPUD0     equ       %00000001
mPTCPUD_PTCPUD1     equ       %00000010
mPTCPUD_PTCPUD2     equ       %00000100
mPTCPUD_PTCPUD3     equ       %00001000
mPTCPUD_PTCPUD4     equ       %00010000
mPTCPUD_PTCPUD5     equ       %00100000
mPTCPUD_PTCPUD6     equ       %01000000
mPTCPUD_PTCPUD7     equ       %10000000

;*** PTCSE - Port C Output Slew Rate Control Enable Register
PTCSE               equ       $0000022B           ;*** PTCSE - Port C Output Slew Rate Control Enable Register
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

;*** PTDDD - Port D Data Direction Register
PTDDD               equ       $0000022C           ;*** PTDDD - Port D Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0        equ       0                   ; PTDDD
PTDDD_PTDDD1        equ       1                   ; PTDDD
PTDDD_PTDDD2        equ       2                   ; PTDDD
PTDDD_PTDDD3        equ       3                   ; PTDDD
PTDDD_PTDDD4        equ       4                   ; PTDDD
PTDDD_PTDDD5        equ       5                   ; PTDDD
; bit position masks
mPTDDD_PTDDD0       equ       %00000001
mPTDDD_PTDDD1       equ       %00000010
mPTDDD_PTDDD2       equ       %00000100
mPTDDD_PTDDD3       equ       %00001000
mPTDDD_PTDDD4       equ       %00010000
mPTDDD_PTDDD5       equ       %00100000

;*** PTDPE - Port D Internal Pulling Device Enable Register
PTDPE               equ       $0000022D           ;*** PTDPE - Port D Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0        equ       0                   ; Internal Pulling Device Enable for Port D Bit 0
PTDPE_PTDPE1        equ       1                   ; Internal Pulling Device Enable for Port D Bit 1
PTDPE_PTDPE2        equ       2                   ; Internal Pulling Device Enable for Port D Bit 2
PTDPE_PTDPE3        equ       3                   ; Internal Pulling Device Enable for Port D Bit 3
PTDPE_PTDPE4        equ       4                   ; Internal Pulling Device Enable for Port D Bit 4
PTDPE_PTDPE5        equ       5                   ; Internal Pulling Device Enable for Port D Bit 5
; bit position masks
mPTDPE_PTDPE0       equ       %00000001
mPTDPE_PTDPE1       equ       %00000010
mPTDPE_PTDPE2       equ       %00000100
mPTDPE_PTDPE3       equ       %00001000
mPTDPE_PTDPE4       equ       %00010000
mPTDPE_PTDPE5       equ       %00100000

;*** PTDPUD - Port D Pullup/Pulldown Control Register
PTDPUD              equ       $0000022E           ;*** PTDPUD - Port D Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPUD_PTDPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port D Bit 0
; bit position masks
mPTDPUD_PTDPUD0     equ       %00000001
mPTDPUD_PTDPUD1     equ       %00000010
mPTDPUD_PTDPUD2     equ       %00000100
mPTDPUD_PTDPUD3     equ       %00001000
mPTDPUD_PTDPUD4     equ       %00010000
mPTDPUD_PTDPUD5     equ       %00100000

;*** PTDSE - Port D Output Slew Rate Control Enable Register
PTDSE               equ       $0000022F           ;*** PTDSE - Port D Output Slew Rate Control Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0        equ       0                   ; Output Slew Rate Enable for Port D Bit 0
PTDSE_PTDSE1        equ       1                   ; Output Slew Rate Enable for Port D Bit 1
PTDSE_PTDSE2        equ       2                   ; Output Slew Rate Enable for Port D Bit 2
PTDSE_PTDSE3        equ       3                   ; Output Slew Rate Enable for Port D Bit 3
PTDSE_PTDSE4        equ       4                   ; Output Slew Rate Enable for Port D Bit 4
PTDSE_PTDSE5        equ       5                   ; Output Slew Rate Enable for Port D Bit 5
; bit position masks
mPTDSE_PTDSE0       equ       %00000001
mPTDSE_PTDSE1       equ       %00000010
mPTDSE_PTDSE2       equ       %00000100
mPTDSE_PTDSE3       equ       %00001000
mPTDSE_PTDSE4       equ       %00010000
mPTDSE_PTDSE5       equ       %00100000

;*** TPMSC - TPM Status and Control Register
TPMSC               equ       $00000230           ;*** TPMSC - TPM Status and Control Register
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
TPMCNT              equ       $00000231           ;*** TPMCNT - TPM Timer Counter Register

;*** TPMCNTH - TPM Timer Counter Register High
TPMCNTH             equ       $00000231           ;*** TPMCNTH - TPM Timer Counter Register High

;*** TPMCNTL - TPM Timer Counter Register Low
TPMCNTL             equ       $00000232           ;*** TPMCNTL - TPM Timer Counter Register Low

;*** TPMMOD - TPM Timer Counter Modulo Register
TPMMOD              equ       $00000233           ;*** TPMMOD - TPM Timer Counter Modulo Register

;*** TPMMODH - TPM Timer Counter Modulo Register High
TPMMODH             equ       $00000233           ;*** TPMMODH - TPM Timer Counter Modulo Register High

;*** TPMMODL - TPM Timer Counter Modulo Register Low
TPMMODL             equ       $00000234           ;*** TPMMODL - TPM Timer Counter Modulo Register Low

;*** KBIPE - KBI Pin Enable Register
KBIPE               equ       $00000235           ;*** KBIPE - KBI Pin Enable Register
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
KBIES               equ       $00000236           ;*** KBIES - KBI Edge Select Register
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

;*** ADCCV - Compare Value Low Register
ADCCV               equ       $00000237           ;*** ADCCV - Compare Value Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV_ADCV0         equ       0                   ; Compare Function Value 0
ADCCV_ADCV1         equ       1                   ; Compare Function Value 1
ADCCV_ADCV2         equ       2                   ; Compare Function Value 2
ADCCV_ADCV3         equ       3                   ; Compare Function Value 3
ADCCV_ADCV4         equ       4                   ; Compare Function Value 4
ADCCV_ADCV5         equ       5                   ; Compare Function Value 5
ADCCV_ADCV6         equ       6                   ; Compare Function Value 6
ADCCV_ADCV7         equ       7                   ; Compare Function Value 7
; bit position masks
mADCCV_ADCV0        equ       %00000001
mADCCV_ADCV1        equ       %00000010
mADCCV_ADCV2        equ       %00000100
mADCCV_ADCV3        equ       %00001000
mADCCV_ADCV4        equ       %00010000
mADCCV_ADCV5        equ       %00100000
mADCCV_ADCV6        equ       %01000000
mADCCV_ADCV7        equ       %10000000

;*** ADCCFG - Configuration Register
ADCCFG              equ       $00000238           ;*** ADCCFG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG_ADICLK0      equ       0                   ; Input Clock Select Bit 0
ADCCFG_ADICLK1      equ       1                   ; Input Clock Select Bit 1
ADCCFG_ADLSMP       equ       4                   ; Long Sample Time Configuration
ADCCFG_ADIV0        equ       5                   ; Clock Divide Select Bit 0
ADCCFG_ADIV1        equ       6                   ; Clock Divide Select Bit 1
; bit position masks
mADCCFG_ADICLK0     equ       %00000001
mADCCFG_ADICLK1     equ       %00000010
mADCCFG_ADLSMP      equ       %00010000
mADCCFG_ADIV0       equ       %00100000
mADCCFG_ADIV1       equ       %01000000

;*** APCTL1 - Pin Control 1 Register
APCTL1              equ       $00000239           ;*** APCTL1 - Pin Control 1 Register
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
APCTL2              equ       $0000023A           ;*** APCTL2 - Pin Control 2 Register
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

;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $0000023C           ;*** ICSC1 - ICS Control Register 1
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
ICSC2               equ       $0000023D           ;*** ICSC2 - ICS Control Register 2
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
ICSTRM              equ       $0000023E           ;*** ICSTRM - ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM         equ       0                   ; ICS Trim Setting
; bit position masks
mICSTRM_TRIM        equ       %11111111

;*** ICSSC - ICS Status and Control Register
ICSSC               equ       $0000023F           ;*** ICSSC - ICS Status and Control Register
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
