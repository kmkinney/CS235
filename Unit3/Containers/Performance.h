#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;

void PerformanceTest()
{
	cout << "performance test" << endl;
	cout << "Insertion" << endl;
	vector<string> my_strings;
	int n = 40000;
	for(int i = 0; i < n; i++)
	{
		my_strings.insert(my_strings.end(), "Hello"); 
		//using .begin() runs for 6 seconds, .end() runs instantly
	}
	
	list<string> my_list;
	for(int i = 0; i < n; i++)
	{
		my_list.insert(my_list.begin(), "Hello"); //runs almost instantly
	}
	
	cout << "access" << endl;
	cout << "vector" << endl;
	n = 40000000;
	string value;
	for (int i = 0; i < n; i++)
	{
		vector<string>::iterator middle = my_strings.begin();
		advance(middle, my_strings.size() / 2);
		value = *middle;
	}
	cout << "linked list" << endl;
	//won't finish, takes too long
	for (int i = 0; i < n; i++)
	{
		list<string>::iterator middle = my_list.begin();
		//advance(middle, my_list.size() / 2);
		value = *middle;
	}
		
}
