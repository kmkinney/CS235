#pragma once
#include "BSTInterface.h"
#include "NodeInterface.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class AVL: public BSTInterface{
    private:
        struct Node: public NodeInterface{
            int data;
            Node *left;
            Node *right;
            int balance;
            Node(int node_data){
                data = node_data;
                left = NULL;
                right = NULL;
                balance = 0;
            };
            int getData() const {return data;}
            Node * getLeft() const {return left;}
            Node * getRight() const {return right;}
        };
        
        Node *root;
    public:
        AVL(){
            root = NULL;
        }
        ~AVL(){
            clear();
        }
        bool add(int value){
            return add(root, value);
        }
        bool add(Node *& r, int value){
            if(r == NULL){
                r = new Node(value);
                return true;
            }
            else if(r->data > value){
                return add(r->left, value);
            }
            else if(r->data < value){
                return add(r->right, value);
            }
            else{
                return false;
            }
        }
        bool remove(int value){
            return remove(root, value);
        }
        bool remove(Node *& r, int value){
            if(r == NULL){
                return false;
            }
            else if(r->data > value){
                return remove(r->left, value);
            }
            else if(r->data < value){
                return remove(r->right, value);
            }
            else{
                if(r->left == NULL && r->right == NULL){
                    Node *tmp = r;
                    r = NULL;
                    delete tmp;
                    return true;
                }
                else if(r->left == NULL){
                    Node *tmp = r;
                    r = r->right;
                    delete tmp;
                    return true;

                }
                else if(r->right == NULL){
                    Node *tmp = r;
                    r = r->left;
                    delete tmp;
                    return true;
                }
                else{
                    Node * pred = r->left;
                    while(pred->right != NULL){
                        pred = pred->right;
                    }
                    r->data = pred->data;
                    remove(r->left, pred->data);
                    return true;
                }
            }
        }
        void clear(){
            clear(root);
            root = NULL;
        }
        void clear(Node *& r){
            if(r != NULL){
                clear(r->left);
                clear(r->right);
                delete r;
            }
        }
        Node * getRoot() const{
            return this->root;
        }
        int getHeight() const{
            if(root == NULL){
                return 0;
            }
            return getHeight(root);
        }
        int getHeight(Node *r) const{
            if(r == NULL){
                return -1;
            }
            return 1 + max(getHeight(r->left), getHeight(r->right));
        }
};