//
//  collideCmpt.hpp
//  SimplisticComponentECS
//
//  Created by Denis Flynn on 17/11/2021.
//  Copyright © 2021 Denis Flynn. All rights reserved.
//

#ifndef collideCmpt_hpp
#define collideCmpt_hpp

#include "Component.hpp"

#include "SFML/Graphics.hpp"
using namespace sf;

class CollideCmpt : public Component
{
public:
    typedef std::shared_ptr<sf::RectangleShape> rectPtr; //ok, I'm tired of writing long statements, so use typedef to create alias - note the irony of me writing this long comment to justify this!!
    typedef std::shared_ptr<CollideCmpt> colCmptPtr;

    CollideCmpt(rectPtr body);

    bool checkCollision(colCmptPtr other);

    Vector2f getSize();
    Vector2f getPos();

private:
    rectPtr _body;
};

#endif /* collideCmpt_hpp */
