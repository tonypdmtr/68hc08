################################################################################
# [Borland/Embarcadero v5.41] Makefile for TBOOT (Tiny Bootloader)
# Copyright (c) by Tony G. Papadimitriou <tonyp@acm.org>
################################################################################

HELP:
 @echo "*********************************************************
 @echo "* Targets: ALL GB60
 @echo "*          QG8 QE8 QE32 QE128 DZ32 DZ60 FL16 SH8 AC32 AC96
 @echo "*********************************************************
 @echo "* Defines: DEBUG
 @echo "*********************************************************

ASM8 = asm8.exe
OPTS = -s+ -l+ -m+ -e+ -ls -lss -exp+

!ifdef DEBUG
DEBUG = -dDEBUG -dMAP
!else
PRIVATE = -dPRIVATE
!endif

OPTS = $(OPTS) $(DEBUG) $(PRIVATE)

################################################################################

all  : qg8 qe8 qe32 qe128 dz32 dz60 fl16 sh8 ac32 ac96
gb60 : tboot_gb60.s
qg8  : tboot_qg8.s
qe8  : tboot_qe8.s
qe32 : tboot_qe32.s
qe128: tboot_qe128.s
dz32 : tboot_dz32.s
dz60 : tboot_dz60.s
fl16 : tboot_fl16.s
sh8  : tboot_sh8.s
ac32 : tboot_ac32.s
ac96 : tboot_ac96.s

################################################################################

tboot_qg8.s: qg8.inc
 $(ASM8) tboot $(OPTS) -dQG8
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_qe8.s: qe8.inc
 $(ASM8) tboot $(OPTS) -dQE8
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_qe32.s: qe32.inc
 $(ASM8) tboot $(OPTS) -dQE32
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_ac32.s: ac32.inc
 $(ASM8) tboot $(OPTS) -dAC32
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_ac96.s: ac96.inc
 $(ASM8) tboot $(OPTS) -dAC96
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_fl16.s: fl16.inc
 $(ASM8) tboot $(OPTS) -dFL16 -dDISABLE_SURE
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_qe128.s: qe128.inc
 $(ASM8) tboot $(OPTS) -dQE128
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_gb60.s: gb60.inc
 $(ASM8) tboot $(OPTS) -dGB60
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_dz32.s: dz32.inc
 $(ASM8) tboot $(OPTS) -dDZ32
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_dz60.s: dz60.inc
 $(ASM8) tboot $(OPTS) -dDZ60
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################

tboot_sh8.s: sh8.inc
 $(ASM8) tboot $(OPTS) -dSH8
 @copy tboot.s19 $@
 @copy tboot.exp $*.exp

################################################################################
