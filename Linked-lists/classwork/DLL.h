#pragma once

template<class T>

class DLL
{
    private:
        struct Node
        {
            T data;
            Node *next = NULL;
            Node *prev = NULL;
        };
        Node *head;
        Node *tail;
        int size;
    public:
        DLL(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ~DLL(){
            Node *tmp;
            while(head != NULL){
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        void push_front(T x){
            Node *add = new Node;
            add->data = x;
            add->next = head;
            if(size == 0){
                tail = add;
            }
            else{
                head->prev = add;
            }
            head = add;
            size++;
        }
        void push_back(T x){
            Node *add = new Node;
            add->data = x;
            add->prev = tail;
            if(size == 0){
                head = add;
            }
            else{
                tail->next = add;
            }
            tail = add;
            size++;
        }
        T pop_front(){
            if(size == 0)
                return 0;
            
            T x = head->data;
            if(size == 1){
                delete head;
                delete tail;
                head = NULL;
                tail = NULL;
                size--;
                return x;
            }
            Node *tmp = head;
            head = head->next;
            head->prev = NULL;
            delete tmp;
            size--;
            return x;
        }
};
