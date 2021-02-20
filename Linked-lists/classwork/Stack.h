#pragma once
#include "Node.h"

template<class T>
class Stack
{
    public:
        Node *head;
        Node *tail;
        int size;
        Stack(){
            head = NULL;
            tail = NULL;
        }
        void push(T data){
            Node *add = new Node<>(data);
            add->next = head;
            head = add;
            if(size == 0)
                tail = add;
            size++;
        }
        T pop(){
            if(size == 0)
                return NULL;
            T data = head->data;
            Node *rem = head;
            head = head->next;
            delete rem;
            size--;
            if(size==0)
                tail=NULL;
            return data;
        }
};