#ifndef AIRPLANES_H_
#define AIRPLANES_H_

class Jet_Engine {};

class Airplane {};
class Jet_Plane : public Airplane {
  private:
    int num_engines;
    Jet_Engine jets[4]; // Jet planes have up to 4 engines.
  // ...
};
#endif
