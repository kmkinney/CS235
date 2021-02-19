#pragma once
#include <vector>
#include <iostream>
using namespace std;

void VectorTest()
{
    cout << "Vector Test" << endl;
    /*
        Vector Methods
        void push_front(<type> item);
        void push_back(<type> item);
        void pop_front();
        void pop_back();
        <type> front();
        <type> back();
        iterator insert(int position, <type> item);
        iterator erase (int position);
        bool empty();
        int size();
    */
   vector<int> my_vect;
   my_vect.push_back(1);
   my_vect.pop_back();
   cout << my_vect.empty() << endl;
}