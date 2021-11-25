RamStart     EQU  $0060
RomStart     EQU  $8000         ; Valid Rom for MR32

$Include 'mr_regs.inc'

                ORG     RamStart
TEMP   ds  1

                ORG     RomStart
START:          mov     #$91,CONFIG        ; EDGE=1, INDEP=1, COPD=1 (cop disabled)
                rsp                    ; reset stack pointer

;               mov     #1,SCBR        ; 19200 Baud
                mov     #2,SCBR        ; 9600 Baud
                mov     #$40,SCC1      ; set BIT5 to enable the SCI
                mov     #$0C,SCC2      ; receiver and transmitter enabled

LOOP            bsr    CHECK_RS232
                bra    LOOP

CHECK_RS232     brclr  5,SCS1,EXIT_RS232
                mov   #$FF,DDRB         ; set PORTB all outputs
                lda   SCDR
                cmp   #'T'
                beq   SEND_TEXT
                sta   PORTB             ; view RS232 BYTE on PORTB
                sta   SCDR              ; send received Byte
EXIT_RS232      rts

SEND_TEXT       ldhx    #TEXT1
NEXT_BYTE       mov     X+,TEMP       ; Variable TEMP
                lda     TEMP
                beq     EXIT_SEND
                sta     SCDR
WAIT            brclr   7,SCS1,WAIT
                bra     NEXT_BYTE
EXIT_SEND       rts

TEXT1  db  $0D,$0A
       db  'Hello from serial interface'
       db  $0D,$0A,$00

               ORG $FFFE
               dw  START
