/*
Implementation of BST class
Kevin Kinney
*/

#include "BST.h"
using namespace std;

/*
======== CONSTRUCTOR AND DESTRUCTOR===========
*/
BST::BST(){
    root = NULL;
}

BST::~BST(){
    clear();
}

/*
============ PUBLIC METHODS ===================
*/

/**
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node * BST::getRootNode() const{
    return root;
}

/**
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
    return addHelper(root, data);
}

/**
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data){
    return removeHelper(root, data);
}

/**
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear(){
    if(root != NULL){
        clearHelper(root);
        root = NULL;
    }
}

/*
==========PRIVATE HELPER METHODS============
*/

/**
* Recursive helper method for insertion into the tree
* @param curr_root the local root
* @param data the data to be added
* @return true if the value was inserted
*/
bool BST::addHelper(Node *& curr_root, int data){
    //If we reach a null node, add the data
    if(curr_root == NULL){
        curr_root = new Node(data);
        return true;
    }

    //else compare data to curr_root's data
    int curr_data = curr_root->getData();
    //If equal, don't add
    if(data == curr_data){
        return false;
    }
    //If data is less than current root, recurse to the left subtree
    else if(data < curr_data){
        return  addHelper(curr_root->getLeftRef(), data);
    }
    //If data is greater than current root, recurse to the right subtree
    else{
        return addHelper(curr_root->getRightRef(), data);
    }   
}

/**
 * 
 */
bool BST::removeHelper(Node *& curr_root, int data){
    //Not found
    if(curr_root == NULL){
        return false;
    }
    //Continue search on left subtree
    else if(curr_root->getData() > data){
        return removeHelper(curr_root->getLeftRef(), data);
    }
    //Continue search on right subtree
    else if(data > curr_root->getData()){
        return removeHelper(curr_root->getRightRef(), data);
    }
    //We found it
    else{
        //Remove Leaf node
        if(curr_root->getLeftChild() == NULL && curr_root->getRightChild() == NULL){
            Node *tmp = curr_root;
            curr_root = NULL;
            delete tmp;
            return true;
        }
        //One child to the left
        else if(curr_root->getRightChild() == NULL){
            //Replace curr_root with left child using reference
            Node *tmp = curr_root;
            curr_root = curr_root->getLeftRef();
            delete tmp;
            return true;
        }
        //One child to the right
        else if(curr_root->getLeftChild() == NULL){
            //Replace curr_root with right child using reference
            Node *tmp = curr_root;
            curr_root = curr_root->getRightRef();
            delete tmp;
            return true;
        }
        //Two children
        else{
            //Find in order predecessor
            //Looks for the largest value in the left subtree
            replace(curr_root, curr_root->getLeftRef());
            return true;
        }
    }
}

/**
 * Recursive helper method to find the in order predecessor
 * of old_root and replace the value of old root with the value
 * of its in order predecessor. Then removes predecessor from tree.
 * @param old_root the root to be removed
 * @param pred the current candidate for in order predecessor
 */
void BST::replace(Node *& old_root, Node *& pred){
    if(pred->getRightChild()!= NULL){
        replace(old_root, pred->getRightRef());
    }
    else{
        old_root->setData(pred->getData());
        removeHelper(old_root->getLeftRef(), pred->getData());
    }
}

/**
 * Recursive Helper method for clear
 * @param curr_root the current root of the subtree
 */
void BST::clearHelper(Node *curr_root){
    if(curr_root != NULL){
        clearHelper(curr_root->getLeftRef());
        clearHelper(curr_root->getRightRef());
        delete curr_root;
    }
}