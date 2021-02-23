TARGETS = PD_Application PD_Application_alt
CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

PD_Application:	PD_Application.o Map_Based_PD.o
	$(CC) $(CCFLAGS) -o $@ $^

PD_Application.o:	PD_Application.cpp Map_Based_PD.h
	$(CC) -c $(CCFLAGS)  $<

Map_Based_PD.o:	Map_Based_PD.cpp Map_Based_PD.h
	$(CC) -c $(CCFLAGS) $<

PD_Application_alt:	PD_Application.o Map_Based_PD_alt.o
	$(CC) $(CCFLAGS) -o $@ $^

Map_Based_PD_alt.o:	Map_Based_PD.cpp Map_Based_PD.h
	$(CC) -c $(CCFLAGS) -DALT -o $@ $<

.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
