$include        'mr_regs.inc'

                org $80
PTR1            ds 2

                ORG    $8000

SineTable       DB     128,177,217,245,255,245,217,177,128
                DB     79,39,11,1,11,39,79

Start           mov     #$91,CONFIG
                rsp
                mov     #0,PORTA
                mov     #$FF,DDRA
                ldhx    #SineTable
                sthx    PTR1

                mov     #$02,SCBR       ;  Baudrate 9600
                mov     #$40,SCC1
                mov     #$0C,SCC2       ; RX and TX enabled
                                        ; only TX is in use
Loop            ldhx    PTR1
                mov     X+,PORTA
                cphx    #SineTable+16
                blo     save_ptr1
                ldhx    #SineTable
save_ptr1       sthx    PTR1

                lda     PORTA
                ldx     SCS1  ; read first status register
                sta     SCDR            ; send byte

                bsr     DELAY

                bra     Loop

DELAY           ldhx    #$F000
next_delay      aix     #-1
                cphx    #0
                bne     next_delay
                rts

                org     $FFFE
                dw      Start
