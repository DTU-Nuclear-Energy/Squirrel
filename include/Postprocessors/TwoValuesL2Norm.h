#pragma once

#include "ElementIntegralVariablePostprocessor.h" // The base class of our object

class TwoValuesL2Norm : public ElementIntegralVariablePostprocessor
{
public:
  static InputParameters validParams();
  TwoValuesL2Norm(const InputParameters & parameters);

  virtual Real getValue() const override; // Function overridden in the src file

protected:
  virtual Real computeQpIntegral() override; // Function overridden in the src file

  const VariableValue & _other_var; // Adjoint neutron flux shape Quadrature-point values
};
