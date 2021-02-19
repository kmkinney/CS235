#pragma once
#include <queue>
#include <iostream>
using namespace std;

//Double Ended Queue
void PriorityQueueTest()
{
	cout << "Priority Queue Test" << endl;
	priority_queue<int> my_queue;
	/* Priority Queue functions
		void push(<type> item);
		void pop();
		<type> top();
		bool empty();
		int size();
	*/
	my_queue.push(1);
	my_queue.push(10);
	my_queue.push(45);
	my_queue.push(300);
	my_queue.push(-1);
	//Will print out in descending order
	while(!my_queue.empty())
	{
		cout << my_queue.top() << endl;
		my_queue.pop();
	}
	//custom comparator
	
	class my_compare
	{
		private:
			bool reverse;
		public:
			my_compare(bool r) : reverse(r){};
			bool operator() (int &lhs, int &rhs)
			{
				if(reverse)
					return (lhs > rhs);
				else
					return (lhs < rhs);
			}
	};
	//reversing priority queue
	cout << "reversed" << endl;
	priority_queue<int, deque<int>, my_compare> rpq(my_compare(true));
	rpq.push(300);
	rpq.push(-300);
	rpq.push(30);
	rpq.push(350);
	rpq.push(330);
	rpq.push(10); 
	while(!rpq.empty())
	{
		cout << rpq.top() << endl;
		rpq.pop();
	}
	
}
