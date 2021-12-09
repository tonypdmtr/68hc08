;*******************************************************************************
;* Program   : TBOOT.ASM
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Always-present Tiny Bootloader
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;* Segments  : RAM    : Variables
;*           : ROM    : Code
;* Note(s)   : User vectors are automatically redirected.
;*******************************************************************************

#ifdef ?
  #Hint ****************************************************
  #Hint * Available conditionals (for use with -Dx option) *
  #Hint ****************************************************
  #Hint *---------------------------------------------------
  #Hint *       S U P P O R T E D   T A R G E T S
  #Hint *---------------------------------------------------
  #Hint * QG8..............: Target is 9S08QG8
  #Hint * QE8..............: Target is 9S08QE8
  #Hint * QE32.............: Target is 9S08QE32
  #Hint * QE128............: Target is 9S08QE128
  #Hint * DZ32.............: Target is 9S08DZ32
  #Hint * DZ60.............: Target is 9S08DZ60
  #Hint * FL16.............: Target is 9S08FL16
  #Hint * SH8..............: Target is 9S08SH8
  #Hint * QD2..............: Target is 9S08QD2
  #Hint * QD4..............: Target is 9S08QD4
  #Hint * AC32.............: Target is 9S08AC32
  #Hint * AC96.............: Target is 9S08AC96
  #Hint *---------------------------------------------------
  #Hint *                   O P T I O N S
  #Hint *---------------------------------------------------
  #Hint * HZ...............: MCU effective clock as Hz
  #Hint * KHZ..............: MCU effective clock as KHz
  #Hint * MHZ..............: MCU effective clock as MHz
  #Hint * BDIV.............: Bus divisor (where available)
  #Hint * FLASH_DATA_SIZE..: Flash size for user data
  #Hint * ALLOW_EEPROM.....: Allow EEPROM address range
  #Hint * NVOPT_VALUE......: Use a specific NVOPT value
  #Hint * HARD_FLOW_CONTROL: For RTS/CTS control
  #Hint * RXINV............: SCI RX line inverted
  #Hint * TXINV............: SCI TX line inverted
  #Hint * BPS..............: BPS = 3/12/24/48/96/192/384/576(00)
  #Hint * SCI..............: SCI = (SCI)1 or (SCI)2 or SoftSCI (-1)
  #Hint * ENABLE_RUN.......: Enable [R]un command
  #Hint * NO_IRQ...........: Disable IRQ pin test
  #Hint * DISABLE_SURE.....: Disable 'Sure?' message
  #Hint * DEBUG............: For debugging only
  #Hint ****************************************************
  #Fatal Run ASM8 -Dx (where x is any of the above)
#endif

BOOTROM_VERSION     def       120                 ;version as x.xx
;-------------------------------------------------------------------------------

SCI                 def       1                   ;SCI to use (1 or 2, -1=Software)
;-------------------------------------------------------------------------------
?                   macro
          #ifdef ~1~
FLASH_DATA_SIZE     def       ~2~
          #endif
                    endm

                    @?        QE128||AC96,1024
                    @?        DZ32||DZ60,0        ; config storage in EEPROM, not Flash
                    @?        GB60,1920

FLASH_DATA_SIZE     def       512                 ; all others have 512 default
;-------------------------------------------------------------------------------
          #ifdef QE128||AC96
BOOTROM             def       $F800               ;These MMU versions are a bit larger
          #else ifdef DZ32||DZ60
BOOTROM             def       $FA00               ;DZ has different Flash protection
          #endif
BOOTROM             def       $FC00

          #ifnz BOOTROM\512
                    #Error    BOOTROM is not on a 512-byte page boundary
          #endif
;-------------------------------------------------------------------------------
          #ifdef PRIVATE
NVOPT_VALUE         def       %10000000           ; NVOPT transfers to FOPT on reset
          #endif             ; ||||||||
NVOPT_VALUE         def       %00000010           ; NVOPT transfers to FOPT on reset
          #ifdef DZ32||DZ60  ; ||||||||
NVOPT_VALUE  set  NVOPT_VALUE|%00100000           ; EPGMOD = 1 (8-byte mode)
          #endif             ; ||||||||
                             ; ||||||++---------- SEC00 \ 00:secure  10:unsecure
                             ; ||||||++---------- SEC01 / 01:secure  11:secure
                             ; |||+++------------ Not Used (Always 0)
                             ; ||+--------------- EPGMOD - EEPROM Sector Mode (DZ only) 1=8-byte mode
                             ; |+---------------- FNORED - No Vector Redirection
                             ; ++---------------- KEYEN - Backdoor key mechanism enable
          #ifndef MAP
                    #MapOff
          #endif
;-------------------------------------------------------------------------------
#ifndef ROM
ROM                 equ       BOOTROM
;-------------------------------------------------------------------------------
;-------------------------------------------------------------------------------
          #ifdef QE128
HZ                  def       32768*512           ;MCU & Cyclone's default
BDIV                def       1
                    #ListOff
                    #Uses     qe128.inc
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef QE8||QE32
HZ                  def       32768*512           ;MCU & Cyclone's default
BDIV                def       1
                    #ListOff
            #ifdef QE8
                    #Uses     qe8.inc
            #else
                    #Uses     qe32.inc
            #endif
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef FL16
HZ                  def       16777216            ;Cyclone default 32768*512
BDIV                def       1
                    #ListOff
                    #Uses     fl16.inc
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef GB60
HZ                  def       243000*64           ;MCU's default
BDIV                equ       1                   ;(actually, no BDIV in GB60)
                    #ListOff
                    #Uses     gb60.inc
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef AC32||AC96
HZ                  def       32768*512           ;MCU & Cyclone's default
BDIV                def       1
                    #ListOff
            #ifdef AC32
                    #Uses     ac32.inc
            #else
                    #Uses     ac96.inc
            #endif
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef QD2||QD4
HZ                  def       32768*512           ;MCU & Cyclone's default
BDIV                def       1
SCI                 set       -1
                    #ListOff
            #ifdef QD2
                    #Uses     qd2.inc
            #else
                    #Uses     qd4.inc
            #endif
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef DZ32||DZ60
HZ                  def       32000000            ;MCU & Cyclone's default
BDIV                def       1
                    #ListOff
            #ifdef DZ32
                    #Uses     dz32.inc
            #else
                    #Uses     dz60.inc
            #endif
                    #ListOn
                    #temp     NVOPT_VALUE>5&1     ;isolate EPGMOD
                    #Message  EPGMOD = {:temp} ({:temp*4+4}-byte mode)
          #endif
;-------------------------------------------------------------------------------
          #ifdef SH8
HZ                  def       33554432            ;MCU & Cyclone's default
BDIV                def       1
                    #ListOff
                    #Uses     sh8.inc
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifdef QG8
HZ                  def       16000000            ;MCU & Cyclone's default
BDIV                def       1
                    #ListOff
                    #Uses     qg8.inc
                    #ListOn
          #endif
;-------------------------------------------------------------------------------
          #ifndef RAM
                    #Fatal    Define one of the supported MCUs (see help with -d?)
          #endif
;-------------------------------------------------------------------------------
                    #ListOn
                    #MapOn
;-------------------------------------------------------------------------------
#endif
;-------------------------------------------------------------------------------

RVECTORS            def       BOOTROM-1&VECTORS
APP_CODE_START      def       TRUE_ROM+FLASH_DATA_SIZE
APP_CODE_END        def       BOOTROM-1
#Message  AppSpace: {APP_CODE_START(h)}-{APP_CODE_END(h)} ({APP_CODE_END-APP_CODE_START+1} bytes) RVECTORS: {RVECTORS(h)}

;-------------------------------------------------------------------------------

                    #XRAM     RAM                 ;used only for boot
                    #ROM      BOOTROM

;*******************************************************************************
#if SCI < 0
SCI_TX_PIN          def
SCI_RX_PIN          def
              #ifdef BPS
BPS_RATE            equ       BPS
              #endif
                    #Uses     lib/soft_sci/sci_rx.sub
                    #Uses     lib/soft_sci/sci_tx.sub
?GetChar            equ       SCI_GetChar
?PutChar            equ       SCI_PutChar
#endif
;*******************************************************************************
; Macros
;*******************************************************************************

#ifnomdef ?print
?print              macro
                    mset      #
          #if :pc-?Print < 128
                    bsr       ?Print
          #else
                    jsr       ?Print
          #endif
                    fcs       ~1~
                    endm
#endif
;-------------------------------------------------------------------------------
Page                macro
                    mset      #
                    #Message  +-------------------------------------------------
                    #Message  | ~1~
                    #Message  +-------------------------------------------------
                    endm

;*******************************************************************************

          #ifndef MAP
                    #MapOff
          #endif
LF2CRLF             def       *

#ifndef ?GetChar||?PutChar
;*******************************************************************************
@Page SCI module starts here
;*******************************************************************************

                    @ConstMinMax SCI,1,2

#ifdef HARD_FLOW_CONTROL
  #ifndef CTS_LINE
          #ifdef QE128
CTS_LINE            pin       PORTE,6             ;/CTS is output from MCU
          #else ifdef QE8||QE32
CTS_LINE            pin       PORTC,7             ;/CTS is output from MCU
          #endif
  #endif
                    @CheckPin CTS_LINE
#endif

?                   macro
          #ifndef SCI~1~BDH                       ;if required SCI does not exist
                    mset      1                   ;remove number (assuming SCI1)
?MY_SCI             equ       1                   ;assume SCI1
          #endif
?MY_SCI             def       ~1~                 ;assume user's SCI
                    #Message  Using SCI~1~
?SCIBDH             equ       SCI~1~BDH,1
?SCIBDL             equ       SCI~1~BDL,1
?SCIC1              equ       SCI~1~C1,1
?SCIC2              equ       SCI~1~C2,1
?SCIC3              equ       SCI~1~C3,1
?SCIS1              equ       SCI~1~S1,1
?SCIS2              equ       SCI~1~S2,1
?SCID               equ       SCI~1~D,1
                    endm

                    @?        {SCI}

                    @StandardBaudRates            ; Attempt to define all standard bps rates
#ifdef BPS
?                   macro
          #if BPS = ~{:loop}.~
?MY_BPS_RATE        def       bps_~{:loop}.~
          #endif
                    mtop      :n
                    endm

                    @?        300,1200,2400,4800,9600,19200,38400,57600,115200
#endif

?MY_BPS_RATE        def       bps_max

                    #Hint     ==================================================
                    #Hint     >>> Actual SCI{?MY_SCI} speed: {BUS_HZ/16/?MY_BPS_RATE} bps <<<
                    #Hint     ==================================================

;*******************************************************************************
                    #ROM
;*******************************************************************************

                    @cop      #SAVE#

;*******************************************************************************
; Purpose: Set SCI BAUD rate to the specified value
; Input  : HX = Needed baud rate (must have taken care of BUSCLK as shown below)
; Note(s):                                                      BUSCLK     HZ
;        : Baud is calculated using this formula: SBR12:SBR0 = ------- = -------
;        :                                                     16*BAUD   32*BAUD
;        : Example: 9600 baud @ 20MHz bus speed, use value: 130

?SetBAUD            proc
                    sthx      ?SCIBDH
#ifz ]?SCIC2
                    mov       #TE_|RE_,?SCIC2     ;Polled RX and TX mode
          #ifdef RXINV
                    #Message  SCI RX inverted
                    mov       #RXINV_,?SCIS2      ;RX inverted
          #else
                    clr       ?SCIS2
          #endif
          #ifdef TXINV
                    #Message  SCI TX inverted
                    mov       #TXINV_,?SCIC3      ;TX inverted
          #else
                    clr       ?SCIC3
          #endif
#else
                    lda       #TE_|RE_            ;Polled RX and TX mode
                    sta       ?SCIC2
          #ifdef RXINV
                    #Message  SCI RX inverted
                    lda       #RXINV_             ;RX inverted
          #else
                    clra
          #endif
                    sta       ?SCIS2
          #ifdef TXINV
                    #Message  SCI TX inverted
                    lda       #TXINV_             ;TX inverted
          #else
                    clra
          #endif
                    sta       ?SCIC3
#endif
          #ifdef HARD_FLOW_CONTROL
                    #Message  HARD_FLOW_CONTROL (CTS) enabled
                    @Off      CTS_LINE            ;start with enabled RX (output)
          #endif
                    rts

;*******************************************************************************
; Purpose: Read SCI char into RegA
; Input  : None
; Output : A = received character
; Note(s):
                    #spauto

?GetChar            proc
Loop@@
          #ifdef HARD_FLOW_CONTROL
                    bclr      CTS_LINE
          #endif
                    @cop

                    lda       ?SCIS1              ;wait for a character
                    bit       #RDRF_
                    beq       Loop@@

                    lda       ?SCID               ;get received character

                    beq       Loop@@              ;ignore Nulls
                    cbeqa     #LF,Loop@@          ;ignore LineFeeds

                    clc                           ;never an error from here
                    rts

;*******************************************************************************
; Purpose: Write RegA character to the SCI
; Input  : A = character to send to the SCI
; Output : None
; Note(s):
                    #spauto

?PutChar            proc
          #ifdef LF2CRLF
                    cmpa      #LF                 ;is it LF?
                    bne       Print@@             ;no, continue as usual

                    lda       #CR                 ;yes, first print a CR
                    bsr       Print@@

                    lda       #LF                 ;next, print a LF
          #endif
Print@@             @cop
          #ifz ]?SCIS1
                    tst       ?SCIS1
          #else
                    psha
                    lda       ?SCIS1
                    pula
          #endif
                    bpl       Print@@
                    sta       ?SCID
                    rts                           ;Carry Clear when exiting
#endif ;#ifndef ?GetChar||?PutChar

;*******************************************************************************
;@Page Common print I/O routines
;*******************************************************************************

;*******************************************************************************
; Purpose: Print constant ASCIZ string following caller instruction (with FCS)
; Input  : None
; Output : None
; Note(s):
                    #spauto

?Print              proc
pc@@                equ       ::,2                ;SP offset to return address
                    pshhx
                    ldhx      pc@@,sp             ;get return address
                    bsr       ?PrintString
                    sthx      pc@@,sp             ;new return is past the ASCIZ string
                    pulhx
                    rts                           ;back to updated return address

;*******************************************************************************
; Purpose: Write (send) a string to the SCI
; Input  : HX -> ASCIZ string, ie., Char1,Char2,...,0
; Output : None
; Note(s):
                    #spauto

?WriteZ             proc
                    pshhx
                    bsr       ?PrintString
                    pulhx
                    rts

;*******************************************************************************
; Purpose: (LOCAL) Write (send) a string to the SCI
; Input  : HX -> ASCIZ string, ie., Char1,Char2,...,0
; Output : HX -> past ASCIZ string
; Note(s):
                    #spauto

?PrintString        proc
                    psha
Loop@@              lda       ,x                  ;get char to print
                    aix       #1                  ;bump up pointer
                    beq       Done@@              ;on terminator, done
                    bsr       ?PutChar            ;print character
                    bra       Loop@@              ;repeat for all chars
Done@@              pula
                    rts

;*******************************************************************************
; Purpose: Display the copyright message on the SCI terminal
; Input  : None
; Output : None
; Note(s):
                    #spauto

?ShowCopyright      proc
                    ldhx      #?CopyrightMsgCls
                    bsr       ?WriteZ
;                   bra       ?ShowSerial

;*******************************************************************************

                    #spauto

?ShowSerial         proc
          #ifdef SERIAL_NUMBER
                    ldhx      #SERIAL_NUMBER

                    lda       ,x
                    cbeqa     #[ERASED_STATE,Done@@         ;All S/N should not have erased first byte ($FF)

                    @?print   'S/N: '
                    bsr       ?WriteZ
Done@@
          #endif
;                   bra       ?NewLine

;*******************************************************************************
; Purpose: Advance a line by sending a CR,LF pair (or equivalent) to the SCI
; Input  : None
; Output : None
; Note(s):
                    #spauto

?NewLine            proc
                    psha
          #ifndef LF2CRLF
                    lda       #CR                 ;send a CR
                    bsr       ?PutChar
          #endif
                    lda       #LF                 ;send a LF
                    bsr       ?PutChar
                    pula
                    rts

;*******************************************************************************
;@Page S19 module starts here
;*******************************************************************************

;*******************************************************************************
                    #XRAM
;*******************************************************************************

?line_crc           rmb       1                   ;S-record CRC
?address            rmb       2                   ;S-record address field
?length             rmb       1                   ;S-record length field
?rec_type           rmb       1                   ;S-record type field

;*******************************************************************************
                    #ROM
;*******************************************************************************

;*******************************************************************************
; Routine: LoadS19
; Purpose: Load an S19 file through the primary SCI port
; Input  : None
; Output : None
; Note(s): Only addresses within APP_CODE_START and APP_CODE_END and VECTORS
;        : are processed.
;        : ESC aborts

                    #spauto

?LoadS19            proc
MainLoop@@          clr       ?line_crc           ;Initialize CRC to zero

SkipBlanks@@        jsr       ?GetCharLocal       ;Get first/next character
                    beq       SkipBlanks@@        ;if EOL, skip blank lines
                    bcs       ??Error             ;abort on ESC

                    cbeqa     #'S',S@@            ;Probable S record

SkipLine@@          jsr       ?SkipToEOL          ;ignore rest of line
                    beq       MainLoop@@
??Error             jmp       ?Error              ;abort on ESC

S@@                 jsr       ?GetCharLocal       ;Get next character
                    bcs       ??Error             ;if ESC, get out with error

                    cbeqa     #'9',S9@@           ;Terminator record
                    cbeqa     #'1',S1@@           ;Code/data record
          #ifdef PPAGE
                    cbeqa     #'8',S8@@           ;Extended terminator record
                    cbeqa     #'2',S2@@           ;Extended address code/data record
          #endif
                    bra       SkipLine@@          ;skip S0 (header) or other lines

;*******************************************************************************
; Purpose: (LOCAL) Adjust the running CRC for the current record
; Input  : A = current byte
; Output : None
; Note(s):
                    #spauto

?UpdateCRC          proc
                    psha
                    add       ?line_crc
                    sta       ?line_crc
                    pula
                    rts
                    endp

;*******************************************************************************

S8@@
S9@@                @?print   '!'
                    bra       OK@@
S2@@
S1@@                @?print   '.'

OK@@                sta       ?rec_type           ;Save the record type
          ;--------------------------------------
          ; Get length of Record Bytes (including 16-bit address and 8-bit CRC)
          ;--------------------------------------
                    jsr       ?ReadHex            ;Get next 2 characters in binary
                    bcs       ??Error             ;if something wrong, get out with error
                    bsr       ?UpdateCRC

                    sub       #3                  ;adjust for 2-byte address and 1-byte CRC
                    sta       ?length             ;save Length of record (without address & CRC)
          ;-------------------------------------- ;get optional PPAGE of load address
          #ifdef PPAGE
                    mov       #2,PPAGE            ;assume default PPAGE for every new S record

                    lda       ?rec_type
                    cmpa      #'2'                ;S2 type record?
                    bne       GetAddress@@        ;if not, continue as usual

                    dec       ?length             ;adjust for 3rd address byte
                    jsr       ?ReadHex            ;get extended address byte (ppage)
                    bcs       ??Error
                    bsr       ?UpdateCRC
                    sta       PPAGE               ;update PPAGE for this record
          #endif
          ;-------------------------------------- ;now, get the load address
GetAddress@@        jsr       ?ReadHex            ;Get MSB of address
                    bcs       ??Error

                    sta       ?address            ;Save MSB of address
                    bsr       ?UpdateCRC

                    jsr       ?ReadHex            ;Get LSB of address
                    bcs       ?Error

                    sta       ?address+1          ;Save LSB of address
                    bsr       ?UpdateCRC
          ;-------------------------------------- ;now, get the code/data bytes
                    tst       ?length             ;Check Length of zero
                    beq       DoCRC@@             ;Empty code/data section of record

Loop@@              jsr       ?ReadHex            ;get first/next data byte
                    bcs       ?Error              ;if something wrong, get out with error

                    bsr       ?UpdateCRC
          ;--------------------------------------
          ; Add load-time CRC calculation here, if required
          ;-------------------------------------- ;save byte and advance pointer
                    ldhx      ?address            ;Get address in HX
                    bsr       ?CheckAddr          ;Check address to be
                    bcs       RangeError@@        ; within valid Flash limits

                    cphx      #VECTORS
                    blo       Save@@
          #ifz RVECTORS-VECTORS&$FF
                    psha
                    tha
                    add       #RVECTORS-VECTORS>8&$FF
                    tah
                    pula
          #else
                    @aix      #RVECTORS-VECTORS   ;redirector to user vectors
          #endif
Save@@              jsr       ?FlashWrite         ;Save to Flash
                    beq       NextByte@@

                    @?print   BS,'F'              ;Flash error indicator

NextByte@@          ldhx      ?address
                    aix       #1                  ;Adjust the PC value by 1
                    sthx      ?address
                    dbnz      ?length,Loop@@      ;One less byte to read
;-------------------------------------------------------------------------------
DoCRC@@             bsr       ?ReadHex            ;Get CRC byte
                    bcs       ?Error              ;if something wrong, get out with error

                    com       ?line_crc           ;Get one's complement of final CRC value
                    cbeq      ?line_crc,GoNext@@  ;Is it the same as the one calculated. Yes, continue

                    @?print   BS,'C'              ;CRC error indicator

          ;See if we're done (i.e., if we just processed an S9 record)

GoNext@@            bsr       ?SkipToEOL          ;Clean up to the end of line
                    lda       ?rec_type           ;Check record type
                    cbeqa     #'9',?Success       ;Done, get out without errors
          #ifdef PPAGE
                    cbeqa     #'8',?Success       ;Done, get out without errors
          #endif
                    jmp       MainLoop@@          ;Go back to read another line
;-------------------------------------------------------------------------------
RangeError@@        @?print   BS,'R'              ;Address Range error indicator
                    bra       NextByte@@          ;skip error byte

;*******************************************************************************

?SkipToEOL          proc
Loop@@              bsr       ?GetCharLocal
                    bcc       Loop@@
?Error              sec
                    rts

;*******************************************************************************
; Purpose: Check address to be within range
; Input  : HX = address
; Output : Carry Clear if within valid ranges
;        : Carry Set if outside valid ranges
; Note(s):

?CheckAddr          proc
          #ifdef PPAGE
          ;--------------------------------------
          ; PPAGE 2 (startup default) has a different allowable range
          ;--------------------------------------
                    @cmp.s    PPAGE #2            ;for all but the default page
                    beq       CheckAddr@@
          ;--------------------------------------
          ; Do a single PPAGE address range check and exit
          ;--------------------------------------
                    cphx      #:PAGE_START
                    blo       ?Error

                    cphx      #:PAGE_END
                    bhi       ?Error

                    clc
                    rts
CheckAddr@@
          #endif
          #ifdef ALLOW_EEPROM
                    #Message  EEPROM is allowed
                    cphx      #EEPROM
                    blo       Go@@

                    cphx      #EEPROM_END
                    bls       Done@@
          #endif
Go@@                cphx      #APP_CODE_START     ;Check address to be
                    blo       ?Error              ; within valid Flash

                    cphx      #VECTORS            ; limits.
                    bhs       Done@@              ;Vectors are passed

                    cphx      #APP_CODE_END       ; as is, and redirected
                    bhi       ?Error              ; automatically by loader.
          #if HighRegs > APP_CODE_START
                    cphx      #HighRegs           ;Check address for hole
                    blo       Done@@              ; in Flash created by

                    cphx      #HighRegs_End       ; HighRegs (certain MCUs only)
                    bls       ?Error
          #endif
Done@@              clc                           ;no errors from here
                    rts

?Success            equ       Done@@

;*******************************************************************************
; Purpose: Read next character from S19 file
; Input  : None
; Output : A = next S19 file character converted to uppercase
;        : CCR[C] = 1 and CCR[Z] = 1 if CR received (normal end-of-line)
;        : CCR[C] = 1 and CCR[Z] = 0 if ESC received (abort)
;        : CCR[C] = 0 and CCR[Z] = 0 for any other character
; Note(s):
                    #spauto

?GetCharLocal       proc
                    jsr       ?GetChar            ;Get a character

                    cmpa      #CR                 ;Z=1 if CR found, Z=0 anything else
                    beq       ?Error              ;(do NOT change to CBEQA)

                    clc                           ;assume no error
                    cbeqa     #ESC,?Error         ;ESC cancels
;                   bra       ?Upcase

;*******************************************************************************
; Purpose: Convert one character to uppercase
; Input  : A = character
; Output : A = CHARACTER
; Note(s): Protects caller's CCR

                    #spauto

?Upcase             proc
                    pshx
                    tpx                           ;(transfer CCR to X)
                    cmpa      #'a'
                    blo       Done@@
                    cmpa      #'z'
                    bhi       Done@@
                    add       #'A'-'a'
Done@@              txp                           ;(transfer X to CCR)
                    pulx
                    rts

;*******************************************************************************
; Purpose: Read two-digit ASCII hex from SCI and convert to binary value in A
; Input  : None
; Output : A = binary value
; Note(s): Destroys HX

                    #spauto

?ReadHex            proc
                    bsr       ?GetCharLocal       ;Get next character
                    bcs       Done@@              ;if EOL, get out with error

                    jsr       ?HexByte            ;Convert from Hex to Binary
                    bcs       Done@@              ;if not hex, get out with error

                    nsa                           ;Move to high nibble
                    tax                           ;save temporarily in X

                    bsr       ?GetCharLocal       ;Get next character
                    bcs       Done@@              ;if EOL, get out with error

                    jsr       ?HexByte            ;Convert from Hex to Binary
                    bcs       Done@@              ;Invalid character, ignore rest of line

                    pshx      tmp@@
                    tsx                           ;20131006 addition
                    ora       tmp@@,spx           ;combine LSN with MSN
                    pulx

;                   clc                           ;indicate "no error" (valid since BCS fall thru)
Done@@              rts

;*******************************************************************************
;@Page Flash module starts here
;*******************************************************************************

;*******************************************************************************
; Flash programming command codes

mBlank              def       $05                 ;Blank check
mByteProg           def       $20                 ;Byte programming
mBurstProg          def       $25                 ;Burst programming
mPageErase          def       $40                 ;Page erase
mMassErase          def       $41                 ;Mase erase

;*******************************************************************************
; Purpose: RAM routine to do the job we can't do from Flash
; Input  : A = value to program
; Output : None
; Note(s): This routine is modified in RAM at zero-based offsets
;        : @1, @2 (address) and @4 (Flash command)
;        : RAM needed: 20 bytes

                    #spauto

?RAM_Code           proc
                    sta       $FFFF               ;Step 1 - Latch data/address
?ADDR_OFFSET        equ       :pc-?RAM_Code-2,2   ;$FFFF (@1,@2) replaced with actual address during RAM copying
                    lda       #mByteProg          ;mByteProg (@4) replaced with actual command during RAM copying
?CMD_OFFSET         equ       :pc-?RAM_Code-1,1
                    sta       FCMD                ;Step 2 - Write command to FCMD

                    lda       #FCBEF_             ;Step 3 - Write FCBEF_ in FSTAT
                    sta       FSTAT

                    lsra                          ;min delay before checking FSTAT (four bus cycles)
                                                  ;instead of NOP (moves FCBEF -> FCCF for later BIT)
Loop@@              bit       FSTAT               ;Step 4 - Wait for completion
                    beq       Loop@@              ;check FCCF_ for completion
                    rts                           ;after exit, check FSTAT for FPVIOL and FACCERR

                    #size     ?RAM_Code

;*******************************************************************************
                    #XRAM
;*******************************************************************************

?burn_routine       rmb       ::?RAM_Code

?burn_address       equ       ?burn_routine+?ADDR_OFFSET,2
?burn_command       equ       ?burn_routine+?CMD_OFFSET,1

;*******************************************************************************
                    #ROM
;*******************************************************************************

;*******************************************************************************
; Purpose: Program an internal Flash location
; Input  : HX -> Flash memory location to program
;        : A = value to write
; Output : CCR[Z] on success
; Note(s): Does not program (skips) non-erased locations

                    #spauto

?FlashWrite         proc
                    cmpa      ,x                  ;(do NOT replace with CBEQ)
                    beq       Done@@              ;value already there, no need to update
          #ifz ERASED_STATE
                    tst       ,x                  ;test if erased, and if not
          #else
                    psha
                    lda       ,x                  ;if not erased already
                    coma
                    pula
          #endif
                    bne       Done@@              ;skip (and report as failure, CCR[Z]=0)

                    bsr       ?PrepareFlash

                    mov       #mByteProg,?burn_command ;save command within LDA #?? instruction
;                   bra       ?FlashIt

Done@@              equ       :AnRTS

;*******************************************************************************
; Purpose: Call RAM routine
; Input  : HX = address to Flash
;        : BurnCommand already set with Flash command
;        : A = value to program
; Output : A = FSTAT
;        : CCR[Z] = 1 on success
; Note(s): Destroys all registers

                    #spauto

?FlashIt            proc
                    sthx      ?burn_address       ;save HX within STA $FFFF instruction
;                   pshcc
;                   sei                           ;disable interrupts (never enabled in this app)
                    @cop                          ;reset COP (for maximum tolerance)
                    jsr       ?burn_routine       ;execute RAM routine to perform Flash command
;                   pulcc
                    lda       FSTAT
                    bit       #FPVIOL_|FACCERR_
                    rts

;*******************************************************************************
; Purpose: Erase an internal Flash page by address
; Input  : HX -> location within page to erase
; Output : CCR[Z] on success
; Note(s): Forces address past HighRegs (if any).

                    #spauto

?FlashErase         proc
          #ifdef HighRegs
                    cphx      #HighRegs
                    blo       Cont@@

                    cphx      #HighRegs_End
                    bhi       Cont@@

                    ldhx      #HighRegs_End+1
          #endif
Cont@@              bsr       ?PrepareFlash

                    mov       #mPageErase,?burn_command ;save command within LDA #?? instruction
                    bra       ?FlashIt

;*******************************************************************************
;*                         Supporting routines
;*******************************************************************************

;*******************************************************************************
; Purpose: Prepare Flash for programming
; Input  : None
; Output : None
; Note(s): Makes FCLK fall between 150-200KHz [FCLK=FBUS/(DIV+1)] and DIV=0..63

                    #spauto

?PrepareFlash       proc
                    psha

                    lda       FCDIV
                    bmi       Done@@

                    lda       #FLASH_CLK_VALUE    ;required to allow further
                    sta       FCDIV               ;access to Flash programming

Done@@              lda       #FPVIOL_|FACCERR_
                    sta       FSTAT               ;clear possible errors

                    pula
                    rts

;*******************************************************************************
?mcu                macro     MCU[,MCU]*
          #ifdef _~{:loop}.~_
                    fcc       \@ ~{:loop}.~\@
                    mexit
          #endif
                    mtop      :n
                    endm
;*******************************************************************************

                    #MapOn

?CopyrightMsgCls    fcc       ASCII_FF,CR         ;a Form Feed and CR (for CLS)
?CopyrightMsg       fcc       'TBoot v{BOOTROM_VERSION(2)} (c) {:year} ASPiSYS'
          #ifexists checkout.inc
                    fcc       ' [Build '
                    #Include  checkout.inc
                    fcc       ']'
          #endif
                    @?mcu     QE128,QE8,QE32,GB60,AC32,AC96,QD2,QD4,DZ32,DZ60,SH8,QG8
                    fcc       ' {HZ/1000(3)} MHz'
          #ifmmu
                    fcc       ' MMU'
          #endif
                    fcb       0                   ;ASCII terminator

;*******************************************************************************
; Purpose: Initialize the MCU with MCU-specific settings for TBoot monitor
; Input  : None
; Output : None
; Note(s): You can affect one-time writable settings as exit is always via reset

                    #spauto

?Initialize         proc
          #ifdef NVICSTRM
                    lda       NVICSTRM
                    sta       ICSTRM
            #ifdef FTRIM_
                    lda       NVFTRIM
                    and       #FTRIM_
              #ifdef DRS1_&DRS0_
                #if MHZ >= 48
                    ora       #DRS1_              ;high DCO range (%01) x1536
                #else if MHZ >= 32
                    ora       #DRS0_              ;middle DCO range (%01) x1024
                #endif
              #endif
                    sta       ICSSC
            #endif
          #else ifdef NVICGTRM
                    lda       NVICGTRM
                    sta       ICGTRM
          #endif
          #ifdef _AC_
                    brclr     DCOS.,ICGS2,*       ;wait for stabilization
                    mov       #%00001100,ICGC1
                              ; ||||||||
                              ; |||||||+--------- Not Used
                              ; ||||||+---------- LOCD (1=Loss of clock disabled)
                              ; |||||+----------- OSCSTEN (1=Enable in off mode)
                              ; |||++------------ CLKS (01 FLL engaged, internal reference)
                              ; ||+-------------- REFS
                              ; |+--------------- RANGE (0=Low, 1=High) reference
                              ; +---------------- HGO (1=High Gain Oscillator)

                    mov       #%01110000,ICGC2    ;Example: 40MHz -> 243KHz/7*64*MFD/RFD
                              ; ||||||||
                              ; |||||+++--------- RFD (1)
                              ; ||||+------------ LOCRE
                              ; |+++------------- MFD (18)
                              ; +---------------- LOLRE

                    brclr     LOCK.,ICGS1,*       ;wait for FLL lock
          #endif
          #ifdef _AC_
SOPT_VALUE          def       %00110011
          #else              ; |||xxxxx
SOPT_VALUE          def       %00100010
          #endif             ; ||||||||
                             ; ||||||||
                             ; |||||||+---------  RSTPE - RST pin enable
                             ; ||||||+----------  BKGDPE - BKGD/MS pin for debugging only
                             ; |||||+-----------  RSTOPE - RTSO pin enable
                             ; |||++------------  Not Used
                             ; ||+--------------  STOPE - Stop Mode Enable
                             ; |+---------------  COPT - COP Timeout (0=Short [32msec], 1=Long [256msec])
                             ; +----------------  COPE - COP Enable
          #ifdef QE128
            #ifnz SOPT_VALUE&COPE_
                    #Warning  COPE does not work well with buggy (QE128) chips
            #endif
          #endif
                    lda       #SOPT_VALUE
                    sta       SOPT                ;write-once register
;         #!ifz ]ICSC1
;                   mov       #%00000111|RDIV_,ICSC1
;                             ; |||||||+--------- IREFSTEN
;                             ; ||||||+---------- IRCLKEN
;                             ; |||||+----------- IREFS
;                             ; ||+++------------ RDIV
;                             ; ++--------------- CLKS
;         #else ifdef ICSC1
;                   lda       #%00000111|RDIV_
;                   sta       ICSC1
;         #endif
          #!ifz ]ICSC2
                    mov       #%00000000|BDIV_|RANGE_,ICSC2
                              ; |||||||+--------- EREFSTEN
                              ; ||||||+---------- ERCLKEN
                              ; |||||+----------- EREFS
                              ; ||||+------------ LP
                              ; |||+------------- HGO
                              ; ||+-------------- RANGE
                              ; ++--------------- BDIV
          #else ifdef ICSC2
                    lda       #%00000000|BDIV_|RANGE_
                    sta       ICSC2
          #endif
;                   bra       ?CopyRamCode

;*******************************************************************************
; Purpose: Copy programming routine from Flash to RAM
; Input  : None
; Output : None
; Note(s):
                    #spauto

?CopyRamCode        proc
          #if ::?RAM_Code <= 256                  ;(most likely scenario)
                    ldhx      #::?RAM_Code        ;(do NOT use CLRH, LDX)
Loop@@              lda       ?RAM_Code-1,x
                    sta       ?burn_routine-1,x
                    dbnzx     Loop@@              ;repeat for all bytes
          #else
                    clrhx
Loop@@              lda       ?RAM_Code,x
                    sta       ?burn_routine,x
                    aix       #1                  ;point to next byte to process
                    cphx      #::?RAM_Code        ;are we done?
                    blo       Loop@@
          #endif
                    rts

;*******************************************************************************
; Fixed vectors are always negative offsets in multiples of 2 from Reset Vector
; From your app, you can access this way:
;                   ldhx      Vreset
;                   ldhx      -2,x
; (where -2 is the appropriate object offset)
;*******************************************************************************
          #ifdef _FL_&&!ID||!_FL_
                    dw        0                   ;indicates end of backward list since v1.20
          #endif
                    dw        ?CopyrightMsg       ;@-2 Copyright ASCIZ string

;*******************************************************************************
;                    PROGRAM EXECUTION STARTS HERE
;*******************************************************************************

                    #spauto

?Start              proc
                    @rsp
                    @cop
          #ifexists shutdown.tmp
                    #Include  shutdown.tmp        ;do special shutdown instructions (if present)
          #endif
                    bmc       ?Monitor            ;in user code entry ints are enabled

                    mov       #IRQPE_,IRQSC
                              ; |||||||+--------- IRQMOD (0=edge, 1=level)
                              ; ||||||+---------- IRQIE (1=Interrupts Enabled)
                              ; |||||+----------- IRQACK
                              ; ||||+------------ IRQF
                              ; |||+------------- IRQPE (1=Pin Enabled)
                              ; ||+-------------- IRQEDG (0=Falling Edge)
                              ; |+--------------- IRQPDD (1=Pulls Disabled)
                              ; +---------------- Always zero

                    jsr       ?cmdRun
;                   bra       ?Monitor

;*******************************************************************************

?Monitor            proc
                    sei                           ;just in case we entered from user code
                    bsr       ?Initialize
          ;--------------------------------------
          ; Initialize the RS232 communications channel
          ;--------------------------------------
          #ifdef ?SetBAUD
                    ldhx      #?MY_BPS_RATE
                    jsr       ?SetBAUD
          #endif
                    jsr       ?ShowCopyright      ;display copyright message for boot loader
;                   bra       ?MainLoop

;*******************************************************************************
; Main loop accepts three commands (E-rase, L-oad, or ESC-ape)
;*******************************************************************************

                    #spauto

?MainLoop           proc
Loop@@
          #ifdef ENABLE_RUN
                    @?print   LF,'[E]rase [L]oad [R]un [ESC]ape:'
          #else
                    @?print   LF,'[E]rase [L]oad [ESC]ape:'
          #endif
                    jsr       ?GetChar
                    jsr       ?Upcase

                    cbeqa     #ESC,?ForceReset    ;(does not return)
                    cbeqa     #'E',Erase@@
                    cbeqa     #'L',Load@@
          #ifdef ENABLE_RUN
                    cbeqa     #'R',Run@@
          #endif
                    bra       Fail@@              ;print ERROR on wrong cmd
          #ifdef ENABLE_RUN
Run@@               jsr       ?RunNow             ;we need JSR in case no code is found
                    bra       Fail@@
          #endif
Erase@@
          #ifdef DISABLE_SURE
                    @?print   LF,'Erasing'
          #else
                    @?print   LF,'Sure?'
                    jsr       ?GetChar
                    cmpa      #'Y'
                    bne       Fail@@
                    @?print   CR,'Erasing'
          #endif
                    jsr       ?EraseFlash
                    bcc       Loop@@
                    bra       Fail@@

Load@@              @?print   LF,'Loading'
                    jsr       ?LoadS19
                    bcc       Loop@@

Fail@@              @?print   ' Error'
                    bra       Loop@@

;*******************************************************************************

?ForceReset         reset                         ; force a reset

;*******************************************************************************
; Purpose: Check if app firmware is available (based on relocated reset vector)
; Input  : None
; Output : HX = execution address
;        : Carry Clear = BOOTMODE enabled
; Note(s):
                    #spauto

?IsAppPresent       proc
                    ldhx      Vreset&$FF|RVECTORS

                    cphx      #APP_CODE_START
                    blo       Fail@@

                    cphx      #BOOTROM
                    bhs       Fail@@

                    clc
                    rts
?No
Fail@@              sec
                    rts

;*******************************************************************************
;                     M O N I T O R   C O M M A N D S
;*******************************************************************************

                    #spauto

?cmdRun             proc
          #ifdef NO_IRQ
            #ifdef TIBBO_DTR
                    @Pullup   TIBBO_DTR,,-1
                    brset     TIBBO_DTR,Done@@    ;force entry to Monitor mode with high Tibbo DTR pin
            #else
                    brn       *                   ;keep image size the same as when BIL is used
            #endif
          #else
                    bil       Done@@              ;force entry to Monitor mode with low IRQ pin
          #endif
;                   bra       ?RunNow
Done@@              equ       :AnRTS

;*******************************************************************************

?RunNow             proc
                    bsr       ?IsAppPresent
                    bcs       Done@@              ;erased vector never executes
                    clra
                    sta       IRQSC               ;restore IRQ to reset default
          #ifdef ?SCIC1
                    sta       ?SCIC1              ;restore all SCI registers
                    sta       ?SCIC2              ;... to their default status
                    sta       ?SCIBDH
                    lda       #4
                    sta       ?SCIBDL
          #endif
                    sthx      $FE                 ;address at top of page zero
                    @lds      #$FE                ;set default out-of-reset SP
                    clra
                    clrhx
Done@@              RTS                           ;return OR execute user code

;*******************************************************************************
; Purpose: Convert an ASCII hex byte '0' to 'F' to binary value
; Input  : A = hex ASCII
; Output : A = binary equivalent, Carry Clear
;        : Carry Set if digits not in 0-9, A-F/a-f character set
; Note(s):
                    #spauto

?HexByte            proc
                    jsr       ?Upcase

                    cmpa      #'0'
                    blo       Done@@              ;Fail@@ really (but CCR[C]=1 already)

                    cmpa      #'F'
                    bhi       Fail@@

                    cmpa      #'9'
                    bls       Number@@

                    cmpa      #'A'
                    blo       Done@@              ;Fail@@ really (but CCR[C]=1 already)

                    sub       #'A'-10-'0'
Number@@            sub       #'0'
;                   clc                           ;(redundant due to positive SUB result)
Done@@              rts

Fail@@              equ       ?No

;*******************************************************************************

                    #spauto

?EraseFlash         proc
          #ifdef PPAGE
                    clr       PPAGE               ;start from first page
NewPage@@           ldhx      #:PAGE_START        ;lower MMU page boundary
Loop@@              pshhx
                    jsr       ?FlashErase         ;erase this page
                    pulhx
;;;;;;;;;;;;;;;;;;; bne       Fail@@
                    @aix      #FLASH_PAGE_SIZE    ;HX -> next page
                    cphx      #:PAGE_END          ;end of MMU page window?
                    blo       Loop@@              ;repeat for all Flash pages
                    inc       PPAGE               ;go to next page
            #if PPAGES = 8
                    tst       PPAGE               ;required, INC result CCR[Z] is invalid
            #else if PPAGES < 8
                    lda       PPAGE
                    cmpa      #PPAGES
            #else
                    #Fatal    Unexpected PPAGES ({PPAGES})
            #endif
                    bne       NewPage@@           ;repeat for all PPAGEs
;                   clc                           ;indicate "no error" (valid since BLO fall thru)
                    rts
          #else ;---------------------------------------------------------------
                    ldhx      #FLASH_START        ;user firmware's first page
Loop@@              pshhx
                    jsr       ?FlashErase         ;erase this page
                    pulhx
                    bne       Fail@@
                    @aix      #FLASH_PAGE_SIZE    ;HX -> next page
                    cphx      #BOOTROM            ;user firmware's last page
                    blo       Loop@@              ;repeat for all Flash pages
;                   clc                           ;indicate "no error" (implied by BLO fall thru)
                    rts

Fail@@              equ       ?No
          #endif
;*******************************************************************************

?                   macro     RealVector
                    mset      2,VECTORS-RVECTORS  ;offset for moving vectors
                    #push
                    #ROM
?~1.2~              proc
                    #Cycles
                    @@ReVector ~1~-{~2~}
                    #pull
                    @@vector  ~1~,?~1.2~
          #if :mindex = 1
                    #Message  Vector redirection overhead: {:cycles} cycles
          #endif
                    endm

          #ifdef QE128
                    @?        Vtpm3ovf            ;TPM3 overflow vector
                    @?        Vtpm3ch5            ;TPM3 channel 5 vector
                    @?        Vtpm3ch4            ;TPM3 channel 4 vector
                    @?        Vtpm3ch3            ;TPM3 channel 3 vector
                    @?        Vtpm3ch2            ;TPM3 channel 2 vector
                    @?        Vtpm3ch1            ;TPM3 channel 1 vector
                    @?        Vtpm3ch0            ;TPM3 channel 0 vector
                    @?        Vrtc                ;RTC vector
                    @?        Vsci2tx             ;SCI2 TX vector
                    @?        Vsci2rx             ;SCI2 RX vector
                    @?        Vsci2err            ;SCI2 Error vector
                    @?        Vacmpx              ;ACMP - Analog Comparator
                    @?        Vadc                ;Analog-to-Digital conversion
                    @?        Vkeyboard           ;Keyboard vector
                    @?        Viicx               ;IIC vector
                    @?        Vsci1tx             ;SCI1 TX vector
                    @?        Vsci1rx             ;SCI1 RX vector
                    @?        Vsci1err            ;SCI1 Error vector
                    @?        Vspi1               ;SPI1 vector
                    @?        Vspi2               ;SPI2 vector
                    @?        Vtpm2ovf            ;TPM2 overflow vector
                    @?        Vtpm2ch2            ;TPM2 channel 2 vector
                    @?        Vtpm2ch1            ;TPM2 channel 1 vector
                    @?        Vtpm2ch0            ;TPM2 channel 0 vector
                    @?        Vtpm1ovf            ;TPM1 overflow vector
                    @?        Vtpm1ch2            ;TPM1 channel 2 vector
                    @?        Vtpm1ch1            ;TPM1 channel 1 vector
                    @?        Vtpm1ch0            ;TPM1 channel 0 vector
                    @?        Vlvd                ;low voltage detect vector
                    @?        Virq                ;IRQ pin vector
                    @?        Vswi                ;SWI vector
          #else ifdef AC96
                    @?        Vspi2               ;SPI2 vector
                    @?        Vtpm3ovf            ;TPM3 overflow vector
                    @?        Vtpm3ch1            ;TPM3 channel 1 vector
                    @?        Vtpm3ch0            ;TPM3 channel 0 vector
                    @?        Vrti                ;Real Time Interrupt vector
                    @?        Viic                ;IIC vector
                    @?        Vadc                ;Analog-to-Digital conversion
                    @?        Vkeyboard           ;Keyboard vector
                    @?        Vsci2tx             ;SCI2 TX vector
                    @?        Vsci2rx             ;SCI2 RX vector
                    @?        Vsci2err            ;SCI2 Error vector
                    @?        Vsci1tx             ;SCI1 TX vector
                    @?        Vsci1rx             ;SCI1 RX vector
                    @?        Vsci1err            ;SCI1 Error vector
                    @?        Vspi                ;SPI vector
                    @?        Vtpm2ovf            ;TPM2 overflow vector
                    @?        Vtpm2ch5            ;TPM2 channel 5 vector
                    @?        Vtpm2ch4            ;TPM2 channel 4 vector
                    @?        Vtpm2ch3            ;TPM2 channel 3 vector
                    @?        Vtpm2ch2            ;TPM2 channel 2 vector
                    @?        Vtpm2ch1            ;TPM2 channel 1 vector
                    @?        Vtpm2ch0            ;TPM2 channel 0 vector
                    @?        Vtpm1ovf            ;TPM1 overflow vector
                    @?        Vtpm1ch5            ;TPM1 channel 5 vector
                    @?        Vtpm1ch4            ;TPM1 channel 4 vector
                    @?        Vtpm1ch3            ;TPM1 channel 3 vector
                    @?        Vtpm1ch2            ;TPM1 channel 2 vector
                    @?        Vtpm1ch1            ;TPM1 channel 1 vector
                    @?        Vtpm1ch0            ;TPM1 channel 0 vector
                    @?        Vicg                ;ICG vector
                    @?        Vlvd                ;low voltage detect vector
                    @?        Virq                ;IRQ pin vector
                    @?        Vswi                ;SWI vector
          #endif
                    @vector   Vreset,?Start       ;/RESET vector

                    end       :s19crc
;*******************************************************************************
                    #Export   APP_CODE_START,APP_CODE_END
                    #Export   APP_CODE_START ROM,APP_CODE_END ROM_END
                    #Export   BOOTROM,BOOTROM_VERSION
                    #Export   FLASH_DATA_SIZE
          #ifnz FLASH_DATA_SIZE
                    #Export   EEPROM,EEPROM_END
          #endif
                    #Export   RVECTORS
;*******************************************************************************
                    @EndStats
