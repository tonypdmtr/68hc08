;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MPXY8600, version 3.00.000 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mpxy8600.inc
;     Processor : MPXY8600
;     FileFormat: V2.32
;     DataSheet : MELBOURNE TIRE PRESSURE MONITOR SENSOR PRODUCT SPECIFICATION REV 1.00
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 13:45
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
ROM_END             equ       $0000DFBF
RAM                 equ       $00000090
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000028F
;
Vkbi                equ       $0000DFE0
VReserved14         equ       $0000DFE2
VReserved13         equ       $0000DFE4
Vrti                equ       $0000DFE6
Vlfrcvr             equ       $0000DFE8
VReserved10         equ       $0000DFEA
Vrfm                equ       $0000DFEC
Vsmi                equ       $0000DFEE
Vtpm1ovf            equ       $0000DFF0
Vtpm1ch1            equ       $0000DFF2
Vtpm1ch0            equ       $0000DFF4
Vwuktmr             equ       $0000DFF6
Vlvd                equ       $0000DFF8
VReserved2          equ       $0000DFFA
Vswi                equ       $0000DFFC
Vreset              equ       $0000DFFE
;

;*** PTAD - Port A Data Register
PTAD                equ       $00000000           ;*** PTAD - Port A Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAD_PTAD0          equ       0                   ; Port A Data Register Bit 0
PTAD_PTAD1          equ       1                   ; Port A Data Register Bit 1
PTAD_PTAD2          equ       2                   ; Port A Data Register Bit 2
PTAD_PTAD3          equ       3                   ; Port A Data Register Bit 3
PTAD_PTAD4          equ       4                   ; Port A Data Register Bit 4
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD1         equ       %00000010
mPTAD_PTAD2         equ       %00000100
mPTAD_PTAD3         equ       %00001000
mPTAD_PTAD4         equ       %00010000

;*** PTAPE - Port A Pull Enable Register
PTAPE               equ       $00000001           ;*** PTAPE - Port A Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pull Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pull Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pull Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pull Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Internal Pull Enable for Port A Bit 4
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000

;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000003           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; Data Direction for Port A Bit 0
PTADD_PTADD1        equ       1                   ; Data Direction for Port A Bit 1
PTADD_PTADD2        equ       2                   ; Data Direction for Port A Bit 2
PTADD_PTADD3        equ       3                   ; Data Direction for Port A Bit 3
PTADD_PTADD4        equ       4                   ; Data Direction for Port A Bit 4
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000
mPTADD_PTADD4       equ       %00010000

;*** PTBD - Port B Data Register
PTBD                equ       $00000004           ;*** PTBD - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBD_PTBD0          equ       0                   ; Port B Data Register Bit 0
PTBD_PTBD1          equ       1                   ; Port B Data Register Bit 1
; bit position masks
mPTBD_PTBD0         equ       %00000001
mPTBD_PTBD1         equ       %00000010

;*** PTBPE - Port B Pull Enable Register
PTBPE               equ       $00000005           ;*** PTBPE - Port B Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Internal Pull Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Internal Pull Enable for Port B Bit 1
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010

;*** PTBDD - Port B Data Direction Register
PTBDD               equ       $00000007           ;*** PTBDD - Port B Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0        equ       0                   ; Data Direction for Port B Bit 0
PTBDD_PTBDD1        equ       1                   ; Data Direction for Port B Bit 1
; bit position masks
mPTBDD_PTBDD0       equ       %00000001
mPTBDD_PTBDD1       equ       %00000010

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
; bit position masks
mKBIPE_KBIPE0       equ       %00000001
mKBIPE_KBIPE1       equ       %00000010
mKBIPE_KBIPE2       equ       %00000100
mKBIPE_KBIPE3       equ       %00001000

;*** KBIES - KBI Edge Select Register
KBIES               equ       $0000000E           ;*** KBIES - KBI Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIES_KBEDG0        equ       0                   ; Keyboard Edge Select Bit 0
KBIES_KBEDG1        equ       1                   ; Keyboard Edge Select Bit 1
KBIES_KBEDG2        equ       2                   ; Keyboard Edge Select Bit 2
KBIES_KBEDG3        equ       3                   ; Keyboard Edge Select Bit 3
; bit position masks
mKBIES_KBEDG0       equ       %00000001
mKBIES_KBEDG1       equ       %00000010
mKBIES_KBEDG2       equ       %00000100
mKBIES_KBEDG3       equ       %00001000

;*** TPM1SC - TPM1 Status and Control Register
TPM1SC              equ       $00000010           ;*** TPM1SC - TPM1 Status and Control Register
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
TPM1CNT             equ       $00000011           ;*** TPM1CNT - TPM1 Timer Counter Register

;*** TPM1CNTH - TPM1 Timer Counter Register High
TPM1CNTH            equ       $00000011           ;*** TPM1CNTH - TPM1 Timer Counter Register High

;*** TPM1CNTL - TPM1 Timer Counter Register Low
TPM1CNTL            equ       $00000012           ;*** TPM1CNTL - TPM1 Timer Counter Register Low

;*** TPM1MOD - TPM1 Timer Counter Modulo Register
TPM1MOD             equ       $00000013           ;*** TPM1MOD - TPM1 Timer Counter Modulo Register

;*** TPM1MODH - TPM1 Timer Counter Modulo Register High
TPM1MODH            equ       $00000013           ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High

;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low
TPM1MODL            equ       $00000014           ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low

;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $00000015           ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
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
TPM1C0V             equ       $00000016           ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register

;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $00000016           ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High

;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $00000017           ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low

;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $00000018           ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
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
TPM1C1V             equ       $00000019           ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register

;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $00000019           ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High

;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $0000001A           ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low

;*** PWUDIV - PWU Divider Register
PWUDIV              equ       $0000001C           ;*** PWUDIV - PWU Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUDIV_WDIV0        equ       0                   ; Wake Up Divider Value, bit 0
PWUDIV_WDIV1        equ       1                   ; Wake Up Divider Value, bit 1
PWUDIV_WDIV2        equ       2                   ; Wake Up Divider Value, bit 2
PWUDIV_WDIV3        equ       3                   ; Wake Up Divider Value, bit 3
PWUDIV_WDIV4        equ       4                   ; Wake Up Divider Value, bit 4
PWUDIV_WDIV5        equ       5                   ; Wake Up Divider Value, bit 5
; bit position masks
mPWUDIV_WDIV0       equ       %00000001
mPWUDIV_WDIV1       equ       %00000010
mPWUDIV_WDIV2       equ       %00000100
mPWUDIV_WDIV3       equ       %00001000
mPWUDIV_WDIV4       equ       %00010000
mPWUDIV_WDIV5       equ       %00100000

;*** PWUCS0 - PWU Control/Status Regsiter 0
PWUCS0              equ       $0000001D           ;*** PWUCS0 - PWU Control/Status Regsiter 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUCS0_WUT0         equ       0                   ; Wake Up Time Interval, bit 0
PWUCS0_WUT1         equ       1                   ; Wake Up Time Interval, bit 1
PWUCS0_WUT2         equ       2                   ; Wake Up Time Interval, bit 2
PWUCS0_WUT3         equ       3                   ; Wake Up Time Interval, bit 3
PWUCS0_WUT4         equ       4                   ; Wake Up Time Interval, bit 4
PWUCS0_WUT5         equ       5                   ; Wake Up Time Interval, bit 5
PWUCS0_WUFACK       equ       6                   ; Acknowledge WUF Interrupt Flag
PWUCS0_WUF          equ       7                   ; Wake Up Interrupt Flag
; bit position masks
mPWUCS0_WUT0        equ       %00000001
mPWUCS0_WUT1        equ       %00000010
mPWUCS0_WUT2        equ       %00000100
mPWUCS0_WUT3        equ       %00001000
mPWUCS0_WUT4        equ       %00010000
mPWUCS0_WUT5        equ       %00100000
mPWUCS0_WUFACK      equ       %01000000
mPWUCS0_WUF         equ       %10000000

;*** PWUCS1 - PWU Control/Status Register 1
PWUCS1              equ       $0000001E           ;*** PWUCS1 - PWU Control/Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUCS1_PRST0        equ       0                   ; Periodic Reset Time Interval, Bit 0
PWUCS1_PRST1        equ       1                   ; Periodic Reset Time Interval, Bit 1
PWUCS1_PRST2        equ       2                   ; Periodic Reset Time Interval, Bit 2
PWUCS1_PRST3        equ       3                   ; Periodic Reset Time Interval, Bit 3
PWUCS1_PRST4        equ       4                   ; Periodic Reset Time Interval, Bit 4
PWUCS1_PRST5        equ       5                   ; Periodic Reset Time Interval, Bit 5
PWUCS1_PRFACK       equ       6                   ; Acknowledge PRF Reset Flag
PWUCS1_PRF          equ       7                   ; Periodic Reset Flag
; bit position masks
mPWUCS1_PRST0       equ       %00000001
mPWUCS1_PRST1       equ       %00000010
mPWUCS1_PRST2       equ       %00000100
mPWUCS1_PRST3       equ       %00001000
mPWUCS1_PRST4       equ       %00010000
mPWUCS1_PRST5       equ       %00100000
mPWUCS1_PRFACK      equ       %01000000
mPWUCS1_PRF         equ       %10000000

;*** PWUS - PWU Wake-Up Status Register
PWUS                equ       $0000001F           ;*** PWUS - PWU Wake-Up Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWUS_CSTAT0         equ       0                   ; Counter Status - These read-only bits show the status of the counter selected by the PSEL
PWUS_CSTAT1         equ       1                   ; Counter Status - These read-only bits show the status of the counter selected by the PSEL
PWUS_CSTAT2         equ       2                   ; Counter Status - These read-only bits show the status of the counter selected by the PSEL
PWUS_CSTAT3         equ       3                   ; Counter Status - These read-only bits show the status of the counter selected by the PSEL
PWUS_CSTAT4         equ       4                   ; Counter Status - These read-only bits show the status of the counter selected by the PSEL
PWUS_CSTAT5         equ       5                   ; Counter Status - These read-only bits show the status of the counter selected by the PSEL
PWUS_PSEL           equ       7                   ; Page Selection - The PSEL read/write bit selects whether the other bits are read from the
; bit position masks
mPWUS_CSTAT0        equ       %00000001
mPWUS_CSTAT1        equ       %00000010
mPWUS_CSTAT2        equ       %00000100
mPWUS_CSTAT3        equ       %00001000
mPWUS_CSTAT4        equ       %00010000
mPWUS_CSTAT5        equ       %00100000
mPWUS_PSEL          equ       %10000000

;*** LFCTL1 - LF Control Register 1
LFCTL1              equ       $00000020           ;*** LFCTL1 - LF Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTL1_SENS0        equ       0                   ; Sensitivity Control, bit 0
LFCTL1_SENS1        equ       1                   ; Sensitivity Control, bit 1
LFCTL1_IDSEL0       equ       2                   ; Wake Up ID Selection, bit 0
LFCTL1_IDSEL1       equ       3                   ; Wake Up ID Selection, bit 1
LFCTL1_LPAGE        equ       4                   ; Page Select
LFCTL1_CARMOD       equ       5                   ; Carrier Mode
LFCTL1_SRES         equ       6                   ; Soft Reset
LFCTL1_LFEN         equ       7                   ; LF Enable
; bit position masks
mLFCTL1_SENS0       equ       %00000001
mLFCTL1_SENS1       equ       %00000010
mLFCTL1_IDSEL0      equ       %00000100
mLFCTL1_IDSEL1      equ       %00001000
mLFCTL1_LPAGE       equ       %00010000
mLFCTL1_CARMOD      equ       %00100000
mLFCTL1_SRES        equ       %01000000
mLFCTL1_LFEN        equ       %10000000

;*** LFCTL2 - LF Control Register 2
LFCTL2              equ       $00000021           ;*** LFCTL2 - LF Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTL2_LFONTM0      equ       0                   ; LF Sampling ON Time Select, bit 0
LFCTL2_LFONTM1      equ       1                   ; LF Sampling ON Time Select, bit 1
LFCTL2_LFONTM2      equ       2                   ; LF Sampling ON Time Select, bit 2
LFCTL2_LFONTM3      equ       3                   ; LF Sampling ON Time Select, bit 3
LFCTL2_LFSTM0       equ       4                   ; LF Sampling Time Interval Select, bit 0
LFCTL2_LFSTM1       equ       5                   ; LF Sampling Time Interval Select, bit 1
LFCTL2_LFSTM2       equ       6                   ; LF Sampling Time Interval Select, bit 2
LFCTL2_LFSTM3       equ       7                   ; LF Sampling Time Interval Select, bit 3
; bit position masks
mLFCTL2_LFONTM0     equ       %00000001
mLFCTL2_LFONTM1     equ       %00000010
mLFCTL2_LFONTM2     equ       %00000100
mLFCTL2_LFONTM3     equ       %00001000
mLFCTL2_LFSTM0      equ       %00010000
mLFCTL2_LFSTM1      equ       %00100000
mLFCTL2_LFSTM2      equ       %01000000
mLFCTL2_LFSTM3      equ       %10000000

;*** LFCTRLD - LF Control Register D (LPAGE = 1)
LFCTRLD             equ       $00000022           ;*** LFCTRLD - LF Control Register D (LPAGE = 1)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTRLD_CHK125      equ       0                   ; 125 kHz Carrier Check
LFCTRLD_ONMODE      equ       1                   ; ON Mode Behavior
; bit position masks
mLFCTRLD_CHK125     equ       %00000001
mLFCTRLD_ONMODE     equ       %00000010

;*** LFCTL3 - LF Control Register 3 (LPAGE = 0)
LFCTL3              equ       $00000022           ;*** LFCTL3 - LF Control Register 3 (LPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTL3_LFCDTM0      equ       0                   ; LF Carrier Detect Time, bit 0
LFCTL3_LFCDTM1      equ       1                   ; LF Carrier Detect Time, bit 1
LFCTL3_LFCDTM2      equ       2                   ; LF Carrier Detect Time, bit 2
LFCTL3_LFCDTM3      equ       3                   ; LF Carrier Detect Time, bit 3
LFCTL3_SYNC0        equ       4                   ; LF SYNC Selection, bit 0
LFCTL3_SYNC1        equ       5                   ; LF SYNC Selection, bit 1
LFCTL3_TOGMOD       equ       6                   ; LFR Mode Toggle
LFCTL3_LFDO         equ       7                   ; LF Detector Output
; bit position masks
mLFCTL3_LFCDTM0     equ       %00000001
mLFCTL3_LFCDTM1     equ       %00000010
mLFCTL3_LFCDTM2     equ       %00000100
mLFCTL3_LFCDTM3     equ       %00001000
mLFCTL3_SYNC0       equ       %00010000
mLFCTL3_SYNC1       equ       %00100000
mLFCTL3_TOGMOD      equ       %01000000
mLFCTL3_LFDO        equ       %10000000

;*** LFCTRLC - LF Control Register C (LPAGE = 1)
LFCTRLC             equ       $00000023           ;*** LFCTRLC - LF Control Register C (LPAGE = 1)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTRLC_DEQEN       equ       0                   ; High Level Attenuator System Enable
LFCTRLC_LOWQ0       equ       1                   ; High Level Attenuator Select, bit 0
LFCTRLC_LOWQ1       equ       2                   ; High Level Attenuator Select, bit 1
; bit position masks
mLFCTRLC_DEQEN      equ       %00000001
mLFCTRLC_LOWQ0      equ       %00000010
mLFCTRLC_LOWQ1      equ       %00000100

;*** LFCTL4 - LFR Control Register 4 (LPAGE = 0)
LFCTL4              equ       $00000023           ;*** LFCTL4 - LFR Control Register 4 (LPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTL4_TIMOUT0      equ       0                   ; SYNC Time Out Select, bit 0, bit 0
LFCTL4_TIMOUT1      equ       1                   ; SYNC Time Out Select, bit 0, bit 1
LFCTL4_VALEN        equ       2                   ; LF carrier validation enable
LFCTL4_DECEN        equ       3                   ; LF Digital Decoder Enable
LFCTL4_LFIDIE       equ       4                   ; LFR ID Detect Interrupt Enable
LFCTL4_LFCDIE       equ       5                   ; LFR Carrier Detect Interrupt Enable
LFCTL4_LFERIE       equ       6                   ; LFR Error Interrupt Enable
LFCTL4_LFDRIE       equ       7                   ; LFR Data Register Full Interrupt Enable
; bit position masks
mLFCTL4_TIMOUT0     equ       %00000001
mLFCTL4_TIMOUT1     equ       %00000010
mLFCTL4_VALEN       equ       %00000100
mLFCTL4_DECEN       equ       %00001000
mLFCTL4_LFIDIE      equ       %00010000
mLFCTL4_LFCDIE      equ       %00100000
mLFCTL4_LFERIE      equ       %01000000
mLFCTL4_LFDRIE      equ       %10000000

;*** LFCTRLB - LF Control Register B (LPAGE = 1)
LFCTRLB             equ       $00000024           ;*** LFCTRLB - LF Control Register B (LPAGE = 1)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTRLB_LFPOL       equ       3                   ; LF Manchester Polarity Select
; bit position masks
mLFCTRLB_LFPOL      equ       %00001000

;*** LFS - LFR Status Register (LPAGE = 0)
LFS                 equ       $00000024           ;*** LFS - LFR Status Register (LPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFS_LFIACK          equ       0                   ; LF Interrupt Acknowledge
LFS_LPSM            equ       1                   ; Low Power Sniff Mode
LFS_LFEOMF          equ       2                   ; LF Receive Data EOM Flag
LFS_LFOVF           equ       3                   ; LF Receive Data Overflow Flag
LFS_LFIDF           equ       4                   ; LF ID Detect Flag
LFS_LFCDF           equ       5                   ; LF Carrier Pulse Detect Flag
LFS_LFERF           equ       6                   ; LF Receive Error Flag
LFS_LFDRF           equ       7                   ; LF Data Ready Flag
; bit position masks
mLFS_LFIACK         equ       %00000001
mLFS_LPSM           equ       %00000010
mLFS_LFEOMF         equ       %00000100
mLFS_LFOVF          equ       %00001000
mLFS_LFIDF          equ       %00010000
mLFS_LFCDF          equ       %00100000
mLFS_LFERF          equ       %01000000
mLFS_LFDRF          equ       %10000000

;*** LFCTRLA - LF Control Register A (LPAGE = 1)
LFCTRLA             equ       $00000025           ;*** LFCTRLA - LF Control Register A (LPAGE = 1)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFCTRLA_LFCC0       equ       0                   ; LF Successive Carrier Validations Counter, bit 0
LFCTRLA_LFCC1       equ       1                   ; LF Successive Carrier Validations Counter, bit 1
LFCTRLA_LFCC2       equ       2                   ; LF Successive Carrier Validations Counter, bit 2
LFCTRLA_LFCC3       equ       3                   ; LF Successive Carrier Validations Counter, bit 3
; bit position masks
mLFCTRLA_LFCC0      equ       %00000001
mLFCTRLA_LFCC1      equ       %00000010
mLFCTRLA_LFCC2      equ       %00000100
mLFCTRLA_LFCC3      equ       %00001000

;*** LFDATA - LFR Data Register (LPAGE = 0)
LFDATA              equ       $00000025           ;*** LFDATA - LFR Data Register (LPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFDATA_RXDATA0      equ       0                   ; Receive Data. LFR in data mode, bit 0
LFDATA_RXDATA1      equ       1                   ; Receive Data. LFR in data mode, bit 1
LFDATA_RXDATA2      equ       2                   ; Receive Data. LFR in data mode, bit 2
LFDATA_RXDATA3      equ       3                   ; Receive Data. LFR in data mode, bit 3
LFDATA_RXDATA4      equ       4                   ; Receive Data. LFR in data mode, bit 4
LFDATA_RXDATA5      equ       5                   ; Receive Data. LFR in data mode, bit 5
LFDATA_RXDATA6      equ       6                   ; Receive Data. LFR in data mode, bit 6
LFDATA_RXDATA7      equ       7                   ; Receive Data. LFR in data mode, bit 7
; bit position masks
mLFDATA_RXDATA0     equ       %00000001
mLFDATA_RXDATA1     equ       %00000010
mLFDATA_RXDATA2     equ       %00000100
mLFDATA_RXDATA3     equ       %00001000
mLFDATA_RXDATA4     equ       %00010000
mLFDATA_RXDATA5     equ       %00100000
mLFDATA_RXDATA6     equ       %01000000
mLFDATA_RXDATA7     equ       %10000000

;*** LFID - LFR ID Register
LFID                equ       $00000026           ;*** LFID - LFR ID Register

;*** LFIDL - LFR ID High Byte
LFIDL               equ       $00000026           ;*** LFIDL - LFR ID High Byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFIDL_ID0           equ       0                   ; LFR ID Bits, bit 0
LFIDL_ID1           equ       1                   ; LFR ID Bits, bit 1
LFIDL_ID2           equ       2                   ; LFR ID Bits, bit 2
LFIDL_ID3           equ       3                   ; LFR ID Bits, bit 3
LFIDL_ID4           equ       4                   ; LFR ID Bits, bit 4
LFIDL_ID5           equ       5                   ; LFR ID Bits, bit 5
LFIDL_ID6           equ       6                   ; LFR ID Bits, bit 6
LFIDL_ID7           equ       7                   ; LFR ID Bits, bit 7
; bit position masks
mLFIDL_ID0          equ       %00000001
mLFIDL_ID1          equ       %00000010
mLFIDL_ID2          equ       %00000100
mLFIDL_ID3          equ       %00001000
mLFIDL_ID4          equ       %00010000
mLFIDL_ID5          equ       %00100000
mLFIDL_ID6          equ       %01000000
mLFIDL_ID7          equ       %10000000

;*** LFIDH - LFR ID Low Byte
LFIDH               equ       $00000027           ;*** LFIDH - LFR ID Low Byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LFIDH_ID8           equ       0                   ; LFR ID, bit 8
LFIDH_ID9           equ       1                   ; LFR ID, bit 9
LFIDH_ID10          equ       2                   ; LFR ID, bit 10
LFIDH_ID11          equ       3                   ; LFR ID, bit 11
LFIDH_ID12          equ       4                   ; LFR ID, bit 12
LFIDH_ID13          equ       5                   ; LFR ID, bit 13
LFIDH_ID14          equ       6                   ; LFR ID, bit 14
LFIDH_ID15          equ       7                   ; LFR ID, bit 15
; bit position masks
mLFIDH_ID8          equ       %00000001
mLFIDH_ID9          equ       %00000010
mLFIDH_ID10         equ       %00000100
mLFIDH_ID11         equ       %00001000
mLFIDH_ID12         equ       %00010000
mLFIDH_ID13         equ       %00100000
mLFIDH_ID14         equ       %01000000
mLFIDH_ID15         equ       %10000000

;*** RFCR0 - RFM Control Register 0
RFCR0               equ       $00000030           ;*** RFCR0 - RFM Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR0_BPS0          equ       0                   ; Output Data Rate, bit 0
RFCR0_BPS1          equ       1                   ; Output Data Rate, bit 1
RFCR0_BPS2          equ       2                   ; Output Data Rate, bit 2
RFCR0_BPS3          equ       3                   ; Output Data Rate, bit 3
RFCR0_BPS4          equ       4                   ; Output Data Rate, bit 4
RFCR0_BPS5          equ       5                   ; Output Data Rate, bit 5
RFCR0_BPS6          equ       6                   ; Output Data Rate, bit 6
RFCR0_BPS7          equ       7                   ; Output Data Rate, bit 7
; bit position masks
mRFCR0_BPS0         equ       %00000001
mRFCR0_BPS1         equ       %00000010
mRFCR0_BPS2         equ       %00000100
mRFCR0_BPS3         equ       %00001000
mRFCR0_BPS4         equ       %00010000
mRFCR0_BPS5         equ       %00100000
mRFCR0_BPS6         equ       %01000000
mRFCR0_BPS7         equ       %10000000

;*** RFCR1 - RFM Control Register 1
RFCR1               equ       $00000031           ;*** RFCR1 - RFM Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR1_FRM0          equ       0                   ; Frame Bit Length, bit 0
RFCR1_FRM1          equ       1                   ; Frame Bit Length, bit 1
RFCR1_FRM2          equ       2                   ; Frame Bit Length, bit 2
RFCR1_FRM3          equ       3                   ; Frame Bit Length, bit 3
RFCR1_FRM4          equ       4                   ; Frame Bit Length, bit 4
RFCR1_FRM5          equ       5                   ; Frame Bit Length, bit 5
RFCR1_FRM6          equ       6                   ; Frame Bit Length, bit 6
RFCR1_FRM7          equ       7                   ; Frame Bit Length, bit 7
; bit position masks
mRFCR1_FRM0         equ       %00000001
mRFCR1_FRM1         equ       %00000010
mRFCR1_FRM2         equ       %00000100
mRFCR1_FRM3         equ       %00001000
mRFCR1_FRM4         equ       %00010000
mRFCR1_FRM5         equ       %00100000
mRFCR1_FRM6         equ       %01000000
mRFCR1_FRM7         equ       %10000000

;*** RFCR2 - RFM Control Register 2
RFCR2               equ       $00000032           ;*** RFCR2 - RFM Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR2_PWR0          equ       0                   ; RF Amplifier Power Level, bit 0
RFCR2_PWR1          equ       1                   ; RF Amplifier Power Level, bit 1
RFCR2_PWR2          equ       2                   ; RF Amplifier Power Level, bit 2
RFCR2_PWR3          equ       3                   ; RF Amplifier Power Level, bit 3
RFCR2_PWR4          equ       4                   ; RF Amplifier Power Level, bit 4
RFCR2_EOM           equ       5                   ; End Of Message
RFCR2_RPAGE         equ       6                   ; Buffer Page Select
RFCR2_SEND          equ       7                   ; Transmission Start Control
; bit position masks
mRFCR2_PWR0         equ       %00000001
mRFCR2_PWR1         equ       %00000010
mRFCR2_PWR2         equ       %00000100
mRFCR2_PWR3         equ       %00001000
mRFCR2_PWR4         equ       %00010000
mRFCR2_EOM          equ       %00100000
mRFCR2_RPAGE        equ       %01000000
mRFCR2_SEND         equ       %10000000

;*** RFCR3 - RFM Control Register 3
RFCR3               equ       $00000033           ;*** RFCR3 - RFM Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR3_FNUM0         equ       0                   ; Number of Transmitted Frames, bit 0
RFCR3_FNUM1         equ       1                   ; Number of Transmitted Frames, bit 1
RFCR3_FNUM2         equ       2                   ; Number of Transmitted Frames, bit 2
RFCR3_FNUM3         equ       3                   ; Number of Transmitted Frames, bit 3
RFCR3_IFID          equ       4                   ; Interframe Interrupt Delay
RFCR3_ISPC          equ       5                   ; Initial Random Space
RFCR3_IFPD          equ       6                   ; Interframe Power Down
RFCR3_DATA          equ       7                   ; Data State
; bit position masks
mRFCR3_FNUM0        equ       %00000001
mRFCR3_FNUM1        equ       %00000010
mRFCR3_FNUM2        equ       %00000100
mRFCR3_FNUM3        equ       %00001000
mRFCR3_IFID         equ       %00010000
mRFCR3_ISPC         equ       %00100000
mRFCR3_IFPD         equ       %01000000
mRFCR3_DATA         equ       %10000000

;*** RFCR4 - RFM Control Register 4
RFCR4               equ       $00000034           ;*** RFCR4 - RFM Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR4_RFBT0         equ       0                   ; Base Timer, bit 0
RFCR4_RFBT1         equ       1                   ; Base Timer, bit 1
RFCR4_RFBT2         equ       2                   ; Base Timer, bit 2
RFCR4_RFBT3         equ       3                   ; Base Timer, bit 3
RFCR4_RFBT4         equ       4                   ; Base Timer, bit 4
RFCR4_RFBT5         equ       5                   ; Base Timer, bit 5
RFCR4_RFBT6         equ       6                   ; Base Timer, bit 6
RFCR4_RFBT7         equ       7                   ; Base Timer, bit 7
; bit position masks
mRFCR4_RFBT0        equ       %00000001
mRFCR4_RFBT1        equ       %00000010
mRFCR4_RFBT2        equ       %00000100
mRFCR4_RFBT3        equ       %00001000
mRFCR4_RFBT4        equ       %00010000
mRFCR4_RFBT5        equ       %00100000
mRFCR4_RFBT6        equ       %01000000
mRFCR4_RFBT7        equ       %10000000

;*** RFCR5 - RFM Control Register 5
RFCR5               equ       $00000035           ;*** RFCR5 - RFM Control Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR5_LFSR0         equ       0                   ; Pseudo-Random Timer, bit 0
RFCR5_LFSR1         equ       1                   ; Pseudo-Random Timer, bit 1
RFCR5_LFSR2         equ       2                   ; Pseudo-Random Timer, bit 2
RFCR5_LFSR3         equ       3                   ; Pseudo-Random Timer, bit 3
RFCR5_LFSR4         equ       4                   ; Pseudo-Random Timer, bit 4
RFCR5_LFSR5         equ       5                   ; Pseudo-Random Timer, bit 5
RFCR5_LFSR6         equ       6                   ; Pseudo-Random Timer, bit 6
RFCR5_BOOST         equ       7                   ; BOOST
; bit position masks
mRFCR5_LFSR0        equ       %00000001
mRFCR5_LFSR1        equ       %00000010
mRFCR5_LFSR2        equ       %00000100
mRFCR5_LFSR3        equ       %00001000
mRFCR5_LFSR4        equ       %00010000
mRFCR5_LFSR5        equ       %00100000
mRFCR5_LFSR6        equ       %01000000
mRFCR5_BOOST        equ       %10000000

;*** RFCR6 - RFM Control Register 6
RFCR6               equ       $00000036           ;*** RFCR6 - RFM Control Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR6_RFFT0         equ       0                   ; Frame Number Timer, bit 0
RFCR6_RFFT1         equ       1                   ; Frame Number Timer, bit 1
RFCR6_RFFT2         equ       2                   ; Frame Number Timer, bit 2
RFCR6_RFFT3         equ       3                   ; Frame Number Timer, bit 3
RFCR6_RFFT4         equ       4                   ; Frame Number Timer, bit 4
RFCR6_RFFT5         equ       5                   ; Frame Number Timer, bit 5
RFCR6_VCO_GAIN0     equ       6                   ; VCO Gain Selection, bit 0
RFCR6_VCO_GAIN1     equ       7                   ; VCO Gain Selection, bit 1
; bit position masks
mRFCR6_RFFT0        equ       %00000001
mRFCR6_RFFT1        equ       %00000010
mRFCR6_RFFT2        equ       %00000100
mRFCR6_RFFT3        equ       %00001000
mRFCR6_RFFT4        equ       %00010000
mRFCR6_RFFT5        equ       %00100000
mRFCR6_VCO_GAIN0    equ       %01000000
mRFCR6_VCO_GAIN1    equ       %10000000

;*** RFCR7 - RFM Control Register 7
RFCR7               equ       $00000037           ;*** RFCR7 - RFM Control Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFCR7_RFMRST        equ       0                   ; RFM Reset
RFCR7_RCTS          equ       1                   ; RF Clear To Send Status
RFCR7_RFLVDEN       equ       2                   ; RF LVD Enable
RFCR7_RFIEN         equ       3                   ; RF Interrupt Enable
RFCR7_RFIACK        equ       4                   ; Acknowledge RF Interrupt Flags
RFCR7_RFVF          equ       5                   ; RF LVD Trigger Flag
RFCR7_RFEF          equ       6                   ; RF Transmission Error Flag
RFCR7_RFIF          equ       7                   ; RF Interrupt Flag
; bit position masks
mRFCR7_RFMRST       equ       %00000001
mRFCR7_RCTS         equ       %00000010
mRFCR7_RFLVDEN      equ       %00000100
mRFCR7_RFIEN        equ       %00001000
mRFCR7_RFIACK       equ       %00010000
mRFCR7_RFVF         equ       %00100000
mRFCR7_RFEF         equ       %01000000
mRFCR7_RFIF         equ       %10000000

;*** EPR_PLL_LPF - EPR Register (RPAGE = 1, VCD_EN = 0)
EPR_PLL_LPF         equ       $00000038           ;*** EPR_PLL_LPF - EPR Register (RPAGE = 1, VCD_EN = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPR_PLL_LPF_PA_SLOPE equ       1                   ; PA Output Slope Selection
EPR_PLL_LPF_PLL_LPF0 equ       4                   ; Low Pass Filter Selection, bit 0
EPR_PLL_LPF_PLL_LPF1 equ       5                   ; Low Pass Filter Selection, bit 1
EPR_PLL_LPF_PLL_LPF2 equ       6                   ; Low Pass Filter Selection, bit 2
; bit position masks
mEPR_PLL_LPF_PA_SLOPE equ       %00000010
mEPR_PLL_LPF_PLL_LPF0 equ       %00010000
mEPR_PLL_LPF_PLL_LPF1 equ       %00100000
mEPR_PLL_LPF_PLL_LPF2 equ       %01000000

;*** EPR_VCD - EPR Register (RPAGE = 1, VCD_EN = 1)
EPR_VCD             equ       $00000038           ;*** EPR_VCD - EPR Register (RPAGE = 1, VCD_EN = 1)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
EPR_VCD_VCD_EN      equ       0                   ; VCD Enable bit
EPR_VCD_PA_SLOPE    equ       1                   ; PA Output Slope Selection
EPR_VCD_VCD0        equ       4                   ; VCO Calibration Count Difference, bit 0
EPR_VCD_VCD1        equ       5                   ; VCO Calibration Count Difference, bit 1
EPR_VCD_VCD2        equ       6                   ; VCO Calibration Count Difference, bit 2
EPR_VCD_VCD3        equ       7                   ; VCO Calibration Count Difference, bit 3
; bit position masks
mEPR_VCD_VCD_EN     equ       %00000001
mEPR_VCD_PA_SLOPE   equ       %00000010
mEPR_VCD_VCD0       equ       %00010000
mEPR_VCD_VCD1       equ       %00100000
mEPR_VCD_VCD2       equ       %01000000
mEPR_VCD_VCD3       equ       %10000000

;*** PLLCR0 - PLL Control Register 0 (RPAGE = 0)
PLLCR0              equ       $00000038           ;*** PLLCR0 - PLL Control Register 0 (RPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PLLCR0_AFREQ5       equ       0                   ; PLL Divider Ratio A, bit 5
PLLCR0_AFREQ6       equ       1                   ; PLL Divider Ratio A, bit 6
PLLCR0_AFREQ7       equ       2                   ; PLL Divider Ratio A, bit 7
PLLCR0_AFREQ8       equ       3                   ; PLL Divider Ratio A, bit 8
PLLCR0_AFREQ9       equ       4                   ; PLL Divider Ratio A, bit 9
PLLCR0_AFREQ10      equ       5                   ; PLL Divider Ratio A, bit 10
PLLCR0_AFREQ11      equ       6                   ; PLL Divider Ratio A, bit 11
PLLCR0_AFREQ12      equ       7                   ; PLL Divider Ratio A, bit 12
; bit position masks
mPLLCR0_AFREQ5      equ       %00000001
mPLLCR0_AFREQ6      equ       %00000010
mPLLCR0_AFREQ7      equ       %00000100
mPLLCR0_AFREQ8      equ       %00001000
mPLLCR0_AFREQ9      equ       %00010000
mPLLCR0_AFREQ10     equ       %00100000
mPLLCR0_AFREQ11     equ       %01000000
mPLLCR0_AFREQ12     equ       %10000000

;*** PLLCR1 - PLL Control Register 1 (RPAGE = 0)
PLLCR1              equ       $00000039           ;*** PLLCR1 - PLL Control Register 1 (RPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PLLCR1_CODE0        equ       0                   ; Data Encoding and Source, bit 0
PLLCR1_CODE1        equ       1                   ; Data Encoding and Source, bit 1
PLLCR1_POL          equ       2                   ; Data Polarity
PLLCR1_AFREQ0       equ       3                   ; PLL Divider Ratio A, bit 0
PLLCR1_AFREQ1       equ       4                   ; PLL Divider Ratio A, bit 1
PLLCR1_AFREQ2       equ       5                   ; PLL Divider Ratio A, bit 2
PLLCR1_AFREQ3       equ       6                   ; PLL Divider Ratio A, bit 3
PLLCR1_AFREQ4       equ       7                   ; PLL Divider Ratio A, bit 4
; bit position masks
mPLLCR1_CODE0       equ       %00000001
mPLLCR1_CODE1       equ       %00000010
mPLLCR1_POL         equ       %00000100
mPLLCR1_AFREQ0      equ       %00001000
mPLLCR1_AFREQ1      equ       %00010000
mPLLCR1_AFREQ2      equ       %00100000
mPLLCR1_AFREQ3      equ       %01000000
mPLLCR1_AFREQ4      equ       %10000000

;*** PLLCR2 - PLL Control Register 2 (RPAGE = 0)
PLLCR2              equ       $0000003A           ;*** PLLCR2 - PLL Control Register 2 (RPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PLLCR2_BFREQ5       equ       0                   ; PLL Divider Ratio B, bit 5
PLLCR2_BFREQ6       equ       1                   ; PLL Divider Ratio B, bit 6
PLLCR2_BFREQ7       equ       2                   ; PLL Divider Ratio B, bit 7
PLLCR2_BFREQ8       equ       3                   ; PLL Divider Ratio B, bit 8
PLLCR2_BFREQ9       equ       4                   ; PLL Divider Ratio B, bit 9
PLLCR2_BFREQ10      equ       5                   ; PLL Divider Ratio B, bit 10
PLLCR2_BFREQ11      equ       6                   ; PLL Divider Ratio B, bit 11
PLLCR2_BFREQ12      equ       7                   ; PLL Divider Ratio B, bit 12
; bit position masks
mPLLCR2_BFREQ5      equ       %00000001
mPLLCR2_BFREQ6      equ       %00000010
mPLLCR2_BFREQ7      equ       %00000100
mPLLCR2_BFREQ8      equ       %00001000
mPLLCR2_BFREQ9      equ       %00010000
mPLLCR2_BFREQ10     equ       %00100000
mPLLCR2_BFREQ11     equ       %01000000
mPLLCR2_BFREQ12     equ       %10000000

;*** PLLCR3 - PLL Control Register 3 (RPAGE = 0)
PLLCR3              equ       $0000003B           ;*** PLLCR3 - PLL Control Register 3 (RPAGE = 0)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PLLCR3_CKREF        equ       0                   ; Generated Clock Reference
PLLCR3_MOD          equ       1                   ; RF Modulation Method
PLLCR3_CF           equ       2                   ; Carrier Frequency
PLLCR3_BFREQ0       equ       3                   ; PLL Divider Ratio B, bit 0
PLLCR3_BFREQ1       equ       4                   ; PLL Divider Ratio B, bit 1
PLLCR3_BFREQ2       equ       5                   ; PLL Divider Ratio B, bit 2
PLLCR3_BFREQ3       equ       6                   ; PLL Divider Ratio B, bit 3
PLLCR3_BFREQ4       equ       7                   ; PLL Divider Ratio B, bit 4
; bit position masks
mPLLCR3_CKREF       equ       %00000001
mPLLCR3_MOD         equ       %00000010
mPLLCR3_CF          equ       %00000100
mPLLCR3_BFREQ0      equ       %00001000
mPLLCR3_BFREQ1      equ       %00010000
mPLLCR3_BFREQ2      equ       %00100000
mPLLCR3_BFREQ3      equ       %01000000
mPLLCR3_BFREQ4      equ       %10000000

;*** RFD0 - RFD Register 0
RFD0                equ       $0000003C           ;*** RFD0 - RFD Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD0_RFD0           equ       0                   ; RFD, bit 0
RFD0_RFD1           equ       1                   ; RFD, bit 1
RFD0_RFD2           equ       2                   ; RFD, bit 2
RFD0_RFD3           equ       3                   ; RFD, bit 3
RFD0_RFD4           equ       4                   ; RFD, bit 4
RFD0_RFD5           equ       5                   ; RFD, bit 5
RFD0_RFD6           equ       6                   ; RFD, bit 6
RFD0_RFD7           equ       7                   ; RFD, bit 7
; bit position masks
mRFD0_RFD0          equ       %00000001
mRFD0_RFD1          equ       %00000010
mRFD0_RFD2          equ       %00000100
mRFD0_RFD3          equ       %00001000
mRFD0_RFD4          equ       %00010000
mRFD0_RFD5          equ       %00100000
mRFD0_RFD6          equ       %01000000
mRFD0_RFD7          equ       %10000000

;*** RFD1 - RFD Register 1
RFD1                equ       $0000003D           ;*** RFD1 - RFD Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD1_RFD8           equ       0                   ; RFD, bit 8
RFD1_RFD9           equ       1                   ; RFD, bit 9
RFD1_RFD10          equ       2                   ; RFD, bit 10
RFD1_RFD11          equ       3                   ; RFD, bit 11
RFD1_RFD12          equ       4                   ; RFD, bit 12
RFD1_RFD13          equ       5                   ; RFD, bit 13
RFD1_RFD14          equ       6                   ; RFD, bit 14
RFD1_RFD15          equ       7                   ; RFD, bit 15
; bit position masks
mRFD1_RFD8          equ       %00000001
mRFD1_RFD9          equ       %00000010
mRFD1_RFD10         equ       %00000100
mRFD1_RFD11         equ       %00001000
mRFD1_RFD12         equ       %00010000
mRFD1_RFD13         equ       %00100000
mRFD1_RFD14         equ       %01000000
mRFD1_RFD15         equ       %10000000

;*** RFD2 - RFD Register 2
RFD2                equ       $0000003E           ;*** RFD2 - RFD Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD2_RFD16          equ       0                   ; RFD, bit 16
RFD2_RFD17          equ       1                   ; RFD, bit 17
RFD2_RFD18          equ       2                   ; RFD, bit 18
RFD2_RFD19          equ       3                   ; RFD, bit 19
RFD2_RFD20          equ       4                   ; RFD, bit 20
RFD2_RFD21          equ       5                   ; RFD, bit 21
RFD2_RFD22          equ       6                   ; RFD, bit 22
RFD2_RFD23          equ       7                   ; RFD, bit 23
; bit position masks
mRFD2_RFD16         equ       %00000001
mRFD2_RFD17         equ       %00000010
mRFD2_RFD18         equ       %00000100
mRFD2_RFD19         equ       %00001000
mRFD2_RFD20         equ       %00010000
mRFD2_RFD21         equ       %00100000
mRFD2_RFD22         equ       %01000000
mRFD2_RFD23         equ       %10000000

;*** RFD3 - RFD Register 3
RFD3                equ       $0000003F           ;*** RFD3 - RFD Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD3_RFD24          equ       0                   ; RFD, bit 24
RFD3_RFD25          equ       1                   ; RFD, bit 25
RFD3_RFD26          equ       2                   ; RFD, bit 26
RFD3_RFD27          equ       3                   ; RFD, bit 27
RFD3_RFD28          equ       4                   ; RFD, bit 28
RFD3_RFD29          equ       5                   ; RFD, bit 29
RFD3_RFD30          equ       6                   ; RFD, bit 30
RFD3_RFD31          equ       7                   ; RFD, bit 31
; bit position masks
mRFD3_RFD24         equ       %00000001
mRFD3_RFD25         equ       %00000010
mRFD3_RFD26         equ       %00000100
mRFD3_RFD27         equ       %00001000
mRFD3_RFD28         equ       %00010000
mRFD3_RFD29         equ       %00100000
mRFD3_RFD30         equ       %01000000
mRFD3_RFD31         equ       %10000000

;*** RFD4 - RFD Register 4
RFD4                equ       $00000040           ;*** RFD4 - RFD Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD4_RFD32          equ       0                   ; RFD, bit 32
RFD4_RFD33          equ       1                   ; RFD, bit 33
RFD4_RFD34          equ       2                   ; RFD, bit 34
RFD4_RFD35          equ       3                   ; RFD, bit 35
RFD4_RFD36          equ       4                   ; RFD, bit 36
RFD4_RFD37          equ       5                   ; RFD, bit 37
RFD4_RFD38          equ       6                   ; RFD, bit 38
RFD4_RFD39          equ       7                   ; RFD, bit 39
; bit position masks
mRFD4_RFD32         equ       %00000001
mRFD4_RFD33         equ       %00000010
mRFD4_RFD34         equ       %00000100
mRFD4_RFD35         equ       %00001000
mRFD4_RFD36         equ       %00010000
mRFD4_RFD37         equ       %00100000
mRFD4_RFD38         equ       %01000000
mRFD4_RFD39         equ       %10000000

;*** RFD5 - RFD Register 5
RFD5                equ       $00000041           ;*** RFD5 - RFD Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD5_RFD40          equ       0                   ; RFD, bit 40
RFD5_RFD41          equ       1                   ; RFD, bit 41
RFD5_RFD42          equ       2                   ; RFD, bit 42
RFD5_RFD43          equ       3                   ; RFD, bit 43
RFD5_RFD44          equ       4                   ; RFD, bit 44
RFD5_RFD45          equ       5                   ; RFD, bit 45
RFD5_RFD46          equ       6                   ; RFD, bit 46
RFD5_RFD47          equ       7                   ; RFD, bit 47
; bit position masks
mRFD5_RFD40         equ       %00000001
mRFD5_RFD41         equ       %00000010
mRFD5_RFD42         equ       %00000100
mRFD5_RFD43         equ       %00001000
mRFD5_RFD44         equ       %00010000
mRFD5_RFD45         equ       %00100000
mRFD5_RFD46         equ       %01000000
mRFD5_RFD47         equ       %10000000

;*** RFD6 - RFD Register 6
RFD6                equ       $00000042           ;*** RFD6 - RFD Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD6_RFD48          equ       0                   ; RFD, bit 48
RFD6_RFD49          equ       1                   ; RFD, bit 49
RFD6_RFD50          equ       2                   ; RFD, bit 50
RFD6_RFD51          equ       3                   ; RFD, bit 51
RFD6_RFD52          equ       4                   ; RFD, bit 52
RFD6_RFD53          equ       5                   ; RFD, bit 53
RFD6_RFD54          equ       6                   ; RFD, bit 54
RFD6_RFD55          equ       7                   ; RFD, bit 55
; bit position masks
mRFD6_RFD48         equ       %00000001
mRFD6_RFD49         equ       %00000010
mRFD6_RFD50         equ       %00000100
mRFD6_RFD51         equ       %00001000
mRFD6_RFD52         equ       %00010000
mRFD6_RFD53         equ       %00100000
mRFD6_RFD54         equ       %01000000
mRFD6_RFD55         equ       %10000000

;*** RFD7 - RFD Register 7
RFD7                equ       $00000043           ;*** RFD7 - RFD Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD7_RFD56          equ       0                   ; RFD, bit 56
RFD7_RFD57          equ       1                   ; RFD, bit 57
RFD7_RFD58          equ       2                   ; RFD, bit 58
RFD7_RFD59          equ       3                   ; RFD, bit 59
RFD7_RFD60          equ       4                   ; RFD, bit 60
RFD7_RFD61          equ       5                   ; RFD, bit 61
RFD7_RFD62          equ       6                   ; RFD, bit 62
RFD7_RFD63          equ       7                   ; RFD, bit 63
; bit position masks
mRFD7_RFD56         equ       %00000001
mRFD7_RFD57         equ       %00000010
mRFD7_RFD58         equ       %00000100
mRFD7_RFD59         equ       %00001000
mRFD7_RFD60         equ       %00010000
mRFD7_RFD61         equ       %00100000
mRFD7_RFD62         equ       %01000000
mRFD7_RFD63         equ       %10000000

;*** RFD8 - RFD Register 8
RFD8                equ       $00000044           ;*** RFD8 - RFD Register 8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD8_RFD64          equ       0                   ; RFD, bit 64
RFD8_RFD65          equ       1                   ; RFD, bit 65
RFD8_RFD66          equ       2                   ; RFD, bit 66
RFD8_RFD67          equ       3                   ; RFD, bit 67
RFD8_RFD68          equ       4                   ; RFD, bit 68
RFD8_RFD69          equ       5                   ; RFD, bit 69
RFD8_RFD70          equ       6                   ; RFD, bit 70
RFD8_RFD71          equ       7                   ; RFD, bit 71
; bit position masks
mRFD8_RFD64         equ       %00000001
mRFD8_RFD65         equ       %00000010
mRFD8_RFD66         equ       %00000100
mRFD8_RFD67         equ       %00001000
mRFD8_RFD68         equ       %00010000
mRFD8_RFD69         equ       %00100000
mRFD8_RFD70         equ       %01000000
mRFD8_RFD71         equ       %10000000

;*** RFD9 - RFD Register 9
RFD9                equ       $00000045           ;*** RFD9 - RFD Register 9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD9_RFD72          equ       0                   ; RFD, bit 72
RFD9_RFD73          equ       1                   ; RFD, bit 73
RFD9_RFD74          equ       2                   ; RFD, bit 74
RFD9_RFD75          equ       3                   ; RFD, bit 75
RFD9_RFD76          equ       4                   ; RFD, bit 76
RFD9_RFD77          equ       5                   ; RFD, bit 77
RFD9_RFD78          equ       6                   ; RFD, bit 78
RFD9_RFD79          equ       7                   ; RFD, bit 79
; bit position masks
mRFD9_RFD72         equ       %00000001
mRFD9_RFD73         equ       %00000010
mRFD9_RFD74         equ       %00000100
mRFD9_RFD75         equ       %00001000
mRFD9_RFD76         equ       %00010000
mRFD9_RFD77         equ       %00100000
mRFD9_RFD78         equ       %01000000
mRFD9_RFD79         equ       %10000000

;*** RFD10 - RFD Register 10
RFD10               equ       $00000046           ;*** RFD10 - RFD Register 10
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD10_RFD80         equ       0                   ; RFD, bit 80
RFD10_RFD81         equ       1                   ; RFD, bit 81
RFD10_RFD82         equ       2                   ; RFD, bit 82
RFD10_RFD83         equ       3                   ; RFD, bit 83
RFD10_RFD84         equ       4                   ; RFD, bit 84
RFD10_RFD85         equ       5                   ; RFD, bit 85
RFD10_RFD86         equ       6                   ; RFD, bit 86
RFD10_RFD87         equ       7                   ; RFD, bit 87
; bit position masks
mRFD10_RFD80        equ       %00000001
mRFD10_RFD81        equ       %00000010
mRFD10_RFD82        equ       %00000100
mRFD10_RFD83        equ       %00001000
mRFD10_RFD84        equ       %00010000
mRFD10_RFD85        equ       %00100000
mRFD10_RFD86        equ       %01000000
mRFD10_RFD87        equ       %10000000

;*** RFD11 - RFD Register 11
RFD11               equ       $00000047           ;*** RFD11 - RFD Register 11
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD11_RFD88         equ       0                   ; RFD, bit 88
RFD11_RFD89         equ       1                   ; RFD, bit 89
RFD11_RFD90         equ       2                   ; RFD, bit 90
RFD11_RFD91         equ       3                   ; RFD, bit 91
RFD11_RFD92         equ       4                   ; RFD, bit 92
RFD11_RFD93         equ       5                   ; RFD, bit 93
RFD11_RFD94         equ       6                   ; RFD, bit 94
RFD11_RFD95         equ       7                   ; RFD, bit 95
; bit position masks
mRFD11_RFD88        equ       %00000001
mRFD11_RFD89        equ       %00000010
mRFD11_RFD90        equ       %00000100
mRFD11_RFD91        equ       %00001000
mRFD11_RFD92        equ       %00010000
mRFD11_RFD93        equ       %00100000
mRFD11_RFD94        equ       %01000000
mRFD11_RFD95        equ       %10000000

;*** RFD12 - RFD Register 12
RFD12               equ       $00000048           ;*** RFD12 - RFD Register 12
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD12_RFD96         equ       0                   ; RFD, bit 96
RFD12_RFD97         equ       1                   ; RFD, bit 97
RFD12_RFD98         equ       2                   ; RFD, bit 98
RFD12_RFD99         equ       3                   ; RFD, bit 99
RFD12_RFD100        equ       4                   ; RFD, bit 100
RFD12_RFD101        equ       5                   ; RFD, bit 101
RFD12_RFD102        equ       6                   ; RFD, bit 102
RFD12_RFD103        equ       7                   ; RFD, bit 103
; bit position masks
mRFD12_RFD96        equ       %00000001
mRFD12_RFD97        equ       %00000010
mRFD12_RFD98        equ       %00000100
mRFD12_RFD99        equ       %00001000
mRFD12_RFD100       equ       %00010000
mRFD12_RFD101       equ       %00100000
mRFD12_RFD102       equ       %01000000
mRFD12_RFD103       equ       %10000000

;*** RFD13 - RFD Register 13
RFD13               equ       $00000049           ;*** RFD13 - RFD Register 13
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD13_RFD104        equ       0                   ; RFD, bit 104
RFD13_RFD105        equ       1                   ; RFD, bit 105
RFD13_RFD106        equ       2                   ; RFD, bit 106
RFD13_RFD107        equ       3                   ; RFD, bit 107
RFD13_RFD108        equ       4                   ; RFD, bit 108
RFD13_RFD109        equ       5                   ; RFD, bit 109
RFD13_RFD110        equ       6                   ; RFD, bit 110
RFD13_RFD111        equ       7                   ; RFD, bit 111
; bit position masks
mRFD13_RFD104       equ       %00000001
mRFD13_RFD105       equ       %00000010
mRFD13_RFD106       equ       %00000100
mRFD13_RFD107       equ       %00001000
mRFD13_RFD108       equ       %00010000
mRFD13_RFD109       equ       %00100000
mRFD13_RFD110       equ       %01000000
mRFD13_RFD111       equ       %10000000

;*** RFD14 - RFD Register 14
RFD14               equ       $0000004A           ;*** RFD14 - RFD Register 14
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD14_RFD112        equ       0                   ; RFD, bit 112
RFD14_RFD113        equ       1                   ; RFD, bit 113
RFD14_RFD114        equ       2                   ; RFD, bit 114
RFD14_RFD115        equ       3                   ; RFD, bit 115
RFD14_RFD116        equ       4                   ; RFD, bit 116
RFD14_RFD117        equ       5                   ; RFD, bit 117
RFD14_RFD118        equ       6                   ; RFD, bit 118
RFD14_RFD119        equ       7                   ; RFD, bit 119
; bit position masks
mRFD14_RFD112       equ       %00000001
mRFD14_RFD113       equ       %00000010
mRFD14_RFD114       equ       %00000100
mRFD14_RFD115       equ       %00001000
mRFD14_RFD116       equ       %00010000
mRFD14_RFD117       equ       %00100000
mRFD14_RFD118       equ       %01000000
mRFD14_RFD119       equ       %10000000

;*** RFD15 - RFD Register 15
RFD15               equ       $0000004B           ;*** RFD15 - RFD Register 15
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RFD15_RFD120        equ       0                   ; RFD, bit 120
RFD15_RFD121        equ       1                   ; RFD, bit 121
RFD15_RFD122        equ       2                   ; RFD, bit 122
RFD15_RFD123        equ       3                   ; RFD, bit 123
RFD15_RFD124        equ       4                   ; RFD, bit 124
RFD15_RFD125        equ       5                   ; RFD, bit 125
RFD15_RFD126        equ       6                   ; RFD, bit 126
RFD15_RFD127        equ       7                   ; RFD, bit 127
; bit position masks
mRFD15_RFD120       equ       %00000001
mRFD15_RFD121       equ       %00000010
mRFD15_RFD122       equ       %00000100
mRFD15_RFD123       equ       %00001000
mRFD15_RFD124       equ       %00010000
mRFD15_RFD125       equ       %00100000
mRFD15_RFD126       equ       %01000000
mRFD15_RFD127       equ       %10000000

;*** PARAM0 - Parameter Register 0
PARAM0              equ       $00000050           ;*** PARAM0 - Parameter Register 0
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
PARAM1              equ       $00000051           ;*** PARAM1 - Parameter Register 1
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
PARAM2              equ       $00000052           ;*** PARAM2 - Parameter Register 2
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
PARAM3              equ       $00000053           ;*** PARAM3 - Parameter Register 3
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
PARAM4              equ       $00000054           ;*** PARAM4 - Parameter Register 4
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
PARAM5              equ       $00000055           ;*** PARAM5 - Parameter Register 5
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
PARAM6              equ       $00000056           ;*** PARAM6 - Parameter Register 6
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
PARAM7              equ       $00000057           ;*** PARAM7 - Parameter Register 7
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
PARAM8              equ       $00000058           ;*** PARAM8 - Parameter Register 8
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
PARAM9              equ       $00000059           ;*** PARAM9 - Parameter Register 9
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
PARAM10             equ       $0000005A           ;*** PARAM10 - Parameter Register 10
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
PARAM11             equ       $0000005B           ;*** PARAM11 - Parameter Register 11
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
PARAM12             equ       $0000005C           ;*** PARAM12 - Parameter Register 12
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
PARAM13             equ       $0000005D           ;*** PARAM13 - Parameter Register 13
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
PARAM14             equ       $0000005E           ;*** PARAM14 - Parameter Register 14
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
PARAM15             equ       $0000005F           ;*** PARAM15 - Parameter Register 15
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
PARAM16             equ       $00000060           ;*** PARAM16 - Parameter Register 16
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
PARAM17             equ       $00000061           ;*** PARAM17 - Parameter Register 17
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
PARAM18             equ       $00000062           ;*** PARAM18 - Parameter Register 18
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
PARAM19             equ       $00000063           ;*** PARAM19 - Parameter Register 19
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
PARAM20             equ       $00000064           ;*** PARAM20 - Parameter Register 20
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
PARAM21             equ       $00000065           ;*** PARAM21 - Parameter Register 21
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
PARAM22             equ       $00000066           ;*** PARAM22 - Parameter Register 22
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
PARAM23             equ       $00000067           ;*** PARAM23 - Parameter Register 23
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
PARAM24             equ       $00000068           ;*** PARAM24 - Parameter Register 24
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
PARAM25             equ       $00000069           ;*** PARAM25 - Parameter Register 25
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
PARAM26             equ       $0000006A           ;*** PARAM26 - Parameter Register 26
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
PARAM27             equ       $0000006B           ;*** PARAM27 - Parameter Register 27
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
PARAM28             equ       $0000006C           ;*** PARAM28 - Parameter Register 28
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
PARAM29             equ       $0000006D           ;*** PARAM29 - Parameter Register 29
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
PARAM30             equ       $0000006E           ;*** PARAM30 - Parameter Register 30
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
PARAM31             equ       $0000006F           ;*** PARAM31 - Parameter Register 31
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

;*** PARAM32 - Parameter Register 32
PARAM32             equ       $00000070           ;*** PARAM32 - Parameter Register 32
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM32_BIT0        equ       0                   ; Bit 0
PARAM32_BIT1        equ       1                   ; Bit 1
PARAM32_BIT2        equ       2                   ; Bit 2
PARAM32_BIT3        equ       3                   ; Bit 3
PARAM32_BIT4        equ       4                   ; Bit 4
PARAM32_BIT5        equ       5                   ; Bit 5
PARAM32_BIT6        equ       6                   ; Bit 6
PARAM32_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM32_BIT0       equ       %00000001
mPARAM32_BIT1       equ       %00000010
mPARAM32_BIT2       equ       %00000100
mPARAM32_BIT3       equ       %00001000
mPARAM32_BIT4       equ       %00010000
mPARAM32_BIT5       equ       %00100000
mPARAM32_BIT6       equ       %01000000
mPARAM32_BIT7       equ       %10000000

;*** PARAM33 - Parameter Register 33
PARAM33             equ       $00000071           ;*** PARAM33 - Parameter Register 33
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM33_BIT0        equ       0                   ; Bit 0
PARAM33_BIT1        equ       1                   ; Bit 1
PARAM33_BIT2        equ       2                   ; Bit 2
PARAM33_BIT3        equ       3                   ; Bit 3
PARAM33_BIT4        equ       4                   ; Bit 4
PARAM33_BIT5        equ       5                   ; Bit 5
PARAM33_BIT6        equ       6                   ; Bit 6
PARAM33_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM33_BIT0       equ       %00000001
mPARAM33_BIT1       equ       %00000010
mPARAM33_BIT2       equ       %00000100
mPARAM33_BIT3       equ       %00001000
mPARAM33_BIT4       equ       %00010000
mPARAM33_BIT5       equ       %00100000
mPARAM33_BIT6       equ       %01000000
mPARAM33_BIT7       equ       %10000000

;*** PARAM34 - Parameter Register 34
PARAM34             equ       $00000072           ;*** PARAM34 - Parameter Register 34
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM34_BIT0        equ       0                   ; Bit 0
PARAM34_BIT1        equ       1                   ; Bit 1
PARAM34_BIT2        equ       2                   ; Bit 2
PARAM34_BIT3        equ       3                   ; Bit 3
PARAM34_BIT4        equ       4                   ; Bit 4
PARAM34_BIT5        equ       5                   ; Bit 5
PARAM34_BIT6        equ       6                   ; Bit 6
PARAM34_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM34_BIT0       equ       %00000001
mPARAM34_BIT1       equ       %00000010
mPARAM34_BIT2       equ       %00000100
mPARAM34_BIT3       equ       %00001000
mPARAM34_BIT4       equ       %00010000
mPARAM34_BIT5       equ       %00100000
mPARAM34_BIT6       equ       %01000000
mPARAM34_BIT7       equ       %10000000

;*** PARAM35 - Parameter Register 35
PARAM35             equ       $00000073           ;*** PARAM35 - Parameter Register 35
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM35_BIT0        equ       0                   ; Bit 0
PARAM35_BIT1        equ       1                   ; Bit 1
PARAM35_BIT2        equ       2                   ; Bit 2
PARAM35_BIT3        equ       3                   ; Bit 3
PARAM35_BIT4        equ       4                   ; Bit 4
PARAM35_BIT5        equ       5                   ; Bit 5
PARAM35_BIT6        equ       6                   ; Bit 6
PARAM35_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM35_BIT0       equ       %00000001
mPARAM35_BIT1       equ       %00000010
mPARAM35_BIT2       equ       %00000100
mPARAM35_BIT3       equ       %00001000
mPARAM35_BIT4       equ       %00010000
mPARAM35_BIT5       equ       %00100000
mPARAM35_BIT6       equ       %01000000
mPARAM35_BIT7       equ       %10000000

;*** PARAM36 - Parameter Register 36
PARAM36             equ       $00000074           ;*** PARAM36 - Parameter Register 36
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM36_BIT0        equ       0                   ; Bit 0
PARAM36_BIT1        equ       1                   ; Bit 1
PARAM36_BIT2        equ       2                   ; Bit 2
PARAM36_BIT3        equ       3                   ; Bit 3
PARAM36_BIT4        equ       4                   ; Bit 4
PARAM36_BIT5        equ       5                   ; Bit 5
PARAM36_BIT6        equ       6                   ; Bit 6
PARAM36_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM36_BIT0       equ       %00000001
mPARAM36_BIT1       equ       %00000010
mPARAM36_BIT2       equ       %00000100
mPARAM36_BIT3       equ       %00001000
mPARAM36_BIT4       equ       %00010000
mPARAM36_BIT5       equ       %00100000
mPARAM36_BIT6       equ       %01000000
mPARAM36_BIT7       equ       %10000000

;*** PARAM37 - Parameter Register 37
PARAM37             equ       $00000075           ;*** PARAM37 - Parameter Register 37
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM37_BIT0        equ       0                   ; Bit 0
PARAM37_BIT1        equ       1                   ; Bit 1
PARAM37_BIT2        equ       2                   ; Bit 2
PARAM37_BIT3        equ       3                   ; Bit 3
PARAM37_BIT4        equ       4                   ; Bit 4
PARAM37_BIT5        equ       5                   ; Bit 5
PARAM37_BIT6        equ       6                   ; Bit 6
PARAM37_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM37_BIT0       equ       %00000001
mPARAM37_BIT1       equ       %00000010
mPARAM37_BIT2       equ       %00000100
mPARAM37_BIT3       equ       %00001000
mPARAM37_BIT4       equ       %00010000
mPARAM37_BIT5       equ       %00100000
mPARAM37_BIT6       equ       %01000000
mPARAM37_BIT7       equ       %10000000

;*** PARAM38 - Parameter Register 38
PARAM38             equ       $00000076           ;*** PARAM38 - Parameter Register 38
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM38_BIT0        equ       0                   ; Bit 0
PARAM38_BIT1        equ       1                   ; Bit 1
PARAM38_BIT2        equ       2                   ; Bit 2
PARAM38_BIT3        equ       3                   ; Bit 3
PARAM38_BIT4        equ       4                   ; Bit 4
PARAM38_BIT5        equ       5                   ; Bit 5
PARAM38_BIT6        equ       6                   ; Bit 6
PARAM38_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM38_BIT0       equ       %00000001
mPARAM38_BIT1       equ       %00000010
mPARAM38_BIT2       equ       %00000100
mPARAM38_BIT3       equ       %00001000
mPARAM38_BIT4       equ       %00010000
mPARAM38_BIT5       equ       %00100000
mPARAM38_BIT6       equ       %01000000
mPARAM38_BIT7       equ       %10000000

;*** PARAM39 - Parameter Register 39
PARAM39             equ       $00000077           ;*** PARAM39 - Parameter Register 39
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM39_BIT0        equ       0                   ; Bit 0
PARAM39_BIT1        equ       1                   ; Bit 1
PARAM39_BIT2        equ       2                   ; Bit 2
PARAM39_BIT3        equ       3                   ; Bit 3
PARAM39_BIT4        equ       4                   ; Bit 4
PARAM39_BIT5        equ       5                   ; Bit 5
PARAM39_BIT6        equ       6                   ; Bit 6
PARAM39_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM39_BIT0       equ       %00000001
mPARAM39_BIT1       equ       %00000010
mPARAM39_BIT2       equ       %00000100
mPARAM39_BIT3       equ       %00001000
mPARAM39_BIT4       equ       %00010000
mPARAM39_BIT5       equ       %00100000
mPARAM39_BIT6       equ       %01000000
mPARAM39_BIT7       equ       %10000000

;*** PARAM40 - Parameter Register 40
PARAM40             equ       $00000078           ;*** PARAM40 - Parameter Register 40
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM40_BIT0        equ       0                   ; Bit 0
PARAM40_BIT1        equ       1                   ; Bit 1
PARAM40_BIT2        equ       2                   ; Bit 2
PARAM40_BIT3        equ       3                   ; Bit 3
PARAM40_BIT4        equ       4                   ; Bit 4
PARAM40_BIT5        equ       5                   ; Bit 5
PARAM40_BIT6        equ       6                   ; Bit 6
PARAM40_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM40_BIT0       equ       %00000001
mPARAM40_BIT1       equ       %00000010
mPARAM40_BIT2       equ       %00000100
mPARAM40_BIT3       equ       %00001000
mPARAM40_BIT4       equ       %00010000
mPARAM40_BIT5       equ       %00100000
mPARAM40_BIT6       equ       %01000000
mPARAM40_BIT7       equ       %10000000

;*** PARAM41 - Parameter Register 41
PARAM41             equ       $00000079           ;*** PARAM41 - Parameter Register 41
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM41_BIT0        equ       0                   ; Bit 0
PARAM41_BIT1        equ       1                   ; Bit 1
PARAM41_BIT2        equ       2                   ; Bit 2
PARAM41_BIT3        equ       3                   ; Bit 3
PARAM41_BIT4        equ       4                   ; Bit 4
PARAM41_BIT5        equ       5                   ; Bit 5
PARAM41_BIT6        equ       6                   ; Bit 6
PARAM41_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM41_BIT0       equ       %00000001
mPARAM41_BIT1       equ       %00000010
mPARAM41_BIT2       equ       %00000100
mPARAM41_BIT3       equ       %00001000
mPARAM41_BIT4       equ       %00010000
mPARAM41_BIT5       equ       %00100000
mPARAM41_BIT6       equ       %01000000
mPARAM41_BIT7       equ       %10000000

;*** PARAM42 - Parameter Register 42
PARAM42             equ       $0000007A           ;*** PARAM42 - Parameter Register 42
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM42_BIT0        equ       0                   ; Bit 0
PARAM42_BIT1        equ       1                   ; Bit 1
PARAM42_BIT2        equ       2                   ; Bit 2
PARAM42_BIT3        equ       3                   ; Bit 3
PARAM42_BIT4        equ       4                   ; Bit 4
PARAM42_BIT5        equ       5                   ; Bit 5
PARAM42_BIT6        equ       6                   ; Bit 6
PARAM42_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM42_BIT0       equ       %00000001
mPARAM42_BIT1       equ       %00000010
mPARAM42_BIT2       equ       %00000100
mPARAM42_BIT3       equ       %00001000
mPARAM42_BIT4       equ       %00010000
mPARAM42_BIT5       equ       %00100000
mPARAM42_BIT6       equ       %01000000
mPARAM42_BIT7       equ       %10000000

;*** PARAM43 - Parameter Register 43
PARAM43             equ       $0000007B           ;*** PARAM43 - Parameter Register 43
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM43_BIT0        equ       0                   ; Bit 0
PARAM43_BIT1        equ       1                   ; Bit 1
PARAM43_BIT2        equ       2                   ; Bit 2
PARAM43_BIT3        equ       3                   ; Bit 3
PARAM43_BIT4        equ       4                   ; Bit 4
PARAM43_BIT5        equ       5                   ; Bit 5
PARAM43_BIT6        equ       6                   ; Bit 6
PARAM43_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM43_BIT0       equ       %00000001
mPARAM43_BIT1       equ       %00000010
mPARAM43_BIT2       equ       %00000100
mPARAM43_BIT3       equ       %00001000
mPARAM43_BIT4       equ       %00010000
mPARAM43_BIT5       equ       %00100000
mPARAM43_BIT6       equ       %01000000
mPARAM43_BIT7       equ       %10000000

;*** PARAM44 - Parameter Register 44
PARAM44             equ       $0000007C           ;*** PARAM44 - Parameter Register 44
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM44_BIT0        equ       0                   ; Bit 0
PARAM44_BIT1        equ       1                   ; Bit 1
PARAM44_BIT2        equ       2                   ; Bit 2
PARAM44_BIT3        equ       3                   ; Bit 3
PARAM44_BIT4        equ       4                   ; Bit 4
PARAM44_BIT5        equ       5                   ; Bit 5
PARAM44_BIT6        equ       6                   ; Bit 6
PARAM44_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM44_BIT0       equ       %00000001
mPARAM44_BIT1       equ       %00000010
mPARAM44_BIT2       equ       %00000100
mPARAM44_BIT3       equ       %00001000
mPARAM44_BIT4       equ       %00010000
mPARAM44_BIT5       equ       %00100000
mPARAM44_BIT6       equ       %01000000
mPARAM44_BIT7       equ       %10000000

;*** PARAM45 - Parameter Register 45
PARAM45             equ       $0000007D           ;*** PARAM45 - Parameter Register 45
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM45_BIT0        equ       0                   ; Bit 0
PARAM45_BIT1        equ       1                   ; Bit 1
PARAM45_BIT2        equ       2                   ; Bit 2
PARAM45_BIT3        equ       3                   ; Bit 3
PARAM45_BIT4        equ       4                   ; Bit 4
PARAM45_BIT5        equ       5                   ; Bit 5
PARAM45_BIT6        equ       6                   ; Bit 6
PARAM45_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM45_BIT0       equ       %00000001
mPARAM45_BIT1       equ       %00000010
mPARAM45_BIT2       equ       %00000100
mPARAM45_BIT3       equ       %00001000
mPARAM45_BIT4       equ       %00010000
mPARAM45_BIT5       equ       %00100000
mPARAM45_BIT6       equ       %01000000
mPARAM45_BIT7       equ       %10000000

;*** PARAM46 - Parameter Register 46
PARAM46             equ       $0000007E           ;*** PARAM46 - Parameter Register 46
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM46_BIT0        equ       0                   ; Bit 0
PARAM46_BIT1        equ       1                   ; Bit 1
PARAM46_BIT2        equ       2                   ; Bit 2
PARAM46_BIT3        equ       3                   ; Bit 3
PARAM46_BIT4        equ       4                   ; Bit 4
PARAM46_BIT5        equ       5                   ; Bit 5
PARAM46_BIT6        equ       6                   ; Bit 6
PARAM46_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM46_BIT0       equ       %00000001
mPARAM46_BIT1       equ       %00000010
mPARAM46_BIT2       equ       %00000100
mPARAM46_BIT3       equ       %00001000
mPARAM46_BIT4       equ       %00010000
mPARAM46_BIT5       equ       %00100000
mPARAM46_BIT6       equ       %01000000
mPARAM46_BIT7       equ       %10000000

;*** PARAM47 - Parameter Register 47
PARAM47             equ       $0000007F           ;*** PARAM47 - Parameter Register 47
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM47_BIT0        equ       0                   ; Bit 0
PARAM47_BIT1        equ       1                   ; Bit 1
PARAM47_BIT2        equ       2                   ; Bit 2
PARAM47_BIT3        equ       3                   ; Bit 3
PARAM47_BIT4        equ       4                   ; Bit 4
PARAM47_BIT5        equ       5                   ; Bit 5
PARAM47_BIT6        equ       6                   ; Bit 6
PARAM47_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM47_BIT0       equ       %00000001
mPARAM47_BIT1       equ       %00000010
mPARAM47_BIT2       equ       %00000100
mPARAM47_BIT3       equ       %00001000
mPARAM47_BIT4       equ       %00010000
mPARAM47_BIT5       equ       %00100000
mPARAM47_BIT6       equ       %01000000
mPARAM47_BIT7       equ       %10000000

;*** PARAM48 - Parameter Register 48
PARAM48             equ       $00000080           ;*** PARAM48 - Parameter Register 48
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM48_BIT0        equ       0                   ; Bit 0
PARAM48_BIT1        equ       1                   ; Bit 1
PARAM48_BIT2        equ       2                   ; Bit 2
PARAM48_BIT3        equ       3                   ; Bit 3
PARAM48_BIT4        equ       4                   ; Bit 4
PARAM48_BIT5        equ       5                   ; Bit 5
PARAM48_BIT6        equ       6                   ; Bit 6
PARAM48_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM48_BIT0       equ       %00000001
mPARAM48_BIT1       equ       %00000010
mPARAM48_BIT2       equ       %00000100
mPARAM48_BIT3       equ       %00001000
mPARAM48_BIT4       equ       %00010000
mPARAM48_BIT5       equ       %00100000
mPARAM48_BIT6       equ       %01000000
mPARAM48_BIT7       equ       %10000000

;*** PARAM49 - Parameter Register 49
PARAM49             equ       $00000081           ;*** PARAM49 - Parameter Register 49
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM49_BIT0        equ       0                   ; Bit 0
PARAM49_BIT1        equ       1                   ; Bit 1
PARAM49_BIT2        equ       2                   ; Bit 2
PARAM49_BIT3        equ       3                   ; Bit 3
PARAM49_BIT4        equ       4                   ; Bit 4
PARAM49_BIT5        equ       5                   ; Bit 5
PARAM49_BIT6        equ       6                   ; Bit 6
PARAM49_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM49_BIT0       equ       %00000001
mPARAM49_BIT1       equ       %00000010
mPARAM49_BIT2       equ       %00000100
mPARAM49_BIT3       equ       %00001000
mPARAM49_BIT4       equ       %00010000
mPARAM49_BIT5       equ       %00100000
mPARAM49_BIT6       equ       %01000000
mPARAM49_BIT7       equ       %10000000

;*** PARAM50 - Parameter Register 50
PARAM50             equ       $00000082           ;*** PARAM50 - Parameter Register 50
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM50_BIT0        equ       0                   ; Bit 0
PARAM50_BIT1        equ       1                   ; Bit 1
PARAM50_BIT2        equ       2                   ; Bit 2
PARAM50_BIT3        equ       3                   ; Bit 3
PARAM50_BIT4        equ       4                   ; Bit 4
PARAM50_BIT5        equ       5                   ; Bit 5
PARAM50_BIT6        equ       6                   ; Bit 6
PARAM50_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM50_BIT0       equ       %00000001
mPARAM50_BIT1       equ       %00000010
mPARAM50_BIT2       equ       %00000100
mPARAM50_BIT3       equ       %00001000
mPARAM50_BIT4       equ       %00010000
mPARAM50_BIT5       equ       %00100000
mPARAM50_BIT6       equ       %01000000
mPARAM50_BIT7       equ       %10000000

;*** PARAM51 - Parameter Register 51
PARAM51             equ       $00000083           ;*** PARAM51 - Parameter Register 51
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM51_BIT0        equ       0                   ; Bit 0
PARAM51_BIT1        equ       1                   ; Bit 1
PARAM51_BIT2        equ       2                   ; Bit 2
PARAM51_BIT3        equ       3                   ; Bit 3
PARAM51_BIT4        equ       4                   ; Bit 4
PARAM51_BIT5        equ       5                   ; Bit 5
PARAM51_BIT6        equ       6                   ; Bit 6
PARAM51_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM51_BIT0       equ       %00000001
mPARAM51_BIT1       equ       %00000010
mPARAM51_BIT2       equ       %00000100
mPARAM51_BIT3       equ       %00001000
mPARAM51_BIT4       equ       %00010000
mPARAM51_BIT5       equ       %00100000
mPARAM51_BIT6       equ       %01000000
mPARAM51_BIT7       equ       %10000000

;*** PARAM52 - Parameter Register 52
PARAM52             equ       $00000084           ;*** PARAM52 - Parameter Register 52
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM52_BIT0        equ       0                   ; Bit 0
PARAM52_BIT1        equ       1                   ; Bit 1
PARAM52_BIT2        equ       2                   ; Bit 2
PARAM52_BIT3        equ       3                   ; Bit 3
PARAM52_BIT4        equ       4                   ; Bit 4
PARAM52_BIT5        equ       5                   ; Bit 5
PARAM52_BIT6        equ       6                   ; Bit 6
PARAM52_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM52_BIT0       equ       %00000001
mPARAM52_BIT1       equ       %00000010
mPARAM52_BIT2       equ       %00000100
mPARAM52_BIT3       equ       %00001000
mPARAM52_BIT4       equ       %00010000
mPARAM52_BIT5       equ       %00100000
mPARAM52_BIT6       equ       %01000000
mPARAM52_BIT7       equ       %10000000

;*** PARAM53 - Parameter Register 53
PARAM53             equ       $00000085           ;*** PARAM53 - Parameter Register 53
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM53_BIT0        equ       0                   ; Bit 0
PARAM53_BIT1        equ       1                   ; Bit 1
PARAM53_BIT2        equ       2                   ; Bit 2
PARAM53_BIT3        equ       3                   ; Bit 3
PARAM53_BIT4        equ       4                   ; Bit 4
PARAM53_BIT5        equ       5                   ; Bit 5
PARAM53_BIT6        equ       6                   ; Bit 6
PARAM53_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM53_BIT0       equ       %00000001
mPARAM53_BIT1       equ       %00000010
mPARAM53_BIT2       equ       %00000100
mPARAM53_BIT3       equ       %00001000
mPARAM53_BIT4       equ       %00010000
mPARAM53_BIT5       equ       %00100000
mPARAM53_BIT6       equ       %01000000
mPARAM53_BIT7       equ       %10000000

;*** PARAM54 - Parameter Register 54
PARAM54             equ       $00000086           ;*** PARAM54 - Parameter Register 54
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM54_BIT0        equ       0                   ; Bit 0
PARAM54_BIT1        equ       1                   ; Bit 1
PARAM54_BIT2        equ       2                   ; Bit 2
PARAM54_BIT3        equ       3                   ; Bit 3
PARAM54_BIT4        equ       4                   ; Bit 4
PARAM54_BIT5        equ       5                   ; Bit 5
PARAM54_BIT6        equ       6                   ; Bit 6
PARAM54_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM54_BIT0       equ       %00000001
mPARAM54_BIT1       equ       %00000010
mPARAM54_BIT2       equ       %00000100
mPARAM54_BIT3       equ       %00001000
mPARAM54_BIT4       equ       %00010000
mPARAM54_BIT5       equ       %00100000
mPARAM54_BIT6       equ       %01000000
mPARAM54_BIT7       equ       %10000000

;*** PARAM55 - Parameter Register 55
PARAM55             equ       $00000087           ;*** PARAM55 - Parameter Register 55
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM55_BIT0        equ       0                   ; Bit 0
PARAM55_BIT1        equ       1                   ; Bit 1
PARAM55_BIT2        equ       2                   ; Bit 2
PARAM55_BIT3        equ       3                   ; Bit 3
PARAM55_BIT4        equ       4                   ; Bit 4
PARAM55_BIT5        equ       5                   ; Bit 5
PARAM55_BIT6        equ       6                   ; Bit 6
PARAM55_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM55_BIT0       equ       %00000001
mPARAM55_BIT1       equ       %00000010
mPARAM55_BIT2       equ       %00000100
mPARAM55_BIT3       equ       %00001000
mPARAM55_BIT4       equ       %00010000
mPARAM55_BIT5       equ       %00100000
mPARAM55_BIT6       equ       %01000000
mPARAM55_BIT7       equ       %10000000

;*** PARAM56 - Parameter Register 56
PARAM56             equ       $00000088           ;*** PARAM56 - Parameter Register 56
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM56_BIT0        equ       0                   ; Bit 0
PARAM56_BIT1        equ       1                   ; Bit 1
PARAM56_BIT2        equ       2                   ; Bit 2
PARAM56_BIT3        equ       3                   ; Bit 3
PARAM56_BIT4        equ       4                   ; Bit 4
PARAM56_BIT5        equ       5                   ; Bit 5
PARAM56_BIT6        equ       6                   ; Bit 6
PARAM56_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM56_BIT0       equ       %00000001
mPARAM56_BIT1       equ       %00000010
mPARAM56_BIT2       equ       %00000100
mPARAM56_BIT3       equ       %00001000
mPARAM56_BIT4       equ       %00010000
mPARAM56_BIT5       equ       %00100000
mPARAM56_BIT6       equ       %01000000
mPARAM56_BIT7       equ       %10000000

;*** PARAM57 - Parameter Register 57
PARAM57             equ       $00000089           ;*** PARAM57 - Parameter Register 57
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM57_BIT0        equ       0                   ; Bit 0
PARAM57_BIT1        equ       1                   ; Bit 1
PARAM57_BIT2        equ       2                   ; Bit 2
PARAM57_BIT3        equ       3                   ; Bit 3
PARAM57_BIT4        equ       4                   ; Bit 4
PARAM57_BIT5        equ       5                   ; Bit 5
PARAM57_BIT6        equ       6                   ; Bit 6
PARAM57_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM57_BIT0       equ       %00000001
mPARAM57_BIT1       equ       %00000010
mPARAM57_BIT2       equ       %00000100
mPARAM57_BIT3       equ       %00001000
mPARAM57_BIT4       equ       %00010000
mPARAM57_BIT5       equ       %00100000
mPARAM57_BIT6       equ       %01000000
mPARAM57_BIT7       equ       %10000000

;*** PARAM58 - Parameter Register 58
PARAM58             equ       $0000008A           ;*** PARAM58 - Parameter Register 58
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM58_BIT0        equ       0                   ; Bit 0
PARAM58_BIT1        equ       1                   ; Bit 1
PARAM58_BIT2        equ       2                   ; Bit 2
PARAM58_BIT3        equ       3                   ; Bit 3
PARAM58_BIT4        equ       4                   ; Bit 4
PARAM58_BIT5        equ       5                   ; Bit 5
PARAM58_BIT6        equ       6                   ; Bit 6
PARAM58_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM58_BIT0       equ       %00000001
mPARAM58_BIT1       equ       %00000010
mPARAM58_BIT2       equ       %00000100
mPARAM58_BIT3       equ       %00001000
mPARAM58_BIT4       equ       %00010000
mPARAM58_BIT5       equ       %00100000
mPARAM58_BIT6       equ       %01000000
mPARAM58_BIT7       equ       %10000000

;*** PARAM59 - Parameter Register 59
PARAM59             equ       $0000008B           ;*** PARAM59 - Parameter Register 59
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM59_BIT0        equ       0                   ; Bit 0
PARAM59_BIT1        equ       1                   ; Bit 1
PARAM59_BIT2        equ       2                   ; Bit 2
PARAM59_BIT3        equ       3                   ; Bit 3
PARAM59_BIT4        equ       4                   ; Bit 4
PARAM59_BIT5        equ       5                   ; Bit 5
PARAM59_BIT6        equ       6                   ; Bit 6
PARAM59_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM59_BIT0       equ       %00000001
mPARAM59_BIT1       equ       %00000010
mPARAM59_BIT2       equ       %00000100
mPARAM59_BIT3       equ       %00001000
mPARAM59_BIT4       equ       %00010000
mPARAM59_BIT5       equ       %00100000
mPARAM59_BIT6       equ       %01000000
mPARAM59_BIT7       equ       %10000000

;*** PARAM60 - Parameter Register 60
PARAM60             equ       $0000008C           ;*** PARAM60 - Parameter Register 60
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM60_BIT0        equ       0                   ; Bit 0
PARAM60_BIT1        equ       1                   ; Bit 1
PARAM60_BIT2        equ       2                   ; Bit 2
PARAM60_BIT3        equ       3                   ; Bit 3
PARAM60_BIT4        equ       4                   ; Bit 4
PARAM60_BIT5        equ       5                   ; Bit 5
PARAM60_BIT6        equ       6                   ; Bit 6
PARAM60_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM60_BIT0       equ       %00000001
mPARAM60_BIT1       equ       %00000010
mPARAM60_BIT2       equ       %00000100
mPARAM60_BIT3       equ       %00001000
mPARAM60_BIT4       equ       %00010000
mPARAM60_BIT5       equ       %00100000
mPARAM60_BIT6       equ       %01000000
mPARAM60_BIT7       equ       %10000000

;*** PARAM61 - Parameter Register 61
PARAM61             equ       $0000008D           ;*** PARAM61 - Parameter Register 61
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM61_BIT0        equ       0                   ; Bit 0
PARAM61_BIT1        equ       1                   ; Bit 1
PARAM61_BIT2        equ       2                   ; Bit 2
PARAM61_BIT3        equ       3                   ; Bit 3
PARAM61_BIT4        equ       4                   ; Bit 4
PARAM61_BIT5        equ       5                   ; Bit 5
PARAM61_BIT6        equ       6                   ; Bit 6
PARAM61_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM61_BIT0       equ       %00000001
mPARAM61_BIT1       equ       %00000010
mPARAM61_BIT2       equ       %00000100
mPARAM61_BIT3       equ       %00001000
mPARAM61_BIT4       equ       %00010000
mPARAM61_BIT5       equ       %00100000
mPARAM61_BIT6       equ       %01000000
mPARAM61_BIT7       equ       %10000000

;*** PARAM62 - Parameter Register 62
PARAM62             equ       $0000008E           ;*** PARAM62 - Parameter Register 62
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM62_BIT0        equ       0                   ; Bit 0
PARAM62_BIT1        equ       1                   ; Bit 1
PARAM62_BIT2        equ       2                   ; Bit 2
PARAM62_BIT3        equ       3                   ; Bit 3
PARAM62_BIT4        equ       4                   ; Bit 4
PARAM62_BIT5        equ       5                   ; Bit 5
PARAM62_BIT6        equ       6                   ; Bit 6
PARAM62_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM62_BIT0       equ       %00000001
mPARAM62_BIT1       equ       %00000010
mPARAM62_BIT2       equ       %00000100
mPARAM62_BIT3       equ       %00001000
mPARAM62_BIT4       equ       %00010000
mPARAM62_BIT5       equ       %00100000
mPARAM62_BIT6       equ       %01000000
mPARAM62_BIT7       equ       %10000000

;*** PARAM63 - Parameter Register 63
PARAM63             equ       $0000008F           ;*** PARAM63 - Parameter Register 63
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PARAM63_BIT0        equ       0                   ; Bit 0
PARAM63_BIT1        equ       1                   ; Bit 1
PARAM63_BIT2        equ       2                   ; Bit 2
PARAM63_BIT3        equ       3                   ; Bit 3
PARAM63_BIT4        equ       4                   ; Bit 4
PARAM63_BIT5        equ       5                   ; Bit 5
PARAM63_BIT6        equ       6                   ; Bit 6
PARAM63_BIT7        equ       7                   ; Bit 7
; bit position masks
mPARAM63_BIT0       equ       %00000001
mPARAM63_BIT1       equ       %00000010
mPARAM63_BIT2       equ       %00000100
mPARAM63_BIT3       equ       %00001000
mPARAM63_BIT4       equ       %00010000
mPARAM63_BIT5       equ       %00100000
mPARAM63_BIT6       equ       %01000000
mPARAM63_BIT7       equ       %10000000

;*** SRS - System Reset Status Register
SRS                 equ       $00001800           ;*** SRS - System Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD             equ       1                   ; Low Voltage Detect
SRS_PWU             equ       2                   ; Programmable Wakeup
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

;*** SIMOPT1 - System Options Register 1
SIMOPT1             equ       $00001802           ;*** SIMOPT1 - System Options Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMOPT1_BKGDPE      equ       1                   ; Background Debug Mode Pin Enable
SIMOPT1_TRH         equ       2                   ; Temperature Restart Level
SIMOPT1_TRE         equ       3                   ; Temperature Restart Wakeup Enable
SIMOPT1_RFEN        equ       4                   ; RF Module Enable
SIMOPT1_STOPE       equ       5                   ; Stop Mode Enable
SIMOPT1_COPCLKS     equ       6                   ; COP Clock Selection
SIMOPT1_COPE        equ       7                   ; COP Watchdog Enable
; bit position masks
mSIMOPT1_BKGDPE     equ       %00000010
mSIMOPT1_TRH        equ       %00000100
mSIMOPT1_TRE        equ       %00001000
mSIMOPT1_RFEN       equ       %00010000
mSIMOPT1_STOPE      equ       %00100000
mSIMOPT1_COPCLKS    equ       %01000000
mSIMOPT1_COPE       equ       %10000000

;*** SIMOPT2 - System Options Register 2
SIMOPT2             equ       $00001803           ;*** SIMOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMOPT2_BUSCLKS0    equ       0                   ; Bus Clock Select - HFO divide by, bit 0
SIMOPT2_BUSCLKS1    equ       1                   ; Bus Clock Select - HFO divide by, bit 1
SIMOPT2_TCLKDIV     equ       2                   ; Timer Clock Divider
SIMOPT2_LFOSEL      equ       3                   ; LFO Selected
SIMOPT2_COPT0       equ       4                   ; COP Watchdog Timeout, bit 0
SIMOPT2_COPT1       equ       5                   ; COP Watchdog Timeout, bit 1
SIMOPT2_COPT2       equ       6                   ; COP Watchdog Timeout, bit 2
; bit position masks
mSIMOPT2_BUSCLKS0   equ       %00000001
mSIMOPT2_BUSCLKS1   equ       %00000010
mSIMOPT2_TCLKDIV    equ       %00000100
mSIMOPT2_LFOSEL     equ       %00001000
mSIMOPT2_COPT0      equ       %00010000
mSIMOPT2_COPT1      equ       %00100000
mSIMOPT2_COPT2      equ       %01000000

;*** SDID - System Device Identification Register
SDID                equ       $00001806           ;*** SDID - System Device Identification Register

;*** SDIDH - System Device Identification Register High
SDIDH               equ       $00001806           ;*** SDIDH - System Device Identification Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8           equ       0                   ; Part Identification Number, bit 8
SDIDH_ID9           equ       1                   ; Part Identification Number, bit 9
SDIDH_ID10          equ       2                   ; Part Identification Number, bit 10
SDIDH_ID11          equ       3                   ; Part Identification Number, bit 11
SDIDH_REV0          equ       4                   ; Revision Number, bit 0
SDIDH_REV1          equ       5                   ; Revision Number, bit 1
SDIDH_REV2          equ       6                   ; Revision Number, bit 2
SDIDH_REV3          equ       7                   ; Revision Number, bit 3
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

;*** SRTISC - System Real-Time Interrupt Status and Control Register
SRTISC              equ       $00001808           ;*** SRTISC - System Real-Time Interrupt Status and Control Register
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
SPMSC1              equ       $00001809           ;*** SPMSC1 - System Power Management Status and Control 1 Register
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
SPMSC2              equ       $0000180A           ;*** SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PDC          equ       1                   ; Power Down Control
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowledge
SPMSC2_PDF          equ       4                   ; Power Down Flag
; bit position masks
mSPMSC2_PDC         equ       %00000010
mSPMSC2_PPDACK      equ       %00000100
mSPMSC2_PDF         equ       %00010000

;*** SPMSC3 - System Power Management Status and Control 3 Register
SPMSC3              equ       $0000180C           ;*** SPMSC3 - System Power Management Status and Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC3_HVWE         equ       0
SPMSC3_HVWIE        equ       1
SPMSC3_HVWACK       equ       2
SPMSC3_HVWF         equ       3
SPMSC3_LVWV         equ       4                   ; Low-Voltage Warning Voltage Select
SPMSC3_LVDV         equ       5                   ; Low-Voltage Detect Voltage Select
SPMSC3_LVWACK       equ       6                   ; Low-Voltage Warning Acknowledge
SPMSC3_LVWF         equ       7                   ; Low-Voltage Warning Flag
; bit position masks
mSPMSC3_HVWE        equ       %00000001
mSPMSC3_HVWIE       equ       %00000010
mSPMSC3_HVWACK      equ       %00000100
mSPMSC3_HVWF        equ       %00001000
mSPMSC3_LVWV        equ       %00010000
mSPMSC3_LVDV        equ       %00100000
mSPMSC3_LVWACK      equ       %01000000
mSPMSC3_LVWF        equ       %10000000

;*** SIMSES - SIM Stop Exit Status
SIMSES              equ       $0000180D           ;*** SIMSES - SIM Stop Exit Status
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMSES_RFF          equ       0                   ; RFM Flag
SIMSES_LFF          equ       1                   ; LFR Flag
SIMSES_PWUF         equ       2                   ; PWU Flag
SIMSES_TRF          equ       3                   ; Temperature Restart Flag
SIMSES_IRQF         equ       4                   ; IRQ Flag
SIMSES_KBF          equ       5                   ; Keyboard Flag
; bit position masks
mSIMSES_RFF         equ       %00000001
mSIMSES_LFF         equ       %00000010
mSIMSES_PWUF        equ       %00000100
mSIMSES_TRF         equ       %00001000
mSIMSES_IRQF        equ       %00010000
mSIMSES_KBF         equ       %00100000

;*** SOTRM - System Oscillator Trim Register
SOTRM               equ       $0000180E           ;*** SOTRM - System Oscillator Trim Register

;*** SIMTST - SIM Test Register
SIMTST              equ       $0000180F           ;*** SIMTST - SIM Test Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMTST_TRO          equ       0                   ; Temperature Restart
; bit position masks
mSIMTST_TRO         equ       %00000001

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
