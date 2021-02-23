#include "Student_Worker.h"
#include <sstream>
/** Return String representation of student worker */
std::string Student_Worker::to_string() const {
  std::ostringstream result;
  result << this->Person::to_string() 
         << "Major: " << major << " GPA: " 
         << gpa << " Rate: " << rate << " Hours: " 
         << hours;
  return result.str();
}
