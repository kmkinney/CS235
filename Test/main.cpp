#include <iostream>
#include "Car.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hi there" << endl;
    Car def;
    Car *newer = new Car(2020);
    def.printYear();
    newer->printYear(); 
}