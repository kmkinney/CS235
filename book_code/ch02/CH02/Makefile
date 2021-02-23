TARGETS =  DivByZero DivByZeroFP Ex2p1p2 GuardDivByZero \
substring_test TestFileName test_array_search test_directory_entry \
test_test_function test_guarded_array test_guarded_array2

CC = g++
CCFLAGS = -g -Wall -pedantic

All:	$(TARGETS)

%.o:	%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

DivByZero:	DivByZero.cpp
	$(CC) $(CCFLAGS) -o $@ $<

DivByZeroFP:	DivByZeroFP.cpp
	$(CC) $(CCFLAGS) -o $@ $<

Ex2p1p1:	Ex2p1p1.cpp
	$(CC) $(CCFLAGS) -o $@ $<

Ex2p1p2:	Ex2p1p2.cpp
	$(CC) $(CCFLAGS) -o $@ $<

GuardDivByZero:	GuardDivByZero.cpp
	$(CC) $(CCFLAGS) -o $@ $<

substring_test:	substring_test.cpp
	$(CC) $(CCFLAGS) -o $@ $<

TestFileName:	TestFileName.cpp
	$(CC) $(CCFLAGS) -o $@ $<

test_array_search:	test_array_search.o array_search.o
	$(CC) $(CCFLAGS) -o $@ $^

test_directory_entry:	test_directory_entry.cpp Directory_Entry.h
	$(CC) $(CCFLAGS) -o $@ $<

test_test_function:	test_test_function.o test_function.o
	$(CC) $(CCFLAGS) -o $@ $^

test_guarded_array:	test_guarded_array.cpp Guarded_Array_X.h
	$(CC) $(CCFLAGS) -o $@ $<

test_guarded_array2:	test_guarded_array2.cpp Guarded_Array_X2.h
	$(CC) $(CCFLAGS) -o $@ $<

test_read_int_x:	test_read_int_x.o read_int_x.o
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f $(TARGETS)
