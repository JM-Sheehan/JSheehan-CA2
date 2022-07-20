#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Object.hpp"
#include "Component.hpp"
#include "GraphicsCmpt.hpp"
#include "SpriteCmpt.hpp"
#include "AnimatedSpriteCmpt.hpp"
#include "MoveCmpt.hpp"
#include "TextureManager.hpp"
#include "InputControllerCmpt.hpp"
#include "ReadableInfoCMPT.hpp"
#include "Game.hpp"
#include "json.hpp"
#include "TileMap.hpp"

//newly added v0.5
// Animation states.
//enum ANIMATION_STATE {WALK_UP, WALK_DOWN,WALK_RIGHT,WALK_LEFT,IDLE_UP,IDLE_DOWN,IDLE_RIGHT,IDLE_LEFT,COUNT};

namespace converter {
    struct MapForJsonStruct {
        std::vector<int> map;
        //ToDo
        std::vector<int> tileSize, mapSize; //what structure would suit these. Note SFML types wont work here.
        std::string textureForMap;
        const int* get_level()
        {
            //since vector must store data contiguously, the following works for array
            int* a = &map[0];
            return a;
        }
    };

    void to_json(nlohmann::json& j, const MapForJsonStruct& ms) {
        j = nlohmann::json{
            {"map",ms.map},
            {"tilesize",ms.tileSize},
            {"mapsize",ms.mapSize},
            {"maptexture",ms.textureForMap}
        };
    }
    void from_json(const nlohmann::json& j, MapForJsonStruct& ms) {
        j.at("map").get_to(ms.map);
        j.at("tilesize").get_to(ms.tileSize);
        j.at("mapsize").get_to(ms.mapSize);
        j.at("maptexture").get_to(ms.textureForMap);
    }


}


using namespace converter;


sf::Vector2u m_widthAndHeight, m_tileSize;


int CreateMapStructure(std::string fileName);
TileMap DrawMap(MapForJsonStruct ms);
TileMap tile_map;

int CreateMapStructure(std::string fileName)
{
    json j;
    std::ifstream i;
    i.open(fileName);
    i >> j;


    auto p2 = j.get<MapForJsonStruct>();
    m_widthAndHeight.x = p2.mapSize[0];
    m_widthAndHeight.y = p2.mapSize[1];
    m_tileSize.x = p2.tileSize[0];
    m_tileSize.y = p2.tileSize[1];

    for (auto i : p2.map) {
        std::cout << i << ' ';
    }
    std::cout << ", mapsize = [" << p2.mapSize[0] << "," << p2.mapSize[1] << "]" << std::endl;
    if (p2.mapSize[0] > 0 || p2.mapSize[1] > 0 || p2.tileSize[0] > 0 || p2.tileSize[1] > 0 || p2.textureForMap.size() > 0) {
        tile_map = DrawMap(p2);
    }

    return EXIT_SUCCESS;
}

TileMap DrawMap(MapForJsonStruct ms)
{
    auto level = ms.get_level();//I know return type is const int*.

       // create the tilemap from the level definition
    TileMap map;

    try {
        map.load(ms.textureForMap, m_tileSize, level, m_widthAndHeight);
    }
    catch (const std::exception& e) // reference to the base of a polymorphic object
    {
        std::cout << e.what(); // information from length_error printed
    }


    return map;
}


int main(int, char const**)
{
 
    //remember that the objects can be turned into anything we want!
    Object player;
    player.AttachComponent<ReadableInfoCMPT>();
    player.AttachComponent<SpriteCmpt>();
    player.GetComponent<ReadableInfoCMPT>()->addComponentDetails("SpriteCmpt");

    player.GetComponent<SpriteCmpt>()->setPosition(sf::Vector2f(0, 0));
    player.AttachComponent<MoveCmpt>(sf::Vector2f(10, 10));
    player.GetComponent<ReadableInfoCMPT>()->addComponentDetails("MoveCmpt");

    //player.AttachComponent<spriteCmpt>("spr_archer_idle_down.png");
    player.AttachComponent<InputControllerCmpt>();
    player.GetComponent<ReadableInfoCMPT>()->addComponentDetails("InputControllerCmpt");
    auto tempTextureID = TextureManager::AddTexture("archer/spr_archer_idle_down.png");
    if (tempTextureID == -1)
    {
        std::cout << "couldn't add texture to player sprite component\n";
        exit(0);
    }
    auto sprcmpt = player.GetComponent<SpriteCmpt>();
    sprcmpt->setTexture(TextureManager::GetTexture(tempTextureID));
    sprcmpt->setPosition(sf::Vector2f(10, 5));

    Object animatedCharacter;
    animatedCharacter.AttachComponent<ReadableInfoCMPT>();
    animatedCharacter.AttachComponent<AnimatedSpriteCmpt>();
    animatedCharacter.GetComponent<ReadableInfoCMPT>()->addComponentDetails("AnimatedSpriteCmpt");

    animatedCharacter.GetComponent<AnimatedSpriteCmpt>()->setPosition(sf::Vector2f(50, 20));
    animatedCharacter.GetComponent<ReadableInfoCMPT>()->addComponentDetails("MoveCmpt");

    auto aCharTempTexture = TextureManager::AddTexture("enemies/goblin/spr_goblin_walk_down.png");
    if (tempTextureID == -1)
    {
        std::cout << "couldn't add texture to animated character sprite component\n";
        exit(0);
    }
    auto aCharSprCmpt = animatedCharacter.GetComponent<AnimatedSpriteCmpt>();
    aCharSprCmpt->SetSprite(TextureManager::GetTexture(aCharTempTexture), 8, 1);
    aCharSprCmpt->SetAnimated(true);

    Object Enemy;
    //BODY_skeleton.png
    Enemy.AttachComponent<ReadableInfoCMPT>();
    Enemy.AttachComponent<SpriteCmpt>();
    Enemy.GetComponent<ReadableInfoCMPT>()->addComponentDetails("spriteCmpt");

    Enemy.GetComponent<SpriteCmpt>()->setPosition(sf::Vector2f(0, 0));
    Enemy.AttachComponent<MoveCmpt>(sf::Vector2f(30, 10));
    Enemy.GetComponent<ReadableInfoCMPT>()->addComponentDetails("MoveCmpt");
    //Enemy.AttachComponent<inputControllerCmpt>();

    std::string filename("enemies/skeleton/spr_skeleton_idle_down.png");
    tempTextureID = TextureManager::AddTexture(filename);
    if (tempTextureID == -1)
    {
        std::cout << "couldn't add texture to player sprite component\n";
        exit(0);
    }
    auto sprcmpt1 = Enemy.GetComponent<SpriteCmpt>();
    sprcmpt1->setTexture(TextureManager::GetTexture(tempTextureID));
    sprcmpt1->setPosition(sf::Vector2f(40, 20));
    Enemy.GetComponent<MoveCmpt>()->setPosition({ 40,50 });
    Object Block;

    CreateMapStructure("map.json");

    Game game;
    game.setMap(tile_map);
    game.AddObjects(&player);
    game.AddObjects(&Enemy);
    game.AddObjects(&animatedCharacter);

    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }


    return EXIT_SUCCESS;
}
