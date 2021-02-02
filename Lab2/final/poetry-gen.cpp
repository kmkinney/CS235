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

const int M = 2;
const int NUM_WORDS = 200;
const int MAX_LINE_LENGTH = 15;

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
    //added random start
    int rand_ind = rand() % (words.size() - M);
    for(int i = 0; i < M; i++)
    {
        state.push_back(words[rand_ind]);
        rand_ind++;
    }
    ofstream outF("output.txt");
    string line;
    int word_count = 0;
    for(int i = 0; i < NUM_WORDS; i++)
    {
        string curr;
        if(phrase_map[state].size() > 0)
        {
            int ind = rand() % phrase_map[state].size();
            curr = phrase_map[state][ind];
            word_count++;
            if(curr.compare("\n") == 0){
                outF << line << endl;
                line = "";
                word_count = 0;
            }
            else if(curr.compare(".") == 0 || curr.compare(",") == 0){
                line = line.substr(0, line.length()-1) + curr + " ";
            }
            else if(word_count >= MAX_LINE_LENGTH){
                line += curr + " ";
                outF << line << endl;
                line = "";
                word_count = 0;
            }
            else{
                line += curr + " ";
            }
            state.push_back(curr);
            state.pop_front();
        }
        else
        {
            state.clear();
            rand_ind = rand() % (words.size() - M);
            for(int i = 0; i < M; i++)
            {
                state.push_back(words[rand_ind]);
                rand_ind++;
            }
        }
    }
    outF << line;
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
            string punct = "";
            for(auto &c:token){
                //include punctuation at end of words
                if(isalpha(c)){
                    nopunct += tolower(c);
                }
                else if(c == '.' | c == ',' ){
                    punct += c;
                }
            }
            words.push_back(nopunct);
            if(!punct.empty())
                words.push_back(punct);
        }
        words.push_back("\n");
    }
    inF.close();
}