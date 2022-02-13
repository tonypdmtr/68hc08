;*******************************************************************************
;* Module    : SQR.MOD
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Square root calculation
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE, Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;*           : Original code for the 80x86 from unknown origin
;* Segments  : RAM    : Variables
;*           : ROM    : Code
;*           : SEG9   : OS definitions (this allows adding more functions)
;* History   : 03.12.18 v1.00 Original (Based on HC11 version)
;*           : 19.09.12 v2.00 Major refactoring and disconnected from OS8
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
#ifdef ?
  #Hint *************************************************
  #Hint * Available Conditional Defines (for -Dx option)
  #Hint *************************************************
  #Hint * VALUE:nnn Value for testing (default 12345)
  #Hint *************************************************
  #Fatal Run ASM8 -Dx (where x is any of the above)
#endif
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; Purpose: Get the square root of the word in XA
; Input  : XA = 15-bit radicand
; Output : X  = root
;        : A  = remainder
; Note(s): If bit 15 of input is set, it's an error

                    #spauto

SqrRoot             proc
                    psha      remainder@@
                    pshx      root@@
                    pshh

                    ais       #-5                 ;allocate work variables
                    #temp     ::
t2@@                next      :temp,2
t1@@                next      :temp,2
counter@@           next      :temp
                    #ais      :temp

                    tsx
                    tst       root@@,spx
                    sec                           ;assume 'error'
                    bmi       Done@@
          ;--------------------------------------
                    tsx
                    clr       t2@@,spx
                    clr       t2@@+1,spx

                    lda       #]$4000
                    sta       t1@@,spx
                    clr       t1@@+1,spx

                    lda       #8
                    sta       counter@@,spx
          ;--------------------------------------
Loop@@              lda       remainder@@,spx
                    sub       t2@@+1,spx
                    sta       remainder@@,spx

                    lda       root@@,spx
                    sbc       t2@@,spx
                    sta       root@@,spx
          ;--------------------------------------
                    lda       remainder@@,spx
                    sub       t1@@+1,spx
                    sta       remainder@@,spx

                    lda       root@@,spx
                    sbc       t1@@,spx
                    sta       root@@,spx
                    bmi       Negative@@
          ;--------------------------------------
                    lsr       t2@@,spx
                    ror       t2@@+1,spx

                    lda       t2@@,spx
                    ora       t1@@,spx
                    sta       t2@@,spx

                    lda       t2@@+1,spx
                    ora       t1@@+1,spx
                    sta       t2@@+1,spx
                    bra       Cont@@
          ;--------------------------------------
Negative@@          lda       remainder@@,spx
                    add       t2@@+1,spx
                    sta       remainder@@,spx

                    lda       root@@,spx
                    adc       t2@@,spx
                    sta       root@@,spx
          ;--------------------------------------
                    lda       remainder@@,spx
                    add       t1@@+1,spx
                    sta       remainder@@,spx

                    lda       root@@,spx
                    adc       t1@@,spx
                    sta       root@@,spx
          ;--------------------------------------
                    lsr       t2@@,spx
                    ror       t2@@+1,spx

Cont@@              lsr       t1@@,spx
                    ror       t1@@+1,spx
                    lsr       t1@@,spx
                    ror       t1@@+1,spx
                    dbnz      counter@@,spx,Loop@@
          ;--------------------------------------
                    lda       t2@@+1,spx          ;root
                    sta       root@@,spx
          ;--------------------------------------
                    clc                           ;indicate 'success'
Done@@              ais       #:ais               ;de-allocate work variables
                    pull
                    rtc

;*******************************************************************************
                    #sp
;*******************************************************************************
                    #Exit

VALUE               def       12345               ;default value to test

;*******************************************************************************
                    #ROM
;*******************************************************************************

Start               proc
                    @rsp

                    ldx       #]VALUE             ;high byte in X
                    lda       #[VALUE             ;low byte in A
                    call      SqrRoot             ;for default VALUE -> H = 111, X = 24

                    bra       *

;*******************************************************************************
                    @vector   Vreset,Start
;*******************************************************************************
