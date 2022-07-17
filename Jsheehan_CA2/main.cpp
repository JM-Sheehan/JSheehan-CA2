
//
// Disclaimer:
// ----------
//
// This code will work o  nly if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Object.hpp"
#include "Component.hpp"
#include "GraphicsCmpt.hpp"
#include "SpriteCmpt.hpp"
#include "AnimatedSpriteCmpt.hpp"
#include "MoveCmpt.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "InputControllerCmpt.hpp"
#include "ReadableInfoCMPT.hpp"

//newly added v0.5
// Animation states.
//enum ANIMATION_STATE {WALK_UP, WALK_DOWN,WALK_RIGHT,WALK_LEFT,IDLE_UP,IDLE_DOWN,IDLE_RIGHT,IDLE_LEFT,COUNT};



int main(int, char const**)
{

    //remember that the objects can be turned into anything we want!
    Object player;
    player.AttachComponent<ReadableInfoCMPT>();
    player.AttachComponent<SpriteCmpt>();
    player.GetComponent<ReadableInfoCMPT>()->addComponentDetails("spriteCmpt");

    player.GetComponent<SpriteCmpt>()->setPosition(sf::Vector2f(0, 0));
    player.AttachComponent<MoveCmpt>(sf::Vector2f(10, 10));
    player.GetComponent<ReadableInfoCMPT>()->addComponentDetails("MoveCmpt");

    //player.AttachComponent<spriteCmpt>("spr_archer_idle_down.png");
    player.AttachComponent<inputControllerCmpt>();
    player.GetComponent<ReadableInfoCMPT>()->addComponentDetails("inputControllerCmpt");
    auto tempTextureID = TextureManager::AddTexture("archer/spr_archer_idle_down.png");
    if (tempTextureID == -1)
    {
        std::cout << "couldn't add texture to player sprite component\n";
        exit(0);
    }
    auto sprcmpt = player.GetComponent<SpriteCmpt>();
    sprcmpt->setTexture(TextureManager::GetTexture(tempTextureID));
    sprcmpt->setPosition(sf::Vector2f(10, 5));



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


    Game game;
    game.AddObjects(&player);
    game.AddObjects(&Enemy);

    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }


    return EXIT_SUCCESS;
}
