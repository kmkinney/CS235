/** Program to test char_allocator */

#include <stdexcept>
#include <iostream>
#include "small_allocator.h"

int main()
{
 KW::small_allocator<char> my_alloc;
 char* p1 = my_alloc.allocate(1);
 char* p2 = my_alloc.allocate(1);
 char* p3 = my_alloc.allocate(5);
 std::cout << "p1 = " << std::hex << (void*)p1 << std::endl;
 std::cout << "p2 = " << std::hex << (void*)p2 << std::endl;
 std::cout << "p3 = " << std::hex << (void*)p3 << std::endl;
 KW::small_allocator<double> my_double_alloc;
 double* p4 = my_double_alloc.allocate(1);
 double* p5 = my_double_alloc.allocate(1);
 double* p6 = my_double_alloc.allocate(1);
 std::cout << "p4 = " << std::hex << (void*)p4 << std::endl;
 std::cout << "p5 = " << std::hex << (void*)p5 << std::endl;
 std::cout << "p6 = " << std::hex << (void*)p6 << std::endl;
 my_double_alloc.deallocate(p4, 1);
 double* ptrs[40];
 for (int i = 0; i < 40; i++) {
   ptrs[i] = my_double_alloc.allocate(1);
   std::cout << "ptrs[" << std::dec << i << "] = " << std::hex 
	     << (void*)ptrs[i] << std::endl;
 }
 char* cptrs[40];
 for (int i = 0; i < 40; i++) {
   cptrs[i] = my_alloc.allocate(1);
   std::cout << "cptrs[" << std::dec << i << "] = " << std::hex 
	     << (void*)cptrs[i] << std::endl;
 }
 // Force a call to the standard allocator
 double* p8 = my_double_alloc.allocate(20);
 double* p9 = my_double_alloc.allocate(20);
 std::cout << "p8 = " << std::hex << (void*)p8 << std::endl;
 std::cout << "p9 = " << std::hex << (void*)p9 << std::endl;
}

