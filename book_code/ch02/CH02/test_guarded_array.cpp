#include "Guarded_Array_X.h"
#include <iostream>
using std::cout;

int main() 
{
  Guarded_Array_X a(10);
  if (a.set_element_of_x(9, 9)) {
    cout << "set_element_of_x(9) succeeded  PASS\n";
  } else {
    cout << "set_element_of_x(9) failed     ****FAIL\n";
  }
  if (a.set_element_of_x(10, 10)) {
    cout << "set_element_of_x(10) succeeded ****FAIL\n";
  } else {
    cout << "set_element_of_x(10) failed    PASS\n";
  }
  int v = a.get_element_of_x(9);
  if (v != INT_MIN) {
    cout << "get_element_of_x(9) succeeded  PASS\n";
  } else {
    cout << "get_element_of_x(9) failed     ****FAIL\n";
  }
  v = a.get_element_of_x(10);
  if (v != INT_MIN) {
    cout << "get_element_of_x(10) succeeded ****FAIL\n";
  } else {
    cout << "get_element_of_x(10) failed    PASS\n";
  }
}
