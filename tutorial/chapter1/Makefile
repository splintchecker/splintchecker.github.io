### Makefile for Chapter 1 of tutorial

.SUFFIXES: .c .splint .exe .output

C_FILES=HelloWorld.c IncludeExperiment.c
SPLINT_FILES=HelloWorld.splint
EXE_FILES=HelloWorld.exe
OUTPUT_FILES=HelloWorld.output

include ../Makefile.constants

all:
	$(MAKE) $(SPLINT_FILES)
	$(MAKE) $(EXE_FILES)
	$(MAKE) $(OUTPUT_FILES)

.c.splint:
	$(RUNSPLINT) $(SPLINTFLAGS) $< > $@

.c.exe:
	$(GCC) $< -o $@

.exe.output:
	$< > $@

compile_check: $(C_FILES)
	$(COMPILECHECK) $(PWD)
