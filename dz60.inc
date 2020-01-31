;*******************************************************************************
;*            MC9S08DZ60 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08DZ60 *
                    #Message  **********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_dz60.exp
  #endif

#endif

_DZ_                def       60
_DZ60_              def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*         Freescale (Original version)
;*
;* Description: Register and bit name definitions for 9S08DZ60
;*
;* Documentation: 9S08DZ60 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08DZ60's architecture, FLASH_DATA_SIZE can only take specific
;*    values.  An invalid value will cause an informative assembler error message.
;* 5. ASM8's #MEMORY directive used to define actual Flash space for user code/data
;*
;* Include Files: COMMON.INC
;*
;* Assembler:  ASM8 by Tony G. Papadimitriou <tonyp@acm.org>
;*
;* Revision History: not yet released
;* Rev #     Date          Who                       Comments
;* -----  -----------  -------------  ------------------------------------------
;*  1.1    07-Jun-11   tonyp@acm.org  Adapted to ASM8 by <tonyp@acm.org>
;*  1.0    31-Mar-08   Freescale      Release version for 9S08DZ60
;*******************************************************************************

; Based on CPU DB MC9S08DZ60_64, version 3.00.001 (RegistersPrg V2.23)

; This header implements the mapping of I/O devices.

; (c) Copyright UNIS, spol. s r.o. 1997-2008
; UNIS, spol. s r.o.
; Jundrovska 33
; 624 00 Brno
; Czech Republic

; CPU Registers Revisions
; - 21.04.2006, V2.87.015
; - Removed bits MCGSC_IREFST, MCGSC_PLLST, FCNFG_ECCDIS, SDIDH_REV0..SDIDH_REV3.
; - Added registers NVFTRIM, NVMCGTRM. Removed register NVECC.
; - Renamed registers ADx ==> ADCx.
; -   REASON  Changes in the data sheet (from rev 0.05 8/5/2005 to rev 1.0 Draft A 04/2006)
; - 16.05.2006, V2.87.023
; - Renamed registers ADCVH ==> ADCCVH, ADCVL ==> ADCCVL, ADCV ==> ADCCV, ADCFG ==> ADCCFG,
; - IICC1 ==> IICC, Added bit CANCTL1_BORM.
; -   REASON  Changes in the data sheet (from rev 1.0 Draft A to rev 1.0 Draft B)
; - 08.09.2006, V2.87.027
; - Added registers CANxIDR2, CANxIDR3, corrected CANxIDR0, CANxIDR1 bits (Standard ID ==> Extended ID).
; -   REASON  Bug-fix (#3723 from the UNIS Issue Manager)
; - 28.06.2007, V2.87.128
; - Removed register FTSTMOD.
; -   REASON  Bug-fix (#4466 from the UNIS Issue Manager)
; - 20.12.2007, V2.87.141
; - Added bits to the ADC registers to use the ADC 12-bit module.
; -   REASON  Changes in the data sheet (from rev 1 6/2006 to rev 3 10/2007).
; - 28.03.2008, V3.00.0
; - Added registers IICC, DBGCA, DBGCB.
; -   REASON  Bug-fix (#5795 from the UNIS Issue Manager)

; File-Format-Revisions
; - 08.03.2006, V2.04
; - Support for bit(s) names duplicated with any register name in .h header files
; - 24.03.2006, V2.05
; -  Changes have not affected this file (because they are related to another family)
; - 26.04.2006, V2.06
; - Absolute assembly supported (depreciated symbols are not defined)
; - 27.04.2006, V2.07
; - Fixed macro __RESET_WATCHDOG for HCS12, HCS12X ,HCS08 DZ and HCS08 EN derivatives (write 0x55,0xAA).
; - 07.06.2006, V2.08
; - For .inc files added constants "RAMStart" and "RAMEnd" even there is only Z_RAM.
; - 03.07.2006, V2.09
; - Flash commands constants supported
; - 27.10.2006, V2.10
; - __RESET_WATCHDOG improved formating and re-definition
; - 23.11.2006, V2.11
; -  Changes have not affected this file (because they are related to another family)
; - 22.01.2007, V2.12
; -  Changes have not affected this file (because they are related to another family)
; - 01.03.2007, V2.13
; - Flash commands constants values converted to HEX format
; - 02.03.2007, V2.14
; - Interrupt vector numbers added into .H, see VectorNumber_*
; - 26.03.2007, V2.15
; -  Changes have not affected this file (because they are related to another family)
; - 10.05.2007, V2.16
; - Fixed flash commands definition for ColdFireV1 assembler (equ -> .equ)
; - 05.06.2007, V2.17
; -  Changes have not affected this file (because they are related to another family)
; - 19.07.2007, V2.18
; - Improved number of blanked lines inside register structures
; - 06.08.2007, V2.19
; - CPUDB revisions generated ahead of the file-format revisions.
; - 11.09.2007, V2.20
; - Added comment about initialization of unbonded pins.
; - 02.01.2008, V2.21
; -  Changes have not affected this file (because they are related to another family)
; - 13.02.2008, V2.22
; -  Changes have not affected this file (because they are related to another family)
; - 20.02.2008, V2.23
; -  Changes have not affected this file (because they are related to another family)

; Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
; derivative device. To avoid extra current drain from floating input pins, the user’s reset
; initialization routine in the application program must either enable on-chip pull-up devices
; or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $18FF               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PORTA               equ       $0000,1             ;Port A Data Register
DDRA                equ       $0001,1             ;Port A Data Direction Register

PORTB               equ       $0002,1             ;Port B Data Register
DDRB                equ       $0003,1             ;Port B Data Direction Register

PORTC               equ       $0004,1             ;Port C Data Register
DDRC                equ       $0005,1             ;Port C Data Direction Register

PORTD               equ       $0006,1             ;Port D Data Register
DDRD                equ       $0007,1             ;Port D Data Direction Register

PORTE               equ       $0008,1             ;Port E Data Register
DDRE                equ       $0009,1             ;Port E Data Direction Register

PORTF               equ       $000A,1             ;Port F Data Register
DDRF                equ       $000B,1             ;Port F Data Direction Register

PORTG               equ       $000C,1             ;Port G Data Register
DDRG                equ       $000D,1             ;Port G Data Direction Register

ACMP1SC             equ       $000E,1             ;ACMP1 Status and Control Register
ACMP2SC             equ       $000F,1             ;ACMP2 Status and Control Register

                    @bitnum   ACMOD0,0            ;Analog Comparator Mode Bit 0
                    @bitnum   ACMOD1,1            ;Analog Comparator Mode Bit 1
                    @bitnum   ACOPE,2             ;Analog Comparator Output Pin Enable
                    @bitnum   ACO,3               ;Analog Comparator Output
                    @bitnum   ACIE,4              ;Analog Comparator Interrupt Enable
                    @bitnum   ACF,5               ;Analog Comparator Flag
                    @bitnum   ACBGS,6             ;Analog Comparator Bandgap Select
                    @bitnum   ACME,7              ;Analog Comparator Module Enable

ADCSC1              equ       $0010,1             ;Status and Control Register 1

                    @bitnum   ADCO,5              ;Continuous Conversion Enable - ADCO is used to enable continuous conversions
                    @bitnum   AIEN,6              ;Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while AIEN is high, an interrupt is asserted
                    @bitnum   COCO,7              ;Conversion Complete Flag

ADCSC2              equ       $0011,1             ;Status and Control Register 2

                    @bitnum   ACFGT,4             ;Compare Function Greater Than Enable
                    @bitnum   ACFE,5              ;Compare Function Enable - ACFE is used to enable the compare function
                    @bitnum   ADTRG,6             ;Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
                    @bitnum   ADACT,7             ;Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted

ADCR                equ       $0012,2             ;Data Result Register
ADCRH               equ       $0012,1             ;Data Result High Register
ADCRL               equ       $0013,1             ;Data Result Low Register

ADCCV               equ       $0014,2             ;Compare Value Register
ADCCVH              equ       $0014,1             ;Compare Value High Register
ADCCVL              equ       $0015,1             ;Compare Value Low Register

ADCCFG              equ       $0016,1             ;Configuration Register

                    @bitnum   ADICLK0,0           ;Input Clock Select Bit 0
                    @bitnum   ADICLK1,1           ;Input Clock Select Bit 1
                    @bitnum   MODE0,2             ;Conversion Mode Selection Bit 0
                    @bitnum   MODE1,3             ;Conversion Mode Selection Bit 1
                    @bitnum   ADLSMP,4            ;Long Sample Time Configuration
                    @bitnum   ADIV0,5             ;Clock Divide Select Bit 0
                    @bitnum   ADIV1,6             ;Clock Divide Select Bit 1
                    @bitnum   ADLPC,7             ;Low Power Configuration

APCTL1              equ       $0017,1             ;Pin Control 1 Register
APCTL2              equ       $0018,1             ;Pin Control 2 Register
APCTL3              equ       $0019,1             ;Pin Control 3 Register

IRQSC               equ       $001C,1             ;Interrupt request status and control register

                    @bitnum   IRQMOD,0            ;IRQ Detection Mode
                    @bitnum   IRQIE,1             ;IRQ Interrupt Enable
                    @bitnum   IRQACK,2            ;IRQ Acknowledge
                    @bitnum   IRQF,3              ;IRQ Flag
                    @bitnum   IRQPE,4             ;IRQ Pin Enable
                    @bitnum   IRQEDG,5            ;IRQ Edge Select
                    @bitnum   IRQPDD,6            ;IRQ Pull Device Disable

TPM1SC              equ       $0020,1             ;TPM1 Status and Control Register

                    @bitnum   PS0,0               ;Prescale Divisor Select Bit 0
                    @bitnum   PS1,1               ;Prescale Divisor Select Bit 1
                    @bitnum   PS2,2               ;Prescale Divisor Select Bit 2
                    @bitnum   CLKSA,3             ;Clock Source Select A
                    @bitnum   CLKSB,4             ;Clock Source Select B
                    @bitnum   CPWMS,5             ;Center-Aligned PWM Select
                    @bitnum   TOIE,6              ;Timer Overflow Interrupt Enable
                    @bitnum   TOF,7               ;Timer Overflow Flag

TPM1CNT             equ       $0021,2             ;TPM1 Timer Counter Register
TPM1CNTH            equ       $0021,1             ;TPM1 Timer Counter Register High
TPM1CNTL            equ       $0022,1             ;TPM1 Timer Counter Register Low
TPM1MOD             equ       $0023,2             ;TPM1 Timer Counter Modulo Register
TPM1MODH            equ       $0023,1             ;TPM1 Timer Counter Modulo Register High
TPM1MODL            equ       $0024,1             ;TPM1 Timer Counter Modulo Register Low

TPM1C0SC            equ       $0025,1             ;TPM1 Timer Channel 0 Status and Control Register
TPM1C0V             equ       $0026,2             ;TPM1 Timer Channel 0 Value Register
TPM1C0VH            equ       $0026,1             ;TPM1 Timer Channel 0 Value Register High
TPM1C0VL            equ       $0027,1             ;TPM1 Timer Channel 0 Value Register Low
TPM1C1SC            equ       $0028,1             ;TPM1 Timer Channel 1 Status and Control Register
TPM1C1V             equ       $0029,2             ;TPM1 Timer Channel 1 Value Register
TPM1C1VH            equ       $0029,1             ;TPM1 Timer Channel 1 Value Register High
TPM1C1VL            equ       $002A,1             ;TPM1 Timer Channel 1 Value Register Low
TPM1C2SC            equ       $002B,1             ;TPM1 Timer Channel 2 Status and Control Register
TPM1C2V             equ       $002C,2             ;TPM1 Timer Channel 2 Value Register
TPM1C2VH            equ       $002C,1             ;TPM1 Timer Channel 2 Value Register High
TPM1C2VL            equ       $002D,1             ;TPM1 Timer Channel 2 Value Register Low
TPM1C3SC            equ       $002E,1             ;TPM1 Timer Channel 3 Status and Control Register
TPM1C3V             equ       $002F,2             ;TPM1 Timer Channel 3 Value Register
TPM1C3VH            equ       $002F,1             ;TPM1 Timer Channel 3 Value Register High
TPM1C3VL            equ       $0030,1             ;TPM1 Timer Channel 3 Value Register Low
TPM1C4SC            equ       $0031,1             ;TPM1 Timer Channel 4 Status and Control Register
TPM1C4V             equ       $0032,2             ;TPM1 Timer Channel 4 Value Register
TPM1C4VH            equ       $0032,1             ;TPM1 Timer Channel 4 Value Register High
TPM1C4VL            equ       $0033,1             ;TPM1 Timer Channel 4 Value Register Low
TPM1C5SC            equ       $0034,1             ;TPM1 Timer Channel 5 Status and Control Register
TPM1C5V             equ       $0035,2             ;TPM1 Timer Channel 5 Value Register
TPM1C5VH            equ       $0035,1             ;TPM1 Timer Channel 5 Value Register High
TPM1C5VL            equ       $0036,1             ;TPM1 Timer Channel 5 Value Register Low

                    @bitnum   ELSxA,2             ;Edge/Level Select Bit A
                    @bitnum   ELSxB,3             ;Edge/Level Select Bit B
                    @bitnum   MSxA,4              ;Mode Select A for TPM Channel 0
                    @bitnum   MSxB,5              ;Mode Select B for TPM Channel 0
                    @bitnum   CHxIE,6             ;Channel 0 Interrupt Enable
                    @bitnum   CHxF,7              ;Channel 0 Flag

SCI1BD              equ       $0038,2             ;SCI1 Baud Rate Register
SCI1BDH             equ       $0038,1             ;SCI1 Baud Rate Register High

                    @bitnum   RXEDGIE,6           ;RxD Input Active Edge Interrupt Enable (for RXEDGIF)
                    @bitnum   LBKDIE,7            ;LIN Break Detect Interrupt Enable (for LBKDIF)

SCI1BDL             equ       $0039,1             ;SCI1 Baud Rate Register Low
SCI1C1              equ       $003A,1             ;SCI1 Control Register 1

                    @bitnum   PT,0                ;Parity Type
                    @bitnum   PE,1                ;Parity Enable
                    @bitnum   ILT,2               ;Idle Line Type Select
                    @bitnum   WAKE,3              ;Receiver Wakeup Method Select
                    @bitnum   M,4                 ;9-Bit or 8-Bit Mode Select
                    @bitnum   RSRC,5              ;Receiver Source Select
                    @bitnum   SCISWAI,6           ;SCI Stops in Wait Mode
                    @bitnum   LOOPS,7             ;Loop Mode Select

SCI1C2              equ       $003B,1             ;SCI1 Control Register 2

                    @bitnum   SBK,0               ;Send Break
                    @bitnum   RWU,1               ;Receiver Wakeup Control
                    @bitnum   RE,2                ;Receiver Enable
                    @bitnum   TE,3                ;Transmitter Enable
                    @bitnum   ILIE,4              ;Idle Line Interrupt Enable (for IDLE)
                    @bitnum   RIE,5               ;Receiver Interrupt Enable (for RDRF)
                    @bitnum   TCIE,6              ;Transmission Complete Interrupt Enable (for TC)
                    @bitnum   TIE,7               ;Transmit Interrupt Enable (for TDRE)

SCI1S1              equ       $003C,1             ;SCI1 Status Register 1

                    @bitnum   PF,0                ;Parity Error Flag
                    @bitnum   FE,1                ;Framing Error Flag
                    @bitnum   NF,2                ;Noise Flag
                    @bitnum   OR,3                ;Receiver Overrun Flag
                    @bitnum   IDLE,4              ;Idle Line Flag
                    @bitnum   RDRF,5              ;Receive Data Register Full Flag
                    @bitnum   TC,6                ;Transmission Complete Flag
                    @bitnum   TDRE,7              ;Transmit Data Register Empty Flag

SCI1S2              equ       $003D,1             ;SCI1 Status Register 2

                    @bitnum   RAF,0               ;Receiver Active Flag
                    @bitnum   LBKDE,1             ;LIN Break Detection Enable
                    @bitnum   BRK13,2             ;Break Character Generation Length
                    @bitnum   RWUID,3             ;Receive Wake Up Idle Detect
                    @bitnum   RXINV,4             ;Receive Data Inversion
                    @bitnum   RXEDGIF,6           ;RxD Pin Active Edge Interrupt Flag
                    @bitnum   LBKDIF,7            ;LIN Break Detect Interrupt Flag

SCI1C3              equ       $003E,1             ;SCI1 Control Register 3

                    @bitnum   PEIE,0              ;Parity Error Interrupt Enable
                    @bitnum   FEIE,1              ;Framing Error Interrupt Enable
                    @bitnum   NEIE,2              ;Noise Error Interrupt Enable
                    @bitnum   ORIE,3              ;Overrun Interrupt Enable
                    @bitnum   TXINV,4             ;Transmit Data Inversion
                    @bitnum   TXDIR,5             ;TxD Pin Direction in Single-Wire Mode
                    @bitnum   T8,6                ;Ninth Data Bit for Transmitter
                    @bitnum   R8,7                ;Ninth Data Bit for Receiver

SCI1D               equ       $003F,1             ;SCI1 Data Register

SCI2BD              equ       $0040,2             ;SCI2 Baud Rate Register
SCI2BDH             equ       $0040,1             ;SCI2 Baud Rate Register High
SCI2BDL             equ       $0041,1             ;SCI2 Baud Rate Register Low
SCI2C1              equ       $0042,1             ;SCI2 Control Register 1
SCI2C2              equ       $0043,1             ;SCI2 Control Register 2
SCI2S1              equ       $0044,1             ;SCI2 Status Register 1
SCI2S2              equ       $0045,1             ;SCI2 Status Register 2
SCI2C3              equ       $0046,1             ;SCI2 Control Register 3
SCI2D               equ       $0047,1             ;SCI2 Data Register

MCGC1               equ       $0048,1             ;MCG Control Register 1
ICSC1               def       MCGC1,1             ;functionally equivalent to the ICSC1 of other MCUs

                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   RDIV0,3             ;Reference Divider, bit 0
                    @bitnum   RDIV1,4             ;Reference Divider, bit 1
                    @bitnum   RDIV2,5             ;Reference Divider, bit 2
                    @bitnum   CLKS0,6             ;Clock Source Select, bit 0
                    @bitnum   CLKS1,7             ;Clock Source Select, bit 1

MCGC2               equ       $0049,1             ;MCG Control Register 2
ICSC2               def       MCGC2,1             ;functionally equivalent to the ICSC2 of other MCUs

                    @bitnum   EREFSTEN,0          ;External Reference Stop Enable
                    @bitnum   ERCLKEN,1           ;External Reference Enable
                    @bitnum   EREFS,2             ;External Reference Select
                    @bitnum   LP,3                ;Low Power Select
                    @bitnum   HGO,4               ;High Gain Oscillator Select
                    @bitnum   RANGE_SEL,5         ;Frequency Range Select
                    @bitnum   BDIV0,6             ;Bus Frequency Divider, bit 0
                    @bitnum   BDIV1,7             ;Bus Frequency Divider, bit 1

MCGTRM              equ       $004A,1             ;MCG Trim Register
ICSTRM              def       MCGTRM,1            ;functionally equivalent to the ICSTRM of other MCUs
MCGSC               equ       $004B,1             ;MCG Status and Control Register
ICSSC               def       MCGSC,1             ;functionally equivalent to the ICSSC of other MCUs

                    @bitnum   FTRIM,0             ;MCG Fine Trim
                    @bitnum   OSCINIT,1           ;OSC Initialization
                    @bitnum   CLKST0,2            ;Clock Mode Status, bit 0
                    @bitnum   CLKST1,3            ;Clock Mode Status, bit 1
                    @bitnum   IREFST,4            ;Internal Reference Status
                    @bitnum   PLLST,5             ;PLL Select Status
                    @bitnum   LOCK,6              ;Lock Status
                    @bitnum   LOLS,7              ;Loss of Lock Status

MCGC3               equ       $004C,1             ;MCG Control Register 3

                    @bitnum   CME,5               ;Clock Monitor Enable
                    @bitnum   PLLS,6              ;PLL Select
                    @bitnum   LOLIE,7             ;Loss of Lock Interrupt Enable

SPIC1               equ       $0050,1             ;SPI Control Register 1

                    @bitnum   LSBFE,0             ;LSB First (Shifter Direction)
                    @bitnum   SSOE,1              ;Slave Select Output Enable
                    @bitnum   CPHA,2              ;Clock Phase
                    @bitnum   CPOL,3              ;Clock Polarity
                    @bitnum   MSTR,4              ;Master/Slave Mode Select
                    @bitnum   SPTIE,5             ;SPI Transmit Interrupt Enable
                    @bitnum   SPE,6               ;SPI System Enable
                    @bitnum   SPIE,7              ;SPI Interrupt Enable (for SPRF and MODF)

SPIC2               equ       $0051,1             ;SPI Control Register 2

                    @bitnum   SPC0,0              ;SPI Pin Control 0
                    @bitnum   SPISWAI,1           ;SPI Stop in Wait Mode
                    @bitnum   BIDIROE,3           ;Bidirectional Mode Output Enable
                    @bitnum   MODFEN,4            ;Master Mode-Fault Function Enable

SPIBR               equ       $0052,1             ;SPI Baud Rate Register
SPIS                equ       $0053,1             ;SPI Status Register

                    @bitnum   MODF,4              ;Master Mode Fault Flag
                    @bitnum   SPTEF,5             ;SPI Transmit Buffer Empty Flag
                    @bitnum   SPRF,7              ;SPI Read Buffer Full Flag

SPID                equ       $0055,1             ;SPI Data Register

IICA                equ       $0058               ;IIC Address Register
IICF                equ       $0059               ;IIC Frequency Divider Register

                    @bitnum   MULT0,6             ;Multiplier Factor Bit 0
                    @bitnum   MULT1,7             ;Multiplier Factor Bit 1

IICC1               equ       $005A,1             ;IIC Control Register 1
IICC                equ       $005A,1             ;IIC Control Register

                    @bitnum   RSTA,2              ;Repeat START
                    @bitnum   TXAK,3              ;Transmit Acknowledge Enable
                    @bitnum   TX,4                ;Transmit Mode Select
                    @bitnum   MST,5               ;Master Mode Select
                    @bitnum   IICIE,6             ;IIC Interrupt Enable
                    @bitnum   IICEN,7             ;IIC Enable

IICS                equ       $005B,1             ;IIC Status Register

                    @bitnum   RXAK,0              ;Receive Acknowledge
                    @bitnum   IICIF,1             ;IIC Interrupt Flag
                    @bitnum   SRW,2               ;Slave Read/Write
                    @bitnum   ARBL,4              ;Arbitration Lost
                    @bitnum   BUSY,5              ;Bus Busy
                    @bitnum   IAAS,6              ;Addressed as a Slave
                    @bitnum   TCF,7               ;Transfer Complete Flag

IICD                equ       $005C,1             ;IIC Data I/O Register
IICC2               equ       $005D,1             ;IIC Control Register 2

                    @bitnum   ADEXT,6             ;Address Extension
                    @bitnum   GCAEN,7             ;General Call Address Enable

TPM2SC              equ       $0060,1             ;TPM2 Status and Control Register
TPM2CNT             equ       $0061,2             ;TPM2 Timer Counter Register
TPM2CNTH            equ       $0061,1             ;TPM2 Timer Counter Register High
TPM2CNTL            equ       $0062,1             ;TPM2 Timer Counter Register Low
TPM2MOD             equ       $0063,2             ;TPM2 Timer Counter Modulo Register
TPM2MODH            equ       $0063,1             ;TPM2 Timer Counter Modulo Register High
TPM2MODL            equ       $0064,1             ;TPM2 Timer Counter Modulo Register Low
TPM2C0SC            equ       $0065,1             ;TPM2 Timer Channel 0 Status and Control Register
TPM2C0V             equ       $0066,2             ;TPM2 Timer Channel 0 Value Register
TPM2C0VH            equ       $0066,1             ;TPM2 Timer Channel 0 Value Register High
TPM2C0VL            equ       $0067,1             ;TPM2 Timer Channel 0 Value Register Low
TPM2C1SC            equ       $0068,1             ;TPM2 Timer Channel 1 Status and Control Register
TPM2C1V             equ       $0069,2             ;TPM2 Timer Channel 1 Value Register
TPM2C1VH            equ       $0069,1             ;TPM2 Timer Channel 1 Value Register High
TPM2C1VL            equ       $006A,1             ;TPM2 Timer Channel 1 Value Register Low

RTCSC               equ       $006C,1             ;RTC Status and Control Register

                    @bitnum   RTIE,4              ;Real-Time Interrupt Enable
                    @bitnum   RTCLKS0,5           ;Real-Time Clock Source Select, bit 0
                    @bitnum   RTCLKS1,6           ;Real-Time Clock Source Select, bit 1
                    @bitnum   RTIF,7              ;Real-Time Interrupt Flag

RTCCNT              equ       $006D,1             ;RTC Counter Register
RTCMOD              equ       $006E,1             ;RTC Modulo Register

SRS                 equ       $1800,1             ;System Reset Status Register
COP                 equ       SRS,1               ;for "STA COP"

                    @bitnum   LVD,1               ;Low Voltage Detect
                    @bitnum   LOC,2               ;Loss-of-Clock Reset
                    @bitnum   ILAD,3              ;Illegal Address
                    @bitnum   ILOP,4              ;Illegal Opcode
                    @bitnum   COP,5               ;Computer Operating Properly (COP) Watchdog
                    @bitnum   PIN,6               ;External Reset Pin
                    @bitnum   POR,7               ;Power-On Reset

SBDFR               equ       $1801,1             ;System Background Debug Force Reset Register

                    @bitnum   BDFR,0              ;Background Debug Force Reset

SOPT1               equ       $1802,1             ;System Options Register 1
SOPT                equ       SOPT1,1

                    @bitnum   IICPS,3             ;IIC Pin Select
                    @bitnum   SCI2PS,4            ;SCI2 Pin Select
                    @bitnum   STOPE,5             ;Stop Mode Enable
                    @bitnum   COPT0,6             ;COP Watchdog Timeout, bit 0
                    @bitnum   COPT1,7             ;COP Watchdog Timeout, bit 1

SOPT2               equ       $1803,1             ;System Options Register 2

                    @bitnum   MCSEL0,0            ;MCLK Divide Select, bit 0
                    @bitnum   MCSEL1,1            ;MCLK Divide Select, bit 1
                    @bitnum   MCSEL2,2            ;MCLK Divide Select, bit 2
                    @bitnum   ADHTS,4             ;ADC Hardware Trigger Select
                    @bitnum   COPW,6              ;COP Window
                    @bitnum   COPCLKS,7           ;COP Watchdog Clock Select

SDID                equ       $1806,2             ;System Device Identification Register
SDIDH               equ       $1806,1             ;System Device Identification Register High
SDIDL               equ       $1807,1             ;System Device Identification Register Low

SPMSC1              equ       $1809,1             ;System Power Management Status and Control 1 Register

                    @bitnum   BGBE,0              ;Bandgap Buffer Enable
                    @bitnum   LVDE,2              ;Low-Voltage Detect Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detect Stop Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detect Reset Enable
                    @bitnum   LVWIE,5             ;Low-Voltage Warning Interrupt Enable
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVWF,7              ;Low-Voltage Warning status

SPMSC2              equ       $180A,1             ;System Power Management Status and Control 2 Register

                    @bitnum   PPDC,0              ;Partial Power Down Control
                    @bitnum   PPDACK,2            ;Partial Power Down Acknowledge
                    @bitnum   PPDF,3              ;Partial Power Down Flag
                    @bitnum   LVWV,4              ;Low-Voltage Warning Voltage Select
                    @bitnum   LVDV,5              ;Low-Voltage Detect Voltage Select

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

                    @bitnum   RWBEN,0             ;Enable R/W for Comparator B
                    @bitnum   RWB,1               ;R/W Comparison Value for Comparator B
                    @bitnum   RWAEN,2             ;Enable R/W for Comparator A
                    @bitnum   RWA,3               ;R/W Comparison Value for Comparator A
                    @bitnum   BRKEN,4             ;Break Enable
                    @bitnum   TAG,5               ;Tag/Force Select
                    @bitnum   ARM,6               ;Arm Control
                    @bitnum   DBGEN,7             ;Debug Module Enable

DBGT                equ       $1817,1             ;Debug Trigger Register

                    @bitnum   BEGIN,6             ;Begin/End Trigger Select
                    @bitnum   TRGSEL,7            ;Trigger Type

DBGS                equ       $1818,1             ;Debug Status Register

                    @bitnum   ARMF,5              ;Arm Flag
                    @bitnum   BF,6                ;Trigger Match B Flag
                    @bitnum   AF,7                ;Trigger Match A Flag

FCDIV               equ       $1820,1             ;EEPROM and FLASH Clock Divider Register

                    @bitnum   PRDIV8,6            ;Enable Prescaler by 8
                    @bitnum   DIVLD,7             ;Clock Divider Load Control

FOPT                equ       $1821,1             ;EEPROM and FLASH Options Register

                    @bitnum   SEC0,0              ;Flash Security Bit 0
                    @bitnum   SEC1,1              ;Flash Security Bit 1
                    @bitnum   EPGMOD,5            ;EEPROM Sector Mode Bit
                    @bitnum   FNORED,6            ;Vector Redirection Disable Bit
                    @bitnum   KEYEN,7             ;Backdoor Key Security Enable Bit

FCNFG               equ       $1823,1             ;EEPROM and FLASH Configuration Register

                    @bitnum   KEYACC,5            ;Enable Security Key Writing
                    @bitnum   EPGSEL,6            ;EEPROM Page Select Bit

FPROT               equ       $1824,1             ;EEPROM and FLASH Protection Register
FSTAT               equ       $1825,1             ;EEPROM and FLASH Status Register

                    @bitnum   FBLANK,2            ;FLASH Flag Indicating the Erase Verify Operation Status
                    @bitnum   FACCERR,4           ;FLASH Access Error Flag
                    @bitnum   FPVIOL,5            ;FLASH Protection Violation Flag
                    @bitnum   FCCF,6              ;FLASH Command Complete Interrupt Flag
                    @bitnum   FCBEF,7             ;FLASH Command Buffer Empty Flag

FCMD                equ       $1826,1             ;EEPROM and FLASH Command Register

PTAPE               equ       $1840,1             ;Port A Pull Enable Register
PTAPUE              equ       PTAPE,1
PTASE               equ       $1841,1             ;Port A Slew Rate Enable Register
PTADS               equ       $1842,1             ;Port A Drive Strength Selection Register

PTASC               equ       $1844,1             ;Port A Interrupt Status and Control Register

                    @bitnum   PTAMOD,0            ;Port A Detection Mode
                    @bitnum   PTAIE,1             ;Port A Interrupt Enable
                    @bitnum   PTAACK,2            ;Port A Interrupt Acknowledge
                    @bitnum   PTAIF,3             ;Port A Interrupt Flag

PTAPS               equ       $1845,1             ;Port A Interrupt Pin Select Register
PTAES               equ       $1846,1             ;Port A Interrupt Edge Select Register

PTBPE               equ       $1848,1             ;Port B Pull Enable Register
PTBPUE              equ       PTBPE,1
PTBSE               equ       $1849,1             ;Port B Slew Rate Enable Register
PTBDS               equ       $184A,1             ;Port B Drive Strength Selection Register

PTBSC               equ       $184C,1             ;Port B Interrupt Status and Control Register

                    @bitnum   PTBMOD,0            ;Port B Detection Mode
                    @bitnum   PTBIE,1             ;Port B Interrupt Enable
                    @bitnum   PTBACK,2            ;Port B Interrupt Acknowledge
                    @bitnum   PTBIF,3             ;Port B Interrupt Flag

PTBPS               equ       $184D,1             ;Port B Interrupt Pin Select Register
PTBES               equ       $184E,1             ;Port B Interrupt Edge Select Register

PTCPE               equ       $1850,1             ;Port C Pull Enable Register
PTCPUE              equ       PTCPE,1
PTCSE               equ       $1851,1             ;Port C Slew Rate Enable Register
PTCDS               equ       $1852,1             ;Port C Drive Strength Selection Register

PTDPE               equ       $1858,1             ;Port D Pull Enable Register
PTDPUE              equ       PTDPE,1
PTDSE               equ       $1859,1             ;Port D Slew Rate Enable Register
PTDDS               equ       $185A,1             ;Port D Drive Strength Selection Register

PTDSC               equ       $185C,1             ;Port D Interrupt Status and Control Register

                    @bitnum   PTDMOD,0            ;Port D Detection Mode
                    @bitnum   PTDIE,1             ;Port D Interrupt Enable
                    @bitnum   PTDACK,2            ;Port D Interrupt Acknowledge
                    @bitnum   PTDIF,3             ;Port D Interrupt Flag

PTDPS               equ       $185D,1             ;Port D Interrupt Pin Select Register
PTDES               equ       $185E,1             ;Port D Interrupt Edge Select Register

PTEPE               equ       $1860,1             ;Port E Pull Enable Register
PTEPUE              equ       PTEPE,1
PTESE               equ       $1861,1             ;Port E Slew Rate Enable Register
PTEDS               equ       $1862,1             ;Port E Drive Strength Selection Register

PTFPE               equ       $1868,1             ;Port F Pull Enable Register
PTFPUE              equ       PTFPE,1
PTFSE               equ       $1869,1             ;Port F Slew Rate Enable Register
PTFDS               equ       $186A,1             ;Port F Drive Strength Selection Register

PTGPE               equ       $1870,1             ;Port G Pull Enable Register
PTGPUE              equ       PTGPE,1
PTGSE               equ       $1871,1             ;Port G Slew Rate Enable Register
PTGDS               equ       $1872,1             ;Port G Drive Strength Selection Register

;*******************************************************************************
; MSCAN CAN
;*******************************************************************************

CAN_BASE            def       $1880

CANCTL0             equ       CAN_BASE+$00,1      ;MSCAN Control 0 Register

CAN_INITRQ          @pin      CANCTL0,0           ;Initialization Mode Request
CAN_SLPRQ           @pin      CANCTL0,1           ;Sleep Mode Request
CAN_WUPE            @pin      CANCTL0,2           ;Wake-Up Enable
CAN_TIME            @pin      CANCTL0,3           ;Timer Enable
CAN_SYNCH           @pin      CANCTL0,4           ;Synchronized Status
CAN_CSWAI           @pin      CANCTL0,5           ;CAN Stops in Wait Mode
CAN_RXACT           @pin      CANCTL0,6           ;Receiver Active Status
CAN_RXFRM           @pin      CANCTL0,7           ;Received Frame Flag

CANCTL1             equ       CAN_BASE+$01,1      ;MSCAN Control 1 Register

CAN_INITAK          @pin      CANCTL1,0           ;Initialization Mode Acknowledge
CAN_SLPAK           @pin      CANCTL1,1           ;Sleep Mode Acknowledge
CAN_WUPM            @pin      CANCTL1,2           ;Wake-Up Mode
CAN_BORM            @pin      CANCTL1,3           ;Bus-Off Recovery Mode
CAN_LISTEN          @pin      CANCTL1,4           ;Listen Only Mode
CAN_LOOPB           @pin      CANCTL1,5           ;Loop Back Self Test Mode
CAN_CLKSRC          @pin      CANCTL1,6           ;MSCAN Clock Source
CAN_CANE            @pin      CANCTL1,7           ;MSCAN Enable

CANBTR0             equ       CAN_BASE+$02,1      ;MSCAN Bus Timing Register 0

CAN_SJW0            @pin      CANBTR0,6           ;Synchronization Jump Width 0
CAN_SJW1            @pin      CANBTR0,7           ;Synchronization Jump Width 1

CANBTR1             equ       CAN_BASE+$03,1      ;MSCAN Bus Timing Register 1

CAN_SAMP            @pin      CANBTR1,7           ;Sampling

CANRFLG             equ       CAN_BASE+$04,1      ;MSCAN Receiver Flag Register

CAN_RXF             @pin      CANRFLG,0           ;Receive Buffer Full
CAN_OVRIF           @pin      CANRFLG,1           ;Overrun Interrupt Flag
CAN_TSTAT0          @pin      CANRFLG,2           ;Transmitter Status Bit 0
CAN_TSTAT1          @pin      CANRFLG,3           ;Transmitter Status Bit 1
CAN_RSTAT0          @pin      CANRFLG,4           ;Receiver Status Bit 0
CAN_RSTAT1          @pin      CANRFLG,5           ;Receiver Status Bit 1
CAN_CSCIF           @pin      CANRFLG,6           ;CAN Status Change Interrupt Flag
CAN_WUPIF           @pin      CANRFLG,7           ;Wake-up Interrupt Flag

CANRIER             equ       CAN_BASE+$05,1      ;MSCAN Receiver Interrupt Enable Register

CAN_RXFIE           @pin      CANRIER,0           ;Receiver Full Interrupt Enable
CAN_OVRIE           @pin      CANRIER,1           ;Overrun Interrupt Enable
CAN_TSTATE0         @pin      CANRIER,2           ;Transmitter Status Change Enable 0
CAN_TSTATE1         @pin      CANRIER,3           ;Transmitter Status Change Enable 1
CAN_RSTATE0         @pin      CANRIER,4           ;Receiver Status Change Enable 0
CAN_RSTATE1         @pin      CANRIER,5           ;Receiver Status Change Enable 1
CAN_CSCIE           @pin      CANRIER,6           ;CAN Status Change Interrupt Enable
CAN_WUPIE           @pin      CANRIER,7           ;Wake-up Interrupt Enable

CANTFLG             equ       CAN_BASE+$06,1      ;MSCAN Transmitter Flag Register

CAN_TXE0            @pin      CANTFLG,0           ;Transmitter Buffer Empty 0
CAN_TXE1            @pin      CANTFLG,1           ;Transmitter Buffer Empty 1
CAN_TXE2            @pin      CANTFLG,2           ;Transmitter Buffer Empty 2

CANTIER             equ       CAN_BASE+$07,1      ;MSCAN Transmitter Interrupt Enable Register

CAN_TXEIE0          @pin      CANTIER,0           ;Transmitter Empty Interrupt Enable 0
CAN_TXEIE1          @pin      CANTIER,1           ;Transmitter Empty Interrupt Enable 1
CAN_TXEIE2          @pin      CANTIER,2           ;Transmitter Empty Interrupt Enable 2

CANTARQ             equ       CAN_BASE+$08,1      ;MSCAN Transmitter Message Abort Request

CAN_ABTRQ0          @pin      CANTARQ,0           ;Abort Request 0
CAN_ABTRQ1          @pin      CANTARQ,1           ;Abort Request 1
CAN_ABTRQ2          @pin      CANTARQ,2           ;Abort Request 2

CANTAAK             equ       CAN_BASE+$09,1      ;MSCAN Transmitter Message Abort Control

CAN_ABTAK0          @pin      CANTAAK,0           ;Abort Acknowledge 0
CAN_ABTAK1          @pin      CANTAAK,1           ;Abort Acknowledge 1
CAN_ABTAK2          @pin      CANTAAK,2           ;Abort Acknowledge 2

CANTBSEL            equ       CAN_BASE+$0A,1      ;MSCAN Transmit Buffer Selection

CAN_TX0             @pin      CANTBSEL,0          ;Transmit Buffer Select 0
CAN_TX1             @pin      CANTBSEL,1          ;Transmit Buffer Select 1
CAN_TX2             @pin      CANTBSEL,2          ;Transmit Buffer Select 2

CANIDAC             equ       CAN_BASE+$0B,1      ;MSCAN Identifier Acceptance Control Register

CAN_IDHIT0          @pin      CANIDAC,0           ;Identifier Acceptance Hit Indicator 0
CAN_IDHIT1          @pin      CANIDAC,1           ;Identifier Acceptance Hit Indicator 1
CAN_IDHIT2          @pin      CANIDAC,2           ;Identifier Acceptance Hit Indicator 2
CAN_IDAM0           @pin      CANIDAC,4           ;Identifier Acceptance Mode 0
CAN_IDAM1           @pin      CANIDAC,5           ;Identifier Acceptance Mode 1

CANMISC             equ       CAN_BASE+$0D,1      ;MSCAN Miscellaneous Register

CAN_BOHOLD          @pin      CANMISC,0           ;Bus-off State Hold Until User Request - If BORM is set

CANRXERR            equ       CAN_BASE+$0E,1      ;MSCAN Receive Error Counter Register
CANTXERR            equ       CAN_BASE+$0F,1      ;MSCAN Transmit Error Counter Register

CANIDAR0            equ       CAN_BASE+$10,1      ;MSCAN Identifier Acceptance Register 0
CANIDAR1            equ       CAN_BASE+$11,1      ;MSCAN Identifier Acceptance Register 1
CANIDAR2            equ       CAN_BASE+$12,1      ;MSCAN Identifier Acceptance Register 2
CANIDAR3            equ       CAN_BASE+$13,1      ;MSCAN Identifier Acceptance Register 3

CANIDMR0            equ       CAN_BASE+$14,1      ;MSCAN Identifier Mask Register 0
CANIDMR1            equ       CAN_BASE+$15,1      ;MSCAN Identifier Mask Register 1
CANIDMR2            equ       CAN_BASE+$16,1      ;MSCAN Identifier Mask Register 2
CANIDMR3            equ       CAN_BASE+$17,1      ;MSCAN Identifier Mask Register 3

CANIDAR4            equ       CAN_BASE+$18,1      ;MSCAN Identifier Acceptance Register 4
CANIDAR5            equ       CAN_BASE+$19,1      ;MSCAN Identifier Acceptance Register 5
CANIDAR6            equ       CAN_BASE+$1A,1      ;MSCAN Identifier Acceptance Register 6
CANIDAR7            equ       CAN_BASE+$1B,1      ;MSCAN Identifier Acceptance Register 7

CANIDMR4            equ       CAN_BASE+$1C,1      ;MSCAN Identifier Mask Register 4
CANIDMR5            equ       CAN_BASE+$1D,1      ;MSCAN Identifier Mask Register 5
CANIDMR6            equ       CAN_BASE+$1E,1      ;MSCAN Identifier Mask Register 6
CANIDMR7            equ       CAN_BASE+$1F,1      ;MSCAN Identifier Mask Register 7

CANRIDR0            equ       CAN_BASE+$20,1      ;MSCAN 0 Receive Identifier Register 0
CANRIDR1            equ       CAN_BASE+$21,1      ;MSCAN 0 Receive Identifier Register 1

CANR_IDE            @pin      CANRIDR1,3          ;ID Extended
CANR_SRR            @pin      CANRIDR1,4          ;Substitute Remote Request

CANRIDR2            equ       CAN_BASE+$22,1      ;MSCAN 0 Receive Identifier Register 2
CANRIDR3            equ       CAN_BASE+$23,1      ;MSCAN 0 Receive Identifier Register 3

CANR_RTR            @pin      CANRIDR3,0          ;Remote Transmission Request

CANRDSR             equ       CAN_BASE+$24,8      ;MSCAN Receive Data Segment Registers
CANRDSR0            equ       CAN_BASE+$24,1      ;MSCAN Receive Data Segment Register 0
CANRDSR1            equ       CAN_BASE+$25,1      ;MSCAN Receive Data Segment Register 1
CANRDSR2            equ       CAN_BASE+$26,1      ;MSCAN Receive Data Segment Register 2
CANRDSR3            equ       CAN_BASE+$27,1      ;MSCAN Receive Data Segment Register 3
CANRDSR4            equ       CAN_BASE+$28,1      ;MSCAN Receive Data Segment Register 4
CANRDSR5            equ       CAN_BASE+$29,1      ;MSCAN Receive Data Segment Register 5
CANRDSR6            equ       CAN_BASE+$2A,1      ;MSCAN Receive Data Segment Register 6
CANRDSR7            equ       CAN_BASE+$2B,1      ;MSCAN Receive Data Segment Register 7

CANRDLR             equ       CAN_BASE+$2C,1      ;MSCAN Receive Data Length Register

CANR_DLC0           @pin      CANRDLR,0           ;Data Length Code Bit 0
CANR_DLC1           @pin      CANRDLR,1           ;Data Length Code Bit 1
CANR_DLC2           @pin      CANRDLR,2           ;Data Length Code Bit 2
CANR_DLC3           @pin      CANRDLR,3           ;Data Length Code Bit 3

CANRTSR             equ       CAN_BASE+$2E,2      ;MSCAN Receive Time Stamp Register
CANRTSRH            equ       CAN_BASE+$2E,1      ;MSCAN Receive Time Stamp Register High
CANRTSRL            equ       CAN_BASE+$2F,1      ;MSCAN Receive Time Stamp Register Low

CANTIDR0            equ       CAN_BASE+$30,1      ;MSCAN 0 Transmit Identifier Register 0
CANTIDR1            equ       CAN_BASE+$31,1      ;MSCAN 0 Transmit Identifier Register 1

CANT_IDE            @pin      CANTIDR1,3          ;ID Extended
CANT_SRR            @pin      CANTIDR1,4          ;Substitute Remote Request

CANTIDR2            equ       CAN_BASE+$32,1      ;MSCAN 0 Transmit Identifier Register 2
CANTIDR3            equ       CAN_BASE+$33,1      ;MSCAN 0 Transmit Identifier Register 3

CANT_RTR            @pin      CANTIDR3,0          ;Remote Transmission Request

CANTDSR             equ       CAN_BASE+$34,8      ;MSCAN Transmit Data Segment Registers
CANTDSR0            equ       CAN_BASE+$34,1      ;MSCAN Transmit Data Segment Register 0
CANTDSR1            equ       CAN_BASE+$35,1      ;MSCAN Transmit Data Segment Register 1
CANTDSR2            equ       CAN_BASE+$36,1      ;MSCAN Transmit Data Segment Register 2
CANTDSR3            equ       CAN_BASE+$37,1      ;MSCAN Transmit Data Segment Register 3
CANTDSR4            equ       CAN_BASE+$38,1      ;MSCAN Transmit Data Segment Register 4
CANTDSR5            equ       CAN_BASE+$39,1      ;MSCAN Transmit Data Segment Register 5
CANTDSR6            equ       CAN_BASE+$3A,1      ;MSCAN Transmit Data Segment Register 6
CANTDSR7            equ       CAN_BASE+$3B,1      ;MSCAN Transmit Data Segment Register 7

CANTDLR             equ       CAN_BASE+$3C,1      ;MSCAN Transmit Data Length Register

CANT_DLC0           @pin      CANTDLR,0           ;Data Length Code Bit 0
CANT_DLC1           @pin      CANTDLR,1           ;Data Length Code Bit 1
CANT_DLC2           @pin      CANTDLR,2           ;Data Length Code Bit 2
CANT_DLC3           @pin      CANTDLR,3           ;Data Length Code Bit 3

CANTTBPR            equ       CAN_BASE+$3D,1      ;MSCAN Transmit Buffer Priority
CANTTSR             equ       CAN_BASE+$3E,2      ;MSCAN Transmit Time Stamp Register
CANTTSRH            equ       CAN_BASE+$3E,1      ;MSCAN Transmit Time Stamp Register High
CANTTSRL            equ       CAN_BASE+$3F,1      ;MSCAN Transmit Time Stamp Register Low

;*******************************************************************************

NVFTRIM             equ       $FFAE,1             ;Non-volatile MCG Fine Trim
NVMCGTRM            equ       $FFAF,1             ;Non-volatile MCG Trim Register
NVICSTRM            def       NVMCGTRM,1          ;functionally equivalent to the NVICSTRM of other MCUs
NVPROT              equ       $FFBD,1             ;Non-volatile FLASH Protection Register
NVOPT               equ       $FFBF,1             ;Non-volatile FLASH Options Register

NVOPT_EPGMOD        @pin      NVOPT,5             ;EEPROM Sector Mode Bit
NVOPT_FNORED        @pin      NVOPT,6             ;Vector Redirection Disable Bit
NVOPT_KEYEN         @pin      NVOPT,7             ;Backdoor Key Security Enable Bit

; Flash commands

Blank_              equ       $05                 ;Blank Check command
ByteProg_           equ       $20                 ;Byte Program command
BurstProg_          equ       $25                 ;Burst Program command
PageErase_          equ       $40                 ;Page Erase command
MassErase_          equ       $41                 ;Mass Erase command
EraseAbort_         equ       $47

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08DZ60_          def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1200                ;typical bandgap voltage in mV

NVBACKKEY           equ       $FFB0,8             ;8-byte backdoor comparison key ($FFB0..$FFB7)

FLASH_PAGE_SIZE     equ       768                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 768
                    #Error    FLASH_PAGE_SIZE should be fixed at 768
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFC0               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

; Vectors
                    #temp     VECTORS
Vacmp2              next      :temp,2             ;ACMP2 vector
Vacmp1              next      :temp,2             ;ACMP1 vector
Vcantx              next      :temp,2
Vcanrx              next      :temp,2
Vcanerr             next      :temp,2
Vcanwu              next      :temp,2
Vrtc                next      :temp,2             ;Real-Time Clock
Viic                next      :temp,2             ;IIC vector
Vadc                next      :temp,2             ;A/D vector
Vport               next      :temp,2             ;Pin-interrupt
Vsci2tx             next      :temp,2             ;SCI2 transmit vector
Vsci2rx             next      :temp,2             ;SCI2 receive vector
Vsci2err            next      :temp,2             ;SCI2 error vector
Vsci1tx             next      :temp,2             ;SCI1 transmit vector
Vsci1rx             next      :temp,2             ;SCI1 receive vector
Vsci1err            next      :temp,2             ;SCI1 error vector
Vspi                next      :temp,2             ;SPI vector
Vtpm2ovf            next      :temp,2             ;TPM2 overflow
Vtpm2ch1            next      :temp,2             ;TPM1 Channel 1
Vtpm2ch0            next      :temp,2             ;TPM1 Channel 0
Vtpm1ovf            next      :temp,2             ;TPM1 overflow
Vtpm1ch5            next      :temp,2             ;TPM1 Channel 5
Vtpm1ch4            next      :temp,2             ;TPM1 Channel 4
Vtpm1ch3            next      :temp,2             ;TPM1 Channel 3
Vtpm1ch2            next      :temp,2             ;TPM1 Channel 2
Vtpm1ch1            next      :temp,2             ;TPM1 Channel 1
Vtpm1ch0            next      :temp,2             ;TPM1 Channel 0
Vlol                next      :temp,2
Vlvd                next      :temp,2             ;Low voltage detect
Virq                next      :temp,2             ;IRQ vector
Vswi                next      :temp,2             ;SWI vector
Vreset              next      :temp,2             ;Reset vector

Vtpmovf             equ       Vtpm1ovf,2
Vtpmch2             equ       Vtpm1ch2,2
Vtpmch1             equ       Vtpm1ch1,2
Vtpmch0             equ       Vtpm1ch0,2

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE*2   ;round up to double block
TRUE_ROM            equ       $1900               ;start of 60K Flash

EEPROM              def       $1400               ;only half of the EEPROM is
EEPROM_END          equ       $17FF               ;visible through this window

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
                    #Error    FLASH_DATA_SIZE is too large
 #endif
#endif

ROM                 def       TRUE_ROM
ROM_END             equ       $FF9F               ;end of all flash (before NV registers and fixed vectors)

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

XROM                equ       $00001080
XROM_END            equ       $000013FF

?                   macro
                    #temp     $10000              ;;count down from 64K
                    mdo
          #if ROM < :temp
                    #temp     :temp-{FLASH_PAGE_SIZE*2} ;;back-up 1.5KB
                    mloop     64/2
          #endif
?NVPROT_MASK        def       $3F-{:mloop*2-2/2}|%11000000  ;EEPROM always unprotected
                    endm

                    @?                            ;calculate NVPROT_MASK value

RAM                 def       $0080               ;start of 2KB RAM
RAM_END             equ       $00FF               ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $107F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 8KB fragmented RAM
#endif

FLASH_START         equ       TRUE_ROM
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ
  #ifndef KHZ
HZ                  def       32000000            ;Cyclone 31250*1024
  #endif
#endif

;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

                    #EEPROM
                    org       EEPROM

                    #DATA


          #ifndef BOOT
                    org       NVPROT              ;NV flash protection byte
                    fcb       ?NVPROT_MASK        ;NVPROT transfers to FPROT on reset

          #ifndef NVOPT_VALUE
                    #Message  Using default NVOPT_VALUE (no vector redirection)
          #endif

NVOPT_VALUE         def       %11100010           ;NVFEOPT transfers to FOPT on reset
                             ; |||||||+----------- SEC00 \ 00:secure  10:unsecure
                             ; ||||||+------------ SEC01 / 01:secure  11:secure
                             ; |||+++------------- Not Used (Always 0)
                             ; ||+---------------- EPGMOD - EEPROM Sector Mode (0=4-byte, 1=8-byte)
                             ; |+----------------- FNORED - Vector Redirection Disable (No Redirection)
                             ; +------------------ KEYEN - Backdoor key mechanism enable

                    org       NVOPT               ;NV flash options byte
                    fcb       NVOPT_VALUE         ;NVFEOPT transfers to FOPT on reset
          #endif
;                   org       NVICSTRIM           ;NV ICS Trim Setting
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
                    #MEMORY   VECTORS   VECTORS|$00FF
                    #MEMORY   EEPROM    EEPROM_END
          #ifdef CRC_LOCATION
                    #MEMORY   CRC_LOCATION CRC_LOCATION+1
          #endif

;*******************************************************************************
                    #Uses     newcop.inc
;*******************************************************************************
