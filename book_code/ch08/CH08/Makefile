TARGETS = Index_Generator Test_Binary_Tree \
Test_Binary_Search_Tree_Words Test_Binary_Search_Tree_Numbers \
Test_Priority_Queue \
Test_Huffman_Tree_KW Test_Huffman_Tree_std
CC = g++
CCFLAGS = -Wall -pedantic -g

all:	$(TARGETS)

Index_Generator:	Index_Generator.o String_Tokenizer.o
	$(CC) $(CCFLAGS) -o $@ $^

Index_Generator.o:	Index_Generator.cpp Binary_Search_Tree.h \
Binary_Tree.h BTNode.h String_Tokenizer.h 
	$(CC) $(CCFLAGS) -c $<

String_Tokenizer.o:	String_Tokenizer.cpp String_Tokenizer.h
	$(CC) $(CCFLAGS) -c $<

Test_Binary_Tree:	Test_Binary_Tree.cpp Binary_Tree.h BTNode.h \
pre_order_traversal.h in_order_traversal.h post_order_traversal.h
	$(CC) $(CCFLAGS) -o $@ $<

Test_Binary_Search_Tree_Words:	Test_Binary_Search_Tree_Words.cpp \
Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	$(CC) $(CCFLAGS) -o $@ $<

Test_Binary_Search_Tree_Numbers:	Test_Binary_Search_Tree_Numbers.cpp \
Binary_Search_Tree.h Binary_Tree.h BTNode.h pre_order_traversal.h
	$(CC) $(CCFLAGS) -o $@ $<

Test_Priority_Queue:	Test_Priority_Queue.cpp priority_queue.h
	$(CC) $(CCFLAGS)  $< -o $@

Test_Huffman_Tree_KW:	Test_Huffman_Tree.o Huffman_Tree_KW.o
	$(CC) $(CCFLAGS) -o $@ $^

Huffman_Tree_KW.o:	Huffman_Tree.cpp Huffman_Tree.h Binary_Tree.h \
BTNode.h
	$(CC) $(CCFLAGS) -c -DUSEKW -o $@ $<

Test_Huffman_Tree_std:	Test_Huffman_Tree.o Huffman_Tree_std.o
	$(CC) $(CCFLAGS) -o $@ $^

Test_Huffman_Tree.o:	Test_Huffman_Tree.cpp Huffman_Tree.h \
Binary_Tree.h BTNode.h
	$(CC) $(CCFLAGS) -c $<

Huffman_Tree_std.o:	Huffman_Tree.cpp Huffman_Tree.h Binary_Tree.h \
BTNode.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGETS)

