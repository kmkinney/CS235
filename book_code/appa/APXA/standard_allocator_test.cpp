#include <iostream>
#include <memory>

template <typename T>
void test_allocator(T&)
{
  std::allocator<T> std_allocator;
  std::cout << "Results of standard allocator\n";
  for (int block_size = 1; block_size < 32; block_size++) {
    std::cout << "Block size is " << block_size << std::endl;
    T* p1 = std_allocator.allocate(block_size);
    T* p2 = std_allocator.allocate(block_size);
    T* p3 = std_allocator.allocate(block_size);
    std::cout << "p1 = " << std::hex << (void*)p1 << std::endl;
    std::cout << "p2 = " << std::hex << (void*)p2 << std::endl;
    std::cout << "p3 = " << std::hex << (void*)p3 << std::endl;
  }
}

int main()
{
  char c;
  double d;
  test_allocator(c);
  test_allocator(d);
}
