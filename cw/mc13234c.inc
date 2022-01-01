;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; Based on CPU DB MC13234C, version 3.00.000 (RegistersPrg V2.33)

; ###################################################################
;     Filename  : mc13234c.inc
;     Processor : MC13234C
;     FileFormat: V2.33
;     DataSheet : MC13237RM rev. 1.7 5/2013
;     Compiler  : CodeWarrior compiler
;     Date/Time : 3/26/2014, 8:23 PM
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2014 Freescale Semiconductor, Inc.
;     All Rights Reserved.
;
;     Redistribution and use in source and binary forms, with or without modification,
;     are permitted provided that the following conditions are met:
;
;     o Redistributions of source code must retain the above copyright notice, this list
;       of conditions and the following disclaimer.
;
;     o Redistributions in binary form must reproduce the above copyright notice, this
;       list of conditions and the following disclaimer in the documentation and/or
;       other materials provided with the distribution.
;
;     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
;       contributors may be used to endorse or promote products derived from this
;       software without specific prior written permission.
;
;     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
;     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
;     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
;     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
;     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
;     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
;     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;     http: www.freescale.com
;     mail: support@freescale.com
;
;     CPU Registers Revisions:
;      - 16.10.2012, V3.00.1:
;              - Flash commands added to header file
;      - 7.11.2013, V3.00.2:
;              - Updates for new silicon revision
;              - Registers updated according to the new reference manual revision - Rev. 1.7, 5/2013
;              - New part ID
;              - New flash size, new ram size
;              - Updated SOPT1 SOPT2 SPMSC2 SOMC1 SCGC2 registers
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
ROM                 equ       $00002080
ROM_END             equ       $00007FFF
RAM                 equ       $00000080
RAM_END             equ       $000000FF
XRAM                equ       $00000100
XRAM_END            equ       $000017FF
RAM1                equ       $00001880
RAM1_END            equ       $0000207F
XROM                equ       $0000C000
XROM_END            equ       $0000FFAD
ROM2Start           equ       $0000FFC0
ROM2End             equ       $0000FFCB
PPAGE_0Start        equ       $00008000
PPAGE_0End          equ       $0000A07F
PPAGE_2Start        equ       $00028000
PPAGE_2End          equ       $0002BFFF
PPAGE_4Start        equ       $00048000
PPAGE_4End          equ       $0004BFFF
PPAGE_5Start        equ       $00058000
PPAGE_5End          equ       $0005BFFF
PPAGE_6Start        equ       $00068000
PPAGE_6End          equ       $0006BFFF
PPAGE_7Start        equ       $00078000
PPAGE_7End          equ       $0007BFFF
;
Vrtc                equ       $0000FFCC
Vkeyboard1          equ       $0000FFCE
Vkeyboard2          equ       $0000FFD0
Viicx               equ       $0000FFD2
Vcmt                equ       $0000FFD4
Vscitx              equ       $0000FFD6
Vscirx              equ       $0000FFD8
Vscierr             equ       $0000FFDA
Vspi                equ       $0000FFDC
Vtpm4ovf            equ       $0000FFDE
Vtpm4ch0            equ       $0000FFE0
Vtpm3ovf            equ       $0000FFE2
Vtpm3ch0            equ       $0000FFE4
Vtpm2ovf            equ       $0000FFE6
Vtpm2ch0            equ       $0000FFE8
Vtpm1ovf            equ       $0000FFEA
Vtpm1ch0            equ       $0000FFEC
Vaes128             equ       $0000FFEE
Vrx_watermark_802_15_4 equ       $0000FFF0
Vtimers_802_15_4    equ       $0000FFF2
Vtx_802_15_4        equ       $0000FFF4
Vrx_802_15_4        equ       $0000FFF6
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

;*** TPM1SC - TPM1 Status and Control Register
TPM1SC              equ       $00000008           ;*** TPM1SC - TPM1 Status and Control Register
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
TPM1CNT             equ       $00000009           ;*** TPM1CNT - TPM1 Timer Counter Register

;*** TPM1CNTH - TPM1 Timer Counter Register High
TPM1CNTH            equ       $00000009           ;*** TPM1CNTH - TPM1 Timer Counter Register High

;*** TPM1CNTL - TPM1 Timer Counter Register Low
TPM1CNTL            equ       $0000000A           ;*** TPM1CNTL - TPM1 Timer Counter Register Low

;*** TPM1MOD - TPM1 Timer Counter Modulo Register
TPM1MOD             equ       $0000000B           ;*** TPM1MOD - TPM1 Timer Counter Modulo Register

;*** TPM1MODH - TPM1 Timer Counter Modulo Register High
TPM1MODH            equ       $0000000B           ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High

;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low
TPM1MODL            equ       $0000000C           ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low

;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
TPM1C0SC            equ       $0000000D           ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register
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
TPM1C0V             equ       $0000000E           ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register

;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High
TPM1C0VH            equ       $0000000E           ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High

;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low
TPM1C0VL            equ       $0000000F           ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low

;*** TPM2SC - TPM2 Status and Control Register
TPM2SC              equ       $00000010           ;*** TPM2SC - TPM2 Status and Control Register
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
TPM2CNT             equ       $00000011           ;*** TPM2CNT - TPM2 Timer Counter Register

;*** TPM2CNTH - TPM2 Timer Counter Register High
TPM2CNTH            equ       $00000011           ;*** TPM2CNTH - TPM2 Timer Counter Register High

;*** TPM2CNTL - TPM2 Timer Counter Register Low
TPM2CNTL            equ       $00000012           ;*** TPM2CNTL - TPM2 Timer Counter Register Low

;*** TPM2MOD - TPM2 Timer Counter Modulo Register
TPM2MOD             equ       $00000013           ;*** TPM2MOD - TPM2 Timer Counter Modulo Register

;*** TPM2MODH - TPM2 Timer Counter Modulo Register High
TPM2MODH            equ       $00000013           ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High

;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low
TPM2MODL            equ       $00000014           ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low

;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
TPM2C0SC            equ       $00000015           ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register
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
TPM2C0V             equ       $00000016           ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register

;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High
TPM2C0VH            equ       $00000016           ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High

;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low
TPM2C0VL            equ       $00000017           ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low

;*** TPM3SC - TPM3 Status and Control Register
TPM3SC              equ       $00000018           ;*** TPM3SC - TPM3 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM3SC_PS0          equ       0                   ; Prescale Divisor Select Bit 0
TPM3SC_PS1          equ       1                   ; Prescale Divisor Select Bit 1
TPM3SC_PS2          equ       2                   ; Prescale Divisor Select Bit 2
TPM3SC_CLKSA        equ       3                   ; Clock Source Select A
TPM3SC_CLKSB        equ       4                   ; Clock Source Select B
TPM3SC_CPWMS        equ       5                   ; Center-Aligned PWM Select
TPM3SC_TOIE         equ       6                   ; Timer Overflow Interrupt Enable
TPM3SC_TOF          equ       7                   ; Timer Overflow Flag
; bit position masks
mTPM3SC_PS0         equ       %00000001
mTPM3SC_PS1         equ       %00000010
mTPM3SC_PS2         equ       %00000100
mTPM3SC_CLKSA       equ       %00001000
mTPM3SC_CLKSB       equ       %00010000
mTPM3SC_CPWMS       equ       %00100000
mTPM3SC_TOIE        equ       %01000000
mTPM3SC_TOF         equ       %10000000

;*** TPM3CNT - TPM3 Timer Counter Register
TPM3CNT             equ       $00000019           ;*** TPM3CNT - TPM3 Timer Counter Register

;*** TPM3CNTH - TPM3 Timer Counter Register High
TPM3CNTH            equ       $00000019           ;*** TPM3CNTH - TPM3 Timer Counter Register High

;*** TPM3CNTL - TPM3 Timer Counter Register Low
TPM3CNTL            equ       $0000001A           ;*** TPM3CNTL - TPM3 Timer Counter Register Low

;*** TPM3MOD - TPM3 Timer Counter Modulo Register
TPM3MOD             equ       $0000001B           ;*** TPM3MOD - TPM3 Timer Counter Modulo Register

;*** TPM3MODH - TPM3 Timer Counter Modulo Register High
TPM3MODH            equ       $0000001B           ;*** TPM3MODH - TPM3 Timer Counter Modulo Register High

;*** TPM3MODL - TPM3 Timer Counter Modulo Register Low
TPM3MODL            equ       $0000001C           ;*** TPM3MODL - TPM3 Timer Counter Modulo Register Low

;*** TPM3C0SC - TPM3 Timer Channel 0 Status and Control Register
TPM3C0SC            equ       $0000001D           ;*** TPM3C0SC - TPM3 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM3C0SC_ELS0A      equ       2                   ; Edge/Level Select Bit A
TPM3C0SC_ELS0B      equ       3                   ; Edge/Level Select Bit B
TPM3C0SC_MS0A       equ       4                   ; Mode Select A for TPM Channel 0
TPM3C0SC_MS0B       equ       5                   ; Mode Select B for TPM Channel 0
TPM3C0SC_CH0IE      equ       6                   ; Channel 0 Interrupt Enable
TPM3C0SC_CH0F       equ       7                   ; Channel 0 Flag
; bit position masks
mTPM3C0SC_ELS0A     equ       %00000100
mTPM3C0SC_ELS0B     equ       %00001000
mTPM3C0SC_MS0A      equ       %00010000
mTPM3C0SC_MS0B      equ       %00100000
mTPM3C0SC_CH0IE     equ       %01000000
mTPM3C0SC_CH0F      equ       %10000000

;*** TPM3C0V - TPM3 Timer Channel 0 Value Register
TPM3C0V             equ       $0000001E           ;*** TPM3C0V - TPM3 Timer Channel 0 Value Register

;*** TPM3C0VH - TPM3 Timer Channel 0 Value Register High
TPM3C0VH            equ       $0000001E           ;*** TPM3C0VH - TPM3 Timer Channel 0 Value Register High

;*** TPM3C0VL - TPM3 Timer Channel 0 Value Register Low
TPM3C0VL            equ       $0000001F           ;*** TPM3C0VL - TPM3 Timer Channel 0 Value Register Low

;*** AES_CONTROL1 - AES 128 Control 1 Register
AES_CONTROL1        equ       $00000020           ;*** AES_CONTROL1 - AES 128 Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
AES_CONTROL1_AES_MSK equ       0                   ; AES128 Interrupt Mask
AES_CONTROL1_LOAD_MAC equ       1                   ; MAC preload
AES_CONTROL1_AES    equ       2                   ; AES mode
AES_CONTROL1_CBC    equ       3                   ; CBC-MAC generation
AES_CONTROL1_CTR    equ       4                   ; Counter encryption mode
AES_CONTROL1_SELFTST equ       5                   ; Self test mode
AES_CONTROL1_START  equ       6                   ; CBC or CTR or CCM or AES mode encryption start
AES_CONTROL1_CLEAR  equ       7                   ; ASM memory clear
; bit position masks
mAES_CONTROL1_AES_MSK equ       %00000001
mAES_CONTROL1_LOAD_MAC equ       %00000010
mAES_CONTROL1_AES   equ       %00000100
mAES_CONTROL1_CBC   equ       %00001000
mAES_CONTROL1_CTR   equ       %00010000
mAES_CONTROL1_SELFTST equ       %00100000
mAES_CONTROL1_START equ       %01000000
mAES_CONTROL1_CLEAR equ       %10000000

;*** AES_CONTROL2 - AES 128 Control Register 2
AES_CONTROL2        equ       $00000021           ;*** AES_CONTROL2 - AES 128 Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
AES_CONTROL2_TSTPAS equ       1                   ; Self test passed
AES_CONTROL2_IRQ_FLAG equ       2                   ; AES Interrupt flag
AES_CONTROL2_DATA_REG_TYPE_SELECT0 equ       5                   ; This register selects the type of data to be written to or read from the 16x8
AES_CONTROL2_DATA_REG_TYPE_SELECT1 equ       6                   ; This register selects the type of data to be written to or read from the 16x8
AES_CONTROL2_DATA_REG_TYPE_SELECT2 equ       7                   ; This register selects the type of data to be written to or read from the 16x8
; bit position masks
mAES_CONTROL2_TSTPAS equ       %00000010
mAES_CONTROL2_IRQ_FLAG equ       %00000100
mAES_CONTROL2_DATA_REG_TYPE_SELECT0 equ       %00100000
mAES_CONTROL2_DATA_REG_TYPE_SELECT1 equ       %01000000
mAES_CONTROL2_DATA_REG_TYPE_SELECT2 equ       %10000000

;*** ASM_Data_0 - AES 128 Data Register 0
ASM_Data_0          equ       $00000022           ;*** ASM_Data_0 - AES 128 Data Register 0

;*** ASM_Data_1 - AES 128 Data Register 1
ASM_Data_1          equ       $00000023           ;*** ASM_Data_1 - AES 128 Data Register 1

;*** ASM_Data_2 - AES 128 Data Register 2
ASM_Data_2          equ       $00000024           ;*** ASM_Data_2 - AES 128 Data Register 2

;*** ASM_Data_3 - AES 128 Data Register 3
ASM_Data_3          equ       $00000025           ;*** ASM_Data_3 - AES 128 Data Register 3

;*** ASM_Data_4 - AES 128 Data Register 4
ASM_Data_4          equ       $00000026           ;*** ASM_Data_4 - AES 128 Data Register 4

;*** ASM_Data_5 - AES 128 Data Register 5
ASM_Data_5          equ       $00000027           ;*** ASM_Data_5 - AES 128 Data Register 5

;*** ASM_Data_6 - AES 128 Data Register 6
ASM_Data_6          equ       $00000028           ;*** ASM_Data_6 - AES 128 Data Register 6

;*** ASM_Data_7 - AES 128 Data Register 7
ASM_Data_7          equ       $00000029           ;*** ASM_Data_7 - AES 128 Data Register 7

;*** ASM_Data_8 - AES 128 Data Register 8
ASM_Data_8          equ       $0000002A           ;*** ASM_Data_8 - AES 128 Data Register 8

;*** ASM_Data_9 - AES 128 Data Register 9
ASM_Data_9          equ       $0000002B           ;*** ASM_Data_9 - AES 128 Data Register 9

;*** ASM_Data_A - AES 128 Data Register A
ASM_Data_A          equ       $0000002C           ;*** ASM_Data_A - AES 128 Data Register A

;*** ASM_Data_B - AES 128 Data Register B
ASM_Data_B          equ       $0000002D           ;*** ASM_Data_B - AES 128 Data Register B

;*** ASM_Data_C - AES 128 Data Register C
ASM_Data_C          equ       $0000002E           ;*** ASM_Data_C - AES 128 Data Register C

;*** ASM_Data_D - AES 128 Data Register D
ASM_Data_D          equ       $0000002F           ;*** ASM_Data_D - AES 128 Data Register D

;*** ASM_Data_E - AES 128 Data Register E
ASM_Data_E          equ       $00000030           ;*** ASM_Data_E - AES 128 Data Register E

;*** ASM_Data_F - AES 128 Data Register F
ASM_Data_F          equ       $00000031           ;*** ASM_Data_F - AES 128 Data Register F

;*** KBI1SC - KBI1 Status and Control Register
KBI1SC              equ       $00000032           ;*** KBI1SC - KBI1 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1SC_KBIMOD       equ       0                   ; Keyboard Detection Mode
KBI1SC_KBIE         equ       1                   ; Keyboard Interrupt Enable
KBI1SC_KBACK        equ       2                   ; Keyboard Interrupt Acknowledge
KBI1SC_KBF          equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI1SC_KBIMOD      equ       %00000001
mKBI1SC_KBIE        equ       %00000010
mKBI1SC_KBACK       equ       %00000100
mKBI1SC_KBF         equ       %00001000

;*** KBI1PE - KBI1 Pin Enable Register
KBI1PE              equ       $00000033           ;*** KBI1PE - KBI1 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI1PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI1PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI1PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
KBI1PE_KBIPE4       equ       4                   ; Keyboard Pin Enable for KBI Port Bit 4
KBI1PE_KBIPE5       equ       5                   ; Keyboard Pin Enable for KBI Port Bit 5
KBI1PE_KBIPE6       equ       6                   ; Keyboard Pin Enable for KBI Port Bit 6
KBI1PE_KBIPE7       equ       7                   ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBI1PE_KBIPE0      equ       %00000001
mKBI1PE_KBIPE1      equ       %00000010
mKBI1PE_KBIPE2      equ       %00000100
mKBI1PE_KBIPE3      equ       %00001000
mKBI1PE_KBIPE4      equ       %00010000
mKBI1PE_KBIPE5      equ       %00100000
mKBI1PE_KBIPE6      equ       %01000000
mKBI1PE_KBIPE7      equ       %10000000

;*** KBI1ES - KBI1 Edge Select Register
KBI1ES              equ       $00000034           ;*** KBI1ES - KBI1 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI1ES_KBEDG0       equ       0                   ; Keyboard Edge Select Bit 0
KBI1ES_KBEDG1       equ       1                   ; Keyboard Edge Select Bit 1
KBI1ES_KBEDG2       equ       2                   ; Keyboard Edge Select Bit 2
KBI1ES_KBEDG3       equ       3                   ; Keyboard Edge Select Bit 3
KBI1ES_KBEDG4       equ       4                   ; Keyboard Edge Select Bit 4
KBI1ES_KBEDG5       equ       5                   ; Keyboard Edge Select Bit 5
KBI1ES_KBEDG6       equ       6                   ; Keyboard Edge Select Bit 6
KBI1ES_KBEDG7       equ       7                   ; Keyboard Edge Select Bit 7
; bit position masks
mKBI1ES_KBEDG0      equ       %00000001
mKBI1ES_KBEDG1      equ       %00000010
mKBI1ES_KBEDG2      equ       %00000100
mKBI1ES_KBEDG3      equ       %00001000
mKBI1ES_KBEDG4      equ       %00010000
mKBI1ES_KBEDG5      equ       %00100000
mKBI1ES_KBEDG6      equ       %01000000
mKBI1ES_KBEDG7      equ       %10000000

;*** KBI2SC - KBI2 Status and Control Register
KBI2SC              equ       $00000035           ;*** KBI2SC - KBI2 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2SC_KBIMOD       equ       0                   ; Keyboard Detection Mode
KBI2SC_KBIE         equ       1                   ; Keyboard Interrupt Enable
KBI2SC_KBACK        equ       2                   ; Keyboard Interrupt Acknowledge
KBI2SC_KBF          equ       3                   ; Keyboard Interrupt Flag
; bit position masks
mKBI2SC_KBIMOD      equ       %00000001
mKBI2SC_KBIE        equ       %00000010
mKBI2SC_KBACK       equ       %00000100
mKBI2SC_KBF         equ       %00001000

;*** KBI2PE - KBI2 Pin Enable Register
KBI2PE              equ       $00000036           ;*** KBI2PE - KBI2 Pin Enable Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2PE_KBIPE0       equ       0                   ; Keyboard Pin Enable for KBI Port Bit 0
KBI2PE_KBIPE1       equ       1                   ; Keyboard Pin Enable for KBI Port Bit 1
KBI2PE_KBIPE2       equ       2                   ; Keyboard Pin Enable for KBI Port Bit 2
KBI2PE_KBIPE3       equ       3                   ; Keyboard Pin Enable for KBI Port Bit 3
; bit position masks
mKBI2PE_KBIPE0      equ       %00000001
mKBI2PE_KBIPE1      equ       %00000010
mKBI2PE_KBIPE2      equ       %00000100
mKBI2PE_KBIPE3      equ       %00001000

;*** KBI2ES - KBI2 Edge Select Register
KBI2ES              equ       $00000037           ;*** KBI2ES - KBI2 Edge Select Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBI2ES_KBEDG0       equ       0                   ; Keyboard Edge Select Bit 0
KBI2ES_KBEDG1       equ       1                   ; Keyboard Edge Select Bit 1
KBI2ES_KBEDG2       equ       2                   ; Keyboard Edge Select Bit 2
KBI2ES_KBEDG3       equ       3                   ; Keyboard Edge Select Bit 3
; bit position masks
mKBI2ES_KBEDG0      equ       %00000001
mKBI2ES_KBEDG1      equ       %00000010
mKBI2ES_KBEDG2      equ       %00000100
mKBI2ES_KBEDG3      equ       %00001000

;*** SCI1BD - SCI1 Baud Rate Register
SCI1BD              equ       $00000038           ;*** SCI1BD - SCI1 Baud Rate Register

;*** SCI1BDH - SCI1 Baud Rate Register High
SCI1BDH             equ       $00000038           ;*** SCI1BDH - SCI1 Baud Rate Register High
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
SCI1BDL             equ       $00000039           ;*** SCI1BDL - SCI1 Baud Rate Register Low
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
SCI1C1              equ       $0000003A           ;*** SCI1C1 - SCI1 Control Register 1
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
SCI1C2              equ       $0000003B           ;*** SCI1C2 - SCI1 Control Register 2
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
SCI1S1              equ       $0000003C           ;*** SCI1S1 - SCI1 Status Register 1
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
SCI1S2              equ       $0000003D           ;*** SCI1S2 - SCI1 Status Register 2
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
SCI1C3              equ       $0000003E           ;*** SCI1C3 - SCI1 Control Register 3
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
SCI1D               equ       $0000003F           ;*** SCI1D - SCI1 Data Register
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

;*** PHY_TXD_ADR_PNTR0 - Transmit Data Pointer Register 0
PHY_TXD_ADR_PNTR0   equ       $00000040           ;*** PHY_TXD_ADR_PNTR0 - Transmit Data Pointer Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_TXD_ADR_PNTR0_TXD_ADR_PNTR equ       0                   ; Transmit Data Pointer, bit 8
; bit position masks
mPHY_TXD_ADR_PNTR0_TXD_ADR_PNTR equ       %00011111

;*** PHY_TXD_ADR_PNTR1 - Transmit Data Pointer Register 1
PHY_TXD_ADR_PNTR1   equ       $00000041           ;*** PHY_TXD_ADR_PNTR1 - Transmit Data Pointer Register 1

;*** PHY_RXD_ADR_PNTR0 - Receive Data Pointer Register 0
PHY_RXD_ADR_PNTR0   equ       $00000042           ;*** PHY_RXD_ADR_PNTR0 - Receive Data Pointer Register 0
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_RXD_ADR_PNTR0_RXD_ADR_PNTR0 equ       0                   ; Receive Data Pointer, bit 8
; bit position masks
mPHY_RXD_ADR_PNTR0_RXD_ADR_PNTR0 equ       %00011111

;*** PHY_RXD_ADR_PNTR1 - Receive Data Pointer Register 1
PHY_RXD_ADR_PNTR1   equ       $00000043           ;*** PHY_RXD_ADR_PNTR1 - Receive Data Pointer Register 1

;*** PHY_CNTRL1 - Transceiver Control Register 1
PHY_CNTRL1          equ       $00000044           ;*** PHY_CNTRL1 - Transceiver Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_CNTRL1_XCVSEQ0  equ       0                   ; Transceiver Sequence, bit 0, bit 0
PHY_CNTRL1_XCVSEQ1  equ       1                   ; Transceiver Sequence, bit 0, bit 1
PHY_CNTRL1_XCVSEQ2  equ       2                   ; Transceiver Sequence, bit 0, bit 2
PHY_CNTRL1_AUTOACK  equ       3                   ; Auto Acknowledge Enable
PHY_CNTRL1_RXACKRQD equ       4                   ; RX Acknowledge Required
PHY_CNTRL1_CCABFRTX equ       5                   ; Clear Channel Assessment Before Transmit
PHY_CNTRL1_SLOTTED  equ       6                   ; Slotted Mode
PHY_CNTRL1_TMRTRIGEN equ       7                   ; Timer Trigger Enable
; bit position masks
mPHY_CNTRL1_XCVSEQ0 equ       %00000001
mPHY_CNTRL1_XCVSEQ1 equ       %00000010
mPHY_CNTRL1_XCVSEQ2 equ       %00000100
mPHY_CNTRL1_AUTOACK equ       %00001000
mPHY_CNTRL1_RXACKRQD equ       %00010000
mPHY_CNTRL1_CCABFRTX equ       %00100000
mPHY_CNTRL1_SLOTTED equ       %01000000
mPHY_CNTRL1_TMRTRIGEN equ       %10000000

;*** PHY_CNTRL2 - Transceiver Control Register 2
PHY_CNTRL2          equ       $00000045           ;*** PHY_CNTRL2 - Transceiver Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_CNTRL2_TC2EN    equ       0                   ; TC2 Prime Enable
PHY_CNTRL2_PROMISCUOUS equ       1                   ; Promiscuous Mode Enable
PHY_CNTRL2_TMRLOAD  equ       2                   ; Timer Load
PHY_CNTRL2_CCATYPE0 equ       3                   ; CCA Type, bit 0, bit 0
PHY_CNTRL2_CCATYPE1 equ       4                   ; CCA Type, bit 0, bit 1
PHY_CNTRL2_PANCORDNTR equ       5                   ; Pan Coordinator Enable
PHY_CNTRL2_TC3TMOUT equ       6                   ; Timer Comparator 3 Time-out
PHY_CNTRL2_TRCV_MSK equ       7                   ; Modem Interrupt Mask
; bit position masks
mPHY_CNTRL2_TC2EN   equ       %00000001
mPHY_CNTRL2_PROMISCUOUS equ       %00000010
mPHY_CNTRL2_TMRLOAD equ       %00000100
mPHY_CNTRL2_CCATYPE0 equ       %00001000
mPHY_CNTRL2_CCATYPE1 equ       %00010000
mPHY_CNTRL2_PANCORDNTR equ       %00100000
mPHY_CNTRL2_TC3TMOUT equ       %01000000
mPHY_CNTRL2_TRCV_MSK equ       %10000000

;*** PHY_CNTRL3 - Transceiver Control Register 3
PHY_CNTRL3          equ       $00000046           ;*** PHY_CNTRL3 - Transceiver Control Register 3
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_CNTRL3_SEQMSK   equ       0                   ; Sequence Interrupt Mask
PHY_CNTRL3_TXMSK    equ       1                   ; Transmitter Interrupt Mask
PHY_CNTRL3_RXMSK    equ       2                   ; Receiver Interrupt Mask
PHY_CNTRL3_CCAMSK   equ       3                   ; Clear Assessment Interrupt Mask
PHY_CNTRL3_RX_WMRK_MSK equ       4                   ; Received Count Water Mark interrupt
PHY_CNTRL3_FILTERFAIL_MSK equ       5                   ; Rx Packet filtering
PHY_CNTRL3_LO1_UNLOCK_MSK equ       6                   ; lo1_lock_irq
PHY_CNTRL3_CRC_MSK  equ       7                   ; Cyclic Redundancy Check
; bit position masks
mPHY_CNTRL3_SEQMSK  equ       %00000001
mPHY_CNTRL3_TXMSK   equ       %00000010
mPHY_CNTRL3_RXMSK   equ       %00000100
mPHY_CNTRL3_CCAMSK  equ       %00001000
mPHY_CNTRL3_RX_WMRK_MSK equ       %00010000
mPHY_CNTRL3_FILTERFAIL_MSK equ       %00100000
mPHY_CNTRL3_LO1_UNLOCK_MSK equ       %01000000
mPHY_CNTRL3_CRC_MSK equ       %10000000

;*** PHY_CNTRL4 - Transceiver Control Register 4
PHY_CNTRL4          equ       $00000047           ;*** PHY_CNTRL4 - Transceiver Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_CNTRL4_TMR1CMP_EN equ       0                   ; Timer Comparator 1 Enable
PHY_CNTRL4_TMR2CMP_EN equ       1                   ; Timer Comparator 2 Enable
PHY_CNTRL4_TMR3CMP_EN equ       2                   ; Timer Comparator 3 Enable
PHY_CNTRL4_TMR4CMP_EN equ       3                   ; Timer Comparator 4 Enable
PHY_CNTRL4_TMR1MSK  equ       4                   ; Timer Comparator 1 Interrupt Mask
PHY_CNTRL4_TMR2MSK  equ       5                   ; Timer Comparator 2 Interrupt Mask
PHY_CNTRL4_TMR3MSK  equ       6                   ; Timer Comparator 3 Interrupt Mask
PHY_CNTRL4_TMR4MSK  equ       7                   ; Timer Comparator 4 Interrupt Mask
; bit position masks
mPHY_CNTRL4_TMR1CMP_EN equ       %00000001
mPHY_CNTRL4_TMR2CMP_EN equ       %00000010
mPHY_CNTRL4_TMR3CMP_EN equ       %00000100
mPHY_CNTRL4_TMR4CMP_EN equ       %00001000
mPHY_CNTRL4_TMR1MSK equ       %00010000
mPHY_CNTRL4_TMR2MSK equ       %00100000
mPHY_CNTRL4_TMR3MSK equ       %01000000
mPHY_CNTRL4_TMR4MSK equ       %10000000

;*** PHY_SRC_CNTRL - Transceiver Source Address Control Register
PHY_SRC_CNTRL       equ       $00000048           ;*** PHY_SRC_CNTRL - Transceiver Source Address Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_SRC_CNTRL_INDEX_DISABLE equ       0                   ; Index Disable
PHY_SRC_CNTRL_INDEX_EN equ       1                   ; Index Enable
PHY_SRC_CNTRL_SRCADDR_EN equ       2                   ; Source Address Matching Enable
PHY_SRC_CNTRL_ACK_FRM_PND equ       3                   ; If SRCADDR_EN enable field is a 0, then ACK_FRM_PND gets copied into the TXACK frame
PHY_SRC_CNTRL_INDEX0 equ       4                   ; Index Field, bit 0, bit 0
PHY_SRC_CNTRL_INDEX1 equ       5                   ; Index Field, bit 0, bit 1
PHY_SRC_CNTRL_INDEX2 equ       6                   ; Index Field, bit 0, bit 2
PHY_SRC_CNTRL_INDEX3 equ       7                   ; Index Field, bit 0, bit 3
; bit position masks
mPHY_SRC_CNTRL_INDEX_DISABLE equ       %00000001
mPHY_SRC_CNTRL_INDEX_EN equ       %00000010
mPHY_SRC_CNTRL_SRCADDR_EN equ       %00000100
mPHY_SRC_CNTRL_ACK_FRM_PND equ       %00001000
mPHY_SRC_CNTRL_INDEX0 equ       %00010000
mPHY_SRC_CNTRL_INDEX1 equ       %00100000
mPHY_SRC_CNTRL_INDEX2 equ       %01000000
mPHY_SRC_CNTRL_INDEX3 equ       %10000000

;*** PHY_SRC_ADDRS_SUM_DATA0 - Transceiver Source Address Sum Data Register 0
PHY_SRC_ADDRS_SUM_DATA0 equ       $00000049           ;*** PHY_SRC_ADDRS_SUM_DATA0 - Transceiver Source Address Sum Data Register 0

;*** PHY_SRC_ADDRS_SUM_DATA1 - Transceiver Source Address Sum Data Register 1
PHY_SRC_ADDRS_SUM_DATA1 equ       $0000004A           ;*** PHY_SRC_ADDRS_SUM_DATA1 - Transceiver Source Address Sum Data Register 1

;*** PHY_RX_WTR_MARK - Receiver Byte Count Watermark Threshold
PHY_RX_WTR_MARK     equ       $0000004B           ;*** PHY_RX_WTR_MARK - Receiver Byte Count Watermark Threshold

;*** PHY_RX_BYTE_COUNT - Receiver Byte Count
PHY_RX_BYTE_COUNT   equ       $0000004C           ;*** PHY_RX_BYTE_COUNT - Receiver Byte Count

;*** PHY_STATUS1 - Status Register 1
PHY_STATUS1         equ       $0000004D           ;*** PHY_STATUS1 - Status Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_STATUS1_TMR1IRQ equ       0                   ; Timer Comparator 1 Interrupt flag
PHY_STATUS1_TMR2IRQ equ       1                   ; Timer Comparator 2 Interrupt flag
PHY_STATUS1_TMR3IRQ equ       2                   ; Timer Comparator 3 Interrupt flag
PHY_STATUS1_TMR4IRQ equ       3                   ; Timer Comparator 4 Interrupt flag
PHY_STATUS1_PI      equ       4                   ; Poll indication
PHY_STATUS1_SRCADDR equ       5                   ; Part of the source address feature
PHY_STATUS1_CCA     equ       6                   ; Clear Channel Assessment result flag
PHY_STATUS1_CRCVALID equ       7                   ; Code Redundancy Check Valid
; bit position masks
mPHY_STATUS1_TMR1IRQ equ       %00000001
mPHY_STATUS1_TMR2IRQ equ       %00000010
mPHY_STATUS1_TMR3IRQ equ       %00000100
mPHY_STATUS1_TMR4IRQ equ       %00001000
mPHY_STATUS1_PI     equ       %00010000
mPHY_STATUS1_SRCADDR equ       %00100000
mPHY_STATUS1_CCA    equ       %01000000
mPHY_STATUS1_CRCVALID equ       %10000000

;*** PHY_STATUS2 - Status Register 2
PHY_STATUS2         equ       $0000004E           ;*** PHY_STATUS2 - Status Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_STATUS2_SEQIRQ  equ       0                   ; Sequence flag
PHY_STATUS2_TXIRQ   equ       1                   ; Transmitter flag
PHY_STATUS2_RXIRQ   equ       2                   ; Receiver flag
PHY_STATUS2_CCAIRQ  equ       3                   ; Clear Channel Assessment flag
PHY_STATUS2_RXWTRMRKIRQ equ       4                   ; Receiver Byte Count Water Mark flag
PHY_STATUS2_FILTERFAIL_IRQ equ       5                   ; Receiver Packet Filter Fail flag
PHY_STATUS2_LO1_UNLOCK_IRQ equ       6                   ; Local Oscillator Un-lock
PHY_STATUS2_RX_FRM_PEND equ       7                   ; Status of the frame pending bit of the frame control field
; bit position masks
mPHY_STATUS2_SEQIRQ equ       %00000001
mPHY_STATUS2_TXIRQ  equ       %00000010
mPHY_STATUS2_RXIRQ  equ       %00000100
mPHY_STATUS2_CCAIRQ equ       %00001000
mPHY_STATUS2_RXWTRMRKIRQ equ       %00010000
mPHY_STATUS2_FILTERFAIL_IRQ equ       %00100000
mPHY_STATUS2_LO1_UNLOCK_IRQ equ       %01000000
mPHY_STATUS2_RX_FRM_PEND equ       %10000000

;*** PHY_CCAFNL - Clear Channel Assessment Final Value
PHY_CCAFNL          equ       $00000050           ;*** PHY_CCAFNL - Clear Channel Assessment Final Value

;*** PHY_EVENT_TMR0 - Event Timer Register 0
PHY_EVENT_TMR0      equ       $00000051           ;*** PHY_EVENT_TMR0 - Event Timer Register 0

;*** PHY_EVENT_TMR1 - Event Timer Register 1
PHY_EVENT_TMR1      equ       $00000052           ;*** PHY_EVENT_TMR1 - Event Timer Register 1

;*** PHY_EVENT_TMR2 - Event Timer Register 2
PHY_EVENT_TMR2      equ       $00000053           ;*** PHY_EVENT_TMR2 - Event Timer Register 2

;*** PHY_TIMESTAMP0 - Time Stamp Register 0
PHY_TIMESTAMP0      equ       $00000054           ;*** PHY_TIMESTAMP0 - Time Stamp Register 0

;*** PHY_TIMESTAMP1 - Time Stamp Register 1
PHY_TIMESTAMP1      equ       $00000055           ;*** PHY_TIMESTAMP1 - Time Stamp Register 1

;*** PHY_TIMESTAMP2 - Time Stamp Register 2
PHY_TIMESTAMP2      equ       $00000056           ;*** PHY_TIMESTAMP2 - Time Stamp Register 2

;*** PHY_T3CMP0 - Event Timer Comparator 3 Register 0
PHY_T3CMP0          equ       $00000057           ;*** PHY_T3CMP0 - Event Timer Comparator 3 Register 0

;*** PHY_T3CMP1 - Event Timer Comparator 3 Register 1
PHY_T3CMP1          equ       $00000058           ;*** PHY_T3CMP1 - Event Timer Comparator 3 Register 1

;*** PHY_T3CMP2 - Event Timer Comparator 3 Register 2
PHY_T3CMP2          equ       $00000059           ;*** PHY_T3CMP2 - Event Timer Comparator 3 Register 2

;*** PHY_TC2_PRIME0 - Time Comparator 2 Prime Register 0
PHY_TC2_PRIME0      equ       $0000005A           ;*** PHY_TC2_PRIME0 - Time Comparator 2 Prime Register 0

;*** PHY_TC2_PRIME1 - Time Comparator 2 Prime Register 1
PHY_TC2_PRIME1      equ       $0000005B           ;*** PHY_TC2_PRIME1 - Time Comparator 2 Prime Register 1

;*** PHY_MACSHORTADDRS0 - MAC Short Address Register 0
PHY_MACSHORTADDRS0  equ       $0000005C           ;*** PHY_MACSHORTADDRS0 - MAC Short Address Register 0

;*** PHY_MACSHORTADDRS1 - MAC Short Address Register 1
PHY_MACSHORTADDRS1  equ       $0000005D           ;*** PHY_MACSHORTADDRS1 - MAC Short Address Register 1

;*** PHY_MACPANID0 - MAC Pan ID Register 0
PHY_MACPANID0       equ       $0000005E           ;*** PHY_MACPANID0 - MAC Pan ID Register 0

;*** PHY_MACPANID1 - MAC Pan ID Register 1
PHY_MACPANID1       equ       $0000005F           ;*** PHY_MACPANID1 - MAC Pan ID Register 1

;*** CMTCG1 - Carrier Generator Data Register 1
CMTCG1              equ       $00000060           ;*** CMTCG1 - Carrier Generator Data Register 1

;*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte
CMTCGH1             equ       $00000060           ;*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte

;*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte
CMTCGL1             equ       $00000061           ;*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte

;*** CMTCG2 - Carrier Generator Data Register 2
CMTCG2              equ       $00000062           ;*** CMTCG2 - Carrier Generator Data Register 2

;*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte
CMTCGH2             equ       $00000062           ;*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte

;*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte
CMTCGL2             equ       $00000063           ;*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte

;*** CMTOC - CMT Output Control Register
CMTOC               equ       $00000064           ;*** CMTOC - CMT Output Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
CMTOC_CMTDIV2       equ       4                   ; CMT Clock Divide Prescaler Bit 2
CMTOC_IROPEN        equ       5                   ; IRO pin enable
CMTOC_CMTPOL        equ       6                   ; CMT output polarity
CMTOC_IROL          equ       7                   ; IRO latch control
; bit position masks
mCMTOC_CMTDIV2      equ       %00010000
mCMTOC_IROPEN       equ       %00100000
mCMTOC_CMTPOL       equ       %01000000
mCMTOC_IROL         equ       %10000000

;*** CMTMSC - CMT Modulator Status and Control Register
CMTMSC              equ       $00000065           ;*** CMTMSC - CMT Modulator Status and Control Register
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
CMTCMD12            equ       $00000066           ;*** CMTCMD12 - CMT Modulator Data Register 12

;*** CMTCMD1 - CMT Modulator Data Register 1
CMTCMD1             equ       $00000066           ;*** CMTCMD1 - CMT Modulator Data Register 1

;*** CMTCMD2 - CMT Modulator Data Register 2
CMTCMD2             equ       $00000067           ;*** CMTCMD2 - CMT Modulator Data Register 2
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
CMTCMD34            equ       $00000068           ;*** CMTCMD34 - CMT Modulator Data Register 34

;*** CMTCMD3 - CMT Modulator Data Register 3
CMTCMD3             equ       $00000068           ;*** CMTCMD3 - CMT Modulator Data Register 3

;*** CMTCMD4 - CMT Modulator Data Register 4
CMTCMD4             equ       $00000069           ;*** CMTCMD4 - CMT Modulator Data Register 4
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

;*** IIC1A - IIC Address Register
IIC1A               equ       $0000006A           ;*** IIC1A - IIC Address Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1A_AD1           equ       1                   ; Slave Address Bit 1
IIC1A_AD2           equ       2                   ; Slave Address Bit 2
IIC1A_AD3           equ       3                   ; Slave Address Bit 3
IIC1A_AD4           equ       4                   ; Slave Address Bit 4
IIC1A_AD5           equ       5                   ; Slave Address Bit 5
IIC1A_AD6           equ       6                   ; Slave Address Bit 6
IIC1A_AD7           equ       7                   ; Slave Address Bit 7
; bit position masks
mIIC1A_AD1          equ       %00000010
mIIC1A_AD2          equ       %00000100
mIIC1A_AD3          equ       %00001000
mIIC1A_AD4          equ       %00010000
mIIC1A_AD5          equ       %00100000
mIIC1A_AD6          equ       %01000000
mIIC1A_AD7          equ       %10000000

;*** IIC1F - IIC Frequency Divider Register
IIC1F               equ       $0000006B           ;*** IIC1F - IIC Frequency Divider Register
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

;*** IIC1C1 - IIC Control Register 1
IIC1C1              equ       $0000006C           ;*** IIC1C1 - IIC Control Register 1
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C1_RSTA         equ       2                   ; Repeat START
IIC1C1_TXAK         equ       3                   ; Transmit Acknowledge Enable
IIC1C1_TX           equ       4                   ; Transmit Mode Select
IIC1C1_MST          equ       5                   ; Master Mode Select
IIC1C1_IICIE        equ       6                   ; IIC Interrupt Enable
IIC1C1_IICEN        equ       7                   ; IIC Enable
; bit position masks
mIIC1C1_RSTA        equ       %00000100
mIIC1C1_TXAK        equ       %00001000
mIIC1C1_TX          equ       %00010000
mIIC1C1_MST         equ       %00100000
mIIC1C1_IICIE       equ       %01000000
mIIC1C1_IICEN       equ       %10000000

;*** IIC1C - IIC Control Register
IIC1C               equ       $0000006C           ;*** IIC1C - IIC Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C_RSTA          equ       2                   ; Repeat START
IIC1C_TXAK          equ       3                   ; Transmit Acknowledge Enable
IIC1C_TX            equ       4                   ; Transmit Mode Select
IIC1C_MST           equ       5                   ; Master Mode Select
IIC1C_IICIE         equ       6                   ; IIC Interrupt Enable
IIC1C_IICEN         equ       7                   ; IIC Enable
; bit position masks
mIIC1C_RSTA         equ       %00000100
mIIC1C_TXAK         equ       %00001000
mIIC1C_TX           equ       %00010000
mIIC1C_MST          equ       %00100000
mIIC1C_IICIE        equ       %01000000
mIIC1C_IICEN        equ       %10000000

;*** IIC1S - IIC Status Register
IIC1S               equ       $0000006D           ;*** IIC1S - IIC Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1S_RXAK          equ       0                   ; Receive Acknowledge
IIC1S_IICIF         equ       1                   ; IIC Interrupt Flag
IIC1S_SRW           equ       2                   ; Slave Read/Write
IIC1S_ARBL          equ       4                   ; Arbitration Lost
IIC1S_BUSY          equ       5                   ; Bus Busy
IIC1S_IAAS          equ       6                   ; Addressed as a Slave
IIC1S_TCF           equ       7                   ; Transfer Complete Flag
; bit position masks
mIIC1S_RXAK         equ       %00000001
mIIC1S_IICIF        equ       %00000010
mIIC1S_SRW          equ       %00000100
mIIC1S_ARBL         equ       %00010000
mIIC1S_BUSY         equ       %00100000
mIIC1S_IAAS         equ       %01000000
mIIC1S_TCF          equ       %10000000

;*** IIC1D - IIC Data I/O Register
IIC1D               equ       $0000006E           ;*** IIC1D - IIC Data I/O Register
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

;*** IIC1C2 - IIC Control Register 2
IIC1C2              equ       $0000006F           ;*** IIC1C2 - IIC Control Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IIC1C2_AD8          equ       0                   ; Slave Address Bit 8
IIC1C2_AD9          equ       1                   ; Slave Address Bit 9
IIC1C2_AD10         equ       2                   ; Slave Address Bit 10
IIC1C2_ADEXT        equ       6                   ; Address Extension
IIC1C2_GCAEN        equ       7                   ; General Call Address Enable
; bit position masks
mIIC1C2_AD8         equ       %00000001
mIIC1C2_AD9         equ       %00000010
mIIC1C2_AD10        equ       %00000100
mIIC1C2_ADEXT       equ       %01000000
mIIC1C2_GCAEN       equ       %10000000

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
; bit position masks
mSPI1C2_SPC0        equ       %00000001
mSPI1C2_SPISWAI     equ       %00000010
mSPI1C2_BIDIROE     equ       %00001000
mSPI1C2_MODFEN      equ       %00010000

;*** SPI1BR - SPI1 Baud Rate Register
SPI1BR              equ       $00000072           ;*** SPI1BR - SPI1 Baud Rate Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1BR_SPR0         equ       0                   ; SPI Baud Rate Divisor Bit 0
SPI1BR_SPR1         equ       1                   ; SPI Baud Rate Divisor Bit 1
SPI1BR_SPR2         equ       2                   ; SPI Baud Rate Divisor Bit 2
SPI1BR_SPPR0        equ       4                   ; SPI Baud Rate Prescale Divisor Bit 0
SPI1BR_SPPR1        equ       5                   ; SPI Baud Rate Prescale Divisor Bit 1
SPI1BR_SPPR2        equ       6                   ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPI1BR_SPR0        equ       %00000001
mSPI1BR_SPR1        equ       %00000010
mSPI1BR_SPR2        equ       %00000100
mSPI1BR_SPPR0       equ       %00010000
mSPI1BR_SPPR1       equ       %00100000
mSPI1BR_SPPR2       equ       %01000000

;*** SPI1S - SPI1 Status Register
SPI1S               equ       $00000073           ;*** SPI1S - SPI1 Status Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPI1S_MODF          equ       4                   ; Master Mode Fault Flag
SPI1S_SPTEF         equ       5                   ; SPI Transmit Buffer Empty Flag
SPI1S_SPRF          equ       7                   ; SPI Read Buffer Full Flag
; bit position masks
mSPI1S_MODF         equ       %00010000
mSPI1S_SPTEF        equ       %00100000
mSPI1S_SPRF         equ       %10000000

;*** SPI1D - SPI1 Data Register
SPI1D               equ       $00000075           ;*** SPI1D - SPI1 Data Register

;*** IRQSC - Interrupt request status and control register
IRQSC               equ       $00000076           ;*** IRQSC - Interrupt request status and control register
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

;*** PPAGE - Program Page Register
PPAGE               equ       $00000078           ;*** PPAGE - Program Page Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPAGE_XA14          equ       0                   ; Extended address, bit 14
PPAGE_XA15          equ       1                   ; Extended address, bit 15
PPAGE_XA16          equ       2                   ; Extended address, bit 16
; bit position masks
mPPAGE_XA14         equ       %00000001
mPPAGE_XA15         equ       %00000010
mPPAGE_XA16         equ       %00000100

;*** LAP2 - Linear Address Pointer Register 2
LAP2                equ       $00000079           ;*** LAP2 - Linear Address Pointer Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP2_LA16           equ       0                   ; Linear address pointer, bit 16
; bit position masks
mLAP2_LA16          equ       %00000001

;*** LAP1 - Linear Address Pointer Register 1
LAP1                equ       $0000007A           ;*** LAP1 - Linear Address Pointer Register 1
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
LAP0                equ       $0000007B           ;*** LAP0 - Linear Address Pointer Register 0
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
LWP                 equ       $0000007C           ;*** LWP - Linear Word Post Increment Register
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
LBP                 equ       $0000007D           ;*** LBP - Linear Byte Post Increment Register
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
LB                  equ       $0000007E           ;*** LB - Linear Byte Register
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
LAPAB               equ       $0000007F           ;*** LAPAB - Linear Address Pointer Add Byte Register
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
SOPT1_BKGDPE        equ       1                   ; Background Debug Mode Pin Enable
SOPT1_STOPE         equ       5                   ; Stop Mode Enable
SOPT1_COPT          equ       6                   ; COP Watchdog Timeout
SOPT1_COPE          equ       7                   ; COP Watchdog Enable
; bit position masks
mSOPT1_BKGDPE       equ       %00000010
mSOPT1_STOPE        equ       %00100000
mSOPT1_COPT         equ       %01000000
mSOPT1_COPE         equ       %10000000

;*** SOPT2 - System Options Register 2
SOPT2               equ       $00001803           ;*** SOPT2 - System Options Register 2
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_PID0          equ       0                   ; Product ID, bit 0
SOPT2_PID1          equ       1                   ; Product ID, bit 1
SOPT2_COPCLKS       equ       7                   ; COP Watchdog Clock Select
; bit position masks
mSOPT2_PID0         equ       %00000001
mSOPT2_PID1         equ       %00000010
mSOPT2_COPCLKS      equ       %10000000

;*** SCI1C4 - SCI1 Control Register 4
SCI1C4              equ       $00001804           ;*** SCI1C4 - SCI1 Control Register 4
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C4_BRFA0        equ       0                   ; Baud rate fine adjust, bit 0
SCI1C4_BRFA1        equ       1                   ; Baud rate fine adjust, bit 1
SCI1C4_BRFA2        equ       2                   ; Baud rate fine adjust, bit 2
SCI1C4_BRFA3        equ       3                   ; Baud rate fine adjust, bit 3
SCI1C4_BRFA4        equ       4                   ; Baud rate fine adjust, bit 4
; bit position masks
mSCI1C4_BRFA0       equ       %00000001
mSCI1C4_BRFA1       equ       %00000010
mSCI1C4_BRFA2       equ       %00000100
mSCI1C4_BRFA3       equ       %00001000
mSCI1C4_BRFA4       equ       %00010000

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
SPMSC1              equ       $00001808           ;*** SPMSC1 - System Power Management Status and Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_LVDE         equ       2                   ; Low-Voltage Detect Enable
SPMSC1_LVDSE        equ       3                   ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE        equ       4                   ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE        equ       5                   ; Low-Voltage Detect Interrupt Enable
SPMSC1_LVDACK       equ       6                   ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF         equ       7                   ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_LVDE        equ       %00000100
mSPMSC1_LVDSE       equ       %00001000
mSPMSC1_LVDRE       equ       %00010000
mSPMSC1_LVDIE       equ       %00100000
mSPMSC1_LVDACK      equ       %01000000
mSPMSC1_LVDF        equ       %10000000

;*** SPMSC2 - System Power Management Status and Control 2 Register
SPMSC2              equ       $00001809           ;*** SPMSC2 - System Power Management Status and Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC         equ       0                   ; Partial Power Down Control
SPMSC2_PPDE         equ       1                   ; Partial Power Down Enable
SPMSC2_LPWUI        equ       5                   ; Low Power Wake Up on Interrupt
SPMSC2_LPRS         equ       6                   ; Low Power Regulator Status
SPMSC2_LPR          equ       7                   ; Low Power Regulator Control
; bit position masks
mSPMSC2_PPDC        equ       %00000001
mSPMSC2_PPDE        equ       %00000010
mSPMSC2_LPWUI       equ       %00100000
mSPMSC2_LPRS        equ       %01000000
mSPMSC2_LPR         equ       %10000000

;*** SPMSC3 - System Power Management Status and Control 3 Register
SPMSC3              equ       $0000180B           ;*** SPMSC3 - System Power Management Status and Control 3 Register
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

;*** SOMC1 -
SOMC1               equ       $0000180C           ;*** SOMC1 -
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOMC1_XTAL0_TST_OUT equ       0                   ; Crystal 0 Test Out (32kHz) Enable
SOMC1_XTAL1STEN     equ       2                   ; Crystal 1 Oscillator (32MHz) STOP3 Mode Enable
SOMC1_XTAL0STEN     equ       3                   ; Crystal 0 Oscillator (32.768KHz) STOP3 Mode Enable
SOMC1_XTAL0EN       equ       4                   ; Crystal 0 Oscillator (32.768KHz) Enable
SOMC1_RDIV0         equ       5                   ; Reference Divider, bit 0
SOMC1_RDIV1         equ       6                   ; Reference Divider, bit 1
SOMC1_RDIV2         equ       7                   ; Reference Divider, bit 2
; bit position masks
mSOMC1_XTAL0_TST_OUT equ       %00000001
mSOMC1_XTAL1STEN    equ       %00000100
mSOMC1_XTAL0STEN    equ       %00001000
mSOMC1_XTAL0EN      equ       %00010000
mSOMC1_RDIV0        equ       %00100000
mSOMC1_RDIV1        equ       %01000000
mSOMC1_RDIV2        equ       %10000000

;*** SOMC2 -
SOMC2               equ       $0000180D           ;*** SOMC2 -
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOMC2_XTAL1_TRIM0   equ       0                   ; XTAL1_TRIM, bit 0
SOMC2_XTAL1_TRIM1   equ       1                   ; XTAL1_TRIM, bit 1
SOMC2_XTAL1_TRIM2   equ       2                   ; XTAL1_TRIM, bit 2
SOMC2_XTAL1_TRIM3   equ       3                   ; XTAL1_TRIM, bit 3
SOMC2_XTAL1_TRIM4   equ       4                   ; XTAL1_TRIM, bit 4
SOMC2_XTAL1_TRIM5   equ       5                   ; XTAL1_TRIM, bit 5
SOMC2_XTAL1_TRIM6   equ       6                   ; XTAL1_TRIM, bit 6
SOMC2_XTAL1_TRIM7   equ       7                   ; XTAL1_TRIM, bit 7
; bit position masks
mSOMC2_XTAL1_TRIM0  equ       %00000001
mSOMC2_XTAL1_TRIM1  equ       %00000010
mSOMC2_XTAL1_TRIM2  equ       %00000100
mSOMC2_XTAL1_TRIM3  equ       %00001000
mSOMC2_XTAL1_TRIM4  equ       %00010000
mSOMC2_XTAL1_TRIM5  equ       %00100000
mSOMC2_XTAL1_TRIM6  equ       %01000000
mSOMC2_XTAL1_TRIM7  equ       %10000000

;*** SCGC1 - System Clock Gating Control 1 Register
SCGC1               equ       $0000180E           ;*** SCGC1 - System Clock Gating Control 1 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI           equ       0                   ; SCI Clock Gate Control
SCGC1_IIC           equ       1                   ; IIC Clock Gate Control
SCGC1_CMT           equ       2                   ; CMT Clock Gate Control
SCGC1_TPM1          equ       3                   ; TPM1 Clock Gate Control
SCGC1_TPM2          equ       4                   ; TPM2 Clock Gate Control
SCGC1_TPM3          equ       5                   ; TPM3 Clock Gate Control
SCGC1_TPM4          equ       6                   ; TPM4 Clock Gate Control
; bit position masks
mSCGC1_SCI          equ       %00000001
mSCGC1_IIC          equ       %00000010
mSCGC1_CMT          equ       %00000100
mSCGC1_TPM1         equ       %00001000
mSCGC1_TPM2         equ       %00010000
mSCGC1_TPM3         equ       %00100000
mSCGC1_TPM4         equ       %01000000

;*** SCGC2 - System Clock Gating Control 2 Register
SCGC2               equ       $0000180F           ;*** SCGC2 - System Clock Gating Control 2 Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI           equ       0                   ; SPI Clock Gate Control
SCGC2_RTC           equ       1                   ; RTC Clock Gate Control
SCGC2_KBI2          equ       2                   ; KBI2 Clock Gate Control
SCGC2_KBI1          equ       3                   ; KBI1 Clock Gate Control
SCGC2_IRQ           equ       4                   ; IRQ Clock Gate Control
SCGC2_FLS           equ       5                   ; FLS Clock Gate Control
SCGC2_DBG           equ       6                   ; DBG Clock Gate Control
; bit position masks
mSCGC2_SPI          equ       %00000001
mSCGC2_RTC          equ       %00000010
mSCGC2_KBI2         equ       %00000100
mSCGC2_KBI1         equ       %00001000
mSCGC2_IRQ          equ       %00010000
mSCGC2_FLS          equ       %00100000
mSCGC2_DBG          equ       %01000000

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

;*** DBGCC - Debug Comparator C Register
DBGCC               equ       $00001814           ;*** DBGCC - Debug Comparator C Register

;*** DBGCCH - Debug Comparator C High Register
DBGCCH              equ       $00001814           ;*** DBGCCH - Debug Comparator C High Register
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
DBGCCL              equ       $00001815           ;*** DBGCCL - Debug Comparator C Low Register
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
DBGF                equ       $00001816           ;*** DBGF - Debug FIFO Register

;*** DBGFH - Debug FIFO High Register
DBGFH               equ       $00001816           ;*** DBGFH - Debug FIFO High Register
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
DBGFL               equ       $00001817           ;*** DBGFL - Debug FIFO Low Register
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
DBGCAX              equ       $00001818           ;*** DBGCAX - Debug Comparator A Extension Register
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
DBGCBX              equ       $00001819           ;*** DBGCBX - Debug Comparator B Extension Register
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
DBGCCX              equ       $0000181A           ;*** DBGCCX - Debug Comparator C Extension Register
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
DBGFX               equ       $0000181B           ;*** DBGFX - Debug FIFO Extended Information Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFX_Bit16         equ       0                   ; Extended Address Bit 16
DBGFX_PPACC         equ       7                   ; PPAGE Access Indicator Bit
; bit position masks
mDBGFX_Bit16        equ       %00000001
mDBGFX_PPACC        equ       %10000000

;*** DBGC - Debug Control Register
DBGC                equ       $0000181C           ;*** DBGC - Debug Control Register
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
DBGT                equ       $0000181D           ;*** DBGT - Debug Trigger Register
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
DBGS                equ       $0000181E           ;*** DBGS - Debug Status Register
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
DBGCNT              equ       $0000181F           ;*** DBGCNT - Debug Count Status Register
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

;*** RTCSC - RTC Status and Control Register
RTCSC               equ       $00001828           ;*** RTCSC - RTC Status and Control Register
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

;*** RTCCNTL - RTC Counter Register Low
RTCCNTL             equ       $00001829           ;*** RTCCNTL - RTC Counter Register Low

;*** RTCMODL - RTC Modulo Register Low
RTCMODL             equ       $0000182A           ;*** RTCMODL - RTC Modulo Register Low

;*** RTCCNTH - RTC Counter Register High
RTCCNTH             equ       $0000182B           ;*** RTCCNTH - RTC Counter Register High

;*** RTCMODH - RTC Modulo Register High
RTCMODH             equ       $0000182C           ;*** RTCMODH - RTC Modulo Register High

;*** PTAPE - Port A Pull Enable Register
PTAPE               equ       $00001830           ;*** PTAPE - Port A Pull Enable Register
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
PTASE               equ       $00001831           ;*** PTASE - Port A Slew Rate Enable Register
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
PTADS               equ       $00001832           ;*** PTADS - Port A Drive Strength Selection Register
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
PTBPE               equ       $00001834           ;*** PTBPE - Port B Pull Enable Register
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
PTBSE               equ       $00001835           ;*** PTBSE - Port B Slew Rate Enable Register
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
PTBDS               equ       $00001836           ;*** PTBDS - Port B Drive Strength Selection Register
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

;*** PTCPE - Port C Pull Enable Register
PTCPE               equ       $00001838           ;*** PTCPE - Port C Pull Enable Register
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
PTCSE               equ       $00001839           ;*** PTCSE - Port C Slew Rate Enable Register
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
PTCDS               equ       $0000183A           ;*** PTCDS - Port C Drive Strength Selection Register
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

;*** PTDPE - Port D Pull Enable Register
PTDPE               equ       $0000183C           ;*** PTDPE - Port D Pull Enable Register
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
PTDSE               equ       $0000183D           ;*** PTDSE - Port D Slew Rate Enable Register
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
PTDDS               equ       $0000183E           ;*** PTDDS - Port D Drive Strength Selection Register
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

;*** PHY_T1CMP0 - Event Timer Comparator 1 Register 0
PHY_T1CMP0          equ       $00001840           ;*** PHY_T1CMP0 - Event Timer Comparator 1 Register 0

;*** PHY_T1CMP1 - Event Timer Comparator 1 Register 1
PHY_T1CMP1          equ       $00001841           ;*** PHY_T1CMP1 - Event Timer Comparator 1 Register 1

;*** PHY_T1CMP2 - Event Timer Comparator 1 Register 2
PHY_T1CMP2          equ       $00001842           ;*** PHY_T1CMP2 - Event Timer Comparator 1 Register 2

;*** PHY_T2CMP0 - Event Timer Comparator 2 Register 0
PHY_T2CMP0          equ       $00001843           ;*** PHY_T2CMP0 - Event Timer Comparator 2 Register 0

;*** PHY_T2CMP1 - Event Timer Comparator 2 Register 1
PHY_T2CMP1          equ       $00001844           ;*** PHY_T2CMP1 - Event Timer Comparator 2 Register 1

;*** PHY_T2CMP2 - Event Timer Comparator 2 Register 2
PHY_T2CMP2          equ       $00001845           ;*** PHY_T2CMP2 - Event Timer Comparator 2 Register 2

;*** PHY_T4CMP0 - Event Timer Comparator 4 Register 0
PHY_T4CMP0          equ       $00001846           ;*** PHY_T4CMP0 - Event Timer Comparator 4 Register 0

;*** PHY_T4CMP1 - Event Timer Comparator 4 Register 1
PHY_T4CMP1          equ       $00001847           ;*** PHY_T4CMP1 - Event Timer Comparator 4 Register 1

;*** PHY_T4CMP2 - Event Timer Comparator 4 Register 2
PHY_T4CMP2          equ       $00001848           ;*** PHY_T4CMP2 - Event Timer Comparator 4 Register 2

;*** PHY_LO1_FRAC0 - LO1 FracN Numerator Value Register 0
PHY_LO1_FRAC0       equ       $00001849           ;*** PHY_LO1_FRAC0 - LO1 FracN Numerator Value Register 0

;*** PHY_LO1_FRAC1 - LO1 FracN Numerator Value Register 1
PHY_LO1_FRAC1       equ       $0000184A           ;*** PHY_LO1_FRAC1 - LO1 FracN Numerator Value Register 1

;*** PHY_LO1_INT - LO1 Integer Register
PHY_LO1_INT         equ       $0000184B           ;*** PHY_LO1_INT - LO1 Integer Register

;*** PHY_PA_PWR_CNTL - Power Amplifier (PA) Power Control Register
PHY_PA_PWR_CNTL     equ       $0000184C           ;*** PHY_PA_PWR_CNTL - Power Amplifier (PA) Power Control Register

;*** PHY_MACLONGADDRS0 - MAC Long Address Register 0
PHY_MACLONGADDRS0   equ       $0000184D           ;*** PHY_MACLONGADDRS0 - MAC Long Address Register 0

;*** PHY_MACLONGADDRS1 - MAC Long Address Register 1
PHY_MACLONGADDRS1   equ       $0000184E           ;*** PHY_MACLONGADDRS1 - MAC Long Address Register 1

;*** PHY_MACLONGADDRS2 - MAC Long Address Register 2
PHY_MACLONGADDRS2   equ       $0000184F           ;*** PHY_MACLONGADDRS2 - MAC Long Address Register 2

;*** PHY_MACLONGADDRS3 - MAC Long Address Register 3
PHY_MACLONGADDRS3   equ       $00001850           ;*** PHY_MACLONGADDRS3 - MAC Long Address Register 3

;*** PHY_MACLONGADDRS4 - MAC Long Address Register 4
PHY_MACLONGADDRS4   equ       $00001851           ;*** PHY_MACLONGADDRS4 - MAC Long Address Register 4

;*** PHY_MACLONGADDRS5 - MAC Long Address Register 5
PHY_MACLONGADDRS5   equ       $00001852           ;*** PHY_MACLONGADDRS5 - MAC Long Address Register 5

;*** PHY_MACLONGADDRS6 - MAC Long Address Register 6
PHY_MACLONGADDRS6   equ       $00001853           ;*** PHY_MACLONGADDRS6 - MAC Long Address Register 6

;*** PHY_MACLONGADDRS7 - MAC Long Address Register 7
PHY_MACLONGADDRS7   equ       $00001854           ;*** PHY_MACLONGADDRS7 - MAC Long Address Register 7

;*** PHY_MAXFRAMELENGTH - Max Frame Length Register
PHY_MAXFRAMELENGTH  equ       $00001855           ;*** PHY_MAXFRAMELENGTH - Max Frame Length Register

;*** PHY_RX_FRAME_FILTER - Receive Frame Filter
PHY_RX_FRAME_FILTER equ       $00001856           ;*** PHY_RX_FRAME_FILTER - Receive Frame Filter
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_RX_FRAME_FILTER_BEACON_FT equ       0                   ; BEACON_FT
PHY_RX_FRAME_FILTER_DATA_FT equ       1                   ; DATA_FT
PHY_RX_FRAME_FILTER_ACK_FT equ       2                   ; ACK_FT
PHY_RX_FRAME_FILTER_CMD_FT equ       3                   ; CMD_FT
PHY_RX_FRAME_FILTER_NS_FT equ       4                   ; NOT_SPECIFIED_FT
; bit position masks
mPHY_RX_FRAME_FILTER_BEACON_FT equ       %00000001
mPHY_RX_FRAME_FILTER_DATA_FT equ       %00000010
mPHY_RX_FRAME_FILTER_ACK_FT equ       %00000100
mPHY_RX_FRAME_FILTER_CMD_FT equ       %00001000
mPHY_RX_FRAME_FILTER_NS_FT equ       %00010000

;*** PHY_MACFRAMEVER -
PHY_MACFRAMEVER     equ       $00001857           ;*** PHY_MACFRAMEVER -
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_MACFRAMEVER_FRM_VER0 equ       0                   ; Frame Version Selection, bit 0, bit 0
PHY_MACFRAMEVER_FRM_VER1 equ       1                   ; Frame Version Selection, bit 0, bit 1
PHY_MACFRAMEVER_TMR_PRESCALE0 equ       5                   ; Timer Prescaler Select, bit 0, bit 0
PHY_MACFRAMEVER_TMR_PRESCALE1 equ       6                   ; Timer Prescaler Select, bit 0, bit 1
PHY_MACFRAMEVER_TMR_PRESCALE2 equ       7                   ; Timer Prescaler Select, bit 0, bit 2
; bit position masks
mPHY_MACFRAMEVER_FRM_VER0 equ       %00000001
mPHY_MACFRAMEVER_FRM_VER1 equ       %00000010
mPHY_MACFRAMEVER_TMR_PRESCALE0 equ       %00100000
mPHY_MACFRAMEVER_TMR_PRESCALE1 equ       %01000000
mPHY_MACFRAMEVER_TMR_PRESCALE2 equ       %10000000

;*** PHY_CCA_THRESHOLD - CCA Energy Threshold
PHY_CCA_THRESHOLD   equ       $00001858           ;*** PHY_CCA_THRESHOLD - CCA Energy Threshold

;*** PHY_CCA_OFFSET_CMP - CCA Power Compensation
PHY_CCA_OFFSET_CMP  equ       $00001859           ;*** PHY_CCA_OFFSET_CMP - CCA Power Compensation

;*** PHY_FSM - Finite State Machine Register
PHY_FSM             equ       $0000185A           ;*** PHY_FSM - Finite State Machine Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PHY_FSM_FSM         equ       0
; bit position masks
mPHY_FSM_FSM        equ       %00111111

;*** PHY_INDIRECT_ACCESS_INDEX - Transceiver Indirect Access Index Register
PHY_INDIRECT_ACCESS_INDEX equ       $0000185B           ;*** PHY_INDIRECT_ACCESS_INDEX - Transceiver Indirect Access Index Register

;*** PHY_INDIRECT_ACCESS_DATA - Transceiver Indirect Access Data Register
PHY_INDIRECT_ACCESS_DATA equ       $0000185C           ;*** PHY_INDIRECT_ACCESS_DATA - Transceiver Indirect Access Data Register

;*** TPM4SC - TPM4 Status and Control Register
TPM4SC              equ       $00001860           ;*** TPM4SC - TPM4 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM4SC_PS0          equ       0                   ; Prescale Divisor Select Bit 0
TPM4SC_PS1          equ       1                   ; Prescale Divisor Select Bit 1
TPM4SC_PS2          equ       2                   ; Prescale Divisor Select Bit 2
TPM4SC_CLKSA        equ       3                   ; Clock Source Select A
TPM4SC_CLKSB        equ       4                   ; Clock Source Select B
TPM4SC_CPWMS        equ       5                   ; Center-Aligned PWM Select
TPM4SC_TOIE         equ       6                   ; Timer Overflow Interrupt Enable
TPM4SC_TOF          equ       7                   ; Timer Overflow Flag
; bit position masks
mTPM4SC_PS0         equ       %00000001
mTPM4SC_PS1         equ       %00000010
mTPM4SC_PS2         equ       %00000100
mTPM4SC_CLKSA       equ       %00001000
mTPM4SC_CLKSB       equ       %00010000
mTPM4SC_CPWMS       equ       %00100000
mTPM4SC_TOIE        equ       %01000000
mTPM4SC_TOF         equ       %10000000

;*** TPM4CNT - TPM4 Timer Counter Register
TPM4CNT             equ       $00001861           ;*** TPM4CNT - TPM4 Timer Counter Register

;*** TPM4CNTH - TPM4 Timer Counter Register High
TPM4CNTH            equ       $00001861           ;*** TPM4CNTH - TPM4 Timer Counter Register High

;*** TPM4CNTL - TPM4 Timer Counter Register Low
TPM4CNTL            equ       $00001862           ;*** TPM4CNTL - TPM4 Timer Counter Register Low

;*** TPM4MOD - TPM4 Timer Counter Modulo Register
TPM4MOD             equ       $00001863           ;*** TPM4MOD - TPM4 Timer Counter Modulo Register

;*** TPM4MODH - TPM4 Timer Counter Modulo Register High
TPM4MODH            equ       $00001863           ;*** TPM4MODH - TPM4 Timer Counter Modulo Register High

;*** TPM4MODL - TPM4 Timer Counter Modulo Register Low
TPM4MODL            equ       $00001864           ;*** TPM4MODL - TPM4 Timer Counter Modulo Register Low

;*** TPM4C0SC - TPM4 Timer Channel 0 Status and Control Register
TPM4C0SC            equ       $00001865           ;*** TPM4C0SC - TPM4 Timer Channel 0 Status and Control Register
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM4C0SC_ELS0A      equ       2                   ; Edge/Level Select Bit A
TPM4C0SC_ELS0B      equ       3                   ; Edge/Level Select Bit B
TPM4C0SC_MS0A       equ       4                   ; Mode Select A for TPM Channel 0
TPM4C0SC_MS0B       equ       5                   ; Mode Select B for TPM Channel 0
TPM4C0SC_CH0IE      equ       6                   ; Channel 0 Interrupt Enable
TPM4C0SC_CH0F       equ       7                   ; Channel 0 Flag
; bit position masks
mTPM4C0SC_ELS0A     equ       %00000100
mTPM4C0SC_ELS0B     equ       %00001000
mTPM4C0SC_MS0A      equ       %00010000
mTPM4C0SC_MS0B      equ       %00100000
mTPM4C0SC_CH0IE     equ       %01000000
mTPM4C0SC_CH0F      equ       %10000000

;*** TPM4C0V - TPM4 Timer Channel 0 Value Register
TPM4C0V             equ       $00001866           ;*** TPM4C0V - TPM4 Timer Channel 0 Value Register

;*** TPM4C0VH - TPM4 Timer Channel 0 Value Register High
TPM4C0VH            equ       $00001866           ;*** TPM4C0VH - TPM4 Timer Channel 0 Value Register High

;*** TPM4C0VL - TPM4 Timer Channel 0 Value Register Low
TPM4C0VL            equ       $00001867           ;*** TPM4C0VL - TPM4 Timer Channel 0 Value Register Low

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

SCIBD               equ       SCI1BD
SCIBDH              equ       SCI1BDH
SCIBDH_SBR8         equ       SCI1BDH_SBR8
SCIBDH_SBR9         equ       SCI1BDH_SBR9
SCIBDH_SBR10        equ       SCI1BDH_SBR10
SCIBDH_SBR11        equ       SCI1BDH_SBR11
SCIBDH_SBR12        equ       SCI1BDH_SBR12
SCIBDH_RXEDGIE      equ       SCI1BDH_RXEDGIE
SCIBDH_LBKDIE       equ       SCI1BDH_LBKDIE
mSCIBDH_SBR8        equ       mSCI1BDH_SBR8
mSCIBDH_SBR9        equ       mSCI1BDH_SBR9
mSCIBDH_SBR10       equ       mSCI1BDH_SBR10
mSCIBDH_SBR11       equ       mSCI1BDH_SBR11
mSCIBDH_SBR12       equ       mSCI1BDH_SBR12
mSCIBDH_RXEDGIE     equ       mSCI1BDH_RXEDGIE
mSCIBDH_LBKDIE      equ       mSCI1BDH_LBKDIE
SCIBDL              equ       SCI1BDL
SCIBDL_SBR0         equ       SCI1BDL_SBR0
SCIBDL_SBR1         equ       SCI1BDL_SBR1
SCIBDL_SBR2         equ       SCI1BDL_SBR2
SCIBDL_SBR3         equ       SCI1BDL_SBR3
SCIBDL_SBR4         equ       SCI1BDL_SBR4
SCIBDL_SBR5         equ       SCI1BDL_SBR5
SCIBDL_SBR6         equ       SCI1BDL_SBR6
SCIBDL_SBR7         equ       SCI1BDL_SBR7
mSCIBDL_SBR0        equ       mSCI1BDL_SBR0
mSCIBDL_SBR1        equ       mSCI1BDL_SBR1
mSCIBDL_SBR2        equ       mSCI1BDL_SBR2
mSCIBDL_SBR3        equ       mSCI1BDL_SBR3
mSCIBDL_SBR4        equ       mSCI1BDL_SBR4
mSCIBDL_SBR5        equ       mSCI1BDL_SBR5
mSCIBDL_SBR6        equ       mSCI1BDL_SBR6
mSCIBDL_SBR7        equ       mSCI1BDL_SBR7
SCIC1               equ       SCI1C1
SCIC1_PT            equ       SCI1C1_PT
SCIC1_PE            equ       SCI1C1_PE
SCIC1_ILT           equ       SCI1C1_ILT
SCIC1_WAKE          equ       SCI1C1_WAKE
SCIC1_M             equ       SCI1C1_M
SCIC1_RSRC          equ       SCI1C1_RSRC
SCIC1_SCISWAI       equ       SCI1C1_SCISWAI
SCIC1_LOOPS         equ       SCI1C1_LOOPS
mSCIC1_PT           equ       mSCI1C1_PT
mSCIC1_PE           equ       mSCI1C1_PE
mSCIC1_ILT          equ       mSCI1C1_ILT
mSCIC1_WAKE         equ       mSCI1C1_WAKE
mSCIC1_M            equ       mSCI1C1_M
mSCIC1_RSRC         equ       mSCI1C1_RSRC
mSCIC1_SCISWAI      equ       mSCI1C1_SCISWAI
mSCIC1_LOOPS        equ       mSCI1C1_LOOPS
SCIC2               equ       SCI1C2
SCIC2_SBK           equ       SCI1C2_SBK
SCIC2_RWU           equ       SCI1C2_RWU
SCIC2_RE            equ       SCI1C2_RE
SCIC2_TE            equ       SCI1C2_TE
SCIC2_ILIE          equ       SCI1C2_ILIE
SCIC2_RIE           equ       SCI1C2_RIE
SCIC2_TCIE          equ       SCI1C2_TCIE
SCIC2_TIE           equ       SCI1C2_TIE
mSCIC2_SBK          equ       mSCI1C2_SBK
mSCIC2_RWU          equ       mSCI1C2_RWU
mSCIC2_RE           equ       mSCI1C2_RE
mSCIC2_TE           equ       mSCI1C2_TE
mSCIC2_ILIE         equ       mSCI1C2_ILIE
mSCIC2_RIE          equ       mSCI1C2_RIE
mSCIC2_TCIE         equ       mSCI1C2_TCIE
mSCIC2_TIE          equ       mSCI1C2_TIE
SCIS1               equ       SCI1S1
SCIS1_PF            equ       SCI1S1_PF
SCIS1_FE            equ       SCI1S1_FE
SCIS1_NF            equ       SCI1S1_NF
SCIS1_OR            equ       SCI1S1_OR
SCIS1_IDLE          equ       SCI1S1_IDLE
SCIS1_RDRF          equ       SCI1S1_RDRF
SCIS1_TC            equ       SCI1S1_TC
SCIS1_TDRE          equ       SCI1S1_TDRE
mSCIS1_PF           equ       mSCI1S1_PF
mSCIS1_FE           equ       mSCI1S1_FE
mSCIS1_NF           equ       mSCI1S1_NF
mSCIS1_OR           equ       mSCI1S1_OR
mSCIS1_IDLE         equ       mSCI1S1_IDLE
mSCIS1_RDRF         equ       mSCI1S1_RDRF
mSCIS1_TC           equ       mSCI1S1_TC
mSCIS1_TDRE         equ       mSCI1S1_TDRE
SCIS2               equ       SCI1S2
SCIS2_RAF           equ       SCI1S2_RAF
SCIS2_LBKDE         equ       SCI1S2_LBKDE
SCIS2_BRK13         equ       SCI1S2_BRK13
SCIS2_RWUID         equ       SCI1S2_RWUID
SCIS2_RXINV         equ       SCI1S2_RXINV
SCIS2_RXEDGIF       equ       SCI1S2_RXEDGIF
SCIS2_LBKDIF        equ       SCI1S2_LBKDIF
mSCIS2_RAF          equ       mSCI1S2_RAF
mSCIS2_LBKDE        equ       mSCI1S2_LBKDE
mSCIS2_BRK13        equ       mSCI1S2_BRK13
mSCIS2_RWUID        equ       mSCI1S2_RWUID
mSCIS2_RXINV        equ       mSCI1S2_RXINV
mSCIS2_RXEDGIF      equ       mSCI1S2_RXEDGIF
mSCIS2_LBKDIF       equ       mSCI1S2_LBKDIF
SCIC3               equ       SCI1C3
SCIC3_PEIE          equ       SCI1C3_PEIE
SCIC3_FEIE          equ       SCI1C3_FEIE
SCIC3_NEIE          equ       SCI1C3_NEIE
SCIC3_ORIE          equ       SCI1C3_ORIE
SCIC3_TXINV         equ       SCI1C3_TXINV
SCIC3_TXDIR         equ       SCI1C3_TXDIR
SCIC3_T8            equ       SCI1C3_T8
SCIC3_R8            equ       SCI1C3_R8
mSCIC3_PEIE         equ       mSCI1C3_PEIE
mSCIC3_FEIE         equ       mSCI1C3_FEIE
mSCIC3_NEIE         equ       mSCI1C3_NEIE
mSCIC3_ORIE         equ       mSCI1C3_ORIE
mSCIC3_TXINV        equ       mSCI1C3_TXINV
mSCIC3_TXDIR        equ       mSCI1C3_TXDIR
mSCIC3_T8           equ       mSCI1C3_T8
mSCIC3_R8           equ       mSCI1C3_R8
SCID                equ       SCI1D
SCID_R0_T0          equ       SCI1D_R0_T0
SCID_R1_T1          equ       SCI1D_R1_T1
SCID_R2_T2          equ       SCI1D_R2_T2
SCID_R3_T3          equ       SCI1D_R3_T3
SCID_R4_T4          equ       SCI1D_R4_T4
SCID_R5_T5          equ       SCI1D_R5_T5
SCID_R6_T6          equ       SCI1D_R6_T6
SCID_R7_T7          equ       SCI1D_R7_T7
mSCID_R0_T0         equ       mSCI1D_R0_T0
mSCID_R1_T1         equ       mSCI1D_R1_T1
mSCID_R2_T2         equ       mSCI1D_R2_T2
mSCID_R3_T3         equ       mSCI1D_R3_T3
mSCID_R4_T4         equ       mSCI1D_R4_T4
mSCID_R5_T5         equ       mSCI1D_R5_T5
mSCID_R6_T6         equ       mSCI1D_R6_T6
mSCID_R7_T7         equ       mSCI1D_R7_T7
IICA                equ       IIC1A
IICA_AD1            equ       IIC1A_AD1
IICA_AD2            equ       IIC1A_AD2
IICA_AD3            equ       IIC1A_AD3
IICA_AD4            equ       IIC1A_AD4
IICA_AD5            equ       IIC1A_AD5
IICA_AD6            equ       IIC1A_AD6
IICA_AD7            equ       IIC1A_AD7
mIICA_AD1           equ       mIIC1A_AD1
mIICA_AD2           equ       mIIC1A_AD2
mIICA_AD3           equ       mIIC1A_AD3
mIICA_AD4           equ       mIIC1A_AD4
mIICA_AD5           equ       mIIC1A_AD5
mIICA_AD6           equ       mIIC1A_AD6
mIICA_AD7           equ       mIIC1A_AD7
IICF                equ       IIC1F
IICF_ICR0           equ       IIC1F_ICR0
IICF_ICR1           equ       IIC1F_ICR1
IICF_ICR2           equ       IIC1F_ICR2
IICF_ICR3           equ       IIC1F_ICR3
IICF_ICR4           equ       IIC1F_ICR4
IICF_ICR5           equ       IIC1F_ICR5
IICF_MULT0          equ       IIC1F_MULT0
IICF_MULT1          equ       IIC1F_MULT1
mIICF_ICR0          equ       mIIC1F_ICR0
mIICF_ICR1          equ       mIIC1F_ICR1
mIICF_ICR2          equ       mIIC1F_ICR2
mIICF_ICR3          equ       mIIC1F_ICR3
mIICF_ICR4          equ       mIIC1F_ICR4
mIICF_ICR5          equ       mIIC1F_ICR5
mIICF_MULT0         equ       mIIC1F_MULT0
mIICF_MULT1         equ       mIIC1F_MULT1
IICC1               equ       IIC1C1
IICC1_RSTA          equ       IIC1C1_RSTA
IICC1_TXAK          equ       IIC1C1_TXAK
IICC1_TX            equ       IIC1C1_TX
IICC1_MST           equ       IIC1C1_MST
IICC1_IICIE         equ       IIC1C1_IICIE
IICC1_IICEN         equ       IIC1C1_IICEN
mIICC1_RSTA         equ       mIIC1C1_RSTA
mIICC1_TXAK         equ       mIIC1C1_TXAK
mIICC1_TX           equ       mIIC1C1_TX
mIICC1_MST          equ       mIIC1C1_MST
mIICC1_IICIE        equ       mIIC1C1_IICIE
mIICC1_IICEN        equ       mIIC1C1_IICEN
IICC                equ       IIC1C
IICC_RSTA           equ       IIC1C_RSTA
IICC_TXAK           equ       IIC1C_TXAK
IICC_TX             equ       IIC1C_TX
IICC_MST            equ       IIC1C_MST
IICC_IICIE          equ       IIC1C_IICIE
IICC_IICEN          equ       IIC1C_IICEN
mIICC_RSTA          equ       mIIC1C_RSTA
mIICC_TXAK          equ       mIIC1C_TXAK
mIICC_TX            equ       mIIC1C_TX
mIICC_MST           equ       mIIC1C_MST
mIICC_IICIE         equ       mIIC1C_IICIE
mIICC_IICEN         equ       mIIC1C_IICEN
IICS                equ       IIC1S
IICS_RXAK           equ       IIC1S_RXAK
IICS_IICIF          equ       IIC1S_IICIF
IICS_SRW            equ       IIC1S_SRW
IICS_ARBL           equ       IIC1S_ARBL
IICS_BUSY           equ       IIC1S_BUSY
IICS_IAAS           equ       IIC1S_IAAS
IICS_TCF            equ       IIC1S_TCF
mIICS_RXAK          equ       mIIC1S_RXAK
mIICS_IICIF         equ       mIIC1S_IICIF
mIICS_SRW           equ       mIIC1S_SRW
mIICS_ARBL          equ       mIIC1S_ARBL
mIICS_BUSY          equ       mIIC1S_BUSY
mIICS_IAAS          equ       mIIC1S_IAAS
mIICS_TCF           equ       mIIC1S_TCF
IICD                equ       IIC1D
IICD_DATA0          equ       IIC1D_DATA0
IICD_DATA1          equ       IIC1D_DATA1
IICD_DATA2          equ       IIC1D_DATA2
IICD_DATA3          equ       IIC1D_DATA3
IICD_DATA4          equ       IIC1D_DATA4
IICD_DATA5          equ       IIC1D_DATA5
IICD_DATA6          equ       IIC1D_DATA6
IICD_DATA7          equ       IIC1D_DATA7
mIICD_DATA0         equ       mIIC1D_DATA0
mIICD_DATA1         equ       mIIC1D_DATA1
mIICD_DATA2         equ       mIIC1D_DATA2
mIICD_DATA3         equ       mIIC1D_DATA3
mIICD_DATA4         equ       mIIC1D_DATA4
mIICD_DATA5         equ       mIIC1D_DATA5
mIICD_DATA6         equ       mIIC1D_DATA6
mIICD_DATA7         equ       mIIC1D_DATA7
IICC2               equ       IIC1C2
IICC2_AD8           equ       IIC1C2_AD8
IICC2_AD9           equ       IIC1C2_AD9
IICC2_AD10          equ       IIC1C2_AD10
IICC2_ADEXT         equ       IIC1C2_ADEXT
IICC2_GCAEN         equ       IIC1C2_GCAEN
mIICC2_AD8          equ       mIIC1C2_AD8
mIICC2_AD9          equ       mIIC1C2_AD9
mIICC2_AD10         equ       mIIC1C2_AD10
mIICC2_ADEXT        equ       mIIC1C2_ADEXT
mIICC2_GCAEN        equ       mIIC1C2_GCAEN
SPIC1               equ       SPI1C1
SPIC1_LSBFE         equ       SPI1C1_LSBFE
SPIC1_SSOE          equ       SPI1C1_SSOE
SPIC1_CPHA          equ       SPI1C1_CPHA
SPIC1_CPOL          equ       SPI1C1_CPOL
SPIC1_MSTR          equ       SPI1C1_MSTR
SPIC1_SPTIE         equ       SPI1C1_SPTIE
SPIC1_SPE           equ       SPI1C1_SPE
SPIC1_SPIE          equ       SPI1C1_SPIE
mSPIC1_LSBFE        equ       mSPI1C1_LSBFE
mSPIC1_SSOE         equ       mSPI1C1_SSOE
mSPIC1_CPHA         equ       mSPI1C1_CPHA
mSPIC1_CPOL         equ       mSPI1C1_CPOL
mSPIC1_MSTR         equ       mSPI1C1_MSTR
mSPIC1_SPTIE        equ       mSPI1C1_SPTIE
mSPIC1_SPE          equ       mSPI1C1_SPE
mSPIC1_SPIE         equ       mSPI1C1_SPIE
SPIC2               equ       SPI1C2
SPIC2_SPC0          equ       SPI1C2_SPC0
SPIC2_SPISWAI       equ       SPI1C2_SPISWAI
SPIC2_BIDIROE       equ       SPI1C2_BIDIROE
SPIC2_MODFEN        equ       SPI1C2_MODFEN
mSPIC2_SPC0         equ       mSPI1C2_SPC0
mSPIC2_SPISWAI      equ       mSPI1C2_SPISWAI
mSPIC2_BIDIROE      equ       mSPI1C2_BIDIROE
mSPIC2_MODFEN       equ       mSPI1C2_MODFEN
SPIBR               equ       SPI1BR
SPIBR_SPR0          equ       SPI1BR_SPR0
SPIBR_SPR1          equ       SPI1BR_SPR1
SPIBR_SPR2          equ       SPI1BR_SPR2
SPIBR_SPPR0         equ       SPI1BR_SPPR0
SPIBR_SPPR1         equ       SPI1BR_SPPR1
SPIBR_SPPR2         equ       SPI1BR_SPPR2
mSPIBR_SPR0         equ       mSPI1BR_SPR0
mSPIBR_SPR1         equ       mSPI1BR_SPR1
mSPIBR_SPR2         equ       mSPI1BR_SPR2
mSPIBR_SPPR0        equ       mSPI1BR_SPPR0
mSPIBR_SPPR1        equ       mSPI1BR_SPPR1
mSPIBR_SPPR2        equ       mSPI1BR_SPPR2
SPIS                equ       SPI1S
SPIS_MODF           equ       SPI1S_MODF
SPIS_SPTEF          equ       SPI1S_SPTEF
SPIS_SPRF           equ       SPI1S_SPRF
mSPIS_MODF          equ       mSPI1S_MODF
mSPIS_SPTEF         equ       mSPI1S_SPTEF
mSPIS_SPRF          equ       mSPI1S_SPRF
SPID                equ       SPI1D
SCIC4               equ       SCI1C4
SCIC4_BRFA0         equ       SCI1C4_BRFA0
SCIC4_BRFA1         equ       SCI1C4_BRFA1
SCIC4_BRFA2         equ       SCI1C4_BRFA2
SCIC4_BRFA3         equ       SCI1C4_BRFA3
SCIC4_BRFA4         equ       SCI1C4_BRFA4
mSCIC4_BRFA0        equ       mSCI1C4_BRFA0
mSCIC4_BRFA1        equ       mSCI1C4_BRFA1
mSCIC4_BRFA2        equ       mSCI1C4_BRFA2
mSCIC4_BRFA3        equ       mSCI1C4_BRFA3
mSCIC4_BRFA4        equ       mSCI1C4_BRFA4

   #ifndef __GENERATE_APPLICATION__

   #endif

; EOF
