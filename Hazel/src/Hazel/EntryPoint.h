//
// Created by Kevin Gori on 25/09/2020.
//

#pragma once


extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
    Hazel::Log::Init();
    HZ_CORE_WARN("Hazel logging initialised!");
    HZ_INFO("Client logging initialised! Var={0}", 1);
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}


