;*******************************************************************************
;                                        Copyright (c) Motorola 1993
;
;                      LISTING 2
;                      *********
;
; File name:  TIME_BASED.ASM
;
; Purpose: To co-ordinate the timing of exection of different
;          modules using the internal Free-Running Counter along
;          with the Output Compare or the Core Timer along with the
;          Core Timer Overflow funtion.
;          If the free-running counter is used to co-ordinate the
;          timing the tasks, which ever one it is, will be executed
;          every 4ms.
;          If the Core Timer is used, the tasks will be executed
;          every 5.12ms.
;
; Target device: 68HC705L4
;
; Memory usage: ROM: 236 BYTES     RAM:  8 BYTES
;
; Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;
; Description: Using the different timing registers inside the MCU
;              and setting up separate counters, the time intervals
;              between the execution of the different tasks can be
;              controlled using the Free-Running Counter along with
;              the Output Compare function or the Core Timer Counter
;              Register along with the Core Timer Overflow Flag.
;              If the programmable timer is used, an interrupt will
;              occur when the value in the Ouput Compare Register
;              equals the value of the Free-Running Counter.
;              If the Core Timer is used, an interrupt will occur
;              when the Core Timer Counter register rolls over from
;              $FF to $00.
;              In this program it is at every 10 interrupts that a
;              task is executed.
;
;
; SUBROUTINES
; -----------
;
; Author: Joanne Santangeli Location:EKB        Created : 17 Jun 93
;                                         Last modified : 26 Aug 93
;
; Update history
; Rev   Author  Date    Description of change
; ---   ------  ----    ----------------------
; 0.1   JS      26/9/93 INITIAL RELEASE
;
;*******************************************************************************
; Motorola reseves the right to make changes without further notice
; to any product herein to improve reliability, function, or design.
; Motorola does not assume any liability  arising out of the
; application or use of any product , circuit, or software described
; herein; neither does it convey any license under its patent rights
; nor the right of others. Motorola products are not designed,
; intended or authorised for use as components in systems intended
; for surgical implant into the body, or other applications intended
; to support life, or for any other application in which failure
; of the Motorola product could create a situation where personal
; injury or death may occur. Should Buyer purchase or use Motorola
; products for any such intended or unauthorised application, Buyer
; shall indemnify and hold Motorola and its officers, employees
; subsidiaries, affiliates, and distributors harmless against all
; claims, costs, damages, expenses and reasonable attorney fees
; arising out of, directly or indirectly, any claim of personal
; injury or death associated with such unint  ended or unauthorised
; use, even if such claim alleges that Motorola was negligent
; regarding the design or manufacture of the part. Motorola and the
; Motorola logo* are registered trademarks of Motorola Ltd.
;*******************************************************************************

;*********************
; PORT  DECLARATIONS *
;*********************

PORTB               equ       $01                 ; Direct address - Port B
DDRB                equ       $05                 ; Data direction register - Port B

;**********
; MEMORY *
;**********

ROM                 equ       $2100               ; User ROM area in the MC68HC05L4
RAM                 equ       $0050               ; RAM area in the MC68HC05L4
VECTORS             equ       $3FF6               ; Start of vector address

;***************************
; CORE TIMER DECLARARTIONS *
;***************************

TS_CTCSR            equ       $08                 ; Core Timer Control & Status Register
                                                  ; CTOF,RTIF,CTOFE,RTIE,-,-,RT1,RT0
TV_CTCR             equ       $09                 ; Core Timer Counter Register

;**********************************
; PROGRAMMABLE TIMER DECLARATIONS *
;**********************************

TV_TCHA             equ       $10                 ; Timer A Counter Register (High)
TV_TCLA             equ       $11                 ; Timer A Counter Register (Low)
TV_ACHA             equ       $12                 ; Timer A Alt Counter Register (high)
TV_ACLA             equ       $13                 ; Timer A Alt Counter Register (low)
TV_TCRA             equ       $0A                 ; Timer A Control Register
TV_TSRA             equ       $0B                 ; Timer A Status Register
TV_ICHA             equ       $0C                 ; Input Capture A Register (High)
TV_ICLA             equ       $0D                 ; Input Capture A Register (Low)
TV_OCHA             equ       $0E                 ; Output Compare A Register (High)
TV_OCLA             equ       $0F                 ; Output Compare A Register (Low)

;******************************************************
; THE FOLLOWING ARE USED TO DETERMINE THE TASK TIMING *
;******************************************************

TW_OCPER            equ       $C8                 ; Output Compare Period set to 200
TW_TSPER            equ       $0A                 ; Time Slice Period set to 10

;*******************************************************************************
                    #RAM      RAM                 ; VARIABLE DECLARATIONS
;*******************************************************************************

TV_TSCP             rmb       1                   ; Programmable Timer Slice Counter
TV_TSCC             rmb       1                   ; Core Timer Time Slice Counter
TV_TSKCP            rmb       1                   ; Programmable Timer Task Counter
TV_TSKCC            rmb       1                   ; Core Timer Task Counter
TV_TSKC             rmb       1                   ; Task Counter used to find task
TV_OPT              rmb       1                   ; Option whether Core or Programmable
                                                  ; Timer is used
TV_DTASK            rmb       1                   ; To check if a task is to be carried
                                                  ; out at that interrupt
TV_STORE            rmb       1                   ; Bit 1 of this variable is clear or
                                                  ; set depending on if a timer
                                                  ; interrupt has occurred or not when
                                                  ; using the Programmable Timer
;*******************************************************************************
; Pins
;*******************************************************************************

PGM_TIMER           pin       TV_OPT
TASK                pin       TV_DTASK

TASK_A              pin       TV_TSKC
TASK_B              pin
TASK_C              pin
TASK_D              pin
TASK_E              pin
TASK_F              pin
TASK_G              pin
TASK_H              pin

OC_FLG              pin       TV_TSRA,6

;*******************************************************************************
                    #ROM      ROM                 ; Absolute address for this section (MC68HC705L4)
;*******************************************************************************

;****************
;  MAIN PROGRAM *
;****************

T_SCHD05            proc
                    bset      PGM_TIMER           ; Set a flag to determine which timer
                    mov       #$FF,DDRB           ; Set PB7-PB0 as outputs
                    clr       PORTB
                    clr       TV_TSKCC            ; Clear Core Timer Task Counter
                    clr       TV_TSKCP            ; Clear Programmable Timer Task Counter
                    brset     PGM_TIMER,Done@@    ; Branch to choose the
                    bra       T_CORE05            ; Core Timer or the

Done@@             ;jmp       T_PROG05            ; Programmable Timer

;***************
; SUBROUTINES *
;***************

;*******************************************************************************
; Name: T_PROG05
;
; Subroutine: Performs co-ordination of task execution using the
;             Output Compare function of the Programmable Timer.
;
; Stack space used(bytes): 2
;
; Subroutines used: T_PRIN05,Dispatcher
;
; External variables used: TW_OCPER,TW_TSPER,TV_TSKCP,TV_OPT
;
; Description: This subroutine initially sets the first Output
;              Compare. It then waits for a timer interrupt to which
;              it sevices with an interrupt sevice routine. The
;              Output Compare is then updated and the Ouput Compare
;              flag is cleared. The routine then jumps to a
;              subroutine to find the particular task and
;              carries it out.
;*******************************************************************************

T_PROG05            proc
                    lda       TV_TSRA             ; Clear Timer Status Register
                    lda       TV_OCLA             ; Compare flag cleared
                    lda       TV_TCLA             ; Timer overflow cleared
                    lda       TV_ICLA             ; Input capture flag cleared
                    clr       TV_OCHA             ; Clear Output Compare (High)
                    clr       TV_OCLA             ; Clear Output Compare (Low)
                    clr       TV_TSCP             ; Clear Time Slice Counter
                    mov       #$40,TV_TCRA        ; Set Output Compare Interrupt enable
Loop@@              cli                           ; Clear Interrupt Mask Bit
_@@                 brset     TASK,Cont@@         ; If bit is set,go to task routine
                    bra       _@@                 ; If not set,wait for next interrupt

Cont@@              bsr       Dispatcher          ; Jump to task routine
                    bclr      TASK                ; Clear task bit
                    bra       Loop@@              ; Go wait for next interrupt

;*******************************************************************************
; Name:T_CORE05
;
; Subroutine: Performs co-ordination of task execution using the
;             Core Timer Counter Register along with the Core Timer
;             overflow flag.
;
; Stack space used(bytes): 4
;
; Subroutines used: T_CRIN05,Dispatcher
;
; External varaibles used: TW_TSPER,T_TSKCC
;
; Description: This subroutine initially sets the Core Timer Overflow
;              Enable. It then waits for an interrupt (ie. when Core
;              Timer Counter Register rolls over frrom $FF to $00 )
;              After returning from servicing the interrupt, it
;              checks to see if the Task Counter has been written to
;              If so, another subroutine is called to find which task
;              is to be executed and then this particular task is
;              carried out. The routine then waits for the next
;              interrupt.
;*******************************************************************************

T_CORE05            proc
                    clr       TV_TSCC             ; Clear Core Time Slice Counter
                    clr       TS_CTCSR            ; Verify Overflow Flag is clear
                    mov       #$23,TS_CTCSR       ; Set Core Timer Overflow Enable,
                                                  ; RT1 & RT0
_10@@               wait                          ; Wait for Interrupt
                    brset     TASK,_20@@          ; If task bit set,go to task routine
                    bra       _10@@               ; If not,go wait for next interrupt

_20@@               bsr       Dispatcher          ; Jump to task routine
                    bclr      TASK                ; Clear task bit
                    bra       _10@@               ; Go to wait for next interrupt

;*****************************
; INTERRUPT SERVICE ROUTINES *
;*****************************

;*******************************************************************************
; Name: T_PRIN05
;
; Subroutine: Checks if a task is to be carried out at this
;             interrupt and updates the Output Compare register.
;
; Stack space used(bytes): 4
;
; Subroutines used: none
;
; External variables used: TW_TSPER,,TV_TSKCP,TW_OCPER
;
; Description: This interrupt sevice routine finds out if a task
;              by incrementing a Time Slice Counter. Each time the
;              interrupt sevice routine is called the counter is
;              incremented. Only when this counter equals ten, is
;              a task carried out.
;              After deciding whether a task is to be carried out,
;              the Output Compare Register is updated, ready to
;              for another interrupt and the Output Compare Flag
;              is cleared.
;*******************************************************************************

T_PRIN05            proc
                    brclr     OC_FLG,Done@@       ; Checks for Output Compare Flag

                    inc       TV_TSCP             ; Inrement Time Slice Counter
                    lda       TV_TSCP             ; Read the Time Slice Counter
                    cmpa      #TW_TSPER           ; Compare contents of ACCA with 10
                    blo       Go@@                ; If < 10, branch back to T_SCHED10
                    clr       TV_TSCP             ; If = 10, clear Time Slice Counter

                    inc       TV_TSKCP            ; Increment Task Counter
                    bset      TASK                ; Set task bit

Go@@                lda       TV_OCLA             ; Read high byte of Output Compare
                    add       #TW_OCPER           ; Load #200 into ACCA
                    sta       TV_OCLA             ; Store in Output Compare (Low)

                    lda       TV_OCHA             ; Read Output Compare (High)
                    adc       #0                  ; Add the contents of the Carry bit
                    sta       TV_OCHA             ; Store at Output Compare (High)

                    lda       TV_OCLA             ; Read Output Compare (low)
                    sta       TV_OCLA             ; Write back to Output Compare (low)

Done@@              rti                           ; Return from Timer Interrupt

;*******************************************************************************
; Name:T_CRIN05
;
; Subroutine: This routine finds if a tassk is to be carried out at
;             this interrupt. It also clears the Core Timer Overflow
;             flag.
;
; Stack space used (bytes) : 4
;
; Subroutines used: none
;
; External varaibles used: TW_TSPER,TV_TSKCC
;
; Description: Initially finds if Time Slice Counter equals
;              Time Slice Period. If so, the Slice counter is cleared
;              and the Task Counter is incremented. The Core Timer
;              Overflow Flag is then reset.
;*******************************************************************************

T_CRIN05            proc
                    inc       TV_TSCC             ; Increment Core Time Slice Counter
                    lda       TV_TSCC             ; Read Time Slice Counter
                    cmpa      #TW_TSPER           ; Compare this to Time Slice Period
                    blo       Done@@              ; If < 10,go to update status register
                    clr       TV_TSCC             ; If = 10, clear Time Slice Counter
                    inc       TV_TSKCC            ; Increment Core Task Counter
                    bset      TASK                ; Set task bit
Done@@              mov       #$23,TS_CTCSR       ; Clear Overflow Flag
                    rti                           ; Return from Interrupt

;*******************************************************************************
; Name: Dispatcher
;
; Subroutine: Routine to find out which task is to be done  and
;             carries it out accordingly.
;
; Stack space used(bytes): 4
;
; Subroutines used: none
;
; External varaibles used: TV_TSKCC,TV_TSKCP
;
; Description: Depending on which bit contains a zero in the Task
;              Counter determines which task is to be carried out.
;              The task to be executed detected and carried out.
;              Each example task shown here each writes a logic
;              high to a different pin at Port B to demonstrate how
;              the tasks are scheduled.
;*******************************************************************************

;*******************************************************************************
; TASK TABLE
;*******************************************************************************

Dispatcher          proc
                    lda       TV_TSKCC            ; Read Core Timer Task Counter
                    bne       Go@@                ; Check if Core Timer or
                    lda       TV_TSKCP            ; Programmable has been used
Go@@                sta       TV_TSKC             ; Stores task in memory
                    brclr     TASK_A,T_20         ; If bit 0 clear,go to Task A
                    brclr     TASK_B,T_25         ; If bit 1 clear,go to Task B
                    brclr     TASK_C,T_30         ; If bit 2 clear,go to Task C
                    brclr     TASK_D,T_35         ; If bit 3 clear,go to Task D
                    brclr     TASK_E,T_40         ; If bit 4 clear,go to Task E
                    brclr     TASK_F,T_45         ; If bit 5 clear,go to Task F
                    brclr     TASK_G,T_50         ; If bit 6 clear,go to Task G
                    brclr     TASK_H,T_55         ; If bit 7 clear,go to Task H
                    clr       PORTB               ; Clear Port B if Task Counter at #$FF
                    rts                           ; Return from routine

;*******************************************************************************
; TASKS FOLLOW
;*******************************************************************************

T_20                mov       #$01,PORTB          ; Example module
                    rts

;*******************************************************************************

T_25                mov       #$02,PORTB          ; Example module
                    rts

;*******************************************************************************

T_30                mov       #$04,PORTB          ; Example module
                    rts

;*******************************************************************************

T_35                mov       #$08,PORTB          ; Example module
                    rts

;*******************************************************************************

T_40                mov       #$10,PORTB          ; Example module
                    rts

;*******************************************************************************

T_45                mov       #$20,PORTB          ; Example module
                    rts

;*******************************************************************************

T_50                mov       #$40,PORTB          ; Example module
                    rts

;*******************************************************************************

T_55                mov       #$80,PORTB          ; Example module
                    rts

;*******************************************************************************

IRQ
SWI                 rti

;*******************************************************************************
                    #VECTORS  VECTORS
;*******************************************************************************

                    dw        T_PRIN05            ; Programmable Interrupt Vector
                    dw        T_CRIN05            ; Core Timer Interrupt Vector
                    dw        IRQ                 ; Hardware Int
                    dw        SWI                 ; Software Int
                    dw        T_SCHD05            ; RESET Interrupt Vector

                    end       :s19crc
