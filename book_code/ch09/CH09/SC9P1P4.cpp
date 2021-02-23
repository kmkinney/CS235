#include "Set_Functions.h"
#include "Multiset_Functions.h"

#include <iostream>
using namespace std;

int main()
{
  multiset<int> m;
  set<int> n;
  m.insert(25); m.insert(37); m.insert(25); m.insert(37);
  n.insert(25); n.insert(37), n.insert(25), n.insert(37);
  cout << "m == " << m << endl;
  cout << "n == " << n << endl;
  m.erase(25); m.erase(37);
  n.erase(25); n.erase(37);
  cout << "m == " << m << endl;
  cout << "n == " << n << endl;
}
/*</exercise>*/
