cmake_minimum_required(VERSION 3.12)
project(Minecraft)

set(CMAKE_CXX_STANDARD 20)

add_executable(Minecraft main.cpp server.cpp server/world.cpp server/player.cpp server/world/entity.cpp server/world/chunk.cpp server/player/inventory.cpp engine.cpp engine.h engine/objects/gui_object.cpp engine/objects/gui_object.h engine/objects/block_object.cpp engine/objects/block_object.h engine/objects/model_object.cpp engine/objects/model_object.h engine/objects/environment_object.cpp engine/objects/environment_object.h engine/render/font.cpp engine/render/font.h engine/render/model.cpp engine/render/model.h engine/render/shader.cpp engine/render/shader.h engine/render/texture.cpp engine/render/texture.h)

# Requires glew32.dll and glfw3.dll in dlls/
add_custom_command(TARGET Minecraft POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/dlls"
        $<TARGET_FILE_DIR:Minecraft>)

# Requires glew32.lib and libglfw3.a in libraries/
target_link_libraries(Minecraft OpenGL32.lib ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glew32.lib ${CMAKE_CURRENT_SOURCE_DIR}/libraries/libglfw3.a)
# Requires includes of GLEW, GLFW, GLM in includes/
target_include_directories(Minecraft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)