//
// Created by Kevin Gori on 02/10/2020.
//

#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel {

class GeneralWindow : public Window {
public:
    GeneralWindow(const WindowProps& props);
    virtual ~GeneralWindow();

    void OnUpdate() override;

    inline unsigned int GetWidth() const override { return m_Data.Width; }
    inline unsigned int GetHeight() const override { return m_Data.Height; }

    // Window attributes
    inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
    void SetVSync(bool enabled) override;
    bool IsVSync() const override;

    // Expose the underlying window pointer
    void* GetWindowPointer() override { return static_cast<void*>(m_Window); }

private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();

private:
    GLFWwindow* m_Window;

    struct WindowData {
        std::string Title;
        unsigned int Width, Height;
        bool VSync;

        EventCallbackFn EventCallback;
    };

    WindowData m_Data;
};

}
