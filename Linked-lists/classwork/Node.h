#pragma once

template <class T>

class Node
{
    public:
        T data;
        Node *next;
        Node(T node_data)){
            data = node_data;
            next = NULL;
        }
};