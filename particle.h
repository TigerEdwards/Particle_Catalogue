#ifndef PARTICLE_H
#define PARTICLE_H

#include "fourMomentum.h"
#include <memory>
#include <iostream>
#include <string>
#include <cmath>
class Particle {
private:
protected:
    double rest_mass;
    double charge;
    bool is_antiparticle;
    double spin;
    std::unique_ptr<fourMomentum> four_momentum;
public:
    // Constructor that initializes the fourMomentum as well
    Particle(double charge, double spin, double E, double px, double py, double pz, bool anti = false);
        
    // Destructor
    virtual ~Particle(); 

    // Copy constructor
    Particle(const Particle& other)
        : rest_mass(other.rest_mass), charge(other.charge),
          spin(other.spin), is_antiparticle(other.is_antiparticle),
          four_momentum(std::make_unique<fourMomentum>(*other.four_momentum)) {}

    // Copy assignment operator
    Particle& operator=(const Particle& other) 
    {
        if (this != &other) 
        {
            rest_mass = other.rest_mass;
            charge = other.charge;
            spin = other.spin;
            is_antiparticle = other.is_antiparticle;
            four_momentum = std::make_unique<fourMomentum>(*other.four_momentum);
        }
        return *this;
    }

    // Virtual function for printing particle summary
    virtual void print_summary() const;
    static double calculate_rest_mass(double E, double px, double py, double pz);
    double get_rest_mass() const;
    bool get_anti_state() const;
    friend fourMomentum operator+(const Particle& one, const Particle& two);
    friend double operator*(const Particle& one, const Particle& two);
};

#endif // PARTICLE_H
