#pragma once
#include "Component.hpp"

#include "SFML/Graphics.hpp"

using namespace sf;

class CollideCmpt : public Component
{
public:
    //typedef std::shared_ptr<sf::RectangleShape> rectPtr; //ok, I'm tired of writing long statements, so use typedef to create alias - note the irony of me writing this long comment to justify this!!
    //typedef std::shared_ptr<CollideCmpt> colCmptPtr;

    CollideCmpt() {};
    CollideCmpt(sf::RectangleShape body);

    bool checkCollision(CollideCmpt other);

    Vector2f getSize();
    Vector2f getPos();

    void setPos(Vector2f pos);
    void setSize(Vector2f size);

    void Update(float timeDelta) {

    }

private:
    RectangleShape _body;
};

