#include "RValue.h"

using namespace AST;
using std::string_view, std::unique_ptr;

IdentExpr::IdentExpr(string_view s) : name(s) {}

IndexExpr::IndexExpr(unique_ptr<Expression> v, unique_ptr<Expression> i)
    : value(std::move(v)), index(std::move(i)) {}

DerefRValue::DerefRValue(Expression e) : expression(std::move(e)) {}
