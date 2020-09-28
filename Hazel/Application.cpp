//
// Created by Kevin Gori on 25/09/2020.
//

#include "hzpch.h"
#include "Hazel/Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel {

    Application::Application() {}
    Application::~Application() {}

    void Application::Run() {
        HZ_CORE_TRACE("Running...");
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication)) {
            HZ_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput)) {
            HZ_TRACE(e);
        }
        while (true);
    }

}