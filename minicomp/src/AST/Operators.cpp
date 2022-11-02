#include "Operators.h"

using namespace AST;
using std::string_view, std::unique_ptr, std::vector;

AssignmentExpr::AssignmentExpr(RValue r, AssignmentOperator op, unique_ptr<Expression> l)
    : right(std::move(r)), op(op), left(std::move(l)) {}

BinaryExpr::BinaryExpr(unique_ptr<Expression> r, BinaryOperator o, unique_ptr<Expression> l)
    : right(std::move(r)), op(o), left(std::move(l)) {}

UnaryExpr::UnaryExpr(UnaryOperator op, unique_ptr<Expression> e)
    : op(op), expr(std::move(e)) {}
