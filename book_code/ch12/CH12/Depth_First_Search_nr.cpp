#include "Graph.h"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

/** Perform a depth-first search of a graph without using recursion.
    @param graph The graph to be searched
    @param parent The parents in the depth-first search tree
    @param discovery_order The discovery order for each vertex
    @param finish_order The finish order for each vertex
*/
void depth_first_search_nr(const Graph& graph,
                        vector<int>& parent,
                        vector<int>& discovery_order,
                        vector<int>& finish_order) {

  // A stack to hold the last previous vertex
  stack<int> previous_vertex;

  // A stack to hold the previous edge iterator
  stack<Graph::iterator> previous_iterator;

  int num_v = graph.get_num_v();
  parent.clear();
  parent.resize(num_v, -1);
  discovery_order.clear();
  discovery_order.resize(num_v, -1);
  finish_order.clear();
  finish_order.resize(num_v, -1);
  vector<bool> visited(num_v, false);
  int discovery_index = 0;
  int finish_index = 0;

  // Create DFS trees starting at each unvisited vertex.
  for (int i = 0; i < num_v; i++) {
    // Put a starting value into each of the stacks.
    if (!visited[i]) {
      previous_vertex.push(i);
      previous_iterator.push(graph.begin(i));
      discovery_order[discovery_index++] = i;
      
      // Loop while there are still edges to explore
      while (!previous_vertex.empty()) {
	int current_vertex = previous_vertex.top();
	Graph::iterator& current_iterator = previous_iterator.top();
	if (current_iterator != graph.end(current_vertex)) {
	  int child = (*current_iterator).get_dest();
	  if (!visited[child]) {
	    parent[child] = current_vertex;
	    previous_vertex.push(child);
	    previous_iterator.push(graph.begin(child));
	    discovery_order[discovery_index++] = child;
	    visited[child] = true;
	  } else {
	    ++current_iterator;
	  }
	} else {
	  finish_order[finish_index++] = current_vertex;
	  previous_iterator.pop();
	  previous_vertex.pop();
	}
      }
    }
  }
}


	
	
	
      
