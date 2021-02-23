TARGETS = Maintain_Queue_std.exe Maintain_Queue_list.exe Maintain_Queue_array.exe \
Maintain_Queue_linked.exe Airline_Checkin_Sim.exe test_deque.exe test_queue_assignment_std.exe \
test_queue_assignment_list.exe test_queue_assignment_array.exe test_queue_assignment_linked.exe

CPPFLAGS = /Zi /EHsc /GR

all:	$(TARGETS)

Maintain_Queue_std.exe:	Maintain_Queue.cpp
	cl /Fe$@ /DUSESTD $(CPPFLAGS) Maintain_Queue.cpp

Maintain_Queue_list.exe:	Maintain_Queue_KW.cpp queue.h List_Queue.tc
	cl /Fe$@ /DUSESTDLIST $(CPPFLAGS) Maintain_Queue_KW.cpp

Maintain_Queue_array.exe:	Maintain_Queue_KW.cpp queue.h Array_Queue.tc
	cl /Fe$@ /DUSEARRAY $(CPPFLAGS) Maintain_Queue_KW.cpp

Maintain_Queue_linked.exe:	Maintain_Queue_KW.cpp queue.h Linked_Queue.tc
	cl /Fe$@ /DUSELIST $(CPPFLAGS) Maintain_Queue_KW.cpp

test_queue_assignment_std.exe:	test_queue_assignment.cpp
	cl $(CPPFLAGS) /DUSESTD /Fe$@ test_queue_assignment.cpp

test_queue_assignment_list.exe:	test_queue_assignment.cpp queue.h List_Queue.tc
	cl /Fe$@ /DUSESTDLIST $(CPPFLAGS) test_queue_assignment.cpp

test_queue_assignment_array.exe:	test_queue_assignment.cpp queue.h Array_Queue.tc
	cl /Fe$@ /DUSEARRAY $(CPPFLAGS) test_queue_assignment.cpp

test_queue_assignment_linked.exe:	test_queue_assignment.cpp queue.h Linked_Queue.tc
	cl /Fe$@ /DUSELIST $(CPPFLAGS) test_queue_assignment.cpp

test_deque.exe:	test_deque.cpp deque.h Carray.h
	cl /Fe$@ $(CPPFLAGS) test_deque.cpp

Airline_Checkin_Sim.exe:	Airline_Checkin_Sim.obj Passenger_Queue.obj Passenger.obj
	cl /Fe$@ $**

Airline_Checkin_Sim.obj:	Airline_Checkin_Sim.cpp Airline_Checkin_Sim.h Passenger.h \
			Passenger_Queue.h Random.h
	cl /c $(CPPFLAGS) Airline_Checkin_Sim.cpp

Passenger.obj:	Passenger.cpp Passenger.h Random.h
	cl /c $(CPPFLAGS) Passenger.cpp

Passenger_Queue.obj:	Passenger_Queue.cpp Passenger_Queue.h Passenger.h Random.h
	cl /c $(CPPFLAGS) Passenger_Queue.cpp

clean:
	del *.exe
	del *.obj
	del *.pdb
	del *.ilk

