#include "Interpreter.h"
#include "AST.h"
#include "DOM.h"
#include <iostream>
#include <stdexcept>
#include <string>

int Interpreter::evaluate(Expr* expr) {
    if (auto num = dynamic_cast<NumberExpr*>(expr)) {
        return num->value;
    } else if (auto var = dynamic_cast<VariableExpr*>(expr)) {
        // For demonstration, return 0 for variables.
        return 0;
    }
    throw std::runtime_error("Unknown expression type");
}

std::string Interpreter::evaluateAsString(Expr* expr) {
    if (auto num = dynamic_cast<NumberExpr*>(expr)) {
        return std::to_string(num->value);
    } else if (auto var = dynamic_cast<VariableExpr*>(expr)) {
        return var->name;
    }
    return "";
}
