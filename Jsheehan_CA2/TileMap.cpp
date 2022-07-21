

#include "TileMap.hpp"

TileMap::TileMap() {

}

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, sf::Vector2u mapSize)
{
    tiles_list = tiles;

    // load the tileset texture
     // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    m_width = mapSize.x;
    m_height = mapSize.y;
    m_tileSize = tileSize;
    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(m_width * m_height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < m_height; ++i)
        for (unsigned int j = 0; j < m_width; ++j)
        {

            // get the current tile number
            int tileNumber = tiles[j + (i * m_width)];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(j + (i * m_width)) * 4];


            // define its 4 corners
            quad[0].position = sf::Vector2f(j * tileSize.x, i * tileSize.y);    
            quad[1].position = sf::Vector2f((j + 1) * tileSize.x, i * tileSize.y);
            quad[2].position = sf::Vector2f((j + 1) * tileSize.x, (i + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(j * tileSize.x, (i + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);



        }

    return true;
}

void TileMap::changeTile(unsigned int tileNumber, unsigned int newTile) {
    // find tiles position in the tileset texture
    int tu = newTile % (m_tileset.getSize().x / m_tileSize.x);
    int tv = newTile / (m_tileset.getSize().x / m_tileSize.x);

    // get a pointer to the current tile's quad
    sf::Vertex* quad = &m_vertices[tileNumber * 4];

    // define its 4 texture coordinates
    quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
    quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
    quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
    quad[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
}

std::vector<int> TileMap::convertToMap(const int* tiles, sf::Vector2u tileSize, sf::Vector2u mapSize) {
    std::vector<int> map;
    unsigned int width = mapSize.x;
    unsigned int height = mapSize.y;
    for (unsigned int i = 0; i < height; ++i)
    {
        for (unsigned int j = 0; j < width; ++j)
        {
            std::cout << "X Coord:    " << j << "\nY Coord:    " << i << std::endl;

            // get the current tile number
            int tileNumber = tiles[j + (i * width)];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(j + (i * (width))) * 4];

            auto pos = quad[0].texCoords.x;
            int vecInt = 0;
            if (pos != 0) {
                vecInt = pos / tileSize.x;
            }
            map.push_back(vecInt);
        }
    }
    return map;
}

bool TileMap::checkOverlap(sf::Vector2f position, sf::Vector2f size) {
    // populate the vertex array, with one quad per tile
    float x_collider = position.x;
    float y_collider = position.y;
    float x_quad;
    float y_quad;
    float width_collider = size.x;
    float height_collider = size.y;
    float width_quad;
    float height_quad;


    for (unsigned int i = 0; i < m_height; ++i) {
        for (unsigned int j = 0; j < m_width; ++j)
        {

            // get the current tile number
            int tileNumber = tiles_list[j + i * m_width];
            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(j + (i * (m_width))) * 4];

            x_quad = quad[0].position.x;
            y_quad = quad[0].position.y;
            width_quad = quad[2].position.x - x_quad;
            height_quad = quad[2].position.y - y_quad;


            if (!((x_collider > x_quad + width_quad) || (x_collider + width_collider < x_quad) ||
                (y_collider > y_quad + height_quad) || (y_collider + height_collider < y_quad))) {
                if (quad[0].texCoords.x != 0) {
                    return true;
                }
            }
            
        }

    }
    return false;
}
