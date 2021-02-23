#include <iostream>
#include "stack.h"
using std::cout;
using std::endl;
using KW::stack;

int main()
{
  stack<int> the_stack;
  for (int i = 0; i < 10; i++)
    the_stack.push(i);
  if (the_stack.size() == 10) {
    cout << "Size test PASSED" << endl;
  } else {
    cout << "Size test ******FAILED\n"
	 << "expected 10 got " << the_stack.size() << endl;
  }
  //  cout << "the_stack == " << the_stack.to_string() << endl;
  stack<int> s2;
  //  cout << "s2 == " << s2.to_string() << endl;
  try {
    // int k = s2.next_to_top();
    // cout << "Expected an exception got " << k << endl;
    cout << "next_to_top on empty stack *******FAILED\n";
  } catch (std::out_of_range& ex) {
    cout << "next_to_top on empty stack PASSED\n";
  }
  s2.push(10);
  try {
    //int k = s2.next_to_top();
    //cout << "Expected an exception got " << k << endl;
    cout << "next_to_top on stack size 1 *******FAILED\n";
  } catch (std::out_of_range& ex) {
    cout << "next_to_top on stack size 1 PASSED\n";
  }
  // cout << "s2 == " << s2.to_string() << endl;
  s2 = the_stack;
  cout << "After assignment\n";
  //cout << "s2 == " << s2.to_string() << endl;
  //if (s2.next_to_top() == 8) {
  //  cout << "next_to_top size >= 2 PASSED\n";
  //} else {
  //  cout << "Expected 8 got " << s2.next_to_top() << endl;
    cout << "next_to_top size >= 2 ********FAILED\n";
    //}
  bool passed = true;
  for (int i = 9; i >= 0; i--) {
    if (i != the_stack.top()) {
      cout << "Expected " << i << " got " << the_stack.top() << endl;
      passed = false;
    }
    the_stack.pop();
  }
  if (passed) {
    cout << "Push and pop test PASSED\n";
  } else {
    cout << "Push and pop test ******FAILED\n";
  }
  passed = true;
  for (int i = 9; i >= 0; i--) {
    if (i != s2.top()) {
      cout << "Expected " << i << " got " << s2.top() << endl;
      passed = false;
    }
    s2.pop();
  }
  if (passed) {
    cout << "Assignment test PASSED\n";
  } else {
    cout << "Assignment test ******FAILED\n";
  }
  if (the_stack.empty()) {
    cout << "Empty test PASSED\n";
  } else {
    cout << "Empty test ******FAILED\n";
  }

  //int test_values[] = {10, 20, 30, 40};
  //stack<int> s3(test_values, test_values+4);
  //cout << "s3 == " << s3.to_string();

}
