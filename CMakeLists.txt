cmake_minimum_required(VERSION 3.12)
project(Minecraft)

set(CMAKE_CXX_STANDARD 20)

add_executable(Minecraft main.cpp server.cpp server/world.cpp server/player.cpp server/world/entity.cpp server/world/chunk.cpp server/player/inventory.cpp client.cpp client/render.cpp client/render/block.cpp client/render/model.cpp client/input.cpp client/render/gui.cpp client/render/asset_loaders/texture.cpp client/render/asset_loaders/shader.cpp client/render/font.cpp client/render/asset_loaders/model.cpp client/view/camera.cpp client/view/projection.cpp client/render/asset_loaders.cpp client/view.cpp)

add_custom_command(TARGET Minecraft POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/dlls"
        $<TARGET_FILE_DIR:Minecraft>)

target_link_libraries(Minecraft OpenGL32.lib ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glew32.lib ${CMAKE_CURRENT_SOURCE_DIR}/libraries/libglfw3.a)
target_include_directories(Minecraft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)