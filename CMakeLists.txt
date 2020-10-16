cmake_minimum_required(VERSION 3.16)

project(cherno_game_engine)

find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED) # No glad in Hunter, so using vcpkg

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(Hazel)  # Shared library


add_subdirectory(Sandbox)  # Executable


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DENABLE_DEBUG_MACRO")
