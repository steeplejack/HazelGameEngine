//
// Created by Kevin Gori on 30/09/2020.
//

#include "hzpch.h"
#include "MacWindow.h"

namespace Hazel {

    static bool s_GLFWInitialized = false;

#ifdef HZ_PLATFORM_MAC
    Window* Window::Create(const WindowProps& props) {
        return new MacWindow(props);
    }
#endif

    MacWindow::MacWindow(const WindowProps& props) {
        Init(props);
    }

    MacWindow::~MacWindow() {
        Shutdown();
    };

    void MacWindow::Init(const WindowProps& props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        HZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            int success = glfwInit();
            HZ_CORE_ASSERT(success, "Could not initialize GLFW!");

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void MacWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }

    void MacWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void MacWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        }
        else {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }

    bool MacWindow::IsVSync() const {
        return m_Data.VSync;
    }

}