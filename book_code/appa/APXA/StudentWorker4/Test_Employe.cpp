#include "Employee.h"

#include <iostream>
#include <ostream>

using namespace std;

int main() {

  Employee e1("John Smith", "123", "Main St", "AnyCity",
	      "ZZ", "99999-9999", false, 25.);

  Employee e2("Johan Schmidt", "345", "Musterstr", 
	      "Musterstadt", "99999", true, 30.);

  cout << "Employee 1: " << e1.to_string() << '\n';
  cout << "Employee 2: " << e2.to_string() << '\n';
}
