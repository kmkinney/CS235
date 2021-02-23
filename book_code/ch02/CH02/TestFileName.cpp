#include <string>
using std::string;

int main(int argc, char* argv[])
{
  string input_file_name;
  if (argc > 1)
    input_file_name = argv[1];
  else
    input_file_name = "Phone.dat";
}
