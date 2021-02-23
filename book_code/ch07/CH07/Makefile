TARGETS = Recursive_Functions TestBinarySearch Blob \
Maze Eight_Queens Towers_Of_Hanoi

CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

Recursive_Functions:	Recursive_Functions.cpp
	g++ $(CCFLAGS) -o $@ $^

TestBinarySearch:	TestBinarySearch.cpp linear_search.h binary_search.h
	g++ $(CCFLAGS) -o $@ TestBinarySearch.cpp

Blob:	Blob.cpp
	g++ $(CCFLAGS) -o $@ Blob.cpp

Maze:	Maze.cpp
	g++ $(CCFLAGS) -o $@ Maze.cpp

Eight_Queens:	Eight_Queens.cpp
	g++ $(CCFLAGS) -o $@ $^

Towers_Of_Hanoi:	Towers_Of_Hanoi.cpp
	g++ $(CCFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f $(TARGETS)
