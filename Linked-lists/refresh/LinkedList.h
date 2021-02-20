#pragma once
#include <string>
#include "Node.h"
using namespace std;

template<class T>
class LinkedList
{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList(){
            head = new Node<T>();
        }
        ~LinkedList(){
            Node<T> *curr = head->getNext();
            Node<T> *temp = 0;
            while(curr !=0 ){
                temp = curr;
                curr = curr->getNext();
                delete temp;
            }
        }
        void add(T element){
            Node<T> *curr = head;
            while(curr->getNext() != 0){
                curr = curr->getNext();
            }
            curr->setNext(new Node<T>(element));
        }
        void remove(T element){
            Node<T> *curr = head;
            while(curr->getNext()->getData() != element){
                curr = curr->getNext();
            }
            Node<T> *temp = curr->getNext();
            curr->setNext(temp->getNext());
            delete temp;
        }
        void printList() const{
            Node<T> *curr = head->getNext();
            while(curr != 0){
                cout << curr->toString();
                if(curr->getNext() != 0)
                    cout << ", ";
                curr = curr->getNext();
            }
            cout << endl;
        }
};