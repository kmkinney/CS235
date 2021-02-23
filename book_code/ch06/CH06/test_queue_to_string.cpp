#include "queue.h"
#include <string>
#include <iostream>
using KW::queue;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void verify(const string&, const string&);

int main()
{
  queue<int> q;
  // Test 1, empty queue
  verify(q.to_string(), "[]");

  // Test 2, queue with one item
  q.push(5);
  verify(q.to_string(), "[5]");

  // Test 3, queue with two items
  q.push(9);
  verify(q.to_string(), "[5, 9]");

  // Test 3, Queue with three items
  q.push(2);
  verify(q.to_string(), "[5, 9, 2]");

  queue<string> q2;
  q2.push("Thome");
  
  verify(q2.to_string(), "[Thome]");

  q2.push("Abreau");
  q2.push("Jones");
  verify(q2.to_string(), "[Thome, Abreau, Jones]");
  q2.pop();
  verify(q2.to_string(), "[Abreau, Jones]");
  q2.push("Harris");
  verify(q2.to_string(), "[Abreau, Jones, Harris]");

  queue<int> q3;
  for (int i = 0; i < 10; i++)
    q3.push(i);  
  verify(q3.to_string(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");
  q3.move_to_rear1();
  verify(q3.to_string(), "[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]");
  q3.move_to_front1();
  verify(q3.to_string(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");
  q3.move_to_front2();
  verify(q3.to_string(), "[9, 0, 1, 2, 3, 4, 5, 6, 7, 8]");
  q3.move_to_rear2();
  verify(q3.to_string(), "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");

}

void verify(const string& s1, const string& s2)
{
  cout << "Expected " << s2 << " got " << s1;
  if (s1 == s2) {
    cout << " passed\n";
  } else {
    cout << " ******FAILED\n";
  }
}

    
  
