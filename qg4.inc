;*******************************************************************************
;*            MC9S08QG4 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER              *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  *********************
                    #Message  * Target: MC9S08QG4 *
                    #Message  *********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_qg4.exp
  #endif

#endif

_QG_                def       8
_QG4_               def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*
;* Description: Register and bit name definitions for 9S08QG4
;*
;* Documentation: 9S08QG4 family Data Sheet for register and bit explanations
;* HCS08 Family Reference Manual (HCS08RM1/D) appendix B for explanation of
;* equate files
;*
;* Modified by <tonyp@acm.org> as follows:
;*
;* 1. All bit names for use with BSET/BCLR/BRSET/BRCLR end with a dot (.)
;* 2. All bit names for use as masks end with an underscore (_)
;* 3. ASM8's segments RAM, ROM, XROM, SEG9 (OS8), EEPROM and VECTORS
;*    initialized with appropriate values for immediate use.
;* 4. The assembly-time symbol FLASH_DATA_SIZE optionally defines the protected Flash
;*    as the difference between total flash and FLASH_DATA_SIZE
;*    Based on MC9S08QG4's architecture, FLASH_DATA_SIZE can only be a multiple
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
;*  1.0    04-Feb-06   T-Pap   Release version for 9S08QG4
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $184F               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PTAD                equ       $00,1               ;I/O port A data register
PORTA               equ       PTAD,1
PTADD               equ       $01,1               ;I/O port A data direction register
DDRA                equ       $01,1               ;I/O port A data direction register
PTBD                equ       $02,1               ;I/O port B data register
PORTB               equ       PTBD,1
PTBDD               equ       $03,1               ;I/O port B data direction register
DDRB                equ       $03,1               ;I/O port B data direction register

; **** Keyboard Interrupt Module (KBI) *****************************************

KBISC               equ       $0C,1               ;KBI status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   KBEDG7,7            ;rise-hi/fall-low for KBIP7 pin
                    @bitnum   KBEDG6,6            ;rise-hi/fall-low for KBIP6 pin
                    @bitnum   KBEDG5,5            ;rise-hi/fall-low for KBIP5 pin
                    @bitnum   KBEDG4,4            ;rise-hi/fall-low for KBIP4 pin
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

ACMPSC              equ       $1A,1               ;Analog Comparator Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   ACME,7              ;Analog Comparator Module Enable
                    @bitnum   ACBGS,6             ;Analog Comparator Bandgap Select
                    @bitnum   ACF,5               ;Analog Comparator Flag
                    @bitnum   ACIE,4              ;Analog Comparator Interrupt Enable
                    @bitnum   ACO,3               ;Analog Comparator Output
                    @bitnum   ACOPE,2             ;Analog Comparator Output Pin Enable

; **** Serial Communications Interface (SCI) ***********************************

SCIBD               equ       $20,2               ;SCI baud rate register
SCIBDH              equ       $20,1               ;SCI baud rate register (high)
SCIBDL              equ       $21,1               ;SCI baud rate register (low byte)
SCIC1               equ       $22,1               ;SCI Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   LOOPS,7             ;loopback mode
                    @bitnum   SCISWAI,6           ;SCI stop in wait
                    @bitnum   RSRC,5              ;receiver source
                    @bitnum   M,4                 ;9/8 bit data
                    @bitnum   WAKE,3              ;wake by addr mark/idle
                    @bitnum   ILT,2               ;idle line type; stop/start
                    @bitnum   PE,1                ;parity enable
                    @bitnum   PT,0                ;parity type

SCIC2               equ       $23,1               ;SCI Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TIE,7               ;transmit interrupt enable
                    @bitnum   TCIE,6              ;TC interrupt enable
                    @bitnum   RIE,5               ;receive interrupt enable
                    @bitnum   ILIE,4              ;idle line interrupt enable
                    @bitnum   TE,3                ;transmitter enable
                    @bitnum   RE,2                ;receiver enable
                    @bitnum   RWU,1               ;receiver wakeup engage
                    @bitnum   SBK,0               ;send break

SCIS1               equ       $24,1               ;SCI Status Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TDRE,7              ;Tx data register empty
                    @bitnum   TC,6                ;transmit complete
                    @bitnum   RDRF,5              ;Rx data register full
                    @bitnum   IDLE,4              ;idle line detected
                    @bitnum   OR,3                ;Rx over run
                    @bitnum   NF,2                ;Rx noise flag
                    @bitnum   FE,1                ;Rx framing error
                    @bitnum   PF,0                ;Rx parity failed

SCIS2               equ       $25,1               ;SCI Status Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   BRK13,2             ;Break Character Length
                    @bitnum   RAF,0               ;Receiver Active Flag

SCIC3               equ       $26,1               ;SCI Control Register 3

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   R8,7                ;9th Rx bit
                    @bitnum   T8,6                ;9th Tx bit
                    @bitnum   TXDIR,5             ;TxD pin direction?
                    @bitnum   TXINV,4             ;Transmit Data Inversion
                    @bitnum   ORIE,3              ;Rx over run int. enable
                    @bitnum   NEIE,2              ;Rx noise flag int. enable
                    @bitnum   FEIE,1              ;Rx framing error int. enable
                    @bitnum   PEIE,0              ;Rx parity error int. enable

SCID                equ       $27,1               ;SCI Data Register (low byte)

; **** Serial Peripheral Interface (SPI) ***************************************

SPIC1               equ       $28,1               ;SPI control register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   SPIE,7              ;SPI interrupt enable
                    @bitnum   SPE,6               ;SPI enable
                    @bitnum   SPTIE,5             ;Tx error interrupt enable
                    @bitnum   MSTR,4              ;master/slave
                    @bitnum   CPOL,3              ;clock polarity
                    @bitnum   CPHA,2              ;clock phase
                    @bitnum   SSOE,1              ;SS output enable
                    @bitnum   LSBFE,0             ;LSB-first enable

SPIC2               equ       $29,1               ;SPI control register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   MODFEN,4            ;mode fault enable
                    @bitnum   BIDIROE,3           ;bi-directional enable
                    @bitnum   SPISWAI,1           ;SPI stops in wait
                    @bitnum   SPC0,0              ;SPI pin 0 control

SPIBR               equ       $2A,1               ;SPI baud rate select

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   SPPR2,6             ;SPI baud rate prescale
                    @bitnum   SPPR1,5             ;         -//-
                    @bitnum   SPPR0,4             ;         -//-
                    @bitnum   SPR2,2              ;SPI rate selact
                    @bitnum   SPR1,1              ;         -//-
                    @bitnum   SPR0,0              ;         -//-

SPIS                equ       $2B,1               ;SPI status register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   SPRF,7              ;SPI Rx full flag
                    @bitnum   SPTEF,5             ;SPI Transmit Buffer Empty Flag
                    @bitnum   MODF,4              ;mode fault flag

SPID                equ       $2D,1               ;SPI data register

; **** Inter-Integrated Circuit Module (IIC) ***********************************

IICA                equ       $30,1               ;IIC address register

IICF                equ       $31,1               ;IIC frequency divider register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   MULT1,7             ;IIC multiply factor (high)
                    @bitnum   MULT0,6             ;IIC multiply factor (low)
                    @bitnum   ICR5,5              ;IIC Divider and Hold bit-5
                    @bitnum   ICR4,4              ;IIC Divider and Hold bit-4
                    @bitnum   ICR3,3              ;IIC Divider and Hold bit-3
                    @bitnum   ICR2,2              ;IIC Divider and Hold bit-2
                    @bitnum   ICR1,1              ;IIC Divider and Hold bit-1
                    @bitnum   ICR0,0              ;IIC Divider and Hold bit-0

IICC                equ       $32,1               ;IIC control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IICEN,7             ;IIC enable bit
                    @bitnum   IICIE,6             ;IIC interrupt enable bit
                    @bitnum   MST,5               ;IIC master mode select bit
                    @bitnum   TX,4                ;IIC transmit mode select bit
                    @bitnum   TXAK,3              ;IIC transmit acknowledge bit
                    @bitnum   RSTA,2              ;IIC repeat start bit

IICS                equ       $33,1               ;IIC status register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TCF,7               ;IIC transfer complete flag bit
                    @bitnum   IAAS,6              ;IIC addressed as slave bit
                    @bitnum   BUSY,5              ;IIC bus busy bit
                    @bitnum   ARBL,4              ;IIC arbitration lost bit
                    @bitnum   SRW,2               ;IIC slave read/write bit
                    @bitnum   IICIF,1             ;IIC interrupt flag bit
                    @bitnum   RXAK,0              ;IIC receive acknowledge bit

IICD                equ       $34,1               ;IIC data I/O register bits 7:0

; **** Internal Clock Source (ICS) *********************************************

ICSC1               equ       $38,1               ;ICS Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable

ICSC2               equ       $39,1               ;ICS Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   RANGE_SEL,5         ;Frequency Range Select
                    @bitnum   HGO,4               ;High Gain Oscillator Select
                    @bitnum   LP,3                ;Low Power Select
                    @bitnum   EREFS,2             ;External Reference Select
                    @bitnum   ERCLKEN,1           ;External Reference Enable
                    @bitnum   EREFSTEN,0          ;External Reference Stop Enable

ICSTRM              equ       $3A,1               ;ICS Trim Register

ICSSC               equ       $3B,1               ;ICS Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   OSCINIT,1           ;OSC Initialization
                    @bitnum   FTRIM,0             ;ICS Fine Trim

; **** Modulo Timer (MTIM) *****************************************************

MTIMSC              equ       $3C,1               ;MTIM Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TOF,7               ;MTIM Overflow Flag
                    @bitnum   TOIE,6              ;MTIM Overflow Interrupt Enable
                    @bitnum   TRST,5              ;MTIM Counter Reset
                    @bitnum   TSTP,4              ;MTIM Counter Stop

MTIMCLK             equ       $3D,1               ;MTIM Clock Configuration Register
MTIMCNT             equ       $3E,1               ;MTIM Counter Register
MTIMMOD             equ       $3F,1               ;MTIM Prescaler Register

; **** Timer/PWM Module (TPM) ***** TPM has 2 channels *************************

TPMSC               equ       $40,1               ;TPM status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

;                   @bitnum   TOF,7               ;timer overflow flag
;                   @bitnum   TOIE,6              ;TOF interrupt enable
                    @bitnum   CPWMS,5             ;centered PWM select
                    @bitnum   CLKSB,4             ;clock select bits
                    @bitnum   CLKSA,3             ;         -//-
                    @bitnum   PS2,2               ;prescaler bits
                    @bitnum   PS1,1               ;         -//-
                    @bitnum   PS0,0               ;         -//-

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
IICPS_              equ       %00000010           ;IIC pin select
ACIC_               equ       %00000001           ;Analog Comparator to Input Capture Enable

SDID                equ       $1806,2             ;system device identification 1 register (read-only)
SDIDH               equ       $1806,1             ;system device identification 1 register (read-only)
SDIDL               equ       $1807,1             ;rev3,2,1,0 + 12-bit ID. QG4 ID = $009

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

SPMSC2              equ       $180A,1             ;System power management status and control 2 register

; bit position masks

PDF_                equ       %00010000           ;power down flag
PPDF_               equ       %00001000           ;partial power down flag
PPDACK_             equ       %00000100           ;partial power down acknowledge
PDC_                equ       %00000010           ;power down control
PPDC_               equ       %00000001           ;partial power down control

SPMSC3              equ       $180C,1             ;System power management status and control 3 register

; bit position masks

LVWF_               equ       %10000000           ;low voltage warning flag
LVWACK_             equ       %01000000           ;low voltage warning acknowledge
LVDV_               equ       %00100000           ;low voltage detect voltage select
LVWV_               equ       %00010000           ;low voltage warning voltage select

; **** Debug Module (DBG) ******************************************************

DBGCA               equ       $1810,2             ;DBG comparator register A
DBGCAH              equ       $1810,1             ;DBG comparator register A (high)
DBGCAL              equ       $1811,1             ;DBG comparator register A (low)
DBGCB               equ       $1812,2             ;DBG comparator register B
DBGCBH              equ       $1812,1             ;DBG comparator register B (high)
DBGCBL              equ       $1813,1             ;DBG comparator register B (low)
DBGF                equ       $1814,2             ;DBG FIFO register
DBGFH               equ       $1814,1             ;DBG FIFO register (high)
DBGFL               equ       $1815,1             ;DBG FIFO register (low)
DBGC                equ       $1816,1             ;DBG control register

; bit position masks

DBGEN_              equ       %10000000           ;debug module enable
ARM_                equ       %01000000           ;arm control
TAG_                equ       %00100000           ;tag/force select
BRKEN_              equ       %00010000           ;break enable
RWA_                equ       %00001000           ;R/W compare A value
RWAEN_              equ       %00000100           ;R/W compare A enable
RWB_                equ       %00000010           ;R/W compare B value
RWBEN_              equ       %00000001           ;R/W compare B enable

DBGT                equ       $1817,1             ;DBG trigger register

; bit position masks

TRGSEL_             equ       %10000000           ;trigger on opcode/access
BEGIN_              equ       %01000000           ;begin/end trigger
TRG3_               equ       %00001000           ;trigger mode bits
TRG2_               equ       %00000100           ;         -//-
TRG1_               equ       %00000010           ;         -//-
TRG0_               equ       %00000001           ;         -//-

DBGS                equ       $1818,1             ;DBG status register

; bit position masks

AF_                 equ       %10000000           ;trigger A match flag
BF_                 equ       %01000000           ;trigger B match flag
ARMF_               equ       %00100000           ;arm flag
CNT3_               equ       %00001000           ;count of items in FIFO (high)
CNT2_               equ       %00000100           ;         -//-
CNT1_               equ       %00000010           ;         -//-
CNT0_               equ       %00000001           ;count of items in FIFO (low)

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
PTBPE               equ       $1844,1             ;I/O port B pullup enable controls
PTBPUE              equ       PTBPE,1
PTBSE               equ       $1845,1             ;I/O port B slew rate control register
PTBDS               equ       $1846,1             ;I/O port B drive strength select register

; **** Flash non-volatile register images **************************************

NVFTRIM             equ       $FFAE,1             ;NV FTRIM
NVICSTRM            equ       $FFAF,1             ;NV ICS Trim

NVBACKKEY           equ       $FFB0,8             ;8-byte backdoor comparison key

; comparison key in $FFB0 through $FFB7

; following 2 registers transfered from flash to working regs at reset

NVPROT              equ       $FFBD,1             ;NV flash protection byte
                                                  ;NVPROT transfers to FPROT on reset
NVOPT               equ       $FFBF,1             ;NV flash options byte
                                                  ;NVOPT transfers to FOPT on reset
;NVOPT_SEC00        equ       0                   ;Security State Code, bit 0
;NVOPT_SEC01        equ       1                   ;Security State Code, bit 1
;NVOPT_FNORED       equ       6                   ;Vector Redirection Disable
;NVOPT_KEYEN        equ       7                   ;Backdoor Key Mechanism Enable

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08QG4_           def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1200                ;typical bandgap voltage in mV

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFD0               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

;--- Vectors
                    #temp     VECTORS
Vrti                next      :temp,2             ;RTI (periodic interrupt) vector
                    next      :temp,4
Vacmp               next      :temp,2             ;ACMP - Analog Comparator
Vadc                next      :temp,2             ;A/D conversion vector
Vkeyboard           next      :temp,2             ;keyboard vector
Viic                next      :temp,2             ;IIC vector
Vscitx              next      :temp,2             ;SCI transmit vector
Vscirx              next      :temp,2             ;SCI receive vector
Vscierr             next      :temp,2             ;SCI error vector
Vspi                next      :temp,2             ;SPI vector
Vmtim               next      :temp,2             ;MTIM Overflow
                    next      :temp,8
Vtpmovf             next      :temp,2             ;TPM overflow vector
Vtpmch1             next      :temp,2             ;TPM channel 1 vector
Vtpmch0             next      :temp,2             ;TPM channel 0 vector
                    next      :temp,2
Vlvd                next      :temp,2             ;low voltage detect vector
Virq                next      :temp,2             ;IRQ pin vector
Vswi                next      :temp,2             ;SWI vector
Vreset              next      :temp,2             ;reset vector

;---

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
TRUE_ROM            equ       $F000

          #ifdef BOOTROM
?NVPROT_MASK        def       BOOTROM-1&$FE00>8   ;enable FPROT
          #endif
?NVPROT_MASK        def       TRUE_ROM+FLASH_DATA_SIZE-1&$FE00>8  ;enable FPROT

EEPROM              def       TRUE_ROM            ;start of flash used as EEPROM (main ROM)
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
                    #Error    FLASH_DATA_SIZE is too large
 #endif
#endif

ROM                 def       EEPROM_END+1
ROM_END             def       $FFAD               ;end of all flash (before NV registers and fixed vectors)

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

RAM                 equ       $60                 ;start of 512 byte RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $015F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 4096 byte RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFC0               ;start of optional S/N

#ifndef MHZ¦HZ
KHZ                 def       16000               ;16.0 MHz internal oscillator
#endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

                    #EEPROM   EEPROM

                    #DATA


          #ifndef BOOT¦NO_CODE
                    org       NVPROT              ;NV flash protection byte
                    fcb       ?NVPROT_MASK        ;NVPROT transfers to FPROT on reset

          #ifndef NVOPT_VALUE
                    #Message  Using default NVOPT_VALUE (no vector redirection)
          #endif

NVOPT_VALUE         def       %11000010           ;NVFEOPT transfers to FOPT on reset
                             ; |||||||+----------- SEC00 \ 00:secure  10:unsecure
                             ; ||||||+------------ SEC01 / 01:secure  11:secure
                             ; ||++++------------- Not Used (Always 0)
                             ; |+----------------- FNORED - Vector Redirection Disable (No Redirection)
                             ; +------------------ KEYEN - Backdoor key mechanism enable

                    org       NVOPT               ;NV flash options byte
                    fcb       NVOPT_VALUE         ;NVFEOPT transfers to FOPT on reset
          #endif
;                   org       NVICGTRIM           ;NV ICG Trim Setting
;                   fcb       ??                  ;ICG trim value measured during factory test. User software optionally
;                                                 ;copies to ICGTRM during initialization.
                    #VECTORS  VECTORS
                    #RAM      RAM
                    #XRAM     XRAM
                    #ROM      ROM

                    #MEMORY   ROM       ROM_END
                    #MEMORY   EEPROM    EEPROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
                    #MEMORY   NVOPT
                    #MEMORY   VECTORS   VECTORS|$FF
                    #!MEMORY  CRC_LOCATION CRC_LOCATION+1
