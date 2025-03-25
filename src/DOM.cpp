#include "DOM.h"
#include <emscripten/emscripten.h>

void dom_print(const std::string &text) {
    // This uses Emscripten to run JavaScript in the browser context.
    EM_ASM_({
        // Replace 'output' with the ID of the element you want to update.
        document.getElementById('output').innerText = UTF8ToString($0);
    }, text.c_str());
}
