#include <iostream>
#include <string>
using namespace std;

int rec_slen(string s)
{
    if (s == "")
        return 0;
    return 1 + rec_slen(s.substr(1));
}

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        cout << argv[1] << " is " << rec_slen(argv[1]) << " letters long." << endl;
    }
}
