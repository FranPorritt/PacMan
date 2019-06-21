#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Points.h"
#include <vector>

enum class gameState
{
	Playing,
	GameOver,
};

class Game
{
protected:
	gameState currentState = gameState::Playing;
	sf::Vector2f playerSpawn;
	sf::Vector2f currentPlayerPos;

	std::vector<Ghosts*>ghosts;
	sf::Vector2f currentGhostPos;
	int behaviourTimer = 0;
	sf::Vector2f scatterTile;

public:
	Game();
	~Game();

	void Update(sf::RenderWindow& window);
	void Play(sf::RenderWindow& window);
};

