#pragma once
#include <queue>
#include <iostream>
using namespace std;

//FIFO
void QueueTest()
{
	cout << "queue test" << endl;
	queue<int> my_queue;
	my_queue.push(1);
	my_queue.push(2);
	my_queue.push(3);
	my_queue.push(4);
	while(!my_queue.empty())
	{
		cout << my_queue.front() << endl;
		my_queue.pop();
	}
}
