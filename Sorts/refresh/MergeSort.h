#pragma once
#include <vector>
#include <queue>
using namespace std;

void Merge(vector<int> &list, int begin, int mid, int end);
void MergeSortHelper(vector<int> &list, int begin, int end);

//Funtion to be called
void MergeSort(vector<int> &list)
{
    MergeSortHelper(list, 0, list.size());
}

//Recursive splitting of the array
void MergeSortHelper(vector<int> &list, int begin, int end)
{
    if(end - begin == 1)
        return;
    int mid = (begin + end) / 2;
    MergeSortHelper(list, begin, mid);
    MergeSortHelper(list, mid, end);
    Merge(list, begin, mid, end);
}

//Merges two sorted sections of the vector into 1 sorted section
void Merge(vector<int> &list, int begin, int mid, int end)
{
    int ri = begin;
    int li = mid;
    queue<int> tmp;
    while(ri < mid || li < end)
    {
        if(ri == mid)
            tmp.push(list[li++]);
        else if(li == end)
            tmp.push(list[ri++]);
        else if(list[ri] < list[li])
            tmp.push(list[ri++]);
        else
            tmp.push(list[li++]);
    }
    //copy into vector
    for(int i = begin; i < end; i++)
    {
        list[i] = tmp.front();
        tmp.pop();
    }
}