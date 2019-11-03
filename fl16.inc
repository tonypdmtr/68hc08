;*******************************************************************************
;*            MC9S08FL16 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08FL16 *
                    #Message  **********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_fl16.exp
  #endif

#endif

_FL_                def       16
_FL16_              def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*
;* Description: Register and bit name definitions for 9S08FL16
;*
;* Documentation: 9S08FL16 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08FL16's architecture, FLASH_DATA_SIZE can only take specific
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
;*  1.0    11-Mar-05   T-Pap   Adapted to ASM8 by <tonyp@acm.org>
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $187F               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PTAD                equ       $0038,1             ;Port A Data Register
PORTA               equ       PTAD,1
PTADD               equ       $0039,1             ;Port A Data Direction Register
DDRA                equ       PTADD,1
PTBD                equ       $003A,1             ;Port B Data Register
PORTB               equ       PTBD,1
PTBDD               equ       $003B,1             ;Port B Data Direction Register
DDRB                equ       PTBDD,1
PTCD                equ       $003C,1             ;Port C Data Register
PORTC               equ       PTCD,1
PTCDD               equ       $003D,1             ;Port C Data Direction Register
DDRC                equ       PTCDD,1
PTDD                equ       $003E,1             ;Port D Data Register
PORTD               equ       PTDD,1
PTDDD               equ       $003F,1             ;Port D Data Direction Register
DDRD                equ       PTDDD,1

; **** Interrupt Request Module (IRQ) ******************************************

IRQSC               equ       $000B,1             ; IRQ status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IRQPDD,6            ;IRQ Pulldown Disable
                    @bitnum   IRQEDG,5            ;IRQ Edge Select
                    @bitnum   IRQPE,4             ;IRQ Pin Enable
                    @bitnum   IRQF,3              ;IRQ Flag
                    @bitnum   IRQACK,2            ;IRQ Acknowledge
                    @bitnum   IRQIE,1             ;IRQ Interrupt Enable
                    @bitnum   IRQMOD,0            ;IRQ Detection Mode

; **** Analog-to-Digital Converter Module (ATD) ********************************

ADCSC1              equ       $0000,1             ;A/D Status & Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   COCO,7              ;Conversion Complete Flag
                    @bitnum   AIEN,6              ;Interrupt Enable
                    @bitnum   ADCO,5              ;Continuous Conversion Enable

ADCSC2              equ       $0001,1             ;A/D Status & Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   ADACT,7             ;Conversion Active
                    @bitnum   ADTRG,6             ;Conversion Trigger Select
                    @bitnum   ACFE,5              ;Compare Function Enable
                    @bitnum   ACFGT,4             ;Compare Function Greater Than Enable

ADCR                equ       $0003,1             ;Data Result Register
ADCCV               equ       $0005,1             ;Compare Value Register

ADCCFG              equ       $0006,1             ;A/D Configuration Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   ADLPC,7             ;Low Power Configuration
                    @bitnum   ADIV1,6             ;Clock Divide Select
                    @bitnum   ADIV0,5
                    @bitnum   ADLSMP.,4           ;Long Sample Time Configuration
                    @bitnum   MODE1,3             ;Conversion Mode Select
                    @bitnum   MODE0,2
                    @bitnum   ADICLK1,1           ;Input Clock Select
                    @bitnum   ADICLK0,0

APCTL1              equ       $0007,1             ;Pin Control 1 Register
APCTL2              equ       $0008,1             ;Pin Control 2 Register

; **** Serial Communications Interface (S08SCIV4) ******************************

SCIBD               equ       $1850,2             ;SCI baud rate register
SCIBDH              equ       $1850,1             ;SCI baud rate register (high)
SCIBDL              equ       $1851,1             ;SCI baud rate register (low)
SCIC1               equ       $1852,1             ;SCI Control Register 1

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   RXEDGIE,6           ;RxD Input Active Edge Interrupt Enable (for RXEDGIF)
                    @bitnum   LBKDIE,7            ;LIN Break Detect Interrupt Enable (for LBKDIF)

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   LOOPS,7             ;loopback mode
                    @bitnum   SCISWAI,6           ;SCI stop in wait
                    @bitnum   RSRC,5              ;receiver source
                    @bitnum   M,4                 ;9/8 bit data
                    @bitnum   WAKE,3              ;wake by addr mark/idle
                    @bitnum   ILT,2               ;idle line type; stop/start
                    @bitnum   PE,1                ;parity enable
                    @bitnum   PT,0                ;parity type

SCIC2               equ       $1853,1             ;SCI Control Register 2

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TIE,7               ;transmit interrupt enable
                    @bitnum   TCIE,6              ;TC interrupt enable
                    @bitnum   RIE,5               ;receive interrupt enable
                    @bitnum   ILIE,4              ;idle line interrupt enable
                    @bitnum   TE,3                ;transmitter enable
                    @bitnum   RE,2                ;receiver enable
                    @bitnum   RWU,1               ;receiver wakeup engage
                    @bitnum   SBK,0               ;send break

SCIS1               equ       $1854,1             ;SCI Status Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TDRE,7              ;Tx data register empty
                    @bitnum   TC,6                ;transmit complete
                    @bitnum   RDRF,5              ;Rx data register full
                    @bitnum   IDLE,4              ;idle line detected
                    @bitnum   OR,3                ;Rx over run
                    @bitnum   NF,2                ;Rx noise flag
                    @bitnum   FE,1                ;Rx framing error
                    @bitnum   PF,0                ;Rx parity failed

SCIS2               equ       $1855,1             ;SCI Status Register 2

; SCI Status Register 2 (SCIxS2)

                    @bitnum   LBKDIF,7            ;LIN Break Detect Interrupt Flag
                    @bitnum   RXEDGIF,6           ;RxD Pin Active Edge Interrupt Flag
                    @bitnum   RXINV,4             ;Receive Data Inversion
                    @bitnum   RWUID,3             ;Receive Wakeup Idle Detect
                    @bitnum   BRK13,2             ;Break Character Generation Length
                    @bitnum   LBKDE,1             ;LIN Break Detection Enable
                    @bitnum   RAF,0               ;Receiver Active Flag

SCIC3               equ       $1856,1             ;SCI Control Register 3

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   R8,7                ;9th Rx bit
                    @bitnum   T8,6                ;9th Tx bit
                    @bitnum   TXDIR,5             ;TxD pin direction?
                    @bitnum   TXINV,4             ;Transmit Data Inversion
                    @bitnum   ORIE,3              ;Rx over run int. enable
                    @bitnum   NEIE,2              ;Rx noise flag int. enable
                    @bitnum   FEIE,1              ;Rx framing error int. enable
                    @bitnum   PEIE,0              ;Rx parity error int. enable

SCID                equ       $1857,1             ;SCI Data Register (low byte)

; **** Timer/PWM Module (TPM) ***** TPM has 2 channels *************************

TPM2SC              equ       $0010,1             ;TPM2 status and control register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

;                   @bitnum   TOF,7               ;timer overflow flag
;                   @bitnum   TOIE,6              ;TOF interrupt enable
                    @bitnum   CPWMS,5             ;centered PWM select
                    @bitnum   CLKSB,4             ;clock select bits
                    @bitnum   CLKSA,3             ;         -//-
                    @bitnum   PS2,2               ;prescaler bits
                    @bitnum   PS1,1               ;         -//-
                    @bitnum   PS0,0               ;         -//-

TPM2CNT             equ       $0011,2             ;TPM2 Timer Counter Register
TPM2CNTH            equ       $0011,1             ;TPM2 Timer Counter Register High
TPM2CNTL            equ       $0012,1             ;TPM2 Timer Counter Register Low
TPM2MOD             equ       $0013,2             ;TPM2 Timer Counter Modulo Register
TPM2MODH            equ       $0013,1             ;TPM2 Timer Counter Modulo Register High
TPM2MODL            equ       $0014,1             ;TPM2 Timer Counter Modulo Register Low

TPM2C0SC            equ       $0015,1             ;TPM2 Timer Channel 0 Status and Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   CHnF,7              ;channel 0 flag
                    @bitnum   CHnIE,6             ;ch 0 interrupt enable
                    @bitnum   MSnB,5              ;mode select B
                    @bitnum   MSnA,4              ;mode select A
                    @bitnum   ELSnB,3             ;edge/level select B
                    @bitnum   ELSnA,2             ;edge/level select A

TPM2C0V             equ       $0016,2             ;TPM2 Timer Channel 0 Value Register
TPM2C0VH            equ       $0016,1             ;TPM2 Timer Channel 0 Value Register High
TPM2C0VL            equ       $0017,1             ;TPM2 Timer Channel 0 Value Register Low

TPM2C1SC            equ       $0018,1             ;TPM2 Timer Channel 1 Status and Control Register
TPM2C1V             equ       $0019,2             ;TPM2 Timer Channel 1 Value Register
TPM2C1VH            equ       $0019,1             ;TPM2 Timer Channel 1 Value Register High
TPM2C1VL            equ       $001A,1             ;TPM2 Timer Channel 1 Value Register Low

; **** Interrupt Priority Controller *******************************************

IPCSC               equ       $001E,1             ;IPC Status and Control Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   IPCSC_IPM0,0        ;Interrupt Priority Mask, bit 0
                    @bitnum   IPCSC_IPM1,1        ;Interrupt Priority Mask, bit 1
                    @bitnum   IPCSC_PULIPM,3      ;Pull IPM from IPMPS
                    @bitnum   IPCSC_PSF,4         ;Pseudo Stack Full
                    @bitnum   IPCSC_PSE,5         ;Pseudo Stack Empty
                    @bitnum   IPCSC_IPCE,7        ;Interrupt Priority Controller Enable

IPMPS               equ       $001F,1             ;Interrupt Priority Mask Pseudo Stack Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   IPMPS_IPM00,0       ;Interrupt Priority Mask pseudo stack position 0, bit 0
                    @bitnum   IPMPS_IPM01,1       ;Interrupt Priority Mask pseudo stack position 0, bit 1
                    @bitnum   IPMPS_IPM10,2       ;Interrupt Priority Mask pseudo stack position 1, bit 0
                    @bitnum   IPMPS_IPM11,3       ;Interrupt Priority Mask pseudo stack position 1, bit 1
                    @bitnum   IPMPS_IPM20,4       ;Interrupt Priority Mask pseudo stack position 2, bit 0
                    @bitnum   IPMPS_IPM21,5       ;Interrupt Priority Mask pseudo stack position 2, bit 1
                    @bitnum   IPMPS_IPM30,6       ;Interrupt Priority Mask pseudo stack position 3, bit 0
                    @bitnum   IPMPS_IPM31,7       ;Interrupt Priority Mask pseudo stack position 3, bit 1

;*******************************************************************************

TPM1SC              equ       $0020,1             ;TPM1 Status and Control Register
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

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ELS2A,2             ;Edge/Level Select Bit A
                    @bitnum   ELS2B,3             ;Edge/Level Select Bit B
                    @bitnum   MS2A,4              ;Mode Select A for TPM Channel 2
                    @bitnum   MS2B,5              ;Mode Select B for TPM Channel 2
                    @bitnum   CH2IE,6             ;Channel 2 Interrupt Enable
                    @bitnum   CH2F,7              ;Channel 2 Flag

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ELS3A,2             ;Edge/Level Select Bit A
                    @bitnum   ELS3B,3             ;Edge/Level Select Bit B
                    @bitnum   MS3A,4              ;Mode Select A for TPM Channel 3
                    @bitnum   MS3B,5              ;Mode Select B for TPM Channel 3
                    @bitnum   CH3IE,6             ;Channel 3 Interrupt Enable
                    @bitnum   CH3F,7              ;Channel 3 Flag

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

COPT1_              equ       %10000000           ;COP time-out select
COPT0_              equ       %01000000           ;COP time-out select
STOPE_              equ       %00100000           ;Stop Mode Enable
TCLKPEN_            equ       %00010000           ;TCLK pin enable
BKGDPE_             equ       %00000010           ;BDM pin enable
RSTPE_              equ       %00000001           ;Reset pin enable

SOPT2               equ       $1803,1             ;SIM System Options Register 2 (write once)

; bit position masks

COPCLKS_            equ       %10000000           ;COP watchdog clock select
COPW_               equ       %01000000           ;COP window

SDID                equ       $1806,2             ;system device identification 1 register (read-only)
SDIDH               equ       $1806,1             ;system device identification 1 register (read-only)
SDIDL               equ       $1807,1             ;rev3,2,1,0 + 12-bit ID. QG8 ID = $009

;*** SPMSC1 - System Power Management Status and Control 1 Register

SPMSC1              equ       $1809,1             ;System Power Management Status and Control 1 Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   BGBE,0              ;Bandgap Buffer Enable
                    @bitnum   LVDE,2              ;Low-Voltage Detect Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detect Stop Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detect Reset Enable
                    @bitnum   LVWIE,5             ;Low-Voltage Warning Interrupt Enable
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVWF,7              ;Low-Voltage Warning status

SPMSC2              equ       $180A,1             ;System Power Management Status and Control 2 Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   PPDC,0              ;Partial Power Down Control
                    @bitnum   PPDACK,2            ;Partial Power Down Acknowledge
                    @bitnum   PPDF,3              ;Partial Power Down Flag
                    @bitnum   LVWV,4              ;Low-Voltage Warning Voltage Select
                    @bitnum   LVDV,5              ;Low-Voltage Detect Voltage Select

; **** Debug Module (DBG) ******************************************************

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

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   RWBEN,0             ;Enable R/W for Comparator B
                    @bitnum   RWB,1               ;R/W Comparison Value for Comparator B
                    @bitnum   RWAEN,2             ;Enable R/W for Comparator A
                    @bitnum   RWA,3               ;R/W Comparison Value for Comparator A
                    @bitnum   BRKEN,4             ;Break Enable
                    @bitnum   TAG,5               ;Tag/Force Select
                    @bitnum   ARM,6               ;Arm Control
                    @bitnum   DBGEN,7             ;Debug Module Enable

DBGT                equ       $1817,1             ;DBG trigger register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   TRG0,0              ;Select Trigger Mode Bit 0
                    @bitnum   TRG1,1              ;Select Trigger Mode Bit 1
                    @bitnum   TRG2,2              ;Select Trigger Mode Bit 2
                    @bitnum   TRG3,3              ;Select Trigger Mode Bit 3
                    @bitnum   BEGIN,6             ;Begin/End Trigger Select
                    @bitnum   TRGSEL,7            ;Trigger Type

DBGS                equ       $1818,1             ;DBG status register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   CNT0,0              ;FIFO Valid Count Bit 0
                    @bitnum   CNT1,1              ;FIFO Valid Count Bit 1
                    @bitnum   CNT2,2              ;FIFO Valid Count Bit 2
                    @bitnum   CNT3,3              ;FIFO Valid Count Bit 3
                    @bitnum   ARMF,5              ;Arm Flag
                    @bitnum   BF,6                ;Trigger Match B Flag
                    @bitnum   AF,7                ;Trigger Match A Flag

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
SEC1_               equ       SEC01_
SEC0_               equ       SEC00_

FCNFG               equ       $1823,1             ;Flash configuration register

; bit position masks

KEYACC_             equ       %00100000           ;enable security key writing

FPROT               equ       $1824,1             ;Flash protection register

; bit position masks

FPDIS_              equ       %00000001           ;flash protection disable

FSTAT               equ       $1825,1             ;lash Status Register

; bit position masks

FCBEF_              equ       %10000000           ;flash command buffer empty flag
FCCF_               equ       %01000000           ;flash command complete flag
FPVIOL_             equ       %00100000           ;flash protection violation
FACCERR_            equ       %00010000           ;flash access error
FBLANK_             equ       %00000100           ;flash verified as all blank (erased =$ff) flag

FCMD                equ       $1826,1             ;FLASH Command Register

PTAPE               equ       $1840,1             ;Port A Pull Enable Register
PTAPUE              equ       PTAPE,1
PTASE               equ       $1841,1             ;Port A Slew Rate Enable Register
PTADS               equ       $1842,1             ;Port A Drive Strength Selection Register
PTBPE               equ       $1844,1             ;Port B Pull Enable Register
PTBPUE              equ       PTBPE,1
PTBSE               equ       $1845,1             ;Port B Slew Rate Enable Register
PTBDS               equ       $1846,1             ;Port B Drive Strength Selection Register
PTCPE               equ       $1848,1             ;Port C Pull Enable Register
PTCPUE              equ       PTCPE,1
PTCSE               equ       $1849,1             ;Port C Slew Rate Enable Register
PTCDS               equ       $184A,1             ;Port C Drive Strength Selection Register
PTDPE               equ       $184C,1             ;Port D Pull Enable Register
PTDPUE              equ       PTDPE,1
PTDSE               equ       $184D,1             ;Port D Slew Rate Enable Register
PTDDS               equ       $184E,1             ;Port D Drive Strength Selection Register

; **** Internal Clock Source (ICS) *********************************************

ICSC1               equ       $1858,1             ;ICS Control Register 1

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable

ICSC2               equ       $1859,1             ;ICS Control Register 2

                    @bitnum   BDIV1,7             ;Bus Frequency Divider
                    @bitnum   BDIV0,6
                    @bitnum   RANGE_SEL,5         ;Frequency Range Select
                    @bitnum   HGO,4               ;High Gain Oscillator Select
                    @bitnum   LP,3                ;Low Power Select
                    @bitnum   EREFS,2             ;External Reference Select
                    @bitnum   ERCLKEN,1           ;External Reference Enable
                    @bitnum   EREFSTEN,0          ;External Reference Stop Enable

ICSTRM              equ       $185A,1             ;ICS Trim Register

ICSSC               equ       $185B,1             ;ICS Status and Control Register

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

; **** Modulo Timer (MTIM16) ***************************************************

MTIMSC              equ       $1860,1             ;MTIM Status & Control Register

; bit numbers for use in BCLR, BSET, BRCLR, and BRSET

                    @bitnum   TOF,7               ;MTIM Overflow Flag
                    @bitnum   TOIE,6              ;MTIM Overflow Interrupt Enable
                    @bitnum   TRST,5              ;MTIM Counter Reset
                    @bitnum   TSTP,4              ;MTIM Counter Stop

MTIMCLK             equ       $1861,1             ;MTIM Clock Configuration Register
MTIMCNT             equ       $1862,2             ;MTIM Counter Register
MTIMCNTH            equ       $1862,1             ;MTIM Counter High Register
MTIMCNTL            equ       $1863,1             ;MTIM Counter Low Register
MTIMMOD             equ       $1864,2             ;MTIM Prescaler Register
MTIMMODH            equ       $1864,1             ;MTIM Prescaler High Register
MTIMMODL            equ       $1865,1             ;MTIM Prescaler Low Register

;*** ILRS0 - Interrupt Level Setting Register **********************************

ILRS0               equ       $1878,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS0_ILR00,0       ;Interrupt Level Register for Source 0, bit 0
                    @bitnum   ILRS0_ILR01,1       ;Interrupt Level Register for Source 0, bit 1
                    @bitnum   ILRS0_ILR10,2       ;Interrupt Level Register for Source 1, bit 0
                    @bitnum   ILRS0_ILR11,3       ;Interrupt Level Register for Source 1, bit 1
                    @bitnum   ILRS0_ILR20,4       ;Interrupt Level Register for Source 2, bit 0
                    @bitnum   ILRS0_ILR21,5       ;Interrupt Level Register for Source 2, bit 1
                    @bitnum   ILRS0_ILR30,6       ;Interrupt Level Register for Source 3, bit 0
                    @bitnum   ILRS0_ILR31,7       ;Interrupt Level Register for Source 3, bit 1

ILRS1               equ       $1879,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS1_ILR40,0       ;Interrupt Level Register for Source 4, bit 0
                    @bitnum   ILRS1_ILR41,1       ;Interrupt Level Register for Source 4, bit 1
                    @bitnum   ILRS1_ILR50,2       ;Interrupt Level Register for Source 5, bit 0
                    @bitnum   ILRS1_ILR51,3       ;Interrupt Level Register for Source 5, bit 1
                    @bitnum   ILRS1_ILR60,4       ;Interrupt Level Register for Source 6, bit 0
                    @bitnum   ILRS1_ILR61,5       ;Interrupt Level Register for Source 6, bit 1
                    @bitnum   ILRS1_ILR70,6       ;Interrupt Level Register for Source 7, bit 0
                    @bitnum   ILRS1_ILR71,7       ;Interrupt Level Register for Source 7, bit 1

ILRS2               equ       $187A,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS2_ILR80,0       ;Interrupt Level Register for Source 8, bit 0
                    @bitnum   ILRS2_ILR81,1       ;Interrupt Level Register for Source 8, bit 1
                    @bitnum   ILRS2_ILR90,2       ;Interrupt Level Register for Source 9, bit 0
                    @bitnum   ILRS2_ILR91,3       ;Interrupt Level Register for Source 9, bit 1
                    @bitnum   ILRS2_ILR100,4      ;Interrupt Level Register for Source 10, bit 0
                    @bitnum   ILRS2_ILR101,5      ;Interrupt Level Register for Source 10, bit 1
                    @bitnum   ILRS2_ILR110,6      ;Interrupt Level Register for Source 11, bit 0
                    @bitnum   ILRS2_ILR111,7      ;Interrupt Level Register for Source 11, bit 1

ILRS3               equ       $187B,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS3_ILR120,0      ;Interrupt Level Register for Source 12, bit 0
                    @bitnum   ILRS3_ILR121,1      ;Interrupt Level Register for Source 12, bit 1
                    @bitnum   ILRS3_ILR130,2      ;Interrupt Level Register for Source 13, bit 0
                    @bitnum   ILRS3_ILR131,3      ;Interrupt Level Register for Source 13, bit 1
                    @bitnum   ILRS3_ILR140,4      ;Interrupt Level Register for Source 14, bit 0
                    @bitnum   ILRS3_ILR141,5      ;Interrupt Level Register for Source 14, bit 1
                    @bitnum   ILRS3_ILR150,6      ;Interrupt Level Register for Source 15, bit 0
                    @bitnum   ILRS3_ILR151,7      ;Interrupt Level Register for Source 15, bit 1

ILRS4               equ       $187C,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS4_ILR160,0      ;Interrupt Level Register for Source 16, bit 0
                    @bitnum   ILRS4_ILR161,1      ;Interrupt Level Register for Source 16, bit 1
                    @bitnum   ILRS4_ILR170,2      ;Interrupt Level Register for Source 17, bit 0
                    @bitnum   ILRS4_ILR171,3      ;Interrupt Level Register for Source 17, bit 1
                    @bitnum   ILRS4_ILR180,4      ;Interrupt Level Register for Source 18, bit 0
                    @bitnum   ILRS4_ILR181,5      ;Interrupt Level Register for Source 18, bit 1
                    @bitnum   ILRS4_ILR190,6      ;Interrupt Level Register for Source 19, bit 0
                    @bitnum   ILRS4_ILR191,7      ;Interrupt Level Register for Source 19, bit 1

ILRS5               equ       $187D,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS5_ILR200,0      ;Interrupt Level Register for Source 20, bit 0
                    @bitnum   ILRS5_ILR201,1      ;Interrupt Level Register for Source 20, bit 1
                    @bitnum   ILRS5_ILR210,2      ;Interrupt Level Register for Source 21, bit 0
                    @bitnum   ILRS5_ILR211,3      ;Interrupt Level Register for Source 21, bit 1
                    @bitnum   ILRS5_ILR220,4      ;Interrupt Level Register for Source 22, bit 0
                    @bitnum   ILRS5_ILR221,5      ;Interrupt Level Register for Source 22, bit 1
                    @bitnum   ILRS5_ILR230,6      ;Interrupt Level Register for Source 23, bit 0
                    @bitnum   ILRS5_ILR231,7      ;Interrupt Level Register for Source 23, bit 1

ILRS6               equ       $187E,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS6_ILR240,0      ;Interrupt Level Register for Source 24, bit 0
                    @bitnum   ILRS6_ILR241,1      ;Interrupt Level Register for Source 24, bit 1
                    @bitnum   ILRS6_ILR250,2      ;Interrupt Level Register for Source 25, bit 0
                    @bitnum   ILRS6_ILR251,3      ;Interrupt Level Register for Source 25, bit 1
                    @bitnum   ILRS6_ILR260,4      ;Interrupt Level Register for Source 26, bit 0
                    @bitnum   ILRS6_ILR261,5      ;Interrupt Level Register for Source 26, bit 1
                    @bitnum   ILRS6_ILR270,6      ;Interrupt Level Register for Source 27, bit 0
                    @bitnum   ILRS6_ILR271,7      ;Interrupt Level Register for Source 27, bit 1

ILRS7               equ       $187F,1             ;Interrupt Level Setting Register

; bit numbers for usage in BCLR, BSET, BRCLR and BRSET

                    @bitnum   ILRS7_ILR280,0      ;Interrupt Level Register for Source 28, bit 0
                    @bitnum   ILRS7_ILR281,1      ;Interrupt Level Register for Source 28, bit 1
                    @bitnum   ILRS7_ILR290,2      ;Interrupt Level Register for Source 29, bit 0
                    @bitnum   ILRS7_ILR291,3      ;Interrupt Level Register for Source 29, bit 1
                    @bitnum   ILRS7_ILR300,4      ;Interrupt Level Register for Source 30, bit 0
                    @bitnum   ILRS7_ILR301,5      ;Interrupt Level Register for Source 30, bit 1
                    @bitnum   ILRS7_ILR310,6      ;Interrupt Level Register for Source 31, bit 0
                    @bitnum   ILRS7_ILR311,7      ;Interrupt Level Register for Source 31, bit 1

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

; comparison key in $FFB0 through $FFB7

; Following 2 registers transfered from flash to working regs at reset

NVPROT              equ       $FFBD,1             ;NV flash protection byte
                                                  ;NVPROT transfers to FPROT on reset
NVOPT               equ       $FFBF,1             ;NV flash options byte
                                                  ;NVFEOPT transfers to FOPT on reset
;NVOPT_SEC00        equ       0                   ;Security State Code, bit 0
;NVOPT_SEC01        equ       1                   ;Security State Code, bit 1
;NVOPT_FNORED       equ       6                   ;Vector Redirection Disable
;NVOPT_KEYEN        equ       7                   ;Backdoor Key Mechanism Enable

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08FL16_          def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1210                ;typical bandgap voltage in mV

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFD2               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

;--- Vectors
                    #temp     VECTORS
Vscitx              next      :temp,2             ;SCI transmit vector
Vscirx              next      :temp,2             ;SCI receive vector
Vscierr             next      :temp,2             ;SCI error vector
                    next      :temp,4
Vadc                next      :temp,2             ;A/D vector
Vtpm2ovf            next      :temp,2             ;TPM2 overflow
Vtpm2ch1            next      :temp,2             ;TPM2 Channel 1
Vtpm2ch0            next      :temp,2             ;TPM2 Channel 0
Vtpm1ovf            next      :temp,2             ;TPM1 overflow
                    next      :temp,4
Vtpm1ch3            next      :temp,2             ;TPM1 Channel 3
Vtpm1ch2            next      :temp,2             ;TPM1 Channel 2
Vtpm1ch1            next      :temp,2             ;TPM1 Channel 1
Vtpm1ch0            next      :temp,2             ;TPM1 Channel 0
Vmtim               next      :temp,2             ;Modulo Timer
                    next      :temp,4
Vlvd                next      :temp,2             ;Low voltage detect
Virq                next      :temp,2             ;IRQ vector
Vswi                next      :temp,2             ;SWI vector
Vreset              next      :temp,2             ;Reset vector

Vtpmovf             equ       Vtpm1ovf,2
Vtpmch3             equ       Vtpm1ch3,2
Vtpmch2             equ       Vtpm1ch2,2
Vtpmch1             equ       Vtpm1ch1,2
Vtpmch0             equ       Vtpm1ch0,2

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
TRUE_ROM            equ       $C000               ;start of 16K Flash

          #ifdef BOOTROM
?NVPROT_MASK        def       BOOTROM-1&$FE00>8   ;enable FPROT
          #endif
?NVPROT_MASK        def       TRUE_ROM+FLASH_DATA_SIZE-1&$FE00>8  ;enable FPROT

EEPROM              def       TRUE_ROM
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

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

XROM                equ       $FFC0               ;unused vectors can hold
XROM_END            equ       $FFD1               ;some more code/data

RAM                 equ       $0040               ;start of 1KB RAM
RAM_END             equ       $00FF               ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $043F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 1024 byte RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ
  #ifndef KHZ
HZ                  def       16777216            ;Cyclone default 32768*512
  #endif
#endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------

;----+-------+----------------------+------------+------------------------
;DRS | DMX32 | Reference range      | FLL factor | DCO range
;----+-------+----------------------+------------+------------------------
;00  |   0   | 31.25 - 39.0625 kHz  |     512    | 16 - 20 MHz
;00  |   1   | 32.768 kHz           |     608    | 19.92 MHz
;01  |   0   | 31.25 - 39.0625 kHz  |    1024    | 32 - 40 MHz -- UNAVAILABLE in FL16
;01  |   1   | 32.768 kHz           |    1216    | 39.85 MHz   -- UNAVAILABLE in FL16
;10  |   0   | 31.25 - 39.0625 kHz  |    1536    | 48 - 60 MHz -- UNAVAILABLE in FL16
;10  |   1   | 32.768 kHz           |    1824    | 59.77 MHz   -- UNAVAILABLE in FL16
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

;*******************************************************************************

                    #EEPROM
                    org       EEPROM

                    #DATA


          #ifndef BOOT
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
                    #MEMORY   EEPROM    EEPROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
                    #MEMORY   NVOPT
                    #MEMORY   VECTORS   VECTORS|$00FF
          #ifdef CRC_LOCATION
                    #MEMORY   CRC_LOCATION CRC_LOCATION+1
          #endif

;*******************************************************************************
                    #Uses     newcop.inc
;*******************************************************************************
