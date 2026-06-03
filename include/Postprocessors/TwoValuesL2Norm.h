#pragma once

#include "ElementIntegralVariablePostprocessor.h" // The base class of our object

// Declares TwoValuesL2Norm as a public subclass of ElementIntegralVariablePostprocessor
class TwoValuesL2Norm : public ElementIntegralVariablePostprocessor
{
public:
  // Required MOOSE methods
  static InputParameters validParams(); // Defines the input file syntax
  TwoValuesL2Norm(const InputParameters & parameters); // Defines the constructor

  virtual Real getValue() const override; // Function overridden in the src file

protected:
  virtual Real computeQpIntegral() override; // Function overridden in the src file

  const VariableValue & _other_var; // Adjoint neutron flux shape Quadrature-point values
};
