//
// Created by Kevin Gori on 11/10/2020.
//

#pragma once

#include "Layer.h"
#include "Vendor/ImGui/imgui.h"

namespace Hazel {

    class HAZEL_API ImGuiLayer : public Layer {

    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;



    private:
        float m_Time = 0.0f;

    };

}
