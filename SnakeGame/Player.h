#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Characters.h"

using namespace std;

enum class EDirection
{
	eUp,
	eDown,
	eLeft,
	eRight,
	eStop,
};

class Player : public Characters
{
protected:
	EDirection direction = EDirection::eStop;
	float gridSize = 25.0f; // Find a better way ie. this is in game class too

	sf::CircleShape player;
	float playerRadius = 12.5f;
	sf::Vector2f playerPos;
	sf::Color playerColor = sf::Color::Yellow;
	int playerLives = 2;

	bool isDead = false;

	sf::Font font;

public:
	Player(float playerRadiusArg, sf::Color playerColorArg, sf::Vector2f playerPosArg);
	~Player();

	void Render(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f& newPlayerPos);

	void Update();
	void Move();
	void Respawn(sf::Vector2f& playerSpawn);
	sf::Vector2f GetPlayerPos();

	bool GetIsDead();

	void DisplayLives(sf::RenderWindow& window);
	int GetLives();
};

