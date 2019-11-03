;*******************************************************************************
; Purpose: Special COP reset sequence for DZ/FL and compatible derivatives
; Input  : None
; Output : None
; Note(s):
          #ifmdef COP
                    #Drop     COP
          #endif
COP                 macro     #SAVE#              ;kick the COP watchdog
          #ifndef COP
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
                    psha
                    lda       #$55
                    sta       COP
                    coma
                    sta       COP
                    pula
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
