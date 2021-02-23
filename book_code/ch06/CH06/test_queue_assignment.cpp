#ifdef USESTD
#include <queue>
using std::queue;
#else
#include "queue.h"
using KW::queue;
#endif

#include <iostream>

using std::cout;
using std::endl;

int main() {

  queue<int> queue1;
  for (int i = 0; i < 10; i++) {
    queue1.push(i);
  }

  cout << "Verify initial creation of queue1\n";
  for (int i = 0; i < 10; i++) {
    if (queue1.front() != i) {
      cout << "queue1.front() == " << queue1.front()
	   << " should contain " << i << endl;
      return 1;
    }
    int temp(queue1.front());
    queue1.push(temp);
    queue1.pop();
  }
  cout << "PASSED\n";

  cout << "Verify that verify did not destroy queue1\n";
  for (int i = 0; i < 10; i++) {
    if (queue1.front() != i) {
      cout << "queue1.front() == " << queue1.front()
	   << " should contain " << i << endl;
      return 1;
    }
    int temp(queue1.front());
    queue1.push(temp);
    queue1.pop();
  }
  cout << "PASSED\n";

  queue<int> queue2;
  for (int i = 0; i < 20; i++) {
    queue2.push(i + 100);
  }

  cout << "Verify initial creation of queue2\n";
  for (int i = 0; i < 20; i++) {
    if (queue2.front() != (i + 100)) {
      cout << "queue2.front() == " << queue2.front()
	   << " should contain " << (i + 100) << endl;
      return 1;
    }
    int temp(queue2.front());
    queue2.push(temp);
    queue2.pop();
  }
  cout << "PASSED\n";

  cout << "Verify that verify did not destroy queue2\n";
  for (int i = 0; i < 20; i++) {
    if (queue2.front() != (i + 100)) {
      cout << "queue2.front() == " << queue2.front()
	   << " should contain " << (i + 100) << endl;
      return 1;
    }
    int temp(queue2.front());
    queue2.push(temp);
    queue2.pop();
  }
  cout << "PASSED\n";

  queue2 = queue1;

  cout << "Verify result of assign queue1 to queue2\n";
  for (int i = 0; i < 10; i++) {
    if (queue2.front() != i) {
      cout << "queue2.front() == " << queue2.front()
	   << " should contain " << i << endl;
      return 1;
    }
    queue2.pop();
  }
  
  cout << "Test passed\n";
  return 0;
}
