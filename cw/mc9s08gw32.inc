;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08GW64_80, version 3.00.000 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08gw32.inc
;     Processor : MC9S08GW32CLK
;     FileFormat: V2.32
;     DataSheet : MC9S08GW64RM Rev.3 Draft A 10/2010
;     Compiler  : CodeWarrior compiler
;     Date/Time : 1.11.2010, 16:46
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
;               - none
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROM                 equ       $0000C000
ROM_END             equ       $0000FF95
RAM                 equ       $000000C0
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $000008BF
STANDBYXRAM         equ       $000018C0
STANDBYXRAM_END     equ       $000018DF
PPAGE_2Start        equ       $00028000
PPAGE_2End          equ       $0002BFFF
;
Vpdb                equ       $0000FF96
Vpdb_err            equ       $0000FF98
Vlcd                equ       $0000FF9A
Virtc               equ       $0000FF9C
Vkbi                equ       $0000FF9E
VReserved45         equ       $0000FFA0
VReserved44         equ       $0000FFA2
VReserved43         equ       $0000FFA4
VReserved42         equ       $0000FFA6
VReserved41         equ       $0000FFA8
VReserved40         equ       $0000FFAA
VReserved39         equ       $0000FFAC
VReserved38         equ       $0000FFAE
VReserved37         equ       $0000FFB0
VReserved36         equ       $0000FFB2
VReserved35         equ       $0000FFB4
VReserved34         equ       $0000FFB6
VReserved33         equ       $0000FFB8
VReserved32         equ       $0000FFBA
VReserved31         equ       $0000FFBC
VReserved30         equ       $0000FFBE
Vpcnt               equ       $0000FFC0
Vpracmp2            equ       $0000FFC2
Vpracmp1            equ       $0000FFC4
Vpracmp0            equ       $0000FFC6
Vadc1               equ       $0000FFC8
Vadc0               equ       $0000FFCA
Vmtim3              equ       $0000FFCC
Vmtim2              equ       $0000FFCE
Vmtim1              equ       $0000FFD0
Vftmovf             equ       $0000FFD2
Vftmch0             equ       $0000FFD4
Vftmch1             equ       $0000FFD6
Viic                equ       $0000FFD8
Vspi2               equ       $0000FFDA
Vspi1               equ       $0000FFDC
Vspi0               equ       $0000FFDE
Vsci3tx             equ       $0000FFE0
Vsci3rx             equ       $0000FFE2
Vsci3err            equ       $0000FFE4
Vsci2tx             equ       $0000FFE6
Vsci2rx             equ       $0000FFE8
Vsci2err            equ       $0000FFEA
Vsci1tx             equ       $0000FFEC
Vsci1rx             equ       $0000FFEE
Vsci1err            equ       $0000FFF0
Vsci0tx             equ       $0000FFF2
Vsci0rx             equ       $0000FFF4
Vsci0err            equ       $0000FFF6
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
; bit position masks
mPTAD_PTAD0         equ       %00000001
mPTAD_PTAD1         equ       %00000010
mPTAD_PTAD2         equ       %00000100
mPTAD_PTAD3         equ       %00001000
mPTAD_PTAD4         equ       %00010000
mPTAD_PTAD5         equ       %00100000
mPTAD_PTAD6         equ       %01000000

;*** PTADD - Port A Data Direction Register
PTADD               equ       $00000001           ;*** PTADD - Port A Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0        equ       0                   ; Data Direction for Port A Bit 0
PTADD_PTADD1        equ       1                   ; Data Direction for Port A Bit 1
PTADD_PTADD2        equ       2                   ; Data Direction for Port A Bit 2
PTADD_PTADD3        equ       3                   ; Data Direction for Port A Bit 3
PTADD_PTADD4        equ       4                   ; Data Direction for Port A Bit 4
PTADD_PTADD5        equ       5                   ; Data Direction for Port A Bit 5
; bit position masks
mPTADD_PTADD0       equ       %00000001
mPTADD_PTADD1       equ       %00000010
mPTADD_PTADD2       equ       %00000100
mPTADD_PTADD3       equ       %00001000
mPTADD_PTADD4       equ       %00010000
mPTADD_PTADD5       equ       %00100000

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

;*** PTED - Port E Data Register
PTED                equ       $00000008           ;*** PTED - Port E Data Register
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
PTEDD               equ       $00000009           ;*** PTEDD - Port E Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0        equ       0                   ; Data Direction for Port E Bit 0
PTEDD_PTEDD1        equ       1                   ; Data Direction for Port E Bit 1
PTEDD_PTEDD2        equ       2                   ; Data Direction for Port E Bit 2
PTEDD_PTEDD3        equ       3                   ; Data Direction for Port E Bit 3
PTEDD_PTEDD4        equ       4                   ; Data Direction for Port E Bit 4
PTEDD_PTEDD5        equ       5                   ; Data Direction for Port E Bit 5
PTEDD_PTEDD6        equ       6                   ; Data Direction for Port E Bit 6
PTEDD_PTEDD7        equ       7                   ; Data Direction for Port E Bit 7
; bit position masks
mPTEDD_PTEDD0       equ       %00000001
mPTEDD_PTEDD1       equ       %00000010
mPTEDD_PTEDD2       equ       %00000100
mPTEDD_PTEDD3       equ       %00001000
mPTEDD_PTEDD4       equ       %00010000
mPTEDD_PTEDD5       equ       %00100000
mPTEDD_PTEDD6       equ       %01000000
mPTEDD_PTEDD7       equ       %10000000

;*** PTFD - Port F Data Register
PTFD                equ       $0000000A           ;*** PTFD - Port F Data Register
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
PTFDD               equ       $0000000B           ;*** PTFDD - Port F Data Direction Register
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

;*** PTGD - Port G Data Register
PTGD                equ       $0000000C           ;*** PTGD - Port G Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGD_PTGD0          equ       0                   ; Port G Data Register Bit 0
PTGD_PTGD1          equ       1                   ; Port G Data Register Bit 1
PTGD_PTGD2          equ       2                   ; Port G Data Register Bit 2
PTGD_PTGD3          equ       3                   ; Port G Data Register Bit 3
PTGD_PTGD4          equ       4                   ; Port G Data Register Bit 4
PTGD_PTGD5          equ       5                   ; Port G Data Register Bit 5
PTGD_PTGD6          equ       6                   ; Port G Data Register Bit 6
PTGD_PTGD7          equ       7                   ; Port G Data Register Bit 7
; bit position masks
mPTGD_PTGD0         equ       %00000001
mPTGD_PTGD1         equ       %00000010
mPTGD_PTGD2         equ       %00000100
mPTGD_PTGD3         equ       %00001000
mPTGD_PTGD4         equ       %00010000
mPTGD_PTGD5         equ       %00100000
mPTGD_PTGD6         equ       %01000000
mPTGD_PTGD7         equ       %10000000

;*** PTGDD - Port G Data Direction Register
PTGDD               equ       $0000000D           ;*** PTGDD - Port G Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDD_PTGDD0        equ       0                   ; Data Direction for Port G Bit 0
PTGDD_PTGDD1        equ       1                   ; Data Direction for Port G Bit 1
PTGDD_PTGDD2        equ       2                   ; Data Direction for Port G Bit 2
PTGDD_PTGDD3        equ       3                   ; Data Direction for Port G Bit 3
PTGDD_PTGDD4        equ       4                   ; Data Direction for Port G Bit 4
PTGDD_PTGDD5        equ       5                   ; Data Direction for Port G Bit 5
PTGDD_PTGDD6        equ       6                   ; Data Direction for Port G Bit 6
PTGDD_PTGDD7        equ       7                   ; Data Direction for Port G Bit 7
; bit position masks
mPTGDD_PTGDD0       equ       %00000001
mPTGDD_PTGDD1       equ       %00000010
mPTGDD_PTGDD2       equ       %00000100
mPTGDD_PTGDD3       equ       %00001000
mPTGDD_PTGDD4       equ       %00010000
mPTGDD_PTGDD5       equ       %00100000
mPTGDD_PTGDD6       equ       %01000000
mPTGDD_PTGDD7       equ       %10000000

;*** PTHD - Port H Data Register
PTHD                equ       $0000000E           ;*** PTHD - Port H Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHD_PTHD0          equ       0                   ; Port H Data Register Bit 0
PTHD_PTHD1          equ       1                   ; Port H Data Register Bit 1
; bit position masks
mPTHD_PTHD0         equ       %00000001
mPTHD_PTHD1         equ       %00000010

;*** PTHDD - Port H Data Direction Register
PTHDD               equ       $0000000F           ;*** PTHDD - Port H Data Direction Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDD_PTHDD0        equ       0                   ; Data Direction for Port H Bit 0
PTHDD_PTHDD1        equ       1                   ; Data Direction for Port H Bit 1
; bit position masks
mPTHDD_PTHDD0       equ       %00000001
mPTHDD_PTHDD1       equ       %00000010

;*** MTIM1SC - MTIM Clock Configuration Register
MTIM1SC             equ       $00000010           ;*** MTIM1SC - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM1SC_TSTP        equ       4                   ; MTIM Counter Stop
MTIM1SC_TRST        equ       5                   ; MTIM Counter Reset
MTIM1SC_TOIE        equ       6                   ; MTIM Overflow Interrupt Enable
MTIM1SC_TOF         equ       7                   ; MTIM Overflow Flag
; bit position masks
mMTIM1SC_TSTP       equ       %00010000
mMTIM1SC_TRST       equ       %00100000
mMTIM1SC_TOIE       equ       %01000000
mMTIM1SC_TOF        equ       %10000000

;*** MTIM1CLK - MTIM Clock Configuration Register
MTIM1CLK            equ       $00000011           ;*** MTIM1CLK - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM1CLK_PS0        equ       0                   ; Clock source Prescaler Bit 0
MTIM1CLK_PS1        equ       1                   ; Clock source Prescaler Bit 1
MTIM1CLK_PS2        equ       2                   ; Clock source Prescaler Bit 2
MTIM1CLK_PS3        equ       3                   ; Clock source Prescaler Bit 3
MTIM1CLK_CLKS0      equ       4                   ; Clock source Select Bit 0
MTIM1CLK_CLKS1      equ       5                   ; Clock source Select Bit 1
; bit position masks
mMTIM1CLK_PS0       equ       %00000001
mMTIM1CLK_PS1       equ       %00000010
mMTIM1CLK_PS2       equ       %00000100
mMTIM1CLK_PS3       equ       %00001000
mMTIM1CLK_CLKS0     equ       %00010000
mMTIM1CLK_CLKS1     equ       %00100000

;*** MTIM1CNT - MTIM Counter Register
MTIM1CNT            equ       $00000012           ;*** MTIM1CNT - MTIM Counter Register

;*** MTIM1MOD - MTIM Modulo Register
MTIM1MOD            equ       $00000013           ;*** MTIM1MOD - MTIM Modulo Register

;*** MTIM2SC - MTIM Clock Configuration Register
MTIM2SC             equ       $00000014           ;*** MTIM2SC - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM2SC_TSTP        equ       4                   ; MTIM Counter Stop
MTIM2SC_TRST        equ       5                   ; MTIM Counter Reset
MTIM2SC_TOIE        equ       6                   ; MTIM Overflow Interrupt Enable
MTIM2SC_TOF         equ       7                   ; MTIM Overflow Flag
; bit position masks
mMTIM2SC_TSTP       equ       %00010000
mMTIM2SC_TRST       equ       %00100000
mMTIM2SC_TOIE       equ       %01000000
mMTIM2SC_TOF        equ       %10000000

;*** MTIM2CLK - MTIM Clock Configuration Register
MTIM2CLK            equ       $00000015           ;*** MTIM2CLK - MTIM Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM2CLK_PS0        equ       0                   ; Clock source Prescaler Bit 0
MTIM2CLK_PS1        equ       1                   ; Clock source Prescaler Bit 1
MTIM2CLK_PS2        equ       2                   ; Clock source Prescaler Bit 2
MTIM2CLK_PS3        equ       3                   ; Clock source Prescaler Bit 3
MTIM2CLK_CLKS0      equ       4                   ; Clock source Select Bit 0
MTIM2CLK_CLKS1      equ       5                   ; Clock source Select Bit 1
; bit position masks
mMTIM2CLK_PS0       equ       %00000001
mMTIM2CLK_PS1       equ       %00000010
mMTIM2CLK_PS2       equ       %00000100
mMTIM2CLK_PS3       equ       %00001000
mMTIM2CLK_CLKS0     equ       %00010000
mMTIM2CLK_CLKS1     equ       %00100000

;*** MTIM2CNT - MTIM Counter Register
MTIM2CNT            equ       $00000016           ;*** MTIM2CNT - MTIM Counter Register

;*** MTIM2MOD - MTIM Modulo Register
MTIM2MOD            equ       $00000017           ;*** MTIM2MOD - MTIM Modulo Register

;*** MTIM3SC - MTIM16 Status and Control Register
MTIM3SC             equ       $00000018           ;*** MTIM3SC - MTIM16 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM3SC_TSTP        equ       4                   ; MTIM16 Counter Stop
MTIM3SC_TRST        equ       5                   ; MTIM16 Counter Reset
MTIM3SC_TOIE        equ       6                   ; MTIM16 Overflow Interrupt Enable
MTIM3SC_TOF         equ       7                   ; MTIM16 Overflow Flag
; bit position masks
mMTIM3SC_TSTP       equ       %00010000
mMTIM3SC_TRST       equ       %00100000
mMTIM3SC_TOIE       equ       %01000000
mMTIM3SC_TOF        equ       %10000000

;*** MTIM3CLK - MTIM16 Clock Configuration Register
MTIM3CLK            equ       $00000019           ;*** MTIM3CLK - MTIM16 Clock Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
MTIM3CLK_PS0        equ       0                   ; Clock source Prescaler Bit 0
MTIM3CLK_PS1        equ       1                   ; Clock source Prescaler Bit 1
MTIM3CLK_PS2        equ       2                   ; Clock source Prescaler Bit 2
MTIM3CLK_PS3        equ       3                   ; Clock source Prescaler Bit 3
MTIM3CLK_CLKS0      equ       4                   ; Clock source Select Bit 0
MTIM3CLK_CLKS1      equ       5                   ; Clock source Select Bit 1
; bit position masks
mMTIM3CLK_PS0       equ       %00000001
mMTIM3CLK_PS1       equ       %00000010
mMTIM3CLK_PS2       equ       %00000100
mMTIM3CLK_PS3       equ       %00001000
mMTIM3CLK_CLKS0     equ       %00010000
mMTIM3CLK_CLKS1     equ       %00100000

;*** MTIM3CNT - MTIM16 Counter Register
MTIM3CNT            equ       $0000001A           ;*** MTIM3CNT - MTIM16 Counter Register

;*** MTIM3CNTH - MTIM16 Counter Register High
MTIM3CNTH           equ       $0000001A           ;*** MTIM3CNTH - MTIM16 Counter Register High

;*** MTIM3CNTL - MTIM16 Counter Register Low
MTIM3CNTL           equ       $0000001B           ;*** MTIM3CNTL - MTIM16 Counter Register Low

;*** MTIM3MOD - MTIM16 Modulo Register
MTIM3MOD            equ       $0000001C           ;*** MTIM3MOD - MTIM16 Modulo Register

;*** MTIM3MODH - MTIM16 Modulo Register High
MTIM3MODH           equ       $0000001C           ;*** MTIM3MODH - MTIM16 Modulo Register High

;*** MTIM3MODL - MTIM16 Modulo Register Low
MTIM3MODL           equ       $0000001D           ;*** MTIM3MODL - MTIM16 Modulo Register Low

;*** PDBSC - PDB Status and Control Register
PDBSC               equ       $00000020           ;*** PDBSC - PDB Status and Control Register

;*** PDBSCH - PDB Status and Control High Register
PDBSCH              equ       $00000020           ;*** PDBSCH - PDB Status and Control High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBSCH_PRESCALER0   equ       5                   ; Clock Prescaler Select, bit 0
PDBSCH_PRESCALER1   equ       6                   ; Clock Prescaler Select, bit 1
PDBSCH_PRESCALER2   equ       7                   ; Clock Prescaler Select, bit 2
; bit position masks
mPDBSCH_PRESCALER0  equ       %00100000
mPDBSCH_PRESCALER1  equ       %01000000
mPDBSCH_PRESCALER2  equ       %10000000

;*** PDBSCL - PDB Status and Control Low Register
PDBSCL              equ       $00000021           ;*** PDBSCL - PDB Status and Control Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBSCL_EN           equ       0                   ; Module Enable
PDBSCL_IE           equ       1                   ; Interrupt Enable
PDBSCL_TRIGSEL0     equ       2                   ; Input Trigger Select, bit 0
PDBSCL_TRIGSEL1     equ       3                   ; Input Trigger Select, bit 1
PDBSCL_TRIGSEL2     equ       4                   ; Input Trigger Select, bit 2
PDBSCL_SWTRIG       equ       5                   ; Software Trigger
PDBSCL_CONT         equ       6                   ; Continuous Mode Enable
PDBSCL_IF           equ       7                   ; Interrupt Flag
; bit position masks
mPDBSCL_EN          equ       %00000001
mPDBSCL_IE          equ       %00000010
mPDBSCL_TRIGSEL0    equ       %00000100
mPDBSCL_TRIGSEL1    equ       %00001000
mPDBSCL_TRIGSEL2    equ       %00010000
mPDBSCL_SWTRIG      equ       %00100000
mPDBSCL_CONT        equ       %01000000
mPDBSCL_IF          equ       %10000000

;*** PDBMOD - PDB Counter Modulus Register
PDBMOD              equ       $00000022           ;*** PDBMOD - PDB Counter Modulus Register

;*** PDBMODH - PDB Counter Modulus High Register
PDBMODH             equ       $00000022           ;*** PDBMODH - PDB Counter Modulus High Register

;*** PDBMODL - PDB Counter Modulus Low Register
PDBMODL             equ       $00000023           ;*** PDBMODL - PDB Counter Modulus Low Register

;*** PDBCNT - PDB Counter Value Register
PDBCNT              equ       $00000024           ;*** PDBCNT - PDB Counter Value Register

;*** PDBCNTH - PDB Counter Value High Register
PDBCNTH             equ       $00000024           ;*** PDBCNTH - PDB Counter Value High Register

;*** PDBCNTL - PDB Counter Value Low Register
PDBCNTL             equ       $00000025           ;*** PDBCNTL - PDB Counter Value Low Register

;*** PDBIDLY - PDB Interrupt Delay Register
PDBIDLY             equ       $00000026           ;*** PDBIDLY - PDB Interrupt Delay Register

;*** PDBIDLYH - PDB Interrupt Delay High Register
PDBIDLYH            equ       $00000026           ;*** PDBIDLYH - PDB Interrupt Delay High Register
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

;*** PDBIDLYL - PDB Interrupt Delay Low Register
PDBIDLYL            equ       $00000027           ;*** PDBIDLYL - PDB Interrupt Delay Low Register
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

;*** PDBCH1CR - PDB Channel 1 Control Register
PDBCH1CR            equ       $00000028           ;*** PDBCH1CR - PDB Channel 1 Control Register

;*** PDBCH1CRH - PDB Channel 1 Control High Register
PDBCH1CRH           equ       $00000028           ;*** PDBCH1CRH - PDB Channel 1 Control High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1CRH_ERRB      equ       6                   ; Sequence error on TriggerB
PDBCH1CRH_ERRA      equ       7                   ; Sequence error on TriggerA
; bit position masks
mPDBCH1CRH_ERRB     equ       %01000000
mPDBCH1CRH_ERRA     equ       %10000000

;*** PDBCH1CRL - PDB Channel 1 Control Low Register
PDBCH1CRL           equ       $00000029           ;*** PDBCH1CRL - PDB Channel 1 Control Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1CRL_ENB       equ       0                   ; Trigger B Enable
PDBCH1CRL_ENA       equ       1                   ; Trigger A Enable
PDBCH1CRL_BOS0      equ       2                   ; Channel 1 Trigger B Output Select, bit 0
PDBCH1CRL_BOS1      equ       3                   ; Channel 1 Trigger B Output Select, bit 1
PDBCH1CRL_AOS0      equ       4                   ; Channel 1 Trigger A Output Select, bit 0
PDBCH1CRL_AOS1      equ       5                   ; Channel 1 Trigger A Output Select, bit 1
; bit position masks
mPDBCH1CRL_ENB      equ       %00000001
mPDBCH1CRL_ENA      equ       %00000010
mPDBCH1CRL_BOS0     equ       %00000100
mPDBCH1CRL_BOS1     equ       %00001000
mPDBCH1CRL_AOS0     equ       %00010000
mPDBCH1CRL_AOS1     equ       %00100000

;*** PDBCH1DLYA - PDB Channel 1 Delay A Register
PDBCH1DLYA          equ       $0000002A           ;*** PDBCH1DLYA - PDB Channel 1 Delay A Register

;*** PDBCH1DLYAH - PDB Channel 1 Delay A High Register
PDBCH1DLYAH         equ       $0000002A           ;*** PDBCH1DLYAH - PDB Channel 1 Delay A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1DLYAH_DELAYA8 equ       0                   ; Delay A, bit 8
PDBCH1DLYAH_DELAYA9 equ       1                   ; Delay A, bit 9
PDBCH1DLYAH_DELAYA10 equ       2                   ; Delay A, bit 10
PDBCH1DLYAH_DELAYA11 equ       3                   ; Delay A, bit 11
PDBCH1DLYAH_DELAYA12 equ       4                   ; Delay A, bit 12
PDBCH1DLYAH_DELAYA13 equ       5                   ; Delay A, bit 13
PDBCH1DLYAH_DELAYA14 equ       6                   ; Delay A, bit 14
PDBCH1DLYAH_DELAYA15 equ       7                   ; Delay A, bit 15
; bit position masks
mPDBCH1DLYAH_DELAYA8 equ       %00000001
mPDBCH1DLYAH_DELAYA9 equ       %00000010
mPDBCH1DLYAH_DELAYA10 equ       %00000100
mPDBCH1DLYAH_DELAYA11 equ       %00001000
mPDBCH1DLYAH_DELAYA12 equ       %00010000
mPDBCH1DLYAH_DELAYA13 equ       %00100000
mPDBCH1DLYAH_DELAYA14 equ       %01000000
mPDBCH1DLYAH_DELAYA15 equ       %10000000

;*** PDBCH1DLYAL - PDB Channel 1 Delay A Low Register
PDBCH1DLYAL         equ       $0000002B           ;*** PDBCH1DLYAL - PDB Channel 1 Delay A Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1DLYAL_DELAYA0 equ       0                   ; Delay A, bit 0
PDBCH1DLYAL_DELAYA1 equ       1                   ; Delay A, bit 1
PDBCH1DLYAL_DELAYA2 equ       2                   ; Delay A, bit 2
PDBCH1DLYAL_DELAYA3 equ       3                   ; Delay A, bit 3
PDBCH1DLYAL_DELAYA4 equ       4                   ; Delay A, bit 4
PDBCH1DLYAL_DELAYA5 equ       5                   ; Delay A, bit 5
PDBCH1DLYAL_DELAYA6 equ       6                   ; Delay A, bit 6
PDBCH1DLYAL_DELAYA7 equ       7                   ; Delay A, bit 7
; bit position masks
mPDBCH1DLYAL_DELAYA0 equ       %00000001
mPDBCH1DLYAL_DELAYA1 equ       %00000010
mPDBCH1DLYAL_DELAYA2 equ       %00000100
mPDBCH1DLYAL_DELAYA3 equ       %00001000
mPDBCH1DLYAL_DELAYA4 equ       %00010000
mPDBCH1DLYAL_DELAYA5 equ       %00100000
mPDBCH1DLYAL_DELAYA6 equ       %01000000
mPDBCH1DLYAL_DELAYA7 equ       %10000000

;*** PDBCH1DLYB - PDB Channel 1 Delay B Register
PDBCH1DLYB          equ       $0000002C           ;*** PDBCH1DLYB - PDB Channel 1 Delay B Register

;*** PDBCH1DLYBH - PDB Channel 1 Delay B High Register
PDBCH1DLYBH         equ       $0000002C           ;*** PDBCH1DLYBH - PDB Channel 1 Delay B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1DLYBH_DELAYB8 equ       0                   ; Delay B, bit 8
PDBCH1DLYBH_DELAYB9 equ       1                   ; Delay B, bit 9
PDBCH1DLYBH_DELAYB10 equ       2                   ; Delay B, bit 10
PDBCH1DLYBH_DELAYB11 equ       3                   ; Delay B, bit 11
PDBCH1DLYBH_DELAYB12 equ       4                   ; Delay B, bit 12
PDBCH1DLYBH_DELAYB13 equ       5                   ; Delay B, bit 13
PDBCH1DLYBH_DELAYB14 equ       6                   ; Delay B, bit 14
PDBCH1DLYBH_DELAYB15 equ       7                   ; Delay B, bit 15
; bit position masks
mPDBCH1DLYBH_DELAYB8 equ       %00000001
mPDBCH1DLYBH_DELAYB9 equ       %00000010
mPDBCH1DLYBH_DELAYB10 equ       %00000100
mPDBCH1DLYBH_DELAYB11 equ       %00001000
mPDBCH1DLYBH_DELAYB12 equ       %00010000
mPDBCH1DLYBH_DELAYB13 equ       %00100000
mPDBCH1DLYBH_DELAYB14 equ       %01000000
mPDBCH1DLYBH_DELAYB15 equ       %10000000

;*** PDBCH1DLYBL - PDB Channel 1 Delay B Low Register
PDBCH1DLYBL         equ       $0000002D           ;*** PDBCH1DLYBL - PDB Channel 1 Delay B Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH1DLYBL_DELAYB0 equ       0                   ; Delay B, bit 0
PDBCH1DLYBL_DELAYB1 equ       1                   ; Delay B, bit 1
PDBCH1DLYBL_DELAYB2 equ       2                   ; Delay B, bit 2
PDBCH1DLYBL_DELAYB3 equ       3                   ; Delay B, bit 3
PDBCH1DLYBL_DELAYB4 equ       4                   ; Delay B, bit 4
PDBCH1DLYBL_DELAYB5 equ       5                   ; Delay B, bit 5
PDBCH1DLYBL_DELAYB6 equ       6                   ; Delay B, bit 6
PDBCH1DLYBL_DELAYB7 equ       7                   ; Delay B, bit 7
; bit position masks
mPDBCH1DLYBL_DELAYB0 equ       %00000001
mPDBCH1DLYBL_DELAYB1 equ       %00000010
mPDBCH1DLYBL_DELAYB2 equ       %00000100
mPDBCH1DLYBL_DELAYB3 equ       %00001000
mPDBCH1DLYBL_DELAYB4 equ       %00010000
mPDBCH1DLYBL_DELAYB5 equ       %00100000
mPDBCH1DLYBL_DELAYB6 equ       %01000000
mPDBCH1DLYBL_DELAYB7 equ       %10000000

;*** PDBCH2CR - PDB Channel 2 Control Register
PDBCH2CR            equ       $00000030           ;*** PDBCH2CR - PDB Channel 2 Control Register

;*** PDBCH2CRH - PDB Channel 2 Control High Register
PDBCH2CRH           equ       $00000030           ;*** PDBCH2CRH - PDB Channel 2 Control High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2CRH_ERRB      equ       6                   ; Sequence error on TriggerB
PDBCH2CRH_ERRA      equ       7                   ; Sequence error on TriggerA
; bit position masks
mPDBCH2CRH_ERRB     equ       %01000000
mPDBCH2CRH_ERRA     equ       %10000000

;*** PDBCH2CRL - PDB Channel 2 Control Low Register
PDBCH2CRL           equ       $00000031           ;*** PDBCH2CRL - PDB Channel 2 Control Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2CRL_ENB       equ       0                   ; Trigger B Enable
PDBCH2CRL_ENA       equ       1                   ; Trigger A Enable
PDBCH2CRL_BOS0      equ       2                   ; Channel 2 Trigger B Output Select, bit 0
PDBCH2CRL_BOS1      equ       3                   ; Channel 2 Trigger B Output Select, bit 1
PDBCH2CRL_AOS0      equ       4                   ; Channel 2 Trigger A Output Select, bit 0
PDBCH2CRL_AOS1      equ       5                   ; Channel 2 Trigger A Output Select, bit 1
; bit position masks
mPDBCH2CRL_ENB      equ       %00000001
mPDBCH2CRL_ENA      equ       %00000010
mPDBCH2CRL_BOS0     equ       %00000100
mPDBCH2CRL_BOS1     equ       %00001000
mPDBCH2CRL_AOS0     equ       %00010000
mPDBCH2CRL_AOS1     equ       %00100000

;*** PDBCH2DLYA - PDB Channel 2 Delay A Register
PDBCH2DLYA          equ       $00000032           ;*** PDBCH2DLYA - PDB Channel 2 Delay A Register

;*** PDBCH2DLYAH - PDB Channel 2 Delay A High Register
PDBCH2DLYAH         equ       $00000032           ;*** PDBCH2DLYAH - PDB Channel 2 Delay A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2DLYAH_DELAYA8 equ       0                   ; Delay A, bit 8
PDBCH2DLYAH_DELAYA9 equ       1                   ; Delay A, bit 9
PDBCH2DLYAH_DELAYA10 equ       2                   ; Delay A, bit 10
PDBCH2DLYAH_DELAYA11 equ       3                   ; Delay A, bit 11
PDBCH2DLYAH_DELAYA12 equ       4                   ; Delay A, bit 12
PDBCH2DLYAH_DELAYA13 equ       5                   ; Delay A, bit 13
PDBCH2DLYAH_DELAYA14 equ       6                   ; Delay A, bit 14
PDBCH2DLYAH_DELAYA15 equ       7                   ; Delay A, bit 15
; bit position masks
mPDBCH2DLYAH_DELAYA8 equ       %00000001
mPDBCH2DLYAH_DELAYA9 equ       %00000010
mPDBCH2DLYAH_DELAYA10 equ       %00000100
mPDBCH2DLYAH_DELAYA11 equ       %00001000
mPDBCH2DLYAH_DELAYA12 equ       %00010000
mPDBCH2DLYAH_DELAYA13 equ       %00100000
mPDBCH2DLYAH_DELAYA14 equ       %01000000
mPDBCH2DLYAH_DELAYA15 equ       %10000000

;*** PDBCH2DLYAL - PDB Channel 2 Delay A Low Register
PDBCH2DLYAL         equ       $00000033           ;*** PDBCH2DLYAL - PDB Channel 2 Delay A Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2DLYAL_DELAYA0 equ       0                   ; Delay A, bit 0
PDBCH2DLYAL_DELAYA1 equ       1                   ; Delay A, bit 1
PDBCH2DLYAL_DELAYA2 equ       2                   ; Delay A, bit 2
PDBCH2DLYAL_DELAYA3 equ       3                   ; Delay A, bit 3
PDBCH2DLYAL_DELAYA4 equ       4                   ; Delay A, bit 4
PDBCH2DLYAL_DELAYA5 equ       5                   ; Delay A, bit 5
PDBCH2DLYAL_DELAYA6 equ       6                   ; Delay A, bit 6
PDBCH2DLYAL_DELAYA7 equ       7                   ; Delay A, bit 7
; bit position masks
mPDBCH2DLYAL_DELAYA0 equ       %00000001
mPDBCH2DLYAL_DELAYA1 equ       %00000010
mPDBCH2DLYAL_DELAYA2 equ       %00000100
mPDBCH2DLYAL_DELAYA3 equ       %00001000
mPDBCH2DLYAL_DELAYA4 equ       %00010000
mPDBCH2DLYAL_DELAYA5 equ       %00100000
mPDBCH2DLYAL_DELAYA6 equ       %01000000
mPDBCH2DLYAL_DELAYA7 equ       %10000000

;*** PDBCH2DLYB - PDB Channel 2 Delay B Register
PDBCH2DLYB          equ       $00000034           ;*** PDBCH2DLYB - PDB Channel 2 Delay B Register

;*** PDBCH2DLYBH - PDB Channel 2 Delay B High Register
PDBCH2DLYBH         equ       $00000034           ;*** PDBCH2DLYBH - PDB Channel 2 Delay B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2DLYBH_DELAYB8 equ       0                   ; Delay B, bit 8
PDBCH2DLYBH_DELAYB9 equ       1                   ; Delay B, bit 9
PDBCH2DLYBH_DELAYB10 equ       2                   ; Delay B, bit 10
PDBCH2DLYBH_DELAYB11 equ       3                   ; Delay B, bit 11
PDBCH2DLYBH_DELAYB12 equ       4                   ; Delay B, bit 12
PDBCH2DLYBH_DELAYB13 equ       5                   ; Delay B, bit 13
PDBCH2DLYBH_DELAYB14 equ       6                   ; Delay B, bit 14
PDBCH2DLYBH_DELAYB15 equ       7                   ; Delay B, bit 15
; bit position masks
mPDBCH2DLYBH_DELAYB8 equ       %00000001
mPDBCH2DLYBH_DELAYB9 equ       %00000010
mPDBCH2DLYBH_DELAYB10 equ       %00000100
mPDBCH2DLYBH_DELAYB11 equ       %00001000
mPDBCH2DLYBH_DELAYB12 equ       %00010000
mPDBCH2DLYBH_DELAYB13 equ       %00100000
mPDBCH2DLYBH_DELAYB14 equ       %01000000
mPDBCH2DLYBH_DELAYB15 equ       %10000000

;*** PDBCH2DLYBL - PDB Channel 2 Delay B Low Register
PDBCH2DLYBL         equ       $00000035           ;*** PDBCH2DLYBL - PDB Channel 2 Delay B Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PDBCH2DLYBL_DELAYB0 equ       0                   ; Delay B, bit 0
PDBCH2DLYBL_DELAYB1 equ       1                   ; Delay B, bit 1
PDBCH2DLYBL_DELAYB2 equ       2                   ; Delay B, bit 2
PDBCH2DLYBL_DELAYB3 equ       3                   ; Delay B, bit 3
PDBCH2DLYBL_DELAYB4 equ       4                   ; Delay B, bit 4
PDBCH2DLYBL_DELAYB5 equ       5                   ; Delay B, bit 5
PDBCH2DLYBL_DELAYB6 equ       6                   ; Delay B, bit 6
PDBCH2DLYBL_DELAYB7 equ       7                   ; Delay B, bit 7
; bit position masks
mPDBCH2DLYBL_DELAYB0 equ       %00000001
mPDBCH2DLYBL_DELAYB1 equ       %00000010
mPDBCH2DLYBL_DELAYB2 equ       %00000100
mPDBCH2DLYBL_DELAYB3 equ       %00001000
mPDBCH2DLYBL_DELAYB4 equ       %00010000
mPDBCH2DLYBL_DELAYB5 equ       %00100000
mPDBCH2DLYBL_DELAYB6 equ       %01000000
mPDBCH2DLYBL_DELAYB7 equ       %10000000

;*** PPAGE - Program Page Register
PPAGE               equ       $00000038           ;*** PPAGE - Program Page Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPAGE_XA14          equ       0                   ; Extended address, bit 14
PPAGE_XA15          equ       1                   ; Extended address, bit 15
PPAGE_XA16          equ       2                   ; Extended address, bit 16
; bit position masks
mPPAGE_XA14         equ       %00000001
mPPAGE_XA15         equ       %00000010
mPPAGE_XA16         equ       %00000100

;*** LAP2 - Linear Address Pointer Register 2
LAP2                equ       $00000039           ;*** LAP2 - Linear Address Pointer Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP2_LA16           equ       0                   ; Linear address pointer, bit 16
; bit position masks
mLAP2_LA16          equ       %00000001

;*** LAP1 - Linear Address Pointer Register 1
LAP1                equ       $0000003A           ;*** LAP1 - Linear Address Pointer Register 1
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
LAP0                equ       $0000003B           ;*** LAP0 - Linear Address Pointer Register 0
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
LWP                 equ       $0000003C           ;*** LWP - Linear Word Post Increment Register
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
LBP                 equ       $0000003D           ;*** LBP - Linear Byte Post Increment Register
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
LB                  equ       $0000003E           ;*** LB - Linear Byte Register
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
LAPAB               equ       $0000003F           ;*** LAPAB - Linear Address Pointer Add Byte Register
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

;*** ADC0SC1A - Status and Control Register 1A
ADC0SC1A            equ       $00000040           ;*** ADC0SC1A - Status and Control Register 1A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0SC1A_ADCHA0     equ       0                   ; Input Channel Select Bit 0
ADC0SC1A_ADCHA1     equ       1                   ; Input Channel Select Bit 1
ADC0SC1A_ADCHA2     equ       2                   ; Input Channel Select Bit 2
ADC0SC1A_ADCHA3     equ       3                   ; Input Channel Select Bit 3
ADC0SC1A_ADCHA4     equ       4                   ; Input Channel Select Bit 4
ADC0SC1A_DIFFA      equ       5                   ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC0SC1A_AIENA      equ       6                   ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA
ADC0SC1A_COCOA      equ       7                   ; Conversion Complete Flag
; bit position masks
mADC0SC1A_ADCHA0    equ       %00000001
mADC0SC1A_ADCHA1    equ       %00000010
mADC0SC1A_ADCHA2    equ       %00000100
mADC0SC1A_ADCHA3    equ       %00001000
mADC0SC1A_ADCHA4    equ       %00010000
mADC0SC1A_DIFFA     equ       %00100000
mADC0SC1A_AIENA     equ       %01000000
mADC0SC1A_COCOA     equ       %10000000

;*** ADC0SC1B - Status and Control Register 1B
ADC0SC1B            equ       $00000041           ;*** ADC0SC1B - Status and Control Register 1B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0SC1B_ADCHB0     equ       0                   ; Input Channel Select Bit 0
ADC0SC1B_ADCHB1     equ       1                   ; Input Channel Select Bit 1
ADC0SC1B_ADCHB2     equ       2                   ; Input Channel Select Bit 2
ADC0SC1B_ADCHB3     equ       3                   ; Input Channel Select Bit 3
ADC0SC1B_ADCHB4     equ       4                   ; Input Channel Select Bit 4
ADC0SC1B_DIFFB      equ       5                   ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC0SC1B_AIENB      equ       6                   ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB
ADC0SC1B_COCOB      equ       7                   ; Conversion Complete Flag
; bit position masks
mADC0SC1B_ADCHB0    equ       %00000001
mADC0SC1B_ADCHB1    equ       %00000010
mADC0SC1B_ADCHB2    equ       %00000100
mADC0SC1B_ADCHB3    equ       %00001000
mADC0SC1B_ADCHB4    equ       %00010000
mADC0SC1B_DIFFB     equ       %00100000
mADC0SC1B_AIENB     equ       %01000000
mADC0SC1B_COCOB     equ       %10000000

;*** ADC0CFG1 - Configuration Register 1
ADC0CFG1            equ       $00000042           ;*** ADC0CFG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CFG1_ADICLK0    equ       0                   ; Input Clock Select Bit 0
ADC0CFG1_ADICLK1    equ       1                   ; Input Clock Select Bit 1
ADC0CFG1_MODE0      equ       2                   ; Conversion Mode Selection Bit 0
ADC0CFG1_MODE1      equ       3                   ; Conversion Mode Selection Bit 1
ADC0CFG1_ADLSMP     equ       4                   ; Long Sample Time Configuration
ADC0CFG1_ADIV0      equ       5                   ; Clock Divide Select Bit 0
ADC0CFG1_ADIV1      equ       6                   ; Clock Divide Select Bit 1
ADC0CFG1_ADLPC      equ       7                   ; Low Power Configuration
; bit position masks
mADC0CFG1_ADICLK0   equ       %00000001
mADC0CFG1_ADICLK1   equ       %00000010
mADC0CFG1_MODE0     equ       %00000100
mADC0CFG1_MODE1     equ       %00001000
mADC0CFG1_ADLSMP    equ       %00010000
mADC0CFG1_ADIV0     equ       %00100000
mADC0CFG1_ADIV1     equ       %01000000
mADC0CFG1_ADLPC     equ       %10000000

;*** ADC0CFG2 - Configuration Register 2
ADC0CFG2            equ       $00000043           ;*** ADC0CFG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CFG2_ADLSTS0    equ       0                   ; Long Sample Time Select Bit 0
ADC0CFG2_ADLSTS1    equ       1                   ; Long Sample Time Select Bit 1
ADC0CFG2_ADHSC      equ       2                   ; High Speed Configuration
ADC0CFG2_ADACKEN    equ       3                   ; Asynchronous Clock Output Enable
; bit position masks
mADC0CFG2_ADLSTS0   equ       %00000001
mADC0CFG2_ADLSTS1   equ       %00000010
mADC0CFG2_ADHSC     equ       %00000100
mADC0CFG2_ADACKEN   equ       %00001000

;*** ADC0RA - Data Result Register A
ADC0RA              equ       $00000044           ;*** ADC0RA - Data Result Register A

;*** ADC0RHA - Data Result High Register A
ADC0RHA             equ       $00000044           ;*** ADC0RHA - Data Result High Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0RHA_D8          equ       0                   ; ADC Result Data Bit 8
ADC0RHA_D9          equ       1                   ; ADC Result Data Bit 9
ADC0RHA_D10         equ       2                   ; ADC Result Data Bit 10
ADC0RHA_D11         equ       3                   ; ADC Result Data Bit 11
ADC0RHA_D12         equ       4                   ; ADC Result Data Bit 12
ADC0RHA_D13         equ       5                   ; ADC Result Data Bit 13
ADC0RHA_D14         equ       6                   ; ADC Result Data Bit 14
ADC0RHA_D15         equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADC0RHA_D8         equ       %00000001
mADC0RHA_D9         equ       %00000010
mADC0RHA_D10        equ       %00000100
mADC0RHA_D11        equ       %00001000
mADC0RHA_D12        equ       %00010000
mADC0RHA_D13        equ       %00100000
mADC0RHA_D14        equ       %01000000
mADC0RHA_D15        equ       %10000000

;*** ADC0RLA - Data Result Low Register A
ADC0RLA             equ       $00000045           ;*** ADC0RLA - Data Result Low Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0RLA_D0          equ       0                   ; ADC Result Data Bit 0
ADC0RLA_D1          equ       1                   ; ADC Result Data Bit 1
ADC0RLA_D2          equ       2                   ; ADC Result Data Bit 2
ADC0RLA_D3          equ       3                   ; ADC Result Data Bit 3
ADC0RLA_D4          equ       4                   ; ADC Result Data Bit 4
ADC0RLA_D5          equ       5                   ; ADC Result Data Bit 5
ADC0RLA_D6          equ       6                   ; ADC Result Data Bit 6
ADC0RLA_D7          equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADC0RLA_D0         equ       %00000001
mADC0RLA_D1         equ       %00000010
mADC0RLA_D2         equ       %00000100
mADC0RLA_D3         equ       %00001000
mADC0RLA_D4         equ       %00010000
mADC0RLA_D5         equ       %00100000
mADC0RLA_D6         equ       %01000000
mADC0RLA_D7         equ       %10000000

;*** ADC0RB - Data Result Register B
ADC0RB              equ       $00000046           ;*** ADC0RB - Data Result Register B

;*** ADC0RHB - Data Result High Register B
ADC0RHB             equ       $00000046           ;*** ADC0RHB - Data Result High Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0RHB_D8          equ       0                   ; ADC Result Data Bit 8
ADC0RHB_D9          equ       1                   ; ADC Result Data Bit 9
ADC0RHB_D10         equ       2                   ; ADC Result Data Bit 10
ADC0RHB_D11         equ       3                   ; ADC Result Data Bit 11
ADC0RHB_D12         equ       4                   ; ADC Result Data Bit 12
ADC0RHB_D13         equ       5                   ; ADC Result Data Bit 13
ADC0RHB_D14         equ       6                   ; ADC Result Data Bit 14
ADC0RHB_D15         equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADC0RHB_D8         equ       %00000001
mADC0RHB_D9         equ       %00000010
mADC0RHB_D10        equ       %00000100
mADC0RHB_D11        equ       %00001000
mADC0RHB_D12        equ       %00010000
mADC0RHB_D13        equ       %00100000
mADC0RHB_D14        equ       %01000000
mADC0RHB_D15        equ       %10000000

;*** ADC0RLB - Data Result Low Register B
ADC0RLB             equ       $00000047           ;*** ADC0RLB - Data Result Low Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0RLB_D0          equ       0                   ; ADC Result Data Bit 0
ADC0RLB_D1          equ       1                   ; ADC Result Data Bit 1
ADC0RLB_D2          equ       2                   ; ADC Result Data Bit 2
ADC0RLB_D3          equ       3                   ; ADC Result Data Bit 3
ADC0RLB_D4          equ       4                   ; ADC Result Data Bit 4
ADC0RLB_D5          equ       5                   ; ADC Result Data Bit 5
ADC0RLB_D6          equ       6                   ; ADC Result Data Bit 6
ADC0RLB_D7          equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADC0RLB_D0         equ       %00000001
mADC0RLB_D1         equ       %00000010
mADC0RLB_D2         equ       %00000100
mADC0RLB_D3         equ       %00001000
mADC0RLB_D4         equ       %00010000
mADC0RLB_D5         equ       %00100000
mADC0RLB_D6         equ       %01000000
mADC0RLB_D7         equ       %10000000

;*** SPI0C1 - SPI0 Control Register 1
SPI0C1              equ       $00000048           ;*** SPI0C1 - SPI0 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0C1_LSBFE        equ       0                   ; LSB First (Shifter Direction)
SPI0C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI0C1_CPHA         equ       2                   ; Clock Phase
SPI0C1_CPOL         equ       3                   ; Clock Polarity
SPI0C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI0C1_SPTIE        equ       5                   ; SPI Transmit Interrupt Enable
SPI0C1_SPE          equ       6                   ; SPI System Enable
SPI0C1_SPIE         equ       7                   ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPI0C1_LSBFE       equ       %00000001
mSPI0C1_SSOE        equ       %00000010
mSPI0C1_CPHA        equ       %00000100
mSPI0C1_CPOL        equ       %00001000
mSPI0C1_MSTR        equ       %00010000
mSPI0C1_SPTIE       equ       %00100000
mSPI0C1_SPE         equ       %01000000
mSPI0C1_SPIE        equ       %10000000

;*** SPI0C2 - SPI0 Control Register 2
SPI0C2              equ       $00000049           ;*** SPI0C2 - SPI0 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI0C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI0C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI0C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPI0C2_SPC0        equ       %00000001
mSPI0C2_SPISWAI     equ       %00000010
mSPI0C2_BIDIROE     equ       %00001000
mSPI0C2_MODFEN      equ       %00010000

;*** SPI0BR - SPI0 Baud Rate Register
SPI0BR              equ       $0000004A           ;*** SPI0BR - SPI0 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI0BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI0BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI0BR_SPR3         equ       3                   ; SPI Baud Rate Divisor Bit 3
SPI0BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI0BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI0BR_SPPR2        equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI0BR_SPR0        equ       %00000001
mSPI0BR_SPR1        equ       %00000010
mSPI0BR_SPR2        equ       %00000100
mSPI0BR_SPR3        equ       %00001000
mSPI0BR_SPPR0       equ       %00010000
mSPI0BR_SPPR1       equ       %00100000
mSPI0BR_SPPR2       equ       %01000000

;*** SPI0S - SPI0 Status Register
SPI0S               equ       $0000004B           ;*** SPI0S - SPI0 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI0S_MODF          equ       4                   ; Master Mode Fault Flag
SPI0S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI0S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI0S_MODF         equ       %00010000
mSPI0S_SPTEF        equ       %00100000
mSPI0S_SPRF         equ       %10000000

;*** SPI0D - SPI0 Data Register
SPI0D               equ       $0000004D           ;*** SPI0D - SPI0 Data Register

;*** SPI1C1 - SPI1 Control Register 1
SPI1C1              equ       $00000050           ;*** SPI1C1 - SPI1 Control Register 1
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
SPI1C2              equ       $00000051           ;*** SPI1C2 - SPI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI1C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI1C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI1C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPI1C2_SPC0        equ       %00000001
mSPI1C2_SPISWAI     equ       %00000010
mSPI1C2_BIDIROE     equ       %00001000
mSPI1C2_MODFEN      equ       %00010000

;*** SPI1BR - SPI1 Baud Rate Register
SPI1BR              equ       $00000052           ;*** SPI1BR - SPI1 Baud Rate Register
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
SPI1S               equ       $00000053           ;*** SPI1S - SPI1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF          equ       4                   ; Master Mode Fault Flag
SPI1S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI1S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_MODF         equ       %00010000
mSPI1S_SPTEF        equ       %00100000
mSPI1S_SPRF         equ       %10000000

;*** SPI1D - SPI1 Data Register
SPI1D               equ       $00000055           ;*** SPI1D - SPI1 Data Register

;*** SPI2C1 - SPI2 Control Register 1
SPI2C1              equ       $00000058           ;*** SPI2C1 - SPI2 Control Register 1
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
SPI2C2              equ       $00000059           ;*** SPI2C2 - SPI2 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2C2_SPC0         equ       0                   ; SPI Pin Control 0
SPI2C2_SPISWAI      equ       1                   ; SPI Stop in Wait Mode
SPI2C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI2C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPI2C2_SPC0        equ       %00000001
mSPI2C2_SPISWAI     equ       %00000010
mSPI2C2_BIDIROE     equ       %00001000
mSPI2C2_MODFEN      equ       %00010000

;*** SPI2BR - SPI2 Baud Rate Register
SPI2BR              equ       $0000005A           ;*** SPI2BR - SPI2 Baud Rate Register
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
SPI2S               equ       $0000005B           ;*** SPI2S - SPI2 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI2S_MODF          equ       4                   ; Master Mode Fault Flag
SPI2S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI2S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI2S_MODF         equ       %00010000
mSPI2S_SPTEF        equ       %00100000
mSPI2S_SPRF         equ       %10000000

;*** SPI2D - SPI2 Data Register
SPI2D               equ       $0000005D           ;*** SPI2D - SPI2 Data Register

;*** PCNT_STATUS - PCounter Status Register
PCNT_STATUS         equ       $00000060           ;*** PCNT_STATUS - PCounter Status Register

;*** PCNT_STATUS_H - PCounter Status Register High
PCNT_STATUS_H       equ       $00000060           ;*** PCNT_STATUS_H - PCounter Status Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNT_STATUS_H_CURR_INV equ       0                   ; Current state of the state machine when a state invalid event occurs, bit 0
PCNT_STATUS_H_PSTATE_INV equ       4                   ; Sensor input pin state when a state invalid event occurs, bit 0
; bit position masks
mPCNT_STATUS_H_CURR_INV equ       %00000111
mPCNT_STATUS_H_PSTATE_INV equ       %01110000

;*** PCNT_STATUS_L - PCounter Status Register Low
PCNT_STATUS_L       equ       $00000061           ;*** PCNT_STATUS_L - PCounter Status Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNT_STATUS_L_FCOVF equ       0                   ; FCounter Overflow Flag
PCNT_STATUS_L_RCOVF equ       1                   ; RCounter Overflow Flag
PCNT_STATUS_L_SINVF equ       2                   ; State Invalid Interrupt Flag
; bit position masks
mPCNT_STATUS_L_FCOVF equ       %00000001
mPCNT_STATUS_L_RCOVF equ       %00000010
mPCNT_STATUS_L_SINVF equ       %00000100

;*** PCNT_CTRL - PCounter Control Register
PCNT_CTRL           equ       $00000062           ;*** PCNT_CTRL - PCounter Control Register

;*** PCNT_CTRL_H - PCounter Control Register High
PCNT_CTRL_H         equ       $00000062           ;*** PCNT_CTRL_H - PCounter Control Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNT_CTRL_H_CHANNEL_SEL equ       0                   ; Channel select bit 0
PCNT_CTRL_H_MODE0   equ       3                   ; Mode select, bit 0
PCNT_CTRL_H_MODE1   equ       4                   ; Mode select, bit 1
PCNT_CTRL_H_FCOVFIE equ       5                   ; FCounter Overflow Interrupt Enable bit
PCNT_CTRL_H_RCOVFIE equ       6                   ; RCounter Overflow Interrupt Eenable bit
PCNT_CTRL_H_SINVIE  equ       7                   ; State Invalid Interrupt Enable bit
; bit position masks
mPCNT_CTRL_H_CHANNEL_SEL equ       %00000111
mPCNT_CTRL_H_MODE0  equ       %00001000
mPCNT_CTRL_H_MODE1  equ       %00010000
mPCNT_CTRL_H_FCOVFIE equ       %00100000
mPCNT_CTRL_H_RCOVFIE equ       %01000000
mPCNT_CTRL_H_SINVIE equ       %10000000

;*** PCNT_CTRL_L - PCounter Control Register Low
PCNT_CTRL_L         equ       $00000063           ;*** PCNT_CTRL_L - PCounter Control Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNT_CTRL_L_FILTER_VALUE equ       0                   ; Filter value bit 0
PCNT_CTRL_L_CPWMS   equ       4                   ; PWM alignment selection
PCNT_CTRL_L_POL     equ       5                   ; PWM polarity bit
PCNT_CTRL_L_DIR     equ       6                   ; Direction bit
PCNT_CTRL_L_PCNT_EN equ       7                   ; Enable/Disable bit
; bit position masks
mPCNT_CTRL_L_FILTER_VALUE equ       %00001111
mPCNT_CTRL_L_CPWMS  equ       %00010000
mPCNT_CTRL_L_POL    equ       %00100000
mPCNT_CTRL_L_DIR    equ       %01000000
mPCNT_CTRL_L_PCNT_EN equ       %10000000

;*** PCNT_FCMOD - PCounter Forward Counter Modulus Register
PCNT_FCMOD          equ       $00000064           ;*** PCNT_FCMOD - PCounter Forward Counter Modulus Register

;*** PCNT_FCMOD_H - PCounter Forward Counter Modulus Register High
PCNT_FCMOD_H        equ       $00000064           ;*** PCNT_FCMOD_H - PCounter Forward Counter Modulus Register High

;*** PCNT_FCMOD_L - PCounter Forward Counter Modulus Register Low
PCNT_FCMOD_L        equ       $00000065           ;*** PCNT_FCMOD_L - PCounter Forward Counter Modulus Register Low

;*** PCNT_FCNTR - PCounter Forward Counter Register
PCNT_FCNTR          equ       $00000066           ;*** PCNT_FCNTR - PCounter Forward Counter Register

;*** PCNT_FCNTR_H - PCounter Forward Counter Register High
PCNT_FCNTR_H        equ       $00000066           ;*** PCNT_FCNTR_H - PCounter Forward Counter Register High

;*** PCNT_FCNTR_L - PCounter Forward Counter Register Low
PCNT_FCNTR_L        equ       $00000067           ;*** PCNT_FCNTR_L - PCounter Forward Counter Register Low

;*** PCNT_RCMOD - PCounter Reverse Counter Modulus Register
PCNT_RCMOD          equ       $00000068           ;*** PCNT_RCMOD - PCounter Reverse Counter Modulus Register

;*** PCNT_RCMOD_H - PCounter Reverse Counter Modulus Register High
PCNT_RCMOD_H        equ       $00000068           ;*** PCNT_RCMOD_H - PCounter Reverse Counter Modulus Register High

;*** PCNT_RCMOD_L - PCounter Reverse Counter Modulus Register Low
PCNT_RCMOD_L        equ       $00000069           ;*** PCNT_RCMOD_L - PCounter Reverse Counter Modulus Register Low

;*** PCNT_RCNTR - PCounter Reverse Counter Register
PCNT_RCNTR          equ       $0000006A           ;*** PCNT_RCNTR - PCounter Reverse Counter Register

;*** PCNT_RCNTR_H - PCounter Reverse Counter Register High
PCNT_RCNTR_H        equ       $0000006A           ;*** PCNT_RCNTR_H - PCounter Reverse Counter Register High

;*** PCNT_RCNTR_L - PCounter Reverse Counter Register Low
PCNT_RCNTR_L        equ       $0000006B           ;*** PCNT_RCNTR_L - PCounter Reverse Counter Register Low

;*** PCNT_PWM_MOD - PCounter PWM Modulus Register
PCNT_PWM_MOD        equ       $0000006C           ;*** PCNT_PWM_MOD - PCounter PWM Modulus Register

;*** PCNT_PWM_MOD_H - PCounter PWM Modulus Register High
PCNT_PWM_MOD_H      equ       $0000006C           ;*** PCNT_PWM_MOD_H - PCounter PWM Modulus Register High

;*** PCNT_PWM_MOD_L - PCounter PWM Modulus Register Low
PCNT_PWM_MOD_L      equ       $0000006D           ;*** PCNT_PWM_MOD_L - PCounter PWM Modulus Register Low

;*** PCNT_PWM_CH0_VAL - PCounter PWM Channel 0 Value Register
PCNT_PWM_CH0_VAL    equ       $0000006E           ;*** PCNT_PWM_CH0_VAL - PCounter PWM Channel 0 Value Register

;*** PCNT_PWM_CH0_H_VAL - PCounter PWM Channel 0 Value Register High
PCNT_PWM_CH0_H_VAL  equ       $0000006E           ;*** PCNT_PWM_CH0_H_VAL - PCounter PWM Channel 0 Value Register High

;*** PCNT_PWM_CH0_L_VAL - PCounter PWM Channel 0 Value Register Low
PCNT_PWM_CH0_L_VAL  equ       $0000006F           ;*** PCNT_PWM_CH0_L_VAL - PCounter PWM Channel 0 Value Register Low

;*** PCNT_PWM_CH1_VAL - PCounter PWM Channel 1 Value Register
PCNT_PWM_CH1_VAL    equ       $00000070           ;*** PCNT_PWM_CH1_VAL - PCounter PWM Channel 1 Value Register

;*** PCNT_PWM_CH1_H_VAL - PCounter PWM Channel 1 Value Register High
PCNT_PWM_CH1_H_VAL  equ       $00000070           ;*** PCNT_PWM_CH1_H_VAL - PCounter PWM Channel 1 Value Register High

;*** PCNT_PWM_CH1_L_VAL - PCounter PWM Channel 1 Value Register Low
PCNT_PWM_CH1_L_VAL  equ       $00000071           ;*** PCNT_PWM_CH1_L_VAL - PCounter PWM Channel 1 Value Register Low

;*** PCNT_STATE - PCounter Status Register
PCNT_STATE          equ       $00000072           ;*** PCNT_STATE - PCounter Status Register

;*** PCNT_STATE_H - PCounter Status Register High
PCNT_STATE_H        equ       $00000072           ;*** PCNT_STATE_H - PCounter Status Register High

;*** PCNT_STATE_L - PCounter Status Register Low
PCNT_STATE_L        equ       $00000073           ;*** PCNT_STATE_L - PCounter Status Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PCNT_STATE_L_CURR_STATE equ       0                   ; This is for debugging purpose.These bits reflect the current state of the state machine
PCNT_STATE_L_PCOUNTER_STATE equ       3                   ; This is for debugging purpose.These bits reflect value on sensor inputs coming into PCounter
; bit position masks
mPCNT_STATE_L_CURR_STATE equ       %00000111
mPCNT_STATE_L_PCOUNTER_STATE equ       %00111000

;*** KBISC - KBI Status and Control Register
KBISC               equ       $00000074           ;*** KBISC - KBI Status and Control Register
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
KBIPE               equ       $00000075           ;*** KBIPE - KBI Pin Enable Register
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
KBIES               equ       $00000076           ;*** KBIES - KBI Edge Select Register
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

;*** IRQSC - Interrupt request status and control register
IRQSC               equ       $00000077           ;*** IRQSC - Interrupt request status and control register
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

;*** SCI0BD - SCI0 Baud Rate Register
SCI0BD              equ       $00000078           ;*** SCI0BD - SCI0 Baud Rate Register

;*** SCI0BDH - SCI0 Baud Rate Register High
SCI0BDH             equ       $00000078           ;*** SCI0BDH - SCI0 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI0BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI0BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI0BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI0BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCI0BDH_RXEDGIE     equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI0BDH_LBKDIE      equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI0BDH_SBR8       equ       %00000001
mSCI0BDH_SBR9       equ       %00000010
mSCI0BDH_SBR10      equ       %00000100
mSCI0BDH_SBR11      equ       %00001000
mSCI0BDH_SBR12      equ       %00010000
mSCI0BDH_RXEDGIE    equ       %01000000
mSCI0BDH_LBKDIE     equ       %10000000

;*** SCI0BDL - SCI0 Baud Rate Register Low
SCI0BDL             equ       $00000079           ;*** SCI0BDL - SCI0 Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0BDL_SBR0        equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCI0BDL_SBR1        equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCI0BDL_SBR2        equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCI0BDL_SBR3        equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCI0BDL_SBR4        equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCI0BDL_SBR5        equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCI0BDL_SBR6        equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCI0BDL_SBR7        equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI0BDL_SBR0       equ       %00000001
mSCI0BDL_SBR1       equ       %00000010
mSCI0BDL_SBR2       equ       %00000100
mSCI0BDL_SBR3       equ       %00001000
mSCI0BDL_SBR4       equ       %00010000
mSCI0BDL_SBR5       equ       %00100000
mSCI0BDL_SBR6       equ       %01000000
mSCI0BDL_SBR7       equ       %10000000

;*** SCI0C1 - SCI0 Control Register 1
SCI0C1              equ       $0000007A           ;*** SCI0C1 - SCI0 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0C1_PT           equ       0                   ; Parity Type
SCI0C1_PE           equ       1                   ; Parity Enable
SCI0C1_ILT          equ       2                   ; Idle Line Type Select
SCI0C1_WAKE         equ       3                   ; Receiver Wakeup Method Select
SCI0C1_M            equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI0C1_RSRC         equ       5                   ; Receiver Source Select
SCI0C1_SCISWAI      equ       6                   ; SCI Stops in Wait Mode
SCI0C1_LOOPS        equ       7                   ; Loop Mode Select
; bit position masks
mSCI0C1_PT          equ       %00000001
mSCI0C1_PE          equ       %00000010
mSCI0C1_ILT         equ       %00000100
mSCI0C1_WAKE        equ       %00001000
mSCI0C1_M           equ       %00010000
mSCI0C1_RSRC        equ       %00100000
mSCI0C1_SCISWAI     equ       %01000000
mSCI0C1_LOOPS       equ       %10000000

;*** SCI0C2 - SCI0 Control Register 2
SCI0C2              equ       $0000007B           ;*** SCI0C2 - SCI0 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0C2_SBK          equ       0                   ; Send Break
SCI0C2_RWU          equ       1                   ; Receiver Wakeup Control
SCI0C2_RE           equ       2                   ; Receiver Enable
SCI0C2_TE           equ       3                   ; Transmitter Enable
SCI0C2_ILIE         equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCI0C2_RIE          equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCI0C2_TCIE         equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCI0C2_TIE          equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI0C2_SBK         equ       %00000001
mSCI0C2_RWU         equ       %00000010
mSCI0C2_RE          equ       %00000100
mSCI0C2_TE          equ       %00001000
mSCI0C2_ILIE        equ       %00010000
mSCI0C2_RIE         equ       %00100000
mSCI0C2_TCIE        equ       %01000000
mSCI0C2_TIE         equ       %10000000

;*** SCI0S1 - SCI0 Status Register 1
SCI0S1              equ       $0000007C           ;*** SCI0S1 - SCI0 Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0S1_PF           equ       0                   ; Parity Error Flag
SCI0S1_FE           equ       1                   ; Framing Error Flag
SCI0S1_NF           equ       2                   ; Noise Flag
SCI0S1_OR           equ       3                   ; Receiver Overrun Flag
SCI0S1_IDLE         equ       4                   ; Idle Line Flag
SCI0S1_RDRF         equ       5                   ; Receive Data Register Full Flag
SCI0S1_TC           equ       6                   ; Transmission Complete Flag
SCI0S1_TDRE         equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI0S1_PF          equ       %00000001
mSCI0S1_FE          equ       %00000010
mSCI0S1_NF          equ       %00000100
mSCI0S1_OR          equ       %00001000
mSCI0S1_IDLE        equ       %00010000
mSCI0S1_RDRF        equ       %00100000
mSCI0S1_TC          equ       %01000000
mSCI0S1_TDRE        equ       %10000000

;*** SCI0S2 - SCI0 Status Register 2
SCI0S2              equ       $0000007D           ;*** SCI0S2 - SCI0 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0S2_RAF          equ       0                   ; Receiver Active Flag
SCI0S2_LBKDE        equ       1                   ; LIN Break Detection Enable
SCI0S2_BRK13        equ       2                   ; Break Character Generation Length
SCI0S2_RWUID        equ       3                   ; Receive Wake Up Idle Detect
SCI0S2_RXINV        equ       4                   ; Receive Data Inversion
SCI0S2_RXEDGIF      equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI0S2_LBKDIF       equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI0S2_RAF         equ       %00000001
mSCI0S2_LBKDE       equ       %00000010
mSCI0S2_BRK13       equ       %00000100
mSCI0S2_RWUID       equ       %00001000
mSCI0S2_RXINV       equ       %00010000
mSCI0S2_RXEDGIF     equ       %01000000
mSCI0S2_LBKDIF      equ       %10000000

;*** SCI0C3 - SCI0 Control Register 3
SCI0C3              equ       $0000007E           ;*** SCI0C3 - SCI0 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI0C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI0C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI0C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI0C3_TXINV        equ       4                   ; Transmit Data Inversion
SCI0C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI0C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI0C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI0C3_PEIE        equ       %00000001
mSCI0C3_FEIE        equ       %00000010
mSCI0C3_NEIE        equ       %00000100
mSCI0C3_ORIE        equ       %00001000
mSCI0C3_TXINV       equ       %00010000
mSCI0C3_TXDIR       equ       %00100000
mSCI0C3_T8          equ       %01000000
mSCI0C3_R8          equ       %10000000

;*** SCI0D - SCI0 Data Register
SCI0D               equ       $0000007F           ;*** SCI0D - SCI0 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI0D_R0_T0         equ       0                   ; Receive/Transmit Data Bit 0
SCI0D_R1_T1         equ       1                   ; Receive/Transmit Data Bit 1
SCI0D_R2_T2         equ       2                   ; Receive/Transmit Data Bit 2
SCI0D_R3_T3         equ       3                   ; Receive/Transmit Data Bit 3
SCI0D_R4_T4         equ       4                   ; Receive/Transmit Data Bit 4
SCI0D_R5_T5         equ       5                   ; Receive/Transmit Data Bit 5
SCI0D_R6_T6         equ       6                   ; Receive/Transmit Data Bit 6
SCI0D_R7_T7         equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCI0D_R0_T0        equ       %00000001
mSCI0D_R1_T1        equ       %00000010
mSCI0D_R2_T2        equ       %00000100
mSCI0D_R3_T3        equ       %00001000
mSCI0D_R4_T4        equ       %00010000
mSCI0D_R5_T5        equ       %00100000
mSCI0D_R6_T6        equ       %01000000
mSCI0D_R7_T7        equ       %10000000

;*** ADC1SC1A - Status and Control Register 1A
ADC1SC1A            equ       $00000080           ;*** ADC1SC1A - Status and Control Register 1A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC1A_ADCHA0     equ       0                   ; Input Channel Select Bit 0
ADC1SC1A_ADCHA1     equ       1                   ; Input Channel Select Bit 1
ADC1SC1A_ADCHA2     equ       2                   ; Input Channel Select Bit 2
ADC1SC1A_ADCHA3     equ       3                   ; Input Channel Select Bit 3
ADC1SC1A_ADCHA4     equ       4                   ; Input Channel Select Bit 4
ADC1SC1A_DIFFA      equ       5                   ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC1SC1A_AIENA      equ       6                   ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA
ADC1SC1A_COCOA      equ       7                   ; Conversion Complete Flag
; bit position masks
mADC1SC1A_ADCHA0    equ       %00000001
mADC1SC1A_ADCHA1    equ       %00000010
mADC1SC1A_ADCHA2    equ       %00000100
mADC1SC1A_ADCHA3    equ       %00001000
mADC1SC1A_ADCHA4    equ       %00010000
mADC1SC1A_DIFFA     equ       %00100000
mADC1SC1A_AIENA     equ       %01000000
mADC1SC1A_COCOA     equ       %10000000

;*** ADC1SC1B - Status and Control Register 1B
ADC1SC1B            equ       $00000081           ;*** ADC1SC1B - Status and Control Register 1B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC1B_ADCHB0     equ       0                   ; Input Channel Select Bit 0
ADC1SC1B_ADCHB1     equ       1                   ; Input Channel Select Bit 1
ADC1SC1B_ADCHB2     equ       2                   ; Input Channel Select Bit 2
ADC1SC1B_ADCHB3     equ       3                   ; Input Channel Select Bit 3
ADC1SC1B_ADCHB4     equ       4                   ; Input Channel Select Bit 4
ADC1SC1B_DIFFB      equ       5                   ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC1SC1B_AIENB      equ       6                   ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB
ADC1SC1B_COCOB      equ       7                   ; Conversion Complete Flag
; bit position masks
mADC1SC1B_ADCHB0    equ       %00000001
mADC1SC1B_ADCHB1    equ       %00000010
mADC1SC1B_ADCHB2    equ       %00000100
mADC1SC1B_ADCHB3    equ       %00001000
mADC1SC1B_ADCHB4    equ       %00010000
mADC1SC1B_DIFFB     equ       %00100000
mADC1SC1B_AIENB     equ       %01000000
mADC1SC1B_COCOB     equ       %10000000

;*** ADC1CFG1 - Configuration Register 1
ADC1CFG1            equ       $00000082           ;*** ADC1CFG1 - Configuration Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CFG1_ADICLK0    equ       0                   ; Input Clock Select Bit 0
ADC1CFG1_ADICLK1    equ       1                   ; Input Clock Select Bit 1
ADC1CFG1_MODE0      equ       2                   ; Conversion Mode Selection Bit 0
ADC1CFG1_MODE1      equ       3                   ; Conversion Mode Selection Bit 1
ADC1CFG1_ADLSMP     equ       4                   ; Long Sample Time Configuration
ADC1CFG1_ADIV0      equ       5                   ; Clock Divide Select Bit 0
ADC1CFG1_ADIV1      equ       6                   ; Clock Divide Select Bit 1
ADC1CFG1_ADLPC      equ       7                   ; Low Power Configuration
; bit position masks
mADC1CFG1_ADICLK0   equ       %00000001
mADC1CFG1_ADICLK1   equ       %00000010
mADC1CFG1_MODE0     equ       %00000100
mADC1CFG1_MODE1     equ       %00001000
mADC1CFG1_ADLSMP    equ       %00010000
mADC1CFG1_ADIV0     equ       %00100000
mADC1CFG1_ADIV1     equ       %01000000
mADC1CFG1_ADLPC     equ       %10000000

;*** ADC1CFG2 - Configuration Register 2
ADC1CFG2            equ       $00000083           ;*** ADC1CFG2 - Configuration Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CFG2_ADLSTS0    equ       0                   ; Long Sample Time Select Bit 0
ADC1CFG2_ADLSTS1    equ       1                   ; Long Sample Time Select Bit 1
ADC1CFG2_ADHSC      equ       2                   ; High Speed Configuration
ADC1CFG2_ADACKEN    equ       3                   ; Asynchronous Clock Output Enable
; bit position masks
mADC1CFG2_ADLSTS0   equ       %00000001
mADC1CFG2_ADLSTS1   equ       %00000010
mADC1CFG2_ADHSC     equ       %00000100
mADC1CFG2_ADACKEN   equ       %00001000

;*** ADC1RA - Data Result Register A
ADC1RA              equ       $00000084           ;*** ADC1RA - Data Result Register A

;*** ADC1RHA - Data Result High Register A
ADC1RHA             equ       $00000084           ;*** ADC1RHA - Data Result High Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RHA_D8          equ       0                   ; ADC Result Data Bit 8
ADC1RHA_D9          equ       1                   ; ADC Result Data Bit 9
ADC1RHA_D10         equ       2                   ; ADC Result Data Bit 10
ADC1RHA_D11         equ       3                   ; ADC Result Data Bit 11
ADC1RHA_D12         equ       4                   ; ADC Result Data Bit 12
ADC1RHA_D13         equ       5                   ; ADC Result Data Bit 13
ADC1RHA_D14         equ       6                   ; ADC Result Data Bit 14
ADC1RHA_D15         equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADC1RHA_D8         equ       %00000001
mADC1RHA_D9         equ       %00000010
mADC1RHA_D10        equ       %00000100
mADC1RHA_D11        equ       %00001000
mADC1RHA_D12        equ       %00010000
mADC1RHA_D13        equ       %00100000
mADC1RHA_D14        equ       %01000000
mADC1RHA_D15        equ       %10000000

;*** ADC1RLA - Data Result Low Register A
ADC1RLA             equ       $00000085           ;*** ADC1RLA - Data Result Low Register A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RLA_D0          equ       0                   ; ADC Result Data Bit 0
ADC1RLA_D1          equ       1                   ; ADC Result Data Bit 1
ADC1RLA_D2          equ       2                   ; ADC Result Data Bit 2
ADC1RLA_D3          equ       3                   ; ADC Result Data Bit 3
ADC1RLA_D4          equ       4                   ; ADC Result Data Bit 4
ADC1RLA_D5          equ       5                   ; ADC Result Data Bit 5
ADC1RLA_D6          equ       6                   ; ADC Result Data Bit 6
ADC1RLA_D7          equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADC1RLA_D0         equ       %00000001
mADC1RLA_D1         equ       %00000010
mADC1RLA_D2         equ       %00000100
mADC1RLA_D3         equ       %00001000
mADC1RLA_D4         equ       %00010000
mADC1RLA_D5         equ       %00100000
mADC1RLA_D6         equ       %01000000
mADC1RLA_D7         equ       %10000000

;*** ADC1RB - Data Result Register B
ADC1RB              equ       $00000086           ;*** ADC1RB - Data Result Register B

;*** ADC1RHB - Data Result High Register B
ADC1RHB             equ       $00000086           ;*** ADC1RHB - Data Result High Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RHB_D8          equ       0                   ; ADC Result Data Bit 8
ADC1RHB_D9          equ       1                   ; ADC Result Data Bit 9
ADC1RHB_D10         equ       2                   ; ADC Result Data Bit 10
ADC1RHB_D11         equ       3                   ; ADC Result Data Bit 11
ADC1RHB_D12         equ       4                   ; ADC Result Data Bit 12
ADC1RHB_D13         equ       5                   ; ADC Result Data Bit 13
ADC1RHB_D14         equ       6                   ; ADC Result Data Bit 14
ADC1RHB_D15         equ       7                   ; ADC Result Data Bit 15
; bit position masks
mADC1RHB_D8         equ       %00000001
mADC1RHB_D9         equ       %00000010
mADC1RHB_D10        equ       %00000100
mADC1RHB_D11        equ       %00001000
mADC1RHB_D12        equ       %00010000
mADC1RHB_D13        equ       %00100000
mADC1RHB_D14        equ       %01000000
mADC1RHB_D15        equ       %10000000

;*** ADC1RLB - Data Result Low Register B
ADC1RLB             equ       $00000087           ;*** ADC1RLB - Data Result Low Register B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1RLB_D0          equ       0                   ; ADC Result Data Bit 0
ADC1RLB_D1          equ       1                   ; ADC Result Data Bit 1
ADC1RLB_D2          equ       2                   ; ADC Result Data Bit 2
ADC1RLB_D3          equ       3                   ; ADC Result Data Bit 3
ADC1RLB_D4          equ       4                   ; ADC Result Data Bit 4
ADC1RLB_D5          equ       5                   ; ADC Result Data Bit 5
ADC1RLB_D6          equ       6                   ; ADC Result Data Bit 6
ADC1RLB_D7          equ       7                   ; ADC Result Data Bit 7
; bit position masks
mADC1RLB_D0         equ       %00000001
mADC1RLB_D1         equ       %00000010
mADC1RLB_D2         equ       %00000100
mADC1RLB_D3         equ       %00001000
mADC1RLB_D4         equ       %00010000
mADC1RLB_D5         equ       %00100000
mADC1RLB_D6         equ       %01000000
mADC1RLB_D7         equ       %10000000

;*** SCI1BD - SCI1 Baud Rate Register
SCI1BD              equ       $00000088           ;*** SCI1BD - SCI1 Baud Rate Register

;*** SCI1BDH - SCI1 Baud Rate Register High
SCI1BDH             equ       $00000088           ;*** SCI1BDH - SCI1 Baud Rate Register High
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
SCI1BDL             equ       $00000089           ;*** SCI1BDL - SCI1 Baud Rate Register Low
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
SCI1C1              equ       $0000008A           ;*** SCI1C1 - SCI1 Control Register 1
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
SCI1C2              equ       $0000008B           ;*** SCI1C2 - SCI1 Control Register 2
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
SCI1S1              equ       $0000008C           ;*** SCI1S1 - SCI1 Status Register 1
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
SCI1S2              equ       $0000008D           ;*** SCI1S2 - SCI1 Status Register 2
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
SCI1C3              equ       $0000008E           ;*** SCI1C3 - SCI1 Control Register 3
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
SCI1D               equ       $0000008F           ;*** SCI1D - SCI1 Data Register
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

;*** IICA1 - IIC Address Register
IICA1               equ       $00000090           ;*** IICA1 - IIC Address Register
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
IICA                equ       $00000090           ;*** IICA - IIC Address Register
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
IICF                equ       $00000091           ;*** IICF - IIC Frequency Divider Register
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
IICC1               equ       $00000092           ;*** IICC1 - IIC Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC1_WUEN          equ       1                   ; Wake-up Enable
IICC1_RSTA          equ       2                   ; Repeat START
IICC1_TXAK          equ       3                   ; Transmit Acknowledge Enable
IICC1_TX            equ       4                   ; Transmit Mode Select
IICC1_MST           equ       5                   ; Master Mode Select
IICC1_IICIE         equ       6                   ; IIC Interrupt Enable
IICC1_IICEN         equ       7                   ; IIC Enable
; bit position masks
mIICC1_WUEN         equ       %00000010
mIICC1_RSTA         equ       %00000100
mIICC1_TXAK         equ       %00001000
mIICC1_TX           equ       %00010000
mIICC1_MST          equ       %00100000
mIICC1_IICIE        equ       %01000000
mIICC1_IICEN        equ       %10000000

;*** IICC - IIC Control Register
IICC                equ       $00000092           ;*** IICC - IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC_WUEN           equ       1                   ; Wake-up Enable
IICC_RSTA           equ       2                   ; Repeat START
IICC_TXAK           equ       3                   ; Transmit Acknowledge Enable
IICC_TX             equ       4                   ; Transmit Mode Select
IICC_MST            equ       5                   ; Master Mode Select
IICC_IICIE          equ       6                   ; IIC Interrupt Enable
IICC_IICEN          equ       7                   ; IIC Enable
; bit position masks
mIICC_WUEN          equ       %00000010
mIICC_RSTA          equ       %00000100
mIICC_TXAK          equ       %00001000
mIICC_TX            equ       %00010000
mIICC_MST           equ       %00100000
mIICC_IICIE         equ       %01000000
mIICC_IICEN         equ       %10000000

;*** IICS - IIC Status Register
IICS                equ       $00000093           ;*** IICS - IIC Status Register
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
IICD                equ       $00000094           ;*** IICD - IIC Data I/O Register
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
IICC2               equ       $00000095           ;*** IICC2 - IIC Control Register 2
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

;*** IICFLT - IIC Filter register
IICFLT              equ       $00000096           ;*** IICFLT - IIC Filter register
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

;*** IICSMB - SMBus Control and Status Register
IICSMB              equ       $00000097           ;*** IICSMB - SMBus Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICSMB_SHTF2IE      equ       0                   ; SHTF2 Interrupt Enable
IICSMB_SHTF2        equ       1                   ; SCL High Timeout Flag 2
IICSMB_SHTF1        equ       2                   ; SCL High Timeout Flag 1
IICSMB_SLTF         equ       3                   ; SCL Low Timeout Flag
IICSMB_TCKSEL       equ       4                   ; Time Out Counter Clock Select
IICSMB_SIICAEN      equ       5                   ; Second IIC Address Enable
IICSMB_ALERTEN      equ       6                   ; SMBus Alert Response Address Enable
IICSMB_FACK         equ       7                   ; Fast NACK/ACK enable
; bit position masks
mIICSMB_SHTF2IE     equ       %00000001
mIICSMB_SHTF2       equ       %00000010
mIICSMB_SHTF1       equ       %00000100
mIICSMB_SLTF        equ       %00001000
mIICSMB_TCKSEL      equ       %00010000
mIICSMB_SIICAEN     equ       %00100000
mIICSMB_ALERTEN     equ       %01000000
mIICSMB_FACK        equ       %10000000

;*** IICA2 - IIC Address Register 2
IICA2               equ       $00000098           ;*** IICA2 - IIC Address Register 2
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
IICSLT              equ       $00000099           ;*** IICSLT - IIC SCL Low Time Out register

;*** IICSLTH - IIC SCL Low Time Out register - High byte
IICSLTH             equ       $00000099           ;*** IICSLTH - IIC SCL Low Time Out register - High byte
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
IICSLTL             equ       $0000009A           ;*** IICSLTL - IIC SCL Low Time Out register - Low byte
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

;*** FTMSC - FTM Status and Control Register
FTMSC               equ       $000000A0           ;*** FTMSC - FTM Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMSC_PS0           equ       0                   ; Prescale Divisor Select Bit 0
FTMSC_PS1           equ       1                   ; Prescale Divisor Select Bit 1
FTMSC_PS2           equ       2                   ; Prescale Divisor Select Bit 2
FTMSC_CLKSA         equ       3                   ; Clock Source Select A
FTMSC_CLKSB         equ       4                   ; Clock Source Select B
FTMSC_CPWMS         equ       5                   ; Center-Aligned PWM Select
FTMSC_TOIE          equ       6                   ; Timer Overflow Interrupt Enable
FTMSC_TOF           equ       7                   ; Timer Overflow Flag
; bit position masks
mFTMSC_PS0          equ       %00000001
mFTMSC_PS1          equ       %00000010
mFTMSC_PS2          equ       %00000100
mFTMSC_CLKSA        equ       %00001000
mFTMSC_CLKSB        equ       %00010000
mFTMSC_CPWMS        equ       %00100000
mFTMSC_TOIE         equ       %01000000
mFTMSC_TOF          equ       %10000000

;*** FTMCNT - FTM Timer Counter Register
FTMCNT              equ       $000000A1           ;*** FTMCNT - FTM Timer Counter Register

;*** FTMCNTH - FTM Timer Counter Register High
FTMCNTH             equ       $000000A1           ;*** FTMCNTH - FTM Timer Counter Register High

;*** FTMCNTL - FTM Timer Counter Register Low
FTMCNTL             equ       $000000A2           ;*** FTMCNTL - FTM Timer Counter Register Low

;*** FTMMOD - FTM Timer Counter Modulo Register
FTMMOD              equ       $000000A3           ;*** FTMMOD - FTM Timer Counter Modulo Register

;*** FTMMODH - FTM Timer Counter Modulo Register High
FTMMODH             equ       $000000A3           ;*** FTMMODH - FTM Timer Counter Modulo Register High

;*** FTMMODL - FTM Timer Counter Modulo Register Low
FTMMODL             equ       $000000A4           ;*** FTMMODL - FTM Timer Counter Modulo Register Low

;*** FTMC0SC - FTM Timer Channel 0 Status and Control Register
FTMC0SC             equ       $000000A5           ;*** FTMC0SC - FTM Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMC0SC_ELS0A       equ       2                   ; Edge/Level Select Bit A
FTMC0SC_ELS0B       equ       3                   ; Edge/Level Select Bit B
FTMC0SC_MS0A        equ       4                   ; Mode Select A for FTM Channel 0
FTMC0SC_MS0B        equ       5                   ; Mode Select B for FTM Channel 0
FTMC0SC_CH0IE       equ       6                   ; Channel 0 Interrupt Enable
FTMC0SC_CH0F        equ       7                   ; Channel 0 Flag
; bit position masks
mFTMC0SC_ELS0A      equ       %00000100
mFTMC0SC_ELS0B      equ       %00001000
mFTMC0SC_MS0A       equ       %00010000
mFTMC0SC_MS0B       equ       %00100000
mFTMC0SC_CH0IE      equ       %01000000
mFTMC0SC_CH0F       equ       %10000000

;*** FTMC0V - FTM Timer Channel 0 Value Register
FTMC0V              equ       $000000A6           ;*** FTMC0V - FTM Timer Channel 0 Value Register

;*** FTMC0VH - FTM Timer Channel 0 Value Register High
FTMC0VH             equ       $000000A6           ;*** FTMC0VH - FTM Timer Channel 0 Value Register High

;*** FTMC0VL - FTM Timer Channel 0 Value Register Low
FTMC0VL             equ       $000000A7           ;*** FTMC0VL - FTM Timer Channel 0 Value Register Low

;*** FTMC1SC - FTM Timer Channel 1 Status and Control Register
FTMC1SC             equ       $000000A8           ;*** FTMC1SC - FTM Timer Channel 1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FTMC1SC_ELS1A       equ       2                   ; Edge/Level Select Bit A
FTMC1SC_ELS1B       equ       3                   ; Edge/Level Select Bit B
FTMC1SC_MS1A        equ       4                   ; Mode Select A for FTM Channel 1
FTMC1SC_MS1B        equ       5                   ; Mode Select B for FTM Channel 1
FTMC1SC_CH1IE       equ       6                   ; Channel 1 Interrupt Enable
FTMC1SC_CH1F        equ       7                   ; Channel 1 Flag
; bit position masks
mFTMC1SC_ELS1A      equ       %00000100
mFTMC1SC_ELS1B      equ       %00001000
mFTMC1SC_MS1A       equ       %00010000
mFTMC1SC_MS1B       equ       %00100000
mFTMC1SC_CH1IE      equ       %01000000
mFTMC1SC_CH1F       equ       %10000000

;*** FTMC1V - FTM Timer Channel 1 Value Register
FTMC1V              equ       $000000A9           ;*** FTMC1V - FTM Timer Channel 1 Value Register

;*** FTMC1VH - FTM Timer Channel 1 Value Register High
FTMC1VH             equ       $000000A9           ;*** FTMC1VH - FTM Timer Channel 1 Value Register High

;*** FTMC1VL - FTM Timer Channel 1 Value Register Low
FTMC1VL             equ       $000000AA           ;*** FTMC1VL - FTM Timer Channel 1 Value Register Low

;*** CRCDH - CRC Data High Register (Word)
CRCDH               equ       $000000B0           ;*** CRCDH - CRC Data High Register (Word)

;*** CRCDH1 - CRC Data High 1 (Upper Byte)
CRCDH1              equ       $000000B0           ;*** CRCDH1 - CRC Data High 1 (Upper Byte)

;*** CRCDH0 - CRC Data High 0 (Lower Byte)
CRCDH0              equ       $000000B1           ;*** CRCDH0 - CRC Data High 0 (Lower Byte)

;*** CRCDL - CRC Data Low Register (Word)
CRCDL               equ       $000000B2           ;*** CRCDL - CRC Data Low Register (Word)

;*** CRCDL1 - CRC Data Low 1 (Upper Byte)
CRCDL1              equ       $000000B2           ;*** CRCDL1 - CRC Data Low 1 (Upper Byte)

;*** CRCDL0 - CRC Data Low 0 (Lower Byte)
CRCDL0              equ       $000000B3           ;*** CRCDL0 - CRC Data Low 0 (Lower Byte)

;*** CRCPH - CRC Polynomial High (Word)
CRCPH               equ       $000000B4           ;*** CRCPH - CRC Polynomial High (Word)

;*** CRCPH1 - CRC Polynomial High Word Upper Byte
CRCPH1              equ       $000000B4           ;*** CRCPH1 - CRC Polynomial High Word Upper Byte

;*** CRCPH0 - CRC Polynomial High Word Lower Byte
CRCPH0              equ       $000000B5           ;*** CRCPH0 - CRC Polynomial High Word Lower Byte

;*** CRCPL - CRC Polynomial Low (Word)
CRCPL               equ       $000000B6           ;*** CRCPL - CRC Polynomial Low (Word)

;*** CRCPL1 - CRC Polynomial Low 1 (Upper Byte)
CRCPL1              equ       $000000B6           ;*** CRCPL1 - CRC Polynomial Low 1 (Upper Byte)

;*** CRCPL0 - CRC Polynomial Low 0 (Lower Byte)
CRCPL0              equ       $000000B7           ;*** CRCPL0 - CRC Polynomial Low 0 (Lower Byte)

;*** CRCCTL - CRC Control Register
CRCCTL              equ       $000000B8           ;*** CRCCTL - CRC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CRCCTL_CRCW         equ       0                   ; Width of CRC protocol
CRCCTL_SEED         equ       1                   ; Write to the CRC Data Registers is a SEED
CRCCTL_FXOR         equ       2                   ; Complement Read of CRCDH/L registers
CRCCTL_TOTR0        equ       4                   ; Type of Transpose for Read bit 0, bit 0
CRCCTL_TOTR1        equ       5                   ; Type of Transpose for Read bit 0, bit 1
CRCCTL_TOTW0        equ       6                   ; Type of Transpose for Writes, bit 0, bit 0
CRCCTL_TOTW1        equ       7                   ; Type of Transpose for Writes, bit 0, bit 1
; bit position masks
mCRCCTL_CRCW        equ       %00000001
mCRCCTL_SEED        equ       %00000010
mCRCCTL_FXOR        equ       %00000100
mCRCCTL_TOTR0       equ       %00010000
mCRCCTL_TOTR1       equ       %00100000
mCRCCTL_TOTW0       equ       %01000000
mCRCCTL_TOTW1       equ       %10000000

;*** LCDPEN0 - LCD Pin Enable Register 0
LCDPEN0             equ       $00001080           ;*** LCDPEN0 - LCD Pin Enable Register 0
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
LCDPEN1             equ       $00001081           ;*** LCDPEN1 - LCD Pin Enable Register 1
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
LCDPEN2             equ       $00001082           ;*** LCDPEN2 - LCD Pin Enable Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN2_PEN16       equ       0                   ; Enable LCD pin 16 for LCD operation
LCDPEN2_PEN17       equ       1                   ; Enable LCD pin 17 for LCD operation
LCDPEN2_PEN18       equ       2                   ; Enable LCD pin 18 for LCD operation
LCDPEN2_PEN19       equ       3                   ; Enable LCD pin 19 for LCD operation
LCDPEN2_PEN20       equ       4                   ; Enable LCD pin 20 for LCD operation
LCDPEN2_PEN21       equ       5                   ; Enable LCD pin 21 for LCD operation
LCDPEN2_PEN22       equ       6                   ; Enable LCD pin 22 for LCD operation
LCDPEN2_PEN23       equ       7                   ; Enable LCD pin 23 for LCD operation
; bit position masks
mLCDPEN2_PEN16      equ       %00000001
mLCDPEN2_PEN17      equ       %00000010
mLCDPEN2_PEN18      equ       %00000100
mLCDPEN2_PEN19      equ       %00001000
mLCDPEN2_PEN20      equ       %00010000
mLCDPEN2_PEN21      equ       %00100000
mLCDPEN2_PEN22      equ       %01000000
mLCDPEN2_PEN23      equ       %10000000

;*** LCDPEN3 - LCD Pin Enable Register 3
LCDPEN3             equ       $00001083           ;*** LCDPEN3 - LCD Pin Enable Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN3_PEN24       equ       0                   ; Enable LCD pin 24 for LCD operation
LCDPEN3_PEN25       equ       1                   ; Enable LCD pin 25 for LCD operation
LCDPEN3_PEN26       equ       2                   ; Enable LCD pin 26 for LCD operation
LCDPEN3_PEN27       equ       3                   ; Enable LCD pin 27 for LCD operation
LCDPEN3_PEN28       equ       4                   ; Enable LCD pin 28 for LCD operation
LCDPEN3_PEN29       equ       5                   ; Enable LCD pin 29 for LCD operation
LCDPEN3_PEN30       equ       6                   ; Enable LCD pin 30 for LCD operation
LCDPEN3_PEN31       equ       7                   ; Enable LCD pin 31 for LCD operation
; bit position masks
mLCDPEN3_PEN24      equ       %00000001
mLCDPEN3_PEN25      equ       %00000010
mLCDPEN3_PEN26      equ       %00000100
mLCDPEN3_PEN27      equ       %00001000
mLCDPEN3_PEN28      equ       %00010000
mLCDPEN3_PEN29      equ       %00100000
mLCDPEN3_PEN30      equ       %01000000
mLCDPEN3_PEN31      equ       %10000000

;*** LCDPEN4 - LCD Pin Enable Register 4
LCDPEN4             equ       $00001084           ;*** LCDPEN4 - LCD Pin Enable Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN4_PEN32       equ       0                   ; Enable LCD pin 32 for LCD operation
LCDPEN4_PEN33       equ       1                   ; Enable LCD pin 33 for LCD operation
LCDPEN4_PEN34       equ       2                   ; Enable LCD pin 34 for LCD operation
LCDPEN4_PEN35       equ       3                   ; Enable LCD pin 35 for LCD operation
LCDPEN4_PEN36       equ       4                   ; Enable LCD pin 36 for LCD operation
LCDPEN4_PEN37       equ       5                   ; Enable LCD pin 37 for LCD operation
LCDPEN4_PEN38       equ       6                   ; Enable LCD pin 38 for LCD operation
LCDPEN4_PEN39       equ       7                   ; Enable LCD pin 39 for LCD operation
; bit position masks
mLCDPEN4_PEN32      equ       %00000001
mLCDPEN4_PEN33      equ       %00000010
mLCDPEN4_PEN34      equ       %00000100
mLCDPEN4_PEN35      equ       %00001000
mLCDPEN4_PEN36      equ       %00010000
mLCDPEN4_PEN37      equ       %00100000
mLCDPEN4_PEN38      equ       %01000000
mLCDPEN4_PEN39      equ       %10000000

;*** LCDPEN5 - LCD Pin Enable Register 5
LCDPEN5             equ       $00001085           ;*** LCDPEN5 - LCD Pin Enable Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN5_PEN40       equ       0                   ; Enable LCD pin 40 for LCD operation
LCDPEN5_PEN41       equ       1                   ; Enable LCD pin 41 for LCD operation
LCDPEN5_PEN42       equ       2                   ; Enable LCD pin 42 for LCD operation
LCDPEN5_PEN43       equ       3                   ; Enable LCD pin 43 for LCD operation
; bit position masks
mLCDPEN5_PEN40      equ       %00000001
mLCDPEN5_PEN41      equ       %00000010
mLCDPEN5_PEN42      equ       %00000100
mLCDPEN5_PEN43      equ       %00001000

;*** LCDBPEN0 - LCD Backplane Enable Register 0
LCDBPEN0            equ       $00001088           ;*** LCDBPEN0 - LCD Backplane Enable Register 0
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
LCDBPEN1            equ       $00001089           ;*** LCDBPEN1 - LCD Backplane Enable Register 1
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
LCDBPEN2            equ       $0000108A           ;*** LCDBPEN2 - LCD Backplane Enable Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN2_BPEN16     equ       0                   ; Enable LCD pin 16 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN17     equ       1                   ; Enable LCD pin 17 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN18     equ       2                   ; Enable LCD pin 18 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN19     equ       3                   ; Enable LCD pin 19 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN20     equ       4                   ; Enable LCD pin 20 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN21     equ       5                   ; Enable LCD pin 21 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN22     equ       6                   ; Enable LCD pin 22 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN23     equ       7                   ; Enable LCD pin 23 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN2_BPEN16    equ       %00000001
mLCDBPEN2_BPEN17    equ       %00000010
mLCDBPEN2_BPEN18    equ       %00000100
mLCDBPEN2_BPEN19    equ       %00001000
mLCDBPEN2_BPEN20    equ       %00010000
mLCDBPEN2_BPEN21    equ       %00100000
mLCDBPEN2_BPEN22    equ       %01000000
mLCDBPEN2_BPEN23    equ       %10000000

;*** LCDBPEN3 - LCD Backplane Enable Register 3
LCDBPEN3            equ       $0000108B           ;*** LCDBPEN3 - LCD Backplane Enable Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN3_BPEN24     equ       0                   ; Enable LCD pin 24 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN25     equ       1                   ; Enable LCD pin 25 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN26     equ       2                   ; Enable LCD pin 26 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN27     equ       3                   ; Enable LCD pin 27 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN28     equ       4                   ; Enable LCD pin 28 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN29     equ       5                   ; Enable LCD pin 29 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN30     equ       6                   ; Enable LCD pin 30 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN31     equ       7                   ; Enable LCD pin 31 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN3_BPEN24    equ       %00000001
mLCDBPEN3_BPEN25    equ       %00000010
mLCDBPEN3_BPEN26    equ       %00000100
mLCDBPEN3_BPEN27    equ       %00001000
mLCDBPEN3_BPEN28    equ       %00010000
mLCDBPEN3_BPEN29    equ       %00100000
mLCDBPEN3_BPEN30    equ       %01000000
mLCDBPEN3_BPEN31    equ       %10000000

;*** LCDBPEN4 - LCD Backplane Enable Register 4
LCDBPEN4            equ       $0000108C           ;*** LCDBPEN4 - LCD Backplane Enable Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN4_BPEN32     equ       0                   ; Enable LCD pin 32 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN33     equ       1                   ; Enable LCD pin 33 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN34     equ       2                   ; Enable LCD pin 34 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN35     equ       3                   ; Enable LCD pin 35 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN36     equ       4                   ; Enable LCD pin 36 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN37     equ       5                   ; Enable LCD pin 37 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN38     equ       6                   ; Enable LCD pin 38 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN39     equ       7                   ; Enable LCD pin 39 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN4_BPEN32    equ       %00000001
mLCDBPEN4_BPEN33    equ       %00000010
mLCDBPEN4_BPEN34    equ       %00000100
mLCDBPEN4_BPEN35    equ       %00001000
mLCDBPEN4_BPEN36    equ       %00010000
mLCDBPEN4_BPEN37    equ       %00100000
mLCDBPEN4_BPEN38    equ       %01000000
mLCDBPEN4_BPEN39    equ       %10000000

;*** LCDBPEN5 - LCD Backplane Enable Register 5
LCDBPEN5            equ       $0000108D           ;*** LCDBPEN5 - LCD Backplane Enable Register 5
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN5_BPEN40     equ       0                   ; Enable LCD pin 40 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN41     equ       1                   ; Enable LCD pin 41 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN42     equ       2                   ; Enable LCD pin 42 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN43     equ       3                   ; Enable LCD pin 43 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN5_BPEN40    equ       %00000001
mLCDBPEN5_BPEN41    equ       %00000010
mLCDBPEN5_BPEN42    equ       %00000100
mLCDBPEN5_BPEN43    equ       %00001000

;*** LCDWF0 - LCD Waveform Register 0
LCDWF0              equ       $00001090           ;*** LCDWF0 - LCD Waveform Register 0
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
LCDWF1              equ       $00001091           ;*** LCDWF1 - LCD Waveform Register 1
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
LCDWF2              equ       $00001092           ;*** LCDWF2 - LCD Waveform Register 2
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
LCDWF3              equ       $00001093           ;*** LCDWF3 - LCD Waveform Register 3
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
LCDWF4              equ       $00001094           ;*** LCDWF4 - LCD Waveform Register 4
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
LCDWF5              equ       $00001095           ;*** LCDWF5 - LCD Waveform Register 5
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
LCDWF6              equ       $00001096           ;*** LCDWF6 - LCD Waveform Register 6
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
LCDWF7              equ       $00001097           ;*** LCDWF7 - LCD Waveform Register 7
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
LCDWF8              equ       $00001098           ;*** LCDWF8 - LCD Waveform Register 8
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
LCDWF9              equ       $00001099           ;*** LCDWF9 - LCD Waveform Register 9
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
LCDWF10             equ       $0000109A           ;*** LCDWF10 - LCD Waveform Register 10
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
LCDWF11             equ       $0000109B           ;*** LCDWF11 - LCD Waveform Register 11
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
LCDWF12             equ       $0000109C           ;*** LCDWF12 - LCD Waveform Register 12
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
LCDWF13             equ       $0000109D           ;*** LCDWF13 - LCD Waveform Register 13
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
LCDWF14             equ       $0000109E           ;*** LCDWF14 - LCD Waveform Register 14
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
LCDWF15             equ       $0000109F           ;*** LCDWF15 - LCD Waveform Register 15
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
LCDWF16             equ       $000010A0           ;*** LCDWF16 - LCD Waveform Register 16
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
LCDWF17             equ       $000010A1           ;*** LCDWF17 - LCD Waveform Register 17
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
LCDWF18             equ       $000010A2           ;*** LCDWF18 - LCD Waveform Register 18
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
LCDWF19             equ       $000010A3           ;*** LCDWF19 - LCD Waveform Register 19
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
LCDWF20             equ       $000010A4           ;*** LCDWF20 - LCD Waveform Register 20
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
LCDWF21             equ       $000010A5           ;*** LCDWF21 - LCD Waveform Register 21
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

;*** LCDWF22 - LCD Waveform Register 22
LCDWF22             equ       $000010A6           ;*** LCDWF22 - LCD Waveform Register 22
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF22_BPALCD22    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPBLCD22    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPCLCD22    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPDLCD22    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPELCD22    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPFLCD22    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPGLCD22    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPHLCD22    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF22_BPALCD22   equ       %00000001
mLCDWF22_BPBLCD22   equ       %00000010
mLCDWF22_BPCLCD22   equ       %00000100
mLCDWF22_BPDLCD22   equ       %00001000
mLCDWF22_BPELCD22   equ       %00010000
mLCDWF22_BPFLCD22   equ       %00100000
mLCDWF22_BPGLCD22   equ       %01000000
mLCDWF22_BPHLCD22   equ       %10000000

;*** LCDWF23 - LCD Waveform Register 23
LCDWF23             equ       $000010A7           ;*** LCDWF23 - LCD Waveform Register 23
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF23_BPALCD23    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPBLCD23    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPCLCD23    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPDLCD23    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPELCD23    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPFLCD23    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPGLCD23    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPHLCD23    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF23_BPALCD23   equ       %00000001
mLCDWF23_BPBLCD23   equ       %00000010
mLCDWF23_BPCLCD23   equ       %00000100
mLCDWF23_BPDLCD23   equ       %00001000
mLCDWF23_BPELCD23   equ       %00010000
mLCDWF23_BPFLCD23   equ       %00100000
mLCDWF23_BPGLCD23   equ       %01000000
mLCDWF23_BPHLCD23   equ       %10000000

;*** LCDWF24 - LCD Waveform Register 24
LCDWF24             equ       $000010A8           ;*** LCDWF24 - LCD Waveform Register 24
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF24_BPALCD24    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPBLCD24    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPCLCD24    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPDLCD24    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPELCD24    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPFLCD24    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPGLCD24    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPHLCD24    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF24_BPALCD24   equ       %00000001
mLCDWF24_BPBLCD24   equ       %00000010
mLCDWF24_BPCLCD24   equ       %00000100
mLCDWF24_BPDLCD24   equ       %00001000
mLCDWF24_BPELCD24   equ       %00010000
mLCDWF24_BPFLCD24   equ       %00100000
mLCDWF24_BPGLCD24   equ       %01000000
mLCDWF24_BPHLCD24   equ       %10000000

;*** LCDWF25 - LCD Waveform Register 25
LCDWF25             equ       $000010A9           ;*** LCDWF25 - LCD Waveform Register 25
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF25_BPALCD25    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPBLCD25    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPCLCD25    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPDLCD25    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPELCD25    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPFLCD25    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPGLCD25    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPHLCD25    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF25_BPALCD25   equ       %00000001
mLCDWF25_BPBLCD25   equ       %00000010
mLCDWF25_BPCLCD25   equ       %00000100
mLCDWF25_BPDLCD25   equ       %00001000
mLCDWF25_BPELCD25   equ       %00010000
mLCDWF25_BPFLCD25   equ       %00100000
mLCDWF25_BPGLCD25   equ       %01000000
mLCDWF25_BPHLCD25   equ       %10000000

;*** LCDWF26 - LCD Waveform Register 26
LCDWF26             equ       $000010AA           ;*** LCDWF26 - LCD Waveform Register 26
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF26_BPALCD26    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPBLCD26    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPCLCD26    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPDLCD26    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPELCD26    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPFLCD26    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPGLCD26    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPHLCD26    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF26_BPALCD26   equ       %00000001
mLCDWF26_BPBLCD26   equ       %00000010
mLCDWF26_BPCLCD26   equ       %00000100
mLCDWF26_BPDLCD26   equ       %00001000
mLCDWF26_BPELCD26   equ       %00010000
mLCDWF26_BPFLCD26   equ       %00100000
mLCDWF26_BPGLCD26   equ       %01000000
mLCDWF26_BPHLCD26   equ       %10000000

;*** LCDWF27 - LCD Waveform Register 27
LCDWF27             equ       $000010AB           ;*** LCDWF27 - LCD Waveform Register 27
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF27_BPALCD27    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPBLCD27    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPCLCD27    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPDLCD27    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPELCD27    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPFLCD27    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPGLCD27    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPHLCD27    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF27_BPALCD27   equ       %00000001
mLCDWF27_BPBLCD27   equ       %00000010
mLCDWF27_BPCLCD27   equ       %00000100
mLCDWF27_BPDLCD27   equ       %00001000
mLCDWF27_BPELCD27   equ       %00010000
mLCDWF27_BPFLCD27   equ       %00100000
mLCDWF27_BPGLCD27   equ       %01000000
mLCDWF27_BPHLCD27   equ       %10000000

;*** LCDWF28 - LCD Waveform Register 28
LCDWF28             equ       $000010AC           ;*** LCDWF28 - LCD Waveform Register 28
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF28_BPALCD28    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPBLCD28    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPCLCD28    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPDLCD28    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPELCD28    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPFLCD28    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPGLCD28    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPHLCD28    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF28_BPALCD28   equ       %00000001
mLCDWF28_BPBLCD28   equ       %00000010
mLCDWF28_BPCLCD28   equ       %00000100
mLCDWF28_BPDLCD28   equ       %00001000
mLCDWF28_BPELCD28   equ       %00010000
mLCDWF28_BPFLCD28   equ       %00100000
mLCDWF28_BPGLCD28   equ       %01000000
mLCDWF28_BPHLCD28   equ       %10000000

;*** LCDWF29 - LCD Waveform Register 29
LCDWF29             equ       $000010AD           ;*** LCDWF29 - LCD Waveform Register 29
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF29_BPALCD29    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPBLCD29    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPCLCD29    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPDLCD29    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPELCD29    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPFLCD29    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPGLCD29    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPHLCD29    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF29_BPALCD29   equ       %00000001
mLCDWF29_BPBLCD29   equ       %00000010
mLCDWF29_BPCLCD29   equ       %00000100
mLCDWF29_BPDLCD29   equ       %00001000
mLCDWF29_BPELCD29   equ       %00010000
mLCDWF29_BPFLCD29   equ       %00100000
mLCDWF29_BPGLCD29   equ       %01000000
mLCDWF29_BPHLCD29   equ       %10000000

;*** LCDWF30 - LCD Waveform Register 30
LCDWF30             equ       $000010AE           ;*** LCDWF30 - LCD Waveform Register 30
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF30_BPALCD30    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPBLCD30    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPCLCD30    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPDLCD30    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPELCD30    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPFLCD30    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPGLCD30    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPHLCD30    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF30_BPALCD30   equ       %00000001
mLCDWF30_BPBLCD30   equ       %00000010
mLCDWF30_BPCLCD30   equ       %00000100
mLCDWF30_BPDLCD30   equ       %00001000
mLCDWF30_BPELCD30   equ       %00010000
mLCDWF30_BPFLCD30   equ       %00100000
mLCDWF30_BPGLCD30   equ       %01000000
mLCDWF30_BPHLCD30   equ       %10000000

;*** LCDWF31 - LCD Waveform Register 31
LCDWF31             equ       $000010AF           ;*** LCDWF31 - LCD Waveform Register 31
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF31_BPALCD31    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPBLCD31    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPCLCD31    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPDLCD31    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPELCD31    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPFLCD31    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPGLCD31    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPHLCD31    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF31_BPALCD31   equ       %00000001
mLCDWF31_BPBLCD31   equ       %00000010
mLCDWF31_BPCLCD31   equ       %00000100
mLCDWF31_BPDLCD31   equ       %00001000
mLCDWF31_BPELCD31   equ       %00010000
mLCDWF31_BPFLCD31   equ       %00100000
mLCDWF31_BPGLCD31   equ       %01000000
mLCDWF31_BPHLCD31   equ       %10000000

;*** LCDWF32 - LCD Waveform Register 32
LCDWF32             equ       $000010B0           ;*** LCDWF32 - LCD Waveform Register 32
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF32_BPALCD32    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPBLCD32    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPCLCD32    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPDLCD32    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPELCD32    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPFLCD32    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPGLCD32    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPHLCD32    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF32_BPALCD32   equ       %00000001
mLCDWF32_BPBLCD32   equ       %00000010
mLCDWF32_BPCLCD32   equ       %00000100
mLCDWF32_BPDLCD32   equ       %00001000
mLCDWF32_BPELCD32   equ       %00010000
mLCDWF32_BPFLCD32   equ       %00100000
mLCDWF32_BPGLCD32   equ       %01000000
mLCDWF32_BPHLCD32   equ       %10000000

;*** LCDWF33 - LCD Waveform Register 33
LCDWF33             equ       $000010B1           ;*** LCDWF33 - LCD Waveform Register 33
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF33_BPALCD33    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPBLCD33    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPCLCD33    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPDLCD33    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPELCD33    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPFLCD33    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPGLCD33    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPHLCD33    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF33_BPALCD33   equ       %00000001
mLCDWF33_BPBLCD33   equ       %00000010
mLCDWF33_BPCLCD33   equ       %00000100
mLCDWF33_BPDLCD33   equ       %00001000
mLCDWF33_BPELCD33   equ       %00010000
mLCDWF33_BPFLCD33   equ       %00100000
mLCDWF33_BPGLCD33   equ       %01000000
mLCDWF33_BPHLCD33   equ       %10000000

;*** LCDWF34 - LCD Waveform Register 34
LCDWF34             equ       $000010B2           ;*** LCDWF34 - LCD Waveform Register 34
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF34_BPALCD34    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPBLCD34    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPCLCD34    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPDLCD34    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPELCD34    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPFLCD34    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPGLCD34    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPHLCD34    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF34_BPALCD34   equ       %00000001
mLCDWF34_BPBLCD34   equ       %00000010
mLCDWF34_BPCLCD34   equ       %00000100
mLCDWF34_BPDLCD34   equ       %00001000
mLCDWF34_BPELCD34   equ       %00010000
mLCDWF34_BPFLCD34   equ       %00100000
mLCDWF34_BPGLCD34   equ       %01000000
mLCDWF34_BPHLCD34   equ       %10000000

;*** LCDWF35 - LCD Waveform Register 35
LCDWF35             equ       $000010B3           ;*** LCDWF35 - LCD Waveform Register 35
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF35_BPALCD35    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPBLCD35    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPCLCD35    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPDLCD35    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPELCD35    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPFLCD35    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPGLCD35    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPHLCD35    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF35_BPALCD35   equ       %00000001
mLCDWF35_BPBLCD35   equ       %00000010
mLCDWF35_BPCLCD35   equ       %00000100
mLCDWF35_BPDLCD35   equ       %00001000
mLCDWF35_BPELCD35   equ       %00010000
mLCDWF35_BPFLCD35   equ       %00100000
mLCDWF35_BPGLCD35   equ       %01000000
mLCDWF35_BPHLCD35   equ       %10000000

;*** LCDWF36 - LCD Waveform Register 36
LCDWF36             equ       $000010B4           ;*** LCDWF36 - LCD Waveform Register 36
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF36_BPALCD36    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPBLCD36    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPCLCD36    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPDLCD36    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPELCD36    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPFLCD36    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPGLCD36    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPHLCD36    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF36_BPALCD36   equ       %00000001
mLCDWF36_BPBLCD36   equ       %00000010
mLCDWF36_BPCLCD36   equ       %00000100
mLCDWF36_BPDLCD36   equ       %00001000
mLCDWF36_BPELCD36   equ       %00010000
mLCDWF36_BPFLCD36   equ       %00100000
mLCDWF36_BPGLCD36   equ       %01000000
mLCDWF36_BPHLCD36   equ       %10000000

;*** LCDWF37 - LCD Waveform Register 37
LCDWF37             equ       $000010B5           ;*** LCDWF37 - LCD Waveform Register 37
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF37_BPALCD37    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPBLCD37    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPCLCD37    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPDLCD37    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPELCD37    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPFLCD37    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPGLCD37    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPHLCD37    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF37_BPALCD37   equ       %00000001
mLCDWF37_BPBLCD37   equ       %00000010
mLCDWF37_BPCLCD37   equ       %00000100
mLCDWF37_BPDLCD37   equ       %00001000
mLCDWF37_BPELCD37   equ       %00010000
mLCDWF37_BPFLCD37   equ       %00100000
mLCDWF37_BPGLCD37   equ       %01000000
mLCDWF37_BPHLCD37   equ       %10000000

;*** LCDWF38 - LCD Waveform Register 38
LCDWF38             equ       $000010B6           ;*** LCDWF38 - LCD Waveform Register 38
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF38_BPALCD38    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPBLCD38    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPCLCD38    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPDLCD38    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPELCD38    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPFLCD38    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPGLCD38    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPHLCD38    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF38_BPALCD38   equ       %00000001
mLCDWF38_BPBLCD38   equ       %00000010
mLCDWF38_BPCLCD38   equ       %00000100
mLCDWF38_BPDLCD38   equ       %00001000
mLCDWF38_BPELCD38   equ       %00010000
mLCDWF38_BPFLCD38   equ       %00100000
mLCDWF38_BPGLCD38   equ       %01000000
mLCDWF38_BPHLCD38   equ       %10000000

;*** LCDWF39 - LCD Waveform Register 39
LCDWF39             equ       $000010B7           ;*** LCDWF39 - LCD Waveform Register 39
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF39_BPALCD39    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPBLCD39    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPCLCD39    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPDLCD39    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPELCD39    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPFLCD39    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPGLCD39    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPHLCD39    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF39_BPALCD39   equ       %00000001
mLCDWF39_BPBLCD39   equ       %00000010
mLCDWF39_BPCLCD39   equ       %00000100
mLCDWF39_BPDLCD39   equ       %00001000
mLCDWF39_BPELCD39   equ       %00010000
mLCDWF39_BPFLCD39   equ       %00100000
mLCDWF39_BPGLCD39   equ       %01000000
mLCDWF39_BPHLCD39   equ       %10000000

;*** LCDWF40 - LCD Waveform Register 40
LCDWF40             equ       $000010B8           ;*** LCDWF40 - LCD Waveform Register 40
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF40_BPALCD40    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPBLCD40    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPCLCD40    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPDLCD40    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPELCD40    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPFLCD40    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPGLCD40    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPHLCD40    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF40_BPALCD40   equ       %00000001
mLCDWF40_BPBLCD40   equ       %00000010
mLCDWF40_BPCLCD40   equ       %00000100
mLCDWF40_BPDLCD40   equ       %00001000
mLCDWF40_BPELCD40   equ       %00010000
mLCDWF40_BPFLCD40   equ       %00100000
mLCDWF40_BPGLCD40   equ       %01000000
mLCDWF40_BPHLCD40   equ       %10000000

;*** LCDWF41 - LCD Waveform Register 41
LCDWF41             equ       $000010B9           ;*** LCDWF41 - LCD Waveform Register 41
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF41_BPALCD41    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPBLCD41    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPCLCD41    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPDLCD41    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPELCD41    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPFLCD41    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPGLCD41    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPHLCD41    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF41_BPALCD41   equ       %00000001
mLCDWF41_BPBLCD41   equ       %00000010
mLCDWF41_BPCLCD41   equ       %00000100
mLCDWF41_BPDLCD41   equ       %00001000
mLCDWF41_BPELCD41   equ       %00010000
mLCDWF41_BPFLCD41   equ       %00100000
mLCDWF41_BPGLCD41   equ       %01000000
mLCDWF41_BPHLCD41   equ       %10000000

;*** LCDWF42 - LCD Waveform Register 42
LCDWF42             equ       $000010BA           ;*** LCDWF42 - LCD Waveform Register 42
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF42_BPALCD42    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPBLCD42    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPCLCD42    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPDLCD42    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPELCD42    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPFLCD42    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPGLCD42    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPHLCD42    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF42_BPALCD42   equ       %00000001
mLCDWF42_BPBLCD42   equ       %00000010
mLCDWF42_BPCLCD42   equ       %00000100
mLCDWF42_BPDLCD42   equ       %00001000
mLCDWF42_BPELCD42   equ       %00010000
mLCDWF42_BPFLCD42   equ       %00100000
mLCDWF42_BPGLCD42   equ       %01000000
mLCDWF42_BPHLCD42   equ       %10000000

;*** LCDWF43 - LCD Waveform Register 43
LCDWF43             equ       $000010BB           ;*** LCDWF43 - LCD Waveform Register 43
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF43_BPALCD43    equ       0                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPBLCD43    equ       1                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPCLCD43    equ       2                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPDLCD43    equ       3                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPELCD43    equ       4                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPFLCD43    equ       5                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPGLCD43    equ       6                   ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPHLCD43    equ       7                   ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF43_BPALCD43   equ       %00000001
mLCDWF43_BPBLCD43   equ       %00000010
mLCDWF43_BPCLCD43   equ       %00000100
mLCDWF43_BPDLCD43   equ       %00001000
mLCDWF43_BPELCD43   equ       %00010000
mLCDWF43_BPFLCD43   equ       %00100000
mLCDWF43_BPGLCD43   equ       %01000000
mLCDWF43_BPHLCD43   equ       %10000000

;*** SRS - System Reset Status Register
SRS                 equ       $00001800           ;*** SRS - System Reset Status Register
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

;*** SBDFR - System Background Debug Force Reset Register
SBDFR               equ       $00001801           ;*** SBDFR - System Background Debug Force Reset Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBDFR_BDFR          equ       0                   ; Background Debug Force Reset
; bit position masks
mSBDFR_BDFR         equ       %00000001

;*** SOPT1 - System Options Register 1
SOPT1               equ       $00001802           ;*** SOPT1 - System Options Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_COPW          equ       0                   ; COP Window Mode
SOPT1_COPCLKS       equ       1                   ; COP Watchdog Clock Select
SOPT1_COPT0         equ       2                   ; COP Watchdog Timeout, bit 0
SOPT1_COPT1         equ       3                   ; COP Watchdog Timeout, bit 1
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_BKGDPE        equ       7                   ; Unused
; bit position masks
mSOPT1_COPW         equ       %00000001
mSOPT1_COPCLKS      equ       %00000010
mSOPT1_COPT0        equ       %00000100
mSOPT1_COPT1        equ       %00001000
mSOPT1_STOPE        equ       %00100000
mSOPT1_BKGDPE       equ       %10000000

;*** SDID - System Device Identification Register
SDID                equ       $00001805           ;*** SDID - System Device Identification Register

;*** SDIDH - System Device Identification Register High
SDIDH               equ       $00001805           ;*** SDIDH - System Device Identification Register High
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
SDIDL               equ       $00001806           ;*** SDIDL - System Device Identification Register Low
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
SCGC1_SCI0          equ       0                   ; SCI0 Clock Gate Control
SCGC1_SCI1          equ       1                   ; SCI1 Clock Gate Control
SCGC1_SCI2          equ       2                   ; SCI2 Clock Gate Control
SCGC1_SCI3          equ       3                   ; SCI3 Clock Gate Control
SCGC1_IIC           equ       4                   ; IIC Clock Gate Control
SCGC1_KBI           equ       5                   ; KBI Clock Gate Control
SCGC1_ADC0          equ       6                   ; ADC0 Clock Gate Control
SCGC1_ADC1          equ       7                   ; ADC1 Clock Gate Control
; bit position masks
mSCGC1_SCI0         equ       %00000001
mSCGC1_SCI1         equ       %00000010
mSCGC1_SCI2         equ       %00000100
mSCGC1_SCI3         equ       %00001000
mSCGC1_IIC          equ       %00010000
mSCGC1_KBI          equ       %00100000
mSCGC1_ADC0         equ       %01000000
mSCGC1_ADC1         equ       %10000000

;*** SCGC2 - System Clock Gating Control 2 Register
SCGC2               equ       $00001809           ;*** SCGC2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI0          equ       0                   ; SPI0 Clock Gate Control
SCGC2_SPI1          equ       1                   ; SPI1 Clock Gate Control
SCGC2_SPI2          equ       2                   ; SPI2 Clock Gate Control
SCGC2_LCD           equ       3                   ; LCD Clock Gate Control
SCGC2_IRQ           equ       4                   ; IRQ Clock Gate Control
SCGC2_VREF          equ       5                   ; VREF Clock Gate Control
SCGC2_CLKPRE        equ       7                   ; CLKPRE Clock Gate Control
; bit position masks
mSCGC2_SPI0         equ       %00000001
mSCGC2_SPI1         equ       %00000010
mSCGC2_SPI2         equ       %00000100
mSCGC2_LCD          equ       %00001000
mSCGC2_IRQ          equ       %00010000
mSCGC2_VREF         equ       %00100000
mSCGC2_CLKPRE       equ       %10000000

;*** SCGC3 - System Clock Gating Control 3 Register
SCGC3               equ       $0000180A           ;*** SCGC3 - System Clock Gating Control 3 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC3_PTA           equ       0                   ; PTA Clock Gate Control
SCGC3_PTB           equ       1                   ; PTB Clock Gate Control
SCGC3_PTC           equ       2                   ; PTC Clock Gate Control
SCGC3_PTD           equ       3                   ; PTD Clock Gate Control
SCGC3_PTE           equ       4                   ; PTE Clock Gate Control
SCGC3_PTF           equ       5                   ; PTF Clock Gate Control
SCGC3_PTG           equ       6                   ; PTG Clock Gate Control
SCGC3_PTH           equ       7                   ; PTH Clock Gate Control
; bit position masks
mSCGC3_PTA          equ       %00000001
mSCGC3_PTB          equ       %00000010
mSCGC3_PTC          equ       %00000100
mSCGC3_PTD          equ       %00001000
mSCGC3_PTE          equ       %00010000
mSCGC3_PTF          equ       %00100000
mSCGC3_PTG          equ       %01000000
mSCGC3_PTH          equ       %10000000

;*** SCGC4 - System Clock Gating Control 4 Register
SCGC4               equ       $0000180B           ;*** SCGC4 - System Clock Gating Control 4 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC4_MTIM3         equ       0                   ; MTIM3 Clock Gate Control
SCGC4_MTIM2         equ       1                   ; MTIM2 Clock Gate Control
SCGC4_MTIM1         equ       2                   ; MTIM1 Clock Gate Control
SCGC4_PDB           equ       3                   ; PDB Clock Gate Control
SCGC4_FTM           equ       4                   ; FTM Clock Gate Control
SCGC4_CRC           equ       5                   ; CRC Clock Gate Control
SCGC4_MUXCTRL       equ       6                   ; MUXCTRL Clock Gate Control
; bit position masks
mSCGC4_MTIM3        equ       %00000001
mSCGC4_MTIM2        equ       %00000010
mSCGC4_MTIM1        equ       %00000100
mSCGC4_PDB          equ       %00001000
mSCGC4_FTM          equ       %00010000
mSCGC4_CRC          equ       %00100000
mSCGC4_MUXCTRL      equ       %01000000

;*** SCGC5 - System Clock Gating Control 5 Register
SCGC5               equ       $0000180C           ;*** SCGC5 - System Clock Gating Control 5 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC5_FLS           equ       0                   ; FLS Clock Gate Control
SCGC5_PCNT          equ       2                   ; PCNT Clock Gate Control
SCGC5_IRTC          equ       3                   ; IRTC Clock Gate Control
SCGC5_BKPT          equ       4                   ; BKPT Clock Gate Control
SCGC5_PRACMP0       equ       5                   ; PRACMP0 Clock Gate Control
SCGC5_PRACMP1       equ       6                   ; PRACMP1 Clock Gate Control
SCGC5_PRACMP2       equ       7                   ; PRACMP2 Clock Gate Control
; bit position masks
mSCGC5_FLS          equ       %00000001
mSCGC5_PCNT         equ       %00000100
mSCGC5_IRTC         equ       %00001000
mSCGC5_BKPT         equ       %00010000
mSCGC5_PRACMP0      equ       %00100000
mSCGC5_PRACMP1      equ       %01000000
mSCGC5_PRACMP2      equ       %10000000

;*** SIMIPS1 - Internal Peripheral Select Register 1
SIMIPS1             equ       $0000180D           ;*** SIMIPS1 - Internal Peripheral Select Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS1_MTIM2CS     equ       2                   ; MTIM2 External Clock Select
SIMIPS1_PCNTSS      equ       3                   ; PCNT Sensor Select
SIMIPS1_MTIM3CS     equ       5                   ; MTIM3 External Clock Select
SIMIPS1_FTMCS       equ       6                   ; FTM External Clock Select
; bit position masks
mSIMIPS1_MTIM2CS    equ       %00000100
mSIMIPS1_PCNTSS     equ       %00001000
mSIMIPS1_MTIM3CS    equ       %00100000
mSIMIPS1_FTMCS      equ       %11000000

;*** SIMIPS2 - Internal Peripheral Select Register 2
SIMIPS2             equ       $0000180E           ;*** SIMIPS2 - Internal Peripheral Select Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS2_MODTX1      equ       0                   ; Modulate TxD1
SIMIPS2_MTBASE1     equ       2                   ; SCI1 Tx Modulation Time Base Select
SIMIPS2_RX1IN       equ       5                   ; SCI1 Rx Input Pin Select
; bit position masks
mSIMIPS2_MODTX1     equ       %00000001
mSIMIPS2_MTBASE1    equ       %00011100
mSIMIPS2_RX1IN      equ       %00100000

;*** SIMIPS3 - Internal Peripheral Select Register 3
SIMIPS3             equ       $0000180F           ;*** SIMIPS3 - Internal Peripheral Select Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMIPS3_MODTX2      equ       0                   ; Modulate Tx2
SIMIPS3_DDRIVE      equ       1                   ; Double Current Drive on TxD2 Enable
SIMIPS3_MTBASE2     equ       2                   ; SCI2 Tx Modulation Time Base Select
SIMIPS3_RX2IN       equ       5                   ; SCI2 Rx Input Pin Select
SIMIPS3_PCNTFCS     equ       6                   ; PCNT Filter Clock Select
; bit position masks
mSIMIPS3_MODTX2     equ       %00000001
mSIMIPS3_DDRIVE     equ       %00000010
mSIMIPS3_MTBASE2    equ       %00011100
mSIMIPS3_RX2IN      equ       %00100000
mSIMIPS3_PCNTFCS    equ       %11000000

;*** SIMCO - SIM Clock Options Register
SIMCO               equ       $00001813           ;*** SIMCO - SIM Clock Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SIMCO_CS            equ       0                   ; Clock Select for CLKOUT pin
; bit position masks
mSIMCO_CS           equ       %00001111

;*** CCSCTRL - Clock Check and Select Control Register
CCSCTRL             equ       $00001814           ;*** CCSCTRL - Clock Check and Select Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CCSCTRL_ICS_EXT_CLK_SEL equ       0                   ; ICS External Clock Select
; bit position masks
mCCSCTRL_ICS_EXT_CLK_SEL equ       %00000001

;*** SPMSC1 - System Power Management Status and Control 1 Register
SPMSC1              equ       $0000181C           ;*** SPMSC1 - System Power Management Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE         equ       0                   ; Bandgap Buffer Enable
SPMSC1_BGBDS        equ       1                   ; Bandgap Buffer Drive Select
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE        equ       5                   ; Low-Voltage Detect Interrupt Enable
SPMSC1_LVDACK       equ       6                   ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF         equ       7                   ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_BGBE        equ       %00000001
mSPMSC1_BGBDS       equ       %00000010
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

;*** FOPT - Flash Options Register
FOPT                equ       $00001821           ;*** FOPT - Flash Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SEC0           equ       0                   ; Flash Security Bit 0
FOPT_SEC1           equ       1                   ; Flash Security Bit 1
FOPT_FNORED         equ       6                   ; Vector Redirection Disable
FOPT_KEYEN          equ       7                   ; Enable Security Key Writing
; bit position masks
mFOPT_SEC0          equ       %00000001
mFOPT_SEC1          equ       %00000010
mFOPT_FNORED        equ       %01000000
mFOPT_KEYEN         equ       %10000000

;*** FCNFG - Flash Configuration Register
FCNFG               equ       $00001823           ;*** FCNFG - Flash Configuration Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC        equ       5                   ; Enable Security Key Writing
; bit position masks
mFCNFG_KEYACC       equ       %00100000

;*** FPROT - Flash Protection Register
FPROT               equ       $00001824           ;*** FPROT - Flash Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPDIS         equ       0                   ; Flash Protection Disable
FPROT_FPS0          equ       1                   ; Flash Protection Size, bit 0
FPROT_FPS1          equ       2                   ; Flash Protection Size, bit 1
FPROT_FPS2          equ       3                   ; Flash Protection Size, bit 2
FPROT_FPS3          equ       4                   ; Flash Protection Size, bit 3
FPROT_FPS4          equ       5                   ; Flash Protection Size, bit 4
FPROT_FPS5          equ       6                   ; Flash Protection Size, bit 5
FPROT_FPS6          equ       7                   ; Flash Protection Size, bit 6
; bit position masks
mFPROT_FPDIS        equ       %00000001
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
FCMD_FCMD7          equ       7                   ; Flash Command, bit 7
; bit position masks
mFCMD_FCMD0         equ       %00000001
mFCMD_FCMD1         equ       %00000010
mFCMD_FCMD2         equ       %00000100
mFCMD_FCMD3         equ       %00001000
mFCMD_FCMD4         equ       %00010000
mFCMD_FCMD5         equ       %00100000
mFCMD_FCMD6         equ       %01000000
mFCMD_FCMD7         equ       %10000000

;*** BKPTCA_word - Breakpoint Comparator A Register(word access)
BKPTCA_word         equ       $00001830           ;*** BKPTCA_word - Breakpoint Comparator A Register(word access)

;*** BKPTCAH - Breakpoint Comparator A High Register
BKPTCAH             equ       $00001830           ;*** BKPTCAH - Breakpoint Comparator A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTCAH_Bit8        equ       0                   ; Comparator A High Compare Bit 8
BKPTCAH_Bit9        equ       1                   ; Comparator A High Compare Bit 9
BKPTCAH_Bit10       equ       2                   ; Comparator A High Compare Bit 10
BKPTCAH_Bit11       equ       3                   ; Comparator A High Compare Bit 11
BKPTCAH_Bit12       equ       4                   ; Comparator A High Compare Bit 12
BKPTCAH_Bit13       equ       5                   ; Comparator A High Compare Bit 13
BKPTCAH_Bit14       equ       6                   ; Comparator A High Compare Bit 14
BKPTCAH_Bit15       equ       7                   ; Comparator A High Compare Bit 15
; bit position masks
mBKPTCAH_Bit8       equ       %00000001
mBKPTCAH_Bit9       equ       %00000010
mBKPTCAH_Bit10      equ       %00000100
mBKPTCAH_Bit11      equ       %00001000
mBKPTCAH_Bit12      equ       %00010000
mBKPTCAH_Bit13      equ       %00100000
mBKPTCAH_Bit14      equ       %01000000
mBKPTCAH_Bit15      equ       %10000000

;*** BKPTCAL - Breakpoint Comparator A Low Register
BKPTCAL             equ       $00001831           ;*** BKPTCAL - Breakpoint Comparator A Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTCAL_Bit0        equ       0                   ; Comparator A Low Compare Bit 0
BKPTCAL_Bit1        equ       1                   ; Comparator A Low Compare Bit 1
BKPTCAL_Bit2        equ       2                   ; Comparator A Low Compare Bit 2
BKPTCAL_Bit3        equ       3                   ; Comparator A Low Compare Bit 3
BKPTCAL_Bit4        equ       4                   ; Comparator A Low Compare Bit 4
BKPTCAL_Bit5        equ       5                   ; Comparator A Low Compare Bit 5
BKPTCAL_Bit6        equ       6                   ; Comparator A Low Compare Bit 6
BKPTCAL_Bit7        equ       7                   ; Comparator A Low Compare Bit 7
; bit position masks
mBKPTCAL_Bit0       equ       %00000001
mBKPTCAL_Bit1       equ       %00000010
mBKPTCAL_Bit2       equ       %00000100
mBKPTCAL_Bit3       equ       %00001000
mBKPTCAL_Bit4       equ       %00010000
mBKPTCAL_Bit5       equ       %00100000
mBKPTCAL_Bit6       equ       %01000000
mBKPTCAL_Bit7       equ       %10000000

;*** BKPTCB_word - Breakpoint Comparator B Register(word access)
BKPTCB_word         equ       $00001832           ;*** BKPTCB_word - Breakpoint Comparator B Register(word access)

;*** BKPTCBH - Breakpoint Comparator B High Register
BKPTCBH             equ       $00001832           ;*** BKPTCBH - Breakpoint Comparator B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTCBH_Bit8        equ       0                   ; Comparator B High Compare Bit 8
BKPTCBH_Bit9        equ       1                   ; Comparator B High Compare Bit 9
BKPTCBH_Bit10       equ       2                   ; Comparator B High Compare Bit 10
BKPTCBH_Bit11       equ       3                   ; Comparator B High Compare Bit 11
BKPTCBH_Bit12       equ       4                   ; Comparator B High Compare Bit 12
BKPTCBH_Bit13       equ       5                   ; Comparator B High Compare Bit 13
BKPTCBH_Bit14       equ       6                   ; Comparator B High Compare Bit 14
BKPTCBH_Bit15       equ       7                   ; Comparator B High Compare Bit 15
; bit position masks
mBKPTCBH_Bit8       equ       %00000001
mBKPTCBH_Bit9       equ       %00000010
mBKPTCBH_Bit10      equ       %00000100
mBKPTCBH_Bit11      equ       %00001000
mBKPTCBH_Bit12      equ       %00010000
mBKPTCBH_Bit13      equ       %00100000
mBKPTCBH_Bit14      equ       %01000000
mBKPTCBH_Bit15      equ       %10000000

;*** BKPTCBL - Breakpoint Comparator B Low Register
BKPTCBL             equ       $00001833           ;*** BKPTCBL - Breakpoint Comparator B Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTCBL_Bit0        equ       0                   ; Comparator B Low Compare Bit 0
BKPTCBL_Bit1        equ       1                   ; Comparator B Low Compare Bit 1
BKPTCBL_Bit2        equ       2                   ; Comparator B Low Compare Bit 2
BKPTCBL_Bit3        equ       3                   ; Comparator B Low Compare Bit 3
BKPTCBL_Bit4        equ       4                   ; Comparator B Low Compare Bit 4
BKPTCBL_Bit5        equ       5                   ; Comparator B Low Compare Bit 5
BKPTCBL_Bit6        equ       6                   ; Comparator B Low Compare Bit 6
BKPTCBL_Bit7        equ       7                   ; Comparator B Low Compare Bit 7
; bit position masks
mBKPTCBL_Bit0       equ       %00000001
mBKPTCBL_Bit1       equ       %00000010
mBKPTCBL_Bit2       equ       %00000100
mBKPTCBL_Bit3       equ       %00001000
mBKPTCBL_Bit4       equ       %00010000
mBKPTCBL_Bit5       equ       %00100000
mBKPTCBL_Bit6       equ       %01000000
mBKPTCBL_Bit7       equ       %10000000

;*** BKPTCC_word - Breakpoint Comparator C Register(word access)
BKPTCC_word         equ       $00001834           ;*** BKPTCC_word - Breakpoint Comparator C Register(word access)

;*** BKPTCCH - Breakpoint Comparator C High Register
BKPTCCH             equ       $00001834           ;*** BKPTCCH - Breakpoint Comparator C High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTCCH_Bit8        equ       0                   ; Comparator C High Compare Bit 8
BKPTCCH_Bit9        equ       1                   ; Comparator C High Compare Bit 9
BKPTCCH_Bit10       equ       2                   ; Comparator C High Compare Bit 10
BKPTCCH_Bit11       equ       3                   ; Comparator C High Compare Bit 11
BKPTCCH_Bit12       equ       4                   ; Comparator C High Compare Bit 12
BKPTCCH_Bit13       equ       5                   ; Comparator C High Compare Bit 13
BKPTCCH_Bit14       equ       6                   ; Comparator C High Compare Bit 14
BKPTCCH_Bit15       equ       7                   ; Comparator C High Compare Bit 15
; bit position masks
mBKPTCCH_Bit8       equ       %00000001
mBKPTCCH_Bit9       equ       %00000010
mBKPTCCH_Bit10      equ       %00000100
mBKPTCCH_Bit11      equ       %00001000
mBKPTCCH_Bit12      equ       %00010000
mBKPTCCH_Bit13      equ       %00100000
mBKPTCCH_Bit14      equ       %01000000
mBKPTCCH_Bit15      equ       %10000000

;*** BKPTCCL - Breakpoint Comparator C Low Register
BKPTCCL             equ       $00001835           ;*** BKPTCCL - Breakpoint Comparator C Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTCCL_Bit0        equ       0                   ; Comparator C Low Compare Bit 0
BKPTCCL_Bit1        equ       1                   ; Comparator C Low Compare Bit 1
BKPTCCL_Bit2        equ       2                   ; Comparator C Low Compare Bit 2
BKPTCCL_Bit3        equ       3                   ; Comparator C Low Compare Bit 3
BKPTCCL_Bit4        equ       4                   ; Comparator C Low Compare Bit 4
BKPTCCL_Bit5        equ       5                   ; Comparator C Low Compare Bit 5
BKPTCCL_Bit6        equ       6                   ; Comparator C Low Compare Bit 6
BKPTCCL_Bit7        equ       7                   ; Comparator C Low Compare Bit 7
; bit position masks
mBKPTCCL_Bit0       equ       %00000001
mBKPTCCL_Bit1       equ       %00000010
mBKPTCCL_Bit2       equ       %00000100
mBKPTCCL_Bit3       equ       %00001000
mBKPTCCL_Bit4       equ       %00010000
mBKPTCCL_Bit5       equ       %00100000
mBKPTCCL_Bit6       equ       %01000000
mBKPTCCL_Bit7       equ       %10000000

;*** BKPTAC - Breakpoint Comparator A Control Register
BKPTAC              equ       $00001836           ;*** BKPTAC - Breakpoint Comparator A Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTAC_FMDC         equ       0                   ; Full Mode Data Condition
BKPTAC_FMEN         equ       1                   ; Full Mode Enable Bit
BKPTAC_PAGESELA     equ       3                   ; Comparator A Page Select Bit
BKPTAC_TAGA         equ       4                   ; Tag or Force Bit
BKPTAC_RWA          equ       5                   ; Read/Write Comparator A Value Bit
BKPTAC_RWAEN        equ       6                   ; Read/Write Comparator A Enable Bit
BKPTAC_BKPTAEN      equ       7                   ; BKPT A Enable Bit
; bit position masks
mBKPTAC_FMDC        equ       %00000001
mBKPTAC_FMEN        equ       %00000010
mBKPTAC_PAGESELA    equ       %00001000
mBKPTAC_TAGA        equ       %00010000
mBKPTAC_RWA         equ       %00100000
mBKPTAC_RWAEN       equ       %01000000
mBKPTAC_BKPTAEN     equ       %10000000

;*** BKPTBC - Breakpoint Comparator B Control Register
BKPTBC              equ       $00001837           ;*** BKPTBC - Breakpoint Comparator B Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTBC_PAGESELB     equ       3                   ; Comparator B Page Select Bit
BKPTBC_TAGB         equ       4                   ; Tag or Force Bit
BKPTBC_RWB          equ       5                   ; Read/Write Comparator B Value Bit
BKPTBC_RWBEN        equ       6                   ; Read/Write Comparator B Enable Bit
BKPTBC_BKPTBEN      equ       7                   ; BKPT B Enable Bit
; bit position masks
mBKPTBC_PAGESELB    equ       %00001000
mBKPTBC_TAGB        equ       %00010000
mBKPTBC_RWB         equ       %00100000
mBKPTBC_RWBEN       equ       %01000000
mBKPTBC_BKPTBEN     equ       %10000000

;*** BKPTBCC - Breakpoint Comparator C Control Register
BKPTBCC             equ       $00001838           ;*** BKPTBCC - Breakpoint Comparator C Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTBCC_PAGESELC    equ       3                   ; Comparator C Page Select Bit
BKPTBCC_TAGC        equ       4                   ; Tag or Force Bit
BKPTBCC_RWC         equ       5                   ; Read/Write Comparator C Value Bit
BKPTBCC_RWCEN       equ       6                   ; Read/Write Comparator C Enable Bit
BKPTBCC_BKPTCEN     equ       7                   ; BKPT C Enable Bit
; bit position masks
mBKPTBCC_PAGESELC   equ       %00001000
mBKPTBCC_TAGC       equ       %00010000
mBKPTBCC_RWC        equ       %00100000
mBKPTBCC_RWCEN      equ       %01000000
mBKPTBCC_BKPTCEN    equ       %10000000

;*** BKPTS - Breakpoint Status Register
BKPTS               equ       $00001839           ;*** BKPTS - Breakpoint Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
BKPTS_CF            equ       0                   ; Comparator C Match Bit
BKPTS_BF            equ       1                   ; Comparator B Match Bit
BKPTS_AF            equ       2                   ; Comparator A Match Bit
; bit position masks
mBKPTS_CF           equ       %00000001
mBKPTS_BF           equ       %00000010
mBKPTS_AF           equ       %00000100

;*** ICSC1 - ICS Control Register 1
ICSC1               equ       $0000183C           ;*** ICSC1 - ICS Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN      equ       0                   ; Internal Reference Stop Enable
ICSC1_IRCLKEN       equ       1                   ; Internal Reference Clock Enable
ICSC1_IREFS         equ       2                   ; Internal Reference Select
ICSC1_RDIV0         equ       3                   ; Reference Divider, bit 0
ICSC1_RDIV1         equ       4                   ; Reference Divider, bit 1
ICSC1_RDIV2         equ       5                   ; Reference Divider, bit 2
ICSC1_CLKS0         equ       6                   ; Clock Source Select, bit 0
ICSC1_CLKS1         equ       7                   ; Clock Source Select, bit 1
; bit position masks
mICSC1_IREFSTEN     equ       %00000001
mICSC1_IRCLKEN      equ       %00000010
mICSC1_IREFS        equ       %00000100
mICSC1_RDIV0        equ       %00001000
mICSC1_RDIV1        equ       %00010000
mICSC1_RDIV2        equ       %00100000
mICSC1_CLKS0        equ       %01000000
mICSC1_CLKS1        equ       %10000000

;*** ICSC2 - ICS Control Register 2
ICSC2               equ       $0000183D           ;*** ICSC2 - ICS Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_EREFSTEN      equ       0                   ; External Reference Stop Enable
ICSC2_ERCLKEN       equ       1                   ; External Reference Enable
ICSC2_EREFS         equ       2                   ; External Reference Select
ICSC2_LP            equ       3                   ; Low Power Select
ICSC2_HGO           equ       4                   ; High Gain Oscillator Select
ICSC2_RANGE         equ       5                   ; Frequency Range Select
ICSC2_BDIV0         equ       6                   ; Bus Frequency Divider, bit 0
ICSC2_BDIV1         equ       7                   ; Bus Frequency Divider, bit 1
; bit position masks
mICSC2_EREFSTEN     equ       %00000001
mICSC2_ERCLKEN      equ       %00000010
mICSC2_EREFS        equ       %00000100
mICSC2_LP           equ       %00001000
mICSC2_HGO          equ       %00010000
mICSC2_RANGE        equ       %00100000
mICSC2_BDIV0        equ       %01000000
mICSC2_BDIV1        equ       %10000000

;*** ICSTRM - ICS Trim Register
ICSTRM              equ       $0000183E           ;*** ICSTRM - ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM0        equ       0                   ; ICS Trim Setting, bit 0
ICSTRM_TRIM1        equ       1                   ; ICS Trim Setting, bit 1
ICSTRM_TRIM2        equ       2                   ; ICS Trim Setting, bit 2
ICSTRM_TRIM3        equ       3                   ; ICS Trim Setting, bit 3
ICSTRM_TRIM4        equ       4                   ; ICS Trim Setting, bit 4
ICSTRM_TRIM5        equ       5                   ; ICS Trim Setting, bit 5
ICSTRM_TRIM6        equ       6                   ; ICS Trim Setting, bit 6
ICSTRM_TRIM7        equ       7                   ; ICS Trim Setting, bit 7
; bit position masks
mICSTRM_TRIM0       equ       %00000001
mICSTRM_TRIM1       equ       %00000010
mICSTRM_TRIM2       equ       %00000100
mICSTRM_TRIM3       equ       %00001000
mICSTRM_TRIM4       equ       %00010000
mICSTRM_TRIM5       equ       %00100000
mICSTRM_TRIM6       equ       %01000000
mICSTRM_TRIM7       equ       %10000000

;*** ICSSC - ICS Status and Control Register
ICSSC               equ       $0000183F           ;*** ICSSC - ICS Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM         equ       0                   ; ICS Fine Trim
ICSSC_OSCINIT       equ       1                   ; OSC Initialization
ICSSC_CLKST0        equ       2                   ; Clock Mode Status, bit 0
ICSSC_CLKST1        equ       3                   ; Clock Mode Status, bit 1
ICSSC_IREFST        equ       4                   ; Internal Reference Status
ICSSC_DMX32         equ       5                   ; DCO Maximum frequency with 32.768 kHz reference
ICSSC_DRST_DRS0     equ       6                   ; DCO Range Status/Range Select, bit 0
ICSSC_DRST_DRS1     equ       7                   ; DCO Range Status/Range Select, bit 1
; bit position masks
mICSSC_FTRIM        equ       %00000001
mICSSC_OSCINIT      equ       %00000010
mICSSC_CLKST0       equ       %00000100
mICSSC_CLKST1       equ       %00001000
mICSSC_IREFST       equ       %00010000
mICSSC_DMX32        equ       %00100000
mICSSC_DRST_DRS0    equ       %01000000
mICSSC_DRST_DRS1    equ       %10000000

;*** ADC0CV1 - Compare Value 1 Register
ADC0CV1             equ       $00001840           ;*** ADC0CV1 - Compare Value 1 Register

;*** ADC0CV1H - Compare Value 1 High Register
ADC0CV1H            equ       $00001840           ;*** ADC0CV1H - Compare Value 1 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CV1H_CV18       equ       0                   ; Compare Function Value 8
ADC0CV1H_CV19       equ       1                   ; Compare Function Value 9
ADC0CV1H_CV110      equ       2                   ; Compare Function Value 10
ADC0CV1H_CV111      equ       3                   ; Compare Function Value 11
ADC0CV1H_CV112      equ       4                   ; Compare Function Value 12
ADC0CV1H_CV113      equ       5                   ; Compare Function Value 13
ADC0CV1H_CV114      equ       6                   ; Compare Function Value 14
ADC0CV1H_CV115      equ       7                   ; Compare Function Value 15
; bit position masks
mADC0CV1H_CV18      equ       %00000001
mADC0CV1H_CV19      equ       %00000010
mADC0CV1H_CV110     equ       %00000100
mADC0CV1H_CV111     equ       %00001000
mADC0CV1H_CV112     equ       %00010000
mADC0CV1H_CV113     equ       %00100000
mADC0CV1H_CV114     equ       %01000000
mADC0CV1H_CV115     equ       %10000000

;*** ADC0CV1L - Compare Value 1 Low Register
ADC0CV1L            equ       $00001841           ;*** ADC0CV1L - Compare Value 1 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CV1L_CV10       equ       0                   ; Compare Function Value 0
ADC0CV1L_CV11       equ       1                   ; Compare Function Value 1
ADC0CV1L_CV12       equ       2                   ; Compare Function Value 2
ADC0CV1L_CV13       equ       3                   ; Compare Function Value 3
ADC0CV1L_CV14       equ       4                   ; Compare Function Value 4
ADC0CV1L_CV15       equ       5                   ; Compare Function Value 5
ADC0CV1L_CV16       equ       6                   ; Compare Function Value 6
ADC0CV1L_CV17       equ       7                   ; Compare Function Value 7
; bit position masks
mADC0CV1L_CV10      equ       %00000001
mADC0CV1L_CV11      equ       %00000010
mADC0CV1L_CV12      equ       %00000100
mADC0CV1L_CV13      equ       %00001000
mADC0CV1L_CV14      equ       %00010000
mADC0CV1L_CV15      equ       %00100000
mADC0CV1L_CV16      equ       %01000000
mADC0CV1L_CV17      equ       %10000000

;*** ADC0CV2 - Compare Value 2 Register
ADC0CV2             equ       $00001842           ;*** ADC0CV2 - Compare Value 2 Register

;*** ADC0CV2H - Compare Value 2 High Register
ADC0CV2H            equ       $00001842           ;*** ADC0CV2H - Compare Value 2 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CV2H_CV28       equ       0                   ; Compare Function Value 8
ADC0CV2H_CV29       equ       1                   ; Compare Function Value 9
ADC0CV2H_CV210      equ       2                   ; Compare Function Value 10
ADC0CV2H_CV211      equ       3                   ; Compare Function Value 11
ADC0CV2H_CV212      equ       4                   ; Compare Function Value 12
ADC0CV2H_CV213      equ       5                   ; Compare Function Value 13
ADC0CV2H_CV214      equ       6                   ; Compare Function Value 14
ADC0CV2H_CV215      equ       7                   ; Compare Function Value 15
; bit position masks
mADC0CV2H_CV28      equ       %00000001
mADC0CV2H_CV29      equ       %00000010
mADC0CV2H_CV210     equ       %00000100
mADC0CV2H_CV211     equ       %00001000
mADC0CV2H_CV212     equ       %00010000
mADC0CV2H_CV213     equ       %00100000
mADC0CV2H_CV214     equ       %01000000
mADC0CV2H_CV215     equ       %10000000

;*** ADC0CV2L - Compare Value 2 Low Register
ADC0CV2L            equ       $00001843           ;*** ADC0CV2L - Compare Value 2 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CV2L_CV20       equ       0                   ; Compare Function Value 0
ADC0CV2L_CV21       equ       1                   ; Compare Function Value 1
ADC0CV2L_CV22       equ       2                   ; Compare Function Value 2
ADC0CV2L_CV23       equ       3                   ; Compare Function Value 3
ADC0CV2L_CV24       equ       4                   ; Compare Function Value 4
ADC0CV2L_CV25       equ       5                   ; Compare Function Value 5
ADC0CV2L_CV26       equ       6                   ; Compare Function Value 6
ADC0CV2L_CV27       equ       7                   ; Compare Function Value 7
; bit position masks
mADC0CV2L_CV20      equ       %00000001
mADC0CV2L_CV21      equ       %00000010
mADC0CV2L_CV22      equ       %00000100
mADC0CV2L_CV23      equ       %00001000
mADC0CV2L_CV24      equ       %00010000
mADC0CV2L_CV25      equ       %00100000
mADC0CV2L_CV26      equ       %01000000
mADC0CV2L_CV27      equ       %10000000

;*** ADC0SC2 - Status and Control Register 2
ADC0SC2             equ       $00001844           ;*** ADC0SC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0SC2_REFSEL0     equ       0                   ; Voltage Reference Selection, bit 0
ADC0SC2_REFSEL1     equ       1                   ; Voltage Reference Selection, bit 1
ADC0SC2_ACREN       equ       3                   ; Compare Function Range Enable
ADC0SC2_ACFGT       equ       4                   ; Compare Function Greater Than Enable
ADC0SC2_ACFE        equ       5                   ; Compare Function Enable - ACFE is used to enable the compare function
ADC0SC2_ADTRG       equ       6                   ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADC0SC2_ADACT       equ       7                   ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a
; bit position masks
mADC0SC2_REFSEL0    equ       %00000001
mADC0SC2_REFSEL1    equ       %00000010
mADC0SC2_ACREN      equ       %00001000
mADC0SC2_ACFGT      equ       %00010000
mADC0SC2_ACFE       equ       %00100000
mADC0SC2_ADTRG      equ       %01000000
mADC0SC2_ADACT      equ       %10000000

;*** ADC0SC3 - Status and Control Register 3
ADC0SC3             equ       $00001845           ;*** ADC0SC3 - Status and Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0SC3_AVGS0       equ       0                   ; Hardware Average select, bit 0
ADC0SC3_AVGS1       equ       1                   ; Hardware Average select, bit 1
ADC0SC3_AVGE        equ       2                   ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADC0SC3_ADCO        equ       3                   ; Continuous Conversion Enable - ADCO enables continuous conversions
ADC0SC3_CALF        equ       6                   ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC0SC3_CAL         equ       7                   ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADC0SC3_AVGS0      equ       %00000001
mADC0SC3_AVGS1      equ       %00000010
mADC0SC3_AVGE       equ       %00000100
mADC0SC3_ADCO       equ       %00001000
mADC0SC3_CALF       equ       %01000000
mADC0SC3_CAL        equ       %10000000

;*** ADC0OFS - Offset Correction Register
ADC0OFS             equ       $00001846           ;*** ADC0OFS - Offset Correction Register

;*** ADC0OFSH - Offset Correction High Register
ADC0OFSH            equ       $00001846           ;*** ADC0OFSH - Offset Correction High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0OFSH_OFS8       equ       0                   ; Offset error correction value bit 8
ADC0OFSH_OFS9       equ       1                   ; Offset error correction value bit 9
ADC0OFSH_OFS10      equ       2                   ; Offset error correction value bit 10
ADC0OFSH_OFS11      equ       3                   ; Offset error correction value bit 11
ADC0OFSH_OFS12      equ       4                   ; Offset error correction value bit 12
ADC0OFSH_OFS13      equ       5                   ; Offset error correction value bit 13
ADC0OFSH_OFS14      equ       6                   ; Offset error correction value bit 14
ADC0OFSH_OFS15      equ       7                   ; Offset error correction value bit 15
; bit position masks
mADC0OFSH_OFS8      equ       %00000001
mADC0OFSH_OFS9      equ       %00000010
mADC0OFSH_OFS10     equ       %00000100
mADC0OFSH_OFS11     equ       %00001000
mADC0OFSH_OFS12     equ       %00010000
mADC0OFSH_OFS13     equ       %00100000
mADC0OFSH_OFS14     equ       %01000000
mADC0OFSH_OFS15     equ       %10000000

;*** ADC0OFSL - Offset Correction Low Register
ADC0OFSL            equ       $00001847           ;*** ADC0OFSL - Offset Correction Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0OFSL_OFS0       equ       0                   ; Offset error correction value bit 0
ADC0OFSL_OFS1       equ       1                   ; Offset error correction value bit 1
ADC0OFSL_OFS2       equ       2                   ; Offset error correction value bit 2
ADC0OFSL_OFS3       equ       3                   ; Offset error correction value bit 3
ADC0OFSL_OFS4       equ       4                   ; Offset error correction value bit 4
ADC0OFSL_OFS5       equ       5                   ; Offset error correction value bit 5
ADC0OFSL_OFS6       equ       6                   ; Offset error correction value bit 6
ADC0OFSL_OFS7       equ       7                   ; Offset error correction value bit 7
; bit position masks
mADC0OFSL_OFS0      equ       %00000001
mADC0OFSL_OFS1      equ       %00000010
mADC0OFSL_OFS2      equ       %00000100
mADC0OFSL_OFS3      equ       %00001000
mADC0OFSL_OFS4      equ       %00010000
mADC0OFSL_OFS5      equ       %00100000
mADC0OFSL_OFS6      equ       %01000000
mADC0OFSL_OFS7      equ       %10000000

;*** ADC0PG - Plus-Side Gain Register
ADC0PG              equ       $00001848           ;*** ADC0PG - Plus-Side Gain Register

;*** ADC0PGH - Plus-Side Gain High Register
ADC0PGH             equ       $00001848           ;*** ADC0PGH - Plus-Side Gain High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0PGH_PG8         equ       0                   ; Gain error correction for the plus-side input value bit 8
ADC0PGH_PG9         equ       1                   ; Gain error correction for the plus-side input value bit 9
ADC0PGH_PG10        equ       2                   ; Gain error correction for the plus-side input value bit 10
ADC0PGH_PG11        equ       3                   ; Gain error correction for the plus-side input value bit 11
ADC0PGH_PG12        equ       4                   ; Gain error correction for the plus-side input value bit 12
ADC0PGH_PG13        equ       5                   ; Gain error correction for the plus-side input value bit 13
ADC0PGH_PG14        equ       6                   ; Gain error correction for the plus-side input value bit 14
ADC0PGH_PG15        equ       7                   ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC0PGH_PG8        equ       %00000001
mADC0PGH_PG9        equ       %00000010
mADC0PGH_PG10       equ       %00000100
mADC0PGH_PG11       equ       %00001000
mADC0PGH_PG12       equ       %00010000
mADC0PGH_PG13       equ       %00100000
mADC0PGH_PG14       equ       %01000000
mADC0PGH_PG15       equ       %10000000

;*** ADC0PGL - Plus-Side Gain Low Register
ADC0PGL             equ       $00001849           ;*** ADC0PGL - Plus-Side Gain Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0PGL_PG0         equ       0                   ; Gain error correction for the plus-side input value bit 0
ADC0PGL_PG1         equ       1                   ; Gain error correction for the plus-side input value bit 1
ADC0PGL_PG2         equ       2                   ; Gain error correction for the plus-side input value bit 2
ADC0PGL_PG3         equ       3                   ; Gain error correction for the plus-side input value bit 3
ADC0PGL_PG4         equ       4                   ; Gain error correction for the plus-side input value bit 4
ADC0PGL_PG5         equ       5                   ; Gain error correction for the plus-side input value bit 5
ADC0PGL_PG6         equ       6                   ; Gain error correction for the plus-side input value bit 6
ADC0PGL_PG7         equ       7                   ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADC0PGL_PG0        equ       %00000001
mADC0PGL_PG1        equ       %00000010
mADC0PGL_PG2        equ       %00000100
mADC0PGL_PG3        equ       %00001000
mADC0PGL_PG4        equ       %00010000
mADC0PGL_PG5        equ       %00100000
mADC0PGL_PG6        equ       %01000000
mADC0PGL_PG7        equ       %10000000

;*** ADC0MG - Minus-Side Gain Register
ADC0MG              equ       $0000184A           ;*** ADC0MG - Minus-Side Gain Register

;*** ADC0MGH - Minus-Side Gain High Register
ADC0MGH             equ       $0000184A           ;*** ADC0MGH - Minus-Side Gain High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0MGH_MG8         equ       0                   ; Gain error correction for the minus-side input value bit 8
ADC0MGH_MG9         equ       1                   ; Gain error correction for the minus-side input value bit 9
ADC0MGH_MG10        equ       2                   ; Gain error correction for the minus-side input value bit 10
ADC0MGH_MG11        equ       3                   ; Gain error correction for the minus-side input value bit 11
ADC0MGH_MG12        equ       4                   ; Gain error correction for the minus-side input value bit 12
ADC0MGH_MG13        equ       5                   ; Gain error correction for the minus-side input value bit 13
ADC0MGH_MG14        equ       6                   ; Gain error correction for the minus-side input value bit 14
ADC0MGH_MG15        equ       7                   ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC0MGH_MG8        equ       %00000001
mADC0MGH_MG9        equ       %00000010
mADC0MGH_MG10       equ       %00000100
mADC0MGH_MG11       equ       %00001000
mADC0MGH_MG12       equ       %00010000
mADC0MGH_MG13       equ       %00100000
mADC0MGH_MG14       equ       %01000000
mADC0MGH_MG15       equ       %10000000

;*** ADC0MGL - Minus-Side Gain Low Register
ADC0MGL             equ       $0000184B           ;*** ADC0MGL - Minus-Side Gain Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0MGL_MG0         equ       0                   ; Gain error correction for the minus-side input value bit 0
ADC0MGL_MG1         equ       1                   ; Gain error correction for the minus-side input value bit 1
ADC0MGL_MG2         equ       2                   ; Gain error correction for the minus-side input value bit 2
ADC0MGL_MG3         equ       3                   ; Gain error correction for the minus-side input value bit 3
ADC0MGL_MG4         equ       4                   ; Gain error correction for the minus-side input value bit 4
ADC0MGL_MG5         equ       5                   ; Gain error correction for the minus-side input value bit 5
ADC0MGL_MG6         equ       6                   ; Gain error correction for the minus-side input value bit 6
ADC0MGL_MG7         equ       7                   ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADC0MGL_MG0        equ       %00000001
mADC0MGL_MG1        equ       %00000010
mADC0MGL_MG2        equ       %00000100
mADC0MGL_MG3        equ       %00001000
mADC0MGL_MG4        equ       %00010000
mADC0MGL_MG5        equ       %00100000
mADC0MGL_MG6        equ       %01000000
mADC0MGL_MG7        equ       %10000000

;*** ADC0CLPD - Plus-Side General Calibration Value D Register
ADC0CLPD            equ       $0000184C           ;*** ADC0CLPD - Plus-Side General Calibration Value D Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLPD_CLPD0      equ       0                   ; Plus-Side General Calibration Value D bit 0
ADC0CLPD_CLPD1      equ       1                   ; Plus-Side General Calibration Value D bit 1
ADC0CLPD_CLPD2      equ       2                   ; Plus-Side General Calibration Value D bit 2
ADC0CLPD_CLPD3      equ       3                   ; Plus-Side General Calibration Value D bit 3
ADC0CLPD_CLPD4      equ       4                   ; Plus-Side General Calibration Value D bit 4
ADC0CLPD_CLPD5      equ       5                   ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADC0CLPD_CLPD0     equ       %00000001
mADC0CLPD_CLPD1     equ       %00000010
mADC0CLPD_CLPD2     equ       %00000100
mADC0CLPD_CLPD3     equ       %00001000
mADC0CLPD_CLPD4     equ       %00010000
mADC0CLPD_CLPD5     equ       %00100000

;*** ADC0CLPS - Plus-Side General Calibration Value S Register
ADC0CLPS            equ       $0000184D           ;*** ADC0CLPS - Plus-Side General Calibration Value S Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLPS_CLPS0      equ       0                   ; Plus-Side General Calibration Value S bit 0
ADC0CLPS_CLPS1      equ       1                   ; Plus-Side General Calibration Value S bit 1
ADC0CLPS_CLPS2      equ       2                   ; Plus-Side General Calibration Value S bit 2
ADC0CLPS_CLPS3      equ       3                   ; Plus-Side General Calibration Value S bit 3
ADC0CLPS_CLPS4      equ       4                   ; Plus-Side General Calibration Value S bit 4
ADC0CLPS_CLPS5      equ       5                   ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADC0CLPS_CLPS0     equ       %00000001
mADC0CLPS_CLPS1     equ       %00000010
mADC0CLPS_CLPS2     equ       %00000100
mADC0CLPS_CLPS3     equ       %00001000
mADC0CLPS_CLPS4     equ       %00010000
mADC0CLPS_CLPS5     equ       %00100000

;*** ADC0CLP4 - Plus-Side General Calibration Value 4 Register
ADC0CLP4            equ       $0000184E           ;*** ADC0CLP4 - Plus-Side General Calibration Value 4 Register

;*** ADC0CLP4H - Plus-Side General Calibration Value 4 High Register
ADC0CLP4H           equ       $0000184E           ;*** ADC0CLP4H - Plus-Side General Calibration Value 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP4H_CLP48     equ       0                   ; Plus-Side General Calibration Value 4 bit 8
ADC0CLP4H_CLP49     equ       1                   ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC0CLP4H_CLP48    equ       %00000001
mADC0CLP4H_CLP49    equ       %00000010

;*** ADC0CLP4L - Plus-Side General Calibration Value 4 Low Register
ADC0CLP4L           equ       $0000184F           ;*** ADC0CLP4L - Plus-Side General Calibration Value 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP4L_CLP40     equ       0                   ; Plus-Side General Calibration Value 4 bit 0
ADC0CLP4L_CLP41     equ       1                   ; Plus-Side General Calibration Value 4 bit 1
ADC0CLP4L_CLP42     equ       2                   ; Plus-Side General Calibration Value 4 bit 2
ADC0CLP4L_CLP43     equ       3                   ; Plus-Side General Calibration Value 4 bit 3
ADC0CLP4L_CLP44     equ       4                   ; Plus-Side General Calibration Value 4 bit 4
ADC0CLP4L_CLP45     equ       5                   ; Plus-Side General Calibration Value 4 bit 5
ADC0CLP4L_CLP46     equ       6                   ; Plus-Side General Calibration Value 4 bit 6
ADC0CLP4L_CLP47     equ       7                   ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADC0CLP4L_CLP40    equ       %00000001
mADC0CLP4L_CLP41    equ       %00000010
mADC0CLP4L_CLP42    equ       %00000100
mADC0CLP4L_CLP43    equ       %00001000
mADC0CLP4L_CLP44    equ       %00010000
mADC0CLP4L_CLP45    equ       %00100000
mADC0CLP4L_CLP46    equ       %01000000
mADC0CLP4L_CLP47    equ       %10000000

;*** ADC0CLP3 - Plus-Side General Calibration Value 3 Register
ADC0CLP3            equ       $00001850           ;*** ADC0CLP3 - Plus-Side General Calibration Value 3 Register

;*** ADC0CLP3H - Plus-Side General Calibration Value 3 High Register
ADC0CLP3H           equ       $00001850           ;*** ADC0CLP3H - Plus-Side General Calibration Value 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP3H_CLP38     equ       0                   ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADC0CLP3H_CLP38    equ       %00000001

;*** ADC0CLP3L - Plus-Side General Calibration Value 3 Low Register
ADC0CLP3L           equ       $00001851           ;*** ADC0CLP3L - Plus-Side General Calibration Value 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP3L_CLP30     equ       0                   ; Plus-Side General Calibration Value 3 bit 0
ADC0CLP3L_CLP31     equ       1                   ; Plus-Side General Calibration Value 3 bit 1
ADC0CLP3L_CLP32     equ       2                   ; Plus-Side General Calibration Value 3 bit 2
ADC0CLP3L_CLP33     equ       3                   ; Plus-Side General Calibration Value 3 bit 3
ADC0CLP3L_CLP34     equ       4                   ; Plus-Side General Calibration Value 3 bit 4
ADC0CLP3L_CLP35     equ       5                   ; Plus-Side General Calibration Value 3 bit 5
ADC0CLP3L_CLP36     equ       6                   ; Plus-Side General Calibration Value 3 bit 6
ADC0CLP3L_CLP37     equ       7                   ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADC0CLP3L_CLP30    equ       %00000001
mADC0CLP3L_CLP31    equ       %00000010
mADC0CLP3L_CLP32    equ       %00000100
mADC0CLP3L_CLP33    equ       %00001000
mADC0CLP3L_CLP34    equ       %00010000
mADC0CLP3L_CLP35    equ       %00100000
mADC0CLP3L_CLP36    equ       %01000000
mADC0CLP3L_CLP37    equ       %10000000

;*** ADC0CLP2 - Plus-Side General Calibration Value 2 Register
ADC0CLP2            equ       $00001852           ;*** ADC0CLP2 - Plus-Side General Calibration Value 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP2_CLP20      equ       0                   ; Plus-Side General Calibration Value 2 bit 0
ADC0CLP2_CLP21      equ       1                   ; Plus-Side General Calibration Value 2 bit 1
ADC0CLP2_CLP22      equ       2                   ; Plus-Side General Calibration Value 2 bit 2
ADC0CLP2_CLP23      equ       3                   ; Plus-Side General Calibration Value 2 bit 3
ADC0CLP2_CLP24      equ       4                   ; Plus-Side General Calibration Value 2 bit 4
ADC0CLP2_CLP25      equ       5                   ; Plus-Side General Calibration Value 2 bit 5
ADC0CLP2_CLP26      equ       6                   ; Plus-Side General Calibration Value 2 bit 6
ADC0CLP2_CLP27      equ       7                   ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADC0CLP2_CLP20     equ       %00000001
mADC0CLP2_CLP21     equ       %00000010
mADC0CLP2_CLP22     equ       %00000100
mADC0CLP2_CLP23     equ       %00001000
mADC0CLP2_CLP24     equ       %00010000
mADC0CLP2_CLP25     equ       %00100000
mADC0CLP2_CLP26     equ       %01000000
mADC0CLP2_CLP27     equ       %10000000

;*** ADC0CLP1 - Plus-Side General Calibration Value 1 Register
ADC0CLP1            equ       $00001853           ;*** ADC0CLP1 - Plus-Side General Calibration Value 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP1_CLP10      equ       0                   ; Plus-Side General Calibration Value 1 bit 0
ADC0CLP1_CLP11      equ       1                   ; Plus-Side General Calibration Value 1 bit 1
ADC0CLP1_CLP12      equ       2                   ; Plus-Side General Calibration Value 1 bit 2
ADC0CLP1_CLP13      equ       3                   ; Plus-Side General Calibration Value 1 bit 3
ADC0CLP1_CLP14      equ       4                   ; Plus-Side General Calibration Value 1 bit 4
ADC0CLP1_CLP15      equ       5                   ; Plus-Side General Calibration Value 1 bit 5
ADC0CLP1_CLP16      equ       6                   ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADC0CLP1_CLP10     equ       %00000001
mADC0CLP1_CLP11     equ       %00000010
mADC0CLP1_CLP12     equ       %00000100
mADC0CLP1_CLP13     equ       %00001000
mADC0CLP1_CLP14     equ       %00010000
mADC0CLP1_CLP15     equ       %00100000
mADC0CLP1_CLP16     equ       %01000000

;*** ADC0CLP0 - Plus-Side General Calibration Value 0 Register
ADC0CLP0            equ       $00001854           ;*** ADC0CLP0 - Plus-Side General Calibration Value 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLP0_CLP00      equ       0                   ; Plus-Side General Calibration Value 0 bit 0
ADC0CLP0_CLP01      equ       1                   ; Plus-Side General Calibration Value 0 bit 1
ADC0CLP0_CLP02      equ       2                   ; Plus-Side General Calibration Value 0 bit 2
ADC0CLP0_CLP03      equ       3                   ; Plus-Side General Calibration Value 0 bit 3
ADC0CLP0_CLP04      equ       4                   ; Plus-Side General Calibration Value 0 bit 4
ADC0CLP0_CLP05      equ       5                   ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADC0CLP0_CLP00     equ       %00000001
mADC0CLP0_CLP01     equ       %00000010
mADC0CLP0_CLP02     equ       %00000100
mADC0CLP0_CLP03     equ       %00001000
mADC0CLP0_CLP04     equ       %00010000
mADC0CLP0_CLP05     equ       %00100000

;*** ADC0CLMD - Minus-Side General Calibration Value D Register
ADC0CLMD            equ       $00001856           ;*** ADC0CLMD - Minus-Side General Calibration Value D Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLMD_CLMD0      equ       0                   ; Minus-Side General Calibration Value D bit 0
ADC0CLMD_CLMD1      equ       1                   ; Minus-Side General Calibration Value D bit 1
ADC0CLMD_CLMD2      equ       2                   ; Minus-Side General Calibration Value D bit 2
ADC0CLMD_CLMD3      equ       3                   ; Minus-Side General Calibration Value D bit 3
ADC0CLMD_CLMD4      equ       4                   ; Minus-Side General Calibration Value D bit 4
ADC0CLMD_CLMD5      equ       5                   ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADC0CLMD_CLMD0     equ       %00000001
mADC0CLMD_CLMD1     equ       %00000010
mADC0CLMD_CLMD2     equ       %00000100
mADC0CLMD_CLMD3     equ       %00001000
mADC0CLMD_CLMD4     equ       %00010000
mADC0CLMD_CLMD5     equ       %00100000

;*** ADC0CLMS - Minus-Side General Calibration Value S Register
ADC0CLMS            equ       $00001857           ;*** ADC0CLMS - Minus-Side General Calibration Value S Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLMS_CLMS0      equ       0                   ; Minus-Side General Calibration Value S bit 0
ADC0CLMS_CLMS1      equ       1                   ; Minus-Side General Calibration Value S bit 1
ADC0CLMS_CLMS2      equ       2                   ; Minus-Side General Calibration Value S bit 2
ADC0CLMS_CLMS3      equ       3                   ; Minus-Side General Calibration Value S bit 3
ADC0CLMS_CLMS4      equ       4                   ; Minus-Side General Calibration Value S bit 4
ADC0CLMS_CLMS5      equ       5                   ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADC0CLMS_CLMS0     equ       %00000001
mADC0CLMS_CLMS1     equ       %00000010
mADC0CLMS_CLMS2     equ       %00000100
mADC0CLMS_CLMS3     equ       %00001000
mADC0CLMS_CLMS4     equ       %00010000
mADC0CLMS_CLMS5     equ       %00100000

;*** ADC0CLM4 - Minus-Side General Calibration Value 4 Register
ADC0CLM4            equ       $00001858           ;*** ADC0CLM4 - Minus-Side General Calibration Value 4 Register

;*** ADC0CLM4H - Minus-Side General Calibration Value 4 High Register
ADC0CLM4H           equ       $00001858           ;*** ADC0CLM4H - Minus-Side General Calibration Value 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM4H_CLM48     equ       0                   ; Minus-Side General Calibration Value 4 bit 8
ADC0CLM4H_CLM49     equ       1                   ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC0CLM4H_CLM48    equ       %00000001
mADC0CLM4H_CLM49    equ       %00000010

;*** ADC0CLM4L - Minus-Side General Calibration Value 4 Low Register
ADC0CLM4L           equ       $00001859           ;*** ADC0CLM4L - Minus-Side General Calibration Value 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM4L_CLM40     equ       0                   ; Minus-Side General Calibration Value 4 bit 0
ADC0CLM4L_CLM41     equ       1                   ; Minus-Side General Calibration Value 4 bit 1
ADC0CLM4L_CLM42     equ       2                   ; Minus-Side General Calibration Value 4 bit 2
ADC0CLM4L_CLM43     equ       3                   ; Minus-Side General Calibration Value 4 bit 3
ADC0CLM4L_CLM44     equ       4                   ; Minus-Side General Calibration Value 4 bit 4
ADC0CLM4L_CLM45     equ       5                   ; Minus-Side General Calibration Value 4 bit 5
ADC0CLM4L_CLM46     equ       6                   ; Minus-Side General Calibration Value 4 bit 6
ADC0CLM4L_CLM47     equ       7                   ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADC0CLM4L_CLM40    equ       %00000001
mADC0CLM4L_CLM41    equ       %00000010
mADC0CLM4L_CLM42    equ       %00000100
mADC0CLM4L_CLM43    equ       %00001000
mADC0CLM4L_CLM44    equ       %00010000
mADC0CLM4L_CLM45    equ       %00100000
mADC0CLM4L_CLM46    equ       %01000000
mADC0CLM4L_CLM47    equ       %10000000

;*** ADC0CLM3 - Minus-Side General Calibration Value 3 Register
ADC0CLM3            equ       $0000185A           ;*** ADC0CLM3 - Minus-Side General Calibration Value 3 Register

;*** ADC0CLM3H - Minus-Side General Calibration Value 3 High Register
ADC0CLM3H           equ       $0000185A           ;*** ADC0CLM3H - Minus-Side General Calibration Value 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM3H_CLM38     equ       0                   ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADC0CLM3H_CLM38    equ       %00000001

;*** ADC0CLM3L - Minus-Side General Calibration Value 3 Low Register
ADC0CLM3L           equ       $0000185B           ;*** ADC0CLM3L - Minus-Side General Calibration Value 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM3L_CLM30     equ       0                   ; Minus-Side General Calibration Value 3 bit 0
ADC0CLM3L_CLM31     equ       1                   ; Minus-Side General Calibration Value 3 bit 1
ADC0CLM3L_CLM32     equ       2                   ; Minus-Side General Calibration Value 3 bit 2
ADC0CLM3L_CLM33     equ       3                   ; Minus-Side General Calibration Value 3 bit 3
ADC0CLM3L_CLM34     equ       4                   ; Minus-Side General Calibration Value 3 bit 4
ADC0CLM3L_CLM35     equ       5                   ; Minus-Side General Calibration Value 3 bit 5
ADC0CLM3L_CLM36     equ       6                   ; Minus-Side General Calibration Value 3 bit 6
ADC0CLM3L_CLM37     equ       7                   ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADC0CLM3L_CLM30    equ       %00000001
mADC0CLM3L_CLM31    equ       %00000010
mADC0CLM3L_CLM32    equ       %00000100
mADC0CLM3L_CLM33    equ       %00001000
mADC0CLM3L_CLM34    equ       %00010000
mADC0CLM3L_CLM35    equ       %00100000
mADC0CLM3L_CLM36    equ       %01000000
mADC0CLM3L_CLM37    equ       %10000000

;*** ADC0CLM2 - Minus-Side General Calibration Value 2 Register
ADC0CLM2            equ       $0000185C           ;*** ADC0CLM2 - Minus-Side General Calibration Value 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM2_CLM20      equ       0                   ; Minus-Side General Calibration Value 2 bit 0
ADC0CLM2_CLM21      equ       1                   ; Minus-Side General Calibration Value 2 bit 1
ADC0CLM2_CLM22      equ       2                   ; Minus-Side General Calibration Value 2 bit 2
ADC0CLM2_CLM23      equ       3                   ; Minus-Side General Calibration Value 2 bit 3
ADC0CLM2_CLM24      equ       4                   ; Minus-Side General Calibration Value 2 bit 4
ADC0CLM2_CLM25      equ       5                   ; Minus-Side General Calibration Value 2 bit 5
ADC0CLM2_CLM26      equ       6                   ; Minus-Side General Calibration Value 2 bit 6
ADC0CLM2_CLM27      equ       7                   ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADC0CLM2_CLM20     equ       %00000001
mADC0CLM2_CLM21     equ       %00000010
mADC0CLM2_CLM22     equ       %00000100
mADC0CLM2_CLM23     equ       %00001000
mADC0CLM2_CLM24     equ       %00010000
mADC0CLM2_CLM25     equ       %00100000
mADC0CLM2_CLM26     equ       %01000000
mADC0CLM2_CLM27     equ       %10000000

;*** ADC0CLM1 - Minus-Side General Calibration Value 1 Register
ADC0CLM1            equ       $0000185D           ;*** ADC0CLM1 - Minus-Side General Calibration Value 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM1_CLM10      equ       0                   ; Minus-Side General Calibration Value 1 bit 0
ADC0CLM1_CLM11      equ       1                   ; Minus-Side General Calibration Value 1 bit 1
ADC0CLM1_CLM12      equ       2                   ; Minus-Side General Calibration Value 1 bit 2
ADC0CLM1_CLM13      equ       3                   ; Minus-Side General Calibration Value 1 bit 3
ADC0CLM1_CLM14      equ       4                   ; Minus-Side General Calibration Value 1 bit 4
ADC0CLM1_CLM15      equ       5                   ; Minus-Side General Calibration Value 1 bit 5
ADC0CLM1_CLM16      equ       6                   ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADC0CLM1_CLM10     equ       %00000001
mADC0CLM1_CLM11     equ       %00000010
mADC0CLM1_CLM12     equ       %00000100
mADC0CLM1_CLM13     equ       %00001000
mADC0CLM1_CLM14     equ       %00010000
mADC0CLM1_CLM15     equ       %00100000
mADC0CLM1_CLM16     equ       %01000000

;*** ADC0CLM0 - Minus-Side General Calibration Value 0 Register
ADC0CLM0            equ       $0000185E           ;*** ADC0CLM0 - Minus-Side General Calibration Value 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC0CLM0_CLM00      equ       0                   ; Minus-Side General Calibration Value 0 bit 0
ADC0CLM0_CLM01      equ       1                   ; Minus-Side General Calibration Value 0 bit 1
ADC0CLM0_CLM02      equ       2                   ; Minus-Side General Calibration Value 0 bit 2
ADC0CLM0_CLM03      equ       3                   ; Minus-Side General Calibration Value 0 bit 3
ADC0CLM0_CLM04      equ       4                   ; Minus-Side General Calibration Value 0 bit 4
ADC0CLM0_CLM05      equ       5                   ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADC0CLM0_CLM00     equ       %00000001
mADC0CLM0_CLM01     equ       %00000010
mADC0CLM0_CLM02     equ       %00000100
mADC0CLM0_CLM03     equ       %00001000
mADC0CLM0_CLM04     equ       %00010000
mADC0CLM0_CLM05     equ       %00100000

;*** CLK_PRSC - CLKOUT Prescaler Register
CLK_PRSC            equ       $00001864           ;*** CLK_PRSC - CLKOUT Prescaler Register

;*** CLK_PRSC_H - CLKOUT Prescaler Register High
CLK_PRSC_H          equ       $00001864           ;*** CLK_PRSC_H - CLKOUT Prescaler Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CLK_PRSC_H_BIT      equ       0                   ; CLKOUT Prescaler match value bits
; bit position masks
mCLK_PRSC_H_BIT     equ       %00000111

;*** CLK_PRSC_L - CLKOUT Prescaler Register Low
CLK_PRSC_L          equ       $00001865           ;*** CLK_PRSC_L - CLKOUT Prescaler Register Low

;*** SCI2BD - SCI2 Baud Rate Register
SCI2BD              equ       $00001868           ;*** SCI2BD - SCI2 Baud Rate Register

;*** SCI2BDH - SCI2 Baud Rate Register High
SCI2BDH             equ       $00001868           ;*** SCI2BDH - SCI2 Baud Rate Register High
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
SCI2BDL             equ       $00001869           ;*** SCI2BDL - SCI2 Baud Rate Register Low
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
SCI2C1              equ       $0000186A           ;*** SCI2C1 - SCI2 Control Register 1
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
SCI2C2              equ       $0000186B           ;*** SCI2C2 - SCI2 Control Register 2
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
SCI2S1              equ       $0000186C           ;*** SCI2S1 - SCI2 Status Register 1
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
SCI2S2              equ       $0000186D           ;*** SCI2S2 - SCI2 Status Register 2
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
SCI2C3              equ       $0000186E           ;*** SCI2C3 - SCI2 Control Register 3
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
SCI2D               equ       $0000186F           ;*** SCI2D - SCI2 Data Register
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

;*** SCI3BD - SCI3 Baud Rate Register
SCI3BD              equ       $00001870           ;*** SCI3BD - SCI3 Baud Rate Register

;*** SCI3BDH - SCI3 Baud Rate Register High
SCI3BDH             equ       $00001870           ;*** SCI3BDH - SCI3 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI3BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI3BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI3BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI3BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
SCI3BDH_RXEDGIE     equ       6                   ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI3BDH_LBKDIE      equ       7                   ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI3BDH_SBR8       equ       %00000001
mSCI3BDH_SBR9       equ       %00000010
mSCI3BDH_SBR10      equ       %00000100
mSCI3BDH_SBR11      equ       %00001000
mSCI3BDH_SBR12      equ       %00010000
mSCI3BDH_RXEDGIE    equ       %01000000
mSCI3BDH_LBKDIE     equ       %10000000

;*** SCI3BDL - SCI3 Baud Rate Register Low
SCI3BDL             equ       $00001871           ;*** SCI3BDL - SCI3 Baud Rate Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3BDL_SBR0        equ       0                   ; Baud Rate Modulo Divisor Bit 0
SCI3BDL_SBR1        equ       1                   ; Baud Rate Modulo Divisor Bit 1
SCI3BDL_SBR2        equ       2                   ; Baud Rate Modulo Divisor Bit 2
SCI3BDL_SBR3        equ       3                   ; Baud Rate Modulo Divisor Bit 3
SCI3BDL_SBR4        equ       4                   ; Baud Rate Modulo Divisor Bit 4
SCI3BDL_SBR5        equ       5                   ; Baud Rate Modulo Divisor Bit 5
SCI3BDL_SBR6        equ       6                   ; Baud Rate Modulo Divisor Bit 6
SCI3BDL_SBR7        equ       7                   ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI3BDL_SBR0       equ       %00000001
mSCI3BDL_SBR1       equ       %00000010
mSCI3BDL_SBR2       equ       %00000100
mSCI3BDL_SBR3       equ       %00001000
mSCI3BDL_SBR4       equ       %00010000
mSCI3BDL_SBR5       equ       %00100000
mSCI3BDL_SBR6       equ       %01000000
mSCI3BDL_SBR7       equ       %10000000

;*** SCI3C1 - SCI3 Control Register 1
SCI3C1              equ       $00001872           ;*** SCI3C1 - SCI3 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3C1_PT           equ       0                   ; Parity Type
SCI3C1_PE           equ       1                   ; Parity Enable
SCI3C1_ILT          equ       2                   ; Idle Line Type Select
SCI3C1_WAKE         equ       3                   ; Receiver Wakeup Method Select
SCI3C1_M            equ       4                   ; 9-Bit or 8-Bit Mode Select
SCI3C1_RSRC         equ       5                   ; Receiver Source Select
SCI3C1_SCISWAI      equ       6                   ; SCI Stops in Wait Mode
SCI3C1_LOOPS        equ       7                   ; Loop Mode Select
; bit position masks
mSCI3C1_PT          equ       %00000001
mSCI3C1_PE          equ       %00000010
mSCI3C1_ILT         equ       %00000100
mSCI3C1_WAKE        equ       %00001000
mSCI3C1_M           equ       %00010000
mSCI3C1_RSRC        equ       %00100000
mSCI3C1_SCISWAI     equ       %01000000
mSCI3C1_LOOPS       equ       %10000000

;*** SCI3C2 - SCI3 Control Register 2
SCI3C2              equ       $00001873           ;*** SCI3C2 - SCI3 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3C2_SBK          equ       0                   ; Send Break
SCI3C2_RWU          equ       1                   ; Receiver Wakeup Control
SCI3C2_RE           equ       2                   ; Receiver Enable
SCI3C2_TE           equ       3                   ; Transmitter Enable
SCI3C2_ILIE         equ       4                   ; Idle Line Interrupt Enable (for IDLE)
SCI3C2_RIE          equ       5                   ; Receiver Interrupt Enable (for RDRF)
SCI3C2_TCIE         equ       6                   ; Transmission Complete Interrupt Enable (for TC)
SCI3C2_TIE          equ       7                   ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI3C2_SBK         equ       %00000001
mSCI3C2_RWU         equ       %00000010
mSCI3C2_RE          equ       %00000100
mSCI3C2_TE          equ       %00001000
mSCI3C2_ILIE        equ       %00010000
mSCI3C2_RIE         equ       %00100000
mSCI3C2_TCIE        equ       %01000000
mSCI3C2_TIE         equ       %10000000

;*** SCI3S1 - SCI3 Status Register 1
SCI3S1              equ       $00001874           ;*** SCI3S1 - SCI3 Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3S1_PF           equ       0                   ; Parity Error Flag
SCI3S1_FE           equ       1                   ; Framing Error Flag
SCI3S1_NF           equ       2                   ; Noise Flag
SCI3S1_OR           equ       3                   ; Receiver Overrun Flag
SCI3S1_IDLE         equ       4                   ; Idle Line Flag
SCI3S1_RDRF         equ       5                   ; Receive Data Register Full Flag
SCI3S1_TC           equ       6                   ; Transmission Complete Flag
SCI3S1_TDRE         equ       7                   ; Transmit Data Register Empty Flag
; bit position masks
mSCI3S1_PF          equ       %00000001
mSCI3S1_FE          equ       %00000010
mSCI3S1_NF          equ       %00000100
mSCI3S1_OR          equ       %00001000
mSCI3S1_IDLE        equ       %00010000
mSCI3S1_RDRF        equ       %00100000
mSCI3S1_TC          equ       %01000000
mSCI3S1_TDRE        equ       %10000000

;*** SCI3S2 - SCI3 Status Register 2
SCI3S2              equ       $00001875           ;*** SCI3S2 - SCI3 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3S2_RAF          equ       0                   ; Receiver Active Flag
SCI3S2_LBKDE        equ       1                   ; LIN Break Detection Enable
SCI3S2_BRK13        equ       2                   ; Break Character Generation Length
SCI3S2_RWUID        equ       3                   ; Receive Wake Up Idle Detect
SCI3S2_RXINV        equ       4                   ; Receive Data Inversion
SCI3S2_RXEDGIF      equ       6                   ; RxD Pin Active Edge Interrupt Flag
SCI3S2_LBKDIF       equ       7                   ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI3S2_RAF         equ       %00000001
mSCI3S2_LBKDE       equ       %00000010
mSCI3S2_BRK13       equ       %00000100
mSCI3S2_RWUID       equ       %00001000
mSCI3S2_RXINV       equ       %00010000
mSCI3S2_RXEDGIF     equ       %01000000
mSCI3S2_LBKDIF      equ       %10000000

;*** SCI3C3 - SCI3 Control Register 3
SCI3C3              equ       $00001876           ;*** SCI3C3 - SCI3 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI3C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI3C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI3C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI3C3_TXINV        equ       4                   ; Transmit Data Inversion
SCI3C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI3C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI3C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI3C3_PEIE        equ       %00000001
mSCI3C3_FEIE        equ       %00000010
mSCI3C3_NEIE        equ       %00000100
mSCI3C3_ORIE        equ       %00001000
mSCI3C3_TXINV       equ       %00010000
mSCI3C3_TXDIR       equ       %00100000
mSCI3C3_T8          equ       %01000000
mSCI3C3_R8          equ       %10000000

;*** SCI3D - SCI3 Data Register
SCI3D               equ       $00001877           ;*** SCI3D - SCI3 Data Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI3D_R0_T0         equ       0                   ; Receive/Transmit Data Bit 0
SCI3D_R1_T1         equ       1                   ; Receive/Transmit Data Bit 1
SCI3D_R2_T2         equ       2                   ; Receive/Transmit Data Bit 2
SCI3D_R3_T3         equ       3                   ; Receive/Transmit Data Bit 3
SCI3D_R4_T4         equ       4                   ; Receive/Transmit Data Bit 4
SCI3D_R5_T5         equ       5                   ; Receive/Transmit Data Bit 5
SCI3D_R6_T6         equ       6                   ; Receive/Transmit Data Bit 6
SCI3D_R7_T7         equ       7                   ; Receive/Transmit Data Bit 7
; bit position masks
mSCI3D_R0_T0        equ       %00000001
mSCI3D_R1_T1        equ       %00000010
mSCI3D_R2_T2        equ       %00000100
mSCI3D_R3_T3        equ       %00001000
mSCI3D_R4_T4        equ       %00010000
mSCI3D_R5_T5        equ       %00100000
mSCI3D_R6_T6        equ       %01000000
mSCI3D_R7_T7        equ       %10000000

;*** LCDC0 - LCD Control Register 0
LCDC0               equ       $00001878           ;*** LCDC0 - LCD Control Register 0
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
LCDC1               equ       $00001879           ;*** LCDC1 - LCD Control Register 1
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
LCDSUPPLY           equ       $0000187A           ;*** LCDSUPPLY - LCD Voltage Supply Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDSUPPLY_VSUPPLY0  equ       0                   ; Voltage Supply Control Bit 0
LCDSUPPLY_VSUPPLY1  equ       1                   ; Voltage Supply Control Bit 1
LCDSUPPLY_BBYPASS   equ       2                   ; Op Amp Control
LCDSUPPLY_LADJ0     equ       4                   ; LCD Module Load Adjust Bit 0
LCDSUPPLY_LADJ1     equ       5                   ; LCD Module Load Adjust Bit 1
LCDSUPPLY_HREFSEL   equ       6                   ; High Reference Select
LCDSUPPLY_CPSEL     equ       7                   ; Charge Pump or Resistor Bias Select
; bit position masks
mLCDSUPPLY_VSUPPLY0 equ       %00000001
mLCDSUPPLY_VSUPPLY1 equ       %00000010
mLCDSUPPLY_BBYPASS  equ       %00000100
mLCDSUPPLY_LADJ0    equ       %00010000
mLCDSUPPLY_LADJ1    equ       %00100000
mLCDSUPPLY_HREFSEL  equ       %01000000
mLCDSUPPLY_CPSEL    equ       %10000000

;*** LCDRVC - LCD Regulated Voltage Control Register
LCDRVC              equ       $0000187B           ;*** LCDRVC - LCD Regulated Voltage Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRVC_RVTRIM0      equ       0                   ; Regulated Voltage Trim Bit 0
LCDRVC_RVTRIM1      equ       1                   ; Regulated Voltage Trim Bit 1
LCDRVC_RVTRIM2      equ       2                   ; Regulated Voltage Trim Bit 2
LCDRVC_RVTRIM3      equ       3                   ; Regulated Voltage Trim Bit 3
LCDRVC_RVEN         equ       7                   ; Regulated Voltage Enable
; bit position masks
mLCDRVC_RVTRIM0     equ       %00000001
mLCDRVC_RVTRIM1     equ       %00000010
mLCDRVC_RVTRIM2     equ       %00000100
mLCDRVC_RVTRIM3     equ       %00001000
mLCDRVC_RVEN        equ       %10000000

;*** LCDBCTL - LCD Blink Control Register
LCDBCTL             equ       $0000187C           ;*** LCDBCTL - LCD Blink Control Register
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
LCDS                equ       $0000187D           ;*** LCDS - LCD Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDS_LCDIF          equ       7                   ; LCD Interrupt Flag
; bit position masks
mLCDS_LCDIF         equ       %10000000

;*** IRTC_YEARMON - RTC Year and Month Counters Register (binary format)
IRTC_YEARMON        equ       $00001880           ;*** IRTC_YEARMON - RTC Year and Month Counters Register (binary format)

;*** IRTC_YEARMON_H - RTC Year and Month Counters Register High(binary format)
IRTC_YEARMON_H      equ       $00001880           ;*** IRTC_YEARMON_H - RTC Year and Month Counters Register High(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_YEARMON_H_YEAR0 equ       0                   ; Year count value bits, bit 0
IRTC_YEARMON_H_YEAR1 equ       1                   ; Year count value bits, bit 1
IRTC_YEARMON_H_YEAR2 equ       2                   ; Year count value bits, bit 2
IRTC_YEARMON_H_YEAR3 equ       3                   ; Year count value bits, bit 3
IRTC_YEARMON_H_YEAR4 equ       4                   ; Year count value bits, bit 4
IRTC_YEARMON_H_YEAR5 equ       5                   ; Year count value bits, bit 5
IRTC_YEARMON_H_YEAR6 equ       6                   ; Year count value bits, bit 6
IRTC_YEARMON_H_YEAR7 equ       7                   ; Year count value bits, bit 7
; bit position masks
mIRTC_YEARMON_H_YEAR0 equ       %00000001
mIRTC_YEARMON_H_YEAR1 equ       %00000010
mIRTC_YEARMON_H_YEAR2 equ       %00000100
mIRTC_YEARMON_H_YEAR3 equ       %00001000
mIRTC_YEARMON_H_YEAR4 equ       %00010000
mIRTC_YEARMON_H_YEAR5 equ       %00100000
mIRTC_YEARMON_H_YEAR6 equ       %01000000
mIRTC_YEARMON_H_YEAR7 equ       %10000000

;*** IRTC_YEARMON_L - RTC Year and Month Counters Register Low(binary format)
IRTC_YEARMON_L      equ       $00001881           ;*** IRTC_YEARMON_L - RTC Year and Month Counters Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_YEARMON_L_MONTH0 equ       0                   ; Month count value bits, bit 0
IRTC_YEARMON_L_MONTH1 equ       1                   ; Month count value bits, bit 1
IRTC_YEARMON_L_MONTH2 equ       2                   ; Month count value bits, bit 2
IRTC_YEARMON_L_MONTH3 equ       3                   ; Month count value bits, bit 3
; bit position masks
mIRTC_YEARMON_L_MONTH0 equ       %00000001
mIRTC_YEARMON_L_MONTH1 equ       %00000010
mIRTC_YEARMON_L_MONTH2 equ       %00000100
mIRTC_YEARMON_L_MONTH3 equ       %00001000

;*** IRTC_DAYS - RTC Days Counter Register (binary format)
IRTC_DAYS           equ       $00001882           ;*** IRTC_DAYS - RTC Days Counter Register (binary format)

;*** IRTC_DAYS_H - RTC Days Counter Register High(binary format)
IRTC_DAYS_H         equ       $00001882           ;*** IRTC_DAYS_H - RTC Days Counter Register High(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DAYS_H_DAY_OF_WEEK0 equ       0                   ; Indicates the current day count, bit 0, bit 0
IRTC_DAYS_H_DAY_OF_WEEK1 equ       1                   ; Indicates the current day count, bit 0, bit 1
IRTC_DAYS_H_DAY_OF_WEEK2 equ       2                   ; Indicates the current day count, bit 0, bit 2
; bit position masks
mIRTC_DAYS_H_DAY_OF_WEEK0 equ       %00000001
mIRTC_DAYS_H_DAY_OF_WEEK1 equ       %00000010
mIRTC_DAYS_H_DAY_OF_WEEK2 equ       %00000100

;*** IRTC_DAYS_L - RTC Days Counter Register Low(binary format)
IRTC_DAYS_L         equ       $00001883           ;*** IRTC_DAYS_L - RTC Days Counter Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DAYS_L_DAYS0   equ       0                   ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 0
IRTC_DAYS_L_DAYS1   equ       1                   ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 1
IRTC_DAYS_L_DAYS2   equ       2                   ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 2
IRTC_DAYS_L_DAYS3   equ       3                   ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 3
IRTC_DAYS_L_DAYS4   equ       4                   ; Day Setting. Indicates the current day count. Valid Count: 1 - 31, bit 4
; bit position masks
mIRTC_DAYS_L_DAYS0  equ       %00000001
mIRTC_DAYS_L_DAYS1  equ       %00000010
mIRTC_DAYS_L_DAYS2  equ       %00000100
mIRTC_DAYS_L_DAYS3  equ       %00001000
mIRTC_DAYS_L_DAYS4  equ       %00010000

;*** IRTC_HOURMIN - RTC Hours and Minutes Counter Register (binary format)
IRTC_HOURMIN        equ       $00001884           ;*** IRTC_HOURMIN - RTC Hours and Minutes Counter Register (binary format)

;*** IRTC_HOURMIN_H - RTC Hours and Minutes Counter Register High(binary format)
IRTC_HOURMIN_H      equ       $00001884           ;*** IRTC_HOURMIN_H - RTC Hours and Minutes Counter Register High(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_HOURMIN_H_HOURS0 equ       0                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17),
IRTC_HOURMIN_H_HOURS1 equ       1                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17),
IRTC_HOURMIN_H_HOURS2 equ       2                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17),
IRTC_HOURMIN_H_HOURS3 equ       3                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17),
IRTC_HOURMIN_H_HOURS4 equ       4                   ; Indicates the current hour. It can be set to any value between 0 and 23 (0x17),
; bit position masks
mIRTC_HOURMIN_H_HOURS0 equ       %00000001
mIRTC_HOURMIN_H_HOURS1 equ       %00000010
mIRTC_HOURMIN_H_HOURS2 equ       %00000100
mIRTC_HOURMIN_H_HOURS3 equ       %00001000
mIRTC_HOURMIN_H_HOURS4 equ       %00010000

;*** IRTC_HOURMIN_L - RTC Hours and Minutes Counter Register Low(binary format)
IRTC_HOURMIN_L      equ       $00001885           ;*** IRTC_HOURMIN_L - RTC Hours and Minutes Counter Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_HOURMIN_L_MINUTES0 equ       0                   ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B),
IRTC_HOURMIN_L_MINUTES1 equ       1                   ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B),
IRTC_HOURMIN_L_MINUTES2 equ       2                   ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B),
IRTC_HOURMIN_L_MINUTES3 equ       3                   ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B),
IRTC_HOURMIN_L_MINUTES4 equ       4                   ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B),
IRTC_HOURMIN_L_MINUTES5 equ       5                   ; Indicates the current minutes. It can be set to any value between 0 and 59 (0x3B),
; bit position masks
mIRTC_HOURMIN_L_MINUTES0 equ       %00000001
mIRTC_HOURMIN_L_MINUTES1 equ       %00000010
mIRTC_HOURMIN_L_MINUTES2 equ       %00000100
mIRTC_HOURMIN_L_MINUTES3 equ       %00001000
mIRTC_HOURMIN_L_MINUTES4 equ       %00010000
mIRTC_HOURMIN_L_MINUTES5 equ       %00100000

;*** IRTC_SECONDS - RTC Seconds Counter Register  (binary format)
IRTC_SECONDS        equ       $00001886           ;*** IRTC_SECONDS - RTC Seconds Counter Register (binary format)

;*** IRTC_SECONDS_H - RTC Seconds Counter Register  High(binary format)
IRTC_SECONDS_H      equ       $00001886           ;*** IRTC_SECONDS_H - RTC Seconds Counter Register High(binary format)

;*** IRTC_SECONDS_L - RTC Seconds Counter Register Low (binary format)
IRTC_SECONDS_L      equ       $00001887           ;*** IRTC_SECONDS_L - RTC Seconds Counter Register Low (binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_SECONDS_L_SECONDS0 equ       0                   ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B),
IRTC_SECONDS_L_SECONDS1 equ       1                   ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B),
IRTC_SECONDS_L_SECONDS2 equ       2                   ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B),
IRTC_SECONDS_L_SECONDS3 equ       3                   ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B),
IRTC_SECONDS_L_SECONDS4 equ       4                   ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B),
IRTC_SECONDS_L_SECONDS5 equ       5                   ; Indicates the current seconds. It can be set to any value between 0 and 59 (0x3B),
; bit position masks
mIRTC_SECONDS_L_SECONDS0 equ       %00000001
mIRTC_SECONDS_L_SECONDS1 equ       %00000010
mIRTC_SECONDS_L_SECONDS2 equ       %00000100
mIRTC_SECONDS_L_SECONDS3 equ       %00001000
mIRTC_SECONDS_L_SECONDS4 equ       %00010000
mIRTC_SECONDS_L_SECONDS5 equ       %00100000

;*** IRTC_ALM_YRMON - RTC Year and Month Alarm Register (binary format)
IRTC_ALM_YRMON      equ       $00001888           ;*** IRTC_ALM_YRMON - RTC Year and Month Alarm Register (binary format)

;*** IRTC_ALM_YRMON_H - RTC Year and Month Alarm Register High(binary format)
IRTC_ALM_YRMON_H    equ       $00001888           ;*** IRTC_ALM_YRMON_H - RTC Year and Month Alarm Register High(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_YRMON_H_ALM_YEAR0 equ       0                   ; Year count value bits, bit 0
IRTC_ALM_YRMON_H_ALM_YEAR1 equ       1                   ; Year count value bits, bit 1
IRTC_ALM_YRMON_H_ALM_YEAR2 equ       2                   ; Year count value bits, bit 2
IRTC_ALM_YRMON_H_ALM_YEAR3 equ       3                   ; Year count value bits, bit 3
IRTC_ALM_YRMON_H_ALM_YEAR4 equ       4                   ; Year count value bits, bit 4
IRTC_ALM_YRMON_H_ALM_YEAR5 equ       5                   ; Year count value bits, bit 5
IRTC_ALM_YRMON_H_ALM_YEAR6 equ       6                   ; Year count value bits, bit 6
IRTC_ALM_YRMON_H_ALM_YEAR7 equ       7                   ; Year count value bits, bit 7
; bit position masks
mIRTC_ALM_YRMON_H_ALM_YEAR0 equ       %00000001
mIRTC_ALM_YRMON_H_ALM_YEAR1 equ       %00000010
mIRTC_ALM_YRMON_H_ALM_YEAR2 equ       %00000100
mIRTC_ALM_YRMON_H_ALM_YEAR3 equ       %00001000
mIRTC_ALM_YRMON_H_ALM_YEAR4 equ       %00010000
mIRTC_ALM_YRMON_H_ALM_YEAR5 equ       %00100000
mIRTC_ALM_YRMON_H_ALM_YEAR6 equ       %01000000
mIRTC_ALM_YRMON_H_ALM_YEAR7 equ       %10000000

;*** IRTC_ALM_YRMON_L - RTC Year and Month Alarm Register Low(binary format)
IRTC_ALM_YRMON_L    equ       $00001889           ;*** IRTC_ALM_YRMON_L - RTC Year and Month Alarm Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_YRMON_L_ALM_MONTH0 equ       0                   ; Month alarm value bits, bit 0
IRTC_ALM_YRMON_L_ALM_MONTH1 equ       1                   ; Month alarm value bits, bit 1
IRTC_ALM_YRMON_L_ALM_MONTH2 equ       2                   ; Month alarm value bits, bit 2
IRTC_ALM_YRMON_L_ALM_MONTH3 equ       3                   ; Month alarm value bits, bit 3
; bit position masks
mIRTC_ALM_YRMON_L_ALM_MONTH0 equ       %00000001
mIRTC_ALM_YRMON_L_ALM_MONTH1 equ       %00000010
mIRTC_ALM_YRMON_L_ALM_MONTH2 equ       %00000100
mIRTC_ALM_YRMON_L_ALM_MONTH3 equ       %00001000

;*** IRTC_ALM_DAYS - RTC Day Alarm Register (binary format)
IRTC_ALM_DAYS       equ       $0000188A           ;*** IRTC_ALM_DAYS - RTC Day Alarm Register (binary format)

;*** IRTC_ALM_DAYS_H - RTC Day Alarm Register High(binary format)
IRTC_ALM_DAYS_H     equ       $0000188A           ;*** IRTC_ALM_DAYS_H - RTC Day Alarm Register High(binary format)

;*** IRTC_ALM_DAYS_L - RTC Day Alarm Register Low(binary format)
IRTC_ALM_DAYS_L     equ       $0000188B           ;*** IRTC_ALM_DAYS_L - RTC Day Alarm Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_DAYS_L_ALM_DAYS0 equ       0                   ; Indicates the current day setting of the alarm, bit 0
IRTC_ALM_DAYS_L_ALM_DAYS1 equ       1                   ; Indicates the current day setting of the alarm, bit 1
IRTC_ALM_DAYS_L_ALM_DAYS2 equ       2                   ; Indicates the current day setting of the alarm, bit 2
IRTC_ALM_DAYS_L_ALM_DAYS3 equ       3                   ; Indicates the current day setting of the alarm, bit 3
IRTC_ALM_DAYS_L_ALM_DAYS4 equ       4                   ; Indicates the current day setting of the alarm, bit 4
; bit position masks
mIRTC_ALM_DAYS_L_ALM_DAYS0 equ       %00000001
mIRTC_ALM_DAYS_L_ALM_DAYS1 equ       %00000010
mIRTC_ALM_DAYS_L_ALM_DAYS2 equ       %00000100
mIRTC_ALM_DAYS_L_ALM_DAYS3 equ       %00001000
mIRTC_ALM_DAYS_L_ALM_DAYS4 equ       %00010000

;*** IRTC_ALM_HM - RTC Hours and Minutes Alarm Register (binary format)
IRTC_ALM_HM         equ       $0000188C           ;*** IRTC_ALM_HM - RTC Hours and Minutes Alarm Register (binary format)

;*** IRTC_ALM_HM_H - RTC Hours and Minutes Alarm Register High(binary format)
IRTC_ALM_HM_H       equ       $0000188C           ;*** IRTC_ALM_HM_H - RTC Hours and Minutes Alarm Register High(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_HM_H_ALM_HOURS0 equ       0                   ; Hours setting of the alarm. It can be set to any value between 0 and 23
IRTC_ALM_HM_H_ALM_HOURS1 equ       1                   ; Hours setting of the alarm. It can be set to any value between 0 and 23
IRTC_ALM_HM_H_ALM_HOURS2 equ       2                   ; Hours setting of the alarm. It can be set to any value between 0 and 23
IRTC_ALM_HM_H_ALM_HOURS3 equ       3                   ; Hours setting of the alarm. It can be set to any value between 0 and 23
IRTC_ALM_HM_H_ALM_HOURS4 equ       4                   ; Hours setting of the alarm. It can be set to any value between 0 and 23
; bit position masks
mIRTC_ALM_HM_H_ALM_HOURS0 equ       %00000001
mIRTC_ALM_HM_H_ALM_HOURS1 equ       %00000010
mIRTC_ALM_HM_H_ALM_HOURS2 equ       %00000100
mIRTC_ALM_HM_H_ALM_HOURS3 equ       %00001000
mIRTC_ALM_HM_H_ALM_HOURS4 equ       %00010000

;*** IRTC_ALM_HM_L - RTC Hours and Minutes Alarm Register Low(binary format)
IRTC_ALM_HM_L       equ       $0000188D           ;*** IRTC_ALM_HM_L - RTC Hours and Minutes Alarm Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_HM_L_ALM_MINUTES0 equ       0                   ; Minutes setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_HM_L_ALM_MINUTES1 equ       1                   ; Minutes setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_HM_L_ALM_MINUTES2 equ       2                   ; Minutes setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_HM_L_ALM_MINUTES3 equ       3                   ; Minutes setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_HM_L_ALM_MINUTES4 equ       4                   ; Minutes setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_HM_L_ALM_MINUTES5 equ       5                   ; Minutes setting of the alarm. It can be set to any value between 0 and 59
; bit position masks
mIRTC_ALM_HM_L_ALM_MINUTES0 equ       %00000001
mIRTC_ALM_HM_L_ALM_MINUTES1 equ       %00000010
mIRTC_ALM_HM_L_ALM_MINUTES2 equ       %00000100
mIRTC_ALM_HM_L_ALM_MINUTES3 equ       %00001000
mIRTC_ALM_HM_L_ALM_MINUTES4 equ       %00010000
mIRTC_ALM_HM_L_ALM_MINUTES5 equ       %00100000

;*** IRTC_ALM_SEC - RTC Seconds Alarm Register (binary format)
IRTC_ALM_SEC        equ       $0000188E           ;*** IRTC_ALM_SEC - RTC Seconds Alarm Register (binary format)

;*** IRTC_ALM_SEC_H - RTC Seconds Alarm Register High(binary format)
IRTC_ALM_SEC_H      equ       $0000188E           ;*** IRTC_ALM_SEC_H - RTC Seconds Alarm Register High(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_SEC_H_DEC_S equ       0                   ; Controls the decrement of seconds counter
IRTC_ALM_SEC_H_INC_S equ       1                   ; Controls the increment of seconds counter
; bit position masks
mIRTC_ALM_SEC_H_DEC_S equ       %00000001
mIRTC_ALM_SEC_H_INC_S equ       %00000010

;*** IRTC_ALM_SEC_L - RTC Seconds Alarm Register Low(binary format)
IRTC_ALM_SEC_L      equ       $0000188F           ;*** IRTC_ALM_SEC_L - RTC Seconds Alarm Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ALM_SEC_L_ALM_SECONDS0 equ       0                   ; Seconds setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_SEC_L_ALM_SECONDS1 equ       1                   ; Seconds setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_SEC_L_ALM_SECONDS2 equ       2                   ; Seconds setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_SEC_L_ALM_SECONDS3 equ       3                   ; Seconds setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_SEC_L_ALM_SECONDS4 equ       4                   ; Seconds setting of the alarm. It can be set to any value between 0 and 59
IRTC_ALM_SEC_L_ALM_SECONDS5 equ       5                   ; Seconds setting of the alarm. It can be set to any value between 0 and 59
; bit position masks
mIRTC_ALM_SEC_L_ALM_SECONDS0 equ       %00000001
mIRTC_ALM_SEC_L_ALM_SECONDS1 equ       %00000010
mIRTC_ALM_SEC_L_ALM_SECONDS2 equ       %00000100
mIRTC_ALM_SEC_L_ALM_SECONDS3 equ       %00001000
mIRTC_ALM_SEC_L_ALM_SECONDS4 equ       %00010000
mIRTC_ALM_SEC_L_ALM_SECONDS5 equ       %00100000

;*** IRTC_CTRL - RTC Control Register
IRTC_CTRL           equ       $00001890           ;*** IRTC_CTRL - RTC Control Register

;*** IRTC_CTRL_H - RTC Control Register High
IRTC_CTRL_H         equ       $00001890           ;*** IRTC_CTRL_H - RTC Control Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_CTRL_H_SWR     equ       0                   ; Software reset
IRTC_CTRL_H_RTC_CLKOUT0 equ       5                   ; Off-chip clock output enable bits, bit 0
IRTC_CTRL_H_RTC_CLKOUT1 equ       6                   ; Off-chip clock output enable bits, bit 1
; bit position masks
mIRTC_CTRL_H_SWR    equ       %00000001
mIRTC_CTRL_H_RTC_CLKOUT0 equ       %00100000
mIRTC_CTRL_H_RTC_CLKOUT1 equ       %01000000

;*** IRTC_CTRL_L - RTC Control Register Low
IRTC_CTRL_L         equ       $00001891           ;*** IRTC_CTRL_L - RTC Control Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_CTRL_L_WE0     equ       0                   ; Write enable bits, bit 0
IRTC_CTRL_L_WE1     equ       1                   ; Write enable bits, bit 1
IRTC_CTRL_L_ALARM_MATCH0 equ       2                   ; Alarm match bits, bit 0
IRTC_CTRL_L_ALARM_MATCH1 equ       3                   ; Alarm match bits, bit 1
IRTC_CTRL_L_DSTEN   equ       6                   ; Daylight saving enable
; bit position masks
mIRTC_CTRL_L_WE0    equ       %00000001
mIRTC_CTRL_L_WE1    equ       %00000010
mIRTC_CTRL_L_ALARM_MATCH0 equ       %00000100
mIRTC_CTRL_L_ALARM_MATCH1 equ       %00001000
mIRTC_CTRL_L_DSTEN  equ       %01000000

;*** IRTC_STATUS - RTC Status Register
IRTC_STATUS         equ       $00001892           ;*** IRTC_STATUS - RTC Status Register

;*** IRTC_STATUS_H - RTC Status Register High
IRTC_STATUS_H       equ       $00001892           ;*** IRTC_STATUS_H - RTC Status Register High

;*** IRTC_STATUS_L - RTC Status Register Low
IRTC_STATUS_L       equ       $00001893           ;*** IRTC_STATUS_L - RTC Status Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_STATUS_L_INVAL equ       0                   ; Invalid time bit
IRTC_STATUS_L_C_DON equ       1                   ; Compensation one bit
IRTC_STATUS_L_BERR  equ       2                   ; Bus error bit
IRTC_STATUS_L_OCAL  equ       3                   ; Calibration output bit or compensation interval bit
IRTC_STATUS_L_WPE   equ       4                   ; Write protect enable
IRTC_STATUS_L_CLV   equ       5                   ; CPU low voltage
IRTC_STATUS_L_PORB  equ       6                   ; Boot Source after POR
; bit position masks
mIRTC_STATUS_L_INVAL equ       %00000001
mIRTC_STATUS_L_C_DON equ       %00000010
mIRTC_STATUS_L_BERR equ       %00000100
mIRTC_STATUS_L_OCAL equ       %00001000
mIRTC_STATUS_L_WPE  equ       %00010000
mIRTC_STATUS_L_CLV  equ       %00100000
mIRTC_STATUS_L_PORB equ       %01000000

;*** IRTC_ISR - RTC Interrupt Status Register
IRTC_ISR            equ       $00001894           ;*** IRTC_ISR - RTC Interrupt Status Register

;*** IRTC_ISR_H - RTC Interrupt Status Register High
IRTC_ISR_H          equ       $00001894           ;*** IRTC_ISR_H - RTC Interrupt Status Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ISR_H_SAM0     equ       0                   ; Sampling timer 0 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM1     equ       1                   ; Sampling timer 1 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM2     equ       2                   ; Sampling timer 2 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM3     equ       3                   ; Sampling timer 3 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM4     equ       4                   ; Sampling timer 4 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM5     equ       5                   ; Sampling timer 5 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM6     equ       6                   ; Sampling timer 6 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM7     equ       7                   ; Sampling timer 7 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
; bit position masks
mIRTC_ISR_H_SAM0    equ       %00000001
mIRTC_ISR_H_SAM1    equ       %00000010
mIRTC_ISR_H_SAM2    equ       %00000100
mIRTC_ISR_H_SAM3    equ       %00001000
mIRTC_ISR_H_SAM4    equ       %00010000
mIRTC_ISR_H_SAM5    equ       %00100000
mIRTC_ISR_H_SAM6    equ       %01000000
mIRTC_ISR_H_SAM7    equ       %10000000

;*** IRTC_ISR_L - RTC Interrupt Status Register Low
IRTC_ISR_L          equ       $00001895           ;*** IRTC_ISR_L - RTC Interrupt Status Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_ISR_L_TMPR     equ       0                   ; Tamper detect interrupt
IRTC_ISR_L_CDT      equ       1                   ; Countdown timer expiry flag
IRTC_ISR_L_ALM      equ       2                   ; Alarm flag
IRTC_ISR_L_DAY      equ       3                   ; Day flag
IRTC_ISR_L_HR       equ       4                   ; Hour flag
IRTC_ISR_L_MIN      equ       5                   ; Minutes flag
IRTC_ISR_L_1HZ      equ       6                   ; Interrupt flag 1 Hz. Indicates an interrupt has occurred. If enabled, this bit is set every half
IRTC_ISR_L_2HZ      equ       7                   ; Interrupt flag 2 Hz. Indicates an interrupt has occurred. If enabled, this bit is set every half
; bit position masks
mIRTC_ISR_L_TMPR    equ       %00000001
mIRTC_ISR_L_CDT     equ       %00000010
mIRTC_ISR_L_ALM     equ       %00000100
mIRTC_ISR_L_DAY     equ       %00001000
mIRTC_ISR_L_HR      equ       %00010000
mIRTC_ISR_L_MIN     equ       %00100000
mIRTC_ISR_L_1HZ     equ       %01000000
mIRTC_ISR_L_2HZ     equ       %10000000

;*** IRTC_IER - RTC Interrupt Enable Register
IRTC_IER            equ       $00001896           ;*** IRTC_IER - RTC Interrupt Enable Register

;*** IRTC_IER_H - RTC Interrupt Enable Register High
IRTC_IER_H          equ       $00001896           ;*** IRTC_IER_H - RTC Interrupt Enable Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_IER_H_SAM0     equ       0                   ; Sampling timer 0 interrupt enable
IRTC_IER_H_SAM1     equ       1                   ; Sampling timer 1 interrupt enable
IRTC_IER_H_SAM2     equ       2                   ; Sampling timer 2 interrupt enable
IRTC_IER_H_SAM3     equ       3                   ; Sampling timer 3 interrupt enable
IRTC_IER_H_SAM4     equ       4                   ; Sampling timer 4 interrupt enable
IRTC_IER_H_SAM5     equ       5                   ; Sampling timer 5 interrupt enable
IRTC_IER_H_SAM6     equ       6                   ; Sampling timer 6 interrupt enable
IRTC_IER_H_SAM7     equ       7                   ; Sampling timer 7 interrupt enable
; bit position masks
mIRTC_IER_H_SAM0    equ       %00000001
mIRTC_IER_H_SAM1    equ       %00000010
mIRTC_IER_H_SAM2    equ       %00000100
mIRTC_IER_H_SAM3    equ       %00001000
mIRTC_IER_H_SAM4    equ       %00010000
mIRTC_IER_H_SAM5    equ       %00100000
mIRTC_IER_H_SAM6    equ       %01000000
mIRTC_IER_H_SAM7    equ       %10000000

;*** IRTC_IER_L - RTC Interrupt Enable Register Low
IRTC_IER_L          equ       $00001897           ;*** IRTC_IER_L - RTC Interrupt Enable Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_IER_L_TMPR     equ       0                   ; Tamper detect interrupt
IRTC_IER_L_CDT      equ       1                   ; Countdown timer expiry flag
IRTC_IER_L_ALM      equ       2                   ; Alarm flag
IRTC_IER_L_DAY      equ       3                   ; Day flag
IRTC_IER_L_HR       equ       4                   ; Hour flag
IRTC_IER_L_MIN      equ       5                   ; Minutes flag
IRTC_IER_L_1HZ      equ       6                   ; Sampling timer interrupt at 1 Hz frequency
IRTC_IER_L_2HZ      equ       7                   ; Sampling timer interrupt at 2 Hz frequency
; bit position masks
mIRTC_IER_L_TMPR    equ       %00000001
mIRTC_IER_L_CDT     equ       %00000010
mIRTC_IER_L_ALM     equ       %00000100
mIRTC_IER_L_DAY     equ       %00001000
mIRTC_IER_L_HR      equ       %00010000
mIRTC_IER_L_MIN     equ       %00100000
mIRTC_IER_L_1HZ     equ       %01000000
mIRTC_IER_L_2HZ     equ       %10000000

;*** IRTC_COUNT_DN - RTC Countdown (Minutes) Timer Register (binary format)
IRTC_COUNT_DN       equ       $00001898           ;*** IRTC_COUNT_DN - RTC Countdown (Minutes) Timer Register (binary format)

;*** IRTC_COUNT_DN_H - RTC Countdown (Minutes) Timer Register High(binary format)
IRTC_COUNT_DN_H     equ       $00001898           ;*** IRTC_COUNT_DN_H - RTC Countdown (Minutes) Timer Register High(binary format)

;*** IRTC_COUNT_DN_L - RTC Countdown (Minutes) Timer Register Low(binary format)
IRTC_COUNT_DN_L     equ       $00001899           ;*** IRTC_COUNT_DN_L - RTC Countdown (Minutes) Timer Register Low(binary format)
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_COUNT_DN_L_COUNTDOWN_COUNT0 equ       0                   ; Countdown counter value bits, bit 0
IRTC_COUNT_DN_L_COUNTDOWN_COUNT1 equ       1                   ; Countdown counter value bits, bit 1
IRTC_COUNT_DN_L_COUNTDOWN_COUNT2 equ       2                   ; Countdown counter value bits, bit 2
IRTC_COUNT_DN_L_COUNTDOWN_COUNT3 equ       3                   ; Countdown counter value bits, bit 3
IRTC_COUNT_DN_L_COUNTDOWN_COUNT4 equ       4                   ; Countdown counter value bits, bit 4
IRTC_COUNT_DN_L_COUNTDOWN_COUNT5 equ       5                   ; Countdown counter value bits, bit 5
IRTC_COUNT_DN_L_COUNTDOWN_COUNT6 equ       6                   ; Countdown counter value bits, bit 6
IRTC_COUNT_DN_L_COUNTDOWN_COUNT7 equ       7                   ; Countdown counter value bits, bit 7
; bit position masks
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT0 equ       %00000001
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT1 equ       %00000010
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT2 equ       %00000100
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT3 equ       %00001000
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT4 equ       %00010000
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT5 equ       %00100000
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT6 equ       %01000000
mIRTC_COUNT_DN_L_COUNTDOWN_COUNT7 equ       %10000000

;*** IRTC_DST_HOUR - RTC Daylight Saving Hour Register
IRTC_DST_HOUR       equ       $000018A2           ;*** IRTC_DST_HOUR - RTC Daylight Saving Hour Register

;*** IRTC_DST_HOUR_H - RTC Daylight Saving Hour Register High
IRTC_DST_HOUR_H     equ       $000018A2           ;*** IRTC_DST_HOUR_H - RTC Daylight Saving Hour Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_HOUR_H_DST_START_HOUR0 equ       0                   ; Hour value when daylight saving has to start bits, bit 0
IRTC_DST_HOUR_H_DST_START_HOUR1 equ       1                   ; Hour value when daylight saving has to start bits, bit 1
IRTC_DST_HOUR_H_DST_START_HOUR2 equ       2                   ; Hour value when daylight saving has to start bits, bit 2
IRTC_DST_HOUR_H_DST_START_HOUR3 equ       3                   ; Hour value when daylight saving has to start bits, bit 3
IRTC_DST_HOUR_H_DST_START_HOUR4 equ       4                   ; Hour value when daylight saving has to start bits, bit 4
; bit position masks
mIRTC_DST_HOUR_H_DST_START_HOUR0 equ       %00000001
mIRTC_DST_HOUR_H_DST_START_HOUR1 equ       %00000010
mIRTC_DST_HOUR_H_DST_START_HOUR2 equ       %00000100
mIRTC_DST_HOUR_H_DST_START_HOUR3 equ       %00001000
mIRTC_DST_HOUR_H_DST_START_HOUR4 equ       %00010000

;*** IRTC_DST_HOUR_L - RTC Daylight Saving Hour Register Low
IRTC_DST_HOUR_L     equ       $000018A3           ;*** IRTC_DST_HOUR_L - RTC Daylight Saving Hour Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_HOUR_L_DST_END_HOUR0 equ       0                   ; Hour value when daylight saving has to end bits, bit 0
IRTC_DST_HOUR_L_DST_END_HOUR1 equ       1                   ; Hour value when daylight saving has to end bits, bit 1
IRTC_DST_HOUR_L_DST_END_HOUR2 equ       2                   ; Hour value when daylight saving has to end bits, bit 2
IRTC_DST_HOUR_L_DST_END_HOUR3 equ       3                   ; Hour value when daylight saving has to end bits, bit 3
IRTC_DST_HOUR_L_DST_END_HOUR4 equ       4                   ; Hour value when daylight saving has to end bits, bit 4
; bit position masks
mIRTC_DST_HOUR_L_DST_END_HOUR0 equ       %00000001
mIRTC_DST_HOUR_L_DST_END_HOUR1 equ       %00000010
mIRTC_DST_HOUR_L_DST_END_HOUR2 equ       %00000100
mIRTC_DST_HOUR_L_DST_END_HOUR3 equ       %00001000
mIRTC_DST_HOUR_L_DST_END_HOUR4 equ       %00010000

;*** IRTC_DST_MNTH - RTC Daylight Saving Month Register
IRTC_DST_MNTH       equ       $000018A4           ;*** IRTC_DST_MNTH - RTC Daylight Saving Month Register

;*** IRTC_DST_MNTH_H - RTC Daylight Saving Month Register High
IRTC_DST_MNTH_H     equ       $000018A4           ;*** IRTC_DST_MNTH_H - RTC Daylight Saving Month Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_MNTH_H_DST_START_MONTH0 equ       0                   ; Month value when daylight saving has to start bits, bit 0
IRTC_DST_MNTH_H_DST_START_MONTH1 equ       1                   ; Month value when daylight saving has to start bits, bit 1
IRTC_DST_MNTH_H_DST_START_MONTH2 equ       2                   ; Month value when daylight saving has to start bits, bit 2
IRTC_DST_MNTH_H_DST_START_MONTH3 equ       3                   ; Month value when daylight saving has to start bits, bit 3
; bit position masks
mIRTC_DST_MNTH_H_DST_START_MONTH0 equ       %00000001
mIRTC_DST_MNTH_H_DST_START_MONTH1 equ       %00000010
mIRTC_DST_MNTH_H_DST_START_MONTH2 equ       %00000100
mIRTC_DST_MNTH_H_DST_START_MONTH3 equ       %00001000

;*** IRTC_DST_MNTH_L - RTC Daylight Saving Month Register Low
IRTC_DST_MNTH_L     equ       $000018A5           ;*** IRTC_DST_MNTH_L - RTC Daylight Saving Month Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_MNTH_L_DST_END_MONTH0 equ       0                   ; Month value when daylight saving has to end bits, bit 0
IRTC_DST_MNTH_L_DST_END_MONTH1 equ       1                   ; Month value when daylight saving has to end bits, bit 1
IRTC_DST_MNTH_L_DST_END_MONTH2 equ       2                   ; Month value when daylight saving has to end bits, bit 2
IRTC_DST_MNTH_L_DST_END_MONTH3 equ       3                   ; Month value when daylight saving has to end bits, bit 3
; bit position masks
mIRTC_DST_MNTH_L_DST_END_MONTH0 equ       %00000001
mIRTC_DST_MNTH_L_DST_END_MONTH1 equ       %00000010
mIRTC_DST_MNTH_L_DST_END_MONTH2 equ       %00000100
mIRTC_DST_MNTH_L_DST_END_MONTH3 equ       %00001000

;*** IRTC_DST_DAY - RTC Daylight Saving Day Register
IRTC_DST_DAY        equ       $000018A6           ;*** IRTC_DST_DAY - RTC Daylight Saving Day Register

;*** IRTC_DST_DAY_H - RTC Daylight Saving Day Register High
IRTC_DST_DAY_H      equ       $000018A6           ;*** IRTC_DST_DAY_H - RTC Daylight Saving Day Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_DAY_H_DST_START_DAY0 equ       0                   ; Day value when daylight saving has to start bits, bit 0
IRTC_DST_DAY_H_DST_START_DAY1 equ       1                   ; Day value when daylight saving has to start bits, bit 1
IRTC_DST_DAY_H_DST_START_DAY2 equ       2                   ; Day value when daylight saving has to start bits, bit 2
IRTC_DST_DAY_H_DST_START_DAY3 equ       3                   ; Day value when daylight saving has to start bits, bit 3
IRTC_DST_DAY_H_DST_START_DAY4 equ       4                   ; Day value when daylight saving has to start bits, bit 4
; bit position masks
mIRTC_DST_DAY_H_DST_START_DAY0 equ       %00000001
mIRTC_DST_DAY_H_DST_START_DAY1 equ       %00000010
mIRTC_DST_DAY_H_DST_START_DAY2 equ       %00000100
mIRTC_DST_DAY_H_DST_START_DAY3 equ       %00001000
mIRTC_DST_DAY_H_DST_START_DAY4 equ       %00010000

;*** IRTC_DST_DAY_L - RTC Daylight Saving Day Register Low
IRTC_DST_DAY_L      equ       $000018A7           ;*** IRTC_DST_DAY_L - RTC Daylight Saving Day Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_DST_DAY_L_DST_END_DAY0 equ       0                   ; Day value when daylight saving has to end bits, bit 0
IRTC_DST_DAY_L_DST_END_DAY1 equ       1                   ; Day value when daylight saving has to end bits, bit 1
IRTC_DST_DAY_L_DST_END_DAY2 equ       2                   ; Day value when daylight saving has to end bits, bit 2
IRTC_DST_DAY_L_DST_END_DAY3 equ       3                   ; Day value when daylight saving has to end bits, bit 3
IRTC_DST_DAY_L_DST_END_DAY4 equ       4                   ; Day value when daylight saving has to end bits, bit 4
; bit position masks
mIRTC_DST_DAY_L_DST_END_DAY0 equ       %00000001
mIRTC_DST_DAY_L_DST_END_DAY1 equ       %00000010
mIRTC_DST_DAY_L_DST_END_DAY2 equ       %00000100
mIRTC_DST_DAY_L_DST_END_DAY3 equ       %00001000
mIRTC_DST_DAY_L_DST_END_DAY4 equ       %00010000

;*** IRTC_COMPEN - RTC Compensation Register
IRTC_COMPEN         equ       $000018A8           ;*** IRTC_COMPEN - RTC Compensation Register

;*** IRTC_COMPEN_H - RTC Compensation Register High
IRTC_COMPEN_H       equ       $000018A8           ;*** IRTC_COMPEN_H - RTC Compensation Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_COMPEN_H_COMPENSATION_INTERVAL0 equ       0                   ; Compensation interval value bits, bit 0
IRTC_COMPEN_H_COMPENSATION_INTERVAL1 equ       1                   ; Compensation interval value bits, bit 1
IRTC_COMPEN_H_COMPENSATION_INTERVAL2 equ       2                   ; Compensation interval value bits, bit 2
IRTC_COMPEN_H_COMPENSATION_INTERVAL3 equ       3                   ; Compensation interval value bits, bit 3
IRTC_COMPEN_H_COMPENSATION_INTERVAL4 equ       4                   ; Compensation interval value bits, bit 4
IRTC_COMPEN_H_COMPENSATION_INTERVAL5 equ       5                   ; Compensation interval value bits, bit 5
IRTC_COMPEN_H_COMPENSATION_INTERVAL6 equ       6                   ; Compensation interval value bits, bit 6
IRTC_COMPEN_H_COMPENSATION_INTERVAL7 equ       7                   ; Compensation interval value bits, bit 7
; bit position masks
mIRTC_COMPEN_H_COMPENSATION_INTERVAL0 equ       %00000001
mIRTC_COMPEN_H_COMPENSATION_INTERVAL1 equ       %00000010
mIRTC_COMPEN_H_COMPENSATION_INTERVAL2 equ       %00000100
mIRTC_COMPEN_H_COMPENSATION_INTERVAL3 equ       %00001000
mIRTC_COMPEN_H_COMPENSATION_INTERVAL4 equ       %00010000
mIRTC_COMPEN_H_COMPENSATION_INTERVAL5 equ       %00100000
mIRTC_COMPEN_H_COMPENSATION_INTERVAL6 equ       %01000000
mIRTC_COMPEN_H_COMPENSATION_INTERVAL7 equ       %10000000

;*** IRTC_COMPEN_L - RTC Compensation Register Low
IRTC_COMPEN_L       equ       $000018A9           ;*** IRTC_COMPEN_L - RTC Compensation Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_COMPEN_L_COMPENSATION_VALUE0 equ       0                   ; Compensation value bits, bit 0
IRTC_COMPEN_L_COMPENSATION_VALUE1 equ       1                   ; Compensation value bits, bit 1
IRTC_COMPEN_L_COMPENSATION_VALUE2 equ       2                   ; Compensation value bits, bit 2
IRTC_COMPEN_L_COMPENSATION_VALUE3 equ       3                   ; Compensation value bits, bit 3
IRTC_COMPEN_L_COMPENSATION_VALUE4 equ       4                   ; Compensation value bits, bit 4
IRTC_COMPEN_L_COMPENSATION_VALUE5 equ       5                   ; Compensation value bits, bit 5
IRTC_COMPEN_L_COMPENSATION_VALUE6 equ       6                   ; Compensation value bits, bit 6
IRTC_COMPEN_L_COMPENSATION_VALUE7 equ       7                   ; Compensation value bits, bit 7
; bit position masks
mIRTC_COMPEN_L_COMPENSATION_VALUE0 equ       %00000001
mIRTC_COMPEN_L_COMPENSATION_VALUE1 equ       %00000010
mIRTC_COMPEN_L_COMPENSATION_VALUE2 equ       %00000100
mIRTC_COMPEN_L_COMPENSATION_VALUE3 equ       %00001000
mIRTC_COMPEN_L_COMPENSATION_VALUE4 equ       %00010000
mIRTC_COMPEN_L_COMPENSATION_VALUE5 equ       %00100000
mIRTC_COMPEN_L_COMPENSATION_VALUE6 equ       %01000000
mIRTC_COMPEN_L_COMPENSATION_VALUE7 equ       %10000000

;*** IRTC_TTSR_YM - RTC Tamper Time Stamp Month & Year Register
IRTC_TTSR_YM        equ       $000018AA           ;*** IRTC_TTSR_YM - RTC Tamper Time Stamp Month & Year Register

;*** IRTC_TTSR_YM_H - RTC Tamper Time Stamp Month & Year Register High
IRTC_TTSR_YM_H      equ       $000018AA           ;*** IRTC_TTSR_YM_H - RTC Tamper Time Stamp Month & Year Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_YM_H_TIME_STAMP_YEAR0 equ       0                   ; Tamper detect year value bits, bit 0
IRTC_TTSR_YM_H_TIME_STAMP_YEAR1 equ       1                   ; Tamper detect year value bits, bit 1
IRTC_TTSR_YM_H_TIME_STAMP_YEAR2 equ       2                   ; Tamper detect year value bits, bit 2
IRTC_TTSR_YM_H_TIME_STAMP_YEAR3 equ       3                   ; Tamper detect year value bits, bit 3
IRTC_TTSR_YM_H_TIME_STAMP_YEAR4 equ       4                   ; Tamper detect year value bits, bit 4
IRTC_TTSR_YM_H_TIME_STAMP_YEAR5 equ       5                   ; Tamper detect year value bits, bit 5
IRTC_TTSR_YM_H_TIME_STAMP_YEAR6 equ       6                   ; Tamper detect year value bits, bit 6
IRTC_TTSR_YM_H_TIME_STAMP_YEAR7 equ       7                   ; Tamper detect year value bits, bit 7
; bit position masks
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR0 equ       %00000001
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR1 equ       %00000010
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR2 equ       %00000100
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR3 equ       %00001000
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR4 equ       %00010000
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR5 equ       %00100000
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR6 equ       %01000000
mIRTC_TTSR_YM_H_TIME_STAMP_YEAR7 equ       %10000000

;*** IRTC_TTSR_YM_L - RTC Tamper Time Stamp Month & Year Register Low
IRTC_TTSR_YM_L      equ       $000018AB           ;*** IRTC_TTSR_YM_L - RTC Tamper Time Stamp Month & Year Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_YM_L_TIME_STAMP_MONTHS0 equ       0                   ; Tamper detect month value bits, bit 0
IRTC_TTSR_YM_L_TIME_STAMP_MONTHS1 equ       1                   ; Tamper detect month value bits, bit 1
IRTC_TTSR_YM_L_TIME_STAMP_MONTHS2 equ       2                   ; Tamper detect month value bits, bit 2
IRTC_TTSR_YM_L_TIME_STAMP_MONTHS3 equ       3                   ; Tamper detect month value bits, bit 3
; bit position masks
mIRTC_TTSR_YM_L_TIME_STAMP_MONTHS0 equ       %00000001
mIRTC_TTSR_YM_L_TIME_STAMP_MONTHS1 equ       %00000010
mIRTC_TTSR_YM_L_TIME_STAMP_MONTHS2 equ       %00000100
mIRTC_TTSR_YM_L_TIME_STAMP_MONTHS3 equ       %00001000

;*** IRTC_TTSR_DAY - RTC Tamper Time Stamp Day Register
IRTC_TTSR_DAY       equ       $000018AC           ;*** IRTC_TTSR_DAY - RTC Tamper Time Stamp Day Register

;*** IRTC_TTSR_DAY_H - RTC Tamper Time Stamp Day Register High
IRTC_TTSR_DAY_H     equ       $000018AC           ;*** IRTC_TTSR_DAY_H - RTC Tamper Time Stamp Day Register High

;*** IRTC_TTSR_DAY_L - RTC Tamper Time Stamp Day Register Low
IRTC_TTSR_DAY_L     equ       $000018AD           ;*** IRTC_TTSR_DAY_L - RTC Tamper Time Stamp Day Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_DAY_L_TIME_STAMP_DAY0 equ       0                   ; Tamper detect days value bits, bit 0
IRTC_TTSR_DAY_L_TIME_STAMP_DAY1 equ       1                   ; Tamper detect days value bits, bit 1
IRTC_TTSR_DAY_L_TIME_STAMP_DAY2 equ       2                   ; Tamper detect days value bits, bit 2
IRTC_TTSR_DAY_L_TIME_STAMP_DAY3 equ       3                   ; Tamper detect days value bits, bit 3
IRTC_TTSR_DAY_L_TIME_STAMP_DAY4 equ       4                   ; Tamper detect days value bits, bit 4
; bit position masks
mIRTC_TTSR_DAY_L_TIME_STAMP_DAY0 equ       %00000001
mIRTC_TTSR_DAY_L_TIME_STAMP_DAY1 equ       %00000010
mIRTC_TTSR_DAY_L_TIME_STAMP_DAY2 equ       %00000100
mIRTC_TTSR_DAY_L_TIME_STAMP_DAY3 equ       %00001000
mIRTC_TTSR_DAY_L_TIME_STAMP_DAY4 equ       %00010000

;*** IRTC_TTSR_HM - RTC Tamper Time Stamp Hours & Minutes Register
IRTC_TTSR_HM        equ       $000018AE           ;*** IRTC_TTSR_HM - RTC Tamper Time Stamp Hours & Minutes Register

;*** IRTC_TTSR_HM_H - RTC Tamper Time Stamp Hours & Minutes Register High
IRTC_TTSR_HM_H      equ       $000018AE           ;*** IRTC_TTSR_HM_H - RTC Tamper Time Stamp Hours & Minutes Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_HM_H_TIME_STAMP_HOURS0 equ       0                   ; Tamper detect hours value bits, bit 0
IRTC_TTSR_HM_H_TIME_STAMP_HOURS1 equ       1                   ; Tamper detect hours value bits, bit 1
IRTC_TTSR_HM_H_TIME_STAMP_HOURS2 equ       2                   ; Tamper detect hours value bits, bit 2
IRTC_TTSR_HM_H_TIME_STAMP_HOURS3 equ       3                   ; Tamper detect hours value bits, bit 3
IRTC_TTSR_HM_H_TIME_STAMP_HOURS4 equ       4                   ; Tamper detect hours value bits, bit 4
; bit position masks
mIRTC_TTSR_HM_H_TIME_STAMP_HOURS0 equ       %00000001
mIRTC_TTSR_HM_H_TIME_STAMP_HOURS1 equ       %00000010
mIRTC_TTSR_HM_H_TIME_STAMP_HOURS2 equ       %00000100
mIRTC_TTSR_HM_H_TIME_STAMP_HOURS3 equ       %00001000
mIRTC_TTSR_HM_H_TIME_STAMP_HOURS4 equ       %00010000

;*** IRTC_TTSR_HM_L - RTC Tamper Time Stamp Hours & Minutes Register Low
IRTC_TTSR_HM_L      equ       $000018AF           ;*** IRTC_TTSR_HM_L - RTC Tamper Time Stamp Hours & Minutes Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_HM_L_TIME_STAMP_MINUTES0 equ       0                   ; Tamper detect minutes value bits, bit 0
IRTC_TTSR_HM_L_TIME_STAMP_MINUTES1 equ       1                   ; Tamper detect minutes value bits, bit 1
IRTC_TTSR_HM_L_TIME_STAMP_MINUTES2 equ       2                   ; Tamper detect minutes value bits, bit 2
IRTC_TTSR_HM_L_TIME_STAMP_MINUTES3 equ       3                   ; Tamper detect minutes value bits, bit 3
IRTC_TTSR_HM_L_TIME_STAMP_MINUTES4 equ       4                   ; Tamper detect minutes value bits, bit 4
IRTC_TTSR_HM_L_TIME_STAMP_MINUTES5 equ       5                   ; Tamper detect minutes value bits, bit 5
; bit position masks
mIRTC_TTSR_HM_L_TIME_STAMP_MINUTES0 equ       %00000001
mIRTC_TTSR_HM_L_TIME_STAMP_MINUTES1 equ       %00000010
mIRTC_TTSR_HM_L_TIME_STAMP_MINUTES2 equ       %00000100
mIRTC_TTSR_HM_L_TIME_STAMP_MINUTES3 equ       %00001000
mIRTC_TTSR_HM_L_TIME_STAMP_MINUTES4 equ       %00010000
mIRTC_TTSR_HM_L_TIME_STAMP_MINUTES5 equ       %00100000

;*** IRTC_TTSR_SEC - RTC Tamper Time Stamp Seconds Register
IRTC_TTSR_SEC       equ       $000018B0           ;*** IRTC_TTSR_SEC - RTC Tamper Time Stamp Seconds Register

;*** IRTC_TTSR_SEC_H - RTC Tamper Time Stamp Seconds Register High
IRTC_TTSR_SEC_H     equ       $000018B0           ;*** IRTC_TTSR_SEC_H - RTC Tamper Time Stamp Seconds Register High

;*** IRTC_TTSR_SEC_L - RTC Tamper Time Stamp Seconds Register Low
IRTC_TTSR_SEC_L     equ       $000018B1           ;*** IRTC_TTSR_SEC_L - RTC Tamper Time Stamp Seconds Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TTSR_SEC_L_TIME_STAMP_SECONDS0 equ       0                   ; Tamper detect seconds value bits, bit 0
IRTC_TTSR_SEC_L_TIME_STAMP_SECONDS1 equ       1                   ; Tamper detect seconds value bits, bit 1
IRTC_TTSR_SEC_L_TIME_STAMP_SECONDS2 equ       2                   ; Tamper detect seconds value bits, bit 2
IRTC_TTSR_SEC_L_TIME_STAMP_SECONDS3 equ       3                   ; Tamper detect seconds value bits, bit 3
IRTC_TTSR_SEC_L_TIME_STAMP_SECONDS4 equ       4                   ; Tamper detect seconds value bits, bit 4
IRTC_TTSR_SEC_L_TIME_STAMP_SECONDS5 equ       5                   ; Tamper detect seconds value bits, bit 5
; bit position masks
mIRTC_TTSR_SEC_L_TIME_STAMP_SECONDS0 equ       %00000001
mIRTC_TTSR_SEC_L_TIME_STAMP_SECONDS1 equ       %00000010
mIRTC_TTSR_SEC_L_TIME_STAMP_SECONDS2 equ       %00000100
mIRTC_TTSR_SEC_L_TIME_STAMP_SECONDS3 equ       %00001000
mIRTC_TTSR_SEC_L_TIME_STAMP_SECONDS4 equ       %00010000
mIRTC_TTSR_SEC_L_TIME_STAMP_SECONDS5 equ       %00100000

;*** IRTC_TAMPER_SCR - Tamper Status & Control Register
IRTC_TAMPER_SCR     equ       $000018B2           ;*** IRTC_TAMPER_SCR - Tamper Status & Control Register

;*** IRTC_TAMPER_SCR_H - Tamper Status & Control Register High
IRTC_TAMPER_SCR_H   equ       $000018B2           ;*** IRTC_TAMPER_SCR_H - Tamper Status & Control Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TAMPER_SCR_H_BAT_TAMPER_STATUS equ       0                   ; Battery Tamper Status Bit
IRTC_TAMPER_SCR_H_TAMPER1_STATUS equ       1                   ; Tamper Pin1 Status Bit
IRTC_TAMPER_SCR_H_TAMPER2_STATUS equ       2                   ; Tamper Pin2 Status Bit
; bit position masks
mIRTC_TAMPER_SCR_H_BAT_TAMPER_STATUS equ       %00000001
mIRTC_TAMPER_SCR_H_TAMPER1_STATUS equ       %00000010
mIRTC_TAMPER_SCR_H_TAMPER2_STATUS equ       %00000100

;*** IRTC_TAMPER_SCR_L - Tamper Status & Control Register Low
IRTC_TAMPER_SCR_L   equ       $000018B3           ;*** IRTC_TAMPER_SCR_L - Tamper Status & Control Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_TAMPER_SCR_L_BAT_TAMPER_CTRL equ       0                   ; Battery Tamper Control Bit
IRTC_TAMPER_SCR_L_TAMPER1_CTRL equ       1                   ; Tamper Pin1 Control Bits
IRTC_TAMPER_SCR_L_TAMPER2_CTRL equ       2                   ; Tamper Pin2 Control Bits
; bit position masks
mIRTC_TAMPER_SCR_L_BAT_TAMPER_CTRL equ       %00000001
mIRTC_TAMPER_SCR_L_TAMPER1_CTRL equ       %00000010
mIRTC_TAMPER_SCR_L_TAMPER2_CTRL equ       %00000100

;*** IRTC_FILTER01_CTRL - Tamper Filter 0 & 1 Control Register
IRTC_FILTER01_CTRL  equ       $000018B4           ;*** IRTC_FILTER01_CTRL - Tamper Filter 0 & 1 Control Register

;*** IRTC_FILTER01_CTRL_H - Tamper Filter 0 & 1 Control Register High
IRTC_FILTER01_CTRL_H equ       $000018B4           ;*** IRTC_FILTER01_CTRL_H - Tamper Filter 0 & 1 Control Register High

;*** IRTC_FILTER01_CTRL_L - Tamper Filter 0 & 1 Control Register Low
IRTC_FILTER01_CTRL_L equ       $000018B5           ;*** IRTC_FILTER01_CTRL_L - Tamper Filter 0 & 1 Control Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_FILTER01_CTRL_L_FILTER1_DURATION0 equ       0                   ; Tamper Detect Bit 1 Filter Duration, bit 0
IRTC_FILTER01_CTRL_L_FILTER1_DURATION1 equ       1                   ; Tamper Detect Bit 1 Filter Duration, bit 1
IRTC_FILTER01_CTRL_L_FILTER1_DURATION2 equ       2                   ; Tamper Detect Bit 1 Filter Duration, bit 2
IRTC_FILTER01_CTRL_L_FILTER1_DURATION3 equ       3                   ; Tamper Detect Bit 1 Filter Duration, bit 3
IRTC_FILTER01_CTRL_L_FILTER1_DURATION4 equ       4                   ; Tamper Detect Bit 1 Filter Duration, bit 4
IRTC_FILTER01_CTRL_L_FILTER1_DURATION5 equ       5                   ; Tamper Detect Bit 1 Filter Duration, bit 5
IRTC_FILTER01_CTRL_L_CLKSEL equ       6                   ; Tamper Filter 1 Clock Select
IRTC_FILTER01_CTRL_L_POL equ       7                   ; Tamper Detect Input Bit 1 Polarity Control
; bit position masks
mIRTC_FILTER01_CTRL_L_FILTER1_DURATION0 equ       %00000001
mIRTC_FILTER01_CTRL_L_FILTER1_DURATION1 equ       %00000010
mIRTC_FILTER01_CTRL_L_FILTER1_DURATION2 equ       %00000100
mIRTC_FILTER01_CTRL_L_FILTER1_DURATION3 equ       %00001000
mIRTC_FILTER01_CTRL_L_FILTER1_DURATION4 equ       %00010000
mIRTC_FILTER01_CTRL_L_FILTER1_DURATION5 equ       %00100000
mIRTC_FILTER01_CTRL_L_CLKSEL equ       %01000000
mIRTC_FILTER01_CTRL_L_POL equ       %10000000

;*** IRTC_FILTER23_CTRL - Tamper Filter 2 & 3 Control Register
IRTC_FILTER23_CTRL  equ       $000018B6           ;*** IRTC_FILTER23_CTRL - Tamper Filter 2 & 3 Control Register

;*** IRTC_FILTER23_CTRL_H - Tamper Filter 2 & 3 Control Register High
IRTC_FILTER23_CTRL_H equ       $000018B6           ;*** IRTC_FILTER23_CTRL_H - Tamper Filter 2 & 3 Control Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRTC_FILTER23_CTRL_H_FILTER2_DURATION0 equ       0                   ; Tamper Detect Bit 2 Filter Duration, bit 0
IRTC_FILTER23_CTRL_H_FILTER2_DURATION1 equ       1                   ; Tamper Detect Bit 2 Filter Duration, bit 1
IRTC_FILTER23_CTRL_H_FILTER2_DURATION2 equ       2                   ; Tamper Detect Bit 2 Filter Duration, bit 2
IRTC_FILTER23_CTRL_H_FILTER2_DURATION3 equ       3                   ; Tamper Detect Bit 2 Filter Duration, bit 3
IRTC_FILTER23_CTRL_H_FILTER2_DURATION4 equ       4                   ; Tamper Detect Bit 2 Filter Duration, bit 4
IRTC_FILTER23_CTRL_H_FILTER2_DURATION5 equ       5                   ; Tamper Detect Bit 2 Filter Duration, bit 5
IRTC_FILTER23_CTRL_H_CLKSEL equ       6                   ; Tamper Filter 2 Clock Select
IRTC_FILTER23_CTRL_H_POL equ       7                   ; Tamper Detect Input Bit 2 Polarity Control
; bit position masks
mIRTC_FILTER23_CTRL_H_FILTER2_DURATION0 equ       %00000001
mIRTC_FILTER23_CTRL_H_FILTER2_DURATION1 equ       %00000010
mIRTC_FILTER23_CTRL_H_FILTER2_DURATION2 equ       %00000100
mIRTC_FILTER23_CTRL_H_FILTER2_DURATION3 equ       %00001000
mIRTC_FILTER23_CTRL_H_FILTER2_DURATION4 equ       %00010000
mIRTC_FILTER23_CTRL_H_FILTER2_DURATION5 equ       %00100000
mIRTC_FILTER23_CTRL_H_CLKSEL equ       %01000000
mIRTC_FILTER23_CTRL_H_POL equ       %10000000

;*** IRTC_FILTER23_CTRL_L - Tamper Filter 2 & 3 Control Register Low
IRTC_FILTER23_CTRL_L equ       $000018B7           ;*** IRTC_FILTER23_CTRL_L - Tamper Filter 2 & 3 Control Register Low

;*** PTAPE - Port A Pull Enable Register
PTAPE               equ       $000018E0           ;*** PTAPE - Port A Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Internal Pull Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Internal Pull Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Internal Pull Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Internal Pull Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Internal Pull Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Internal Pull Enable for Port A Bit 5
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000

;*** PTASE - Port A Slew Rate Enable Register
PTASE               equ       $000018E1           ;*** PTASE - Port A Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2        equ       2                   ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3        equ       3                   ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE5        equ       5                   ; Output Slew Rate Enable for Port A Bit 5
PTASE_PTASE6        equ       6                   ; Output Slew Rate Enable for Port A Bit 6
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE2       equ       %00000100
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000
mPTASE_PTASE5       equ       %00100000
mPTASE_PTASE6       equ       %01000000

;*** PTADS - Port A Drive Strength Selection Register
PTADS               equ       $000018E2           ;*** PTADS - Port A Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0        equ       0                   ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1        equ       1                   ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2        equ       2                   ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3        equ       3                   ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4        equ       4                   ; Output Drive Strength Selection for Port A Bit 4
PTADS_PTADS5        equ       5                   ; Output Drive Strength Selection for Port A Bit 5
PTADS_PTADS6        equ       6                   ; Output Drive Strength Selection for Port A Bit 6
; bit position masks
mPTADS_PTADS0       equ       %00000001
mPTADS_PTADS1       equ       %00000010
mPTADS_PTADS2       equ       %00000100
mPTADS_PTADS3       equ       %00001000
mPTADS_PTADS4       equ       %00010000
mPTADS_PTADS5       equ       %00100000
mPTADS_PTADS6       equ       %01000000

;*** PTAIFE - Port A Input Filter Enable Register
PTAIFE              equ       $000018E3           ;*** PTAIFE - Port A Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAIFE_PTAIFE0      equ       0                   ; Port A Input Filter Enable Bit 0
PTAIFE_PTAIFE1      equ       1                   ; Port A Input Filter Enable Bit 1
PTAIFE_PTAIFE2      equ       2                   ; Port A Input Filter Enable Bit 2
PTAIFE_PTAIFE3      equ       3                   ; Port A Input Filter Enable Bit 3
PTAIFE_PTAIFE4      equ       4                   ; Port A Input Filter Enable Bit 4
PTAIFE_PTAIFE5      equ       5                   ; Port A Input Filter Enable Bit 5
; bit position masks
mPTAIFE_PTAIFE0     equ       %00000001
mPTAIFE_PTAIFE1     equ       %00000010
mPTAIFE_PTAIFE2     equ       %00000100
mPTAIFE_PTAIFE3     equ       %00001000
mPTAIFE_PTAIFE4     equ       %00010000
mPTAIFE_PTAIFE5     equ       %00100000

;*** PTBPE - Port B Pull Enable Register
PTBPE               equ       $000018E4           ;*** PTBPE - Port B Pull Enable Register
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
PTBSE               equ       $000018E5           ;*** PTBSE - Port B Slew Rate Enable Register
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
PTBDS               equ       $000018E6           ;*** PTBDS - Port B Drive Strength Selection Register
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
PTBIFE              equ       $000018E7           ;*** PTBIFE - Port B Input Filter Enable Register
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
PTCPE               equ       $000018E8           ;*** PTCPE - Port C Pull Enable Register
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
PTCSE               equ       $000018E9           ;*** PTCSE - Port C Slew Rate Enable Register
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
PTCDS               equ       $000018EA           ;*** PTCDS - Port C Drive Strength Selection Register
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
PTCIFE              equ       $000018EB           ;*** PTCIFE - Port C Input Filter Enable Register
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
PTDPE               equ       $000018EC           ;*** PTDPE - Port D Pull Enable Register
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
PTDSE               equ       $000018ED           ;*** PTDSE - Port D Slew Rate Enable Register
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
PTDDS               equ       $000018EE           ;*** PTDDS - Port D Drive Strength Selection Register
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
PTDIFE              equ       $000018EF           ;*** PTDIFE - Port D Input Filter Enable Register
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
PTEPE               equ       $000018F0           ;*** PTEPE - Port E Pull Enable Register
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
PTESE               equ       $000018F1           ;*** PTESE - Port E Slew Rate Enable Register
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
PTEDS               equ       $000018F2           ;*** PTEDS - Port E Drive Strength Selection Register
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
PTEIFE              equ       $000018F3           ;*** PTEIFE - Port E Input Filter Enable Register
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
PTFPE               equ       $000018F4           ;*** PTFPE - Port F Pull Enable Register
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
PTFSE               equ       $000018F5           ;*** PTFSE - Port F Slew Rate Enable Register
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
PTFDS               equ       $000018F6           ;*** PTFDS - Port F Drive Strength Selection Register
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
PTFIFE              equ       $000018F7           ;*** PTFIFE - Port F Input Filter Enable Register
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
PTGPE               equ       $000018F8           ;*** PTGPE - Port G Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0        equ       0                   ; Internal Pull Enable for Port G Bit 0
PTGPE_PTGPE1        equ       1                   ; Internal Pull Enable for Port G Bit 1
PTGPE_PTGPE2        equ       2                   ; Internal Pull Enable for Port G Bit 2
PTGPE_PTGPE3        equ       3                   ; Internal Pull Enable for Port G Bit 3
PTGPE_PTGPE4        equ       4                   ; Internal Pull Enable for Port G Bit 4
PTGPE_PTGPE5        equ       5                   ; Internal Pull Enable for Port G Bit 5
PTGPE_PTGPE6        equ       6                   ; Internal Pull Enable for Port G Bit 6
PTGPE_PTGPE7        equ       7                   ; Internal Pull Enable for Port G Bit 7
; bit position masks
mPTGPE_PTGPE0       equ       %00000001
mPTGPE_PTGPE1       equ       %00000010
mPTGPE_PTGPE2       equ       %00000100
mPTGPE_PTGPE3       equ       %00001000
mPTGPE_PTGPE4       equ       %00010000
mPTGPE_PTGPE5       equ       %00100000
mPTGPE_PTGPE6       equ       %01000000
mPTGPE_PTGPE7       equ       %10000000

;*** PTGSE - Port G Slew Rate Enable Register
PTGSE               equ       $000018F9           ;*** PTGSE - Port G Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0        equ       0                   ; Output Slew Rate Enable for Port G Bit 0
PTGSE_PTGSE1        equ       1                   ; Output Slew Rate Enable for Port G Bit 1
PTGSE_PTGSE2        equ       2                   ; Output Slew Rate Enable for Port G Bit 2
PTGSE_PTGSE3        equ       3                   ; Output Slew Rate Enable for Port G Bit 3
PTGSE_PTGSE4        equ       4                   ; Output Slew Rate Enable for Port G Bit 4
PTGSE_PTGSE5        equ       5                   ; Output Slew Rate Enable for Port G Bit 5
PTGSE_PTGSE6        equ       6                   ; Output Slew Rate Enable for Port G Bit 6
PTGSE_PTGSE7        equ       7                   ; Output Slew Rate Enable for Port G Bit 7
; bit position masks
mPTGSE_PTGSE0       equ       %00000001
mPTGSE_PTGSE1       equ       %00000010
mPTGSE_PTGSE2       equ       %00000100
mPTGSE_PTGSE3       equ       %00001000
mPTGSE_PTGSE4       equ       %00010000
mPTGSE_PTGSE5       equ       %00100000
mPTGSE_PTGSE6       equ       %01000000
mPTGSE_PTGSE7       equ       %10000000

;*** PTGDS - Port G Drive Strength Selection Register
PTGDS               equ       $000018FA           ;*** PTGDS - Port G Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGDS_PTGDS0        equ       0                   ; Output Drive Strength Selection for Port G Bit 0
PTGDS_PTGDS1        equ       1                   ; Output Drive Strength Selection for Port G Bit 1
PTGDS_PTGDS2        equ       2                   ; Output Drive Strength Selection for Port G Bit 2
PTGDS_PTGDS3        equ       3                   ; Output Drive Strength Selection for Port G Bit 3
PTGDS_PTGDS4        equ       4                   ; Output Drive Strength Selection for Port G Bit 4
PTGDS_PTGDS5        equ       5                   ; Output Drive Strength Selection for Port G Bit 5
PTGDS_PTGDS6        equ       6                   ; Output Drive Strength Selection for Port G Bit 6
PTGDS_PTGDS7        equ       7                   ; Output Drive Strength Selection for Port G Bit 7
; bit position masks
mPTGDS_PTGDS0       equ       %00000001
mPTGDS_PTGDS1       equ       %00000010
mPTGDS_PTGDS2       equ       %00000100
mPTGDS_PTGDS3       equ       %00001000
mPTGDS_PTGDS4       equ       %00010000
mPTGDS_PTGDS5       equ       %00100000
mPTGDS_PTGDS6       equ       %01000000
mPTGDS_PTGDS7       equ       %10000000

;*** PTGIFE - Port G Input Filter Enable Register
PTGIFE              equ       $000018FB           ;*** PTGIFE - Port G Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGIFE_PTGIFE0      equ       0                   ; Port G Input Filter Enable Bit 0
PTGIFE_PTGIFE1      equ       1                   ; Port G Input Filter Enable Bit 1
PTGIFE_PTGIFE2      equ       2                   ; Port G Input Filter Enable Bit 2
PTGIFE_PTGIFE3      equ       3                   ; Port G Input Filter Enable Bit 3
PTGIFE_PTGIFE4      equ       4                   ; Port G Input Filter Enable Bit 4
PTGIFE_PTGIFE5      equ       5                   ; Port G Input Filter Enable Bit 5
PTGIFE_PTGIFE6      equ       6                   ; Port G Input Filter Enable Bit 6
PTGIFE_PTGIFE7      equ       7                   ; Port G Input Filter Enable Bit 7
; bit position masks
mPTGIFE_PTGIFE0     equ       %00000001
mPTGIFE_PTGIFE1     equ       %00000010
mPTGIFE_PTGIFE2     equ       %00000100
mPTGIFE_PTGIFE3     equ       %00001000
mPTGIFE_PTGIFE4     equ       %00010000
mPTGIFE_PTGIFE5     equ       %00100000
mPTGIFE_PTGIFE6     equ       %01000000
mPTGIFE_PTGIFE7     equ       %10000000

;*** PTHPE - Port H Pull Enable Register
PTHPE               equ       $000018FC           ;*** PTHPE - Port H Pull Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPE_PTHPE0        equ       0                   ; Internal Pull Enable for Port H Bit 0
PTHPE_PTHPE1        equ       1                   ; Internal Pull Enable for Port H Bit 1
; bit position masks
mPTHPE_PTHPE0       equ       %00000001
mPTHPE_PTHPE1       equ       %00000010

;*** PTHSE - Port H Slew Rate Enable Register
PTHSE               equ       $000018FD           ;*** PTHSE - Port H Slew Rate Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHSE_PTHSE0        equ       0                   ; Output Slew Rate Enable for Port H Bit 0
PTHSE_PTHSE1        equ       1                   ; Output Slew Rate Enable for Port H Bit 1
; bit position masks
mPTHSE_PTHSE0       equ       %00000001
mPTHSE_PTHSE1       equ       %00000010

;*** PTHDS - Port H Drive Strength Selection Register
PTHDS               equ       $000018FE           ;*** PTHDS - Port H Drive Strength Selection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHDS_PTHDS0        equ       0                   ; Output Drive Strength Selection for Port H Bit 0
PTHDS_PTHDS1        equ       1                   ; Output Drive Strength Selection for Port H Bit 1
; bit position masks
mPTHDS_PTHDS0       equ       %00000001
mPTHDS_PTHDS1       equ       %00000010

;*** PTHIFE - Port H Input Filter Enable Register
PTHIFE              equ       $000018FF           ;*** PTHIFE - Port H Input Filter Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHIFE_PTHIFE0      equ       0                   ; Port H Input Filter Enable Bit 0
PTHIFE_PTHIFE1      equ       1                   ; Port H Input Filter Enable Bit 1
; bit position masks
mPTHIFE_PTHIFE0     equ       %00000001
mPTHIFE_PTHIFE1     equ       %00000010

;*** ADC1CV1 - Compare Value 1 Register
ADC1CV1             equ       $00001900           ;*** ADC1CV1 - Compare Value 1 Register

;*** ADC1CV1H - Compare Value 1 High Register
ADC1CV1H            equ       $00001900           ;*** ADC1CV1H - Compare Value 1 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV1H_CV18       equ       0                   ; Compare Function Value 8
ADC1CV1H_CV19       equ       1                   ; Compare Function Value 9
ADC1CV1H_CV110      equ       2                   ; Compare Function Value 10
ADC1CV1H_CV111      equ       3                   ; Compare Function Value 11
ADC1CV1H_CV112      equ       4                   ; Compare Function Value 12
ADC1CV1H_CV113      equ       5                   ; Compare Function Value 13
ADC1CV1H_CV114      equ       6                   ; Compare Function Value 14
ADC1CV1H_CV115      equ       7                   ; Compare Function Value 15
; bit position masks
mADC1CV1H_CV18      equ       %00000001
mADC1CV1H_CV19      equ       %00000010
mADC1CV1H_CV110     equ       %00000100
mADC1CV1H_CV111     equ       %00001000
mADC1CV1H_CV112     equ       %00010000
mADC1CV1H_CV113     equ       %00100000
mADC1CV1H_CV114     equ       %01000000
mADC1CV1H_CV115     equ       %10000000

;*** ADC1CV1L - Compare Value 1 Low Register
ADC1CV1L            equ       $00001901           ;*** ADC1CV1L - Compare Value 1 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV1L_CV10       equ       0                   ; Compare Function Value 0
ADC1CV1L_CV11       equ       1                   ; Compare Function Value 1
ADC1CV1L_CV12       equ       2                   ; Compare Function Value 2
ADC1CV1L_CV13       equ       3                   ; Compare Function Value 3
ADC1CV1L_CV14       equ       4                   ; Compare Function Value 4
ADC1CV1L_CV15       equ       5                   ; Compare Function Value 5
ADC1CV1L_CV16       equ       6                   ; Compare Function Value 6
ADC1CV1L_CV17       equ       7                   ; Compare Function Value 7
; bit position masks
mADC1CV1L_CV10      equ       %00000001
mADC1CV1L_CV11      equ       %00000010
mADC1CV1L_CV12      equ       %00000100
mADC1CV1L_CV13      equ       %00001000
mADC1CV1L_CV14      equ       %00010000
mADC1CV1L_CV15      equ       %00100000
mADC1CV1L_CV16      equ       %01000000
mADC1CV1L_CV17      equ       %10000000

;*** ADC1CV2 - Compare Value 2 Register
ADC1CV2             equ       $00001902           ;*** ADC1CV2 - Compare Value 2 Register

;*** ADC1CV2H - Compare Value 2 High Register
ADC1CV2H            equ       $00001902           ;*** ADC1CV2H - Compare Value 2 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV2H_CV28       equ       0                   ; Compare Function Value 8
ADC1CV2H_CV29       equ       1                   ; Compare Function Value 9
ADC1CV2H_CV210      equ       2                   ; Compare Function Value 10
ADC1CV2H_CV211      equ       3                   ; Compare Function Value 11
ADC1CV2H_CV212      equ       4                   ; Compare Function Value 12
ADC1CV2H_CV213      equ       5                   ; Compare Function Value 13
ADC1CV2H_CV214      equ       6                   ; Compare Function Value 14
ADC1CV2H_CV215      equ       7                   ; Compare Function Value 15
; bit position masks
mADC1CV2H_CV28      equ       %00000001
mADC1CV2H_CV29      equ       %00000010
mADC1CV2H_CV210     equ       %00000100
mADC1CV2H_CV211     equ       %00001000
mADC1CV2H_CV212     equ       %00010000
mADC1CV2H_CV213     equ       %00100000
mADC1CV2H_CV214     equ       %01000000
mADC1CV2H_CV215     equ       %10000000

;*** ADC1CV2L - Compare Value 2 Low Register
ADC1CV2L            equ       $00001903           ;*** ADC1CV2L - Compare Value 2 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CV2L_CV20       equ       0                   ; Compare Function Value 0
ADC1CV2L_CV21       equ       1                   ; Compare Function Value 1
ADC1CV2L_CV22       equ       2                   ; Compare Function Value 2
ADC1CV2L_CV23       equ       3                   ; Compare Function Value 3
ADC1CV2L_CV24       equ       4                   ; Compare Function Value 4
ADC1CV2L_CV25       equ       5                   ; Compare Function Value 5
ADC1CV2L_CV26       equ       6                   ; Compare Function Value 6
ADC1CV2L_CV27       equ       7                   ; Compare Function Value 7
; bit position masks
mADC1CV2L_CV20      equ       %00000001
mADC1CV2L_CV21      equ       %00000010
mADC1CV2L_CV22      equ       %00000100
mADC1CV2L_CV23      equ       %00001000
mADC1CV2L_CV24      equ       %00010000
mADC1CV2L_CV25      equ       %00100000
mADC1CV2L_CV26      equ       %01000000
mADC1CV2L_CV27      equ       %10000000

;*** ADC1SC2 - Status and Control Register 2
ADC1SC2             equ       $00001904           ;*** ADC1SC2 - Status and Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC2_REFSEL0     equ       0                   ; Voltage Reference Selection, bit 0
ADC1SC2_REFSEL1     equ       1                   ; Voltage Reference Selection, bit 1
ADC1SC2_ACREN       equ       3                   ; Compare Function Range Enable
ADC1SC2_ACFGT       equ       4                   ; Compare Function Greater Than Enable
ADC1SC2_ACFE        equ       5                   ; Compare Function Enable - ACFE is used to enable the compare function
ADC1SC2_ADTRG       equ       6                   ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADC1SC2_ADACT       equ       7                   ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a
; bit position masks
mADC1SC2_REFSEL0    equ       %00000001
mADC1SC2_REFSEL1    equ       %00000010
mADC1SC2_ACREN      equ       %00001000
mADC1SC2_ACFGT      equ       %00010000
mADC1SC2_ACFE       equ       %00100000
mADC1SC2_ADTRG      equ       %01000000
mADC1SC2_ADACT      equ       %10000000

;*** ADC1SC3 - Status and Control Register 3
ADC1SC3             equ       $00001905           ;*** ADC1SC3 - Status and Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1SC3_AVGS0       equ       0                   ; Hardware Average select, bit 0
ADC1SC3_AVGS1       equ       1                   ; Hardware Average select, bit 1
ADC1SC3_AVGE        equ       2                   ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADC1SC3_ADCO        equ       3                   ; Continuous Conversion Enable - ADCO enables continuous conversions
ADC1SC3_CALF        equ       6                   ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC1SC3_CAL         equ       7                   ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADC1SC3_AVGS0      equ       %00000001
mADC1SC3_AVGS1      equ       %00000010
mADC1SC3_AVGE       equ       %00000100
mADC1SC3_ADCO       equ       %00001000
mADC1SC3_CALF       equ       %01000000
mADC1SC3_CAL        equ       %10000000

;*** ADC1OFS - Offset Correction Register
ADC1OFS             equ       $00001906           ;*** ADC1OFS - Offset Correction Register

;*** ADC1OFSH - Offset Correction High Register
ADC1OFSH            equ       $00001906           ;*** ADC1OFSH - Offset Correction High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1OFSH_OFS8       equ       0                   ; Offset error correction value bit 8
ADC1OFSH_OFS9       equ       1                   ; Offset error correction value bit 9
ADC1OFSH_OFS10      equ       2                   ; Offset error correction value bit 10
ADC1OFSH_OFS11      equ       3                   ; Offset error correction value bit 11
ADC1OFSH_OFS12      equ       4                   ; Offset error correction value bit 12
ADC1OFSH_OFS13      equ       5                   ; Offset error correction value bit 13
ADC1OFSH_OFS14      equ       6                   ; Offset error correction value bit 14
ADC1OFSH_OFS15      equ       7                   ; Offset error correction value bit 15
; bit position masks
mADC1OFSH_OFS8      equ       %00000001
mADC1OFSH_OFS9      equ       %00000010
mADC1OFSH_OFS10     equ       %00000100
mADC1OFSH_OFS11     equ       %00001000
mADC1OFSH_OFS12     equ       %00010000
mADC1OFSH_OFS13     equ       %00100000
mADC1OFSH_OFS14     equ       %01000000
mADC1OFSH_OFS15     equ       %10000000

;*** ADC1OFSL - Offset Correction Low Register
ADC1OFSL            equ       $00001907           ;*** ADC1OFSL - Offset Correction Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1OFSL_OFS0       equ       0                   ; Offset error correction value bit 0
ADC1OFSL_OFS1       equ       1                   ; Offset error correction value bit 1
ADC1OFSL_OFS2       equ       2                   ; Offset error correction value bit 2
ADC1OFSL_OFS3       equ       3                   ; Offset error correction value bit 3
ADC1OFSL_OFS4       equ       4                   ; Offset error correction value bit 4
ADC1OFSL_OFS5       equ       5                   ; Offset error correction value bit 5
ADC1OFSL_OFS6       equ       6                   ; Offset error correction value bit 6
ADC1OFSL_OFS7       equ       7                   ; Offset error correction value bit 7
; bit position masks
mADC1OFSL_OFS0      equ       %00000001
mADC1OFSL_OFS1      equ       %00000010
mADC1OFSL_OFS2      equ       %00000100
mADC1OFSL_OFS3      equ       %00001000
mADC1OFSL_OFS4      equ       %00010000
mADC1OFSL_OFS5      equ       %00100000
mADC1OFSL_OFS6      equ       %01000000
mADC1OFSL_OFS7      equ       %10000000

;*** ADC1PG - Plus-Side Gain Register
ADC1PG              equ       $00001908           ;*** ADC1PG - Plus-Side Gain Register

;*** ADC1PGH - Plus-Side Gain High Register
ADC1PGH             equ       $00001908           ;*** ADC1PGH - Plus-Side Gain High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1PGH_PG8         equ       0                   ; Gain error correction for the plus-side input value bit 8
ADC1PGH_PG9         equ       1                   ; Gain error correction for the plus-side input value bit 9
ADC1PGH_PG10        equ       2                   ; Gain error correction for the plus-side input value bit 10
ADC1PGH_PG11        equ       3                   ; Gain error correction for the plus-side input value bit 11
ADC1PGH_PG12        equ       4                   ; Gain error correction for the plus-side input value bit 12
ADC1PGH_PG13        equ       5                   ; Gain error correction for the plus-side input value bit 13
ADC1PGH_PG14        equ       6                   ; Gain error correction for the plus-side input value bit 14
ADC1PGH_PG15        equ       7                   ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADC1PGH_PG8        equ       %00000001
mADC1PGH_PG9        equ       %00000010
mADC1PGH_PG10       equ       %00000100
mADC1PGH_PG11       equ       %00001000
mADC1PGH_PG12       equ       %00010000
mADC1PGH_PG13       equ       %00100000
mADC1PGH_PG14       equ       %01000000
mADC1PGH_PG15       equ       %10000000

;*** ADC1PGL - Plus-Side Gain Low Register
ADC1PGL             equ       $00001909           ;*** ADC1PGL - Plus-Side Gain Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1PGL_PG0         equ       0                   ; Gain error correction for the plus-side input value bit 0
ADC1PGL_PG1         equ       1                   ; Gain error correction for the plus-side input value bit 1
ADC1PGL_PG2         equ       2                   ; Gain error correction for the plus-side input value bit 2
ADC1PGL_PG3         equ       3                   ; Gain error correction for the plus-side input value bit 3
ADC1PGL_PG4         equ       4                   ; Gain error correction for the plus-side input value bit 4
ADC1PGL_PG5         equ       5                   ; Gain error correction for the plus-side input value bit 5
ADC1PGL_PG6         equ       6                   ; Gain error correction for the plus-side input value bit 6
ADC1PGL_PG7         equ       7                   ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADC1PGL_PG0        equ       %00000001
mADC1PGL_PG1        equ       %00000010
mADC1PGL_PG2        equ       %00000100
mADC1PGL_PG3        equ       %00001000
mADC1PGL_PG4        equ       %00010000
mADC1PGL_PG5        equ       %00100000
mADC1PGL_PG6        equ       %01000000
mADC1PGL_PG7        equ       %10000000

;*** ADC1MG - Minus-Side Gain Register
ADC1MG              equ       $0000190A           ;*** ADC1MG - Minus-Side Gain Register

;*** ADC1MGH - Minus-Side Gain High Register
ADC1MGH             equ       $0000190A           ;*** ADC1MGH - Minus-Side Gain High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1MGH_MG8         equ       0                   ; Gain error correction for the minus-side input value bit 8
ADC1MGH_MG9         equ       1                   ; Gain error correction for the minus-side input value bit 9
ADC1MGH_MG10        equ       2                   ; Gain error correction for the minus-side input value bit 10
ADC1MGH_MG11        equ       3                   ; Gain error correction for the minus-side input value bit 11
ADC1MGH_MG12        equ       4                   ; Gain error correction for the minus-side input value bit 12
ADC1MGH_MG13        equ       5                   ; Gain error correction for the minus-side input value bit 13
ADC1MGH_MG14        equ       6                   ; Gain error correction for the minus-side input value bit 14
ADC1MGH_MG15        equ       7                   ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADC1MGH_MG8        equ       %00000001
mADC1MGH_MG9        equ       %00000010
mADC1MGH_MG10       equ       %00000100
mADC1MGH_MG11       equ       %00001000
mADC1MGH_MG12       equ       %00010000
mADC1MGH_MG13       equ       %00100000
mADC1MGH_MG14       equ       %01000000
mADC1MGH_MG15       equ       %10000000

;*** ADC1MGL - Minus-Side Gain Low Register
ADC1MGL             equ       $0000190B           ;*** ADC1MGL - Minus-Side Gain Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1MGL_MG0         equ       0                   ; Gain error correction for the minus-side input value bit 0
ADC1MGL_MG1         equ       1                   ; Gain error correction for the minus-side input value bit 1
ADC1MGL_MG2         equ       2                   ; Gain error correction for the minus-side input value bit 2
ADC1MGL_MG3         equ       3                   ; Gain error correction for the minus-side input value bit 3
ADC1MGL_MG4         equ       4                   ; Gain error correction for the minus-side input value bit 4
ADC1MGL_MG5         equ       5                   ; Gain error correction for the minus-side input value bit 5
ADC1MGL_MG6         equ       6                   ; Gain error correction for the minus-side input value bit 6
ADC1MGL_MG7         equ       7                   ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADC1MGL_MG0        equ       %00000001
mADC1MGL_MG1        equ       %00000010
mADC1MGL_MG2        equ       %00000100
mADC1MGL_MG3        equ       %00001000
mADC1MGL_MG4        equ       %00010000
mADC1MGL_MG5        equ       %00100000
mADC1MGL_MG6        equ       %01000000
mADC1MGL_MG7        equ       %10000000

;*** ADC1CLPD - Plus-Side General Calibration Value D Register
ADC1CLPD            equ       $0000190C           ;*** ADC1CLPD - Plus-Side General Calibration Value D Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLPD_CLPD0      equ       0                   ; Plus-Side General Calibration Value D bit 0
ADC1CLPD_CLPD1      equ       1                   ; Plus-Side General Calibration Value D bit 1
ADC1CLPD_CLPD2      equ       2                   ; Plus-Side General Calibration Value D bit 2
ADC1CLPD_CLPD3      equ       3                   ; Plus-Side General Calibration Value D bit 3
ADC1CLPD_CLPD4      equ       4                   ; Plus-Side General Calibration Value D bit 4
ADC1CLPD_CLPD5      equ       5                   ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADC1CLPD_CLPD0     equ       %00000001
mADC1CLPD_CLPD1     equ       %00000010
mADC1CLPD_CLPD2     equ       %00000100
mADC1CLPD_CLPD3     equ       %00001000
mADC1CLPD_CLPD4     equ       %00010000
mADC1CLPD_CLPD5     equ       %00100000

;*** ADC1CLPS - Plus-Side General Calibration Value S Register
ADC1CLPS            equ       $0000190D           ;*** ADC1CLPS - Plus-Side General Calibration Value S Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLPS_CLPS0      equ       0                   ; Plus-Side General Calibration Value S bit 0
ADC1CLPS_CLPS1      equ       1                   ; Plus-Side General Calibration Value S bit 1
ADC1CLPS_CLPS2      equ       2                   ; Plus-Side General Calibration Value S bit 2
ADC1CLPS_CLPS3      equ       3                   ; Plus-Side General Calibration Value S bit 3
ADC1CLPS_CLPS4      equ       4                   ; Plus-Side General Calibration Value S bit 4
ADC1CLPS_CLPS5      equ       5                   ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADC1CLPS_CLPS0     equ       %00000001
mADC1CLPS_CLPS1     equ       %00000010
mADC1CLPS_CLPS2     equ       %00000100
mADC1CLPS_CLPS3     equ       %00001000
mADC1CLPS_CLPS4     equ       %00010000
mADC1CLPS_CLPS5     equ       %00100000

;*** ADC1CLP4 - Plus-Side General Calibration Value 4 Register
ADC1CLP4            equ       $0000190E           ;*** ADC1CLP4 - Plus-Side General Calibration Value 4 Register

;*** ADC1CLP4H - Plus-Side General Calibration Value 4 High Register
ADC1CLP4H           equ       $0000190E           ;*** ADC1CLP4H - Plus-Side General Calibration Value 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP4H_CLP48     equ       0                   ; Plus-Side General Calibration Value 4 bit 8
ADC1CLP4H_CLP49     equ       1                   ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADC1CLP4H_CLP48    equ       %00000001
mADC1CLP4H_CLP49    equ       %00000010

;*** ADC1CLP4L - Plus-Side General Calibration Value 4 Low Register
ADC1CLP4L           equ       $0000190F           ;*** ADC1CLP4L - Plus-Side General Calibration Value 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP4L_CLP40     equ       0                   ; Plus-Side General Calibration Value 4 bit 0
ADC1CLP4L_CLP41     equ       1                   ; Plus-Side General Calibration Value 4 bit 1
ADC1CLP4L_CLP42     equ       2                   ; Plus-Side General Calibration Value 4 bit 2
ADC1CLP4L_CLP43     equ       3                   ; Plus-Side General Calibration Value 4 bit 3
ADC1CLP4L_CLP44     equ       4                   ; Plus-Side General Calibration Value 4 bit 4
ADC1CLP4L_CLP45     equ       5                   ; Plus-Side General Calibration Value 4 bit 5
ADC1CLP4L_CLP46     equ       6                   ; Plus-Side General Calibration Value 4 bit 6
ADC1CLP4L_CLP47     equ       7                   ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADC1CLP4L_CLP40    equ       %00000001
mADC1CLP4L_CLP41    equ       %00000010
mADC1CLP4L_CLP42    equ       %00000100
mADC1CLP4L_CLP43    equ       %00001000
mADC1CLP4L_CLP44    equ       %00010000
mADC1CLP4L_CLP45    equ       %00100000
mADC1CLP4L_CLP46    equ       %01000000
mADC1CLP4L_CLP47    equ       %10000000

;*** ADC1CLP3 - Plus-Side General Calibration Value 3 Register
ADC1CLP3            equ       $00001910           ;*** ADC1CLP3 - Plus-Side General Calibration Value 3 Register

;*** ADC1CLP3H - Plus-Side General Calibration Value 3 High Register
ADC1CLP3H           equ       $00001910           ;*** ADC1CLP3H - Plus-Side General Calibration Value 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP3H_CLP38     equ       0                   ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADC1CLP3H_CLP38    equ       %00000001

;*** ADC1CLP3L - Plus-Side General Calibration Value 3 Low Register
ADC1CLP3L           equ       $00001911           ;*** ADC1CLP3L - Plus-Side General Calibration Value 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP3L_CLP30     equ       0                   ; Plus-Side General Calibration Value 3 bit 0
ADC1CLP3L_CLP31     equ       1                   ; Plus-Side General Calibration Value 3 bit 1
ADC1CLP3L_CLP32     equ       2                   ; Plus-Side General Calibration Value 3 bit 2
ADC1CLP3L_CLP33     equ       3                   ; Plus-Side General Calibration Value 3 bit 3
ADC1CLP3L_CLP34     equ       4                   ; Plus-Side General Calibration Value 3 bit 4
ADC1CLP3L_CLP35     equ       5                   ; Plus-Side General Calibration Value 3 bit 5
ADC1CLP3L_CLP36     equ       6                   ; Plus-Side General Calibration Value 3 bit 6
ADC1CLP3L_CLP37     equ       7                   ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADC1CLP3L_CLP30    equ       %00000001
mADC1CLP3L_CLP31    equ       %00000010
mADC1CLP3L_CLP32    equ       %00000100
mADC1CLP3L_CLP33    equ       %00001000
mADC1CLP3L_CLP34    equ       %00010000
mADC1CLP3L_CLP35    equ       %00100000
mADC1CLP3L_CLP36    equ       %01000000
mADC1CLP3L_CLP37    equ       %10000000

;*** ADC1CLP2 - Plus-Side General Calibration Value 2 Register
ADC1CLP2            equ       $00001912           ;*** ADC1CLP2 - Plus-Side General Calibration Value 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP2_CLP20      equ       0                   ; Plus-Side General Calibration Value 2 bit 0
ADC1CLP2_CLP21      equ       1                   ; Plus-Side General Calibration Value 2 bit 1
ADC1CLP2_CLP22      equ       2                   ; Plus-Side General Calibration Value 2 bit 2
ADC1CLP2_CLP23      equ       3                   ; Plus-Side General Calibration Value 2 bit 3
ADC1CLP2_CLP24      equ       4                   ; Plus-Side General Calibration Value 2 bit 4
ADC1CLP2_CLP25      equ       5                   ; Plus-Side General Calibration Value 2 bit 5
ADC1CLP2_CLP26      equ       6                   ; Plus-Side General Calibration Value 2 bit 6
ADC1CLP2_CLP27      equ       7                   ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADC1CLP2_CLP20     equ       %00000001
mADC1CLP2_CLP21     equ       %00000010
mADC1CLP2_CLP22     equ       %00000100
mADC1CLP2_CLP23     equ       %00001000
mADC1CLP2_CLP24     equ       %00010000
mADC1CLP2_CLP25     equ       %00100000
mADC1CLP2_CLP26     equ       %01000000
mADC1CLP2_CLP27     equ       %10000000

;*** ADC1CLP1 - Plus-Side General Calibration Value 1 Register
ADC1CLP1            equ       $00001913           ;*** ADC1CLP1 - Plus-Side General Calibration Value 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP1_CLP10      equ       0                   ; Plus-Side General Calibration Value 1 bit 0
ADC1CLP1_CLP11      equ       1                   ; Plus-Side General Calibration Value 1 bit 1
ADC1CLP1_CLP12      equ       2                   ; Plus-Side General Calibration Value 1 bit 2
ADC1CLP1_CLP13      equ       3                   ; Plus-Side General Calibration Value 1 bit 3
ADC1CLP1_CLP14      equ       4                   ; Plus-Side General Calibration Value 1 bit 4
ADC1CLP1_CLP15      equ       5                   ; Plus-Side General Calibration Value 1 bit 5
ADC1CLP1_CLP16      equ       6                   ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADC1CLP1_CLP10     equ       %00000001
mADC1CLP1_CLP11     equ       %00000010
mADC1CLP1_CLP12     equ       %00000100
mADC1CLP1_CLP13     equ       %00001000
mADC1CLP1_CLP14     equ       %00010000
mADC1CLP1_CLP15     equ       %00100000
mADC1CLP1_CLP16     equ       %01000000

;*** ADC1CLP0 - Plus-Side General Calibration Value 0 Register
ADC1CLP0            equ       $00001914           ;*** ADC1CLP0 - Plus-Side General Calibration Value 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLP0_CLP00      equ       0                   ; Plus-Side General Calibration Value 0 bit 0
ADC1CLP0_CLP01      equ       1                   ; Plus-Side General Calibration Value 0 bit 1
ADC1CLP0_CLP02      equ       2                   ; Plus-Side General Calibration Value 0 bit 2
ADC1CLP0_CLP03      equ       3                   ; Plus-Side General Calibration Value 0 bit 3
ADC1CLP0_CLP04      equ       4                   ; Plus-Side General Calibration Value 0 bit 4
ADC1CLP0_CLP05      equ       5                   ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADC1CLP0_CLP00     equ       %00000001
mADC1CLP0_CLP01     equ       %00000010
mADC1CLP0_CLP02     equ       %00000100
mADC1CLP0_CLP03     equ       %00001000
mADC1CLP0_CLP04     equ       %00010000
mADC1CLP0_CLP05     equ       %00100000

;*** ADC1CLMD - Minus-Side General Calibration Value D Register
ADC1CLMD            equ       $00001916           ;*** ADC1CLMD - Minus-Side General Calibration Value D Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLMD_CLMD0      equ       0                   ; Minus-Side General Calibration Value D bit 0
ADC1CLMD_CLMD1      equ       1                   ; Minus-Side General Calibration Value D bit 1
ADC1CLMD_CLMD2      equ       2                   ; Minus-Side General Calibration Value D bit 2
ADC1CLMD_CLMD3      equ       3                   ; Minus-Side General Calibration Value D bit 3
ADC1CLMD_CLMD4      equ       4                   ; Minus-Side General Calibration Value D bit 4
ADC1CLMD_CLMD5      equ       5                   ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADC1CLMD_CLMD0     equ       %00000001
mADC1CLMD_CLMD1     equ       %00000010
mADC1CLMD_CLMD2     equ       %00000100
mADC1CLMD_CLMD3     equ       %00001000
mADC1CLMD_CLMD4     equ       %00010000
mADC1CLMD_CLMD5     equ       %00100000

;*** ADC1CLMS - Minus-Side General Calibration Value S Register
ADC1CLMS            equ       $00001917           ;*** ADC1CLMS - Minus-Side General Calibration Value S Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLMS_CLMS0      equ       0                   ; Minus-Side General Calibration Value S bit 0
ADC1CLMS_CLMS1      equ       1                   ; Minus-Side General Calibration Value S bit 1
ADC1CLMS_CLMS2      equ       2                   ; Minus-Side General Calibration Value S bit 2
ADC1CLMS_CLMS3      equ       3                   ; Minus-Side General Calibration Value S bit 3
ADC1CLMS_CLMS4      equ       4                   ; Minus-Side General Calibration Value S bit 4
ADC1CLMS_CLMS5      equ       5                   ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADC1CLMS_CLMS0     equ       %00000001
mADC1CLMS_CLMS1     equ       %00000010
mADC1CLMS_CLMS2     equ       %00000100
mADC1CLMS_CLMS3     equ       %00001000
mADC1CLMS_CLMS4     equ       %00010000
mADC1CLMS_CLMS5     equ       %00100000

;*** ADC1CLM4 - Minus-Side General Calibration Value 4 Register
ADC1CLM4            equ       $00001918           ;*** ADC1CLM4 - Minus-Side General Calibration Value 4 Register

;*** ADC1CLM4H - Minus-Side General Calibration Value 4 High Register
ADC1CLM4H           equ       $00001918           ;*** ADC1CLM4H - Minus-Side General Calibration Value 4 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM4H_CLM48     equ       0                   ; Minus-Side General Calibration Value 4 bit 8
ADC1CLM4H_CLM49     equ       1                   ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADC1CLM4H_CLM48    equ       %00000001
mADC1CLM4H_CLM49    equ       %00000010

;*** ADC1CLM4L - Minus-Side General Calibration Value 4 Low Register
ADC1CLM4L           equ       $00001919           ;*** ADC1CLM4L - Minus-Side General Calibration Value 4 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM4L_CLM40     equ       0                   ; Minus-Side General Calibration Value 4 bit 0
ADC1CLM4L_CLM41     equ       1                   ; Minus-Side General Calibration Value 4 bit 1
ADC1CLM4L_CLM42     equ       2                   ; Minus-Side General Calibration Value 4 bit 2
ADC1CLM4L_CLM43     equ       3                   ; Minus-Side General Calibration Value 4 bit 3
ADC1CLM4L_CLM44     equ       4                   ; Minus-Side General Calibration Value 4 bit 4
ADC1CLM4L_CLM45     equ       5                   ; Minus-Side General Calibration Value 4 bit 5
ADC1CLM4L_CLM46     equ       6                   ; Minus-Side General Calibration Value 4 bit 6
ADC1CLM4L_CLM47     equ       7                   ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADC1CLM4L_CLM40    equ       %00000001
mADC1CLM4L_CLM41    equ       %00000010
mADC1CLM4L_CLM42    equ       %00000100
mADC1CLM4L_CLM43    equ       %00001000
mADC1CLM4L_CLM44    equ       %00010000
mADC1CLM4L_CLM45    equ       %00100000
mADC1CLM4L_CLM46    equ       %01000000
mADC1CLM4L_CLM47    equ       %10000000

;*** ADC1CLM3 - Minus-Side General Calibration Value 3 Register
ADC1CLM3            equ       $0000191A           ;*** ADC1CLM3 - Minus-Side General Calibration Value 3 Register

;*** ADC1CLM3H - Minus-Side General Calibration Value 3 High Register
ADC1CLM3H           equ       $0000191A           ;*** ADC1CLM3H - Minus-Side General Calibration Value 3 High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM3H_CLM38     equ       0                   ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADC1CLM3H_CLM38    equ       %00000001

;*** ADC1CLM3L - Minus-Side General Calibration Value 3 Low Register
ADC1CLM3L           equ       $0000191B           ;*** ADC1CLM3L - Minus-Side General Calibration Value 3 Low Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM3L_CLM30     equ       0                   ; Minus-Side General Calibration Value 3 bit 0
ADC1CLM3L_CLM31     equ       1                   ; Minus-Side General Calibration Value 3 bit 1
ADC1CLM3L_CLM32     equ       2                   ; Minus-Side General Calibration Value 3 bit 2
ADC1CLM3L_CLM33     equ       3                   ; Minus-Side General Calibration Value 3 bit 3
ADC1CLM3L_CLM34     equ       4                   ; Minus-Side General Calibration Value 3 bit 4
ADC1CLM3L_CLM35     equ       5                   ; Minus-Side General Calibration Value 3 bit 5
ADC1CLM3L_CLM36     equ       6                   ; Minus-Side General Calibration Value 3 bit 6
ADC1CLM3L_CLM37     equ       7                   ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADC1CLM3L_CLM30    equ       %00000001
mADC1CLM3L_CLM31    equ       %00000010
mADC1CLM3L_CLM32    equ       %00000100
mADC1CLM3L_CLM33    equ       %00001000
mADC1CLM3L_CLM34    equ       %00010000
mADC1CLM3L_CLM35    equ       %00100000
mADC1CLM3L_CLM36    equ       %01000000
mADC1CLM3L_CLM37    equ       %10000000

;*** ADC1CLM2 - Minus-Side General Calibration Value 2 Register
ADC1CLM2            equ       $0000191C           ;*** ADC1CLM2 - Minus-Side General Calibration Value 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM2_CLM20      equ       0                   ; Minus-Side General Calibration Value 2 bit 0
ADC1CLM2_CLM21      equ       1                   ; Minus-Side General Calibration Value 2 bit 1
ADC1CLM2_CLM22      equ       2                   ; Minus-Side General Calibration Value 2 bit 2
ADC1CLM2_CLM23      equ       3                   ; Minus-Side General Calibration Value 2 bit 3
ADC1CLM2_CLM24      equ       4                   ; Minus-Side General Calibration Value 2 bit 4
ADC1CLM2_CLM25      equ       5                   ; Minus-Side General Calibration Value 2 bit 5
ADC1CLM2_CLM26      equ       6                   ; Minus-Side General Calibration Value 2 bit 6
ADC1CLM2_CLM27      equ       7                   ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADC1CLM2_CLM20     equ       %00000001
mADC1CLM2_CLM21     equ       %00000010
mADC1CLM2_CLM22     equ       %00000100
mADC1CLM2_CLM23     equ       %00001000
mADC1CLM2_CLM24     equ       %00010000
mADC1CLM2_CLM25     equ       %00100000
mADC1CLM2_CLM26     equ       %01000000
mADC1CLM2_CLM27     equ       %10000000

;*** ADC1CLM1 - Minus-Side General Calibration Value 1 Register
ADC1CLM1            equ       $0000191D           ;*** ADC1CLM1 - Minus-Side General Calibration Value 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM1_CLM10      equ       0                   ; Minus-Side General Calibration Value 1 bit 0
ADC1CLM1_CLM11      equ       1                   ; Minus-Side General Calibration Value 1 bit 1
ADC1CLM1_CLM12      equ       2                   ; Minus-Side General Calibration Value 1 bit 2
ADC1CLM1_CLM13      equ       3                   ; Minus-Side General Calibration Value 1 bit 3
ADC1CLM1_CLM14      equ       4                   ; Minus-Side General Calibration Value 1 bit 4
ADC1CLM1_CLM15      equ       5                   ; Minus-Side General Calibration Value 1 bit 5
ADC1CLM1_CLM16      equ       6                   ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADC1CLM1_CLM10     equ       %00000001
mADC1CLM1_CLM11     equ       %00000010
mADC1CLM1_CLM12     equ       %00000100
mADC1CLM1_CLM13     equ       %00001000
mADC1CLM1_CLM14     equ       %00010000
mADC1CLM1_CLM15     equ       %00100000
mADC1CLM1_CLM16     equ       %01000000

;*** ADC1CLM0 - Minus-Side General Calibration Value 0 Register
ADC1CLM0            equ       $0000191E           ;*** ADC1CLM0 - Minus-Side General Calibration Value 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADC1CLM0_CLM00      equ       0                   ; Minus-Side General Calibration Value 0 bit 0
ADC1CLM0_CLM01      equ       1                   ; Minus-Side General Calibration Value 0 bit 1
ADC1CLM0_CLM02      equ       2                   ; Minus-Side General Calibration Value 0 bit 2
ADC1CLM0_CLM03      equ       3                   ; Minus-Side General Calibration Value 0 bit 3
ADC1CLM0_CLM04      equ       4                   ; Minus-Side General Calibration Value 0 bit 4
ADC1CLM0_CLM05      equ       5                   ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADC1CLM0_CLM00     equ       %00000001
mADC1CLM0_CLM01     equ       %00000010
mADC1CLM0_CLM02     equ       %00000100
mADC1CLM0_CLM03     equ       %00001000
mADC1CLM0_CLM04     equ       %00010000
mADC1CLM0_CLM05     equ       %00100000

;*** PRACMP0CS - PRACMP0 Control and Status Register
PRACMP0CS           equ       $00001924           ;*** PRACMP0CS - PRACMP0 Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP0CS_ACIEN     equ       0                   ; ACMP Interrupt Enable
PRACMP0CS_ACINTS0   equ       1                   ; ACMP Interrupt Select, bit 0
PRACMP0CS_ACINTS1   equ       2                   ; ACMP Interrupt Select, bit 1
PRACMP0CS_ACMPO     equ       3                   ; ACMP Output Bit
PRACMP0CS_ACOPE     equ       4                   ; ACMP Output Pin Enable
PRACMP0CS_ACMPF     equ       6                   ; ACMP Interrupt Flag
PRACMP0CS_ACEN      equ       7                   ; ACMP Module Enable
; bit position masks
mPRACMP0CS_ACIEN    equ       %00000001
mPRACMP0CS_ACINTS0  equ       %00000010
mPRACMP0CS_ACINTS1  equ       %00000100
mPRACMP0CS_ACMPO    equ       %00001000
mPRACMP0CS_ACOPE    equ       %00010000
mPRACMP0CS_ACMPF    equ       %01000000
mPRACMP0CS_ACEN     equ       %10000000

;*** PRACMP0C0 - PRACMP0 Control 0 Register
PRACMP0C0           equ       $00001925           ;*** PRACMP0C0 - PRACMP0 Control 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP0C0_ACNSEL0   equ       0                   ; ACMP Negative Input Select, bit 0
PRACMP0C0_ACNSEL1   equ       1                   ; ACMP Negative Input Select, bit 1
PRACMP0C0_ACNSEL2   equ       2                   ; ACMP Negative Input Select, bit 2
PRACMP0C0_PRGHWT    equ       3                   ; ACMP Hardware Trigger Select
PRACMP0C0_ACPSEL0   equ       4                   ; ACMP Positive Input Select, bit 0
PRACMP0C0_ACPSEL1   equ       5                   ; ACMP Positive Input Select, bit 1
PRACMP0C0_ACPSEL2   equ       6                   ; ACMP Positive Input Select, bit 2
PRACMP0C0_CMPHWT    equ       7                   ; PRG Hardware Trigger Select
; bit position masks
mPRACMP0C0_ACNSEL0  equ       %00000001
mPRACMP0C0_ACNSEL1  equ       %00000010
mPRACMP0C0_ACNSEL2  equ       %00000100
mPRACMP0C0_PRGHWT   equ       %00001000
mPRACMP0C0_ACPSEL0  equ       %00010000
mPRACMP0C0_ACPSEL1  equ       %00100000
mPRACMP0C0_ACPSEL2  equ       %01000000
mPRACMP0C0_CMPHWT   equ       %10000000

;*** PRACMP0C1 - PRACMP0 Control 1 Register
PRACMP0C1           equ       $00001926           ;*** PRACMP0C1 - PRACMP0 Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP0C1_PRGOS0    equ       0                   ; Programmable Reference Generator Output Selection, bit 0
PRACMP0C1_PRGOS1    equ       1                   ; Programmable Reference Generator Output Selection, bit 1
PRACMP0C1_PRGOS2    equ       2                   ; Programmable Reference Generator Output Selection, bit 2
PRACMP0C1_PRGOS3    equ       3                   ; Programmable Reference Generator Output Selection, bit 3
PRACMP0C1_PRGOS4    equ       4                   ; Programmable Reference Generator Output Selection, bit 4
PRACMP0C1_PRGINS    equ       6                   ; Programmable Reference Generator Input Selection
PRACMP0C1_PRGEN     equ       7                   ; Programmable Reference Generator Enable
; bit position masks
mPRACMP0C1_PRGOS0   equ       %00000001
mPRACMP0C1_PRGOS1   equ       %00000010
mPRACMP0C1_PRGOS2   equ       %00000100
mPRACMP0C1_PRGOS3   equ       %00001000
mPRACMP0C1_PRGOS4   equ       %00010000
mPRACMP0C1_PRGINS   equ       %01000000
mPRACMP0C1_PRGEN    equ       %10000000

;*** PRACMP0C2 - PRACMP0 Control 2 Register
PRACMP0C2           equ       $00001927           ;*** PRACMP0C2 - PRACMP0 Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP0C2_ACIPE0    equ       0                   ; ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0
PRACMP0C2_ACIPE1    equ       1                   ; ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1
PRACMP0C2_ACIPE2    equ       2                   ; ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2
PRACMP0C2_ACIPE3    equ       3                   ; ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3
PRACMP0C2_ACIPE4    equ       4                   ; ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4
PRACMP0C2_ACIPE5    equ       5                   ; ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5
PRACMP0C2_ACIPE6    equ       6                   ; ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6
; bit position masks
mPRACMP0C2_ACIPE0   equ       %00000001
mPRACMP0C2_ACIPE1   equ       %00000010
mPRACMP0C2_ACIPE2   equ       %00000100
mPRACMP0C2_ACIPE3   equ       %00001000
mPRACMP0C2_ACIPE4   equ       %00010000
mPRACMP0C2_ACIPE5   equ       %00100000
mPRACMP0C2_ACIPE6   equ       %01000000

;*** PRACMP1CS - PRACMP1 Control and Status Register
PRACMP1CS           equ       $00001928           ;*** PRACMP1CS - PRACMP1 Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1CS_ACIEN     equ       0                   ; ACMP Interrupt Enable
PRACMP1CS_ACINTS0   equ       1                   ; ACMP Interrupt Select, bit 0
PRACMP1CS_ACINTS1   equ       2                   ; ACMP Interrupt Select, bit 1
PRACMP1CS_ACMPO     equ       3                   ; ACMP Output Bit
PRACMP1CS_ACOPE     equ       4                   ; ACMP Output Pin Enable
PRACMP1CS_ACMPF     equ       6                   ; ACMP Interrupt Flag
PRACMP1CS_ACEN      equ       7                   ; ACMP Module Enable
; bit position masks
mPRACMP1CS_ACIEN    equ       %00000001
mPRACMP1CS_ACINTS0  equ       %00000010
mPRACMP1CS_ACINTS1  equ       %00000100
mPRACMP1CS_ACMPO    equ       %00001000
mPRACMP1CS_ACOPE    equ       %00010000
mPRACMP1CS_ACMPF    equ       %01000000
mPRACMP1CS_ACEN     equ       %10000000

;*** PRACMP1C0 - PRACMP1 Control 0 Register
PRACMP1C0           equ       $00001929           ;*** PRACMP1C0 - PRACMP1 Control 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1C0_ACNSEL0   equ       0                   ; ACMP Negative Input Select, bit 0
PRACMP1C0_ACNSEL1   equ       1                   ; ACMP Negative Input Select, bit 1
PRACMP1C0_ACNSEL2   equ       2                   ; ACMP Negative Input Select, bit 2
PRACMP1C0_PRGHWT    equ       3                   ; ACMP Hardware Trigger Select
PRACMP1C0_ACPSEL0   equ       4                   ; ACMP Positive Input Select, bit 0
PRACMP1C0_ACPSEL1   equ       5                   ; ACMP Positive Input Select, bit 1
PRACMP1C0_ACPSEL2   equ       6                   ; ACMP Positive Input Select, bit 2
PRACMP1C0_CMPHWT    equ       7                   ; PRG Hardware Trigger Select
; bit position masks
mPRACMP1C0_ACNSEL0  equ       %00000001
mPRACMP1C0_ACNSEL1  equ       %00000010
mPRACMP1C0_ACNSEL2  equ       %00000100
mPRACMP1C0_PRGHWT   equ       %00001000
mPRACMP1C0_ACPSEL0  equ       %00010000
mPRACMP1C0_ACPSEL1  equ       %00100000
mPRACMP1C0_ACPSEL2  equ       %01000000
mPRACMP1C0_CMPHWT   equ       %10000000

;*** PRACMP1C1 - PRACMP1 Control 1 Register
PRACMP1C1           equ       $0000192A           ;*** PRACMP1C1 - PRACMP1 Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1C1_PRGOS0    equ       0                   ; Programmable Reference Generator Output Selection, bit 0
PRACMP1C1_PRGOS1    equ       1                   ; Programmable Reference Generator Output Selection, bit 1
PRACMP1C1_PRGOS2    equ       2                   ; Programmable Reference Generator Output Selection, bit 2
PRACMP1C1_PRGOS3    equ       3                   ; Programmable Reference Generator Output Selection, bit 3
PRACMP1C1_PRGOS4    equ       4                   ; Programmable Reference Generator Output Selection, bit 4
PRACMP1C1_PRGINS    equ       6                   ; Programmable Reference Generator Input Selection
PRACMP1C1_PRGEN     equ       7                   ; Programmable Reference Generator Enable
; bit position masks
mPRACMP1C1_PRGOS0   equ       %00000001
mPRACMP1C1_PRGOS1   equ       %00000010
mPRACMP1C1_PRGOS2   equ       %00000100
mPRACMP1C1_PRGOS3   equ       %00001000
mPRACMP1C1_PRGOS4   equ       %00010000
mPRACMP1C1_PRGINS   equ       %01000000
mPRACMP1C1_PRGEN    equ       %10000000

;*** PRACMP1C2 - PRACMP1 Control 2 Register
PRACMP1C2           equ       $0000192B           ;*** PRACMP1C2 - PRACMP1 Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP1C2_ACIPE0    equ       0                   ; ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0
PRACMP1C2_ACIPE1    equ       1                   ; ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1
PRACMP1C2_ACIPE2    equ       2                   ; ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2
PRACMP1C2_ACIPE3    equ       3                   ; ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3
PRACMP1C2_ACIPE4    equ       4                   ; ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4
PRACMP1C2_ACIPE5    equ       5                   ; ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5
PRACMP1C2_ACIPE6    equ       6                   ; ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6
; bit position masks
mPRACMP1C2_ACIPE0   equ       %00000001
mPRACMP1C2_ACIPE1   equ       %00000010
mPRACMP1C2_ACIPE2   equ       %00000100
mPRACMP1C2_ACIPE3   equ       %00001000
mPRACMP1C2_ACIPE4   equ       %00010000
mPRACMP1C2_ACIPE5   equ       %00100000
mPRACMP1C2_ACIPE6   equ       %01000000

;*** PRACMP2CS - PRACMP2 Control and Status Register
PRACMP2CS           equ       $0000192C           ;*** PRACMP2CS - PRACMP2 Control and Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2CS_ACIEN     equ       0                   ; ACMP Interrupt Enable
PRACMP2CS_ACINTS0   equ       1                   ; ACMP Interrupt Select, bit 0
PRACMP2CS_ACINTS1   equ       2                   ; ACMP Interrupt Select, bit 1
PRACMP2CS_ACMPO     equ       3                   ; ACMP Output Bit
PRACMP2CS_ACOPE     equ       4                   ; ACMP Output Pin Enable
PRACMP2CS_ACMPF     equ       6                   ; ACMP Interrupt Flag
PRACMP2CS_ACEN      equ       7                   ; ACMP Module Enable
; bit position masks
mPRACMP2CS_ACIEN    equ       %00000001
mPRACMP2CS_ACINTS0  equ       %00000010
mPRACMP2CS_ACINTS1  equ       %00000100
mPRACMP2CS_ACMPO    equ       %00001000
mPRACMP2CS_ACOPE    equ       %00010000
mPRACMP2CS_ACMPF    equ       %01000000
mPRACMP2CS_ACEN     equ       %10000000

;*** PRACMP2C0 - PRACMP2 Control 0 Register
PRACMP2C0           equ       $0000192D           ;*** PRACMP2C0 - PRACMP2 Control 0 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2C0_ACNSEL0   equ       0                   ; ACMP Negative Input Select, bit 0
PRACMP2C0_ACNSEL1   equ       1                   ; ACMP Negative Input Select, bit 1
PRACMP2C0_ACNSEL2   equ       2                   ; ACMP Negative Input Select, bit 2
PRACMP2C0_PRGHWT    equ       3                   ; ACMP Hardware Trigger Select
PRACMP2C0_ACPSEL0   equ       4                   ; ACMP Positive Input Select, bit 0
PRACMP2C0_ACPSEL1   equ       5                   ; ACMP Positive Input Select, bit 1
PRACMP2C0_ACPSEL2   equ       6                   ; ACMP Positive Input Select, bit 2
PRACMP2C0_CMPHWT    equ       7                   ; PRG Hardware Trigger Select
; bit position masks
mPRACMP2C0_ACNSEL0  equ       %00000001
mPRACMP2C0_ACNSEL1  equ       %00000010
mPRACMP2C0_ACNSEL2  equ       %00000100
mPRACMP2C0_PRGHWT   equ       %00001000
mPRACMP2C0_ACPSEL0  equ       %00010000
mPRACMP2C0_ACPSEL1  equ       %00100000
mPRACMP2C0_ACPSEL2  equ       %01000000
mPRACMP2C0_CMPHWT   equ       %10000000

;*** PRACMP2C1 - PRACMP2 Control 1 Register
PRACMP2C1           equ       $0000192E           ;*** PRACMP2C1 - PRACMP2 Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2C1_PRGOS0    equ       0                   ; Programmable Reference Generator Output Selection, bit 0
PRACMP2C1_PRGOS1    equ       1                   ; Programmable Reference Generator Output Selection, bit 1
PRACMP2C1_PRGOS2    equ       2                   ; Programmable Reference Generator Output Selection, bit 2
PRACMP2C1_PRGOS3    equ       3                   ; Programmable Reference Generator Output Selection, bit 3
PRACMP2C1_PRGOS4    equ       4                   ; Programmable Reference Generator Output Selection, bit 4
PRACMP2C1_PRGINS    equ       6                   ; Programmable Reference Generator Input Selection
PRACMP2C1_PRGEN     equ       7                   ; Programmable Reference Generator Enable
; bit position masks
mPRACMP2C1_PRGOS0   equ       %00000001
mPRACMP2C1_PRGOS1   equ       %00000010
mPRACMP2C1_PRGOS2   equ       %00000100
mPRACMP2C1_PRGOS3   equ       %00001000
mPRACMP2C1_PRGOS4   equ       %00010000
mPRACMP2C1_PRGINS   equ       %01000000
mPRACMP2C1_PRGEN    equ       %10000000

;*** PRACMP2C2 - PRACMP2 Control 2 Register
PRACMP2C2           equ       $0000192F           ;*** PRACMP2C2 - PRACMP2 Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PRACMP2C2_ACIPE0    equ       0                   ; ACMP Input Pin 0 Enable - ACIPE0 is used to control the PRACMP external pin 0
PRACMP2C2_ACIPE1    equ       1                   ; ACMP Input Pin 1 Enable - ACIPE1 is used to control the PRACMP external pin 1
PRACMP2C2_ACIPE2    equ       2                   ; ACMP Input Pin 2 Enable - ACIPE2 is used to control the PRACMP external pin 2
PRACMP2C2_ACIPE3    equ       3                   ; ACMP Input Pin 3 Enable - ACIPE3 is used to control the PRACMP external pin 3
PRACMP2C2_ACIPE4    equ       4                   ; ACMP Input Pin 4 Enable - ACIPE4 is used to control the PRACMP external pin 4
PRACMP2C2_ACIPE5    equ       5                   ; ACMP Input Pin 5 Enable - ACIPE5 is used to control the PRACMP external pin 5
PRACMP2C2_ACIPE6    equ       6                   ; ACMP Input Pin 6 Enable - ACIPE6 is used to control the PRACMP external pin 6
; bit position masks
mPRACMP2C2_ACIPE0   equ       %00000001
mPRACMP2C2_ACIPE1   equ       %00000010
mPRACMP2C2_ACIPE2   equ       %00000100
mPRACMP2C2_ACIPE3   equ       %00001000
mPRACMP2C2_ACIPE4   equ       %00010000
mPRACMP2C2_ACIPE5   equ       %00100000
mPRACMP2C2_ACIPE6   equ       %01000000

;*** VREFTRM - VREF Trim Register
VREFTRM             equ       $00001930           ;*** VREFTRM - VREF Trim Register
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
VREFSC              equ       $00001931           ;*** VREFSC - VREF Control Register
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

;*** PTAPF1 - Port A Routing Register 1
PTAPF1              equ       $00001940           ;*** PTAPF1 - Port A Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPF1_A0           equ       0                   ; Port PTA0 Pin Mux Controls
PTAPF1_A1           equ       4                   ; Port PTA1 Pin Mux Controls
; bit position masks
mPTAPF1_A0          equ       %00000111
mPTAPF1_A1          equ       %01110000

;*** PTAPF2 - Port A Routing Register 2
PTAPF2              equ       $00001941           ;*** PTAPF2 - Port A Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPF2_A2           equ       0                   ; Port PTA2 Pin Mux Controls
PTAPF2_A3           equ       4                   ; Port PTA3 Pin Mux Controls
; bit position masks
mPTAPF2_A2          equ       %00000111
mPTAPF2_A3          equ       %01110000

;*** PTAPF3 - Port A Routing Register 3
PTAPF3              equ       $00001942           ;*** PTAPF3 - Port A Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPF3_A4           equ       0                   ; Port PTA4 Pin Mux Controls
PTAPF3_A5           equ       4                   ; Port PTA5 Pin Mux Controls
; bit position masks
mPTAPF3_A4          equ       %00000111
mPTAPF3_A5          equ       %01110000

;*** PTAPF4 - Port A Routing Register 4
PTAPF4              equ       $00001943           ;*** PTAPF4 - Port A Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPF4_A6           equ       0                   ; Port PTA6 Pin Mux Controls
; bit position masks
mPTAPF4_A6          equ       %00000111

;*** PTBPF1 - Port B Routing Register 1
PTBPF1              equ       $00001944           ;*** PTBPF1 - Port B Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPF1_B0           equ       0                   ; Port PTB0 Pin Mux Controls
PTBPF1_B1           equ       4                   ; Port PTB1 Pin Mux Controls
; bit position masks
mPTBPF1_B0          equ       %00000111
mPTBPF1_B1          equ       %01110000

;*** PTBPF2 - Port B Routing Register 2
PTBPF2              equ       $00001945           ;*** PTBPF2 - Port B Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPF2_B2           equ       0                   ; Port PTB2 Pin Mux Controls
PTBPF2_B3           equ       4                   ; Port PTB3 Pin Mux Controls
; bit position masks
mPTBPF2_B2          equ       %00000111
mPTBPF2_B3          equ       %01110000

;*** PTBPF3 - Port B Routing Register 3
PTBPF3              equ       $00001946           ;*** PTBPF3 - Port B Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPF3_B4           equ       0                   ; Port PTB4 Pin Mux Controls
PTBPF3_B5           equ       4                   ; Port PTB5 Pin Mux Controls
; bit position masks
mPTBPF3_B4          equ       %00000111
mPTBPF3_B5          equ       %01110000

;*** PTBPF4 - Port B Routing Register 4
PTBPF4              equ       $00001947           ;*** PTBPF4 - Port B Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPF4_B6           equ       0                   ; Port PTB6 Pin Mux Controls
PTBPF4_B7           equ       4                   ; Port PTB7 Pin Mux Controls
; bit position masks
mPTBPF4_B6          equ       %00000111
mPTBPF4_B7          equ       %01110000

;*** PTCPF1 - Port C Routing Register 1
PTCPF1              equ       $00001948           ;*** PTCPF1 - Port C Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPF1_C0           equ       0                   ; Port PTC0 Pin Mux Controls
PTCPF1_C1           equ       4                   ; Port PTC1 Pin Mux Controls
; bit position masks
mPTCPF1_C0          equ       %00000111
mPTCPF1_C1          equ       %01110000

;*** PTCPF2 - Port C Routing Register 2
PTCPF2              equ       $00001949           ;*** PTCPF2 - Port C Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPF2_C2           equ       0                   ; Port PTC2 Pin Mux Controls
PTCPF2_C3           equ       4                   ; Port PTC3 Pin Mux Controls
; bit position masks
mPTCPF2_C2          equ       %00000111
mPTCPF2_C3          equ       %01110000

;*** PTCPF3 - Port C Routing Register 3
PTCPF3              equ       $0000194A           ;*** PTCPF3 - Port C Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPF3_C4           equ       0                   ; Port PTC4 Pin Mux Controls
PTCPF3_C5           equ       4                   ; Port PTC5 Pin Mux Controls
; bit position masks
mPTCPF3_C4          equ       %00000111
mPTCPF3_C5          equ       %01110000

;*** PTCPF4 - Port C Routing Register 4
PTCPF4              equ       $0000194B           ;*** PTCPF4 - Port C Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPF4_C6           equ       0                   ; Port PTC6 Pin Mux Controls
PTCPF4_C7           equ       4                   ; Port PTC7 Pin Mux Controls
; bit position masks
mPTCPF4_C6          equ       %00000111
mPTCPF4_C7          equ       %01110000

;*** PTDPF1 - Port D Routing Register 1
PTDPF1              equ       $0000194C           ;*** PTDPF1 - Port D Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPF1_D0           equ       0                   ; Port PTD0 Pin Mux Controls
PTDPF1_D1           equ       4                   ; Port PTD1 Pin Mux Controls
; bit position masks
mPTDPF1_D0          equ       %00000111
mPTDPF1_D1          equ       %01110000

;*** PTDPF2 - Port D Routing Register 2
PTDPF2              equ       $0000194D           ;*** PTDPF2 - Port D Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPF2_D2           equ       0                   ; Port PTD2 Pin Mux Controls
PTDPF2_D3           equ       4                   ; Port PTD3 Pin Mux Controls
; bit position masks
mPTDPF2_D2          equ       %00000111
mPTDPF2_D3          equ       %01110000

;*** PTDPF3 - Port D Routing Register 3
PTDPF3              equ       $0000194E           ;*** PTDPF3 - Port D Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPF3_D4           equ       0                   ; Port PTD4 Pin Mux Controls
PTDPF3_D5           equ       4                   ; Port PTD5 Pin Mux Controls
; bit position masks
mPTDPF3_D4          equ       %00000111
mPTDPF3_D5          equ       %01110000

;*** PTDPF4 - Port D Routing Register 4
PTDPF4              equ       $0000194F           ;*** PTDPF4 - Port D Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPF4_D6           equ       0                   ; Port PTD6 Pin Mux Controls
PTDPF4_D7           equ       4                   ; Port PTD7 Pin Mux Controls
; bit position masks
mPTDPF4_D6          equ       %00000111
mPTDPF4_D7          equ       %01110000

;*** PTEPF1 - Port E Routing Register 1
PTEPF1              equ       $00001950           ;*** PTEPF1 - Port E Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPF1_E0           equ       0                   ; Port PTE0 Pin Mux Controls
PTEPF1_E1           equ       4                   ; Port PTE1 Pin Mux Controls
; bit position masks
mPTEPF1_E0          equ       %00000111
mPTEPF1_E1          equ       %01110000

;*** PTEPF2 - Port E Routing Register 2
PTEPF2              equ       $00001951           ;*** PTEPF2 - Port E Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPF2_E2           equ       0                   ; Port PTE2 Pin Mux Controls
PTEPF2_E3           equ       4                   ; Port PTE3 Pin Mux Controls
; bit position masks
mPTEPF2_E2          equ       %00000111
mPTEPF2_E3          equ       %01110000

;*** PTEPF3 - Port E Routing Register 3
PTEPF3              equ       $00001952           ;*** PTEPF3 - Port E Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPF3_E4           equ       0                   ; Port PTE4 Pin Mux Controls
PTEPF3_E5           equ       4                   ; Port PTE5 Pin Mux Controls
; bit position masks
mPTEPF3_E4          equ       %00000111
mPTEPF3_E5          equ       %01110000

;*** PTEPF4 - Port E Routing Register 4
PTEPF4              equ       $00001953           ;*** PTEPF4 - Port E Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPF4_E6           equ       0                   ; Port PTE6 Pin Mux Controls
PTEPF4_E7           equ       4                   ; Port PTE7 Pin Mux Controls
; bit position masks
mPTEPF4_E6          equ       %00000111
mPTEPF4_E7          equ       %01110000

;*** PTFPF1 - Port F Routing Register 1
PTFPF1              equ       $00001954           ;*** PTFPF1 - Port F Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPF1_F0           equ       0                   ; Port PTF0 Pin Mux Controls
PTFPF1_F1           equ       4                   ; Port PTF1 Pin Mux Controls
; bit position masks
mPTFPF1_F0          equ       %00000111
mPTFPF1_F1          equ       %01110000

;*** PTFPF2 - Port F Routing Register 2
PTFPF2              equ       $00001955           ;*** PTFPF2 - Port F Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPF2_F2           equ       0                   ; Port PTF2 Pin Mux Controls
PTFPF2_F3           equ       4                   ; Port PTF3 Pin Mux Controls
; bit position masks
mPTFPF2_F2          equ       %00000111
mPTFPF2_F3          equ       %01110000

;*** PTFPF3 - Port F Routing Register 3
PTFPF3              equ       $00001956           ;*** PTFPF3 - Port F Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPF3_F4           equ       0                   ; Port PTF4 Pin Mux Controls
PTFPF3_F5           equ       4                   ; Port PTF5 Pin Mux Controls
; bit position masks
mPTFPF3_F4          equ       %00000111
mPTFPF3_F5          equ       %01110000

;*** PTFPF4 - Port F Routing Register 4
PTFPF4              equ       $00001957           ;*** PTFPF4 - Port F Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPF4_F6           equ       0                   ; Port PTF6 Pin Mux Controls
PTFPF4_F7           equ       4                   ; Port PTF7 Pin Mux Controls
; bit position masks
mPTFPF4_F6          equ       %00000111
mPTFPF4_F7          equ       %01110000

;*** PTGPF1 - Port G Routing Register 1
PTGPF1              equ       $00001958           ;*** PTGPF1 - Port G Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPF1_G0           equ       0                   ; Port PTG0 Pin Mux Controls
PTGPF1_G1           equ       4                   ; Port PTG1 Pin Mux Controls
; bit position masks
mPTGPF1_G0          equ       %00000111
mPTGPF1_G1          equ       %01110000

;*** PTGPF2 - Port G Routing Register 2
PTGPF2              equ       $00001959           ;*** PTGPF2 - Port G Routing Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPF2_G2           equ       0                   ; Port PTG2 Pin Mux Controls
PTGPF2_G3           equ       4                   ; Port PTG3 Pin Mux Controls
; bit position masks
mPTGPF2_G2          equ       %00000111
mPTGPF2_G3          equ       %01110000

;*** PTGPF3 - Port G Routing Register 3
PTGPF3              equ       $0000195A           ;*** PTGPF3 - Port G Routing Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPF3_G4           equ       0                   ; Port PTG4 Pin Mux Controls
PTGPF3_G5           equ       4                   ; Port PTG5 Pin Mux Controls
; bit position masks
mPTGPF3_G4          equ       %00000111
mPTGPF3_G5          equ       %01110000

;*** PTGPF4 - Port G Routing Register 4
PTGPF4              equ       $0000195B           ;*** PTGPF4 - Port G Routing Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPF4_G6           equ       0                   ; Port PTG6 Pin Mux Controls
PTGPF4_G7           equ       4                   ; Port PTG7 Pin Mux Controls
; bit position masks
mPTGPF4_G6          equ       %00000111
mPTGPF4_G7          equ       %01110000

;*** PTHPF1 - Port H Routing Register 1
PTHPF1              equ       $0000195C           ;*** PTHPF1 - Port H Routing Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTHPF1_H0           equ       0                   ; Port PTH0 Pin Mux Controls
PTHPF1_H1           equ       4                   ; Port PTH1 Pin Mux Controls
; bit position masks
mPTHPF1_H0          equ       %00000111
mPTHPF1_H1          equ       %01110000

;*** NVVREFTRM - Non-volatile VREF Trim Register
NVVREFTRM           equ       $0000FFAD           ;*** NVVREFTRM - Non-volatile VREF Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVVREFTRM_TRM0      equ       0                   ; Trim Bit 0, bit 0
NVVREFTRM_TRM1      equ       1                   ; Trim Bit 0, bit 1
NVVREFTRM_TRM2      equ       2                   ; Trim Bit 0, bit 2
NVVREFTRM_TRM3      equ       3                   ; Trim Bit 0, bit 3
NVVREFTRM_TRM4      equ       4                   ; Trim Bit 0, bit 4
NVVREFTRM_TRM5      equ       5                   ; Trim Bit 0, bit 5
NVVREFTRM_TRM6      equ       6                   ; Trim Bit 0, bit 6
NVVREFTRM_TRM7      equ       7                   ; Trim Bit 0, bit 7
; bit position masks
mNVVREFTRM_TRM0     equ       %00000001
mNVVREFTRM_TRM1     equ       %00000010
mNVVREFTRM_TRM2     equ       %00000100
mNVVREFTRM_TRM3     equ       %00001000
mNVVREFTRM_TRM4     equ       %00010000
mNVVREFTRM_TRM5     equ       %00100000
mNVVREFTRM_TRM6     equ       %01000000
mNVVREFTRM_TRM7     equ       %10000000

;*** NVFTRIM - Non-volatile ICS Fine Trim
NVFTRIM             equ       $0000FFAE           ;*** NVFTRIM - Non-volatile ICS Fine Trim
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFTRIM_FTRIM       equ       0                   ; ICS Fine Trim
; bit position masks
mNVFTRIM_FTRIM      equ       %00000001

;*** NVICSTRM - Non-volatile ICS Trim Register
NVICSTRM            equ       $0000FFAF           ;*** NVICSTRM - Non-volatile ICS Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVICSTRM_TRIM0      equ       0                   ; ICS Trim Setting, bit 0
NVICSTRM_TRIM1      equ       1                   ; ICS Trim Setting, bit 1
NVICSTRM_TRIM2      equ       2                   ; ICS Trim Setting, bit 2
NVICSTRM_TRIM3      equ       3                   ; ICS Trim Setting, bit 3
NVICSTRM_TRIM4      equ       4                   ; ICS Trim Setting, bit 4
NVICSTRM_TRIM5      equ       5                   ; ICS Trim Setting, bit 5
NVICSTRM_TRIM6      equ       6                   ; ICS Trim Setting, bit 6
NVICSTRM_TRIM7      equ       7                   ; ICS Trim Setting, bit 7
; bit position masks
mNVICSTRM_TRIM0     equ       %00000001
mNVICSTRM_TRIM1     equ       %00000010
mNVICSTRM_TRIM2     equ       %00000100
mNVICSTRM_TRIM3     equ       %00001000
mNVICSTRM_TRIM4     equ       %00010000
mNVICSTRM_TRIM5     equ       %00100000
mNVICSTRM_TRIM6     equ       %01000000
mNVICSTRM_TRIM7     equ       %10000000

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

;*** NVPROT - Non-volatile Flash Protection Register
NVPROT              equ       $0000FFBD           ;*** NVPROT - Non-volatile Flash Protection Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPDIS        equ       0                   ; Flash Protection Disable
NVPROT_FPS0         equ       1                   ; Flash Protection Size, bit 0
NVPROT_FPS1         equ       2                   ; Flash Protection Size, bit 1
NVPROT_FPS2         equ       3                   ; Flash Protection Size, bit 2
NVPROT_FPS3         equ       4                   ; Flash Protection Size, bit 3
NVPROT_FPS4         equ       5                   ; Flash Protection Size, bit 4
NVPROT_FPS5         equ       6                   ; Flash Protection Size, bit 5
NVPROT_FPS6         equ       7                   ; Flash Protection Size, bit 6
; bit position masks
mNVPROT_FPDIS       equ       %00000001
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
NVOPT_FNORED        equ       6                   ; Vector Redirection Disable
NVOPT_KEYEN         equ       7                   ; Backdoor Key Security Enable
; bit position masks
mNVOPT_SEC0         equ       %00000001
mNVOPT_SEC1         equ       %00000010
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
