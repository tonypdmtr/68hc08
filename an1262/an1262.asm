;*******************************************************************************
;                                             COPYRIGHT (c) MOTOROLA 1994
;
;                          LISTING 1
;                          *********
;
; FILE NAME: PRIORITY.ASM
;
; PURPOSE: The purpose of this software is to provide a means of executing
;          a number of user defined tasks, where the order of execution of
;          each task is determind by the level of priority that the task is
;          assigned by the user.
;
; TARGET DEVICE: 68HC(7)05
;
; MEMORY USAGE(bytes)  RAM: 22 BYTES     ROM: 640 BYTES
;
; Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;
; DESCRIPTION:  This Priority Scheduler uses 3 task request register
;               (for 3 different priority levels) to organise the user
;               defined tasks into different priorities. Each bit
;               in each of the 3 task request registers corresponds
;               to one task in a Task Table, located at the end of the
;               program. The user is simply required to enter a task into
;               the appropriate position in the task table and set the
;               corresponding bit in the correct task request register.
;               The prefix PS refers to PRIORITY SCHEDULER.
;
; AUTHOR: Joanne Santangeli   LOCATION: EKB    LAST EDIT DATE:  9/DEC/94
;
; UPDATE HISTORY
; REV      AUTHOR      DATE       DESCRIPTION OF CHANGE
; ---      ------    ---------    ---------------------
; 1.O      JS        9/12/94      INITIAL RELEASE
;
;===============================================================================
; Motorola reserves the right to make changes without further notice to any
; product herein to improve reliability, function, or design. Motorola does
; not assume any  liability arising  out  of the  application or use of any
; product,  circuit, or software described herein;  neither  does it convey
; any license under its patent rights  nor the  rights of others.  Motorola
; products are not designed, intended,  or authorized for use as components
; in  systems  intended  for  surgical  implant  into  the  body, or  other
; applications intended to support life, or  for any  other application  in
; which the failure of the Motorola product  could create a situation where
; personal injury or death may occur. Should Buyer purchase or use Motorola
; products for any such intended  or unauthorized  application, Buyer shall
; indemnify and  hold  Motorola  and its officers, employees, subsidiaries,
; affiliates,  and distributors harmless against all claims costs, damages,
; and expenses, and reasonable  attorney  fees arising  out of, directly or
; indirectly,  any claim of personal injury  or death  associated with such
; unintended or unauthorized use, even if such claim alleges that  Motorola
; was negligent regarding the  design  or manufacture of the part. Motorola
; and the Motorola logo* are registered trademarks of Motorola Ltd.
;*******************************************************************************

;********************************
; MEMORY AND PORT DECLARATIONS  *
;********************************

ROM                 equ       $180                ; User ROM are for the 705C9
RAM                 equ       $50                 ; RAM are for 705C9
VECTOR              equ       $3FF4               ; Start of vector addresses
TABLE               equ       $400                ; Start address of task table

PORTA               equ       $00                 ; Port A declaration
DDRA                equ       $04                 ; Port A Data Direction declaration
PORTB               equ       $01                 ; Port B declaration
DDRB                equ       $05                 ; Port B Data Direction Register

BRATE               equ       $0D                 ; Baud rate register
SCCR1               equ       $0E                 ; SCI control register 1
SCCR2               equ       $0F                 ; SCI control register 2
SCDAT               equ       $11                 ; SCI data register
SCSR                equ       $10                 ; SCI status register
          ;-------------------------------------- ; PRIORITY SCHEDULER CONSTANTS
LSB                 equ       0                   ; Bit 0 of task request registers
DO_TASK             equ       1                   ; Flag to say do Priority 1 task
TRY_PR3             equ       2                   ; Flag to say check Priority 3
GO_PR1              equ       3                   ; Flag to say go back to Priority 1
          ;-------------------------------------- ; EXAMPLE TASK CONSTANT
FINAL               equ       4                   ; To indicate last time round Task D

JMP_OPCODE          equ       $CD

;*******************************************************************************
                    #RAM      RAM
;*******************************************************************************
          ;-------------------------------------- ; PRIORITY SCHEDULER VARIABLES
JumpLong            rmb       8                   ; Space to write a procedure in RAM
pr_level            rmb       1                   ; Holds the priority level number
taskreq             rmb       3                   ; Task request register
shadowtask          rmb       3                   ; Copy of the task request register
add_pointer         rmb       1                   ; Points to address in task table
shiftcnt            rmb       3                   ; Number of shifts done on
tasktemp            rmb       1                   ; Copy of shadowtask for BRSET comm
sysflag             rmb       1                   ; Location for system holding flags
settasks            rmb       1                   ; In SCI routine to set tasks to run
          ;-------------------------------------- ; EXAMPLE TASK VARIABLES
delay_var           rmb       1                   ; Variable used in example routine
time_on             rmb       1                   ; Variable used in example routine
num_on_leds         rmb       1                   ; Controls seq of LEDS in example
app_flag_reg        rmb       1                   ; Varaible used in example routine

;*******************************************************************************
                    #ROM      ROM
;*******************************************************************************

;***************
; MAIN PROGRAM *
;***************

SCHED05             proc
                    bsr       INITIAL             ; Initialise Port A & RAM
                    cli                           ; Clear Interrupt Mask
                    bra       PSCHED              ; Priority scheduler

;*************
; PROCEDURES *
;*************

;*******************************************************************************
; NAME: INITIAL
;
; PURPOSE:      To initialise ports and clear all RAM locations used in the
;               program.
;
; SUBROUTINES USED:     CLEAR
;
; DESCRIPTION: Procedure sets all Port A pins as outputs
;*******************************************************************************

INITIAL             proc
                    clr       PORTA               ; Clear Port A
                    mov       #$FF,DDRA           ; Set all pins as outputs
;                   bra       CLEAR               ; Go to clear RAM locations

;*******************************************************************************

CLEAR               proc
                    clrx
Loop@@              clr       RAM,x               ; Clear RAM location
                    incx                          ; Go to next location
                    cpx       #$20                ; Cleared all the locations ?
                    blo       Loop@@              ; If not go clear next location
                    rts                           ; Otherwise, exit

;*******************************************************************************
; NAME: PSCHED
;
; PURPOSE:      This procedure is the control routine for the priority
;               scheduler. It controls which priority level task request
;               register is inspected at what time.
;
; ENTRY CONDITIONS:     The prioritys' task request registers will have
;                       been filled with flags corresponding to tasks in
;                       the task table that the user wishes to execute, or
;                       indeed if a task has set another task to execute, a
;                       flag will be set in the task request register.
;                       All the RAM locations and port A will have been
;                       initialised.
;
; EXIT CONDITIONS:      This procedure is never exited.
;
; SUBROUTINES USED:     PRIOR_1, PRIOR_2, PRIOR_3OR3, PRIOR_3, WRITERAM,
;                       COPY, CHECKBIT0, SHIFTREG, INCSHIFT, CLRSHIFT,
;                       INC_LEVEL, UPDATE.
;
; EXTERNAL VARIABLES USED:      JumpLong, pr_level, taskreq, shadowtask,
;                               add_pointer, shiftcnt, tasktemp, sysflag,
;                               num_on_leds, time_on, NUM_FLASH, delay_var.
;
; DESCRIPTION:  1. When a priority level is to be operated on, a copy will
;                  be made of the corresponding task request register. The
;                  original will then be cleared so that it can be updated
;                  when new tasks require execution.
;
;               2. Priority 1 will be checked first, starting form bit 0
;
;               3. After all these tasks have been checked and executed,
;                  one Priority 2 task will be executed.
;
;               4. If there are no Priority2 tasks at this time, a Priority
;                  3 task will be executed.
;
;               5. Every time a task has been executed, the bit in the
;                  copied task request register, which corresponds to the
;                  task, shall be cleared.
;
;               6. When any one of the copied task request registers is
;                  declared totally empty, it shall be updated again by
;                  copying the original corresponding task request register
;                  In this way, any new tasks that require execution may be
;                  given a time slot in which to execute.
;
;               7. After either  a Priority 2 task or Priority 3 task has
;                  been executed, the scheduler will then go back and check
;                  the updated Priority 1 task request register. If there
;                  are any Priority 1 tasks to be executed, they will all
;                  be executed before any further Priority 2 or Priority 3
;                  tasks.
;
;               8. The whole process will then be repeated             .
;*******************************************************************************

PSCHED              proc
                    bsr       PRIOR_1             ; Examine & Execute Priority 1 tasks
                    bsr       PRIOR_2             ; Examine Priority 2 task reqest reg
Loop@@              bsr       PRIOR_2OR3          ; Executes one Priority 2 or 3 task
                    brset     TRY_PR3,sysflag,_@@ ;Go to examine Priority 3
                    bra       PSCHED              ; Go back to Priority 1
_@@                 bsr       PRIOR_3             ; Examine Priority 3
                    bra       Loop@@              ; Go & execute a Priority 2 or 3 task

;*******************************************************************************
; NAME: PRIOR_1
;
; PURPOSE:      To examine the Priority 1 task request register and execute
;               all the Priority 1 tasks set to execute at that time.
;
; EXIT CONDITIONS:      All Priority 1 task set to execute at that time
;                       have been completed.
;*******************************************************************************

PRIOR_1             proc
                    clrx
                    stx       pr_level            ; Set priority level to 1
                    jsr       COPY                ; Copy task req reg to a temp loc
                    lda       shadowtask,x        ; Read this temporary location
                    beq       Done@@              ; If its empty, go try Priority 2
Loop@@              jsr       CHECKBIT0           ; Otherwise,go check bit 0
                    brset     DO_TASK,sysflag,_@@ ;If bit 0 set,go do a task
                    bra       _1@@                ; Otherwise shift right
_@@                 bsr       WRITERAM            ; Go write subroutine in RAM
                    jsr       JumpLong            ; Go execute the correct task
                    inc       add_pointer         ; Update address pointer
                    bclr      DO_TASK,sysflag     ; Clear flag to say done the task
_1@@                jsr       SHIFTREG            ; Shift tempoary register to right
                    lda       shadowtask,x        ; Read the temporary register
                    beq       Done@@              ; If reg now empty,go to Priority 2
                    jsr       INCSHIFT            ; Otherwise, increment shift counter
                    lda       shiftcnt,x          ; Read value in shift counter
                    cmp       #$07                ; Completed max number of shifts ?
                    bls       Loop@@              ; If not, try next bit in Priority 1
Done@@              rts

;*******************************************************************************
; NAME: PRIOR_2
;
; PURPOSE:   To examine the Priority 2 task request register
;
; ENTRY CONDITIONS:     All priority 1 tasks have been executed.
;
; EXIT CONDITIONS:      A flag is set to say either, go execute one Priority
;                       task, or go examine the Priority 3 task request
;                       register.
;*******************************************************************************

PRIOR_2             proc
                    jsr       CLRSHIFT            ; Clear previous shift counter
                    jsr       INC_LEVEL           ; Increment priority level
                    lda       shiftcnt,x          ; Read present shift counter
                    bne       _@@                 ; If it <> 0,update address pointer
                    bsr       COPY                ; Copy task req reg to a temp loc
_@@                 jsr       UPDATE              ; Update address pointer
                    add       #$10                ; Set address pointer to start of
                    sta       add_pointer         ; correct section in the task table
                    ldx       pr_level
                    lda       shadowtask,x        ; Read the temporary location
                    bne       Done@@              ; If its empty, set flag TRY_PR3
                                                  ; Otherwise, exit
                    bset      TRY_PR3,sysflag     ; Set flag to say try Priority 3
Done@@              rts

;*******************************************************************************
; NAME: PRIOR_2OR3
;
; PURPOSE: To execute either one Priority 2 or Priority 3 task.
;
; ENTRY CONDITIONS:     Flag set to say execute either a Priority 2 or
;                       Priority 3 task.
;
; EXIT CONDITIONS:      Either a Priority  2 task or a Priority 3 task has
;                       been executed.
;*******************************************************************************

PRIOR_2OR3          proc
                    brset     TRY_PR3,sysflag,Done@@ ;If TRY_PR3 set, exit
                    brset     GO_PR1,sysflag,_2@@ ;If GO_PR1 set go PRIOR23
Loop@@              bsr       CHECKBIT0           ; Otherwise try bit 0 in reg
                    brset     DO_TASK,sysflag,_@@ ;If bit 0 set, go do task
                    bsr       SHIFTREG            ; Otherwise, shift reg to the right
                    bsr       INCSHIFT            ; Increment shift counter
                    bra       Loop@@              ; Go check next bit
_@@                 bsr       WRITERAM            ; Go to write procedure in RAM
                    jsr       JumpLong            ; Go to execute the task
                    bclr      DO_TASK,sysflag     ; Clear flag to say done task
                    bsr       SHIFTREG            ; Shift reg to the right
                    lda       shadowtask,x        ; Read the temporary location
                    beq       _1@@                ; If now empty, go to PRIOR23_10
                    bsr       INCSHIFT            ; Otherwise,increment shift counter
                    lda       shiftcnt,x          ; Read value of shift counter
                    cmp       #$07                ; Done max number of shifts ?
                    bls       _2@@                ; If not, go to _2@@
_1@@                bsr       CLRSHIFT            ; Go clear shift counter
_2@@                clra                          ; Set address pointer back to
                    sta       add_pointer         ; start of Priority 1 addresses
                    bclr      GO_PR1,sysflag      ; Clear flag, go back to Priority 1
Done@@              rts

;*******************************************************************************
; NAME: PRIOR_3
;
; PURPOSE:      To examine the Priority 3 task request register
;
; ENTRY CONDITIONS:     All the Priority 1 and Priority 2 tasks set to
;                       execute at that time have been completed.
;
; EXIT CONDITIONS:      A flag is set to say either go execute a Priority 3
;                       or go back to check Priority 1 task request register
;*******************************************************************************

PRIOR_3             proc
                    bsr       INC_LEVEL           ; Increment priority level

                    lda       shiftcnt,x          ; Read shift counter
                    bne       _@@                 ; If empty,go update address pointer
                    bsr       COPY                ; Copy task req reg to a temp loc
_@@                 bsr       UPDATE              ; Update address pointer
                    add       #$20                ; Set pointer to correct section
                    sta       add_pointer         ; in the task table
                    bclr      TRY_PR3,sysflag     ; Clear flag
                    ldx       pr_level            ; Read the temporary task
                    lda       shadowtask,x        ; request register
                    bne       Done@@              ; If empty set flag,go to Priority 1
                                                  ; Otherwise,go try bit 0
                    bset      GO_PR1,sysflag
Done@@              rts

;*******************************************************************************
; NAME: WRITERAM
;
; PURPOSE:      To write a subroutine in RAM so that the scheduler can
;               access a 16-bit address, which is the address of the task in
;               the task table.
;
; ENTRY CONDITIONS:     A flag has been set to say a task is to be executed
;
; EXIT CONDITIONS:      The task corresponding to the bit set in the copy
;                       of the task request register has been executed.
;
; DESCRIPTION:          The opcode for "JSR" is copied to memory. Then the
;                       high byte and low byte are copied to different
;                       memory locations. Then the opcode for "RTS" is
;                       copied to memory. We then carry out the subroutine
;                       at the address in the task table.
;*******************************************************************************

WRITERAM            proc
                    ldx       add_pointer         ; Read the address in task table

                    lda       #JMP_OPCODE         ; Read the opcode for "JSR"
                    sta       JumpLong            ; Copy it to location in memory

                    lda       TaskTable,x         ; Read the high byte of address
                    sta       JumpLong+1          ; Copy this to next loc in JumpLong

                    incx                          ; Increment address
                    stx       add_pointer

                    lda       TaskTable,x         ; Read the low byte of the address
                    sta       JumpLong+2          ; Copy this to next loc in JumpLong

                    lda       :AnRTS              ; Read in the opcode for "RTS"
                    sta       JumpLong+3          ; Copy this at next loc in JumpLong
                    rts

;*******************************************************************************
; NAME: COPY
;
; PURPOSE: Makes a copy of the original task request register.
;*******************************************************************************

COPY                proc
                    ldx       pr_level            ; Read the task request register
                    lda       taskreq,x
                    sta       shadowtask,x        ; Copy it to a temporary location
                    clr       taskreq,x           ; Clear original
                    rts

;*******************************************************************************
; NAME: CHECKBIT0
;
; PURPOSE:      Checks the first bit in the task request register to see if
;               it is set. If so, a flag is set to say a task is to be
;               executed. If not the address pointer in the task table is
;               updated to point to the next task in the task table.
;*******************************************************************************

CHECKBIT0           proc
                    ldx       pr_level            ; Copy temporary location
                    lda       shadowtask,x        ; to another temporary location so
                    sta       tasktemp            ; can do a BRSET command
                    brset     LSB,tasktemp,_@@    ;Bit 0 set,go execute a task
                    inc:2     add_pointer         ; Otherwise update address pointer
                                                  ; to point to next task in task table
                    bra       Done@@
_@@                 bset      DO_TASK,sysflag     ; Set flag to say do a task
Done@@              rts

;*******************************************************************************
; NAME: SHIFTREG
;
; PURPOSE:      This subroutine shifts the copied task request register one
;               place to the right, so that it can search for a bit set in
;               position zero.
;*******************************************************************************

SHIFTREG            proc
                    ldx       pr_level            ; Perform logical shift right on
                    lsr       shadowtask,x        ; temporary location
                    rts

;*******************************************************************************
; NAME: INCSHIFT
;
; PURPOSE:      This routine increments the shift counter of the priority
;               level being operated on. A maximum of 7 shifts is
;               allowed in an 8-bit register, so this controls how many
;               more bits in the register to check for a set bit.
;*******************************************************************************

INCSHIFT            proc
                    ldx       pr_level
                    inc       shiftcnt,x          ; Increment shift counter
                    rts

;*******************************************************************************
; NAME: CLRSHIFT
;
; PURPOSE:      To clear the present priority's shift counter before
;               starting work on another.
;*******************************************************************************

CLRSHIFT            proc
                    ldx       pr_level            ; Clear previous priority shift
                    lda       shiftcnt,x          ; counter
                    clr       shiftcnt,x
                    rts

;*******************************************************************************
; NAME: INC_LEVEL
;
; PURPOSE:      Increments the priority level when finished working on the
;               present one.
;*******************************************************************************

INC_LEVEL           proc
                    inc       pr_level            ; Increment prority level
                    ldx       pr_level
                    rts

;*******************************************************************************
; NAME: UPDATE
;
; PURPOSE:      Sets the address pointer to the start of the section in
;               the task table which holds the addresses for the tasks
;               in that priority.
;*******************************************************************************

UPDATE              proc
                    ldx       pr_level
                    lda       shiftcnt,x          ; Update address pointer to point
                    ldx       #2                  ; to start of correct section
                    mul                           ; in the task table
                    rts

;*******************************************************************************
                    #SEG9     TABLE               ; TASK TABLE
;*******************************************************************************

TaskTable           dw        TASKA
                    dw:2      :AnRTS              ; Unused entries point to dummy tasks
                    dw        TASKD
                    dw:2      :AnRTS
                    dw        TASKG
                    dw:4      :AnRTS
                    dw        TASKL
                    dw:8      :AnRTS
                    dw        TASKU
                    dw:2      :AnRTS
                    dw        TASKX

;*******************************************************************************
                    #ROM                          ; TASKS FOLLOW
;*******************************************************************************

TASKA               proc
                    mov       #$01,PORTB          ; Example module
                    rts                           ; Dummy task

;*******************************************************************************

TASKD               proc
                    lda       #$10                ; Load in decimal 16
                    sta       num_on_leds         ; Store this value in memory

Loop@@              lda       num_on_leds         ; Read this value
                    bne       _1@@                ; If not empty, go to decrement
                    bset      FINAL,app_flag_reg  ; Set flag to exit after o/p a zero
                    bra       _2@@                ; Go to copy vaue back to memory

_1@@                deca                          ; Decrement number shown on LEDs
_2@@                sta       num_on_leds         ; Copy value back to memory
                    and       #$0F
                    nsa                           ; Shift left
                    sta       PORTA               ; Send value to Port A
                    mov       #$25,time_on        ; Store this value in memory

_3@@                bsr       DELAY               ; Go to DELAY subroutine
                    dec       time_on             ; Decrement the value in time_on
                    lda       time_on             ; Read the value
                    bne       _3@@                ; If <> 0, go back to delay again

                    brset     FINAL,app_flag_reg,Done@@ ; If flag set, exit
                    bra       Loop@@              ; Otherwise, go to output next number

Done@@              bclr      FINAL,app_flag_reg  ; Clear flag before leaving routine
                    rts                           ; Exit

;***************************************************************************

DELAY               proc
                    lda       #$FF                ; Simple delay routine
Loop@@              deca                          ; Keep looping round OUTLP until
                    bne       Loop@@              ; accumulator is zero
                    inc       delay_var           ; Increment counter
                    lda       delay_var           ; Read counter value
                    cmp       #$CC                ; Does it equal HEX CC
                    bls       DELAY               ; If not go back and start agin
                    rts                           ; Otherwise, exit

;***************************************************************************

TASKG               proc
                    mov       #$04,PORTB          ; Example module
                    rts

;*******************************************************************************

TASKL               proc
                    mov       #$08,PORTB          ; Example module
                    rts

;*******************************************************************************

TASKU               proc
                    mov       #$10,PORTB          ; Example module
                    rts

;*******************************************************************************

TASKX               proc
                    mov       #$20,PORTB          ; Example module
                    rts

;*******************************************************************************
; SCI INTERRUPT SERVICE ROUTINE
;*******************************************************************************

DATA                proc
                    bsr       GETDATA             ; Checks for received data
                    tax                           ; Store received ASCII data in X

                    and       #$0F                ; Convert LSB of ASCII char to HEX
                    ora       #'0'                ; $3(LSB) = "LSB"
                    cmp       #'9'                ; 3A-3F need to change to 41-46
                    bls       _1@@                ; Branch if 30-39 OK
                    add       #7                  ; Add offset
_1@@                psha                          ; Store LSB of HEX on stack

                    txa                           ; Read the original ASCII data
                    lsra:4                        ; Shift right 4 bits
                    ora       #'0'                ; ASCII for N is $3N
                    cmp       #'9'                ; 3A-3F need to change to 41-46
                    bls       _2@@                ; Branch if 30-39
                    add       #7                  ; Add offset
_2@@                psha                          ; MS nibble of HEX to stack

                    lda       #13                 ; Load HEX value for "<CR>"
                    bsr       SENDATA             ; Carriage Return

                    lda       #'$'                ; Load HEX value "$"
                    bsr       SENDATA             ; Print dollar sign

                    pula                          ; Get high half of HEX value
                    bsr       SENDATA             ; Print

                    pula                          ; Get low half of HEX value
                    bsr       SENDATA             ; Print

                    clrx                          ; These seven lines demonstrate
                    clr       settasks            ; how flags are set in the Priority 1
                    bset      0,settasks          ; (X=0) task request regiser in order
                    bset      1,settasks          ; to set the corresponding tasks to
                    bset      2,settasks          ; run. settasks is used as a temporary
                    lda       settasks            ; register since the operation
                    sta       taskreq,x           ; BSET 0,taskreq,0, for instance,
                    rti                           ; cannot be done.

;*******************************************************************************

GETDATA             proc
                    brclr     5,SCSR,*            ; RDRF = 1 ?
                    lda       SCDAT               ; OK, get data
                    rts

;*******************************************************************************

SENDATA             proc
                    brclr     7,SCSR,*            ; TDRE = 1 ?
                    sta       SCDAT               ; OK, send data
                    rts

;*******************************************************************************

SPI                ;rti
TIRQ               ;rti
IRQ                ;rti
SWI                 rti

;*******************************************************************************
                    #VECTORS  VECTOR
;*******************************************************************************

                    dw        SPI                 ; SPI interrupt vector
                    dw        DATA                ; SCI interrupt vector
                    dw        TIRQ                ; Timer interrupt vector
                    dw        IRQ                 ; External interrrupt vector
                    dw        SWI                 ; Software interrupt vector
                    dw        SCHED05             ; Reset interrupt vector

                    end       :s19crc
