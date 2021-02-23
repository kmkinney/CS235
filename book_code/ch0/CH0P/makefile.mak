TARGETS = test_count_occurences.exe eof_test.exe File_Test.exe \
format_demo.exe HelloWorld.exe manipulator_example.exe \
output_example.exe precision_demo.exe string_stream_demo.exe \
test_KW_assert.exe test_string_tokenizer.exe two_dim_array_demo.exe

CPPFLAGS = /Zi /EHsc /GR

all:	$(TARGETS)

test_count_occurences.exe:	test_count_occurences.obj count_occurences.obj
	cl $(CPPFLAGS) /Fe$@ $**

test_count_occurences.obj: test_count_occurences.cpp
	cl $(CPPFLAGS) /c $**

count_occurences.obj:	count_occurences.cpp
	cl $(CPPFLAGS) /c $**

test_KW_assert.exe:	test_KW_assert.cpp KW_assert.h
	cl $(CPPFLAGS) /Fe$@ test_KW_assert.cpp

eof_test.exe:	eof_test.cpp
	cl $(CPPFLAGS) /Fe$@ $**

File_Test.exe:	File_Test.cpp
	cl $(CPPFLAGS) /Fe$@ $**

format_demo.exe:	format_demo.cpp
	cl $(CPPFLAGS) /Fe$@ $**


HelloWorld.exe:	HelloWorld.cpp
	cl $(CPPFLAGS) /Fe$@ $**

manipulator_example.exe:	manipulator_example.cpp
	cl $(CPPFLAGS) /Fe$@ $**

output_example.exe:	output_example.cpp
	cl $(CPPFLAGS) /Fe$@ $**

precision_demo.exe:	precision_demo.cpp
	cl $(CPPFLAGS) /Fe$@ $**

string_stream_demo.exe:	string_stream_demo.obj String_Tokenizer.obj
	cl $(CPPFLAGS) /Fe$@ $**

string_stream_demo.obj:	string_stream_demo.cpp String_Tokenizer.h
	cl $(CPPFLAGS) /c string_stream_demo.cpp

test_string_tokenizer.exe:	test_string_tokenizer.obj String_Tokenizer.obj
	cl $(CPPFLAGS) /Fe$@ $**

test_string_tokenizer.obj: test_string_tokenizer.cpp String_Tokenizer.h
	cl $(CPPFLAGS) /c test_string_tokenizer.cpp

String_Tokenizer.obj:	String_Tokenizer.cpp String_Tokenizer.h
	cl $(CPPFLAGS) /c String_Tokenizer.cpp

two_dim_array_demo.exe:	two_dim_array_demo.cpp
	cl $(CPPFLAGS) /Fe$@ $**

clean:
	del *.exe
	del *.obj


