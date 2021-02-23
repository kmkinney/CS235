#ifndef PASSENGER_H_
#define PASSENGER_H_

/** A class to represent a passenger. */
class Passenger {
  public:

  /** Creates a new passenger.
      @param arrive_time The time this passenger arrives */
  Passenger(int arrive_time);

  /** Gets the arrival time.
      @return The arrival time */
  int get_arrival_time() {
    return arrival_time;
  }

  /** Gets the processing time.
      @return The processing time */
  int get_processing_time() {
    return processing_time;
  }

  /** Gets the passenger ID.
      @return The passenger ID */
  int get_id() {
    return passenger_id;
  }

  /** Sets the maximum processing time.
      @param max_process_time The new value */
  static void set_max_processing_time(int max_process_time) {
    max_processing_time = max_process_time;
  }

  private:

  // Data Fields
  /** The ID number for this passenger. */
  int passenger_id;

  /** The time needed to process this passenger. */
  int processing_time;

  /** The time this passenger arrives. */
  int arrival_time;

  /** The maximum time to process a passenger. */
  static int max_processing_time;

  /** The sequence number for passengers. */
  static int id_num;

};

#endif
