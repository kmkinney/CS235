#include <string>
#include <stack>
#include <iostream>
#include <sstream>

using std::string;
using std::stack;
using std::istringstream;
using std::cin;
using std::cout;
using std::getline;
using std::endl;

string reverse_words(const string& in)
{
}

int main()
{
  string line;
  while (getline(cin, line)) {
    cout << line << endl;
    cout << reverse_words(line) << endl << endl;
  }
}

