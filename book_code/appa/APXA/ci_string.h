#ifndef CI_STRING_H_
#define CI_STRING_H_

#include <string>
#include <cctype>

/** Definition of a case insensitive string class.
    This is based on an article by Sutter from
    "Exceptional C++" published by Addison-Wesley
*/

/** Create a specialized char_trates class derived
    from the standard char_traits class
*/
class ci_char_traits : public std::char_traits<char>
{
 public:
  /** Override the eq function to ignore case */
  static bool eq(const char& c1, const char& c2) {
    return std::toupper(c1) == std::toupper(c2);
  }

  /** Override the lt function to ignore case */
  static bool lt(const char& c1, const char& c2) {
    return std::toupper(c1) < std::toupper(c2);
  }

  /** Override the compare function to ignore case */
  static int compare(const char* s1, const char* s2, size_t n) {
    // Scan to the end, or until different characters are found
    while (n > 0 && *s1 != 0 && *s2 != 0 
	   && eq(*s1, *s2)) {
      n--;
      s1++; 
      s2++;
    }
    // If at the end of both strings, they are equal
    if (n == 0 || (*s1 == 0 && *s2 == 0)) 
      return 0;
    // If s1 is longer than s2, then s1 is greater
    if (s1 != 0 && s2 == 0) return 1;
    // If s2 is longer than s1, then s2 is greater
    if (s2 != 0 && *s1 == 0) return -1;
    // Compare the different characters
    if (lt(*s1, *s2)) return -1;
    else return +1;
  }

  /** Override the find function to ignore case */
  static const char* find(const char* s, size_t n, const char& c) {
    while (n > 0 && !eq(*s, c)) {
      n--;
      s++;
    }
    if (n > 0)
      return s;
    else
      return 0;
  }
};

typedef std::basic_string<char, ci_char_traits> ci_string;

#endif

    
