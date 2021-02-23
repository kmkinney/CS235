TARGETS = ComputeAreaAndPerim
CC = cl
CPPFLAGS = /Zi /EHsc /GR

all:	$(TARGETS)

ComputeAreaAndPerim:	ComputeAreaAndPerim.obj Circle.obj Rectangle.obj \
Rt_Triangle.obj
	$(CC) $(CPPFLAGS) -Fe$@ $**

ComputeAreaAndPerim.obj: ComputeAreaAndPerim.cpp Circle.h Rectangle.h \
Rt_Triangle.h Shape.h
	$(CC) $(CPPFLAGS) /c ComputeAreaAndPerim.cpp

Circle.obj:	Circle.cpp Circle.h Shape.h
	$(CC)  $(CPPFLAGS) /c Circle.cpp

Rectangle.obj:	Rectangle.cpp Rectangle.h Shape.h
	$(CC)  $(CPPFLAGS) /c Rectangle.cpp

Rt_Triangle.obj:	Rt_Triangle.cpp Rt_Triangle.h Shape.h
	$(CC) $(CPPFLAGS) /c Rt_Triangle.cpp

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk
