CONFIG  EQU  $001F
PORTB   EQU  $0001
DDRB    EQU  $0005

                ORG     $60
direction       ds      1

                ORG     $8000

START           mov     #$01,CONFIG     ; disable COP
                mov     #$FF,DDRB
                mov     #$01,PORTB
                mov     #$0,direction

LOOP            ldhx    #60000
next_delay      aix     #-1
                cphx    #0
                bne     next_delay

                tst     direction
                bne     GO_RIGHT
                lsl     PORTB
                tst     PORTB
                bne     SHIFT_OKAY
                mov     #$80,PORTB
                mov     #1,direction
                bra     SHIFT_OKAY

GO_RIGHT        lsr     PORTB
                tst     PORTB
                bne     SHIFT_OKAY
                mov     #$01,PORTB
                mov     #0,direction

SHIFT_OKAY
                bra     LOOP

                ORG     $FFFE
                dw      START           ; Reset vector
