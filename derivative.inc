;*******************************************************************************
;* Purpose   : CodeWarrior MCU selector
;*           : (Makes it easier to transfer source code from CodeWarrior to ASM8)
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : Public Domain.  Prepared by Tony Papadimitriou <tonyp@acm.org>
;* Original  : http://www.aspisys.com/code/hc08/derivative.html
;*******************************************************************************

                    #HomeDir  cw
                    #Uses     cw.inc

?                   macro     conditional,filename
          #ifdef ?DONE
                    mexit
          #endif
                    mset      0,~1~
          #ifdef ~text~
?DONE
                    #Include  ~2~
          #else ifdef ~TEXT~
?DONE
                    #Include  ~2~
          #endif
                    endm

                    @?        hc08,generic.inc
                    @?        hcs08,generic_hcs08.inc
                    @?        mc13211,mc13211.inc
                    @?        mc13212,mc13212.inc
                    @?        mc13213,mc13213.inc
                    @?        mc13214,mc13214.inc
                    @?        ac8,mc9s08ac8.inc
                    @?        jm8,mc9s08jm8.inc
                    @?        ll8,mc9s08ll8.inc
                    @?        qa2,mc9s08qa2.inc
                    @?        qa4,mc9s08qa4.inc
                    @?        qd2,mc9s08qd2.inc
                    @?        qd4,mc9s08qd4.inc
                    @?        qe4,mc9s08qe4.inc
                    @?        qe8,mc9s08qe8.inc
                    @?        qg4,mc9s08qg4.inc
                    @?        qg8,mc9s08qg8.inc
                    @?        rc8,mc9s08rc8.inc
                    @?        rd8,mc9s08rd8.inc
                    @?        re8,mc9s08re8.inc
                    @?        rt4,mc9s08rt4.inc
                    @?        rt8,mc9s08rt8.inc
                    @?        sf4,mc9s08sf4.inc
                    @?        sg4,mc9s08sg4.inc
                    @?        sg8,mc9s08sg8.inc
                    @?        sh4,mc9s08sh4.inc
                    @?        sh8,mc9s08sh8.inc
                    @?        sl8,mc9s08sl8.inc
                    @?        mpxy8300,mpxy8300.inc
                    @?        ab32,mc68hc908ab32.inc
                    @?        ap16,mc68hc908ap16.inc
                    @?        ap16a,mc68hc908ap16a.inc
                    @?        ap32,mc68hc908ap32.inc
                    @?        ap32a,mc68hc908ap32a.inc
                    @?        ap64,mc68hc908ap64.inc
                    @?        ap64a,mc68hc908ap64a.inc
                    @?        ap8,mc68hc908ap8.inc
                    @?        ap8a,mc68hc908ap8a.inc
                    @?        as32a,mc68hc908as32a.inc
                    @?        as60,mc68hc908as60.inc
                    @?        as60a,mc68hc908as60a.inc
                    @?        az32a,mc68hc908az32a.inc
                    @?        az60a,mc68hc908az60a.inc
                    @?        bd48,mc68hc908bd48.inc
                    @?        ey16,mc68hc908ey16.inc
                    @?        ey16a,mc68hc908ey16a.inc
                    @?        ey8,mc68hc908ey8.inc
                    @?        ey8a,mc68hc908ey8a.inc
                    @?        gp32,mc68hc908gp32.inc
                    @?        gr16,mc68hc908gr16.inc
                    @?        gr16a,mc68hc908gr16a.inc
                    @?        gr32a,mc68hc908gr32a.inc
                    @?        gr4,mc68hc908gr4.inc
                    @?        gr48a,mc68hc908gr48a.inc
                    @?        gr4a,mc68hc908gr4a.inc
                    @?        gr60a,mc68hc908gr60a.inc
                    @?        gr8,mc68hc908gr8.inc
                    @?        gr8a,mc68hc908gr8a.inc
                    @?        gt16,mc68hc908gt16.inc
                    @?        gt8,mc68hc908gt8.inc
                    @?        gz16,mc68hc908gz16.inc
                    @?        gz32,mc68hc908gz32.inc
                    @?        gz48,mc68hc908gz48.inc
                    @?        gz60,mc68hc908gz60.inc
                    @?        gz8,mc68hc908gz8.inc
                    @?        jb12,mc68hc908jb12.inc
                    @?        jb16,mc68hc908jb16.inc
                    @?        jb8,mc68hc908jb8.inc
                    @?        jg16,mc68hc908jg16.inc
                    @?        jk1,mc68hc908jk1.inc
                    @?        jk16,mc68hc908jk16.inc
                    @?        jk3,mc68hc908jk3.inc
                    @?        jk8,mc68hc908jk8.inc
                    @?        jl16,mc68hc908jl16.inc
                    @?        jl3,mc68hc908jl3.inc
                    @?        jl3e,mc68hc908jl3e.inc
                    @?        jl8,mc68hc908jl8.inc
                    @?        jr32,mc68hc908jr32.inc
                    @?        jw32,mc68hc908jw32.inc
                    @?        kx2,mc68hc908kx2.inc
                    @?        kx8,mc68hc908kx8.inc
                    @?        lb8,mc68hc908lb8.inc
                    @?        ld60,mc68hc908ld60.inc
                    @?        ld64,mc68hc908ld64.inc
                    @?        lj12,mc68hc908lj12.inc
                    @?        lj24,mc68hc908lj24.inc
                    @?        lk24,mc68hc908lk24.inc
                    @?        lt4,mc68hc908lt4.inc
                    @?        lt8,mc68hc908lt8.inc
                    @?        lv8,mc68hc908lv8.inc
                    @?        mr16,mc68hc908mr16.inc
                    @?        mr32,mc68hc908mr32.inc
                    @?        mr8,mc68hc908mr8.inc
                    @?        qb4,mc68hc908qb4.inc
                    @?        qb8,mc68hc908qb8.inc
                    @?        qc16,mc68hc908qc16.inc
                    @?        qc4,mc68hc908qc4.inc
                    @?        qc8,mc68hc908qc8.inc
                    @?        gl2,mc68hc908ql2.inc
                    @?        ql3,mc68hc908ql3.inc
                    @?        ql4,mc68hc908ql4.inc
                    @?        ql8,mc68hc908ql8.inc
                    @?        qt1,mc68hc908qt1.inc
                    @?        qt1a,mc68hc908qt1a.inc
                    @?        qt2,mc68hc908qt2.inc
                    @?        qt2a,mc68hc908qt2a.inc
                    @?        qt4,mc68hc908qt4.inc
                    @?        qt4a,mc68hc908qt4a.inc
                    @?        qt8,mc68hc908qt8.inc
                    @?        qy1,mc68hc908qy1.inc
                    @?        qy1a,mc68hc908qy1a.inc
                    @?        qy2,mc68hc908qy2.inc
                    @?        qy2a,mc68hc908qy2a.inc
                    @?        qy4,mc68hc908qy4.inc
                    @?        qy4a,mc68hc908qy4a.inc
                    @?        qy8,mc68hc908qy8.inc
                    @?        rf2,mc68hc908rf2.inc
                    @?        rk2,mc68hc908rk2.inc
                    @?        sr12,mc68hc908sr12.inc
                    @?        hlcqt1,mc68hlc908qt1.inc
                    @?        hlcqt2,mc68hlc908qt2.inc
                    @?        hlcqt4,mc68hlc908qt4.inc
                    @?        hlcqy1,mc68hlc908qy1.inc
                    @?        hlcqy2,mc68hlc908qy2.inc
                    @?        hlcqy4,mc68hlc908qy4.inc
                    @?        ac128,mc9s08ac128.inc
                    @?        ac16,mc9s08ac16.inc
                    @?        ac32,mc9s08ac32.inc
                    @?        ac48,mc9s08ac48.inc
                    @?        ac60,mc9s08ac60.inc
                    @?        ac96,mc9s08ac96.inc
                    @?        aw16,mc9s08aw16.inc
                    @?        aw16a,mc9s08aw16a.inc
                    @?        aw32,mc9s08aw32.inc
                    @?        aw48,mc9s08aw48.inc
                    @?        aw60,mc9s08aw60.inc
                    @?        aw8a,mc9s08aw8a.inc
                    @?        de32,mc9s08de32.inc
                    @?        de60,mc9s08de60.inc
                    @?        dn16,mc9s08dn16.inc
                    @?        dn32,mc9s08dn32.inc
                    @?        dn48,mc9s08dn48.inc
                    @?        dn60,mc9s08dn60.inc
                    @?        dv128,mc9s08dv128.inc
                    @?        dv16,mc9s08dv16.inc
                    @?        dv32,mc9s08dv32.inc
                    @?        dv48,mc9s08dv48.inc
                    @?        dv60,mc9s08dv60.inc
                    @?        dv96,mc9s08dv96.inc
                    @?        dz128,mc9s08dz128.inc
                    @?        dz16,mc9s08dz16.inc
                    @?        dz32,mc9s08dz32.inc
                    @?        dz48,mc9s08dz48.inc
                    @?        dz60,mc9s08dz60.inc
                    @?        dz96,mc9s08dz96.inc
                    @?        el16,mc9s08el16.inc
                    @?        el32,mc9s08el32.inc
                    @?        en16,mc9s08en16.inc
                    @?        en32,mc9s08en32.inc
                    @?        gb32,mc9s08gb32.inc
                    @?        gb32a,mc9s08gb32a.inc
                    @?        gb60,mc9s08gb60.inc
                    @?        gb60a,mc9s08gb60a.inc
                    @?        gt16,mc9s08gt16.inc
                    @?        gt16a,mc9s08gt16a.inc
                    @?        gt32,mc9s08gt32.inc
                    @?        gt32a,mc9s08gt32a.inc
                    @?        gt60,mc9s08gt60.inc
                    @?        gt60a,mc9s08gt60a.inc
                    @?        gt8a,mc9s08gt8a.inc
                    @?        jm16,mc9s08jm16.inc
                    @?        jm16t,mc9s08jm16t.inc
                    @?        jm32,mc9s08jm32.inc
                    @?        jm60,mc9s08jm60.inc
                    @?        jr12,mc9s08jr12.inc
                    @?        lc20,mc9s08lc20.inc
                    @?        lc36,mc9s08lc36.inc
                    @?        lc60,mc9s08lc60.inc
                    @?        ll16,mc9s08ll16.inc
                    @?        qe128,mc9s08qe128.inc
                    @?        qe16,mc9s08qe16.inc
                    @?        qe32,mc9s08qe32.inc
                    @?        qe64,mc9s08qe64.inc
                    @?        qe96,mc9s08qe96.inc
                    @?        ra16,mc9s08ra16.inc
                    @?        rc16,mc9s08rc16.inc
                    @?        rc32,mc9s08rc32.inc
                    @?        rc60,mc9s08rc60.inc
                    @?        rd16,mc9s08rd16.inc
                    @?        rd32,mc9s08rd32.inc
                    @?        rd60,mc9s08rd60.inc
                    @?        re16,mc9s08re16.inc
                    @?        re32,mc9s08re32.inc
                    @?        re60,mc9s08re60.inc
                    @?        rg32,mc9s08rg32.inc
                    @?        rg60,mc9s08rg60.inc
                    @?        rt16,mc9s08rt16.inc
                    @?        sg16,mc9s08sg16.inc
                    @?        sg32,mc9s08sg32.inc
                    @?        sh16,mc9s08sh16.inc
                    @?        sh32,mc9s08sh32.inc
                    @?        sl16,mc9s08sl16.inc

          #ifndef ?DONE
                    #Uses     mc9s08gb60a.inc
          #endif

#ifnomdef feed_watchdog
feed_watchdog       macro                         ;Watchdog feed macro
                    sta       SRS                 ;feed the watchdog
                    endm
#endif
                    #HomeDir
