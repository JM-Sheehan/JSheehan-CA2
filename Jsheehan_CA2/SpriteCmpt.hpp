//
//  spriteCmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef spriteCmpt_hpp
#define spriteCmpt_hpp

#include "GraphicsCmpt.hpp"
#include "Component.hpp"
#include <iostream>
#include <memory>

class SpriteCmpt : public Component
{
public:
    ///this will be a non animated sprite, ala simple roguelikes
    SpriteCmpt()
    {}

    SpriteCmpt(const sf::Texture& texture)//new v0.5
    {
        m_sprite.setTexture(texture);
    }

    SpriteCmpt(std::string filename)//new v0.5
    {

        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(filename))
        {
            std::cout << "I couldn't load " << filename << std::endl;
            exit(-1);
        }
        m_sprite.setTexture(*texture);
    }
    void load_texture(std::string filename)//new v0.5
    {

        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(filename))
        {
            std::cout << "I couldn't load " << filename << std::endl;
            exit(-1);
        }
        m_sprite.setTexture(*texture);
    }

    void Draw(sf::RenderWindow& window, float timeDelta);

    ///Use texture to set our sprite
    void setTexture(const sf::Texture& texture) //note will only have reference to texture!
    {
        m_sprite.setTexture(texture);
    }

    ///set position
    void setPosition(sf::Vector2f position)
    {
        m_sprite.setPosition(position);

    }


protected:
    sf::Sprite m_sprite;


    float m_timeDelta;

};

#endif /* spriteCmpt_hpp */
