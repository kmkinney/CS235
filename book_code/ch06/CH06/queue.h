#ifndef QUEUE_H_
#define QUEUE_H_

// Insert necessary include directives here.
#include <algorithm>
#ifdef USELIST
#include <cstddef>
#elif USESTDLIST
#include <list>
#endif
#include <string>
#include <sstream>

namespace KW {
  
  /** A queue is a data structure that provides first-in first-out
      access to the items that are stored in it. Only the least recently
      inserted item is accessible.
  */
  template<typename Item_Type>
    class queue {
    
    public:
    
    // Constructor and member functions
    /** Constructs an empty queue. */
    queue();

    /** Pushes an item onto the back of the queue.
        @param item The item to be inserted
    */
    void push(const Item_Type& item);
    
    /** Returns a reference to the object at the front of the queue 
        without removing it.
        @return A reference to the object at the front of the queue
    */
    Item_Type& front();
    
    /** Returns a const reference to the object at the 
        front of the queue without removing it.
        @return A const reference to the object at the front of the queue
    */
    const Item_Type& front() const;
    
    /** Removes the front item from the queue. */
    void pop();
    
    /** Determines whether the queue is empty. */
    bool empty() const;
    
    /** Returns the number of items in the queue */
    size_t size() const;
    
    // Copy constructor, assignment operator, destructor, and swap





      

    private:
    // Insert implementation-specific data fields
#ifdef USELIST
    // Insert definition of Node here
#include "Node.h"
    // Data fields
    /** A sequential container to contain the queue items */
    Node* front_of_queue;
    Node* back_of_queue;
    size_t num_items;
#elif USEARRAY
    /** Double the capacity and reallocate the data
	Pre: The array is filled to capacity
	Post: The capacity is doubled and the first half
	of the expanded array is filled with data.
    */
    void reallocate();
    
    // Data fields
    /** The initial size of the data array */
    static const size_t DEFAULT_CAPACITY = 10;
    /** The current capacity of the data array */
    size_t capacity;
    /** The number of items in the queue */
    size_t num_items;
    /** The index of the front of the queue */
    size_t front_index;
    /** The index of the rear of the queue */
    size_t rear_index;
    /** Pointer to the array containing the data */
    Item_Type* the_data;
#elif USESTDLIST
    /** A standard linked list container to contain the queue items */
    std::list<Item_Type> container;
#endif
        
  }; // End class queue
  
  // Insert member function implementation here
#ifdef USELIST
#include "Linked_Queue.tc"
#elif USEARRAY
#include "Array_Queue.tc"
#elif USESTDLIST
#include "List_Queue.tc"
#endif
  // Specialization of swap template
