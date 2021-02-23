#include "Person.h"
#include <ostream>
#include <sstream>

/** Return String representation of employee */
std::string Person::to_string() {
  std::ostringstream result;
  result << name << '\n' << p_address->to_string();
  return result.str();
}

/** Assignment operator */
Person& Person::operator=(const Person& other)
{
  Person temp(other);
  swap(temp);
  return *this;
}

