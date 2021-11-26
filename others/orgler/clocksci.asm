*** Orgler electronic CLOCKSCI.ASM ****

RAMStart       EQU  $0080
RomStart       EQU  $F000            ;Valid for all JL3, JK3, JK
VectorStart    EQU  $FFDE

$Include 'jl3regs.inc'             ;For the 68HC908JL3, 68HC908JK3, 68HC908JK1
$include 'rampage.inc'

           org RomStart
$include 'tisr.inc'
*********************************************************************
MainInit          rsp
                  ldhx     #$80             ; Start for clearing RAM
NextRamClear      clr     0,X
                  incx
                  cmpx    #$FB              ; Clear RAM from $00-$FB
                  bne     NextRamClear
*----------------------------------------------------------------
                  mov    #0,PORTD
                  lda    #%11101000
                  sta    DDRD
*--------------------------------------------
                  bsr    EMUL_SCI_INIT
                  bsr    Init_Timer
                  cli
**********************************************************************
**********************************************************************
LOOP              sta     COPCTL
                  brclr   7,timebase,LOOP
                  bclr    7,timebase
*--------------------------------------
                 lda    loopcount
                 inca
                 cmp    #200           ; 200 * 5 = 1 second
                 blo    Save_LoopCount
*                 ---
                 lda    second
                 inca
                 cmp    #60
                 blo    SaveSecond
                 clra
SaveSecond       sta    second
*                ----

                 clra
Save_LoopCount   sta    loopcount
                 cmp    #40
                 blo    LED_ON
                 bclr   3,PORTD
                 bra    LED_OK

LED_ON           bset   3,PORTD
LED_OK
*               ----------------------------
                bra     LOOP
**************************************************************
$include 'emulsci.inc'
$include 'vectors.inc'
