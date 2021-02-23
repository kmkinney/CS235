TARGETS = PD_Application
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

PD_Application:	PD_Application.o Vector_Based_PD.o
	$(CC) $(CCFLAGS) -o $@ $^

PD_Application.o:	PD_Application.cpp Vector_Based_PD.h
	$(CC) $(CCFLAGS) -c $<

Vector_Based_PD.o:	Vector_Based_PD.cpp Vector_Based_PD.h
	$(CC) $(CCFLAGS) -c $<

.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
