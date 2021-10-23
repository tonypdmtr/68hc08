; math1.asm
; Uses:
; Benötigt: MAT1,MAT2,MAT3,MAT3,MAT4,MAT5,MAT6,MAT7
; simple math routines
; einfache Mathematik Routinen (AN1219)
; Created:
; Erstellt:     19.06.01 st-js
; Update:
; Ergänzt:      26.06.01 st-js
;               03.07.01 st-js  ADD- und SUB-Routinen mit INFO in A
;               16.11.06 st-js  für HC(S)08  ohne TMPD...TMPI!
; ADD1616  (MAT0;MAT1)+(MAT4;MAT5) -> (MAT0;MAT1) Achtung ohne Uebertrag!
;                                                 no carry!
; ADD3232  (MAT0..MAT3)+(MAT4..MAT5) -> (MAT0..MAT3) Achtung ohne Uebertrag!
;                                                    no carry!
; SUB1616  (MAT0;MAT1)-(MAT4;MAT5) -> (MAT0;MAT1)
; SUB3232  (MAT0..MAT3)-(MAT4..MAT5) -> (MAT0..MAT3)
; in A wird folgende INFO zurückgegeben:
; info in A:
;    A=$00 Resultat ist NULL/zero!
;    A=$80 Resultat ist NEGATIV
;    A=$01 Resultat ist POSITIV
; NEG16    (MAT0;MAT1) -> (MAT0;MAT1)
; NEG32    (MAT0..MAT3) -> (MAT0..MAT3)
; unsigned Funktionen/functions
; DIVU3216 (MAT0..MAT3)/(MAT4;MAT5) -> (MAT0..MAT3)
; MULU168  (MAT0;MAT1)*(MAT2) -> (MAT0..MAT3) max. 24Bit lang!/ max.24 bits long
; MULU1616 (MAT0;MAT1)*(MAT4;MAT5) -> (MAT0..MAT3)
; Addition (MAT0;MAT1)+(MAT4;MAT5) -> (MAT0;MAT1) Achtung ohne Uebertrag!
;                                                 no carry!

#ifmain ;-----------------------------------------------------------------------
                    #ListOff
                    #Uses     mcu.inc
                    #ListOn
#endif ;------------------------------------------------------------------------

                    #Push
                    #RAM

MAT0                rmb       1
MAT1                rmb       1
MAT2                rmb       1
MAT3                rmb       1
MAT4                rmb       1
MAT5                rmb       1
MAT6                rmb       1
MAT7                rmb       1

                    #Pull

;*******************************************************************************

ADD1616             proc
                    @add.w    MAT0,MAT4,MAT0

                    lda       MAT0
                    bmi       Negative@@
                    add       MAT1
                    bne       Positive@@

Zero@@              clra                          ; Resultat NULL/zero
                    bra       Done@@

Negative@@          lda       #$80                ; Resultat NEGATIV
                    bra       Done@@

Positive@@          lda       #$01                ; Resultat POSITIV

Done@@              rts

;*******************************************************************************
; *Addition (MAT0..MAT3)+(MAT4..MAT5) -> (MAT0..MAT3) Achtung ohne Uebertrag!
;                                                   no carry

ADD3232             proc
                    @add.l    MAT0,MAT4,MAT0

                    lda       MAT0
                    bmi       Negative@@
                    add       MAT1
                    bne       Positive@@
                    add       MAT2
                    bne       Positive@@
                    add       MAT3
                    beq       Zero@@
                    bra       Positive@@

Negative@@          lda       #$80                ; Resultat NEGATIV
                    rts

Positive@@          lda       #$01                ; Resultat POSITIV
                    rts

Zero@@              clra                          ; Resultat NULL
                    rts

;*******************************************************************************
; 2er Komplement (MAT0;MAT1) -> (MAT0;MAT1)

NEG16               proc
                    @neg.w    MAT0
                    rts

;*******************************************************************************
; 2er Komplement (MAT0..MAT3) -> (MAT0..MAT3)

NEG32               proc
                    neg       MAT3
                    bcc       Go@@

                    @add.b    MAT2,#1,MAT2
                    bcc       Go@@

                    @add.b    MAT1,#1,MAT1
                    bcc       Go@@

                    inc       MAT0

Go@@                neg       MAT2
                    bcc       Done@@

                    @add.b    MAT1,#1,MAT1
                    bcc       Done@@

                    inc       MAT0

Done@@              @neg.w    MAT0
                    rts

;*******************************************************************************
; Subtraktion (MAT0;MAT1)-(MAT4;MAT5) -> (MAT0;MAT1)

SUB1616             proc
                    @sub.w    MAT0,MAT4,MAT0

                    lda       MAT0
                    bmi       Negative@@

                    add       MAT1
                    beq       Zero@@

                    bra       Positive@@

Negative@@          lda       #$80                ; Resultat NEGATIV
                    bra       Done@@

Positive@@          lda       #$01                ; Resultat POSITIV
                    bra       Done@@

Zero@@              clra                          ; Resultat NULL
Done@@              rts

;*******************************************************************************
; Subtraktion (MAT0..MAT3)-(MAT4..MAT7) -> (MAT0..MAT3)

SUB3232             proc
                    @sub.l    MAT0,MAT4,MAT0

                    lda       MAT0
                    bmi       Negative@@

                    add       MAT1
                    bne       Positive@@

                    add       MAT2
                    bne       Positive@@

                    add       MAT3
                    beq       Zero@@

                    bra       Positive@@

Negative@@          lda       #$80                ; Resultat NEGATIV
                    bra       Done@@

Positive@@          lda       #$01                ; Resultat POSITIV
                    bra       Done@@

Zero@@              clra                          ; Resultat NULL
Done@@              rts

;*******************************************************************************
; Division (MAT0;MAT1;MAT2;MAT3)/(MAT4;MAT5)

; Beschreibung siehe AN1219 Seite 11 / Listing Seite 24
; description see AN1219 page 11 / listig page 24

                    #spauto

DIVU3216            proc
dividend@@          equ       MAT0+2,4
divisor             equ       MAT4,2
quotient@@          equ       MAT0,2
remainder@@         equ       MAT0,2
                    push                          ; save all registers

                    @local    divisor 2,count     ; reserve three bytes of temp storage

                    @mova.s,  #32 count@@,sp      ; loop counter for number of shifts
                    @mova.s,  divisor divisor@@,sp; put divisor in working storage

;     Shift all four bytes of dividend 16 bits to the right and clear
;     both bytes of the temporary remainder location

                    mov       dividend@@+1,dividend@@+3  ; shift dividend lsb
                    mov       dividend@@,dividend@@+2  ; shift 2nd byte of dividend
                    mov       dividend@@-1,dividend@@+1  ; shift 3rd byte of dividend
                    mov       dividend@@-2,dividend@@  ; shift dividend msb
                    @clr.s    remainder@@         ; zero remainder
;
Loop@@              lda       remainder@@         ; get remainder msb
                    rola                          ; shift remainder msb into carry
                    @rol.s    dividend@@          ; shift dividend
                    @rol.s    remainder@@         ; shift remainder
;
;     Subtract both bytes of the divisor from the remainder
;
                    @sub.s,   remainder@@ divisor@@,sp remainder@@  ; subtract divisor msb from remainder msb

                    lda       dividend@@+3        ; get low byte of dividend/quotient
                    sbc       #0                  ; dividend low bit holds subtract carry
                    sta       dividend@@+3        ; store low byte of dividend/quotient
;
;     Check dividend/quotient lsb. If clear, set lsb of quotient to indicate
;     successful subraction, else add both bytes of divisor back to remainder
;
                    brclr     dividend@@+3,Skip@@ ; check for a carry from subtraction
                                                  ; and add divisor to remainder if set
                    @add.s,   remainder@@ divisor@@,sp remainder@@ ; add divisor msb to remainder msb

                    clra                          ; add carry to low bit of dividend
                    adc       dividend@@+3        ; get low byte of dividend
                    sta       dividend@@+3        ; store low byte of dividend

                    bra       Cont@@              ; do next shift and subtract

Skip@@              bset      dividend@@+3

Cont@@              dbnz      count@@,sp,Loop@@   ; decrement loop counter and do next
;
;     Move 32-bit dividend into MAT0.....MAT0+3 and put 16-bit
;     remainder in MAT4:MAT4+1
;                                                 ;shift
                    @mova.w,  remainder@@ divisor@@,sp ; temporarily store remainder
                    @mov.l    dividend@@,quotient@@ ; shift all four bytes of quotient 16 bits to the left
                    @mova.w,  divisor@@,sp MAT4   ; store final remainder msb
;
;     Deallocate local storage, restore register values, and return from subroutine
;
                    ais       #:ais               ; deallocate temporary storage
                    pull                          ; restore all registers
                    rts

;*******************************************************************************
; Multiplikation (MAT0;MAT1)*MAT2 -> (MAT0..MAT3)  Resultat ist max. 24Bit lang
;                                                  result is max. 24 bits long
                    #spauto

MULU168             proc
                    lda       MAT0
                    ldx       MAT2
                    mul                           ; multiplizieren des oberen Bytes
                    stx       MAT4
                    sta       MAT5                ; zwischenspeichern

                    lda       MAT1
                    ldx       MAT2
                    mul                           ; multiplizieren des unteren Bytes
                    sta       MAT3                ; LO-Byte i.O.
                    txa

                    add       MAT5                ; addieren der Teilresultate für HI-Byte
                    sta       MAT2

                    lda       MAT4
                    sta       MAT1

                    clr       MAT0                ; MAT0 ist immer 0!
                    rts

;*******************************************************************************
; Multiplikation (MAT0;MAT1)*(MAT4;MAT5) -> (MAT0..MAT3)
; Beschreibung AN1219 Seite 2
; description AN1219 page 2

                    #spauto

MULU1616            proc
                    push                          ; save acc, x-reg, h-reg

                    @local    num1 2,num2 2,tmp,carry

                    clr       carry@@,sp          ; zero storage for multiplication carry
;
;     Multiply (MAT0:MAT0+1) by MAT4+1
;
                    ldx       MAT0+1              ; load x-reg w/multiplier lsb
                    lda       MAT4+1              ; load acc w/multiplicand lsb
                    mul                           ; multiply
                    stx       carry@@,sp          ; save carry from multiply
                    sta       MAT0+3              ; store lsb of final result

                    ldx       MAT0                ; load x-reg w/multiplier msb
                    lda       MAT0+1              ; load acc w/multiplicand lsb
                    mul                           ; multiply
                    add       carry@@,sp          ; add carry from previous multiply
                    sta       num1@@+1,sp         ; store 2nd byte of interm. result 1.
                    bcc       Skip1@@             ; check for carry from addition
                    incx                          ; increment msb of interm. result 1.
Skip1@@             stx       num1@@,sp           ; store msb of interm. result 1.
                    clr       carry@@,sp          ; clear storage for carry
;
;     Multiply (MAT0:MAT0+1) by MAT4
;
                    ldx       MAT0+1              ; load x-reg w/multiplier lsb
                    lda       MAT4                ; load acc w/multiplicand msb
                    mul                           ; multiply
                    stx       carry@@,sp          ; save carry from multiply
                    sta       tmp@@,sp            ; store lsb of interm. result 2.

                    ldx       MAT0                ; load x-reg w/multiplier msb
                    lda       MAT4                ; load acc w/multiplicand msb
                    mul                           ; multiply
                    add       carry@@,sp          ; add carry from previous multiply
                    sta       num2@@+1,sp         ; store 2nd byte of interm. result 2.
                    bcc       Skip2@@             ; check for carry from addition
                    incx                          ; increment msb of interm. result 2.
Skip2@@             stx       num2@@,sp           ; store msb of interm. result 2.
;
;     Add the intermediate results and store the remaining three bytes of the
;     final value in locations MAT0....MAT0+2.
;
                    tsx
                    @add.w,   num1@@,spx num2@@+1,spx MAT0+1

                    clra                          ; add any carry from previous addition
                    adc       num2@@,spx          ; load acc with msb from 2nd result
                    sta       MAT0                ; store msb of final result
;
;     Reset stack pointer and recover original register values
;
                    ais       #:ais               ; deallocate local storage
                    pull                          ; restore h-reg, x-reg, accumulator
                    rts

;*******************************************************************************
                    #sp
;*******************************************************************************
