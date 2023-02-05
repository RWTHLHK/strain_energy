#pragma once
#include "AuxKernel.h"

class HistoricalMaxStrainEnergyAux : public AuxKernel
{
public:
  static InputParameters validParams();
  HistoricalMaxStrainEnergyAux(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;
  const Real _strain_energy; // strain_energy
  Real _H; // Historical Maximum Strain Energy
};
