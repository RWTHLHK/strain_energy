#pragma once
#include "AuxKernel.h"
#include "RankTwoTensor.h"
#include "RankTwoScalarAux.h"
#include "Algebra.h"
class TensileStrainEnergyAux : public RankTwoScalarAux
{
public:
  static InputParameters validParams();
  TensileStrainEnergyAux(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;
  const RankTwoTensor _strain_tensor; // rank 2 tensor of total strain
  const Real _lambda; // lame constant
  const Real _mu; // lame constant
};
