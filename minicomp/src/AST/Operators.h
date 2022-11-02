#pragma once

#include "Node.h"
#include "RValue.h"
#include <memory>
#include <string_view>
#include <vector>


namespace AST {
    enum class AssignmentOperator {
        BASIC,
        PLUS,
        MINUS,
        DIVIDE,
        MULTIPLY,
    };

    enum class BinaryOperator {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        CAST,
        LOGIC_OR,
        LOGIC_AND,
        LESS_THAN,
        GREATER_THAN,
        LTE, GTE,
    };

    enum class UnaryOperator {
        REFERENCE,
        NUMERIC_NEGATE,
        LOGIC_NEGATE,
        DEREF,
    };

    class AssignmentExpr : public Expression, public Statement {
        AssignmentOperator op;
        RValue right;
        std::unique_ptr<Expression> left;
    public:
        AssignmentExpr(RValue, AssignmentOperator, std::unique_ptr<Expression>);
    };

    class BinaryExpr : public Expression {
        BinaryOperator op;
        std::unique_ptr<Expression> right, left;
    public:
        BinaryExpr(std::unique_ptr<Expression>, BinaryOperator, std::unique_ptr<Expression>);
    };

    class UnaryExpr : public Expression {
        UnaryOperator op;
        std::unique_ptr<Expression> expr;
    public:
        UnaryExpr(UnaryOperator, std::unique_ptr<Expression>);
    };

}