#pragma once
#include <deque>
#include <iostream>
using namespace std;

//Double Ended Queue
void DequeTest()
{
	cout << "Deque Test" << endl;
	deque<int> my_deque;
	/* Deque functions
		void push_back(<type> item);
		void push_front(<type> item);
		void pop_back();
		void pop_front();
		<type> front();
		<type> back();
		<type> at(int index);
		iterator insert(int position, <type> item);
		iterator erase(int position);
		int size();
		bool empty();
	*/
	//Good to use if you are adding to and from beginnings and ends a lot
	my_deque.push_front(0);
	my_deque.push_back(1);
	my_deque.push_front(-1);
	cout << my_deque[0] << endl;
}
