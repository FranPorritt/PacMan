#include "Pinky.h"

Pinky::Pinky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg) :
	Ghosts(ghostRadiusArg, ghostColorArg, ghostPosArg, scatterTileArg)
{
}

Pinky::~Pinky()
{
}

void Pinky::Chase(sf::Vector2f& currentPlayerPos)
{
	if (lastPlayerPos.x - currentPlayerPos.x < 0)
	{
		//player moving right
		targetPos = { currentPlayerPos.x + (4 * gridSize), currentPlayerPos.y };
	}
	else if (lastPlayerPos.x - currentPlayerPos.x > 0)
	{
		//moving left
		targetPos = { currentPlayerPos.x - (4 * gridSize), currentPlayerPos.y };
	}
	else if (lastPlayerPos.y - currentPlayerPos.y < 0)
	{
		//moving down
		targetPos = { currentPlayerPos.x, currentPlayerPos.y + (4 * gridSize) };
	}
	else if (lastPlayerPos.y - currentPlayerPos.y > 0)
	{
		//moving up
		targetPos = { currentPlayerPos.x, currentPlayerPos.y - (4 * gridSize) };
	}

	xDirVector = targetPos.x - ghostPos.x;
	yDirVector = targetPos.y - ghostPos.y;

	lastPlayerPos = currentPlayerPos;
}
