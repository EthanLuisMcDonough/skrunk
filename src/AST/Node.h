#pragma once

#include <vector>

namespace AST {
    class Statement {};
    class Expression {};

    class Block {
        std::vector<Statement> statements;
    public:
        Block(std::vector<Statement>);
    };
}