### Makefile for Chapter 2 of tutorial

.SUFFIXES: .c .splint .exe .output

C_FILES=Initialized.c Uninitialized.c InvalidDeclaration.c DivisionMistake.c\
 PrintCharacter.c PrintString.c
SPLINT_FILES=Uninitialized.splint DivisionMistake.splint
EXE_FILES=Initialized.exe
OUTPUT_FILES=Initialized.output

include ../Makefile.constants

all:  
	$(MAKE) $(SPLINT_FILES)
	$(MAKE) $(EXE_FILES)
	$(MAKE) $(OUTPUT_FILES)

.c.splint:  
	-$(RUNSPLINT) $(SPLINTFLAGS) $< > $@

.c.exe:
	$(GCC) $< -o $@

.exe.output:  
	$< > $@

compile_check: $(C_FILES)
	$(COMPILECHECK) $(PWD)


