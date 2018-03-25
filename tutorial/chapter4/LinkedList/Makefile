### Makefile for Linked List program of chapter 4 of tutorial

.SUFFIXES: .c .splint .exe .output .html

C_FILES=LinkedList.c AddOut.c FixMalloc.c FixFgets.c FixSscanf.c

SPLINT_FILES=LinkedList.splint AddOut.splint FixMalloc.splint FixFgets.splint FixSscanf.splint

EXE_FILES=

OUTPUT_FILES=

SUB_C_FILES= Typedefs.c emp_list_create.c insert_record.c copy_record.c \
 test_bench.c

HTML_FILES=LinkedList.html test_bench.html AddOut.html FixMalloc.html FixFgets.html FixSscanf.html 

WARNING_FILES=LinkedList.warning AddOut.warning FixMalloc.warning FixFgets.warning 

include ../../Makefile.constants

EXTRACT_LINES=../../scripts/extract_lines.pl
INS_LINE_NUMBERS=../../scripts/insert_line_numbers.pl
C_TO_HTML = ../../scripts/c_to_html
RUNSPLINT=../../scripts/runsplint
EXTRACT_LINES_BY_NUMBER=../../scripts/extract_lines_by_number.pl
LINKED_LIST_FLAGS=-exportlocal $(SPLINTFLAGS)

export INS_LINE_NUMBERS

all:
	$(MAKE) $(SPLINT_FILES)
	$(MAKE) $(WARNING_FILES)
	$(MAKE) $(SUB_C_FILES)
	$(MAKE) $(HTML_FILES)

LinkedList.warning: LinkedList.splint
	$(EXTRACT_LINES_BY_NUMBER)  4 8 < LinkedList.splint > $@

AddOut.warning: AddOut.splint
	$(EXTRACT_LINES_BY_NUMBER) 10 15 < AddOut.splint > $@

FixMalloc.warning: FixMalloc.splint
	$(EXTRACT_LINES_BY_NUMBER) 91 93 < FixMalloc.splint > $@

FixFgets.warning:: FixFgets.splint
	$(EXTRACT_LINES_BY_NUMBER) 91 93 < FixFgets.splint > $@


Typedefs.c: LinkedList.c
	$(EXTRACT_LINES) '/*!Begin Typedefs!*/' '/*!End Typedefs!*/' < LinkedList.c  > $@

emp_list_create.c: LinkedList.c
	$(EXTRACT_LINES) '/*!Begin emp_list_create!*/' '/*!End emp_list_create!*/' < LinkedList.c > $@

insert_record.c: LinkedList.c
	$(EXTRACT_LINES) '/*!Begin insert_record!*/' '/*!End insert_record!*/' < LinkedList.c > $@ 

copy_record.c: LinkedList.c
	$(EXTRACT_LINES) '/*!Begin copy_record!*/' '/*!End copy_record!*/' < LinkedList.c > $@ 

test_bench.c: LinkedList.c
	$(EXTRACT_LINES) '/*!Begin test_bench!*/' '/*!End test_bench!*/' < LinkedList.c > $@ 

.c.html:
	$(C_TO_HTML) $(PWD) $<       

.c.splint:
	-$(RUNSPLINT) $(LINKED_LIST_FLAGS) $< > $@

.c.exe:
	$(GCC) $< -o $@

.exe.output:
	$< > $@

compile_check: $(C_FILES)
	$(COMPILECHECK) $(PWD)







