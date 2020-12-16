//
// Created by Kevin Gori on 14/12/2020.
//

#include "hzpch.h"
#include "MacInput.h"
#include "Hazel/Application.h"

# include <GLFW/glfw3.h>

namespace Hazel {

    Input* Input::s_Instance = new MacInput();

    bool MacInput::IsKeyPressedImpl(int keycode) {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacInput::IsMouseButtonPressedImpl(int button) {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> MacInput::GetMousePositionImpl() {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return { (float)xpos, float(ypos) };
    }

    float MacInput::GetMouseXImpl() {
        auto [x, _] = GetMousePositionImpl();
        return x;
    }

    float MacInput::GetMouseYImpl() {
        auto [_, y] = GetMousePositionImpl();
        return y;
    }
}