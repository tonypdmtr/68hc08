$include 'mr_regs.inc'

                ORG     $8000

START           mov     #$91,CONFIG     ; disable COP
                mov     #$55,PORTA
                mov     #$FF,DDRA
                mov     #0,DDRB
                mov     #$FF,DDRE

                mov     #$70,ADCLK     ; 8 Bit Modus

                mov     #$02,SCBR       ;  Baudrate 9600
                mov     #$40,SCC1
                mov     #$0C,SCC2       ; RX and TX enabled
                                        ; only TX is in use
LOOP            lda     #0
                sta     ADSCR

                ldhx    #$1000
next_delay      aix     #-1
                cphx    #$0
                bne     next_delay

                ldhx    ADRH
                stx     PORTA

                lda     SCS1  ; read first status register
                stx     SCDR            ; send byte

                lda     PORTE
                eor     #$FF
                sta     PORTE

                bra     LOOP

                ORG     $FFFE
                dw      START           ; Reset vector
