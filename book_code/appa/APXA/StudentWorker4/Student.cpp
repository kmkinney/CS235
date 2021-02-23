#include "Student.h"
#include <sstream>

/** Return String representation of employee */
std::string Student::to_string() {
  std::ostringstream result;
  result << Person::to_string()
	 << "Major: " << major << " GPA: " 
	 << gpa;
  return result.str();
}
