#pragma once

#include <vector>
#include <string>

enum class Keyword {
    I8, I16, I32, I64,
    U8, U16, U32, U64,
    WHILE, FOR, DO,
    IF, ELSE, RETURN,
    GOTO, BREAK, CONTINUE,
    MATCH, FN, IMPORT,
    EXTERNAL, VAR, LET,
    CONST,
};

enum class Symbol {
    OPEN_PAREN,
    CLOSED_PAREN,
    OPEN_BRACKET,
    CLOSED_BRACKET,
    OPEN_CURLY,
    CLOSED_CURLY,

    ASTERISK,
    PLUS,
    MINUS,
    SLASH,
    EQ,
    AMPERSAND,
    EXCLAMATION,

    SEMICOLON,
    COLON,

    PLUS_ASSIGN,
    MINUS_ASSIGN,
    MULT_ASSIGN,
    DIV_ASSIGN,
    ARROW,

    COMPARISON_EQ,
    NOT_EQ,
    GTE,
    LTE,
};

struct Location {
    unsigned int row;
    unsigned int col;

    Location(unsigned int, unsigned int);
    Location(void);

    void feed(char);
};

struct Token {
    enum class Type;

    Type tag;
    Location start, end;
    union {
        Keyword keyword;
        Symbol symbol;
        std::string identifier;
    };

    Token(Keyword, Location, Location);
    Token(Symbol, Location, Location);
    Token(std::string, Location, Location);
};

enum class Token::Type {
    KEYWORD, IDENTIFIER, SYMBOL
};

std::vector<Token> lex(std::string const&);