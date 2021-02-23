/** Program to maintain a queue of customers.
 *  @author Koffman and Wolfgang
 */

#include "queue.h"
#include <string>
#include <iostream>
using KW::queue;
using std::string;
using std::cin;
using std::cout;
using std::endl;

/** Performs the operations selected on queue customers.
    pre:  customers has been created.
    post: customers is modified based on user selections.
*/
int main()
{
  queue<string> customers;
  int choice_num = 0;
  string choices[] = {
    "push", "front", "pop", "size", "quit"};
  const int NUM_CHOICES = 5;
  
  // Perform all operations selected by user.
  while (choice_num < NUM_CHOICES - 1) {
    // Select the next operation.
    cout << "Select an operation on customer queue\n";
    for (int i = 0; i < NUM_CHOICES; i++) {
      cout << i << ": " << choices[i] << endl;
    }
    string name;
    cin >> choice_num;
    switch (choice_num) {
    case 0:
      cout << "Enter new customer name\n";
      cin >> name;
      customers.push(name);
      break;
    case 1:
      cout << "Customer " << customers.front() 
	   << " is next in line\n";
      break;
    case 2:
      cout << "Customer " << customers.front()
	   << " removed from line\n";
      customers.pop();
      break;
    case 3:
      cout << "Size of line is " << customers.size() << endl;
      break;
    case 4:
      cout << "Leaving customer queue.\n"
	   << "Number of customers in queue is " << customers.size() << endl;
      break;
    default:
      cout << "Invalid selection\n";
      break;
    }
  } // End while.
  return 0;
}
