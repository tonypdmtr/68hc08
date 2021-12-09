;*******************************************************************************
;* Include   : MACROS.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Sample macro definitions for ASM8 (Win32 & Linux versions, only)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/macros.html
;* Note(s)   : Use: #Include macros.inc
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
;*           : Some macros may call themselves with extra parameters so that
;*           : they may control the loop without having the user provide those
;*           : control values.
;* History   : 10.07.26 v1.00 First (non-beta) release
;*           : 10.07.29 v1.01 Added #SPADD in PushV macro for #SPAUTO mode
;*           : 10.07.31 v1.02 Removed now redundant push-related macros with
;*           :                optional label as the latest version of ASM8 has
;*           :                this capability built-in (when in -X mode).
;*           : 10.08.01 v1.03 PIN macro now allows for pin-name in label column
;*           : 10.08.06 v1.04 ADD.B third parm made optional
;*           : 10.08.08 v1.05 Added #SPAUTO in Pull macro (for ,SP parms)
;*           : 10.08.09 v1.06 Added AND.B/W/L, ORA.B/W/L and EOR.B/W/L macros
;*           : 10.08.12 v1.07 LDH & STH now see index even w/o comma override
;*           : 10.08.17 v1.08 Fixed Pull macro to work with ,SP variable case
;*           : 10.08.19 v1.09 Optimized CMP.W for HCS and added #PUSH/SPAUTO/PULL
;*           : 10.08.20 v1.10 Log2 now uses :loop (latest ASM8)
;*           : 10.08.21 v1.11 Added PROC, ENDPROC, and ClrRange macros
;*           : 10.08.29 v1.12 CMP.W now works with ,X indexed 2nd operand (HCS)
;*           : 10.08.31 v1.13 Added sema macro for OS8 semaphore definition
;*           : 10.09.01 v1.14 Improved LDH by loading full HX while protecting X
;*           : 10.09.04 v1.15 Adapted to latest ASM8 enhancements
;*           : 10.09.06 v1.16 Improved LDXA & STXA (no parm override needed)
;*           : 10.09.10 v1.17 Added IncByHX and DecByHX macros
;*           : 10.09.16 v1.18 Macro _PUSH_ moved to COMMON.INC
;*           : 10.09.19 v1.19 Improved PushV and PullV
;*           : 10.09.22 v1.20 Made use of MTOP found in latest ASM8
;*           :                Improved DefBaud to display baud defs in any order
;*           : 10.09.23 v1.21 Improved FillROM macro
;*           : 10.09.24 v1.22 Replaced double-@ string delimiter with \@
;*           : 10.09.25 v1.23 Improved Align2 macro to not use ?$$$
;*           : 10.10.20 v1.24 Adapted to latest ASM8 (eg., use of MSET)
;*           : 10.10.25 v1.25 Made use of MSWAP (latest ASM8 build)
;*           : 10.10.30 v1.26 Single operand macros use index w/o override
;*           : 10.11.01 v1.27 RePin macro defined (AND UNDEFINED IN v1.28)
;*           : 10.11.03 v1.28 Pin macro redefines if label appears on right side
;*           : 10.11.05 v1.29 Replaced :loop with MSWAP in DefBaud, sema macros
;*           : 10.11.08 v1.30 Added 'X-index not allowed' error in DIVs
;*           : 10.11.09 v1.31 Macro DEFAULT removed. Use built-in DEF instead.
;*           :                FillROM moved to MACROS2.INC
;*           : 10.11.19 v1.32 Renamed Align2 to Align, and allowed for label
;*           : 10.11.20 v1.33 Add optional shift left parameter to Log2
;*           : 10.11.25 v1.34 Input, Output, On, Off now accept multiple PinNames
;*           : 10.11.26 v1.35 Added ABS (abs.b, abs.w, abs.l) for absolute value
;*           : 10.11.28 v1.36 Align macro improved to also align label values
;*           : 10.12.01 v1.37 Adapted to latest ASM8 => shorter/faster macros
;*           : 10.12.03 v1.38 Adapted to latest ASM8 => macros OK in @@ sub-mode
;*           : 10.12.28 v1.39 Added ReadPin to set the CCR[C] based on pin status
;*           : 11.02.03 v1.40 Improved fNextTask to behave similarly if no MTOS
;*           : 11.02.06 v1.41 ReadPin improved to accept regular BRSET syntax
;*           : 11.02.11 v1.42 Renamed Align back to Align2 (because power of 2)
;*           :                Added Align to align based on multiple (not power)
;*           : 11.02.28 v1.43 Added #SPADD in ReVector (in case it is under SPAUTO)
;*           : 11.03.04 v1.44 Added TST.B TST.W and TST.L macros
;*           :                Log2 macro now also returns answer in :MEXIT
;*           : 11.03.16 v1.45 Made use of #EXIT directive to speedup assembly
;*           : 11.03.20 v1.46 Optimized Pull and fixed for SPAUTO mode use
;*           : 11.03.27 v1.47 Improved RSP/LDS allows for index without override
;*           : 11.03.31 v1.48 Improved DefADKey to also accept ~label~ format
;*           : 11.04.20 v1.49 Changed ,X to ,AX in some macros (in case we use #X)
;*           : 11.04.26 v1.50 Added CopyRange macro
;*           : 11.08.17 v1.51 Added Pullup macro to set pull-up for given PIN(s)
;*           : 11.08.30 v1.52 Improved ClrRange for empty immediate range
;*           : 11.09.06 v1.53 Added XA2HX and HX2XA
;*           : 11.10.17 v1.54 Allowed multiple parameters for CheckPin
;*           : 11.10.26 v1.55 Added REP (repeat) macro
;*           : 11.11.11 v1.56 PIN macro now gives warning if pin number over 7
;*           : 11.11.24 v1.57 Updated PULLUP macro to use BSET when possible
;*           : 11.12.01 v1.58 Corrected PULLUP macro for BSET case
;*           : 12.03.17 v1.59 Shortened DIV.W and DIV.L by use of DIV.B
;*           :                AIS & AIX no longer allow non-immediate operand
;*           :                Macro ALIGN commented out, use built-in ALIGN
;*           : 12.06.13 v1.60 Improved PIN macro for sequential auto-assignment
;*           : 12.06.25 v1.61 Improved DefBaud macro to not redefine for same values
;*           : 12.08.06 v1.62 Added EndStats macro (for showing final statistics)
;*           : 12.09.28 v1.63 DIV.B improved to allow X-index mode for divisor
;*           : 12.10.22 v1.64 BugFix: cmp.w and ClrRange macros X-index mode detection
;*           : 12.11.19 v1.65 Improved EndStats macro, and better support for MMU mode
;*           : 12.12.05 v1.66 Added CAX & CXA (Cmp A to X and vice-versa) macros
;*           :                REP macro improved to also allow macro(s) as parameter
;*           : 13.01.21 v1.67 Added ADC.B and SBC.B macros. Changed certain .L
;*           :                macros to use .W, and .W to use .B internally
;*           : 13.02.03 v1.68 Improved PIN macro
;*           : 13.02.11 v2.00 Made use ~[n.p]~ macro placeholder. May produce
;*           :                different object code.
;*           :                Made ADD.B and ADC.B smarter for #0 parm cases
;*           :                Added ADC.W, ADC.L, SBC.W and SBC.L macros
;*           :                Several macros improved.
;*           : W A R N I N G  Because of the new ~[n.p]~ capability the six
;*           : W A R N I N G  macros SUB.[BWL] and CMP.[BWL] now 'subtract' 2nd
;*           : W A R N I N G  from 1st for immediate mode operand(s).  These
;*           : W A R N I N G  macros now also work with X-indexed mode in all
;*           : W A R N I N G  cases.  IMPORTANT: Source code in apps that use
;*           : W A R N I N G  any of these macros may need revision to correct
;*           : W A R N I N G  the 1st/2nd parameter order when immediate mode is
;*           : W A R N I N G  involved.
;*           : 13.03.03 v2.01 Added calls to _#_ and _not_#_ in some macros
;*           :                Improved ReVector, tst.w, and tst.l macros
;*           :                Moved some frequently used macros to COMMON.INC
;*           :                ClrRange no longer destroys registers
;*           : 13.03.13 v2.02 Added _FindStr_ macro (Find String)
;*           : 13.04.05 v2.03 Optimized PushV macro
;*           : 13.04.12 v2.04 PushV / PullV macros moved to COMMON.INC
;*           : 13.04.23 v2.05 BugFix: _ldacmp_ macro (in COMMON.INC) now compares
;*           :                even with #0 to adjust the Carry like the real CMP
;*           :                instruction.  This corrects all CMP.x macros in here.
;*           : 13.05.07 v2.06 BugFix: EndStats macro for MMU case
;*           : 13.05.07 v2.07 ADD.B and ADC.B moved to COMMON.INC as they are
;*           :                also used by ADD.S
;*           : 13.05.14 v2.08 Added PORT macro for single line port bit(s) definition
;*           :                (eg., FSTAT @port $1825,,,FBLANK,,FACCERR,FPVIOL,FCCF,FCBEF)
;*           : 13.08.08 v2.09 CopyRange now shows error if size is not word
;*           : 13.08.13 v2.10 Improved CopyRange to accept either byte or word size
;*           : 13.09.29 v2.11 Improved EndStats macro to use ?_OBJECT_? by default
;*           : 13.10.12 v2.12 Renamed "copy" macro to "copy.b"
;*           : 13.10.24 v2.13 Rewrote AddOS to use #ROM (moved to COMMON.INC)
;*           : 13.11.01 v2.14 Moved (improved version of) AIX into COMMON.INC
;*           : 13.11.07 v2.15 Improved Pullup macro
;*           : 14.10.11 v2.16 Added MarkModuleVars & ClrModuleVars macros
;*           : 15.04.03 v2.17 Added sema #SAVE# option to create Lock/Unlock code
;*           : 15.05.15 v2.18 Adapted to latest sema lock/unlock parameter passing scheme
;*           :                Added fLock, fLockAttempt, fUnlock, fUnlockOnly
;*           :                global macros to deal with compatibility issues
;*           :                between old and new semaphore schemes
;*           : 15.05.27 v2.19 Removed deprecated fUnlockOnly macro
;*           : 15.09.17 v2.20 Added is8bit & is16bit helper macros
;*           :                Incorporated is8bit into mov.b & is16bit into mov.w
;*           : 17.10.01 v2.21 Moved PROC and ENDPROC macros into their own file (proc.inc)
;*           : 17.10.13 v2.22 MarkModuleVars adds #push-#pull to protect user segment use
;*           : 19.04.13 v2.23 Pullup macro forces BSET to avoid macro invocation
;*           : 19.04.25 v2.24 EndStats macro now always shows 'Module size'
;*           : 19.11.26 v2.25 EndStats macro now adds ?HANDLER_CYCLES display
;*           : 20.02.12 v2.26 Added Msg macro to silence debugging messages
;*           :                unless SHOW_ALL_MESSAGES is defined
;*           : 20.06.04 v2.27 Simplified ReadPin macro
;*           : 20.06.17 v2.28 Removed cbeq macro and rewrote cbne to use only cbeq
;*           : 20.07.15 v2.29 Added CopyPin macro to copy pin state to another pin
;*           : 21.02.11 v2.30 No longer calls @MyDefaultDirectives at inclusion
;*           : 21.04.09 v2.31 Show hint when sema is already defined
;*           : 21.06.29 v2.32 Improved CopyPin macro to use CCR[C] if FromPin is missing
;*           : 21.10.01 v2.33 Improved Input and Output macros to ignore non-register pins
;*           : 21.10.06 v2.34 Removed practically useless _FindStr_ macro (Find String)
;*           : 21.10.25 v2.35 Added DEPRECATED hint in ExpPin and PIN macros
;*           : 21.11.01 v2.36 COP macro will do nothing if NO_COP is defined
;*           : 21.11.26 v2.37 Prepend `sema` if missing in fLock[Attempt]/fUnlock
;*           : 21.12.01 v2.38 Simplified yet improved LCDFCS macro definition
;*           : 21.12.08 v2.39 BugFix: Off-by-one error in LCDFCS simplification
;*******************************************************************************

                    #Exit     _MACROS_
_MACROS_
          #if :version < 1200
                    #Warning  Some macros are incompatible with ASM8 v{:version(2)} (please update to ASM8 v12 or later)
          #endif
;*******************************************************************************
; My personal preferences for most situations (adjust to suit your needs)

MyDefaultDirectives macro
                    #CaseOn                       ;Case-sensitive labels
                    #OptRelOn                     ;Jump->Branch warnings
                    #OptRtsOff                    ;No redundant RTS warnings
                    #SpacesOff                    ;No non-string spaces in operands
                    #ExtraOn                      ;Extra mnemonics enabled
                    #MapOn                        ;Source-level mapping enabled
                    #TraceOff                     ;No source-level macro mapping
                    #HcsOn                        ;Enable HCS08 instructions
                    #S1                           ;S1/S2 auto-selection
                    #Jump                         ;Auto CALL->JSR & RTC->RTS conversion
                    #@Macro                       ;Macro syntax is @macro
                    #Parms                        ;Default macro parameter delimiter
                    endm

;*******************************************************************************
;*******************************************************************************
                   ;@MyDefaultDirectives          ;this one called at inclusion
;*******************************************************************************
;*******************************************************************************

COP                 macro                         ;kick the COP watchdog
          #ifparm ~1~ = #SAVE#                    ;to be compatible with special COP macro versions
                    mexit
          #endif
          #ifdef COP&&!NO_COP
                    sta       COP
          #endif
                    endm

;*******************************************************************************

Msg                 macro
          #ifndef SHOW_ALL_MESSAGES               ;;define this to show messages
                    mexit
          #endif
                    mset      #
                    #Message  ~1~
                    endm

;*******************************************************************************
; Test if any immediate value in list is greater than 8-bit

is8bit              macro
                    mreq      1
                    mswap     1,:loop
          #ifnb ~#~
            #if ~#1~&$FFFFFF00 > 0
                    #Warning  Value {:loop} ({~#1~}) is bigger than 8-bit
            #endif
          #endif
                    mtop      :n
                    endm

;*******************************************************************************
; Test if any immediate value in list is greater than 16-bit

is16bit             macro
                    mreq      1
                    mswap     1,:loop
          #ifnb ~#~
            #if ~#1~&$FFFF0000 > 0
                    #Warning  Value {:loop} ({~#1~}) is bigger than 16-bit
            #endif
          #endif
                    mtop      :n
                    endm

;*******************************************************************************
; Simulate 68HC11's LDS instruction (HX is destroyed, however)

lds                 macro     [#]StackTop
                    ldhx      ~@~
                    txs
                    endm

;*******************************************************************************

rsp                 macro     [[#]StackTop]       ;does LDS with most-used value
                    mdef      1,#STACKTOP
                    @lds      ~@~
                    endm

;*******************************************************************************
; Mark the beginning and end of variables for either RAM or XRAM

MarkModuleVars      macro
                    #push
?RAM_BEGIN          equ       :RAM
?XRAM_BEGIN         equ       :XRAM

                    msuspend                      ;;here, code adds variables

?RAM_END            equ       :RAM
?XRAM_END           equ       :XRAM
                    #pull
                    endm

;*******************************************************************************
; Clear variables marked by the MarkModuleVars macro

ClrModuleVars       macro
                    @@ClrRange #?RAM_BEGIN,#?RAM_END
                    @ClrRange #?XRAM_BEGIN,#?XRAM_END
                    endm

;*******************************************************************************
; Clear a range to zero (or given value)

ClrRange            macro     [#]FromAddressPtr,[#]ToAddressPtr[,[#]WithValue]
                    mreq      1,2:[#]FromAddressPtr,[#]ToAddressPtr[,[#]WithValue]
                    mdef      3,#0                ;;default value is zero
                    @@_not_x_ ~2~
          #ifparm ~#~
            #ifnoparm ~#2~ = ~2~
              #if ~#1~ = ~#2~
                    mexit                         ;;nothing to do
              #endif
            #endif
          #endif
                    #push
                    #spauto   :sp
                    push
                    @@_lda_   ~3~
                    ldhx      ~1~
Loop$$$
                    sta       ,ax
                    aix       #1
                    cphx      ~2~
                    blo       Loop$$$
                    pull
                    #pull
                    endm

;*******************************************************************************
; Copy a range of bytes between fixed addresses - no registers destroyed

CopyRange           macro     #Source,#Destination,[#]Size
                    mreq      1,2,3:#Source,#Destination,[#]Size
          #ifparm ~,1~~,2~
                    merror    Source/Destination is indexed
          #endif
                    @@_#_     ~1~ ~2~
                    @@_not_x_ ~3~
                    mset      0,cphx              ;;default comparison is word
          #ifnb ~3~ = ~#3~                        ;except for immediate mode
            #if ::~3,~ <> 2                       ;if size is not word
              #if ::~3,~ <> 1                     ;and byte is not byte
                    merror    Non-byte or non-word size (~3~)
              #endif
            #endif
            #if ::~3,~ = 1
                    mset      0,cmpx
            #endif
          #endif
                    #push
                    #spauto   :sp
                    push
                    clrhx                         ;;HX to be used as counter
Loop$$$             lda       ~#1~,ax             ;;copy source byte
                    sta       ~#2~,ax             ;;to destination byte
                    aix       #1                  ;;advance index
                    ~text~    ~3~                 ;;are we done?
                    blo       Loop$$$             ;;repeat while not done
                    pull
                    #pull
                    endm

;*******************************************************************************
; LDXA (Load XA) in one step

ldxa                macro     [#]Operand
                    mset      #
                    lda       ~[1.-2]~
                    ldx       ~[1.-1]~
                    endm

;*******************************************************************************
; STXA (Store XA) in one step

stxa                macro     Address
                    mset      #
                    stx       ~1~
                    sta       ~1,~+1~,1~
                    endm

;*******************************************************************************
; CAX - Compare A to X

cax                 macro
                    pshx
                    cmpa      1,asp
                    pulx
                    endm

;*******************************************************************************
; CXA - Compare X to A

cxa                 macro
                    psha
                    cmpx      1,asp
                    pula
                    endm

;*******************************************************************************
; LDH (Load H register)

ldh                 macro     [#]Operand
          #ifparm ~#~
                    pshx
                    ldhx      ~1~<8
                    pulx
                    mexit
          #endif
                    #push
                    #spauto   :sp
          #ifhcs
                    pshx
                    ldhx      ~@~
                    pulx
          #else
                    psha
                    lda       ~@~
                    tah
                    pula
          #endif
                    #pull
                    endm

;*******************************************************************************
; STH (Store H register)

sth                 macro     Operand
                    #push
                    #spauto   :sp
                    psha
                    tha
                    sta       ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Copy XA to HX

XA2HX               macro
                    txh
                    tax
                    endm

;*******************************************************************************
; Copy HX to XA

HX2XA               macro
                    txa
                    thx
                    endm

;*******************************************************************************
; Swap the values of two symbols (using old XOR technique, and no temp symbol)

SwapSymbols         macro     Symbol1,Symbol2
~1~                 set       {~1~}^{~2~}
~2~                 set       {~1~}^{~2~}
~1~                 set       {~1~}^{~2~}
                    endm

;*******************************************************************************
; Swap two byte-size variables (does not destroy any registers)

swap.b              macro     Variable1 Variable2
                    mset      #' '
                    mreq      1,2:Variable1 Variable2
                    #push
                    #spauto   :sp
                    psha
                    @@_swap_  ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Swap two word-size variables (does not destroy any registers)

swap.w              macro     Variable1 Variable2
                    mset      #' '
                    mreq      1,2:Variable1 Variable2
                    #push
                    #spauto   :sp
                    psha
                    @@_swap_  ~[1.-1]~ ~[2.-1]~
                    @@_swap_  ~[1.-2]~ ~[2.-2]~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Swap two long variables (does not destroy any registers)

swap.l              macro     Variable1 Variable2
                    mset      #' '
                    mreq      1,2:Variable1 Variable2
                    #push
                    #spauto   :sp
                    psha
                    @@_swap_  ~[1.1]~ ~[2.1]~
                    @@_swap_  ~[1.2]~ ~[2.2]~
                    @@_swap_  ~[1.3]~ ~[2.3]~
                    @@_swap_  ~[1.4]~ ~[2.4]~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Align the current segment (e.g, #ROM) to specific power-of-two block size.
; If a label is present on the same line as the macro call, set the label to the
; value after the alignment occurs.  Default power is 0, byte alignment.
; If the "UnalignedValue" expression is present (and its value is other than
; :PC, then instead of aligning the current segment, it only sets the label to
; aligned value.  This way, it can be used to align just a label without the
; segment.

Align2              macro     Power[,UnalignedValue]
                    mdef      1,0
                    mdef      2,:PC
                    mset      1,{1<{~1~}+{~2~}-1(h)}&{1<{~1~}-1^$FFFFFF(h)}
          #ifparm ~2~ = :PC
                    org       ~1~
          #endif
          #ifparm ~label~
~label~             set       ~1~
          #endif
                    mexit     ~1~
                    endm

;*******************************************************************************
; CLR for bytes (differs from built-in CLR in that it works for any address)

clr.b               macro     Variable
          #ifparm ~,1~~2~
                    clr       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    clr       ~@~
                    mexit
          #endif
                    psha
                    clra
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; CLR for words

clr.w               macro     Variable
          #ifparm ~,1~~2~
                    clr       ~@~
                    clr       ~1,~+1~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    clr       ~@~
                    clr       ~1~+1
                    mexit
          #endif
                    psha
                    clra
                    sta       ~@~
                    sta       ~1~+1
                    pula
                    endm

;*******************************************************************************
; CLR for longs

clr.l               macro     Variable
          #ifparm ~,1~~2~
                    clr       ~@~
                    clr       ~1,~+1~,1~,~2~
                    clr       ~1,~+2~,1~,~2~
                    clr       ~1,~+3~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    clr       ~1~
                    clr       ~1~+1
                    clr       ~1~+2
                    clr       ~1~+3
                    mexit
          #endif
          #ifhcs
                    pshhx
                    clrhx
                    sthx      ~1~
                    sthx      ~1~+2
                    pulhx
                    mexit
          #endif
                    psha
                    clra
                    sta       ~1~
                    sta       ~1~+1
                    sta       ~1~+2
                    sta       ~1~+3
                    pula
                    endm

;*******************************************************************************
; INC for bytes (differs from built-in INC in that it works for any address)

inc.b               macro     Variable
          #ifparm ~,1~~2~
                    inc       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    inc       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    inca
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; INC for words

inc.w               macro     Variable
          #ifparm ~,1~~2~
                    inc       ~1,~+1~,1~,~2~
                    bne       Done$$$
                    inc       ~@~
Done$$$
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    inc       ~1~+1
                    bne       Done$$$
                    inc       ~1~
Done$$$
                    mexit
          #endif
          #ifhcs
                    pshhx
                    ldhx      ~1~
                    aix       #1
                    sthx      ~1~
                    pulhx
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    inc       1,ax
                    bne       Done$$$
                    inc       ,ax
Done$$$
                    pulhx
                    endm

;*******************************************************************************
; INC for longs

inc.l               macro     Variable
          #ifparm ~,1~~2~
                    inc       ~1,~+3~,1~,~2~
                    bne       Done$$$
                    inc       ~1,~+2~,1~,~2~
                    bne       Done$$$
                    inc       ~1,~+1~,1~,~2~
                    bne       Done$$$
                    inc       ~@~
Done$$$
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    inc       ~1~+3
                    bne       Done$$$
                    inc       ~1~+2
                    bne       Done$$$
                    inc       ~1~+1
                    bne       Done$$$
                    inc       ~1~
Done$$$
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    inc       3,ax
                    bne       Done$$$
                    inc       2,ax
                    bne       Done$$$
                    inc       1,ax
                    bne       Done$$$
                    inc       ,ax
Done$$$
                    pulhx
                    endm

;*******************************************************************************
; (In/De)crement word using HX without protecting its original value (quicker)
; User is responsible for saving/restoring HX as needed by application

IncByHX             macro     Variable
                    mset      #
          #ifnhcs
                    mstop     Macro works with 9S08 only
          #endif
                    @@_not_x_ ~1~
                    @@_size_, ~1~ 2
                    ldhx      ~1~
                    aix       #1
                    sthx      ~1~
                    endm

;-------------------------------------------------------------------------------

DecByHX             macro     Variable
                    mset      #
          #ifnhcs
                    mstop     Macro works with 9S08 only
          #endif
                    @@_not_x_ ~1~
                    @@_size_, ~1~ 2
                    ldhx      ~1~
                    aix       #-1
                    sthx      ~1~
                    endm

;*******************************************************************************
; COM for bytes (differs from built-in COM in that it works for any address)

com.b               macro     Variable
          #ifparm ~,1~~2~
                    com       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    com       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    coma
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; COM for words

com.w               macro     Variable
          #ifparm ~,1~~2~
                    com       ~@~
                    com       ~1,~+1~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    com       ~1~
                    com       ~1~+1
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    com       ,ax
                    com       1,ax
                    pulhx
                    endm

;*******************************************************************************
; COM for longs

com.l               macro     Variable
          #ifparm ~,1~~2~
                    com       ~@~
                    com       ~1,~+1~,1~,~2~
                    com       ~1,~+2~,1~,~2~
                    com       ~1,~+3~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    com       ~1~
                    com       ~1~+1
                    com       ~1~+2
                    com       ~1~+3
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    com       ,ax
                    com       1,ax
                    com       2,ax
                    com       3,ax
                    pulhx
                    endm

;*******************************************************************************
; NEG for bytes (differs from built-in NEG in that it works for any address)

neg.b               macro     Variable
          #ifparm ~,1~~2~
                    neg       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    neg       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    nega
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; NEG for words

neg.w               macro     Variable
          #ifparm ~,1~~2~
                    com       ~@~
                    neg       ~1,~+1~,1~,~2~
                    bne       Done$$$
                    inc       ~@~
Done$$$
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    com       ~1~
                    neg       ~1~+1
                    bne       Done$$$
                    inc       ~1~
Done$$$
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    com       ,ax
                    neg       1,ax
                    bne       Done$$$
                    inc       ,ax
Done$$$
                    pulhx
                    endm

;*******************************************************************************
; NEG for longs

neg.l               macro     Variable
          #ifparm ~,1~~2~
                    com       ~@~
                    com       ~1,~+1~,1~,~2~
                    com       ~1,~+2~,1~,~2~
                    neg       ~1,~+3~,1~,~2~
                    bne       Done$$$
                    inc       ~1,~+2~,1~,~2~
                    bne       Done$$$
                    inc       ~1,~+1~,1~,~2~
                    bne       Done$$$
                    inc       ~@~
Done$$$
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    com       ~1~
                    com       ~1~+1
                    com       ~1~+2
                    neg       ~1~+3
                    bne       Done$$$
                    inc       ~1~+2
                    bne       Done$$$
                    inc       ~1~+1
                    bne       Done$$$
                    inc       ~1~
Done$$$
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    com       ,ax
                    com       1,ax
                    com       2,ax
                    neg       3,ax
                    bne       Done$$$
                    inc       2,ax
                    bne       Done$$$
                    inc       1,ax
                    bne       Done$$$
                    inc       ,ax
Done$$$
                    pulhx
                    endm

;*******************************************************************************
; (ABS) Make operand positive

abs.b               macro     ByteVariable
                    mreq      1:ByteVariable
                    @@tst.b   ~@~
                    bpl       Done$$$
                    @@neg.b   ~@~
Done$$$
                    endm

;-------------------------------------------------------------------------------

abs.w               macro     WordVariable
                    mreq      1:WordVariable
                    @@tst.b   ~@~
                    bpl       Done$$$
                    @@neg.w   ~@~
Done$$$
                    endm

;-------------------------------------------------------------------------------

abs.l               macro     LongVariable
                    mreq      1:LongVariable
                    @@tst.b   ~@~
                    bpl       Done$$$
                    @@neg.l   ~@~
Done$$$
                    endm

;*******************************************************************************
; MOV for bytes (differs from built-in MOV in that it works for any address)
;               (uses COPY if MOV not possible)

mov.b               macro     [#]Source,Destination
                    @@is8bit  ~1~
    #ifparm ~#~
          #ifz ~2~&$FFFFFF00
                    mov       ~@~
                    mexit
          #endif
                    @Copy.b   ~@~
                    mexit
    #endif
          #ifz ~1~&$FFFFFF00
              #ifz ~2~&$FFFFFF00
                    mov       ~@~
                    mexit
              #endif
          #endif
                    @Copy.b   ~@~
                    endm

;*******************************************************************************
; MOV for words (uses COPY if MOV not possible)
; MSB moved last to correctly adjust the N flag.

mov.w               macro     [#]Source,Destination
                    @@is16bit ~1~
          #ifnz ~2~&$FFFFFF00
                    @Copy.w   ~@~
                    mexit
          #endif
          #ifb ~#~
              #ifnz ~1~&$FFFFFF00
                    @Copy.w   ~@~
                    mexit
              #endif
          #endif
                    mov       ~[1.-2]~,~[2.-2]~
                    mov       ~[1.-1]~,~[2.-1]~
                    endm

;*******************************************************************************
; MOV for longs (uses COPY if MOV not possible)
; MSB moved last to correctly adjust the N flag.

mov.l               macro     [#]Source,Destination
          #ifnz ~2~&$FFFFFF00
                    @Copy.l   ~@~
                    mexit
          #endif
          #ifb ~#~
              #ifnz ~1~&$FFFFFF00
                    @Copy.l   ~@~
                    mexit
              #endif
          #endif
                    mov       ~[1.4]~,~[2.4]~
                    mov       ~[1.3]~,~[2.3]~
                    mov       ~[1.2]~,~[2.2]~
                    mov       ~[1.1]~,~[2.1]~
                    endm

;*******************************************************************************
; LSL for bytes (differs from built-in LSL in that it works for any address)

lsl.b               macro     Variable
          #ifparm ~,1~~2~
                    lsl       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    lsl       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    lsla
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; LSL for words

lsl.w               macro     Variable
          #ifparm ~,1~~2~
                    lsl       ~1,~+1~,1~,~2~
                    rol       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    lsl       ~1~+1
                    rol       ~1~
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    lsl       1,ax
                    rol       ,ax
                    pulhx
                    endm

;*******************************************************************************
; LSL for longs

lsl.l               macro     Variable
          #ifparm ~,1~~2~
                    lsl       ~1,~+3~,1~,~2~
                    rol       ~1,~+2~,1~,~2~
                    rol       ~1,~+1~,1~,~2~
                    rol       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    lsl       ~1~+3
                    rol       ~1~+2
                    rol       ~1~+1
                    rol       ~1~
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    lsl       3,ax
                    rol       2,ax
                    rol       1,ax
                    rol       ,ax
                    pulhx
                    endm

;*******************************************************************************
; LSR for bytes (differs from built-in LSR in that it works for any address)

lsr.b               macro     Variable
          #ifparm ~,1~~2~
                    lsr       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    lsr       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    lsra
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; LSR for words

lsr.w               macro     Variable
          #ifparm ~,1~~2~
                    lsr       ~@~
                    ror       ~1,~+1~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    lsr       ~1~
                    ror       ~1~+1
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    lsr       ,ax
                    ror       1,ax
                    pulhx
                    endm

;*******************************************************************************
; LSR for longs

lsr.l               macro     Variable
          #ifparm ~,1~~2~
                    lsr       ~@~
                    ror       ~1,~+1~,1~,~2~
                    ror       ~1,~+2~,1~,~2~
                    ror       ~1,~+3~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    lsr       ~1~
                    ror       ~1~+1
                    ror       ~1~+2
                    ror       ~1~+3
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    lsr       ,ax
                    ror       1,ax
                    ror       2,ax
                    ror       3,ax
                    pulhx
                    endm

;*******************************************************************************
; ASR for bytes (differs from built-in ASR in that it works for any address)

asr.b               macro     Variable
          #ifparm ~,1~~2~
                    asr       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    asr       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    asra
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; ASR for words

asr.w               macro     Variable
          #ifparm ~,1~~2~
                    asr       ~@~
                    ror       ~1,~+1~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    asr       ~1~
                    ror       ~1~+1
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    asr       ,ax
                    ror       1,ax
                    pulhx
                    endm

;*******************************************************************************
; ASR for longs

asr.l               macro     Variable
          #ifparm ~,1~~2~
                    asr       ~@~
                    ror       ~1,~+1~,1~,~2~
                    ror       ~1,~+2~,1~,~2~
                    ror       ~1,~+3~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    asr       ~1~
                    ror       ~1~+1
                    ror       ~1~+2
                    ror       ~1~+3
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    asr       ,ax
                    ror       1,ax
                    ror       2,ax
                    ror       3,ax
                    pulhx
                    endm

;*******************************************************************************
; ROR for bytes (differs from built-in ROR in that it works for any address)

ror.b               macro     Variable
          #ifparm ~,1~~2~
                    ror       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    ror       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    rora
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; ROR for words

ror.w               macro     Variable
          #ifparm ~,1~~2~
                    ror       ~@~
                    ror       ~1,~+1~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    ror       ~1~
                    ror       ~1~+1
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    ror       ,ax
                    ror       1,ax
                    pulhx
                    endm

;*******************************************************************************
; ROR for longs

ror.l               macro     Variable
          #ifparm ~,1~~2~
                    ror       ~@~
                    ror       ~1,~+1~,1~,~2~
                    ror       ~1,~+2~,1~,~2~
                    ror       ~1,~+3~,1~,~2~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    ror       ~1~
                    ror       ~1~+1
                    ror       ~1~+2
                    ror       ~1~+3
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    ror       ,ax
                    ror       1,ax
                    ror       2,ax
                    ror       3,ax
                    pulhx
                    endm

;*******************************************************************************
; ROL for bytes (differs from built-in ROL in that it works for any address)

rol.b               macro     Variable
          #ifparm ~,1~~2~
                    rol       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00
                    rol       ~@~
                    mexit
          #endif
                    psha
                    lda       ~@~
                    rola
                    sta       ~@~
                    pula
                    endm

;*******************************************************************************
; ROL for words

rol.w               macro     Variable
          #ifparm ~,1~~2~
                    rol       ~1,~+1~,1~,~2~
                    rol       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    rol       ~1~+1
                    rol       ~1~
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    rol       1,ax
                    rol       ,ax
                    pulhx
                    endm

;*******************************************************************************
; ROL for longs

rol.l               macro     Variable
          #ifparm ~,1~~2~
                    rol       ~1,~+3~,1~,~2~
                    rol       ~1,~+2~,1~,~2~
                    rol       ~1,~+1~,1~,~2~
                    rol       ~@~
                    mexit
          #endif
          #ifz ~1~&$FFFFFF00                      ;assumes whole word in zero page
                    rol       ~1~+3
                    rol       ~1~+2
                    rol       ~1~+1
                    rol       ~1~
                    mexit
          #endif
                    pshhx
                    ldhx      #~1~
                    rol       3,ax
                    rol       2,ax
                    rol       1,ax
                    rol       ,ax
                    pulhx
                    endm

;*******************************************************************************
; Copy bytes using RegA (shorter code than Copy but it does not protect RegA)

mova                macro     [#]Source,Destination
                    @@is8bit  ~1~
                    lda       ~1~
                    sta       ~2~
                    endm

;*******************************************************************************

mova.w              macro     [#]Source,Destination
                    @@is16bit ~1~
                    lda       ~[1.-2]~
                    sta       ~[2.-2]~
                    lda       ~[1.-1]~
                    sta       ~[2.-1]~
                    endm

;*******************************************************************************

mova.l              macro     [#]Source,Destination
                    lda       ~[1.4]~
                    sta       ~[2.4]~
                    lda       ~[1.3]~
                    sta       ~[2.3]~
                    lda       ~[1.2]~
                    sta       ~[2.2]~
                    lda       ~[1.1]~
                    sta       ~[2.1]~
                    endm

;*******************************************************************************
; Copy bytes - no registers destroyed

Copy.b              macro     [#]Source,Destination
                    #push
                    #spauto   :sp
                    psha
                    lda       ~1~
                    sta       ~2~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Copy words - no registers destroyed

Copy.w              macro     [#]Source,Destination
                    #push
                    #spauto   :sp
                    psha
                    @@mova.w  ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Copy longs - no registers destroyed

Copy.l              macro     [#]Source,Destination
                    #push
                    #spauto   :sp
                    psha
                    @@mova.l  ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; ADD bytes (see COMMON.INC)
; Note: No destination required if you only need to add in RegA

;*******************************************************************************
; ADD words

add.w               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@add.b   ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    @adc.b    ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    endm

;*******************************************************************************
; ADD longs

add.l               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@add.b   ~[1.4]~\,~[2.4]~\,~[3.4]~
                    @@adc.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @@adc.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @adc.b    ~[1.1]~\,~[2.1]~\,~[3.1]~
                    endm

;*******************************************************************************
; ADD bytes with Carry (see COMMON.INC)
; Note: No destination required if you only interested in the Carry flag

;*******************************************************************************
; ADD words with Carry
; Note: No destination required if you only interested in the Carry flag

adc.w               macro     [#]Operand1,[#]Operand2[,Destination]
                    mreq      1,2:[#]Operand1,[#]Operand2[,Destination]
                    @@adc.b   ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    @adc.b    ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    endm

;*******************************************************************************
; ADD longs with Carry
; Note: No destination required if you only interested in the Carry flag

adc.l               macro     [#]Operand1,[#]Operand2[,Destination]
                    mreq      1,2:[#]Operand1,[#]Operand2[,Destination]
                    @@adc.b   ~[1.4]~\,~[2.4]~\,~[3.4]~
                    @@adc.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @@adc.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @adc.b    ~[1.1]~\,~[2.1]~\,~[3.1]~
                    endm

;*******************************************************************************
; SUB bytes
; Note: No destination required if you only need to compare

sub.b               macro     [#]Operand1,[#]Operand2[,Destination]
                    lda       ~1~
                    sub       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; SUB words
; Note: No destination required if you only need to compare

sub.w               macro     [#]Operand1,[#]Operand2[,Destination]
                    mreq      1,2:[#]Operand1,[#]Operand2[,Destination]
                    @@sub.b   ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    @sbc.b    ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    endm

;*******************************************************************************
; SUB longs
; (With immediate mode, it subtracts first operand from second -- more natural)
; Note: No destination required if you only need to compare

sub.l               macro     [#]Operand1,[#]Operand2[,Destination]
                    mreq      1,2:[#]Operand1,[#]Operand2[,Destination]
                    @@sub.b   ~[1.4]~\,~[2.4]~\,~[3.4]~
                    @@sbc.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @@sbc.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @sbc.b    ~[1.1]~\,~[2.1]~\,~[3.1]~
                    endm

;*******************************************************************************
; SUB bytes with Borrow
; Note: No destination required if you only need to compare

sbc.b               macro     [#]Operand1,[#]Operand2[,Destination]
                    lda       ~1~
                    sbc       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; SUB words with Borrow
; Note: No destination required if you only need to compare

sbc.w               macro     [#]Operand1,[#]Operand2[,Destination]
                    mreq      1,2:[#]Operand1,[#]Operand2[,Destination]
                    @@sbc.b   ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    @sbc.b    ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    endm

;*******************************************************************************
; SUB longs with Borrow
; Note: No destination required if you only need to compare

sbc.l               macro     [#]Operand1,[#]Operand2[,Destination]
                    mreq      1,2:[#]Operand1,[#]Operand2[,Destination]
                    @@sbc.b   ~[1.4]~\,~[2.4]~\,~[3.4]~
                    @@sbc.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @@sbc.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @sbc.b    ~[1.1]~\,~[2.1]~\,~[3.1]~
                    endm

;*******************************************************************************
; AND bytes

and.b               macro     [#]Operand1,Operand2[,Destination]
                    lda       ~1~
                    and       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; AND words

and.w               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@and.b   ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    @and.b    ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    endm

;*******************************************************************************
; AND longs

and.l               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@and.b   ~[1.1]~\,~[2.1]~\,~[3.1]~
                    @@and.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @@and.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @and.b    ~[1.4]~\,~[2.4]~\,~[3.4]~
                    endm

;*******************************************************************************
; OR bytes

ora.b               macro     [#]Operand1,Operand2[,Destination]
                    lda       ~1~
                    ora       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; OR words

ora.w               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@ora.b   ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    @ora.b    ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    endm

;*******************************************************************************
; OR longs

ora.l               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@ora.b   ~[1.1]~\,~[2.1]~\,~[3.1]~
                    @@ora.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @@ora.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @ora.b    ~[1.4]~\,~[2.4]~\,~[3.4]~
                    endm

;*******************************************************************************
; XOR bytes
; Note: No destination required if you only need result in RegA

eor.b               macro     [#]Operand1,Operand2[,Destination]
                    lda       ~1~
                    eor       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; XOR words

eor.w               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@eor.b   ~[1.-1]~\,~[2.-1]~\,~[3.-1]~
                    @eor.b    ~[1.-2]~\,~[2.-2]~\,~[3.-2]~
                    endm

;*******************************************************************************
; XOR longs

eor.l               macro     [#]Operand1,[#]Operand2,Destination
                    mreq      1,2,3
                    @@eor.b   ~[1.1]~\,~[2.1]~\,~[3.1]~
                    @@eor.b   ~[1.2]~\,~[2.2]~\,~[3.2]~
                    @@eor.b   ~[1.3]~\,~[2.3]~\,~[3.3]~
                    @eor.b    ~[1.4]~\,~[2.4]~\,~[3.4]~
                    endm

;*******************************************************************************
; CMP for bytes

cmp.b               macro     [#]Operand1,[#]Operand2
                    #push
                    #spauto   :sp
                    psha
                    @@_ldacmp_ ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; CMP for words

cmp.w               macro     [#]Operand1,[#]Operand2
                    #push
                    #spauto   :sp
                    psha
                    @@_ldacmp_ ~[1.-1]~\,~[2.-1]~
                    bne       Done$$$
                    @@_ldacmp_ ~[1.-2]~\,~[2.-2]~
Done$$$
                    pula
                    #pull
                    endm

;*******************************************************************************
; CMP for longs

cmp.l               macro     [#]Operand1,[#]Operand2
                    #push
                    #spauto   :sp
                    psha
                    @@_ldacmp_ ~[1.1]~\,~[2.1]~
                    bne       Done$$$
                    @@_ldacmp_ ~[1.2]~\,~[2.2]~
                    bne       Done$$$
                    @@_ldacmp_ ~[1.3]~\,~[2.3]~
                    bne       Done$$$
                    @@_ldacmp_ ~[1.4]~\,~[2.4]~
Done$$$
                    pula
                    #pull
                    endm

;*******************************************************************************
; DIV byte

div.b               macro     Variable[,[#]Divisor]
                    @@_not_x_ ~1~
          #ifparm ~2~
                    ldx       ~2~
                    clrh
          #endif
          #ifparm ~'~,1~'.1.3~ = ,sp
          #iftos ~1,~
                    pula
                    div
                    psha
                    mexit
          #endif
          #endif
                    lda       ~1~
                    div
                    sta       ~1~
                    endm

;*******************************************************************************
; DIV word

div.w               macro     Variable[,[#]Divisor]
                    @@div.b   ~@~
                    @div.b    ~1,~+1~,1~
                    endm

;*******************************************************************************
; DIV long

div.l               macro     Variable[,[#]Divisor]
                    @@div.w   ~@~
                    @div.w    ~1,~+2~,1~
                    endm

;*******************************************************************************
; TST bytes (differs from built-in TST in that it works for any address)

tst.b               macro     Operand
                    #push
                    #spauto   :sp
                    #ppc
          #ifb ~,1~~2~
          #ifnz ]~1~
                    psha
                    lda       ~@~
                    pula
          #endif
          #endif
          #if :pc = :ppc
                    tst       ~@~
          #endif
                    #pull
                    endm

;*******************************************************************************
; TST words (current non-HCS version leaves CCR[N] invalid)

tst.w               macro     Operand
                    mset      #
                    #push
                    #spauto   :sp
          #ifhcs
                    pshhx
                    ldhx      ~1~
                    pulhx
          #else
                    psha
                    lda       ~[1.-1]~
                    ora       ~[1.-2]~
                    pula
          #endif
                    #pull
                    endm

;*******************************************************************************
; TST longs (current version leaves CCR[N] invalid)

tst.l               macro     Operand
                    mset      #
                    #push
                    #spauto   :sp
                    psha
                    lda       ~[1.1]~
                    ora       ~[1.2]~
                    ora       ~[1.3]~
                    ora       ~[1.4]~
                    pula
                    #pull
                    endm

;*******************************************************************************
; AIS but only for non-zero values.  Especially useful with automatic offsets
; such as :PSP which may assume any value, even zero.  Transparent in #MCF mode.

ais                 macro     Size
          #ifnz ~#1~
                    !ais      ~1~
          #endif
                    endm

;*******************************************************************************
; Vector redirection for MCUs (like the QE128) which don't have it in hardware
; This should be placed first (and only) thing inside any hard ISR handler.

ReVector            macro     [#]SoftVectorAddress
                    #push
                    #spauto   :sp
                    lda       ~[1.-2]~
                    psha
                    lda       ~[1.-1]~
                    psha
                    RTS                           ;;JUMP to stacked vector
                    #pull
                    endm

;*******************************************************************************
; Define port bits by position (Similar functionality to PIN and BITNUM macros)
; If label is present, first parameter is the address for the label
; (Address may be followed by " size" for the label. Default size is one.)
; If the label is missing only the bits need to be specified.
; Bits should be given in least significant order (from Bit0 to BitN)
; leaving blank those bits that are undefined/don't care.

Port                macro     Address [Size][,Bit0,...,BitN]
                    #temp     32                  ;;max 32-bit if no label is given
          #ifnb ~label~
                    mreq      1:Address [Size][,Bit0,...,BitN]
                    mset      1,~1~ 1             ;;default size is one
~label~             set       ~' '~,~' '2~
                    mdel      1
          #endif
          #ifnz ::~label~
                    #temp     ::~label~*8         ;;max bits if label is sized
          #endif
          #if :temp > 32
                    merror    Max length is 32-bit (not {:temp}-bit)
          #endif
          #if :nn > :temp
                    merror    More than {:temp} bits specified ({:nn})
          #endif
          #ifnz :nn
                    #Message  --------------------------------------------------
            #ifnb ~label
                    #Message  ~label~ [{~label~(h)}]
                    #Message  --------------------------------------------------
            #endif
          #endif
                    mdo
                    #temp     :mloop-1
          #ifnb ~{:mloop}.~
                    mset      0
            #ifparm ~{:mloop}.1.1~ = _            ;;if _ 1st, use LABEL_BIT format
                    mset      0,~label~
            #endif
                    #Message  ~label~~'....................'.1.{20-:label}~ Bit{:temp} ~{:mloop}.~
~text~~{:mloop}.~.  equ       :temp
~text~~{:mloop}.~_  equ       1<:temp
          #endif
                    mloop     :nn
                    endm

;*******************************************************************************
; Define PIN names (PIN for port, PIN. for pin number, and PIN_ for mask)
; (It can also be used for bit-mapped registers or variables)
; PinName can be either the 1st parameter (when three parameters are present),
; or the label on the left side of the macro (when two parameters are present)

Pin                 macro     [[PinName,]PORT[,BitNumber]]
          #ifb ~@~
              #ifb ~label~
                    merror    A label for the pin is required
              #endif
              #ifb ~text~
                    merror    PORT parm required on first use
              #endif
                    #temp
              #ifdef ~text~.
                    #temp     ~text~.+1
              #endif
~label~             set       ~text~
~label~.            equ       {:temp}
~label~_            equ       1<~label~.
                    mset      0,~label~
          #endif
          #ifb ~label~
            #if :n = 1
                    mset      0,~1~
                    mexit
            #endif
                    mreq      1,2:PinName,PORT[,BitNumber]
                    mdef      3,0
                    mset      0,~1~
                    #temp     ~3~
~1~                 set       ~2~
~1~.                set       ~3~
~1~_                set       1<~1~.
          #else ifnb ~@~
                    mreq      1:PORT[,BitNumber]
                    mdef      2,0
                    mset      0,~label~
                    #temp     ~2~
~label~             set       ~1~
~label~.            equ       ~2~
~label~_            equ       1<~label~.
          #endif
          #if :temp > 7
                    #Warning  BitNumber ({:temp}) > 7
          #endif
          #if :index = 1
                    #Hint     Deprecated. Use built-in PIN pseudo-op instead
          #endif
                    endm

;*******************************************************************************
; Check if a pin has been defined (normally via @PIN macro), else issue error.
; (It can also be used for bit-mapped registers or variables.)
; Place it inside a general-purpose module to warn the user including the module
; about missing but required pin definitions.  The user then simply needs to add
; the correct @pin definitions for each missing pin before including the module.
; (Note: MSET allows us to do a simple trick; use parameter 0 as an 'embedded
; macro' to define the error directive once, even though we use it three times.)

CheckPin            macro     PinName[,PinName]*
          #ifndef ~{:loop}.~&&~{:loop}.~.&&~{:loop}.~_
            #ifnz ~{:loop}.~&$FFF8FF00            ;;complement of $700FF
                    #Error    \@~{:loop}.~\@ not defined with [@]pin
                    mexit
            #endif
          #endif
                    mtop      :n
                    endm

;*******************************************************************************
; Export pin(s)

ExpPin              macro     PinName[,PinName]*
                    #Hint     Deprecated. Use PIN and #EXPORT instead
                    mreq      1:PinName[,PinName]*
                    mdo
          #ifdef ~{:mloop}.~
                    @@CheckPin ~{:mloop}.~
                    #!Export  ~{:mloop}.~,~{:mloop}.~.,~{:mloop}.~_
          #endif
                    mloop     :n
                    endm

;*******************************************************************************
; Read the status of a PIN into the CCR[C]

ReadPin             macro     PinName
          #ifdef ~1'.'~.
                    mdef      2,~1'.'~
                    !brset    ~1'.'~.,~2~,:pc+3
          #else
                    !brset    ~1~,:pc+3
          #endif
                    endm

;*******************************************************************************
; Copy pin state to another pin.  If FromPin is missing, use the CCR[C] value

CopyPin             macro     [FromPin],ToPin
          #ifb ~1~
                    bcc       _0$$$               ;;if source low, go copy a low
          #else
            #ifdef ~1~.
                    @@brclr   ~1~,_0$$$           ;;if source low, go copy a low
            #else
                    brclr     ~1~,_0$$$           ;;if source low, go copy a low
            #endif
          #endif
          #ifdef ~2~.
                    @@bset    ~2~                 ;;else, make target high
          #else
                    bset      ~2~                 ;;else, make target high
          #endif
                    bra       Done$$$             ;;we're done
_0$$$
          #ifdef ~2~.
                    @@bclr    ~2~                 ;;make target low
          #else
                    bclr      ~2~                 ;;make target low
          #endif
Done$$$             endm

;*******************************************************************************
; Set pull-up for given PIN(s)

Pullup              macro     PIN[,PIN]*[,,NoSaveRegAflag]
                    mset      0,ABCDEFGHIJK       ;;ports to check (adjust as needed)
          #if :loop = 1
                    #temp
          #endif
          #ifdef ~{:loop}.~
                    mdo
          #ifdef PT~text.{:mloop}.1~PUE
            #if [[~{:loop}.~ = PORT~text.{:mloop}.1~
              #ifz ]PT~text.{:mloop}.1~PUE
                #ifdef ~{:loop}.~.
                    !bset     ~{:loop}.~.,PT~text.{:mloop}.1~PUE
                #else
                    #temp2    ~{:loop}.~
                    !bset     {]]{:temp2}},PT~text.{:mloop}.1~PUE
                #endif
              #else
                #if :n = :nn
                  #ifz :temp
                    psha
                    #temp     1
                  #endif
                #endif
                    lda       PT~text.{:mloop}.1~PUE
                #ifdef ~{:loop}.~_
                    ora       #~{:loop}.~_
                #else
                    ora       #@~{:loop}.~
                #endif
                    sta       PT~text.{:mloop}.1~PUE
              #endif
            #endif
          #endif
                    mloop     :text
          #else
                    #Hint     Skipping \@~0~\@ on undefined \@~{:loop}.~\@
          #endif
                    mtop      :n
              #ifnz :temp
                    pula
              #endif
                    endm

;*******************************************************************************
; Define Bit names using "Bit." for bit number, and "Bit_" for mask

BitNum              macro     BinName,BitNumber
~1~.                equ       ~2~
~1~_                equ       1<~1~.
                    endm

;*******************************************************************************
; Define all BitName bits from MinNumber to MaxNumber

Bits                macro     BitName,MinNumber,MaxNumber[,FirstBit]
                    mreq      1,2,3:BitName,MinNumber,MaxNumber[,FirstBit]
                    mdef      4,0
                    mdo
~1~{~2~+:mloop-1}.  equ       {~4~+:mloop-1}
~1~{~2~+:mloop-1}_  equ       1<{~4~+:mloop-1}
                    mloop     {~3~-~2~+1}
                    endm

;*******************************************************************************
; Make PIN an input or output, accordingly

Input               macro     PinName[,PinName]*
                    mreq      1:PinName[,PinName]*
                    mswap     1,:loop
          #if [[~1~ < RAM                         ;;only for registers, not flags
            #ifdef DDR
              #ifdef ~1~.
                    !bclr     ~1~.,~1~+DDR
              #else
                    !bclr     ~1~+DDR
              #endif
            #else
              #ifnz ~1~+DDRO&$FFFFFF00
                    psha
              #endif
              #ifdef ~1~.
                    @@_bclr_  ~1~.,~1~+DDRO
                    @@_bset_  ~1~.,~1~+DDRI
              #else
                    @@_bclr_  {]]~1~},~1~+DDRO
                    @@_bset_  {]]~1~},~1~+DDRI
              #endif
              #ifnz ~1~+DDRO&$FFFFFF00
                    pula
              #endif
            #endif
          #endif
                    mtop      :n
                    endm
;-------------------------------------------------------------------------------
Output              macro     PinName[,PinName]*
                    mreq      1:PinName[,PinName]*
                    mswap     1,:loop
          #if [[~1~ < RAM                         ;;only for registers, not flags
            #ifdef DDR
              #ifdef ~1~.
                    !bset     ~1~.,~1~+DDR
              #else
                    !bset     ~1~+DDR
              #endif
            #else
              #ifnz ~1~+DDRO&$FFFFFF00
                    psha
              #endif
              #ifdef ~1~.
                    @@_bclr_  ~1~.,~1~+DDRI
                    @@_bset_  ~1~.,~1~+DDRO
              #else
                    @@_bclr_  {]]~1~},~1~+DDRI
                    @@_bset_  {]]~1~},~1~+DDRO
              #endif
              #ifnz ~1~+DDRO&$FFFFFF00
                    pula
              #endif
            #endif
          #endif
                    mtop      :n
                    endm

;*******************************************************************************
; Turn PIN On or Off, accordingly, and make sure it's an output.

On                  macro     PinName[,PinName]*
                    mreq      1:PinName[,PinName]*
                    mswap     1,:loop
          #ifdef ~1~.
                    !bset     ~1~.,~1~
          #else
                    !bset     ~1~
          #endif
                    @@Output  ~1~
                    mtop      :n
                    endm
;-------------------------------------------------------------------------------
Off                 macro     PinName[,PinName]*
                    mreq      1:PinName[,PinName]*
                    mswap     1,:loop
          #ifdef ~1~.
                    !bclr     ~1~.,~1~
          #else
                    !bclr     ~1~
          #endif
                    @@Output  ~1~
                    mtop      :n
                    endm

;*******************************************************************************
; Toggle Pin name

Toggle              macro     PinName[,PinName]*
                    mreq      1:PinName[,PinName]*
                    psha
                    mdo
                    mswap     1,:mloop
                    lda       ~1~
          #ifdef ~1~_
                    eor       #~1~_               ;toggle pin
          #else
                    eor       #@~1~               ;toggle pin
          #endif
                    sta       ~1~
                    mloop     :n
                    pula
                    endm

;*******************************************************************************
; CBEQA complement

cbnea               macro     CompareTarget,Address
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    cbeqa     ~1~,Done$$$
                    bra       ~2~
Done$$$             endm

;*******************************************************************************
; CBEQ  complement

cbne                macro     CompareTarget,Address
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    cbeq      ~1~,Done$$$
                    bra       ~2~
Done$$$             endm

;*******************************************************************************
; CBEQX complement

cbnex               macro     CompareTarget,Address
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    cbeqx     ~1~,Done$$$
                    bra       ~2~
Done$$$             endm

;*******************************************************************************

Copyright           macro     [SinceYear]
                    mdef      1,{:year}
          #ifparm ~1~ = {:year}
                    mset      1
          #else
                    mset      1,~1~-
          #endif
                    #Message  Copyright (c) ASPiSYS ~1~{:year}
                    fcs       'Copyright (c) ASPiSYS ~1~{:year}'
                    endm

;*******************************************************************************
; Some commonly-used OS8-related macros
;*******************************************************************************

;*******************************************************************************
; Give up current task's remaining timeslice if running under OS8

fNextTask           macro
          #ifdef _MTOS_
                    os        fNextTask
          #else
                    cli
                    nop
          #endif
                    endm

;*******************************************************************************
; Semaphore Lock/Unlock

fLock               macro     sema
          #ifndef _MTOS_
                    mexit
          #endif
          #ifb ~1.1.4~ == sema
                    mset      1,sema~1~           ;;prepend sema if missing
          #endif
          #if _MTOS_ < 124
                    psha
                    lda       #~#1~
                    os        ~0~
                    pula
          #else
                    os        ~0~
                    fcb       ~#1~
          #endif
                    endm

;*******************************************************************************

fLockAttempt        macro     sema
          #ifndef _MTOS_
                    mexit
          #endif
          #ifb ~1.1.4~ == sema
                    mset      1,sema~1~           ;;prepend sema if missing
          #endif
          #if _MTOS_ < 124
                    psha
                    lda       #~#1~
                    os        ~0~
                    pula
          #else
                    os        ~0~
                    fcb       ~#1~
          #endif
                    endm

;*******************************************************************************

fUnlock             macro
          #ifndef _MTOS_
                    mexit
          #endif
          #ifb ~1.1.4~ == sema
                    mset      1,sema~1~           ;;prepend sema if missing
          #endif
          #if _MTOS_ < 124
                    psha
                    lda       #~#1~
                    os        ~0~
                    pula
          #else
                    os        ~0~
                    fcb       ~#1~
          #endif
                    endm

;*******************************************************************************
; Define one (or more) semaphore(s).  Skip already defined ones.
; Create Lock/Unlock calls for each defined semaphore when using keyword #SAVE#

sema                macro     Sema1[,Sema2]*
          #ifparm ~1~ = #SAVE#
                    mdo
                    mset      2,~text','{:mloop}~
            #ifb ~2~
                    mexit
            #endif
            #ifdef sema~2~
                    #Message  Defined Lock~2~ & Unlock~2~ calls
Lock~2~             proc
                    psha
                    tpa
                    @@fLock   sema~2~
                    tap
                    pula
                    rtc

Unlock~2~           proc
                    psha
                    tpa
                    @@fUnlock sema~2~
                    tap
                    pula
                    rtc
            #endif
                    mloop
                    mexit
          #endif
                    mdo
                    mswap     1,:mloop
          #ifdef sema~1~
                    #Hint     sema~1~ already defined
          #else
sema~1~             exp       :index
MAXSEMAS            set       sema~1~
                    mset      0,~1~,~text~
          #endif
                    mloop     :n
                    endm

;*******************************************************************************
; Define keys for ADKEYS.MOD based on actual voltage measured
; Two possible call formats:
; 1.                @DefADKey KEY,mVolts
; 2. KEY_VALUE_KEY  @DefADKey mVolts

DefADKey            macro     (KEY_VALUE_)NAME,mV
          #ifb ~label~
                    mreq      1,2:(KEY_VALUE_)NAME,mV
                    mset      1,KEY_VALUE_~1~
          #else
                    mreq      1:mV
                    mset      2,~1~               ;;move mV to parm 2
                    mset      1,~label~           ;;move label to parm 1
          #endif
                    #temp     ~2~*255/VDD-10
          #if :temp < 0
                    #temp
          #endif
~1~                 set       :temp
                    endm

;*******************************************************************************
; FCB (Form Constant Byte) with BCD value of the parameter constant (upto 99)

BCD                 macro     Constant[,Constant]*
                    mreq      1:Constant[,Constant]*
                    mswap     1,:loop
                    fcb       ~1~\10|{~1~\100/10<4}  ;;\100 to truncate high byte
                    mtop      :n
                    endm

;*******************************************************************************
; Define a Pascal-style string

StrPas              macro     'string text'
                    mset      #
                    mreq      1:'string text'
                    mstr      1
                    fcc       :1-2,~1~            ;length, string text
                    endm

;*******************************************************************************
; Define a string for the current LCD and warn if the string is too long to fit

lcdfcs              macro
                    mset      #
                    mreq      1:At least one parameter is required
                    #temp     :pc
                    fcs       ~1~
                    #temp     :pc-:temp-1         ;;-1 for not counting ASCIZ terminator
          #if :temp > LCD_COLS
                    #Warning  String too long ({:temp}) for {LCD_COLS}x{LCD_ROWS} LCD
          #endif
                    mexit     :temp               ;;return total string length
                    endm

;*******************************************************************************
; Define usable bps rates (based on BUS) from the given list and define related
; labels formatted as bps_nnn where nnn is the baud rate, and also define
; bps_max to be the same as the highest possible bps rate.

DefBaud             macro     DesiredBaud1[,DesiredBaud2[,...]]
          #ifnhcs
                    merror    For use with 9S08 MCUs only
          #endif
                    mswap     1,:loop
          #ifb ~1~
                    mexit
          #endif
          #if :loop = 1                           ;;[2012.06.25] avoid redefinition
             #ifb ~text~
                    mset      0,{BUS_HZ}
             #else if ~text~ = BUS_HZ
                    mexit
             #else
                    mset      0,{BUS_HZ}
             #endif
          #endif
bps_$$$             set       BUS_HZ/16/~1~
          #if bps_$$$ > 1<13-1
                    #Message  bps_~1~ too slow (baud rate register overflow)
                    mtop
          #else ifz bps_$$$
                    #Message  bps_~1~ too fast (baud rate register underflow)
                    mtop
          #endif
                    #temp     BUS_HZ/{BUS_HZ/~1~/16*16}
      #if :temp < 100+2*~1~/100
      #if :temp > 100-2*~1~/100
                    ;^ ±2% allowed baud tolerance as percent (change as needed)
          #ifdef bps_~1~
bps_~1~             set       bps_$$$
          #else
bps_~1~             exp       bps_$$$
          #endif
bps_max             def       bps_$$$             ;first time max bps rate
          #if ~1~ >= BUS_HZ/16/bps_max
bps_max             set       bps_$$$             ;make this the new max bps rate
          #endif
                    #temp     BUS_HZ/16/bps_$$$-~1~*10000/~1~
                    #Message  bps_~1~ = {BUS_HZ/16/bps_$$$} bps, {:temp(2)}% off
      #endif
      #endif
          #ifndef bps_~1~
                    #Message  bps_~1~ inaccurate at {BUS_KHZ(3)} MHz bus, not defined
          #endif
;-------------------------------------------------------------------------------
                    mtop
                    endm

;*******************************************************************************
; Quickly define all usable standard baud rates in one go, plus any extra ones

StandardBaudRates   macro     [AnyExtraBaudRates]
                    @DefBaud  300,1200,2400,4800,9600,19200,38400,57600,115200,~@~
                    endm

;*******************************************************************************
; Symbol to the left of macro call (if present) and :MEXIT internal variable
; are SET to the integer Log2 (log base two) of the given expression.
; Quick-n-dirty calculation of integer part of log2(n) for values upto 2^31-1
; Useful to get power from value (e.g., as when used with various prescalers.)
; With the optional ShiftLeftBits parameter, one can shift the result into the
; expected bit positions (e.g., within a larger bitmap).

#ifnomdef Log2
Log2                macro     Expr[,ShiftLeftBits]
                    mreq      1:Usage: Label @~0~ Expression[,ShiftLeftBits]
                    mdef      2,0
                    #temp     :loop-2
#ifz ~1~
                    #temp     :temp<{~2~}
          #ifparm ~label~
~label~             set       :temp
          #endif
                    mexit     :temp
#endif
                    mset      1,{~1~>1}
                    mtop
                    endm
#endif

;*******************************************************************************
; Macro for showing end-of-program statistics (to be updated as needed)

EndStats            macro     [Module Start Label]
          #ifincluded
                    mexit
          #endif
          #ifndef ...                             ;;show stats only when ... is defined
                    mexit
          #endif
                    #Hint     +-------------------------------------------------
                    #Hint     | Statistics (from \@~mfilename~/~0~\@ macro)
                    #Hint     +-------------------------------------------------
                    mdef      1,?_OBJECT_?
                    #Hint     | Module size...: {*-~1~} bytes (from ?_OBJECT_?)
                    #temp                         ;;initialize total to zero
                    mset      0
          #if $100-:RAM > 0
                    #Hint     | Available RAMz: {$100-:RAM} byte(s)
          #endif
          #ifdef XRAM
                    #temp     XRAM_END-:XRAM+1    ;;count XRAM if available
                    mset      0,[includes XRAM]
          #endif
                    #temp     RAM_END-:RAM+1+:temp ;;add RAM
                    #Hint     | Available RAM : {:temp} byte(s) ~text~
          #if :temp-REQUIRED_STACK < 0
                    mset      0,[WARNING] ~text~
          #endif
          #ifdef _MTOS_
                    #temp     :temp-{REQUIRED_STACK*MAXTASKS}
          #else
                    #temp     :temp-REQUIRED_STACK
          #endif
                    #Hint     | Non-stack RAM : {:temp} byte(s) ~text~
          #if ROM_END-:ROM+1 >= 0
                    #Hint     | Available ROM : {ROM_END-:ROM+1}/{ROM_END-ROM} byte(s)
          #endif
                    mset      0
          #ifdef XROM
                    #Hint     | Available XROM: {XROM_END-:XROM+1}/{XROM_END-XROM} byte(s)
          #endif
          #ifmmu
                    #temp     :SEG0-PPAGE0
                    #temp     :SEG2-PPAGE2+:temp
                    #temp     :SEG4-PPAGE4+:temp
                    #temp     :SEG5-PPAGE5+:temp
                    #temp     :SEG6-PPAGE6+:temp
                    #temp     :SEG7-PPAGE7+:temp
                    #Hint     | Available Seg0: {{:PAGE_END-:PAGE_START}-{:SEG0-PPAGE0}} byte(s)
                    #Hint     | Available Seg2: {{:PAGE_END-:PAGE_START}-{:SEG2-PPAGE2}} byte(s)
                    #Hint     | Available Seg4: {{:PAGE_END-:PAGE_START}-{:SEG4-PPAGE4}} byte(s)
                    #Hint     | Available Seg5: {{:PAGE_END-:PAGE_START}-{:SEG5-PPAGE5}} byte(s)
                    #Hint     | Available Seg6: {{:PAGE_END-:PAGE_START}-{:SEG6-PPAGE6}} byte(s)
                    #Hint     | Available Seg7: {{:PAGE_END-:PAGE_START}-{:SEG7-PPAGE7}} byte(s)
                    #Hint     | Available MMU : {:PAGE_END-:PAGE_START*6-:temp} byte(s) [total]
          #endif
          #ifdef NUMBER_OF_OS_CALLS
                    #Hint     | Total OS calls: {NUMBER_OF_OS_CALLS} (of {MAX_OS_CALLS})
          #endif
          #ifdef TASK_STACK_SIZE
                    #Hint     | Stack per task: {TASK_STACK_SIZE} bytes [TASK_STACK_SIZE]
          #endif
                    #Hint     | Macros called : {:totalmacrocalls}
                    #Hint     | [#]PROCs used : {:proc}
                    #Hint     | Max stack used: {:spmax}
          #ifdef ?HANDLER_CYCLES
                    #Hint     | Handler cycles: {?HANDLER_CYCLES}
          #endif
                    #Hint     +-------------------------------------------------
          #ifdef TASK_STACK_SIZE
            #if :spmax > TASK_STACK_SIZE
                    #Warning  Max stack used ({:spmax}) > TASK_STACK_SIZE ({TASK_STACK_SIZE})
            #endif
          #endif
                    endm

;*******************************************************************************
                    #Exit
;*******************************************************************************
;                   Test various macro expansions
;*******************************************************************************

                    #ListOff
                    #Uses     mcu.inc
                    #ListOn

                    @MyDefaultDirectives

                    #RAM

var_zero_page       rmb       4                   ;for testing zero page ops

                    #XRAM

var_any_page        rmb       4                   ;for testing non-zero page ops

                    #ROM

                    @Vector   Vreset,Start

LED                 pin       PORTA               ;define a port pin

Start               @align2   9                   ;as power of two

                    @rsp

                    @On       LED                 ;turn pin On and make output
                    @Off      LED                 ;turn pin Off and make output
                    bset      LED
                    bclr      LED
                    brset     LED,*
                    brclr     LED,*

                    @bitnum   ADPU,1              ;define a single bit
                    @bits     Flag,5,8            ;define Flag5..Flag8 bits & masks
                    @bits     A,1,5,3             ;define A1..A5 starting from 3

                    @pin      XXX,var_any_page,3  ;define a non-zero page "pin"
                    @bset     XXX                 ;turn "pin" on
                    @bclr     XXX                 ;turn "pin" off
                    @brset    XXX,*
                    @brclr    XXX,*
                    @toggle   XXX,LED

                    @ClrRange #$80,$100

                    fcb       :year\100,:month,:date  ;decimal date stored as is
                    @bcd      :year,:month,:date  ;decimal date stored as BCD

MyCopyright         @Copyright
                    @Copyright 1998

                    @StrPas   'Hello World!'      ;a Pascal string
                    @StrPas   '.. etc ..'         ;and another one
                    @StrPas   and w/o quotes
          #ifhcs
                    @StandardBaudRates            ;attempt to define all standard bps rates
                    @DefBaud  230400,460800       ;and some extra ones
          #endif
LogOf4096           @Log2     2*2048              ;Set symbol to log2 of following expression
                    #Message  Log2 of {2*2048} returned: LogOf4096={LogOf4096}, :MEXIT={:mexit}

                    @clr.b    var_zero_page
                    @clr.w    var_zero_page
                    @clr.l    var_zero_page

                    @inc.b    var_zero_page
                    @inc.w    var_zero_page
                    @inc.l    var_zero_page

                    @com.b    var_zero_page
                    @com.w    var_zero_page
                    @com.l    var_zero_page

                    @lsl.b    var_zero_page
                    @lsl.w    var_zero_page
                    @lsl.l    var_zero_page

                    @lsr.b    var_zero_page
                    @lsr.w    var_zero_page
                    @lsr.l    var_zero_page

                    @asr.b    var_zero_page
                    @asr.w    var_zero_page
                    @asr.l    var_zero_page

                    @ror.b    var_zero_page
                    @ror.w    var_zero_page
                    @ror.l    var_zero_page

                    @neg.b    var_zero_page
                    @neg.w    var_zero_page
                    @neg.l    var_zero_page

                    @div.b    var_zero_page
                    @div.w    var_zero_page
                    @div.l    var_zero_page

                    @tst.b    var_zero_page
                    @tst.w    var_zero_page
                    @tst.l    var_zero_page

                    @mov.b    var_zero_page,var_zero_page
                    @mov.w    var_zero_page,var_zero_page
                    @mov.l    var_zero_page,var_zero_page
                    @mov.b    #123,var_zero_page
                    @mov.w    #12345,var_zero_page
                    @mov.l    #123456789,var_zero_page

                    @cmp.b    var_zero_page,#123
                    @cmp.w    var_zero_page,#12345
                    @cmp.l    var_zero_page,#123456789
                    @cmp.b    var_zero_page,var_zero_page
                    @cmp.w    var_zero_page,var_zero_page
                    @cmp.l    var_zero_page,var_zero_page

                    @abs.b    var_zero_page
                    @abs.w    var_zero_page
                    @abs.l    var_zero_page

                    @add.b    var_zero_page,var_zero_page,var_zero_page
                    @add.w    var_zero_page,var_zero_page,var_zero_page
                    @add.l    var_zero_page,var_zero_page,var_zero_page
                    @add.b    #123,var_zero_page,var_zero_page
                    @add.w    #12345,var_zero_page,var_zero_page
                    @add.l    #123456789,var_zero_page,var_zero_page
                    @add.b,   1,sp 2,sp 3,sp
                    @add.w,   1,sp 2,sp 3,sp
                    @add.l,   1,sp 2,sp 3,sp

                    @sub.b    var_zero_page,var_zero_page,var_zero_page
                    @sub.w    var_zero_page,var_zero_page,var_zero_page
                    @sub.l    var_zero_page,var_zero_page,var_zero_page
                    @sub.b    #123,var_zero_page,var_zero_page
                    @sub.b    var_zero_page,#123,var_zero_page
                    @sub.w    #12345,var_zero_page,var_zero_page
                    @sub.w    var_zero_page,#12345,var_zero_page
                    @sub.l    #123456789,var_zero_page,var_zero_page
                    @sub.l    var_zero_page,#123456789,var_zero_page
                    @sub.b,   1,sp 2,sp 3,sp
                    @sub.w,   1,sp 2,sp 3,sp
                    @sub.l,   1,sp 2,sp 3,sp

                    @and.b    var_zero_page,var_zero_page,var_zero_page
                    @and.w    var_zero_page,var_zero_page,var_zero_page
                    @and.l    var_zero_page,var_zero_page,var_zero_page
                    @and.b    #123,var_zero_page,var_zero_page
                    @and.w    #12345,var_zero_page,var_zero_page
                    @and.l    #123456789,var_zero_page,var_zero_page
                    @and.b,   1,sp 2,sp 3,sp
                    @and.w,   1,sp 2,sp 3,sp
                    @and.l,   1,sp 2,sp 3,sp

                    @ora.b    var_zero_page,var_zero_page,var_zero_page
                    @ora.w    var_zero_page,var_zero_page,var_zero_page
                    @ora.l    var_zero_page,var_zero_page,var_zero_page
                    @ora.b    #123,var_zero_page,var_zero_page
                    @ora.w    #12345,var_zero_page,var_zero_page
                    @ora.l    #123456789,var_zero_page,var_zero_page
                    @ora.b,   1,sp 2,sp 3,sp
                    @ora.w,   1,sp 2,sp 3,sp
                    @ora.l,   1,sp 2,sp 3,sp

                    @eor.b    var_zero_page,var_zero_page,var_zero_page
                    @eor.w    var_zero_page,var_zero_page,var_zero_page
                    @eor.l    var_zero_page,var_zero_page,var_zero_page
                    @eor.b    #123,var_zero_page,var_zero_page
                    @eor.w    #12345,var_zero_page,var_zero_page
                    @eor.l    #123456789,var_zero_page,var_zero_page
                    @eor.b,   1,sp 2,sp 3,sp
                    @eor.w,   1,sp 2,sp 3,sp
                    @eor.l,   1,sp 2,sp 3,sp
          ;--------------------------------------
                    @clr.b    var_any_page
                    @clr.w    var_any_page
                    @clr.l    var_any_page

                    @inc.b    var_any_page
                    @inc.w    var_any_page
                    @inc.l    var_any_page

                    @com.b    var_any_page
                    @com.w    var_any_page
                    @com.l    var_any_page

                    @lsl.b    var_any_page
                    @lsl.w    var_any_page
                    @lsl.l    var_any_page

                    @lsr.b    var_any_page
                    @lsr.w    var_any_page
                    @lsr.l    var_any_page

                    @asr.b    var_any_page
                    @asr.w    var_any_page
                    @asr.l    var_any_page

                    @ror.b    var_any_page
                    @ror.w    var_any_page
                    @ror.l    var_any_page

                    @neg.b    var_any_page
                    @neg.w    var_any_page
                    @neg.l    var_any_page

                    @div.b    var_any_page
                    @div.w    var_any_page
                    @div.l    var_any_page

                    @tst.b    var_any_page
                    @tst.w    var_any_page
                    @tst.l    var_any_page

                    @mov.b    var_any_page,var_any_page
                    @mov.w    var_any_page,var_any_page
                    @mov.l    var_any_page,var_any_page
                    @mov.b    #123,var_any_page
                    @mov.w    #12345,var_any_page
                    @mov.l    #123456789,var_any_page

                    @cmp.b    #123,var_any_page
                    @cmp.b    var_any_page,#123
                    @cmp.w    #12345,var_any_page
                    @cmp.w    var_any_page,#12345
                    @cmp.l    #123456789,var_any_page
                    @cmp.l    var_any_page,#123456789
                    @cmp.b    var_any_page,var_any_page
                    @cmp.w    var_any_page,var_any_page
                    @cmp.l    var_any_page,var_any_page

                    @abs.b    var_any_page
                    @abs.w    var_any_page
                    @abs.l    var_any_page

                    @abs.b    1,x
                    @abs.w    2,sp
                    @abs.l    3,spx

                    @add.b    var_any_page,var_any_page,var_any_page
                    @add.w    var_any_page,var_any_page,var_any_page
                    @add.l    var_any_page,var_any_page,var_any_page
                    @add.b    #123,var_any_page,var_any_page
                    @add.w    #12345,var_any_page,var_any_page
                    @add.l    #123456789,var_any_page,var_any_page

                    @sub.b    var_any_page,var_any_page,var_any_page
                    @sub.w    var_any_page,var_any_page,var_any_page
                    @sub.l    var_any_page,var_any_page,var_any_page
                    @sub.b    #123,var_any_page,var_any_page
                    @sub.w    #12345,var_any_page,var_any_page
                    @sub.l    #123456789,var_any_page,var_any_page

                    @and.b    var_any_page,var_any_page,var_any_page
                    @and.w    var_any_page,var_any_page,var_any_page
                    @and.l    var_any_page,var_any_page,var_any_page
                    @and.b    #123,var_any_page,var_any_page
                    @and.w    #12345,var_any_page,var_any_page
                    @and.l    #123456789,var_any_page,var_any_page

                    @ora.b    var_any_page,var_any_page,var_any_page
                    @ora.w    var_any_page,var_any_page,var_any_page
                    @ora.l    var_any_page,var_any_page,var_any_page
                    @ora.b    #123,var_any_page,var_any_page
                    @ora.w    #12345,var_any_page,var_any_page
                    @ora.l    #123456789,var_any_page,var_any_page

                    @eor.b    var_any_page,var_any_page,var_any_page
                    @eor.w    var_any_page,var_any_page,var_any_page
                    @eor.l    var_any_page,var_any_page,var_any_page
                    @eor.b    #123,var_any_page,var_any_page
                    @eor.w    #12345,var_any_page,var_any_page
                    @eor.l    #123456789,var_any_page,var_any_page

                    @ldxa     #1
                    @ldxa     var_zero_page
                    @ldxa     var_any_page
                    @ldxa     1,sp
                    @ldxa     1,x

                    @stxa     var_zero_page
                    @stxa     var_any_page
                    @stxa     1,sp

                    @ldh      #123
                    @ldh      var_zero_page
                    @ldh      var_any_page
                    @ldh      1,x
                    @ldh      1,sp

                    @sth      var_zero_page
                    @sth      var_any_page
                    @sth      1,sp

                    @swap.b   var_zero_page var_any_page
                    @swap.w   var_any_page var_zero_page
                    @swap.l   var_zero_page var_any_page
                    @swap.b   1,sp 2,sp
                    @swap.w   1,sp 3,sp
                    @swap.l   1,sp 5,sp
                    @swap.b   ,x 1,x
                    @swap.w   ,x 2,x
                    @swap.l   ,x 4,x

                    @aix      #0
                    @aix      #5
                    @aix      #-5

                    @ais      #0
                    @ais      #5
                    @ais      #-5

                    @pushv    var_zero_page
                    @pushv    var_zero_page 2
                    @pullv    var_zero_page
                    @pullv    var_zero_page 2

                    @CopyRange  #var_zero_page,#var_any_page,#5

                    #spauto
                    push      temp
                    @pushv    temp,sp
                    ldhx      temp,sp
                    @pullv    temp,sp
                    ldhx      temp,sp

                    @rep      2,lsla,rolx         ;shift left XA twice

;*******************************************************************************
                    @EndStats
