#include "MoveCmpt.hpp"
MoveCmpt:: MoveCmpt()
{
    //"safe" defaults
    m_position.x = 0;
    m_position.y = 0;
    //new v0.5
    m_speed = { 0,0 };
}

MoveCmpt::MoveCmpt(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
    //new v0.5
    m_speed = { 0,0 };
}
MoveCmpt::MoveCmpt(sf::Vector2f pos)
{
    m_position = pos;
    //new v0.5
    m_speed = { 0,0 };
}
void MoveCmpt::setPosition(sf::Vector2f pos)
{
    m_position = pos;
}

sf::Vector2f MoveCmpt::getPosition()
{
    return m_position;
}

void MoveCmpt::updatePosition()
{
    m_position += m_speed;
}


void MoveCmpt::updatePosition(sf::Vector2f speed)
{
    m_speed = speed;
    m_position += m_speed;
}