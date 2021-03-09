#pragma once
#include "NodeInterface.h"
#include <iostream>
using namespace std;

/**
 * Node class is a Binary Tree Node
 * Inherits from Node Interface
 */
class Node: public NodeInterface {
    protected:
        int data;
        Node *left;
        Node *right;
    public: 
        Node(int node_data, Node *left_child=NULL, Node *right_child=NULL);
        ~Node(){};

        /*
        * Returns the data that is stored in this node
        *
        * @return the data that is stored in this node.
        */
        int getData() const;

        /**
         * Sets data to new value
         * @param new_data the new data
         */
        void setData(int new_data);

        /**
        * Returns the left child of this node or null if it doesn't have one.
        *
        * @return the left child of this node or null if it doesn't have one.
        */
        Node * getLeftChild() const;

        /**
        * Returns the right child of this node or null if it doesn't have one.
        *
        * @return the right child of this node or null if it doesn't have one.
        */
        Node * getRightChild() const;

        /**
        * Returns the reference to the left child of this node or null if it doesn't have one.
        *
        * @return the reference to the left child of this node or null if it doesn't have one.
        */
        Node *& getLeftRef();

        /**
        * Returns the reference to the right child of this node 
        * or null if it doesn't have one.
        *
        * @return the reference to the right child of this node 
        * or null if it doesn't have one.
        */
        Node *& getRightRef();

};