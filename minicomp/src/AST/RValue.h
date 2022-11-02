#pragma once

#include "Node.h"
#include <string_view>
#include <memory>

namespace AST {
    class RValue {};

    class IdentExpr : public Expression, public RValue {
        std::string_view name;
    public:
        IdentExpr(std::string_view);
    };

    class IndexExpr : public Expression, public RValue {
        std::unique_ptr<Expression> value, index;
    public:
        IndexExpr(std::unique_ptr<Expression>, std::unique_ptr<Expression>);
    };

    class DerefRValue : public RValue {
        Expression expression;
    public:
        DerefRValue(Expression);
    };
}