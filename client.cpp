#include "client.h"

Client::Client() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
    }

    GLFWmonitor*  monitor   =   glfwGetPrimaryMonitor();
    const GLFWvidmode*  mode    =   glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    this->window = glfwCreateWindow(mode->width, mode->height, "Minecraft", monitor, NULL);
    glfwMakeContextCurrent(this->window);

    glewExperimental = true;
    GLenum err = glewInit();

    if (err != GLEW_OK) {
            std::cout << "Failed to initialize GLEW" << std::endl;
    }

    InputHandler::initInput(this->window);
}

void Client::update() {
    glfwSwapBuffers(this->window);
}
