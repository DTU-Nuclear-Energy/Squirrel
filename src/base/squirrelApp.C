/**
 * This is the top-level application file of a MOOSE app. 
 * It connects the custom objects developed in the Squirrel app to the MOOSE framework.
*/

#include "squirrelApp.h" // Own class definition
#include "Moose.h"       // Core MOOSE framework
#include "AppFactory.h"  // Factory for creating app instances
#include "ModulesApp.h"  // MOOSE physics modules (e.g. Navier-Stokes)
#include "MooseSyntax.h" // Input file syntax registration system

// MOOSE syntax to get, set and convert parameters from the input file to Kernels
InputParameters
squirrelApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  return params;
}

// The class constructor simply calls registerAll()
// _factory, _action_factory, and _syntax are all protected members inherited from MooseApp
squirrelApp::squirrelApp(InputParameters parameters) : MooseApp(parameters)
{
  ModulesApp::registerAllObjects<squirrelApp>(_factory, _action_factory, _syntax);
}

squirrelApp::~squirrelApp() {} // MOOSE handles the destructor internally

// registerAll() is the most important method: it connects Squirrel to the MOOSE framework 
void
squirrelApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  // Registers all built-in MOOSE physics modules and makes them available in the input files
  ModulesApp::registerAllObjects<squirrelApp>(f, af, syntax);
  // Registers all custom objects tagged with registerMooseObject("squirrelApp",...)
  Registry::registerObjectsTo(f, {"squirrelApp"});
  // Registers any custom Actions (advanced input file syntax handlers) tagged with squirrelApp
  Registry::registerActionsTo(af, {"squirrelApp"});
}

// Registers Squirrel with the AppFactory, to use it as a sub-app inside another MOOSE application
void
squirrelApp::registerApps()
{
  registerApp(squirrelApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
squirrelApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  squirrelApp::registerAll(f, af, s);
}
extern "C" void
squirrelApp__registerApps()
{
  squirrelApp::registerApps();
}
