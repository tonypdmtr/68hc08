                    #ListOff
                    #Uses     qt4.inc

PTA                 equ       PORTA
PTA0                equ       0
DDRA0               equ       0
RamStart            equ       RAM
FlashStart          equ       ROM
Vkbd                equ       Vkeyboard
Vtimov              equ       Vtimovf
COCO                equ       COCO.
TOF                 equ       TOF.

AWUIE               equ       6
ADIV2               equ       7
ADICLK              equ       $003F
CH0_                equ       1<0
CH1_                equ       1<1
CH2_                equ       1<2
CH3_                equ       1<3
CH4_                equ       1<4
                    #ListOn
;*******************************************************************************
;* Title:  ASB520.ASM               Copyright (c) Motorola 2003
;*******************************************************************************
;* Author: Bill Lucas - Motorola TSPG - 8/16 Bit Division
;*
;* Description: Simple IR remote control transmitter
;*
;* This program demonstrates how a simple infrared remote control
;* can be made using a small microcontroller, in this case a Motorola
;* MC68HC908QT2. In order not to complicate the design, only six
;* functions will be supported by the remote controller. This remote
;* controller is specifically designed to control a single device. It
;* is an APEX model AD-1201 DVD. Other devices may be controlled by
;* changing the IR timing tables and if necessary, changing the
;* carrier frequency of the carrier generator routine.
;* This program is programmed into a MC68HC908QT2 and installed on the
;* ASB520 PC board.
;*
;* Documentation: MC68HC908QY4/D MC68HC908QT/QU Family Data Sheet and
;* HC08 Family Reference Manual (CPU08RM/AD)
;*
;* Include File: MC68HC908QT2.equ
;*
;* Assembler:  P&E Microcomputer Systems - CASMS08Z or Metrowerks
;* CodeWarrier 3.0
;* To assemble this file with the P&E assembler, search for the text
;* "; for P&E". It will be found in two places in this source file.
;* Remeove the ; for P&E text, comment the next line and this source
;* code will assemble with CASM08Z.
;*
;* Revision History:
;* Rev #      Date        Who               Comments
;* -----  -----------  ----------  ---------------------------------------------
;*  0.1      1-Aug-03  Bill Lucas  Preliminary version
;*  0.2     19-Aug-03  Bill Lucas  Tested with P&E assembler
;*  1.0     27-Aug-03  Bill Lucas  Tested with MetroWerks assembler
;*******************************************************************************
;
;
;*******************************************************************************
; Equates follow:
;

initCONFIG2         equ       %00011000           ;initialization for Config2
;                              || ||  |       CONFIG2 is a write-once register
;                              || ||  +-RSTEN   - 0 disable RST pin function
;                              || ++----OSCOPT[1:0]- 1:1 use crystal for oscillator
;                              |+-------IRQEN   - 0 disable ext IRQ pin fcn
;                              +--------IRQPUE  - 0 enable pull-up on IRQ

initCONFIG1         equ       %10010011           ;initialization for Config1
;                              ||||||||       CONFIG1 is a write-once register
;                              |||||||+-COPD    - 1 disable COP watchdog
;                              ||||||+--STOP    - 1 enable STOP instruction
;                              |||||+---SSREC   - 0 4096 cycle STOP recovery
;                              ||||+----LVI5OR3 - 0 set LVI for 3v system
;                              |||+-----LVIPWRD - 1 disable power to LVI system
;                              ||+------LVIRSTD - 0 enable reset on LVI trip
;                              |+-------LVISTOP - 0 disable LVI in STOP mode
;                              +--------COPRS   - 1 short COP timeout

IRPIN               equ       PTA0                ;IR xmit connected to PORTA bit 0
IRPORT              equ       PTA                 ;IR xmit connected to PORTA
TestBit             equ       2                   ;PTA2 sed for production test
PowerValue          equ       160                 ;min. value for the POWER switch
PauseValue          equ       120                 ;min. value for the PAUSE switch
PlayValue           equ       75                  ;min. value for the PLAY switch
ForwardValue        equ       38                  ;min. value for the FORWARD switch
StopValue           equ       14                  ;min. value for the STOP switch

;*******************************************************************************

                    org       RamStart
; Variables follow:

PointerTemp         rmb       2                   ; temp pointer to PatTable for xmit
ServiceTime         rmb       1                   ; counter to time service to keyboard

;*******************************************************************************

                    org       FlashStart
; IR constant tables follow:

; IR pattern table follows for the six supported buttons. It was
; imperially generated from an APEX model AD-1201 remote controller.

; The format of the table is:
; Carrier on time at 27.75us. per count, carrier off time at 1us. per
; count, carrier on time at 27.75us per count, carrier off time at
; 1us. per count, etc until a 0 entry is encountered in the table.

PowerPatTable       equ       *                   ; POWER output pattern table
                    fdb       328,4505,21,539,22,532,21,1672,22,538,21
                    fdb       561,21,561,20,565,21,561,20,1684,21,1676
                    fdb       21,553,21,1691,20,1687,21,1671,21,1675,21
                    fdb       1674,21,1673,21,1685,21,1665,21,545,21,544
                    fdb       21,552,21,1684,20,568,21,562,20,576,20,580
                    fdb       20,1683,21,1685,20,1698,20,564,20,1702,20
                    fdb       0                   ; end of table marker

PlayPatTable        equ       *                   ; PLAY/ENTER output pattern table
                    fdb       328,4542,20,567,20,584,19,1713,20,552,20
                    fdb       569,20,586,20,581,20,585,19,1708,20,1707
                    fdb       20,587,20,1700,20,1715,20,1706,20,1698,20
                    fdb       1708,20,591,20,1710,20,1700,20,1691,20,587
                    fdb       20,585,20,585,19,577,20,1722,19,593,19,584
                    fdb       19,619,19,1709,19,1724,20,1731,19,1718,19
                    fdb       0                   ; end of table marker

FwdPatTable         equ       *                   ; FORWARD output pattern table
                    fdb       327,4553,20,600,19,600,19,1712,20,585,20
                    fdb       590,19,583,19,592,20,605,18,1718,20,1690,21
                    fdb       559,21,1689,21,1697,19,1704,21,1686,21,1698
                    fdb       19,566,21,557,21,1672,21,1689,20,562,21,591
                    fdb       19,1680,21,588,20,1674,21,1680,20,567,21
                    fdb       553,21,1692,21,1699,20,557,21,1686,21
                    fdb       0                   ; end of table marker

RevPatTable         equ       *                   ; REVERSE output pattern table
                    fdb       328,4571,19,569,20,585,19,1721,19,585,19
                    fdb       590,20,594,20,594,19,637,18,1710,20,1715
                    fdb       19,592,19,1711,20,1700,20,1739,19,1688,20
                    fdb       1701,20,1704,20,1686,21,1693,20,1702,20,564
                    fdb       19,584,20,613,18,603,19,584,20,581,19,656,17
                    fdb       607,19,1735,19,1725,19,1749,19,1698,19
                    fdb       0                   ; end of table marker

PausePatTable       equ       *                   ; PAUSE output pattern table
                    fdb       328,4510,21,539,21,580,20,1690,21,568,20
                    fdb       576,20,565,20,594,19,585,20,1710,20,1706,20
                    fdb       575,19,1709,20,1694,20,1700,20,1692,21,1690
                    fdb       20,573,20,611,18,590,20,1685,20,586,20,571
                    fdb       20,585,19,585,20,1723,19,1719,20,1698,20,570
                    fdb       20,1707,20,1720,19,1709,20,1695,20
                    fdb       0                   ; end of table marker

StopPatTable        equ       *                   ; STOP output pattern table
                    fdb       329,4475,22,513,22,521,22,1643,22,513,22
                    fdb       526,22,524,22,529,21,533,21,1660,21,1665
                    fdb       21,537,21,1661,22,1663,21,1665,21,1657,22
                    fdb       1662,21,531,22,536,21,1662,22,1663,21,532
                    fdb       22,538,21,541,21,545,21,1669,21,1668,21,540
                    fdb       21,544,21,1669,21,1669,21,1663,22,1667,21
                    fdb       0                   ; end of table marker

;*********************************************************************
; Code follows:

;*******************************************************************************
; ReadA2D: Converts on channel 1; AD1/PTA1
; Called by jsr  ReadA2D
; Value returned in reg. A
;*******************************************************************************

ReadA2D             proc
                    bset      ADIV2,ADICLK        ; bus clock /16
                    mov       #CH0_,ADSCR         ; dummy convert on channel 1
                    brclr     COCO,ADSCR,*        ; discard first conversion after stop
                    mov       #CH0_,ADSCR         ; convert on channel 1
                    brclr     COCO,ADSCR,*        ; wait for the conversion to complete
                    lda       ADR                 ; get the results
                    mov       #CH4_+CH3_+CH2_+CH1_+CH0_,ADSCR  ; A/D powered off
                    rts

;*******************************************************************************
; DecodeKey: Checks to see if a key is depressed. Services it if one
; is depressed. If no key is depressed, just return.

DecodeKey           proc
                    bsr       ReadA2D             ; read key input port
                    cmp       #$f0                ; If value too high, no key pressed
                    bcc       DecodeExit          ; no key depressed. Just exit
                    cmp       #PowerValue         ; A/D val if POWER switch pressed
                    bcc       PowerSwitch         ; Send POWER command
                    cmp       #PauseValue         ; A/D val if PAUSE switch pressed
                    bcc       PauseSwitch         ; Send PAUSE command
                    cmp       #PlayValue          ; A/D val if PLAY/ENTER sw pressed
                    bcc       PlaySwitch          ; Send PLAY command
                    cmp       #ForwardValue       ; A/D val if FORWARD switch pressed
                    bcc       ForwardSwitch       ; Send FORWARD command
                    cmp       #StopValue          ; A/D val if STOP switch pressed
                    bcc       StopSwitch          ; Send STOP command
                                                  ; else
                    ldhx      #RevPatTable        ; REVERSE data
                    bra       Transmit            ; must be REVERSE switch..send REVERSE cmd

PowerSwitch         ldhx      #PowerPatTable      ; POWER data
                    bra       Transmit            ; send POWER command

PlaySwitch          ldhx      #PlayPatTable       ; PLAY data
                    bra       Transmit            ; send PLAY/ENTER command

ForwardSwitch       ldhx      #FwdPatTable        ; FORWARD data
                    bra       Transmit            ; send FORWARD command

StopSwitch          ldhx      #StopPatTable       ; STOP data
                    bra       Transmit            ; send REVERSE command

PauseSwitch         ldhx      #PausePatTable      ; PAUSE data
                    bra       Transmit            ; send PAUSE command

DecodeExit          rts                           ; no key was depressed; just exit

;*******************************************************************************
; Transmit: Sends the IR pattern, based on the pattern tables, out of
; the IR port.
; Called by         jsr       Transmit
;*******************************************************************************

Transmit            proc
                    sthx      PointerTemp         ; temp pointer into data table
TxLoop              bsr       Get16Bits           ; get the 16 bits mark time
                    cphx      #0                  ; are we at the end of the table?
                    beq       TxDone              ; yes
                    bsr       CarGen              ; output the mark time
                    bsr       Get16Bits           ; get the 16 bits space time
                    cphx      #0                  ; are we at the end of the table?
                    beq       TxDone              ; yes
                    bsr       TimeDelay           ; space time
                    bra       TxLoop              ; continue

TxDone              ldhx      #35000              ; Set up for 35ms delay
                    !jsr      TimeDelay           ; Delay. Repeat time ~162ms to 189ms
                    rts                           ; all done, return

;*******************************************************************************
; Get16Bits: Routine to get the 16-bit pattern times
;*******************************************************************************

Get16Bits           proc
                    ldhx      PointerTemp         ; next data
                    lda       0,x                 ; high byte of data
                    psha                          ; save for transfer to reg. H
                    lda       1,x                 ; low byte of data
                    psha                          ; save for transfer to reg. X
                    aix       #2                  ; set up for the next 2 bytes of data
                    sthx      PointerTemp         ; use the next time around
                    pulx                          ; low byte data in reg. X
                    pulh                          ; high byte in reg. H
                    rts

;*******************************************************************************
; TimeDelay: Routine to generate a time delay in 1us. increments.
; It is used to time Space times for the IR output. The clock
; for this system is 16 MHz resonator / 4 = 4 MHz system bus. The
; timer is initialized for a prescaler, bus clock / 4. Adjustment
; is made for call time, set up overhead and return times. Timer
; channel 0 used.
; Called by using:
;                   ldhx      #time in 1us. increments (never < 10us.)
;                   jsr       TimeDelay
;*******************************************************************************

TimeDelay           proc
                    aix       #-7                 ; compensation for ~call time
                    mov       #TSTOP_|TRST_,TSC   ; stop and reset timer
                    sthx      TMODH               ; put compare value in TIM0 val reg.
                    lda       TSC0                ; clear compare flag is set
                    bclr      TOF,TSC             ; complete the clearing process
                    mov       #PS1_,TSC           ; restart the timer @ prescaler = 4
                    brclr     TOF,TSC,*           ; loop until compare
                    rts

;*******************************************************************************
; CarGen: Routine to generate a carrier of 36.036 kHz for an APEX DVD
; Note: IR LED duty cycle is <50% to conserve power
; Do 111 cycles * 250 ns = 36.036 kHz actual
; Burst minimum time is 27.750 us. with x=1
; Burst maximum time is 1.819 sec. with x = $ffff
; h:x= burst time/27.750e-6
; Call by using:
;                   ldhx      #(burst time*27.75e-6)
;                   jsr       CarGen
;*******************************************************************************

CarGen              proc
                    bset      IRPIN,IRPORT        ; (4) - LED on time
                    lda       #$d                 ; (2) |48
                    dbnza     *                   ; (39 = 3*13) |
                    nop                           ; (1) |
                    nop                           ; (1) |
extra               nop                           ; (1) |
; -
                    bclr      IRPIN,IRPORT        ; (4) - LED off time
                    lda       #$10                ; (2) |63
                    dbnza     *                   ; (48 = 3*16) |
                    aix       #-1                 ; (2) |
                    cphx      #0                  ; (3) |
                    nop                           ; (1) |
                    bne       CarGen              ; (3) -
                    rts                           ; Total =111~ = 36.036 kHz = 27.75us.

;*******************************************************************************
; Called at system reset
; Initialize Configuration registers, external oscillator, ports, wake
; up and variable
; Check for production test mode
; When done, fall into the main loop
;*******************************************************************************

Start               proc
                    bset      TestBit,PTAPUE      ; Port A bit 2 floats on PC board
                    nop                           ; Some time to charge PCB capacitance
                    nop

                    brclr     TestBit,PTA,GoTest  ; Do we need to run production code?

                    mov       #initCONFIG1,CONFIG1  ; Short WU, LVI off, STP en., cop dis.
                    mov       #initCONFIG2,CONFIG2  ; Crystal drives the oscillator
                    mov       2,OSCSTAT           ; Turn on external clock generator
                    mov       #$ff,PTBPUE         ; All PTB pull-ups on. Port not bonded

                    bclr      PTA0,PTA            ; Port A, bit 0 = 0. Itdrives the IR LED
                    bset      DDRA0,DDRA          ; Make Port A, bit 0 an output

                    bset      AWUIE,KBIER         ; Auto wake up enabled

                    clr       ServiceTime         ; Counter to service the keyboard
;                   bra       RCloop

;*******************************************************************************
; The main loop is here
;*******************************************************************************

RCloop              stop                          ; Stop until next wake up interrupt
                    inc       ServiceTime         ; Bump the time to service keyboard
                    lda       ServiceTime         ; Current count
                    and       #3                  ; We only care about the lower 2 bits
                    cmp       #3                  ; Have we reached 3 yet?
                    bne       RCloop              ; No just stop for now
                    jsr       DecodeKey           ; Service the keyboard & send IR data
                    bra       RCloop              ; wait for the next wake up interrupt

GoTest              !jmp      TestCode            ; Do test code, stretch the BRA above

;*******************************************************************************
; Interrupt service routines are here.
; Only one interrupt is used, the wake-up interrupt. It is set for
; interrupt approximately every 16ms to 23ms, based on Vdd and temp.
; The rest of the vectors are vectored to a RTI and ignored
;*******************************************************************************

WakeUPisr           proc
                    bset      2,KBSCR             ; Acknowledge wake up interrupt
BadInterrupt        rti                           ; vector all unused interrupts here

CodeEnd             equ       *
;*******************************************************************************
; Vectors follow:
;*******************************************************************************

                    org       Vadc                ; ADC vector
                    fdb       BadInterrupt

                    org       Vkbd                ; Keyboard vector
                    fdb       WakeUPisr

                    org       Vtimov              ; Timer overflow vector
                    fdb       BadInterrupt

                    org       Vtimch1             ; Timer channel 1 vector
                    fdb       BadInterrupt

                    org       Vtimch0             ; Timer channel 0 vector
                    fdb       BadInterrupt

                    org       Virq                ; IRQ vector
                    fdb       BadInterrupt

                    org       Vswi                ; SWI vector
                    fdb       BadInterrupt

                    org       Vreset              ; Reset vector
                    fdb       Start

;                   #NoList

;*******************************************************************************
; The following code is used for production testing of the PC board.
; It runs if Port A, bit 2 is low at reset. It is not particularly
; efficient, but is a quick way to test the six pushbuttons and red
; LED. It doesn't test the IR LED. This code doesn't run in low power
; mode.

                    org       CodeEnd

TestCode            proc
                    mov       #$8b,CONFIG1        ; Short Wu, 5V LVI STOP enabled, cop disabled
                    bclr      PTA0,PTA            ; Port A, bit 0 drives the IR LED.
                    bset      DDRA0,DDRA          ; Make Port A, bit 0 an output

                    lda       #5                  ; Blink the red led 5x for test mode
TestLoop            psha
                    bsr       BlinkLED
                    pula
                    deca                          ; Done yet?
                    bne       TestLoop            ; no....continue
; Now read the switches and blink the red LED from 1 to 6 times based
; on which switch, SW1-SW6, is depressed.
TestLoop2           jsr       ReadA2D             ; Read key input port
                    cmp       #$f0                ; If value too high, no key pressed
                    bcc       TestLoop2           ; No key depressed. Just loop
                    cmp       #PowerValue         ; A/D val if SW1 switch pressed
                    bcc       SW1PowerSwitch      ; Send 1 blink
                    cmp       #PauseValue         ; A/D val if SW2 switch pressed
                    bcc       SW2PauseSwitch      ; Send 2 blinks
                    cmp       #PlayValue          ; A/D val if SW3 sw pressed
                    bcc       SW3PlaySwitch       ; Send 3 blinks
                    cmp       #ForwardValue       ; A/D val if SW6 switch pressed
                    bcc       SW6ForwardSwitch    ; Send 6 blinks
                    cmp       #StopValue          ; A/D val if SW5 switch pressed
                    bcc       SW5StopSwitch       ; 5 blinks SW5 depressed
          ; else must have been the reverse switch
                    lda       #4                  ; 4 blinks SW4 depressed
                    bra       Blink

;*******************************************************************************

SW1PowerSwitch      proc
                    lda       #1                  ; 1 blink SW1 depressed
                    bra       Blink

;*******************************************************************************

SW2PauseSwitch      proc
                    lda       #2                  ; 2 blinks SW2 depressed
                    bra       Blink

;*******************************************************************************

SW3PlaySwitch       proc
                    lda       #3                  ; 3 blinks SW3 depressed
                    bra       Blink

;*******************************************************************************

SW6ForwardSwitch    proc
                    lda       #6                  ; 6 blinks SW6 depressed
                    bra       Blink

;*******************************************************************************

SW5StopSwitch       proc
                    lda       #5                  ; 5 blinks SW5 depressed
;                   bra       Blink

;*******************************************************************************

Blink               proc
BlnkLoop            psha
                    bsr       BlinkLED
                    pula                          ; Get number of blink times remaining
                    deca                          ; Done yet?
                    bne       BlnkLoop            ; No....continue
                    lda       #10
TDloop              psha
                    ldhx      #$ffff              ; Delay 10 * 65.6ms led off time
                    jsr       TimeDelay
                    pula                          ; Get number of delay times remaining
                    deca                          ; Done yet?
                    bne       TDloop              ; Not yet?
                    bra       TestLoop2           ; Continue test

;*******************************************************************************

BlinkLED            proc
                    ldhx      #$1f90              ; About 200ms on time
                    jsr       CarGen              ; LED on
                    ldhx      #$ffff              ; 2 * 65.636ms LED off time
                    jsr       TimeDelay           ; LED off
                    ldhx      #$ffff              ; 65.636ms delay
                    jsr       TimeDelay           ; LED off
                    rts
