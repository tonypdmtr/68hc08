$include 'mr_regs.inc'

                ORG     $8000

START           mov     #$91,CONFIG     ; disable COP
                mov     #$FF,DDRA       ;PORTA all outputs
                mov     #0,DDRB
                mov     #$FF,DDRE       ;PORTE all outputs

                mov     #$70,ADCLK     ; 8 Bit Modus

LOOP            lda     #0
                sta     ADSCR

                ldhx    #$1000
next_delay      aix     #-1
                cphx    #$0
                bne     next_delay

                ldhx    ADRH
                stx     PORTA

                lda     PORTE
                eor     #$FF
                sta     PORTE

                bra     LOOP

                ORG     $FFFE
                dw      START      ; Reset vector
