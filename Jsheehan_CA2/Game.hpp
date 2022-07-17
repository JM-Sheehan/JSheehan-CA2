#pragma once
#include "Window.hpp"
#include "ResourcePath.hpp"

#include "TileMap.hpp"
#include "Object.hpp"
#include "SpriteCmpt.hpp"
#include "InputControllerCmpt.hpp"
#include "MoveCmpt.hpp"



//#include "ResourcePath.hpp"
class Game {
public:
	Game();
	~Game();

	void AddObjects(Object* obj)
	{
		m_gameObjects.push_back(obj);
	}

	void HandleInput();
	void Update();
	void Render();

	sf::Time GetElapsed();
	void RestartClock();

	Window* GetWindow();
private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;
	TileMap map;
	sf::Sprite mapSprite_;
	std::vector<int> level;//for now but will use different data structure instead of int later...


	//player and enemies
	std::vector<Object* > m_gameObjects;//vector of pointers to objects/entities


};
