/** Implementation file for the class German_Address */
#include "Address.h"
using std::string;

string German_Address::to_string()
{
  string result = street;
  result += " ";
  result += house_number;
  result += "\n";
  result += postal_code;
  result += " ";
  result += municipality;
  result += "\n";
  result += "Germany\n";
  return result;
}

