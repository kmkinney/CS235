/** Program to illustrate a division by zero error */
#include <iostream>

int main() {
  
  int sum = 1;
  int count = 0;
  double average;
if (count == 0)
  average = 0.0;
else
  average = sum / count;
  std::cout << "average is " << average << "\n";
}
