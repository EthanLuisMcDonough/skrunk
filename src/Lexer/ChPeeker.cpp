#include "ChPeeker.h"

using namespace Lexer;
using std::string_view, std::function, std::optional;

ChPeeker::ChPeeker(string_view ref) 
    : Util::Peeker<string_view::iterator>(ref.begin(), ref.end()), 
        loc(), str(ref) {}

const optional<char>& ChPeeker::advance() {
    auto c = current();
    auto result = Util::Peeker<string_view::iterator>::advance();
    if (result) { loc.feed(*c); }
    return current();
}

Location ChPeeker::get_start() const {
    return loc;
}

Location ChPeeker::get_end() const {
    Location l = loc;
    if (auto c = current()) {
        l.feed(*c);
    }
    return l;
}

string_view ChPeeker::take_while(function<bool(char)> predicate) {
    auto start = get_index();
    skip_while(predicate);
    return str.substr(start, get_index() - start);
}

const optional<char>& ChPeeker::next_eq(char c) {
    return next_if([c](char ch) { return ch == c; });
}

const optional<char>& ChPeeker::next_any(const char* c) {
    return next_if([c](char ch) { 
        for (int i = 0; c[i] != '\0'; i++) {
            if (c[i] == ch) { return true; }
        }
        return false;
    });
}