#pragma once

#include "ElementIntegralVariablePostprocessor.h"

class WeightDNPPostprocessor : public ElementIntegralVariablePostprocessor
{
public:
  static InputParameters validParams();
  WeightDNPPostprocessor(const InputParameters & parameters);

  virtual Real getValue() const override;

protected:
  virtual Real computeQpIntegral() override;

  const VariableValue & _other_var; // Adjoint neutron flux shape Quadrature-point values
  const PostprocessorValue & _norm; // Normalisation factor computed by another postprocessor
  Real _lambda; // Decay constant value
};
