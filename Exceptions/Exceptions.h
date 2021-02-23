#pragma once
#include <iostream>
#include <vector>
using namespace std;

void thrower(){
    string message = "something wrong";
    throw message;
}

void Exceptions(){
    /*
    try{
        thrower();
    } catch(string err){
        cout << err << endl;
    }*/
    try{
        vector<int> list(5);
        cout << list.at(10);
    } catch(const exception& e){
        cout << e.what() << endl;
    }
}