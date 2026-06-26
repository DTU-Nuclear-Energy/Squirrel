#pragma once

// The base class of our object: an AuxKernel object
#include "AuxKernel.h"

// Declares ScalarMultiplication as a public subclass of AuxKernel
class ScalarMultiplication : public AuxKernel
{
public:
  // Required MOOSE methods 
  static InputParameters validParams(); // Defines the input file syntax
  ScalarMultiplication(const InputParameters & parameters); // Defines the constructor

protected:
  // MOOSE AuxKernels must override computeValue() by the function declared in the src file
  virtual Real computeValue() override;
  
  // Quadrature-point values of the source field variable
  // The const enforces that you only read from it, never modify it
  const VariableValue & _src;
  // Scalar variable object (full object, not just values)
  MooseVariableScalar & _var;
  // boolean to invert the scalar variable
  bool _invert_scalar;
  unsigned int _idx; // Component index
  Real _normal_factor; // Normalisation factor
};
