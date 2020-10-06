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
#        ../Platform/Windows/WindowsWindow.cpp
#        ../Platform/Windows/WindowsWindow.h
#        ../Platform/Mac/MacWindow.cpp
#        ../Platform/Mac/MacWindow.h
        ../Platform/General/GeneralWindow.cpp
        ../Platform/General/GeneralWindow.h
        LayerStack.cpp LayerStack.h Layer.cpp Layer.h)
target_compile_definitions(Hazel PUBLIC SPDLOG_FMT_EXTERNAL)
target_compile_definitions(Hazel PUBLIC HZ_PLATFORM_MAC)
target_compile_definitions(Hazel PUBLIC GLFW_INCLUDE_NONE)
target_precompile_headers(Hazel PUBLIC ../hzpch.h)
target_include_directories(Hazel PUBLIC
        "${SPDLOG_ROOT}/include"
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Hazel"
        "${PROJECT_SOURCE_DIR}")
target_link_libraries(Hazel PRIVATE glm)
target_link_libraries(Hazel PRIVATE glfw)
target_link_libraries(Hazel PRIVATE imgui::imgui)
target_link_libraries(Hazel PRIVATE spdlog::spdlog)
target_link_libraries(Hazel PRIVATE glad::glad)