#include "Particle.h"

// Constructor
Particle::Particle( double E, double px, double py, double pz, double charge, double spin, bool anti)
    : charge(charge), spin(spin), is_antiparticle(anti),
      four_momentum(std::make_unique<fourMomentum>(E, px, py, pz)) 
      {rest_mass = calculate_rest_mass(E, px, py, pz);}

// Virtual destructor
Particle::~Particle(){}

double Particle::calculate_rest_mass(double E, double px, double py, double pz) 
{
  return sqrt(E*E - (px*px + py*py + pz*pz)); 
}

double Particle::get_rest_mass() const 
{
  return rest_mass;
}

void Particle::print_summary() const 
{
    std::cout << "Mass: " << rest_mass
              << ", Charge: " << charge
              << ", Spin: " << spin
              << ", Antiparticle: " << (is_antiparticle ? "Yes" : "No") 
              << ", Four-Momentum: (E=" << four_momentum->get_energy()
              << ", px=" << four_momentum->get_px()
              << ", py=" << four_momentum->get_py()
              << ", pz=" << four_momentum->get_pz() << ")" 
              << std::endl;
}

// Four Momentum Sum
fourMomentum operator+(const Particle& one, const Particle& two) 
{
    return fourMomentum(
        one.four_momentum->get_energy() + two.four_momentum->get_energy(),
        one.four_momentum->get_px() + two.four_momentum->get_px(),
        one.four_momentum->get_py() + two.four_momentum->get_py(),
        one.four_momentum->get_pz() + two.four_momentum->get_pz()
    );
}
//Dot Product
double operator*(const Particle& one, const Particle& two) {
    double product = one.four_momentum->get_energy() * two.four_momentum->get_energy();
    product -= one.four_momentum->get_px() * two.four_momentum->get_px() +
               one.four_momentum->get_py() * two.four_momentum->get_py() +
               one.four_momentum->get_pz() * two.four_momentum->get_pz();
    return product;
}