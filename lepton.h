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
    virtual void print_summary() const;
};


class electron : public Lepton 
{
private:
  std::vector<double> calorimeter_layers;

public:
  electron(double E, double p_x, double p_y, double p_z, bool anti = false);
  void print_summary() const override;
  const std::vector<double>& get_calorimeter_layers() const;
    
};

class muon : public Lepton 
{
private:
  bool is_isolated;

public:
  muon(double E, double p_x, double p_y, double p_z,  bool anti = false, bool isolated = false);
  void print_summary() const override;
  bool get_isolation_status() const;
};

class tau : public Lepton 
{
private:
  std::vector<std::shared_ptr<Lepton>> decay_products;
  std::string decay_flag;
public:
  tau(double E, double p_x, double p_y, double p_z, bool anti = false);
  void decay(int mode);  
  void print_decay_products() const;
  void print_summary() const override;
};
#endif 