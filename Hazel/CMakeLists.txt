add_library(Hazel SHARED
        src/Hazel/Core.h
        src/Hazel/Application.cpp
        src/Hazel/Application.h
        src/Hazel.h
        src/Hazel/EntryPoint.h
        src/Hazel/Log.cpp
        src/Hazel/Log.h
        src/Hazel/Events/Event.h
        src/Hazel/Events/ApplicationEvent.h
        src/Hazel/Events/MouseEvent.h
        src/Hazel/Events/KeyEvent.h
        src/hzpch.h
        src/hzpch.cpp
        src/Hazel/Window.h
        src/Platform/Mac/MacWindow.cpp
        src/Platform/Mac/MacWindow.h
        src/Hazel/LayerStack.cpp
        src/Hazel/LayerStack.h
        src/Hazel/Layer.cpp
        src/Hazel/Layer.h
        src/Hazel/ImGui/ImGuiLayer.h
        src/Hazel/ImGui/ImGuiLayer.cpp
        Vendor/ImGui/imgui.cpp
        Vendor/ImGui/backends/imgui_impl_opengl3.cpp
        Vendor/ImGui/backends/imgui_impl_glfw.cpp
        Vendor/ImGui/imgui_demo.cpp
        Vendor/ImGui/imgui_draw.cpp
        Vendor/ImGui/imgui_widgets.cpp
        src/Hazel/Input.h
        src/Platform/Mac/MacInput.h
        src/Platform/Mac/MacInput.cpp src/Hazel/KeyCodes.h src/Hazel/MouseButtonCodes.h)

target_compile_definitions(Hazel PUBLIC SPDLOG_FMT_EXTERNAL)
target_compile_definitions(Hazel PUBLIC HZ_PLATFORM_MAC)
target_compile_definitions(Hazel PUBLIC GLFW_INCLUDE_NONE)
target_precompile_headers(Hazel PUBLIC src/hzpch.h)
target_include_directories(Hazel PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/Hazel"
        "${PROJECT_SOURCE_DIR}/Hazel/src"
        "${PROJECT_SOURCE_DIR}/Hazel/Vendor/ImGui")

target_link_libraries(Hazel PRIVATE glm)
target_link_libraries(Hazel PRIVATE glfw)
target_link_libraries(Hazel PRIVATE spdlog::spdlog)
target_link_libraries(Hazel PRIVATE glad::glad)