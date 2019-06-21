#pragma once
#include <SFML/Graphics.hpp>
#include "Characters.h"

enum class EGhostDirection
{
	eUp,
	eDown,
	eLeft,
	eRight,
	eStop,
};

class Ghosts : public Characters
{
protected:
	EGhostDirection direction = EGhostDirection::eLeft;
	float gridSize = 25.0f; // Find a better way ie. this is in game class too

	float ghostRadius = 12.5f;
	sf::Vector2f ghostPos;
	sf::Color ghostColor;

	sf::Vector2f targetPos;
	int xDirVector = 0;
	int yDirVector = 0;

	sf::Vector2f scatterTile;

public:
	Ghosts(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Ghosts();

	void Render(sf::RenderWindow& window);
	void Move();

	// CHASE WILL NEED TO BE IN AN UPDATE
	void Pathfinding();
	void Chase(sf::Vector2f& currentPlayerPos);		// Actively chasing player	
	void Scatter(sf::Vector2f& targetTile);		// Head to one of the four corners of the map	
	void Frightened();	// Fleeing from player -- Activated by power up
	// Need a respawn too

	sf::Vector2f GetGhostPos();
};

