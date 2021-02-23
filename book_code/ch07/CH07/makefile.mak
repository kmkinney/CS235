TARGETS = Recursive_Functions.exe TestBinarySearch.exe Blob.exe \
Maze.exe Eight_Queens.exe Towers_Of_Hanoi.exe

CPPFLAGS = /Zi /EHsc /GR /W1

all:	$(TARGETS)

Recursive_Functions.exe:	Recursive_Functions.cpp
	cl $(CPPFLAGS) /Fe$@ $**

TestBinarySearch.exe:	TestBinarySearch.cpp linear_search.h binary_search.h
	cl $(CPPFLAGS) /Fe$@ TestBinarySearch.cpp

Blob.exe:	Blob.cpp
	cl $(CPPFLAGS) /Fe$@ Blob.cpp

Maze.exe:	Maze.cpp
	cl $(CPPFLAGS) /Fe$@ Maze.cpp

Eight_Queens.exe:	Eight_Queens.cpp
	cl $(CPPFLAGS) /Fe$@ $**

Towers_Of_Hanoi.exe:	Towers_Of_Hanoi.cpp
	cl $(CPPFLAGS) /Fe$@ $**

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk

