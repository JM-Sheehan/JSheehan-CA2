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
    MoveCmpt()
    {
        //"safe" defaults
        m_position.x = 0;
        m_position.y = 0;
        //new v0.5
        m_speed = { 0,0 };
    }

    MoveCmpt(int x, int y)
    {
        m_position.x = x;
        m_position.y = y;
        //new v0.5
        m_speed = { 0,0 };
    }
    MoveCmpt(sf::Vector2f pos)
    {
        m_position = pos;
        //new v0.5
        m_speed = { 0,0 };
    }
    void setPosition(sf::Vector2f pos)
    {
        m_position = pos;
    }

    sf::Vector2f getPosition()
    {
        return m_position;
    }

    void updatePosition()
    {
        m_position += m_speed;
    }


    void updatePosition(sf::Vector2f speed)
    {
        m_speed = speed;
        m_position += m_speed;
    }
private:
    sf::Vector2f m_position;
    //new v0.5
    sf::Vector2f m_speed;
};

#endif /* MoveCmpt_hpp */
