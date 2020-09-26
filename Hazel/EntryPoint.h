//
// Created by Kevin Gori on 25/09/2020.
//

#pragma once

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}


