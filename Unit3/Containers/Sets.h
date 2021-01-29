#pragma once
#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool IsWordInSet(string word, set<string>& word_set);
void PrintSetInt(set<int>& int_set);
/*
    A set is an associative container.
    Basic set is sorted, like Java TreeSet<>
    All items in a set must be unique
    Not indexed
    Notated with {}
    Is a member notation ∈
    A union of two sets is a set of all elements found in either set (write with a U)
    Intersection (A ⋂ B) is the set of all elements found in both sets
    Difference of sets A-B is set of elements in A that are not in B
    A is a subset of B (A ⊆ B) if every element of A is a member of B
*/

/*
    Set functions
    pair<iterator,bool> insert(<type> val);
        iterator is position of object, bool is whether it was added
    int erase(<type> val);
    void clear();
    iterator find(<type> val);
    int size();
    bool empty();
*/
void SetTest()
{
    cout << "Set test" << endl;
    set<string> words;
    words.insert("a");
    words.insert("b");
    words.insert("c");
    words.insert("d");
    words.insert("e");

    //iterating
    set<string>::iterator it;
    for(it = words.begin(); it != words.end(); it++)
    {
        cout << *it << endl;
    }

    cout << IsWordInSet("f", words) << endl;


    set<int> s1;
    set<int> s2;

    s1.insert(1);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);

    s2.insert(1);
    s2.insert(6);

    set<int> union_set;
    
    //Create a union of 2 sets
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), 
        inserter(union_set, union_set.begin()));
    
    PrintSetInt(s1);
    PrintSetInt(s2);
    PrintSetInt(union_set);


    //Other types of sets
    unordered_set<string> words_unordered;
}

bool IsWordInSet(string word, set<string>& word_set)
{
    return word_set.find(word) != word_set.end();
}

void PrintSetInt(set<int>& int_set)
{
    set<int>::iterator it;
    for(it = int_set.begin(); it != int_set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}