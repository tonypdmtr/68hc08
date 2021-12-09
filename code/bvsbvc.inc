;*******************************************************************************
;* Include   : BVSBVC.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Macros to implement missing oVerflow bit instructions, i.e.,
;*           : Set/Clear CCR[V], and non-CCR-destructive BVC and BVS equivalents
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/bvsbvc.html
;* Note(s)   : Use: #Include bvsbvc.inc
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #CaseOn
                    #HideMacros
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; Set CCR[V] flag

sev                 macro
                    psha
                    tpa
                    ora       #$80
                    tap
                    pula
                    endm

;*******************************************************************************
; Clear CCR[V] flag

clv                 macro
                    psha
                    tpa
                    and       #$80^$FF
                    tap
                    pula
                    endm

;*******************************************************************************
; Branch if CCR[V] flag is clear

bvc                 macro
          #ifparm ~1~ = *
                    mset      1,{*}
          #endif
                    ais       #-2
                    push
                    tpa
                    ldhx      #Done$$$
                    tsta
                    bmi       Skip$$$
                    ldhx      #~#1~
Skip$$$
                    sthx      4,asp
                    tap
                    pull
                    RTS
Done$$$
          #ifspauto
                    #spadd    -2
          #endif
                    endm

;-------------------------------------------------------------------------------
; Jump equivalent for BVC (just for consistency)

jvc                 macro
                    @bvc      ~@~
                    endm

;*******************************************************************************
; Branch if CCR[V] flag is set

bvs                 macro
          #ifparm ~1~ = *
                    mset      1,{*}
          #endif
                    ais       #-2
                    push
                    tpa
                    ldhx      #Done$$$
                    tsta
                    bpl       Skip$$$
                    ldhx      #~#1~
Skip$$$
                    sthx      4,asp
                    tap
                    pull
                    RTS
Done$$$
          #ifspauto
                    #spadd    -2
          #endif
                    endm

;-------------------------------------------------------------------------------
; Jump equivalent for BVS (just for consistency)

jvs                 macro
                    @bvs      ~@~
                    endm

;*******************************************************************************
                    #Exit
;*******************************************************************************

;*******************************************************************************
;                   Test various macro expansions
;*******************************************************************************

                    #ListOff
                    #Uses     mcu.inc
                    #ListOn

                    #ROM

Start               proc
                    @rsp
                    clra                          ;(keeps simulator happy)

                    @sev
          ;---
                    @bvc      Error
          ;---
                    @clv
          ;---
                    @bvs      Error
          ;---
                    @clv
                    @bvc      BVC_OK
                    nop
BVC_OK              @sev
                    @bvs      ALL_OK
                    nop
ALL_OK              bra       *
Error               bra       *

                    @vector   Vreset,Start
