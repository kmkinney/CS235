#include "Address.h"

#include <iostream>
#include <ostream>

using std::cout;

int main() {

  Address* add1 = new US_Address("123", "Main St", "AnyCity",
                                 "ZZ", "99999-9999");

  Address* add2 = new German_Address("345", "Musterstr", 
                                     "Musterstadt", "99999");

  cout << add1->to_string() << "\n\n";
  cout << add2->to_string() << "\n\n";
}
