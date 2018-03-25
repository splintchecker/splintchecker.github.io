###
### LCLint db sample
###
### Second iteration: weakchecks
###

LCLINTFLAGS = -weak
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) original > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy
