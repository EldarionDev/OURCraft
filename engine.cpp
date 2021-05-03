#include "engine.h"

std::map<std::string, BlockObject> registered_blocks;
std::map<std::string, EnvironmentObject> registered_environments;
std::map<std::string, GuiObject> registered_guis;
std::map<std::string, ModelObject> registered_objects;

std::list<Gui*> gui_render_list;
std::list<Block*> block_render_list;
std::list<Object*> object_render_list;
std::list<Environment*> environment_render_list;

void Engine::init_engine(std::string asset_path) {

}

/* Later pass shaders, textures, ... */
void Engine::register_gui(std::string name) {
    registered_guis.insert(std::make_pair(name, GuiObject()));
}

void Engine::register_block(std::string name) {
    registered_blocks.insert(std::make_pair(name, BlockObject()));
}

void Engine::register_object(std::string name) {
    registered_objects.insert(std::make_pair(name, ModelObject()));
}

void Engine::register_environment(std::string name) {
    registered_environments.insert(std::make_pair(name, EnvironmentObject()));
}

void Engine::add_render_gui (Gui *gui) {
    gui_render_list.push_back(gui);
}

void Engine::add_render_block (Block *block) {
    block_render_list.push_back(block);
}

void Engine::add_render_object (Object *object) {
    object_render_list.push_back(object);
}

void Engine::add_render_environment (Environment *environment) {
    environment_render_list.push_back(environment);
}

void Engine::remove_render_gui (Gui *gui) {
    gui_render_list.remove(gui);
}

void Engine::remove_render_block (Block *block) {
    block_render_list.remove(block);
}

void Engine::remove_render_object (Object *object) {
    object_render_list.remove(object);
}

void Engine::remove_render_environment (Environment *environment) {
    environment_render_list.remove(environment);
}

void Engine::update() {
    for (auto e = environment_render_list.begin(); e != environment_render_list.end(); e++) {
        (*e)->render();
    }
    for (auto e = block_render_list.begin(); e != block_render_list.end(); e++) {
        (*e)->render();
    }
    for (auto e = object_render_list.begin(); e != object_render_list.end(); e++) {
        (*e)->render();
    }
    for (auto e = gui_render_list.begin(); e != gui_render_list.end(); e++) {
        (*e)->render();
    }
}

Gui::Gui(std::string gui_name) {
    this->gui = &registered_guis.find(gui_name)->second;
}

void Gui::render() {

}

Object::Object(std::string object_name, float pos_x, float pos_y, float pos_z) {
    this->transform(pos_x, pos_y, pos_z);
    this->calc_model_matrix();
    this->object = &registered_objects.find(object_name)->second;
    this->update = false;
    this->scaling = glm::vec3(1.0f);
    this->rotation = glm::vec4(1.0f, 1.0f, 1.0f, 360.0f);
}

void Object::transform(float pos_x, float pos_y, float pos_z) {
    this->position = glm::vec3(pos_x, pos_y, pos_z);
    this->update = true;
}

void Object::scale(float scale_x, float scale_y, float scale_z) {
    this->position = glm::vec3(scale_x, scale_y, scale_z);
    this->update = true;
}

void Object::rotate(float rot_x, float rot_y, float rot_z, float rot_degrees) {
    this->rotation = glm::vec4(rot_x, rot_y, rot_z, rot_degrees);
    this->update = true;
}

void Object::calc_model_matrix() {
    this->model_matrix = glm::mat4(1.0f);
    this->model_matrix = glm::translate(this->model_matrix, this->position);
    this->model_matrix = glm::rotate(this->model_matrix, this->rotation.w, glm::vec3(this->rotation.x, this->rotation.y, this->rotation.z));
    this->model_matrix = glm::scale(this->model_matrix, this->scaling);
}

void Object::render() {
    if (this->update) {
        this->calc_model_matrix();
        this->update = false;
    }
}

Block::Block(std::string block_name, float pos_x, float pos_y, float pos_z) {
    this->block = &registered_blocks.find(block_name)->second;
    this->model_matrix = glm::mat4(1.0f);
    this->model_matrix = glm::translate(this->model_matrix, glm::vec3(pos_x, pos_y, pos_z));
}

void Block::render() {

}

Environment::Environment(std::string environment_name) {
    this->environment = &registered_environments.find(environment_name)->second;
}

void Environment::render() {

}