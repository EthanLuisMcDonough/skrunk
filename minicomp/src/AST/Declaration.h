#pragma once

#include "Node.h"
#include <string_view>

namespace AST {

    class Declarator {
        std::string_view name;
        Expression value;
    public:
        Declarator(std::string_view, Expression);
    };

    class Declaration : public Statement {
        std::vector<Declarator> declarators;
        bool mut;
    public:
        Declaration(std::vector<Declarator>, bool);
    };
}