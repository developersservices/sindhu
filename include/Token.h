#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    Identifier,
    Number,
    Plus,
    Minus,
    Star,
    Slash,
    Equal,
    Semicolon,
    EndOfFile,
    Unknown
};

struct Token {
    TokenType type;
    std::string text;
    Token(TokenType type, const std::string &text) : type(type), text(text) {}
};

#endif // TOKEN_H
