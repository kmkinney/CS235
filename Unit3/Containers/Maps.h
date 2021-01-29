#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
    Stores <key, value> pairs

    functions
    insert(key_type key, value_type value)
    erase(key_type key)
    at(key_type key)
    empty()
    size()
*/
void MapTest()
{
    cout << "Map Test" << endl;
    map<string, string> names;
    
    //ways to insert
    pair<string, string> my_pair;
    my_pair.first = "kevin";
    my_pair.second = "kinney";
    names.insert(my_pair);
    cout << names["kevin"] << endl;

    names["gretchen"] = "kinney";
    cout << names["gretchen"] << endl;
}