//
//  GraphicsCmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 03/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef GraphicsCmpt_hpp
#define GraphicsCmpt_hpp

#include <stdio.h>
#include "Component.hpp"
#include <SFML/Graphics.hpp>

class GraphicsCmpt : public Component
{
public:
    GraphicsCmpt() {}
    void Draw(sf::RenderWindow& window, float timeDelta);
private:
    float m_timeDelta;
};
#endif /* GraphicsCmpt_hpp */
