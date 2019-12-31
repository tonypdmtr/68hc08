;*******************************************************************************
;* Include   : MCU.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : General MCU selection for ASM8
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2019 by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/mcu.html
;*******************************************************************************

?                   macro
          #ifb ~1~
                    %~0~      GB60,QE8,QE32,QE128,QG8,QT4,QT4A,QY4,QD4,QD2,DZ32,DZ60,FL16,SH8,PA16,PA32,GP32,LJ12,AC32,AC96,PL4,PL16
                    mexit
          #endif
                    mdo
          #ifdef ~{:mloop}.~
                    #Uses     ~{:mloop}.~.inc
          #endif
                    mloop     :n
                    #Hint     Undefined MCU (assuming \@~1~\@)
                    #Uses     ~1~.inc
                    endm

                    @?
