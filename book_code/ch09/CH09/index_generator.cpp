/** Program to generate a simple index */

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <list>
#include <string>
#include "String_Tokenizer.h"
#ifdef USESTD
#include <map>
typedef std::map<std::string, std::list<int> > map_type;
#elif KWSTD
#include "map.h"
typedef KW::map<std::string, std::list<int> > map_type;
#elif KWCHAIN
#include "Hash_Table_Chain.h"
typedef KW::hash_map<std::string, std::list<int> > map_type;
#elif KWCHAINSLL
#include "Hash_Table_Chain_SLL.h"
typedef KW::hash_map<std::string, std::list<int> > map_type;
#elif KWOPEN
#include "Hash_Table_Open.h"
typedef KW::hash_map<std::string, std::list<int> > map_type;
#else
#include "hash_map.h"
typedef KW::hash_map<std::string, std::list<int> > map_type;
#endif

using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istream;
using std::istringstream;
using std::tolower;
using std::list;
using std::right;
using std::setw;

void to_lower(string& a_string)
{
  for (size_t i = 0; i < a_string.length(); i++)
    a_string[i] = tolower(a_string[i]);
}

void print_index(const map_type& index)
{
  for (map_type::const_iterator itr = index.begin();
       itr != index.end(); ++itr) {
    // print the word
    cout << itr->first << ": ";
    // print the first line number
    list<int>::const_iterator itr2 = (itr->second).begin();
    cout << *itr2;
    // print the rest of the line numbers
    ++itr2;
    for (; itr2 != (itr->second).end(); itr2++)
      cout << ", " << *itr2;
    cout << '\n';
  }
}

/** Reads each word (a key) in the data file in and stores it
    in a map along with a list of line numbers (a value).
    pre:  index is an empty map.
    post: lowercase form of each word with all its
          line numbers is stored in index.
    @param in An istream attached to the data file
    @param index The index
*/
void build_index(istream& in, map_type& index) {
  string next_line;  // Each data line
  int line_num = 0;  // Line number
  // Keep reading lines until done
  while (getline(in, next_line)) {
    line_num++;
    // Create a String_Tokenizer for the current data line
    // using punctuation and white space as delimiters
    String_Tokenizer tokenizer(next_line, " ,.:-!?/%\'\"");
    // Insert each token in the index
    while (tokenizer.has_more_tokens()) {
      string word = tokenizer.next_token();
      to_lower(word);
index[word].push_back(line_num);
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
#ifdef KWOPEN
    cout << "Average number of probes to build index " 
	 << index.average_probes() << endl;
#endif

  } catch (exception& ex) {
    cout << "Standard exception thrown " << ex.what() << endl;
  }
}

      

  
