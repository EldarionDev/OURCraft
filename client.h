#ifndef MINECRAFT_CLIENT_H
#define MINECRAFT_CLIENT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "client/view.h"
#include "client/render.h"
#include "client/input.h"

class Client {
public:
    Client();
    void update();
private:
    GLFWwindow *window;
};

#endif
