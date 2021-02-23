#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

/** Function to return an integer data value between two
    specified end points.
    pre: min_n <= max_n
    @param prompt Message to be displayed
    @param min_n Smallest value in range
    @param max_n Largest value in range
    @throws invalid_argument if min_n > max_n
    @return The first data value that is in range
*/
int read_int(const string& prompt, int min_n, int max_n) {
  if (min_n > max_n)
    throw invalid_argument("In read_int, min_n not <= max_n");
  bool in_range = false;
  int num = 0;
  while (!in_range) {
    cout << prompt;
    if (cin >> num) {
in_range = min_n <= num <= max_n;
    } else {
      cout << "Bad numeric string -- try again\n";
      // Reset the error flag.
      cin.clear();
      // Skip current input line.
      cin.ignore(numeric_limits<int>::max(), '\n');
    }
  }
  return num;
}
