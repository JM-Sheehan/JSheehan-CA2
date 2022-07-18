//
//  TileMap.hpp
//  AssetManagerv1
//
//  Created by Denis Flynn on 19/09/2018.
//  Copyright © 2018 Denis Flynn. All rights reserved.
//

#ifndef TileMap_hpp
#define TileMap_hpp
#include <string>
#include "Window.hpp"
#include "json.hpp"


// Tiles.
enum  TILE {
    GRASS,  //- passible
    WATER,  //- impassible or slow
    STONE,  //- impassible
    TREE,   //maybe change this tile - impassible
    INVALID  //Invalid tile
};

// map TILE values to JSON as strings
NLOHMANN_JSON_SERIALIZE_ENUM(TILE, {
    {INVALID, nullptr},
    {WATER, "WATER"},
    {STONE, "STONE"},
    {TREE, "TREE"},
    })

    struct Tile {
    TILE type;                          // The type of tile this is.
    int columnIndex;                    // The column index of the tile.
    int rowIndex;                       // The row index of the tile.
    sf::Sprite sprite;                  // The tile sprite.
    int H;                              // Heuristic / movement cost to goal.
    int G;                              // Movement cost. (Total of entire path)
    int F;                              // Estimated cost for full path. (G + H)
    Tile* parentNode;                   // Node to reach this node.
};


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap();
    bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
    void ResetNotes();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif /* TileMap_hpp */