#include "Ghosts.h"
#include <cmath>

Ghosts::Ghosts(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg) :
	ghostRadius(ghostRadiusArg), ghostColor(ghostColorArg), ghostPos(ghostPosArg), scatterTile(scatterTileArg)
{
}

Ghosts::~Ghosts()
{
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
	if (std::max(abs(xDirVector), abs(yDirVector)) == abs(xDirVector)) // If x position is further than y position
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
			else if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
			}
			else if ((canMoveDown) && (direction != EGhostDirection::eUp))
			{
				direction = EGhostDirection::eDown;
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
			else if ((canMoveRight) && (direction != EGhostDirection::eLeft))
			{
				direction = EGhostDirection::eRight;
			}
			else if ((canMoveUp) && (direction != EGhostDirection::eDown))
			{
				direction = EGhostDirection::eUp;
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
			else if ((canMoveUp) && (direction != EGhostDirection::eDown))
			{
				direction = EGhostDirection::eUp;
			}
			else if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
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
			else if ((canMoveDown) && (direction != EGhostDirection::eUp))
			{
				direction = EGhostDirection::eDown;
			}
			else if ((canMoveLeft) && (direction != EGhostDirection::eRight))
			{
				direction = EGhostDirection::eLeft;
			}
		}
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
	// Frightened -- Used by all ghosts -- No target tile, instead each ghost randomly decides which why to go. Turn dark blue and are vunerable to player
	//
	// 1. Change colour - Dark Blue
	// 2. Randomly set direction
}

sf::Vector2f Ghosts::GetGhostPos()
{
	return ghostPos;
}
