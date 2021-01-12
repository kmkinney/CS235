#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List<int> ls;
    ls.put(7);
    cout << ls.get() << endl;
    return 0;
}