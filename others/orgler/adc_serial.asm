;*******************************************************************************
                    #Uses     mr_regs.inc
;*******************************************************************************
                    #ROM      $8000

Start               proc
                    mov       #$91,CONFIG         ;disable COP
                    mov       #$55,PORTA
                    mov       #$FF,DDRA
                    clr       DDRB
                    mov       #$FF,DDRE

                    mov       #$70,ADCLK          ;8 Bit Modus

                    mov       #$02,SCBR           ;9600 bps
                    mov       #$40,SCC1
                    mov       #$0C,SCC2           ;RX and TX enabled
                                                  ;only TX is in use
Loop@@              clr       ADSCR

                    ldhx      #$1000
_@@                 aix       #-1
                    cphx      #0
                    bne       _@@

                    ldhx      ADRH
                    stx       PORTA

                    tst       SCS1                ;read first status register
                    stx       SCDR                ;send byte

                    lda       PORTE
                    eor       #$FF
                    sta       PORTE

                    bra       Loop@@

;*******************************************************************************
                    #VECTORS  $FFFE
                    dw        Start               ;Reset vector
