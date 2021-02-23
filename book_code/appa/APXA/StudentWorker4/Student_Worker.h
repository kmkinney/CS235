#ifndef STUDENT_WORKER_H_
#define STUDENT_WORKER_H_

#include "Employee.h"
#include "Student.h"

class Student_Worker : public Employee, public Student
{
 public:
  /** Construct a new Student_Worker
      @param name  The Student_Workers's name
      @param the_address A pointer to Student_Worker's address
      @param rate The hourly rate
      @param major The student's major
  */
  Student_Worker(const std::string& name,
                 Address* the_address,
                 double rate,
                 const std::string& major) 
    : Person(name, the_address),  
    Employee(name, the_address, rate) ,
    Student(name, the_address, major) {}
  /** Return a string representation of a student worker */
  std::string to_string();
};

#endif

