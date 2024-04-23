#include "Quark.h"
#include <iostream>

// Constructor 
Quark::Quark(double charge, double spin, double E, double px, double py, double pz, double b_number, bool anti)
        : Particle(charge, spin, E, px, py, pz, anti), baryon_number(b_number) {}

// Destructor
Quark::~Quark() {}

//Print Function
void Quark::print_summary() const {
    std::cout << "Quark - ";
    std::cout << "Mass: " << rest_mass << " MeV/c^2, ";
    std::cout << "Charge: " << charge << ", ";
    std::cout << "Spin: " << spin << ", ";
    std::cout << "Baryon Number: " << baryon_number << ", ";
    std::cout << "Antiparticle: " << (is_antiparticle ? "Yes" : "No") << std::endl;
}
