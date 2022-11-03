#include <iostream>
#include <vector>
#include <string_view>
#include "Peeker.h"
#include "Lex.h"

using std::vector;

int main(int argc, char* argv[]) {
    std::string_view test_code = "fn main() { let m = 20l as f64; var g = 19; \n #whatever \nif g < 3 { g = 95; } while g > 3 { g -= 6; }}";
    try {
        for (const auto& token : Lexer::lex(test_code)) {
            std::cout << token << ", ";
        }
    } catch (Lexer::LexException e) {
        std::cout << "Lex error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}