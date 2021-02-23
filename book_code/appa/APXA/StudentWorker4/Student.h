#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"
#include <string>
#undef major
class Student: public virtual Person
{
 public:
  /** Create an empty employee */
  Student() {}
  /** Create an employee from the given parameters
      @param the_name The student's name
      @param the_address A pointer to the student's address
      @param the_major The student's major
  */
  explicit Student(const std::string& the_name, 
                   Address* the_address,
                   const std::string& the_major)
    : Person(the_name, the_address), gpa(0.0), major(the_major) {}


  /** Update Student's house number */
  void set_house_number (std::string new_house_number) {
    p_address->set_house_number(new_house_number);
  }

  /** Set Student's gpa #include */
  void set_gpa(double new_gpa) { gpa = new_gpa; }

  /** Return String Representation of Student */
  std::string to_string();


 protected:
  double gpa;
  std::string major;
};

#endif
