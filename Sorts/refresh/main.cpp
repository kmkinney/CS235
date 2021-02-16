#include <iostream>
#include <random>
#include <vector>
#include "Util.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;

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

    cout << "Quick Sort" << endl;
    RandomVector(list, 10);
    PrintVector(list);
    QuickSort(list);
    PrintVector(list);
    
    return 0;
}