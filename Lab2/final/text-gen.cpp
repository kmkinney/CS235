#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

void ReadWordsToVector(vector<string> &words, string file_name);
void MakePhraseMap(map<list<string>, vector<string>> &phrase_map, vector<string> &words);
void GenerateTextFromPhraseMap(map<list<string>, vector<string>> &phrase_map, vector<string> &words);

const int M = 4;
const int NUM_WORDS = 200;

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        //Read file names from command line
        string file_name;
        vector<string> words;

        //Combining files
        for(int i = 1; i < argc ; i++)
        {  
            file_name = argv[i];
            ReadWordsToVector(words, file_name);
        }

        
        map<list<string>, vector<string>> phrase_map;
        MakePhraseMap(phrase_map, words);

        GenerateTextFromPhraseMap(phrase_map, words);

    }
    return 0;
}


void MakePhraseMap(map<list<string>, vector<string>> &phrase_map, vector<string> &words)
{
    list<string> state;
    for(int i = 0; i < M; i++)
    {
        state.push_back("");
    }
    for(vector<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        phrase_map[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }
}

void GenerateTextFromPhraseMap(map<list<string>, vector<string>> &phrase_map, vector<string> &words)
{
    srand(time(NULL));
    list<string> state;
    state.clear();
    //added random start
    int rand_start = rand() % (words.size() - M);
    for(int i = 0; i < M; i++)
    {
        state.push_back(words[rand_start]);
        rand_start++;
    }
    ofstream outF("output.txt");
    for(int i = 0; i < NUM_WORDS; i++)
    {
        if(phrase_map[state].size() > 0)
        {
            int ind = rand() % phrase_map[state].size();
            outF << phrase_map[state][ind];
            if(phrase_map[state][ind].compare("\n") != 0)
                outF << " ";
            state.push_back(phrase_map[state][ind]);
            state.pop_front();
        }
        else
        {
            state.clear();
            for(int i = 0; i < M; i++)
            {
                state.push_back("");
            }
        }
    }
    outF.close();
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
                //include punctuation at end of words
                if(isalpha(c) | c == '.' | c == ',' | c == '\"' | c == '\''){
                    nopunct += c;
                }
            }
            words.push_back(nopunct);
        }
        words.push_back("\n");
    }
    inF.close();
}