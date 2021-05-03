#include "server.h"
#include "engine.h"

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    while(1) {
        Engine::update();
    }

    return 0;
}
