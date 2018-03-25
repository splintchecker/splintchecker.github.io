### Makefile for Chapter 3 of tutorial

.SUFFIXES: .c .splint .exe .output

C_FILES=IfExample.c ElseExample.c IfQuiz.c BMI.c DangerousFloat.c NeedLoop.c\
 FirstLoop.c GradeAsk.c GradeAskSwitch.c Month.c MonthExtra.c Sum.c SumFor.c\
 DecToBin.c Factorial.c IntegerSolutions.c LargerThanTen.c\
 GradeAskSwitchNoBreak.c SwitchFallThrough.c SwitchFallThroughAnnotated.c\
 EqualMistake.c Matrix.c MatrixWithAnnotation.c

SPLINT_FILES=BMI.splint InfiniteLoop.splint SwitchFallThrough.splint\
 SwitchFallThroughAnnotated.splint EqualMistake.splint FindMax.splint\
 MatrixWithAnnotation.splint GradeAskSwitchNoBreak.splint Matrix.splint\

EXE_FILES=GradeAskSwitchNoBreak.exe EqualMistake.exe FindMax.exe Matrix.exe\
 LargerThanTen.exe

OUTPUT_FILES=GradeAskSwitchNoBreak.output EqualMistake.output FindMax.output\
 Matrix.output LargerThanTen.output

include ../Makefile.constants

all:
	$(MAKE) $(SPLINT_FILES)
	$(MAKE) $(EXE_FILES)
	$(MAKE) $(OUTPUT_FILES)

Matrix.splint:
	-$(RUNSPLINT) $(SPLINTFLAGS) +looploopbreak Matrix.c > $@

BMI.splint:
	-$(RUNSPLINT) $(SPLINTFLAGS) +elseifcomplete BMI.c > $@

.c.splint:
	-$(RUNSPLINT) $(SPLINTFLAGS) $< > $@

.c.exe:
	$(GCC) $< -o $@

.exe.output:
	$< > $@

compile_check: $(C_FILES)
	$(COMPILECHECK) $(PWD)







