#include "Lepton.h"
#include <iostream>

// Constructor 
Lepton::Lepton(double charge, double spin, double E, double px, double py, double pz, int leptonNumber, bool anti)
    : Particle(charge, spin, E, px, py, pz, anti), lepton_number(leptonNumber) {}

// Destructor
Lepton::~Lepton() {}

// Print
void Lepton::print_summary() const {
    std::cout << "Lepton - ";
    std::cout << "Mass: " << rest_mass << " MeV/c^2, ";
    std::cout << "Charge: " << charge << ", ";
    std::cout << "Spin: " << spin << ", ";
    std::cout << "Lepton Number: " << lepton_number << ", ";
    std::cout << "Antiparticle: " << (is_antiparticle ? "Yes" : "No") << std::endl;
}
