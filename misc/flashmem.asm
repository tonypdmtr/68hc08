;*******************************************************************************
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;*******************************************************************************

;*******************************************************************************
; Example code for flashing JK3 memory
;*******************************************************************************

; The declarations are like this.....JK3 PART

CONFIG2             equ       $1E                 ;Configuration Register 2
CONFIG1             equ       $1F                 ;Configuration Register 1
FLBPR               equ       $FE09               ;FLASH Block Protect Register

RAM                 def       $80
STACKTOP            def       $100

ERASE_CMD           equ       $FC06
WRITE_CMD           equ       $FC09

ROM                 def       $EC40               ; change to wherever start of program ROM actually is

;*******************************************************************************
                    #RAM      RAM+8
;*******************************************************************************

ctrlbyt             rmb       1                   ; Mass erase flag is Bit6.
cpuspd              rmb       1                   ; CPU bus speed X 4 (e.g. 32 for 8 MHz)
laddr               rmb       2                   ; Last address for WRITE or program
data                equ       *
b_hyst_hir          rmb       1                   ; NOT TO BE OVERWRITTEN
b_typer             rmb       1                   ; NOT TO BE OVERWRITTEN
bxfd_durr           rmb       1                   ; NOT TO BE OVERWRITTEN
usa_cdnr            rmb       1                   ; NOT TO BE OVERWRITTEN
;-------------------------------------------------------------------------------
                    org       RAM+20

          ; here the variables used in the MAIN program
          ; ......

;*******************************************************************************
                    #ROM      ROM
;*******************************************************************************

Start               proc
                    ldhx      #STACKTOP
                    txs

                    clr       CONFIG2
                    mov       #$31,CONFIG1        ; DISEABLE COP & LVI

                    lda       #$FF                ; unprotect all the flash
                    sta       FLBPR
          ;-------------------------------------- ; first, erase the flash page
                    ldhx      #$EC01              ; any byte in page will do
                    mov       #4,cpuspd
                    bclr      6,ctrlbyt
                    jsr       ERASE_CMD
          ;-------------------------------------- ; next, program the flash page
                    ldhx      #$EC00+3            ; set ending range address
                    sthx      laddr
                    ldhx      #$EC00              ; set begin of range
                    mov       #4,cpuspd           ; set cpu speed=1Mhz
                    jsr       WRITE_CMD           ; program the data range

                    bra       *                   ; stay here forever (or rest of program)
