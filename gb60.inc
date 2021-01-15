;*******************************************************************************
;*           MC9S08GB60 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER              *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08GB60 *
                    #Message  **********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  BootROM pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_gb60.exp
  #endif

#endif

_GB_                def       60
_GB60_              def       *

FLL_FACTOR          def       256                 ;dummy to silence generic warning

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*         Jim Sibigtroth - Motorola TSPG (Original version)
;*
;* Description: Register and bit name definitions for 9S08GB60
;*
;* Documentation: 9S08GB60 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08GB60's architecture, FLASH_DATA_SIZE can only take specific
;*    values.  An invalid value will cause an informative assembler error message.
;* 5. ASM8's #MEMORY directive used to define actual Flash space for user code/data
;*
;* Include Files: COMMON.INC
;*
;* Assembler:  ASM8 by Tony G. Papadimitriou <tonyp@acm.org>
;*
;* Revision History: not yet released
;* Rev #     Date      Who     Comments
;* -----  -----------  ------  -------------------------------------------------
;*  1.5    24-Oct-05   T-Pap   Added some aliases
;*  1.4    05-Feb-04   T-Pap   Adapted to ASM8 by <tonyp@acm.org>
;*  1.3    28-Apr-03   J-Sib   SPCO->SPC0, IIAS->IAAS, AN2111 format
;*  1.2    24-Apr-03   J-Sib   correct minor typos in comments
;*  1.1    21-Apr-03   J-Sib   comments and modify for CW 3.0 project
;*  1.0    15-Apr-03   J-Sib   Release version for 9S08GB60
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $182B               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PTAD                equ       $00,1               ;I/O port A data register
PORTA               equ       PTAD,1
PTAPE               equ       $01,1               ;I/O port A pullup enable controls
PTAPUE              equ       PTAPE,1
PTASE               equ       $02,1               ;I/O port A slew rate control register
PTADD               equ       $03,1               ;I/O port A data direction register
DDRA                equ       $03,1               ;I/O port A data direction register
PTBD                equ       $04,1               ;I/O port B data register
PORTB               equ       PTBD,1
PTBPE               equ       $05,1               ;I/O port B pullup enable controls
PTBPUE              equ       PTBPE,1
PTBSE               equ       $06,1               ;I/O port B slew rate control register
PTBDD               equ       $07,1               ;I/O port B data direction register
DDRB                equ       $07,1               ;I/O port B data direction register
PTCD                equ       $08,1               ;I/O port C data register
PORTC               equ       PTCD,1
PTCPE               equ       $09,1               ;I/O port C pullup enable controls
PTCPUE              equ       PTCPE,1
PTCSE               equ       $0A,1               ;I/O port C slew rate control register
PTCDD               equ       $0B,1               ;I/O port C data direction register
DDRC                equ       $0B,1               ;I/O port C data direction register
PTDD                equ       $0C,1               ;I/O port D data register
PORTD               equ       PTDD,1
PTDPE               equ       $0D,1               ;I/O port D pullup enable controls
PTDPUE              equ       PTDPE,1
PTDSE               equ       $0E,1               ;I/O port D slew rate control register
PTDDD               equ       $0F,1               ;I/O port D data direction register
DDRD                equ       $0F,1               ;I/O port D data direction register
PTED                equ       $10,1               ;I/O port E data register
PORTE               equ       $10,1               ;I/O port E data register
PTEPE               equ       $11,1               ;I/O port E pullup enable controls
PTEPUE              equ       PTEPE,1
PTESE               equ       $12,1               ;I/O port E slew rate control register
PTEDD               equ       $13,1               ;I/O port E data direction register
DDRE                equ       $13,1               ;I/O port E data direction register
PTFD                equ       $40,1               ;I/O port F data register
PORTF               equ       $40,1               ;I/O port F data register
PTFPE               equ       $41,1               ;I/O port F pullup enable controls
PTFPUE              equ       PTFPE,1
PTFSE               equ       $42,1               ;I/O port F slew rate control register
PTFDD               equ       $43,1               ;I/O port F data direction register
DDRF                equ       $43,1               ;I/O port F data direction register
PTGD                equ       $44,1               ;I/O port G data register
PORTG               equ       $44,1               ;I/O port G data register
PTGPE               equ       $45,1               ;I/O port G pullup enable controls
PTGPUE              equ       PTGPE,1
PTGSE               equ       $46,1               ;I/O port G slew rate control register
PTGDD               equ       $47,1               ;I/O port G data direction register
DDRG                equ       $47,1               ;I/O port G data direction register

; **** Interrupt Request Module (IRQ) ******************************************

IRQSC               equ       $14,1               ;IRQ status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IRQEDG,5            ;IRQ pin edge sensitivity
                    @bitnum   IRQPE,4             ;IRQ pin enable (PTB5)
                    @bitnum   IRQF,3              ;IRQ flag
                    @bitnum   IRQACK,2            ;acknowledge IRQ flag
                    @bitnum   IRQIE,1             ;IRQ pin interrupt enable
                    @bitnum   IRQMOD,0            ;IRQ mode

; **** Keyboard Interrupt Module (KBI) *****************************************

KBISC               equ       $16                 ;KBI status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   KBEDG7,7            ;rise-hi/fall-low for KBIP7 pin
                    @bitnum   KBEDG6,6            ;rise-hi/fall-low for KBIP6 pin
                    @bitnum   KBEDG5,5            ;rise-hi/fall-low for KBIP5 pin
                    @bitnum   KBEDG4,4            ;rise-hi/fall-low for KBIP4 pin
                    @bitnum   KBF,3               ;KBI flag
                    @bitnum   KBACK,2             ;acknowledge
                    @bitnum   KBIE,1              ;KBI interrupt enable
                    @bitnum   KBIMOD,0            ;KBI mode select

KBIPE               equ       $17                 ;KBI pin enable controls

; **** Serial Communications Interface 1&2 (SCI1 & SCI2) ***********************

SCI1BD              equ       $18,2               ;SCI1 baud rate register
SCI1BDH             equ       $18,1               ;SCI1 baud rate register (high)
SCI1BDL             equ       $19,1               ;SCI1 baud rate register (low byte)
SCI2BD              equ       $20,2               ;SCI2 baud rate register
SCI2BDH             equ       $20,1               ;SCI2 baud rate register (high)
SCI2BDL             equ       $21,1               ;SCI2 baud rate register (low byte)
SCI1C1              equ       $1A,1               ;SCI1 control register 1
SCI2C1              equ       $22,1               ;SCI2 control register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   LOOPS,7             ;loopback mode
                    @bitnum   SCISWAI,6           ;SCI stop in wait
                    @bitnum   RSRC,5              ;receiver source
                    @bitnum   M,4                 ;9/8 bit data
                    @bitnum   WAKE,3              ;wake by addr mark/idle
                    @bitnum   ILT,2               ;idle line type; stop/start
                    @bitnum   PE,1                ;parity enable
                    @bitnum   PT,0                ;parity type

SCI1C2              equ       $1B,1               ;SCI1 control register 2
SCI2C2              equ       $23,1               ;SCI2 control register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TIE,7               ;transmit interrupt enable
                    @bitnum   TCIE,6              ;TC interrupt enable
                    @bitnum   RIE,5               ;receive interrupt enable
                    @bitnum   ILIE,4              ;idle line interrupt enable
                    @bitnum   TE,3                ;transmitter enable
                    @bitnum   RE,2                ;receiver enable
                    @bitnum   RWU,1               ;receiver wakeup engage
                    @bitnum   SBK,0               ;send break

SCI1S1              equ       $1C,1               ;SCI1 status register 1
SCI2S1              equ       $24,1               ;SCI2 status register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TDRE,7              ;Tx data register empty
                    @bitnum   TC,6                ;transmit complete
                    @bitnum   RDRF,5              ;Rx data register full
                    @bitnum   IDLE,4              ;idle line detected
                    @bitnum   OR,3                ;Rx over run
                    @bitnum   NF,2                ;Rx noise flag
                    @bitnum   FE,1                ;Rx framing error
                    @bitnum   PF,0                ;Rx parity failed

SCI1S2              equ       $1D,1               ;SCI1 status register 2
SCI2S2              equ       $25,1               ;SCI2 status register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   RAF,0               ;(bit #0) Rx active flag

SCI1C3              equ       $1E,1               ;SCI1 control register 3
SCI2C3              equ       $26,1               ;SCI2 control register 3

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   R8,7                ;9th Rx bit
                    @bitnum   T8,6                ;9th Tx bit
                    @bitnum   TXDIR,5             ;TxD pin direction?
                    @bitnum   ORIE,3              ;Rx over run int. enable
                    @bitnum   NEIE,2              ;Rx noise flag int. enable
                    @bitnum   FEIE,1              ;Rx framing error int. enable
                    @bitnum   PEIE,0              ;Rx parity error int. enable

SCI1D               equ       $1F,1               ;SCI1 data register (low byte)
SCI2D               equ       $27,1               ;SCI2 data register (low byte)

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

SPRF                @pin      SPIS,7              ;SPI Rx full flag
SPTEF               @pin      SPIS,5              ;SPI Transmit Buffer Empty Flag
MODF                @pin      SPIS,4              ;mode fault flag

SPID                equ       $2D,1               ;SPI data register

; **** Analog-to-Digital Converter Module (ATD) ********************************

ATDC                equ       $50,1               ;A/D control tegister

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   ATDPU,7             ;A/D power up
                    @bitnum   DJM,6               ;justification mode; rt/left
                    @bitnum   RES8,5              ;A/D resolution select
                    @bitnum   SGN,4               ;signed result select
                    @bitnum   PRS3,3              ;prescaler rate select (high)
                    @bitnum   PRS2,2              ;prescaler rate select
                    @bitnum   PRS1,1              ;prescaler rate select
                    @bitnum   PRS0,0              ;prescaler rate select (low)

ATDSC               equ       $51,1               ;A/D status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   CCF,7               ;conversion complete flag
                    @bitnum   ATDIE,6             ;A/D interrupt enable
                    @bitnum   ATDCO,5             ;A/D continuous conversion
                    @bitnum   ATDCH4,4            ;A/D input channel select (high)
                    @bitnum   ATDCH3,3            ;A/D input channel select
                    @bitnum   ATDCH2,2            ;A/D input channel select
                    @bitnum   ATDCH1,1            ;A/D input channel select
                    @bitnum   ATDCH0,0            ;A/D input channel select (low)

ATDPE               equ       $54,1               ;A/D pin enable register
ATDR                equ       $52,2               ;A/D result register
ATDRH               equ       $52,1               ;A/D result register (high)
ATDRL               equ       $53,1               ;A/D result register (low)

; **** Inter-Integrated Circuit Module (IIC) ***********************************

IICA                equ       $58,1               ;IIC address register

IICF                equ       $59,1               ;IIC frequency divider register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   MULT1,7             ;IIC multiply factor (high)
                    @bitnum   MULT0,6             ;IIC multiply factor (low)
                    @bitnum   ICR5,5              ;IIC Divider and Hold bit-5
                    @bitnum   ICR4,4              ;IIC Divider and Hold bit-4
                    @bitnum   ICR3,3              ;IIC Divider and Hold bit-3
                    @bitnum   ICR2,2              ;IIC Divider and Hold bit-2
                    @bitnum   ICR1,1              ;IIC Divider and Hold bit-1
                    @bitnum   ICR0,0              ;IIC Divider and Hold bit-0

IICC                equ       $5A,1               ;IIC control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IICEN,7             ;IIC enable bit
                    @bitnum   IICIE,6             ;IIC interrupt enable bit
                    @bitnum   MST,5               ;IIC master mode select bit
                    @bitnum   TX,4                ;IIC transmit mode select bit
                    @bitnum   TXAK,3              ;IIC transmit acknowledge bit
                    @bitnum   RSTA,2              ;IIC repeat start bit

IICS                equ       $5B,1               ;IIC status register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TCF,7               ;IIC transfer complete flag bit
                    @bitnum   IAAS,6              ;IIC addressed as slave bit
                    @bitnum   BUSY,5              ;IIC bus busy bit
                    @bitnum   ARBL,4              ;IIC arbitration lost bit
                    @bitnum   SRW,2               ;IIC slave read/write bit
                    @bitnum   IICIF,1             ;IIC interrupt flag bit
                    @bitnum   RXAK,0              ;IIC receive acknowledge bit

IICD                equ       $5C,1               ;IIC data I/O register bits 7:0

; **** Timer/PWM Module 1 (TPM1) ***** TPM1 has 3 channels *********************
; **** Timer/PWM Module 2 (TPM2) ***** TPM2 has 5 channels *********************

TPM1SC              equ       $30,1               ;TPM1 status and control register
TPMSC               equ       TPM1SC,1
TPM2SC              equ       $60,1               ;TPM2 status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TOF,7               ;timer overflow flag
                    @bitnum   TOIE,6              ;TOF interrupt enable
                    @bitnum   CPWMS,5             ;centered PWM select
                    @bitnum   CLKSB,4             ;clock select bits
                    @bitnum   CLKSA,3             ;         -//-
                    @bitnum   PS2,2               ;prescaler bits
                    @bitnum   PS1,1               ;         -//-
                    @bitnum   PS0,0               ;         -//-

TPM1CNT             equ       $31,2               ;TPM1 counter
TPM1CNTH            equ       $31,1               ;TPM1 counter (high half)
TPM1CNTL            equ       $32,1               ;TPM1 counter (low half)
TPM1MOD             equ       $33,2               ;TPM1 modulo register
TPM1MODH            equ       $33,1               ;TPM1 modulo register (high half)
TPM1MODL            equ       $34,1               ;TPM1 modulo register(low half)

TPMCNT              equ       TPM1CNTH,2
TPMCNTH             equ       TPM1CNTH,1
TPMCNTL             equ       TPM1CNTL,1
TPMMOD              equ       TPM1MODH,2
TPMMODH             equ       TPM1MODH,1
TPMMODL             equ       TPM1MODL,1

TPM2CNT             equ       $61,2               ;TPM2 counter
TPM2CNTH            equ       $61,1               ;TPM2 counter (high half)
TPM2CNTL            equ       $62,1               ;TPM2 counter (low half)
TPM2MOD             equ       $63,2               ;TPM2 modulo register
TPM2MODH            equ       $63,1               ;TPM2 modulo register (high half)
TPM2MODL            equ       $64,1               ;TPM2 modulo register(low half)

TPM1C0SC            equ       $35,1               ;TPM1 channel 0 status and control
TPMC0SC             equ       TPM1C0SC,1
TPM2C0SC            equ       $65,1               ;TPM2 channel 0 status and control

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   CHxF,7              ;Channel n Flag
                    @bitnum   CHxIE,6             ;Channel n Interrupt Enable
                    @bitnum   MSxB,5              ;Mode Select B for TPM Channel n
                    @bitnum   MSxA,4              ;Mode Select A for TPM Channel n
                    @bitnum   ELSxB,3             ;Edge/Level Select Bits
                    @bitnum   ELSxA,2

TPM1C0V             equ       $36,2               ;TPM1 channel 0 value register
TPM1C0VH            equ       $36,1               ;TPM1 channel 0 value register (high)
TPM1C0VL            equ       $37,1               ;TPM1 channel 0 value register (low)
TPMC0V              equ       TPM1C0VH,2
TPMC0VH             equ       TPM1C0VH,1
TPMC0VL             equ       TPM1C0VL,1

TPM2C0V             equ       $66,2               ;TPM2 channel 0 value register
TPM2C0VH            equ       $66,1               ;TPM2 channel 0 value register (high)
TPM2C0VL            equ       $67,1               ;TPM2 channel 0 value register (low)

TPM1C1SC            equ       $38,1               ;TPM1 channel 1 status and control
TPMC1SC             equ       TPM1C1SC,1
TPM2C1SC            equ       $68,1               ;TPM2 channel 1 status and control

TPM1C1V             equ       $39,2               ;TPM1 channel 1 value register
TPM1C1VH            equ       $39,1               ;TPM1 channel 1 value register (high)
TPM1C1VL            equ       $3A,1               ;TPM1 channel 1 value register (low)
TPMC1V              equ       TPM1C1VH,2
TPMC1VH             equ       TPM1C1VH,1
TPMC1VL             equ       TPM1C1VL,1

TPM2C1V             equ       $69,2               ;TPM2 channel 1 value register
TPM2C1VH            equ       $69,1               ;TPM2 channel 1 value register (high)
TPM2C1VL            equ       $6A,1               ;TPM2 channel 1 value register (low)

TPM1C2SC            equ       $3B,1               ;TPM1 channel 2 status and control
TPMC2SC             equ       TPM1C2SC,1
TPM2C2SC            equ       $6B,1               ;TPM2 channel 2 status and control

TPM1C2V             equ       $3C,2               ;TPM1 channel 2 value register
TPM1C2VH            equ       $3C,1               ;TPM1 channel 2 value register (high)
TPM1C2VL            equ       $3D,1               ;TPM1 channel 2 value register (low)
TPMC2V              equ       TPM1C2VH,2
TPMC2VH             equ       TPM1C2VH,1
TPMC2VL             equ       TPM1C2VL,1

TPM2C2V             equ       $6C,2               ;TPM2 channel 1 value register
TPM2C2VH            equ       $6C,1               ;TPM2 channel 1 value register (high)
TPM2C2VL            equ       $6D,1               ;TPM2 channel 1 value register (low)

TPM2C3SC            equ       $6E,1               ;TPM2 channel 3 status and control
TPM2C3V             equ       $6F,2               ;TPM2 channel 1 value register
TPM2C3VH            equ       $6F,1               ;TPM2 channel 1 value register (high)
TPM2C3VL            equ       $70,1               ;TPM2 channel 1 value register (low)

TPM2C4SC            equ       $71,1               ;TPM2 channel 4 status and control
TPM2C4VH            equ       $72,1               ;TPM2 channel 1 value register (high)
TPM2C4VL            equ       $73,1               ;TPM2 channel 1 value register (low)

; **** Internal Clock Generator Module (ICG) ***********************************

ICGC1               equ       $48,1               ;ICG control register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   RANGE_SEL,6         ;frequency range select
                    @bitnum   REFS,5              ;reference select
                    @bitnum   CLKS1,4             ;clock select bit 1
                    @bitnum   CLKS0,3             ;clock select bit 0
                    @bitnum   OSCSTEN,2           ;oscillator runs in stop

ICGC2               equ       $49,1               ;ICG control register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   LOLRE,7             ;loss of lock reset enable
                    @bitnum   MFD2,6              ;multiplication factor div
                    @bitnum   MFD1,5              ;         -//-
                    @bitnum   MFD0,4              ;         -//-
                    @bitnum   LOCRE,3             ;loss of clock reset enable
                    @bitnum   RFD2,2              ;reference divider
                    @bitnum   RFD1,1              ;         -//-
                    @bitnum   RFD0,0              ;         -//-

ICGS1               equ       $4A,1               ;ICG status register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   CLKST1,7            ;clock mode status 1
                    @bitnum   CLKST0,6            ;clock mode status 0
                    @bitnum   REFST,5             ;reference clock status
                    @bitnum   LOLS,4              ;loss of lock status
                    @bitnum   LOCK,3              ;FLL lock status
                    @bitnum   LOCS,2              ;loss of clock status
                    @bitnum   ERCS,1              ;ext ref clk status
                    @bitnum   ICGIF,0             ;ICG interrupt flag

ICGS2               equ       $4B,1               ;ICG status register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   DCOS,0              ;DCO Clock Stable

ICGFLT              equ       $4C,2               ;ICG filter register (upper 4 bits in bits 3:0)
ICGFLTU             equ       $4C,1               ;ICG filter register (upper 4 bits in bits 3:0)
ICGFLTL             equ       $4D,1               ;ICG filter register (lower 8 bits)

ICGTRM              equ       $4E,1               ;ICG trim register

; **** System Integration Module (SIM) *****************************************

SRS                 equ       $1800,1             ;SIM reset status register
COP                 equ       SRS,1               ;for "STA COP"

; bit position masks

POR_                equ       %10000000           ;power-on reset
PIN_                equ       %01000000           ;external reset pin
COP_                equ       %00100000           ;COP watchdog timed out
ILOP_               equ       %00010000           ;illegal opcode
ICG_                equ       %00000100           ;illegal address access
LVD_                equ       %00000010           ;low-voltage detect

SBDFR               equ       $1801,1             ;system BDM reset register

; bit position masks

BDFR_               equ       %00000001           ;BDM force reset

SOPT                equ       $1802,1             ;SIM options register (write once)

; bit position masks

COPE_               equ       %10000000           ;COP watchdog enable
COPT_               equ       %01000000           ;COP time-out select
STOPE_              equ       %00100000           ;stop enable
BKGDPE_             equ       %00000010           ;BDM pin enable

SDID                equ       $1806,2             ;system device identification 1 register (read-only)
SDIDH               equ       $1806,1             ;system device identification 1 register (read-only)
SDIDL               equ       $1807,1             ;rev3,2,1,0 + 12-bit ID. GB60 ID = $002

; bit position masks within SDIDH

REV3_               equ       %10000000           ;device revision identification (high)
REV2_               equ       %01000000           ;device revision identification
REV1_               equ       %00100000           ;device revision identification
REV0_               equ       %00010000           ;device revision identification (low)

; **** Power Management and Control Module (PMC) *******************************

SRTISC              equ       $1808,1             ;System RTI ststus and control register

; bit position masks

RTIF_               equ       %10000000           ;real-time interrupt flag
RTIACK_             equ       %01000000           ;real-time interrupt acknowledge
RTICLKS_            equ       %00100000           ;real-time interrupt clock select
RTIE_               equ       %00010000           ;real-time interrupt enable
RTIS2_              equ       %00000100           ;real-time interrupt delay select (high)
RTIS1_              equ       %00000010           ;real-time interrupt delay select
RTIS0_              equ       %00000001           ;real-time interrupt delay select (low)

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

LVWF_               equ       %10000000           ;low voltage warning flag
LVWACK_             equ       %01000000           ;low voltage warning acknowledge
LVDV_               equ       %00100000           ;low voltage detect voltage select
LVWV_               equ       %00010000           ;low voltage warning voltage select
PPDF_               equ       %00001000           ;partial power down flag
PPDACK_             equ       %00000100           ;partial power down acknowledge
PDC_                equ       %00000010           ;power down control
PPDC_               equ       %00000001           ;partial power down control

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

FPOPEN_             equ       %10000000           ;open unprotected flash for program/erase
FPDIS_              equ       %01000000           ;flash protection disable
FPS2_               equ       %00100000           ;flash protect size select (high)
FPS1_               equ       %00010000           ;flash protect size select
FPS0_               equ       %00001000           ;flash protect size select (low)

FSTAT               equ       $1825,1             ;Flash status register

; bit position masks

FCBEF_              equ       %10000000           ;flash command buffer empty flag
FCCF_               equ       %01000000           ;flash command complete flag
FPVIOL_             equ       %00100000           ;flash protection violation
FACCERR_            equ       %00010000           ;flash access error
FBLANK_             equ       %00000100           ;flash verified as all blank (erased =$ff) flag

FCMD                equ       $1826,1             ;Flash command register

; command codes for flash programming/erasure to be used with FCMD register

Blank_              equ       $05                 ;Blank Check command
ByteProg_           equ       $20                 ;Byte Program command
BurstProg_          equ       $25                 ;Burst Program command
PageErase_          equ       $40                 ;Page Erase command
MassErase_          equ       $41                 ;Mass Erase command

; **** Flash non-volatile register images **************************************

NVBACKKEY           equ       $FFB0,1             ;8-byte backdoor comparison key
                                                  ;comparison key in $FFB0 through $FFB7

; following 2 registers transfered from flash to working regs at reset

NVPROT              equ       $FFBD,1             ;NV flash protection byte

; NVPROT transfers to FPROT on reset

NVICGTRIM           equ       $FFBE,1             ;NV ICG Trim Setting

; ICG trim value measured during factory test. User software optionally
; copies to ICGTRM during initialization.

NVOPT               equ       $FFBF,1             ;NV flash options byte

; NVFEOPT transfers to FOPT on reset

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08GB60_          def       *                   ;Tells us this INCLUDE has been used

FLASH_PAGE_SIZE     def       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFCC               ;start of fixed vectors
          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

;--- Vectors
                    #temp     VECTORS
Vrti                next      :temp,2             ;RTI (periodic interrupt) vector
Viic                next      :temp,2             ;IIC vector
Vadc                next      :temp,2             ;analog to digital conversion vector
Vkeyboard           next      :temp,2             ;keyboard vector
Vsci2tx             next      :temp,2             ;SCI2 transmit vector
Vsci2rx             next      :temp,2             ;SCI2 receive vector
Vsci2err            next      :temp,2             ;SCI2 error vector
Vsci1tx             next      :temp,2             ;SCI1 transmit vector
Vsci1rx             next      :temp,2             ;SCI1 receive vector
Vsci1err            next      :temp,2             ;SCI1 error vector
Vspi                next      :temp,2             ;SPI vector
Vtpm2ovf            next      :temp,2             ;TPM2 overflow vector
Vtpm2ch4            next      :temp,2             ;TPM2 channel 4 vector
Vtpm2ch3            next      :temp,2             ;TPM2 channel 3 vector
Vtpm2ch2            next      :temp,2             ;TPM2 channel 2 vector
Vtpm2ch1            next      :temp,2             ;TPM2 channel 1 vector
Vtpm2ch0            next      :temp,2             ;TPM2 channel 0 vector
Vtpm1ovf            next      :temp,2             ;TPM1 overflow vector
Vtpm1ch2            next      :temp,2             ;TPM1 channel 2 vector
Vtpm1ch1            next      :temp,2             ;TPM1 channel 1 vector
Vtpm1ch0            next      :temp,2             ;TPM1 channel 0 vector
Vicg                next      :temp,2             ;ICG vector
Vlvd                next      :temp,2             ;low voltage detect vector
Virq                next      :temp,2             ;IRQ pin vector
Vswi                next      :temp,2             ;SWI vector
Vreset              next      :temp,2             ;reset vector
;-------------------------------------------------------------------------------
; Aliases for certain vectors
;-------------------------------------------------------------------------------
Viicx               equ       Viic,2
Vspi1               equ       Vspi,2

Vtpmovf             equ       Vtpm1ovf,2
Vtpmch2             equ       Vtpm1ch2,2
Vtpmch1             equ       Vtpm1ch1,2
Vtpmch0             equ       Vtpm1ch0,2

Vscitx              equ       Vsci1tx,2
Vscirx              equ       Vsci1rx,2
Vscierr             equ       Vsci1err,2
;-------------------------------------------------------------------------------
TRUE_ROM            equ       $1080               ;start of 60K flash (extra ROM)

;-------------------------------------------------------------------------------
?                   macro     Size,NVPROT_Mask
#if FLASH_DATA_SIZE = ~1~
?NVPROT_MASK        equ       %~2~
#endif
                    endm

                    @?            0,10111000
                    @?         1920,10111000
                    @?        28544,10110000
                    @?        44928,10101000
                    @?        53120,10100000
                    @?        57216,10011000
                    @?        59264,10010000
                    @?        60288,10001000
                    @?        60800,10000000
                    @?        61312,11000000
;-------------------------------------------------------------------------------

          #ifdef BOOTROM
?NVPROT_MASK        set       %11000000
          #endif

          #ifndef ?NVPROT_MASK
                    #Error    FLASH_DATA_SIZE ({FLASH_DATA_SIZE}) not 0,1920,28544,44928,53120,57216,59264,60288,60800,61312
          #endif

EEPROM              def       TRUE_ROM
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

          #if EEPROM_END <= HighRegs_End
ROM                 def       HighRegs_End+1
          #endif
ROM                 def       EEPROM_END+1

ROM_END             def       $FFAF               ;end of all flash (before NV register and fixed vectors)

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

RAM                 def       $80                 ;start of 4096 byte RAM
RAM_END             def       $FF                 ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            def       $107F               ;last true RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 4096 byte RAM
#endif

FLASH_START         def       EEPROM_END+1
FLASH_END           def       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       def       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ¦KHZ
HZ                  def       8000000             ;8MHz PEMicro Simulator
;HZ                 def       15552000            ;243KHz (IRG) *64
#endif

BDIV                def       1                   ;actually GB60 does not have a BDIV option

;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

;                   @pin      SPI_SS,PORTE,2      ;SPI /SS pin

                    #EEPROM
                    org       EEPROM

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
                    #VECTORS
                    org       VECTORS

                    #RAM
                    org       RAM

                    #XRAM
                    org       XRAM

                    #ROM
                    org       ROM

                    #MEMORY   ROM       ROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
                    #MEMORY   NVOPT
                    #MEMORY   VECTORS   VECTORS|$FF

          #if EEPROM < HighRegs
                    #MEMORY   EEPROM    HighRegs-1
          #endif

          #if EEPROM_END > HighRegs_End
                    #MEMORY   HighRegs_End+1 EEPROM_END
          #endif

          #ifdef RVECTORS
                    #MEMORY   RVECTORS  RVECTORS|$FF
          #endif

          #ifdef CRC_LOCATION
                    #MEMORY   CRC_LOCATION CRC_LOCATION+1
          #endif
