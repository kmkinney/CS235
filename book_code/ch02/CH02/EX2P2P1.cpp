#include <iostream>
#include <limits>
#include <stdexcept>
#include <fenv.h>
using std::cout;
using std::endl;
using std::exception;
using std::numeric_limits;

#define echo(x) #x << " == " << (x)

float to_big() {
  return numeric_limits<long double>::max() + 1.0f;
}

float to_small() {
  return numeric_limits<double>::min();
}

int int_too_big() {
  return numeric_limits<int>::max() + 100;
}


int main()
{
#pragma STDC FENV_ACCESS on
  cout << echo(numeric_limits<double>::max()) << endl;
  cout << echo(numeric_limits<double>::min()) << endl;
  cout << echo(numeric_limits<int>::max()) << endl;
  cout << echo(numeric_limits<int>::min()) << endl;
  float big, small;
  int int_big;
  try {
    big = to_big();
  } catch(exception& ex) {
    cout << "Exception caught " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception caught\n";
  }
  cout << echo(big) << endl;

  try {
    int_big = int_too_big();
  } catch(exception& ex) {
    cout << "Exception caught " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception caught\n";
  }
  cout << echo(int_big) << endl;

  try {
    small = to_small();
  } catch(exception& ex) {
    cout << "Exception caught " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception caught\n";
  }
  cout << echo(small) << endl;

  cout << "Floating point exceptions enabled\n";
  fexcept_t current_exceptions;
  fegetexceptflag(&current_exceptions, FE_OVERFLOW | FE_UNDERFLOW);
  fesetexceptflag(&current_exceptions, FE_OVERFLOW | FE_UNDERFLOW);

  try {
    big = to_big();
  } catch(exception& ex) {
    cout << "Exception caught " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception caught\n";
  }
  cout << echo(big) << endl;

  try {
    int_big = int_too_big();
  } catch(exception& ex) {
    cout << "Exception caught " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception caught\n";
  }
  cout << echo(int_big) << endl;

  try {
    small = to_small();
  } catch(exception& ex) {
    cout << "Exception caught " << ex.what() << endl;
  } catch (...) {
    cout << "Unknown exception caught\n";
  }
  cout << echo(small) << endl;
}
