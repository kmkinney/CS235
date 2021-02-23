PD_Application:	PD_Application.o Array_Based_PD.o
	g++ -o PD_Application PD_Application.o Array_Based_PD.o

PD_Application.o:	PD_Application.cpp Array_Based_PD.h
	g++ -c -Wall -pedantic PD_Application.cpp

Array_Based_PD.o:	Array_Based_PD.cpp Array_Based_PD.h
	g++ -c -Wall -pedantic Array_Based_PD.cpp

.PHONY:	clean

clean:
	rm -f *.o
	rm -f PD_Application
