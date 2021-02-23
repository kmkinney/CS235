TARGETS = test_Food
CC = cl
CPPFLAGS = /Zi /EHsc /GR

all: $(TARGETS)

test_Food:	test_Food.cpp Vegetable.h Food.h
	$(CC) $(CPPFLAGS) test_Food.cpp 
 
clean:
	del *.obj
	del *.exe
	del *.ilk
	del *.pdb

