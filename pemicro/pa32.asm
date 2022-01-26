;*******************************************************************************
; Original verified disassembly of PA32/PT32 v1.03 algorithm dated
; 01/24/2014 [2014-01-24] by P&E Microcomputer Systems
;*******************************************************************************
                    #NoMMU
HZ                  def       33554432            ;Cyclone default 32768*1024
BDIV                def       1
                    #ListOff
NO_CODE
                    #Uses     pa32.inc
                    #ListOn
                    #Memory   #OFF#
;*******************************************************************************
; Constants
;*******************************************************************************

PROG_VERSION        equ       177                 ;required prog version as x.xx
BUFFER_LENGTH       def       2048
MODULE_LENGTH       equ       $CF00

;*******************************************************************************
#s19write ;version 1.03, 01/24/2014, Copyright P&E Microcomputer Systems, www.pemicro.com [9s08pt32]
#s19write ;Assembled with ASM8 v{:version(2)} on {:year}-{:month(z)}-{:date(z)}
#s19write ;Device Motorola/Freescale/NPX, 9S08PA32, All
#s19write ;begin_cs
#s19write REQUIRES_PROG_VERSION={PROG_VERSION(2)}/
#s19write DEVICE_IS_PT
#s19write WRITE_BYTE=20/{WDOG_CS1(L)}/       ;Disable COP Watchdog
#s19write WRITE_BYTE=00/{WDOG_CS2(L)}/
#s19write WRITE_BYTE=FF/{WDOG_TOVALH(L)}/
#s19write WRITE_BYTE=FF/{WDOG_TOVALL(L)}/
#s19write WRITE_BYTE=00/{WDOG_WINH(L)}/
#s19write WRITE_BYTE=00/{WDOG_WINL(L)}/
#s19write WRITE_BYTE=FF/{NVM_FPROT(L)}/       ;Disable Flash Protection
#s19write WRITE_BYTE=80/{NVM_EEPROT(L)}/       ;Disable EEPROM Protection
#s19write BLANK_MODULE_ONLY
#s19write ICS_RANGE=000312500/000390625/000000320/ ;ICS Range (LSB = decimal place)
#s19write WRITE_BYTE_AND_SYNC=80/{ICS_C2(L)}/  ;Bus Freq ~ 1 MHZ
#s19write 09BIT_TRIM=303A/303B/01/FF6F/FF6E/00100000/
#s19write WRITE_BYTE_AND_SYNC=00/{ICS_C2(L)}/  ;Bus Freq ~ 16.777MHZ
#s19write NO_BASE_ADDRESS=00003100/         ;Fixed at $3100
#s19write ADDR_RANGE=00000000/000000FF/00/FFFFFFC0/FFFFFE00/     ; $3100-$31FF (EEPROM)
#s19write ADDR_RANGE=00004F00/0000CEFF/00/FFFFFFC0/FFFFFE00/     ; $8000-$FFFF (FLASH)
#s19write BLOCKING_MASK=00000007/00003100/000031FF/              ; 8 bytes only for EEPROM
#s19write BLOCKING_MASK=00000007/00008000/0000FDFF/              ; 8 bytes only for flash
#s19write BLOCKING_MASK=000001FF/0000FE00/0000FFFF/              ; 512 bytes only for PFLASH last sector
#s19write UNIMP_ADDR=0000002B/0000002B/                        ; $002B Unimplemented
#s19write UNIMP_ADDR=0000304F/0000304F/                        ; $304F Unimplemented
#s19write UNIMP_ADDR=00003069/00003069/                        ; $3069 Unimplemented
#s19write UNIMP_ADDR=000030AA/000030AB/                        ; $30AA-$30AB Unimplemented
#s19write UNIMP_ADDR=000030AE/000030AE/                        ; $30AE Unimplemented
#s19write UNIMP_ADDR=000030EB/000030EB/                        ; $30EB Unimplemented
#s19write UNIMP_ADDR=000030FE/000030FF/                        ; $30FE-$30FF Unimplemented
#s19write UNIMP_ADDR=00001040/00002FFF/                        ; $1040-$2FFF Unimplemented
#s19write UNIMP_ADDR=00003200/00007FFF/                        ; $3200-$7FFF Unimplemented
#s19write ;end_cs
;Format:  USER=UU uuuuuuuuuuuuuuuuuuuNpppppppppp/lowbound/up_bound/
;              ^^Unique              ^0..4 = bytes of parameter size (0=none)
#s19write USER=SD Secure Device      0No Value  /00000000/FFFFFFFF/
#s19write
;*******************************************************************************
                    #RAM      RAM                 ;table must appear first in S19
;*******************************************************************************

                    long      RAM                 ;STACK
                                                  ;The address of the top of the stack
                                                  ;used by any of the execution routines
                    long      buffer              ;BUFFER
                                                  ;The address of the buffer which
                                                  ;holds either bytes or words to
                                                  ;be programmed into the modules
                    long      ::buffer            ;BUFFER_LENGTH
                                                  ;The length of the buffer in bytes.
                                                  ;This buffer should contain at
                                                  ;least 258 bytes
                    long      EEPROM              ;MODULE
                                                  ;The address at which the module
                                                  ;is physically addressed. During
                                                  ;execution, the user specified
                                                  ;base address is translated to
                                                  ;the module address. Thus, the
                                                  ;module need not have the addresses
                                                  ;at which the user code/data is
                                                  ;programmed
                    long      MODULE_LENGTH       ;MODULE_LENGTH
                                                  ;The length of the module being
                                                  ;programmed in bytes
                    long      Erased?             ;BLANK_BYTES
                                                  ;The address of a routine to check
                                                  ;a block of bytes to see if they
                                                  ;are erased. Word (sp+2) contains
                                                  ;the starting address, and word (sp+4)
                                                  ;contains the number of bytes to check.
                                                  ;Checking is done on a byte by byte
                                                  ;basis. If (sp+4)<>0 on return then
                                                  ;an error occured at word address (SP+4)-1
                    long      NUL                 ;BLANK_WORDS
                                                  ;The address of a routine to check a block of
                                                  ;words to see if they are erased. Word (sp+2)
                                                  ;contains the starting address, and word (sp+4)
                                                  ;contains the number of bytes to check. Checking
                                                  ;is done on a word by word basis. If (sp+4)<>0 on
                                                  ;return then an error occured at word address (SP+4)-2.
                    long      NUL                 ;ERASE_BYTES
                                                  ;The address of a routine to erase a block of
                                                  ;bytes. Word (sp+2) contains the starting address,
                                                  ;and word (sp+4) contains the number of bytes to
                                                  ;check. Checking if done is on a byte by byte basis.
                                                  ;If (sp+4)<>0 on return then an error occured.
                    long      NUL                 ;ERASE_WORDS
                                                  ;The address of a routine to erase a block of
                                                  ;words. Word (sp+2) contains the starting address,
                                                  ;and word (sp+4) contains the number of bytes to
                                                  ;check. Checking if done is on a word by word basis.
                                                  ;If (sp+4)<>0 on return then an error occured.
                    long      EraseModule         ;ERASE_MODULE
                                                  ;The address of a routine which erases the entire
                                                  ;module. Word (sp+2) contains the starting address,
                                                  ;and word (sp+4) contains the number of bytes to
                                                  ;check. Checking if done on a word by word or a
                                                  ;byte by byte basis. If (sp+4)<>0 on return then an
                                                  ;error occured.
                    long      BurstProgram        ;PROGRAM_BYTES
                                                  ;The address of a routine which programs a block
                                                  ;of bytes residing in the buffer. Word (sp+4) contains
                                                  ;the length of the block in bytes. Word (sp+2) contains
                                                  ;the starting address at which they are to be
                                                  ;programmed.  Returning with HX non zero indicates
                                                  ;an error.
                    long      NUL                 ;PROGRAM_WORDS
                                                  ;The address of a routine which programs a block
                                                  ;of words residing in the buffer. Word (sp+4) contains
                                                  ;the length of the block in bytes. Word (sp+2) contains
                                                  ;the starting address at which they are to be
                                                  ;programmed.  Returning with HX non zero indicates
                                                  ;an error.
                    long      NUL                 ;VOLTAGE_ON
                                                  ;The address of a routine which turns on the
                                                  ;voltages necessary to program/erase the
                                                  ;module. If this routine does not exist, the
                                                  ;user will be prompted to turn the voltages on.
                    long      NUL                 ;VOLTAGE_OFF
                                                  ;The address of a routine which turns off the
                                                  ;voltages necessary to program/erase the
                                                  ;module. If this routine does not exist, the
                                                  ;user will be prompted to turn the voltages off.
                    long      Start               ;ENABLE
                                                  ;The address of a routine which sets up and
                                                  ;enables the module at startup. Returning with
                                                  ;HX <> 0 indicates an error.
                    long      NUL                 ;DISABLE
                                                  ;The address of a routine which shuts down the
                                                  ;module.
                    long      NUL                 ;BEFORE_READ
                                                  ;The address of a routine which sets up the
                                                  ;module to do a read. Word (sp+2) contains
                                                  ;the address to be read.
                    long      NUL                 ;AFTER_READ
                                                  ;The address of a routine which takes the
                                                  ;module out of read mode.
          ;-------------------------------------- ;USER_FUNCTIONs (up to six)
                    long      SecureDevice        ;These are the optional user functions. They
                                                  ;are created with USER= statements in the S8P
                                                  ;file and corresponding address as an extra
                                                  ;address in the table. On entry, word (sp) is
                                                  ;buffer_pointer, (sp+2) is module_address, HX
                                                  ;is user parameter. On return, if HX <>0 an
                                                  ;error occurred.
                    long      NUL                 ;(DoErase)
;                   long:4    NUL                 ;placeholders for user functions

;*******************************************************************************
                    #RAM      RAM
;*******************************************************************************

.buffer             rmb       2                   ;pointer to buffer
address             rmb       2                   ;address to program
byte_counter        rmb       2                   ;remaining bytes to program
flash_value         rmb       1                   ;value to program
flash_command       rmb       1                   ;programming command
byte_counter_copy   rmb       2                   ;written once for what purpose?
buffer              rmb       BUFFER_LENGTH       ;data to program

                    @assert   ::buffer >= 258     ;verify minimum required buffer length

;*******************************************************************************
                    #ROM      :RAM
;*******************************************************************************

Start               proc
                    ldhx      #STACKTOP
                    txs
                    psha
                    lda       #$30
                    sta       NVM_FSTAT
                    pula
                    sta       NVM_FCLKDIV
                    ldhx      #0
                    !bgnd

;*******************************************************************************

EraseModule         proc
                    lda       #$30
                    sta       NVM_FSTAT
                    lda       #0
                    sta       NVM_FCCOBIX
                    lda       #8
                    sta       NVM_FCCOBHI
          ;-------------------------------------- ;Start operation and wait for completion
                    lda       #CCIF_
                    sta       NVM_FSTAT
_1@@                lda       NVM_FSTAT
                    and       #CCIF_
                    cmpa      #CCIF_
                    bne       _1@@
          ;--------------------------------------
                    lda       NVM_FSTAT
                    and       #$33
                    beq       _2@@
                    tax
                    !bgnd
          ;--------------------------------------
_2@@                lda       NV_RESERVED
                    sta       buffer
                    lda       NV_RESERVED+1
                    sta       buffer+1
                    lda       NV_RESERVED+2
                    sta       buffer+2
                    lda       NV_RESERVED+3
                    sta       buffer+3
                    lda       NV_FPROT
                    sta       buffer+4
                    lda       NV_EEPROT
                    sta       buffer+5
                    lda       NV_FOPT
                    sta       buffer+6
                    lda       NV_FSEC
                    and       #$fe
                    sta       buffer+7

                    ldhx      #buffer
                    sthx      .buffer
                    ldhx      #NV_RESERVED
                    sthx      address
                    ldhx      #8
                    sthx      byte_counter
                    jmp       ?ProgramSector

;*******************************************************************************

?DoEEPROM           proc
                    lda       #0
                    sta       flash_command
                    lda       #$11
                    sta       NVM_FCCOBHI
                    lda       flash_command
                    sta       NVM_FCCOBLO
                    lda       NVM_FCCOBIX
                    inca
                    sta       NVM_FCCOBIX
                    lda       address
                    sta       NVM_FCCOBHI
                    lda       address+1
                    sta       NVM_FCCOBLO
                    ldhx      address
                    aix       #4
                    sthx      address
          ;--------------------------------------
                    ldhx      .buffer
Loop@@              lda       NVM_FCCOBIX
                    inca
                    sta       NVM_FCCOBIX
                    lda       ,x
                    sta       NVM_FCCOBLO
                    aix       #1
                    lda       NVM_FCCOBIX
                    cmpa      #5
                    blt       Loop@@
          ;-------------------------------------- ;Start operation and wait for completion
                    lda       #CCIF_
                    sta       NVM_FSTAT
                    sthx      .buffer
WaitComplete@@      lda       NVM_FSTAT
                    and       #CCIF_
                    cmpa      #CCIF_
                    bne       WaitComplete@@
                    rts

;*******************************************************************************

?DoFlash            proc
                    lda       #0
                    sta       flash_command
                    lda       #6
                    sta       NVM_FCCOBHI
                    lda       flash_command
                    sta       NVM_FCCOBLO
                    lda       NVM_FCCOBIX
                    inca
                    sta       NVM_FCCOBIX
                    lda       address
                    sta       NVM_FCCOBHI
                    lda       address+1
                    sta       NVM_FCCOBLO
                    ldhx      address
                    aix       #8
                    sthx      address
          ;--------------------------------------
                    ldhx      .buffer
Loop@@              lda       NVM_FCCOBIX
                    inca
                    sta       NVM_FCCOBIX
                    lda       ,x
                    sta       NVM_FCCOBHI
                    aix       #1
                    lda       ,x
                    sta       NVM_FCCOBLO
                    aix       #1
                    lda       NVM_FCCOBIX
                    cmpa      #5
                    blt       Loop@@
          ;-------------------------------------- ;Start operation and wait for completion
                    lda       #CCIF_
                    sta       NVM_FSTAT
                    sthx      .buffer
WaitComplete@@      lda       NVM_FSTAT
                    and       #CCIF_
                    cmpa      #CCIF_
                    bne       WaitComplete@@
                    rts

;*******************************************************************************

L95C                proc
                    lda       #$30
                    sta       NVM_FSTAT
                    lda       #0
                    sta       NVM_FCCOBIX
                    lda       #10
                    sta       NVM_FCCOBHI
                    lda       #0
                    sta       NVM_FCCOBLO
                    lda       NVM_FCCOBIX
                    inca
                    sta       NVM_FCCOBIX
                    lda       #$FE
                    sta       NVM_FCCOBHI
                    lda       #0
                    sta       NVM_FCCOBLO
          ;-------------------------------------- ;Start operation and wait for completion
                    lda       #CCIF_
                    sta       NVM_FSTAT
Loop@@              lda       NVM_FSTAT
                    and       #CCIF_
                    cmpa      #CCIF_
                    bne       Loop@@
          ;--------------------------------------
                    lda       NVM_FSTAT
                    and       #$33
                    beq       ?ProgramSector
                    tax
                    !bgnd

;*******************************************************************************

BurstProgram        proc
                    mov       byte_counter,byte_counter_copy
                    mov       byte_counter+1,byte_counter_copy+1
                    lda       #$30
                    sta       NVM_FSTAT
;                   bra       L9A3

;*******************************************************************************

L9A3                proc
                    lda       #0
                    sta       NVM_FCCOBIX
                    lda       address
                    cmpa      #$31
                    beq       _2@@
                    cmpa      #$FE
                    beq       _1@@
                    bra       ?ProgramSector
_1@@                lda       address+1
                    cmpa      #0
                    beq       L95C
                    bra       ?ProgramSector

_2@@                jsr       ?DoEEPROM
                    lda       NVM_FSTAT
                    and       #$33
                    beq       _3@@
                    tax
                    !bgnd

_3@@                lda       #0
                    sta       NVM_FCCOBIX
                    jsr       ?DoEEPROM
                    lda       NVM_FSTAT
                    and       #$33
                    beq       ?DecrementCounter
                    tax
                    !bgnd

;*******************************************************************************

?ProgramSector      proc
                    lda       #0
                    sta       NVM_FCCOBIX
                    jsr       ?DoFlash
                    lda       NVM_FSTAT
                    and       #$33
                    beq       ?DecrementCounter
                    tax
                    !bgnd

;*******************************************************************************

?DecrementCounter   proc
                    ldhx      byte_counter
                    aix       #-8
                    sthx      byte_counter
                    cphx      #0
                    bne       L9A3
                    !bgnd

;*******************************************************************************

SecureDevice        proc
          ;-------------------------------------- ;copy previous contents to buffer
                    lda       NV_RESERVED
                    sta       buffer
                    lda       NV_RESERVED+1
                    sta       buffer+1
                    lda       NV_RESERVED+2
                    sta       buffer+2
                    lda       NV_RESERVED+3
                    sta       buffer+3
                    lda       NV_FPROT
                    sta       buffer+4
                    lda       NV_EEPROT
                    sta       buffer+5
                    lda       NV_FOPT
                    sta       buffer+6
                    lda       NV_FSEC
                    and       #SEC1_|SEC0_^NOT    ;force SEC bits to zeros (secured)
                    sta       buffer+7
          ;--------------------------------------
                    ldhx      #buffer
                    sthx      .buffer
                    ldhx      #NV_RESERVED        ;start programming address
                    sthx      address
                    ldhx      #8                  ;number of bytes to program
                    sthx      byte_counter
                    jmp       ?ProgramSector

;*******************************************************************************

Erased?             proc
                    lda       #ERASED_STATE       ;A6FF
          ;-------------------------------------- ;Check EEPROM section
                    ldhx      #EEPROM
_1@@                cbeq      x+,_2@@
                    jmp       Done@@
_2@@                cphx      #EEPROM_END+1
                    bne       _1@@
          ;-------------------------------------- ;Check ROM code section
                    ldhx      #TRUE_ROM
Loop@@              cbeq      x+,_3@@
                    jmp       Done@@
_3@@                cphx      #NV_FSEC
                    bne       Loop@@
          ;-------------------------------------- ;Check vectors section
                    ldhx      #XROM
_5@@                cbeq      x+,_4@@
                    jmp       Done@@
_4@@                cphx      #0
                    bne       _5@@
          ;--------------------------------------
Done@@              sthx      byte_counter
                    !bgnd

;*******************************************************************************
                    #Hint     612 bytes, CRC: $BCB2
;*******************************************************************************
