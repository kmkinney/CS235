/** Program to test read_int */
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int read_int(const string&, int, int);

int main()
{
  int i = read_int("Enter a number between 1 and 10: ", 1, 10);
  cout << "The number entered is " << i << endl;
}
