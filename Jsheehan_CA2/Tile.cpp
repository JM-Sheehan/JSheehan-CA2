#include "Tile.hpp"

Tile::Tile(unsigned int type, sf::Sprite& tile_sprite) {
    m_type = type;
    m_tile_sprite = tile_sprite;
}