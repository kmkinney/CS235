The following files are included in this directory:

README.txt    This file

Makefile      The make file for g++ under Linux or MinGw (Windows).

makefile.mak  The make file for nmake for Microsoft C++ .NET

	      NOTE: Both make files also use source files from CH08.

Test_Binary_Search_Tree_Word   A test driver for binary search trees
			       that takes word inputs.

Test_Binary_Search_Tree_Double A test driver for binary search trees
			       that takes double inputs.

Test_Two_Three_Tree_Word       A test driver for 2-3 trees that takes
			       word inputs

Test_Two_Tree_Tree_Double      A test driver for 2-3 trees that takes
			       double inputs

Test_Two_Three_Four_Tree_Word  A test driver for 2-3-4 trees that takes
			       word inputs

Test_Two_Three_Four_Tree_Double A test driver for 2-3-4 trees that takes
				double inputs

Test_BTree_Double	A test driver for B-Trees that take double inputs
			The following variations are built:
			Test_BTree3_Double order 3 (equivalent to 2-3 tree)
			Test_BTree4_Double order 4 (equivalent to 2-3-4 tree)
			Test_BTree5_Double order 5
			Test_BTree6_Double order 6
			Test_BTree7_Double order 7

The .txt files are test cases for the _Double versions.

The test drivers do not prompt for input. For the word versions input is
terminated by end-of-file (^Z on windows, ^D on Linux). After reaching eof,
the Binary_Search_Tree driver will continue to read words and erase them
from the tree.

Input for the _Double versions is terminated by a zero. After reaching zero,
the Binary_Search_Tree driver will continue to read input and erase the
values from the tree.


