#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        vector<string> words;
        set<string> unique;
        string file_name = argv[1];
        cout << file_name << endl;
        ifstream inF(file_name);
        string line;
        cout << inF.is_open() << endl;
        while(getline(inF, line))
        {
            istringstream ss(line);
            string token;
            while(ss >> token)
            {
                string nopunct = "";
                for(auto &c:token){
                    if(isalpha(c)){
                        nopunct += c;
                    }
                }
                words.push_back(nopunct);
                unique.insert(nopunct);
            }
        }
        cout << "number of total words: " << words.size() << endl;
        cout << "number of unique words: " << unique.size() << endl;
        cout << "unique words:" << endl;
        ofstream outF("unique.txt");
        for(set<string>::iterator it = unique.begin(); it != unique.end(); it++)
        {
            outF << *it << " ";
        }
        outF << endl;
        inF.close();
        outF.close();
    }
    return 0;
}