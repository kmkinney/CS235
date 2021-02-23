#include "list_with_allocator.h"

#include <iostream>
#include <ostream>
using std::cout;
using KW::list;

template <typename Item_Type>
void print_list(const list<Item_Type>& a_list)
{
  typename list<Item_Type>::const_iterator iter = a_list.begin();
  while (iter != a_list.end()) {
    cout << *iter;
    ++iter;
    if (iter != a_list.end())
      cout << "  ==>  ";
  }
  cout << '\n';
}

int main() {

 KW::list<int> test_list1;
 for (int i = 0; i < 20; i++)
   test_list1.push_back(i);
 print_list(test_list1);
 bool passed = true;
 int j = 0;
 for (KW::list<int>::iterator itr = test_list1.begin();
      itr != test_list1.end(); ++itr) {
   if (*itr != j) {
     cout << "Expected " << j << " got "
	  << *itr << '\n';
     passed = false;
   }
   j++;
   if (j > test_list1.size()) {
     cout << "Iterator failed to indicate end\n";
     passed = false;
   }
 }
 if (passed) 
   cout << "push_front and iterator test passed\n";
 KW::list<int> test_list2 = test_list1;
 print_list(test_list2);
 j = 0;
 for (KW::list<int>::iterator itr = test_list2.begin();
      itr != test_list2.end(); ++itr) {
   if (*itr != j) {
     cout << "Expected " << j << " got "
	  << *itr << '\n';
     passed = false;
   }
   j++;
   if (j > test_list2.size()) {
     cout << "Iterator failed to indicate end\n";
     passed = false;
   }
 }
 if (passed) 
   cout << "Copy Constructor passed\n";
 passed = true;
 for (int i = 0; i < 20; i++) {
   if (test_list1.front() != i) {
     cout << "Expected " << i << " got " <<
       test_list1.front() << '\n';
     passed = false;
   }
   test_list1.pop_front();
 }
 if (passed && test_list1.size() == 0) {
   cout << "Test of push_front/pop_front passed\n";
 }
 print_list(test_list1);
 test_list1 = test_list2;
 print_list(test_list1);
 j = 0;
 for (KW::list<int>::iterator itr = test_list1.begin();
      itr != test_list1.end(); ++itr) {
   if (*itr != j) {
     cout << "Expected " << j << " got "
	  << *itr << '\n';
     passed = false;
   }
   j++;
   if (j > test_list1.size()) {
     cout << "Iterator failed to indicate end\n";
     passed = false;
   }
 }
 if (passed) 
   cout << "Assignment operator passed \n";
 KW::list<int> test_list3;
 for (int i = 0; i < 20; i += 2)
   test_list3.push_back(i);
 KW::list<int>::iterator itr2 = test_list3.begin();
 for (int i = 1; i < 20; i += 2) {
   ++itr2;
   itr2 = test_list3.insert(itr2, i);
   ++itr2;
 }
 j = 0;
 for (KW::list<int>::iterator itr = test_list3.begin();
      itr != test_list1.end(); ++itr) {
   if (*itr != j) {
     cout << "Expected " << j << " got "
	  << *itr << '\n';
     passed = false;
   }
   j++;
   if (j > test_list3.size()) {
     cout << "Iterator failed to indicate end\n";
     passed = false;
   }
 }
 if (passed) 
   cout << "Insert test passed\n";
 for (int i = 19; i >= 0; i--) {
   if (i != test_list3.back()) {
     cout << "Expected " << i << " got " << test_list3.back()
	  << '\n';
     passed = false;
   }
   test_list3.pop_back();
 }
 if (passed) 
   cout << "Pop_back test passed\n";
 return 0;
}

// void print_list(const list<int>& a_list)
// {
//   list<int>::const_iterator iter = a_list.begin();
//   while (iter != a_list.end()) {
//     cout << *iter;
//     ++iter;
//     if (iter != a_list.end())
//       cout << "  ==>  ";
//   }
//   cout << '\n';
// }

