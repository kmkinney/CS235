#include <iostream>
#include"MV.h"
using namespace std;

int main()
{
    MV<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(13);
    cout << arr.toString() << endl;
    arr.remove(0);
    cout << arr.toString() << endl;
    arr.insertAt(0, 1);
    cout << arr.toString() << endl;

    return 0;
}