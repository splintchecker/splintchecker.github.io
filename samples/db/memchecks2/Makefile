###
### LCLint db sample
###
### Sixth iteration: memchecks2
###

LCLINTFLAGS = -allimponly -macrovarprefixexclude
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) memchecks1 > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	cp erc.c.html ../memchecks1/erc-next.c.html
	$(MAKE) tidy

