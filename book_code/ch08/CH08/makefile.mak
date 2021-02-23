all:	Index_Generator Test_Binary_Tree Test_Binary_Search_Tree_Words \
Test_Binary_Search_Tree_Double Test_Priority_Queue Test_Huffman_Tree_KW \
Test_Huffman_Tree_std

CPPFLAGS = /EHsc /Zi

Index_Generator:	Index_Generator.obj String_Tokenizer.obj
	cl $(CPPFLAGS) /Fe$@ $**

Index_Generator.obj:	Index_Generator.cpp Binary_Search_Tree.h \
Binary_Tree.h BTNode.h String_Tokenizer.h 
	cl $(CPPFLAGS) /c Index_Generator.cpp

String_Tokenizer.obj:	String_Tokenizer.cpp String_Tokenizer.h
	cl $(CPPFLAGS) /c String_Tokenizer.cpp

Test_Binary_Tree:	Test_Binary_Tree.cpp Binary_Tree.h BTNode.h \
pre_order_traversal.h in_order_traversal.h post_order_traversal.h
	cl $(CPPFLAGS) /Fe$@ Test_Binary_Tree.cpp

Test_Binary_Search_Tree_Words:	Test_Binary_Search_Tree_Words.cpp \
Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	cl $(CPPFLAGS) /Fe$@ Test_Binary_Search_Tree_Words.cpp

Test_Binary_Search_Tree_Double:	Test_Binary_Search_Tree_Double.cpp \
Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	cl $(CPPFLAGS) /Fe$@ Test_Binary_Search_Tree_Double.cpp

Test_Priority_Queue:	Test_Priority_Queue.cpp priority_queue.h
	cl -I. -I../CH06 $(CPPFLAGS) /Fe$@ Test_Priority_Queue.cpp

Test_Huffman_Tree_KW:	Test_Huffman_Tree.obj Huffman_Tree_KW.obj
	cl $(CPPFLAGS) /Fe$@ $**

Huffman_Tree_KW.obj:	Huffman_Tree.cpp Huffman_Tree.h Binary_Tree.h \
BTNode.h
	cl $(CPPFLAGS) /c /DUSEKW /Fo$@ Huffman_Tree.cpp

Test_Huffman_Tree_std:	Test_Huffman_Tree.obj Huffman_Tree_std.obj
	cl $(CPPFLAGS) /Fe$@ $**

Test_Huffman_Tree.obj:	Test_Huffman_Tree.cpp Huffman_Tree.h \
Binary_Tree.h BTNode.h
	cl $(CPPFLAGS) /c Test_Huffman_Tree.cpp

Huffman_Tree_std.obj:	Huffman_Tree.cpp Huffman_Tree.h Binary_Tree.h \
BTNode.h
	cl $(CPPFLAGS) /c /Fo$@ Huffman_Tree.cpp

clean:
	del *.obj
	del *.exe

