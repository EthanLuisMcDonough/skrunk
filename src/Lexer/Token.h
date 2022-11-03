#pragma once

#include <iostream>
#include <vector>
#include <string_view>
#include <functional>
#include "Location.h"
#include "Symbols.h"

namespace Lexer {
    struct MatchArgs {
        std::function<void(Symbol)> symbol = [](auto _) {};
        std::function<void(Grouper)> grouper = [](auto _) {};
        std::function<void(Keyword)> keyword = [](auto _) {};
        std::function<void(std::string_view)> string = [](auto _) {};
        std::function<void(std::string_view)> ident = [](auto _) {};
        std::function<void(char)> i8 = [](auto _) {};
        std::function<void(int)> i32 = [](auto _) {};
        std::function<void(long int)> i64 = [](auto _) {};
        std::function<void(double)> f64= [](auto _) {};
    };

    struct Token {
        enum class Type;

        Token(Keyword, Location, Location);
        Token(std::string_view, Type, Location, Location);

        Token(Grouper, Location, Location);
        Token(Symbol, Location, Location);

        Token(char, Location, Location);
        Token(int, Location, Location);
        Token(long int, Location, Location);
        Token(double, Location, Location);

        static Token string(std::string_view, Location, Location);
        static Token ident(std::string_view, Location, Location);

        Type get_tag() const;
        Location get_start() const;
        Location get_end() const;

        void match(MatchArgs) const;
        std::ostream& print(std::ostream&) const;
    private:
        Type tag;
        Location start, end;

        union {
            Symbol symbol;
            Grouper grouper;
            Keyword keyword;

            std::string_view str;
            char i8;

            int i32;
            long int i64;

            double f64;
        };
    };

    enum class Token::Type {
        KEYWORD, IDENTIFIER,
        SYMBOL, GROUPER, STRING,
        I8, I32, I64, F64,
    };

    std::ostream& operator<<(std::ostream&, const Token&);
}