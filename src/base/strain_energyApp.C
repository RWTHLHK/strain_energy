#include "strain_energyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
strain_energyApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

strain_energyApp::strain_energyApp(InputParameters parameters) : MooseApp(parameters)
{
  strain_energyApp::registerAll(_factory, _action_factory, _syntax);
}

strain_energyApp::~strain_energyApp() {}

void
strain_energyApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"strain_energyApp"});
  Registry::registerActionsTo(af, {"strain_energyApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
strain_energyApp::registerApps()
{
  registerApp(strain_energyApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
strain_energyApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  strain_energyApp::registerAll(f, af, s);
}
extern "C" void
strain_energyApp__registerApps()
{
  strain_energyApp::registerApps();
}
