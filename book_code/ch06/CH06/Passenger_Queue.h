#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include <string>
#include <queue>
#include "Passenger.h"

/** Class to simulate a queue of passengers. */
class Passenger_Queue {

  public:

  // Constructor
  /** Constructs a Passenger_Queue with the given name.
      @param my_name The name of this queue
  */
   Passenger_Queue(std::string my_name) : num_served(0), total_wait(0),
     queue_name(my_name) {}
   
  /** Returns the number of passengers served.
      @return The number of passengers served
  */
  int get_num_served() const {
    return num_served;
  }

  /** Returns the total wait time.
      @return The total wait time
   */
  int get_total_wait() const {
    return total_wait;
  }

  /** Returns the queue name.
      @return The queue name
   */
  std::string get_queue_name() const {
    return queue_name;
  }

  /** Sets the arrival rate.
      @param new_arrival_rate The value to set
  */
  void set_arrival_rate(double new_arrival_rate) {
    arrival_rate = new_arrival_rate;
   }

  /** Determines whether the passenger queue is empty.
      @return true if the passenger queue is empty
  */
  bool empty() const {
    return the_queue.empty();
  }

  /** Determines the size of the passenger queue.
      @return the size of the passenger queue
  */
  size_t size() const {
    return the_queue.size();
  }

  /** Checks whether a new arrival has occurred.
      @param clock The current simulated time
      @param show_all Flag to indicate that detailed
                      data should be output
  */
  void check_new_arrival(int clock, bool show_all);

  /** Updates statistics.
      pre: The queue is not empty.
      @param clock The current simulated time
      @param show_all Flag to indicate whether to show detail
      @return Time passenger is done being served
  */
  int update(int clock, bool show_all);

  private:

  // Data Fields
  /**  The queue of passengers. */
  std::queue<Passenger> the_queue;

  /** The number of passengers served. */
  int num_served;

  /** The total time passengers were waiting. */
  int total_wait;

  /** The name of this queue. */
  std::string queue_name;

  /** The average arrival rate. */
  double arrival_rate;

};

#endif
