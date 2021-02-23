// Implementation of the Clock class
#include "Clock.h"

/** Set the clock. */
void Clock::set_clock(int hr, int min, int sec)
{
  hours = hr;
  minutes = min;
  seconds = sec;
}

/** Get the current hour. */
int Clock::get_hours() const
{
  return hours;
}

/** Get the current minute. */
int Clock::get_minutes() const
{
  return minutes;
}

/** Get the current second. */
int Clock::get_seconds() const
{
  return seconds;
}

/** Advance the clock by one second. */
void Clock::tick()
{
  seconds++;
  if (seconds >= 60) {
    minutes++;
    seconds -= 60;
  }
  if (minutes >= 60) {
    hours++;
    minutes -= 60;
  }
  if (hours > 12) {
    hours -= 12;
  }
}

