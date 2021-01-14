#include "TodoList.h"
#include <iostream>
#include <string>
using namespace std;

//constructor, takes no arguments
TodoList::TodoList()
{
    //read in from file
    ifstream inFile(FILE_NAME);
    string line;
    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            tasks.push_back(line);
        }
    }
    inFile.close();
}

//destructor. Writes contents to file.
TodoList::~TodoList()
{
    ofstream outFile(FILE_NAME, ofstream::out | ofstream::trunc);
    if(outFile.is_open())
    {
        for(int i = 0;i < tasks.size();i++)
        {
            outFile << tasks[i] << endl;
        }
    }
    outFile.close();
}

//adds task to task list
void TodoList::add(string _duedate, string _task)
{
    tasks.push_back(_duedate + " " + _task);
}

//return 1 if successful, 0 if failed
int TodoList::remove(string _task)
{
    string tempTask;
    for(int i = 0;i < tasks.size();i++)
    {
        tempTask = tasks[i].substr(tasks[i].find(' ') + 1);
        if(tempTask.compare(_task) == 0)
        {
            tasks.erase(tasks.begin() + i);
            return 1;
        }
    }
    return 0;
}

//prints all tasks in TODO list
void TodoList::printTodoList()
{
    for(int i = 0;i < tasks.size();i++)
    {
        cout << tasks[i] << endl;
    }
}

//prints all tasks due on given date
void TodoList::printDaysTasks(string _date)
{
    string temp;
    string day;
    bool hasTasks = false;
    for(int i = 0;i < tasks.size();i++)
    {
        temp = tasks[i];
        string day = temp.substr(0, temp.find(' '));
        if(day.compare(_date) == 0)
        {
            cout << temp.substr(temp.find(' ') + 1) << endl;
            if(!hasTasks)
            {
                hasTasks = true;
            }
        }
    }
    if(!hasTasks)
    {
        cout << "No tasks were found due on " << _date << endl;
    }
}