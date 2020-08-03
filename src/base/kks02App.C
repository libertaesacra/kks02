#include "kks02App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kks02App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

kks02App::kks02App(InputParameters parameters) : MooseApp(parameters)
{
  kks02App::registerAll(_factory, _action_factory, _syntax);
}

kks02App::~kks02App() {}

void
kks02App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"kks02App"});
  Registry::registerActionsTo(af, {"kks02App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kks02App::registerApps()
{
  registerApp(kks02App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kks02App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kks02App::registerAll(f, af, s);
}
extern "C" void
kks02App__registerApps()
{
  kks02App::registerApps();
}
