###
### LCLint db sample
###
### Third iteration: useiters
###

LCLINTFLAGS = -weak +showscan +stats -macrovarprefixexclude
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) weakchecks > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	cp bool.h.html ../weakchecks/bool-next.h.html
	cp drive.c.html ../weakchecks/drive-next.c.html
	$(MAKE) tidy
