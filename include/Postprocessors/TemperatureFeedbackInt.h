#pragma once

#include "ElementIntegralVariablePostprocessor.h"

class TemperatureFeedbackInt : public ElementIntegralVariablePostprocessor

{
public:
  static InputParameters validParams();
  TemperatureFeedbackInt(const InputParameters & parameters);

  virtual Real getValue() const override;

protected:
  virtual Real computeQpIntegral() override;
  
  const VariableValue & _T_ref; // Reference temperature Quadrature-point values
  const VariableValue & _flux; // Adjoint neutron flux shape Quadrature-point values
  const PostprocessorValue & _Norm; // Normalisation factor computed by another postprocessor
  Real _total_rho; // Total change in reactivity value
};
