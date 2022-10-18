#include "Lexer.h"

Location::Location(unsigned int r, unsigned int c) {
    row = r;
    col = c;
}

Location::Location(void) : Location(0, 0) {};

void Location::feed(char c) {
    if (c == '\n') {
        row++;
        col = 0;
    } else {
        col++;
    }
}

Token::Token(std::string str, struct Location s, struct Location e) {
    identifier = str;
    start = s;
    end = e;
    tag = Type::IDENTIFIER;
}

Token::Token(enum Keyword k, struct Location s, struct Location e) {
    keyword = k;
    start = s;
    end = e;
    tag = Type::KEYWORD;
}

Token::Token(enum Symbol sym, struct Location s, struct Location e) {
    symbol = sym;
    start = s;
    end = e;
    tag = Type::SYMBOL;
}

std::vector<Token> lex(std::string const& str) {
    std::vector<Token> tokens;

    // @TODO

    return tokens;
}