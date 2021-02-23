#include <iostream>
#include <sstream>
#include <string>
#include "String_Tokenizer.h"
using std::string;
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;


int main()
{
  string person_data = "Doe, John 5/15/65";
  string person_data2 = "Roe, Jane 9/25/66";
  // Parse person_data using an istringstream
  /*<snippet id="1" omit="false">*/
  istringstream in(person_data);
  /*</snippet>*/
  // Extract the family name and given name
  string family_name, given_name;
  /*<snippet id="2" omit="false">*/
  in >> family_name >> given_name;
  /*</snippet>*/
  // Extract the month, day, and year
  int month, day, year;
  char c;
  /*<snippet id="3" omit="false">*/
  in >> month;         // read the month as an int
  in >> c;             // read the '/' character
  in >> day;           // read the day as an int
  in >> c;             // read the '/' character
  /*</snippet>*/
  
  //Display the results
  cout << "family_name: " << family_name << endl;
  cout << "given_name: " << given_name << endl;
  cout << "month: " << month << endl;
  cout << "day: " << day << endl;
  cout << "year: " << year << endl;
  
  //Use the string tokenizer
  String_Tokenizer st(person_data2, " ,/");
  family_name = st.next_token();
  given_name = st.next_token();
  string s_month = st.next_token();
  string s_day = st.next_token();
  string s_year = st.next_token();
  
  //Use an istringstream to parse the month, day, and year
  /*<snippet id="4">*/
  istringstream(s_month) >> month;
  istringstream(s_day) >> day;
  istringstream(s_year) >> year;
  /*</snippet>*/
  
  //Display the results
  cout << "family_name: " << family_name << endl;
  cout << "given_name: " << given_name << endl;
  cout << "month: " << month << endl;
  cout << "day: " << day << endl;
  cout << "year: " << year << endl;
  
  // Create a person_data string
  /*<snippet id="5" omit="false">*/
  ostringstream out;
  out << family_name << ", " << given_name << ' ' << month << '/' 
      << day << '/' << year;
  string person_data3 = out.str();
  /*</snippet>*/
  cout << person_data3; 
}
