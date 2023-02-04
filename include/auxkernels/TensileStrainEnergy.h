#pragma once
#include "AuxKernel.h"
#include "RankTwoTensor.h"
#include "RankTwoScalarAux.h"

class TensileStrainEnergyAux : public RankTwoScalarAux
{
public:
  static InputParameters validParams();
  TensileStrainEnergyAux(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;
  const RankTwoTensor _strain_tensor; // rank 2 tensor of total strain

private:
  RankTwoTensor computeTensileStrainTensor();
};
