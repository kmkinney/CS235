#pragma once
#include <sstream>
#include <iostream>
#include <queue>
#include "BSTInterface.h"
#include "NodeInterface.h"

namespace TP{
    //Helper methods
    namespace{
        void in_order_helper(std::queue<int> &nodes, NodeInterface *n){
            if(n != NULL){
                in_order_helper(nodes, n->getLeft());
                nodes.push(n->getData());
                in_order_helper(nodes, n->getRight());
            }
        }

        void pre_order_helper(std::queue<int> &nodes, NodeInterface *n){
            if(n != NULL){
                nodes.push(n->getData());
                in_order_helper(nodes, n->getLeft());
                in_order_helper(nodes, n->getRight());
            }
        }

        void post_order_helper(std::queue<int> &nodes, NodeInterface *n){
            if(n != NULL){
                in_order_helper(nodes, n->getLeft());
                in_order_helper(nodes, n->getRight());
                nodes.push(n->getData());
            }
        }
    }
    void PrintInorder(BSTInterface &tree){
        std::queue<int> nodes;
        in_order_helper(nodes, tree.getRoot());
        std::cout << "In Order Traversal" << std::endl;
        while(!nodes.empty()){
            std::cout << nodes.front();
            nodes.pop();
            if(!nodes.empty()){
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    void PrintPreorder(BSTInterface &tree){
        std::queue<int> nodes;
        pre_order_helper(nodes, tree.getRoot());
        std::cout << "Pre Order Traversal" << std::endl;
        while(!nodes.empty()){
            std::cout << nodes.front();
            nodes.pop();
            if(!nodes.empty()){
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    void PrintPostorder(BSTInterface &tree){
        std::queue<int> nodes;
        post_order_helper(nodes, tree.getRoot());
        std::cout << "Post Order Traversal" << std::endl;
        while(!nodes.empty()){
            std::cout << nodes.front();
            nodes.pop();
            if(!nodes.empty()){
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    
    void PrintBFS(BSTInterface &tree){
        std::queue<NodeInterface *> nodes;
        int depth = 0;
        NodeInterface * tmp = tree.getRoot();
        if(tmp == NULL){
            std::cout << "Empty Tree" << std::endl;
        }
        else{
            nodes.push(tmp);
            while(!nodes.empty()){
                std::cout << depth << ": ";
                int num_nodes = nodes.size();
                while(num_nodes>0){
                    tmp = nodes.front();
                    std::cout << tmp->getData() << " ";
                    if(tmp->getLeft() != NULL){
                        nodes.push(tmp->getLeft());
                    }
                    if(tmp->getRight()!= NULL){
                        nodes.push(tmp->getRight());
                    }
                    nodes.pop();
                    num_nodes--;
                }
                std::cout << std::endl;
                depth++;
            }
        }
    }
};