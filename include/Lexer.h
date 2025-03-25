#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <string>
#include <vector>

class Lexer {
public:
    Lexer(const std::string &source);
    std::vector<Token> tokenize();

private:
    char peek() const;
    char get();
    void skipWhitespace();
    std::string source;
    size_t current;
};

#endif // LEXER_H
