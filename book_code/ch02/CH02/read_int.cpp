#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>

using namespace std;

/** Method to return an integer data value in response
    to a prompt. If a non-number is entered (as when the
    first character is not a digit) the function will
    prompt for another input after discarding the
    erroneous input.
    @param prompt Message to be displayed
    @return The first valid data value
*/
int read_int(const string& prompt)
{
  cin.exceptions(ios_base::failbit);
  int num = 0;
  while (true) { // Loop until valid input
    try { 
      cout << prompt;
      cin >> num;
      return num;
    } catch (ios_base::failure& ex) {
      cout << "Bad numeric string -- try again\n";
      // Reset the error flag
      cin.clear();
      // Skip current input line
      cin.ignore(numeric_limits<int>::max(), '\n');
    }
  }
}

/** Method to return an integer data value between two
    specified end points.
    pre: min_n <= max_n
    @param prompt Message to be displayed
    @param min_n Smallest value in range
    @param max_n Largest value in range
    @throws invalid_argument if min_n > max_n
    @return The first data value that is in range
*/
int read_int(const string& prompt, int min_n, int max_n)
{
}
