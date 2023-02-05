#include "HistoricalMaxStrainEnergy.h"
registerMooseObject("strain_energyApp", HistoricalMaxStrainEnergyAux);
InputParameters
HistoricalMaxStrainEnergyAux::validParams()
{
  InputParameters params = AuxKernel::validParams();
  params.addClassDescription("record historical maximum strain energy");
  params.addRequiredParam<Real>("strain_energy", "current strain energy");
  return params;
}

HistoricalMaxStrainEnergyAux::HistoricalMaxStrainEnergyAux(const InputParameters & parameters)
  : AuxKernel(parameters), _strain_energy(getParam<Real>("strain_energy")),
  _H(0)
{
}

Real
HistoricalMaxStrainEnergyAux::computeValue(){
    if (_H < _strain_energy)
    {
        _H = _strain_energy; //update historical maximum
    }
    return _H;
}
