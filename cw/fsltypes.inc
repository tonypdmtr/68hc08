;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

                    #Exit     _FSLTYPES_
_FSLTYPES_

;Typedefs
;typedef unsigned char  UINT8;  	;unsigned 8 bit definition
;typedef unsigned short UINT16; 	;unsigned 16 bit definition
;typedef unsigned long  UINT32; 	;unsigned 32 bit definition
;typedef signed char    INT8;   	;signed 8 bit definition
;typedef short          INT16;  	;signed 16 bit definition
;typedef long int       INT32;  	;signed 32 bit definition

; Definitions

_OUT                equ       1
_IN                 equ       0

;Macros

FLAG_SET            macro     BitNumber,Register
                    @bset     ~1~\,~2~
                    endm

FLAG_CLR            macro     BitNumber,Register
                    @bclr     ~1~\,~2~
                    endm

FLAG_CHK            macro     BitNumber,Register
                    #push
                    #spauto   :sp
                    psha
                    lda       ~2~
                    bit       #1<~#1~
                    pula
                    #pull
                    endm

False               equ       0x00
True                equ       0x01
