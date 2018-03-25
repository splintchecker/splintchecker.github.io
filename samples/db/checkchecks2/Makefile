###
### LCLint db sample
###
### Tenth iteration: checkchecks2
###

LCLINTFLAGS = +checks -allimponly +allmacros +showsummary 
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) checkchecks1 > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	cp dbase.c.html ../checkchecks1/dbase-next.c.html
	$(MAKE) tidy
