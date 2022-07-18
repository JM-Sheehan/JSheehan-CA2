
//  spriteCmpt.cpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#include "SpriteCmpt.hpp"

SpriteCmpt::SpriteCmpt() {
    m_timeDelta = 0;
}

SpriteCmpt::SpriteCmpt(const sf::Texture& texture)//new v0.5
{
    m_timeDelta = 0;
    m_sprite.setTexture(texture);
}

SpriteCmpt::SpriteCmpt(std::string filename)//new v0.5
{
    m_timeDelta = 0;

    auto texture = std::make_unique<sf::Texture>();
    if (!texture->loadFromFile(filename))
    {
        std::cout << "I couldn't load " << filename << std::endl;
        exit(-1);
    }
    m_sprite.setTexture(*texture);
}
void SpriteCmpt::load_texture(std::string filename)//new v0.5
{

    auto texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(filename))
    {
        std::cout << "I couldn't load " << filename << std::endl;
        exit(-1);
    }
    m_sprite.setTexture(*texture);
}


///Use texture to set our sprite
void SpriteCmpt::setTexture(const sf::Texture& texture) //note will only have reference to texture!
{
    m_sprite.setTexture(texture);
}

///set position
void SpriteCmpt::setPosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);

}



void SpriteCmpt::Draw(sf::RenderWindow& window, float timeDelta)
{

    window.draw(m_sprite);
}
