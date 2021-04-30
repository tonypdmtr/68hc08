;*******************************************************************************
;*            MC9S08AC32 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08AC32 *
                    #Message  **********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_ac32.exp
  #endif

#endif

_AC_                def       32
_AC32_              def       *

;*******************************************************************************
;* Author: Tony Papadimitriou - <tonyp@acm.org>
;*         Uknown - Motorola TSPG (Original version)
;*
;* Description: Register and bit name definitions for 9S08AC32
;*
;* Documentation: 9S08AC32 family Data Sheet for register and bit explanations
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
;*    Based on MC9S08AC32's architecture, FLASH_DATA_SIZE can only take specific
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
;* 2.18    2007.07.19          Improved number of blanked lines inside register structures
;* 2.19    2007.08.06          CPUDB revisions generated ahead of the file-format revisions.
;* 2.20    2007.09.11          Added comment about initialization of unbonded pins.
;* 2.21    2008.01.02          Changes have not affected this file (because they are related to another family)
;* 2.22    2008.02.13          Changes have not affected this file (because they are related to another family)
;* 2.23    2008.02.20          Changes have not affected this file (because they are related to another family)
;* 2.24    2008.07.03          Added support for bits with name starting with number (like "1HZ")
;* 2.25    2008.11.28          StandBy RAM array declaration for ANSI-C added
;* 2.26    2008.12.01          Duplication of bit (or bit-group) name with register name is not marked as a problem, if register is internal only and it is not displayed in I/O map.
;* 2.27    2009.03.17          Merged bit-group is not generated, if the name matches with another bit name in the register
;* 2.28    2009.04.06          Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
;* 2.29    2009.08.03          If there is just one bits group matching register name, single bits are not generated
;* 2.30    2009.09.10          Fixed generation of registers arrays.
;* 2.31    2009.10.15          HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
;* 2.32    2010.05.18          MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
;*******************************************************************************

; **** Memory Map and Interrupt Vectors ****************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $185F               ;end of high page registers

; **** Input/Output (I/O) Ports ************************************************

PORTA               equ       $00,1               ;I/O port A Data Register
DDRA                equ       $01,1               ;I/O port A Data Direction Register
PORTB               equ       $02,1               ;I/O port B Data Register
DDRB                equ       $03,1               ;I/O port B Data Direction Register
PORTC               equ       $04,1               ;I/O port C Data Register
DDRC                equ       $05,1               ;I/O port C Data Direction Register
PORTD               equ       $06,1               ;I/O port D Data Register
DDRD                equ       $07,1               ;I/O port D Data Direction Register
PORTE               equ       $08,1               ;I/O port E Data Register
DDRE                equ       $09,1               ;I/O port E Data Direction Register
PORTF               equ       $0A,1               ;I/O port F Data Register
DDRF                equ       $0B,1               ;I/O port F Data Direction Register
PORTG               equ       $0C,1               ;I/O port G Data Register
DDRG                equ       $0D,1               ;I/O port G Data Direction Register

ADC1SC1             equ       $10,1               ;Status and Control Register 1
ADCSC1              equ       $10,1               ;Status and Control Register 1
ADC1SC2             equ       $11,1               ;Status and Control Register 2
ADCSC2              equ       $11,1               ;Status and Control Register 2
ADC1R               equ       $12,2               ;Data Result Register
ADCR                equ       $12,2               ;Data Result Register
ADC1RH              equ       $12,1               ;Data Result High Register
ADCRH               equ       $12,1               ;Data Result High Register
ADC1RL              equ       $13,1               ;Data Result Low Register
ADCRL               equ       $13,1               ;Data Result Low Register
ADC1CV              equ       $14,2               ;Compare Value Register
ADCCV               equ       $14,2               ;Compare Value Register
ADC1CVH             equ       $14,1               ;Compare Value High Register
ADCCVH              equ       $14,1               ;Compare Value High Register
ADC1CVL             equ       $15,1               ;Compare Value Low Register
ADCCVL              equ       $15,1               ;Compare Value Low Register
ADC1CFG             equ       $16,1               ;Configuration Register
ADCCFG              equ       $16,1               ;Configuration Register
APCTL1              equ       $17,1               ;Pin Control 1 Register
APCTL2              equ       $18,1               ;Pin Control 2 Register

IRQSC               equ       $1C,1               ;Interrupt request status and control register

KBISC               equ       $1E,1               ;KBI Status and Control Register
KBIPE               equ       $1F,1               ;KBI Pin Enable Register

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
TPM1C2SC            equ       $2B,1               ;TPM1 Timer Channel 2 Status and Control Register
TPM1C2V             equ       $2C,2               ;TPM1 Timer Channel 2 Value Register
TPM1C2VH            equ       $2C,1               ;TPM1 Timer Channel 2 Value Register High
TPM1C2VL            equ       $2D,1               ;TPM1 Timer Channel 2 Value Register Low
TPM1C3SC            equ       $2E,1               ;TPM1 Timer Channel 3 Status and Control Register
TPM1C3V             equ       $2F,2               ;TPM1 Timer Channel 3 Value Register
TPM1C3VH            equ       $2F,1               ;TPM1 Timer Channel 3 Value Register High
TPM1C3VL            equ       $30,1               ;TPM1 Timer Channel 3 Value Register Low
TPM1C4SC            equ       $31,1               ;TPM1 Timer Channel 4 Status and Control Register
TPM1C4V             equ       $32,2               ;TPM1 Timer Channel 4 Value Register
TPM1C4VH            equ       $32,1               ;TPM1 Timer Channel 4 Value Register High
TPM1C4VL            equ       $33,1               ;TPM1 Timer Channel 4 Value Register Low
TPM1C5SC            equ       $34,1               ;TPM1 Timer Channel 5 Status and Control Register
TPM1C5V             equ       $35,2               ;TPM1 Timer Channel 5 Value Register
TPM1C5VH            equ       $35,1               ;TPM1 Timer Channel 5 Value Register High
TPM1C5VL            equ       $36,1               ;TPM1 Timer Channel 5 Value Register Low

TPMSC               equ       TPM1SC,::TPM1SC     ;TPM1 Status and Control Register
TPMCNT              equ       TPM1CNT,::TPM1CNT   ;TPM1 Timer Counter Register
TPMCNTH             equ       TPM1CNTH,::TPM1CNTH ;TPM1 Timer Counter Register High
TPMCNTL             equ       TPM1CNTL,::TPM1CNTL ;TPM1 Timer Counter Register Low
TPMMOD              equ       TPM1MOD,::TPM1MOD   ;TPM1 Timer Counter Modulo Register
TPMMODH             equ       TPM1MODH,::TPM1MODH ;TPM1 Timer Counter Modulo Register High
TPMMODL             equ       TPM1MODL,::TPM1MODL ;TPM1 Timer Counter Modulo Register Low
TPMC0SC             equ       TPM1C0SC,::TPM1C0SC ;TPM1 Timer Channel 0 Status and Control Register
TPMC0V              equ       TPM1C0V,::TPM1C0V   ;TPM1 Timer Channel 0 Value Register
TPMC0VH             equ       TPM1C0VH,::TPM1C0VH ;TPM1 Timer Channel 0 Value Register High
TPMC0VL             equ       TPM1C0VL,::TPM1C0VL ;TPM1 Timer Channel 0 Value Register Low
TPMC1SC             equ       TPM1C1SC,::TPM1C1SC ;TPM1 Timer Channel 1 Status and Control Register
TPMC1V              equ       TPM1C1V,::TPM1C1V   ;TPM1 Timer Channel 1 Value Register
TPMC1VH             equ       TPM1C1VH,::TPM1C1VH ;TPM1 Timer Channel 1 Value Register High
TPMC1VL             equ       TPM1C1VL,::TPM1C1VL ;TPM1 Timer Channel 1 Value Register Low
TPMC2SC             equ       TPM1C2SC,::TPM1C2SC ;TPM1 Timer Channel 2 Status and Control Register
TPMC2V              equ       TPM1C2V,::TPM1C2V   ;TPM1 Timer Channel 2 Value Register
TPMC2VH             equ       TPM1C2VH,::TPM1C2VH ;TPM1 Timer Channel 2 Value Register High
TPMC2VL             equ       TPM1C2VL,::TPM1C2VL ;TPM1 Timer Channel 2 Value Register Low
TPMC3SC             equ       TPM1C3SC,::TPM1C3SC ;TPM1 Timer Channel 3 Status and Control Register
TPMC3V              equ       TPM1C3V,::TPM1C3V   ;TPM1 Timer Channel 3 Value Register
TPMC3VH             equ       TPM1C3VH,::TPM1C3VH ;TPM1 Timer Channel 3 Value Register High
TPMC3VL             equ       TPM1C3VL,::TPM1C3VL ;TPM1 Timer Channel 3 Value Register Low
TPMC4SC             equ       TPM1C4SC,::TPM1C4SC ;TPM1 Timer Channel 4 Status and Control Register
TPMC4V              equ       TPM1C4V,::TPM1C4V   ;TPM1 Timer Channel 4 Value Register
TPMC4VH             equ       TPM1C4VH,::TPM1C4VH ;TPM1 Timer Channel 4 Value Register High
TPMC4VL             equ       TPM1C4VL,::TPM1C4VL ;TPM1 Timer Channel 4 Value Register Low
TPMC5SC             equ       TPM1C5SC,::TPM1C5SC ;TPM1 Timer Channel 5 Status and Control Register
TPMC5V              equ       TPM1C5V,::TPM1C5V   ;TPM1 Timer Channel 5 Value Register
TPMC5VH             equ       TPM1C5VH,::TPM1C5VH ;TPM1 Timer Channel 5 Value Register High
TPMC5VL             equ       TPM1C5VL,::TPM1C5VL ;TPM1 Timer Channel 5 Value Register Low

SCI1BD              equ       $38,2               ;SCI1 Baud Rate Register
SCI1BDH             equ       $38,1               ;SCI1 Baud Rate Register High
SCI1BDL             equ       $39,1               ;SCI1 Baud Rate Register Low
SCI1C1              equ       $3A,1               ;SCI1 Control Register 1
SCI1C2              equ       $3B,1               ;SCI1 Control Register 2
SCI1S1              equ       $3C,1               ;SCI1 Status Register 1
SCI1S2              equ       $3D,1               ;SCI1 Status Register 2
SCI1C3              equ       $3E,1               ;SCI1 Control Register 3
SCI1D               equ       $3F,1               ;SCI1 Data Register

SCI2BD              equ       $40,2               ;SCI2 Baud Rate Register
SCI2BDH             equ       $40,1               ;SCI2 Baud Rate Register High
SCI2BDL             equ       $41,1               ;SCI2 Baud Rate Register Low
SCI2C1              equ       $42,1               ;SCI2 Control Register 1
SCI2C2              equ       $43,1               ;SCI2 Control Register 2
SCI2S1              equ       $44,1               ;SCI2 Status Register 1
SCI2S2              equ       $45,1               ;SCI2 Status Register 2
SCI2C3              equ       $46,1               ;SCI2 Control Register 3
SCI2D               equ       $47,1               ;SCI2 Data Register

ICGC1               equ       $48,1               ;ICG Control Register 1
ICGC2               equ       $49,1               ;ICG Control Register 2
ICGS1               equ       $4A,1               ;ICG Status Register 1
ICGS2               equ       $4B,1               ;ICG Status Register 2
ICGFLT              equ       $4C,2               ;ICG Filter Register
ICGFLTU             equ       $4C,1               ;ICG Upper Filter Register
ICGFLTL             equ       $4D,1               ;ICG Lower Filter Register
ICGTRM              equ       $4E,1               ;ICG Trim Register
ICSTRM              equ       ICGTRM,::ICGTRM     ;ICG Trim Register

SPI1C1              equ       $50,1               ;SPI1 Control Register 1
SPI1C2              equ       $51,1               ;SPI1 Control Register 2
SPI1BR              equ       $52,1               ;SPI1 Baud Rate Register
SPI1S               equ       $53,1               ;SPI1 Status Register
SPI1D               equ       $55,1               ;SPI1 Data Register

CRCH                equ       $56,1               ;CRC High Register
CRCL                equ       $57,1               ;CRC Low Register

IIC1A               equ       $58,1               ;IIC Address Register
IIC1F               equ       $59,1               ;IIC Frequency Divider Register
IIC1C1              equ       $5A,1               ;IIC Control Register 1
IIC1C               equ       $5A,1               ;IIC Control Register
IIC1S               equ       $5B,1               ;IIC Status Register
IIC1D               equ       $5C,1               ;IIC Data I/O Register
IIC1C2              equ       $5D,1               ;IIC Control Register 2

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

SRS                 equ       $1800,1             ;System Reset Status Register
SBDFR               equ       $1801,1             ;System Background Debug Force Reset Register
SOPT                equ       $1802,1             ;System Options Register
SOPT1               equ       $1802,1             ;System Options Register
SMCLK               equ       $1803,1             ;System MCLK Control Register

SDID                equ       $1806,2             ;System Device Identification Register
SDIDH               equ       $1806,1             ;System Device Identification Register High
SDIDL               equ       $1807,1             ;System Device Identification Register Low

SRTISC              equ       $1808,1             ;System Real-Time Interrupt Status and Control Register
SPMSC1              equ       $1809,1             ;System Power Management Status and Control 1 Register
SPMSC2              equ       $180A,1             ;System Power Management Status and Control 2 Register

SOPT2               equ       $180C,1             ;System Options Register 2

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

TPM3SC              equ       $1830,1             ;TPM3 Status and Control Register
TPM3CNT             equ       $1831,2             ;TPM3 Timer Counter Register
TPM3CNTH            equ       $1831,1             ;TPM3 Timer Counter Register High
TPM3CNTL            equ       $1832,1             ;TPM3 Timer Counter Register Low
TPM3MOD             equ       $1833,2             ;TPM3 Timer Counter Modulo Register
TPM3MODH            equ       $1833,1             ;TPM3 Timer Counter Modulo Register High
TPM3MODL            equ       $1834,1             ;TPM3 Timer Counter Modulo Register Low
TPM3C0SC            equ       $1835,1             ;TPM3 Timer Channel 0 Status and Control Register

TPM3C0V             equ       $1836,2             ;TPM3 Timer Channel 0 Value Register
TPM3C0VH            equ       $1836,1             ;TPM3 Timer Channel 0 Value Register High
TPM3C0VL            equ       $1837,1             ;TPM3 Timer Channel 0 Value Register Low
TPM3C1SC            equ       $1838,1             ;TPM3 Timer Channel 1 Status and Control Register
TPM3C1V             equ       $1839,2             ;TPM3 Timer Channel 1 Value Register
TPM3C1VH            equ       $1839,1             ;TPM3 Timer Channel 1 Value Register High
TPM3C1VL            equ       $183A,1             ;TPM3 Timer Channel 1 Value Register Low

PTAPUE              equ       $1840,1             ;Port A Pull Enable Register
PTASE               equ       $1841,1             ;Port A Slew Rate Enable Register
PTADS               equ       $1842,1             ;Port A Drive Strength Selection Register
PTBPUE              equ       $1844,1             ;Port B Pull Enable Register
PTBSE               equ       $1845,1             ;Port B Slew Rate Enable Register
PTBDS               equ       $1846,1             ;Port B Drive Strength Selection Register
PTCPUE              equ       $1848,1             ;Port C Pull Enable Register
PTCSE               equ       $1849,1             ;Port C Slew Rate Enable Register
PTCDS               equ       $184A,1             ;Port C Drive Strength Selection Register
PTDPUE              equ       $184C,1             ;Port D Pull Enable Register
PTDSE               equ       $184D,1             ;Port D Slew Rate Enable Register
PTDDS               equ       $184E,1             ;Port D Drive Strength Selection Register
PTEPUE              equ       $1850,1             ;Port E Pull Enable Register
PTESE               equ       $1851,1             ;Port E Slew Rate Enable Register
PTEDS               equ       $1852,1             ;Port E Drive Strength Selection Register
PTFPUE              equ       $1854,1             ;Port F Pull Enable Register
PTFSE               equ       $1855,1             ;Port F Slew Rate Enable Register
PTFDS               equ       $1856,1             ;Port F Drive Strength Selection Register
PTGPUE              equ       $1858,1             ;Port G Pull Enable Register
PTGSE               equ       $1859,1             ;Port G Slew Rate Enable Register
PTGDS               equ       $185A,1             ;Port G Drive Strength Selection Register

NVBACKKEY           equ       $FFB0,8             ;Backdoor Comparison Key
NVICGTRM1           equ       $FFBC,1             ;Non volatile storage of 250kHz ICG trim value
NVPROT              equ       $FFBD,1             ;Non-volatile FLASH Protection Register
NVICGTRM            equ       $FFBE,1             ;Non volatile ICG Trim Register
NVICSTRM            equ       NVICGTRM,::NVICGTRM ;Non volatile ICG Trim Register
NVOPT               equ       $FFBF,1             ;Non-volatile Flash Options Register

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

                    @bitnum   KEYEN,7             ;Backdoor Key Security Enable
                    @bitnum   FNORED,6            ;Vector Redirection Disable
                    @bitnum   SEC1,1              ;Flash Security Bits
                    @bitnum   SEC0,0
                    @bitnum   SEC00,0             ; -//- (alias)
                    @bitnum   SEC01,1

; Flash Configuration Register (FCNFG)

                    @bitnum   KEYACC,5            ;Enable Security Key Writing

; Flash Protection Register (FPROT and NVPROT)

                    @bitnum   FPOPEN,0            ;Flash Protection Open

;*** ADC1SC1 - Status and Control Register 1

                    @bitnum   ADCH0,0             ;Input Channel Select Bit 0
                    @bitnum   ADCH1,1             ;Input Channel Select Bit 1
                    @bitnum   ADCH2,2             ;Input Channel Select Bit 2
                    @bitnum   ADCH3,3             ;Input Channel Select Bit 3
                    @bitnum   ADCH4,4             ;Input Channel Select Bit 4
                    @bitnum   ADCO,5              ;Continuous Conversion Enable - ADCO is used to enable continuous conversions
                    @bitnum   AIEN,6              ;Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while
                    @bitnum   COCO,7              ;Conversion Complete Flag

;*** ADC1SC2 - Status and Control Register 2

                    @bitnum   ACFGT,4             ;Compare Function Greater Than Enable
                    @bitnum   ACFE,5              ;Compare Function Enable - ACFE is used to enable the compare function
                    @bitnum   ADTRG,6             ;Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
                    @bitnum   ADACT,7             ;Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a

;*** ADC1CFG - Configuration Register

                    @bitnum   ADICLK0,0           ;Input Clock Select Bit 0
                    @bitnum   ADICLK1,1           ;Input Clock Select Bit 1
                    @bitnum   MODE0,2             ;Conversion Mode Selection Bit 0
                    @bitnum   MODE1,3             ;Conversion Mode Selection Bit 1
                    @bitnum   ADLSMP,4            ;Long Sample Time Configuration
                    @bitnum   ADIV0,5             ;Clock Divide Select Bit 0
                    @bitnum   ADIV1,6             ;Clock Divide Select Bit 1
                    @bitnum   ADLPC,7             ;Low Power Configuration

;*** IRQSC - Interrupt request status and control register

                    @bitnum   IRQMOD,0            ;IRQ Detection Mode
                    @bitnum   IRQIE,1             ;IRQ Interrupt Enable
                    @bitnum   IRQACK,2            ;IRQ Acknowledge
                    @bitnum   IRQF,3              ;IRQ Flag
                    @bitnum   IRQPE,4             ;IRQ Pin Enable
                    @bitnum   IRQEDG,5            ;IRQ Edge Select
                    @bitnum   IRQPDD,6            ;IRQ Pull Device Disable

;*** KBISC - KBI Status and Control Register

                    @bitnum   KBIMOD,0            ;Keyboard Detection Mode
                    @bitnum   KBIE,1              ;Keyboard Interrupt Enable
                    @bitnum   KBACK,2             ;Keyboard Interrupt Acknowledge
                    @bitnum   KBF,3               ;Keyboard Interrupt Flag
                    @bitnum   KBEDG4,4            ;Keyboard Edge Select for KBI Port Bit 4
                    @bitnum   KBEDG5,5            ;Keyboard Edge Select for KBI Port Bit 5
                    @bitnum   KBEDG6,6            ;Keyboard Edge Select for KBI Port Bit 6
                    @bitnum   KBEDG7,7            ;Keyboard Edge Select for KBI Port Bit 7

;*** TPMxSC - TPMx Status and Control Register

                    @bitnum   PS0,0               ;Prescale Divisor Select Bit 0
                    @bitnum   PS1,1               ;Prescale Divisor Select Bit 1
                    @bitnum   PS2,2               ;Prescale Divisor Select Bit 2
                    @bitnum   CLKSA,3             ;Clock Source Select A
                    @bitnum   CLKSB,4             ;Clock Source Select B
                    @bitnum   CPWMS,5             ;Center-Aligned PWM Select
                    @bitnum   TOIE,6              ;Timer Overflow Interrupt Enable
                    @bitnum   TOF,7               ;Timer Overflow Flag

;*** TPMxC0SC - TPMx Timer Channel 0 Status and Control Register

                    @bitnum   ELSxA,2             ;Edge/Level Select Bit A
                    @bitnum   ELSxB,3             ;Edge/Level Select Bit B
                    @bitnum   MSxA,4              ;Mode Select A for TPM Channel x
                    @bitnum   MSxB,5              ;Mode Select B for TPM Channel x
                    @bitnum   CHxIE,6             ;Channel x Interrupt Enable
                    @bitnum   CHxF,7              ;Channel x Flag

;*** SCIxC1 - SCIx Control Register 1

                    @bitnum   PT,0                ;Parity Type
                    @bitnum   PE,1                ;Parity Enable
                    @bitnum   ILT,2               ;Idle Line Type Select
                    @bitnum   WAKE,3              ;Receiver Wakeup Method Select
                    @bitnum   M,4                 ;9-Bit or 8-Bit Mode Select
                    @bitnum   RSRC,5              ;Receiver Source Select
                    @bitnum   SCISWAI,6           ;SCI Stops in Wait Mode
                    @bitnum   LOOPS,7             ;Loop Mode Select

;*** SCIxC2 - SCIx Control Register 2

                    @bitnum   SBK,0               ;Send Break
                    @bitnum   RWU,1               ;Receiver Wakeup Control
                    @bitnum   RE,2                ;Receiver Enable
                    @bitnum   TE,3                ;Transmitter Enable
                    @bitnum   ILIE,4              ;Idle Line Interrupt Enable (for IDLE)
                    @bitnum   RIE,5               ;Receiver Interrupt Enable (for RDRF)
                    @bitnum   TCIE,6              ;Transmission Complete Interrupt Enable (for TC)
                    @bitnum   TIE,7               ;Transmit Interrupt Enable (for TDRE)

;*** SCIxS1 - SCIx Status Register 1

                    @bitnum   PF,0                ;Parity Error Flag
                    @bitnum   FE,1                ;Framing Error Flag
                    @bitnum   NF,2                ;Noise Flag
                    @bitnum   OR,3                ;Receiver Overrun Flag
                    @bitnum   IDLE,4              ;Idle Line Flag
                    @bitnum   RDRF,5              ;Receive Data Register Full Flag
                    @bitnum   TC,6                ;Transmission Complete Flag
                    @bitnum   TDRE,7              ;Transmit Data Register Empty Flag

;*** SCIxS2 - SCIx Status Register 2

                    @bitnum   RAF,0               ;Receiver Active Flag
                    @bitnum   LBKDE,1             ;LIN Break Detection Enable
                    @bitnum   BRK13,2             ;Break Character Generation Length
                    @bitnum   RWUID,3             ;Receive Wake Up Idle Detect
                    @bitnum   RXINV,4             ;Receive Data Inversion
                    @bitnum   RXEDGIF,6           ;RxD Pin Active Edge Interrupt Flag
                    @bitnum   LBKDIF,7            ;LIN Break Detect Interrupt Flag

;*** SCIxC3 - SCIx Control Register 3

                    @bitnum   PEIE,0              ;Parity Error Interrupt Enable
                    @bitnum   FEIE,1              ;Framing Error Interrupt Enable
                    @bitnum   NEIE,2              ;Noise Error Interrupt Enable
                    @bitnum   ORIE,3              ;Overrun Interrupt Enable
                    @bitnum   TXINV,4             ;Transmit Data Inversion
                    @bitnum   TXDIR,5             ;TxD Pin Direction in Single-Wire Mode
                    @bitnum   T8,6                ;Ninth Data Bit for Transmitter
                    @bitnum   R8,7                ;Ninth Data Bit for Receiver

;*** SCIxBDH - SCIx Baud Rate Register High

                    @bitnum   RXEDGIE,6           ;RxD Input Active Edge Interrupt Enable (for RXEDGIF)
                    @bitnum   LBKDIE,7            ;LIN Break Detect Interrupt Enable (for LBKDIF)

;*** ICGC1 - ICG Control Register 1

                    @bitnum   LOCD,1              ;Loss of Clock Disable
                    @bitnum   OSCSTEN,2           ;Enable Oscillator in Off Mode
                    @bitnum   CLKS0,3             ;Clock Mode Select, bit 0
                    @bitnum   CLKS1,4             ;Clock Mode Select, bit 1
                    @bitnum   REFS,5              ;External Reference Select
                    @bitnum   RANGE_SEL,6         ;Frequency Range Select
                    @bitnum   HGO,7               ;High Gain Oscillator Select

;*** ICGC2 - ICG Control Register 2

                    @bitnum   RFD0,0              ;Reduced Frequency Divider, bit 0
                    @bitnum   RFD1,1              ;Reduced Frequency Divider, bit 1
                    @bitnum   RFD2,2              ;Reduced Frequency Divider, bit 2
                    @bitnum   LOCRE,3             ;Loss of Clock Reset Enable
                    @bitnum   MFD0,4              ;Multiplication Factor, bit 0
                    @bitnum   MFD1,5              ;Multiplication Factor, bit 1
                    @bitnum   MFD2,6              ;Multiplication Factor, bit 2
                    @bitnum   LOLRE,7             ;Loss of Lock Reset Enable

;*** ICGS1 - ICG Status Register 1

                    @bitnum   ICGIF,0             ;ICG Interrupt Flag
                    @bitnum   ERCS,1              ;External Reference Clock Status
                    @bitnum   LOCS,2              ;Loss Of Clock Status
                    @bitnum   LOCK,3              ;FLL Lock Status
                    @bitnum   LOLS,4              ;FLL Loss of Lock Status
                    @bitnum   REFST,5             ;Reference Clock Status
                    @bitnum   CLKST0,6            ;Clock Mode Status, bit 0
                    @bitnum   CLKST1,7            ;Clock Mode Status, bit 1

;*** ICGS2 - ICG Status Register 2

                    @bitnum   DCOS,0              ;DCO Clock Stable

;*** SPI1C1 - SPI1 Control Register 1

                    @bitnum   LSBFE,0             ;LSB First (Shifter Direction)
                    @bitnum   SSOE,1              ;Slave Select Output Enable
                    @bitnum   CPHA,2              ;Clock Phase
                    @bitnum   CPOL,3              ;Clock Polarity
                    @bitnum   MSTR,4              ;Master/Slave Mode Select
                    @bitnum   SPTIE,5             ;SPI Transmit Interrupt Enable
                    @bitnum   SPE,6               ;SPI System Enable
                    @bitnum   SPIE,7              ;SPI Interrupt Enable (for SPRF and MODF)

;*** SPI1C2 - SPI1 Control Register 2

                    @bitnum   SPC0,0              ;SPI Pin Control 0
                    @bitnum   SPISWAI,1           ;SPI Stop in Wait Mode
                    @bitnum   BIDIROE,3           ;Bidirectional Mode Output Enable
                    @bitnum   MODFEN,4            ;Master Mode-Fault Function Enable

;*** SPI1BR - SPI1 Baud Rate Register

                    @bitnum   SPR0,0              ;SPI Baud Rate Divisor Bit 0
                    @bitnum   SPR1,1              ;SPI Baud Rate Divisor Bit 1
                    @bitnum   SPR2,2              ;SPI Baud Rate Divisor Bit 2
                    @bitnum   SPPR0,4             ;SPI Baud Rate Prescale Divisor Bit 0
                    @bitnum   SPPR1,5             ;SPI Baud Rate Prescale Divisor Bit 1
                    @bitnum   SPPR2,6             ;SPI Baud Rate Prescale Divisor Bit 2

;*** SPI1S - SPI1 Status Register

                    @bitnum   MODF,4              ;Master Mode Fault Flag
                    @bitnum   SPTEF,5             ;SPI Transmit Buffer Empty Flag
                    @bitnum   SPRF,7              ;SPI Read Buffer Full Flag

;*** IIC1F - IIC Frequency Divider Register

                    @bitnum   ICR0,0              ;IIC Clock Rate Bit 0
                    @bitnum   ICR1,1              ;IIC Clock Rate Bit 1
                    @bitnum   ICR2,2              ;IIC Clock Rate Bit 2
                    @bitnum   ICR3,3              ;IIC Clock Rate Bit 3
                    @bitnum   ICR4,4              ;IIC Clock Rate Bit 4
                    @bitnum   ICR5,5              ;IIC Clock Rate Bit 5
                    @bitnum   MULT0,6             ;Multiplier Factor Bit 0
                    @bitnum   MULT1,7             ;Multiplier Factor Bit 1

;*** IICxC - IIC Control Register

                    @bitnum   RSTA,2              ;Repeat START
                    @bitnum   TXAK,3              ;Transmit Acknowledge Enable
                    @bitnum   TX,4                ;Transmit Mode Select
                    @bitnum   MST,5               ;Master Mode Select
                    @bitnum   IICIE,6             ;IIC Interrupt Enable
                    @bitnum   IICEN,7             ;IIC Enable

;*** IIC1S - IIC Status Register

                    @bitnum   RXAK,0              ;Receive Acknowledge
                    @bitnum   IICIF,1             ;IIC Interrupt Flag
                    @bitnum   SRW,2               ;Slave Read/Write
                    @bitnum   ARBL,4              ;Arbitration Lost
                    @bitnum   BUSY,5              ;Bus Busy
                    @bitnum   IAAS,6              ;Addressed as a Slave
                    @bitnum   TCF,7               ;Transfer Complete Flag

;*** IIC1C2 - IIC Control Register 2

                    @bitnum   AD8,0               ;Slave Address Bit 8
                    @bitnum   AD9,1               ;Slave Address Bit 9
                    @bitnum   AD10,2              ;Slave Address Bit 10
                    @bitnum   ADEXT,6             ;Address Extension
                    @bitnum   GCAEN,7             ;General Call Address Enable

;*** SRS - System Reset Status Register

                    @bitnum   LVD,1               ;Low Voltage Detect
                    @bitnum   ICG,2               ;Internal Clock Generation Module Reset
                    @bitnum   ILOP,4              ;Illegal Opcode
                    @bitnum   COP,5               ;Computer Operating Properly (COP) Watchdog
                    @bitnum   PIN,6               ;External Reset Pin
                    @bitnum   POR,7               ;Power-On Reset

;*** SBDFR - System Background Debug Force Reset Register

                    @bitnum   BDFR,0              ;Background Debug Force Reset

;*** SOPT - System Options Register

                    @bitnum   STOPE,5             ;Stop Mode Enable
                    @bitnum   COPT,6              ;COP Watchdog Timeout
                    @bitnum   COPE,7              ;COP Watchdog Enable

;*** SMCLK - System MCLK Control Register

                    @bitnum   MCSEL0,0            ;MCLK Divide Select, bit 0
                    @bitnum   MCSEL1,1            ;MCLK Divide Select, bit 1
                    @bitnum   MCSEL2,2            ;MCLK Divide Select, bit 2
                    @bitnum   MPE,4               ;MCLK Pin Enable

;*** SDIDH - System Device Identification Register High

                    @bitnum   ID8,0               ;Part Identification Number, bit 8
                    @bitnum   ID9,1               ;Part Identification Number, bit 9
                    @bitnum   ID10,2              ;Part Identification Number, bit 10
                    @bitnum   ID11,3              ;Part Identification Number, bit 11

;*** SRTISC - System Real-Time Interrupt Status and Control Register

                    @bitnum   RTIS0,0             ;Real-Time Interrupt Delay Selects, bit 0
                    @bitnum   RTIS1,1             ;Real-Time Interrupt Delay Selects, bit 1
                    @bitnum   RTIS2,2             ;Real-Time Interrupt Delay Selects, bit 2
                    @bitnum   RTIE,4              ;Real-Time Interrupt Enable
                    @bitnum   RTICLKS,5           ;Real-Time Interrupt Clock Select
                    @bitnum   RTIACK,6            ;Real-Time Interrupt Acknowledge
                    @bitnum   RTIF,7              ;Real-Time Interrupt Flag

;*** SPMSC1 - System Power Management Status and Control 1 Register

                    @bitnum   BGBE,0              ;Bandgap Buffer Enable
                    @bitnum   LVDE,2              ;Low-Voltage Detect Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detect Stop Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detect Reset Enable
                    @bitnum   LVDIE,5             ;Low-Voltage Detect Interrupt Enable
                    @bitnum   LVDACK,6            ;Low-Voltage Detect Acknowledge
                    @bitnum   LVDF,7              ;Low-Voltage Detect Flag

;*** SPMSC2 - System Power Management Status and Control 2 Register

                    @bitnum   PPDC,0              ;Partial Power Down Control
                    @bitnum   PPDACK,2            ;Partial Power Down Acknowledge
                    @bitnum   PPDF,3              ;Partial Power Down Flag
                    @bitnum   LVWV,4              ;Low-Voltage Warning Voltage Select
                    @bitnum   LVDV,5              ;Low-Voltage Detect Voltage Select
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVWF,7              ;Low-Voltage Warning Flag

;*** SOPT2 - System Options Register 2

                    @bitnum   TPMCCFG,3           ;TPM Clock Confguration
                    @bitnum   COPCLKS,7           ;COP Watchdog Clock Select

;*** DBGC - Debug Control Register

                    @bitnum   RWBEN,0             ;Enable R/W for Comparator B
                    @bitnum   RWB,1               ;R/W Comparison Value for Comparator B
                    @bitnum   RWAEN,2             ;Enable R/W for Comparator A
                    @bitnum   RWA,3               ;R/W Comparison Value for Comparator A
                    @bitnum   BRKEN,4             ;Break Enable
                    @bitnum   TAG,5               ;Tag/Force Select
                    @bitnum   ARM,6               ;Arm Control
                    @bitnum   DBGEN,7             ;Debug Module Enable

;*** DBGT - Debug Trigger Register

                    @bitnum   TRG0,0              ;Select Trigger Mode Bit 0
                    @bitnum   TRG1,1              ;Select Trigger Mode Bit 1
                    @bitnum   TRG2,2              ;Select Trigger Mode Bit 2
                    @bitnum   TRG3,3              ;Select Trigger Mode Bit 3
                    @bitnum   BEGIN,6             ;Begin/End Trigger Select
                    @bitnum   TRGSEL,7            ;Trigger Type

;*** DBGS - Debug Status Register

                    @bitnum   CNT0,0              ;FIFO Valid Count Bit 0
                    @bitnum   CNT1,1              ;FIFO Valid Count Bit 1
                    @bitnum   CNT2,2              ;FIFO Valid Count Bit 2
                    @bitnum   CNT3,3              ;FIFO Valid Count Bit 3
                    @bitnum   ARMF,5              ;Arm Flag
                    @bitnum   BF,6                ;Trigger Match B Flag
                    @bitnum   AF,7                ;Trigger Match A Flag

;*** FSTAT - Flash Status Register

                    @bitnum   FBLANK,2            ;FLASH Flag Indicating the Erase Verify Operation Status
                    @bitnum   FACCERR,4           ;FLASH Access Error Flag
                    @bitnum   FPVIOL,5            ;FLASH Protection Violation Flag
                    @bitnum   FCCF,6              ;FLASH Command Complete Interrupt Flag
                    @bitnum   FCBEF,7             ;FLASH Command Buffer Empty Flag

;*** NVPROT - Non-volatile FLASH Protection Register

                    @bitnum   FPDIS,0             ;FLASH Protection Disable
                    @bitnum   FPS1,1              ;FLASH Protect Select Bit 1
                    @bitnum   FPS2,2              ;FLASH Protect Select Bit 2
                    @bitnum   FPS3,3              ;FLASH Protect Select Bit 3
                    @bitnum   FPS4,4              ;FLASH Protect Select Bit 4
                    @bitnum   FPS5,5              ;FLASH Protect Select Bit 5
                    @bitnum   FPS6,6              ;FLASH Protect Select Bit 6
                    @bitnum   FPS7,7              ;FLASH Protect Select Bit 7

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08AC32_          def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       26                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       27                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1170                ;typical bandgap voltage in mV

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFC6               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

; Vectors
                    #temp     VECTORS
Vtpm3ovf            next      :temp,2             ;TPM3 overflow
Vtpm3ch1            next      :temp,2             ;TPM3 Channel 1
Vtpm3ch0            next      :temp,2             ;TPM3 Channel 0
Vrti                next      :temp,2
Viic                next      :temp,2             ;IIC vector
Vadc                next      :temp,2             ;A/D vector
Vkeyboard           next      :temp,2             ;Keyboard vector
Vsci2tx             next      :temp,2             ;SCI2 transmit vector
Vsci2rx             next      :temp,2             ;SCI2 receive vector
Vsci2err            next      :temp,2             ;SCI2 error vector
Vsci1tx             next      :temp,2             ;SCI1 transmit vector
Vsci1rx             next      :temp,2             ;SCI1 receive vector
Vsci1err            next      :temp,2             ;SCI1 error vector
Vspi                next      :temp,2             ;SPI1 vector
Vtpm2ovf            next      :temp,2             ;TPM2 overflow
Vtpm2ch1            next      :temp,2             ;TPM2 Channel 1
Vtpm2ch0            next      :temp,2             ;TPM2 Channel 0
Vtpm1ovf            next      :temp,2             ;TPM1 overflow
Vtpm1ch5            next      :temp,2             ;TPM1 Channel 5
Vtpm1ch4            next      :temp,2             ;TPM1 Channel 4
Vtpm1ch3            next      :temp,2             ;TPM1 Channel 3
Vtpm1ch2            next      :temp,2             ;TPM1 Channel 2
Vtpm1ch1            next      :temp,2             ;TPM1 Channel 1
Vtpm1ch0            next      :temp,2             ;TPM1 Channel 0
Vicg                next      :temp,2             ;Internal Clock Generator
Vlvd                next      :temp,2             ;Low voltage detect
Virq                next      :temp,2             ;IRQ vector
Vswi                next      :temp,2             ;SWI vector
Vreset              next      :temp,2             ;Reset vector

Vtpmovf             equ       Vtpm1ovf,::Vtpm1ovf
Vtpmch5             equ       Vtpm1ch5,::Vtpm1ch5
Vtpmch4             equ       Vtpm1ch4,::Vtpm1ch4
Vtpmch3             equ       Vtpm1ch3,::Vtpm1ch3
Vtpmch2             equ       Vtpm1ch2,::Vtpm1ch2
Vtpmch1             equ       Vtpm1ch1,::Vtpm1ch1
Vtpmch0             equ       Vtpm1ch0,::Vtpm1ch0

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
TRUE_ROM            equ       $8000               ;start of 32K Flash

EEPROM              def       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
  #ifnz FLASH_DATA_SIZE
                    #Error    FLASH_DATA_SIZE ({FLASH_DATA_SIZE}) is too large
  #endif
 #endif
#endif

ROM                 def       EEPROM_END+1
ROM_END             equ       $FF9F               ;end of all flash (before NV registers and fixed vectors)

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

          #if FLASH_DATA_SIZE = 32*512*2          ;32KB in 512-byte pages
?NVPROT_MASK        def       1
          #endif
?NVPROT_MASK        def       ROM-1&$FE00>8

RAM                 equ       $70                 ;start of 2KB RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $086F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 2KB fragmented RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ¦KHZ
HZ                  def       16777216            ;Cyclone 32768*512
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
