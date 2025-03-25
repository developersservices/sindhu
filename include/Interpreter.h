#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "AST.h"
#include <string>

class Interpreter {
public:
    int evaluate(Expr* expr);
    std::string evaluateAsString(Expr* expr); // Helper function
};

#endif // INTERPRETER_H
