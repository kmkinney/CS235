TARGETS = Maintain_Queue_std \
Airline_Checkin_Sim \
test_deque test_queue_assignment_std

CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

Maintain_Queue_std:	Maintain_Queue.cpp
	$(CC) -o $@ $(CCFLAGS) $<

test_queue_assignment_std:	test_queue_assignment.cpp
	$(CC) $(CCFLAGS) -DUSESTD -o $@ $<

test_deque:	test_deque.cpp deque.h Carray.h
	$(CC) -o $@ $(CCFLAGS) $<

Airline_Checkin_Sim:	Airline_Checkin_Sim.o Passenger_Queue.o Passenger.o
	$(CC) -o $@ $^

Airline_Checkin_Sim.o:	Airline_Checkin_Sim.cpp Airline_Checkin_Sim.h \
Passenger.h Passenger_Queue.h Random.h
	$(CC) -c $(CCFLAGS) $<

Passenger.o:	Passenger.cpp Passenger.h Random.h
	$(CC) -c $(CCFLAGS) $<

Passenger_Queue.o:	Passenger_Queue.cpp Passenger_Queue.h Passenger.h \
Random.h
	$(CC) -c $(CCFLAGS) $<

.PHONY:	clean

clean:
	rm -f $(TARGETS)
	rm -f *.o
