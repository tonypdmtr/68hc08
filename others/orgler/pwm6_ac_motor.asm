RAMStart    EQU $0060
RomStart    EQU $8000
VectorStart EQU $FFD2

$Include 'mr_regs.inc'

        org RAMStart

PTR_SINUS       ds 3
LOOPTIMING      ds 1
LOOPCOUNTER     ds 1
TEMP            ds 1
TIMER           ds 1

              org RomStart
;******** sine table with 192 base points
SINE_TABLE
 DB 128,132,136,140,145,149,153,157   ; line 1
 DB 161,165,169,173,177,180,184,188   ; line 2
 DB 192,195,199,202,205,209,212,215   ; line 3
 DB 218,221,223,226,229,231,234,236   ; line 4
 DB 238,240,242,244,245,247,248,250   ; line 5
 DB 251,252,253,253,254,254,255,255   ; line 6
 DB 255,255,255,254,254,253,253,252   ; line 7
 DB 251,250,248,247,245,244,242,240   ; line 8
 DB 238,236,234,231,229,226,223,221   ; line 9
 DB 218,215,212,209,205,202,199,195   ; line 10
 DB 191,188,184,180,177,173,169,165   ; line 11
 DB 161,157,153,149,145,140,136,132   ; line 12
 DB 128,124,120,116,111,107,103,099   ; line 13
 DB 095,091,087,083,079,076,072,068   ; line 14
 DB 064,061,057,054,051,047,044,041   ; line 15
 DB 038,035,033,030,027,025,022,020   ; line 16
 DB 018,016,014,012,011,009,008,006   ; line 17
 DB 005,004,003,003,002,002,001,001   ; line 18
 DB 001,001,001,002,002,003,003,004   ; line 19
 DB 005,006,008,009,011,012,014,016   ; line 20
 DB 018,020,022,025,027,030,033,035   ; line 21
 DB 038,041,044,047,051,054,057,061   ; line 22
 DB 065,068,072,076,079,083,087,091   ; line 23
 DB 095,099,103,107,111,116,120,124   ; line 24

;*****REPEAT TABLE*****
 DB 128,132,136,140,145,149,153,157   ; line 25
 DB 161,165,169,173,177,180,184,188   ; line 26
 DB 192,195,199,202,205,209,212,215   ; line 27
 DB 218,221,223,226,229,231,234,236   ; line 28
 DB 238,240,242,244,245,247,248,250   ; line 29
 DB 251,252,253,253,254,254,255,255   ; line 30
 DB 255,255,255,254,254,253,253,252   ; line 31
 DB 251,250,248,247,245,244,242,240   ; line 32
 DB 238,236,234,231,229,226,223,221   ; line 33
 DB 218,215,212,209,205,202,199,195   ; line 34
 DB 191,188,184,180,177,173,169,165   ; line 35
 DB 161,157,153,149,145,140,136,132   ; line 36
 DB 128,124,120,116,111,107,103,099   ; line 37
 DB 095,091,087,083,079,076,072,068   ; line 38
 DB 064,061,057,054,051,047,044,041   ; line 39
 DB 038,035,033,030,027,025,022,020   ; line 40
 DB 018,016,014,012,011,009,008,006   ; line 41
 DB 005,004,003,003,002,002,001,001   ; line 42
 DB 001,001,001,002,002,003,003,004   ; line 43
 DB 005,006,008,009,011,012,014,016   ; line 44
 DB 018,020,022,025,027,030,033,035   ; line 45
 DB 038,041,044,047,051,054,057,061   ; line 46
 DB 065,068,072,076,079,083,087,091   ; line 47
 DB 095,099,103,107,111,116,120,124   ; line 48

;*****REPEAT TABLE*****
 DB 128,132,136,140,145,149,153,157   ; line 25
 DB 161,165,169,173,177,180,184,188   ; line 26
 DB 192,195,199,202,205,209,212,215   ; line 27
 DB 218,221,223,226,229,231,234,236   ; line 28
 DB 238,240,242,244,245,247,248,250   ; line 29
 DB 251,252,253,253,254,254,255,255   ; line 30
 DB 255,255,255,254,254,253,253,252   ; line 31
 DB 251,250,248,247,245,244,242,240   ; line 32
 DB 238,236,234,231,229,226,223,221   ; line 33
 DB 218,215,212,209,205,202,199,195   ; line 34
 DB 191,188,184,180,177,173,169,165   ; line 35
 DB 161,157,153,149,145,140,136,132   ; line 36
 DB 128,124,120,116,111,107,103,099   ; line 37
 DB 095,091,087,083,079,076,072,068   ; line 38
 DB 064,061,057,054,051,047,044,041   ; line 39
 DB 038,035,033,030,027,025,022,020   ; line 40
 DB 018,016,014,012,011,009,008,006   ; line 41
 DB 005,004,003,003,002,002,001,001   ; line 42
 DB 001,001,001,002,002,003,003,004   ; line 43
 DB 005,006,008,009,011,012,014,016   ; line 44
 DB 018,020,022,025,027,030,033,035   ; line 45
 DB 038,041,044,047,051,054,057,061   ; line 46
 DB 065,068,072,076,079,083,087,091   ; line 47
 DB 095,099,103,107,111,116,120,124   ; line 48

                org $9000
**************************************************************
* DUMMY_ISR - Dummy Interrupt Service Routine. *
**************************************************************
dummy_isr       rti             ; interrupt return

Main_Init:      mov     #$01,CONFIG     ;INDEP=0, complementary output  COPD=0 (cop enabled)
;               ---------------
                bclr    5,PCTL          ; set PLL activ
                lda     #$33
                sta     PPG
                bset    5,PCTL
                bset    4,PCTL
;               ----------------------- set Stack Pointer
                ldhx    #$02FF
                txs
;--------------------------------- clear RAM ------------
                clr     TEMP
                ldhx    #RAMStart
next_x          mov     TEMP,X+
                cphx    #$0300
                blo     next_x
;---------------------------------------
                bset    3,DDRB                  ; only for test to see interrupt time
                bset    6,DDRB                  ; only for test to see loop time
                bsr     Init_PWMMC
                cli                             ; Allow interrupts to happen
*************************************************************
**************************************************************
LOOP            sta    $FFFF                    ;   reset watchdog if cop enabled
                brclr 7,LOOPTIMING,LOOP         ;   Realtime approx. 5 msec
                bclr  7,LOOPTIMING
* -----
                dec     LOOPCOUNTER
                bne     LoopCountOkay

                lda     PORTB
                and     #%01000000
                beq     set_6
                bclr    6,PORTB
                bra     ok_6
set_6           bset    6,PORTB
ok_6
                mov     #200,LOOPCOUNTER
LoopCountOkay
                bra LOOP

**************************************************************
* Init_PWM for 3 phase sine output
**************************************************************
Init_PWMMC      ldhx  #256           ; Load Counter Modulo Register with 256
                sthx   PMODH
                mov    #0,DEADTM

                ldhx   #$8000
                sthx   PTR_SINUS

                ldhx   #20
                sthx   PVAL1H

                ldhx   #40
                sthx   PVAL3H

                ldhx   #80
                sthx   PVAL5H

                mov   #0,PCTL2           ; Reload every PWM cycle, fastest PWM frequency
                mov   #$23,PCTL1         ; interrupt, load parameters, PWM on
                bset  1,PCTL1            ; force reload on PWM parameters
                mov   #%00111111,PWMOUT
                rts
***********************************************************

INT_PWM6        pshh
                lda      PCTL1
                bclr     4,PCTL1

                ldhx     PTR_SINUS
                lda      0,X            ; indexed H:X with offset
                sta      PVAL1L

                lda     64,X
                sta     PVAL3L

                lda     128,X
                sta     PVAL5L

                bset    1,PCTL1

                inc     PTR_SINUS+2
                bne     ptr_ok
                lda     PTR_SINUS+1
                inca
                cmp     #192
                blo     save_a
                clra
save_a          sta     PTR_SINUS+1
ptr_ok
****************************************
                dec     TIMER
                bne     Timer_Okay
                mov     #$FF,LOOPTIMING
                mov     #$24,TIMER
Timer_Okay
*****************************************
                lda PORTB
                eor #%00001000
                sta PORTB

                pulh
                rti

**************************************************************
* Vectors - Timer Interrupt Service Routine.                 *
**************************************************************
   org  VectorStart

 dw  dummy_isr    ; SCI Transmit Vector
 dw  dummy_isr    ; SCI Receive Vector
 dw  dummy_isr    ; SCI Error Vector
 dw  dummy_isr    ; SPI Transmit Vector
 dw  dummy_isr    ; SPI Receive Vector
 dw  dummy_isr    ; ADC Conversion Complete
 dw  dummy_isr    ; TIM2 Overflow Vector
 dw  dummy_isr    ; TIM2 Channel 1 Vector
 dw  dummy_isr    ; TIM2 Channel 0 Vector
 dw  dummy_isr    ; TIM1 Overflow Vector
 dw  dummy_isr    ; TIM1 Channel 3 Vector  PE7
 dw  dummy_isr    ; TIM1 Channel 2 Vector
 dw  dummy_isr    ; TIM1 Channel 1 Vector
 dw  dummy_isr    ; TIM1 Channel 0 Vector
 dw  INT_PWM6     ; PWMMC Vector
 dw  dummy_isr    ; Fault 4 Vector
 dw  dummy_isr    ; Fault 3 Vector
 dw  dummy_isr    ; Fault 2 Vector
 dw  dummy_isr    ; Fault 1 Vector
 dw  dummy_isr    ; PLL Vector
 dw  dummy_isr    ; ~IRQ1 Vector
 dw  dummy_isr    ; SWI Vector
 dw  Main_Init    ; Reset Vector
