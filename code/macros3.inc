;*******************************************************************************
;* Include   : MACROS3.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Sample macro definitions for ASM8 (Win32 & Linux versions, only)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2021 by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/macros3.html
;* Note(s)   : Use: #Include macros3.inc
;*           :
;*           : These macros are actually nothing more than unrolled loops.
;*           :
;*           : All macros are written so that they are compatible with all
;*           : macro modes (#@Macro, #Macro, and #MCF) and their @@ submode.
;*           : Wherever a variable address is expected as parameter, you can use
;*           : a simple variable, an expression pointing to variable, or indexed
;*           : mode.  Wherever a pointer value is expected you can use immediate
;*           : mode, simple variable or related expression, or indexed mode to
;*           : specify from where to get that pointer.  This makes it possible
;*           : to use the same macros in a variety of situations and regardless
;*           : of addressing mode.  (Of course, when an indexed mode is used,
;*           : macro call parameter separator must be overridden to anything but
;*           : the default comma, to properly recognize the comma inside the
;*           : indexed parameter.)
;*           :
;*           : IMPORTANT: All macros in this file do NOT preserve any registers.
;*           :
;* History   : 11.01.04 v1.00 First release
;*           ; 11.02.01       Corrected INC.M
;*           ; 11.04.10       Made SUB.M destination optional (used for comparison)
;*           ; 11.11.20       Added MOVA.M macro
;*           ; 11.11.25       Added IsZero macro
;*           ; 13.04.03       Adapted to auto-size detection
;*           ; 13.04.05       Improved MOVA.M macro by adding immediate mode
;*           ; 13.04.24       Renamed IsZero.m to zero?.m
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; Test for zero for any-size variable

zero?.m             macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
          #if :mloop = 1
                    lda       ~1,~+{:mloop-1}~,1~
          #else
                    ora       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ~2~
                    endm

;*******************************************************************************
; CLR for any-size variable

clr.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
                    clr       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~
                    endm

;*******************************************************************************
; INC for any-size variable

inc.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
                    inc       ~1,~+{~2~-:mloop}~,1~
          #if :mloop <> ~2~
                    bne       Done$$$
          #endif
                    mloop     ~2~
Done$$$
                    endm

;*******************************************************************************
; COM for any-size variable

com.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
                    com       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~
                    endm

;*******************************************************************************
; NEG for any-size variable

neg.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
          #if ~2~ > 1
                    mdo
                    com       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~-1
          #endif
                    neg       ~1,~+{~2~-1}~,1~
          #if ~2~ > 1
                    mdo
                    bne       Done$$$
                    inc       ~1,~+{~2~-:mloop-1}~,1~
                    mloop     ~2~-1
Done$$$
          #endif
                    endm

;*******************************************************************************
; MOV for any-size variable

mov.m               macro     Source,Destination[,Size]
                    mreq      1,2:Source,Destination[,Size]
                    mdef      3,{::~2,~}
                    mdo
                    mov       ~1~+{:mloop-1},~2~+{:mloop-1}
                    mloop     ~3~
                    endm

;*******************************************************************************
; MOVA for any-size variable

mova.m              macro     [#]Source,Destination[,Size]
                    mreq      1,2:Source,Destination[,Size]
                    mdef      3,{::~2,~}
          #ifparm ~#~
                    mdo
                    lda       ~1~>{~3~-:mloop*8}&$FF
                    sta       ~2,~+{:mloop-1}~,2~
                    mloop     ~3~
                    mexit
          #endif
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    sta       ~2,~+{:mloop-1}~,2~
                    mloop     ~3~
                    endm

;*******************************************************************************
; LSL for any-size variable

lsl.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
          #if :mloop = 1
                    lsl       ~1,~+{~2~-:mloop}~,1~
          #else
                    rol       ~1,~+{~2~-:mloop}~,1~
          #endif
                    mloop     ~2~
                    endm

;*******************************************************************************
; LSR for any-size variable

lsr.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
          #if :mloop = 1
                    lsr       ~1,~+{:mloop-1}~,1~
          #else
                    ror       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ~2~
                    endm

;*******************************************************************************
; ASR for any-size variable

asr.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
          #if :mloop = 1
                    asr       ~1,~+{:mloop-1}~,1~
          #else
                    ror       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ~2~
                    endm

;*******************************************************************************
; ROR for any-size variable

ror.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
                    ror       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~
                    endm

;*******************************************************************************
; ROL for any-size variable

rol.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
                    mdef      2,{::~1,~}
                    mdo
                    rol       ~1,~+{~2~-:mloop}~,1~
                    mloop     ~2~
                    endm

;*******************************************************************************
; ADD for any-size variable

add.m               macro     Operand1,Operand2,Destination[,Size]
                    mreq      1,2,3:Operand1,Operand2,Destination[,Size]
                    mdef      4,{::~3,~}
                    mdo
                    lda       ~1,~+{~4~-:mloop}~,1~
          #if :mloop = 1
                    add       ~2,~+{~4~-:mloop}~,2~
          #else
                    adc       ~2,~+{~4~-:mloop}~,2~
          #endif
                    sta       ~3,~+{~4~-:mloop}~,3~
                    mloop     ~4~
                    endm

;*******************************************************************************
; SUB for any-size variable

sub.m               macro     Operand1,Operand2[,Destination][,Size]
                    mreq      1,2:Operand1,Operand2[,Destination][,Size]
          #ifb ~3~
                    mdef      4,{::~1,~}
          #else
                    mdef      4,{::~3,~}
          #endif
                    mdo
                    lda       ~1,~+{~4~-:mloop}~,1~
          #if :mloop = 1
                    sub       ~2,~+{~4~-:mloop}~,2~
          #else
                    sbc       ~2,~+{~4~-:mloop}~,2~
          #endif
          #ifnb ~3~
                    sta       ~3,~+{~4~-:mloop}~,3~
          #endif
                    mloop     ~4~
                    endm

;*******************************************************************************
; AND for any-size variable

and.m               macro     Operand1,Operand2,Destination[,Size]
                    mreq      1,2,3:Operand1,Operand2,Destination[,Size]
                    mdef      4,{::~3,~}
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    and       ~2,~+{:mloop-1}~,2~
                    sta       ~3,~+{:mloop-1}~,3~
                    mloop     ~4~
                    endm

;*******************************************************************************
; OR for any-size variable

ora.m               macro     Operand1,Operand2,Destination[,Size]
                    mreq      1,2,3:Operand1,Operand2,Destination[,Size]
                    mdef      4,{::~3,~}
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    ora       ~2,~+{:mloop-1}~,2~
                    sta       ~3,~+{:mloop-1}~,3~
                    mloop     ~4~
                    endm

;*******************************************************************************
; XOR for any-size variable

eor.m               macro     Operand1,Operand2,Destination[,Size]
                    mreq      1,2,3:Operand1,Operand2,Destination[,Size]
                    mdef      4,{::~3,~}
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    eor       ~2,~+{:mloop-1}~,2~
                    sta       ~3,~+{:mloop-1}~,3~
                    mloop     ~4~
                    endm

;*******************************************************************************
; CMP for any-size variable

cmp.m               macro     Operand1,Operand2[,Size]
                    mreq      1,2:Operand1,Operand2[,Size]
          #ifb ~#~
                    mdef      3,{::~1,~}
          #endif
          #ifb ~2.1.1~ = #
                    mdef      3,{::~2,~}
          #endif
                    mdef      3,1
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    cmpa      ~2,~+{:mloop-1}~,2~
          #if :mloop <> ~3~
                    bne       Done$$$
          #endif
                    mloop     ~3~
Done$$$
                    endm

;*******************************************************************************
; DIV for any-size variable (HX assumed already set with appropriate values)

div.m               macro     Variable[,Size]
                    mreq      1:Variable[,Size]
          #ifnz ::~1,~
                    mdef      2,{::~1,~}
          #endif
                    mdef      2,1
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    div
                    sta       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~
                    endm

;*******************************************************************************
                    #Exit
;*******************************************************************************
;                   Test various macro expansions
;*******************************************************************************
                    #HideMacros

                    #RAM

Op1                 rmb       2
Op2                 rmb       2
Ans                 rmb       2

                    #ROM

Start               proc
                    @add.m    Op1,Op2,Ans
                    @asr.m    Op1
                    @clr.m    Op1
                    @cmp.m    Op1,Op2
                    @com.m    Op1
                    @div.m    Op1
                    @inc.m    Op1
                    @zero?.m  Op1
                    @lsl.m    Op1
                    @lsr.m    Op1
                    @mov.m    Op1,Op2
                    @neg.m    Op1
                    @ora.m    Op1,Op2,Ans
                    @ror.m    Op1
                    @sub.m    Op1,Op2,Ans
          ;--------------------------------------
                    #ParmS    space
                    @add.m    Op1,sp Op2,x Ans,spx
                    @asr.m    Op1,sp
                    @clr.m    Op1,sp
                    @cmp.m    Op1,sp Op2,x
                    @com.m    Op1,sp
                    @div.m    Op1,sp
                    @zero?.m  Op1,sp
                    @inc.m    Op1,sp
                    @lsl.m    Op1,sp
                    @lsr.m    Op1,sp
                    @neg.m    Op1,sp
                    @ora.m    Op1,sp Op2,x Ans,spx
                    @ror.m    Op1,sp
                    @sub.m    Op1,sp Op2,x Ans,spx
          ;--------------------------------------
                    #ParmS
                    @sub.m    Op1,Op2
