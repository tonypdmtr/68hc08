;*******************************************************************************
; LCDTERM.ASM
;
; LCD Terminal with an MC68HC908QY4 and an HD44780 LCD display
; PortA Bit 0 is used for RS232 reception via the GetByte ROM routine
; Since the LCD display is a bit slow, Getbyte is turned into a KeyBoard
; Interrupt routine called. KBInt is active on PTA0 and we on
; falling edge called, there GetByte is called and the
; Data saved. The MCU is programmed with the UserMonitor.
; Therefore the alternative vector addresses are used.
;
;
; Everything that is urgently needed is available
; Adding the ability to load characters would be good
; Characters greater than 127 are not intercepted, but do not match
; German character set
; Control characters like CR LF or Backspace are not implemented
; The terminal should only be from an MC anyway and not from a keyboard
; to be discribed
;*******************************************************************************

;*******************************************************************************
; VT100 Commands
;
; Reset Device          <ESC>c                       ok
; Cursor Home           <ESC>[H                      ok
; Cursor Up             <ESC>[{COUNT}A
; Cursor Down           <ESC>[{COUNT}B
; Cursor Forward        <ESC>[{COUNT}C
; Force Cursor Position <ESC>[{ROW};{COLUMN}f        ok
; Scroll Up             <ESC>M                       ok
; Erase End of Line     <ESC>[K                      ok
; Erase Line            <ESC>[2K                     ok
; Erase Screen          <ESC>[2J                     ok
;*******************************************************************************
                    #ListOff
                    #Uses     qy4.inc
                    #ListOn
;*******************************************************************************
; SYSTEM DEFINITIONS AND EQUATES
;*******************************************************************************

TRIMLOC             equ       $FFC0               ; nonvolatile trim value (flash)
INIT_CONFIG1        equ       %01001001           ; Config Register1
GetByte             equ       $2D6b               ; ROM routine getbyte on PTA0
          ;-------------------------------------- ; Application Specific Definitions
LCD_DATA            equ       PORTB
LCD_COLS            equ       16                  ; LCD columns
LCD_E               pin       PORTA,4
LCD_RS              pin       PORTA,5
ESC                 def       $1B                 ; Escape Character
          ;-------------------------------------- ; SCI definitions
KEY                 pin       PORTA
          ;-------------------------------------- ; LCD commands
CLRDISP             equ       %00000001           ; Clear display
CURHOME             equ       %00000010           ; Cursor Home
ENTMODI             equ       %00000111           ; Character entry mode with increment
ENTMODD             equ       %00000101           ; Character entry mode with decrement
ENTMODO             equ       %00000100           ; Character Entry Moode Off
DSPON               equ       %00001100           ; Diplay On
DSPOFF              equ       %00001000           ; Display off
CURON               equ       %00001111           ; Cursor underline blinking on
CUROFF              equ       %00001100           ; Cursor off
SETRAMADR           equ       %01000000           ; Set Ram Adress
SETDSPADR           equ       %10000000           ; Set display address
FUNCSET             equ       %00111000           ; Function set 8 bit 5 * 7 pixels
          ;-------------------------------------- ; LCD addresses
ROW1ADR             equ       $80                 ; Start address line 1
ROW2ADR             equ       $C0                 ; Start address line 2

;*******************************************************************************
                    #RAM
;*******************************************************************************

time                rmb       1                   ; used in delay routine
current_ch          rmb       1                   ; current character
row                 rmb       1                   ; row
col                 rmb       1                   ; column
inptr               rmb       1                   ; position in the receive buffer for reception
outptr              rmb       1                   ; position in the receive buffer for output
data                rmb       32                  ; Receive data buffer 32 bytes
screen              rmb       32                  ; Memory image of the display 2 lines of 16 bytes each
parm1               rmb       1                   ; Parameters for VT commands
parm2               rmb       1

;*******************************************************************************
                    #ROM
;*******************************************************************************

;*******************************************************************************
; Main routine
;*******************************************************************************

Start               proc
                    lda       #INIT_CONFIG1       ; Write config register
                    sta       CONFIG1
                    lda       TRIMLOC             ; Load oscillator trim value
                    sta       OSCTRIM             ; and put

                    jsr       RamInit             ; Initialize ram
          ;-------------------------------------- ; Initialize ports
                    bclr      LCD_E               ; clear LCD_CTRL
                    bclr      LCD_RS
                    clr       LCD_DATA            ; clear LCD_DATA
                    lda       #$FF                ; make ports outputs
                    sta       DDRB                ; PortB output
                    bset      LCD_E+DDR           ; PORTA Pins as outputs
                    bset      LCD_RS+DDR
          ;-------------------------------------- ; Initialize keyboard int on PTA0
                    sei                           ; first prohibit interuppts
                    mov       #%00000100,KBSCR    ; Pending ints delete ints allow falling edge
                    mov       #%00000001,KBIER    ; Allow PTA0 interrupt
          ;-------------------------------------- ; Initialize LCD
                    bsr       LCD_Init
          ;-------------------------------------- ; further initializations
                    lda       #$80                ; Address start of line 1
                    jsr       LCD_Addr            ; send addr to LCD
                    clr       row                 ; and write out cursor position
                    clr       col
;                   lda       #$80
;                   jsr       LCD_Addr
                    cli                           ; allow interrupts from now on
          ;-------------------------------------- ; Actual processing begins
MainLoop@@          jsr       GetChar             ; Fetch characters
                    cmpa      #' '
                    blo       Ctrl@@              ; < space is control character

                    sta       current_ch
                    jsr       LCD_Write           ; Output characters
                    lda       row
                    nsa
                    add       col
                    tax
                    lda       current_ch
                    sta       screen,x
                    inc       col                 ; Count up the column
                    lda       col                 ; Last column ?
                    cmpa      #LCD_COLS
                    bne       MainLoop@@          ; no then the next sign
                    lda       row                 ; 2nd line?
                    bne       BeginLine@@         ; yes, then get only the beginning
                    inc       row                 ; Increase line counter

BeginLine@@         lda       #ROW2ADR            ; Load start address 2nd line
                    jsr       LCD_Addr            ; Set address
                    clr       col                 ; Set column to 0
                    bra       MainLoop@@          ; and from the front

Ctrl@@              cmpa      #ESC                ; ESC then command
                    bne       Cont@@              ; others not at first
                    clr       parm1               ; initialize parameters
                    clr       parm2
                    jsr       VT_Command
          ;--------------------------------------
          ; ignore other control characters first
          ;--------------------------------------
Cont@@              bra       MainLoop@@          ; and start all over again

;*******************************************************************************
; Subroutines
;*******************************************************************************

;*******************************************************************************
; Wait 100 us for TIME
; (@3.2 MHz internal bus frequency, that's 320 cycles)

VarDelay            proc
Loop@@              bsr       ?Delay100us
                    dbnz      time,Loop@@
                    rts

;*******************************************************************************
                              #Cycles
?Delay100us         proc
                    psha
                    lda       #DELAY@@
                              #Cycles
                    dbnza     *
                              #temp :cycles
                    pula
                    rts

DELAY@@             equ       BUS_KHZ/10-:cycles-:ocycles/:temp

;*******************************************************************************
; LCD Routines
;*******************************************************************************

;*******************************************************************************
; Initialize the display

LCD_Init            proc
          ;-------------------------------------- ; with 15ms delay
                    bclr      LCD_RS              ; LCD auf Instruction setzen
                    mov       #150,time           ; set delay time
                    bsr       VarDelay            ; sub for 0.1ms delay
          ;-------------------------------------- ; send init command
                    lda       #FUNCSET            ; LCD init command
                    sta       LCD_DATA
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
          ;-------------------------------------- ; 4.1ms delay
                    mov       #41,time            ; set delay time
                    bsr       VarDelay            ; sub for 0.1ms delay
          ;-------------------------------------- ; send init command (2nd time)
                    lda       #FUNCSET            ; LCD init command
                    sta       LCD_DATA
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
          ;-------------------------------------- ; 100us delay
                    mov       #1,time             ; set delay time
                    bsr       VarDelay            ; sub for 0.1ms delay
          ;-------------------------------------- ; send init command
                    lda       #FUNCSET            ; LCD init command
                    jsr       LCD_Write           ; write data to LCD
          ;--------------------------------------
          ; send function set command
          ; 8 bit bus, 2 rows, 5x7 dots
          ;--------------------------------------
                    lda       #FUNCSET            ; function set command
                    jsr       LCD_Write           ; write data to LCD
          ;--------------------------------------
          ; send display ctrl command
          ; display on, cursor off, no blinking
          ;--------------------------------------
                    lda       #DSPON              ; display ctrl command
                    jsr       LCD_Write           ; write data to LCD
          ;--------------------------------------
          ; send clear display command
          ; clear display, cursor addr=0
          ;--------------------------------------
                    bsr       LCD_Clear
          ;--------------------------------------
          ; send entry mode command
          ; increment, no display shift
          ;--------------------------------------
                    lda       #$06                ; entry mode command
                    jsr       LCD_Addr            ; write data to LCD
          ;--------------------------------------
          ; send messages
          ; set the address, send data
          ;--------------------------------------
                    jsr       Message1            ; send Message1
                    jmp       Message2            ; send Message2

;*******************************************************************************
; Clear the LCD

LCD_Clear           proc
                    lda       #CLRDISP            ; clear display command
                    jsr       LCD_Addr            ; write data to LCD
                    mov       #16,time            ; set delay time for 1.6ms
                    bsr       VarDelay            ; sub for 0.1ms delay
                    clrx
                    lda       #' '
Loop@@              sta       screen,x            ; and the screen buffer
                    incx
                    cmpx      #::screen           ; fill with spaces
                    bne       Loop@@
                    rts

;*******************************************************************************
; Cursor Home

LCD_Home            proc
                    lda       #CURHOME            ; clear display command
                    bsr       LCD_Addr            ; write data to LCD
                    clr       row                 ; cursor Position merken
                    clr       col
                    mov       #16,time            ; set delay time for 1.6ms
                    bra       VarDelay            ; sub for 0.1ms delay

;*******************************************************************************
; Scrolls one line

LCD_Scroll          proc
                    clrx                          ; x delete
Loop@@              lda       screen+LCD_COLS,x   ; load lower line
                    sta       screen,x            ; in upper store
                    lda       #' '                ; Write blanks on the bottom line
                    sta       screen+LCD_COLS,x
                    incx
                    cmpx      #LCD_COLS
                    bne       Loop@@
                    bsr       WriteScreen         ; and spend
                    lda       #ROW2ADR
                    bsr       LCD_Addr
                    clr       col
                    rts

;*******************************************************************************
; Clear to the end of the line

LCD_ClrEol          proc
                    lda       row                 ; Load line counter
                    bne       _1@@                ; line 1 ?
                    lda       #ROW1ADR            ; otherwise load address from line 0
                    bra       _2@@                ; continue

_1@@                lda       #ROW2ADR            ; Load address from line 1
_2@@                add       col                 ; Add up the column
                    bsr       LCD_Addr            ; set address
                    ldx       col                 ; Load the column position of the cursor
                    lda       row
                    bne       Loop2@@             ; line 1 then continue

Loop1@@             lda       #' '                ; load spaces
                    bsr       LCD_Write           ; and spend
                    incx                          ; Increase counter
                    cmpx      #LCD_COLS           ; until the end of the line
                    bne       Loop1@@

                    lda       #ROW1ADR            ; Load address line 0
                    add       col                 ; Add column
                    bsr       LCD_Addr            ; set address
                    bra       _5@@                ; and further

Loop2@@             lda       #' '                ; load spaces
                    bsr       LCD_Write           ; and spend
                    incx                          ; Increase counter
                    cmpx      #LCD_COLS           ; until the end of the line
                    bne       Loop2@@
                    lda       #ROW2ADR            ; Load address line 1
                    add       col                 ; Add column
                    bsr       LCD_Addr            ; set address

_5@@                ldx       col                 ; Load line
                    lda       row                 ; load column in x
                    bne       _7@@                ; Line 1 then continue

Loop3@@             lda       #' '                ; Space in battery
                    sta       screen,x            ; and write in screenbuffer
                    incx                          ; x increase
                    cmpx      #LCD_COLS           ; to the end of the line
                    bne       Loop3@@
                    bra       Done@@              ; and out

_7@@                aix       #LCD_COLS           ; LCD_COLS for the second line
Loop4@@             lda       #' '                ; Error in battery
                    sta       screen,x            ; Fill the buffer
                    incx                          ; Increase counter
                    cmpx      #::screen           ; end of line?
                    bne       Loop4@@

Done@@              rts

;*******************************************************************************
; Write characters in the LCD registers

LCD_Write           proc
                    sta       LCD_DATA            ; output on data port
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
;                   bra       ?Delay40us

;*******************************************************************************
                              #Cycles
?Delay40us          proc
                    psha
                    lda       #DELAY@@
                              #Cycles
                    dbnza     *
                              #temp :cycles
                    pula
                    rts

DELAY@@             equ       40*BUS_KHZ/1000-:cycles-:ocycles/:temp

;*******************************************************************************
; Sets the LCD address to the value of the registers

LCD_Addr            proc
                    bclr      LCD_RS              ; LCD in command mode
                    sta       LCD_DATA            ; output on data port
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
                    bsr       ?Delay40us
                    bset      LCD_RS              ; LCD in data mode
                    rts

;*******************************************************************************
; Write the contents on the display

WriteScreen         proc
                    lda       #$80                ; addr = $80 row0 column0
                    bsr       LCD_Addr            ; send addr to LCD

                    clrx
_1@@                lda       screen,x            ; Load characters from buffer
                    bsr       LCD_Write           ; write data to LCD
                    incx
                    cmpx      #LCD_COLS
                    bne       _1@@                ; top line
          ;--------------------------------------
                    lda       #$C0                ; addr = $C0 row1 column0
                    bsr       LCD_Addr            ; send addr to LCD

_2@@                lda       screen,x            ; Load characters from buffer
                    bsr       LCD_Write           ; write data to LCD
                    incx
                    cmpx      #::screen
                    bne       _2@@                ; bottom line
                    rts

;*******************************************************************************
; Message1 and Message2 give you from sport news

Message1            proc
                    lda       #$84                ; addr = $04 Zeile1 Spalte4
                    ldhx      #Msg@@
                    bra       ?LCD_Write

Msg@@               fcs       'NITRON'

;*******************************************************************************

Message2            proc
                    lda       #$C0                ; addr = $C0 Zeile2 Spalte0
                    ldhx      #Msg@@
                    bra       ?LCD_Write

Msg@@               fcs       'LCD Terminal'

;*******************************************************************************

?LCD_Write          proc
                    bsr       LCD_Addr            ; send addr to LCD
Loop@@              lda       ,x                  ; load AccA w/char from msg
                    beq       Done@@              ; end of msg?
                    bsr       LCD_Write           ; write data to LCD
                    aix       #1
                    bra       Loop@@              ; loop to finish msg
Done@@              equ       :AnRTS

;**************************************************************************
; End of the LCD routines
;**************************************************************************

;*******************************************************************************
; initializes the RAM memory

RamInit             proc
                    clra
                    sta       time
                    sta       row
                    sta       col
                    sta       inptr
                    sta       outptr
                    sta       parm1
                    sta       parm2
                    clrx
          ;--------------------------------------
                    lda       #' '
Loop@@              clr       data,x
                    sta       screen,x
                    incx
                    cmpx      #::screen
                    bne       Loop@@
                    rts

;*******************************************************************************
; fetches the next character from the buffer and returns it in the battery

GetChar             proc
                    pshx
Loop@@              ldx       outptr              ; Output pointer in the receive buffer
                    cmpx      inptr               ; Compare with input pointer
                    beq       Loop@@              ; both right then there is nothing
                    lda       data,x              ; otherwise charge in battery
                    incx                          ; increase index
                    stx       outptr              ; and save output pointer
                    cmpx      #::data             ; end of the buffer?
                    bne       Done@@              ; no then out
                    clr       outptr              ; otherwise set the pointer to the beginning of the buffer
Done@@              pulx
                    rts

;*******************************************************************************
; Edit VT100 commands
;
; (Force cursor position is not implemented)

VT_Command          proc
                    bsr       GetChar             ; Get character after ESC
                    cmpa      #'c'                ; Reset device?
                    bne       ScrollUp?@@         ; otherwise continue
                    jsr       LCD_Init            ; reset
                    bsr       RamInit             ; Initialize ram
                    jsr       LCD_Home            ; and set cursor
                    jmp       Done@@              ; and out

ScrollUp?@@         cmpa      #'M'                ; Scroll Up?
                    bne       _1@@                ; otherwise continue
                    jsr       LCD_Scroll          ; Scroll
                    jmp       Done@@              ; and out

_1@@                cmpa      #'['                ; Everything else starts with square brackets
                    bne       Fail@@              ; otherwise out because of errors
                    bsr       GetChar             ; Get the next character
                    cmpa      #'H'                ; Cursor Home?
                    bne       _2@@                ; otherwise continue
                    jsr       LCD_Home            ; Cursor Home
Fail@@              jmp       Done@@              ; and out

_2@@                cmpa      #'K'                ; Clear to end of line
                    bne       _3@@                ; otherwise continue
                    jsr       LCD_ClrEol          ; delete line to the end
                    jmp       Done@@              ; and out

_3@@                cmpa      #'2'                ; there are several possibilities here
                    bne       _5@@
                    sta       parm1               ; first save, could be parameters
                    bsr       GetChar             ; next character
                    cmpa      #'K'                ; K is erase line
                    bne       _4@@                ; otherwise keep trying
                    clr       col                 ; set column to 0
                    jsr       LCD_ClrEol          ; and delete to the end of the line
                    bra       Done@@              ; and out

_4@@                cmpa      #'J'                ; J is clear screen
                    bne       _5@@                ; otherwise continue testing
                    jsr       LCD_Clear
                    bra       Done@@

_5@@                cmpa      #'1'                ; Force cursor position
                    bne       _6@@                ; here only with lines 0 and 1
                    sub       #'0'                ; conversion to binary
                    sta       parm1               ; save because another value is coming
                    bra       Force@@

_6@@                cmpa      #'0'
                    bne       _9@@
                    sub       #'0'                ; convert to binary
                    sta       parm1               ; and save

Force@@             bsr       GetChar             ; Line saved next character
                    cmpa      #';'                ; delimiter
                    bne       _9@@
                    bsr       GetChar             ; next character
                    cmpa      #'2'                ; max 16 characters per line therefore first character less than 2
                    bhi       _7@@                ; or less than 10
                    sub       #'0'                ; convert to binary
                    nsa                           ; times 16
                    sta       parm2               ; and save
                    jsr       GetChar

_7@@                cmpa      #'f'                ; end first character is already column
                    bne       _8@@                ; Column is two digits
                    lda       parm2               ; divide value by 16 again
                    nsa
                    sta       parm2               ; and save
                    lda       parm1               ; fetch line
                    sta       row                 ; and secure
                    clc                           ; carry delete to zero push
                    rora:3                        ; Slide to the correct position
                    add       #$80                ; Add $80 to $80 or $C0
                    add       parm2               ; Add column load
                    jsr       LCD_Addr            ; Set address
                    lda       parm2               ; Note column in cursor position
                    sta       col
                    bra       Done@@              ; and finally

_8@@                cmpa      #'9'                ; The second character cannot be greater than 9
                    bhi       _9@@                ; otherwise out because of errors
                    sub       #'0'                ; make binary
                    add       parm2               ; add
                    cmpa      #$0A                ; greater than 10?
                    blo       Force2@@
                    sub       #$06                ; then subtract 6 because the 1 was multiplied by 16 above

Force2@@            sta       parm2               ; and secure
                    lda       parm1               ; fetch line
                    sta       row                 ; and save cursor position
                    clc                           ; carry delete to zero push
                    rora:3                        ; Slide to the correct position
                    add       #$80                ; Add $80 to $80 or $C0
                    add       parm2               ; Add up column load
                    jsr       LCD_Addr            ; set address
                    lda       parm2               ; and set splate for cursor position
                    sta       col
                    jsr       GetChar             ; should be f
                    !bra      Done@@
_9@@                !...      add error handling here (if needed)
Done@@              rts

;*******************************************************************************
; Keyboard Interrupt service Routine
;
; Is called with a falling edge on PTA0
; Calls GetByte and writes the received data to the receive buffer
; approx. 20 bars until Getbyte begins. Gebtbyte goes to the middle of the bit
; This shifts it backwards by about 20 bars. is at 9600 baud
; a bit of about 330 cycles should not be a problem
; Stop bit is ignored when receiving, therefore after receiving
; about 300 bars time before the next character can come.

KBD_Handler         proc
                    pshh
                    mov       #%00000010,KBIER    ; Disable 4 KB int
                    bclr      KEY                 ; initialize PTA0 for serial comms
                    jsr       GetByte             ; RS232 byte received
                    ldx       inptr               ; Load pointer for receive buffer
                    sta       data,x              ; and secure characters
                    incx                          ; Increase pointer
                    cmpx      #::data             ; end of buffer?
                    bne       Save@@              ; no then continue
                    clrx                          ; otherwise go to the beginning
Save@@              stx       inptr               ; and save
                    mov       #%00000100,KBSCR    ; Write ACK to clear everything
                    mov       #%00000001,KBIER    ; Allow ints on PTA0 again
                    pulh
                    rti

;*******************************************************************************
                    @vector   Vkeyboard,KBD_Handler
                    @vector   Vreset,Start
;*******************************************************************************
