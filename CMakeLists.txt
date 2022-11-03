# CMakeList.txt : CMake project for skrunk, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("skrunk")

# Add source to this project's executable.
add_executable (skrunk "src/main.cpp" "src/AST/ControlFlow.cpp" "src/AST/ControlFlow.h" "src/AST/Declaration.cpp" "src/AST/Declaration.h" "src/AST/Function.cpp" "src/AST/Function.h" "src/AST/Literals.cpp" "src/AST/Literals.h" "src/AST/Node.cpp" "src/AST/Node.h" "src/AST/Operators.cpp" "src/AST/Operators.h" "src/AST/Program.cpp" "src/AST/Program.h" "src/AST/RValue.cpp" "src/AST/RValue.h" "src/AST/Type.cpp" "src/AST/Type.h" "src/Lexer/ChPeeker.cpp" "src/Lexer/ChPeeker.h" "src/Lexer/Lex.cpp" "src/Lexer/Lex.h" "src/Lexer/Location.cpp" "src/Lexer/Location.h" "src/Lexer/Symbols.cpp" "src/Lexer/Symbols.h" "src/Lexer/Token.cpp" "src/Lexer/Token.h" "src/Util/Peeker.cpp" "src/Util/Peeker.h")
set_property(TARGET skrunk PROPERTY CXX_STANDARD 20)

target_include_directories(skrunk PRIVATE "src/Lexer" "src/AST" "src/Util")