#include "DOM.h"
#include <string>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#include <iostream>
#endif

void dom_print(const std::string &text) {
#ifdef __EMSCRIPTEN__
    EM_ASM_({
        // Assumes there's an element with id "output" in your HTML.
        document.getElementById('output').innerText = UTF8ToString($0);
    }, text.c_str());
#else
    // For native builds, simply print to console.
    std::cout << text << std::endl;
#endif
}
