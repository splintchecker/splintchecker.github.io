###
### LCLint db sample
###
### Twelth iteration: strictchecks
###

### Naming convention flags are now in .lclintrc

LCLINTFLAGS = +strict +showsummary +repeatunrecog

include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) namechecks > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	setenv LCLINTFLAGS "+checks"; $(MAKE) -e check >& lclint-checks.out
	-$(DIFF) lclint-checks.out lclint-checks.expect
	$(RUNTOHTML) lclint-checks.out > lclint-checks.out.html
	setenv LCLINTFLAGS "+checks +allblock +allempty"; $(MAKE) -e check >& lclint-blocks.out
	-$(DIFF) lclint-blocks.out lclint-blocks.expect
	$(RUNTOHTML) lclint-blocks.out > lclint-blocks.out.html
	setenv LCLINTFLAGS "+checks -allimponly +allmacros +exportany"; $(MAKE) -e check >& lclint-exports.out
	-$(DIFF) lclint-exports.out lclint-exports.expect
	$(RUNTOHTML) lclint-exports.out > lclint-exports.out.html
	setenv LCLINTFLAGS "+checks +moduncon +modunconnomods"; $(MAKE) -e check >& lclint-moduncon.out
	-$(DIFF) lclint-moduncon.out lclint-moduncon.expect
	$(RUNTOHTML) lclint-moduncon.out > lclint-moduncon.out.html
	setenv LCLINTFLAGS "+checks +exportlocal"; $(MAKE) -e check >& lclint-exportlocal.out
	-$(DIFF) lclint-exportlocal.out lclint-exportlocal.expect
	$(RUNTOHTML) lclint-exportlocal.out > lclint-exportlocal.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	cp bool.h.html ../namechecks/bool-next.h.tml
	$(MAKE) tidy
