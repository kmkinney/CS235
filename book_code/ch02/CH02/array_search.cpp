/** Searches an array to find the first occurrence of a target.
    @param x Array to search
    @param x_length The length of the array
    @param target Target to search for
    @return The subscript of first occurrence if found;
            otherwise, return -1.
*/
int search(int x[], int x_length, int target) {
  for (int i = 0; i < x_length; i++) {
    if (x[i] == target)
      return i;
  }
  
  // target not found
  return -1;
}
