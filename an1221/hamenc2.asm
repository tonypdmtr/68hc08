;*******************************************************************************
; Program Name: HAMENC28.ASM (Hamming Encoder - Matrix Calculation)
; Revision: 1.00
; Date: January 21,1993
;
; Written By: Mark Glenewinkel
;             Motorola CSIC Applications
;
; Assembled Under: aspisys.com/ASM8 by Tony Papadimitriou <tonyp@acm.org>
;
;       *********************************
;       *       Revision History
;       *********************************
;
;       Rev     0.50    12/15/92        M.A. McQuilken
;                              HC05 version to be translated to HC08 code
;
;       Rev     0.60    01/20/93        M.R. Glenewinkel
;                              Fixed logic bugs
;
;       Rev     1.00    01/22/93        M.R. Glenewinkel
;                              HC08 version
;*******************************************************************************
; Program Description:
;
;       This routine will encode a four-bit info word into a (7,4)
;       Hamming encoding codeword.
;
;
;       This routine differs from HAMENC1 not in results, but in
;       method. Whereas HAMENC1 was basically an easy look-up of
;       pre-encoded (7,4) Hamming codewords, HAMENC2 actually
;       performs the matrix arithmetic to encode the 4-bit info word
;       input. Fortunately when working with modulo arithmetic
;       (particularly mod-2), things like multiplication and such
;       are reduced to fairly easy functions.
;
;       This routine follows this basic overall flow: Workspace is
;       cleared, the info word is first multiplied, each bit in the
;       product is then added together (this is effectively
;       calculating the parity of the product), the actual final
;       codeword is constructed one-bit at a time, at that point
;       the next row from the generator matrix is fetched and this
;       process repeated until all of the generator matrix rows have
;       been combined with the info word.
;
;       For a more detailed description of the process of error
;       control codes and Hamming codes in particular, please
;       refer to Motorola Application Note 1221.
;
; TASK DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  ACCA                                         Enter routine with
;                                                ACCA=LSN of info
;                                                word (4-bit).
;                       ACCA                    Leave routine with
;                                                7-bit codeword in
;                                                here.
;
;
; LOCAL DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  codeword             codeword                Yup, you guessed it
;                                                ...this is where we
;                                                keep a temp version
;                                                of the codeword.
;  WordCntr             WordCntr                Keeps track of the
;                                                GenMatrix row that
;                                                is combined with
;                                                the info word.
;  ACCA                 ACCA                    Misc. computational
;                                                use.
;  X                    X                       Misc. computational
;                                                use.
;*******************************************************************************

                    #push
                    #RAM      *

?codeword           rmb       1
?infoword           rmb       1
?word_counter       rmb       1

                    #pull

;*******************************************************************************
; As stated in the header, the first place to start is
; the clearing of data space:

HamEnc2             proc
                    clr       ?word_counter
                    clr       ?codeword
          ;--------------------------------------
          ; Next, before we begin the process of multiplying and adding the
          ; codeword with the info word, we need to save a copy of the info word
          ; (remember, we are entering the routine with ACCA having the
          ; info word):
          ;--------------------------------------
                    sta       ?infoword
          ;--------------------------------------
          ; Now we begin the fun stuff...doing the actual multiplication and
          ; addition that is required to this super-fun Hamming stuff. Each
          ; multiplication with binary data is actually a logical AND on a
          ; bitwise basis:
          ;--------------------------------------
GetInfoWord@@       lda       ?infoword           ; get the info word for the
                                                  ; multiplication.
                    ldx       ?word_counter       ; get the current row count
                                                  ; into the generator matrix.
                    and       ?GenMatrix,x        ; Go forth and multiply...
          ;--------------------------------------
          ; Well...that wasn't so bad, was it? Now that the multiplication
          ; is complete we begin the task of adding the product, bit-by-bit
          ; (so to speak). Rather than go through the actual tedium of adding
          ; each bit within the product one bit at a time, I've made a look-up
          ; table that has it done for you. It even has the clever name of
          ; PARATEE to remind you that the process of adding bits within a
          ; byte is determining the byte's parity:
          ;--------------------------------------
                    tax                           ; the byte to have parity
                                                  ; encoded resides in ACCA.
                    lda       ?ParaTee,x          ; get the parity value from LUT
          ;--------------------------------------
          ; As mentioned in the header, the actual codeword is constructed
          ; one-bit at a time. For each multiplication and addition we do,
          ; a single bit within the final codeword results. At this point,
          ; then, we must construct another bit of the codeword from the
          ; last multiplcation and addition:
          ;--------------------------------------
                    beq       Cont@@              ; if parity is odd, then
                                                  ; we do nothing to the
                                                  ; final codeword.
                                                  ; here's the branch to do
                                                  ; nothing, otherwise
                                                  ; we add a positive bit
                                                  ; to the correct position
                                                  ; in the codeword.
          ;--------------------------------------
          ; If we've made it here, then we know to set a bit in the codeword.
          ; So even though the value in ACCA gets "stepped on" in this part
          ; of the routine, the contents of ACCA have done its job and got
          ; us to this point. A look-up table (called CoSet) was used as the
          ; mechanism to construct the codeword one bit at time. CoSet
          ; contains only one bit=1...in each case only the bit that we wish
          ; to set within the byte:
          ;--------------------------------------
                    ldx       ?word_counter       ; word_counter has the current bit
                                                  ; position in it.
                    lda       CoSet,x             ; get bit (in correct position)
                                                  ; to be set.
                    ora       ?codeword           ; set the bit.
                    sta       ?codeword           ; modify codeword for next use.
          ;--------------------------------------
          ; This completes a single cycle in the process of encoding an info
          ; word into a bit within the final codeword. All that is left to do
          ; is to check to see if we have completed the entire codeword. If
          ; we haven't, then pointers get modified so we can do the next one:
          ;--------------------------------------
Cont@@              inc       ?word_counter       ; inc current row/bit position
                    lda       ?word_counter       ; load updated word_counter
                    cmpa      #7                  ; check to see if we're done.
                    blo       GetInfoWord@@       ; Go back, Jack, and
                                                  ; do it again...
                    rtc                           ; done !!!

;*******************************************************************************
; Tables
;*******************************************************************************

?GenMatrix          fcb       %00001011
                    fcb       %00001110
                    fcb       %00000111
                    fcb       %00001000
                    fcb       %00000100
                    fcb       %00000010
                    fcb       %00000001

?ParaTee            fcb       $00
                    fcb       $FF
                    fcb       $FF
                    fcb       $00
                    fcb       $FF
                    fcb       $00
                    fcb       $00
                    fcb       $FF
                    fcb       $FF
                    fcb       $00
                    fcb       $00
                    fcb       $FF
                    fcb       $00
                    fcb       $FF
                    fcb       $FF
                    fcb       $00

CoSet               fcb       %01000000
                    fcb       %00100000
                    fcb       %00010000
                    fcb       %00001000
                    fcb       %00000100
                    fcb       %00000010
                    fcb       %00000001

;*******************************************************************************
#ifmain
                    #VECTORS  $FFFE               ;reset vector
                    dw        HamEnc2
#endif
;*******************************************************************************
