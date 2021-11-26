SERIAL_PIN          pin       PORTB

;*******************************************************************************

EMUL_SCI_INIT       proc
                    ldhx      #WAIT_START_BIT
                    sthx      funcEmulSci
                    ldhx      EMULRXBUF
                    sthx      ptrEmulSci
                    bclr      SERIAL_PIN+DDR
                    rts

;*******************************************************************************
; 8 N 1 = 1 Startbit 8 Databits 1 Stopbit

WAIT_START_BIT      proc
                    beq       Done@@
                    ldhx      #START1_OKAY
                    sthx      funcEmulSci
                    mov       #2,countx
                    clr       RSBYTE
                    mov       #8,bitcount
Done@@              rts

;*******************************************************************************

?SetError           proc
                    inc       error
                    bra       EMUL_SCI_INIT

;*******************************************************************************

START1_OKAY         proc
                    beq       ?SetError
                    dbnz      countx,Done@@
                    ldhx      #BIT_CHECK
                    sthx      funcEmulSci
                    mov       #4,countx
Done@@              rts

;*******************************************************************************

BIT_CHECK           proc
                    dbnz      countx,Done@@
                    tsta
                    clc
                    beq       Go@@
                    sec
Go@@                ror       RSBYTE
                    mov       #4,countx
                    dbnz      bitcount,Done@@
;                   bra       StopBitInit
Done@@              equ       :AnRTS

;*******************************************************************************

StopBitInit         proc
                    mov       #4,countx
                    ldhx      #STOP_BIT
                    sthx      funcEmulSci
                    rts

;*******************************************************************************

STOP_BIT            proc
                    dbnz      countx,Done@@
                    tsta
                    bne       ?SetError

                    ldhx      ptrEmulSci
                    lda       RSBYTE
                    coma
                    sta       ,x
                    aix       #1
                    sthx      ptrEmulSci
                    cphx      #EMULRXBUF+2
                    bhs       EMUL_EVALUATE
;                   bra       GoWaitStartBit
Done@@              equ       :AnRTS

;*******************************************************************************

GoWaitStartBit      proc
                    ldhx      #WAIT_START_BIT
                    sthx      funcEmulSci
                    rts

;*******************************************************************************

EMUL_EVALUATE       proc
                    lda       EMULRXBUF           ; RAM or Ports ?
                    cmpa      #'A'
                    bne       _@@

                    cphx      #EMULRXBUF+5
                    blo       GoWaitStartBit

                    ldhx      #EMUL_SET_A
                    sthx      funcEmulSci
                    rts

_@@                 ldhx      #RAM_PORT
                    sthx      funcEmulSci
                    rts

;*******************************************************************************

EMUL_SET_A          proc
                    lda       EMULRXBUF           ; 'A'
                    add       EMULRXBUF+1         ; address high
                    add       EMULRXBUF+2         ; address low
                    add       EMULRXBUF+3         ; value
                    cmpa      EMULRXBUF+4         ; checksum
                    bne       Done@@

                    ldhx      EMULRXBUF+1         ; 1+2 adresse
                    lda       EMULRXBUF+3         ; value
                    sta       ,x

Done@@              jmp       EMUL_SCI_INIT

;*******************************************************************************

RAM_PORT            proc
                    lda       EMULRXBUF
                    cbeqa     #'B',SEND_RAM
                    cbeqa     #'D',SEND_PORT
                    jmp       EMUL_SCI_INIT

;*******************************************************************************

SCI_ERROR           proc
                    inc       SCI_ERROR_COUNT
                    jmp       EMUL_SCI_INIT

;*******************************************************************************

SEND_PORT           proc
                    clrhx
                    bra       SavePtrSCI

;*******************************************************************************

SEND_RAM            proc
                    ldhx      #RAMStart
                    sthx      ptrEmulSci

                    lda       EMULRXBUF+1         ; 8-bit address
                    add       ptrEmulSci+1
                    sta       ptrEmulSci+1
                    clra
                    adc       ptrEmulSci
                    sta       ptrEmulSci
                    ldhx      ptrEmulSci

SavePtrSCI          sthx      ptrEmulSci          ; pointer to tx-address

                    mov       #64,iTxBytes        ; number of bytes = 64
                    ldhx      #EMUL_TX_INIT
                    sthx      funcEmulSci
                    rts

;*******************************************************************************

EMUL_TX_INIT        proc
                    ldhx      #TX_DELAY
                    sthx      funcEmulSci
                    mov       #50,txcount         ; 50 x 104 = 5 msec
                    rts

;*******************************************************************************

TX_DELAY            proc
                    dbnz      txcount,Done@@
                    bset      SERIAL_PIN+DDR
                    ldhx      #TX_START_BIT
                    sthx      funcEmulSci
                    mov       #4,txcount
Done@@              rts

;*******************************************************************************

TX_START_BIT        proc
                    dbnz      txcount,Done@@

                    mov       #4,txcount

                    bclr      SERIAL_PIN

                    ldhx      ptrEmulSci
                    mov       x+,ShiftByte
                    sthx      ptrEmulSci
                    dec       iTxBytes

                    clr       SerCounter          ; Counter auf Null

                    ldhx      #TX_ROUTINE
                    sthx      funcEmulSci
Done@@              rts

;*******************************************************************************

TX_ROUTINE          proc
                    dbnz      txcount,Done@@

                    mov       #4,txcount

                    lsr       ShiftByte           ; shift right
                    bcs       _1@@

                    bclr      SERIAL_PIN
                    bra       Cont@@

_1@@                bset      SERIAL_PIN

Cont@@              inc       SerCounter
                    lda       SerCounter
                    cmpa      #8                  ; 8 Bits sent
                    bne       Done@@

                    ldhx      #TX_STOP_BIT        ; send with 1 StopBit
                    sthx      funcEmulSci
Done@@              rts

;*******************************************************************************

TX_STOP_BIT         proc
                    dbnz      txcount,Done@@

                    mov       #4,txcount

                    bset      SERIAL_PIN

                    lda       iTxBytes
                    jeq       SerialDone

                    ldhx      #TX_START_BIT
                    sthx      funcEmulSci

Done@@              rts

;*******************************************************************************

SerialDone          equ       EMUL_SCI_INIT
