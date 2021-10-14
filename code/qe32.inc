;*******************************************************************************
;*            MC9S08QE32 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08QE32 *
                    #Message  **********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
          #ifexists tboot_qe32.exp
                    #Uses     tboot_qe32.exp
          #else ifexists tboot.exp
                    #Uses     tboot.exp
          #else
                    #Uses     tboot/tboot_qe32.exp
          #endif

#endif

_QE_                def       32
_QE32_              def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*         Jim Sibigtroth - Motorola TSPG (Original version)
;*
;* Description: Register and bit name definitions for 9S08QE32
;*
;* Documentation: 9S08QE32 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08QE32's architecture, FLASH_DATA_SIZE can only take specific
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
;*  1.0    15-Apr-03   J-Sib   Release version for 9S08QE32
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $187F               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PORTA               equ       $00,1               ;I/O port A data register
DDRA                equ       $01,1               ;I/O port A data direction register
PORTB               equ       $02,1               ;I/O port B data register
DDRB                equ       $03,1               ;I/O port B data direction register
PORTC               equ       $04,1               ;I/O port C data register
DDRC                equ       $05,1               ;I/O port C data direction register
PORTD               equ       $06,1               ;I/O port D data register
DDRD                equ       $07,1               ;I/O port D data direction register
PORTE               equ       $08,1               ;I/O port E data register
DDRE                equ       $09,1               ;I/O port E data direction register

KBI1SC              equ       $0C,1               ;KBI status and control register
KBI1PE              equ       $0D,1               ;KBI pin enable controls
KBI1ES              equ       $0E,1               ;KBI edge select

IRQSC               equ       $0F,1               ;IRQ status and control register

ADCSC1              equ       $10,1               ;A/D status & control register 1
ADCSC2              equ       $11,1               ;A/D status & control register 2
ADCR                equ       $12,2               ;A/D data result register
ADCRH               equ       $12,1               ;A/D data result register (high)
ADCRL               equ       $13,1               ;A/D data result register (low)
ADCCV               equ       $14,2               ;A/D compare value register
ADCCVH              equ       $14,1               ;A/D compare value register (high)
ADCCVL              equ       $15,1               ;A/D compare value register (low)
ADCCFG              equ       $16,1               ;A/D configuration register

APCTL1              equ       $17,1
APCTL2              equ       $18,1

ACMP1SC             equ       $1A,1
ACMP2SC             equ       $1B,1

SCI1BD              equ       $20,2               ;SCI1 baud rate register
SCI1BDH             equ       $20,1               ;SCI1 baud rate register (high)
SCI1BDL             equ       $21,1               ;SCI1 baud rate register (low)
SCI1C1              equ       $22,1               ;SCI1 control register 1
SCI1C2              equ       $23,1               ;SCI1 control register 2
SCI1S1              equ       $24,1               ;SCI1 status register 1
SCI1S2              equ       $25,1               ;SCI1 status register 2
SCI1C3              equ       $26,1               ;SCI1 control register 3
SCI1D               equ       $27,1               ;SCI1 data register

SPI1C1              equ       $28,1               ;SPI1 control register 1
SPI1C2              equ       $29,1               ;SPI1 control register 2
SPI1BR              equ       $2A,1               ;SPI1 baud rate select
SPI1S               equ       $2B,1               ;SPI1 status register
SPI1D               equ       $2D,1               ;SPI1 data register

SPIC1               equ       SPI1C1,1
SPIC2               equ       SPI1C2,1
SPIBR               equ       SPI1BR,1
SPIS                equ       SPI1S,1
SPID                equ       SPI1D,1

IIC1A               equ       $30,1               ;IIC1 address register
IIC1F               equ       $31,1               ;IIC1 frequency divider register
IIC1C1              equ       $32,1               ;IIC1 control register 1
IIC1S               equ       $33,1               ;IIC1 status register
IIC1D               equ       $34,1               ;IIC1 data register
IIC1C2              equ       $35,1               ;IIC1 control register 2

IICA                equ       IIC1A,::IIC1A       ;IIC1 address register (alias)
IICF                equ       IIC1F,::IIC1F       ;IIC1 frequency divider register (alias)
IICC                equ       IIC1C1,::IIC1C1     ;IIC1 control register 1 (alias)
IICS                equ       IIC1S,::IIC1S       ;IIC1 status register (alias)
IICD                equ       IIC1D,::IIC1D       ;IIC1 data register (alias)

ICSC1               equ       $38,1
ICSC2               equ       $39,1
ICSTRM              equ       $3A,1
ICSSC               equ       $3B,1

KBI2SC              equ       $3C,1               ;KBI status and control register
KBI2PE              equ       $3D,1               ;KBI pin enable controls
KBI2ES              equ       $3E,1               ;KBI edge select

TPM1SC              equ       $40,1               ;TPM1 status and control register
TPM1CNT             equ       $41,2               ;TPM1 counter
TPM1CNTH            equ       $41,1               ;TPM1 counter (high half)
TPM1CNTL            equ       $42,1               ;TPM1 counter (low half)
TPM1MOD             equ       $43,2               ;TPM1 modulo register
TPM1MODH            equ       $43,1               ;TPM1 modulo register (high half)
TPM1MODL            equ       $44,1               ;TPM1 modulo register(low half)
TPM1C0SC            equ       $45,1               ;TPM1 channel 0 status and control
TPM1C0V             equ       $46,2               ;TPM1 channel 0 value register
TPM1C0VH            equ       $46,1               ;TPM1 channel 0 value register (high)
TPM1C0VL            equ       $47,1               ;TPM1 channel 0 value register (low)
TPM1C1SC            equ       $48,1               ;TPM1 channel 1 status and control
TPM1C1V             equ       $49,2               ;TPM1 channel 1 value register
TPM1C1VH            equ       $49,1               ;TPM1 channel 1 value register (high)
TPM1C1VL            equ       $4A,1               ;TPM1 channel 1 value register (low)
TPM1C2SC            equ       $4B,1               ;TPM1 channel 2 status and control
TPM1C2V             equ       $4C,2               ;TPM1 channel 2 value register
TPM1C2VH            equ       $4C,1               ;TPM1 channel 2 value register (high)
TPM1C2VL            equ       $4D,1               ;TPM1 channel 2 value register (low)

TPMSC               equ       TPM1SC,1
TPMCNT              equ       TPM1CNTH,2
TPMCNTH             equ       TPM1CNTH,1
TPMCNTL             equ       TPM1CNTL,1
TPMMOD              equ       TPM1MODH,2
TPMMODH             equ       TPM1MODH,1
TPMMODL             equ       TPM1MODL,1
TPMC0SC             equ       TPM1C0SC,1
TPMC0V              equ       TPM1C0VH,2
TPMC0VH             equ       TPM1C0VH,1
TPMC0VL             equ       TPM1C0VL,1
TPMC1SC             equ       TPM1C1SC,1
TPMC1V              equ       TPM1C1VH,2
TPMC1VH             equ       TPM1C1VH,1
TPMC1VL             equ       TPM1C1VL,1
TPMC2SC             equ       TPM1C2SC,1
TPMC2V              equ       TPM1C2VH,2
TPMC2VH             equ       TPM1C2VH,1
TPMC2VL             equ       TPM1C2VL,1

TPM2SC              equ       $50,1               ;TPM2 status and control register
TPM2CNT             equ       $51,2               ;TPM2 counter
TPM2CNTH            equ       $51,1               ;TPM2 counter (high half)
TPM2CNTL            equ       $52,1               ;TPM2 counter (low half)
TPM2MOD             equ       $53,2               ;TPM2 modulo register
TPM2MODH            equ       $53,1               ;TPM2 modulo register (high half)
TPM2MODL            equ       $54,1               ;TPM2 modulo register(low half)
TPM2C0SC            equ       $55,1               ;TPM2 channel 0 status and control
TPM2C0V             equ       $56,2               ;TPM2 channel 0 value register
TPM2C0VH            equ       $56,1               ;TPM2 channel 0 value register (high)
TPM2C0VL            equ       $57,1               ;TPM2 channel 0 value register (low)
TPM2C1SC            equ       $58,1               ;TPM2 channel 1 status and control
TPM2C1V             equ       $59,2               ;TPM2 channel 1 value register
TPM2C1VH            equ       $59,1               ;TPM2 channel 1 value register (high)
TPM2C1VL            equ       $5A,1               ;TPM2 channel 1 value register (low)
TPM2C2SC            equ       $5B,1               ;TPM2 channel 2 status and control
TPM2C2V             equ       $5C,2               ;TPM2 channel 2 value register
TPM2C2VH            equ       $5C,1               ;TPM2 channel 2 value register (high)
TPM2C2VL            equ       $5D,1               ;TPM2 channel 2 value register (low)

TPM3SC              equ       $60,1               ;TPM3 status and control register
TPM3CNT             equ       $61,2               ;TPM3 counter
TPM3CNTH            equ       $61,1               ;TPM3 counter (high half)
TPM3CNTL            equ       $62,1               ;TPM3 counter (low half)
TPM3MOD             equ       $63,2               ;TPM3 modulo register
TPM3MODH            equ       $63,1               ;TPM3 modulo register (high half)
TPM3MODL            equ       $64,1               ;TPM3 modulo register(low half)
TPM3C0SC            equ       $65,1               ;TPM3 channel 0 status and control
TPM3C0V             equ       $66,2               ;TPM3 channel 0 value register
TPM3C0VH            equ       $66,1               ;TPM3 channel 0 value register (high)
TPM3C0VL            equ       $67,1               ;TPM3 channel 0 value register (low)
TPM3C1SC            equ       $68,1               ;TPM3 channel 1 status and control
TPM3C1V             equ       $69,2               ;TPM3 channel 1 value register
TPM3C1VH            equ       $69,1               ;TPM3 channel 1 value register (high)
TPM3C1VL            equ       $6A,1               ;TPM3 channel 1 value register (low)
TPM3C2SC            equ       $6B,1               ;TPM3 channel 2 status and control
TPM3C2V             equ       $6C,2               ;TPM3 channel 2 value register
TPM3C2VH            equ       $6C,1               ;TPM3 channel 2 value register (high)
TPM3C2VL            equ       $6D,1               ;TPM3 channel 2 value register (low)
TPM3C3SC            equ       $6E,1               ;TPM3 channel 3 status and control
TPM3C3V             equ       $6F,2               ;TPM3 channel 3 value register
TPM3C3VH            equ       $6F,1               ;TPM3 channel 3 value register (high)
TPM3C3VL            equ       $70,1               ;TPM3 channel 3 value register (low)
TPM3C4SC            equ       $71,1               ;TPM3 channel 4 status and control
TPM3C4V             equ       $72,2               ;TPM3 channel 4 value register
TPM3C4VH            equ       $72,1               ;TPM3 channel 4 value register (high)
TPM3C4VL            equ       $73,1               ;TPM3 channel 4 value register (low)
TPM3C5SC            equ       $74,1               ;TPM3 channel 5 status and control
TPM3C5V             equ       $75,2               ;TPM3 channel 5 value register
TPM3C5VH            equ       $75,1               ;TPM3 channel 5 value register (high)
TPM3C5VL            equ       $76,1               ;TPM3 channel 5 value register (low)

SRS                 equ       $1800,1             ;SIM reset status register
COP                 equ       SRS,1               ;for "STA COP"

SBDFR               equ       $1801,1             ;system BDM reset register
SOPT1               equ       $1802,1             ;SIM options register 1
SOPT                equ       SOPT1,1
SOPT2               equ       $1803,1             ;SIM options register 2
SDID                equ       $1806,2             ;system device identification 1 register (read-only)
SDIDH               equ       $1806,1             ;system device identification 1 register (read-only)
SDIDL               equ       $1807,1             ;rev3,2,1,0 + 12-bit ID. QE32 ID = $1F

SPMSC1              equ       $1808,1             ;System power management status and control 1 register
SPMSC2              equ       $1809,1             ;System power management status and control 2 register
SPMSC3              equ       $180B,1             ;System power management status and control 3 register

SCGC1               equ       $180E,1
SCGC2               equ       $180F,1

DBGCA               equ       $1810,2             ;DBG comparator register A
DBGCAH              equ       $1810,1             ;DBG comparator register A (high)
DBGCAL              equ       $1811,1             ;DBG comparator register A (low)
DBGCB               equ       $1812,2             ;DBG comparator register B
DBGCBH              equ       $1812,1             ;DBG comparator register B (high)
DBGCBL              equ       $1813,1             ;DBG comparator register B (low)
DBGCC               equ       $1814,2             ;DBG comparator register C
DBGCCH              equ       $1814,1             ;DBG comparator register C (high)
DBGCCL              equ       $1815,1             ;DBG comparator register C (low)
DBGF                equ       $1816,2             ;DBG FIFO register
DBGFH               equ       $1816,1             ;DBG FIFO register (high)
DBGFL               equ       $1817,1             ;DBG FIFO register (low)
DBGCAX              equ       $1818,1
DBGCBX              equ       $1819,1
DBGCCX              equ       $181A,1
DBGFX               equ       $181B,1
DBGC                equ       $181C,1
DBGT                equ       $181D,1             ;DBG trigger register
DBGS                equ       $181E,1             ;DBG status register
DBGCNT              equ       $181F,1

FCDIV               equ       $1820,1             ;Flash clock divider register
FOPT                equ       $1821,1             ;Flash options register
FCNFG               equ       $1823,1             ;Flash configuration register
FPROT               equ       $1824,1             ;Flash protection register
FSTAT               equ       $1825,1             ;Flash status register
FCMD                equ       $1826,1             ;Flash command register

RTCSC               equ       $1830,1
RTCCNT              equ       $1831,1
RTCMOD              equ       $1832,1

PTAPUE              equ       $1840,1             ;I/O port A pullup enable controls
PTAPE               equ       PTAPUE,1            ;-//- (alias)
PTASE               equ       $1841,1             ;I/O port A slew rate control register
PTADS               equ       $1842,1             ;I/O port A drive strength

PTBPUE              equ       $1844,1             ;I/O port B pullup enable controls
PTBPE               equ       PTBPUE,1            ;-//- (alias)
PTBSE               equ       $1845,1             ;I/O port B slew rate control register
PTBDS               equ       $1846,1             ;I/O port B drive strength

PTCPUE              equ       $1848,1             ;I/O port C pullup enable controls
PTCSE               equ       $1849,1             ;I/O port C slew rate control register
PTCDS               equ       $184A,1             ;I/O port C drive strength

PTDPUE              equ       $184C,1             ;I/O port D pullup enable controls
PTDSE               equ       $184D,1             ;I/O port D slew rate control register
PTDDS               equ       $184E,1             ;I/O port D drive strength

PTEPUE              equ       $1850,1             ;I/O port E pullup enable controls
PTESE               equ       $1851,1             ;I/O port E slew rate control register
PTEDS               equ       $1852,1             ;I/O port E drive strength

SCI2BD              equ       $1870,2             ;SCI2 baud rate register
SCI2BDH             equ       $1870,1             ;SCI2 baud rate register (high)
SCI2BDL             equ       $1871,1             ;SCI2 baud rate register (low)
SCI2C1              equ       $1872,1             ;SCI2 control register 1
SCI2C2              equ       $1873,1             ;SCI2 control register 2
SCI2S1              equ       $1874,1             ;SCI2 status register 1
SCI2S2              equ       $1875,1             ;SCI2 status register 2
SCI2C3              equ       $1876,1             ;SCI2 control register 3
SCI2D               equ       $1877,1             ;SCI2 data register

;*******************************************************************************
; Bit numbers for use in BCLR, BSET, BRCLR, and BRSET
;*******************************************************************************

;-------------------------------------------------------------------------------
; Flash
;-------------------------------------------------------------------------------

; Flash Clock Divider Register (FCDIV)

                    @bitnum   FDIVLD,7            ;Clock Divider Load Control
                    @bitnum   PRDIV8,6            ;Enable Prescaler by 8

; Flash Options Register (FOPT and NVOPT)

                    @bitnum   KEYEN1,7            ;Backdoor Key Security Enable
                    @bitnum   KEYEN0,6
                    @bitnum   SEC1,1              ;Flash Security Bits
                    @bitnum   SEC0,0

; Flash Configuration Register (FCNFG)

                    @bitnum   KEYACC,5            ;Enable Security Key Writing

; Flash Protection Register (FPROT and NVPROT)

                    @bitnum   FPOPEN,0            ;Flash Protection Open

; Flash Status Register (FSTAT)

                    @bitnum   FCBEF,7             ;Flash Command Buffer Empty Flag
                    @bitnum   FCCF,6              ;Flash Command Complete Interrupt Flag
                    @bitnum   FPVIOL,5            ;Flash Protection Violation Flag
                    @bitnum   FACCERR,4           ;Flash Access Error Flag
                    @bitnum   FBLANK,2            ;Flash Flag Indicating the Erase Verify Operation Status

;-------------------------------------------------------------------------------
; IRQ Status and Control (IRQSC)
;-------------------------------------------------------------------------------

                    @bitnum   IRQPDD,6            ;IRQ Pulldown Disable
                    @bitnum   IRQEDG,5            ;IRQ Edge Select
                    @bitnum   IRQPE,4             ;IRQ Pin Enable
                    @bitnum   IRQF,3              ;IRQ Flag
                    @bitnum   IRQACK,2            ;IRQ Acknowledge
                    @bitnum   IRQIE,1             ;IRQ Interrupt Enable
                    @bitnum   IRQMOD,0            ;IRQ Detection Mode

;-------------------------------------------------------------------------------
; System Reset Status Register (SRS)
;-------------------------------------------------------------------------------

                    @bitnum   POR,7               ;Power-On Reset
                    @bitnum   PIN,6               ;External Reset Pin
                    @bitnum   COP,5               ;COP Watchdog
                    @bitnum   ILOP,4              ;Illegal Opcode
                    @bitnum   LVD,1               ;Low Voltage Detect

;-------------------------------------------------------------------------------
; System Options Register 1 (SOPT1)
;-------------------------------------------------------------------------------

                    @bitnum   COPE,7              ;COP Watchdog Enable
                    @bitnum   COPT,6              ;COP Watchdog Timeout
                    @bitnum   STOPE,5             ;Stop Mode Enable
                    @bitnum   BKGDPE,1            ;Background Debug Mode Pin Enable
                    @bitnum   RSTPE,0             ;/RESET Pin Enable

;-------------------------------------------------------------------------------
; System Options Register 2 (SOPT2)
;-------------------------------------------------------------------------------

                    @bitnum   COPCLKS,7           ;COP Watchdog Clock Select
                    @bitnum   SPIFE,4             ;SPI Ports Input Filter Enable
                    @bitnum   SPI1PS,3            ;SPI1 Pin Select
                    @bitnum   ACIC2,2             ;Analog Comparator 2 to Input Capture Enable
                    @bitnum   IIC1PS,1            ;IIC1 Pin Select
                    @bitnum   ACIC1,0             ;Analog Comparator 1 to Input Capture Enable

;-------------------------------------------------------------------------------
; System Power Management Status and Control 1 Register (SPMSC1)
;-------------------------------------------------------------------------------

                    @bitnum   LVDF,7              ;Low-Voltage Detect Flag
                    @bitnum   LVDACK,6            ;Low-Voltage Detect Ackowledge
                    @bitnum   LVDIE,5             ;Low-Voltage Detect Interrupt Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detect Reset Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detect Stop Enable
                    @bitnum   LVDE,2              ;Low-Voltage Detect Enable
                    @bitnum   BGBE,0              ;Bandgap Buffer Enable

;-------------------------------------------------------------------------------
; System Power Management Status and Control 2 Register (SPMSC2)
;-------------------------------------------------------------------------------

                    @bitnum   LPR,7               ;Low Power Regulator Control
                    @bitnum   LPRS,6              ;Low Power Regulator Status
                    @bitnum   LPWUI,5             ;Low Power Wake Up on Interrupt
                    @bitnum   PPDF,3              ;Partial Power Down Flag
                    @bitnum   PPDACK,2            ;Partial Power Down Acknowledge
                    @bitnum   PPDE,1              ;Partial Power Down Enable
                    @bitnum   PPDC,0              ;Partial Power Down Control

;-------------------------------------------------------------------------------
; System Power Management Status and Control 3 Register (SPMSC3)
;-------------------------------------------------------------------------------

                    @bitnum   LVWF,7              ;Low-Voltage Warning Flag
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVDV,5              ;Low-Voltage Detect Voltage Select
                    @bitnum   LVWV,4              ;Low-Voltage Warning Voltage Select
                    @bitnum   LVWIE,3             ;Low-Voltage Warning Interrupt Enable

;-------------------------------------------------------------------------------
; System Clock Gating Control 1 Register (SCGC1)
;-------------------------------------------------------------------------------

                    @bitnum   TPM3,7              ;TPM3 Clock Gate Control
                    @bitnum   TPM2,6              ;PM2 Clock Gate Control
                    @bitnum   TPM1,5              ;TPM1 Clock Gate Control
                    @bitnum   ADC,4               ;ADC Clock Gate Control
                    @bitnum   IIC1,2              ;IIC1 Clock Gate Control
                    @bitnum   SCI2,1              ;SCI2 Clock Gate Control
                    @bitnum   SCI1,0              ;SCI1 Clock Gate Control

;-------------------------------------------------------------------------------
; System Clock Gating Control 2 Register (SCGC2)
;-------------------------------------------------------------------------------

                    @bitnum   DBG,7               ;DBG Clock Gate Control
                    @bitnum   FLS,6               ;Flash Register Clock Gate Control
                    @bitnum   IRQ,5               ;IRQ Clock Gate Control
                    @bitnum   KBI,4               ;KBI Clock Gate Control
                    @bitnum   ACMP,3              ;ACMP Clock Gate Control
                    @bitnum   RTC,2               ;RTC Clock Gate Control
                    @bitnum   SPI1,0              ;SPI1 Clock Gate Control

;-------------------------------------------------------------------------------
; KBI Interrupt Status and Control Register (KBIxSC)
;-------------------------------------------------------------------------------

                    @bitnum   KBF,3               ;KBI Interrupt Flag
                    @bitnum   KBACK,2             ;KBI Interrupt Acknowledge
                    @bitnum   KBIE,1              ;KBI Interrupt Enable
                    @bitnum   KBIMOD,0            ;KBI Detection Mode

;-------------------------------------------------------------------------------
; ACMPx Status and Control Register (ACMPxSC)
;-------------------------------------------------------------------------------

                    @bitnum   ACME,7              ;Analog Comparator Module Enable
                    @bitnum   ACBGS,6             ;Analog Comparator Bandgap Select
                    @bitnum   ACF,5               ;Analog Comparator Flag
                    @bitnum   ACIE,4              ;Analog Comparator Interrupt Enable
                    @bitnum   ACO,3               ;Analog Comparator Output
                    @bitnum   ACOPE,2             ;Analog Comparator Output Pin Enable
                    @bitnum   ACMOD1,1            ;Analog Comparator Mode
                    @bitnum   ACMOD0,0

;-------------------------------------------------------------------------------
; Status and Control Register 1 (ADCSC1)
;-------------------------------------------------------------------------------

                    @bitnum   COCO,7              ;Conversion Complete Flag
                    @bitnum   AIEN,6              ;Interrupt Enable
                    @bitnum   ADCO,5              ;Continuous Conversion Enable

;-------------------------------------------------------------------------------
; Status and Control Register 2 (ADCSC2)
;-------------------------------------------------------------------------------

                    @bitnum   ADACT,7             ;Conversion Active
                    @bitnum   ADTRG,6             ;Conversion Trigger Select
                    @bitnum   ACFE,5              ;Compare Function Enable
                    @bitnum   ACFGT,4             ;Compare Function Greater Than Enable

;-------------------------------------------------------------------------------
; Configuration Register (ADCCFG)
;-------------------------------------------------------------------------------

                    @bitnum   ADLPC,7             ;Low Power Configuration
                    @bitnum   ADIV1,6             ;Clock Divide Select
                    @bitnum   ADIV0,5
                    @bitnum   ADLSMP,4            ;Long Sample Time Configuration
                    @bitnum   MODE1,3             ;Conversion Mode Select
                    @bitnum   MODE0,2
                    @bitnum   ADICLK1,1           ;Input Clock Select
                    @bitnum   ADICLK0,0

;-------------------------------------------------------------------------------
; Internal Clock Source (ICS)
;-------------------------------------------------------------------------------

; ICSC1

                    @bitnum   CLKS1,7             ;Clock Source Select
                    @bitnum   CLKS0,6
                    @bitnum   RDIV2,5             ;Reference Divider
                    @bitnum   RDIV1,4
                    @bitnum   RDIV0,3
                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable

; ICSC2

                    @bitnum   BDIV1,7             ;Bus Frequency Divider
                    @bitnum   BDIV0,6
                    @bitnum   RANGE_SEL,5         ;Frequency Range Select
                    @bitnum   HGO,4               ;High Gain Oscillator Select
                    @bitnum   LP,3                ;Low Power Select
                    @bitnum   EREFS,2             ;External Reference Select
                    @bitnum   ERCLKEN,1           ;External Reference Enable
                    @bitnum   EREFSTEN,0          ;External Reference Stop Enable

; ICSSC

                    @bitnum   DRST1,7             ;DCO Range Status
                    @bitnum   DRST0,6
                    @bitnum   DRS1,7              ;DCO Range Select
                    @bitnum   DRS0,6
                    @bitnum   DMX32,5             ;DCO Maximum frequency with 32.768KHz reference
                    @bitnum   IREFST,4            ;Internal Reference Status
                    @bitnum   CLKST1,3            ;Clock Mode Status
                    @bitnum   CLKST0,2
                    @bitnum   OSCINIT,1           ;OSC Initialization
                    @bitnum   FTRIM,0             ;ICS Fine Trim

;-------------------------------------------------------------------------------
; Inter-Integrated Circuit (S08IICV2)
;-------------------------------------------------------------------------------

; IIC Control Register (IICxC1)

                    @bitnum   IICEN,7             ;IIC Enable
                    @bitnum   IICIE,6             ;IIC Interrupt Enable
                    @bitnum   MST,5               ;Master Mode Select
                    @bitnum   TX,4                ;Transmit Mode Select
                    @bitnum   TXAK,3              ;Transmit Acknowledge Enable
                    @bitnum   RSTA,2              ;Repeat START

; IIC Status Register (IICxS)

                    @bitnum   TCF,7               ;Transfer Complete Flag
                    @bitnum   IIAS,6              ;Addressed as slave
                    @bitnum   BUSY,5              ;Bus Busy
                    @bitnum   ARBL,4              ;Arbitration Lost
                    @bitnum   SRW,2               ;Slave Read/Write
                    @bitnum   IICIF,1             ;IIC Interrupt Flag
                    @bitnum   RXAK,0              ;Receive Acknowledge

; IIC Control Register 2 (IICxC2)

                    @bitnum   GCAEN,7             ;General Call Address Enable
                    @bitnum   ADEXT,6             ;Address Extension
                    @bitnum   AD10,2              ;Slave Address (bits 10..8)
                    @bitnum   AD9,1
                    @bitnum   AD8,0

;-------------------------------------------------------------------------------
; Real-Time Counter (S08RTCV1)
;-------------------------------------------------------------------------------

; RTC Status and Control Register (RTCSC)

                    @bitnum   RTIF,7              ;Real-Time Interrupt Flag
                    @bitnum   RTCLKS1,6           ;Real-Time Clock Source Select
                    @bitnum   RTCLKS0,5
                    @bitnum   RTIE,4              ;Real-Time Interrupt Enable
                    @bitnum   RTCPS3,3            ;Real-Time Clock Prescaler Select
                    @bitnum   RTCPS2,2
                    @bitnum   RTCPS1,1
                    @bitnum   RTCPS0,0

;-------------------------------------------------------------------------------
; Serial Communications Interface (S08SCIV4)
;-------------------------------------------------------------------------------

; SCI Baud Rate Registers (SCIxBDH, SCIxBDL)

                    @bitnum   LBKDIE,7            ;LIN Break Detect Interrupt Enable (for LBKDIF)
                    @bitnum   RXEDGIE,6           ;RxD Input Active Edge Interrupt Enable (for RXEDGIF)

; SCI Control Register 1 (SCIxC1)

                    @bitnum   LOOPS,7             ;Loop Mode Select
                    @bitnum   SCISWAI,6           ;SCI Stops in Wait Mode
                    @bitnum   RSRC,5              ;Receiver Source Select
                    @bitnum   M,4                 ;9-Bit Mode Select
                    @bitnum   WAKE,3              ;Receiver Wakeup Method Select
                    @bitnum   ILT,2               ;Idle Line Type Select
                    @bitnum   PE,1                ;Parity Enable
                    @bitnum   PT,0                ;Parity Type

; SCI Control Register 2 (SCIxC2)

                    @bitnum   TIE,7               ;Transmit Interrupt Enable (for TDRE)
                    @bitnum   TCIE,6              ;Transmission Complete Interrupt Enable (for TC)
                    @bitnum   RIE,5               ;Receiver Interrupt Enable (for RDRF)
                    @bitnum   ILIE,4              ;Idle Line Interrupt Enable (for IDLE)
                    @bitnum   TE,3                ;Transmitter Enable
                    @bitnum   RE,2                ;Receiver Enable
                    @bitnum   RWU,1               ;Receiver Wakeup Control
                    @bitnum   SBK,0               ;Send Break

; SCI Status Register 1 (SCIxS1)

                    @bitnum   TDRE,7              ;Transmit Data Register Empty
                    @bitnum   TC,6                ;Transmission Complete Flag
                    @bitnum   RDRF,5              ;Receive Data Register Full Flag
                    @bitnum   IDLE,4              ;Idle Line Flag
                    @bitnum   OR,3                ;Receiver Overrun Flag
                    @bitnum   NF,2                ;Noise Flag
                    @bitnum   FE,1                ;Framing Error Flag
                    @bitnum   PF,0                ;Parity Errot Flag

; SCI Status Register 2 (SCIxS2)

                    @bitnum   LBKDIF,7            ;LIN Break Detect Interrupt Flag
                    @bitnum   RXEDGIF,6           ;RxD Pin Active Edge Interrupt Flag
                    @bitnum   RXINV,4             ;Receive Data Inversion
                    @bitnum   RWUID,3             ;Receive Wakeup Idle Detect
                    @bitnum   BRK13,2             ;Break Character Generation Length
                    @bitnum   LBKDE,1             ;LIN Break Detection Enable
                    @bitnum   RAF,0               ;Receiver Active Flag

; SCI Control Register 3 (SCIxC3)

                    @bitnum   R8,7                ;Ninth Data Bit for Receiver
                    @bitnum   T8,6                ;Ninth Data Bit for Transmitter
                    @bitnum   TXDIR,5             ;TxD Pin Direction in Single-Wire Mode
                    @bitnum   TXINV,4             ;Transmit Data Inversion
                    @bitnum   ORIE,3              ;Overrun Interrupt Enable
                    @bitnum   NEIE,2              ;Noise Error Interrupt Enable
                    @bitnum   FEIE,1              ;Framing Error Interrupt Enable
                    @bitnum   PEIE,0              ;Parity Error Interrupt Enable

;-------------------------------------------------------------------------------
; Serial Peripheral Interface (S08SPIV3)
;-------------------------------------------------------------------------------

; SPI Control Register 1 (SPIxC1)

                    @bitnum   SPIE,7              ;SPI Interrupt Enable (for SPRF and MODF)
                    @bitnum   SPE,6               ;SPI System Enable
                    @bitnum   SPTIE,5             ;SPI Transmit Interrupt Enable
                    @bitnum   MSTR,4              ;Master/Slave Mode Select
                    @bitnum   CPOL,3              ;Clock Polarity
                    @bitnum   CPHA,2              ;Clock Phase
                    @bitnum   SSOE,1              ;Slave Select Output Enable
                    @bitnum   LSBFE,0             ;LSB First (Shifter Direction)

; SPI Control Register 2 (SPIxC2)

                    @bitnum   MODFEN,4            ;Master Mode-Fault Function Enable
                    @bitnum   BIDIROE,3           ;Bidirectional mode Output Enable
                    @bitnum   SPISWAI,1           ;SPI Stop in Wait Mode
                    @bitnum   SPC0,0              ;SPI Pin Control 0

; SPI Status Register (SPIxS)

                    @bitnum   SPRF,7              ;SPI Read Buffer Full Flag
                    @bitnum   SPTEF,5             ;SPI Transmit Buffer Empty Flag
                    @bitnum   MODF,4              ;Master Mode Fault Flag

;-------------------------------------------------------------------------------
; Timer/Pulse-Width Modulator (S08TPMV3)
;-------------------------------------------------------------------------------

; TPM Status and Control Register (TPMxSC)

                    @bitnum   TOF,7               ;Timer Overflow Flag
                    @bitnum   TOIE,6              ;Timer Overflow Interrupt Enable
                    @bitnum   CPWMS,5             ;Center-aligned PWM Select
                    @bitnum   CLKSB,4             ;Clock Source Select B
                    @bitnum   CLKSA,3             ;Clock Source Select A
                    @bitnum   PS2,2               ;Prescale factor Select
                    @bitnum   PS1,1
                    @bitnum   PS0,0

; TPM Channel n Status and Control Register (TPMxCnSC)

                    @bitnum   CHxF,7              ;Channel n Flag
                    @bitnum   CHxIE,6             ;Channel n Interrupt Enable
                    @bitnum   MSxB,5              ;Mode Select B for TPM Channel n
                    @bitnum   MSxA,4              ;Mode Select A for TPM Channel n
                    @bitnum   ELSxB,3             ;Edge/Level Select Bits
                    @bitnum   ELSxA,2

;-------------------------------------------------------------------------------
; Background Debug Controller (BDC)
;-------------------------------------------------------------------------------

; BDC Status and Control Register (BDCSCR)

                    @bitnum   ENBDM,7             ;Enable BDM (Permit Active Background Mode)
                    @bitnum   BDMACT,6            ;Background Mode Active Status
                    @bitnum   BKPTEN,5            ;BDC Breakpoint Enable
                    @bitnum   FTS,4               ;Force/Tag Select
                    @bitnum   CLKSW,3             ;Select Source for BDC Communications Clock
                    @bitnum   WS,2                ;Wait or Stop Status
                    @bitnum   WSF,1               ;Wait or Stop Failure Status
                    @bitnum   DVF,0               ;Data Valid Failure Status

; System Background Debug Force Reset Register (SBDFR)

                    @bitnum   BDFR,0              ;Background Debug Force Reset

; Debug Comparator A Extension Register (DBGCAX)

                    @bitnum   RWAEN,7             ;Read/Write Comparator A Enable Bit
                    @bitnum   RWA,6               ;Read/Write Comparator A Value Bit
                    @bitnum   PAGSEL,5            ;Comparator A Page Select Bit
                    @bitnum   BIT16,0             ;Comparator A Extended Address Bit-16 Compare Bit

; Debug Comparator B Extension Register (DBGCBX)

                    @bitnum   RWBEN,7             ;Read/Write Comparator B Enable Bit
                    @bitnum   RWB,6               ;Read/Write Comparator B Value Bit

; Debug Comparator C Extension Register (DBGCCX)

                    @bitnum   RWCEN,7             ;Read/Write Comparator C Enable Bit
                    @bitnum   RWC,6               ;Read/Write Comparator C Value Bit

; Debug Control Register (DBGC)

                    @bitnum   DBGEN,7             ;DBG Module Enable Bit
                    @bitnum   ARM,6               ;Arm bit
                    @bitnum   TAG,5               ;Tar or Force Bit
                    @bitnum   BRKEN,4             ;Break Enable Bit
                    @bitnum   LOOP1,0             ;Select LOOP1 Capture Mode

; Debug Trigger Register (DBGT)

                    @bitnum   TRGSEL,7            ;Trigger Selection Bit
                    @bitnum   BEGIN,6             ;Begin/End Trigger Bit
                    @bitnum   TRG3,3              ;Trigger Mode Bits
                    @bitnum   TRG2,2
                    @bitnum   TRG1,1
                    @bitnum   TRG0,0

; Debug Status Register (DBGS)

                    @bitnum   AF,7                ;Trigger A Match Bit
                    @bitnum   BF,6                ;Trigger B Match Bit
                    @bitnum   CF,5                ;Trigger C Match Bit
                    @bitnum   ARMF,0              ;Arm Flag Bit

;*******************************************************************************
; Command codes for flash programming/erasure to be used with FCMD register
;*******************************************************************************

Blank_              equ       $05                 ;Blank Check command
ByteProg_           equ       $20                 ;Byte Program command
BurstProg_          equ       $25                 ;Burst Program command
PageErase_          equ       $40                 ;Page Erase command
MassErase_          equ       $41                 ;Mass Erase command

; **** Flash non-volatile register images **************************************

NVFTRIM             equ       $FFAE,1             ;NV FTRIM
NVICSTRM            equ       $FFAF,1             ;NV ICS Trim

NVBACKKEY           equ       $FFB0,8             ;8-byte backdoor comparison key ($FFB0..$FFB7)

; Following 2 registers transfered from flash to working regs at reset

NVPROT              equ       $FFBD,1             ;NV flash protection byte
                                                  ;NVPROT transfers to FPROT on reset
NVOPT               equ       $FFBF,1             ;NV flash options byte
                                                  ;NVFEOPT transfers to FOPT on reset
; **** END OF ORIGINAL DEFINITIONS *********************************************

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1170                ;typical bandgap voltage in mV

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFC0               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

; Vectors
                    #temp     VECTORS
Vtpm3ovf            next      :temp,2             ;TPM3 overflow
Vtpm3ch5            next      :temp,2             ;TPM3 Channel 5
Vtpm3ch4            next      :temp,2             ;TPM3 Channel 4
Vtpm3ch3            next      :temp,2             ;TPM3 Channel 3
Vtpm3ch2            next      :temp,2             ;TPM3 Channel 2
Vtpm3ch1            next      :temp,2             ;TPM3 Channel 1
Vtpm3ch0            next      :temp,2             ;TPM3 Channel 0
Vrtc                next      :temp,2             ;Real-Time Clock
Vsci2tx             next      :temp,2             ;SCI2 transmit vector
Vsci2rx             next      :temp,2             ;SCI2 receive vector
Vsci2err            next      :temp,2             ;SCI2 error vector
Vacmpx              next      :temp,2             ;ACMP vector
Vadc                next      :temp,2             ;A/D vector
Vkeyboard           next      :temp,2             ;Keyboard vector
Viicx               next      :temp,2             ;IIC vector
Vsci1tx             next      :temp,2             ;SCI1 transmit vector
Vsci1rx             next      :temp,2             ;SCI1 receive vector
Vsci1err            next      :temp,2             ;SCI1 error vector
Vspi1               next      :temp,2             ;SPI1 vector
                    #temp     :temp+2
Vtpm2ovf            next      :temp,2             ;TPM2 overflow
Vtpm2ch2            next      :temp,2             ;TPM2 Channel 2
Vtpm2ch1            next      :temp,2             ;TPM2 Channel 1
Vtpm2ch0            next      :temp,2             ;TPM2 Channel 0
Vtpm1ovf            next      :temp,2             ;TPM1 overflow
Vtpm1ch2            next      :temp,2             ;TPM1 Channel 2
Vtpm1ch1            next      :temp,2             ;TPM1 Channel 1
Vtpm1ch0            next      :temp,2             ;TPM1 Channel 0
Vlvd                next      :temp,2             ;Low voltage detect
Virq                next      :temp,2             ;IRQ vector
Vswi                next      :temp,2             ;SWI vector
Vreset              next      :temp,2             ;Reset vector

Vtpmovf             equ       Vtpm1ovf,2
Vtpmch2             equ       Vtpm1ch2,2
Vtpmch1             equ       Vtpm1ch1,2
Vtpmch0             equ       Vtpm1ch0,2

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
TRUE_ROM            equ       $8000               ;start of 32K Flash

EEPROM              def       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          def       EEPROM+FLASH_DATA_SIZE-1

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
                    #Error    FLASH_DATA_SIZE is too large
 #endif
#endif

ROM                 def       EEPROM_END+1
ROM_END             def       $FF9F               ;end of all flash (before NV registers and fixed vectors)

          #if FLASH_DATA_SIZE = 32*512*2          ;32KB in 512-byte pages
?NVPROT_MASK        def       1
          #endif
?NVPROT_MASK        def       ROM-1&$FE00>8

RAM                 equ       $80                 ;start of 2KB RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $087F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 2KB fragmented RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ||KHZ
HZ                  def       16777216            ;Cyclone 32768*512
#endif

;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

;----+-------+----------------------+------------+------------------------
;DRS | DMX32 | Reference range      | FLL factor | DCO range
;----+-------+----------------------+------------+------------------------
;00  |   0   | 31.25 - 39.0625 kHz  |     512    | 16 - 20 MHz
;00  |   1   | 32.768 kHz           |     608    | 19.92 MHz
;01  |   0   | 31.25 - 39.0625 kHz  |    1024    | 32 - 40 MHz
;01  |   1   | 32.768 kHz           |    1216    | 39.85 MHz
;10  |   0   | 31.25 - 39.0625 kHz  |    1536    | 48 - 60 MHz
;10  |   1   | 32.768 kHz           |    1824    | 59.77 MHz
;11  | Reserved

?                   macro     FLL_FACTOR,DRS,DMX(32)
                    mreq      1,2,3:FLL_FACTOR,DRS,DMX(32)
          #if FLL_FACTOR = ~1~
DRS_                equ       ~2~<DRS0.
DMX_                equ       ~3~<DMX32.
                    #Message  FLL_FACTOR = {FLL_FACTOR}, DRS_ = ~2~ ({DRS_}), DMX_ = ~3~ ({DMX_})
          #endif
                    endm

                    @?         512,0,0
                    @?         608,0,1
                    @?        1024,1,0
                    @?        1216,1,1
                    @?        1536,2,0
                    @?        1824,2,1

;*******************************************************************************

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
          #endif
NVOPT_VALUE         def       %11000000           ;NVFEOPT transfers to FOPT on reset
                             ; |||||||+----------- SEC00 \ 00:secure  10:unsecure
                             ; ||||||+------------ SEC01 / 01:secure  11:secure
                             ; ||++++------------- Not Used (Always 0)
                             ; |+----------------- FNORED - Vector Redirection Disable (No Redirection)
                             ; +------------------ KEYEN - Backdoor key mechanism enable

                    org       NVOPT               ;NV flash options byte
                    fcb       NVOPT_VALUE         ;NVFEOPT transfers to FOPT on reset
          #endif
;                   org       NVICSTRIM           ;NV ICS Trim Setting
;                   fcb       ??                  ;ICG trim value measured during factory test. User software optionally
;                                                 ;copies to ICGTRM during initialization.
                    #VECTORS  VECTORS
                    #RAM      RAM
                    #XRAM     XRAM
                    #ROM      ROM

                    #MEMORY   ROM       ROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
                    #MEMORY   NVOPT
                    #MEMORY   VECTORS   VECTORS|$FF
                    #MEMORY   EEPROM    EEPROM_END
                    #!MEMORY  CRC_LOCATION CRC_LOCATION+1
