;*******************************************************************************
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;*******************************************************************************
;*                                                                             *
;*        EEPROM Emulation using FLASH in MC68HC908QT/QY MCUs                  *
;*                                                                             *
;*  This listing includes an alternative Write subroutine to the               *
;*  one presented in Application Note AN2346. It avoids using the              *
;*  908QT/QY erase routine in ROM and thus the additional page erase           *
;*  described in Errata 68HC908QY/QTMSE3. It downloads code into               *
;*  RAM and uses all of the top half of the RAM (from $C0 to $FF).             *
;*                                                                             *
;*  The main subroutine "WrtBlock" is the same as in the Application           *
;*  Note code except that it calls "EEEPage" instead of the ROM                *
;*  subroutine "EraRnge". As long as this change is made to                    *
;*  WrtBlock, the only aditional code required is "EEEPage" and                *
;*  "EEEinRAM". The FLASH reading routime "RdBlock" and the                    *
;*  subroutine "FindClear" are identical to those in the Application           *
;*  Note.                                                                      *
;*                                                                             *
;*  Peter Topping                                   18th July 2002             *
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     qt4a.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

PgrRnge             equ       $2809               ;FLASH programming routine in ROM
CtrlByt             equ       $88                 ;control byte for ROM subroutines
CPUSpd              equ       $89                 ;CPU speed in units of 0.25MHz
LstAddr             equ       $8A                 ;last FLASH address to be programmed

; Additional equates

ERASE               equ       %00000010           ;erase bit in FLCR
HVEN                equ       %00001000           ;high voltage bit in FLCR
ERAHVEN             equ       %00001010           ;erase and high voltage bits in FLCR
;FLBPR              equ       $FFBE               ;flash block protect reg (flash)
;FLCR               equ       $FE08               ;FLASH control register

;*******************************************************************************
                    #ROM      $FD00
;*******************************************************************************

;*******************************************************************************
;*  RdBlock - Reads a block of data from FLASH and puts it in RAM              *
;*                                                                             *
;*  Calling convention:    ldhx   #Blk1page                                    *
;*                         lda    #Blk1Size                                    *
;*                         jsr    RdBlock                                      *
;*                                                                             *
;*  Inputs:  HX - pointing to start of FLASH page used for data               *
;*           A  - block size                                                  *
;*                                                                             *
;*  Returns: HX - pointing to start of FLASH block containing data            *
;*           A  - data from first byte of block                               *
;*                                                                             *
;*  Uses:    FindClear                                                         *
;*******************************************************************************

                    #spauto

RdBlock             proc
                    psha      blocksize@@         ;save block size
                    bsr       FindClear           ;find first erased block
                    cmpa      #$FF                ;was an erased block found ?
                    bne       Skip@@              ;if not then don't go back a block
                    txa                           ;get LS byte of address
                    and       #$3F                ;only look at address within page
                    beq       Skip@@              ;if 0 then no data so don't go back
                    txa                           ;if not get LS byte of address again
                    sub       blocksize@@,sp      ;and subtract block size to point
                    tax                           ;to start of valid data block
Skip@@              lda       ,x                  ;get first byte of data
                    ais       #:ais               ;de-allocate stack
                    rts

;*******************************************************************************
;*  WrtBlock - Writes a block of data into FLASH from RAM buffer               *
;*                                                                             *
;*  Calling convention:    ldhx   #Blk1page                                    *
;*                         lda    #Blk1Size                                    *
;*                         jsr    WrtBlock                                     *
;*                                                                             *
;*  Inputs:  HX - pointing to start of FLASH page used for data               *
;*           A  - block size                                                  *
;*                                                                             *
;*  Returns: nothing                                                           *
;*                                                                             *
;*  Uses:    FindClear, EEEPage, EEEinRAM (RAM), PgrRnge (ROM)                 *
;*******************************************************************************

                    #spauto

WrtBlock            proc
                    mov       #13,CPUSpd          ;3.2MHz/0.25MHz = 13
                    clr       CtrlByt             ;page (not mass) erase
                    psha      bs@@                ;save block size
                    bsr       FindClear           ;find first available erased block
                    cbeqa     #$FF,Found@@        ;if erased block found, write to it
                    bsr       EEEPage             ;if not then erase page
                    txa                           ;get LS byte of FLASH address
                    and       #$C0                ;and reset it to start of page
                    tax                           ;HX now pointing to first block

Found@@             pula                          ;get block size
                    pshx                          ;save start address LS byte
                    add       bs@@,sp             ;add block size to LS byte
                    deca                          ;back to last address in block
                    tax                           ;last address now in HX
                    sthx      LstAddr             ;save in RAM for use by ROM routine
                    pulx                          ;restore X (H hasn't changed)
                    jmp       PgrRnge             ;program block (includes RTS)

;*******************************************************************************
; Purpose: Finds first erased block within page
; Input  : HX -> start of page used for required data
;        : Stack - block size last thing on stack
; Output : if erased block found:
;        : HX -> start of first erased block in page
;        : A = $FF
;        : if no erased block found (page full):
;        : HX -> start of last written block
;        : A = $00

                    #spauto   2                   ;2 [RTS]

FindClear           proc
                    @parms    blocksize

                    lda       #$40                ;number of bytes in a page
                    sub       blocksize@@,sp      ;less number in first block
                    psha      counter@@           ;save bytes left

Loop@@              lda       ,x                  ;get first data byte in block
                    cbeqa     #$FF,Done@@         ;if erased byte exit, else try next

          #iftos counter@@
                    pula                          ;bytes left
                    sub       blocksize@@,sp      ;less number in next block
                    psha                          ;resave bytes left
          #else
                    lda       counter@@,sp        ;bytes left
                    sub       blocksize@@,sp      ;less number in next block
                    sta       counter@@,sp        ;resave bytes left
          #endif
                    bmi       NoRoom@@            ;enough for another block ?

                    txa                           ;yes, get LS byte of address
                    add       blocksize@@,sp      ;add block size
                    tax                           ;put it back (can't be a carry)
                    bra       Loop@@              ;and try again

NoRoom@@            clra                          ;no room but A can't be $FF
Done@@              ais       #:ais               ;fix stack pointer
                    rts

;*******************************************************************************
; Purpose: RAM resident part of EEEPage
;        : Delays calculated to give the required times assuming the bus
;        : clock is 3.2MHz + 25% ie 4.0MHz.
; Note(s): Call:    ldhx   #{pointer to routine}
;        :          jsr    ,x

                    #spauto

RAMSIZE             equ       56

EEEinRAM            proc
                    psha                          ;save CCR
                    lda       RAMSIZE,x           ;retrieve FLASH address MSB from RAM
                    ldx       RAMSIZE+1,x         ;and LS byte
                    tah                           ;MSB into h (address is now in HX)
                    lda       #ERASE
                    sta       FLCR                ;set ERASE bit in control register
                    lda       FLBPR               ;read block protection register
                    sta       ,x                  ;write to an address within page
                    lda       #14                 ;3 cycle loop so 14 times for delay
                    dbnza     *                   ;of 10us at 4 MHz (14*3/4MHz=10.5us)

                    lda       #ERAHVEN            ;ERASE and HVEN bit
                    sta       FLCR                ;set HVEN bit in control register
          ;-------------------------------------- ;delay 4ms of HVEN high
                    pshhx
                    ldhx      #DELAY@@
                              #Cycles
Loop@@              aix       #-1
                    cphx      #0
                    bne       Loop@@
                              #temp :cycles
                    pulhx

DELAY@@             equ       4*BUS_KHZ/:temp
          ;--------------------------------------
                    lda       #HVEN
                    sta       FLCR                ;clear ERASE bit
                    lda       #7                  ;3 cycle loop so 7 times for delay
                    dbnza     *                   ;of 10us at 4 MHz (7*3/4MHz=5.2us)

                    clra
                    sta       FLCR                ;clear HVEN bit
                    pula                          ;restore CCR (2 cycles)
                    brn       *                   ;3 more cycles ie >1us
                    rts

                    #size     EEEinRAM
          #if ::EEEinRAM <> RAMSIZE
                    #Warning  Change RAMSIZE to {::EEEinRAM}
          #endif

;*******************************************************************************
; Purpose: Erases a page of emulated EEPROM FLASH
; Input  : HX -> FLASH page to be erased
; Output : None
; Note(s): Call:    ldhx   #EEPage
;        :          jsr    EEEpage

                    #spauto

EEEPage             proc
                    pshhx                         ;save FLASH address in RAM for
                    #ais

                    ldhx      #RAMSIZE            ;get size of RAM resident routine
Loop@@              lda       EEEinRAM-1,x        ;get a byte of code
                    psha                          ;and put it into RAM
                    dbnzx     Loop@@              ;finished ?

                    #spadd    RAMSIZE-1

                    tsx                           ;pointer to RAM routine

                    tpa                           ;get CCR
                    sei                           ;disable interrupts
                    jsr       ,x                  ;execute RAM routine
                    tap                           ;restore CCR

                    ais       #:ais               ;de-allocate stack space
                    pulhx                         ;restore FLASH address
                    rts

;*******************************************************************************
                    #sp
;*******************************************************************************
