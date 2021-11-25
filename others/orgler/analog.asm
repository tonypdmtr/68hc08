;*******************************************************************************
                    #Uses     mr_regs.inc
;*******************************************************************************
                    #ROM      $8000

Start               proc
                    mov       #$91,CONFIG         ;disable COP
                    mov       #$FF,DDRA           ;PORTA all outputs
                    clr       DDRB
                    mov       #$FF,DDRE           ;PORTE all outputs

                    mov       #$70,ADCLK          ;8 Bit Modus

Loop@@              clr       ADSCR

                    ldhx      #$1000
_@@                 aix       #-1
                    cphx      #0
                    bne       _@@

                    ldhx      ADRH
                    stx       PORTA

                    lda       PORTE
                    eor       #$FF
                    sta       PORTE

                    bra       Loop@@

;*******************************************************************************
                    #VECTORS
;*******************************************************************************
                    org       $FFFE
                    dw        Start               ;Reset vector
