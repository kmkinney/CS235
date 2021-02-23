#ifndef PERSON_H_
#define PERSON_H_

#include "Address.h"
#include <string>

class Person
{
 public:
  /** Create an empty employee */
  Person() {}
  /** Create a person from the given parameters
      @param the_name The employee's name
      @param the_address A pointer to the person's address
  */
  explicit Person(const std::string& the_name, Address* the_address) 
    : name(the_name), p_address(the_address) {}

  /** The copy constructor */
  Person(const Person& other) 
    : name(other.name), p_address(other.p_address->clone()) {} 

  /** The assignment operator */
  Person& operator=(const Person& other);

  /** The destructor */
  virtual ~Person() { delete p_address; }

  /** Update Person's house number */
  void set_house_number (std::string new_house_number) {
    p_address->set_house_number(new_house_number);
  }

  /** Swap the contents of this Person and the other Person */
  void swap(Person& other)
    {
      std::swap(name, other.name);
      std::swap(p_address, other.p_address);
    }

  /** Return String Representation of Person */
  std::string to_string() const;

 protected:
  std::string name;
  Address* p_address;
};

inline
void swap(Person& p1, Person& p2)
{
  p1.swap(p2);
}

#endif
