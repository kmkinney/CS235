/** Implementation file for the class US_Address */
#include "Address.h"
using std::string;

string US_Address::to_string()
{
  string result = house_number;
  result += " ";
  result += street;
  result += "\n";
  result += municipality;
  result += " ";
  result += state_or_provence;
  result += "  ";
  result += postal_code;
  result += "\n";
  return result;
}
