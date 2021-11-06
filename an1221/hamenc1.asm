;*******************************************************************************
; Program Name: HAMENC1.ASM (Hamming Encoder #1 - Table Look-up)
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
;                       Added more comments
;
;       Rev     1.00    01/22/93        M.R. Glenewinkel
;                       HC08 version
;*******************************************************************************
; Program Description:
;       This routine will encode a four-bit info word into a (7,4)
;       Hamming encoding codeword.
;
;       This source code is an example of using a table look-up
;       method to encode a four bit info word to a seven bit code
;       word. For a more detailed description of the process of error
;       control codes and Hamming codes in particular, please
;       refer to Motorola Application Note 1221.
;       This routine consists of only one instruction, a
;       look-up table fetch, where the encoding has been already
;       done and inserted into this look-up table.
;
;       "info word" is the word you want to encode
;       "codeword" is an encoded info word
;
; TASK DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  X                                            Enter routine with
;                                                X-reg=LSN of info
;                                                word.
;                       ACCA                    Leave routine with
;                                                7-bit codeword in here
;
;
; LOCAL DATA:
;  Input Variables      Output Variables        Description
;  ----------------     -----------------       -------------
;  ACCA                                         Misc. computational
;                                                use.
;*******************************************************************************

                    org       *

HamEnc1             proc
                    lda       ?CodeWords,x        ; ACCA <- (CodeWords+X)
                                                  ; X contains the offset
                                                  ; from CodeWords
                    rtc                           ; done !!!

;*******************************************************************************
                    #DATA     $2000               ; Tables
;*******************************************************************************

?CodeWords          fcb       %00000000
                    fcb       %01010001
                    fcb       %01110010
                    fcb       %00100011
                    fcb       %00110100
                    fcb       %01100101
                    fcb       %01000110
                    fcb       %00010111
                    fcb       %01101000
                    fcb       %00111001
                    fcb       %00011010
                    fcb       %01001011
                    fcb       %01011100
                    fcb       %00001101
                    fcb       %00101110
                    fcb       %01111111

;*******************************************************************************
#ifmain
                    #VECTORS  $FFFE               ;reset vector
                    dw        HamEnc1
#endif
;*******************************************************************************
