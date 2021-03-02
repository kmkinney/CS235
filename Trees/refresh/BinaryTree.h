#pragma once
#include "TreeNode.h"
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class BinaryTree{
    private:
        #include "TreeNode.h"
        TreeNode<T> *root;
        void clear(TreeNode<T> *curr){
            if(curr == NULL)
                return;
            clear(curr->left);
            clear(curr->right);
            delete curr;
        }
    public:
        BinaryTree(){
            root = NULL;
        }
        ~BinaryTree(){
            clear(root);
        }
        void add(T value){
            if(root == NULL){
                root = new TreeNode<T>(value);
                return;
            }
            addHelper(value, root);
        }
        bool addHelper(T value, TreeNode<T> *curr){
            if(curr->left == NULL){
                curr->left = new TreeNode<T>(value);
                return true;
            }
            else if(curr->right == NULL){
                curr->right = new TreeNode<T>(value);
                return true;
            }
            if(addHelper(value, curr->left))
                return true;
            return addHelper(value, curr->right);
        }
        void remove(T value){

        }
        int size(){
            return 0;//number of nodes
        }
        string in_order(){
            stringstream ss;
            in_order_helper(ss, root);
            return ss.str();
        }
        void in_order_helper(stringstream &ss, TreeNode<T>*curr){
            if(curr == NULL){
                return;
            }
            if(curr->left == NULL && curr->right){
                ss << curr->data;
                return;
            }
            in_order_helper(ss, curr->left);
            ss << curr->data;
            in_order_helper(ss, curr->right);
        }
};