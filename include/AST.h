#ifndef AST_H
#define AST_H

#include "Token.h"
#include <memory>
#include <string>

struct Expr {
    virtual ~Expr() = default;
};

using ExprPtr = std::unique_ptr<Expr>;

struct NumberExpr : public Expr {
    int value;
    NumberExpr(int value) : value(value) {}
};

struct VariableExpr : public Expr {
    std::string name;
    VariableExpr(const std::string &name) : name(name) {}
};

#endif // AST_H
