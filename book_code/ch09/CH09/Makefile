TARGETS = Test_Map_std Test_Map_KWSTD \
index_generator_std index_generator_KWSTD \
Test_Huffman_Tree Test_Set_Functions Test_Set_Functions_alt \
multimap_index_generator Demo_Multiset \
Demo_Multiset Demo_Set_Functions

CC = g++
CCFLAGS = -g -Wall -pedantic

all: $(TARGETS)

multimap_index_generator:	multimap_index_generator.cpp \
String_Tokenizer.h String_Tokenizer.o
	$(CC) $(CCFLAGS)  -o multimap_index_generator \
multimap_index_generator.cpp String_Tokenizer.o

Test_Set_Functions:	Test_Set_Functions.cpp Set_Functions.h
	$(CC) $(CCFLAGS) -o Test_Set_Functions \
Test_Set_Functions.cpp

Test_Set_Functions_alt:	Test_Set_Functions_alt.cpp Set_Functions_alt.h
	$(CC) $(CCFLAGS) -o Test_Set_Functions_alt \
Test_Set_Functions_alt.cpp

Test_Map_std:	Test_Map.cpp
	$(CC) $(CCFLAGS) -DUSESTD -o Test_Map_std Test_Map.cpp

Test_Map_KWSTD:	Test_Map.cpp map.h
	$(CC) $(CCFLAGS) -DKWSTD -o Test_Map_KWSTD Test_Map.cpp

Test_Map_KWINLINEOPEN:	Test_Map.cpp Hash_Table_Open.h
	$(CC) $(CCFLAGS) -DKWOPEN -o Test_Map_KWINLINEOPEN \
Test_Map.cpp

Test_Map_KWINLINECHAIN:	Test_Map.cpp Hash_Table_Chain.h
	$(CC) $(CCFLAGS) -DKWCHAIN -o Test_Map_KWINLINECHAIN \
Test_Map.cpp

Test_Map_KWCHAINSLL:	Test_Map.cpp Hash_Table_Chain_SLL.h
	$(CC) $(CCFLAGS) -DKWCHAINSLL -o $@ Test_Map.cpp

Test_Map_to_string_KWINLINEOPEN:	Test_Map_to_string.cpp \
Hash_Table_Open.h
	$(CC) $(CCFLAGS) -DKWOPEN -o $@ $<

Test_Map_to_string_KWINLINECHAIN:	Test_Map_to_string.cpp \
Hash_Table_Chain.h
	$(CC) $(CCFLAGS) -DKWCHAIN -o $@ $<

index_generator_std:	index_generator.cpp String_Tokenizer.h \
String_Tokenizer.o
	$(CC) $(CCFLAGS) -DUSESTD  -o index_generator_std \
index_generator.cpp String_Tokenizer.o

index_generator_KWSTD:	index_generator.cpp map.h \
String_Tokenizer.h String_Tokenizer.o
	$(CC) $(CCFLAGS) -DKWSTD  -o \
index_generator_KWSTD index_generator.cpp String_Tokenizer.o

index_generator_KWINLINEOPEN:	index_generator.cpp \
Hash_Table_Open.h String_Tokenizer.h String_Tokenizer.o
	$(CC) $(CCFLAGS) -DKWOPEN  -o \
index_generator_KWINLINEOPEN index_generator.cpp String_Tokenizer.o

index_generator_KWINLINECHAIN:	index_generator.cpp \
Hash_Table_Chain.h String_Tokenizer.h String_Tokenizer.o
	$(CC) $(CCFLAGS) -DKWCHAIN  -o \
index_generator_KWINLINECHAIN index_generator.cpp String_Tokenizer.o

index_generator_KWCHAINSLL:	index_generator.cpp \
Hash_Table_Chain_SLL.h String_Tokenizer.h String_Tokenizer.o
	$(CC) $(CCFLAGS) -DKWCHAIN  -o $@ index_generator.cpp \
String_Tokenizer.o

Test_Huffman_Tree:	Test_Huffman_Tree.o Huffman_Tree.o \
Bit_String.o
	$(CC) $(CCFLAGS) -o Test_Huffman_Tree \
Test_Huffman_Tree.o Huffman_Tree.o Bit_String.o

Huffman_Tree.o:	Huffman_Tree.cpp Huffman_Tree.h Bit_String.h
	$(CC) $(CCFLAGS)  -c Huffman_Tree.cpp

Bit_String.o:	Bit_String.cpp Bit_String.h
	$(CC) $(CCFLAGS) -c Bit_String.cpp

Test_Huffman_Tree.o:	Test_Huffman_Tree.cpp Huffman_Tree.h \
Bit_String.h
	$(CC) $(CCFLAGS) -c  Test_Huffman_Tree.cpp

String_Tokenizer.o:	String_Tokenizer.cpp String_Tokenizer.cpp
	$(CC) $(CCFLAGS) -c String_Tokenizer.cpp

SC9P1P1: SC9P1P1.cpp Set_Functions.h
	$(CC) $(CCFLAGS) -o $@ $<

SC9P1P2: SC9P1P2.cpp Set_Functions.h
	$(CC) $(CCFLAGS) -o $@ $<

SC9P1P3: SC9P1P3.cpp Multiset_Functions.h
	$(CC) $(CCFLAGS) -o $@ $<

SC9P1P4: SC9P1P4.cpp Set_Functions.h Multiset_Functions.h
	$(CC) $(CCFLAGS) -o $@ $<

SC9P2P2: SC9P2P2.cpp
	$(CC) $(CCFLAGS) -o $@ $<

SC9P2P3: SC9P2P3.cpp
	$(CC) $(CCFLAGS) -o $@ $<

Count_Words:	Count_Words.cpp
	$(CC) $(CCFLAGS) -o $@ $<

Demo_Multiset:	Demo_Multiset.cpp
	$(CC) $(CCFLAGS) -o $@ $<

Demo_Set_Functions:	Demo_Set_Functions.cpp Set_Functions.h
	$(CC) $(CCFLAGS) -o $@ $<

.PHONEY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
