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
    MoveCmpt(int x, int y);
    MoveCmpt(sf::Vector2f pos);

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition();

    void updatePosition();
    void updatePosition(sf::Vector2f speed);
    void Update(float timeDelta) {

    }
private:
    sf::Vector2f m_position;
    //new v0.5
    sf::Vector2f m_speed;
};

#endif /* MoveCmpt_hpp */
