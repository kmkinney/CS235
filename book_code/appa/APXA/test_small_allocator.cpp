/** Program to test small_allocator */

#include <iostream>
#include "small_allocator.h"
template <typename T, typename Allocator>
void test_allocator(T&, Allocator& my_alloc)
{
  // Allocate two objects
  T* p1 = my_alloc.allocate(1);
  T* p2 = my_alloc.allocate(1);
  // Display the object's addresses
  std::cout << "p1 = " << std::hex << (void*)p1 << std::endl;
  std::cout << "p2 = " << std::hex << (void*)p2 << std::endl;
  // Allocate a block of five objects
  T* p3 = my_alloc.allocate(5);
  // Allocate one more object
  T* p4 = my_alloc.allocate(1);
  std::cout << "p3 = " << std::hex << (void*)p3 << std::endl;
  std::cout << "p4 = " << std::hex << (void*)p4 << std::endl;
  // Deallocate p2
  my_alloc.deallocate(p2, 1);
  // Allocate two more objects
  T* p5 = my_alloc.allocate(1);
  T* p6 = my_alloc.allocate(1);
  // Display their addresses
  std::cout << "p5 = " << std::hex << (void*)p5 << std::endl;
  std::cout << "p6 = " << std::hex << (void*)p6 << std::endl;
  // Now allocate 40 objects
  T* ptrs[40];
  for (int i = 0; i < 40; i++) {
    ptrs[i] = my_alloc.allocate(1);
    std::cout << "ptrs[" << std::dec << i << "] = " << std::hex 
	      << (void*)ptrs[i] << std::endl;
  }
}

int main()
{
  char c;
  double d;
  KW::small_allocator<char> char_alloc;
  KW::small_allocator<double> double_alloc;
  std::cout << "KW::small_allocator<char>\n";
  test_allocator(c, char_alloc);
  std::cout << "KW::small_allocator<double>\n";
  test_allocator(d, double_alloc);
  std::allocator<char> std_char_allocator;
  std::cout << "std::allocator<char>\n";
  test_allocator(c, std_char_allocator);
  std::allocator<double> std_double_allocator;
  std::cout << "std::allocator<double>\n";
  test_allocator(d, std_double_allocator);
}
