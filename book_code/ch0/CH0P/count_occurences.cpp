#include <string>
using std::string;
/*<snippet id="1" omit="false">*/
int count_occurrences(char c, const string& s) {
  int count = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (c == s[i])
      count++;
  }
  return count;
/*</snippet>*/
}
