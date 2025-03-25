#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string &source) : source(source), current(0) {}

char Lexer::peek() const {
    if (current < source.size()) return source[current];
    return '\0';
}

char Lexer::get() {
    return source[current++];
}

void Lexer::skipWhitespace() {
    while (std::isspace(peek())) {
        get();
    }
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (current < source.size()) {
        skipWhitespace();
        char c = peek();
        if (std::isdigit(c)) {
            std::string num;
            while (std::isdigit(peek())) {
                num.push_back(get());
            }
            tokens.emplace_back(TokenType::Number, num);
        } else if (std::isalpha(c)) {
            std::string ident;
            while (std::isalnum(peek())) {
                ident.push_back(get());
            }
            tokens.emplace_back(TokenType::Identifier, ident);
        } else {
            switch (c) {
                case '+':
                    tokens.emplace_back(TokenType::Plus, std::string(1, get()));
                    break;
                case '-':
                    tokens.emplace_back(TokenType::Minus, std::string(1, get()));
                    break;
                case '*':
                    tokens.emplace_back(TokenType::Star, std::string(1, get()));
                    break;
                case '/':
                    tokens.emplace_back(TokenType::Slash, std::string(1, get()));
                    break;
                case '=':
                    tokens.emplace_back(TokenType::Equal, std::string(1, get()));
                    break;
                case ';':
                    tokens.emplace_back(TokenType::Semicolon, std::string(1, get()));
                    break;
                default:
                    tokens.emplace_back(TokenType::Unknown, std::string(1, get()));
                    break;
            }
        }
    }
    tokens.emplace_back(TokenType::EndOfFile, "");
    return tokens;
}
