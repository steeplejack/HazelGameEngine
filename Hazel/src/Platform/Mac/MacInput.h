//
// Created by Kevin Gori on 14/12/2020.
//

#pragma once

#include "Hazel/Input.h"

namespace Hazel {

    class MacInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };

}