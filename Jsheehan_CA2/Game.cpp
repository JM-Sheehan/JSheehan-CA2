#include "Game.hpp"


Game::Game() : m_window("Tiling", sf::Vector2u(1280, 800))

{
    m_clock.restart();
    unsigned int var = time(nullptr);
    srand(var);
    //mapSprite_ = nullptr;

    m_elapsed = 0.0f;


}

Game::~Game() {}

sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
WindowComponent* Game::GetWindow() { return &m_window; }

void Game::setMap(TileMap tile_map) {
    Game::map = tile_map;
}


void Game::HandleInput() {
    // Input handling.

    for (auto& i : m_gameObjects)
    {
        auto movecmpt = i->GetComponent<MoveCmpt>();

        auto icmpt = i->GetComponent<InputControllerCmpt>();
        if (movecmpt == nullptr || icmpt == nullptr)
            break;
        if (icmpt->IsKeyPressed(InputControllerCmpt::KEY::KEY_LEFT))
            movecmpt->updatePosition({ -1,0 });
        if (icmpt->IsKeyPressed(InputControllerCmpt::KEY::KEY_RIGHT))
            movecmpt->updatePosition({ 1,0 });

        if (icmpt->IsKeyPressed(InputControllerCmpt::KEY::KEY_UP))
            movecmpt->updatePosition({ 0,-1 });

        if (icmpt->IsKeyPressed(InputControllerCmpt::KEY::KEY_DOWN))
            movecmpt->updatePosition({ 0,1 });

        movecmpt->Update(0.01f);
    }


}

void Game::Update() {
    m_window.Update();
}

void Game::Render() {
    m_window.BeginDraw();
    // Render here.
    m_window.Draw(Game::map);
    for (auto& i : m_gameObjects)
    {

        auto sprCmpt = i->GetComponent<SpriteCmpt>();
        auto moveCmpt = i->GetComponent<MoveCmpt>();
        auto animatedSprCmpt = i->GetComponent<AnimatedSpriteCmpt>();
        auto collideCmpt = i->GetComponent<CollideCmpt>();

        if (collideCmpt != nullptr && moveCmpt != nullptr && sprCmpt != nullptr) {
            sf::Vector2f  position = moveCmpt->getPosition();

            bool checkingCollision = map.checkOverlap(position , collideCmpt->getSize());
            if (checkingCollision) {
                std::cout << "Colliding" << std::endl;
                moveCmpt->setPosition(collideCmpt->getPos());
            }
            else {
                std::cout << "Not Colliding" << std::endl;
                collideCmpt->setPos(moveCmpt->getPosition());
                sprCmpt->setPosition(moveCmpt->getPosition());
            }
        }
        else if (sprCmpt != nullptr && moveCmpt != nullptr) {
            sprCmpt->setPosition(moveCmpt->getPosition());
        }  

        if (sprCmpt != nullptr) sprCmpt->Draw(*m_window.GetRenderWindow(), 0.01f);

        if (animatedSprCmpt != nullptr && moveCmpt != nullptr) animatedSprCmpt->setPosition(moveCmpt->getPosition());
        if (animatedSprCmpt != nullptr) animatedSprCmpt->Draw(*m_window.GetRenderWindow(), 0.01f);



    }


    m_window.EndDraw();
}

void Game::AddObjects(Object* obj)
{
    Game::m_gameObjects.push_back(obj);
}