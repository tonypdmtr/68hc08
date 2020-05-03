;*******************************************************************************
;* Purpose   : CodeWarrior compatibility macros
;*           : (Makes it easier to transfer source code from CodeWarrior to ASM8)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : Public Domain.  Prepared by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/cw.html
;*******************************************************************************

                    #Exit     _CW_
_CW_
                    #Macro    @@
                    #OptRelOff
                    #OptRtsOff
                    #SpacesOn
                    #CaseOn
                    #MaxLabel 50

                    org       *

include             macro
                    #Include  ~1~
                    endm

fail                macro     Message
                    #Fatal    ~1~
                    endm

even                macro
                    align     2
                    endm

llen                macro
                    endm

spc                 macro
                    endm

title               macro     Message
                    endm

ttl                 macro
                    mset      #
                    @title    ~1~
                    endm

                    #ROM

ds.b                macro     Operands
                    rmb       ~{:loop}.~
                    mtop      :n
          #ifnb ~label~
                    #size     ~label~,1
          #endif
                    endm

ds.w                macro     Operands
                    rmb       ~{:loop}.~*2
                    mtop      :n
          #ifnb ~label~
                    #size     ~label~,2
          #endif
                    endm

dc.b                macro     Operands
                    fcb       ~{:loop}.~
                    mtop      :n
          #ifnb ~label~
                    #size     ~label~
          #endif
                    endm

dcb.b               macro
                    mset      #
                    @dc.b     ~1~
                    endm

dc.w                macro     Operands
                    dw        ~{:loop}.~
                    mtop      :n
          #ifnb ~label~
                    #size     ~label~
          #endif
                    endm

dcb.w               macro
                    mset      #
                    @dc.w     ~1~
                    endm

ABSENTRY            macro
                    endm

xdef.b              macro
                    mset      #
                    xdef      ~1~
                    endm

xdef.w              macro
                    mset      #
                    xdef      ~1~
                    endm

xdef                macro     Entry[,Entry]*
                    mreq      1
                    #Export   ~{:loop}.~
                    mtop      :n
                    endm

xref.b              macro
                    mset      #
                    xref      ~1~
                    endm

xref.w              macro
                    mset      #
                    xref      ~1~
                    endm

xref                macro     Entry[,Entry]*
~{:loop}.~          equ       -1                  ;;dummy w/ worst case size
                    mtop      :n
                    endm

xrefb               macro
                    mset      #
                    @xref     ~1~
                    endm

section             macro
          #ifparm ~1~ = short
                    #RAM
;;          #ifparm ~label~
;;~label~             set       *
;;          #endif
                    #Undef    ~label~
                    mexit
          #endif
                    #ROM
;;          #ifparm ~label~
;;~label~             set       *
;;          #endif
                    #Undef    ~label~
                    endm

bsct                macro
                    #RAM
                    endm

dsct                macro
                    #XRAM
                    endm

psct                macro
                    #ROM
                    endm

page                macro
                    #Page
                    endm

for                 macro     ;FOR i=n TO n
                    mset      #' '
                    mdo       ~1'='2~
~1'='1~             set       ~1'='2~
                    msuspend
                    mloop     ~3~
                    endm

feed_watchdog       macro
                    nop
                    endm
