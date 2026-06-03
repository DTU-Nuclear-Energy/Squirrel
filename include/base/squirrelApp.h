//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once // Ensures a header file is included only once during compilation

/**
 * The base class of our object: a MOOSE application. It provides all the core framework 
 * machinery: the factory system, problem setup, execution pipeline, mesh handling, etc. 
 * The Squirrel app just inherits all of it.
 */
#include "MooseApp.h"

// Declares squirrelApp as a public subclass of MooseApp
class squirrelApp : public MooseApp
{
public:
  // Required MOOSE methods
  static InputParameters validParams(); // Defines the input file syntax
  squirrelApp(InputParameters parameters); // Defines the constructor
  virtual ~squirrelApp(); // MooseApp uses a virtual destructor
  static void registerApps(); // Registers Squirrel as a MOOSE application
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s); // Connects Squirrel to the MOOSE framework 
};
