#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "Graph.h"
using namespace std;

void depth_first_search_nr(const Graph& graph,
                        vector<int>& parent,
                        vector<int>& discovery_order,
                        vector<int>& finish_order);

/** Main function to demonstrate the algorithm.
    pre: argv[1] is the name of the input file.
    pre: argv[2] is the type of graph.
    @param argc The count of command line arguments
    @param argv The command line arguments
*/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Usage Depth_First_Search <input> <graph type>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;
  Graph* graph;
  try {
    graph = Graph::create_graph(in, true, argv[2]);
  } catch (invalid_argument& ex) {
    cerr << ex.what() << endl;
    cerr << "Valid graph types are \"List\" and \"Matrix\"\n";
    return 1;
  }
  vector<int> parent;
  vector<int> discovery_order;
  vector<int> finish_order;
  depth_first_search_nr(*graph, parent, discovery_order, finish_order);
  cout << setw(4) << "i";
  cout << setw(8) << "discovery_order";
  cout << setw(8) << "finish_order";
  cout << setw(8) << "parent";
  cout << endl;
  for (int i = 0; i < graph->get_num_v(); i++) {
    cout << setw(4) << i;
    cout << setw(8) << discovery_order[i];
    cout << setw(8) << finish_order[i];
    cout << setw(8) << parent[i];
    cout << endl;
  }
  return 0;
}
