;*******************************************************************************
;* Include   : BLOCKS.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Structured block macros for ASM8 (Win32 & Linux versions, only)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2019 by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/blocks.html
;* Note(s)   : Use: #Include blocks.inc
;*******************************************************************************
; WORK-IN-PROGRESS: Tested to SOME extent but macros may still contain errors.
; Currently, only the following constructs are implemented:
; [Nested] FOR loop
; [Nested] IF statement
; [Nested] LOOP ... [BREAK] ... ENDLOOP
;*******************************************************************************

                    #Exit     _BLOCKS_
_BLOCKS_

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; FOR loop (w/ byte control variable)
; The index variable can be accessed using ,SP indexed mode and the symbol name
; created by enclosing the LoopName between underscores, eg. LoopA -> _LoopA_,sp
;*******************************************************************************

For.b               macro     UniqueForLoopName,[#]StartValue,[#]StopValue
                    mset      #' '
                    mreq      1,2,3:UniqueForLoopName,[#]StartValue,[#]StopValue
                    #push
                    #spauto   :sp
                    psha                          ;save user A
                    lda       ~2~
?For~1~.Loop        equ       *,1                 ;byte size
                    cmpa      ~3~
                    !jhi      ?For~1~.Exit
                    #pull
                    psha      _~1~_
                    lda       2,asp               ;reload user A
                    endm

;*******************************************************************************
; FOR loop (w/ word control variable)
; The index variable can be accessed using ,SP indexed mode and the symbol name
; created by enclosing the LoopName between underscores, eg. LoopA -> _LoopA_,sp
;*******************************************************************************

For.w               macro     UniqueForLoopName,[#]StartValue,[#]StopValue
                    mset      #' '
                    mreq      1,2,3:UniqueForLoopName,[#]StartValue,[#]StopValue
                    #push
                    #spauto   :sp
                    pshhx                         ;save user HX
                    ldhx      ~2~
?For~1~.Loop        equ       *,2                 ;word size
                    cphx      ~3~
                    !jhi      ?For~1~.Exit
                    #pull
                    pshhx     _~1~_
                    ldhx      3,asp               ;reload user HX
                    endm

;*******************************************************************************
; ENDFOR for either case (byte or word operand)
;*******************************************************************************

EndFor              macro     UniqueForLoopName
                    mreq      1:UniqueForLoopName
          #if ::?For~1~.Loop = 1
                    sta       2,asp               ;update possibly changed user A
                    pula
                    inca
          #endif
          #if ::?For~1~.Loop = 2
                    sthx      3,asp               ;update possibly changed user HX
                    pulhx
                    aix       #1
          #endif
                    !jmp      ?For~1~.Loop
?For~1~.Exit
          #if ::?For~1~.Loop = 1
                    pula                          ;restore updated user A
          #endif
          #if ::?For~1~.Loop = 2
                    pulhx                         ;restore updated user HX
          #endif
                    endm

;*******************************************************************************
; IF statement.  Usage: @IF Operand1,COMPARATOR,Operand2[,WORD] <code> @ENDIF
; COMPARATOR is one of EQ, NE, GT, GE, LT, LE, HI, HS, LO, LS (as in branches)
; If COMPARATOR is either PL or MI then only Operand1 is used; Operand2 ignored.
; Specify WORD for 4th parm to have a WORD-size comparison.  Default is BYTE.
; You can also use the IF.W macro to automatically add the WORD parameter, or
; the IF.B (alias for IF without the WORD parameter) for byte parameters.
;*******************************************************************************

IF.W                macro     Operand1,Comparator,Operand2
                    mset      #' '
                    mreq      1,2,3:Operand1,Comparator,Operand2
                    mset      4,WORD
                    @if       ~@~
                    endm

;-------------------------------------------------------------------------------

IF.B                macro     Operand1,Comparator,Operand2
                    mset      #' '
                    mreq      1,2,3:Operand1,Comparator,Operand2
                    mset      4
                    @if       ~@~
                    endm

;-------------------------------------------------------------------------------

IF                  macro     Operand1,Comparator,Operand2[,WORD]
                    mset      #' '
                    mreq      1,2,3:Operand1,Comparator,Operand2[,WORD]
?IF_                set       :index
?ENDIF_             set       ?IF_
                    #push
                    #spauto   :sp
    #ifparm ~4~ = WORD
                    pshhx
                    ldhx      ~1~
          #ifnoparm ~2~ = MI
          #ifnoparm ~2~ = PL
              #ifparm ~'~,3~'.{:3}~ = x
                    #psp
                    pshhx
                    ldhx      3,asp               ;;we must re-load X index
                    ldhx      ~3~
                    pshhx
                    ldhx      3,asp
                    cphx      1,asp
                    ais       #:psp
              #else
                    cphx      ~3~
              #endif
          #endif
          #endif
                    pulhx
    #else
                    psha
                    lda       ~1~
          #ifnoparm ~2~ = MI
          #ifnoparm ~2~ = PL
                    cmpa      ~3~
          #endif
          #endif
                    pula
    #endif
                    #pull
                    mset      1
                    mset      9,{?IF_}
                    mset      7,eqnegtgeltlehihslolsplmi    ;;2-char actions
                    mset      8,neeqleltgegtlslohshimipl    ;;their opposites
                    mdo
          #ifparm ~2~ = ~7.{:mloop-1*2+1}.2~
                    mset      1,!j~8.{:mloop-1*2+1}.2~
          #else
                    mloop     :7/2
          #endif
                    mreq      1:Unknown comparator \@~2~\@
                    ~1~       ?IF_~9~
                    endm

;-------------------------------------------------------------------------------
; ENDIF

ENDIF               macro
          #ifndef ?ENDIF_
                    merror    ~0~ must follow an IF
          #endif
                    mdo
          #ifz ?ENDIF_
                    merror    Unmatched ~0~
          #endif
                    mdef      9,?IF_{?ENDIF_}
          #ifdef ~9~
?ENDIF_             set       ?ENDIF_-1
                    mset      9,?IF_{?ENDIF_}
                    mloop
          #endif
~9~
?ENDIF_             set       ?ENDIF_-1
                    endm

;*******************************************************************************
; LOOP .. ENDLOOP statement.  Usage: @LOOP ... [@BREAK] ... @ENDLOOP
; @BREAK is optional in case we want to exit the loop.
;*******************************************************************************

LOOP                macro
?LOOP_              set       :index
?LOOP_{?LOOP_}
                    endm

;-------------------------------------------------------------------------------
; BREAK

BREAK               macro
                    mset      0,merror ~0~ must be inside a LOOP ... ENDLOOP
          #ifndef ?LOOP_{?LOOP_}
                    ~text~
          #endif
          #ifz ?LOOP_
                    ~text~
          #endif
                    !jmp      ?ENDLOOP_{?LOOP_}
                    endm

;-------------------------------------------------------------------------------
; ENDLOOP

ENDLOOP             macro
          #ifndef ?LOOP_
                    merror    ~0~ must follow a LOOP
          #endif
          #ifz ?LOOP_
                    merror    Unmatched ~0~
          #endif
          #ifndef ?LOOP_{?LOOP_}
?LOOP_              set       ?LOOP_-1
                    mtop
          #endif
                    !jmp      ?LOOP_{?LOOP_}
                    #Undef    ?LOOP_{?LOOP_}
?ENDLOOP_{?LOOP_}
?LOOP_              set       ?LOOP_-1
                    endm

;*******************************************************************************
                    #Exit
;*******************************************************************************
;                   Test various macro expansions
;*******************************************************************************

CmdBlock            macro
                    txa
                    sta       ,x                  ;;just to see it execute
                    aix       #1
                    endm

                    #RAM

min                 rmb       2
max                 rmb       2

buffer              rmb       50

                    #ROM

                    #spauto

Start               proc
                    @rsp
                    clra                          ;(keeps simulator happy)

                    ldhx      #buffer

                    @mov.w    #1,min
                    @mov.w    #5,max
          ;-------------------------------------- ;FOR loop using variable bounds
Test1               @For.w    LoopA min max
                    @CmdBlock                     ;any instructions (not necessarily in a macro)

                    ldhx      _LoopA_,sp          ;HX = LoopA loop index

                    @EndFor   LoopA
          ;-------------------------------------- ;FOR loop using constant bounds
Test2               @For.b    LoopB #3 #5
                    @CmdBlock                     ;any instructions (not necessarily in a macro)
                    @CmdBlock                     ;any instructions (not necessarily in a macro)
                    @EndFor   LoopB
          ;-------------------------------------- ;nested FOR loops using both variable and constant bounds
Test3               clra                          ;zero our counter to see how many times inside loops
                    ldhx      #12

                    @For.w    Outer min #3
                    @For.w    Inner #4 max
                    @For.b    Loop #2 #3

          ;as you can see, user registers are not affected by the FOR loop

                    inca                          ;each time thru the loop, we
                    aix       #-1                 ;increment A and decrement HX

                    @EndFor   Loop
                    @EndFor   Inner
                    @EndFor   Outer

Done                cmpa      #12                 ;expected RegA value
                    jne       Error

                    cphx      #0                  ;expected RegHX value
                    jne       Error

          ;---------------------------------------------------------------------
          ; Test the IF/ENDIF macro expansions
          ;---------------------------------------------------------------------

TestIF              @if.w     min eq max          ;Simple  IF (with word comparison)
                    nop
                    @endif
          ;--------------------------------------
                    @if       #4 ne max           ;Nested IF
                    nop
                    @if       max gt min          ;-+
                    nop                           ; |
                    @endif                        ;-+
                    nop
                    @endif
          ;--------------------------------------
                    @if       #1 eq #1            ;Separate nested IFs
                    nop
                    @if       min eq #3           ;-+
                    nop                           ; |
                    @endif                        ;-+
                    nop
                    @if       #3 lt #4            ;-+
                    nop                           ; |
                    @endif                        ;-+
                    nop
                    @endif
          ;--------------------------------------
                    ldhx      #max                ;3rd parm is X indexed
                    @if.w     min eq ,x
                    nop
                    @endif

          ;---------------------------------------------------------------------
          ; Test the LOOP/BREAK/ENDLOOP macro expansions
          ;---------------------------------------------------------------------

                    lda       #3
                    psha      count@@

TestLoop            @loop
                    nop

                    @if       count@@,sp lt #1
                    @break
                    @endif

                    dec       count@@,sp

                    nop
                    @endloop

                    pula
          ;--------------------------------------
                    lda       #3
                    psha      OuterCounter

TestNestedLoop      @loop
                    nop

                    lda       #1
                    psha      count@@

                    @loop

                    @if       count@@,sp eq #255
                    @break
                    @endif

                    dec       count@@,sp

                    @endloop

                    pula

                    dec       OuterCounter,sp

                    @if       OuterCounter,sp eq #0
                    @break
                    @endif

                    nop
                    @endloop

                    pula
          ;--------------------------------------
          #ifdef
                    @loop
                    @loop
                    @endloop
                    @loop
                    @endloop
                    @endloop
          #endif
          ;--------------------------------------
;                   @break                        ;causes error (outside LOOP)
;                   @endloop                      ;causes error (unmatched)
          ;--------------------------------------
                    bra       *
Error               bra       *

                    @vector   Vreset,Start
