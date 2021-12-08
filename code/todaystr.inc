;*******************************************************************************
;* Include   : TODAYSTR.INC
;* Programmer: Tony Papadimitriou <tonyp@acm.org>
;* Purpose   : Macros to create a string with today's date in specified format
;* Language  : Motorola/Freescale/NXP HC08/9S08 Assembly Language (aspisys.com/ASM8)
;* Status    : FREEWARE Copyright (c) 2022 by Tony Papadimitriou <tonyp@acm.org>
;* Note(s)   : Use: #Uses todaystr.inc
;*******************************************************************************

Date                macro     DateFormat
                    mreq      1:DateFormat
;;------------------------------------------------------------------------------
          #ifparm ~1~ = yyyymmdd
                    fcc       '{:year}.{:month(z)}.{:date(z)}'
          #else ifparm ~1~ = ddmmyyyy
                    fcc       '{:date(z)}/{:month(z)}/{:year}'
          #else ifparm ~1~ = mmddyyyy
                    fcc       '{:month(z)}/{:date(z)}/{:year}'
          #else ifparm ~1~ = USA
                    @@DayName
                    fcc       ', '
                    @@MonthName
                    fcc       ' {:date}, {:year}'
          #else ifparm ~1~ = EU
                    @@DayName
                    fcc       ', {:date} '
                    @@MonthName
                    fcc       ' {:year}'
          #else
                    #Error    Missing Format code. Possible formats:
                    #Error    yyyymmdd = 'YYYY.MM.DD' Global
                    #Error    ddmmyyyy = 'DD/MM/YYYY' Europe
                    #Error    mmddyyyy = 'MM/DD/YYYY' USA
                    #Error    USA = 'Day, Month n, Year'
                    #Error    EU = 'Day, n Month Year'
          #endif
                    endm

;*******************************************************************************
; Form a constant string (FCC) with name of given month and optional max length

MonthName           macro     [MonthNumber][,MaxLength]
                    mset      0,January,February,March,April,May,June,July,August,September,October,November,December
                    mdef      1,:month
                    mdef      2,10
                    mset      0,~text','{~1~}~
                    fcc       \@~text.1.{~2~}~\@
                    endm

;*******************************************************************************
; Form a constant string (FCC) with the given YY,MM,DD

Today               macro     [YY,MM,DD]
                    mdef      1,:year
                    mdef      2,:month
                    mdef      3,:date
                    @@MonthName ~2~
                    fcc       \@ {~3~}, {~1~}\@
                    endm

;*******************************************************************************
; Get the day-of-week number (0=Sunday) for any YYYY,MM,DD date
; (In the latest version of the assembler you may use the built-in symbol :DOW
; for getting the assembly-time day-of-week)

GetDayOfWeek        macro     YYYY,MM,DD
                    mdef      1,:year
                    mdef      2,:month
                    mdef      3,:date

                    mset      2,{~2~-2}           ;dec(month, 2);
          #if ~2~ < 1                             ;if (month < 1) or (month > 10) then
                    mset      2,{~2~+12}          ;Inc(month, 12);
                    mset      1,{~1~-1}           ;Dec(year, 1)
          #endif
          #if ~2~ > 10
                    mset      2,{~2~+12}          ;Inc(month, 12);
                    mset      1,{~1~-1}           ;Dec(year, 1)
          #endif
                    mset      4,{~1~/100}
                    mset      1,{~1~\100}
          ; temp := (trunc((13 * month - 1) div 5) + day + yr +
          ;         (yr div 4) + (cent div 4) - cent - cent) mod 7;
                    mset      4,{~4~/4+{~1~/4+{13*~2~-1/5+~3~+~1~}}-~4~-~4~}\7
          #if ~4~ < 0                             ;if temp < 0 then Inc(temp, 7);
                    mset      4,~4~+7
          #endif
~label~             set       ~4~
                    endm                          ;GetDayOfWeek

;*******************************************************************************
; Form a constant string (FCC) with name of given day and optional max length

DayName             macro     [DayNumber][,MaxLength]
                    mset      0,Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday
                    mdef      1,:dow
                    mdef      2,10
                    mset      0,~text','{~1~+1}~
                    fcc       \@~text.1.{~2~}~\@
                    endm

;*******************************************************************************
                    #Exit
;*******************************************************************************
;                   Test some macro expansions
;*******************************************************************************

CRLF                macro
                    fcc       13,10
                    endm

                    org       *
                    @Date     yyyymmdd
                    @CRLF                         ;newline for easier viewing in binary
                    @Date     ddmmyyyy
                    @CRLF
                    @Date     mmddyyyy
                    @CRLF
                    @Date     usa
                    @CRLF
                    @Date     eu
                    @CRLF

                    @MonthName          :month
                    @CRLF
                    @MonthName :month,4
                    @CRLF

                    @Today
                    @CRLF
                    @Today    ,:month\12+1        ;one month from now
                    @CRLF

                    @DayName
                    @CRLF
                    @DayName  ,3
                    @CRLF
dow                 @GetDayOfWeek :year,:month,:date
                    @CRLF
                    @DayName  dow
                    @CRLF
                    @DayName  0
                    @CRLF
