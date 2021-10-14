;*******************************************************************************
;*            MC9S08QG8 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER              *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  *********************
                    #Message  * Target: MC9S08QG8 *
                    #Message  *********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
          #ifexists tboot_qg8.exp
                    #Uses     tboot_qg8.exp
          #else ifexists tboot.exp
                    #Uses     tboot.exp
          #else
                    #Uses     tboot/tboot_qg8.exp
          #endif

#endif

_QG_                def       8
_QG8_               def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*
;* Description: Register and bit name definitions for 9S08QG8
;*
;* Documentation: 9S08QG8 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08QG8's architecture, FLASH_DATA_SIZE can only be a multiple
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
;*  1.0    04-Feb-06   T-Pap   Release version for 9S08QG8
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

KBEDG7.             equ       7                   ;rise-hi/fall-low for KBIP7 pin
KBEDG6.             equ       6                   ;rise-hi/fall-low for KBIP6 pin
KBEDG5.             equ       5                   ;rise-hi/fall-low for KBIP5 pin
KBEDG4.             equ       4                   ;rise-hi/fall-low for KBIP4 pin
KBF.                equ       3                   ;KBI flag
KBACK.              equ       2                   ;acknowledge
KBIE.               equ       1                   ;KBI interrupt enable
KBIMOD.             equ       0                   ;KBI mode select

; bit position masks

KBEDG7_             equ       %10000000           ;rise-hi/fall-low for KBIP7 pin
KBEDG6_             equ       %01000000           ;rise-hi/fall-low for KBIP6 pin
KBEDG5_             equ       %00100000           ;rise-hi/fall-low for KBIP5 pin
KBEDG4_             equ       %00010000           ;rise-hi/fall-low for KBIP4 pin
KBF_                equ       %00001000           ;KBI flag
KBACK_              equ       %00000100           ;acknowledge
KBIE_               equ       %00000010           ;KBI interrupt enable
KBIMOD_             equ       %00000001           ;KBI mode select

KBIPE               equ       $0D,1               ;KBI pin enable controls
KBIES               equ       $0E,1               ;KBI edge-select register

; **** Interrupt Request Module (IRQ) ******************************************

IRQSC               equ       $0F,1               ;IRQ status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

IRQPDD.             equ       6                   ;IRQ pin pullup disable
IRQPE.              equ       4                   ;IRQ pin enable (PTB5)
IRQF.               equ       3                   ;IRQ flag
IRQACK.             equ       2                   ;acknowledge IRQ flag
IRQIE.              equ       1                   ;IRQ pin interrupt enable
IRQMOD.             equ       0                   ;IRQ mode

; bit position masks

IRQEDG_             equ       %00100000           ;IRQ pin edge sensitivity
IRQPE_              equ       %00010000           ;IRQ pin enable (PTB5)
IRQF_               equ       %00001000           ;IRQ flag
IRQACK_             equ       %00000100           ;acknowledge IRQ flag
IRQIE_              equ       %00000010           ;IRQ pin interrupt enable
IRQMOD_             equ       %00000001           ;IRQ mode

; **** Analog-to-Digital Converter Module (ATD) ********************************

ADCSC1              equ       $10,1               ;A/D Status & Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

COCO.               equ       7                   ;Conversion Complete Flag
AIEN.               equ       6                   ;Interrupt Enable
ADCO.               equ       5                   ;Continuous Conversion Enable

; bit position masks

COCO_               equ       %10000000           ;Conversion Complete Flag
AIEN_               equ       %01000000           ;Interrupt Enable
ADCO_               equ       %00100000           ;Continuous Conversion Enable

ADCSC2              equ       $11,1               ;A/D Status & Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

ADACT.              equ       7                   ;Conversion Active
ADTRG.              equ       6                   ;Conversion Trigger Select
ACFE.               equ       5                   ;Compare Function Enable
ACFGT.              equ       4                   ;Compare Function Greater Than Enable

; bit position masks

ADACT_              equ       %10000000           ;Conversion Active
ADTRG_              equ       %01000000           ;Conversion Trigger Select
ACFE_               equ       %00100000           ;Compare Function Enable
ACFGT_              equ       %00010000           ;Compare Function Greater Than Enable

ADCR                equ       $12,2               ;A/D Result
ADCRH               equ       $12,1               ;A/D Result High
ADCRL               equ       $13,1               ;A/D Result Low
ADCCV               equ       $14,2               ;A/D Compare
ADCCVH              equ       $14,1               ;A/D Compare High
ADCCVL              equ       $15,1               ;A/D Compare Low

ADCCFG              equ       $16,1               ;A/D Configuration Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

ADLPC.              equ       7                   ;Low power configuration
ADLSMP.             equ       4                   ;Long Time Sample Configuration

; bit position masks

ADLPC_              equ       %10000000           ;Low power configuration
ADLSMP_             equ       %00010000           ;Long Time Sample Configuration

APCTL1              equ       $17,1               ;Pin Control 1 Register (Ch. 00-07)

ACMPSC              equ       $1A,1               ;Analog Comparator Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

ACME.               equ       7                   ;Analog Comparator Module Enable
ACBGS.              equ       6                   ;Analog Comparator Bandgap Select
ACF.                equ       5                   ;Analog Comparator Flag
ACIE.               equ       4                   ;Analog Comparator Interrupt Enable
ACO.                equ       3                   ;Analog Comparator Output
ACOPE.              equ       2                   ;Analog Comparator Output Pin Enable

; bit position masks

ACME_               equ       %10000000           ;Analog Comparator Module Enable
ACBGS_              equ       %01000000           ;Analog Comparator Bandgap Select
ACF_                equ       %00100000           ;Analog Comparator Flag
ACIE_               equ       %00010000           ;Analog Comparator Interrupt Enable
ACO_                equ       %00001000           ;Analog Comparator Output
ACOPE_              equ       %00000100           ;Analog Comparator Output Pin Enable

; **** Serial Communications Interface (SCI) ***********************************

SCIBD               equ       $20,2               ;SCI baud rate register
SCIBDH              equ       $20,1               ;SCI baud rate register (high)
SCIBDL              equ       $21,1               ;SCI baud rate register (low byte)
SCIC1               equ       $22,1               ;SCI Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

LOOPS.              equ       7                   ;loopback mode
SCISWAI.            equ       6                   ;SCI stop in wait
RSRC.               equ       5                   ;receiver source
M.                  equ       4                   ;9/8 bit data
WAKE.               equ       3                   ;wake by addr mark/idle
ILT.                equ       2                   ;idle line type; stop/start
PE.                 equ       1                   ;parity enable
PT.                 equ       0                   ;parity type

; bit position masks

LOOPS_              equ       %10000000           ;loopback mode select
SCISWAI_            equ       %01000000           ;SCI stops in wait mode
RSRC_               equ       %00100000           ;receiver source
M_                  equ       %00010000           ;9/8 bit data
WAKE_               equ       %00001000           ;wakeup by addr mark/idle
ILT_                equ       %00000100           ;idle line type; after stop/start
PE_                 equ       %00000010           ;parity enable
PT_                 equ       %00000001           ;parity type even/odd

SCIC2               equ       $23,1               ;SCI Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

TIE.                equ       7                   ;transmit interrupt enable
TCIE.               equ       6                   ;TC interrupt enable
RIE.                equ       5                   ;receive interrupt enable
ILIE.               equ       4                   ;idle line interrupt enable
TE.                 equ       3                   ;transmitter enable
RE.                 equ       2                   ;receiver enable
RWU.                equ       1                   ;receiver wakeup engage
SBK.                equ       0                   ;send break

; bit position masks

TIE_                equ       %10000000           ;transmit interrupt (TDRE) enable
TCIE_               equ       %01000000           ;transmit complete interrupt enable
RIE_                equ       %00100000           ;receive interrupt (RDRF) enable
ILIE_               equ       %00010000           ;idle line interrupt (ILIE) enable
TE_                 equ       %00001000           ;transmitter enable
RE_                 equ       %00000100           ;receiver enable
RWU_                equ       %00000010           ;receiver wakeup engage
SBK_                equ       %00000001           ;send break characters

SCIS1               equ       $24,1               ;SCI Status Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

TDRE.               equ       7                   ;Tx data register empty
TC.                 equ       6                   ;transmit complete
RDRF.               equ       5                   ;Rx data register full
IDLE.               equ       4                   ;idle line detected
OR.                 equ       3                   ;Rx over run
NF.                 equ       2                   ;Rx noise flag
FE.                 equ       1                   ;Rx framing error
PF.                 equ       0                   ;Rx parity failed

; bit position masks

TDRE_               equ       %10000000           ;transmit data register empty
TC_                 equ       %01000000           ;transmit complete
RDRF_               equ       %00100000           ;receive data register full
IDLE_               equ       %00010000           ;idle line detected
OR_                 equ       %00001000           ;receiver over run
NF_                 equ       %00000100           ;receiver noise flag
FE_                 equ       %00000010           ;receiver framing error
PF_                 equ       %00000001           ;received parity failed

SCIS2               equ       $25,1               ;SCI Status Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

BRK13.              equ       2                   ;Break Character Length
RAF.                equ       0                   ;Receiver Active Flag

; bit position masks

BRK13_              equ       %00000100           ;Break Character Length
RAF_                equ       %00000001           ;Receiver Active Flag

SCIC3               equ       $26,1               ;SCI Control Register 3

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

R8.                 equ       7                   ;9th Rx bit
T8.                 equ       6                   ;9th Tx bit
TXDIR.              equ       5                   ;TxD pin direction?
TXINV.              equ       4                   ;Transmit Data Inversion
ORIE.               equ       3                   ;Rx over run int. enable
NEIE.               equ       2                   ;Rx noise flag int. enable
FEIE.               equ       1                   ;Rx framing error int. enable
PEIE.               equ       0                   ;Rx parity error int. enable

; bit position masks

R8_                 equ       %10000000           ;9th receive data bit
T8_                 equ       %01000000           ;9th transmit data bit
TXDIR_              equ       %00100000           ;transmit pin direction?
TXINV_              equ       %00010000           ;Transmit Data Inversion
ORIE_               equ       %00001000           ;receiver over run int. enable
NEIE_               equ       %00000100           ;receiver noise flag int. enable
FEIE_               equ       %00000010           ;receiver framing error int. enable
PEIE_               equ       %00000001           ;received parity error int. enable

SCID                equ       $27,1               ;SCI Data Register (low byte)

; **** Serial Peripheral Interface (SPI) ***************************************

SPIC1               equ       $28,1               ;SPI control register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

SPIE.               equ       7                   ;SPI interrupt enable
SPE.                equ       6                   ;SPI enable
SPTIE.              equ       5                   ;Tx error interrupt enable
MSTR.               equ       4                   ;master/slave
CPOL.               equ       3                   ;clock polarity
CPHA.               equ       2                   ;clock phase
SSOE.               equ       1                   ;SS output enable
LSBFE.              equ       0                   ;LSB-first enable

; bit position masks

SPIE_               equ       %10000000           ;SPI interrupt enable
SPE_                equ       %01000000           ;SPI enable
SPTIE_              equ       %00100000           ;SPI Tx error interrupt enable
MSTR_               equ       %00010000           ;master/slave
CPOL_               equ       %00001000           ;clock polarity
CPHA_               equ       %00000100           ;clock phase
SSOE_               equ       %00000010           ;slave select output enable
LSBFE_              equ       %00000001           ;LSB-first enable

SPIC2               equ       $29,1               ;SPI control register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

MODFEN.             equ       4                   ;mode fault enable
BIDIROE.            equ       3                   ;bi-directional enable
SPISWAI.            equ       1                   ;SPI stops in wait
SPC0.               equ       0                   ;SPI pin 0 control

; bit position masks

MODFEN_             equ       %00010000           ;mode fault enable
BIDIROE_            equ       %00001000           ;bi-directional operation enable
SPISWAI_            equ       %00000010           ;SPI stops in wait mode
SPC0_               equ       %00000001           ;SPI pin 0 control

SPIBR               equ       $2A,1               ;SPI baud rate select

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

SPPR2.              equ       6                   ;SPI baud rate prescale
SPPR1.              equ       5                   ;         -//-
SPPR0.              equ       4                   ;         -//-
SPR2.               equ       2                   ;SPI rate selact
SPR1.               equ       1                   ;         -//-
SPR0.               equ       0                   ;         -//-

; bit position masks

SPPR2_              equ       %01000000           ;SPI baud rate prescale
SPPR1_              equ       %00100000           ;         -//-
SPPR0_              equ       %00010000           ;         -//-
SPR2_               equ       %00000100           ;SPI rate select
SPR1_               equ       %00000010           ;         -//-
SPR0_               equ       %00000001           ;         -//-

SPIS                equ       $2B,1               ;SPI status register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

SPRF.               equ       7                   ;SPI Rx full flag
SPTEF.              equ       5                   ;SPI Transmit Buffer Empty Flag
MODF.               equ       4                   ;mode fault flag

; bit position masks

SPRF_               equ       %10000000           ;SPI receive buffer full flag
SPTEF_              equ       %00100000           ;SPI Transmit Buffer Empty Flag
MODF_               equ       %00010000           ;mode fault flag

SPID                equ       $2D,1               ;SPI data register

; **** Inter-Integrated Circuit Module (IIC) ***********************************

IICA                equ       $30,1               ;IIC address register

IICF                equ       $31,1               ;IIC frequency divider register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

MULT1.              equ       7                   ;IIC multiply factor (high)
MULT0.              equ       6                   ;IIC multiply factor (low)
ICR5.               equ       5                   ;IIC Divider and Hold bit-5
ICR4.               equ       4                   ;IIC Divider and Hold bit-4
ICR3.               equ       3                   ;IIC Divider and Hold bit-3
ICR2.               equ       2                   ;IIC Divider and Hold bit-2
ICR1.               equ       1                   ;IIC Divider and Hold bit-1
ICR0.               equ       0                   ;IIC Divider and Hold bit-0

; bit position masks

MULT1_              equ       %10000000           ;IIC multiply factor (high)
MULT0_              equ       %01000000           ;IIC multiply factor (low)
ICR5_               equ       %00100000           ;IIC Divider and Hold bit-5
ICR4_               equ       %00010000           ;IIC Divider and Hold bit-4
ICR3_               equ       %00001000           ;IIC Divider and Hold bit-3
ICR2_               equ       %00000100           ;IIC Divider and Hold bit-2
ICR1_               equ       %00000010           ;IIC Divider and Hold bit-1
ICR0_               equ       %00000001           ;IIC Divider and Hold bit-0

IICC                equ       $32,1               ;IIC control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

IICEN.              equ       7                   ;(bit #7) IIC enable bit
IICIE.              equ       6                   ;(bit #6) IIC interrupt enable bit
MST.                equ       5                   ;(bit #5) IIC master mode select bit
TX.                 equ       4                   ;(bit #4) IIC transmit mode select bit
TXAK.               equ       3                   ;(bit #3) IIC transmit acknowledge bit
RSTA.               equ       2                   ;(bit #2) IIC repeat start bit

; bit position masks

IICEN_              equ       %10000000           ;IIC enable
IICIE_              equ       %01000000           ;IIC interrupt enable bit
MST_                equ       %00100000           ;IIC master mode select bit
TX_                 equ       %00010000           ;IIC transmit mode select bit
TXAK_               equ       %00001000           ;IIC transmit acknowledge bit
RSTA_               equ       %00000100           ;IIC repeat start bit

IICS                equ       $33,1               ;IIC status register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

TCF.                equ       7                   ;IIC transfer complete flag bit
IAAS.               equ       6                   ;IIC addressed as slave bit
BUSY.               equ       5                   ;IIC bus busy bit
ARBL.               equ       4                   ;IIC arbitration lost bit
SRW.                equ       2                   ;IIC slave read/write bit
IICIF.              equ       1                   ;IIC interrupt flag bit
RXAK.               equ       0                   ;IIC receive acknowledge bit

; bit position masks

TCF_                equ       %10000000           ;IIC transfer complete flag bit
IAAS_               equ       %01000000           ;IIC addressed as slave bit
BUSY_               equ       %00100000           ;IIC bus busy bit
ARBL_               equ       %00010000           ;IIC arbitration lost bit
SRW_                equ       %00000100           ;IIC slave read/write bit
IICIF_              equ       %00000010           ;IIC interrupt flag bit
RXAK_               equ       %00000001           ;IIC receive acknowledge bit

IICD                equ       $34,1               ;IIC data I/O register bits 7:0

; **** Internal Clock Source (ICS) *********************************************

ICSC1               equ       $38,1               ;ICS Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

IREFS.              equ       2                   ;Internal Reference Select
IRCLKEN.            equ       1                   ;Internal Reference Clock Enable
IREFSTEN.           equ       0                   ;Internal Reference Stop Enable

; bit position masks

IREFS_              equ       %00000100           ;Internal Reference Select
IRCLKEN_            equ       %00000010           ;Internal Reference Clock Enable
IREFSTEN_           equ       %00000001           ;Internal Reference Stop Enable

ICSC2               equ       $39,1               ;ICS Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

RANGE_SEL.          equ       5                   ;Frequency Range Select
HGO.                equ       4                   ;High Gain Oscillator Select
LP.                 equ       3                   ;Low Power Select
EREFS.              equ       2                   ;External Reference Select
ERCLKEN.            equ       1                   ;External Reference Enable
EREFSTEN.           equ       0                   ;External Reference Stop Enable

; bit position masks

RANGE_SEL_          equ       %00100000           ;Frequency Range Select
HGO_                equ       %00010000           ;High Gain Oscillator Select
LP_                 equ       %00001000           ;Low Power Select
EREFS_              equ       %00000100           ;External Reference Select
ERCLKEN_            equ       %00000010           ;External Reference Enable
EREFSTEN_           equ       %00000001           ;External Reference Stop Enable

ICSTRM              equ       $3A,1               ;ICS Trim Register

ICSSC               equ       $3B,1               ;ICS Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

OSCINIT.            equ       1                   ;OSC Initialization
FTRIM.              equ       0                   ;ICS Fine Trim

; bit position masks

OSCINIT_            equ       %00000010           ;OSC Initialization
FTRIM_              equ       %00000001           ;ICS Fine Trim

; **** Modulo Timer (MTIM) *****************************************************

MTIMSC              equ       $3C,1               ;MTIM Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

TOF.                equ       7                   ;MTIM Overflow Flag
TOIE.               equ       6                   ;MTIM Overflow Interrupt Enable
TRST.               equ       5                   ;MTIM Counter Reset
TSTP.               equ       4                   ;MTIM Counter Stop

; bit position masks

TOF_                equ       %10000000           ;MTIM Overflow Flag
TOIE_               equ       %01000000           ;MTIM Overflow Interrupt Enable
TRST_               equ       %00100000           ;MTIM Counter Reset
TSTP_               equ       %00010000           ;MTIM Counter Stop

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
TRUE_ROM            equ       $E000

          #ifdef BOOTROM
?NVPROT_MASK        def       BOOTROM-1&$FE00>8   ;enable FPROT
          #endif
?NVPROT_MASK        def       TRUE_ROM+FLASH_DATA_SIZE-1&$FE00>8  ;enable FPROT

EEPROM              def       TRUE_ROM            ;start of flash used as EEPROM (main ROM)
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          def       EEPROM+FLASH_DATA_SIZE-1

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
XRAM_END            equ       $025F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 4096 byte RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFC0               ;start of optional S/N

#ifndef MHZ||HZ
KHZ                 def       16000               ;16.0 MHz internal oscillator
#endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

                    #EEPROM   EEPROM

                    #DATA

          #ifndef BOOT||NO_CODE
                    org       NVPROT              ;NV flash protection byte
                    fcb       ?NVPROT_MASK        ;NVPROT transfers to FPROT on reset

          #ifndef NVOPT_VALUE
                    #Message  Using default NVOPT_VALUE (no vector redirection)
          #endif

          #ifdef DEBUG
NVOPT_VALUE         def       %11000010           ;NVFEOPT transfers to FOPT on reset
          #endif             ; ||||||||
NVOPT_VALUE         def       %11000000           ;NVFEOPT transfers to FOPT on reset
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
