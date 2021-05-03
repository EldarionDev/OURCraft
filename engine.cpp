#include "engine.h"

std::map<std::string, BlockObject> registered_blocks;
std::map<std::string, EnvironmentObject> registered_environments;
std::map<std::string, GuiObject> registered_guis;
std::map<std::string, ModelObject> registered_objects;

std::list<GuiInstance*> gui_render_list;
std::list<BlockInstance*> block_render_list;
std::list<ObjectInstance*> object_render_list;
std::list<EnvironmentInstance*> environment_render_list;

GLFWwindow* game_window;

/*Later load all the assets */
void Engine::init_engine(std::string asset_path) {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
    }

    GLFWmonitor*  monitor   =   glfwGetPrimaryMonitor();
    const GLFWvidmode*  mode    =   glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    game_window = glfwCreateWindow(mode->width, mode->height, "Minecraft", monitor, NULL);
    glfwMakeContextCurrent(game_window);

    glewExperimental = true;
    GLenum err = glewInit();

    if (err != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
    }

    InputHandler::initInput(game_window);
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

void Engine::add_render_gui (GuiInstance *GuiInstance) {
    GuiInstance_render_list.push_back(GuiInstance);
}

void Engine::add_render_block (BlockInstance *BlockInstance) {
    block_render_list.push_back(BlockInstance);
}

void Engine::add_render_object (ObjectInstance *ObjectInstance) {
    object_render_list.push_back(ObjectInstance);
}

void Engine::add_render_environment (EnvironmentInstance *EnvironmentInstance) {
    environment_render_list.push_back(EnvironmentInstance);
}

void Engine::remove_render_gui (GuiInstance *GuiInstance) {
    gui_render_list.remove(GuiInstance);
}

void Engine::remove_render_block (BlockInstance *BlockInstance) {
    block_render_list.remove(BlockInstance);
}

void Engine::remove_render_object (ObjectInstance *ObjectInstance) {
    object_render_list.remove(ObjectInstance);
}

void Engine::remove_render_environment (EnvironmentInstance *EnvironmentInstance) {
    environment_render_list.remove(EnvironmentInstance);
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


    glfwSwapBuffers(game_window);
    glfwPollEvents();
}

GuiInstance::GuiInstance(std::string GuiInstance_name) {
    this->gui = &registered_guis.find(GuiInstance_name)->second;
}

void GuiInstance::render() {

}

ObjectInstance::ObjectInstance(std::string ObjectInstance_name, float pos_x, float pos_y, float pos_z) {
    this->transform(pos_x, pos_y, pos_z);
    this->calc_model_matrix();
    this->object = &registered_objects.find(ObjectInstance_name)->second;
    this->update = false;
    this->scaling = glm::vec3(1.0f);
    this->rotation = glm::vec4(1.0f, 1.0f, 1.0f, 360.0f);
}

void ObjectInstance::transform(float pos_x, float pos_y, float pos_z) {
    this->position = glm::vec3(pos_x, pos_y, pos_z);
    this->update = true;
}

void ObjectInstance::scale(float scale_x, float scale_y, float scale_z) {
    this->position = glm::vec3(scale_x, scale_y, scale_z);
    this->update = true;
}

void ObjectInstance::rotate(float rot_x, float rot_y, float rot_z, float rot_degrees) {
    this->rotation = glm::vec4(rot_x, rot_y, rot_z, rot_degrees);
    this->update = true;
}

void ObjectInstance::calc_model_matrix() {
    this->model_matrix = glm::mat4(1.0f);
    this->model_matrix = glm::translate(this->model_matrix, this->position);
    this->model_matrix = glm::rotate(this->model_matrix, this->rotation.w, glm::vec3(this->rotation.x, this->rotation.y, this->rotation.z));
    this->model_matrix = glm::scale(this->model_matrix, this->scaling);
}

void ObjectInstance::render() {
    if (this->update) {
        this->calc_model_matrix();
        this->update = false;
    }
}

BlockInstance::BlockInstance(std::string BlockInstance_name, float pos_x, float pos_y, float pos_z) {
    this->block = &registered_blocks.find(BlockInstance_name)->second;
    this->model_matrix = glm::mat4(1.0f);
    this->model_matrix = glm::translate(this->model_matrix, glm::vec3(pos_x, pos_y, pos_z));
}

void BlockInstance::render() {

}

EnvironmentInstance::EnvironmentInstance(std::string EnvironmentInstance_name) {
    this->environment = &registered_environments.find(EnvironmentInstance_name)->second;
}

void EnvironmentInstance::render() {

}