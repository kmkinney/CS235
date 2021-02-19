#pragma once
#include <string>
#include "Node.h"
using namespace std;

template<class T>
class LinkedList
{
    private:
        Node *head();
    public:
        LinkedList(){}
        ~LinkedList(){
            Node *curr = head->getNext();
            Node *temp = NULL;
            while(curr !=0 ){
                temp = curr;
                curr = curr->getNext();
                delete temp;
            }

        }
        bool add(Node *element){
            Node *curr = head;
            while(curr->getNext() != 0){
                curr = curr->getNext();
            }
            curr->setNext(element);
        }

};