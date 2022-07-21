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
    SpriteCmpt();

    SpriteCmpt(const sf::Texture& texture);

    SpriteCmpt(std::string filename);//new v0.5

    void load_texture(std::string filename);//new v0.5

    void Draw(sf::RenderWindow& window, float timeDelta);

    ///Use texture to set our sprite
    void setTexture(const sf::Texture& texture); //note will only have reference to texture!

    ///set position
    void setPosition(sf::Vector2f position);
    
    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    void Update(float timeDelta) {

    }
protected:
    sf::Sprite m_sprite;

    float m_timeDelta;

};

#endif /* spriteCmpt_hpp */
