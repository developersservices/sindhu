cmake_minimum_required(VERSION 3.10)
project(sindhuhu)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(sindhuhu
    src/main.cpp
    src/Lexer.cpp
    src/Parser.cpp
    src/AST.cpp
    src/Interpreter.cpp
    src/Token.cpp  # Include if Token.cpp has implementation details
)
