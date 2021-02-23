/** Program to check an expression for balanced parentheses. */

#include <stack>
#include <string>
#include <iostream>
using namespace std;

// The set of opening parentheses.
const string OPEN = "([{";
// The corresponding set of closing parentheses.
const string CLOSE = ")]}";

/** Function to determine whether a character is one of the opening
    parentheses (defined in constant OPEN).
    @param ch Character to be tested
    @return true If the character is an opening parenthesis
*/
bool is_open(char ch) {
  return OPEN.find(ch) != string::npos;
}

/** Function to determine whether a character is one of the closing
    parentheses (defined in constant CLOSE).
    @param ch Character to be tested
    @return true If the character is a closing parenthesis
*/
bool is_close(char ch) {
  return CLOSE.find(ch) != string::npos;
}

/** Test the input string to see that it contains balanced
    parentheses. This function tests an input string to
    see that each type of parenthesis is balanced. '(' is
    matched with ')', '[' is matched with ']', and '{' is
    matched with '}'.
    @param expression A string containing the expression to be examined
    @return true if all parentheses match
*/
bool is_balanced(const string& expression) {
  // A stack for the open parentheses that haven't been matched
  stack<char> s;
  bool balanced = true;
  string::const_iterator iter = expression.begin();
  while (balanced && (iter != expression.end())) {
    char next_ch = *iter;
    if (is_open(next_ch)) {
      s.push(next_ch);
    } else if (is_close(next_ch)) {
      if (s.empty()) {
        balanced = false;
      } else {
        char top_ch = s.top();
        s.pop();
        balanced = 
          OPEN.find(top_ch) == CLOSE.find(next_ch);
      }
    }
    ++iter;
  }
  return balanced && s.empty();
}

/** Main function to test is_balanced. */
int main() {
  cout << "Enter an expression\n";
  string expression;
  while (getline(cin, expression) && (expression != "")) {
    cout << expression;
    if (is_balanced(expression)) {
      cout << " is balanced\n";
    } else {
      cout << " is not balanced\n";
    }
    cout << "Enter another expression: ";
  }
  return 0;
}
