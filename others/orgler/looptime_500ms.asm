PORTD   EQU $0003
DDRD    EQU $0007
CONFIG1 EQU $001F
TSC     EQU $0020
TSC0    EQU $0025
TCH0H   EQU $0026
TCH0L   EQU $0027

                org   $0080           ; RAM address
count1          ds    1

                org    $F000
START           mov   #$01,CONFIG1    ; disable COP
                mov   #$04,DDRD
                mov   #$30,TSC        ; Timer STOP and RESET
                mov   #$14,TSC0       ; set TIMER action: toggle on output compare
                mov   #0,TSC          ; start the TIMER

LOOP            lda   TSC0
                bpl   LOOP            ; wait until BIT7 is set
                and   #$7F
                sta   TSC0            ; clear the CH0F flag
                lda   TCH0H
                add   #$60
                sta   TCH0H           ; add $6000
                mov   #0,TCH0L        ; write to low byte
;               =================
                lda   count1
                inca
                cmp   #50             ; T = decimal
                blo   SAVE_COUNT1
                lda   PORTD
                eor   #$04
                sta   PORTD           ; toggle
                clra
SAVE_COUNT1     sta     count1
;               =================
                bra   LOOP

                org $FFFE
                dw  START                   ; Reset Vector

;PORTD BIT [PIN 19] output frequency 50 Hz
;PORTD BIT [PIN 17] output frequency  1 Hz
