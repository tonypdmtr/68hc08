;*******************************************************************************
;*            MC9S08SH8 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  *********************
                    #Message  * Target: MC9S08SH8 *
                    #Message  *********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
          #ifexists tboot_sh8.exp
                    #Uses     tboot_sh8.exp
          #else ifexists tboot.exp
                    #Uses     tboot.exp
          #else
                    #Uses     tboot/tboot_sh8.exp
          #endif

#endif

_SH_                def       8
_SH8_               def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*         Jim Sibigtroth - Motorola TSPG (Original version)
;*
;* Description: Register and bit name definitions for 9S08SH8
;*
;* Documentation: 9S08SH8 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08SH8's architecture, FLASH_DATA_SIZE can only take specific
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
;*  1.0    24-Nov-13   T-Pap   Release version for 9S08SH8
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $185F               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PORTA               equ       $00,1               ;Port A Data Register
DDRA                equ       $01,1               ;Port A Data Direction Register
PORTB               equ       $02,1               ;Port B Data Register
DDRB                equ       $03,1               ;Port B Data Direction Register
PORTC               equ       $04,1               ;Port C Data Register
DDRC                equ       $05,1               ;Port C Data Direction Register
ACMPSC              equ       $0E,1               ;ACMP Status and Control Register

ADCSC1              equ       $10,1               ;Status and Control Register 1
ADCSC2              equ       $11,1               ;Status and Control Register 2
ADCR                equ       $12,2               ;Data Result Register
ADCRH               equ       $12,1               ;Data Result High Register
ADCRL               equ       $13,1               ;Data Result Low Register

ADCCV               equ       $14,2               ;Compare Value Register
ADCCVH              equ       $14,1               ;Compare Value High Register
ADCCVL              equ       $15,1               ;Compare Value Low Register

ADCCFG              equ       $16,1               ;Configuration Register

APCTL1              equ       $17,1               ;Pin Control 1 Register
APCTL2              equ       $18,1               ;Pin Control 2 Register

IRQSC               equ       $1A,1               ;Interrupt request status and control register

MTIMSC              equ       $1C,1               ;MTIM Clock Configuration Register

MTIMCLK             equ       $1D,1               ;MTIM Clock Configuration Register

MTIMCNT             equ       $1E,1               ;MTIM Counter Register
MTIMMOD             equ       $1F,1               ;MTIM Modulo Register

TPM1SC              equ       $20,1               ;TPM1 Status and Control Register

TPM1CNT             equ       $21,2               ;TPM1 Timer Counter Register
TPM1CNTH            equ       $21,1               ;TPM1 Timer Counter Register High
TPM1CNTL            equ       $22,1               ;TPM1 Timer Counter Register Low
TPM1MOD             equ       $23,2               ;TPM1 Timer Counter Modulo Register
TPM1MODH            equ       $23,1               ;TPM1 Timer Counter Modulo Register High
TPM1MODL            equ       $24,1               ;TPM1 Timer Counter Modulo Register Low
TPM1C0SC            equ       $25,1               ;TPM1 Timer Channel 0 Status and Control Register

TPM1C0V             equ       $26,2               ;TPM1 Timer Channel 0 Value Register
TPM1C0VH            equ       $26,1               ;TPM1 Timer Channel 0 Value Register High
TPM1C0VL            equ       $27,1               ;TPM1 Timer Channel 0 Value Register Low
TPM1C1SC            equ       $28,1               ;TPM1 Timer Channel 1 Status and Control Register

TPM1C1V             equ       $29,2               ;TPM1 Timer Channel 1 Value Register
TPM1C1VH            equ       $29,1               ;TPM1 Timer Channel 1 Value Register High
TPM1C1VL            equ       $2A,1               ;TPM1 Timer Channel 1 Value Register Low
          ;
SCIBD               equ       $38,2               ;SCI Baud Rate Register
SCIBDH              equ       $38,1               ;SCI Baud Rate Register High
SCIBDL              equ       $39,1               ;SCI Baud Rate Register Low
SCIC1               equ       $3A,1               ;SCI Control Register 1
SCIC2               equ       $3B,1               ;SCI Control Register 2
SCIS1               equ       $3C,1               ;SCI Status Register 1
SCIS2               equ       $3D,1               ;SCI Status Register 2
SCIC3               equ       $3E,1               ;SCI Control Register 3
SCID                equ       $3F,1               ;SCI Data Register

ICSC1               equ       $48,1               ;ICS Control Register 1
ICSC2               equ       $49,1               ;ICS Control Register 2
ICSTRM              equ       $4A,1               ;ICS Trim Register
ICSSC               equ       $4B,1               ;ICS Status and Control Register

SPIC1               equ       $50,1               ;SPI Control Register 1
SPIC2               equ       $51,1               ;SPI Control Register 2
SPIBR               equ       $52,1               ;SPI Baud Rate Register
SPIS                equ       $53,1               ;SPI Status Register
SPID                equ       $55,1               ;SPI Data Register

IICA                equ       $58,1               ;IIC Address Register
IICF                equ       $59,1               ;IIC Frequency Divider Register
IICC1               equ       $5A,1               ;IIC Control Register 1
IICC                equ       $5A,1               ;IIC Control Register
IICS                equ       $5B,1               ;IIC Status Register
IICD                equ       $5C,1               ;IIC Data I/O Register
IICC2               equ       $5D,1               ;IIC Control Register 2

TPM2SC              equ       $60,1               ;TPM2 Status and Control Register
TPM2CNT             equ       $61,2               ;TPM2 Timer Counter Register
TPM2CNTH            equ       $61,1               ;TPM2 Timer Counter Register High
TPM2CNTL            equ       $62,1               ;TPM2 Timer Counter Register Low
TPM2MOD             equ       $63,2               ;TPM2 Timer Counter Modulo Register
TPM2MODH            equ       $63,1               ;TPM2 Timer Counter Modulo Register High
TPM2MODL            equ       $64,1               ;TPM2 Timer Counter Modulo Register Low
TPM2C0SC            equ       $65,1               ;TPM2 Timer Channel 0 Status and Control Register
TPM2C0V             equ       $66,2               ;TPM2 Timer Channel 0 Value Register
TPM2C0VH            equ       $66,1               ;TPM2 Timer Channel 0 Value Register High
TPM2C0VL            equ       $67,1               ;TPM2 Timer Channel 0 Value Register Low
TPM2C1SC            equ       $68,1               ;TPM2 Timer Channel 1 Status and Control Register
TPM2C1V             equ       $69,2               ;TPM2 Timer Channel 1 Value Register
TPM2C1VH            equ       $69,1               ;TPM2 Timer Channel 1 Value Register High
TPM2C1VL            equ       $6A,1               ;TPM2 Timer Channel 1 Value Register Low

RTCSC               equ       $6C,1               ;RTC Status and Control Register
RTCCNT              equ       $6D,1               ;RTC Counter Register
RTCMOD              equ       $6E,1               ;RTC Modulo Register

SRS                 equ       $1800,1             ;System Reset Status Register
COP                 equ       SRS,1               ;for "STA COP"

SBDFR               equ       $1801,1             ;System Background Debug Force Reset Register
SOPT1               equ       $1802,1             ;System Options Register 1
SOPT                equ       SOPT1,1
SOPT2               equ       $1803,1             ;System Options Register 2
SDID                equ       $1806,2             ;System Device Identification Register
SDIDH               equ       $1806,1             ;System Device Identification Register High
SDIDL               equ       $1807,1             ;System Device Identification Register Low

SPMSC1              equ       $1809,1             ;System Power Management Status and Control 1 Register
SPMSC2              equ       $180A,1             ;System Power Management Status and Control 2 Register

DBGCA               equ       $1810,2             ;Debug Comparator A Register
DBGCAH              equ       $1810,1             ;Debug Comparator A High Register
DBGCAL              equ       $1811,1             ;Debug Comparator A Low Register
DBGCB               equ       $1812,2             ;Debug Comparator B Register
DBGCBH              equ       $1812,1             ;Debug Comparator B High Register
DBGCBL              equ       $1813,1             ;Debug Comparator B Low Register
DBGF                equ       $1814,2             ;Debug FIFO Register
DBGFH               equ       $1814,1             ;Debug FIFO High Register
DBGFL               equ       $1815,1             ;Debug FIFO Low Register
DBGC                equ       $1816,1             ;Debug Control Register
DBGT                equ       $1817,1             ;Debug Trigger Register
DBGS                equ       $1818,1             ;Debug Status Register

FCDIV               equ       $1820,1             ;FLASH Clock Divider Register
FOPT                equ       $1821,1             ;FLASH Options Register
FCNFG               equ       $1823,1             ;FLASH Configuration Register
FPROT               equ       $1824,1             ;FLASH Protection Register
FSTAT               equ       $1825,1             ;Flash Status Register
FCMD                equ       $1826,1             ;FLASH Command Register

PTAPE               equ       $1840,1             ;Port A Pull Enable Register
PTASE               equ       $1841,1             ;Port A Slew Rate Enable Register
PTADS               equ       $1842,1             ;Port A Drive Strength Selection Register
PTASC               equ       $1844,1             ;Port A Interrupt Status and Control Register

PTAPS               equ       $1845,1             ;Port A Interrupt Pin Select Register
PTAES               equ       $1846,1             ;Port A Interrupt Edge Select Register
PTBPE               equ       $1848,1             ;Port B Pull Enable Register
PTBSE               equ       $1849,1             ;Port B Slew Rate Enable Register
PTBDS               equ       $184A,1             ;Port B Drive Strength Selection Register
PTBSC               equ       $184C,1             ;Port B Interrupt Status and Control Register

PTBPS               equ       $184D,1             ;Port B Interrupt Pin Select Register
PTBES               equ       $184E,1             ;Port B Interrupt Edge Select Register
PTCPE               equ       $1850,1             ;Port C Pull Enable Register
PTCSE               equ       $1851,1             ;Port C Slew Rate Enable Register
PTCDS               equ       $1852,1             ;Port C Drive Strength Selection Register
GNGC                equ       $1853,1             ;Ganged Output Drive Control Register

NVFTRIM             equ       $FFAE,1             ;Non-volatile ICS Fine Trim
NVICSTRM            equ       $FFAF,1             ;Non-volatile ICS Trim Register
NVBACKKEY           equ       $FFB0,8             ;Backdoor Comparison Key
NVPROT              equ       $FFBD,1             ;Non-volatile FLASH Protection Register
NVOPT               equ       $FFBF,1             ;Non-volatile Flash Options Register

;*******************************************************************************
; Bit numbers for use in BCLR, BSET, BRCLR, and BRSET
;*******************************************************************************

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
; MTIM
;-------------------------------------------------------------------------------

                    @bitnum   TRST,5
                    @bitnum   TSTP,4

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

                    @bitnum   IREFST,4            ;Internal Reference Status
                    @bitnum   CLKST1,3            ;Clock Mode Status
                    @bitnum   CLKST0,2
                    @bitnum   OSCINIT,1           ;OSC Initialization
                    @bitnum   FTRIM,0             ;ICS Fine Trim

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
; System Reset Status Register (SRS)
;-------------------------------------------------------------------------------

                    @bitnum   POR,7               ;Power-On Reset
                    @bitnum   PIN,6               ;External Reset Pin
                    @bitnum   COP,5               ;COP Watchdog
                    @bitnum   ILOP,4              ;Illegal Opcode
                    @bitnum   ILAD,3              ;Illegal Address
                    @bitnum   LVD,1               ;Low Voltage Detect

;-------------------------------------------------------------------------------
; System Options Register 1 (SOPT1)
;-------------------------------------------------------------------------------

                    @bitnum   COPT1,7             ;COP Watchdog Enable
                    @bitnum   COPT0,6             ;COP Watchdog Timeout
                    @bitnum   STOPE,5             ;Stop Mode Enable
                    @bitnum   IICPS,2             ;IIC Pin Select
                    @bitnum   BKGDPE,1            ;Background Debug Mode Pin Enable
                    @bitnum   RSTPE,0             ;/RESET Pin Enable

;-------------------------------------------------------------------------------
; System Options Register 2 (SOPT2)
;-------------------------------------------------------------------------------

                    @bitnum   COPCLKS,7           ;COP Watchdog Clock Select
                    @bitnum   COPW,6              ;COP Windowed
                    @bitnum   ACIC,4              ;Analog Comparator to Input Capture Enable
                    @bitnum   T1CH1PS,1           ;TPM1CH1 Pin Select
                    @bitnum   T1CH0PS,0           ;TPM1CH0 Pin Select

;-------------------------------------------------------------------------------
; System Power Management Status and Control 1 Register (SPMSC1)
;-------------------------------------------------------------------------------

                    @bitnum   LVWF,7              ;Low-Voltage Warning Flag
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVWIE,5             ;Low-Voltage Warning Interrupt Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detection Reset Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detection Stop Enable
                    @bitnum   LVDE,2              ;Low-Voltage Detection Enable
                    @bitnum   BGBE,0              ;Bandgap Buffer Enable

;-------------------------------------------------------------------------------
; System Power Management Status and Control 2 Register (SPMSC2)
;-------------------------------------------------------------------------------

                    @bitnum   LVDV,5              ;Low-Voltage Voltage level
                    @bitnum   LVWV,4              ;Low-Voltage Warning Voltage
                    @bitnum   PPDF,3              ;Partial Power Down Flag
                    @bitnum   PPDACK,2            ;Partial Power Down Acknowledge
                    @bitnum   PPDC,0              ;Partial Power Down Control

;-------------------------------------------------------------------------------
; Background Debug Controller (BDC)
;-------------------------------------------------------------------------------

; Debug Control Register (DBGC)

                    @bitnum   DBGEN,7             ;DBG Module Enable Bit
                    @bitnum   ARM,6               ;Arm bit
                    @bitnum   TAG,5               ;Tar or Force Bit
                    @bitnum   BRKEN,4             ;Break Enable Bit
                    @bitnum   RWA,3
                    @bitnum   RWAEN,2
                    @bitnum   RWB,1
                    @bitnum   RWBEN,0

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
                    @bitnum   ARMF,5              ;Arm Flag Bit
                    @bitnum   CNT3,3
                    @bitnum   CNT2,2
                    @bitnum   CNT1,1
                    @bitnum   CNT0,0

; BDC Status and Control Register (BDCSCR)

                    @bitnum   ENBDM,7             ;Enable BDM (Permit Active Background Mode)
                    @bitnum   BDMACT,6            ;Background Mode Active Status
                    @bitnum   BKPTEN,5            ;BDC Breakpoint Enable
                    @bitnum   FTS,4               ;Force/Tag Select
                    @bitnum   CLKSW,3             ;Select Source for BDC Communications Clock
                    @bitnum   WS,2                ;Wait or Stop Status
                    @bitnum   WSF,1               ;Wait or Stop Failure Status
                    @bitnum   DVF,0               ;Data Valid Failure Status

;-------------------------------------------------------------------------------
; Flash
;-------------------------------------------------------------------------------

; Flash Clock Divider Register (FCDIV)

                    @bitnum   DIVLD,7             ;Clock Divider Load Control
                    @bitnum   PRDIV8,6            ;Enable Prescaler by 8

; Flash Options Register (FOPT and NVOPT)

                    @bitnum   KEYEN,7             ;Backdoor Key Security Enable
                    @bitnum   FNORED,6
                    @bitnum   SEC1,1              ;Flash Security Bits
                    @bitnum   SEC0,0

; Flash Configuration Register (FCNFG)

                    @bitnum   KEYACC,5            ;Enable Security Key Writing

; Flash Protection Register (FPROT and NVPROT)

                    @bitnum   FPDIS,0             ;Flash Protection Disable

; Flash Status Register (FSTAT)

                    @bitnum   FCBEF,7             ;Flash Command Buffer Empty Flag
                    @bitnum   FCCF,6              ;Flash Command Complete Interrupt Flag
                    @bitnum   FPVIOL,5            ;Flash Protection Violation Flag
                    @bitnum   FACCERR,4           ;Flash Access Error Flag
                    @bitnum   FBLANK,2            ;Flash Flag Indicating the Erase Verify Operation Status

;-------------------------------------------------------------------------------
; Port A/B Interrupt Status and Control
;-------------------------------------------------------------------------------

                    @bitnum   PTAIF,3             ;PORTA Interrupt Flag
                    @bitnum   PTAACK,2            ;PORTA Interrupt Acknowledge
                    @bitnum   PTAIE,1             ;PORTA Interrupt Enable
                    @bitnum   PTAMOD,0            ;PORTA Detection Mode

                    @bitnum   PTBIF,3             ;PORTB Interrupt Flag
                    @bitnum   PTBACK,2            ;PORTB Interrupt Acknowledge
                    @bitnum   PTBIE,1             ;PORTB Interrupt Enable
                    @bitnum   PTBMOD,0            ;PORTB Detection Mode

;-------------------------------------------------------------------------------
; Ganged output
;-------------------------------------------------------------------------------

                    @bitnum   GNGEN,0             ;Ganged Output Drive Enable Bit

;*******************************************************************************
; Command codes for flash programming/erasure to be used with FCMD register
;*******************************************************************************

Blank_              equ       $05                 ;Blank Check command
ByteProg_           equ       $20                 ;Byte Program command
BurstProg_          equ       $25                 ;Burst Program command
PageErase_          equ       $40                 ;Page Erase command
MassErase_          equ       $41                 ;Mass Erase command

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08SH8_           def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap

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
                    next      :temp,2
Vacmp               next      :temp,2
                    next      :temp,2*3
Vmtim               next      :temp,2
Vrtc                next      :temp,2
Viic                next      :temp,2
Vadc                next      :temp,2
                    next      :temp,2
Vportb              next      :temp,2
Vporta              next      :temp,2
                    next      :temp,2
Vscitx              next      :temp,2
Vscirx              next      :temp,2
Vscierr             next      :temp,2
Vspi                next      :temp,2
Vtpm2ovf            next      :temp,2
Vtpm2ch1            next      :temp,2
Vtpm2ch0            next      :temp,2
Vtpm1ovf            next      :temp,2
                    next      :temp,2*4
Vtpm1ch1            next      :temp,2
Vtpm1ch0            next      :temp,2
                    next      :temp,2
Vlvd                next      :temp,2
Virq                next      :temp,2
Vswi                next      :temp,2
Vreset              next      :temp,2

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
TRUE_ROM            equ       $E000               ;start of Flash

EEPROM              def       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          def       EEPROM+FLASH_DATA_SIZE-1

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
                    #Error    FLASH_DATA_SIZE is too large
 #endif
#endif

ROM                 def       EEPROM_END+1
ROM_END             equ       $FF9F               ;end of all flash (before NV registers and fixed vectors)

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

          #if FLASH_DATA_SIZE = 8*512*2           ;8KB in 512-byte pages
?NVPROT_MASK        def       1
          #endif
?NVPROT_MASK        def       ROM-1&$FE00>8

RAM                 equ       $80                 ;start of RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

XRAM                equ       $0100               ;start of non-zero page RAM
XRAM_END            equ       $027F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ||KHZ
HZ                  def       33554432            ;Cyclone 32768*1024
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
