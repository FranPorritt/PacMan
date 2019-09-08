#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Points.h"
#include <vector>

enum class gameState
{
	Menu,
	Playing,
	GameOver,
	GameWon,
	Restart,
};

class Game
{
protected:
	gameState currentState = gameState::Menu;
	sf::Vector2f playerSpawn;
	sf::Vector2f currentPlayerPos;

	std::vector<Ghosts*>ghosts;
	sf::Vector2f currentGhostPos;
	//Blinky& blinky;
	sf::Vector2f blinkyPos;
	int behaviourTimer = 0;
	sf::Vector2f scatterTile;

	bool isRestarting = false;
	bool isResetting = false;

public:
	Game();
	~Game();

	void Update(sf::RenderWindow& window, const int& screenWidth, const int& screenHeight);
	void Menu(sf::RenderWindow& window, const int& screenWidth, const int& screenHeight);
	void Play(sf::RenderWindow& window, const int& screenWidth);
	void GameOver(sf::RenderWindow& window, const int& screenWidth);
	void GameWon(sf::RenderWindow& window, const int& screenWidth);
	void Restart(sf::RenderWindow& window);

	bool GetRestart();
};

