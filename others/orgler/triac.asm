;*******************************************************************************
; The hardware must provide a zerocross circuit,PD5 PIN18
; output drives a photo coupler PD4 PIN 19
;*******************************************************************************

RAMStart       EQU  $0080
RomStart       EQU  $F000       ;Valid for all JL3, JK3, JK1

$Include 'jl3regs.inc'          ; for the 68HC908JK3 JK1 JL3

OFF_VALUE  EQU 23500

                ORG RAMStart
TIMEBASE    ds   1
iCount      ds   1
iDelta      ds   1
ONTIME      ds   2

              org RomStart

**************************************************************
* START - This is the point where code starts executing  *
*             after a RESET.                                 *
**************************************************************
START:  mov #$01,CONFIG1          ;COPD=1 (cop disabled)
        rsp
        mov  #%00000000,PORTD     ; Led to control
        mov  #%01010000,DDRD      ; Led output and PD4 Triac Signal

        mov    #$FF,iCount  ; minus=>decrement plus=increment
        mov    #5,iDelta
        ldhx   #OFF_VALUE
        sthx   ONTIME       ;

;-------------------------
        mov   #$30,TSC     ; Timer A - Cleared + Stopped.
        mov   #$48,TSC1    ; INPUT CAPTURE, Interrupt (INT_ZEROCROSS)
                           ; capture on falling edge
        mov   #$0,TSC      ; Start the timer
        bclr  7,TSC1
        cli                 ; Allow interrupts to happen
;------------------------------------

*************************************************************
LOOP:   brclr  7,TIMEBASE,LOOP
        bclr   7,TIMEBASE

        lda     iCount
        bmi     DECREMENT

        lda     ONTIME+1
        add     iDelta
        sta     ONTIME+1
        lda     ONTIME
        adc     #0
        sta     ONTIME
        ldhx    ONTIME
        cphx    #OFF_VALUE
        blo     INC_OKAY
        mov     #$FF,iCount
INC_OKAY:
        BRA     RAMP_OKAY

DECREMENT:
         lda     ONTIME+1
         sub     iDelta
         sta     ONTIME+1
         lda     ONTIME
         sbc     #0
         sta     ONTIME
         ldhx    ONTIME
         cphx    #1500
         bhi     RAMP_OKAY
         mov     #1,iCount
RAMP_OKAY:
         bra     LOOP
**************************************************************

********* Interrupt-Function *********************************
INT_ZEROCROSS:
        pshh

        mov   #$30,TSC        ; Timer A - Cleared + Stopped.
        mov   #$10,TSC0       ; pin under port control
                              ; initialize timer output level low
*       ------------
        bclr  7,TSC1          ; reset interrupt flag
*       -------------
        ldhx  ONTIME          ; set time to start the ON-IMPULS
        sthx  TCH0H

        mov   #$14,TSC0        ;Timer Ch1 Output compare,toggle, no interrupt
                               ; output on PD4 PIN19
        mov   #0,TSC           ; start the timer now

        lda    PORTD
        eor    #$40
        sta    PORTD           ; Led output to control zerocross

        mov    #$FF,TIMEBASE   ; set for looptime 10 msec

        pulh
        rti
**************************************************************

            ORG $FFF4
        dw  INT_ZEROCROSS  ; TIM1 Channel 1 Vector  PD5 PIN 18

            ORG $FFFE
        dw  START          ; Reset Vector
