TARGETS = Breadth_First_Search Depth_First_Search \
Depth_First_Search_nr \
Topological_Sort Maze Dijkstra \
Dijkstra_Trace Prim Prim_Trace Dijkstra_Prime \
test_modifiable_PQ

CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

Breadth_First_Search: Test_Breadth_First_Search.o Breadth_First_Search.o \
Graph.o Matrix_Graph.o List_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Depth_First_Search:	Test_Depth_First_Search.o Depth_First_Search.o \
Graph.o Matrix_Graph.o List_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Depth_First_Search_nr:	Test_Depth_First_Search_nr.o Depth_First_Search_nr.o \
Graph.o Matrix_Graph.o List_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Breadth_First_Search.o:	Test_Breadth_First_Search.cpp Graph.h
	$(CC) $(CCFLAGS) -c $<

Test_Depth_First_Search.o:	Test_Depth_First_Search.cpp
	$(CC) $(CCFLAGS) -c $<

Test_Depth_First_Search_nr.o:	Test_Depth_First_Search_nr.cpp
	$(CC) $(CCFLAGS) -c $<

Breadth_First_Search.o:	Breadth_First_Search.cpp Graph.h
	$(CC) $(CCFLAGS) -c $<

Depth_First_Search.o:	Depth_First_Search.cpp Graph.h
	$(CC) $(CCFLAGS) -c $<

Depth_First_Search_nr.o:	Depth_First_Search_nr.cpp Graph.h
	$(CC) $(CCFLAGS) -c $<

Graph.o:	Graph.cpp Graph.h Edge.h List_Graph.h Matrix_Graph.h
	$(CC) $(CCFLAGS) -c Graph.cpp

Matrix_Graph.o:	Matrix_Graph.cpp Matrix_Graph.h Graph.h Edge.h
	$(CC) $(CCFLAGS) -c Matrix_Graph.cpp

List_Graph.o:	List_Graph.cpp List_Graph.h Graph.h Edge.h
	$(CC) $(CCFLAGS) -c List_Graph.cpp


Topological_Sort:	Topological_Sort.o Depth_First_Search.o Graph.o \
List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Topological_Sort.o:	Topological_Sort.cpp Graph.h
	$(CC) -c $(CCFLAGS) $<

Maze: Maze.o Breadth_First_Search.o Graph.o List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Maze.o:	Maze.cpp Graph.h Edge.h
	$(CC) -c $(CCFLAGS) $<

Dijkstra:	Dijkstra.o Graph.o List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Dijkstra_Trace:	Dijkstra_Trace.o Graph.o List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Dijkstra.o:	Dijkstra.cpp Graph.h Edge.h
	$(CC) $(CCFLAGS) -c $<

Dijkstra_Trace.o:	Dijkstra.cpp Graph.h Edge.h
	$(CC) $(CCFLAGS) -DTRACE -c $< -o $@

Dijkstra_Prime: Dijkstra_Prime.o Graph.o List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Dijkstra_Prime.o:	Dijkstra_Prime.cpp Graph.h Edge.h
	$(CC) $(CCFLAGS) -c  $<

Prim: Prim.o Graph.o List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Prim.o:	Prim.cpp Graph.h Edge.h
	$(CC) $(CCFLAGS) -c  $<

Prim_Trace: Prim_Trace.o Graph.o List_Graph.o Matrix_Graph.o
	$(CC) $(CCFLAGS) -o $@ $^

Prim_Trace.o:	Prim.cpp Graph.h Edge.h
	$(CC) $(CCFLAGS) -DTRACE -c  $< -o $@

test_modifiable_PQ:	test_modifiable_PQ.cpp Modifiable_Priority_Queue.h
	$(CC) $(CCFLAGS) -o $@ $<


.PHONY:	clean
clean:
	rm -f *.o
	rm -f $(TARGETS)

