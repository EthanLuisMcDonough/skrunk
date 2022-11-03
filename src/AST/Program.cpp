#include "Program.h"

using namespace AST;
using std::vector;

Program::Program(vector<Function> fns, vector<FunctionSignature> ffs) : 
    functions(std::move(fns)), ffi(std::move(ffs)) {}
