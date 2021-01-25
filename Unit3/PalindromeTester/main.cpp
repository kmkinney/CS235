#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsPalindrome(string word);

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        string word = argv[1];
        bool is_palindrome = IsPalindrome(word);
        if(is_palindrome)
            cout << word << " is a palindrome." << endl;
        else
            cout << word << " is not a palindrome." << endl;
    }
    else
    {
        cout << "Pass a single word to test if it is a palindrome" << endl;
        return 1;
    }
    return 0;
}

bool IsPalindrome(string word)
{
    stack<char> letters;
    string::iterator itr;
    //push half the letters onto the stack (rounds up for odd numbers)
    for(itr = word.begin(); itr+(word.size()/2) != word.end(); itr++)
    {
        letters.push(*itr);
    }
    //If odd length, ignore the middle letter
    if(word.size() % 2 != 0)
        letters.pop();
    
    //test the stack against the second half of the word, if equal the word is a palindrome
    while(!letters.empty())
    {
        if(itr == word.end() || letters.top() != *itr)
            return false;
        letters.pop();
        itr++;
    }
    return true;
}