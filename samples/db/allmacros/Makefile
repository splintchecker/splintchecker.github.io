###
### LCLint db sample
###
### Eigth iteration: allmacros
###

LCLINTFLAGS = -allimponly +allmacros
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) memchecks3 > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	setenv LCLINTFLAGS "-allimponly -macrovarprefixexclude"; $(MAKE) -e check >& lclint-nomacros.out
	-$(DIFF) lclint-nomacros.out lclint-nomacros.expect
	$(RUNTOHTML) lclint-nomacros.out > lclint-nomacros.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy
