#pragma once

namespace Lexer {
    struct Location {
        unsigned int row;
        unsigned int col;

        Location(unsigned int, unsigned int);
        Location();

        void feed(char);
    };
}