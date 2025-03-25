#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "Runtime.h"
#include "DOM.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

int main(int argc, char* argv[]) {
    std::string source;
    if (argc > 1) {
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "Error: Could not open file " << argv[1] << "\n";
            return 1;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        source = buffer.str();
    } else {
        // Default source code if no file is provided.
        source = "42"; // This simply prints the number 42.
    }

    runtime_init();

    Lexer lexer(source);
    auto tokens = lexer.tokenize();
    Parser parser(tokens);
    auto expr = parser.parseExpression();
    Interpreter interpreter;
    int result = interpreter.evaluate(expr.get());
    
#ifdef __EMSCRIPTEN__
    // For WebAssembly builds, output via dom_print.
    dom_print("Result: " + std::to_string(result));
#else
    // For native builds, output to console.
    std::cout << "Result: " << result << std::endl;
#endif

    return 0;
}
