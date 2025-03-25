#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "AST.h"
#include <vector>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    ExprPtr parseExpression();

private:
    const std::vector<Token>& tokens;
    size_t current;

    const Token& peek() const;
    const Token& get();
    bool match(TokenType type);
    ExprPtr parsePrimary();
};

#endif // PARSER_H
