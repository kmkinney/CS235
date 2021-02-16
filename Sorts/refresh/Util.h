#pragma once
#include <iostream>
#include <vector>
#include <random>
using namespace std;

void RandomVector(vector<int> &list, int size)
{
    list.clear();
    for(int i = 0; i < size; i++)
    {
        list.push_back(rand() % 101);
    }
}

void PrintVector(vector<int> &list)
{
    vector<int>::iterator it;
    cout << "[";
    for(it = list.begin(); it != list.end(); it++)
    {
        cout << *it;
        if(next(it, 1) != list.end())
            cout << ", ";
    }
    cout << "]" << endl;
}
void Swap(vector<int> &list, int pos1, int pos2){list[pos1] = list[pos2] ^ list[pos1] ^  (list[pos2] = list[pos1]);}