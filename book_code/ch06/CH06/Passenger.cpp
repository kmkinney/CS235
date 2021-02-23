/** Implementation of the Passenger class. */

#include "Passenger.h"
#include "Random.h"
extern Random my_random;   // Declared in Airline_Checkin_Sim.cpp

/** Creates a new passenger.
    @param arrive_time The time this passenger arrives */
Passenger::Passenger(int arrive_time) {
  arrival_time = arrive_time;
  processing_time = 1 + my_random.next_int(max_processing_time);
  passenger_id = id_num++;
}

// Definition of static members.
/** The maximum time to process a passenger. */
int Passenger::max_processing_time;

/** The sequence number for passengers. */
int Passenger::id_num = 0;
