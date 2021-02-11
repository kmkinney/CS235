#include <iostream>
#include <fstream>
#include "Pathfinder.h"
using namespace std;

void PrintVector(vector<string> &path){
    for(vector<string>::iterator it = path.begin(); it != path.end(); it++){
        cout << *it << endl;
    }
}

int main(int argc, char const *argv[])
{
    if(argc == 2){
        Pathfinder path_finder;
        string grid = path_finder.toString();
        cout << grid << endl << endl;
        if(path_finder.importMaze(argv[1])){
            vector<string> path;
            grid = path_finder.toString();
            cout << grid << endl << endl;

            cout << "Solving maze" << endl;
            path = path_finder.solveMaze();

            grid = path_finder.toString();
            cout << grid << endl << endl;
            PrintVector(path);
        }
        return 0;
    }
    cout << "file arg needed" << endl;
    return 1;
}
