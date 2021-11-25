CONFIG  EQU  $001F
PORTB   EQU  $0001
DDRB    EQU  $0005

                ORG     $8000

START           mov     #$01,CONFIG     ; disable COP
                mov     #$FF,DDRB
                mov     #$80,PORTB

LOOP            ldhx    #60000
next_delay      aix     #-1
                cphx    #0
                bne     next_delay

                lsr     PORTB
                tst     PORTB
                bne     SHIFT_OKAY
                mov     #$80,PORTB
SHIFT_OKAY
                bra     LOOP

                ORG     $FFFE
                dw      START           ; Reset vector
