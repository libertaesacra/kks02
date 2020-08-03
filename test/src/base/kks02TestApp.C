//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "kks02TestApp.h"
#include "kks02App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
kks02TestApp::validParams()
{
  InputParameters params = kks02App::validParams();
  return params;
}

kks02TestApp::kks02TestApp(InputParameters parameters) : MooseApp(parameters)
{
  kks02TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

kks02TestApp::~kks02TestApp() {}

void
kks02TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  kks02App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"kks02TestApp"});
    Registry::registerActionsTo(af, {"kks02TestApp"});
  }
}

void
kks02TestApp::registerApps()
{
  registerApp(kks02App);
  registerApp(kks02TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
kks02TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kks02TestApp::registerAll(f, af, s);
}
extern "C" void
kks02TestApp__registerApps()
{
  kks02TestApp::registerApps();
}
