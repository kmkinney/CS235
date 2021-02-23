TARGETS = Test_Palindrome_Finder Paren_Checker Test_Infix_To_Postfix \
Test_Infix_To_Postfix_Parens Test_Postfix_Evaluator Test_Stack_KW \
Test_Stack_KW_LIST  EX5p2p1 EX5p2p2 EX5p2p3

CC = g++
CCFLAGS = -Wall -pedantic -g

all:	$(TARGETS)

Test_Palindrome_Finder:	Test_Palindrome_Finder.o Palindrome_Finder.o
	$(CC) $(CCFLAGS) -o $@ $^

Paren_Checker:	Paren_Checker.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Infix_To_Postfix:	Test_Infix_To_Postfix.o Infix_To_Postfix.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Infix_To_Postfix_Parens:	Test_Infix_To_Postfix.o Infix_To_Postfix_Parens.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Infix_To_Postfix_Exp:	Test_Infix_To_Postfix.o Infix_To_Postfix_Exp.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Postfix_Evaluator:	Test_Postfix_Evaluator.o Postfix_Evaluator.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Palindrome_Finder.o:	Test_Palindrome_Finder.cpp Palindrome_Finder.h
	$(CC) $(CCFLAGS) -c $<

Palindrome_Finder.o:	Palindrome_Finder.cpp Palindrome_Finder.h
	$(CC) $(CCFLAGS) -c $<

Paren_Checker.o:	Paren_Checker.cpp
	$(CC) $(CCFLAGS) -c $<

Test_Infix_To_Postfix.o:	Test_Infix_To_Postfix.cpp Infix_To_Postfix.h \
Syntax_Error.h
	$(CC) $(CCFLAGS) -c $<

Infix_To_Postfix.o:	Infix_To_Postfix.cpp Infix_To_Postfix.h Syntax_Error.h
	$(CC) $(CCFLAGS) -c $<

Infix_To_Postfix_Parens.o:	Infix_To_Postfix_Parens.cpp Infix_To_Postfix.h Syntax_Error.h
	$(CC) $(CCFLAGS) -c $<

Infix_To_Postfix_Exp.o:	Infix_To_Postfix_Exp.cpp Infix_To_Postfix.h Syntax_Error.h
	$(CC) $(CCFLAGS) -c $<

Test_Postfix_Evaluator.o:	Test_Postfix_Evaluator.cpp \
Postfix_Evaluator.h Syntax_Error.h
	$(CC) $(CCFLAGS) -c $<

Postfix_Evaluator.o:	Postfix_Evaluator.cpp Postfix_Evaluator.h \
Syntax_Error.h
	$(CC) $(CCFLAGS) -c $<

Test_Stack_KW:	Test_Stack.cpp stack.h Stack.tc
	$(CC) $(CCFLAGS) -DUSEKW -o $@ $<

Test_Stack_KW_LIST: Test_Stack.cpp stack.h Linked_Stack.tc
	$(CC) $(CCFLAGS) -DUSEKW -DUSELIST -o $@ $<

RQ5P7:	RQ5P7.cpp stack.h Stack.tc
	$(CC) $(CCFLAGS) -o $@ $<

EX5p2p1:	EX5p2p1.cpp
	$(CC) $(CCFLAGS) -o $@ $^

EX5p2p2:	EX5p2p2.cpp
	$(CC) $(CCFLAGS) -o $@ $^

EX5p2p3:	EX5p2p3.cpp
	$(CC) $(CCFLAGS) -o $@ $^



.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)

