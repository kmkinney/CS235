#include <string>
#include <iostream>
#include <cassert>
#include "String_Tokenizer.h"
using std::cout;
using std::endl;
using std::string;

int main()
{
  // Create a string tokenizer
  /*<snippet id="1">*/
  string person_data = "Doe, John 5/15/65";
  String_Tokenizer st(person_data, " ,/");
  /*</snippet>*/
  // Extract the tokens
  /*<snippet id="2">*/
  string family_name = st.next_token(); // stores "Doe"
  string given_name = st.next_token();  // stores "John"
  string month = st.next_token();       // stores "5"
  string day = st.next_token();         // stores "15"
  string year = st.next_token();        // stores "65"
  /*</snippet>*/
  // Verify that the tokens are as expected
  /*<snippet id="3">*/
  assert(family_name == "Doe");
  assert(given_name == "John");
  assert(month == "5");
  assert(day == "15");
  assert(year == "65");
  /*</snippet>*/
  // Create another string tokenizer
  /*<snippet id="4">*/
  string sentence = "This is a set of seven tokens";
  String_Tokenizer get_words(sentence);
  /*</snippet>*/
  // Use a loop to print out the words
  /*<snippet id="5">*/
  while (get_words.has_more_tokens())
    cout << get_words.next_token() << endl;
  /*</snippet>*/
}
