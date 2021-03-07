#pragma once
#include "TreeNode.h"
#include <sstream>
using namespace std;

template<typename T>
class BST{
    private:
        TreeNode<T> *root;

        //Helper methods
        bool addHelper(T value, TreeNode<T> *curr){
            if(curr->data == value){
                return false;
            }
            if(curr->data > value){
                if(curr->left == NULL){
                    curr->left = new TreeNode<T>(value);
                    return true;
                }
                return addHelper(value, curr->left);
            }
            if(curr->right == NULL){
                curr->right = new TreeNode<T>(value);
                return true;
            }
            return addHelper(value, curr->right);
        }
        
        bool containsHelper(T value, TreeNode<T> *curr){
            return false;
        }
        bool removeHelper(T value, TreeNode<T> *curr){
            return false;
        }
    public:
        BST(){
            root = NULL;
        }
        ~BST(){
            //delete contents
        }
        bool add(T value){
            if(root == NULL){
                root = new TreeNode<T>(value);
                return true;
            }
            return addHelper(value, root);
        }
        bool contains(T value){
            return false;
        }
        bool remove(T value){
            return false;
        }
        void clear(){
            //empty tree
        }
        int getHeight(){
            return 0;
        }
        int getWidth(){
            return 0;
        }
        string inOrder(){
            stringstream ss;
            return ss.str();
        }
};