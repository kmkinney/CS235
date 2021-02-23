#ifndef LIST_WITH_ALLOCATOR_H_
#define LIST_WITH_ALLOCATOR_H_

#include <stdexcept>
#include <cstddef>
#include "small_allocator.h"

/** Class list implements a subset of the standard
    list class using a double-linked list.
    @author Koffman and Wolfgang
*/
namespace KW {
  
  template <typename Item_Type, 
    typename Alloc=small_allocator<Item_Type> >
    class list {
    private:
    // Insert definition of nested class DNode here
    #include "DNode.h"
    Alloc allocator;
    typename Alloc::template rebind<DNode>::other node_allocator;
    public:
    // Insert definition of nested class iterator here
    #include "list_iterator.h"
    // Give list access to internal values in iterator
    friend class iterator;
    // Insert definition of nested class const_iterator here
    #include "list_const_iterator.h"
    // Give list access to internal values in const_iterator
    friend class const_iterator;
    
    // Data fields
    /** A reference to the head of the list */
    DNode* head;
    /** A reference to the end of the list */
    DNode* tail;
    /** The size of the list */
    int num_items;
    // Functions
    public:
    /** Construct an empty list */
    list() {
      head = NULL;
      tail = NULL;
      num_items = 0;
    }
    
    /** Construct a copy of a list */
    list(const list<Item_Type>& other) {
      head = NULL;
      tail = NULL;
      num_items = 0;
      for (const_iterator itr = other.begin(); itr != other.end();
           ++itr) {
        push_back(*itr);
      }
    }

    /** Construct a list from a sequence */
    template <typename iterator>
      list(iterator begin, iterator end) {
      head = NULL;
      tail = NULL;
      while (begin != end) {
	push_back(*begin++);
      }
    }
    
    /** Destroy a list */
    virtual ~list() {
      while (head != NULL) {
        DNode* current = head;
        head = head->next;
	node_allocator.destroy(current);
	node_allocator.deallocate(current, 1);
      }
      tail = NULL;
      num_items = 0;
    }
    
    /** Swap this list contents with another one */
    void swap(list<Item_Type> other) {
      std::swap(head, other.head);
      std::swap(tail, other.tail);
      std::swap(num_items, other.num_items);
    }
    
    /** Assign the contents of one list to another */
    list<Item_Type>& operator=(const list<Item_Type>& other) {
      list<Item_Type> temp_copy(other);
      swap(temp_copy);
      return *this;
    }
    
    /** Insert an object at the beginning of the list.
        @param item - the item to be added 
    */
    void push_front(const Item_Type& item) {
      head = node_allocator.allocate(1);
      node_allocator.construct(head, DNode(item, NULL, head));
      if (head->next != NULL)
        head->next->prev = head;  // Step 1
      if (tail == NULL)
        tail = head;
      num_items++;
    }

    /** Insert an object at the end of the list.
        @param item - the item to be added 
    */
    void push_back(const Item_Type& item) {
      if (tail != NULL) {
	tail->next = node_allocator.allocate(1);
	node_allocator.construct(tail->next, DNode(item, tail, NULL));
        tail = tail->next;
        num_items++;
      } else {
        push_front(item);
      }
    }

    /** Insert an object at a position in the list
        indicated by an iterator.  The new item is
        inserted before the position indicated by
        the iterator.
        @param pos The iterator that references the 
                   position where the item is to be
                   inserted.
        @param item The item to be inserted
        @return An iterator that references the inserted
                item.
    */
    iterator insert(iterator pos, const Item_Type& item) {
      // Check for special cases
      if (pos.current == head) {
        push_front(item);
        return begin();
      } else if (pos.current == NULL) {
        push_back(item);
        return iterator(this, tail);
      } 
      else {
        // Create a new node linked before node referenced by pos
	DNode* new_node = node_allocator.allocate(1);
	node_allocator.construct(new_node, DNode(item,
						pos.current->prev,
						pos.current)); // Step1
        // Update links
        pos.current->prev->next = new_node;     // Step 2
        pos.current->prev = new_node;           // Step 3
        num_items++;
        return iterator(this, new_node);
      }
   }

    /** Get a reference to the first element in the list.
        This can be used on either side of an assignment.
        @return The first element in the list.
        @throws invaid_argument if the list is empty
    */
    Item_Type& front() {
      if (head == NULL)
        throw std::invalid_argument
	  ("Attempt to call front() on an empty list");
      return  head->data;
    }

    /** Get a constant reference to first element in the list.
        This can only be used on the right side of an assignment.
        @return The first element in the list.
        @throws invaid_argument if the list is empty
    */
    const Item_Type& front() const {
      if (head == NULL)
        throw std::invalid_argument
          ("Attempt to call front() on an empty list");
      return  head->data;
    }
    
    /** Get a reference to the last element in the list.
        This can be used on either side of an assignment.
        @return The last element in the list.
        @throws std::invalid_argument if the list is empty
    */
    Item_Type& back() {
      if (tail == NULL)
        throw std::invalid_argument
	  ("Attempt to call back() on an empty list");
      return  tail->data;
    }
    
    /** Get a constant reference to the last element in the list.
        This can only be used on the right side of an assgnment.
        @return The last element in the list.
        @throws std::invalid_argument if the list is empty
    */
    const Item_Type& back() const {
      if (tail == NULL)
        throw std::invalid_argument
	  ("Attempt to call back() on an empty list");
      return  tail->data;
    }
    
    /** Query the size of the list
        @return The number of objects in the list 
    */
    int size() const {
      return num_items;
    }
    
    /** Indicate if the list is empty
        @return true if the list is empty
    */
    bool empty() const {
      return num_items == 0;
    }
    
    /** Remove the first item from the list
        @throws std::invalid_argument If the list is empty
    */
    void pop_front() {
      if (head == NULL) 
        throw std::invalid_argument
	  ("Attempt to call pop_front() on an empty list");
      DNode* removed_node = head;
      head = head->next;
      node_allocator.destroy(removed_node);
      node_allocator.deallocate(removed_node, 1);
      if (head != NULL) 
        head->prev = NULL;
      else
        tail = NULL;
      num_items--;
    }
    
    /** Remove the last item from the list
        @throws std::invalid_argument If the list is empty
    */
    void pop_back() {
      if (tail == NULL)
        throw std::invalid_argument
	  ("Attempt to call pop_back() on an empty list");
      DNode* removed_node = tail;
      tail = tail->prev;
      node_allocator.destroy(removed_node);
      node_allocator.deallocate(removed_node, 1);
      if (tail != NULL)
        tail->next = NULL;
      else
        head = NULL;
      num_items--;
    }
    

    /** Remove an item referenced by an iterator
        @param pos An iterator referencing the item to
                   be removed
        @return An iterator that referenced the item
                following the item being removed
        @throws std::invalid_argument if the list is empty
                or if pos references end()
    */
    iterator erase(iterator pos) {
      if (empty()) 
        throw std::invalid_argument
	  ("Attempt to call erase on an empty list");
      if (pos == end())
        throw std::invalid_argument
	  ("Attempt to call erase of end()");
      /* Create an iterator that references the position
         following pos */
      iterator return_value = pos;
      ++return_value;
      // Check for special cases
      if (pos.current == head) {
        pop_front();
        return return_value;
      } else if (pos.current == tail) {
        pop_back();
        return return_value;
      } else {
        // Unlink current node
        DNode* removed_node = pos.current;
        removed_node->prev->next = removed_node->next;
        removed_node->next->prev = removed_node->prev;
	node_allocator.destroy(removed_node);
	node_allocator.deallocate(removed_node, 1);
        return return_value;
      }
    }

    /** Remove all occurences of a value from the list
        @param item The value to be removed
    */
    void remove(const Item_Type& item) {
      iterator itr = begin();
      while (itr != end()) {
        if (*itr == item)
          itr = erase(itr);
        else
          ++itr;
      }
    }
    
    /** Return an iterator to the beginning of the list
        @return an itertor to the beginning of the list
    */
    iterator begin() {
      iterator return_value(this, head);
      return return_value;
    }
    
    /** Return a const_iterator to the beginning of
        the list
        @return a const_iterator to the beginning of
        the list
    */
    const_iterator begin() const {
      const_iterator return_value(this, head);
      return return_value;
    }
    
    /** Return an iterator to the end of the list
        @return an iterator to the end of the list
    */
    iterator end() {
      iterator return_value(this, NULL);
      return return_value;
    }
    
    /** Return a const_iterator to the end of the list
        @return a const_iterator to the end of the list
    */
    const_iterator end() const {
      const_iterator return_value(this, NULL);
      return return_value;
    }
  }; // End list
} // End namespace KW

#endif

