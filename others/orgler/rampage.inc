     org RAMStart
SECOND          ds 1

TIMEBASE        ds 1
TIMECOUNT       ds 1
LOOPCOUNT       ds 1
TIMER           ds 2

************************
TEMP            ds 2
**********************************************
*      Emulated Serial
**********************************************
EMUL_TX_BYTES    DS 1
funcEmulSci      DS 2
error            DS 1
bitcount         DS 1
status           DS 1
countx           DS 1
RSBYTE           DS 1
EmulSciTimeout   DS 1
ptrEmulSci       DS 2
SerCounter       DS 1
ShiftByte        DS 1
iTxBytes         DS 1
txcount          DS 1
SCI_ERROR_COUNT  DS 1
EMULRXBUF        DS 8
***************************************
***************************************
