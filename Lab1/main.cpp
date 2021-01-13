#include <iostream>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[])
{
    TodoList myList;
    if(argc > 1) //command line arguments found
    {
        cout << "command line arguments" << endl;
    }else
    {
        cout << "No commands found" << endl;
    }
    
    return 0;
}