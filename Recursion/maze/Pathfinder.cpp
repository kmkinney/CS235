#include "Pathfinder.h"
#include <sstream>
#include <fstream>
using namespace std;

//5 x 5 grid string
string Pathfinder::toString() const{
    stringstream ss;
    int r, c;
    for(r = 0; r < ROW_SIZE; r++){
        for(c = 0; c < COL_SIZE; c++){
            ss << maze[r][c];
            if(c < COL_SIZE - 1)
                ss << " ";
        }
        if(r < ROW_SIZE - 1)
            ss << endl;
    }
    return ss.str();
}

void Pathfinder::createRandomMaze(){
    srand(time(NULL));
    int r, c;
    for(r = 0; r < ROW_SIZE; r++){
        for(c = 0; c < COL_SIZE; c++){
            maze[r][c] = rand() % 2;
        }
    }
    maze[0][0] = 1;
    maze[ROW_SIZE - 1][COL_SIZE - 1] = 1;
}

bool Pathfinder::importMaze(string file_name){
    ifstream inF(file_name);
    if(!inF.is_open())
        return false;
    string line;
    int r = 0;
    while(getline(inF, line)){
        if(r >= ROW_SIZE){
            cout << "Too many lines" << endl;
            return false;
        }
        stringstream ss(line);
        int token;
        int c = 0;
        while(ss >> token){
            if(c >= COL_SIZE){
                cout << "Too many numbers on row: " << r << endl;
                return false;
            }
            maze[r][c] = token;
            c++;
        }
        if(c != COL_SIZE){
            cout << "not enough numbers on row: " << r << endl;
            return false;
        }
        r++;
    }
    if(r != ROW_SIZE){
        cout << "not enough rows, 5 needed" << endl;
        return false;
    }
    return true;
}

bool Pathfinder::searchMazePaths(int r, int c, vector<string> &path){
    if(r < 0 || r >= ROW_SIZE)
        return false;
    if(c < 0 || c >= COL_SIZE)
        return false;
    if(maze[r][c] == 0 || maze[r][c] == 2)
        return false;

    stringstream ss;
    ss << "(" << r << ", " << c << ")";
    path.push_back(ss.str());
    maze[r][c] = 2;

    if(r == (ROW_SIZE - 1) && c == (COL_SIZE - 1))
        return true;
    
    return searchMazePaths(r+1, c, path) ||
           searchMazePaths(r-1, c, path) ||
           searchMazePaths(r, c+1, path) ||
           searchMazePaths(r, c-1, path);
}

vector<string> Pathfinder::solveMaze(){
    if(searchMazePaths(0, 0, solution))
        return solution;
    solution.clear();
    return solution;
}

void Pathfinder::clear(){
    int r, c;
    for(r = 0;r < ROW_SIZE; r++){
        for(c = 0; c < COL_SIZE; c++){
            maze[r][c] = 0;
        }
    }
}