#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Person.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <ostream>

class Employee : public Person
{
 public:
  /** Create an empty employee */
  Employee() {}
  /** Create an employee from the given parameters
      @param the_name The employee's name
      @param the_address Pointer to Employee's address
      @param the_rate The employees hourly rate
  */
  explicit Employee(const std::string& the_name, 
                    Address* the_address,
                    double the_rate)
    : Person(the_name, the_address), rate(the_rate), hours(0.0) {}

  /** Update Employee's house number */
  void set_house_number (std::string new_house_number) {
    p_address->set_house_number(new_house_number);
  }

  /** Return a string representation of Employee */
  std::string to_string() const;

 protected:
  double rate;
  double hours;
};

#endif
