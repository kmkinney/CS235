/** Program to generate a simple index using a multimap */

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <map>
#include "String_Tokenizer.h"

using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::tolower;
using std::right;
using std::setw;
using std::multimap;
using std::pair;

typedef multimap<string, int> map_type;

void to_lower(string& a_string)
{
  for (size_t i = 0; i < a_string.length(); i++)
    a_string[i] = tolower(a_string[i]);
}

void print_index(const multimap<string, int>& index) {
  for (multimap<string, int>::const_iterator itr = index.begin();
       itr != index.end(); ) {
    // Print the word
    string word = itr->first;
    cout << word << ": ";
    // Print the first line number
    cout << itr->second;
    // Print the rest of the line numbers
    multimap<string, int>::const_iterator next_word 
      = index.upper_bound(word);
    ++itr;
    while (itr != next_word) {
      cout << ", " << itr->second;
      ++itr;
    }
    cout << '\n';
  }
}

/** Reads each word (a key) in the data file in and stores it
    in a map along with a list of line numbers (a value).
    pre:  index in an empty map.
    post: lower case form of each word with all its
          line numbers is stored in index.
    @param in A istream attached to the data file
    @param index The index
*/
void build_index(istream& in, map_type& index)
{
  string next_line;  //Each data line
  int line_num = 0;  //Line number
  // Keep reading lines until done
  while (getline(in, next_line)) {
    line_num++;
    // Create a String_Tokenizer for the current data line
    // using punctuation and white space as delimeters
    String_Tokenizer tokenizer(next_line, " ,.:-!?/%\'\"");
    // Insert each token in the index
    while (tokenizer.has_more_tokens()) {
      string word = tokenizer.next_token();
      to_lower(word);
index.insert(pair<string, int>(word, line_num));
    }
  }
}

int main(int argc, char* argv[])
{
  try {
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
    map_type index;
    build_index(in, index);
    
    // Show the index
    cout << "There are " << index.size() << " words\n";
    cout << "The index is\n";
    print_index(index);
  } catch (exception& ex) {
    cout << "Standard exception thrown " << ex.what() << endl;
  }
}

      

  
