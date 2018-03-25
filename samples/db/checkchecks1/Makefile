###
### LCLint db sample
###
### Ninth iteration: checkchecks
###

LCLINTFLAGS = +checks -allimponly +allmacros +showsummary
include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) allmacros > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	setenv LCLINTFLAGS "-allimponly +allmacros +showscan +stats"; \
            $(MAKE) -e check >& lclint-standard.out
	-$(DIFF) lclint-standard.out lclint-standard.expect
	$(RUNTOHTML) lclint-standard.out > lclint-standard.out.html
	setenv LCLINTFLAGS "-enumint -type -allimponly +allmacros +showscan +stats"; \
            $(MAKE) -e check >& lclint-enumindex.out
	-$(DIFF) lclint-enumindex.out lclint-enumindex.expect
	$(RUNTOHTML) lclint-enumindex.out > lclint-enumindex.out.html
	setenv LCLINTFLAGS "-enumint +enumindex -allimponly +allmacros +showscan +stats"; \
            $(MAKE) -e check >& lclint-enumtype.out
	-$(DIFF) lclint-enumtype.out lclint-enumtype.expect
	$(RUNTOHTML) lclint-enumtype.out > lclint-enumtype.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy
