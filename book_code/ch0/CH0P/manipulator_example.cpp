/* Program to demonstrate the effect of some I/O manipulators. */

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  // showpoint
  cout << "Using showpoint the number 12345.0 " 
       << " is output as " << showpoint << 12345.0 
       << "\nand using noshowpoint it is output as "
       << noshowpoint << 12345.0 << endl;

  // setw
  cout << "Using setw(10) the number 12345 appears as "
       << setw(10) << 12345 << endl;

  // setfill and setw
  cout << "Using setfill('0') and setw(10) 12345 appears as "
       << setfill('0') << setw(10) << 12345 << endl;
  // Reset to blank fill (the default)
  cout << setfill(' ');

  // left, setfill and setw
  cout << "Using left, setfill('*') and setw(10) 12345 appears as "
       << left << setfill('*') << setw(10) << 12345 << endl;
  // Reset to right justification and blank fill (the defaults)
  cout << right << setfill(' ');
}

