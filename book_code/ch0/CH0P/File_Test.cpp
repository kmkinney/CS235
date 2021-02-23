/* File_Test is an application that illustrates stream operations. */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Reads a line from an input file and a line from the console.
   Concatenates the two lines and writes them to an output file.
   Does this until all input lines have been read.
   For the array pointed to by argv, argv[1] is the input file name
   and argv[2] is the output file name. argc is the number of 
   elements in this array.
*/
int main(int argc, char* argv[]) {

  // Validate the number of arguments
  if (argc < 3) {
    cerr << "Usage File_Test <input file> <output file>\n";
    return 1;
  }

  // Define the input file stream
  ifstream ins(argv[1]);
  if (!ins) {
    cerr << "Failed to open " << argv[1] << " for input\n";
    return 1;
  }

  // Define the output file stream
  ofstream outs(argv[2]);
  if (!outs) {
    cerr << "Failed to open " << argv[2] << " for output\n";
    return 1;
  }

  // Reads words and writes them to the output file until done.
  string first;
  string second;
  while (ins >> first) {
/*<snippet id="1" omit="false">*/
cout << "Type a word to follow " << first << ": ";
cin >> second;
/*</snippet>*/
/*<snippet id="2" omit="false">*/
outs << first << ", " << second << endl;
/*</snippet>*/
  }

  // Close files
  ins.close();
  outs.close();
  return 0;
}

