#ifndef DIRECTORY_ENTRY_H
#define DIRECTORY_ENTRY_H
/** Definition of the Directory_Entry class */
#include <string>
class Directory_Entry {
 public:
  Directory_Entry(const std::string& the_name, 
		  const std::string& the_number) :
    name(the_name), number(the_number) {}
  std::string get_name() {return name;}
  std::string get_number() {return number;}
  void set_number(const std::string& new_number) {
    number = new_number;
  }
  bool operator==(const Directory_Entry& other) {
    return name == other.name;
  }
 private:
  std::string name;
  std::string number;
};
#endif
