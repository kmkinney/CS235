#include <iostream>
#include <string>
#include "LinkedList.h"
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
    return 0;
}