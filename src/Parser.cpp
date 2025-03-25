#include "Parser.h"
#include <stdexcept>
#include <cstdlib>

Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens), current(0) {}

const Token& Parser::peek() const {
    return tokens[current];
}

const Token& Parser::get() {
    return tokens[current++];
}

bool Parser::match(TokenType type) {
    if (peek().type == type) {
        get();
        return true;
    }
    return false;
}

ExprPtr Parser::parsePrimary() {
    const Token& token = get();
    if (token.type == TokenType::Number) {
        int value = std::atoi(token.text.c_str());
        return std::make_unique<NumberExpr>(value);
    } else if (token.type == TokenType::Identifier) {
        return std::make_unique<VariableExpr>(token.text);
    }
    throw std::runtime_error("Unexpected token in primary expression");
}

ExprPtr Parser::parseExpression() {
    // For simplicity, we handle binary expressions with '+' and '-' only.
    ExprPtr left = parsePrimary();

    while (peek().type == TokenType::Plus || peek().type == TokenType::Minus) {
        Token op = get();
        ExprPtr right = parsePrimary();
        left = std::make_unique<BinaryExpr>(std::move(left), op, std::move(right));
    }
    return left;
}
