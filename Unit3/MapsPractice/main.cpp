#include <iostream>
#include <fstream>
#include <set>
#include <map>
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
        map<string, int> wordcount;
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
                wordcount[nopunct]++;
            }
        }
        cout << "number of total words: " << words.size() << endl;
        ofstream outF("wordcount.txt");
        pair<string, int> max_count;
        max_count.second = 0;
        for(map<string, int>::iterator it = wordcount.begin(); it != wordcount.end(); it++)
        {
            outF << it->first << " : " << it->second << endl;
            if(it->second > max_count.second)
                max_count = (*it);
        }
        cout << "Max word: " << max_count.first << " = " << max_count.second << endl;
        inF.close();
        outF.close();
    }
    return 0;
}