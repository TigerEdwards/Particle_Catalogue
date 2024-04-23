#ifndef LEPTON_H
#define LEPTON_H

#include "Particle.h"

class Lepton : public Particle {
private:
    int lepton_number;

public:
    // Constructor 
     Lepton(double charge, double spin, double E, double px, double py, double pz, int leptonNumber, bool anti = false);

    // Destructor
    virtual ~Lepton();

    // Print
    virtual void print_summary() const override;
};

#endif 