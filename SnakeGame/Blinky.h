#pragma once
#include "Ghosts.h"

class Blinky : public Ghosts
{
protected:
	sf::Vector2f scatterTile = { 0,0 };

public:
	Blinky(float ghostRadiusArg, sf::Color ghostColorArg, sf::Vector2f ghostPosArg, sf::Vector2f scatterTileArg);
	~Blinky();
};

