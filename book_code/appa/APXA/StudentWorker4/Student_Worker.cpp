#include "Student_Worker.h"
#include <sstream>

/** Return String representation of employee */
std::string Student_Worker::to_string() {
  std::ostringstream result;
  result << Person::to_string() 
         << "Major: " << major << " GPA: " 
         << gpa << " Rate: " << rate << " Hours: " 
	 << hours;
  return result.str();
}
