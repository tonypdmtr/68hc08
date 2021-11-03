;*******************************************************************************
; Purpose: Special COP reset sequence for PA and compatible derivatives
; Input  : None
; Output : None
; Note(s):
          #ifmdef COP
                    #Drop     COP
          #endif
COP                 macro     #SAVE#              ;kick the COP watchdog
          #ifdef NO_COP||!WDOG_CNT
                    mexit
          #endif
          #ifparm ~1~ = #SAVE#
            #ifdef KickCop
                    merror    KickCop proc is already defined
            #endif
                    #push
                    #MapOff
                    #Cycles
KickCop             proc
                    push
                    tpa
                    sei
                    ldhx      #$A602
                    #temp     :ccycles
                    sthx      WDOG_CNT
                    ldhx      #$B480
                    sthx      WDOG_CNT
          #if :ccycles-:temp > 16
                    #Warning  COP sequence longer than 16 cycles ({:ccycles-:temp})
          #endif
                    tap
                    pull
                    rtc
KICKCOP_CYCLES      equ       :cycles
                    #pull
                    mexit
          #endif
          #ifdef KickCop
                    #temp1    :ocycles
                    #temp2    :cycles
                    call      KickCop
                    #temp     :cycles+KICKCOP_CYCLES
                    #Cycles   :temp1
                    #Cycles   :temp2+:temp
          #endif
                    endm
;-------------------------------------------------------------------------------
DisableCOP          macro
                    push
                    tpa
                    sei
                    ldhx      #$C520
                    #temp     :ccycles
                    sthx      WDOG_CNT
                    ldhx      #$D928
                    sthx      WDOG_CNT
          #if :ccycles-:temp > 16
                    #Warning  COP sequence longer than 16 cycles ({:ccycles-:temp})
          #endif
                    clrx
                    stx       WDOG_CS1
                    stx       WDOG_CS2
                    comx
                    stx       WDOG_TOVAL
                    stx       WDOG_TOVAL+1
                    tap
                    pull
                    endm
