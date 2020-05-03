;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; ###################################################################
;     Filename  : mc9s08pl16.inc
;     Processor : MC9S08PL16
;     DataSheet : MC9S08PL16RM Rev. 2, 07/2018
;     Compiler  : CodeWarrior compiler
;     Date/Time : 2018-07-11 15:05:06
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2018 NXP Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.nxp.com
;     mail      : support@nxp.com
; ###################################################################

;**************** interrupt vector table ****************
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
Vsci1txd            equ       $0000FFC6
Vsci1rxd            equ       $0000FFC8
Vsci1err            equ       $0000FFCA
Vsci0txd            equ       $0000FFCC
Vsci0rxd            equ       $0000FFCE
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
VReserved5          equ       $0000FFF4
Vclk                equ       $0000FFF6
Vlvw                equ       $0000FFF8
Virq                equ       $0000FFFA
Vswi                equ       $0000FFFC
Vreset              equ       $0000FFFE

;*************Memory Map************************
RAM                 equ       $00000040
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000083F
EEPROM              equ       $00003100
EEPROM_END          equ       $000031FF
ROM                 equ       $0000C000
ROM_END             equ       $0000FF6F
XROM                equ       $0000FF80
XROM_END            equ       $0000FFAF

;*** PORT_PTAD Port A Data Register
PORT_PTAD           equ       $00000000
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


;*** PORT_PTBD Port B Data Register
PORT_PTBD           equ       $00000001
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


;*** PORT_PTCD Port C Data Register
PORT_PTCD           equ       $00000002
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


;*** PORT_PTDD Port D Data Register
PORT_PTDD           equ       $00000003
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDD_PTDD0     equ       0
PORT_PTDD_PTDD1     equ       1
PORT_PTDD_PTDD2     equ       2
PORT_PTDD_PTDD6     equ       6
PORT_PTDD_PTDD7     equ       7
; bit position masks
mPORT_PTDD_PTDD0    equ       %00000001
mPORT_PTDD_PTDD1    equ       %00000010
mPORT_PTDD_PTDD2    equ       %00000100
mPORT_PTDD_PTDD6    equ       %01000000
mPORT_PTDD_PTDD7    equ       %10000000


;*** PORT_PTED Port E Data Register
PORT_PTED           equ       $00000004
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTED_PTED      equ       4
; bit position masks
mPORT_PTED_PTED     equ       %00010000


;*** ADC_SC1 Status and Control Register 1
ADC_SC1             equ       $00000010
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC1_ADCH0       equ       0
ADC_SC1_ADCH1       equ       1
ADC_SC1_ADCH2       equ       2
ADC_SC1_ADCH3       equ       3
ADC_SC1_ADCH4       equ       4
ADC_SC1_ADCO        equ       5
ADC_SC1_AIEN        equ       6
ADC_SC1_COCO        equ       7
; bit position masks
mADC_SC1_ADCH0      equ       %00000001
mADC_SC1_ADCH1      equ       %00000010
mADC_SC1_ADCH2      equ       %00000100
mADC_SC1_ADCH3      equ       %00001000
mADC_SC1_ADCH4      equ       %00010000
mADC_SC1_ADCO       equ       %00100000
mADC_SC1_AIEN       equ       %01000000
mADC_SC1_COCO       equ       %10000000


;*** ADC_SC2 Status and Control Register 2
ADC_SC2             equ       $00000011
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC2_FFULL       equ       2
ADC_SC2_FEMPTY      equ       3
ADC_SC2_ACFGT       equ       4
ADC_SC2_ACFE        equ       5
ADC_SC2_ADTRG       equ       6
ADC_SC2_ADACT       equ       7
; bit position masks
mADC_SC2_FFULL      equ       %00000100
mADC_SC2_FEMPTY     equ       %00001000
mADC_SC2_ACFGT      equ       %00010000
mADC_SC2_ACFE       equ       %00100000
mADC_SC2_ADTRG      equ       %01000000
mADC_SC2_ADACT      equ       %10000000


;*** ADC_SC3 Status and Control Register 3
ADC_SC3             equ       $00000012
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC3_ADICLK0     equ       0
ADC_SC3_ADICLK1     equ       1
ADC_SC3_MODE0       equ       2
ADC_SC3_MODE1       equ       3
ADC_SC3_ADLSMP      equ       4
ADC_SC3_ADIV0       equ       5
ADC_SC3_ADIV1       equ       6
ADC_SC3_ADLPC       equ       7
; bit position masks
mADC_SC3_ADICLK0    equ       %00000001
mADC_SC3_ADICLK1    equ       %00000010
mADC_SC3_MODE0      equ       %00000100
mADC_SC3_MODE1      equ       %00001000
mADC_SC3_ADLSMP     equ       %00010000
mADC_SC3_ADIV0      equ       %00100000
mADC_SC3_ADIV1      equ       %01000000
mADC_SC3_ADLPC      equ       %10000000


;*** ADC_SC4 Status and Control Register 4
ADC_SC4             equ       $00000013
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_SC4_AFDEP0      equ       0
ADC_SC4_AFDEP1      equ       1
ADC_SC4_AFDEP2      equ       2
ADC_SC4_ACFSEL      equ       5
ADC_SC4_ASCANE      equ       6
; bit position masks
mADC_SC4_AFDEP0     equ       %00000001
mADC_SC4_AFDEP1     equ       %00000010
mADC_SC4_AFDEP2     equ       %00000100
mADC_SC4_ACFSEL     equ       %00100000
mADC_SC4_ASCANE     equ       %01000000


;*** ADC_R Conversion Result Register
ADC_R               equ       $00000014


;*** ADC_RH Conversion Result High Register
ADC_RH              equ       $00000014
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_RH_ADR0         equ       0
ADC_RH_ADR1         equ       1
; bit position masks
mADC_RH_ADR0        equ       %00000001
mADC_RH_ADR1        equ       %00000010


;*** ADC_RL Conversion Result Low Register
ADC_RL              equ       $00000015
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_RL_ADR0         equ       0
ADC_RL_ADR1         equ       1
ADC_RL_ADR2         equ       2
ADC_RL_ADR3         equ       3
ADC_RL_ADR4         equ       4
ADC_RL_ADR5         equ       5
ADC_RL_ADR6         equ       6
ADC_RL_ADR7         equ       7
; bit position masks
mADC_RL_ADR0        equ       %00000001
mADC_RL_ADR1        equ       %00000010
mADC_RL_ADR2        equ       %00000100
mADC_RL_ADR3        equ       %00001000
mADC_RL_ADR4        equ       %00010000
mADC_RL_ADR5        equ       %00100000
mADC_RL_ADR6        equ       %01000000
mADC_RL_ADR7        equ       %10000000


;*** ADC_CV Compare Value Register
ADC_CV              equ       $00000016


;*** ADC_CVH Compare Value High Register
ADC_CVH             equ       $00000016
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_CVH_CV0         equ       0
ADC_CVH_CV1         equ       1
; bit position masks
mADC_CVH_CV0        equ       %00000001
mADC_CVH_CV1        equ       %00000010


;*** ADC_CVL Compare Value Low Register
ADC_CVL             equ       $00000017
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_CVL_CV0         equ       0
ADC_CVL_CV1         equ       1
ADC_CVL_CV2         equ       2
ADC_CVL_CV3         equ       3
ADC_CVL_CV4         equ       4
ADC_CVL_CV5         equ       5
ADC_CVL_CV6         equ       6
ADC_CVL_CV7         equ       7
; bit position masks
mADC_CVL_CV0        equ       %00000001
mADC_CVL_CV1        equ       %00000010
mADC_CVL_CV2        equ       %00000100
mADC_CVL_CV3        equ       %00001000
mADC_CVL_CV4        equ       %00010000
mADC_CVL_CV5        equ       %00100000
mADC_CVL_CV6        equ       %01000000
mADC_CVL_CV7        equ       %10000000


;*** MTIM0_SC MTIM Status and Control Register
MTIM0_SC            equ       $00000018
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM0_SC_TSTP       equ       4
MTIM0_SC_TRST       equ       5
MTIM0_SC_TOIE       equ       6
MTIM0_SC_TOF        equ       7
; bit position masks
mMTIM0_SC_TSTP      equ       %00010000
mMTIM0_SC_TRST      equ       %00100000
mMTIM0_SC_TOIE      equ       %01000000
mMTIM0_SC_TOF       equ       %10000000


;*** MTIM0_CLK MTIM Clock Configuration Register
MTIM0_CLK           equ       $00000019
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM0_CLK_PS0       equ       0
MTIM0_CLK_PS1       equ       1
MTIM0_CLK_PS2       equ       2
MTIM0_CLK_PS3       equ       3
MTIM0_CLK_CLKS0     equ       4
MTIM0_CLK_CLKS1     equ       5
; bit position masks
mMTIM0_CLK_PS0      equ       %00000001
mMTIM0_CLK_PS1      equ       %00000010
mMTIM0_CLK_PS2      equ       %00000100
mMTIM0_CLK_PS3      equ       %00001000
mMTIM0_CLK_CLKS0    equ       %00010000
mMTIM0_CLK_CLKS1    equ       %00100000


;*** MTIM0_CNT MTIM Counter Register
MTIM0_CNT           equ       $0000001A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM0_CNT_COUNT0    equ       0
MTIM0_CNT_COUNT1    equ       1
MTIM0_CNT_COUNT2    equ       2
MTIM0_CNT_COUNT3    equ       3
MTIM0_CNT_COUNT4    equ       4
MTIM0_CNT_COUNT5    equ       5
MTIM0_CNT_COUNT6    equ       6
MTIM0_CNT_COUNT7    equ       7
; bit position masks
mMTIM0_CNT_COUNT0   equ       %00000001
mMTIM0_CNT_COUNT1   equ       %00000010
mMTIM0_CNT_COUNT2   equ       %00000100
mMTIM0_CNT_COUNT3   equ       %00001000
mMTIM0_CNT_COUNT4   equ       %00010000
mMTIM0_CNT_COUNT5   equ       %00100000
mMTIM0_CNT_COUNT6   equ       %01000000
mMTIM0_CNT_COUNT7   equ       %10000000


;*** MTIM0_MOD MTIM Modulo Register
MTIM0_MOD           equ       $0000001B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM0_MOD_MOD0      equ       0
MTIM0_MOD_MOD1      equ       1
MTIM0_MOD_MOD2      equ       2
MTIM0_MOD_MOD3      equ       3
MTIM0_MOD_MOD4      equ       4
MTIM0_MOD_MOD5      equ       5
MTIM0_MOD_MOD6      equ       6
MTIM0_MOD_MOD7      equ       7
; bit position masks
mMTIM0_MOD_MOD0     equ       %00000001
mMTIM0_MOD_MOD1     equ       %00000010
mMTIM0_MOD_MOD2     equ       %00000100
mMTIM0_MOD_MOD3     equ       %00001000
mMTIM0_MOD_MOD4     equ       %00010000
mMTIM0_MOD_MOD5     equ       %00100000
mMTIM0_MOD_MOD6     equ       %01000000
mMTIM0_MOD_MOD7     equ       %10000000


;*** FTM0_SC Status and Control
FTM0_SC             equ       $00000020
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_SC_PS0         equ       0
FTM0_SC_PS1         equ       1
FTM0_SC_PS2         equ       2
FTM0_SC_CLKS0       equ       3
FTM0_SC_CLKS1       equ       4
FTM0_SC_CPWMS       equ       5
FTM0_SC_TOIE        equ       6
FTM0_SC_TOF         equ       7
; bit position masks
mFTM0_SC_PS0        equ       %00000001
mFTM0_SC_PS1        equ       %00000010
mFTM0_SC_PS2        equ       %00000100
mFTM0_SC_CLKS0      equ       %00001000
mFTM0_SC_CLKS1      equ       %00010000
mFTM0_SC_CPWMS      equ       %00100000
mFTM0_SC_TOIE       equ       %01000000
mFTM0_SC_TOF        equ       %10000000


;*** FTM0_CNT Counter  0x00000021 ***
FTM0_CNT            equ       $00000021


;*** FTM0_CNTH Counter High
FTM0_CNTH           equ       $00000021
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_CNTH_COUNT_H0  equ       0
FTM0_CNTH_COUNT_H1  equ       1
FTM0_CNTH_COUNT_H2  equ       2
FTM0_CNTH_COUNT_H3  equ       3
FTM0_CNTH_COUNT_H4  equ       4
FTM0_CNTH_COUNT_H5  equ       5
FTM0_CNTH_COUNT_H6  equ       6
FTM0_CNTH_COUNT_H7  equ       7
; bit position masks
mFTM0_CNTH_COUNT_H0 equ       %00000001
mFTM0_CNTH_COUNT_H1 equ       %00000010
mFTM0_CNTH_COUNT_H2 equ       %00000100
mFTM0_CNTH_COUNT_H3 equ       %00001000
mFTM0_CNTH_COUNT_H4 equ       %00010000
mFTM0_CNTH_COUNT_H5 equ       %00100000
mFTM0_CNTH_COUNT_H6 equ       %01000000
mFTM0_CNTH_COUNT_H7 equ       %10000000


;*** FTM0_CNTL Counter Low
FTM0_CNTL           equ       $00000022
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_CNTL_COUNT_L0  equ       0
FTM0_CNTL_COUNT_L1  equ       1
FTM0_CNTL_COUNT_L2  equ       2
FTM0_CNTL_COUNT_L3  equ       3
FTM0_CNTL_COUNT_L4  equ       4
FTM0_CNTL_COUNT_L5  equ       5
FTM0_CNTL_COUNT_L6  equ       6
FTM0_CNTL_COUNT_L7  equ       7
; bit position masks
mFTM0_CNTL_COUNT_L0 equ       %00000001
mFTM0_CNTL_COUNT_L1 equ       %00000010
mFTM0_CNTL_COUNT_L2 equ       %00000100
mFTM0_CNTL_COUNT_L3 equ       %00001000
mFTM0_CNTL_COUNT_L4 equ       %00010000
mFTM0_CNTL_COUNT_L5 equ       %00100000
mFTM0_CNTL_COUNT_L6 equ       %01000000
mFTM0_CNTL_COUNT_L7 equ       %10000000


;*** FTM0_MOD Modulo  0x00000023 ***
FTM0_MOD            equ       $00000023


;*** FTM0_MODH Modulo High
FTM0_MODH           equ       $00000023
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_MODH_MOD_H0    equ       0
FTM0_MODH_MOD_H1    equ       1
FTM0_MODH_MOD_H2    equ       2
FTM0_MODH_MOD_H3    equ       3
FTM0_MODH_MOD_H4    equ       4
FTM0_MODH_MOD_H5    equ       5
FTM0_MODH_MOD_H6    equ       6
FTM0_MODH_MOD_H7    equ       7
; bit position masks
mFTM0_MODH_MOD_H0   equ       %00000001
mFTM0_MODH_MOD_H1   equ       %00000010
mFTM0_MODH_MOD_H2   equ       %00000100
mFTM0_MODH_MOD_H3   equ       %00001000
mFTM0_MODH_MOD_H4   equ       %00010000
mFTM0_MODH_MOD_H5   equ       %00100000
mFTM0_MODH_MOD_H6   equ       %01000000
mFTM0_MODH_MOD_H7   equ       %10000000


;*** FTM0_MODL Modulo Low
FTM0_MODL           equ       $00000024
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_MODL_MOD_L0    equ       0
FTM0_MODL_MOD_L1    equ       1
FTM0_MODL_MOD_L2    equ       2
FTM0_MODL_MOD_L3    equ       3
FTM0_MODL_MOD_L4    equ       4
FTM0_MODL_MOD_L5    equ       5
FTM0_MODL_MOD_L6    equ       6
FTM0_MODL_MOD_L7    equ       7
; bit position masks
mFTM0_MODL_MOD_L0   equ       %00000001
mFTM0_MODL_MOD_L1   equ       %00000010
mFTM0_MODL_MOD_L2   equ       %00000100
mFTM0_MODL_MOD_L3   equ       %00001000
mFTM0_MODL_MOD_L4   equ       %00010000
mFTM0_MODL_MOD_L5   equ       %00100000
mFTM0_MODL_MOD_L6   equ       %01000000
mFTM0_MODL_MOD_L7   equ       %10000000


;*** FTM0_C0SC Channel Status and Control
FTM0_C0SC           equ       $00000025
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C0SC_ELSA      equ       2
FTM0_C0SC_ELSB      equ       3
FTM0_C0SC_MSA       equ       4
FTM0_C0SC_MSB       equ       5
FTM0_C0SC_CHIE      equ       6
FTM0_C0SC_CHF       equ       7
; bit position masks
mFTM0_C0SC_ELSA     equ       %00000100
mFTM0_C0SC_ELSB     equ       %00001000
mFTM0_C0SC_MSA      equ       %00010000
mFTM0_C0SC_MSB      equ       %00100000
mFTM0_C0SC_CHIE     equ       %01000000
mFTM0_C0SC_CHF      equ       %10000000


;*** FTM0_C0V Channel Value  0x00000026 ***
FTM0_C0V            equ       $00000026


;*** FTM0_C0VH Channel Value High
FTM0_C0VH           equ       $00000026
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C0VH_VAL_H0    equ       0
FTM0_C0VH_VAL_H1    equ       1
FTM0_C0VH_VAL_H2    equ       2
FTM0_C0VH_VAL_H3    equ       3
FTM0_C0VH_VAL_H4    equ       4
FTM0_C0VH_VAL_H5    equ       5
FTM0_C0VH_VAL_H6    equ       6
FTM0_C0VH_VAL_H7    equ       7
; bit position masks
mFTM0_C0VH_VAL_H0   equ       %00000001
mFTM0_C0VH_VAL_H1   equ       %00000010
mFTM0_C0VH_VAL_H2   equ       %00000100
mFTM0_C0VH_VAL_H3   equ       %00001000
mFTM0_C0VH_VAL_H4   equ       %00010000
mFTM0_C0VH_VAL_H5   equ       %00100000
mFTM0_C0VH_VAL_H6   equ       %01000000
mFTM0_C0VH_VAL_H7   equ       %10000000


;*** FTM0_C0VL Channel Value Low
FTM0_C0VL           equ       $00000027
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C0VL_VAL_L0    equ       0
FTM0_C0VL_VAL_L1    equ       1
FTM0_C0VL_VAL_L2    equ       2
FTM0_C0VL_VAL_L3    equ       3
FTM0_C0VL_VAL_L4    equ       4
FTM0_C0VL_VAL_L5    equ       5
FTM0_C0VL_VAL_L6    equ       6
FTM0_C0VL_VAL_L7    equ       7
; bit position masks
mFTM0_C0VL_VAL_L0   equ       %00000001
mFTM0_C0VL_VAL_L1   equ       %00000010
mFTM0_C0VL_VAL_L2   equ       %00000100
mFTM0_C0VL_VAL_L3   equ       %00001000
mFTM0_C0VL_VAL_L4   equ       %00010000
mFTM0_C0VL_VAL_L5   equ       %00100000
mFTM0_C0VL_VAL_L6   equ       %01000000
mFTM0_C0VL_VAL_L7   equ       %10000000


;*** FTM0_C1SC Channel Status and Control
FTM0_C1SC           equ       $00000028
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C1SC_ELSA      equ       2
FTM0_C1SC_ELSB      equ       3
FTM0_C1SC_MSA       equ       4
FTM0_C1SC_MSB       equ       5
FTM0_C1SC_CHIE      equ       6
FTM0_C1SC_CHF       equ       7
; bit position masks
mFTM0_C1SC_ELSA     equ       %00000100
mFTM0_C1SC_ELSB     equ       %00001000
mFTM0_C1SC_MSA      equ       %00010000
mFTM0_C1SC_MSB      equ       %00100000
mFTM0_C1SC_CHIE     equ       %01000000
mFTM0_C1SC_CHF      equ       %10000000


;*** FTM0_C1V Channel Value  0x00000029 ***
FTM0_C1V            equ       $00000029


;*** FTM0_C1VH Channel Value High
FTM0_C1VH           equ       $00000029
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C1VH_VAL_H0    equ       0
FTM0_C1VH_VAL_H1    equ       1
FTM0_C1VH_VAL_H2    equ       2
FTM0_C1VH_VAL_H3    equ       3
FTM0_C1VH_VAL_H4    equ       4
FTM0_C1VH_VAL_H5    equ       5
FTM0_C1VH_VAL_H6    equ       6
FTM0_C1VH_VAL_H7    equ       7
; bit position masks
mFTM0_C1VH_VAL_H0   equ       %00000001
mFTM0_C1VH_VAL_H1   equ       %00000010
mFTM0_C1VH_VAL_H2   equ       %00000100
mFTM0_C1VH_VAL_H3   equ       %00001000
mFTM0_C1VH_VAL_H4   equ       %00010000
mFTM0_C1VH_VAL_H5   equ       %00100000
mFTM0_C1VH_VAL_H6   equ       %01000000
mFTM0_C1VH_VAL_H7   equ       %10000000


;*** FTM0_C1VL Channel Value Low
FTM0_C1VL           equ       $0000002A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM0_C1VL_VAL_L0    equ       0
FTM0_C1VL_VAL_L1    equ       1
FTM0_C1VL_VAL_L2    equ       2
FTM0_C1VL_VAL_L3    equ       3
FTM0_C1VL_VAL_L4    equ       4
FTM0_C1VL_VAL_L5    equ       5
FTM0_C1VL_VAL_L6    equ       6
FTM0_C1VL_VAL_L7    equ       7
; bit position masks
mFTM0_C1VL_VAL_L0   equ       %00000001
mFTM0_C1VL_VAL_L1   equ       %00000010
mFTM0_C1VL_VAL_L2   equ       %00000100
mFTM0_C1VL_VAL_L3   equ       %00001000
mFTM0_C1VL_VAL_L4   equ       %00010000
mFTM0_C1VL_VAL_L5   equ       %00100000
mFTM0_C1VL_VAL_L6   equ       %01000000
mFTM0_C1VL_VAL_L7   equ       %10000000


;*** IRQ_SC Interrupt Pin Request Status and Control Register
IRQ_SC              equ       $0000003B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQ_SC_IRQMOD       equ       0
IRQ_SC_IRQIE        equ       1
IRQ_SC_IRQACK       equ       2
IRQ_SC_IRQF         equ       3
IRQ_SC_IRQPE        equ       4
IRQ_SC_IRQEDG       equ       5
IRQ_SC_IRQPDD       equ       6
; bit position masks
mIRQ_SC_IRQMOD      equ       %00000001
mIRQ_SC_IRQIE       equ       %00000010
mIRQ_SC_IRQACK      equ       %00000100
mIRQ_SC_IRQF        equ       %00001000
mIRQ_SC_IRQPE       equ       %00010000
mIRQ_SC_IRQEDG      equ       %00100000
mIRQ_SC_IRQPDD      equ       %01000000


;*** KBI0_SC KBI Status and Control Register
KBI0_SC             equ       $0000003C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI0_SC_KBMOD       equ       0
KBI0_SC_KBIE        equ       1
KBI0_SC_KBACK       equ       2
KBI0_SC_KBF         equ       3
; bit position masks
mKBI0_SC_KBMOD      equ       %00000001
mKBI0_SC_KBIE       equ       %00000010
mKBI0_SC_KBACK      equ       %00000100
mKBI0_SC_KBF        equ       %00001000


;*** IPC_SC IPC Status and Control Register
IPC_SC              equ       $0000003E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_SC_IPM0         equ       0
IPC_SC_IPM1         equ       1
IPC_SC_PULIPM       equ       3
IPC_SC_PSF          equ       4
IPC_SC_PSE          equ       5
IPC_SC_IPCE         equ       7
; bit position masks
mIPC_SC_IPM0        equ       %00000001
mIPC_SC_IPM1        equ       %00000010
mIPC_SC_PULIPM      equ       %00001000
mIPC_SC_PSF         equ       %00010000
mIPC_SC_PSE         equ       %00100000
mIPC_SC_IPCE        equ       %10000000


;*** IPC_IPMPS Interrupt Priority Mask Pseudo Stack Register
IPC_IPMPS           equ       $0000003F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_IPMPS_IPM00     equ       0
IPC_IPMPS_IPM01     equ       1
IPC_IPMPS_IPM10     equ       2
IPC_IPMPS_IPM11     equ       3
IPC_IPMPS_IPM20     equ       4
IPC_IPMPS_IPM21     equ       5
IPC_IPMPS_IPM30     equ       6
IPC_IPMPS_IPM31     equ       7
; bit position masks
mIPC_IPMPS_IPM00    equ       %00000001
mIPC_IPMPS_IPM01    equ       %00000010
mIPC_IPMPS_IPM10    equ       %00000100
mIPC_IPMPS_IPM11    equ       %00001000
mIPC_IPMPS_IPM20    equ       %00010000
mIPC_IPMPS_IPM21    equ       %00100000
mIPC_IPMPS_IPM30    equ       %01000000
mIPC_IPMPS_IPM31    equ       %10000000


;*** SYS_SRS System Reset Status Register
SYS_SRS             equ       $00003000
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SRS_LVD         equ       1
SYS_SRS_LOC         equ       2
SYS_SRS_ILAD        equ       3
SYS_SRS_ILOP        equ       4
SYS_SRS_WDOG        equ       5
SYS_SRS_PIN         equ       6
SYS_SRS_POR         equ       7
; bit position masks
mSYS_SRS_LVD        equ       %00000010
mSYS_SRS_LOC        equ       %00000100
mSYS_SRS_ILAD       equ       %00001000
mSYS_SRS_ILOP       equ       %00010000
mSYS_SRS_WDOG       equ       %00100000
mSYS_SRS_PIN        equ       %01000000
mSYS_SRS_POR        equ       %10000000


;*** SYS_SBDFR System Background Debug Force Reset Register
SYS_SBDFR           equ       $00003001
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SBDFR_BDFR      equ       0
; bit position masks
mSYS_SBDFR_BDFR     equ       %00000001


;*** SYS_SDID System Device Identification Register:  0x00003002 ***
SYS_SDID            equ       $00003002


;*** SYS_SDIDH System Device Identification Register: High
SYS_SDIDH           equ       $00003002
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SDIDH_ID0       equ       0
SYS_SDIDH_ID1       equ       1
SYS_SDIDH_ID2       equ       2
SYS_SDIDH_ID3       equ       3
; bit position masks
mSYS_SDIDH_ID0      equ       %00000001
mSYS_SDIDH_ID1      equ       %00000010
mSYS_SDIDH_ID2      equ       %00000100
mSYS_SDIDH_ID3      equ       %00001000


;*** SYS_SDIDL System Device Identification Register: Low
SYS_SDIDL           equ       $00003003
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SDIDL_ID0       equ       0
SYS_SDIDL_ID1       equ       1
SYS_SDIDL_ID2       equ       2
SYS_SDIDL_ID3       equ       3
SYS_SDIDL_ID4       equ       4
SYS_SDIDL_ID5       equ       5
SYS_SDIDL_ID6       equ       6
SYS_SDIDL_ID7       equ       7
; bit position masks
mSYS_SDIDL_ID0      equ       %00000001
mSYS_SDIDL_ID1      equ       %00000010
mSYS_SDIDL_ID2      equ       %00000100
mSYS_SDIDL_ID3      equ       %00001000
mSYS_SDIDL_ID4      equ       %00010000
mSYS_SDIDL_ID5      equ       %00100000
mSYS_SDIDL_ID6      equ       %01000000
mSYS_SDIDL_ID7      equ       %10000000


;*** SYS_SOPT1 System Options Register 1
SYS_SOPT1           equ       $00003004
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT1_STOPE     equ       0
SYS_SOPT1_FWAKE     equ       1
SYS_SOPT1_RSTPE     equ       2
SYS_SOPT1_BKGDPE    equ       3
SYS_SOPT1_FTM2PS    equ       4
SYS_SOPT1_SCI0PS    equ       7
; bit position masks
mSYS_SOPT1_STOPE    equ       %00000001
mSYS_SOPT1_FWAKE    equ       %00000010
mSYS_SOPT1_RSTPE    equ       %00000100
mSYS_SOPT1_BKGDPE   equ       %00001000
mSYS_SOPT1_FTM2PS   equ       %00010000
mSYS_SOPT1_SCI0PS   equ       %10000000


;*** SYS_SOPT2 System Options Register 2
SYS_SOPT2           equ       $00003005
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT2_ADHWTS0   equ       0
SYS_SOPT2_ADHWTS1   equ       1
SYS_SOPT2_RXDCE     equ       4
SYS_SOPT2_TXDME     equ       7
; bit position masks
mSYS_SOPT2_ADHWTS0  equ       %00000001
mSYS_SOPT2_ADHWTS1  equ       %00000010
mSYS_SOPT2_RXDCE    equ       %00010000
mSYS_SOPT2_TXDME    equ       %10000000


;*** SYS_SOPT3 System Options Register 3
SYS_SOPT3           equ       $00003006
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_SOPT3_BUSREF0   equ       0
SYS_SOPT3_BUSREF1   equ       1
SYS_SOPT3_BUSREF2   equ       2
SYS_SOPT3_CLKOE     equ       3
SYS_SOPT3_FTM0PS    equ       6
; bit position masks
mSYS_SOPT3_BUSREF0  equ       %00000001
mSYS_SOPT3_BUSREF1  equ       %00000010
mSYS_SOPT3_BUSREF2  equ       %00000100
mSYS_SOPT3_CLKOE    equ       %00001000
mSYS_SOPT3_FTM0PS   equ       %01000000


;*** SCG_C1 System Clock Gating Control 1 Register
SCG_C1              equ       $0000300C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C1_RTC          equ       0
SCG_C1_MTIM0        equ       1
SCG_C1_FTM0         equ       5
SCG_C1_FTM2         equ       7
; bit position masks
mSCG_C1_RTC         equ       %00000001
mSCG_C1_MTIM0       equ       %00000010
mSCG_C1_FTM0        equ       %00100000
mSCG_C1_FTM2        equ       %10000000


;*** SCG_C2 System Clock Gating Control 2 Register
SCG_C2              equ       $0000300D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C2_CRC          equ       2
SCG_C2_IPC          equ       3
SCG_C2_NVM          equ       4
SCG_C2_DBG          equ       5
; bit position masks
mSCG_C2_CRC         equ       %00000100
mSCG_C2_IPC         equ       %00001000
mSCG_C2_NVM         equ       %00010000
mSCG_C2_DBG         equ       %00100000


;*** SCG_C3 System Clock Gating Control 3 Register
SCG_C3              equ       $0000300E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C3_SCI0         equ       4
SCG_C3_SCI1         equ       5
; bit position masks
mSCG_C3_SCI0        equ       %00010000
mSCG_C3_SCI1        equ       %00100000


;*** SCG_C4 System Clock Gating Control 4 Register
SCG_C4              equ       $0000300F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCG_C4_KBI0         equ       0
SCG_C4_IRQ          equ       3
SCG_C4_ADC          equ       5
; bit position masks
mSCG_C4_KBI0        equ       %00000001
mSCG_C4_IRQ         equ       %00001000
mSCG_C4_ADC         equ       %00100000


;*** DBG_CA Debug Comparator A Register
DBG_CA              equ       $00003010


;*** DBG_CAH Debug Comparator A High Register
DBG_CAH             equ       $00003010
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CAH_CA0         equ       0
DBG_CAH_CA1         equ       1
DBG_CAH_CA2         equ       2
DBG_CAH_CA3         equ       3
DBG_CAH_CA4         equ       4
DBG_CAH_CA5         equ       5
DBG_CAH_CA6         equ       6
DBG_CAH_CA7         equ       7
; bit position masks
mDBG_CAH_CA0        equ       %00000001
mDBG_CAH_CA1        equ       %00000010
mDBG_CAH_CA2        equ       %00000100
mDBG_CAH_CA3        equ       %00001000
mDBG_CAH_CA4        equ       %00010000
mDBG_CAH_CA5        equ       %00100000
mDBG_CAH_CA6        equ       %01000000
mDBG_CAH_CA7        equ       %10000000


;*** DBG_CAL Debug Comparator A Low Register
DBG_CAL             equ       $00003011
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CAL_CA0         equ       0
DBG_CAL_CA1         equ       1
DBG_CAL_CA2         equ       2
DBG_CAL_CA3         equ       3
DBG_CAL_CA4         equ       4
DBG_CAL_CA5         equ       5
DBG_CAL_CA6         equ       6
DBG_CAL_CA7         equ       7
; bit position masks
mDBG_CAL_CA0        equ       %00000001
mDBG_CAL_CA1        equ       %00000010
mDBG_CAL_CA2        equ       %00000100
mDBG_CAL_CA3        equ       %00001000
mDBG_CAL_CA4        equ       %00010000
mDBG_CAL_CA5        equ       %00100000
mDBG_CAL_CA6        equ       %01000000
mDBG_CAL_CA7        equ       %10000000


;*** DBG_CB Debug Comparator B Register
DBG_CB              equ       $00003012


;*** DBG_CBH Debug Comparator B High Register
DBG_CBH             equ       $00003012
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CBH_CB0         equ       0
DBG_CBH_CB1         equ       1
DBG_CBH_CB2         equ       2
DBG_CBH_CB3         equ       3
DBG_CBH_CB4         equ       4
DBG_CBH_CB5         equ       5
DBG_CBH_CB6         equ       6
DBG_CBH_CB7         equ       7
; bit position masks
mDBG_CBH_CB0        equ       %00000001
mDBG_CBH_CB1        equ       %00000010
mDBG_CBH_CB2        equ       %00000100
mDBG_CBH_CB3        equ       %00001000
mDBG_CBH_CB4        equ       %00010000
mDBG_CBH_CB5        equ       %00100000
mDBG_CBH_CB6        equ       %01000000
mDBG_CBH_CB7        equ       %10000000


;*** DBG_CBL Debug Comparator B Low Register
DBG_CBL             equ       $00003013
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CBL_CB0         equ       0
DBG_CBL_CB1         equ       1
DBG_CBL_CB2         equ       2
DBG_CBL_CB3         equ       3
DBG_CBL_CB4         equ       4
DBG_CBL_CB5         equ       5
DBG_CBL_CB6         equ       6
DBG_CBL_CB7         equ       7
; bit position masks
mDBG_CBL_CB0        equ       %00000001
mDBG_CBL_CB1        equ       %00000010
mDBG_CBL_CB2        equ       %00000100
mDBG_CBL_CB3        equ       %00001000
mDBG_CBL_CB4        equ       %00010000
mDBG_CBL_CB5        equ       %00100000
mDBG_CBL_CB6        equ       %01000000
mDBG_CBL_CB7        equ       %10000000


;*** DBG_CC Debug Comparator C Register
DBG_CC              equ       $00003014


;*** DBG_CCH Debug Comparator C High Register
DBG_CCH             equ       $00003014
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CCH_CC0         equ       0
DBG_CCH_CC1         equ       1
DBG_CCH_CC2         equ       2
DBG_CCH_CC3         equ       3
DBG_CCH_CC4         equ       4
DBG_CCH_CC5         equ       5
DBG_CCH_CC6         equ       6
DBG_CCH_CC7         equ       7
; bit position masks
mDBG_CCH_CC0        equ       %00000001
mDBG_CCH_CC1        equ       %00000010
mDBG_CCH_CC2        equ       %00000100
mDBG_CCH_CC3        equ       %00001000
mDBG_CCH_CC4        equ       %00010000
mDBG_CCH_CC5        equ       %00100000
mDBG_CCH_CC6        equ       %01000000
mDBG_CCH_CC7        equ       %10000000


;*** DBG_CCL Debug Comparator C Low Register
DBG_CCL             equ       $00003015
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CCL_CC0         equ       0
DBG_CCL_CC1         equ       1
DBG_CCL_CC2         equ       2
DBG_CCL_CC3         equ       3
DBG_CCL_CC4         equ       4
DBG_CCL_CC5         equ       5
DBG_CCL_CC6         equ       6
DBG_CCL_CC7         equ       7
; bit position masks
mDBG_CCL_CC0        equ       %00000001
mDBG_CCL_CC1        equ       %00000010
mDBG_CCL_CC2        equ       %00000100
mDBG_CCL_CC3        equ       %00001000
mDBG_CCL_CC4        equ       %00010000
mDBG_CCL_CC5        equ       %00100000
mDBG_CCL_CC6        equ       %01000000
mDBG_CCL_CC7        equ       %10000000


;*** DBG_F Debug FIFO Register
DBG_F               equ       $00003016


;*** DBG_FH Debug FIFO High Register
DBG_FH              equ       $00003016
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_FH_F0           equ       0
DBG_FH_F1           equ       1
DBG_FH_F2           equ       2
DBG_FH_F3           equ       3
DBG_FH_F4           equ       4
DBG_FH_F5           equ       5
DBG_FH_F6           equ       6
DBG_FH_F7           equ       7
; bit position masks
mDBG_FH_F0          equ       %00000001
mDBG_FH_F1          equ       %00000010
mDBG_FH_F2          equ       %00000100
mDBG_FH_F3          equ       %00001000
mDBG_FH_F4          equ       %00010000
mDBG_FH_F5          equ       %00100000
mDBG_FH_F6          equ       %01000000
mDBG_FH_F7          equ       %10000000


;*** DBG_FL Debug FIFO Low Register
DBG_FL              equ       $00003017
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_FL_F0           equ       0
DBG_FL_F1           equ       1
DBG_FL_F2           equ       2
DBG_FL_F3           equ       3
DBG_FL_F4           equ       4
DBG_FL_F5           equ       5
DBG_FL_F6           equ       6
DBG_FL_F7           equ       7
; bit position masks
mDBG_FL_F0          equ       %00000001
mDBG_FL_F1          equ       %00000010
mDBG_FL_F2          equ       %00000100
mDBG_FL_F3          equ       %00001000
mDBG_FL_F4          equ       %00010000
mDBG_FL_F5          equ       %00100000
mDBG_FL_F6          equ       %01000000
mDBG_FL_F7          equ       %10000000


;*** DBG_CAX Debug Comparator A Extension Register
DBG_CAX             equ       $00003018
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CAX_RWA         equ       6
DBG_CAX_RWAEN       equ       7
; bit position masks
mDBG_CAX_RWA        equ       %01000000
mDBG_CAX_RWAEN      equ       %10000000


;*** DBG_CBX Debug Comparator B Extension Register
DBG_CBX             equ       $00003019
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CBX_RWB         equ       6
DBG_CBX_RWBEN       equ       7
; bit position masks
mDBG_CBX_RWB        equ       %01000000
mDBG_CBX_RWBEN      equ       %10000000


;*** DBG_CCX Debug Comparator C Extension Register
DBG_CCX             equ       $0000301A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CCX_RWC         equ       6
DBG_CCX_RWCEN       equ       7
; bit position masks
mDBG_CCX_RWC        equ       %01000000
mDBG_CCX_RWCEN      equ       %10000000


;*** DBG_FX Debug FIFO Extended Information Register
DBG_FX              equ       $0000301B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_FX_Bit16        equ       0
DBG_FX_PPACC        equ       7
; bit position masks
mDBG_FX_Bit16       equ       %00000001
mDBG_FX_PPACC       equ       %10000000


;*** DBG_C Debug Control Register
DBG_C               equ       $0000301C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_C_LOOP1         equ       0
DBG_C_BRKEN         equ       4
DBG_C_TAG           equ       5
DBG_C_ARM           equ       6
DBG_C_DBGEN         equ       7
; bit position masks
mDBG_C_LOOP1        equ       %00000001
mDBG_C_BRKEN        equ       %00010000
mDBG_C_TAG          equ       %00100000
mDBG_C_ARM          equ       %01000000
mDBG_C_DBGEN        equ       %10000000


;*** DBG_T Debug Trigger Register
DBG_T               equ       $0000301D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_T_TRG0          equ       0
DBG_T_TRG1          equ       1
DBG_T_TRG2          equ       2
DBG_T_TRG3          equ       3
DBG_T_BEGIN         equ       6
DBG_T_TRGSEL        equ       7
; bit position masks
mDBG_T_TRG0         equ       %00000001
mDBG_T_TRG1         equ       %00000010
mDBG_T_TRG2         equ       %00000100
mDBG_T_TRG3         equ       %00001000
mDBG_T_BEGIN        equ       %01000000
mDBG_T_TRGSEL       equ       %10000000


;*** DBG_S Debug Status Register
DBG_S               equ       $0000301E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_S_ARMF          equ       0
DBG_S_CF            equ       5
DBG_S_BF            equ       6
DBG_S_AF            equ       7
; bit position masks
mDBG_S_ARMF         equ       %00000001
mDBG_S_CF           equ       %00100000
mDBG_S_BF           equ       %01000000
mDBG_S_AF           equ       %10000000


;*** DBG_CNT Debug Count Status Register
DBG_CNT             equ       $0000301F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CNT_CNT0        equ       0
DBG_CNT_CNT1        equ       1
DBG_CNT_CNT2        equ       2
DBG_CNT_CNT3        equ       3
; bit position masks
mDBG_CNT_CNT0       equ       %00000001
mDBG_CNT_CNT1       equ       %00000010
mDBG_CNT_CNT2       equ       %00000100
mDBG_CNT_CNT3       equ       %00001000


;*** NVM_FCLKDIV Flash Clock Divider Register
NVM_FCLKDIV         equ       $00003020
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCLKDIV_FDIV0   equ       0
NVM_FCLKDIV_FDIV1   equ       1
NVM_FCLKDIV_FDIV2   equ       2
NVM_FCLKDIV_FDIV3   equ       3
NVM_FCLKDIV_FDIV4   equ       4
NVM_FCLKDIV_FDIV5   equ       5
NVM_FCLKDIV_FDIVLCK equ       6
NVM_FCLKDIV_FDIVLD  equ       7
; bit position masks
mNVM_FCLKDIV_FDIV0  equ       %00000001
mNVM_FCLKDIV_FDIV1  equ       %00000010
mNVM_FCLKDIV_FDIV2  equ       %00000100
mNVM_FCLKDIV_FDIV3  equ       %00001000
mNVM_FCLKDIV_FDIV4  equ       %00010000
mNVM_FCLKDIV_FDIV5  equ       %00100000
mNVM_FCLKDIV_FDIVLCK equ       %01000000
mNVM_FCLKDIV_FDIVLD equ       %10000000


;*** NVM_FSEC Flash Security Register
NVM_FSEC            equ       $00003021
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


;*** NVM_FCCOBIX Flash CCOB Index Register
NVM_FCCOBIX         equ       $00003022
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCCOBIX_CCOBIX0 equ       0
NVM_FCCOBIX_CCOBIX1 equ       1
NVM_FCCOBIX_CCOBIX2 equ       2
; bit position masks
mNVM_FCCOBIX_CCOBIX0 equ       %00000001
mNVM_FCCOBIX_CCOBIX1 equ       %00000010
mNVM_FCCOBIX_CCOBIX2 equ       %00000100


;*** NVM_FCNFG Flash Configuration Register
NVM_FCNFG           equ       $00003024
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCNFG_FSFD      equ       0
NVM_FCNFG_FDFD      equ       1
NVM_FCNFG_IGNSF     equ       4
NVM_FCNFG_CCIE      equ       7
; bit position masks
mNVM_FCNFG_FSFD     equ       %00000001
mNVM_FCNFG_FDFD     equ       %00000010
mNVM_FCNFG_IGNSF    equ       %00010000
mNVM_FCNFG_CCIE     equ       %10000000


;*** NVM_FERCNFG Flash Error Configuration Register
NVM_FERCNFG         equ       $00003025
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FERCNFG_SFDIE   equ       0
NVM_FERCNFG_DFDIE   equ       1
; bit position masks
mNVM_FERCNFG_SFDIE  equ       %00000001
mNVM_FERCNFG_DFDIE  equ       %00000010


;*** NVM_FSTAT Flash Status Register
NVM_FSTAT           equ       $00003026
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FSTAT_MGSTAT0   equ       0
NVM_FSTAT_MGSTAT1   equ       1
NVM_FSTAT_MGBUSY    equ       3
NVM_FSTAT_FPVIOL    equ       4
NVM_FSTAT_ACCERR    equ       5
NVM_FSTAT_CCIF      equ       7
; bit position masks
mNVM_FSTAT_MGSTAT0  equ       %00000001
mNVM_FSTAT_MGSTAT1  equ       %00000010
mNVM_FSTAT_MGBUSY   equ       %00001000
mNVM_FSTAT_FPVIOL   equ       %00010000
mNVM_FSTAT_ACCERR   equ       %00100000
mNVM_FSTAT_CCIF     equ       %10000000


;*** NVM_FERSTAT Flash Error Status Register
NVM_FERSTAT         equ       $00003027
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FERSTAT_SFDIF   equ       0
NVM_FERSTAT_DFDIF   equ       1
; bit position masks
mNVM_FERSTAT_SFDIF  equ       %00000001
mNVM_FERSTAT_DFDIF  equ       %00000010


;*** NVM_FPROT Flash Protection Register
NVM_FPROT           equ       $00003028
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FPROT_FPHS0     equ       3
NVM_FPROT_FPHS1     equ       4
NVM_FPROT_FPHDIS    equ       5
NVM_FPROT_FPOPEN    equ       7
; bit position masks
mNVM_FPROT_FPHS0    equ       %00001000
mNVM_FPROT_FPHS1    equ       %00010000
mNVM_FPROT_FPHDIS   equ       %00100000
mNVM_FPROT_FPOPEN   equ       %10000000


;*** NVM_EEPROT EEPROM Protection Register
NVM_EEPROT          equ       $00003029
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_EEPROT_DPS0     equ       0
NVM_EEPROT_DPS1     equ       1
NVM_EEPROT_DPS2     equ       2
NVM_EEPROT_DPOPEN   equ       7
; bit position masks
mNVM_EEPROT_DPS0    equ       %00000001
mNVM_EEPROT_DPS1    equ       %00000010
mNVM_EEPROT_DPS2    equ       %00000100
mNVM_EEPROT_DPOPEN  equ       %10000000


;*** NVM_FCCOBHI Flash Common Command Object Register:High
NVM_FCCOBHI         equ       $0000302A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCCOBHI_CCOB0   equ       0
NVM_FCCOBHI_CCOB1   equ       1
NVM_FCCOBHI_CCOB2   equ       2
NVM_FCCOBHI_CCOB3   equ       3
NVM_FCCOBHI_CCOB4   equ       4
NVM_FCCOBHI_CCOB5   equ       5
NVM_FCCOBHI_CCOB6   equ       6
NVM_FCCOBHI_CCOB7   equ       7
; bit position masks
mNVM_FCCOBHI_CCOB0  equ       %00000001
mNVM_FCCOBHI_CCOB1  equ       %00000010
mNVM_FCCOBHI_CCOB2  equ       %00000100
mNVM_FCCOBHI_CCOB3  equ       %00001000
mNVM_FCCOBHI_CCOB4  equ       %00010000
mNVM_FCCOBHI_CCOB5  equ       %00100000
mNVM_FCCOBHI_CCOB6  equ       %01000000
mNVM_FCCOBHI_CCOB7  equ       %10000000


;*** NVM_FCCOBLO Flash Common Command Object Register: Low
NVM_FCCOBLO         equ       $0000302B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FCCOBLO_CCOB0   equ       0
NVM_FCCOBLO_CCOB1   equ       1
NVM_FCCOBLO_CCOB2   equ       2
NVM_FCCOBLO_CCOB3   equ       3
NVM_FCCOBLO_CCOB4   equ       4
NVM_FCCOBLO_CCOB5   equ       5
NVM_FCCOBLO_CCOB6   equ       6
NVM_FCCOBLO_CCOB7   equ       7
; bit position masks
mNVM_FCCOBLO_CCOB0  equ       %00000001
mNVM_FCCOBLO_CCOB1  equ       %00000010
mNVM_FCCOBLO_CCOB2  equ       %00000100
mNVM_FCCOBLO_CCOB3  equ       %00001000
mNVM_FCCOBLO_CCOB4  equ       %00010000
mNVM_FCCOBLO_CCOB5  equ       %00100000
mNVM_FCCOBLO_CCOB6  equ       %01000000
mNVM_FCCOBLO_CCOB7  equ       %10000000


;*** NVM_FOPT Flash Option Register
NVM_FOPT            equ       $0000302C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVM_FOPT_NV0        equ       0
NVM_FOPT_NV1        equ       1
NVM_FOPT_NV2        equ       2
NVM_FOPT_NV3        equ       3
NVM_FOPT_NV4        equ       4
NVM_FOPT_NV5        equ       5
NVM_FOPT_NV6        equ       6
NVM_FOPT_NV7        equ       7
; bit position masks
mNVM_FOPT_NV0       equ       %00000001
mNVM_FOPT_NV1       equ       %00000010
mNVM_FOPT_NV2       equ       %00000100
mNVM_FOPT_NV3       equ       %00001000
mNVM_FOPT_NV4       equ       %00010000
mNVM_FOPT_NV5       equ       %00100000
mNVM_FOPT_NV6       equ       %01000000
mNVM_FOPT_NV7       equ       %10000000


;*** WDOG_CS1 Watchdog Control and Status Register 1
WDOG_CS1            equ       $00003030
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_CS1_STOP       equ       0
WDOG_CS1_WAIT       equ       1
WDOG_CS1_DBG        equ       2
WDOG_CS1_TST0       equ       3
WDOG_CS1_TST1       equ       4
WDOG_CS1_UPDATE     equ       5
WDOG_CS1_INT        equ       6
WDOG_CS1_EN         equ       7
; bit position masks
mWDOG_CS1_STOP      equ       %00000001
mWDOG_CS1_WAIT      equ       %00000010
mWDOG_CS1_DBG       equ       %00000100
mWDOG_CS1_TST0      equ       %00001000
mWDOG_CS1_TST1      equ       %00010000
mWDOG_CS1_UPDATE    equ       %00100000
mWDOG_CS1_INT       equ       %01000000
mWDOG_CS1_EN        equ       %10000000


;*** WDOG_CS2 Watchdog Control and Status Register 2
WDOG_CS2            equ       $00003031
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_CS2_CLK0       equ       0
WDOG_CS2_CLK1       equ       1
WDOG_CS2_PRES       equ       4
WDOG_CS2_FLG        equ       6
WDOG_CS2_WIN        equ       7
; bit position masks
mWDOG_CS2_CLK0      equ       %00000001
mWDOG_CS2_CLK1      equ       %00000010
mWDOG_CS2_PRES      equ       %00010000
mWDOG_CS2_FLG       equ       %01000000
mWDOG_CS2_WIN       equ       %10000000


;*** WDOG_CNT Watchdog Counter Register:  0x00003032 ***
WDOG_CNT            equ       $00003032


;*** WDOG_CNTH Watchdog Counter Register: High
WDOG_CNTH           equ       $00003032
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_CNTH_CNTHIGH0  equ       0
WDOG_CNTH_CNTHIGH1  equ       1
WDOG_CNTH_CNTHIGH2  equ       2
WDOG_CNTH_CNTHIGH3  equ       3
WDOG_CNTH_CNTHIGH4  equ       4
WDOG_CNTH_CNTHIGH5  equ       5
WDOG_CNTH_CNTHIGH6  equ       6
WDOG_CNTH_CNTHIGH7  equ       7
; bit position masks
mWDOG_CNTH_CNTHIGH0 equ       %00000001
mWDOG_CNTH_CNTHIGH1 equ       %00000010
mWDOG_CNTH_CNTHIGH2 equ       %00000100
mWDOG_CNTH_CNTHIGH3 equ       %00001000
mWDOG_CNTH_CNTHIGH4 equ       %00010000
mWDOG_CNTH_CNTHIGH5 equ       %00100000
mWDOG_CNTH_CNTHIGH6 equ       %01000000
mWDOG_CNTH_CNTHIGH7 equ       %10000000


;*** WDOG_CNTL Watchdog Counter Register: Low
WDOG_CNTL           equ       $00003033
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_CNTL_CNTLOW0   equ       0
WDOG_CNTL_CNTLOW1   equ       1
WDOG_CNTL_CNTLOW2   equ       2
WDOG_CNTL_CNTLOW3   equ       3
WDOG_CNTL_CNTLOW4   equ       4
WDOG_CNTL_CNTLOW5   equ       5
WDOG_CNTL_CNTLOW6   equ       6
WDOG_CNTL_CNTLOW7   equ       7
; bit position masks
mWDOG_CNTL_CNTLOW0  equ       %00000001
mWDOG_CNTL_CNTLOW1  equ       %00000010
mWDOG_CNTL_CNTLOW2  equ       %00000100
mWDOG_CNTL_CNTLOW3  equ       %00001000
mWDOG_CNTL_CNTLOW4  equ       %00010000
mWDOG_CNTL_CNTLOW5  equ       %00100000
mWDOG_CNTL_CNTLOW6  equ       %01000000
mWDOG_CNTL_CNTLOW7  equ       %10000000


;*** WDOG_TOVAL Watchdog Timeout Value Register:  0x00003034 ***
WDOG_TOVAL          equ       $00003034


;*** WDOG_TOVALH Watchdog Timeout Value Register: High
WDOG_TOVALH         equ       $00003034
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_TOVALH_TOVALHIGH0 equ       0
WDOG_TOVALH_TOVALHIGH1 equ       1
WDOG_TOVALH_TOVALHIGH2 equ       2
WDOG_TOVALH_TOVALHIGH3 equ       3
WDOG_TOVALH_TOVALHIGH4 equ       4
WDOG_TOVALH_TOVALHIGH5 equ       5
WDOG_TOVALH_TOVALHIGH6 equ       6
WDOG_TOVALH_TOVALHIGH7 equ       7
; bit position masks
mWDOG_TOVALH_TOVALHIGH0 equ       %00000001
mWDOG_TOVALH_TOVALHIGH1 equ       %00000010
mWDOG_TOVALH_TOVALHIGH2 equ       %00000100
mWDOG_TOVALH_TOVALHIGH3 equ       %00001000
mWDOG_TOVALH_TOVALHIGH4 equ       %00010000
mWDOG_TOVALH_TOVALHIGH5 equ       %00100000
mWDOG_TOVALH_TOVALHIGH6 equ       %01000000
mWDOG_TOVALH_TOVALHIGH7 equ       %10000000


;*** WDOG_TOVALL Watchdog Timeout Value Register: Low
WDOG_TOVALL         equ       $00003035
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_TOVALL_TOVALLOW0 equ       0
WDOG_TOVALL_TOVALLOW1 equ       1
WDOG_TOVALL_TOVALLOW2 equ       2
WDOG_TOVALL_TOVALLOW3 equ       3
WDOG_TOVALL_TOVALLOW4 equ       4
WDOG_TOVALL_TOVALLOW5 equ       5
WDOG_TOVALL_TOVALLOW6 equ       6
WDOG_TOVALL_TOVALLOW7 equ       7
; bit position masks
mWDOG_TOVALL_TOVALLOW0 equ       %00000001
mWDOG_TOVALL_TOVALLOW1 equ       %00000010
mWDOG_TOVALL_TOVALLOW2 equ       %00000100
mWDOG_TOVALL_TOVALLOW3 equ       %00001000
mWDOG_TOVALL_TOVALLOW4 equ       %00010000
mWDOG_TOVALL_TOVALLOW5 equ       %00100000
mWDOG_TOVALL_TOVALLOW6 equ       %01000000
mWDOG_TOVALL_TOVALLOW7 equ       %10000000


;*** WDOG_WIN Watchdog Window Register:  0x00003036 ***
WDOG_WIN            equ       $00003036


;*** WDOG_WINH Watchdog Window Register: High
WDOG_WINH           equ       $00003036
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_WINH_WINHIGH0  equ       0
WDOG_WINH_WINHIGH1  equ       1
WDOG_WINH_WINHIGH2  equ       2
WDOG_WINH_WINHIGH3  equ       3
WDOG_WINH_WINHIGH4  equ       4
WDOG_WINH_WINHIGH5  equ       5
WDOG_WINH_WINHIGH6  equ       6
WDOG_WINH_WINHIGH7  equ       7
; bit position masks
mWDOG_WINH_WINHIGH0 equ       %00000001
mWDOG_WINH_WINHIGH1 equ       %00000010
mWDOG_WINH_WINHIGH2 equ       %00000100
mWDOG_WINH_WINHIGH3 equ       %00001000
mWDOG_WINH_WINHIGH4 equ       %00010000
mWDOG_WINH_WINHIGH5 equ       %00100000
mWDOG_WINH_WINHIGH6 equ       %01000000
mWDOG_WINH_WINHIGH7 equ       %10000000


;*** WDOG_WINL Watchdog Window Register: Low
WDOG_WINL           equ       $00003037
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
WDOG_WINL_WINLOW0   equ       0
WDOG_WINL_WINLOW1   equ       1
WDOG_WINL_WINLOW2   equ       2
WDOG_WINL_WINLOW3   equ       3
WDOG_WINL_WINLOW4   equ       4
WDOG_WINL_WINLOW5   equ       5
WDOG_WINL_WINLOW6   equ       6
WDOG_WINL_WINLOW7   equ       7
; bit position masks
mWDOG_WINL_WINLOW0  equ       %00000001
mWDOG_WINL_WINLOW1  equ       %00000010
mWDOG_WINL_WINLOW2  equ       %00000100
mWDOG_WINL_WINLOW3  equ       %00001000
mWDOG_WINL_WINLOW4  equ       %00010000
mWDOG_WINL_WINLOW5  equ       %00100000
mWDOG_WINL_WINLOW6  equ       %01000000
mWDOG_WINL_WINLOW7  equ       %10000000

;*** ICS_C1 ICS Control Register 1
ICS_C1              equ       $00003038
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C1_IREFSTEN     equ       0
ICS_C1_IRCLKEN      equ       1
ICS_C1_IREFS        equ       2
ICS_C1_RDIV0        equ       3
ICS_C1_RDIV1        equ       4
ICS_C1_RDIV2        equ       5
ICS_C1_CLKS0        equ       6
ICS_C1_CLKS1        equ       7
; bit position masks
mICS_C1_IREFSTEN    equ       %00000001
mICS_C1_IRCLKEN     equ       %00000010
mICS_C1_IREFS       equ       %00000100
mICS_C1_RDIV0       equ       %00001000
mICS_C1_RDIV1       equ       %00010000
mICS_C1_RDIV2       equ       %00100000
mICS_C1_CLKS0       equ       %01000000
mICS_C1_CLKS1       equ       %10000000


;*** ICS_C2 ICS Control Register 2
ICS_C2              equ       $00003039
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C2_LP           equ       4
ICS_C2_BDIV0        equ       5
ICS_C2_BDIV1        equ       6
ICS_C2_BDIV2        equ       7
; bit position masks
mICS_C2_LP          equ       %00010000
mICS_C2_BDIV0       equ       %00100000
mICS_C2_BDIV1       equ       %01000000
mICS_C2_BDIV2       equ       %10000000


;*** ICS_C3 ICS Control Register 3
ICS_C3              equ       $0000303A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C3_SCTRIM0      equ       0
ICS_C3_SCTRIM1      equ       1
ICS_C3_SCTRIM2      equ       2
ICS_C3_SCTRIM3      equ       3
ICS_C3_SCTRIM4      equ       4
ICS_C3_SCTRIM5      equ       5
ICS_C3_SCTRIM6      equ       6
ICS_C3_SCTRIM7      equ       7
; bit position masks
mICS_C3_SCTRIM0     equ       %00000001
mICS_C3_SCTRIM1     equ       %00000010
mICS_C3_SCTRIM2     equ       %00000100
mICS_C3_SCTRIM3     equ       %00001000
mICS_C3_SCTRIM4     equ       %00010000
mICS_C3_SCTRIM5     equ       %00100000
mICS_C3_SCTRIM6     equ       %01000000
mICS_C3_SCTRIM7     equ       %10000000


;*** ICS_C4 ICS Control Register 4
ICS_C4              equ       $0000303B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C4_SCFTRIM      equ       0
ICS_C4_CME          equ       5
ICS_C4_LOLIE        equ       7
; bit position masks
mICS_C4_SCFTRIM     equ       %00000001
mICS_C4_CME         equ       %00100000
mICS_C4_LOLIE       equ       %10000000


;*** ICS_S ICS Status Register
ICS_S               equ       $0000303C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_S_CLKST0        equ       2
ICS_S_CLKST1        equ       3
ICS_S_IREFST        equ       4
ICS_S_LOCK          equ       6
ICS_S_LOLS          equ       7
; bit position masks
mICS_S_CLKST0       equ       %00000100
mICS_S_CLKST1       equ       %00001000
mICS_S_IREFST       equ       %00010000
mICS_S_LOCK         equ       %01000000
mICS_S_LOLS         equ       %10000000


;*** ICS_OSCSC OSC Status and Control Register
ICS_OSCSC           equ       $0000303E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_OSCSC_OSCINIT   equ       0
ICS_OSCSC_HGO       equ       1
ICS_OSCSC_RANGE     equ       2
ICS_OSCSC_OSCOS     equ       4
ICS_OSCSC_OSCSTEN   equ       5
ICS_OSCSC_OSCEN     equ       7
; bit position masks
mICS_OSCSC_OSCINIT  equ       %00000001
mICS_OSCSC_HGO      equ       %00000010
mICS_OSCSC_RANGE    equ       %00000100
mICS_OSCSC_OSCOS    equ       %00010000
mICS_OSCSC_OSCSTEN  equ       %00100000
mICS_OSCSC_OSCEN    equ       %10000000


;*** PMC_SPMSC1 System Power Management Status and Control 1 Register
PMC_SPMSC1          equ       $00003040
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_SPMSC1_BGBE     equ       0
PMC_SPMSC1_BGBDS    equ       1
PMC_SPMSC1_LVDE     equ       2
PMC_SPMSC1_LVDSE    equ       3
PMC_SPMSC1_LVDRE    equ       4
PMC_SPMSC1_LVWIE    equ       5
PMC_SPMSC1_LVWACK   equ       6
PMC_SPMSC1_LVWF     equ       7
; bit position masks
mPMC_SPMSC1_BGBE    equ       %00000001
mPMC_SPMSC1_BGBDS   equ       %00000010
mPMC_SPMSC1_LVDE    equ       %00000100
mPMC_SPMSC1_LVDSE   equ       %00001000
mPMC_SPMSC1_LVDRE   equ       %00010000
mPMC_SPMSC1_LVWIE   equ       %00100000
mPMC_SPMSC1_LVWACK  equ       %01000000
mPMC_SPMSC1_LVWF    equ       %10000000


;*** PMC_SPMSC2 System Power Management Status and Control 2 Register
PMC_SPMSC2          equ       $00003041
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_SPMSC2_LVWV0    equ       4
PMC_SPMSC2_LVWV1    equ       5
PMC_SPMSC2_LVDV     equ       6
; bit position masks
mPMC_SPMSC2_LVWV0   equ       %00010000
mPMC_SPMSC2_LVWV1   equ       %00100000
mPMC_SPMSC2_LVDV    equ       %01000000


;*** SYS_ILLA Illegal Address Register:  0x0000304A ***
SYS_ILLA            equ       $0000304A


;*** SYS_ILLAH Illegal Address Register: High
SYS_ILLAH           equ       $0000304A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_ILLAH_ADDR0     equ       0
SYS_ILLAH_ADDR1     equ       1
SYS_ILLAH_ADDR2     equ       2
SYS_ILLAH_ADDR3     equ       3
SYS_ILLAH_ADDR4     equ       4
SYS_ILLAH_ADDR5     equ       5
SYS_ILLAH_ADDR6     equ       6
SYS_ILLAH_ADDR7     equ       7
; bit position masks
mSYS_ILLAH_ADDR0    equ       %00000001
mSYS_ILLAH_ADDR1    equ       %00000010
mSYS_ILLAH_ADDR2    equ       %00000100
mSYS_ILLAH_ADDR3    equ       %00001000
mSYS_ILLAH_ADDR4    equ       %00010000
mSYS_ILLAH_ADDR5    equ       %00100000
mSYS_ILLAH_ADDR6    equ       %01000000
mSYS_ILLAH_ADDR7    equ       %10000000


;*** SYS_ILLAL Illegal Address Register: Low
SYS_ILLAL           equ       $0000304B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_ILLAL_ADDR0     equ       0
SYS_ILLAL_ADDR1     equ       1
SYS_ILLAL_ADDR2     equ       2
SYS_ILLAL_ADDR3     equ       3
SYS_ILLAL_ADDR4     equ       4
SYS_ILLAL_ADDR5     equ       5
SYS_ILLAL_ADDR6     equ       6
SYS_ILLAL_ADDR7     equ       7
; bit position masks
mSYS_ILLAL_ADDR0    equ       %00000001
mSYS_ILLAL_ADDR1    equ       %00000010
mSYS_ILLAL_ADDR2    equ       %00000100
mSYS_ILLAL_ADDR3    equ       %00001000
mSYS_ILLAL_ADDR4    equ       %00010000
mSYS_ILLAL_ADDR5    equ       %00100000
mSYS_ILLAL_ADDR6    equ       %01000000
mSYS_ILLAL_ADDR7    equ       %10000000


;*** IPC_ILRS0 Interrupt Level Setting Registers n
IPC_ILRS0           equ       $00003050
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS0_ILRn00    equ       0
IPC_ILRS0_ILRn01    equ       1
IPC_ILRS0_ILRn10    equ       2
IPC_ILRS0_ILRn11    equ       3
IPC_ILRS0_ILRn20    equ       4
IPC_ILRS0_ILRn21    equ       5
IPC_ILRS0_ILRn30    equ       6
IPC_ILRS0_ILRn31    equ       7
; bit position masks
mIPC_ILRS0_ILRn00   equ       %00000001
mIPC_ILRS0_ILRn01   equ       %00000010
mIPC_ILRS0_ILRn10   equ       %00000100
mIPC_ILRS0_ILRn11   equ       %00001000
mIPC_ILRS0_ILRn20   equ       %00010000
mIPC_ILRS0_ILRn21   equ       %00100000
mIPC_ILRS0_ILRn30   equ       %01000000
mIPC_ILRS0_ILRn31   equ       %10000000


;*** IPC_ILRS1 Interrupt Level Setting Registers n
IPC_ILRS1           equ       $00003051
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS1_ILRn00    equ       0
IPC_ILRS1_ILRn01    equ       1
IPC_ILRS1_ILRn10    equ       2
IPC_ILRS1_ILRn11    equ       3
IPC_ILRS1_ILRn20    equ       4
IPC_ILRS1_ILRn21    equ       5
IPC_ILRS1_ILRn30    equ       6
IPC_ILRS1_ILRn31    equ       7
; bit position masks
mIPC_ILRS1_ILRn00   equ       %00000001
mIPC_ILRS1_ILRn01   equ       %00000010
mIPC_ILRS1_ILRn10   equ       %00000100
mIPC_ILRS1_ILRn11   equ       %00001000
mIPC_ILRS1_ILRn20   equ       %00010000
mIPC_ILRS1_ILRn21   equ       %00100000
mIPC_ILRS1_ILRn30   equ       %01000000
mIPC_ILRS1_ILRn31   equ       %10000000


;*** IPC_ILRS2 Interrupt Level Setting Registers n
IPC_ILRS2           equ       $00003052
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS2_ILRn00    equ       0
IPC_ILRS2_ILRn01    equ       1
IPC_ILRS2_ILRn10    equ       2
IPC_ILRS2_ILRn11    equ       3
IPC_ILRS2_ILRn20    equ       4
IPC_ILRS2_ILRn21    equ       5
IPC_ILRS2_ILRn30    equ       6
IPC_ILRS2_ILRn31    equ       7
; bit position masks
mIPC_ILRS2_ILRn00   equ       %00000001
mIPC_ILRS2_ILRn01   equ       %00000010
mIPC_ILRS2_ILRn10   equ       %00000100
mIPC_ILRS2_ILRn11   equ       %00001000
mIPC_ILRS2_ILRn20   equ       %00010000
mIPC_ILRS2_ILRn21   equ       %00100000
mIPC_ILRS2_ILRn30   equ       %01000000
mIPC_ILRS2_ILRn31   equ       %10000000


;*** IPC_ILRS3 Interrupt Level Setting Registers n
IPC_ILRS3           equ       $00003053
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS3_ILRn00    equ       0
IPC_ILRS3_ILRn01    equ       1
IPC_ILRS3_ILRn10    equ       2
IPC_ILRS3_ILRn11    equ       3
IPC_ILRS3_ILRn20    equ       4
IPC_ILRS3_ILRn21    equ       5
IPC_ILRS3_ILRn30    equ       6
IPC_ILRS3_ILRn31    equ       7
; bit position masks
mIPC_ILRS3_ILRn00   equ       %00000001
mIPC_ILRS3_ILRn01   equ       %00000010
mIPC_ILRS3_ILRn10   equ       %00000100
mIPC_ILRS3_ILRn11   equ       %00001000
mIPC_ILRS3_ILRn20   equ       %00010000
mIPC_ILRS3_ILRn21   equ       %00100000
mIPC_ILRS3_ILRn30   equ       %01000000
mIPC_ILRS3_ILRn31   equ       %10000000


;*** IPC_ILRS4 Interrupt Level Setting Registers n
IPC_ILRS4           equ       $00003054
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS4_ILRn00    equ       0
IPC_ILRS4_ILRn01    equ       1
IPC_ILRS4_ILRn10    equ       2
IPC_ILRS4_ILRn11    equ       3
IPC_ILRS4_ILRn20    equ       4
IPC_ILRS4_ILRn21    equ       5
IPC_ILRS4_ILRn30    equ       6
IPC_ILRS4_ILRn31    equ       7
; bit position masks
mIPC_ILRS4_ILRn00   equ       %00000001
mIPC_ILRS4_ILRn01   equ       %00000010
mIPC_ILRS4_ILRn10   equ       %00000100
mIPC_ILRS4_ILRn11   equ       %00001000
mIPC_ILRS4_ILRn20   equ       %00010000
mIPC_ILRS4_ILRn21   equ       %00100000
mIPC_ILRS4_ILRn30   equ       %01000000
mIPC_ILRS4_ILRn31   equ       %10000000


;*** IPC_ILRS5 Interrupt Level Setting Registers n
IPC_ILRS5           equ       $00003055
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS5_ILRn00    equ       0
IPC_ILRS5_ILRn01    equ       1
IPC_ILRS5_ILRn10    equ       2
IPC_ILRS5_ILRn11    equ       3
IPC_ILRS5_ILRn20    equ       4
IPC_ILRS5_ILRn21    equ       5
IPC_ILRS5_ILRn30    equ       6
IPC_ILRS5_ILRn31    equ       7
; bit position masks
mIPC_ILRS5_ILRn00   equ       %00000001
mIPC_ILRS5_ILRn01   equ       %00000010
mIPC_ILRS5_ILRn10   equ       %00000100
mIPC_ILRS5_ILRn11   equ       %00001000
mIPC_ILRS5_ILRn20   equ       %00010000
mIPC_ILRS5_ILRn21   equ       %00100000
mIPC_ILRS5_ILRn30   equ       %01000000
mIPC_ILRS5_ILRn31   equ       %10000000


;*** IPC_ILRS6 Interrupt Level Setting Registers n
IPC_ILRS6           equ       $00003056
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS6_ILRn00    equ       0
IPC_ILRS6_ILRn01    equ       1
IPC_ILRS6_ILRn10    equ       2
IPC_ILRS6_ILRn11    equ       3
IPC_ILRS6_ILRn20    equ       4
IPC_ILRS6_ILRn21    equ       5
IPC_ILRS6_ILRn30    equ       6
IPC_ILRS6_ILRn31    equ       7
; bit position masks
mIPC_ILRS6_ILRn00   equ       %00000001
mIPC_ILRS6_ILRn01   equ       %00000010
mIPC_ILRS6_ILRn10   equ       %00000100
mIPC_ILRS6_ILRn11   equ       %00001000
mIPC_ILRS6_ILRn20   equ       %00010000
mIPC_ILRS6_ILRn21   equ       %00100000
mIPC_ILRS6_ILRn30   equ       %01000000
mIPC_ILRS6_ILRn31   equ       %10000000


;*** IPC_ILRS7 Interrupt Level Setting Registers n
IPC_ILRS7           equ       $00003057
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS7_ILRn00    equ       0
IPC_ILRS7_ILRn01    equ       1
IPC_ILRS7_ILRn10    equ       2
IPC_ILRS7_ILRn11    equ       3
IPC_ILRS7_ILRn20    equ       4
IPC_ILRS7_ILRn21    equ       5
IPC_ILRS7_ILRn30    equ       6
IPC_ILRS7_ILRn31    equ       7
; bit position masks
mIPC_ILRS7_ILRn00   equ       %00000001
mIPC_ILRS7_ILRn01   equ       %00000010
mIPC_ILRS7_ILRn10   equ       %00000100
mIPC_ILRS7_ILRn11   equ       %00001000
mIPC_ILRS7_ILRn20   equ       %00010000
mIPC_ILRS7_ILRn21   equ       %00100000
mIPC_ILRS7_ILRn30   equ       %01000000
mIPC_ILRS7_ILRn31   equ       %10000000


;*** IPC_ILRS8 Interrupt Level Setting Registers n
IPC_ILRS8           equ       $00003058
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS8_ILRn00    equ       0
IPC_ILRS8_ILRn01    equ       1
IPC_ILRS8_ILRn10    equ       2
IPC_ILRS8_ILRn11    equ       3
IPC_ILRS8_ILRn20    equ       4
IPC_ILRS8_ILRn21    equ       5
IPC_ILRS8_ILRn30    equ       6
IPC_ILRS8_ILRn31    equ       7
; bit position masks
mIPC_ILRS8_ILRn00   equ       %00000001
mIPC_ILRS8_ILRn01   equ       %00000010
mIPC_ILRS8_ILRn10   equ       %00000100
mIPC_ILRS8_ILRn11   equ       %00001000
mIPC_ILRS8_ILRn20   equ       %00010000
mIPC_ILRS8_ILRn21   equ       %00100000
mIPC_ILRS8_ILRn30   equ       %01000000
mIPC_ILRS8_ILRn31   equ       %10000000


;*** IPC_ILRS9 Interrupt Level Setting Registers n
IPC_ILRS9           equ       $00003059
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IPC_ILRS9_ILRn00    equ       0
IPC_ILRS9_ILRn01    equ       1
IPC_ILRS9_ILRn10    equ       2
IPC_ILRS9_ILRn11    equ       3
IPC_ILRS9_ILRn20    equ       4
IPC_ILRS9_ILRn21    equ       5
IPC_ILRS9_ILRn30    equ       6
IPC_ILRS9_ILRn31    equ       7
; bit position masks
mIPC_ILRS9_ILRn00   equ       %00000001
mIPC_ILRS9_ILRn01   equ       %00000010
mIPC_ILRS9_ILRn10   equ       %00000100
mIPC_ILRS9_ILRn11   equ       %00001000
mIPC_ILRS9_ILRn20   equ       %00010000
mIPC_ILRS9_ILRn21   equ       %00100000
mIPC_ILRS9_ILRn30   equ       %01000000
mIPC_ILRS9_ILRn31   equ       %10000000


;*** CRC_D0 CRC Data 0 Register
CRC_D0              equ       $00003060
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_D0_DH00         equ       0
CRC_D0_DH01         equ       1
CRC_D0_DH02         equ       2
CRC_D0_DH03         equ       3
CRC_D0_DH04         equ       4
CRC_D0_DH05         equ       5
CRC_D0_DH06         equ       6
CRC_D0_DH07         equ       7
; bit position masks
mCRC_D0_DH00        equ       %00000001
mCRC_D0_DH01        equ       %00000010
mCRC_D0_DH02        equ       %00000100
mCRC_D0_DH03        equ       %00001000
mCRC_D0_DH04        equ       %00010000
mCRC_D0_DH05        equ       %00100000
mCRC_D0_DH06        equ       %01000000
mCRC_D0_DH07        equ       %10000000


;*** CRC_D1 CRC Data 1 Register
CRC_D1              equ       $00003061
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_D1_D10          equ       0
CRC_D1_D11          equ       1
CRC_D1_D12          equ       2
CRC_D1_D13          equ       3
CRC_D1_D14          equ       4
CRC_D1_D15          equ       5
CRC_D1_D16          equ       6
CRC_D1_D17          equ       7
; bit position masks
mCRC_D1_D10         equ       %00000001
mCRC_D1_D11         equ       %00000010
mCRC_D1_D12         equ       %00000100
mCRC_D1_D13         equ       %00001000
mCRC_D1_D14         equ       %00010000
mCRC_D1_D15         equ       %00100000
mCRC_D1_D16         equ       %01000000
mCRC_D1_D17         equ       %10000000


;*** CRC_D2 CRC Data 2 Register
CRC_D2              equ       $00003062
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_D2_D20          equ       0
CRC_D2_D21          equ       1
CRC_D2_D22          equ       2
CRC_D2_D23          equ       3
CRC_D2_D24          equ       4
CRC_D2_D25          equ       5
CRC_D2_D26          equ       6
CRC_D2_D27          equ       7
; bit position masks
mCRC_D2_D20         equ       %00000001
mCRC_D2_D21         equ       %00000010
mCRC_D2_D22         equ       %00000100
mCRC_D2_D23         equ       %00001000
mCRC_D2_D24         equ       %00010000
mCRC_D2_D25         equ       %00100000
mCRC_D2_D26         equ       %01000000
mCRC_D2_D27         equ       %10000000


;*** CRC_D3 CRC Data 3 Register
CRC_D3              equ       $00003063
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_D3_D30          equ       0
CRC_D3_D31          equ       1
CRC_D3_D32          equ       2
CRC_D3_D33          equ       3
CRC_D3_D34          equ       4
CRC_D3_D35          equ       5
CRC_D3_D36          equ       6
CRC_D3_D37          equ       7
; bit position masks
mCRC_D3_D30         equ       %00000001
mCRC_D3_D31         equ       %00000010
mCRC_D3_D32         equ       %00000100
mCRC_D3_D33         equ       %00001000
mCRC_D3_D34         equ       %00010000
mCRC_D3_D35         equ       %00100000
mCRC_D3_D36         equ       %01000000
mCRC_D3_D37         equ       %10000000


;*** CRC_P0 CRC Polynomial 0 Register
CRC_P0              equ       $00003064
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_P0_P00          equ       0
CRC_P0_P01          equ       1
CRC_P0_P02          equ       2
CRC_P0_P03          equ       3
CRC_P0_P04          equ       4
CRC_P0_P05          equ       5
CRC_P0_P06          equ       6
CRC_P0_P07          equ       7
; bit position masks
mCRC_P0_P00         equ       %00000001
mCRC_P0_P01         equ       %00000010
mCRC_P0_P02         equ       %00000100
mCRC_P0_P03         equ       %00001000
mCRC_P0_P04         equ       %00010000
mCRC_P0_P05         equ       %00100000
mCRC_P0_P06         equ       %01000000
mCRC_P0_P07         equ       %10000000


;*** CRC_P1 CRC Polynomial 1 Register
CRC_P1              equ       $00003065
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_P1_P10          equ       0
CRC_P1_P11          equ       1
CRC_P1_P12          equ       2
CRC_P1_P13          equ       3
CRC_P1_P14          equ       4
CRC_P1_P15          equ       5
CRC_P1_P16          equ       6
CRC_P1_P17          equ       7
; bit position masks
mCRC_P1_P10         equ       %00000001
mCRC_P1_P11         equ       %00000010
mCRC_P1_P12         equ       %00000100
mCRC_P1_P13         equ       %00001000
mCRC_P1_P14         equ       %00010000
mCRC_P1_P15         equ       %00100000
mCRC_P1_P16         equ       %01000000
mCRC_P1_P17         equ       %10000000


;*** CRC_P2 CRC Polynomial 2 Register
CRC_P2              equ       $00003066
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_P2_P20          equ       0
CRC_P2_P21          equ       1
CRC_P2_P22          equ       2
CRC_P2_P23          equ       3
CRC_P2_P24          equ       4
CRC_P2_P25          equ       5
CRC_P2_P26          equ       6
CRC_P2_P27          equ       7
; bit position masks
mCRC_P2_P20         equ       %00000001
mCRC_P2_P21         equ       %00000010
mCRC_P2_P22         equ       %00000100
mCRC_P2_P23         equ       %00001000
mCRC_P2_P24         equ       %00010000
mCRC_P2_P25         equ       %00100000
mCRC_P2_P26         equ       %01000000
mCRC_P2_P27         equ       %10000000


;*** CRC_P3 CRC Polynomial 3 Register
CRC_P3              equ       $00003067
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_P3_P30          equ       0
CRC_P3_P31          equ       1
CRC_P3_P32          equ       2
CRC_P3_P33          equ       3
CRC_P3_P34          equ       4
CRC_P3_P35          equ       5
CRC_P3_P36          equ       6
CRC_P3_P37          equ       7
; bit position masks
mCRC_P3_P30         equ       %00000001
mCRC_P3_P31         equ       %00000010
mCRC_P3_P32         equ       %00000100
mCRC_P3_P33         equ       %00001000
mCRC_P3_P34         equ       %00010000
mCRC_P3_P35         equ       %00100000
mCRC_P3_P36         equ       %01000000
mCRC_P3_P37         equ       %10000000


;*** CRC_CTRL CRC Control Register
CRC_CTRL            equ       $00003068
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRC_CTRL_TCRC       equ       0
CRC_CTRL_WAS        equ       1
CRC_CTRL_FXOR       equ       2
CRC_CTRL_TOTR0      equ       4
CRC_CTRL_TOTR1      equ       5
CRC_CTRL_TOT0       equ       6
CRC_CTRL_TOT1       equ       7
; bit position masks
mCRC_CTRL_TCRC      equ       %00000001
mCRC_CTRL_WAS       equ       %00000010
mCRC_CTRL_FXOR      equ       %00000100
mCRC_CTRL_TOTR0     equ       %00010000
mCRC_CTRL_TOTR1     equ       %00100000
mCRC_CTRL_TOT0      equ       %01000000
mCRC_CTRL_TOT1      equ       %10000000


;*** RTC_SC1 RTC Status and Control Register 1
RTC_SC1             equ       $0000306A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_SC1_RTCO        equ       4
RTC_SC1_RTIE        equ       6
RTC_SC1_RTIF        equ       7
; bit position masks
mRTC_SC1_RTCO       equ       %00010000
mRTC_SC1_RTIE       equ       %01000000
mRTC_SC1_RTIF       equ       %10000000


;*** RTC_SC2 RTC Status and Control Register 2
RTC_SC2             equ       $0000306B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_SC2_RTCPS0      equ       0
RTC_SC2_RTCPS1      equ       1
RTC_SC2_RTCPS2      equ       2
RTC_SC2_RTCLKS0     equ       6
RTC_SC2_RTCLKS1     equ       7
; bit position masks
mRTC_SC2_RTCPS0     equ       %00000001
mRTC_SC2_RTCPS1     equ       %00000010
mRTC_SC2_RTCPS2     equ       %00000100
mRTC_SC2_RTCLKS0    equ       %01000000
mRTC_SC2_RTCLKS1    equ       %10000000


;*** RTC_MOD RTC Modulo Register:  0x0000306C ***
RTC_MOD             equ       $0000306C


;*** RTC_MODH RTC Modulo Register: High
RTC_MODH            equ       $0000306C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_MODH_MODH0      equ       0
RTC_MODH_MODH1      equ       1
RTC_MODH_MODH2      equ       2
RTC_MODH_MODH3      equ       3
RTC_MODH_MODH4      equ       4
RTC_MODH_MODH5      equ       5
RTC_MODH_MODH6      equ       6
RTC_MODH_MODH7      equ       7
; bit position masks
mRTC_MODH_MODH0     equ       %00000001
mRTC_MODH_MODH1     equ       %00000010
mRTC_MODH_MODH2     equ       %00000100
mRTC_MODH_MODH3     equ       %00001000
mRTC_MODH_MODH4     equ       %00010000
mRTC_MODH_MODH5     equ       %00100000
mRTC_MODH_MODH6     equ       %01000000
mRTC_MODH_MODH7     equ       %10000000


;*** RTC_MODL RTC Modulo Register: Low
RTC_MODL            equ       $0000306D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_MODL_MODL0      equ       0
RTC_MODL_MODL1      equ       1
RTC_MODL_MODL2      equ       2
RTC_MODL_MODL3      equ       3
RTC_MODL_MODL4      equ       4
RTC_MODL_MODL5      equ       5
RTC_MODL_MODL6      equ       6
RTC_MODL_MODL7      equ       7
; bit position masks
mRTC_MODL_MODL0     equ       %00000001
mRTC_MODL_MODL1     equ       %00000010
mRTC_MODL_MODL2     equ       %00000100
mRTC_MODL_MODL3     equ       %00001000
mRTC_MODL_MODL4     equ       %00010000
mRTC_MODL_MODL5     equ       %00100000
mRTC_MODL_MODL6     equ       %01000000
mRTC_MODL_MODL7     equ       %10000000


;*** RTC_CNT RTC Counter Register:  0x0000306E ***
RTC_CNT             equ       $0000306E


;*** RTC_CNTH RTC Counter Register: High
RTC_CNTH            equ       $0000306E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_CNTH_CNTH0      equ       0
RTC_CNTH_CNTH1      equ       1
RTC_CNTH_CNTH2      equ       2
RTC_CNTH_CNTH3      equ       3
RTC_CNTH_CNTH4      equ       4
RTC_CNTH_CNTH5      equ       5
RTC_CNTH_CNTH6      equ       6
RTC_CNTH_CNTH7      equ       7
; bit position masks
mRTC_CNTH_CNTH0     equ       %00000001
mRTC_CNTH_CNTH1     equ       %00000010
mRTC_CNTH_CNTH2     equ       %00000100
mRTC_CNTH_CNTH3     equ       %00001000
mRTC_CNTH_CNTH4     equ       %00010000
mRTC_CNTH_CNTH5     equ       %00100000
mRTC_CNTH_CNTH6     equ       %01000000
mRTC_CNTH_CNTH7     equ       %10000000


;*** RTC_CNTL RTC Counter Register: Low
RTC_CNTL            equ       $0000306F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
RTC_CNTL_CNTL0      equ       0
RTC_CNTL_CNTL1      equ       1
RTC_CNTL_CNTL2      equ       2
RTC_CNTL_CNTL3      equ       3
RTC_CNTL_CNTL4      equ       4
RTC_CNTL_CNTL5      equ       5
RTC_CNTL_CNTL6      equ       6
RTC_CNTL_CNTL7      equ       7
; bit position masks
mRTC_CNTL_CNTL0     equ       %00000001
mRTC_CNTL_CNTL1     equ       %00000010
mRTC_CNTL_CNTL2     equ       %00000100
mRTC_CNTL_CNTL3     equ       %00001000
mRTC_CNTL_CNTL4     equ       %00010000
mRTC_CNTL_CNTL5     equ       %00100000
mRTC_CNTL_CNTL6     equ       %01000000
mRTC_CNTL_CNTL7     equ       %10000000


;*** KBI0_PE KBI Pin Enable Register
KBI0_PE             equ       $0000307C
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


;*** KBI0_ES KBI Edge Select Register
KBI0_ES             equ       $0000307D
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


;*** SCI0_BD SCI
SCI0_BD             equ       $00003080


;*** SCI0_BDH SCI
SCI0_BDH            equ       $00003080
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_BDH_SBR0       equ       0
SCI0_BDH_SBR1       equ       1
SCI0_BDH_SBR2       equ       2
SCI0_BDH_SBR3       equ       3
SCI0_BDH_SBR4       equ       4
SCI0_BDH_SBNS       equ       5
SCI0_BDH_RXEDGIE    equ       6
SCI0_BDH_LBKDIE     equ       7
; bit position masks
mSCI0_BDH_SBR0      equ       %00000001
mSCI0_BDH_SBR1      equ       %00000010
mSCI0_BDH_SBR2      equ       %00000100
mSCI0_BDH_SBR3      equ       %00001000
mSCI0_BDH_SBR4      equ       %00010000
mSCI0_BDH_SBNS      equ       %00100000
mSCI0_BDH_RXEDGIE   equ       %01000000
mSCI0_BDH_LBKDIE    equ       %10000000


;*** SCI0_BDL SCI
SCI0_BDL            equ       $00003081
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_BDL_SBR0       equ       0
SCI0_BDL_SBR1       equ       1
SCI0_BDL_SBR2       equ       2
SCI0_BDL_SBR3       equ       3
SCI0_BDL_SBR4       equ       4
SCI0_BDL_SBR5       equ       5
SCI0_BDL_SBR6       equ       6
SCI0_BDL_SBR7       equ       7
; bit position masks
mSCI0_BDL_SBR0      equ       %00000001
mSCI0_BDL_SBR1      equ       %00000010
mSCI0_BDL_SBR2      equ       %00000100
mSCI0_BDL_SBR3      equ       %00001000
mSCI0_BDL_SBR4      equ       %00010000
mSCI0_BDL_SBR5      equ       %00100000
mSCI0_BDL_SBR6      equ       %01000000
mSCI0_BDL_SBR7      equ       %10000000


;*** SCI0_C1 SCI
SCI0_C1             equ       $00003082
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_C1_PT          equ       0
SCI0_C1_PE          equ       1
SCI0_C1_ILT         equ       2
SCI0_C1_WAKE        equ       3
SCI0_C1_M           equ       4
SCI0_C1_RSRC        equ       5
SCI0_C1_SCISWAI     equ       6
SCI0_C1_LOOPS       equ       7
; bit position masks
mSCI0_C1_PT         equ       %00000001
mSCI0_C1_PE         equ       %00000010
mSCI0_C1_ILT        equ       %00000100
mSCI0_C1_WAKE       equ       %00001000
mSCI0_C1_M          equ       %00010000
mSCI0_C1_RSRC       equ       %00100000
mSCI0_C1_SCISWAI    equ       %01000000
mSCI0_C1_LOOPS      equ       %10000000


;*** SCI0_C2 SCI
SCI0_C2             equ       $00003083
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_C2_SBK         equ       0
SCI0_C2_RWU         equ       1
SCI0_C2_RE          equ       2
SCI0_C2_TE          equ       3
SCI0_C2_ILIE        equ       4
SCI0_C2_RIE         equ       5
SCI0_C2_TCIE        equ       6
SCI0_C2_TIE         equ       7
; bit position masks
mSCI0_C2_SBK        equ       %00000001
mSCI0_C2_RWU        equ       %00000010
mSCI0_C2_RE         equ       %00000100
mSCI0_C2_TE         equ       %00001000
mSCI0_C2_ILIE       equ       %00010000
mSCI0_C2_RIE        equ       %00100000
mSCI0_C2_TCIE       equ       %01000000
mSCI0_C2_TIE        equ       %10000000


;*** SCI0_S1 SCI
SCI0_S1             equ       $00003084
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_S1_PF          equ       0
SCI0_S1_FE          equ       1
SCI0_S1_NF          equ       2
SCI0_S1_OR          equ       3
SCI0_S1_IDLE        equ       4
SCI0_S1_RDRF        equ       5
SCI0_S1_TC          equ       6
SCI0_S1_TDRE        equ       7
; bit position masks
mSCI0_S1_PF         equ       %00000001
mSCI0_S1_FE         equ       %00000010
mSCI0_S1_NF         equ       %00000100
mSCI0_S1_OR         equ       %00001000
mSCI0_S1_IDLE       equ       %00010000
mSCI0_S1_RDRF       equ       %00100000
mSCI0_S1_TC         equ       %01000000
mSCI0_S1_TDRE       equ       %10000000


;*** SCI0_S2 SCI
SCI0_S2             equ       $00003085
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_S2_RAF         equ       0
SCI0_S2_LBKDE       equ       1
SCI0_S2_BRK13       equ       2
SCI0_S2_RWUID       equ       3
SCI0_S2_RXINV       equ       4
SCI0_S2_RXEDGIF     equ       6
SCI0_S2_LBKDIF      equ       7
; bit position masks
mSCI0_S2_RAF        equ       %00000001
mSCI0_S2_LBKDE      equ       %00000010
mSCI0_S2_BRK13      equ       %00000100
mSCI0_S2_RWUID      equ       %00001000
mSCI0_S2_RXINV      equ       %00010000
mSCI0_S2_RXEDGIF    equ       %01000000
mSCI0_S2_LBKDIF     equ       %10000000


;*** SCI0_C3 SCI
SCI0_C3             equ       $00003086
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_C3_PEIE        equ       0
SCI0_C3_FEIE        equ       1
SCI0_C3_NEIE        equ       2
SCI0_C3_ORIE        equ       3
SCI0_C3_TXINV       equ       4
SCI0_C3_TXDIR       equ       5
SCI0_C3_T8          equ       6
SCI0_C3_R8          equ       7
; bit position masks
mSCI0_C3_PEIE       equ       %00000001
mSCI0_C3_FEIE       equ       %00000010
mSCI0_C3_NEIE       equ       %00000100
mSCI0_C3_ORIE       equ       %00001000
mSCI0_C3_TXINV      equ       %00010000
mSCI0_C3_TXDIR      equ       %00100000
mSCI0_C3_T8         equ       %01000000
mSCI0_C3_R8         equ       %10000000


;*** SCI0_D SCI
SCI0_D              equ       $00003087
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0_D_R0T0         equ       0
SCI0_D_R1T1         equ       1
SCI0_D_R2T2         equ       2
SCI0_D_R3T3         equ       3
SCI0_D_R4T4         equ       4
SCI0_D_R5T5         equ       5
SCI0_D_R6T6         equ       6
SCI0_D_R7T7         equ       7
; bit position masks
mSCI0_D_R0T0        equ       %00000001
mSCI0_D_R1T1        equ       %00000010
mSCI0_D_R2T2        equ       %00000100
mSCI0_D_R3T3        equ       %00001000
mSCI0_D_R4T4        equ       %00010000
mSCI0_D_R5T5        equ       %00100000
mSCI0_D_R6T6        equ       %01000000
mSCI0_D_R7T7        equ       %10000000


;*** SCI1_BD SCI
SCI1_BD             equ       $00003088


;*** SCI1_BDH SCI
SCI1_BDH            equ       $00003088
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_BDH_SBR0       equ       0
SCI1_BDH_SBR1       equ       1
SCI1_BDH_SBR2       equ       2
SCI1_BDH_SBR3       equ       3
SCI1_BDH_SBR4       equ       4
SCI1_BDH_SBNS       equ       5
SCI1_BDH_RXEDGIE    equ       6
SCI1_BDH_LBKDIE     equ       7
; bit position masks
mSCI1_BDH_SBR0      equ       %00000001
mSCI1_BDH_SBR1      equ       %00000010
mSCI1_BDH_SBR2      equ       %00000100
mSCI1_BDH_SBR3      equ       %00001000
mSCI1_BDH_SBR4      equ       %00010000
mSCI1_BDH_SBNS      equ       %00100000
mSCI1_BDH_RXEDGIE   equ       %01000000
mSCI1_BDH_LBKDIE    equ       %10000000


;*** SCI1_BDL SCI
SCI1_BDL            equ       $00003089
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_BDL_SBR0       equ       0
SCI1_BDL_SBR1       equ       1
SCI1_BDL_SBR2       equ       2
SCI1_BDL_SBR3       equ       3
SCI1_BDL_SBR4       equ       4
SCI1_BDL_SBR5       equ       5
SCI1_BDL_SBR6       equ       6
SCI1_BDL_SBR7       equ       7
; bit position masks
mSCI1_BDL_SBR0      equ       %00000001
mSCI1_BDL_SBR1      equ       %00000010
mSCI1_BDL_SBR2      equ       %00000100
mSCI1_BDL_SBR3      equ       %00001000
mSCI1_BDL_SBR4      equ       %00010000
mSCI1_BDL_SBR5      equ       %00100000
mSCI1_BDL_SBR6      equ       %01000000
mSCI1_BDL_SBR7      equ       %10000000


;*** SCI1_C1 SCI
SCI1_C1             equ       $0000308A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_C1_PT          equ       0
SCI1_C1_PE          equ       1
SCI1_C1_ILT         equ       2
SCI1_C1_WAKE        equ       3
SCI1_C1_M           equ       4
SCI1_C1_RSRC        equ       5
SCI1_C1_SCISWAI     equ       6
SCI1_C1_LOOPS       equ       7
; bit position masks
mSCI1_C1_PT         equ       %00000001
mSCI1_C1_PE         equ       %00000010
mSCI1_C1_ILT        equ       %00000100
mSCI1_C1_WAKE       equ       %00001000
mSCI1_C1_M          equ       %00010000
mSCI1_C1_RSRC       equ       %00100000
mSCI1_C1_SCISWAI    equ       %01000000
mSCI1_C1_LOOPS      equ       %10000000


;*** SCI1_C2 SCI
SCI1_C2             equ       $0000308B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_C2_SBK         equ       0
SCI1_C2_RWU         equ       1
SCI1_C2_RE          equ       2
SCI1_C2_TE          equ       3
SCI1_C2_ILIE        equ       4
SCI1_C2_RIE         equ       5
SCI1_C2_TCIE        equ       6
SCI1_C2_TIE         equ       7
; bit position masks
mSCI1_C2_SBK        equ       %00000001
mSCI1_C2_RWU        equ       %00000010
mSCI1_C2_RE         equ       %00000100
mSCI1_C2_TE         equ       %00001000
mSCI1_C2_ILIE       equ       %00010000
mSCI1_C2_RIE        equ       %00100000
mSCI1_C2_TCIE       equ       %01000000
mSCI1_C2_TIE        equ       %10000000


;*** SCI1_S1 SCI
SCI1_S1             equ       $0000308C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_S1_PF          equ       0
SCI1_S1_FE          equ       1
SCI1_S1_NF          equ       2
SCI1_S1_OR          equ       3
SCI1_S1_IDLE        equ       4
SCI1_S1_RDRF        equ       5
SCI1_S1_TC          equ       6
SCI1_S1_TDRE        equ       7
; bit position masks
mSCI1_S1_PF         equ       %00000001
mSCI1_S1_FE         equ       %00000010
mSCI1_S1_NF         equ       %00000100
mSCI1_S1_OR         equ       %00001000
mSCI1_S1_IDLE       equ       %00010000
mSCI1_S1_RDRF       equ       %00100000
mSCI1_S1_TC         equ       %01000000
mSCI1_S1_TDRE       equ       %10000000


;*** SCI1_S2 SCI
SCI1_S2             equ       $0000308D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_S2_RAF         equ       0
SCI1_S2_LBKDE       equ       1
SCI1_S2_BRK13       equ       2
SCI1_S2_RWUID       equ       3
SCI1_S2_RXINV       equ       4
SCI1_S2_RXEDGIF     equ       6
SCI1_S2_LBKDIF      equ       7
; bit position masks
mSCI1_S2_RAF        equ       %00000001
mSCI1_S2_LBKDE      equ       %00000010
mSCI1_S2_BRK13      equ       %00000100
mSCI1_S2_RWUID      equ       %00001000
mSCI1_S2_RXINV      equ       %00010000
mSCI1_S2_RXEDGIF    equ       %01000000
mSCI1_S2_LBKDIF     equ       %10000000


;*** SCI1_C3 SCI
SCI1_C3             equ       $0000308E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_C3_PEIE        equ       0
SCI1_C3_FEIE        equ       1
SCI1_C3_NEIE        equ       2
SCI1_C3_ORIE        equ       3
SCI1_C3_TXINV       equ       4
SCI1_C3_TXDIR       equ       5
SCI1_C3_T8          equ       6
SCI1_C3_R8          equ       7
; bit position masks
mSCI1_C3_PEIE       equ       %00000001
mSCI1_C3_FEIE       equ       %00000010
mSCI1_C3_NEIE       equ       %00000100
mSCI1_C3_ORIE       equ       %00001000
mSCI1_C3_TXINV      equ       %00010000
mSCI1_C3_TXDIR      equ       %00100000
mSCI1_C3_T8         equ       %01000000
mSCI1_C3_R8         equ       %10000000


;*** SCI1_D SCI
SCI1_D              equ       $0000308F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1_D_R0T0         equ       0
SCI1_D_R1T1         equ       1
SCI1_D_R2T2         equ       2
SCI1_D_R3T3         equ       3
SCI1_D_R4T4         equ       4
SCI1_D_R5T5         equ       5
SCI1_D_R6T6         equ       6
SCI1_D_R7T7         equ       7
; bit position masks
mSCI1_D_R0T0        equ       %00000001
mSCI1_D_R1T1        equ       %00000010
mSCI1_D_R2T2        equ       %00000100
mSCI1_D_R3T3        equ       %00001000
mSCI1_D_R4T4        equ       %00010000
mSCI1_D_R5T5        equ       %00100000
mSCI1_D_R6T6        equ       %01000000
mSCI1_D_R7T7        equ       %10000000


;*** ADC_APCTL1 Pin Control 1 Register
ADC_APCTL1          equ       $000030AC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_APCTL1_ADPC0    equ       0
ADC_APCTL1_ADPC1    equ       1
ADC_APCTL1_ADPC2    equ       2
ADC_APCTL1_ADPC3    equ       3
ADC_APCTL1_ADPC4    equ       4
ADC_APCTL1_ADPC5    equ       5
ADC_APCTL1_ADPC6    equ       6
ADC_APCTL1_ADPC7    equ       7
; bit position masks
mADC_APCTL1_ADPC0   equ       %00000001
mADC_APCTL1_ADPC1   equ       %00000010
mADC_APCTL1_ADPC2   equ       %00000100
mADC_APCTL1_ADPC3   equ       %00001000
mADC_APCTL1_ADPC4   equ       %00010000
mADC_APCTL1_ADPC5   equ       %00100000
mADC_APCTL1_ADPC6   equ       %01000000
mADC_APCTL1_ADPC7   equ       %10000000


;*** ADC_APCTL2 Pin Control 2 Register
ADC_APCTL2          equ       $000030AD
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC_APCTL2_ADPC8    equ       0
ADC_APCTL2_ADPC9    equ       1
ADC_APCTL2_ADPC10   equ       2
ADC_APCTL2_ADPC11   equ       3
; bit position masks
mADC_APCTL2_ADPC8   equ       %00000001
mADC_APCTL2_ADPC9   equ       %00000010
mADC_APCTL2_ADPC10  equ       %00000100
mADC_APCTL2_ADPC11  equ       %00001000


;*** PORT_PTAOE Port A Output Enable Register
PORT_PTAOE          equ       $000030B0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAOE_PTAOE0   equ       0
PORT_PTAOE_PTAOE1   equ       1
PORT_PTAOE_PTAOE2   equ       2
PORT_PTAOE_PTAOE3   equ       3
PORT_PTAOE_PTAOE4   equ       4
PORT_PTAOE_PTAOE5   equ       5
PORT_PTAOE_PTAOE6   equ       6
PORT_PTAOE_PTAOE7   equ       7
; bit position masks
mPORT_PTAOE_PTAOE0  equ       %00000001
mPORT_PTAOE_PTAOE1  equ       %00000010
mPORT_PTAOE_PTAOE2  equ       %00000100
mPORT_PTAOE_PTAOE3  equ       %00001000
mPORT_PTAOE_PTAOE4  equ       %00010000
mPORT_PTAOE_PTAOE5  equ       %00100000
mPORT_PTAOE_PTAOE6  equ       %01000000
mPORT_PTAOE_PTAOE7  equ       %10000000


;*** PORT_PTBOE Port B Output Enable Register
PORT_PTBOE          equ       $000030B1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBOE_PTBOE0   equ       0
PORT_PTBOE_PTBOE1   equ       1
PORT_PTBOE_PTBOE2   equ       2
PORT_PTBOE_PTBOE3   equ       3
PORT_PTBOE_PTBOE4   equ       4
PORT_PTBOE_PTBOE5   equ       5
PORT_PTBOE_PTBOE6   equ       6
PORT_PTBOE_PTBOE7   equ       7
; bit position masks
mPORT_PTBOE_PTBOE0  equ       %00000001
mPORT_PTBOE_PTBOE1  equ       %00000010
mPORT_PTBOE_PTBOE2  equ       %00000100
mPORT_PTBOE_PTBOE3  equ       %00001000
mPORT_PTBOE_PTBOE4  equ       %00010000
mPORT_PTBOE_PTBOE5  equ       %00100000
mPORT_PTBOE_PTBOE6  equ       %01000000
mPORT_PTBOE_PTBOE7  equ       %10000000


;*** PORT_PTCOE Port C Output Enable Register
PORT_PTCOE          equ       $000030B2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCOE_PTCOE0   equ       0
PORT_PTCOE_PTCOE1   equ       1
PORT_PTCOE_PTCOE2   equ       2
PORT_PTCOE_PTCOE3   equ       3
PORT_PTCOE_PTCOE4   equ       4
PORT_PTCOE_PTCOE5   equ       5
PORT_PTCOE_PTCOE6   equ       6
PORT_PTCOE_PTCOE7   equ       7
; bit position masks
mPORT_PTCOE_PTCOE0  equ       %00000001
mPORT_PTCOE_PTCOE1  equ       %00000010
mPORT_PTCOE_PTCOE2  equ       %00000100
mPORT_PTCOE_PTCOE3  equ       %00001000
mPORT_PTCOE_PTCOE4  equ       %00010000
mPORT_PTCOE_PTCOE5  equ       %00100000
mPORT_PTCOE_PTCOE6  equ       %01000000
mPORT_PTCOE_PTCOE7  equ       %10000000


;*** PORT_PTDOE Port D Output Enable Register
PORT_PTDOE          equ       $000030B3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDOE_PTDOE0   equ       0
PORT_PTDOE_PTDOE1   equ       1
PORT_PTDOE_PTDOE2   equ       2
PORT_PTDOE_PTDOE6   equ       6
PORT_PTDOE_PTDOE7   equ       7
; bit position masks
mPORT_PTDOE_PTDOE0  equ       %00000001
mPORT_PTDOE_PTDOE1  equ       %00000010
mPORT_PTDOE_PTDOE2  equ       %00000100
mPORT_PTDOE_PTDOE6  equ       %01000000
mPORT_PTDOE_PTDOE7  equ       %10000000


;*** PORT_PTEOE Port E Output Enable Register
PORT_PTEOE          equ       $000030B4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTEOE_PTEOE4   equ       4
; bit position masks
mPORT_PTEOE_PTEOE4  equ       %00010000


;*** PORT_PTAIE Port A Input Enable Register
PORT_PTAIE          equ       $000030B8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAIE_PTAIE0   equ       0
PORT_PTAIE_PTAIE1   equ       1
PORT_PTAIE_PTAIE2   equ       2
PORT_PTAIE_PTAIE3   equ       3
PORT_PTAIE_PTAIE5   equ       5
PORT_PTAIE_PTAIE6   equ       6
PORT_PTAIE_PTAIE7   equ       7
; bit position masks
mPORT_PTAIE_PTAIE0  equ       %00000001
mPORT_PTAIE_PTAIE1  equ       %00000010
mPORT_PTAIE_PTAIE2  equ       %00000100
mPORT_PTAIE_PTAIE3  equ       %00001000
mPORT_PTAIE_PTAIE5  equ       %00100000
mPORT_PTAIE_PTAIE6  equ       %01000000
mPORT_PTAIE_PTAIE7  equ       %10000000


;*** PORT_PTBIE Port B Input Enable Register
PORT_PTBIE          equ       $000030B9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBIE_PTBIE0   equ       0
PORT_PTBIE_PTBIE1   equ       1
PORT_PTBIE_PTBIE2   equ       2
PORT_PTBIE_PTBIE3   equ       3
PORT_PTBIE_PTBIE4   equ       4
PORT_PTBIE_PTBIE5   equ       5
PORT_PTBIE_PTBIE6   equ       6
PORT_PTBIE_PTBIE7   equ       7
; bit position masks
mPORT_PTBIE_PTBIE0  equ       %00000001
mPORT_PTBIE_PTBIE1  equ       %00000010
mPORT_PTBIE_PTBIE2  equ       %00000100
mPORT_PTBIE_PTBIE3  equ       %00001000
mPORT_PTBIE_PTBIE4  equ       %00010000
mPORT_PTBIE_PTBIE5  equ       %00100000
mPORT_PTBIE_PTBIE6  equ       %01000000
mPORT_PTBIE_PTBIE7  equ       %10000000


;*** PORT_PTCIE Port C Input Enable Register
PORT_PTCIE          equ       $000030BA
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCIE_PTCIE0   equ       0
PORT_PTCIE_PTCIE1   equ       1
PORT_PTCIE_PTCIE2   equ       2
PORT_PTCIE_PTCIE3   equ       3
PORT_PTCIE_PTCIE4   equ       4
PORT_PTCIE_PTCIE5   equ       5
PORT_PTCIE_PTCIE6   equ       6
PORT_PTCIE_PTCIE7   equ       7
; bit position masks
mPORT_PTCIE_PTCIE0  equ       %00000001
mPORT_PTCIE_PTCIE1  equ       %00000010
mPORT_PTCIE_PTCIE2  equ       %00000100
mPORT_PTCIE_PTCIE3  equ       %00001000
mPORT_PTCIE_PTCIE4  equ       %00010000
mPORT_PTCIE_PTCIE5  equ       %00100000
mPORT_PTCIE_PTCIE6  equ       %01000000
mPORT_PTCIE_PTCIE7  equ       %10000000


;*** PORT_PTDIE Port D Input Enable Register
PORT_PTDIE          equ       $000030BB
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDIE_PTDIE0   equ       0
PORT_PTDIE_PTDIE1   equ       1
PORT_PTDIE_PTDIE2   equ       2
PORT_PTDIE_PTDIE6   equ       6
PORT_PTDIE_PTDIE7   equ       7
; bit position masks
mPORT_PTDIE_PTDIE0  equ       %00000001
mPORT_PTDIE_PTDIE1  equ       %00000010
mPORT_PTDIE_PTDIE2  equ       %00000100
mPORT_PTDIE_PTDIE6  equ       %01000000
mPORT_PTDIE_PTDIE7  equ       %10000000


;*** PORT_PTEIE Port E Input Enable Register
PORT_PTEIE          equ       $000030BC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTEIE_PTEIE4   equ       4
; bit position masks
mPORT_PTEIE_PTEIE4  equ       %00010000


;*** FTM2_SC Status and Control
FTM2_SC             equ       $000030C0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_SC_PS0         equ       0
FTM2_SC_PS1         equ       1
FTM2_SC_PS2         equ       2
FTM2_SC_CLKS0       equ       3
FTM2_SC_CLKS1       equ       4
FTM2_SC_CPWMS       equ       5
FTM2_SC_TOIE        equ       6
FTM2_SC_TOF         equ       7
; bit position masks
mFTM2_SC_PS0        equ       %00000001
mFTM2_SC_PS1        equ       %00000010
mFTM2_SC_PS2        equ       %00000100
mFTM2_SC_CLKS0      equ       %00001000
mFTM2_SC_CLKS1      equ       %00010000
mFTM2_SC_CPWMS      equ       %00100000
mFTM2_SC_TOIE       equ       %01000000
mFTM2_SC_TOF        equ       %10000000


;*** FTM2_CNT Counter  0x000030C1 ***
FTM2_CNT            equ       $000030C1


;*** FTM2_CNTH Counter High
FTM2_CNTH           equ       $000030C1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_CNTH_COUNT_H0  equ       0
FTM2_CNTH_COUNT_H1  equ       1
FTM2_CNTH_COUNT_H2  equ       2
FTM2_CNTH_COUNT_H3  equ       3
FTM2_CNTH_COUNT_H4  equ       4
FTM2_CNTH_COUNT_H5  equ       5
FTM2_CNTH_COUNT_H6  equ       6
FTM2_CNTH_COUNT_H7  equ       7
; bit position masks
mFTM2_CNTH_COUNT_H0 equ       %00000001
mFTM2_CNTH_COUNT_H1 equ       %00000010
mFTM2_CNTH_COUNT_H2 equ       %00000100
mFTM2_CNTH_COUNT_H3 equ       %00001000
mFTM2_CNTH_COUNT_H4 equ       %00010000
mFTM2_CNTH_COUNT_H5 equ       %00100000
mFTM2_CNTH_COUNT_H6 equ       %01000000
mFTM2_CNTH_COUNT_H7 equ       %10000000


;*** FTM2_CNTL Counter Low
FTM2_CNTL           equ       $000030C2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_CNTL_COUNT_L0  equ       0
FTM2_CNTL_COUNT_L1  equ       1
FTM2_CNTL_COUNT_L2  equ       2
FTM2_CNTL_COUNT_L3  equ       3
FTM2_CNTL_COUNT_L4  equ       4
FTM2_CNTL_COUNT_L5  equ       5
FTM2_CNTL_COUNT_L6  equ       6
FTM2_CNTL_COUNT_L7  equ       7
; bit position masks
mFTM2_CNTL_COUNT_L0 equ       %00000001
mFTM2_CNTL_COUNT_L1 equ       %00000010
mFTM2_CNTL_COUNT_L2 equ       %00000100
mFTM2_CNTL_COUNT_L3 equ       %00001000
mFTM2_CNTL_COUNT_L4 equ       %00010000
mFTM2_CNTL_COUNT_L5 equ       %00100000
mFTM2_CNTL_COUNT_L6 equ       %01000000
mFTM2_CNTL_COUNT_L7 equ       %10000000


;*** FTM2_MOD Modulo  0x000030C3 ***
FTM2_MOD            equ       $000030C3


;*** FTM2_MODH Modulo High
FTM2_MODH           equ       $000030C3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_MODH_MOD_H0    equ       0
FTM2_MODH_MOD_H1    equ       1
FTM2_MODH_MOD_H2    equ       2
FTM2_MODH_MOD_H3    equ       3
FTM2_MODH_MOD_H4    equ       4
FTM2_MODH_MOD_H5    equ       5
FTM2_MODH_MOD_H6    equ       6
FTM2_MODH_MOD_H7    equ       7
; bit position masks
mFTM2_MODH_MOD_H0   equ       %00000001
mFTM2_MODH_MOD_H1   equ       %00000010
mFTM2_MODH_MOD_H2   equ       %00000100
mFTM2_MODH_MOD_H3   equ       %00001000
mFTM2_MODH_MOD_H4   equ       %00010000
mFTM2_MODH_MOD_H5   equ       %00100000
mFTM2_MODH_MOD_H6   equ       %01000000
mFTM2_MODH_MOD_H7   equ       %10000000


;*** FTM2_MODL Modulo Low
FTM2_MODL           equ       $000030C4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_MODL_MOD_L0    equ       0
FTM2_MODL_MOD_L1    equ       1
FTM2_MODL_MOD_L2    equ       2
FTM2_MODL_MOD_L3    equ       3
FTM2_MODL_MOD_L4    equ       4
FTM2_MODL_MOD_L5    equ       5
FTM2_MODL_MOD_L6    equ       6
FTM2_MODL_MOD_L7    equ       7
; bit position masks
mFTM2_MODL_MOD_L0   equ       %00000001
mFTM2_MODL_MOD_L1   equ       %00000010
mFTM2_MODL_MOD_L2   equ       %00000100
mFTM2_MODL_MOD_L3   equ       %00001000
mFTM2_MODL_MOD_L4   equ       %00010000
mFTM2_MODL_MOD_L5   equ       %00100000
mFTM2_MODL_MOD_L6   equ       %01000000
mFTM2_MODL_MOD_L7   equ       %10000000


;*** FTM2_C0SC Channel Status and Control
FTM2_C0SC           equ       $000030C5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C0SC_ELSA      equ       2
FTM2_C0SC_ELSB      equ       3
FTM2_C0SC_MSA       equ       4
FTM2_C0SC_MSB       equ       5
FTM2_C0SC_CHIE      equ       6
FTM2_C0SC_CHF       equ       7
; bit position masks
mFTM2_C0SC_ELSA     equ       %00000100
mFTM2_C0SC_ELSB     equ       %00001000
mFTM2_C0SC_MSA      equ       %00010000
mFTM2_C0SC_MSB      equ       %00100000
mFTM2_C0SC_CHIE     equ       %01000000
mFTM2_C0SC_CHF      equ       %10000000


;*** FTM2_C0V Channel Value  0x000030C6 ***
FTM2_C0V            equ       $000030C6


;*** FTM2_C0VH Channel Value High
FTM2_C0VH           equ       $000030C6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C0VH_VAL_H0    equ       0
FTM2_C0VH_VAL_H1    equ       1
FTM2_C0VH_VAL_H2    equ       2
FTM2_C0VH_VAL_H3    equ       3
FTM2_C0VH_VAL_H4    equ       4
FTM2_C0VH_VAL_H5    equ       5
FTM2_C0VH_VAL_H6    equ       6
FTM2_C0VH_VAL_H7    equ       7
; bit position masks
mFTM2_C0VH_VAL_H0   equ       %00000001
mFTM2_C0VH_VAL_H1   equ       %00000010
mFTM2_C0VH_VAL_H2   equ       %00000100
mFTM2_C0VH_VAL_H3   equ       %00001000
mFTM2_C0VH_VAL_H4   equ       %00010000
mFTM2_C0VH_VAL_H5   equ       %00100000
mFTM2_C0VH_VAL_H6   equ       %01000000
mFTM2_C0VH_VAL_H7   equ       %10000000


;*** FTM2_C0VL Channel Value Low
FTM2_C0VL           equ       $000030C7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C0VL_VAL_L0    equ       0
FTM2_C0VL_VAL_L1    equ       1
FTM2_C0VL_VAL_L2    equ       2
FTM2_C0VL_VAL_L3    equ       3
FTM2_C0VL_VAL_L4    equ       4
FTM2_C0VL_VAL_L5    equ       5
FTM2_C0VL_VAL_L6    equ       6
FTM2_C0VL_VAL_L7    equ       7
; bit position masks
mFTM2_C0VL_VAL_L0   equ       %00000001
mFTM2_C0VL_VAL_L1   equ       %00000010
mFTM2_C0VL_VAL_L2   equ       %00000100
mFTM2_C0VL_VAL_L3   equ       %00001000
mFTM2_C0VL_VAL_L4   equ       %00010000
mFTM2_C0VL_VAL_L5   equ       %00100000
mFTM2_C0VL_VAL_L6   equ       %01000000
mFTM2_C0VL_VAL_L7   equ       %10000000


;*** FTM2_C1SC Channel Status and Control
FTM2_C1SC           equ       $000030C8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C1SC_ELSA      equ       2
FTM2_C1SC_ELSB      equ       3
FTM2_C1SC_MSA       equ       4
FTM2_C1SC_MSB       equ       5
FTM2_C1SC_CHIE      equ       6
FTM2_C1SC_CHF       equ       7
; bit position masks
mFTM2_C1SC_ELSA     equ       %00000100
mFTM2_C1SC_ELSB     equ       %00001000
mFTM2_C1SC_MSA      equ       %00010000
mFTM2_C1SC_MSB      equ       %00100000
mFTM2_C1SC_CHIE     equ       %01000000
mFTM2_C1SC_CHF      equ       %10000000


;*** FTM2_C1V Channel Value  0x000030C9 ***
FTM2_C1V            equ       $000030C9


;*** FTM2_C1VH Channel Value High
FTM2_C1VH           equ       $000030C9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C1VH_VAL_H0    equ       0
FTM2_C1VH_VAL_H1    equ       1
FTM2_C1VH_VAL_H2    equ       2
FTM2_C1VH_VAL_H3    equ       3
FTM2_C1VH_VAL_H4    equ       4
FTM2_C1VH_VAL_H5    equ       5
FTM2_C1VH_VAL_H6    equ       6
FTM2_C1VH_VAL_H7    equ       7
; bit position masks
mFTM2_C1VH_VAL_H0   equ       %00000001
mFTM2_C1VH_VAL_H1   equ       %00000010
mFTM2_C1VH_VAL_H2   equ       %00000100
mFTM2_C1VH_VAL_H3   equ       %00001000
mFTM2_C1VH_VAL_H4   equ       %00010000
mFTM2_C1VH_VAL_H5   equ       %00100000
mFTM2_C1VH_VAL_H6   equ       %01000000
mFTM2_C1VH_VAL_H7   equ       %10000000


;*** FTM2_C1VL Channel Value Low
FTM2_C1VL           equ       $000030CA
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C1VL_VAL_L0    equ       0
FTM2_C1VL_VAL_L1    equ       1
FTM2_C1VL_VAL_L2    equ       2
FTM2_C1VL_VAL_L3    equ       3
FTM2_C1VL_VAL_L4    equ       4
FTM2_C1VL_VAL_L5    equ       5
FTM2_C1VL_VAL_L6    equ       6
FTM2_C1VL_VAL_L7    equ       7
; bit position masks
mFTM2_C1VL_VAL_L0   equ       %00000001
mFTM2_C1VL_VAL_L1   equ       %00000010
mFTM2_C1VL_VAL_L2   equ       %00000100
mFTM2_C1VL_VAL_L3   equ       %00001000
mFTM2_C1VL_VAL_L4   equ       %00010000
mFTM2_C1VL_VAL_L5   equ       %00100000
mFTM2_C1VL_VAL_L6   equ       %01000000
mFTM2_C1VL_VAL_L7   equ       %10000000


;*** FTM2_C2SC Channel Status and Control
FTM2_C2SC           equ       $000030CB
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C2SC_ELSA      equ       2
FTM2_C2SC_ELSB      equ       3
FTM2_C2SC_MSA       equ       4
FTM2_C2SC_MSB       equ       5
FTM2_C2SC_CHIE      equ       6
FTM2_C2SC_CHF       equ       7
; bit position masks
mFTM2_C2SC_ELSA     equ       %00000100
mFTM2_C2SC_ELSB     equ       %00001000
mFTM2_C2SC_MSA      equ       %00010000
mFTM2_C2SC_MSB      equ       %00100000
mFTM2_C2SC_CHIE     equ       %01000000
mFTM2_C2SC_CHF      equ       %10000000


;*** FTM2_C2V Channel Value  0x000030CC ***
FTM2_C2V            equ       $000030CC


;*** FTM2_C2VH Channel Value High
FTM2_C2VH           equ       $000030CC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C2VH_VAL_H0    equ       0
FTM2_C2VH_VAL_H1    equ       1
FTM2_C2VH_VAL_H2    equ       2
FTM2_C2VH_VAL_H3    equ       3
FTM2_C2VH_VAL_H4    equ       4
FTM2_C2VH_VAL_H5    equ       5
FTM2_C2VH_VAL_H6    equ       6
FTM2_C2VH_VAL_H7    equ       7
; bit position masks
mFTM2_C2VH_VAL_H0   equ       %00000001
mFTM2_C2VH_VAL_H1   equ       %00000010
mFTM2_C2VH_VAL_H2   equ       %00000100
mFTM2_C2VH_VAL_H3   equ       %00001000
mFTM2_C2VH_VAL_H4   equ       %00010000
mFTM2_C2VH_VAL_H5   equ       %00100000
mFTM2_C2VH_VAL_H6   equ       %01000000
mFTM2_C2VH_VAL_H7   equ       %10000000


;*** FTM2_C2VL Channel Value Low
FTM2_C2VL           equ       $000030CD
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C2VL_VAL_L0    equ       0
FTM2_C2VL_VAL_L1    equ       1
FTM2_C2VL_VAL_L2    equ       2
FTM2_C2VL_VAL_L3    equ       3
FTM2_C2VL_VAL_L4    equ       4
FTM2_C2VL_VAL_L5    equ       5
FTM2_C2VL_VAL_L6    equ       6
FTM2_C2VL_VAL_L7    equ       7
; bit position masks
mFTM2_C2VL_VAL_L0   equ       %00000001
mFTM2_C2VL_VAL_L1   equ       %00000010
mFTM2_C2VL_VAL_L2   equ       %00000100
mFTM2_C2VL_VAL_L3   equ       %00001000
mFTM2_C2VL_VAL_L4   equ       %00010000
mFTM2_C2VL_VAL_L5   equ       %00100000
mFTM2_C2VL_VAL_L6   equ       %01000000
mFTM2_C2VL_VAL_L7   equ       %10000000


;*** FTM2_C3SC Channel Status and Control
FTM2_C3SC           equ       $000030CE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C3SC_ELSA      equ       2
FTM2_C3SC_ELSB      equ       3
FTM2_C3SC_MSA       equ       4
FTM2_C3SC_MSB       equ       5
FTM2_C3SC_CHIE      equ       6
FTM2_C3SC_CHF       equ       7
; bit position masks
mFTM2_C3SC_ELSA     equ       %00000100
mFTM2_C3SC_ELSB     equ       %00001000
mFTM2_C3SC_MSA      equ       %00010000
mFTM2_C3SC_MSB      equ       %00100000
mFTM2_C3SC_CHIE     equ       %01000000
mFTM2_C3SC_CHF      equ       %10000000


;*** FTM2_C3V Channel Value  0x000030CF ***
FTM2_C3V            equ       $000030CF


;*** FTM2_C3VH Channel Value High
FTM2_C3VH           equ       $000030CF
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C3VH_VAL_H0    equ       0
FTM2_C3VH_VAL_H1    equ       1
FTM2_C3VH_VAL_H2    equ       2
FTM2_C3VH_VAL_H3    equ       3
FTM2_C3VH_VAL_H4    equ       4
FTM2_C3VH_VAL_H5    equ       5
FTM2_C3VH_VAL_H6    equ       6
FTM2_C3VH_VAL_H7    equ       7
; bit position masks
mFTM2_C3VH_VAL_H0   equ       %00000001
mFTM2_C3VH_VAL_H1   equ       %00000010
mFTM2_C3VH_VAL_H2   equ       %00000100
mFTM2_C3VH_VAL_H3   equ       %00001000
mFTM2_C3VH_VAL_H4   equ       %00010000
mFTM2_C3VH_VAL_H5   equ       %00100000
mFTM2_C3VH_VAL_H6   equ       %01000000
mFTM2_C3VH_VAL_H7   equ       %10000000


;*** FTM2_C3VL Channel Value Low
FTM2_C3VL           equ       $000030D0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C3VL_VAL_L0    equ       0
FTM2_C3VL_VAL_L1    equ       1
FTM2_C3VL_VAL_L2    equ       2
FTM2_C3VL_VAL_L3    equ       3
FTM2_C3VL_VAL_L4    equ       4
FTM2_C3VL_VAL_L5    equ       5
FTM2_C3VL_VAL_L6    equ       6
FTM2_C3VL_VAL_L7    equ       7
; bit position masks
mFTM2_C3VL_VAL_L0   equ       %00000001
mFTM2_C3VL_VAL_L1   equ       %00000010
mFTM2_C3VL_VAL_L2   equ       %00000100
mFTM2_C3VL_VAL_L3   equ       %00001000
mFTM2_C3VL_VAL_L4   equ       %00010000
mFTM2_C3VL_VAL_L5   equ       %00100000
mFTM2_C3VL_VAL_L6   equ       %01000000
mFTM2_C3VL_VAL_L7   equ       %10000000


;*** FTM2_C4SC Channel Status and Control
FTM2_C4SC           equ       $000030D1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C4SC_ELSA      equ       2
FTM2_C4SC_ELSB      equ       3
FTM2_C4SC_MSA       equ       4
FTM2_C4SC_MSB       equ       5
FTM2_C4SC_CHIE      equ       6
FTM2_C4SC_CHF       equ       7
; bit position masks
mFTM2_C4SC_ELSA     equ       %00000100
mFTM2_C4SC_ELSB     equ       %00001000
mFTM2_C4SC_MSA      equ       %00010000
mFTM2_C4SC_MSB      equ       %00100000
mFTM2_C4SC_CHIE     equ       %01000000
mFTM2_C4SC_CHF      equ       %10000000


;*** FTM2_C4V Channel Value  0x000030D2 ***
FTM2_C4V            equ       $000030D2


;*** FTM2_C4VH Channel Value High
FTM2_C4VH           equ       $000030D2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C4VH_VAL_H0    equ       0
FTM2_C4VH_VAL_H1    equ       1
FTM2_C4VH_VAL_H2    equ       2
FTM2_C4VH_VAL_H3    equ       3
FTM2_C4VH_VAL_H4    equ       4
FTM2_C4VH_VAL_H5    equ       5
FTM2_C4VH_VAL_H6    equ       6
FTM2_C4VH_VAL_H7    equ       7
; bit position masks
mFTM2_C4VH_VAL_H0   equ       %00000001
mFTM2_C4VH_VAL_H1   equ       %00000010
mFTM2_C4VH_VAL_H2   equ       %00000100
mFTM2_C4VH_VAL_H3   equ       %00001000
mFTM2_C4VH_VAL_H4   equ       %00010000
mFTM2_C4VH_VAL_H5   equ       %00100000
mFTM2_C4VH_VAL_H6   equ       %01000000
mFTM2_C4VH_VAL_H7   equ       %10000000


;*** FTM2_C4VL Channel Value Low
FTM2_C4VL           equ       $000030D3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C4VL_VAL_L0    equ       0
FTM2_C4VL_VAL_L1    equ       1
FTM2_C4VL_VAL_L2    equ       2
FTM2_C4VL_VAL_L3    equ       3
FTM2_C4VL_VAL_L4    equ       4
FTM2_C4VL_VAL_L5    equ       5
FTM2_C4VL_VAL_L6    equ       6
FTM2_C4VL_VAL_L7    equ       7
; bit position masks
mFTM2_C4VL_VAL_L0   equ       %00000001
mFTM2_C4VL_VAL_L1   equ       %00000010
mFTM2_C4VL_VAL_L2   equ       %00000100
mFTM2_C4VL_VAL_L3   equ       %00001000
mFTM2_C4VL_VAL_L4   equ       %00010000
mFTM2_C4VL_VAL_L5   equ       %00100000
mFTM2_C4VL_VAL_L6   equ       %01000000
mFTM2_C4VL_VAL_L7   equ       %10000000


;*** FTM2_C5SC Channel Status and Control
FTM2_C5SC           equ       $000030D4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C5SC_ELSA      equ       2
FTM2_C5SC_ELSB      equ       3
FTM2_C5SC_MSA       equ       4
FTM2_C5SC_MSB       equ       5
FTM2_C5SC_CHIE      equ       6
FTM2_C5SC_CHF       equ       7
; bit position masks
mFTM2_C5SC_ELSA     equ       %00000100
mFTM2_C5SC_ELSB     equ       %00001000
mFTM2_C5SC_MSA      equ       %00010000
mFTM2_C5SC_MSB      equ       %00100000
mFTM2_C5SC_CHIE     equ       %01000000
mFTM2_C5SC_CHF      equ       %10000000


;*** FTM2_C5V Channel Value  0x000030D5 ***
FTM2_C5V            equ       $000030D5


;*** FTM2_C5VH Channel Value High
FTM2_C5VH           equ       $000030D5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C5VH_VAL_H0    equ       0
FTM2_C5VH_VAL_H1    equ       1
FTM2_C5VH_VAL_H2    equ       2
FTM2_C5VH_VAL_H3    equ       3
FTM2_C5VH_VAL_H4    equ       4
FTM2_C5VH_VAL_H5    equ       5
FTM2_C5VH_VAL_H6    equ       6
FTM2_C5VH_VAL_H7    equ       7
; bit position masks
mFTM2_C5VH_VAL_H0   equ       %00000001
mFTM2_C5VH_VAL_H1   equ       %00000010
mFTM2_C5VH_VAL_H2   equ       %00000100
mFTM2_C5VH_VAL_H3   equ       %00001000
mFTM2_C5VH_VAL_H4   equ       %00010000
mFTM2_C5VH_VAL_H5   equ       %00100000
mFTM2_C5VH_VAL_H6   equ       %01000000
mFTM2_C5VH_VAL_H7   equ       %10000000


;*** FTM2_C5VL Channel Value Low
FTM2_C5VL           equ       $000030D6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTM2_C5VL_VAL_L0    equ       0
FTM2_C5VL_VAL_L1    equ       1
FTM2_C5VL_VAL_L2    equ       2
FTM2_C5VL_VAL_L3    equ       3
FTM2_C5VL_VAL_L4    equ       4
FTM2_C5VL_VAL_L5    equ       5
FTM2_C5VL_VAL_L6    equ       6
FTM2_C5VL_VAL_L7    equ       7
; bit position masks
mFTM2_C5VL_VAL_L0   equ       %00000001
mFTM2_C5VL_VAL_L1   equ       %00000010
mFTM2_C5VL_VAL_L2   equ       %00000100
mFTM2_C5VL_VAL_L3   equ       %00001000
mFTM2_C5VL_VAL_L4   equ       %00010000
mFTM2_C5VL_VAL_L5   equ       %00100000
mFTM2_C5VL_VAL_L6   equ       %01000000
mFTM2_C5VL_VAL_L7   equ       %10000000


;*** PORT_IOFLT0 Port Filter Register 0
PORT_IOFLT0         equ       $000030EC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT0_FLTA0   equ       0
PORT_IOFLT0_FLTA1   equ       1
PORT_IOFLT0_FLTB0   equ       2
PORT_IOFLT0_FLTB1   equ       3
PORT_IOFLT0_FLTC0   equ       4
PORT_IOFLT0_FLTC1   equ       5
PORT_IOFLT0_FLTD0   equ       6
PORT_IOFLT0_FLTD1   equ       7
; bit position masks
mPORT_IOFLT0_FLTA0  equ       %00000001
mPORT_IOFLT0_FLTA1  equ       %00000010
mPORT_IOFLT0_FLTB0  equ       %00000100
mPORT_IOFLT0_FLTB1  equ       %00001000
mPORT_IOFLT0_FLTC0  equ       %00010000
mPORT_IOFLT0_FLTC1  equ       %00100000
mPORT_IOFLT0_FLTD0  equ       %01000000
mPORT_IOFLT0_FLTD1  equ       %10000000


;*** PORT_IOFLT1 Port Filter Register 1
PORT_IOFLT1         equ       $000030ED
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT1_FLTE0   equ       0
PORT_IOFLT1_FLTE1   equ       1
; bit position masks
mPORT_IOFLT1_FLTE0  equ       %00000001
mPORT_IOFLT1_FLTE1  equ       %00000010


;*** PORT_IOFLT2 Port Filter Register 2
PORT_IOFLT2         equ       $000030EE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT2_FLTRST0 equ       0
PORT_IOFLT2_FLTRST1 equ       1
PORT_IOFLT2_FLTKBI00 equ       2
PORT_IOFLT2_FLTKBI01 equ       3
; bit position masks
mPORT_IOFLT2_FLTRST0 equ       %00000001
mPORT_IOFLT2_FLTRST1 equ       %00000010
mPORT_IOFLT2_FLTKBI00 equ       %00000100
mPORT_IOFLT2_FLTKBI01 equ       %00001000


;*** PORT_FCLKDIV Port Clock Division Register
PORT_FCLKDIV        equ       $000030EF
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_FCLKDIV_FLTDIV10 equ       0
PORT_FCLKDIV_FLTDIV11 equ       1
PORT_FCLKDIV_FLTDIV20 equ       2
PORT_FCLKDIV_FLTDIV21 equ       3
PORT_FCLKDIV_FLTDIV22 equ       4
PORT_FCLKDIV_FLTDIV30 equ       5
PORT_FCLKDIV_FLTDIV31 equ       6
PORT_FCLKDIV_FLTDIV32 equ       7
; bit position masks
mPORT_FCLKDIV_FLTDIV10 equ       %00000001
mPORT_FCLKDIV_FLTDIV11 equ       %00000010
mPORT_FCLKDIV_FLTDIV20 equ       %00000100
mPORT_FCLKDIV_FLTDIV21 equ       %00001000
mPORT_FCLKDIV_FLTDIV22 equ       %00010000
mPORT_FCLKDIV_FLTDIV30 equ       %00100000
mPORT_FCLKDIV_FLTDIV31 equ       %01000000
mPORT_FCLKDIV_FLTDIV32 equ       %10000000


;*** PORT_PTAPE Port A Pullup Enable Register
PORT_PTAPE          equ       $000030F0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTAPE_PTAPE0   equ       0
PORT_PTAPE_PTAPE1   equ       1
PORT_PTAPE_PTAPE2   equ       2
PORT_PTAPE_PTAPE3   equ       3
PORT_PTAPE_PTAPE5   equ       5
PORT_PTAPE_PTAPE6   equ       6
PORT_PTAPE_PTAPE7   equ       7
; bit position masks
mPORT_PTAPE_PTAPE0  equ       %00000001
mPORT_PTAPE_PTAPE1  equ       %00000010
mPORT_PTAPE_PTAPE2  equ       %00000100
mPORT_PTAPE_PTAPE3  equ       %00001000
mPORT_PTAPE_PTAPE5  equ       %00100000
mPORT_PTAPE_PTAPE6  equ       %01000000
mPORT_PTAPE_PTAPE7  equ       %10000000


;*** PORT_PTBPE Port B Pullup Enable Register
PORT_PTBPE          equ       $000030F1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBPE_PTBPE0   equ       0
PORT_PTBPE_PTBPE1   equ       1
PORT_PTBPE_PTBPE2   equ       2
PORT_PTBPE_PTBPE3   equ       3
PORT_PTBPE_PTBPE4   equ       4
PORT_PTBPE_PTBPE5   equ       5
PORT_PTBPE_PTBPE6   equ       6
PORT_PTBPE_PTBPE7   equ       7
; bit position masks
mPORT_PTBPE_PTBPE0  equ       %00000001
mPORT_PTBPE_PTBPE1  equ       %00000010
mPORT_PTBPE_PTBPE2  equ       %00000100
mPORT_PTBPE_PTBPE3  equ       %00001000
mPORT_PTBPE_PTBPE4  equ       %00010000
mPORT_PTBPE_PTBPE5  equ       %00100000
mPORT_PTBPE_PTBPE6  equ       %01000000
mPORT_PTBPE_PTBPE7  equ       %10000000


;*** PORT_PTCPE Port C Pullup Enable Register
PORT_PTCPE          equ       $000030F2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCPE_PTCPE0   equ       0
PORT_PTCPE_PTCPE1   equ       1
PORT_PTCPE_PTCPE2   equ       2
PORT_PTCPE_PTCPE3   equ       3
PORT_PTCPE_PTCPE4   equ       4
PORT_PTCPE_PTCPE5   equ       5
PORT_PTCPE_PTCPE6   equ       6
PORT_PTCPE_PTCPE7   equ       7
; bit position masks
mPORT_PTCPE_PTCPE0  equ       %00000001
mPORT_PTCPE_PTCPE1  equ       %00000010
mPORT_PTCPE_PTCPE2  equ       %00000100
mPORT_PTCPE_PTCPE3  equ       %00001000
mPORT_PTCPE_PTCPE4  equ       %00010000
mPORT_PTCPE_PTCPE5  equ       %00100000
mPORT_PTCPE_PTCPE6  equ       %01000000
mPORT_PTCPE_PTCPE7  equ       %10000000


;*** PORT_PTDPE Port D Pullup Enable Register
PORT_PTDPE          equ       $000030F3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTDPE_PTDPE0   equ       0
PORT_PTDPE_PTDPE1   equ       1
PORT_PTDPE_PTDPE2   equ       2
PORT_PTDPE_PTDPE6   equ       6
PORT_PTDPE_PTDPE7   equ       7
; bit position masks
mPORT_PTDPE_PTDPE0  equ       %00000001
mPORT_PTDPE_PTDPE1  equ       %00000010
mPORT_PTDPE_PTDPE2  equ       %00000100
mPORT_PTDPE_PTDPE6  equ       %01000000
mPORT_PTDPE_PTDPE7  equ       %10000000


;*** PORT_PTEPE Port E Pullup Enable Register
PORT_PTEPE          equ       $000030F4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTEPE_PTEPE4   equ       4
; bit position masks
mPORT_PTEPE_PTEPE4  equ       %00010000


;*** SYS_UUID1 Universally Unique Identifier Register 1
SYS_UUID1           equ       $000030F8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID1_ID0       equ       0
SYS_UUID1_ID1       equ       1
SYS_UUID1_ID2       equ       2
SYS_UUID1_ID3       equ       3
SYS_UUID1_ID4       equ       4
SYS_UUID1_ID5       equ       5
SYS_UUID1_ID6       equ       6
SYS_UUID1_ID7       equ       7
; bit position masks
mSYS_UUID1_ID0      equ       %00000001
mSYS_UUID1_ID1      equ       %00000010
mSYS_UUID1_ID2      equ       %00000100
mSYS_UUID1_ID3      equ       %00001000
mSYS_UUID1_ID4      equ       %00010000
mSYS_UUID1_ID5      equ       %00100000
mSYS_UUID1_ID6      equ       %01000000
mSYS_UUID1_ID7      equ       %10000000


;*** SYS_UUID2 Universally Unique Identifier Register 2
SYS_UUID2           equ       $000030F9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID2_ID0       equ       0
SYS_UUID2_ID1       equ       1
SYS_UUID2_ID2       equ       2
SYS_UUID2_ID3       equ       3
SYS_UUID2_ID4       equ       4
SYS_UUID2_ID5       equ       5
SYS_UUID2_ID6       equ       6
SYS_UUID2_ID7       equ       7
; bit position masks
mSYS_UUID2_ID0      equ       %00000001
mSYS_UUID2_ID1      equ       %00000010
mSYS_UUID2_ID2      equ       %00000100
mSYS_UUID2_ID3      equ       %00001000
mSYS_UUID2_ID4      equ       %00010000
mSYS_UUID2_ID5      equ       %00100000
mSYS_UUID2_ID6      equ       %01000000
mSYS_UUID2_ID7      equ       %10000000


;*** SYS_UUID3 Universally Unique Identifier Register 3
SYS_UUID3           equ       $000030FA
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID3_ID0       equ       0
SYS_UUID3_ID1       equ       1
SYS_UUID3_ID2       equ       2
SYS_UUID3_ID3       equ       3
SYS_UUID3_ID4       equ       4
SYS_UUID3_ID5       equ       5
SYS_UUID3_ID6       equ       6
SYS_UUID3_ID7       equ       7
; bit position masks
mSYS_UUID3_ID0      equ       %00000001
mSYS_UUID3_ID1      equ       %00000010
mSYS_UUID3_ID2      equ       %00000100
mSYS_UUID3_ID3      equ       %00001000
mSYS_UUID3_ID4      equ       %00010000
mSYS_UUID3_ID5      equ       %00100000
mSYS_UUID3_ID6      equ       %01000000
mSYS_UUID3_ID7      equ       %10000000


;*** SYS_UUID4 Universally Unique Identifier Register 4
SYS_UUID4           equ       $000030FB
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID4_ID0       equ       0
SYS_UUID4_ID1       equ       1
SYS_UUID4_ID2       equ       2
SYS_UUID4_ID3       equ       3
SYS_UUID4_ID4       equ       4
SYS_UUID4_ID5       equ       5
SYS_UUID4_ID6       equ       6
SYS_UUID4_ID7       equ       7
; bit position masks
mSYS_UUID4_ID0      equ       %00000001
mSYS_UUID4_ID1      equ       %00000010
mSYS_UUID4_ID2      equ       %00000100
mSYS_UUID4_ID3      equ       %00001000
mSYS_UUID4_ID4      equ       %00010000
mSYS_UUID4_ID5      equ       %00100000
mSYS_UUID4_ID6      equ       %01000000
mSYS_UUID4_ID7      equ       %10000000


;*** SYS_UUID5 Universally Unique Identifier Register 5
SYS_UUID5           equ       $000030FC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID5_ID0       equ       0
SYS_UUID5_ID1       equ       1
SYS_UUID5_ID2       equ       2
SYS_UUID5_ID3       equ       3
SYS_UUID5_ID4       equ       4
SYS_UUID5_ID5       equ       5
SYS_UUID5_ID6       equ       6
SYS_UUID5_ID7       equ       7
; bit position masks
mSYS_UUID5_ID0      equ       %00000001
mSYS_UUID5_ID1      equ       %00000010
mSYS_UUID5_ID2      equ       %00000100
mSYS_UUID5_ID3      equ       %00001000
mSYS_UUID5_ID4      equ       %00010000
mSYS_UUID5_ID5      equ       %00100000
mSYS_UUID5_ID6      equ       %01000000
mSYS_UUID5_ID7      equ       %10000000


;*** SYS_UUID6 Universally Unique Identifier Register 6
SYS_UUID6           equ       $000030FD
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID6_ID0       equ       0
SYS_UUID6_ID1       equ       1
SYS_UUID6_ID2       equ       2
SYS_UUID6_ID3       equ       3
SYS_UUID6_ID4       equ       4
SYS_UUID6_ID5       equ       5
SYS_UUID6_ID6       equ       6
SYS_UUID6_ID7       equ       7
; bit position masks
mSYS_UUID6_ID0      equ       %00000001
mSYS_UUID6_ID1      equ       %00000010
mSYS_UUID6_ID2      equ       %00000100
mSYS_UUID6_ID3      equ       %00001000
mSYS_UUID6_ID4      equ       %00010000
mSYS_UUID6_ID5      equ       %00100000
mSYS_UUID6_ID6      equ       %01000000
mSYS_UUID6_ID7      equ       %10000000


;*** SYS_UUID7 Universally Unique Identifier Register 7
SYS_UUID7           equ       $000030FE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID7_ID0       equ       0
SYS_UUID7_ID1       equ       1
SYS_UUID7_ID2       equ       2
SYS_UUID7_ID3       equ       3
SYS_UUID7_ID4       equ       4
SYS_UUID7_ID5       equ       5
SYS_UUID7_ID6       equ       6
SYS_UUID7_ID7       equ       7
; bit position masks
mSYS_UUID7_ID0      equ       %00000001
mSYS_UUID7_ID1      equ       %00000010
mSYS_UUID7_ID2      equ       %00000100
mSYS_UUID7_ID3      equ       %00001000
mSYS_UUID7_ID4      equ       %00010000
mSYS_UUID7_ID5      equ       %00100000
mSYS_UUID7_ID6      equ       %01000000
mSYS_UUID7_ID7      equ       %10000000


;*** SYS_UUID8 Universally Unique Identifier Register 8
SYS_UUID8           equ       $000030FF
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SYS_UUID8_ID0       equ       0
SYS_UUID8_ID1       equ       1
SYS_UUID8_ID2       equ       2
SYS_UUID8_ID3       equ       3
SYS_UUID8_ID4       equ       4
SYS_UUID8_ID5       equ       5
SYS_UUID8_ID6       equ       6
SYS_UUID8_ID7       equ       7
; bit position masks
mSYS_UUID8_ID0      equ       %00000001
mSYS_UUID8_ID1      equ       %00000010
mSYS_UUID8_ID2      equ       %00000100
mSYS_UUID8_ID3      equ       %00001000
mSYS_UUID8_ID4      equ       %00010000
mSYS_UUID8_ID5      equ       %00100000
mSYS_UUID8_ID6      equ       %01000000
mSYS_UUID8_ID7      equ       %10000000


;*** NV_BACKKEY0 Back Door Key Register n
NV_BACKKEY0         equ       $0000FF70
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY0_BACKKEY0 equ       0
NV_BACKKEY0_BACKKEY1 equ       1
NV_BACKKEY0_BACKKEY2 equ       2
NV_BACKKEY0_BACKKEY3 equ       3
NV_BACKKEY0_BACKKEY4 equ       4
NV_BACKKEY0_BACKKEY5 equ       5
NV_BACKKEY0_BACKKEY6 equ       6
NV_BACKKEY0_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY0_BACKKEY0 equ       %00000001
mNV_BACKKEY0_BACKKEY1 equ       %00000010
mNV_BACKKEY0_BACKKEY2 equ       %00000100
mNV_BACKKEY0_BACKKEY3 equ       %00001000
mNV_BACKKEY0_BACKKEY4 equ       %00010000
mNV_BACKKEY0_BACKKEY5 equ       %00100000
mNV_BACKKEY0_BACKKEY6 equ       %01000000
mNV_BACKKEY0_BACKKEY7 equ       %10000000


;*** NV_BACKKEY1 Back Door Key Register n
NV_BACKKEY1         equ       $0000FF71
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY1_BACKKEY0 equ       0
NV_BACKKEY1_BACKKEY1 equ       1
NV_BACKKEY1_BACKKEY2 equ       2
NV_BACKKEY1_BACKKEY3 equ       3
NV_BACKKEY1_BACKKEY4 equ       4
NV_BACKKEY1_BACKKEY5 equ       5
NV_BACKKEY1_BACKKEY6 equ       6
NV_BACKKEY1_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY1_BACKKEY0 equ       %00000001
mNV_BACKKEY1_BACKKEY1 equ       %00000010
mNV_BACKKEY1_BACKKEY2 equ       %00000100
mNV_BACKKEY1_BACKKEY3 equ       %00001000
mNV_BACKKEY1_BACKKEY4 equ       %00010000
mNV_BACKKEY1_BACKKEY5 equ       %00100000
mNV_BACKKEY1_BACKKEY6 equ       %01000000
mNV_BACKKEY1_BACKKEY7 equ       %10000000


;*** NV_BACKKEY2 Back Door Key Register n
NV_BACKKEY2         equ       $0000FF72
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY2_BACKKEY0 equ       0
NV_BACKKEY2_BACKKEY1 equ       1
NV_BACKKEY2_BACKKEY2 equ       2
NV_BACKKEY2_BACKKEY3 equ       3
NV_BACKKEY2_BACKKEY4 equ       4
NV_BACKKEY2_BACKKEY5 equ       5
NV_BACKKEY2_BACKKEY6 equ       6
NV_BACKKEY2_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY2_BACKKEY0 equ       %00000001
mNV_BACKKEY2_BACKKEY1 equ       %00000010
mNV_BACKKEY2_BACKKEY2 equ       %00000100
mNV_BACKKEY2_BACKKEY3 equ       %00001000
mNV_BACKKEY2_BACKKEY4 equ       %00010000
mNV_BACKKEY2_BACKKEY5 equ       %00100000
mNV_BACKKEY2_BACKKEY6 equ       %01000000
mNV_BACKKEY2_BACKKEY7 equ       %10000000


;*** NV_BACKKEY3 Back Door Key Register n
NV_BACKKEY3         equ       $0000FF73
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY3_BACKKEY0 equ       0
NV_BACKKEY3_BACKKEY1 equ       1
NV_BACKKEY3_BACKKEY2 equ       2
NV_BACKKEY3_BACKKEY3 equ       3
NV_BACKKEY3_BACKKEY4 equ       4
NV_BACKKEY3_BACKKEY5 equ       5
NV_BACKKEY3_BACKKEY6 equ       6
NV_BACKKEY3_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY3_BACKKEY0 equ       %00000001
mNV_BACKKEY3_BACKKEY1 equ       %00000010
mNV_BACKKEY3_BACKKEY2 equ       %00000100
mNV_BACKKEY3_BACKKEY3 equ       %00001000
mNV_BACKKEY3_BACKKEY4 equ       %00010000
mNV_BACKKEY3_BACKKEY5 equ       %00100000
mNV_BACKKEY3_BACKKEY6 equ       %01000000
mNV_BACKKEY3_BACKKEY7 equ       %10000000


;*** NV_BACKKEY4 Back Door Key Register n
NV_BACKKEY4         equ       $0000FF74
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY4_BACKKEY0 equ       0
NV_BACKKEY4_BACKKEY1 equ       1
NV_BACKKEY4_BACKKEY2 equ       2
NV_BACKKEY4_BACKKEY3 equ       3
NV_BACKKEY4_BACKKEY4 equ       4
NV_BACKKEY4_BACKKEY5 equ       5
NV_BACKKEY4_BACKKEY6 equ       6
NV_BACKKEY4_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY4_BACKKEY0 equ       %00000001
mNV_BACKKEY4_BACKKEY1 equ       %00000010
mNV_BACKKEY4_BACKKEY2 equ       %00000100
mNV_BACKKEY4_BACKKEY3 equ       %00001000
mNV_BACKKEY4_BACKKEY4 equ       %00010000
mNV_BACKKEY4_BACKKEY5 equ       %00100000
mNV_BACKKEY4_BACKKEY6 equ       %01000000
mNV_BACKKEY4_BACKKEY7 equ       %10000000


;*** NV_BACKKEY5 Back Door Key Register n
NV_BACKKEY5         equ       $0000FF75
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY5_BACKKEY0 equ       0
NV_BACKKEY5_BACKKEY1 equ       1
NV_BACKKEY5_BACKKEY2 equ       2
NV_BACKKEY5_BACKKEY3 equ       3
NV_BACKKEY5_BACKKEY4 equ       4
NV_BACKKEY5_BACKKEY5 equ       5
NV_BACKKEY5_BACKKEY6 equ       6
NV_BACKKEY5_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY5_BACKKEY0 equ       %00000001
mNV_BACKKEY5_BACKKEY1 equ       %00000010
mNV_BACKKEY5_BACKKEY2 equ       %00000100
mNV_BACKKEY5_BACKKEY3 equ       %00001000
mNV_BACKKEY5_BACKKEY4 equ       %00010000
mNV_BACKKEY5_BACKKEY5 equ       %00100000
mNV_BACKKEY5_BACKKEY6 equ       %01000000
mNV_BACKKEY5_BACKKEY7 equ       %10000000


;*** NV_BACKKEY6 Back Door Key Register n
NV_BACKKEY6         equ       $0000FF76
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY6_BACKKEY0 equ       0
NV_BACKKEY6_BACKKEY1 equ       1
NV_BACKKEY6_BACKKEY2 equ       2
NV_BACKKEY6_BACKKEY3 equ       3
NV_BACKKEY6_BACKKEY4 equ       4
NV_BACKKEY6_BACKKEY5 equ       5
NV_BACKKEY6_BACKKEY6 equ       6
NV_BACKKEY6_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY6_BACKKEY0 equ       %00000001
mNV_BACKKEY6_BACKKEY1 equ       %00000010
mNV_BACKKEY6_BACKKEY2 equ       %00000100
mNV_BACKKEY6_BACKKEY3 equ       %00001000
mNV_BACKKEY6_BACKKEY4 equ       %00010000
mNV_BACKKEY6_BACKKEY5 equ       %00100000
mNV_BACKKEY6_BACKKEY6 equ       %01000000
mNV_BACKKEY6_BACKKEY7 equ       %10000000


;*** NV_BACKKEY7 Back Door Key Register n
NV_BACKKEY7         equ       $0000FF77
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_BACKKEY7_BACKKEY0 equ       0
NV_BACKKEY7_BACKKEY1 equ       1
NV_BACKKEY7_BACKKEY2 equ       2
NV_BACKKEY7_BACKKEY3 equ       3
NV_BACKKEY7_BACKKEY4 equ       4
NV_BACKKEY7_BACKKEY5 equ       5
NV_BACKKEY7_BACKKEY6 equ       6
NV_BACKKEY7_BACKKEY7 equ       7
; bit position masks
mNV_BACKKEY7_BACKKEY0 equ       %00000001
mNV_BACKKEY7_BACKKEY1 equ       %00000010
mNV_BACKKEY7_BACKKEY2 equ       %00000100
mNV_BACKKEY7_BACKKEY3 equ       %00001000
mNV_BACKKEY7_BACKKEY4 equ       %00010000
mNV_BACKKEY7_BACKKEY5 equ       %00100000
mNV_BACKKEY7_BACKKEY6 equ       %01000000
mNV_BACKKEY7_BACKKEY7 equ       %10000000


;*** NV_FPROT Flash Protection Register
NV_FPROT            equ       $0000FF7C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FPROT_FPHS0      equ       3
NV_FPROT_FPHS1      equ       4
NV_FPROT_FPHDIS     equ       5
NV_FPROT_FPOPEN     equ       7
; bit position masks
mNV_FPROT_FPHS0     equ       %00001000
mNV_FPROT_FPHS1     equ       %00010000
mNV_FPROT_FPHDIS    equ       %00100000
mNV_FPROT_FPOPEN    equ       %10000000


;*** NV_EEPROT EEPROM Protection Register
NV_EEPROT           equ       $0000FF7D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_EEPROT_DPS0      equ       0
NV_EEPROT_DPS1      equ       1
NV_EEPROT_DPS2      equ       2
NV_EEPROT_DPOPEN    equ       7
; bit position masks
mNV_EEPROT_DPS0     equ       %00000001
mNV_EEPROT_DPS1     equ       %00000010
mNV_EEPROT_DPS2     equ       %00000100
mNV_EEPROT_DPOPEN   equ       %10000000


;*** NV_FOPT Flash Option Register
NV_FOPT             equ       $0000FF7E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FOPT_NV0         equ       0
NV_FOPT_NV1         equ       1
NV_FOPT_NV2         equ       2
NV_FOPT_NV3         equ       3
NV_FOPT_NV4         equ       4
NV_FOPT_NV5         equ       5
NV_FOPT_NV6         equ       6
NV_FOPT_NV7         equ       7
; bit position masks
mNV_FOPT_NV0        equ       %00000001
mNV_FOPT_NV1        equ       %00000010
mNV_FOPT_NV2        equ       %00000100
mNV_FOPT_NV3        equ       %00001000
mNV_FOPT_NV4        equ       %00010000
mNV_FOPT_NV5        equ       %00100000
mNV_FOPT_NV6        equ       %01000000
mNV_FOPT_NV7        equ       %10000000


;*** NV_FSEC Flash Security Register
NV_FSEC             equ       $0000FF7F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FSEC_SEC0        equ       0
NV_FSEC_SEC1        equ       1
NV_FSEC_KEYEN0      equ       6
NV_FSEC_KEYEN1      equ       7
; bit position masks
mNV_FSEC_SEC0       equ       %00000001
mNV_FSEC_SEC1       equ       %00000010
mNV_FSEC_KEYEN0     equ       %01000000
mNV_FSEC_KEYEN1     equ       %10000000
