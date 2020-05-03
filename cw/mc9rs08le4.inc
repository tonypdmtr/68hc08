;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9RS08LE4_28, version 3.00.015 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9rs08le4.inc
;     Processor : MC9RS08LE4CWL
;     FileFormat: V2.32
;     DataSheet : MC9RS08LE4RM Rev. 1 9/2008
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
;      - 25.08.2008, V3.00.0:
;              - Renamed register PMCSC -> SPMSC1.
;              - Removed registers LCDRVC, LCDPEN3, LCDBPEN3.
;              - Removed bits LCDSUPPLY[BBYPASS,HREFSEL,CPSEL], ICSSC[IREFST].
;              -   REASON: Bug-fix (#6457 in Issue Manager).
;
;     File-Format-Revisions:
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
XRAM                equ       $00000050
XRAM_END            equ       $000000BF
RAM1                equ       $00000100
RAM1_END            equ       $0000017F
ROM                 equ       $00003000
ROM_END             equ       $00003FF9
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


;*** SRS - System Reset Status Register
SRS                 equ       $00000018           ;*** SRS - System Reset Status Register
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
SOPT                equ       $00000019           ;*** SOPT - System Options Register
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


;*** SIP1 - System Interrupt Pending Register 1
SIP1                equ       $0000001A           ;*** SIP1 - System Interrupt Pending Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIP1_RTI            equ       0                   ; Real-Time Interrupt Pending
SIP1_LCD            equ       1                   ; LCD Interrupt Pending
SIP1_KBI            equ       2                   ; KBI Interrupt Pending
SIP1_ADC            equ       3                   ; ADC Interrupt Pending
SIP1_SCIE           equ       4                   ; SCI Error Interrupt Pending
SIP1_SCIR           equ       5                   ; SCI Receive Interrupt Pending
SIP1_SCIT           equ       6                   ; SCI Transmit Interrupt Pending
SIP1_LVD            equ       7                   ; LVD Interrupt Pending
; bit position masks
mSIP1_RTI           equ       %00000001
mSIP1_LCD           equ       %00000010
mSIP1_KBI           equ       %00000100
mSIP1_ADC           equ       %00001000
mSIP1_SCIE          equ       %00010000
mSIP1_SCIR          equ       %00100000
mSIP1_SCIT          equ       %01000000
mSIP1_LVD           equ       %10000000


;*** SIP2 - System Interrupt Pending Register 2
SIP2                equ       $0000001B           ;*** SIP2 - System Interrupt Pending Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIP2_TPM1           equ       0                   ; TPM1 Interrupt Pending
SIP2_TPM1CH0        equ       1                   ; TPM1 Channel 0 Interrupt Pending
SIP2_TPM1CH1        equ       2                   ; TPM1 Channel 1 Interrupt Pending
SIP2_TPM2           equ       4                   ; TPM2 Interrupt Pending
SIP2_TPM2CH0        equ       5                   ; TPM2 Channel 0 Interrupt Pending
SIP2_TPM2CH1        equ       6                   ; TPM2 Channel 1 Interrupt Pending
; bit position masks
mSIP2_TPM1          equ       %00000001
mSIP2_TPM1CH0       equ       %00000010
mSIP2_TPM1CH1       equ       %00000100
mSIP2_TPM2          equ       %00010000
mSIP2_TPM2CH0       equ       %00100000
mSIP2_TPM2CH1       equ       %01000000


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
KBIES               equ       $0000001E           ;*** KBIES - KBI Edge Select Register
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


;*** LCDWF0 - LCD Waveform Register 0
LCDWF0              equ       $00000020           ;*** LCDWF0 - LCD Waveform Register 0
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
LCDWF1              equ       $00000021           ;*** LCDWF1 - LCD Waveform Register 1
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
LCDWF2              equ       $00000022           ;*** LCDWF2 - LCD Waveform Register 2
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
LCDWF3              equ       $00000023           ;*** LCDWF3 - LCD Waveform Register 3
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
LCDWF4              equ       $00000024           ;*** LCDWF4 - LCD Waveform Register 4
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
LCDWF5              equ       $00000025           ;*** LCDWF5 - LCD Waveform Register 5
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
LCDWF6              equ       $00000026           ;*** LCDWF6 - LCD Waveform Register 6
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
LCDWF7              equ       $00000027           ;*** LCDWF7 - LCD Waveform Register 7
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
LCDWF8              equ       $00000028           ;*** LCDWF8 - LCD Waveform Register 8
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
LCDWF9              equ       $00000029           ;*** LCDWF9 - LCD Waveform Register 9
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
LCDWF10             equ       $0000002A           ;*** LCDWF10 - LCD Waveform Register 10
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
LCDWF11             equ       $0000002B           ;*** LCDWF11 - LCD Waveform Register 11
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
LCDWF12             equ       $0000002C           ;*** LCDWF12 - LCD Waveform Register 12
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
LCDWF13             equ       $0000002D           ;*** LCDWF13 - LCD Waveform Register 13
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
LCDWF14             equ       $0000002E           ;*** LCDWF14 - LCD Waveform Register 14
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
LCDWF15             equ       $0000002F           ;*** LCDWF15 - LCD Waveform Register 15
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
LCDWF16             equ       $00000030           ;*** LCDWF16 - LCD Waveform Register 16
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
LCDWF17             equ       $00000031           ;*** LCDWF17 - LCD Waveform Register 17
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
LCDWF18             equ       $00000032           ;*** LCDWF18 - LCD Waveform Register 18
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
LCDWF19             equ       $00000033           ;*** LCDWF19 - LCD Waveform Register 19
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
LCDWF20             equ       $00000034           ;*** LCDWF20 - LCD Waveform Register 20
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
LCDWF21             equ       $00000035           ;*** LCDWF21 - LCD Waveform Register 21
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


;*** LCDC0 - LCD Control Register 0
LCDC0               equ       $00000040           ;*** LCDC0 - LCD Control Register 0
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
LCDC1               equ       $00000041           ;*** LCDC1 - LCD Control Register 1
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
LCDSUPPLY           equ       $00000042           ;*** LCDSUPPLY - LCD Voltage Supply Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDSUPPLY_VSUPPLY0  equ       0                   ; Voltage Supply Control Bit 0
LCDSUPPLY_VSUPPLY1  equ       1                   ; Voltage Supply Control Bit 1
LCDSUPPLY_LADJ0     equ       4                   ; LCD Module Load Adjust Bit 0
LCDSUPPLY_LADJ1     equ       5                   ; LCD Module Load Adjust Bit 1
; bit position masks
mLCDSUPPLY_VSUPPLY0 equ       %00000001
mLCDSUPPLY_VSUPPLY1 equ       %00000010
mLCDSUPPLY_LADJ0    equ       %00010000
mLCDSUPPLY_LADJ1    equ       %00100000


;*** LCDBCTL - LCD Blink Control Register
LCDBCTL             equ       $00000044           ;*** LCDBCTL - LCD Blink Control Register
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
LCDS                equ       $00000045           ;*** LCDS - LCD Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDS_LCDIF          equ       7                   ; LCD Interrupt Flag
; bit position masks
mLCDS_LCDIF         equ       %10000000


;*** PTAD - Port A Data Register
PTAD                equ       $00000046           ;*** PTAD - Port A Data Register
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
PTADD               equ       $00000047           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; PTADD
PTADD_PTADD1        equ       1                   ; PTADD
PTADD_PTADD2        equ       2                   ; PTADD
PTADD_PTADD3        equ       3                   ; PTADD
PTADD_PTADD4        equ       4                   ; PTADD
PTADD_PTADD5        equ       5                   ; PTADD
PTADD_PTADD6        equ       6                   ; PTADD
PTADD_PTADD7        equ       7                   ; PTADD
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
PTBD                equ       $00000048           ;*** PTBD - Port B Data Register
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
PTBDD               equ       $00000049           ;*** PTBDD - Port B Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD2        equ       2                   ; PTBDD
PTBDD_PTBDD3        equ       3                   ; PTBDD
PTBDD_PTBDD4        equ       4                   ; PTBDD
PTBDD_PTBDD5        equ       5                   ; PTBDD
PTBDD_PTBDD6        equ       6                   ; PTBDD
PTBDD_PTBDD7        equ       7                   ; PTBDD
; bit position masks
mPTBDD_PTBDD2       equ       %00000100
mPTBDD_PTBDD3       equ       %00001000
mPTBDD_PTBDD4       equ       %00010000
mPTBDD_PTBDD5       equ       %00100000
mPTBDD_PTBDD6       equ       %01000000
mPTBDD_PTBDD7       equ       %10000000


;*** PTCD - Port C Data Register
PTCD                equ       $0000004A           ;*** PTCD - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0          equ       0                   ; Port C Data Register Bit 0
PTCD_PTCD1          equ       1                   ; Port C Data Register Bit 1
; bit position masks
mPTCD_PTCD0         equ       %00000001
mPTCD_PTCD1         equ       %00000010


;*** PTCDD - Port C Data Direction Register
PTCDD               equ       $0000004B           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; PTCDD
PTCDD_PTCDD1        equ       1                   ; PTCDD
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010


;*** PTDD - Port D Data Register
PTDD                equ       $0000004C           ;*** PTDD - Port D Data Register
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
PTDDD               equ       $0000004D           ;*** PTDDD - Port D Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0        equ       0                   ; PTDDD
PTDDD_PTDDD1        equ       1                   ; PTDDD
PTDDD_PTDDD2        equ       2                   ; PTDDD
PTDDD_PTDDD3        equ       3                   ; PTDDD
PTDDD_PTDDD4        equ       4                   ; PTDDD
PTDDD_PTDDD5        equ       5                   ; PTDDD
PTDDD_PTDDD6        equ       6                   ; PTDDD
PTDDD_PTDDD7        equ       7                   ; PTDDD
; bit position masks
mPTDDD_PTDDD0       equ       %00000001
mPTDDD_PTDDD1       equ       %00000010
mPTDDD_PTDDD2       equ       %00000100
mPTDDD_PTDDD3       equ       %00001000
mPTDDD_PTDDD4       equ       %00010000
mPTDDD_PTDDD5       equ       %00100000
mPTDDD_PTDDD6       equ       %01000000
mPTDDD_PTDDD7       equ       %10000000


;*** PTAPE - Port A Internal Pulling Device Enable Register
PTAPE               equ       $00000200           ;*** PTAPE - Port A Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pulling Device Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pulling Device Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pulling Device Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pulling Device Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Internal Pulling Device Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Internal Pulling Device Enable for Port A Bit 5
PTAPE_PTAPE6        equ       6                   ; Internal Pulling Device Enable for Port A Bit 6
PTAPE_PTAPE7        equ       7                   ; Internal Pulling Device Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000
mPTAPE_PTAPE6       equ       %01000000
mPTAPE_PTAPE7       equ       %10000000


;*** PTAPUD - Port A Pullup/Pulldown Control Register
PTAPUD              equ       $00000201           ;*** PTAPUD - Port A Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUD_PTAPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD6      equ       6                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD7      equ       7                   ; Pullup/Pulldown Device Control for Port A Bit 0
; bit position masks
mPTAPUD_PTAPUD0     equ       %00000001
mPTAPUD_PTAPUD1     equ       %00000010
mPTAPUD_PTAPUD2     equ       %00000100
mPTAPUD_PTAPUD3     equ       %00001000
mPTAPUD_PTAPUD4     equ       %00010000
mPTAPUD_PTAPUD5     equ       %00100000
mPTAPUD_PTAPUD6     equ       %01000000
mPTAPUD_PTAPUD7     equ       %10000000


;*** PTADS - Port A Drive Strength Selection Register
PTADS               equ       $00000202           ;*** PTADS - Port A Drive Strength Selection Register
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


;*** PTASE - Port A Output Slew Rate Control Enable Register
PTASE               equ       $00000203           ;*** PTASE - Port A Output Slew Rate Control Enable Register
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


;*** PTBPE - Port B Internal Pulling Device Enable Register
PTBPE               equ       $00000204           ;*** PTBPE - Port B Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Internal Pulling Device Enable for Port B Bit 0
PTBPE_PTBPE2        equ       2                   ; Internal Pulling Device Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Internal Pulling Device Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Internal Pulling Device Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Internal Pulling Device Enable for Port B Bit 5
PTBPE_PTBPE6        equ       6                   ; Internal Pulling Device Enable for Port B Bit 6
PTBPE_PTBPE7        equ       7                   ; Internal Pulling Device Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000
mPTBPE_PTBPE6       equ       %01000000
mPTBPE_PTBPE7       equ       %10000000


;*** PTBPUD - Port B Pullup/Pulldown Control Register
PTBPUD              equ       $00000205           ;*** PTBPUD - Port B Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPUD_PTBPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD6      equ       6                   ; Pullup/Pulldown Device Control for Port B Bit 0
PTBPUD_PTBPUD7      equ       7                   ; Pullup/Pulldown Device Control for Port B Bit 0
; bit position masks
mPTBPUD_PTBPUD0     equ       %00000001
mPTBPUD_PTBPUD2     equ       %00000100
mPTBPUD_PTBPUD3     equ       %00001000
mPTBPUD_PTBPUD4     equ       %00010000
mPTBPUD_PTBPUD5     equ       %00100000
mPTBPUD_PTBPUD6     equ       %01000000
mPTBPUD_PTBPUD7     equ       %10000000


;*** PTBDS - Port B Drive Strength Selection Register
PTBDS               equ       $00000206           ;*** PTBDS - Port B Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS1        equ       1                   ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2        equ       2                   ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3        equ       3                   ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4        equ       4                   ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5        equ       5                   ; Output Drive Strength Selection for Port B Bit 5
PTBDS_PTBDS6        equ       6                   ; Output Drive Strength Selection for Port B Bit 6
PTBDS_PTBDS7        equ       7                   ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTBDS_PTBDS1       equ       %00000010
mPTBDS_PTBDS2       equ       %00000100
mPTBDS_PTBDS3       equ       %00001000
mPTBDS_PTBDS4       equ       %00010000
mPTBDS_PTBDS5       equ       %00100000
mPTBDS_PTBDS6       equ       %01000000
mPTBDS_PTBDS7       equ       %10000000


;*** PTBSE - Port B Output Slew Rate Control Enable Register
PTBSE               equ       $00000207           ;*** PTBSE - Port B Output Slew Rate Control Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE1        equ       1                   ; Output Slew Rate Enable for Port B Bit 1
PTBSE_PTBSE2        equ       2                   ; Output Slew Rate Enable for Port B Bit 2
PTBSE_PTBSE3        equ       3                   ; Output Slew Rate Enable for Port B Bit 3
PTBSE_PTBSE4        equ       4                   ; Output Slew Rate Enable for Port B Bit 4
PTBSE_PTBSE5        equ       5                   ; Output Slew Rate Enable for Port B Bit 5
PTBSE_PTBSE6        equ       6                   ; Output Slew Rate Enable for Port B Bit 6
PTBSE_PTBSE7        equ       7                   ; Output Slew Rate Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE1       equ       %00000010
mPTBSE_PTBSE2       equ       %00000100
mPTBSE_PTBSE3       equ       %00001000
mPTBSE_PTBSE4       equ       %00010000
mPTBSE_PTBSE5       equ       %00100000
mPTBSE_PTBSE6       equ       %01000000
mPTBSE_PTBSE7       equ       %10000000


;*** PTCPE - Port C Internal Pulling Device Enable Register
PTCPE               equ       $00000208           ;*** PTCPE - Port C Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Internal Pulling Device Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Internal Pulling Device Enable for Port C Bit 1
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010


;*** PTCPUD - Port C Pullup/Pulldown Control Register
PTCPUD              equ       $00000209           ;*** PTCPUD - Port C Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPUD_PTCPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port C Bit 0
PTCPUD_PTCPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port C Bit 0
; bit position masks
mPTCPUD_PTCPUD0     equ       %00000001
mPTCPUD_PTCPUD1     equ       %00000010


;*** PTCDS - Port C Drive Strength Selection Register
PTCDS               equ       $0000020A           ;*** PTCDS - Port C Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0        equ       0                   ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1        equ       1                   ; Output Drive Strength Selection for Port C Bit 1
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010


;*** PTCSE - Port C Output Slew Rate Control Enable Register
PTCSE               equ       $0000020B           ;*** PTCSE - Port C Output Slew Rate Control Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0        equ       0                   ; Output Slew Rate Enable for Port C Bit 0
PTCSE_PTCSE1        equ       1                   ; Output Slew Rate Enable for Port C Bit 1
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010


;*** PTDPE - Port D Internal Pulling Device Enable Register
PTDPE               equ       $0000020C           ;*** PTDPE - Port D Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0        equ       0                   ; Internal Pulling Device Enable for Port D Bit 0
PTDPE_PTDPE1        equ       1                   ; Internal Pulling Device Enable for Port D Bit 1
PTDPE_PTDPE2        equ       2                   ; Internal Pulling Device Enable for Port D Bit 2
PTDPE_PTDPE3        equ       3                   ; Internal Pulling Device Enable for Port D Bit 3
PTDPE_PTDPE4        equ       4                   ; Internal Pulling Device Enable for Port D Bit 4
PTDPE_PTDPE5        equ       5                   ; Internal Pulling Device Enable for Port D Bit 5
PTDPE_PTDPE6        equ       6                   ; Internal Pulling Device Enable for Port D Bit 6
PTDPE_PTDPE7        equ       7                   ; Internal Pulling Device Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0       equ       %00000001
mPTDPE_PTDPE1       equ       %00000010
mPTDPE_PTDPE2       equ       %00000100
mPTDPE_PTDPE3       equ       %00001000
mPTDPE_PTDPE4       equ       %00010000
mPTDPE_PTDPE5       equ       %00100000
mPTDPE_PTDPE6       equ       %01000000
mPTDPE_PTDPE7       equ       %10000000


;*** PTDPUD - Port D Pullup/Pulldown Control Register
PTDPUD              equ       $0000020D           ;*** PTDPUD - Port D Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPUD_PTDPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD3      equ       3                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD6      equ       6                   ; Pullup/Pulldown Device Control for Port D Bit 0
PTDPUD_PTDPUD7      equ       7                   ; Pullup/Pulldown Device Control for Port D Bit 0
; bit position masks
mPTDPUD_PTDPUD0     equ       %00000001
mPTDPUD_PTDPUD1     equ       %00000010
mPTDPUD_PTDPUD2     equ       %00000100
mPTDPUD_PTDPUD3     equ       %00001000
mPTDPUD_PTDPUD4     equ       %00010000
mPTDPUD_PTDPUD5     equ       %00100000
mPTDPUD_PTDPUD6     equ       %01000000
mPTDPUD_PTDPUD7     equ       %10000000


;*** PTDDS - Port D Drive Strength Selection Register
PTDDS               equ       $0000020E           ;*** PTDDS - Port D Drive Strength Selection Register
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


;*** PTDSE - Port D Output Slew Rate Control Enable Register
PTDSE               equ       $0000020F           ;*** PTDSE - Port D Output Slew Rate Control Enable Register
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


;*** SCIBD - SCI Baud Rate Register
SCIBD               equ       $00000210           ;*** SCIBD - SCI Baud Rate Register


;*** SCIBDH - SCI Baud Rate Register High
SCIBDH              equ       $00000210           ;*** SCIBDH - SCI Baud Rate Register High
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
SCIBDL              equ       $00000211           ;*** SCIBDL - SCI Baud Rate Register Low
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
SCIC1               equ       $00000212           ;*** SCIC1 - SCI Control Register 1
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
SCIC2               equ       $00000213           ;*** SCIC2 - SCI Control Register 2
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
SCIS1               equ       $00000214           ;*** SCIS1 - SCI Status Register 1
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
SCIS2               equ       $00000215           ;*** SCIS2 - SCI Status Register 2
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
SCIC3               equ       $00000216           ;*** SCIC3 - SCI Control Register 3
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
SCID                equ       $00000217           ;*** SCID - SCI Data Register
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


;*** SDID - System Device Identification Register
SDID                equ       $0000021A           ;*** SDID - System Device Identification Register


;*** SDIDH - System Device Identification Register High
SDIDH               equ       $0000021A           ;*** SDIDH - System Device Identification Register High
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
SDIDL               equ       $0000021B           ;*** SDIDL - System Device Identification Register Low
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
SRTISC              equ       $0000021C           ;*** SRTISC - System Real-Time Interrupt Status and Control Register
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


;*** SPMSC1 - System Power Management Status and Control Register
SPMSC1              equ       $0000021D           ;*** SPMSC1 - System Power Management Status and Control Register
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


;*** TPM1SC - TPM1 Status and Control Register
TPM1SC              equ       $00000220           ;*** TPM1SC - TPM1 Status and Control Register
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
TPM1CNT             equ       $00000221           ;*** TPM1CNT - TPM1 Timer Counter Register


;*** TPM1CNTH - TPM1 Timer Counter Register High
TPM1CNTH            equ       $00000221           ;*** TPM1CNTH - TPM1 Timer Counter Register High


;*** TPM1CNTL - TPM1 Timer Counter Register Low
TPM1CNTL            equ       $00000222           ;*** TPM1CNTL - TPM1 Timer Counter Register Low


;*** TPM1MOD - TPM1 Timer Counter Modulo Register
TPM1MOD             equ       $00000223           ;*** TPM1MOD - TPM1 Timer Counter Modulo Register


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High
TPM1MODH            equ       $00000223           ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low
TPM1MODL            equ       $00000224           ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $00000225           ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
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
TPM1C0V             equ       $00000226           ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $00000226           ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $00000227           ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $00000228           ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
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
TPM1C1V             equ       $00000229           ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $00000229           ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $0000022A           ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low


;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $0000022C           ;*** ICSC1 - ICS Control Register 1
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
ICSC2               equ       $0000022D           ;*** ICSC2 - ICS Control Register 2
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
ICSTRM              equ       $0000022E           ;*** ICSTRM - ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM         equ       0                   ; ICS Trim Setting
; bit position masks
mICSTRM_TRIM        equ       %11111111


;*** ICSSC - ICS Status and Control Register
ICSSC               equ       $0000022F           ;*** ICSSC - ICS Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM         equ       0                   ; ICS Fine Trim
ICSSC_OSCINIT       equ       1                   ; OSC Initialization
ICSSC_CLKST         equ       2                   ; Clock Mode Status
; bit position masks
mICSSC_FTRIM        equ       %00000001
mICSSC_OSCINIT      equ       %00000010
mICSSC_CLKST        equ       %00001100


;*** TPM2SC - TPM2 Status and Control Register
TPM2SC              equ       $00000230           ;*** TPM2SC - TPM2 Status and Control Register
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
TPM2CNT             equ       $00000231           ;*** TPM2CNT - TPM2 Timer Counter Register


;*** TPM2CNTH - TPM2 Timer Counter Register High
TPM2CNTH            equ       $00000231           ;*** TPM2CNTH - TPM2 Timer Counter Register High


;*** TPM2CNTL - TPM2 Timer Counter Register Low
TPM2CNTL            equ       $00000232           ;*** TPM2CNTL - TPM2 Timer Counter Register Low


;*** TPM2MOD - TPM2 Timer Counter Modulo Register
TPM2MOD             equ       $00000233           ;*** TPM2MOD - TPM2 Timer Counter Modulo Register


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High
TPM2MODH            equ       $00000233           ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low
TPM2MODL            equ       $00000234           ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $00000235           ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
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
TPM2C0V             equ       $00000236           ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $00000236           ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $00000237           ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
TPM2C1SC            equ       $00000238           ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
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
TPM2C1V             equ       $00000239           ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High
TPM2C1VH            equ       $00000239           ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low
TPM2C1VL            equ       $0000023A           ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low


;*** FOPT - Flash Options Register
FOPT                equ       $0000023C           ;*** FOPT - Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SECD           equ       0                   ; Security State Code
; bit position masks
mFOPT_SECD          equ       %00000001


;*** FLCR - Flash Control Register
FLCR                equ       $0000023D           ;*** FLCR - Flash Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_MASS           equ       2                   ; Mass Erase Control Bit
FLCR_HVEN           equ       3                   ; High Voltage Enable
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_MASS          equ       %00000100
mFLCR_HVEN          equ       %00001000


;*** LCDPEN0 - LCD Pin Enable Register 0
LCDPEN0             equ       $00000240           ;*** LCDPEN0 - LCD Pin Enable Register 0
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
LCDPEN1             equ       $00000241           ;*** LCDPEN1 - LCD Pin Enable Register 1
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
LCDPEN2             equ       $00000242           ;*** LCDPEN2 - LCD Pin Enable Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN2_PEN16       equ       0                   ; Enable LCD pin 16 for LCD operation
LCDPEN2_PEN17       equ       1                   ; Enable LCD pin 17 for LCD operation
LCDPEN2_PEN18       equ       2                   ; Enable LCD pin 18 for LCD operation
LCDPEN2_PEN19       equ       3                   ; Enable LCD pin 19 for LCD operation
LCDPEN2_PEN20       equ       4                   ; Enable LCD pin 20 for LCD operation
LCDPEN2_PEN21       equ       5                   ; Enable LCD pin 21 for LCD operation
; bit position masks
mLCDPEN2_PEN16      equ       %00000001
mLCDPEN2_PEN17      equ       %00000010
mLCDPEN2_PEN18      equ       %00000100
mLCDPEN2_PEN19      equ       %00001000
mLCDPEN2_PEN20      equ       %00010000
mLCDPEN2_PEN21      equ       %00100000


;*** LCDBPEN0 - LCD Backplane Enable Register 0
LCDBPEN0            equ       $00000248           ;*** LCDBPEN0 - LCD Backplane Enable Register 0
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
LCDBPEN1            equ       $00000249           ;*** LCDBPEN1 - LCD Backplane Enable Register 1
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
LCDBPEN2            equ       $0000024A           ;*** LCDBPEN2 - LCD Backplane Enable Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN2_BPEN16     equ       0                   ; Enable LCD pin 16 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN17     equ       1                   ; Enable LCD pin 17 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN18     equ       2                   ; Enable LCD pin 18 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN19     equ       3                   ; Enable LCD pin 19 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN20     equ       4                   ; Enable LCD pin 20 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN21     equ       5                   ; Enable LCD pin 21 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN2_BPEN16    equ       %00000001
mLCDBPEN2_BPEN17    equ       %00000010
mLCDBPEN2_BPEN18    equ       %00000100
mLCDBPEN2_BPEN19    equ       %00001000
mLCDBPEN2_BPEN20    equ       %00010000
mLCDBPEN2_BPEN21    equ       %00100000


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
; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------



; **** 25.8.2008 13:29:57

       #ifndef __GENERATE_APPLICATION__
       #endif


; **** 28.8.2008 9:56:31

PMCSC               equ       SPMSC1
PMCSC_BGBE          equ       SPMSC1_BGBE
PMCSC_LVDE          equ       SPMSC1_LVDE
PMCSC_LVDSE         equ       SPMSC1_LVDSE
PMCSC_LVDRE         equ       SPMSC1_LVDRE
PMCSC_LVDIE         equ       SPMSC1_LVDIE
PMCSC_LVDACK        equ       SPMSC1_LVDACK
PMCSC_LVDF          equ       SPMSC1_LVDF
mPMCSC_BGBE         equ       mSPMSC1_BGBE
mPMCSC_LVDE         equ       mSPMSC1_LVDE
mPMCSC_LVDSE        equ       mSPMSC1_LVDSE
mPMCSC_LVDRE        equ       mSPMSC1_LVDRE
mPMCSC_LVDIE        equ       mSPMSC1_LVDIE
mPMCSC_LVDACK       equ       mSPMSC1_LVDACK
mPMCSC_LVDF         equ       mSPMSC1_LVDF

; EOF
