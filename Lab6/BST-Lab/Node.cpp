#include "Node.h"
#include <iostream>
using namespace std;

/**
* Constructor
* @param node_data the value of the node
* @param left_child the left child, default is NULL
* @param right_child the right child, default is NULL
*/
Node::Node(int node_data, Node *left_child, Node *right_child) {
    data = node_data;
    left = left_child;
    right = right_child;
}

/**
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const{
    return data;
}

/**
 * Sets data to new value
 * @param new_data the new data
 */
void Node::setData(int new_data){
    data = new_data;
}

/**
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node * Node::getLeftChild() const{
    return left;
}

/**
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node * Node::getRightChild() const{
    return right;
}

/**
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node *& Node::getLeftRef(){
    return left;
}

/**
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node *& Node::getRightRef(){
    return right;
}