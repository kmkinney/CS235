/*<exercise chapter="2" section="3" type="programming" number="1">*/
/** Program to test read_int */
#include <iostream>
#include <string>
#include <stdexcept>
#include <ios>
#include <sstream>
#include <limits>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::ios_base;
using std::ostringstream;
using std::numeric_limits;

int read_int(const string&);
int read_int(const string&, int, int);

void do_test(int min_n, int max_n)
{
  ostringstream pstring;
  pstring << "Enter a number between " << min_n << " and " << max_n << ": ";
  string prompt = pstring.str();
  int i;
  /*<exercise chapter="2" section="2" type="programming" number="3">*/
  try {
    i = read_int(prompt, min_n, max_n);
  } catch (invalid_argument& ex) {
    cout << "Invalid argument " << ex.what() << endl;
  } catch (ios_base::failure& ex) {
    cout << "I/O failure " << ex.what() << endl;
    cin.clear();
  } catch (std::exception& ex) {
    cout << "other standard exception " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception\n";
  }
  /*</exercise>*/
  cout << "The number entered is " << i << endl;
}

int main()
{
  // Test the single parameter version
  int i = read_int("Enter a number between 1 and 10: ");
  cout << "The number entered is " << i << endl;

  // Test 1 of the 3 parameter version
  cout << "This should throw invalid_argument exception\n";
  do_test(5, 1);

  // Test 2 and 3
  cout << "Enter .5 in response to prompt, report bad numeric string\n";
  cout << "Next enter a 2, should work fine\n";
  do_test(1, 5);

  // Test 4
  cout << "Enter -1 in response to prompt, should repeat prompt\n";
  cout << "Enter EOF in response to prompt, should throw ios_base::failure\n";
  do_test(1, 5);

  // Test 5
  cout << "Enter a 3, there should be an empty prompt" << endl;
  i = read_int("", 1, 5);
  cout << "Number entered is " << i << endl;

  // Test 6
  cout << "Enter a 1, should repeat prompt\n";
  cout << "Enter a 0, should work fine\n";
  do_test(0, 0);

  // Test 7
  cout << "Enter a 0, should work fine\n";
  do_test(-10, 5);
}
/*</exercise>*/
