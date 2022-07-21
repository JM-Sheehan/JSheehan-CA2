#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    sf::VertexArray m_vertices;
    TileMap();
    sf::Vector2u m_tileSize;
    bool load(
        const std::string& tileset,
        sf::Vector2u tileSize,
        const int* tiles,
        sf::Vector2u mapSize);


    void changeTile(
        unsigned int tileNumber, 
        unsigned int newTile);

    // Method to convert tileMap to JSON format for saving.
    std::vector<int> convertToMap(
        const int* tiles,
        sf::Vector2u tileSize,
        sf::Vector2u mapSize);

    bool checkOverlap(sf::Vector2f position, sf::Vector2f size);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        sf::Transform transform = getTransform();
        states.transform = transform;

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);

    }

    unsigned int m_width;
    unsigned int m_height;
    sf::Texture m_tileset;
    const int* tiles_list;

};