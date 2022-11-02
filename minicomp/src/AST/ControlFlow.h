#pragma once

#include "Node.h"
#include <vector>
#include <optional>

namespace AST {
    class ConditionBodyPair {
        Expression expr;
        Block body;
    public:
        ConditionBodyPair(Expression, Block);
    };

    class WhileLoop : public Statement {
        ConditionBodyPair pair;
    public:
        WhileLoop(ConditionBodyPair);
    };

    class IfChain : public Statement {
        ConditionBodyPair primary;
        std::vector<ConditionBodyPair> elseifs;
        std::optional<Block> else_block;
    public:
        IfChain(ConditionBodyPair, std::vector<ConditionBodyPair>, std::optional<Block>);
    };

    class BreakStmt : public Statement {};
    class ContinueStmt : public Statement {};
    class ReturnStmt : public Statement {
        Expression expr;
    public:
        ReturnStmt(Expression);
    };
}