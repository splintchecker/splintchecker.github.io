###
### LCLint db sample
###
### Fourteenth iteration: final
###

LCLINTFLAGS = +strict +showsummary -exportconstant -exportlocal +strictlib
include ../Makefile.constants

MODULES = $(BASEMODULES) bool.lcl check.lcl

all: 
	$(MAKE) clean
	$(DIFFDIR) strictlib > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy



