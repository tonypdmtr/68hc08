                    org       VectorStart-1

dummy_isr           rti                           ;return

;*******************************************************************************
                    #VECTORS  VectorStart
;*******************************************************************************

                    dw        dummy_isr           ;ADC Conversion Complete Vector
                    dw        dummy_isr           ;Keyboard Vector
                    dw        dummy_isr           ;(No Vector Assigned $FFE2-$FFE3)
                    dw        dummy_isr           ;(No Vector Assigned $FFE4-$FFE5)
                    dw        dummy_isr           ;(No Vector Assigned $FFE6-$FFE7)
                    dw        dummy_isr           ;(No Vector Assigned $FFE8-$FFE9)
                    dw        dummy_isr           ;(No Vector Assigned $FFEA-$FFEB)
                    dw        dummy_isr           ;(No Vector Assigned $FFEC-$FFED)
                    dw        dummy_isr           ;(No Vector Assigned $FFEE-$FFEF)
                    dw        dummy_isr           ;(No Vector Assigned $FFF0-$FFF1)
                    dw        dummy_isr           ;TIM1 Overflow Vector
                    dw        dummy_isr           ;TIM1 Channel 1 Vector
                    dw        T_ISR               ;TIM1 Channel 0 Vector
                    dw        dummy_isr           ;(No Vector Assigned $FFF8-$FFF9)
                    dw        dummy_isr           ;~IRQ1
                    dw        dummy_isr           ;SWI Vector
                    dw        MainInit            ;Reset Vector
