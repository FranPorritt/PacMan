#include "Inky.h"

Inky::Inky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg, Blinky& blinky) :
	Ghosts(ghostRadiusArg, ghostColorArg, ghostPosArg, scatterTileArg) 
{
}

Inky::~Inky()
{
}

void Inky::Chase(sf::Vector2f& currentPlayerPos)
{
	blinkyDistance = { currentPlayerPos.x - blinky.GetGhostPos().x, currentPlayerPos.y - blinky.GetGhostPos().y }; // Gets Blinky's distance from the Player

	if (lastPlayerPos.x - currentPlayerPos.x < 0)
	{
		//player moving right
		targetPos = { currentPlayerPos.x + (blinkyDistance.x * 2), currentPlayerPos.y };
	}
	else if (lastPlayerPos.x - currentPlayerPos.x > 0)
	{
		//moving left
		targetPos = { currentPlayerPos.x - (blinkyDistance.x * 2), currentPlayerPos.y };
	}
	else if (lastPlayerPos.y - currentPlayerPos.y < 0)
	{
		//moving down
		targetPos = { currentPlayerPos.x, currentPlayerPos.y + (blinkyDistance.y * 2) };
	}
	else if (lastPlayerPos.y - currentPlayerPos.y > 0)
	{
		//moving up
		targetPos = { currentPlayerPos.x, currentPlayerPos.y - (blinkyDistance.y * 2) };
	}

	xDirVector = targetPos.x - ghostPos.x;
	yDirVector = targetPos.y - ghostPos.y;

	lastPlayerPos = currentPlayerPos;
}
