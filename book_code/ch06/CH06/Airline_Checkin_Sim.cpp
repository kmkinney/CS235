/** Implementaiton of Airline Checkin Simulation
 *   @author Koffman & Wolfgang
 */

#include "Airline_Checkin_Sim.h"
#include <iostream>
#include <string>
#include <cctype>
#include "Random.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/** Global definition of random number generator */
Random my_random;

int main() {
  Airline_Checkin_Sim simulation;
  simulation.enter_data();
  simulation.run_simulation();
  simulation.show_stats();
}

void Airline_Checkin_Sim::run_simulation() {
  for (clock = 0; clock < total_time; clock++) {
    frequent_flyer_queue.check_new_arrival(clock, show_all);
    regular_passenger_queue.check_new_arrival(clock, show_all);
    if (clock >= time_done) {
      start_serve();
    }
  }
}

void Airline_Checkin_Sim::start_serve() {
  if (!frequent_flyer_queue.empty()
      && ( (frequent_flyers_since_RP <= frequent_flyer_max)
	   || regular_passenger_queue.empty())) {
    // Serve the next frequent flyer.
    frequent_flyers_since_RP++;
    time_done = frequent_flyer_queue.update(clock, show_all);
  }
  else if (!regular_passenger_queue.empty()) {
    // Serve the next regular passenger.
    frequent_flyers_since_RP = 0;
    time_done = regular_passenger_queue.update(clock, show_all);
  }
  else if (show_all) {
    cout << "Time is " << clock
	 << ": Server is idle\n";
  }
}

/** Function to show the statistics. */
void Airline_Checkin_Sim::show_stats() {
  cout << "\nThe number of regular passengers served was "
       << regular_passenger_queue.get_num_served() << endl;
  double average_waiting_time =
    double(regular_passenger_queue.get_total_wait())
    / double(regular_passenger_queue.get_num_served());
  cout << " with an average waiting time of "
       << average_waiting_time << endl;
  cout << "The number of frequent flyers served was "
       << frequent_flyer_queue.get_num_served() << endl;
  average_waiting_time =
    double( frequent_flyer_queue.get_total_wait())
    / double(frequent_flyer_queue.get_num_served());
  cout << " with an average waiting time of "
       << average_waiting_time << endl;
  cout << "Passengers in frequent flyer queue: "
       << frequent_flyer_queue.size() << endl;
  cout << "Passengers in regular passenger queue: "
       << regular_passenger_queue.size() << endl;
}

void Airline_Checkin_Sim::enter_data() {
  // Exercise
}
