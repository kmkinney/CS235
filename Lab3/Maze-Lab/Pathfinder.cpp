#include "Pathfinder.h"
#include <sstream>
#include <fstream>
#include <random>
Pathfinder::Pathfinder(){
    srand(time(NULL));
    clear();
}
/*
* toString
*/
string Pathfinder::toString() const{
    stringstream res;
    int x, y, z;
    for(z = 0; z < Z_SIZE; z++){
        for(y = 0; y < Y_SIZE; y++){
            for(x = 0; x < X_SIZE; x++){
                res << maze[z][y][x];
                if(x < X_SIZE - 1){
                    res << " ";
                }
            }
            res << endl;
        }
        if(z < Z_SIZE - 1){
            res << endl;
        }
    }
    return res.str();
}

/*
* createRandomMaze
*/
void Pathfinder::createRandomMaze(){
    int x, y, z;
    for(z = 0; z < Z_SIZE; z++){
        for(y = 0; y < Y_SIZE; y++){
            for(x = 0; x < X_SIZE; x++){
                maze[z][y][x] = rand() % 2;
            }
        }
    }
    //Start and exit
    maze[0][0][0] = OPEN;
    maze[Z_SIZE - 1][Y_SIZE  - 1][X_SIZE - 1] = OPEN;
}


/*
* importMaze
*
* Reads in a maze from a file with the given file name and stores it as the current maze.
* Does nothing if the file does not exist or if the file's data does not represent a valid
* maze.
*
* The file's contents must be of the format described above to be considered valid.
*
* Parameter:	file_name
*				The name of the file containing a maze
* Returns:		bool
*				True if the maze is imported correctly; false otherwise
*/
bool Pathfinder::importMaze(string file_name){
    //open file
    ifstream fin(file_name);
    if(!fin.is_open())
        return false;

    //fill maze
    int copy_maze[X_SIZE][Y_SIZE][Z_SIZE];
    int curr;
    int x, y, z;
    for(z = 0; z < Z_SIZE; z++){
        for(y = 0; y < Y_SIZE; y++){
            for(x = 0; x < X_SIZE; x++){
                fin >> curr;

                //bad input
                if(fin.fail() || fin.bad())
                    return false;
                //not a 1 or a 0
                if(curr != OPEN && curr != WALL)
                    return false;
            
                copy_maze[z][y][x] = curr;
            }
        }
    }
    //Check start and end condition
    if(copy_maze[0][0][0] != OPEN || copy_maze[Z_SIZE - 1][Y_SIZE  - 1][X_SIZE - 1] != OPEN)
        return false;
    //too many inputs
    fin >> curr;
    if(!fin.eof())
        return false;
    
    //Success, copy into array
    for(z = 0; z < Z_SIZE; z++){
        for(y = 0; y < Y_SIZE; y++){
            for(x = 0; x < X_SIZE; x++){
                maze[z][y][x] = copy_maze[z][y][x];
            }
        }
    }
    return true;
}

//Part 3-----------------------------------------------------------------------------------
/*
* solveMaze
*
* Attempts to solve the current maze and returns a solution if one is found.
*
* A solution to a maze is a list of coordinates for the path from the entrance to the exit
* (or an empty vector if no solution is found). This list cannot contain duplicates, and
* any two consecutive coordinates in the list can only differ by 1 for only one
* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
* where x, y, and z are the integer coordinates of a cell.
*
* Understand that most mazes will contain multiple solutions
*
* Returns:		vector<string>
*				A solution to the current maze, or an empty vector if none exists
*/
vector<string> Pathfinder::solveMaze(){
    solution.clear();
    findPath(0, 0, 0);
    //reset path variables
    int x, y, z;
    for(z = 0; z < Z_SIZE; z++){
        for(y = 0; y < Y_SIZE; y++){
            for(x = 0; x < X_SIZE; x++){
                if(maze[z][y][x] == PATH)
                    maze[z][y][x] = OPEN;
            }
        }
    }
    return solution;
}

bool Pathfinder::findPath(int x, int y, int z){
    //Check all bounds
    if(x < 0 || x >= X_SIZE)
        return false;
    if(y < 0 || y >= Y_SIZE)
        return false;
    if(z < 0 || z >= Z_SIZE)
        return false;
    
    
    //see if we've hit a wall or see if we've been here before
    if(maze[z][y][x] == PATH || maze[z][y][x] == WALL)
        return false;
    //Add position to path
    stringstream pos;
    pos << "(" << x << ", " << y << ", " << z << ")";
    solution.push_back(pos.str());
    maze[z][y][x] = PATH;

    //Check to see if we've reached the end
    if(x == X_SIZE - 1 && y == Y_SIZE - 1 && z == Z_SIZE - 1)
        return true;
    
    //Keep looking
    if(findPath(x+1, y, z) || findPath(x-1, y, z) || findPath(x, y+1, z) ||
       findPath(x, y-1, z) || findPath(x, y, z+1) || findPath(x, y, z-1))
            return true; //solved it
    else{
        solution.pop_back();
        return false;
    }
}

void Pathfinder::clear(){
    int x, y, z;
    for(x = 0; x < X_SIZE; x++){
        for(y = 0;y < Y_SIZE; y++){
            for(z = 0;z < Z_SIZE; z++){
                maze[z][y][x] = OPEN;
            }
        }
    }
}

int Pathfinder::getValue(int x, int y, int z){
    return maze[z][y][x];
}
