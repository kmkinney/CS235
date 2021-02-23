#ifndef READ_BINARY_TREE_H
#define READ_BINARY_TREE_H

#include "Binary_Tree.h"
#include <istream>
#include <sstream>

template<typename Item_Type>
Binary_Tree<Item_Type> read_binary_tree(std::istream& in, const Item_Type&) {
  std::string next_token;
  in >> next_token;
  if (next_token == "null") {
    return Binary_Tree<Item_Type>();
  } else {
    Item_Type the_data;
    std::istringstream ins(next_token);
    ins >> the_data;
    Binary_Tree<Item_Type> left = read_binary_tree(in, the_data);
    Binary_Tree<Item_Type> right = read_binary_tree(in, the_data);
    return Binary_Tree<Item_Type>(the_data, left, right);
  }
}

#endif
