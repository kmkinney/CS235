TARGETS = test_count_occurences eof_test File_Test format_demo \
HelloWorld manipulator_example output_example precision_demo \
string_stream_demo test_KW_assert test_string_tokenizer \
two_dim_array_demo EXPP7P1 EXPP8P1 EXPP9P1 EXPP9P2 RQPP3 RQPP4 RQPP5_6_7_8 \


CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

test_count_occurences:	test_count_occurences.o count_occurences.o
	$(CC) $(CCFLAGS) -o $@ $^

test_count_occurences.o: test_count_occurences.cpp
	$(CC) $(CCFLAGS) -c $<

count_occurences.o:	count_occurences.cpp
	$(CC) $(CCFLAGS) -c $<

test_KW_assert:	test_KW_assert.cpp KW_assert.h
	$(CC) $(CCFLAGS) -o $@ $<

eof_test:	eof_test.cpp
	$(CC) $(CCFLAGS) -o $@ $<

File_Test:	File_Test.cpp
	$(CC) $(CCFLAGS) -o $@ $<

format_demo:	format_demo.cpp
	$(CC) $(CCFLAGS) -o $@ $<


HelloWorld:	HelloWorld.cpp
	$(CC) $(CCFLAGS) -o $@ $<

manipulator_example:	manipulator_example.cpp
	$(CC) $(CCFLAGS) -o $@ $<

output_example:	output_example.cpp
	$(CC) $(CCFLAGS) -o $@ $<

precision_demo:	precision_demo.cpp
	$(CC) $(CCFLAGS) -o $@ $<

string_stream_demo:	string_stream_demo.o String_Tokenizer.o
	$(CC) $(CCFLAGS) -o $@ $^

string_stream_demo.o:	string_stream_demo.cpp String_Tokenizer.h
	$(CC) $(CCFLAGS) -c $<

test_string_tokenizer:	test_string_tokenizer.o String_Tokenizer.o
	$(CC) $(CCFLAGS) -o $@ $^

test_string_tokenizer.o: test_string_tokenizer.cpp String_Tokenizer.h
	$(CC) $(CCFLAGS) -c $<

String_Tokenizer.o:	String_Tokenizer.cpp String_Tokenizer.h
	$(CC) $(CCFLAGS) -c $<

two_dim_array_demo:	two_dim_array_demo.cpp
	$(CC) $(CCFLAGS) -o $@ $<

EXPP7P1:	EXPP7P1.cpp
	$(CC) $(CCFLAGS) -o $@ $<

EXPP8P1:	EXPP8P1.cpp
	$(CC) $(CCFLAGS) -o $@ $<

EXPP9P1:	EXPP9P1.cpp
	$(CC) $(CCFLAGS) -o $@ $<

EXPP9P2:	EXPP9P2.cpp
	$(CC) $(CCFLAGS) -o $@ $<

RQPP3:	RQPP3.cpp
	$(CC) $(CCFLAGS) -o $@ $<

RQPP4:	RQPP4.cpp
	$(CC) $(CCFLAGS) -o $@ $<

RQPP5_6_7_8:	RQPP5_6_7_8.cpp
	$(CC) $(CCFLAGS) -o $@ $<

same_elements:	same_elements.cpp
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGETS)
