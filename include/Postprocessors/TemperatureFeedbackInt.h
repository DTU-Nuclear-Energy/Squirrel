#pragma once

#include "ElementIntegralVariablePostprocessor.h" // The base class of our object

// Declares TemperatureFeedbackInt as a public subclass of ElementIntegralVariablePostprocessor
class TemperatureFeedbackInt : public ElementIntegralVariablePostprocessor
{
public:
  // Required MOOSE methods
  static InputParameters validParams();
  TemperatureFeedbackInt(const InputParameters & parameters);

  virtual Real getValue() const override; // Function overridden in the src file

protected:
  virtual Real computeQpIntegral() override; // Function overridden in the src file
  
  const VariableValue & _T_ref; // Reference temperature Quadrature-point values
  const VariableValue & _flux; // Adjoint neutron flux shape Quadrature-point values
  const PostprocessorValue & _Norm; // Normalisation factor computed by another postprocessor
  Real _total_rho; // Total change in reactivity value
};
