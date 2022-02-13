;*******************************************************************************
;* Program   : TASKER2.ASM
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Demonstrate the simplest (?) preemptive two-task switcher
;*           : Each task runs for 8ms (with 1KHz internal oscillator)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;* History   : 99.08.18 v1.00 Original (68HC11)
;*           : 07.11.10       Ported to 9S08QG8/GB60
;*******************************************************************************

#ifdef ?
  #Hint +---------------------------------------------------
  #Hint | Available conditionals (for use with -Dx option)
  #Hint +---------------------------------------------------
  #Hint | DEBUG: for Simulator runs
  #Hint | SWI..: ExtraTask gives up its remaining timeslice
  #Hint +---------------------------------------------------
  #Fatal Run ASM8 -Dx (where x is any of the above)
#endif

          #ifdef DEBUG
                    #Message  For Simulator use only (do NOT burn device)
          #endif
MHZ                 def       16
                    #ListOff
          #ifdef GB60
                    #Uses     gb60.inc            ;Definitions for GB60
SCIBDH              equ       SCI1BDH
SCIC2               equ       SCI1C2
SCIS1               equ       SCI1S1
SCID                equ       SCI1D
          #else
                    #Uses     qg8.inc             ;Definitions for QG8
          #endif
                    #ListOn

                    @StandardBaudRates

;*******************************************************************************
; Macros
;*******************************************************************************

Yield               macro
          #ifdef SWI
                    swi                           ;give up remaining timeslice
          #endif
                    endm

;*******************************************************************************
                    #RAM
;*******************************************************************************

; Multitasking-related variables and definitions

stack_pointer       rmb       2                   ;SP for 'other' task
                                                  ;Extra stack, adjust size as needed
EXTRASTACK          equ       :pc+50              ;top of extra stack + 1

;*******************************************************************************
                    #ROM
;*******************************************************************************

;*******************************************************************************
; Purpose: Real Time Interrupt requests come here (does automatic task switching)

                    #spauto

RTI_Handler         proc
                    @ora.b    SRTISC,#RTIACK_,SRTISC  ;Reset the RTI int
;                   bra       SWI_Handler

;*******************************************************************************
; Purpose: Make a task switch (can be done 'manually' with a SWI instruction)

                    #spauto

SWI_Handler         proc
                    pshh      h@@

                    @cop                          ;kick the COP
                    ldhx      stack_pointer       ;prepare other stack
                    pshhx
                    @lea      h@@,sp              ;adjust for PSHHX above
                    sthx      stack_pointer       ;save current SP
                    pulhx
                    txs                           ;load current stack

                    pulh
                    rti

;*******************************************************************************

                    #spauto

Start               proc
                    lda       #COP_
                    sta       SOPT                ;no COP for testing
          ;--------------------------------------
          ; Extra task initialization (prepare the initial stack frame)
          ;--------------------------------------
                    @lds      #EXTRASTACK         ;extra stack

                    ldhx      #ExtraTask          ;point to extra task start address
                    pshhx
                    clra
                    psha:4                        ;X, A, CCR, and H start out zeroed (in that order)

                    tsx
                    sthx      stack_pointer
          ;--------------------------------------
          ; Normal initialization for this (main) process
          ;--------------------------------------
                    @rsp                          ;standard stack
          ;--------------------------------------
          ; Initialize the SCI for polled mode operation
          ;--------------------------------------
                    ldhx      #bps_9600           ;speed to use for testing
                    sthx      SCIBDH
                    mov       #TE_|RE_,SCIC2      ;Polled RX and TX mode
          ;--------------------------------------
          ; Real-time clock initialization (~8ms @1KHz internal oscillator)
          ;--------------------------------------
                    lda       #RTIE_|Bit0_
                    sta       SRTISC

                    clra
                    clrhx

                    cli                           ;allow multi-tasking from this point on
;                   bra       Main

;*******************************************************************************
; MAIN TASK
;*******************************************************************************

                    #spauto

Main                proc
Loop@@              lda       #'1'                ;main task sends a stream of 1's
                    bsr       PutChar             ;..to the SCI
                    bra       Loop@@              ;loop forever

;*******************************************************************************
; SECONDARY TASK - This is the extra task
;*******************************************************************************

                    #spauto

ExtraTask           proc
Loop@@              lda       #'2'                ;extra task sends a stream of 2's

                    @Yield                        ;give up remaining timeslice

                    bsr       PutChar             ;..to the SCI
                    bra       Loop@@              ;Cannot use RTS or RTI (independent process)

;*******************************************************************************
; Purpose: Common routine for sending a character in RegA to the SCI
; Input  : A = character to send to the SCI
; Output : None
                    #spauto

PutChar             proc
Loop@@              tst       SCIS1               ;needed for flag clearing sequence
                    bpl       Loop@@
                    sta       SCID
                    rts

;*******************************************************************************
                    @vector   Vrti,RTI_Handler
                    @vector   Vswi,SWI_Handler
                    @vector   Vreset,Start
;*******************************************************************************
                    end       :s19crc
