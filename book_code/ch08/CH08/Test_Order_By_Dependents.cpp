#include <vector>
#include <iostream>
#include "Random.h"
#include "priority_queue.h"
#include "Person.h"
#include "Order_By_Dependents.h"

using std::cout;
using std::endl;
using KW::priority_queue;
using std::vector;

int main()
{
  Random random;
  priority_queue<Person, vector<Person>, Order_By_Dependents> pq;
  for (int i = 0; i < 100; i++) {
    int num = random.next_int(1000);
    Person p;
    p.set_number_dependents(num);
    pq.push(p);
  }
  vector<Person> v;
  while(!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  bool passed = true;
  for (size_t i = 1; i < v.size(); i++) {
    if(v[i - 1].get_number_dependents() < v[i].get_number_dependents()) {
      passed = false;
      cout << "Data out of order " << v[i -1].get_number_dependents()
	   << " " << v[i].get_number_dependents() << endl;
    }
  }
  if (passed) 
    cout << "PASSED\n";
  else
    cout << "******FAILED\n";
}
