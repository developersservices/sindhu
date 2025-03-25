#include "Runtime.h"
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

void runtime_init() {
    // Perform any runtime initialization here.
#ifdef __EMSCRIPTEN__
    // Emscripten-specific initialization if needed.
#endif
}
