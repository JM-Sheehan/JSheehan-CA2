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
class collideCmpt;

typedef std::shared_ptr<sf::RectangleShape> rectPtr; //ok, I'm tired of writing long statements, so use typedef to create alias - note the irony of me writing this long comment to justify this!!
typedef std::shared_ptr<collideCmpt> colCmptPtr;

class collideCmpt : public Component
{
public:
    collideCmpt(rectPtr body) :_body(body)
    {
    }

    bool checkCollision(colCmptPtr other)
    {
        float x2 = other->getPos().x;
        float y2 = other->getPos().y;
        float x1 = getPos().x;
        float y1 = getPos().y;
        float w = getSize().x;
        float h = getSize().y; //for now assume both are same size - usually ok if standard sprites!

        if ((x1 < x1 + w) && (x1 + w > x2) && (y1 < y2 + h) && (y1 + h > y2))
            return true;
        else
            return false;

    }
    Vector2f getSize()
    {
        return _body->getSize();
    }
    Vector2f getPos()
    {
        return _body->getPosition();
    }
private:
    rectPtr _body;
};

#endif /* collideCmpt_hpp */
