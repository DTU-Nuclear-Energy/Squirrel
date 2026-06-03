#pragma once

#include "AuxKernel.h" // The base class of our object

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
  MooseVariableScalar & _var; // Scalar variable object
  Real _normal_factor; // Normalisation factor
};
