#include "Computer.h"
#include "Lap_Top.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
#ifdef ERRORS
  Computer c1;
#endif
  Computer c2("Ace", "AMD Athlon 2000", 512, 60);
#ifdef ERRORS
  Lap_Top c3("Ace", "AMD Athlon 2000", 512, 60);
#endif
  Lap_Top c4("Ace", "AMD Athlon 2000", 512, 60, 15.5, 7.5);
#ifdef ERRORS
  cout << c2.manufacturer << ", " << c2.processor << endl;
#endif
  cout << c2.get_disk_size() << ", " << c4.get_ram_size() << endl;
  cout << c2.to_string() << '\n' << c4.to_string() << endl;
}
