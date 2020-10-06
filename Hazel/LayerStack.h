//
// Created by Kevin Gori on 03/10/2020.
//

#pragma once

#include "Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel {

    class HAZEL_API LayerStack {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(std::unique_ptr<Layer> layer);
        void PushOverlay(std::unique_ptr<Layer> overlay);
        void PopLayer(std::unique_ptr<Layer> layer);
        void PopOverlay(std::unique_ptr<Layer> overlay);

        std::vector<std::unique_ptr<Layer>>::iterator begin() { return m_Layers.begin(); }
        std::vector<std::unique_ptr<Layer>>::iterator end() { return m_Layers.end(); }
    private:
        std::vector<std::unique_ptr<Layer>> m_Layers;
        std::vector<std::unique_ptr<Layer>>::iterator m_LayerInsert;
    };

}




