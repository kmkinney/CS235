#ifndef AIRLINE_CHECKIN_SIM_H_
#define ARRLINE_CHECKIN_SIM_H_

#include "Passenger_Queue.h"

/** Simulates the check-in process of an airline. */
class Airline_Checkin_Sim {

  public:

  Airline_Checkin_Sim () : frequent_flyer_queue("Frequent Flyer Queue"),
    regular_passenger_queue("Regular Passenger Queue"), clock(0), 
    time_done(0) {}

  /** Run the simulation. */
  void run_simulation();

  /** Function to show the statistics. */
  void show_stats(); 

  /** Function to read the simulation parameters. */
  void enter_data();
    
  private:
  
  /** Function to start serving a passenger. */
  void start_serve();

  // Data Fields
  /** Queue of frequent flyers. */
  Passenger_Queue frequent_flyer_queue;

  /** Queue of regular passengers. */
  Passenger_Queue regular_passenger_queue;

  /** Maximum number of frequent flyers to be served
      before a regular passenger gets served. */
  int frequent_flyer_max;

  /** Maximum time to serve a passenger. */
  int max_processing_time;

  /** Total simulated time. */
  int total_time;

  /** If set true, print additional output. */
  bool show_all;

  /** Simulated clock. */
  int clock;

  /** Time that the agent will be done with the current passenger. */
  int time_done;

  /** Number of frequent flyers served since the
      last regular passenger was served. */
  int frequent_flyers_since_RP;

};

#endif
