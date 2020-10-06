//
// Created by Kevin Gori on 25/09/2020.
//

#include "hzpch.h"
#include "Hazel/Application.h"

#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    Application::~Application() {}

    void Application::PushLayer(std::unique_ptr<Layer> layer) {
        m_Layerstack.PushLayer(std::move(layer));
    }

    void Application::PushOverlay(std::unique_ptr<Layer> overlay) {
        m_Layerstack.PushOverlay(std::move(overlay));
    }

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        for (auto it = m_Layerstack.end(); it != m_Layerstack.begin(); ) {
            (*--it)->OnEvent(e);
            if (e.Handled) {
                break;
            }
        }
    }

    void Application::Run() {
        HZ_CORE_TRACE("Running...");

        while (m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (std::unique_ptr<Layer>& layer : m_Layerstack) {
                layer->OnUpdate();
            }
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e) {
        m_Running = false;
        return true;
    }

}