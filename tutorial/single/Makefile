### Makefile for Chapter 4 of tutorial

.SUFFIXES: .c .splint .exe .output

C_FILES=RunOutOfMemory.c RunOutOfMemoryFixed.c MemoryLeak.c DanglingPointer.c StackAllocated.c

SPLINT_FILES=RunOutOfMemory.splint RunOutOfMemoryFixed.splint MemoryLeak.splint DanglingPointer.splint StackAllocated.splint

EXE_FILES=RunOutOfMemory.exe StackAllocated.exe

OUTPUT_FILES=RunOutOfMemory.output StackAllocated.output

include ../Makefile.constants

all:
	$(MAKE) $(SPLINT_FILES)
	$(MAKE) $(EXE_FILES)
	$(MAKE) $(OUTPUT_FILES)
	cd LinkedList; $(MAKE) all;

RunOutOfMemory.output:
	 RunOutOfMemory.exe | tail --lines=15 > $@


.c.splint:
	-$(RUNSPLINT) $(SPLINTFLAGS) $< > $@

.c.exe:
	$(GCC) $< -o $@

.exe.output:
	$< > $@

compile_check: $(C_FILES)
	$(COMPILECHECK) $(PWD)







