#ifndef MINECRAFT_ENGINE_H
#define MINECRAFT_ENGINE_H

#include <string>
#include <map>
#include <list>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "engine/objects/block_object.h"
#include "engine/objects/environment_object.h"
#include "engine/objects/gui_object.h"
#include "engine/objects/model_object.h"
#include "engine/input.h"

/* Classes the game may construct */
class Gui {
public:
    Gui(std::string gui_name);
    void render ();
private:
    GuiObject* gui;
};

class Block {
public:
    Block (std::string block_name, float pos_x, float pos_y, float pos_z);
    void render ();
private:
    BlockObject* block;
    glm::mat4 model_matrix;
};

class Object {
public:
    Object (std::string object_name, float pos_x, float pos_y, float pos_z);
    void transform (float pos_x, float pos_y, float pos_z);
    void rotate (float rot_x, float rot_y, float rot_z, float rot_degrees);
    void scale  (float scale_x, float scale_y, float scale_z);
    void render ();
private:
    void calc_model_matrix();
    ModelObject* object;
    glm::vec3 position;
    glm::vec4 rotation;
    glm::vec3 scaling;
    bool update;
    glm::mat4 model_matrix;
};

class Environment {
public:
    Environment(std::string environment_name);
    void render();
private:
    EnvironmentObject* environment;
};

namespace Engine {
    /* Load assets */
    void init_engine(std::string asset_path);

    /* Game can register new objects, pointer returned for the game to modify them */
    void register_gui (std::string name);
    void register_block (std::string name);
    void register_object (std::string name);
    void register_environment (std::string name);

    /* Add objects to the render list, added by the game */
    void add_render_gui (Gui* gui);
    void add_render_block (Block* block);
    void add_render_object (Object* object);
    void add_render_environment (Environment* environment);

    /* Remove objects from the render list, removed by the game */
    void remove_render_gui (Gui* gui);
    void remove_render_block (Block* block);
    void remove_render_object (Object* object);
    void remove_render_environment (Environment* environment);

    void update ();
}

#endif
