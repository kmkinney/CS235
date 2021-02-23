#include <iostream>
using namespace std;

int main()
{
  int* x;
  int* y;
  int* z;
  x = new int[20];
  x[10] = 0;
  y = x;
  x[10] = 5;
  cout << x[10] << ", " << y[10] << endl;
  x[10] = 15;
  z = new int[10];
  for (int i = 0; i < 10; i++) 
    z[i] = x[i];
  x[10] = 25;
  cout << x[10] << ", " << y[10] << ", " << z[10] << endl;
}
