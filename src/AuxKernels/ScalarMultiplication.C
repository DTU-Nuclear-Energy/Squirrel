/**
 * This is a MOOSE AuxKernel that computes a new auxiliary variable by multiplying a regular field 
 * variable by a scalar variable (plus an optional normalization factor).
*/

#include "ScalarMultiplication.h"
#include "MooseVariableScalar.h"
#include "libmesh/dof_map.h"

registerMooseObject("squirrelApp", ScalarMultiplication);

// MOOSE Input file interface
/**
 * This defines what users write in the .i input file. source_variable is a standard coupled field 
 * variable, while factor is explicitly a scalar variable (one value for the whole domain, 
 * not per node/element).
 */
InputParameters
ScalarMultiplication::validParams()
{
  InputParameters params = AuxKernel::validParams();
  params.addClassDescription("Multiplies a variable based on a scalar value.");
  params.addRequiredCoupledVar("source_variable", "The variable to be multiplied");
  params.addRequiredParam<VariableName>("factor", "Name of the factor");
  params.addParam<Real>("normal_factor", 1.0, "The normalization factor");
  return params;
}

ScalarMultiplication::ScalarMultiplication(const InputParameters & parameters)
  : AuxKernel(parameters),
    _src(coupledValue("source_variable")),
    _var(_subproblem.getScalarVariable(_tid, getParam<VariableName>("factor"))),
    _normal_factor(getParam<Real>("normal_factor"))
{
}



Real
ScalarMultiplication::computeValue()
{
  _var.reinit();

return _normal_factor*_src[_qp] * _var.sln()[0];
}



