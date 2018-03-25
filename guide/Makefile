###
### This Makefile produces the figures included in the LCLint User's
### Guide.
###

.SUFFIXES: .out .expect .c .lcl .h .lh .diff
.PHONY: clean

RUNTOHTML = /u/evs/lclint/scripts/runtohtmls
GENHTML = /u/evs/lclint/scripts/genhtmls
CTOHTML = /u/evs/bin/ctohtmlplain
BASEDIR = /u/evs/perl/basedir
MAKERUNNER = /u/evs/lclint/scripts/makerunner

SHELL = /bin/csh 

DIFF = diff

all: fig2 fig3 fig4 fig5 fig6 fig7 fig8 fig9 fig10 fig11 fig12 fig13 \
     fig14 fig15 fig16 fig17 fig18 fig19 fig20 fig21 fig22 sumsquares

test:
	$(MAKE) >& all.out
	$(DIFF) all.out all.expect

fig1:
	@echo "Figure 1 is a picture"

fig2.html:
	$(CTOHTML) palindrome.c mstring.h bool.h
	echo "Figure 2.  ..."

fig2: palindrome.c mstring.h bool.h
	-lclint palindrome.c |& $(RUNTOHTML) > fig2-out
	presurround fig2-out

fig3: bool.c bool.h
	lclint bool.c +predboolptr |& $(RUNTOHTML) > fig3-out
	presurround fig3-out

fig4: modify.c
	lclint modify.c +checks |& $(RUNTOHTML) > fig4-out
	presurround fig4-out

fig5: globals.c
	lclint globals.c +checks |& $(RUNTOHTML) > fig5-out
	presurround fig5-out

fig6: only.c
	lclint only.c  |& $(RUNTOHTML) > fig6-out
	presurround fig6-out

fig7: stack.c
	lclint stack.c |& $(RUNTOHTML) > fig7-out
	presurround fig7-out

fig8: implicit.c
	@echo "No output for Figure 8"
	lclint implicit.c

fig9: rstring.c
	lclint rstring.c |& $(RUNTOHTML) > fig9-out
	presurround fig9-out

fig10: unique.c
	lclint unique.c |& $(RUNTOHTML) > fig10-out
	presurround fig10-out

fig11: returned.c
	lclint returned.c  |& $(RUNTOHTML) > fig11-out
	presurround fig11-out

fig12: exposure.c
	lclint exposure.c +checks |& $(RUNTOHTML) > fig12-out
	presurround fig12-out

fig13: usedef.c
	lclint usedef.c |& $(RUNTOHTML) > fig13-out
	presurround fig13-out

fig14: annotglobs.c
	lclint annotglobs.c |& $(RUNTOHTML) > fig14-out
	presurround fig14-out

fig15: null.c
	lclint null.c |& $(RUNTOHTML) > fig15-out
	presurround fig15-out

fig16: mstring.c
	lclint mstringnn.c  |& $(RUNTOHTML) > fig16-out
	presurround fig16-out

fig17: special.c
	@echo "Figure 1 is a picture"

fig18: names.c
	lclint names.c +distinctinternalnames +internalnamelookalike +ansireserved |& $(RUNTOHTML) > fig18-out
	presurround fig18-out

fig19: order.c
	lclint order.c +evalorderuncon |& $(RUNTOHTML) > fig19-out
	presurround fig19-out

fig20: loop.c
	lclint loop.c |& $(RUNTOHTML) > fig20-out
	presurround fig20-out

fig21: switch.c
	lclint switch.c |& $(RUNTOHTML) > fig20-out
	presurround fig21-out

fig22: noeffect.c
	lclint noeffect.c +noeffectuncon |& $(RUNTOHTML) > fig22-out
	presurround fig22-out

fig23: ignore.c
	lclint ignore.c |& $(RUNTOHTML) > fig23-out
	presurround fig23-out

clean: 
	-rm -f core a.out *.*~

