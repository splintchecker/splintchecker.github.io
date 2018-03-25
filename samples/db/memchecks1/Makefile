###
### LCLint db sample
###
### Fifth iteration: memchecks1
###

LCLINTFLAGS = -allimponly -macrovarprefixexclude
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) standardchecks > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	$(RUNTOHTML) lclint.out > lclint.out.html
	-$(DIFF) lclint.out lclint.expect
	setenv LCLINTFLAGS "+allimponly -macrovarprefixexclude"; $(MAKE) -e check >& lclint-imp.out
	-$(DIFF) lclint-imp.out lclint-imp.expect
	$(RUNTOHTML) lclint-imp.out > lclint-imp.out.html
	setenv LCLINTFLAGS "-memchecks -macrovarprefixexclude"; $(MAKE) -e check >& lclint-nomemchecks.out
	-$(DIFF) lclint-nomemchecks.out lclint-nomemchecks.expect
	$(RUNTOHTML) lclint-nomemchecks.out > lclint-nomemchecks.out.html

	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy
