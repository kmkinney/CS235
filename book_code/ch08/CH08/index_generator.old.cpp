/** Program to generate a simple index */

#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <iomanip>
#include "string_tokenizer.h"

using namespace std;

void to_lower(string& a_string)
{
  for (int i = 0; i < a_string.length(); i++) {
    a_string[i] = tolower(a_string[i]);
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
    cerr << "Usage index_generator <input file>\n";
    return 1;
  }

  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }

  // Build Index
  set<string> index;
  string next_line;
  int line_num = 0;
  while (getline(in, next_line)) {
    line_num++;
    string_tokenizer tokenizer(next_line, " ,.:-!?/%\'\"");
    while (tokenizer.has_more_tokens()) {
      string word = tokenizer.next_token();
      to_lower(word);
      ostringstream os;
      os << word;
      os << ", ";
      os << setfill('0');
      os << right;
      os << setw(3) << line_num;
      index.insert(os.str());
    }
  }

  // Show the index
  for (set<string>::iterator itr = index.begin();
       itr != index.end(); ++itr)
    cout << *itr << endl;
}

      

  
