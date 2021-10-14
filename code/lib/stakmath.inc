;*******************************************************************************
; Math-related macros used in conjunction with stakmath.sub library
; Common macros for all stakmath library operations (some not to be called directly)
;*******************************************************************************

_signed_            macro
          #ifndef SIGNED
                    #Warning  SIGNED \@~mfilename~\@ expected
          #endif
                    endm
;-------------------------------------------------------------------------------
_StkMthMax_         macro     Expression
                    mset      #
                    mtrim     1
                    #temp
                    mdo
                    mset      0,~'=()+-*\/&|^><'{:mloop}~
                    mtrim     0
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~text.1.1~~text.{:text}~ = []
                    mset      0,~text.2.{:text-2}~
          #endif
                    mset      0,~text,~           ;;remove possible index
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~text.1.1~ = #
                    mset      0,~text.2~          ;;remove # from number
          #endif
          #ifnb ~text~
            #ifnb ~text.1.1~ = .
                    #Warning  Pointers (~text~) have unknown size
            #endif
            #ifnum ~text~                         ;estimate byte size for numeric constant
              #ifnz ~text~>16
                #if 3 > :temp
                    #temp     3
                #endif
              #endif
              #ifnz ~text~>24
                #if 4 > :temp
                    #temp     4
                #endif
              #endif
            #endif
            #ifb ~text.1.1~ = :
              #ifnonum ~text~
                #ifdef ~text~
                  #if {::~text~} > :temp
                    #temp     ::~text~
                  #endif
                #endif
              #endif
            #endif
          #endif
                    mloop     {:1/2}              ;;max term/factor estimate
          #ifz :temp
                    #Warning  Undetermined bit-size (using 32-bit)
                    #temp     4
          #endif
;         #ifb \@~'*'~\@ = \@~1~\@                ;if any multiplication is present
;           #if :temp < 4
;                   #temp     :temp+1             ;give some more bits (normally double, but on average this is OK)
;           #endif
;         #endif
          #if :temp > 8                           ;for exceptional cases, enforce
                    #temp     8                   ;maximum available bit-size
          #endif
                    @_FindStkMth_ {:temp*8}
                    endm
;-------------------------------------------------------------------------------
; Default version -- works with signed/unsigned operands
; (In :MEXIT, it returns the actual bit-size used)
Eval                macro     Expression
                    #push
                    #HideMacros
                    mset      #
                    mtrim     1
                    @@_StkMthMax_ ~1~
                    #temp      :mexit
                    @@_FindStkMth_ {:temp}
                    #temp     :mexit
                    @@Eval{:temp} ~1~
                    mset      0,{:spcheck},{:spfree-:ais},{:ais}
                    #pull
          #ifspauto
                    #spauto   ~text,~
                    #spadd    ~text','2~
                    #ais
                    #spadd    ~text','3~
          #endif
                    mexit     {:temp}
                    endm
;-------------------------------------------------------------------------------
; Signed version -- gives warning to alert you if SIGNED was not defined
; (In :MEXIT, it returns the actual bit-size used)
EvalS               macro     Expression
                    mset      #
                    @@_signed_
                    @Eval     ~1~
                    endm
;-------------------------------------------------------------------------------
StrMath             macro
          #ifnb ~1~
            #ifdef ~1,~
              #ifnz ::~1,~
                    @_DoStr   {::~1,~*8}\,~1~\,~2~
                    mexit
              #endif
            #endif
          #endif
                    mset      #
                    mtrim     1
                    @@_StkMthMax_ ~1,~
                    #temp     :mexit
                    @_DoStr   {:temp}\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
_FindStkMth_        macro     BitVersion
                    #temp
                    mdo       ~1~/8               ;;find the next highest bit version included (but not less than requested)
            #ifdef _STKMTH{:mloop*8}_
              #ifz :temp
                    #temp     :mloop*8            ;;found
              #endif
            #endif
                    mloop     8                   ;;highest possible is 64 (8x8)
            #ifz :temp
                    mstop     Include STKMTH{~1~}.SUB (or higher)
            #endif
                    mexit     :temp
                    endm
;-------------------------------------------------------------------------------
_Eval_              macro     [BitSize,]Expression (eg. [ans=](a+b)*(a-b)/2)
          #if :macronest = 1
                    mstop     Macro not to be called directly (eg. use @Eval32)
          #endif
          #ifb ~00~ = ~0~
                    @@_needs_spauto_
                    mdef      1,32
                    mswap     0,1                 ;;bitsize now in ~ text ~
                    mdel      1
                    mset      #
                    @@Msg     --------------------------------------------------
                    @@Msg     Expr: ~1~
                    @@Msg     --------------------------------------------------
                    @@_FindStkMth_ ~text~
                    mset      0,{:mexit},~text~   ;;(bitsize to use, actual bitsize)
          #endif
                    mset      #
                    mreq      1:Expression (eg. [ans=](a+b)*(a-b)/2 -- spaces OK)
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifb ~00~ = ~0~
                    mtrim     1                   ;;remove all spaces
                    mset      #'='                ;;split on assignment (if any)
            #if :nn > 2
                    mstop     Too many assignment operators
            #endif
            #if :nn > 1
                    @@~0~     ~2~
          ;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-
                    mset      9                   ;;assume signed (when SIGNED)
              #ifparm ~1.1.1~~1.{:1}~ = []
                    mset      9,unsigned
                    mset      1,~1.2.{:1-2}~
              #endif
          ;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-;-
              #ifparm ~1.1.1~ = .                 ;;pointers ...
                #if ~text,~/8 <> ~text','2~/8
                    @@ResizeTOS #~text,~/8\,#~text','2~/8\,\,~9~
                    @@lea     ~1~
                    @@_?sei_  ~1~
                    @@pullv   ~1~ ~text','2~/8    ;;are resized and then pulled
                    @_?cli_   ~1~
                    mexit
                #endif
              #endif
              #ifdef ~1,~                         ;;if assignment var defined
                    @Save~text,~ ~1~              ;;save to it
                    mexit
              #endif
              #ifparm ~,1~ = ,spx                 ;;SPX is SP-equivalent in EVAL
                    mset      1,~1,~,sp           ;;change to SP-index
              #endif
              #ifparm ~,1~ = ,sp                  ;;else, if SP-indexed
~1,~                equ       ::,~text,~/8        ;;leave on stack with this name
                    @@Msg     Saved to TOS (~1,~)
                    mexit
              #endif
                    merror    Unknown variable \@~1~\@
            #endif
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifstr ~1~
            #if :1-2 > 4
                    mstop     String constant (~1~) too long
            #endif
                    @Load~text,~ #~1~
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~1.1.1~ = -                     ;;process leading negative
            #ifnum ~1~
                    @Load~text,~ #~1~             ;;numerics use immediate mode
                    mexit
            #endif
            #ifdef ~1.2~
              #ifz ::~1.2~
                    @Load~text,~ #~1~             ;;named constants use immediate mode
                    mexit
              #endif
            #endif
                    @~0~      #0~1~               ;;anything else, subtract from zero
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    mset      #'+-|^'             ;;split terms
          #if :nn > 1
                    mdo       2
                    @@~0~     ~{:nn-:mloop+2}.2~  ;;process terms right to left
                    mloop     :nn
                    @@~0~     ~1~                 ;;the first term without operator
                    mdo       2
            #ifparm ~{:mloop}.1.1~ = +
                    @@Msg     Add~text,~
                    call      StackAdd~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = -
                    @@Msg     Sub~text,~
                    call      StackSub~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = |
                    @@Msg     Or~text,~
                    call      StackOr~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = ^
                    @@Msg     Xor~text,~
                    call      StackXor~text,~
                    #spadd    -{~text,~/8}
            #endif
                    mloop     :nn
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    mset      #'*\/&><'           ;;split factors
          #if :nn > 1
                    mdo       2
                    @@~0~     ~{:nn-:mloop+2}.2~  ;;process factors right to left
                    mloop     :nn
                    @@~0~     ~1~                 ;;the first factor without operator
                    mdo       2
            #ifparm ~{:mloop}.1.1~ = *
                    @@Msg     Mul~text,~
                    call      StackMul~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = /
                    @@Msg     Div~text,~
                    call      StackDiv~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = \
                    @@Msg     Mod~text,~
                    call      StackMod~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = &
                    @@Msg     And~text,~
                    call      StackAnd~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = >
                    @@Msg     Shr~text,~
                    call      StackShr~text,~
                    #spadd    -{~text,~/8}
            #endif
            #ifparm ~{:mloop}.1.1~ = <
                    @@Msg     Shl~text,~
                    call      StackShl~text,~
                    #spadd    -{~text,~/8}
            #endif
                    mloop     :nn
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~1.1.4~~1.{:1}~ = NEG()         ;;do NEG(ate) function
                    @@~0~     ~1.5.{:1-5}~
                    @@Msg     Neg~text,~
                    call      StackNegate~text,~
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~1.1.4~~1.{:1}~ = ABS()         ;;do ABS(olute) function
                    @@~0~     ~1.5.{:1-5}~
                    @@Msg     Abs~text,~
                    call      StackAbs~text,~
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~1.1.4~~1.{:1}~ = SQR()         ;;do SQR() function -- square
                    @@~0~     ~1.5.{:1-5}~
                    @@Msg     Sqr~text,~(TOS)
                    tsx
                    call      StackLoad~text,~
                    call      StackMul~text,~
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifparm ~1.1.1~~1.{:1}~ = ()            ;;process parenthesized sub-expression
                    @~0~      ~1.2.{:1-2}~
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    mset      9                   ;;assume signed (when SIGNED)
          #ifparm ~1.1.1~~1.{:1}~ = []
                    mset      9,unsigned
                    mset      1,~1.2.{:1-2}~
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifnum ~#1~
                    mset      1,#~#1~             ;;numerics use immediate mode
          #endif
          #ifparm ~1.1.2~ = -:
                    mset      1,#~1~              ;;negative internal symbol use immediate
          #endif
          #ifparm ~1.1.1~ = :
                    mset      1,#~1~              ;;positive internal symbol use immediate
          #endif
          #ifb ~,1~
            #ifdef ~#1~
              #ifz ::~#1~
                    mset      1,#~#1~             ;;named constants use immediate
              #endif
            #endif
          #endif
          #ifparm ~,1~ = ,spx                     ;;SPX is SP-equivalent in EVAL
                    mset      1,~1,~,sp           ;;change to SP-index
          #endif
          #ifparm ~1.1.1~ = .                     ;;pointers ...
            #if ~text','2~/8 <> ~text,~/8
                    @@_?sei_  ~1~
                    @@pushv   ~1~ ~text','2~/8    ;;are pushed and then resized
                    @@_?cli_  ~1~
                    @ResizeTOS #~text','2~/8\,#~text,~/8\,\,~9~
                    mexit
            #endif
          #endif
          #ifnb ~9~
                    mset      1,[~1~]
          #endif
                    @Load~text,~ ~1~              ;;anything else, load as is
                    endm
;-------------------------------------------------------------------------------
Comp                macro     Exp1 Exp2
                    mset      #' '
                    mreq      1,2:Exp1 Exp2
                    #push
                    #spauto   :sp
                    push
                    #ais
                    @@Eval    a$$$,sp = ~1~
                    @@Eval    b$$$,sp = ~2~
                    @@_cmp_.s a$$$,sp b$$$,sp
                    ais       #:ais
                    pull
                    #pull
                    endm
;-------------------------------------------------------------------------------
Eval8               macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval16              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval24              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval32              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval40              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval48              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval56              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Eval64              macro
                    mset      #
                    @_Eval_   ~0.5~\,~1~
                    endm
;-------------------------------------------------------------------------------
Str16               macro     [Number],[ResultString]
                    @_DoStr   16\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
Str24               macro     [Number],[ResultString]
                    @_DoStr   24\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
Str32               macro     [Number],[ResultString]
                    @_DoStr   32\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
Str40               macro     [Number],[ResultString]
                    @_DoStr   40\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
Str48               macro     [Number],[ResultString]
                    @_DoStr   48\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
Str56               macro     [Number],[ResultString]
                    @_DoStr   56\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
Str64               macro     [Number],[ResultString]
                    @_DoStr   64\,~1~\,~2~
                    endm
;-------------------------------------------------------------------------------
_?sei_              macro
          #ifdef NO_CLI
                    mexit
          #endif
          #ifndef _MTOS_
                    mexit
          #endif
                    mset      #
          #ifnb ~','2~ = sp
                    mexit
          #endif
          #ifnb ~','2~ = spx
                    mexit
          #endif
          #ifnb ~','2~ = psp
                    mexit
          #endif
          #ifdef ~1,~
            #if ::~1,~ < 2
                    mexit
            #endif
          #endif
                    sei
                    endm
;-------------------------------------------------------------------------------
_?cli_              macro
          #ifdef NO_CLI
                    mexit
          #endif
          #ifndef _MTOS_
                    mexit
          #endif
                    mset      #
          #ifnb ~','2~ = sp
                    mexit
          #endif
          #ifnb ~','2~ = spx
                    mexit
          #endif
          #ifnb ~','2~ = psp
                    mexit
          #endif
          #ifdef ~1,~
            #if ::~1,~ < 2
                    mexit
            #endif
          #endif
                    cli
                    endm
;-------------------------------------------------------------------------------
_DoLoad             macro     BitSize[,Variable]  ;if no Variable, wherever HX points
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    mreq      1:BitSize[,Variable]
                    #temp     ~1~/8               ;;bytesize now in :temp
                    mdel      1                   ;;get rid of bitsize parm
                    mset      #                   ;;unite all parms into one
                    mtrim     1
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    mset      9                   ;;assume signed (when SIGNED)
          #ifparm ~1.1.1~~1.{:1}~ = []
                    mset      9,unsigned
                    mset      1,~1.2.{:1-2}~
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    @@_not_x_ ~1~                 ;;X-mode not allowed
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifnum ~1~
                    mset      1,#~1~              ;;numerics use immediate mode
          #endif
          #ifb ~,1~
            #ifdef ~#1~
              #ifz ::~#1~
                    mset      1,#~#1~             ;;named constants use immediate mode
              #endif
            #endif
          #endif
          #ifnb ~#~                               ;;process immediate mode
                    @@Msg     Load{:temp*8} ~1~
                    mset      1,~#1~
                    mset      0                   ;;use as flag for CLRH usage
                    mdo
            #ifz ~#1~>{:mloop-1*8}&$FF
              #ifz :text
                    clrh
                    mset      0,clrh              ;;flag CLRH was used
              #endif
                    pshh
            #else
                    ldx       #~#1~>{:mloop-1*8}&$FF
                    pshx
            #endif
                    mloop     :temp
                    mexit
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifnb ~1,~
            #ifb ~1.1.1~ = .                      ;;except for pointers
              #ifnz ::~1,~                        ;;and constants
                #if ::~1,~ <> :temp               ;;different-size variables
                    @@_?sei_  ~1~
                    @@pushv   ~1~                 ;;are pushed and then resized
                    @@_?cli_  ~1~
                    @ResizeTOS #{::~1,~}\,#{:temp}\,\,~9~
                    mexit
                #endif
              #endif
            #endif
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
          #ifndef ~1,~
                    #Warning  Loading forward \@~1,~\@ as var
          #endif
                    @@Msg     Load{:temp*8} ~1~
                    @@lea     ~1~                 ;;default case
                    @@_?sei_  ~1~
                    call      StackLoad{:temp*8}  ;;load as is
                    @@_?cli_  ~1~
          #ifspauto
                    #spadd    :temp
          #endif
                    endm
;-------------------------------------------------------------------------------
_DoSave             macro     BitSize[,Variable]  ;if no Variable, wherever HX points
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    mreq      1:BitSize[,Variable]
                    mset      2,~@@~
                    mtrim     2
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    mset      9                   ;;assume signed (when SIGNED)
          #ifparm ~2.1.1~~2.{:1}~ = []
                    mset      9,unsigned
                    mset      2,~2.2.{:2-2}~
          #endif
          ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                    @@_not_x_ ~2~
          #ifnb ~2,~
            #ifb ~2.1.1~ = .                      ;;except for pointers
              #ifnz ::~2,~                        ;;and constants
                #if ::~2,~ <> ~1~/8               ;;different-size variables
                    @@ResizeTOS #{~1~/8}\,#{::~2,~}\,\,~9~
                    @@_?sei_  ~2~
                    @@pullv   ~2~                 ;;are resized and then pulled
                    @_?cli_   ~2~
                    mexit
                #endif
              #endif
            #endif
          #endif
                    @@Msg     Save~1~ ~2~
                    @@lea     ~2~                 ;;default case
                    @@_?sei_  ~2~
                    call      StackSave~1~        ;;save as is
                    @@_?cli_  ~2~
          #ifspauto
                    #spadd    -~1~/8
          #endif
                    endm
;-------------------------------------------------------------------------------
_DoSwap             macro     BitSize
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    call      StackSwap~1~
                    endm
;-------------------------------------------------------------------------------
_DoOperation        macro     Operation[,BitSize]
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    mdef      2,~1.{:1-1}~
                    @@Msg     ~1~
                    call      Stack~1~
          #ifspauto
                    #spadd    -~2~/8
          #endif
                    endm
;-------------------------------------------------------------------------------
_DoMath             macro     Operation,BitSize[,Operand1[,Operand2[,Answer]]]
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
          #ifnoparm ~3~
                    @_DoOperation ~1~
                    mexit
          #endif
          #ifnoparm ~4~
                    @@Load~2~ ~3~
              #ifnoparm ~1~ = Add~2~
              #ifnoparm ~1~ = Mul~2~
          ;except for Add and Mul which are commutative, we must swap the stack
                    call      StackSwap~2~        ;one parm is Operand2 (eg, Div32 XXX does TOS/XXX)
              #endif
              #endif
                    @_DoOperation ~1~
                    mexit
          #endif
                    @@Load~2~ ~4~
                    @@Load~2~ ~3~
                    @@_DoOperation ~1~
          #ifparm ~5~
                    @Save~2~  ~5~
          #endif
                    endm
;-------------------------------------------------------------------------------
_DoAbs              macro     BitSize[,Source][,Destination]
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    @@Msg     Abs~1~ ~@@~
                    @@_FindStkMth_ ~1~
                    mset      1,{:mexit}
          #ifparm ~2~
                    @@Load~1~ ~2~
          #endif
                    call      StackAbs~1~
          #ifparm ~2~~3~
                    @Save~1~  ~3~
          #endif
                    endm
;-------------------------------------------------------------------------------
_DoNeg              macro     BitSize[,Source][,Destination]
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    @@Msg     Neg~1~ ~@@~
                    @@_FindStkMth_ ~1~
                    mset      1,{:mexit}
          #ifparm ~2~
                    @@Load~1~ ~2~
          #endif
                    call      StackNegate~1~
          #ifparm ~2~~3~
                    @Save~1~  ~3~
          #endif
                    endm
;-------------------------------------------------------------------------------
_DoStr              macro     BitSize,[Variable],[ResultString]
          #if :macronest = 1
                    #Warning  Macro NOT to be called directly
          #endif
                    @@_FindStkMth_ ~1~
          #ifb ~2~
            #if ~1~ <> :mexit
                    #Warning  Size mismatch (Using Str~1~ for MATHSIZE={:mexit})
            #endif
          #endif
                    mset      1,{:mexit}
          #ifparm ~'~,3~'.{:3}~ = x
                    pshhx
          #endif
          #ifparm ~2~
                    @@Load~1~ ~2~
               #ifparm ~'~,3~'.{:3}~ = x
                    ldhx      ~1~/8+1,asp         ;reload user HX for next LDHX
               #endif
          #endif
          #ifnb ~2~
                    @@Msg     Convert \@~2~\@ ({::~2,~*8}-bit) to ASCIZ in \@~3~\@
          #endif
                    @@lea     ~3~
                    call      Stack~1~ToASCIZ
          #ifparm ~2~
                    ais       #~1~/8
          #endif
          #ifparm ~'~,3~'.{:3}~ = x
                    pulhx
          #endif
                    endm
