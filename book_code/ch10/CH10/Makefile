TARGETS = TestAllSorts

CC = g++
CCFLAGS = -g -pedantic -Wall

all:	$(TARGETS)

TestAllSorts:	TestAllSorts.cpp
	$(CC) $(CCFLAGS) -o $@ $<

TestAllSortsDecending:	TestAllSortsDecending.cpp
	$(CC) $(CCFLAGS) -o $@ $<

TestAllSortsArray:	TestAllSortsArray.cpp
	$(CC) $(CCFLAGS) -o $@ $<

TestAllSortsTrace:	TestAllSorts.cpp
	$(CC) $(CCFLAGS) -DTRACE -o $@ $<

.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
