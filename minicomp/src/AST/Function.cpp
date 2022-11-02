#include "Function.h"

using namespace AST;
using std::string_view, std::vector;

Parameter::Parameter(string_view s, bool mut, Type type)
    : name(s), mut(mut), type(type) {}

FunctionSignature::FunctionSignature(string_view s, vector<Parameter> params)
    : name(s), params(std::move(params)) {}

Function::Function(FunctionSignature s, Block b)
    : signature(s), body(b) {}