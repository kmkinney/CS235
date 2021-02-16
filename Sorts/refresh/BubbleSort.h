#pragma once
#include <vector>
using namespace std;

void BubbleSort(vector<int> &list)
{
    int i, j;
    for(i = 0; i < list.size(); i++)
    {
        for(j = 0; j < list.size()-1-i; j++)
        {
            if(list[j] > list[j+1])
            {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;

            }
        }
    }
}

void SmartBubbleSort(vector<int> &list)
{
    int i, j;
    for(i = 0; i < list.size(); i++)
    {
        bool swap = false;
        for(j = 0; j < list.size()-1-i; j++)
        {
            if(list[j] > list[j+1])
            {
                list[j] = list[j] ^ list[j+1] ^ (list[j+1] = list[j]);
                swap = true;
            }
        }
        if(!swap)
            return;
    }
}