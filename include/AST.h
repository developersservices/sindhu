#ifndef AST_H
#define AST_H

#include "Token.h"
#include <memory>
#include <string>

// Base class for expressions
struct Expr {
    virtual ~Expr() = default;
};

using ExprPtr = std::unique_ptr<Expr>;

// Numeric literal expression
struct NumberExpr : public Expr {
    int value;
    NumberExpr(int value) : value(value) {}
};

// Variable expression (not used in this simple demo)
struct VariableExpr : public Expr {
    std::string name;
    VariableExpr(const std::string &name) : name(name) {}
};

// Binary expression (e.g., addition or subtraction)
struct BinaryExpr : public Expr {
    ExprPtr left;
    Token op;
    ExprPtr right;

    BinaryExpr(ExprPtr left, Token op, ExprPtr right)
        : left(std::move(left)), op(op), right(std::move(right)) {}
};

#endif // AST_H
