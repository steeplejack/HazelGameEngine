//
// Created by Kevin Gori on 25/09/2020.
//

#include "Application.h"
#include <iostream>

namespace Hazel {

    Application::Application() {}
    Application::~Application() {}

    void Application::Run() {
        std::cout << "Running..." << std::endl;
        while (true);
    }

}