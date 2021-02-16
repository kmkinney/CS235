#pragma once
#include <vector>
using namespace std;

void InsertionSort(vector<int> &list)
{
    int i, j;
    for(i = 1; i < list.size(); i++)
    {
        int val = list[i];
        j = i;
        //start at current pos and look back, then
        //shift until spot in sorted array is located
        while(list[j-1] > val && j >=0)
        {
            list[j] = list[j-1];
            j--;
        }
        list[j] = val;
    }
}