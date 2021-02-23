#include <iostream>
using std::cout;
using std::endl;
/*<snippet id="1" omit="false">*/
/* Returns an array that contains the sum of elements in each row of a
    two-dimensional array with four columns and num_rows rows.
*/
int* sum_each_row(int x[][4], int num_rows) {
  // Allocate storage for the array of sums.
/*<snippet id="3" omit="false">*/
int* result = new int[num_rows];
/*</snippet>*/
  for (int r = 0; r < num_rows; r++) {
    result[r] = 0;
    // Add the value in each column of row r to result[r]
    for (int c = 0; c < 4; c++) {
/*<snippet id="4" omit="false">*/
result[r] += x[r][c];
/*</snippet>*/
    }
  }
  return result;
}
/*</snippet>*/

int main() {

int my_stuff[2][4] = {{1, 5, 3, 9},
{2, 8, 22, 8}};
/*<snippet id="2" omit="false">*/
int* sums = sum_each_row(my_stuff, 2);
/*</snippet>*/
for (int i = 0; i < 2; i++)
  cout << "sums[" << i << "] = " << sums[i] << endl;
return 0;
}
