#include <iostream>
using std::cout;

// Declare function to be tested.
int search(int[], int, int);

// Declare verify function.
void verify(int[], int, int, int);

/** main function.  */
int main() {
  int x[] = {5, 12, 15, 4, 8, 12, 7};   // Array to search.
  // Compute length of array.
  const int x_length = sizeof(x) / sizeof(int);
  
  // Test for target as first element.
verify(x, x_length, 5, 0);
  // Test for target as last element.
  verify(x, x_length, 7, 6);
  // Test for target not in array.
  verify(x, x_length, -5, -1);
  // Test for multiple occurrences of target.
  verify(x, x_length, 12, 1);
  // Test for target somewhere in middle.
  verify(x, x_length, 4, 3);
  
  // Test for 1-element array.
  int y[1] = {10};
  const int y_length = 1;
  verify(y, y_length, 10, 0);
  verify(y, y_length, -10, -1);
  
  // Test for an empty array.
  int* z = NULL;
  verify(z, 0, 10, -1);
}

/** Call the search function with the specified parameters and
    verify the expected result.
    @param x The array to be searched
    @param x_length The length of the array to be searched
    @param target The target to be found
    @param expected The expected result
*/
void verify(int x[], int x_length, int target, int expected) {
int actual = search(x, x_length, target);
cout << "search(x, " << target << ") is "
     << actual << ", expected " << expected;
if (actual == expected)
  cout << ":  Pass\n";
else
  cout << ":  ****Fail\n";
}

