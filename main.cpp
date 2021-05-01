#include "server.h"
#include "client.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (!glfwInit()) {
        std::cout << "GLFW initialization failed." << std::endl;
    }

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Minecraft", NULL, NULL);
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    GLenum err = glewInit();

    if (err != GLEW_OK) {
        std::cout << "Glew initialization failed miserably" << std::endl;
        std::cout << glewGetErrorString(err) << std::endl;
    }

    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.5f, 0.7f, 1.0f);
        glfwSwapBuffers(window);
    }

    return 0;
}
