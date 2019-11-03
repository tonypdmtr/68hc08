;*******************************************************************************
; Purpose: Special COP reset sequence for PA and compatible derivatives
; Input  : None
; Output : None
; Note(s):
          #ifmdef COP
                    #Drop     COP
          #endif
COP                 macro     #SAVE#              ;kick the COP watchdog
          #ifndef WDOG_CNT
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
                    sthx      WDOG_CNT
                    ldhx      #$B480
                    sthx      WDOG_CNT
                    tap
                    pull
                    rtc
KICKCOP_CYCLES      equ       :cycles
                    #pull
                    mexit
          #endif
          #ifdef KickCop
                    #temp     :ocycles<16+:cycles
                    call      KickCop
?$$$                equ       :cycles+KICKCOP_CYCLES
                    #Cycles   :temp>16&$FFFF
                    #Cycles   :temp&$FFFF+?$$$
          #endif
                    endm
;-------------------------------------------------------------------------------
DisableCOP          macro
                    push
                    tpa
                    sei
                    ldhx      #$C520
                    sthx      WDOG_CNT
                    ldhx      #$D928
                    sthx      WDOG_CNT
                    clrx
                    stx       WDOG_CS1
                    stx       WDOG_CS2
                    comx
                    stx       WDOG_TOVAL
                    stx       WDOG_TOVAL+1
                    tap
                    pull
                    endm
