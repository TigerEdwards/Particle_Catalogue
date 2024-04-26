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

electron::electron(double E, double p_x, double p_y, double p_z, bool anti)
: Lepton(anti ? 1.0 : -1.0, 0.5, E, p_x, p_y, p_z, anti ? -1.0 : 1.0, anti)
{
  double layer_energy = E / 4.0;
  calorimeter_layers = std::vector<double>(4, layer_energy);
}

void electron::print_summary() const 
{
  bool type = get_anti_state();
  std::cout<<(type? "Positron" : "Electron")<<"Electron Calorimeter Layers: ";
  for(auto layer : calorimeter_layers) 
  {
    std::cout<<layer<<" ";
  }
  std::cout<<std::endl;
  Lepton::print_summary();
}

muon::muon(double E, double p_x, double p_y, double p_z, bool anti, bool isolated)
: Lepton(anti ? 1.0 : -1.0, 0.5, E, p_x, p_y, p_z, anti ? -1.0 : 1.0, anti){}

void muon::print_summary() const 
{
  bool type = get_anti_state();
  std::cout<<(type? "Anti Muon" : "Muon")<<std::endl;
  Lepton::print_summary();
  std::cout<<"Isolation Status: "<<(is_isolated ? "Isolated" : "Not Isolated")<<std::endl;
}

tau::tau(double E, double p_x, double p_y, double p_z, bool anti)
: Lepton(anti ? 1.0 : -1.0, 0.5, E, p_x, p_y, p_z, anti ? -1.0 : 1.0, anti){}

void tau::decay(int mode) 
{
// Clear previous decay products
decay_products.clear();

if(mode == 0) 
{
  decay_products.push_back(std::make_shared<electron>(0.5, 0.1, 0.1, 0.1, true));
  decay_products.push_back(std::make_shared<electronNeutrino>(0.25, 0.05, 0.05, 0.05, false, true));
  decay_products.push_back(std::make_shared<tauNeutrino>(0.25, 0.05, 0.05, 0.05,true, false));
  decay_flag = "Tau decayed leptonically into electron and neutrinos."; 
} 
else if(mode == 1) 
{  
  decay_products.push_back(std::make_shared<muon>(0.5, 0.1, 0.1, 0.1,false));
  decay_products.push_back(std::make_shared<tauNeutrino>(0.25, 0.05, 0.05, 0.05,false, false));
  decay_flag ="Tau decayed leptonically into muon and neutrinos.";
} 
else if(mode == 2) 
{
  decay_flag ="Tau decayed hadronically.";
} 
else 
{
  decay_flag ="Invalid decay mode selected.";
}
}