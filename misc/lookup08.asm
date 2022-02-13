;*******************************************************************************
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Date      : 2003.02.28 (original)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : Public Domain
;* Note(s)   : Example code to lookup a table of upto 256 16-bit values
;*******************************************************************************

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

;*******************************************************************************
; Routine: LookupWordTable
; Input  : HX -> Table
;        : stack before call: 16-bit word to look for
; Output : If found    : Carry Clear
;        :               HX -> Table entry
;        :               A = index
;        : If not found: Carry Set
; Note(s): Table is terminated by a $0000 word (modify accordingly)

                    #spauto   :ab

LookupWordTable     proc
target@@            equ       1,2
                    pshhx
                    psha      ans@@
                    #ais

                    clra
                    psha      index@@             ;keeps index

Loop@@              lda       ,x
                    ora       1,x                 ;if at end of table
                    beq       NotFound@@          ;we didn't find anything
          #ifhcs
                    pshhx
                    ldhx      ,x
                    cphx      target@@,sp
                    pulhx
          #else
                    lda       target@@,sp         ;higher byte of target
                    cmpa      ,x
                    bne       Cont@@
                    lda       target@@+1,sp       ;lower byte of target
                    cmpa      1,x
          #endif
                    bne       Cont@@
          ;--------------------------------------
          ; exits from here if it finds the target
          ;--------------------------------------
                    tsx
                    lda       index@@,spx
                    sta       ans@@,spx
                    clc                           ;indicate 'found'
                    bra       Done@@

Cont@@              aix       #2                  ;point HX to next word
                    inc       index@@,sp          ;increment index
                    bne       Loop@@              ;on overflow, abort

NotFound@@          sec                           ;indicate 'not found'
                    pula                          ;balance stack
Done@@              pula
                    pulhx
                    rts

;*******************************************************************************
                    #sp
;*******************************************************************************
                    #Exit

Start               proc
                    rsp
                    clra                          ;Simulators don't like uninitialized regs
          ;--------------------------------------
          ; first sample call returns with Carry Clear, A=2, HX->third entry
          ;--------------------------------------
                    ldhx      #$3456              ;target value
                    pshhx                         ;pass parameter on stack
                    ldhx      #SampleTable
                    bsr       LookupWordTable
                    pulhx                         ;remove parameter from stack
                    bcs       NotFound@@
          ;--------------------------------------
          ; second sample call returns with Carry Set, rest not changed
          ;--------------------------------------
                    ldhx      #$1111              ;target value
                    pshhx                         ;pass parameter on stack
                    ldhx      #SampleTable
                    bsr       LookupWordTable
                    pulhx                         ;remove parameter from stack
                    bcs       NotFound@@
          ;--------------------------------------
Found               bra       *
NotFound@@          bra       *

SampleTable         dw        $1234
                    dw        $2345
                    dw        $3456
                    dw        $4567
                    dw        $5678
                    dw        $6789
                    dw        $789A
                    dw        $89AB
                    dw        $9ABC
                    dw        $ABCD
                    dw        $BCDE
                    dw        $CDEF
                    dw        $DEF0
                    dw        $EF01
                    dw        $F012
                    dw        $0123
                    dw        $0000               ;terminator

;*******************************************************************************
                    @vector   Vreset,Start
;*******************************************************************************
