#pragma once
#include <vector>
#include <string_view>
#include <stdexcept>
#include "Token.h"

namespace Lexer {
    class LexException : public std::runtime_error {
    protected:
        LexException(const char*);
    };

    struct EofException : public LexException {
        EofException();
    };

    class SymbolException : public LexException {
        char c;
        Location loc;
    public:
        SymbolException(Location, char);
        char get_char() const;
        Location get_location() const;
    };

    std::vector<Token> lex(std::string_view);
}