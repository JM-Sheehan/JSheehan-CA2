#ifndef COMPONENT_H
#define COMPONENT_H


#include <SFML/Graphics.hpp>

class Component
{

public:
    Component(); //need to define in CPP file.
    /**
    * Create a virtual function so the class is polymorphic.
    */
    virtual void Update(float timeDelta) = 0;
};
#endif
