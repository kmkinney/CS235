#pragma once
#include <stack>
#include <iostream>
using namespace std;

void StackTest()
{
	cout << "Stack test" << endl;
	stack<int> my_stack;
	my_stack.push(1);
	my_stack.push(2);
	my_stack.push(3);
	my_stack.push(4);
	my_stack.push(5);
	while(!my_stack.empty())
	{
		cout << my_stack.top() << endl;
		my_stack.pop();
	}
}
