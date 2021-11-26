;*******************************************************************************
                    #RAM      RAMStart
;*******************************************************************************

second              rmb       1

timebase            rmb       1
timecount           rmb       1
loopcount           rmb       1
timer               rmb       2

temp                rmb       2
          ;-------------------------------------- ;Emulated serial
emul_tx_bytes       rmb       1
funcEmulSci         rmb       2
error               rmb       1
bitcount            rmb       1
status              rmb       1
countx              rmb       1
RSBYTE              rmb       1
EmulSciTimeout      rmb       1
ptrEmulSci          rmb       2
SerCounter          rmb       1
ShiftByte           rmb       1
iTxBytes            rmb       1
txcount             rmb       1
SCI_ERROR_COUNT     rmb       1
EMULRXBUF           rmb       8
