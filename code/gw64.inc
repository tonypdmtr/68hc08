;*******************************************************************************
;*            MC9S08GW64 FRAMEWORK INCLUDE FILE FOR ASM8 ASSEMBLER             *
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************

                    #Uses     macros.inc
                    #Message  **********************
                    #Message  * Target: MC9S08GW64 *
                    #Message  **********************

                    #HcsOn
#ifdef BOOT
                    #Message  TBoot pre-loaded
  #ifexists tboot.exp
                    #Uses     tboot.exp
  #else
                    #Uses     tboot/tboot_gw64.exp
  #endif

#endif

_GW_                def       64
_GW64_              def       *

; ###################################################################
;     Filename  : mc9s08gw64.inc
;     Processor : MC9S08GW64CLK
;     FileFormat: V2.32
;     DataSheet : MC9S08GW64RM Rev.3 Draft A 10/2010
;     Compiler  : CodeWarrior compiler
;     Date/Time : 1.11.2010, 16:46
;     Abstract  :
;         This header implements the mapping of I/O devices.
;
;     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
;
;     http      : www.freescale.com
;     mail      : support@freescale.com
;
;     CPU Registers Revisions:
;               - none
;
;     File-Format-Revisions:
;               - none
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
STANDBYXRAM         equ       $18C0
STANDBYXRAM_END     equ       $18DF

PPAGE_0Start        equ       $8000
PPAGE_0End          equ       $90BF
PPAGE_0_1Start      equ       $9800
PPAGE_0_1End        equ       $995F
PPAGE_2Start        equ       $028000
PPAGE_2End          equ       $02BFFF

;-------------------------------------------------------------------------------

PTAD                equ       $00,1               ;Port A Data Register
PTADD               equ       $01,1               ;Port A Data Direction Register
PTBD                equ       $02,1               ;Port B Data Register
PTBDD               equ       $03,1               ;Port B Data Direction Register
PTCD                equ       $04,1               ;Port C Data Register
PTCDD               equ       $05,1               ;Port C Data Direction Register
PTDD                equ       $06,1               ;Port D Data Register
PTDDD               equ       $07,1               ;Port D Data Direction Register
PTED                equ       $08,1               ;Port E Data Register
PTEDD               equ       $09,1               ;Port E Data Direction Register
PTFD                equ       $0A,1               ;Port F Data Register
PTFDD               equ       $0B,1               ;Port F Data Direction Register
PTGD                equ       $0C,1               ;Port G Data Register
PTGDD               equ       $0D,1               ;Port G Data Direction Register
PTHD                equ       $0E,1               ;Port H Data Register
PTHDD               equ       $0F,1               ;Port H Data Direction Register

;-------------------------------------------------------------------------------

MTIM1SC             equ       $10,1               ;MTIM Clock Configuration Register
MTIM1CLK            equ       $11,1               ;MTIM Clock Configuration Register
MTIM1CNT            equ       $12,1               ;MTIM Counter Register
MTIM1MOD            equ       $13,1               ;MTIM Modulo Register
MTIM2SC             equ       $14,1               ;MTIM Clock Configuration Register
MTIM2CLK            equ       $15,1               ;MTIM Clock Configuration Register
MTIM2CNT            equ       $16,1               ;MTIM Counter Register
MTIM2MOD            equ       $17,1               ;MTIM Modulo Register

MTIM3SC             equ       $18,1               ;MTIM16 Status and Control Register
MTIM3CLK            equ       $19,1               ;MTIM16 Clock Configuration Register
MTIM3CNT            equ       $1A,2               ;MTIM16 Counter Register
MTIM3CNTH           equ       $1A,1               ;MTIM16 Counter Register High
MTIM3CNTL           equ       $1B,1               ;MTIM16 Counter Register Low
MTIM3MOD            equ       $1C,2               ;MTIM16 Modulo Register
MTIM3MODH           equ       $1C,1               ;MTIM16 Modulo Register High
MTIM3MODL           equ       $1D,1               ;MTIM16 Modulo Register Low

                    @bitnum   MTIM_TSTP,4         ;MTIM Counter Stop
                    @bitnum   MTIM_TRST,5         ;MTIM Counter Reset
                    @bitnum   MTIM_TOIE,6         ;MTIM Overflow Interrupt Enable
                    @bitnum   MTIM_TOF,7          ;MTIM Overflow Flag

                    @bitnum   MTIM_PS0,0          ;Clock source Prescaler Bit 0
                    @bitnum   MTIM_PS1,1          ;Clock source Prescaler Bit 1
                    @bitnum   MTIM_PS2,2          ;Clock source Prescaler Bit 2
                    @bitnum   MTIM_PS3,3          ;Clock source Prescaler Bit 3
                    @bitnum   MTIM_CLKS0,4        ;Clock source Select Bit 0
                    @bitnum   MTIM_CLKS1,5        ;Clock source Select Bit 1

;-------------------------------------------------------------------------------

PDBSC               equ       $20,2               ;PDB Status and Control Register
PDBSCH              equ       $20,1               ;PDB Status and Control High Register
PDBSCL              equ       $21,1               ;PDB Status and Control Low Register
PDBMOD              equ       $22,2               ;PDB Counter Modulus Register
PDBMODH             equ       $22,1               ;PDB Counter Modulus High Register
PDBMODL             equ       $23,1               ;PDB Counter Modulus Low Register
PDBCNT              equ       $24,2               ;PDB Counter Value Register
PDBCNTH             equ       $24,1               ;PDB Counter Value High Register
PDBCNTL             equ       $25,1               ;PDB Counter Value Low Register
PDBIDLY             equ       $26,2               ;PDB Interrupt Delay Register
PDBIDLYH            equ       $26,1               ;PDB Interrupt Delay High Register
PDBIDLYL            equ       $27,1               ;PDB Interrupt Delay Low Register
PDBCH1CR            equ       $28,2               ;PDB Channel 1 Control Register
PDBCH1CRH           equ       $28,1               ;PDB Channel 1 Control High Register
PDBCH1CRL           equ       $29,1               ;PDB Channel 1 Control Low Register
PDBCH1DLYA          equ       $2A,2               ;PDB Channel 1 Delay A Register
PDBCH1DLYAH         equ       $2A,1               ;PDB Channel 1 Delay A High Register
PDBCH1DLYAL         equ       $2B,1               ;PDB Channel 1 Delay A Low Register
PDBCH1DLYB          equ       $2C,2               ;PDB Channel 1 Delay B Register
PDBCH1DLYBH         equ       $2C,1               ;PDB Channel 1 Delay B High Register
PDBCH1DLYBL         equ       $2D,1               ;PDB Channel 1 Delay B Low Register
PDBCH2CR            equ       $30,2               ;PDB Channel 2 Control Register
PDBCH2CRH           equ       $30,1               ;PDB Channel 2 Control High Register
PDBCH2CRL           equ       $31,1               ;PDB Channel 2 Control Low Register
PDBCH2DLYA          equ       $32,2               ;PDB Channel 2 Delay A Register
PDBCH2DLYAH         equ       $32,1               ;PDB Channel 2 Delay A High Register
PDBCH2DLYAL         equ       $33,1               ;PDB Channel 2 Delay A Low Register
PDBCH2DLYB          equ       $34,2               ;PDB Channel 2 Delay B Register
PDBCH2DLYBH         equ       $34,1               ;PDB Channel 2 Delay B High Register
PDBCH2DLYBL         equ       $35,1               ;PDB Channel 2 Delay B Low Register

                    @bitnum   PDBSCH_PRESCALER0,5 ;Clock Prescaler Select, bit 0
                    @bitnum   PDBSCH_PRESCALER1,6 ;Clock Prescaler Select, bit 1
                    @bitnum   PDBSCH_PRESCALER2,7 ;Clock Prescaler Select, bit 2

                    @bitnum   PDBSCL_EN,0         ;Module Enable
                    @bitnum   PDBSCL_IE,1         ;Interrupt Enable
                    @bitnum   PDBSCL_TRIGSEL0,2   ;Input Trigger Select, bit 0
                    @bitnum   PDBSCL_TRIGSEL1,3   ;Input Trigger Select, bit 1
                    @bitnum   PDBSCL_TRIGSEL2,4   ;Input Trigger Select, bit 2
                    @bitnum   PDBSCL_SWTRIG,5     ;Software Trigger
                    @bitnum   PDBSCL_CONT,6       ;Continuous Mode Enable
                    @bitnum   PDBSCL_IF,7         ;Interrupt Flag

                    @bitnum   PDBCHxCRH_ERRB,6    ;Sequence error on TriggerB
                    @bitnum   PDBCHxCRH_ERRA,7    ;Sequence error on TriggerA

                    @bitnum   PDBCHxCRL_ENB,0     ;Trigger B Enable
                    @bitnum   PDBCHxCRL_ENA,1     ;Trigger A Enable
                    @bitnum   PDBCHxCRL_BOS0,2    ;Channel 1 Trigger B Output Select, bit 0
                    @bitnum   PDBCHxCRL_BOS1,3    ;Channel 1 Trigger B Output Select, bit 1
                    @bitnum   PDBCHxCRL_AOS0,4    ;Channel 1 Trigger A Output Select, bit 0
                    @bitnum   PDBCHxCRL_AOS1,5    ;Channel 1 Trigger A Output Select, bit 1

                    @bitnum   PDBCH2CRL_ENB,0     ;Trigger B Enable
                    @bitnum   PDBCH2CRL_ENA,1     ;Trigger A Enable
                    @bitnum   PDBCH2CRL_BOS0,2    ;Channel 2 Trigger B Output Select, bit 0
                    @bitnum   PDBCH2CRL_BOS1,3    ;Channel 2 Trigger B Output Select, bit 1
                    @bitnum   PDBCH2CRL_AOS0,4    ;Channel 2 Trigger A Output Select, bit 0
                    @bitnum   PDBCH2CRL_AOS1,5    ;Channel 2 Trigger A Output Select, bit 1
          ;-------------------------------------- ;MMU related
PPAGE               equ       $38,1               ;Program Page Register
LAP2                equ       $39,1               ;Linear Address Pointer Register 2
LAP1                equ       $3A,1               ;Linear Address Pointer Register 1
LAP0                equ       $3B,1               ;Linear Address Pointer Register 0
LWP                 equ       $3C,1               ;Linear Word Post Increment Register
LBP                 equ       $3D,1               ;Linear Byte Post Increment Register
LB                  equ       $3E,1               ;Linear Byte Register
LAPAB               equ       $3F,1               ;Linear Address Pointer Add Byte Register
          ;--------------------------------------
ADC0SC1A            equ       $40,1               ;Status and Control Register 1A
ADC0SC1B            equ       $41,1               ;Status and Control Register 1B
ADC0CFG1            equ       $42,1               ;Configuration Register 1
ADC0CFG2            equ       $43,1               ;Configuration Register 2
ADC0RA              equ       $44,2               ;Data Result Register A
ADC0RHA             equ       $44,1               ;Data Result High Register A
ADC0RLA             equ       $45,1               ;Data Result Low Register A
ADC0RB              equ       $46,2               ;Data Result Register B
ADC0RHB             equ       $46,1               ;Data Result High Register B
ADC0RLB             equ       $47,1               ;Data Result Low Register B

                    @bitnum   ADCH0,0             ;Input Channel Select Bit 0
                    @bitnum   ADCH1,1             ;Input Channel Select Bit 1
                    @bitnum   ADCH2,2             ;Input Channel Select Bit 2
                    @bitnum   ADCH3,3             ;Input Channel Select Bit 3
                    @bitnum   ADCH4,4             ;Input Channel Select Bit 4
                    @bitnum   DIFF,5              ;Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
                    @bitnum   AIEN,6              ;Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA
                    @bitnum   COCO,7              ;Conversion Complete Flag

                    @bitnum   ADICLK0,0           ;Input Clock Select Bit 0
                    @bitnum   ADICLK1,1           ;Input Clock Select Bit 1
                    @bitnum   MODE0,2             ;Conversion Mode Selection Bit 0
                    @bitnum   MODE1,3             ;Conversion Mode Selection Bit 1
                    @bitnum   ADLSMP,4            ;Long Sample Time Configuration
                    @bitnum   ADIV0,5             ;Clock Divide Select Bit 0
                    @bitnum   ADIV1,6             ;Clock Divide Select Bit 1
                    @bitnum   ADLPC,7             ;Low Power Configuration

                    @bitnum   ADLSTS0,0           ;Long Sample Time Select Bit 0
                    @bitnum   ADLSTS1,1           ;Long Sample Time Select Bit 1
                    @bitnum   ADHSC,2             ;High Speed Configuration
                    @bitnum   ADACKEN,3           ;Asynchronous Clock Output Enable

;-------------------------------------------------------------------------------

SPI0C1              equ       $48,1               ;SPI0 Control Register 1
SPI0C2              equ       $49,1               ;SPI0 Control Register 2
SPI0BR              equ       $4A,1               ;SPI0 Baud Rate Register
SPI0S               equ       $4B,1               ;SPI0 Status Register
SPI0D               equ       $4D,1               ;SPI0 Data Register

SPI1C1              equ       $50,1               ;SPI1 Control Register 1
SPI1C2              equ       $51,1               ;SPI1 Control Register 2
SPI1BR              equ       $52,1               ;SPI1 Baud Rate Register
SPI1S               equ       $53,1               ;SPI1 Status Register
SPI1D               equ       $55,1               ;SPI1 Data Register

SPI2C1              equ       $58,1               ;SPI2 Control Register 1
SPI2C2              equ       $59,1               ;SPI2 Control Register 2
SPI2BR              equ       $5A,1               ;SPI2 Baud Rate Register
SPI2S               equ       $5B,1               ;SPI2 Status Register
SPI2D               equ       $5D,1               ;SPI2 Data Register

                    @bitnum   SPI_LSBFE,0         ;LSB First (Shifter Direction)
                    @bitnum   SPI_SSOE,1          ;Slave Select Output Enable
                    @bitnum   SPI_CPHA,2          ;Clock Phase
                    @bitnum   SPI_CPOL,3          ;Clock Polarity
                    @bitnum   SPI_MSTR,4          ;Master/Slave Mode Select
                    @bitnum   SPI_SPTIE,5         ;SPI Transmit Interrupt Enable
                    @bitnum   SPI_SPE,6           ;SPI System Enable
                    @bitnum   SPI_SPIE,7          ;SPI Interrupt Enable (for SPRF and MODF)

                    @bitnum   SPI_SPC0,0          ;SPI Pin Control 0
                    @bitnum   SPI_SPISWAI,1       ;SPI Stop in Wait Mode
                    @bitnum   SPI_BIDIROE,3       ;Bidirectional Mode Output Enable
                    @bitnum   SPI_MODFEN,4        ;Master Mode-Fault Function Enable

                    @bitnum   SPI_MODF,4          ;Master Mode Fault Flag
                    @bitnum   SPI_SPTEF,5         ;SPI Transmit Buffer Empty Flag
                    @bitnum   SPI_SPRF,7          ;SPI Read Buffer Full Flag

;-------------------------------------------------------------------------------

PCNT_STATUS         equ       $60,2               ;PCounter Status Register
PCNT_STATUS_H       equ       $60,1               ;PCounter Status Register High
PCNT_STATUS_L       equ       $61,1               ;PCounter Status Register Low
PCNT_CTRL           equ       $62,2               ;PCounter Control Register
PCNT_CTRL_H         equ       $62,1               ;PCounter Control Register High
PCNT_CTRL_L         equ       $63,1               ;PCounter Control Register Low
PCNT_FCMOD          equ       $64,2               ;PCounter Forward Counter Modulus Register
PCNT_FCMOD_H        equ       $64,1               ;PCounter Forward Counter Modulus Register High
PCNT_FCMOD_L        equ       $65,1               ;PCounter Forward Counter Modulus Register Low
PCNT_FCNTR          equ       $66,2               ;PCounter Forward Counter Register
PCNT_FCNTR_H        equ       $66,1               ;PCounter Forward Counter Register High
PCNT_FCNTR_L        equ       $67,1               ;PCounter Forward Counter Register Low
PCNT_RCMOD          equ       $68,2               ;PCounter Reverse Counter Modulus Register
PCNT_RCMOD_H        equ       $68,1               ;PCounter Reverse Counter Modulus Register High
PCNT_RCMOD_L        equ       $69,1               ;PCounter Reverse Counter Modulus Register Low
PCNT_RCNTR          equ       $6A,2               ;PCounter Reverse Counter Register
PCNT_RCNTR_H        equ       $6A,1               ;PCounter Reverse Counter Register High
PCNT_RCNTR_L        equ       $6B,1               ;PCounter Reverse Counter Register Low
PCNT_PWM_MOD        equ       $6C,2               ;PCounter PWM Modulus Register
PCNT_PWM_MOD_H      equ       $6C,1               ;PCounter PWM Modulus Register High
PCNT_PWM_MOD_L      equ       $6D,1               ;PCounter PWM Modulus Register Low
PCNT_PWM_CH0_VAL    equ       $6E,2               ;PCounter PWM Channel 0 Value Register
PCNT_PWM_CH0_H_VAL  equ       $6E,1               ;PCounter PWM Channel 0 Value Register High
PCNT_PWM_CH0_L_VAL  equ       $6F,1               ;PCounter PWM Channel 0 Value Register Low
PCNT_PWM_CH1_VAL    equ       $70,2               ;PCounter PWM Channel 1 Value Register
PCNT_PWM_CH1_H_VAL  equ       $70,1               ;PCounter PWM Channel 1 Value Register High
PCNT_PWM_CH1_L_VAL  equ       $71,1               ;PCounter PWM Channel 1 Value Register Low
PCNT_STATE          equ       $72,2               ;PCounter Status Register
PCNT_STATE_H        equ       $72,1               ;PCounter Status Register High
PCNT_STATE_L        equ       $73,1               ;PCounter Status Register Low

                    @bitnum   CURR_INV,0          ;Current state of the state machine when a state invalid event occurs, bit 0
                    @bitnum   PSTATE_INV,4        ;Sensor input pin state when a state invalid event occurs, bit 0

                    @bitnum   FCOVF,0             ;FCounter Overflow Flag
                    @bitnum   RCOVF,1             ;RCounter Overflow Flag
                    @bitnum   SINVF,2             ;State Invalid Interrupt Flag

                    @bitnum   CHANNEL_SEL,0       ;Channel select bit 0
                    @bitnum   PCNT_MODE0,3        ;Mode select, bit 0
                    @bitnum   PCNT_MODE1,4        ;Mode select, bit 1
                    @bitnum   FCOVFIE,5           ;FCounter Overflow Interrupt Enable bit
                    @bitnum   RCOVFIE,6           ;RCounter Overflow Interrupt Eenable bit
                    @bitnum   SINVIE,7            ;State Invalid Interrupt Enable bit

                    @bitnum   PCNT_FILTER_VALUE,0 ;Filter value bit 0
                    @bitnum   PCNT_CPWMS,4        ;PWM alignment selection
                    @bitnum   PCNT_POL,5          ;PWM polarity bit
                    @bitnum   PCNT_DIR,6          ;Direction bit
                    @bitnum   PCNT_PCNT_EN,7      ;Enable/Disable bit

                    @bitnum   PCNTCURR_STATE,0    ;This is for debugging purpose.These bits reflect the current state of the state machine
                    @bitnum   PCNTPCOUNTER_STATE,3;This is for debugging purpose.These bits reflect value on sensor inputs coming into PCounter

;-------------------------------------------------------------------------------

KBISC               equ       $74,1               ;KBI Status and Control Register

                    @bitnum   KBIMOD,0            ;Keyboard Detection Mode
                    @bitnum   KBIE,1              ;Keyboard Interrupt Enable
                    @bitnum   KBACK,2             ;Keyboard Interrupt Acknowledge
                    @bitnum   KBF,3               ;Keyboard Interrupt Flag

KBIPE               equ       $75,1               ;KBI Pin Enable Register
KBIES               equ       $76,1               ;KBI Edge Select Register

;-------------------------------------------------------------------------------

IRQSC               equ       $77,1               ;Interrupt request status and control register

                    @bitnum   IRQMOD,0            ;IRQ Detection Mode
                    @bitnum   IRQIE,1             ;IRQ Interrupt Enable
                    @bitnum   IRQACK,2            ;IRQ Acknowledge
                    @bitnum   IRQF,3              ;IRQ Flag
                    @bitnum   IRQPE,4             ;IRQ Pin Enable
                    @bitnum   IRQEDG,5            ;IRQ Edge Select
                    @bitnum   IRQPDD,6            ;IRQ Pull Device Disable

;-------------------------------------------------------------------------------

SCI0BD              equ       $78,1               ;SCI0 Baud Rate Register
SCI0BDH             equ       $78,1               ;SCI0 Baud Rate Register High

                    @bitnum   RXEDGIE,6           ;RxD Input Active Edge Interrupt Enable (for RXEDGIF)
                    @bitnum   LBKDIE,7            ;LIN Break Detect Interrupt Enable (for LBKDIF)

SCI0BDL             equ       $79,1               ;SCI0 Baud Rate Register Low
SCI0C1              equ       $7A,1               ;SCI0 Control Register 1

SCI0C1_PT           equ       0                   ;Parity Type
SCI0C1_PE           equ       1                   ;Parity Enable
SCI0C1_ILT          equ       2                   ;Idle Line Type Select
SCI0C1_WAKE         equ       3                   ;Receiver Wakeup Method Select
SCI0C1_M            equ       4                   ;9-Bit or 8-Bit Mode Select
SCI0C1_RSRC         equ       5                   ;Receiver Source Select
SCI0C1_SCISWAI      equ       6                   ;SCI Stops in Wait Mode
SCI0C1_LOOPS        equ       7                   ;Loop Mode Select

SCI0C2              equ       $7B,1               ;SCI0 Control Register 2

SCI0C2_SBK          equ       0                   ;Send Break
SCI0C2_RWU          equ       1                   ;Receiver Wakeup Control
SCI0C2_RE           equ       2                   ;Receiver Enable
SCI0C2_TE           equ       3                   ;Transmitter Enable
SCI0C2_ILIE         equ       4                   ;Idle Line Interrupt Enable (for IDLE)
SCI0C2_RIE          equ       5                   ;Receiver Interrupt Enable (for RDRF)
SCI0C2_TCIE         equ       6                   ;Transmission Complete Interrupt Enable (for TC)
SCI0C2_TIE          equ       7                   ;Transmit Interrupt Enable (for TDRE)

SCI0S1              equ       $7C,1               ;SCI0 Status Register 1

SCI0S1_PF           equ       0                   ;Parity Error Flag
SCI0S1_FE           equ       1                   ;Framing Error Flag
SCI0S1_NF           equ       2                   ;Noise Flag
SCI0S1_OR           equ       3                   ;Receiver Overrun Flag
SCI0S1_IDLE         equ       4                   ;Idle Line Flag
SCI0S1_RDRF         equ       5                   ;Receive Data Register Full Flag
SCI0S1_TC           equ       6                   ;Transmission Complete Flag
SCI0S1_TDRE         equ       7                   ;Transmit Data Register Empty Flag

SCI0S2              equ       $7D,1               ;SCI0 Status Register 2

SCI0S2_RAF          equ       0                   ;Receiver Active Flag
SCI0S2_LBKDE        equ       1                   ;LIN Break Detection Enable
SCI0S2_BRK13        equ       2                   ;Break Character Generation Length
SCI0S2_RWUID        equ       3                   ;Receive Wake Up Idle Detect
SCI0S2_RXINV        equ       4                   ;Receive Data Inversion
SCI0S2_RXEDGIF      equ       6                   ;RxD Pin Active Edge Interrupt Flag
SCI0S2_LBKDIF       equ       7                   ;LIN Break Detect Interrupt Flag

SCI0C3              equ       $7E,1               ;SCI0 Control Register 3

SCI0C3_PEIE         equ       0                   ;Parity Error Interrupt Enable
SCI0C3_FEIE         equ       1                   ;Framing Error Interrupt Enable
SCI0C3_NEIE         equ       2                   ;Noise Error Interrupt Enable
SCI0C3_ORIE         equ       3                   ;Overrun Interrupt Enable
SCI0C3_TXINV        equ       4                   ;Transmit Data Inversion
SCI0C3_TXDIR        equ       5                   ;TxD Pin Direction in Single-Wire Mode
SCI0C3_T8           equ       6                   ;Ninth Data Bit for Transmitter
SCI0C3_R8           equ       7                   ;Ninth Data Bit for Receiver

SCI0D               equ       $7F,1               ;SCI0 Data Register

;-------------------------------------------------------------------------------

ADC1SC1A            equ       $80,1               ;Status and Control Register 1A

ADC1SC1A_DIFFA      equ       5                   ;Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADC1SC1A_AIENA      equ       6                   ;Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA
ADC1SC1A_COCOA      equ       7                   ;Conversion Complete Flag

ADC1SC1B            equ       $81,1               ;Status and Control Register 1B

ADC1SC1B_ADCHB0     equ       0                   ;Input Channel Select Bit 0
ADC1SC1B_ADCHB1     equ       1                   ;Input Channel Select Bit 1
ADC1SC1B_ADCHB2     equ       2                   ;Input Channel Select Bit 2
ADC1SC1B_ADCHB3     equ       3                   ;Input Channel Select Bit 3
ADC1SC1B_ADCHB4     equ       4                   ;Input Channel Select Bit 4
ADC1SC1B_DIFFB      equ       5                   ;Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADC1SC1B_AIENB      equ       6                   ;Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB
ADC1SC1B_COCOB      equ       7                   ;Conversion Complete Flag

ADC1CFG1            equ       $82,1               ;Configuration Register 1

ADC1CFG1_ADICLK0    equ       0                   ;Input Clock Select Bit 0
ADC1CFG1_ADICLK1    equ       1                   ;Input Clock Select Bit 1
ADC1CFG1_MODE0      equ       2                   ;Conversion Mode Selection Bit 0
ADC1CFG1_MODE1      equ       3                   ;Conversion Mode Selection Bit 1
ADC1CFG1_ADLSMP     equ       4                   ;Long Sample Time Configuration
ADC1CFG1_ADIV0      equ       5                   ;Clock Divide Select Bit 0
ADC1CFG1_ADIV1      equ       6                   ;Clock Divide Select Bit 1
ADC1CFG1_ADLPC      equ       7                   ;Low Power Configuration

ADC1CFG2            equ       $83,1               ;Configuration Register 2

ADC1CFG2_ADLSTS0    equ       0                   ;Long Sample Time Select Bit 0
ADC1CFG2_ADLSTS1    equ       1                   ;Long Sample Time Select Bit 1
ADC1CFG2_ADHSC      equ       2                   ;High Speed Configuration
ADC1CFG2_ADACKEN    equ       3                   ;Asynchronous Clock Output Enable

ADC1RA              equ       $84,2               ;Data Result Register A
ADC1RHA             equ       $84,1               ;Data Result High Register A
ADC1RLA             equ       $85,1               ;Data Result Low Register A

ADC1RB              equ       $86,2               ;Data Result Register B
ADC1RHB             equ       $86,1               ;Data Result High Register B
ADC1RLB             equ       $87,1               ;Data Result Low Register B

;-------------------------------------------------------------------------------

SCI1BD              equ       $88,2               ;SCI1 Baud Rate Register
SCI1BDH             equ       $88,1               ;SCI1 Baud Rate Register High
SCI1BDL             equ       $89,1               ;SCI1 Baud Rate Register Low
SCI1C1              equ       $8A,1               ;SCI1 Control Register 1

SCI1C1_PT           equ       0                   ;Parity Type
SCI1C1_PE           equ       1                   ;Parity Enable
SCI1C1_ILT          equ       2                   ;Idle Line Type Select
SCI1C1_WAKE         equ       3                   ;Receiver Wakeup Method Select
SCI1C1_M            equ       4                   ;9-Bit or 8-Bit Mode Select
SCI1C1_RSRC         equ       5                   ;Receiver Source Select
SCI1C1_SCISWAI      equ       6                   ;SCI Stops in Wait Mode
SCI1C1_LOOPS        equ       7                   ;Loop Mode Select

SCI1C2              equ       $8B,1               ;SCI1 Control Register 2

SCI1C2_SBK          equ       0                   ;Send Break
SCI1C2_RWU          equ       1                   ;Receiver Wakeup Control
SCI1C2_RE           equ       2                   ;Receiver Enable
SCI1C2_TE           equ       3                   ;Transmitter Enable
SCI1C2_ILIE         equ       4                   ;Idle Line Interrupt Enable (for IDLE)
SCI1C2_RIE          equ       5                   ;Receiver Interrupt Enable (for RDRF)
SCI1C2_TCIE         equ       6                   ;Transmission Complete Interrupt Enable (for TC)
SCI1C2_TIE          equ       7                   ;Transmit Interrupt Enable (for TDRE)

SCI1S1              equ       $8C,1               ;SCI1 Status Register 1

SCI1S1_PF           equ       0                   ;Parity Error Flag
SCI1S1_FE           equ       1                   ;Framing Error Flag
SCI1S1_NF           equ       2                   ;Noise Flag
SCI1S1_OR           equ       3                   ;Receiver Overrun Flag
SCI1S1_IDLE         equ       4                   ;Idle Line Flag
SCI1S1_RDRF         equ       5                   ;Receive Data Register Full Flag
SCI1S1_TC           equ       6                   ;Transmission Complete Flag
SCI1S1_TDRE         equ       7                   ;Transmit Data Register Empty Flag

SCI1S2              equ       $8D,1               ;SCI1 Status Register 2

SCI1S2_RAF          equ       0                   ;Receiver Active Flag
SCI1S2_LBKDE        equ       1                   ;LIN Break Detection Enable
SCI1S2_BRK13        equ       2                   ;Break Character Generation Length
SCI1S2_RWUID        equ       3                   ;Receive Wake Up Idle Detect
SCI1S2_RXINV        equ       4                   ;Receive Data Inversion
SCI1S2_RXEDGIF      equ       6                   ;RxD Pin Active Edge Interrupt Flag
SCI1S2_LBKDIF       equ       7                   ;LIN Break Detect Interrupt Flag

SCI1C3              equ       $8E,1               ;SCI1 Control Register 3

SCI1C3_PEIE         equ       0                   ;Parity Error Interrupt Enable
SCI1C3_FEIE         equ       1                   ;Framing Error Interrupt Enable
SCI1C3_NEIE         equ       2                   ;Noise Error Interrupt Enable
SCI1C3_ORIE         equ       3                   ;Overrun Interrupt Enable
SCI1C3_TXINV        equ       4                   ;Transmit Data Inversion
SCI1C3_TXDIR        equ       5                   ;TxD Pin Direction in Single-Wire Mode
SCI1C3_T8           equ       6                   ;Ninth Data Bit for Transmitter
SCI1C3_R8           equ       7                   ;Ninth Data Bit for Receiver

SCI1D               equ       $8F,1               ;SCI1 Data Register

;-------------------------------------------------------------------------------

IICA1               equ       $90,2               ;IIC Address Register
IICA                equ       $90,1               ;IIC Address Register
IICF                equ       $91,1               ;IIC Frequency Divider Register

IICF_ICR0           equ       0                   ;IIC Clock Rate Bit 0
IICF_ICR1           equ       1                   ;IIC Clock Rate Bit 1
IICF_ICR2           equ       2                   ;IIC Clock Rate Bit 2
IICF_ICR3           equ       3                   ;IIC Clock Rate Bit 3
IICF_ICR4           equ       4                   ;IIC Clock Rate Bit 4
IICF_ICR5           equ       5                   ;IIC Clock Rate Bit 5
IICF_MULT0          equ       6                   ;Multiplier Factor Bit 0
IICF_MULT1          equ       7                   ;Multiplier Factor Bit 1

IICC1               equ       $92,1               ;IIC Control Register 1

IICC1_WUEN          equ       1                   ;Wake-up Enable
IICC1_RSTA          equ       2                   ;Repeat START
IICC1_TXAK          equ       3                   ;Transmit Acknowledge Enable
IICC1_TX            equ       4                   ;Transmit Mode Select
IICC1_MST           equ       5                   ;Master Mode Select
IICC1_IICIE         equ       6                   ;IIC Interrupt Enable
IICC1_IICEN         equ       7                   ;IIC Enable

IICC                equ       $92,1               ;IIC Control Register

IICC_WUEN           equ       1                   ;Wake-up Enable
IICC_RSTA           equ       2                   ;Repeat START
IICC_TXAK           equ       3                   ;Transmit Acknowledge Enable
IICC_TX             equ       4                   ;Transmit Mode Select
IICC_MST            equ       5                   ;Master Mode Select
IICC_IICIE          equ       6                   ;IIC Interrupt Enable
IICC_IICEN          equ       7                   ;IIC Enable

IICS                equ       $93,1               ;IIC Status Register

IICS_RXAK           equ       0                   ;Receive Acknowledge
IICS_IICIF          equ       1                   ;IIC Interrupt Flag
IICS_SRW            equ       2                   ;Slave Read/Write
IICS_ARBL           equ       4                   ;Arbitration Lost
IICS_BUSY           equ       5                   ;Bus Busy
IICS_IAAS           equ       6                   ;Addressed as a Slave
IICS_TCF            equ       7                   ;Transfer Complete Flag

IICD                equ       $94,1               ;IIC Data I/O Register
IICC2               equ       $95,1               ;IIC Control Register 2

IICC2_AD8           equ       0                   ;Slave Address Bit 8
IICC2_AD9           equ       1                   ;Slave Address Bit 9
IICC2_AD10          equ       2                   ;Slave Address Bit 10
IICC2_ADEXT         equ       6                   ;Address Extension
IICC2_GCAEN         equ       7                   ;General Call Address Enable

IICFLT              equ       $96,1               ;IIC Filter register
IICSMB              equ       $97,1               ;SMBus Control and Status Register

IICSMB_SHTF2IE      equ       0                   ;SHTF2 Interrupt Enable
IICSMB_SHTF2        equ       1                   ;SCL High Timeout Flag 2
IICSMB_SHTF1        equ       2                   ;SCL High Timeout Flag 1
IICSMB_SLTF         equ       3                   ;SCL Low Timeout Flag
IICSMB_TCKSEL       equ       4                   ;Time Out Counter Clock Select
IICSMB_SIICAEN      equ       5                   ;Second IIC Address Enable
IICSMB_ALERTEN      equ       6                   ;SMBus Alert Response Address Enable
IICSMB_FACK         equ       7                   ;Fast NACK/ACK enable

IICA2               equ       $98,1               ;IIC Address Register 2
IICSLT              equ       $99,2               ;IIC SCL Low Time Out register
IICSLTH             equ       $99,1               ;IIC SCL Low Time Out register - High byte
IICSLTL             equ       $9A,1               ;IIC SCL Low Time Out register - Low byte

;-------------------------------------------------------------------------------

FTMSC               equ       $A0,1               ;FTM Status and Control Register
FTMCNT              equ       $A1,2               ;FTM Timer Counter Register
FTMCNTH             equ       $A1,1               ;FTM Timer Counter Register High
FTMCNTL             equ       $A2,1               ;FTM Timer Counter Register Low
FTMMOD              equ       $A3,2               ;FTM Timer Counter Modulo Register
FTMMODH             equ       $A3,1               ;FTM Timer Counter Modulo Register High
FTMMODL             equ       $A4,1               ;FTM Timer Counter Modulo Register Low
FTMC0SC             equ       $A5,1               ;FTM Timer Channel 0 Status and Control Register
FTMC0V              equ       $A6,2               ;FTM Timer Channel 0 Value Register
FTMC0VH             equ       $A6,1               ;FTM Timer Channel 0 Value Register High
FTMC0VL             equ       $A7,1               ;FTM Timer Channel 0 Value Register Low
FTMC1SC             equ       $A8,1               ;FTM Timer Channel 1 Status and Control Register
FTMC1V              equ       $A9,2               ;FTM Timer Channel 1 Value Register
FTMC1VH             equ       $A9,1               ;FTM Timer Channel 1 Value Register High
FTMC1VL             equ       $AA,1               ;FTM Timer Channel 1 Value Register Low

                    @bitnum   PS0,0               ;Prescale Divisor Select Bit 0
                    @bitnum   PS1,1               ;Prescale Divisor Select Bit 1
                    @bitnum   PS2,2               ;Prescale Divisor Select Bit 2
                    @bitnum   CLKSA,3             ;Clock Source Select A
                    @bitnum   CLKSB,4             ;Clock Source Select B
                    @bitnum   CPWMS,5             ;Center-Aligned PWM Select
                    @bitnum   TOIE,6              ;Timer Overflow Interrupt Enable
                    @bitnum   TOF,7               ;Timer Overflow Flag

                    @bitnum   ELSxA,2             ;Edge/Level Select Bit A
                    @bitnum   ELSxB,3             ;Edge/Level Select Bit B
                    @bitnum   MSxA,4              ;Mode Select A for FTM Channel 1
                    @bitnum   MSxB,5              ;Mode Select B for FTM Channel 1
                    @bitnum   CHxIE,6             ;Channel 1 Interrupt Enable
                    @bitnum   CHxF,7              ;Channel 1 Flag

;-------------------------------------------------------------------------------

CRCDH               equ       $B0,2               ;CRC Data High Register (Word)
CRCDH1              equ       $B0,1               ;CRC Data High 1 (Upper Byte)
CRCDH0              equ       $B1,1               ;CRC Data High 0 (Lower Byte)
CRCDL               equ       $B2,2               ;CRC Data Low Register (Word)
CRCDL1              equ       $B2,1               ;CRC Data Low 1 (Upper Byte)
CRCDL0              equ       $B3,1               ;CRC Data Low 0 (Lower Byte)
CRCPH               equ       $B4,2               ;CRC Polynomial High (Word)
CRCPH1              equ       $B4,1               ;CRC Polynomial High Word Upper Byte
CRCPH0              equ       $B5,1               ;CRC Polynomial High Word Lower Byte
CRCPL               equ       $B6,2               ;CRC Polynomial Low (Word)
CRCPL1              equ       $B6,1               ;CRC Polynomial Low 1 (Upper Byte)
CRCPL0              equ       $B7,1               ;CRC Polynomial Low 0 (Lower Byte)
CRCCTL              equ       $B8,1               ;CRC Control Register

                    @bitnum   CRCCTL_CRCW,0       ;Width of CRC protocol
                    @bitnum   CRCCTL_SEED,1       ;Write to the CRC Data Registers is a SEED
                    @bitnum   CRCCTL_FXOR,2       ;Complement Read of CRCDH/L registers
                    @bitnum   CRCCTL_TOTR0,4      ;Type of Transpose for Read bit 0, bit 0
                    @bitnum   CRCCTL_TOTR1,5      ;Type of Transpose for Read bit 0, bit 1
                    @bitnum   CRCCTL_TOTW0,6      ;Type of Transpose for Writes, bit 0, bit 0
                    @bitnum   CRCCTL_TOTW1,7      ;Type of Transpose for Writes, bit 0, bit 1

;-------------------------------------------------------------------------------

LCDPEN0             equ       $1080,1             ;LCD Pin Enable Register 0
LCDPEN1             equ       $1081,1             ;LCD Pin Enable Register 1
LCDPEN2             equ       $1082,1             ;LCD Pin Enable Register 2
LCDPEN3             equ       $1083,1             ;LCD Pin Enable Register 3
LCDPEN4             equ       $1084,1             ;LCD Pin Enable Register 4
LCDPEN5             equ       $1085,1             ;LCD Pin Enable Register 5
LCDBPEN0            equ       $1088,1             ;LCD Backplane Enable Register 0
LCDBPEN1            equ       $1089,1             ;LCD Backplane Enable Register 1
LCDBPEN2            equ       $108A,1             ;LCD Backplane Enable Register 2
LCDBPEN3            equ       $108B,1             ;LCD Backplane Enable Register 3
LCDBPEN4            equ       $108C,1             ;LCD Backplane Enable Register 4
LCDBPEN5            equ       $108D,1             ;LCD Backplane Enable Register 5
LCDWF0              equ       $1090,1             ;LCD Waveform Register 0
LCDWF1              equ       $1091,1             ;LCD Waveform Register 1
LCDWF2              equ       $1092,1             ;LCD Waveform Register 2
LCDWF3              equ       $1093,1             ;LCD Waveform Register 3
LCDWF4              equ       $1094,1             ;LCD Waveform Register 4
LCDWF5              equ       $1095,1             ;LCD Waveform Register 5
LCDWF6              equ       $1096,1             ;LCD Waveform Register 6
LCDWF7              equ       $1097,1             ;LCD Waveform Register 7
LCDWF8              equ       $1098,1             ;LCD Waveform Register 8
LCDWF9              equ       $1099,1             ;LCD Waveform Register 9
LCDWF10             equ       $109A,1             ;LCD Waveform Register 10
LCDWF11             equ       $109B,1             ;LCD Waveform Register 11
LCDWF12             equ       $109C,1             ;LCD Waveform Register 12
LCDWF13             equ       $109D,1             ;LCD Waveform Register 13
LCDWF14             equ       $109E,1             ;LCD Waveform Register 14
LCDWF15             equ       $109F,1             ;LCD Waveform Register 15
LCDWF16             equ       $10A0,1             ;LCD Waveform Register 16
LCDWF17             equ       $10A1,1             ;LCD Waveform Register 17
LCDWF18             equ       $10A2,1             ;LCD Waveform Register 18
LCDWF19             equ       $10A3,1             ;LCD Waveform Register 19
LCDWF20             equ       $10A4,1             ;LCD Waveform Register 20
LCDWF21             equ       $10A5,1             ;LCD Waveform Register 21
LCDWF22             equ       $10A6,1             ;LCD Waveform Register 22
LCDWF23             equ       $10A7,1             ;LCD Waveform Register 23
LCDWF24             equ       $10A8,1             ;LCD Waveform Register 24
LCDWF25             equ       $10A9,1             ;LCD Waveform Register 25
LCDWF26             equ       $10AA,1             ;LCD Waveform Register 26
LCDWF27             equ       $10AB,1             ;LCD Waveform Register 27
LCDWF28             equ       $10AC,1             ;LCD Waveform Register 28
LCDWF29             equ       $10AD,1             ;LCD Waveform Register 29
LCDWF30             equ       $10AE,1             ;LCD Waveform Register 30
LCDWF31             equ       $10AF,1             ;LCD Waveform Register 31
LCDWF32             equ       $10B0,1             ;LCD Waveform Register 32
LCDWF33             equ       $10B1,1             ;LCD Waveform Register 33
LCDWF34             equ       $10B2,1             ;LCD Waveform Register 34
LCDWF35             equ       $10B3,1             ;LCD Waveform Register 35
LCDWF36             equ       $10B4,1             ;LCD Waveform Register 36
LCDWF37             equ       $10B5,1             ;LCD Waveform Register 37
LCDWF38             equ       $10B6,1             ;LCD Waveform Register 38
LCDWF39             equ       $10B7,1             ;LCD Waveform Register 39
LCDWF40             equ       $10B8,1             ;LCD Waveform Register 40
LCDWF41             equ       $10B9,1             ;LCD Waveform Register 41
LCDWF42             equ       $10BA,1             ;LCD Waveform Register 42
LCDWF43             equ       $10BB,1             ;LCD Waveform Register 43

;-------------------------------------------------------------------------------

SRS                 equ       $1800,1             ;System Reset Status Register

                    @bitnum   SRS_LVD,1           ;Low Voltage Detect
                    @bitnum   SRS_ILAD,3          ;Illegal Address
                    @bitnum   SRS_ILOP,4          ;Illegal Opcode
                    @bitnum   SRS_COP,5           ;Computer Operating Properly (COP) Watchdog
                    @bitnum   SRS_PIN,6           ;External Reset Pin
                    @bitnum   SRS_POR,7           ;Power-On Reset

;-------------------------------------------------------------------------------

SBDFR               equ       $1801,1             ;System Background Debug Force Reset Register

                    @bitnum   SBDFR_BDFR,0        ;Background Debug Force Reset

;-------------------------------------------------------------------------------

SOPT1               equ       $1802,1             ;System Options Register 1

                    @bitnum   COPW,0              ;COP Window Mode
                    @bitnum   COPCLKS,1           ;COP Watchdog Clock Select
                    @bitnum   COPT0,2             ;COP Watchdog Timeout, bit 0
                    @bitnum   COPT1,3             ;COP Watchdog Timeout, bit 1
                    @bitnum   STOPE,5             ;Stop Mode Enable
                    @bitnum   BKGDPE,7            ;Unused

;-------------------------------------------------------------------------------

SDID                equ       $1805,2             ;System Device Identification Register
SDIDH               equ       $1805,1             ;System Device Identification Register High
SDIDL               equ       $1806,1             ;System Device Identification Register Low

;-------------------------------------------------------------------------------

SCGC1               equ       $1808,1             ;System Clock Gating Control 1 Register

                    @bitnum   SCG_SCI0,0          ;SCI0 Clock Gate Control
                    @bitnum   SCG_SCI1,1          ;SCI1 Clock Gate Control
                    @bitnum   SCG_SCI2,2          ;SCI2 Clock Gate Control
                    @bitnum   SCG_SCI3,3          ;SCI3 Clock Gate Control
                    @bitnum   SCG_IIC,4           ;IIC Clock Gate Control
                    @bitnum   SCG_KBI,5           ;KBI Clock Gate Control
                    @bitnum   SCG_ADC0,6          ;ADC0 Clock Gate Control
                    @bitnum   SCG_ADC1,7          ;ADC1 Clock Gate Control

SCGC2               equ       $1809,1             ;System Clock Gating Control 2 Register

                    @bitnum   SCG_SPI0,0          ;SPI0 Clock Gate Control
                    @bitnum   SCG_SPI1,1          ;SPI1 Clock Gate Control
                    @bitnum   SCG_SPI2,2          ;SPI2 Clock Gate Control
                    @bitnum   SCG_LCD,3           ;LCD Clock Gate Control
                    @bitnum   SCG_IRQ,4           ;IRQ Clock Gate Control
                    @bitnum   SCG_VREF,5          ;VREF Clock Gate Control
                    @bitnum   SCG_CLKPRE,7        ;CLKPRE Clock Gate Control

SCGC3               equ       $180A,1             ;System Clock Gating Control 3 Register

                    @bitnum   SCG_PTA,0           ;PTA Clock Gate Control
                    @bitnum   SCG_PTB,1           ;PTB Clock Gate Control
                    @bitnum   SCG_PTC,2           ;PTC Clock Gate Control
                    @bitnum   SCG_PTD,3           ;PTD Clock Gate Control
                    @bitnum   SCG_PTE,4           ;PTE Clock Gate Control
                    @bitnum   SCG_PTF,5           ;PTF Clock Gate Control
                    @bitnum   SCG_PTG,6           ;PTG Clock Gate Control
                    @bitnum   SCG_PTH,7           ;PTH Clock Gate Control

SCGC4               equ       $180B,1             ;System Clock Gating Control 4 Register

                    @bitnum   SCG_MTIM3,0         ;MTIM3 Clock Gate Control
                    @bitnum   SCG_MTIM2,1         ;MTIM2 Clock Gate Control
                    @bitnum   SCG_MTIM1,2         ;MTIM1 Clock Gate Control
                    @bitnum   SCG_PDB,3           ;PDB Clock Gate Control
                    @bitnum   SCG_FTM,4           ;FTM Clock Gate Control
                    @bitnum   SCG_CRC,5           ;CRC Clock Gate Control
                    @bitnum   SCG_MUXCTRL,6       ;MUXCTRL Clock Gate Control

SCGC5               equ       $180C,1             ;System Clock Gating Control 5 Register

                    @bitnum   SCG_FLS,0           ;FLS Clock Gate Control
                    @bitnum   SCG_PCNT,2          ;PCNT Clock Gate Control
                    @bitnum   SCG_IRTC,3          ;IRTC Clock Gate Control
                    @bitnum   SCG_BKPT,4          ;BKPT Clock Gate Control
                    @bitnum   SCG_PRACMP0,5       ;PRACMP0 Clock Gate Control
                    @bitnum   SCG_PRACMP1,6       ;PRACMP1 Clock Gate Control
                    @bitnum   SCG_PRACMP2,7       ;PRACMP2 Clock Gate Control

;-------------------------------------------------------------------------------

SIMIPS1             equ       $180D,1             ;Internal Peripheral Select Register 1
SIMIPS2             equ       $180E,1             ;Internal Peripheral Select Register 2
SIMIPS3             equ       $180F,1             ;Internal Peripheral Select Register 3
SIMCO               equ       $1813,1             ;SIM Clock Options Register

                    @bitnum   SIMIPS1_MTIM2CS,2   ;MTIM2 External Clock Select
                    @bitnum   SIMIPS1_PCNTSS,3    ;PCNT Sensor Select
                    @bitnum   SIMIPS1_MTIM3CS,5   ;MTIM3 External Clock Select
                    @bitnum   SIMIPS1_FTMCS,6     ;FTM External Clock Select

                    @bitnum   SIMIPS2_MODTX1,0    ;Modulate TxD1
                    @bitnum   SIMIPS2_MTBASE1,2   ;SCI1 Tx Modulation Time Base Select
                    @bitnum   SIMIPS2_RX1IN,5     ;SCI1 Rx Input Pin Select

                    @bitnum   SIMIPS3_MODTX2,0    ;Modulate Tx2
                    @bitnum   SIMIPS3_DDRIVE,1    ;Double Current Drive on TxD2 Enable
                    @bitnum   SIMIPS3_MTBASE2,2   ;SCI2 Tx Modulation Time Base Select
                    @bitnum   SIMIPS3_RX2IN,5     ;SCI2 Rx Input Pin Select
                    @bitnum   SIMIPS3_PCNTFCS,6   ;PCNT Filter Clock Select

                    @bitnum   SIMCO_CS,0          ;Clock Select for CLKOUT pin

;-------------------------------------------------------------------------------

CCSCTRL             equ       $1814,1             ;Clock Check and Select Control Register

                    @bitnum   ICS_EXT_CLK_SEL,0   ;ICS External Clock Select

;-------------------------------------------------------------------------------

SPMSC1              equ       $181C,1             ;System Power Management Status and Control 1 Register

                    @bitnum   BGBE,0              ;Bandgap Buffer Enable
                    @bitnum   BGBDS,1             ;Bandgap Buffer Drive Select
                    @bitnum   LVDE,2              ;Low-Voltage Detect Enable
                    @bitnum   LVDSE,3             ;Low-Voltage Detect Stop Enable
                    @bitnum   LVDRE,4             ;Low-Voltage Detect Reset Enable
                    @bitnum   LVDIE,5             ;Low-Voltage Detect Interrupt Enable
                    @bitnum   LVDACK,6            ;Low-Voltage Detect Acknowledge
                    @bitnum   LVDF,7              ;Low-Voltage Detect Flag

SPMSC2              equ       $181D,1             ;System Power Management Status and Control 2 Register

                    @bitnum   PPDC,0              ;Partial Power Down Control
                    @bitnum   PPDE,1              ;Partial Power-Down Enable
                    @bitnum   PPDACK,2            ;Partial Power Down Acknowledge
                    @bitnum   PPDF,3              ;Partial Power Down Flag
                    @bitnum   LPWUI,5             ;Low Power Wake Up on Interrupt
                    @bitnum   LPRS,6              ;Low Power Regulator Status
                    @bitnum   LPR,7               ;Low Power Regulator Control

SPMSC3              equ       $181F,1             ;System Power Management Status and Control 3 Register

                    @bitnum   LVWIE,3             ;Low-Voltage Warning Interrupt Enable
                    @bitnum   LVWV,4              ;Low-Voltage Warning Voltage Select
                    @bitnum   LVDV,5              ;Low-Voltage Detect Voltage Select
                    @bitnum   LVWACK,6            ;Low-Voltage Warning Acknowledge
                    @bitnum   LVWF,7              ;Low-Voltage Warning Flag

;-------------------------------------------------------------------------------

FCDIV               equ       $1820,1             ;FLASH Clock Divider Register

                    @bitnum   FPRDIV8,6           ;Prescale (Divide) FLASH Clock by 8
                    @bitnum   FDIVLD,7            ;Divisor Loaded Status Flag

FOPT                equ       $1821,1             ;Flash Options Register

                    @bitnum   SEC0,0              ;Flash Security Bit 0
                    @bitnum   SEC1,1              ;Flash Security Bit 1
                    @bitnum   FNORED,6            ;Vector Redirection Disable
                    @bitnum   KEYEN,7             ;Enable Security Key Writing

FCNFG               equ       $1823,1             ;Flash Configuration Register

FCNFG_KEYACC        equ       5                   ;Enable Security Key Writing

FPROT               equ       $1824,1             ;Flash Protection Register

                    @bitnum   FPROT_FPDIS,0       ;Flash Protection Disable

FSTAT               equ       $1825,1             ;Flash Status Register

                    @bitnum   FBLANK,2            ;FLASH Flag Indicating the Erase Verify Operation Status
                    @bitnum   FACCERR,4           ;FLASH Access Error Flag
                    @bitnum   FPVIOL,5            ;FLASH Protection Violation Flag
                    @bitnum   FCCF,6              ;FLASH Command Complete Interrupt Flag
                    @bitnum   FCBEF,7             ;FLASH Command Buffer Empty Flag

FCMD                equ       $1826,1             ;Flash Command Register

;-------------------------------------------------------------------------------

BKPTCA              equ       $1830,2             ;Breakpoint Comparator A Register(word access)
BKPTCAH             equ       $1830,1             ;Breakpoint Comparator A High Register
BKPTCAL             equ       $1831,1             ;Breakpoint Comparator A Low Register

BKPTCB              equ       $1832,2             ;Breakpoint Comparator B Register(word access)
BKPTCBH             equ       $1832,1             ;Breakpoint Comparator B High Register
BKPTCBL             equ       $1833,1             ;Breakpoint Comparator B Low Register

BKPTCC              equ       $1834,2             ;Breakpoint Comparator C Register(word access)
BKPTCCH             equ       $1834,1             ;Breakpoint Comparator C High Register
BKPTCCL             equ       $1835,1             ;Breakpoint Comparator C Low Register

BKPTAC              equ       $1836,1             ;Breakpoint Comparator A Control Register

                    @bitnum   BKPTAC_FMDC,0       ;Full Mode Data Condition
                    @bitnum   BKPTAC_FMEN,1       ;Full Mode Enable Bit
                    @bitnum   BKPTAC_PAGESELA,3   ;Comparator A Page Select Bit
                    @bitnum   BKPTAC_TAGA,4       ;Tag or Force Bit
                    @bitnum   BKPTAC_RWA,5        ;Read/Write Comparator A Value Bit
                    @bitnum   BKPTAC_RWAEN,6      ;Read/Write Comparator A Enable Bit
                    @bitnum   BKPTAC_BKPTAEN,7    ;BKPT A Enable Bit

BKPTBC              equ       $1837,1             ;Breakpoint Comparator B Control Register

                    @bitnum   BKPTBC_PAGESELB,3   ;Comparator B Page Select Bit
                    @bitnum   BKPTBC_TAGB,4       ;Tag or Force Bit
                    @bitnum   BKPTBC_RWB,5        ;Read/Write Comparator B Value Bit
                    @bitnum   BKPTBC_RWBEN,6      ;Read/Write Comparator B Enable Bit
                    @bitnum   BKPTBC_BKPTBEN,7    ;BKPT B Enable Bit

BKPTBCC             equ       $1838,1             ;Breakpoint Comparator C Control Register

                    @bitnum   BKPTBCC_PAGESELC,3  ;Comparator C Page Select Bit
                    @bitnum   BKPTBCC_TAGC,4      ;Tag or Force Bit
                    @bitnum   BKPTBCC_RWC,5       ;Read/Write Comparator C Value Bit
                    @bitnum   BKPTBCC_RWCEN,6     ;Read/Write Comparator C Enable Bit
                    @bitnum   BKPTBCC_BKPTCEN,7   ;BKPT C Enable Bit

BKPTS               equ       $1839,1             ;Breakpoint Status Register

                    @bitnum   BKPTS_CF,0          ;Comparator C Match Bit
                    @bitnum   BKPTS_BF,1          ;Comparator B Match Bit
                    @bitnum   BKPTS_AF,2          ;Comparator A Match Bit

;-------------------------------------------------------------------------------

ICSC1               equ       $183C,1             ;ICS Control Register 1

                    @bitnum   IREFSTEN,0          ;Internal Reference Stop Enable
                    @bitnum   IRCLKEN,1           ;Internal Reference Clock Enable
                    @bitnum   IREFS,2             ;Internal Reference Select
                    @bitnum   RDIV0,3             ;Reference Divider, bit 0
                    @bitnum   RDIV1,4             ;Reference Divider, bit 1
                    @bitnum   RDIV2,5             ;Reference Divider, bit 2
                    @bitnum   ICS_CLKS0,6         ;Clock Source Select, bit 0
                    @bitnum   ICS_CLKS1,7         ;Clock Source Select, bit 1

ICSC2               equ       $183D,1             ;ICS Control Register 2

                    @bitnum   EREFSTEN,0          ;External Reference Stop Enable
                    @bitnum   ERCLKEN,1           ;External Reference Enable
                    @bitnum   EREFS,2             ;External Reference Select
                    @bitnum   LP,3                ;Low Power Select
                    @bitnum   HGO,4               ;High Gain Oscillator Select
                    @bitnum   RANGE_SEL,5         ;Frequency Range Select
                    @bitnum   BDIV0,6             ;Bus Frequency Divider, bit 0
                    @bitnum   BDIV1,7             ;Bus Frequency Divider, bit 1

ICSTRM              equ       $183E,1             ;ICS Trim Register

ICSSC               equ       $183F,1             ;ICS Status and Control Register

ICSSC_FTRIM         equ       0                   ;ICS Fine Trim
ICSSC_OSCINIT       equ       1                   ;OSC Initialization
ICSSC_CLKST0        equ       2                   ;Clock Mode Status, bit 0
ICSSC_CLKST1        equ       3                   ;Clock Mode Status, bit 1
ICSSC_IREFST        equ       4                   ;Internal Reference Status
ICSSC_DMX32         equ       5                   ;DCO Maximum frequency with 32.768 kHz reference
ICSSC_DRST_DRS0     equ       6                   ;DCO Range Status/Range Select, bit 0
ICSSC_DRST_DRS1     equ       7                   ;DCO Range Status/Range Select, bit 1

;-------------------------------------------------------------------------------

ADC0CV1             equ       $1840,2             ;Compare Value 1 Register
ADC0CV1H            equ       $1840,1             ;Compare Value 1 High Register
ADC0CV1L            equ       $1841,1             ;Compare Value 1 Low Register

ADC0CV2             equ       $1842,2             ;Compare Value 2 Register
ADC0CV2H            equ       $1842,1             ;Compare Value 2 High Register
ADC0CV2L            equ       $1843,1             ;Compare Value 2 Low Register

ADC0SC2             equ       $1844,1             ;Status and Control Register 2

ADC0SC2_REFSEL0     equ       0                   ;Voltage Reference Selection, bit 0
ADC0SC2_REFSEL1     equ       1                   ;Voltage Reference Selection, bit 1
ADC0SC2_ACREN       equ       3                   ;Compare Function Range Enable
ADC0SC2_ACFGT       equ       4                   ;Compare Function Greater Than Enable
ADC0SC2_ACFE        equ       5                   ;Compare Function Enable - ACFE is used to enable the compare function
ADC0SC2_ADTRG       equ       6                   ;Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADC0SC2_ADACT       equ       7                   ;Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a

ADC0SC3             equ       $1845,1             ;Status and Control Register 3

ADC0SC3_AVGS0       equ       0                   ;Hardware Average select, bit 0
ADC0SC3_AVGS1       equ       1                   ;Hardware Average select, bit 1
ADC0SC3_AVGE        equ       2                   ;Hardware average enable - AVGE enables the hardware average function of the ADC
ADC0SC3_ADCO        equ       3                   ;Continuous Conversion Enable - ADCO enables continuous conversions
ADC0SC3_CALF        equ       6                   ;Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC0SC3_CAL         equ       7                   ;Calibration - CAL begins the calibration sequence when set

ADC0OFS             equ       $1846,2             ;Offset Correction Register
ADC0OFSH            equ       $1846,1             ;Offset Correction High Register
ADC0OFSL            equ       $1847,1             ;Offset Correction Low Register
ADC0PG              equ       $1848,2             ;Plus-Side Gain Register
ADC0PGH             equ       $1848,1             ;Plus-Side Gain High Register
ADC0PGL             equ       $1849,1             ;Plus-Side Gain Low Register
ADC0MG              equ       $184A,2             ;Minus-Side Gain Register
ADC0MGH             equ       $184A,1             ;Minus-Side Gain High Register
ADC0MGL             equ       $184B,1             ;Minus-Side Gain Low Register
ADC0CLPD            equ       $184C,1             ;Plus-Side General Calibration Value D Register

ADC0CLPD_CLPD0      equ       0                   ;Plus-Side General Calibration Value D bit 0
ADC0CLPD_CLPD1      equ       1                   ;Plus-Side General Calibration Value D bit 1
ADC0CLPD_CLPD2      equ       2                   ;Plus-Side General Calibration Value D bit 2
ADC0CLPD_CLPD3      equ       3                   ;Plus-Side General Calibration Value D bit 3
ADC0CLPD_CLPD4      equ       4                   ;Plus-Side General Calibration Value D bit 4
ADC0CLPD_CLPD5      equ       5                   ;Plus-Side General Calibration Value D bit 5

ADC0CLPS            equ       $184D,1             ;Plus-Side General Calibration Value S Register

ADC0CLPS_CLPS0      equ       0                   ;Plus-Side General Calibration Value S bit 0
ADC0CLPS_CLPS1      equ       1                   ;Plus-Side General Calibration Value S bit 1
ADC0CLPS_CLPS2      equ       2                   ;Plus-Side General Calibration Value S bit 2
ADC0CLPS_CLPS3      equ       3                   ;Plus-Side General Calibration Value S bit 3
ADC0CLPS_CLPS4      equ       4                   ;Plus-Side General Calibration Value S bit 4
ADC0CLPS_CLPS5      equ       5                   ;Plus-Side General Calibration Value S bit 5

ADC0CLP4            equ       $184E,2             ;Plus-Side General Calibration Value 4 Register
ADC0CLP4H           equ       $184E,1             ;Plus-Side General Calibration Value 4 High Register

ADC0CLP4H_CLP48     equ       0                   ;Plus-Side General Calibration Value 4 bit 8
ADC0CLP4H_CLP49     equ       1                   ;Plus-Side General Calibration Value 4 bit 9

ADC0CLP4L           equ       $184F,1             ;Plus-Side General Calibration Value 4 Low Register
ADC0CLP3            equ       $1850,2             ;Plus-Side General Calibration Value 3 Register
ADC0CLP3H           equ       $1850,1             ;Plus-Side General Calibration Value 3 High Register
ADC0CLP3L           equ       $1851,1             ;Plus-Side General Calibration Value 3 Low Register
ADC0CLP2            equ       $1852,1             ;Plus-Side General Calibration Value 2 Register
ADC0CLP1            equ       $1853,1             ;Plus-Side General Calibration Value 1 Register
ADC0CLP0            equ       $1854,1             ;Plus-Side General Calibration Value 0 Register

ADC0CLMD            equ       $1856,1             ;Minus-Side General Calibration Value D Register

ADC0CLMD_CLMD0      equ       0                   ;Minus-Side General Calibration Value D bit 0
ADC0CLMD_CLMD1      equ       1                   ;Minus-Side General Calibration Value D bit 1
ADC0CLMD_CLMD2      equ       2                   ;Minus-Side General Calibration Value D bit 2
ADC0CLMD_CLMD3      equ       3                   ;Minus-Side General Calibration Value D bit 3
ADC0CLMD_CLMD4      equ       4                   ;Minus-Side General Calibration Value D bit 4
ADC0CLMD_CLMD5      equ       5                   ;Minus-Side General Calibration Value D bit 5

ADC0CLMS            equ       $1857,1             ;Minus-Side General Calibration Value S Register

ADC0CLMS_CLMS0      equ       0                   ;Minus-Side General Calibration Value S bit 0
ADC0CLMS_CLMS1      equ       1                   ;Minus-Side General Calibration Value S bit 1
ADC0CLMS_CLMS2      equ       2                   ;Minus-Side General Calibration Value S bit 2
ADC0CLMS_CLMS3      equ       3                   ;Minus-Side General Calibration Value S bit 3
ADC0CLMS_CLMS4      equ       4                   ;Minus-Side General Calibration Value S bit 4
ADC0CLMS_CLMS5      equ       5                   ;Minus-Side General Calibration Value S bit 5

ADC0CLM4            equ       $1858,2             ;Minus-Side General Calibration Value 4 Register
ADC0CLM4H           equ       $1858,1             ;Minus-Side General Calibration Value 4 High Register
ADC0CLM4L           equ       $1859,1             ;Minus-Side General Calibration Value 4 Low Register
ADC0CLM3            equ       $185A,2             ;Minus-Side General Calibration Value 3 Register
ADC0CLM3H           equ       $185A,1             ;Minus-Side General Calibration Value 3 High Register
ADC0CLM3L           equ       $185B,1             ;Minus-Side General Calibration Value 3 Low Register
ADC0CLM2            equ       $185C,1             ;Minus-Side General Calibration Value 2 Register
ADC0CLM1            equ       $185D,1             ;Minus-Side General Calibration Value 1 Register
ADC0CLM0            equ       $185E,1             ;Minus-Side General Calibration Value 0 Register

;-------------------------------------------------------------------------------

CLK_PRSC            equ       $1864,2             ;CLKOUT Prescaler Register
CLK_PRSC_H          equ       $1864,1             ;CLKOUT Prescaler Register High
CLK_PRSC_L          equ       $1865,1             ;CLKOUT Prescaler Register Low

                    @bitnum   CLK_PRSC_H_BIT,0    ;CLKOUT Prescaler match value bits

;-------------------------------------------------------------------------------

SCI2BD              equ       $1868,2             ;SCI2 Baud Rate Register
SCI2BDH             equ       $1868,1             ;SCI2 Baud Rate Register High
SCI2BDL             equ       $1869,1             ;SCI2 Baud Rate Register Low
SCI2C1              equ       $186A,1             ;SCI2 Control Register 1

SCI2C1_PT           equ       0                   ;Parity Type
SCI2C1_PE           equ       1                   ;Parity Enable
SCI2C1_ILT          equ       2                   ;Idle Line Type Select
SCI2C1_WAKE         equ       3                   ;Receiver Wakeup Method Select
SCI2C1_M            equ       4                   ;9-Bit or 8-Bit Mode Select
SCI2C1_RSRC         equ       5                   ;Receiver Source Select
SCI2C1_SCISWAI      equ       6                   ;SCI Stops in Wait Mode
SCI2C1_LOOPS        equ       7                   ;Loop Mode Select

SCI2C2              equ       $186B,1             ;SCI2 Control Register 2

SCI2C2_SBK          equ       0                   ;Send Break
SCI2C2_RWU          equ       1                   ;Receiver Wakeup Control
SCI2C2_RE           equ       2                   ;Receiver Enable
SCI2C2_TE           equ       3                   ;Transmitter Enable
SCI2C2_ILIE         equ       4                   ;Idle Line Interrupt Enable (for IDLE)
SCI2C2_RIE          equ       5                   ;Receiver Interrupt Enable (for RDRF)
SCI2C2_TCIE         equ       6                   ;Transmission Complete Interrupt Enable (for TC)
SCI2C2_TIE          equ       7                   ;Transmit Interrupt Enable (for TDRE)

SCI2S1              equ       $186C,1             ;SCI2 Status Register 1

SCI2S1_PF           equ       0                   ;Parity Error Flag
SCI2S1_FE           equ       1                   ;Framing Error Flag
SCI2S1_NF           equ       2                   ;Noise Flag
SCI2S1_OR           equ       3                   ;Receiver Overrun Flag
SCI2S1_IDLE         equ       4                   ;Idle Line Flag
SCI2S1_RDRF         equ       5                   ;Receive Data Register Full Flag
SCI2S1_TC           equ       6                   ;Transmission Complete Flag
SCI2S1_TDRE         equ       7                   ;Transmit Data Register Empty Flag

SCI2S2              equ       $186D,1             ;SCI2 Status Register 2

SCI2S2_RAF          equ       0                   ;Receiver Active Flag
SCI2S2_LBKDE        equ       1                   ;LIN Break Detection Enable
SCI2S2_BRK13        equ       2                   ;Break Character Generation Length
SCI2S2_RWUID        equ       3                   ;Receive Wake Up Idle Detect
SCI2S2_RXINV        equ       4                   ;Receive Data Inversion
SCI2S2_RXEDGIF      equ       6                   ;RxD Pin Active Edge Interrupt Flag
SCI2S2_LBKDIF       equ       7                   ;LIN Break Detect Interrupt Flag

SCI2C3              equ       $186E,1             ;SCI2 Control Register 3

SCI2C3_PEIE         equ       0                   ;Parity Error Interrupt Enable
SCI2C3_FEIE         equ       1                   ;Framing Error Interrupt Enable
SCI2C3_NEIE         equ       2                   ;Noise Error Interrupt Enable
SCI2C3_ORIE         equ       3                   ;Overrun Interrupt Enable
SCI2C3_TXINV        equ       4                   ;Transmit Data Inversion
SCI2C3_TXDIR        equ       5                   ;TxD Pin Direction in Single-Wire Mode
SCI2C3_T8           equ       6                   ;Ninth Data Bit for Transmitter
SCI2C3_R8           equ       7                   ;Ninth Data Bit for Receiver

SCI2D               equ       $186F,1             ;SCI2 Data Register

SCI3BD              equ       $1870,2             ;SCI3 Baud Rate Register
SCI3BDH             equ       $1870,1             ;SCI3 Baud Rate Register High
SCI3BDL             equ       $1871,1             ;SCI3 Baud Rate Register Low
SCI3C1              equ       $1872,1             ;SCI3 Control Register 1

SCI3C1_PT           equ       0                   ;Parity Type
SCI3C1_PE           equ       1                   ;Parity Enable
SCI3C1_ILT          equ       2                   ;Idle Line Type Select
SCI3C1_WAKE         equ       3                   ;Receiver Wakeup Method Select
SCI3C1_M            equ       4                   ;9-Bit or 8-Bit Mode Select
SCI3C1_RSRC         equ       5                   ;Receiver Source Select
SCI3C1_SCISWAI      equ       6                   ;SCI Stops in Wait Mode
SCI3C1_LOOPS        equ       7                   ;Loop Mode Select

SCI3C2              equ       $1873,1             ;SCI3 Control Register 2

SCI3C2_SBK          equ       0                   ;Send Break
SCI3C2_RWU          equ       1                   ;Receiver Wakeup Control
SCI3C2_RE           equ       2                   ;Receiver Enable
SCI3C2_TE           equ       3                   ;Transmitter Enable
SCI3C2_ILIE         equ       4                   ;Idle Line Interrupt Enable (for IDLE)
SCI3C2_RIE          equ       5                   ;Receiver Interrupt Enable (for RDRF)
SCI3C2_TCIE         equ       6                   ;Transmission Complete Interrupt Enable (for TC)
SCI3C2_TIE          equ       7                   ;Transmit Interrupt Enable (for TDRE)

SCI3S1              equ       $1874,1             ;SCI3 Status Register 1

SCI3S1_PF           equ       0                   ;Parity Error Flag
SCI3S1_FE           equ       1                   ;Framing Error Flag
SCI3S1_NF           equ       2                   ;Noise Flag
SCI3S1_OR           equ       3                   ;Receiver Overrun Flag
SCI3S1_IDLE         equ       4                   ;Idle Line Flag
SCI3S1_RDRF         equ       5                   ;Receive Data Register Full Flag
SCI3S1_TC           equ       6                   ;Transmission Complete Flag
SCI3S1_TDRE         equ       7                   ;Transmit Data Register Empty Flag

SCI3S2              equ       $1875,1             ;SCI3 Status Register 2

SCI3S2_RAF          equ       0                   ;Receiver Active Flag
SCI3S2_LBKDE        equ       1                   ;LIN Break Detection Enable
SCI3S2_BRK13        equ       2                   ;Break Character Generation Length
SCI3S2_RWUID        equ       3                   ;Receive Wake Up Idle Detect
SCI3S2_RXINV        equ       4                   ;Receive Data Inversion
SCI3S2_RXEDGIF      equ       6                   ;RxD Pin Active Edge Interrupt Flag
SCI3S2_LBKDIF       equ       7                   ;LIN Break Detect Interrupt Flag

SCI3C3              equ       $1876,1             ;SCI3 Control Register 3

SCI3C3_PEIE         equ       0                   ;Parity Error Interrupt Enable
SCI3C3_FEIE         equ       1                   ;Framing Error Interrupt Enable
SCI3C3_NEIE         equ       2                   ;Noise Error Interrupt Enable
SCI3C3_ORIE         equ       3                   ;Overrun Interrupt Enable
SCI3C3_TXINV        equ       4                   ;Transmit Data Inversion
SCI3C3_TXDIR        equ       5                   ;TxD Pin Direction in Single-Wire Mode
SCI3C3_T8           equ       6                   ;Ninth Data Bit for Transmitter
SCI3C3_R8           equ       7                   ;Ninth Data Bit for Receiver

SCI3D               equ       $1877,1             ;SCI3 Data Register

;-------------------------------------------------------------------------------

LCDC0               equ       $1878,1             ;LCD Control Register 0

LCDC0_DUTY0         equ       0                   ;LCD Duty Select Bit 0
LCDC0_DUTY1         equ       1                   ;LCD Duty Select Bit 1
LCDC0_DUTY2         equ       2                   ;LCD Duty Select Bit 2
LCDC0_LCLK0         equ       3                   ;LCD Clock Prescaler Bit 0
LCDC0_LCLK1         equ       4                   ;LCD Clock Prescaler Bit 1
LCDC0_LCLK2         equ       5                   ;LCD Clock Prescaler Bit 2
LCDC0_SOURCE        equ       6                   ;LCD Clock Source Select
LCDC0_LCDEN         equ       7                   ;LCD Driver Enable

LCDC1               equ       $1879,1             ;LCD Control Register 1

LCDC1_LCDSTP        equ       0                   ;LCD Module Driver and Charge Pump Stop While in Stop2 or Stop3 Mode
LCDC1_LCDWAI        equ       1                   ;LCD Module Driver and Charge Pump Stop While in Wait Mode
LCDC1_FCDEN         equ       2                   ;Full Complementary Drive Enable
LCDC1_LCDIEN        equ       7                   ;LCD Module Frame Frequency Interrupt Enable

LCDSUPPLY           equ       $187A,1             ;LCD Voltage Supply Register

LCDSUPPLY_VSUPPLY0  equ       0                   ;Voltage Supply Control Bit 0
LCDSUPPLY_VSUPPLY1  equ       1                   ;Voltage Supply Control Bit 1
LCDSUPPLY_BBYPASS   equ       2                   ;Op Amp Control
LCDSUPPLY_LADJ0     equ       4                   ;LCD Module Load Adjust Bit 0
LCDSUPPLY_LADJ1     equ       5                   ;LCD Module Load Adjust Bit 1
LCDSUPPLY_HREFSEL   equ       6                   ;High Reference Select
LCDSUPPLY_CPSEL     equ       7                   ;Charge Pump or Resistor Bias Select

LCDRVC              equ       $187B,1             ;LCD Regulated Voltage Control Register

LCDRVC_RVTRIM0      equ       0                   ;Regulated Voltage Trim Bit 0
LCDRVC_RVTRIM1      equ       1                   ;Regulated Voltage Trim Bit 1
LCDRVC_RVTRIM2      equ       2                   ;Regulated Voltage Trim Bit 2
LCDRVC_RVTRIM3      equ       3                   ;Regulated Voltage Trim Bit 3
LCDRVC_RVEN         equ       7                   ;Regulated Voltage Enable

LCDBCTL             equ       $187C,1             ;LCD Blink Control Register

LCDBCTL_BRATE0      equ       0                   ;Blink-Rate Configuration Bit 0
LCDBCTL_BRATE1      equ       1                   ;Blink-Rate Configuration Bit 1
LCDBCTL_BRATE2      equ       2                   ;Blink-Rate Configuration Bit 2
LCDBCTL_BMODE       equ       3                   ;Blink Mode
LCDBCTL_BLANK       equ       5                   ;Blank Display Mode
LCDBCTL_ALT         equ       6                   ;Alternate Display Mode
LCDBCTL_BLINK       equ       7                   ;Blink Command

LCDS                equ       $187D,1             ;LCD Status Register

                    @bitnum   LCDS_LCDIF,7        ;LCD Interrupt Flag

;-------------------------------------------------------------------------------

IRTC_YEARMON        equ       $1880,2             ;RTC Year and Month Counters Register (binary format)
IRTC_YEARMON_H      equ       $1880,1             ;RTC Year and Month Counters Register High(binary format)
IRTC_YEARMON_L      equ       $1881,1             ;RTC Year and Month Counters Register Low(binary format)
IRTC_DAYS           equ       $1882,2             ;RTC Days Counter Register (binary format)
IRTC_DAYS_H         equ       $1882,1             ;RTC Days Counter Register High(binary format)
IRTC_DAYS_L         equ       $1883,1             ;RTC Days Counter Register Low(binary format)
IRTC_HOURMIN        equ       $1884,2             ;RTC Hours and Minutes Counter Register (binary format)
IRTC_HOURMIN_H      equ       $1884,1             ;RTC Hours and Minutes Counter Register High(binary format)
IRTC_HOURMIN_L      equ       $1885,1             ;RTC Hours and Minutes Counter Register Low(binary format)
IRTC_SECONDS        equ       $1886,2             ;RTC Seconds Counter Register (binary format)
IRTC_SECONDS_H      equ       $1886,1             ;RTC Seconds Counter Register High(binary format)
IRTC_SECONDS_L      equ       $1887,1             ;RTC Seconds Counter Register Low (binary format)
IRTC_ALM_YRMON      equ       $1888,2             ;RTC Year and Month Alarm Register (binary format)
IRTC_ALM_YRMON_H    equ       $1888,1             ;RTC Year and Month Alarm Register High(binary format)
IRTC_ALM_YRMON_L    equ       $1889,1             ;RTC Year and Month Alarm Register Low(binary format)
IRTC_ALM_DAYS       equ       $188A,2             ;RTC Day Alarm Register (binary format)
IRTC_ALM_DAYS_H     equ       $188A,1             ;RTC Day Alarm Register High(binary format)
IRTC_ALM_DAYS_L     equ       $188B,1             ;RTC Day Alarm Register Low(binary format)
IRTC_ALM_HM         equ       $188C,2             ;RTC Hours and Minutes Alarm Register (binary format)
IRTC_ALM_HM_H       equ       $188C,1             ;RTC Hours and Minutes Alarm Register High(binary format)
IRTC_ALM_HM_L       equ       $188D,1             ;RTC Hours and Minutes Alarm Register Low(binary format)
IRTC_ALM_SEC        equ       $188E,2             ;RTC Seconds Alarm Register (binary format)
IRTC_ALM_SEC_H      equ       $188E,1             ;RTC Seconds Alarm Register High(binary format)
IRTC_ALM_SEC_L      equ       $188F,1             ;RTC Seconds Alarm Register Low(binary format)
IRTC_CTRL           equ       $1890,2             ;RTC Control Register
IRTC_CTRL_H         equ       $1890,1             ;RTC Control Register High
IRTC_CTRL_L         equ       $1891,1             ;RTC Control Register Low

                    @bitnum   IRTC_CTRL_H_SWR,0   ;Software reset

                    @bitnum   IRTC_ALM_DEC_S,0    ;Controls the decrement of seconds counter
                    @bitnum   IRTC_ALM_INC_S,1    ;Controls the increment of seconds counter

                    @bitnum   RTC_CLKOUT0,5       ;Off-chip clock output enable bits, bit 0
                    @bitnum   RTC_CLKOUT1,6       ;Off-chip clock output enable bits, bit 1

                    @bitnum   IRTC_WE0,0          ;Write enable bits, bit 0
                    @bitnum   IRTC_WE1,1          ;Write enable bits, bit 1
                    @bitnum   IRTC_ALARM_MATCH0,2 ;Alarm match bits, bit 0
                    @bitnum   IRTC_ALARM_MATCH1,3 ;Alarm match bits, bit 1
                    @bitnum   IRTC_DSTEN,6        ;Daylight saving enable

IRTC_STATUS         equ       $1892,2             ;RTC Status Register
IRTC_STATUS_H       equ       $1892,1             ;RTC Status Register High
IRTC_STATUS_L       equ       $1893,1             ;RTC Status Register Low

IRTC_STATUS_L_INVAL equ       0                   ;Invalid time bit
IRTC_STATUS_L_C_DON equ       1                   ;Compensation one bit
IRTC_STATUS_L_BERR  equ       2                   ;Bus error bit
IRTC_STATUS_L_OCAL  equ       3                   ;Calibration output bit or compensation interval bit
IRTC_STATUS_L_WPE   equ       4                   ;Write protect enable
IRTC_STATUS_L_CLV   equ       5                   ;CPU low voltage
IRTC_STATUS_L_PORB  equ       6                   ;Boot Source after POR

IRTC_ISR            equ       $1894,2             ;RTC Interrupt Status Register
IRTC_ISR_H          equ       $1894,1             ;RTC Interrupt Status Register High

IRTC_ISR_H_SAM0     equ       0                   ;Sampling timer 0 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM1     equ       1                   ;Sampling timer 1 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM2     equ       2                   ;Sampling timer 2 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM3     equ       3                   ;Sampling timer 3 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM4     equ       4                   ;Sampling timer 4 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM5     equ       5                   ;Sampling timer 5 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM6     equ       6                   ;Sampling timer 6 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate
IRTC_ISR_H_SAM7     equ       7                   ;Sampling timer 7 interrupt flag. Indicates than an interrupt has occurred at the corresponding sampling rate

IRTC_ISR_L          equ       $1895,1             ;RTC Interrupt Status Register Low

IRTC_ISR_L_TMPR     equ       0                   ;Tamper detect interrupt
IRTC_ISR_L_CDT      equ       1                   ;Countdown timer expiry flag
IRTC_ISR_L_ALM      equ       2                   ;Alarm flag
IRTC_ISR_L_DAY      equ       3                   ;Day flag
IRTC_ISR_L_HR       equ       4                   ;Hour flag
IRTC_ISR_L_MIN      equ       5                   ;Minutes flag
IRTC_ISR_L_1HZ      equ       6                   ;Interrupt flag 1 Hz. Indicates an interrupt has occurred. If enabled, this bit is set every
IRTC_ISR_L_2HZ      equ       7                   ;Interrupt flag 2 Hz. Indicates an interrupt has occurred. If enabled, this bit is set every

IRTC_IER            equ       $1896,2             ;RTC Interrupt Enable Register
IRTC_IER_H          equ       $1896,1             ;RTC Interrupt Enable Register High
IRTC_IER_L          equ       $1897,1             ;RTC Interrupt Enable Register Low

IRTC_IER_L_TMPR     equ       0                   ;Tamper detect interrupt
IRTC_IER_L_CDT      equ       1                   ;Countdown timer expiry flag
IRTC_IER_L_ALM      equ       2                   ;Alarm flag
IRTC_IER_L_DAY      equ       3                   ;Day flag
IRTC_IER_L_HR       equ       4                   ;Hour flag
IRTC_IER_L_MIN      equ       5                   ;Minutes flag
IRTC_IER_L_1HZ      equ       6                   ;Sampling timer interrupt at 1 Hz frequency
IRTC_IER_L_2HZ      equ       7                   ;Sampling timer interrupt at 2 Hz frequency

IRTC_COUNT_DN       equ       $1898,2             ;RTC Countdown (Minutes) Timer Register (binary format)
IRTC_COUNT_DN_H     equ       $1898,1             ;RTC Countdown (Minutes) Timer Register High(binary format)
IRTC_COUNT_DN_L     equ       $1899,1             ;RTC Countdown (Minutes) Timer Register Low(binary format)
IRTC_DST_HOUR       equ       $18A2,2             ;RTC Daylight Saving Hour Register
IRTC_DST_HOUR_H     equ       $18A2,1             ;RTC Daylight Saving Hour Register High
IRTC_DST_HOUR_L     equ       $18A3,1             ;RTC Daylight Saving Hour Register Low
IRTC_DST_MNTH       equ       $18A4,2             ;RTC Daylight Saving Month Register
IRTC_DST_MNTH_H     equ       $18A4,1             ;RTC Daylight Saving Month Register High
IRTC_DST_MNTH_L     equ       $18A5,1             ;RTC Daylight Saving Month Register Low
IRTC_DST_DAY        equ       $18A6,2             ;RTC Daylight Saving Day Register
IRTC_DST_DAY_H      equ       $18A6,1             ;RTC Daylight Saving Day Register High
IRTC_DST_DAY_L      equ       $18A7,1             ;RTC Daylight Saving Day Register Low
IRTC_COMPEN         equ       $18A8,2             ;RTC Compensation Register
IRTC_COMPEN_H       equ       $18A8,1             ;RTC Compensation Register High
IRTC_COMPEN_L       equ       $18A9,1             ;RTC Compensation Register Low
IRTC_TTSR_YM        equ       $18AA,2             ;RTC Tamper Time Stamp Month & Year Register
IRTC_TTSR_YM_H      equ       $18AA,1             ;RTC Tamper Time Stamp Month & Year Register High
IRTC_TTSR_YM_L      equ       $18AB,1             ;RTC Tamper Time Stamp Month & Year Register Low
IRTC_TTSR_DAY       equ       $18AC,2             ;RTC Tamper Time Stamp Day Register
IRTC_TTSR_DAY_H     equ       $18AC,1             ;RTC Tamper Time Stamp Day Register High
IRTC_TTSR_DAY_L     equ       $18AD,1             ;RTC Tamper Time Stamp Day Register Low
IRTC_TTSR_HM        equ       $18AE,2             ;RTC Tamper Time Stamp Hours & Minutes Register
IRTC_TTSR_HM_H      equ       $18AE,1             ;RTC Tamper Time Stamp Hours & Minutes Register High
IRTC_TTSR_HM_L      equ       $18AF,1             ;RTC Tamper Time Stamp Hours & Minutes Register Low
IRTC_TTSR_SEC       equ       $18B0,2             ;RTC Tamper Time Stamp Seconds Register
IRTC_TTSR_SEC_H     equ       $18B0,1             ;RTC Tamper Time Stamp Seconds Register High
IRTC_TTSR_SEC_L     equ       $18B1,1             ;RTC Tamper Time Stamp Seconds Register Low
IRTC_TAMPER_SCR     equ       $18B2,2             ;Tamper Status & Control Register
IRTC_TAMPER_SCR_H   equ       $18B2,1             ;Tamper Status & Control Register High
IRTC_TAMPER_SCR_L   equ       $18B3,1             ;Tamper Status & Control Register Low
IRTC_FILTER01_CTRL  equ       $18B4,2             ;Tamper Filter 0 & 1 Control Register
IRTC_FILTER23_CTRL  equ       $18B6,2             ;Tamper Filter 2 & 3 Control Register
IRTC_FILTER23_CTRLH equ       $18B6,1             ;Tamper Filter 2 & 3 Control Register High
IRTC_FILTER23_CTRLL equ       $18B7,1             ;Tamper Filter 2 & 3 Control Register Low

                    @bitnum   BAT_TAMPER_STATUS,0 ;Battery Tamper Status Bit
                    @bitnum   TAMPER1_STATUS,1    ;Tamper Pin1 Status Bit
                    @bitnum   TAMPER2_STATUS,2    ;Tamper Pin2 Status Bit

                    @bitnum   BAT_TAMPER_CTRL,0   ;Battery Tamper Control Bit
                    @bitnum   TAMPER1_CTRL,1      ;Tamper Pin1 Control Bits
                    @bitnum   TAMPER2_CTRL,2      ;Tamper Pin2 Control Bits

                    @bitnum   IRTC_CLKSEL,6       ;Tamper Filter 1 Clock Select
                    @bitnum   IRTC_POL,7          ;Tamper Detect Input Bit 1 Polarity Control

;-------------------------------------------------------------------------------

PTAPE               equ       $18E0,1             ;Port A Pull Enable Register
PTASE               equ       $18E1,1             ;Port A Slew Rate Enable Register
PTADS               equ       $18E2,1             ;Port A Drive Strength Selection Register
PTAIFE              equ       $18E3,1             ;Port A Input Filter Enable Register
PTBPE               equ       $18E4,1             ;Port B Pull Enable Register
PTBSE               equ       $18E5,1             ;Port B Slew Rate Enable Register
PTBDS               equ       $18E6,1             ;Port B Drive Strength Selection Register
PTBIFE              equ       $18E7,1             ;Port B Input Filter Enable Register
PTCPE               equ       $18E8,1             ;Port C Pull Enable Register
PTCSE               equ       $18E9,1             ;Port C Slew Rate Enable Register
PTCDS               equ       $18EA,1             ;Port C Drive Strength Selection Register
PTCIFE              equ       $18EB,1             ;Port C Input Filter Enable Register
PTDPE               equ       $18EC,1             ;Port D Pull Enable Register
PTDSE               equ       $18ED,1             ;Port D Slew Rate Enable Register
PTDDS               equ       $18EE,1             ;Port D Drive Strength Selection Register
PTDIFE              equ       $18EF,1             ;Port D Input Filter Enable Register
PTEPE               equ       $18F0,1             ;Port E Pull Enable Register
PTESE               equ       $18F1,1             ;Port E Slew Rate Enable Register
PTEDS               equ       $18F2,1             ;Port E Drive Strength Selection Register
PTEIFE              equ       $18F3,1             ;Port E Input Filter Enable Register
PTFPE               equ       $18F4,1             ;Port F Pull Enable Register
PTFSE               equ       $18F5,1             ;Port F Slew Rate Enable Register
PTFDS               equ       $18F6,1             ;Port F Drive Strength Selection Register
PTFIFE              equ       $18F7,1             ;Port F Input Filter Enable Register
PTGPE               equ       $18F8,1             ;Port G Pull Enable Register
PTGSE               equ       $18F9,1             ;Port G Slew Rate Enable Register
PTGDS               equ       $18FA,1             ;Port G Drive Strength Selection Register
PTGIFE              equ       $18FB,1             ;Port G Input Filter Enable Register
PTHPE               equ       $18FC,1             ;Port H Pull Enable Register
PTHSE               equ       $18FD,1             ;Port H Slew Rate Enable Register
PTHDS               equ       $18FE,1             ;Port H Drive Strength Selection Register
PTHIFE              equ       $18FF,1             ;Port H Input Filter Enable Register

;-------------------------------------------------------------------------------

ADC1CV1             equ       $1900,2             ;Compare Value 1 Register
ADC1CV1H            equ       $1900,1             ;Compare Value 1 High Register
ADC1CV1L            equ       $1901,1             ;Compare Value 1 Low Register

ADC1CV2             equ       $1902,2             ;Compare Value 2 Register
ADC1CV2H            equ       $1902,1             ;Compare Value 2 High Register
ADC1CV2L            equ       $1903,1             ;Compare Value 2 Low Register

ADC1SC2             equ       $1904,1             ;Status and Control Register 2

ADC1SC2_REFSEL0     equ       0                   ;Voltage Reference Selection, bit 0
ADC1SC2_REFSEL1     equ       1                   ;Voltage Reference Selection, bit 1
ADC1SC2_ACREN       equ       3                   ;Compare Function Range Enable
ADC1SC2_ACFGT       equ       4                   ;Compare Function Greater Than Enable
ADC1SC2_ACFE        equ       5                   ;Compare Function Enable - ACFE is used to enable the compare function
ADC1SC2_ADTRG       equ       6                   ;Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating
ADC1SC2_ADACT       equ       7                   ;Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a

ADC1SC3             equ       $1905,1             ;Status and Control Register 3

ADC1SC3_AVGS0       equ       0                   ;Hardware Average select, bit 0
ADC1SC3_AVGS1       equ       1                   ;Hardware Average select, bit 1
ADC1SC3_AVGE        equ       2                   ;Hardware average enable - AVGE enables the hardware average function of the ADC
ADC1SC3_ADCO        equ       3                   ;Continuous Conversion Enable - ADCO enables continuous conversions
ADC1SC3_CALF        equ       6                   ;Calibration Failed Flag - CALF displays the result of the calibration sequence
ADC1SC3_CAL         equ       7                   ;Calibration - CAL begins the calibration sequence when set

ADC1OFS             equ       $1906,2             ;Offset Correction Register
ADC1OFSH            equ       $1906,1             ;Offset Correction High Register
ADC1OFSL            equ       $1907,1             ;Offset Correction Low Register

ADC1PG              equ       $1908,2             ;Plus-Side Gain Register
ADC1PGH             equ       $1908,1             ;Plus-Side Gain High Register
ADC1PGL             equ       $1909,1             ;Plus-Side Gain Low Register

ADC1MG              equ       $190A,2             ;Minus-Side Gain Register
ADC1MGH             equ       $190A,1             ;Minus-Side Gain High Register
ADC1MGL             equ       $190B,1             ;Minus-Side Gain Low Register

ADC1CLPD            equ       $190C,1             ;Plus-Side General Calibration Value D Register

ADC1CLPD_CLPD0      equ       0                   ;Plus-Side General Calibration Value D bit 0
ADC1CLPD_CLPD1      equ       1                   ;Plus-Side General Calibration Value D bit 1
ADC1CLPD_CLPD2      equ       2                   ;Plus-Side General Calibration Value D bit 2
ADC1CLPD_CLPD3      equ       3                   ;Plus-Side General Calibration Value D bit 3
ADC1CLPD_CLPD4      equ       4                   ;Plus-Side General Calibration Value D bit 4
ADC1CLPD_CLPD5      equ       5                   ;Plus-Side General Calibration Value D bit 5

ADC1CLPS            equ       $190D,1             ;Plus-Side General Calibration Value S Register

ADC1CLPS_CLPS0      equ       0                   ;Plus-Side General Calibration Value S bit 0
ADC1CLPS_CLPS1      equ       1                   ;Plus-Side General Calibration Value S bit 1
ADC1CLPS_CLPS2      equ       2                   ;Plus-Side General Calibration Value S bit 2
ADC1CLPS_CLPS3      equ       3                   ;Plus-Side General Calibration Value S bit 3
ADC1CLPS_CLPS4      equ       4                   ;Plus-Side General Calibration Value S bit 4
ADC1CLPS_CLPS5      equ       5                   ;Plus-Side General Calibration Value S bit 5

ADC1CLP4            equ       $190E,2             ;Plus-Side General Calibration Value 4 Register
ADC1CLP4H           equ       $190E,1             ;Plus-Side General Calibration Value 4 High Register
ADC1CLP4L           equ       $190F,1             ;Plus-Side General Calibration Value 4 Low Register
ADC1CLP3            equ       $1910,2             ;Plus-Side General Calibration Value 3 Register
ADC1CLP3H           equ       $1910,1             ;Plus-Side General Calibration Value 3 High Register
ADC1CLP3L           equ       $1911,1             ;Plus-Side General Calibration Value 3 Low Register
ADC1CLP2            equ       $1912,1             ;Plus-Side General Calibration Value 2 Register
ADC1CLP1            equ       $1913,1             ;Plus-Side General Calibration Value 1 Register
ADC1CLP0            equ       $1914,1             ;Plus-Side General Calibration Value 0 Register
ADC1CLMD            equ       $1916,1             ;Minus-Side General Calibration Value D Register
ADC1CLMS            equ       $1917,1             ;Minus-Side General Calibration Value S Register
ADC1CLM4            equ       $1918,2             ;Minus-Side General Calibration Value 4 Register
ADC1CLM4H           equ       $1918,1             ;Minus-Side General Calibration Value 4 High Register
ADC1CLM4L           equ       $1919,1             ;Minus-Side General Calibration Value 4 Low Register
ADC1CLM3            equ       $191A,2             ;Minus-Side General Calibration Value 3 Register
ADC1CLM3H           equ       $191A,1             ;Minus-Side General Calibration Value 3 High Register
ADC1CLM3L           equ       $191B,1             ;Minus-Side General Calibration Value 3 Low Register
ADC1CLM2            equ       $191C,1             ;Minus-Side General Calibration Value 2 Register
ADC1CLM1            equ       $191D,1             ;Minus-Side General Calibration Value 1 Register
ADC1CLM0            equ       $191E,1             ;Minus-Side General Calibration Value 0 Register

;-------------------------------------------------------------------------------

PRACMP0CS           equ       $1924,1             ;PRACMP0 Control and Status Register

PRACMP0CS_ACIEN     equ       0                   ;ACMP Interrupt Enable
PRACMP0CS_ACINTS0   equ       1                   ;ACMP Interrupt Select, bit 0
PRACMP0CS_ACINTS1   equ       2                   ;ACMP Interrupt Select, bit 1
PRACMP0CS_ACMPO     equ       3                   ;ACMP Output Bit
PRACMP0CS_ACOPE     equ       4                   ;ACMP Output Pin Enable
PRACMP0CS_ACMPF     equ       6                   ;ACMP Interrupt Flag
PRACMP0CS_ACEN      equ       7                   ;ACMP Module Enable

PRACMP0C0           equ       $1925,1             ;PRACMP0 Control 0 Register

PRACMP0C0_ACNSEL0   equ       0                   ;ACMP Negative Input Select, bit 0
PRACMP0C0_ACNSEL1   equ       1                   ;ACMP Negative Input Select, bit 1
PRACMP0C0_ACNSEL2   equ       2                   ;ACMP Negative Input Select, bit 2
PRACMP0C0_PRGHWT    equ       3                   ;ACMP Hardware Trigger Select
PRACMP0C0_ACPSEL0   equ       4                   ;ACMP Positive Input Select, bit 0
PRACMP0C0_ACPSEL1   equ       5                   ;ACMP Positive Input Select, bit 1
PRACMP0C0_ACPSEL2   equ       6                   ;ACMP Positive Input Select, bit 2
PRACMP0C0_CMPHWT    equ       7                   ;PRG Hardware Trigger Select

PRACMP0C1           equ       $1926,1             ;PRACMP0 Control 1 Register

PRACMP0C1_PRGOS0    equ       0                   ;Programmable Reference Generator Output Selection, bit 0
PRACMP0C1_PRGOS1    equ       1                   ;Programmable Reference Generator Output Selection, bit 1
PRACMP0C1_PRGOS2    equ       2                   ;Programmable Reference Generator Output Selection, bit 2
PRACMP0C1_PRGOS3    equ       3                   ;Programmable Reference Generator Output Selection, bit 3
PRACMP0C1_PRGOS4    equ       4                   ;Programmable Reference Generator Output Selection, bit 4
PRACMP0C1_PRGINS    equ       6                   ;Programmable Reference Generator Input Selection
PRACMP0C1_PRGEN     equ       7                   ;Programmable Reference Generator Enable

PRACMP0C2           equ       $1927,1             ;PRACMP0 Control 2 Register
PRACMP1CS           equ       $1928,1             ;PRACMP1 Control and Status Register

PRACMP1CS_ACIEN     equ       0                   ;ACMP Interrupt Enable
PRACMP1CS_ACINTS0   equ       1                   ;ACMP Interrupt Select, bit 0
PRACMP1CS_ACINTS1   equ       2                   ;ACMP Interrupt Select, bit 1
PRACMP1CS_ACMPO     equ       3                   ;ACMP Output Bit
PRACMP1CS_ACOPE     equ       4                   ;ACMP Output Pin Enable
PRACMP1CS_ACMPF     equ       6                   ;ACMP Interrupt Flag
PRACMP1CS_ACEN      equ       7                   ;ACMP Module Enable

PRACMP1C0           equ       $1929,1             ;PRACMP1 Control 0 Register

PRACMP1C0_ACNSEL0   equ       0                   ;ACMP Negative Input Select, bit 0
PRACMP1C0_ACNSEL1   equ       1                   ;ACMP Negative Input Select, bit 1
PRACMP1C0_ACNSEL2   equ       2                   ;ACMP Negative Input Select, bit 2
PRACMP1C0_PRGHWT    equ       3                   ;ACMP Hardware Trigger Select
PRACMP1C0_ACPSEL0   equ       4                   ;ACMP Positive Input Select, bit 0
PRACMP1C0_ACPSEL1   equ       5                   ;ACMP Positive Input Select, bit 1
PRACMP1C0_ACPSEL2   equ       6                   ;ACMP Positive Input Select, bit 2
PRACMP1C0_CMPHWT    equ       7                   ;PRG Hardware Trigger Select

PRACMP1C1           equ       $192A,1             ;PRACMP1 Control 1 Register

PRACMP1C1_PRGOS0    equ       0                   ;Programmable Reference Generator Output Selection, bit 0
PRACMP1C1_PRGOS1    equ       1                   ;Programmable Reference Generator Output Selection, bit 1
PRACMP1C1_PRGOS2    equ       2                   ;Programmable Reference Generator Output Selection, bit 2
PRACMP1C1_PRGOS3    equ       3                   ;Programmable Reference Generator Output Selection, bit 3
PRACMP1C1_PRGOS4    equ       4                   ;Programmable Reference Generator Output Selection, bit 4
PRACMP1C1_PRGINS    equ       6                   ;Programmable Reference Generator Input Selection
PRACMP1C1_PRGEN     equ       7                   ;Programmable Reference Generator Enable

PRACMP1C2           equ       $192B,1             ;PRACMP1 Control 2 Register
PRACMP2CS           equ       $192C,1             ;PRACMP2 Control and Status Register

PRACMP2CS_ACIEN     equ       0                   ;ACMP Interrupt Enable
PRACMP2CS_ACINTS0   equ       1                   ;ACMP Interrupt Select, bit 0
PRACMP2CS_ACINTS1   equ       2                   ;ACMP Interrupt Select, bit 1
PRACMP2CS_ACMPO     equ       3                   ;ACMP Output Bit
PRACMP2CS_ACOPE     equ       4                   ;ACMP Output Pin Enable
PRACMP2CS_ACMPF     equ       6                   ;ACMP Interrupt Flag
PRACMP2CS_ACEN      equ       7                   ;ACMP Module Enable

PRACMP2C0           equ       $192D,1             ;PRACMP2 Control 0 Register

PRACMP2C0_ACNSEL0   equ       0                   ;ACMP Negative Input Select, bit 0
PRACMP2C0_ACNSEL1   equ       1                   ;ACMP Negative Input Select, bit 1
PRACMP2C0_ACNSEL2   equ       2                   ;ACMP Negative Input Select, bit 2
PRACMP2C0_PRGHWT    equ       3                   ;ACMP Hardware Trigger Select
PRACMP2C0_ACPSEL0   equ       4                   ;ACMP Positive Input Select, bit 0
PRACMP2C0_ACPSEL1   equ       5                   ;ACMP Positive Input Select, bit 1
PRACMP2C0_ACPSEL2   equ       6                   ;ACMP Positive Input Select, bit 2
PRACMP2C0_CMPHWT    equ       7                   ;PRG Hardware Trigger Select

PRACMP2C1           equ       $192E,1             ;PRACMP2 Control 1 Register

PRACMP2C1_PRGOS0    equ       0                   ;Programmable Reference Generator Output Selection, bit 0
PRACMP2C1_PRGOS1    equ       1                   ;Programmable Reference Generator Output Selection, bit 1
PRACMP2C1_PRGOS2    equ       2                   ;Programmable Reference Generator Output Selection, bit 2
PRACMP2C1_PRGOS3    equ       3                   ;Programmable Reference Generator Output Selection, bit 3
PRACMP2C1_PRGOS4    equ       4                   ;Programmable Reference Generator Output Selection, bit 4
PRACMP2C1_PRGINS    equ       6                   ;Programmable Reference Generator Input Selection
PRACMP2C1_PRGEN     equ       7                   ;Programmable Reference Generator Enable

PRACMP2C2           equ       $192F,1             ;PRACMP2 Control 2 Register

;-------------------------------------------------------------------------------

VREFTRM             equ       $1930,1             ;VREF Trim Register
VREFSC              equ       $1931,1             ;VREF Control Register

VREFSC_MODE0        equ       0                   ;Mode selection, bit 0
VREFSC_MODE1        equ       1                   ;Mode selection, bit 1
VREFSC_VREFST       equ       2                   ;Internal Voltage Reference Stable
VREFSC_VREFEN       equ       7                   ;Internal Voltage Reference Enable

;-------------------------------------------------------------------------------

PTAPF1              equ       $1940,1             ;Port A Routing Register 1

PTAPF1_A0           equ       0                   ;Port PTA0 Pin Mux Controls
PTAPF1_A1           equ       4                   ;Port PTA1 Pin Mux Controls

PTAPF2              equ       $1941,1             ;Port A Routing Register 2

PTAPF2_A2           equ       0                   ;Port PTA2 Pin Mux Controls
PTAPF2_A3           equ       4                   ;Port PTA3 Pin Mux Controls

PTAPF3              equ       $1942,1             ;Port A Routing Register 3

PTAPF3_A4           equ       0                   ;Port PTA4 Pin Mux Controls
PTAPF3_A5           equ       4                   ;Port PTA5 Pin Mux Controls

PTAPF4              equ       $1943,1             ;Port A Routing Register 4

PTAPF4_A6           equ       0                   ;Port PTA6 Pin Mux Controls

PTBPF1              equ       $1944,1             ;Port B Routing Register 1

PTBPF1_B0           equ       0                   ;Port PTB0 Pin Mux Controls
PTBPF1_B1           equ       4                   ;Port PTB1 Pin Mux Controls

PTBPF2              equ       $1945,1             ;Port B Routing Register 2

PTBPF2_B2           equ       0                   ;Port PTB2 Pin Mux Controls
PTBPF2_B3           equ       4                   ;Port PTB3 Pin Mux Controls

PTBPF3              equ       $1946,1             ;Port B Routing Register 3

PTBPF3_B4           equ       0                   ;Port PTB4 Pin Mux Controls
PTBPF3_B5           equ       4                   ;Port PTB5 Pin Mux Controls

PTBPF4              equ       $1947,1             ;Port B Routing Register 4

PTBPF4_B6           equ       0                   ;Port PTB6 Pin Mux Controls
PTBPF4_B7           equ       4                   ;Port PTB7 Pin Mux Controls

PTCPF1              equ       $1948,1             ;Port C Routing Register 1

PTCPF1_C0           equ       0                   ;Port PTC0 Pin Mux Controls
PTCPF1_C1           equ       4                   ;Port PTC1 Pin Mux Controls

PTCPF2              equ       $1949,1             ;Port C Routing Register 2

PTCPF2_C2           equ       0                   ;Port PTC2 Pin Mux Controls
PTCPF2_C3           equ       4                   ;Port PTC3 Pin Mux Controls

PTCPF3              equ       $194A,1             ;Port C Routing Register 3

PTCPF3_C4           equ       0                   ;Port PTC4 Pin Mux Controls
PTCPF3_C5           equ       4                   ;Port PTC5 Pin Mux Controls

PTCPF4              equ       $194B,1             ;Port C Routing Register 4

PTCPF4_C6           equ       0                   ;Port PTC6 Pin Mux Controls
PTCPF4_C7           equ       4                   ;Port PTC7 Pin Mux Controls

PTDPF1              equ       $194C,1             ;Port D Routing Register 1

PTDPF1_D0           equ       0                   ;Port PTD0 Pin Mux Controls
PTDPF1_D1           equ       4                   ;Port PTD1 Pin Mux Controls

PTDPF2              equ       $194D,1             ;Port D Routing Register 2

PTDPF2_D2           equ       0                   ;Port PTD2 Pin Mux Controls
PTDPF2_D3           equ       4                   ;Port PTD3 Pin Mux Controls

PTDPF3              equ       $194E,1             ;Port D Routing Register 3

PTDPF3_D4           equ       0                   ;Port PTD4 Pin Mux Controls
PTDPF3_D5           equ       4                   ;Port PTD5 Pin Mux Controls

PTDPF4              equ       $194F,1             ;Port D Routing Register 4

PTDPF4_D6           equ       0                   ;Port PTD6 Pin Mux Controls
PTDPF4_D7           equ       4                   ;Port PTD7 Pin Mux Controls

PTEPF1              equ       $1950,1             ;Port E Routing Register 1

PTEPF1_E0           equ       0                   ;Port PTE0 Pin Mux Controls
PTEPF1_E1           equ       4                   ;Port PTE1 Pin Mux Controls

PTEPF2              equ       $1951,1             ;Port E Routing Register 2

PTEPF2_E2           equ       0                   ;Port PTE2 Pin Mux Controls
PTEPF2_E3           equ       4                   ;Port PTE3 Pin Mux Controls

PTEPF3              equ       $1952,1             ;Port E Routing Register 3

PTEPF3_E4           equ       0                   ;Port PTE4 Pin Mux Controls
PTEPF3_E5           equ       4                   ;Port PTE5 Pin Mux Controls

PTEPF4              equ       $1953,1             ;Port E Routing Register 4

PTEPF4_E6           equ       0                   ;Port PTE6 Pin Mux Controls
PTEPF4_E7           equ       4                   ;Port PTE7 Pin Mux Controls

PTFPF1              equ       $1954,1             ;Port F Routing Register 1

PTFPF1_F0           equ       0                   ;Port PTF0 Pin Mux Controls
PTFPF1_F1           equ       4                   ;Port PTF1 Pin Mux Controls

PTFPF2              equ       $1955,1             ;Port F Routing Register 2

PTFPF2_F2           equ       0                   ;Port PTF2 Pin Mux Controls
PTFPF2_F3           equ       4                   ;Port PTF3 Pin Mux Controls

PTFPF3              equ       $1956,1             ;Port F Routing Register 3

PTFPF3_F4           equ       0                   ;Port PTF4 Pin Mux Controls
PTFPF3_F5           equ       4                   ;Port PTF5 Pin Mux Controls

PTFPF4              equ       $1957,1             ;Port F Routing Register 4

PTFPF4_F6           equ       0                   ;Port PTF6 Pin Mux Controls
PTFPF4_F7           equ       4                   ;Port PTF7 Pin Mux Controls

PTGPF1              equ       $1958,1             ;Port G Routing Register 1

PTGPF1_G0           equ       0                   ;Port PTG0 Pin Mux Controls
PTGPF1_G1           equ       4                   ;Port PTG1 Pin Mux Controls

PTGPF2              equ       $1959,1             ;Port G Routing Register 2

PTGPF2_G2           equ       0                   ;Port PTG2 Pin Mux Controls
PTGPF2_G3           equ       4                   ;Port PTG3 Pin Mux Controls

PTGPF3              equ       $195A,1             ;Port G Routing Register 3

PTGPF3_G4           equ       0                   ;Port PTG4 Pin Mux Controls
PTGPF3_G5           equ       4                   ;Port PTG5 Pin Mux Controls

PTGPF4              equ       $195B,1             ;Port G Routing Register 4

PTGPF4_G6           equ       0                   ;Port PTG6 Pin Mux Controls
PTGPF4_G7           equ       4                   ;Port PTG7 Pin Mux Controls

PTHPF1              equ       $195C,1             ;Port H Routing Register 1

PTHPF1_H0           equ       0                   ;Port PTH0 Pin Mux Controls
PTHPF1_H1           equ       4                   ;Port PTH1 Pin Mux Controls

;-------------------------------------------------------------------------------

NVVREFTRM           equ       $FFAD,1             ;Non-volatile VREF Trim Register
NVFTRIM             equ       $FFAE,1             ;Non-volatile ICS Fine Trim

NVFTRIM_FTRIM       equ       0                   ;ICS Fine Trim

NVICSTRM            equ       $FFAF,1             ;Non-volatile ICS Trim Register
NVBACKKEY           equ       $FFB0,8             ;Backdoor Comparison Key 0
NVPROT              equ       $FFBD,1             ;Non-volatile Flash Protection Register

                    @bitnum   NVPROT_FPDIS,0      ;Flash Protection Disable

NVOPT               equ       $FFBF,1             ;Non-volatile Flash Options Register

NVOPT_SEC0          equ       0                   ;Flash Security Bit 0
NVOPT_SEC1          equ       1                   ;Flash Security Bit 1
NVOPT_FNORED        equ       6                   ;Vector Redirection Disable
NVOPT_KEYEN         equ       7                   ;Backdoor Key Security Enable

;-------------------------------------------------------------------------------
; Flash commands
;-------------------------------------------------------------------------------

mBlank              equ       $05
mBurstProg          equ       $25
mByteProg           equ       $20
mMassErase          equ       $41
mPageErase          equ       $40

; **** END OF ORIGINAL DEFINITIONS *********************************************

_9S08GW64_          def       *                   ;Tells us this INCLUDE has been used

TEMPERATURE_CHANNEL equ       22                  ;Channel for internal temperature
BANDGAP_CHANNEL     equ       23                  ;Channel for internal bandgap
BANDGAP_VOLTAGE     def       1210                ;typical bandgap voltage in mV

FLASH_PAGE_SIZE     equ       512                 ;minimum that must be erased at once

          #if FLASH_PAGE_SIZE <> 512
                    #Error    FLASH_PAGE_SIZE should be fixed at 512
          #endif

FLASH_DATA_SIZE     def       0                   ;default: no runtime flash storage

VECTORS             equ       $FF96               ;start of fixed vectors

          #ifdef RVECTORS
VECTORS             set       RVECTORS
          #endif

;--- Vectors
                    #temp     VECTORS
Vpdb                next      :temp,2             ;$FF96 PDB
Vpdberr             next      :temp,2             ;$FF98 PDB sequence error
Vlcd                next      :temp,2             ;$FF9A LCD
Virtc               next      :temp,2             ;$FF9C IRTC
Vkbi                next      :temp,2             ;$FF9E KBI
                    next      :temp,2*16
Vpcnt               next      :temp,2             ;$FFC0 PCNT
Vpracmp2            next      :temp,2             ;$FFC2 Analog Comparator
Vpracmp1            next      :temp,2             ;$FFC4 Analog Comparator
Vpracmp0            next      :temp,2             ;$FFC6 Analog Comparator
Vadc1               next      :temp,2             ;$FFC8 A/D vector
Vadc0               next      :temp,2             ;$FFCA A/D vector
Vmtim2              next      :temp,2             ;$FFCC Modulo Timer
Vmtim1              next      :temp,2             ;$FFCE Modulo Timer
Vmtim0              next      :temp,2             ;$FFD0 Modulo Timer
Vftmovf             next      :temp,2             ;$FFD2 FTM overflow
Vftmch0             next      :temp,2             ;$FFD4 FTM Channel 0
Vftmch1             next      :temp,2             ;$FFD6 FTM Channel 1
Viic                next      :temp,2             ;$FFD8 IIC
Vspi2               next      :temp,2             ;$FFDA SPI
Vspi1               next      :temp,2             ;$FFDC SPI
Vspi0               next      :temp,2             ;$FFDE SPI
Vsci3tx             next      :temp,2             ;$FFE0 SCI3 transmit
Vsci3rx             next      :temp,2             ;$FFE2 SCI3 receive
Vsci3err            next      :temp,2             ;$FFE4 SCI3 error
Vsci2tx             next      :temp,2             ;$FFE6 SCI2 transmit
Vsci2rx             next      :temp,2             ;$FFE8 SCI2 receive
Vsci2err            next      :temp,2             ;$FFEA SCI2 error
Vsci1tx             next      :temp,2             ;$FFEC SCI1 transmit
Vsci1rx             next      :temp,2             ;$FFEE SCI1 receive
Vsci1err            next      :temp,2             ;$FFF0 SCI1 error
Vsci0tx             next      :temp,2             ;$FFF2 SCI transmit
Vsci0rx             next      :temp,2             ;$FFF4 SCI receive
Vsci0err            next      :temp,2             ;$FFF6 SCI error
Vlvd                next      :temp,2             ;$FFF8 Low voltage detect
Virq                next      :temp,2             ;$FFFA IRQ
Vswi                next      :temp,2             ;$FFFC SWI vector
Vreset              next      :temp,2             ;$FFFE Reset vector

FLASH_DATA_SIZE     align     FLASH_PAGE_SIZE     ;round to next higher block
          #ifmmu
TRUE_ROM            equ       $C000               ;start(!) of 16K non-paged flash (do NOT use $2080-$3FFF, $4000-$7FFF which are also PPAGE 0 and 1)
          #else
TRUE_ROM            equ       $1960               ;start(!) of ~58K non-paged flash
          #endif
          #ifmmu
EEPROM              equ       $10C0
          #endif
EEPROM              def       TRUE_ROM
EEPROM              align     FLASH_PAGE_SIZE
EEPROM_END          equ       EEPROM+FLASH_DATA_SIZE-1

#ifdef BOOTROM
 #if EEPROM_END >= BOOTROM
                    #Error    FLASH_DATA_SIZE is too large
 #endif
#endif

ROM                 def       TRUE_ROM
ROM_END             equ       $FF95               ;end of all flash (before NV registers and fixed vectors)
          #ifmmu
XROM                def       $1960
XROM_END            def       :PAGE_START-1       ;end of pre-window flash
          #endif
XROM                def       EEPROM_END+1
XROM_END            def       $17FF

#ifdef BOOT&BOOTROM
ROM_END             set       BOOTROM-1
#endif

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

RAM                 equ       $C0                 ;start of RAM
RAM_END             equ       $FF                 ;last zero-page RAM location

XRAM                equ       $0100
XRAM_END            equ       $107F               ;last RAM location

#ifdef BOOTRAM_END
RAM                 set       BOOTRAM_END         ;start of 1024 byte RAM
#endif

FLASH_START         equ       EEPROM_END+1
FLASH_END           equ       ROM_END

          #ifdef BOOT&BOOTROM
FLASH_END           set       BOOTROM-1
          #endif

SERIAL_NUMBER       equ       $FFA0               ;start of optional S/N (FFA0-FFAD)

#ifndef MHZ||KHZ
HZ                  def       16777216            ;Cyclone default 32768*512
#endif
;----------------------+------------+-------------------------------------------
; Reference range      | FLL factor | DCO range
;----------------------+------------+-------------------------------------------
; 31.25 - 39.0625 kHz  |     512    | 16 - 20 MHz

FLL_FACTOR          equ       512                 ;fixed at 512

MIN_FLASH_KHZ       def       800
MAX_FLASH_KHZ       def       1000
;-------------------------------------------------------------------------------
          #ifmmu
?                   macro
                    #SEG{:loop-1} :PAGE_START
                    mtop      8
                    endm

                    @?

          #ifdef PEMICRO
PPAGE0              equ       $00<16+:PAGE_START  ;(compatible with P&E Micro programmers)
          #else
PPAGE0              equ       $80<16+:PAGE_START  ;$80 instead of $00 on purpose (equivalent but unambiguous)
          #endif
PPAGE1              equ       $01<16+:PAGE_START
PPAGE2              equ       $02<16+:PAGE_START
PPAGE3              equ       $03<16+:PAGE_START

PPAGE_SIZE          equ       :PAGE_END-:PAGE_START+1

?                   macro     Page
                    mswap     1,:loop
                    #SEG~1~   PPAGE~1~
                    #MEMORY   PPAGE~1~  PPAGE~1~+PPAGE_SIZE-1
                    mtop      :n
                    endm

                    @?        0,1,2               ;define memory for PPAGEs
          #endif
;-------------------------------------------------------------------------------
                    #Uses     common.inc
;-------------------------------------------------------------------------------
;*******************************************************************************
; Aliases for compatibility convenience with existing library code
;*******************************************************************************

Vscitx              equ       Vsci0tx,2
Vscirx              equ       Vsci0rx,2
Vscierr             equ       Vsci0err,2

;*******************************************************************************

HighRegs            equ       $1800               ;start of high page registers
HighRegs_End        equ       $195F,1             ;end of high page registers

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
                    #MEMORY   EEPROM    EEPROM_END
                    #MEMORY   NVBACKKEY NVBACKKEY+7
                    #MEMORY   NVPROT
                    #MEMORY   NVOPT
                    #MEMORY   VECTORS   VECTORS|$FF
                    #!MEMORY  CRC_LOCATION CRC_LOCATION+1

;*******************************************************************************
                    #Uses     newcop.inc
;*******************************************************************************
