#include "input.h"

std::list<std::function<void(int key, int action)>> callbacks = {};

void InputHandler::initInput(GLFWwindow* window) {
    glfwSetKeyCallback(window, key_callback);
}

void InputHandler::registerListener(std::function<void(int key, int action)> callback) {
    callbacks.push_back(callback);
}

void InputHandler::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    for (auto i = callbacks.begin(); i != callbacks.end(); i++) {
        (*i)(key, action);
    }
}