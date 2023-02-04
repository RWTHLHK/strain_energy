#include "TensileStrainEnergy.h"
#include "MooseUtils.h"
#include "metaphysicl/raw_type.h"
registerMooseObject("strain_energyApp", TensileStrainEnergyAux);

InputParameters
TensileStrainEnergyAux::validParams()
{
  InputParameters params = RankTwoScalarAux::validParams();
  params.addClassDescription("compute tensile strain energy");
  return params;
}

TensileStrainEnergyAux::TensileStrainEnergyAux(const InputParameters & parameters)
  : RankTwoScalarAux(parameters)
{
  RankTwoTensor _strain_tensor = MetaPhysicL::raw_value(_tensor[_qp]);
}

Real
TensileStrainEnergyAux::computeValue()
{
  RankTwoTensor tensor = MetaPhysicL::raw_value(_tensor[_qp]);
  return _strain_tensor.tr();
}
