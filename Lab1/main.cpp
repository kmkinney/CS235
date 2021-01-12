#include <iostream>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc > 1) //command line arguments found
    {
        cout << "command line arguments" << endl;
    }
    cout << "running" << endl;
    return 0;
}