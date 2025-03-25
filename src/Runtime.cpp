// In Runtime.cpp
#include "Runtime.h"
#include <emscripten/emscripten.h>

void console_print(const std::string &message) {
    // Call JavaScript's console.log via EM_JS
    EM_ASM_({ console.log(UTF8ToString($0)); }, message.c_str());
}
