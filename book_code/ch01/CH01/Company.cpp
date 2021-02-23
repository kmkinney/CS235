#include "Company.h"
#include <ostream>
using std::ostream;
using std::endl;

/** Sets an element of employees.
    @param index The position of the employee
    @param emp The employee
*/
void Company::set_employee(int index, Person emp) {
  if (index >= 0 && index < num_employees)
    employees[index] = emp;
}

/** Gets an employee.
    @param index The position of the employee
    @return The employee object or if not defined
            return a default Person object
*/
Person Company::get_employee(int index) {
  if (index >= 0 && index < num_employees)
    return employees[index];
  else
    return Person();
}

/** Builds and inserts a string consisting of all employees'
    data, with newline characters between employees.
    @param os The destination ostream
    @param company The Company object to be output
    @return The updated ostream
*/
ostream& operator<<(ostream& os, const Company& company) {
  for (int i = 0; i < company.num_employees; i++)
    os << company.employees[i] << endl;
return os;
}
