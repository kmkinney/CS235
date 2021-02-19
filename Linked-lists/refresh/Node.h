#pragma once
#include <string>
using namespace std;

template<class T>
class Node
{
    private:
        T *data;
        Node *next;
    public:
        Node(T *node_data=0, Node *next_node=0){
            data = node_data;next=next_node;
        }
        ~Node(){
            if(data != 0)
                delete this->data;
        }
        void setData(T *new_data){data=new_data;}
        void setNext(Node nex_node){next=next_node;}
        T* getData() const{return data;}
        Node* getNext() const{return next;}

};