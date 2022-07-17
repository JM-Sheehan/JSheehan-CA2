//
//  MoveCmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//
//#pragma once
#ifndef MoveCmpt_hpp
#define MoveCmpt_hpp

#include "Component.hpp"

class MoveCmpt : public Component
{

public:
    MoveCmpt();
    MoveCmpt(int, int);
    MoveCmpt(sf::Vector2f );

    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();

    void updatePosition();
    void updatePosition(sf::Vector2f);

private:
    sf::Vector2f m_position;
    //new v0.5
    sf::Vector2f m_speed;
};

#endif /* MoveCmpt_hpp */
