#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "AST.h"
#include <unordered_map>
#include <string>

class Interpreter {
public:
    int evaluate(Expr* expr);
private:
    std::unordered_map<std::string, int> environment;
};

#endif // INTERPRETER_H
