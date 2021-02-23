TARGETS = Test_Clock Test_Clockx Test_Person Test_Company Test_Personx

CC = g++
CCFLAGS = -g -pedantic -Wall

all:	$(TARGETS)

Test_Clock:	Test_Clock.o Clock.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Clockx:	Test_Clockx.o Clock.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Person:	Test_Person.o Person.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Personx:	Test_Person.o Personx.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Company:	Test_Company.o Company.o Person.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Clock.o:	Test_Clock.cpp Clock.h
	$(CC) -c $(CCFLAGS) $<

Clock.o:	Clock.cpp Clock.h
	$(CC) -c $(CCFLAGS) $<

Test_Clockx.o:	Test_Clockx.cpp Clock.h
	$(CC) -c $(CCFLAGS) $<

Test_Person.o:	Test_Person.cpp Person.h
	$(CC) -c $(CCFLAGS) $<

Person.o:	Person.cpp Person.h
	$(CC) -c $(CCFLAGS) $<

Personx.o:	Person.cpp Person.h
	$(CC) -o $@ -c $(CCFLAGS) -DEXERCISE $<

Test_Company.o:	Test_Company.cpp Company.h Person.h
	$(CC) -c $(CCFLAGS) $<

Company.o:	Company.cpp Company.h
	$(CC) -c $(CCFLAGS) $<

.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
