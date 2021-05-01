#include "server.h"
#include "client.h"

#include <iostream>

bool run = true;

void check_key_esc(int key, int action) {
    if (key == GLFW_KEY_ESCAPE) {
        run = false;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Client game_client;
    InputHandler::registerListener(check_key_esc);

    while (run) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.5f, 0.7f, 1.0f);

        game_client.update();
        glfwPollEvents();
    }
    return 0;
}
