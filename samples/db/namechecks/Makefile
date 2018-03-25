###
### LCLint db sample
###
### Tenth iteration: namechecks
###

LCLINTFLAGS = +checks -allimponly +allmacros +showsummary +czech

include ../Makefile.constants

all: 
	$(MAKE) clean
	$(DIFFDIR) checkchecks2 > diffs.html
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	setenv LCLINTFLAGS "+checks -allimponly +allmacros"; \
            $(MAKE) -e check >& lclint-checks.out
	$(RUNTOHTML) lclint-checks.out > lclint-checks.out.html
	-$(DIFF) lclint-checks.out lclint-checks.expect
	setenv LCLINTFLAGS "+checks -allimponly +allmacros +distinctexternalnames"; \
            $(MAKE) -e check >& lclint-external.out
	-$(DIFF) lclint-external.out lclint-external.expect
	$(RUNTOHTML) lclint-external.out > lclint-external.out.html
	setenv LCLINTFLAGS "+checks -allimponly +allmacros +distinctexternalnames -externalnamelength 12"; \
            $(MAKE) -e check >& lclint-externallen.out
	-$(DIFF) lclint-externallen.out lclint-externallen.expect
	$(RUNTOHTML) lclint-externallen.out > lclint-externallen.out.html
	setenv LCLINTFLAGS "+checks -allimponly +allmacros +distinctexternalnames -externalnamelength 14"; \
            $(MAKE) -e check >& lclint-externallen14.out
	-$(DIFF) lclint-externallen14.out lclint-externallen14.expect
	$(RUNTOHTML) lclint-externallen14.out > lclint-externallen14.out.html
	setenv LCLINTFLAGS "+checks -allimponly +allmacros +distinctexternalnames -externalnamelength 14 +distinctinternalnames +internalnamelookalike"; \
            $(MAKE) -e check >& lclint-internal.out
	-$(DIFF) lclint-internal.out lclint-internal.expect
	$(RUNTOHTML) lclint-internal.out > lclint-internal.out.html
	setenv LCLINTFLAGS "+checks -allimponly +allmacros +distinctexternalnames -externalnamelength 14 +distinctinternalnames +internalnamelookalike"; \
            $(MAKE) -e check >& lclint-internal.out
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy
