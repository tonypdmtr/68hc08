;*******************************************************************************
;*            MC9S08QD2 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER              *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  *********************
                    #Message  * Target: MC9S08QD2 *
                    #Message  *********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_qd2.exp
  #endif

#endif

_QD_                def       2
_QD2_               def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*
;* Description: Register and bit name definitions for 9S08QD2
;*
;* Documentation: 9S08QD2 family Data Sheet for register and bit explanations
;* HCS08 Family Reference Manual (HCS08RM1/D) appendix B for explanation of
;* equate files
;*
;* Modified by T-Pap as follows:
;*
;* 1. All bit names for use with BSET/BCLR/BRSET/BRCLR end with a dot (.)
;* 2. All bit names for use as masks end with an underscore (_)
;* 3. ASM8's segments RAM, ROM, XROM, SEG9 (OS8), EEPROM and VECTORS
;*    initialized with appropriate values for immediate use.
;* 4. The assembly-time symbol FLASH_DATA_SIZE optionally defines the protected Flash
;*    as the difference between total flash and FLASH_DATA_SIZE
;*    Based on MC9S08QD2's architecture, FLASH_DATA_SIZE can only be a multiple
;*    of FLASH_PAGE_SIZE.  An invalid value will be rounded to closest valid one.
;* 5. ASM8's #MEMORY directive used to define actual Flash space for user code/data
;*
;* Include Files: COMMON.INC
;*
;* Assembler:  ASM8 by Tony G. Papadimitriou <tonyp@acm.org>
;*
;* Revision History: not yet released
;* Rev #     Date      Who     Comments
;* -----  -----------  ------  -------------------------------------------------
;*  1.0    23-Nov-11   T-Pap   Release version for 9S08QD2
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $184F               ;end of high page registers

; Vectors

Vrti                equ       $FFD0               ;RTI (periodic interrupt) vector
Vadc                equ       $FFD8               ;A/D conversion vector
Vkeyboard           equ       $FFDA               ;keyboard vector
Vtpm2ovf            equ       $FFEA               ;TPM2 overflow vector
Vtpm2ch0            equ       $FFEE               ;TPM2 channel 0 vector
Vtpm1ovf            equ       $FFF0               ;TPM1 overflow vector
Vtpm1ch1            equ       $FFF2               ;TPM1 channel 1 vector
Vtpm1ch0            equ       $FFF4               ;TPM1 channel 0 vector
Virq                equ       $FFF8               ;IRQ pin vector
Vlvd                equ       $FFFA               ;low voltage detect vector
Vswi                equ       $FFFC               ;SWI vector
Vreset              equ       $FFFE               ;reset vector

; **** Input/Output (I/O) Ports ************************************************

PTAD                equ       $00,1               ;I/O port A data register
PORTA               equ       PTAD,1
PTADD               equ       $01,1               ;I/O port A data direction register
DDRA                equ       $01,1               ;I/O port A data direction register

; **** Keyboard Interrupt Module (KBI) *****************************************

KBISC               equ       $0C,1               ;KBI status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   KBF,3               ;KBI flag
                    @bitnum   KBACK,2             ;acknowledge
                    @bitnum   KBIE,1              ;KBI interrupt enable
                    @bitnum   KBIMOD,0            ;KBI mode select

KBIPE               equ       $0D,1               ;KBI pin enable controls
KBIES               equ       $0E,1               ;KBI edge-select register

; **** Interrupt Request Module (IRQ) ******************************************

IRQSC               equ       $0F,1               ;IRQ status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IRQPDD,6            ;IRQ pin pullup disable
                    @bitnum   IRQEDG,5            ;IRQ pin edge sensitivity
                    @bitnum   IRQPE,4             ;IRQ pin enable (PTB5)
                    @bitnum   IRQF,3              ;IRQ flag
                    @bitnum   IRQACK,2            ;acknowledge IRQ flag
                    @bitnum   IRQIE,1             ;IRQ pin interrupt enable
                    @bitnum   IRQMOD,0            ;IRQ mode

; **** Analog-to-Digital Converter Module (ATD) ********************************

ADCSC1              equ       $10,1               ;A/D Status & Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   COCO,7              ;Conversion Complete Flag
                    @bitnum   AIEN,6              ;Interrupt Enable
                    @bitnum   ADCO,5              ;Continuous Conversion Enable

ADCSC2              equ       $11,1               ;A/D Status & Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   ADACT,7             ;Conversion Active
                    @bitnum   ADTRG,6             ;Conversion Trigger Select
                    @bitnum   ACFE,5              ;Compare Function Enable
                    @bitnum   ACFGT,4             ;Compare Function Greater Than Enable

ADCR                equ       $12,2               ;A/D Result
ADCRH               equ       $12,1               ;A/D Result High
ADCRL               equ       $13,1               ;A/D Result Low
ADCCV               equ       $14,2               ;A/D Compare
ADCCVH              equ       $14,1               ;A/D Compare High
ADCCVL              equ       $15,1               ;A/D Compare Low

ADCCFG              equ       $16,1               ;A/D Configuration Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   ADLPC,7             ;Low power configuration
                    @bitnum   ADLSMP,4            ;Long Time Sample Configuration

APCTL1              equ       $17,1               ;Pin Control 1 Register (Ch. 00-07)

; **** Timer/PWM1 Module (TPM) ***** TPM2 has 1 channel *************************

TPM2SC              equ       $20,1               ;TPM status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TOF,7               ;timer overflow flag
                    @bitnum   TOIE,6              ;TOF interrupt enable
                    @bitnum   CPWMS,5             ;centered PWM select
                    @bitnum   CLKSB,4             ;clock select bits
                    @bitnum   CLKSA,3             ;         -//-
                    @bitnum   PS2,2               ;prescaler bits
                    @bitnum   PS1,1               ;         -//-
                    @bitnum   PS0,0               ;         -//-

TPM2CNT             equ       $21,2               ;TPM counter
TPM2CNTH            equ       $21,1               ;TPM counter (high half)
TPM2CNTL            equ       $22,1               ;TPM counter (low half)
TPM2MOD             equ       $23,2               ;TPM modulo register
TPM2MODH            equ       $23,1               ;TPM modulo register (high half)
TPM2MODL            equ       $24,1               ;TPM modulo register(low half)

TPM2C0SC            equ       $25,1               ;TPM channel 0 status and control
TPM2C0V             equ       $26,2               ;TPM channel 0 value register
TPM2C0VH            equ       $26,1               ;TPM channel 0 value register (high)
TPM2C0VL            equ       $27,1               ;TPM channel 0 value register (low)

;-------------------------------------------------------------------------------
; Internal Clock Source (ICS)
;-------------------------------------------------------------------------------

ICSC1               equ       $38,1               ;ICS Control Register 1

                    @bitnum   CLKS1,7             ;Clock Source Select
                    @bitnum   CLKS0,6
                    @bitnum   RDIV2,5             ;Reference Divider
                    @bitnum   RDIV1,4
                    @bitnum   RDIV0,3
                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable

;-------------------------------------------------------------------------------

ICSC2               equ       $39,1               ;ICS Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   BDIV1,7             ;Bus Frequency Divider
                    @bitnum   BDIV0,6
                    @bitnum   RANGE_SEL,5         ;Frequency Range Select
                    @bitnum   HGO,4               ;High Gain Oscillator Select
                    @bitnum   LP,3                ;Low Power Select
                    @bitnum   EREFS,2             ;External Reference Select
                    @bitnum   ERCLKEN,1           ;External Reference Enable
                    @bitnum   EREFSTEN,0          ;External Reference Stop Enable

;-------------------------------------------------------------------------------

ICSTRM              equ       $3A,1               ;ICS Trim Register
ICSSC               equ       $3B,1               ;ICS Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

; ICSSC

                    @bitnum   CLKST1,3            ;Clock Mode Status
                    @bitnum   CLKST0,2
                    @bitnum   OSCINIT,1           ;OSC Initialization
                    @bitnum   FTRIM,0             ;ICS Fine Trim

; **** Timer/PWM Module (TPM) ***** TPM has 2 channels *************************

TPMSC               equ       $40,1               ;TPM status and control register
TPMCNT              equ       $41,2               ;TPM counter
TPMCNTH             equ       $41,1               ;TPM counter (high half)
TPMCNTL             equ       $42,1               ;TPM counter (low half)
TPMMOD              equ       $43,2               ;TPM modulo register
TPMMODH             equ       $43,1               ;TPM modulo register (high half)
TPMMODL             equ       $44,1               ;TPM modulo register(low half)

TPMC0SC             equ       $45,1               ;TPM channel 0 status and control

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   CHxF,7              ;channel 0 flag
                    @bitnum   CHxIE,6             ;ch 0 interrupt enable
                    @bitnum   MSxB,5              ;mode select B
                    @bitnum   MSxA,4              ;mode select A
                    @bitnum   ELSxB,3             ;edge/level select B
                    @bitnum   ELSxA,2             ;edge/level select A

TPMC0V              equ       $46,2               ;TPM channel 0 value register
TPMC0VH             equ       $46,1               ;TPM channel 0 value register (high)
TPMC0VL             equ       $47,1               ;TPM channel 0 value register (low)

TPMC1SC             equ       $48,1               ;TPM channel 1 status and control
TPMC1V              equ       $49,2               ;TPM channel 1 value register
TPMC1VH             equ       $49,1               ;TPM channel 1 value register (high)
TPMC1VL             equ       $4A,1               ;TPM channel 1 value register (low)

; Aliases

TPM1SC              equ       TPMSC,1             ;TPM Status and Control
TPM1CNT             equ       TPMCNTH,2           ;TPM counter
TPM1CNTH            equ       TPMCNTH,1           ;TPM counter (high half)
TPM1CNTL            equ       TPMCNTL,1           ;TPM counter (low half)
TPM1MOD             equ       TPMMODH,2           ;TPM modulo register
TPM1MODH            equ       TPMMODH,1           ;TPM modulo register (high half)
TPM1MODL            equ       TPMMODL,1           ;TPM modulo register(low half)
TPM1C0SC            equ       TPMC0SC,1           ;TPM channel 0 status and control
TPM1C0V             equ       TPMC0VH,2           ;TPM channel 0 value register
TPM1C0VH            equ       TPMC0VH,1           ;TPM channel 0 value register (high)
TPM1C0VL            equ       TPMC0VL,1           ;TPM channel 0 value register (low)
TPM1C1SC            equ       TPMC1SC,1           ;TPM channel 1 status and control
TPM1C1V             equ       TPMC1VH,2           ;TPM channel 1 value register
TPM1C1VH            equ       TPMC1VH,1           ;TPM channel 1 value register (high)
TPM1C1VL            equ       TPMC1VL,1           ;TPM channel 1 value register (low)

; **** System Integration Module (SIM) *****************************************

SRS                 equ       $1800,1             ;SIM reset status register
COP                 equ       SRS,1               ;for "STA COP"

; bit position masks

POR_                equ       %10000000           ;power-on reset
PIN_                equ       %01000000           ;external reset pin
COP_                equ       %00100000           ;COP watchdog timed out
ILOP_               equ       %00010000           ;illegal opcode
ILAD_               equ       %00001000           ;illegal address access
LVD_                equ       %00000010           ;low-voltage detect

SBDFR               equ       $1801,1             ;system BDM reset register

; bit position masks

BDFR_               equ       %00000001           ;BDM force reset

SOPT1               equ       $1802,1             ;SIM System Options Register 1 (write once)
SOPT                equ       SOPT1,1

; bit position masks

COPE_               equ       %10000000           ;COP watchdog enable
COPT_               equ       %01000000           ;COP time-out select
STOPE_              equ       %00100000           ;Stop Mode Enable
BKGDPE_             equ       %00000010           ;BDM pin enable
RSTPE_              equ       %00000001           ;Reset pin enable

SOPT2               equ       $1803,1             ;SIM System Options Register 2 (write once)

; bit position masks

COPCLKS_            equ       %10000000           ;COP watchdog clock select

SDID                equ       $1806,2             ;system device identification 1 register (read-only)
SDIDH               equ       $1806,1             ;system device identification 1 register (read-only)
SDIDL               equ       $1807,1             ;rev3,2,1,0 + 12-bit ID. QG8 ID = $009

; bit position masks within SDIDH

REV3_               equ       %10000000           ;device revision identification (high)
REV2_               equ       %01000000           ;device revision identification
REV1_               equ       %00100000           ;device revision identification
REV0_               equ       %00010000           ;device revision identification (low)

; **** Real Time Interrupt Module (RTI) ****************************************

SRTISC              equ       $1808,1             ;System RTI status and control register

; bit position masks

RTIF_               equ       %10000000           ;real-time interrupt flag
RTIACK_             equ       %01000000           ;real-time interrupt acknowledge
RTICLKS_            equ       %00100000           ;real-time interrupt clock select
RTIE_               equ       %00010000           ;real-time interrupt enable
RTIS2_              equ       %00000100           ;real-time interrupt delay select (high)
RTIS1_              equ       %00000010           ;real-time interrupt delay select
RTIS0_              equ       %00000001           ;real-time interrupt delay select (low)

; **** Power Management and Control Module (PMC) *******************************

SPMSC1              equ       $1809,1             ;System power management status and control 1 register

; bit position masks

LVDF_               equ       %10000000           ;low voltage detect flag
LVDACK_             equ       %01000000           ;LVD interrupt acknowledge
LVDIE_              equ       %00100000           ;LVD interrupt enable
LVDRE_              equ       %00010000           ;LVD reset enable (write once bit)
LVDSE_              equ       %00001000           ;LDV stop enable (write once bit)
LVDE_               equ       %00000100           ;LVD enable (write once bit)
BGBE_               equ       %00000001           ;Bandgap Band Enable

SPMSC2              equ       $180A,1             ;System power management status and control 2 register

; bit position masks

LVWF_               equ       %10000000           ;low voltage warning flag
LVWACK_             equ       %01000000           ;low voltage warning acknowledge
LVDV_               equ       %00100000           ;low voltage detect voltage select
LVWV_               equ       %00010000           ;low voltage warning voltage select
PPDF_               equ       %00001000           ;partial power down flag
PPDACK_             equ       %00000100           ;partial power down acknowledge
PPDC_               equ       %00000001           ;partial power down control

; **** Flash Module (FLASH) ****************************************************

FCDIV               equ       $1820,1             ;Flash clock divider register

; bit position masks

DIVLD_              equ       %10000000           ;clock divider loaded
PRDIV8_             equ       %01000000           ;enable prescale by 8

FOPT                equ       $1821,1             ;Flash options register

; bit position masks

KEYEN_              equ       %10000000           ;enable backdoor key to security
FNORED_             equ       %01000000           ;Vector redirection enable
SEC01_              equ       %00000010           ;security state code (high)
SEC00_              equ       %00000001           ;security state code (low)

FCNFG               equ       $1823,1             ;Flash configuration register

; bit position masks

KEYACC_             equ       %00100000           ;enable security key writing

FPROT               equ       $1824,1             ;Flash protection register

; bit position masks

FPDIS_              equ       %00000001           ;flash protection disable

FSTAT               equ       $1825,1             ;Flash status register

; bit position masks

FCBEF_              equ       %10000000           ;flash command buffer empty flag
FCCF_               equ       %01000000           ;flash command complete flag
FPVIOL_             equ       %00100000           ;flash protection violation
FACCERR_            equ       %00010000           ;flash access error
FBLANK_             equ       %00000100           ;flash verified as all blank (erased =$ff) flag

FCMD                equ       $1826,1             ;Flash command register

; command codes for flash programming/erasure to be used with FCMD register

mBlank              equ       $05                 ;Blank Check command
mByteProg           equ       $20                 ;Byte Program command
mBurstProg          equ       $25                 ;Burst Program command
mPageErase          equ       $40                 ;Page Erase command
mMassErase          equ       $41                 ;Mass Erase command

PTAPE               equ       $1840,1             ;I/O port A pullup enable controls
PTAPUE              equ       PTAPE,1
PTASE               equ       $1841,1             ;I/O port A slew rate control register
PTADS               equ       $1842,1             ;I/O port A drive strength select register

; **** Flash non-volatile register images **************************************

NVFTRIM             equ       $FFAE,1             ;NV FTRIM
NVICSTRM            equ       $FFAF,1             ;NV ICS Trim
NVBACKKEY           equ       $FFB0,8             ;8-byte backdoor comparison key ($FFB0..$FFB7)

; following 2 registers transfered from flash to working regs at reset

NVPROT              equ       $FFBD,1             ;NV flash protection byte

; NVPROT transfers to FPROT on reset

NVOPT               equ       $FFBF,1             ;NV flash options byte

; NVOPT transfers to FOPT on reset

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08QD2_           def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFD0               ;start of fixed vectors

TRUE_ROM            equ       $F800               ;start of flash used as EEPROM (main ROM)

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
?NVPROT_MASK        equ       TRUE_ROM+FLASH_DATA_SIZE-1&$FE00>8 ;enable FPROT
RVECTORS            equ       VECTORS-$FFFF+TRUE_ROM+FLASH_DATA_SIZE-1

EEPROM              def       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

ROM                 def       EEPROM_END+1
ROM_END             equ       $FFA9               ;end of all flash (before NV registers and fixed vectors)

SERIAL_NUMBER       equ       $FFC0               ;start of optional S/N

RAM                 equ       $80                 ;start of 512 byte RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 4096 byte RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

#ifndef MHZ||HZ
KHZ                 def       16000               ;16 MHz internal oscillator
#endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

                    #EEPROM   EEPROM

                    #DATA

          #ifndef NO_CODE
                    org       NVPROT              ;NV flash protection byte
                    fcb       ?NVPROT_MASK        ;NVPROT transfers to FPROT on reset
                             ; 00000000
                             ; |||||+++----------- Not Used (Always 0)
                             ; ||+++-------------- FPS2..FPS1 Flash Protect Size Selects
                             ; |+----------------- FPDIS - Flash Protection Disable
                             ; +------------------ FPOPEN - Non-protected memory can be altered
          #endif
          #ifndef NVOPT_VALUE
                    #Message  Using default NVOPT_VALUE (no vector redirection)
          #endif

          #ifdef DEBUG
NVOPT_VALUE         def       %11000010           ;NVFEOPT transfers to FOPT on reset
          #endif
NVOPT_VALUE         def       %11000000           ;NVFEOPT transfers to FOPT on reset
                             ; |||||||+----------- SEC00 \ 00:secure  10:unsecure
                             ; ||||||+------------ SEC01 / 01:secure  11:secure
                             ; ||++++------------- Not Used (Always 0)
                             ; |+----------------- FNORED - Vector Redirection Disable (No Redirection)
                             ; +------------------ KEYEN - Backdoor key mechanism enable
          #ifndef NO_CODE
                    org       NVOPT               ;NV flash options byte
                    fcb       NVOPT_VALUE         ;NVFEOPT transfers to FOPT on reset
          #endif
;                   org       NVICGTRIM           ;NV ICG Trim Setting
;                   fcb       ??                  ;ICG trim value measured during factory test. User software optionally
;                                                 ;copies to ICGTRM during initialization.
                    #VECTORS  VECTORS
                    #RAM      RAM
                    #XRAM     ROM                 ;to cause #VARIABLE error(s)
                    #ROM      ROM

                    #MEMORY   ROM       ROM_END
                    #MEMORY   EEPROM    EEPROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
;                   #MEMORY   NVFTRIM
;                   #MEMORY   NVICSTRM
                    #MEMORY   NVOPT
                    #MEMORY   VECTORS   VECTORS|$FF
                    #!MEMORY  CRC_LOCATION CRC_LOCATION+1
                    #!MEMORY  RVECTORS  RVECTORS|$FF
