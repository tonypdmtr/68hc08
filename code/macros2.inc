;*******************************************************************************
;* Include   : MACROS2.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Less often used macros for ASM8 (Win32 & Linux versions, only)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/macros2.html
;* Note(s)   : Use: #Include macros2.inc
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; LDA X++, STA X++, and MOVA ,X++ equivalent macros

lda_xpp             macro     AddressPtr
                    ldhx      ~@~
                    lda       ,x
                    aix       #1
                    sthx      ~@~
                    endm
;-------------------------------------------------------------------------------
sta_xpp             macro     AddressPtr
                    ldhx      ~@~
                    sta       ,x
                    aix       #1
                    sthx      ~@~
                    endm
;-------------------------------------------------------------------------------
mova_xpp            macro     FromPtr,ToPtr
                    @@lda_xpp ~1~
                    @sta_xpp  ~2~
                    endm
;-------------------------------------------------------------------------------
mov_xpp             macro     FromPtr,ToPtr
                    #push
                    #spauto   :sp
                    push
                    @@mova_xpp ~@~
                    pull
                    #pull
                    endm

;*******************************************************************************
; Adds HCS08 LDHX addressing modes to HC08.  Transparent in HCS08 mode.

ldhx                macro     Operand
                    mset      #
                    mreq      1:Operand
          #ifhcs
                    !ldhx     ~1~
                    mexit
          #endif
          #ifparm ~'~,1~'.{:1}~ = x               ;for ,X ,AX ,SPX modes only
                    #push
                    #spauto   :sp
                    psha
                    lda       ~[1.-1]~
                    ldx       ~[1.-2]~
                    tah
                    pula
                    #pull
                    mexit
          #endif
                    ldx       ~[1.-1]~
                    txh
                    ldx       ~[1.-2]~
                    endm

;*******************************************************************************
; LSR for combined register XA

lsrxa               macro     [Count]             ;Logical Shift Right XA
                    mdef      1,1
                    lsrx
                    rora
                    mtop      ~1~
                    endm

;*******************************************************************************
; LSL for combined register XA

lslxa               macro     [Count]             ;Logical Shift Left XA
                    mdef      1,1
                    lsla
                    rolx
                    mtop      ~1~
                    endm

;*******************************************************************************
; Compare A to X
#ifnomdef cax
cax                 macro
                    pshx
                    cmpa      1,asp
                    pulx
                    endm
#endif
;*******************************************************************************
; Return with RTS and de-allocate specified number of stack bytes

rts                 macro     StackBytes
          #ifb ~1~
                    !rts
                    mexit
          #endif
          #if ~1~ > 127
                    merror    ~1~ is over the AIS maximum of 127
          #endif
          #ifhcs
                    pshhx
                    ldhx      3,asp
                    sthx      3+~1~,asp
                    pulhx
                    ais       #~1~
                    !rts
                    mexit
          #endif
                    psha
                    lda       2,asp
                    sta       2+~1~,asp
                    lda       3,asp
                    sta       3+~1~,asp
                    pula
                    ais       #~1~
                    !rts
                    endm

;*******************************************************************************
; Return with RTS/RTC and de-allocate specified number of stack bytes

rtc                 macro     StackBytes
          #ifb ~1~
                    !rtc
                    mexit
          #endif
          #if ~1~ > 127
                    merror    ~1~ is over the AIS maximum of 127
          #endif
          #ifhcs
                    pshhx
                    ldhx      :ab+1,asp
                    sthx      :ab+1+~1~,asp
          #ifmmu
                    ldx       :ab+3,asp
                    stx       :ab+3+~1~,asp
          #endif
                    pulhx
                    ais       #~1~
                    rtc
                    mexit
          #endif
                    psha
                    lda       :ab,asp
                    sta       :ab+~1~,asp
                    lda       :ab+1,asp
                    sta       :ab+1+~1~,asp
          #ifmmu
                    lda       :ab+2,asp
                    sta       :ab+2+~1~,asp
          #endif
                    pula
                    ais       #~1~
                    rtc
                    endm

;*******************************************************************************
; Simulate a JUMP to any MMU page (if in #MMU mode). Same as JMP if not in #MMU.
; Does not require override of default macro parameter separator.
; It sees ~2~ as index, but also accepts index in ~1~ (with separator override).
; Example use: @Leap FarCode
;            : @Leap FarTable,x

Leap                macro     PagedAddress[,x]
                    mset      #
          #ifnommu
                    jmp       ~1~
                    mexit
          #endif
                    #push
                    #spauto   :sp
                    ais       #-3                 ;;make room for 24-bit address
                    #psp
                    psha                          ;;save caller's A
                    tpa
                    psha                          ;;save caller's CCR
          #ifb ~,1~                               ;;non-indexed mode assumes IMM
                    lda       #~#1~&$FF
                    sta       3,psp
                    lda       #~#1~>8&$FF
                    sta       2,psp
                    lda       #~#1~>16&$FF
                    sta       1,psp
          #else
                    lda       ~1,~+2~,1~
                    sta       3,psp
                    lda       ~1,~+1~,1~
                    sta       2,psp
                    lda       ~1~
                    sta       1,psp
          #endif
                    pula
                    tap                           ;;restore caller's CCR
                    pula                          ;;restore caller's A
                    RTC                           ;;make the jump
                    #pull
                    endm

;*******************************************************************************
; AIX macro automatically splits offset into as many AIX as needed.  If the
; number of bytes required is bigger than ADDHX size, it uses one ADDHX instead.

#ifnomdef aix
aix                 macro   #OffsetConstant
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
#endif
;*******************************************************************************
; Calculate factorial of given number

Factorial           macro     Number
~label~             set       1
                    mdo
~label~             set       ~label~*:mloop
                    mloop     ~1~
                    endm

;*******************************************************************************
; Clear a memory range by StartAddress/EndAddress or StartAddress/Size

Clear               macro     From,[To][,Counter]
          #ifparm ~1~
                    ldhx      ~1~
          #endif
                    @@_lda_   ~3~
Loop$$$
                    clr       ,ax
                    aix       #1
          #ifparm ~2~
                    cphx      ~2~
                    blo       Loop$$$
                    mexit
          #endif
                    dbnza     Loop$$$
                    endm

;*******************************************************************************
; Find the Greatest Common Divisor (GCD) of two constants

#ifnomdef gcd
gcd                 macro     a,b
          #if ~1~ = ~2~
            #ifparm ~label~
~label~             set       ~1~
            #endif
                    mexit     ~1~
          #endif
          #if ~1~ > ~2~
                    mset      1,{~1~-{~2~}}
                    mtop
          #endif
                    mset      2,{~2~-{~1~}}
                    mtop
                    endm
#endif

;*******************************************************************************
; Find the Least Common Multiple (LCM) of two constants. Prerequisite macro: GCD
; Note: To avoid overflow, first divides, then multiplies. GCD certainly divides
;       both numbers, so no problem doing so, and it's more efficient.

#ifnomdef lcm
lcm                 macro     a,b
                    @@gcd     ~@~
          #ifparm ~label~
~label~             set       {~1~}/:mexit*{~2~}
          #endif
                    mexit     {~1~}/:mexit*{~2~}
                    endm
#endif
;*******************************************************************************
; Calculate paced loop coefficients from a list of task execution intervals,
; all using a common counter counting up (modulo MAX_PACE_TIME).
; On exit, two constants hold the values: MIN_PACE_TIME, MAX_PACE_TIME

CalcPacedLoop       macro     T1,T2[,T3]*
                    mreq      1,2:T1,T2[,T3]*
MIN_PACE_TIME       set       ~1~
MAX_PACE_TIME       set       ~1~
                    mdo
                    mswap     1,:mloop+1
                    @@gcd     ~1~\,MIN_PACE_TIME
MIN_PACE_TIME       set       :mexit
                    @@lcm     ~1~\,MAX_PACE_TIME
MAX_PACE_TIME       set       :mexit
                    mloop     :mloop+:{:mloop+2}
                    #Message  MIN_PACE_TIME: {MIN_PACE_TIME}, MAX_PACE_TIME: {MAX_PACE_TIME}
                    endm

;*******************************************************************************
; Form a 7-bit ASCII string terminated with last character's msb set.
; This format uses one less byte than an ASCIZ string, but cannot handle
; characters with ASCII codes of 128 or above.

Str7                macro     String
                    mset      #                   ;;unite all parms into one
                    mstr      1                   ;;make it a proper string
          #if :1 < 3
                    merror    Null string not allowed
          #endif
                    mdo       2
          #if :mloop = :1-1
                    fcb       \@~c1~\@|$80
                    mexit
          #endif
                    fcb       \@~c1~\@&$7F
                    mloop     :1-1
                    endm

;*******************************************************************************
; Alternate coding does not force leading chars to 7-bit but it's shorter/faster
;                   #Drop     Str7                ;uncomment to test 2nd version

#ifnomdef Str7
Str7                macro     String
                    mset      #                   ;;unite all parms into one
                    mstr      1
          #if :1 < 3
                    merror    Null string not allowed
          #endif
                    mset      2
          #if :1-2 > 1
                    mset      2,\@~1.2.{:1-3}~\@,
          #endif
                    mset      3,\@~1.{:1-1}.1~\@|$80
                    fcc       ~2~~3~
                    endm
#endif
;*******************************************************************************
; Delay current assembly by some arbitrary constant

DelayAssembler      macro     DelayValue
                    mreq      1:DelayValue (Delays assembler by some arbitrary constant)
                    mtop      ~1~
                    endm

;*******************************************************************************
; Check if a constant parameter is a power of two

IsPowerOfTwo        macro     Constant[,Constant]*
                    mreq      1:Constant[,Constant]*
                    mswap     1,:loop
          #ifnz ~1~-1&{~1~}
                    merror    ~1~ not a power of two
          #endif
                    mtop      :n        ;repeat for all parms
                    endm

;*******************************************************************************
; Macro to convert "graphic" bitmap to binary (useful for defining fonts, etc.
; in a more visual way than just numbers).
; An FCB, DW, or LONG value is stored, depending on the size of the parameter
; bit pattern.  The pattern should have underscores for zeros, and any other
; printable character for ones.

Font                macro     GraphicBitmapPattern
                    mreq      1:GraphicBitmapPattern
                    mdef      9,%
          #ifparm ~1.{:loop}.1~ = _
                    mset      9,~9~0
          #else
                    mset      9,~9~1
          #endif
                    mtop      :1
          #if :1 <= 8
                    fcb       ~9~                 ;~1~
          #else if :1 <= 16
                    dw        ~9~                 ;~1~
          #else
                    long      ~9~                 ;~1~
          #endif
                    endm

;*******************************************************************************
; Fill a (normally) non-RAM memory range with specific value or address low byte

FillROM             macro     From,To[,Value]     ;Fill a ROM range with value
                    mreq      1,2:From,To[,Value]
                    #ppc
                    org       ~1~                 ;beginning at specified location
                    #temp     {~2~-~1~+1}         ;:temp holds the number of bytes
          #ifnoparm ~3~
                    mdo                           ;place value (low byte of address)
                    fcb       {:pc&$FF(h)}
                    mloop     :temp               ;repeat with next location
                    org       :ppc
                    mexit
          #endif
          #if :temp > $7FFF
                    fcb:$7FFF ~3~                 ;;place value (user-supplied)
                    #temp     :temp-$7FFF
          #endif
                    fcb::temp ~3~                 ;;place value (user-supplied)
                    org       :ppc
                    endm

;*******************************************************************************
; Fill a memory area (from Start to Finish) with a string

FillROMString       macro     Start,Finish,String
                    mreq      1,2,3
                    mstr      3
                    #ppc
                    org       ~1~
                    fcc:~2~-{~1~(h)}+1/{:3-2} ~3~
                    #temp     ~2~-:PC+1
          #if :temp > 0
                    fcb::temp 0
          #endif
                    org       :ppc
                    endm

;*******************************************************************************
; Display a table of allowed command-line conditionals to use for assembly

AllowedConditionals macro     Conditional Description[,Conditional Description]*
#ifdef ?
  #Hint +===================================================
  #Hint | Available conditionals (for use with -Dx option)
  #Hint +===================================================
                    mdo
          #ifparm ~{:mloop}.1.' '~ = ~{:mloop}.1.1~
  #Hint | ~{:mloop}[ ]~
          #else
  #Hint | ~{:mloop}[ ]~: ~{:mloop}.' '~
          #endif
                    mloop     :n
  #Hint +===================================================
  #Fatal Run ASM8 -Dx (where x is any of the above)
#endif
                    endm

;*******************************************************************************
                    #Exit
;*******************************************************************************
;                   Test various macro expansions
;*******************************************************************************

                    @AllowedConditionals DEBUG Enables debugging code,XTAL Uses external crystal,TEST
                    org       *

Fact8               @Factorial 8
                    #Message  Factorial of 8 is {Fact8}

a                   def       24
b                   def       80

                    @gcd      a,b
                    #Message  gcd({a},{b})={:mexit}

                    @lcm      a,b
                    #Message  lcm({a},{b})={:mexit}
          ;--------------------------------------
                    @CalcPacedLoop 4,7,12,21,42
                    @CalcPacedLoop 10,50,200
          ;--------------------------------------
                    @Clear    $80,$100
          ;--------------------------------------
                    #HcsOff
                    @ldhx     1,sp
                    @ldhx     1,x
                    @ldhx,    1,x
                    @ldhx     1,ax
                    @ldhx     1,spx
                    #HcsOn
                    @ldhx     1,sp
                    @ldhx     1,x
                    @ldhx,    1,x
                    @ldhx     1,ax
                    @ldhx     1,spx
          ;--------------------------------------
                    @lsrxa
          ;--------------------------------------
                    @lsrxa    2
          ;--------------------------------------
                    @lslxa
          ;--------------------------------------
                    @lslxa    2
          ;--------------------------------------
                    @aix      -768                ;from -1 to -768 it uses AIX
          ;--------------------------------------
                    @aix      -769                ;below that it uses ADDHX
          ;--------------------------------------
                    @aix      762                 ;from 1 to 762 it uses AIX
          ;--------------------------------------
                    @aix      763                 ;above that it uses ADDHX
          ;--------------------------------------
                    @IsPowerOfTwo 512,32,2
          #ifmmu
                    @leap     $123456
                    @leap     ,x
                    @leap     1,sp
          #else
                    @leap     $1234
                    @leap     ,x
          #endif
                    @FillROM  $8000,$80FF,$AA     ;fill range with $AA
                    @FillROM  $8100,$81FF         ;fill range with low address byte
                    @FillROMString $8200,$82FF,'UNUSED'
          ;--------------------------------------
                    @font     __OOOO__
                    @font     _OO__OO_
                    @font     OO____OO
                    @font     OOOOOOOO
                    @font     OO____OO
                    @font     OO____OO
                    @font     OO____OO
                    @font     ________
          ;--------------------------------------
                    @Str7     'Quoted String'
                    @Str7     Written by <tonyp@acm.org>
