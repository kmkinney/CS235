#include <iostream>
using std::cout;

void test_function(char a, char b) {
  if (a < 'M') {
    if (b < 'X') {
      cout << "Path 1\n";
    } else {
      cout << "Path 2\n";
    }
  } else { 
    if (b < 'C') {
      cout << "Path 3\n";
    } else {
      cout << "Path 4\n";
    }
  }
}
