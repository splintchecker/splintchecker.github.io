###
### LCLint db sample
###
### Fourth iteration: standardchecks
###

LCLINTFLAGS = -memchecks +showsummary -macrovarprefixexclude
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) useiters > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.expect drive.out 
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.expect lclint.out
	$(RUNTOHTML) lclint.out > lclint.out.html
	setenv LCLINTFLAGS "-weak -macrovarprefixexclude" ; \
	   $(MAKE) -e check >& lclint-weak.out
	-$(DIFF) lclint-weak.out lclint-weak.expect
	$(RUNTOHTML) lclint-weak.out > lclint-weak.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy
