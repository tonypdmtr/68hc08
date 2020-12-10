;*******************************************************************************
; LCDTERM.ASM
;
; LCD Terminal with an MC68HC908QY4 and an HD44780 LCD display
; PortA Bit 0 is used for RS232 reception via the GetByte ROM routine
; Since the LCD display is a bit slow, Getbyte is turned into a KeyBoard
; Interrupt routine called. KBInt is active on PTA0 and we on
; falling edge called, there GetByte is called and the
; Data saved. The MCU is programmed with the UserMonitor.
; Therefore the alternative vector addresses are used.
;
;
; Everything that is urgently needed is available
; Adding the ability to load characters would be good
; Characters greater than 127 are not intercepted, but do not match
; German character set
; Control characters like CR LF or Backspace are not implemented
; The terminal should only be from an MC anyway and not from a keyboard
; to be discribed
;*******************************************************************************

;*******************************************************************************
; VT100 Kommandos
;
; Reset Device          <ESC>c                       ok
; Cursor Home           <ESC>[H                      ok
; Cursor Up             <ESC>[{COUNT}A
; Cursor Down           <ESC>[{COUNT}B
; Cursor Forward        <ESC>[{COUNT}C
; Force Cursor Position <ESC>[{ROW};{COLUMN}f        ok
; Scroll Up             <ESC>M                       ok
; Erase End of Line     <ESC>[K                      ok
; Erase Line            <ESC>[2K                     ok
; Erase Screen          <ESC>[2J                     ok
;*******************************************************************************

                    #Uses     qt4.inc

;*** SYSTEM DEFINITIONS AND EQUATES ********************************************

;**** Equates to setup alternate vectors **********************************
; actual vectors will pass control to these locations.
; user code would include jump instructions at these locations that
; jump to the user's interrupt service routines, for example
;                   org       AltADC                                               *
;                   jmp       ADCisr                                               *
;                   jmp       KBDisr                                               *
;*******************************************************************************

AltADC              equ       $FDEB               ; Alternate ADC interrupt vector
AltKBD              equ       $FDEE               ; '     KBD wakeup ' '
AltTOF              equ       $FDF1               ; '     TOF        ' '
AltTCH1             equ       $FDF4               ; '     Timer Ch.1 ' '
AltTCH0             equ       $FDF7               ; '     Timer Ch.0 ' '
AltIRQ              equ       $FDFA               ; '     IRQ        ' '
AltRESET            equ       $FDFD               ; '     RESET      ' '

TRIMLOC             equ       $FFC0               ; nonvolatile trim value (flash)
InitConfig1         equ       %01001001           ; Config Register1
GetByte             equ       $2D6b               ; ROM routine Getbyte auf PTA0

;*** Application Specific Definitions ******************************************

LCD_CTRL            equ       $00                 ; PORTA
LCD_DATA            equ       $01                 ; PORTB
E                   equ       4                   ; PORTA, bit 4
RS                  equ       5                   ; PORTA, bit 5
ESC                 def       $01B                ; Escape Character

;*** SCI Definitionen **********************************************************

PTA                 equ       $0000
PTA0                equ       0                   ; bit #0 for PTA0

;*** LCD Kommandos *************************************************************

CLRDISP             equ       %00000001           ; Display L?schen
CURHOME             equ       %00000010           ; Cursor Home
ENTMODI             equ       %00000111           ; Character Entry Mode mit Inkrement
ENTMODD             equ       %00000101           ; Character Entry Mode mit Dekrement
ENTMODO             equ       %00000100           ; Character Entry Moode Off
DSPON               equ       %00001100           ; Diplay On
DSPOFF              equ       %00001000           ; Display Off
CURON               equ       %00001111           ; Cursor Underline blinking on
CUROFF              equ       %00001100           ; Cursor off
SETRAMADR           equ       %01000000           ; Set Ram Adress
SETDSPADR           equ       %10000000           ; Set Display Adress
FUNCSET             equ       %00111000           ; Function Set 8 Bit 5*7 Pixel

;*** LCD Adressen **************************************************************

row1adr             equ       $80                 ; Startadresse Zeile 1
row2adr             equ       $C0                 ; Startadresse Zeile 2

;*** Memory Definitions ********************************************************

ROM                 def       $EE00               ; start of Flash mem
RAM                 def       $80                 ; start of RAM mem

MSG_STORAGE         equ       $FA00               ; start of message block

;*** RAM VARIABLEN *************************************************************

                    org       RAM

TIME                ds        1                   ; in delay routine benutzt
zeichen             ds        1                   ; aktuelles Zeichen
row                 ds        1                   ; Zeile
col                 ds        1                   ; spalte
inptr               ds        1                   ; position im Empfangspuffer f?r empfang
outptr              ds        1                   ; position im empfangspuffer f?r ausgabe
data                ds        32                  ; Empfangsdaten puffer 32 Byte
screen              ds        32                  ; Speicherabbild der Anzeige 2 Zeilen a 16 Byte
parm1               ds        1                   ; Parameter f?r VT Kommandos
parm2               ds        1

;***      71 Byte Ram used

;*** MAIN ROUTINE **************************************************************

                    org       ROM                 ; start am annfang des FLASH ROMs

                    lda       InitConfig1         ; Configregister Schreiben
                    sta       CONFIG1
                    lda       TRIMLOC             ; Oszillator trim value laden
                    sta       OSCTRIM             ; und setzen

;*** Initialize ram ************************************************************

                    jsr       raminit

;*** Initialize Ports **********************************************************

START               bclr      E,LCD_CTRL          ; clear LCD_CTRL
                    bclr      RS,LCD_CTRL
                    clr       LCD_DATA            ; clear LCD_DATA
                    lda       #$FF                ; make ports outputs
                    sta       DDRB                ; PortB output
                    bset      E,DDRA              ; PORTA Pins als outputs
                    bset      RS,DDRA

;*** Initialisiere Keyboard int auf PTA0 **********************************

                    sei                           ; erstmal Interuppts verbieten
                    mov       #%00000100,KBSCR    ; Pending ints l?schen Ints zulassen fallenden flanke
                    mov       #%00000001,KBIER    ; PTA0 Interrupt zulassen

;*** LCD Initialisieren ***************************************************

                    bsr       LCD_init

;*** weitere Initialisierungen ********************************************

                    lda       #$80                ; Adresse Beginn Zeile 1
                    jsr       LCD_ADDR            ; send addr to LCD
                    clr       row                 ; und Cursorposituion wegschreiben
                    clr       col
;                   lda       #$80
;                   jsr       LCD_ADDR
                    cli                           ; von jetzt an Interrupts zulassen

;*** Beginn der eigentlichen Verarbeitung *********************************
loop
                    jsr       getchar             ; Zeichen holen
                    cmp       #$20
                    blo       loop3               ; < $20 ist steuerzeichen

loop1
                    sta       zeichen
                    jsr       LCD_WRITE           ; Zeichen ausgeben
                    lda       row
                    nsa
                    add       col
                    tax
                    lda       zeichen
                    sta       screen,x
                    inc       col                 ; Spalte hochz?hlen
                    lda       col                 ; Letzte Spalte ?
                    cmp       #$10
                    bne       loop                ; nein dann n?chstes Zeichen
                    lda       row                 ; zweite Zeile ?
                    bne       loop2               ; ja dann nur auf Anfang setezen
                    inc       row                 ; Zeilenz?hler erh?hen
loop2
                    lda       #row2adr            ; Startadresse 2te Zeile laden
                    jsr       LCD_ADDR            ; Adresse setzen
                    clr       col                 ; Spalte auf 0 setzen
                    bra       loop                ; und von vorne

loop3
                    cmp       #ESC                ; ESC dann Kommando
                    bne       loop4               ; andere erstmal nicht
                    clr       parm1               ; parameter initialisieren
                    clr       parm2
                    jsr       vt_command
; andere steuerzeichen erstmal ignorieren
loop4
                    bra       loop                ; und von vorne los

DUMMY               bra       DUMMY               ; Hier soll es eigentlich nie hingehen

;*******************************************************************************
;  unterprogramme
;*******************************************************************************

;*******************************************************************************
; VAR_DELAY
;
; Wartet TIME mal 100 us
; bei 3,2 MHz internener Busfrequenz 320 Takte
;
;*******************************************************************************

VAR_DELAY           lda       #33                 ; 2

VAR_DEL1
                    deca                          ; 1
                    nop                           ; 1
                    nop                           ; 1
                    nop                           ; 1
                    nop                           ; 1
                    nop                           ; 1 =6 Takte
                    nop
                    nop

                    bne       VAR_DEL1            ; 9 * 33 Takte = 297 Takte + 2 = 299 Takte

                    dec       TIME                ; 4 = 303 Zakte

                    brn       VAR_DEL1            ; 3 = 306
                    brn       VAR_DEL1            ; 3 = 309
                    brn       VAR_DEL1            ; 3 = 312
                    nop                           ; 1 = 313
                    nop                           ; 1 = 314
                    bne       VAR_DEL1            ; 3 = 317
                    rts                           ; 4

;*******************************************************************************
; LCD Routinen
;*******************************************************************************

;*******************************************************************************
; LCD_init
;
; Initialisiert das Display
;
;*******************************************************************************

LCD_init

;*** 15ms warten

                    bclr      RS,LCD_CTRL         ; LCD auf Instruction setzen
                    lda       #150
                    sta       TIME                ; set delay time
                    bsr       VAR_DELAY           ; sub for 0.1ms delay

;*** Send Init Command

                    lda       #FUNCSET            ; LCD init command
                    sta       LCD_DATA
                    bset      E,LCD_CTRL          ; clock in data
                    bclr      E,LCD_CTRL

;*** Warten 4.1ms

                    lda       #41
                    sta       TIME                ; set delay time
                    bsr       VAR_DELAY           ; sub for 0.1ms delay

;*** Send Init Command

                    lda       #FUNCSET            ; LCD init command
                    sta       LCD_DATA
                    bset      E,LCD_CTRL          ; clock in data
                    bclr      E,LCD_CTRL

;*** 100us warten

                    lda       #1
                    sta       TIME                ; set delay time
                    bsr       VAR_DELAY           ; sub for 0.1ms delay

;*** Send Init Command

                    lda       #FUNCSET            ; LCD init command
                    jsr       LCD_WRITE           ; write data to LCD

;*** Send Function Set Command
;*** 8 bit bus, 2 rows, 5x7 dots

                    lda       #FUNCSET            ; function set command
                    jsr       LCD_WRITE           ; write data to LCD

;*** Send Display Ctrl Command

;*** display on, cursor off, no blinking

                    lda       #DSPON              ; display ctrl command
                    jsr       LCD_WRITE           ; write data to LCD

;*** Send Clear Display Command

;*** clear display, cursor addr=0

                    bsr       LCD_clear

;*** Send Entry Mode Command

;*** increment, no display shift

                    lda       #$06                ; entry mode command
                    jsr       LCD_ADDR            ; write data to LCD

;*** SEND MESSAGES

;*** Set the address, send data

                    jsr       MESSAGE1            ; send Message1
                    jsr       MESSAGE2            ; send Message2
                    rts

;*******************************************************************************
; LCD_clear
;
; L?scht das LCD
;
;*******************************************************************************

LCD_clear
                    lda       #CLRDISP            ; clear display command
                    jsr       LCD_ADDR            ; write data to LCD
                    lda       #16
                    sta       TIME                ; set delay time for 1.6ms
                    bsr       VAR_DELAY           ; sub for 0.1ms delay
                    ldx       #0
                    lda       #' '
LCD_clear1
                    sta       screen,x            ; und den screen buffer
                    incx
                    cpx       #$20                ; mit leerzeichen f?llen
                    bne       LCD_clear1
                    rts

;*******************************************************************************
; LCD_home
;
; Cursor Home
;
;*******************************************************************************

LCD_home
                    lda       #CURHOME            ; clear display command
                    jsr       LCD_ADDR            ; write data to LCD
                    clr       row                 ; cursor Position merken
                    clr       col
                    lda       #16
                    sta       TIME                ; set delay time for 1.6ms
                    bsr       VAR_DELAY           ; sub for 0.1ms delay
                    rts

;**************************************************************************
; LCD_scroll                                                             *
;                                                                        *
; Einze zeile scrollen                                                   *
;                                                                        *
;**************************************************************************

LCD_scroll
                    clrx                          ; x l?schen
lcd_scr1
                    lda       screen+$10,x        ; untere Zeile laden
                    sta       screen,x            ; in obere speichern
                    lda       #' '                ; Blanks in untere Zeile schreiben
                    sta       screen+$10,x
                    incx
                    cpx       #$10
                    bne       lcd_scr1
                    bsr       write_scr           ; und ausgeben
                    lda       #row2adr
                    bsr       LCD_ADDR
                    mov       #0,col
                    rts

;**************************************************************************
; LCD_clreol                                                             *
;                                                                        *
; Bis zum ende der Zeile l?schen                                         *
;                                                                        *
;**************************************************************************

LCD_clreol

                    lda       row                 ; Zeilenz?hler laden
                    bne       LCD_clreol1         ; zeile 1 ?
                    lda       #row1adr            ; sonst adresse von Zeile 0 laden
                    bra       LCD_clreol2         ; weiter

LCD_clreol1
                    lda       #row2adr            ; adresse von Zeile 1 laden

LCD_clreol2
                    add       col                 ; Spalte aufaddieren
                    bsr       LCD_ADDR            ; adresse setzen
                    ldx       col                 ; spaltenposition des cursors laden
                    lda       row
                    bne       LCD_clreol4         ; zeile 1 dann weiter
LCD_clreol3
                    lda       #' '                ; leerzeichen laden
                    bsr       LCD_WRITE           ; und ausgeben
                    incx                          ; z?hler eh?hen
                    cpx       #$10                ; bis zum ende der zeile
                    bne       LCD_clreol3
                    lda       #row1adr            ; Adresse Zeile 0 laden
                    add       col                 ; Spalte addieren
                    bsr       LCD_ADDR            ; adresse setzen
                    bra       LCD_clreol5         ; und weiter

LCD_clreol4
                    lda       #' '                ; leerzeichen laden
                    bsr       LCD_WRITE           ; und ausgeben
                    incx                          ; z?hler eh?hen
                    cpx       #$10                ; bis zum ende der zeile
                    bne       LCD_clreol4
                    lda       #row2adr            ; Adresse Zeile 1 laden
                    add       col                 ; Spalte addieren
                    bsr       LCD_ADDR            ; adresse setzen

LCD_clreol5

                    ldx       col                 ; Zeile Laden
                    lda       row                 ; spalte in x laden
                    bne       LCD_clreol7         ; Zeile 1 dann weiter

LCD_clreol6
                    lda       #' '                ; Leerzeichen in akku
                    sta       screen,x            ; und in screenbuffer schreiben
                    incx                          ; x erh?hen
                    cpx       #$10                ; bis zum ende der Zeile
                    bne       LCD_clreol6
                    bra       LCD_clreol9         ; und raus

LCD_clreol7
                    aix       #$10                ; $10 f?r zweite Zeile dazu
LCD_clreol8
                    lda       #' '                ; Lerrzeichen in Akku
                    sta       screen,x            ; Puffer f?llen
                    incx                          ; z?hler eh?hen
                    cpx       #$20                ; zeile zuende ?
                    bne       LCD_clreol8

LCD_clreol9

                    rts


;**************************************************************************
; LCD_WRITE                                                              *
;                                                                        *
; Schreibt Zeichen im Akku auf das LCD                                   *
;                                                                        *
;**************************************************************************

LCD_WRITE
                    sta       LCD_DATA            ; auf Datenport ausgeben
                    bset      E,LCD_CTRL          ; clock in data
                    bclr      E,LCD_CTRL
                    lda       #30                 ; 2 40us delay f?r LCD
LCD_W1
                    deca                          ; 3
                    bne       LCD_W1              ; 3
                    rts



;**************************************************************************
; LCD_ADDR                                                               *
;                                                                        *
; Setzt die LCD Adresse auf den Wert des Akkus                           *
;                                                                        *
;**************************************************************************

LCD_ADDR            bclr      RS,LCD_CTRL         ; LCD in command mode
                    sta       LCD_DATA            ; auf datenport ausgeben
                    bset      E,LCD_CTRL          ; clock in data
                    bclr      E,LCD_CTRL
                    lda       #30                 ; 2 40us delay
LCD_ADDR1
                    deca                          ; 3
                    bne       LCD_ADDR1           ; 3
                    bset      RS,LCD_CTRL         ; LCD in data mode
                    rts



;**************************************************************************
; write_scr                                                              *
;                                                                        *
; gibt den inhalt von screen auf dem Display aus                         *
;**************************************************************************

write_scr
                    lda       #$80                ; addr = $80 Zeile0 Spalte0
                    bsr       LCD_ADDR            ; sende addr to LCD
                    clrx
write_scr1
                    lda       screen,X            ; zeichen aus puffer laden
                    bsr       LCD_WRITE           ; write data to LCD
                    incx
                    cpx       #$10
                    bne       write_scr1          ; obere Zeile
                    lda       #$C0                ; addr = $C0 Zeile1 Spalte0
                    bsr       LCD_ADDR            ; send addr to LCD
write_scr2
                    lda       screen,X            ; zeichen aus puffer laden
                    bsr       LCD_WRITE           ; write data to LCD
                    incx
                    cpx       #$20
                    bne       write_scr2          ; untere Zeile
                    rts



;**************************************************************************
; MESSAGE1 und MESSAGE2 geben dir Starnachrichten aus                    *
;                                                                        *
;**************************************************************************

MESSAGE1            lda       #$84                ; addr = $04 Zeile1 Spalte4
                    bsr       LCD_ADDR            ; send addr to LCD
                    clrx
L3                  lda       MSG1,X              ; load AccA w/char from msg
                    beq       OUTMSG1             ; end of msg?
                    bsr       LCD_WRITE           ; write data to LCD
                    incx
                    bra       L3                  ; loop to finish msg

OUTMSG1             rts



MESSAGE2            lda       #$C0                ; addr = $C0 Zeile2 Spalte0
                    bsr       LCD_ADDR            ; send addr to LCD
                    clrx
L5                  lda       MSG2,X              ; load AccA w/char from msg
                    beq       OUTMSG2             ; end of msg?
                    bsr       LCD_WRITE           ; write data to LCD
                    incx
                    bra       L5                  ; loop to finish msg

OUTMSG2             rts

;**************************************************************************
; Ende der LCD Routinen                                                  *
;**************************************************************************

;**************************************************************************
; raminit                                                                *
;                                                                        *
; initialisiert den Ram Speicher                                         *
;                                                                        *
;**************************************************************************

raminit
                    clr       TIME
                    clr       row
                    clr       col
                    clr       inptr
                    clr       outptr
                    clr       parm1
                    clr       parm2
                    ldx       #0
                    lda       #0
raminit1
                    sta       data,x
                    incx
                    cpx       #$20
                    bne       raminit1
                    ldx       #0
                    lda       #' '
raminit2
                    sta       screen,x
                    incx
                    cpx       #$20
                    bne       raminit2
                    rts

;**************************************************************************
; getchar                                                                *
;                                                                        *
; holt das n?chste Zeichen aus dem Puffer und gibt es im akku zur?ck     *
;                                                                        *
;**************************************************************************

getchar

                    pshx                          ; x-reg sichern
getch1
                    ldx       outptr              ; Ausgabezeiger im Empfangspuffer
                    cpx       inptr               ; Mit eingabezeiger vergleichen
                    beq       getch1              ; beide gleich dann ist nix da
                    lda       data,x              ; sonst in akku laden
                    incx                          ; index erh?hen
                    stx       outptr              ; und ausgabezeiger speichern
                    cpx       #20                 ; ende des puffers ?
                    bne       getchend            ; nein dann raus
                    clr       outptr              ; sonst zeiger auf Anfang des Puffers setzen
getchend
                    pulx                          ; x-reg zur?ckholen
                    rts                           ; und zur?ck

;**************************************************************************
; vt_command                                                             *
;                                                                        *
; vt100 Kommandos bearbeiten                                             *
;                                                                        *
;                                                                        *
;                                                                        *
;  force Cursor Position ist noch etwas im argen                         *
;  m??te dringend ausgelagert werden in eigene subroutine                *
;  und etwas besser strukturieren                                        *
;                                                                        *
;**************************************************************************

vt_command
                    bsr       getchar             ; Zeichen nach ESC holen
                    cmp       #'c'                ; Reset Device ?
                    bne       vt_comm_1           ; sonst weiter
                    jsr       LCD_init            ; zur?cksetzen
                    bsr       raminit             ; Ram initialisieren
                    jsr       LCD_home            ; und cursor setzen
                    jmp       vt_comm_end         ; und raus

vt_comm_1
                    cmp       #'M'                ; Scroll Up ?
                    bne       vt_comm2            ; sonst weiter
                    jsr       LCD_scroll          ; Scrollen
                    jmp       vt_comm_end         ; und raus

vt_comm2
                    cmp       #'['                ; Alles weitere f?ngt mit eckiger klammer an
                    bne       vt_err              ; sonst raus weil fehler
                    bsr       getchar             ; n?chstes Zeichen holen
                    cmp       #'H'                ; Cursor Home ?
                    bne       vt_comm3            ; sonst weiter
                    jsr       LCD_home            ; Cursor Home
vt_err              jmp       vt_comm_end         ; und raus

vt_comm3
                    cmp       #'K'                ; Clear to end of Line
                    bne       vt_comm4            ; sonst weiter
                    jsr       LCD_clreol          ; zeile bis zum ende l?schen
                    jmp       vt_comm_end         ; und raus

vt_comm4
                    cmp       #'2'                ; hier gibt es mehrere m?glichkeiten
                    bne       vt_comm6
                    sta       parm1               ; erstmal speichern, k?nnte parameter sein
                    bsr       getchar             ; n?chstes Zeichen
                    cmp       #'K'                ; K ist erase line
                    bne       vt_comm5            ; sonst weiter probieren
                    clr       col                 ; spalte auf 0 setzen
                    jsr       LCD_clreol          ; und bis zum ende der Zeile l?schen
                    bra       vt_comm_end         ; und raus

vt_comm5
                    cmp       #'J'                ; J ist Clear Screen
                    bne       vt_comm6            ; sonst weiter testen
                    jsr       LCD_clear
                    bra       vt_comm_end

vt_comm6
                    cmp       #'1'                ; Force Cursor position
                    bne       vt_comm7            ; hier nur mit Zeile 0 und 1
                    sub       #30                 ; umwandlung in bin?r
                    sta       parm1               ; speichern weil noch ein wert kommt
                    bra       force

vt_comm7
                    cmp       #'0'
                    bne       vt_comm10
                    sub       #30                 ; umwandlung in bin?r
                    sta       parm1               ; und speichern
force
                    bsr       getchar             ; Zeile gespeichert n?chstes Zeichen
                    cmp       #';'                ; Trennzeichen
                    bne       vt_comm10
                    bsr       getchar             ; n?chstes Zeichen
                    cmp       #'2'                ; max 16 Zeichen pro Zeile daher erstes Zeichen kleiner 2
                    bhi       vt_comm8            ; oder kleiner 10
                    sub       #30                 ; bin?r machen
                    nsa                           ; mal 16
                    sta       parm2               ; und speichern
                    jsr       getchar
vt_comm8

                    cmp       #'f'                ; ende erstes Zeichen ist schon spalte
                    bne       vt_comm9            ; Spalte ist zweistellig
                    lda       parm2               ; wert wieder durch 16 teilen
                    nsa
                    sta       parm2               ; und speichern
                    lda       parm1               ; zeile holen
                    sta       row                 ; und sichern
                    clc                           ; carry l?schen zum nullen schieben
                    rora                          ; Schieben bis an richtiger Position
                    rora
                    rora
                    add       #$80                ; $80 dazu ergibt 80 oder C0
                    add       parm2               ; Spalte laden aufaddieren
                    jsr       LCD_ADDR            ; Adresse setzen
                    lda       parm2               ; spalte in Cursorposition merken
                    sta       col
                    bra       vt_comm_end         ; und schluss

vt_comm9
                    cmp       #'9'                ; Zweites Zeichen darf nicht gr??er 9 sein
                    bhi       vt_comm10           ; sonst raus wegen fehler
                    sub       $30                 ; bin?r machen
                    add       parm2               ; hinzuaddieren
                    cmp       #$0A                ; gr??er 10 ?
                    blo       force2
                    sub       #$06                ; dann 6 abziehen weil ober die 1 mit 16 multipliziert wurde

force2
                    sta       parm2               ; und sichern
                    lda       parm1               ; zeile holen
                    sta       row                 ; und cursorposition sichern
                    clc                           ; carry l?schen zum nullen schieben
                    rora                          ; Schieben bis an richtiger Position
                    rora
                    rora
                    add       #$80                ; $80 dazu ergibt 80 oder C0
                    add       parm2               ; Spalte laden aufaddieren
                    jsr       LCD_ADDR            ; adresse setzen
                    lda       parm2               ; und splate f?r cursorposition setzen
                    sta       col
                    jsr       getchar             ; sollte f sein
                    !bra      vt_comm_end
vt_comm10
; hier k?nnte eine fehllerbehandlung stattfinden
vt_comm_end
                    rts

;**************************************************************************
; Keyboard Interrupt service Routine                                     *
;                                                                        *
; Wird bei fallender Flanke auf PTA0 aufgerufen                          *
; Ruft GetByte auf und schreibt empfangene Daten in den Empfangspuffer   *
; ca 20 Takte bis Getbyte beginnt. Gebtbyte geht auf die Mitte des Bits  *
; Dadurch Verschiebung um ca 20 Takte nach hinten. bei 9600 Baud ist     *
; ein bit ca 330 Takte sollte kein Problem sein                          *
; Stopbit wird beim Empfang ignoriert, deshalb nach empfang              *
; ca 300 Takte zeit bevor n?chstes Zeichen kommen kann.                  *
;**************************************************************************
KbdIsr

                    pshh                          ; 2 save H-reg
                    sei                           ; 2 keine weiteren Interrupts zulassen
                    mov       #%00000010,KBIER    ; 4 KB-Int disablen
                    bclr      PTA0,PTA            ; 4initialize PTA0 for serial comms
                    jsr       GetByte             ; RS232 Byte empfangen
                    ldx       inptr               ; Zeiger f?r Empfangspuffer laden
                    sta       data,x              ; und Zeichen sichern
                    incx                          ; Zeiger erh?hen
                    cpx       #$20                ; ende des Puffers ?
                    bne       kbd1                ; nein dann weiter
                    clrx                          ; sonst auf Anfang setzen
kbd1
                    stx       inptr               ; und speichern
                    mov       #%00000100,KBSCR    ; ACK schreiben um alles zu clearen
                    mov       #%00000001,KBIER    ; ints auf PTA0 wieder zulassen
                    cli                           ; ints wieder erlauben
                    pulh                          ; H-Reg zur?ckholen
                    rti

;*** MESSAGE STORAGE ******************************************************

                    org       MSG_STORAGE

MSG1                db        'NITRON'
                    db        0
MSG2                db        'LCD Terminal'
                    db        0


;*** Belegung der Vektoren ************************************************

                    org       AltRESET
                    jmp       $EE00

                    org       AltKBD
                    jmp       KbdIsr
