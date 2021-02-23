The following files are included in this directory:

NOTE: Since the Edge class is needed for the Graph, nothing will compile
until the Edge class is provided.  For the Student version, this class
is not provided since it is an exercise.

Makefile			 A make file for g++ under Linux -- see 
				 description below
Breadth_First_Search.cpp	 The implementation of the breadth-first search
Depth_First_Search.cpp		 The implementation of the depth-first search
Dijkstra.cpp			 Dijkstra's shortest path algorithm
Dijkstra_Prime.cpp		 Dijkstra's shortest path algorithm using
				 sets.
Graph.cpp			 The implementation of the Graph abstract class
List_Graph.cpp			 The implementation of the Graph using
				 adjacency lists.
Matrix_Graph.cpp		 The implementation of the Graph using
				 adjacency matrix
Maze.cpp			 Program to solve a maze using breadth-first
				 search
Prim.cpp			 Prim's minimum spanning tree algorithm
Test_Breadth_First_Search.cpp	 Test program for the breadth-first search
Test_Depth_First_Search.cpp	 Test program for the depth-first search
test_modifiable_PQ.cpp		 Test program for the modifiable priority queue
Topological_Sort.cpp		 Topological sort algoirthm using depth-first
				 search.
Edge.h				 Definition of the Edge class
Graph.h				 Definition of the Graph class
List_Graph.h			 Definition of the List_Graph class
Matrix_Graph.h			 Definition of the Matrix_Graph class
Modifiable_Priority_Queue.h	 Definition of the Modifiable_Priority_Queue 
CIS.txt				 Graph representing course prerequisites
DAG.txt				 A directed acylic graph
DagWithLoop.txt			 Another directed acyclic graph
DagWithoutLoop.txt		 A directed graph with a loop
Dijkstra_test1.txt		 Test case for Dijkstra's algorithm
Dijkstra_test2.txt		 Test case for Dijkstra's algorithm
Dijkstra_test3.txt		 Test case for Dijkstra's algorithm
Graph2.txt			 The graph of figure 12.8
MazeA.txt			 The graph representation of MazeAX
MazeAX.txt			 A maze represented by X's and spaces
MazeB.txt			 The graph representation of MazeBX
MazeBX.txt			 The maze of figure 12.21
minspan1.txt			 A test case for Prim's algorithm
minspan2.txt			 Another test case for Prim's algorithm
README.txt			 This file.

The Makefile builds the following programs

Breadth_First_Search		 Test program for breadth-first search
Depth_First_Search		 Test program for depth-first search 
Topological_Sort		 The topological sort program
Maze				 The solution to a maze using BFS
Dijkstra			 Dijkstra's shortest path algorithm 
Prim				 Prim's minimum spanning tree algorithm
Dijkstra_Prime			 Dijkstra's algorithm using sets
test_modifiable_PQ		 Test the modifiable priority queue

Except for the test_modifiable_PQ program, all programs take two command
line arguments. The first is the file containing the graph, and the second
is the type of graph (either "Matrix" or "List").

Both Prim.cpp and Dijkstra_Prime.cpp use the Set_Funcitons.h file from CH09.
