#pragma once // Ensures a header file is included only once during compilation

#include "ElementIntegralVariablePostprocessor.h" // The base class of our object

// Declares WeightDNPPostprocessor as a public subclass of ElementIntegralVariablePostprocessor
class WeightDNPPostprocessor : public ElementIntegralVariablePostprocessor
{
public:
  // Required MOOSE methods
  static InputParameters validParams(); // Defines the input file syntax
  WeightDNPPostprocessor(const InputParameters & parameters); // Defines the constructor

  virtual Real getValue() const override; // Function overridden in the src file

protected:
  virtual Real computeQpIntegral() override; // Function overridden in the src file

  const VariableValue & _other_var; // Adjoint neutron flux shape Quadrature-point values
  const PostprocessorValue & _norm; // Normalisation factor computed by another postprocessor
  Real _lambda; // Decay constant value
};
