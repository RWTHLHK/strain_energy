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
  params.addRequiredParam<Real>("mu", "lame constants");
  return params;
}

TensileStrainEnergyAux::TensileStrainEnergyAux(const InputParameters & parameters)
  : RankTwoScalarAux(parameters), _lambda(getParam<Real>("lambda")),
  _mu(getParam<Real>("mu"))

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
    if (eigvals[i] > 0)
    {
      positive_part += eigvals[i]*Kronecker(eigvectors.column(i));
    }
  }
  
  Real strain_trace = _strain_tensor.tr(); // trace of total strain tensor
  if (strain_trace > 0)
    return 0.5 * _lambda * strain_trace * strain_trace + 
           _mu * (positive_part * positive_part).tr();
  else
    return _mu * (positive_part * positive_part).tr();
}
