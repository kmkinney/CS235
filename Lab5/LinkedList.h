/*
* Kevin Kinney
* Lab5 Linked Lists
*/
#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T> {
    private:
        /* Node stores data and a pointer to the next node */
        struct Node {
            T data;
            Node *next;
            Node(const T &node_data, Node *next_node){
                data = node_data;
                next = next_node;
            };
        };
        Node* head;
        int list_size;
    public:
        /*
        * Constructs an empty LinkedList
        */
        LinkedList(void) {
            head = NULL;
            list_size = 0;
        };
        /*
        * Deallocates memory used by the LinkedList
        */
        ~LinkedList(void) {
            Node *tmp;
            while(head != NULL){
                tmp = head->next;
                delete head;
                head = tmp;
            }
        };

        /*
        insertHead

        A node with the given value should be inserted at the beginning of the list.

        Do not allow duplicate values in the list.
        */
        void insertHead(T value){
            //check duplicates
            for(Node *n = head; n != NULL; n = n->next)
                if(n->data == value)
                    return;
            Node *add = new Node(value, head);
            head = add;
            list_size++;
        }

        /*
        insertTail

        A node with the given value should be inserted at the end of the list.

        Do not allow duplicate values in the list.
        */
        void insertTail(T value){
            //check if empty list
            if(head == NULL){
                Node *add = new Node(value, head);
                head = add;
                list_size++;
                return;
            }
            //check duplicates, stop when reaching tail in order to insert
            Node *n;
            for(n = head; n->next != NULL; n = n->next)
                if(n->data == value)
                    return;
            //check tail for duplicate
            if(n->data == value)
                return;
            
            //insert at tail
            Node *add = new Node(value, NULL);
            n->next = add;
            list_size++;
        }

        /*
        insertAfter

        A node with the given value should be inserted immediately after the
        node whose value is equal to insertionNode.

        A node should only be added if the node whose value is equal to
        insertionNode is in the list. Do not allow duplicate values in the list.
        */
        void insertAfter(T value, T insertionNode){
            Node *insert = NULL;
            //check duplicates and find insertion node
            for(Node *n = head; n != NULL; n = n->next){
                if(n->data == value)
                    return;
                if(n->data == insertionNode)
                    insert = n;
            }
            //insertionNode not in list or list is empty
            if(insert == NULL)
                return;

            //Insert value immediately after insertionNode
            Node *add = new Node(value, insert->next);
            insert->next = add;
            list_size++;
        }

        /*
        remove

        The node with the given value should be removed from the list.

        The list may or may not include a node with the given value.
        */
        void remove(T value){
            //Check if list is empty
            if(head == NULL)
                return;
            //Check if node to be removed is the head node
            if(head->data == value){
                Node *tmp = head->next;
                delete head;
                head = tmp;
                list_size--;
                return;
            }
            //Check rest of list
            for(Node *n = head; n->next != NULL; n = n->next){
                //If value is found, remove it from list
                if(n->next->data == value){
                    Node *tmp = n->next;
                    n->next = tmp->next;
                    delete tmp;
                    list_size--;
                    return;
                }
            }
        }

        /*
        clear

        Remove all nodes from the list.
        */
        void clear(){
            //Iterate through all nodes and delete them
            while(head != NULL){
                Node *tmp = head->next;
                delete head;
                head = tmp;
            }
            list_size = 0;
        }

        /*
        at

        Returns the value of the node at the given index. The list begins at
        index 0.

        If the given index is out of range of the list, throw an out of range exception.
        */
        T at(int index){
            //Check index to see if it is in bounds
            if(head == NULL || index < 0 || index >= list_size)
                throw out_of_range("out of range");
            //Iterate index number of nodes through the list
            Node *n = head;
            for(int i = 0; i < index; i++)
                n = n->next;
            return n->data;
        }

        /*
        size

        Returns the number of nodes in the list.
        */
        int size(){
            return list_size;
        }

        /*
        toString
        
        Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
        There should be no trailing space at the end of the string

        For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
        "1 2 3 4 5"
        */
        string toString(){
            //return an empty string if the list is empty
            if(head == NULL){
                return string();
            }
            stringstream ss;
            for(Node *n = head; n != NULL; n = n->next){
                ss << n->data;
                if(n->next != NULL)
                    ss << " ";
            }
            return ss.str();
        }
};
