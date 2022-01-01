;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08JS16_24, version 3.00.019 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08js8l.inc
;     Processor : MC9S08JS8LCFK
;     FileFormat: V2.32
;     DataSheet : MC9S08JS16RM Rev. 4 4/2009
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
;      - 22.08.2008, V3.00.0:
;              - Removed register SOPT3. Added Checksum Bypass at 0xFFBA.
;              -   REASON: Changes in Reference Manual(from Rev. 0 Draft D 12/2007 to Rev. 0 Draft F 4/2008).
;      - 13.11.2008, V3.00.1:
;              - Removed vectors VReserved30(0xFFC2),VReserved31(0xFFC0).
;              -   REASON: Changes in Reference Manual (#6793 in Issue Manager).
;      - 16.04.2009, V3.00.2:
;              - Address of NVFTRIM, NVMCGTRM changed to 0xFFAE,0xFFAF
;              -   REASON: Changes in Reference Manual (from Rev 1, 8/2008 to Rev 3, 3/2009).
;      - 6.08.2009, V3.00.3:
;              - Bits SIGNATURE0-SIGNATURE7 merged to SIGNATURE[0:7] group.
;              -   REASON: Access to individual bits is useless (#7539 in Issue Manager).
;
;     File-Format-Revisions:
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
ROM                 equ       $0000E400
ROM_END             equ       $0000FFAD
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000027F
RAM1                equ       $00001860
RAM1_END            equ       $0000195F
XROM                equ       $0000FFC0
XROM_END            equ       $0000FFC3
ROM2Start           equ       $0000E000
ROM2End             equ       $0000E3FF
;
Vrtc                equ       $0000FFC4
VReserved28         equ       $0000FFC6
VReserved27         equ       $0000FFC8
Vmtim               equ       $0000FFCA
Vkeyboard           equ       $0000FFCC
VReserved24         equ       $0000FFCE
VReserved23         equ       $0000FFD0
VReserved22         equ       $0000FFD2
Vscitx              equ       $0000FFD4
Vscirx              equ       $0000FFD6
Vscierr             equ       $0000FFD8
VReserved18         equ       $0000FFDA
VReserved17         equ       $0000FFDC
VReserved16         equ       $0000FFDE
VReserved15         equ       $0000FFE0
VReserved14         equ       $0000FFE2
VReserved13         equ       $0000FFE4
VReserved12         equ       $0000FFE6
Vtpmovf             equ       $0000FFE8
Vtpmch1             equ       $0000FFEA
Vtpmch0             equ       $0000FFEC
VReserved8          equ       $0000FFEE
Vusb                equ       $0000FFF0
VReserved6          equ       $0000FFF2
Vspi                equ       $0000FFF4
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
PTBDD_PTBDD4        equ       4                   ; Data Direction for Port B Bit 4
PTBDD_PTBDD5        equ       5                   ; Data Direction for Port B Bit 5
; bit position masks
mPTBDD_PTBDD0       equ       %00000001
mPTBDD_PTBDD1       equ       %00000010
mPTBDD_PTBDD4       equ       %00010000
mPTBDD_PTBDD5       equ       %00100000

;*** MTIMSC - MTIM Clock Configuration Register
MTIMSC              equ       $00000008           ;*** MTIMSC - MTIM Clock Configuration Register
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
MTIMCLK             equ       $00000009           ;*** MTIMCLK - MTIM Clock Configuration Register
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
MTIMCNT             equ       $0000000A           ;*** MTIMCNT - MTIM Counter Register

;*** MTIMMOD - MTIM Modulo Register
MTIMMOD             equ       $0000000B           ;*** MTIMMOD - MTIM Modulo Register

;*** CRCH - CRC High Register
CRCH                equ       $0000000C           ;*** CRCH - CRC High Register
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
CRCL                equ       $0000000D           ;*** CRCL - CRC Low Register
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

;*** TPMSC - TPM Status and Control Register
TPMSC               equ       $00000010           ;*** TPMSC - TPM Status and Control Register
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
TPMCNT              equ       $00000011           ;*** TPMCNT - TPM Timer Counter Register

;*** TPMCNTH - TPM Timer Counter Register High
TPMCNTH             equ       $00000011           ;*** TPMCNTH - TPM Timer Counter Register High

;*** TPMCNTL - TPM Timer Counter Register Low
TPMCNTL             equ       $00000012           ;*** TPMCNTL - TPM Timer Counter Register Low

;*** TPMMOD - TPM Timer Counter Modulo Register
TPMMOD              equ       $00000013           ;*** TPMMOD - TPM Timer Counter Modulo Register

;*** TPMMODH - TPM Timer Counter Modulo Register High
TPMMODH             equ       $00000013           ;*** TPMMODH - TPM Timer Counter Modulo Register High

;*** TPMMODL - TPM Timer Counter Modulo Register Low
TPMMODL             equ       $00000014           ;*** TPMMODL - TPM Timer Counter Modulo Register Low

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

;*** SPIC1 - SPI Control Register 1
SPIC1               equ       $00000030           ;*** SPIC1 - SPI Control Register 1
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
SPIC2               equ       $00000031           ;*** SPIC2 - SPI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC2_SPC0          equ       0                   ; SPI Pin Control 0
SPIC2_SPISWAI       equ       1                   ; SPI Stop in Wait Mode
SPIC2_BIDIROE       equ       3                   ; Bidirectional Mode Output Enable
SPIC2_MODFEN        equ       4                   ; Master Mode-Fault Function Enable
SPIC2_SPIMODE       equ       6                   ; SPI 8- or 16-bit Mode Select
SPIC2_SPMIE         equ       7                   ; SPI Match Interrupt Enable
; bit position masks
mSPIC2_SPC0         equ       %00000001
mSPIC2_SPISWAI      equ       %00000010
mSPIC2_BIDIROE      equ       %00001000
mSPIC2_MODFEN       equ       %00010000
mSPIC2_SPIMODE      equ       %01000000
mSPIC2_SPMIE        equ       %10000000

;*** SPIBR - SPI Baud Rate Register
SPIBR               equ       $00000032           ;*** SPIBR - SPI Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIBR_SPR0          equ       0                   ; SPI Baud Rate Divisor Bit 0
SPIBR_SPR1          equ       1                   ; SPI Baud Rate Divisor Bit 1
SPIBR_SPR2          equ       2                   ; SPI Baud Rate Divisor Bit 2
SPIBR_SPPR0         equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPIBR_SPPR1         equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPIBR_SPPR2         equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPIBR_SPR0         equ       %00000001
mSPIBR_SPR1         equ       %00000010
mSPIBR_SPR2         equ       %00000100
mSPIBR_SPPR0        equ       %00010000
mSPIBR_SPPR1        equ       %00100000
mSPIBR_SPPR2        equ       %01000000

;*** SPIS - SPI Status Register
SPIS                equ       $00000033           ;*** SPIS - SPI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIS_MODF           equ       4                   ; Master Mode Fault Flag
SPIS_SPTEF          equ       5                   ; SPI Transmit Buffer Empty Flag
SPIS_SPMF           equ       6                   ; SPI Match Flag
SPIS_SPRF           equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPIS_MODF          equ       %00010000
mSPIS_SPTEF         equ       %00100000
mSPIS_SPMF          equ       %01000000
mSPIS_SPRF          equ       %10000000

;*** SPID16 - SPI Data Register
SPID16              equ       $00000034           ;*** SPID16 - SPI Data Register

;*** SPIDH - SPI Data Register High
SPIDH               equ       $00000034           ;*** SPIDH - SPI Data Register High

;*** SPIDL - SPI Data Register Low
SPIDL               equ       $00000035           ;*** SPIDL - SPI Data Register Low

;*** SPID - SPI Data Register Low
SPID                equ       $00000035           ;*** SPID - SPI Data Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPID_Bit0           equ       0                   ; SPI Data Bit 0
SPID_Bit1           equ       1                   ; SPI Data Bit 1
SPID_Bit2           equ       2                   ; SPI Data Bit 2
SPID_Bit3           equ       3                   ; SPI Data Bit 3
SPID_Bit4           equ       4                   ; SPI Data Bit 4
SPID_Bit5           equ       5                   ; SPI Data Bit 5
SPID_Bit6           equ       6                   ; SPI Data Bit 6
SPID_Bit7           equ       7                   ; SPI Data Bit 7
; bit position masks
mSPID_Bit0          equ       %00000001
mSPID_Bit1          equ       %00000010
mSPID_Bit2          equ       %00000100
mSPID_Bit3          equ       %00001000
mSPID_Bit4          equ       %00010000
mSPID_Bit5          equ       %00100000
mSPID_Bit6          equ       %01000000
mSPID_Bit7          equ       %10000000

;*** SPIM - SPI Match Register
SPIM                equ       $00000036           ;*** SPIM - SPI Match Register

;*** SPIMH - SPI Match Register High
SPIMH               equ       $00000036           ;*** SPIMH - SPI Match Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIMH_Bit8          equ       0                   ; SPI Match Value Bit 8
SPIMH_Bit9          equ       1                   ; SPI Match Value Bit 9
SPIMH_Bit10         equ       2                   ; SPI Match Value Bit 10
SPIMH_Bit11         equ       3                   ; SPI Match Value Bit 11
SPIMH_Bit12         equ       4                   ; SPI Match Value Bit 12
SPIMH_Bit13         equ       5                   ; SPI Match Value Bit 13
SPIMH_Bit14         equ       6                   ; SPI Match Value Bit 14
SPIMH_Bit15         equ       7                   ; SPI Match Value Bit 15
; bit position masks
mSPIMH_Bit8         equ       %00000001
mSPIMH_Bit9         equ       %00000010
mSPIMH_Bit10        equ       %00000100
mSPIMH_Bit11        equ       %00001000
mSPIMH_Bit12        equ       %00010000
mSPIMH_Bit13        equ       %00100000
mSPIMH_Bit14        equ       %01000000
mSPIMH_Bit15        equ       %10000000

;*** SPIML - SPI Match Register Low
SPIML               equ       $00000037           ;*** SPIML - SPI Match Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIML_Bit0          equ       0                   ; SPI Match Value Bit 0
SPIML_Bit1          equ       1                   ; SPI Match Value Bit 1
SPIML_Bit2          equ       2                   ; SPI Match Value Bit 2
SPIML_Bit3          equ       3                   ; SPI Match Value Bit 3
SPIML_Bit4          equ       4                   ; SPI Match Value Bit 4
SPIML_Bit5          equ       5                   ; SPI Match Value Bit 5
SPIML_Bit6          equ       6                   ; SPI Match Value Bit 6
SPIML_Bit7          equ       7                   ; SPI Match Value Bit 7
; bit position masks
mSPIML_Bit0         equ       %00000001
mSPIML_Bit1         equ       %00000010
mSPIML_Bit2         equ       %00000100
mSPIML_Bit3         equ       %00001000
mSPIML_Bit4         equ       %00010000
mSPIML_Bit5         equ       %00100000
mSPIML_Bit6         equ       %01000000
mSPIML_Bit7         equ       %10000000

;*** MCGC1 - MCG Control Register 1
MCGC1               equ       $00000040           ;*** MCGC1 - MCG Control Register 1
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
MCGC2               equ       $00000041           ;*** MCGC2 - MCG Control Register 2
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
MCGTRM              equ       $00000042           ;*** MCGTRM - MCG Trim Register
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
MCGSC               equ       $00000043           ;*** MCGSC - MCG Status and Control Register
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
MCGC3               equ       $00000044           ;*** MCGC3 - MCG Control Register 3
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

;*** RTCSC - RTC Status and Control Register
RTCSC               equ       $00000048           ;*** RTCSC - RTC Status and Control Register
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
RTCCNT              equ       $00000049           ;*** RTCCNT - RTC Counter Register

;*** RTCMOD - RTC Modulo Register
RTCMOD              equ       $0000004A           ;*** RTCMOD - RTC Modulo Register

;*** USBCTL0 - USB Control Register 0
USBCTL0             equ       $00000050           ;*** USBCTL0 - USB Control Register 0
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
PERID               equ       $00000058           ;*** PERID - Peripheral ID Register
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
IDCOMP              equ       $00000059           ;*** IDCOMP - Peripheral ID Complement Register
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
REV                 equ       $0000005A           ;*** REV - Peripheral Revision Register
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
INTSTAT             equ       $00000060           ;*** INTSTAT - Interrupt Status Register
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
INTENB              equ       $00000061           ;*** INTENB - Interrupt Enable Register
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
ERRSTAT             equ       $00000062           ;*** ERRSTAT - Error Interrupt Status Register
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
ERRENB              equ       $00000063           ;*** ERRENB - Error Interrupt Enable Register
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
STAT                equ       $00000064           ;*** STAT - Status Register
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
CTL                 equ       $00000065           ;*** CTL - Control Register
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
ADDR                equ       $00000066           ;*** ADDR - Address Register
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
FRMNUML             equ       $00000067           ;*** FRMNUML - Frame Number Register Low
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
FRMNUMH             equ       $00000068           ;*** FRMNUMH - Frame Number Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRMNUMH_FRM8        equ       0                   ; Frame Number Bit 8
FRMNUMH_FRM9        equ       1                   ; Frame Number Bit 9
FRMNUMH_FRM10       equ       2                   ; Frame Number Bit 10
; bit position masks
mFRMNUMH_FRM8       equ       %00000001
mFRMNUMH_FRM9       equ       %00000010
mFRMNUMH_FRM10      equ       %00000100

;*** EPCTL0 - Endpoint Control Register 0
EPCTL0              equ       $0000006D           ;*** EPCTL0 - Endpoint Control Register 0
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
EPCTL1              equ       $0000006E           ;*** EPCTL1 - Endpoint Control Register 1
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
EPCTL2              equ       $0000006F           ;*** EPCTL2 - Endpoint Control Register 2
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
EPCTL3              equ       $00000070           ;*** EPCTL3 - Endpoint Control Register 3
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
EPCTL4              equ       $00000071           ;*** EPCTL4 - Endpoint Control Register 4
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
EPCTL5              equ       $00000072           ;*** EPCTL5 - Endpoint Control Register 5
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
EPCTL6              equ       $00000073           ;*** EPCTL6 - Endpoint Control Register 6
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
SRS_ILAD            equ       3                   ; Illegal Address
SRS_ILOP            equ       4                   ; Illegal Opcode
SRS_COP             equ       5                   ; Computer Operating Properly (COP) Watchdog
SRS_PIN             equ       6                   ; External Reset Pin
SRS_POR             equ       7                   ; Power-On Reset
; bit position masks
mSRS_LVD            equ       %00000010
mSRS_LOC            equ       %00000100
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
SOPT1_BLMSS         equ       2                   ; BLMS Pin State
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT0         equ       6                   ; COP Watchdog Timeout, bit 0
SOPT1_COPT1         equ       7                   ; COP Watchdog Timeout, bit 1
; bit position masks
mSOPT1_RSTPE        equ       %00000001
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_BLMSS        equ       %00000100
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT0        equ       %01000000
mSOPT1_COPT1        equ       %10000000

;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_SPIFE         equ       2                   ; SPI Ports Input Filter Enable
SOPT2_COPW          equ       6                   ; COP Window
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_SPIFE        equ       %00000100
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
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVWIE        equ       5                   ; Low-Voltage Warning Interrupt Enable
SPMSC1_LVWACK       equ       6                   ; Low-Voltage Warning Acknowledge
SPMSC1_LVWF         equ       7                   ; Low-Voltage Warning status
; bit position masks
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

;*** FTRIM - Reserved for storage of FTRIM
FTRIM               equ       $0000180C           ;*** FTRIM - Reserved for storage of FTRIM
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTRIM_FTRIM         equ       0                   ; Factory FTRIM value
; bit position masks
mFTRIM_FTRIM        equ       %00000001

;*** MCGTRIM - Reserved for storage of MCGTRIM
MCGTRIM             equ       $0000180D           ;*** MCGTRIM - Reserved for storage of MCGTRIM
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGTRIM_TRIM0       equ       0                   ; Factory trim value, bit 0
MCGTRIM_TRIM1       equ       1                   ; Factory trim value, bit 1
MCGTRIM_TRIM2       equ       2                   ; Factory trim value, bit 2
MCGTRIM_TRIM3       equ       3                   ; Factory trim value, bit 3
MCGTRIM_TRIM4       equ       4                   ; Factory trim value, bit 4
MCGTRIM_TRIM5       equ       5                   ; Factory trim value, bit 5
MCGTRIM_TRIM6       equ       6                   ; Factory trim value, bit 6
MCGTRIM_TRIM7       equ       7                   ; Factory trim value, bit 7
; bit position masks
mMCGTRIM_TRIM0      equ       %00000001
mMCGTRIM_TRIM1      equ       %00000010
mMCGTRIM_TRIM2      equ       %00000100
mMCGTRIM_TRIM3      equ       %00001000
mMCGTRIM_TRIM4      equ       %00010000
mMCGTRIM_TRIM5      equ       %00100000
mMCGTRIM_TRIM6      equ       %01000000
mMCGTRIM_TRIM7      equ       %10000000

;*** FPROTD - Flash Protection Defeat Register
FPROTD              equ       $0000180E           ;*** FPROTD - Flash Protection Defeat Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROTD_Bit0         equ       0                   ; FPROT_FPDIS can be set to 1
; bit position masks
mFPROTD_Bit0        equ       %00000001

;*** SIGNATURE - SIGNATURE Register
SIGNATURE           equ       $0000180F           ;*** SIGNATURE - SIGNATURE Register

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
PTBPE_PTBPE4        equ       4                   ; Internal Pull Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Internal Pull Enable for Port B Bit 5
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000

;*** PTBSE - Port B Slew Rate Enable Register
PTBSE               equ       $00001845           ;*** PTBSE - Port B Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE1        equ       1                   ; Output Slew Rate Enable for Port B Bit 1
PTBSE_PTBSE2        equ       2                   ; Output Slew Rate Enable for Port B Bit 2
PTBSE_PTBSE3        equ       3                   ; Output Slew Rate Enable for Port B Bit 3
PTBSE_PTBSE4        equ       4                   ; Output Slew Rate Enable for Port B Bit 4
PTBSE_PTBSE5        equ       5                   ; Output Slew Rate Enable for Port B Bit 5
; bit position masks
mPTBSE_PTBSE1       equ       %00000010
mPTBSE_PTBSE2       equ       %00000100
mPTBSE_PTBSE3       equ       %00001000
mPTBSE_PTBSE4       equ       %00010000
mPTBSE_PTBSE5       equ       %00100000

;*** PTBDS - Port B Drive Strength Selection Register
PTBDS               equ       $00001846           ;*** PTBDS - Port B Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS1        equ       1                   ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2        equ       2                   ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3        equ       3                   ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4        equ       4                   ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5        equ       5                   ; Output Drive Strength Selection for Port B Bit 5
; bit position masks
mPTBDS_PTBDS1       equ       %00000010
mPTBDS_PTBDS2       equ       %00000100
mPTBDS_PTBDS3       equ       %00001000
mPTBDS_PTBDS4       equ       %00010000
mPTBDS_PTBDS5       equ       %00100000

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

;*** CHECKSUMBYPASS - Checksum bypass
CHECKSUMBYPASS      equ       $0000FFBA           ;*** CHECKSUMBYPASS - Checksum bypass
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CHECKSUMBYPASS_BIT0 equ       0                   ; Checksum bypass, bit 0
CHECKSUMBYPASS_BIT1 equ       1                   ; Checksum bypass, bit 1
CHECKSUMBYPASS_BIT2 equ       2                   ; Checksum bypass, bit 2
CHECKSUMBYPASS_BIT3 equ       3                   ; Checksum bypass, bit 3
CHECKSUMBYPASS_BIT4 equ       4                   ; Checksum bypass, bit 4
CHECKSUMBYPASS_BIT5 equ       5                   ; Checksum bypass, bit 5
CHECKSUMBYPASS_BIT6 equ       6                   ; Checksum bypass, bit 6
CHECKSUMBYPASS_BIT7 equ       7                   ; Checksum bypass, bit 7
; bit position masks
mCHECKSUMBYPASS_BIT0 equ       %00000001
mCHECKSUMBYPASS_BIT1 equ       %00000010
mCHECKSUMBYPASS_BIT2 equ       %00000100
mCHECKSUMBYPASS_BIT3 equ       %00001000
mCHECKSUMBYPASS_BIT4 equ       %00010000
mCHECKSUMBYPASS_BIT5 equ       %00100000
mCHECKSUMBYPASS_BIT6 equ       %01000000
mCHECKSUMBYPASS_BIT7 equ       %10000000

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

; **** 11.8.2009 7:48:10

       #ifndef __GENERATE_APPLICATION__
       #endif

; EOF
