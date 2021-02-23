/** Program to generate a simple index. */

#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include "String_Tokenizer.h"
#include "Binary_Search_Tree.h"

using namespace std;

/** Function to convert a string to lowercase. 
    post: All characters in the string are converted
          to their lowercase equivalents.
    @param a_string The string to be converted
*/
void to_lower(string& a_string) {
  for (size_t i = 0; i < a_string.length(); i++)
    a_string[i] = tolower(a_string[i]);
}

/** Function to build the index.
    post: index contains the index of all words
          in the input file.
    @param index The Binary_Search_Tree that will
           contain the index
    @param in The istream that contains the file
*/
void build_index(Binary_Search_Tree<string>& index,
                 istream& in) {
  string next_line;
  int line_num = 0;
  while (getline(in, next_line)) {
    line_num++;
    String_Tokenizer tokenizer(next_line, " ,.:-!?/%\'\"");
    while (tokenizer.has_more_tokens()) {
      string word = tokenizer.next_token();
      to_lower(word);
      ostringstream os;
      os << word;
      os << ", ";
      os << right;
      os << setw(3) << line_num;
      index.insert(os.str());
    }
  }
}

/** Function to print the index in alphabetic order.
    Performs an inorder traversal of the index.
    @param index The Binary_Tree containing the index
           subtree being traversed.
*/
void print_index(const Binary_Tree<string>& index) {
}

int main(int argc, char* argv[]) {
}
