#pragma once

#include "Function.h"
#include <string_view>
#include <vector>

namespace AST {
    class Program {
        std::vector<Function> functions;
        std::vector<FunctionSignature> ffi;
    public:
        Program(std::vector<Function>, std::vector<FunctionSignature>);
    };
}