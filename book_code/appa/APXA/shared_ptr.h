#ifndef SHARED_PTR_H_
#define SHARED_PTR_H_

#include <cstddef>
#include <algorithm>

/** A shared pointer keeps track of the pointers to a dynamically allocated
    object. When there are no pointers pointing to that object, then
    the object is deleted.
*/
template<class Object_Type>
class shared_ptr     // Indirect smart pointers
{

 private:
  /** Class to represent an object pointed to by a shared_ptr.
      This class contains a pointer to the object and the
      reference count.
  */
  struct Object_Rep
    {
      // All members are public
      /** The reference count */
      long ref_count;
      /** The pointer to the object */
      Object_Type* object_ptr;
      /** Construct an Object_Rep */
      Object_Rep(Object_Type* pointer) : ref_count(1), object_ptr(pointer) {
      }
    };
  
public:
  /** Construct a shared pointer to a dynamically allocated object.
      pre:  The argument is the result of the new operator.
      @param ptr A pointer to a newly created dynamically allocated object.
  */
  shared_ptr(Object_Type* ptr = NULL) : 
    rep(ptr != NULL ? new Object_Rep(ptr) : NULL) {}
  
  /** Constructs a shared pointer to a dynamically allocated object
      that is a subclass of Object_Type
      pre:  The argument is the result of the new operator and is
            a subclass of Object_Type
      @param ptr A pointer to a newly created dynamically allocated object.
  */
  template<typename Subclass_Type>
   shared_ptr(Subclass_Type* ptr = NULL) :
    rep(ptr != NULL ? new Object_Rep(ptr) : NULL) {}

  /** Make a copy of a shared pointer
      post: Increments the reference countl
      @param other The other shared pointer
  */
  shared_ptr(const shared_ptr& other) : rep(other.rep) {
    if (rep != NULL) {
      rep->ref_count++;
    }
  }

  /** Destroy a shared pointer
      post: Decrements reference count. If reference count is now
      zero, the object and the object_rep are deleted
  */
  ~shared_ptr() {
    if (rep != NULL) {
      rep->ref_count--;
      if (rep->ref_count == 0) {
	delete rep->object_ptr;
	delete rep;
      }
    }
  }

  /** Swap this shared pointer with another
      @param other The other shared pointer
  */
  void swap(shared_ptr& other) {
    std::swap(rep, other.rep);
  }

  /** Assign one shared_ptr to another
      @param other The other shared_ptr
  */
  shared_ptr& operator=(const shared_ptr& other) {
    shared_ptr temp(other);
    swap(temp);
    return *this;
  }

  /** De-reference a shared pointer */
  Object_Type& operator*() const {
    return *(rep->object_ptr);
  }

  /** Provide member access throught a shared pointer */
  Object_Type* operator->() const {
    return rep->object_ptr;
  }

  /** Test two shared pointers for equality */
  bool operator==(const shared_ptr& other) const {
    return rep == other.rep;
  }

  /** Test this shared pointer for NULL */
  bool operator==(void*) const {
    return rep == NULL;
  }

  /** Test two shared pointers for inequality */
  bool operator!=(const shared_ptr& other) const {
    return rep != other.rep;
  }

  /** Test this shared pointer for not NULL */
  bool operator!=(void*) const {
    return rep != NULL;
  }

  /** Return the reference count 
      This function is included for testing purposes only.
  */
  long count() {
    if (rep != NULL) {
      return rep->ref_count;
    } else {
      return 0;
    }
  }

  /** Return a pointer to the target object 
      This function is included for testing purposes only.
  */
  Object_Type* get() {
    if (rep != NULL) {
      return rep->object_ptr;
    } else {
      return NULL;
    }
  }

 private:
  /** A pointer to the Object_Rep */
  Object_Rep* rep;

};

/** Specialization of standard swap 
    @param ptr1 A shared_ptr
    @param ptr2 The other shared ptr
*/
template<typename Object_Type>
void swap(shared_ptr<Object_Type>& ptr1, shared_ptr<Object_Type>& ptr2) {
  ptr1.swap(ptr2);
}

#endif

