cmake_minimum_required(VERSION 3.15)

include("hunter/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.270.tar.gz"
        SHA1 "41a60fd1f73d9e4d1af7db812bcdeef7ad486d48"
)

project(cherno_game_engine)
hunter_add_package(glm)
hunter_add_package(imgui)
hunter_add_package(glfw)
hunter_add_package(spdlog)

find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(Hazel)  # Shared library


add_subdirectory(Sandbox)  # Executable
