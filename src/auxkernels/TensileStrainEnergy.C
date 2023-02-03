#include "TensileStrainEnergy.h"
registerMooseObject("strain_energyApp", TensileStrainEnergyAux);

InputParameters
TensileStrainEnergyAux::validParams(){
    InputParameters params = RankTwoScalarAux::validParams();
    params.addClassDecription("compute tensile strain energy")
    return params;
}