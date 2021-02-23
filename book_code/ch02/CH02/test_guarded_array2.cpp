#include "Guarded_Array_X2.h"
#include <iostream>
using std::cout;

int main() 
{
  Guarded_Array_X a(10);
  try {
    a.set_element_of_x(9, 9);
    cout << "set_element_of_x(9) succeeded  PASS\n";
  } catch (std::out_of_range& ex) {
    cout << ex.what() << '\n';
    cout << "set_element_of_x(9) failed     ****FAIL\n";
  }    
  try {
    a.set_element_of_x(10, 10);
    cout << "set_element_of_x(10) succeeded ****FAIL\n";
  } catch (std::out_of_range& ex) {
    cout << ex.what() << '\n';
    cout << "set_element_of_x(10) failed    PASS\n";
  }
  try {
    int v = a.get_element_of_x(9);
    cout << "get_element_of_x(9) succeeded  PASS\n";
  } catch (std::out_of_range& ex) {
    cout << ex.what() << '\n';
    cout << "get_element_of_x(9) failed     ****FAIL\n";
  }
  try {
    int v = a.get_element_of_x(10);
    cout << "get_element_of_x(10) succeeded ****FAIL\n";
  } catch (std::out_of_range& ex) {
    cout << ex.what() << '\n';
    cout << "get_element_of_x(10) failed    PASS\n";
  }
}
