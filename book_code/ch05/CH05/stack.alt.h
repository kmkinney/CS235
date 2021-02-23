#ifndef STACK_H_
#define STACK_H_
#include <vector>
namespace KW {
  /** A stack is a data structure that provides last-in first-out
      access to the items that are stored in it. Only the most recently
      inserted item is accessible.
  */
  template<typename Item_Type>
    class stack {
    
    public:
      // Member functions

      /** Pushes an item onto the top of the stack.
          @param item The item to be inserted
      */
      void push(const Item_Type item) {
        container.push_back(item);
      }

      /** Returns a reference to the object at the top of the stack 
          without removing it.
          @return A reference to the object at the top of the stack
      */
      Item_Type& top() {return container.back();}

      /** Returns a const reference to the object at the at the 
          top of the stack without removing it.
          @return A const reference to the object at the top of the stack
      */
      const Item_Type& top() const {return container.back();}

      /** Removes the top item from the stack. */
      void pop() {container.pop_back();}

      /** Determines whether the stack is empty. */
      bool empty() const {return container.empty();}

      /** Returns the number of items in the stack. */
      size_t size() const {return container.size();}
    private:
      // Data fields
      /** A sequential container to contain the stack items */
      std::vector<Item_Type> container;
  };
}
#endif
