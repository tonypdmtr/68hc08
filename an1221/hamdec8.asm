;*******************************************************************************
; Program Name: HAMDEC8.ASM ( Hamming Decoder - Matrix Calculation )
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
;                       HC05 version to be translated to HC08 code
;
;       Rev     0.60    01/21/93        M.R. Glenewinkel
;                       Fixed logic bugs
;
;       Rev     1.00    01/22/93        M.R. Glenewinkel
;                       HC08 version
;*******************************************************************************
; Program Description:
;
;       This routine will evaluate a received Hamming-encoded
;       codeword and decode it into its original form, thereby
;       receiving the originally encoded data. HAMDEC will
;       successfully do this even in the presence of up to 1
;       single-bit error induced into the received codeword
;       by the channel.
;
;       This routine works similarly to the HAMENC2 routine, in
;       that the calculations that are performed are actual
;       matrix-type arithmetic operations. The routine works like
;       this: The workspace is prepared (cleared), the received
;       codeword is multiplied by each column of a matrix referred
;       to as "the transpose of the parity check" matrix, byte wide
;       parity is generated, and a 3-bit word is created (it is
;       called the syndrome). The non-zero syndrome is then used
;       to identify the bit location of the error. The syndrome is
;       used to correct the corrupted bit position and recover the
;       original four-bit info word. If the syndrome is zero, then
;       no detectable errors have occurred and the info word
;       is recovered.
;
; TASK DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  ACCA                                         Enter routine with
;                                                ACCA=Codeword.
;                       ACCA                    Same contents
;                                                as ?infoword.
;                       ?infoword               The recovered
;                                                info word.
;
; LOCAL DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  bit_counter          bit_counter             Keeps track of the
;                                                column # within
;                                                ?HTranspose.
;  CodeWord             CodeWord                Yup, you guessed it
;                                                ...this is where we
;                                                keep a temp version
;                                                of the codeword.
;  column_counter       column_counter          Keeps track of the
;                                                H-transpose column
;                                                that is combined
;                                                with the codeword.
;                       ?infoword               The recovered
;                                                info word.
;  Syndrome             Syndrome                Data which gives us
;                                                the location of any
;                                                errors (if any).
;  ACCA                 ACCA                    Misc. computational
;                                                use.
;  X                    X                       Misc. computational
;                                                use.
;*******************************************************************************

                    #push
                    #RAM      *

?bit_counter        rmb       1
?codeword           rmb       1
?column_counter     rmb       1
?infoword           rmb       1
?parity             rmb       1
?syndrome           rmb       1

                    #pull

;*******************************************************************************
; We must prepare the workspace...any nonzero stuff in some variables
; could really mess up our process. So...

HamDec              proc
                    clr       ?column_counter
                    clr       ?syndrome
          ;--------------------------------------
          ; Since we enter this routine with the codeword contained in the
          ; accumulator, and use the codeword multiple times, a copy is first
          ; made into the location called "codeword":
          ;--------------------------------------
                    sta       ?codeword

GetCodeWord@@       lda       ?codeword           ; get the first argument
                                                  ; used in our multiplication.
                    ldx       ?column_counter     ; get the current column to
                                                  ; be worked on
                    and       ?HTranspose,x       ; Multiply!
          ;--------------------------------------
          ; The next step in the process is to calculate the parity of the
          ; received codeword. This is accomplished by rotating each bit
          ; through the carry bit and then complementing a byte called "parity":
          ;--------------------------------------
                    clr       ?parity             ; clear the workspace
                    mov       #8,?bit_counter     ; prep loop counter x to do
                                                  ; all eight bits in received
                                                  ; codeword.
                                                  ; it's now prepped.
RotateIt@@          lsla                          ; start the process of deter-
                                                  ; mining the state of each
                                                  ; bit within the rec'd
                                                  ; codeword.
                    bcc       Cont@@              ; if carry is not positive,
                                                  ; then do nothing but
                                                  ; bump counter.
                    com       ?parity
          ;--------------------------------------
          ; Bump pointer for the next bit to do. If the
          ; counter is zero, then the process stops:
          ;--------------------------------------
Cont@@              dbnz      ?bit_counter,RotateIt@@
                    lda       ?parity
          ;--------------------------------------
          ; The next step in our overall decoding of the codeword into an
          ; information word, is to calculate the syndrome. Remember, the
          ; syndrome will tell us whether a detectable error has occurred and
          ; allow us to find out where it occurred. Again, if the syndrome is
          ; zero, then no detectable error has occurred and we may recover the
          ; original info word by merely "looking it up" in a look-up table.
          ;--------------------------------------
                    cmp       #$FF
                    bne       BildSynDun@@        ; if syndrome (bit#=X)
                                                  ; is a 0, then
                                                  ; branch else fall through...
                    ldx       ?column_counter     ; find out which part of the
                                                  ; syndrome we're working on.
                    lda       ?CoSet,x            ; get ith bit of syndrome
                                                  ; and set to a one.
                    ora       ?syndrome
                    sta       ?syndrome           ; save it for later use.
          ;--------------------------------------
          ; We're finally to the point where we want to see if all of the bits
          ; have been processed. This is done by updating the column counter
          ; (?column_counter) and branching back to the top of the process if we
          ; must finish constructing the syndrome. Else, we move down into
          ; correcting the error and/or just recovering the codeword.
          ;--------------------------------------
BildSynDun@@        inc       ?column_counter      ; inc current column counter
                    lda       ?column_counter      ; load column counter
                    cmpa      #3
                    blo       GetCodeWord@@       ; branch if not done with
                                                  ; all 3 columns
                    ldx       ?syndrome
                    lda       ?codeword           ; get codeword for correction
                    eor       ?CoSet2,x           ; correct the codeword. ACCA
                                                  ; now contains the corrected
                                                  ; codeword.
          ;--------------------------------------
          ; One of the traits of Hamming codes is that part of the codeword
          ; is the info word (nibble, in this case). If you look at the
          ; listing for HamEnc1, you'll notice that the least significant
          ; nibble contains the info word. Hence, the recovery process for
          ; the Hamming decode merely consists of ANDing the LSN of the
          ; corrected codeword. So...
          ;--------------------------------------
                    and       #$0F                ; ACCA now has the original
                                                  ; info word.
                    sta       ?infoword
                    rtc                           ; done !!!

;**********************************************************************
; Tables

?HTranspose         fcb       %01001011
                    fcb       %00101110
                    fcb       %00010111

?CoSet              fcb       %00000100
                    fcb       %00000010
                    fcb       %00000001

?CoSet2             fcb       %00000000
                    fcb       %00010000
                    fcb       %00100000
                    fcb       %00000100
                    fcb       %01000000
                    fcb       %00000001
                    fcb       %00001000
                    fcb       %00000010

;*******************************************************************************
#ifmain
                    #VECTORS  $FFFE               ;reset vector
                    dw        HamDec
#endif
;*******************************************************************************
