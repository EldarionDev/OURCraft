# cmake_minimum_required(VERSION <specify CMake version here>)
project(Minecraft)

set(CMAKE_CXX_STANDARD 20)

add_executable(Minecraft main.cpp server.cpp server/world.cpp server/player.cpp server/world/entity.cpp server/world/chunk.cpp server/player/inventory.cpp client.cpp client/render.cpp client/render/block.cpp client/render/model.cpp client/input.cpp client/render/gui.cpp client/render/gui.h client/render/asset_loaders/texture.cpp client/render/asset_loaders/texture.h client/render/asset_loaders/shader.cpp client/render/asset_loaders/shader.h client/render/font.cpp client/render/font.h client/render/asset_loaders/model.cpp client/render/asset_loaders/model.h client/view/camera.cpp client/view/camera.h client/view/projection.cpp client/view/projection.h)