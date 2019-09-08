#pragma once
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Points.h"

enum class EGhostDirection
{
	eUp,
	eDown,
	eLeft,
	eRight,
	eStop,
};

enum class ghostState
{
	LeavingHouse,
	Chasing,
	Scattering,
	Frightened,
	Respawning,
};

class Ghosts : public Characters
{
protected:
	EGhostDirection direction = EGhostDirection::eStop;
	float gridSize = 25.0f; // Find a better way ie. this is in game class too


	ghostState currentState = ghostState::LeavingHouse;
	float ghostRadius = 12.5f;
	sf::Vector2f ghostPos;
	sf::Color ghostColor;
	bool hasLeftHouse = false;

	sf::Vector2f targetPos;
	int xDirVector = 0;
	int yDirVector = 0;

	int behaviourTimer = 0;
	sf::Vector2f scatterTile;

	bool isFrightened = false;
	int powerTimer = 0;
	sf::Color frightColor = sf::Color::Blue;
	sf::Color defaultColor = ghostColor;

	int respawnTimer = 0;
	bool isRespawning = false;
	bool isPlayerDead = false;

	Points* points = Points::getInstance();
	int ghostValue = 200;

public:
	Ghosts(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Ghosts();

	void Update(sf::Vector2f& currentPlayerPos, sf::Vector2f& targetTile);
	void Render(sf::RenderWindow& window);
	void Move();

	void Pathfinding();
	void LeaveHouse();
	virtual void Chase(sf::Vector2f& currentPlayerPos);		// Actively chasing player	
	void Scatter(sf::Vector2f& targetTile);					// Head to one of the four corners of the map	
	void Frightened();										// Fleeing from player -- Activated by power up	
	void Respawn();
	void PlayerCollision(sf::Vector2f& currentPlayerPos);
	void ResetBehaviour();
	void SetFrightenedTrue();
	void SetFrightenedFalse();

	sf::Vector2f GetGhostPos();
	sf::Vector2f GetScatterTile();
	bool GetHouse();
	bool GetFright();
	bool GetRespawn();
	bool GetPlayerDeath();
};

