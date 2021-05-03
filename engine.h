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
class GuiInstance {
public:
    GuiInstance(std::string gui_name);
    void render ();
private:
    GuiObject* gui;
};

class BlockInstance {
public:
    BlockInstance (std::string block_name, float pos_x, float pos_y, float pos_z);
    void render ();
private:
    BlockObject* block;
    glm::mat4 model_matrix;
};

class ObjectInstance {
public:
    ObjectInstance (std::string object_name, float pos_x, float pos_y, float pos_z);
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

class EnvironmentInstance {
public:
    EnvironmentInstance (std::string environment_name);
    void render ();
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
    void add_render_gui (GuiInstance* gui);
    void add_render_block (BlockInstance* block);
    void add_render_object (ObjectInstance* object);
    void add_render_environment (EnvironmentInstance* environment);

    /* Remove objects from the render list, removed by the game */
    void remove_render_gui (GuiInstance* gui);
    void remove_render_block (BlockInstance* block);
    void remove_render_object (ObjectInstance* object);
    void remove_render_environment (EnvironmentInstance* environment);

    void update ();
}

#endif
