#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <string>
#include <emscripten/emscripten.h>

extern "C" {

    // Expose this function to JavaScript so that we can pass source code from an HTML page.
    EMSCRIPTEN_KEEPALIVE
    int run_program(const char* source) {
        std::string src(source);
        Lexer lexer(src);
        auto tokens = lexer.tokenize();
        Parser parser(tokens);
        auto expr = parser.parseExpression();
        Interpreter interpreter;
        int result = interpreter.evaluate(expr.get());
        return result;
    }
}

#ifdef EMSCRIPTEN
// When compiling for WebAssembly, do not run main() automatically.
#else
int main() {
    std::string source = "3 + 4 - 2";
    std::cout << "Result: " << run_program(source.c_str()) << std::endl;
    return 0;
}
#endif
