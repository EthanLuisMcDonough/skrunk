#include "ControlFlow.h"

using std::vector, std::optional;
using namespace AST;

ConditionBodyPair::ConditionBodyPair(Expression e, Block b) 
    : expr(std::move(e)), body(std::move(b)) {}

WhileLoop::WhileLoop(ConditionBodyPair p) : pair(std::move(p)) {}

IfChain::IfChain(ConditionBodyPair p, vector<ConditionBodyPair> els, optional<Block> e) 
    : primary(std::move(p)), elseifs(std::move(els)), else_block(std::move(e)) {}

ReturnStmt::ReturnStmt(Expression e) : expr(std::move(e)) {}