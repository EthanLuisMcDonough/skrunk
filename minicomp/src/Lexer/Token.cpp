#include "Token.h"
#include <iostream>

using namespace Lexer;
using std::string_view, std::ostream;

Token::Token(Grouper g, Location s, Location e)
    : grouper(g), start(s), end(e), tag(Type::GROUPER) {}

Token::Token(string_view str, Token::Type t, Location s, Location e) 
    : str(str), start(s), end(e), tag(t) {}

Token::Token(Keyword k, Location s, Location e) 
    : keyword(k), start(s), end(e), tag(Type::KEYWORD) {}

Token::Token(Symbol sym, Location s, Location e) 
    : symbol(sym), start(s), end(e), tag(Type::SYMBOL) {}

Token::Token(char c, Location s, Location e)
    : i8(c), start(s), end(e), tag(Type::I8) {}

Token::Token(int i, Location s, Location e)
    : i32(i), start(s), end(e), tag(Type::I32) {}

Token::Token(long int i, Location s, Location e)
    : i64(i), start(s), end(e), tag(Type::I64) {}

Token::Token(double f, Location s, Location e)
    : f64(f), start(s), end(e), tag(Type::F64) {}

Token Token::string(string_view s, Location b, Location e) {
    return Token(s, Token::Type::STRING, b, e);
}

Token Token::ident(std::string_view s, Location b, Location e) {
    return Token(s, Token::Type::IDENTIFIER, b, e);
}

Token::Type Token::get_tag() const {
    return tag;
}

Location Token::get_start() const {
    return start;
}

Location Token::get_end() const {
    return end;
}

void Token::match(MatchArgs args) const {
    switch (tag) {
    case Token::Type::IDENTIFIER:
        args.ident(str);
        break;
    case Token::Type::GROUPER:
        args.grouper(grouper);
        break;
    case Token::Type::SYMBOL:
        args.symbol(symbol);
        break;
    case Token::Type::KEYWORD:
        args.keyword(keyword);
        break;
    case Token::Type::STRING:
        args.string(str);
        break;
    case Token::Type::I8:
        args.i8(i8);
        break;
    case Token::Type::I32:
        args.i32(i32);
        break;
    case Token::Type::I64:
        args.i64(i64);
        break;
    case Token::Type::F64:
        args.f64(f64);
        break;
    }
}

ostream& Token::print(ostream& stream) const {
    switch (tag) {
    case Token::Type::IDENTIFIER: 
        return stream << "Identifier(" << str << ")";
    case Token::Type::GROUPER:
        return stream << "Grouper('" << grouper.get_char() << "')";
    case Token::Type::SYMBOL:
        return stream << "Symbol('" << symbol_str(symbol) << "')";
    case Token::Type::KEYWORD:
        return stream << "Keyword(" << keyword_str(keyword) << ")";
    case Token::Type::STRING:
        return stream << "String(\"" << str << "\")";
    case Token::Type::I8:
        return stream << "I8(" << (int)i8 << ")"; 
    case Token::Type::I32:
        return stream << "I32(" << i32 << ")";
    case Token::Type::I64:
        return stream << "I64(" << i64 << ")";
    case Token::Type::F64:
        return stream << "F64(" << f64 << ")";
    }
    return stream;
}

ostream& Lexer::operator<<(ostream& stream, const Token& token) {
    return token.print(stream);
}