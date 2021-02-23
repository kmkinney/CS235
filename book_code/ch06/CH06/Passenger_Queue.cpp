/** Implementation of Passenger Queue Class.
 */
#include "Passenger_Queue.h"
#include <iostream>
using std::cout;
using std::endl;

#include "Random.h"
extern Random my_random;

/** Checks whether a new arrival has occurred.
    @param clock The current simulated time
    @param show_all Flag to indicate that detailed
                    data should be output
*/
void Passenger_Queue::check_new_arrival(int clock, bool show_all) {
  if (my_random.next_double() < arrival_rate) {
    the_queue.push(Passenger(clock));
    if (show_all) {
      cout << "Time is "
           << clock <<  ": "
           << queue_name
           << " arrival, new queue size is "
           << the_queue.size() << endl;
    }
  }
}

/** Update statistics.
    pre: The queue is not empty.
    @param clock The current simulated time
    @param show_all Flag to indicate whether to show detail
    @return Time passenger is done being served
*/
int Passenger_Queue::update(int clock, bool show_all) {
  Passenger next_passenger = the_queue.front();
  the_queue.pop();
  int time_stamp = next_passenger.get_arrival_time();
  int wait = clock - time_stamp;
  total_wait += wait;
  num_served++;
  if (show_all) {
    cout << "Time is " << clock
         << ": Serving "
         << queue_name
         << " with time stamp "
         << time_stamp << endl;
  }
  return clock + next_passenger.get_processing_time();
}
