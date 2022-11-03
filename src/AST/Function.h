#pragma once

#include "Type.h"
#include "Node.h"
#include <string_view>
#include <vector>
#include <memory>

namespace AST {
    class Parameter {
        bool mut;
        std::string_view name;
        Type type;
    public:
        Parameter(std::string_view, bool, Type);
    };

    class FunctionSignature {
        std::vector<Parameter> params;
        std::string_view name;
    public:
        FunctionSignature(std::string_view, std::vector<Parameter>);
    };

    class Function {
        FunctionSignature signature;
        Block body;
    public:
        Function(FunctionSignature, Block);
    };

    class CallExpr : public Expression, public Statement {
        std::unique_ptr<Expression> func;
        std::vector<Expression> arguments;
    public:
        CallExpr(std::unique_ptr<Expression>, std::vector<Expression>);
    };
}