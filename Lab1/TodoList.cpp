#include "TodoList.h"
#include <iostream>
#include <string>
using namespace std;
TodoList::TodoList()
{
    ifstream inFile(FILE_NAME);
    string line;
    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            cout << line << endl;
            this->tasks.push_back(line);
        }
    }
    inFile.close();
}
TodoList::~TodoList()
{
    ofstream outFile(FILE_NAME, ofstream::out | ofstream::trunc);
    if(outFile.is_open())
    {
        for(int i = 0;i < this->tasks.size();i++)
        {
            outFile << this->tasks.at(i) << endl;
        }
    }
    outFile.close();
}
void TodoList::add(string _duedate, string _task)
{
    this->tasks.push_back(_duedate + " " + _task);
}
int TodoList::remove(string _task)
{
    return 0;
}
void TodoList::printTodoList()
{
    for(int i = 0;i < this->tasks.size();i++)
    {
        cout << this->tasks.at(i);
    }
}
void TodoList::printDaysTasks(string _date)
{
    for(int i = 0;i < this->tasks.size();i++)
    {
        string t = this->tasks.at(i);
        string d = t.substr(0, t.find(" "));
        cout << d << endl;
    }
}