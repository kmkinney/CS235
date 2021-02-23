#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>

using std::string;
using std::equal;
using std::toupper;
using std::cout;
using std::cin;
using std::endl;

/** Function class to perform case-insensitive comparison
    of characters. */
class Ci_Equal {
  public:
    bool operator()(char c1, char c2) {
      return toupper(c1) == toupper(c2);
    }
};

bool is_palindrome(const std::string& input_string)
{
}

int main()
{

  string line;
  cout << "Enter a string followed by a new line\n"
       << "To quit, enter an empty line:  ";
  while (getline(cin, line) && (line != "")) {
    cout << line << endl;
    if (is_palindrome(line)) {
      cout << "Is a palindrome\n\n";
    } else {
      cout << "Is not a palindrome\n\n";
    }
    cout << "Enter a string: ";
  }
}


