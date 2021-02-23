#ifndef SMALL_ALLOCATOR_H_
#define SMALL_ALLOCATOR_H_
#include <memory>

/** Class to efficiently allocate small object values. */
namespace KW {
  // Forward declaration of small_allocator class
  template <typename T> class small_allocator;
  // Specialization for void -- copied from the standard
  template<> class small_allocator<void> {
  public:
    typedef void* pointer;
    typedef const void* const_pointer;
    template <class U>
      struct rebind {
        typedef small_allocator<U> other;
      };
  };

  // Template for other types
  template <typename T> class small_allocator {
  public:

    //Typdefs
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    template <typename U> struct rebind
    {
      typedef small_allocator<U> other;
    };
    typedef typename std::allocator<T>::size_type size_type;
    typedef typename std::allocator<T>::difference_type difference_type;

    // Constructors and destructor
    // All do nothing since all data members are static
    small_allocator() {}
    small_allocator(const small_allocator<T>&) {}
    ~small_allocator() {}

    // Member functions

    // Assignment does nothing
    small_allocator<T>& operator=(const small_allocator<char>&) {
      return *this;
    }

    /** Return a pointer to the parameter */
    pointer address(T& x) {return &x;}

    /** Return a pointer to the parameter */
    const_pointer address(const T& x) {return &x;}

    /** Allocate space for objects
        @param n The number of objects to be allocated
    */
    pointer allocate(size_type n, 
                     small_allocator<void>::const_pointer hint=0);

    /** Return an allocated object (or small array) to the free 
        storage pool
        @param p Pointer to allocated object
        @param n The number of object
    */

    void deallocate(pointer p, size_type n);
    /** Return the maximum number of objects that can be allocated */
    size_type max_size() const {
      // Delegate to the standard allocator
      return std::allocator<T>().max_size();
    }

    /** Construct a copy of val in the space pointed to
        @param p A pointer to raw memory
        @param val The value
    */
    void construct(pointer p, const T& val) {
      // Invoke the copy constructor to copy val into the space
      new ((void*)p)T(val);
    }

    /** Destroy the object pointed to by p */
    void destroy(pointer p) {
      // Invoke the destructor
      p->~T();
    }

  private:
    //Data fields
    /** Size of block to be managed by the small_allocator */
    static const size_t BLOCK_SIZE = sizeof(long) * 8;
    /** Nested class to contain the blocks */
    struct block 
    {
      /** Pointer to the next block */
      block* next;
      /** Bit mask to keep track of allocated objects */
      long alloc;
      /** Array to hold the space for the objects */
      T mem [BLOCK_SIZE];
    };
    /** Pointer to the first block in the list */
    static block* head;
  };

/** Implementation of the small_allocator */

/** Pointer to the head of linked list of memory blocks */
template <typename T>
typename small_allocator<T>::block* small_allocator<T>::head = NULL;

/** Allocate space for objects
    @param n The number of objects to be allocated
*/
 template <typename T>
   typename small_allocator<T>::pointer 
   small_allocator<T>::allocate(size_type n, 
                          typename std::allocator<void>::const_pointer hint) {
   // If the object size is greater than BLOCK_SIZE, then use the
   // standard allocator
   if (sizeof(T) > BLOCK_SIZE) {
     std::allocator<T> alloc;
     return alloc.allocate(n, hint);
   }
   // If n > BLOCK_SIZE/2, then we use the standard allocator
   if (n > BLOCK_SIZE/2) {
     std::allocator<T> alloc;
     return alloc.allocate(n, hint);
   } 
   else {
     // Search for a free object
     block* current = head;
     size_type i = 0;
     unsigned long mask;
     while (current != NULL) {
       // Search for a free object
       mask = ~0L; // Set mask to 11111111...11
       mask >>= n; // Mask is now 00..0111...11
       mask = ~mask; // Mask is   11..1000...00
       i = 0;
       long a = current->alloc;
       while ((i < (BLOCK_SIZE - (n-1))) && ((a & mask) != 0)) {
         mask >>= 1;
         i++;
       }
       if (i < (BLOCK_SIZE - (n-1))) {
         // We found the space
         // Compute the address of the returned object
	 break;
       } else {
	 current = current->next;
       }
     }
     if (current == NULL) {
       // No more free blocks, create a new one and link it to the list
       current = head; // Save head in current
       // Allocate space for a block
       std::allocator<block> std_alloc;
       head = std_alloc.allocate(1);
       head->alloc = 0;      // Mark all objects available
       head->next = current; // link to the list;
       current = head;
       i = 0;              
       mask = ~0L;           // create the mask
       mask >>= n;
       mask = ~mask;
     }
     // Compute the address of the result;
     pointer result = current->mem + i;
     // Mark these objects as allocated
     current->alloc |= mask;
     return result;
   }
 }

 /**    Return an allocated object (or small array) to the free 
        storage pool
        @param p Pointer to allocated object
        @param n The number of object
 */
 template <typename T>
   void small_allocator<T>::deallocate(pointer p, size_type n)
   {
     /* If more than BLOCK_SIZE/2, then it was allocated by the 
        standard allocator */
     if (n > BLOCK_SIZE/2) {
       std::allocator<T> alloc;
       alloc.deallocate(p, n);
     }
     else {
       // Search for the block that contains this object
       block* current = head;
       while (current != NULL 
              && !(p >= current->mem 
                   && p < current->mem+BLOCK_SIZE)) {
         current = current->next;
       }
       if (current == NULL) {
         // See if the standard allocator can deal with it
         std::allocator<T> alloc;
         alloc.deallocate(p, n);
       } 
       else {
         // Found it
         // Mark these objects as available
         int i = p - current->mem;
         unsigned long mask = ~0L;
         mask >>= n;
         mask = ~mask;
         mask >>= i;
         current->alloc &= ~mask;  
       }
     }
   }
   // Equality operators
   /** All small_allocators for the same type are equal */
   template <typename T>
   inline
   bool operator==(const small_allocator<T>&, const small_allocator<T>&) {
     return true;
   }
   template <typename T>
   inline
   bool operator!=(const small_allocator<T>&, const small_allocator<T>&) {
     return false;
   } 
} // End of namespace KW

#endif
