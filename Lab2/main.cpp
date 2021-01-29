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

void ReadWordsToVector(vector<string> &words, string file_name);
void ReadWordsToSet(set<string> &word_set, string file_name);
void PrintVectorToFile(vector<string> &words, string file_name);
void PrintSetToFile(set<string> &word_set, string file_name);

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        string file_name = argv[1];
        vector<string> words;
        ReadWordsToVector(words, file_name);
        PrintVectorToFile(words, "vector.txt");

        set<string> word_set;
        ReadWordsToSet(word_set, file_name);
        PrintSetToFile(word_set, "set.txt");
        
    }
    return 0;
}

void ReadWordsToSet(set<string> &word_set, string file_name)
{
    ifstream inF(file_name);
    string line;
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
            word_set.insert(nopunct);
        }
    }
    inF.close();
}

void ReadWordsToVector(vector<string> &words, string file_name)
{
    ifstream inF(file_name);
    string line;
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
        }
    }
    inF.close();
}

void PrintSetToFile(set<string> &word_set, string file_name)
{
    ofstream outF(file_name);
    set<string>::iterator it;
    for(it = word_set.begin(); it != word_set.end(); it++)
    {
        outF << *it << endl;
    }
    outF.close();
}

void PrintVectorToFile(vector<string> &words, string file_name)
{
    ofstream outF(file_name);
    vector<string>::iterator it;
    for(it = words.begin(); it != words.end(); it++)
    {
        outF << *it << endl;
    }
    outF.close();
}