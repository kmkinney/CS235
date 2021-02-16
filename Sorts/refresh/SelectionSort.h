#pragma once
#include <vector>
using namespace std;

void SelectionSort(vector<int> &list)
{
    int i, j;
    for(i = 0; i < list.size() - 1; i++)
    {
        int min_index = i;
        for(j = i+1; j < list.size(); j++)
        {
            if(list[j] < list[min_index])
                min_index = j;
        }
        list[i] = list[i] ^ list[min_index] ^ (list[min_index] = list[i]);
    }
}