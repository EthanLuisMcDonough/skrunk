#include "Node.h"

using namespace AST;
using std::vector;

Block::Block(vector<Statement> s) : statements(std::move(s)) {}