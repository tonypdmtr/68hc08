;*******************************************************************************
; File name: LCD.ASM
; Example Code for LCD Module (HD44780) using either 4-bit or 8-bit bus
; Ver: 1.0
; Date: April 10, 1998
; Author: Mark Glenewinkel
;         Motorola Field Applications
;         Consumer Systems Group
; Assembler: ASM8 http://www.aspisys.com/asm8.htm
;
; For code explanation and flow charts,
; please consult Motorola Application Note
;    "Interfacing the HC705C8A to an LCD Module"
;    Literature # ANxxxx/D
;
; Adapted to ASM8 by Tony Papadimitriou <tonyp@acm.org>
; Define WIDEBUS for 8-bit mode and leave undefined for 4-bit mode
;*******************************************************************************

#ifdef ?
  #Hint +===================================================
  #Hint | Available conditionals (for use with -Dx option)
  #Hint +===================================================
  #Hint | WIDEBUS: Use 8-bit mode LCD data bus
  #Hint +===================================================
  #Fatal Run ASM8 -Dx (where x is any of the above)
#endif
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
                    #MCF
          #ifdef WIDEBUS
                    #Message  LCD in 8-bit mode
          #else
                    #Message  LCD in 4-bit mode
          #endif
;*******************************************************************************
; Application Specific Definitions
;*******************************************************************************

LCD_CTRL            equ       PORTA
LCD_DATA            equ       PORTB
LCD_E               @pin      LCD_CTRL,0
LCD_RW              @pin      LCD_CTRL,2
LCD_RS              @pin      LCD_CTRL,1

;*******************************************************************************
                    #ROM
;*******************************************************************************

Start               proc
          ;-------------------------------------- ; Initialize Ports
                    clr       LCD_CTRL            ; clear LCD_CTRL
                    clr       LCD_DATA            ; clear LCD_DATA
                    lda       #$FF                ; make ports outputs
                    sta       LCD_CTRL+DDR
                    sta       LCD_DATA+DDR
          ;-------------------------------------- ; Initialize the LCD
                    lda       #150                ; Wait for 15ms
                    bsr       VarDelay            ; sub for 0.1ms delay
          ;-------------------------------------- ; Send Init Command
          #ifdef WIDEBUS
                    lda       #$38                ; LCD init command
          #else
                    lda       #$30                ; LCD init command
          #endif
                    sta       LCD_DATA
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
          ;-------------------------------------- ; Wait for 4.1ms
                    lda       #41
                    bsr       VarDelay            ; sub for 0.1ms delay
          ;-------------------------------------- ; Send Init Command
          #ifdef WIDEBUS
                    lda       #$38                ; LCD init command
          #else
                    lda       #$30                ; LCD init command
          #endif
                    sta       LCD_DATA
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
          ;-------------------------------------- ; Wait for 100 us
                    lda       #1
                    bsr       VarDelay            ; sub for 0.1ms delay
          ;-------------------------------------- ; Send Init Command
          #ifdef WIDEBUS
                    lda       #$38                ; LCD init command
          #else
                    lda       #$30                ; LCD init command
          #endif
                    bsr       LcdWrite            ; write data to LCD
          ;-------------------------------------- ; Send Function Set Command
          #ifdef WIDEBUS                          ; 8 bit bus, 2 rows, 5x7 dots
                    lda       #$38                ; function set command
          #else                                   ; 4 bit bus, 2 rows, 5x7 dots
                    lda       #$20                ; function set command
                    bsr       LcdWrite            ; write data to LCD

                    lda       #$20                ; function set command
                    bsr       LcdWrite            ; write data to LCD

                    lda       #$80                ; function set command
          #endif
                    bsr       LcdWrite            ; write data to LCD
          ;--------------------------------------
          ; Send Display Ctrl Command, display on, cursor off, no blinking
          ;--------------------------------------
          #ifdef WIDEBUS
                    lda       #$0C                ; display ctrl command
          #else
                    clra                          ; display ctrl command MSB
                    bsr       LcdWrite            ; write data to LCD
                    lda       #$C0                ; display ctrl command LSB
          #endif
                    bsr       LcdWrite            ; write data to LCD
          ;--------------------------------------
          ; Send Clear Display Command, clear display, cursor addr=0
          ;--------------------------------------
          #ifdef WIDEBUS
                    lda       #$01                ; clear display command
          #else
                    clra                          ; clear display command MSB
          #endif
                    bsr       LcdWrite            ; write data to LCD
                    lda       #16
                    bsr       VarDelay            ; sub for 0.1ms delay
          #ifndef WIDEBUS
                    lda       #$10                ; clear display command LSB
                    bsr       LcdWrite            ; write data to LCD
                    lda       #16
                    bsr       VarDelay            ; delay for 1.6ms
          #endif
          ;--------------------------------------
          ; Send Entry Mode Command increment, no display shift
          ;--------------------------------------
          #ifdef WIDEBUS
                    lda       #$06                ; entry mode command
          #else
                    clra                          ; entry mode command MSB
                    bsr       LcdWrite            ; write data to LCD
                    lda       #$60                ; entry mode command LSB
          #endif
                    bsr       LcdWrite            ; write data to LCD
          ;--------------------------------------
          ; Send messages
          ; Set the address, send data
          ;--------------------------------------
                    bsr       Message1            ; send Message1
                    bsr       Message2            ; send Message2
                    bra       *                   ; done with example

;*******************************************************************************
; SUBROUTINES
;*******************************************************************************

;*******************************************************************************
; Routine creates a delay according to the formula time*100us
; (using a BUS_KHZ internal bus)

VarDelay            proc
                    psha
                              #Cycles
Loop@@              bsr       Delay100us
                    dbnza     Loop@@
                              #temp :cycles
                    pula
                    rts

;*******************************************************************************
                              #Cycles :temp
Delay100us          proc
                    pshhx
                    ldhx      #DELAY@@
                              #Cycles
Loop@@              aix       #-1
                    cphx      #0
                    bne       Loop@@
                              #temp :cycles
                    pulhx
                    rts

DELAY@@             equ       100*BUS_KHZ/1000-:cycles-:ocycles/:temp

;*******************************************************************************
; Routine sends LCD Data

LcdWrite            proc
                    sta       LCD_DATA
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
;                   bra       Delay40us

;*******************************************************************************
                              #Cycles 5
Delay40us           proc
                    psha
                    lda       #DELAY@@
                              #Cycles
                    dbnza     *
                              #temp :cycles
                    pula
                    rts

DELAY@@             equ       40*BUS_KHZ/1000-:cycles-:ocycles/:temp

;*******************************************************************************
; Routine sends LCD Address

LcdAddr             proc
                    bclr      LCD_RS              ; LCD in command mode
                    sta       LCD_DATA
                    bset      LCD_E               ; clock in data
                    bclr      LCD_E
                    bsr       Delay40us
                    bset      LCD_RS              ; LCD in data mode
                    rts

;*******************************************************************************

Message1            proc
          #ifdef WIDEBUS
                    lda       #$84                ; addr = $04
          #else
                    lda       #$80                ; addr = $04 MSB
                    bsr       LcdAddr             ; send addr to LCD
                    lda       #$40                ; addr = $04 LSB
          #endif
                    bsr       LcdAddr             ; send addr to LCD
                    clrhx
Loop@@              lda       Msg1,x              ; load AccA w/char from msg
                    beq       Done@@              ; end of msg?
                    bsr       LcdWrite            ; write data to LCD
          #ifndef WIDEBUS
                    lda       Msg1,x              ; load Acca w/char from msg
                    nsa                           ; swap LSB with MSB
                    bsr       LcdWrite            ; write data to LCD
          #endif
                    aix       #1
                    bra       Loop@@              ; loop to finish msg
Done@@              equ       :AnRTS

;*******************************************************************************

Message2            proc
                    lda       #$C0                ; addr = $40 MSB
          #ifndef WIDEBUS
                    bsr       LcdAddr             ; send addr to LCD
                    clra                          ; addr = $40 LSB
          #endif
                    bsr       LcdAddr             ; send addr to LCD
                    clrhx
Loop@@              lda       Msg2,x              ; load AccA w/char from msg
                    beq       Done@@              ; end of msg?
          #ifndef WIDEBUS
                    bsr       LcdWrite            ; write data to LCD
                    lda       Msg2,x              ; load AccA w/char from msg
                    asla:4                        ; shift LSB to MSB
          #endif
                    bsr       LcdWrite            ; write data to LCD
                    aix       #1
                    bra       Loop@@              ; loop to finish msg
Done@@              equ       :AnRTS

;*******************************************************************************

Msg1                fcs       'Motorola'
Msg2                fcs       'Microcontrollers'

;*******************************************************************************
                    @vector   Vreset,Start
;*******************************************************************************
