CCFLAGS = /EHsc /Zi /GR

all:	 test_map_std.exe test_map_KWSTD.exe test_map_KWINLINEOPEN.exe \
test_map_KWINLINECHAIN.exe index_generator_std.exe index_generator_KWSTD.exe \
index_generator_KWINLINEOPEN.exe index_generator_KWINLINECHAIN.exe \
test_huffman_tree.exe test_set_functions.exe multimap_index_generator.exe \
Demo_Multiset.exe

multimap_index_generator.exe:	multimap_index_generator.cpp \
String_Tokenizer.h String_Tokenizer.obj
	cl $(CCFLAGS)  /Femultimap_index_generator \
multimap_index_generator.cpp String_Tokenizer.obj

test_set_functions.exe:	test_set_functions.cpp Set_Functions.h
	cl $(CCFLAGS) /Fetest_set_functions \
test_set_functions.cpp

test_map_std.exe:	test_map.cpp
	cl $(CCFLAGS) -DUSESTD /Fetest_map_std test_map.cpp

test_map_KWSTD.exe:	test_map.cpp map.h
	cl $(CCFLAGS) -DKWSTD /Fetest_map_KWSTD test_map.cpp

test_map_KWINLINEOPEN.exe:	test_map.cpp Hash_Table_Open.h
	cl $(CCFLAGS) -DKWOPEN /Fetest_map_KWINLINEOPEN \
test_map.cpp

test_map_KWINLINECHAIN.exe:	test_map.cpp Hash_Table_Chain.h
	cl $(CCFLAGS) -DKWCHAIN /Fetest_map_KWINLINECHAIN \
test_map.cpp

index_generator_std.exe:	index_generator.cpp String_Tokenizer.h \
String_Tokenizer.obj
	cl $(CCFLAGS) -DUSESTD  /Feindex_generator_std \
index_generator.cpp String_Tokenizer.obj

index_generator_KWSTD.exe:	index_generator.cpp map.h \
String_Tokenizer.h String_Tokenizer.obj
	cl $(CCFLAGS) -DKWSTD  /Feindex_generator_KWSTD \
index_generator.cpp String_Tokenizer.obj

index_generator_KWINLINEOPEN.exe:	index_generator.cpp \
Hash_Table_Open.h String_Tokenizer.h String_Tokenizer.obj
	cl $(CCFLAGS) -DKWOPEN  /Feindex_generator_KWINLINEOPEN \
index_generator.cpp String_Tokenizer.obj

index_generator_KWINLINECHAIN.exe:	index_generator.cpp \
Hash_Table_Chain.h String_Tokenizer.h String_Tokenizer.obj
	cl $(CCFLAGS) -DKWCHAIN  /Feindex_generator_KWINLINECHAIN \
index_generator.cpp String_Tokenizer.obj

test_huffman_tree.exe:	test_huffman_tree.obj Huffman_Tree.obj \
Bit_String.obj
	cl $(CCFLAGS) /Fetest_huffman_tree \
test_huffman_tree.obj Huffman_Tree.obj Bit_String.obj

Huffman_Tree.obj:	Huffman_Tree.cpp Huffman_Tree.h Bit_String.h
	cl $(CCFLAGS)  /c Huffman_Tree.cpp

Bit_String.obj:	Bit_String.cpp Bit_String.h
	cl $(CCFLAGS) /c Bit_String.cpp

test_huffman_tree.obj:	test_huffman_tree.cpp Huffman_Tree.h \
Bit_String.h
	cl $(CCFLAGS)  /c test_huffman_tree.cpp

String_Tokenizer.obj:	String_Tokenizer.cpp String_Tokenizer.cpp
	cl $(CCFLAGS) /c String_Tokenizer.cpp

Demo_Multiset.exe:	Demo_Multiset.cpp
	cl $(CCFLAGS) Demo_Multiset.cpp



clean:
	del *.exe
	del *.obj
	del *.pdb
	del *.ilk

