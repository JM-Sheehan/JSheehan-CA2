#include "CollideCmpt.hpp"
CollideCmpt::CollideCmpt(rectPtr body) :_body(body)
{
}

bool CollideCmpt::checkCollision(colCmptPtr other) {
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

Vector2f CollideCmpt::getSize()
{
    return _body->getSize();
}

Vector2f CollideCmpt::getPos()
{
    return _body->getPosition();
}