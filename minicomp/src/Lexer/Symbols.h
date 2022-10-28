#pragma once

#include <optional>
#include <string_view>

namespace Lexer {
    enum class Keyword {
        I8, I32, I64, F64,
        WHILE, IF, ELSE, RETURN,
        GOTO, BREAK, CONTINUE,
        FN, IMPORT, EXTERNAL, 
        VAR, LET, FALSE, TRUE,
        CONST, AS, BOOL, NIL,
        OR, AND,

        // Reserved for the future
        STRUCT, U8, U32, U64, F32,
        IMPL, ENUM, TRAIT, SELF,
        INLINE, MATCH, FOR, DO, IN,
    };

    std::optional<Keyword> keyword_from_str(std::string_view);
    const char* keyword_str(const Keyword&);

    enum class Symbol {
        ASTERISK,
        PLUS,
        MINUS,
        SLASH,
        CARET,
        PIPE,
        TILDE,
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
        GT,
        LT,
    };

    const char* symbol_str(const Symbol&);

    struct Grouper {
        enum class Direction;
        enum class Symbol;

        Grouper(Direction, Symbol);

        bool is_open() const;
        Symbol get_symbol() const;
        char get_char() const;

        static Grouper open(Symbol);
        static Grouper closed(Symbol);
    private:
        Direction dir;
        Symbol sym;
    };

    enum class Grouper::Direction {
        OPEN, CLOSED,
    };

    enum class Grouper::Symbol {
        PAREN,
        BRACE,
        CURLY,
    };

}