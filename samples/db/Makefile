###
### Makefile
###
### Top-level Makefile for making all iterations.
###

all:
	cd original; $(MAKE) all
	cd weakchecks; $(MAKE) all
	cd useiters; $(MAKE) all
	cd standardchecks; $(MAKE) all
	cd memchecks1; $(MAKE) all
	cd memchecks2; $(MAKE) all
	cd memchecks3; $(MAKE) all
	cd allmacros; $(MAKE) all
	cd checkchecks1; $(MAKE) all
	cd checkchecks2; $(MAKE) all
	cd namechecks; $(MAKE) all
	cd strictchecks; $(MAKE) all
	cd final; $(MAKE) all

runners:
	cd original; $(MAKE) runner
	cd weakchecks; $(MAKE) runner
	cd useiters; $(MAKE) runner
	cd standardchecks; $(MAKE) runner
	cd memchecks1; $(MAKE) runner
	cd memchecks2; $(MAKE) runner
	cd memchecks3; $(MAKE) runner
	cd allmacros; $(MAKE) runner
	cd checkchecks1; $(MAKE) runner
	cd checkchecks2; $(MAKE) runner
	cd namechecks; $(MAKE) runner
	cd strictchecks; $(MAKE) runner
	cd final; $(MAKE) runner

tags:
	etags -d -t */*.c */*.h */*.lcl

htmltags:
	etags *.html */*.html */*/*.html
