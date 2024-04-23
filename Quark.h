#ifndef QUARK_H
#define QUARK_H

#include "Particle.h"

class Quark : public Particle {
private:
    double baryon_number; 

public:
    // Constructor 
    Quark(double charge, double spin, double E, double px, double py, double pz, double b_number, bool anti = false);

    // Destructor
    virtual ~Quark();

    // Print
    virtual void print_summary() const override;
};

#endif
