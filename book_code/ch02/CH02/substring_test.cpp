/** Program to demonstrate the out_of_range exception thrown
    by the string.substr function if the start index is greater
    than the length of the string.
*/
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

int main() {
  // Enter a string and substring start index.
  string a_string;
  int start_pos;
  cout << "Type in a string: ";
  getline(cin, a_string);
  cout << "Enter start position of a substring: ";
  cin >> start_pos;

  try {
    cout << "The substring is "
         << a_string.substr(start_pos) << endl;
    return 0;
  } catch (out_of_range& ex) {
    cerr << "*** Out_of_range exception thrown for start position " 
         << start_pos << "\n"
         << ex.what() << endl;
    return 1;
  }
} 
