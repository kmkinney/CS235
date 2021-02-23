#ifndef CHAR_ALLOCATOR_H_
#define CHAR_ALLOCATOR_H_
#include <memory>
#include "small_allocator.h"

/** Class to efficiently allocate single char values. */
namespace KW {
  template <typename T> class small_allocator;
  template<> class small_allocator<char> {
  public:
    //Typdef
    typedef char* pointer;
    typedef const char* const_pointer;
    typedef char value_type;
    typedef char& reference;
    typedef const char& const_reference;
    template <typename U> struct rebind
    {
      typedef small_allocator<U> other;
    };
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    // Constructors and destructor
    small_allocator() {} // Do nothing, all data members are static
    small_allocator(const small_allocator<char>&) {} // Do nothing, all data members are static
    ~small_allocator() {}
    // Member functions
    // Assignment does nothing
    small_allocator<char>& operator=(const small_allocator<char>&) {return *this;}
    pointer address(char& c) {return &c;}
    const_pointer address(const char& c) {return &c;}
    pointer allocate(size_type, std::allocator<void>::const_pointer hint=0);
    void deallocate(pointer, size_type);
    size_type max_size() const;
    void construct(pointer p, const char& val);
    void destroy(pointer p);
  private:
    static const size_type BLOCK_SIZE = sizeof(long) * 8;
    struct block 
    {
      block* next;             // Pointer to next block
      long allocated; // Bit mask to keep tract of allocated bytes
      char mem [BLOCK_SIZE];   // The data
    };
    static block* head; // Linked list of memory blocks
  };
}

#endif
