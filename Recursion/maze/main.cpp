#include <iostream>
#include <fstream>
#include "Pathfinder.h"
using namespace std;

int main(int argc, char const *argv[])
{
    if(argc == 2){
        Pathfinder path_finder;
        string grid = path_finder.toString();
        cout << grid << endl << endl;
        if(path_finder.importMaze(argv[1])){
            grid = path_finder.toString();
            cout << grid << endl << endl;
        }
        return 0;
    }
    cout << "file arg needed" << endl;
    return 1;
}
