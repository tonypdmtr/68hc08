################################################################################
# AWK program to convert CW source to ASM8 syntax                <tonyp@acm.org>
################################################################################
# 2010.09.24 Original
# 2014.04.22
# 2016.03.01 Corrected RAM1
# 2017.01.26 Added conversion of plain IF directive
################################################################################

BEGIN {
  outdir = ".\\"
  out_ext = ".inc"
  workfile = "\n"
  filename = ""
  }

################################################################################

function output()
{
  if (workfile != FILENAME) {
    start = 1
    workfile = FILENAME
    filename = FILENAME
    match(filename,/\\.+\\/)
    if (RLENGTH) filename = substr(filename,RLENGTH+1,length(filename)-RLENGTH)
    filename = outdir filename out_ext
  }

  if (start) {
    print ";[PROCESSED BY CW.AWK]"                > filename
    #print "                    #ListOff"          > filename
    #print "                    #Uses     cw.inc"  >> filename
    #print "                    #ListOn"           >> filename
    #print ""                                      >> filename
    start = 0
  }
  print                                           >> filename
}

################################################################################

function pad(s,max)
{
  if (max < 1) return s
  while (length(s) < max-1)
    s = (s " ")
  return (s " ")
}

################################################################################

# Skip lines we added in previous runs

/                    #ListOff/          { if (FNR == 1) next }
/                    #Include  cw.inc/  { if (FNR == 2) next }
/                    #ListOn/           { if (FNR == 3) next }
/^$/                                    { if (FNR == 4) next }

# Truncate lines longer than 255
{ if (length($0) > 254) $0 = substr($0,1,254) }

# Simply output pure comments
/^[[:space:]]*[;|\*]/ { output(); next }

# If inside a macro, convert parameters to ASM8 format
tolower($2)=="macro",tolower($1)=="endm" {
  sub(/\\[0-9]/,"~&~")
}

# Get rid of trailing label colons
/^[a-zA-Z?._][a-zA-Z?._0-9@]*:/ {
  $1 = substr($1,1,length($1)-1)
}

# Convert INCLUDE/IF/IFDEF/IFNDEF/ELSE/ENDIF/IFEQ/IFNE to ASM8's syntax

{sub(/[^#][Ii][Nn][Cc][Ll][Uu][Dd][Ee]/,"#Include")}
{sub(/[^#][Ii][Ff][Dd][Ee][Ff]/,"#ifdef")}
{sub(/[^#][Ii][Ff][Nn][Dd][Ee][Ff]/,"#ifndef")}
{sub(/[^#][Ee][Ll][Ss][Ee]/,"#else")}
{sub(/[^#][Ee][Nn][Dd][Ii][Ff]/,"#endif")}
{sub(/[^#][Ii][Ff][Ee][Qq]/,"#ifz")}
{sub(/[^#][Ii][Ff][Nn][Ee]/,"#ifnz")}
{sub(/[[:space:]][Ii][Ff][[:space:]]/,"#if ")}
{sub(/ROMStart/,"ROM")}
{sub(/ROMEnd/,"ROM_END")}
{sub(/ROM1Start/,"XROM")}
{sub(/ROM1End/,"XROM_END")}
{sub(/Z_RAMStart/,"RAM")}
{sub(/Z_RAMEnd/,"RAM_END")}
{sub(/RAMStart/,"XRAM")}
{sub(/RAMEnd/,"XRAM_END")}
{sub(/RAM1Start/,"RAM1")}
{sub(/RAM1End/,"RAM1_END")}

# Skip deprecated code stubs for error generation
/This_symb_has_been_depreciated/ { next }

# Simply output directives
/^[[:space:]]*[\#\$].+/ { output(); next }

# Just output everything else, as is

{
 $0 = pad($1,20) pad($2,10) pad($3,20) $4 " " $5 " " $6 " " $7 " " $8 " " $9 " " $10 " " $11 " " $12 " " $13 " " $14 " " $15 " " $16 " " $17 " " $18 " " $19 " " $20
 output()
}
