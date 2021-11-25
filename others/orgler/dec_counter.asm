CONFIG  EQU  $001F
PORTB   EQU  $0001
DDRB    EQU  $0005

                ORG     $8000

START           mov     #$01,CONFIG     ; disable COP
                mov     #$FF,PORTB
                mov     #$FF,DDRB
                clra

LOOP            inca
                cmpa    #10             ; T -> decimal
                blo     WRITE_PORTB
                clra
WRITE_PORTB     sta     PORTB

                ldhx    #60000           ; delay time
next_x1         aix     #-1
                cphx    #0
                bne     next_x1

                ldhx    #60000           ; delay time
next_x2         aix     #-1
                cphx    #0
                bne     next_x2

                bra     LOOP

                ORG     $FFFE
                dw      START           ; Reset vector
