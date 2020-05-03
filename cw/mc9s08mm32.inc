;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08MM128_64, version 3.00.014 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08mm32.inc
;     Processor : MC9S08MM32VLH
;     FileFormat: V2.32
;     DataSheet : MC9S08MM128RM Rev. 3 07/2010
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 13:42
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;      - 22.4.2010, V3.00.0:
;              - Removed locations PPAGE_0_1Start, PPAGE_0_1End from the mc9s08mm64.inc.
;      - 25.6.2010, V3.00.1:
;              - Removed SOPT5 register from 0x180D. This location is reserved for internal testing.
;
;     File-Format-Revisions:
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
ROM_END             equ       $0000FF9D
RAM                 equ       $000000B0
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $000010AF
RAM1                equ       $00001920
RAM1_END            equ       $00001A1F
PPAGE_2Start        equ       $00028000
PPAGE_2End          equ       $0002BFFF
PPAGE_4Start        equ       $00048000
PPAGE_4End          equ       $00048FFF
;
Vsci2tx             equ       $0000FF9E
VReserved47         equ       $0000FFA0
VReserved46         equ       $0000FFA2
VReserved45         equ       $0000FFA4
VReserved44         equ       $0000FFA6
VReserved43         equ       $0000FFA8
VReserved42         equ       $0000FFAA
VReserved41         equ       $0000FFAC
VReserved40         equ       $0000FFAE
VReserved39         equ       $0000FFB0
VReserved38         equ       $0000FFB2
VReserved37         equ       $0000FFB4
VReserved36         equ       $0000FFB6
VReserved35         equ       $0000FFB8
VReserved34         equ       $0000FFBA
VReserved33         equ       $0000FFBC
VReserved32         equ       $0000FFBE
Vsci2rx             equ       $0000FFC0
Vsci2err            equ       $0000FFC2
Vtod                equ       $0000FFC4
Vkeyboard2          equ       $0000FFC6
Vkeyboard1          equ       $0000FFC8
Vpracmp             equ       $0000FFCA
Vadc                equ       $0000FFCC
Viic                equ       $0000FFCE
Vsci1tx             equ       $0000FFD0
Vsci1rx             equ       $0000FFD2
Vsci1err            equ       $0000FFD4
Vcmt                equ       $0000FFD6
Vspi2               equ       $0000FFD8
Vtpm2ovf            equ       $0000FFDA
Vtpm2ch3            equ       $0000FFDC
Vtpm2ch2            equ       $0000FFDE
Vtpm2ch1            equ       $0000FFE0
Vtpm2ch0            equ       $0000FFE2
Vtpm1ovf            equ       $0000FFE4
Vtpm1ch3            equ       $0000FFE6
Vtpm1ch2            equ       $0000FFE8
Vtpm1ch1            equ       $0000FFEA
Vtpm1ch0            equ       $0000FFEC
Vdac                equ       $0000FFEE
Vpdb                equ       $0000FFF0
Vusb                equ       $0000FFF2
Vspi1               equ       $0000FFF4
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
PTBDD               equ       $00000003           ;*** PTBDD - Port B Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0        equ       0                   ; Data Direction for Port B Bit 0
PTBDD_PTBDD1        equ       1                   ; Data Direction for Port B Bit 1
PTBDD_PTBDD2        equ       2                   ; Data Direction for Port B Bit 2
PTBDD_PTBDD3        equ       3                   ; Data Direction for Port B Bit 3
PTBDD_PTBDD4        equ       4                   ; Data Direction for Port B Bit 4
PTBDD_PTBDD5        equ       5                   ; Data Direction for Port B Bit 5
PTBDD_PTBDD6        equ       6                   ; Data Direction for Port B Bit 6
PTBDD_PTBDD7        equ       7                   ; Data Direction for Port B Bit 7
; bit position masks
mPTBDD_PTBDD0       equ       %00000001
mPTBDD_PTBDD1       equ       %00000010
mPTBDD_PTBDD2       equ       %00000100
mPTBDD_PTBDD3       equ       %00001000
mPTBDD_PTBDD4       equ       %00010000
mPTBDD_PTBDD5       equ       %00100000
mPTBDD_PTBDD6       equ       %01000000
mPTBDD_PTBDD7       equ       %10000000


;*** PTCD - Port C Data Register
PTCD                equ       $00000004           ;*** PTCD - Port C Data Register
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


;*** PTCDD - Port C Data Direction Register
PTCDD               equ       $00000005           ;*** PTCDD - Port C Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0        equ       0                   ; Data Direction for Port C Bit 0
PTCDD_PTCDD1        equ       1                   ; Data Direction for Port C Bit 1
PTCDD_PTCDD2        equ       2                   ; Data Direction for Port C Bit 2
PTCDD_PTCDD3        equ       3                   ; Data Direction for Port C Bit 3
PTCDD_PTCDD4        equ       4                   ; Data Direction for Port C Bit 4
PTCDD_PTCDD5        equ       5                   ; Data Direction for Port C Bit 5
PTCDD_PTCDD6        equ       6                   ; Data Direction for Port C Bit 6
PTCDD_PTCDD7        equ       7                   ; Data Direction for Port C Bit 7
; bit position masks
mPTCDD_PTCDD0       equ       %00000001
mPTCDD_PTCDD1       equ       %00000010
mPTCDD_PTCDD2       equ       %00000100
mPTCDD_PTCDD3       equ       %00001000
mPTCDD_PTCDD4       equ       %00010000
mPTCDD_PTCDD5       equ       %00100000
mPTCDD_PTCDD6       equ       %01000000
mPTCDD_PTCDD7       equ       %10000000


;*** PTDD - Port D Data Register
PTDD                equ       $00000006           ;*** PTDD - Port D Data Register
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
PTDDD               equ       $00000007           ;*** PTDDD - Port D Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0        equ       0                   ; Data Direction for Port D Bit 0
PTDDD_PTDDD1        equ       1                   ; Data Direction for Port D Bit 1
PTDDD_PTDDD2        equ       2                   ; Data Direction for Port D Bit 2
PTDDD_PTDDD3        equ       3                   ; Data Direction for Port D Bit 3
PTDDD_PTDDD4        equ       4                   ; Data Direction for Port D Bit 4
PTDDD_PTDDD5        equ       5                   ; Data Direction for Port D Bit 5
PTDDD_PTDDD6        equ       6                   ; Data Direction for Port D Bit 6
PTDDD_PTDDD7        equ       7                   ; Data Direction for Port D Bit 7
; bit position masks
mPTDDD_PTDDD0       equ       %00000001
mPTDDD_PTDDD1       equ       %00000010
mPTDDD_PTDDD2       equ       %00000100
mPTDDD_PTDDD3       equ       %00001000
mPTDDD_PTDDD4       equ       %00010000
mPTDDD_PTDDD5       equ       %00100000
mPTDDD_PTDDD6       equ       %01000000
mPTDDD_PTDDD7       equ       %10000000


;*** PPAGE - Program Page Register
PPAGE               equ       $00000008           ;*** PPAGE - Program Page Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPAGE_XA14          equ       0                   ; Extended address, bit 14
PPAGE_XA15          equ       1                   ; Extended address, bit 15
PPAGE_XA16          equ       2                   ; Extended address, bit 16
; bit position masks
mPPAGE_XA14         equ       %00000001
mPPAGE_XA15         equ       %00000010
mPPAGE_XA16         equ       %00000100


;*** LAP2 - Linear Address Pointer Register 2
LAP2                equ       $00000009           ;*** LAP2 - Linear Address Pointer Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP2_LA16           equ       0                   ; Linear address pointer, bit 16
; bit position masks
mLAP2_LA16          equ       %00000001


;*** LAP1 - Linear Address Pointer Register 1
LAP1                equ       $0000000A           ;*** LAP1 - Linear Address Pointer Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP1_LA8            equ       0                   ; Linear address pointer, bit 8
LAP1_LA9            equ       1                   ; Linear address pointer, bit 9
LAP1_LA10           equ       2                   ; Linear address pointer, bit 10
LAP1_LA11           equ       3                   ; Linear address pointer, bit 11
LAP1_LA12           equ       4                   ; Linear address pointer, bit 12
LAP1_LA13           equ       5                   ; Linear address pointer, bit 13
LAP1_LA14           equ       6                   ; Linear address pointer, bit 14
LAP1_LA15           equ       7                   ; Linear address pointer, bit 15
; bit position masks
mLAP1_LA8           equ       %00000001
mLAP1_LA9           equ       %00000010
mLAP1_LA10          equ       %00000100
mLAP1_LA11          equ       %00001000
mLAP1_LA12          equ       %00010000
mLAP1_LA13          equ       %00100000
mLAP1_LA14          equ       %01000000
mLAP1_LA15          equ       %10000000


;*** LAP0 - Linear Address Pointer Register 0
LAP0                equ       $0000000B           ;*** LAP0 - Linear Address Pointer Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP0_LA0            equ       0                   ; Linear address pointer, bit 0
LAP0_LA1            equ       1                   ; Linear address pointer, bit 1
LAP0_LA2            equ       2                   ; Linear address pointer, bit 2
LAP0_LA3            equ       3                   ; Linear address pointer, bit 3
LAP0_LA4            equ       4                   ; Linear address pointer, bit 4
LAP0_LA5            equ       5                   ; Linear address pointer, bit 5
LAP0_LA6            equ       6                   ; Linear address pointer, bit 6
LAP0_LA7            equ       7                   ; Linear address pointer, bit 7
; bit position masks
mLAP0_LA0           equ       %00000001
mLAP0_LA1           equ       %00000010
mLAP0_LA2           equ       %00000100
mLAP0_LA3           equ       %00001000
mLAP0_LA4           equ       %00010000
mLAP0_LA5           equ       %00100000
mLAP0_LA6           equ       %01000000
mLAP0_LA7           equ       %10000000


;*** LWP - Linear Word Post Increment Register
LWP                 equ       $0000000C           ;*** LWP - Linear Word Post Increment Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LWP_D0              equ       0                   ; Data value bit 0
LWP_D1              equ       1                   ; Data value bit 1
LWP_D2              equ       2                   ; Data value bit 2
LWP_D3              equ       3                   ; Data value bit 3
LWP_D4              equ       4                   ; Data value bit 4
LWP_D5              equ       5                   ; Data value bit 5
LWP_D6              equ       6                   ; Data value bit 6
LWP_D7              equ       7                   ; Data value bit 7
; bit position masks
mLWP_D0             equ       %00000001
mLWP_D1             equ       %00000010
mLWP_D2             equ       %00000100
mLWP_D3             equ       %00001000
mLWP_D4             equ       %00010000
mLWP_D5             equ       %00100000
mLWP_D6             equ       %01000000
mLWP_D7             equ       %10000000


;*** LBP - Linear Byte Post Increment Register
LBP                 equ       $0000000D           ;*** LBP - Linear Byte Post Increment Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LBP_D0              equ       0                   ; Data value bit 0
LBP_D1              equ       1                   ; Data value bit 1
LBP_D2              equ       2                   ; Data value bit 2
LBP_D3              equ       3                   ; Data value bit 3
LBP_D4              equ       4                   ; Data value bit 4
LBP_D5              equ       5                   ; Data value bit 5
LBP_D6              equ       6                   ; Data value bit 6
LBP_D7              equ       7                   ; Data value bit 7
; bit position masks
mLBP_D0             equ       %00000001
mLBP_D1             equ       %00000010
mLBP_D2             equ       %00000100
mLBP_D3             equ       %00001000
mLBP_D4             equ       %00010000
mLBP_D5             equ       %00100000
mLBP_D6             equ       %01000000
mLBP_D7             equ       %10000000


;*** LB - Linear Byte Register
LB                  equ       $0000000E           ;*** LB - Linear Byte Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LB_D0               equ       0                   ; Data value bit 0
LB_D1               equ       1                   ; Data value bit 1
LB_D2               equ       2                   ; Data value bit 2
LB_D3               equ       3                   ; Data value bit 3
LB_D4               equ       4                   ; Data value bit 4
LB_D5               equ       5                   ; Data value bit 5
LB_D6               equ       6                   ; Data value bit 6
LB_D7               equ       7                   ; Data value bit 7
; bit position masks
mLB_D0              equ       %00000001
mLB_D1              equ       %00000010
mLB_D2              equ       %00000100
mLB_D3              equ       %00001000
mLB_D4              equ       %00010000
mLB_D5              equ       %00100000
mLB_D6              equ       %01000000
mLB_D7              equ       %10000000


;*** LAPAB - Linear Address Pointer Add Byte Register
LAPAB               equ       $0000000F           ;*** LAPAB - Linear Address Pointer Add Byte Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAPAB_D0            equ       0                   ; Data value bit 0
LAPAB_D1            equ       1                   ; Data value bit 1
LAPAB_D2            equ       2                   ; Data value bit 2
LAPAB_D3            equ       3                   ; Data value bit 3
LAPAB_D4            equ       4                   ; Data value bit 4
LAPAB_D5            equ       5                   ; Data value bit 5
LAPAB_D6            equ       6                   ; Data value bit 6
LAPAB_D7            equ       7                   ; Data value bit 7
; bit position masks
mLAPAB_D0           equ       %00000001
mLAPAB_D1           equ       %00000010
mLAPAB_D2           equ       %00000100
mLAPAB_D3           equ       %00001000
mLAPAB_D4           equ       %00010000
mLAPAB_D5           equ       %00100000
mLAPAB_D6           equ       %01000000
mLAPAB_D7           equ       %10000000


;*** DACDAT0 - DAC Data 0 Register
DACDAT0             equ       $00000010           ;*** DACDAT0 - DAC Data 0 Register


;*** DACDAT0H - DAC Data 0 High Register
DACDAT0H            equ       $00000010           ;*** DACDAT0H - DAC Data 0 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT0H_DACDAT08   equ       0                   ; Buffer Data 0 High, bit 8
DACDAT0H_DACDAT09   equ       1                   ; Buffer Data 0 High, bit 9
DACDAT0H_DACDAT010  equ       2                   ; Buffer Data 0 High, bit 10
DACDAT0H_DACDAT011  equ       3                   ; Buffer Data 0 High, bit 11
; bit position masks
mDACDAT0H_DACDAT08  equ       %00000001
mDACDAT0H_DACDAT09  equ       %00000010
mDACDAT0H_DACDAT010 equ       %00000100
mDACDAT0H_DACDAT011 equ       %00001000


;*** DACDAT0L - DAC Data 0 Low Register
DACDAT0L            equ       $00000011           ;*** DACDAT0L - DAC Data 0 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT0L_DACDAT00   equ       0                   ; Buffer Data 0 Low, bit 0
DACDAT0L_DACDAT01   equ       1                   ; Buffer Data 0 Low, bit 1
DACDAT0L_DACDAT02   equ       2                   ; Buffer Data 0 Low, bit 2
DACDAT0L_DACDAT03   equ       3                   ; Buffer Data 0 Low, bit 3
DACDAT0L_DACDAT04   equ       4                   ; Buffer Data 0 Low, bit 4
DACDAT0L_DACDAT05   equ       5                   ; Buffer Data 0 Low, bit 5
DACDAT0L_DACDAT06   equ       6                   ; Buffer Data 0 Low, bit 6
DACDAT0L_DACDAT07   equ       7                   ; Buffer Data 0 Low, bit 7
; bit position masks
mDACDAT0L_DACDAT00  equ       %00000001
mDACDAT0L_DACDAT01  equ       %00000010
mDACDAT0L_DACDAT02  equ       %00000100
mDACDAT0L_DACDAT03  equ       %00001000
mDACDAT0L_DACDAT04  equ       %00010000
mDACDAT0L_DACDAT05  equ       %00100000
mDACDAT0L_DACDAT06  equ       %01000000
mDACDAT0L_DACDAT07  equ       %10000000


;*** DACDAT1 - DAC Data 1 Register
DACDAT1             equ       $00000012           ;*** DACDAT1 - DAC Data 1 Register


;*** DACDAT1H - DAC Data 1 High Register
DACDAT1H            equ       $00000012           ;*** DACDAT1H - DAC Data 1 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT1H_DACDAT18   equ       0                   ; Buffer Data 1 High, bit 8
DACDAT1H_DACDAT19   equ       1                   ; Buffer Data 1 High, bit 9
DACDAT1H_DACDAT110  equ       2                   ; Buffer Data 1 High, bit 10
DACDAT1H_DACDAT111  equ       3                   ; Buffer Data 1 High, bit 11
; bit position masks
mDACDAT1H_DACDAT18  equ       %00000001
mDACDAT1H_DACDAT19  equ       %00000010
mDACDAT1H_DACDAT110 equ       %00000100
mDACDAT1H_DACDAT111 equ       %00001000


;*** DACDAT1L - DAC Data 1 Low Register
DACDAT1L            equ       $00000013           ;*** DACDAT1L - DAC Data 1 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT1L_DACDAT10   equ       0                   ; Buffer Data 1 Low, bit 0
DACDAT1L_DACDAT11   equ       1                   ; Buffer Data 1 Low, bit 1
DACDAT1L_DACDAT12   equ       2                   ; Buffer Data 1 Low, bit 2
DACDAT1L_DACDAT13   equ       3                   ; Buffer Data 1 Low, bit 3
DACDAT1L_DACDAT14   equ       4                   ; Buffer Data 1 Low, bit 4
DACDAT1L_DACDAT15   equ       5                   ; Buffer Data 1 Low, bit 5
DACDAT1L_DACDAT16   equ       6                   ; Buffer Data 1 Low, bit 6
DACDAT1L_DACDAT17   equ       7                   ; Buffer Data 1 Low, bit 7
; bit position masks
mDACDAT1L_DACDAT10  equ       %00000001
mDACDAT1L_DACDAT11  equ       %00000010
mDACDAT1L_DACDAT12  equ       %00000100
mDACDAT1L_DACDAT13  equ       %00001000
mDACDAT1L_DACDAT14  equ       %00010000
mDACDAT1L_DACDAT15  equ       %00100000
mDACDAT1L_DACDAT16  equ       %01000000
mDACDAT1L_DACDAT17  equ       %10000000


;*** DACDAT2 - DAC Data 2 Register
DACDAT2             equ       $00000014           ;*** DACDAT2 - DAC Data 2 Register


;*** DACDAT2H - DAC Data 2 High Register
DACDAT2H            equ       $00000014           ;*** DACDAT2H - DAC Data 2 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT2H_DACDAT28   equ       0                   ; Buffer Data 2 High, bit 8
DACDAT2H_DACDAT29   equ       1                   ; Buffer Data 2 High, bit 9
DACDAT2H_DACDAT210  equ       2                   ; Buffer Data 2 High, bit 10
DACDAT2H_DACDAT211  equ       3                   ; Buffer Data 2 High, bit 11
; bit position masks
mDACDAT2H_DACDAT28  equ       %00000001
mDACDAT2H_DACDAT29  equ       %00000010
mDACDAT2H_DACDAT210 equ       %00000100
mDACDAT2H_DACDAT211 equ       %00001000


;*** DACDAT2L - DAC Data 2 Low Register
DACDAT2L            equ       $00000015           ;*** DACDAT2L - DAC Data 2 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT2L_DACDAT20   equ       0                   ; Buffer Data 2 Low, bit 0
DACDAT2L_DACDAT21   equ       1                   ; Buffer Data 2 Low, bit 1
DACDAT2L_DACDAT22   equ       2                   ; Buffer Data 2 Low, bit 2
DACDAT2L_DACDAT23   equ       3                   ; Buffer Data 2 Low, bit 3
DACDAT2L_DACDAT24   equ       4                   ; Buffer Data 2 Low, bit 4
DACDAT2L_DACDAT25   equ       5                   ; Buffer Data 2 Low, bit 5
DACDAT2L_DACDAT26   equ       6                   ; Buffer Data 2 Low, bit 6
DACDAT2L_DACDAT27   equ       7                   ; Buffer Data 2 Low, bit 7
; bit position masks
mDACDAT2L_DACDAT20  equ       %00000001
mDACDAT2L_DACDAT21  equ       %00000010
mDACDAT2L_DACDAT22  equ       %00000100
mDACDAT2L_DACDAT23  equ       %00001000
mDACDAT2L_DACDAT24  equ       %00010000
mDACDAT2L_DACDAT25  equ       %00100000
mDACDAT2L_DACDAT26  equ       %01000000
mDACDAT2L_DACDAT27  equ       %10000000


;*** DACDAT3 - DAC Data 3 Register
DACDAT3             equ       $00000016           ;*** DACDAT3 - DAC Data 3 Register


;*** DACDAT3H - DAC Data 3 High Register
DACDAT3H            equ       $00000016           ;*** DACDAT3H - DAC Data 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT3H_DACDAT38   equ       0                   ; Buffer Data 3 High, bit 8
DACDAT3H_DACDAT39   equ       1                   ; Buffer Data 3 High, bit 9
DACDAT3H_DACDAT310  equ       2                   ; Buffer Data 3 High, bit 10
DACDAT3H_DACDAT311  equ       3                   ; Buffer Data 3 High, bit 11
; bit position masks
mDACDAT3H_DACDAT38  equ       %00000001
mDACDAT3H_DACDAT39  equ       %00000010
mDACDAT3H_DACDAT310 equ       %00000100
mDACDAT3H_DACDAT311 equ       %00001000


;*** DACDAT3L - DAC Data 3 Low Register
DACDAT3L            equ       $00000017           ;*** DACDAT3L - DAC Data 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT3L_DACDAT30   equ       0                   ; Buffer Data 3 Low, bit 0
DACDAT3L_DACDAT31   equ       1                   ; Buffer Data 3 Low, bit 1
DACDAT3L_DACDAT32   equ       2                   ; Buffer Data 3 Low, bit 2
DACDAT3L_DACDAT33   equ       3                   ; Buffer Data 3 Low, bit 3
DACDAT3L_DACDAT34   equ       4                   ; Buffer Data 3 Low, bit 4
DACDAT3L_DACDAT35   equ       5                   ; Buffer Data 3 Low, bit 5
DACDAT3L_DACDAT36   equ       6                   ; Buffer Data 3 Low, bit 6
DACDAT3L_DACDAT37   equ       7                   ; Buffer Data 3 Low, bit 7
; bit position masks
mDACDAT3L_DACDAT30  equ       %00000001
mDACDAT3L_DACDAT31  equ       %00000010
mDACDAT3L_DACDAT32  equ       %00000100
mDACDAT3L_DACDAT33  equ       %00001000
mDACDAT3L_DACDAT34  equ       %00010000
mDACDAT3L_DACDAT35  equ       %00100000
mDACDAT3L_DACDAT36  equ       %01000000
mDACDAT3L_DACDAT37  equ       %10000000


;*** DACDAT4 - DAC Data 4 Register
DACDAT4             equ       $00000018           ;*** DACDAT4 - DAC Data 4 Register


;*** DACDAT4H - DAC Data 4 High Register
DACDAT4H            equ       $00000018           ;*** DACDAT4H - DAC Data 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT4H_DACDAT48   equ       0                   ; Buffer Data 4 High, bit 8
DACDAT4H_DACDAT49   equ       1                   ; Buffer Data 4 High, bit 9
DACDAT4H_DACDAT410  equ       2                   ; Buffer Data 4 High, bit 10
DACDAT4H_DACDAT411  equ       3                   ; Buffer Data 4 High, bit 11
; bit position masks
mDACDAT4H_DACDAT48  equ       %00000001
mDACDAT4H_DACDAT49  equ       %00000010
mDACDAT4H_DACDAT410 equ       %00000100
mDACDAT4H_DACDAT411 equ       %00001000


;*** DACDAT4L - DAC Data 4 Low Register
DACDAT4L            equ       $00000019           ;*** DACDAT4L - DAC Data 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT4L_DACDAT40   equ       0                   ; Buffer Data 4 Low, bit 0
DACDAT4L_DACDAT41   equ       1                   ; Buffer Data 4 Low, bit 1
DACDAT4L_DACDAT42   equ       2                   ; Buffer Data 4 Low, bit 2
DACDAT4L_DACDAT43   equ       3                   ; Buffer Data 4 Low, bit 3
DACDAT4L_DACDAT44   equ       4                   ; Buffer Data 4 Low, bit 4
DACDAT4L_DACDAT45   equ       5                   ; Buffer Data 4 Low, bit 5
DACDAT4L_DACDAT46   equ       6                   ; Buffer Data 4 Low, bit 6
DACDAT4L_DACDAT47   equ       7                   ; Buffer Data 4 Low, bit 7
; bit position masks
mDACDAT4L_DACDAT40  equ       %00000001
mDACDAT4L_DACDAT41  equ       %00000010
mDACDAT4L_DACDAT42  equ       %00000100
mDACDAT4L_DACDAT43  equ       %00001000
mDACDAT4L_DACDAT44  equ       %00010000
mDACDAT4L_DACDAT45  equ       %00100000
mDACDAT4L_DACDAT46  equ       %01000000
mDACDAT4L_DACDAT47  equ       %10000000


;*** DACDAT5 - DAC Data 5 Register
DACDAT5             equ       $0000001A           ;*** DACDAT5 - DAC Data 5 Register


;*** DACDAT5H - DAC Data 5 High Register
DACDAT5H            equ       $0000001A           ;*** DACDAT5H - DAC Data 5 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT5H_DACDAT58   equ       0                   ; Buffer Data 5 High, bit 8
DACDAT5H_DACDAT59   equ       1                   ; Buffer Data 5 High, bit 9
DACDAT5H_DACDAT510  equ       2                   ; Buffer Data 5 High, bit 10
DACDAT5H_DACDAT511  equ       3                   ; Buffer Data 5 High, bit 11
; bit position masks
mDACDAT5H_DACDAT58  equ       %00000001
mDACDAT5H_DACDAT59  equ       %00000010
mDACDAT5H_DACDAT510 equ       %00000100
mDACDAT5H_DACDAT511 equ       %00001000


;*** DACDAT5L - DAC Data 5 Low Register
DACDAT5L            equ       $0000001B           ;*** DACDAT5L - DAC Data 5 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT5L_DACDAT50   equ       0                   ; Buffer Data 5 Low, bit 0
DACDAT5L_DACDAT51   equ       1                   ; Buffer Data 5 Low, bit 1
DACDAT5L_DACDAT52   equ       2                   ; Buffer Data 5 Low, bit 2
DACDAT5L_DACDAT53   equ       3                   ; Buffer Data 5 Low, bit 3
DACDAT5L_DACDAT54   equ       4                   ; Buffer Data 5 Low, bit 4
DACDAT5L_DACDAT55   equ       5                   ; Buffer Data 5 Low, bit 5
DACDAT5L_DACDAT56   equ       6                   ; Buffer Data 5 Low, bit 6
DACDAT5L_DACDAT57   equ       7                   ; Buffer Data 5 Low, bit 7
; bit position masks
mDACDAT5L_DACDAT50  equ       %00000001
mDACDAT5L_DACDAT51  equ       %00000010
mDACDAT5L_DACDAT52  equ       %00000100
mDACDAT5L_DACDAT53  equ       %00001000
mDACDAT5L_DACDAT54  equ       %00010000
mDACDAT5L_DACDAT55  equ       %00100000
mDACDAT5L_DACDAT56  equ       %01000000
mDACDAT5L_DACDAT57  equ       %10000000


;*** DACDAT6 - DAC Data 6 Register
DACDAT6             equ       $0000001C           ;*** DACDAT6 - DAC Data 6 Register


;*** DACDAT6H - DAC Data 6 High Register
DACDAT6H            equ       $0000001C           ;*** DACDAT6H - DAC Data 6 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT6H_DACDAT68   equ       0                   ; Buffer Data 6 High, bit 8
DACDAT6H_DACDAT69   equ       1                   ; Buffer Data 6 High, bit 9
DACDAT6H_DACDAT610  equ       2                   ; Buffer Data 6 High, bit 10
DACDAT6H_DACDAT611  equ       3                   ; Buffer Data 6 High, bit 11
; bit position masks
mDACDAT6H_DACDAT68  equ       %00000001
mDACDAT6H_DACDAT69  equ       %00000010
mDACDAT6H_DACDAT610 equ       %00000100
mDACDAT6H_DACDAT611 equ       %00001000


;*** DACDAT6L - DAC Data 6 Low Register
DACDAT6L            equ       $0000001D           ;*** DACDAT6L - DAC Data 6 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT6L_DACDAT60   equ       0                   ; Buffer Data 6 Low, bit 0
DACDAT6L_DACDAT61   equ       1                   ; Buffer Data 6 Low, bit 1
DACDAT6L_DACDAT62   equ       2                   ; Buffer Data 6 Low, bit 2
DACDAT6L_DACDAT63   equ       3                   ; Buffer Data 6 Low, bit 3
DACDAT6L_DACDAT64   equ       4                   ; Buffer Data 6 Low, bit 4
DACDAT6L_DACDAT65   equ       5                   ; Buffer Data 6 Low, bit 5
DACDAT6L_DACDAT66   equ       6                   ; Buffer Data 6 Low, bit 6
DACDAT6L_DACDAT67   equ       7                   ; Buffer Data 6 Low, bit 7
; bit position masks
mDACDAT6L_DACDAT60  equ       %00000001
mDACDAT6L_DACDAT61  equ       %00000010
mDACDAT6L_DACDAT62  equ       %00000100
mDACDAT6L_DACDAT63  equ       %00001000
mDACDAT6L_DACDAT64  equ       %00010000
mDACDAT6L_DACDAT65  equ       %00100000
mDACDAT6L_DACDAT66  equ       %01000000
mDACDAT6L_DACDAT67  equ       %10000000


;*** DACDAT7 - DAC Data 7 Register
DACDAT7             equ       $0000001E           ;*** DACDAT7 - DAC Data 7 Register


;*** DACDAT7H - DAC Data 7 High Register
DACDAT7H            equ       $0000001E           ;*** DACDAT7H - DAC Data 7 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT7H_DACDAT78   equ       0                   ; Buffer Data 7 High, bit 8
DACDAT7H_DACDAT79   equ       1                   ; Buffer Data 7 High, bit 9
DACDAT7H_DACDAT710  equ       2                   ; Buffer Data 7 High, bit 10
DACDAT7H_DACDAT711  equ       3                   ; Buffer Data 7 High, bit 11
; bit position masks
mDACDAT7H_DACDAT78  equ       %00000001
mDACDAT7H_DACDAT79  equ       %00000010
mDACDAT7H_DACDAT710 equ       %00000100
mDACDAT7H_DACDAT711 equ       %00001000


;*** DACDAT7L - DAC Data 7 Low Register
DACDAT7L            equ       $0000001F           ;*** DACDAT7L - DAC Data 7 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT7L_DACDAT70   equ       0                   ; Buffer Data 7 Low, bit 0
DACDAT7L_DACDAT71   equ       1                   ; Buffer Data 7 Low, bit 1
DACDAT7L_DACDAT72   equ       2                   ; Buffer Data 7 Low, bit 2
DACDAT7L_DACDAT73   equ       3                   ; Buffer Data 7 Low, bit 3
DACDAT7L_DACDAT74   equ       4                   ; Buffer Data 7 Low, bit 4
DACDAT7L_DACDAT75   equ       5                   ; Buffer Data 7 Low, bit 5
DACDAT7L_DACDAT76   equ       6                   ; Buffer Data 7 Low, bit 6
DACDAT7L_DACDAT77   equ       7                   ; Buffer Data 7 Low, bit 7
; bit position masks
mDACDAT7L_DACDAT70  equ       %00000001
mDACDAT7L_DACDAT71  equ       %00000010
mDACDAT7L_DACDAT72  equ       %00000100
mDACDAT7L_DACDAT73  equ       %00001000
mDACDAT7L_DACDAT74  equ       %00010000
mDACDAT7L_DACDAT75  equ       %00100000
mDACDAT7L_DACDAT76  equ       %01000000
mDACDAT7L_DACDAT77  equ       %10000000


;*** DACDAT8 - DAC Data 8 Register
DACDAT8             equ       $00000020           ;*** DACDAT8 - DAC Data 8 Register


;*** DACDAT8H - DAC Data 8 High Register
DACDAT8H            equ       $00000020           ;*** DACDAT8H - DAC Data 8 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT8H_DACDAT88   equ       0                   ; Buffer Data 8 High, bit 8
DACDAT8H_DACDAT89   equ       1                   ; Buffer Data 8 High, bit 9
DACDAT8H_DACDAT810  equ       2                   ; Buffer Data 8 High, bit 10
DACDAT8H_DACDAT811  equ       3                   ; Buffer Data 8 High, bit 11
; bit position masks
mDACDAT8H_DACDAT88  equ       %00000001
mDACDAT8H_DACDAT89  equ       %00000010
mDACDAT8H_DACDAT810 equ       %00000100
mDACDAT8H_DACDAT811 equ       %00001000


;*** DACDAT8L - DAC Data 8 Low Register
DACDAT8L            equ       $00000021           ;*** DACDAT8L - DAC Data 8 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT8L_DACDAT80   equ       0                   ; Buffer Data 8 Low, bit 0
DACDAT8L_DACDAT81   equ       1                   ; Buffer Data 8 Low, bit 1
DACDAT8L_DACDAT82   equ       2                   ; Buffer Data 8 Low, bit 2
DACDAT8L_DACDAT83   equ       3                   ; Buffer Data 8 Low, bit 3
DACDAT8L_DACDAT84   equ       4                   ; Buffer Data 8 Low, bit 4
DACDAT8L_DACDAT85   equ       5                   ; Buffer Data 8 Low, bit 5
DACDAT8L_DACDAT86   equ       6                   ; Buffer Data 8 Low, bit 6
DACDAT8L_DACDAT87   equ       7                   ; Buffer Data 8 Low, bit 7
; bit position masks
mDACDAT8L_DACDAT80  equ       %00000001
mDACDAT8L_DACDAT81  equ       %00000010
mDACDAT8L_DACDAT82  equ       %00000100
mDACDAT8L_DACDAT83  equ       %00001000
mDACDAT8L_DACDAT84  equ       %00010000
mDACDAT8L_DACDAT85  equ       %00100000
mDACDAT8L_DACDAT86  equ       %01000000
mDACDAT8L_DACDAT87  equ       %10000000


;*** DACDAT9 - DAC Data 9 Register
DACDAT9             equ       $00000022           ;*** DACDAT9 - DAC Data 9 Register


;*** DACDAT9H - DAC Data 9 High Register
DACDAT9H            equ       $00000022           ;*** DACDAT9H - DAC Data 9 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT9H_DACDAT98   equ       0                   ; Buffer Data 9 High, bit 8
DACDAT9H_DACDAT99   equ       1                   ; Buffer Data 9 High, bit 9
DACDAT9H_DACDAT910  equ       2                   ; Buffer Data 9 High, bit 10
DACDAT9H_DACDAT911  equ       3                   ; Buffer Data 9 High, bit 11
; bit position masks
mDACDAT9H_DACDAT98  equ       %00000001
mDACDAT9H_DACDAT99  equ       %00000010
mDACDAT9H_DACDAT910 equ       %00000100
mDACDAT9H_DACDAT911 equ       %00001000


;*** DACDAT9L - DAC Data 9 Low Register
DACDAT9L            equ       $00000023           ;*** DACDAT9L - DAC Data 9 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT9L_DACDAT90   equ       0                   ; Buffer Data 9 Low, bit 0
DACDAT9L_DACDAT91   equ       1                   ; Buffer Data 9 Low, bit 1
DACDAT9L_DACDAT92   equ       2                   ; Buffer Data 9 Low, bit 2
DACDAT9L_DACDAT93   equ       3                   ; Buffer Data 9 Low, bit 3
DACDAT9L_DACDAT94   equ       4                   ; Buffer Data 9 Low, bit 4
DACDAT9L_DACDAT95   equ       5                   ; Buffer Data 9 Low, bit 5
DACDAT9L_DACDAT96   equ       6                   ; Buffer Data 9 Low, bit 6
DACDAT9L_DACDAT97   equ       7                   ; Buffer Data 9 Low, bit 7
; bit position masks
mDACDAT9L_DACDAT90  equ       %00000001
mDACDAT9L_DACDAT91  equ       %00000010
mDACDAT9L_DACDAT92  equ       %00000100
mDACDAT9L_DACDAT93  equ       %00001000
mDACDAT9L_DACDAT94  equ       %00010000
mDACDAT9L_DACDAT95  equ       %00100000
mDACDAT9L_DACDAT96  equ       %01000000
mDACDAT9L_DACDAT97  equ       %10000000


;*** DACDAT10 - DAC Data 10 Register
DACDAT10            equ       $00000024           ;*** DACDAT10 - DAC Data 10 Register


;*** DACDAT10H - DAC Data 10 High Register
DACDAT10H           equ       $00000024           ;*** DACDAT10H - DAC Data 10 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT10H_DACDAT108 equ       0                   ; Buffer Data 10 High, bit 8
DACDAT10H_DACDAT109 equ       1                   ; Buffer Data 10 High, bit 9
DACDAT10H_DACDAT1010 equ       2                   ; Buffer Data 10 High, bit 10
DACDAT10H_DACDAT1011 equ       3                   ; Buffer Data 10 High, bit 11
; bit position masks
mDACDAT10H_DACDAT108 equ       %00000001
mDACDAT10H_DACDAT109 equ       %00000010
mDACDAT10H_DACDAT1010 equ       %00000100
mDACDAT10H_DACDAT1011 equ       %00001000


;*** DACDAT10L - DAC Data 10 Low Register
DACDAT10L           equ       $00000025           ;*** DACDAT10L - DAC Data 10 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT10L_DACDAT100 equ       0                   ; Buffer Data 10 Low, bit 0
DACDAT10L_DACDAT101 equ       1                   ; Buffer Data 10 Low, bit 1
DACDAT10L_DACDAT102 equ       2                   ; Buffer Data 10 Low, bit 2
DACDAT10L_DACDAT103 equ       3                   ; Buffer Data 10 Low, bit 3
DACDAT10L_DACDAT104 equ       4                   ; Buffer Data 10 Low, bit 4
DACDAT10L_DACDAT105 equ       5                   ; Buffer Data 10 Low, bit 5
DACDAT10L_DACDAT106 equ       6                   ; Buffer Data 10 Low, bit 6
DACDAT10L_DACDAT107 equ       7                   ; Buffer Data 10 Low, bit 7
; bit position masks
mDACDAT10L_DACDAT100 equ       %00000001
mDACDAT10L_DACDAT101 equ       %00000010
mDACDAT10L_DACDAT102 equ       %00000100
mDACDAT10L_DACDAT103 equ       %00001000
mDACDAT10L_DACDAT104 equ       %00010000
mDACDAT10L_DACDAT105 equ       %00100000
mDACDAT10L_DACDAT106 equ       %01000000
mDACDAT10L_DACDAT107 equ       %10000000


;*** DACDAT11 - DAC Data 11 Register
DACDAT11            equ       $00000026           ;*** DACDAT11 - DAC Data 11 Register


;*** DACDAT11H - DAC Data 11 High Register
DACDAT11H           equ       $00000026           ;*** DACDAT11H - DAC Data 11 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT11H_DACDAT118 equ       0                   ; Buffer Data 11 High, bit 8
DACDAT11H_DACDAT119 equ       1                   ; Buffer Data 11 High, bit 9
DACDAT11H_DACDAT1110 equ       2                   ; Buffer Data 11 High, bit 10
DACDAT11H_DACDAT1111 equ       3                   ; Buffer Data 11 High, bit 11
; bit position masks
mDACDAT11H_DACDAT118 equ       %00000001
mDACDAT11H_DACDAT119 equ       %00000010
mDACDAT11H_DACDAT1110 equ       %00000100
mDACDAT11H_DACDAT1111 equ       %00001000


;*** DACDAT11L - DAC Data 11 Low Register
DACDAT11L           equ       $00000027           ;*** DACDAT11L - DAC Data 11 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT11L_DACDAT110 equ       0                   ; Buffer Data 11 Low, bit 0
DACDAT11L_DACDAT111 equ       1                   ; Buffer Data 11 Low, bit 1
DACDAT11L_DACDAT112 equ       2                   ; Buffer Data 11 Low, bit 2
DACDAT11L_DACDAT113 equ       3                   ; Buffer Data 11 Low, bit 3
DACDAT11L_DACDAT114 equ       4                   ; Buffer Data 11 Low, bit 4
DACDAT11L_DACDAT115 equ       5                   ; Buffer Data 11 Low, bit 5
DACDAT11L_DACDAT116 equ       6                   ; Buffer Data 11 Low, bit 6
DACDAT11L_DACDAT117 equ       7                   ; Buffer Data 11 Low, bit 7
; bit position masks
mDACDAT11L_DACDAT110 equ       %00000001
mDACDAT11L_DACDAT111 equ       %00000010
mDACDAT11L_DACDAT112 equ       %00000100
mDACDAT11L_DACDAT113 equ       %00001000
mDACDAT11L_DACDAT114 equ       %00010000
mDACDAT11L_DACDAT115 equ       %00100000
mDACDAT11L_DACDAT116 equ       %01000000
mDACDAT11L_DACDAT117 equ       %10000000


;*** DACDAT12 - DAC Data 12 Register
DACDAT12            equ       $00000028           ;*** DACDAT12 - DAC Data 12 Register


;*** DACDAT12H - DAC Data 12 High Register
DACDAT12H           equ       $00000028           ;*** DACDAT12H - DAC Data 12 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT12H_DACDAT128 equ       0                   ; Buffer Data 12 High, bit 8
DACDAT12H_DACDAT129 equ       1                   ; Buffer Data 12 High, bit 9
DACDAT12H_DACDAT1210 equ       2                   ; Buffer Data 12 High, bit 10
DACDAT12H_DACDAT1211 equ       3                   ; Buffer Data 12 High, bit 11
; bit position masks
mDACDAT12H_DACDAT128 equ       %00000001
mDACDAT12H_DACDAT129 equ       %00000010
mDACDAT12H_DACDAT1210 equ       %00000100
mDACDAT12H_DACDAT1211 equ       %00001000


;*** DACDAT12L - DAC Data 12 Low Register
DACDAT12L           equ       $00000029           ;*** DACDAT12L - DAC Data 12 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT12L_DACDAT120 equ       0                   ; Buffer Data 12 Low, bit 0
DACDAT12L_DACDAT121 equ       1                   ; Buffer Data 12 Low, bit 1
DACDAT12L_DACDAT122 equ       2                   ; Buffer Data 12 Low, bit 2
DACDAT12L_DACDAT123 equ       3                   ; Buffer Data 12 Low, bit 3
DACDAT12L_DACDAT124 equ       4                   ; Buffer Data 12 Low, bit 4
DACDAT12L_DACDAT125 equ       5                   ; Buffer Data 12 Low, bit 5
DACDAT12L_DACDAT126 equ       6                   ; Buffer Data 12 Low, bit 6
DACDAT12L_DACDAT127 equ       7                   ; Buffer Data 12 Low, bit 7
; bit position masks
mDACDAT12L_DACDAT120 equ       %00000001
mDACDAT12L_DACDAT121 equ       %00000010
mDACDAT12L_DACDAT122 equ       %00000100
mDACDAT12L_DACDAT123 equ       %00001000
mDACDAT12L_DACDAT124 equ       %00010000
mDACDAT12L_DACDAT125 equ       %00100000
mDACDAT12L_DACDAT126 equ       %01000000
mDACDAT12L_DACDAT127 equ       %10000000


;*** DACDAT13 - DAC Data 13 Register
DACDAT13            equ       $0000002A           ;*** DACDAT13 - DAC Data 13 Register


;*** DACDAT13H - DAC Data 13 High Register
DACDAT13H           equ       $0000002A           ;*** DACDAT13H - DAC Data 13 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT13H_DACDAT138 equ       0                   ; Buffer Data 13 High, bit 8
DACDAT13H_DACDAT139 equ       1                   ; Buffer Data 13 High, bit 9
DACDAT13H_DACDAT1310 equ       2                   ; Buffer Data 13 High, bit 10
DACDAT13H_DACDAT1311 equ       3                   ; Buffer Data 13 High, bit 11
; bit position masks
mDACDAT13H_DACDAT138 equ       %00000001
mDACDAT13H_DACDAT139 equ       %00000010
mDACDAT13H_DACDAT1310 equ       %00000100
mDACDAT13H_DACDAT1311 equ       %00001000


;*** DACDAT13L - DAC Data 13 Low Register
DACDAT13L           equ       $0000002B           ;*** DACDAT13L - DAC Data 13 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT13L_DACDAT130 equ       0                   ; Buffer Data 13 Low, bit 0
DACDAT13L_DACDAT131 equ       1                   ; Buffer Data 13 Low, bit 1
DACDAT13L_DACDAT132 equ       2                   ; Buffer Data 13 Low, bit 2
DACDAT13L_DACDAT133 equ       3                   ; Buffer Data 13 Low, bit 3
DACDAT13L_DACDAT134 equ       4                   ; Buffer Data 13 Low, bit 4
DACDAT13L_DACDAT135 equ       5                   ; Buffer Data 13 Low, bit 5
DACDAT13L_DACDAT136 equ       6                   ; Buffer Data 13 Low, bit 6
DACDAT13L_DACDAT137 equ       7                   ; Buffer Data 13 Low, bit 7
; bit position masks
mDACDAT13L_DACDAT130 equ       %00000001
mDACDAT13L_DACDAT131 equ       %00000010
mDACDAT13L_DACDAT132 equ       %00000100
mDACDAT13L_DACDAT133 equ       %00001000
mDACDAT13L_DACDAT134 equ       %00010000
mDACDAT13L_DACDAT135 equ       %00100000
mDACDAT13L_DACDAT136 equ       %01000000
mDACDAT13L_DACDAT137 equ       %10000000


;*** DACDAT14 - DAC Data 14 Register
DACDAT14            equ       $0000002C           ;*** DACDAT14 - DAC Data 14 Register


;*** DACDAT14H - DAC Data 14 High Register
DACDAT14H           equ       $0000002C           ;*** DACDAT14H - DAC Data 14 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT14H_DACDAT148 equ       0                   ; Buffer Data 14 High, bit 8
DACDAT14H_DACDAT149 equ       1                   ; Buffer Data 14 High, bit 9
DACDAT14H_DACDAT1410 equ       2                   ; Buffer Data 14 High, bit 10
DACDAT14H_DACDAT1411 equ       3                   ; Buffer Data 14 High, bit 11
; bit position masks
mDACDAT14H_DACDAT148 equ       %00000001
mDACDAT14H_DACDAT149 equ       %00000010
mDACDAT14H_DACDAT1410 equ       %00000100
mDACDAT14H_DACDAT1411 equ       %00001000


;*** DACDAT14L - DAC Data 14 Low Register
DACDAT14L           equ       $0000002D           ;*** DACDAT14L - DAC Data 14 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT14L_DACDAT140 equ       0                   ; Buffer Data 14 Low, bit 0
DACDAT14L_DACDAT141 equ       1                   ; Buffer Data 14 Low, bit 1
DACDAT14L_DACDAT142 equ       2                   ; Buffer Data 14 Low, bit 2
DACDAT14L_DACDAT143 equ       3                   ; Buffer Data 14 Low, bit 3
DACDAT14L_DACDAT144 equ       4                   ; Buffer Data 14 Low, bit 4
DACDAT14L_DACDAT145 equ       5                   ; Buffer Data 14 Low, bit 5
DACDAT14L_DACDAT146 equ       6                   ; Buffer Data 14 Low, bit 6
DACDAT14L_DACDAT147 equ       7                   ; Buffer Data 14 Low, bit 7
; bit position masks
mDACDAT14L_DACDAT140 equ       %00000001
mDACDAT14L_DACDAT141 equ       %00000010
mDACDAT14L_DACDAT142 equ       %00000100
mDACDAT14L_DACDAT143 equ       %00001000
mDACDAT14L_DACDAT144 equ       %00010000
mDACDAT14L_DACDAT145 equ       %00100000
mDACDAT14L_DACDAT146 equ       %01000000
mDACDAT14L_DACDAT147 equ       %10000000


;*** DACDAT15 - DAC Data 15 Register
DACDAT15            equ       $0000002E           ;*** DACDAT15 - DAC Data 15 Register


;*** DACDAT15H - DAC Data 15 High Register
DACDAT15H           equ       $0000002E           ;*** DACDAT15H - DAC Data 15 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT15H_DACDAT158 equ       0                   ; Buffer Data 15 High, bit 8
DACDAT15H_DACDAT159 equ       1                   ; Buffer Data 15 High, bit 9
DACDAT15H_DACDAT1510 equ       2                   ; Buffer Data 15 High, bit 10
DACDAT15H_DACDAT1511 equ       3                   ; Buffer Data 15 High, bit 11
; bit position masks
mDACDAT15H_DACDAT158 equ       %00000001
mDACDAT15H_DACDAT159 equ       %00000010
mDACDAT15H_DACDAT1510 equ       %00000100
mDACDAT15H_DACDAT1511 equ       %00001000


;*** DACDAT15L - DAC Data 15 Low Register
DACDAT15L           equ       $0000002F           ;*** DACDAT15L - DAC Data 15 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACDAT15L_DACDAT150 equ       0                   ; Buffer Data 15 Low, bit 0
DACDAT15L_DACDAT151 equ       1                   ; Buffer Data 15 Low, bit 1
DACDAT15L_DACDAT152 equ       2                   ; Buffer Data 15 Low, bit 2
DACDAT15L_DACDAT153 equ       3                   ; Buffer Data 15 Low, bit 3
DACDAT15L_DACDAT154 equ       4                   ; Buffer Data 15 Low, bit 4
DACDAT15L_DACDAT155 equ       5                   ; Buffer Data 15 Low, bit 5
DACDAT15L_DACDAT156 equ       6                   ; Buffer Data 15 Low, bit 6
DACDAT15L_DACDAT157 equ       7                   ; Buffer Data 15 Low, bit 7
; bit position masks
mDACDAT15L_DACDAT150 equ       %00000001
mDACDAT15L_DACDAT151 equ       %00000010
mDACDAT15L_DACDAT152 equ       %00000100
mDACDAT15L_DACDAT153 equ       %00001000
mDACDAT15L_DACDAT154 equ       %00010000
mDACDAT15L_DACDAT155 equ       %00100000
mDACDAT15L_DACDAT156 equ       %01000000
mDACDAT15L_DACDAT157 equ       %10000000


;*** DACS - DAC Status Register
DACS                equ       $00000030           ;*** DACS - DAC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACS_DACRPB         equ       0                   ; DAC buffer read pointer bottom position flag
DACS_DACRPT         equ       1                   ; DAC buffer read pointer top position flag
DACS_DACWM          equ       2                   ; DAC buffer watermark flag
; bit position masks
mDACS_DACRPB        equ       %00000001
mDACS_DACRPT        equ       %00000010
mDACS_DACWM         equ       %00000100


;*** DACC0 - DAC Control 0 Register
DACC0               equ       $00000031           ;*** DACC0 - DAC Control 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACC0_DACBIE        equ       0                   ; DAC buffer read pointer bottom flag interrupt enable
DACC0_DACTIE        equ       1                   ; DAC buffer read pointer top flag interrupt enable
DACC0_DACWIE        equ       2                   ; DAC buffer watermark interrupt enable
DACC0_LPEN          equ       3                   ; DAC low power control
DACC0_DACSTRG       equ       4                   ; DAC software trigger - active high
DACC0_DACTSEL       equ       5                   ; DAC trigger select
DACC0_DACRFS        equ       6                   ; DAC Reference Select
DACC0_DACEN         equ       7                   ; DAC enable - The DACEN bit starts the Programmable Reference Generator operation
; bit position masks
mDACC0_DACBIE       equ       %00000001
mDACC0_DACTIE       equ       %00000010
mDACC0_DACWIE       equ       %00000100
mDACC0_LPEN         equ       %00001000
mDACC0_DACSTRG      equ       %00010000
mDACC0_DACTSEL      equ       %00100000
mDACC0_DACRFS       equ       %01000000
mDACC0_DACEN        equ       %10000000


;*** DACC1 - DAC Control 1 Register
DACC1               equ       $00000032           ;*** DACC1 - DAC Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACC1_DACBFE        equ       0                   ; DAC Buffer Enable
DACC1_DACBFMD0      equ       1                   ; DAC Buffer Work Mode Select, bit 0
DACC1_DACBFMD1      equ       2                   ; DAC Buffer Work Mode Select, bit 1
DACC1_DACBFWM0      equ       3                   ; DAC Buffer Watermark Select, bit 0
DACC1_DACBFWM1      equ       4                   ; DAC Buffer Watermark Select, bit 1
; bit position masks
mDACC1_DACBFE       equ       %00000001
mDACC1_DACBFMD0     equ       %00000010
mDACC1_DACBFMD1     equ       %00000100
mDACC1_DACBFWM0     equ       %00001000
mDACC1_DACBFWM1     equ       %00010000


;*** DACC2 - DAC Control 2 Register
DACC2               equ       $00000033           ;*** DACC2 - DAC Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACC2_DACBFUP       equ       0                   ; DAC Buffer Upper Limit
DACC2_DACBFRP       equ       4                   ; DAC Buffer Read Pointer
; bit position masks
mDACC2_DACBFUP      equ       %00001111
mDACC2_DACBFRP      equ       %11110000


;*** PRACMPCS - PRACMP Control and Status Register
PRACMPCS            equ       $00000034           ;*** PRACMPCS - PRACMP Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMPCS_ACIEN      equ       0                   ; ACMP Interrupt Enable
PRACMPCS_ACINTS0    equ       1                   ; ACMP Interrupt Select, bit 0
PRACMPCS_ACINTS1    equ       2                   ; ACMP Interrupt Select, bit 1
PRACMPCS_ACMPO      equ       3                   ; ACMP Output Bit
PRACMPCS_ACOPE      equ       4                   ; ACMP Output Pin Enable
PRACMPCS_ACMPF      equ       6                   ; ACMP Interrupt Flag
PRACMPCS_ACEN       equ       7                   ; ACMP Module Enable
; bit position masks
mPRACMPCS_ACIEN     equ       %00000001
mPRACMPCS_ACINTS0   equ       %00000010
mPRACMPCS_ACINTS1   equ       %00000100
mPRACMPCS_ACMPO     equ       %00001000
mPRACMPCS_ACOPE     equ       %00010000
mPRACMPCS_ACMPF     equ       %01000000
mPRACMPCS_ACEN      equ       %10000000


;*** PRACMPC0 - PRACMP Control 0 Register
PRACMPC0            equ       $00000035           ;*** PRACMPC0 - PRACMP Control 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMPC0_ACNSEL0    equ       0                   ; ACMP Negative Input Select, bit 0
PRACMPC0_ACNSEL1    equ       1                   ; ACMP Negative Input Select, bit 1
PRACMPC0_ACNSEL2    equ       2                   ; ACMP Negative Input Select, bit 2
PRACMPC0_ACPSEL0    equ       4                   ; ACMP Positive Input Select, bit 0
PRACMPC0_ACPSEL1    equ       5                   ; ACMP Positive Input Select, bit 1
PRACMPC0_ACPSEL2    equ       6                   ; ACMP Positive Input Select, bit 2
; bit position masks
mPRACMPC0_ACNSEL0   equ       %00000001
mPRACMPC0_ACNSEL1   equ       %00000010
mPRACMPC0_ACNSEL2   equ       %00000100
mPRACMPC0_ACPSEL0   equ       %00010000
mPRACMPC0_ACPSEL1   equ       %00100000
mPRACMPC0_ACPSEL2   equ       %01000000


;*** PRACMPC1 - PRACMP Control 1 Register
PRACMPC1            equ       $00000036           ;*** PRACMPC1 - PRACMP Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMPC1_PRGOS0     equ       0                   ; Programmable Reference Generator Output Selection, bit 0
PRACMPC1_PRGOS1     equ       1                   ; Programmable Reference Generator Output Selection, bit 1
PRACMPC1_PRGOS2     equ       2                   ; Programmable Reference Generator Output Selection, bit 2
PRACMPC1_PRGOS3     equ       3                   ; Programmable Reference Generator Output Selection, bit 3
PRACMPC1_PRGOS4     equ       4                   ; Programmable Reference Generator Output Selection, bit 4
PRACMPC1_PRGINS     equ       6                   ; Programmable Reference Generator Input Selection
PRACMPC1_PRGEN      equ       7                   ; Programmable Reference Generator Enable
; bit position masks
mPRACMPC1_PRGOS0    equ       %00000001
mPRACMPC1_PRGOS1    equ       %00000010
mPRACMPC1_PRGOS2    equ       %00000100
mPRACMPC1_PRGOS3    equ       %00001000
mPRACMPC1_PRGOS4    equ       %00010000
mPRACMPC1_PRGINS    equ       %01000000
mPRACMPC1_PRGEN     equ       %10000000


;*** PRACMPC2 - PRACMP Control 2 Register
PRACMPC2            equ       $00000037           ;*** PRACMPC2 - PRACMP Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMPC2_ACIPE0     equ       0                   ; ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0
PRACMPC2_ACIPE1     equ       1                   ; ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1
PRACMPC2_ACIPE2     equ       2                   ; ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2
PRACMPC2_ACIPE3     equ       3                   ; ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3
PRACMPC2_ACIPE4     equ       4                   ; ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4
PRACMPC2_ACIPE5     equ       5                   ; ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5
PRACMPC2_ACIPE6     equ       6                   ; ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6
; bit position masks
mPRACMPC2_ACIPE0    equ       %00000001
mPRACMPC2_ACIPE1    equ       %00000010
mPRACMPC2_ACIPE2    equ       %00000100
mPRACMPC2_ACIPE3    equ       %00001000
mPRACMPC2_ACIPE4    equ       %00010000
mPRACMPC2_ACIPE5    equ       %00100000
mPRACMPC2_ACIPE6    equ       %01000000


;*** MCGC1 - MCG Control Register 1
MCGC1               equ       $00000038           ;*** MCGC1 - MCG Control Register 1
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
MCGC2               equ       $00000039           ;*** MCGC2 - MCG Control Register 2
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
MCGTRM              equ       $0000003A           ;*** MCGTRM - MCG Trim Register
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
MCGSC               equ       $0000003B           ;*** MCGSC - MCG Status and Control Register
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
MCGC3               equ       $0000003C           ;*** MCGC3 - MCG Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC3_VDIV0         equ       0                   ; VCO Divider, bit 0
MCGC3_VDIV1         equ       1                   ; VCO Divider, bit 1
MCGC3_VDIV2         equ       2                   ; VCO Divider, bit 2
MCGC3_VDIV3         equ       3                   ; VCO Divider, bit 3
MCGC3_DIV32         equ       4                   ; Divide-by-32 Enable
MCGC3_CME           equ       5                   ; Clock Monitor Enable
MCGC3_PLLS          equ       6                   ; PLL Select
MCGC3_LOLIE         equ       7                   ; Loss of Lock Interrupt Enable
; bit position masks
mMCGC3_VDIV0        equ       %00000001
mMCGC3_VDIV1        equ       %00000010
mMCGC3_VDIV2        equ       %00000100
mMCGC3_VDIV3        equ       %00001000
mMCGC3_DIV32        equ       %00010000
mMCGC3_CME          equ       %00100000
mMCGC3_PLLS         equ       %01000000
mMCGC3_LOLIE        equ       %10000000


;*** MCGC4 - MCG Control Register 4
MCGC4               equ       $0000003D           ;*** MCGC4 - MCG Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MCGC4_DRST_DRS0     equ       0                   ; DCO Range Status / DCO Range Select, bit 0
MCGC4_DRST_DRS1     equ       1                   ; DCO Range Status / DCO Range Select, bit 1
MCGC4_DMX32         equ       5                   ; DCO Maximum frequency with 32.768 kHz reference
; bit position masks
mMCGC4_DRST_DRS0    equ       %00000001
mMCGC4_DRST_DRS1    equ       %00000010
mMCGC4_DMX32        equ       %00100000


;*** ADCSC1A - Status and Control Register 1A
ADCSC1A             equ       $00000040           ;*** ADCSC1A - Status and Control Register 1A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1A_ADCHA0      equ       0                   ; Input Channel Select Bit 0
ADCSC1A_ADCHA1      equ       1                   ; Input Channel Select Bit 1
ADCSC1A_ADCHA2      equ       2                   ; Input Channel Select Bit 2
ADCSC1A_ADCHA3      equ       3                   ; Input Channel Select Bit 3
ADCSC1A_ADCHA4      equ       4                   ; Input Channel Select Bit 4
ADCSC1A_DIFFA       equ       5                   ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADCSC1A_AIENA       equ       6                   ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA
ADCSC1A_COCOA       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1A_ADCHA0     equ       %00000001
mADCSC1A_ADCHA1     equ       %00000010
mADCSC1A_ADCHA2     equ       %00000100
mADCSC1A_ADCHA3     equ       %00001000
mADCSC1A_ADCHA4     equ       %00010000
mADCSC1A_DIFFA      equ       %00100000
mADCSC1A_AIENA      equ       %01000000
mADCSC1A_COCOA      equ       %10000000


;*** ADCSC1B - Status and Control Register 1B
ADCSC1B             equ       $00000041           ;*** ADCSC1B - Status and Control Register 1B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1B_ADCHB0      equ       0                   ; Input Channel Select Bit 0
ADCSC1B_ADCHB1      equ       1                   ; Input Channel Select Bit 1
ADCSC1B_ADCHB2      equ       2                   ; Input Channel Select Bit 2
ADCSC1B_ADCHB3      equ       3                   ; Input Channel Select Bit 3
ADCSC1B_ADCHB4      equ       4                   ; Input Channel Select Bit 4
ADCSC1B_DIFFB       equ       5                   ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADCSC1B_AIENB       equ       6                   ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB
ADCSC1B_COCOB       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1B_ADCHB0     equ       %00000001
mADCSC1B_ADCHB1     equ       %00000010
mADCSC1B_ADCHB2     equ       %00000100
mADCSC1B_ADCHB3     equ       %00001000
mADCSC1B_ADCHB4     equ       %00010000
mADCSC1B_DIFFB      equ       %00100000
mADCSC1B_AIENB      equ       %01000000
mADCSC1B_COCOB      equ       %10000000


;*** ADCSC1C - Status and Control Register 1C
ADCSC1C             equ       $00000042           ;*** ADCSC1C - Status and Control Register 1C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1C_ADCHC0      equ       0                   ; Input Channel Select Bit 0
ADCSC1C_ADCHC1      equ       1                   ; Input Channel Select Bit 1
ADCSC1C_ADCHC2      equ       2                   ; Input Channel Select Bit 2
ADCSC1C_ADCHC3      equ       3                   ; Input Channel Select Bit 3
ADCSC1C_ADCHC4      equ       4                   ; Input Channel Select Bit 4
ADCSC1C_DIFFC       equ       5                   ; Differential Mode Enable - DIFFC configures the ADC to operate in differential mode
ADCSC1C_AIENC       equ       6                   ; Interrupt Enable - AIENC enables conversion complete interrupts. When COCOC becomes set while the respective AIENC
ADCSC1C_COCOC       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1C_ADCHC0     equ       %00000001
mADCSC1C_ADCHC1     equ       %00000010
mADCSC1C_ADCHC2     equ       %00000100
mADCSC1C_ADCHC3     equ       %00001000
mADCSC1C_ADCHC4     equ       %00010000
mADCSC1C_DIFFC      equ       %00100000
mADCSC1C_AIENC      equ       %01000000
mADCSC1C_COCOC      equ       %10000000


;*** ADCSC1D - Status and Control Register 1D
ADCSC1D             equ       $00000043           ;*** ADCSC1D - Status and Control Register 1D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1D_ADCHD0      equ       0                   ; Input Channel Select Bit 0
ADCSC1D_ADCHD1      equ       1                   ; Input Channel Select Bit 1
ADCSC1D_ADCHD2      equ       2                   ; Input Channel Select Bit 2
ADCSC1D_ADCHD3      equ       3                   ; Input Channel Select Bit 3
ADCSC1D_ADCHD4      equ       4                   ; Input Channel Select Bit 4
ADCSC1D_DIFFD       equ       5                   ; Differential Mode Enable - DIFFD configures the ADC to operate in differential mode
ADCSC1D_AIEND       equ       6                   ; Interrupt Enable - AIEND enables conversion complete interrupts. When COCOD becomes set while the respective AIEND
ADCSC1D_COCOD       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1D_ADCHD0     equ       %00000001
mADCSC1D_ADCHD1     equ       %00000010
mADCSC1D_ADCHD2     equ       %00000100
mADCSC1D_ADCHD3     equ       %00001000
mADCSC1D_ADCHD4     equ       %00010000
mADCSC1D_DIFFD      equ       %00100000
mADCSC1D_AIEND      equ       %01000000
mADCSC1D_COCOD      equ       %10000000


;*** ADCSC1E - Status and Control Register 1E
ADCSC1E             equ       $00000044           ;*** ADCSC1E - Status and Control Register 1E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1E_ADCHE0      equ       0                   ; Input Channel Select Bit 0
ADCSC1E_ADCHE1      equ       1                   ; Input Channel Select Bit 1
ADCSC1E_ADCHE2      equ       2                   ; Input Channel Select Bit 2
ADCSC1E_ADCHE3      equ       3                   ; Input Channel Select Bit 3
ADCSC1E_ADCHE4      equ       4                   ; Input Channel Select Bit 4
ADCSC1E_DIFFE       equ       5                   ; Differential Mode Enable - DIFFE configures the ADC to operate in differential mode
ADCSC1E_AIENE       equ       6                   ; Interrupt Enable - AIENE enables conversion complete interrupts. When COCOE becomes set while the respective AIENE
ADCSC1E_COCOE       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1E_ADCHE0     equ       %00000001
mADCSC1E_ADCHE1     equ       %00000010
mADCSC1E_ADCHE2     equ       %00000100
mADCSC1E_ADCHE3     equ       %00001000
mADCSC1E_ADCHE4     equ       %00010000
mADCSC1E_DIFFE      equ       %00100000
mADCSC1E_AIENE      equ       %01000000
mADCSC1E_COCOE      equ       %10000000


;*** ADCSC1F - Status and Control Register 1F
ADCSC1F             equ       $00000045           ;*** ADCSC1F - Status and Control Register 1F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1F_ADCHF0      equ       0                   ; Input Channel Select Bit 0
ADCSC1F_ADCHF1      equ       1                   ; Input Channel Select Bit 1
ADCSC1F_ADCHF2      equ       2                   ; Input Channel Select Bit 2
ADCSC1F_ADCHF3      equ       3                   ; Input Channel Select Bit 3
ADCSC1F_ADCHF4      equ       4                   ; Input Channel Select Bit 4
ADCSC1F_DIFFF       equ       5                   ; Differential Mode Enable - DIFFF configures the ADC to operate in differential mode
ADCSC1F_AIENF       equ       6                   ; Interrupt Enable - AIENF enables conversion complete interrupts. When COCOF becomes set while the respective AIENF
ADCSC1F_COCOF       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1F_ADCHF0     equ       %00000001
mADCSC1F_ADCHF1     equ       %00000010
mADCSC1F_ADCHF2     equ       %00000100
mADCSC1F_ADCHF3     equ       %00001000
mADCSC1F_ADCHF4     equ       %00010000
mADCSC1F_DIFFF      equ       %00100000
mADCSC1F_AIENF      equ       %01000000
mADCSC1F_COCOF      equ       %10000000


;*** ADCSC1G - Status and Control Register 1G
ADCSC1G             equ       $00000046           ;*** ADCSC1G - Status and Control Register 1G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1G_ADCHG0      equ       0                   ; Input Channel Select Bit 0
ADCSC1G_ADCHG1      equ       1                   ; Input Channel Select Bit 1
ADCSC1G_ADCHG2      equ       2                   ; Input Channel Select Bit 2
ADCSC1G_ADCHG3      equ       3                   ; Input Channel Select Bit 3
ADCSC1G_ADCHG4      equ       4                   ; Input Channel Select Bit 4
ADCSC1G_DIFFG       equ       5                   ; Differential Mode Enable - DIFFG configures the ADC to operate in differential mode
ADCSC1G_AIENG       equ       6                   ; Interrupt Enable - AIENG enables conversion complete interrupts. When COCOG becomes set while the respective AIENG
ADCSC1G_COCOG       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1G_ADCHG0     equ       %00000001
mADCSC1G_ADCHG1     equ       %00000010
mADCSC1G_ADCHG2     equ       %00000100
mADCSC1G_ADCHG3     equ       %00001000
mADCSC1G_ADCHG4     equ       %00010000
mADCSC1G_DIFFG      equ       %00100000
mADCSC1G_AIENG      equ       %01000000
mADCSC1G_COCOG      equ       %10000000


;*** ADCSC1H - Status and Control Register 1H
ADCSC1H             equ       $00000047           ;*** ADCSC1H - Status and Control Register 1H
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1H_ADCHH0      equ       0                   ; Input Channel Select Bit 0
ADCSC1H_ADCHH1      equ       1                   ; Input Channel Select Bit 1
ADCSC1H_ADCHH2      equ       2                   ; Input Channel Select Bit 2
ADCSC1H_ADCHH3      equ       3                   ; Input Channel Select Bit 3
ADCSC1H_ADCHH4      equ       4                   ; Input Channel Select Bit 4
ADCSC1H_DIFFH       equ       5                   ; Differential Mode Enable - DIFFH configures the ADC to operate in differential mode
ADCSC1H_AIENH       equ       6                   ; Interrupt Enable - AIENH enables conversion complete interrupts. When COCOH becomes set while the respective AIENH
ADCSC1H_COCOH       equ       7                   ; Conversion Complete Flag
; bit position masks
mADCSC1H_ADCHH0     equ       %00000001
mADCSC1H_ADCHH1     equ       %00000010
mADCSC1H_ADCHH2     equ       %00000100
mADCSC1H_ADCHH3     equ       %00001000
mADCSC1H_ADCHH4     equ       %00010000
mADCSC1H_DIFFH      equ       %00100000
mADCSC1H_AIENH      equ       %01000000
mADCSC1H_COCOH      equ       %10000000


;*** ADCCFG1 - Configuration Register 1
ADCCFG1             equ       $00000048           ;*** ADCCFG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG1_ADICLK0     equ       0                   ; Input Clock Select Bit 0
ADCCFG1_ADICLK1     equ       1                   ; Input Clock Select Bit 1
ADCCFG1_MODE0       equ       2                   ; Conversion Mode Selection Bit 0
ADCCFG1_MODE1       equ       3                   ; Conversion Mode Selection Bit 1
ADCCFG1_ADLSMP      equ       4                   ; Long Sample Time Configuration
ADCCFG1_ADIV0       equ       5                   ; Clock Divide Select Bit 0
ADCCFG1_ADIV1       equ       6                   ; Clock Divide Select Bit 1
ADCCFG1_ADLPC       equ       7                   ; Low Power Configuration
; bit position masks
mADCCFG1_ADICLK0    equ       %00000001
mADCCFG1_ADICLK1    equ       %00000010
mADCCFG1_MODE0      equ       %00000100
mADCCFG1_MODE1      equ       %00001000
mADCCFG1_ADLSMP     equ       %00010000
mADCCFG1_ADIV0      equ       %00100000
mADCCFG1_ADIV1      equ       %01000000
mADCCFG1_ADLPC      equ       %10000000


;*** ADCCFG2 - Configuration Register 2
ADCCFG2             equ       $00000049           ;*** ADCCFG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG2_ADLSTS0     equ       0                   ; Long Sample Time Select Bit 0
ADCCFG2_ADLSTS1     equ       1                   ; Long Sample Time Select Bit 1
ADCCFG2_ADHSC       equ       2                   ; High Speed Configuration
ADCCFG2_ADACKEN     equ       3                   ; Asynchronous Clock Output Enable
; bit position masks
mADCCFG2_ADLSTS0    equ       %00000001
mADCCFG2_ADLSTS1    equ       %00000010
mADCCFG2_ADHSC      equ       %00000100
mADCCFG2_ADACKEN    equ       %00001000


;*** ADCRA - Data Result Register A
ADCRA               equ       $0000004A           ;*** ADCRA - Data Result Register A


;*** ADCRHA - Data Result High Register A
ADCRHA              equ       $0000004A           ;*** ADCRHA - Data Result High Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHA_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHA_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHA_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHA_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHA_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHA_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHA_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHA_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHA_D8          equ       %00000001
mADCRHA_D9          equ       %00000010
mADCRHA_D10         equ       %00000100
mADCRHA_D11         equ       %00001000
mADCRHA_D12         equ       %00010000
mADCRHA_D13         equ       %00100000
mADCRHA_D14         equ       %01000000
mADCRHA_D15         equ       %10000000


;*** ADCRLA - Data Result Low Register A
ADCRLA              equ       $0000004B           ;*** ADCRLA - Data Result Low Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLA_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLA_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLA_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLA_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLA_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLA_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLA_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLA_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLA_D0          equ       %00000001
mADCRLA_D1          equ       %00000010
mADCRLA_D2          equ       %00000100
mADCRLA_D3          equ       %00001000
mADCRLA_D4          equ       %00010000
mADCRLA_D5          equ       %00100000
mADCRLA_D6          equ       %01000000
mADCRLA_D7          equ       %10000000


;*** ADCRB - Data Result Register B
ADCRB               equ       $0000004C           ;*** ADCRB - Data Result Register B


;*** ADCRHB - Data Result High Register B
ADCRHB              equ       $0000004C           ;*** ADCRHB - Data Result High Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHB_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHB_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHB_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHB_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHB_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHB_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHB_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHB_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHB_D8          equ       %00000001
mADCRHB_D9          equ       %00000010
mADCRHB_D10         equ       %00000100
mADCRHB_D11         equ       %00001000
mADCRHB_D12         equ       %00010000
mADCRHB_D13         equ       %00100000
mADCRHB_D14         equ       %01000000
mADCRHB_D15         equ       %10000000


;*** ADCRLB - Data Result Low Register B
ADCRLB              equ       $0000004D           ;*** ADCRLB - Data Result Low Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLB_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLB_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLB_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLB_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLB_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLB_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLB_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLB_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLB_D0          equ       %00000001
mADCRLB_D1          equ       %00000010
mADCRLB_D2          equ       %00000100
mADCRLB_D3          equ       %00001000
mADCRLB_D4          equ       %00010000
mADCRLB_D5          equ       %00100000
mADCRLB_D6          equ       %01000000
mADCRLB_D7          equ       %10000000


;*** ADCRC - Data Result Register C
ADCRC               equ       $0000004E           ;*** ADCRC - Data Result Register C


;*** ADCRHC - Data Result High Register C
ADCRHC              equ       $0000004E           ;*** ADCRHC - Data Result High Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHC_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHC_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHC_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHC_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHC_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHC_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHC_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHC_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHC_D8          equ       %00000001
mADCRHC_D9          equ       %00000010
mADCRHC_D10         equ       %00000100
mADCRHC_D11         equ       %00001000
mADCRHC_D12         equ       %00010000
mADCRHC_D13         equ       %00100000
mADCRHC_D14         equ       %01000000
mADCRHC_D15         equ       %10000000


;*** ADCRLC - Data Result Low Register C
ADCRLC              equ       $0000004F           ;*** ADCRLC - Data Result Low Register C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLC_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLC_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLC_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLC_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLC_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLC_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLC_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLC_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLC_D0          equ       %00000001
mADCRLC_D1          equ       %00000010
mADCRLC_D2          equ       %00000100
mADCRLC_D3          equ       %00001000
mADCRLC_D4          equ       %00010000
mADCRLC_D5          equ       %00100000
mADCRLC_D6          equ       %01000000
mADCRLC_D7          equ       %10000000


;*** ADCRD - Data Result Register D
ADCRD               equ       $00000050           ;*** ADCRD - Data Result Register D


;*** ADCRHD - Data Result High Register D
ADCRHD              equ       $00000050           ;*** ADCRHD - Data Result High Register D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHD_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHD_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHD_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHD_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHD_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHD_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHD_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHD_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHD_D8          equ       %00000001
mADCRHD_D9          equ       %00000010
mADCRHD_D10         equ       %00000100
mADCRHD_D11         equ       %00001000
mADCRHD_D12         equ       %00010000
mADCRHD_D13         equ       %00100000
mADCRHD_D14         equ       %01000000
mADCRHD_D15         equ       %10000000


;*** ADCRLD - Data Result Low Register D
ADCRLD              equ       $00000051           ;*** ADCRLD - Data Result Low Register D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLD_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLD_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLD_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLD_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLD_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLD_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLD_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLD_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLD_D0          equ       %00000001
mADCRLD_D1          equ       %00000010
mADCRLD_D2          equ       %00000100
mADCRLD_D3          equ       %00001000
mADCRLD_D4          equ       %00010000
mADCRLD_D5          equ       %00100000
mADCRLD_D6          equ       %01000000
mADCRLD_D7          equ       %10000000


;*** ADCRE - Data Result Register E
ADCRE               equ       $00000052           ;*** ADCRE - Data Result Register E


;*** ADCRHE - Data Result High Register E
ADCRHE              equ       $00000052           ;*** ADCRHE - Data Result High Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHE_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHE_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHE_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHE_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHE_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHE_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHE_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHE_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHE_D8          equ       %00000001
mADCRHE_D9          equ       %00000010
mADCRHE_D10         equ       %00000100
mADCRHE_D11         equ       %00001000
mADCRHE_D12         equ       %00010000
mADCRHE_D13         equ       %00100000
mADCRHE_D14         equ       %01000000
mADCRHE_D15         equ       %10000000


;*** ADCRLE - Data Result Low Register E
ADCRLE              equ       $00000053           ;*** ADCRLE - Data Result Low Register E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLE_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLE_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLE_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLE_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLE_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLE_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLE_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLE_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLE_D0          equ       %00000001
mADCRLE_D1          equ       %00000010
mADCRLE_D2          equ       %00000100
mADCRLE_D3          equ       %00001000
mADCRLE_D4          equ       %00010000
mADCRLE_D5          equ       %00100000
mADCRLE_D6          equ       %01000000
mADCRLE_D7          equ       %10000000


;*** ADCRF - Data Result Register F
ADCRF               equ       $00000054           ;*** ADCRF - Data Result Register F


;*** ADCRHF - Data Result High Register F
ADCRHF              equ       $00000054           ;*** ADCRHF - Data Result High Register F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHF_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHF_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHF_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHF_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHF_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHF_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHF_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHF_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHF_D8          equ       %00000001
mADCRHF_D9          equ       %00000010
mADCRHF_D10         equ       %00000100
mADCRHF_D11         equ       %00001000
mADCRHF_D12         equ       %00010000
mADCRHF_D13         equ       %00100000
mADCRHF_D14         equ       %01000000
mADCRHF_D15         equ       %10000000


;*** ADCRLF - Data Result Low Register F
ADCRLF              equ       $00000055           ;*** ADCRLF - Data Result Low Register F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLF_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLF_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLF_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLF_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLF_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLF_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLF_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLF_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLF_D0          equ       %00000001
mADCRLF_D1          equ       %00000010
mADCRLF_D2          equ       %00000100
mADCRLF_D3          equ       %00001000
mADCRLF_D4          equ       %00010000
mADCRLF_D5          equ       %00100000
mADCRLF_D6          equ       %01000000
mADCRLF_D7          equ       %10000000


;*** ADCRG - Data Result Register G
ADCRG               equ       $00000056           ;*** ADCRG - Data Result Register G


;*** ADCRHG - Data Result High Register G
ADCRHG              equ       $00000056           ;*** ADCRHG - Data Result High Register G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHG_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHG_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHG_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHG_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHG_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHG_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHG_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHG_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHG_D8          equ       %00000001
mADCRHG_D9          equ       %00000010
mADCRHG_D10         equ       %00000100
mADCRHG_D11         equ       %00001000
mADCRHG_D12         equ       %00010000
mADCRHG_D13         equ       %00100000
mADCRHG_D14         equ       %01000000
mADCRHG_D15         equ       %10000000


;*** ADCRLG - Data Result Low Register G
ADCRLG              equ       $00000057           ;*** ADCRLG - Data Result Low Register G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLG_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLG_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLG_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLG_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLG_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLG_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLG_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLG_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLG_D0          equ       %00000001
mADCRLG_D1          equ       %00000010
mADCRLG_D2          equ       %00000100
mADCRLG_D3          equ       %00001000
mADCRLG_D4          equ       %00010000
mADCRLG_D5          equ       %00100000
mADCRLG_D6          equ       %01000000
mADCRLG_D7          equ       %10000000


;*** ADCRH - Data Result Register H
ADCRH               equ       $00000058           ;*** ADCRH - Data Result Register H


;*** ADCRHH - Data Result High Register H
ADCRHH              equ       $00000058           ;*** ADCRHH - Data Result High Register H
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHH_D8           equ       0                   ; ADC Result Data Bit 8
ADCRHH_D9           equ       1                   ; ADC Result Data Bit 9
ADCRHH_D10          equ       2                   ; ADC Result Data Bit 10
ADCRHH_D11          equ       3                   ; ADC Result Data Bit 11
ADCRHH_D12          equ       4                   ; ADC Result Data Bit 12
ADCRHH_D13          equ       5                   ; ADC Result Data Bit 13
ADCRHH_D14          equ       6                   ; ADC Result Data Bit 14
ADCRHH_D15          equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADCRHH_D8          equ       %00000001
mADCRHH_D9          equ       %00000010
mADCRHH_D10         equ       %00000100
mADCRHH_D11         equ       %00001000
mADCRHH_D12         equ       %00010000
mADCRHH_D13         equ       %00100000
mADCRHH_D14         equ       %01000000
mADCRHH_D15         equ       %10000000


;*** ADCRLH - Data Result Low Register H
ADCRLH              equ       $00000059           ;*** ADCRLH - Data Result Low Register H
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLH_D0           equ       0                   ; ADC Result Data Bit 0
ADCRLH_D1           equ       1                   ; ADC Result Data Bit 1
ADCRLH_D2           equ       2                   ; ADC Result Data Bit 2
ADCRLH_D3           equ       3                   ; ADC Result Data Bit 3
ADCRLH_D4           equ       4                   ; ADC Result Data Bit 4
ADCRLH_D5           equ       5                   ; ADC Result Data Bit 5
ADCRLH_D6           equ       6                   ; ADC Result Data Bit 6
ADCRLH_D7           equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADCRLH_D0          equ       %00000001
mADCRLH_D1          equ       %00000010
mADCRLH_D2          equ       %00000100
mADCRLH_D3          equ       %00001000
mADCRLH_D4          equ       %00010000
mADCRLH_D5          equ       %00100000
mADCRLH_D6          equ       %01000000
mADCRLH_D7          equ       %10000000


;*** VREFTRM - VREF Trim Register
VREFTRM             equ       $0000005C           ;*** VREFTRM - VREF Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREFTRM_TRM0        equ       0                   ; Trim Bits, bit 0
VREFTRM_TRM1        equ       1                   ; Trim Bits, bit 1
VREFTRM_TRM2        equ       2                   ; Trim Bits, bit 2
VREFTRM_TRM3        equ       3                   ; Trim Bits, bit 3
VREFTRM_TRM4        equ       4                   ; Trim Bits, bit 4
VREFTRM_TRM5        equ       5                   ; Trim Bits, bit 5
VREFTRM_TRM6        equ       6                   ; Trim Bits, bit 6
VREFTRM_TRM7        equ       7                   ; Trim Bits, bit 7
; bit position masks
mVREFTRM_TRM0       equ       %00000001
mVREFTRM_TRM1       equ       %00000010
mVREFTRM_TRM2       equ       %00000100
mVREFTRM_TRM3       equ       %00001000
mVREFTRM_TRM4       equ       %00010000
mVREFTRM_TRM5       equ       %00100000
mVREFTRM_TRM6       equ       %01000000
mVREFTRM_TRM7       equ       %10000000


;*** VREFSC - VREF Control Register
VREFSC              equ       $0000005D           ;*** VREFSC - VREF Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREFSC_MODE0        equ       0                   ; Mode selection, bit 0
VREFSC_MODE1        equ       1                   ; Mode selection, bit 1
VREFSC_VREFST       equ       2                   ; Internal Voltage Reference Stable
VREFSC_VREFEN       equ       7                   ; Internal Voltage Reference Enable
; bit position masks
mVREFSC_MODE0       equ       %00000001
mVREFSC_MODE1       equ       %00000010
mVREFSC_VREFST      equ       %00000100
mVREFSC_VREFEN      equ       %10000000


;*** IRQSC - Interrupt request status and control register
IRQSC               equ       $0000005F           ;*** IRQSC - Interrupt request status and control register
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


;*** IICA1 - IIC Address Register
IICA1               equ       $00000060           ;*** IICA1 - IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA1_AD1           equ       1                   ; Slave Address Bit 1
IICA1_AD2           equ       2                   ; Slave Address Bit 2
IICA1_AD3           equ       3                   ; Slave Address Bit 3
IICA1_AD4           equ       4                   ; Slave Address Bit 4
IICA1_AD5           equ       5                   ; Slave Address Bit 5
IICA1_AD6           equ       6                   ; Slave Address Bit 6
IICA1_AD7           equ       7                   ; Slave Address Bit 7
; bit position masks
mIICA1_AD1          equ       %00000010
mIICA1_AD2          equ       %00000100
mIICA1_AD3          equ       %00001000
mIICA1_AD4          equ       %00010000
mIICA1_AD5          equ       %00100000
mIICA1_AD6          equ       %01000000
mIICA1_AD7          equ       %10000000


;*** IICA - IIC Address Register
IICA                equ       $00000060           ;*** IICA - IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA_AD1            equ       1                   ; Slave Address Bit 1
IICA_AD2            equ       2                   ; Slave Address Bit 2
IICA_AD3            equ       3                   ; Slave Address Bit 3
IICA_AD4            equ       4                   ; Slave Address Bit 4
IICA_AD5            equ       5                   ; Slave Address Bit 5
IICA_AD6            equ       6                   ; Slave Address Bit 6
IICA_AD7            equ       7                   ; Slave Address Bit 7
; bit position masks
mIICA_AD1           equ       %00000010
mIICA_AD2           equ       %00000100
mIICA_AD3           equ       %00001000
mIICA_AD4           equ       %00010000
mIICA_AD5           equ       %00100000
mIICA_AD6           equ       %01000000
mIICA_AD7           equ       %10000000


;*** IICF - IIC Frequency Divider Register
IICF                equ       $00000061           ;*** IICF - IIC Frequency Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICF_ICR0           equ       0                   ; IIC Clock Rate Bit 0
IICF_ICR1           equ       1                   ; IIC Clock Rate Bit 1
IICF_ICR2           equ       2                   ; IIC Clock Rate Bit 2
IICF_ICR3           equ       3                   ; IIC Clock Rate Bit 3
IICF_ICR4           equ       4                   ; IIC Clock Rate Bit 4
IICF_ICR5           equ       5                   ; IIC Clock Rate Bit 5
IICF_MULT0          equ       6                   ; Multiplier Factor Bit 0
IICF_MULT1          equ       7                   ; Multiplier Factor Bit 1
; bit position masks
mIICF_ICR0          equ       %00000001
mIICF_ICR1          equ       %00000010
mIICF_ICR2          equ       %00000100
mIICF_ICR3          equ       %00001000
mIICF_ICR4          equ       %00010000
mIICF_ICR5          equ       %00100000
mIICF_MULT0         equ       %01000000
mIICF_MULT1         equ       %10000000


;*** IICC1 - IIC Control Register 1
IICC1               equ       $00000062           ;*** IICC1 - IIC Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC1_RSTA          equ       2                   ; Repeat START
IICC1_TXAK          equ       3                   ; Transmit Acknowledge Enable
IICC1_TX            equ       4                   ; Transmit Mode Select
IICC1_MST           equ       5                   ; Master Mode Select
IICC1_IICIE         equ       6                   ; IIC Interrupt Enable
IICC1_IICEN         equ       7                   ; IIC Enable
; bit position masks
mIICC1_RSTA         equ       %00000100
mIICC1_TXAK         equ       %00001000
mIICC1_TX           equ       %00010000
mIICC1_MST          equ       %00100000
mIICC1_IICIE        equ       %01000000
mIICC1_IICEN        equ       %10000000


;*** IICC - IIC Control Register
IICC                equ       $00000062           ;*** IICC - IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC_RSTA           equ       2                   ; Repeat START
IICC_TXAK           equ       3                   ; Transmit Acknowledge Enable
IICC_TX             equ       4                   ; Transmit Mode Select
IICC_MST            equ       5                   ; Master Mode Select
IICC_IICIE          equ       6                   ; IIC Interrupt Enable
IICC_IICEN          equ       7                   ; IIC Enable
; bit position masks
mIICC_RSTA          equ       %00000100
mIICC_TXAK          equ       %00001000
mIICC_TX            equ       %00010000
mIICC_MST           equ       %00100000
mIICC_IICIE         equ       %01000000
mIICC_IICEN         equ       %10000000


;*** IICS - IIC Status Register
IICS                equ       $00000063           ;*** IICS - IIC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICS_RXAK           equ       0                   ; Receive Acknowledge
IICS_IICIF          equ       1                   ; IIC Interrupt Flag
IICS_SRW            equ       2                   ; Slave Read/Write
IICS_ARBL           equ       4                   ; Arbitration Lost
IICS_BUSY           equ       5                   ; Bus Busy
IICS_IAAS           equ       6                   ; Addressed as a Slave
IICS_TCF            equ       7                   ; Transfer Complete Flag
; bit position masks
mIICS_RXAK          equ       %00000001
mIICS_IICIF         equ       %00000010
mIICS_SRW           equ       %00000100
mIICS_ARBL          equ       %00010000
mIICS_BUSY          equ       %00100000
mIICS_IAAS          equ       %01000000
mIICS_TCF           equ       %10000000


;*** IICD - IIC Data I/O Register
IICD                equ       $00000064           ;*** IICD - IIC Data I/O Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICD_DATA0          equ       0                   ; IIC Data Bit 0
IICD_DATA1          equ       1                   ; IIC Data Bit 1
IICD_DATA2          equ       2                   ; IIC Data Bit 2
IICD_DATA3          equ       3                   ; IIC Data Bit 3
IICD_DATA4          equ       4                   ; IIC Data Bit 4
IICD_DATA5          equ       5                   ; IIC Data Bit 5
IICD_DATA6          equ       6                   ; IIC Data Bit 6
IICD_DATA7          equ       7                   ; IIC Data Bit 7
; bit position masks
mIICD_DATA0         equ       %00000001
mIICD_DATA1         equ       %00000010
mIICD_DATA2         equ       %00000100
mIICD_DATA3         equ       %00001000
mIICD_DATA4         equ       %00010000
mIICD_DATA5         equ       %00100000
mIICD_DATA6         equ       %01000000
mIICD_DATA7         equ       %10000000


;*** IICC2 - IIC Control Register 2
IICC2               equ       $00000065           ;*** IICC2 - IIC Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC2_AD8           equ       0                   ; Slave Address Bit 8
IICC2_AD9           equ       1                   ; Slave Address Bit 9
IICC2_AD10          equ       2                   ; Slave Address Bit 10
IICC2_ADEXT         equ       6                   ; Address Extension
IICC2_GCAEN         equ       7                   ; General Call Address Enable
; bit position masks
mIICC2_AD8          equ       %00000001
mIICC2_AD9          equ       %00000010
mIICC2_AD10         equ       %00000100
mIICC2_ADEXT        equ       %01000000
mIICC2_GCAEN        equ       %10000000


;*** IICSMB - SMBus Control and Status Register
IICSMB              equ       $00000066           ;*** IICSMB - SMBus Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSMB_SHTF         equ       2                   ; SCL High Timeout Flag
IICSMB_SLTF         equ       3                   ; SCL Low Timeout Flag
IICSMB_TCKSEL       equ       4                   ; Time Out Counter Clock Select
IICSMB_SIICAEN      equ       5                   ; Second IIC Address Enable
IICSMB_ALERTEN      equ       6                   ; SMBus Alert Response Address Enable
IICSMB_FACK         equ       7                   ; Fast NACK/ACK enable
; bit position masks
mIICSMB_SHTF        equ       %00000100
mIICSMB_SLTF        equ       %00001000
mIICSMB_TCKSEL      equ       %00010000
mIICSMB_SIICAEN     equ       %00100000
mIICSMB_ALERTEN     equ       %01000000
mIICSMB_FACK        equ       %10000000


;*** IICA2 - IIC Address Register 2
IICA2               equ       $00000067           ;*** IICA2 - IIC Address Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA2_SAD1          equ       1                   ; SMBus Address Bit 1
IICA2_SAD2          equ       2                   ; SMBus Address Bit 2
IICA2_SAD3          equ       3                   ; SMBus Address Bit 3
IICA2_SAD4          equ       4                   ; SMBus Address Bit 4
IICA2_SAD5          equ       5                   ; SMBus Address Bit 5
IICA2_SAD6          equ       6                   ; SMBus Address Bit 6
IICA2_SAD7          equ       7                   ; SMBus Address Bit 7
; bit position masks
mIICA2_SAD1         equ       %00000010
mIICA2_SAD2         equ       %00000100
mIICA2_SAD3         equ       %00001000
mIICA2_SAD4         equ       %00010000
mIICA2_SAD5         equ       %00100000
mIICA2_SAD6         equ       %01000000
mIICA2_SAD7         equ       %10000000


;*** IICSLT - IIC SCL Low Time Out register
IICSLT              equ       $00000068           ;*** IICSLT - IIC SCL Low Time Out register


;*** IICSLTH - IIC SCL Low Time Out register - High byte
IICSLTH             equ       $00000068           ;*** IICSLTH - IIC SCL Low Time Out register - High byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLTH_SSLT8       equ       0                   ; SCL Low Time Out Bit 8
IICSLTH_SSLT9       equ       1                   ; SCL Low Time Out Bit 9
IICSLTH_SSLT10      equ       2                   ; SCL Low Time Out Bit 10
IICSLTH_SSLT11      equ       3                   ; SCL Low Time Out Bit 11
IICSLTH_SSLT12      equ       4                   ; SCL Low Time Out Bit 12
IICSLTH_SSLT13      equ       5                   ; SCL Low Time Out Bit 13
IICSLTH_SSLT14      equ       6                   ; SCL Low Time Out Bit 14
IICSLTH_SSLT15      equ       7                   ; SCL Low Time Out Bit 15
; bit position masks
mIICSLTH_SSLT8      equ       %00000001
mIICSLTH_SSLT9      equ       %00000010
mIICSLTH_SSLT10     equ       %00000100
mIICSLTH_SSLT11     equ       %00001000
mIICSLTH_SSLT12     equ       %00010000
mIICSLTH_SSLT13     equ       %00100000
mIICSLTH_SSLT14     equ       %01000000
mIICSLTH_SSLT15     equ       %10000000


;*** IICSLTL - IIC SCL Low Time Out register - Low byte
IICSLTL             equ       $00000069           ;*** IICSLTL - IIC SCL Low Time Out register - Low byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSLTL_SSLT0       equ       0                   ; SCL Low Time Out Bits, bit 0
IICSLTL_SSLT1       equ       1                   ; SCL Low Time Out Bits, bit 1
IICSLTL_SSLT2       equ       2                   ; SCL Low Time Out Bits, bit 2
IICSLTL_SSLT3       equ       3                   ; SCL Low Time Out Bits, bit 3
IICSLTL_SSLT4       equ       4                   ; SCL Low Time Out Bits, bit 4
IICSLTL_SSLT5       equ       5                   ; SCL Low Time Out Bits, bit 5
IICSLTL_SSLT6       equ       6                   ; SCL Low Time Out Bits, bit 6
IICSLTL_SSLT7       equ       7                   ; SCL Low Time Out Bits, bit 7
; bit position masks
mIICSLTL_SSLT0      equ       %00000001
mIICSLTL_SSLT1      equ       %00000010
mIICSLTL_SSLT2      equ       %00000100
mIICSLTL_SSLT3      equ       %00001000
mIICSLTL_SSLT4      equ       %00010000
mIICSLTL_SSLT5      equ       %00100000
mIICSLTL_SSLT6      equ       %01000000
mIICSLTL_SSLT7      equ       %10000000


;*** IICFLT - IIC Filter register
IICFLT              equ       $0000006A           ;*** IICFLT - IIC Filter register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICFLT_FLT0         equ       0                   ; Filter value bit 0
IICFLT_FLT1         equ       1                   ; Filter value bit 1
IICFLT_FLT2         equ       2                   ; Filter value bit 2
IICFLT_FLT3         equ       3                   ; Filter value bit 3
; bit position masks
mIICFLT_FLT0        equ       %00000001
mIICFLT_FLT1        equ       %00000010
mIICFLT_FLT2        equ       %00000100
mIICFLT_FLT3        equ       %00001000


;*** KBI1SC - KBI1 Status and Control Register
KBI1SC              equ       $0000006C           ;*** KBI1SC - KBI1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1SC_KBI1MOD      equ       0                   ; Keyboard Detection Mode
KBI1SC_KB1IE        equ       1                   ; Keyboard Interrupt Enable
KBI1SC_KB1ACK       equ       2                   ; Keyboard Interrupt Acknowledge
KBI1SC_KB1F         equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI1SC_KBI1MOD     equ       %00000001
mKBI1SC_KB1IE       equ       %00000010
mKBI1SC_KB1ACK      equ       %00000100
mKBI1SC_KB1F        equ       %00001000


;*** KBI1PE - KBI1 Pin Enable Register
KBI1PE              equ       $0000006D           ;*** KBI1PE - KBI1 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBI1PE0      equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI1PE_KBI1PE1      equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI1PE_KBI1PE2      equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI1PE_KBI1PE3      equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBI1PE_KBI1PE4      equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBI1PE_KBI1PE5      equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBI1PE_KBI1PE6      equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBI1PE_KBI1PE7      equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI1PE_KBI1PE0     equ       %00000001
mKBI1PE_KBI1PE1     equ       %00000010
mKBI1PE_KBI1PE2     equ       %00000100
mKBI1PE_KBI1PE3     equ       %00001000
mKBI1PE_KBI1PE4     equ       %00010000
mKBI1PE_KBI1PE5     equ       %00100000
mKBI1PE_KBI1PE6     equ       %01000000
mKBI1PE_KBI1PE7     equ       %10000000


;*** KBI1ES - KBI1 Edge Select Register
KBI1ES              equ       $0000006E           ;*** KBI1ES - KBI1 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1ES_KB1EDG0      equ       0                   ; Keyboard Edge Select Bit 0
KBI1ES_KB1EDG1      equ       1                   ; Keyboard Edge Select Bit 1
KBI1ES_KB1EDG2      equ       2                   ; Keyboard Edge Select Bit 2
KBI1ES_KB1EDG3      equ       3                   ; Keyboard Edge Select Bit 3
KBI1ES_KB1EDG4      equ       4                   ; Keyboard Edge Select Bit 4
KBI1ES_KB1EDG5      equ       5                   ; Keyboard Edge Select Bit 5
KBI1ES_KB1EDG6      equ       6                   ; Keyboard Edge Select Bit 6
KBI1ES_KB1EDG7      equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBI1ES_KB1EDG0     equ       %00000001
mKBI1ES_KB1EDG1     equ       %00000010
mKBI1ES_KB1EDG2     equ       %00000100
mKBI1ES_KB1EDG3     equ       %00001000
mKBI1ES_KB1EDG4     equ       %00010000
mKBI1ES_KB1EDG5     equ       %00100000
mKBI1ES_KB1EDG6     equ       %01000000
mKBI1ES_KB1EDG7     equ       %10000000


;*** SPI1C1 - SPI1 Control Register 1
SPI1C1              equ       $00000070           ;*** SPI1C1 - SPI1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C1_LSBFE        equ       0                   ; LSB First (Shifter Direction)
SPI1C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI1C1_CPHA         equ       2                   ; Clock Phase
SPI1C1_CPOL         equ       3                   ; Clock Polarity
SPI1C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI1C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI1C1_SPE          equ       6                   ; SPI System Enable
SPI1C1_SPIE         equ       7                   ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI1C1_LSBFE       equ       %00000001
mSPI1C1_SSOE        equ       %00000010
mSPI1C1_CPHA        equ       %00000100
mSPI1C1_CPOL        equ       %00001000
mSPI1C1_MSTR        equ       %00010000
mSPI1C1_SPTIE       equ       %00100000
mSPI1C1_SPE         equ       %01000000
mSPI1C1_SPIE        equ       %10000000


;*** SPI1C2 - SPI1 Control Register 2
SPI1C2              equ       $00000071           ;*** SPI1C2 - SPI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI1C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI1C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI1C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
SPI1C2_SPIMODE      equ       6                   ; SPI 8- or 16-bit Mode Select
SPI1C2_SPMIE        equ       7                   ; SPI Match Interrupt Enable
; bit position masks
mSPI1C2_SPC0        equ       %00000001
mSPI1C2_SPISWAI     equ       %00000010
mSPI1C2_BIDIROE     equ       %00001000
mSPI1C2_MODFEN      equ       %00010000
mSPI1C2_SPIMODE     equ       %01000000
mSPI1C2_SPMIE       equ       %10000000


;*** SPI1BR - SPI1 Baud Rate Register
SPI1BR              equ       $00000072           ;*** SPI1BR - SPI1 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI1BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI1BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI1BR_SPR3         equ       3                   ; SPI Baud Rate Divisor Bit 3
SPI1BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2        equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0        equ       %00000001
mSPI1BR_SPR1        equ       %00000010
mSPI1BR_SPR2        equ       %00000100
mSPI1BR_SPR3        equ       %00001000
mSPI1BR_SPPR0       equ       %00010000
mSPI1BR_SPPR1       equ       %00100000
mSPI1BR_SPPR2       equ       %01000000


;*** SPI1S - SPI1 Status Register
SPI1S               equ       $00000073           ;*** SPI1S - SPI1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_RFIFOEF       equ       0                   ; SPI Read FIFO Empty Flag
SPI1S_TXFULLF       equ       1                   ; SPI Transmit FIFO Full Flag
SPI1S_TNEAREF       equ       2                   ; SPI Transmit FIFO Nearly Empty Flag
SPI1S_RNFULLF       equ       3                   ; SPI Receive FIFO Nearly Full Flag
SPI1S_MODF          equ       4                   ; Master Mode Fault Flag
SPI1S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI1S_SPMF          equ       6                   ; SPI Match Flag
SPI1S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_RFIFOEF      equ       %00000001
mSPI1S_TXFULLF      equ       %00000010
mSPI1S_TNEAREF      equ       %00000100
mSPI1S_RNFULLF      equ       %00001000
mSPI1S_MODF         equ       %00010000
mSPI1S_SPTEF        equ       %00100000
mSPI1S_SPMF         equ       %01000000
mSPI1S_SPRF         equ       %10000000


;*** SPI1D16 - SPI1 Data Register
SPI1D16             equ       $00000074           ;*** SPI1D16 - SPI1 Data Register


;*** SPI1DH - SPI1 Data Register High
SPI1DH              equ       $00000074           ;*** SPI1DH - SPI1 Data Register High


;*** SPI1DL - SPI1 Data Register Low
SPI1DL              equ       $00000075           ;*** SPI1DL - SPI1 Data Register Low


;*** SPI1D - SPI1 Data Register Low
SPI1D               equ       $00000075           ;*** SPI1D - SPI1 Data Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1D_Bit0          equ       0                   ; SPI Data Bit 0
SPI1D_Bit1          equ       1                   ; SPI Data Bit 1
SPI1D_Bit2          equ       2                   ; SPI Data Bit 2
SPI1D_Bit3          equ       3                   ; SPI Data Bit 3
SPI1D_Bit4          equ       4                   ; SPI Data Bit 4
SPI1D_Bit5          equ       5                   ; SPI Data Bit 5
SPI1D_Bit6          equ       6                   ; SPI Data Bit 6
SPI1D_Bit7          equ       7                   ; SPI Data Bit 7
; bit position masks
mSPI1D_Bit0         equ       %00000001
mSPI1D_Bit1         equ       %00000010
mSPI1D_Bit2         equ       %00000100
mSPI1D_Bit3         equ       %00001000
mSPI1D_Bit4         equ       %00010000
mSPI1D_Bit5         equ       %00100000
mSPI1D_Bit6         equ       %01000000
mSPI1D_Bit7         equ       %10000000


;*** SPI1M - SPI1 Match Register
SPI1M               equ       $00000076           ;*** SPI1M - SPI1 Match Register


;*** SPI1MH - SPI1 Match Register High
SPI1MH              equ       $00000076           ;*** SPI1MH - SPI1 Match Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1MH_Bit8         equ       0                   ; SPI Match Value Bit 8
SPI1MH_Bit9         equ       1                   ; SPI Match Value Bit 9
SPI1MH_Bit10        equ       2                   ; SPI Match Value Bit 10
SPI1MH_Bit11        equ       3                   ; SPI Match Value Bit 11
SPI1MH_Bit12        equ       4                   ; SPI Match Value Bit 12
SPI1MH_Bit13        equ       5                   ; SPI Match Value Bit 13
SPI1MH_Bit14        equ       6                   ; SPI Match Value Bit 14
SPI1MH_Bit15        equ       7                   ; SPI Match Value Bit 15
; bit position masks
mSPI1MH_Bit8        equ       %00000001
mSPI1MH_Bit9        equ       %00000010
mSPI1MH_Bit10       equ       %00000100
mSPI1MH_Bit11       equ       %00001000
mSPI1MH_Bit12       equ       %00010000
mSPI1MH_Bit13       equ       %00100000
mSPI1MH_Bit14       equ       %01000000
mSPI1MH_Bit15       equ       %10000000


;*** SPI1ML - SPI1 Match Register Low
SPI1ML              equ       $00000077           ;*** SPI1ML - SPI1 Match Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1ML_Bit0         equ       0                   ; SPI Match Value Bit 0
SPI1ML_Bit1         equ       1                   ; SPI Match Value Bit 1
SPI1ML_Bit2         equ       2                   ; SPI Match Value Bit 2
SPI1ML_Bit3         equ       3                   ; SPI Match Value Bit 3
SPI1ML_Bit4         equ       4                   ; SPI Match Value Bit 4
SPI1ML_Bit5         equ       5                   ; SPI Match Value Bit 5
SPI1ML_Bit6         equ       6                   ; SPI Match Value Bit 6
SPI1ML_Bit7         equ       7                   ; SPI Match Value Bit 7
; bit position masks
mSPI1ML_Bit0        equ       %00000001
mSPI1ML_Bit1        equ       %00000010
mSPI1ML_Bit2        equ       %00000100
mSPI1ML_Bit3        equ       %00001000
mSPI1ML_Bit4        equ       %00010000
mSPI1ML_Bit5        equ       %00100000
mSPI1ML_Bit6        equ       %01000000
mSPI1ML_Bit7        equ       %10000000


;*** SPI1C3 - SPI1 Control Register 3
SPI1C3              equ       $00000078           ;*** SPI1C3 - SPI1 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C3_FIFOMODE     equ       0                   ; SPI FIFO Mode Enable
SPI1C3_RNFULLIEN    equ       1                   ; Receive FIFO Nearly Full Interrupt Enable. This is an additional interrupt on the SPI and will
SPI1C3_TNEARIEN     equ       2                   ; Transmit FIFO Nearly Empty Interrupt Enable. This is an additional interrupt on the SPI and will
SPI1C3_INTCLR       equ       3                   ; Interrupt Clearing Mechanism Select - This bit selects the mechanism by which SPRF, SPTEF, TNEAREF, RNFULLF
SPI1C3_RNFULLF_MARK equ       4                   ; Receive FIFO Nearly Full Water Mark - This bit selects the mark for which RNFULLF flag
SPI1C3_TNEAREF_MARK equ       5                   ; Transmit FIFO Nearly Empty Water Mark - This bit selects the mark after which TNEAREF flag
; bit position masks
mSPI1C3_FIFOMODE    equ       %00000001
mSPI1C3_RNFULLIEN   equ       %00000010
mSPI1C3_TNEARIEN    equ       %00000100
mSPI1C3_INTCLR      equ       %00001000
mSPI1C3_RNFULLF_MARK equ       %00010000
mSPI1C3_TNEAREF_MARK equ       %00100000


;*** SPI1CI - SPI1 Clear Interrupt Register
SPI1CI              equ       $00000079           ;*** SPI1CI - SPI1 Clear Interrupt Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1CI_SPRFCI       equ       0                   ; Receive FIFO Full Flag Clear Interrupt Bit - Write of 1 clears the TNEAREF interrupt provided
SPI1CI_SPTEFCI      equ       1                   ; Transmit FIFO Empty Flag Clear Interrupt Bit - Write of 1 clears the SPTEF interrupt provided
SPI1CI_RNFULLFCI    equ       2                   ; Receive FIFO Nearly Full Flag Clear Interrupt - Write of 1 clears the RNFULLF interrupt provided
SPI1CI_TNEAREFCI    equ       3                   ; Transmit FIFO Nearly Empty Flag Clear Interrupt Bit - Write of 1 clears the TNEAREF interrupt
SPI1CI_RXFOF        equ       4                   ; RX FIFO Overflow Flag - This Flag indicates that RX FIFO overflow condition has occured
SPI1CI_TXFOF        equ       5                   ; TX FIFO Overflow Flag - This Flag indicates that TX FIFO overflow condition has occured
SPI1CI_RXFERR       equ       6                   ; Receive FIFO Error Flag - This flag indicates that RX FIFO error occured because entries in
SPI1CI_TXFERR       equ       7                   ; Transmit FIFO ErrorFlag - This flag indicates that TX FIFO error occured because entries in fifo
; bit position masks
mSPI1CI_SPRFCI      equ       %00000001
mSPI1CI_SPTEFCI     equ       %00000010
mSPI1CI_RNFULLFCI   equ       %00000100
mSPI1CI_TNEAREFCI   equ       %00001000
mSPI1CI_RXFOF       equ       %00010000
mSPI1CI_TXFOF       equ       %00100000
mSPI1CI_RXFERR      equ       %01000000
mSPI1CI_TXFERR      equ       %10000000


;*** KBI2SC - KBI2 Status and Control Register
KBI2SC              equ       $0000007C           ;*** KBI2SC - KBI2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2SC_KBI2MOD      equ       0                   ; Keyboard Detection Mode
KBI2SC_KB2IE        equ       1                   ; Keyboard Interrupt Enable
KBI2SC_KB2ACK       equ       2                   ; Keyboard Interrupt Acknowledge
KBI2SC_KB2F         equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI2SC_KBI2MOD     equ       %00000001
mKBI2SC_KB2IE       equ       %00000010
mKBI2SC_KB2ACK      equ       %00000100
mKBI2SC_KB2F        equ       %00001000


;*** KBI2PE - KBI2 Pin Enable Register
KBI2PE              equ       $0000007D           ;*** KBI2PE - KBI2 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2PE_KBI2PE0      equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI2PE_KBI2PE1      equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI2PE_KBI2PE2      equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI2PE_KBI2PE3      equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBI2PE_KBI2PE4      equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBI2PE_KBI2PE5      equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBI2PE_KBI2PE6      equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBI2PE_KBI2PE7      equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI2PE_KBI2PE0     equ       %00000001
mKBI2PE_KBI2PE1     equ       %00000010
mKBI2PE_KBI2PE2     equ       %00000100
mKBI2PE_KBI2PE3     equ       %00001000
mKBI2PE_KBI2PE4     equ       %00010000
mKBI2PE_KBI2PE5     equ       %00100000
mKBI2PE_KBI2PE6     equ       %01000000
mKBI2PE_KBI2PE7     equ       %10000000


;*** KBI2ES - KBI2 Edge Select Register
KBI2ES              equ       $0000007E           ;*** KBI2ES - KBI2 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2ES_KB2EDG0      equ       0                   ; Keyboard Edge Select Bit 0
KBI2ES_KB2EDG1      equ       1                   ; Keyboard Edge Select Bit 1
KBI2ES_KB2EDG2      equ       2                   ; Keyboard Edge Select Bit 2
KBI2ES_KB2EDG3      equ       3                   ; Keyboard Edge Select Bit 3
KBI2ES_KB2EDG4      equ       4                   ; Keyboard Edge Select Bit 4
KBI2ES_KB2EDG5      equ       5                   ; Keyboard Edge Select Bit 5
KBI2ES_KB2EDG6      equ       6                   ; Keyboard Edge Select Bit 6
KBI2ES_KB2EDG7      equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBI2ES_KB2EDG0     equ       %00000001
mKBI2ES_KB2EDG1     equ       %00000010
mKBI2ES_KB2EDG2     equ       %00000100
mKBI2ES_KB2EDG3     equ       %00001000
mKBI2ES_KB2EDG4     equ       %00010000
mKBI2ES_KB2EDG5     equ       %00100000
mKBI2ES_KB2EDG6     equ       %01000000
mKBI2ES_KB2EDG7     equ       %10000000


;*** USBCTL0 - USB Control Register 0
USBCTL0             equ       $00000080           ;*** USBCTL0 - USB Control Register 0
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
PERID               equ       $00000088           ;*** PERID - Peripheral ID Register
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
IDCOMP              equ       $00000089           ;*** IDCOMP - Peripheral ID Complement Register
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
REV                 equ       $0000008A           ;*** REV - Peripheral Revision Register
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
INTSTAT             equ       $00000090           ;*** INTSTAT - Interrupt Status Register
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
INTENB              equ       $00000091           ;*** INTENB - Interrupt Enable Register
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
ERRSTAT             equ       $00000092           ;*** ERRSTAT - Error Interrupt Status Register
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
ERRENB              equ       $00000093           ;*** ERRENB - Error Interrupt Enable Register
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
STAT                equ       $00000094           ;*** STAT - Status Register
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
CTL                 equ       $00000095           ;*** CTL - Control Register
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
ADDR                equ       $00000096           ;*** ADDR - Address Register
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
FRMNUML             equ       $00000097           ;*** FRMNUML - Frame Number Register Low
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
FRMNUMH             equ       $00000098           ;*** FRMNUMH - Frame Number Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FRMNUMH_FRM8        equ       0                   ; Frame Number Bit 8
FRMNUMH_FRM9        equ       1                   ; Frame Number Bit 9
FRMNUMH_FRM10       equ       2                   ; Frame Number Bit 10
; bit position masks
mFRMNUMH_FRM8       equ       %00000001
mFRMNUMH_FRM9       equ       %00000010
mFRMNUMH_FRM10      equ       %00000100


;*** EPCTL0 - Endpoint Control Register 0
EPCTL0              equ       $0000009D           ;*** EPCTL0 - Endpoint Control Register 0
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
EPCTL1              equ       $0000009E           ;*** EPCTL1 - Endpoint Control Register 1
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
EPCTL2              equ       $0000009F           ;*** EPCTL2 - Endpoint Control Register 2
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
EPCTL3              equ       $000000A0           ;*** EPCTL3 - Endpoint Control Register 3
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
EPCTL4              equ       $000000A1           ;*** EPCTL4 - Endpoint Control Register 4
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
EPCTL5              equ       $000000A2           ;*** EPCTL5 - Endpoint Control Register 5
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
EPCTL6              equ       $000000A3           ;*** EPCTL6 - Endpoint Control Register 6
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
SOPT1_BLMSS         equ       3                   ; Boot Loader Mode Select Status
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT0         equ       6                   ; COP Watchdog Timeout, bit 0
SOPT1_COPT1         equ       7                   ; COP Watchdog Timeout, bit 1
; bit position masks
mSOPT1_RSTPE        equ       %00000001
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_BLMSS        equ       %00001000
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT0        equ       %01000000
mSOPT1_COPT1        equ       %10000000


;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_ACIC          equ       0                   ; Analog Comparator to Input Capture Enable
SOPT2_CLKOUT_EN     equ       4                   ; Clock Output Enable
SOPT2_COPW          equ       6                   ; COP Window
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_ACIC         equ       %00000001
mSOPT2_CLKOUT_EN    equ       %00010000
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


;*** SCGC1 - System Clock Gating Control 1 Register
SCGC1               equ       $00001808           ;*** SCGC1 - System Clock Gating Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI1          equ       0                   ; SCI1 Clock Gate Control
SCGC1_SCI2          equ       1                   ; SCI2 Clock Gate Control
SCGC1_IIC           equ       2                   ; IIC Clock Gate Control
SCGC1_DAC           equ       3                   ; DAC Clock Gate Control
SCGC1_ADC           equ       4                   ; ADC Clock Gate Control
SCGC1_TPM1          equ       5                   ; TPM1 Clock Gate Control
SCGC1_TPM2          equ       6                   ; TPM2 Clock Gate Control
SCGC1_CMT           equ       7                   ; CMT Clock Gate Control
; bit position masks
mSCGC1_SCI1         equ       %00000001
mSCGC1_SCI2         equ       %00000010
mSCGC1_IIC          equ       %00000100
mSCGC1_DAC          equ       %00001000
mSCGC1_ADC          equ       %00010000
mSCGC1_TPM1         equ       %00100000
mSCGC1_TPM2         equ       %01000000
mSCGC1_CMT          equ       %10000000


;*** SCGC2 - System Clock Gating Control 2 Register
SCGC2               equ       $00001809           ;*** SCGC2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI1          equ       0                   ; SPI1 Clock Gate Control
SCGC2_SPI2          equ       1                   ; SPI2 Clock Gate Control
SCGC2_TOD           equ       2                   ; TOD Clock Gate Control
SCGC2_PRACMP        equ       3                   ; PRACMP Clock Gate Control
SCGC2_KBI           equ       4                   ; KBI Clock Gate Control
SCGC2_IRQ           equ       5                   ; IRQ Clock Gate Control
SCGC2_PDB           equ       6                   ; PDB Register Clock Gate Control
SCGC2_USB           equ       7                   ; USB Clock Gate Control
; bit position masks
mSCGC2_SPI1         equ       %00000001
mSCGC2_SPI2         equ       %00000010
mSCGC2_TOD          equ       %00000100
mSCGC2_PRACMP       equ       %00001000
mSCGC2_KBI          equ       %00010000
mSCGC2_IRQ          equ       %00100000
mSCGC2_PDB          equ       %01000000
mSCGC2_USB          equ       %10000000


;*** SCGC3 - System Clock Gating Control 3 Register
SCGC3               equ       $0000180A           ;*** SCGC3 - System Clock Gating Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC3_GPOA1         equ       0                   ; GPOA1 Clock Gate Control
SCGC3_GPOA2         equ       1                   ; GPOA2 Clock Gate Control
SCGC3_TRIAMP1       equ       2                   ; TRIAMP1 Clock Gate Control
SCGC3_TRIAMP2       equ       3                   ; TRIAMP2 Clock Gate Control
SCGC3_FLS1          equ       4                   ; FLS1 Clock Gate Control
SCGC3_CRC           equ       6                   ; CRC Clock Gate Control
SCGC3_VREF          equ       7                   ; VREF Clock Gate Control
; bit position masks
mSCGC3_GPOA1        equ       %00000001
mSCGC3_GPOA2        equ       %00000010
mSCGC3_TRIAMP1      equ       %00000100
mSCGC3_TRIAMP2      equ       %00001000
mSCGC3_FLS1         equ       %00010000
mSCGC3_CRC          equ       %01000000
mSCGC3_VREF         equ       %10000000


;*** SOPT3 - System Options 3 Register
SOPT3               equ       $0000180B           ;*** SOPT3 - System Options 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT3_CMT_PAD       equ       0                   ; CMT pad drive strength
SOPT3_SCI1_PAD      equ       1                   ; SCI_PAD pad drive strength
SOPT3_IICPS         equ       5                   ; IIC Pin Select
SOPT3_SCI1PS        equ       6                   ; SCI1 Pin Select
SOPT3_SCI2PS        equ       7                   ; SCI2 Pin Select
; bit position masks
mSOPT3_CMT_PAD      equ       %00000001
mSOPT3_SCI1_PAD     equ       %00000010
mSOPT3_IICPS        equ       %00100000
mSOPT3_SCI1PS       equ       %01000000
mSOPT3_SCI2PS       equ       %10000000


;*** SOPT4 - System Options 4 Register
SOPT4               equ       $0000180C           ;*** SOPT4 - System Options 4 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT4_IRODSE        equ       0                   ; Drive Strength Control Enable for IRO pin
SOPT4_IROSRE        equ       1                   ; Output Slew Rate Control Enable for IRO pin
; bit position masks
mSOPT4_IRODSE       equ       %00000001
mSOPT4_IROSRE       equ       %00000010


;*** SIMIPS - SIM Internal Peripheral Select Register
SIMIPS              equ       $0000180E           ;*** SIMIPS - SIM Internal Peripheral Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS_MODTX1       equ       0                   ; Modulate TX1
SIMIPS_MTBASE10     equ       2                   ; SCI1 TX Modulation Time Base Select, bit 0
SIMIPS_MTBASE11     equ       3                   ; SCI1 TX Modulation Time Base Select, bit 1
SIMIPS_RX1IN        equ       6                   ; SCI1 RX Input Pin Select
SIMIPS_ADCTRS       equ       7                   ; ADC HWTRG Select
; bit position masks
mSIMIPS_MODTX1      equ       %00000001
mSIMIPS_MTBASE10    equ       %00000100
mSIMIPS_MTBASE11    equ       %00001000
mSIMIPS_RX1IN       equ       %01000000
mSIMIPS_ADCTRS      equ       %10000000


;*** SIGNATURE - SIGNATURE Register
SIGNATURE           equ       $0000180F           ;*** SIGNATURE - SIGNATURE Register


;*** CCSCTRL - Clock Check & Select Control
CCSCTRL             equ       $00001810           ;*** CCSCTRL - Clock Check & Select Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSCTRL_SEL         equ       0                   ; External Clock Select
CCSCTRL_TEST        equ       1                   ; TEST
CCSCTRL_EN          equ       2                   ; Enable clock for CCS
CCSCTRL_EREFS1      equ       3                   ; External Reference Select
CCSCTRL_OSCINIT1    equ       4                   ; Oscillator Initialization
CCSCTRL_ERCLKEN1    equ       5                   ; External Clock Enable
CCSCTRL_HGO1        equ       6                   ; High-Gain Oscillator Select
CCSCTRL_RANGE1      equ       7                   ; Frequency Range Select
; bit position masks
mCCSCTRL_SEL        equ       %00000001
mCCSCTRL_TEST       equ       %00000010
mCCSCTRL_EN         equ       %00000100
mCCSCTRL_EREFS1     equ       %00001000
mCCSCTRL_OSCINIT1   equ       %00010000
mCCSCTRL_ERCLKEN1   equ       %00100000
mCCSCTRL_HGO1       equ       %01000000
mCCSCTRL_RANGE1     equ       %10000000


;*** CCSTMR1 - CCS XOSC1 Timer Register
CCSTMR1             equ       $00001811           ;*** CCSTMR1 - CCS XOSC1 Timer Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSTMR1_CNT10       equ       0                   ; CNT1, bit 0
CCSTMR1_CNT11       equ       1                   ; CNT1, bit 1
CCSTMR1_CNT12       equ       2                   ; CNT1, bit 2
CCSTMR1_CNT13       equ       3                   ; CNT1, bit 3
CCSTMR1_CNT14       equ       4                   ; CNT1, bit 4
CCSTMR1_CNT15       equ       5                   ; CNT1, bit 5
CCSTMR1_CNT16       equ       6                   ; CNT1, bit 6
CCSTMR1_CNT17       equ       7                   ; CNT1, bit 7
; bit position masks
mCCSTMR1_CNT10      equ       %00000001
mCCSTMR1_CNT11      equ       %00000010
mCCSTMR1_CNT12      equ       %00000100
mCCSTMR1_CNT13      equ       %00001000
mCCSTMR1_CNT14      equ       %00010000
mCCSTMR1_CNT15      equ       %00100000
mCCSTMR1_CNT16      equ       %01000000
mCCSTMR1_CNT17      equ       %10000000


;*** CCSTMR2 - CCS XOSC2 Timer Register
CCSTMR2             equ       $00001812           ;*** CCSTMR2 - CCS XOSC2 Timer Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSTMR2_CNT20       equ       0                   ; CNT2, bit 0
CCSTMR2_CNT21       equ       1                   ; CNT2, bit 1
CCSTMR2_CNT22       equ       2                   ; CNT2, bit 2
CCSTMR2_CNT23       equ       3                   ; CNT2, bit 3
CCSTMR2_CNT24       equ       4                   ; CNT2, bit 4
CCSTMR2_CNT25       equ       5                   ; CNT2, bit 5
CCSTMR2_CNT26       equ       6                   ; CNT2, bit 6
CCSTMR2_CNT27       equ       7                   ; CNT2, bit 7
; bit position masks
mCCSTMR2_CNT20      equ       %00000001
mCCSTMR2_CNT21      equ       %00000010
mCCSTMR2_CNT22      equ       %00000100
mCCSTMR2_CNT23      equ       %00001000
mCCSTMR2_CNT24      equ       %00010000
mCCSTMR2_CNT25      equ       %00100000
mCCSTMR2_CNT26      equ       %01000000
mCCSTMR2_CNT27      equ       %10000000


;*** CCSTMRIR - CCS Internal Reference Clock Timer Register
CCSTMRIR            equ       $00001813           ;*** CCSTMRIR - CCS Internal Reference Clock Timer Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSTMRIR_CNTIR0     equ       0                   ; CNTIR, bit 0
CCSTMRIR_CNTIR1     equ       1                   ; CNTIR, bit 1
CCSTMRIR_CNTIR2     equ       2                   ; CNTIR, bit 2
CCSTMRIR_CNTIR3     equ       3                   ; CNTIR, bit 3
CCSTMRIR_CNTIR4     equ       4                   ; CNTIR, bit 4
CCSTMRIR_CNTIR5     equ       5                   ; CNTIR, bit 5
CCSTMRIR_CNTIR6     equ       6                   ; CNTIR, bit 6
CCSTMRIR_CNTIR7     equ       7                   ; CNTIR, bit 7
; bit position masks
mCCSTMRIR_CNTIR0    equ       %00000001
mCCSTMRIR_CNTIR1    equ       %00000010
mCCSTMRIR_CNTIR2    equ       %00000100
mCCSTMRIR_CNTIR3    equ       %00001000
mCCSTMRIR_CNTIR4    equ       %00010000
mCCSTMRIR_CNTIR5    equ       %00100000
mCCSTMRIR_CNTIR6    equ       %01000000
mCCSTMRIR_CNTIR7    equ       %10000000


;*** FPROTD - Flash Protection Disable Register
FPROTD              equ       $00001814           ;*** FPROTD - Flash Protection Disable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROTD_FPDIS        equ       0                   ; Disable Flash protection
; bit position masks
mFPROTD_FPDIS       equ       %00000001


;*** SIMCO - SIM Clock Set and Select Register
SIMCO               equ       $00001819           ;*** SIMCO - SIM Clock Set and Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMCO_CS0           equ       0                   ; CLKOUT Select, bit 0
SIMCO_CS1           equ       1                   ; CLKOUT Select, bit 1
SIMCO_CS2           equ       2                   ; CLKOUT Select, bit 2
; bit position masks
mSIMCO_CS0          equ       %00000001
mSIMCO_CS1          equ       %00000010
mSIMCO_CS2          equ       %00000100


;*** SPMSC1 - System Power Management Status and Control 1 Register
SPMSC1              equ       $0000181C           ;*** SPMSC1 - System Power Management Status and Control 1 Register
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
SPMSC2              equ       $0000181D           ;*** SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC         equ       0                   ; Partial Power Down Control
SPMSC2_PPDE         equ       1                   ; Partial Power-Down Enable
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowledge
SPMSC2_PPDF         equ       3                   ; Partial Power Down Flag
SPMSC2_LPWUI        equ       5                   ; Low Power Wake Up on Interrupt
SPMSC2_LPRS         equ       6                   ; Low Power Regulator Status
SPMSC2_LPR          equ       7                   ; Low Power Regulator Control
; bit position masks
mSPMSC2_PPDC        equ       %00000001
mSPMSC2_PPDE        equ       %00000010
mSPMSC2_PPDACK      equ       %00000100
mSPMSC2_PPDF        equ       %00001000
mSPMSC2_LPWUI       equ       %00100000
mSPMSC2_LPRS        equ       %01000000
mSPMSC2_LPR         equ       %10000000


;*** SPMSC3 - System Power Management Status and Control 3 Register
SPMSC3              equ       $0000181F           ;*** SPMSC3 - System Power Management Status and Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC3_LVWIE        equ       3                   ; Low-Voltage Warning Interrupt Enable
SPMSC3_LVWV         equ       4                   ; Low-Voltage Warning Voltage Select
SPMSC3_LVDV         equ       5                   ; Low-Voltage Detect Voltage Select
SPMSC3_LVWACK       equ       6                   ; Low-Voltage Warning Acknowledge
SPMSC3_LVWF         equ       7                   ; Low-Voltage Warning Flag
; bit position masks
mSPMSC3_LVWIE       equ       %00001000
mSPMSC3_LVWV        equ       %00010000
mSPMSC3_LVDV        equ       %00100000
mSPMSC3_LVWACK      equ       %01000000
mSPMSC3_LVWF        equ       %10000000


;*** FCDIV - FLASH Clock Divider Register
FCDIV               equ       $00001820           ;*** FCDIV - FLASH Clock Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCDIV_FDIV0         equ       0                   ; Divisor for FLASH Clock Divider, bit 0
FCDIV_FDIV1         equ       1                   ; Divisor for FLASH Clock Divider, bit 1
FCDIV_FDIV2         equ       2                   ; Divisor for FLASH Clock Divider, bit 2
FCDIV_FDIV3         equ       3                   ; Divisor for FLASH Clock Divider, bit 3
FCDIV_FDIV4         equ       4                   ; Divisor for FLASH Clock Divider, bit 4
FCDIV_FDIV5         equ       5                   ; Divisor for FLASH Clock Divider, bit 5
FCDIV_PRDIV8        equ       6                   ; Prescale (Divide) FLASH Clock by 8
FCDIV_FDIVLD        equ       7                   ; Divisor Loaded Status Flag
; bit position masks
mFCDIV_FDIV0        equ       %00000001
mFCDIV_FDIV1        equ       %00000010
mFCDIV_FDIV2        equ       %00000100
mFCDIV_FDIV3        equ       %00001000
mFCDIV_FDIV4        equ       %00010000
mFCDIV_FDIV5        equ       %00100000
mFCDIV_PRDIV8       equ       %01000000
mFCDIV_FDIVLD       equ       %10000000


;*** FOPT - Flash Options Register
FOPT                equ       $00001821           ;*** FOPT - Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SEC0           equ       0                   ; Flash Security Bit 0
FOPT_SEC1           equ       1                   ; Flash Security Bit 1
FOPT_KEYEN0         equ       6                   ; Backdoor Key Security Enable Bit 0
FOPT_KEYEN1         equ       7                   ; Backdoor Key Security Enable Bit 1
; bit position masks
mFOPT_SEC0          equ       %00000001
mFOPT_SEC1          equ       %00000010
mFOPT_KEYEN0        equ       %01000000
mFOPT_KEYEN1        equ       %10000000


;*** FCNFG - Flash Configuration Register
FCNFG               equ       $00001823           ;*** FCNFG - Flash Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC        equ       5                   ; Enable Security Key Writing
; bit position masks
mFCNFG_KEYACC       equ       %00100000


;*** FPROT - Flash Protection Register
FPROT               equ       $00001824           ;*** FPROT - Flash Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPOPEN        equ       0                   ; Flash Protection Open
FPROT_FPS0          equ       1                   ; Flash Protection Size, bit 0
FPROT_FPS1          equ       2                   ; Flash Protection Size, bit 1
FPROT_FPS2          equ       3                   ; Flash Protection Size, bit 2
FPROT_FPS3          equ       4                   ; Flash Protection Size, bit 3
FPROT_FPS4          equ       5                   ; Flash Protection Size, bit 4
FPROT_FPS5          equ       6                   ; Flash Protection Size, bit 5
FPROT_FPS6          equ       7                   ; Flash Protection Size, bit 6
; bit position masks
mFPROT_FPOPEN       equ       %00000001
mFPROT_FPS0         equ       %00000010
mFPROT_FPS1         equ       %00000100
mFPROT_FPS2         equ       %00001000
mFPROT_FPS3         equ       %00010000
mFPROT_FPS4         equ       %00100000
mFPROT_FPS5         equ       %01000000
mFPROT_FPS6         equ       %10000000


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


;*** FCMD - Flash Command Register
FCMD                equ       $00001826           ;*** FCMD - Flash Command Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCMD_FCMD0          equ       0                   ; Flash Command, bit 0
FCMD_FCMD1          equ       1                   ; Flash Command, bit 1
FCMD_FCMD2          equ       2                   ; Flash Command, bit 2
FCMD_FCMD3          equ       3                   ; Flash Command, bit 3
FCMD_FCMD4          equ       4                   ; Flash Command, bit 4
FCMD_FCMD5          equ       5                   ; Flash Command, bit 5
FCMD_FCMD6          equ       6                   ; Flash Command, bit 6
; bit position masks
mFCMD_FCMD0         equ       %00000001
mFCMD_FCMD1         equ       %00000010
mFCMD_FCMD2         equ       %00000100
mFCMD_FCMD3         equ       %00001000
mFCMD_FCMD4         equ       %00010000
mFCMD_FCMD5         equ       %00100000
mFCMD_FCMD6         equ       %01000000


;*** PTED - Port E Data Register
PTED                equ       $00001830           ;*** PTED - Port E Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTED_PTED0          equ       0                   ; Port E Data Register Bit 0
PTED_PTED1          equ       1                   ; Port E Data Register Bit 1
PTED_PTED2          equ       2                   ; Port E Data Register Bit 2
PTED_PTED3          equ       3                   ; Port E Data Register Bit 3
PTED_PTED4          equ       4                   ; Port E Data Register Bit 4
PTED_PTED5          equ       5                   ; Port E Data Register Bit 5
PTED_PTED6          equ       6                   ; Port E Data Register Bit 6
PTED_PTED7          equ       7                   ; Port E Data Register Bit 7
; bit position masks
mPTED_PTED0         equ       %00000001
mPTED_PTED1         equ       %00000010
mPTED_PTED2         equ       %00000100
mPTED_PTED3         equ       %00001000
mPTED_PTED4         equ       %00010000
mPTED_PTED5         equ       %00100000
mPTED_PTED6         equ       %01000000
mPTED_PTED7         equ       %10000000


;*** PTEDD - Port E Data Direction Register
PTEDD               equ       $00001831           ;*** PTEDD - Port E Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0        equ       0                   ; Data Direction for Port E Bit 0
PTEDD_PTEDD1        equ       1                   ; Data Direction for Port E Bit 1
PTEDD_PTEDD2        equ       2                   ; Data Direction for Port E Bit 2
PTEDD_PTEDD3        equ       3                   ; Data Direction for Port E Bit 3
PTEDD_PTEDD5        equ       5                   ; Data Direction for Port E Bit 5
PTEDD_PTEDD6        equ       6                   ; Data Direction for Port E Bit 6
PTEDD_PTEDD7        equ       7                   ; Data Direction for Port E Bit 7
; bit position masks
mPTEDD_PTEDD0       equ       %00000001
mPTEDD_PTEDD1       equ       %00000010
mPTEDD_PTEDD2       equ       %00000100
mPTEDD_PTEDD3       equ       %00001000
mPTEDD_PTEDD5       equ       %00100000
mPTEDD_PTEDD6       equ       %01000000
mPTEDD_PTEDD7       equ       %10000000


;*** PTFD - Port F Data Register
PTFD                equ       $00001832           ;*** PTFD - Port F Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFD_PTFD0          equ       0                   ; Port F Data Register Bit 0
PTFD_PTFD1          equ       1                   ; Port F Data Register Bit 1
PTFD_PTFD2          equ       2                   ; Port F Data Register Bit 2
PTFD_PTFD3          equ       3                   ; Port F Data Register Bit 3
PTFD_PTFD4          equ       4                   ; Port F Data Register Bit 4
PTFD_PTFD5          equ       5                   ; Port F Data Register Bit 5
PTFD_PTFD6          equ       6                   ; Port F Data Register Bit 6
PTFD_PTFD7          equ       7                   ; Port F Data Register Bit 7
; bit position masks
mPTFD_PTFD0         equ       %00000001
mPTFD_PTFD1         equ       %00000010
mPTFD_PTFD2         equ       %00000100
mPTFD_PTFD3         equ       %00001000
mPTFD_PTFD4         equ       %00010000
mPTFD_PTFD5         equ       %00100000
mPTFD_PTFD6         equ       %01000000
mPTFD_PTFD7         equ       %10000000


;*** PTFDD - Port F Data Direction Register
PTFDD               equ       $00001833           ;*** PTFDD - Port F Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDD_PTFDD0        equ       0                   ; Data Direction for Port F Bit 0
PTFDD_PTFDD1        equ       1                   ; Data Direction for Port F Bit 1
PTFDD_PTFDD2        equ       2                   ; Data Direction for Port F Bit 2
PTFDD_PTFDD3        equ       3                   ; Data Direction for Port F Bit 3
PTFDD_PTFDD4        equ       4                   ; Data Direction for Port F Bit 4
PTFDD_PTFDD5        equ       5                   ; Data Direction for Port F Bit 5
PTFDD_PTFDD6        equ       6                   ; Data Direction for Port F Bit 6
PTFDD_PTFDD7        equ       7                   ; Data Direction for Port F Bit 7
; bit position masks
mPTFDD_PTFDD0       equ       %00000001
mPTFDD_PTFDD1       equ       %00000010
mPTFDD_PTFDD2       equ       %00000100
mPTFDD_PTFDD3       equ       %00001000
mPTFDD_PTFDD4       equ       %00010000
mPTFDD_PTFDD5       equ       %00100000
mPTFDD_PTFDD6       equ       %01000000
mPTFDD_PTFDD7       equ       %10000000


;*** SCI2BD - SCI2 Baud Rate Register
SCI2BD              equ       $00001838           ;*** SCI2BD - SCI2 Baud Rate Register


;*** SCI2BDH - SCI2 Baud Rate Register High
SCI2BDH             equ       $00001838           ;*** SCI2BDH - SCI2 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI2BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI2BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI2BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI2BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCI2BDH_RXEDGIE     equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI2BDH_LBKDIE      equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI2BDH_SBR8       equ       %00000001
mSCI2BDH_SBR9       equ       %00000010
mSCI2BDH_SBR10      equ       %00000100
mSCI2BDH_SBR11      equ       %00001000
mSCI2BDH_SBR12      equ       %00010000
mSCI2BDH_RXEDGIE    equ       %01000000
mSCI2BDH_LBKDIE     equ       %10000000


;*** SCI2BDL - SCI2 Baud Rate Register Low
SCI2BDL             equ       $00001839           ;*** SCI2BDL - SCI2 Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDL_SBR0        equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCI2BDL_SBR1        equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCI2BDL_SBR2        equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCI2BDL_SBR3        equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCI2BDL_SBR4        equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCI2BDL_SBR5        equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCI2BDL_SBR6        equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCI2BDL_SBR7        equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI2BDL_SBR0       equ       %00000001
mSCI2BDL_SBR1       equ       %00000010
mSCI2BDL_SBR2       equ       %00000100
mSCI2BDL_SBR3       equ       %00001000
mSCI2BDL_SBR4       equ       %00010000
mSCI2BDL_SBR5       equ       %00100000
mSCI2BDL_SBR6       equ       %01000000
mSCI2BDL_SBR7       equ       %10000000


;*** SCI2C1 - SCI2 Control Register 1
SCI2C1              equ       $0000183A           ;*** SCI2C1 - SCI2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C1_PT           equ       0                   ; Parity Type
SCI2C1_PE           equ       1                   ; Parity Enable
SCI2C1_ILT          equ       2                   ; Idle Line Type Select
SCI2C1_WAKE         equ       3                   ; Receiver Wakeup Method Select
SCI2C1_M            equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI2C1_RSRC         equ       5                   ; Receiver Source Select
SCI2C1_SCISWAI      equ       6                   ; SCI Stops in Wait Mode
SCI2C1_LOOPS        equ       7                   ; Loop Mode Select
; bit position masks
mSCI2C1_PT          equ       %00000001
mSCI2C1_PE          equ       %00000010
mSCI2C1_ILT         equ       %00000100
mSCI2C1_WAKE        equ       %00001000
mSCI2C1_M           equ       %00010000
mSCI2C1_RSRC        equ       %00100000
mSCI2C1_SCISWAI     equ       %01000000
mSCI2C1_LOOPS       equ       %10000000


;*** SCI2C2 - SCI2 Control Register 2
SCI2C2              equ       $0000183B           ;*** SCI2C2 - SCI2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C2_SBK          equ       0                   ; Send Break
SCI2C2_RWU          equ       1                   ; Receiver Wakeup Control
SCI2C2_RE           equ       2                   ; Receiver Enable
SCI2C2_TE           equ       3                   ; Transmitter Enable
SCI2C2_ILIE         equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCI2C2_RIE          equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCI2C2_TCIE         equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCI2C2_TIE          equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI2C2_SBK         equ       %00000001
mSCI2C2_RWU         equ       %00000010
mSCI2C2_RE          equ       %00000100
mSCI2C2_TE          equ       %00001000
mSCI2C2_ILIE        equ       %00010000
mSCI2C2_RIE         equ       %00100000
mSCI2C2_TCIE        equ       %01000000
mSCI2C2_TIE         equ       %10000000


;*** SCI2S1 - SCI2 Status Register 1
SCI2S1              equ       $0000183C           ;*** SCI2S1 - SCI2 Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S1_PF           equ       0                   ; Parity Error Flag
SCI2S1_FE           equ       1                   ; Framing Error Flag
SCI2S1_NF           equ       2                   ; Noise Flag
SCI2S1_OR           equ       3                   ; Receiver Overrun Flag
SCI2S1_IDLE         equ       4                   ; Idle Line Flag
SCI2S1_RDRF         equ       5                   ; Receive Data Register Full Flag
SCI2S1_TC           equ       6                   ; Transmission Complete Flag
SCI2S1_TDRE         equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI2S1_PF          equ       %00000001
mSCI2S1_FE          equ       %00000010
mSCI2S1_NF          equ       %00000100
mSCI2S1_OR          equ       %00001000
mSCI2S1_IDLE        equ       %00010000
mSCI2S1_RDRF        equ       %00100000
mSCI2S1_TC          equ       %01000000
mSCI2S1_TDRE        equ       %10000000


;*** SCI2S2 - SCI2 Status Register 2
SCI2S2              equ       $0000183D           ;*** SCI2S2 - SCI2 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S2_RAF          equ       0                   ; Receiver Active Flag
SCI2S2_LBKDE        equ       1                   ; LIN Break Detection Enable
SCI2S2_BRK13        equ       2                   ; Break Character Generation Length
SCI2S2_RWUID        equ       3                   ; Receive Wake Up Idle Detect
SCI2S2_RXINV        equ       4                   ; Receive Data Inversion
SCI2S2_RXEDGIF      equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI2S2_LBKDIF       equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI2S2_RAF         equ       %00000001
mSCI2S2_LBKDE       equ       %00000010
mSCI2S2_BRK13       equ       %00000100
mSCI2S2_RWUID       equ       %00001000
mSCI2S2_RXINV       equ       %00010000
mSCI2S2_RXEDGIF     equ       %01000000
mSCI2S2_LBKDIF      equ       %10000000


;*** SCI2C3 - SCI2 Control Register 3
SCI2C3              equ       $0000183E           ;*** SCI2C3 - SCI2 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI2C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI2C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI2C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI2C3_TXINV        equ       4                   ; Transmit Data Inversion
SCI2C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI2C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI2C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI2C3_PEIE        equ       %00000001
mSCI2C3_FEIE        equ       %00000010
mSCI2C3_NEIE        equ       %00000100
mSCI2C3_ORIE        equ       %00001000
mSCI2C3_TXINV       equ       %00010000
mSCI2C3_TXDIR       equ       %00100000
mSCI2C3_T8          equ       %01000000
mSCI2C3_R8          equ       %10000000


;*** SCI2D - SCI2 Data Register
SCI2D               equ       $0000183F           ;*** SCI2D - SCI2 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2D_R0_T0         equ       0                   ; Receive/Transmit Data Bit 0
SCI2D_R1_T1         equ       1                   ; Receive/Transmit Data Bit 1
SCI2D_R2_T2         equ       2                   ; Receive/Transmit Data Bit 2
SCI2D_R3_T3         equ       3                   ; Receive/Transmit Data Bit 3
SCI2D_R4_T4         equ       4                   ; Receive/Transmit Data Bit 4
SCI2D_R5_T5         equ       5                   ; Receive/Transmit Data Bit 5
SCI2D_R6_T6         equ       6                   ; Receive/Transmit Data Bit 6
SCI2D_R7_T7         equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCI2D_R0_T0        equ       %00000001
mSCI2D_R1_T1        equ       %00000010
mSCI2D_R2_T2        equ       %00000100
mSCI2D_R3_T3        equ       %00001000
mSCI2D_R4_T4        equ       %00010000
mSCI2D_R5_T5        equ       %00100000
mSCI2D_R6_T6        equ       %01000000
mSCI2D_R7_T7        equ       %10000000


;*** SPI2C1 - SPI2 Control Register 1
SPI2C1              equ       $00001840           ;*** SPI2C1 - SPI2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C1_LSBFE        equ       0                   ; LSB First (Shifter Direction)
SPI2C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI2C1_CPHA         equ       2                   ; Clock Phase
SPI2C1_CPOL         equ       3                   ; Clock Polarity
SPI2C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI2C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI2C1_SPE          equ       6                   ; SPI System Enable
SPI2C1_SPIE         equ       7                   ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI2C1_LSBFE       equ       %00000001
mSPI2C1_SSOE        equ       %00000010
mSPI2C1_CPHA        equ       %00000100
mSPI2C1_CPOL        equ       %00001000
mSPI2C1_MSTR        equ       %00010000
mSPI2C1_SPTIE       equ       %00100000
mSPI2C1_SPE         equ       %01000000
mSPI2C1_SPIE        equ       %10000000


;*** SPI2C2 - SPI2 Control Register 2
SPI2C2              equ       $00001841           ;*** SPI2C2 - SPI2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI2C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI2C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI2C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
SPI2C2_SPMIE        equ       7                   ; SPI Match Interrupt Enable
; bit position masks
mSPI2C2_SPC0        equ       %00000001
mSPI2C2_SPISWAI     equ       %00000010
mSPI2C2_BIDIROE     equ       %00001000
mSPI2C2_MODFEN      equ       %00010000
mSPI2C2_SPMIE       equ       %10000000


;*** SPI2BR - SPI2 Baud Rate Register
SPI2BR              equ       $00001842           ;*** SPI2BR - SPI2 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI2BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI2BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI2BR_SPR3         equ       3                   ; SPI Baud Rate Divisor Bit 3
SPI2BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI2BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI2BR_SPPR2        equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI2BR_SPR0        equ       %00000001
mSPI2BR_SPR1        equ       %00000010
mSPI2BR_SPR2        equ       %00000100
mSPI2BR_SPR3        equ       %00001000
mSPI2BR_SPPR0       equ       %00010000
mSPI2BR_SPPR1       equ       %00100000
mSPI2BR_SPPR2       equ       %01000000


;*** SPI2S - SPI2 Status Register
SPI2S               equ       $00001843           ;*** SPI2S - SPI2 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_MODF          equ       4                   ; Master Mode Fault Flag
SPI2S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI2S_SPMF          equ       6                   ; SPI Match Flag
SPI2S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI2S_MODF         equ       %00010000
mSPI2S_SPTEF        equ       %00100000
mSPI2S_SPMF         equ       %01000000
mSPI2S_SPRF         equ       %10000000


;*** SPI2D - SPI2 Data Register
SPI2D               equ       $00001845           ;*** SPI2D - SPI2 Data Register


;*** SPI2M - SPI2 Match Register
SPI2M               equ       $00001847           ;*** SPI2M - SPI2 Match Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2M_Bit0          equ       0                   ; SPI Match Value Bit 0
SPI2M_Bit1          equ       1                   ; SPI Match Value Bit 1
SPI2M_Bit2          equ       2                   ; SPI Match Value Bit 2
SPI2M_Bit3          equ       3                   ; SPI Match Value Bit 3
SPI2M_Bit4          equ       4                   ; SPI Match Value Bit 4
SPI2M_Bit5          equ       5                   ; SPI Match Value Bit 5
SPI2M_Bit6          equ       6                   ; SPI Match Value Bit 6
SPI2M_Bit7          equ       7                   ; SPI Match Value Bit 7
; bit position masks
mSPI2M_Bit0         equ       %00000001
mSPI2M_Bit1         equ       %00000010
mSPI2M_Bit2         equ       %00000100
mSPI2M_Bit3         equ       %00001000
mSPI2M_Bit4         equ       %00010000
mSPI2M_Bit5         equ       %00100000
mSPI2M_Bit6         equ       %01000000
mSPI2M_Bit7         equ       %10000000


;*** PTGD - Port G Data Register
PTGD                equ       $00001848           ;*** PTGD - Port G Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGD_PTGD0          equ       0                   ; Port G Data Register Bit 0
PTGD_PTGD1          equ       1                   ; Port G Data Register Bit 1
; bit position masks
mPTGD_PTGD0         equ       %00000001
mPTGD_PTGD1         equ       %00000010


;*** PTGDD - Port G Data Direction Register
PTGDD               equ       $00001849           ;*** PTGDD - Port G Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDD_PTGDD0        equ       0                   ; Data Direction for Port G Bit 0
PTGDD_PTGDD1        equ       1                   ; Data Direction for Port G Bit 1
; bit position masks
mPTGDD_PTGDD0       equ       %00000001
mPTGDD_PTGDD1       equ       %00000010


;*** PTAPE - Port A Pull Enable Register
PTAPE               equ       $00001850           ;*** PTAPE - Port A Pull Enable Register
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
PTASE               equ       $00001851           ;*** PTASE - Port A Slew Rate Enable Register
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
PTADS               equ       $00001852           ;*** PTADS - Port A Drive Strength Selection Register
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


;*** PTAIFE - Port A Input Filter Enable Register
PTAIFE              equ       $00001853           ;*** PTAIFE - Port A Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAIFE_PTAIFE0      equ       0                   ; Port A Input Filter Enable Bit 0
PTAIFE_PTAIFE1      equ       1                   ; Port A Input Filter Enable Bit 1
PTAIFE_PTAIFE2      equ       2                   ; Port A Input Filter Enable Bit 2
PTAIFE_PTAIFE3      equ       3                   ; Port A Input Filter Enable Bit 3
PTAIFE_PTAIFE4      equ       4                   ; Port A Input Filter Enable Bit 4
PTAIFE_PTAIFE5      equ       5                   ; Port A Input Filter Enable Bit 5
PTAIFE_PTAIFE6      equ       6                   ; Port A Input Filter Enable Bit 6
PTAIFE_PTAIFE7      equ       7                   ; Port A Input Filter Enable Bit 7
; bit position masks
mPTAIFE_PTAIFE0     equ       %00000001
mPTAIFE_PTAIFE1     equ       %00000010
mPTAIFE_PTAIFE2     equ       %00000100
mPTAIFE_PTAIFE3     equ       %00001000
mPTAIFE_PTAIFE4     equ       %00010000
mPTAIFE_PTAIFE5     equ       %00100000
mPTAIFE_PTAIFE6     equ       %01000000
mPTAIFE_PTAIFE7     equ       %10000000


;*** PTBPE - Port B Pull Enable Register
PTBPE               equ       $00001854           ;*** PTBPE - Port B Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Internal Pull Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Internal Pull Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Internal Pull Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Internal Pull Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Internal Pull Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Internal Pull Enable for Port B Bit 5
PTBPE_PTBPE6        equ       6                   ; Internal Pull Enable for Port B Bit 6
PTBPE_PTBPE7        equ       7                   ; Internal Pull Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000
mPTBPE_PTBPE6       equ       %01000000
mPTBPE_PTBPE7       equ       %10000000


;*** PTBSE - Port B Slew Rate Enable Register
PTBSE               equ       $00001855           ;*** PTBSE - Port B Slew Rate Enable Register
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


;*** PTBDS - Port B Drive Strength Selection Register
PTBDS               equ       $00001856           ;*** PTBDS - Port B Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS0        equ       0                   ; Output Drive Strength Selection for Port B Bit 0
PTBDS_PTBDS1        equ       1                   ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2        equ       2                   ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS3        equ       3                   ; Output Drive Strength Selection for Port B Bit 3
PTBDS_PTBDS4        equ       4                   ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5        equ       5                   ; Output Drive Strength Selection for Port B Bit 5
PTBDS_PTBDS6        equ       6                   ; Output Drive Strength Selection for Port B Bit 6
PTBDS_PTBDS7        equ       7                   ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTBDS_PTBDS0       equ       %00000001
mPTBDS_PTBDS1       equ       %00000010
mPTBDS_PTBDS2       equ       %00000100
mPTBDS_PTBDS3       equ       %00001000
mPTBDS_PTBDS4       equ       %00010000
mPTBDS_PTBDS5       equ       %00100000
mPTBDS_PTBDS6       equ       %01000000
mPTBDS_PTBDS7       equ       %10000000


;*** PTBIFE - Port B Input Filter Enable Register
PTBIFE              equ       $00001857           ;*** PTBIFE - Port B Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBIFE_PTBIFE0      equ       0                   ; Port B Input Filter Enable Bit 0
PTBIFE_PTBIFE1      equ       1                   ; Port B Input Filter Enable Bit 1
PTBIFE_PTBIFE2      equ       2                   ; Port B Input Filter Enable Bit 2
PTBIFE_PTBIFE3      equ       3                   ; Port B Input Filter Enable Bit 3
PTBIFE_PTBIFE4      equ       4                   ; Port B Input Filter Enable Bit 4
PTBIFE_PTBIFE5      equ       5                   ; Port B Input Filter Enable Bit 5
PTBIFE_PTBIFE6      equ       6                   ; Port B Input Filter Enable Bit 6
PTBIFE_PTBIFE7      equ       7                   ; Port B Input Filter Enable Bit 7
; bit position masks
mPTBIFE_PTBIFE0     equ       %00000001
mPTBIFE_PTBIFE1     equ       %00000010
mPTBIFE_PTBIFE2     equ       %00000100
mPTBIFE_PTBIFE3     equ       %00001000
mPTBIFE_PTBIFE4     equ       %00010000
mPTBIFE_PTBIFE5     equ       %00100000
mPTBIFE_PTBIFE6     equ       %01000000
mPTBIFE_PTBIFE7     equ       %10000000


;*** PTCPE - Port C Pull Enable Register
PTCPE               equ       $00001858           ;*** PTCPE - Port C Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Internal Pull Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Internal Pull Enable for Port C Bit 1
PTCPE_PTCPE2        equ       2                   ; Internal Pull Enable for Port C Bit 2
PTCPE_PTCPE3        equ       3                   ; Internal Pull Enable for Port C Bit 3
PTCPE_PTCPE4        equ       4                   ; Internal Pull Enable for Port C Bit 4
PTCPE_PTCPE5        equ       5                   ; Internal Pull Enable for Port C Bit 5
PTCPE_PTCPE6        equ       6                   ; Internal Pull Enable for Port C Bit 6
PTCPE_PTCPE7        equ       7                   ; Internal Pull Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000
mPTCPE_PTCPE6       equ       %01000000
mPTCPE_PTCPE7       equ       %10000000


;*** PTCSE - Port C Slew Rate Enable Register
PTCSE               equ       $00001859           ;*** PTCSE - Port C Slew Rate Enable Register
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


;*** PTCDS - Port C Drive Strength Selection Register
PTCDS               equ       $0000185A           ;*** PTCDS - Port C Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0        equ       0                   ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1        equ       1                   ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2        equ       2                   ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3        equ       3                   ; Output Drive Strength Selection for Port C Bit 3
PTCDS_PTCDS4        equ       4                   ; Output Drive Strength Selection for Port C Bit 4
PTCDS_PTCDS5        equ       5                   ; Output Drive Strength Selection for Port C Bit 5
PTCDS_PTCDS6        equ       6                   ; Output Drive Strength Selection for Port C Bit 6
PTCDS_PTCDS7        equ       7                   ; Output Drive Strength Selection for Port C Bit 7
; bit position masks
mPTCDS_PTCDS0       equ       %00000001
mPTCDS_PTCDS1       equ       %00000010
mPTCDS_PTCDS2       equ       %00000100
mPTCDS_PTCDS3       equ       %00001000
mPTCDS_PTCDS4       equ       %00010000
mPTCDS_PTCDS5       equ       %00100000
mPTCDS_PTCDS6       equ       %01000000
mPTCDS_PTCDS7       equ       %10000000


;*** PTCIFE - Port C Input Filter Enable Register
PTCIFE              equ       $0000185B           ;*** PTCIFE - Port C Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCIFE_PTCIFE0      equ       0                   ; Port C Input Filter Enable Bit 0
PTCIFE_PTCIFE1      equ       1                   ; Port C Input Filter Enable Bit 1
PTCIFE_PTCIFE2      equ       2                   ; Port C Input Filter Enable Bit 2
PTCIFE_PTCIFE3      equ       3                   ; Port C Input Filter Enable Bit 3
PTCIFE_PTCIFE4      equ       4                   ; Port C Input Filter Enable Bit 4
PTCIFE_PTCIFE5      equ       5                   ; Port C Input Filter Enable Bit 5
PTCIFE_PTCIFE6      equ       6                   ; Port C Input Filter Enable Bit 6
PTCIFE_PTCIFE7      equ       7                   ; Port C Input Filter Enable Bit 7
; bit position masks
mPTCIFE_PTCIFE0     equ       %00000001
mPTCIFE_PTCIFE1     equ       %00000010
mPTCIFE_PTCIFE2     equ       %00000100
mPTCIFE_PTCIFE3     equ       %00001000
mPTCIFE_PTCIFE4     equ       %00010000
mPTCIFE_PTCIFE5     equ       %00100000
mPTCIFE_PTCIFE6     equ       %01000000
mPTCIFE_PTCIFE7     equ       %10000000


;*** PTDPE - Port D Pull Enable Register
PTDPE               equ       $0000185C           ;*** PTDPE - Port D Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0        equ       0                   ; Internal Pull Enable for Port D Bit 0
PTDPE_PTDPE1        equ       1                   ; Internal Pull Enable for Port D Bit 1
PTDPE_PTDPE2        equ       2                   ; Internal Pull Enable for Port D Bit 2
PTDPE_PTDPE3        equ       3                   ; Internal Pull Enable for Port D Bit 3
PTDPE_PTDPE4        equ       4                   ; Internal Pull Enable for Port D Bit 4
PTDPE_PTDPE5        equ       5                   ; Internal Pull Enable for Port D Bit 5
PTDPE_PTDPE6        equ       6                   ; Internal Pull Enable for Port D Bit 6
PTDPE_PTDPE7        equ       7                   ; Internal Pull Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0       equ       %00000001
mPTDPE_PTDPE1       equ       %00000010
mPTDPE_PTDPE2       equ       %00000100
mPTDPE_PTDPE3       equ       %00001000
mPTDPE_PTDPE4       equ       %00010000
mPTDPE_PTDPE5       equ       %00100000
mPTDPE_PTDPE6       equ       %01000000
mPTDPE_PTDPE7       equ       %10000000


;*** PTDSE - Port D Slew Rate Enable Register
PTDSE               equ       $0000185D           ;*** PTDSE - Port D Slew Rate Enable Register
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


;*** PTDDS - Port D Drive Strength Selection Register
PTDDS               equ       $0000185E           ;*** PTDDS - Port D Drive Strength Selection Register
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


;*** PTDIFE - Port D Input Filter Enable Register
PTDIFE              equ       $0000185F           ;*** PTDIFE - Port D Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDIFE_PTDIFE0      equ       0                   ; Port D Input Filter Enable Bit 0
PTDIFE_PTDIFE1      equ       1                   ; Port D Input Filter Enable Bit 1
PTDIFE_PTDIFE2      equ       2                   ; Port D Input Filter Enable Bit 2
PTDIFE_PTDIFE3      equ       3                   ; Port D Input Filter Enable Bit 3
PTDIFE_PTDIFE4      equ       4                   ; Port D Input Filter Enable Bit 4
PTDIFE_PTDIFE5      equ       5                   ; Port D Input Filter Enable Bit 5
PTDIFE_PTDIFE6      equ       6                   ; Port D Input Filter Enable Bit 6
PTDIFE_PTDIFE7      equ       7                   ; Port D Input Filter Enable Bit 7
; bit position masks
mPTDIFE_PTDIFE0     equ       %00000001
mPTDIFE_PTDIFE1     equ       %00000010
mPTDIFE_PTDIFE2     equ       %00000100
mPTDIFE_PTDIFE3     equ       %00001000
mPTDIFE_PTDIFE4     equ       %00010000
mPTDIFE_PTDIFE5     equ       %00100000
mPTDIFE_PTDIFE6     equ       %01000000
mPTDIFE_PTDIFE7     equ       %10000000


;*** PTEPE - Port E Pull Enable Register
PTEPE               equ       $00001860           ;*** PTEPE - Port E Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPE_PTEPE0        equ       0                   ; Internal Pull Enable for Port E Bit 0
PTEPE_PTEPE1        equ       1                   ; Internal Pull Enable for Port E Bit 1
PTEPE_PTEPE2        equ       2                   ; Internal Pull Enable for Port E Bit 2
PTEPE_PTEPE3        equ       3                   ; Internal Pull Enable for Port E Bit 3
PTEPE_PTEPE4        equ       4                   ; Internal Pull Enable for Port E Bit 4
PTEPE_PTEPE5        equ       5                   ; Internal Pull Enable for Port E Bit 5
PTEPE_PTEPE6        equ       6                   ; Internal Pull Enable for Port E Bit 6
PTEPE_PTEPE7        equ       7                   ; Internal Pull Enable for Port E Bit 7
; bit position masks
mPTEPE_PTEPE0       equ       %00000001
mPTEPE_PTEPE1       equ       %00000010
mPTEPE_PTEPE2       equ       %00000100
mPTEPE_PTEPE3       equ       %00001000
mPTEPE_PTEPE4       equ       %00010000
mPTEPE_PTEPE5       equ       %00100000
mPTEPE_PTEPE6       equ       %01000000
mPTEPE_PTEPE7       equ       %10000000


;*** PTESE - Port E Slew Rate Enable Register
PTESE               equ       $00001861           ;*** PTESE - Port E Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESE_PTESE0        equ       0                   ; Output Slew Rate Enable for Port E Bit 0
PTESE_PTESE1        equ       1                   ; Output Slew Rate Enable for Port E Bit 1
PTESE_PTESE2        equ       2                   ; Output Slew Rate Enable for Port E Bit 2
PTESE_PTESE3        equ       3                   ; Output Slew Rate Enable for Port E Bit 3
PTESE_PTESE4        equ       4                   ; Output Slew Rate Enable for Port E Bit 4
PTESE_PTESE5        equ       5                   ; Output Slew Rate Enable for Port E Bit 5
PTESE_PTESE6        equ       6                   ; Output Slew Rate Enable for Port E Bit 6
PTESE_PTESE7        equ       7                   ; Output Slew Rate Enable for Port E Bit 7
; bit position masks
mPTESE_PTESE0       equ       %00000001
mPTESE_PTESE1       equ       %00000010
mPTESE_PTESE2       equ       %00000100
mPTESE_PTESE3       equ       %00001000
mPTESE_PTESE4       equ       %00010000
mPTESE_PTESE5       equ       %00100000
mPTESE_PTESE6       equ       %01000000
mPTESE_PTESE7       equ       %10000000


;*** PTEDS - Port E Drive Strength Selection Register
PTEDS               equ       $00001862           ;*** PTEDS - Port E Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDS_PTEDS0        equ       0                   ; Output Drive Strength Selection for Port E Bit 0
PTEDS_PTEDS1        equ       1                   ; Output Drive Strength Selection for Port E Bit 1
PTEDS_PTEDS2        equ       2                   ; Output Drive Strength Selection for Port E Bit 2
PTEDS_PTEDS3        equ       3                   ; Output Drive Strength Selection for Port E Bit 3
PTEDS_PTEDS4        equ       4                   ; Output Drive Strength Selection for Port E Bit 4
PTEDS_PTEDS5        equ       5                   ; Output Drive Strength Selection for Port E Bit 5
PTEDS_PTEDS6        equ       6                   ; Output Drive Strength Selection for Port E Bit 6
PTEDS_PTEDS7        equ       7                   ; Output Drive Strength Selection for Port E Bit 7
; bit position masks
mPTEDS_PTEDS0       equ       %00000001
mPTEDS_PTEDS1       equ       %00000010
mPTEDS_PTEDS2       equ       %00000100
mPTEDS_PTEDS3       equ       %00001000
mPTEDS_PTEDS4       equ       %00010000
mPTEDS_PTEDS5       equ       %00100000
mPTEDS_PTEDS6       equ       %01000000
mPTEDS_PTEDS7       equ       %10000000


;*** PTEIFE - Port E Input Filter Enable Register
PTEIFE              equ       $00001863           ;*** PTEIFE - Port E Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEIFE_PTEIFE0      equ       0                   ; Port E Input Filter Enable Bit 0
PTEIFE_PTEIFE1      equ       1                   ; Port E Input Filter Enable Bit 1
PTEIFE_PTEIFE2      equ       2                   ; Port E Input Filter Enable Bit 2
PTEIFE_PTEIFE3      equ       3                   ; Port E Input Filter Enable Bit 3
PTEIFE_PTEIFE4      equ       4                   ; Port E Input Filter Enable Bit 4
PTEIFE_PTEIFE5      equ       5                   ; Port E Input Filter Enable Bit 5
PTEIFE_PTEIFE6      equ       6                   ; Port E Input Filter Enable Bit 6
PTEIFE_PTEIFE7      equ       7                   ; Port E Input Filter Enable Bit 7
; bit position masks
mPTEIFE_PTEIFE0     equ       %00000001
mPTEIFE_PTEIFE1     equ       %00000010
mPTEIFE_PTEIFE2     equ       %00000100
mPTEIFE_PTEIFE3     equ       %00001000
mPTEIFE_PTEIFE4     equ       %00010000
mPTEIFE_PTEIFE5     equ       %00100000
mPTEIFE_PTEIFE6     equ       %01000000
mPTEIFE_PTEIFE7     equ       %10000000


;*** PTFPE - Port F Pull Enable Register
PTFPE               equ       $00001864           ;*** PTFPE - Port F Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPE_PTFPE0        equ       0                   ; Internal Pull Enable for Port F Bit 0
PTFPE_PTFPE1        equ       1                   ; Internal Pull Enable for Port F Bit 1
PTFPE_PTFPE2        equ       2                   ; Internal Pull Enable for Port F Bit 2
PTFPE_PTFPE3        equ       3                   ; Internal Pull Enable for Port F Bit 3
PTFPE_PTFPE4        equ       4                   ; Internal Pull Enable for Port F Bit 4
PTFPE_PTFPE5        equ       5                   ; Internal Pull Enable for Port F Bit 5
PTFPE_PTFPE6        equ       6                   ; Internal Pull Enable for Port F Bit 6
PTFPE_PTFPE7        equ       7                   ; Internal Pull Enable for Port F Bit 7
; bit position masks
mPTFPE_PTFPE0       equ       %00000001
mPTFPE_PTFPE1       equ       %00000010
mPTFPE_PTFPE2       equ       %00000100
mPTFPE_PTFPE3       equ       %00001000
mPTFPE_PTFPE4       equ       %00010000
mPTFPE_PTFPE5       equ       %00100000
mPTFPE_PTFPE6       equ       %01000000
mPTFPE_PTFPE7       equ       %10000000


;*** PTFSE - Port F Slew Rate Enable Register
PTFSE               equ       $00001865           ;*** PTFSE - Port F Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0        equ       0                   ; Output Slew Rate Enable for Port F Bit 0
PTFSE_PTFSE1        equ       1                   ; Output Slew Rate Enable for Port F Bit 1
PTFSE_PTFSE2        equ       2                   ; Output Slew Rate Enable for Port F Bit 2
PTFSE_PTFSE3        equ       3                   ; Output Slew Rate Enable for Port F Bit 3
PTFSE_PTFSE4        equ       4                   ; Output Slew Rate Enable for Port F Bit 4
PTFSE_PTFSE5        equ       5                   ; Output Slew Rate Enable for Port F Bit 5
PTFSE_PTFSE6        equ       6                   ; Output Slew Rate Enable for Port F Bit 6
PTFSE_PTFSE7        equ       7                   ; Output Slew Rate Enable for Port F Bit 7
; bit position masks
mPTFSE_PTFSE0       equ       %00000001
mPTFSE_PTFSE1       equ       %00000010
mPTFSE_PTFSE2       equ       %00000100
mPTFSE_PTFSE3       equ       %00001000
mPTFSE_PTFSE4       equ       %00010000
mPTFSE_PTFSE5       equ       %00100000
mPTFSE_PTFSE6       equ       %01000000
mPTFSE_PTFSE7       equ       %10000000


;*** PTFDS - Port F Drive Strength Selection Register
PTFDS               equ       $00001866           ;*** PTFDS - Port F Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFDS_PTFDS0        equ       0                   ; Output Drive Strength Selection for Port F Bit 0
PTFDS_PTFDS1        equ       1                   ; Output Drive Strength Selection for Port F Bit 1
PTFDS_PTFDS2        equ       2                   ; Output Drive Strength Selection for Port F Bit 2
PTFDS_PTFDS3        equ       3                   ; Output Drive Strength Selection for Port F Bit 3
PTFDS_PTFDS4        equ       4                   ; Output Drive Strength Selection for Port F Bit 4
PTFDS_PTFDS5        equ       5                   ; Output Drive Strength Selection for Port F Bit 5
PTFDS_PTFDS6        equ       6                   ; Output Drive Strength Selection for Port F Bit 6
PTFDS_PTFDS7        equ       7                   ; Output Drive Strength Selection for Port F Bit 7
; bit position masks
mPTFDS_PTFDS0       equ       %00000001
mPTFDS_PTFDS1       equ       %00000010
mPTFDS_PTFDS2       equ       %00000100
mPTFDS_PTFDS3       equ       %00001000
mPTFDS_PTFDS4       equ       %00010000
mPTFDS_PTFDS5       equ       %00100000
mPTFDS_PTFDS6       equ       %01000000
mPTFDS_PTFDS7       equ       %10000000


;*** PTFIFE - Port F Input Filter Enable Register
PTFIFE              equ       $00001867           ;*** PTFIFE - Port F Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFIFE_PTFIFE0      equ       0                   ; Port F Input Filter Enable Bit 0
PTFIFE_PTFIFE1      equ       1                   ; Port F Input Filter Enable Bit 1
PTFIFE_PTFIFE2      equ       2                   ; Port F Input Filter Enable Bit 2
PTFIFE_PTFIFE3      equ       3                   ; Port F Input Filter Enable Bit 3
PTFIFE_PTFIFE4      equ       4                   ; Port F Input Filter Enable Bit 4
PTFIFE_PTFIFE5      equ       5                   ; Port F Input Filter Enable Bit 5
PTFIFE_PTFIFE6      equ       6                   ; Port F Input Filter Enable Bit 6
PTFIFE_PTFIFE7      equ       7                   ; Port F Input Filter Enable Bit 7
; bit position masks
mPTFIFE_PTFIFE0     equ       %00000001
mPTFIFE_PTFIFE1     equ       %00000010
mPTFIFE_PTFIFE2     equ       %00000100
mPTFIFE_PTFIFE3     equ       %00001000
mPTFIFE_PTFIFE4     equ       %00010000
mPTFIFE_PTFIFE5     equ       %00100000
mPTFIFE_PTFIFE6     equ       %01000000
mPTFIFE_PTFIFE7     equ       %10000000


;*** PTGPE - Port G Pull Enable Register
PTGPE               equ       $00001868           ;*** PTGPE - Port G Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0        equ       0                   ; Internal Pull Enable for Port G Bit 0
PTGPE_PTGPE1        equ       1                   ; Internal Pull Enable for Port G Bit 1
; bit position masks
mPTGPE_PTGPE0       equ       %00000001
mPTGPE_PTGPE1       equ       %00000010


;*** PTGSE - Port G Slew Rate Enable Register
PTGSE               equ       $00001869           ;*** PTGSE - Port G Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0        equ       0                   ; Output Slew Rate Enable for Port G Bit 0
PTGSE_PTGSE1        equ       1                   ; Output Slew Rate Enable for Port G Bit 1
; bit position masks
mPTGSE_PTGSE0       equ       %00000001
mPTGSE_PTGSE1       equ       %00000010


;*** PTGDS - Port G Drive Strength Selection Register
PTGDS               equ       $0000186A           ;*** PTGDS - Port G Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDS_PTGDS0        equ       0                   ; Output Drive Strength Selection for Port G Bit 0
PTGDS_PTGDS1        equ       1                   ; Output Drive Strength Selection for Port G Bit 1
; bit position masks
mPTGDS_PTGDS0       equ       %00000001
mPTGDS_PTGDS1       equ       %00000010


;*** PTGIFE - Port G Input Filter Enable Register
PTGIFE              equ       $0000186B           ;*** PTGIFE - Port G Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGIFE_PTGIFE0      equ       0                   ; Port G Input Filter Enable Bit 0
PTGIFE_PTGIFE1      equ       1                   ; Port G Input Filter Enable Bit 1
; bit position masks
mPTGIFE_PTGIFE0     equ       %00000001
mPTGIFE_PTGIFE1     equ       %00000010


;*** TIAMP1C0 - TIAMP1 Control Register 0
TIAMP1C0            equ       $0000186C           ;*** TIAMP1C0 - TIAMP1 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TIAMP1C0_LPEN       equ       6                   ; Low-Power Enable
TIAMP1C0_TIAMPEN    equ       7                   ; Trans-Impedance Amplifier Enable
; bit position masks
mTIAMP1C0_LPEN      equ       %01000000
mTIAMP1C0_TIAMPEN   equ       %10000000


;*** TIAMP2C0 - TIAMP2 Control Register 0
TIAMP2C0            equ       $0000186E           ;*** TIAMP2C0 - TIAMP2 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TIAMP2C0_LPEN       equ       6                   ; Low-Power Enable
TIAMP2C0_TIAMPEN    equ       7                   ; Trans-Impedance Amplifier Enable
; bit position masks
mTIAMP2C0_LPEN      equ       %01000000
mTIAMP2C0_TIAMPEN   equ       %10000000


;*** CMTCG1 - Carrier Generator Data Register 1
CMTCG1              equ       $00001870           ;*** CMTCG1 - Carrier Generator Data Register 1


;*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte
CMTCGH1             equ       $00001870           ;*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte


;*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte
CMTCGL1             equ       $00001871           ;*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte


;*** CMTCG2 - Carrier Generator Data Register 2
CMTCG2              equ       $00001872           ;*** CMTCG2 - Carrier Generator Data Register 2


;*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte
CMTCGH2             equ       $00001872           ;*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte


;*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte
CMTCGL2             equ       $00001873           ;*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte


;*** CMTOC - CMT Output Control Register
CMTOC               equ       $00001874           ;*** CMTOC - CMT Output Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTOC_IROPEN        equ       5                   ; IRO pin enable
CMTOC_CMTPOL        equ       6                   ; CMT output polarity
CMTOC_IROL          equ       7                   ; IRO latch control
; bit position masks
mCMTOC_IROPEN       equ       %00100000
mCMTOC_CMTPOL       equ       %01000000
mCMTOC_IROL         equ       %10000000


;*** CMTMSC - CMT Modulator Status and Control Register
CMTMSC              equ       $00001875           ;*** CMTMSC - CMT Modulator Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTMSC_MCGEN        equ       0                   ; Modulator and Carrier Generator Enable
CMTMSC_EOCIE        equ       1                   ; End of Cycle Interrupt Enable
CMTMSC_FSK          equ       2                   ; FSK Mode Select
CMTMSC_BASE         equ       3                   ; Baseband Mode Enable
CMTMSC_EXSPC        equ       4                   ; Extended Space Enable
CMTMSC_CMTDIV0      equ       5                   ; CMT Clock Divide Prescaler Bit 0
CMTMSC_CMTDIV1      equ       6                   ; CMT Clock Divide Prescaler Bit 1
CMTMSC_EOCF         equ       7                   ; End of Cycle Status Flag
; bit position masks
mCMTMSC_MCGEN       equ       %00000001
mCMTMSC_EOCIE       equ       %00000010
mCMTMSC_FSK         equ       %00000100
mCMTMSC_BASE        equ       %00001000
mCMTMSC_EXSPC       equ       %00010000
mCMTMSC_CMTDIV0     equ       %00100000
mCMTMSC_CMTDIV1     equ       %01000000
mCMTMSC_EOCF        equ       %10000000


;*** CMTCMD12 - CMT Modulator Data Register 12
CMTCMD12            equ       $00001876           ;*** CMTCMD12 - CMT Modulator Data Register 12


;*** CMTCMD1 - CMT Modulator Data Register 1
CMTCMD1             equ       $00001876           ;*** CMTCMD1 - CMT Modulator Data Register 1


;*** CMTCMD2 - CMT Modulator Data Register 2
CMTCMD2             equ       $00001877           ;*** CMTCMD2 - CMT Modulator Data Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCMD2_MB0         equ       0                   ; Data Value Bit 0
CMTCMD2_MB1         equ       1                   ; Data Value Bit 1
CMTCMD2_MB2         equ       2                   ; Data Value Bit 2
CMTCMD2_MB3         equ       3                   ; Data Value Bit 3
CMTCMD2_MB4         equ       4                   ; Data Value Bit 4
CMTCMD2_MB5         equ       5                   ; Data Value Bit 5
CMTCMD2_MB6         equ       6                   ; Data Value Bit 6
CMTCMD2_MB7         equ       7                   ; Data Value Bit 7
; bit position masks
mCMTCMD2_MB0        equ       %00000001
mCMTCMD2_MB1        equ       %00000010
mCMTCMD2_MB2        equ       %00000100
mCMTCMD2_MB3        equ       %00001000
mCMTCMD2_MB4        equ       %00010000
mCMTCMD2_MB5        equ       %00100000
mCMTCMD2_MB6        equ       %01000000
mCMTCMD2_MB7        equ       %10000000


;*** CMTCMD34 - CMT Modulator Data Register 34
CMTCMD34            equ       $00001878           ;*** CMTCMD34 - CMT Modulator Data Register 34


;*** CMTCMD3 - CMT Modulator Data Register 3
CMTCMD3             equ       $00001878           ;*** CMTCMD3 - CMT Modulator Data Register 3


;*** CMTCMD4 - CMT Modulator Data Register 4
CMTCMD4             equ       $00001879           ;*** CMTCMD4 - CMT Modulator Data Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTCMD4_SB0         equ       0                   ; Data Value Bit 0
CMTCMD4_SB1         equ       1                   ; Data Value Bit 1
CMTCMD4_SB2         equ       2                   ; Data Value Bit 2
CMTCMD4_SB3         equ       3                   ; Data Value Bit 3
CMTCMD4_SB4         equ       4                   ; Data Value Bit 4
CMTCMD4_SB5         equ       5                   ; Data Value Bit 5
CMTCMD4_SB6         equ       6                   ; Data Value Bit 6
CMTCMD4_SB7         equ       7                   ; Data Value Bit 7
; bit position masks
mCMTCMD4_SB0        equ       %00000001
mCMTCMD4_SB1        equ       %00000010
mCMTCMD4_SB2        equ       %00000100
mCMTCMD4_SB3        equ       %00001000
mCMTCMD4_SB4        equ       %00010000
mCMTCMD4_SB5        equ       %00100000
mCMTCMD4_SB6        equ       %01000000
mCMTCMD4_SB7        equ       %10000000


;*** GPAMP1C0 - GPAMP1 Control Register 0
GPAMP1C0            equ       $0000187C           ;*** GPAMP1C0 - GPAMP1 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAMP1C0_MODE0      equ       0                   ; Mode selection bits, bit 0
GPAMP1C0_MODE1      equ       1                   ; Mode selection bits, bit 1
GPAMP1C0_LPEN       equ       6                   ; Low-power mode enable
GPAMP1C0_GPAMPEN    equ       7                   ; OPAMP enable
; bit position masks
mGPAMP1C0_MODE0     equ       %00000001
mGPAMP1C0_MODE1     equ       %00000010
mGPAMP1C0_LPEN      equ       %01000000
mGPAMP1C0_GPAMPEN   equ       %10000000


;*** GPAMP1C1 - GPAMP1 Control Register 1
GPAMP1C1            equ       $0000187D           ;*** GPAMP1C1 - GPAMP1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAMP1C1_AMPRI0     equ       0                   ; OPAMP Gains Selector, bit 0
GPAMP1C1_AMPRI1     equ       1                   ; OPAMP Gains Selector, bit 1
GPAMP1C1_AMPRF0     equ       2                   ; OPAMP Gains Selector, bit 0
GPAMP1C1_AMPRF1     equ       3                   ; OPAMP Gains Selector, bit 1
GPAMP1C1_AMPRF2     equ       4                   ; OPAMP Gains Selector, bit 2
; bit position masks
mGPAMP1C1_AMPRI0    equ       %00000001
mGPAMP1C1_AMPRI1    equ       %00000010
mGPAMP1C1_AMPRF0    equ       %00000100
mGPAMP1C1_AMPRF1    equ       %00001000
mGPAMP1C1_AMPRF2    equ       %00010000


;*** GPAMP1C2 - GPAMP1 Control Register 2
GPAMP1C2            equ       $0000187E           ;*** GPAMP1C2 - GPAMP1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAMP1C2_AMPNSEL0   equ       0                   ; Amplifier negative input terminal selector bits, bit 0
GPAMP1C2_AMPNSEL1   equ       1                   ; Amplifier negative input terminal selector bits, bit 1
GPAMP1C2_AMPNSEL2   equ       2                   ; Amplifier negative input terminal selector bits, bit 2
GPAMP1C2_AMPPSEL0   equ       4                   ; Amplifier positive input terminal selector bits, bit 0
GPAMP1C2_AMPPSEL1   equ       5                   ; Amplifier positive input terminal selector bits, bit 1
GPAMP1C2_AMPPSEL2   equ       6                   ; Amplifier positive input terminal selector bits, bit 2
; bit position masks
mGPAMP1C2_AMPNSEL0  equ       %00000001
mGPAMP1C2_AMPNSEL1  equ       %00000010
mGPAMP1C2_AMPNSEL2  equ       %00000100
mGPAMP1C2_AMPPSEL0  equ       %00010000
mGPAMP1C2_AMPPSEL1  equ       %00100000
mGPAMP1C2_AMPPSEL2  equ       %01000000


;*** DBGCA - Debug Comparator A Register
DBGCA               equ       $00001880           ;*** DBGCA - Debug Comparator A Register


;*** DBGCAH - Debug Comparator A High Register
DBGCAH              equ       $00001880           ;*** DBGCAH - Debug Comparator A High Register
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
DBGCAL              equ       $00001881           ;*** DBGCAL - Debug Comparator A Low Register
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
DBGCB               equ       $00001882           ;*** DBGCB - Debug Comparator B Register


;*** DBGCBH - Debug Comparator B High Register
DBGCBH              equ       $00001882           ;*** DBGCBH - Debug Comparator B High Register
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
DBGCBL              equ       $00001883           ;*** DBGCBL - Debug Comparator B Low Register
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


;*** DBGCC - Debug Comparator C Register
DBGCC               equ       $00001884           ;*** DBGCC - Debug Comparator C Register


;*** DBGCCH - Debug Comparator C High Register
DBGCCH              equ       $00001884           ;*** DBGCCH - Debug Comparator C High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCH_Bit8         equ       0                   ; Comparator C High Compare Bit 8
DBGCCH_Bit9         equ       1                   ; Comparator C High Compare Bit 9
DBGCCH_Bit10        equ       2                   ; Comparator C High Compare Bit 10
DBGCCH_Bit11        equ       3                   ; Comparator C High Compare Bit 11
DBGCCH_Bit12        equ       4                   ; Comparator C High Compare Bit 12
DBGCCH_Bit13        equ       5                   ; Comparator C High Compare Bit 13
DBGCCH_Bit14        equ       6                   ; Comparator C High Compare Bit 14
DBGCCH_Bit15        equ       7                   ; Comparator C High Compare Bit 15
; bit position masks
mDBGCCH_Bit8        equ       %00000001
mDBGCCH_Bit9        equ       %00000010
mDBGCCH_Bit10       equ       %00000100
mDBGCCH_Bit11       equ       %00001000
mDBGCCH_Bit12       equ       %00010000
mDBGCCH_Bit13       equ       %00100000
mDBGCCH_Bit14       equ       %01000000
mDBGCCH_Bit15       equ       %10000000


;*** DBGCCL - Debug Comparator C Low Register
DBGCCL              equ       $00001885           ;*** DBGCCL - Debug Comparator C Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCL_Bit0         equ       0                   ; Comparator C Low Compare Bit 0
DBGCCL_Bit1         equ       1                   ; Comparator C Low Compare Bit 1
DBGCCL_Bit2         equ       2                   ; Comparator C Low Compare Bit 2
DBGCCL_Bit3         equ       3                   ; Comparator C Low Compare Bit 3
DBGCCL_Bit4         equ       4                   ; Comparator C Low Compare Bit 4
DBGCCL_Bit5         equ       5                   ; Comparator C Low Compare Bit 5
DBGCCL_Bit6         equ       6                   ; Comparator C Low Compare Bit 6
DBGCCL_Bit7         equ       7                   ; Comparator C Low Compare Bit 7
; bit position masks
mDBGCCL_Bit0        equ       %00000001
mDBGCCL_Bit1        equ       %00000010
mDBGCCL_Bit2        equ       %00000100
mDBGCCL_Bit3        equ       %00001000
mDBGCCL_Bit4        equ       %00010000
mDBGCCL_Bit5        equ       %00100000
mDBGCCL_Bit6        equ       %01000000
mDBGCCL_Bit7        equ       %10000000


;*** DBGF - Debug FIFO Register
DBGF                equ       $00001886           ;*** DBGF - Debug FIFO Register


;*** DBGFH - Debug FIFO High Register
DBGFH               equ       $00001886           ;*** DBGFH - Debug FIFO High Register
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
DBGFL               equ       $00001887           ;*** DBGFL - Debug FIFO Low Register
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


;*** DBGCAX - Debug Comparator A Extension Register
DBGCAX              equ       $00001888           ;*** DBGCAX - Debug Comparator A Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAX_Bit16        equ       0                   ; omparator A Extended Address Bit 16 Compare Bit
DBGCAX_PAGSEL       equ       5                   ; Comparator A Page Select Bit
DBGCAX_RWA          equ       6                   ; Read/Write Comparator A Value Bit
DBGCAX_RWAEN        equ       7                   ; Read/Write Comparator A Enable Bit
; bit position masks
mDBGCAX_Bit16       equ       %00000001
mDBGCAX_PAGSEL      equ       %00100000
mDBGCAX_RWA         equ       %01000000
mDBGCAX_RWAEN       equ       %10000000


;*** DBGCBX - Debug Comparator B Extension Register
DBGCBX              equ       $00001889           ;*** DBGCBX - Debug Comparator B Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBX_Bit16        equ       0                   ; omparator B Extended Address Bit 16 Compare Bit
DBGCBX_PAGSEL       equ       5                   ; Comparator B Page Select Bit
DBGCBX_RWB          equ       6                   ; Read/Write Comparator B Value Bit
DBGCBX_RWBEN        equ       7                   ; Read/Write Comparator B Enable Bit
; bit position masks
mDBGCBX_Bit16       equ       %00000001
mDBGCBX_PAGSEL      equ       %00100000
mDBGCBX_RWB         equ       %01000000
mDBGCBX_RWBEN       equ       %10000000


;*** DBGCCX - Debug Comparator C Extension Register
DBGCCX              equ       $0000188A           ;*** DBGCCX - Debug Comparator C Extension Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCX_Bit16        equ       0                   ; omparator C Extended Address Bit 16 Compare Bit
DBGCCX_PAGSEL       equ       5                   ; Comparator C Page Select Bit
DBGCCX_RWC          equ       6                   ; Read/Write Comparator C Value Bit
DBGCCX_RWCEN        equ       7                   ; Read/Write Comparator C Enable Bit
; bit position masks
mDBGCCX_Bit16       equ       %00000001
mDBGCCX_PAGSEL      equ       %00100000
mDBGCCX_RWC         equ       %01000000
mDBGCCX_RWCEN       equ       %10000000


;*** DBGFX - Debug FIFO Extended Information Register
DBGFX               equ       $0000188B           ;*** DBGFX - Debug FIFO Extended Information Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFX_Bit16         equ       0                   ; Extended Address Bit 16
DBGFX_PPACC         equ       7                   ; PPAGE Access Indicator Bit
; bit position masks
mDBGFX_Bit16        equ       %00000001
mDBGFX_PPACC        equ       %10000000


;*** DBGC - Debug Control Register
DBGC                equ       $0000188C           ;*** DBGC - Debug Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC_LOOP1          equ       0                   ; Select LOOP1 Capture Mode
DBGC_BRKEN          equ       4                   ; Break Enable Bit
DBGC_TAG            equ       5                   ; Tag or Force Bit
DBGC_ARM            equ       6                   ; Arm Bit
DBGC_DBGEN          equ       7                   ; DBG Module Enable Bit
; bit position masks
mDBGC_LOOP1         equ       %00000001
mDBGC_BRKEN         equ       %00010000
mDBGC_TAG           equ       %00100000
mDBGC_ARM           equ       %01000000
mDBGC_DBGEN         equ       %10000000


;*** DBGT - Debug Trigger Register
DBGT                equ       $0000188D           ;*** DBGT - Debug Trigger Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGT_TRG0           equ       0                   ; Trigger Mode Bit 0
DBGT_TRG1           equ       1                   ; Trigger Mode Bit 1
DBGT_TRG2           equ       2                   ; Trigger Mode Bit 2
DBGT_TRG3           equ       3                   ; Trigger Mode Bit 3
DBGT_BEGIN          equ       6                   ; Begin/End Trigger Bit
DBGT_TRGSEL         equ       7                   ; Trigger Selection Bit
; bit position masks
mDBGT_TRG0          equ       %00000001
mDBGT_TRG1          equ       %00000010
mDBGT_TRG2          equ       %00000100
mDBGT_TRG3          equ       %00001000
mDBGT_BEGIN         equ       %01000000
mDBGT_TRGSEL        equ       %10000000


;*** DBGS - Debug Status Register
DBGS                equ       $0000188E           ;*** DBGS - Debug Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGS_ARMF           equ       0                   ; Arm Flag Bit
DBGS_CF             equ       5                   ; Trigger C Match Bit
DBGS_BF             equ       6                   ; Trigger B Match Bit
DBGS_AF             equ       7                   ; Trigger A Match Bit
; bit position masks
mDBGS_ARMF          equ       %00000001
mDBGS_CF            equ       %00100000
mDBGS_BF            equ       %01000000
mDBGS_AF            equ       %10000000


;*** DBGCNT - Debug Count Status Register
DBGCNT              equ       $0000188F           ;*** DBGCNT - Debug Count Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCNT_CNT0         equ       0                   ; FIFO Valid Count Bits, bit 0
DBGCNT_CNT1         equ       1                   ; FIFO Valid Count Bits, bit 1
DBGCNT_CNT2         equ       2                   ; FIFO Valid Count Bits, bit 2
DBGCNT_CNT3         equ       3                   ; FIFO Valid Count Bits, bit 3
; bit position masks
mDBGCNT_CNT0        equ       %00000001
mDBGCNT_CNT1        equ       %00000010
mDBGCNT_CNT2        equ       %00000100
mDBGCNT_CNT3        equ       %00001000


;*** CRCH - CRC High Register
CRCH                equ       $00001890           ;*** CRCH - CRC High Register
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
CRCL                equ       $00001891           ;*** CRCL - CRC Low Register
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


;*** TRANSPOSE - CRC Transpose Register
TRANSPOSE           equ       $00001892           ;*** TRANSPOSE - CRC Transpose Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TRANSPOSE_BIT0      equ       0                   ; CRC transpose register, bit 0
TRANSPOSE_BIT1      equ       1                   ; CRC transpose register, bit 1
TRANSPOSE_BIT2      equ       2                   ; CRC transpose register, bit 2
TRANSPOSE_BIT3      equ       3                   ; CRC transpose register, bit 3
TRANSPOSE_BIT4      equ       4                   ; CRC transpose register, bit 4
TRANSPOSE_BIT5      equ       5                   ; CRC transpose register, bit 5
TRANSPOSE_BIT6      equ       6                   ; CRC transpose register, bit 6
TRANSPOSE_BIT7      equ       7                   ; CRC transpose register, bit 7
; bit position masks
mTRANSPOSE_BIT0     equ       %00000001
mTRANSPOSE_BIT1     equ       %00000010
mTRANSPOSE_BIT2     equ       %00000100
mTRANSPOSE_BIT3     equ       %00001000
mTRANSPOSE_BIT4     equ       %00010000
mTRANSPOSE_BIT5     equ       %00100000
mTRANSPOSE_BIT6     equ       %01000000
mTRANSPOSE_BIT7     equ       %10000000


;*** GPAMP2C0 - GPAMP2 Control Register 0
GPAMP2C0            equ       $00001898           ;*** GPAMP2C0 - GPAMP2 Control Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAMP2C0_MODE0      equ       0                   ; Mode selection bits, bit 0
GPAMP2C0_MODE1      equ       1                   ; Mode selection bits, bit 1
GPAMP2C0_LPEN       equ       6                   ; Low-power mode enable
GPAMP2C0_GPAMPEN    equ       7                   ; OPAMP enable
; bit position masks
mGPAMP2C0_MODE0     equ       %00000001
mGPAMP2C0_MODE1     equ       %00000010
mGPAMP2C0_LPEN      equ       %01000000
mGPAMP2C0_GPAMPEN   equ       %10000000


;*** GPAMP2C1 - GPAMP2 Control Register 1
GPAMP2C1            equ       $00001899           ;*** GPAMP2C1 - GPAMP2 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAMP2C1_AMPRI0     equ       0                   ; OPAMP Gains Selector, bit 0
GPAMP2C1_AMPRI1     equ       1                   ; OPAMP Gains Selector, bit 1
GPAMP2C1_AMPRF0     equ       2                   ; OPAMP Gains Selector, bit 0
GPAMP2C1_AMPRF1     equ       3                   ; OPAMP Gains Selector, bit 1
GPAMP2C1_AMPRF2     equ       4                   ; OPAMP Gains Selector, bit 2
; bit position masks
mGPAMP2C1_AMPRI0    equ       %00000001
mGPAMP2C1_AMPRI1    equ       %00000010
mGPAMP2C1_AMPRF0    equ       %00000100
mGPAMP2C1_AMPRF1    equ       %00001000
mGPAMP2C1_AMPRF2    equ       %00010000


;*** GPAMP2C2 - GPAMP2 Control Register 2
GPAMP2C2            equ       $0000189A           ;*** GPAMP2C2 - GPAMP2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
GPAMP2C2_AMPNSEL0   equ       0                   ; Amplifier negative input terminal selector bits, bit 0
GPAMP2C2_AMPNSEL1   equ       1                   ; Amplifier negative input terminal selector bits, bit 1
GPAMP2C2_AMPNSEL2   equ       2                   ; Amplifier negative input terminal selector bits, bit 2
GPAMP2C2_AMPPSEL0   equ       4                   ; Amplifier positive input terminal selector bits, bit 0
GPAMP2C2_AMPPSEL1   equ       5                   ; Amplifier positive input terminal selector bits, bit 1
GPAMP2C2_AMPPSEL2   equ       6                   ; Amplifier positive input terminal selector bits, bit 2
; bit position masks
mGPAMP2C2_AMPNSEL0  equ       %00000001
mGPAMP2C2_AMPNSEL1  equ       %00000010
mGPAMP2C2_AMPNSEL2  equ       %00000100
mGPAMP2C2_AMPPSEL0  equ       %00010000
mGPAMP2C2_AMPPSEL1  equ       %00100000
mGPAMP2C2_AMPPSEL2  equ       %01000000


;*** TODC - TOD Control Register
TODC                equ       $0000189C           ;*** TODC - TOD Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TODC_TODPS0         equ       0                   ; TOD Prescaler Bits, bit 0
TODC_TODPS1         equ       1                   ; TOD Prescaler Bits, bit 1
TODC_TODPS2         equ       2                   ; TOD Prescaler Bits, bit 2
TODC_TODCLKEN       equ       3                   ; TOD Clock Enable
TODC_TODR           equ       4                   ; TOD Reset
TODC_TODCLKS0       equ       5                   ; TOD Clock Source, bit 0
TODC_TODCLKS1       equ       6                   ; TOD Clock Source, bit 1
TODC_TODEN          equ       7                   ; Time of Day Enable
; bit position masks
mTODC_TODPS0        equ       %00000001
mTODC_TODPS1        equ       %00000010
mTODC_TODPS2        equ       %00000100
mTODC_TODCLKEN      equ       %00001000
mTODC_TODR          equ       %00010000
mTODC_TODCLKS0      equ       %00100000
mTODC_TODCLKS1      equ       %01000000
mTODC_TODEN         equ       %10000000


;*** TODSC - TOD Status and Control Register
TODSC               equ       $0000189D           ;*** TODSC - TOD Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TODSC_MTCHWC        equ       0                   ; Match Write Complete
TODSC_MTCHEN        equ       1                   ; Match Function Enable
TODSC_MTCHIE        equ       2                   ; Match Interrupt Enable
TODSC_SECIE         equ       3                   ; Second Interrupt Enable
TODSC_QSECIE        equ       4                   ; Quarter-Second Interrupt Enable
TODSC_MTCHF         equ       5                   ; Match Interrupt Flag
TODSC_SECF          equ       6                   ; Second Interrupt Flag
TODSC_QSECF         equ       7                   ; Quarter-Second Interrupt Flag
; bit position masks
mTODSC_MTCHWC       equ       %00000001
mTODSC_MTCHEN       equ       %00000010
mTODSC_MTCHIE       equ       %00000100
mTODSC_SECIE        equ       %00001000
mTODSC_QSECIE       equ       %00010000
mTODSC_MTCHF        equ       %00100000
mTODSC_SECF         equ       %01000000
mTODSC_QSECF        equ       %10000000


;*** TODM - TOD Match Register
TODM                equ       $0000189E           ;*** TODM - TOD Match Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TODM_MQSEC0         equ       0                   ; Match Quarter-Second Bits, bit 0
TODM_MQSEC1         equ       1                   ; Match Quarter-Second Bits, bit 1
TODM_TODM0          equ       2                   ; TOD Match Value, bit 0
TODM_TODM1          equ       3                   ; TOD Match Value, bit 1
TODM_TODM2          equ       4                   ; TOD Match Value, bit 2
TODM_TODM3          equ       5                   ; TOD Match Value, bit 3
TODM_TODM4          equ       6                   ; TOD Match Value, bit 4
TODM_TODM5          equ       7                   ; TOD Match Value, bit 5
; bit position masks
mTODM_MQSEC0        equ       %00000001
mTODM_MQSEC1        equ       %00000010
mTODM_TODM0         equ       %00000100
mTODM_TODM1         equ       %00001000
mTODM_TODM2         equ       %00010000
mTODM_TODM3         equ       %00100000
mTODM_TODM4         equ       %01000000
mTODM_TODM5         equ       %10000000


;*** TODCNT - TOD Counter Register
TODCNT              equ       $0000189F           ;*** TODCNT - TOD Counter Register


;*** TPM2SC - TPM2 Status and Control Register
TPM2SC              equ       $000018A0           ;*** TPM2SC - TPM2 Status and Control Register
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
TPM2CNT             equ       $000018A1           ;*** TPM2CNT - TPM2 Timer Counter Register


;*** TPM2CNTH - TPM2 Timer Counter Register High
TPM2CNTH            equ       $000018A1           ;*** TPM2CNTH - TPM2 Timer Counter Register High


;*** TPM2CNTL - TPM2 Timer Counter Register Low
TPM2CNTL            equ       $000018A2           ;*** TPM2CNTL - TPM2 Timer Counter Register Low


;*** TPM2MOD - TPM2 Timer Counter Modulo Register
TPM2MOD             equ       $000018A3           ;*** TPM2MOD - TPM2 Timer Counter Modulo Register


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High
TPM2MODH            equ       $000018A3           ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low
TPM2MODL            equ       $000018A4           ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $000018A5           ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
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
TPM2C0V             equ       $000018A6           ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $000018A6           ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $000018A7           ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
TPM2C1SC            equ       $000018A8           ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register
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
TPM2C1V             equ       $000018A9           ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High
TPM2C1VH            equ       $000018A9           ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low
TPM2C1VL            equ       $000018AA           ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low


;*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register
TPM2C2SC            equ       $000018AB           ;*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C2SC_ELS2A      equ       2                   ; Edge/Level Select Bit A
TPM2C2SC_ELS2B      equ       3                   ; Edge/Level Select Bit B
TPM2C2SC_MS2A       equ       4                   ; Mode Select A for TPM Channel 2
TPM2C2SC_MS2B       equ       5                   ; Mode Select B for TPM Channel 2
TPM2C2SC_CH2IE      equ       6                   ; Channel 2 Interrupt Enable
TPM2C2SC_CH2F       equ       7                   ; Channel 2 Flag
; bit position masks
mTPM2C2SC_ELS2A     equ       %00000100
mTPM2C2SC_ELS2B     equ       %00001000
mTPM2C2SC_MS2A      equ       %00010000
mTPM2C2SC_MS2B      equ       %00100000
mTPM2C2SC_CH2IE     equ       %01000000
mTPM2C2SC_CH2F      equ       %10000000


;*** TPM2C2V - TPM2 Timer Channel 2 Value Register
TPM2C2V             equ       $000018AC           ;*** TPM2C2V - TPM2 Timer Channel 2 Value Register


;*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High
TPM2C2VH            equ       $000018AC           ;*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High


;*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low
TPM2C2VL            equ       $000018AD           ;*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low


;*** TPM2C3SC - TPM2 Timer Channel 3 Status and Control Register
TPM2C3SC            equ       $000018AE           ;*** TPM2C3SC - TPM2 Timer Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C3SC_ELS3A      equ       2                   ; Edge/Level Select Bit A
TPM2C3SC_ELS3B      equ       3                   ; Edge/Level Select Bit B
TPM2C3SC_MS3A       equ       4                   ; Mode Select A for TPM Channel 3
TPM2C3SC_MS3B       equ       5                   ; Mode Select B for TPM Channel 3
TPM2C3SC_CH3IE      equ       6                   ; Channel 3 Interrupt Enable
TPM2C3SC_CH3F       equ       7                   ; Channel 3 Flag
; bit position masks
mTPM2C3SC_ELS3A     equ       %00000100
mTPM2C3SC_ELS3B     equ       %00001000
mTPM2C3SC_MS3A      equ       %00010000
mTPM2C3SC_MS3B      equ       %00100000
mTPM2C3SC_CH3IE     equ       %01000000
mTPM2C3SC_CH3F      equ       %10000000


;*** TPM2C3V - TPM2 Timer Channel 3 Value Register
TPM2C3V             equ       $000018AF           ;*** TPM2C3V - TPM2 Timer Channel 3 Value Register


;*** TPM2C3VH - TPM2 Timer Channel 3 Value Register High
TPM2C3VH            equ       $000018AF           ;*** TPM2C3VH - TPM2 Timer Channel 3 Value Register High


;*** TPM2C3VL - TPM2 Timer Channel 3 Value Register Low
TPM2C3VL            equ       $000018B0           ;*** TPM2C3VL - TPM2 Timer Channel 3 Value Register Low


;*** SCI1BD - SCI1 Baud Rate Register
SCI1BD              equ       $000018B8           ;*** SCI1BD - SCI1 Baud Rate Register


;*** SCI1BDH - SCI1 Baud Rate Register High
SCI1BDH             equ       $000018B8           ;*** SCI1BDH - SCI1 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCI1BDH_RXEDGIE     equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1BDH_LBKDIE      equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1BDH_SBR8       equ       %00000001
mSCI1BDH_SBR9       equ       %00000010
mSCI1BDH_SBR10      equ       %00000100
mSCI1BDH_SBR11      equ       %00001000
mSCI1BDH_SBR12      equ       %00010000
mSCI1BDH_RXEDGIE    equ       %01000000
mSCI1BDH_LBKDIE     equ       %10000000


;*** SCI1BDL - SCI1 Baud Rate Register Low
SCI1BDL             equ       $000018B9           ;*** SCI1BDL - SCI1 Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDL_SBR0        equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCI1BDL_SBR1        equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCI1BDL_SBR2        equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCI1BDL_SBR3        equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCI1BDL_SBR4        equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCI1BDL_SBR5        equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCI1BDL_SBR6        equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCI1BDL_SBR7        equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI1BDL_SBR0       equ       %00000001
mSCI1BDL_SBR1       equ       %00000010
mSCI1BDL_SBR2       equ       %00000100
mSCI1BDL_SBR3       equ       %00001000
mSCI1BDL_SBR4       equ       %00010000
mSCI1BDL_SBR5       equ       %00100000
mSCI1BDL_SBR6       equ       %01000000
mSCI1BDL_SBR7       equ       %10000000


;*** SCI1C1 - SCI1 Control Register 1
SCI1C1              equ       $000018BA           ;*** SCI1C1 - SCI1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C1_PT           equ       0                   ; Parity Type
SCI1C1_PE           equ       1                   ; Parity Enable
SCI1C1_ILT          equ       2                   ; Idle Line Type Select
SCI1C1_WAKE         equ       3                   ; Receiver Wakeup Method Select
SCI1C1_M            equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI1C1_RSRC         equ       5                   ; Receiver Source Select
SCI1C1_SCISWAI      equ       6                   ; SCI Stops in Wait Mode
SCI1C1_LOOPS        equ       7                   ; Loop Mode Select
; bit position masks
mSCI1C1_PT          equ       %00000001
mSCI1C1_PE          equ       %00000010
mSCI1C1_ILT         equ       %00000100
mSCI1C1_WAKE        equ       %00001000
mSCI1C1_M           equ       %00010000
mSCI1C1_RSRC        equ       %00100000
mSCI1C1_SCISWAI     equ       %01000000
mSCI1C1_LOOPS       equ       %10000000


;*** SCI1C2 - SCI1 Control Register 2
SCI1C2              equ       $000018BB           ;*** SCI1C2 - SCI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C2_SBK          equ       0                   ; Send Break
SCI1C2_RWU          equ       1                   ; Receiver Wakeup Control
SCI1C2_RE           equ       2                   ; Receiver Enable
SCI1C2_TE           equ       3                   ; Transmitter Enable
SCI1C2_ILIE         equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCI1C2_RIE          equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCI1C2_TCIE         equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCI1C2_TIE          equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI1C2_SBK         equ       %00000001
mSCI1C2_RWU         equ       %00000010
mSCI1C2_RE          equ       %00000100
mSCI1C2_TE          equ       %00001000
mSCI1C2_ILIE        equ       %00010000
mSCI1C2_RIE         equ       %00100000
mSCI1C2_TCIE        equ       %01000000
mSCI1C2_TIE         equ       %10000000


;*** SCI1S1 - SCI1 Status Register 1
SCI1S1              equ       $000018BC           ;*** SCI1S1 - SCI1 Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S1_PF           equ       0                   ; Parity Error Flag
SCI1S1_FE           equ       1                   ; Framing Error Flag
SCI1S1_NF           equ       2                   ; Noise Flag
SCI1S1_OR           equ       3                   ; Receiver Overrun Flag
SCI1S1_IDLE         equ       4                   ; Idle Line Flag
SCI1S1_RDRF         equ       5                   ; Receive Data Register Full Flag
SCI1S1_TC           equ       6                   ; Transmission Complete Flag
SCI1S1_TDRE         equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI1S1_PF          equ       %00000001
mSCI1S1_FE          equ       %00000010
mSCI1S1_NF          equ       %00000100
mSCI1S1_OR          equ       %00001000
mSCI1S1_IDLE        equ       %00010000
mSCI1S1_RDRF        equ       %00100000
mSCI1S1_TC          equ       %01000000
mSCI1S1_TDRE        equ       %10000000


;*** SCI1S2 - SCI1 Status Register 2
SCI1S2              equ       $000018BD           ;*** SCI1S2 - SCI1 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF          equ       0                   ; Receiver Active Flag
SCI1S2_LBKDE        equ       1                   ; LIN Break Detection Enable
SCI1S2_BRK13        equ       2                   ; Break Character Generation Length
SCI1S2_RWUID        equ       3                   ; Receive Wake Up Idle Detect
SCI1S2_RXINV        equ       4                   ; Receive Data Inversion
SCI1S2_RXEDGIF      equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI1S2_LBKDIF       equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI1S2_RAF         equ       %00000001
mSCI1S2_LBKDE       equ       %00000010
mSCI1S2_BRK13       equ       %00000100
mSCI1S2_RWUID       equ       %00001000
mSCI1S2_RXINV       equ       %00010000
mSCI1S2_RXEDGIF     equ       %01000000
mSCI1S2_LBKDIF      equ       %10000000


;*** SCI1C3 - SCI1 Control Register 3
SCI1C3              equ       $000018BE           ;*** SCI1C3 - SCI1 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI1C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI1C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI1C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI1C3_TXINV        equ       4                   ; Transmit Data Inversion
SCI1C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI1C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE        equ       %00000001
mSCI1C3_FEIE        equ       %00000010
mSCI1C3_NEIE        equ       %00000100
mSCI1C3_ORIE        equ       %00001000
mSCI1C3_TXINV       equ       %00010000
mSCI1C3_TXDIR       equ       %00100000
mSCI1C3_T8          equ       %01000000
mSCI1C3_R8          equ       %10000000


;*** SCI1D - SCI1 Data Register
SCI1D               equ       $000018BF           ;*** SCI1D - SCI1 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1D_R0_T0         equ       0                   ; Receive/Transmit Data Bit 0
SCI1D_R1_T1         equ       1                   ; Receive/Transmit Data Bit 1
SCI1D_R2_T2         equ       2                   ; Receive/Transmit Data Bit 2
SCI1D_R3_T3         equ       3                   ; Receive/Transmit Data Bit 3
SCI1D_R4_T4         equ       4                   ; Receive/Transmit Data Bit 4
SCI1D_R5_T5         equ       5                   ; Receive/Transmit Data Bit 5
SCI1D_R6_T6         equ       6                   ; Receive/Transmit Data Bit 6
SCI1D_R7_T7         equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCI1D_R0_T0        equ       %00000001
mSCI1D_R1_T1        equ       %00000010
mSCI1D_R2_T2        equ       %00000100
mSCI1D_R3_T3        equ       %00001000
mSCI1D_R4_T4        equ       %00010000
mSCI1D_R5_T5        equ       %00100000
mSCI1D_R6_T6        equ       %01000000
mSCI1D_R7_T7        equ       %10000000


;*** PDBSC - PDB Status and Control Register
PDBSC               equ       $000018C0           ;*** PDBSC - PDB Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBSC_LDOK          equ       0                   ; Load OK
PDBSC_DACTOE        equ       1                   ; DAC Trigger Output Enable
PDBSC_TOS0          equ       2                   ; Trigger Output Select, bit 0
PDBSC_TOS1          equ       3                   ; Trigger Output Select, bit 1
PDBSC_LDMOD         equ       4                   ; Load Mode Select
PDBSC_PDBIE         equ       5                   ; PDB Interrupt Enable
PDBSC_PDBIF         equ       6                   ; PDB Interrupt Flag
PDBSC_PDBEN         equ       7                   ; PDB module Enable
; bit position masks
mPDBSC_LDOK         equ       %00000001
mPDBSC_DACTOE       equ       %00000010
mPDBSC_TOS0         equ       %00000100
mPDBSC_TOS1         equ       %00001000
mPDBSC_LDMOD        equ       %00010000
mPDBSC_PDBIE        equ       %00100000
mPDBSC_PDBIF        equ       %01000000
mPDBSC_PDBEN        equ       %10000000


;*** PDBC1 - PDB Control Register 1
PDBC1               equ       $000018C1           ;*** PDBC1 - PDB Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBC1_MULT          equ       0                   ; Multiply prescaler bit
PDBC1_CONT          equ       1                   ; Continuous Mode Enable
PDBC1_TRIGSEL0      equ       2                   ; Input Trigger Select, bit 0
PDBC1_TRIGSEL1      equ       3                   ; Input Trigger Select, bit 1
PDBC1_TRIGSEL2      equ       4                   ; Input Trigger Select, bit 2
PDBC1_PRESCALER0    equ       5                   ; Clock Prescaler Select, bit 0
PDBC1_PRESCALER1    equ       6                   ; Clock Prescaler Select, bit 1
PDBC1_PRESCALER2    equ       7                   ; Clock Prescaler Select, bit 2
; bit position masks
mPDBC1_MULT         equ       %00000001
mPDBC1_CONT         equ       %00000010
mPDBC1_TRIGSEL0     equ       %00000100
mPDBC1_TRIGSEL1     equ       %00001000
mPDBC1_TRIGSEL2     equ       %00010000
mPDBC1_PRESCALER0   equ       %00100000
mPDBC1_PRESCALER1   equ       %01000000
mPDBC1_PRESCALER2   equ       %10000000


;*** PDBC2 - PDB Control Register 2
PDBC2               equ       $000018C2           ;*** PDBC2 - PDB Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBC2_SWTRIG        equ       0                   ; SoftwareTrigger
PDBC2_BB1           equ       1                   ; Back to Back enable, bit 1
PDBC2_BB2           equ       2                   ; Back to Back enable, bit 2
PDBC2_BB3           equ       3                   ; Back to Back enable, bit 3
PDBC2_BB4           equ       4                   ; Back to Back enable, bit 4
PDBC2_BB5           equ       5                   ; Back to Back enable, bit 5
PDBC2_BB6           equ       6                   ; Back to Back enable, bit 6
PDBC2_BB7           equ       7                   ; Back to Back enable, bit 7
; bit position masks
mPDBC2_SWTRIG       equ       %00000001
mPDBC2_BB1          equ       %00000010
mPDBC2_BB2          equ       %00000100
mPDBC2_BB3          equ       %00001000
mPDBC2_BB4          equ       %00010000
mPDBC2_BB5          equ       %00100000
mPDBC2_BB6          equ       %01000000
mPDBC2_BB7          equ       %10000000


;*** PDBCHEN - PDB Channel Enable
PDBCHEN             equ       $000018C3           ;*** PDBCHEN - PDB Channel Enable
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCHEN_CHEN0       equ       0                   ; PDB channel enable, bit 0
PDBCHEN_CHEN1       equ       1                   ; PDB channel enable, bit 1
PDBCHEN_CHEN2       equ       2                   ; PDB channel enable, bit 2
PDBCHEN_CHEN3       equ       3                   ; PDB channel enable, bit 3
PDBCHEN_CHEN4       equ       4                   ; PDB channel enable, bit 4
PDBCHEN_CHEN5       equ       5                   ; PDB channel enable, bit 5
PDBCHEN_CHEN6       equ       6                   ; PDB channel enable, bit 6
PDBCHEN_CHEN7       equ       7                   ; PDB channel enable, bit 7
; bit position masks
mPDBCHEN_CHEN0      equ       %00000001
mPDBCHEN_CHEN1      equ       %00000010
mPDBCHEN_CHEN2      equ       %00000100
mPDBCHEN_CHEN3      equ       %00001000
mPDBCHEN_CHEN4      equ       %00010000
mPDBCHEN_CHEN5      equ       %00100000
mPDBCHEN_CHEN6      equ       %01000000
mPDBCHEN_CHEN7      equ       %10000000


;*** PDBMOD - PDB Modulus Register
PDBMOD              equ       $000018C4           ;*** PDBMOD - PDB Modulus Register


;*** PDBMODH - PDB Modulus Register High
PDBMODH             equ       $000018C4           ;*** PDBMODH - PDB Modulus Register High


;*** PDBMODL - PDB Modulus Register Low
PDBMODL             equ       $000018C5           ;*** PDBMODL - PDB Modulus Register Low


;*** PDBCNT - PDB Counter Register
PDBCNT              equ       $000018C6           ;*** PDBCNT - PDB Counter Register


;*** PDBCNTH - PDB Counter Register High
PDBCNTH             equ       $000018C6           ;*** PDBCNTH - PDB Counter Register High


;*** PDBCNTL - PDB Counter Register Low
PDBCNTL             equ       $000018C7           ;*** PDBCNTL - PDB Counter Register Low


;*** PDBIDLY - PDB Interrupt Delay Register
PDBIDLY             equ       $000018C8           ;*** PDBIDLY - PDB Interrupt Delay Register


;*** PDBIDLYH - PDB Interrupt Delay Register High
PDBIDLYH            equ       $000018C8           ;*** PDBIDLYH - PDB Interrupt Delay Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBIDLYH_IDELAY8    equ       0                   ; Interrupt Delay, bit 8
PDBIDLYH_IDELAY9    equ       1                   ; Interrupt Delay, bit 9
PDBIDLYH_IDELAY10   equ       2                   ; Interrupt Delay, bit 10
PDBIDLYH_IDELAY11   equ       3                   ; Interrupt Delay, bit 11
PDBIDLYH_IDELAY12   equ       4                   ; Interrupt Delay, bit 12
PDBIDLYH_IDELAY13   equ       5                   ; Interrupt Delay, bit 13
PDBIDLYH_IDELAY14   equ       6                   ; Interrupt Delay, bit 14
PDBIDLYH_IDELAY15   equ       7                   ; Interrupt Delay, bit 15
; bit position masks
mPDBIDLYH_IDELAY8   equ       %00000001
mPDBIDLYH_IDELAY9   equ       %00000010
mPDBIDLYH_IDELAY10  equ       %00000100
mPDBIDLYH_IDELAY11  equ       %00001000
mPDBIDLYH_IDELAY12  equ       %00010000
mPDBIDLYH_IDELAY13  equ       %00100000
mPDBIDLYH_IDELAY14  equ       %01000000
mPDBIDLYH_IDELAY15  equ       %10000000


;*** PDBIDLYL - PDB Interrupt Delay Register Low
PDBIDLYL            equ       $000018C9           ;*** PDBIDLYL - PDB Interrupt Delay Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBIDLYL_IDELAY0    equ       0                   ; Interrupt Delay, bit 0
PDBIDLYL_IDELAY1    equ       1                   ; Interrupt Delay, bit 1
PDBIDLYL_IDELAY2    equ       2                   ; Interrupt Delay, bit 2
PDBIDLYL_IDELAY3    equ       3                   ; Interrupt Delay, bit 3
PDBIDLYL_IDELAY4    equ       4                   ; Interrupt Delay, bit 4
PDBIDLYL_IDELAY5    equ       5                   ; Interrupt Delay, bit 5
PDBIDLYL_IDELAY6    equ       6                   ; Interrupt Delay, bit 6
PDBIDLYL_IDELAY7    equ       7                   ; Interrupt Delay, bit 7
; bit position masks
mPDBIDLYL_IDELAY0   equ       %00000001
mPDBIDLYL_IDELAY1   equ       %00000010
mPDBIDLYL_IDELAY2   equ       %00000100
mPDBIDLYL_IDELAY3   equ       %00001000
mPDBIDLYL_IDELAY4   equ       %00010000
mPDBIDLYL_IDELAY5   equ       %00100000
mPDBIDLYL_IDELAY6   equ       %01000000
mPDBIDLYL_IDELAY7   equ       %10000000


;*** DACINT - DAC Trigger Interval Register
DACINT              equ       $000018CA           ;*** DACINT - DAC Trigger Interval Register


;*** DACINTH - DAC Trigger Interval Register High
DACINTH             equ       $000018CA           ;*** DACINTH - DAC Trigger Interval Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACINTH_DACINT8     equ       0                   ; DAC Interval, bit 8
DACINTH_DACINT9     equ       1                   ; DAC Interval, bit 9
DACINTH_DACINT10    equ       2                   ; DAC Interval, bit 10
DACINTH_DACINT11    equ       3                   ; DAC Interval, bit 11
DACINTH_DACINT12    equ       4                   ; DAC Interval, bit 12
DACINTH_DACINT13    equ       5                   ; DAC Interval, bit 13
DACINTH_DACINT14    equ       6                   ; DAC Interval, bit 14
DACINTH_DACINT15    equ       7                   ; DAC Interval, bit 15
; bit position masks
mDACINTH_DACINT8    equ       %00000001
mDACINTH_DACINT9    equ       %00000010
mDACINTH_DACINT10   equ       %00000100
mDACINTH_DACINT11   equ       %00001000
mDACINTH_DACINT12   equ       %00010000
mDACINTH_DACINT13   equ       %00100000
mDACINTH_DACINT14   equ       %01000000
mDACINTH_DACINT15   equ       %10000000


;*** DACINTL - DAC Trigger Interval Register Low
DACINTL             equ       $000018CB           ;*** DACINTL - DAC Trigger Interval Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DACINTL_DACINT0     equ       0                   ; DAC Interval, bit 0
DACINTL_DACINT1     equ       1                   ; DAC Interval, bit 1
DACINTL_DACINT2     equ       2                   ; DAC Interval, bit 2
DACINTL_DACINT3     equ       3                   ; DAC Interval, bit 3
DACINTL_DACINT4     equ       4                   ; DAC Interval, bit 4
DACINTL_DACINT5     equ       5                   ; DAC Interval, bit 5
DACINTL_DACINT6     equ       6                   ; DAC Interval, bit 6
DACINTL_DACINT7     equ       7                   ; DAC Interval, bit 7
; bit position masks
mDACINTL_DACINT0    equ       %00000001
mDACINTL_DACINT1    equ       %00000010
mDACINTL_DACINT2    equ       %00000100
mDACINTL_DACINT3    equ       %00001000
mDACINTL_DACINT4    equ       %00010000
mDACINTL_DACINT5    equ       %00100000
mDACINTL_DACINT6    equ       %01000000
mDACINTL_DACINT7    equ       %10000000


;*** PDBDLYA - PDB Delay A Register
PDBDLYA             equ       $000018CC           ;*** PDBDLYA - PDB Delay A Register


;*** PDBDLYAH - PDB Delay A Register High
PDBDLYAH            equ       $000018CC           ;*** PDBDLYAH - PDB Delay A Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYAH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYAH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYAH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYAH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYAH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYAH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYAH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYAH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYAH_DELAY8    equ       %00000001
mPDBDLYAH_DELAY9    equ       %00000010
mPDBDLYAH_DELAY10   equ       %00000100
mPDBDLYAH_DELAY11   equ       %00001000
mPDBDLYAH_DELAY12   equ       %00010000
mPDBDLYAH_DELAY13   equ       %00100000
mPDBDLYAH_DELAY14   equ       %01000000
mPDBDLYAH_DELAY15   equ       %10000000


;*** PDBDLYAL - PDB Delay A Register Low
PDBDLYAL            equ       $000018CD           ;*** PDBDLYAL - PDB Delay A Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYAL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYAL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYAL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYAL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYAL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYAL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYAL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYAL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYAL_DELAY0    equ       %00000001
mPDBDLYAL_DELAY1    equ       %00000010
mPDBDLYAL_DELAY2    equ       %00000100
mPDBDLYAL_DELAY3    equ       %00001000
mPDBDLYAL_DELAY4    equ       %00010000
mPDBDLYAL_DELAY5    equ       %00100000
mPDBDLYAL_DELAY6    equ       %01000000
mPDBDLYAL_DELAY7    equ       %10000000


;*** PDBDLYB - PDB Delay B Register
PDBDLYB             equ       $000018CE           ;*** PDBDLYB - PDB Delay B Register


;*** PDBDLYBH - PDB Delay B Register High
PDBDLYBH            equ       $000018CE           ;*** PDBDLYBH - PDB Delay B Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYBH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYBH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYBH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYBH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYBH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYBH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYBH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYBH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYBH_DELAY8    equ       %00000001
mPDBDLYBH_DELAY9    equ       %00000010
mPDBDLYBH_DELAY10   equ       %00000100
mPDBDLYBH_DELAY11   equ       %00001000
mPDBDLYBH_DELAY12   equ       %00010000
mPDBDLYBH_DELAY13   equ       %00100000
mPDBDLYBH_DELAY14   equ       %01000000
mPDBDLYBH_DELAY15   equ       %10000000


;*** PDBDLYBL - PDB Delay B Register Low
PDBDLYBL            equ       $000018CF           ;*** PDBDLYBL - PDB Delay B Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYBL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYBL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYBL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYBL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYBL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYBL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYBL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYBL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYBL_DELAY0    equ       %00000001
mPDBDLYBL_DELAY1    equ       %00000010
mPDBDLYBL_DELAY2    equ       %00000100
mPDBDLYBL_DELAY3    equ       %00001000
mPDBDLYBL_DELAY4    equ       %00010000
mPDBDLYBL_DELAY5    equ       %00100000
mPDBDLYBL_DELAY6    equ       %01000000
mPDBDLYBL_DELAY7    equ       %10000000


;*** PDBDLYC - PDB Delay C Register
PDBDLYC             equ       $000018D0           ;*** PDBDLYC - PDB Delay C Register


;*** PDBDLYCH - PDB Delay C Register High
PDBDLYCH            equ       $000018D0           ;*** PDBDLYCH - PDB Delay C Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYCH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYCH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYCH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYCH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYCH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYCH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYCH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYCH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYCH_DELAY8    equ       %00000001
mPDBDLYCH_DELAY9    equ       %00000010
mPDBDLYCH_DELAY10   equ       %00000100
mPDBDLYCH_DELAY11   equ       %00001000
mPDBDLYCH_DELAY12   equ       %00010000
mPDBDLYCH_DELAY13   equ       %00100000
mPDBDLYCH_DELAY14   equ       %01000000
mPDBDLYCH_DELAY15   equ       %10000000


;*** PDBDLYCL - PDB Delay C Register Low
PDBDLYCL            equ       $000018D1           ;*** PDBDLYCL - PDB Delay C Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYCL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYCL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYCL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYCL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYCL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYCL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYCL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYCL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYCL_DELAY0    equ       %00000001
mPDBDLYCL_DELAY1    equ       %00000010
mPDBDLYCL_DELAY2    equ       %00000100
mPDBDLYCL_DELAY3    equ       %00001000
mPDBDLYCL_DELAY4    equ       %00010000
mPDBDLYCL_DELAY5    equ       %00100000
mPDBDLYCL_DELAY6    equ       %01000000
mPDBDLYCL_DELAY7    equ       %10000000


;*** PDBDLYD - PDB Delay D Register
PDBDLYD             equ       $000018D2           ;*** PDBDLYD - PDB Delay D Register


;*** PDBDLYDH - PDB Delay D Register High
PDBDLYDH            equ       $000018D2           ;*** PDBDLYDH - PDB Delay D Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYDH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYDH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYDH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYDH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYDH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYDH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYDH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYDH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYDH_DELAY8    equ       %00000001
mPDBDLYDH_DELAY9    equ       %00000010
mPDBDLYDH_DELAY10   equ       %00000100
mPDBDLYDH_DELAY11   equ       %00001000
mPDBDLYDH_DELAY12   equ       %00010000
mPDBDLYDH_DELAY13   equ       %00100000
mPDBDLYDH_DELAY14   equ       %01000000
mPDBDLYDH_DELAY15   equ       %10000000


;*** PDBDLYDL - PDB Delay D Register Low
PDBDLYDL            equ       $000018D3           ;*** PDBDLYDL - PDB Delay D Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYDL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYDL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYDL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYDL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYDL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYDL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYDL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYDL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYDL_DELAY0    equ       %00000001
mPDBDLYDL_DELAY1    equ       %00000010
mPDBDLYDL_DELAY2    equ       %00000100
mPDBDLYDL_DELAY3    equ       %00001000
mPDBDLYDL_DELAY4    equ       %00010000
mPDBDLYDL_DELAY5    equ       %00100000
mPDBDLYDL_DELAY6    equ       %01000000
mPDBDLYDL_DELAY7    equ       %10000000


;*** PDBDLYE - PDB Delay E Register
PDBDLYE             equ       $000018D4           ;*** PDBDLYE - PDB Delay E Register


;*** PDBDLYEH - PDB Delay E Register High
PDBDLYEH            equ       $000018D4           ;*** PDBDLYEH - PDB Delay E Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYEH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYEH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYEH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYEH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYEH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYEH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYEH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYEH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYEH_DELAY8    equ       %00000001
mPDBDLYEH_DELAY9    equ       %00000010
mPDBDLYEH_DELAY10   equ       %00000100
mPDBDLYEH_DELAY11   equ       %00001000
mPDBDLYEH_DELAY12   equ       %00010000
mPDBDLYEH_DELAY13   equ       %00100000
mPDBDLYEH_DELAY14   equ       %01000000
mPDBDLYEH_DELAY15   equ       %10000000


;*** PDBDLYEL - PDB Delay E Register Low
PDBDLYEL            equ       $000018D5           ;*** PDBDLYEL - PDB Delay E Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYEL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYEL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYEL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYEL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYEL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYEL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYEL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYEL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYEL_DELAY0    equ       %00000001
mPDBDLYEL_DELAY1    equ       %00000010
mPDBDLYEL_DELAY2    equ       %00000100
mPDBDLYEL_DELAY3    equ       %00001000
mPDBDLYEL_DELAY4    equ       %00010000
mPDBDLYEL_DELAY5    equ       %00100000
mPDBDLYEL_DELAY6    equ       %01000000
mPDBDLYEL_DELAY7    equ       %10000000


;*** PDBDLYF - PDB Delay F Register
PDBDLYF             equ       $000018D6           ;*** PDBDLYF - PDB Delay F Register


;*** PDBDLYFH - PDB Delay F Register High
PDBDLYFH            equ       $000018D6           ;*** PDBDLYFH - PDB Delay F Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYFH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYFH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYFH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYFH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYFH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYFH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYFH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYFH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYFH_DELAY8    equ       %00000001
mPDBDLYFH_DELAY9    equ       %00000010
mPDBDLYFH_DELAY10   equ       %00000100
mPDBDLYFH_DELAY11   equ       %00001000
mPDBDLYFH_DELAY12   equ       %00010000
mPDBDLYFH_DELAY13   equ       %00100000
mPDBDLYFH_DELAY14   equ       %01000000
mPDBDLYFH_DELAY15   equ       %10000000


;*** PDBDLYFL - PDB Delay F Register Low
PDBDLYFL            equ       $000018D7           ;*** PDBDLYFL - PDB Delay F Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYFL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYFL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYFL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYFL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYFL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYFL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYFL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYFL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYFL_DELAY0    equ       %00000001
mPDBDLYFL_DELAY1    equ       %00000010
mPDBDLYFL_DELAY2    equ       %00000100
mPDBDLYFL_DELAY3    equ       %00001000
mPDBDLYFL_DELAY4    equ       %00010000
mPDBDLYFL_DELAY5    equ       %00100000
mPDBDLYFL_DELAY6    equ       %01000000
mPDBDLYFL_DELAY7    equ       %10000000


;*** PDBDLYG - PDB Delay G Register
PDBDLYG             equ       $000018D8           ;*** PDBDLYG - PDB Delay G Register


;*** PDBDLYGH - PDB Delay G Register High
PDBDLYGH            equ       $000018D8           ;*** PDBDLYGH - PDB Delay G Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYGH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYGH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYGH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYGH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYGH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYGH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYGH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYGH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYGH_DELAY8    equ       %00000001
mPDBDLYGH_DELAY9    equ       %00000010
mPDBDLYGH_DELAY10   equ       %00000100
mPDBDLYGH_DELAY11   equ       %00001000
mPDBDLYGH_DELAY12   equ       %00010000
mPDBDLYGH_DELAY13   equ       %00100000
mPDBDLYGH_DELAY14   equ       %01000000
mPDBDLYGH_DELAY15   equ       %10000000


;*** PDBDLYGL - PDB Delay G Register Low
PDBDLYGL            equ       $000018D9           ;*** PDBDLYGL - PDB Delay G Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYGL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYGL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYGL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYGL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYGL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYGL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYGL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYGL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYGL_DELAY0    equ       %00000001
mPDBDLYGL_DELAY1    equ       %00000010
mPDBDLYGL_DELAY2    equ       %00000100
mPDBDLYGL_DELAY3    equ       %00001000
mPDBDLYGL_DELAY4    equ       %00010000
mPDBDLYGL_DELAY5    equ       %00100000
mPDBDLYGL_DELAY6    equ       %01000000
mPDBDLYGL_DELAY7    equ       %10000000


;*** PDBDLYH - PDB Delay H Register
PDBDLYH             equ       $000018DA           ;*** PDBDLYH - PDB Delay H Register


;*** PDBDLYHH - PDB Delay H Register High
PDBDLYHH            equ       $000018DA           ;*** PDBDLYHH - PDB Delay H Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYHH_DELAY8     equ       0                   ; Delay, bit 8
PDBDLYHH_DELAY9     equ       1                   ; Delay, bit 9
PDBDLYHH_DELAY10    equ       2                   ; Delay, bit 10
PDBDLYHH_DELAY11    equ       3                   ; Delay, bit 11
PDBDLYHH_DELAY12    equ       4                   ; Delay, bit 12
PDBDLYHH_DELAY13    equ       5                   ; Delay, bit 13
PDBDLYHH_DELAY14    equ       6                   ; Delay, bit 14
PDBDLYHH_DELAY15    equ       7                   ; Delay, bit 15
; bit position masks
mPDBDLYHH_DELAY8    equ       %00000001
mPDBDLYHH_DELAY9    equ       %00000010
mPDBDLYHH_DELAY10   equ       %00000100
mPDBDLYHH_DELAY11   equ       %00001000
mPDBDLYHH_DELAY12   equ       %00010000
mPDBDLYHH_DELAY13   equ       %00100000
mPDBDLYHH_DELAY14   equ       %01000000
mPDBDLYHH_DELAY15   equ       %10000000


;*** PDBDLYHL - PDB Delay H Register Low
PDBDLYHL            equ       $000018DB           ;*** PDBDLYHL - PDB Delay H Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBDLYHL_DELAY0     equ       0                   ; Delay, bit 0
PDBDLYHL_DELAY1     equ       1                   ; Delay, bit 1
PDBDLYHL_DELAY2     equ       2                   ; Delay, bit 2
PDBDLYHL_DELAY3     equ       3                   ; Delay, bit 3
PDBDLYHL_DELAY4     equ       4                   ; Delay, bit 4
PDBDLYHL_DELAY5     equ       5                   ; Delay, bit 5
PDBDLYHL_DELAY6     equ       6                   ; Delay, bit 6
PDBDLYHL_DELAY7     equ       7                   ; Delay, bit 7
; bit position masks
mPDBDLYHL_DELAY0    equ       %00000001
mPDBDLYHL_DELAY1    equ       %00000010
mPDBDLYHL_DELAY2    equ       %00000100
mPDBDLYHL_DELAY3    equ       %00001000
mPDBDLYHL_DELAY4    equ       %00010000
mPDBDLYHL_DELAY5    equ       %00100000
mPDBDLYHL_DELAY6    equ       %01000000
mPDBDLYHL_DELAY7    equ       %10000000


;*** TPM1SC - TPM1 Status and Control Register
TPM1SC              equ       $000018E0           ;*** TPM1SC - TPM1 Status and Control Register
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
TPM1CNT             equ       $000018E1           ;*** TPM1CNT - TPM1 Timer Counter Register


;*** TPM1CNTH - TPM1 Timer Counter Register High
TPM1CNTH            equ       $000018E1           ;*** TPM1CNTH - TPM1 Timer Counter Register High


;*** TPM1CNTL - TPM1 Timer Counter Register Low
TPM1CNTL            equ       $000018E2           ;*** TPM1CNTL - TPM1 Timer Counter Register Low


;*** TPM1MOD - TPM1 Timer Counter Modulo Register
TPM1MOD             equ       $000018E3           ;*** TPM1MOD - TPM1 Timer Counter Modulo Register


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High
TPM1MODH            equ       $000018E3           ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low
TPM1MODL            equ       $000018E4           ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $000018E5           ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
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
TPM1C0V             equ       $000018E6           ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $000018E6           ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $000018E7           ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $000018E8           ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register
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
TPM1C1V             equ       $000018E9           ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $000018E9           ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $000018EA           ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low


;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register
TPM1C2SC            equ       $000018EB           ;*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C2SC_ELS2A      equ       2                   ; Edge/Level Select Bit A
TPM1C2SC_ELS2B      equ       3                   ; Edge/Level Select Bit B
TPM1C2SC_MS2A       equ       4                   ; Mode Select A for TPM Channel 2
TPM1C2SC_MS2B       equ       5                   ; Mode Select B for TPM Channel 2
TPM1C2SC_CH2IE      equ       6                   ; Channel 2 Interrupt Enable
TPM1C2SC_CH2F       equ       7                   ; Channel 2 Flag
; bit position masks
mTPM1C2SC_ELS2A     equ       %00000100
mTPM1C2SC_ELS2B     equ       %00001000
mTPM1C2SC_MS2A      equ       %00010000
mTPM1C2SC_MS2B      equ       %00100000
mTPM1C2SC_CH2IE     equ       %01000000
mTPM1C2SC_CH2F      equ       %10000000


;*** TPM1C2V - TPM1 Timer Channel 2 Value Register
TPM1C2V             equ       $000018EC           ;*** TPM1C2V - TPM1 Timer Channel 2 Value Register


;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High
TPM1C2VH            equ       $000018EC           ;*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High


;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low
TPM1C2VL            equ       $000018ED           ;*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low


;*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register
TPM1C3SC            equ       $000018EE           ;*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C3SC_ELS3A      equ       2                   ; Edge/Level Select Bit A
TPM1C3SC_ELS3B      equ       3                   ; Edge/Level Select Bit B
TPM1C3SC_MS3A       equ       4                   ; Mode Select A for TPM Channel 3
TPM1C3SC_MS3B       equ       5                   ; Mode Select B for TPM Channel 3
TPM1C3SC_CH3IE      equ       6                   ; Channel 3 Interrupt Enable
TPM1C3SC_CH3F       equ       7                   ; Channel 3 Flag
; bit position masks
mTPM1C3SC_ELS3A     equ       %00000100
mTPM1C3SC_ELS3B     equ       %00001000
mTPM1C3SC_MS3A      equ       %00010000
mTPM1C3SC_MS3B      equ       %00100000
mTPM1C3SC_CH3IE     equ       %01000000
mTPM1C3SC_CH3F      equ       %10000000


;*** TPM1C3V - TPM1 Timer Channel 3 Value Register
TPM1C3V             equ       $000018EF           ;*** TPM1C3V - TPM1 Timer Channel 3 Value Register


;*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High
TPM1C3VH            equ       $000018EF           ;*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High


;*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low
TPM1C3VL            equ       $000018F0           ;*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low


;*** ADCCV1 - Compare Value 1 Register
ADCCV1              equ       $000018F8           ;*** ADCCV1 - Compare Value 1 Register


;*** ADCCV1H - Compare Value 1 High Register
ADCCV1H             equ       $000018F8           ;*** ADCCV1H - Compare Value 1 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV1H_CV18        equ       0                   ; Compare Function Value 8
ADCCV1H_CV19        equ       1                   ; Compare Function Value 9
ADCCV1H_CV110       equ       2                   ; Compare Function Value 10
ADCCV1H_CV111       equ       3                   ; Compare Function Value 11
ADCCV1H_CV112       equ       4                   ; Compare Function Value 12
ADCCV1H_CV113       equ       5                   ; Compare Function Value 13
ADCCV1H_CV114       equ       6                   ; Compare Function Value 14
ADCCV1H_CV115       equ       7                   ; Compare Function Value 15
; bit position masks
mADCCV1H_CV18       equ       %00000001
mADCCV1H_CV19       equ       %00000010
mADCCV1H_CV110      equ       %00000100
mADCCV1H_CV111      equ       %00001000
mADCCV1H_CV112      equ       %00010000
mADCCV1H_CV113      equ       %00100000
mADCCV1H_CV114      equ       %01000000
mADCCV1H_CV115      equ       %10000000


;*** ADCCV1L - Compare Value 1 Low Register
ADCCV1L             equ       $000018F9           ;*** ADCCV1L - Compare Value 1 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV1L_CV10        equ       0                   ; Compare Function Value 0
ADCCV1L_CV11        equ       1                   ; Compare Function Value 1
ADCCV1L_CV12        equ       2                   ; Compare Function Value 2
ADCCV1L_CV13        equ       3                   ; Compare Function Value 3
ADCCV1L_CV14        equ       4                   ; Compare Function Value 4
ADCCV1L_CV15        equ       5                   ; Compare Function Value 5
ADCCV1L_CV16        equ       6                   ; Compare Function Value 6
ADCCV1L_CV17        equ       7                   ; Compare Function Value 7
; bit position masks
mADCCV1L_CV10       equ       %00000001
mADCCV1L_CV11       equ       %00000010
mADCCV1L_CV12       equ       %00000100
mADCCV1L_CV13       equ       %00001000
mADCCV1L_CV14       equ       %00010000
mADCCV1L_CV15       equ       %00100000
mADCCV1L_CV16       equ       %01000000
mADCCV1L_CV17       equ       %10000000


;*** ADCCV2 - Compare Value 2 Register
ADCCV2              equ       $000018FA           ;*** ADCCV2 - Compare Value 2 Register


;*** ADCCV2H - Compare Value 2 High Register
ADCCV2H             equ       $000018FA           ;*** ADCCV2H - Compare Value 2 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV2H_CV28        equ       0                   ; Compare Function Value 8
ADCCV2H_CV29        equ       1                   ; Compare Function Value 9
ADCCV2H_CV210       equ       2                   ; Compare Function Value 10
ADCCV2H_CV211       equ       3                   ; Compare Function Value 11
ADCCV2H_CV212       equ       4                   ; Compare Function Value 12
ADCCV2H_CV213       equ       5                   ; Compare Function Value 13
ADCCV2H_CV214       equ       6                   ; Compare Function Value 14
ADCCV2H_CV215       equ       7                   ; Compare Function Value 15
; bit position masks
mADCCV2H_CV28       equ       %00000001
mADCCV2H_CV29       equ       %00000010
mADCCV2H_CV210      equ       %00000100
mADCCV2H_CV211      equ       %00001000
mADCCV2H_CV212      equ       %00010000
mADCCV2H_CV213      equ       %00100000
mADCCV2H_CV214      equ       %01000000
mADCCV2H_CV215      equ       %10000000


;*** ADCCV2L - Compare Value 2 Low Register
ADCCV2L             equ       $000018FB           ;*** ADCCV2L - Compare Value 2 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV2L_CV20        equ       0                   ; Compare Function Value 0
ADCCV2L_CV21        equ       1                   ; Compare Function Value 1
ADCCV2L_CV22        equ       2                   ; Compare Function Value 2
ADCCV2L_CV23        equ       3                   ; Compare Function Value 3
ADCCV2L_CV24        equ       4                   ; Compare Function Value 4
ADCCV2L_CV25        equ       5                   ; Compare Function Value 5
ADCCV2L_CV26        equ       6                   ; Compare Function Value 6
ADCCV2L_CV27        equ       7                   ; Compare Function Value 7
; bit position masks
mADCCV2L_CV20       equ       %00000001
mADCCV2L_CV21       equ       %00000010
mADCCV2L_CV22       equ       %00000100
mADCCV2L_CV23       equ       %00001000
mADCCV2L_CV24       equ       %00010000
mADCCV2L_CV25       equ       %00100000
mADCCV2L_CV26       equ       %01000000
mADCCV2L_CV27       equ       %10000000


;*** ADCSC2 - Status and Control Register 2
ADCSC2              equ       $000018FC           ;*** ADCSC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC2_REFSEL0      equ       0                   ; Voltage Reference Selection, bit 0
ADCSC2_REFSEL1      equ       1                   ; Voltage Reference Selection, bit 1
ADCSC2_ACREN        equ       3                   ; Compare Function Range Enable
ADCSC2_ACFGT        equ       4                   ; Compare Function Greater Than Enable
ADCSC2_ACFE         equ       5                   ; Compare Function Enable - ACFE is used to enable the compare function
ADCSC2_ADTRG        equ       6                   ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADCSC2_ADACT        equ       7                   ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a
; bit position masks
mADCSC2_REFSEL0     equ       %00000001
mADCSC2_REFSEL1     equ       %00000010
mADCSC2_ACREN       equ       %00001000
mADCSC2_ACFGT       equ       %00010000
mADCSC2_ACFE        equ       %00100000
mADCSC2_ADTRG       equ       %01000000
mADCSC2_ADACT       equ       %10000000


;*** ADCSC3 - Status and Control Register 3
ADCSC3              equ       $000018FD           ;*** ADCSC3 - Status and Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC3_AVGS0        equ       0                   ; Hardware Average select, bit 0
ADCSC3_AVGS1        equ       1                   ; Hardware Average select, bit 1
ADCSC3_AVGE         equ       2                   ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADCSC3_ADCO         equ       3                   ; Continuous Conversion Enable - ADCO enables continuous conversions
ADCSC3_CALF         equ       6                   ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADCSC3_CAL          equ       7                   ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADCSC3_AVGS0       equ       %00000001
mADCSC3_AVGS1       equ       %00000010
mADCSC3_AVGE        equ       %00000100
mADCSC3_ADCO        equ       %00001000
mADCSC3_CALF        equ       %01000000
mADCSC3_CAL         equ       %10000000


;*** ADCOFS - Offset Correction Register
ADCOFS              equ       $000018FE           ;*** ADCOFS - Offset Correction Register


;*** ADCOFSH - Offset Correction High Register
ADCOFSH             equ       $000018FE           ;*** ADCOFSH - Offset Correction High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCOFSH_OFS8        equ       0                   ; Offset error correction value bit 8
ADCOFSH_OFS9        equ       1                   ; Offset error correction value bit 9
ADCOFSH_OFS10       equ       2                   ; Offset error correction value bit 10
ADCOFSH_OFS11       equ       3                   ; Offset error correction value bit 11
ADCOFSH_OFS12       equ       4                   ; Offset error correction value bit 12
ADCOFSH_OFS13       equ       5                   ; Offset error correction value bit 13
ADCOFSH_OFS14       equ       6                   ; Offset error correction value bit 14
ADCOFSH_OFS15       equ       7                   ; Offset error correction value bit 15
; bit position masks
mADCOFSH_OFS8       equ       %00000001
mADCOFSH_OFS9       equ       %00000010
mADCOFSH_OFS10      equ       %00000100
mADCOFSH_OFS11      equ       %00001000
mADCOFSH_OFS12      equ       %00010000
mADCOFSH_OFS13      equ       %00100000
mADCOFSH_OFS14      equ       %01000000
mADCOFSH_OFS15      equ       %10000000


;*** ADCOFSL - Offset Correction Low Register
ADCOFSL             equ       $000018FF           ;*** ADCOFSL - Offset Correction Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCOFSL_OFS0        equ       0                   ; Offset error correction value bit 0
ADCOFSL_OFS1        equ       1                   ; Offset error correction value bit 1
ADCOFSL_OFS2        equ       2                   ; Offset error correction value bit 2
ADCOFSL_OFS3        equ       3                   ; Offset error correction value bit 3
ADCOFSL_OFS4        equ       4                   ; Offset error correction value bit 4
ADCOFSL_OFS5        equ       5                   ; Offset error correction value bit 5
ADCOFSL_OFS6        equ       6                   ; Offset error correction value bit 6
ADCOFSL_OFS7        equ       7                   ; Offset error correction value bit 7
; bit position masks
mADCOFSL_OFS0       equ       %00000001
mADCOFSL_OFS1       equ       %00000010
mADCOFSL_OFS2       equ       %00000100
mADCOFSL_OFS3       equ       %00001000
mADCOFSL_OFS4       equ       %00010000
mADCOFSL_OFS5       equ       %00100000
mADCOFSL_OFS6       equ       %01000000
mADCOFSL_OFS7       equ       %10000000


;*** ADCPG - Plus-Side Gain Register
ADCPG               equ       $00001900           ;*** ADCPG - Plus-Side Gain Register


;*** ADCPGH - Plus-Side Gain High Register
ADCPGH              equ       $00001900           ;*** ADCPGH - Plus-Side Gain High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCPGH_PG8          equ       0                   ; Gain error correction for the plus-side input value bit 8
ADCPGH_PG9          equ       1                   ; Gain error correction for the plus-side input value bit 9
ADCPGH_PG10         equ       2                   ; Gain error correction for the plus-side input value bit 10
ADCPGH_PG11         equ       3                   ; Gain error correction for the plus-side input value bit 11
ADCPGH_PG12         equ       4                   ; Gain error correction for the plus-side input value bit 12
ADCPGH_PG13         equ       5                   ; Gain error correction for the plus-side input value bit 13
ADCPGH_PG14         equ       6                   ; Gain error correction for the plus-side input value bit 14
ADCPGH_PG15         equ       7                   ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADCPGH_PG8         equ       %00000001
mADCPGH_PG9         equ       %00000010
mADCPGH_PG10        equ       %00000100
mADCPGH_PG11        equ       %00001000
mADCPGH_PG12        equ       %00010000
mADCPGH_PG13        equ       %00100000
mADCPGH_PG14        equ       %01000000
mADCPGH_PG15        equ       %10000000


;*** ADCPGL - Plus-Side Gain Low Register
ADCPGL              equ       $00001901           ;*** ADCPGL - Plus-Side Gain Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCPGL_PG0          equ       0                   ; Gain error correction for the plus-side input value bit 0
ADCPGL_PG1          equ       1                   ; Gain error correction for the plus-side input value bit 1
ADCPGL_PG2          equ       2                   ; Gain error correction for the plus-side input value bit 2
ADCPGL_PG3          equ       3                   ; Gain error correction for the plus-side input value bit 3
ADCPGL_PG4          equ       4                   ; Gain error correction for the plus-side input value bit 4
ADCPGL_PG5          equ       5                   ; Gain error correction for the plus-side input value bit 5
ADCPGL_PG6          equ       6                   ; Gain error correction for the plus-side input value bit 6
ADCPGL_PG7          equ       7                   ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADCPGL_PG0         equ       %00000001
mADCPGL_PG1         equ       %00000010
mADCPGL_PG2         equ       %00000100
mADCPGL_PG3         equ       %00001000
mADCPGL_PG4         equ       %00010000
mADCPGL_PG5         equ       %00100000
mADCPGL_PG6         equ       %01000000
mADCPGL_PG7         equ       %10000000


;*** ADCMG - Minus-Side Gain Register
ADCMG               equ       $00001902           ;*** ADCMG - Minus-Side Gain Register


;*** ADCMGH - Minus-Side Gain High Register
ADCMGH              equ       $00001902           ;*** ADCMGH - Minus-Side Gain High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCMGH_MG8          equ       0                   ; Gain error correction for the minus-side input value bit 8
ADCMGH_MG9          equ       1                   ; Gain error correction for the minus-side input value bit 9
ADCMGH_MG10         equ       2                   ; Gain error correction for the minus-side input value bit 10
ADCMGH_MG11         equ       3                   ; Gain error correction for the minus-side input value bit 11
ADCMGH_MG12         equ       4                   ; Gain error correction for the minus-side input value bit 12
ADCMGH_MG13         equ       5                   ; Gain error correction for the minus-side input value bit 13
ADCMGH_MG14         equ       6                   ; Gain error correction for the minus-side input value bit 14
ADCMGH_MG15         equ       7                   ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADCMGH_MG8         equ       %00000001
mADCMGH_MG9         equ       %00000010
mADCMGH_MG10        equ       %00000100
mADCMGH_MG11        equ       %00001000
mADCMGH_MG12        equ       %00010000
mADCMGH_MG13        equ       %00100000
mADCMGH_MG14        equ       %01000000
mADCMGH_MG15        equ       %10000000


;*** ADCMGL - Minus-Side Gain Low Register
ADCMGL              equ       $00001903           ;*** ADCMGL - Minus-Side Gain Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCMGL_MG0          equ       0                   ; Gain error correction for the minus-side input value bit 0
ADCMGL_MG1          equ       1                   ; Gain error correction for the minus-side input value bit 1
ADCMGL_MG2          equ       2                   ; Gain error correction for the minus-side input value bit 2
ADCMGL_MG3          equ       3                   ; Gain error correction for the minus-side input value bit 3
ADCMGL_MG4          equ       4                   ; Gain error correction for the minus-side input value bit 4
ADCMGL_MG5          equ       5                   ; Gain error correction for the minus-side input value bit 5
ADCMGL_MG6          equ       6                   ; Gain error correction for the minus-side input value bit 6
ADCMGL_MG7          equ       7                   ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADCMGL_MG0         equ       %00000001
mADCMGL_MG1         equ       %00000010
mADCMGL_MG2         equ       %00000100
mADCMGL_MG3         equ       %00001000
mADCMGL_MG4         equ       %00010000
mADCMGL_MG5         equ       %00100000
mADCMGL_MG6         equ       %01000000
mADCMGL_MG7         equ       %10000000


;*** ADCCLPD - Plus-Side General Calibration Value D Register
ADCCLPD             equ       $00001904           ;*** ADCCLPD - Plus-Side General Calibration Value D Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLPD_CLPD0       equ       0                   ; Plus-Side General Calibration Value D bit 0
ADCCLPD_CLPD1       equ       1                   ; Plus-Side General Calibration Value D bit 1
ADCCLPD_CLPD2       equ       2                   ; Plus-Side General Calibration Value D bit 2
ADCCLPD_CLPD3       equ       3                   ; Plus-Side General Calibration Value D bit 3
ADCCLPD_CLPD4       equ       4                   ; Plus-Side General Calibration Value D bit 4
ADCCLPD_CLPD5       equ       5                   ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADCCLPD_CLPD0      equ       %00000001
mADCCLPD_CLPD1      equ       %00000010
mADCCLPD_CLPD2      equ       %00000100
mADCCLPD_CLPD3      equ       %00001000
mADCCLPD_CLPD4      equ       %00010000
mADCCLPD_CLPD5      equ       %00100000


;*** ADCCLPS - Plus-Side General Calibration Value S Register
ADCCLPS             equ       $00001905           ;*** ADCCLPS - Plus-Side General Calibration Value S Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLPS_CLPS0       equ       0                   ; Plus-Side General Calibration Value S bit 0
ADCCLPS_CLPS1       equ       1                   ; Plus-Side General Calibration Value S bit 1
ADCCLPS_CLPS2       equ       2                   ; Plus-Side General Calibration Value S bit 2
ADCCLPS_CLPS3       equ       3                   ; Plus-Side General Calibration Value S bit 3
ADCCLPS_CLPS4       equ       4                   ; Plus-Side General Calibration Value S bit 4
ADCCLPS_CLPS5       equ       5                   ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADCCLPS_CLPS0      equ       %00000001
mADCCLPS_CLPS1      equ       %00000010
mADCCLPS_CLPS2      equ       %00000100
mADCCLPS_CLPS3      equ       %00001000
mADCCLPS_CLPS4      equ       %00010000
mADCCLPS_CLPS5      equ       %00100000


;*** ADCCLP4 - Plus-Side General Calibration Value 4 Register
ADCCLP4             equ       $00001906           ;*** ADCCLP4 - Plus-Side General Calibration Value 4 Register


;*** ADCCLP4H - Plus-Side General Calibration Value 4 High Register
ADCCLP4H            equ       $00001906           ;*** ADCCLP4H - Plus-Side General Calibration Value 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP4H_CLP48      equ       0                   ; Plus-Side General Calibration Value 4 bit 8
ADCCLP4H_CLP49      equ       1                   ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADCCLP4H_CLP48     equ       %00000001
mADCCLP4H_CLP49     equ       %00000010


;*** ADCCLP4L - Plus-Side General Calibration Value 4 Low Register
ADCCLP4L            equ       $00001907           ;*** ADCCLP4L - Plus-Side General Calibration Value 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP4L_CLP40      equ       0                   ; Plus-Side General Calibration Value 4 bit 0
ADCCLP4L_CLP41      equ       1                   ; Plus-Side General Calibration Value 4 bit 1
ADCCLP4L_CLP42      equ       2                   ; Plus-Side General Calibration Value 4 bit 2
ADCCLP4L_CLP43      equ       3                   ; Plus-Side General Calibration Value 4 bit 3
ADCCLP4L_CLP44      equ       4                   ; Plus-Side General Calibration Value 4 bit 4
ADCCLP4L_CLP45      equ       5                   ; Plus-Side General Calibration Value 4 bit 5
ADCCLP4L_CLP46      equ       6                   ; Plus-Side General Calibration Value 4 bit 6
ADCCLP4L_CLP47      equ       7                   ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADCCLP4L_CLP40     equ       %00000001
mADCCLP4L_CLP41     equ       %00000010
mADCCLP4L_CLP42     equ       %00000100
mADCCLP4L_CLP43     equ       %00001000
mADCCLP4L_CLP44     equ       %00010000
mADCCLP4L_CLP45     equ       %00100000
mADCCLP4L_CLP46     equ       %01000000
mADCCLP4L_CLP47     equ       %10000000


;*** ADCCLP3 - Plus-Side General Calibration Value 3 Register
ADCCLP3             equ       $00001908           ;*** ADCCLP3 - Plus-Side General Calibration Value 3 Register


;*** ADCCLP3H - Plus-Side General Calibration Value 3 High Register
ADCCLP3H            equ       $00001908           ;*** ADCCLP3H - Plus-Side General Calibration Value 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP3H_CLP38      equ       0                   ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADCCLP3H_CLP38     equ       %00000001


;*** ADCCLP3L - Plus-Side General Calibration Value 3 Low Register
ADCCLP3L            equ       $00001909           ;*** ADCCLP3L - Plus-Side General Calibration Value 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP3L_CLP30      equ       0                   ; Plus-Side General Calibration Value 3 bit 0
ADCCLP3L_CLP31      equ       1                   ; Plus-Side General Calibration Value 3 bit 1
ADCCLP3L_CLP32      equ       2                   ; Plus-Side General Calibration Value 3 bit 2
ADCCLP3L_CLP33      equ       3                   ; Plus-Side General Calibration Value 3 bit 3
ADCCLP3L_CLP34      equ       4                   ; Plus-Side General Calibration Value 3 bit 4
ADCCLP3L_CLP35      equ       5                   ; Plus-Side General Calibration Value 3 bit 5
ADCCLP3L_CLP36      equ       6                   ; Plus-Side General Calibration Value 3 bit 6
ADCCLP3L_CLP37      equ       7                   ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADCCLP3L_CLP30     equ       %00000001
mADCCLP3L_CLP31     equ       %00000010
mADCCLP3L_CLP32     equ       %00000100
mADCCLP3L_CLP33     equ       %00001000
mADCCLP3L_CLP34     equ       %00010000
mADCCLP3L_CLP35     equ       %00100000
mADCCLP3L_CLP36     equ       %01000000
mADCCLP3L_CLP37     equ       %10000000


;*** ADCCLP2 - Plus-Side General Calibration Value 2 Register
ADCCLP2             equ       $0000190A           ;*** ADCCLP2 - Plus-Side General Calibration Value 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP2_CLP20       equ       0                   ; Plus-Side General Calibration Value 2 bit 0
ADCCLP2_CLP21       equ       1                   ; Plus-Side General Calibration Value 2 bit 1
ADCCLP2_CLP22       equ       2                   ; Plus-Side General Calibration Value 2 bit 2
ADCCLP2_CLP23       equ       3                   ; Plus-Side General Calibration Value 2 bit 3
ADCCLP2_CLP24       equ       4                   ; Plus-Side General Calibration Value 2 bit 4
ADCCLP2_CLP25       equ       5                   ; Plus-Side General Calibration Value 2 bit 5
ADCCLP2_CLP26       equ       6                   ; Plus-Side General Calibration Value 2 bit 6
ADCCLP2_CLP27       equ       7                   ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADCCLP2_CLP20      equ       %00000001
mADCCLP2_CLP21      equ       %00000010
mADCCLP2_CLP22      equ       %00000100
mADCCLP2_CLP23      equ       %00001000
mADCCLP2_CLP24      equ       %00010000
mADCCLP2_CLP25      equ       %00100000
mADCCLP2_CLP26      equ       %01000000
mADCCLP2_CLP27      equ       %10000000


;*** ADCCLP1 - Plus-Side General Calibration Value 1 Register
ADCCLP1             equ       $0000190B           ;*** ADCCLP1 - Plus-Side General Calibration Value 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP1_CLP10       equ       0                   ; Plus-Side General Calibration Value 1 bit 0
ADCCLP1_CLP11       equ       1                   ; Plus-Side General Calibration Value 1 bit 1
ADCCLP1_CLP12       equ       2                   ; Plus-Side General Calibration Value 1 bit 2
ADCCLP1_CLP13       equ       3                   ; Plus-Side General Calibration Value 1 bit 3
ADCCLP1_CLP14       equ       4                   ; Plus-Side General Calibration Value 1 bit 4
ADCCLP1_CLP15       equ       5                   ; Plus-Side General Calibration Value 1 bit 5
ADCCLP1_CLP16       equ       6                   ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADCCLP1_CLP10      equ       %00000001
mADCCLP1_CLP11      equ       %00000010
mADCCLP1_CLP12      equ       %00000100
mADCCLP1_CLP13      equ       %00001000
mADCCLP1_CLP14      equ       %00010000
mADCCLP1_CLP15      equ       %00100000
mADCCLP1_CLP16      equ       %01000000


;*** ADCCLP0 - Plus-Side General Calibration Value 0 Register
ADCCLP0             equ       $0000190C           ;*** ADCCLP0 - Plus-Side General Calibration Value 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP0_CLP00       equ       0                   ; Plus-Side General Calibration Value 0 bit 0
ADCCLP0_CLP01       equ       1                   ; Plus-Side General Calibration Value 0 bit 1
ADCCLP0_CLP02       equ       2                   ; Plus-Side General Calibration Value 0 bit 2
ADCCLP0_CLP03       equ       3                   ; Plus-Side General Calibration Value 0 bit 3
ADCCLP0_CLP04       equ       4                   ; Plus-Side General Calibration Value 0 bit 4
ADCCLP0_CLP05       equ       5                   ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADCCLP0_CLP00      equ       %00000001
mADCCLP0_CLP01      equ       %00000010
mADCCLP0_CLP02      equ       %00000100
mADCCLP0_CLP03      equ       %00001000
mADCCLP0_CLP04      equ       %00010000
mADCCLP0_CLP05      equ       %00100000


;*** ADCCLMD - Minus-Side General Calibration Value D Register
ADCCLMD             equ       $0000190E           ;*** ADCCLMD - Minus-Side General Calibration Value D Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLMD_CLMD0       equ       0                   ; Minus-Side General Calibration Value D bit 0
ADCCLMD_CLMD1       equ       1                   ; Minus-Side General Calibration Value D bit 1
ADCCLMD_CLMD2       equ       2                   ; Minus-Side General Calibration Value D bit 2
ADCCLMD_CLMD3       equ       3                   ; Minus-Side General Calibration Value D bit 3
ADCCLMD_CLMD4       equ       4                   ; Minus-Side General Calibration Value D bit 4
ADCCLMD_CLMD5       equ       5                   ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADCCLMD_CLMD0      equ       %00000001
mADCCLMD_CLMD1      equ       %00000010
mADCCLMD_CLMD2      equ       %00000100
mADCCLMD_CLMD3      equ       %00001000
mADCCLMD_CLMD4      equ       %00010000
mADCCLMD_CLMD5      equ       %00100000


;*** ADCCLMS - Minus-Side General Calibration Value S Register
ADCCLMS             equ       $0000190F           ;*** ADCCLMS - Minus-Side General Calibration Value S Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLMS_CLMS0       equ       0                   ; Minus-Side General Calibration Value S bit 0
ADCCLMS_CLMS1       equ       1                   ; Minus-Side General Calibration Value S bit 1
ADCCLMS_CLMS2       equ       2                   ; Minus-Side General Calibration Value S bit 2
ADCCLMS_CLMS3       equ       3                   ; Minus-Side General Calibration Value S bit 3
ADCCLMS_CLMS4       equ       4                   ; Minus-Side General Calibration Value S bit 4
ADCCLMS_CLMS5       equ       5                   ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADCCLMS_CLMS0      equ       %00000001
mADCCLMS_CLMS1      equ       %00000010
mADCCLMS_CLMS2      equ       %00000100
mADCCLMS_CLMS3      equ       %00001000
mADCCLMS_CLMS4      equ       %00010000
mADCCLMS_CLMS5      equ       %00100000


;*** ADCCLM4 - Minus-Side General Calibration Value 4 Register
ADCCLM4             equ       $00001910           ;*** ADCCLM4 - Minus-Side General Calibration Value 4 Register


;*** ADCCLM4H - Minus-Side General Calibration Value 4 High Register
ADCCLM4H            equ       $00001910           ;*** ADCCLM4H - Minus-Side General Calibration Value 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM4H_CLM48      equ       0                   ; Minus-Side General Calibration Value 4 bit 8
ADCCLM4H_CLM49      equ       1                   ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADCCLM4H_CLM48     equ       %00000001
mADCCLM4H_CLM49     equ       %00000010


;*** ADCCLM4L - Minus-Side General Calibration Value 4 Low Register
ADCCLM4L            equ       $00001911           ;*** ADCCLM4L - Minus-Side General Calibration Value 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM4L_CLM40      equ       0                   ; Minus-Side General Calibration Value 4 bit 0
ADCCLM4L_CLM41      equ       1                   ; Minus-Side General Calibration Value 4 bit 1
ADCCLM4L_CLM42      equ       2                   ; Minus-Side General Calibration Value 4 bit 2
ADCCLM4L_CLM43      equ       3                   ; Minus-Side General Calibration Value 4 bit 3
ADCCLM4L_CLM44      equ       4                   ; Minus-Side General Calibration Value 4 bit 4
ADCCLM4L_CLM45      equ       5                   ; Minus-Side General Calibration Value 4 bit 5
ADCCLM4L_CLM46      equ       6                   ; Minus-Side General Calibration Value 4 bit 6
ADCCLM4L_CLM47      equ       7                   ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADCCLM4L_CLM40     equ       %00000001
mADCCLM4L_CLM41     equ       %00000010
mADCCLM4L_CLM42     equ       %00000100
mADCCLM4L_CLM43     equ       %00001000
mADCCLM4L_CLM44     equ       %00010000
mADCCLM4L_CLM45     equ       %00100000
mADCCLM4L_CLM46     equ       %01000000
mADCCLM4L_CLM47     equ       %10000000


;*** ADCCLM3 - Minus-Side General Calibration Value 3 Register
ADCCLM3             equ       $00001912           ;*** ADCCLM3 - Minus-Side General Calibration Value 3 Register


;*** ADCCLM3H - Minus-Side General Calibration Value 3 High Register
ADCCLM3H            equ       $00001912           ;*** ADCCLM3H - Minus-Side General Calibration Value 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM3H_CLM38      equ       0                   ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADCCLM3H_CLM38     equ       %00000001


;*** ADCCLM3L - Minus-Side General Calibration Value 3 Low Register
ADCCLM3L            equ       $00001913           ;*** ADCCLM3L - Minus-Side General Calibration Value 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM3L_CLM30      equ       0                   ; Minus-Side General Calibration Value 3 bit 0
ADCCLM3L_CLM31      equ       1                   ; Minus-Side General Calibration Value 3 bit 1
ADCCLM3L_CLM32      equ       2                   ; Minus-Side General Calibration Value 3 bit 2
ADCCLM3L_CLM33      equ       3                   ; Minus-Side General Calibration Value 3 bit 3
ADCCLM3L_CLM34      equ       4                   ; Minus-Side General Calibration Value 3 bit 4
ADCCLM3L_CLM35      equ       5                   ; Minus-Side General Calibration Value 3 bit 5
ADCCLM3L_CLM36      equ       6                   ; Minus-Side General Calibration Value 3 bit 6
ADCCLM3L_CLM37      equ       7                   ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADCCLM3L_CLM30     equ       %00000001
mADCCLM3L_CLM31     equ       %00000010
mADCCLM3L_CLM32     equ       %00000100
mADCCLM3L_CLM33     equ       %00001000
mADCCLM3L_CLM34     equ       %00010000
mADCCLM3L_CLM35     equ       %00100000
mADCCLM3L_CLM36     equ       %01000000
mADCCLM3L_CLM37     equ       %10000000


;*** ADCCLM2 - Minus-Side General Calibration Value 2 Register
ADCCLM2             equ       $00001914           ;*** ADCCLM2 - Minus-Side General Calibration Value 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM2_CLM20       equ       0                   ; Minus-Side General Calibration Value 2 bit 0
ADCCLM2_CLM21       equ       1                   ; Minus-Side General Calibration Value 2 bit 1
ADCCLM2_CLM22       equ       2                   ; Minus-Side General Calibration Value 2 bit 2
ADCCLM2_CLM23       equ       3                   ; Minus-Side General Calibration Value 2 bit 3
ADCCLM2_CLM24       equ       4                   ; Minus-Side General Calibration Value 2 bit 4
ADCCLM2_CLM25       equ       5                   ; Minus-Side General Calibration Value 2 bit 5
ADCCLM2_CLM26       equ       6                   ; Minus-Side General Calibration Value 2 bit 6
ADCCLM2_CLM27       equ       7                   ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADCCLM2_CLM20      equ       %00000001
mADCCLM2_CLM21      equ       %00000010
mADCCLM2_CLM22      equ       %00000100
mADCCLM2_CLM23      equ       %00001000
mADCCLM2_CLM24      equ       %00010000
mADCCLM2_CLM25      equ       %00100000
mADCCLM2_CLM26      equ       %01000000
mADCCLM2_CLM27      equ       %10000000


;*** ADCCLM1 - Minus-Side General Calibration Value 1 Register
ADCCLM1             equ       $00001915           ;*** ADCCLM1 - Minus-Side General Calibration Value 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM1_CLM10       equ       0                   ; Minus-Side General Calibration Value 1 bit 0
ADCCLM1_CLM11       equ       1                   ; Minus-Side General Calibration Value 1 bit 1
ADCCLM1_CLM12       equ       2                   ; Minus-Side General Calibration Value 1 bit 2
ADCCLM1_CLM13       equ       3                   ; Minus-Side General Calibration Value 1 bit 3
ADCCLM1_CLM14       equ       4                   ; Minus-Side General Calibration Value 1 bit 4
ADCCLM1_CLM15       equ       5                   ; Minus-Side General Calibration Value 1 bit 5
ADCCLM1_CLM16       equ       6                   ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADCCLM1_CLM10      equ       %00000001
mADCCLM1_CLM11      equ       %00000010
mADCCLM1_CLM12      equ       %00000100
mADCCLM1_CLM13      equ       %00001000
mADCCLM1_CLM14      equ       %00010000
mADCCLM1_CLM15      equ       %00100000
mADCCLM1_CLM16      equ       %01000000


;*** ADCCLM0 - Minus-Side General Calibration Value 0 Register
ADCCLM0             equ       $00001916           ;*** ADCCLM0 - Minus-Side General Calibration Value 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM0_CLM00       equ       0                   ; Minus-Side General Calibration Value 0 bit 0
ADCCLM0_CLM01       equ       1                   ; Minus-Side General Calibration Value 0 bit 1
ADCCLM0_CLM02       equ       2                   ; Minus-Side General Calibration Value 0 bit 2
ADCCLM0_CLM03       equ       3                   ; Minus-Side General Calibration Value 0 bit 3
ADCCLM0_CLM04       equ       4                   ; Minus-Side General Calibration Value 0 bit 4
ADCCLM0_CLM05       equ       5                   ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADCCLM0_CLM00      equ       %00000001
mADCCLM0_CLM01      equ       %00000010
mADCCLM0_CLM02      equ       %00000100
mADCCLM0_CLM03      equ       %00001000
mADCCLM0_CLM04      equ       %00010000
mADCCLM0_CLM05      equ       %00100000


;*** APCTL1 - Pin Control 1 Register
APCTL1              equ       $00001917           ;*** APCTL1 - Pin Control 1 Register
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
APCTL2              equ       $00001918           ;*** APCTL2 - Pin Control 2 Register
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


;*** FCHKS - Flash Checksum Register
FCHKS               equ       $0000FFB8           ;*** FCHKS - Flash Checksum Register


;*** FCHKSH - Flash Checksum Register High Byte
FCHKSH              equ       $0000FFB8           ;*** FCHKSH - Flash Checksum Register High Byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCHKSH_CHECKSUM8    equ       0                   ; Flash checksum bit 8
FCHKSH_CHECKSUM9    equ       1                   ; Flash checksum bit 9
FCHKSH_CHECKSUM10   equ       2                   ; Flash checksum bit 10
FCHKSH_CHECKSUM11   equ       3                   ; Flash checksum bit 11
FCHKSH_CHECKSUM12   equ       4                   ; Flash checksum bit 12
FCHKSH_CHECKSUM13   equ       5                   ; Flash checksum bit 13
FCHKSH_CHECKSUM14   equ       6                   ; Flash checksum bit 14
FCHKSH_CHECKSUM15   equ       7                   ; Flash checksum bit 15
; bit position masks
mFCHKSH_CHECKSUM8   equ       %00000001
mFCHKSH_CHECKSUM9   equ       %00000010
mFCHKSH_CHECKSUM10  equ       %00000100
mFCHKSH_CHECKSUM11  equ       %00001000
mFCHKSH_CHECKSUM12  equ       %00010000
mFCHKSH_CHECKSUM13  equ       %00100000
mFCHKSH_CHECKSUM14  equ       %01000000
mFCHKSH_CHECKSUM15  equ       %10000000


;*** FCHKSL - Flash Checksum Register Low Byte
FCHKSL              equ       $0000FFB9           ;*** FCHKSL - Flash Checksum Register Low Byte
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCHKSL_CHECKSUM0    equ       0                   ; Flash checksum bits, bit 0
FCHKSL_CHECKSUM1    equ       1                   ; Flash checksum bits, bit 1
FCHKSL_CHECKSUM2    equ       2                   ; Flash checksum bits, bit 2
FCHKSL_CHECKSUM3    equ       3                   ; Flash checksum bits, bit 3
FCHKSL_CHECKSUM4    equ       4                   ; Flash checksum bits, bit 4
FCHKSL_CHECKSUM5    equ       5                   ; Flash checksum bits, bit 5
FCHKSL_CHECKSUM6    equ       6                   ; Flash checksum bits, bit 6
FCHKSL_CHECKSUM7    equ       7                   ; Flash checksum bits, bit 7
; bit position masks
mFCHKSL_CHECKSUM0   equ       %00000001
mFCHKSL_CHECKSUM1   equ       %00000010
mFCHKSL_CHECKSUM2   equ       %00000100
mFCHKSL_CHECKSUM3   equ       %00001000
mFCHKSL_CHECKSUM4   equ       %00010000
mFCHKSL_CHECKSUM5   equ       %00100000
mFCHKSL_CHECKSUM6   equ       %01000000
mFCHKSL_CHECKSUM7   equ       %10000000


;*** CHKSBYP - Checksum Bypass Register
CHKSBYP             equ       $0000FFBA           ;*** CHKSBYP - Checksum Bypass Register


;*** Partial_Erase_Semaphore - Flash partial erase semaphore
Partial_Erase_Semaphore equ       $0000FFBC           ;*** Partial_Erase_Semaphore - Flash partial erase semaphore


;*** NVPROT - Non-volatile Flash Protection Register
NVPROT              equ       $0000FFBD           ;*** NVPROT - Non-volatile Flash Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPOPEN       equ       0                   ; Flash Protection Open
NVPROT_FPS0         equ       1                   ; Flash Protection Size, bit 0
NVPROT_FPS1         equ       2                   ; Flash Protection Size, bit 1
NVPROT_FPS2         equ       3                   ; Flash Protection Size, bit 2
NVPROT_FPS3         equ       4                   ; Flash Protection Size, bit 3
NVPROT_FPS4         equ       5                   ; Flash Protection Size, bit 4
NVPROT_FPS5         equ       6                   ; Flash Protection Size, bit 5
NVPROT_FPS6         equ       7                   ; Flash Protection Size, bit 6
; bit position masks
mNVPROT_FPOPEN      equ       %00000001
mNVPROT_FPS0        equ       %00000010
mNVPROT_FPS1        equ       %00000100
mNVPROT_FPS2        equ       %00001000
mNVPROT_FPS3        equ       %00010000
mNVPROT_FPS4        equ       %00100000
mNVPROT_FPS5        equ       %01000000
mNVPROT_FPS6        equ       %10000000


;*** NVOPT - Non-volatile Flash Options Register
NVOPT               equ       $0000FFBF           ;*** NVOPT - Non-volatile Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC0          equ       0                   ; Flash Security Bit 0
NVOPT_SEC1          equ       1                   ; Flash Security Bit 1
NVOPT_KEYEN0        equ       6                   ; Backdoor Key Security Enable Bit 0
NVOPT_KEYEN1        equ       7                   ; Backdoor Key Security Enable Bit 1
; bit position masks
mNVOPT_SEC0         equ       %00000001
mNVOPT_SEC1         equ       %00000010
mNVOPT_KEYEN0       equ       %01000000
mNVOPT_KEYEN1       equ       %10000000



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

; **** 22.4.2010 13:24:38


; **** 25.6.2010 10:51:51

;*** SOPT5 - System Options Register 5
SOPT5               equ       $0000180D           ;*** SOPT5 - System Options Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT5_PMC_LVD_TRIM0 equ       0                   ; PMC LVD TRIM, bit 0
SOPT5_PMC_LVD_TRIM1 equ       1                   ; PMC LVD TRIM, bit 1
SOPT5_PMC_LVD_TRIM2 equ       2                   ; PMC LVD TRIM, bit 2
SOPT5_PMC_LVD_TRIM3 equ       3                   ; PMC LVD TRIM, bit 3
SOPT5_PMC_LVD_TRIM4 equ       4                   ; PMC LVD TRIM, bit 4
; bit position masks
mSOPT5_PMC_LVD_TRIM0 equ       %00000001
mSOPT5_PMC_LVD_TRIM1 equ       %00000010
mSOPT5_PMC_LVD_TRIM2 equ       %00000100
mSOPT5_PMC_LVD_TRIM3 equ       %00001000
mSOPT5_PMC_LVD_TRIM4 equ       %00010000

; EOF
