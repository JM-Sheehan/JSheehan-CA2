#pragma once
#include "ResourcePath.hpp"
#include "json.hpp"
#include "TileMap.hpp"
#include "Object.hpp"
#include "SpriteCmpt.hpp"
#include "InputControllerCmpt.hpp"
#include "MoveCmpt.hpp"
#include "AnimatedSpriteCmpt.hpp"
#include "TileMap.hpp"
#include <fstream>
#include "WindowComponent.hpp"
#include "CollideCmpt.hpp"



using namespace nlohmann;


//#include "ResourcePath.hpp"
class Game {
public:
	Game();
	~Game();

	void AddObjects(Object* obj);
	void HandleInput();
	void Update();
	void Render();
	sf::Time GetElapsed();
	void RestartClock();
	WindowComponent* GetWindow();
	void setMap(TileMap tile_map);

private:
	WindowComponent m_window;
	sf::Clock m_clock;
	float m_elapsed;
	TileMap map;
	sf::Sprite mapSprite_;
	std::vector<int> level;//for now but will use different data structure instead of int later...

	//player and enemies
	std::vector<Object* > m_gameObjects;//vector of pointers to objects/entities


};
