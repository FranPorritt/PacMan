#include "Ghosts.h"
#include <cmath>
#include <iostream>

Ghosts::Ghosts(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg) :
	ghostRadius(ghostRadiusArg), ghostColor(ghostColorArg), ghostPos(ghostPosArg), scatterTile(scatterTileArg)
{
}

Ghosts::~Ghosts()
{
}

void Ghosts::Update(sf::Vector2f& currentPlayerPos, sf::Vector2f& targetTile)
{
	switch (currentState)
	{
	case ghostState::LeavingHouse:
		LeaveHouse();
		break;

	case ghostState::Chasing:
		Chase(currentPlayerPos);
		break;

	case ghostState::Scattering:
		Scatter(targetTile);
		break;

	case ghostState::Frightened:
		Frightened();
		break;

	case ghostState::Respawning:
		Respawn();
		break;

	default:
		break;
	}

	if (hasLeftHouse)
	{
		if (isFrightened)
		{
			currentState = ghostState::Frightened;
			behaviourTimer = 0;  // Resets chase loop
		}
		else
		{
			// Switches periodically from chase to scatter
			if (behaviourTimer < 100)
			{
				currentState = ghostState::Chasing;
			}
			else
			{
				currentState = ghostState::Scattering;
			}
		}
	}
	else
	{
		currentState = ghostState::LeavingHouse;
	}

	if (behaviourTimer > 125) // Resets behaviour timer after chase-scatter loop
	{
		ResetBehaviour();
	}
	behaviourTimer++;

	if (isRespawning) // Stops ghost from still being frightened after respawning
	{
		respawnTimer--;

		if (respawnTimer <= 0)
		{
			isRespawning = false;
		}
	}

	Pathfinding();
	Move();
}

void Ghosts::Render(sf::RenderWindow& window)
{
	sf::CircleShape ghost(ghostRadius);
	ghost.setOrigin(-2.5, -2.5);
	ghost.setPosition(ghostPos);
	ghost.setFillColor(ghostColor);
	window.draw(ghost);
}

void Ghosts::Move()
{
	if ((!canMoveUp) && (direction == EGhostDirection::eUp))
	{
		direction = EGhostDirection::eStop;
	}
	if ((!canMoveDown) && (direction == EGhostDirection::eDown))
	{
		direction = EGhostDirection::eStop;
	}
	if ((!canMoveLeft) && (direction == EGhostDirection::eLeft))
	{
		direction = EGhostDirection::eStop;
	}
	if ((!canMoveRight) && (direction == EGhostDirection::eRight))
	{
		direction = EGhostDirection::eStop;
	}

	if (direction == EGhostDirection::eDown)
	{
		canMoveUp = false;
	}
	if (direction == EGhostDirection::eUp)
	{
		canMoveDown = false;
	}
	if (direction == EGhostDirection::eRight)
	{
		canMoveLeft = false;
	}
	if (direction == EGhostDirection::eLeft)
	{
		canMoveRight = false;
	}

	switch (direction)
	{
	case EGhostDirection::eUp:
		ghostPos.y -= gridSize;
		break;

	case EGhostDirection::eDown:
		ghostPos.y += gridSize;
		break;

	case EGhostDirection::eRight:
		ghostPos.x += gridSize;
		break;

	case EGhostDirection::eLeft:
		ghostPos.x -= gridSize;
		break;

	case EGhostDirection::eStop:
		break;

	default:
		break;
	}
}

void Ghosts::Pathfinding()
{
	// max + abs, makes numbers positive and returns largest
	if ((std::max(abs(xDirVector), abs(yDirVector))) == abs(xDirVector)) // If x position is further than y position
	{
		if (xDirVector > 0)
		{
			if ((canMoveRight) && (direction != EGhostDirection::eLeft))
			{
				direction = EGhostDirection::eRight;
			}
			else if ((canMoveUp) && (direction != EGhostDirection::eDown))
			{
				direction = EGhostDirection::eUp;
			}
			else if ((canMoveDown) && (direction != EGhostDirection::eUp))
			{
				direction = EGhostDirection::eDown;
			}
			else if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
			}
			else
			{
				direction = EGhostDirection::eStop;
			}
		}
		else
		{
			if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
			}
			else if ((canMoveDown) && (direction != EGhostDirection::eUp))
			{
				direction = EGhostDirection::eDown;
			}
			else if ((canMoveUp) && (direction != EGhostDirection::eDown))
			{
				direction = EGhostDirection::eUp;
			}
			else if ((canMoveRight) && (direction != EGhostDirection::eLeft))
			{
				direction = EGhostDirection::eRight;
			}
			else
			{
				direction = EGhostDirection::eStop;
			}
		}
	}
	else
	{
		if (yDirVector > 0)
		{
			if ((canMoveDown) && (direction != EGhostDirection::eUp))
			{
				direction = EGhostDirection::eDown;
			}
			else if ((canMoveRight) && (direction != EGhostDirection::eLeft))
			{
				direction = EGhostDirection::eRight;
			}
			else if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
			}
			else if ((canMoveUp) && (direction != EGhostDirection::eDown))
			{
				direction = EGhostDirection::eUp;
			}
			else
			{
				direction = EGhostDirection::eStop;
			}
		}
		else
		{
			if ((canMoveUp) && (direction != EGhostDirection::eDown))
			{
				direction = EGhostDirection::eUp;
			}
			else if ((canMoveRight) && (direction != EGhostDirection::eLeft))
			{
				direction = EGhostDirection::eRight;
			}
			else if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
			}
			else if ((canMoveDown) && (direction != EGhostDirection::eUp))
			{
				direction = EGhostDirection::eDown;
			}
			else
			{
				direction = EGhostDirection::eStop;
			}
		}
	}
}

void Ghosts::LeaveHouse()
{
	targetPos = { 400.0f, 365.0f };

	xDirVector = targetPos.x - ghostPos.x;
	yDirVector = targetPos.y - ghostPos.y;

	if (targetPos == ghostPos)
	{
		hasLeftHouse = true;
	}
}

void Ghosts::Chase(sf::Vector2f& currentPlayerPos)
{
	targetPos = currentPlayerPos;

	xDirVector = targetPos.x - ghostPos.x;
	yDirVector = targetPos.y - ghostPos.y;
}

void Ghosts::Scatter(sf::Vector2f& targetTile)
{
	targetPos = targetTile;

	xDirVector = targetPos.x - ghostPos.x;
	yDirVector = targetPos.y - ghostPos.y;
}

void Ghosts::Frightened()
{
	if (ghostColor != sf::Color::Blue)
	{
		defaultColor = ghostColor;
		ghostColor = frightColor;
	}

	xDirVector = (rand() % 10) - (rand() % 5);
	yDirVector = (rand() % 10) - (rand() % 5);
}

void Ghosts::Respawn()
{
	currentState = ghostState::Respawning;

	ghostPos = { 400.0f, 440.0f };
	hasLeftHouse = false;
	SetFrightenedFalse();

	respawnTimer = 50;
	isRespawning = true;
	isPlayerDead = false;
}

void Ghosts::PlayerCollision(sf::Vector2f& currentPlayerPos)
{
	if (currentPlayerPos == ghostPos)
	{
		if (isFrightened)
		{
			// Ghost dies
			// Respawn -- Not frightened
			// Add points
			std::cout << "Ghost Dead" << std::endl;
			Respawn();
			points->AddPoints(ghostValue);
		}
		else
		{
			// Player dies -- Lose a life
			// Respawn Player
			// Respawn Ghosts -- Reset timer
			std::cout << "Player Dead" << std::endl;
			isPlayerDead = true;
		}
	}
}

void Ghosts::ResetBehaviour()
{
	respawnTimer = 0;
	behaviourTimer = 0;
}

void Ghosts::SetFrightenedFalse()
{
	ghostColor = defaultColor;
	isFrightened = false;
}

void Ghosts::SetFrightenedTrue()
{
	isFrightened = true;
}

sf::Vector2f Ghosts::GetGhostPos()
{
	return ghostPos;
}

sf::Vector2f Ghosts::GetScatterTile()
{
	return scatterTile;
}

bool Ghosts::GetHouse()
{
	return hasLeftHouse;
}

bool Ghosts::GetFright()
{
	return isFrightened;
}

bool Ghosts::GetRespawn()
{
	return isRespawning;
}

bool Ghosts::GetPlayerDeath()
{
	return isPlayerDead;
}