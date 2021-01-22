#pragma once
#include <vector>
#include <list>
#include <iostream>
using namespace std;

void IteratorTest()
{
    cout << "Iterator Test" << endl;
    vector<int> my_nums;
    my_nums.push_back(1);
    my_nums.push_back(2);
    my_nums.push_back(3);
    my_nums.push_back(4);
    // a good way to iterate over a vector using size_t
    for(size_t i = 0; i < my_nums.size(); i++)
    {
        cout << my_nums[i] << endl;
    }
    cout << "using iterator" << endl;
    //iterating over a vector using iterators
    for(vector<int>::iterator itr = my_nums.begin(); itr != my_nums.end(); itr++)
    {
        cout << *itr << endl; //dereference the pointer
    }

    //using a list
    cout << "using list" << endl;
    list<int> my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(4);
    
    //same loop works for list, [] won't work
    for(list<int>::iterator itr = my_list.begin(); itr != my_list.end(); itr++)
    {
    	cout << *itr << endl;
    } 
}
