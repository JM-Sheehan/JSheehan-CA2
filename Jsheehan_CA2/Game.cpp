#include "Game.hpp"
#include <fstream>

Game::Game() : m_window("Tiling", sf::Vector2u(1280, 800))

{
    m_clock.restart();
    srand(time(nullptr));
    //mapSprite_ = nullptr;
    nlohmann::json jsonMap;
    std::ifstream inJson("level1.json");
    if (!inJson) {
        std::cerr << "Error loading file\n";
        exit(0);
    }
    inJson >> jsonMap;
    std::vector<int> levelVector = jsonMap["level"];
    level = levelVector;
    sf::Vector2u tileSize;
    tileSize.x = jsonMap["TileSize"][0];
    tileSize.y = jsonMap["TileSize"][1];

    std::cout << jsonMap["level"] << std::endl;

    if (!map.load(jsonMap["tileset"], tileSize, level, 16, 8))
        return ;

    m_elapsed = 0.0f;


}

Game::~Game() {}

sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
    // Input handling.

    for (auto& i : m_gameObjects)
    {
        auto movecmpt = i->GetComponent<MoveCmpt>();

        auto icmpt = i->GetComponent<inputControllerCmpt>();
        if (movecmpt == nullptr || icmpt == nullptr)
            break;
        if (icmpt->IsKeyPressed(inputControllerCmpt::KEY::KEY_LEFT))
            movecmpt->updatePosition({ -1,0 });
        if (icmpt->IsKeyPressed(inputControllerCmpt::KEY::KEY_RIGHT))
            movecmpt->updatePosition({ 1,0 });

        if (icmpt->IsKeyPressed(inputControllerCmpt::KEY::KEY_UP))
            movecmpt->updatePosition({ 0,-1 });

        if (icmpt->IsKeyPressed(inputControllerCmpt::KEY::KEY_DOWN))
            movecmpt->updatePosition({ 0,1 });

        movecmpt->Update(0.01);
    }


}

void Game::Update() {
    m_window.Update();
}

void Game::Render() {
    m_window.BeginDraw();
    // Render here.
    m_window.GetRenderWindow()->draw(map);

    for (auto& i : m_gameObjects)
    {
        auto sprCmpt = i->GetComponent<SpriteCmpt>();
        auto moveCmpt = i->GetComponent<MoveCmpt>();
        if (sprCmpt != nullptr && moveCmpt != nullptr)            sprCmpt->setPosition(moveCmpt->getPosition());
        if (sprCmpt != nullptr)
            sprCmpt->Draw(*m_window.GetRenderWindow(), 0.01);
    }


    m_window.EndDraw();
}

void Game::AddObjects(Object* obj)
{
    Game::m_gameObjects.push_back(obj);
}