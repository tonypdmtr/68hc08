;*******************************************************************************
;*            MC9S08PA32 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08PA32 *
                    #Message  **********************

                    #HcsOn
                    #NoMMU                        ;MMU not available
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_pa32.exp
  #endif

#endif

_PA_                def       32
_PA32_              def       *

; ###################################################################
;     Filename  : mc9s08pa32.inc
;     Processor : MC9S08PA32VLD
;     FileFormat: V2.33
;     DataSheet : MC9S08PA32RM Rev. 2, 8/2014
;     Compiler  : CodeWarrior compiler
;     Date/Time : 2/2/2012, 4:50 PM
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;               - none
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

; Memory Map and Interrupt Vectors
;******************************************

PORTA               equ       $00,1               ;PORT_PTAD - Port A Data Register
PORTB               equ       $01,1               ;PORT_PTBD - Port B Data Register
PORTC               equ       $02,1               ;PORT_PTCD - Port C Data Register
PORTD               equ       $03,1               ;PORT_PTDD - Port D Data Register
PORTE               equ       $04,1               ;PORT_PTED - Port E Data Register

ADCSC1              equ       $10,1               ;ADC_SC1 - Status and Control Register 1

                    @bitnum   ADCO,5              ;Continuous Conversion Enable
                    @bitnum   AIEN,6              ;Interrupt Enable
                    @bitnum   COCO,7              ;Conversion Complete Flag

ADCSC2              equ       $11,1               ;ADC_SC2 - Status and Control Register 2

                    @bitnum   FFULL,2             ;Result FIFO full
                    @bitnum   FEMPTY,3            ;Result FIFO empty
                    @bitnum   ACFGT,4             ;Compare Function Greater Than Enable
                    @bitnum   ACFE,5              ;Compare Function Enable
                    @bitnum   ADTRG,6             ;Conversion Trigger Select
                    @bitnum   ADACT,7             ;Conversion Active

ADCCFG              equ       $12,1               ;ADC_SC3 - Status and Control Register 3

                    @bitnum   ADICLK0,0           ;Input Clock Select, bit 0
                    @bitnum   ADICLK1,1           ;Input Clock Select, bit 1
                    @bitnum   MODE0,2             ;Conversion Mode Selection, bit 0
                    @bitnum   MODE1,3             ;Conversion Mode Selection, bit 1
                    @bitnum   ADLSMP,4            ;Long Sample Time Configuration
                    @bitnum   ADIV0,5             ;Clock Divide Select, bit 0
                    @bitnum   ADIV1,6             ;Clock Divide Select, bit 1
                    @bitnum   ADLPC,7             ;Low-Power Configuration

ADC_SC4             equ       $13,1               ;Status and Control Register 4

                    @bitnum   AFDEP0,0            ;FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared,
                    @bitnum   AFDEP1,1            ;FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared,
                    @bitnum   AFDEP2,2            ;FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared,
                    @bitnum   ACFSEL,5            ;Compare function select OR/AND when the FIFO function is enabled (AFDEP > 0) .When this bit
                    @bitnum   ASCANE,6            ;FIFO Scan Mode Enable

ADCR                equ       $14,2               ;ADC_R - Data Result Register
ADCRH               equ       $14,1               ;ADC_RH - Conversion Result High Register
ADCRL               equ       $15,1               ;ADC_RL - Conversion Result Low Register

ADCCV               equ       $16,2               ;ADC_CV - Compare Value Register
ADCCVH              equ       $16,1               ;ADC_CVH - Compare Value High Register
ADCCVL              equ       $17,1               ;ADC_CVL - Compare Value Low Register

MTIMSC              equ       $18,1               ;MTIM0_SC - MTIM Status and Control Register

                    @bitnum   MTIM_TSTP,4         ;MTIM Counter Stop
                    @bitnum   MTIM_TRST,5         ;MTIM Counter Reset
                    @bitnum   MTIM_TOIE,6         ;MTIM Overflow Interrupt Enable
                    @bitnum   MTIM_TOF,7          ;MTIM Overflow Flag

MTIMCLK             equ       $19,1               ;MTIM0_CLK - MTIM Clock Configuration Register

                    @bitnum   MTIM_PS0,0          ;Clock Source Prescaler, bit 0
                    @bitnum   MTIM_PS1,1          ;Clock Source Prescaler, bit 1
                    @bitnum   MTIM_PS2,2          ;Clock Source Prescaler, bit 2
                    @bitnum   MTIM_PS3,3          ;Clock Source Prescaler, bit 3
                    @bitnum   MTIM_CLKS0,4        ;Clock Source Select, bit 0
                    @bitnum   MTIM_CLKS1,5        ;Clock Source Select, bit 1

MTIMCNT             equ       $1A,1               ;MTIM0_CNT - MTIM Counter Register
MTIMMOD             equ       $1B,1               ;MTIM0_MOD - MTIM Modulo Register

FTM0_SC             equ       $20,1               ;Status and Control

                    @bitnum   PS0,0               ;Prescale Factor Selection, bit 0
                    @bitnum   PS1,1               ;Prescale Factor Selection, bit 1
                    @bitnum   PS2,2               ;Prescale Factor Selection, bit 2
                    @bitnum   CLKS0,3             ;Clock Source Selection, bit 0
                    @bitnum   CLKS1,4             ;Clock Source Selection, bit 1
                    @bitnum   CPWMS,5             ;Center-aligned PWM Select
                    @bitnum   TOIE,6              ;Timer Overflow Interrupt Enable
                    @bitnum   TOF,7               ;Timer Overflow Flag

FTM0_CNT            equ       $21,2               ;FTM0 Timer Counter Register
FTM0_CNTH           equ       $21,1               ;Counter High
FTM0_CNTL           equ       $22,1               ;Counter Low
FTM0_MOD            equ       $23,2               ;FTM0 Timer Counter Modulo Register
FTM0_MODH           equ       $23,1               ;Modulo High
FTM0_MODL           equ       $24,1               ;Modulo Low
FTM0_C0SC           equ       $25,1               ;Channel Status and Control
FTM0_C0V            equ       $26,2               ;FTM0 Timer Channel 0 Value Register
FTM0_C0VH           equ       $26,1               ;Channel Value High
FTM0_C0VL           equ       $27,1               ;Channel Value Low
FTM0_C1SC           equ       $28,1               ;Channel Status and Control
FTM0_C1V            equ       $29,2               ;FTM0 Timer Channel 1 Value Register
FTM0_C1VH           equ       $29,1               ;Channel Value High
FTM0_C1VL           equ       $2A,1               ;Channel Value Low

                    @bitnum   ELSA,2              ;Edge or Level Select
                    @bitnum   ELSB,3              ;Edge or Level Select
                    @bitnum   MSA,4               ;Channel Mode Select
                    @bitnum   MSB,5               ;Channel Mode Select
                    @bitnum   CHIE,6              ;Channel Interrupt Enable
                    @bitnum   CHF,7               ;Channel Flag

TPM0SC              equ       FTM0_SC,::FTM0_SC
TPM0CNT             equ       FTM0_CNT,::FTM0_CNT
TPM0CNTH            equ       FTM0_CNTH,::FTM0_CNTH
TPM0CNTL            equ       FTM0_CNTL,::FTM0_CNTL
TPM0MOD             equ       FTM0_MOD,::FTM0_MOD
TPM0MODH            equ       FTM0_MODH,::FTM0_MODH
TPM0MODL            equ       FTM0_MODL,::FTM0_MODL
TPM0C0SC            equ       FTM0_C0SC,::FTM0_C0SC
TPM0C0V             equ       FTM0_C0V,::FTM0_C0V
TPM0C0VH            equ       FTM0_C0VH,::FTM0_C0VH
TPM0C0VL            equ       FTM0_C0VL,::FTM0_C0VL
TPM0C1SC            equ       FTM0_C1SC,::FTM0_C1SC
TPM0C1V             equ       FTM0_C1V,::FTM0_C1V
TPM0C1VH            equ       FTM0_C1VH,::FTM0_C1VH
TPM0C1VL            equ       FTM0_C1VL,::FTM0_C1VL

FTM1_SC             equ       $30,1               ; FTM1_SC - Status and Control
FTM1_CNT            equ       $31,2               ; FTM1_CNT - FTM1 Timer Counter Register
FTM1_CNTH           equ       $31,1               ; FTM1_CNTH - Counter High
FTM1_CNTL           equ       $32,1               ; FTM1_CNTL - Counter Low
FTM1_MOD            equ       $33,2               ; FTM1_MOD - FTM1 Timer Counter Modulo Register
FTM1_MODH           equ       $33,1               ; FTM1_MODH - Modulo High
FTM1_MODL           equ       $34,1               ; FTM1_MODL - Modulo Low
FTM1_C0SC           equ       $35,1               ; FTM1_C0SC - Channel Status and Control
FTM1_C0V            equ       $36,2               ; FTM1_C0V - FTM1 Timer Channel 0 Value Register
FTM1_C0VH           equ       $36,1               ; FTM1_C0VH - Channel Value High
FTM1_C0VL           equ       $37,1               ; FTM1_C0VL - Channel Value Low
FTM1_C1SC           equ       $38,1               ; FTM1_C1SC - Channel Status and Control
FTM1_C1V            equ       $39,2               ; FTM1_C1V - FTM1 Timer Channel 1 Value Register
FTM1_C1VH           equ       $39,1               ; FTM1_C1VH - Channel Value High
FTM1_C1VL           equ       $3A,1               ; FTM1_C1VL - Channel Value Low

TPM1SC              equ       FTM1_SC,::FTM1_SC
TPM1CNT             equ       FTM1_CNT,::FTM1_CNT
TPM1CNTH            equ       FTM1_CNTH,::FTM1_CNTH
TPM1CNTL            equ       FTM1_CNTL,::FTM1_CNTL
TPM1MOD             equ       FTM1_MOD,::FTM1_MOD
TPM1MODH            equ       FTM1_MODH,::FTM1_MODH
TPM1MODL            equ       FTM1_MODL,::FTM1_MODL
TPM1C0SC            equ       FTM1_C0SC,::FTM1_C0SC
TPM1C0V             equ       FTM1_C0V,::FTM1_C0V
TPM1C0VH            equ       FTM1_C0VH,::FTM1_C0VH
TPM1C0VL            equ       FTM1_C0VL,::FTM1_C0VL
TPM1C1SC            equ       FTM1_C1SC,::FTM1_C1SC
TPM1C1V             equ       FTM1_C1V,::FTM1_C1V
TPM1C1VH            equ       FTM1_C1VH,::FTM1_C1VH
TPM1C1VL            equ       FTM1_C1VL,::FTM1_C1VL

ACMP_CS             equ       $2C,1               ;ACMP Control and Status Register

                    @bitnum   ACMOD0,0            ;ACMP MOD, bit 0
                    @bitnum   ACMOD1,1            ;ACMP MOD, bit 1
                    @bitnum   ACOPE,2             ;ACMP Output Pin Enable
                    @bitnum   ACO,3               ;ACMP Output
                    @bitnum   ACIE,4              ;ACMP Interrupt Enable
                    @bitnum   ACF,5               ;ACMP Interrupt Flag Bit
                    @bitnum   HYST,6              ;Analoy Comparator Hystersis Selection
                    @bitnum   ACE,7               ;Analog Comparator Enable

ACMP_C0             equ       $2D,1               ;ACMP Control Register 0

                    @bitnum   ACNSEL0,0           ;ACMP Negative Input Select, bit 0
                    @bitnum   ACNSEL1,1           ;ACMP Negative Input Select, bit 1
                    @bitnum   ACPSEL0,4           ;ACMP Positive Input Select, bit 0
                    @bitnum   ACPSEL1,5           ;ACMP Positive Input Select, bit 1

ACMP_C1             equ       $2E,1               ;ACMP Control Register 1

                    @bitnum   DACVAL0,0           ;DAC Output Level Selection, bit 0
                    @bitnum   DACVAL1,1           ;DAC Output Level Selection, bit 1
                    @bitnum   DACVAL2,2           ;DAC Output Level Selection, bit 2
                    @bitnum   DACVAL3,3           ;DAC Output Level Selection, bit 3
                    @bitnum   DACVAL4,4           ;DAC Output Level Selection, bit 4
                    @bitnum   DACVAL5,5           ;DAC Output Level Selection, bit 5
                    @bitnum   DACREF,6            ;DAC Reference Select
                    @bitnum   DACEN,7             ;DAC Enable

ACMP_C2             equ       $2F,1               ;ACMP Control Register 2

                    @bitnum   ACIPE0,0
                    @bitnum   ACIPE1,1
                    @bitnum   ACIPE2,2

IRQSC               equ       $3B,1               ;IRQ_SC - Interrupt Pin Request Status and Control Register

                    @bitnum   IRQMOD,0            ;IRQ Detection Mode
                    @bitnum   IRQIE,1             ;IRQ Interrupt Enable
                    @bitnum   IRQACK,2            ;IRQ Acknowledge
                    @bitnum   IRQF,3              ;IRQ Flag
                    @bitnum   IRQPE,4             ;IRQ Pin Enable
                    @bitnum   IRQEDG,5            ;Interrupt Request (IRQ) Edge Select
                    @bitnum   IRQPDD,6            ;Interrupt Request (IRQ) Pull Device Disable

KBI0_SC             equ       $3C,1               ;KBI0_SC - KBI Status and Control Register
KBI1_SC             equ       $3D,1               ;KBI1_SC - KBI Status and Control Register

KBISC               equ       KBI0_SC,1           ;KBI0_SC - KBI Status and Control Register
KBI2SC              equ       KBI1_SC,1           ;KBI1_SC - KBI Status and Control Register

                    @bitnum   KBMOD,0             ;KBI Detection Mode
                    @bitnum   KBIE,1              ;KBI Interrupt Enable
                    @bitnum   KBACK,2             ;KBI Acknowledge
                    @bitnum   KBF,3               ;KBI Interrupt Flag

IPC_SC              equ       $3E,1               ;IPC Status and Control Register

                    @bitnum   IPM0,0              ;Interrupt Priority Mask, bit 0
                    @bitnum   IPM1,1              ;Interrupt Priority Mask, bit 1
                    @bitnum   PULIPM,3            ;Pull IPM from IPMPS
                    @bitnum   PSF,4               ;Pseudo Stack Full
                    @bitnum   PSE,5               ;Pseudo Stack Empty
                    @bitnum   IPCE,7              ;Interrupt Priority Controller Enable

IPC_IPMPS           equ       $3F,1               ;Interrupt Priority Mask Pseudo Stack Register

                    @bitnum   IPM00,0             ;Interrupt Priority Mask pseudo stack position 0, bit 0
                    @bitnum   IPM01,1             ;Interrupt Priority Mask pseudo stack position 0, bit 1
                    @bitnum   IPM10,2             ;Interrupt Priority Mask pseudo stack position 1, bit 0
                    @bitnum   IPM11,3             ;Interrupt Priority Mask pseudo stack position 1, bit 1
                    @bitnum   IPM20,4             ;Interrupt Priority Mask pseudo stack position 2, bit 0
                    @bitnum   IPM21,5             ;Interrupt Priority Mask pseudo stack position 2, bit 1
                    @bitnum   IPM30,6             ;Interrupt Priority Mask pseudo stack position 3, bit 0
                    @bitnum   IPM31,7             ;Interrupt Priority Mask pseudo stack position 3, bit 1

SRS                 equ       $3000,1             ;SYS_SRS - System Reset Status Register

                    @bitnum   LVD,1               ;Low Voltage Detect
                    @bitnum   LOC,2               ;Internal Clock Source Module Reset
                    @bitnum   ILAD,3              ;Illegal Address
                    @bitnum   ILOP,4              ;Illegal Opcode
                    @bitnum   WDOG,5              ;Watchdog (WDOG)
                    @bitnum   PIN,6               ;External Reset Pin
                    @bitnum   POR,7               ;Power-On Reset

SBDFR               equ       $3001,1             ;SYS_SBDFR - System Background Debug Force Reset Register

                    @bitnum   BDFR,0              ;Background Debug Force Reset

SYS_SDID            equ       $3002,2             ;System Device Identification Register
SYS_SDIDH           equ       $3002,1             ;System Device Identification Register: High
SYS_SDIDL           equ       $3003,1             ;System Device Identification Register: Low

SYS_SOPT1           equ       $3004,1             ;System Options Register 1

                    @bitnum   STOPE,0             ;Stop Mode Enable
                    @bitnum   FWAKE,1             ;Fast Wakeup Enable
                    @bitnum   RSTPE,2             ;RESET Pin Enable
                    @bitnum   BKGDPE,3            ;Background Debug Mode Pin Enable
                    @bitnum   FTM2PS,4            ;FTM2 Port Pin Select
                    @bitnum   IICPS,5             ;IIC Port Pin Select
                    @bitnum   SPI0PS,6            ;SPI0 Pin Select
                    @bitnum   SCI0PS,7            ;SCI0 Pin Select

SYS_SOPT2           equ       $3005,1             ;System Options Register 2

                    @bitnum   ADHWTS0,0           ;ADC Hardware Trigger Source, bit 0
                    @bitnum   ADHWTS1,1           ;ADC Hardware Trigger Source, bit 1
                    @bitnum   RXDCE,4             ;SCI0 RxD Capture Select
                    @bitnum   RXDFE,5             ;SCI0 RxD Filter Select
                    @bitnum   FTMSYNC,6           ;FTM2 Synchronization Select
                    @bitnum   TXDME,7             ;SCI0 TxD Modulation Select

SYS_SOPT3           equ       $3006,1             ;System Options Register 3

                    @bitnum   BUSREF0,0           ;BUS Output select, bit 0
                    @bitnum   BUSREF1,1           ;BUS Output select, bit 1
                    @bitnum   BUSREF2,2           ;BUS Output select, bit 2
                    @bitnum   CLKOE,3             ;CLK Output Enable
                    @bitnum   FTM0PS,6            ;FTM0 Pin Select
                    @bitnum   DLYACT,7            ;FTM2 Trigger Delay Active

SYS_SOPT4           equ       $3007,1             ;System Options Register 4

SCG_C1              equ       $300C,1             ;System Clock Gating Control 1 Register

                    @bitnum   RTC,0               ;RTC Clock Gate Control
                    @bitnum   MTIM0,1             ;MTIM0 Clock Gate Control
                    @bitnum   FTM0,5              ;FTM0 Clock Gate Control
                    @bitnum   FTM1,6              ;FTM1 Clock Gate Control
                    @bitnum   FTM2,7              ;FTM2 Clock Gate Control

SCG_C2              equ       $300D,1             ;System Clock Gating Control 2 Register

                    @bitnum   SCG_CRC,2           ;CRC Clock Gate Control
                    @bitnum   SCG_IPC,3           ;IPC Clock Gate Control
                    @bitnum   SCG_NVM,4           ;NVM Clock Gate Control
                    @bitnum   SCG_DBG,5           ;DBG Clock Gate Control

SCG_C3              equ       $300E,1             ;System Clock Gating Control 3 Register

                    @bitnum   IIC,1               ;IIC Clock Gate Control
                    @bitnum   SPI0,2              ;SPI0 Clock Gate Control
                    @bitnum   SCI0,4              ;SCI0 Clock Gate Control
                    @bitnum   SCI1,5              ;SCI1 Clock Gate Control

SCG_C4              equ       $300F,1             ;System Clock Gating Control 4 Register

                    @bitnum   KBI0,0              ;KBI0 Clock Gate Control
                    @bitnum   IRQ,3               ;IRQ Clock Gate Control
                    @bitnum   ADC,5               ;ADC Clock Gate Control
                    @bitnum   ACMP,7              ;ACMP Clock Gate Control

DBG_CAH             equ       $3010,1             ;Debug Comparator A High Register
DBG_CAL             equ       $3011,1             ;Debug Comparator A Low Register
DBG_CBH             equ       $3012,1             ;Debug Comparator B High Register
DBG_CBL             equ       $3013,1             ;Debug Comparator B Low Register
DBG_CCH             equ       $3014,1             ;Debug Comparator C High Register
DBG_CCL             equ       $3015,1             ;Debug Comparator C Low Register
DBG_FH              equ       $3016,1             ;Debug FIFO High Register
DBG_FL              equ       $3017,1             ;Debug FIFO Low Register

DBG_CAX             equ       $3018,1             ;Debug Comparator A Extension Register

                    @bitnum   RWA,6               ;Read/Write Comparator A Value Bit
                    @bitnum   RWAEN,7             ;Read/Write Comparator A Enable Bit

DBG_CBX             equ       $3019,1             ;Debug Comparator B Extension Register

                    @bitnum   RWB,6               ;Read/Write Comparator B Value Bit
                    @bitnum   RWBEN,7             ;Read/Write Comparator B Enable Bit

DBG_CCX             equ       $301A,1             ;Debug Comparator C Extension Register

                    @bitnum   RWC,6               ;Read/Write Comparator C Value Bit
                    @bitnum   RWCEN,7             ;Read/Write Comparator C Enable Bit

DBG_FX              equ       $301B,1             ;Debug FIFO Extended Information Register

                    @bitnum   Bit16,0             ;Extended Address Bit 16
                    @bitnum   PPACC,7             ;PPAGE Access Indicator Bit

DBG_C               equ       $301C,1             ;Debug Control Register

                    @bitnum   LOOP1,0             ;Select LOOP1 Capture Mode
                    @bitnum   BRKEN,4             ;Break Enable Bit
                    @bitnum   TAG,5               ;Tag or Force Bit
                    @bitnum   ARM,6               ;Arm Bit
                    @bitnum   DBGEN,7             ;DBG Module Enable Bit

DBG_T               equ       $301D,1             ;Debug Trigger Register

                    @bitnum   TRG0,0              ;Trigger Mode Bits, bit 0
                    @bitnum   TRG1,1              ;Trigger Mode Bits, bit 1
                    @bitnum   TRG2,2              ;Trigger Mode Bits, bit 2
                    @bitnum   TRG3,3              ;Trigger Mode Bits, bit 3
                    @bitnum   BEGIN,6             ;Begin/End Trigger Bit
                    @bitnum   TRGSEL,7            ;Trigger Selection Bit

DBG_S               equ       $301E,1             ;Debug Status Register

                    @bitnum   ARMF,0              ;Arm Flag Bit
                    @bitnum   CF,5                ;Trigger C Match Bit
                    @bitnum   BF,6                ;Trigger B Match Bit
                    @bitnum   AF,7                ;Trigger A Match Bit

DBG_CNT             equ       $301F,1             ;Debug Count Status Register

                    @bitnum   CNT,0               ;FIFO Valid Count Bitss

NVM_BASE            equ       $3020               ;NVM register base
NVM_FCLKDIV         equ       $3020,1             ;NVM_FCLKDIV - Flash Clock Divider Register

                    @bitnum   FDIV0,0             ;Clock Divider Bits, bit 0
                    @bitnum   FDIV1,1             ;Clock Divider Bits, bit 1
                    @bitnum   FDIV2,2             ;Clock Divider Bits, bit 2
                    @bitnum   FDIV3,3             ;Clock Divider Bits, bit 3
                    @bitnum   FDIV4,4             ;Clock Divider Bits, bit 4
                    @bitnum   FDIV5,5             ;Clock Divider Bits, bit 5
                    @bitnum   FDIVLCK,6           ;Clock Divider Locked
                    @bitnum   FDIVLD,7            ;Clock Divider Loaded

NVM_FSEC            equ       $3021,1             ;Flash Security Register
NVM_FCCOBIX         equ       $3022,1             ;Flash CCOB Index Register
NVM_FCNFG           equ       $3024,1             ;Flash Configuration Register

                    @bitnum   FSFD,0              ;Force Single Bit Fault Detect
                    @bitnum   FDFD,1              ;Force Double Bit Fault Detect
                    @bitnum   IGNSF,4             ;Ignore Single Bit Fault
                    @bitnum   CCIE,7              ;Command Complete Interrupt Enable

NVM_FERCNFG         equ       $3025,1             ;Flash Error Configuration Register

                    @bitnum   SFDIE,0             ;Single Bit Fault Detect Interrupt Enable
                    @bitnum   DFDIE,1             ;Double Bit Fault Detect Interrupt Enable

NVM_FSTAT           equ       $3026,1             ;Flash Status Register

                    @bitnum   MGSTAT0,0
                    @bitnum   MGSTAT1,1
                    @bitnum   MGBUSY,3            ;Memory Controller Busy Flag
                    @bitnum   FPVIOL,4            ;Flash Protection Violation Flag
                    @bitnum   FACCERR,5           ;Flash Access Error Flag
                    @bitnum   CCIF,7              ;Command Complete Interrupt Flag

NVM_FERSTAT         equ       $3027,1             ;Flash Error Status Register

                    @bitnum   SFDIF,0             ;Single Bit Fault Detect Interrupt Flag
                    @bitnum   DFDIF,1             ;Double Bit Fault Detect Interrupt Flag

NVM_FPROT           equ       $3028,1             ;Flash Protection Register

                    @bitnum   FPHS0,3
                    @bitnum   FPHS1,4
                    @bitnum   FPHDIS,5            ;Flash Protection Higher Address Range Disable
                    @bitnum   FPOPEN,7            ;Flash Protection Operation Enable

NVM_EEPROT          equ       $3029,1             ;EEPROM Protection Register

                    @bitnum   DPS0,0              ;EEPROM Protection Size, bit 0
                    @bitnum   DPS1,1              ;EEPROM Protection Size, bit 1
                    @bitnum   DPS2,2              ;EEPROM Protection Size, bit 2
                    @bitnum   DPOPEN,7            ;EEPROM Protection Control

NVM_FCCOB           equ       $302A,2             ;Flash Common Command Object Register
NVM_FCCOBHI         equ       $302A,1             ;Flash Common Command Object Register:High
NVM_FCCOBLO         equ       $302B,1             ;Flash Common Command Object Register: Low

NVM_FOPT            equ       $302C,1             ;Flash Option Register

WDOG_CS1            equ       $3030,1             ;Watchdog Control and Status Register 1

                    @bitnum   WDOG_STOP,0         ;Stop Enable
                    @bitnum   WDOG_WAIT,1         ;Wait Enable
                    @bitnum   WDOG_DBG,2          ;Debug Enable
                    @bitnum   WDOG_TST0,3         ;Watchdog Test, bit 0
                    @bitnum   WDOG_TST1,4         ;Watchdog Test, bit 1
                    @bitnum   WDOG_UPDATE,5       ;Allow updates
                    @bitnum   WDOG_INT,6          ;Watchdog Interrupt
                    @bitnum   WDOG_EN,7           ;Watchdog Enable

WDOG_CS2            equ       $3031,1             ;Watchdog Control and Status Register 2

                    @bitnum   WDOG_CLK0,0         ;Watchdog Clock, bit 0
                    @bitnum   WDOG_CLK1,1         ;Watchdog Clock, bit 1
                    @bitnum   WDOG_PRES,4         ;Watchdog Prescalar
                    @bitnum   WDOG_FLG,6          ;Watchdog Interrupt Flag
                    @bitnum   WDOG_WIN,7          ;Watchdog Window

WDOG_CNT            equ       $3032,2             ;Watchdog Counter Register
WDOG_CNTH           equ       $3032,1             ;Watchdog Counter Register: High
WDOG_CNTL           equ       $3033,1             ;Watchdog Counter Register: Low
WDOG_TOVAL          equ       $3034,2             ;Watchdog Timer Register
WDOG_TOVALH         equ       $3034,1             ;Watchdog Timeout Value Register: High
WDOG_TOVALL         equ       $3035,1             ;Watchdog Timeout Value Register: Low
WDOG_WIN            equ       $3036,2             ;Watchdog Window Register
WDOG_WINH           equ       $3036,1             ;Watchdog Window Register: High
WDOG_WINL           equ       $3037,1             ;Watchdog Window Register: Low

ICSC1               equ       $3038,1             ;ICS_C1 - ICS Control Register 1

                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   ICS_RDIV0,3         ;Reference Divider, bit 0
                    @bitnum   ICS_RDIV1,4         ;Reference Divider, bit 1
                    @bitnum   ICS_RDIV2,5         ;Reference Divider, bit 2
                    @bitnum   ICS_CLKS0,6         ;Clock Source Select, bit 0
                    @bitnum   ICS_CLKS1,7         ;Clock Source Select, bit 1

ICS_C2              equ       $3039,1             ;ICS Control Register 2

                    @bitnum   LP,4                ;Low Power Select
                    @bitnum   BDIV0,5             ;Bus Frequency Divider, bit 0
                    @bitnum   BDIV1,6             ;Bus Frequency Divider, bit 1
                    @bitnum   BDIV2,7             ;Bus Frequency Divider, bit 2

ICS_C3              equ       $303A,1             ;ICS Control Register 3
ICS_C4              equ       $303B,1             ;ICS Control Register 4

                    @bitnum   SCFTRIM,0           ;Slow Internal Reference Clock Fine Trim
                    @bitnum   CME,5               ;Clock Monitor Enable
                    @bitnum   LOLIE,7             ;Loss of Lock Interrupt

ICS_S               equ       $303C,1             ;ICS Status Register

                    @bitnum   CLKST0,2            ;Clock Mode Status, bit 0
                    @bitnum   CLKST1,3            ;Clock Mode Status, bit 1
                    @bitnum   IREFST,4            ;Internal Reference Status
                    @bitnum   LOCK,6              ;Lock Status
                    @bitnum   LOLS,7              ;Loss of Lock Status

ICS_OSCSC           equ       $303E,1             ;OSC Status and Control Register

                    @bitnum   OSCINIT,0           ;OSC Initialization
                    @bitnum   HGO,1               ;High Gain Oscillator Select
                    @bitnum   RANGE_SEL,2         ;Frequency Range Select
                    @bitnum   OSCOS,4             ;OSC Output Select
                    @bitnum   OSCSTEN,5           ;OSC Enable in Stop mode
                    @bitnum   OSCEN,7             ;OSC Enable

SPMSC1              equ       $3040,1             ;PMC_SPMSC1 - System Power Management Status and Control 1 Register

                    @bitnum   BGBE,0              ;Bandgap Buffer Enable
                    @bitnum   BGBDS,1             ;Bandgap Buffer Drive Select
                    @bitnum   LVDE,2              ;Low-Voltage Detect Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detect Stop Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detect Reset Enable
                    @bitnum   LVWIE,5             ;Low-Voltage Warning Interrupt Enable
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVWF,7              ;Low-Voltage Warning Flag

PMC_SPMSC2          equ       $3041,1             ;System Power Management Status and Control 2 Register

                    @bitnum   LVWV0,4             ;Low-Voltage Warning Voltage Select, bit 0
                    @bitnum   LVWV1,5             ;Low-Voltage Warning Voltage Select, bit 1
                    @bitnum   LVDV,6              ;Low-Voltage Detect Voltage Select

SYS_ILLA            equ       $304A,2             ;Illegal Address Register
SYS_ILLAH           equ       $304A,1             ;Illegal Address Register: High
SYS_ILLAL           equ       $304B,1             ;Illegal Address Register: Low

IPC_ILRS0           equ       $3050,1             ;Interrupt Level Setting Registers n
IPC_ILRS1           equ       $3051,1             ;Interrupt Level Setting Registers n
IPC_ILRS2           equ       $3052,1             ;Interrupt Level Setting Registers n
IPC_ILRS3           equ       $3053,1             ;Interrupt Level Setting Registers n
IPC_ILRS4           equ       $3054,1             ;Interrupt Level Setting Registers n
IPC_ILRS5           equ       $3055,1             ;Interrupt Level Setting Registers n
IPC_ILRS6           equ       $3056,1             ;Interrupt Level Setting Registers n
IPC_ILRS7           equ       $3057,1             ;Interrupt Level Setting Registers n
IPC_ILRS8           equ       $3058,1             ;Interrupt Level Setting Registers n
IPC_ILRS9           equ       $3059,1             ;Interrupt Level Setting Registers n

                    @bitnum   ILRn00,0            ;Interrupt Level Register for Source n+0, bit 0
                    @bitnum   ILRn01,1            ;Interrupt Level Register for Source n+0, bit 1
                    @bitnum   ILRn10,2            ;Interrupt Level Register for Source n+1, bit 0
                    @bitnum   ILRn11,3            ;Interrupt Level Register for Source n+1, bit 1
                    @bitnum   ILRn20,4            ;Interrupt Level Register for Source n+2, bit 0
                    @bitnum   ILRn21,5            ;Interrupt Level Register for Source n+2, bit 1
                    @bitnum   ILRn30,6            ;Interrupt Level Register for Source n+3, bit 0
                    @bitnum   ILRn31,7            ;Interrupt Level Register for Source n+3, bit 1

CRC_D0D1            equ       $3060,2             ;CRC_D0D1 register
CRC_D0              equ       $3060,1             ;CRC Data 0 Register
CRC_D1              equ       $3061,1             ;CRC Data 1 Register
CRC_D2D3            equ       $3062,2             ;CRC_D2D3 register
CRC_D2              equ       $3062,1             ;CRC Data 2 Register
CRC_D3              equ       $3063,1             ;CRC Data 3 Register
CRC_P0P1            equ       $3064,2             ;CRC_P0P1 register
CRC_P0              equ       $3064,1             ;CRC Polynomial 0 Register
CRC_P1              equ       $3065,1             ;CRC Polynomial 1 Register
CRC_P2P3            equ       $3066,2             ;CRC_P2P3 register
CRC_P2              equ       $3066,1             ;CRC Polynomial 2 Register
CRC_P3              equ       $3067,1             ;CRC Polynomial 3 Register
CRC_CTRL            equ       $3068,1             ;CRC Control Register

                    @bitnum   TCRC,0              ;Width of Polynomial Generator
                    @bitnum   WAS,1               ;Write CRC data register as seed
                    @bitnum   FXOR,2              ;Complement of Read
                    @bitnum   TOTR0,4             ;Reverse of Read, bit 0
                    @bitnum   TOTR1,5             ;Reverse of Read, bit 1
                    @bitnum   TOT0,6              ;Reverse of Write, bit 0
                    @bitnum   TOT1,7              ;Reverse of Write, bit 1

RTC_SC1             equ       $306A,1             ;RTC Status and Control Register 1

                    @bitnum   RTIE,6              ;Real-Time Interrupt Enable
                    @bitnum   RTIF,7              ;Real-Time Interrupt Flag

RTC_SC2             equ       $306B,1             ;RTC Status and Control Register 2

                    @bitnum   RTCPS0,0            ;Real-Time Clock Prescaler Select, bit 0
                    @bitnum   RTCPS1,1            ;Real-Time Clock Prescaler Select, bit 1
                    @bitnum   RTCPS2,2            ;Real-Time Clock Prescaler Select, bit 2
                    @bitnum   RTCLKS0,6           ;Real-Time Clock Source Select, bit 0
                    @bitnum   RTCLKS1,7           ;Real-Time Clock Source Select, bit 1

RTC_MOD             equ       $306C,2             ;RTC Modulo Register
RTC_MODH            equ       $306C,1             ;RTC Modulo Register: High
RTC_MODL            equ       $306D,1             ;RTC Modulo Register: Low
RTC_CNT             equ       $306E,2             ;RTC Counter Register
RTC_CNTH            equ       $306E,1             ;RTC Counter Register: High
RTC_CNTL            equ       $306F,1             ;RTC Counter Register: Low

I2C_A1              equ       $3070,1             ;I2C Address Register 1
IIC1A               equ       I2C_A1,1
IICA                equ       I2C_A1,1

I2C_F               equ       $3071,1             ;I2C Frequency Divider register
IIC1F               equ       I2C_F,1
IICF                equ       I2C_F,1

                    @bitnum   ICR0,0              ;Clock rate, bit 0
                    @bitnum   ICR1,1              ;Clock rate, bit 1
                    @bitnum   ICR2,2              ;Clock rate, bit 2
                    @bitnum   ICR3,3              ;Clock rate, bit 3
                    @bitnum   ICR4,4              ;Clock rate, bit 4
                    @bitnum   ICR5,5              ;Clock rate, bit 5
                    @bitnum   MULT0,6             ;The MULT bits define the multiplier factor mul. This factor is used along with the SCL
                    @bitnum   MULT1,7             ;The MULT bits define the multiplier factor mul. This factor is used along with the SCL

I2C_C1              equ       $3072,1             ;I2C Control Register 1
IIC1C1              equ       I2C_C1,1
IICC                equ       I2C_C1,1

                    @bitnum   WUEN,1              ;Wakeup enable
                    @bitnum   RSTA,2              ;Repeat START
                    @bitnum   TXAK,3              ;Transmit acknowledge enable
                    @bitnum   TX,4                ;Transmit mode select
                    @bitnum   MST,5               ;Master mode select
                    @bitnum   IICIE,6             ;I2C interrupt enable
                    @bitnum   IICEN,7             ;I2C enable

I2C_S               equ       $3073,1             ;I2C Status Register
IIC1S               equ       I2C_S,1
IICS                equ       I2C_S,1

                    @bitnum   RXAK,0              ;Receive acknowledge
                    @bitnum   IICIF,1             ;Interrupt flag
                    @bitnum   SRW,2               ;Slave read/write
                    @bitnum   RAM,3               ;Range address match
                    @bitnum   ARBL,4              ;Arbitration lost
                    @bitnum   BUSY,5              ;Bus busy
                    @bitnum   IAAS,6              ;Addressed as a slave
                    @bitnum   TCF,7               ;Transfer complete flag

I2C_D               equ       $3074,1             ;I2C Data I/O register
IIC1D               equ       I2C_D,1
IICD                equ       I2C_D,1

I2C_C2              equ       $3075,1             ;I2C Control Register 2
IIC1C2              equ       I2C_C2,1

                    @bitnum   AD8,0
                    @bitnum   AD9,1
                    @bitnum   AD10,2
                    @bitnum   RMEN,3              ;Range address matching enable
                    @bitnum   SBRC,4              ;Slave baud rate control
                    @bitnum   HDRS,5              ;High drive select
                    @bitnum   ADEXT,6             ;Address extension
                    @bitnum   GCAEN,7             ;General call address enable

I2C_FLT             equ       $3076,1             ;I2C Programmable Input Glitch Filter register
I2C_RA              equ       $3077,1             ;I2C Range Address register

                    @bitnum   I2C_RA_RAD0,1       ;Range slave address, bit 0
                    @bitnum   I2C_RA_RAD1,2       ;Range slave address, bit 1
                    @bitnum   I2C_RA_RAD2,3       ;Range slave address, bit 2
                    @bitnum   I2C_RA_RAD3,4       ;Range slave address, bit 3
                    @bitnum   I2C_RA_RAD4,5       ;Range slave address, bit 4
                    @bitnum   I2C_RA_RAD5,6       ;Range slave address, bit 5
                    @bitnum   I2C_RA_RAD6,7       ;Range slave address, bit 6

I2C_SMB             equ       $3078,1             ;I2C SMBus Control and Status register

                    @bitnum   SHTF2IE,0           ;SHTF2 interrupt enable
                    @bitnum   SHTF2,1             ;SCL high timeout flag 2
                    @bitnum   SHTF1,2             ;SCL high timeout flag 1
                    @bitnum   SLTF,3              ;SCL low timeout flag
                    @bitnum   TCKSEL,4            ;Timeout counter clock select
                    @bitnum   SIICAEN,5           ;Second I2C address enable
                    @bitnum   ALERTEN,6           ;SMBus alert response address enable
                    @bitnum   FACK,7              ;Fast NACK/ACK enable

I2C_A2              equ       $3079,1             ;I2C Address Register 2
I2C_SLT             equ       $307A,2             ;I2C SCL Low Timeout register
I2C_SLTH            equ       $307A,1             ;I2C SCL Low Timeout Register High
I2C_SLTL            equ       $307B,1             ;I2C SCL Low Timeout Register Low

KBI0_PE             equ       $307C,1             ;KBIx Pin Enable Register
KBI0_ES             equ       $307D,1             ;KBIx Edge Select Register

KBI1_PE             equ       $307E,1             ;KBIx Pin Enable Register
KBI1_ES             equ       $307F,1             ;KBIx Edge Select Register

SCIBD               equ       $3080,2             ;SCI0_BD  - SCI0 Baud Rate Register
SCIBDH              equ       $3080,1             ;SCI0_BDH - SCI Baud Rate Register: High
SCIBDL              equ       $3081,1             ;SCI0_BDL - SCI Baud Rate Register: Low
SCIC1               equ       $3082,1             ;SCI0_C1  - SCI Control Register 1

                    @bitnum   SBNS,5              ;Stop Bit Number Select
                    @bitnum   RXEDGIE,6           ;RxD Input Active Edge Interrupt Enable (for RXEDGIF)
                    @bitnum   LBKDIE,7            ;LIN Break Detect Interrupt Enable (for LBKDIF)

                    @bitnum   PT,0                ;Parity Type
                    @bitnum   PE,1                ;Parity Enable
                    @bitnum   ILT,2               ;Idle Line Type Select
                    @bitnum   WAKE,3              ;Receiver Wakeup Method Select
                    @bitnum   M,4                 ;9-Bit or 8-Bit Mode Select
                    @bitnum   RSRC,5              ;Receiver Source Select
                    @bitnum   SCISWAI,6           ;SCI Stops in Wait Mode
                    @bitnum   LOOPS,7             ;Loop Mode Select

SCIC2               equ       $3083,1             ;SCI0_C2 - SCI Control Register 2

                    @bitnum   SBK,0               ;Send Break
                    @bitnum   RWU,1               ;Receiver Wakeup Control
                    @bitnum   RE,2                ;Receiver Enable
                    @bitnum   TE,3                ;Transmitter Enable
                    @bitnum   ILIE,4              ;Idle Line Interrupt Enable for IDLE
                    @bitnum   RIE,5               ;Receiver Interrupt Enable for RDRF
                    @bitnum   TCIE,6              ;Transmission Complete Interrupt Enable for TC
                    @bitnum   TIE,7               ;Transmit Interrupt Enable for TDRE

SCIS1               equ       $3084,1             ;SCI0_S1 - SCI Status Register 1

                    @bitnum   PF,0                ;Parity Error Flag
                    @bitnum   FE,1                ;Framing Error Flag
                    @bitnum   NF,2                ;Noise Flag
                    @bitnum   OR,3                ;Receiver Overrun Flag
                    @bitnum   IDLE,4              ;Idle Line Flag
                    @bitnum   RDRF,5              ;Receive Data Register Full Flag
                    @bitnum   TC,6                ;Transmission Complete Flag
                    @bitnum   TDRE,7              ;Transmit Data Register Empty Flag

SCIS2               equ       $3085,1             ;SCI0_S2 - SCI Status Register 2

                    @bitnum   RAF,0               ;Receiver Active Flag
                    @bitnum   LBKDE,1             ;LIN Break Detection Enable
                    @bitnum   BRK13,2             ;Break Character Generation Length
                    @bitnum   RWUID,3             ;Receive Wake Up Idle Detect
                    @bitnum   RXINV,4             ;Receive Data Inversion
                    @bitnum   RXEDGIF,6           ;RxD Pin Active Edge Interrupt Flag
                    @bitnum   LBKDIF,7            ;LIN Break Detect Interrupt Flag

SCIC3               equ       $3086,1             ;SCI0_C3 - SCI Control Register 3

                    @bitnum   PEIE,0              ;Parity Error Interrupt Enable
                    @bitnum   FEIE,1              ;Framing Error Interrupt Enable
                    @bitnum   NEIE,2              ;Noise Error Interrupt Enable
                    @bitnum   ORIE,3              ;Overrun Interrupt Enable
                    @bitnum   TXINV,4             ;Transmit Data Inversion
                    @bitnum   TXDIR,5             ;TxD Pin Direction in Single-Wire Mode
                    @bitnum   T8,6                ;Ninth Data Bit for Transmitter
                    @bitnum   R8,7                ;Ninth Data Bit for Receiver

SCID                equ       $3087,1             ;SCI0_D - SCI Data Register

SCI2BD              equ       $3088,2             ;SCI1_BD  - SCI2 Baud Rate Register
SCI2BDH             equ       $3088,1             ;SCI1_BDH - SCI2 Baud Rate Register: High
SCI2BDL             equ       $3089,1             ;SCI1_BDL - SCI2 Baud Rate Register: Low
SCI2C1              equ       $308A,1             ;SCI1_C1  - SCI2 Control Register 1
SCI2C2              equ       $308B,1             ;SCI1_C2  - SCI2 Control Register 2
SCI2S1              equ       $308C,1             ;SCI1_S1  - SCI2 Status Register 1
SCI2S2              equ       $308D,1             ;SCI1_S2  - SCI2 Status Register 2
SCI2C3              equ       $308E,1             ;SCI1_C3  - SCI2 Control Register 3
SCI2D               equ       $308F,1             ;SCI1_D   - SCI2 Data Register

SPI0_C1             equ       $3098,1             ;SPI control register 1

                    @bitnum   LSBFE,0             ;LSB first (shifter direction)
                    @bitnum   SSOE,1              ;Slave select output enable
                    @bitnum   CPHA,2              ;Clock phase
                    @bitnum   CPOL,3              ;Clock polarity
                    @bitnum   MSTR,4              ;Master/slave mode select
                    @bitnum   SPTIE,5             ;SPI transmit interrupt enable
                    @bitnum   SPE,6               ;SPI system enable
                    @bitnum   SPIE,7              ;SPI interrupt enable: for SPRF and MODF

SPI0_C2             equ       $3099,1             ;SPI control register 2

                    @bitnum   SPC0,0              ;SPI pin control 0
                    @bitnum   SPISWAI,1           ;SPI stop in wait mode
                    @bitnum   BIDIROE,3           ;Bidirectional mode output enable
                    @bitnum   MODFEN,4            ;Master mode-fault function enable
                    @bitnum   SPMIE,7             ;SPI match interrupt enable

SPI0_BR             equ       $309A,1             ;SPI baud rate register
SPI0_S              equ       $309B,1             ;SPI status register
SPIS                equ       SPI0_S              ;alias for QE compatibility

                    @bitnum   MODF,4              ;Master mode fault flag
                    @bitnum   SPTEF,5             ;SPI transmit buffer empty flag
                    @bitnum   SPMF,6              ;SPI match flag
                    @bitnum   SPRF,7              ;SPI read buffer full flag

SPI0_D              equ       $309D,1             ;SPI data register
SPI0_M              equ       $309F,1             ;SPI match register
          ;-------------------------------------- ;aliases for QE compatibility
SPIC1               equ       SPI0_C1
SPIC2               equ       SPI0_C2
SPIBR               equ       SPI0_BR
SPID                equ       SPI0_D
          ;--------------------------------------
ADC_APCTL1          equ       $30AC,1             ;Pin Control 1 Register
ADC_APCTL2          equ       $30AD,1             ;Pin Control 2 Register

PORT_HDRVE          equ       $30AF,1             ;Port High Drive Enable Register

PORT_PTAOE          equ       $30B0,1             ;Port A Output Enable Register
PORT_PTBOE          equ       $30B1,1             ;Port B Output Enable Register
PORT_PTCOE          equ       $30B2,1             ;Port C Output Enable Register
PORT_PTDOE          equ       $30B3,1             ;Port D Output Enable Register
PORT_PTEOE          equ       $30B4,1             ;Port E Output Enable Register

PORT_PTAIE          equ       $30B8,1             ;Port A Input Enable Register
PORT_PTBIE          equ       $30B9,1             ;Port B Input Enable Register
PORT_PTCIE          equ       $30BA,1             ;Port C Input Enable Register
PORT_PTDIE          equ       $30BB,1             ;Port D Input Enable Register
PORT_PTEIE          equ       $30BC,1             ;Port E Input Enable Register

FTM2_SC             equ       $30C0,1             ;Status and Control
FTM2_CNT            equ       $30C1,2             ;FTM2 Timer Counter Register
FTM2_CNTH           equ       $30C1,1             ;Counter High
FTM2_CNTL           equ       $30C2,1             ;Counter Low
FTM2_MOD            equ       $30C3,2             ;FTM2 Timer Counter Modulo Register
FTM2_MODH           equ       $30C3,1             ;Modulo High
FTM2_MODL           equ       $30C4,1             ;Modulo Low
FTM2_C0SC           equ       $30C5,1             ;Channel Status and Control
FTM2_C0V            equ       $30C6,2             ;FTM2 Timer Channel 0 Value Register
FTM2_C0VH           equ       $30C6,1             ;Channel Value High
FTM2_C0VL           equ       $30C7,1             ;Channel Value Low
FTM2_C1SC           equ       $30C8,1             ;Channel Status and Control
FTM2_C1V            equ       $30C9,2             ;FTM2 Timer Channel 1 Value Register
FTM2_C1VH           equ       $30C9,1             ;Channel Value High
FTM2_C1VL           equ       $30CA,1             ;Channel Value Low
FTM2_C2SC           equ       $30CB,1             ;Channel Status and Control
FTM2_C2V            equ       $30CC,2             ;FTM2 Timer Channel 2 Value Register
FTM2_C2VH           equ       $30CC,1             ;Channel Value High
FTM2_C2VL           equ       $30CD,1             ;Channel Value Low
FTM2_C3SC           equ       $30CE,1             ;Channel Status and Control
FTM2_C3V            equ       $30CF,2             ;FTM2 Timer Channel 3 Value Register
FTM2_C3VH           equ       $30CF,1             ;Channel Value High
FTM2_C3VL           equ       $30D0,1             ;Channel Value Low
FTM2_C4SC           equ       $30D1,1             ;Channel Status and Control
FTM2_C4V            equ       $30D2,2             ;FTM2 Timer Channel 4 Value Register
FTM2_C4VH           equ       $30D2,1             ;Channel Value High
FTM2_C4VL           equ       $30D3,1             ;Channel Value Low
FTM2_C5SC           equ       $30D4,1             ;Channel Status and Control
FTM2_C5V            equ       $30D5,2             ;FTM2 Timer Channel 5 Value Register
FTM2_C5VH           equ       $30D5,1             ;Channel Value High
FTM2_C5VL           equ       $30D6,1             ;Channel Value Low
FTM2_CNTIN          equ       $30D7,2             ;FTM2 Counter Initial Value Registers
FTM2_CNTINH         equ       $30D7,1             ;Counter Initial Value High
FTM2_CNTINL         equ       $30D8,1             ;Counter Initial Value Low
FTM2_STATUS         equ       $30D9,1             ;Capture and Compare Status
FTM2_MODE           equ       $30DA,1             ;Features Mode Selection

                    @bitnum   FTMEN,0             ;FTM Enable
                    @bitnum   INIT,1              ;Initialize the Output Channels
                    @bitnum   WPDIS,2             ;Write Protection Disable
                    @bitnum   PWMSYNC,3           ;PWM Synchronization Mode
                    @bitnum   CAPTEST,4           ;Capture Test Mode Enable
                    @bitnum   FAULTM0,5           ;Fault Control Mode, bit 0
                    @bitnum   FAULTM1,6           ;Fault Control Mode, bit 1
                    @bitnum   FAULTIE,7           ;Fault Interrupt Enable

FTM2_SYNC           equ       $30DB,1             ;Synchronization

                    @bitnum   CNTMIN,0            ;Minimum Boundary Cycle Enable
                    @bitnum   CNTMAX,1            ;Maximum Boundary Cycle Enable
                    @bitnum   REINIT,2            ;FTM Counter Reinitialization by Synchronization (See "FTM Counter Synchronization")
                    @bitnum   SYNCHOM,3           ;Output Mask Synchronization
                    @bitnum   TRIG0,4             ;PWM Synchronization External Trigger 0
                    @bitnum   TRIG1,5             ;PWM Synchronization External Trigger 1
                    @bitnum   TRIG2,6             ;PWM Synchronization External Trigger 2
                    @bitnum   SWSYNC,7            ;PWM Synchronization Software Trigger

FTM2_OUTINIT        equ       $30DC,1             ;Initial State for Channel Output
FTM2_OUTMASK        equ       $30DD,1             ;Output Mask
FTM2_COMBINE0       equ       $30DE,1             ;Function for Linked Channels
FTM2_COMBINE1       equ       $30DF,1             ;Function for Linked Channels
FTM2_COMBINE2       equ       $30E0,1             ;Function for Linked Channels

                    @bitnum   COMBINE,0           ;Combine Channels
                    @bitnum   COMP,1              ;Complement of Channel (n)
                    @bitnum   DECAPEN,2           ;Dual Edge Capture Mode Enable
                    @bitnum   DECAP,3             ;Dual Edge Capture Mode Captures
                    @bitnum   DTEN,4              ;Deadtime Enable
                    @bitnum   SYNCEN,5            ;Synchronization Enable
                    @bitnum   FAULTEN,6           ;Fault Control Enable

FTM2_DEADTIME       equ       $30E2,1             ;Deadtime Insertion Control

FTM2_EXTTRIG        equ       $30E3,1             ;External Trigger
                    @bitnum   CH2TRIG,0           ;Channel 2 Trigger Enable
                    @bitnum   CH3TRIG,1           ;Channel 3 Trigger Enable
                    @bitnum   CH4TRIG,2           ;Channel 4 Trigger Enable
                    @bitnum   CH5TRIG,3           ;Channel 5 Trigger Enable
                    @bitnum   CH0TRIG,4           ;Channel 0 Trigger Enable
                    @bitnum   CH1TRIG,5           ;Channel 1 Trigger Enable
                    @bitnum   INITTRIGEN,6        ;Initialization Trigger Enable
                    @bitnum   TRIGF,7             ;Channel Trigger Flag

FTM2_POL            equ       $30E4,1             ;Channels Polarity
FTM2_FMS            equ       $30E5,1             ;Fault Mode Status

                    @bitnum   FAULTF0,0           ;Fault Detection Flag 0
                    @bitnum   FAULTF1,1           ;Fault Detection Flag 1
                    @bitnum   FAULTF2,2           ;Fault Detection Flag 2
                    @bitnum   FAULTF3,3           ;Fault Detection Flag 3
                    @bitnum   FAULTIN,5           ;Fault Inputs
                    @bitnum   WPEN,6              ;Write Protection Enable
                    @bitnum   FAULTF,7            ;Fault Detection Flag

FTM2_FILTER0        equ       $30E6,1             ;Input Capture Filter Control
FTM2_FILTER1        equ       $30E7,1             ;Input Capture Filter Control
FTM2_FLTFILTER      equ       $30E8,1             ;Fault Input Filter Control

FTM2_FLTCTRL        equ       $30E9,1             ;Fault Input Control

TPM2SC              equ       FTM2_SC,::FTM2_SC             ;Status and Control
TPM2CNT             equ       FTM2_CNT,::FTM2_CNT           ;FTM2 Timer Counter Register
TPM2CNTH            equ       FTM2_CNTH,::FTM2_CNTH         ;Counter High
TPM2CNTL            equ       FTM2_CNTL,::FTM2_CNTL         ;Counter Low
TPM2MOD             equ       FTM2_MOD,::FTM2_MOD           ;FTM2 Timer Counter Modulo Register
TPM2MODH            equ       FTM2_MODH,::FTM2_MODH         ;Modulo High
TPM2MODL            equ       FTM2_MODL,::FTM2_MODL         ;Modulo Low
TPM2C0SC            equ       FTM2_C0SC,::FTM2_C0SC         ;Channel Status and Control
TPM2C0V             equ       FTM2_C0V,::FTM2_C0V           ;FTM2 Timer Channel 0 Value Register
TPM2C0VH            equ       FTM2_C0VH,::FTM2_C0VH         ;Channel Value High
TPM2C0VL            equ       FTM2_C0VL,::FTM2_C0VL         ;Channel Value Low
TPM2C1SC            equ       FTM2_C1SC,::FTM2_C1SC         ;Channel Status and Control
TPM2C1V             equ       FTM2_C1V,::FTM2_C1V           ;FTM2 Timer Channel 1 Value Register
TPM2C1VH            equ       FTM2_C1VH,::FTM2_C1VH         ;Channel Value High
TPM2C1VL            equ       FTM2_C1VL,::FTM2_C1VL         ;Channel Value Low
TPM2C2SC            equ       FTM2_C2SC,::FTM2_C2SC         ;Channel Status and Control
TPM2C2V             equ       FTM2_C2V,::FTM2_C2V           ;FTM2 Timer Channel 2 Value Register
TPM2C2VH            equ       FTM2_C2VH,::FTM2_C2VH         ;Channel Value High
TPM2C2VL            equ       FTM2_C2VL,::FTM2_C2VL         ;Channel Value Low
TPM2C3SC            equ       FTM2_C3SC,::FTM2_C3SC         ;Channel Status and Control
TPM2C3V             equ       FTM2_C3V,::FTM2_C3V           ;FTM2 Timer Channel 3 Value Register
TPM2C3VH            equ       FTM2_C3VH,::FTM2_C3VH         ;Channel Value High
TPM2C3VL            equ       FTM2_C3VL,::FTM2_C3VL         ;Channel Value Low
TPM2C4SC            equ       FTM2_C4SC,::FTM2_C4SC         ;Channel Status and Control
TPM2C4V             equ       FTM2_C4V,::FTM2_C4V           ;FTM2 Timer Channel 4 Value Register
TPM2C4VH            equ       FTM2_C4VH,::FTM2_C4VH         ;Channel Value High
TPM2C4VL            equ       FTM2_C4VL,::FTM2_C4VL         ;Channel Value Low
TPM2C5SC            equ       FTM2_C5SC,::FTM2_C5SC         ;Channel Status and Control
TPM2C5V             equ       FTM2_C5V,::FTM2_C5V           ;FTM2 Timer Channel 5 Value Register
TPM2C5VH            equ       FTM2_C5VH,::FTM2_C5VH         ;Channel Value High
TPM2C5VL            equ       FTM2_C5VL,::FTM2_C5VL         ;Channel Value Low

PORT_IOFLT0         equ       $30EC,1             ;Port Filter Register 0
PORT_IOFLT1         equ       $30ED,1             ;Port Filter Register 1

                    @bitnum   FLTE0,0             ;Filter selection for input from PTE, bit 0
                    @bitnum   FLTE1,1             ;Filter selection for input from PTE, bit 1

PORT_IOFLT2         equ       $30EE,1             ;Port Filter Register 2

                    @bitnum   FLTRST0,0           ;Filter selection for input from RESET/IRQ, bit 0
                    @bitnum   FLTRST1,1           ;Filter selection for input from RESET/IRQ, bit 1
                    @bitnum   FLTKBI00,2          ;Filter selection for input from KBI0, bit 0
                    @bitnum   FLTKBI01,3          ;Filter selection for input from KBI0, bit 1

PORT_FCLKDIV        equ       $30EF,1             ;Port Clock Division Register
PTAPUE              equ       $30F0,1             ;Port A Pullup Enable Register
PTBPUE              equ       $30F1,1             ;Port B Pullup Enable Register
PTCPUE              equ       $30F2,1             ;Port C Pullup Enable Register
PTDPUE              equ       $30F3,1             ;Port D Pullup Enable Register
PTEPUE              equ       $30F4,1             ;Port E Pullup Enable Register

PORT_PTAPE          equ       PTAPUE,::PTAPUE     ;Port A Pullup Enable Register
PORT_PTBPE          equ       PTBPUE,::PTBPUE     ;Port B Pullup Enable Register
PORT_PTCPE          equ       PTCPUE,::PTCPUE     ;Port C Pullup Enable Register
PORT_PTDPE          equ       PTDPUE,::PTDPUE     ;Port D Pullup Enable Register
PORT_PTEPE          equ       PTEPUE,::PTEPUE     ;Port E Pullup Enable Register

SYS_UUID            equ       $30F8,8             ;Universally Unique Identifier Register
SYS_UUID1           equ       $30F8,1             ;Universally Unique Identifier Register 1
SYS_UUID2           equ       $30F9,1             ;Universally Unique Identifier Register 2
SYS_UUID3           equ       $30FA,1             ;Universally Unique Identifier Register 3
SYS_UUID4           equ       $30FB,1             ;Universally Unique Identifier Register 4
SYS_UUID5           equ       $30FC,1             ;Universally Unique Identifier Register 5
SYS_UUID6           equ       $30FD,1             ;Universally Unique Identifier Register 6
SYS_UUID7           equ       $30FE,1             ;Universally Unique Identifier Register 7
SYS_UUID8           equ       $30FF,1             ;Universally Unique Identifier Register 8

NVFTRIM             equ       $FF6E,1             ;NV FTRIM
NVICSTRM            equ       $FF6F,1             ;NV ICS Trim

NVBACKKEY           equ       $FF70,8             ;NV_BACKKEY - Back Door Key Register

NV_FPROT            equ       $FF7C,1             ;Flash Protection Register
NV_EEPROT           equ       $FF7D,1             ;EEPROM Protection Register
NV_FOPT             equ       $FF7E,1             ;Flash Option Register
NV_FSEC             equ       $FF7F,1             ;Flash Security Register

                    @bitnum   SEC0,0              ;Flash Security Bits, bit 0
                    @bitnum   SEC1,1              ;Flash Security Bits, bit 1
                    @bitnum   KEYEN0,6            ;Backdoor Key Security Enable Bits, bit 0
                    @bitnum   KEYEN1,7            ;Backdoor Key Security Enable Bits, bit 1

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08PA32_          def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       22                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       23                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1210                ;typical bandgap voltage in mV

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FFB0               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

;--- Vectors
                    #temp     VECTORS
Vnvm                next      :temp,2             ;$FFB0 NVM vector
Vkbi1               next      :temp,2             ;$FFB2 KBI1 vector
Vkbi0               next      :temp,2             ;$FFB4 KBI0 vector
                    next      :temp,2
Vrtc                next      :temp,2             ;$FFB8 Real Time Clock vector
Viic                next      :temp,2             ;$FFBA IIC vector
Vspi1               next      :temp,2             ;$FFBC SPI vector
Vspi0               next      :temp,2             ;$FFBE SPI vector
Vsci2tx             next      :temp,2             ;$FFC0 SCI2 transmit vector
Vsci2rx             next      :temp,2             ;$FFC2 SCI2 receive vector
Vsci2err            next      :temp,2             ;$FFC4 SCI2 error vector
Vsci1tx             next      :temp,2             ;$FFC6 SCI1 transmit vector
Vsci1rx             next      :temp,2             ;$FFC8 SCI1 receive vector
Vsci1err            next      :temp,2             ;$FFCA SCI1 error vector
Vsci0tx             next      :temp,2             ;$FFCC SCI transmit vector
Vsci0rx             next      :temp,2             ;$FFCE SCI receive vector
Vsci0err            next      :temp,2             ;$FFD0 SCI error vector
Vadc                next      :temp,2             ;$FFD2 A/D vector
Vacmp               next      :temp,2             ;$FFD4 Analog Comparator
Vmtim1              next      :temp,2             ;$FFD6 Modulo Timer 1
Vmtim               next      :temp,2             ;$FFD8 Modulo Timer
Vftm0ovf            next      :temp,2             ;$FFDA FTM0 overflow
Vftm0ch1            next      :temp,2             ;$FFDC FTM0 Channel 1
Vftm0ch0            next      :temp,2             ;$FFDE FTM0 Channel 0
Vftm1ovf            next      :temp,2             ;$FFE0 FTM1 overflow
Vftm1ch1            next      :temp,2             ;$FFE2 FTM1 Channel 1
Vftm1ch0            next      :temp,2             ;$FFE4 FTM1 Channel 0
Vftm2ovf            next      :temp,2             ;$FFE6 FTM2 overflow
Vftm2ch5            next      :temp,2             ;$FFE8 FTM2 Channel 5
Vftm2ch4            next      :temp,2             ;$FFEA FTM2 Channel 4
Vftm2ch3            next      :temp,2             ;$FFEC FTM2 Channel 3
Vftm2ch2            next      :temp,2             ;$FFEE FTM2 Channel 2
Vftm2ch1            next      :temp,2             ;$FFF0 FTM2 Channel 1
Vftm2ch0            next      :temp,2             ;$FFF2 FTM2 Channel 0
Vftm2flt            next      :temp,2             ;$FFF4 FTM2 ...
Vclk                next      :temp,2             ;$FFF6 Clock loss of lock
Vlvw                next      :temp,2             ;$FFF8 Low voltage warning
Virq_wdog           next      :temp,2             ;$FFFA IRQ and watchdog vector
Vswi                next      :temp,2             ;$FFFC SWI vector
Vreset              next      :temp,2             ;$FFFE Reset vector

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
TRUE_ROM            equ       $8000               ;start of 32K Flash

EEPROM              equ       $3100
EEPROM_END          equ       $31FF

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
                    #Error    FLASH_DATA_SIZE is too large
 #endif
#endif

ROM                 def       TRUE_ROM
ROM_END             equ       $FF6D               ;end of all flash (before NV registers and fixed vectors)

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

XROM                equ       $FF80               ;unused vectors can hold
XROM_END            equ       $FFAF               ;some more code/data

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

RAM                 equ       $40                 ;start of 4KB RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $103F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 1024 byte RAM
#endif

FLASH_START         equ       TRUE_ROM
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ||KHZ
HZ                  def       33554432            ;Cyclone default 32768*1024
#endif
;----------------------+------------+-------------------------------------------
; Reference range      | FLL factor | DCO range
;----------------------+------------+-------------------------------------------
; 31.25 - 39.0625 kHz  |    1024    | 32 - 40 MHz

MIN_FLASH_KHZ       def       800
MAX_FLASH_KHZ       def       1000

;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------
;*******************************************************************************
; Aliases for compatibility convenience with existing library code
;*******************************************************************************

;ICSC2               equ       ICS_C2             ;serious bit differences

Vscitx              equ       Vsci0tx
Vscirx              equ       Vsci0rx
Vscierr             equ       Vsci0err

NVOPT               equ       NV_FOPT,1
NVPROT              equ       NV_FPROT,1          ;NVM_FPROT
FSTAT               equ       NVM_FSTAT,1
FCDIV               equ       NVM_FCLKDIV,1

;*******************************************************************************

HighRegs            equ       $3000               ;start of high page registers
HighRegs_End        equ       $30FF               ;end of high page registers

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
NVOPT_VALUE         def       %10000010           ;NVFEOPT transfers to FOPT on reset
          #endif             ; ||||||||
NVOPT_VALUE         def       %10000000           ;NVFEOPT transfers to FOPT on reset
                             ; ||||||++----------- SEC00 \ 00:secure  10:unsecure
                             ; ||||||++----------- SEC01 / 01:secure  11:secure
                             ; ||++++------------- Not Used (Always 0)
                             ; ++----------------- KEYEN - Backdoor key mechanism enable
                             ; ++----------------- 10:enabled, all others:disabled

                    org       NV_FSEC             ;NV flash options byte
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
                    #MEMORY   EEPROM    EEPROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
                    #MEMORY   NVOPT
                    #MEMORY   NV_FSEC
                    #MEMORY   VECTORS   VECTORS|$FF
                    #!MEMORY  CRC_LOCATION CRC_LOCATION+1

;*******************************************************************************
                    #Uses     pa_cop.inc
;*******************************************************************************
