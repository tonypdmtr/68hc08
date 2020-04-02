;*******************************************************************************
; Program Name: TDPACK.ASM (Time Diversity Pack and UnPack)
; Revision: 1.00
; Date: January 20,1993
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
;       Rev     0.60    01/20/93        M.R. Glenewinkel
;                       Fixed logic bugs
;
;       Rev     1.00    01/22/93        M.R. Glenewinkel
;                       HC08 version
;*******************************************************************************
; Program Description:
;
;       This routine will take a matrix that is 8 bits wide and 8
;       bytes deep and transpose the matrix so that the first row
;       becomes the 1st column, the second row becomes the 2nd
;       column...the last row becomes the 8th column. This is to
;       distribute data bits over several byte transfers so that no
;       channel errors "wipe out" a complete single byte...only
;       individual bits within each source byte will be hit (if the
;       channel fades are "deep" and not frequent). It is expected
;       that the complementary process of "unpacking" (un-transposing)
;       on the receive end must be done to recover the data as it was
;       intended. By executing another transpose on the data, the data
;       will be "unpacked" to its original form.
;
;       As stated above, this routine transposes a matrix consisting
;       of 64 bits. It does this by left shifting each bit of one
;       source row into its corresponding destination column. After
;       all eight bits of the source are shifted to the destination
;       column, the next source byte is left shifted to the next
;       destination column. This entire process is repeated until
;       all eight source bytes and destination bytes have had all of
;       their bits moved.
;
; Task Data:
;
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  src_buffer                                   Eight byte buffer for
;                                                info that is to be
;                                                transposed before
;                                                transmission on
;                                                channel.
;                       dest_buffer             Eight byte buffer that
;                                                contains transposed
;                                                version of data
;                                                previously contained
;                                                in src_buffer
;
;
; LOCAL DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  bit_counter          bit_counter             Keeps track of the
;                                                bits being shifted
;                                                from the source
;                                                buffer
;  dest_counter         dest_counter            Current byte location
;                                                in destination
;                                                buffer.
;  src_counter          src_counter             Current byte location
;                                                in source buffer.
;  ACCA                 ACCA                    Misc. computational
;                                                use.
;  X                    X                       Misc. computational
;                                                use.
;*******************************************************************************
; Register and Variable Equates
;
;       None
;*******************************************************************************

; Memory
                    org       $50

bit_counter         rmb       1
dest_counter        rmb       1
src_counter         rmb       1
src_buffer          rmb       8
dest_buffer         rmb       8

;*******************************************************************************

                    org       $1000               ; beginning of program area
Start               equ       *

;*******************************************************************************
; Main Routine

; Initialization of the variables must occur before the data can
; be manipulated.

TDPack              proc
                    mov       #src_buffer,src_counter
                                                  ; the starting place for
                                                  ; source data manipulation
          ;--------------------------------------
          ; Although the next couple of lines could also be considered
          ; basic workspace initialization, the initialization occurs
          ; every 8-bits of source data manipulation:
          ;--------------------------------------
SetUpDestPntr@@     mov       #dest_buffer,dest_counter
                                                  ; these two lines allow us to
                                                  ; point to dest_buffer
          ;--------------------------------------
          ; A separate bit counter is maintained to ease the hassle of
          ; evaluating the loop point for the 8 bits:
          ;--------------------------------------
                    mov       #8,bit_counter      ; (bit_counter) <- #8
          ;--------------------------------------
          ; At this point, the inner loop (which counts the
          ; bits shifted out of the source buffer) begins.
          ;--------------------------------------
InnerLoop@@         ldx       src_counter         ; src_counter contains the
                                                  ; location of the current
                                                  ; byte to be shifted
                                                  ; out of the source buffer.
                    lsl       ,x                  ; this moves from source
                                                  ; data buffer
                                                  ; into the carry bit.
          ;--------------------------------------
          ; Time to move the data into the destination buffer:
          ;--------------------------------------
                    ldx       dest_counter        ; like the src_counter, this
                                                  ; pointer contains the
                                                  ; address of the destination
                                                  ; byte.
                    rol       ,x                  ; move data from carry into
                                                  ; destination byte.
          ;--------------------------------------
          ; Here's where we determine if we've shifted enough data bits:
          ;--------------------------------------
                    inc       dest_counter        ; proceed to next
                                                  ; destination byte
                    dbnz      bit_counter,InnerLoop@@
                                                  ; branch if we've not moved
                                                  ; eight bits in eight of
                                                  ; the destination bytes.
          ;--------------------------------------
          ; If we've made it here, then we've moved an eight bit chunk of the
          ; source buffer. These next few lines of code determine the actual
          ; value of the pointer into the source buffer. It also contains
          ; the test for completion of movement into the destination buffer:
          ;--------------------------------------
                    inc       src_counter         ; update counter
                    lda       src_counter         ; get counter in ACCA

                    cmpa      #src_buffer+8       ; test
                    bne       SetUpDestPntr@@     ; branch if we haven't
                                                  ; moved everything.
                    bra       *                   ; done !!!

;*******************************************************************************
; Vector Setup
;*******************************************************************************

                    org       $FFFE
                    dw        Start               ; set up reset vector

;*******************************************************************************
