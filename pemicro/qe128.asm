;*******************************************************************************
; Based on the original verified disassembly of QE128 v1.05 algorithm dated
; 12/10/2009 [2009-12-10] by P&E Microcomputer Systems
;*******************************************************************************
                    #NoMMU
HZ                  def       8388608*2
BDIV                def       1
                    #ListOff
NO_CODE
                    #Uses     qe128.inc
                    #ListOn
                    #Memory   #OFF#
;*******************************************************************************
; Constants
;*******************************************************************************

PROG_VERSION        equ       144                 ;required prog version as x.xx
BUFFER_LENGTH       def       1024
MODULE_LENGTH       equ       7<16+:PAGE_END+1-TRUE_ROM

;*******************************************************************************
#s19write ;version 1.05, 12/10/2009, Copyright P&E Microcomputer Systems, www.pemicro.com [9s08qe128]
#s19write ;Modified by Tony G. Papadimitriou <tonyp@acm.org> on 2021-02-22 [-50 bytes]
#s19write ;Assembled with ASM8 v{:version(2)} on {:year}-{:month(z)}-{:date(z)}
#s19write ;Device Motorola/Freescale/NPX, 9S08QE128, All
#s19write ;begin_cs
#s19write REQUIRES_PROG_VERSION={PROG_VERSION(2)}/
#s19write WRITE_BYTE=02/{SOPT(L)}/       ;Clear COP Watchdog
#s19write WRITE_BYTE=FF/{FPROT(L)}/       ;Disable Flash Protection
#s19write BOUNDARY_MASK={:PAGE_END-:PAGE_START^NOT(L)}/       ; {:PAGE_END-:PAGE_START+1/1024}K pages
#s19write BLANK_MODULE_ONLY
#s19write ICS_RANGE=000312500/000390625/000000320/ ;ICS Range (LSB = decimal place)
#s19write WRITE_BYTE_AND_SYNC=80/{ICSTRM(L)}/
#s19write WRITE_BYTE_AND_SYNC=31/{ICSSC(L)}/
#s19write WRITE_BYTE_AND_SYNC=11/{ICSSC(L)}/  ;Reset ICS Module
#s19write WRITE_BYTE_AND_SYNC=C0/{ICSC2(L)}/  ;Bus Freq ~ {BUS_HZ/8(6)}MHZ
#s19write 09BIT_TRIM={ICSTRM(W)}/{ICSSC(W)}/01/{NVICSTRM(W)}/{NVFTRIM(W)}/{BUS_HZ/8(L)}/
#s19write WRITE_BYTE_AND_SYNC=00/00000039/  ;Bus Freq ~ {BUS_HZ(6)}MHZ
#s19write S08_FLASH_PAGING=00/{:PAGE_START(W)}/{:PAGE_END(W)}/{PPAGE(W)}/
#s19write PROGRAMMING_ALSO_DOES_VERIFY
#s19write NO_BASE_ADDRESS={TRUE_ROM(l)}/         ;Fixed at {TRUE_ROM(h)}
#s19write ADDR_RANGE=00000000/0000DF7F/00/FFFFFFC0/FFFFFE00/     ; $2080-$FFFF
#s19write ADDR_RANGE=00015F80/00019F7F/00/FFFFFFC0/FFFFFE00/     ; $18000-$1BFFF
#s19write ADDR_RANGE=00025F80/00029F7F/00/FFFFFFC0/FFFFFE00/     ; $28000-$2BFFF
#s19write ADDR_RANGE=00035F80/00039F7F/00/FFFFFFC0/FFFFFE00/     ; $38000-$3BFFF
#s19write ADDR_RANGE=00045F80/00049F7F/00/FFFFFFC0/FFFFFE00/     ; $48000-$4BFFF
#s19write ADDR_RANGE=00055F80/00059F7F/00/FFFFFFC0/FFFFFE00/     ; $58000-$5BFFF
#s19write ADDR_RANGE=00065F80/00069F7F/00/FFFFFFC0/FFFFFE00/     ; $68000-$6BFFF
#s19write ADDR_RANGE=00075F80/00079F7F/00/FFFFFFC0/FFFFFE00/     ; $78000-$7BFFF
#s19write ;end_cs
;Format:  USER=UU uuuuuuuuuuuuuuuuuuuNpppppppppp/lowbound/up_bound/
;              ^^Unique              ^0..4 = bytes of parameter size (0=none)
#s19write USER=SD Secure Device      0No Value  /00000000/FFFFFFFF/
#s19write USER=EP Erase Page         1Address?  /{TRUE_ROM(L)}/{7<16+:PAGE_END(L)}/
          #ifdef
#s19write USER=X3 Some Function3     1Address?  /00000000/FFFFFFFF/
#s19write USER=X4 Some Function4     1Address?  /00000000/FFFFFFFF/
#s19write USER=X5 Some Function5     1Address?  /00000000/FFFFFFFF/
#s19write USER=X6 Some Function6     1Address?  /00000000/FFFFFFFF/
          #endif
#s19write COMMENT2=S-Record Addresses {TRUE_ROM(h)}-$3FFF --> Page 0
#s19write COMMENT1=S-Record Addresses $4000-{:PAGE_START-1(h)} --> Page 1
#s19write COMMENT3=S-Record Addresses {:PAGE_START(h)}-{:PAGE_END(h)} --> Page 0
#s19write COMMENT4=S-Record Addresses {:PAGE_END+1(h)}-$FFFF --> Page 3
#s19write COMMENT5=All Pages can be accessed with 24-Bit Address...
#s19write COMMENT6=... eg $2{:PAGE_START(w)}-$2{:PAGE_END(w)} --> Page 2
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
                    long      TRUE_ROM            ;MODULE
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
                    long      DoErase
;                   long:4    NUL                 ;placeholders for user functions

;*******************************************************************************
                    #RAM      RAM+2
;*******************************************************************************

address             rmb       2                   ;address to program
byte_counter        rmb       2                   ;remaining bytes to program
flash_value         rmb       1                   ;value to program
flash_command       rmb       1                   ;programming command
buffer              rmb       BUFFER_LENGTH       ;data to program

                    @assert   ::buffer >= 258     ;verify minimum required buffer length

;*******************************************************************************
                    #ROM      :RAM
;*******************************************************************************

Start               proc
                    ldhx      #$1080              ;(compatible with QE64's RAM)
                    txs
                    tax
                    lda       FSTAT
                    ora       #FPVIOL_|FACCERR_
                    sta       FSTAT
                    stx       FCDIV
                    bra       ?BackToCyclone

;*******************************************************************************

Program             proc
                    lda       #FPVIOL_|FACCERR_
                    bit       FSTAT
                    beq       Done@@
                    sta:2     FSTAT               ;(is repetition redundant?)
Done@@             ;bra       DoCommand

;*******************************************************************************

DoCommand           proc
                    lda       flash_value
                    sta       ,x
                    lda       flash_command
                    sta       FCMD
                    lda       #FCBEF_
                    sta       FSTAT
                    rts

;*******************************************************************************

ProgramAndWait      proc
                    bsr       Program
;                   bra       WaitProgramFinish

;*******************************************************************************

WaitProgramFinish   proc
                    psha
                    lda       #FCCF_
Loop@@              bit       FSTAT
                    beq       Loop@@
                    pula
                    rts

;*******************************************************************************

BurstProgram        proc
                    stx       PPAGE
                    mov       #BurstProg_,flash_command
                    ldhx      byte_counter
                    pshhx
          ;-------------------------------------- ;hardcode bytes to process
                    lda       #[buffer
                    sub       address+1
                    sta       _1@@+1              ;update LSB of program function
                    sta       _2@@+1              ;update LSB of verify function
                    lda       #]buffer
                    sbc       address
                    sta       _1@@                ;update MSB of program function
                    sta       _2@@                ;update MSB of verify function
          ;-------------------------------------- ;program range
                    ldhx      address             ;offset into buffer
Loop@@              lda       $FFFF,x             ;placeholder offset to be written over
_1@@                equ       *-2,2
                    sta       flash_value
                    bsr       DoCommand
                    bsr       ?DecrementCounter
                    beq       Go@@
          ;--------------------------------------
                    lda       #FCBEF_
WaitEmptyCmd@@      bit       FSTAT
                    beq       WaitEmptyCmd@@
                    bra       Loop@@
          ;--------------------------------------
Go@@                bsr       WaitProgramFinish
                    pulhx
                    sthx      byte_counter
          ;-------------------------------------- ;verify range
                    ldhx      address             ;offset into buffer
Loop2@@             lda       $FFFF,x             ;placeholder offset to be written over
_2@@                equ       *-2,2
                    cmpa      ,x
                    bne       Done@@
                    bsr       ?DecrementCounter
                    bne       Loop2@@
?BackToCyclone      clrhx
Done@@              !bgnd

;*******************************************************************************

?DecrementCounter   proc
                    aix       #1
                    pshhx
                    ldhx      byte_counter
                    aix       #-1
                    sthx      byte_counter
                    pulhx
                    rts

;*******************************************************************************

EraseFlash          proc
                    sta       PPAGE
                    mov       #PageErase_,flash_command
                    mov       #ERASED_STATE,flash_value
                    bsr       ProgramAndWait
                    lda       FSTAT
                    and       #FPVIOL_|FACCERR_
                    tah
                    tax
                    rts

;*******************************************************************************

DoErase             proc
                    bsr       EraseFlash
                    !bgnd

;*******************************************************************************

SecureDevice        proc
                    lda       NVOPT
                    and       #SEC1_|SEC0_^NOT              ;secure Flash mask
                    sta       buffer
                    ldhx      #NVOPT
                    sthx      address
                    ldhx      #1
                    sthx      byte_counter
                    bra       BurstProgram

;*******************************************************************************

EraseModule         proc
                    ldhx      #:PAGE_END+1
                    mov       #ERASED_STATE,flash_value
                    mov       #MassErase_,flash_command
                    jsr       ProgramAndWait
                    mov       #ByteProg_,flash_command
                    mov       #SEC0_^NOT,flash_value        ;unsecure Flash
                    ldhx      #NVOPT
                    jsr       ProgramAndWait
;                   bra       Erased?

;*******************************************************************************

Erased?             proc
                    lda       #ERASED_STATE
                    clr       PPAGE               ;first PPAGE
                    ldhx      #TRUE_ROM           ;beginning of visible Flash
FlashLoop@@         cbeq      x+,_1@@             ;if erased, continue
                    bra       Done@@              ;else done
_1@@                cphx      #NVOPT              ;until NVOPT register
                    bne       FlashLoop@@         ;repeat
          ;--------------------------------------
                    ldhx      #VECTORS            ;start of fixed vectors
VectorLoop@@        cbeq      x+,_2@@             ;if erased, continue
                    bra       Done@@              ;else done
_2@@                cphx      #0                  ;until end of all Flash
                    bne       VectorLoop@@        ;repeat
          ;-------------------------------------- ;check if all PPAGEs are erased
PageLoop@@          inc       PPAGE               ;advance PPAGE
                    lda       PPAGE
                    cmpa      #3                  ;vector page (PPAGE 3)?
                    beq       PageLoop@@          ;skip PPAGE 3
          ;--------------------------------------
                    lda       #ERASED_STATE       ;erased Flash state
                    ldhx      #:PAGE_START        ;from beginning of PPAGE window
WindowLoop@@        cbeq      x+,_3@@             ;if erased, continue
                    bra       Done@@              ;else done
_3@@                cphx      #:PAGE_END+1        ;until end of PPAGE window
                    bne       WindowLoop@@        ;repeat
          ;--------------------------------------
                    lda       PPAGE
                    cmpa      #7                  ;last PPAGE?
                    bne       PageLoop@@          ;repeat until then
                    clrhx
Done@@              sthx      byte_counter
                    !bgnd

;*******************************************************************************
