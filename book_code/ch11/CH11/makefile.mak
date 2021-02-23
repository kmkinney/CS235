all:	Test_Binary_Search_Tree_Word.exe Test_Binary_Search_Tree_Double.exe \
Test_Two_Three_Tree_Word.exe Test_Two_Three_Tree_Double.exe \
Test_Two_Three_Four_Tree_Word.exe Test_Two_Three_Four_Tree_Double.exe \
Test_BTree3.exe Test_BTree4.exe Test_BTree5.exe \
Test_BTree6.exe Test_BTree7.exe

CPPFLAGS = /EHsc /Zi /GR

Test_Binary_Search_Tree_Word.exe: Test_Binary_Search_Tree_Word.cpp AVL_Tree.h \
Red_Black_Tree.h BST_With_Rotate.h AVLNode.h RBNode.h
	cl $(CPPFLAGS) -I. -I../CH08 /FeTest_Binary_Search_Tree \
Test_Binary_Search_Tree_Word.cpp

Test_Binary_Search_Tree_Double.exe: Test_Binary_Search_Tree_Double.cpp \
AVL_Tree.h Red_Black_Tree.h BST_With_Rotate.h AVLNode.h RBNode.h
	cl $(CPPFLAGS) -I. -I../CH08 /FeTest_Binary_Search_Tree2 \
Test_Binary_Search_Tree_Double.cpp

Test_Two_Three_Tree_Word.exe: Test_Two_Three_Tree_Word.cpp Two_Three_Tree.h
	cl $(CPPFLAGS) /FeTest_Two_Three_Tree Test_Two_Three_Tree_Word.cpp 

Test_Two_Three_Tree_Double.exe:	Test_Two_Three_Tree_Double.cpp Two_Three_Tree.h
	cl $(CPPFLAGS) /FeTest_Two_Three_Tree2 \
Test_Two_Three_Tree_Double.cpp 

Test_Two_Three_Four_Tree_Word.exe:	Test_Two_Three_Four_Tree_Word.cpp \
Two_Three_Four_Tree.h
	cl $(CPPFLAGS) /FeTest_Two_Three_Four_Tree \
Test_Two_Three_Four_Tree_Word.cpp 

Test_Two_Three_Four_Tree_Double.exe:	Test_Two_Three_Four_Tree_Double.cpp \
Two_Three_Four_Tree.h
	cl $(CPPFLAGS) /FeTest_Two_Three_Four_Tree2 \
Test_Two_Three_Four_Tree_Double.cpp 

Test_BTree3.exe:	Test_BTree_Double.cpp B_Tree.h
	cl $(CPPFLAGS) -DNN=3 /Fe$@ Test_BTree_Double.cpp

Test_BTree4.exe:	Test_BTree_Double.cpp B_Tree.h
	cl $(CPPFLAGS) -DNN=4 /Fe$@ Test_BTree_Double.cpp

Test_BTree5.exe:	Test_BTree_Double.cpp B_Tree.h
	cl $(CPPFLAGS) -DNN=5 /Fe$@ Test_BTree_Double.cpp

Test_BTree6.exe:	Test_BTree_Double.cpp B_Tree.h
	cl $(CPPFLAGS) -DNN=6 /Fe$@ Test_BTree_Double.cpp

Test_BTree7.exe:	Test_BTree_Double.cpp B_Tree.h
	cl $(CPPFLAGS) -DNN=7 /Fe$@ Test_BTree_Double.cpp

clean:
	del *.obj
	del *.exe


