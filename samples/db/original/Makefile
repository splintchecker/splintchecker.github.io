###
### LCLint db sample
###
### First iteration: original
###

### 
### lsl is required to run this iteration.  If lsl is not installed,
### skip to the second iteration.
###

LCLINTFLAGS = -weak +showscan +stats

include ../Makefile.constants

###
### This version uses stdio.lcl.
### In other iterations, the standard <stdio> import is used.
###

LCSFILES = $(LCSFILES) stdio.lcs 
dbase.lcs: stdio.lcs

all: 
	$(MAKE) clean
	$(MAKE) drive
	drive >& drive.out
	$(DIFF) drive.out drive.expect
	$(MAKE) check >& lclint.out
	-$(DIFF) lclint.out lclint.expect
	$(RUNTOHTML) lclint.out > lclint.out.html
	$(CTOHTML) *.c *.h *.lh *.lcl *.lsl
	$(MAKE) tidy






