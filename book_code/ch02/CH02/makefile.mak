TARGETS =  DivByZero.exe DivByZeroFP.exe GuardDivByZero.exe \
substring_test.exe TestFileName.exe test_array_search.exe \
test_directory_entry.exe test_test_function.exe test_guarded_array.exe \
test_guarded_array2.exe test_read_int.exe test_sin_cos.exe

CC = cl
CPPFLAGS = /Zi /EHsc /GR

all:	$(TARGETS)

DivByZero.exe:	DivByZero.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

DivByZeroFP.exe:	DivByZeroFP.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

Ex2p1p1.exe:	Ex2p1p1.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

Ex2p1p2.exe:	Ex2p1p2.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

GuardDivByZero.exe:	GuardDivByZero.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

substring_test.exe:	substring_test.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

TestFileName.exe:	TestFileName.cpp
	$(CC) $(CPPFLAGS) -o $@ $**

test_array_search.exe:	test_array_search.obj array_search.obj
	$(CC) $(CPPFLAGS) -o $@ $**

test_directory_entry.exe:	test_directory_entry.cpp Directory_Entry.h
	$(CC) $(CPPFLAGS) -o $@ test_directory_entry.cpp

test_test_function.exe:	test_test_function.obj test_function.obj
	$(CC) $(CPPFLAGS) -o $@ $**

test_guarded_array.exe:	test_guarded_array.cpp Guarded_Array_X.h
	$(CC) $(CPPFLAGS) -o $@ test_guarded_array.cpp

test_guarded_array2.exe:	test_guarded_array2.cpp Guarded_Array_X2.h
	$(CC) $(CPPFLAGS) -o $@ test_guarded_array2.cpp

test_read_int.exe:	test_read_int.obj read_int.obj
	$(CC) $(CPPFLAGS) -o $@ $**

test_read_int_x.exe:	test_read_int_x.obj read_int_x.obj
	$(CC) $(CPPFLAGS) -o $@ $**

test_sin_cos.exe:	test_sin_cos.obj sin_cos.obj
	$(CC) $(CPPFLAGS) -o $@ $**

clean:
	del *.exe
	del *.obj
	del *.pdb
	del *.ilk


