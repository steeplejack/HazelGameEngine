//
// Created by Kevin Gori on 03/10/2020.
//

#include "hzpch.h"
#include "Hazel/Layer.h"

namespace Hazel {

    Layer::Layer(const std::string& name)
            : m_DebugName(name) {

    }

    Layer::~Layer() {
        HZ_CORE_WARN("Deleted layer {0}", m_DebugName);
    };

}