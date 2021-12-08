;*******************************************************************************
;*           COMMON EQUATES -- MCU INDEPENDENT -- FOR ASM8 ASSEMBLER           *
;*******************************************************************************
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;*******************************************************************************
; FREEWARE, Copyright (c) Tony G. Papadimitriou <tonyp@acm.org>
;*******************************************************************************
; General naming conventions (older code may not yet follow precisely):
;-------------------------------------------------------------------------------
; Dot-ending names (XXX.) indicate a unique bit by position number (7 thru 0)
; Underscore-ending names (XXX_) indicate a bit mask (possibly multiple bits)
; Underscore surrounded names (_XXX_) indicate special system symbols such as
; CCR offsets, etc.
; Constants use uppercase (XXX)
; Variables use lowercase and underscores as needed (my_var).
; Pointers begin with a point/dot (.xxx).
; Code labels use CamelCase
; Local labels end with @@ (although ASM8 allows @@ to be anywhere inside label)
;*******************************************************************************
          #if :version < 1200
                    #Warning  Some macros are incompatible with ASM8 v{:version(2)} (please update to ASM8 v12 or later)
          #endif
#ifmain ;-----------------------------------------------------------------------
                    #Fatal    This file can not be used stand-alone
#endif ;------------------------------------------------------------------------

NOT                 def       -1                  ;Used with XOR to get NOT result

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
; Restrict the value of a constant label between a minimum and a maximum
; printing a warning if the value is outside the allowed range

ConstMinMax         macro     Symbol[,MinValue][,MaxValue][,Message]
                    mreq      1:Symbol[,MinValue][,MaxValue]
                    mdef      4,~2~ <= ~1,~ <= ~3~ [not {~1,~}]
                    mset      0,~4~
          #ifb ~2~~3~
                    merror    No MinValue or MaxValue given
          #endif
          #ifnb ~2~
            #if ~1,~ < ~2~
                    #Warning  ~text~
            #endif
          #endif
          #ifnb ~3~
            #if ~1,~ > ~3~
                    #Warning  ~text~
            #endif
          #endif
                    endm

;*******************************************************************************
; Restrict the value of a constant label to one of the specified values
; printing a warning if the value is not in the given set

ConstValues         macro     Symbol,Value[,Value]*
                    mreq      1,2:Symbol,Value[,Value]*
          #ifndef ~1,~
                    mexit     ;;mstop     ~1,~ not yet defined
          #endif
                    mdo       2
          #if ~1,~ = ~{:mloop}.~
                    mexit
          #endif
                    mloop     :n
                    mset      0,~1,~
                    mdel      1
                    mset      #
                    #Warning  ~text~ ({~text~}) not in [~1~]
                    endm

;*******************************************************************************

VDD                 def       3000                ;MCU voltage in mV

;===============================================================================

?max                macro     CONST,UpperLimit
          #if ~1~ > ~2~
                    merror    ~1~ ({~1~}) > ~2~ not allowed
          #endif
                    endm

;-------------------------------------------------------------------------------

BDIV                def       2                   ;default bus divider (9S08)
BDIV_               @Log2     BDIV,6              ;move BDIV bits to Bit7..Bit6
                    @?max     BDIV,8

;===============================================================================

?hz                 macro     FromHz,ToHz
                    mreq      1,2:FromHz,ToHz
#ifdef BUS_~1~
                    mset      1,BUS_~1~
                    mset      2,BUS_~2~
#endif
#ifdef ~1~
          #if ~1~\1000 >= 500
~2~                 set       ~1~/1000+1
          #else
~2~                 set       ~1~/1000
          #endif
#endif
#ifparm ~1.1.4~ = BUS_
          #ifhcs
            #ifdef _PA_||_PT_||_PL_
~1.5~               set       ~1~*BDIV
            #else
~1.5~               set       ~1~*2*BDIV
            #endif
          #else
~1.5~               set       ~1~*4
          #endif
#endif
                    endm

;-------------------------------------------------------------------------------

#ifdef BUS_MHZ
BUS_HZ              def       BUS_MHZ*1000000
BUS_KHZ             def       BUS_MHZ*1000
#endif
                    @?hz      HZ,KHZ
                    @?hz      KHZ,MHZ

MHZ                 def       16                  ;default crystal speed
KHZ                 def       MHZ*1000
HZ                  def       KHZ*1000
          #ifhcs
            #ifdef _PA_||_PT_||_PL_
BUS_HZ              def       HZ/BDIV
            #else
BUS_HZ              def       HZ/2/BDIV
            #endif
          #else
BUS_HZ              def       HZ/4
          #endif
BUS_KHZ             def       BUS_HZ/1000
BUS_MHZ             def       BUS_KHZ/1000

;===============================================================================

#ifhcs
?calc_fll_factor    macro
          #ifdef _QD_
                    #temp1    1
                    mset      0,512
          #else ifdef _FL_
                    #temp1    2
                    mset      0,512,608
          #else ifdef _PA_||_PT_||_PL_
                    #temp1    1
                    mset      0,1024
          #else ifdef _AC_
                    #temp1    2
                    mset      0,1,64
          #else
                    #temp1    6
                    mset      0,512,1024,1536,608,1216,1824
          #endif
                    mdo
                    #temp     ~text[,]{:mloop}~
          ;;------------------------------------- ;MCU variants with ICG
          #ifdef ICGC1
                    #temp2    HZ*7/243000/:temp
            #if :temp2 >= 4
              #if :temp2 <= 18
                #ifz :temp2\2
FLL_FACTOR          def       :temp
                #endif
              #endif
            #endif
          ;;-------------------------------------
          #else
          ;;------------------------------------- ;MCU variants without ICG
            #ifz HZ*10\:temp
              #if HZ*10/:temp >= 312500
                #if HZ*10/:temp <= 390625
FLL_FACTOR          def       :temp
                #endif
              #endif
            #endif
          #endif
          ;;-------------------------------------
                    mloop     :temp1
                    endm
                    @?calc_fll_factor
FLL_FACTOR          def       512
                    @?max     FLL_FACTOR,1824

                    #temp                         ;assume low RANGE
          #ifdef TCXO
            #if TCXO >= 1000000
                    #temp     1                   ;high RANGE
              #ifdef RDIV
                    @ConstMinMax TCXO/RDIV,31250,39063
              #endif
            #endif
          #else !if XTAL >= 1000000
                    #temp     1                   ;high RANGE
            #ifdef RDIV
                    @ConstMinMax XTAL/RDIV,31250,39063
            #endif
          #endif
          #!if RDIV > 128
                    #temp     1                   ;high RANGE
          #endif
RANGE               def       :temp               ;default divider range (0,1)

          #ifdef RDIV
            #ifz RANGE
                    @ConstValues RDIV,1,2,4,8,16,32,64,128
RDIV_               @Log2     RDIV,3              ;move RDIV bits to Bit5..Bit3
            #else
                    @ConstValues RDIV,32,64,128,256,512,1024
RDIV_               @Log2     RDIV/32,3           ;move RDIV bits to Bit5..Bit3
            #endif
          #else
RDIV_               equ       0                   ;a dummy no-op value
          #endif
RANGE_              equ       RANGE<RANGE_SEL.    ;move RANGE bit to correct bit
                    @?max     RANGE,1
#endif
;===============================================================================
          #ifhcs
            #ifdef ICGC1
              #ifnz FLL_FACTOR
                    #temp     HZ*7/243000/FLL_FACTOR
                #if :temp >= 4
                  #if :temp <= 18
                    #ifz :temp\2
MFD                 equ       :temp
                    #else
                    #Warning  Out-of-range MFD {:temp}
                    #endif
                  #endif
                #endif
              #endif
            #else
              #ifnz FLL_FACTOR
                    #temp     HZ*10/FLL_FACTOR
                #ifz HZ*10\FLL_FACTOR
                    #Message  Trim to IRCLK {:temp(1)} Hz (FLL_FACTOR={FLL_FACTOR})
                #else
                    #Warning  Unsupported CPU clock ({HZ(6)} MHz)
                #endif
                #if :temp < 312500
                    #Warning  Out-of-range trim value {:temp(1)} Hz
                #else if :temp > 390625
                    #Warning  Out-of-range trim value {:temp(1)} Hz
                #endif
              #endif
            #endif
          #endif

MSEC_CYCLES         def       BUS_KHZ             ;rough number of cycles per millisecond

;-------------------------------------------------------------------------------

?                   macro
                    #temp     :index-1
Bit{:temp}.         equ       {:temp}
Bit{:temp}_         equ       1<{:temp}
                    mtop      16
                    endm

                    @?                            ;Define Bit0 .. Bit15

;-------------------------------------------------------------------------------
; CCR bits (by position)
;-------------------------------------------------------------------------------

                    @bitnum   CCR_V,7             ;Overflow flag in CCR
                    @bitnum   CCR_U1,6            ;--Undefined
                    @bitnum   CCR_U0,5            ;--Undefined
                    @bitnum   CCR_H,4             ;Half-Carry flag in CCR
                    @bitnum   CCR_I,3             ;Interrupts flag in CCR
                    @bitnum   CCR_N,2             ;Negative flag in CCR
                    @bitnum   CCR_Z,1             ;Zero flag in CCR
                    @bitnum   CCR_C,0             ;Carry flag in CCR

CMP_AFFECTED_       equ       CCR_V_|CCR_N_|CCR_Z_|CCR_C_ ;CMP affected bits
CMP_NOT_AFFECTED_   equ       CMP_AFFECTED_^NOT           ;CMP not affected bits
;-------------------------------------------------------------------------------
; SP (one-based) offsets account for the return address of OS8 dispatcher's CALL
;-------------------------------------------------------------------------------

                    #temp     1+:ab               ;start of stacked data, if any
_H_                 setn      :temp               ;stacked by OS8 SWI ISR
_CCR_               setn      :temp               ;stacked by HC[S]08 interrupt
_A_                 setn      :temp               ;         -//-
_X_                 setn      :temp               ;         -//-
_PCH_               setn      :temp               ;         -//-
_PCL_               setn      :temp               ;         -//-
_DATA_              setn      :temp               ;offset to caller's TOS data

_PC_                set       _PCH_,2             ;alias for full PC word

_INT_FRAME_SIZE_    set       _DATA_-_H_

;*******************************************************************************
; Displays an error message if the assembly-time condition is false
; (The condition should be written as to be compatible with the #IF directive)

assert              macro     Condition[,message]
                    mset      #','
          #if ~1~
                    mexit
          #endif
                    mdel      1                   ;;get rid of condition
                    mset      #                   ;;unify string message
                    mdef      1,Assertion failed (~1~) ;;default message
                    merror    ~1~
                    endm

;*******************************************************************************
; Macro to test if a symbol is at TOS, and issue an error if not

tos                 macro     Symbol
                    mset      #
          #iftos ~1,~
                    mexit
          #endif
                    merror    ~1,~ is expected at TOS
                    endm

;*******************************************************************************
; For each defined port letter, repeat the given instruction.
; Use * as the wildcard that will be replaced with the corresponding letter.
; * may appear once both in the CmdToDo and the Mask to match.
; If LetterList exists, it will be used instead of the full letter list.

ForEachPort         macro     [@]CmdToDo,Mask*[,LetterList]
                    mset      #','
                    mreq      1,2:[@]CmdToDo,Mask* (where * will be replaced by the letter)
                    mset      0,~3~
                    mdef      0,ABCDEFGHIJKLMNOPQRSTUVWXYZ
          #ifparm ~1.1.1~ = @
                    mset      1,@~1~              ;;make macro a @@ call
          #endif
                    mdo
          #ifdef ~2'*'~~text.{:mloop}.1~~2'*'2~
                    ~1'*'~~text.{:mloop}.1~~1'*'2~
          #endif
                    mloop     :text
                    endm

;*******************************************************************************
; Macro to dynamically execute another macro or instruction as one atomic
; operation (i.e., with interrupts temporarily disabled).
; When done with the operation, it restores interrupts to their original status.
; You could use with any macro.  For example, using an ADD.L (add longs) macro
; you could perform the addition with interrupts disabled, even if the original
; macro does not provide for atomicity of operation(s).  Example:
;                   @atomic   add.l,Number1,Number2,Answer

Atomic              macro     [@]CmdToDo[,Parameter]*
                    mreq      1:[@]CmdToDo[,Parameter]*
          #ifparm ~1.1.1~ = @
                    mset      1,@~1~              ;;make macro a @@ call
          #endif
                    mswap     0,1
                    mdel      1
                    mset      #
                    #push
                    #spauto   :sp
                    pshcc
                    sei

                    ~text~    ~1~

                    pulcc
          #if :sp <> :spcheck
                    #Warning  Macro \@~text~\@ resizes stack, ~0~ may fail
          #endif
                    #pull
                    endm

;*******************************************************************************
; Find a character in the string pointed to by HX, and point right past it.
; The user's original RegA is not destroyed.
; CCR[Z] = 1 if end of string reached while searching

SkipChar            macro     [[#]Character]
                    mset      #
          #ifnb ~1~
                    #push
                    #spauto   :sp
                    psha
                    @@_lda_   ~1~
          #endif
Loop$$$
                    tst       ,x                  ;;is it end of ASCIZ string?
                    cbeq      x+,Done$$$          ;;char found, done
                    bne       Loop$$$             ;;repeat until end of ASCIZ string
Done$$$
          #ifnb ~1~
                    pula
                    #pull
          #endif
                    endm

;*******************************************************************************
; Skip over the current and following characters as long as they match the target
; On completion, HX -> first non-target character
; The user's original RegA is not destroyed

EatChar             macro     [[#]Character]
                    mset      #
          #ifnb ~1~
                    #push
                    #spauto   :sp
                    psha
                    @@_lda_   ~1~
          #endif
                    cbeq      x+,*                ;;eat up matching chars
                    aix       #-1                 ;;went too far, back up one
          #ifnb ~1~
                    pula
                    #pull
          #endif
                    endm

;*******************************************************************************
; Find (in RegA) the minimum between RegA and operand

MinA                macro     Operand
                    mset      #
                    mreq      1:Operand
                    cmpa      ~1~
                    bls       Done$$$
                    lda       ~1~
Done$$$
                    endm

;*******************************************************************************
; Find (in RegA) the maximum between RegA and operand

MaxA                macro     Operand
                    mset      #
                    mreq      1:Operand
                    cmpa      ~1~
                    bhs       Done$$$
                    lda       ~1~
Done$$$
                    endm

;*******************************************************************************
; Long version of CBEQA

cjeqa               macro     #operand,target
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    cbeqa     ~1~,Go$$$
                    bra       Done$$$
Go$$$
                    jmp       ~2~
Done$$$
                    endm

;*******************************************************************************
; Long version of CBEQX

cjeqx               macro     #operand,target
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    cbeqx     ~1~,Go$$$
                    bra       Done$$$
Go$$$
                    jmp       ~2~
Done$$$
                    endm

;*******************************************************************************
; Point HX to a TableEntry given its zero-based index, table address, and
; TableEntry bytesize.  Index is optional (in case it is already loaded in RegA)

TblOfs              macro     [[#]Index],[#]Table,[#]TableEntrySize
                    mreq      2,3:[[#]Index],[#]Table,[#]TableEntrySize
          #ifnb ~1~
                    @@_size_, ~1~ 1
          #endif
                    @@_size_, ~3~ 1
                    @@_not_x_ ~2~
                    #push
                    #spauto   :sp
                    psha
                    @@_lda_   ~1~                 ;A = index
                    #temp
          #ifparm ~3.1.1~ = #                     ;;special case optimization
            #!if ~#3~ = 1                         ;;for defined immediate of size 1
                    #temp     1                   ;mark action taken
            #endif
            #ifnum ~#3~                           ;;for numeric immediate
              #if ~#3~ = 1                        ;;of size 1
                    #temp     1                   ;mark action taken
              #endif
            #endif
          #endif
          #ifz :temp
                    ldx       ~3~                 ;X = bytesize of TableEntry
                    mul                           ;XA = offset into table
                    add       ~[2.-2]~
                    xgax
          #else
                    add       ~[2.-2]~            ;XA = offset into table
                    tax
                    clra
          #endif
                    adc       ~[2.-1]~
                    tah                           ;HX -> TableEntry
                    pula
                    #pull
                    endm

;*******************************************************************************
; Macro to use XRAM if XRAM has been defined, RAM otherwise

XRAM                macro
                    #RAM
          #ifdef XRAM
                    #XRAM
          #endif
                    endm

;*******************************************************************************
; Macro to define TASK_STACK_SIZE based on which RAM is used for stack

FixTaskStackSize    macro     MinimumTaskStackSizeConstant
          #ifndef _MTOS_
                    #Hint     ~0~ only useful under MTOS, ignored
                    mexit
          #endif
                    mdef      1,REQUIRED_STACK
                    #temp     MAXTASKS
          #ifdef MY_MAXTASKS
                    #temp     MY_MAXTASKS
          #endif
          #!if STACKTOP > XRAM
TASK_STACK_SIZE     def       XRAM_END-:XRAM/:temp
          #endif
TASK_STACK_SIZE     def       RAM_END-:RAM/:temp
                    #Message  TASK_STACK_SIZE = {TASK_STACK_SIZE} byte(s) per task
          #!if TASK_STACK_SIZE < ~1~
                    #Warning  TASK_STACK_SIZE ({TASK_STACK_SIZE}) too low (<{~1~})
          #endif
                    endm

;*******************************************************************************
; EQU but it also copies the size of the original label
; (a single label is expected as parameter, no expressions)

equ                 macro     Label
                    mset      #
                    mreq      1:Label @~0~ Label
                    mset      0,Label expected, found
          #ifnum ~1~
                    mstop     ~text~ number (~1~)
          #endif
          #ifstr ~1~
                    mstop     ~text~ string (~1~)
          #endif
          #ifnb ~'()[]+-*/\,<>^&|'2~
                    mstop     ~text~ expr (~1~)
          #endif
~label~             set       ~1~,::~1~
                    endm

;*******************************************************************************
; Macro to allocate a variable to #RAM or #XRAM (if XRAM defined) based on size
; [Smaller vars (upto LONG or MaxSizeForRAM) go to #RAM, everything else to #XRAM]

Var                 macro     Size[,MaxSizeForRAM]
          #ifnb ~2~
                    mset      0,~2~               ;;set new MaxSizeForRAM default
            #ifb ~1~
                    mexit                         ;;special case only to define MaxSizeForRAM
            #endif
          #endif
                    mdef      0,4                 ;;startup MaxSizeForRAM default
                    #push
                    #RAM
          #ifdef XRAM                             ;;when XRAM is defined
            #if ~#1~ > ~text~                     ;;anything above ~TEXT~ goes to XRAM
                    #XRAM
            #else if :RAM+~#1~ > RAM_END+1        ;;if RAM is full or not enough, use XRAM
                    #XRAM
            #endif
          #endif
~label~             set       *,~1~
                    rmb       ~1~                 ;~label~
                    #pull
                    endm

;*******************************************************************************

asciz               macro     [Message,]MaxSizeWithoutTrailingZero
                    mset      #','
          #ifstr ~1~
            #if :1-2 > ~2~
                    merror    Message is longer ({:1-2}) than allowed ({~2~})
            #endif
            #if * < EEPROM
                    merror    Can't place constant in RAM
            #endif
                    fcc       ~1~
                    fcb:{~2~-:1+3} 0
                    mexit
          #endif
          #if * < EEPROM
                    rmb       ~1~+1
          #else
                    fcb:{~1~+1} 0
          #endif
          #ifnb ~label~
                    #size     ~label~
          #endif
                    endm

;*******************************************************************************
; Repeat one or more user instructions a given number of times
; Example1:         @rep      #2,lsla,rolx        ;shift left XA twice
; Example2:         @rep      count@@,sp          ;repeat NOP count@@,sp times
;                   nop
;                   mresume

Rep                 macro     [#]Times[,Instruction]*
    #if :n = 1                                    ;;block follows macro
                    mset      #
                    mreq      1:Times
                    #push
                    #spauto   :sp
          #if ::~1,~ <= 1
                    psha                          ;;protect user's A
                    lda       ~1~                 ;;A = counter value
Loop$$$
                    psha                          ;;save current counter
                    lda       2,asp               ;;A = user's A
                    msuspend                      ;;run user code
                    sta       2,asp               ;;save user's A for later
                    pula                          ;;restore current counter
                    dbnza     Loop$$$             ;;one less iteration to go
                    pula                          ;;restore user's A
          #else if ::~1,~ = 2
                    pshhx                         ;;protect user's HX
                    ldhx      ~1~                 ;;HX = counter value
Loop$$$
                    pshhx                         ;;save current counter
                    ldhx      3,asp               ;;HX = user's HX
                    msuspend                      ;;run user code
                    sthx      3,asp               ;;save user's HX for later
                    pulhx                         ;;restore current counter
                    aix       #-1                 ;;one less iteration to go
                    cphx      #0
                    bne       Loop$$$
                    pulhx                         ;;restore user's HX
          #else
                    merror    Unsupported control variable size (~1~: {::~1,~})
          #endif
                    #pull
                    mexit
    #endif
                    mreq      1,2:[#]Times,Instruction[,Instruction]*
          #ifz ~#1~
                    mexit                         ;;nothing to do
          #endif
                    mdo       2
          #ifparm ~{:mloop}.1.2~ = @@             ;;convert @@macro to @macro
                    mset      :mloop,~{:mloop}.2~
          #endif
          #ifparm ~{:mloop}.1.1~ = @              ;;convert @macro to @@macro
                    mset      :mloop,@~{:mloop}.~
          #endif
                    ~{:mloop}.~
                    mloop     :n
                    mtop      ~#1~
                    endm

;*******************************************************************************
; Macro to define local variables (var@@) for an SPAUTO based subroutine
; Format is name[space]bytesize
; (If bytesize not present, size ONE is assumed for all except for pointers.
; By my convention pointer names begin with a point/dot [e.g., .buffer is a
; pointer to 'buffer'].  In this case, the default bytesize is TWO)

Local               macro
                    mreq      1:Name n[,Name n]*
                    @@_needs_spauto_
          ;;--------------------------------------------------------------------
          ;;count total parameters size while formatting as Label<space>Size
          ;;--------------------------------------------------------------------
          #ifnum ~1~
                    #temp     ~1~
          #else
                    #temp
                    mdo
            #ifb ~{:mloop}' '2~
              #ifparm ~{:mloop}.1.1~ = .
                    mset      :mloop,~{:mloop}.~ 2          ;;append default pointer size of two
              #else
                    mset      :mloop,~{:mloop}.~ 1          ;;append default data size of one
              #endif
            #endif
            #ifnonum ~{:mloop}' '2~
              #ifndef ~{:mloop}' '2~
                    merror    Parm {:mloop} \@~{:mloop}' '2~\@ not label[ size]
              #endif
            #endif
                    #temp     :temp+~{:mloop}' '2~
            #if :temp > 127
                    merror    Too much RAM ({:temp}) for locals @{:mloop}
            #endif
                    mloop     :n
          #endif
          ;;--------------------------------------------------------------------
          ;;create local structure
          ;;--------------------------------------------------------------------
                    #push
                    ais       #-{:temp}
                    #pull
                    #spadd    :temp
          #ifnonum ~1~
                    #temp     ::
                    mdo
          #ifparm ~{:mloop}.1.1~ = ?
~{:mloop}' '~       next      :temp,~{:mloop}' '2~  ;;define file local variable
          #else
~{:mloop}' '~@@     next      :temp,~{:mloop}' '2~  ;;define proc local variable
          #endif
                    mloop     :n
          #endif
                    mexit     :ais                ;;return size in :MEXIT
                    endm

;*******************************************************************************
; Macro to define parameters (var@@) passed into an SPAUTO based subroutine
; Format is name[space]bytesize
; (If bytesize not present, size ONE is assumed for all except for pointers.
; By my convention pointer names begin with a point/dot [e.g., .buffer is a
; pointer to 'buffer'].  In this case, the default bytesize is TWO)

Parms               macro
                    mreq      1:Name n[,Name n]*
                    @@_needs_spauto_
          ;;--------------------------------------------------------------------
          ;;Format parameter(s) as Label<space>Size
          ;;--------------------------------------------------------------------
                    mdo
          #ifb ~{:mloop}' '2~
            #ifparm ~{:mloop}.1.1~ = .
                    mset      :mloop,~{:mloop}.~ 2          ;;append default pointer size of two
            #else
                    mset      :mloop,~{:mloop}.~ 1          ;;append default data size of one
            #endif
          #endif
          #ifnonum ~{:mloop}' '2~
            #ifndef ~{:mloop}' '2~
                    merror    Parm {:mloop} \@~{:mloop}' '2~\@ not label[ size]
            #endif
          #endif
                    mloop     :n
          ;;--------------------------------------------------------------------
          ;;define structure
          ;;--------------------------------------------------------------------
                    #temp     1
                    mdo
          #ifparm ~{:mloop}.1.1~ = ?
~{:mloop}' '~       next      :temp,~{:mloop}' '2~  ;;define user parameter (file-local)
          #else
~{:mloop}' '~@@     next      :temp,~{:mloop}' '2~  ;;define user parameter (proc-local)
          #endif
                    mloop     :n
                    mexit     :temp-1             ;;return size in :MEXIT
                    endm

;*******************************************************************************
; Check if we're in SPAUTO mode, and issue a (user defined) warning if not

_needs_spauto_      macro     [optional warning]
          #ifspauto
                    mexit
          #endif
                    mset      #
          #ifb ~1~
                    mstop     #SPAUTO mode required
          #endif
                    #Warning  ~1~
                    endm

;*******************************************************************************
; Checks the passed parameter and issues an error if it is X-indexed
; (This is meant to be called from other macros -- not to be called directly)

_not_x_             macro
                    mset      #' '
          #ifb ~1~
                    mexit                         ;;nothing to do
          #endif
          #ifparm ~'~,1~'.{:1}~ = x
                    #Error    X-index not allowed (~1~)
          #endif
                    mdel      1
                    mtop
                    endm

;*******************************************************************************
; Checks the passed parameter and issues an error if it is SP-indexed
; (This is meant to be called from other macros -- not to be called directly)

_not_sp_            macro
                    mset      #' '
          #ifb ~1~
                    mexit                         ;;nothing to do
          #endif
          #ifparm ~'~,1~'.{:1-1}~ = sp
                    #Error    SP-index not allowed (~1~)
          #endif
                    mdel      1
                    mtop
                    endm

;*******************************************************************************
; Checks the passed parameter and issues an error if it is immediate mode
; (This is meant to be called from other macros -- not to be called directly)

_not_#_             macro
                    mset      #' '
          #ifb ~1~
                    mexit                         ;;nothing to do
          #endif
          #ifparm ~#~
                    #Error    Immediate mode not allowed (~1~)
          #endif
                    mdel      1
                    mtop
                    endm

;*******************************************************************************
; Checks the passed parameter and issues an error if it is NOT immediate mode
; (This is meant to be called from other macros -- not to be called directly)

_#_                 macro
                    mset      #' '
          #ifb ~1~
                    mexit                         ;;nothing to do
          #endif
          #ifb ~#~
                    #Error    Immediate mode expected (~1~)
          #endif
                    mdel      1
                    mtop
                    endm

;*******************************************************************************
; Check if no size info exists for give symbol (parameter)

_nosize_            macro
                    mset      #
                    mset      0,mstop [~00~] No size (~1~)
          #ifnb ~#~
                    ~text~ [immediate]
          #endif
          #ifb ~1,~
                    ~text~ [blank]
          #endif
          #ifnum ~1,~
                    ~text~ [numeric]
          #endif
          #ifndef ~1,~
                    ~text~ [undefined]
          #endif
          #ifz ::~1,~
                    ~text~ [constant]
          #endif
                    endm

;*******************************************************************************
; Check if all given non-immediate mode operands have the same size
; (Skip immediate mode ones, and constants -- labels with size zero)
; (This is meant to be called from other macros -- not to be called directly)

_samesize_          macro     Operand1,Operand2[,Operand]*
                    mreq      1,2:Operand1,Operand2[,Operand]*
                    mset      0
                    mdo
                    mswap     1,{:mloop}
          #ifb ~#~
            #ifnb ~1,~
                    @@_nosize_ ~1~
              #ifb ~text~
                    mset      0,~1~
              #endif
              #if ::~text,~ <> ::~1,~
                    mstop     \@~text~\@ ({::~text,~}) size <> \@~1~\@ ({::~1,~})
              #endif
            #endif
          #endif
                    mloop     :n
                    endm

;*******************************************************************************
; Check if size exists, and optionally if it is one of the expected ones
; (This is meant to be called from other macros -- not to be called directly)

_size_              macro     Label[,ExpectedSize]*
          #ifparm ~#~
                    mexit                         ;;ignore for immediate mode
          #endif
                    @@_nosize_ ~1~
                    mdo       2
          #ifnb ~{:mloop}.~
            #if ::~1,~ = ~{:mloop}.~
                    mexit
            #endif
          #endif
                    mloop     :n
                    mswap     0,1
                    mdel      1
                    mset      #
          #ifnb ~1~
                    mstop     \@~text,~\@ size is {::~text,~}, expected ~1~
          #endif
                    endm

;*******************************************************************************
; Reload HX from RegHx location if the parm specified is X-indexed
; If RegHX location is not specified, the previous one will be used (or error).
; Finally, load HX from the referenced location, regardless of addressing mode.
; (This is meant to be called from other macros -- not to be called directly)

_ldhx_              macro     Parm[ RegHX]
                    mset      #' '
                    mreq      1:Parm[,RegHX]
                    mdef      2,~text~
                    mset      0,~2~               ;;use this as new default
          #ifb ~2~
                    merror    RegHX location is needed 1st time
          #endif
          #ifparm ~'~,1~'.{:1}~ = x               ;for any X-indexed mode
            #ifparm ~,1~ = ,spx                   ;for SPX mode ...
                    tsx                           ;reload stack frame pointer
            #else                                 ;for all others
              #ifhcs
                    ldhx      ~2~                 ;reload original HX
              #else
                    psha
                    lda       ~2~                 ;reload original HX
                    ldx       ~2,~+1~,2~
                    tah
                    pula
              #endif
            #endif
          #endif
                    @lea      ~1~                 ;load actual parameter
                    endm

;*******************************************************************************
; Optional LDA: Do a LDA instruction but only if the parameter is non-blank
; (This is meant to be called from other macros -- not to be called directly)

_lda_               macro
                    mset      #
          #ifb ~1~
                    mexit
          #endif
          #ifparm ~#~
            #!ifz ~#1~
                    clra
                    mexit
            #endif
          #endif
                    lda       ~1~
                    endm

;*******************************************************************************
; Optional STA: Do a STA instruction but only if the parameter is non-blank
; (This is meant to be called from other macros -- not to be called directly)

_sta_               macro
          #ifnb ~@~
                    sta       ~@~
          #endif
                    endm

;*******************************************************************************
; LDA & CMP combo but it optimizes LDA to CLRA
; (This is meant to be called from other macros, but it may be called directly)

_ldacmp_            macro     [#]Operand1,[#]Operand2
          #ifparm ~#~
          #ifdef ~#1~
                    mset      1,~#~{~#1~}
          #endif
          #endif
          #ifparm ~1~ = #0
                    clra
          #else
                    lda       ~1~
          #endif
                    mswap     1,2
          #ifparm ~#~
          #ifdef ~#1~
                    mset      1,~#~{~#1~}
          #endif
          #endif
                    cmpa      ~1~                 ;;needed even when #0 to adjust Carry
                    endm

;*******************************************************************************
; Swap two byte-size variables (does not protect RegA) - Primitive macro
; (This is meant to be called from other macros, but it may be called directly)

_swap_              macro     Variable1 Variable2
                    mset      #' '
                    #push
                    #spauto   :sp
                    lda       ~1~
                    psha
                    lda       ~2~
                    sta       ~1~
                    pula
                    sta       ~2~
                    #pull
                    endm

;*******************************************************************************
; Swap two same-size variables

swap.s              macro     Variable1 Variable2
                    mset      #' '
                    mreq      1,2:Variable1 Variable2
                    @@_samesize_ ~@~
                    #push
                    #spauto   :sp
                    psha
                    mdo
                    @@_swap_  ~1,~+{:mloop-1}~,1~ ~2,~+{:mloop-1}~,2~
                    mloop     ::~1,~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Defines the PullUp Enable label to the left for the given port parameter

PUE                 macro     PortLabel
                    mdef      0,ABCDEFGHIJKLMNOPQRSTUVWXYZ
          #!if PORT~text.{:loop}.1~ = [[~1~
~label~             set       PT~text.{:loop}.1~PUE
                    mexit
          #endif
                    mtop      :text
                    #Undef    ~label~
                    merror    \@~1~\@ does not match any port
                    endm

;*******************************************************************************
; Check if a parameter is pointer

_need_pointer_      macro     pointer_variable
                    mreq      1:pointer_variable
                    mset      0,Pointer (~1~) must be a word variable
          #ifparm ~#~
                    mstop     ~text~
          #else if ::~1,~ <> 2
                    mstop     ~text~
          #endif
          #ifb ~1.1.1~ = .
          #ifb ~1.1.2~ = ?.
          #ifb ~1,~ == _PC_
          #ifb ~1.1.2~ == pc
                    #Hint     By convention, start pointers with dot (~1~ => .~1~)
          #endif
          #endif
          #endif
          #endif
                    endm

;*******************************************************************************
; Get A from the location pointed to by the parm, while bumping up that pointer

GetNextA            macro     Pointer [DoneOnZero]
                    mset      #' '
                    @@_need_pointer_ ~1~
                    @@_not_x_ ~@~
          #ifhcs
                    ldhx      ~1~
                    lda       ,x
            #ifnb ~2~
                    beq       ~2~
            #endif
                    aix       #1
                    sthx      ~1~
          #else
                    #push
                    #spauto   :sp
                    ldx       ~1~
                    pshx
                    ldx       ~1,~+1~,1~
                    pulh
                    lda       ,x
            #ifnb ~2~
                    beq       ~2~
            #endif
                    aix       #1
                    stx       ~1,~+1~,1~
                    pshx
                    thx
                    stx       ~1~
                    pulx
                    #pull
          #endif
                    endm

;*******************************************************************************
; Put A into the location pointed to by the parm, while bumping up that pointer

PutNextA            macro     Pointer [DoneOnZero]
                    mset      #' '
                    @@_need_pointer_ ~1~
                    @@_not_x_ ~1~
          #ifhcs
                    ldhx      ~1~
                    sta       ,x
            #ifnb ~2~
                    beq       ~2~
            #endif
                    aix       #1
                    sthx      ~1~
          #else
                    #push
                    #spauto   :sp
                    ldx       ~1~
                    pshx
                    ldx       ~1,~+1~,1~
                    pulh
                    sta       ,x
            #ifnb ~2~
                    beq       ~2~
            #endif
                    aix       #1
                    stx       ~1,~+1~,1~
                    pshx
                    thx
                    stx       ~1~
                    pulx
                    #pull
          #endif
                    endm

;*******************************************************************************
; AIX but only for non-zero values.  Transparent in #MCF mode.
; Automatically splits offset into as many AIX as needed.  If the number of
; bytes required is bigger than ADDHX size, it uses a single ADDHX instead.

aix                 macro     #OffsetConstant
          #ifz ~#1~
                    mexit
          #endif
     #if ~#1~ < 0
          #if ~#1~ >= -768
          #ifnz ~#1~/128
                    !aix:{~#1~/128^$FF+1&$FF} #-128  ;same as aix:-(~1~/128) #-128
          #endif
          #ifnz ~#1~\128
                    !aix      #{~#1~\128}
          #endif
                    mexit
          #endif
                    addhx     #~#1~
                    mexit
     #endif
          #if ~#1~ <= 762
          #ifnz ~#1~/127
                    !aix:{~#1~/127} #127
          #endif
          #ifnz ~#1~\127
                    !aix      #{~#1~\127}
          #endif
                    mexit
          #endif
                    addhx     #~#1~
                    endm

;*******************************************************************************
; Make HX point to given stack element (only when in #SP[AUTO] modes)

StackPtr            macro     StackLabel
                    mreq      1:StackLabel
          #ifnz ~#1~+:tsx
                    !aix      #~#1~+:tsx
          #endif
                    endm

;*******************************************************************************
; Load Effective Address in RegHX

lea                 macro
                    mset      #
          #ifb ~1~
                    mexit                         ;;no parm, nothing to do
          #endif
          #ifparm ~#~
                    ldhx      ~1~                 ;;immediate value load as is
                    mexit
          #endif
          #ifparm ~1.1.1~ = .                     ;;dot-beginning symbols treat as pointers
            #ifhcs
                    ldhx      ~1~
            #else
                    psha
                    lda       ~[1.-1]~
                    ldx       ~[1.-2]~
                    tah
                    pula
            #endif
                    mexit
          #endif
          #ifparm ~1.1.2~ = ?.                    ;;dot-beginning file-local symbols treat as pointers
            #ifhcs
                    ldhx      ~1~
            #else
                    psha
                    lda       ~[1.-1]~
                    ldx       ~[1.-2]~
                    tah
                    pula
            #endif
                    mexit
          #endif
    #ifparm ~,1~                                  ;;indexed modes
          #ifparm ~,1~ = ,sp                      ;;SP case treat specially
                    tsx
              #ifnz ~1,~+:tsx
                    !aix      #~1,~+:tsx
              #endif
                    mexit
          #endif
          #ifparm ~,1~ = ,spx                     ;;SPX case treat specially
                    tsx
              #ifnz ~1,~+:tsx
                    !aix      #~1,~+:tsx
              #endif
                    mexit
          #endif
          #ifparm ~,1~ = ,psp                     ;;PSP case treat specially
                    tsx
              #ifnz ~1,~+{:psp-1}
                    !aix      #~1,~+{:psp-1}
              #endif
                    mexit
          #endif
          #ifparm ~,1~ = ,x
            #ifnb ~1,~
                    @aix      #~1,~               ;;X-indexed add possible offset
            #endif
                    mexit
          #endif
          #ifparm ~,1~ = ,ax
            #ifnb ~1,~
                    @aix      #~1,~               ;;X-indexed add possible offset
            #endif
                    mexit
          #endif
          #ifhcs
                    ldhx      ~1~                 ;;any other index treat as pointer (regardless of name convention)
          #else
                    psha
                    lda       ~[1.-1]~
                    ldx       ~[1.-2]~
                    tah
                    pula
          #endif
                    mexit
    #endif
                    ldhx      #~1~                ;;everything else is fixed RAM
                    endm

;*******************************************************************************
; Find the Greatest Common Divisor (GCD) of two constants.
; Answer is placed in LABEL (if present) and :MEXIT variable

gcd                 macro     a,b
          #ifz ~1~
                    mexit     1
          #else ifz ~2~
                    mexit     1
          #endif
          #if ~1~ = ~2~
              #ifparm ~label~
~label~             set       ~1~
              #endif
                    mexit     ~1~
          #else if ~1~ > ~2~
                    mset      1,{~1~-{~2~}}
                    mtop
          #endif
                    mset      2,{~2~-{~1~}}
                    mtop
                    endm

;*******************************************************************************
; Find the Least Common Multiple (LCM) of two constants. Prerequisite macro: GCD
; Note: To avoid overflow, first divides, then multiplies. GCD certainly divides
;       both numbers, so no problem doing so, and it's more efficient.
;       Answer is placed in LABEL (if present) and :MEXIT variable

lcm                 macro     a,b
                    @@gcd     ~@~
          #ifparm ~label~
~label~             set       {~1~}/:mexit*{~2~}
          #endif
                    mexit     {~1~}/:mexit*{~2~}
                    endm

;*******************************************************************************
; Vector assignment
; (Places vector in #VECTORS segment, then returns to current segment)

Vector              macro     Vvector,ISR_Address
          #ifb ~2~
            #ifndef ~1~
              #ifdef ...
                    #Hint     Missing \@~1~\@ vector ignored
              #endif
                    mexit                         ;avoids error on empty but undefined vectors
            #endif
          #endif
                    mdef      2,AnRTI
                    #push
                    #VECTORS
                    #ppc
          #ifdef OS8PRELOADED&RVECTORS
                    org       ~1~-VECTORS+RVECTORS
          #else
                    org       ~1~
          #endif
                    dw        ~2~
                    org       :ppc
                    #pull
                    endm

;*******************************************************************************
; PUSH any variable onto the stack. If 'newname' given the variable will then be
; assigned the name inside the string.
; Constants require a size as it cannot be determined automatically.
; (All registers may be destroyed)

PushV               macro     variable[ SizeOf(var)][ 'newname']
                    mset      #' '
                    mset      0                   ;;cancel any stack names
                    mreq      1:variable[ SizeOf(var)][ 'newname']
          #ifstr ~{:nn}.~                         ;;if last parm is a string
                    mset      0,~{:nn}.~          ;;it is the stack name
                    mset      0,~text.2.{:text-2}~ ;;after removing quotes
                    mdel      :nn                 ;;parm no longer needed
          #endif
          #ifb ~2~
                    #temp     1
            #ifnum ~1,~
                    #temp
            #endif
            #ifb ~1,~
                    #temp
            #endif
            #ifz :temp
                    #Warning  Zero size \@~1~\@
            #endif
          #endif
          #ifnb ~#~                               ;;immediate mode
                    mreq      1,2:Constant SizeOf(Constant)
            #if ~2~ < 0
                    merror    Negative size (~1~): ~2~
            #endif
            #ifnb ~text~
                    mset      0,~text~,~2~
            #endif
                    #temp
                    mdo
            #ifz ~#1~>{:mloop-1*8}&$FF
              #ifz :temp
                    #temp     1
                    clra
              #endif
            #else
                    #temp
                    lda       ~1~>{:mloop-1*8}&$FF
            #endif
            #if :mloop = ~2~
                    psha      ~text~
            #else
                    psha
            #endif
                    mloop     ~2~
            #if ~#1~ >= 0
              #ifnz ~#1~>{:mloop*8}
                    merror    Constant ~#1~ ({~#1~}) bigger than ~2~ byte(s)
              #endif
            #else
              #ifnz -{~#1~(h)}>{:mloop*8-1}
                    merror    Constant ~#1~ ({~#1~}) bigger than ~2~ byte(s)
              #endif
            #endif
                    @@Msg     ~0~ ~1~ ({~2~*8}-bit)
                    mexit
          #endif
          #ifnb ~1,~
            #ifnz ::~1,~
                    mdef      2,{::~1,~}
            #endif
          #endif
                    mdef      2,1
          #if ~2~ < 0
                    merror    Negative size (~1~): ~2~
          #endif
                    @@Msg     ~0~ ~1~ ({~2~*8}-bit)
                    #ifnb ~text~
                    mset      0,~text~,~2~
                    #endif
          #if ~2~ = 1                             ;;single-byte variable case
            #ifb ~1.1.1~ = .                      ;;but not for pointers
              #ifparm ~'~,1~'.1.3~ = ,sp          ;;for SP and SPX only
                #iftos ~1,~                       ;;if at TOS, special case
                    pula                          ;;A = TOS value
                    psha                          ;;put it back the way it was
                    psha      ~text~
                    mexit
                #endif
              #endif
                    lda       ~1~
                    psha      ~text~
                    mexit
            #endif
          #endif
                    #push                         ;;save current X offset etc.
          #ifb ~,1~ = ,x                          ;;only if not X-indexed
                    @@lea     ~1~                 ;;HX -> variable
                    #x                            ;;zero X offsets
          #else
                    #x        ~1,~                ;;make use of offset
          #endif
                    mdo
                    lda       {~2~-:mloop},x
          #if :mloop = ~2~
                    psha      ~text~
          #else
                    psha
          #endif
                    mloop     ~2~
                    #pull                         ;;restore current X offset etc.
          #ifspauto
                    #spadd    ~2~                 ;;needed because of #PUSH/#PULL
          #endif
                    endm

;*******************************************************************************
; PULL any variable from the stack. If size is missing, size one is assumed.
; (All registers may be destroyed)

PullV               macro     Variable[ SizeOf(Variable)]
                    mset      #' '
                    mreq      1:Variable[ SizeOf(Variable)]
                    @@_not_#_ ~1~
          #ifb ~2~
                    #temp     1
            #ifnum ~1,~
                    #temp
            #endif
            #ifb ~1,~
                    #temp
            #endif
            #ifz :temp
                    #Warning  Zero size \@~1~\@
            #endif
          #endif
          #ifnz ::~1,~
                    mdef      2,{::~1,~}
          #endif
                    mdef      2,1
          #if ~2~ < 0
                    merror    Negative size (~1~): ~2~
          #endif
                    @@Msg     ~0~ ~1~ ({~2~*8}-bit)
          #if ~2~ = 1                             ;;single-byte variable case
            #ifb ~1.1.1~ = .                      ;;but not for pointers
              #ifparm ~'~,1~'.1.3~ = ,sp          ;;for SP and SPX only
                #iftos ~1,~                       ;;if at TOS, special case
                    mstop     ~0~ to same stack location!
                #endif
              #endif
                    pula
                    sta       ~1~
                    mexit
            #endif
          #endif
                    #push                         ;;save current X offset etc.
          #ifb ~,1~ = ,x                          ;;only if not X-indexed
                    @@lea     ~1~                 ;;HX -> variable
                    #x                            ;;zero X offsets
          #else
                    #x        ~1,~                ;;make use of offset
          #endif
                    mdo
                    pula
                    sta       {:mloop-1},x
                    mloop     ~2~
                    #pull                         ;;restore current X offset etc.
          #ifspauto
                    #spadd    -~2~                ;;needed because of #PUSH/#PULL
          #endif
                    endm

;*******************************************************************************
; A group of macros for use with any sized variable
;*******************************************************************************

;*******************************************************************************
; Clear any sized variable up to 256 bytes without preserving HX

_ClrVar_            macro     Variable
                    clrh
                    ldx       #::~1~
Loop$$$
                    clr       ~1~-1,ax
                    dbnzx     Loop$$$
                    endm

;*******************************************************************************
; Clear any sized variable

ClrVar              macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
          #ifb ~,1~
                    mset      1,~#1~
            #if ::~1,~ < 256
              #ifz ]{~1~-1}
                    pshhx
                    @@_ClrVar_ ~1~
                    pulhx
                    mexit
              #endif
            #endif
                    pshhx
                    ldhx      #~1~+::~1~
Loop$$$
                    aix       #-1
                    clr       ,ax
                    cphx      #~1~
                    bne       Loop$$$
                    pulhx
                    mexit
          #endif
          #if ::~1,~ <= 8
            #ifnb ~,1~
                    @clr.s    ~1~
                    mexit
            #endif
          #endif
                    #push
                    #spauto   :sp
                    push
                    lda       #::~1,~
                    @@lea     ~1~
Loop$$$
                    clr       ,ax
                    aix       #1
                    dbnza     Loop$$$
                    pull
                    #pull
                    endm

;*******************************************************************************
; Test for zero for any sized variable (current version leaves CCR[N] invalid)

_tst_.s             macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
          #if ::~1,~ = 1
            #ifz ]~1,~
                    tst       ~1~
                    mexit
            #endif
          #endif
                    mdo
          #if :mloop = 1
                    lda       ~1,~+{:mloop-1}~,1~
          #else
                    ora       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; TST for any sized variable (current version leaves CCR[N] invalid)

tst.s               macro     Operand
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
          #if ::~1,~ = 1
            #ifz ]~1,~
                    tst       ~1~
                    mexit
            #endif
          #endif
                    #push
                    #spauto   :sp
                    psha
                    mdo
          #if :mloop = 1
                    lda       ~1,~+{:mloop-1}~,1~
          #else
                    ora       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ::~1,~
                    pula
                    #pull
                    endm

;*******************************************************************************
; CLR for any sized variable

clr.s               macro     Variable [Size]
                    mset      #' '
                    mreq      1
          #ifb ~2~
                    @@_nosize_ ~1~
          #endif
                    mdef      2,::~1,~
          #ifb ~,1~
          #ifnz ]~1~
                    #push
                    #spauto   :sp
                    psha
                    clra
                    mdo
                    sta       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~
                    pula
                    #pull
                    mexit
          #endif
          #endif
                    mdo
                    clr       ~1,~+{:mloop-1}~,1~
                    mloop     ~2~
                    endm

;*******************************************************************************
; INC for any sized variable

inc.s               macro     Variable [Branch]
                    mset      #' '
                    mreq      1
                    mdef      2,Done$$$
                    @@_nosize_ ~1~
                    mdo
                    inc       ~1,~+{::~1,~-:mloop}~,1~
          #if :mloop <> ::~1,~
                    bne       ~2~
          #endif
                    mloop     ::~1,~
Done$$$
                    endm

;*******************************************************************************
; DEC (simulation) for any sized variable.

dec.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
                    #push
                    #spauto   :sp
                    psha
                    @@sub.s   ~1~ #1 ~1~
                    @@_cmp_.s ~1~ #0
                    pula
                    #pull
                    endm

;*******************************************************************************
; COM for any sized variable

com.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
          #ifb ~,1~
          #ifnz ]~1~
                    #push
                    #spauto   :sp
                    psha
                    mdo
                    lda       ~1,~+{:mloop-1}~,1~
                    coma
                    sta       ~1,~+{:mloop-1}~,1~
                    mloop     {::~1,~}
                    pula
                    #pull
                    mexit
          #endif
          #endif
                    mdo
                    com       ~1,~+{:mloop-1}~,1~
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; ABS for any sized variable

abs.s               macro     Variable
                    mset      #
                    mreq      1:Variable
                    @@tst.b   ~1~
                    bpl       Done$$$
                    @@neg.s   ~1~
Done$$$
                    endm

;*******************************************************************************
; NEG for any sized variable

neg.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
          #if ::~1,~ > 1
                    mdo
                    com       ~1,~+{:mloop-1}~,1~
                    mloop     ::~1,~-1
          #endif
                    neg       ~1,~+{::~1,~-1}~,1~
          #if ::~1,~ > 1
                    mdo
                    bne       Done$$$
                    inc       ~1,~+{::~1,~-:mloop-1}~,1~
                    mloop     ::~1,~-1
Done$$$
          #endif
                    endm

;*******************************************************************************
; MOV for any sized variable (simpler version that does not test MSB)

move.s              macro     [#]Source Destination
                    mset      #' '
                    mreq      1,2:[#]Source Destination
          #ifnb ~2~ = x+
                    @@_nosize_ ~1~
                    #temp     ::~1,~
          #else
                    @@_nosize_ ~2~
                    #temp     ::~2,~
          #endif
                    mdo
          #ifnb ~#~
                    mov       ~1~>{:temp-:mloop*8}&$FF,~2~+{:mloop-1}
          #else ifnb ~1~ = x+
                    mov       x+,~2~+{:mloop-1}             ;;special X+, case
          #else ifnb ~2~ = x+
                    mov       ~1~+{:mloop-1},x+             ;;special ,X+ case
          #else
              #if :mloop = 1
                    @@_samesize_ ~@~
              #endif
                    mov       ~1~+{:mloop-1},~2~+{:mloop-1}
          #endif
                    mloop     :temp
                    endm

;*******************************************************************************
; MOV for any sized variable (but also tests MSB for negative)

mov.s               macro     [#]Source Destination
                    mset      #' '
                    @@move.s  ~@~
          #ifnb ~2~ = x+
            #if ::~1,~ < 2
                    mexit                         ;;single byte var, no need for TST
            #endif
                    tst       ~1~                 ;;var,x+ case
                    mexit
          #endif
          #if ::~2,~ < 2
                    mexit                         ;;single byte var, no need for TST
          #endif
                    tst       ~2~                 ;;all other cases
                    endm

;*******************************************************************************
; MOVA for any sized variable

mova.s              macro     [#]Source Destination
                    mset      #' '
                    mreq      1,2:Source Destination
          #ifb ~#~
                    @@_samesize_ ~@~
          #else
                    @@_nosize_ ~2~
          #endif
                    mset      0                   ;;no CLRA used
                    mdo
          #ifnb ~#~
                    #temp                         ;;no optimization
            #!ifz ~#1~>{::~2,~-:mloop*8}&$FF
                #ifb ~text~
                    clra
                #endif
                    mset      0,clra              ;;CLRA used
                    #temp     1                   ;;optimization
            #endif
            #ifz :temp                            ;;if no optimization
                    lda       ~1~>{::~2,~-:mloop*8}&$FF
                    mset      0                   ;;no CLRA used
            #endif
          #else
                    lda       ~1,~+{:mloop-1}~,1~
          #endif
                    sta       ~2,~+{:mloop-1}~,2~
                    mloop     ::~2,~
                    endm

;*******************************************************************************
; MOVX emulation of a hypothetical instruction that will use the same X-index to
;      move a single byte from source X-offset to dest X-offset and advance the
;      HX index afterwards. It will behave as an atomic instruction.
; Example:          clrhx
;                   lda       #10                 ;number of bytes to copy
; Loop@@            @movx     EEPROM,RAM
;                   dbnza     Loop@@

movx                macro     source_offset,destination_offset
                    @@_not_x_ ~1~ ~2~
                    @@_not_sp_ ~1~ ~2~
                    psha
                    tpa
                    psha
                    sei
                    lda       ~#1~,x
                    sta       ~#2~,x
                    aix       #1
                    pula
                    tap
                    pula
                    endm

;*******************************************************************************
; Copy for any sized variable

copy.s              macro
                    mset      #' '
                    #push
                    #spauto   :sp
                    psha
                    @@mova.s  ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; LSL for any sized variable

lsl.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
                    mdo
          #if :mloop = 1
                    lsl       ~1,~+{::~1,~-:mloop}~,1~
          #else
                    rol       ~1,~+{::~1,~-:mloop}~,1~
          #endif
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; LSR for any sized variable

lsr.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
                    mdo
          #if :mloop = 1
                    lsr       ~1,~+{:mloop-1}~,1~
          #else
                    ror       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; ASR for any sized variable

asr.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
                    mdo
          #if :mloop = 1
                    asr       ~1,~+{:mloop-1}~,1~
          #else
                    ror       ~1,~+{:mloop-1}~,1~
          #endif
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; ROR for any sized variable

ror.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
                    mdo
                    ror       ~1,~+{:mloop-1}~,1~
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; ROL for any sized variable

rol.s               macro     Variable
                    mset      #
                    mreq      1
                    @@_nosize_ ~1~
                    mdo
                    rol       ~1,~+{::~1,~-:mloop}~,1~
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; ADD bytes
; Note: No destination required if you only need to add in RegA

add.b               macro     [#]Operand1,[#]Operand2[,Destination]
          #ifparm ~#~
            #ifdef ~#1~
                    mset      1,~#~{~#1~}
            #endif
          #endif
                    mswap     1,2
          #ifparm ~#~
            #ifdef ~#1~
                    mset      1,~#~{~#1~}
            #endif
          #endif
                    mswap     1,2
          #ifparm ~1~~2~ = #0#0
                    clra
                    @_sta_    ~3~
                    mexit
          #endif
          #ifparm ~1~ = #0
                    lda       ~2~
                    @_sta_    ~3~
                    mexit
          #endif
          #ifparm ~2~ = #0
                    lda       ~1~
                    @_sta_    ~3~
                    mexit
          #endif
                    lda       ~1~
                    add       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; ADD bytes with Carry
; Note: No destination required if you only interested in the Carry flag

adc.b               macro     [#]Operand1,[#]Operand2[,Destination]
          #ifparm ~#~
            #ifdef ~#1~
                    mset      1,~#~{~#1~}
            #endif
          #endif
                    mswap     1,2
          #ifparm ~#~
            #ifdef ~#1~
                    mset      1,~#~{~#1~}
            #endif
          #endif
                    mswap     1,2
          #ifparm ~1~ = #0
                    clra
                    adc       ~2~
                    @_sta_    ~3~
                    mexit
          #endif
          #ifparm ~2~ = #0
                    clra
                    adc       ~1~
                    @_sta_    ~3~
                    mexit
          #endif
                    lda       ~1~
                    adc       ~2~
                    @_sta_    ~3~
                    endm

;*******************************************************************************
; ADD for any sized variable

add.s               macro     [#]Operand1 [#]Operand2 Destination
                    mset      #' '
                    mreq      1,2,3:[#]Operand1 [#]Operand2 Destination
                    @@_samesize_ ~@~
                    mset      0,@@add.b,          ;;first time, do an ADD
                    mdo
          #ifparm ~#~
                    mset      0,~text~ ~1~>{:mloop-1*8}&$FF
          #else
                    mset      0,~text~ ~1,~+{::~3,~-:mloop}~,1~
          #endif
          #ifparm ~2.1.1~ = #
                    mset      0,~text~ ~2~>{:mloop-1*8}&$FF
          #else
                    mset      0,~text~ ~2,~+{::~3,~-:mloop}~,2~
          #endif
                    mset      0,~text~ ~3,~+{::~3,~-:mloop}~,3~
                    ~text~
                    mset      0,@@adc.b,          ;;next time(s), do an ADC
                    mloop     ::~3,~
                    endm

;*******************************************************************************
; SUB for any sized variable

sub.s               macro     [#]Operand1 [#]Operand2 Destination
                    mset      #' '
                    mreq      1,2:[#]Operand1 [#]Operand2 Destination
                    @@_samesize_ ~@~
                    #temp
          #ifb ~3~
                    @@_nosize_ ~1~
                    #temp     ::~1,~
          #else
                    @@_nosize_ ~3~
                    #temp     ::~3,~
          #endif
                    mset      0,sub               ;;first time, do a SUB
                    mdo
          #ifparm ~#~
                    lda       ~1~>{:mloop-1*8}&$FF
          #else
                    lda       ~1,~+{:temp-:mloop}~,1~
          #endif
          #ifparm ~2.1.1~ = #
                    ~text~    ~2~>{:mloop-1*8}&$FF
          #else
                    ~text~    ~2,~+{:temp-:mloop}~,2~
          #endif
          #ifnb ~3~
                    sta       ~3,~+{:temp-:mloop}~,3~
          #endif
                    mset      0,sbc               ;;next time(s), do a SBC
                    mloop     :temp
                    endm

;*******************************************************************************
; AND for any sized variable

and.s               macro     [#]Operand1 [#]Operand2 Destination
                    mset      #' '
                    mreq      1,2,3:[#]Operand1 [#]Operand2 Destination
                    @@_samesize_ ~@~
                    mdo
          #ifnb ~#~
                    @@_lda_   ~1~>{::~3,~-:mloop*8}&$FF
          #else
                    lda       ~1,~+{:mloop-1}~,1~
          #endif
          #ifnb ~2.1.1~ = #
                    and       ~2~>{::~3,~-:mloop*8}&$FF
          #else
                    and       ~2,~+{:mloop-1}~,2~
          #endif
                    sta       ~3,~+{:mloop-1}~,3~
                    mloop     ::~3,~
                    endm

;*******************************************************************************
; OR for any sized variable

ora.s               macro     [#]Operand1 [#]Operand2 Destination
                    mset      #' '
                    mreq      1,2,3:[#]Operand1 [#]Operand2 Destination
                    @@_samesize_ ~@~
                    mdo
          #ifnb ~#~
                    @@_lda_   ~1~>{::~3,~-:mloop*8}&$FF
          #else
                    lda       ~1,~+{:mloop-1}~,1~
          #endif
          #ifnb ~2.1.1~ = #
                    ora       ~2~>{::~3,~-:mloop*8}&$FF
          #else
                    ora       ~2,~+{:mloop-1}~,2~
          #endif
                    sta       ~3,~+{:mloop-1}~,3~
                    mloop     ::~3,~
                    endm

;*******************************************************************************
; XOR for any sized variable

eor.s               macro     [#]Operand1 [#]Operand2 Destination
                    mset      #' '
                    mreq      1,2,3:[#]Operand1 [#]Operand2 Destination
                    @@_samesize_ ~@~
                    mdo
          #ifnb ~#~
                    @@_lda_   ~1~>{::~3,~-:mloop*8}&$FF
          #else
                    lda       ~1,~+{:mloop-1}~,1~
          #endif
          #ifnb ~2.1.1~ = #
                    eor       ~2~>{::~3,~-:mloop*8}&$FF
          #else
                    eor       ~2,~+{:mloop-1}~,2~
          #endif
                    sta       ~3,~+{:mloop-1}~,3~
                    mloop     ::~3,~
                    endm

;*******************************************************************************
; CMP for any sized variable (without protecting RegA)
; (This is meant to be called from other macros, but it may be called directly)

_cmp_.s             macro     [#]Operand1 [#]Operand2
                    mset      #' '
                    mreq      1,2:[#]Operand1 [#]Operand2
                    @@_samesize_ ~@~
          #ifparm ~1.1.1~~2.1.1~ = ##
                    mset      #
                    mstop     Both operands are immediate! \@~1~\@
          #endif
                    #temp     1
          #ifb ~#~
                    #temp     ::~1,~
          #endif
          #ifb ~2.1.1~ = #
                    #temp     ::~2,~
          #endif
                    mdo
          #ifnb ~#~
                    @@_lda_   ~1~>{:temp-:mloop*8}&$FF
          #else
                    lda       ~1,~+{:mloop-1}~,1~
          #endif
          #ifnb ~2.1.1~ = #
                    cmpa      ~2~>{:temp-:mloop*8}&$FF      ;;needed even if #0 to adjust Carry
          #else
                    cmpa      ~2,~+{:mloop-1}~,2~
          #endif
          #if :mloop <> :temp
                    bne       Done$$$
          #endif
                    mloop     :temp
Done$$$
                    endm

;*******************************************************************************
; CMP for any sized variable

cmp.s               macro     [#]Operand1 [#]Operand2
                    mset      #' '
                    #push
                    #spauto   :sp
                    psha
                    @@_cmp_.s ~@~
                    pula
                    #pull
                    endm

;*******************************************************************************
; DIV for any sized variable (HX assumed already set with appropriate values)
; Optionally, the 8-bit divisor can be provided as second argument

div.s               macro     Variable [[#]divisor8]
                    mset      #' '
                    mreq      1
                    @@_not_x_ ~1~
                    @@_nosize_ ~1~
          #ifnb ~2~
                    ldx       ~2~
                    clrh
          #endif
                    #temp     1
          #ifnb ~'~,1~'.1.3~ = ,sp                ;;sees SP or SPX index
            #iftos ~1,~
                    #temp     2
                    pula
                    div
                    psha
              #if ::~1,~ = 1
                    mexit
              #endif
            #endif
          #endif
                    mdo       {:temp}
                    lda       ~1,~+{:mloop-1}~,1~
                    div
                    sta       ~1,~+{:mloop-1}~,1~
                    mloop     ::~1,~
                    endm

;*******************************************************************************
; A general-purpose FOR loop wrapper
; Limits : Start, Stop and Step (if not immediate) have to match size of
;        : ControlVar (or you will get an error)
; Note(s): Use FORS for signed version
;        : Negative steps not allowed (will be treated as positive)
; Example: FOR i 1 5 ... MRESUME (where i is any variable declared earlier)

fors                macro     ControlVar [#]Start [#]Stop[ [#]PositiveStep]
                    mset      #
                    @for      ~1~
                    endm
;-------------------------------------------------------------------------------
for                 macro     ControlVar [#]Start [#]Stop[ [#]PositiveStep]
                    mset      #' '
                    mreq      1,2,3:ControlVar [#]Start [#]Stop[ [#]PositiveStep]
                    mdef      4,#1                ;;default step is one
                    @@_nosize_  ~1~               ;;need sized control variable
                    #temp     ::~1,~
                    mdo       2
          #ifnum ~{:mloop}.~
                    mset      :mloop,#~{:mloop}.~
          #endif
                    mloop     4
                    @@_samesize_ ~@~
                    @@copy.s  ~2~ ~1~
Loop$$$
                    @@cmp.s   ~1~ ~3~
          #ifparm ~00~ = fors
                    !jgt      Done$$$             ;;signed version (FORS)
          #else
                    !jhi      Done$$$             ;;unsigned version (FOR)
          #endif
                    msuspend
                    #push
                    #spauto   :sp
                    psha
                    @@add.s   ~1~ ~4~ ~1~
                    pula
                    #pull
                    !jmp      Loop$$$
Done$$$
                    endm

;*******************************************************************************
; Show the current value and size of the specified symbol(s)

ShowSym             macro     Symbol[,Symbol]*
                    #Message  --------------------------------------------------
                    mdo
                    mswap     1,:mloop
          #ifdef ~1~
                    #Message  Symbol \@~1~\@~'...................'.1.{20-:1}~ {~1~} (size: {::~1~})
          #endif
                    mloop     :n
                    endm

;*******************************************************************************
; Find the minimum value of the given symbol(s)

_MinSymbolValue_    macro     ConstExpr[,ConstExpr]*
                    mreq      1:ConstExpr[,ConstExpr]*
                    #temp     -1
                    mdo
                    mswap     1,:mloop
          #ifdef ~1~
            #if :mloop = 1
                    #temp     ~1~
            #endif
            #if ~1~ < :temp
                    #temp     ~1~
            #endif
          #endif
                    mloop     :n
                    mexit     :temp
                    endm

;*******************************************************************************
; BSET for Pin names without protection of RegA

_bset_              macro     PinName
                    mset      #','
          #ifparm ~2~
            #!ifnz ]~2~
                    lda       ~2~
              #ifnum ~1~
                    ora       #1<~1~
              #else
                #ifdef ~1'.'~_
                    ora       #~1'.'~_
                #else
                    ora       #@~1'.'~
                #endif
              #endif
                    sta       ~2~
                    mexit
            #endif
                    !bset     ~@~
                    mexit
          #endif
          #ifz [[~1~&$FFFFFF00
            #ifdef ~1~.
                    !bset     ~1~.,~1~
            #else
                    !bset     ~1~
            #endif
                    mexit
          #endif
                    lda       ~1~
          #ifdef ~1~_
                    ora       #~1~_
          #else
                    ora       #@~1~
          #endif
                    sta       ~1~
                    endm

;*******************************************************************************
; BCLR for Pin names without protection of RegA

_bclr_              macro     PinName
                    mset      #','
          #ifparm ~2~
            #!ifnz ]~2~
                    lda       ~2~
              #ifnum ~1~
                    and       #1<~1~^$FF
              #else
                #ifdef ~1'.'~_
                    and       #~1'.'~_^$FF
                #else
                    and       #@~1'.'~^$FF
                #endif
              #endif
                    sta       ~2~
                    mexit
            #endif
                    !bclr     ~@~
                    mexit
          #endif
          #ifz [[~1~&$FFFFFF00
            #ifdef ~1~.
                    !bclr     ~1~.,~1~
            #else
                    !bclr     ~1~
            #endif
                    mexit
          #endif
                    lda       ~1~
          #ifdef ~1~_
                    and       #~1~_^$FF
          #else
                    and       #@~1~^$FF
          #endif
                    sta       ~1~
                    endm

;*******************************************************************************
; BSET for Pin names

bset                macro     PinName
                    mset      #','
          #ifparm ~2~
            #!ifnz ]~2~
                    psha
                    lda       ~2~
              #ifnum ~1~
                    ora       #1<~1~
              #else
                #ifdef ~1'.'~_
                    ora       #~1'.'~_
                #else
                    ora       #@~1'.'~
                #endif
              #endif
                    sta       ~2~
                    pula
                    mexit
            #endif
                    !bset     ~@~
                    mexit
          #endif
          #ifz [[~1~&$FFFFFF00
            #ifdef ~1~.
                    !bset     ~1~.,~1~
            #else
                    !bset     ~1~
            #endif
                    mexit
          #endif
                    psha
                    lda       ~1~
          #ifdef ~1~_
                    ora       #~1~_
          #else
                    ora       #@~1~
          #endif
                    sta       ~1~
                    pula
                    endm

;*******************************************************************************
; BCLR for Pin names

bclr                macro     PinName
                    mset      #','
          #ifparm ~2~
            #!ifnz ]~2~
                    psha
                    lda       ~2~
              #ifnum ~1~
                    and       #1<~1~^$FF
              #else
                #ifdef ~1'.'~_
                    and       #~1'.'~_^$FF
                #else
                    and       #@~1'.'~^$FF
                #endif
              #endif
                    sta       ~2~
                    pula
                    mexit
            #endif
                    !bclr     ~@~
                    mexit
          #endif
          #ifz [[~1~&$FFFFFF00
            #ifdef ~1~.
                    !bclr     ~1~.,~1~
            #else
                    !bclr     ~1~
            #endif
                    mexit
          #endif
                    psha
                    lda       ~1~
          #ifdef ~1~_
                    and       #~1~_^$FF
          #else
                    and       #@~1~^$FF
          #endif
                    sta       ~1~
                    pula
                    endm

;*******************************************************************************
;BRSET for Pin names

brset               macro     PinName,Address
                    mset      #','
          #ifparm ~3~
                    !brset    ~@~
                    mexit
          #endif
          #ifz [[~1~&$FFFFFF00
            #ifdef ~1~.
                    !brset    ~1~.,~1~,~2~
            #else
                    !brset    ~1~,~2~
            #endif
                    mexit
          #endif
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    psha
                    lda       ~1~
          #ifdef ~1~_
                    and       #~1~_
          #else
                    and       #@~1~
          #endif
                    pula
                    bne       ~2~
                    endm

;*******************************************************************************
; BRCLR for Pin names

brclr               macro     PinName,Address
                    mset      #','
          #ifparm ~3~
                    !brclr    ~@~
                    mexit
          #endif
          #ifz [[~1~&$FFFFFF00
            #ifdef ~1~.
                    !brclr    ~1~.,~1~,~2~
            #else
                    !brclr    ~1~,~2~
            #endif
                    mexit
          #endif
          #ifparm ~2~ = *
                    mset      2,{*}
          #endif
                    psha
                    lda       ~1~
          #ifdef ~1~_
                    and       #~1~_
          #else
                    and       #@~1~
          #endif
                    pula
                    beq       ~2~
                    endm

;*******************************************************************************
; Adds a new OS call to table

AddOS               macro     Name[,AlternateLocalName]
                    #temp     :index
                    mdef      2,?~1~
                    #push
                    #ROM
          #ifdef HighRegs&HighRegs_End
            #if :pc >= HighRegs
              #if :pc <= HighRegs_End
                    org       HighRegs_End+1
              #endif
            #endif
          #endif
                    mdef      0,{:pc}
          #if :temp = 1
                    org       :pc+{MAX_OS_CALLS*:ab} ;;make room for so many OS calls
          #endif
                    #ppc
                    org       ~text~
#ifndef OSCommands
OSCommands          exp       *
#endif
f~1~                exp       :temp-1
                    far       ~2~
                    mset      0,{:pc}
NUMBER_OF_OS_CALLS  set       :temp               ;Number of opcodes defined (so far)
                    org       :ppc
          #if :temp > 256
                    #Warning  Word size opcodes, OS => OSW
          #endif
          #if :temp > MAX_OS_CALLS
                    merror    {MAX_OS_CALLS} MAX_OS_CALLS, need {:temp} (+{:temp-MAX_OS_CALLS})
          #endif
                    #pull
;-------------------------------------------------------------------------------
                    endm

;*******************************************************************************
; Define FLAG names (FLAG for port, FLAG. for pin number, and FLAG_ for mask)
; to be used for defining bit (boolean) flags.

Flag                macro     [FlagBaseName (needed first time or to change name)]
          #ifb ~text~
            #ifb ~1~
                    mreq      1:[FlagBaseName (needed first time or to change name)]
            #endif
          #endif
          #ifnb ~1~
                    mset      0,~1~,1,0           ;;flag base name definition (starts with suffix 1)
            #ifb ~label~
                    mexit                         ;;exit if no label with flag name definition
            #endif
          #endif
                    #temp     ~text','3~
          #ifndef ~text,~~text','2~
                    #push
                    #RAM
~text,~~text','2~   rmb       1
                    #pull
          #endif
~label~             set       ~text,~~text','2~
~label~.            equ       ~text','3~
~label~_            equ       1<~text','3~
                    #temp     :temp+1
          #if :temp < 8
                    mset      0,~text,~,~text','2~,{:temp}
          #else
                    #temp     ~text','2~+1
                    mset      0,~text,~,{:temp},0
          #endif
                    endm

;*******************************************************************************

aax                 macro     [count]
                    mdef      1,1
          #ifdef AAX
                    call      AAX
          #else
                    !aax
          #endif
                    mtop      ~1~
                    endm

;*******************************************************************************
; In-place multiply a byte by ten. If no parameter is given then do so in RegA

ByteX10             macro     Variable
                    mset      #
          #ifb ~1~
            #ifdef RegAx10
                    call      RegAx10
                    mexit
            #endif
            #if :index > 2
                    #Hint     Consider \@#Uses lib/convert/regax10.sub\@ optimization
            #endif
                    pshx
                    ldx       #10
                    mul
                    lsrx                          ;CCR[C] = 9th bit of result
                    pulx
                    mexit
          #endif
          #ifnb ~#~
                    merror    Variable expected (~1~)
          #endif
                    #push
                    #spauto   :sp
                    psha
                    lda       ~1~
                    @@~0~
                    sta       ~1~
                    pula
                    #pull
                    endm

;*******************************************************************************
; Run a section of code with interrupts disabled; then restore to previous state

NoInts              macro
                    @@_needs_spauto_ Stack indexing may fail if not in #spauto mode
                    psha
                    tpa
                    sei
                    msuspend
                    tap
                    pula
                    endm

;*******************************************************************************
; Assign name to the non-volatile EEPROM image of an existing EE_[X]BLOCK variable

eeprom              macro     Name,variable
          #ifndef ~2~
                    mexit
          #endif
          #ifdef EE_XBLOCK
            #if ~2~ >= EE_XBLOCK
~1~                 equ       ~2~-EE_XBLOCK+EEPROM+::EE_BLOCK,::~2~
                    mexit
            #endif
          #endif
~1~                 equ       ~2~-EE_BLOCK+EEPROM,::~2~
                    endm

;*******************************************************************************
; ASCII CONTROL CODES

NULL                def        0                  ;null
NUL                 def        0                  ;alternate spelling for NULL
ASCII_SOH           def        1                  ;Start of Heading
ASCII_STX           def        2                  ;Start of Text
ASCII_ETX           def        3                  ;End of Text
EOT                 def        4                  ;End of Transmission
ASCII_ENQ           def        5                  ;Enquiry
ACK                 def        6                  ;Acknowledge
BELL                def        7                  ;Bell
BS                  def        8                  ;Backspace
TAB                 def        9                  ;Horizontal Tab
LF                  def       10                  ;Line Feed
ASCII_VT            def       11                  ;Vertical Tab
ASCII_FF            def       12                  ;Form Feed
CR                  def       13                  ;Carriage Return
ASCII_SO            def       14                  ;Shift Out
ASCII_SI            def       15                  ;Shift In
ASCII_DLE           def       16                  ;Data Link Escape
ASCII_DC1           def       17                  ;Device Control 1
XON                 def       17                  ;XON
ASCII_DC2           def       18                  ;Device Control 2
ASCII_DC3           def       19                  ;Device Control 3
XOFF                def       19                  ;XOFF
ASCII_DC4           def       20                  ;Device Control 4
ASCII_NAK           def       21                  ;Negative acknowledge
ASCII_SYN           def       22                  ;Synchronous idle
ASCII_ETB           def       23                  ;End of Transmission Block
ASCII_CAN           def       24                  ;Cancel
ASCII_EM            def       25                  ;End of Medium
ASCII_SUB           def       26                  ;CTRL-Z
CTRL_Z              def       26                  ; -//-
ESC                 def       27                  ;Escape
ASCII_FS            def       28                  ;File Separator
ASCII_GS            def       29                  ;Group Separator
ASCII_RS            def       30                  ;Record Separator
ASCII_US            def       31                  ;Unit Separator

#ifdef PORTA&DDRA
DDR                 def       DDRA-PORTA          ;standard DDR offset
#else ifdef PORTA&PORT_PTAIE&PORT_PTAOE
DDRI                def       PORT_PTAIE-PORTA    ;standard DDR offsets
DDRO                def       PORT_PTAOE-PORTA    ; for separate I/O cases
#endif
;---------------------------- Miscellaneous ------------------------------------

SPEED_SIZE          def       2                   ;1 = SPEED, 2 = SIZE optimization
                    @ConstMinMax SPEED_SIZE,1,2

BYTE                def       1                   ;8-bit quantity
WORD                def       2                   ;16-bit quantity
POINTER             def       3                   ;24-bit (paged) pointer
DWORD               def       4                   ;32-bit quantity
QWORD               def       8                   ;64-bit quantity

S_BYTE              def       0,1                 ;size of 8-bit quantity
S_WORD              def       0,2                 ;size of 16-bit quantity
S_POINTER           def       0,:ab               ;size of pointer: 16-bit (normal), 24-bit (paged)
S_DWORD             def       0,4                 ;size of 32-bit quantity
S_QWORD             def       0,8                 ;size of 64-bit quantity

MAXERROR            def       0                   ;used for error codes
ERASED_STATE        def       -1                  ;default [E]EPROM/Flash Erased State
          #ifndef STACK_IN_LOW_RAM
            #!if XRAM_END-XRAM > RAM_END-RAM
STACKTOP            def       XRAM_END+1          ;top-of-stack plus one for use with LDHX, TXS
            #endif
          #endif
STACKTOP            def       RAM_END+1           ;top-of-stack plus one for use with LDHX, TXS
REQUIRED_STACK      def       50                  ;minimum required stack in bytes
          #ifhcs
MAX_OS_CALLS        def       100                 ;default room for OS calls (9S08)
          #endif
MAX_OS_CALLS        def       64                  ;default room for OS calls (68HC08)
                    @ConstMinMax MAX_OS_CALLS,1,256

          #ifdef VERSION
                    #Message  Firmware v{VERSION(2)}
          #endif
                    #Message  MCU Operating Voltage (VDD): {VDD(3)}V
;-------------------------------------------------------------------------------
?                   macro
                    #Message  ~1~: {~1~} Hz ({~1~/RDIV} Hz IRCLK, RDIV={RDIV})
                    endm

          #ifdef TCXO
                    @?        TCXO
          #endif
          #ifdef XTAL
                    @?        XTAL
          #endif
          #ifz KHZ\1000
                    #Message  {KHZ/100(1)} MHz ({BUS_KHZ/100(1)} MHz bus, BDIV={BDIV}) Cycle: {10000000/BUS_KHZ(1)} nsec
          #else
                    #Message  {KHZ(3)} MHz ({BUS_KHZ(3)} MHz bus, BDIV={BDIV}) Cycle: {10000000/BUS_KHZ(1)} nsec
          #endif
;-------------------------------------------------------------------------------
?                   macro
                    mswap     1,:loop
          #ifdef ~1~&&~1~_END
            #if ~1~_END > ~1~
                    #Message  ~1~~'..........:'.1.{10-:1}~ {~1~(h)}-{~1~_END(h)} ({~1~_END-~1~+1} bytes)
            #endif
          #else ifdef ~1~
                    #Message  ~1~~'..........:'.1.{10-:1}~ {~1~(h)}-{~1~&$FF0000+:PAGE_END(h)} ({~1~&$FF0000+:PAGE_END-~1~+1} bytes)
          #endif
                    mtop      :n
                    endm

                    @?        RAM,XRAM,EEPROM,ROM,XROM,PPAGE0,PPAGE2,PPAGE4,PPAGE5,PPAGE6,PPAGE7
                    #Message  DataFlash: {FLASH_DATA_SIZE} bytes
;-------------------------------------------------------------------------------
          #ifnz REQUIRED_STACK
            #ifdef MAXTASKS
                    #temp     REQUIRED_STACK*MAXTASKS
            #else
                    #temp     REQUIRED_STACK
            #endif
                    #Message  STACK: {STACKTOP-:temp(h)}-{STACKTOP-1(h)} [REQUIRED_STACK: {:temp} bytes]
          #else
                    #Message  REQUIRED_STACK: None!
          #endif
          ;--------------------------------------
          ; Allocate variable space (accounting for required stack)
          ;--------------------------------------
?                   macro     FromAddress,ToAddress
          #ifdef MAXTASKS
                    mdef      2,STACKTOP-{REQUIRED_STACK*MAXTASKS}-1
          #endif
                    mdef      2,STACKTOP-REQUIRED_STACK-1
                    #VARIABLE ~1~ ~2~
                    #Message  Variable space in ~1~~' :'.{:1-2}~ {~1~(h)}-{~2~(h)} ({~2~-~1~+1} bytes)
                    endm
#ifdef XRAM
          #if STACKTOP > XRAM
                    @?        RAM,RAM_END
                    @?        XRAM
          #else
                    @?        RAM
                    @?        XRAM,XRAM_END
          #endif
#else
                    @?        RAM
#endif
          ;-------------------------------------- ;Flash page mask
#ifdef FLASH_PAGE_SIZE
FLASH_PAGE_MASK     def       FLASH_PAGE_SIZE-1^$FFFF
                    #Message  FLASH_PAGE_SIZE = {FLASH_PAGE_SIZE} (FLASH_PAGE_MASK = {FLASH_PAGE_MASK(h)})
#endif
;------------------- Flash Clock calculation based on bus KHZ ------------------
#ifhcs
          #ifmmu
            #ifexists mmu.inc
                    #Uses     mmu.inc
            #endif
          #endif
  #ifdef _PA_||_PT_||_PL_
MIN_FLASH_KHZ       def       800
MAX_FLASH_KHZ       def       1000
  #endif
MIN_FLASH_KHZ       def       150
MAX_FLASH_KHZ       def       200

?                   macro     [TargetFlashKHZ]
                    mdef      1,MAX_FLASH_KHZ     ;ideal Flash clock is MAX_FLASH_KHZ
                    #temp     BUS_KHZ/~1~-1       ;divide bus by 1
                    mset      2,:temp&$3F+1
          #ifdef PRDIV8_
            #if BUS_KHZ/~1~-1 > 63                ;divide bus by 8
                    #temp     BUS_KHZ/8/~1~-1|PRDIV8_
                    mset      2,:temp&$3F+1*8
            #endif
          #endif
                    mset      2,BUS_KHZ/{~2~}
          #if ~2~ > MAX_FLASH_KHZ
                    mset      1,{~1~-1}
                    mtop
          #else if ~2~ < MIN_FLASH_KHZ
                    merror    No suitable FLASH_CLK_VALUE @ {KHZ(3)} MHz
          #endif
FLASH_CLK_VALUE     equ       :temp
                    #Message  FLASH @ {~2~} KHz (use FCDIV := FLASH_CLK_VALUE [{FLASH_CLK_VALUE}])
                    endm

                    @?                            ;Calc Flash Clock Value
#endif
;-------------------------------------------------------------------------------
;-------------------------------------------------------------------------------
          #ifdef SIMHCS
                    #Hint     +------------------------------------+
                    #Hint     | SIMULATOR mode (do NOT distribute) |
                    #Hint     +------------------------------------+
          #else ifdef DEBUG
                    #Hint     +------------------------------------+
                    #Hint     | DEBUG/BDM mode (do NOT distribute) |
                    #Hint     +------------------------------------+
          #endif
