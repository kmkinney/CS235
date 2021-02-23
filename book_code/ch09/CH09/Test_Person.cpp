/** Test_Person is an application that tests class Person. */
#include <iostream>
#include "Person.h"
using std::cout;
using std::endl;

int main() {
  Person p1("Sam", "Jones", "1234", 1930);
  cout << "p1: " << p1 << endl;
  Person p2("Jane", "Jones", "5678", 1990);
  cout << "p2: " << p2 << endl;

  cout << "Age of " << p1.get_given_name() 
       << " is " << p1.age(2004) << endl;
  if (p1.is_senior(2004))
    cout << p1.get_given_name() << " can ride the subway for free\n";
  else
    cout << p1.get_given_name() << " must pay to ride the subway\n";
  if (p2.can_vote(2004))
    cout << p2.get_given_name() << " can vote\n";
  else
    cout << p2.get_given_name() << " can't vote\n";
  // Make Sam younger
  p1.set_birth_year(1950);
  // Now see whether he has to pay to ride the subway.
  cout << "Age of " << p1.get_given_name() 
       << " is " << p1.age(2004) << endl;
  if (p1.is_senior(2004))
    cout << p1.get_given_name() << " can ride the subway for free\n";
  else
    cout << p1.get_given_name() << " must pay to ride the subway\n";

  Person p3("James", "Henry", "9876", 2005);
  Person p4("Henry", "James", "9877", 2005);

  cout << "The hash code for " << p3 << " is " << hash<Person>()(p3) << endl;
  cout << "The hash code for " << p4 << " is " << hash<Person>()(p4) << endl;
}
