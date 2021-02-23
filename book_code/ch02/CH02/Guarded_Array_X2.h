#ifndef GUARDED_ARRAY_X2_H
#define GUARDED_ARRAY_X2_H

#include <climits>
#include <stdexcept>

class Guarded_Array_X
{
 public:
  explicit Guarded_Array_X(int size) : x(new int[size]), X_SIZE(size) {}
  ~Guarded_Array_X() {delete x;}
  /** Stores val in the element of array x with subscript index.
      @param index The subscript of element to be changed
      @param val The value to be stored
      @return true if val is stored; otherwise, false
  */
  bool set_element_of_x(int index, int val) {
    if (index >= 0 && index < X_SIZE) {
      x[index] = val;
      return true;
    } else {
      return false;
    }
  }
  /** Retrieves the value stored in the element of array x with 
      subscript index.
      @param index The subscript of the element to be retrieved
      @return The value if index is within bounds. Otherwise, INT_MIN.
  */
/** Gets the value in the element of array x with subscript index.
    @param index The subscript of the element to be retrieved
    @return the value stored at x[index] if index is in range
    @throws a std::out_of_range exception if index is not in range
*/
int get_element_of_x(int index) {
}
 private:
  int* x;
  int X_SIZE;
};

#endif
