###
### LCLint db sample
###
### Seventh iteration: memchecks3
###

LCLINTFLAGS = -allimponly -macrovarprefixexclude
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) memchecks2 > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	cp empset.lcl ../memchecks2/empset-next.lcl
	cp ereftab.lcl ../memchecks2/ereftab-next.lcl
	$(MAKE) tidy
