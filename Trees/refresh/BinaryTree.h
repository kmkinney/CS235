#pragma once
#include "TreeNode.h"
#include <sstream>

template<typename T>
class BinaryTree{
    private:
        TreeNode *root;
    public:
        BinaryTree(){
            root = NULL;
        }
        ~BinaryTree(){
            //delete all nodes
        }
        void add(T value){

        }
        void remove(T value){

        }
        int size(){
            return 0;//number of nodes
        }
};