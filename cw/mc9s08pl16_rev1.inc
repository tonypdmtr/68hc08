;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08PL16_44, version 3.00.000 (RegistersPrg V2.33)

; ###################################################################
;     Filename  : mc9s08pl16.inc
;     Processor : MC9S08PL16CLD
;     FileFormat: V2.33
;     DataSheet : MC9S08PT16RM Rev. 0 Draft B, 10/2011
;     Compiler  : CodeWarrior compiler
;     Date/Time : 2/2/2012, 4:51 PM
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;      - 15.09.2010, V2.33 :
;               - Empty union is not generated for data overlapping registers, cause there is no bit access
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000C000
ROM_END             equ       $0000FF6F
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000083F
XROM                equ       $0000FF80
XROM_END            equ       $0000FFAF
EEPROM              equ       $00003100
EEPROM_END          equ       $000031FF
;
Vnvm                equ       $0000FFB0
VReserved38         equ       $0000FFB2
Vkbi0               equ       $0000FFB4
VReserved36         equ       $0000FFB6
Vrtc                equ       $0000FFB8
VReserved34         equ       $0000FFBA
VReserved33         equ       $0000FFBC
VReserved32         equ       $0000FFBE
VReserved31         equ       $0000FFC0
VReserved30         equ       $0000FFC2
VReserved29         equ       $0000FFC4
Vsci1tx             equ       $0000FFC6
Vsci1rx             equ       $0000FFC8
Vsci1err            equ       $0000FFCA
Vsci0tx             equ       $0000FFCC
Vsci0rx             equ       $0000FFCE
Vsci0err            equ       $0000FFD0
Vadc                equ       $0000FFD2
VReserved21         equ       $0000FFD4
VReserved20         equ       $0000FFD6
Vmtim0              equ       $0000FFD8
Vftm0ovf            equ       $0000FFDA
Vftm0ch1            equ       $0000FFDC
Vftm0ch0            equ       $0000FFDE
VReserved15         equ       $0000FFE0
VReserved14         equ       $0000FFE2
VReserved13         equ       $0000FFE4
Vftm2ovf            equ       $0000FFE6
Vftm2ch5            equ       $0000FFE8
Vftm2ch4            equ       $0000FFEA
Vftm2ch3            equ       $0000FFEC
Vftm2ch2            equ       $0000FFEE
Vftm2ch1            equ       $0000FFF0
Vftm2ch0            equ       $0000FFF2
Vftm2flt            equ       $0000FFF4
Vclk                equ       $0000FFF6
Vlvw                equ       $0000FFF8
Virq_wdog           equ       $0000FFFA
Vswi                equ       $0000FFFC
Vreset              equ       $0000FFFE
;


;*** PORT_PTAD - Port A Data Register
PORT_PTAD           equ       $00000000           ;*** PORT_PTAD - Port A Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAD_PTAD0     equ       0
PORT_PTAD_PTAD1     equ       1
PORT_PTAD_PTAD2     equ       2
PORT_PTAD_PTAD3     equ       3
PORT_PTAD_PTAD4     equ       4
PORT_PTAD_PTAD5     equ       5
PORT_PTAD_PTAD6     equ       6
PORT_PTAD_PTAD7     equ       7
; bit position masks
mPORT_PTAD_PTAD0    equ       %00000001
mPORT_PTAD_PTAD1    equ       %00000010
mPORT_PTAD_PTAD2    equ       %00000100
mPORT_PTAD_PTAD3    equ       %00001000
mPORT_PTAD_PTAD4    equ       %00010000
mPORT_PTAD_PTAD5    equ       %00100000
mPORT_PTAD_PTAD6    equ       %01000000
mPORT_PTAD_PTAD7    equ       %10000000


;*** PORT_PTBD - Port B Data Register
PORT_PTBD           equ       $00000001           ;*** PORT_PTBD - Port B Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBD_PTBD0     equ       0
PORT_PTBD_PTBD1     equ       1
PORT_PTBD_PTBD2     equ       2
PORT_PTBD_PTBD3     equ       3
PORT_PTBD_PTBD4     equ       4
PORT_PTBD_PTBD5     equ       5
PORT_PTBD_PTBD6     equ       6
PORT_PTBD_PTBD7     equ       7
; bit position masks
mPORT_PTBD_PTBD0    equ       %00000001
mPORT_PTBD_PTBD1    equ       %00000010
mPORT_PTBD_PTBD2    equ       %00000100
mPORT_PTBD_PTBD3    equ       %00001000
mPORT_PTBD_PTBD4    equ       %00010000
mPORT_PTBD_PTBD5    equ       %00100000
mPORT_PTBD_PTBD6    equ       %01000000
mPORT_PTBD_PTBD7    equ       %10000000


;*** PORT_PTCD - Port C Data Register
PORT_PTCD           equ       $00000002           ;*** PORT_PTCD - Port C Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCD_PTCD0     equ       0
PORT_PTCD_PTCD1     equ       1
PORT_PTCD_PTCD2     equ       2
PORT_PTCD_PTCD3     equ       3
PORT_PTCD_PTCD4     equ       4
PORT_PTCD_PTCD5     equ       5
PORT_PTCD_PTCD6     equ       6
PORT_PTCD_PTCD7     equ       7
; bit position masks
mPORT_PTCD_PTCD0    equ       %00000001
mPORT_PTCD_PTCD1    equ       %00000010
mPORT_PTCD_PTCD2    equ       %00000100
mPORT_PTCD_PTCD3    equ       %00001000
mPORT_PTCD_PTCD4    equ       %00010000
mPORT_PTCD_PTCD5    equ       %00100000
mPORT_PTCD_PTCD6    equ       %01000000
mPORT_PTCD_PTCD7    equ       %10000000


;*** PORT_PTDD - Port D Data Register
PORT_PTDD           equ       $00000003           ;*** PORT_PTDD - Port D Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDD_PTDD0     equ       0
PORT_PTDD_PTDD1     equ       1
PORT_PTDD_PTDD2     equ       2
PORT_PTDD_PTDD3     equ       3
PORT_PTDD_PTDD4     equ       4
PORT_PTDD_PTDD5     equ       5
PORT_PTDD_PTDD6     equ       6
PORT_PTDD_PTDD7     equ       7
; bit position masks
mPORT_PTDD_PTDD0    equ       %00000001
mPORT_PTDD_PTDD1    equ       %00000010
mPORT_PTDD_PTDD2    equ       %00000100
mPORT_PTDD_PTDD3    equ       %00001000
mPORT_PTDD_PTDD4    equ       %00010000
mPORT_PTDD_PTDD5    equ       %00100000
mPORT_PTDD_PTDD6    equ       %01000000
mPORT_PTDD_PTDD7    equ       %10000000


;*** PORT_PTED - Port E Data Register
PORT_PTED           equ       $00000004           ;*** PORT_PTED - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTED_PTED0     equ       0
PORT_PTED_PTED1     equ       1
PORT_PTED_PTED2     equ       2
PORT_PTED_PTED3     equ       3
PORT_PTED_PTED4     equ       4
; bit position masks
mPORT_PTED_PTED0    equ       %00000001
mPORT_PTED_PTED1    equ       %00000010
mPORT_PTED_PTED2    equ       %00000100
mPORT_PTED_PTED3    equ       %00001000
mPORT_PTED_PTED4    equ       %00010000


;*** ADC_SC1 - Status and Control Register 1
ADC_SC1             equ       $00000010           ;*** ADC_SC1 - Status and Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC1_ADCH0       equ       0                   ; Input Channel Select, bit 0
ADC_SC1_ADCH1       equ       1                   ; Input Channel Select, bit 1
ADC_SC1_ADCH2       equ       2                   ; Input Channel Select, bit 2
ADC_SC1_ADCH3       equ       3                   ; Input Channel Select, bit 3
ADC_SC1_ADCH4       equ       4                   ; Input Channel Select, bit 4
ADC_SC1_ADCO        equ       5                   ; Continuous Conversion Enable
ADC_SC1_AIEN        equ       6                   ; Interrupt Enable
ADC_SC1_COCO        equ       7                   ; Conversion Complete Flag
; bit position masks
mADC_SC1_ADCH0      equ       %00000001
mADC_SC1_ADCH1      equ       %00000010
mADC_SC1_ADCH2      equ       %00000100
mADC_SC1_ADCH3      equ       %00001000
mADC_SC1_ADCH4      equ       %00010000
mADC_SC1_ADCO       equ       %00100000
mADC_SC1_AIEN       equ       %01000000
mADC_SC1_COCO       equ       %10000000


;*** ADC_SC2 - Status and Control Register 2
ADC_SC2             equ       $00000011           ;*** ADC_SC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC2_FFULL       equ       2                   ; Result FIFO full
ADC_SC2_FEMPTY      equ       3                   ; Result FIFO empty
ADC_SC2_ACFGT       equ       4                   ; Compare Function Greater Than Enable
ADC_SC2_ACFE        equ       5                   ; Compare Function Enable
ADC_SC2_ADTRG       equ       6                   ; Conversion Trigger Select
ADC_SC2_ADACT       equ       7                   ; Conversion Active
; bit position masks
mADC_SC2_FFULL      equ       %00000100
mADC_SC2_FEMPTY     equ       %00001000
mADC_SC2_ACFGT      equ       %00010000
mADC_SC2_ACFE       equ       %00100000
mADC_SC2_ADTRG      equ       %01000000
mADC_SC2_ADACT      equ       %10000000


;*** ADC_SC3 - Status and Control Register 3
ADC_SC3             equ       $00000012           ;*** ADC_SC3 - Status and Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC3_ADICLK0     equ       0                   ; Input Clock Select, bit 0
ADC_SC3_ADICLK1     equ       1                   ; Input Clock Select, bit 1
ADC_SC3_MODE0       equ       2                   ; Conversion Mode Selection, bit 0
ADC_SC3_MODE1       equ       3                   ; Conversion Mode Selection, bit 1
ADC_SC3_ADLSMP      equ       4                   ; Long Sample Time Configuration
ADC_SC3_ADIV0       equ       5                   ; Clock Divide Select, bit 0
ADC_SC3_ADIV1       equ       6                   ; Clock Divide Select, bit 1
ADC_SC3_ADLPC       equ       7                   ; Low-Power Configuration
; bit position masks
mADC_SC3_ADICLK0    equ       %00000001
mADC_SC3_ADICLK1    equ       %00000010
mADC_SC3_MODE0      equ       %00000100
mADC_SC3_MODE1      equ       %00001000
mADC_SC3_ADLSMP     equ       %00010000
mADC_SC3_ADIV0      equ       %00100000
mADC_SC3_ADIV1      equ       %01000000
mADC_SC3_ADLPC      equ       %10000000


;*** ADC_SC4 - Status and Control Register 4
ADC_SC4             equ       $00000013           ;*** ADC_SC4 - Status and Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC4_AFDEP0      equ       0                   ; FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared,
ADC_SC4_AFDEP1      equ       1                   ; FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared,
ADC_SC4_AFDEP2      equ       2                   ; FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared,
ADC_SC4_ACFSEL      equ       5                   ; Compare function select OR/AND when the FIFO function is enabled (AFDEP > 0) .When this bit
ADC_SC4_ASCANE      equ       6                   ; FIFO Scan Mode Enable
; bit position masks
mADC_SC4_AFDEP0     equ       %00000001
mADC_SC4_AFDEP1     equ       %00000010
mADC_SC4_AFDEP2     equ       %00000100
mADC_SC4_ACFSEL     equ       %00100000
mADC_SC4_ASCANE     equ       %01000000


;*** ADC_R - Data Result Register
ADC_R               equ       $00000014           ;*** ADC_R - Data Result Register


;*** ADC_RH - Conversion Result High Register
ADC_RH              equ       $00000014           ;*** ADC_RH - Conversion Result High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_RH_ADR0         equ       0                   ; Conversion Result[15:8], bit 0
ADC_RH_ADR1         equ       1                   ; Conversion Result[15:8], bit 1
ADC_RH_ADR2         equ       2                   ; Conversion Result[15:8], bit 2
ADC_RH_ADR3         equ       3                   ; Conversion Result[15:8], bit 3
ADC_RH_ADR4         equ       4                   ; Conversion Result[15:8], bit 4
ADC_RH_ADR5         equ       5                   ; Conversion Result[15:8], bit 5
ADC_RH_ADR6         equ       6                   ; Conversion Result[15:8], bit 6
ADC_RH_ADR7         equ       7                   ; Conversion Result[15:8], bit 7
; bit position masks
mADC_RH_ADR0        equ       %00000001
mADC_RH_ADR1        equ       %00000010
mADC_RH_ADR2        equ       %00000100
mADC_RH_ADR3        equ       %00001000
mADC_RH_ADR4        equ       %00010000
mADC_RH_ADR5        equ       %00100000
mADC_RH_ADR6        equ       %01000000
mADC_RH_ADR7        equ       %10000000


;*** ADC_RL - Conversion Result Low Register
ADC_RL              equ       $00000015           ;*** ADC_RL - Conversion Result Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_RL_ADR0         equ       0                   ; Conversion Result[7:0], bit 0
ADC_RL_ADR1         equ       1                   ; Conversion Result[7:0], bit 1
ADC_RL_ADR2         equ       2                   ; Conversion Result[7:0], bit 2
ADC_RL_ADR3         equ       3                   ; Conversion Result[7:0], bit 3
ADC_RL_ADR4         equ       4                   ; Conversion Result[7:0], bit 4
ADC_RL_ADR5         equ       5                   ; Conversion Result[7:0], bit 5
ADC_RL_ADR6         equ       6                   ; Conversion Result[7:0], bit 6
ADC_RL_ADR7         equ       7                   ; Conversion Result[7:0], bit 7
; bit position masks
mADC_RL_ADR0        equ       %00000001
mADC_RL_ADR1        equ       %00000010
mADC_RL_ADR2        equ       %00000100
mADC_RL_ADR3        equ       %00001000
mADC_RL_ADR4        equ       %00010000
mADC_RL_ADR5        equ       %00100000
mADC_RL_ADR6        equ       %01000000
mADC_RL_ADR7        equ       %10000000


;*** ADC_CV - Compare Value Register
ADC_CV              equ       $00000016           ;*** ADC_CV - Compare Value Register


;*** ADC_CVH - Compare Value High Register
ADC_CVH             equ       $00000016           ;*** ADC_CVH - Compare Value High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_CVH_CV0         equ       0                   ; Conversion Result[15:8], bit 0
ADC_CVH_CV1         equ       1                   ; Conversion Result[15:8], bit 1
ADC_CVH_CV2         equ       2                   ; Conversion Result[15:8], bit 2
ADC_CVH_CV3         equ       3                   ; Conversion Result[15:8], bit 3
ADC_CVH_CV4         equ       4                   ; Conversion Result[15:8], bit 4
ADC_CVH_CV5         equ       5                   ; Conversion Result[15:8], bit 5
ADC_CVH_CV6         equ       6                   ; Conversion Result[15:8], bit 6
ADC_CVH_CV7         equ       7                   ; Conversion Result[15:8], bit 7
; bit position masks
mADC_CVH_CV0        equ       %00000001
mADC_CVH_CV1        equ       %00000010
mADC_CVH_CV2        equ       %00000100
mADC_CVH_CV3        equ       %00001000
mADC_CVH_CV4        equ       %00010000
mADC_CVH_CV5        equ       %00100000
mADC_CVH_CV6        equ       %01000000
mADC_CVH_CV7        equ       %10000000


;*** ADC_CVL - Compare Value Low Register
ADC_CVL             equ       $00000017           ;*** ADC_CVL - Compare Value Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_CVL_CV0         equ       0                   ; Conversion Result[7:0], bit 0
ADC_CVL_CV1         equ       1                   ; Conversion Result[7:0], bit 1
ADC_CVL_CV2         equ       2                   ; Conversion Result[7:0], bit 2
ADC_CVL_CV3         equ       3                   ; Conversion Result[7:0], bit 3
ADC_CVL_CV4         equ       4                   ; Conversion Result[7:0], bit 4
ADC_CVL_CV5         equ       5                   ; Conversion Result[7:0], bit 5
ADC_CVL_CV6         equ       6                   ; Conversion Result[7:0], bit 6
ADC_CVL_CV7         equ       7                   ; Conversion Result[7:0], bit 7
; bit position masks
mADC_CVL_CV0        equ       %00000001
mADC_CVL_CV1        equ       %00000010
mADC_CVL_CV2        equ       %00000100
mADC_CVL_CV3        equ       %00001000
mADC_CVL_CV4        equ       %00010000
mADC_CVL_CV5        equ       %00100000
mADC_CVL_CV6        equ       %01000000
mADC_CVL_CV7        equ       %10000000


;*** MTIM0_SC - MTIM Status and Control Register
MTIM0_SC            equ       $00000018           ;*** MTIM0_SC - MTIM Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM0_SC_TSTP       equ       4                   ; MTIM Counter Stop
MTIM0_SC_TRST       equ       5                   ; MTIM Counter Reset
MTIM0_SC_TOIE       equ       6                   ; MTIM Overflow Interrupt Enable
MTIM0_SC_TOF        equ       7                   ; MTIM Overflow Flag
; bit position masks
mMTIM0_SC_TSTP      equ       %00010000
mMTIM0_SC_TRST      equ       %00100000
mMTIM0_SC_TOIE      equ       %01000000
mMTIM0_SC_TOF       equ       %10000000


;*** MTIM0_CLK - MTIM Clock Configuration Register
MTIM0_CLK           equ       $00000019           ;*** MTIM0_CLK - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM0_CLK_PS0       equ       0                   ; Clock Source Prescaler, bit 0
MTIM0_CLK_PS1       equ       1                   ; Clock Source Prescaler, bit 1
MTIM0_CLK_PS2       equ       2                   ; Clock Source Prescaler, bit 2
MTIM0_CLK_PS3       equ       3                   ; Clock Source Prescaler, bit 3
MTIM0_CLK_CLKS0     equ       4                   ; Clock Source Select, bit 0
MTIM0_CLK_CLKS1     equ       5                   ; Clock Source Select, bit 1
; bit position masks
mMTIM0_CLK_PS0      equ       %00000001
mMTIM0_CLK_PS1      equ       %00000010
mMTIM0_CLK_PS2      equ       %00000100
mMTIM0_CLK_PS3      equ       %00001000
mMTIM0_CLK_CLKS0    equ       %00010000
mMTIM0_CLK_CLKS1    equ       %00100000


;*** MTIM0_CNT - MTIM Counter Register
MTIM0_CNT           equ       $0000001A           ;*** MTIM0_CNT - MTIM Counter Register


;*** MTIM0_MOD - MTIM Modulo Register
MTIM0_MOD           equ       $0000001B           ;*** MTIM0_MOD - MTIM Modulo Register


;*** FTM0_SC - Status and Control
FTM0_SC             equ       $00000020           ;*** FTM0_SC - Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_SC_PS0         equ       0                   ; Prescale Factor Selection, bit 0
FTM0_SC_PS1         equ       1                   ; Prescale Factor Selection, bit 1
FTM0_SC_PS2         equ       2                   ; Prescale Factor Selection, bit 2
FTM0_SC_CLKS0       equ       3                   ; Clock Source Selection, bit 0
FTM0_SC_CLKS1       equ       4                   ; Clock Source Selection, bit 1
FTM0_SC_CPWMS       equ       5                   ; Center-aligned PWM Select
FTM0_SC_TOIE        equ       6                   ; Timer Overflow Interrupt Enable
FTM0_SC_TOF         equ       7                   ; Timer Overflow Flag
; bit position masks
mFTM0_SC_PS0        equ       %00000001
mFTM0_SC_PS1        equ       %00000010
mFTM0_SC_PS2        equ       %00000100
mFTM0_SC_CLKS0      equ       %00001000
mFTM0_SC_CLKS1      equ       %00010000
mFTM0_SC_CPWMS      equ       %00100000
mFTM0_SC_TOIE       equ       %01000000
mFTM0_SC_TOF        equ       %10000000


;*** FTM0_CNT - FTM0 Timer Counter Register
FTM0_CNT            equ       $00000021           ;*** FTM0_CNT - FTM0 Timer Counter Register


;*** FTM0_CNTH - Counter High
FTM0_CNTH           equ       $00000021           ;*** FTM0_CNTH - Counter High


;*** FTM0_CNTL - Counter Low
FTM0_CNTL           equ       $00000022           ;*** FTM0_CNTL - Counter Low


;*** FTM0_MOD - FTM0 Timer Counter Modulo Register
FTM0_MOD            equ       $00000023           ;*** FTM0_MOD - FTM0 Timer Counter Modulo Register


;*** FTM0_MODH - Modulo High
FTM0_MODH           equ       $00000023           ;*** FTM0_MODH - Modulo High


;*** FTM0_MODL - Modulo Low
FTM0_MODL           equ       $00000024           ;*** FTM0_MODL - Modulo Low


;*** FTM0_C0SC - Channel Status and Control
FTM0_C0SC           equ       $00000025           ;*** FTM0_C0SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C0SC_ELSA      equ       2                   ; Edge or Level Select
FTM0_C0SC_ELSB      equ       3                   ; Edge or Level Select
FTM0_C0SC_MSA       equ       4                   ; Channel Mode Select
FTM0_C0SC_MSB       equ       5                   ; Channel Mode Select
FTM0_C0SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM0_C0SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM0_C0SC_ELSA     equ       %00000100
mFTM0_C0SC_ELSB     equ       %00001000
mFTM0_C0SC_MSA      equ       %00010000
mFTM0_C0SC_MSB      equ       %00100000
mFTM0_C0SC_CHIE     equ       %01000000
mFTM0_C0SC_CHF      equ       %10000000


;*** FTM0_C0V - FTM0 Timer Channel 0 Value Register
FTM0_C0V            equ       $00000026           ;*** FTM0_C0V - FTM0 Timer Channel 0 Value Register


;*** FTM0_C0VH - Channel Value High
FTM0_C0VH           equ       $00000026           ;*** FTM0_C0VH - Channel Value High


;*** FTM0_C0VL - Channel Value Low
FTM0_C0VL           equ       $00000027           ;*** FTM0_C0VL - Channel Value Low


;*** FTM0_C1SC - Channel Status and Control
FTM0_C1SC           equ       $00000028           ;*** FTM0_C1SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C1SC_ELSA      equ       2                   ; Edge or Level Select
FTM0_C1SC_ELSB      equ       3                   ; Edge or Level Select
FTM0_C1SC_MSA       equ       4                   ; Channel Mode Select
FTM0_C1SC_MSB       equ       5                   ; Channel Mode Select
FTM0_C1SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM0_C1SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM0_C1SC_ELSA     equ       %00000100
mFTM0_C1SC_ELSB     equ       %00001000
mFTM0_C1SC_MSA      equ       %00010000
mFTM0_C1SC_MSB      equ       %00100000
mFTM0_C1SC_CHIE     equ       %01000000
mFTM0_C1SC_CHF      equ       %10000000


;*** FTM0_C1V - FTM0 Timer Channel 1 Value Register
FTM0_C1V            equ       $00000029           ;*** FTM0_C1V - FTM0 Timer Channel 1 Value Register


;*** FTM0_C1VH - Channel Value High
FTM0_C1VH           equ       $00000029           ;*** FTM0_C1VH - Channel Value High


;*** FTM0_C1VL - Channel Value Low
FTM0_C1VL           equ       $0000002A           ;*** FTM0_C1VL - Channel Value Low


;*** IRQ_SC - Interrupt Pin Request Status and Control Register
IRQ_SC              equ       $0000003B           ;*** IRQ_SC - Interrupt Pin Request Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQ_SC_IRQMOD       equ       0                   ; IRQ Detection Mode
IRQ_SC_IRQIE        equ       1                   ; IRQ Interrupt Enable
IRQ_SC_IRQACK       equ       2                   ; IRQ Acknowledge
IRQ_SC_IRQF         equ       3                   ; IRQ Flag
IRQ_SC_IRQPE        equ       4                   ; IRQ Pin Enable
IRQ_SC_IRQEDG       equ       5                   ; Interrupt Request (IRQ) Edge Select
IRQ_SC_IRQPDD       equ       6                   ; Interrupt Request (IRQ) Pull Device Disable
; bit position masks
mIRQ_SC_IRQMOD      equ       %00000001
mIRQ_SC_IRQIE       equ       %00000010
mIRQ_SC_IRQACK      equ       %00000100
mIRQ_SC_IRQF        equ       %00001000
mIRQ_SC_IRQPE       equ       %00010000
mIRQ_SC_IRQEDG      equ       %00100000
mIRQ_SC_IRQPDD      equ       %01000000


;*** KBI0_SC - KBI Status and Control Register
KBI0_SC             equ       $0000003C           ;*** KBI0_SC - KBI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI0_SC_KBMOD       equ       0                   ; KBI Detection Mode
KBI0_SC_KBIE        equ       1                   ; KBI Interrupt Enable
KBI0_SC_KBACK       equ       2                   ; KBI Acknowledge
KBI0_SC_KBF         equ       3                   ; KBI Interrupt Flag
; bit position masks
mKBI0_SC_KBMOD      equ       %00000001
mKBI0_SC_KBIE       equ       %00000010
mKBI0_SC_KBACK      equ       %00000100
mKBI0_SC_KBF        equ       %00001000


;*** IPC_SC - IPC Status and Control Register
IPC_SC              equ       $0000003E           ;*** IPC_SC - IPC Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_SC_IPM0         equ       0                   ; Interrupt Priority Mask, bit 0
IPC_SC_IPM1         equ       1                   ; Interrupt Priority Mask, bit 1
IPC_SC_PULIPM       equ       3                   ; Pull IPM from IPMPS
IPC_SC_PSF          equ       4                   ; Pseudo Stack Full
IPC_SC_PSE          equ       5                   ; Pseudo Stack Empty
IPC_SC_IPCE         equ       7                   ; Interrupt Priority Controller Enable
; bit position masks
mIPC_SC_IPM0        equ       %00000001
mIPC_SC_IPM1        equ       %00000010
mIPC_SC_PULIPM      equ       %00001000
mIPC_SC_PSF         equ       %00010000
mIPC_SC_PSE         equ       %00100000
mIPC_SC_IPCE        equ       %10000000


;*** IPC_IPMPS - Interrupt Priority Mask Pseudo Stack Register
IPC_IPMPS           equ       $0000003F           ;*** IPC_IPMPS - Interrupt Priority Mask Pseudo Stack Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_IPMPS_IPM00     equ       0                   ; Interrupt Priority Mask pseudo stack position 0, bit 0
IPC_IPMPS_IPM01     equ       1                   ; Interrupt Priority Mask pseudo stack position 0, bit 1
IPC_IPMPS_IPM10     equ       2                   ; Interrupt Priority Mask pseudo stack position 1, bit 0
IPC_IPMPS_IPM11     equ       3                   ; Interrupt Priority Mask pseudo stack position 1, bit 1
IPC_IPMPS_IPM20     equ       4                   ; Interrupt Priority Mask pseudo stack position 2, bit 0
IPC_IPMPS_IPM21     equ       5                   ; Interrupt Priority Mask pseudo stack position 2, bit 1
IPC_IPMPS_IPM30     equ       6                   ; Interrupt Priority Mask pseudo stack position 3, bit 0
IPC_IPMPS_IPM31     equ       7                   ; Interrupt Priority Mask pseudo stack position 3, bit 1
; bit position masks
mIPC_IPMPS_IPM00    equ       %00000001
mIPC_IPMPS_IPM01    equ       %00000010
mIPC_IPMPS_IPM10    equ       %00000100
mIPC_IPMPS_IPM11    equ       %00001000
mIPC_IPMPS_IPM20    equ       %00010000
mIPC_IPMPS_IPM21    equ       %00100000
mIPC_IPMPS_IPM30    equ       %01000000
mIPC_IPMPS_IPM31    equ       %10000000


;*** SYS_SRS - System Reset Status Register
SYS_SRS             equ       $00003000           ;*** SYS_SRS - System Reset Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SRS_LVD         equ       1                   ; Low Voltage Detect
SYS_SRS_LOC         equ       2                   ; Internal Clock Source Module Reset
SYS_SRS_ILAD        equ       3                   ; Illegal Address
SYS_SRS_ILOP        equ       4                   ; Illegal Opcode
SYS_SRS_WDOG        equ       5                   ; Watchdog (WDOG)
SYS_SRS_PIN         equ       6                   ; External Reset Pin
SYS_SRS_POR         equ       7                   ; Power-On Reset
; bit position masks
mSYS_SRS_LVD        equ       %00000010
mSYS_SRS_LOC        equ       %00000100
mSYS_SRS_ILAD       equ       %00001000
mSYS_SRS_ILOP       equ       %00010000
mSYS_SRS_WDOG       equ       %00100000
mSYS_SRS_PIN        equ       %01000000
mSYS_SRS_POR        equ       %10000000


;*** SYS_SBDFR - System Background Debug Force Reset Register
SYS_SBDFR           equ       $00003001           ;*** SYS_SBDFR - System Background Debug Force Reset Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SBDFR_BDFR      equ       0                   ; Background Debug Force Reset
; bit position masks
mSYS_SBDFR_BDFR     equ       %00000001


;*** SYS_SDID - System Device Identification Register
SYS_SDID            equ       $00003002           ;*** SYS_SDID - System Device Identification Register


;*** SYS_SDIDH - System Device Identification Register: High
SYS_SDIDH           equ       $00003002           ;*** SYS_SDIDH - System Device Identification Register: High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SDIDH_ID0       equ       0                   ; Part Identification Number, bit 0
SYS_SDIDH_ID1       equ       1                   ; Part Identification Number, bit 1
SYS_SDIDH_ID2       equ       2                   ; Part Identification Number, bit 2
SYS_SDIDH_ID3       equ       3                   ; Part Identification Number, bit 3
; bit position masks
mSYS_SDIDH_ID0      equ       %00000001
mSYS_SDIDH_ID1      equ       %00000010
mSYS_SDIDH_ID2      equ       %00000100
mSYS_SDIDH_ID3      equ       %00001000


;*** SYS_SDIDL - System Device Identification Register: Low
SYS_SDIDL           equ       $00003003           ;*** SYS_SDIDL - System Device Identification Register: Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SDIDL_ID0       equ       0                   ; Part Identification Number, bit 0
SYS_SDIDL_ID1       equ       1                   ; Part Identification Number, bit 1
SYS_SDIDL_ID2       equ       2                   ; Part Identification Number, bit 2
SYS_SDIDL_ID3       equ       3                   ; Part Identification Number, bit 3
SYS_SDIDL_ID4       equ       4                   ; Part Identification Number, bit 4
SYS_SDIDL_ID5       equ       5                   ; Part Identification Number, bit 5
SYS_SDIDL_ID6       equ       6                   ; Part Identification Number, bit 6
SYS_SDIDL_ID7       equ       7                   ; Part Identification Number, bit 7
; bit position masks
mSYS_SDIDL_ID0      equ       %00000001
mSYS_SDIDL_ID1      equ       %00000010
mSYS_SDIDL_ID2      equ       %00000100
mSYS_SDIDL_ID3      equ       %00001000
mSYS_SDIDL_ID4      equ       %00010000
mSYS_SDIDL_ID5      equ       %00100000
mSYS_SDIDL_ID6      equ       %01000000
mSYS_SDIDL_ID7      equ       %10000000


;*** SYS_SOPT1 - System Options Register 1
SYS_SOPT1           equ       $00003004           ;*** SYS_SOPT1 - System Options Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT1_STOPE     equ       0                   ; Stop Mode Enable
SYS_SOPT1_FWAKE     equ       1                   ; Fast Wakeup Enable
SYS_SOPT1_RSTPE     equ       2                   ; RESET Pin Enable
SYS_SOPT1_BKGDPE    equ       3                   ; Background Debug Mode Pin Enable
SYS_SOPT1_FTM2PS    equ       4                   ; FTM2 Port Pin Select
SYS_SOPT1_SCI0PS    equ       7                   ; SCI0 Pin Select
; bit position masks
mSYS_SOPT1_STOPE    equ       %00000001
mSYS_SOPT1_FWAKE    equ       %00000010
mSYS_SOPT1_RSTPE    equ       %00000100
mSYS_SOPT1_BKGDPE   equ       %00001000
mSYS_SOPT1_FTM2PS   equ       %00010000
mSYS_SOPT1_SCI0PS   equ       %10000000


;*** SYS_SOPT2 - System Options Register 2
SYS_SOPT2           equ       $00003005           ;*** SYS_SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT2_ADHWTS0   equ       0                   ; ADC Hardware Trigger Source, bit 0
SYS_SOPT2_ADHWTS1   equ       1                   ; ADC Hardware Trigger Source, bit 1
SYS_SOPT2_RXDCE     equ       4                   ; SCI0 RxD Capture Select
SYS_SOPT2_FTMSYNC   equ       6                   ; FTM2 Synchronization Select
SYS_SOPT2_TXDME     equ       7                   ; SCI0 TxD Modulation Select
; bit position masks
mSYS_SOPT2_ADHWTS0  equ       %00000001
mSYS_SOPT2_ADHWTS1  equ       %00000010
mSYS_SOPT2_RXDCE    equ       %00010000
mSYS_SOPT2_FTMSYNC  equ       %01000000
mSYS_SOPT2_TXDME    equ       %10000000


;*** SYS_SOPT3 - System Options Register 3
SYS_SOPT3           equ       $00003006           ;*** SYS_SOPT3 - System Options Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT3_BUSREF0   equ       0                   ; BUS Output select, bit 0
SYS_SOPT3_BUSREF1   equ       1                   ; BUS Output select, bit 1
SYS_SOPT3_BUSREF2   equ       2                   ; BUS Output select, bit 2
SYS_SOPT3_CLKOE     equ       3                   ; CLK Output Enable
SYS_SOPT3_FTM0PS    equ       6                   ; FTM0 Pin Select
SYS_SOPT3_DLYACT    equ       7                   ; FTM2 Trigger Delay Active
; bit position masks
mSYS_SOPT3_BUSREF0  equ       %00000001
mSYS_SOPT3_BUSREF1  equ       %00000010
mSYS_SOPT3_BUSREF2  equ       %00000100
mSYS_SOPT3_CLKOE    equ       %00001000
mSYS_SOPT3_FTM0PS   equ       %01000000
mSYS_SOPT3_DLYACT   equ       %10000000


;*** SYS_SOPT4 - System Options Register 4
SYS_SOPT4           equ       $00003007           ;*** SYS_SOPT4 - System Options Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT4_DELAY0    equ       0                   ; FTM2 Trigger Delay, bit 0
SYS_SOPT4_DELAY1    equ       1                   ; FTM2 Trigger Delay, bit 1
SYS_SOPT4_DELAY2    equ       2                   ; FTM2 Trigger Delay, bit 2
SYS_SOPT4_DELAY3    equ       3                   ; FTM2 Trigger Delay, bit 3
SYS_SOPT4_DELAY4    equ       4                   ; FTM2 Trigger Delay, bit 4
SYS_SOPT4_DELAY5    equ       5                   ; FTM2 Trigger Delay, bit 5
SYS_SOPT4_DELAY6    equ       6                   ; FTM2 Trigger Delay, bit 6
SYS_SOPT4_DELAY7    equ       7                   ; FTM2 Trigger Delay, bit 7
; bit position masks
mSYS_SOPT4_DELAY0   equ       %00000001
mSYS_SOPT4_DELAY1   equ       %00000010
mSYS_SOPT4_DELAY2   equ       %00000100
mSYS_SOPT4_DELAY3   equ       %00001000
mSYS_SOPT4_DELAY4   equ       %00010000
mSYS_SOPT4_DELAY5   equ       %00100000
mSYS_SOPT4_DELAY6   equ       %01000000
mSYS_SOPT4_DELAY7   equ       %10000000


;*** SCG_C1 - System Clock Gating Control 1 Register
SCG_C1              equ       $0000300C           ;*** SCG_C1 - System Clock Gating Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C1_RTC          equ       0                   ; RTC Clock Gate Control
SCG_C1_MTIM0        equ       1                   ; MTIM0 Clock Gate Control
SCG_C1_FTM0         equ       5                   ; FTM0 Clock Gate Control
SCG_C1_FTM2         equ       7                   ; FTM2 Clock Gate Control
; bit position masks
mSCG_C1_RTC         equ       %00000001
mSCG_C1_MTIM0       equ       %00000010
mSCG_C1_FTM0        equ       %00100000
mSCG_C1_FTM2        equ       %10000000


;*** SCG_C2 - System Clock Gating Control 2 Register
SCG_C2              equ       $0000300D           ;*** SCG_C2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C2_IPC          equ       3                   ; IPC Clock Gate Control
SCG_C2_NVM          equ       4                   ; NVM Clock Gate Control
SCG_C2_DBG          equ       5                   ; DBG Clock Gate Control
; bit position masks
mSCG_C2_IPC         equ       %00001000
mSCG_C2_NVM         equ       %00010000
mSCG_C2_DBG         equ       %00100000


;*** SCG_C3 - System Clock Gating Control 3 Register
SCG_C3              equ       $0000300E           ;*** SCG_C3 - System Clock Gating Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C3_SCI0         equ       4                   ; SCI0 Clock Gate Control
SCG_C3_SCI1         equ       5                   ; SCI1 Clock Gate Control
; bit position masks
mSCG_C3_SCI0        equ       %00010000
mSCG_C3_SCI1        equ       %00100000


;*** SCG_C4 - System Clock Gating Control 4 Register
SCG_C4              equ       $0000300F           ;*** SCG_C4 - System Clock Gating Control 4 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C4_KBI0         equ       0                   ; KBI0 Clock Gate Control
SCG_C4_IRQ          equ       3                   ; IRQ Clock Gate Control
SCG_C4_ADC          equ       5                   ; ADC Clock Gate Control
; bit position masks
mSCG_C4_KBI0        equ       %00000001
mSCG_C4_IRQ         equ       %00001000
mSCG_C4_ADC         equ       %00100000


;*** DBG_CAH - Debug Comparator A High Register
DBG_CAH             equ       $00003010           ;*** DBG_CAH - Debug Comparator A High Register


;*** DBG_CAL - Debug Comparator A Low Register
DBG_CAL             equ       $00003011           ;*** DBG_CAL - Debug Comparator A Low Register


;*** DBG_CBH - Debug Comparator B High Register
DBG_CBH             equ       $00003012           ;*** DBG_CBH - Debug Comparator B High Register


;*** DBG_CBL - Debug Comparator B Low Register
DBG_CBL             equ       $00003013           ;*** DBG_CBL - Debug Comparator B Low Register


;*** DBG_CCH - Debug Comparator C High Register
DBG_CCH             equ       $00003014           ;*** DBG_CCH - Debug Comparator C High Register


;*** DBG_CCL - Debug Comparator C Low Register
DBG_CCL             equ       $00003015           ;*** DBG_CCL - Debug Comparator C Low Register


;*** DBG_FH - Debug FIFO High Register
DBG_FH              equ       $00003016           ;*** DBG_FH - Debug FIFO High Register


;*** DBG_FL - Debug FIFO Low Register
DBG_FL              equ       $00003017           ;*** DBG_FL - Debug FIFO Low Register


;*** DBG_CAX - Debug Comparator A Extension Register
DBG_CAX             equ       $00003018           ;*** DBG_CAX - Debug Comparator A Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CAX_RWA         equ       6                   ; Read/Write Comparator A Value Bit
DBG_CAX_RWAEN       equ       7                   ; Read/Write Comparator A Enable Bit
; bit position masks
mDBG_CAX_RWA        equ       %01000000
mDBG_CAX_RWAEN      equ       %10000000


;*** DBG_CBX - Debug Comparator B Extension Register
DBG_CBX             equ       $00003019           ;*** DBG_CBX - Debug Comparator B Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CBX_RWB         equ       6                   ; Read/Write Comparator B Value Bit
DBG_CBX_RWBEN       equ       7                   ; Read/Write Comparator B Enable Bit
; bit position masks
mDBG_CBX_RWB        equ       %01000000
mDBG_CBX_RWBEN      equ       %10000000


;*** DBG_CCX - Debug Comparator C Extension Register
DBG_CCX             equ       $0000301A           ;*** DBG_CCX - Debug Comparator C Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CCX_RWC         equ       6                   ; Read/Write Comparator C Value Bit
DBG_CCX_RWCEN       equ       7                   ; Read/Write Comparator C Enable Bit
; bit position masks
mDBG_CCX_RWC        equ       %01000000
mDBG_CCX_RWCEN      equ       %10000000


;*** DBG_FX - Debug FIFO Extended Information Register
DBG_FX              equ       $0000301B           ;*** DBG_FX - Debug FIFO Extended Information Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_FX_Bit16        equ       0                   ; Extended Address Bit 16
DBG_FX_PPACC        equ       7                   ; PPAGE Access Indicator Bit
; bit position masks
mDBG_FX_Bit16       equ       %00000001
mDBG_FX_PPACC       equ       %10000000


;*** DBG_C - Debug Control Register
DBG_C               equ       $0000301C           ;*** DBG_C - Debug Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_C_LOOP1         equ       0                   ; Select LOOP1 Capture Mode
DBG_C_BRKEN         equ       4                   ; Break Enable Bit
DBG_C_TAG           equ       5                   ; Tag or Force Bit
DBG_C_ARM           equ       6                   ; Arm Bit
DBG_C_DBGEN         equ       7                   ; DBG Module Enable Bit
; bit position masks
mDBG_C_LOOP1        equ       %00000001
mDBG_C_BRKEN        equ       %00010000
mDBG_C_TAG          equ       %00100000
mDBG_C_ARM          equ       %01000000
mDBG_C_DBGEN        equ       %10000000


;*** DBG_T - Debug Trigger Register
DBG_T               equ       $0000301D           ;*** DBG_T - Debug Trigger Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_T_TRG0          equ       0                   ; Trigger Mode Bits, bit 0
DBG_T_TRG1          equ       1                   ; Trigger Mode Bits, bit 1
DBG_T_TRG2          equ       2                   ; Trigger Mode Bits, bit 2
DBG_T_TRG3          equ       3                   ; Trigger Mode Bits, bit 3
DBG_T_BEGIN         equ       6                   ; Begin/End Trigger Bit
DBG_T_TRGSEL        equ       7                   ; Trigger Selection Bit
; bit position masks
mDBG_T_TRG0         equ       %00000001
mDBG_T_TRG1         equ       %00000010
mDBG_T_TRG2         equ       %00000100
mDBG_T_TRG3         equ       %00001000
mDBG_T_BEGIN        equ       %01000000
mDBG_T_TRGSEL       equ       %10000000


;*** DBG_S - Debug Status Register
DBG_S               equ       $0000301E           ;*** DBG_S - Debug Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_S_ARMF          equ       0                   ; Arm Flag Bit
DBG_S_CF            equ       5                   ; Trigger C Match Bit
DBG_S_BF            equ       6                   ; Trigger B Match Bit
DBG_S_AF            equ       7                   ; Trigger A Match Bit
; bit position masks
mDBG_S_ARMF         equ       %00000001
mDBG_S_CF           equ       %00100000
mDBG_S_BF           equ       %01000000
mDBG_S_AF           equ       %10000000


;*** DBG_CNT - Debug Count Status Register
DBG_CNT             equ       $0000301F           ;*** DBG_CNT - Debug Count Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CNT_CNT         equ       0                   ; FIFO Valid Count Bitss
; bit position masks
mDBG_CNT_CNT        equ       %00001111


;*** NVM_FCLKDIV - Flash Clock Divider Register
NVM_FCLKDIV         equ       $00003020           ;*** NVM_FCLKDIV - Flash Clock Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCLKDIV_FDIV0   equ       0                   ; Clock Divider Bits, bit 0
NVM_FCLKDIV_FDIV1   equ       1                   ; Clock Divider Bits, bit 1
NVM_FCLKDIV_FDIV2   equ       2                   ; Clock Divider Bits, bit 2
NVM_FCLKDIV_FDIV3   equ       3                   ; Clock Divider Bits, bit 3
NVM_FCLKDIV_FDIV4   equ       4                   ; Clock Divider Bits, bit 4
NVM_FCLKDIV_FDIV5   equ       5                   ; Clock Divider Bits, bit 5
NVM_FCLKDIV_FDIVLCK equ       6                   ; Clock Divider Locked
NVM_FCLKDIV_FDIVLD  equ       7                   ; Clock Divider Loaded
; bit position masks
mNVM_FCLKDIV_FDIV0  equ       %00000001
mNVM_FCLKDIV_FDIV1  equ       %00000010
mNVM_FCLKDIV_FDIV2  equ       %00000100
mNVM_FCLKDIV_FDIV3  equ       %00001000
mNVM_FCLKDIV_FDIV4  equ       %00010000
mNVM_FCLKDIV_FDIV5  equ       %00100000
mNVM_FCLKDIV_FDIVLCK equ       %01000000
mNVM_FCLKDIV_FDIVLD equ       %10000000


;*** NVM_FSEC - Flash Security Register
NVM_FSEC            equ       $00003021           ;*** NVM_FSEC - Flash Security Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FSEC_SEC0       equ       0
NVM_FSEC_SEC1       equ       1
NVM_FSEC_KEYEN0     equ       6
NVM_FSEC_KEYEN1     equ       7
; bit position masks
mNVM_FSEC_SEC0      equ       %00000001
mNVM_FSEC_SEC1      equ       %00000010
mNVM_FSEC_KEYEN0    equ       %01000000
mNVM_FSEC_KEYEN1    equ       %10000000


;*** NVM_FCCOBIX - Flash CCOB Index Register
NVM_FCCOBIX         equ       $00003022           ;*** NVM_FCCOBIX - Flash CCOB Index Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCCOBIX_CCOBIX0 equ       0                   ; Common Command Register Index, bit 0
NVM_FCCOBIX_CCOBIX1 equ       1                   ; Common Command Register Index, bit 1
NVM_FCCOBIX_CCOBIX2 equ       2                   ; Common Command Register Index, bit 2
; bit position masks
mNVM_FCCOBIX_CCOBIX0 equ       %00000001
mNVM_FCCOBIX_CCOBIX1 equ       %00000010
mNVM_FCCOBIX_CCOBIX2 equ       %00000100


;*** NVM_FCNFG - Flash Configuration Register
NVM_FCNFG           equ       $00003024           ;*** NVM_FCNFG - Flash Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCNFG_FSFD      equ       0                   ; Force Single Bit Fault Detect
NVM_FCNFG_FDFD      equ       1                   ; Force Double Bit Fault Detect
NVM_FCNFG_IGNSF     equ       4                   ; Ignore Single Bit Fault
NVM_FCNFG_CCIE      equ       7                   ; Command Complete Interrupt Enable
; bit position masks
mNVM_FCNFG_FSFD     equ       %00000001
mNVM_FCNFG_FDFD     equ       %00000010
mNVM_FCNFG_IGNSF    equ       %00010000
mNVM_FCNFG_CCIE     equ       %10000000


;*** NVM_FERCNFG - Flash Error Configuration Register
NVM_FERCNFG         equ       $00003025           ;*** NVM_FERCNFG - Flash Error Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FERCNFG_SFDIE   equ       0                   ; Single Bit Fault Detect Interrupt Enable
NVM_FERCNFG_DFDIE   equ       1                   ; Double Bit Fault Detect Interrupt Enable
; bit position masks
mNVM_FERCNFG_SFDIE  equ       %00000001
mNVM_FERCNFG_DFDIE  equ       %00000010


;*** NVM_FSTAT - Flash Status Register
NVM_FSTAT           equ       $00003026           ;*** NVM_FSTAT - Flash Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FSTAT_MGSTAT0   equ       0
NVM_FSTAT_MGSTAT1   equ       1
NVM_FSTAT_MGBUSY    equ       3                   ; Memory Controller Busy Flag
NVM_FSTAT_FPVIOL    equ       4                   ; Flash Protection Violation Flag
NVM_FSTAT_ACCERR    equ       5                   ; Flash Access Error Flag
NVM_FSTAT_CCIF      equ       7                   ; Command Complete Interrupt Flag
; bit position masks
mNVM_FSTAT_MGSTAT0  equ       %00000001
mNVM_FSTAT_MGSTAT1  equ       %00000010
mNVM_FSTAT_MGBUSY   equ       %00001000
mNVM_FSTAT_FPVIOL   equ       %00010000
mNVM_FSTAT_ACCERR   equ       %00100000
mNVM_FSTAT_CCIF     equ       %10000000


;*** NVM_FERSTAT - Flash Error Status Register
NVM_FERSTAT         equ       $00003027           ;*** NVM_FERSTAT - Flash Error Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FERSTAT_SFDIF   equ       0                   ; Single Bit Fault Detect Interrupt Flag
NVM_FERSTAT_DFDIF   equ       1                   ; Double Bit Fault Detect Interrupt Flag
; bit position masks
mNVM_FERSTAT_SFDIF  equ       %00000001
mNVM_FERSTAT_DFDIF  equ       %00000010


;*** NVM_FPROT - Flash Protection Register
NVM_FPROT           equ       $00003028           ;*** NVM_FPROT - Flash Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FPROT_FPHS0     equ       3
NVM_FPROT_FPHS1     equ       4
NVM_FPROT_FPHDIS    equ       5                   ; Flash Protection Higher Address Range Disable
NVM_FPROT_FPOPEN    equ       7                   ; Flash Protection Operation Enable
; bit position masks
mNVM_FPROT_FPHS0    equ       %00001000
mNVM_FPROT_FPHS1    equ       %00010000
mNVM_FPROT_FPHDIS   equ       %00100000
mNVM_FPROT_FPOPEN   equ       %10000000


;*** NVM_EEPROT - EEPROM Protection Register
NVM_EEPROT          equ       $00003029           ;*** NVM_EEPROT - EEPROM Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_EEPROT_DPS0     equ       0                   ; EEPROM Protection Size, bit 0
NVM_EEPROT_DPS1     equ       1                   ; EEPROM Protection Size, bit 1
NVM_EEPROT_DPS2     equ       2                   ; EEPROM Protection Size, bit 2
NVM_EEPROT_DPOPEN   equ       7                   ; EEPROM Protection Control
; bit position masks
mNVM_EEPROT_DPS0    equ       %00000001
mNVM_EEPROT_DPS1    equ       %00000010
mNVM_EEPROT_DPS2    equ       %00000100
mNVM_EEPROT_DPOPEN  equ       %10000000


;*** NVM_FCCOB - Flash Common Command Object Register
NVM_FCCOB           equ       $0000302A           ;*** NVM_FCCOB - Flash Common Command Object Register


;*** NVM_FCCOBHI - Flash Common Command Object Register:High
NVM_FCCOBHI         equ       $0000302A           ;*** NVM_FCCOBHI - Flash Common Command Object Register:High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCCOBHI_CCOB0   equ       0                   ; Common Command Object Bit 15:8, bit 0
NVM_FCCOBHI_CCOB1   equ       1                   ; Common Command Object Bit 15:8, bit 1
NVM_FCCOBHI_CCOB2   equ       2                   ; Common Command Object Bit 15:8, bit 2
NVM_FCCOBHI_CCOB3   equ       3                   ; Common Command Object Bit 15:8, bit 3
NVM_FCCOBHI_CCOB4   equ       4                   ; Common Command Object Bit 15:8, bit 4
NVM_FCCOBHI_CCOB5   equ       5                   ; Common Command Object Bit 15:8, bit 5
NVM_FCCOBHI_CCOB6   equ       6                   ; Common Command Object Bit 15:8, bit 6
NVM_FCCOBHI_CCOB7   equ       7                   ; Common Command Object Bit 15:8, bit 7
; bit position masks
mNVM_FCCOBHI_CCOB0  equ       %00000001
mNVM_FCCOBHI_CCOB1  equ       %00000010
mNVM_FCCOBHI_CCOB2  equ       %00000100
mNVM_FCCOBHI_CCOB3  equ       %00001000
mNVM_FCCOBHI_CCOB4  equ       %00010000
mNVM_FCCOBHI_CCOB5  equ       %00100000
mNVM_FCCOBHI_CCOB6  equ       %01000000
mNVM_FCCOBHI_CCOB7  equ       %10000000


;*** NVM_FCCOBLO - Flash Common Command Object Register: Low
NVM_FCCOBLO         equ       $0000302B           ;*** NVM_FCCOBLO - Flash Common Command Object Register: Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCCOBLO_CCOB0   equ       0                   ; Common Command Object Bit 7:0, bit 0
NVM_FCCOBLO_CCOB1   equ       1                   ; Common Command Object Bit 7:0, bit 1
NVM_FCCOBLO_CCOB2   equ       2                   ; Common Command Object Bit 7:0, bit 2
NVM_FCCOBLO_CCOB3   equ       3                   ; Common Command Object Bit 7:0, bit 3
NVM_FCCOBLO_CCOB4   equ       4                   ; Common Command Object Bit 7:0, bit 4
NVM_FCCOBLO_CCOB5   equ       5                   ; Common Command Object Bit 7:0, bit 5
NVM_FCCOBLO_CCOB6   equ       6                   ; Common Command Object Bit 7:0, bit 6
NVM_FCCOBLO_CCOB7   equ       7                   ; Common Command Object Bit 7:0, bit 7
; bit position masks
mNVM_FCCOBLO_CCOB0  equ       %00000001
mNVM_FCCOBLO_CCOB1  equ       %00000010
mNVM_FCCOBLO_CCOB2  equ       %00000100
mNVM_FCCOBLO_CCOB3  equ       %00001000
mNVM_FCCOBLO_CCOB4  equ       %00010000
mNVM_FCCOBLO_CCOB5  equ       %00100000
mNVM_FCCOBLO_CCOB6  equ       %01000000
mNVM_FCCOBLO_CCOB7  equ       %10000000


;*** NVM_FOPT - Flash Option Register
NVM_FOPT            equ       $0000302C           ;*** NVM_FOPT - Flash Option Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FOPT_NV0        equ       0                   ; Non-volatile Bits, bit 0
NVM_FOPT_NV1        equ       1                   ; Non-volatile Bits, bit 1
NVM_FOPT_NV2        equ       2                   ; Non-volatile Bits, bit 2
NVM_FOPT_NV3        equ       3                   ; Non-volatile Bits, bit 3
NVM_FOPT_NV4        equ       4                   ; Non-volatile Bits, bit 4
NVM_FOPT_NV5        equ       5                   ; Non-volatile Bits, bit 5
NVM_FOPT_NV6        equ       6                   ; Non-volatile Bits, bit 6
NVM_FOPT_NV7        equ       7                   ; Non-volatile Bits, bit 7
; bit position masks
mNVM_FOPT_NV0       equ       %00000001
mNVM_FOPT_NV1       equ       %00000010
mNVM_FOPT_NV2       equ       %00000100
mNVM_FOPT_NV3       equ       %00001000
mNVM_FOPT_NV4       equ       %00010000
mNVM_FOPT_NV5       equ       %00100000
mNVM_FOPT_NV6       equ       %01000000
mNVM_FOPT_NV7       equ       %10000000


;*** WDOG_CS1 - Watchdog Control and Status Register 1
WDOG_CS1            equ       $00003030           ;*** WDOG_CS1 - Watchdog Control and Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_CS1_STOP       equ       0                   ; Stop Enable
WDOG_CS1_WAIT       equ       1                   ; Wait Enable
WDOG_CS1_DBG        equ       2                   ; Debug Enable
WDOG_CS1_TST0       equ       3                   ; Watchdog Test, bit 0
WDOG_CS1_TST1       equ       4                   ; Watchdog Test, bit 1
WDOG_CS1_UPDATE     equ       5                   ; Allow updates
WDOG_CS1_INT        equ       6                   ; Watchdog Interrupt
WDOG_CS1_EN         equ       7                   ; Watchdog Enable
; bit position masks
mWDOG_CS1_STOP      equ       %00000001
mWDOG_CS1_WAIT      equ       %00000010
mWDOG_CS1_DBG       equ       %00000100
mWDOG_CS1_TST0      equ       %00001000
mWDOG_CS1_TST1      equ       %00010000
mWDOG_CS1_UPDATE    equ       %00100000
mWDOG_CS1_INT       equ       %01000000
mWDOG_CS1_EN        equ       %10000000


;*** WDOG_CS2 - Watchdog Control and Status Register 2
WDOG_CS2            equ       $00003031           ;*** WDOG_CS2 - Watchdog Control and Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_CS2_CLK0       equ       0                   ; Watchdog Clock, bit 0
WDOG_CS2_CLK1       equ       1                   ; Watchdog Clock, bit 1
WDOG_CS2_PRES       equ       4                   ; Watchdog Prescalar
WDOG_CS2_FLG        equ       6                   ; Watchdog Interrupt Flag
WDOG_CS2_WIN        equ       7                   ; Watchdog Window
; bit position masks
mWDOG_CS2_CLK0      equ       %00000001
mWDOG_CS2_CLK1      equ       %00000010
mWDOG_CS2_PRES      equ       %00010000
mWDOG_CS2_FLG       equ       %01000000
mWDOG_CS2_WIN       equ       %10000000


;*** WDOG_CNT - Watchdog Counter Register
WDOG_CNT            equ       $00003032           ;*** WDOG_CNT - Watchdog Counter Register


;*** WDOG_CNTH - Watchdog Counter Register: High
WDOG_CNTH           equ       $00003032           ;*** WDOG_CNTH - Watchdog Counter Register: High


;*** WDOG_CNTL - Watchdog Counter Register: Low
WDOG_CNTL           equ       $00003033           ;*** WDOG_CNTL - Watchdog Counter Register: Low


;*** WDOG_TOVAL - Watchdog Timer Register
WDOG_TOVAL          equ       $00003034           ;*** WDOG_TOVAL - Watchdog Timer Register


;*** WDOG_TOVALH - Watchdog Timeout Value Register: High
WDOG_TOVALH         equ       $00003034           ;*** WDOG_TOVALH - Watchdog Timeout Value Register: High


;*** WDOG_TOVALL - Watchdog Timeout Value Register: Low
WDOG_TOVALL         equ       $00003035           ;*** WDOG_TOVALL - Watchdog Timeout Value Register: Low


;*** WDOG_WIN - Watchdog Window Register
WDOG_WIN            equ       $00003036           ;*** WDOG_WIN - Watchdog Window Register


;*** WDOG_WINH - Watchdog Window Register: High
WDOG_WINH           equ       $00003036           ;*** WDOG_WINH - Watchdog Window Register: High


;*** WDOG_WINL - Watchdog Window Register: Low
WDOG_WINL           equ       $00003037           ;*** WDOG_WINL - Watchdog Window Register: Low


;*** ICS_C1 - ICS Control Register 1
ICS_C1              equ       $00003038           ;*** ICS_C1 - ICS Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C1_IREFSTEN     equ       0                   ; Internal Reference Stop Enable
ICS_C1_IRCLKEN      equ       1                   ; Internal Reference Clock Enable
ICS_C1_IREFS        equ       2                   ; Internal Reference Select
ICS_C1_RDIV0        equ       3                   ; Reference Divider, bit 0
ICS_C1_RDIV1        equ       4                   ; Reference Divider, bit 1
ICS_C1_RDIV2        equ       5                   ; Reference Divider, bit 2
ICS_C1_CLKS0        equ       6                   ; Clock Source Select, bit 0
ICS_C1_CLKS1        equ       7                   ; Clock Source Select, bit 1
; bit position masks
mICS_C1_IREFSTEN    equ       %00000001
mICS_C1_IRCLKEN     equ       %00000010
mICS_C1_IREFS       equ       %00000100
mICS_C1_RDIV0       equ       %00001000
mICS_C1_RDIV1       equ       %00010000
mICS_C1_RDIV2       equ       %00100000
mICS_C1_CLKS0       equ       %01000000
mICS_C1_CLKS1       equ       %10000000


;*** ICS_C2 - ICS Control Register 2
ICS_C2              equ       $00003039           ;*** ICS_C2 - ICS Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C2_LP           equ       4                   ; Low Power Select
ICS_C2_BDIV0        equ       5                   ; Bus Frequency Divider, bit 0
ICS_C2_BDIV1        equ       6                   ; Bus Frequency Divider, bit 1
ICS_C2_BDIV2        equ       7                   ; Bus Frequency Divider, bit 2
; bit position masks
mICS_C2_LP          equ       %00010000
mICS_C2_BDIV0       equ       %00100000
mICS_C2_BDIV1       equ       %01000000
mICS_C2_BDIV2       equ       %10000000


;*** ICS_C3 - ICS Control Register 3
ICS_C3              equ       $0000303A           ;*** ICS_C3 - ICS Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C3_SCTRIM0      equ       0                   ; Slow Internal Reference Clock Trim Setting, bit 0
ICS_C3_SCTRIM1      equ       1                   ; Slow Internal Reference Clock Trim Setting, bit 1
ICS_C3_SCTRIM2      equ       2                   ; Slow Internal Reference Clock Trim Setting, bit 2
ICS_C3_SCTRIM3      equ       3                   ; Slow Internal Reference Clock Trim Setting, bit 3
ICS_C3_SCTRIM4      equ       4                   ; Slow Internal Reference Clock Trim Setting, bit 4
ICS_C3_SCTRIM5      equ       5                   ; Slow Internal Reference Clock Trim Setting, bit 5
ICS_C3_SCTRIM6      equ       6                   ; Slow Internal Reference Clock Trim Setting, bit 6
ICS_C3_SCTRIM7      equ       7                   ; Slow Internal Reference Clock Trim Setting, bit 7
; bit position masks
mICS_C3_SCTRIM0     equ       %00000001
mICS_C3_SCTRIM1     equ       %00000010
mICS_C3_SCTRIM2     equ       %00000100
mICS_C3_SCTRIM3     equ       %00001000
mICS_C3_SCTRIM4     equ       %00010000
mICS_C3_SCTRIM5     equ       %00100000
mICS_C3_SCTRIM6     equ       %01000000
mICS_C3_SCTRIM7     equ       %10000000


;*** ICS_C4 - ICS Control Register 4
ICS_C4              equ       $0000303B           ;*** ICS_C4 - ICS Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C4_SCFTRIM      equ       0                   ; Slow Internal Reference Clock Fine Trim
ICS_C4_CME          equ       5                   ; Clock Monitor Enable
ICS_C4_LOLIE        equ       7                   ; Loss of Lock Interrupt
; bit position masks
mICS_C4_SCFTRIM     equ       %00000001
mICS_C4_CME         equ       %00100000
mICS_C4_LOLIE       equ       %10000000


;*** ICS_S - ICS Status Register
ICS_S               equ       $0000303C           ;*** ICS_S - ICS Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_S_CLKST0        equ       2                   ; Clock Mode Status, bit 0
ICS_S_CLKST1        equ       3                   ; Clock Mode Status, bit 1
ICS_S_IREFST        equ       4                   ; Internal Reference Status
ICS_S_LOCK          equ       6                   ; Lock Status
ICS_S_LOLS          equ       7                   ; Loss of Lock Status
; bit position masks
mICS_S_CLKST0       equ       %00000100
mICS_S_CLKST1       equ       %00001000
mICS_S_IREFST       equ       %00010000
mICS_S_LOCK         equ       %01000000
mICS_S_LOLS         equ       %10000000


;*** ICS_OSCSC - OSC Status and Control Register
ICS_OSCSC           equ       $0000303E           ;*** ICS_OSCSC - OSC Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_OSCSC_OSCINIT   equ       0                   ; OSC Initialization
ICS_OSCSC_HGO       equ       1                   ; High Gain Oscillator Select
ICS_OSCSC_RANGE     equ       2                   ; Frequency Range Select
ICS_OSCSC_OSCOS     equ       4                   ; OSC Output Select
ICS_OSCSC_OSCSTEN   equ       5                   ; OSC Enable in Stop mode
ICS_OSCSC_OSCEN     equ       7                   ; OSC Enable
; bit position masks
mICS_OSCSC_OSCINIT  equ       %00000001
mICS_OSCSC_HGO      equ       %00000010
mICS_OSCSC_RANGE    equ       %00000100
mICS_OSCSC_OSCOS    equ       %00010000
mICS_OSCSC_OSCSTEN  equ       %00100000
mICS_OSCSC_OSCEN    equ       %10000000


;*** PMC_SPMSC1 - System Power Management Status and Control 1 Register
PMC_SPMSC1          equ       $00003040           ;*** PMC_SPMSC1 - System Power Management Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_SPMSC1_BGBE     equ       0                   ; Bandgap Buffer Enable
PMC_SPMSC1_BGBDS    equ       1                   ; Bandgap Buffer Drive Select
PMC_SPMSC1_LVDE     equ       2                   ; Low-Voltage Detect Enable
PMC_SPMSC1_LVDSE    equ       3                   ; Low-Voltage Detect Stop Enable
PMC_SPMSC1_LVDRE    equ       4                   ; Low-Voltage Detect Reset Enable
PMC_SPMSC1_LVWIE    equ       5                   ; Low-Voltage Warning Interrupt Enable
PMC_SPMSC1_LVWACK   equ       6                   ; Low-Voltage Warning Acknowledge
PMC_SPMSC1_LVWF     equ       7                   ; Low-Voltage Warning Flag
; bit position masks
mPMC_SPMSC1_BGBE    equ       %00000001
mPMC_SPMSC1_BGBDS   equ       %00000010
mPMC_SPMSC1_LVDE    equ       %00000100
mPMC_SPMSC1_LVDSE   equ       %00001000
mPMC_SPMSC1_LVDRE   equ       %00010000
mPMC_SPMSC1_LVWIE   equ       %00100000
mPMC_SPMSC1_LVWACK  equ       %01000000
mPMC_SPMSC1_LVWF    equ       %10000000


;*** PMC_SPMSC2 - System Power Management Status and Control 2 Register
PMC_SPMSC2          equ       $00003041           ;*** PMC_SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_SPMSC2_LVWV0    equ       4                   ; Low-Voltage Warning Voltage Select, bit 0
PMC_SPMSC2_LVWV1    equ       5                   ; Low-Voltage Warning Voltage Select, bit 1
PMC_SPMSC2_LVDV     equ       6                   ; Low-Voltage Detect Voltage Select
; bit position masks
mPMC_SPMSC2_LVWV0   equ       %00010000
mPMC_SPMSC2_LVWV1   equ       %00100000
mPMC_SPMSC2_LVDV    equ       %01000000


;*** SYS_ILLAH - Illegal Address Register: High
SYS_ILLAH           equ       $0000304A           ;*** SYS_ILLAH - Illegal Address Register: High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_ILLAH_ADDR0     equ       0                   ; High 8-bit of illegal address, bit 0
SYS_ILLAH_ADDR1     equ       1                   ; High 8-bit of illegal address, bit 1
SYS_ILLAH_ADDR2     equ       2                   ; High 8-bit of illegal address, bit 2
SYS_ILLAH_ADDR3     equ       3                   ; High 8-bit of illegal address, bit 3
SYS_ILLAH_ADDR4     equ       4                   ; High 8-bit of illegal address, bit 4
SYS_ILLAH_ADDR5     equ       5                   ; High 8-bit of illegal address, bit 5
SYS_ILLAH_ADDR6     equ       6                   ; High 8-bit of illegal address, bit 6
SYS_ILLAH_ADDR7     equ       7                   ; High 8-bit of illegal address, bit 7
; bit position masks
mSYS_ILLAH_ADDR0    equ       %00000001
mSYS_ILLAH_ADDR1    equ       %00000010
mSYS_ILLAH_ADDR2    equ       %00000100
mSYS_ILLAH_ADDR3    equ       %00001000
mSYS_ILLAH_ADDR4    equ       %00010000
mSYS_ILLAH_ADDR5    equ       %00100000
mSYS_ILLAH_ADDR6    equ       %01000000
mSYS_ILLAH_ADDR7    equ       %10000000


;*** SYS_ILLAL - Illegal Address Register: Low
SYS_ILLAL           equ       $0000304B           ;*** SYS_ILLAL - Illegal Address Register: Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_ILLAL_ADDR0     equ       0                   ; Low 8-bit of illegal address, bit 0
SYS_ILLAL_ADDR1     equ       1                   ; Low 8-bit of illegal address, bit 1
SYS_ILLAL_ADDR2     equ       2                   ; Low 8-bit of illegal address, bit 2
SYS_ILLAL_ADDR3     equ       3                   ; Low 8-bit of illegal address, bit 3
SYS_ILLAL_ADDR4     equ       4                   ; Low 8-bit of illegal address, bit 4
SYS_ILLAL_ADDR5     equ       5                   ; Low 8-bit of illegal address, bit 5
SYS_ILLAL_ADDR6     equ       6                   ; Low 8-bit of illegal address, bit 6
SYS_ILLAL_ADDR7     equ       7                   ; Low 8-bit of illegal address, bit 7
; bit position masks
mSYS_ILLAL_ADDR0    equ       %00000001
mSYS_ILLAL_ADDR1    equ       %00000010
mSYS_ILLAL_ADDR2    equ       %00000100
mSYS_ILLAL_ADDR3    equ       %00001000
mSYS_ILLAL_ADDR4    equ       %00010000
mSYS_ILLAL_ADDR5    equ       %00100000
mSYS_ILLAL_ADDR6    equ       %01000000
mSYS_ILLAL_ADDR7    equ       %10000000


;*** IPC_ILRS0 - Interrupt Level Setting Registers n
IPC_ILRS0           equ       $00003050           ;*** IPC_ILRS0 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS0_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS0_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS0_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS0_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS0_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS0_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS0_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS0_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS0_ILRn00   equ       %00000001
mIPC_ILRS0_ILRn01   equ       %00000010
mIPC_ILRS0_ILRn10   equ       %00000100
mIPC_ILRS0_ILRn11   equ       %00001000
mIPC_ILRS0_ILRn20   equ       %00010000
mIPC_ILRS0_ILRn21   equ       %00100000
mIPC_ILRS0_ILRn30   equ       %01000000
mIPC_ILRS0_ILRn31   equ       %10000000


;*** IPC_ILRS1 - Interrupt Level Setting Registers n
IPC_ILRS1           equ       $00003051           ;*** IPC_ILRS1 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS1_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS1_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS1_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS1_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS1_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS1_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS1_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS1_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS1_ILRn00   equ       %00000001
mIPC_ILRS1_ILRn01   equ       %00000010
mIPC_ILRS1_ILRn10   equ       %00000100
mIPC_ILRS1_ILRn11   equ       %00001000
mIPC_ILRS1_ILRn20   equ       %00010000
mIPC_ILRS1_ILRn21   equ       %00100000
mIPC_ILRS1_ILRn30   equ       %01000000
mIPC_ILRS1_ILRn31   equ       %10000000


;*** IPC_ILRS2 - Interrupt Level Setting Registers n
IPC_ILRS2           equ       $00003052           ;*** IPC_ILRS2 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS2_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS2_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS2_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS2_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS2_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS2_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS2_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS2_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS2_ILRn00   equ       %00000001
mIPC_ILRS2_ILRn01   equ       %00000010
mIPC_ILRS2_ILRn10   equ       %00000100
mIPC_ILRS2_ILRn11   equ       %00001000
mIPC_ILRS2_ILRn20   equ       %00010000
mIPC_ILRS2_ILRn21   equ       %00100000
mIPC_ILRS2_ILRn30   equ       %01000000
mIPC_ILRS2_ILRn31   equ       %10000000


;*** IPC_ILRS3 - Interrupt Level Setting Registers n
IPC_ILRS3           equ       $00003053           ;*** IPC_ILRS3 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS3_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS3_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS3_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS3_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS3_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS3_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS3_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS3_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS3_ILRn00   equ       %00000001
mIPC_ILRS3_ILRn01   equ       %00000010
mIPC_ILRS3_ILRn10   equ       %00000100
mIPC_ILRS3_ILRn11   equ       %00001000
mIPC_ILRS3_ILRn20   equ       %00010000
mIPC_ILRS3_ILRn21   equ       %00100000
mIPC_ILRS3_ILRn30   equ       %01000000
mIPC_ILRS3_ILRn31   equ       %10000000


;*** IPC_ILRS4 - Interrupt Level Setting Registers n
IPC_ILRS4           equ       $00003054           ;*** IPC_ILRS4 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS4_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS4_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS4_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS4_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS4_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS4_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS4_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS4_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS4_ILRn00   equ       %00000001
mIPC_ILRS4_ILRn01   equ       %00000010
mIPC_ILRS4_ILRn10   equ       %00000100
mIPC_ILRS4_ILRn11   equ       %00001000
mIPC_ILRS4_ILRn20   equ       %00010000
mIPC_ILRS4_ILRn21   equ       %00100000
mIPC_ILRS4_ILRn30   equ       %01000000
mIPC_ILRS4_ILRn31   equ       %10000000


;*** IPC_ILRS5 - Interrupt Level Setting Registers n
IPC_ILRS5           equ       $00003055           ;*** IPC_ILRS5 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS5_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS5_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS5_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS5_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS5_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS5_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS5_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS5_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS5_ILRn00   equ       %00000001
mIPC_ILRS5_ILRn01   equ       %00000010
mIPC_ILRS5_ILRn10   equ       %00000100
mIPC_ILRS5_ILRn11   equ       %00001000
mIPC_ILRS5_ILRn20   equ       %00010000
mIPC_ILRS5_ILRn21   equ       %00100000
mIPC_ILRS5_ILRn30   equ       %01000000
mIPC_ILRS5_ILRn31   equ       %10000000


;*** IPC_ILRS6 - Interrupt Level Setting Registers n
IPC_ILRS6           equ       $00003056           ;*** IPC_ILRS6 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS6_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS6_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS6_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS6_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS6_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS6_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS6_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS6_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS6_ILRn00   equ       %00000001
mIPC_ILRS6_ILRn01   equ       %00000010
mIPC_ILRS6_ILRn10   equ       %00000100
mIPC_ILRS6_ILRn11   equ       %00001000
mIPC_ILRS6_ILRn20   equ       %00010000
mIPC_ILRS6_ILRn21   equ       %00100000
mIPC_ILRS6_ILRn30   equ       %01000000
mIPC_ILRS6_ILRn31   equ       %10000000


;*** IPC_ILRS7 - Interrupt Level Setting Registers n
IPC_ILRS7           equ       $00003057           ;*** IPC_ILRS7 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS7_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS7_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS7_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS7_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS7_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS7_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS7_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS7_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS7_ILRn00   equ       %00000001
mIPC_ILRS7_ILRn01   equ       %00000010
mIPC_ILRS7_ILRn10   equ       %00000100
mIPC_ILRS7_ILRn11   equ       %00001000
mIPC_ILRS7_ILRn20   equ       %00010000
mIPC_ILRS7_ILRn21   equ       %00100000
mIPC_ILRS7_ILRn30   equ       %01000000
mIPC_ILRS7_ILRn31   equ       %10000000


;*** IPC_ILRS8 - Interrupt Level Setting Registers n
IPC_ILRS8           equ       $00003058           ;*** IPC_ILRS8 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS8_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS8_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS8_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS8_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS8_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS8_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS8_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS8_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS8_ILRn00   equ       %00000001
mIPC_ILRS8_ILRn01   equ       %00000010
mIPC_ILRS8_ILRn10   equ       %00000100
mIPC_ILRS8_ILRn11   equ       %00001000
mIPC_ILRS8_ILRn20   equ       %00010000
mIPC_ILRS8_ILRn21   equ       %00100000
mIPC_ILRS8_ILRn30   equ       %01000000
mIPC_ILRS8_ILRn31   equ       %10000000


;*** IPC_ILRS9 - Interrupt Level Setting Registers n
IPC_ILRS9           equ       $00003059           ;*** IPC_ILRS9 - Interrupt Level Setting Registers n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS9_ILRn00    equ       0                   ; Interrupt Level Register for Source n+0, bit 0
IPC_ILRS9_ILRn01    equ       1                   ; Interrupt Level Register for Source n+0, bit 1
IPC_ILRS9_ILRn10    equ       2                   ; Interrupt Level Register for Source n+1, bit 0
IPC_ILRS9_ILRn11    equ       3                   ; Interrupt Level Register for Source n+1, bit 1
IPC_ILRS9_ILRn20    equ       4                   ; Interrupt Level Register for Source n+2, bit 0
IPC_ILRS9_ILRn21    equ       5                   ; Interrupt Level Register for Source n+2, bit 1
IPC_ILRS9_ILRn30    equ       6                   ; Interrupt Level Register for Source n+3, bit 0
IPC_ILRS9_ILRn31    equ       7                   ; Interrupt Level Register for Source n+3, bit 1
; bit position masks
mIPC_ILRS9_ILRn00   equ       %00000001
mIPC_ILRS9_ILRn01   equ       %00000010
mIPC_ILRS9_ILRn10   equ       %00000100
mIPC_ILRS9_ILRn11   equ       %00001000
mIPC_ILRS9_ILRn20   equ       %00010000
mIPC_ILRS9_ILRn21   equ       %00100000
mIPC_ILRS9_ILRn30   equ       %01000000
mIPC_ILRS9_ILRn31   equ       %10000000


;*** RTC_SC1 - RTC Status and Control Register 1
RTC_SC1             equ       $0000306A           ;*** RTC_SC1 - RTC Status and Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_SC1_RTIE        equ       6                   ; Real-Time Interrupt Enable
RTC_SC1_RTIF        equ       7                   ; Real-Time Interrupt Flag
; bit position masks
mRTC_SC1_RTIE       equ       %01000000
mRTC_SC1_RTIF       equ       %10000000


;*** RTC_SC2 - RTC Status and Control Register 2
RTC_SC2             equ       $0000306B           ;*** RTC_SC2 - RTC Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_SC2_RTCPS0      equ       0                   ; Real-Time Clock Prescaler Select, bit 0
RTC_SC2_RTCPS1      equ       1                   ; Real-Time Clock Prescaler Select, bit 1
RTC_SC2_RTCPS2      equ       2                   ; Real-Time Clock Prescaler Select, bit 2
RTC_SC2_RTCLKS0     equ       6                   ; Real-Time Clock Source Select, bit 0
RTC_SC2_RTCLKS1     equ       7                   ; Real-Time Clock Source Select, bit 1
; bit position masks
mRTC_SC2_RTCPS0     equ       %00000001
mRTC_SC2_RTCPS1     equ       %00000010
mRTC_SC2_RTCPS2     equ       %00000100
mRTC_SC2_RTCLKS0    equ       %01000000
mRTC_SC2_RTCLKS1    equ       %10000000


;*** RTC_MOD - RTC Modulo Register
RTC_MOD             equ       $0000306C           ;*** RTC_MOD - RTC Modulo Register


;*** RTC_MODH - RTC Modulo Register: High
RTC_MODH            equ       $0000306C           ;*** RTC_MODH - RTC Modulo Register: High


;*** RTC_MODL - RTC Modulo Register: Low
RTC_MODL            equ       $0000306D           ;*** RTC_MODL - RTC Modulo Register: Low


;*** RTC_CNT - RTC Counter Register
RTC_CNT             equ       $0000306E           ;*** RTC_CNT - RTC Counter Register


;*** RTC_CNTH - RTC Counter Register: High
RTC_CNTH            equ       $0000306E           ;*** RTC_CNTH - RTC Counter Register: High


;*** RTC_CNTL - RTC Counter Register: Low
RTC_CNTL            equ       $0000306F           ;*** RTC_CNTL - RTC Counter Register: Low


;*** KBI0_PE - KBIx Pin Enable Register
KBI0_PE             equ       $0000307C           ;*** KBI0_PE - KBIx Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI0_PE_KBIPE0      equ       0
KBI0_PE_KBIPE1      equ       1
KBI0_PE_KBIPE2      equ       2
KBI0_PE_KBIPE3      equ       3
KBI0_PE_KBIPE4      equ       4
KBI0_PE_KBIPE5      equ       5
KBI0_PE_KBIPE6      equ       6
KBI0_PE_KBIPE7      equ       7
; bit position masks
mKBI0_PE_KBIPE0     equ       %00000001
mKBI0_PE_KBIPE1     equ       %00000010
mKBI0_PE_KBIPE2     equ       %00000100
mKBI0_PE_KBIPE3     equ       %00001000
mKBI0_PE_KBIPE4     equ       %00010000
mKBI0_PE_KBIPE5     equ       %00100000
mKBI0_PE_KBIPE6     equ       %01000000
mKBI0_PE_KBIPE7     equ       %10000000


;*** KBI0_ES - KBIx Edge Select Register
KBI0_ES             equ       $0000307D           ;*** KBI0_ES - KBIx Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI0_ES_KBEDG0      equ       0
KBI0_ES_KBEDG1      equ       1
KBI0_ES_KBEDG2      equ       2
KBI0_ES_KBEDG3      equ       3
KBI0_ES_KBEDG4      equ       4
KBI0_ES_KBEDG5      equ       5
KBI0_ES_KBEDG6      equ       6
KBI0_ES_KBEDG7      equ       7
; bit position masks
mKBI0_ES_KBEDG0     equ       %00000001
mKBI0_ES_KBEDG1     equ       %00000010
mKBI0_ES_KBEDG2     equ       %00000100
mKBI0_ES_KBEDG3     equ       %00001000
mKBI0_ES_KBEDG4     equ       %00010000
mKBI0_ES_KBEDG5     equ       %00100000
mKBI0_ES_KBEDG6     equ       %01000000
mKBI0_ES_KBEDG7     equ       %10000000


;*** SCI0_BD - SCI0 Baud Rate Register
SCI0_BD             equ       $00003080           ;*** SCI0_BD - SCI0 Baud Rate Register


;*** SCI0_BDH - SCI Baud Rate Register: High
SCI0_BDH            equ       $00003080           ;*** SCI0_BDH - SCI Baud Rate Register: High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_BDH_SBR0       equ       0                   ; Baud Rate Modulo Divisor, bit 0
SCI0_BDH_SBR1       equ       1                   ; Baud Rate Modulo Divisor, bit 1
SCI0_BDH_SBR2       equ       2                   ; Baud Rate Modulo Divisor, bit 2
SCI0_BDH_SBR3       equ       3                   ; Baud Rate Modulo Divisor, bit 3
SCI0_BDH_SBR4       equ       4                   ; Baud Rate Modulo Divisor, bit 4
SCI0_BDH_SBNS       equ       5                   ; Stop Bit Number Select
SCI0_BDH_RXEDGIE    equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI0_BDH_LBKDIE     equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI0_BDH_SBR0      equ       %00000001
mSCI0_BDH_SBR1      equ       %00000010
mSCI0_BDH_SBR2      equ       %00000100
mSCI0_BDH_SBR3      equ       %00001000
mSCI0_BDH_SBR4      equ       %00010000
mSCI0_BDH_SBNS      equ       %00100000
mSCI0_BDH_RXEDGIE   equ       %01000000
mSCI0_BDH_LBKDIE    equ       %10000000


;*** SCI0_BDL - SCI Baud Rate Register: Low
SCI0_BDL            equ       $00003081           ;*** SCI0_BDL - SCI Baud Rate Register: Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_BDL_SBR0       equ       0                   ; Baud Rate Modulo Divisor, bit 0
SCI0_BDL_SBR1       equ       1                   ; Baud Rate Modulo Divisor, bit 1
SCI0_BDL_SBR2       equ       2                   ; Baud Rate Modulo Divisor, bit 2
SCI0_BDL_SBR3       equ       3                   ; Baud Rate Modulo Divisor, bit 3
SCI0_BDL_SBR4       equ       4                   ; Baud Rate Modulo Divisor, bit 4
SCI0_BDL_SBR5       equ       5                   ; Baud Rate Modulo Divisor, bit 5
SCI0_BDL_SBR6       equ       6                   ; Baud Rate Modulo Divisor, bit 6
SCI0_BDL_SBR7       equ       7                   ; Baud Rate Modulo Divisor, bit 7
; bit position masks
mSCI0_BDL_SBR0      equ       %00000001
mSCI0_BDL_SBR1      equ       %00000010
mSCI0_BDL_SBR2      equ       %00000100
mSCI0_BDL_SBR3      equ       %00001000
mSCI0_BDL_SBR4      equ       %00010000
mSCI0_BDL_SBR5      equ       %00100000
mSCI0_BDL_SBR6      equ       %01000000
mSCI0_BDL_SBR7      equ       %10000000


;*** SCI0_C1 - SCI Control Register 1
SCI0_C1             equ       $00003082           ;*** SCI0_C1 - SCI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_C1_PT          equ       0                   ; Parity Type
SCI0_C1_PE          equ       1                   ; Parity Enable
SCI0_C1_ILT         equ       2                   ; Idle Line Type Select
SCI0_C1_WAKE        equ       3                   ; Receiver Wakeup Method Select
SCI0_C1_M           equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI0_C1_RSRC        equ       5                   ; Receiver Source Select
SCI0_C1_SCISWAI     equ       6                   ; SCI Stops in Wait Mode
SCI0_C1_LOOPS       equ       7                   ; Loop Mode Select
; bit position masks
mSCI0_C1_PT         equ       %00000001
mSCI0_C1_PE         equ       %00000010
mSCI0_C1_ILT        equ       %00000100
mSCI0_C1_WAKE       equ       %00001000
mSCI0_C1_M          equ       %00010000
mSCI0_C1_RSRC       equ       %00100000
mSCI0_C1_SCISWAI    equ       %01000000
mSCI0_C1_LOOPS      equ       %10000000


;*** SCI0_C2 - SCI Control Register 2
SCI0_C2             equ       $00003083           ;*** SCI0_C2 - SCI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_C2_SBK         equ       0                   ; Send Break
SCI0_C2_RWU         equ       1                   ; Receiver Wakeup Control
SCI0_C2_RE          equ       2                   ; Receiver Enable
SCI0_C2_TE          equ       3                   ; Transmitter Enable
SCI0_C2_ILIE        equ       4                   ; Idle Line Interrupt Enable for IDLE
SCI0_C2_RIE         equ       5                   ; Receiver Interrupt Enable for RDRF
SCI0_C2_TCIE        equ       6                   ; Transmission Complete Interrupt Enable for TC
SCI0_C2_TIE         equ       7                   ; Transmit Interrupt Enable for TDRE
; bit position masks
mSCI0_C2_SBK        equ       %00000001
mSCI0_C2_RWU        equ       %00000010
mSCI0_C2_RE         equ       %00000100
mSCI0_C2_TE         equ       %00001000
mSCI0_C2_ILIE       equ       %00010000
mSCI0_C2_RIE        equ       %00100000
mSCI0_C2_TCIE       equ       %01000000
mSCI0_C2_TIE        equ       %10000000


;*** SCI0_S1 - SCI Status Register 1
SCI0_S1             equ       $00003084           ;*** SCI0_S1 - SCI Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_S1_PF          equ       0                   ; Parity Error Flag
SCI0_S1_FE          equ       1                   ; Framing Error Flag
SCI0_S1_NF          equ       2                   ; Noise Flag
SCI0_S1_OR          equ       3                   ; Receiver Overrun Flag
SCI0_S1_IDLE        equ       4                   ; Idle Line Flag
SCI0_S1_RDRF        equ       5                   ; Receive Data Register Full Flag
SCI0_S1_TC          equ       6                   ; Transmission Complete Flag
SCI0_S1_TDRE        equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI0_S1_PF         equ       %00000001
mSCI0_S1_FE         equ       %00000010
mSCI0_S1_NF         equ       %00000100
mSCI0_S1_OR         equ       %00001000
mSCI0_S1_IDLE       equ       %00010000
mSCI0_S1_RDRF       equ       %00100000
mSCI0_S1_TC         equ       %01000000
mSCI0_S1_TDRE       equ       %10000000


;*** SCI0_S2 - SCI Status Register 2
SCI0_S2             equ       $00003085           ;*** SCI0_S2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_S2_RAF         equ       0                   ; Receiver Active Flag
SCI0_S2_LBKDE       equ       1                   ; LIN Break Detection Enable
SCI0_S2_BRK13       equ       2                   ; Break Character Generation Length
SCI0_S2_RWUID       equ       3                   ; Receive Wake Up Idle Detect
SCI0_S2_RXINV       equ       4                   ; Receive Data Inversion
SCI0_S2_RXEDGIF     equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI0_S2_LBKDIF      equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI0_S2_RAF        equ       %00000001
mSCI0_S2_LBKDE      equ       %00000010
mSCI0_S2_BRK13      equ       %00000100
mSCI0_S2_RWUID      equ       %00001000
mSCI0_S2_RXINV      equ       %00010000
mSCI0_S2_RXEDGIF    equ       %01000000
mSCI0_S2_LBKDIF     equ       %10000000


;*** SCI0_C3 - SCI Control Register 3
SCI0_C3             equ       $00003086           ;*** SCI0_C3 - SCI Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_C3_PEIE        equ       0                   ; Parity Error Interrupt Enable
SCI0_C3_FEIE        equ       1                   ; Framing Error Interrupt Enable
SCI0_C3_NEIE        equ       2                   ; Noise Error Interrupt Enable
SCI0_C3_ORIE        equ       3                   ; Overrun Interrupt Enable
SCI0_C3_TXINV       equ       4                   ; Transmit Data Inversion
SCI0_C3_TXDIR       equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI0_C3_T8          equ       6                   ; Ninth Data Bit for Transmitter
SCI0_C3_R8          equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI0_C3_PEIE       equ       %00000001
mSCI0_C3_FEIE       equ       %00000010
mSCI0_C3_NEIE       equ       %00000100
mSCI0_C3_ORIE       equ       %00001000
mSCI0_C3_TXINV      equ       %00010000
mSCI0_C3_TXDIR      equ       %00100000
mSCI0_C3_T8         equ       %01000000
mSCI0_C3_R8         equ       %10000000


;*** SCI0_D - SCI Data Register
SCI0_D              equ       $00003087           ;*** SCI0_D - SCI Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_D_R0T0         equ       0                   ; Read receive data buffer 0 or write transmit data buffer 0
SCI0_D_R1T1         equ       1                   ; Read receive data buffer 1 or write transmit data buffer 1
SCI0_D_R2T2         equ       2                   ; Read receive data buffer 2 or write transmit data buffer 2
SCI0_D_R3T3         equ       3                   ; Read receive data buffer 3 or write transmit data buffer 3
SCI0_D_R4T4         equ       4                   ; Read receive data buffer 4 or write transmit data buffer 4
SCI0_D_R5T5         equ       5                   ; Read receive data buffer 5 or write transmit data buffer 5
SCI0_D_R6T6         equ       6                   ; Read receive data buffer 6 or write transmit data buffer 6
SCI0_D_R7T7         equ       7                   ; Read receive data buffer 7 or write transmit data buffer 7
; bit position masks
mSCI0_D_R0T0        equ       %00000001
mSCI0_D_R1T1        equ       %00000010
mSCI0_D_R2T2        equ       %00000100
mSCI0_D_R3T3        equ       %00001000
mSCI0_D_R4T4        equ       %00010000
mSCI0_D_R5T5        equ       %00100000
mSCI0_D_R6T6        equ       %01000000
mSCI0_D_R7T7        equ       %10000000


;*** SCI1_BD - SCI1 Baud Rate Register
SCI1_BD             equ       $00003088           ;*** SCI1_BD - SCI1 Baud Rate Register


;*** SCI1_BDH - SCI Baud Rate Register: High
SCI1_BDH            equ       $00003088           ;*** SCI1_BDH - SCI Baud Rate Register: High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_BDH_SBR0       equ       0                   ; Baud Rate Modulo Divisor, bit 0
SCI1_BDH_SBR1       equ       1                   ; Baud Rate Modulo Divisor, bit 1
SCI1_BDH_SBR2       equ       2                   ; Baud Rate Modulo Divisor, bit 2
SCI1_BDH_SBR3       equ       3                   ; Baud Rate Modulo Divisor, bit 3
SCI1_BDH_SBR4       equ       4                   ; Baud Rate Modulo Divisor, bit 4
SCI1_BDH_SBNS       equ       5                   ; Stop Bit Number Select
SCI1_BDH_RXEDGIE    equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1_BDH_LBKDIE     equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1_BDH_SBR0      equ       %00000001
mSCI1_BDH_SBR1      equ       %00000010
mSCI1_BDH_SBR2      equ       %00000100
mSCI1_BDH_SBR3      equ       %00001000
mSCI1_BDH_SBR4      equ       %00010000
mSCI1_BDH_SBNS      equ       %00100000
mSCI1_BDH_RXEDGIE   equ       %01000000
mSCI1_BDH_LBKDIE    equ       %10000000


;*** SCI1_BDL - SCI Baud Rate Register: Low
SCI1_BDL            equ       $00003089           ;*** SCI1_BDL - SCI Baud Rate Register: Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_BDL_SBR0       equ       0                   ; Baud Rate Modulo Divisor, bit 0
SCI1_BDL_SBR1       equ       1                   ; Baud Rate Modulo Divisor, bit 1
SCI1_BDL_SBR2       equ       2                   ; Baud Rate Modulo Divisor, bit 2
SCI1_BDL_SBR3       equ       3                   ; Baud Rate Modulo Divisor, bit 3
SCI1_BDL_SBR4       equ       4                   ; Baud Rate Modulo Divisor, bit 4
SCI1_BDL_SBR5       equ       5                   ; Baud Rate Modulo Divisor, bit 5
SCI1_BDL_SBR6       equ       6                   ; Baud Rate Modulo Divisor, bit 6
SCI1_BDL_SBR7       equ       7                   ; Baud Rate Modulo Divisor, bit 7
; bit position masks
mSCI1_BDL_SBR0      equ       %00000001
mSCI1_BDL_SBR1      equ       %00000010
mSCI1_BDL_SBR2      equ       %00000100
mSCI1_BDL_SBR3      equ       %00001000
mSCI1_BDL_SBR4      equ       %00010000
mSCI1_BDL_SBR5      equ       %00100000
mSCI1_BDL_SBR6      equ       %01000000
mSCI1_BDL_SBR7      equ       %10000000


;*** SCI1_C1 - SCI Control Register 1
SCI1_C1             equ       $0000308A           ;*** SCI1_C1 - SCI Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_C1_PT          equ       0                   ; Parity Type
SCI1_C1_PE          equ       1                   ; Parity Enable
SCI1_C1_ILT         equ       2                   ; Idle Line Type Select
SCI1_C1_WAKE        equ       3                   ; Receiver Wakeup Method Select
SCI1_C1_M           equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI1_C1_RSRC        equ       5                   ; Receiver Source Select
SCI1_C1_SCISWAI     equ       6                   ; SCI Stops in Wait Mode
SCI1_C1_LOOPS       equ       7                   ; Loop Mode Select
; bit position masks
mSCI1_C1_PT         equ       %00000001
mSCI1_C1_PE         equ       %00000010
mSCI1_C1_ILT        equ       %00000100
mSCI1_C1_WAKE       equ       %00001000
mSCI1_C1_M          equ       %00010000
mSCI1_C1_RSRC       equ       %00100000
mSCI1_C1_SCISWAI    equ       %01000000
mSCI1_C1_LOOPS      equ       %10000000


;*** SCI1_C2 - SCI Control Register 2
SCI1_C2             equ       $0000308B           ;*** SCI1_C2 - SCI Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_C2_SBK         equ       0                   ; Send Break
SCI1_C2_RWU         equ       1                   ; Receiver Wakeup Control
SCI1_C2_RE          equ       2                   ; Receiver Enable
SCI1_C2_TE          equ       3                   ; Transmitter Enable
SCI1_C2_ILIE        equ       4                   ; Idle Line Interrupt Enable for IDLE
SCI1_C2_RIE         equ       5                   ; Receiver Interrupt Enable for RDRF
SCI1_C2_TCIE        equ       6                   ; Transmission Complete Interrupt Enable for TC
SCI1_C2_TIE         equ       7                   ; Transmit Interrupt Enable for TDRE
; bit position masks
mSCI1_C2_SBK        equ       %00000001
mSCI1_C2_RWU        equ       %00000010
mSCI1_C2_RE         equ       %00000100
mSCI1_C2_TE         equ       %00001000
mSCI1_C2_ILIE       equ       %00010000
mSCI1_C2_RIE        equ       %00100000
mSCI1_C2_TCIE       equ       %01000000
mSCI1_C2_TIE        equ       %10000000


;*** SCI1_S1 - SCI Status Register 1
SCI1_S1             equ       $0000308C           ;*** SCI1_S1 - SCI Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_S1_PF          equ       0                   ; Parity Error Flag
SCI1_S1_FE          equ       1                   ; Framing Error Flag
SCI1_S1_NF          equ       2                   ; Noise Flag
SCI1_S1_OR          equ       3                   ; Receiver Overrun Flag
SCI1_S1_IDLE        equ       4                   ; Idle Line Flag
SCI1_S1_RDRF        equ       5                   ; Receive Data Register Full Flag
SCI1_S1_TC          equ       6                   ; Transmission Complete Flag
SCI1_S1_TDRE        equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI1_S1_PF         equ       %00000001
mSCI1_S1_FE         equ       %00000010
mSCI1_S1_NF         equ       %00000100
mSCI1_S1_OR         equ       %00001000
mSCI1_S1_IDLE       equ       %00010000
mSCI1_S1_RDRF       equ       %00100000
mSCI1_S1_TC         equ       %01000000
mSCI1_S1_TDRE       equ       %10000000


;*** SCI1_S2 - SCI Status Register 2
SCI1_S2             equ       $0000308D           ;*** SCI1_S2 - SCI Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_S2_RAF         equ       0                   ; Receiver Active Flag
SCI1_S2_LBKDE       equ       1                   ; LIN Break Detection Enable
SCI1_S2_BRK13       equ       2                   ; Break Character Generation Length
SCI1_S2_RWUID       equ       3                   ; Receive Wake Up Idle Detect
SCI1_S2_RXINV       equ       4                   ; Receive Data Inversion
SCI1_S2_RXEDGIF     equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI1_S2_LBKDIF      equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI1_S2_RAF        equ       %00000001
mSCI1_S2_LBKDE      equ       %00000010
mSCI1_S2_BRK13      equ       %00000100
mSCI1_S2_RWUID      equ       %00001000
mSCI1_S2_RXINV      equ       %00010000
mSCI1_S2_RXEDGIF    equ       %01000000
mSCI1_S2_LBKDIF     equ       %10000000


;*** SCI1_C3 - SCI Control Register 3
SCI1_C3             equ       $0000308E           ;*** SCI1_C3 - SCI Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_C3_PEIE        equ       0                   ; Parity Error Interrupt Enable
SCI1_C3_FEIE        equ       1                   ; Framing Error Interrupt Enable
SCI1_C3_NEIE        equ       2                   ; Noise Error Interrupt Enable
SCI1_C3_ORIE        equ       3                   ; Overrun Interrupt Enable
SCI1_C3_TXINV       equ       4                   ; Transmit Data Inversion
SCI1_C3_TXDIR       equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI1_C3_T8          equ       6                   ; Ninth Data Bit for Transmitter
SCI1_C3_R8          equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI1_C3_PEIE       equ       %00000001
mSCI1_C3_FEIE       equ       %00000010
mSCI1_C3_NEIE       equ       %00000100
mSCI1_C3_ORIE       equ       %00001000
mSCI1_C3_TXINV      equ       %00010000
mSCI1_C3_TXDIR      equ       %00100000
mSCI1_C3_T8         equ       %01000000
mSCI1_C3_R8         equ       %10000000


;*** SCI1_D - SCI Data Register
SCI1_D              equ       $0000308F           ;*** SCI1_D - SCI Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_D_R0T0         equ       0                   ; Read receive data buffer 0 or write transmit data buffer 0
SCI1_D_R1T1         equ       1                   ; Read receive data buffer 1 or write transmit data buffer 1
SCI1_D_R2T2         equ       2                   ; Read receive data buffer 2 or write transmit data buffer 2
SCI1_D_R3T3         equ       3                   ; Read receive data buffer 3 or write transmit data buffer 3
SCI1_D_R4T4         equ       4                   ; Read receive data buffer 4 or write transmit data buffer 4
SCI1_D_R5T5         equ       5                   ; Read receive data buffer 5 or write transmit data buffer 5
SCI1_D_R6T6         equ       6                   ; Read receive data buffer 6 or write transmit data buffer 6
SCI1_D_R7T7         equ       7                   ; Read receive data buffer 7 or write transmit data buffer 7
; bit position masks
mSCI1_D_R0T0        equ       %00000001
mSCI1_D_R1T1        equ       %00000010
mSCI1_D_R2T2        equ       %00000100
mSCI1_D_R3T3        equ       %00001000
mSCI1_D_R4T4        equ       %00010000
mSCI1_D_R5T5        equ       %00100000
mSCI1_D_R6T6        equ       %01000000
mSCI1_D_R7T7        equ       %10000000


;*** ADC_APCTL1 - Pin Control 1 Register
ADC_APCTL1          equ       $000030AC           ;*** ADC_APCTL1 - Pin Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_APCTL1_ADPC0    equ       0                   ; ADC Pin Control 0
ADC_APCTL1_ADPC1    equ       1                   ; ADC Pin Control 1
ADC_APCTL1_ADPC2    equ       2                   ; ADC Pin Control 2
ADC_APCTL1_ADPC3    equ       3                   ; ADC Pin Control 3
ADC_APCTL1_ADPC4    equ       4                   ; ADC Pin Control 4
ADC_APCTL1_ADPC5    equ       5                   ; ADC Pin Control 5
ADC_APCTL1_ADPC6    equ       6                   ; ADC Pin Control 6
ADC_APCTL1_ADPC7    equ       7                   ; ADC Pin Control 7
; bit position masks
mADC_APCTL1_ADPC0   equ       %00000001
mADC_APCTL1_ADPC1   equ       %00000010
mADC_APCTL1_ADPC2   equ       %00000100
mADC_APCTL1_ADPC3   equ       %00001000
mADC_APCTL1_ADPC4   equ       %00010000
mADC_APCTL1_ADPC5   equ       %00100000
mADC_APCTL1_ADPC6   equ       %01000000
mADC_APCTL1_ADPC7   equ       %10000000


;*** ADC_APCTL2 - Pin Control 2 Register
ADC_APCTL2          equ       $000030AD           ;*** ADC_APCTL2 - Pin Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_APCTL2_ADPC8    equ       0                   ; ADC Pin Control 8
ADC_APCTL2_ADPC9    equ       1                   ; ADC Pin Control 9
ADC_APCTL2_ADPC10   equ       2                   ; ADC Pin Control 10
ADC_APCTL2_ADPC11   equ       3                   ; ADC Pin Control 11
; bit position masks
mADC_APCTL2_ADPC8   equ       %00000001
mADC_APCTL2_ADPC9   equ       %00000010
mADC_APCTL2_ADPC10  equ       %00000100
mADC_APCTL2_ADPC11  equ       %00001000


;*** PORT_HDRVE - Port High Drive Enable Register
PORT_HDRVE          equ       $000030AF           ;*** PORT_HDRVE - Port High Drive Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_HDRVE_PTB4     equ       0                   ; PTB4
PORT_HDRVE_PTB5     equ       1                   ; PTB5
PORT_HDRVE_PTD0     equ       2                   ; PTD0
PORT_HDRVE_PTD1     equ       3                   ; PTD1
; bit position masks
mPORT_HDRVE_PTB4    equ       %00000001
mPORT_HDRVE_PTB5    equ       %00000010
mPORT_HDRVE_PTD0    equ       %00000100
mPORT_HDRVE_PTD1    equ       %00001000


;*** PORT_PTAOE - Port A Output Enable Register
PORT_PTAOE          equ       $000030B0           ;*** PORT_PTAOE - Port A Output Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAOE_PTAOE0   equ       0                   ; Output Enable for Port A Bit 0
PORT_PTAOE_PTAOE1   equ       1                   ; Output Enable for Port A Bit 1
PORT_PTAOE_PTAOE2   equ       2                   ; Output Enable for Port A Bit 2
PORT_PTAOE_PTAOE3   equ       3                   ; Output Enable for Port A Bit 3
PORT_PTAOE_PTAOE4   equ       4                   ; Output Enable for Port A Bit 4
PORT_PTAOE_PTAOE5   equ       5                   ; Output Enable for Port A Bit 5
PORT_PTAOE_PTAOE6   equ       6                   ; Output Enable for Port A Bit 6
PORT_PTAOE_PTAOE7   equ       7                   ; Output Enable for Port A Bit 7
; bit position masks
mPORT_PTAOE_PTAOE0  equ       %00000001
mPORT_PTAOE_PTAOE1  equ       %00000010
mPORT_PTAOE_PTAOE2  equ       %00000100
mPORT_PTAOE_PTAOE3  equ       %00001000
mPORT_PTAOE_PTAOE4  equ       %00010000
mPORT_PTAOE_PTAOE5  equ       %00100000
mPORT_PTAOE_PTAOE6  equ       %01000000
mPORT_PTAOE_PTAOE7  equ       %10000000


;*** PORT_PTBOE - Port B Output Enable Register
PORT_PTBOE          equ       $000030B1           ;*** PORT_PTBOE - Port B Output Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBOE_PTBOE0   equ       0                   ; Output Enable for Port B Bit 0
PORT_PTBOE_PTBOE1   equ       1                   ; Output Enable for Port B Bit 1
PORT_PTBOE_PTBOE2   equ       2                   ; Output Enable for Port B Bit 2
PORT_PTBOE_PTBOE3   equ       3                   ; Output Enable for Port B Bit 3
PORT_PTBOE_PTBOE4   equ       4                   ; Output Enable for Port B Bit 4
PORT_PTBOE_PTBOE5   equ       5                   ; Output Enable for Port B Bit 5
PORT_PTBOE_PTBOE6   equ       6                   ; Output Enable for Port B Bit 6
PORT_PTBOE_PTBOE7   equ       7                   ; Output Enable for Port B Bit 7
; bit position masks
mPORT_PTBOE_PTBOE0  equ       %00000001
mPORT_PTBOE_PTBOE1  equ       %00000010
mPORT_PTBOE_PTBOE2  equ       %00000100
mPORT_PTBOE_PTBOE3  equ       %00001000
mPORT_PTBOE_PTBOE4  equ       %00010000
mPORT_PTBOE_PTBOE5  equ       %00100000
mPORT_PTBOE_PTBOE6  equ       %01000000
mPORT_PTBOE_PTBOE7  equ       %10000000


;*** PORT_PTCOE - Port C Output Enable Register
PORT_PTCOE          equ       $000030B2           ;*** PORT_PTCOE - Port C Output Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCOE_PTCOE0   equ       0                   ; Output Enable for Port C Bit 0
PORT_PTCOE_PTCOE1   equ       1                   ; Output Enable for Port C Bit 1
PORT_PTCOE_PTCOE2   equ       2                   ; Output Enable for Port C Bit 2
PORT_PTCOE_PTCOE3   equ       3                   ; Output Enable for Port C Bit 3
PORT_PTCOE_PTCOE4   equ       4                   ; Output Enable for Port C Bit 4
PORT_PTCOE_PTCOE5   equ       5                   ; Output Enable for Port C Bit 5
PORT_PTCOE_PTCOE6   equ       6                   ; Output Enable for Port C Bit 6
PORT_PTCOE_PTCOE7   equ       7                   ; Output Enable for Port C Bit 7
; bit position masks
mPORT_PTCOE_PTCOE0  equ       %00000001
mPORT_PTCOE_PTCOE1  equ       %00000010
mPORT_PTCOE_PTCOE2  equ       %00000100
mPORT_PTCOE_PTCOE3  equ       %00001000
mPORT_PTCOE_PTCOE4  equ       %00010000
mPORT_PTCOE_PTCOE5  equ       %00100000
mPORT_PTCOE_PTCOE6  equ       %01000000
mPORT_PTCOE_PTCOE7  equ       %10000000


;*** PORT_PTDOE - Port D Output Enable Register
PORT_PTDOE          equ       $000030B3           ;*** PORT_PTDOE - Port D Output Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDOE_PTDOE0   equ       0                   ; Output Enable for Port D Bit 0
PORT_PTDOE_PTDOE1   equ       1                   ; Output Enable for Port D Bit 1
PORT_PTDOE_PTDOE2   equ       2                   ; Output Enable for Port D Bit 2
PORT_PTDOE_PTDOE3   equ       3                   ; Output Enable for Port D Bit 3
PORT_PTDOE_PTDOE4   equ       4                   ; Output Enable for Port D Bit 4
PORT_PTDOE_PTDOE5   equ       5                   ; Output Enable for Port D Bit 5
PORT_PTDOE_PTDOE6   equ       6                   ; Output Enable for Port D Bit 6
PORT_PTDOE_PTDOE7   equ       7                   ; Output Enable for Port D Bit 7
; bit position masks
mPORT_PTDOE_PTDOE0  equ       %00000001
mPORT_PTDOE_PTDOE1  equ       %00000010
mPORT_PTDOE_PTDOE2  equ       %00000100
mPORT_PTDOE_PTDOE3  equ       %00001000
mPORT_PTDOE_PTDOE4  equ       %00010000
mPORT_PTDOE_PTDOE5  equ       %00100000
mPORT_PTDOE_PTDOE6  equ       %01000000
mPORT_PTDOE_PTDOE7  equ       %10000000


;*** PORT_PTEOE - Port E Output Enable Register
PORT_PTEOE          equ       $000030B4           ;*** PORT_PTEOE - Port E Output Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTEOE_PTEOE0   equ       0                   ; Output Enable for Port E Bit 0
PORT_PTEOE_PTEOE1   equ       1                   ; Output Enable for Port E Bit 1
PORT_PTEOE_PTEOE2   equ       2                   ; Output Enable for Port E Bit 2
PORT_PTEOE_PTEOE3   equ       3                   ; Output Enable for Port E Bit 3
PORT_PTEOE_PTEOE4   equ       4                   ; Output Enable for Port E Bit 4
; bit position masks
mPORT_PTEOE_PTEOE0  equ       %00000001
mPORT_PTEOE_PTEOE1  equ       %00000010
mPORT_PTEOE_PTEOE2  equ       %00000100
mPORT_PTEOE_PTEOE3  equ       %00001000
mPORT_PTEOE_PTEOE4  equ       %00010000


;*** PORT_PTAIE - Port A Input Enable Register
PORT_PTAIE          equ       $000030B8           ;*** PORT_PTAIE - Port A Input Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAIE_PTAIE0   equ       0                   ; Input Enable for Port A Bit 0
PORT_PTAIE_PTAIE1   equ       1                   ; Input Enable for Port A Bit 1
PORT_PTAIE_PTAIE2   equ       2                   ; Input Enable for Port A Bit 2
PORT_PTAIE_PTAIE3   equ       3                   ; Input Enable for Port A Bit 3
PORT_PTAIE_PTAIE5   equ       5                   ; Input Enable for Port A Bit 5
PORT_PTAIE_PTAIE6   equ       6                   ; Input Enable for Port A Bit 6
PORT_PTAIE_PTAIE7   equ       7                   ; Input Enable for Port A Bit 7
; bit position masks
mPORT_PTAIE_PTAIE0  equ       %00000001
mPORT_PTAIE_PTAIE1  equ       %00000010
mPORT_PTAIE_PTAIE2  equ       %00000100
mPORT_PTAIE_PTAIE3  equ       %00001000
mPORT_PTAIE_PTAIE5  equ       %00100000
mPORT_PTAIE_PTAIE6  equ       %01000000
mPORT_PTAIE_PTAIE7  equ       %10000000


;*** PORT_PTBIE - Port B Input Enable Register
PORT_PTBIE          equ       $000030B9           ;*** PORT_PTBIE - Port B Input Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBIE_PTBIE0   equ       0                   ; Input Enable for Port B Bit 0
PORT_PTBIE_PTBIE1   equ       1                   ; Input Enable for Port B Bit 1
PORT_PTBIE_PTBIE2   equ       2                   ; Input Enable for Port B Bit 2
PORT_PTBIE_PTBIE3   equ       3                   ; Input Enable for Port B Bit 3
PORT_PTBIE_PTBIE4   equ       4                   ; Input Enable for Port B Bit 4
PORT_PTBIE_PTBIE5   equ       5                   ; Input Enable for Port B Bit 5
PORT_PTBIE_PTBIE6   equ       6                   ; Input Enable for Port B Bit 6
PORT_PTBIE_PTBIE7   equ       7                   ; Input Enable for Port B Bit 7
; bit position masks
mPORT_PTBIE_PTBIE0  equ       %00000001
mPORT_PTBIE_PTBIE1  equ       %00000010
mPORT_PTBIE_PTBIE2  equ       %00000100
mPORT_PTBIE_PTBIE3  equ       %00001000
mPORT_PTBIE_PTBIE4  equ       %00010000
mPORT_PTBIE_PTBIE5  equ       %00100000
mPORT_PTBIE_PTBIE6  equ       %01000000
mPORT_PTBIE_PTBIE7  equ       %10000000


;*** PORT_PTCIE - Port C Input Enable Register
PORT_PTCIE          equ       $000030BA           ;*** PORT_PTCIE - Port C Input Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCIE_PTCIE0   equ       0                   ; Input Enable for Port C Bit 0
PORT_PTCIE_PTCIE1   equ       1                   ; Input Enable for Port C Bit 1
PORT_PTCIE_PTCIE2   equ       2                   ; Input Enable for Port C Bit 2
PORT_PTCIE_PTCIE3   equ       3                   ; Input Enable for Port C Bit 3
PORT_PTCIE_PTCIE4   equ       4                   ; Input Enable for Port C Bit 4
PORT_PTCIE_PTCIE5   equ       5                   ; Input Enable for Port C Bit 5
PORT_PTCIE_PTCIE6   equ       6                   ; Input Enable for Port C Bit 6
PORT_PTCIE_PTCIE7   equ       7                   ; Input Enable for Port C Bit 7
; bit position masks
mPORT_PTCIE_PTCIE0  equ       %00000001
mPORT_PTCIE_PTCIE1  equ       %00000010
mPORT_PTCIE_PTCIE2  equ       %00000100
mPORT_PTCIE_PTCIE3  equ       %00001000
mPORT_PTCIE_PTCIE4  equ       %00010000
mPORT_PTCIE_PTCIE5  equ       %00100000
mPORT_PTCIE_PTCIE6  equ       %01000000
mPORT_PTCIE_PTCIE7  equ       %10000000


;*** PORT_PTDIE - Port D Input Enable Register
PORT_PTDIE          equ       $000030BB           ;*** PORT_PTDIE - Port D Input Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDIE_PTDIE0   equ       0                   ; Input Enable for Port D Bit 0
PORT_PTDIE_PTDIE1   equ       1                   ; Input Enable for Port D Bit 1
PORT_PTDIE_PTDIE2   equ       2                   ; Input Enable for Port D Bit 2
PORT_PTDIE_PTDIE3   equ       3                   ; Input Enable for Port D Bit 3
PORT_PTDIE_PTDIE4   equ       4                   ; Input Enable for Port D Bit 4
PORT_PTDIE_PTDIE5   equ       5                   ; Input Enable for Port D Bit 5
PORT_PTDIE_PTDIE6   equ       6                   ; Input Enable for Port D Bit 6
PORT_PTDIE_PTDIE7   equ       7                   ; Input Enable for Port D Bit 7
; bit position masks
mPORT_PTDIE_PTDIE0  equ       %00000001
mPORT_PTDIE_PTDIE1  equ       %00000010
mPORT_PTDIE_PTDIE2  equ       %00000100
mPORT_PTDIE_PTDIE3  equ       %00001000
mPORT_PTDIE_PTDIE4  equ       %00010000
mPORT_PTDIE_PTDIE5  equ       %00100000
mPORT_PTDIE_PTDIE6  equ       %01000000
mPORT_PTDIE_PTDIE7  equ       %10000000


;*** PORT_PTEIE - Port E Input Enable Register
PORT_PTEIE          equ       $000030BC           ;*** PORT_PTEIE - Port E Input Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTEIE_PTEIE0   equ       0                   ; Input Enable for Port E Bit 0
PORT_PTEIE_PTEIE1   equ       1                   ; Input Enable for Port E Bit 1
PORT_PTEIE_PTEIE2   equ       2                   ; Input Enable for Port E Bit 2
PORT_PTEIE_PTEIE3   equ       3                   ; Input Enable for Port E Bit 3
PORT_PTEIE_PTEIE4   equ       4                   ; Input Enable for Port E Bit 4
; bit position masks
mPORT_PTEIE_PTEIE0  equ       %00000001
mPORT_PTEIE_PTEIE1  equ       %00000010
mPORT_PTEIE_PTEIE2  equ       %00000100
mPORT_PTEIE_PTEIE3  equ       %00001000
mPORT_PTEIE_PTEIE4  equ       %00010000


;*** FTM2_SC - Status and Control
FTM2_SC             equ       $000030C0           ;*** FTM2_SC - Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_SC_PS0         equ       0                   ; Prescale Factor Selection, bit 0
FTM2_SC_PS1         equ       1                   ; Prescale Factor Selection, bit 1
FTM2_SC_PS2         equ       2                   ; Prescale Factor Selection, bit 2
FTM2_SC_CLKS0       equ       3                   ; Clock Source Selection, bit 0
FTM2_SC_CLKS1       equ       4                   ; Clock Source Selection, bit 1
FTM2_SC_CPWMS       equ       5                   ; Center-aligned PWM Select
FTM2_SC_TOIE        equ       6                   ; Timer Overflow Interrupt Enable
FTM2_SC_TOF         equ       7                   ; Timer Overflow Flag
; bit position masks
mFTM2_SC_PS0        equ       %00000001
mFTM2_SC_PS1        equ       %00000010
mFTM2_SC_PS2        equ       %00000100
mFTM2_SC_CLKS0      equ       %00001000
mFTM2_SC_CLKS1      equ       %00010000
mFTM2_SC_CPWMS      equ       %00100000
mFTM2_SC_TOIE       equ       %01000000
mFTM2_SC_TOF        equ       %10000000


;*** FTM2_CNT - FTM2 Timer Counter Register
FTM2_CNT            equ       $000030C1           ;*** FTM2_CNT - FTM2 Timer Counter Register


;*** FTM2_CNTH - Counter High
FTM2_CNTH           equ       $000030C1           ;*** FTM2_CNTH - Counter High


;*** FTM2_CNTL - Counter Low
FTM2_CNTL           equ       $000030C2           ;*** FTM2_CNTL - Counter Low


;*** FTM2_MOD - FTM2 Timer Counter Modulo Register
FTM2_MOD            equ       $000030C3           ;*** FTM2_MOD - FTM2 Timer Counter Modulo Register


;*** FTM2_MODH - Modulo High
FTM2_MODH           equ       $000030C3           ;*** FTM2_MODH - Modulo High


;*** FTM2_MODL - Modulo Low
FTM2_MODL           equ       $000030C4           ;*** FTM2_MODL - Modulo Low


;*** FTM2_C0SC - Channel Status and Control
FTM2_C0SC           equ       $000030C5           ;*** FTM2_C0SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C0SC_ELSA      equ       2                   ; Edge or Level Select
FTM2_C0SC_ELSB      equ       3                   ; Edge or Level Select
FTM2_C0SC_MSA       equ       4                   ; Channel Mode Select
FTM2_C0SC_MSB       equ       5                   ; Channel Mode Select
FTM2_C0SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM2_C0SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM2_C0SC_ELSA     equ       %00000100
mFTM2_C0SC_ELSB     equ       %00001000
mFTM2_C0SC_MSA      equ       %00010000
mFTM2_C0SC_MSB      equ       %00100000
mFTM2_C0SC_CHIE     equ       %01000000
mFTM2_C0SC_CHF      equ       %10000000


;*** FTM2_C0V - FTM2 Timer Channel 0 Value Register
FTM2_C0V            equ       $000030C6           ;*** FTM2_C0V - FTM2 Timer Channel 0 Value Register


;*** FTM2_C0VH - Channel Value High
FTM2_C0VH           equ       $000030C6           ;*** FTM2_C0VH - Channel Value High


;*** FTM2_C0VL - Channel Value Low
FTM2_C0VL           equ       $000030C7           ;*** FTM2_C0VL - Channel Value Low


;*** FTM2_C1SC - Channel Status and Control
FTM2_C1SC           equ       $000030C8           ;*** FTM2_C1SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C1SC_ELSA      equ       2                   ; Edge or Level Select
FTM2_C1SC_ELSB      equ       3                   ; Edge or Level Select
FTM2_C1SC_MSA       equ       4                   ; Channel Mode Select
FTM2_C1SC_MSB       equ       5                   ; Channel Mode Select
FTM2_C1SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM2_C1SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM2_C1SC_ELSA     equ       %00000100
mFTM2_C1SC_ELSB     equ       %00001000
mFTM2_C1SC_MSA      equ       %00010000
mFTM2_C1SC_MSB      equ       %00100000
mFTM2_C1SC_CHIE     equ       %01000000
mFTM2_C1SC_CHF      equ       %10000000


;*** FTM2_C1V - FTM2 Timer Channel 1 Value Register
FTM2_C1V            equ       $000030C9           ;*** FTM2_C1V - FTM2 Timer Channel 1 Value Register


;*** FTM2_C1VH - Channel Value High
FTM2_C1VH           equ       $000030C9           ;*** FTM2_C1VH - Channel Value High


;*** FTM2_C1VL - Channel Value Low
FTM2_C1VL           equ       $000030CA           ;*** FTM2_C1VL - Channel Value Low


;*** FTM2_C2SC - Channel Status and Control
FTM2_C2SC           equ       $000030CB           ;*** FTM2_C2SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C2SC_ELSA      equ       2                   ; Edge or Level Select
FTM2_C2SC_ELSB      equ       3                   ; Edge or Level Select
FTM2_C2SC_MSA       equ       4                   ; Channel Mode Select
FTM2_C2SC_MSB       equ       5                   ; Channel Mode Select
FTM2_C2SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM2_C2SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM2_C2SC_ELSA     equ       %00000100
mFTM2_C2SC_ELSB     equ       %00001000
mFTM2_C2SC_MSA      equ       %00010000
mFTM2_C2SC_MSB      equ       %00100000
mFTM2_C2SC_CHIE     equ       %01000000
mFTM2_C2SC_CHF      equ       %10000000


;*** FTM2_C2V - FTM2 Timer Channel 2 Value Register
FTM2_C2V            equ       $000030CC           ;*** FTM2_C2V - FTM2 Timer Channel 2 Value Register


;*** FTM2_C2VH - Channel Value High
FTM2_C2VH           equ       $000030CC           ;*** FTM2_C2VH - Channel Value High


;*** FTM2_C2VL - Channel Value Low
FTM2_C2VL           equ       $000030CD           ;*** FTM2_C2VL - Channel Value Low


;*** FTM2_C3SC - Channel Status and Control
FTM2_C3SC           equ       $000030CE           ;*** FTM2_C3SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C3SC_ELSA      equ       2                   ; Edge or Level Select
FTM2_C3SC_ELSB      equ       3                   ; Edge or Level Select
FTM2_C3SC_MSA       equ       4                   ; Channel Mode Select
FTM2_C3SC_MSB       equ       5                   ; Channel Mode Select
FTM2_C3SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM2_C3SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM2_C3SC_ELSA     equ       %00000100
mFTM2_C3SC_ELSB     equ       %00001000
mFTM2_C3SC_MSA      equ       %00010000
mFTM2_C3SC_MSB      equ       %00100000
mFTM2_C3SC_CHIE     equ       %01000000
mFTM2_C3SC_CHF      equ       %10000000


;*** FTM2_C3V - FTM2 Timer Channel 3 Value Register
FTM2_C3V            equ       $000030CF           ;*** FTM2_C3V - FTM2 Timer Channel 3 Value Register


;*** FTM2_C3VH - Channel Value High
FTM2_C3VH           equ       $000030CF           ;*** FTM2_C3VH - Channel Value High


;*** FTM2_C3VL - Channel Value Low
FTM2_C3VL           equ       $000030D0           ;*** FTM2_C3VL - Channel Value Low


;*** FTM2_C4SC - Channel Status and Control
FTM2_C4SC           equ       $000030D1           ;*** FTM2_C4SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C4SC_ELSA      equ       2                   ; Edge or Level Select
FTM2_C4SC_ELSB      equ       3                   ; Edge or Level Select
FTM2_C4SC_MSA       equ       4                   ; Channel Mode Select
FTM2_C4SC_MSB       equ       5                   ; Channel Mode Select
FTM2_C4SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM2_C4SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM2_C4SC_ELSA     equ       %00000100
mFTM2_C4SC_ELSB     equ       %00001000
mFTM2_C4SC_MSA      equ       %00010000
mFTM2_C4SC_MSB      equ       %00100000
mFTM2_C4SC_CHIE     equ       %01000000
mFTM2_C4SC_CHF      equ       %10000000


;*** FTM2_C4V - FTM2 Timer Channel 4 Value Register
FTM2_C4V            equ       $000030D2           ;*** FTM2_C4V - FTM2 Timer Channel 4 Value Register


;*** FTM2_C4VH - Channel Value High
FTM2_C4VH           equ       $000030D2           ;*** FTM2_C4VH - Channel Value High


;*** FTM2_C4VL - Channel Value Low
FTM2_C4VL           equ       $000030D3           ;*** FTM2_C4VL - Channel Value Low


;*** FTM2_C5SC - Channel Status and Control
FTM2_C5SC           equ       $000030D4           ;*** FTM2_C5SC - Channel Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C5SC_ELSA      equ       2                   ; Edge or Level Select
FTM2_C5SC_ELSB      equ       3                   ; Edge or Level Select
FTM2_C5SC_MSA       equ       4                   ; Channel Mode Select
FTM2_C5SC_MSB       equ       5                   ; Channel Mode Select
FTM2_C5SC_CHIE      equ       6                   ; Channel Interrupt Enable
FTM2_C5SC_CHF       equ       7                   ; Channel Flag
; bit position masks
mFTM2_C5SC_ELSA     equ       %00000100
mFTM2_C5SC_ELSB     equ       %00001000
mFTM2_C5SC_MSA      equ       %00010000
mFTM2_C5SC_MSB      equ       %00100000
mFTM2_C5SC_CHIE     equ       %01000000
mFTM2_C5SC_CHF      equ       %10000000


;*** FTM2_C5V - FTM2 Timer Channel 5 Value Register
FTM2_C5V            equ       $000030D5           ;*** FTM2_C5V - FTM2 Timer Channel 5 Value Register


;*** FTM2_C5VH - Channel Value High
FTM2_C5VH           equ       $000030D5           ;*** FTM2_C5VH - Channel Value High


;*** FTM2_C5VL - Channel Value Low
FTM2_C5VL           equ       $000030D6           ;*** FTM2_C5VL - Channel Value Low


;*** FTM2_CNTIN - FTM2 Counter Initial Value Registers
FTM2_CNTIN          equ       $000030D7           ;*** FTM2_CNTIN - FTM2 Counter Initial Value Registers


;*** FTM2_CNTINH - Counter Initial Value High
FTM2_CNTINH         equ       $000030D7           ;*** FTM2_CNTINH - Counter Initial Value High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_CNTINH_INIT_H0 equ       0                   ; Counter Initial Value High Byte, bit 0
FTM2_CNTINH_INIT_H1 equ       1                   ; Counter Initial Value High Byte, bit 1
FTM2_CNTINH_INIT_H2 equ       2                   ; Counter Initial Value High Byte, bit 2
FTM2_CNTINH_INIT_H3 equ       3                   ; Counter Initial Value High Byte, bit 3
FTM2_CNTINH_INIT_H4 equ       4                   ; Counter Initial Value High Byte, bit 4
FTM2_CNTINH_INIT_H5 equ       5                   ; Counter Initial Value High Byte, bit 5
FTM2_CNTINH_INIT_H6 equ       6                   ; Counter Initial Value High Byte, bit 6
FTM2_CNTINH_INIT_H7 equ       7                   ; Counter Initial Value High Byte, bit 7
; bit position masks
mFTM2_CNTINH_INIT_H0 equ       %00000001
mFTM2_CNTINH_INIT_H1 equ       %00000010
mFTM2_CNTINH_INIT_H2 equ       %00000100
mFTM2_CNTINH_INIT_H3 equ       %00001000
mFTM2_CNTINH_INIT_H4 equ       %00010000
mFTM2_CNTINH_INIT_H5 equ       %00100000
mFTM2_CNTINH_INIT_H6 equ       %01000000
mFTM2_CNTINH_INIT_H7 equ       %10000000


;*** FTM2_CNTINL - Counter Initial Value Low
FTM2_CNTINL         equ       $000030D8           ;*** FTM2_CNTINL - Counter Initial Value Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_CNTINL_INIT_L0 equ       0                   ; Counter Initial Value Low Byte, bit 0
FTM2_CNTINL_INIT_L1 equ       1                   ; Counter Initial Value Low Byte, bit 1
FTM2_CNTINL_INIT_L2 equ       2                   ; Counter Initial Value Low Byte, bit 2
FTM2_CNTINL_INIT_L3 equ       3                   ; Counter Initial Value Low Byte, bit 3
FTM2_CNTINL_INIT_L4 equ       4                   ; Counter Initial Value Low Byte, bit 4
FTM2_CNTINL_INIT_L5 equ       5                   ; Counter Initial Value Low Byte, bit 5
FTM2_CNTINL_INIT_L6 equ       6                   ; Counter Initial Value Low Byte, bit 6
FTM2_CNTINL_INIT_L7 equ       7                   ; Counter Initial Value Low Byte, bit 7
; bit position masks
mFTM2_CNTINL_INIT_L0 equ       %00000001
mFTM2_CNTINL_INIT_L1 equ       %00000010
mFTM2_CNTINL_INIT_L2 equ       %00000100
mFTM2_CNTINL_INIT_L3 equ       %00001000
mFTM2_CNTINL_INIT_L4 equ       %00010000
mFTM2_CNTINL_INIT_L5 equ       %00100000
mFTM2_CNTINL_INIT_L6 equ       %01000000
mFTM2_CNTINL_INIT_L7 equ       %10000000


;*** FTM2_STATUS - Capture and Compare Status
FTM2_STATUS         equ       $000030D9           ;*** FTM2_STATUS - Capture and Compare Status
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_STATUS_CH0F    equ       0                   ; Channel 0 Flag
FTM2_STATUS_CH1F    equ       1                   ; Channel 1 Flag
FTM2_STATUS_CH2F    equ       2                   ; Channel 2 Flag
FTM2_STATUS_CH3F    equ       3                   ; Channel 3 Flag
FTM2_STATUS_CH4F    equ       4                   ; Channel 4 Flag
FTM2_STATUS_CH5F    equ       5                   ; Channel 5 Flag
FTM2_STATUS_CH6F    equ       6                   ; Channel 6 Flag
FTM2_STATUS_CH7F    equ       7                   ; Channel 7 Flag
; bit position masks
mFTM2_STATUS_CH0F   equ       %00000001
mFTM2_STATUS_CH1F   equ       %00000010
mFTM2_STATUS_CH2F   equ       %00000100
mFTM2_STATUS_CH3F   equ       %00001000
mFTM2_STATUS_CH4F   equ       %00010000
mFTM2_STATUS_CH5F   equ       %00100000
mFTM2_STATUS_CH6F   equ       %01000000
mFTM2_STATUS_CH7F   equ       %10000000


;*** FTM2_MODE - Features Mode Selection
FTM2_MODE           equ       $000030DA           ;*** FTM2_MODE - Features Mode Selection
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_MODE_FTMEN     equ       0                   ; FTM Enable
FTM2_MODE_INIT      equ       1                   ; Initialize the Output Channels
FTM2_MODE_WPDIS     equ       2                   ; Write Protection Disable
FTM2_MODE_PWMSYNC   equ       3                   ; PWM Synchronization Mode
FTM2_MODE_CAPTEST   equ       4                   ; Capture Test Mode Enable
FTM2_MODE_FAULTM0   equ       5                   ; Fault Control Mode, bit 0
FTM2_MODE_FAULTM1   equ       6                   ; Fault Control Mode, bit 1
FTM2_MODE_FAULTIE   equ       7                   ; Fault Interrupt Enable
; bit position masks
mFTM2_MODE_FTMEN    equ       %00000001
mFTM2_MODE_INIT     equ       %00000010
mFTM2_MODE_WPDIS    equ       %00000100
mFTM2_MODE_PWMSYNC  equ       %00001000
mFTM2_MODE_CAPTEST  equ       %00010000
mFTM2_MODE_FAULTM0  equ       %00100000
mFTM2_MODE_FAULTM1  equ       %01000000
mFTM2_MODE_FAULTIE  equ       %10000000


;*** FTM2_SYNC - Synchronization
FTM2_SYNC           equ       $000030DB           ;*** FTM2_SYNC - Synchronization
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_SYNC_CNTMIN    equ       0                   ; Minimum Boundary Cycle Enable
FTM2_SYNC_CNTMAX    equ       1                   ; Maximum Boundary Cycle Enable
FTM2_SYNC_REINIT    equ       2                   ; FTM Counter Reinitialization by Synchronization (See "FTM Counter Synchronization")
FTM2_SYNC_SYNCHOM   equ       3                   ; Output Mask Synchronization
FTM2_SYNC_TRIG0     equ       4                   ; PWM Synchronization External Trigger 0
FTM2_SYNC_TRIG1     equ       5                   ; PWM Synchronization External Trigger 1
FTM2_SYNC_TRIG2     equ       6                   ; PWM Synchronization External Trigger 2
FTM2_SYNC_SWSYNC    equ       7                   ; PWM Synchronization Software Trigger
; bit position masks
mFTM2_SYNC_CNTMIN   equ       %00000001
mFTM2_SYNC_CNTMAX   equ       %00000010
mFTM2_SYNC_REINIT   equ       %00000100
mFTM2_SYNC_SYNCHOM  equ       %00001000
mFTM2_SYNC_TRIG0    equ       %00010000
mFTM2_SYNC_TRIG1    equ       %00100000
mFTM2_SYNC_TRIG2    equ       %01000000
mFTM2_SYNC_SWSYNC   equ       %10000000


;*** FTM2_OUTINIT - Initial State for Channel Output
FTM2_OUTINIT        equ       $000030DC           ;*** FTM2_OUTINIT - Initial State for Channel Output
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_OUTINIT_CH0OI  equ       0                   ; Channel 0 Output Initialization Value
FTM2_OUTINIT_CH1OI  equ       1                   ; Channel 1 Output Initialization Value
FTM2_OUTINIT_CH2OI  equ       2                   ; Channel 2 Output Initialization Value
FTM2_OUTINIT_CH3OI  equ       3                   ; Channel 3 Output Initialization Value
FTM2_OUTINIT_CH4OI  equ       4                   ; Channel 4 Output Initialization Value
FTM2_OUTINIT_CH5OI  equ       5                   ; Channel 5 Output Initialization Value
FTM2_OUTINIT_CH6OI  equ       6                   ; Channel 6 Output Initialization Value
FTM2_OUTINIT_CH7OI  equ       7                   ; Channel 7 Output Initialization Value
; bit position masks
mFTM2_OUTINIT_CH0OI equ       %00000001
mFTM2_OUTINIT_CH1OI equ       %00000010
mFTM2_OUTINIT_CH2OI equ       %00000100
mFTM2_OUTINIT_CH3OI equ       %00001000
mFTM2_OUTINIT_CH4OI equ       %00010000
mFTM2_OUTINIT_CH5OI equ       %00100000
mFTM2_OUTINIT_CH6OI equ       %01000000
mFTM2_OUTINIT_CH7OI equ       %10000000


;*** FTM2_OUTMASK - Output Mask
FTM2_OUTMASK        equ       $000030DD           ;*** FTM2_OUTMASK - Output Mask
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_OUTMASK_CH0OM  equ       0                   ; Channel 0 Output Mask
FTM2_OUTMASK_CH1OM  equ       1                   ; Channel 1 Output Mask
FTM2_OUTMASK_CH2OM  equ       2                   ; Channel 2 Output Mask
FTM2_OUTMASK_CH3OM  equ       3                   ; Channel 3 Output Mask
FTM2_OUTMASK_CH4OM  equ       4                   ; Channel 4 Output Mask
FTM2_OUTMASK_CH5OM  equ       5                   ; Channel 5 Output Mask
FTM2_OUTMASK_CH6OM  equ       6                   ; Channel 6 Output Mask
FTM2_OUTMASK_CH7OM  equ       7                   ; Channel 7 Output Mask
; bit position masks
mFTM2_OUTMASK_CH0OM equ       %00000001
mFTM2_OUTMASK_CH1OM equ       %00000010
mFTM2_OUTMASK_CH2OM equ       %00000100
mFTM2_OUTMASK_CH3OM equ       %00001000
mFTM2_OUTMASK_CH4OM equ       %00010000
mFTM2_OUTMASK_CH5OM equ       %00100000
mFTM2_OUTMASK_CH6OM equ       %01000000
mFTM2_OUTMASK_CH7OM equ       %10000000


;*** FTM2_COMBINE0 - Function for Linked Channels
FTM2_COMBINE0       equ       $000030DE           ;*** FTM2_COMBINE0 - Function for Linked Channels
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_COMBINE0_COMBINE equ       0                   ; Combine Channels
FTM2_COMBINE0_COMP  equ       1                   ; Complement of Channel (n)
FTM2_COMBINE0_DECAPEN equ       2                   ; Dual Edge Capture Mode Enable
FTM2_COMBINE0_DECAP equ       3                   ; Dual Edge Capture Mode Captures
FTM2_COMBINE0_DTEN  equ       4                   ; Deadtime Enable
FTM2_COMBINE0_SYNCEN equ       5                   ; Synchronization Enable
FTM2_COMBINE0_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM2_COMBINE0_COMBINE equ       %00000001
mFTM2_COMBINE0_COMP equ       %00000010
mFTM2_COMBINE0_DECAPEN equ       %00000100
mFTM2_COMBINE0_DECAP equ       %00001000
mFTM2_COMBINE0_DTEN equ       %00010000
mFTM2_COMBINE0_SYNCEN equ       %00100000
mFTM2_COMBINE0_FAULTEN equ       %01000000


;*** FTM2_COMBINE1 - Function for Linked Channels
FTM2_COMBINE1       equ       $000030DF           ;*** FTM2_COMBINE1 - Function for Linked Channels
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_COMBINE1_COMBINE equ       0                   ; Combine Channels
FTM2_COMBINE1_COMP  equ       1                   ; Complement of Channel (n)
FTM2_COMBINE1_DECAPEN equ       2                   ; Dual Edge Capture Mode Enable
FTM2_COMBINE1_DECAP equ       3                   ; Dual Edge Capture Mode Captures
FTM2_COMBINE1_DTEN  equ       4                   ; Deadtime Enable
FTM2_COMBINE1_SYNCEN equ       5                   ; Synchronization Enable
FTM2_COMBINE1_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM2_COMBINE1_COMBINE equ       %00000001
mFTM2_COMBINE1_COMP equ       %00000010
mFTM2_COMBINE1_DECAPEN equ       %00000100
mFTM2_COMBINE1_DECAP equ       %00001000
mFTM2_COMBINE1_DTEN equ       %00010000
mFTM2_COMBINE1_SYNCEN equ       %00100000
mFTM2_COMBINE1_FAULTEN equ       %01000000


;*** FTM2_COMBINE2 - Function for Linked Channels
FTM2_COMBINE2       equ       $000030E0           ;*** FTM2_COMBINE2 - Function for Linked Channels
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_COMBINE2_COMBINE equ       0                   ; Combine Channels
FTM2_COMBINE2_COMP  equ       1                   ; Complement of Channel (n)
FTM2_COMBINE2_DECAPEN equ       2                   ; Dual Edge Capture Mode Enable
FTM2_COMBINE2_DECAP equ       3                   ; Dual Edge Capture Mode Captures
FTM2_COMBINE2_DTEN  equ       4                   ; Deadtime Enable
FTM2_COMBINE2_SYNCEN equ       5                   ; Synchronization Enable
FTM2_COMBINE2_FAULTEN equ       6                   ; Fault Control Enable
; bit position masks
mFTM2_COMBINE2_COMBINE equ       %00000001
mFTM2_COMBINE2_COMP equ       %00000010
mFTM2_COMBINE2_DECAPEN equ       %00000100
mFTM2_COMBINE2_DECAP equ       %00001000
mFTM2_COMBINE2_DTEN equ       %00010000
mFTM2_COMBINE2_SYNCEN equ       %00100000
mFTM2_COMBINE2_FAULTEN equ       %01000000


;*** FTM2_DEADTIME - Deadtime Insertion Control
FTM2_DEADTIME       equ       $000030E2           ;*** FTM2_DEADTIME - Deadtime Insertion Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_DEADTIME_DTVAL0 equ       0                   ; Deadtime Value, bit 0
FTM2_DEADTIME_DTVAL1 equ       1                   ; Deadtime Value, bit 1
FTM2_DEADTIME_DTVAL2 equ       2                   ; Deadtime Value, bit 2
FTM2_DEADTIME_DTVAL3 equ       3                   ; Deadtime Value, bit 3
FTM2_DEADTIME_DTVAL4 equ       4                   ; Deadtime Value, bit 4
FTM2_DEADTIME_DTVAL5 equ       5                   ; Deadtime Value, bit 5
FTM2_DEADTIME_DTPS0 equ       6                   ; Deadtime Prescaler Value, bit 0
FTM2_DEADTIME_DTPS1 equ       7                   ; Deadtime Prescaler Value, bit 1
; bit position masks
mFTM2_DEADTIME_DTVAL0 equ       %00000001
mFTM2_DEADTIME_DTVAL1 equ       %00000010
mFTM2_DEADTIME_DTVAL2 equ       %00000100
mFTM2_DEADTIME_DTVAL3 equ       %00001000
mFTM2_DEADTIME_DTVAL4 equ       %00010000
mFTM2_DEADTIME_DTVAL5 equ       %00100000
mFTM2_DEADTIME_DTPS0 equ       %01000000
mFTM2_DEADTIME_DTPS1 equ       %10000000


;*** FTM2_EXTTRIG - External Trigger
FTM2_EXTTRIG        equ       $000030E3           ;*** FTM2_EXTTRIG - External Trigger
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_EXTTRIG_CH2TRIG equ       0                   ; Channel 2 Trigger Enable
FTM2_EXTTRIG_CH3TRIG equ       1                   ; Channel 3 Trigger Enable
FTM2_EXTTRIG_CH4TRIG equ       2                   ; Channel 4 Trigger Enable
FTM2_EXTTRIG_CH5TRIG equ       3                   ; Channel 5 Trigger Enable
FTM2_EXTTRIG_CH0TRIG equ       4                   ; Channel 0 Trigger Enable
FTM2_EXTTRIG_CH1TRIG equ       5                   ; Channel 1 Trigger Enable
FTM2_EXTTRIG_INITTRIGEN equ       6                   ; Initialization Trigger Enable
FTM2_EXTTRIG_TRIGF  equ       7                   ; Channel Trigger Flag
; bit position masks
mFTM2_EXTTRIG_CH2TRIG equ       %00000001
mFTM2_EXTTRIG_CH3TRIG equ       %00000010
mFTM2_EXTTRIG_CH4TRIG equ       %00000100
mFTM2_EXTTRIG_CH5TRIG equ       %00001000
mFTM2_EXTTRIG_CH0TRIG equ       %00010000
mFTM2_EXTTRIG_CH1TRIG equ       %00100000
mFTM2_EXTTRIG_INITTRIGEN equ       %01000000
mFTM2_EXTTRIG_TRIGF equ       %10000000


;*** FTM2_POL - Channels Polarity
FTM2_POL            equ       $000030E4           ;*** FTM2_POL - Channels Polarity
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_POL_POL0       equ       0                   ; Channel 0 Polarity
FTM2_POL_POL1       equ       1                   ; Channel 1 Polarity
FTM2_POL_POL2       equ       2                   ; Channel 2 Polarity
FTM2_POL_POL3       equ       3                   ; Channel 3 Polarity
FTM2_POL_POL4       equ       4                   ; Channel 4 Polarity
FTM2_POL_POL5       equ       5                   ; Channel 5 Polarity
FTM2_POL_POL6       equ       6                   ; Channel 6 Polarity
FTM2_POL_POL7       equ       7                   ; Channel 7 Polarity
; bit position masks
mFTM2_POL_POL0      equ       %00000001
mFTM2_POL_POL1      equ       %00000010
mFTM2_POL_POL2      equ       %00000100
mFTM2_POL_POL3      equ       %00001000
mFTM2_POL_POL4      equ       %00010000
mFTM2_POL_POL5      equ       %00100000
mFTM2_POL_POL6      equ       %01000000
mFTM2_POL_POL7      equ       %10000000


;*** FTM2_FMS - Fault Mode Status
FTM2_FMS            equ       $000030E5           ;*** FTM2_FMS - Fault Mode Status
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_FMS_FAULTF0    equ       0                   ; Fault Detection Flag 0
FTM2_FMS_FAULTF1    equ       1                   ; Fault Detection Flag 1
FTM2_FMS_FAULTF2    equ       2                   ; Fault Detection Flag 2
FTM2_FMS_FAULTF3    equ       3                   ; Fault Detection Flag 3
FTM2_FMS_FAULTIN    equ       5                   ; Fault Inputs
FTM2_FMS_WPEN       equ       6                   ; Write Protection Enable
FTM2_FMS_FAULTF     equ       7                   ; Fault Detection Flag
; bit position masks
mFTM2_FMS_FAULTF0   equ       %00000001
mFTM2_FMS_FAULTF1   equ       %00000010
mFTM2_FMS_FAULTF2   equ       %00000100
mFTM2_FMS_FAULTF3   equ       %00001000
mFTM2_FMS_FAULTIN   equ       %00100000
mFTM2_FMS_WPEN      equ       %01000000
mFTM2_FMS_FAULTF    equ       %10000000


;*** FTM2_FILTER0 - Input Capture Filter Control
FTM2_FILTER0        equ       $000030E6           ;*** FTM2_FILTER0 - Input Capture Filter Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_FILTER0_CHevenFVAL0 equ       0                   ; Input Filter for Even Channel, bit 0
FTM2_FILTER0_CHevenFVAL1 equ       1                   ; Input Filter for Even Channel, bit 1
FTM2_FILTER0_CHevenFVAL2 equ       2                   ; Input Filter for Even Channel, bit 2
FTM2_FILTER0_CHevenFVAL3 equ       3                   ; Input Filter for Even Channel, bit 3
FTM2_FILTER0_CHoddFVAL0 equ       4                   ; Input Filter for Odd Channel, bit 0
FTM2_FILTER0_CHoddFVAL1 equ       5                   ; Input Filter for Odd Channel, bit 1
FTM2_FILTER0_CHoddFVAL2 equ       6                   ; Input Filter for Odd Channel, bit 2
FTM2_FILTER0_CHoddFVAL3 equ       7                   ; Input Filter for Odd Channel, bit 3
; bit position masks
mFTM2_FILTER0_CHevenFVAL0 equ       %00000001
mFTM2_FILTER0_CHevenFVAL1 equ       %00000010
mFTM2_FILTER0_CHevenFVAL2 equ       %00000100
mFTM2_FILTER0_CHevenFVAL3 equ       %00001000
mFTM2_FILTER0_CHoddFVAL0 equ       %00010000
mFTM2_FILTER0_CHoddFVAL1 equ       %00100000
mFTM2_FILTER0_CHoddFVAL2 equ       %01000000
mFTM2_FILTER0_CHoddFVAL3 equ       %10000000


;*** FTM2_FILTER1 - Input Capture Filter Control
FTM2_FILTER1        equ       $000030E7           ;*** FTM2_FILTER1 - Input Capture Filter Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_FILTER1_CHevenFVAL0 equ       0                   ; Input Filter for Even Channel, bit 0
FTM2_FILTER1_CHevenFVAL1 equ       1                   ; Input Filter for Even Channel, bit 1
FTM2_FILTER1_CHevenFVAL2 equ       2                   ; Input Filter for Even Channel, bit 2
FTM2_FILTER1_CHevenFVAL3 equ       3                   ; Input Filter for Even Channel, bit 3
FTM2_FILTER1_CHoddFVAL0 equ       4                   ; Input Filter for Odd Channel, bit 0
FTM2_FILTER1_CHoddFVAL1 equ       5                   ; Input Filter for Odd Channel, bit 1
FTM2_FILTER1_CHoddFVAL2 equ       6                   ; Input Filter for Odd Channel, bit 2
FTM2_FILTER1_CHoddFVAL3 equ       7                   ; Input Filter for Odd Channel, bit 3
; bit position masks
mFTM2_FILTER1_CHevenFVAL0 equ       %00000001
mFTM2_FILTER1_CHevenFVAL1 equ       %00000010
mFTM2_FILTER1_CHevenFVAL2 equ       %00000100
mFTM2_FILTER1_CHevenFVAL3 equ       %00001000
mFTM2_FILTER1_CHoddFVAL0 equ       %00010000
mFTM2_FILTER1_CHoddFVAL1 equ       %00100000
mFTM2_FILTER1_CHoddFVAL2 equ       %01000000
mFTM2_FILTER1_CHoddFVAL3 equ       %10000000


;*** FTM2_FLTFILTER - Fault Input Filter Control
FTM2_FLTFILTER      equ       $000030E8           ;*** FTM2_FLTFILTER - Fault Input Filter Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_FLTFILTER_FFVAL0 equ       0                   ; Fault Input Filter, bit 0
FTM2_FLTFILTER_FFVAL1 equ       1                   ; Fault Input Filter, bit 1
FTM2_FLTFILTER_FFVAL2 equ       2                   ; Fault Input Filter, bit 2
FTM2_FLTFILTER_FFVAL3 equ       3                   ; Fault Input Filter, bit 3
; bit position masks
mFTM2_FLTFILTER_FFVAL0 equ       %00000001
mFTM2_FLTFILTER_FFVAL1 equ       %00000010
mFTM2_FLTFILTER_FFVAL2 equ       %00000100
mFTM2_FLTFILTER_FFVAL3 equ       %00001000


;*** FTM2_FLTCTRL - Fault Input Control
FTM2_FLTCTRL        equ       $000030E9           ;*** FTM2_FLTCTRL - Fault Input Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_FLTCTRL_FAULT0EN equ       0                   ; Fault Input 0 Enable
FTM2_FLTCTRL_FAULT1EN equ       1                   ; Fault Input 1 Enable
FTM2_FLTCTRL_FAULT2EN equ       2                   ; Fault Input 2 Enable
FTM2_FLTCTRL_FAULT3EN equ       3                   ; Fault Input 3 Enable
FTM2_FLTCTRL_FFLTR0EN equ       4                   ; Fault Input 0 Filter Enable
FTM2_FLTCTRL_FFLTR1EN equ       5                   ; Fault Input 1 Filter Enable
FTM2_FLTCTRL_FFLTR2EN equ       6                   ; Fault Input 2 Filter Enable
FTM2_FLTCTRL_FFLTR3EN equ       7                   ; Fault Input 3 Filter Enable
; bit position masks
mFTM2_FLTCTRL_FAULT0EN equ       %00000001
mFTM2_FLTCTRL_FAULT1EN equ       %00000010
mFTM2_FLTCTRL_FAULT2EN equ       %00000100
mFTM2_FLTCTRL_FAULT3EN equ       %00001000
mFTM2_FLTCTRL_FFLTR0EN equ       %00010000
mFTM2_FLTCTRL_FFLTR1EN equ       %00100000
mFTM2_FLTCTRL_FFLTR2EN equ       %01000000
mFTM2_FLTCTRL_FFLTR3EN equ       %10000000


;*** PORT_IOFLT0 - Port Filter Register 0
PORT_IOFLT0         equ       $000030EC           ;*** PORT_IOFLT0 - Port Filter Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT0_FLTA0   equ       0                   ; Filter selection for input from PTA, bit 0
PORT_IOFLT0_FLTA1   equ       1                   ; Filter selection for input from PTA, bit 1
PORT_IOFLT0_FLTB0   equ       2                   ; Filter selection for input from PTB, bit 0
PORT_IOFLT0_FLTB1   equ       3                   ; Filter selection for input from PTB, bit 1
PORT_IOFLT0_FLTC0   equ       4                   ; Filter selection for input from PTC, bit 0
PORT_IOFLT0_FLTC1   equ       5                   ; Filter selection for input from PTC, bit 1
PORT_IOFLT0_FLTD0   equ       6                   ; Filter selection for input from PTD, bit 0
PORT_IOFLT0_FLTD1   equ       7                   ; Filter selection for input from PTD, bit 1
; bit position masks
mPORT_IOFLT0_FLTA0  equ       %00000001
mPORT_IOFLT0_FLTA1  equ       %00000010
mPORT_IOFLT0_FLTB0  equ       %00000100
mPORT_IOFLT0_FLTB1  equ       %00001000
mPORT_IOFLT0_FLTC0  equ       %00010000
mPORT_IOFLT0_FLTC1  equ       %00100000
mPORT_IOFLT0_FLTD0  equ       %01000000
mPORT_IOFLT0_FLTD1  equ       %10000000


;*** PORT_IOFLT1 - Port Filter Register 1
PORT_IOFLT1         equ       $000030ED           ;*** PORT_IOFLT1 - Port Filter Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT1_FLTE0   equ       0                   ; Filter selection for input from PTE, bit 0
PORT_IOFLT1_FLTE1   equ       1                   ; Filter selection for input from PTE, bit 1
; bit position masks
mPORT_IOFLT1_FLTE0  equ       %00000001
mPORT_IOFLT1_FLTE1  equ       %00000010


;*** PORT_IOFLT2 - Port Filter Register 2
PORT_IOFLT2         equ       $000030EE           ;*** PORT_IOFLT2 - Port Filter Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT2_FLTRST0 equ       0                   ; Filter selection for input from RESET/IRQ, bit 0
PORT_IOFLT2_FLTRST1 equ       1                   ; Filter selection for input from RESET/IRQ, bit 1
PORT_IOFLT2_FLTKBI00 equ       2                   ; Filter selection for input from KBI0, bit 0
PORT_IOFLT2_FLTKBI01 equ       3                   ; Filter selection for input from KBI0, bit 1
; bit position masks
mPORT_IOFLT2_FLTRST0 equ       %00000001
mPORT_IOFLT2_FLTRST1 equ       %00000010
mPORT_IOFLT2_FLTKBI00 equ       %00000100
mPORT_IOFLT2_FLTKBI01 equ       %00001000


;*** PORT_FCLKDIV - Port Clock Division Register
PORT_FCLKDIV        equ       $000030EF           ;*** PORT_FCLKDIV - Port Clock Division Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_FCLKDIV_FLTDIV10 equ       0                   ; , bit 0
PORT_FCLKDIV_FLTDIV11 equ       1                   ; , bit 1
PORT_FCLKDIV_FLTDIV20 equ       2                   ; , bit 0
PORT_FCLKDIV_FLTDIV21 equ       3                   ; , bit 1
PORT_FCLKDIV_FLTDIV22 equ       4                   ; , bit 2
PORT_FCLKDIV_FLTDIV30 equ       5                   ; , bit 0
PORT_FCLKDIV_FLTDIV31 equ       6                   ; , bit 1
PORT_FCLKDIV_FLTDIV32 equ       7                   ; , bit 2
; bit position masks
mPORT_FCLKDIV_FLTDIV10 equ       %00000001
mPORT_FCLKDIV_FLTDIV11 equ       %00000010
mPORT_FCLKDIV_FLTDIV20 equ       %00000100
mPORT_FCLKDIV_FLTDIV21 equ       %00001000
mPORT_FCLKDIV_FLTDIV22 equ       %00010000
mPORT_FCLKDIV_FLTDIV30 equ       %00100000
mPORT_FCLKDIV_FLTDIV31 equ       %01000000
mPORT_FCLKDIV_FLTDIV32 equ       %10000000


;*** PORT_PTAPE - Port A Pullup Enable Register
PORT_PTAPE          equ       $000030F0           ;*** PORT_PTAPE - Port A Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAPE_PTAPE0   equ       0                   ; Pull Enable for Port A Bit 0
PORT_PTAPE_PTAPE1   equ       1                   ; Pull Enable for Port A Bit 1
PORT_PTAPE_PTAPE2   equ       2                   ; Pull Enable for Port A Bit 2
PORT_PTAPE_PTAPE3   equ       3                   ; Pull Enable for Port A Bit 3
PORT_PTAPE_PTAPE5   equ       5                   ; Pull Enable for Port A Bit 5
PORT_PTAPE_PTAPE6   equ       6                   ; Pull Enable for Port A Bit 6
PORT_PTAPE_PTAPE7   equ       7                   ; Pull Enable for Port A Bit 7
; bit position masks
mPORT_PTAPE_PTAPE0  equ       %00000001
mPORT_PTAPE_PTAPE1  equ       %00000010
mPORT_PTAPE_PTAPE2  equ       %00000100
mPORT_PTAPE_PTAPE3  equ       %00001000
mPORT_PTAPE_PTAPE5  equ       %00100000
mPORT_PTAPE_PTAPE6  equ       %01000000
mPORT_PTAPE_PTAPE7  equ       %10000000


;*** PORT_PTBPE - Port B Pullup Enable Register
PORT_PTBPE          equ       $000030F1           ;*** PORT_PTBPE - Port B Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBPE_PTBPE0   equ       0                   ; Pull Enable for Port B Bit 0
PORT_PTBPE_PTBPE1   equ       1                   ; Pull Enable for Port B Bit 1
PORT_PTBPE_PTBPE2   equ       2                   ; Pull Enable for Port B Bit 2
PORT_PTBPE_PTBPE3   equ       3                   ; Pull Enable for Port B Bit 3
PORT_PTBPE_PTBPE4   equ       4                   ; Pull Enable for Port B Bit 4
PORT_PTBPE_PTBPE5   equ       5                   ; Pull Enable for Port B Bit 5
PORT_PTBPE_PTBPE6   equ       6                   ; Pull Enable for Port B Bit 6
PORT_PTBPE_PTBPE7   equ       7                   ; Pull Enable for Port B Bit 7
; bit position masks
mPORT_PTBPE_PTBPE0  equ       %00000001
mPORT_PTBPE_PTBPE1  equ       %00000010
mPORT_PTBPE_PTBPE2  equ       %00000100
mPORT_PTBPE_PTBPE3  equ       %00001000
mPORT_PTBPE_PTBPE4  equ       %00010000
mPORT_PTBPE_PTBPE5  equ       %00100000
mPORT_PTBPE_PTBPE6  equ       %01000000
mPORT_PTBPE_PTBPE7  equ       %10000000


;*** PORT_PTCPE - Port C Pullup Enable Register
PORT_PTCPE          equ       $000030F2           ;*** PORT_PTCPE - Port C Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCPE_PTCPE0   equ       0                   ; Pull Enable for Port C Bit 0
PORT_PTCPE_PTCPE1   equ       1                   ; Pull Enable for Port C Bit 1
PORT_PTCPE_PTCPE2   equ       2                   ; Pull Enable for Port C Bit 2
PORT_PTCPE_PTCPE3   equ       3                   ; Pull Enable for Port C Bit 3
PORT_PTCPE_PTCPE4   equ       4                   ; Pull Enable for Port C Bit 4
PORT_PTCPE_PTCPE5   equ       5                   ; Pull Enable for Port C Bit 5
PORT_PTCPE_PTCPE6   equ       6                   ; Pull Enable for Port C Bit 6
PORT_PTCPE_PTCPE7   equ       7                   ; Pull Enable for Port C Bit 7
; bit position masks
mPORT_PTCPE_PTCPE0  equ       %00000001
mPORT_PTCPE_PTCPE1  equ       %00000010
mPORT_PTCPE_PTCPE2  equ       %00000100
mPORT_PTCPE_PTCPE3  equ       %00001000
mPORT_PTCPE_PTCPE4  equ       %00010000
mPORT_PTCPE_PTCPE5  equ       %00100000
mPORT_PTCPE_PTCPE6  equ       %01000000
mPORT_PTCPE_PTCPE7  equ       %10000000


;*** PORT_PTDPE - Port D Pullup Enable Register
PORT_PTDPE          equ       $000030F3           ;*** PORT_PTDPE - Port D Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDPE_PTDPE0   equ       0                   ; Pull Enable for Port D Bit 0
PORT_PTDPE_PTDPE1   equ       1                   ; Pull Enable for Port D Bit 1
PORT_PTDPE_PTDPE2   equ       2                   ; Pull Enable for Port D Bit 2
PORT_PTDPE_PTDPE3   equ       3                   ; Pull Enable for Port D Bit 3
PORT_PTDPE_PTDPE4   equ       4                   ; Pull Enable for Port D Bit 4
PORT_PTDPE_PTDPE5   equ       5                   ; Pull Enable for Port D Bit 5
PORT_PTDPE_PTDPE6   equ       6                   ; Pull Enable for Port D Bit 6
PORT_PTDPE_PTDPE7   equ       7                   ; Pull Enable for Port D Bit 7
; bit position masks
mPORT_PTDPE_PTDPE0  equ       %00000001
mPORT_PTDPE_PTDPE1  equ       %00000010
mPORT_PTDPE_PTDPE2  equ       %00000100
mPORT_PTDPE_PTDPE3  equ       %00001000
mPORT_PTDPE_PTDPE4  equ       %00010000
mPORT_PTDPE_PTDPE5  equ       %00100000
mPORT_PTDPE_PTDPE6  equ       %01000000
mPORT_PTDPE_PTDPE7  equ       %10000000


;*** PORT_PTEPE - Port E Pullup Enable Register
PORT_PTEPE          equ       $000030F4           ;*** PORT_PTEPE - Port E Pullup Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTEPE_PTEPE0   equ       0                   ; Pull Enable for Port E Bit 0
PORT_PTEPE_PTEPE1   equ       1                   ; Pull Enable for Port E Bit 1
PORT_PTEPE_PTEPE2   equ       2                   ; Pull Enable for Port E Bit 2
PORT_PTEPE_PTEPE3   equ       3                   ; Pull Enable for Port E Bit 3
PORT_PTEPE_PTEPE4   equ       4                   ; Pull Enable for Port E Bit 4
; bit position masks
mPORT_PTEPE_PTEPE0  equ       %00000001
mPORT_PTEPE_PTEPE1  equ       %00000010
mPORT_PTEPE_PTEPE2  equ       %00000100
mPORT_PTEPE_PTEPE3  equ       %00001000
mPORT_PTEPE_PTEPE4  equ       %00010000


;*** SYS_UUID1 - Universally Unique Identifier Register 1
SYS_UUID1           equ       $000030F8           ;*** SYS_UUID1 - Universally Unique Identifier Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID1_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID1_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID1_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID1_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID1_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID1_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID1_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID1_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID1_ID0      equ       %00000001
mSYS_UUID1_ID1      equ       %00000010
mSYS_UUID1_ID2      equ       %00000100
mSYS_UUID1_ID3      equ       %00001000
mSYS_UUID1_ID4      equ       %00010000
mSYS_UUID1_ID5      equ       %00100000
mSYS_UUID1_ID6      equ       %01000000
mSYS_UUID1_ID7      equ       %10000000


;*** SYS_UUID2 - Universally Unique Identifier Register 2
SYS_UUID2           equ       $000030F9           ;*** SYS_UUID2 - Universally Unique Identifier Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID2_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID2_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID2_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID2_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID2_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID2_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID2_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID2_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID2_ID0      equ       %00000001
mSYS_UUID2_ID1      equ       %00000010
mSYS_UUID2_ID2      equ       %00000100
mSYS_UUID2_ID3      equ       %00001000
mSYS_UUID2_ID4      equ       %00010000
mSYS_UUID2_ID5      equ       %00100000
mSYS_UUID2_ID6      equ       %01000000
mSYS_UUID2_ID7      equ       %10000000


;*** SYS_UUID3 - Universally Unique Identifier Register 3
SYS_UUID3           equ       $000030FA           ;*** SYS_UUID3 - Universally Unique Identifier Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID3_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID3_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID3_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID3_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID3_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID3_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID3_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID3_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID3_ID0      equ       %00000001
mSYS_UUID3_ID1      equ       %00000010
mSYS_UUID3_ID2      equ       %00000100
mSYS_UUID3_ID3      equ       %00001000
mSYS_UUID3_ID4      equ       %00010000
mSYS_UUID3_ID5      equ       %00100000
mSYS_UUID3_ID6      equ       %01000000
mSYS_UUID3_ID7      equ       %10000000


;*** SYS_UUID4 - Universally Unique Identifier Register 4
SYS_UUID4           equ       $000030FB           ;*** SYS_UUID4 - Universally Unique Identifier Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID4_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID4_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID4_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID4_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID4_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID4_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID4_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID4_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID4_ID0      equ       %00000001
mSYS_UUID4_ID1      equ       %00000010
mSYS_UUID4_ID2      equ       %00000100
mSYS_UUID4_ID3      equ       %00001000
mSYS_UUID4_ID4      equ       %00010000
mSYS_UUID4_ID5      equ       %00100000
mSYS_UUID4_ID6      equ       %01000000
mSYS_UUID4_ID7      equ       %10000000


;*** SYS_UUID5 - Universally Unique Identifier Register 5
SYS_UUID5           equ       $000030FC           ;*** SYS_UUID5 - Universally Unique Identifier Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID5_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID5_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID5_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID5_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID5_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID5_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID5_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID5_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID5_ID0      equ       %00000001
mSYS_UUID5_ID1      equ       %00000010
mSYS_UUID5_ID2      equ       %00000100
mSYS_UUID5_ID3      equ       %00001000
mSYS_UUID5_ID4      equ       %00010000
mSYS_UUID5_ID5      equ       %00100000
mSYS_UUID5_ID6      equ       %01000000
mSYS_UUID5_ID7      equ       %10000000


;*** SYS_UUID6 - Universally Unique Identifier Register 6
SYS_UUID6           equ       $000030FD           ;*** SYS_UUID6 - Universally Unique Identifier Register 6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID6_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID6_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID6_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID6_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID6_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID6_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID6_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID6_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID6_ID0      equ       %00000001
mSYS_UUID6_ID1      equ       %00000010
mSYS_UUID6_ID2      equ       %00000100
mSYS_UUID6_ID3      equ       %00001000
mSYS_UUID6_ID4      equ       %00010000
mSYS_UUID6_ID5      equ       %00100000
mSYS_UUID6_ID6      equ       %01000000
mSYS_UUID6_ID7      equ       %10000000


;*** SYS_UUID7 - Universally Unique Identifier Register 7
SYS_UUID7           equ       $000030FE           ;*** SYS_UUID7 - Universally Unique Identifier Register 7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID7_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID7_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID7_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID7_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID7_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID7_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID7_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID7_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID7_ID0      equ       %00000001
mSYS_UUID7_ID1      equ       %00000010
mSYS_UUID7_ID2      equ       %00000100
mSYS_UUID7_ID3      equ       %00001000
mSYS_UUID7_ID4      equ       %00010000
mSYS_UUID7_ID5      equ       %00100000
mSYS_UUID7_ID6      equ       %01000000
mSYS_UUID7_ID7      equ       %10000000


;*** SYS_UUID8 - Universally Unique Identifier Register 8
SYS_UUID8           equ       $000030FF           ;*** SYS_UUID8 - Universally Unique Identifier Register 8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID8_ID0       equ       0                   ; Universally Unique Identifier, bit 0
SYS_UUID8_ID1       equ       1                   ; Universally Unique Identifier, bit 1
SYS_UUID8_ID2       equ       2                   ; Universally Unique Identifier, bit 2
SYS_UUID8_ID3       equ       3                   ; Universally Unique Identifier, bit 3
SYS_UUID8_ID4       equ       4                   ; Universally Unique Identifier, bit 4
SYS_UUID8_ID5       equ       5                   ; Universally Unique Identifier, bit 5
SYS_UUID8_ID6       equ       6                   ; Universally Unique Identifier, bit 6
SYS_UUID8_ID7       equ       7                   ; Universally Unique Identifier, bit 7
; bit position masks
mSYS_UUID8_ID0      equ       %00000001
mSYS_UUID8_ID1      equ       %00000010
mSYS_UUID8_ID2      equ       %00000100
mSYS_UUID8_ID3      equ       %00001000
mSYS_UUID8_ID4      equ       %00010000
mSYS_UUID8_ID5      equ       %00100000
mSYS_UUID8_ID6      equ       %01000000
mSYS_UUID8_ID7      equ       %10000000


;*** NV_BACKKEY0 - Back Door Key Register n
NV_BACKKEY0         equ       $0000FF70           ;*** NV_BACKKEY0 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY0_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY0_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY0_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY0_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY0_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY0_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY0_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY0_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY0_BACKKEY0 equ       %00000001
mNV_BACKKEY0_BACKKEY1 equ       %00000010
mNV_BACKKEY0_BACKKEY2 equ       %00000100
mNV_BACKKEY0_BACKKEY3 equ       %00001000
mNV_BACKKEY0_BACKKEY4 equ       %00010000
mNV_BACKKEY0_BACKKEY5 equ       %00100000
mNV_BACKKEY0_BACKKEY6 equ       %01000000
mNV_BACKKEY0_BACKKEY7 equ       %10000000


;*** NV_BACKKEY1 - Back Door Key Register n
NV_BACKKEY1         equ       $0000FF71           ;*** NV_BACKKEY1 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY1_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY1_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY1_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY1_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY1_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY1_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY1_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY1_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY1_BACKKEY0 equ       %00000001
mNV_BACKKEY1_BACKKEY1 equ       %00000010
mNV_BACKKEY1_BACKKEY2 equ       %00000100
mNV_BACKKEY1_BACKKEY3 equ       %00001000
mNV_BACKKEY1_BACKKEY4 equ       %00010000
mNV_BACKKEY1_BACKKEY5 equ       %00100000
mNV_BACKKEY1_BACKKEY6 equ       %01000000
mNV_BACKKEY1_BACKKEY7 equ       %10000000


;*** NV_BACKKEY2 - Back Door Key Register n
NV_BACKKEY2         equ       $0000FF72           ;*** NV_BACKKEY2 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY2_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY2_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY2_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY2_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY2_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY2_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY2_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY2_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY2_BACKKEY0 equ       %00000001
mNV_BACKKEY2_BACKKEY1 equ       %00000010
mNV_BACKKEY2_BACKKEY2 equ       %00000100
mNV_BACKKEY2_BACKKEY3 equ       %00001000
mNV_BACKKEY2_BACKKEY4 equ       %00010000
mNV_BACKKEY2_BACKKEY5 equ       %00100000
mNV_BACKKEY2_BACKKEY6 equ       %01000000
mNV_BACKKEY2_BACKKEY7 equ       %10000000


;*** NV_BACKKEY3 - Back Door Key Register n
NV_BACKKEY3         equ       $0000FF73           ;*** NV_BACKKEY3 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY3_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY3_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY3_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY3_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY3_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY3_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY3_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY3_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY3_BACKKEY0 equ       %00000001
mNV_BACKKEY3_BACKKEY1 equ       %00000010
mNV_BACKKEY3_BACKKEY2 equ       %00000100
mNV_BACKKEY3_BACKKEY3 equ       %00001000
mNV_BACKKEY3_BACKKEY4 equ       %00010000
mNV_BACKKEY3_BACKKEY5 equ       %00100000
mNV_BACKKEY3_BACKKEY6 equ       %01000000
mNV_BACKKEY3_BACKKEY7 equ       %10000000


;*** NV_BACKKEY4 - Back Door Key Register n
NV_BACKKEY4         equ       $0000FF74           ;*** NV_BACKKEY4 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY4_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY4_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY4_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY4_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY4_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY4_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY4_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY4_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY4_BACKKEY0 equ       %00000001
mNV_BACKKEY4_BACKKEY1 equ       %00000010
mNV_BACKKEY4_BACKKEY2 equ       %00000100
mNV_BACKKEY4_BACKKEY3 equ       %00001000
mNV_BACKKEY4_BACKKEY4 equ       %00010000
mNV_BACKKEY4_BACKKEY5 equ       %00100000
mNV_BACKKEY4_BACKKEY6 equ       %01000000
mNV_BACKKEY4_BACKKEY7 equ       %10000000


;*** NV_BACKKEY5 - Back Door Key Register n
NV_BACKKEY5         equ       $0000FF75           ;*** NV_BACKKEY5 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY5_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY5_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY5_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY5_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY5_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY5_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY5_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY5_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY5_BACKKEY0 equ       %00000001
mNV_BACKKEY5_BACKKEY1 equ       %00000010
mNV_BACKKEY5_BACKKEY2 equ       %00000100
mNV_BACKKEY5_BACKKEY3 equ       %00001000
mNV_BACKKEY5_BACKKEY4 equ       %00010000
mNV_BACKKEY5_BACKKEY5 equ       %00100000
mNV_BACKKEY5_BACKKEY6 equ       %01000000
mNV_BACKKEY5_BACKKEY7 equ       %10000000


;*** NV_BACKKEY6 - Back Door Key Register n
NV_BACKKEY6         equ       $0000FF76           ;*** NV_BACKKEY6 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY6_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY6_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY6_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY6_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY6_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY6_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY6_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY6_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY6_BACKKEY0 equ       %00000001
mNV_BACKKEY6_BACKKEY1 equ       %00000010
mNV_BACKKEY6_BACKKEY2 equ       %00000100
mNV_BACKKEY6_BACKKEY3 equ       %00001000
mNV_BACKKEY6_BACKKEY4 equ       %00010000
mNV_BACKKEY6_BACKKEY5 equ       %00100000
mNV_BACKKEY6_BACKKEY6 equ       %01000000
mNV_BACKKEY6_BACKKEY7 equ       %10000000


;*** NV_BACKKEY7 - Back Door Key Register n
NV_BACKKEY7         equ       $0000FF77           ;*** NV_BACKKEY7 - Back Door Key Register n
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY7_BACKKEY0 equ       0                   ; Back Door Key, bit 0
NV_BACKKEY7_BACKKEY1 equ       1                   ; Back Door Key, bit 1
NV_BACKKEY7_BACKKEY2 equ       2                   ; Back Door Key, bit 2
NV_BACKKEY7_BACKKEY3 equ       3                   ; Back Door Key, bit 3
NV_BACKKEY7_BACKKEY4 equ       4                   ; Back Door Key, bit 4
NV_BACKKEY7_BACKKEY5 equ       5                   ; Back Door Key, bit 5
NV_BACKKEY7_BACKKEY6 equ       6                   ; Back Door Key, bit 6
NV_BACKKEY7_BACKKEY7 equ       7                   ; Back Door Key, bit 7
; bit position masks
mNV_BACKKEY7_BACKKEY0 equ       %00000001
mNV_BACKKEY7_BACKKEY1 equ       %00000010
mNV_BACKKEY7_BACKKEY2 equ       %00000100
mNV_BACKKEY7_BACKKEY3 equ       %00001000
mNV_BACKKEY7_BACKKEY4 equ       %00010000
mNV_BACKKEY7_BACKKEY5 equ       %00100000
mNV_BACKKEY7_BACKKEY6 equ       %01000000
mNV_BACKKEY7_BACKKEY7 equ       %10000000


;*** NV_FPROT - Flash Protection Register
NV_FPROT            equ       $0000FF7C           ;*** NV_FPROT - Flash Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FPROT_FPHS0      equ       3                   ; Flash Protection Higher Address Size, bit 0
NV_FPROT_FPHS1      equ       4                   ; Flash Protection Higher Address Size, bit 1
NV_FPROT_FPHDIS     equ       5                   ; Flash Protection Higher Address Range Disable
NV_FPROT_FPOPEN     equ       7                   ; Flash Protection Operation Enable
; bit position masks
mNV_FPROT_FPHS0     equ       %00001000
mNV_FPROT_FPHS1     equ       %00010000
mNV_FPROT_FPHDIS    equ       %00100000
mNV_FPROT_FPOPEN    equ       %10000000


;*** NV_EEPROT - EEPROM Protection Register
NV_EEPROT           equ       $0000FF7D           ;*** NV_EEPROT - EEPROM Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_EEPROT_DPS0      equ       0                   ; EEPROM Protection Size, bit 0
NV_EEPROT_DPS1      equ       1                   ; EEPROM Protection Size, bit 1
NV_EEPROT_DPS2      equ       2                   ; EEPROM Protection Size, bit 2
NV_EEPROT_DPOPEN    equ       7                   ; EEPROM Protection Control
; bit position masks
mNV_EEPROT_DPS0     equ       %00000001
mNV_EEPROT_DPS1     equ       %00000010
mNV_EEPROT_DPS2     equ       %00000100
mNV_EEPROT_DPOPEN   equ       %10000000


;*** NV_FOPT - Flash Option Register
NV_FOPT             equ       $0000FF7E           ;*** NV_FOPT - Flash Option Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FOPT_NV0         equ       0                   ; Non-volatile Bits, bit 0
NV_FOPT_NV1         equ       1                   ; Non-volatile Bits, bit 1
NV_FOPT_NV2         equ       2                   ; Non-volatile Bits, bit 2
NV_FOPT_NV3         equ       3                   ; Non-volatile Bits, bit 3
NV_FOPT_NV4         equ       4                   ; Non-volatile Bits, bit 4
NV_FOPT_NV5         equ       5                   ; Non-volatile Bits, bit 5
NV_FOPT_NV6         equ       6                   ; Non-volatile Bits, bit 6
NV_FOPT_NV7         equ       7                   ; Non-volatile Bits, bit 7
; bit position masks
mNV_FOPT_NV0        equ       %00000001
mNV_FOPT_NV1        equ       %00000010
mNV_FOPT_NV2        equ       %00000100
mNV_FOPT_NV3        equ       %00001000
mNV_FOPT_NV4        equ       %00010000
mNV_FOPT_NV5        equ       %00100000
mNV_FOPT_NV6        equ       %01000000
mNV_FOPT_NV7        equ       %10000000


;*** NV_FSEC - Flash Security Register
NV_FSEC             equ       $0000FF7F           ;*** NV_FSEC - Flash Security Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FSEC_SEC0        equ       0                   ; Flash Security Bits, bit 0
NV_FSEC_SEC1        equ       1                   ; Flash Security Bits, bit 1
NV_FSEC_KEYEN0      equ       6                   ; Backdoor Key Security Enable Bits, bit 0
NV_FSEC_KEYEN1      equ       7                   ; Backdoor Key Security Enable Bits, bit 1
; bit position masks
mNV_FSEC_SEC0       equ       %00000001
mNV_FSEC_SEC1       equ       %00000010
mNV_FSEC_KEYEN0     equ       %01000000
mNV_FSEC_KEYEN1     equ       %10000000



;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
       #ifndef  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
       #endif

; EOF
