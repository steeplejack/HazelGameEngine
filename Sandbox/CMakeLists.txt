add_executable(Sandbox Sandbox.cpp)
target_link_libraries(Sandbox PUBLIC Hazel)
target_include_directories(Sandbox PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Hazel"
        "${PROJECT_SOURCE_DIR}")