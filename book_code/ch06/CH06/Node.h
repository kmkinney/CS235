#ifndef NODE_H_
#define NODE_H_

/** A Node is the building block for a single-linked list */
struct Node {
  // Data Fields
  /** The Data */
  Item_Type data;
  /** The pointer to the next node. */
  Node* next;
  
  // Constructor
  /** Creates a new Node that points to another node
      @param data_item The data stored
      @param next_ptr Pointer to the node pointed to by the new node
  */
  Node(const Item_Type& data_item, Node* next_ptr = NULL)
    : data(data_item), next(next_ptr) {}
};

#endif
