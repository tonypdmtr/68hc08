;*******************************************************************************
;* DMA App Note code                                                  CRC: $E4EC
;*******************************************************************************
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* (http://www.aspisys.com/freeware.htm)
;* Optimized heavily by combining a lot of repeating code.
;*******************************************************************************

                    #ListOff
;                   #Uses     common.inc
                    #Uses     h708xl36.frk
                    #ListOn

; Equates

INITMIN             equ       25                  ;Initial min duty cycle of 25%
INITMAX             equ       75                  ;Initial max duty cycle of 75%
INITSTEP            equ       1                   ;Initial duty cycle step size = 1
MAXBUF              equ       164                 ;Code requires this to be < 256

Vreset              equ       $FFFE

          #if MAXBUF >= 256
                    #Error    Code requires MAXBUF ({MAXBUF}) to be < 256
          #endif

;*******************************************************************************
                    #RAM
;*******************************************************************************

rx_byte             rmb       1
min_duty            rmb       1
max_duty            rmb       1
duty_step           rmb       1
buf_size            rmb       1
.mes                rmb       2

; Data Buffers

bufbegin            rmb       MAXBUF
mesbuf              rmb       256

;*******************************************************************************
; Each message segment will have a string of characters to be
; printed followed by an integer variable to be printed at the
; end of that string.
; For instance, the message 'A max duty cycle of 15 is too small.' would
; be formed by first calling this macro to pass the first segment of
; the message.  The string indicated by %1 would consist of
; 'A max duty cycle of ', and the variable would be the one that
; contained the value 15.  Then the FINISHMES macro would be called
; to transfer the end of the message.
;*******************************************************************************

;*******************************************************************************
; Beginning of program execution
;*******************************************************************************

RAM_END             def       $FF
STACKTOP            equ       RAM_END+1

;*******************************************************************************
                    #ROM      *
;*******************************************************************************

                    #spauto

Start               proc
                    mov       #COPD,CONFIG        ;Disable the COP--for EPROM cfg
                    ldhx      #STACKTOP           ;Load a pointer to top of RAM
                    txs                           ;Set stack pointer to top of RAM
                    cli                           ; Allow interrupts
          ;--------------------------------------
          ; Initialize global DMA configuration registers
          ;--------------------------------------
                    mov       #$88,DSC            ;Set DMAP, Disable Looping, Set DMAWE
                    mov       #$80,DC1            ;Set bandwidth of DMA to 67%

                    bsr       Init_RAM_SCI        ;Initialize RAM and SCI using DMA CH2
                    bsr       StartWaveform       ;Start waveform w/ SPI/TIM/DMA
                    jsr       WaitDMA2            ;Wait for Intro message to finish

Loop@@              jsr       SendStatusString    ;Send status message to user
                    ldhx      #strsel             ;Prompt user for which function
                    jsr       XmitStr
                    jsr       WaitDMA2            ;Wait for transfer to finish
                    lda       #3                  ;User can respond with 0 - 3
                    jsr       GetDigit            ;Get a valid value--dec result in Acc
                    bsr       SelectAction        ;Respond to user's selection
                    bra       Loop@@              ;Keep going in the main loop

;*******************************************************************************
; Purpose: Use dma channel 2 to initialize RAM buffer and send
;        : introduction message via the SCI to the user.
; Input  : None
; Output : None
; Note(s): The introduction message started in this routine will be using
;        : the SCI and DMA CH2.  Any routine following this one that uses
;        : DMA CH2 should be sure to wait until this transfer is complete
;        : by executing a 'jsr WaitDMA2'

                    #spauto

Init_RAM_SCI        proc
                    ldhx      #AbsMaxDuty         ;Set src addr to be abs max duty const
                    sthx      D2SH
                    ldhx      #bufbegin           ;Set dest addr to be buffer pointer
                    sthx      D2DH
                    mov       #$2c,D2C            ;Static src, inc dest, word, and
                                                  ; set to SPI even though it is software
                    mov       #MAXBUF,D2BL        ;Fill in entire table with constant
                    bset      TEC2,DC1            ;Enable DMA CH2 w/o interrupts
                    mov       #$10,DC2            ;Initiate DMA transfer
                    nop:2                         ;All DMA word transfers are 100%
                                                  ; bandwidth.  NOPs ensure DMA transfer
                                                  ; had time to start before clear below
                    clr       DC2                 ;DMA transfer should be finished now
                    bclr      IFC2,DSC            ;Clear DMA CH2 interrupt flag
          ;--------------------------------------
          ; Configure the SCI to ready it to transmit
          ; data sent to it from the DMA
          ;--------------------------------------
                    mov       #$03,SCBR           ;Initialize SCI Baud rate to 9600
                    bset      ENSCI,SCC1          ;Enable the SCI to ready it to transfer
                    mov       #$10,SCC3           ;Enable the DMA SCI transmitter interrupt
                    mov       #$88,SCC2           ;Enable the SCI transmitter
          ;-------------------------------------- ;Transfer intro message via the SCI
                    ldhx      #strint             ;HX must have pointer to start of message
                    jsr       XmitStr             ;Transmit introduction to user screen
          ;-------------------------------------- ;Set up RAM buffer with initial waveform to send
                    mov       #INITMIN,min_duty
                    mov       #INITMAX,max_duty
                    mov       #INITSTEP,duty_step
                    jmp       SetupBuf

;*******************************************************************************
; Purpose: Set up SPI and DMA CH0 to create external clock for timer
;        : and DMA CH1 and TIM CH0 to start the PWM waveform.
; Input  : None
; Output : None
                    #spauto

StartWaveform       proc
                    ldhx      #spidata            ;Set up pointer to SPI data to send
                    sthx      D0SH
                    clr       D0DH                ;Destination is SPI data register
                    mov       #SPDR,D0DL
                    mov       #$05,D0C            ;Static src & dest, byte, SPI Trans
                    mov       #$FF,D0BL           ;Since looping on same byte (static src
                                                          ; and dest), byte count is arbitrary
                    bset      L0,DSC              ;Make it loop on this transfer
                    bset      TEC0,DC1            ;Enable DMA CH0 w/o interrupts
                    mov       #$03,SPSCR          ;Set up SPI with div 128 baud rate
                    mov       #$63,SPCR           ;Enable SPI as a mstr with dma xmit int
          ;--------------------------------------
          ; Set up timer CH0 to create the PWM in conjunction with DMA CH1
          ;--------------------------------------
                    mov       #$37,TSC            ;Stop & reset timer; clock externally
                    clr       TMODH               ;Set PWM period by programming
                    mov       #100,TMODL          ; overflow register
                    clr       TCH0H               ;Initialize w/ a min duty cycle by
                    mov       min_duty,TCH0L      ; writing a byte to channel reg 0
                    mov       #$5A,TSC0           ;Configure chan 0 as unbuffered PWM
                    mov       #$01,TDMA           ; and enable it to be service by DMA
          ;-------------------------------------- ;Set up DMA CH1 to receive timer CH0 interrupt
                    ldhx      #bufbegin           ;Load in beginning of buffer
                    sthx      D1SH                ;Store in source address of DMA CH1
                    ldhx      #TCH0L              ;Load in address of TIM CH0
                    sthx      D1DH                ;Store in dest address of DMA CH1
                    mov       #$80,D1C            ;Inc src, static dest, byte xfer, TIM CH0
                    mov       buf_size,D1BL       ;Load bytes in table for initial case
                    bset      L1,DSC              ;Enable looping on this channel
                    bset      TEC1,DC1            ;Enable DMA CH1 w/o interrupts

                    bclr      TSTOP,TSC           ;Start timer waveform
                    rts

;*******************************************************************************
; Purpose: Select correct action based on user's response to main menu
; Input  : Acc has user input value (decimal value from 0 to 3)
; Output : None, but registers altered
; Note(s): This routine does not directly execute an RTS.  Instead it jumps
;        : to a routine that takes the appropriate action, and these routines
;        : are all ended by an RTS.

                    #spauto

SelectAction        proc
                    cbeqa     #0,ResetWaveform    ;Did user enter 0
                                                  ;If 0, reset waveform to default values
                                                  ;If not, see if it was 1
                    cbeqa     #1,PromptMinDuty    ;Did user ask to do selection 1?
                                                  ;If not, look to see if it was 2
                                                  ;If 1, prompt user for minimum value
                    cmpa      #2                  ;Did user ask to do selection 2?
                    jeq       PromptMaxDuty       ;If not, must have asked for selection 3
                                                  ;If 2, prompt user for maximum value
                    jmp       PromptDutyStep      ;Since 3, prompt for duty cycle step size

;*******************************************************************************
; Purpose: Routine used to reset waveform back to it's default values
; Input  : None
; Output : None
                    #spauto

ResetWaveform       proc
                    mov       #INITMIN,min_duty   ;Reset buffer parameters back
                    mov       #INITMAX,max_duty   ; to the default values as
                    mov       #INITSTEP,duty_step ; requested by the user
                    jmp       UpdateTimerBuffer   ;Update timer PWM buffer
                                                  ;All we need to do for selection 0
;*******************************************************************************
; Purpose: Prompt user to enter the minimum duty cycle value
; Input  : None
; Output : None, but register are altered

                    #spauto

PromptMinDuty       proc
                    ldhx      #mesbuf             ;Load address to beginning of message buffer
                    sthx      .mes                ;Reset message pointer to start of buffer

                    ldhx      #strgmn             ;Transfer next string into message buffer
                    jsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       max_duty            ;Transfer a single byte value
                    jsr       HexToASCII          ; into the buffer as an ASCII value
                    jsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strgmf             ;Transfer rest of string into RAM buffer
                    jsr       StrXfr
                    ldhx      #mesbuf             ;Load in pointer to message to send
                    txa                           ;Put lower byte of address into Acc
                    psha      tmp@@               ;Use value to calc # of bytes in message
                    lda       .mes+1              ;Load least significant byte of pointer
                    sub       tmp@@,sp            ;Subtract least significant byte of start
                    ais       #1                  ;Remove value from the stack
                    jsr       WaitDMA2            ;Wait for any previous transfer to finish
                    jsr       XmitStr             ;Tranfer message to the user and
                    jsr       WaitDMA2            ; wait for string to finish transmission
                    jsr       GetPackedBCD        ;Get the packed BCD response from user
                    cmpa      max_duty            ;Is this less than the max duty cycle
                    blt       TooLow@@            ;If so, make sure it isn't too low

                    ldhx      #mesbuf             ;Load address to beginning of message buffer
                    sthx      .mes                ;Reset message pointer to start of buffer

                    ldhx      #stremh             ;Transfer next string into message buffer
                    jsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       max_duty            ;Transfer a single byte value
                    jsr       HexToASCII          ; into the buffer as an ASCII value
                    jsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strfin             ;Transfer rest of string into RAM buffer
                    jsr       StrXfr
                    ldhx      #mesbuf             ;Load in pointer to message to send
                    txa                           ;Put lower byte of address into Acc
                    psha      tmp@@               ;Use value to calc # of bytes in message
                    lda       .mes+1              ;Load least significant byte of pointer
                    sub       tmp@@,sp            ;Subtract least significant byte of start
                    ais       #1                  ;Remove value from the stack
                    jsr       WaitDMA2            ;Wait for any previous transfer to finish
                    jsr       XmitStr             ;Tranfer message to the user and
                    jsr       WaitDMA2            ; wait for string to finish transmission
                    bra       PromptMinDuty       ;Prompt them again for the value

TooLow@@            cmpa      #9                  ;Is the value greater than 9
                    bgt       Save@@              ;If so, value is ok
                    ldhx      #streml             ;Tell user they entered too small a value
                    jsr       XmitStr
                    jsr       WaitDMA2
                    bra       PromptMinDuty       ;Prompt them again for the value

Save@@              sta       min_duty            ;Checks out ok, so save
                    jmp       UpdateTimerBuffer   ;Update the timer buffer with this value
                                                  ;All we need to do for 1 selection
;*******************************************************************************
; Purpose: Prompt user to enter the maximum duty cycle value
; Input  : None
; Output : None, but register are altered

                    #spauto

PromptMaxDuty       proc
                    ldhx      #mesbuf             ;Load address to beginning of message buffer
                    sthx      .mes                ;Reset message pointer to start of buffer

                    ldhx      #strgmx             ;Transfer next string into message buffer
                    jsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       min_duty            ;Transfer a single byte value
                    jsr       HexToASCII          ; into the buffer as an ASCII value
                    jsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strgxf             ;Transfer rest of string into RAM buffer
                    jsr       StrXfr
                    ldhx      #mesbuf             ;Load in pointer to message to send
                    txa                           ;Put lower byte of address into Acc
                    psha      tmp@@               ;Use value to calc # of bytes in message
                    lda       .mes+1              ;Load least significant byte of pointer
                    sub       tmp@@,sp            ;Subtract least significant byte of start
                    ais       #1                  ;Remove value from the stack
                    jsr       WaitDMA2            ;Wait for any previous transfer to finish
                    jsr       XmitStr             ;Tranfer message to the user and
                    jsr       WaitDMA2            ; wait for string to finish transmission
                    bsr       GetPackedBCD        ;Get the packed BCD response from user
                    cmpa      min_duty            ;Is this greater than the min duty cycle
                    bgt       TooBig@@            ;If so, make sure it isn't too large

                    ldhx      #mesbuf             ;Load address to beginning of message buffer
                    sthx      .mes                ;Reset message pointer to start of buffer

                    ldhx      #strexl             ;Transfer next string into message buffer
                    jsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       min_duty            ;Transfer a single byte value
                    jsr       HexToASCII          ; into the buffer as an ASCII value
                    jsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strfin             ;Transfer rest of string into RAM buffer
                    jsr       StrXfr
                    ldhx      #mesbuf             ;Load in pointer to message to send
                    txa                           ;Put lower byte of address into Acc
                    psha      tmp@@               ;Use value to calc # of bytes in message
                    lda       .mes+1              ;Load least significant byte of pointer
                    sub       tmp@@,sp            ;Subtract least significant byte of start
                    ais       #1                  ;Remove value from the stack
                    jsr       WaitDMA2            ;Wait for any previous transfer to finish
                    jsr       XmitStr             ;Tranfer message to the user and
                    jsr       WaitDMA2            ; wait for string to finish transmission
                    bra       PromptMaxDuty       ;Prompt them again for the value

TooBig@@            cmpa      #91                 ;Is the value less than 91
                    blt       Save@@              ;If so, value is ok
                    ldhx      #strexh             ;Tell user they entered too large a value
                    jsr       XmitStr
                    jsr       WaitDMA2
                    bra       PromptMaxDuty       ;Prompt them again for the value

Save@@              sta       max_duty            ;Checks out ok, so save
                    bra       UpdateTimerBuffer   ;Update the timer buffer with this value
                                                  ;All we need to do for 2 selection

;*******************************************************************************
; Purpose: Prompt user to enter the duty cycle step size
; Input  : None
; Output : None, but register are altered

                    #spauto

PromptDutyStep      proc
Loop@@              ldhx      #strdcs             ;Prompt user to enter duty cycle step size
                    jsr       XmitStr             ; (strdcs) via the SCI/DMA
                    jsr       WaitDMA2            ;Wait for string transfer to finish
                    lda       #9                  ;Max value for the step size is 9
                    bsr       GetDigit            ;Get the digit from the user
                    tsta                          ;Did he enter a non-zero number?
                    bne       Save@@              ;If so, then this is a good step size

                    ldhx      #strlss             ;Tell user that step size is too low
                    jsr       XmitStr
                    jsr       WaitDMA2
                    bra       Loop@@              ;Prompt them again for the value

Save@@              sta       duty_step           ;Store value into global variable
                    bra       UpdateTimerBuffer   ;Update the timer buffer with this value
                                                  ;All we need to do for 3 selection

;*******************************************************************************
; Purpose: Get a packed BCD number from the user
; Input  : None
; Output : Packed BCD value will be in accumulator
; Note(s): Only valid decimal digits will be echoed to the user,
;        : and the routine requires two digits be entered, without the
;        :need for a carriage return.

                    #spauto

GetPackedBCD        proc
                    lda       #9                  ;Set max potential digit to be 9
                    bsr       GetDigit            ;Get 1st digit of user's response
                    asla                          ;Multiply digit by 2
                    psha      ans@@               ;Save result
                    tsx
                    asla:2                        ;User's digit times 8
                    add       ans@@,spx           ;Acc = 8*digit+2*digit = 10*digit
                    sta       ans@@,spx           ;Save result over now useless data
                    lda       #9                  ;Set max potential digit to be 9
                    bsr       GetDigit            ;Get second digit of user's response
                    add       ans@@,spx           ;Accumulator now has packed BCD value
                    ais       #:ais               ;Remove value from the stack
                    rts                           ;Return with BCD number in acc

;*******************************************************************************
; Purpose: Update timer PWM buffer
; Input  : None
; Output : None
; Note(s): Dependancy: The three static variables min_duty, max_duty, and
;        : duty_step need to be properly setup before this
;        : routine is called.  It uses the static variable
;        ; buf_size which is altered by the SetupBuf routine.

                    #spauto

UpdateTimerBuffer   proc
                    bclr      TEC1,DC1            ;Disable timer's DMA channel
                    clr       D1BC                ; and ready it for a new transfer
                    jsr       SetupBuf            ;Update the buffer
                    mov       buf_size,D1BL       ;Update the buffer size
                    bset      TEC1,DC1            ;Restart the timer PWM
                    rts                           ;New PWM has begun

;*******************************************************************************
; Purpose: Accept input from the terminal, echoing only digits, and
;        : returning the decimal values to the calling routine
; Input  : Maximum digit value acceptable in Acc
; Output : Decimal digit accepted from user in Acc
; Note(s): Clears all pending receiver interrupts, enables
;        : the receiver and its interrupts, and then waits for the
;        : interrupt.  The receiver ISR will disable the RE bit,
;        : which tells this routine that a byte has been received.
;        : The ISR places the received byte in the static variable,
;        : rx_byte.  If the received byte is valid, it is echoed to
;        : the user, otherwise no response is made.  Once a valid
;        : value is received, the decimal equivalent is returned.

                    #spauto

GetDigit            proc
                    psha      max@@               ;Save max value
Loop@@              lda       SCS1                ;Clear any pending SCI receive flags
                    lda       SCDR
                    bset      RE,SCC2             ;Enable SCI receiver
                    bset      SCRIE,SCC2          ; with interrupts
Wait@@              wait                          ;Wait for digit to be accepted
                    brset     RE,SCC2,Wait@@      ;If receiver still active, wait more
                    lda       #'0'                ;Load acceptable lower bound
                    cmpa      rx_byte             ;Is value less than lower bound?
                    bgt       Loop@@              ;If so, keep looking for valid value
                    add       max@@,sp            ;Acc now has upper limit
                    cmpa      rx_byte             ;Is value greater than upper bound?
                    blt       Loop@@              ;If so, keep looking for valid value
                    pula                          ;Clear value off of stack
                    lda       rx_byte             ;Load in the valid received value
                    bclr      SCTIE,SCC2          ;Disable SCI transmitter interrupts
                    bclr      DMATE,SCC3          ;Use the CPU to send 1 byte via SCI
                    brclr     SCTE,SCS1,*         ;Wait for TE to become set
                    sta       SCDR                ;Echo back to screen
                    bset      DMATE,SCC3          ;Reconfigure SCI as a DMA interrupt
                    bset      SCTIE,SCC2          ;Re-enable SCI transmitter interrupts
                    sub       #'0'                ;Convert to a decimal value
                    rts

;*******************************************************************************
; Purpose: Send the status string to the user
; Input  : None
; Output : None, but registers are altered
; Note(s): To do so, we need to build up a status message in the RAM
;        : string buffer. This message consistents of 3 text segments
;        : each terminated with a value.

                    #spauto

SendStatusString    proc
                    ldhx      #mesbuf             ;Load address to beginning of message buffer
                    sthx      .mes                ;Reset message pointer to start of buffer

                    ldhx      #strsbg             ;Transfer next string into message buffer
                    bsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       min_duty            ;Transfer a single byte value
                    bsr       HexToASCII          ; into the buffer as an ASCII value
                    bsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strsmd             ;Transfer next string into message buffer
                    bsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       max_duty            ;Transfer a single byte value
                    bsr       HexToASCII          ; into the buffer as an ASCII value
                    bsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strsed             ;Transfer next string into message buffer
                    bsr       StrXfr              ;Transfer the string into RAM buffer
                    lda       duty_step           ;Transfer a single byte value
                    bsr       HexToASCII          ; into the buffer as an ASCII value
                    bsr       WaitDMA2            ;Wait for string transfer to finish

                    ldhx      #strsfn             ;Transfer rest of string into RAM buffer
                    bsr       StrXfr
                    ldhx      #mesbuf             ;Load in pointer to message to send
                    txa                           ;Put lower byte of address into Acc
                    psha      tmp@@               ;Use value to calc # of bytes in message
                    lda       .mes+1              ;Load least significant byte of pointer
                    sub       tmp@@,sp            ;Subtract least significant byte of start
                    ais       #1                  ;Remove value from the stack
                    bsr       WaitDMA2            ;Wait for any previous transfer to finish
                    bsr       XmitStr             ;Tranfer message to the user and
                    bra       WaitDMA2            ; wait for string to finish transmission

;*******************************************************************************
; Purpose: Convert a hex value into an ASCII character, and then transfer
;        : it to the message buffer
; Input  : Hex value to convert is in Acc.
;        : Buffer location to place ASCII in .mes variable.
; Output : .mes variable updated to point to next free location

                    #spauto

HexToASCII          proc
                    push                          ;Save registers on the stack to preserve

                    clrh                          ;Clear H so that HX has proper byte offset
                    tax                           ;Transfer value into X to serve as offset
                    lda       h2pbcd,x            ;Load in converted value
                    psha                          ;Save value on stack
                    and       #$f0                ;Mask off lower nibble
                    beq       Lower@@             ;Value is < 10, so only print 1 digit
                    nsa                           ;Shift upper nibble into lower nibble
                    and       #$0F
                    add       #'0'                ;Convert number to ascii
                    ldhx      .mes                ;Load in place to store value
                    sta       ,x                  ;Store into message table
                    aix       #1                  ;Increment to next empty position in table
                    bra       Skip@@              ;skip load of message point--in HX
Lower@@             ldhx      .mes                ;Load in place to store converted value
Skip@@              pula                          ;Restore converted value to print
                    and       #$0f                ;Mask off upper nibble
                    add       #'0'                ;Convert number to ascii
                    sta       ,x                  ;Store into message table
                    aix       #1                  ;Increment to next empty position in table
                    sthx      .mes                ;Update static message pointer variable

                    pull                          ;Restore registers
                    rts

;*******************************************************************************
; Purpose: Use DMA CH2 to transfer an ASCII string to RAM message buffer
; Input  : Pointer to beginning of string to transfer in HX
;        : Number of bytes in string in Acc
;        : Place to put string in a RAM message pointer--.mes
; Output : None
; Note(s): Updates the .mes to where next string should begin

                    #spauto

StrXfr              proc
                    bsr       Length              ;length of string in A

                    sthx      D2SH                ;Source is beginning of string
                    ldhx      .mes                ;Set dest addr to be value in current
                    sthx      D2DH                ; RAM message buffer pointer
                    mov       #$A4,D2C            ;Inc src, inc dest, byte, and
                                                  ; set to SPI receive (unused)

                    sta       D2BL                ;Acc has number of bytes in string
                    bset      IEC2,DC1            ;Enable DMA CH2 w/ interrupts
                    bset      TEC2,DC1            ; so the software bit can be cleared
                    bset      4,DC2               ;Initiate DMA transfer

                    ldhx      .mes                ;Update message pointer to point to
                    aax                           ; where next string (in this case the
                    aix       #1                  ; ASCII value) should begin.
                    sthx      .mes                ;AIX #1 is for ASCIZ terminator
                    rts

;*******************************************************************************
; Purpose: Wait for DMA CH2 to finish its current transfer before returning
; Input  : None
; Output : None
                    #spauto

WaitDMA2            proc
                    sei                           ;Don't allow interrupt that is
                                                  ; needed to pull MCU out of wait
                                                  ; to occur between BRCLR & WAIT
                    brclr     TEC2,DC1,Done@@     ;Transfer complete already?
Loop@@              wait                          ;Allow DMA CH2 to complete
                                                  ; Also clears I bit to allow int
                    sei                           ;Don't allow interrupt b/f WAIT
                    brset     TEC2,DC1,Loop@@     ;DMA CH2 finished if TEC2 is clear
Done@@              cli                           ;Interrupt has been taken,
                    rts                           ; so allow others to occur

;*******************************************************************************
; Purpose: Subroutine used to initiate a transfer to the SCI via DMA CH2
; Input  : 1) 16 bit address pointer to beginning of string in HX
;        : 2) Number of bytes in string in Acc (max of 256).
; Output : None, but DMA CH2 is enabled to transmit to SCI
; Note(s): Assumptions: Channel 2 looping is disabled, DMA DMAP and bandwidth
;        :              are configured as desired.

                    #spauto

XmitStr             proc
                    sthx      D2SH                ;Pointer to start of string -> src reg

                    clr       D2DH                ;Move SCI data register (in page zero)
                    mov       #SCDR,D2DL          ; into destination register
                    mov       #$87,D2C            ;Select Inc. Source & Static Dest.,
                                                  ; Byte transfers, and SCI Transmit Int

                    bsr       Length              ;get length of string in A
                    sta       D2BL                ;Number of bytes to send -> block len reg

                    bset      IEC2,DC1            ;Enable DMA CH2 with interrupts
                    bset      TEC2,DC1
                    rts

;*******************************************************************************
; Purpose: Return the length of an ASCIZ string
; Input  : HX -> ASCIZ string
; Output : A = length (max is 255)

                    #spauto

Length              proc
                    pshhx
                    clra
Loop@@              tst       ,x
                    beq       Done@@
                    dbnza     Loop@@
                    nega
Done@@              pulhx
                    rts

;*******************************************************************************
; Purpose: Routine used to fill buffer with values to send to timer
;        : to create variable PWM on channel 0--registers unaltered
; Input  : Correct values already set in min_duty, max_duty, and
;        : duty_step variables.
; Output : buf_size will contain the number of bytes in buffer

                    #spauto

SetupBuf            proc
                    push                          ;Save value of registers on stack

                    asl       duty_step           ;Double step size to keep buffer < 200 bytes
                    ldhx      #bufbegin           ;Point to beginning of buffer
                    lda       min_duty            ;Load in first buffer value
                    clr       buf_size            ;Initialize byte count to 0
Buf1@@              sta       ,x                  ;Store value into buffer
                    aix       #2                  ;Skip over preset buffer value
                    inc       buf_size            ;Increment number of entries
                    add       duty_step           ;Increment PWM by step size
                    cmpa      max_duty            ;Compare to max value
                    bls       Buf1@@              ;If not exceeded, store and do next
                    lda       buf_size            ;Double buffer size to account
                    add       buf_size            ; for fixed values stored in buffer
                    psha      tmp@@               ;Remember number of bytes stored so far

                    lda       max_duty            ;Load in next buffer value
                    clr       buf_size            ;Ready byte count for second half
Buf2@@              sta       ,x                  ;Store value into buffer
                    aix       #2                  ;Skip over preset buffer value
                    inc       buf_size            ;Increment number of entries
                    sub       duty_step           ;Decrement PWM by step size
                    cmpa      min_duty            ;Compare to min value
                    bhs       Buf2@@              ;If still higher, store and do next
                    lda       buf_size            ;Double buffer size to account
                    add       buf_size            ; for fixed values stored in buffer
                    add       tmp@@,sp            ;Add in value from first half
                    sta       buf_size            ;Store total off for later
                    pula                          ;Clear value off of the stack
                    asr       duty_step           ;Restore step size back to entered value

                    pull                          ;Restore registers from stack
                    rts

;*******************************************************************************
; Purpose: Interrupt service routine for the DMA
; Input  : None
; Output : For channel 2, the IFC2 bit is cleared.
; Note(s): Only DMA CH2 can create interrupts.

                    #spauto

DMA_Handler         proc
                    brclr     IFC2,DSC,Done@@     ;CH2 interrupt service routine
                    bclr      IFC2,DSC            ;Clear CH2 flag
                    clr       DC2                 ;Clear any software initiated transfer
Done@@              rti                           ;Not needed for SCI servicing

;*******************************************************************************
; Purpose: Interrupt service routine for the SCI receiver
; Input  : None
; Output : Received data byte put into static variable rx_byte
; Note(s): SCI receiver is disabled after each received byte

                    #spauto

SCI_Handler         proc
                    lda       SCS1                ;Load status reg--ignore error flags
                    mov       SCDR,rx_byte        ;Store received byte for other routines
                    bclr      SCRIE,SCC2          ;Disable the SCI receiver interrupts
                    bclr      RE,SCC2             ; and receiver itself between chars
                    rti

;-------------------------------------------------------------------------------
; Program constants
;-------------------------------------------------------------------------------

AbsMaxDuty          dw        99                  ;Change to next pulse width at 99% of period
                                                  ; when increasing (two bytes for DMA)
spidata             fcc       $0f                 ;Create a clock with output of SPI MOSI
                                                  ; By changing data, one can change freq
                                                  ; of the clock used to generate PWM
;*******************************************************************************
;                    Strings to be printed to the user
;*******************************************************************************
; Note(s): Naming convention: str<name> indicates the beginning of the <name> string
;        :                    end<name> indicates the end of the <name> string
;        : All end<name> labels should be followed by 1 byte to be consistent.
;        : Following each string is an equate (called len<name>) that equals the
;        :    string's length in bytes ( len<name> = end<name>-str<name>+1 ).
;        : Some messages need to have numbers inserted into them, so there is
;        :    a separate string for each message segment.
;        : This naming convention must be followed to use the defined macros.
;        : Note that no message is allowed to have more than a total of 256 bytes.

; ASCII control character equates

CR                  equ       13                  ;Return cursor to beginning of line
LF                  equ       10                  ;Advance cursor one line
CLS                 equ       $1a                 ;Clear screen
;-------------------------------------------------------------------------------
strint              fcc       CLS
                    fcc       'Welcome to the DMA demonstration.  The SPI MOSI '
                    fcc       'is being used to generate',LF
                    fcc       'an external clock for the timer which in turn is '
                    fcc       'generating a varying',LF
                    fcc       'PWM on channel 0--both continuously driven '
                    fcc       'by the DMA.  Also, all text',LF
                    fcs       'is sent using the SCI via the DMA.',LF
                    #size     strint

strsbg              fcc       LF,LF
                    fcc       'Currently generating a waveform that varies from a '
                    fcs       'duty cycle of '
                    #size     strsbg

strsmd              fcs       '% to '

strsed              fcs       '% at',LF,'a step size of '

strsfn              fcs       '.  Please choose which you would like to alter.'

strsel              fcc       LF,LF,'Would you like to change',LF
                    fcc       '   0) back to the default values',LF
                    fcc       '   1) the minimum duty cycle value',LF
                    fcc       '   2) the maximum duty cycle value',LF
                    fcc       '   3) the step size of the change in duty cycle',LF
                    fcs       '  ?'
                    #size     strsel

strgmn              fcc       LF,LF,'Please enter the minimum duty cycle '
                    fcc       '[must be an integer between 10',LF
                    fcs       'and '
                    #size     strgmn

strgmf              fcs       '--the current maximum duty cycle]: '

stremh              fcc       LF,'The minimum duty cycle must be less than the '
                    fcs       'current maximum duty cycle',LF,'value of '
                    #size     stremh

strfin              fcs       '.  Please try again.'

streml              fcc       LF,'The minimum duty cycle must be greater than 9.'
                    fcs       '  Please try again.'
                    #size     streml

strgmx              fcc       LF,LF,'Please enter the maximum duty cycle '
                    fcs       '[must be an integer between '
                    #size     strgmx

strgxf              fcs       '--current',LF,'min duty cycle--and 90]: '

strexl              fcc       LF,'The maximum duty cycle must be greater than the '
                    fcs       'current minimum duty cycle',LF,'value of '
                    #size     strexl

strexh              fcc       LF,'The maximum duty cycle must be less than 91.'
                    fcs       '  Please try again.'
                    #size     strexh

strdcs              fcc       LF,LF,'Please enter the duty cycle step size '
                    fcs       '[must be an integer between 1 and 9]: '
                    #size     strdcs

strlss              fcc       LF,'The duty cycle step size must be greater than 0.'
                    fcs       '  Please try again.'
                    #size     strlss

;*******************************************************************************

h2pbcd              fcb       $00,$01,$02,$03,$04,$05,$06,$07,$08,$09
                    fcb       $10,$11,$12,$13,$14,$15,$16,$17,$18,$19
                    fcb       $20,$21,$22,$23,$24,$25,$26,$27,$28,$29
                    fcb       $30,$31,$32,$33,$34,$35,$36,$37,$38,$39
                    fcb       $40,$41,$42,$43,$44,$45,$46,$47,$48,$49
                    fcb       $50,$51,$52,$53,$54,$55,$56,$57,$58,$59
                    fcb       $60,$61,$62,$63,$64,$65,$66,$67,$68,$69
                    fcb       $70,$71,$72,$73,$74,$75,$76,$77,$78,$79
                    fcb       $80,$81,$82,$83,$84,$85,$86,$87,$88,$89
                    fcb       $90,$91,$92,$93,$94,$95,$96,$97,$98,$99

;*******************************************************************************
                    #VECTORS
;*******************************************************************************

                    org       SCIRec_INT
                    dw        SCI_Handler

                    org       DMA_INT
                    dw        DMA_Handler

                    org       Vreset
                    dw        Start
