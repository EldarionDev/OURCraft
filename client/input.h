#ifndef MINECRAFT_INPUT_H
#define MINECRAFT_INPUT_H

#include <GLFW/glfw3.h>
#include <list>
#include <functional>

namespace InputHandler {
    void initInput(GLFWwindow* window);
    void registerListener(std::function<void(int key, int action)>);

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
}

#endif
