#include "Literals.h"

using namespace AST;
using std::string_view, std::unique_ptr, std::vector;

IntExpr::IntExpr(int v) : value(v) {}

LongExpr::LongExpr(long int l) : value(l) {}

CharExpr::CharExpr(signed char c) : value(c) {}

DoubleExpr::DoubleExpr(double d) : value(d) {};

StringExpr::StringExpr(string_view s) : value(s) {}