/**
 * This is a MOOSE AuxKernel that computes a new auxiliary variable by multiplying a regular field 
 * variable by a scalar variable (plus an optional normalization factor).
*/

// The headers bring in the class definition, MOOSE's scalar variable type, and libMesh's DOF map
// MOOSE internally uses dof_map to locate and retrieve the scalar variable's single DOF 
#include "ScalarMultiplication.h"
#include "MooseVariableScalar.h"
#include "libmesh/dof_map.h"

// Registers this object within the MOOSE app SquirrelApp, making it available in input files
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
  // Requires a standard coupled field variable (e.g. temperature)
  params.addRequiredCoupledVar("source_variable", "The variable to be multiplied");
  // Requires a scalar variable (e.g. a global multiplier)
  params.addRequiredParam<VariableName>("factor", "Name of the factor");
  // Requires a scalar variable (e.g. a global multiplier)
  params.addParam<bool>("invert_factor", false, "Take the invert of the factor");
  // Optional normalisation, defaults to 1
  params.addParam<Real>("normal_factor", 1.0, "The normalization factor");
  // Optional vector component to use, defaults to 0
  params.addParam<unsigned int>("component", 0, "Component to output for this variable");
  return params;
}

// MOOSE Definition of the constructor
ScalarMultiplication::ScalarMultiplication(const InputParameters & parameters)
  : AuxKernel(parameters),
  // coupledValue() gives access to the field variable's values at quadrature points (_qp)
  _src(coupledValue("source_variable")),
  // getScalarVariable() retrieves the scalar variable by name — this is the special path
  // needed for scalar (0D) variables, which aren't coupled the normal way   
  _var(_subproblem.getScalarVariable(_tid, getParam<VariableName>("factor"))),
  _invert_scalar(getParam<bool>("invert_factor")),
  _idx(getParam<unsigned int>("component")),
  _normal_factor(getParam<Real>("normal_factor"))
{
}

// Actual Calculation
Real
ScalarMultiplication::computeValue()
{
  // Refreshes the scalar variable's solution values (required before reading them) 
  _var.reinit();
  // Optional normalisation factor from the input file * 
  // The source field variable's value at the current quadrature point (_qp) *
  // The scalar variable's solution value (index [0] = first/only DOF)
  if (_invert_scalar)
    return _normal_factor * _src[_qp] /_var.sln()[_idx];
  else
    return _normal_factor * _src[_qp] * _var.sln()[_idx];
}
