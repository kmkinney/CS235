#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

int main()
{
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.remove(1);
    list.printList();

    Stack<string> stack;
    stack.push("hi");
    stack.push("hello");
    cout << stack.pop() << endl;
    return 0;
}