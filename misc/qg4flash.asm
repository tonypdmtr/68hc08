;*******************************************************************************
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;*******************************************************************************

;*******************************************************************************
; Example of quick and dirty EEPROM emulation in QG8 Flash
; By Peg from Freescale forums. Adapted to ASM8 by tonyp@acm.org
; Designed to be used on a DEMOQG8 board
; --- What it does ---
; On power up checks if string "Peg" is in buffer at FLASH_ADDRESS
; If it is it turns LED on
; If you press SW it will either erase the page at FLASH_ADDRESS
; or program the string in there, depending on LED status.
; So, if you repeatedly power up and press the button
; you should have the LED on every second time.
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     qg8.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

mByteProg           def       $20
mPageErase          def       $40

;*******************************************************************************
; SUBROUTINE:   FlashProg1
; ON ENTRY:     H:X - points at the flash byte to be programmed
; A holds the data for the location to be programmed
; ON RETURN:    H:X unchanged and A = FSTAT shifted left by 2 bits
; Z=1 if OK, Z=0 if protect violation or access error
; Uses 32 bytes of stack space + 2 bytes for BSR/JSR used to call it
; USES:         DoOnStack which uses SpSub
;*******************************************************************************

                    #spauto

FlashProg1          proc
                    psha                          ;temporarily save entry data
                    lda       #FPVIOL_|FACCERR_   ;mask
                    sta       FSTAT               ;abort any command and clear errors
                    lda       #mByteProg          ;mask pattern for byte prog command
                    bsr       DoOnStack           ;execute prog code from stack RAM
                    ais       #:ais               ;deallocate data location from stack
                    rts                           ;Z = 1 means there was an error

;*******************************************************************************
; SUBROUTINE:   FlashErase1
; ON ENTRY:     H:X - points at a location in a page to be erased
; ON RETURN:    H:X unchanged a A = FSTAT shifted left by 2 bits
; Z=1 if OK, Z=0 if protect violation or access error
; Uses 32 bytes of stack space + 2 bytes for BSR/JSR used to call it
; USES:         DoOnStack which uses SpSub
;*******************************************************************************

                    #spauto

FlashErase1         proc
                    psha                          ;adjust sp for DoOnStack entry
                    lda       #FPVIOL_|FACCERR_   ;mask
                    sta       FSTAT               ;abort any command and clear any errors
                    lda       #mPageErase         ;mask pattern for page erase command
                    bsr       DoOnStack           ;finish command from stack based subroutine
                    ais       #:ais               ;de-allocate data location from stack
                    rts                           ;Z = 0 means there was an error

;*******************************************************************************
; SUBROUTINE:       SpSub                                                                         ;
;*******************************************************************************

_CMD_               equ       1,1
_ADR_               equ       2,2

                    #spauto   2+::SpSub

SpSub               proc
                    ldhx      _ADR_,sp
                    sta       ,x

                    lda       _CMD_,sp
                    sta       FCMD

                    lda       #FCBEF_
                    sta       FSTAT

                    lsra                          ;FCBEF_ -> FCCF_

Loop@@              bit       FSTAT
                    beq       Loop@@
                    rts                           ;back into DoOnStack in flash

                    #size     SpSub

;*******************************************************************************
; SUBROUTINE:   DoOnStack
; ON ENTRY:     H:X - points at the flash byte to be programmed
; A holds the data for the location to be programmed
; ON RETURN:    H:X unchanged a A = FSTAT shifted left by 2 bits
; Z=1 if OK, Z=0 if protect violation or access error
; Uses 32 bytes of stack space + 2 bytes for BSR/JSR used to call it
; USES:         DoOnStack which uses SpSub
;*******************************************************************************

                    #spauto   2

DoOnStack           proc
                    @parms    data
                    pshhx                         ;save pointer to flash
                    psha                          ;save command to stack

                    ldhx      #SpSub+::SpSub-1    ;point at last byte to move to stack
Loop@@              lda       ,x                  ;read from flash
                    psha                          ;move onto stack
                    aix       #-1                 ;next byte to move
                    cphx      #SpSub              ;past end?
                    bhs       Loop@@              ;loop until the whole subroutine is on stack

                    #spadd    ::SpSub-1           ;tell assembler how stack has grown

                    tsx                           ;point to subroutine on stack
                    lda       data@@,spx          ;preload data for command
                    bms       Cont@@              ;skip if I already set
                    sei                           ;block interupts while flash busy
                    jsr       ,x                  ;execute the subroutine on the stack
                    cli                           ;OK to cleat the I mask now
                    bra       Done@@              ;continue to stack de-allocation

Cont@@              jsr       ,x                  ;execute the subroutine on the stack
Done@@              ais       #:ais               ;de-allocate subroutine body _ H:X + command
                                                  ;H:X flash pointer OK from SpSub
                    lsla                          ;A=00 & Z=1 unless PVIOL or ACCERR
                    rts                           ;to flash where DoOnStack was called

;*******************************************************************************
                    #sp
;*******************************************************************************
                    #Exit

LED                 pin       PTBD,6
SW                  pin       PTAD,2

FLASH_ADDRESS       def       $FB00

;*******************************************************************************
; Macros
;*******************************************************************************

LED                 macro     On|Off
          #ifparm ~1~ = ON
                    bclr      LED                 ;turn on LED (active low)
          #else
                    bset      LED                 ;turn off LED (active low)
          #endif
                    bset      LED+DDR             ;make it an output
                    endm

;*******************************************************************************

Start               proc
                    @rsp

                    lda       #$52
                    sta       SOPT1               ;disable COP

                    lda       NVICSTRM            ;get the ICS trim value
                    sta       ICSTRM              ;trim ICS

                    lda       #FLASH_CLK_VALUE
                    sta       FCDIV               ;set flash clock

                    @LED      Off

                    lda       #%00001100          ;apply pullups to pushbuttons
                    sta       PTAPE

?                   macro     UnquotedString
                    lda       FLASH_ADDRESS+{:loop-1}
                    cmp       #\@~1.{:loop}.1~\@  ;check if string present
                    bne       NoPeg@@
                    mtop      :1
                    endm

                    @?        Peg                 ;check if string present

                    @LED      On                  ;turn on LED as "Peg" string is in Flash

NoPeg@@             brset     SW,*                ;wait for SW to be pressed
                    bsr       Erase               ;call erase routine to erase string (whole page really)
                    brset     LED,WritePeg@@      ;program in string as it is blank
                    bra       *                   ;wait here forever
          ;--------------------------------------
?                   macro     UnquotedString
                    ldhx      #FLASH_ADDRESS+{:loop-1}
                    lda       #\@~C1~\@           ;char/byte to program there
                    jsr       FlashProg1
                    mtop      :1
                    endm

WritePeg@@          @?        Peg
          ;--------------------------------------
                    bra       *                   ;wait here forever

;*******************************************************************************

                    #spauto

Erase               proc
                    ldhx      #FLASH_ADDRESS      ;get beginning address of page to be erased
                    jmp       FlashErase1         ;call erase routine to be sure is blank

;*******************************************************************************
                    @vector   Vreset,Start
;*******************************************************************************
