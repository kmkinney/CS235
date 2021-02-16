#pragma once
#include <vector>
#include <iostream>
#include "Util.h"
using namespace std;

int MedianOfThree(vector<int> &list, int start, int end);
int Partition(vector<int> &list, int  start, int end, int pivot);
void QuickSortRec(vector<int> &list, int start, int end);


void QuickSort(vector<int> &list)
{
    QuickSortRec(list, 0, list.size());
}

void QuickSortRec(vector<int> &list, int start, int end)
{
    if((end - start) >= 2) //BASE CASE
    {
        int pivot = MedianOfThree(list, start, end);
        cout << "Median of Three: (" << start << ", " << end << ") "; 
        PrintVector(list);
        pivot = Partition(list, start, end, pivot);
        cout << "Partition: ";
        PrintVector(list);
        //Recurse on the vector to either side of the pivot
        QuickSortRec(list, start, pivot);
        QuickSortRec(list, pivot+1, end);
    }
}

int Partition(vector<int> &list, int  start, int end, int pivot)
{
    //Swap pivot to start of list
    Swap(list, start, pivot);
    int up = start + 1;
    int down = end - 1;
    do
    {
        while(up < end-1 && list[up] < list[start])
            up++;
        while(down > start && list[down] >= list[start])
            down--;
        if(up < down)
            Swap(list, up, down);
    } while (up < down);
    Swap(list, start, down);
    return down;
}

int MedianOfThree(vector<int> &list, int start, int end)
{
    int mid = (start + end) / 2;
    if(list[mid] < list[start])
        Swap(list, start, mid);
    if(list[end-1] < list[mid]){
        Swap(list, mid, end-1);
        if(list[mid] < list[start])
            Swap(list, start, mid);
    }
    return mid;
}
