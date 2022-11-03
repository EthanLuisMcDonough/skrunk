#include "Type.h"

using namespace AST;

Type::Type(Primative p) : type(p) {}

PointerType::PointerType(Primative p, unsigned int l) 
    : Type(p), ref_level(l) {}

PointerType::PointerType(Primative p) : PointerType(p, 1) {}