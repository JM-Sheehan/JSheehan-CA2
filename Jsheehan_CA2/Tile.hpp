#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>


/*
Constructor Class for Tiles, Used in Sidebar.
*/
class Tile
{
public:
    Tile(unsigned int type, sf::Sprite& tile_sprite);
    unsigned int m_type;
    sf::Sprite m_tile_sprite;
};