#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc> 1){
        ifstream inF (argv[1]);
        string line;
        int word_count = 0;
        while(inF.is_open() && getline(inF, line)){
            istringstream ss(line);
            string item;
            while(ss >> item){
                bool is_word = false;
                for(auto &c:item){
                    if(isalpha(c)){
                        is_word = true;
                        break;
                    }
                }
                if(is_word)
                    word_count++;
            }
        }
        cout << "Number of words: " << word_count << endl;
    }
    return 0;
}
