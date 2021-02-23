#include "shared_ptr.h"
#include <iostream>
using namespace std;

#define ECHO(X) #X << ": " << (X)

struct Test_Class {
  Test_Class() {
    cout << "Instance of Test_Class created: this == " << this << endl;
  }

  virtual ~Test_Class() {
    cout << "Instance of Test_Class deleted: this == " << this << endl;
  }

  virtual void speak() {
    cout << "I am a Test_Class: this == " << this << endl;
  }
};

struct Subclass1 : public Test_Class {
  Subclass1() {
    cout << "Instance of Subclass1 created: this == " << this << endl;
  }

  ~Subclass1() {
    cout << "Instance of Subclass1 deleted: this == " << this << endl;
  }

  void speak() {
    cout << "I am a Subclass1: this == " << this << endl;
  }
};

struct Subclass2 : public Test_Class {
  Subclass2() {
    cout << "Instance of Subclass2 created: this == " << this << endl;
  }

  ~Subclass2() {
    cout << "Instance of Subclass2 deleted: this == " << this << endl;
  }

  void speak() {
    cout << "I am a Subclass2: this == " << this << endl;
  }
};


int main() {
  
  shared_ptr<Test_Class> ptr1(new Test_Class);
  cout << ECHO(ptr1.get()) << "  " << ECHO(ptr1.count()) << endl;

  shared_ptr<Test_Class> ptr2 = ptr1;
  cout << ECHO(ptr2.get()) << "  " << ECHO(ptr2.count()) << endl;
  
  assert (ptr1.get() == ptr2.get());
  assert (ptr1.count() == 2);
  assert (ptr2.count() == 2);
  assert (ptr1 == ptr2);

  // Enter a block
  { 
    shared_ptr<Test_Class> ptr3(new Test_Class);
    cout << ECHO(ptr3.get()) << "  " << ECHO(ptr2.count()) << endl;
    shared_ptr<Test_Class> ptr4 = ptr1;
    cout << ECHO(ptr4.get()) << "  " << ECHO(ptr4.count()) << endl;
    assert (ptr4.count() == 3);
  }
  cout << "A second object should have been created an destroyed\n";
  cout << "The original object should have its ref counter inc and dec\n";
  assert (ptr1.count() == 2);

  // Create pointers to subclasses
  shared_ptr<Test_Class> ptr3 = new Subclass1();
  shared_ptr<Test_Class> ptr4 = new Subclass2();
  // See what they really point to;
  ptr3->speak();
  ptr4->speak();

  // Swap them
  swap(ptr3, ptr4);
  // See if they have swapped
  ptr3->speak();
  ptr4->speak();

  // Set ptr1 to point to ptr3
  ptr1 = ptr3;
  ptr1->speak();

  // Set ptr2 to point to ptr4
  ptr2 = ptr4;
  ptr2->speak();
  cout << "The original object should now be destroyed\n";

  // Set ptr2 to NULL
  ptr2 = NULL;
  cout << ECHO(ptr4.count()) << endl;
  assert (ptr4.count() == 1);

  cout << "On exit the subclass objects should be destroyed\n";
  return 0;
}

