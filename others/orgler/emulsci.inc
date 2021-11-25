***************************************************
EMUL_SCI_INIT   ldhx   #WAIT_START_BIT
                sthx   funcEmulSci
                ldhx   #EMULRXBUF
                sthx   ptrEmulSci
                jsr    SetPinToInport
                rts
****************************************************
* 8 N 1 = 1 Startbit 8 Databits 1 Stopbit
****************************************************
WAIT_START_BIT  beq    exit_0
                ldhx   #START1_OKAY
                sthx   funcEmulSci
                lda    #2
                sta    countx
                clr    RSBYTE
                lda    #8
                sta    bitcount
exit_0          rts
*---------------------------------
set_error       inc    error
                bra    EMUL_SCI_INIT

START1_OKAY     beq    set_error
                dec    countx
                bne    exit_1
                ldhx   #BIT_CHECK
                sthx   funcEmulSci
                lda    #4
                sta    countx
exit_1          rts
*-----------------------------------
BIT_CHECK       dec    countx
                bne    exit_2
                clc
                tsta
                beq    ShiftRsbyte
                sec
ShiftRsbyte     ror    RSBYTE
                lda    #4
                sta    countx
                dec    bitcount
                beq    StopBitInit
exit_2          rts

StopBitInit     lda   #4
                sta   countx
                ldhx  #STOP_BIT
                sthx  funcEmulSci
                rts

STOP_BIT        dec  countx
                bne  exit_2
                tsta
                bne     set_error
*  -----
                lda     RSBYTE
                coma
                ldhx    ptrEmulSci
                sta     ,X
                incx
                sthx   ptrEmulSci
                cphx   #EMULRXBUF+2
                bhs    EMUL_EVALUATE
*  ------
GoWaitStartBit  ldhx   #WAIT_START_BIT
                sthx   funcEmulSci
                rts
****************************************************************
EMUL_EVALUATE   lda   EMULRXBUF      ;RAM or Ports ?
                 cmpa  #'A'
                 bne   EmulEvaluate2
*  ---------
                 cphx #EMULRXBUF+5
                 blo GoWaitStartBit

                 ldhx #EMUL_SET_A
                 sthx funcEmulSci
                 rts

EmulEvaluate2   ldhx   #RAM_PORT
                sthx   funcEmulSci
                rts
**************************************************************
EMUL_SET_A      lda  EMULRXBUF      ;'A'
                add  EMULRXBUF+1    ; address high
                add  EMULRXBUF+2    ; address low
                add  EMULRXBUF+3    ; value
                cmpa EMULRXBUF+4    ; checksum
                bne  EMUL_A_EXIT

                ldhx  EMULRXBUF+1          ; 1+2 adresse
                lda   EMULRXBUF+3          ; value
                sta   0,X

EMUL_A_EXIT     jmp   EMUL_SCI_INIT      ; rts included
**************************************************************
RAM_PORT        lda    EMULRXBUF
                cmpa   #'B'
                beq    SEND_RAM
                cmpa   #'D'
                beq    SEND_PORT
                jmp    EMUL_SCI_INIT           ; rts included
****************************************************************
SCI_ERROR       inc    SCI_ERROR_COUNT
                jmp    EMUL_SCI_INIT
****************************************************************
SEND_PORT       ldhx    #0
                bra     saveptrSCI
SEND_RAM        ldhx    #RAMStart
                sthx    ptrEmulSci

                lda    EMULRXBUF+1      ;8-Bit-Adresse
                add    ptrEmulSci+1
                sta    ptrEmulSci+1
                lda    ptrEmulSci
                adc    #0
                sta    ptrEmulSci
                ldhx   ptrEmulSci

saveptrSCI      sthx   ptrEmulSci             ;pointer to tx-address

              lda    #64                     ;number of bytes = 64
TxInitGo      sta    iTxBytes
              ldhx   #EMUL_TX_INIT
              sthx   funcEmulSci
              rts
********************************************************************
EMUL_TX_INIT   ldhx  #TX_DELAY
               sthx  funcEmulSci
               lda   #50             ;50 x 104 =   5 msec
               sta   txcount
               rts
*=============================================
TX_DELAY       dec   txcount
               beq   *+3
               rts
               bsr   SetPinToOutport
               ldhx  #TX_START_BIT
               sthx  funcEmulSci
               lda   #4
               sta   txcount
               rts
*============================================
TX_START_BIT   dec   txcount
               beq   *+3
               rts
               lda   #4
               sta   txcount
*  ---------------
               bsr    SetOutPortZero

               ldhx    ptrEmulSci
               mov     X+,ShiftByte
               sthx    ptrEmulSci
               dec     iTxBytes

               clr      SerCounter     ; Counter auf Null
*  ---------------
               ldhx #TX_ROUTINE
               sthx funcEmulSci
               rts
*=====================================
TX_ROUTINE     dec txcount
               beq *+3
               rts
               lda #4
               sta txcount

               lsr   ShiftByte          ;shift rigth
               bcs   BitIsOne

BitIsNull      bsr   SetOutPortZero
               bra   EndShift

BitIsOne        bsr SetOutPortOne

EndShift        inc    SerCounter
                lda    SerCounter
                cmpa   #8              ;8 Bits sent
                bne    Exit_TX
*  ---------------------
                ldhx   #TX_STOP_BIT    ;send with 1 StopBit
                sthx   funcEmulSci
Exit_TX         rts
*------------------------------------------------------
TX_STOP_BIT     dec   txcount
                beq   *+3
                rts
                lda   #4
                sta   txcount

                bsr   SetOutPortOne
*  ------------------
                lda   iTxBytes
                beq   SerialDone
*  ---
                ldhx  #TX_START_BIT
                sthx  funcEmulSci
*  --------------------
ExitSerial      rts
SerialDone      jmp   EMUL_SCI_INIT  ;rts included

SetOutPortOne     bset  0,PORTB
                rts
SetOutPortZero     bclr  0,PORTB
                rts
SetPinToInport  bclr  0,DDRB
                rts

SetPinToOutport bset  0,DDRB
                rts
