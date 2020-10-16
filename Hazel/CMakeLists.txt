add_library(Hazel SHARED Core.h
        Application.cpp Application.h
        ../Hazel.h
        EntryPoint.h
        Log.cpp Log.h
        Events/Event.h
        Events/ApplicationEvent.h
        Events/MouseEvent.h
        Events/KeyEvent.h
        ../hzpch.h
        ../hzpch.cpp
        Window.h
        ../Platform/General/GeneralWindow.cpp
        ../Platform/General/GeneralWindow.h
        LayerStack.cpp
        LayerStack.h
        Layer.cpp
        Layer.h
        ImGui/ImGuiLayer.h
        ImGui/ImGuiLayer.cpp
        ../Vendor/ImGui/imgui.cpp
        ../Vendor/ImGui/backends/imgui_impl_opengl3.cpp
        ../Vendor/ImGui/imgui_demo.cpp
        ../Vendor/ImGui/imgui_draw.cpp
        ../Vendor/ImGui/imgui_widgets.cpp)

target_compile_definitions(Hazel PUBLIC SPDLOG_FMT_EXTERNAL)
target_compile_definitions(Hazel PUBLIC HZ_PLATFORM_MAC)
target_compile_definitions(Hazel PUBLIC GLFW_INCLUDE_NONE)
target_precompile_headers(Hazel PUBLIC ../hzpch.h)
target_include_directories(Hazel PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Hazel"
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/Vendor/ImGui")

target_link_libraries(Hazel PRIVATE glm)
target_link_libraries(Hazel PRIVATE glfw)
target_link_libraries(Hazel PRIVATE spdlog::spdlog)
target_link_libraries(Hazel PRIVATE glad::glad)