#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

/** Declaration of the abstract class Address */ 
class Address
{
 public:
  //Functions
  explicit Address(const std::string& hn, const std::string& str,
		   const std::string muni, const std::string& stpro, 
		   const std::string pc)
    : house_number(hn), street(str), municipality(muni), 
    state_or_provence(stpro), postal_code(pc) {}
  virtual std::string to_string() = 0;
  virtual Address* clone() = 0;
  virtual ~Address() {}
  void set_house_number(std::string& new_house_number) {
    house_number = new_house_number;}
 protected:
  //DataFields
  std::string house_number;
  std::string street;
  std::string municipality;
  std::string state_or_provence;
  std::string postal_code;
};

/** Declaration of the class US Address */
class US_Address : public Address
{
 public:
  explicit US_Address(const std::string& hn, const std::string& str,
		      const std::string muni, const std::string& stpro, 
		      const std::string pc)
    : Address(hn, str, muni, stpro, pc) {}
  std::string to_string();
  Address* clone() { return new US_Address(*this); }
};

/** Declaration of the class German Address */
class German_Address : public Address
{
 public:
  explicit German_Address(const std::string& hn, const std::string& str,
		   const std::string muni, const std::string pc)
    : Address(hn, str, muni, "", pc) {}
  std::string to_string();
  Address* clone() { return new German_Address(*this); }
};


#endif
