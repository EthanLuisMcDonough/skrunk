#include "Symbols.h"

using namespace Lexer;
using std::string_view, std::optional;

Grouper::Grouper(Grouper::Direction d, Grouper::Symbol s) {
    sym = s;
    dir = d;
}

bool Grouper::is_open() const {
    return dir == Grouper::Direction::OPEN;
}

Grouper::Symbol Grouper::get_symbol() const {
    return sym;
}

Grouper Grouper::open(Grouper::Symbol s) {
    return Grouper(Grouper::Direction::OPEN, s);
}

Grouper Grouper::closed(Grouper::Symbol s) {
    return Grouper(Grouper::Direction::CLOSED, s);
}

char Grouper::get_char() const {
    switch (sym) {
    case Grouper::Symbol::PAREN: return is_open() ? '(' : ')';
    case Grouper::Symbol::BRACE: return is_open() ? '[' : ']';
    case Grouper::Symbol::CURLY: return is_open() ? '{' : '}';
    }
    return '!';
}

optional<Keyword> Lexer::keyword_from_str(string_view s) {
    if (s == "as") return {Keyword::AS};
    if (s == "bool") return { Keyword::BOOL };
    if (s == "break") return { Keyword::BREAK };
    if (s == "const") return { Keyword::CONST };
    if (s == "continue") return { Keyword::CONTINUE };
    if (s == "else") return { Keyword::ELSE };
    if (s == "external") return { Keyword::EXTERNAL };
    if (s == "f64") return { Keyword::F64 };
    if (s == "false") return { Keyword::FALSE };
    if (s == "fn") return { Keyword::FN };
    if (s == "goto") return { Keyword::GOTO };
    if (s == "i32") return { Keyword::I32 };
    if (s == "i64") return { Keyword::I64 };
    if (s == "i8") return { Keyword::I8 };
    if (s == "import") return { Keyword::IMPORT };
    if (s == "let") return { Keyword::LET };
    if (s == "return") return { Keyword::RETURN };
    if (s == "while") return { Keyword::WHILE };
    if (s == "nil") return { Keyword::NIL };
    if (s == "and") return { Keyword::AND };
    if (s == "or") return { Keyword::OR };
    if (s == "struct") return { Keyword::STRUCT };
    if (s == "u8") return { Keyword::U8 };
    if (s == "u32") return { Keyword::U32 };
    if (s == "u64") return { Keyword::U64 };
    if (s == "f32") return { Keyword::F32 };
    if (s == "impl") return { Keyword::IMPL };
    if (s == "enum") return { Keyword::ENUM };
    if (s == "trait") return { Keyword::TRAIT };
    if (s == "self") return { Keyword::SELF };
    if (s == "inline") return { Keyword::INLINE };
    if (s == "match") return { Keyword::MATCH };
    if (s == "for") return { Keyword::FOR };
    if (s == "do") return { Keyword::DO };
    if (s == "in") return { Keyword::IN };
    if (s == "true") return { Keyword::TRUE };
    if (s == "pub") return { Keyword::PUB };
    return std::nullopt;
}

const char* Lexer::keyword_str(const Keyword& k) {
    switch (k) {
    case Keyword::AS: return "as";
    case Keyword::BOOL: return "bool";
    case Keyword::BREAK: return "break";
    case Keyword::CONST: return "const";
    case Keyword::CONTINUE: return "continue";
    case Keyword::ELSE: return "else";
    case Keyword::EXTERNAL: return "external";
    case Keyword::F64: return "f64";
    case Keyword::FALSE: return "false";
    case Keyword::FN: return "fn";
    case Keyword::GOTO: return "goto";
    case Keyword::I32: return "i32";
    case Keyword::I64: return "i64";
    case Keyword::I8: return "i8";
    case Keyword::IF: return "if";
    case Keyword::IMPORT: return "import";
    case Keyword::LET: return "let";
    case Keyword::RETURN: return "return";
    case Keyword::WHILE: return "while";
    case Keyword::NIL: return "nil";
    case Keyword::OR: return "or";
    case Keyword::AND: return "and";
    case Keyword::STRUCT: return "struct";
    case Keyword::U8: return "u8";
    case Keyword::U32: return "u32";
    case Keyword::U64: return "u64";
    case Keyword::F32: return "f32";
    case Keyword::IMPL: return "impl";
    case Keyword::ENUM: return "enum";
    case Keyword::TRAIT: return "trait";
    case Keyword::TRUE: return "true";
    case Keyword::SELF: return "self";
    case Keyword::INLINE: return "inline";
    case Keyword::MATCH: return "match";
    case Keyword::FOR: return "for";
    case Keyword::DO: return "do";
    case Keyword::IN: return "in";
    case Keyword::PUB: return "pub";
    }
    return "!!!UNACCOUNTED FOR KEYWORD IN keyword_str!!!";
}

const char* Lexer::symbol_str(const Symbol& s) {
    switch (s) {
    case Symbol::ASTERISK: return "*";
    case Symbol::PLUS: return "+";
    case Symbol::MINUS: return "-";
    case Symbol::SLASH: return "/";
    case Symbol::PIPE: return "|";
    case Symbol::CARET: return "^";
    case Symbol::TILDE: return "~";
    case Symbol::EQ: return "=";
    case Symbol::AMPERSAND: return "&";
    case Symbol::EXCLAMATION: return "!";
    case Symbol::SEMICOLON: return ";";
    case Symbol::COLON: return ":";
    case Symbol::PLUS_ASSIGN: return "+=";
    case Symbol::MINUS_ASSIGN: return "-=";
    case Symbol::MULT_ASSIGN: return "*=";
    case Symbol::DIV_ASSIGN: return "/=";
    case Symbol::ARROW: return "->";
    case Symbol::COMPARISON_EQ: return "==";
    case Symbol::NOT_EQ: return "!=";
    case Symbol::GTE: return ">=";
    case Symbol::LTE: return "<=";
    case Symbol::GT: return ">";
    case Symbol::LT: return "<";
    }
    return "!!!UNACCOUNTED FOR SYMBOL IN symbol_str!!!";
}