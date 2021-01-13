#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoListInterface.h"
using namespace std;

const string FILE_NAME = "TODOList.txt";

class TodoList: public TodoListInterface{
    private:
        vector<string> tasks;
    public:
        TodoList();
        ~TodoList();
        void add(string _duedate, string _task);
        int remove(string _task);
        void printTodoList();
        void printDaysTasks(string _date);
};

#endif