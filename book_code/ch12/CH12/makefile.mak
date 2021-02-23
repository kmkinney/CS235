TARGETS = Breadth_First_Search.exe Depth_First_Search.exe \
Topological_Sort.exe Maze.exe Dijkstra.exe Prim.exe Dijkstra_Prime.exe \
test_modifiable_PQ.exe

CCFLAGS = /EHsc /Zi /GR

all:	$(TARGETS)

Breadth_First_Search.exe: Test_Breadth_First_Search.obj \
Breadth_First_Search.obj Graph.obj Matrix_Graph.obj List_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Depth_First_Search.exe:	Test_Depth_First_Search.obj Depth_First_Search.obj \
Graph.obj Matrix_Graph.obj List_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Test_Breadth_First_Search.obj:	Test_Breadth_First_Search.cpp Graph.h
	cl $(CCFLAGS) -c Test_Breadth_First_Search.cpp

Test_Depth_First_Search.obj:	Test_Depth_First_Search.cpp Graph.h
	cl $(CCFLAGS) -c Test_Depth_First_Search.cpp

Breadth_First_Search.obj:	Breadth_First_Search.cpp Graph.h
	cl $(CCFLAGS) -c Breadth_First_Search.cpp

Depth_First_Search.obj:	Depth_First_Search.cpp Graph.h
	cl $(CCFLAGS) -c Depth_First_Search.cpp

Graph.obj:	Graph.cpp Graph.h Edge.h List_Graph.h Matrix_Graph.h
	cl $(CCFLAGS) -c Graph.cpp

Matrix_Graph.obj:	Matrix_Graph.cpp Matrix_Graph.h Graph.h Edge.h
	cl $(CCFLAGS) -c Matrix_Graph.cpp

List_Graph.obj:	List_Graph.cpp List_Graph.h Graph.h Edge.h
	cl $(CCFLAGS) -c List_Graph.cpp


Topological_Sort.exe:	Topological_Sort.obj Depth_First_Search.obj Graph.obj \
List_Graph.obj Matrix_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Topological_Sort.obj:	Topological_Sort.cpp Graph.h
	cl -c $(CCFLAGS) Topological_Sort.cpp

Maze.exe: Maze.obj Breadth_First_Search.obj Graph.obj List_Graph.obj \
Matrix_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Maze.obj:	Maze.cpp Graph.h Edge.h
	cl -c $(CCFLAGS) Maze.cpp

Dijkstra.exe:	Dijkstra.obj Graph.obj List_Graph.obj Matrix_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Dijkstra.obj:	Dijkstra.cpp Graph.h Edge.h
	cl $(CCFLAGS) -c Dijkstra.cpp

Dijkstra_Prime.exe: Dijkstra_Prime.obj Graph.obj List_Graph.obj \
Matrix_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Dijkstra_Prime.obj:	Dijkstra_Prime.cpp Graph.h Edge.h
	cl $(CCFLAGS) -c -I. -I../CH09 Dijkstra_Prime.cpp

Prim.exe: Prim.obj Graph.obj List_Graph.obj Matrix_Graph.obj
	cl $(CCFLAGS) /Fe$@ $**

Prim.obj:	Prim.cpp Graph.h Edge.h
	cl $(CCFLAGS) -c -I. -I../CH09 Prim.cpp

test_modifiable_PQ.exe:	test_modifiable_PQ.cpp Modifiable_Priority_Queue.h
	cl $(CCFLAGS) /Fe$@ test_modifiable_PQ.cpp


clean:
	del *.obj
	del *.exe

