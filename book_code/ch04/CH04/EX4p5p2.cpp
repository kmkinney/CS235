/** Program to demonstrate manipulations of the double linked
    list node
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace KW {
  
  /** Dummy template class to encapsulate the DNode class */
  template <typename Item_Type>
  class DLL
  {
  public:
#include "DNode.h"
  };
} 

typedef KW::DLL<string>::DNode DNode;

void print_list(DNode* node)
{
  if (node) {
    if (node->prev && node->prev->next != node) {
      cout << node->prev->data << " <== ";
    }
    cout << node->data;
    if (node->next) {
      if (node->next->prev == node) {
	cout << " <=> ";
      } else {
	cout << " ==> ";
      }
      print_list(node->next);
    }
  } else {
    cout << "NULL";
  }
  cout << endl;
}

int main()
{
  DNode* tom = new DNode("Tom");
  DNode* dick = new DNode("Dick");
  DNode* harry = new DNode("Harry");
  DNode* sam = new DNode("Sam");
  
  tom->next = dick;
  dick->prev = tom;
  dick->next = harry;
  harry->prev = dick;
  harry->next = sam;
  sam->prev = harry;
  
  DNode* head = tom;
  DNode* tail = sam;
}
