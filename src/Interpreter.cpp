#include "Interpreter.h"
#include "AST.h"
#include <stdexcept>

int Interpreter::evaluate(Expr* expr) {
    if (auto num = dynamic_cast<NumberExpr*>(expr)) {
        return num->value;
    } else if (auto binary = dynamic_cast<BinaryExpr*>(expr)) {
        int left = evaluate(binary->left.get());
        int right = evaluate(binary->right.get());
        if (binary->op.type == TokenType::Plus) {
            return left + right;
        } else if (binary->op.type == TokenType::Minus) {
            return left - right;
        } else {
            throw std::runtime_error("Unsupported binary operator");
        }
    }
    throw std::runtime_error("Unknown expression type");
}
