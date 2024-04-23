// fourMomentum.h
#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include <iostream>
#include <vector>

class fourMomentum 
{
public:
  double energy;
  std::vector<double> momentum; 

  // Constructor
  fourMomentum(double E, double p_x, double p_y, double p_z)
  : energy(E), momentum({p_x, p_y, p_z}) 
  {
    std::cout<<"FourMomentum Constructor Called."<<std::endl;
  }

  // Copy constructor
  fourMomentum(const fourMomentum& other)
  : energy(other.energy), momentum(other.momentum) 
  {
    std::cout<<"FourMomentum Copy Constructor Called."<<std::endl;
  }

  // Copy assignment operator
  fourMomentum& operator=(const fourMomentum& other) 
  {
    if (this != &other) 
    {
        energy = other.energy;
        momentum = other.momentum;
    }
    std::cout<<"FourMomentum Copy Assignment Called."<<std::endl;
    return *this;
  }

// Move constructor
  fourMomentum(fourMomentum&& other) noexcept
  : energy(std::move(other.energy)), momentum(std::move(other.momentum)) 
  {
    std::cout<<"FourMomentum Move Constructor Called."<<std::endl;
  }

  // Move assignment operator
  fourMomentum& operator=(fourMomentum&& other) noexcept 
  {
    if (this != &other) 
    {
        energy = std::move(other.energy);
        momentum = std::move(other.momentum);
    }
    std::cout<<"FourMomentum Move Assignment Called."<<std::endl;
    return *this;
  }

// Destructor
  ~fourMomentum() 
  {
    std::cout<<"FourMomentum Destructor Called."<<std::endl;
  }
  //Getters
  double get_energy() const { return energy; }
  double get_px() const { return momentum[0]; }
  double get_py() const { return momentum[1]; }
  double get_pz() const { return momentum[2]; }

  // Setters
  void set_energy(double E) { energy = E; }
  void set_px(double px) { momentum[0] = px; }
  void set_py(double py) { momentum[1] = py; }
  void set_pz(double pz) { momentum[2] = pz; }
  };

#endif
