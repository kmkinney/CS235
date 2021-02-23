/** Implementation of character allocator */

#include "char_allocator.h"

/** Pointer to the head of linked list of memory blocks */
KW::small_allocator<char>::block* KW::small_allocator<char>::head = NULL;

/** Allocate characters
    @param n The number of characters to be allocated
*/
KW::small_allocator<char>::pointer 
KW::small_allocator<char>::allocate(size_type n, 
			      std::allocator<void>::const_pointer hint) {
  // If n > BLOCK_SIZE, then we use the standard allocator
  if (n > BLOCK_SIZE) {
    std::allocator<char> alloc;
    return alloc.allocate(n, hint);
  } else {
    // Search for a free byte
    block* current = head;
    // If allocated == -1, this block is full
    while (true) {
      // No more free blocks, create a new one and link it to the list
      if (current == NULL) {
	current = head;
	head = new block;
	head->allocated = 0;
	head->next = current;
	current = head;
      }
      // Search for a free char
      // Create a word of all ones
      unsigned long mask = (unsigned long)(-1L);
      mask >>= n; // Shift right so there are n leading zeros
      mask = ~mask; // Invert
      int i = 0;
      long a = current->allocated;
      while ((i < (BLOCK_SIZE - (n-1))) && (a & mask)) {
	mask >>= 1;
	i++;
      }
      if (i < (BLOCK_SIZE - (n-1))) {
	// We found the space
	// Compute the address of the returned char
	pointer result = current->mem + i;
	// Mark this character as allocated
	current->allocated |= mask;
	return result;
      } else {
	// Try next block
	current = current->next;
      }
    }
  }
}

/** Return an allocated byte to the free storage pool
    @param p Pointer to allocated char
    @param n The number of char
*/
void KW::small_allocator<char>::deallocate(pointer p, size_type n)
{
  /* If more than one char, then it was allocated by the 
     standard allocator */
  if (n > BLOCK_SIZE) {
    std::allocator<char> alloc;
    alloc.deallocate(p, n);
  } else {
    // Search for the block that contains this char
    block* current = head;
    while (current != NULL 
	   && !(p >= current->mem 
		&& p < current->mem+BLOCK_SIZE)) {
      current = current->next;
    }
    if (current != NULL) {
      // Found it
      // Mark these characters as available
      int i = p - current->mem;
      unsigned long mask = (unsigned long)(-1L);
      mask >>= n;
      mask = ~mask;
      mask >>= i;
      current->allocated &= ~mask;  
    } else {
      // See if the standard allocator can deal with it
      std::allocator<char> alloc;
      alloc.deallocate(p, n);
    }
  }
}

// Delelegate the max_size funciton to the standard allocator
KW::small_allocator<char>::size_type 
KW::small_allocator<char>::max_size() const
{
  std::allocator<char> alloc;
  return alloc.max_size();
}

// To construct a char, merely copy it
void 
KW::small_allocator<char>::construct(pointer p, const char& val)
{
  *p = val;
}

// Do nothing, chars do not have destructors
void KW::small_allocator<char>::destroy(pointer p) {}
