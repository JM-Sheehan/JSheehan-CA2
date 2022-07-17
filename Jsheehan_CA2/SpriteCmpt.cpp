
//  spriteCmpt.cpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#include "SpriteCmpt.hpp"
void SpriteCmpt::Draw(sf::RenderWindow& window, float timeDelta)
{
    //m_timeDelta += timeDelta;//really only needed for animation


    window.draw(m_sprite);
}
