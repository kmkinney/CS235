#include "Employee.h"

#include <sstream>
#include <ostream>

using std::string;
using std::ostringstream;

string Employee::to_string() const
{
  ostringstream result;
  result << name << '\n'
	 << p_address->to_string()
	 << "Rate: " << rate
	 << "Hours: " << hours;
  return result.str();
}

