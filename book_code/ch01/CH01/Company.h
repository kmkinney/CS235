#ifndef COMPANY_H_
#define COMPANY_H_

#include "Person.h"  // Definition of the Person class
#include <iostream>  // Declaration of I/O classes

/** Company is a class that represents a company.
    The data field employees provides storage for 
    an array of Person objects.
*/
class Company {
  public:  // Constructors 
    // Constructors     // Constructors
    /** Creates a new array of Person objects.
        @param size The size of array employees
    */
    Company(int size) : 
      num_employees(size), employees(new Person[size]) {}

    Company() : 
      num_employees(DEFAULT_SIZE), employees(new Person[DEFAULT_SIZE]) {}
     
  // Functions

    /** Sets an element of employees.
        @param index The position of the employee
        @param emp The employee  
    */
    void set_employee(int index, Person emp);

    /** Gets an employee.
        @param index The position of the employee
        @return the employee object or if not defined
               a default Person object  
    */
    Person get_employee(int index);

    /** Builds and outputs a string consisting of all employees'
        data, with newline characters between employees.
        @param os The destination ostream
        @param company The company object to be output
        @return The updated ostream object  
    */
    friend std::ostream& operator<<(std::ostream& os,                                     const Company& company);

  private:
    // Data Fields
    /** The number of employees. */
    int num_employees;
    /** The array of employees. */
    Person* employees;
     
    /** The default size of the array. */
    static const int DEFAULT_SIZE = 100;
};

#endif
