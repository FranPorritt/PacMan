#include "Clyde.h"

Clyde::Clyde(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg) :
	Ghosts(ghostRadiusArg, ghostColorArg, ghostPosArg, scatterTileArg)
{
}

Clyde::~Clyde()
{
}

void Clyde::Chase(sf::Vector2f& currentPlayerPos)
{
	if ((abs(xDirVector) >= (8 * gridSize)) || (abs(yDirVector) >= (8*gridSize)))
	{
		targetPos = currentPlayerPos;
	}
	else
	{
		targetPos = scatterTile;
	}

	xDirVector = targetPos.x - ghostPos.x;
	yDirVector = targetPos.y - ghostPos.y;
}
