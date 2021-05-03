#include "server.h"
#include "engine.h"

#include <iostream>

bool run = true;

void check_key_esc(int key, int action) {
    if (key == GLFW_KEY_ESCAPE) {
        run = false;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Engine::init_engine("");
    InputHandler::registerListener(check_key_esc);

    while(run) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.5f, 0.7, 1.0f);
        Engine::update();
    }

    return 0;
}
