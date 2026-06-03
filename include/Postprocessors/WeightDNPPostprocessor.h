#pragma once

#include "ElementIntegralVariablePostprocessor.h"

class WeightDNPPostprocessor : public ElementIntegralVariablePostprocessor
{
public:
  static InputParameters validParams();
  WeightDNPPostprocessor(const InputParameters & parameters);

  virtual Real getValue() const override; // Function overridden in the src file

protected:
  virtual Real computeQpIntegral() override; // Function overridden in the src file

  /// The variable to compare to
  const VariableValue & _other_var;
  const PostprocessorValue & _norm;
  Real _lambda;
};


//#pragma once
//
//#include "ElementIntegralVariablePostprocessor.h"
//
//class WeightDNPPostprocessor : public ElementIntegralVariablePostprocessor
//{
//public:
//  static InputParameters validParams();
//
//  WeightDNPPostprocessor(const InputParameters & parameters);
//
//  virtual void threadJoin(const UserObject & y) override;
//
//protected:
//  virtual Real computeQpIntegral() override;
//
//  /// The variable to compare to
//  const VariableValue & _other_var;
//  const PostprocessorValue & _norm;
//  Real _lambda;
//};
//
//
