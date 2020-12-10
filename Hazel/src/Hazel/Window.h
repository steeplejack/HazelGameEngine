//
// Created by Kevin Gori on 30/09/2020.
//

#pragma once

#include <GLFW/glfw3.h>
#include "hzpch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Hazel {

    struct WindowProps {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string& title = "Hazel Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
                : Title(title), Width(width), Height(height)
                {}
    };

    // Interface representing a desktop window
    class HAZEL_API Window {
        friend class ImGuiLayer;
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());

    private:
        virtual void* GetWindowPointer() = 0;
    };
}




