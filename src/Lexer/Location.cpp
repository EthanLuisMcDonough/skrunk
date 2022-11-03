#include "Location.h"

using namespace Lexer;

Location::Location(unsigned int r, unsigned int c) : row(r), col(c) {}
Location::Location() : Location(0, 0) {}

void Location::feed(char c) {
    if (c == '\n') {
        row++;
        col = 0;
    }
    else {
        col++;
    }
}