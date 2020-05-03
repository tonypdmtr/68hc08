;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC68HC908LB8, version 2.87.182 (RegistersPrg V2.28)

; ###################################################################
;     Filename  : mc68hc908lb8.inc
;     Processor : MC68HC908LB8CDWE
;     FileFormat: V2.28
;     DataSheet : MC68HC908LB8 Rev. 1 8/2005
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
ROM                 equ       $0000DE00
ROM_END             equ       $0000FDFF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       RAM
XRAM_END            equ       RAM_END
;
INT_ADC             equ       $0000FFDE
INT_KBI             equ       $0000FFE0
Reserved2           equ       $0000FFE2
Reserved3           equ       $0000FFE4
Reserved4           equ       $0000FFE6
Reserved5           equ       $0000FFE8
Reserved6           equ       $0000FFEA
INT_SHTDWN          equ       $0000FFEC
INT_PWMINT          equ       $0000FFEE
INT_FAULT           equ       $0000FFF0
INT_TIMOvr          equ       $0000FFF2
INT_TIMCH1          equ       $0000FFF4
INT_TIMCH0          equ       $0000FFF6
Reserved13          equ       $0000FFF8
INT_IRQ             equ       $0000FFFA
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
; bit position masks
mPTA_PTA0           equ       %00000001
mPTA_PTA1           equ       %00000010
mPTA_PTA2           equ       %00000100
mPTA_PTA3           equ       %00001000
mPTA_PTA4           equ       %00010000
mPTA_PTA5           equ       %00100000
mPTA_PTA6           equ       %01000000


;*** PTB - Port B Data Register
PTB                 equ       $00000001           ;*** PTB - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTB_PTB0            equ       0                   ; Port B Data Bit 0
PTB_PTB1            equ       1                   ; Port B Data Bit 1
PTB_PTB2            equ       2                   ; Port B Data Bit 2
PTB_PTB3            equ       3                   ; Port B Data Bit 3
PTB_PTB4            equ       4                   ; Port B Data Bit 4
PTB_PTB5            equ       5                   ; Port B Data Bit 5
PTB_PTB6            equ       6                   ; Port B Data Bit 6
PTB_PTB7            equ       7                   ; Port B Data Bit 7
; bit position masks
mPTB_PTB0           equ       %00000001
mPTB_PTB1           equ       %00000010
mPTB_PTB2           equ       %00000100
mPTB_PTB3           equ       %00001000
mPTB_PTB4           equ       %00010000
mPTB_PTB5           equ       %00100000
mPTB_PTB6           equ       %01000000
mPTB_PTB7           equ       %10000000


;*** PTC - Port C Data Register
PTC                 equ       $00000002           ;*** PTC - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTC_PTC0            equ       0                   ; Port C Data Bit 0
PTC_PTC1            equ       1                   ; Port C Data Bit 1
PTC_PTC2            equ       2                   ; Port C Data Bit 2
; bit position masks
mPTC_PTC0           equ       %00000001
mPTC_PTC1           equ       %00000010
mPTC_PTC2           equ       %00000100


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
; bit position masks
mDDRA_DDRA0         equ       %00000001
mDDRA_DDRA1         equ       %00000010
mDDRA_DDRA2         equ       %00000100
mDDRA_DDRA3         equ       %00001000
mDDRA_DDRA4         equ       %00010000
mDDRA_DDRA5         equ       %00100000
mDDRA_DDRA6         equ       %01000000


;*** DDRB - Data Direction Register B
DDRB                equ       $00000005           ;*** DDRB - Data Direction Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRB_DDRB0          equ       0                   ; Data Direction Register B Bit 0
DDRB_DDRB1          equ       1                   ; Data Direction Register B Bit 1
DDRB_DDRB2          equ       2                   ; Data Direction Register B Bit 2
DDRB_DDRB3          equ       3                   ; Data Direction Register B Bit 3
DDRB_DDRB4          equ       4                   ; Data Direction Register B Bit 4
DDRB_DDRB5          equ       5                   ; Data Direction Register B Bit 5
DDRB_DDRB6          equ       6                   ; Data Direction Register B Bit 6
DDRB_DDRB7          equ       7                   ; Data Direction Register B Bit 7
; bit position masks
mDDRB_DDRB0         equ       %00000001
mDDRB_DDRB1         equ       %00000010
mDDRB_DDRB2         equ       %00000100
mDDRB_DDRB3         equ       %00001000
mDDRB_DDRB4         equ       %00010000
mDDRB_DDRB5         equ       %00100000
mDDRB_DDRB6         equ       %01000000
mDDRB_DDRB7         equ       %10000000


;*** DDRC - Data Direction Register C
DDRC                equ       $00000006           ;*** DDRC - Data Direction Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DDRC_DDRC0          equ       0                   ; Data Direction Register C Bit 0
DDRC_DDRC1          equ       1                   ; Data Direction Register C Bit 1
; bit position masks
mDDRC_DDRC0         equ       %00000001
mDDRC_DDRC1         equ       %00000010


;*** PTAPUE - Port A Input Pullup Enable Register
PTAPUE              equ       $0000000D           ;*** PTAPUE - Port A Input Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPUE_PTA0PUE      equ       0                   ; Pull-Up Enable bit 0, Port A
PTAPUE_PTA1PUE      equ       1                   ; Pull-Up Enable bit 1, Port A
PTAPUE_PTA2PUE      equ       2                   ; Pull-Up Enable bit 2, Port A
PTAPUE_PTA3PUE      equ       3                   ; Pull-Up Enable bit 3, Port A
PTAPUE_PTA4PUE      equ       4                   ; Pull-Up Enable bit 4, Port A
PTAPUE_PTA5PUE      equ       5                   ; Pull-Up Enable bit 5, Port A
PTAPUE_PTA6PUE      equ       6                   ; Pull-Up Enable bit 6, Port A
; bit position masks
mPTAPUE_PTA0PUE     equ       %00000001
mPTAPUE_PTA1PUE     equ       %00000010
mPTAPUE_PTA2PUE     equ       %00000100
mPTAPUE_PTA3PUE     equ       %00001000
mPTAPUE_PTA4PUE     equ       %00010000
mPTAPUE_PTA5PUE     equ       %00100000
mPTAPUE_PTA6PUE     equ       %01000000


;*** PTCPUE - Port C Input Pullup Enable Register
PTCPUE              equ       $0000000E           ;*** PTCPUE - Port C Input Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPUE_PTCPUE0      equ       0                   ; Pull-Up Enable bit 0, Port C
PTCPUE_PTCPUE1      equ       1                   ; Pull-Up Enable bit 1, Port C
PTCPUE_PTCPUE2      equ       2                   ; Pull-Up Enable bit 2, Port C
PTCPUE_OSC2EN       equ       7                   ; Enable PTC1 on OSC2 Pin
; bit position masks
mPTCPUE_PTCPUE0     equ       %00000001
mPTCPUE_PTCPUE1     equ       %00000010
mPTCPUE_PTCPUE2     equ       %00000100
mPTCPUE_OSC2EN      equ       %10000000


;*** INTKBSCR - Keyboard Status and Control Register
INTKBSCR            equ       $0000001A           ;*** INTKBSCR - Keyboard Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBSCR_MODEK      equ       0                   ; Keyboard Triggering Sensitivity Bit
INTKBSCR_IMASKK     equ       1                   ; Keyboard Interrupt Mask Bit
INTKBSCR_ACKK       equ       2                   ; Keyboard Acknowledge Bit
INTKBSCR_KEYF       equ       3                   ; Keyboard Flag Bit
; bit position masks
mINTKBSCR_MODEK     equ       %00000001
mINTKBSCR_IMASKK    equ       %00000010
mINTKBSCR_ACKK      equ       %00000100
mINTKBSCR_KEYF      equ       %00001000


;*** INTKBIER - Keyboard Interrrupt Enable Register KBIER
INTKBIER            equ       $0000001B           ;*** INTKBIER - Keyboard Interrrupt Enable Register KBIER
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTKBIER_KBIE0      equ       0                   ; Keyboard Interrupt Enable Bit 0
INTKBIER_KBIE1      equ       1                   ; Keyboard Interrupt Enable Bit 1
INTKBIER_KBIE2      equ       2                   ; Keyboard Interrupt Enable Bit 2
INTKBIER_KBIE3      equ       3                   ; Keyboard Interrupt Enable Bit 3
INTKBIER_KBIE4      equ       4                   ; Keyboard Interrupt Enable Bit 4
INTKBIER_KBIE5      equ       5                   ; Keyboard Interrupt Enable Bit 5
INTKBIER_KBIE6      equ       6                   ; Keyboard Interrupt Enable Bit 6
; bit position masks
mINTKBIER_KBIE0     equ       %00000001
mINTKBIER_KBIE1     equ       %00000010
mINTKBIER_KBIE2     equ       %00000100
mINTKBIER_KBIE3     equ       %00001000
mINTKBIER_KBIE4     equ       %00010000
mINTKBIER_KBIE5     equ       %00100000
mINTKBIER_KBIE6     equ       %01000000


;*** INTSCR - IRQ Status and Control Register
INTSCR              equ       $0000001D           ;*** INTSCR - IRQ Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
INTSCR_MODE         equ       0                   ; IRQ Edge/Level Select Bit
INTSCR_IMASK        equ       1                   ; IRQ Interrupt Mask Bit
INTSCR_ACK          equ       2                   ; IRQ Interrupt Request Acknowledge Bit
INTSCR_IRQF         equ       3                   ; IRQ Flag
; bit position masks
mINTSCR_MODE        equ       %00000001
mINTSCR_IMASK       equ       %00000010
mINTSCR_ACK         equ       %00000100
mINTSCR_IRQF        equ       %00001000


;*** CONFIG2 - Configuration Register 2
CONFIG2             equ       $0000001E           ;*** CONFIG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG2_RSTEN       equ       0                   ; RST Pin Function Selection
CONFIG2_OSCOPT0     equ       3                   ; Selection Bit 0 for Oscillator Option
CONFIG2_OSCOPT1     equ       4                   ; Selection Bit 1 for Oscillator Option
CONFIG2_IRQEN       equ       6                   ; IRQ Pin Function Selection Bit
CONFIG2_IRQPUD      equ       7                   ; IRQ Pin Pull-Up Control Bit
; bit position masks
mCONFIG2_RSTEN      equ       %00000001
mCONFIG2_OSCOPT0    equ       %00001000
mCONFIG2_OSCOPT1    equ       %00010000
mCONFIG2_IRQEN      equ       %01000000
mCONFIG2_IRQPUD     equ       %10000000


;*** CONFIG1 - Configuration Register 1
CONFIG1             equ       $0000001F           ;*** CONFIG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CONFIG1_COPD        equ       0                   ; COP Disable Bit
CONFIG1_STOP        equ       1                   ; STOP Instruction Enable Bit
CONFIG1_SSREC       equ       2                   ; Short Stop Recovery Bit
CONFIG1_LVIPWRD     equ       4                   ; LVI Power Disable Bit
CONFIG1_LVIRSTD     equ       5                   ; LVI Reset Disable Bit
CONFIG1_LVISTOP     equ       6                   ; LVI Enable in Stop Mode Bit
CONFIG1_COPRS       equ       7                   ; COP Reset Period Selection Bit
; bit position masks
mCONFIG1_COPD       equ       %00000001
mCONFIG1_STOP       equ       %00000010
mCONFIG1_SSREC      equ       %00000100
mCONFIG1_LVIPWRD    equ       %00010000
mCONFIG1_LVIRSTD    equ       %00100000
mCONFIG1_LVISTOP    equ       %01000000
mCONFIG1_COPRS      equ       %10000000


;*** TSC - TIM Status and Control Register TSC
TSC                 equ       $00000020           ;*** TSC - TIM Status and Control Register TSC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TSC_PS0             equ       0                   ; Prescaler Select Bit 0
TSC_PS1             equ       1                   ; Prescaler Select Bit 1
TSC_PS2             equ       2                   ; Prescaler Select Bit 2
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
TSC0_ELS0A          equ       2                   ; Edge/Level Select Bit A
TSC0_ELS0B          equ       3                   ; Edge/Level Select Bit B
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
TSC1_ELS1A          equ       2                   ; Edge/Level Select Bit A
TSC1_ELS1B          equ       3                   ; Edge/Level Select Bit B
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


;*** OSCSTAT - Oscillator Status Register
OSCSTAT             equ       $00000036           ;*** OSCSTAT - Oscillator Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSCSTAT_ECGST       equ       0                   ; External Clock Status Bit
OSCSTAT_ECGON       equ       1                   ; External Clock Generator On Bit
; bit position masks
mOSCSTAT_ECGST      equ       %00000001
mOSCSTAT_ECGON      equ       %00000010


;*** OSCTRIM - Oscillator Trim Register
OSCTRIM             equ       $00000038           ;*** OSCTRIM - Oscillator Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OSCTRIM_TRIM0       equ       0                   ; Internal Oscillator Trim Factor Bit 0
OSCTRIM_TRIM1       equ       1                   ; Internal Oscillator Trim Factor Bit 1
OSCTRIM_TRIM2       equ       2                   ; Internal Oscillator Trim Factor Bit 2
OSCTRIM_TRIM3       equ       3                   ; Internal Oscillator Trim Factor Bit 3
OSCTRIM_TRIM4       equ       4                   ; Internal Oscillator Trim Factor Bit 4
OSCTRIM_TRIM5       equ       5                   ; Internal Oscillator Trim Factor Bit 5
OSCTRIM_TRIM6       equ       6                   ; Internal Oscillator Trim Factor Bit 6
OSCTRIM_TRIM7       equ       7                   ; Internal Oscillator Trim Factor Bit 7
; bit position masks
mOSCTRIM_TRIM0      equ       %00000001
mOSCTRIM_TRIM1      equ       %00000010
mOSCTRIM_TRIM2      equ       %00000100
mOSCTRIM_TRIM3      equ       %00001000
mOSCTRIM_TRIM4      equ       %00010000
mOSCTRIM_TRIM5      equ       %00100000
mOSCTRIM_TRIM6      equ       %01000000
mOSCTRIM_TRIM7      equ       %10000000


;*** OACCR - Operational Amplifier Control Register
OACCR               equ       $00000039           ;*** OACCR - Operational Amplifier Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
OACCR_OACE          equ       0                   ; Op Amp/Comparator Enable Bit
OACCR_OACM          equ       7                   ; Op Amp/Comparator Mode Select Bit
; bit position masks
mOACCR_OACE         equ       %00000001
mOACCR_OACM         equ       %10000000


;*** ADSCR - ADC Status and Control Register
ADSCR               equ       $0000003C           ;*** ADSCR - ADC Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADSCR_ADCH0         equ       0                   ; ADC Channel Select Bit 0
ADSCR_ADCH1         equ       1                   ; ADC Channel Select Bit 1
ADSCR_ADCH2         equ       2                   ; ADC Channel Select Bit 2
ADSCR_ADCH3         equ       3                   ; ADC Channel Select Bit 3
ADSCR_ADCH4         equ       4                   ; ADC Channel Select Bit 4
ADSCR_ADCO          equ       5                   ; ADC Continuous Conversion Bit
ADSCR_AIEN          equ       6                   ; ADC Interrupt Enable Bit
ADSCR_COCO          equ       7                   ; Conversions Complete Bit
; bit position masks
mADSCR_ADCH0        equ       %00000001
mADSCR_ADCH1        equ       %00000010
mADSCR_ADCH2        equ       %00000100
mADSCR_ADCH3        equ       %00001000
mADSCR_ADCH4        equ       %00010000
mADSCR_ADCO         equ       %00100000
mADSCR_AIEN         equ       %01000000
mADSCR_COCO         equ       %10000000


;*** ADR - ADC Data Register
ADR                 equ       $0000003E           ;*** ADR - ADC Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADR_AD0             equ       0                   ; ADC Data Bit 0
ADR_AD1             equ       1                   ; ADC Data Bit 1
ADR_AD2             equ       2                   ; ADC Data Bit 2
ADR_AD3             equ       3                   ; ADC Data Bit 3
ADR_AD4             equ       4                   ; ADC Data Bit 4
ADR_AD5             equ       5                   ; ADC Data Bit 5
ADR_AD6             equ       6                   ; ADC Data Bit 6
ADR_AD7             equ       7                   ; ADC Data Bit 7
; bit position masks
mADR_AD0            equ       %00000001
mADR_AD1            equ       %00000010
mADR_AD2            equ       %00000100
mADR_AD3            equ       %00001000
mADR_AD4            equ       %00010000
mADR_AD5            equ       %00100000
mADR_AD6            equ       %01000000
mADR_AD7            equ       %10000000


;*** ADCLK - ADC Input Clock Register
ADCLK               equ       $0000003F           ;*** ADCLK - ADC Input Clock Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCLK_ADIV0         equ       5                   ; ADC Clock Prescaler Bit 0
ADCLK_ADIV1         equ       6                   ; ADC Clock Prescaler Bit 1
ADCLK_ADIV2         equ       7                   ; ADC Clock Prescaler Bit 2
; bit position masks
mADCLK_ADIV0        equ       %00100000
mADCLK_ADIV1        equ       %01000000
mADCLK_ADIV2        equ       %10000000


;*** PCTL1 - PWM Control Register 1
PCTL1               equ       $00000040           ;*** PCTL1 - PWM Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL1_PWMEN         equ       0                   ; PWM Module Enable Bit
PCTL1_LDOK          equ       1                   ; Load OK Bit
PCTL1_PWMF          equ       4                   ; PWM Reload Flag
PCTL1_PWMINT        equ       5                   ; PWM Interrupt Enable Bit
PCTL1_FPOS          equ       6                   ; Fault Pin Position Bit
; bit position masks
mPCTL1_PWMEN        equ       %00000001
mPCTL1_LDOK         equ       %00000010
mPCTL1_PWMF         equ       %00010000
mPCTL1_PWMINT       equ       %00100000
mPCTL1_FPOS         equ       %01000000


;*** PCTL2 - PWM Control Register 2
PCTL2               equ       $00000041           ;*** PCTL2 - PWM Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCTL2_PRSC0         equ       0                   ; PWM Prescaler Bit 0
PCTL2_PRSC1         equ       1                   ; PWM Prescaler Bit 1
PCTL2_POL0          equ       2                   ; Polarity Bit for PWM0
PCTL2_POL1          equ       3                   ; Polarity Bit for PWM1
PCTL2_DIS0          equ       4                   ; Software Disable Bit for PWM0
PCTL2_DIS1          equ       5                   ; Software Disable Bit for PWM1
PCTL2_LDFQ0         equ       6                   ; PWM Load Frequency Bit 0
PCTL2_LDFQ1         equ       7                   ; PWM Load Frequency Bit 1
; bit position masks
mPCTL2_PRSC0        equ       %00000001
mPCTL2_PRSC1        equ       %00000010
mPCTL2_POL0         equ       %00000100
mPCTL2_POL1         equ       %00001000
mPCTL2_DIS0         equ       %00010000
mPCTL2_DIS1         equ       %00100000
mPCTL2_LDFQ0        equ       %01000000
mPCTL2_LDFQ1        equ       %10000000


;*** FCR - Fault Control Register
FCR                 equ       $00000042           ;*** FCR - Fault Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCR_FMODE           equ       0                   ; Fault Mode Selection for Fault Pin Bit (automatic versus manual mode)
FCR_FINT            equ       1                   ; Fault Interrupt Enable Bit
; bit position masks
mFCR_FMODE          equ       %00000001
mFCR_FINT           equ       %00000010


;*** FSR - Fault Status Register
FSR                 equ       $00000043           ;*** FSR - Fault Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSR_FFLAG           equ       0                   ; Fault Event Flag
FSR_FPIN            equ       1                   ; State of Fault Pin Bit
; bit position masks
mFSR_FFLAG          equ       %00000001
mFSR_FPIN           equ       %00000010


;*** FCR2 - Fault Control Register 2
FCR2                equ       $00000044           ;*** FCR2 - Fault Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCR2_FTACK          equ       0                   ; Fault Acknowledge Bit
; bit position masks
mFCR2_FTACK         equ       %00000001


;*** PCNT - PWM Counter Register
PCNT                equ       $00000045           ;*** PCNT - PWM Counter Register


;*** PCNTH - PWM Counter Register High
PCNTH               equ       $00000045           ;*** PCNTH - PWM Counter Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNTH_BIT8          equ       0                   ; PWM Counter Bit 8
PCNTH_BIT9          equ       1                   ; PWM Counter Bit 9
PCNTH_BIT10         equ       2                   ; PWM Counter Bit 10
PCNTH_BIT11         equ       3                   ; PWM Counter Bit 11
; bit position masks
mPCNTH_BIT8         equ       %00000001
mPCNTH_BIT9         equ       %00000010
mPCNTH_BIT10        equ       %00000100
mPCNTH_BIT11        equ       %00001000


;*** PCNTL - PWM Counter Register Low
PCNTL               equ       $00000046           ;*** PCNTL - PWM Counter Register Low


;*** PMOD - PWM Counter Modulo Register
PMOD                equ       $00000047           ;*** PMOD - PWM Counter Modulo Register


;*** PMODH - PWM Counter Modulo Register High
PMODH               equ       $00000047           ;*** PMODH - PWM Counter Modulo Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMODH_BIT8          equ       0                   ; PWM Counter Modulo Bit 8
PMODH_BIT9          equ       1                   ; PWM Counter Modulo Bit 9
PMODH_BIT10         equ       2                   ; PWM Counter Modulo Bit 10
PMODH_BIT11         equ       3                   ; PWM Counter Modulo Bit 11
; bit position masks
mPMODH_BIT8         equ       %00000001
mPMODH_BIT9         equ       %00000010
mPMODH_BIT10        equ       %00000100
mPMODH_BIT11        equ       %00001000


;*** PMODL - PWM Counter Modulo Register Low
PMODL               equ       $00000048           ;*** PMODL - PWM Counter Modulo Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMODL_BIT0          equ       0                   ; PWM Counter Modulo Bit 0
PMODL_BIT1          equ       1                   ; PWM Counter Modulo Bit 1
PMODL_BIT2          equ       2                   ; PWM Counter Modulo Bit 2
PMODL_BIT3          equ       3                   ; PWM Counter Modulo Bit 3
PMODL_BIT4          equ       4                   ; PWM Counter Modulo Bit 4
PMODL_BIT5          equ       5                   ; PWM Counter Modulo Bit 5
PMODL_BIT6          equ       6                   ; PWM Counter Modulo Bit 6
PMODL_BIT7          equ       7                   ; PWM Counter Modulo Bit 7
; bit position masks
mPMODL_BIT0         equ       %00000001
mPMODL_BIT1         equ       %00000010
mPMODL_BIT2         equ       %00000100
mPMODL_BIT3         equ       %00001000
mPMODL_BIT4         equ       %00010000
mPMODL_BIT5         equ       %00100000
mPMODL_BIT6         equ       %01000000
mPMODL_BIT7         equ       %10000000


;*** PVAL0 - PWM0 Value Registers
PVAL0               equ       $00000049           ;*** PVAL0 - PWM0 Value Registers


;*** PVAL0H - PWM0 Value Registers High
PVAL0H              equ       $00000049           ;*** PVAL0H - PWM0 Value Registers High


;*** PVAL0L - PWM0 Value Registers Low
PVAL0L              equ       $0000004A           ;*** PVAL0L - PWM0 Value Registers Low


;*** PVAL1 - PWM1 Value Registers
PVAL1               equ       $0000004B           ;*** PVAL1 - PWM1 Value Registers


;*** PVAL1H - PWM1 Value Registers High
PVAL1H              equ       $0000004B           ;*** PVAL1H - PWM1 Value Registers High


;*** PVAL1L - PWM1 Value Registers Low
PVAL1L              equ       $0000004C           ;*** PVAL1L - PWM1 Value Registers Low


;*** DISMAP - PWM Disable Mapping Write-Once Register
DISMAP              equ       $0000004D           ;*** DISMAP - PWM Disable Mapping Write-Once Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DISMAP_MAP0         equ       0                   ; Disable Map for PWM0 Bit
DISMAP_MAP1         equ       1                   ; Disable Map for PWM1 Bit
; bit position masks
mDISMAP_MAP0        equ       %00000001
mDISMAP_MAP1        equ       %00000010


;*** HRPCTRL - HRP Control Register
HRPCTRL             equ       $00000051           ;*** HRPCTRL - HRP Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPCTRL_HRPEN       equ       0                   ; HRP Enable
HRPCTRL_HRPMODE     equ       1                   ; Mode Select
HRPCTRL_SHTEN       equ       2                   ; Shutdown Pin Enable
HRPCTRL_SHTIE       equ       3                   ; SHTDWN Interrupt Enable
HRPCTRL_SHTIF       equ       4                   ; SHTDWN Interrupt Flag
HRPCTRL_HRPOE       equ       5                   ; HRP Output Enable
HRPCTRL_SHTLVL      equ       6                   ; SHTDWN Pin Level
; bit position masks
mHRPCTRL_HRPEN      equ       %00000001
mHRPCTRL_HRPMODE    equ       %00000010
mHRPCTRL_SHTEN      equ       %00000100
mHRPCTRL_SHTIE      equ       %00001000
mHRPCTRL_SHTIF      equ       %00010000
mHRPCTRL_HRPOE      equ       %00100000
mHRPCTRL_SHTLVL     equ       %01000000


;*** HRPDC - HRP Duty Cycle Registers
HRPDC               equ       $00000052           ;*** HRPDC - HRP Duty Cycle Registers


;*** HRPDCH - HRP Duty Cycle Registers High
HRPDCH              equ       $00000052           ;*** HRPDCH - HRP Duty Cycle Registers High


;*** HRPDCL - HRP Duty Cycle Registers Low
HRPDCL              equ       $00000053           ;*** HRPDCL - HRP Duty Cycle Registers Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPDCL_STEP0        equ       0                   ; Dithering Step Value Bit 0
HRPDCL_STEP1        equ       1                   ; Dithering Step Value Bit 1
HRPDCL_STEP2        equ       2                   ; Dithering Step Value Bit 2
HRPDCL_STEP3        equ       3                   ; Dithering Step Value Bit 3
HRPDCL_STEP4        equ       4                   ; Dithering Step Value Bit 4
HRPDCL_DC0          equ       5                   ; Duty Cycle Value Bit 0
HRPDCL_DC1          equ       6                   ; Duty Cycle Value Bit 1
HRPDCL_DC2          equ       7                   ; Duty Cycle Value Bit 2
; bit position masks
mHRPDCL_STEP0       equ       %00000001
mHRPDCL_STEP1       equ       %00000010
mHRPDCL_STEP2       equ       %00000100
mHRPDCL_STEP3       equ       %00001000
mHRPDCL_STEP4       equ       %00010000
mHRPDCL_DC0         equ       %00100000
mHRPDCL_DC1         equ       %01000000
mHRPDCL_DC2         equ       %10000000


;*** HRPPER - HRP Period Registers
HRPPER              equ       $00000054           ;*** HRPPER - HRP Period Registers


;*** HRPPERH - HRP Period Registers High
HRPPERH             equ       $00000054           ;*** HRPPERH - HRP Period Registers High


;*** HRPPERL - HRP Period Registers Low
HRPPERL             equ       $00000055           ;*** HRPPERL - HRP Period Registers Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPPERL_STEP0       equ       0                   ; Dithering Step Value Bit 0
HRPPERL_STEP1       equ       1                   ; Dithering Step Value Bit 1
HRPPERL_STEP2       equ       2                   ; Dithering Step Value Bit 2
HRPPERL_STEP3       equ       3                   ; Dithering Step Value Bit 3
HRPPERL_STEP4       equ       4                   ; Dithering Step Value Bit 4
HRPPERL_P0          equ       5                   ; Period Value Bit 0
HRPPERL_P1          equ       6                   ; Period Value Bit 1
HRPPERL_P2          equ       7                   ; Period Value Bit 2
; bit position masks
mHRPPERL_STEP0      equ       %00000001
mHRPPERL_STEP1      equ       %00000010
mHRPPERL_STEP2      equ       %00000100
mHRPPERL_STEP3      equ       %00001000
mHRPPERL_STEP4      equ       %00010000
mHRPPERL_P0         equ       %00100000
mHRPPERL_P1         equ       %01000000
mHRPPERL_P2         equ       %10000000


;*** HRPDT - HRP Dead Time Register
HRPDT               equ       $00000056           ;*** HRPDT - HRP Dead Time Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPDT_DT0           equ       0                   ; HRP Dead Time Bit 0
HRPDT_DT1           equ       1                   ; HRP Dead Time Bit 1
HRPDT_DT2           equ       2                   ; HRP Dead Time Bit 2
HRPDT_DT3           equ       3                   ; HRP Dead Time Bit 3
HRPDT_DT4           equ       4                   ; HRP Dead Time Bit 4
HRPDT_DT5           equ       5                   ; HRP Dead Time Bit 5
HRPDT_DT6           equ       6                   ; HRP Dead Time Bit 6
HRPDT_DT7           equ       7                   ; HRP Dead Time Bit 7
; bit position masks
mHRPDT_DT0          equ       %00000001
mHRPDT_DT1          equ       %00000010
mHRPDT_DT2          equ       %00000100
mHRPDT_DT3          equ       %00001000
mHRPDT_DT4          equ       %00010000
mHRPDT_DT5          equ       %00100000
mHRPDT_DT6          equ       %01000000
mHRPDT_DT7          equ       %10000000


;*** HRPTB - HRP Timebase Register
HRPTB               equ       $00000057           ;*** HRPTB - HRP Timebase Register


;*** HRPTBH - HRP Timebase Register High
HRPTBH              equ       $00000057           ;*** HRPTBH - HRP Timebase Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPTBH_TB8          equ       0                   ; HRP Timebase Bit 8
HRPTBH_TB9          equ       1                   ; HRP Timebase Bit 9
HRPTBH_TB10         equ       2                   ; HRP Timebase Bit 10
HRPTBH_TB11         equ       3                   ; HRP Timebase Bit 11
HRPTBH_TB12         equ       4                   ; HRP Timebase Bit 12
HRPTBH_TB13         equ       5                   ; HRP Timebase Bit 13
HRPTBH_TB14         equ       6                   ; HRP Timebase Bit 14
HRPTBH_TB15         equ       7                   ; HRP Timebase Bit 15
; bit position masks
mHRPTBH_TB8         equ       %00000001
mHRPTBH_TB9         equ       %00000010
mHRPTBH_TB10        equ       %00000100
mHRPTBH_TB11        equ       %00001000
mHRPTBH_TB12        equ       %00010000
mHRPTBH_TB13        equ       %00100000
mHRPTBH_TB14        equ       %01000000
mHRPTBH_TB15        equ       %10000000


;*** HRPTBL - HRP Timebase Register Low
HRPTBL              equ       $00000058           ;*** HRPTBL - HRP Timebase Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPTBL_TB0          equ       0                   ; HRP Timebase Bit 0
HRPTBL_TB1          equ       1                   ; HRP Timebase Bit 1
HRPTBL_TB2          equ       2                   ; HRP Timebase Bit 2
HRPTBL_TB3          equ       3                   ; HRP Timebase Bit 3
HRPTBL_TB4          equ       4                   ; HRP Timebase Bit 4
HRPTBL_TB5          equ       5                   ; HRP Timebase Bit 5
HRPTBL_TB6          equ       6                   ; HRP Timebase Bit 6
HRPTBL_TB7          equ       7                   ; HRP Timebase Bit 7
; bit position masks
mHRPTBL_TB0         equ       %00000001
mHRPTBL_TB1         equ       %00000010
mHRPTBL_TB2         equ       %00000100
mHRPTBL_TB3         equ       %00001000
mHRPTBL_TB4         equ       %00010000
mHRPTBL_TB5         equ       %00100000
mHRPTBL_TB6         equ       %01000000
mHRPTBL_TB7         equ       %10000000


;*** HRPDCR - Frequency Dithering Control Register
HRPDCR              equ       $00000059           ;*** HRPDCR - Frequency Dithering Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
HRPDCR_SEL0         equ       0                   ; Dithering Step/Modulus Select Bit 0
HRPDCR_SEL1         equ       1                   ; Dithering Step/Modulus Select Bit 1
HRPDCR_SEL2         equ       2                   ; Dithering Step/Modulus Select Bit 2
HRPDCR_CLKSRC       equ       3                   ; Dithering Clock Source
; bit position masks
mHRPDCR_SEL0        equ       %00000001
mHRPDCR_SEL1        equ       %00000010
mHRPDCR_SEL2        equ       %00000100
mHRPDCR_CLKSRC      equ       %00001000


;*** BSR - Break Status Register
BSR                 equ       $0000FE00           ;*** BSR - Break Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BSR_SBSW            equ       1                   ; SIM Break Stop/Wait
; bit position masks
mBSR_SBSW           equ       %00000010


;*** SRSR - SIM Reset Status Register
SRSR                equ       $0000FE01           ;*** SRSR - SIM Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRSR_LVI            equ       1                   ; Low-Voltage Inhibit Reset Bit
SRSR_MODRST         equ       2                   ; Monitor Mode Entry Module Reset Bit
SRSR_ILAD           equ       3                   ; Illegal Address Reset Bit
SRSR_ILOP           equ       4                   ; Illegal Opcode Reset Bit
SRSR_COP            equ       5                   ; Computer Operating Properly Reset Bit
SRSR_PIN            equ       6                   ; External Reset Bit
SRSR_POR            equ       7                   ; Power-On Reset Bit
; bit position masks
mSRSR_LVI           equ       %00000010
mSRSR_MODRST        equ       %00000100
mSRSR_ILAD          equ       %00001000
mSRSR_ILOP          equ       %00010000
mSRSR_COP           equ       %00100000
mSRSR_PIN           equ       %01000000
mSRSR_POR           equ       %10000000


;*** BRKAR - Break Auxiliary Register
BRKAR               equ       $0000FE02           ;*** BRKAR - Break Auxiliary Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKAR_BDCOP         equ       0                   ; Break Disable COP Bit
; bit position masks
mBRKAR_BDCOP        equ       %00000001


;*** BFCR - Break Flag Control Register
BFCR                equ       $0000FE03           ;*** BFCR - Break Flag Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BFCR_BCFE           equ       7                   ; Break Clear Flag Enable Bit
; bit position masks
mBFCR_BCFE          equ       %10000000


;*** FLCR - FLASH Control Register
FLCR                equ       $0000FE08           ;*** FLCR - FLASH Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLCR_PGM            equ       0                   ; Program Control Bit
FLCR_ERASE          equ       1                   ; Erase Control Bit
FLCR_MASS           equ       2                   ; Mass Erase Control Bit
FLCR_HVEN           equ       3                   ; High-Voltage Enable Bit
; bit position masks
mFLCR_PGM           equ       %00000001
mFLCR_ERASE         equ       %00000010
mFLCR_MASS          equ       %00000100
mFLCR_HVEN          equ       %00001000


;*** BRK - Break Address Register
BRK                 equ       $0000FE09           ;*** BRK - Break Address Register


;*** BRKH - Break Address Register High
BRKH                equ       $0000FE09           ;*** BRKH - Break Address Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKH_BIT8           equ       0                   ; Break Address Register Bit 8
BRKH_BIT9           equ       1                   ; Break Address Register Bit 9
BRKH_BIT10          equ       2                   ; Break Address Register Bit 10
BRKH_BIT11          equ       3                   ; Break Address Register Bit 11
BRKH_BIT12          equ       4                   ; Break Address Register Bit 12
BRKH_BIT13          equ       5                   ; Break Address Register Bit 13
BRKH_BIT14          equ       6                   ; Break Address Register Bit 14
BRKH_BIT15          equ       7                   ; Break Address Register Bit 15
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
BRKL                equ       $0000FE0A           ;*** BRKL - Break Address Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKL_BIT0           equ       0                   ; Break Address Register Bit 0
BRKL_BIT1           equ       1                   ; Break Address Register Bit 1
BRKL_BIT2           equ       2                   ; Break Address Register Bit 2
BRKL_BIT3           equ       3                   ; Break Address Register Bit 3
BRKL_BIT4           equ       4                   ; Break Address Register Bit 4
BRKL_BIT5           equ       5                   ; Break Address Register Bit 5
BRKL_BIT6           equ       6                   ; Break Address Register Bit 6
BRKL_BIT7           equ       7                   ; Break Address Register Bit 7
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
BRKSCR              equ       $0000FE0B           ;*** BRKSCR - Break Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BRKSCR_BRKA         equ       6                   ; Break Active Bit
BRKSCR_BRKE         equ       7                   ; Break Enable Bit
; bit position masks
mBRKSCR_BRKA        equ       %01000000
mBRKSCR_BRKE        equ       %10000000


;*** LVISR - LVI Status Register
LVISR               equ       $0000FE0C           ;*** LVISR - LVI Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LVISR_LVIOUT        equ       7                   ; LVI Output Bit
; bit position masks
mLVISR_LVIOUT       equ       %10000000


;*** FLBPR - FLASH Block Protect Register
FLBPR               equ       $0000FF7E           ;*** FLBPR - FLASH Block Protect Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FLBPR_BPR0          equ       0                   ; FLASH Block Protect Bit 0
FLBPR_BPR1          equ       1                   ; FLASH Block Protect Bit 1
FLBPR_BPR2          equ       2                   ; FLASH Block Protect Bit 2
FLBPR_BPR3          equ       3                   ; FLASH Block Protect Bit 3
FLBPR_BPR4          equ       4                   ; FLASH Block Protect Bit 4
FLBPR_BPR5          equ       5                   ; FLASH Block Protect Bit 5
FLBPR_BPR6          equ       6                   ; FLASH Block Protect Bit 6
FLBPR_BPR7          equ       7                   ; FLASH Block Protect Bit 7
; bit position masks
mFLBPR_BPR0         equ       %00000001
mFLBPR_BPR1         equ       %00000010
mFLBPR_BPR2         equ       %00000100
mFLBPR_BPR3         equ       %00001000
mFLBPR_BPR4         equ       %00010000
mFLBPR_BPR5         equ       %00100000
mFLBPR_BPR6         equ       %01000000
mFLBPR_BPR7         equ       %10000000


;*** NVOSCTRIM - Oscillator Trim Register (trimmed at the factory)
NVOSCTRIM           equ       $0000FFC0           ;*** NVOSCTRIM - Oscillator Trim Register (trimmed at the factory)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOSCTRIM_TRIM0     equ       0                   ; Internal Oscillator Trim Factor Bit 0
NVOSCTRIM_TRIM1     equ       1                   ; Internal Oscillator Trim Factor Bit 1
NVOSCTRIM_TRIM2     equ       2                   ; Internal Oscillator Trim Factor Bit 2
NVOSCTRIM_TRIM3     equ       3                   ; Internal Oscillator Trim Factor Bit 3
NVOSCTRIM_TRIM4     equ       4                   ; Internal Oscillator Trim Factor Bit 4
NVOSCTRIM_TRIM5     equ       5                   ; Internal Oscillator Trim Factor Bit 5
NVOSCTRIM_TRIM6     equ       6                   ; Internal Oscillator Trim Factor Bit 6
NVOSCTRIM_TRIM7     equ       7                   ; Internal Oscillator Trim Factor Bit 7
; bit position masks
mNVOSCTRIM_TRIM0    equ       %00000001
mNVOSCTRIM_TRIM1    equ       %00000010
mNVOSCTRIM_TRIM2    equ       %00000100
mNVOSCTRIM_TRIM3    equ       %00001000
mNVOSCTRIM_TRIM4    equ       %00010000
mNVOSCTRIM_TRIM5    equ       %00100000
mNVOSCTRIM_TRIM6    equ       %01000000
mNVOSCTRIM_TRIM7    equ       %10000000


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
