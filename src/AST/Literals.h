#pragma once

#include "Node.h"
#include <memory>
#include <string_view>
#include <vector>

namespace AST {
    class IntExpr : public Expression {
        int value;
    public:
        IntExpr(int);
    };

    class LongExpr : public Expression {
        long int value;
    public:
        LongExpr(long int);
    };

    class CharExpr : public Expression {
        signed char value;
    public:
        CharExpr(signed char);
    };

    class DoubleExpr : public Expression {
        double value;
    public:
        DoubleExpr(double);
    };

    class StringExpr : public Expression {
        std::string_view value;
    public:
        StringExpr(std::string_view);
    };
}