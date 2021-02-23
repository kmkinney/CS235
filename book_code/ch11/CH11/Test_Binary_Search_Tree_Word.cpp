/** Program to test binary tree class */

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
#include "AVL_Tree.h"
#include "Red_Black_Tree.h"
#include "pre_order_traversal.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <tree type>\n";
    cerr << "Valid tree types: Binary_Search_Tree, AVL_Tree, "
	 << "or Red_Black_Tree\n";
    return 1;
  }
  Binary_Search_Tree<string>* the_tree = NULL;
  if (string(argv[1]) == "Binary_Search_Tree") 
    the_tree = new Binary_Search_Tree<string>;
  else if (string(argv[1]) == "AVL_Tree")
    the_tree = new AVL_Tree<string>; 
  else if (string(argv[1]) == "Red_Black_Tree")
    the_tree = new Red_Black_Tree<string>;
  if (the_tree == NULL) {
    cerr << "Unrecognized tree type\n";
    cerr << "Valid tree types: Binary_Search_Tree, AVL_Tree, "
	 << "or Red_Black_Tree\n";
    return 1;
  }
  string word;
  while (cin >> word) {
    the_tree->insert(word);
    pre_order_traversal(*the_tree, cout, 0);
  }
  cin.clear();
  //  while (cin >> word) {
  //  the_tree->erase(word);
  //  pre_order_traversal(*the_tree, cout, 0);
  // }
}
