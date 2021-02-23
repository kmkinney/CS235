#pragma once
#include "Node.h"
using namespace std;

template<class T>

class Stack
{
    private:
        Node<T> *head;
    public:
        Stack(){head=0;}
        ~Stack(){
            while(head!=0){
                Node<T> *tmp = head;
                head = head->getNext();
                delete tmp;
            }
        }
        void push(T x){
            Node<T> *add = new Node<T>(x);
            add->setNext(head);
            head = add;
        }
        T pop(){
            if(head == 0)
                return NULL;
            T x = head->getData();
            Node<T> *tmp = head;
            head = head->getNext();
            delete tmp;
            return x;
        }
};