/** Program to test case-insensitive string class */

#include "ci_string.h"
#include <iostream>
using namespace std;

int main()
{

  ci_string s1 = "AbCdEfG";
  ci_string s2 = "aBcDeFg";

  // ci_strings s1 and s2 should be equal
  if (s1 == s2) {
    cout << "PASS     " << s1.c_str() << " == " 
	 << s2.c_str() << endl;
  } else {
    cout << "**** FAIL" << s1.c_str() << " == " 
	 << s2.c_str() << endl;
  }
  ci_string s3 = "aBcD";
  // ci_string s1 should be > ci_string s3
  if (s1 > s3) {
    cout << "PASS     " << s1.c_str() << " > " 
	 << s3.c_str() << endl;
  } else {
    cout << "**** FAIL" << s1.c_str() << " > " 
	 << s3.c_str() << endl;
  }
  // ci_string s3 should be < ci_string s1
  if (s3 < s1) {
    cout << "PASS     " << s3.c_str() << " < " 
	 << s1.c_str() << endl;
  } else {
    cout << "**** FAIL" << s3.c_str() << " < " 
	 << s1.c_str() << endl;
  }
  // The letter 'D' should be at pos 3 in ci_string s1
  if (s1.find('D') == 3) {
    cout << "PASS     " << "Found D as pos 3 in "
	 << s1.c_str() << endl;
   } else { 
     cout << "**** FAIL" << "Did not find D at pos 3 in "
	  << s1.c_str() << endl;
   }
  // The letter 'X' should not be in ci_string s1
  if (s1.find('X') == string::npos) {
    cout << "PASS     " << "Did not find X in ci_string "
	 << s1.c_str() << endl;
  } else {
    cout << "**** FAIL" << "Found X in ci_sting "
	 << s1.c_str() << " at pos " << s1.find('X') << endl;
  }
}
