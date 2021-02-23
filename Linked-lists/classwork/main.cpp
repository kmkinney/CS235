#include <iostream>
#include <string>
#include "DLL.h"
using namespace std;

int main()
{
    DLL<int> dll;
    dll.push_front(1);
    cout << dll.pop_front() << endl; 

    DLL<string> sll;
    cout << sll.pop_front();
    return 0;
}