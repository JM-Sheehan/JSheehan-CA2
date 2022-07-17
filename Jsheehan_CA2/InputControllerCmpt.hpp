//
//  inputControllerCmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef inputControllerCmpt_hpp
#define inputControllerCmpt_hpp

#include <stdio.h>
#include "Component.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class InputControllerCmpt : public Component
{
public:
    //new v0.5
    enum class KEY
    {
        KEY_LEFT,
        KEY_RIGHT,
        KEY_UP,
        KEY_DOWN,
        KEY_ATTACK,
        KEY_ESC,
        KEY_SHIFT
    };
    // Returns true if the given key is pressed.
    bool IsKeyPressed(KEY keycode);
};
#endif /* inputControllerCmpt_hpp */
