/** Program to illustrate a division by zero error */
#include <iostream>

int main() {

  double sum = 1.0;
  double count = 0.0;
  double average = sum / count;

  std::cout << "average is " << average << "\n";
}
