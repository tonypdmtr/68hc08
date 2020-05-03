;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC9S08GB60A, version 2.87.214 (RegistersPrg V2.32)

; ###################################################################
;     Filename  : mc9s08gb32a.inc
;     Processor : MC9S08GB32ACFU
;     FileFormat: V2.32
;     DataSheet : MC9S08GB60A Rev. 1.00 08/2005
;     Compiler  : CodeWarrior compiler
;     Date/Time : 5.10.2010, 13:39
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;      - 23.02.2006, V2.87.175:
;              - Renamed bits IIC1A_ADDR0..6 ==> IIC1A_ADDR1..7 REASON: Bug-fix (#3047 in Issue Manager)
;      - 11.04.2006, V2.87.182:
;              - Renamed bits IIC1A_ADDR0..6 ==> IIC1A_ADDR1..7 REASON: Bug-fix (#3047 in Issue Manager)
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
ROM                 equ       $00008000
ROM_END             equ       $0000FFAF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $0000087F
XROM                equ       $0000FFC0
XROM_END            equ       $0000FFCB
;
Vrti                equ       $0000FFCC
Viic1               equ       $0000FFCE
Vatd1               equ       $0000FFD0
Vkeyboard1          equ       $0000FFD2
Vsci2tx             equ       $0000FFD4
Vsci2rx             equ       $0000FFD6
Vsci2err            equ       $0000FFD8
Vsci1tx             equ       $0000FFDA
Vsci1rx             equ       $0000FFDC
Vsci1err            equ       $0000FFDE
Vspi1               equ       $0000FFE0
Vtpm2ovf            equ       $0000FFE2
Vtpm2ch4            equ       $0000FFE4
Vtpm2ch3            equ       $0000FFE6
Vtpm2ch2            equ       $0000FFE8
Vtpm2ch1            equ       $0000FFEA
Vtpm2ch0            equ       $0000FFEC
Vtpm1ovf            equ       $0000FFEE
Vtpm1ch2            equ       $0000FFF0
Vtpm1ch1            equ       $0000FFF2
Vtpm1ch0            equ       $0000FFF4
Vicg                equ       $0000FFF6
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


;*** PTAPE - Pullup Enable for Port A
PTAPE               equ       $00000001           ;*** PTAPE - Pullup Enable for Port A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0        equ       0                   ; Pullup Enable for Port A Bit 0
PTAPE_PTAPE1        equ       1                   ; Pullup Enable for Port A Bit 1
PTAPE_PTAPE2        equ       2                   ; Pullup Enable for Port A Bit 2
PTAPE_PTAPE3        equ       3                   ; Pullup Enable for Port A Bit 3
PTAPE_PTAPE4        equ       4                   ; Pullup Enable for Port A Bit 4
PTAPE_PTAPE5        equ       5                   ; Pullup Enable for Port A Bit 5
PTAPE_PTAPE6        equ       6                   ; Pullup Enable for Port A Bit 6
PTAPE_PTAPE7        equ       7                   ; Pullup Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0       equ       %00000001
mPTAPE_PTAPE1       equ       %00000010
mPTAPE_PTAPE2       equ       %00000100
mPTAPE_PTAPE3       equ       %00001000
mPTAPE_PTAPE4       equ       %00010000
mPTAPE_PTAPE5       equ       %00100000
mPTAPE_PTAPE6       equ       %01000000
mPTAPE_PTAPE7       equ       %10000000


;*** PTASE - Slew Rate Control Enable for Port A
PTASE               equ       $00000002           ;*** PTASE - Slew Rate Control Enable for Port A
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0        equ       0                   ; Slew Rate Control Enable for Port A Bit 0
PTASE_PTASE1        equ       1                   ; Slew Rate Control Enable for Port A Bit 1
PTASE_PTASE2        equ       2                   ; Slew Rate Control Enable for Port A Bit 2
PTASE_PTASE3        equ       3                   ; Slew Rate Control Enable for Port A Bit 3
PTASE_PTASE4        equ       4                   ; Slew Rate Control Enable for Port A Bit 4
PTASE_PTASE5        equ       5                   ; Slew Rate Control Enable for Port A Bit 5
PTASE_PTASE6        equ       6                   ; Slew Rate Control Enable for Port A Bit 6
PTASE_PTASE7        equ       7                   ; Slew Rate Control Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0       equ       %00000001
mPTASE_PTASE1       equ       %00000010
mPTASE_PTASE2       equ       %00000100
mPTASE_PTASE3       equ       %00001000
mPTASE_PTASE4       equ       %00010000
mPTASE_PTASE5       equ       %00100000
mPTASE_PTASE6       equ       %01000000
mPTASE_PTASE7       equ       %10000000


;*** PTADD - Data Direction Register A
PTADD               equ       $00000003           ;*** PTADD - Data Direction Register A
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
PTBD                equ       $00000004           ;*** PTBD - Port B Data Register
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


;*** PTBPE - Pullup Enable for Port B
PTBPE               equ       $00000005           ;*** PTBPE - Pullup Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0        equ       0                   ; Pullup Enable for Port B Bit 0
PTBPE_PTBPE1        equ       1                   ; Pullup Enable for Port B Bit 1
PTBPE_PTBPE2        equ       2                   ; Pullup Enable for Port B Bit 2
PTBPE_PTBPE3        equ       3                   ; Pullup Enable for Port B Bit 3
PTBPE_PTBPE4        equ       4                   ; Pullup Enable for Port B Bit 4
PTBPE_PTBPE5        equ       5                   ; Pullup Enable for Port B Bit 5
PTBPE_PTBPE6        equ       6                   ; Pullup Enable for Port B Bit 6
PTBPE_PTBPE7        equ       7                   ; Pullup Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0       equ       %00000001
mPTBPE_PTBPE1       equ       %00000010
mPTBPE_PTBPE2       equ       %00000100
mPTBPE_PTBPE3       equ       %00001000
mPTBPE_PTBPE4       equ       %00010000
mPTBPE_PTBPE5       equ       %00100000
mPTBPE_PTBPE6       equ       %01000000
mPTBPE_PTBPE7       equ       %10000000


;*** PTBSE - Slew Rate Control Enable for Port B
PTBSE               equ       $00000006           ;*** PTBSE - Slew Rate Control Enable for Port B
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0        equ       0                   ; Slew Rate Control Enable for Port B Bit 0
PTBSE_PTBSE1        equ       1                   ; Slew Rate Control Enable for Port B Bit 1
PTBSE_PTBSE2        equ       2                   ; Slew Rate Control Enable for Port B Bit 2
PTBSE_PTBSE3        equ       3                   ; Slew Rate Control Enable for Port B Bit 3
PTBSE_PTBSE4        equ       4                   ; Slew Rate Control Enable for Port B Bit 4
PTBSE_PTBSE5        equ       5                   ; Slew Rate Control Enable for Port B Bit 5
PTBSE_PTBSE6        equ       6                   ; Slew Rate Control Enable for Port B Bit 6
PTBSE_PTBSE7        equ       7                   ; Slew Rate Control Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE0       equ       %00000001
mPTBSE_PTBSE1       equ       %00000010
mPTBSE_PTBSE2       equ       %00000100
mPTBSE_PTBSE3       equ       %00001000
mPTBSE_PTBSE4       equ       %00010000
mPTBSE_PTBSE5       equ       %00100000
mPTBSE_PTBSE6       equ       %01000000
mPTBSE_PTBSE7       equ       %10000000


;*** PTBDD - Data Direction Register B
PTBDD               equ       $00000007           ;*** PTBDD - Data Direction Register B
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
PTCD                equ       $00000008           ;*** PTCD - Port C Data Register
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


;*** PTCPE - Pullup Enable for Port C
PTCPE               equ       $00000009           ;*** PTCPE - Pullup Enable for Port C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0        equ       0                   ; Pullup Enable for Port C Bit 0
PTCPE_PTCPE1        equ       1                   ; Pullup Enable for Port C Bit 1
PTCPE_PTCPE2        equ       2                   ; Pullup Enable for Port C Bit 2
PTCPE_PTCPE3        equ       3                   ; Pullup Enable for Port C Bit 3
PTCPE_PTCPE4        equ       4                   ; Pullup Enable for Port C Bit 4
PTCPE_PTCPE5        equ       5                   ; Pullup Enable for Port C Bit 5
PTCPE_PTCPE6        equ       6                   ; Pullup Enable for Port C Bit 6
PTCPE_PTCPE7        equ       7                   ; Pullup Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0       equ       %00000001
mPTCPE_PTCPE1       equ       %00000010
mPTCPE_PTCPE2       equ       %00000100
mPTCPE_PTCPE3       equ       %00001000
mPTCPE_PTCPE4       equ       %00010000
mPTCPE_PTCPE5       equ       %00100000
mPTCPE_PTCPE6       equ       %01000000
mPTCPE_PTCPE7       equ       %10000000


;*** PTCSE - Slew Rate Control Enable for Port C
PTCSE               equ       $0000000A           ;*** PTCSE - Slew Rate Control Enable for Port C
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0        equ       0                   ; Slew Rate Control Enable for Port C Bit 0
PTCSE_PTCSE1        equ       1                   ; Slew Rate Control Enable for Port C Bit 1
PTCSE_PTCSE2        equ       2                   ; Slew Rate Control Enable for Port C Bit 2
PTCSE_PTCSE3        equ       3                   ; Slew Rate Control Enable for Port C Bit 3
PTCSE_PTCSE4        equ       4                   ; Slew Rate Control Enable for Port C Bit 4
PTCSE_PTCSE5        equ       5                   ; Slew Rate Control Enable for Port C Bit 5
PTCSE_PTCSE6        equ       6                   ; Slew Rate Control Enable for Port C Bit 6
PTCSE_PTCSE7        equ       7                   ; Slew Rate Control Enable for Port C Bit 7
; bit position masks
mPTCSE_PTCSE0       equ       %00000001
mPTCSE_PTCSE1       equ       %00000010
mPTCSE_PTCSE2       equ       %00000100
mPTCSE_PTCSE3       equ       %00001000
mPTCSE_PTCSE4       equ       %00010000
mPTCSE_PTCSE5       equ       %00100000
mPTCSE_PTCSE6       equ       %01000000
mPTCSE_PTCSE7       equ       %10000000


;*** PTCDD - Data Direction Register C
PTCDD               equ       $0000000B           ;*** PTCDD - Data Direction Register C
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
PTDD                equ       $0000000C           ;*** PTDD - Port D Data Register
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


;*** PTDPE - Pullup Enable for Port D
PTDPE               equ       $0000000D           ;*** PTDPE - Pullup Enable for Port D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0        equ       0                   ; Pullup Enable for Port D Bit 0
PTDPE_PTDPE1        equ       1                   ; Pullup Enable for Port D Bit 1
PTDPE_PTDPE2        equ       2                   ; Pullup Enable for Port D Bit 2
PTDPE_PTDPE3        equ       3                   ; Pullup Enable for Port D Bit 3
PTDPE_PTDPE4        equ       4                   ; Pullup Enable for Port D Bit 4
PTDPE_PTDPE5        equ       5                   ; Pullup Enable for Port D Bit 5
PTDPE_PTDPE6        equ       6                   ; Pullup Enable for Port D Bit 6
PTDPE_PTDPE7        equ       7                   ; Pullup Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0       equ       %00000001
mPTDPE_PTDPE1       equ       %00000010
mPTDPE_PTDPE2       equ       %00000100
mPTDPE_PTDPE3       equ       %00001000
mPTDPE_PTDPE4       equ       %00010000
mPTDPE_PTDPE5       equ       %00100000
mPTDPE_PTDPE6       equ       %01000000
mPTDPE_PTDPE7       equ       %10000000


;*** PTDSE - Slew Rate Control Enable for Port D
PTDSE               equ       $0000000E           ;*** PTDSE - Slew Rate Control Enable for Port D
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0        equ       0                   ; Slew Rate Control Enable for Port D Bit 0
PTDSE_PTDSE1        equ       1                   ; Slew Rate Control Enable for Port D Bit 1
PTDSE_PTDSE2        equ       2                   ; Slew Rate Control Enable for Port D Bit 2
PTDSE_PTDSE3        equ       3                   ; Slew Rate Control Enable for Port D Bit 3
PTDSE_PTDSE4        equ       4                   ; Slew Rate Control Enable for Port D Bit 4
PTDSE_PTDSE5        equ       5                   ; Slew Rate Control Enable for Port D Bit 5
PTDSE_PTDSE6        equ       6                   ; Slew Rate Control Enable for Port D Bit 6
PTDSE_PTDSE7        equ       7                   ; Slew Rate Control Enable for Port D Bit 7
; bit position masks
mPTDSE_PTDSE0       equ       %00000001
mPTDSE_PTDSE1       equ       %00000010
mPTDSE_PTDSE2       equ       %00000100
mPTDSE_PTDSE3       equ       %00001000
mPTDSE_PTDSE4       equ       %00010000
mPTDSE_PTDSE5       equ       %00100000
mPTDSE_PTDSE6       equ       %01000000
mPTDSE_PTDSE7       equ       %10000000


;*** PTDDD - Data Direction Register D
PTDDD               equ       $0000000F           ;*** PTDDD - Data Direction Register D
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
PTED                equ       $00000010           ;*** PTED - Port E Data Register
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


;*** PTEPE - Pullup Enable for Port E
PTEPE               equ       $00000011           ;*** PTEPE - Pullup Enable for Port E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPE_PTEPE0        equ       0                   ; Pullup Enable for Port E Bit 0
PTEPE_PTEPE1        equ       1                   ; Pullup Enable for Port E Bit 1
PTEPE_PTEPE2        equ       2                   ; Pullup Enable for Port E Bit 2
PTEPE_PTEPE3        equ       3                   ; Pullup Enable for Port E Bit 3
PTEPE_PTEPE4        equ       4                   ; Pullup Enable for Port E Bit 4
PTEPE_PTEPE5        equ       5                   ; Pullup Enable for Port E Bit 5
PTEPE_PTEPE6        equ       6                   ; Pullup Enable for Port E Bit 6
PTEPE_PTEPE7        equ       7                   ; Pullup Enable for Port E Bit 7
; bit position masks
mPTEPE_PTEPE0       equ       %00000001
mPTEPE_PTEPE1       equ       %00000010
mPTEPE_PTEPE2       equ       %00000100
mPTEPE_PTEPE3       equ       %00001000
mPTEPE_PTEPE4       equ       %00010000
mPTEPE_PTEPE5       equ       %00100000
mPTEPE_PTEPE6       equ       %01000000
mPTEPE_PTEPE7       equ       %10000000


;*** PTESE - Slew Rate Control Enable for Port E
PTESE               equ       $00000012           ;*** PTESE - Slew Rate Control Enable for Port E
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESE_PTESE0        equ       0                   ; Slew Rate Control Enable for Port E Bit 0
PTESE_PTESE1        equ       1                   ; Slew Rate Control Enable for Port E Bit 1
PTESE_PTESE2        equ       2                   ; Slew Rate Control Enable for Port E Bit 2
PTESE_PTESE3        equ       3                   ; Slew Rate Control Enable for Port E Bit 3
PTESE_PTESE4        equ       4                   ; Slew Rate Control Enable for Port E Bit 4
PTESE_PTESE5        equ       5                   ; Slew Rate Control Enable for Port E Bit 5
PTESE_PTESE6        equ       6                   ; Slew Rate Control Enable for Port E Bit 6
PTESE_PTESE7        equ       7                   ; Slew Rate Control Enable for Port E Bit 7
; bit position masks
mPTESE_PTESE0       equ       %00000001
mPTESE_PTESE1       equ       %00000010
mPTESE_PTESE2       equ       %00000100
mPTESE_PTESE3       equ       %00001000
mPTESE_PTESE4       equ       %00010000
mPTESE_PTESE5       equ       %00100000
mPTESE_PTESE6       equ       %01000000
mPTESE_PTESE7       equ       %10000000


;*** PTEDD - Data Direction Register E
PTEDD               equ       $00000013           ;*** PTEDD - Data Direction Register E
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


;*** IRQSC - Interrupt Request Status and Control Register
IRQSC               equ       $00000014           ;*** IRQSC - Interrupt Request Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD        equ       0                   ; IRQ Detection Mode
IRQSC_IRQIE         equ       1                   ; IRQ Interrupt Enable
IRQSC_IRQACK        equ       2                   ; IRQ Acknowledge
IRQSC_IRQF          equ       3                   ; IRQ Flag
IRQSC_IRQPE         equ       4                   ; IRQ Pin Enable
IRQSC_IRQEDG        equ       5                   ; Interrupt Request (IRQ) Edge Select
; bit position masks
mIRQSC_IRQMOD       equ       %00000001
mIRQSC_IRQIE        equ       %00000010
mIRQSC_IRQACK       equ       %00000100
mIRQSC_IRQF         equ       %00001000
mIRQSC_IRQPE        equ       %00010000
mIRQSC_IRQEDG       equ       %00100000


;*** KBI1SC - KBI1 Status and Control
KBI1SC              equ       $00000016           ;*** KBI1SC - KBI1 Status and Control
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1SC_KBIMOD       equ       0                   ; Keyboard Detection Mode
KBI1SC_KBIE         equ       1                   ; Keyboard Interrupt Enable
KBI1SC_KBACK        equ       2                   ; Keyboard Interrupt Acknowledge
KBI1SC_KBF          equ       3                   ; Keyboard Interrupt Flag
KBI1SC_KBEDG4       equ       4                   ; Keyboard Edge Select for Port A Bit 4
KBI1SC_KBEDG5       equ       5                   ; Keyboard Edge Select for Port A Bit 5
KBI1SC_KBEDG6       equ       6                   ; Keyboard Edge Select for Port A Bit 6
KBI1SC_KBEDG7       equ       7                   ; Keyboard Edge Select for Port A Bit 7
; bit position masks
mKBI1SC_KBIMOD      equ       %00000001
mKBI1SC_KBIE        equ       %00000010
mKBI1SC_KBACK       equ       %00000100
mKBI1SC_KBF         equ       %00001000
mKBI1SC_KBEDG4      equ       %00010000
mKBI1SC_KBEDG5      equ       %00100000
mKBI1SC_KBEDG6      equ       %01000000
mKBI1SC_KBEDG7      equ       %10000000


;*** KBI1PE - KBI1 Pin Enable Register
KBI1PE              equ       $00000017           ;*** KBI1PE - KBI1 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for Port A Bit 0
KBI1PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for Port A Bit 1
KBI1PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for Port A Bit 2
KBI1PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for Port A Bit 3
KBI1PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for Port A Bit 4
KBI1PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for Port A Bit 5
KBI1PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for Port A Bit 6
KBI1PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for Port A Bit 7
; bit position masks
mKBI1PE_KBIPE0      equ       %00000001
mKBI1PE_KBIPE1      equ       %00000010
mKBI1PE_KBIPE2      equ       %00000100
mKBI1PE_KBIPE3      equ       %00001000
mKBI1PE_KBIPE4      equ       %00010000
mKBI1PE_KBIPE5      equ       %00100000
mKBI1PE_KBIPE6      equ       %01000000
mKBI1PE_KBIPE7      equ       %10000000


;*** SCI1BD - SCI1 Baud Rate Register
SCI1BD              equ       $00000018           ;*** SCI1BD - SCI1 Baud Rate Register


;*** SCI1BDH - SCI1 Baud Rate Register High
SCI1BDH             equ       $00000018           ;*** SCI1BDH - SCI1 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
; bit position masks
mSCI1BDH_SBR8       equ       %00000001
mSCI1BDH_SBR9       equ       %00000010
mSCI1BDH_SBR10      equ       %00000100
mSCI1BDH_SBR11      equ       %00001000
mSCI1BDH_SBR12      equ       %00010000


;*** SCI1BDL - SCI1 Baud Rate Register Low
SCI1BDL             equ       $00000019           ;*** SCI1BDL - SCI1 Baud Rate Register Low
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
SCI1C1              equ       $0000001A           ;*** SCI1C1 - SCI1 Control Register 1
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
SCI1C2              equ       $0000001B           ;*** SCI1C2 - SCI1 Control Register 2
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
SCI1S1              equ       $0000001C           ;*** SCI1S1 - SCI1 Status Register 1
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
SCI1S2              equ       $0000001D           ;*** SCI1S2 - SCI1 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF          equ       0                   ; Receiver Active Flag
; bit position masks
mSCI1S2_RAF         equ       %00000001


;*** SCI1C3 - SCI1 Control Register 3
SCI1C3              equ       $0000001E           ;*** SCI1C3 - SCI1 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI1C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI1C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI1C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI1C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI1C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE        equ       %00000001
mSCI1C3_FEIE        equ       %00000010
mSCI1C3_NEIE        equ       %00000100
mSCI1C3_ORIE        equ       %00001000
mSCI1C3_TXDIR       equ       %00100000
mSCI1C3_T8          equ       %01000000
mSCI1C3_R8          equ       %10000000


;*** SCI1D - SCI1 Data Register
SCI1D               equ       $0000001F           ;*** SCI1D - SCI1 Data Register
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


;*** SCI2BD - SCI2 Baud Rate Register
SCI2BD              equ       $00000020           ;*** SCI2BD - SCI2 Baud Rate Register


;*** SCI2BDH - SCI2 Baud Rate Register High
SCI2BDH             equ       $00000020           ;*** SCI2BDH - SCI2 Baud Rate Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDH_SBR8        equ       0                   ; Baud Rate Modulo Divisor Bit 8
SCI2BDH_SBR9        equ       1                   ; Baud Rate Modulo Divisor Bit 9
SCI2BDH_SBR10       equ       2                   ; Baud Rate Modulo Divisor Bit 10
SCI2BDH_SBR11       equ       3                   ; Baud Rate Modulo Divisor Bit 11
SCI2BDH_SBR12       equ       4                   ; Baud Rate Modulo Divisor Bit 12
; bit position masks
mSCI2BDH_SBR8       equ       %00000001
mSCI2BDH_SBR9       equ       %00000010
mSCI2BDH_SBR10      equ       %00000100
mSCI2BDH_SBR11      equ       %00001000
mSCI2BDH_SBR12      equ       %00010000


;*** SCI2BDL - SCI2 Baud Rate Register Low
SCI2BDL             equ       $00000021           ;*** SCI2BDL - SCI2 Baud Rate Register Low
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


;*** SCI2C1 - SCI1 Control Register 1
SCI2C1              equ       $00000022           ;*** SCI2C1 - SCI1 Control Register 1
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
SCI2C2              equ       $00000023           ;*** SCI2C2 - SCI2 Control Register 2
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
SCI2S1              equ       $00000024           ;*** SCI2S1 - SCI2 Status Register 1
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
SCI2S2              equ       $00000025           ;*** SCI2S2 - SCI2 Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S2_RAF          equ       0                   ; Receiver Active Flag
; bit position masks
mSCI2S2_RAF         equ       %00000001


;*** SCI2C3 - SCI2 Control Register 3
SCI2C3              equ       $00000026           ;*** SCI2C3 - SCI2 Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C3_PEIE         equ       0                   ; Parity Error Interrupt Enable
SCI2C3_FEIE         equ       1                   ; Framing Error Interrupt Enable
SCI2C3_NEIE         equ       2                   ; Noise Error Interrupt Enable
SCI2C3_ORIE         equ       3                   ; Overrun Interrupt Enable
SCI2C3_TXDIR        equ       5                   ; TxD Pin Direction in Single-Wire Mode
SCI2C3_T8           equ       6                   ; Ninth Data Bit for Transmitter
SCI2C3_R8           equ       7                   ; Ninth Data Bit for Receiver
; bit position masks
mSCI2C3_PEIE        equ       %00000001
mSCI2C3_FEIE        equ       %00000010
mSCI2C3_NEIE        equ       %00000100
mSCI2C3_ORIE        equ       %00001000
mSCI2C3_TXDIR       equ       %00100000
mSCI2C3_T8          equ       %01000000
mSCI2C3_R8          equ       %10000000


;*** SCI2D - SCI2 Data Register
SCI2D               equ       $00000027           ;*** SCI2D - SCI2 Data Register
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


;*** SPI1C1 - SPI1 Control Register 1
SPI1C1              equ       $00000028           ;*** SPI1C1 - SPI1 Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C1_LSBFE        equ       0                   ; LSB First (shifter direction)
SPI1C1_SSOE         equ       1                   ; Slave Select Output Enable
SPI1C1_CPHA         equ       2                   ; Clock Phase
SPI1C1_CPOL         equ       3                   ; Clock Polarity
SPI1C1_MSTR         equ       4                   ; Master/Slave Mode Select
SPI1C1_SPTIE        equ       5                   ; SPI1 Transmit Interrupt Enable
SPI1C1_SPE          equ       6                   ; SPI1 System Enable
SPI1C1_SPIE         equ       7                   ; SPI1 Interrupt Enable
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
SPI1C2              equ       $00000029           ;*** SPI1C2 - SPI1 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1C2_SPC0         equ       0                   ; SPI1 Pin Control 0
SPI1C2_SPISWAI      equ       1                   ; SPI1 Stop in Wait Mode
SPI1C2_BIDIROE      equ       3                   ; Bidirectional Mode Output Enable
SPI1C2_MODFEN       equ       4                   ; Master Mode-Fault Function Enable
; bit position masks
mSPI1C2_SPC0        equ       %00000001
mSPI1C2_SPISWAI     equ       %00000010
mSPI1C2_BIDIROE     equ       %00001000
mSPI1C2_MODFEN      equ       %00010000


;*** SPI1BR - SPI1 Baud Rate Register
SPI1BR              equ       $0000002A           ;*** SPI1BR - SPI1 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0         equ       0                   ; SPI1 Baud Rate Divisor Bit 0
SPI1BR_SPR1         equ       1                   ; SPI1 Baud Rate Divisor Bit 1
SPI1BR_SPR2         equ       2                   ; SPI1 Baud Rate Divisor Bit 2
SPI1BR_SPPR0        equ       4                   ; SPI1 Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1        equ       5                   ; SPI1 Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2        equ       6                   ; SPI1 Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0        equ       %00000001
mSPI1BR_SPR1        equ       %00000010
mSPI1BR_SPR2        equ       %00000100
mSPI1BR_SPPR0       equ       %00010000
mSPI1BR_SPPR1       equ       %00100000
mSPI1BR_SPPR2       equ       %01000000


;*** SPI1S - SPI1 Status Register
SPI1S               equ       $0000002B           ;*** SPI1S - SPI1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF          equ       4                   ; Master Mode Fault Flag
SPI1S_SPTEF         equ       5                   ; SPI1 Transmit Buffer Empty Flag
SPI1S_SPRF          equ       7                   ; SPI1 Read Buffer Full Flag
; bit position masks
mSPI1S_MODF         equ       %00010000
mSPI1S_SPTEF        equ       %00100000
mSPI1S_SPRF         equ       %10000000


;*** SPI1D - SPI1 Data Register
SPI1D               equ       $0000002D           ;*** SPI1D - SPI1 Data Register


;*** TPM1SC - TPM 1 Status and Control Register
TPM1SC              equ       $00000030           ;*** TPM1SC - TPM 1 Status and Control Register
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


;*** TPM1CNT - TPM 1 Counter Register
TPM1CNT             equ       $00000031           ;*** TPM1CNT - TPM 1 Counter Register


;*** TPM1CNTH - TPM 1 Counter Register High
TPM1CNTH            equ       $00000031           ;*** TPM1CNTH - TPM 1 Counter Register High


;*** TPM1CNTL - TPM 1 Counter Register Low
TPM1CNTL            equ       $00000032           ;*** TPM1CNTL - TPM 1 Counter Register Low


;*** TPM1MOD - TPM 1 Timer Counter Modulo Register
TPM1MOD             equ       $00000033           ;*** TPM1MOD - TPM 1 Timer Counter Modulo Register


;*** TPM1MODH - TPM 1 Timer Counter Modulo Register High
TPM1MODH            equ       $00000033           ;*** TPM1MODH - TPM 1 Timer Counter Modulo Register High


;*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low
TPM1MODL            equ       $00000034           ;*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low


;*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $00000035           ;*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register
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


;*** TPM1C0V - TPM 1 Timer Channel 0 Value Register
TPM1C0V             equ       $00000036           ;*** TPM1C0V - TPM 1 Timer Channel 0 Value Register


;*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $00000036           ;*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High


;*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $00000037           ;*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low


;*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register
TPM1C1SC            equ       $00000038           ;*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register
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


;*** TPM1C1V - TPM 1 Timer Channel 1 Value Register
TPM1C1V             equ       $00000039           ;*** TPM1C1V - TPM 1 Timer Channel 1 Value Register


;*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High
TPM1C1VH            equ       $00000039           ;*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High


;*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low
TPM1C1VL            equ       $0000003A           ;*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low


;*** TPM1C2SC - TPM 1 Timer Channel 2 Status and Control Register
TPM1C2SC            equ       $0000003B           ;*** TPM1C2SC - TPM 1 Timer Channel 2 Status and Control Register
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


;*** TPM1C2V - TPM 1 Timer Channel 2 Value Register
TPM1C2V             equ       $0000003C           ;*** TPM1C2V - TPM 1 Timer Channel 2 Value Register


;*** TPM1C2VH - TPM 1 Timer Channel 2 Value Register High
TPM1C2VH            equ       $0000003C           ;*** TPM1C2VH - TPM 1 Timer Channel 2 Value Register High


;*** TPM1C2VL - TPM 1 Timer Channel 2 Value Register Low
TPM1C2VL            equ       $0000003D           ;*** TPM1C2VL - TPM 1 Timer Channel 2 Value Register Low


;*** PTFD - Port F Data Register
PTFD                equ       $00000040           ;*** PTFD - Port F Data Register
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


;*** PTFPE - Pullup Enable for Port F
PTFPE               equ       $00000041           ;*** PTFPE - Pullup Enable for Port F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFPE_PTFPE0        equ       0                   ; Pullup Enable for Port F Bit 0
PTFPE_PTFPE1        equ       1                   ; Pullup Enable for Port F Bit 1
PTFPE_PTFPE2        equ       2                   ; Pullup Enable for Port F Bit 2
PTFPE_PTFPE3        equ       3                   ; Pullup Enable for Port F Bit 3
PTFPE_PTFPE4        equ       4                   ; Pullup Enable for Port F Bit 4
PTFPE_PTFPE5        equ       5                   ; Pullup Enable for Port F Bit 5
PTFPE_PTFPE6        equ       6                   ; Pullup Enable for Port F Bit 6
PTFPE_PTFPE7        equ       7                   ; Pullup Enable for Port F Bit 7
; bit position masks
mPTFPE_PTFPE0       equ       %00000001
mPTFPE_PTFPE1       equ       %00000010
mPTFPE_PTFPE2       equ       %00000100
mPTFPE_PTFPE3       equ       %00001000
mPTFPE_PTFPE4       equ       %00010000
mPTFPE_PTFPE5       equ       %00100000
mPTFPE_PTFPE6       equ       %01000000
mPTFPE_PTFPE7       equ       %10000000


;*** PTFSE - Slew Rate Control Enable for Port F
PTFSE               equ       $00000042           ;*** PTFSE - Slew Rate Control Enable for Port F
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTFSE_PTFSE0        equ       0                   ; Slew Rate Control Enable for Port F Bit 0
PTFSE_PTFSE1        equ       1                   ; Slew Rate Control Enable for Port F Bit 1
PTFSE_PTFSE2        equ       2                   ; Slew Rate Control Enable for Port F Bit 2
PTFSE_PTFSE3        equ       3                   ; Slew Rate Control Enable for Port F Bit 3
PTFSE_PTFSE4        equ       4                   ; Slew Rate Control Enable for Port F Bit 4
PTFSE_PTFSE5        equ       5                   ; Slew Rate Control Enable for Port F Bit 5
PTFSE_PTFSE6        equ       6                   ; Slew Rate Control Enable for Port F Bit 6
PTFSE_PTFSE7        equ       7                   ; Slew Rate Control Enable for Port F Bit 7
; bit position masks
mPTFSE_PTFSE0       equ       %00000001
mPTFSE_PTFSE1       equ       %00000010
mPTFSE_PTFSE2       equ       %00000100
mPTFSE_PTFSE3       equ       %00001000
mPTFSE_PTFSE4       equ       %00010000
mPTFSE_PTFSE5       equ       %00100000
mPTFSE_PTFSE6       equ       %01000000
mPTFSE_PTFSE7       equ       %10000000


;*** PTFDD - Data Direction Register F
PTFDD               equ       $00000043           ;*** PTFDD - Data Direction Register F
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
PTGD                equ       $00000044           ;*** PTGD - Port G Data Register
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


;*** PTGPE - Pullup Enable for Port G
PTGPE               equ       $00000045           ;*** PTGPE - Pullup Enable for Port G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGPE_PTGPE0        equ       0                   ; Pullup Enable for Port G Bit 0
PTGPE_PTGPE1        equ       1                   ; Pullup Enable for Port G Bit 1
PTGPE_PTGPE2        equ       2                   ; Pullup Enable for Port G Bit 2
PTGPE_PTGPE3        equ       3                   ; Pullup Enable for Port G Bit 3
PTGPE_PTGPE4        equ       4                   ; Pullup Enable for Port G Bit 4
PTGPE_PTGPE5        equ       5                   ; Pullup Enable for Port G Bit 5
PTGPE_PTGPE6        equ       6                   ; Pullup Enable for Port G Bit 6
PTGPE_PTGPE7        equ       7                   ; Pullup Enable for Port G Bit 7
; bit position masks
mPTGPE_PTGPE0       equ       %00000001
mPTGPE_PTGPE1       equ       %00000010
mPTGPE_PTGPE2       equ       %00000100
mPTGPE_PTGPE3       equ       %00001000
mPTGPE_PTGPE4       equ       %00010000
mPTGPE_PTGPE5       equ       %00100000
mPTGPE_PTGPE6       equ       %01000000
mPTGPE_PTGPE7       equ       %10000000


;*** PTGSE - Slew Rate Control Enable for Port G
PTGSE               equ       $00000046           ;*** PTGSE - Slew Rate Control Enable for Port G
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTGSE_PTGSE0        equ       0                   ; Slew Rate Control Enable for Port G Bit 0
PTGSE_PTGSE1        equ       1                   ; Slew Rate Control Enable for Port G Bit 1
PTGSE_PTGSE2        equ       2                   ; Slew Rate Control Enable for Port G Bit 2
PTGSE_PTGSE3        equ       3                   ; Slew Rate Control Enable for Port G Bit 3
PTGSE_PTGSE4        equ       4                   ; Slew Rate Control Enable for Port G Bit 4
PTGSE_PTGSE5        equ       5                   ; Slew Rate Control Enable for Port G Bit 5
PTGSE_PTGSE6        equ       6                   ; Slew Rate Control Enable for Port G Bit 6
PTGSE_PTGSE7        equ       7                   ; Slew Rate Control Enable for Port G Bit 7
; bit position masks
mPTGSE_PTGSE0       equ       %00000001
mPTGSE_PTGSE1       equ       %00000010
mPTGSE_PTGSE2       equ       %00000100
mPTGSE_PTGSE3       equ       %00001000
mPTGSE_PTGSE4       equ       %00010000
mPTGSE_PTGSE5       equ       %00100000
mPTGSE_PTGSE6       equ       %01000000
mPTGSE_PTGSE7       equ       %10000000


;*** PTGDD - Data Direction Register G
PTGDD               equ       $00000047           ;*** PTGDD - Data Direction Register G
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


;*** ICGC1 - ICG Control Register 1
ICGC1               equ       $00000048           ;*** ICGC1 - ICG Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGC1_LOCD          equ       1                   ; Loss of Clock Disable
ICGC1_OSCSTEN       equ       2                   ; Enable Oscillator in Off Mode
ICGC1_CLKS0         equ       3                   ; Clock Mode Select Bit 0
ICGC1_CLKS1         equ       4                   ; Clock Mode Select Bit 1
ICGC1_REFS          equ       5                   ; External Reference Select
ICGC1_RANGE         equ       6                   ; Frequency Range Select
ICGC1_HGO           equ       7                   ; High Gain Oscillator Select
; bit position masks
mICGC1_LOCD         equ       %00000010
mICGC1_OSCSTEN      equ       %00000100
mICGC1_CLKS0        equ       %00001000
mICGC1_CLKS1        equ       %00010000
mICGC1_REFS         equ       %00100000
mICGC1_RANGE        equ       %01000000
mICGC1_HGO          equ       %10000000


;*** ICGC2 - ICG Control Register 2
ICGC2               equ       $00000049           ;*** ICGC2 - ICG Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGC2_RFD0          equ       0                   ; Reduced Frequency Divider Bit 0
ICGC2_RFD1          equ       1                   ; Reduced Frequency Divider Bit 1
ICGC2_RFD2          equ       2                   ; Reduced Frequency Divider Bit 2
ICGC2_LOCRE         equ       3                   ; Loss of Clock Reset Enable
ICGC2_MFD0          equ       4                   ; Multiplication Factor Bit 0
ICGC2_MFD1          equ       5                   ; Multiplication Factor Bit 1
ICGC2_MFD2          equ       6                   ; Multiplication Factor Bit 2
ICGC2_LOLRE         equ       7                   ; Loss of Lock Reset Enable
; bit position masks
mICGC2_RFD0         equ       %00000001
mICGC2_RFD1         equ       %00000010
mICGC2_RFD2         equ       %00000100
mICGC2_LOCRE        equ       %00001000
mICGC2_MFD0         equ       %00010000
mICGC2_MFD1         equ       %00100000
mICGC2_MFD2         equ       %01000000
mICGC2_LOLRE        equ       %10000000


;*** ICGS1 - ICG Status Register 1
ICGS1               equ       $0000004A           ;*** ICGS1 - ICG Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGS1_ICGIF         equ       0                   ; ICG Interrupt Flag
ICGS1_ERCS          equ       1                   ; External Reference Clock Status
ICGS1_LOCS          equ       2                   ; Loss Of Clock Status
ICGS1_LOCK          equ       3                   ; FLL Lock Status
ICGS1_LOLS          equ       4                   ; FLL Loss of Lock Status
ICGS1_REFST         equ       5                   ; Reference Clock Status
ICGS1_CLKST0        equ       6                   ; Clock Mode Status Bit 0
ICGS1_CLKST1        equ       7                   ; Clock Mode Status Bit 1
; bit position masks
mICGS1_ICGIF        equ       %00000001
mICGS1_ERCS         equ       %00000010
mICGS1_LOCS         equ       %00000100
mICGS1_LOCK         equ       %00001000
mICGS1_LOLS         equ       %00010000
mICGS1_REFST        equ       %00100000
mICGS1_CLKST0       equ       %01000000
mICGS1_CLKST1       equ       %10000000


;*** ICGS2 - ICG Status Register 2
ICGS2               equ       $0000004B           ;*** ICGS2 - ICG Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGS2_DCOS          equ       0                   ; DCO Clock Stable
; bit position masks
mICGS2_DCOS         equ       %00000001


;*** ICGFLT - ICG Filter Register
ICGFLT              equ       $0000004C           ;*** ICGFLT - ICG Filter Register


;*** ICGFLTU - ICG Upper Filter Register
ICGFLTU             equ       $0000004C           ;*** ICGFLTU - ICG Upper Filter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGFLTU_FILT8       equ       0                   ; ICG Filter Bit 8
ICGFLTU_FILT9       equ       1                   ; ICG Filter Bit 9
ICGFLTU_FILT10      equ       2                   ; ICG Filter Bit 10
ICGFLTU_FILT11      equ       3                   ; ICG Filter Bit 11
; bit position masks
mICGFLTU_FILT8      equ       %00000001
mICGFLTU_FILT9      equ       %00000010
mICGFLTU_FILT10     equ       %00000100
mICGFLTU_FILT11     equ       %00001000


;*** ICGFLTL - ICG Lower Filter Register
ICGFLTL             equ       $0000004D           ;*** ICGFLTL - ICG Lower Filter Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGFLTL_FILT0       equ       0                   ; ICG Filter Bit 0
ICGFLTL_FILT1       equ       1                   ; ICG Filter Bit 1
ICGFLTL_FILT2       equ       2                   ; ICG Filter Bit 2
ICGFLTL_FILT3       equ       3                   ; ICG Filter Bit 3
ICGFLTL_FILT4       equ       4                   ; ICG Filter Bit 4
ICGFLTL_FILT5       equ       5                   ; ICG Filter Bit 5
ICGFLTL_FILT6       equ       6                   ; ICG Filter Bit 6
ICGFLTL_FILT7       equ       7                   ; ICG Filter Bit 7
; bit position masks
mICGFLTL_FILT0      equ       %00000001
mICGFLTL_FILT1      equ       %00000010
mICGFLTL_FILT2      equ       %00000100
mICGFLTL_FILT3      equ       %00001000
mICGFLTL_FILT4      equ       %00010000
mICGFLTL_FILT5      equ       %00100000
mICGFLTL_FILT6      equ       %01000000
mICGFLTL_FILT7      equ       %10000000


;*** ICGTRM - ICG Trim Register
ICGTRM              equ       $0000004E           ;*** ICGTRM - ICG Trim Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICGTRM_TRIM0        equ       0                   ; ICG Trim Bit 0
ICGTRM_TRIM1        equ       1                   ; ICG Trim Bit 1
ICGTRM_TRIM2        equ       2                   ; ICG Trim Bit 2
ICGTRM_TRIM3        equ       3                   ; ICG Trim Bit 3
ICGTRM_TRIM4        equ       4                   ; ICG Trim Bit 4
ICGTRM_TRIM5        equ       5                   ; ICG Trim Bit 5
ICGTRM_TRIM6        equ       6                   ; ICG Trim Bit 6
ICGTRM_TRIM7        equ       7                   ; ICG Trim Bit 7
; bit position masks
mICGTRM_TRIM0       equ       %00000001
mICGTRM_TRIM1       equ       %00000010
mICGTRM_TRIM2       equ       %00000100
mICGTRM_TRIM3       equ       %00001000
mICGTRM_TRIM4       equ       %00010000
mICGTRM_TRIM5       equ       %00100000
mICGTRM_TRIM6       equ       %01000000
mICGTRM_TRIM7       equ       %10000000


;*** ATD1C - ATD1 Control Register
ATD1C               equ       $00000050           ;*** ATD1C - ATD1 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD1C_PRS0          equ       0                   ; Prescaler Rate Select Bit 0
ATD1C_PRS1          equ       1                   ; Prescaler Rate Select Bit 1
ATD1C_PRS2          equ       2                   ; Prescaler Rate Select Bit 2
ATD1C_PRS3          equ       3                   ; Prescaler Rate Select Bit 3
ATD1C_SGN           equ       4                   ; Signed Result Select
ATD1C_RES8          equ       5                   ; ATD Resolution Select
ATD1C_DJM           equ       6                   ; Data Justification Mode
ATD1C_ATDPU         equ       7                   ; ATD Power Up
; bit position masks
mATD1C_PRS0         equ       %00000001
mATD1C_PRS1         equ       %00000010
mATD1C_PRS2         equ       %00000100
mATD1C_PRS3         equ       %00001000
mATD1C_SGN          equ       %00010000
mATD1C_RES8         equ       %00100000
mATD1C_DJM          equ       %01000000
mATD1C_ATDPU        equ       %10000000


;*** ATD1SC - ATD1 Status and Control Register
ATD1SC              equ       $00000051           ;*** ATD1SC - ATD1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD1SC_ATDCH0       equ       0                   ; Analog Input Channel Select Bit 0
ATD1SC_ATDCH1       equ       1                   ; Analog Input Channel Select Bit 1
ATD1SC_ATDCH2       equ       2                   ; Analog Input Channel Select Bit 2
ATD1SC_ATDCH3       equ       3                   ; Analog Input Channel Select Bit 3
ATD1SC_ATDCH4       equ       4                   ; Analog Input Channel Select Bit 4
ATD1SC_ATDCO        equ       5                   ; ATD Continuous Conversion
ATD1SC_ATDIE        equ       6                   ; ATD Interrupt Enabled
ATD1SC_CCF          equ       7                   ; Conversion Complete Flag
; bit position masks
mATD1SC_ATDCH0      equ       %00000001
mATD1SC_ATDCH1      equ       %00000010
mATD1SC_ATDCH2      equ       %00000100
mATD1SC_ATDCH3      equ       %00001000
mATD1SC_ATDCH4      equ       %00010000
mATD1SC_ATDCO       equ       %00100000
mATD1SC_ATDIE       equ       %01000000
mATD1SC_CCF         equ       %10000000


;*** ATD1R - ATD1 Result Data
ATD1R               equ       $00000052           ;*** ATD1R - ATD1 Result Data


;*** ATD1RH - ATD1 Result Data High Right Justified
ATD1RH              equ       $00000052           ;*** ATD1RH - ATD1 Result Data High Right Justified
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD1RH_BIT8         equ       0                   ; ATD Result Data Bit 8
ATD1RH_BIT9         equ       1                   ; ATD Result Data Bit 9
ATD1RH_BIT10        equ       2                   ; ATD Result Data Bit 10
ATD1RH_BIT11        equ       3                   ; ATD Result Data Bit 11
ATD1RH_BIT12        equ       4                   ; ATD Result Data Bit 12
ATD1RH_BIT13        equ       5                   ; ATD Result Data Bit 13
ATD1RH_BIT14        equ       6                   ; ATD Result Data Bit 14
ATD1RH_BIT15        equ       7                   ; ATD Result Data Bit 15
; bit position masks
mATD1RH_BIT8        equ       %00000001
mATD1RH_BIT9        equ       %00000010
mATD1RH_BIT10       equ       %00000100
mATD1RH_BIT11       equ       %00001000
mATD1RH_BIT12       equ       %00010000
mATD1RH_BIT13       equ       %00100000
mATD1RH_BIT14       equ       %01000000
mATD1RH_BIT15       equ       %10000000


;*** ATD1RL - ATD1 Result Data Low Right Justified
ATD1RL              equ       $00000053           ;*** ATD1RL - ATD1 Result Data Low Right Justified
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD1RL_BIT0         equ       0                   ; ATD Result Data Bit 0
ATD1RL_BIT1         equ       1                   ; ATD Result Data Bit 1
ATD1RL_BIT2         equ       2                   ; ATD Result Data Bit 2
ATD1RL_BIT3         equ       3                   ; ATD Result Data Bit 3
ATD1RL_BIT4         equ       4                   ; ATD Result Data Bit 4
ATD1RL_BIT5         equ       5                   ; ATD Result Data Bit 5
ATD1RL_BIT6         equ       6                   ; ATD Result Data Bit 6
ATD1RL_BIT7         equ       7                   ; ATD Result Data Bit 7
; bit position masks
mATD1RL_BIT0        equ       %00000001
mATD1RL_BIT1        equ       %00000010
mATD1RL_BIT2        equ       %00000100
mATD1RL_BIT3        equ       %00001000
mATD1RL_BIT4        equ       %00010000
mATD1RL_BIT5        equ       %00100000
mATD1RL_BIT6        equ       %01000000
mATD1RL_BIT7        equ       %10000000


;*** ATD1PE - ATD1 Pin Enable
ATD1PE              equ       $00000054           ;*** ATD1PE - ATD1 Pin Enable
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ATD1PE_ATDPE0       equ       0                   ; ATD Pin Enable Bit 0
ATD1PE_ATDPE1       equ       1                   ; ATD Pin Enable Bit 1
ATD1PE_ATDPE2       equ       2                   ; ATD Pin Enable Bit 2
ATD1PE_ATDPE3       equ       3                   ; ATD Pin Enable Bit 3
ATD1PE_ATDPE4       equ       4                   ; ATD Pin Enable Bit 4
ATD1PE_ATDPE5       equ       5                   ; ATD Pin Enable Bit 5
ATD1PE_ATDPE6       equ       6                   ; ATD Pin Enable Bit 6
ATD1PE_ATDPE7       equ       7                   ; ATD Pin Enable Bit 7
; bit position masks
mATD1PE_ATDPE0      equ       %00000001
mATD1PE_ATDPE1      equ       %00000010
mATD1PE_ATDPE2      equ       %00000100
mATD1PE_ATDPE3      equ       %00001000
mATD1PE_ATDPE4      equ       %00010000
mATD1PE_ATDPE5      equ       %00100000
mATD1PE_ATDPE6      equ       %01000000
mATD1PE_ATDPE7      equ       %10000000


;*** IIC1A - IIC1 Address Register
IIC1A               equ       $00000058           ;*** IIC1A - IIC1 Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1A_ADDR1         equ       1                   ; IIC Address Bit 1
IIC1A_ADDR2         equ       2                   ; IIC Address Bit 2
IIC1A_ADDR3         equ       3                   ; IIC Address Bit 3
IIC1A_ADDR4         equ       4                   ; IIC Address Bit 4
IIC1A_ADDR5         equ       5                   ; IIC Address Bit 5
IIC1A_ADDR6         equ       6                   ; IIC Address Bit 6
IIC1A_ADDR7         equ       7                   ; IIC Address Bit 7
; bit position masks
mIIC1A_ADDR1        equ       %00000010
mIIC1A_ADDR2        equ       %00000100
mIIC1A_ADDR3        equ       %00001000
mIIC1A_ADDR4        equ       %00010000
mIIC1A_ADDR5        equ       %00100000
mIIC1A_ADDR6        equ       %01000000
mIIC1A_ADDR7        equ       %10000000


;*** IIC1F - IIC1 Frequency Divider Register
IIC1F               equ       $00000059           ;*** IIC1F - IIC1 Frequency Divider Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1F_ICR0          equ       0                   ; IIC Clock Rate Bit 0
IIC1F_ICR1          equ       1                   ; IIC Clock Rate Bit 1
IIC1F_ICR2          equ       2                   ; IIC Clock Rate Bit 2
IIC1F_ICR3          equ       3                   ; IIC Clock Rate Bit 3
IIC1F_ICR4          equ       4                   ; IIC Clock Rate Bit 4
IIC1F_ICR5          equ       5                   ; IIC Clock Rate Bit 5
IIC1F_MULT0         equ       6                   ; Multiplier Factor Bit 0
IIC1F_MULT1         equ       7                   ; Multiplier Factor Bit 1
; bit position masks
mIIC1F_ICR0         equ       %00000001
mIIC1F_ICR1         equ       %00000010
mIIC1F_ICR2         equ       %00000100
mIIC1F_ICR3         equ       %00001000
mIIC1F_ICR4         equ       %00010000
mIIC1F_ICR5         equ       %00100000
mIIC1F_MULT0        equ       %01000000
mIIC1F_MULT1        equ       %10000000


;*** IIC1C - IIC1 Control Register
IIC1C               equ       $0000005A           ;*** IIC1C - IIC1 Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C_RSTA          equ       2                   ; Repeat START Bit
IIC1C_TXAK          equ       3                   ; Transmit Acknowledge Enable Bit
IIC1C_TX            equ       4                   ; Transmit Mode Select Bit
IIC1C_MST           equ       5                   ; Master Mode Select Bit
IIC1C_IICIE         equ       6                   ; IIC Interrupt Enable Bit
IIC1C_IICEN         equ       7                   ; IIC Enable Bit
; bit position masks
mIIC1C_RSTA         equ       %00000100
mIIC1C_TXAK         equ       %00001000
mIIC1C_TX           equ       %00010000
mIIC1C_MST          equ       %00100000
mIIC1C_IICIE        equ       %01000000
mIIC1C_IICEN        equ       %10000000


;*** IIC1S - IIC1 Status Register
IIC1S               equ       $0000005B           ;*** IIC1S - IIC1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1S_RXAK          equ       0                   ; Receive Acknowledge
IIC1S_IICIF         equ       1                   ; IIC Interrupt Flag
IIC1S_SRW           equ       2                   ; Slave Read/Write
IIC1S_ARBL          equ       4                   ; Arbitration Lost
IIC1S_BUSY          equ       5                   ; Bus Busy bit
IIC1S_IAAS          equ       6                   ; Addressed as a Slave Bit
IIC1S_TCF           equ       7                   ; Transfer Complete Flag
; bit position masks
mIIC1S_RXAK         equ       %00000001
mIIC1S_IICIF        equ       %00000010
mIIC1S_SRW          equ       %00000100
mIIC1S_ARBL         equ       %00010000
mIIC1S_BUSY         equ       %00100000
mIIC1S_IAAS         equ       %01000000
mIIC1S_TCF          equ       %10000000


;*** IIC1D - IIC1 Data I/O Register
IIC1D               equ       $0000005C           ;*** IIC1D - IIC1 Data I/O Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1D_DATA0         equ       0                   ; IIC Data Bit 0
IIC1D_DATA1         equ       1                   ; IIC Data Bit 1
IIC1D_DATA2         equ       2                   ; IIC Data Bit 2
IIC1D_DATA3         equ       3                   ; IIC Data Bit 3
IIC1D_DATA4         equ       4                   ; IIC Data Bit 4
IIC1D_DATA5         equ       5                   ; IIC Data Bit 5
IIC1D_DATA6         equ       6                   ; IIC Data Bit 6
IIC1D_DATA7         equ       7                   ; IIC Data Bit 7
; bit position masks
mIIC1D_DATA0        equ       %00000001
mIIC1D_DATA1        equ       %00000010
mIIC1D_DATA2        equ       %00000100
mIIC1D_DATA3        equ       %00001000
mIIC1D_DATA4        equ       %00010000
mIIC1D_DATA5        equ       %00100000
mIIC1D_DATA6        equ       %01000000
mIIC1D_DATA7        equ       %10000000


;*** TPM2SC - TPM 2 Status and Control Register
TPM2SC              equ       $00000060           ;*** TPM2SC - TPM 2 Status and Control Register
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


;*** TPM2CNT - TPM 2 Counter Register
TPM2CNT             equ       $00000061           ;*** TPM2CNT - TPM 2 Counter Register


;*** TPM2CNTH - TPM 2 Counter Register High
TPM2CNTH            equ       $00000061           ;*** TPM2CNTH - TPM 2 Counter Register High


;*** TPM2CNTL - TPM 2 Counter Register Low
TPM2CNTL            equ       $00000062           ;*** TPM2CNTL - TPM 2 Counter Register Low


;*** TPM2MOD - TPM 2 Timer Counter Modulo Register
TPM2MOD             equ       $00000063           ;*** TPM2MOD - TPM 2 Timer Counter Modulo Register


;*** TPM2MODH - TPM 2 Timer Counter Modulo Register High
TPM2MODH            equ       $00000063           ;*** TPM2MODH - TPM 2 Timer Counter Modulo Register High


;*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low
TPM2MODL            equ       $00000064           ;*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low


;*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $00000065           ;*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register
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


;*** TPM2C0V - TPM 2 Timer Channel 0 Value Register
TPM2C0V             equ       $00000066           ;*** TPM2C0V - TPM 2 Timer Channel 0 Value Register


;*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $00000066           ;*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High


;*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $00000067           ;*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low


;*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register
TPM2C1SC            equ       $00000068           ;*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register
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


;*** TPM2C1V - TPM 2 Timer Channel 1 Value Register
TPM2C1V             equ       $00000069           ;*** TPM2C1V - TPM 2 Timer Channel 1 Value Register


;*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High
TPM2C1VH            equ       $00000069           ;*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High


;*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low
TPM2C1VL            equ       $0000006A           ;*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low


;*** TPM2C2SC - TPM 2 Timer Channel 2 Status and Control Register
TPM2C2SC            equ       $0000006B           ;*** TPM2C2SC - TPM 2 Timer Channel 2 Status and Control Register
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


;*** TPM2C2V - TPM 2 Timer Channel 2 Value Register
TPM2C2V             equ       $0000006C           ;*** TPM2C2V - TPM 2 Timer Channel 2 Value Register


;*** TPM2C2VH - TPM 2 Timer Channel 2 Value Register High
TPM2C2VH            equ       $0000006C           ;*** TPM2C2VH - TPM 2 Timer Channel 2 Value Register High


;*** TPM2C2VL - TPM 2 Timer Channel 2 Value Register Low
TPM2C2VL            equ       $0000006D           ;*** TPM2C2VL - TPM 2 Timer Channel 2 Value Register Low


;*** TPM2C3SC - TPM 2 Timer Channel 3 Status and Control Register
TPM2C3SC            equ       $0000006E           ;*** TPM2C3SC - TPM 2 Timer Channel 3 Status and Control Register
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


;*** TPM2C3V - TPM 2 Timer Channel 3 Value Register
TPM2C3V             equ       $0000006F           ;*** TPM2C3V - TPM 2 Timer Channel 3 Value Register


;*** TPM2C3VH - TPM 2 Timer Channel 3 Value Register High
TPM2C3VH            equ       $0000006F           ;*** TPM2C3VH - TPM 2 Timer Channel 3 Value Register High


;*** TPM2C3VL - TPM 2 Timer Channel 3 Value Register Low
TPM2C3VL            equ       $00000070           ;*** TPM2C3VL - TPM 2 Timer Channel 3 Value Register Low


;*** TPM2C4SC - TPM 2 Timer Channel 4 Status and Control Register
TPM2C4SC            equ       $00000071           ;*** TPM2C4SC - TPM 2 Timer Channel 4 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C4SC_ELS4A      equ       2                   ; Edge/Level Select Bit A
TPM2C4SC_ELS4B      equ       3                   ; Edge/Level Select Bit B
TPM2C4SC_MS4A       equ       4                   ; Mode Select A for TPM Channel 4
TPM2C4SC_MS4B       equ       5                   ; Mode Select B for TPM Channel 4
TPM2C4SC_CH4IE      equ       6                   ; Channel 4 Interrupt Enable
TPM2C4SC_CH4F       equ       7                   ; Channel 4 Flag
; bit position masks
mTPM2C4SC_ELS4A     equ       %00000100
mTPM2C4SC_ELS4B     equ       %00001000
mTPM2C4SC_MS4A      equ       %00010000
mTPM2C4SC_MS4B      equ       %00100000
mTPM2C4SC_CH4IE     equ       %01000000
mTPM2C4SC_CH4F      equ       %10000000


;*** TPM2C4V - TPM 2 Timer Channel 4 Value Register
TPM2C4V             equ       $00000072           ;*** TPM2C4V - TPM 2 Timer Channel 4 Value Register


;*** TPM2C4VH - TPM 2 Timer Channel 4 Value Register High
TPM2C4VH            equ       $00000072           ;*** TPM2C4VH - TPM 2 Timer Channel 4 Value Register High


;*** TPM2C4VL - TPM 2 Timer Channel 4 Value Register Low
TPM2C4VL            equ       $00000073           ;*** TPM2C4VL - TPM 2 Timer Channel 4 Value Register Low


;*** SRS - System Reset Status
SRS                 equ       $00001800           ;*** SRS - System Reset Status
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD             equ       1                   ; Low Voltage Detect
SRS_ICG             equ       2                   ; Internal Clock Generation Module Reset
SRS_ILOP            equ       4                   ; Illegal Opcode
SRS_COP             equ       5                   ; Computer Operating Properly (COP) Watchdog
SRS_PIN             equ       6                   ; External Reset Pin
SRS_POR             equ       7                   ; Power-On Reset
; bit position masks
mSRS_LVD            equ       %00000010
mSRS_ICG            equ       %00000100
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


;*** SOPT - System Options Register
SOPT                equ       $00001802           ;*** SOPT - System Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT_BKGDPE         equ       1                   ; Background Debug Mode Pin Enable
SOPT_STOPE          equ       5                   ; Stop Mode Enable
SOPT_COPT           equ       6                   ; COP Watchdog Timeout
SOPT_COPE           equ       7                   ; COP Watchdog Enable
; bit position masks
mSOPT_BKGDPE        equ       %00000010
mSOPT_STOPE         equ       %00100000
mSOPT_COPT          equ       %01000000
mSOPT_COPE          equ       %10000000


;*** SDID - System Integration Module Part ID Register
SDID                equ       $00001806           ;*** SDID - System Integration Module Part ID Register


;*** SDIDH - System Integration Module Part ID Register High
SDIDH               equ       $00001806           ;*** SDIDH - System Integration Module Part ID Register High
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8           equ       0                   ; Part Identification Number 8
SDIDH_ID9           equ       1                   ; Part Identification Number 9
SDIDH_ID10          equ       2                   ; Part Identification Number 10
SDIDH_ID11          equ       3                   ; Part Identification Number 11
SDIDH_REV0          equ       4                   ; Revision Number 0
SDIDH_REV1          equ       5                   ; Revision Number 1
SDIDH_REV2          equ       6                   ; Revision Number 2
SDIDH_REV3          equ       7                   ; Revision Number 3
; bit position masks
mSDIDH_ID8          equ       %00000001
mSDIDH_ID9          equ       %00000010
mSDIDH_ID10         equ       %00000100
mSDIDH_ID11         equ       %00001000
mSDIDH_REV0         equ       %00010000
mSDIDH_REV1         equ       %00100000
mSDIDH_REV2         equ       %01000000
mSDIDH_REV3         equ       %10000000


;*** SDIDL - System Integration Module Part ID Register Low
SDIDL               equ       $00001807           ;*** SDIDL - System Integration Module Part ID Register Low
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDL_ID0           equ       0                   ; Part Identification Number 0
SDIDL_ID1           equ       1                   ; Part Identification Number 1
SDIDL_ID2           equ       2                   ; Part Identification Number 2
SDIDL_ID3           equ       3                   ; Part Identification Number 3
SDIDL_ID4           equ       4                   ; Part Identification Number 4
SDIDL_ID5           equ       5                   ; Part Identification Number 5
SDIDL_ID6           equ       6                   ; Part Identification Number 6
SDIDL_ID7           equ       7                   ; Part Identification Number 7
; bit position masks
mSDIDL_ID0          equ       %00000001
mSDIDL_ID1          equ       %00000010
mSDIDL_ID2          equ       %00000100
mSDIDL_ID3          equ       %00001000
mSDIDL_ID4          equ       %00010000
mSDIDL_ID5          equ       %00100000
mSDIDL_ID6          equ       %01000000
mSDIDL_ID7          equ       %10000000


;*** SRTISC - System RTI Status and Control Register
SRTISC              equ       $00001808           ;*** SRTISC - System RTI Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRTISC_RTIS0        equ       0                   ; Real-Time Interrupt Delay Select Bit 0
SRTISC_RTIS1        equ       1                   ; Real-Time Interrupt Delay Select Bit 1
SRTISC_RTIS2        equ       2                   ; Real-Time Interrupt Delay Select Bit 2
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


;*** SPMSC1 - PM Status and Control 1 Register
SPMSC1              equ       $00001809           ;*** SPMSC1 - PM Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE        equ       5                   ; Low-Voltage Detect Interrrupt Enable
SPMSC1_LVDACK       equ       6                   ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF         equ       7                   ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_LVDE        equ       %00000100
mSPMSC1_LVDSE       equ       %00001000
mSPMSC1_LVDRE       equ       %00010000
mSPMSC1_LVDIE       equ       %00100000
mSPMSC1_LVDACK      equ       %01000000
mSPMSC1_LVDF        equ       %10000000


;*** SPMSC2 - PM Status and Control 2 Register
SPMSC2              equ       $0000180A           ;*** SPMSC2 - PM Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC         equ       0                   ; Partial Power Down Control
SPMSC2_PDC          equ       1                   ; Power Down Control
SPMSC2_PPDACK       equ       2                   ; Partial Power Down Acknowlege
SPMSC2_PPDF         equ       3                   ; Partial Power Down Flag
SPMSC2_LVWV         equ       4                   ; Low-Voltage Warning Voltage Select
SPMSC2_LVDV         equ       5                   ; Low-Voltage Detect Voltage Select
SPMSC2_LVWACK       equ       6                   ; Low-Voltage Warning Acknowlege
SPMSC2_LVWF         equ       7                   ; Low-Voltage Warning Flag
; bit position masks
mSPMSC2_PPDC        equ       %00000001
mSPMSC2_PDC         equ       %00000010
mSPMSC2_PPDACK      equ       %00000100
mSPMSC2_PPDF        equ       %00001000
mSPMSC2_LVWV        equ       %00010000
mSPMSC2_LVDV        equ       %00100000
mSPMSC2_LVWACK      equ       %01000000
mSPMSC2_LVWF        equ       %10000000


;*** DBGCAH - Debug Comparator A High Register
DBGCAH              equ       $00001810           ;*** DBGCAH - Debug Comparator A High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAH_Bit8         equ       0                   ; Debug Comparator A Bit 8
DBGCAH_Bit9         equ       1                   ; Debug Comparator A Bit 9
DBGCAH_Bit10        equ       2                   ; Debug Comparator A Bit 10
DBGCAH_Bit11        equ       3                   ; Debug Comparator A Bit 11
DBGCAH_Bit12        equ       4                   ; Debug Comparator A Bit 12
DBGCAH_Bit13        equ       5                   ; Debug Comparator A Bit 13
DBGCAH_Bit14        equ       6                   ; Debug Comparator A Bit 14
DBGCAH_Bit15        equ       7                   ; Debug Comparator A Bit 15
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
DBGCAL_Bit0         equ       0                   ; Debug Comparator A Bit 0
DBGCAL_Bit1         equ       1                   ; Debug Comparator A Bit 1
DBGCAL_Bit2         equ       2                   ; Debug Comparator A Bit 2
DBGCAL_Bit3         equ       3                   ; Debug Comparator A Bit 3
DBGCAL_Bit4         equ       4                   ; Debug Comparator A Bit 4
DBGCAL_Bit5         equ       5                   ; Debug Comparator A Bit 5
DBGCAL_Bit6         equ       6                   ; Debug Comparator A Bit 6
DBGCAL_Bit7         equ       7                   ; Debug Comparator A Bit 7
; bit position masks
mDBGCAL_Bit0        equ       %00000001
mDBGCAL_Bit1        equ       %00000010
mDBGCAL_Bit2        equ       %00000100
mDBGCAL_Bit3        equ       %00001000
mDBGCAL_Bit4        equ       %00010000
mDBGCAL_Bit5        equ       %00100000
mDBGCAL_Bit6        equ       %01000000
mDBGCAL_Bit7        equ       %10000000


;*** DBGCBH - Debug Comparator B High Register
DBGCBH              equ       $00001812           ;*** DBGCBH - Debug Comparator B High Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBH_Bit8         equ       0                   ; Debug Comparator B Bit 8
DBGCBH_Bit9         equ       1                   ; Debug Comparator B Bit 9
DBGCBH_Bit10        equ       2                   ; Debug Comparator B Bit 10
DBGCBH_Bit11        equ       3                   ; Debug Comparator B Bit 11
DBGCBH_Bit12        equ       4                   ; Debug Comparator B Bit 12
DBGCBH_Bit13        equ       5                   ; Debug Comparator B Bit 13
DBGCBH_Bit14        equ       6                   ; Debug Comparator B Bit 14
DBGCBH_Bit15        equ       7                   ; Debug Comparator B Bit 15
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
DBGCBL_Bit0         equ       0                   ; Debug Comparator B Bit 0
DBGCBL_Bit1         equ       1                   ; Debug Comparator B Bit 1
DBGCBL_Bit2         equ       2                   ; Debug Comparator B Bit 2
DBGCBL_Bit3         equ       3                   ; Debug Comparator B Bit 3
DBGCBL_Bit4         equ       4                   ; Debug Comparator B Bit 4
DBGCBL_Bit5         equ       5                   ; Debug Comparator B Bit 5
DBGCBL_Bit6         equ       6                   ; Debug Comparator B Bit 6
DBGCBL_Bit7         equ       7                   ; Debug Comparator B Bit 7
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
DBGFH_Bit8          equ       0                   ; Debug FIFO Bit 8
DBGFH_Bit9          equ       1                   ; Debug FIFO Bit 9
DBGFH_Bit10         equ       2                   ; Debug FIFO Bit 10
DBGFH_Bit11         equ       3                   ; Debug FIFO Bit 11
DBGFH_Bit12         equ       4                   ; Debug FIFO Bit 12
DBGFH_Bit13         equ       5                   ; Debug FIFO Bit 13
DBGFH_Bit14         equ       6                   ; Debug FIFO Bit 14
DBGFH_Bit15         equ       7                   ; Debug FIFO Bit 15
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
DBGFL_Bit0          equ       0                   ; Debug FIFO Bit 0
DBGFL_Bit1          equ       1                   ; Debug FIFO Bit 1
DBGFL_Bit2          equ       2                   ; Debug FIFO Bit 2
DBGFL_Bit3          equ       3                   ; Debug FIFO Bit 3
DBGFL_Bit4          equ       4                   ; Debug FIFO Bit 4
DBGFL_Bit5          equ       5                   ; Debug FIFO Bit 5
DBGFL_Bit6          equ       6                   ; Debug FIFO Bit 6
DBGFL_Bit7          equ       7                   ; Debug FIFO Bit 7
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
FCDIV_DIV0          equ       0                   ; Divisor for FLASH Clock Divider Bit 0
FCDIV_DIV1          equ       1                   ; Divisor for FLASH Clock Divider Bit 1
FCDIV_DIV2          equ       2                   ; Divisor for FLASH Clock Divider Bit 2
FCDIV_DIV3          equ       3                   ; Divisor for FLASH Clock Divider Bit 3
FCDIV_DIV4          equ       4                   ; Divisor for FLASH Clock Divider Bit 4
FCDIV_DIV5          equ       5                   ; Divisor for FLASH Clock Divider Bit 5
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
FOPT_SEC00          equ       0                   ; Security State Code Bit 0
FOPT_SEC01          equ       1                   ; Security State Code Bit 1
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
FPROT_FPS0          equ       3                   ; FLASH Protect Size Select Bit 0
FPROT_FPS1          equ       4                   ; FLASH Protect Size Select Bit 1
FPROT_FPS2          equ       5                   ; FLASH Protect Size Select Bit 2
FPROT_FPDIS         equ       6                   ; FLASH Protection Disable
FPROT_FPOPEN        equ       7                   ; Open Unprotected FLASH for Program/Erase
; bit position masks
mFPROT_FPS0         equ       %00001000
mFPROT_FPS1         equ       %00010000
mFPROT_FPS2         equ       %00100000
mFPROT_FPDIS        equ       %01000000
mFPROT_FPOPEN       equ       %10000000


;*** FSTAT - FLASH Status Register
FSTAT               equ       $00001825           ;*** FSTAT - FLASH Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_FBLANK        equ       2                   ; FLASH Verified as All Blank (erased) Flag
FSTAT_FACCERR       equ       4                   ; Access Error Flag
FSTAT_FPVIOL        equ       5                   ; Protection Violation Flag
FSTAT_FCCF          equ       6                   ; FLASH Command Complete Flag
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
NVBACKKEY0_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY0_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY0_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY0_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY0_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY0_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY0_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY0_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY1_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY1_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY1_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY1_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY1_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY1_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY1_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY1_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY2_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY2_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY2_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY2_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY2_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY2_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY2_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY2_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY3_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY3_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY3_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY3_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY3_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY3_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY3_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY3_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY4_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY4_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY4_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY4_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY4_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY4_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY4_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY4_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY5_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY5_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY5_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY5_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY5_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY5_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY5_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY5_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY6_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY6_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY6_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY6_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY6_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY6_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY6_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY6_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVBACKKEY7_KEY0     equ       0                   ; Backdoor Comparison Key bits, bit 0
NVBACKKEY7_KEY1     equ       1                   ; Backdoor Comparison Key bits, bit 1
NVBACKKEY7_KEY2     equ       2                   ; Backdoor Comparison Key bits, bit 2
NVBACKKEY7_KEY3     equ       3                   ; Backdoor Comparison Key bits, bit 3
NVBACKKEY7_KEY4     equ       4                   ; Backdoor Comparison Key bits, bit 4
NVBACKKEY7_KEY5     equ       5                   ; Backdoor Comparison Key bits, bit 5
NVBACKKEY7_KEY6     equ       6                   ; Backdoor Comparison Key bits, bit 6
NVBACKKEY7_KEY7     equ       7                   ; Backdoor Comparison Key bits, bit 7
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
NVPROT_FPS0         equ       3                   ; FLASH Protect Size Select Bit 0
NVPROT_FPS1         equ       4                   ; FLASH Protect Size Select Bit 1
NVPROT_FPS2         equ       5                   ; FLASH Protect Size Select Bit 2
NVPROT_FPDIS        equ       6                   ; FLASH Protection Disable
NVPROT_FPOPEN       equ       7                   ; Open Unprotected FLASH for Program/Erase
; bit position masks
mNVPROT_FPS0        equ       %00001000
mNVPROT_FPS1        equ       %00010000
mNVPROT_FPS2        equ       %00100000
mNVPROT_FPDIS       equ       %01000000
mNVPROT_FPOPEN      equ       %10000000


;*** NVOPT - Non-volatile FLASH Options Register
NVOPT               equ       $0000FFBF           ;*** NVOPT - Non-volatile FLASH Options Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC00         equ       0                   ; Security State Code Bit 0
NVOPT_SEC01         equ       1                   ; Security State Code Bit 1
NVOPT_FNORED        equ       6                   ; Vector Redirection Disable
NVOPT_KEYEN         equ       7                   ; Backdoor Key Mechanism Enable
; bit position masks
mNVOPT_SEC00        equ       %00000001
mNVOPT_SEC01        equ       %00000010
mNVOPT_FNORED       equ       %01000000
mNVOPT_KEYEN        equ       %10000000



; Flash commands
mBlank              equ       $05
mByteProg           equ       $20
mBurstProg          equ       $25
mMassErase          equ       $41
mPageErase          equ       $40


;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************
       #ifndef  __GENERATE_APPLICATION__                            ; not supported for absolute assembler
       #endif

; EOF
