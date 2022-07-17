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

class inputControllerCmpt : public Component
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
    bool IsKeyPressed(KEY keycode)
    {
        switch (keycode)
        {
        case KEY::KEY_SHIFT:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)))
            {
                std::cout << "shift pressed" << std::endl;
                return true;
            }
            break;
        case KEY::KEY_LEFT:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -40))
            {
                std::cout << "leftkey pressed" << std::endl;
                return true;
            }
            break;

        case KEY::KEY_RIGHT:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 40))
            {
                std::cout << "rightkey pressed" << std::endl;
                return true;
            }
            break;

        case KEY::KEY_UP:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -40))
            {
                return true;
            }
            break;

        case KEY::KEY_DOWN:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 40))
            {
                return true;
            }
            break;

        case KEY::KEY_ATTACK:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
            {
                return true;
            }
            break;

        case KEY::KEY_ESC:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return true;
            }
        }

        return false;
    }
};
#endif /* inputControllerCmpt_hpp */
