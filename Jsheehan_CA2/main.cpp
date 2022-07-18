#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
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

    

    Game game;
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
