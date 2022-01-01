;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9RS08KA2_8, version 3.00.021 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9rs08ka2.inc
;     Processor : MC9RS08KA2CPC
;     FileFormat: V2.32
;     DataSheet : MC9RS08KA2 Rev. 3 9/2007
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 14:52
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
;      - 01.03.2007, V2.13 :
;               - Flash commands constants values converted to HEX format
;      - 02.03.2007, V2.14 :
;               - Changes have not affected this file (because they are related to another family)
;      - 26.03.2007, V2.15 :
;               - RS08 header files: Pragma C110 added; REG_BASE removed
;      - 10.05.2007, V2.16 :
;               - Changes have not affected this file (because they are related to another family)
;      - 05.06.2007, V2.17 :
;               - Fixed pointer to non-volatile registers for RS08 C compiler
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
XRAM                equ       $00000020
XRAM_END            equ       $0000004F
ROM                 equ       $00003800
ROM_END             equ       $00003FF7
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
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD1         equ       %00000010
mPTAD_PTAD2         equ       %00000100
mPTAD_PTAD3         equ       %00001000
mPTAD_PTAD4         equ       %00010000
mPTAD_PTAD5         equ       %00100000

;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000011           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; PTADD
PTADD_PTADD1        equ       1                   ; PTADD
PTADD_PTADD4        equ       4                   ; PTADD
PTADD_PTADD5        equ       5                   ; PTADD
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD4       equ       %00010000
mPTADD_PTADD5       equ       %00100000

;*** ACMPSC - ACMP Status and Control Register
ACMPSC              equ       $00000013           ;*** ACMPSC - ACMP Status and Control Register
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

;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $00000014           ;*** ICSC1 - ICS Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN      equ       0                   ; Internal Reference Stop Enable
ICSC1_CLKS          equ       6                   ; Clock Source Select
; bit position masks
mICSC1_IREFSTEN     equ       %00000001
mICSC1_CLKS         equ       %01000000

;*** ICSC2 - ICS Control Register 2
ICSC2               equ       $00000015           ;*** ICSC2 - ICS Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_LP            equ       3                   ; Low Power Select
ICSC2_BDIV          equ       6                   ; Bus Frequency Divider
; bit position masks
mICSC2_LP           equ       %00001000
mICSC2_BDIV         equ       %11000000

;*** ICSTRM - ICS Trim Register
ICSTRM              equ       $00000016           ;*** ICSTRM - ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM         equ       0                   ; ICS Trim Setting
; bit position masks
mICSTRM_TRIM        equ       %11111111

;*** ICSSC - ICS Status and Control Register
ICSSC               equ       $00000017           ;*** ICSSC - ICS Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM         equ       0                   ; ICS Fine Trim
ICSSC_CLKST         equ       2                   ; Clock Mode Status
; bit position masks
mICSSC_FTRIM        equ       %00000001
mICSSC_CLKST        equ       %00000100

;*** MTIMSC - MTIM Clock Configuration Register
MTIMSC              equ       $00000018           ;*** MTIMSC - MTIM Clock Configuration Register
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
MTIMCLK             equ       $00000019           ;*** MTIMCLK - MTIM Clock Configuration Register
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
MTIMCNT             equ       $0000001A           ;*** MTIMCNT - MTIM Counter Register

;*** MTIMMOD - MTIM Modulo Register
MTIMMOD             equ       $0000001B           ;*** MTIMMOD - MTIM Modulo Register

;*** KBISC - KBI Status and Control Register
KBISC               equ       $0000001C           ;*** KBISC - KBI Status and Control Register
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
KBIPE               equ       $0000001D           ;*** KBIPE - KBI Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPE_KBIPE0        equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBIPE_KBIPE1        equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBIPE_KBIPE2        equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBIPE_KBIPE4        equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBIPE_KBIPE5        equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
; bit position masks
mKBIPE_KBIPE0       equ       %00000001
mKBIPE_KBIPE1       equ       %00000010
mKBIPE_KBIPE2       equ       %00000100
mKBIPE_KBIPE4       equ       %00010000
mKBIPE_KBIPE5       equ       %00100000

;*** KBIES - KBI Edge Select Register
KBIES               equ       $0000001E           ;*** KBIES - KBI Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIES_KBEDG0        equ       0                   ; Keyboard Edge Select Bit 0
KBIES_KBEDG1        equ       1                   ; Keyboard Edge Select Bit 1
KBIES_KBEDG2        equ       2                   ; Keyboard Edge Select Bit 2
KBIES_KBEDG4        equ       4                   ; Keyboard Edge Select Bit 4
KBIES_KBEDG5        equ       5                   ; Keyboard Edge Select Bit 5
; bit position masks
mKBIES_KBEDG0       equ       %00000001
mKBIES_KBEDG1       equ       %00000010
mKBIES_KBEDG2       equ       %00000100
mKBIES_KBEDG4       equ       %00010000
mKBIES_KBEDG5       equ       %00100000

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
SIP1_LVD            equ       0                   ; Low-VoltageDetectInterruptPending
SIP1_RTI            equ       1                   ; Real-TimeInterruptPending
SIP1_MTIM           equ       2                   ; Modulo Timer Interrupt Pending
SIP1_ACMP           equ       3                   ; Analog Comparator Interrupt Pending
SIP1_KBI            equ       4                   ; Keyboard Interrupt Pending
; bit position masks
mSIP1_LVD           equ       %00000001
mSIP1_RTI           equ       %00000010
mSIP1_MTIM          equ       %00000100
mSIP1_ACMP          equ       %00001000
mSIP1_KBI           equ       %00010000

;*** SDID - System Device Identification Register
SDID                equ       $00000206           ;*** SDID - System Device Identification Register

;*** SDIDH - System Device Identification Register High
SDIDH               equ       $00000206           ;*** SDIDH - System Device Identification Register High
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

;*** PTAPE - Port A Internal Pulling Device Enable Register
PTAPE               equ       $00000220           ;*** PTAPE - Port A Internal Pulling Device Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pulling Device Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pulling Device Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pulling Device Enable for Port A Bit 2
PTAPE_PTAPE4        equ       4                   ; Internal Pulling Device Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Internal Pulling Device Enable for Port A Bit 5
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000

;*** PTAPUD - Port A Pullup/Pulldown Control Register
PTAPUD              equ       $00000221           ;*** PTAPUD - Port A Pullup/Pulldown Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUD_PTAPUD0      equ       0                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD1      equ       1                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD2      equ       2                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD4      equ       4                   ; Pullup/Pulldown Device Control for Port A Bit 0
PTAPUD_PTAPUD5      equ       5                   ; Pullup/Pulldown Device Control for Port A Bit 0
; bit position masks
mPTAPUD_PTAPUD0     equ       %00000001
mPTAPUD_PTAPUD1     equ       %00000010
mPTAPUD_PTAPUD2     equ       %00000100
mPTAPUD_PTAPUD4     equ       %00010000
mPTAPUD_PTAPUD5     equ       %00100000

;*** PTASE - Port A Output Slew Rate Control Enable Register
PTASE               equ       $00000222           ;*** PTASE - Port A Output Slew Rate Control Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE3        equ       3                   ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE5        equ       5                   ; Output Slew Rate Enable for Port A Bit 5
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000
mPTASE_PTASE5       equ       %00100000

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

;
; Follows changes from the database 2.87.051 version
KBISC_KBMOD         equ       KBISC_KBIMOD
mKBISC_KBMOD        equ       mKBISC_KBIMOD

; **** 14.06.2007 15:54:08

       #ifndef __GENERATE_APPLICATION__
       #endif
NV_ICSTRM           equ       NVICSTRM
NV_ICSTRM_TRIM      equ       NVICSTRM_TRIM
mNV_ICSTRM_TRIM     equ       mNVICSTRM_TRIM
NV_FTRIM            equ       NVFTRIM
NV_FTRIM_FTRIM      equ       NVFTRIM_FTRIM
mNV_FTRIM_FTRIM     equ       mNVFTRIM_FTRIM

; EOF
