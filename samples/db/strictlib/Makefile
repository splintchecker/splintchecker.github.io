###
### LCLint db sample
###
### Thirteenth iteration: strictlib
###

LCLINTFLAGS = +strict +showsummary -exportconstant -exportlocal +strictlib +whichlib

include ../Makefile.constants

MODULES = $(BASEMODULES) bool.lcl check.lcl

all: 
	$(MAKE) clean
	$(DIFFDIR) strictchecks > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	setenv LCLINTFLAGS "+strict -exportconstant -exportlocal"; $(MAKE) -e check >& lclint-strict.out
	-$(DIFF) lclint-strict.out lclint-strict.expect
	$(RUNTOHTML) lclint-strict.out > lclint-strict.out.html
	setenv LCLINTFLAGS "+strict -exportconstant -exportlocal +strictlib -mods -globs"; $(MAKE) -e check >& lclint-retval.out
	-$(DIFF) lclint-retval.out lclint-retval.expect
	$(RUNTOHTML) lclint-retval.out > lclint-retval.out.html
	setenv LCLINTFLAGS "+strict -exportconstant -exportlocal +strictlib -retval"; $(MAKE) -e check >& lclint-io.out
	-$(DIFF) lclint-io.out lclint-io.expect
	$(RUNTOHTML) lclint-io.out > lclint-io.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	cp eref.c.html ../strictchecks/eref-next.c.html
	cp erc.c.html ../strictchecks/erc-next.c.html
	cp bool.lcl.html ../strictchecks/bool-next.lcl.html
	cp check.lcl.html ../strictchecks/check-next.lcl.html
	cp employee.lcl.html ../strictchecks/employee-next.lcl.html
	cp eref.lcl.html ../strictchecks/eref-next.lcl.html
	cp empset.lcl.html ../strictchecks/empset-next.lcl.html
	cp empset.c.html ../strictchecks/empset-next.c.html
	cp dbase.lcl.html ../strictchecks/dbase-next.lcl.html
	cp dbase.c.html ../strictchecks/dbase-next.c.html
	cp drive.lcl.html ../strictchecks/drive-next.lcl.html
	$(MAKE) tidy



