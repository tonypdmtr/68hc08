;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908RF2, version 2.87.075 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908rf2.inc
;     Processor : MC68HC908RF2CFA
;     FileFormat: V2.28
;     DataSheet : MC68HC908RF2/D Rev. 4 5/2004
;     Compiler  : CodeWarrior compiler
;     Date/Time : 27.5.2009, 10:00
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;      - 14.11.2005, V2.00 :
;               - Deprecated symbols added for backward compatibility (section at the end of this file)
;      - 15.11.2005, V2.01 :
;               - Changes have not affected this file (because they are related to another family)
;      - 17.12.2005, V2.02 :
;               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
;      - 16.01.2006, V2.03 :
;               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
;               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
;      - 08.03.2006, V2.04 :
;               - Support for bit(s) names duplicated with any register name in .h header files
;      - 24.03.2006, V2.05 :
;               - Changes have not affected this file (because they are related to another family)
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
;               - Changes have not affected this file (because they are related to another family)
;      - 22.01.2007, V2.12 :
;               - Changes have not affected this file (because they are related to another family)
;      - 01.03.2007, V2.13 :
;               - Flash commands constants values converted to HEX format
;      - 02.03.2007, V2.14 :
;               - Interrupt vector numbers added into .H, see VectorNumber_*
;      - 26.03.2007, V2.15 :
;               - Changes have not affected this file (because they are related to another family)
;      - 10.05.2007, V2.16 :
;               - Fixed flash commands definition for ColdFireV1 assembler (equ -> .equ)
;      - 05.06.2007, V2.17 :
;               - Changes have not affected this file (because they are related to another family)
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
;               - Duplication of bit (or bit-group) name with register name is not marked as a problem, is register is internal only and it is not displayed in I/O map.
;      - 17.3.2009, V2.27 :
;               - Merged bit-group is not generated, if the name matchs with anouther bit name in the register
;      - 6.4.2009, V2.28 :
;               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $00007800
ROM_END             equ       $00007FEE
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       RAM
XRAM_END            equ       RAM_END
;
INT_ICG             equ       $0000FFF2
INT_TIMOvr          equ       $0000FFF4
INT_TIMCH1          equ       $0000FFF6
INT_TIMCH0          equ       $0000FFF8
INT_KBI_IRQ1        equ       $0000FFFA
INT_SWI             equ       $0000FFFC
INT_RESET           equ       $0000FFFE
;

;*** PTA - Port A Data Register
PTA                 equ       $00000000           ;*** PTA - Port A Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTA_PTA0            equ       0                   ; Port A Data Bit 0
PTA_PTA1            equ       1                   ; Port A Data Bit 1
PTA_PTA2            equ       2                   ; Port A Data Bit 2
PTA_PTA3            equ       3                   ; Port A Data Bit 3
PTA_PTA4            equ       4                   ; Port A Data Bit 4
PTA_PTA5            equ       5                   ; Port A Data Bit 5
PTA_PTA6            equ       6                   ; Port A Data Bit 6
PTA_PTA7            equ       7                   ; Port A Data Bit 7
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000
mPTA_PTA5           equ       %00100000
mPTA_PTA6           equ       %01000000
mPTA_PTA7           equ       %10000000

;*** PTB - Port B Data Register
PTB                 equ       $00000001           ;*** PTB - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTB_PTB0            equ       0                   ; Port B Data Bit 0
PTB_PTB1            equ       1                   ; Port B Data Bit 1
PTB_PTB2            equ       2                   ; Port B Data Bit 2
PTB_PTB3            equ       3                   ; Port B Data Bit 3
; bit position masks
mPTB_PTB0           equ       %00000001
mPTB_PTB1           equ       %00000010
mPTB_PTB2           equ       %00000100
mPTB_PTB3           equ       %00001000

;*** DDRA - Data Direction Register A
DDRA                equ       $00000004           ;*** DDRA - Data Direction Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRA_DDRA0          equ       0                   ; Data Direction Register A Bit 0
DDRA_DDRA1          equ       1                   ; Data Direction Register A Bit 1
DDRA_DDRA2          equ       2                   ; Data Direction Register A Bit 2
DDRA_DDRA3          equ       3                   ; Data Direction Register A Bit 3
DDRA_DDRA4          equ       4                   ; Data Direction Register A Bit 4
DDRA_DDRA5          equ       5                   ; Data Direction Register A Bit 5
DDRA_DDRA6          equ       6                   ; Data Direction Register A Bit 6
DDRA_DDRA7          equ       7                   ; Data Direction Register A Bit 7
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA2         equ       %00000100
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000
mDDRA_DDRA5         equ       %00100000
mDDRA_DDRA6         equ       %01000000
mDDRA_DDRA7         equ       %10000000

;*** DDRB - Data Direction Register B
DDRB                equ       $00000005           ;*** DDRB - Data Direction Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRB_DDRB0          equ       0                   ; Data Direction Register B Bit 0
DDRB_DDRB1          equ       1                   ; Data Direction Register B Bit 1
DDRB_DDRB2          equ       2                   ; Data Direction Register B Bit 2
DDRB_DDRB3          equ       3                   ; Data Direction Register B Bit 3
DDRB_MCLKEN         equ       7                   ; MCLK Enable Bit
; bit position masks
mDDRB_DDRB0         equ       %00000001
mDDRB_DDRB1         equ       %00000010
mDDRB_DDRB2         equ       %00000100
mDDRB_DDRB3         equ       %00001000
mDDRB_MCLKEN        equ       %10000000

;*** INTKBSCR - Keyboard Status and Control Register
INTKBSCR            equ       $0000001A           ;*** INTKBSCR - Keyboard Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBSCR_MODEK      equ       0                   ; Keyboard Triggering Sensitivity Bit
INTKBSCR_IMASKK     equ       1                   ; Keyboard Interrupt Mask Bit
INTKBSCR_ACKK       equ       2                   ; Keyboard Acknowledge Bit
INTKBSCR_KEYF       equ       3                   ; Keyboard Flag Bit
INTKBSCR_MODEI      equ       4                   ; IRQ Edge/Level Select Bit
INTKBSCR_IMASKI     equ       5                   ; IRQ Interrupt Mask Bit
INTKBSCR_ACKI       equ       6                   ; IRQ Interrupt Request Acknowledge Bit
INTKBSCR_IRQ1F      equ       7                   ; IRQ Flag Bit
; bit position masks
mINTKBSCR_MODEK     equ       %00000001
mINTKBSCR_IMASKK    equ       %00000010
mINTKBSCR_ACKK      equ       %00000100
mINTKBSCR_KEYF      equ       %00001000
mINTKBSCR_MODEI     equ       %00010000
mINTKBSCR_IMASKI    equ       %00100000
mINTKBSCR_ACKI      equ       %01000000
mINTKBSCR_IRQ1F     equ       %10000000

;*** INTKBIER - Keyboard Interrrupt Enable Register KBIER
INTKBIER            equ       $0000001B           ;*** INTKBIER - Keyboard Interrrupt Enable Register KBIER
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBIER_KBIE1      equ       1                   ; Keyboard Interrupt Enable Bit 1
INTKBIER_KBIE2      equ       2                   ; Keyboard Interrupt Enable Bit 2
INTKBIER_KBIE3      equ       3                   ; Keyboard Interrupt Enable Bit 3
INTKBIER_KBIE4      equ       4                   ; Keyboard Interrupt Enable Bit 4
INTKBIER_KBIE5      equ       5                   ; Keyboard Interrupt Enable Bit 5
INTKBIER_KBIE6      equ       6                   ; Keyboard Interrupt Enable Bit 6
; bit position masks
mINTKBIER_KBIE1     equ       %00000010
mINTKBIER_KBIE2     equ       %00000100
mINTKBIER_KBIE3     equ       %00001000
mINTKBIER_KBIE4     equ       %00010000
mINTKBIER_KBIE5     equ       %00100000
mINTKBIER_KBIE6     equ       %01000000

;*** CONFIG - Configuration Register
CONFIG              equ       $0000001F           ;*** CONFIG - Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG_COPD         equ       0                   ; COP Disable Bit
CONFIG_STOP         equ       1                   ; STOP Instruction Enable Bit
CONFIG_SSREC        equ       2                   ; Short Stop Recovery Bit
CONFIG_COPRS        equ       3                   ; COP Reset Period Selection Bit
CONFIG_LVIPWR       equ       4                   ; Low Voltage Inhibit Power Enable Bit
CONFIG_LVIRST       equ       5                   ; Low Voltage Inhibit Reset Enable Bit
CONFIG_LVISTOP      equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG_EXTSLOW      equ       7                   ; Slow External Crystal Enable Bit
; bit position masks
mCONFIG_COPD        equ       %00000001
mCONFIG_STOP        equ       %00000010
mCONFIG_SSREC       equ       %00000100
mCONFIG_COPRS       equ       %00001000
mCONFIG_LVIPWR      equ       %00010000
mCONFIG_LVIRST      equ       %00100000
mCONFIG_LVISTOP     equ       %01000000
mCONFIG_EXTSLOW     equ       %10000000

;*** TSC - TIM Status and Control Register TSC
TSC                 equ       $00000020           ;*** TSC - TIM Status and Control Register TSC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC_PS0             equ       0                   ; Prescaler Select Bit
TSC_PS1             equ       1                   ; Prescaler Select Bit
TSC_PS2             equ       2                   ; Prescaler Select Bit
TSC_TRST            equ       4                   ; TIM Reset Bit
TSC_TSTOP           equ       5                   ; TIM Stop Bit
TSC_TOIE            equ       6                   ; TIM Overflow Interrupt Enable Bit
TSC_TOF             equ       7                   ; TIM Overflow Flag Bit
; bit position masks
mTSC_PS0            equ       %00000001
mTSC_PS1            equ       %00000010
mTSC_PS2            equ       %00000100
mTSC_TRST           equ       %00010000
mTSC_TSTOP          equ       %00100000
mTSC_TOIE           equ       %01000000
mTSC_TOF            equ       %10000000

;*** TCNT - TIM Counter Register
TCNT                equ       $00000021           ;*** TCNT - TIM Counter Register

;*** TCNTH - TIM Counter Register High
TCNTH               equ       $00000021           ;*** TCNTH - TIM Counter Register High

;*** TCNTL - TIM Counter Register Low
TCNTL               equ       $00000022           ;*** TCNTL - TIM Counter Register Low

;*** TMOD - TIM Counter Modulo Register
TMOD                equ       $00000023           ;*** TMOD - TIM Counter Modulo Register

;*** TMODH - TIM Counter Modulo Register High
TMODH               equ       $00000023           ;*** TMODH - TIM Counter Modulo Register High

;*** TMODL - TIM Counter Modulo Register Low
TMODL               equ       $00000024           ;*** TMODL - TIM Counter Modulo Register Low

;*** TSC0 - TIM Channel 0 Status and Control Register
TSC0                equ       $00000025           ;*** TSC0 - TIM Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC0_CH0MAX         equ       0                   ; Channel 0 Maximum Duty Cycle Bit
TSC0_TOV0           equ       1                   ; Toggle-On-Overflow Bit
TSC0_ELS0A          equ       2                   ; Edge/Level Select Bit
TSC0_ELS0B          equ       3                   ; Edge/Level Select Bit
TSC0_MS0A           equ       4                   ; Mode Select Bit A
TSC0_MS0B           equ       5                   ; Mode Select Bit B
TSC0_CH0IE          equ       6                   ; Channel 0 Interrupt Enable Bit
TSC0_CH0F           equ       7                   ; Channel 0 Flag Bit
; bit position masks
mTSC0_CH0MAX        equ       %00000001
mTSC0_TOV0          equ       %00000010
mTSC0_ELS0A         equ       %00000100
mTSC0_ELS0B         equ       %00001000
mTSC0_MS0A          equ       %00010000
mTSC0_MS0B          equ       %00100000
mTSC0_CH0IE         equ       %01000000
mTSC0_CH0F          equ       %10000000

;*** TCH0 - TIM Channel 0 Register
TCH0                equ       $00000026           ;*** TCH0 - TIM Channel 0 Register

;*** TCH0H - TIM Channel 0 Register High
TCH0H               equ       $00000026           ;*** TCH0H - TIM Channel 0 Register High

;*** TCH0L - TIM Channel 0 Register Low
TCH0L               equ       $00000027           ;*** TCH0L - TIM Channel 0 Register Low

;*** TSC1 - TIM Channel 1 Status and Control Register
TSC1                equ       $00000028           ;*** TSC1 - TIM Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC1_CH1MAX         equ       0                   ; Channel 1 Maximum Duty Cycle Bit
TSC1_TOV1           equ       1                   ; Toggle-On-Overflow Bit
TSC1_ELS1A          equ       2                   ; Edge/Level Select Bit
TSC1_ELS1B          equ       3                   ; Edge/Level Select Bit
TSC1_MS1A           equ       4                   ; Mode Select Bit A
TSC1_CH1IE          equ       6                   ; Channel 1 Interrupt Enable Bit
TSC1_CH1F           equ       7                   ; Channel 1 Flag Bit
; bit position masks
mTSC1_CH1MAX        equ       %00000001
mTSC1_TOV1          equ       %00000010
mTSC1_ELS1A         equ       %00000100
mTSC1_ELS1B         equ       %00001000
mTSC1_MS1A          equ       %00010000
mTSC1_CH1IE         equ       %01000000
mTSC1_CH1F          equ       %10000000

;*** TCH1 - TIM Channel 1 Register
TCH1                equ       $00000029           ;*** TCH1 - TIM Channel 1 Register

;*** TCH1H - TIM Channel 1 Register High
TCH1H               equ       $00000029           ;*** TCH1H - TIM Channel 1 Register High

;*** TCH1L - TIM Channel 1 Register Low
TCH1L               equ       $0000002A           ;*** TCH1L - TIM Channel 1 Register Low

;*** ICGCR - ICG Control Register
ICGCR               equ       $00000036           ;*** ICGCR - ICG Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGCR_ECGS          equ       0                   ; Extrernal Clock Generator Stable Bit
ICGCR_ECGON         equ       1                   ; External Clock Generator On Bit
ICGCR_ICGS          equ       2                   ; Internal Clock Generator Stable Bit
ICGCR_ICGON         equ       3                   ; Internal Clock Generator On Bit
ICGCR_CS            equ       4                   ; Clock Select Bit
ICGCR_CMON          equ       5                   ; Clock Monitor On Bit
ICGCR_CMF           equ       6                   ; Clock Monitor Interrupt Flag
ICGCR_CMIE          equ       7                   ; Clock Monitor Interrupt Enable Bit
; bit position masks
mICGCR_ECGS         equ       %00000001
mICGCR_ECGON        equ       %00000010
mICGCR_ICGS         equ       %00000100
mICGCR_ICGON        equ       %00001000
mICGCR_CS           equ       %00010000
mICGCR_CMON         equ       %00100000
mICGCR_CMF          equ       %01000000
mICGCR_CMIE         equ       %10000000

;*** ICGMR - ICG Multiplier Register
ICGMR               equ       $00000037           ;*** ICGMR - ICG Multiplier Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGMR_N0            equ       0                   ; ICG Multiplier Factor Bit
ICGMR_N1            equ       1                   ; ICG Multiplier Factor Bit
ICGMR_N2            equ       2                   ; ICG Multiplier Factor Bit
ICGMR_N3            equ       3                   ; ICG Multiplier Factor Bit
ICGMR_N4            equ       4                   ; ICG Multiplier Factor Bit
ICGMR_N5            equ       5                   ; ICG Multiplier Factor Bit
ICGMR_N6            equ       6                   ; ICG Multiplier Factor Bit
; bit position masks
mICGMR_N0           equ       %00000001
mICGMR_N1           equ       %00000010
mICGMR_N2           equ       %00000100
mICGMR_N3           equ       %00001000
mICGMR_N4           equ       %00010000
mICGMR_N5           equ       %00100000
mICGMR_N6           equ       %01000000

;*** ICGTR - ICG Trim Register
ICGTR               equ       $00000038           ;*** ICGTR - ICG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGTR_TRIM0         equ       0                   ; ICG Trim Factor Bit
ICGTR_TRIM1         equ       1                   ; ICG Trim Factor Bit
ICGTR_TRIM2         equ       2                   ; ICG Trim Factor Bit
ICGTR_TRIM3         equ       3                   ; ICG Trim Factor Bit
ICGTR_TRIM4         equ       4                   ; ICG Trim Factor Bit
ICGTR_TRIM5         equ       5                   ; ICG Trim Factor Bit
ICGTR_TRIM6         equ       6                   ; ICG Trim Factor Bit
ICGTR_TRIM7         equ       7                   ; ICG Trim Factor Bit
; bit position masks
mICGTR_TRIM0        equ       %00000001
mICGTR_TRIM1        equ       %00000010
mICGTR_TRIM2        equ       %00000100
mICGTR_TRIM3        equ       %00001000
mICGTR_TRIM4        equ       %00010000
mICGTR_TRIM5        equ       %00100000
mICGTR_TRIM6        equ       %01000000
mICGTR_TRIM7        equ       %10000000

;*** ICGDVR - ICG DCO Divider Control Register
ICGDVR              equ       $00000039           ;*** ICGDVR - ICG DCO Divider Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGDVR_DDIV0        equ       0                   ; ICG DCO Divider Control Bit
ICGDVR_DDIV1        equ       1                   ; ICG DCO Divider Control Bit
ICGDVR_DDIV2        equ       2                   ; ICG DCO Divider Control Bit
ICGDVR_DDIV3        equ       3                   ; ICG DCO Divider Control Bit
; bit position masks
mICGDVR_DDIV0       equ       %00000001
mICGDVR_DDIV1       equ       %00000010
mICGDVR_DDIV2       equ       %00000100
mICGDVR_DDIV3       equ       %00001000

;*** ICGDSR - ICG DCO Stage Control Register
ICGDSR              equ       $0000003A           ;*** ICGDSR - ICG DCO Stage Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGDSR_DSTG0        equ       0                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG1        equ       1                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG2        equ       2                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG3        equ       3                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG4        equ       4                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG5        equ       5                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG6        equ       6                   ; ICG DCO Stage Control Bit
ICGDSR_DSTG7        equ       7                   ; ICG DCO Stage Control Bit
; bit position masks
mICGDSR_DSTG0       equ       %00000001
mICGDSR_DSTG1       equ       %00000010
mICGDSR_DSTG2       equ       %00000100
mICGDSR_DSTG3       equ       %00001000
mICGDSR_DSTG4       equ       %00010000
mICGDSR_DSTG5       equ       %00100000
mICGDSR_DSTG6       equ       %01000000
mICGDSR_DSTG7       equ       %10000000

;*** SBSR - SIM Break Status Register
SBSR                equ       $0000FE00           ;*** SBSR - SIM Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBSR_SBSW           equ       1                   ; Break Wait Bit
; bit position masks
mSBSR_SBSW          equ       %00000010

;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset Bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
mSRSR_ILAD          equ       %00001000
mSRSR_ILOP          equ       %00010000
mSRSR_COP           equ       %00100000
mSRSR_PIN           equ       %01000000
mSRSR_POR           equ       %10000000

;*** SBFCR - SIM Break Flag Control Register
SBFCR               equ       $0000FE02           ;*** SBFCR - SIM Break Flag Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBFCR_BCFE          equ       7                   ; Break Clear Flag Enable Bit
; bit position masks
mSBFCR_BCFE         equ       %10000000

;*** FLCR - FLASH 2TS Control Register
FLCR                equ       $0000FE08           ;*** FLCR - FLASH 2TS Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_ERASE          equ       1                   ; Erase Control Bit
FLCR_MARGIN         equ       2                   ; Mass Erase Control Bit
FLCR_HVEN           equ       3                   ; High-Voltage Enable Bit
FLCR_BLK0           equ       4                   ; Block Erase Control Bit
FLCR_BLK1           equ       5                   ; Block Erase Control Bit
FLCR_FDIV0          equ       6                   ; Frequency Divide Control Bit
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_ERASE         equ       %00000010
mFLCR_MARGIN        equ       %00000100
mFLCR_HVEN          equ       %00001000
mFLCR_BLK0          equ       %00010000
mFLCR_BLK1          equ       %00100000
mFLCR_FDIV0         equ       %01000000

;*** BRK - Break Address Register
BRK                 equ       $0000FE0C           ;*** BRK - Break Address Register

;*** BRKH - Break Address Register High
BRKH                equ       $0000FE0C           ;*** BRKH - Break Address Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKH_BIT8           equ       0                   ; Break Address Register Bit
BRKH_BIT9           equ       1                   ; Break Address Register Bit
BRKH_BIT10          equ       2                   ; Break Address Register Bit
BRKH_BIT11          equ       3                   ; Break Address Register Bit
BRKH_BIT12          equ       4                   ; Break Address Register Bit
BRKH_BIT13          equ       5                   ; Break Address Register Bit
BRKH_BIT14          equ       6                   ; Break Address Register Bit
BRKH_BIT15          equ       7                   ; Break Address Register Bit
; bit position masks
mBRKH_BIT8          equ       %00000001
mBRKH_BIT9          equ       %00000010
mBRKH_BIT10         equ       %00000100
mBRKH_BIT11         equ       %00001000
mBRKH_BIT12         equ       %00010000
mBRKH_BIT13         equ       %00100000
mBRKH_BIT14         equ       %01000000
mBRKH_BIT15         equ       %10000000

;*** BRKL - Break Address Register Low
BRKL                equ       $0000FE0D           ;*** BRKL - Break Address Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKL_BIT0           equ       0                   ; Break Address Register Bit
BRKL_BIT1           equ       1                   ; Break Address Register Bit
BRKL_BIT2           equ       2                   ; Break Address Register Bit
BRKL_BIT3           equ       3                   ; Break Address Register Bit
BRKL_BIT4           equ       4                   ; Break Address Register Bit
BRKL_BIT5           equ       5                   ; Break Address Register Bit
BRKL_BIT6           equ       6                   ; Break Address Register Bit
BRKL_BIT7           equ       7                   ; Break Address Register Bit
; bit position masks
mBRKL_BIT0          equ       %00000001
mBRKL_BIT1          equ       %00000010
mBRKL_BIT2          equ       %00000100
mBRKL_BIT3          equ       %00001000
mBRKL_BIT4          equ       %00010000
mBRKL_BIT5          equ       %00100000
mBRKL_BIT6          equ       %01000000
mBRKL_BIT7          equ       %10000000

;*** BRKSCR - Break Status and Control Register
BRKSCR              equ       $0000FE0E           ;*** BRKSCR - Break Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKSCR_BRKA         equ       6                   ; Break Active Bit
BRKSCR_BRKE         equ       7                   ; Break Enable Bit
; bit position masks
mBRKSCR_BRKA        equ       %01000000
mBRKSCR_BRKE        equ       %10000000

;*** LVISR - LVI Status Register
LVISR               equ       $0000FE0F           ;*** LVISR - LVI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISR_LOWV          equ       5                   ; LVI Low Indicator Bit
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LOWV         equ       %00100000
mLVISR_LVIOUT       equ       %10000000

;*** FLBPR - FLASH 2TS Block Protect Register
FLBPR               equ       $0000FFF0           ;*** FLBPR - FLASH 2TS Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR0          equ       0                   ; Block Protect Register Bit 0
FLBPR_BPR1          equ       1                   ; Block Protect Register Bit 1
FLBPR_BPR2          equ       2                   ; Block Protect Register Bit 2
FLBPR_BPR3          equ       3                   ; Block Protect Register Bit 3
; bit position masks
mFLBPR_BPR0         equ       %00000001
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000

;*** COPCTL - COP Control Register
COPCTL              equ       $0000FFFF           ;*** COPCTL - COP Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
COPCTL_BIT0         equ       0                   ; Bit 0
COPCTL_BIT1         equ       1                   ; Bit 1
COPCTL_BIT2         equ       2                   ; Bit 2
COPCTL_BIT3         equ       3                   ; Bit 3
COPCTL_BIT4         equ       4                   ; Bit 4
COPCTL_BIT5         equ       5                   ; Bit 5
COPCTL_BIT6         equ       6                   ; Bit 6
COPCTL_BIT7         equ       7                   ; Bit 7
; bit position masks
mCOPCTL_BIT0        equ       %00000001
mCOPCTL_BIT1        equ       %00000010
mCOPCTL_BIT2        equ       %00000100
mCOPCTL_BIT3        equ       %00001000
mCOPCTL_BIT4        equ       %00010000
mCOPCTL_BIT5        equ       %00100000
mCOPCTL_BIT6        equ       %01000000
mCOPCTL_BIT7        equ       %10000000

;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
       #ifndef  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
       #endif
; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------

; EOF
