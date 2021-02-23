TARGETS = test_char_allocator test_small_allocator \
test_list_with_allocator standard_allocator_test \
test_ci_string test_shared_ptr

CC = g++
CCFLAGS = -Wall -pedantic -g

all:	$(TARGETS)

test_char_allocator:	test_char_allocator.o char_allocator.o
	$(CC) $(CCFLAGS) -o $@ $^

test_small_allocator:	test_small_allocator.o
	$(CC) $(CCFLAGS) -o $@ $^

test_list_with_allocator:	test_list_with_allocator.o
	$(CC) $(CCFLAGS) -o $@ $^

standard_allocator_test:	standard_allocator_test.o
	$(CC) $(CCFLAGS) -o $@ $^

test_ci_string:	test_ci_string.o
	$(CC) $(CCFLAGS) -o $@ $^

test_shared_ptr:	test_shared_ptr.o
	$(CC) $(CCFLAGS) -o $@ $^

%.o:	%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

char_allocator.o: char_allocator.cpp small_allocator.h
standard_allocator_test.o: standard_allocator_test.cpp
test_char_allocator.o: test_char_allocator.cpp small_allocator.h
test_ci_string.o: test_ci_string.cpp ci_string.h
test_list_with_allocator.o: test_list_with_allocator.cpp \
  list_with_allocator.h small_allocator.h DNode.h list_iterator.h \
  list_const_iterator.h
test_shared_ptr.o: test_shared_ptr.cpp shared_ptr.h
test_small_allocator.o: test_small_allocator.cpp small_allocator.h

.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
