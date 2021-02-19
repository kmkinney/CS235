#pragma once
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

template<typename ItemType>
void print(ItemType items) {

 std::cout << '[';

 for (typename ItemType::iterator i = items.begin(); i != items.end(); i++) {
   if (i != items.begin())
     std::cout << ", ";
   std::cout << '\'' << *i << '\'';
 }

 std::cout << ']' << std::endl;

}


template<typename K, typename V>
void print(std::map<K,V> items) {

 std::cout << '{';

 for (typename std::map<K,V>::iterator i = items.begin(); i != items.end(); i++) {
   if (i != items.begin())
     std::cout << ", ";
   std::cout << i->first << '=' << i->second;
 }

 std::cout << '}' << std::endl;

}

/*
    Stores <key, value> pairs

    functions
    insert(key_type key, value_type value)
    erase(key_type key)
    at(key_type key) also []
    empty()
    size()

    C++STL Map
    pair<iterator,bool> insert(pair<key_type, value_type>(key, value));
    int erase (key_type key);
    value_type at(key_type key);
    my_map[key_type key];
    iterator find(key_type key);
    bool empty();
    int size();
    void clear();
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

    //names.insert("aiden", "kinney"); doesn't work
    names.insert(pair<string, string>("aiden", "kinney"));

    print(names);

    unordered_map<string, int> no_order;
}