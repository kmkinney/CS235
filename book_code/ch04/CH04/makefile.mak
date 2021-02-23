TARGETS = test_ordered_list test_vector test_list\
demo_double_linked_list_node list_demo_std list_demo_KW \
Mean_And_Stdev single_linked_list

CCFLAGS = /Zi /EHsc /GR

all:	$(TARGETS)

test_ordered_list:	test_ordered_list.cpp Ordered_List.h
	cl $(CCFLAGS) /Fe$@ test_ordered_list.cpp

test_vector:		test_vector.cpp vector.h
	cl $(CCFLAGS) /Fe$@ test_vector.cpp

test_list:	test_list.cpp list.h DNode.h list_iterator.h list_const_iterator.h
	cl $(CCFLAGS) /Fe$@ test_list.cpp

demo_double_linked_list_node:	demo_double_linked_list_node.cpp DNode.h
	cl $(CCFLAGS) /Fe$@ demo_double_linked_list_node.cpp

list_demo_std:	list_demo.cpp
	cl $(CCFLAGS) /Fe$@ list_demo.cpp

list_demo_KW:	list_demo.cpp list.h DNode.h list_iterator.h list_const_iterator.h
	cl $(CCFLAGS) -DUSEKW /Fe$@ list_demo.cpp

Mean_And_Stdev:	Mean_And_Stdev.cpp
	cl $(CCFLAGS) /Fe$@ Mean_And_Stdev.cpp

single_linked_list:	single_linked_list.cpp Node.h
	cl $(CCFLAGS) /Fe$@ single_linked_list.cpp

clean:
	del *.exe
	del *.obj
	del *.pdb
	del *.ikl

