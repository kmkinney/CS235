#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define ECHO(x) cout << #x << " == " << (x) << endl

int main()
{
  cout << boolalpha;	
  string happy = "Happy birthday to you";
  ECHO(happy);
  ECHO(happy == "Happy birthday to you");
  ECHO("Happy birthday to you" == happy);
  string un_happy = happy[0] + string("Happy birthday to you").substr(1);
  ECHO(un_happy);
  ECHO("happy" < "Happy");
  ECHO("happy" < happy);
  int p1 = happy.find_first_of(" ,.!", 1);
  ECHO(p1);
  int p2 = happy. find_first_of(" ,.!", p1 + 1);
  ECHO(p2);
  string what = happy.substr(p1 + 1, p2 - p1 -1);
  ECHO(what);
  {
  double d = 53.12345;
  cout << setprecision(3);
  cout << setw(15) << d << endl;
  cout << fixed << setw(12) << d << endl;
  cout << scientific << setw(15) << d << endl;

  }
}
