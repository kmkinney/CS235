/** Program to test the deque */

#include <deque>
#include <iostream>
#include "deque.h"
using std::cout;
using std::endl;

void verify(const std::deque<int>& d1, const KW::deque<int>& d2);

int main() {

  std::deque<int> std_deque;
  KW::deque<int> KW_deque;


  cout << "push_back test\n";
  // Insert some values to the back
  for (int i = 0; i < 100; i++) {
    std_deque.push_back(i);
    KW_deque.push_back(i);
  }

  // See if they are the same
  verify(std_deque, KW_deque);

  cout << "pop_front test\n";
  bool passed = true;
  // Remove and verify from front
  while (!KW_deque.empty()) {
    if (KW_deque.front() != std_deque.front()) {
      cout << "*****FAIL expected " << std_deque.front()
	   << " got " << KW_deque.front() << endl;
    }
    KW_deque.pop_front();
    std_deque.pop_front();
  }
  if (passed)
    cout << "PASSED\n";


  cout << "push_back test\n";
  // Insert some values to the back
  for (int i = 0; i < 100; i++) {
    std_deque.push_back(i);
    KW_deque.push_back(i);
  }

  // See if they are the same
  verify(std_deque, KW_deque);

  cout << "pop_back test\n";
  passed = true;
  // Remove and verify from back
  while (!KW_deque.empty()) {
    if (KW_deque.back() != std_deque.back()) {
      cout << "*****FAIL expected " << std_deque.back()
	   << " got " << KW_deque.back() << endl;
    }
    KW_deque.pop_back();
    std_deque.pop_back();
  }
  if (passed)
    cout << "PASSED\n";

  cout << "push_front test\n";
  // Insert some values to the front
  for (int i = 100; i < 200; i++) {
    std_deque.push_front(i);
    KW_deque.push_front(i);
  }

  // See if they are the same
  verify(std_deque, KW_deque);

  cout << "pop_front test\n";
  passed = true;
  // Remove and verify from front
  while (!KW_deque.empty()) {
    if (KW_deque.front() != std_deque.front()) {
      cout << "*****FAIL expected " << std_deque.front()
	   << " got " << KW_deque.front() << endl;
    }
    KW_deque.pop_front();
    std_deque.pop_front();
  }
  if (passed)
    cout << "PASSED\n";
  
  cout << "push_front test\n";
  // Insert some values to the front
  for (int i = 100; i < 200; i++) {
    std_deque.push_front(i);
    KW_deque.push_front(i);
  }
  
  // See if they are the same
  verify(std_deque, KW_deque);

  cout << "pop_back test\n";
  passed = true;
  // Remove and verify from back
  while (!KW_deque.empty()) {
    if (KW_deque.back() != std_deque.back()) {
      cout << "*****FAIL expected " << std_deque.back()
	   << " got " << KW_deque.back() << endl;
    }
    KW_deque.pop_back();
    std_deque.pop_back();
  }
  if (passed)
    cout << "PASSED\n";


  cout << "alternate push and pop test\n";
  // Alternate insertion and removal
  for (int i = 1000; i < 1100; i++) {
    switch (i % 4) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      std_deque.pop_front();
      KW_deque.pop_front();
      break;
    case 3:
      std_deque.pop_back();
      KW_deque.pop_back();
      break;
    default:
      break;
    }
    std_deque.push_front(i);
    std_deque.push_back(i + 100);
    KW_deque.push_front(i);
    KW_deque.push_back(i + 100);
  }
  
  // See if they are the same
  verify(std_deque, KW_deque);

  return 0;
  
}

void verify(const std::deque<int>& d1, const KW::deque<int>& d2) {
  bool passed = true;

  if (d1.size() != d2.size()) {
    cout << "**** Fail size not the same\n"
	 << "Expected " << d1.size()
	 << " got " << d2.size() << endl;

    passed = false;
  }

  for (size_t i = 0; i < d1.size(); i++) {
    if (d1[i] != d2[i]) {
      cout << "**** FAIL Expected " << d1[i]
	   << " got " << d2[i] << endl;
      passed = false;
    }
  }
  if (passed) {
    cout << "PASSED    deques are the same\n";
  }
}



