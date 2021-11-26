;*******************************************************************************
; T_ISR - Timer Interrupt Service Routine.
;    Crystal 9,8304 MHz /4 = Busfreq => 2.457.600
;   1/x->406,901 nsec
;  1 second 2.457.600 cycles
;  10msec  = 24576 cycles or 96 x 256

T_ISR               proc
                    pshh
                    lda       TSC0
                    and       #$7f
                    sta       TSC0                ; Clear O.C. Flag
          ;-------------------------------------- ; 256 Clockcycles = 104 lsec
                    ldhx      TCH0H
                    aix       #64
                    sthx      TCH0H
          ;--------------------------------------
                    ldhx      funcEmulSci
                    lda       PORTB
                    eor       #BIT0
                    and       #BIT0
                    jsr       ,x

                    lda       timecount
                    inca
                    cmpa      #48
                    blo       Save@@
                    mov       #$FF,timebase       ; loop time 5 msec
                    clra
Save@@              sta       timecount
                    pulh
                    rti

;*******************************************************************************
; Turns on timer 1 channel 0

Init_Timer          proc
                    mov   #$32,TSC      ; Timer A - Cleared + Stopped.
                                        ; prescaler  :4
                    clr   TCH0H
                    clr   TCH0L

                    mov   #$54,TSC0     ; Timer A Channel 0 (PTD4) Toggle on output compare
                    mov   #$02,TSC      ; Start the timer -> prescaler: 4
                    rts
