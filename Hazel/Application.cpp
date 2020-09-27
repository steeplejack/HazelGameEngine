//
// Created by Kevin Gori on 25/09/2020.
//

#include "Application.h"
#include "Log.h"
#include <iostream>

namespace Hazel {

    Application::Application() {}
    Application::~Application() {}

    void Application::Run() {
        HZ_CORE_TRACE("Running...");
        while (true);
    }

}