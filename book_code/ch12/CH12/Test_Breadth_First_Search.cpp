#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Graph.h"
using namespace std;

vector<int> breadth_first_search(const Graph& graph, int start);

/** Main function to demonstrate the algorithm
    @param argc The count of the command line args
    @param argv The command line arguments
                argv[1] is the name of the input file
		argv[2] is the type of the graph to use
*/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Usage BreadthFirstSearch <input file> <graph type>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  Graph* graph;
  try {
    graph = Graph::create_graph(in, false, argv[2]);
  } catch (invalid_argument& ex) {
    cerr << ex.what() << endl;
    cerr << "Valid graph types are \"List\" and \"Matrix\"\n";
    return 1;
  }
  vector<int> parent = breadth_first_search(*graph, 0);
  for (int i = 0; i < graph->get_num_v(); i++) {
    cout << "parent[" << i << "] = " << parent[i] << endl;
  }
  return 0;
}
