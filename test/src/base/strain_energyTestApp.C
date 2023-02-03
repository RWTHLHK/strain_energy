//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "strain_energyTestApp.h"
#include "strain_energyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
strain_energyTestApp::validParams()
{
  InputParameters params = strain_energyApp::validParams();
  return params;
}

strain_energyTestApp::strain_energyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  strain_energyTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

strain_energyTestApp::~strain_energyTestApp() {}

void
strain_energyTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  strain_energyApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"strain_energyTestApp"});
    Registry::registerActionsTo(af, {"strain_energyTestApp"});
  }
}

void
strain_energyTestApp::registerApps()
{
  registerApp(strain_energyApp);
  registerApp(strain_energyTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
strain_energyTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  strain_energyTestApp::registerAll(f, af, s);
}
extern "C" void
strain_energyTestApp__registerApps()
{
  strain_energyTestApp::registerApps();
}
