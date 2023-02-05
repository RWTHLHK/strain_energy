#include "TensileStrainEnergy.h"
#include "MooseUtils.h"
#include "metaphysicl/raw_type.h"
#include <vector>
registerMooseObject("strain_energyApp", TensileStrainEnergyAux);

InputParameters
TensileStrainEnergyAux::validParams()
{
  InputParameters params = RankTwoScalarAux::validParams();
  params.addClassDescription("compute tensile strain energy");
  params.addRequiredParam<Real>("lambda", "lame constants");
  return params;
}

TensileStrainEnergyAux::TensileStrainEnergyAux(const InputParameters & parameters)
  : RankTwoScalarAux(parameters), _lambda(getParam<Real>("lambda"))

{
  RankTwoTensor _strain_tensor = MetaPhysicL::raw_value(_tensor[_qp]);
}

Real
TensileStrainEnergyAux::computeValue()
{
  std::vector<Real> eigvals;
  RankTwoTensor eigvectors;
  _strain_tensor.symmetricEigenvaluesEigenvectors(eigvals, eigvectors);
  RankTwoTensor positive_part;
  for (auto i : make_range(3))
  {
    for (auto j : make_range(3))
    {
      positive_part(i, j) = 0;
    }
  }
  for (auto i : make_range(3))
  {
    if (eigvals(i) > 0)
    {
      positive_part += 0;
    }
  }
  Real strain_trace = _strain_tensor.tr(); // trace of total strain tensor
  if (strain_trace > 0)
    return 0.5 * _lambda * strain_trace * strain_trace;
  else
    return 0;
}
