;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; ###################################################################
;     Filename  : mc9s08su16.inc
;     Processor : MC9S08SU16
;     DataSheet : MC9S08SU16RM Rev. 5 4/2017
;     Compiler  : CodeWarrior compiler
;     Date/Time : 28.04.2017, 19:33
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2017 NXP Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.nxp.com
;     mail      : support@nxp.com
; ###################################################################

;**************** interrupt vector table ****************
Vreset              equ       $0000FFFE
Vswi                equ       $0000FFFC
Virq                equ       $0000FFFA
Vlvw                equ       $0000FFF8
Vovw                equ       $0000FFF6
Vmcpwmf             equ       $0000FFF4
Vmcpwm              equ       $0000FFF2
Vpwt0rdy            equ       $0000FFF0
Vpwt0ovf            equ       $0000FFEE
Vpwt1rdy            equ       $0000FFEC
Vpwt1ovf            equ       $0000FFEA
Vadc0               equ       $0000FFE8
Vadc1               equ       $0000FFE6
Vgduamp             equ       $0000FFE4
reserve1            equ       $0000FFE2
reserve2            equ       $0000FFE0
Vtpmch0             equ       $0000FFDE
Vtpmch1             equ       $0000FFDC
Vtpmovf             equ       $0000FFDA
Vcmp                equ       $0000FFD8
Vgducmp0            equ       $0000FFD6
Vgducmp1            equ       $0000FFD4
Vgducmp2            equ       $0000FFD2
Vscierr             equ       $0000FFD0
Vscirx              equ       $0000FFCE
Vscitx              equ       $0000FFCC
Vpdb                equ       $0000FFCA
Vics                equ       $0000FFC8
Vmtim               equ       $0000FFC6
Vkbi                equ       $0000FFC4
Viic                equ       $0000FFC2
Vnvm                equ       $0000FFC0

;*************Memory Map************************
Dreg_e              equ       $0000007F
Hreg_b              equ       $00001800
XRAM                equ       $00000080
ROM                 equ       $0000E000
Dreg_b              equ       $00000000
XRAM_END            equ       $0000017F
ROM_END             equ       $0000FFFF
Hreg_e              equ       $000018FF

;*** ADC0_SC1 Status and Control Register 1
ADC0_SC1            equ       $00000010
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0_SC1_ADCH0      equ       0
ADC0_SC1_ADCH1      equ       1
ADC0_SC1_ADCH2      equ       2
ADC0_SC1_ADCH3      equ       3
ADC0_SC1_ADCH4      equ       4
ADC0_SC1_ADCO       equ       5
ADC0_SC1_AIEN       equ       6
ADC0_SC1_COCO       equ       7
; bit position masks
mADC0_SC1_ADCH0     equ       %00000001
mADC0_SC1_ADCH1     equ       %00000010
mADC0_SC1_ADCH2     equ       %00000100
mADC0_SC1_ADCH3     equ       %00001000
mADC0_SC1_ADCH4     equ       %00010000
mADC0_SC1_ADCO      equ       %00100000
mADC0_SC1_AIEN      equ       %01000000
mADC0_SC1_COCO      equ       %10000000

;*** ADC0_SC2 Status and Control Register 2
ADC0_SC2            equ       $00000011
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0_SC2_REFSEL0    equ       0
ADC0_SC2_REFSEL1    equ       1
ADC0_SC2_FFULL      equ       2
ADC0_SC2_FEMPTY     equ       3
ADC0_SC2_ACFGT      equ       4
ADC0_SC2_ACFE       equ       5
ADC0_SC2_ADTRG      equ       6
ADC0_SC2_ADACT      equ       7
; bit position masks
mADC0_SC2_REFSEL0   equ       %00000001
mADC0_SC2_REFSEL1   equ       %00000010
mADC0_SC2_FFULL     equ       %00000100
mADC0_SC2_FEMPTY    equ       %00001000
mADC0_SC2_ACFGT     equ       %00010000
mADC0_SC2_ACFE      equ       %00100000
mADC0_SC2_ADTRG     equ       %01000000
mADC0_SC2_ADACT     equ       %10000000

;*** ADC0_SC3 Status and Control Register 3
ADC0_SC3            equ       $00000012
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0_SC3_ADICLK0    equ       0
ADC0_SC3_ADICLK1    equ       1
ADC0_SC3_MODE0      equ       2
ADC0_SC3_MODE1      equ       3
ADC0_SC3_ADLSMP     equ       4
ADC0_SC3_ADIV0      equ       5
ADC0_SC3_ADIV1      equ       6
ADC0_SC3_ADLPC      equ       7
; bit position masks
mADC0_SC3_ADICLK0   equ       %00000001
mADC0_SC3_ADICLK1   equ       %00000010
mADC0_SC3_MODE0     equ       %00000100
mADC0_SC3_MODE1     equ       %00001000
mADC0_SC3_ADLSMP    equ       %00010000
mADC0_SC3_ADIV0     equ       %00100000
mADC0_SC3_ADIV1     equ       %01000000
mADC0_SC3_ADLPC     equ       %10000000

;*** ADC0_SC4 Status and Control Register 4
ADC0_SC4            equ       $00000013
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0_SC4_AFDEP0     equ       0
ADC0_SC4_AFDEP1     equ       1
ADC0_SC4_AFDEP2     equ       2
ADC0_SC4_HTRGMASKSEL equ       3
ADC0_SC4_HTRGMASKE  equ       4
ADC0_SC4_ACFSEL     equ       5
ADC0_SC4_ASCANE     equ       6
ADC0_SC4_HTRGME     equ       7
; bit position masks
mADC0_SC4_AFDEP0    equ       %00000001
mADC0_SC4_AFDEP1    equ       %00000010
mADC0_SC4_AFDEP2    equ       %00000100
mADC0_SC4_HTRGMASKSEL equ       %00001000
mADC0_SC4_HTRGMASKE equ       %00010000
mADC0_SC4_ACFSEL    equ       %00100000
mADC0_SC4_ASCANE    equ       %01000000
mADC0_SC4_HTRGME    equ       %10000000

;*** ADC0_RH Conversion Result High Register
ADC0_RH             equ       $00000014
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0_RH_ADR0        equ       0
ADC0_RH_ADR1        equ       1
ADC0_RH_ADR2        equ       2
ADC0_RH_ADR3        equ       3
; bit position masks
mADC0_RH_ADR0       equ       %00000001
mADC0_RH_ADR1       equ       %00000010
mADC0_RH_ADR2       equ       %00000100
mADC0_RH_ADR3       equ       %00001000

;*** ADC0_RL Conversion Result Low Register
ADC0_RL             equ       $00000015

;*** ADC0_CVH Compare Value High Register
ADC0_CVH            equ       $00000016
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0_CVH_CV0        equ       0
ADC0_CVH_CV1        equ       1
ADC0_CVH_CV2        equ       2
ADC0_CVH_CV3        equ       3
; bit position masks
mADC0_CVH_CV0       equ       %00000001
mADC0_CVH_CV1       equ       %00000010
mADC0_CVH_CV2       equ       %00000100
mADC0_CVH_CV3       equ       %00001000

;*** ADC0_CVL Compare Value Low Register
ADC0_CVL            equ       $00000017

;*** ADC1_SC1 Status and Control Register 1
ADC1_SC1            equ       $00000018
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1_SC1_ADCH0      equ       0
ADC1_SC1_ADCH1      equ       1
ADC1_SC1_ADCH2      equ       2
ADC1_SC1_ADCH3      equ       3
ADC1_SC1_ADCH4      equ       4
ADC1_SC1_ADCO       equ       5
ADC1_SC1_AIEN       equ       6
ADC1_SC1_COCO       equ       7
; bit position masks
mADC1_SC1_ADCH0     equ       %00000001
mADC1_SC1_ADCH1     equ       %00000010
mADC1_SC1_ADCH2     equ       %00000100
mADC1_SC1_ADCH3     equ       %00001000
mADC1_SC1_ADCH4     equ       %00010000
mADC1_SC1_ADCO      equ       %00100000
mADC1_SC1_AIEN      equ       %01000000
mADC1_SC1_COCO      equ       %10000000

;*** ADC1_SC2 Status and Control Register 2
ADC1_SC2            equ       $00000019
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1_SC2_REFSEL0    equ       0
ADC1_SC2_REFSEL1    equ       1
ADC1_SC2_FFULL      equ       2
ADC1_SC2_FEMPTY     equ       3
ADC1_SC2_ACFGT      equ       4
ADC1_SC2_ACFE       equ       5
ADC1_SC2_ADTRG      equ       6
ADC1_SC2_ADACT      equ       7
; bit position masks
mADC1_SC2_REFSEL0   equ       %00000001
mADC1_SC2_REFSEL1   equ       %00000010
mADC1_SC2_FFULL     equ       %00000100
mADC1_SC2_FEMPTY    equ       %00001000
mADC1_SC2_ACFGT     equ       %00010000
mADC1_SC2_ACFE      equ       %00100000
mADC1_SC2_ADTRG     equ       %01000000
mADC1_SC2_ADACT     equ       %10000000

;*** ADC1_SC3 Status and Control Register 3
ADC1_SC3            equ       $0000001A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1_SC3_ADICLK0    equ       0
ADC1_SC3_ADICLK1    equ       1
ADC1_SC3_MODE0      equ       2
ADC1_SC3_MODE1      equ       3
ADC1_SC3_ADLSMP     equ       4
ADC1_SC3_ADIV0      equ       5
ADC1_SC3_ADIV1      equ       6
ADC1_SC3_ADLPC      equ       7
; bit position masks
mADC1_SC3_ADICLK0   equ       %00000001
mADC1_SC3_ADICLK1   equ       %00000010
mADC1_SC3_MODE0     equ       %00000100
mADC1_SC3_MODE1     equ       %00001000
mADC1_SC3_ADLSMP    equ       %00010000
mADC1_SC3_ADIV0     equ       %00100000
mADC1_SC3_ADIV1     equ       %01000000
mADC1_SC3_ADLPC     equ       %10000000

;*** ADC1_SC4 Status and Control Register 4
ADC1_SC4            equ       $0000001B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1_SC4_AFDEP0     equ       0
ADC1_SC4_AFDEP1     equ       1
ADC1_SC4_AFDEP2     equ       2
ADC1_SC4_HTRGMASKSEL equ       3
ADC1_SC4_HTRGMASKE  equ       4
ADC1_SC4_ACFSEL     equ       5
ADC1_SC4_ASCANE     equ       6
ADC1_SC4_HTRGME     equ       7
; bit position masks
mADC1_SC4_AFDEP0    equ       %00000001
mADC1_SC4_AFDEP1    equ       %00000010
mADC1_SC4_AFDEP2    equ       %00000100
mADC1_SC4_HTRGMASKSEL equ       %00001000
mADC1_SC4_HTRGMASKE equ       %00010000
mADC1_SC4_ACFSEL    equ       %00100000
mADC1_SC4_ASCANE    equ       %01000000
mADC1_SC4_HTRGME    equ       %10000000

;*** ADC1_RH Conversion Result High Register
ADC1_RH             equ       $0000001C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1_RH_ADR0        equ       0
ADC1_RH_ADR1        equ       1
ADC1_RH_ADR2        equ       2
ADC1_RH_ADR3        equ       3
; bit position masks
mADC1_RH_ADR0       equ       %00000001
mADC1_RH_ADR1       equ       %00000010
mADC1_RH_ADR2       equ       %00000100
mADC1_RH_ADR3       equ       %00001000

;*** ADC1_RL Conversion Result Low Register
ADC1_RL             equ       $0000001D

;*** ADC1_CVH Compare Value High Register
ADC1_CVH            equ       $0000001E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1_CVH_CV0        equ       0
ADC1_CVH_CV1        equ       1
ADC1_CVH_CV2        equ       2
ADC1_CVH_CV3        equ       3
; bit position masks
mADC1_CVH_CV0       equ       %00000001
mADC1_CVH_CV1       equ       %00000010
mADC1_CVH_CV2       equ       %00000100
mADC1_CVH_CV3       equ       %00001000

;*** ADC1_CVL Compare Value Low Register
ADC1_CVL            equ       $0000001F

;*** CMP_CR0 CMP Control Register 0
CMP_CR0             equ       $00000068
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMP_CR0_HYSTCTR     equ       0
CMP_CR0_FILTER_CNT0 equ       4
CMP_CR0_FILTER_CNT1 equ       5
CMP_CR0_FILTER_CNT2 equ       6
; bit position masks
mCMP_CR0_HYSTCTR    equ       %00000001
mCMP_CR0_FILTER_CNT0 equ       %00010000
mCMP_CR0_FILTER_CNT1 equ       %00100000
mCMP_CR0_FILTER_CNT2 equ       %01000000

;*** CMP_CR1 CMP Control Register 1
CMP_CR1             equ       $00000069
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMP_CR1_EN          equ       0
CMP_CR1_OPE         equ       1
CMP_CR1_COS         equ       2
CMP_CR1_INV         equ       3
CMP_CR1_PMODE       equ       4
CMP_CR1_WE          equ       6
CMP_CR1_SE          equ       7
; bit position masks
mCMP_CR1_EN         equ       %00000001
mCMP_CR1_OPE        equ       %00000010
mCMP_CR1_COS        equ       %00000100
mCMP_CR1_INV        equ       %00001000
mCMP_CR1_PMODE      equ       %00010000
mCMP_CR1_WE         equ       %01000000
mCMP_CR1_SE         equ       %10000000

;*** CMP_FPR CMP Filter Period Register
CMP_FPR             equ       $0000006A

;*** CMP_SCR CMP Status and Control Register
CMP_SCR             equ       $0000006B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMP_SCR_COUT        equ       0
CMP_SCR_CFF         equ       1
CMP_SCR_CFR         equ       2
CMP_SCR_IEF         equ       3
CMP_SCR_IER         equ       4
; bit position masks
mCMP_SCR_COUT       equ       %00000001
mCMP_SCR_CFF        equ       %00000010
mCMP_SCR_CFR        equ       %00000100
mCMP_SCR_IEF        equ       %00001000
mCMP_SCR_IER        equ       %00010000

;*** CMP_DACCR DAC Control Register
CMP_DACCR           equ       $0000006C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMP_DACCR_VOSEL0    equ       0
CMP_DACCR_VOSEL1    equ       1
CMP_DACCR_VOSEL2    equ       2
CMP_DACCR_VOSEL3    equ       3
CMP_DACCR_VOSEL4    equ       4
CMP_DACCR_VOSEL5    equ       5
CMP_DACCR_VRSEL     equ       6
CMP_DACCR_DACEN     equ       7
; bit position masks
mCMP_DACCR_VOSEL0   equ       %00000001
mCMP_DACCR_VOSEL1   equ       %00000010
mCMP_DACCR_VOSEL2   equ       %00000100
mCMP_DACCR_VOSEL3   equ       %00001000
mCMP_DACCR_VOSEL4   equ       %00010000
mCMP_DACCR_VOSEL5   equ       %00100000
mCMP_DACCR_VRSEL    equ       %01000000
mCMP_DACCR_DACEN    equ       %10000000

;*** CMP_MUXCR MUX Control Register
CMP_MUXCR           equ       $0000006D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMP_MUXCR_MSEL0     equ       0
CMP_MUXCR_MSEL1     equ       1
CMP_MUXCR_PSEL0     equ       4
CMP_MUXCR_PSEL1     equ       5
; bit position masks
mCMP_MUXCR_MSEL0    equ       %00000001
mCMP_MUXCR_MSEL1    equ       %00000010
mCMP_MUXCR_PSEL0    equ       %00010000
mCMP_MUXCR_PSEL1    equ       %00100000

;*** CMP_MUXPE MUX Pin Enable Register
CMP_MUXPE           equ       $0000006E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMP_MUXPE_INPE0     equ       0
CMP_MUXPE_INPE1     equ       1
CMP_MUXPE_INPE2     equ       2
; bit position masks
mCMP_MUXPE_INPE0    equ       %00000001
mCMP_MUXPE_INPE1    equ       %00000010
mCMP_MUXPE_INPE2    equ       %00000100

;*** CRC_DH1 CRC Data register: High 1
CRC_DH1             equ       $00001890

;*** CRC_DH0 CRC Data register: High 0
CRC_DH0             equ       $00001891

;*** CRC_DL1 CRC Data register: Low 1
CRC_DL1             equ       $00001892

;*** CRC_DL0 CRC Data register: Low 0
CRC_DL0             equ       $00001893

;*** CRC_PH1 CRC Polynomial Register: High 1
CRC_PH1             equ       $00001894

;*** CRC_PH0 CRC Polynomial Register: High 0
CRC_PH0             equ       $00001895

;*** CRC_PL1 CRC Polynomial Register: Low 1
CRC_PL1             equ       $00001896

;*** CRC_PL0 CRC Polynomial Register: Low 0
CRC_PL0             equ       $00001897

;*** CRC_CTRL CRC Control register
CRC_CTRL            equ       $00001898
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

;*** DBG_CAH Debug Comparator A High Register
DBG_CAH             equ       $000018C0

;*** DBG_CAL Debug Comparator A Low Register
DBG_CAL             equ       $000018C1

;*** DBG_CBH Debug Comparator B High Register
DBG_CBH             equ       $000018C2

;*** DBG_CBL Debug Comparator B Low Register
DBG_CBL             equ       $000018C3

;*** DBG_CCH Debug Comparator C High Register
DBG_CCH             equ       $000018C4

;*** DBG_CCL Debug Comparator C Low Register
DBG_CCL             equ       $000018C5

;*** DBG_FH Debug FIFO High Register
DBG_FH              equ       $000018C6

;*** DBG_FL Debug FIFO Low Register
DBG_FL              equ       $000018C7

;*** DBG_CAX Debug Comparator A Extension Register
DBG_CAX             equ       $000018C8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CAX_RWA         equ       6
DBG_CAX_RWAEN       equ       7
; bit position masks
mDBG_CAX_RWA        equ       %01000000
mDBG_CAX_RWAEN      equ       %10000000

;*** DBG_CBX Debug Comparator B Extension Register
DBG_CBX             equ       $000018C9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CBX_RWB         equ       6
DBG_CBX_RWBEN       equ       7
; bit position masks
mDBG_CBX_RWB        equ       %01000000
mDBG_CBX_RWBEN      equ       %10000000

;*** DBG_CCX Debug Comparator C Extension Register
DBG_CCX             equ       $000018CA
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_CCX_RWC         equ       6
DBG_CCX_RWCEN       equ       7
; bit position masks
mDBG_CCX_RWC        equ       %01000000
mDBG_CCX_RWCEN      equ       %10000000

;*** DBG_FX Debug FIFO Extended Information Register
DBG_FX              equ       $000018CB
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBG_FX_Bit16        equ       0
DBG_FX_PPACC        equ       7
; bit position masks
mDBG_FX_Bit16       equ       %00000001
mDBG_FX_PPACC       equ       %10000000

;*** DBG_C Debug Control Register
DBG_C               equ       $000018CC
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
DBG_T               equ       $000018CD
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
DBG_S               equ       $000018CE
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
DBG_CNT             equ       $000018CF
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

;*** FTM0_SC Status and Control
FTM0_SC             equ       $00000070
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

;*** FTM0_CNTH Counter High
FTM0_CNTH           equ       $00000071

;*** FTM0_CNTL Counter Low
FTM0_CNTL           equ       $00000072

;*** FTM0_MODH Modulo High
FTM0_MODH           equ       $00000073

;*** FTM0_MODL Modulo Low
FTM0_MODL           equ       $00000074

;*** FTM0_C0SC Channel Status and Control
FTM0_C0SC           equ       $00000075
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

;*** FTM0_C0VH Channel Value High
FTM0_C0VH           equ       $00000076

;*** FTM0_C0VL Channel Value Low
FTM0_C0VL           equ       $00000077

;*** FTM0_C1SC Channel Status and Control
FTM0_C1SC           equ       $00000078
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

;*** FTM0_C1VH Channel Value High
FTM0_C1VH           equ       $00000079

;*** FTM0_C1VL Channel Value Low
FTM0_C1VL           equ       $0000007A

;*** FTMRH_FCLKDIV Flash Clock Divider Register
FTMRH_FCLKDIV       equ       $00001830
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMRH_FCLKDIV_FDIV0 equ       0
FTMRH_FCLKDIV_FDIV1 equ       1
FTMRH_FCLKDIV_FDIV2 equ       2
FTMRH_FCLKDIV_FDIV3 equ       3
FTMRH_FCLKDIV_FDIV4 equ       4
FTMRH_FCLKDIV_FDIV5 equ       5
FTMRH_FCLKDIV_FDIVLCK equ       6
FTMRH_FCLKDIV_FDIVLD equ       7
; bit position masks
mFTMRH_FCLKDIV_FDIV0 equ       %00000001
mFTMRH_FCLKDIV_FDIV1 equ       %00000010
mFTMRH_FCLKDIV_FDIV2 equ       %00000100
mFTMRH_FCLKDIV_FDIV3 equ       %00001000
mFTMRH_FCLKDIV_FDIV4 equ       %00010000
mFTMRH_FCLKDIV_FDIV5 equ       %00100000
mFTMRH_FCLKDIV_FDIVLCK equ       %01000000
mFTMRH_FCLKDIV_FDIVLD equ       %10000000

;*** FTMRH_FSEC Flash Security Register
FTMRH_FSEC          equ       $00001831
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMRH_FSEC_SEC0     equ       0
FTMRH_FSEC_SEC1     equ       1
FTMRH_FSEC_KEYEN0   equ       6
FTMRH_FSEC_KEYEN1   equ       7
; bit position masks
mFTMRH_FSEC_SEC0    equ       %00000001
mFTMRH_FSEC_SEC1    equ       %00000010
mFTMRH_FSEC_KEYEN0  equ       %01000000
mFTMRH_FSEC_KEYEN1  equ       %10000000

;*** FTMRH_FCCOBIX Flash CCOB Index Register
FTMRH_FCCOBIX       equ       $00001832
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMRH_FCCOBIX_CCOBIX0 equ       0
FTMRH_FCCOBIX_CCOBIX1 equ       1
FTMRH_FCCOBIX_CCOBIX2 equ       2
; bit position masks
mFTMRH_FCCOBIX_CCOBIX0 equ       %00000001
mFTMRH_FCCOBIX_CCOBIX1 equ       %00000010
mFTMRH_FCCOBIX_CCOBIX2 equ       %00000100

;*** FTMRH_FCNFG Flash Configuration Register
FTMRH_FCNFG         equ       $00001834
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMRH_FCNFG_CCIE    equ       7
; bit position masks
mFTMRH_FCNFG_CCIE   equ       %10000000

;*** FTMRH_FSTAT Flash Status Register
FTMRH_FSTAT         equ       $00001836
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMRH_FSTAT_MGSTAT0 equ       0
FTMRH_FSTAT_MGSTAT1 equ       1
FTMRH_FSTAT_MGBUSY  equ       3
FTMRH_FSTAT_FPVIOL  equ       4
FTMRH_FSTAT_ACCERR  equ       5
FTMRH_FSTAT_CCIF    equ       7
; bit position masks
mFTMRH_FSTAT_MGSTAT0 equ       %00000001
mFTMRH_FSTAT_MGSTAT1 equ       %00000010
mFTMRH_FSTAT_MGBUSY equ       %00001000
mFTMRH_FSTAT_FPVIOL equ       %00010000
mFTMRH_FSTAT_ACCERR equ       %00100000
mFTMRH_FSTAT_CCIF   equ       %10000000

;*** FTMRH_FPROT Flash Protection Register
FTMRH_FPROT         equ       $00001838
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMRH_FPROT_RNV0    equ       0
FTMRH_FPROT_RNV1    equ       1
FTMRH_FPROT_RNV2    equ       2
FTMRH_FPROT_FPHS0   equ       3
FTMRH_FPROT_FPHS1   equ       4
FTMRH_FPROT_FPHDIS  equ       5
FTMRH_FPROT_RNV6    equ       6
FTMRH_FPROT_FPOPEN  equ       7
; bit position masks
mFTMRH_FPROT_RNV0   equ       %00000001
mFTMRH_FPROT_RNV1   equ       %00000010
mFTMRH_FPROT_RNV2   equ       %00000100
mFTMRH_FPROT_FPHS0  equ       %00001000
mFTMRH_FPROT_FPHS1  equ       %00010000
mFTMRH_FPROT_FPHDIS equ       %00100000
mFTMRH_FPROT_RNV6   equ       %01000000
mFTMRH_FPROT_FPOPEN equ       %10000000

;*** FTMRH_FCCOBHI Flash Common Command Object Register:High
FTMRH_FCCOBHI       equ       $0000183A

;*** FTMRH_FCCOBLO Flash Common Command Object Register: Low
FTMRH_FCCOBLO       equ       $0000183B

;*** FTMRH_FOPT Flash Option Register
FTMRH_FOPT          equ       $0000183C

;*** GDU_PHCMP0CR0 PHCMP0 Control Register 0
GDU_PHCMP0CR0       equ       $00000020
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP0CR0_HYSTCTR equ       0
GDU_PHCMP0CR0_FILTER_CNT0 equ       4
GDU_PHCMP0CR0_FILTER_CNT1 equ       5
GDU_PHCMP0CR0_FILTER_CNT2 equ       6
; bit position masks
mGDU_PHCMP0CR0_HYSTCTR equ       %00000001
mGDU_PHCMP0CR0_FILTER_CNT0 equ       %00010000
mGDU_PHCMP0CR0_FILTER_CNT1 equ       %00100000
mGDU_PHCMP0CR0_FILTER_CNT2 equ       %01000000

;*** GDU_PHCMP0CR1 PHCMP0 Control Register 1
GDU_PHCMP0CR1       equ       $00000021
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP0CR1_EN    equ       0
GDU_PHCMP0CR1_OPE   equ       1
GDU_PHCMP0CR1_COS   equ       2
GDU_PHCMP0CR1_INV   equ       3
GDU_PHCMP0CR1_PMODE equ       4
GDU_PHCMP0CR1_WE    equ       6
GDU_PHCMP0CR1_SE    equ       7
; bit position masks
mGDU_PHCMP0CR1_EN   equ       %00000001
mGDU_PHCMP0CR1_OPE  equ       %00000010
mGDU_PHCMP0CR1_COS  equ       %00000100
mGDU_PHCMP0CR1_INV  equ       %00001000
mGDU_PHCMP0CR1_PMODE equ       %00010000
mGDU_PHCMP0CR1_WE   equ       %01000000
mGDU_PHCMP0CR1_SE   equ       %10000000

;*** GDU_PHCMP0FPR PHCMP0 Filter Period Register
GDU_PHCMP0FPR       equ       $00000022

;*** GDU_PHCMP0SCR PHCMP0 Status and Control Register
GDU_PHCMP0SCR       equ       $00000023
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP0SCR_COUT  equ       0
GDU_PHCMP0SCR_CFF   equ       1
GDU_PHCMP0SCR_CFR   equ       2
GDU_PHCMP0SCR_IEF   equ       3
GDU_PHCMP0SCR_IER   equ       4
; bit position masks
mGDU_PHCMP0SCR_COUT equ       %00000001
mGDU_PHCMP0SCR_CFF  equ       %00000010
mGDU_PHCMP0SCR_CFR  equ       %00000100
mGDU_PHCMP0SCR_IEF  equ       %00001000
mGDU_PHCMP0SCR_IER  equ       %00010000

;*** GDU_PHCMP1CR0 PHCMP1 Control Register 0
GDU_PHCMP1CR0       equ       $00000024
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP1CR0_HYSTCTR equ       0
GDU_PHCMP1CR0_FILTER_CNT0 equ       4
GDU_PHCMP1CR0_FILTER_CNT1 equ       5
GDU_PHCMP1CR0_FILTER_CNT2 equ       6
; bit position masks
mGDU_PHCMP1CR0_HYSTCTR equ       %00000001
mGDU_PHCMP1CR0_FILTER_CNT0 equ       %00010000
mGDU_PHCMP1CR0_FILTER_CNT1 equ       %00100000
mGDU_PHCMP1CR0_FILTER_CNT2 equ       %01000000

;*** GDU_PHCMP1CR1 PHCMP1 Control Register 1
GDU_PHCMP1CR1       equ       $00000025
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP1CR1_EN    equ       0
GDU_PHCMP1CR1_OPE   equ       1
GDU_PHCMP1CR1_COS   equ       2
GDU_PHCMP1CR1_INV   equ       3
GDU_PHCMP1CR1_PMODE equ       4
GDU_PHCMP1CR1_WE    equ       6
GDU_PHCMP1CR1_SE    equ       7
; bit position masks
mGDU_PHCMP1CR1_EN   equ       %00000001
mGDU_PHCMP1CR1_OPE  equ       %00000010
mGDU_PHCMP1CR1_COS  equ       %00000100
mGDU_PHCMP1CR1_INV  equ       %00001000
mGDU_PHCMP1CR1_PMODE equ       %00010000
mGDU_PHCMP1CR1_WE   equ       %01000000
mGDU_PHCMP1CR1_SE   equ       %10000000

;*** GDU_PHCMP1FPR PHCMP1 Filter Period Register
GDU_PHCMP1FPR       equ       $00000026

;*** GDU_PHCMP1SCR PHCMP1 Status and Control Register
GDU_PHCMP1SCR       equ       $00000027
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP1SCR_COUT  equ       0
GDU_PHCMP1SCR_CFF   equ       1
GDU_PHCMP1SCR_CFR   equ       2
GDU_PHCMP1SCR_IEF   equ       3
GDU_PHCMP1SCR_IER   equ       4
; bit position masks
mGDU_PHCMP1SCR_COUT equ       %00000001
mGDU_PHCMP1SCR_CFF  equ       %00000010
mGDU_PHCMP1SCR_CFR  equ       %00000100
mGDU_PHCMP1SCR_IEF  equ       %00001000
mGDU_PHCMP1SCR_IER  equ       %00010000

;*** GDU_PHCMP2CR0 PHCMP2 Control Register 0
GDU_PHCMP2CR0       equ       $00000028
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP2CR0_HYSTCTR equ       0
GDU_PHCMP2CR0_FILTER_CNT0 equ       4
GDU_PHCMP2CR0_FILTER_CNT1 equ       5
GDU_PHCMP2CR0_FILTER_CNT2 equ       6
; bit position masks
mGDU_PHCMP2CR0_HYSTCTR equ       %00000001
mGDU_PHCMP2CR0_FILTER_CNT0 equ       %00010000
mGDU_PHCMP2CR0_FILTER_CNT1 equ       %00100000
mGDU_PHCMP2CR0_FILTER_CNT2 equ       %01000000

;*** GDU_PHCMP2CR1 PHCMP2 Control Register 1
GDU_PHCMP2CR1       equ       $00000029
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP2CR1_EN    equ       0
GDU_PHCMP2CR1_OPE   equ       1
GDU_PHCMP2CR1_COS   equ       2
GDU_PHCMP2CR1_INV   equ       3
GDU_PHCMP2CR1_PMODE equ       4
GDU_PHCMP2CR1_WE    equ       6
GDU_PHCMP2CR1_SE    equ       7
; bit position masks
mGDU_PHCMP2CR1_EN   equ       %00000001
mGDU_PHCMP2CR1_OPE  equ       %00000010
mGDU_PHCMP2CR1_COS  equ       %00000100
mGDU_PHCMP2CR1_INV  equ       %00001000
mGDU_PHCMP2CR1_PMODE equ       %00010000
mGDU_PHCMP2CR1_WE   equ       %01000000
mGDU_PHCMP2CR1_SE   equ       %10000000

;*** GDU_PHCMP2FPR PHCMP2 Filter Period Register
GDU_PHCMP2FPR       equ       $0000002A

;*** GDU_PHCMP2SCR PHCMP2 Status and Control Register
GDU_PHCMP2SCR       equ       $0000002B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHCMP2SCR_COUT  equ       0
GDU_PHCMP2SCR_CFF   equ       1
GDU_PHCMP2SCR_CFR   equ       2
GDU_PHCMP2SCR_IEF   equ       3
GDU_PHCMP2SCR_IER   equ       4
; bit position masks
mGDU_PHCMP2SCR_COUT equ       %00000001
mGDU_PHCMP2SCR_CFF  equ       %00000010
mGDU_PHCMP2SCR_CFR  equ       %00000100
mGDU_PHCMP2SCR_IEF  equ       %00001000
mGDU_PHCMP2SCR_IER  equ       %00010000

;*** GDU_CLMPCTRL Clamp Control Register
GDU_CLMPCTRL        equ       $00001870
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_CLMPCTRL_CLAMPEN equ       0
GDU_CLMPCTRL_TUNE0  equ       1
GDU_CLMPCTRL_TUNE1  equ       2
GDU_CLMPCTRL_TUNE2  equ       3
GDU_CLMPCTRL_OVPIE  equ       6
GDU_CLMPCTRL_OVPEN  equ       7
; bit position masks
mGDU_CLMPCTRL_CLAMPEN equ       %00000001
mGDU_CLMPCTRL_TUNE0 equ       %00000010
mGDU_CLMPCTRL_TUNE1 equ       %00000100
mGDU_CLMPCTRL_TUNE2 equ       %00001000
mGDU_CLMPCTRL_OVPIE equ       %01000000
mGDU_CLMPCTRL_OVPEN equ       %10000000

;*** GDU_IOCTRL I/O Control Register
GDU_IOCTRL          equ       $00001871
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_IOCTRL_PDE      equ       0
GDU_IOCTRL_LSDS0    equ       1
GDU_IOCTRL_LSDS1    equ       2
GDU_IOCTRL_HSDS0    equ       4
GDU_IOCTRL_HSDS1    equ       5
GDU_IOCTRL_HSDE     equ       7
; bit position masks
mGDU_IOCTRL_PDE     equ       %00000001
mGDU_IOCTRL_LSDS0   equ       %00000010
mGDU_IOCTRL_LSDS1   equ       %00000100
mGDU_IOCTRL_HSDS0   equ       %00010000
mGDU_IOCTRL_HSDS1   equ       %00100000
mGDU_IOCTRL_HSDE    equ       %10000000

;*** GDU_PHASECTRL Virtual Network Phase Detection Control
GDU_PHASECTRL       equ       $00001872
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_PHASECTRL_PHSEL0 equ       0
GDU_PHASECTRL_PHSEL1 equ       1
GDU_PHASECTRL_PHSEL2 equ       2
GDU_PHASECTRL_EXTSEL equ       4
GDU_PHASECTRL_INTSEL equ       5
GDU_PHASECTRL_VNEN  equ       6
; bit position masks
mGDU_PHASECTRL_PHSEL0 equ       %00000001
mGDU_PHASECTRL_PHSEL1 equ       %00000010
mGDU_PHASECTRL_PHSEL2 equ       %00000100
mGDU_PHASECTRL_EXTSEL equ       %00010000
mGDU_PHASECTRL_INTSEL equ       %00100000
mGDU_PHASECTRL_VNEN equ       %01000000

;*** GDU_CURCTRL Current Sensor and Overcurrent Protection Control                        Register
GDU_CURCTRL         equ       $00001873
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_CURCTRL_AMP1EN  equ       0
GDU_CURCTRL_AMP0EN  equ       2
; bit position masks
mGDU_CURCTRL_AMP1EN equ       %00000001
mGDU_CURCTRL_AMP0EN equ       %00000100

;*** GDU_LIMIT0CR0 LIMIT0 CMP Control Register 0
GDU_LIMIT0CR0       equ       $00001874
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT0CR0_HYST  equ       0
GDU_LIMIT0CR0_FLTCNT0 equ       4
GDU_LIMIT0CR0_FLTCNT1 equ       5
GDU_LIMIT0CR0_FLTCNT2 equ       6
; bit position masks
mGDU_LIMIT0CR0_HYST equ       %00000001
mGDU_LIMIT0CR0_FLTCNT0 equ       %00010000
mGDU_LIMIT0CR0_FLTCNT1 equ       %00100000
mGDU_LIMIT0CR0_FLTCNT2 equ       %01000000

;*** GDU_LIMIT0CR1 LIMIT0 CMP Control Register 1
GDU_LIMIT0CR1       equ       $00001875
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT0CR1_EN    equ       0
GDU_LIMIT0CR1_OPE   equ       1
GDU_LIMIT0CR1_COS   equ       2
GDU_LIMIT0CR1_INV   equ       3
GDU_LIMIT0CR1_PMODE equ       4
GDU_LIMIT0CR1_WE    equ       6
GDU_LIMIT0CR1_SE    equ       7
; bit position masks
mGDU_LIMIT0CR1_EN   equ       %00000001
mGDU_LIMIT0CR1_OPE  equ       %00000010
mGDU_LIMIT0CR1_COS  equ       %00000100
mGDU_LIMIT0CR1_INV  equ       %00001000
mGDU_LIMIT0CR1_PMODE equ       %00010000
mGDU_LIMIT0CR1_WE   equ       %01000000
mGDU_LIMIT0CR1_SE   equ       %10000000

;*** GDU_LIMIT0FPR LIMIT0 CMP Filter Period Register
GDU_LIMIT0FPR       equ       $00001876

;*** GDU_LIMIT0SCR LIMIT0 CMP Status and Control Register
GDU_LIMIT0SCR       equ       $00001877
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT0SCR_COUT  equ       0
GDU_LIMIT0SCR_CFF   equ       1
GDU_LIMIT0SCR_CFR   equ       2
GDU_LIMIT0SCR_IEF   equ       3
GDU_LIMIT0SCR_IER   equ       4
; bit position masks
mGDU_LIMIT0SCR_COUT equ       %00000001
mGDU_LIMIT0SCR_CFF  equ       %00000010
mGDU_LIMIT0SCR_CFR  equ       %00000100
mGDU_LIMIT0SCR_IEF  equ       %00001000
mGDU_LIMIT0SCR_IER  equ       %00010000

;*** GDU_LIMIT0DACCR LIMIT0 DAC Control Register
GDU_LIMIT0DACCR     equ       $00001878
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT0DACCR_VOSEL0 equ       0
GDU_LIMIT0DACCR_VOSEL1 equ       1
GDU_LIMIT0DACCR_VOSEL2 equ       2
GDU_LIMIT0DACCR_VOSEL3 equ       3
GDU_LIMIT0DACCR_VOSEL4 equ       4
GDU_LIMIT0DACCR_VOSEL5 equ       5
; bit position masks
mGDU_LIMIT0DACCR_VOSEL0 equ       %00000001
mGDU_LIMIT0DACCR_VOSEL1 equ       %00000010
mGDU_LIMIT0DACCR_VOSEL2 equ       %00000100
mGDU_LIMIT0DACCR_VOSEL3 equ       %00001000
mGDU_LIMIT0DACCR_VOSEL4 equ       %00010000
mGDU_LIMIT0DACCR_VOSEL5 equ       %00100000

;*** GDU_LIMIT1CR0 LIMIT1 CMP Control Register 0
GDU_LIMIT1CR0       equ       $00001879
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT1CR0_HYST  equ       0
GDU_LIMIT1CR0_FLTCNT0 equ       4
GDU_LIMIT1CR0_FLTCNT1 equ       5
GDU_LIMIT1CR0_FLTCNT2 equ       6
; bit position masks
mGDU_LIMIT1CR0_HYST equ       %00000001
mGDU_LIMIT1CR0_FLTCNT0 equ       %00010000
mGDU_LIMIT1CR0_FLTCNT1 equ       %00100000
mGDU_LIMIT1CR0_FLTCNT2 equ       %01000000

;*** GDU_LIMIT1CR1 LIMIT1 CMP Control Register 1
GDU_LIMIT1CR1       equ       $0000187A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT1CR1_EN    equ       0
GDU_LIMIT1CR1_OPE   equ       1
GDU_LIMIT1CR1_COS   equ       2
GDU_LIMIT1CR1_INV   equ       3
GDU_LIMIT1CR1_PMODE equ       4
GDU_LIMIT1CR1_WE    equ       6
GDU_LIMIT1CR1_SE    equ       7
; bit position masks
mGDU_LIMIT1CR1_EN   equ       %00000001
mGDU_LIMIT1CR1_OPE  equ       %00000010
mGDU_LIMIT1CR1_COS  equ       %00000100
mGDU_LIMIT1CR1_INV  equ       %00001000
mGDU_LIMIT1CR1_PMODE equ       %00010000
mGDU_LIMIT1CR1_WE   equ       %01000000
mGDU_LIMIT1CR1_SE   equ       %10000000

;*** GDU_LIMIT1FPR LIMIT1 CMP Filter Period Register
GDU_LIMIT1FPR       equ       $0000187B

;*** GDU_LIMIT1SCR LIMIT1 CMP Status and Control Register
GDU_LIMIT1SCR       equ       $0000187C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT1SCR_COUT  equ       0
GDU_LIMIT1SCR_CFF   equ       1
GDU_LIMIT1SCR_CFR   equ       2
GDU_LIMIT1SCR_IEF   equ       3
GDU_LIMIT1SCR_IER   equ       4
; bit position masks
mGDU_LIMIT1SCR_COUT equ       %00000001
mGDU_LIMIT1SCR_CFF  equ       %00000010
mGDU_LIMIT1SCR_CFR  equ       %00000100
mGDU_LIMIT1SCR_IEF  equ       %00001000
mGDU_LIMIT1SCR_IER  equ       %00010000

;*** GDU_LIMIT1DACCR LIMIT1 DAC Control Register
GDU_LIMIT1DACCR     equ       $0000187D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_LIMIT1DACCR_VOSEL0 equ       0
GDU_LIMIT1DACCR_VOSEL1 equ       1
GDU_LIMIT1DACCR_VOSEL2 equ       2
GDU_LIMIT1DACCR_VOSEL3 equ       3
GDU_LIMIT1DACCR_VOSEL4 equ       4
GDU_LIMIT1DACCR_VOSEL5 equ       5
; bit position masks
mGDU_LIMIT1DACCR_VOSEL0 equ       %00000001
mGDU_LIMIT1DACCR_VOSEL1 equ       %00000010
mGDU_LIMIT1DACCR_VOSEL2 equ       %00000100
mGDU_LIMIT1DACCR_VOSEL3 equ       %00001000
mGDU_LIMIT1DACCR_VOSEL4 equ       %00010000
mGDU_LIMIT1DACCR_VOSEL5 equ       %00100000

;*** GDU_STATREG PDCS and Clamp Status Register
GDU_STATREG         equ       $0000187E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_STATREG_PHASE0  equ       0
GDU_STATREG_PHASE1  equ       1
GDU_STATREG_PHASE2  equ       2
GDU_STATREG_OVP24V  equ       6
GDU_STATREG_OVP22V  equ       7
; bit position masks
mGDU_STATREG_PHASE0 equ       %00000001
mGDU_STATREG_PHASE1 equ       %00000010
mGDU_STATREG_PHASE2 equ       %00000100
mGDU_STATREG_OVP24V equ       %01000000
mGDU_STATREG_OVP22V equ       %10000000

;*** GDU_SIGBIAS LIMIT CMP BIAS Register
GDU_SIGBIAS         equ       $0000187F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GDU_SIGBIAS_BIASSEL equ       7
; bit position masks
mGDU_SIGBIAS_BIASSEL equ       %10000000

;*** I2C_A1 I2C Address Register 1
I2C_A1              equ       $000018B0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_A1_AD0          equ       1
I2C_A1_AD1          equ       2
I2C_A1_AD2          equ       3
I2C_A1_AD3          equ       4
I2C_A1_AD4          equ       5
I2C_A1_AD5          equ       6
I2C_A1_AD6          equ       7
; bit position masks
mI2C_A1_AD0         equ       %00000010
mI2C_A1_AD1         equ       %00000100
mI2C_A1_AD2         equ       %00001000
mI2C_A1_AD3         equ       %00010000
mI2C_A1_AD4         equ       %00100000
mI2C_A1_AD5         equ       %01000000
mI2C_A1_AD6         equ       %10000000

;*** I2C_F I2C Frequency Divider register
I2C_F               equ       $000018B1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_F_ICR0          equ       0
I2C_F_ICR1          equ       1
I2C_F_ICR2          equ       2
I2C_F_ICR3          equ       3
I2C_F_ICR4          equ       4
I2C_F_ICR5          equ       5
I2C_F_MULT0         equ       6
I2C_F_MULT1         equ       7
; bit position masks
mI2C_F_ICR0         equ       %00000001
mI2C_F_ICR1         equ       %00000010
mI2C_F_ICR2         equ       %00000100
mI2C_F_ICR3         equ       %00001000
mI2C_F_ICR4         equ       %00010000
mI2C_F_ICR5         equ       %00100000
mI2C_F_MULT0        equ       %01000000
mI2C_F_MULT1        equ       %10000000

;*** I2C_C1 I2C Control Register 1
I2C_C1              equ       $000018B2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_C1_WUEN         equ       1
I2C_C1_RSTA         equ       2
I2C_C1_TXAK         equ       3
I2C_C1_TX           equ       4
I2C_C1_MST          equ       5
I2C_C1_IICIE        equ       6
I2C_C1_IICEN        equ       7
; bit position masks
mI2C_C1_WUEN        equ       %00000010
mI2C_C1_RSTA        equ       %00000100
mI2C_C1_TXAK        equ       %00001000
mI2C_C1_TX          equ       %00010000
mI2C_C1_MST         equ       %00100000
mI2C_C1_IICIE       equ       %01000000
mI2C_C1_IICEN       equ       %10000000

;*** I2C_S I2C Status register
I2C_S               equ       $000018B3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_S_RXAK          equ       0
I2C_S_IICIF         equ       1
I2C_S_SRW           equ       2
I2C_S_RAM           equ       3
I2C_S_ARBL          equ       4
I2C_S_BUSY          equ       5
I2C_S_IAAS          equ       6
I2C_S_TCF           equ       7
; bit position masks
mI2C_S_RXAK         equ       %00000001
mI2C_S_IICIF        equ       %00000010
mI2C_S_SRW          equ       %00000100
mI2C_S_RAM          equ       %00001000
mI2C_S_ARBL         equ       %00010000
mI2C_S_BUSY         equ       %00100000
mI2C_S_IAAS         equ       %01000000
mI2C_S_TCF          equ       %10000000

;*** I2C_D I2C Data I/O register
I2C_D               equ       $000018B4

;*** I2C_C2 I2C Control Register 2
I2C_C2              equ       $000018B5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_C2_AD0          equ       0
I2C_C2_AD1          equ       1
I2C_C2_AD2          equ       2
I2C_C2_RMEN         equ       3
I2C_C2_ADEXT        equ       6
I2C_C2_GCAEN        equ       7
; bit position masks
mI2C_C2_AD0         equ       %00000001
mI2C_C2_AD1         equ       %00000010
mI2C_C2_AD2         equ       %00000100
mI2C_C2_RMEN        equ       %00001000
mI2C_C2_ADEXT       equ       %01000000
mI2C_C2_GCAEN       equ       %10000000

;*** I2C_SCS I2C
I2C_SCS             equ       $000018B6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_SCS_STARTF      equ       4
I2C_SCS_SSIE        equ       5
I2C_SCS_STOPF       equ       6
I2C_SCS_SHEN        equ       7
; bit position masks
mI2C_SCS_STARTF     equ       %00010000
mI2C_SCS_SSIE       equ       %00100000
mI2C_SCS_STOPF      equ       %01000000
mI2C_SCS_SHEN       equ       %10000000

;*** I2C_RA I2C Range Address register
I2C_RA              equ       $000018B7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_RA_RAD0         equ       1
I2C_RA_RAD1         equ       2
I2C_RA_RAD2         equ       3
I2C_RA_RAD3         equ       4
I2C_RA_RAD4         equ       5
I2C_RA_RAD5         equ       6
I2C_RA_RAD6         equ       7
; bit position masks
mI2C_RA_RAD0        equ       %00000010
mI2C_RA_RAD1        equ       %00000100
mI2C_RA_RAD2        equ       %00001000
mI2C_RA_RAD3        equ       %00010000
mI2C_RA_RAD4        equ       %00100000
mI2C_RA_RAD5        equ       %01000000
mI2C_RA_RAD6        equ       %10000000

;*** I2C_SMB I2C SMBus Control and Status register
I2C_SMB             equ       $000018B8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_SMB_SHTF2IE     equ       0
I2C_SMB_SHTF2       equ       1
I2C_SMB_SHTF1       equ       2
I2C_SMB_SLTF        equ       3
I2C_SMB_TCKSEL      equ       4
I2C_SMB_SIICAEN     equ       5
I2C_SMB_ALERTEN     equ       6
I2C_SMB_FACK        equ       7
; bit position masks
mI2C_SMB_SHTF2IE    equ       %00000001
mI2C_SMB_SHTF2      equ       %00000010
mI2C_SMB_SHTF1      equ       %00000100
mI2C_SMB_SLTF       equ       %00001000
mI2C_SMB_TCKSEL     equ       %00010000
mI2C_SMB_SIICAEN    equ       %00100000
mI2C_SMB_ALERTEN    equ       %01000000
mI2C_SMB_FACK       equ       %10000000

;*** I2C_A2 I2C Address Register 2
I2C_A2              equ       $000018B9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_A2_SAD0         equ       1
I2C_A2_SAD1         equ       2
I2C_A2_SAD2         equ       3
I2C_A2_SAD3         equ       4
I2C_A2_SAD4         equ       5
I2C_A2_SAD5         equ       6
I2C_A2_SAD6         equ       7
; bit position masks
mI2C_A2_SAD0        equ       %00000010
mI2C_A2_SAD1        equ       %00000100
mI2C_A2_SAD2        equ       %00001000
mI2C_A2_SAD3        equ       %00010000
mI2C_A2_SAD4        equ       %00100000
mI2C_A2_SAD5        equ       %01000000
mI2C_A2_SAD6        equ       %10000000

;*** I2C_SLTH I2C SCL Low Timeout Register High
I2C_SLTH            equ       $000018BA

;*** I2C_SLTL I2C SCL Low Timeout Register Low
I2C_SLTL            equ       $000018BB

;*** I2C_S2 I2C Status register 2
I2C_S2              equ       $000018BC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
I2C_S2_EMPTY        equ       0
I2C_S2_ERROR        equ       1
; bit position masks
mI2C_S2_EMPTY       equ       %00000001
mI2C_S2_ERROR       equ       %00000010

;*** ICS_C1 ICS Control Register 1
ICS_C1              equ       $00001848
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C1_IRCLKEN      equ       1
ICS_C1_IREFS        equ       2
ICS_C1_RDIV0        equ       3
ICS_C1_RDIV1        equ       4
ICS_C1_RDIV2        equ       5
ICS_C1_CLKS0        equ       6
ICS_C1_CLKS1        equ       7
; bit position masks
mICS_C1_IRCLKEN     equ       %00000010
mICS_C1_IREFS       equ       %00000100
mICS_C1_RDIV0       equ       %00001000
mICS_C1_RDIV1       equ       %00010000
mICS_C1_RDIV2       equ       %00100000
mICS_C1_CLKS0       equ       %01000000
mICS_C1_CLKS1       equ       %10000000

;*** ICS_C2 ICS Control Register 2
ICS_C2              equ       $00001849
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
ICS_C3              equ       $0000184A

;*** ICS_C4 ICS Control Register 4
ICS_C4              equ       $0000184B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICS_C4_SCFTRIM      equ       0
ICS_C4_CME          equ       5
ICS_C4_LOLIE        equ       7
; bit position masks
mICS_C4_SCFTRIM     equ       %00000001
mICS_C4_CME         equ       %00100000
mICS_C4_LOLIE       equ       %10000000

;*** ICS_S ICS Status Register
ICS_S               equ       $0000184C
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

;*** IPC_SC IPC Status and Control Register
IPC_SC              equ       $0000000E
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
IPC_IPMPS           equ       $0000000F
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

;*** IPC_ILRS0 Interrupt Level Setting Registers n
IPC_ILRS0           equ       $00001860
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
IPC_ILRS1           equ       $00001861
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
IPC_ILRS2           equ       $00001862
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
IPC_ILRS3           equ       $00001863
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
IPC_ILRS4           equ       $00001864
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
IPC_ILRS5           equ       $00001865
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
IPC_ILRS6           equ       $00001866
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
IPC_ILRS7           equ       $00001867
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

;*** IRQ_SC Interrupt Pin Request Status and Control Register
IRQ_SC              equ       $0000007F
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

;*** KBI_SC KBI Status and Control Register
KBI_SC              equ       $0000007C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI_SC_KBMOD        equ       0
KBI_SC_KBIE         equ       1
KBI_SC_KBACK        equ       2
KBI_SC_KBF          equ       3
; bit position masks
mKBI_SC_KBMOD       equ       %00000001
mKBI_SC_KBIE        equ       %00000010
mKBI_SC_KBACK       equ       %00000100
mKBI_SC_KBF         equ       %00001000

;*** KBI_PE KBI Pin Enable Register
KBI_PE              equ       $0000007D

;*** KBI_ES KBI Edge Select Register
KBI_ES              equ       $0000007E

;*** MTIM_SC MTIM16 status and control register
MTIM_SC             equ       $00000008
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM_SC_TSTP        equ       4
MTIM_SC_TRST        equ       5
MTIM_SC_TOIE        equ       6
MTIM_SC_TOF         equ       7
; bit position masks
mMTIM_SC_TSTP       equ       %00010000
mMTIM_SC_TRST       equ       %00100000
mMTIM_SC_TOIE       equ       %01000000
mMTIM_SC_TOF        equ       %10000000

;*** MTIM_CLK MTIM16 clock configuration register
MTIM_CLK            equ       $00000009
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM_CLK_PS0        equ       0
MTIM_CLK_PS1        equ       1
MTIM_CLK_PS2        equ       2
MTIM_CLK_PS3        equ       3
MTIM_CLK_CLKS0      equ       4
MTIM_CLK_CLKS1      equ       5
; bit position masks
mMTIM_CLK_PS0       equ       %00000001
mMTIM_CLK_PS1       equ       %00000010
mMTIM_CLK_PS2       equ       %00000100
mMTIM_CLK_PS3       equ       %00001000
mMTIM_CLK_CLKS0     equ       %00010000
mMTIM_CLK_CLKS1     equ       %00100000

;*** MTIM_CNTH MTIM16 counter register high
MTIM_CNTH           equ       $0000000A

;*** MTIM_CNTL MTIM16 counter register low
MTIM_CNTL           equ       $0000000B

;*** MTIM_MODH MTIM16 modulo register high
MTIM_MODH           equ       $0000000C

;*** MTIM_MODL MTIM16 modulo register low
MTIM_MODL           equ       $0000000D

;*** PDB_CTRL0 PDB Control Register 0
PDB_CTRL0           equ       $00000060
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB_CTRL0_MOD0      equ       0
PDB_CTRL0_TRGOUT0   equ       1
PDB_CTRL0_TCIE0     equ       2
PDB_CTRL0_TCF0      equ       3
PDB_CTRL0_MOD1      equ       4
PDB_CTRL0_TRGOUT1   equ       5
PDB_CTRL0_TCIE1     equ       6
PDB_CTRL0_TCF1      equ       7
; bit position masks
mPDB_CTRL0_MOD0     equ       %00000001
mPDB_CTRL0_TRGOUT0  equ       %00000010
mPDB_CTRL0_TCIE0    equ       %00000100
mPDB_CTRL0_TCF0     equ       %00001000
mPDB_CTRL0_MOD1     equ       %00010000
mPDB_CTRL0_TRGOUT1  equ       %00100000
mPDB_CTRL0_TCIE1    equ       %01000000
mPDB_CTRL0_TCF1     equ       %10000000

;*** PDB_CTRL1 PDB Control Register 1
PDB_CTRL1           equ       $00000061
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB_CTRL1_SWTRG0    equ       0
PDB_CTRL1_SWCLR0    equ       1
PDB_CTRL1_SWTRG1    equ       2
PDB_CTRL1_SWCLR1    equ       3
PDB_CTRL1_PRESCALER0 equ       4
PDB_CTRL1_PRESCALER1 equ       5
PDB_CTRL1_CNTSEL0   equ       6
PDB_CTRL1_CNTSEL1   equ       7
; bit position masks
mPDB_CTRL1_SWTRG0   equ       %00000001
mPDB_CTRL1_SWCLR0   equ       %00000010
mPDB_CTRL1_SWTRG1   equ       %00000100
mPDB_CTRL1_SWCLR1   equ       %00001000
mPDB_CTRL1_PRESCALER0 equ       %00010000
mPDB_CTRL1_PRESCALER1 equ       %00100000
mPDB_CTRL1_CNTSEL0  equ       %01000000
mPDB_CTRL1_CNTSEL1  equ       %10000000

;*** PDB_CMPL0 PDB0 Comparison Low Register
PDB_CMPL0           equ       $00000062

;*** PDB_CMPH0 PDB0 Comparison High Register
PDB_CMPH0           equ       $00000063

;*** PDB_CNT0 PDB0 Counter High/Low
PDB_CNT0            equ       $00000064
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB_CNT0_CNT0_0_PDBEN0 equ       0
PDB_CNT0_CNT0_7_10  equ       1
PDB_CNT0_CNT0_7_11  equ       2
PDB_CNT0_CNT0_7_12  equ       3
PDB_CNT0_CNT0_7_13  equ       4
PDB_CNT0_CNT0_7_14  equ       5
PDB_CNT0_CNT0_7_15  equ       6
PDB_CNT0_CNT0_7_16  equ       7
; bit position masks
mPDB_CNT0_CNT0_0_PDBEN0 equ       %00000001
mPDB_CNT0_CNT0_7_10 equ       %00000010
mPDB_CNT0_CNT0_7_11 equ       %00000100
mPDB_CNT0_CNT0_7_12 equ       %00001000
mPDB_CNT0_CNT0_7_13 equ       %00010000
mPDB_CNT0_CNT0_7_14 equ       %00100000
mPDB_CNT0_CNT0_7_15 equ       %01000000
mPDB_CNT0_CNT0_7_16 equ       %10000000

;*** PDB_CMPL1 PDB1 Comparison Low Register
PDB_CMPL1           equ       $00000065

;*** PDB_CMPH1 PDB1 Comparison High Register
PDB_CMPH1           equ       $00000066

;*** PDB_CNT1 PDB1 Counter High/Low
PDB_CNT1            equ       $00000067
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDB_CNT1_CNT1_0_PDBEN1 equ       0
PDB_CNT1_CNT1_7_10  equ       1
PDB_CNT1_CNT1_7_11  equ       2
PDB_CNT1_CNT1_7_12  equ       3
PDB_CNT1_CNT1_7_13  equ       4
PDB_CNT1_CNT1_7_14  equ       5
PDB_CNT1_CNT1_7_15  equ       6
PDB_CNT1_CNT1_7_16  equ       7
; bit position masks
mPDB_CNT1_CNT1_0_PDBEN1 equ       %00000001
mPDB_CNT1_CNT1_7_10 equ       %00000010
mPDB_CNT1_CNT1_7_11 equ       %00000100
mPDB_CNT1_CNT1_7_12 equ       %00001000
mPDB_CNT1_CNT1_7_13 equ       %00010000
mPDB_CNT1_CNT1_7_14 equ       %00100000
mPDB_CNT1_CNT1_7_15 equ       %01000000
mPDB_CNT1_CNT1_7_16 equ       %10000000

;*** PMC_CTRL Control Register
PMC_CTRL            equ       $00001850
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_CTRL_RC20KENSTP equ       1
PMC_CTRL_VREFDN     equ       2
PMC_CTRL_GWREN      equ       7
; bit position masks
mPMC_CTRL_RC20KENSTP equ       %00000010
mPMC_CTRL_VREFDN    equ       %00000100
mPMC_CTRL_GWREN     equ       %10000000

;*** PMC_RST Reset Flags Register
PMC_RST             equ       $00001851
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_RST_LVRF        equ       5
PMC_RST_PORF        equ       6
; bit position masks
mPMC_RST_LVRF       equ       %00100000
mPMC_RST_PORF       equ       %01000000

;*** PMC_TPCTRLSTAT Temperature Control and Status Register
PMC_TPCTRLSTAT      equ       $00001852
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_TPCTRLSTAT_HTIF equ       0
PMC_TPCTRLSTAT_HTIE equ       1
PMC_TPCTRLSTAT_HTDS equ       2
PMC_TPCTRLSTAT_TEMPEN equ       3
PMC_TPCTRLSTAT_SWON equ       4
; bit position masks
mPMC_TPCTRLSTAT_HTIF equ       %00000001
mPMC_TPCTRLSTAT_HTIE equ       %00000010
mPMC_TPCTRLSTAT_HTDS equ       %00000100
mPMC_TPCTRLSTAT_TEMPEN equ       %00001000
mPMC_TPCTRLSTAT_SWON equ       %00010000

;*** PMC_TPTM Temperature Offset Step Trim Register
PMC_TPTM            equ       $00001853
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_TPTM_TOT0       equ       0
PMC_TPTM_TOT1       equ       1
PMC_TPTM_TOT2       equ       2
PMC_TPTM_TOT3       equ       3
PMC_TPTM_TRMTPEN    equ       7
; bit position masks
mPMC_TPTM_TOT0      equ       %00000001
mPMC_TPTM_TOT1      equ       %00000010
mPMC_TPTM_TOT2      equ       %00000100
mPMC_TPTM_TOT3      equ       %00001000
mPMC_TPTM_TRMTPEN   equ       %10000000

;*** PMC_RC20KTRM RC Oscillator Offset Step Trim Register
PMC_RC20KTRM        equ       $00001854
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_RC20KTRM_OSCOT0 equ       0
PMC_RC20KTRM_OSCOT1 equ       1
PMC_RC20KTRM_OSCOT2 equ       2
PMC_RC20KTRM_OSCOT3 equ       3
PMC_RC20KTRM_OSCOT4 equ       4
PMC_RC20KTRM_OSCOT5 equ       5
; bit position masks
mPMC_RC20KTRM_OSCOT0 equ       %00000001
mPMC_RC20KTRM_OSCOT1 equ       %00000010
mPMC_RC20KTRM_OSCOT2 equ       %00000100
mPMC_RC20KTRM_OSCOT3 equ       %00001000
mPMC_RC20KTRM_OSCOT4 equ       %00010000
mPMC_RC20KTRM_OSCOT5 equ       %00100000

;*** PMC_LVCTLSTAT1 Low Voltage Control and Status Register 1 (system 5                        V)
PMC_LVCTLSTAT1      equ       $00001855
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_LVCTLSTAT1_SLVWSEL equ       1
PMC_LVCTLSTAT1_SLVWIE equ       2
PMC_LVCTLSTAT1_SLVWACK equ       3
PMC_LVCTLSTAT1_SLVWF equ       4
; bit position masks
mPMC_LVCTLSTAT1_SLVWSEL equ       %00000010
mPMC_LVCTLSTAT1_SLVWIE equ       %00000100
mPMC_LVCTLSTAT1_SLVWACK equ       %00001000
mPMC_LVCTLSTAT1_SLVWF equ       %00010000

;*** PMC_LVCTLSTAT2 Low Voltage Control and Status Register 2                        (V
PMC_LVCTLSTAT2      equ       $00001856
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_LVCTLSTAT2_RLVWIE equ       2
PMC_LVCTLSTAT2_RLVWACK equ       3
PMC_LVCTLSTAT2_RLVWF equ       4
; bit position masks
mPMC_LVCTLSTAT2_RLVWIE equ       %00000100
mPMC_LVCTLSTAT2_RLVWACK equ       %00001000
mPMC_LVCTLSTAT2_RLVWF equ       %00010000

;*** PMC_VREFHCFG V
PMC_VREFHCFG        equ       $00001857
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_VREFHCFG_T5V0   equ       0
PMC_VREFHCFG_T5V1   equ       1
PMC_VREFHCFG_T5V2   equ       2
PMC_VREFHCFG_T5V3   equ       3
PMC_VREFHCFG_T5V4   equ       4
PMC_VREFHCFG_T5V5   equ       5
; bit position masks
mPMC_VREFHCFG_T5V0  equ       %00000001
mPMC_VREFHCFG_T5V1  equ       %00000010
mPMC_VREFHCFG_T5V2  equ       %00000100
mPMC_VREFHCFG_T5V3  equ       %00001000
mPMC_VREFHCFG_T5V4  equ       %00010000
mPMC_VREFHCFG_T5V5  equ       %00100000

;*** PMC_VREFHLVW VREFH Low Voltage Warning (LVW) Configuration                        Register
PMC_VREFHLVW        equ       $00001858
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_VREFHLVW_LVWCFG0 equ       0
PMC_VREFHLVW_LVWCFG1 equ       1
; bit position masks
mPMC_VREFHLVW_LVWCFG0 equ       %00000001
mPMC_VREFHLVW_LVWCFG1 equ       %00000010

;*** PMC_STAT Status Register
PMC_STAT            equ       $00001859
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PMC_STAT_VREFRDY    equ       0
PMC_STAT_HBGRDY     equ       2
; bit position masks
mPMC_STAT_VREFRDY   equ       %00000001
mPMC_STAT_HBGRDY    equ       %00000100

;*** PORT_PTAD Port A Data Register
PORT_PTAD           equ       $00000000

;*** PORT_PTBD Port B Data Register
PORT_PTBD           equ       $00000001

;*** PORT_PTCD Port C Data Register
PORT_PTCD           equ       $00000002
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCD_PTCD      equ       0
; bit position masks
mPORT_PTCD_PTCD     equ       %00000001

;*** PORT_PTADD Port A Direction Register
PORT_PTADD          equ       $00000003

;*** PORT_PTBDD Port B Direction Register
PORT_PTBDD          equ       $00000004

;*** PORT_PTCDD Port C Direction Register
PORT_PTCDD          equ       $00000005
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCDD_PTCDD    equ       0
; bit position masks
mPORT_PTCDD_PTCDD   equ       %00000001

;*** PORT_PTAPE Port A Pullup Enable Register
PORT_PTAPE          equ       $000018E0

;*** PORT_PTBPE Port B Pullup/Pulldown Enable Register
PORT_PTBPE          equ       $000018E1

;*** PORT_PTCPE Port C Pullup Enable Register
PORT_PTCPE          equ       $000018E2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTCPE_PTCPE    equ       0
; bit position masks
mPORT_PTCPE_PTCPE   equ       %00000001

;*** PORT_PTBHD Port B High Drive Strength Selection Register
PORT_PTBHD          equ       $000018E6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_PTBHD_HD7      equ       7
; bit position masks
mPORT_PTBHD_HD7     equ       %10000000

;*** PORT_FCLKDIV Port Clock Division Register
PORT_FCLKDIV        equ       $000018EC
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

;*** PORT_IOFLT0 Port Filter Register 0
PORT_IOFLT0         equ       $000018ED
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT0_FLTA0   equ       0
PORT_IOFLT0_FLTA1   equ       1
PORT_IOFLT0_FLTB0   equ       2
PORT_IOFLT0_FLTB1   equ       3
PORT_IOFLT0_FLTC0   equ       4
PORT_IOFLT0_FLTC1   equ       5
; bit position masks
mPORT_IOFLT0_FLTA0  equ       %00000001
mPORT_IOFLT0_FLTA1  equ       %00000010
mPORT_IOFLT0_FLTB0  equ       %00000100
mPORT_IOFLT0_FLTB1  equ       %00001000
mPORT_IOFLT0_FLTC0  equ       %00010000
mPORT_IOFLT0_FLTC1  equ       %00100000

;*** PORT_IOFLT1 Port Filter Register 1
PORT_IOFLT1         equ       $000018EE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT1_FLTRST0 equ       4
PORT_IOFLT1_FLTRST1 equ       5
PORT_IOFLT1_FLTKBI0 equ       6
PORT_IOFLT1_FLTKBI1 equ       7
; bit position masks
mPORT_IOFLT1_FLTRST0 equ       %00010000
mPORT_IOFLT1_FLTRST1 equ       %00100000
mPORT_IOFLT1_FLTKBI0 equ       %01000000
mPORT_IOFLT1_FLTKBI1 equ       %10000000

;*** PORT_IOFLT2 Port Filter Register 2
PORT_IOFLT2         equ       $000018EF
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PORT_IOFLT2_FLTXBI0 equ       0
PORT_IOFLT2_FLTXBI1 equ       1
PORT_IOFLT2_FLTI2C0 equ       2
PORT_IOFLT2_FLTI2C1 equ       3
PORT_IOFLT2_FLTPWT00 equ       4
PORT_IOFLT2_FLTPWT01 equ       5
PORT_IOFLT2_FLTPWT10 equ       6
PORT_IOFLT2_FLTPWT11 equ       7
; bit position masks
mPORT_IOFLT2_FLTXBI0 equ       %00000001
mPORT_IOFLT2_FLTXBI1 equ       %00000010
mPORT_IOFLT2_FLTI2C0 equ       %00000100
mPORT_IOFLT2_FLTI2C1 equ       %00001000
mPORT_IOFLT2_FLTPWT00 equ       %00010000
mPORT_IOFLT2_FLTPWT01 equ       %00100000
mPORT_IOFLT2_FLTPWT10 equ       %01000000
mPORT_IOFLT2_FLTPWT11 equ       %10000000

;*** PWM_CTRLL PWM Control Register: Low
PWM_CTRLL           equ       $00000040
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CTRLL_PWMEN     equ       0
PWM_CTRLL_LDOK      equ       1
PWM_CTRLL_PWMF      equ       4
PWM_CTRLL_PWMRIE    equ       5
PWM_CTRLL_PRSC0     equ       6
PWM_CTRLL_PRSC1     equ       7
; bit position masks
mPWM_CTRLL_PWMEN    equ       %00000001
mPWM_CTRLL_LDOK     equ       %00000010
mPWM_CTRLL_PWMF     equ       %00010000
mPWM_CTRLL_PWMRIE   equ       %00100000
mPWM_CTRLL_PRSC0    equ       %01000000
mPWM_CTRLL_PRSC1    equ       %10000000

;*** PWM_CTRLH PWM Control Register: High
PWM_CTRLH           equ       $00000041
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CTRLH_HALF      equ       3
PWM_CTRLH_LDFQ0     equ       4
PWM_CTRLH_LDFQ1     equ       5
PWM_CTRLH_LDFQ2     equ       6
PWM_CTRLH_LDFQ3     equ       7
; bit position masks
mPWM_CTRLH_HALF     equ       %00001000
mPWM_CTRLH_LDFQ0    equ       %00010000
mPWM_CTRLH_LDFQ1    equ       %00100000
mPWM_CTRLH_LDFQ2    equ       %01000000
mPWM_CTRLH_LDFQ3    equ       %10000000

;*** PWM_FCTRLL PWM Fault Control Register: Low
PWM_FCTRLL          equ       $00000042
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_FCTRLL_FMODE0   equ       0
PWM_FCTRLL_FIE0     equ       1
PWM_FCTRLL_FMODE1   equ       2
PWM_FCTRLL_FIE1     equ       3
PWM_FCTRLL_FMODE2   equ       4
PWM_FCTRLL_FIE2     equ       5
PWM_FCTRLL_FMODE3   equ       6
PWM_FCTRLL_FIE3     equ       7
; bit position masks
mPWM_FCTRLL_FMODE0  equ       %00000001
mPWM_FCTRLL_FIE0    equ       %00000010
mPWM_FCTRLL_FMODE1  equ       %00000100
mPWM_FCTRLL_FIE1    equ       %00001000
mPWM_FCTRLL_FMODE2  equ       %00010000
mPWM_FCTRLL_FIE2    equ       %00100000
mPWM_FCTRLL_FMODE3  equ       %01000000
mPWM_FCTRLL_FIE3    equ       %10000000

;*** PWM_FCTRLH PWM Fault Control Register: High
PWM_FCTRLH          equ       $00000043
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_FCTRLH_FPOL0    equ       0
PWM_FCTRLH_FPOL1    equ       1
PWM_FCTRLH_FPOL2    equ       2
PWM_FCTRLH_FPOL3    equ       3
; bit position masks
mPWM_FCTRLH_FPOL0   equ       %00000001
mPWM_FCTRLH_FPOL1   equ       %00000010
mPWM_FCTRLH_FPOL2   equ       %00000100
mPWM_FCTRLH_FPOL3   equ       %00001000

;*** PWM_FLTACKL PWM Fault Status Acknowledge Register: Low
PWM_FLTACKL         equ       $00000044
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_FLTACKL_FTACK0  equ       0
PWM_FLTACKL_FTACK1  equ       2
PWM_FLTACKL_FTACK2  equ       4
PWM_FLTACKL_FTACK3  equ       6
; bit position masks
mPWM_FLTACKL_FTACK0 equ       %00000001
mPWM_FLTACKL_FTACK1 equ       %00000100
mPWM_FLTACKL_FTACK2 equ       %00010000
mPWM_FLTACKL_FTACK3 equ       %01000000

;*** PWM_FLTACKH PWM Fault Status Acknowledge Register: High
PWM_FLTACKH         equ       $00000045
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_FLTACKH_FFLAG0  equ       0
PWM_FLTACKH_FPIN0   equ       1
PWM_FLTACKH_FFLAG1  equ       2
PWM_FLTACKH_FPIN1   equ       3
PWM_FLTACKH_FFLAG2  equ       4
PWM_FLTACKH_FPIN2   equ       5
PWM_FLTACKH_FFLAG3  equ       6
PWM_FLTACKH_FPIN3   equ       7
; bit position masks
mPWM_FLTACKH_FFLAG0 equ       %00000001
mPWM_FLTACKH_FPIN0  equ       %00000010
mPWM_FLTACKH_FFLAG1 equ       %00000100
mPWM_FLTACKH_FPIN1  equ       %00001000
mPWM_FLTACKH_FFLAG2 equ       %00010000
mPWM_FLTACKH_FPIN2  equ       %00100000
mPWM_FLTACKH_FFLAG3 equ       %01000000
mPWM_FLTACKH_FPIN3  equ       %10000000

;*** PWM_OUTL PWM Output Control Register: Low
PWM_OUTL            equ       $00000046
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_OUTL_OUT0       equ       0
PWM_OUTL_OUT1       equ       1
PWM_OUTL_OUT2       equ       2
PWM_OUTL_OUT3       equ       3
PWM_OUTL_OUT4       equ       4
PWM_OUTL_OUT5       equ       5
; bit position masks
mPWM_OUTL_OUT0      equ       %00000001
mPWM_OUTL_OUT1      equ       %00000010
mPWM_OUTL_OUT2      equ       %00000100
mPWM_OUTL_OUT3      equ       %00001000
mPWM_OUTL_OUT4      equ       %00010000
mPWM_OUTL_OUT5      equ       %00100000

;*** PWM_OUTH PWM Output Control Register: High
PWM_OUTH            equ       $00000047
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_OUTH_OUTCTL0    equ       0
PWM_OUTH_OUTCTL1    equ       1
PWM_OUTH_OUTCTL2    equ       2
PWM_OUTH_OUTCTL3    equ       3
PWM_OUTH_OUTCTL4    equ       4
PWM_OUTH_OUTCTL5    equ       5
PWM_OUTH_PADEN      equ       7
; bit position masks
mPWM_OUTH_OUTCTL0   equ       %00000001
mPWM_OUTH_OUTCTL1   equ       %00000010
mPWM_OUTH_OUTCTL2   equ       %00000100
mPWM_OUTH_OUTCTL3   equ       %00001000
mPWM_OUTH_OUTCTL4   equ       %00010000
mPWM_OUTH_OUTCTL5   equ       %00100000
mPWM_OUTH_PADEN     equ       %10000000

;*** PWM_CNTRL PWM Counter Register: Low
PWM_CNTRL           equ       $00000048

;*** PWM_CNTRH PWM Counter Register: High
PWM_CNTRH           equ       $00000049
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CNTRH_CNTR14_80 equ       0
PWM_CNTRH_CNTR14_81 equ       1
PWM_CNTRH_CNTR14_82 equ       2
PWM_CNTRH_CNTR14_83 equ       3
PWM_CNTRH_CNTR14_84 equ       4
PWM_CNTRH_CNTR14_85 equ       5
PWM_CNTRH_CNTR14_86 equ       6
; bit position masks
mPWM_CNTRH_CNTR14_80 equ       %00000001
mPWM_CNTRH_CNTR14_81 equ       %00000010
mPWM_CNTRH_CNTR14_82 equ       %00000100
mPWM_CNTRH_CNTR14_83 equ       %00001000
mPWM_CNTRH_CNTR14_84 equ       %00010000
mPWM_CNTRH_CNTR14_85 equ       %00100000
mPWM_CNTRH_CNTR14_86 equ       %01000000

;*** PWM_CMODL PWM Counter Register: Low
PWM_CMODL           equ       $0000004A

;*** PWM_CMODH PWM Counter Register: High
PWM_CMODH           equ       $0000004B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CMODH_CMOD14_80 equ       0
PWM_CMODH_CMOD14_81 equ       1
PWM_CMODH_CMOD14_82 equ       2
PWM_CMODH_CMOD14_83 equ       3
PWM_CMODH_CMOD14_84 equ       4
PWM_CMODH_CMOD14_85 equ       5
PWM_CMODH_CMOD14_86 equ       6
; bit position masks
mPWM_CMODH_CMOD14_80 equ       %00000001
mPWM_CMODH_CMOD14_81 equ       %00000010
mPWM_CMODH_CMOD14_82 equ       %00000100
mPWM_CMODH_CMOD14_83 equ       %00001000
mPWM_CMODH_CMOD14_84 equ       %00010000
mPWM_CMODH_CMOD14_85 equ       %00100000
mPWM_CMODH_CMOD14_86 equ       %01000000

;*** PWM_VAL0L PWM Value Register: Low
PWM_VAL0L           equ       $0000004C

;*** PWM_VAL0H PWM Value Register: High
PWM_VAL0H           equ       $0000004D

;*** PWM_VAL1L PWM Value Register: Low
PWM_VAL1L           equ       $0000004E

;*** PWM_VAL1H PWM Value Register: High
PWM_VAL1H           equ       $0000004F

;*** PWM_VAL2L PWM Value Register: Low
PWM_VAL2L           equ       $00000050

;*** PWM_VAL2H PWM Value Register: High
PWM_VAL2H           equ       $00000051

;*** PWM_VAL3L PWM Value Register: Low
PWM_VAL3L           equ       $00000052

;*** PWM_VAL3H PWM Value Register: High
PWM_VAL3H           equ       $00000053

;*** PWM_VAL4L PWM Value Register: Low
PWM_VAL4L           equ       $00000054

;*** PWM_VAL4H PWM Value Register: High
PWM_VAL4H           equ       $00000055

;*** PWM_VAL5L PWM Value Register: Low
PWM_VAL5L           equ       $00000056

;*** PWM_VAL5H PWM Value Register: High
PWM_VAL5H           equ       $00000057

;*** PWM_DTIM0L PWM Deadtime Register: Low
PWM_DTIM0L          equ       $00000058

;*** PWM_DTIM0H PWM Deadtime Register: High
PWM_DTIM0H          equ       $00000059
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_DTIM0H_PWMDT11_80 equ       0
PWM_DTIM0H_PWMDT11_81 equ       1
PWM_DTIM0H_PWMDT11_82 equ       2
PWM_DTIM0H_PWMDT11_83 equ       3
; bit position masks
mPWM_DTIM0H_PWMDT11_80 equ       %00000001
mPWM_DTIM0H_PWMDT11_81 equ       %00000010
mPWM_DTIM0H_PWMDT11_82 equ       %00000100
mPWM_DTIM0H_PWMDT11_83 equ       %00001000

;*** PWM_DTIM1L PWM Deadtime Register: Low
PWM_DTIM1L          equ       $0000005A

;*** PWM_DTIM1H PWM Deadtime Register: High
PWM_DTIM1H          equ       $0000005B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_DTIM1H_PWMDT11_80 equ       0
PWM_DTIM1H_PWMDT11_81 equ       1
PWM_DTIM1H_PWMDT11_82 equ       2
PWM_DTIM1H_PWMDT11_83 equ       3
; bit position masks
mPWM_DTIM1H_PWMDT11_80 equ       %00000001
mPWM_DTIM1H_PWMDT11_81 equ       %00000010
mPWM_DTIM1H_PWMDT11_82 equ       %00000100
mPWM_DTIM1H_PWMDT11_83 equ       %00001000

;*** PWM_DMAP1L PWM Disable Mapping Registers 1: Low
PWM_DMAP1L          equ       $0000005C

;*** PWM_DMAP1H PWM Disable Mapping Registers 1: High
PWM_DMAP1H          equ       $0000005D

;*** PWM_DMAP2L PWM Disable Mapping Registers 2: Low
PWM_DMAP2L          equ       $0000005E

;*** PWM_CNFGL PWM Configure Register: Low
PWM_CNFGL           equ       $00001820
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CNFGL_WP        equ       0
PWM_CNFGL_INDEP0    equ       1
PWM_CNFGL_INDEP1    equ       2
PWM_CNFGL_INDEP2    equ       3
PWM_CNFGL_BOTNEG0   equ       4
PWM_CNFGL_BOTNEG1   equ       5
PWM_CNFGL_BOTNEG2   equ       6
; bit position masks
mPWM_CNFGL_WP       equ       %00000001
mPWM_CNFGL_INDEP0   equ       %00000010
mPWM_CNFGL_INDEP1   equ       %00000100
mPWM_CNFGL_INDEP2   equ       %00001000
mPWM_CNFGL_BOTNEG0  equ       %00010000
mPWM_CNFGL_BOTNEG1  equ       %00100000
mPWM_CNFGL_BOTNEG2  equ       %01000000

;*** PWM_CNFGH PWM Configure Register: High
PWM_CNFGH           equ       $00001821
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CNFGH_TOPNEG0   equ       0
PWM_CNFGH_TOPNEG1   equ       1
PWM_CNFGH_TOPNEG2   equ       2
PWM_CNFGH_EDG       equ       4
PWM_CNFGH_WAITEN    equ       5
PWM_CNFGH_DBGEN     equ       6
; bit position masks
mPWM_CNFGH_TOPNEG0  equ       %00000001
mPWM_CNFGH_TOPNEG1  equ       %00000010
mPWM_CNFGH_TOPNEG2  equ       %00000100
mPWM_CNFGH_EDG      equ       %00010000
mPWM_CNFGH_WAITEN   equ       %00100000
mPWM_CNFGH_DBGEN    equ       %01000000

;*** PWM_CCTRLL PWM Channel Control Register: Low
PWM_CCTRLL          equ       $00001822
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CCTRLL_SWP01    equ       0
PWM_CCTRLL_SWP23    equ       1
PWM_CCTRLL_SWP45    equ       2
PWM_CCTRLL_VLMODE0  equ       4
PWM_CCTRLL_VLMODE1  equ       5
; bit position masks
mPWM_CCTRLL_SWP01   equ       %00000001
mPWM_CCTRLL_SWP23   equ       %00000010
mPWM_CCTRLL_SWP45   equ       %00000100
mPWM_CCTRLL_VLMODE0 equ       %00010000
mPWM_CCTRLL_VLMODE1 equ       %00100000

;*** PWM_CCTRLH PWM Channel Control Register: High
PWM_CCTRLH          equ       $00001823
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CCTRLH_MSK0     equ       0
PWM_CCTRLH_MSK1     equ       1
PWM_CCTRLH_MSK2     equ       2
PWM_CCTRLH_MSK3     equ       3
PWM_CCTRLH_MSK4     equ       4
PWM_CCTRLH_MSK5     equ       5
PWM_CCTRLH_ENHA     equ       7
; bit position masks
mPWM_CCTRLH_MSK0    equ       %00000001
mPWM_CCTRLH_MSK1    equ       %00000010
mPWM_CCTRLH_MSK2    equ       %00000100
mPWM_CCTRLH_MSK3    equ       %00001000
mPWM_CCTRLH_MSK4    equ       %00010000
mPWM_CCTRLH_MSK5    equ       %00100000
mPWM_CCTRLH_ENHA    equ       %10000000

;*** PWM_PECTRLL PWM Pulse Edge Control Register: Low
PWM_PECTRLL         equ       $00001826
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_PECTRLL_PEC0    equ       3
PWM_PECTRLL_PEC1    equ       4
PWM_PECTRLL_PEC2    equ       5
; bit position masks
mPWM_PECTRLL_PEC0   equ       %00001000
mPWM_PECTRLL_PEC1   equ       %00010000
mPWM_PECTRLL_PEC2   equ       %00100000

;*** PWM_CINVH PWM Compare Invert Register: High
PWM_CINVH           equ       $00001829
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWM_CINVH_CINV0     equ       0
PWM_CINVH_CINV1     equ       1
PWM_CINVH_CINV2     equ       2
PWM_CINVH_CINV3     equ       3
PWM_CINVH_CINV4     equ       4
PWM_CINVH_CINV5     equ       5
; bit position masks
mPWM_CINVH_CINV0    equ       %00000001
mPWM_CINVH_CINV1    equ       %00000010
mPWM_CINVH_CINV2    equ       %00000100
mPWM_CINVH_CINV3    equ       %00001000
mPWM_CINVH_CINV4    equ       %00010000
mPWM_CINVH_CINV5    equ       %00100000

;*** PWT0_CS Pulse Width Timer Control and Status Register
PWT0_CS             equ       $00000030
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWT0_CS_PWTOV       equ       0
PWT0_CS_PWTRDY      equ       1
PWT0_CS_FCTLE       equ       2
PWT0_CS_PWTSR       equ       3
PWT0_CS_POVIE       equ       4
PWT0_CS_PRDYIE      equ       5
PWT0_CS_PWTIE       equ       6
PWT0_CS_PWTEN       equ       7
; bit position masks
mPWT0_CS_PWTOV      equ       %00000001
mPWT0_CS_PWTRDY     equ       %00000010
mPWT0_CS_FCTLE      equ       %00000100
mPWT0_CS_PWTSR      equ       %00001000
mPWT0_CS_POVIE      equ       %00010000
mPWT0_CS_PRDYIE     equ       %00100000
mPWT0_CS_PWTIE      equ       %01000000
mPWT0_CS_PWTEN      equ       %10000000

;*** PWT0_CR Pulse Width Timer Control Register
PWT0_CR             equ       $00000031
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWT0_CR_PRE0        equ       0
PWT0_CR_PRE1        equ       1
PWT0_CR_PRE2        equ       2
PWT0_CR_LVL         equ       3
PWT0_CR_TGL         equ       4
PWT0_CR_PINSEL0     equ       5
PWT0_CR_PINSEL1     equ       6
PWT0_CR_PCLKS       equ       7
; bit position masks
mPWT0_CR_PRE0       equ       %00000001
mPWT0_CR_PRE1       equ       %00000010
mPWT0_CR_PRE2       equ       %00000100
mPWT0_CR_LVL        equ       %00001000
mPWT0_CR_TGL        equ       %00010000
mPWT0_CR_PINSEL0    equ       %00100000
mPWT0_CR_PINSEL1    equ       %01000000
mPWT0_CR_PCLKS      equ       %10000000

;*** PWT0_PPH Pulse Width Timer Positive Pulse Width Register: High
PWT0_PPH            equ       $00000032

;*** PWT0_PPL Pulse Width Timer Positive Pulse Width Register: Loq
PWT0_PPL            equ       $00000033

;*** PWT0_NPH Pulse Width Timer Negative Pulse Width Register: High
PWT0_NPH            equ       $00000034

;*** PWT0_NPL Pulse Width Timer Negative Pulse Width Register: Low
PWT0_NPL            equ       $00000035

;*** PWT0_CNTH Pulse Width Timer Counter Register: High
PWT0_CNTH           equ       $00000036

;*** PWT0_CNTL Pulse Width Timer Counter Register: Low
PWT0_CNTL           equ       $00000037

;*** PWT1_CS Pulse Width Timer Control and Status Register
PWT1_CS             equ       $00000038
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWT1_CS_PWTOV       equ       0
PWT1_CS_PWTRDY      equ       1
PWT1_CS_FCTLE       equ       2
PWT1_CS_PWTSR       equ       3
PWT1_CS_POVIE       equ       4
PWT1_CS_PRDYIE      equ       5
PWT1_CS_PWTIE       equ       6
PWT1_CS_PWTEN       equ       7
; bit position masks
mPWT1_CS_PWTOV      equ       %00000001
mPWT1_CS_PWTRDY     equ       %00000010
mPWT1_CS_FCTLE      equ       %00000100
mPWT1_CS_PWTSR      equ       %00001000
mPWT1_CS_POVIE      equ       %00010000
mPWT1_CS_PRDYIE     equ       %00100000
mPWT1_CS_PWTIE      equ       %01000000
mPWT1_CS_PWTEN      equ       %10000000

;*** PWT1_CR Pulse Width Timer Control Register
PWT1_CR             equ       $00000039
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PWT1_CR_PRE0        equ       0
PWT1_CR_PRE1        equ       1
PWT1_CR_PRE2        equ       2
PWT1_CR_LVL         equ       3
PWT1_CR_TGL         equ       4
PWT1_CR_PINSEL0     equ       5
PWT1_CR_PINSEL1     equ       6
PWT1_CR_PCLKS       equ       7
; bit position masks
mPWT1_CR_PRE0       equ       %00000001
mPWT1_CR_PRE1       equ       %00000010
mPWT1_CR_PRE2       equ       %00000100
mPWT1_CR_LVL        equ       %00001000
mPWT1_CR_TGL        equ       %00010000
mPWT1_CR_PINSEL0    equ       %00100000
mPWT1_CR_PINSEL1    equ       %01000000
mPWT1_CR_PCLKS      equ       %10000000

;*** PWT1_PPH Pulse Width Timer Positive Pulse Width Register: High
PWT1_PPH            equ       $0000003A

;*** PWT1_PPL Pulse Width Timer Positive Pulse Width Register: Loq
PWT1_PPL            equ       $0000003B

;*** PWT1_NPH Pulse Width Timer Negative Pulse Width Register: High
PWT1_NPH            equ       $0000003C

;*** PWT1_NPL Pulse Width Timer Negative Pulse Width Register: Low
PWT1_NPL            equ       $0000003D

;*** PWT1_CNTH Pulse Width Timer Counter Register: High
PWT1_CNTH           equ       $0000003E

;*** PWT1_CNTL Pulse Width Timer Counter Register: Low
PWT1_CNTL           equ       $0000003F

;*** SCI0_BDH SCI
SCI0_BDH            equ       $00001868
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
SCI0_BDL            equ       $00001869

;*** SCI0_C1 SCI
SCI0_C1             equ       $0000186A
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
SCI0_C2             equ       $0000186B
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
SCI0_S1             equ       $0000186C
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
SCI0_S2             equ       $0000186D
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
SCI0_C3             equ       $0000186E
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
SCI0_D              equ       $0000186F
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

;*** SIM_SRS System Reset Status Register
SIM_SRS             equ       $00001800
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SRS_FILA        equ       0
SIM_SRS_LVD         equ       1
SIM_SRS_LOC         equ       2
SIM_SRS_ILAD        equ       3
SIM_SRS_ILOP        equ       4
SIM_SRS_WCOP        equ       5
SIM_SRS_PIN         equ       6
SIM_SRS_POR         equ       7
; bit position masks
mSIM_SRS_FILA       equ       %00000001
mSIM_SRS_LVD        equ       %00000010
mSIM_SRS_LOC        equ       %00000100
mSIM_SRS_ILAD       equ       %00001000
mSIM_SRS_ILOP       equ       %00010000
mSIM_SRS_WCOP       equ       %00100000
mSIM_SRS_PIN        equ       %01000000
mSIM_SRS_POR        equ       %10000000

;*** SIM_SBDFR System Background Debug Force Reset Register
SIM_SBDFR           equ       $00001801
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SBDFR_BDFR      equ       0
; bit position masks
mSIM_SBDFR_BDFR     equ       %00000001

;*** SIM_SDIDH System Device Identification Register: High
SIM_SDIDH           equ       $00001802
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SDIDH_ID0       equ       0
SIM_SDIDH_ID1       equ       1
SIM_SDIDH_ID2       equ       2
SIM_SDIDH_ID3       equ       3
; bit position masks
mSIM_SDIDH_ID0      equ       %00000001
mSIM_SDIDH_ID1      equ       %00000010
mSIM_SDIDH_ID2      equ       %00000100
mSIM_SDIDH_ID3      equ       %00001000

;*** SIM_SDIDL System Device Identification Register: Low
SIM_SDIDL           equ       $00001803

;*** SIM_SOPT1 System Options Register 1
SIM_SOPT1           equ       $00001804
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SOPT1_STOPE     equ       0
SIM_SOPT1_FWAKE     equ       1
SIM_SOPT1_RANGE     equ       2
SIM_SOPT1_COPW      equ       3
SIM_SOPT1_COPCLKS0  equ       4
SIM_SOPT1_COPCLKS1  equ       5
SIM_SOPT1_COPT0     equ       6
SIM_SOPT1_COPT1     equ       7
; bit position masks
mSIM_SOPT1_STOPE    equ       %00000001
mSIM_SOPT1_FWAKE    equ       %00000010
mSIM_SOPT1_RANGE    equ       %00000100
mSIM_SOPT1_COPW     equ       %00001000
mSIM_SOPT1_COPCLKS0 equ       %00010000
mSIM_SOPT1_COPCLKS1 equ       %00100000
mSIM_SOPT1_COPT0    equ       %01000000
mSIM_SOPT1_COPT1    equ       %10000000

;*** SIM_SOPT2 System Options Register 2
SIM_SOPT2           equ       $00001805
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SOPT2_BUSREF0   equ       0
SIM_SOPT2_BUSREF1   equ       1
SIM_SOPT2_BUSREF2   equ       2
SIM_SOPT2_WPXB      equ       6
SIM_SOPT2_ESFC      equ       7
; bit position masks
mSIM_SOPT2_BUSREF0  equ       %00000001
mSIM_SOPT2_BUSREF1  equ       %00000010
mSIM_SOPT2_BUSREF2  equ       %00000100
mSIM_SOPT2_WPXB     equ       %01000000
mSIM_SOPT2_ESFC     equ       %10000000

;*** SIM_MUXPTAL System Port A Pin Multiplexing Control Register: Low
SIM_MUXPTAL         equ       $00001806
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_MUXPTAL_MUXPTA00 equ       0
SIM_MUXPTAL_MUXPTA01 equ       1
SIM_MUXPTAL_MUXPTA10 equ       2
SIM_MUXPTAL_MUXPTA11 equ       3
SIM_MUXPTAL_MUXPTA20 equ       4
SIM_MUXPTAL_MUXPTA21 equ       5
SIM_MUXPTAL_MUXPTA30 equ       6
SIM_MUXPTAL_MUXPTA31 equ       7
; bit position masks
mSIM_MUXPTAL_MUXPTA00 equ       %00000001
mSIM_MUXPTAL_MUXPTA01 equ       %00000010
mSIM_MUXPTAL_MUXPTA10 equ       %00000100
mSIM_MUXPTAL_MUXPTA11 equ       %00001000
mSIM_MUXPTAL_MUXPTA20 equ       %00010000
mSIM_MUXPTAL_MUXPTA21 equ       %00100000
mSIM_MUXPTAL_MUXPTA30 equ       %01000000
mSIM_MUXPTAL_MUXPTA31 equ       %10000000

;*** SIM_MUXPTAH System Port A Pin Multiplexing Control Register: High
SIM_MUXPTAH         equ       $00001807
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_MUXPTAH_MUXPTA40 equ       0
SIM_MUXPTAH_MUXPTA41 equ       1
SIM_MUXPTAH_MUXPTA50 equ       2
SIM_MUXPTAH_MUXPTA51 equ       3
SIM_MUXPTAH_MUXPTA60 equ       4
SIM_MUXPTAH_MUXPTA61 equ       5
SIM_MUXPTAH_MUXPTA70 equ       6
SIM_MUXPTAH_MUXPTA71 equ       7
; bit position masks
mSIM_MUXPTAH_MUXPTA40 equ       %00000001
mSIM_MUXPTAH_MUXPTA41 equ       %00000010
mSIM_MUXPTAH_MUXPTA50 equ       %00000100
mSIM_MUXPTAH_MUXPTA51 equ       %00001000
mSIM_MUXPTAH_MUXPTA60 equ       %00010000
mSIM_MUXPTAH_MUXPTA61 equ       %00100000
mSIM_MUXPTAH_MUXPTA70 equ       %01000000
mSIM_MUXPTAH_MUXPTA71 equ       %10000000

;*** SIM_MUXPTBL System Port B Pin Multiplexing Control Register: Low
SIM_MUXPTBL         equ       $00001808
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_MUXPTBL_MUXPTB00 equ       0
SIM_MUXPTBL_MUXPTB01 equ       1
SIM_MUXPTBL_MUXPTB10 equ       2
SIM_MUXPTBL_MUXPTB11 equ       3
SIM_MUXPTBL_MUXPTB20 equ       4
SIM_MUXPTBL_MUXPTB21 equ       5
SIM_MUXPTBL_MUXPTB30 equ       6
SIM_MUXPTBL_MUXPTB31 equ       7
; bit position masks
mSIM_MUXPTBL_MUXPTB00 equ       %00000001
mSIM_MUXPTBL_MUXPTB01 equ       %00000010
mSIM_MUXPTBL_MUXPTB10 equ       %00000100
mSIM_MUXPTBL_MUXPTB11 equ       %00001000
mSIM_MUXPTBL_MUXPTB20 equ       %00010000
mSIM_MUXPTBL_MUXPTB21 equ       %00100000
mSIM_MUXPTBL_MUXPTB30 equ       %01000000
mSIM_MUXPTBL_MUXPTB31 equ       %10000000

;*** SIM_MUXPTBH System Port B Pin Multiplexing Control Register: High
SIM_MUXPTBH         equ       $00001809
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_MUXPTBH_MUXPTB40 equ       0
SIM_MUXPTBH_MUXPTB41 equ       1
SIM_MUXPTBH_MUXPTB50 equ       2
SIM_MUXPTBH_MUXPTB51 equ       3
SIM_MUXPTBH_MUXPTB60 equ       4
SIM_MUXPTBH_MUXPTB61 equ       5
SIM_MUXPTBH_MUXPTB70 equ       6
SIM_MUXPTBH_MUXPTB71 equ       7
; bit position masks
mSIM_MUXPTBH_MUXPTB40 equ       %00000001
mSIM_MUXPTBH_MUXPTB41 equ       %00000010
mSIM_MUXPTBH_MUXPTB50 equ       %00000100
mSIM_MUXPTBH_MUXPTB51 equ       %00001000
mSIM_MUXPTBH_MUXPTB60 equ       %00010000
mSIM_MUXPTBH_MUXPTB61 equ       %00100000
mSIM_MUXPTBH_MUXPTB70 equ       %01000000
mSIM_MUXPTBH_MUXPTB71 equ       %10000000

;*** SIM_MUXPTCL System Port C Pin Multiplexing Control Register: Low
SIM_MUXPTCL         equ       $0000180A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_MUXPTCL_MUXPTC00 equ       0
SIM_MUXPTCL_MUXPTC01 equ       1
; bit position masks
mSIM_MUXPTCL_MUXPTC00 equ       %00000001
mSIM_MUXPTCL_MUXPTC01 equ       %00000010

;*** SIM_SCGC1 System Clock Gating Control 1 Register
SIM_SCGC1           equ       $0000180C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SCGC1_CRC       equ       2
SIM_SCGC1_IPC       equ       3
SIM_SCGC1_NVM       equ       4
SIM_SCGC1_DBG       equ       5
SIM_SCGC1_PMC       equ       6
; bit position masks
mSIM_SCGC1_CRC      equ       %00000100
mSIM_SCGC1_IPC      equ       %00001000
mSIM_SCGC1_NVM      equ       %00010000
mSIM_SCGC1_DBG      equ       %00100000
mSIM_SCGC1_PMC      equ       %01000000

;*** SIM_SCGC2 System Clock Gating Control 2 Register
SIM_SCGC2           equ       $0000180D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SCGC2_KBI       equ       0
SIM_SCGC2_PDB       equ       1
SIM_SCGC2_IRQ       equ       3
SIM_SCGC2_ADC0      equ       4
SIM_SCGC2_ADC1      equ       5
SIM_SCGC2_GDU_CMP   equ       6
SIM_SCGC2_CMP0      equ       7
; bit position masks
mSIM_SCGC2_KBI      equ       %00000001
mSIM_SCGC2_PDB      equ       %00000010
mSIM_SCGC2_IRQ      equ       %00001000
mSIM_SCGC2_ADC0     equ       %00010000
mSIM_SCGC2_ADC1     equ       %00100000
mSIM_SCGC2_GDU_CMP  equ       %01000000
mSIM_SCGC2_CMP0     equ       %10000000

;*** SIM_SCGC3 System Clock Gating Control 3 Register
SIM_SCGC3           equ       $0000180E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SCGC3_FTM       equ       1
SIM_SCGC3_SCI       equ       2
SIM_SCGC3_PWT0      equ       3
SIM_SCGC3_PWT1      equ       4
SIM_SCGC3_MTIM      equ       5
SIM_SCGC3_PWM       equ       6
SIM_SCGC3_I2C       equ       7
; bit position masks
mSIM_SCGC3_FTM      equ       %00000010
mSIM_SCGC3_SCI      equ       %00000100
mSIM_SCGC3_PWT0     equ       %00001000
mSIM_SCGC3_PWT1     equ       %00010000
mSIM_SCGC3_MTIM     equ       %00100000
mSIM_SCGC3_PWM      equ       %01000000
mSIM_SCGC3_I2C      equ       %10000000

;*** SIM_SCDIV System Clock Divider Register
SIM_SCDIV           equ       $0000180F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIM_SCDIV_DIV3      equ       0
SIM_SCDIV_DIV2      equ       2
SIM_SCDIV_DIV1      equ       5
; bit position masks
mSIM_SCDIV_DIV3     equ       %00000001
mSIM_SCDIV_DIV2     equ       %00000100
mSIM_SCDIV_DIV1     equ       %00100000

;*** SIM_PORREG0 System POR Register
SIM_PORREG0         equ       $00001810

;*** SIM_PORREG1 System POR Register
SIM_PORREG1         equ       $00001811

;*** SIM_PORREG2 System POR Register
SIM_PORREG2         equ       $00001812

;*** SIM_PORREG3 System POR Register
SIM_PORREG3         equ       $00001813

;*** SIM_PORREG4 System POR Register
SIM_PORREG4         equ       $00001814

;*** SIM_PORREG5 System POR Register
SIM_PORREG5         equ       $00001815

;*** SIM_PORREG6 System POR Register
SIM_PORREG6         equ       $00001816

;*** SIM_PORREG7 System POR Register
SIM_PORREG7         equ       $00001817

;*** SIM_ILLAH Illegal Address Register: High
SIM_ILLAH           equ       $00001880

;*** SIM_ILLAL Illegal Address Register: Low
SIM_ILLAL           equ       $00001881

;*** SIM_UUID0 Universally Unique Identifier Register 0
SIM_UUID0           equ       $000018F8

;*** SIM_UUID1 Universally Unique Identifier Register 1
SIM_UUID1           equ       $000018F9

;*** SIM_UUID2 Universally Unique Identifier Register 2
SIM_UUID2           equ       $000018FA

;*** SIM_UUID3 Universally Unique Identifier Register 3
SIM_UUID3           equ       $000018FB

;*** SIM_UUID4 Universally Unique Identifier Register 4
SIM_UUID4           equ       $000018FC

;*** SIM_UUID5 Universally Unique Identifier Register 5
SIM_UUID5           equ       $000018FD

;*** SIM_UUID6 Universally Unique Identifier Register 6
SIM_UUID6           equ       $000018FE

;*** SIM_UUID7 Universally Unique Identifier Register 7
SIM_UUID7           equ       $000018FF

;*** XBAR_EXTMUX External Mux Selection Register
XBAR_EXTMUX         equ       $00000006
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_EXTMUX_SEL0    equ       0
XBAR_EXTMUX_SEL1    equ       1
XBAR_EXTMUX_SEL2    equ       2
; bit position masks
mXBAR_EXTMUX_SEL0   equ       %00000001
mXBAR_EXTMUX_SEL1   equ       %00000010
mXBAR_EXTMUX_SEL2   equ       %00000100

;*** XBAR_SEL0 XBAR Selection Register
XBAR_SEL0           equ       $000018D0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL0_SEL0      equ       0
XBAR_SEL0_SEL1      equ       1
XBAR_SEL0_SEL2      equ       2
XBAR_SEL0_SEL3      equ       3
; bit position masks
mXBAR_SEL0_SEL0     equ       %00000001
mXBAR_SEL0_SEL1     equ       %00000010
mXBAR_SEL0_SEL2     equ       %00000100
mXBAR_SEL0_SEL3     equ       %00001000

;*** XBAR_SEL1 XBAR Selection Register
XBAR_SEL1           equ       $000018D1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL1_SEL0      equ       0
XBAR_SEL1_SEL1      equ       1
XBAR_SEL1_SEL2      equ       2
XBAR_SEL1_SEL3      equ       3
; bit position masks
mXBAR_SEL1_SEL0     equ       %00000001
mXBAR_SEL1_SEL1     equ       %00000010
mXBAR_SEL1_SEL2     equ       %00000100
mXBAR_SEL1_SEL3     equ       %00001000

;*** XBAR_SEL2 XBAR Selection Register
XBAR_SEL2           equ       $000018D2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL2_SEL0      equ       0
XBAR_SEL2_SEL1      equ       1
XBAR_SEL2_SEL2      equ       2
XBAR_SEL2_SEL3      equ       3
; bit position masks
mXBAR_SEL2_SEL0     equ       %00000001
mXBAR_SEL2_SEL1     equ       %00000010
mXBAR_SEL2_SEL2     equ       %00000100
mXBAR_SEL2_SEL3     equ       %00001000

;*** XBAR_SEL3 XBAR Selection Register
XBAR_SEL3           equ       $000018D3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL3_SEL0      equ       0
XBAR_SEL3_SEL1      equ       1
XBAR_SEL3_SEL2      equ       2
XBAR_SEL3_SEL3      equ       3
; bit position masks
mXBAR_SEL3_SEL0     equ       %00000001
mXBAR_SEL3_SEL1     equ       %00000010
mXBAR_SEL3_SEL2     equ       %00000100
mXBAR_SEL3_SEL3     equ       %00001000

;*** XBAR_SEL4 XBAR Selection Register
XBAR_SEL4           equ       $000018D4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL4_SEL0      equ       0
XBAR_SEL4_SEL1      equ       1
XBAR_SEL4_SEL2      equ       2
XBAR_SEL4_SEL3      equ       3
; bit position masks
mXBAR_SEL4_SEL0     equ       %00000001
mXBAR_SEL4_SEL1     equ       %00000010
mXBAR_SEL4_SEL2     equ       %00000100
mXBAR_SEL4_SEL3     equ       %00001000

;*** XBAR_SEL5 XBAR Selection Register
XBAR_SEL5           equ       $000018D5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL5_SEL0      equ       0
XBAR_SEL5_SEL1      equ       1
XBAR_SEL5_SEL2      equ       2
XBAR_SEL5_SEL3      equ       3
; bit position masks
mXBAR_SEL5_SEL0     equ       %00000001
mXBAR_SEL5_SEL1     equ       %00000010
mXBAR_SEL5_SEL2     equ       %00000100
mXBAR_SEL5_SEL3     equ       %00001000

;*** XBAR_SEL6 XBAR Selection Register
XBAR_SEL6           equ       $000018D6
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL6_SEL0      equ       0
XBAR_SEL6_SEL1      equ       1
XBAR_SEL6_SEL2      equ       2
XBAR_SEL6_SEL3      equ       3
; bit position masks
mXBAR_SEL6_SEL0     equ       %00000001
mXBAR_SEL6_SEL1     equ       %00000010
mXBAR_SEL6_SEL2     equ       %00000100
mXBAR_SEL6_SEL3     equ       %00001000

;*** XBAR_SEL7 XBAR Selection Register
XBAR_SEL7           equ       $000018D7
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL7_SEL0      equ       0
XBAR_SEL7_SEL1      equ       1
XBAR_SEL7_SEL2      equ       2
XBAR_SEL7_SEL3      equ       3
; bit position masks
mXBAR_SEL7_SEL0     equ       %00000001
mXBAR_SEL7_SEL1     equ       %00000010
mXBAR_SEL7_SEL2     equ       %00000100
mXBAR_SEL7_SEL3     equ       %00001000

;*** XBAR_SEL8 XBAR Selection Register
XBAR_SEL8           equ       $000018D8
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL8_SEL0      equ       0
XBAR_SEL8_SEL1      equ       1
XBAR_SEL8_SEL2      equ       2
XBAR_SEL8_SEL3      equ       3
; bit position masks
mXBAR_SEL8_SEL0     equ       %00000001
mXBAR_SEL8_SEL1     equ       %00000010
mXBAR_SEL8_SEL2     equ       %00000100
mXBAR_SEL8_SEL3     equ       %00001000

;*** XBAR_SEL9 XBAR Selection Register
XBAR_SEL9           equ       $000018D9
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL9_SEL0      equ       0
XBAR_SEL9_SEL1      equ       1
XBAR_SEL9_SEL2      equ       2
XBAR_SEL9_SEL3      equ       3
; bit position masks
mXBAR_SEL9_SEL0     equ       %00000001
mXBAR_SEL9_SEL1     equ       %00000010
mXBAR_SEL9_SEL2     equ       %00000100
mXBAR_SEL9_SEL3     equ       %00001000

;*** XBAR_SEL10 XBAR Selection Register
XBAR_SEL10          equ       $000018DA
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL10_SEL0     equ       0
XBAR_SEL10_SEL1     equ       1
XBAR_SEL10_SEL2     equ       2
XBAR_SEL10_SEL3     equ       3
; bit position masks
mXBAR_SEL10_SEL0    equ       %00000001
mXBAR_SEL10_SEL1    equ       %00000010
mXBAR_SEL10_SEL2    equ       %00000100
mXBAR_SEL10_SEL3    equ       %00001000

;*** XBAR_SEL11 XBAR Selection Register
XBAR_SEL11          equ       $000018DB
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL11_SEL0     equ       0
XBAR_SEL11_SEL1     equ       1
XBAR_SEL11_SEL2     equ       2
XBAR_SEL11_SEL3     equ       3
; bit position masks
mXBAR_SEL11_SEL0    equ       %00000001
mXBAR_SEL11_SEL1    equ       %00000010
mXBAR_SEL11_SEL2    equ       %00000100
mXBAR_SEL11_SEL3    equ       %00001000

;*** XBAR_SEL12 XBAR Selection Register
XBAR_SEL12          equ       $000018DC
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL12_SEL0     equ       0
XBAR_SEL12_SEL1     equ       1
XBAR_SEL12_SEL2     equ       2
XBAR_SEL12_SEL3     equ       3
; bit position masks
mXBAR_SEL12_SEL0    equ       %00000001
mXBAR_SEL12_SEL1    equ       %00000010
mXBAR_SEL12_SEL2    equ       %00000100
mXBAR_SEL12_SEL3    equ       %00001000

;*** XBAR_SEL13 XBAR Selection Register
XBAR_SEL13          equ       $000018DD
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL13_SEL0     equ       0
XBAR_SEL13_SEL1     equ       1
XBAR_SEL13_SEL2     equ       2
XBAR_SEL13_SEL3     equ       3
; bit position masks
mXBAR_SEL13_SEL0    equ       %00000001
mXBAR_SEL13_SEL1    equ       %00000010
mXBAR_SEL13_SEL2    equ       %00000100
mXBAR_SEL13_SEL3    equ       %00001000

;*** XBAR_SEL14 XBAR Selection Register
XBAR_SEL14          equ       $000018DE
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL14_SEL0     equ       0
XBAR_SEL14_SEL1     equ       1
XBAR_SEL14_SEL2     equ       2
XBAR_SEL14_SEL3     equ       3
; bit position masks
mXBAR_SEL14_SEL0    equ       %00000001
mXBAR_SEL14_SEL1    equ       %00000010
mXBAR_SEL14_SEL2    equ       %00000100
mXBAR_SEL14_SEL3    equ       %00001000

;*** XBAR_SEL15 XBAR Selection Register
XBAR_SEL15          equ       $000018DF
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
XBAR_SEL15_SEL0     equ       0
XBAR_SEL15_SEL1     equ       1
XBAR_SEL15_SEL2     equ       2
XBAR_SEL15_SEL3     equ       3
; bit position masks
mXBAR_SEL15_SEL0    equ       %00000001
mXBAR_SEL15_SEL1    equ       %00000010
mXBAR_SEL15_SEL2    equ       %00000100
mXBAR_SEL15_SEL3    equ       %00001000

;*** NV_FTRIM - Slow Internal Reference Clock Fine Trim
NV_FTRIM            equ       $0000FF6E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FTRIM_FTRIM      equ       0                   ; ICS_C4, bit 0
; bit position masks
mNV_FTRIM_FTRIM     equ       %00000001

;*** NV_ICSTRM - Slow Internal Reference Clock Trim Setting
NV_ICSTRM           equ       $0000FF6F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_ICSTRM_TRIM0     equ       0                   ; ICS_C3, bit 0
NV_ICSTRM_TRIM1     equ       1                   ; ICS_C3, bit 1
NV_ICSTRM_TRIM2     equ       2                   ; ICS_C3, bit 2
NV_ICSTRM_TRIM3     equ       3                   ; ICS_C3, bit 3
NV_ICSTRM_TRIM4     equ       4                   ; ICS_C3, bit 4
NV_ICSTRM_TRIM5     equ       5                   ; ICS_C3, bit 5
NV_ICSTRM_TRIM6     equ       6                   ; ICS_C3, bit 6
NV_ICSTRM_TRIM7     equ       7                   ; ICS_C3, bit 7
; bit position masks
mNV_ICSTRM_TRIM0    equ       %00000001
mNV_ICSTRM_TRIM1    equ       %00000010
mNV_ICSTRM_TRIM2    equ       %00000100
mNV_ICSTRM_TRIM3    equ       %00001000
mNV_ICSTRM_TRIM4    equ       %00010000
mNV_ICSTRM_TRIM5    equ       %00100000
mNV_ICSTRM_TRIM6    equ       %01000000
mNV_ICSTRM_TRIM7    equ       %10000000

;*** NV_BACKKEY0 - Back Door Key Register n
NV_BACKKEY0         equ       $0000FF70
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
NV_BACKKEY1         equ       $0000FF71
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
NV_BACKKEY2         equ       $0000FF72
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
NV_BACKKEY3         equ       $0000FF73
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
NV_BACKKEY4         equ       $0000FF74
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
NV_BACKKEY5         equ       $0000FF75
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
NV_BACKKEY6         equ       $0000FF76
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
NV_BACKKEY7         equ       $0000FF77
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
NV_FPROT            equ       $0000FF7C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NV_FPROT_FPH0       equ       3                   ; Flash Protection Higher Address Size, bit 0
NV_FPROT_FPH1       equ       4                   ; Flash Protection Higher Address Size, bit 1
NV_FPROT_FPHDIS     equ       5                   ; Flash Protection Higher Address Range Disable
NV_FPROT_FPOPEN     equ       7                   ; Flash Protection Operation Enable
; bit position masks
mNV_FPROT_FPH0      equ       %00001000
mNV_FPROT_FPH1      equ       %00010000
mNV_FPROT_FPHDIS    equ       %00100000
mNV_FPROT_FPOPEN    equ       %10000000

;*** NV_FOPT - Flash Option Register
NV_FOPT             equ       $0000FF7E
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
NV_FSEC             equ       $0000FF7F
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
