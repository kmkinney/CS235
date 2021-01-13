#include <iostream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[])
{
    TodoList myList;
    if(argc > 1) //command line arguments found
    {
        cout << "command line arguments" << endl;
        string command = argv[1];
        if(command.compare("add") == 0)
        {
            if(argc > 3){//need date and task
                myList.add(argv[2], argv[3]); //for now, must add rest later
            } 
        }
        else if (command.compare("remove") == 0)
        {
            //remove
        }
        else if (command.compare("print") == 0)
        {
            //print
        }
        else
        {
            cout << "command not recognized" << endl;
        }
        
    }
    else
    {
        cout << "No commands found" << endl;
    }
    
    return 0;
}