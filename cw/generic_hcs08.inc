;[PROCESSED BY CW.AWK]
                    #ListOff
                    #Uses     cw.inc
                    #ListOn

; this just a generic bare minimum, which can be used for own extensions

PTAD                equ       $0000               ; Port A
PTADD               equ       $0003               ; Port A data direction

SRS                 equ       $1800               ; System Reset Status register; COP controlled by bit 5
