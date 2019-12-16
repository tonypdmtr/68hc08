;*******************************************************************************
;* Module    : SCI_TX.MOD
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Software SCI TX (transmitter)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : Copyright (c) 2019 by Tony Papadimitriou <tonyp@acm.org>
;* Segments  : To be placed in user defined segment (MMU compatible)
;* Subsystems: None -- Fully software driven (bit-banged)
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     qd4.inc
                    #ListOn
                    #MCF
SCI_TX_PIN          @pin      PORTA,0
#endif ;------------------------------------------------------------------------

                    @CheckPin SCI_TX_PIN

?TX                 @pin      SCI_TX_PIN,SCI_TX_PIN.

;*******************************************************************************
; To determine the value to use for each bps rate, you must divide the
; bus-clock (e.g., 8MHz) by the bps rate (e.g., 9600).  So, 8000000/9600=
; 833.33333 but we round to the closest integer which in this case is 833.
; So, for an 8MHz bus system, to get a bps rate of 9600, we use the value 833
;-------------------------------------------------------------------------------
; Note: This software driven SCI is more capable than a built-in SCI, found in
; most HC08s, in that it can produce pretty much any bps rate (within the speed
; limits of the MCU) using any crystal frequency.  All you have to do is come
; up with the correct values as described above.
;*******************************************************************************

BPS_RATE            def       9600
?bps_value          equ       BUS_HZ/BPS_RATE

;*******************************************************************************
; Purpose: Send char in RegA to the SCI
; Input  : A = character
; Output : None [CCR destroyed]
; Notes  : Interrupts may have to be disabled during transmission

                    #spauto

SCI_PutChar         proc
                    push

                    @Output   ?TX                 ;insure data line is output

                    ldx       #9                  ;number of data bits to send (including start bit)
                    bra       Zero@@              ;send the start bit (a zero)
          ;-------------------------------------- ;send the data bits
Loop@@              @cop                          ;reset COP to be safe
                    lsra                          ;SCI is lsb first
                    bcc       Zero@@

                    bset      ?TX                 ;a 'HIGH' bit
                    bra       Cont@@

Zero@@              bclr      ?TX                 ;a 'LOW' bit
                              #Cycles
Cont@@              bsr       ?DelayBitTime       ;delay one bit time
                              #temp :cycles       ;?BSR_CYCLES
                    dbnzx     Loop@@              ;not done yet, put another bit
          ;--------------------------------------
                    bset      ?TX                 ;send the stop bit (a one)
                    bsr       ?DelayBitTime
                    pull
                    rtc

;*******************************************************************************
; Purpose: Delay a full bit time (based on ?bps_value) including JSR & RTS
; Input  : None
; Output : None
; Note(s):
                    #spauto
                              #Cycles :temp
?DelayBitTime       proc
                    psha
                    lda       #DELAY@@
                              #Cycles
Loop@@              @cop
                    dbnza     Loop@@
                              #temp :cycles
                    pula
                    rts

DELAY@@             equ       ?bps_value-:cycles-:ocycles/:temp

;*******************************************************************************
                    #sp
;*******************************************************************************