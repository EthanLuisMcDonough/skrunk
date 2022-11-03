#include "Declaration.h"

using namespace AST;
using std::vector, std::string_view;

Declaration::Declaration(vector<Declarator> d, bool b)
    : declarators(std::move(d)), mut(b) {}

Declarator::Declarator(string_view s, Expression e)
    : name(s), value(std::move(e)) {}