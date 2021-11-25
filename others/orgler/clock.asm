*** Orgler electronic CLOCK.ASM ****

RAMStart       EQU  $0080
RomStart       EQU  $F000            ;Valid for all JL3, JK3, JK1
VectorStart    EQU  $FFDE

$Include 'jl3regs.inc'             ;For the 68HC908JL3, 68HC908JK3, 68HC908JK1

        org RAMStart
SECOND          ds 1
TIMEBASE        ds 1
TIMECOUNT       ds 1
LOOPCOUNT       ds 1

           org RomStart
**************************************************************
* T_ISR - Timer Interrupt Service Routine.                   *
*    Crystal 9,8304 MHz /4 = Busfreq => 2.457.600            *
*   1/x->406,901 nsec                                        *
*  1 second 2.457.600 cycles                                 *
*  10msec  = 24576 cycles or 96 x 256                        *
**************************************************************
T_ISR:          pshh
                lda    TSC0
                and    #$7f
                sta    TSC0                ; Clear O.C. Flag
*               -------------              ; 256 Clockcycles = 104 lsec
                ldhx    TCH0H
                aix     #64
                sthx    TCH0H
*               ------------
                lda     TIMECOUNT
                inca
                cmp     #48
                blo     TIME_OK
                mov     #$FF,TIMEBASE    ; loop time 5 msec
                clra
TIME_OK         sta     TIMECOUNT
                pulh
                rti

**************************************************************
* Init_Timer - Turns on timer 1 channel 0                    *
**************************************************************
Init_Timer:     mov   #$32,TSC      ; Timer A - Cleared + Stopped.
                                    ; prescaler  :4
                mov   #$0,TCH0H     ;
                mov   #$0,TCH0L     ;

                mov   #$54,TSC0     ; Timer A Channel 0 (PTD4) Toggle on output compare
                mov   #$02,TSC      ; Start the timer -> prescaler: 4
                rts
*********************************************************************
*********************************************************************
MainInit          rsp
                  ldhx     #$80             ; Start for clearing RAM
NextRamClear      clr     0,X
                  incx
                  cmpx    #$FB              ; Clear RAM from $00-$FB
                  bne     NextRamClear
*----------------------------------------------------------------
                  bset   3,DDRD
*--------------------------------------------
                  bsr    Init_Timer
                  cli
**********************************************************************
**********************************************************************
LOOP              sta     COPCTL
                  brclr   7,TIMEBASE,LOOP
                  bclr    7,TIMEBASE
*--------------------------------------
                 lda    LOOPCOUNT
                 inca
                 cmp    #200           ; 200 * 5 = 1 second
                 blo    Save_LoopCount
*                 ---
                 lda    SECOND
                 inca
                 cmp    #60
                 blo    SaveSecond
                 clra
SaveSecond       sta    SECOND
*                ----
                 clra
Save_LoopCount   sta    LOOPCOUNT
                 cmp    #40
                 blo    LED_ON
                 bclr   3,PORTD
                 bra    LED_OK

LED_ON           bset   3,PORTD
LED_OK
*               ----------------------------
                bra     LOOP
**************************************************************

**************************************************************
* Vectors - Timer Interrupt Service Routine.                 *
**************************************************************
              org  VectorStart-1
dummy_isr       rti           ; return

               org  VectorStart

        dw  dummy_isr    ; ADC Conversion Complete Vector
        dw  dummy_isr    ; Keyboard Vector
        dw  dummy_isr    ; (No Vector Assigned $FFE2-$FFE3)
        dw  dummy_isr    ; (No Vector Assigned $FFE4-$FFE5)
        dw  dummy_isr    ; (No Vector Assigned $FFE6-$FFE7)
        dw  dummy_isr    ; (No Vector Assigned $FFE8-$FFE9)
        dw  dummy_isr    ; (No Vector Assigned $FFEA-$FFEB)
        dw  dummy_isr    ; (No Vector Assigned $FFEC-$FFED)
        dw  dummy_isr    ; (No Vector Assigned $FFEE-$FFEF)
        dw  dummy_isr    ; (No Vector Assigned $FFF0-$FFF1)
        dw  dummy_isr    ; TIM1 Overflow Vector
        dw  dummy_isr    ; TIM1 Channel 1 Vector
        dw  T_ISR         ; TIM1 Channel 0 Vector
        dw  dummy_isr    ; (No Vector Assigned $FFF8-$FFF9)
        dw  dummy_isr    ; ~IRQ1
        dw  dummy_isr    ; SWI Vector
        dw  MainInit     ; Reset Vector
