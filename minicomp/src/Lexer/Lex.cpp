#include "Lex.h"
#include "ChPeeker.h"
#include <functional>
#include <cctype>
#include <string_view>
#include <climits>

using namespace Lexer;
using std::string, std::vector, std::function, std::string_view;

LexException::LexException(const char* m) : std::runtime_error(m) {};

EofException::EofException() : LexException("Unexpected end of file") {};

SymbolException::SymbolException(Location l, char c)
    : LexException("Unexpected symbol"), loc(l), c(c) {}

Location SymbolException::get_location() const {
    return loc;
}

char SymbolException::get_char() const {
    return c;
}

void eq_op(ChPeeker& c, vector<Token>& tokens, Symbol eq, Symbol no_eq, Location start) {
    tokens.emplace_back(c.next_eq('=') ? eq : no_eq, std::move(start), c.get_end());
}

vector<Token> Lexer::lex(string_view str) {
    std::vector<Token> tokens;
    ChPeeker c(str);

    while (auto ch = c.current()) {
        Location start = c.get_start();
        bool advance = true;

        switch (*ch) {
        case '#':
            c.skip_while([](char c) { return c != '\n'; });
            break;
        case ':':
            tokens.emplace_back(Symbol::COLON, std::move(start), c.get_end());
            break;
        case ';':
            tokens.emplace_back(Symbol::SEMICOLON, std::move(start), c.get_end());
            break;
        case '&':
            tokens.emplace_back(Symbol::AMPERSAND, std::move(start), c.get_end());
            break;
        case '|':
            tokens.emplace_back(Symbol::PIPE, std::move(start), c.get_end());
            break;
        case '^':
            tokens.emplace_back(Symbol::CARET, std::move(start), c.get_end());
            break;
        case '~':
            tokens.emplace_back(Symbol::TILDE, std::move(start), c.get_end());
            break;
        case '\"': {
            bool escaped = false;
            auto body = c.take_while([escaped] (char c) mutable {
                bool cont = c != '\"' || escaped;
                escaped = c == '\\';
                return cont;
            });

            if (!c.next_eq('\"')) {
                throw EofException();
            }

            tokens.push_back(Token::string(body, std::move(start), c.get_end()));
        } break;
        case '*': eq_op(c, tokens, Symbol::MULT_ASSIGN, Symbol::ASTERISK, std::move(start)); break;
        case '+': eq_op(c, tokens, Symbol::PLUS_ASSIGN, Symbol::PLUS, std::move(start)); break;
        case '/': eq_op(c, tokens, Symbol::DIV_ASSIGN, Symbol::SLASH, std::move(start)); break;
        case '-':
            if (auto n = c.next_any(">=")) {
                tokens.emplace_back(
                    n == '>' ? Symbol::ARROW : Symbol::MINUS_ASSIGN,
                    std::move(start), c.get_end());
            } else {
                tokens.emplace_back(Symbol::MINUS, std::move(start), c.get_end());
            }
            break;
        case '>': eq_op(c, tokens, Symbol::GTE, Symbol::GT, std::move(start)); break;
        case '<': eq_op(c, tokens, Symbol::LTE, Symbol::LT, std::move(start)); break;
        case '=': eq_op(c, tokens, Symbol::COMPARISON_EQ, Symbol::EQ, std::move(start)); break;
        case '!': eq_op(c, tokens, Symbol::NOT_EQ, Symbol::EXCLAMATION, std::move(start)); break;
        case '(':
            tokens.emplace_back(
                Grouper::open(Grouper::Symbol::PAREN),
                std::move(start), c.get_end());
            break;
        case ')':
            tokens.emplace_back(
                Grouper::closed(Grouper::Symbol::PAREN),
                std::move(start), c.get_end());
            break;
        case '[':
            tokens.emplace_back(
                Grouper::open(Grouper::Symbol::BRACE),
                std::move(start), c.get_end());
            break;
        case ']':
            tokens.emplace_back(
                Grouper::closed(Grouper::Symbol::BRACE),
                std::move(start), c.get_end());
            break;
        case '{':
            tokens.emplace_back(
                Grouper::open(Grouper::Symbol::CURLY),
                std::move(start), c.get_end());
            break;
        case '}':
            tokens.emplace_back(
                Grouper::closed(Grouper::Symbol::CURLY),
                std::move(start), c.get_end());
            break;
        case '\n':
        case ' ':
        case '\t':
        case '\v':
        case '\r':
            break;
        default:
            if (isdigit(*ch)) {
                long int front = *ch - '0';
                while (auto digit = c.next_if(isdigit)) {
                    front *= 10;
                    front += *digit - '0';
                }

                if (c.next_eq('.')) {
                    double d = (double)front;
                    for (int place = 10; auto dd = c.next_if(isdigit); place *= 10) {
                        d += (double)(*dd - '0') / place;
                    }

                    tokens.emplace_back(d, std::move(start), c.get_end());
                    c.next_eq('d');
                } else if (auto ty = c.next_any("lids")) {
                    switch (*ty) {
                    case 'l': tokens.emplace_back(front, std::move(start), c.get_end()); break;
                    case 'i': tokens.emplace_back((int)front, std::move(start), c.get_end()); break;
                    case 'd': tokens.emplace_back((double)front, std::move(start), c.get_end()); break;
                    case 's': tokens.emplace_back((char)front, std::move(start), c.get_end()); break;
                    }
                } else if (front > INT_MAX) {
                    tokens.emplace_back(front, std::move(start), c.get_end());
                } else {
                    tokens.emplace_back((int)front, std::move(start), c.get_end());
                }
            } else if (isalpha(*ch)) {
                auto body = c.take_while([](char c) {
                    return isalnum(c) || c == '_';
                });
                if (auto keyword = keyword_from_str(body)) {
                    tokens.emplace_back(*keyword, std::move(start), c.get_end());
                } else {
                    tokens.push_back(Token::ident(body, std::move(start), c.get_end()));
                }
                advance = false;
            } else {
                throw SymbolException(std::move(start), *ch);
            }
        }

        if (advance) {
            c.advance();
        }
    }

    return tokens;
}
