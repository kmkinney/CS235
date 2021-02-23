/** Program to test the Directory_Entry class */
#include "Directory_Entry.h"
#include <iostream>
using std::cout;

int main()
{
// Create some directory entries.
Directory_Entry tom("Tom", "123-555-4567");
Directory_Entry dick("Dick", "321-555-9876");
// Display the entries.
cout << "tom -- name: " << tom.get_name()
     << " number: " << tom.get_number() << '\n';
cout << "dick -- name: " << dick.get_name()
     << " number: " << dick.get_number() << '\n';
// See if they are equal.
if (tom == dick) 
  cout << "FAILURE -- tom and dick are equal\n";
else
  cout << "SUCCESS -- tom and dick are not equal\n";
if (dick == tom)
  cout << "FAILURE -- tom and dick are equal\n";
else
  cout << "SUCCESS -- tom and dick are not equal\n";
// Create another directory entry.
Directory_Entry tom2("Tom", "888-555-9999");
cout << "tom2 -- name: " << tom2.get_name()
     << " number: " << tom2.get_number() << '\n';
// See whether the two toms are equal.
if (tom == tom2)
  cout << "SUCCESS -- tom and tom2 are equal\n";
else 
  cout << "FAILURE -- tom and tom2 are not equal\n";
if (tom2 == tom)
  cout << "SUCCESS -- tom and tom2 are equal\n";
else 
  cout << "FAILURE -- tom and tom2 are not equal\n";
dick.set_number(tom.get_number());
// Dick and Tom should have the same number
cout << "dick -- name: " << dick.get_name()
     << " dick -- number: " << dick.get_number() << '\n';
}
