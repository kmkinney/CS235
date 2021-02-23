CPPFLAGS = /Zi /EHsc /GR
CC = cl

all:	Airplanes

Airplanes:	Airplanes.cpp Airplanes.h
	$(CC) $(CPPFLAGS) -Fe$@ Airplanes.cpp

clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk

