#include <iostream>
#include <random>
#include <vector>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
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

int main()
{
    srand(time(NULL));
    vector<int> list;

    cout << "Unsorted" << endl;
    RandomVector(list, 10);
    PrintVector(list);

    cout << "Bubble Sort" << endl;
    BubbleSort(list);
    PrintVector(list);

    cout << "Smart Bubble Sort" << endl;
    RandomVector(list, 10);
    SmartBubbleSort(list);
    PrintVector(list);

    cout << "Selection Sort" << endl;
    RandomVector(list, 10);
    SelectionSort(list);
    PrintVector(list);

    cout << "Insertion Sort" << endl;
    RandomVector(list, 10);
    InsertionSort(list);
    PrintVector(list);

    cout << "Merge Sort" << endl;
    RandomVector(list, 10);
    PrintVector(list);
    MergeSort(list);
    PrintVector(list);
    
    return 0;
}