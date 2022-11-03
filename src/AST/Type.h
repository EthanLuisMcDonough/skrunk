#pragma once

namespace AST {
    enum Primative {
        I8, I32, I64, F64
    };

    class Type {
        Primative type;
    public:
        Type(Primative);
    };

    class PointerType : public Type {
        unsigned int ref_level;
    public:
        PointerType(Primative);
        PointerType(Primative, unsigned int);
    };
}