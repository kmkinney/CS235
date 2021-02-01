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
void ReadWordsToSet(set<string> &word_set, string file_name);
void PrintVectorToFile(vector<string> &words, string file_name);
void PrintSetToFile(set<string> &word_set, string file_name);
void PrintMapToFile(map<string, string> &word_map, string file_name);
void MakePhraseMap(map<list<string>, vector<string>> &phrase_map, vector<string> &words);
void GenerateTextFromPhraseMap(map<list<string>, vector<string>> &phrase_map, vector<string> &words);

const int M = 2;

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        //Read file name from command line
        string file_name = argv[1];
        vector<string> words;
        set<string> word_set;

        //Read words to a set, then output set to a file
        ReadWordsToSet(word_set, file_name);
        PrintSetToFile(word_set, file_name + "_set.txt");

        //Read words to a vector, then output vector to a file
        ReadWordsToVector(words, file_name);
        PrintVectorToFile(words, file_name + "_vector.txt");

        //Create a map storing each word and the last word that follows it
        
        map<string, string> word_map;
        string last;
        vector<string>::iterator it;
        for(it = words.begin(); it != words.end(); it++)
        {
            word_map[last] = *it;
            last = *it;
        }
        PrintMapToFile(word_map, file_name + "_map.txt");

        //100 word text generation
        last = "";
        for(int i = 0; i < 100; i++)
        {
            cout << word_map[last] << " ";
            last = word_map[last];
        }
        cout << endl << endl;

        //create a map that maps each word to a vector of strings that follow it
        map<string, vector<string>> vector_map;
        last = "";
        for(it = words.begin(); it != words.end(); it++)
        {
            vector_map[last].push_back(*it);
            last = *it;
        }

        //Printing the 6th entry to the terminal
        map<string, vector<string>>::iterator mp_it = vector_map.begin();
        advance(mp_it, 5);
        cout << "6th entry vector contents:" << endl;
        for(it = mp_it->second.begin(); it != mp_it->second.end(); it++)
        {
            if(next(it) == mp_it->second.end())
                cout << *it;
            else
                cout << *it << ", ";
        }
        cout << endl << endl;

        //Generate new radom text
        srand(time(NULL));

        last = "";
        for(int i = 0; i < 100; i++)
        {
            int ind = rand() % vector_map[last].size();
            cout << vector_map[last][ind] << " ";
            last = vector_map[last][ind];
        }
        cout << endl << endl;
        
        //Using multiple word context
        map<list<string>, vector<string>> phrase_map;
        MakePhraseMap(phrase_map, words);

        //Generating text based off of the phrase map
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
    for(int i = 0; i < 100; i++)
    {
        if(phrase_map[state].size() > 0)
        {
            int ind = rand() % phrase_map[state].size();
            cout << phrase_map[state][ind] << " ";
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

void PrintMapToFile(map<string, string> &word_map, string file_name)
{
    ofstream outF(file_name);
    map<string, string>::iterator it;
    for(it = word_map.begin(); it != word_map.end(); it++)
    {
        outF << it->first << ", " << it->second << endl;
    }
    outF.close();
}