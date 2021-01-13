//Kevin Kinney
//Lab 1 c++ review
#include <iostream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[])
{
    TodoList myList;
    if(argc > 1) //command line arguments found
    {
        string command = argv[1];
        //add
        if(command.compare("add") == 0)
        {
            string day;
            string task;
            if(argc > 3){//need date and task
                day = argv[2];
                task = argv[3];
                myList.add(day, task); //for now, must add rest later
            }
            else
            {
                cout << "ERROR must provide a due date and task" << endl;
            }
            
        }
        //remove
        else if (command.compare("remove") == 0)
        {
            string task = argv[2];
            if(myList.remove(task))
            {
                cout << "\"" << task << "\" was removed successfully" << endl;
            }
            else
            {
                cout << "ERROR failed to remove task" << endl;
                return 1;
            }
        }
        //print list
        else if (command.compare("printList") == 0)
        {
            myList.printTodoList();
        }
        //print day
        else if (command.compare("printDay") == 0)
        {
            string day = argv[2];
            myList.printDaysTasks(day);
        }
        //other
        else
        {
            cout << "ERROR command not recognized" << endl;
            return 1;
        }
        
    }
    //no command line args
    else
    {
        cout << "No commands found" << endl;
    }
    return 0;
}